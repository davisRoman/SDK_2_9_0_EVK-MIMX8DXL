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

/* UART2_RX (number AN33), UART2_RX */
/* Routed pin properties */
#define BOARD_INITPINS_UART2_RX_PERIPHERAL                             ADMA__FTM   /*!< Peripheral name */
#define BOARD_INITPINS_UART2_RX_SIGNAL                                    ftm_ch   /*!< Signal name */
#define BOARD_INITPINS_UART2_RX_CHANNEL                                        0   /*!< Signal channel */
#define BOARD_INITPINS_UART2_RX_PIN_NAME                                UART2_RX   /*!< Routed pin name */
#define BOARD_INITPINS_UART2_RX_PIN_FUNCTION_ID                    SC_P_UART2_RX   /*!< Pin function id */
#define BOARD_INITPINS_UART2_RX_LABEL                                 "UART2_RX"   /*!< Label */
#define BOARD_INITPINS_UART2_RX_NAME                                  "UART2_RX"   /*!< Identifier */

/* UART2_TX (number AP34), UART2_TX */
/* Routed pin properties */
#define BOARD_INITPINS_UART2_TX_PERIPHERAL                             ADMA__FTM   /*!< Peripheral name */
#define BOARD_INITPINS_UART2_TX_SIGNAL                                    ftm_ch   /*!< Signal name */
#define BOARD_INITPINS_UART2_TX_CHANNEL                                        1   /*!< Signal channel */
#define BOARD_INITPINS_UART2_TX_PIN_NAME                                UART2_TX   /*!< Routed pin name */
#define BOARD_INITPINS_UART2_TX_PIN_FUNCTION_ID                    SC_P_UART2_TX   /*!< Pin function id */
#define BOARD_INITPINS_UART2_TX_LABEL                                 "UART2_TX"   /*!< Label */
#define BOARD_INITPINS_UART2_TX_NAME                                  "UART2_TX"   /*!< Identifier */

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
