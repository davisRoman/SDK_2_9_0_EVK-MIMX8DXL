/*
 * Copyright  2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_elcdif.h"
#include "fsl_debug_console.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APP_ELCDIF ADMA__LCDIF

#define APP_IMG_HEIGHT 800
#define APP_IMG_WIDTH  1280
#define APP_HSW        10
#define APP_HFP        70
#define APP_HBP        80
#define APP_VSW        3
#define APP_VFP        10
#define APP_VBP        10
#define APP_POL_FLAGS \
    (kELCDIF_DataEnableActiveHigh | kELCDIF_VsyncActiveLow | kELCDIF_HsyncActiveLow | kELCDIF_DriveDataOnRisingClkEdge)

/* Frame buffer data alignment, for better performance, the LCDIF frame buffer should be 64B align. */
#define FRAME_BUFFER_ALIGN 64

#define APP_LCDIF_DATA_BUS kELCDIF_DataBus18Bit
#ifndef APP_LCDIF_DATA_BUS
#define APP_LCDIF_DATA_BUS kELCDIF_DataBus24Bit
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void BOARD_EnableLcdInterrupt(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
AT_NONCACHEABLE_SECTION_ALIGN(static uint32_t s_psBuffer[APP_IMG_HEIGHT][APP_IMG_WIDTH], FRAME_BUFFER_ALIGN);
AT_NONCACHEABLE_SECTION_ALIGN(static uint32_t s_asBuffer[APP_IMG_HEIGHT][APP_IMG_WIDTH], FRAME_BUFFER_ALIGN);

/*******************************************************************************
 * Code
 ******************************************************************************/
static void BOARD_InitLcd(void)
{
    status_t status;
    sc_ipc_t ipc  = BOARD_GetRpcHandle();
    uint32_t freq = SC_133MHZ;

    static const board_io_expander_pin_t lcdIOEXPPin[] = {
        kIOEXP_M40_DEBUG_UART_SEL, kIOEXP_SPI3_CS0_SEL, kIOEXP_LCD_BL_CNTR, kIOEXP_UART1_SEL,
        kIOEXP_SPI3_SEL,           kIOEXP_SPI0_SEL,     kIOEXP_MUX3_EN,
    };

    static const board_io_expander_pin_level_t lcdIOEXPPinLevel[] = {
        kIOEXP_PinLow, kIOEXP_PinLow, kIOEXP_PinHigh, kIOEXP_PinLow, kIOEXP_PinLow, kIOEXP_PinLow, kIOEXP_PinLow,
    };

    /* Initialize the LPI2C to control IO EXPANDER. */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_I2C_2, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to power on SC_R_I2C_2\r\n");
        while (1)
            ;
    }

    if (sc_pm_set_clock_rate(ipc, SC_R_I2C_2, SC_PM_CLK_PER, &freq) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to set SC_R_I2C_2 clock rate\r\n");
        while (1)
            ;
    }

    if (sc_pm_clock_enable(ipc, SC_R_I2C_2, SC_PM_CLK_PER, true, false) != SC_ERR_NONE)
    {
        PRINTF("Error: Failed to enable SC_R_I2C_2 clock \r\n");
        while (1)
            ;
    }

    BOARD_LPI2C_Init(ADMA__LPI2C2, freq);

    /* Configure the IO EXPANDER. */
    for (uint32_t i = 0; i < ARRAY_SIZE(lcdIOEXPPin); i++)
    {
        status = BOARD_SetIOExpanderPinLevel(lcdIOEXPPin[i], lcdIOEXPPinLevel[i]);
        if (kStatus_Success != status)
        {
            PRINTF("Set IO EXP pin level failed\r\n");
            while (1)
                ;
        }

        status = BOARD_SetIOExpanderPinDirection(lcdIOEXPPin[i], kIOEXP_PinOutput);
        if (kStatus_Success != status)
        {
            PRINTF("Set IO EXP direction failed\r\n");
            while (1)
                ;
        }
    }
}

