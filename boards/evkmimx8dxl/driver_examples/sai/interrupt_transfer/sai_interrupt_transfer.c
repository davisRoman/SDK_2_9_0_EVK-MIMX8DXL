/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_sai.h"
#include "music.h"
#include "fsl_codec_common.h"

#include "fsl_wm8960.h"
#include "main/imx8dxl_pads.h"
#include "svc/pad/pad_api.h"
#include "fsl_gpio.h"
#include "fsl_irqsteer.h"
#include "fsl_codec_adapter.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* SAI and I2C instance and clock */
#define DEMO_CODEC_WM8960
#define DEMO_SAI            ADMA__SAI1
#define DEMO_SAI_CHANNEL    (0)
#define DEMO_SAI_BITWIDTH   (kSAI_WordWidth16bits)
#define DEMO_I2C            ADMA__LPI2C2
#define DEMO_SAI_CLK_FREQ   (24576000U)
#define DEMO_I2C_CLK_FREQ   CLOCK_GetIpFreq(kCLOCK_DMA_Lpi2c2)
#define DEMO_LPI2C_BAUDRATE (400000)

/*Board I2C Addresses*/
#define EXAMPLE_I2C_PCA9548_ADDR (0x70)

#define DEMO_AUDIO_DATA_CHANNEL                           (2U)
#define DEMO_AUDIO_BIT_WIDTH                              kSAI_WordWidth16bits
#define DEMO_AUDIO_SAMPLE_RATE                            (kSAI_SampleRate16KHz)
#define DEMO_AUDIO_MASTER_CLOCK                           DEMO_SAI_CLK_FREQ
#define DEMO_AUDIO_DATA_PUT_INTO_SECTION(name, alignSize) AT_NONCACHEABLE_SECTION_ALIGN_INIT(name, alignSize)

#define DEMO_SAI_TX_SYNC_MODE kSAI_ModeAsync
#define DEMO_SAI_RX_SYNC_MODE kSAI_ModeSync
#define DEMO_SAI_MASTER_SLAVE kSAI_Master

#define BOARD_MASTER_CLOCK_CONFIG()
#define BOARD_SAI_RXCONFIG(config, mode)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
extern void BOARD_SAI_RXConfig(sai_transceiver_t *config, sai_sync_mode_t sync);
/*******************************************************************************
 * Variables
 ******************************************************************************/
wm8960_config_t wm8960Config = {
    .i2cConfig = {.codecI2CInstance = BOARD_CODEC_I2C_INSTANCE, .codecI2CSourceClock = BOARD_CODEC_I2C_CLOCK_FREQ},
    .route     = kWM8960_RoutePlaybackandRecord,
    .rightInputSource = kWM8960_InputDifferentialMicInput2,
    .playSource       = kWM8960_PlaySourceDAC,
    .slaveAddress     = WM8960_I2C_ADDR,
    .bus              = kWM8960_BusI2S,
    .format           = {.mclk_HZ    = 24576000U,
               .sampleRate = kWM8960_AudioSampleRate16KHz,
               .bitWidth   = kWM8960_AudioBitWidth16bit},
    .master_slave     = false,
};
codec_config_t boardCodecConfig = {.codecDevType = kCODEC_WM8960, .codecDevConfig = &wm8960Config};
sai_handle_t txHandle           = {0};
static volatile bool isFinished = false;
extern codec_config_t boardCodecConfig;
codec_handle_t codecHandle;

/*******************************************************************************
 * Code
 ******************************************************************************/
static bool PCA9548_WriteReg(LPI2C_Type *base, const uint8_t dev_addr, uint8_t *txBuff, uint32_t txSize)
{
    status_t reVal = kStatus_Fail;

    if (kStatus_Success == LPI2C_MasterStart(base, dev_addr, kLPI2C_Write))
    {
        while (LPI2C_MasterGetStatusFlags(base) & kLPI2C_MasterNackDetectFlag)
        {
        }

        reVal = LPI2C_MasterSend(base, txBuff, txSize);
        if (reVal != kStatus_Success)
        {
            return -1;
        }

        reVal = LPI2C_MasterStop(base);
        if (reVal != kStatus_Success)
        {
            return -1;
        }
    }
    return kStatus_Success;
}

sc_err_t BOARD_ConfigureExpansionIO()
{
    sc_err_t err = SC_ERR_NONE;
    lpi2c_master_config_t masterConfig;
    uint8_t txBuffer[4] = {0};
    uint32_t i;

    /*
     * PCA9548 is configured to choose SC0/SD0 channel
     */
    LPI2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Hz = DEMO_LPI2C_BAUDRATE;
    LPI2C_MasterInit(DEMO_I2C, &masterConfig, DEMO_I2C_CLK_FREQ);

    txBuffer[0] = 0x0;
    PCA9548_WriteReg(DEMO_I2C, EXAMPLE_I2C_PCA9548_ADDR, txBuffer, 1);
    i = 0;
    while (i < 15000000)
    {
        __ASM("nop");
        i++;
    }
    txBuffer[0] = 0x2;
    PCA9548_WriteReg(DEMO_I2C, EXAMPLE_I2C_PCA9548_ADDR, txBuffer, 1);

    LPI2C_MasterDeinit(DEMO_I2C);
    return err;
}

static void callback(I2S_Type *base, sai_handle_t *handle, status_t status, void *userData)
{
    isFinished = true;
}

/*!
 * @brief Main function
 */
