/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

#include "board.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/* UART0_RX (number AM34), UART0_RX */
#define BOARD_INITUARTPINS_UART0_RX_PIN_FUNCTION_ID                SC_P_UART0_RX   /*!< Pin function id */

/* UART0_TX (number AN35), UART0_TX */
#define BOARD_INITUARTPINS_UART0_TX_PIN_FUNCTION_ID                SC_P_UART0_TX   /*!< Pin function id */

/* MCLK_OUT0 (coord V34), LCD_CLK */
#define BOARD_INITLCDPINS_LCD_CLK_PIN_FUNCTION_ID                 SC_P_MCLK_OUT0   /*!< Pin function id */

/* MCLK_IN1 (coord U35), LCD_03 */
#define BOARD_INITLCDPINS_LCD_03_PIN_FUNCTION_ID                   SC_P_MCLK_IN1   /*!< Pin function id */

/* SPI3_CS0 (coord T34), SPI3_CS0 */
#define BOARD_INITLCDPINS_SPI3_CS0_PIN_FUNCTION_ID                 SC_P_SPI3_CS0   /*!< Pin function id */

/* MCLK_IN0 (coord U33), LCD_VSYNC */
#define BOARD_INITLCDPINS_LCD_VSYNC_PIN_FUNCTION_ID                SC_P_MCLK_IN0   /*!< Pin function id */

/* SPI3_SCK (coord P34), SPI3_SCK */
#define BOARD_INITLCDPINS_SPI3_SCK_PIN_FUNCTION_ID                 SC_P_SPI3_SCK   /*!< Pin function id */

/* SPI3_SDO (coord R35), SPI3_SDO */
#define BOARD_INITLCDPINS_SPI3_SDO_PIN_FUNCTION_ID                 SC_P_SPI3_SDO   /*!< Pin function id */

/* SPI3_SDI (coord R33), SPI3_SDI */
#define BOARD_INITLCDPINS_SPI3_SDI_PIN_FUNCTION_ID                 SC_P_SPI3_SDI   /*!< Pin function id */

/* ENET1_RGMII_TXD3 (coord L33), ENET1_RGMII_TXD3 */
#define BOARD_INITLCDPINS_ENET1_RGMII_TXD3_PIN_FUNCTION_ID SC_P_ENET1_RGMII_TXD3   /*!< Pin function id */

/* UART1_TX (coord W35), UART1_TX */
#define BOARD_INITLCDPINS_UART1_TX_PIN_FUNCTION_ID                 SC_P_UART1_TX   /*!< Pin function id */

/* UART1_RX (coord W33), UART1_RX */
#define BOARD_INITLCDPINS_UART1_RX_PIN_FUNCTION_ID                 SC_P_UART1_RX   /*!< Pin function id */

/* UART1_RTS_B (coord W29), UART1_RTS_B */
#define BOARD_INITLCDPINS_UART1_RTS_B_PIN_FUNCTION_ID           SC_P_UART1_RTS_B   /*!< Pin function id */

/* UART1_CTS_B (number AA29), UART1_CTS_B */
#define BOARD_INITLCDPINS_UART1_CTS_B_PIN_FUNCTION_ID           SC_P_UART1_CTS_B   /*!< Pin function id */

/* SPI0_SCK (coord Y34), SPI0_SCK */
#define BOARD_INITLCDPINS_SPI0_SCK_PIN_FUNCTION_ID                 SC_P_SPI0_SCK   /*!< Pin function id */

/* SPI0_SDI (number AA33), SPI0_SDI */
#define BOARD_INITLCDPINS_SPI0_SDI_PIN_FUNCTION_ID                 SC_P_SPI0_SDI   /*!< Pin function id */

/* SPI0_SDO (number AA35), SPI0_SDO */
#define BOARD_INITLCDPINS_SPI0_SDO_PIN_FUNCTION_ID                 SC_P_SPI0_SDO   /*!< Pin function id */

/* SPI0_CS1 (number AC35), SPI0_CS1 */
#define BOARD_INITLCDPINS_SPI0_CS1_PIN_FUNCTION_ID                 SC_P_SPI0_CS1   /*!< Pin function id */

/* SPI0_CS0 (number AB34), SPI0_CS0 */
#define BOARD_INITLCDPINS_SPI0_CS0_PIN_FUNCTION_ID                 SC_P_SPI0_CS0   /*!< Pin function id */

/* ADC_IN1 (number AE35), LCD_13 */
#define BOARD_INITLCDPINS_LCD_13_PIN_FUNCTION_ID                    SC_P_ADC_IN1   /*!< Pin function id */

/* ADC_IN0 (number AD34), LCD_14 */
#define BOARD_INITLCDPINS_LCD_14_PIN_FUNCTION_ID                    SC_P_ADC_IN0   /*!< Pin function id */

/* ADC_IN3 (number AF34), ADC_IN3 */
#define BOARD_INITLCDPINS_ADC_IN3_PIN_FUNCTION_ID                   SC_P_ADC_IN3   /*!< Pin function id */

/* ADC_IN2 (number AC33), ADC_IN2 */
#define BOARD_INITLCDPINS_ADC_IN2_PIN_FUNCTION_ID                   SC_P_ADC_IN2   /*!< Pin function id */

/* ADC_IN5 (number AG35), LCD_17 */
#define BOARD_INITLCDPINS_LCD_17_PIN_FUNCTION_ID                    SC_P_ADC_IN5   /*!< Pin function id */

/* SPI1_SCK (number AP16), I2C2_SDA */
#define BOARD_INITIOEXPANDERI2CPINS_I2C2_SDA_PIN_FUNCTION_ID       SC_P_SPI1_SCK   /*!< Pin function id */

/* SPI1_SDO (number AR17), I2C2_SCL */
#define BOARD_INITIOEXPANDERI2CPINS_I2C2_SCL_PIN_FUNCTION_ID       SC_P_SPI1_SDO   /*!< Pin function id */

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 * @param ipc scfw ipchandle.
 *
 */
void BOARD_InitUartPins(sc_ipc_t ipc);                     /*!< Function assigned for the core: Cortex-M4F[m4] */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 * @param ipc scfw ipchandle.
 *
 */
void BOARD_InitLcdPins(sc_ipc_t ipc);                      /*!< Function assigned for the core: Cortex-M4F[m4] */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 * @param ipc scfw ipchandle.
 *
 */
void BOARD_InitIOExpanderI2CPins(sc_ipc_t ipc);            /*!< Function assigned for the core: Cortex-M4F[m4] */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