static void BOARD_InitLcdifPixelClock(void)
{
    sc_err_t err;
    sc_ipc_t ipc;
    uint32_t pixelClock_Hz;
    uint32_t lcdPllClock_Hz;

    ipc = BOARD_GetRpcHandle();

    /* Power Off the PLL and LCD to reset. */
    if (sc_pm_set_resource_power_mode(ipc, SC_R_ELCDIF_PLL, SC_PM_PW_MODE_OFF) != SC_ERR_NONE)
    {
        assert(false);
    }

    if (sc_pm_set_resource_power_mode(ipc, SC_R_LCD_0, SC_PM_PW_MODE_OFF) != SC_ERR_NONE)
    {
        assert(false);
    }

    if (sc_pm_set_resource_power_mode(ipc, SC_R_ELCDIF_PLL, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        assert(false);
    }

    if (sc_pm_set_resource_power_mode(ipc, SC_R_LCD_0, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        assert(false);
    }

    lcdPllClock_Hz = 648000000;
    err            = sc_pm_set_clock_rate(ipc, SC_R_ELCDIF_PLL, SC_PM_CLK_MISC, &lcdPllClock_Hz);
    if (SC_ERR_NONE != err)
    {
        assert(false);
    }

    err = sc_pm_clock_enable(ipc, SC_R_ELCDIF_PLL, SC_PM_CLK_MISC, true, false);
    if (SC_ERR_NONE != err)
    {
        assert(false);
    }

    err = sc_pm_set_clock_parent(ipc, SC_R_LCD_0, SC_PM_CLK_PER, SC_PM_PARENT_BYPS);
    if (SC_ERR_NONE != err)
    {
        assert(false);
    }

    /* Pixel clock for 60Hz frame rate is 68.9~73.4MHz, typical value 71.1MHz. */
    pixelClock_Hz = 71100000;
    err           = sc_pm_set_clock_rate(ipc, SC_R_LCD_0, SC_PM_CLK_PER, &pixelClock_Hz);
    if (SC_ERR_NONE != err)
    {
        assert(false);
    }
}

/* Initialize debug console through ADMA UART0. */
static void BOARD_InitDebugConsole_ADMA_UART0(void)
{
    uint32_t freq;
    sc_ipc_t ipc = BOARD_GetRpcHandle();

    if (sc_pm_set_resource_power_mode(ipc, SC_R_UART_0, SC_PM_PW_MODE_ON) != SC_ERR_NONE)
    {
        assert(false);
    }

    freq = CLOCK_SetIpFreq(kCLOCK_DMA_Lpuart0, SC_133MHZ);
    assert(freq != 0U);

    DbgConsole_Init(0, BOARD_DEBUG_UART_BAUDRATE, BOARD_DEBUG_UART_TYPE, freq);
}



void APP_FillPsBuffer(uint32_t buffer[][APP_IMG_WIDTH])
{
    /* PS buffer is a blue rectangle in the center. */

    uint32_t i, j;

    /* Background color. */
    memset(buffer, 0, sizeof(uint32_t) * APP_IMG_WIDTH * APP_IMG_HEIGHT);

    /* Foreground color. */
    for (i = APP_IMG_HEIGHT / 4; i < APP_IMG_HEIGHT * 3 / 4; i++)
    {
        for (j = APP_IMG_WIDTH / 4; j < APP_IMG_WIDTH * 3 / 4; j++)
        {
            buffer[i][j] = 0x000000FFU;
        }
    }
}

void APP_ELCDIF_Init(void)
{
    const elcdif_rgb_mode_config_t config = {
        .panelWidth    = APP_IMG_WIDTH,
        .panelHeight   = APP_IMG_HEIGHT,
        .hsw           = APP_HSW,
        .hfp           = APP_HFP,
        .hbp           = APP_HBP,
        .vsw           = APP_VSW,
        .vfp           = APP_VFP,
        .vbp           = APP_VBP,
        .polarityFlags = APP_POL_FLAGS,
        .bufferAddr    = (uint32_t)s_psBuffer,
        .pixelFormat   = kELCDIF_PixelFormatXRGB8888,
        .dataBus       = APP_LCDIF_DATA_BUS,
    };

    ELCDIF_RgbModeInit(APP_ELCDIF, &config);
}

void APP_FillAsBuffer(uint32_t buffer[][APP_IMG_WIDTH])
{
    /* AS buffer is full screen red. */

    uint32_t i, j;

    /* Foreground color. */
    for (i = 0; i < APP_IMG_HEIGHT; i++)
    {
        for (j = 0; j < APP_IMG_WIDTH; j++)
        {
            buffer[i][j] = 0x00FF0000U;
        }
    }
}

void APP_ELCDIF_AlphaRun(void)
{
    uint32_t alpha   = 0U;
    int32_t alphaInc = 1U;

    const elcdif_as_buffer_config_t asBufferConfig = {
        .bufferAddr  = (uint32_t)s_asBuffer,
        .pixelFormat = kELCDIF_AsPixelFormatRGB888,
    };

    elcdif_as_blend_config_t asBlendConfig = {
        .alpha       = alpha,
        .invertAlpha = false,
        .alphaMode   = kELCDIF_AlphaOverride,
        .ropMode     = kELCDIF_RopMaskAs, /* Don't care. */
    };

    ELCDIF_SetAlphaSurfaceBufferConfig(APP_ELCDIF, &asBufferConfig);
    ELCDIF_SetAlphaSurfaceBlendConfig(APP_ELCDIF, &asBlendConfig);
    ELCDIF_EnableAlphaSurface(APP_ELCDIF, true);

    ELCDIF_EnableInterrupts(APP_ELCDIF, kELCDIF_CurFrameDoneInterruptEnable);
    ELCDIF_RgbModeStart(APP_ELCDIF);

    while (1)
    {
        alpha += alphaInc;

        if (0xFF == alpha)
        {
            alphaInc = -1;
        }
        else if (0 == alpha)
        {
            alphaInc = 1;
        }

        asBlendConfig.alpha = alpha;

        /* Wait for previous frame complete. */
        while (!(kELCDIF_CurFrameDone & ELCDIF_GetInterruptStatus(APP_ELCDIF)))
        {
        }
        ELCDIF_ClearInterruptStatus(APP_ELCDIF, kELCDIF_CurFrameDone);

        ELCDIF_SetAlphaSurfaceBlendConfig(APP_ELCDIF, &asBlendConfig);
    }
}

void setUp(void)
{
}

void tearDown(void)
{
}

/*!
 * @brief Main function
 */
int main(void)
{
    sc_ipc_t ipc;
    ipc = BOARD_InitRpc();
    BOARD_BootClockRUN();
    BOARD_InitMemory();
    BOARD_InitUartPins(ipc);
    BOARD_InitLcdPins(ipc);
    BOARD_InitIOExpanderI2CPins(ipc);
    BOARD_InitDebugConsole_ADMA_UART0();
    BOARD_InitLcdifPixelClock();
    BOARD_InitLcd();

    PRINTF("LCDIF alpha example started ...\r\n");

    APP_FillPsBuffer(s_psBuffer);

    APP_FillAsBuffer(s_asBuffer);

    APP_ELCDIF_Init();

    APP_ELCDIF_AlphaRun();

    while (1)
    {
    }
}
