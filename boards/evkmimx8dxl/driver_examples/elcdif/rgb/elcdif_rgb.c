/*
 * Copyright  2017-2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_elcdif.h"
#include "fsl_debug_console.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_irqsteer.h"
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
static volatile bool s_frameDone = false;

AT_NONCACHEABLE_SECTION_ALIGN(static uint32_t s_frameBuffer[2][APP_IMG_HEIGHT][APP_IMG_WIDTH], FRAME_BUFFER_ALIGN);

/*******************************************************************************
 * Code
 ******************************************************************************/
extern void APP_LCDIF_IRQHandler(void);

void LCD_MOD_INT_IRQHandler(void)
{
    APP_LCDIF_IRQHandler();
    __DSB();
}

/* Enable interrupt. */
void BOARD_EnableLcdInterrupt(void)
{
    IRQSTEER_EnableInterrupt(IRQSTEER, LCD_MOD_INT_IRQn);
}

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


void APP_LCDIF_IRQHandler(void)
{
    uint32_t intStatus;

    intStatus = ELCDIF_GetInterruptStatus(APP_ELCDIF);

    ELCDIF_ClearInterruptStatus(APP_ELCDIF, intStatus);

    if (intStatus & kELCDIF_CurFrameDone)
    {
        s_frameDone = true;
    }
    SDK_ISR_EXIT_BARRIER;
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
        .bufferAddr    = (uint32_t)s_frameBuffer[0],
        .pixelFormat   = kELCDIF_PixelFormatXRGB8888,
        .dataBus       = APP_LCDIF_DATA_BUS,
    };

#if (defined(APP_ELCDIF_HAS_DISPLAY_INTERFACE) && APP_ELCDIF_HAS_DISPLAY_INTERFACE)
    BOARD_InitDisplayInterface();
#endif
    ELCDIF_RgbModeInit(APP_ELCDIF, &config);
}

void APP_FillFrameBuffer(uint32_t frameBuffer[APP_IMG_HEIGHT][APP_IMG_WIDTH])
{
    /* Background color. */
    static const uint32_t bgColor = 0U;
    /* Foreground color. */
    static uint8_t fgColorIndex          = 0U;
    static const uint32_t fgColorTable[] = {0x000000FFU, 0x0000FF00U, 0x0000FFFFU, 0x00FF0000U,
                                            0x00FF00FFU, 0x00FFFF00U, 0x00FFFFFFU};
    uint32_t fgColor                     = fgColorTable[fgColorIndex];

    /* Position of the foreground rectangle. */
    static uint16_t upperLeftX  = 0U;
    static uint16_t upperLeftY  = 0U;
    static uint16_t lowerRightX = (APP_IMG_WIDTH - 1U) / 2U;
    static uint16_t lowerRightY = (APP_IMG_HEIGHT - 1U) / 2U;

    static int8_t incX = 1;
    static int8_t incY = 1;

    /* Change color in next forame or not. */
    static bool changeColor = false;

    uint32_t i, j;

    /* Background color. */
    for (i = 0; i < APP_IMG_HEIGHT; i++)
    {
        for (j = 0; j < APP_IMG_WIDTH; j++)
        {
            frameBuffer[i][j] = bgColor;
        }
    }

    /* Foreground color. */
    for (i = upperLeftY; i < lowerRightY; i++)
    {
        for (j = upperLeftX; j < lowerRightX; j++)
        {
            frameBuffer[i][j] = fgColor;
        }
    }

    /* Update the format: color and rectangle position. */
    upperLeftX += incX;
    upperLeftY += incY;
    lowerRightX += incX;
    lowerRightY += incY;

    changeColor = false;

    if (0U == upperLeftX)
    {
        incX        = 1;
        changeColor = true;
    }
    else if (APP_IMG_WIDTH - 1 == lowerRightX)
    {
        incX        = -1;
        changeColor = true;
    }

    if (0U == upperLeftY)
    {
        incY        = 1;
        changeColor = true;
    }
    else if (APP_IMG_HEIGHT - 1 == lowerRightY)
    {
        incY        = -1;
        changeColor = true;
    }

    if (changeColor)
    {
        fgColorIndex++;

        if (ARRAY_SIZE(fgColorTable) == fgColorIndex)
        {
            fgColorIndex = 0U;
        }
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    uint32_t frameBufferIndex = 0;

    sc_ipc_t ipc;
    ipc = BOARD_InitRpc();
    BOARD_BootClockRUN();

    sc_pm_set_resource_power_mode(ipc, SC_R_IRQSTR_M4_0, SC_PM_PW_MODE_ON);
    IRQSTEER_Init(IRQSTEER);

    BOARD_InitMemory();
    BOARD_InitUartPins(ipc);
    BOARD_InitLcdPins(ipc);
    BOARD_InitIOExpanderI2CPins(ipc);
    BOARD_InitDebugConsole_ADMA_UART0();
    BOARD_InitLcdifPixelClock();
    BOARD_InitLcd();

    PRINTF("LCDIF RGB example start...\r\n");

    APP_ELCDIF_Init();

    BOARD_EnableLcdInterrupt();

    /* Clear the frame buffer. */
    memset(s_frameBuffer, 0, sizeof(s_frameBuffer));

    APP_FillFrameBuffer(s_frameBuffer[frameBufferIndex]);

    ELCDIF_EnableInterrupts(APP_ELCDIF, kELCDIF_CurFrameDoneInterruptEnable);
    ELCDIF_RgbModeStart(APP_ELCDIF);

    while (1)
    {
        frameBufferIndex ^= 1U;

        APP_FillFrameBuffer(s_frameBuffer[frameBufferIndex]);

        ELCDIF_SetNextBufferAddr(APP_ELCDIF, (uint32_t)s_frameBuffer[frameBufferIndex]);

        s_frameDone = false;
        /* Wait for previous frame complete. */
        while (!s_frameDone)
        {
        }
    }
}
