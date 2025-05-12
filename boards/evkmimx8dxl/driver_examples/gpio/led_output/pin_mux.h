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

/* SPI3_SDO (coord R35), SPI3_SDO */
/* Routed pin properties */
#define BOARD_INITPINS_SPI3_SDO_PERIPHERAL                           LSIO__GPIO0   /*!< Peripheral name */
#define BOARD_INITPINS_SPI3_SDO_SIGNAL                                   gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SPI3_SDO_CHANNEL                                       14   /*!< Signal channel */
#define BOARD_INITPINS_SPI3_SDO_PIN_NAME                                SPI3_SDO   /*!< Routed pin name */
#define BOARD_INITPINS_SPI3_SDO_PIN_FUNCTION_ID                    SC_P_SPI3_SDO   /*!< Pin function id */
#define BOARD_INITPINS_SPI3_SDO_LABEL                                 "SPI3_SDO"   /*!< Label */
#define BOARD_INITPINS_SPI3_SDO_NAME                                  "SPI3_SDO"   /*!< Identifier */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SPI3_SDO_GPIO                                 LSIO__GPIO0   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SPI3_SDO_GPIO_PIN                                     14U   /*!< GPIO pin number */
#define BOARD_INITPINS_SPI3_SDO_GPIO_PIN_MASK                        (1U << 14U)   /*!< GPIO pin mask */

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
