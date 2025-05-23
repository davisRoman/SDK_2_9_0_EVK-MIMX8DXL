/*
 * Copyright 2017, 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_lpspi.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_irqsteer.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*Master related*/
#define EXAMPLE_LPSPI_SLAVE_BASEADDR         ADMA__LPSPI3
#define EXAMPLE_LPSPI_SLAVE_PCS_FOR_INIT     kLPSPI_Pcs1
#define EXAMPLE_LPSPI_SLAVE_PCS_FOR_TRANSFER kLPSPI_SlavePcs1
#define EXAMPLE_LPSPI_SLAVE_IRQN             ADMA_SPI3_INT_IRQn
#define EXAMPLE_LPSPI_SLAVE_IRQHandler       ADMA_SPI3_INT_IRQHandler
#define TRANSFER_SIZE 64U /*! Transfer dataSize */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* LPSPI user callback */
void LPSPI_SlaveUserCallback(LPSPI_Type *base, lpspi_slave_handle_t *handle, status_t status, void *userData);

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t slaveRxData[TRANSFER_SIZE] = {0U};
uint8_t slaveTxData[TRANSFER_SIZE] = {0U};

volatile uint32_t slaveTxCount;
volatile uint32_t slaveRxCount;
volatile uint8_t g_slaveRxWatermark;
uint8_t g_slaveFifoSize;

volatile bool isSlaveTransferCompleted = false;

/*******************************************************************************
 * Code
 ******************************************************************************/
void EXAMPLE_LPSPI_SLAVE_IRQHandler(void)
{
    if (slaveRxCount < TRANSFER_SIZE)
    {
        /* While reading out the RX FIFO as more data may be coming into the RX FIFO. We'll
         * re-enable the interrupts after reading out the FIFO.
         */
        while (LPSPI_GetRxFifoCount(EXAMPLE_LPSPI_SLAVE_BASEADDR))
        {
            slaveRxData[slaveRxCount] = LPSPI_ReadData(EXAMPLE_LPSPI_SLAVE_BASEADDR);
            slaveRxCount++;

            if (slaveRxCount == TRANSFER_SIZE)
            {
                LPSPI_DisableInterrupts(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_RxInterruptEnable);
                break;
            }
        }
    }

    /* Update rxWatermark. There isn't RX interrupt for the last datas if the RX count is not greater than rxWatermark.
     */
    if ((TRANSFER_SIZE - slaveRxCount) <= g_slaveRxWatermark)
    {
        EXAMPLE_LPSPI_SLAVE_BASEADDR->FCR =
            (EXAMPLE_LPSPI_SLAVE_BASEADDR->FCR & (~LPSPI_FCR_RXWATER_MASK)) |
            LPSPI_FCR_RXWATER(((TRANSFER_SIZE - slaveRxCount) > 1U) ? ((TRANSFER_SIZE - slaveRxCount) - 1U) : (0U));
    }

    if (slaveTxCount < TRANSFER_SIZE)
    {
        while (LPSPI_GetTxFifoCount(EXAMPLE_LPSPI_SLAVE_BASEADDR) < g_slaveFifoSize)
        {
            /*Write the word to TX register*/
            LPSPI_WriteData(EXAMPLE_LPSPI_SLAVE_BASEADDR, slaveTxData[slaveTxCount]);
            ++slaveTxCount;

            if (slaveTxCount == TRANSFER_SIZE)
            {
                /* Disable interrupt requests */
                LPSPI_DisableInterrupts(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_TxInterruptEnable);
                break;
            }
        }
    }

    /* Check if we're done with this transfer.*/
    if ((slaveRxCount == TRANSFER_SIZE) && (slaveTxCount == TRANSFER_SIZE))
    {
        /* Complete the transfer. */
        isSlaveTransferCompleted = true;
    }
    SDK_ISR_EXIT_BARRIER;
}

/*!
 * @brief Main function
 */
