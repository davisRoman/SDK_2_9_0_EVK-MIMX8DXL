/*
 * Copyright 2017 NXP
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

lpspi_slave_handle_t g_s_handle;
volatile bool isTransferCompleted = false;

/*******************************************************************************
 * Code
 ******************************************************************************/

void LPSPI_SlaveUserCallback(LPSPI_Type *base, lpspi_slave_handle_t *handle, status_t status, void *userData)
{
    if (status == kStatus_Success)
    {
        PRINTF("This is LPSPI slave transfer completed callback. \r\n");
        PRINTF("It's a successful transfer. \r\n\r\n");
    }

    if (status == kStatus_LPSPI_Error)
    {
        PRINTF("This is LPSPI slave transfer completed callback. \r\n");
        PRINTF("Error occurred in this transfer. \r\n\r\n");
    }

    isTransferCompleted = true;
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

    PRINTF("LPSPI board to board polling example.\r\n");

    uint32_t i;
    lpspi_slave_config_t slaveConfig;
    lpspi_transfer_t slaveXfer;

    /*Slave config*/
    LPSPI_SlaveGetDefaultConfig(&slaveConfig);
    slaveConfig.whichPcs = EXAMPLE_LPSPI_SLAVE_PCS_FOR_INIT;

    LPSPI_SlaveInit(EXAMPLE_LPSPI_SLAVE_BASEADDR, &slaveConfig);

    LPSPI_SlaveTransferCreateHandle(EXAMPLE_LPSPI_SLAVE_BASEADDR, &g_s_handle, LPSPI_SlaveUserCallback, NULL);

    while (1)
    {
        PRINTF("\r\n Slave example is running...\r\n");

        /* Reset the receive buffer */
        for (i = 0U; i < TRANSFER_SIZE; i++)
        {
            slaveRxData[i] = 0U;
        }

        /* Set slave transfer ready to receive data */
        isTransferCompleted = false;

        slaveXfer.txData      = NULL;
        slaveXfer.rxData      = slaveRxData;
        slaveXfer.dataSize    = TRANSFER_SIZE;
        slaveXfer.configFlags = EXAMPLE_LPSPI_SLAVE_PCS_FOR_TRANSFER | kLPSPI_SlaveByteSwap;

        /* Slave start receive */
        LPSPI_SlaveTransferNonBlocking(EXAMPLE_LPSPI_SLAVE_BASEADDR, &g_s_handle, &slaveXfer);

        while (!isTransferCompleted)
        {
        }

        /* Set slave transfer ready to send back data */
        isTransferCompleted = false;

        slaveXfer.txData      = slaveRxData;
        slaveXfer.rxData      = NULL;
        slaveXfer.dataSize    = TRANSFER_SIZE;
        slaveXfer.configFlags = EXAMPLE_LPSPI_SLAVE_PCS_FOR_TRANSFER | kLPSPI_SlaveByteSwap;

        /* Slave start send */
        LPSPI_SlaveTransferNonBlocking(EXAMPLE_LPSPI_SLAVE_BASEADDR, &g_s_handle, &slaveXfer);

        while (!isTransferCompleted)
        {
        }

        /* Print out receive buffer */
        PRINTF("\r\n Slave received:");
        for (i = 0U; i < TRANSFER_SIZE; i++)
        {
            /* Print 16 numbers in a line */
            if ((i & 0x0FU) == 0U)
            {
                PRINTF("\r\n    ");
            }
            PRINTF(" %02X", slaveRxData[i]);
        }
        PRINTF("\r\n");
    }
}