int main(void)
{
    sai_transfer_t xfer;
    uint32_t temp = 0;
    sai_transceiver_t config;

    sc_ipc_t ipc;
    sc_pm_clock_rate_t src_rate = SC_133MHZ;

    /* set mclk 24.576M */
    uint32_t misc_src_rate = 24576000U;
    /* set pll clock,to get accurate mclk freq,it is recommended to set this integer multiple of misc_src_rate,but
     * should in [650MHz-1300MHz] */
    uint32_t pll_src_rate = 1228800000U;

    ipc = BOARD_InitRpc();
    BOARD_InitPins(ipc);
    BOARD_BootClockRUN();
    BOARD_I2C_ConfigurePins(ipc);

    BOARD_InitDebugConsole();
    BOARD_InitMemory();

    /* Power on LPI2C. */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_I2C_2, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to power on LPI2C\r\n");
    }

    /* Set LPI2C clock */
    if (sc_pm_set_clock_rate(ipc, SC_R_I2C_2, SC_PM_CLK_PER, &src_rate) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to set SC_R_I2C_2 clock rate\r\n");
    }
    if (sc_pm_clock_enable(ipc, SC_R_I2C_2, SC_PM_CLK_PER, true, false) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to enable SC_R_I2C_2 clock \r\n");
    }

    /* Power on R0, R0 is used to the common control from SCU that reset the U75 I2C expander */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_BOARD_R0, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to power on R0\r\n");
    }

    /* Power on SAI. */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_SAI_1, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to power on SAI\r\n");
    }

    /* Power on MCLKOUT0, AUDIO PLL0 clocks */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_AUDIO_PLL_0, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to enable Audio PLL0\r\n");
    }

    /* Set SC_PM_CLK_PLL clock freq and enable */
    if (sc_pm_set_clock_rate(ipc, SC_R_AUDIO_PLL_0, SC_PM_CLK_PLL, &pll_src_rate) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to set SC_PM_CLK_PLL clock rate\r\n");
    }
    if (sc_pm_clock_enable(ipc, SC_R_AUDIO_PLL_0, SC_PM_CLK_PLL, true, false) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to enable SC_PM_CLK_PLL clock\r\n");
    }

    /* Set AUDIO PLL0 DIV clock freq and enable */
    if (sc_pm_set_clock_rate(ipc, SC_R_AUDIO_PLL_0, SC_PM_CLK_MISC0, &misc_src_rate) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to set Audio PLL0 DIV clock rate\r\n");
    }
    if (sc_pm_clock_enable(ipc, SC_R_AUDIO_PLL_0, SC_PM_CLK_MISC0, true, false) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to enable Audio PLL0 DIV clock\r\n");
    }

    /* Set AUDIO PLL0 REC clock freq and enable */
    if (sc_pm_set_clock_rate(ipc, SC_R_AUDIO_PLL_0, SC_PM_CLK_MISC1, &misc_src_rate) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to set Audio PLL0 REC clock rate\r\n");
    }
    if (sc_pm_clock_enable(ipc, SC_R_AUDIO_PLL_0, SC_PM_CLK_MISC1, true, false) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to enable Audio PLL0 REC clock\r\n");
    }

    /* Power on MCLK_OUT clock */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_MCLK_OUT_1, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to power on MCLKOUT1\r\n");
    }

    /* Power on IRQSteer . */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_IRQSTR_M4_0, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to power on IRQSTR\r\n");
    }

    BOARD_ConfigureExpansionIO();

    /* Enable interrupt in irqsteer */
    IRQSTEER_Init(IRQSTEER);
    IRQSTEER_EnableInterrupt(IRQSTEER, ADMA_SAI1_INT_IRQn);

    PRINTF("SAI example started!\n\r");

    /* SAI init */
    SAI_Init(DEMO_SAI);
    SAI_TransferTxCreateHandle(DEMO_SAI, &txHandle, callback, NULL);
    /* I2S mode configurations */
    SAI_GetClassicI2SConfig(&config, DEMO_AUDIO_BIT_WIDTH, kSAI_Stereo, 1U << DEMO_SAI_CHANNEL);
    config.syncMode    = DEMO_SAI_TX_SYNC_MODE;
    config.masterSlave = DEMO_SAI_MASTER_SLAVE;
    SAI_TransferTxSetConfig(DEMO_SAI, &txHandle, &config);

    /* set bit clock divider */
    SAI_TxSetBitClockRate(DEMO_SAI, DEMO_AUDIO_MASTER_CLOCK, DEMO_AUDIO_SAMPLE_RATE, DEMO_AUDIO_BIT_WIDTH,
                          DEMO_AUDIO_DATA_CHANNEL);
    /* sai rx configurations */
    BOARD_SAI_RXCONFIG(&config, DEMO_SAI_RX_SYNC_MODE);
    /* master clock configurations */
    BOARD_MASTER_CLOCK_CONFIG();

    /* Use default setting to init codec */
    if (CODEC_Init(&codecHandle, &boardCodecConfig) != kStatus_Success)
    {
        assert(false);
    }

    /*  xfer structure */
    temp          = (uint32_t)music;
    xfer.data     = (uint8_t *)temp;
    xfer.dataSize = MUSIC_LEN;
    SAI_TransferSendNonBlocking(DEMO_SAI, &txHandle, &xfer);
    /* Wait until finished */
    while (isFinished != true)
    {
    }

    PRINTF("\n\r SAI example finished!\n\r ");
    while (1)
    {
    }
}
