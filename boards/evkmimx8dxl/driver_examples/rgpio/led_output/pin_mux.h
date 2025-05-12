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

/* SPI0_SCK (coord Y34), SPI0_SCK */
/* Routed pin properties */
#define BOARD_INITPINS_SPI0_SCK_PERIPHERAL                            M40__GPIO0   /*!< Peripheral name */
#define BOARD_INITPINS_SPI0_SCK_SIGNAL                                   gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SPI0_SCK_CHANNEL                                       00   /*!< Signal channel */
#define BOARD_INITPINS_SPI0_SCK_PIN_NAME                                SPI0_SCK   /*!< Routed pin name */
#define BOARD_INITPINS_SPI0_SCK_PIN_FUNCTION_ID                    SC_P_SPI0_SCK   /*!< Pin function id */
#define BOARD_INITPINS_SPI0_SCK_LABEL                                 "SPI0_SCK"   /*!< Label */
#define BOARD_INITPINS_SPI0_SCK_NAME                                  "SPI0_SCK"   /*!< Identifier */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SPI0_SCK_GPIO                                  M40__GPIO0   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SPI0_SCK_GPIO_PIN                                      0U   /*!< GPIO pin number */
#define BOARD_INITPINS_SPI0_SCK_GPIO_PIN_MASK                         (1U << 0U)   /*!< GPIO pin mask */

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
