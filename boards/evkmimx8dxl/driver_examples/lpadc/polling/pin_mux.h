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

/* ADC_IN2 (number AC33), ADC_IN2 */
/* Routed pin properties */
#define BOARD_INITPINS_ADC_IN2_PERIPHERAL                             M40__UART0   /*!< Peripheral name */
#define BOARD_INITPINS_ADC_IN2_SIGNAL                                    uart_rx   /*!< Signal name */
#define BOARD_INITPINS_ADC_IN2_PIN_NAME                                  ADC_IN2   /*!< Routed pin name */
#define BOARD_INITPINS_ADC_IN2_PIN_FUNCTION_ID                      SC_P_ADC_IN2   /*!< Pin function id */
#define BOARD_INITPINS_ADC_IN2_LABEL                                   "ADC_IN2"   /*!< Label */
#define BOARD_INITPINS_ADC_IN2_NAME                                    "ADC_IN2"   /*!< Identifier */

/* ADC_IN3 (number AF34), ADC_IN3 */
/* Routed pin properties */
#define BOARD_INITPINS_ADC_IN3_PERIPHERAL                             M40__UART0   /*!< Peripheral name */
#define BOARD_INITPINS_ADC_IN3_SIGNAL                                    uart_tx   /*!< Signal name */
#define BOARD_INITPINS_ADC_IN3_PIN_NAME                                  ADC_IN3   /*!< Routed pin name */
#define BOARD_INITPINS_ADC_IN3_PIN_FUNCTION_ID                      SC_P_ADC_IN3   /*!< Pin function id */
#define BOARD_INITPINS_ADC_IN3_LABEL                                   "ADC_IN3"   /*!< Label */
#define BOARD_INITPINS_ADC_IN3_NAME                                    "ADC_IN3"   /*!< Identifier */

/* ADC_IN5 (number AG35), LCD_17 */
/* Routed pin properties */
#define BOARD_INITPINS_LCD_17_PERIPHERAL                               ADMA__ADC   /*!< Peripheral name */
#define BOARD_INITPINS_LCD_17_SIGNAL                                      adc_in   /*!< Signal name */
#define BOARD_INITPINS_LCD_17_CHANNEL                                          5   /*!< Signal channel */
#define BOARD_INITPINS_LCD_17_PIN_NAME                                   ADC_IN5   /*!< Routed pin name */
#define BOARD_INITPINS_LCD_17_PIN_FUNCTION_ID                       SC_P_ADC_IN5   /*!< Pin function id */
#define BOARD_INITPINS_LCD_17_LABEL                                     "LCD_17"   /*!< Label */
#define BOARD_INITPINS_LCD_17_NAME                                      "LCD_17"   /*!< Identifier */

/* SCU_GPIO0_00 (number AR27) */
/* Routed pin properties */
#define BOARD_INITPINS_SCU_GPIO0_00_PERIPHERAL                              M40__UART0   /*!< Peripheral name */
#define BOARD_INITPINS_SCU_GPIO0_00_SIGNAL                                     uart_rx   /*!< Signal name */
#define BOARD_INITPINS_SCU_GPIO0_00_PIN_NAME                              SCU_GPIO0_00   /*!< Routed pin name */
#define BOARD_INITPINS_SCU_GPIO0_00_PIN_FUNCTION_ID                  SC_P_SCU_GPIO0_00   /*!< Pin function id */
#define BOARD_INITPINS_SCU_GPIO0_00_LABEL                               "SCU_GPIO0_00"   /*!< Label */
#define BOARD_INITPINS_SCU_GPIO0_00_NAME                                "SCU_GPIO0_00"   /*!< Identifier */

/* SCU_GPIO0_01 (number AP26) */
/* Routed pin properties */
#define BOARD_INITPINS_SCU_GPIO0_01_PERIPHERAL                              M40__UART0   /*!< Peripheral name */
#define BOARD_INITPINS_SCU_GPIO0_01_SIGNAL                                     uart_tx   /*!< Signal name */
#define BOARD_INITPINS_SCU_GPIO0_01_PIN_NAME                              SCU_GPIO0_01   /*!< Routed pin name */
#define BOARD_INITPINS_SCU_GPIO0_01_PIN_FUNCTION_ID                  SC_P_SCU_GPIO0_01   /*!< Pin function id */
#define BOARD_INITPINS_SCU_GPIO0_01_LABEL                               "SCU_GPIO0_01"   /*!< Label */
#define BOARD_INITPINS_SCU_GPIO0_01_NAME                                "SCU_GPIO0_01"   /*!< Identifier */

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
void BOARD_InitPins(sc_ipc_t ipc);                         /*!< Function assigned for the core: Cortex-M4F[m4] */

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
