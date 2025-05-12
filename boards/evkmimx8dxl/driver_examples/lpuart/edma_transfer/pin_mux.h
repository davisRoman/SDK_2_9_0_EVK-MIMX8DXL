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

/* UART0_TX (number AN35), UART0_TX */
/* Routed pin properties */
#define BOARD_INITPINS_UART0_TX_PERIPHERAL                           ADMA__UART0   /*!< Peripheral name */
#define BOARD_INITPINS_UART0_TX_SIGNAL                                   uart_tx   /*!< Signal name */
#define BOARD_INITPINS_UART0_TX_PIN_NAME                                UART0_TX   /*!< Routed pin name */
#define BOARD_INITPINS_UART0_TX_PIN_FUNCTION_ID                    SC_P_UART0_TX   /*!< Pin function id */
#define BOARD_INITPINS_UART0_TX_LABEL                                 "UART0_TX"   /*!< Label */
#define BOARD_INITPINS_UART0_TX_NAME                                  "UART0_TX"   /*!< Identifier */

/* UART0_RX (number AM34), UART0_RX */
/* Routed pin properties */
#define BOARD_INITPINS_UART0_RX_PERIPHERAL                           ADMA__UART0   /*!< Peripheral name */
#define BOARD_INITPINS_UART0_RX_SIGNAL                                   uart_rx   /*!< Signal name */
#define BOARD_INITPINS_UART0_RX_PIN_NAME                                UART0_RX   /*!< Routed pin name */
#define BOARD_INITPINS_UART0_RX_PIN_FUNCTION_ID                    SC_P_UART0_RX   /*!< Pin function id */
#define BOARD_INITPINS_UART0_RX_LABEL                                 "UART0_RX"   /*!< Label */
#define BOARD_INITPINS_UART0_RX_NAME                                  "UART0_RX"   /*!< Identifier */

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