int main(void)
{
    sc_ipc_t ipc;
    uint32_t freq;

    ipc = BOARD_InitRpc();
    BOARD_InitPins(ipc);
    BOARD_BootClockRUN();
    BOARD_InitMemory();
    BOARD_InitDebugConsole();

    /* Power on SPI. */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_SPI_3, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to power on LPSPI3\r\n");
    }

    /* Setup LPSPI clock */
    freq = CLOCK_SetIpFreq(kCLOCK_DMA_Lpspi3, SC_66MHZ);
    if (freq == 0)
    {
        PRINTF("Error: Failed to set LPSPI3 clock frequency\r\n");
    }

    if (sc_pm_set_resource_power_mode(ipc, SC_R_IRQSTR_M4_0, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to power on IRQSTR\r\n");
    }

    /* Enable LPSPI interrupt in IRQSTEER */
    IRQSTEER_Init(IRQSTEER);
    NVIC_EnableIRQ(IRQSTEER_2_IRQn);
    IRQSTEER_EnableInterrupt(IRQSTEER, ADMA_SPI3_INT_IRQn);

    PRINTF("LPSPI board to board functional interrupt example.\r\n");
    PRINTF("  Slave start to receive data...\r\n");

    uint32_t errorCount;
    uint32_t i;
    lpspi_slave_config_t slaveConfig;
    lpspi_which_pcs_t whichPcs;
    uint8_t txWatermark;

    /*Slave config*/
    LPSPI_SlaveGetDefaultConfig(&slaveConfig);
    slaveConfig.whichPcs = EXAMPLE_LPSPI_SLAVE_PCS_FOR_INIT;

    LPSPI_SlaveInit(EXAMPLE_LPSPI_SLAVE_BASEADDR, &slaveConfig);

    /*Set up the transfer data*/
    for (i = 0; i < TRANSFER_SIZE; i++)
    {
        slaveTxData[i] = i % 256;
        slaveRxData[i] = 0;
    }
    /******************Set up slave first ******************/
    isSlaveTransferCompleted = false;
    slaveTxCount             = 0;
    slaveRxCount             = 0;
    whichPcs                 = EXAMPLE_LPSPI_SLAVE_PCS_FOR_INIT;

    /*The TX and RX FIFO sizes are always the same*/
    g_slaveFifoSize = LPSPI_GetRxFifoSize(EXAMPLE_LPSPI_SLAVE_BASEADDR);

    /*Set the RX and TX watermarks to reduce the ISR times.*/
    if (g_slaveFifoSize > 1)
    {
        txWatermark        = 1;
        g_slaveRxWatermark = g_slaveFifoSize - 2;
    }
    else
    {
        txWatermark        = 0;
        g_slaveRxWatermark = 0;
    }

    LPSPI_SetFifoWatermarks(EXAMPLE_LPSPI_SLAVE_BASEADDR, txWatermark, g_slaveRxWatermark);

    LPSPI_Enable(EXAMPLE_LPSPI_SLAVE_BASEADDR, false);
    EXAMPLE_LPSPI_SLAVE_BASEADDR->CFGR1 &= (~LPSPI_CFGR1_NOSTALL_MASK);
    LPSPI_Enable(EXAMPLE_LPSPI_SLAVE_BASEADDR, true);

    /*Flush FIFO , clear status , disable all the interrupts.*/
    LPSPI_FlushFifo(EXAMPLE_LPSPI_SLAVE_BASEADDR, true, true);
    LPSPI_ClearStatusFlags(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_AllStatusFlag);
    LPSPI_DisableInterrupts(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_AllInterruptEnable);

    LPSPI_SelectTransferPCS(EXAMPLE_LPSPI_SLAVE_BASEADDR, whichPcs);

    /* Enable the NVIC for LPSPI peripheral. Note that below code is useless if the LPSPI interrupt is in INTMUX ,
     * and you should also enable the INTMUX interrupt in your application.
     */
    EnableIRQ(EXAMPLE_LPSPI_SLAVE_IRQN);

    /*TCR is also shared the FIFO , so wait for TCR written.*/
    while (LPSPI_GetTxFifoCount(EXAMPLE_LPSPI_SLAVE_BASEADDR) != 0)
    {
    }

    /*Fill up the TX data in FIFO */
    while (LPSPI_GetTxFifoCount(EXAMPLE_LPSPI_SLAVE_BASEADDR) < g_slaveFifoSize)
    {
        /*Write the word to TX register*/
        LPSPI_WriteData(EXAMPLE_LPSPI_SLAVE_BASEADDR, slaveTxData[slaveTxCount]);
        ++slaveTxCount;

        if (slaveTxCount == TRANSFER_SIZE)
        {
            break;
        }
    }
    if (slaveTxCount == TRANSFER_SIZE)
    {
        /* Only enable rx interrupt if tx data are all pushed to FIFO */
        LPSPI_EnableInterrupts(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_RxInterruptEnable);
    }
    else
    {
        LPSPI_EnableInterrupts(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_RxInterruptEnable | kLPSPI_TxInterruptEnable);
    }

    /******************Wait for master and slave transfer completed.******************/
    while (!isSlaveTransferCompleted)
    {
    }

    errorCount = 0;
    for (i = 0; i < TRANSFER_SIZE; i++)
    {
        if (slaveTxData[i] != slaveRxData[i])
        {
            errorCount++;
        }
    }
    if (errorCount == 0)
    {
        PRINTF("\r\nLPSPI transfer all data matched! \r\n");
    }
    else
    {
        PRINTF("\r\nError occurred in LPSPI transfer ! \r\n");
    }
    /* Print out receive buffer */
    PRINTF("\r\n Slave received:\r\n");
    for (i = 0U; i < TRANSFER_SIZE; i++)
    {
        /* Print 16 numbers in a line */
        if ((i & 0x0FU) == 0U)
        {
            PRINTF("\r\n");
        }
        PRINTF(" %02X", slaveRxData[i]);
    }
    PRINTF("\r\n");

    LPSPI_Deinit(EXAMPLE_LPSPI_SLAVE_BASEADDR);

    PRINTF("End of slave example! \r\n");

    while (1)
    {
    }
}
