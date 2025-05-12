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
#define LPUART_INITPINS_UART0_TX_PERIPHERAL                          ADMA__UART0   /*!< Peripheral name */
#define LPUART_INITPINS_UART0_TX_SIGNAL                                  uart_tx   /*!< Signal name */
#define LPUART_INITPINS_UART0_TX_PIN_NAME                               UART0_TX   /*!< Routed pin name */
#define LPUART_INITPINS_UART0_TX_PIN_FUNCTION_ID                   SC_P_UART0_TX   /*!< Pin function id */
#define LPUART_INITPINS_UART0_TX_LABEL                                "UART0_TX"   /*!< Label */
#define LPUART_INITPINS_UART0_TX_NAME                                 "UART0_TX"   /*!< Identifier */

/* UART0_RX (number AM34), UART0_RX */
/* Routed pin properties */
#define LPUART_INITPINS_UART0_RX_PERIPHERAL                          ADMA__UART0   /*!< Peripheral name */
#define LPUART_INITPINS_UART0_RX_SIGNAL                                  uart_rx   /*!< Signal name */
#define LPUART_INITPINS_UART0_RX_PIN_NAME                               UART0_RX   /*!< Routed pin name */
#define LPUART_INITPINS_UART0_RX_PIN_FUNCTION_ID                   SC_P_UART0_RX   /*!< Pin function id */
#define LPUART_INITPINS_UART0_RX_LABEL                                "UART0_RX"   /*!< Label */
#define LPUART_INITPINS_UART0_RX_NAME                                 "UART0_RX"   /*!< Identifier */

/* UART0_RX (number AM34), UART0_RX */
/* Routed pin properties */
#define LPUART_DEINITPINS_UART0_RX_PERIPHERAL                        LSIO__GPIO1   /*!< Peripheral name */
#define LPUART_DEINITPINS_UART0_RX_SIGNAL                                gpio_io   /*!< Signal name */
#define LPUART_DEINITPINS_UART0_RX_CHANNEL                                    21   /*!< Signal channel */
#define LPUART_DEINITPINS_UART0_RX_PIN_NAME                             UART0_RX   /*!< Routed pin name */
#define LPUART_DEINITPINS_UART0_RX_PIN_FUNCTION_ID                 SC_P_UART0_RX   /*!< Pin function id */
#define LPUART_DEINITPINS_UART0_RX_LABEL                              "UART0_RX"   /*!< Label */
#define LPUART_DEINITPINS_UART0_RX_NAME                               "UART0_RX"   /*!< Identifier */

/* Symbols to be used with GPIO driver */
#define LPUART_DEINITPINS_UART0_RX_GPIO                              LSIO__GPIO1   /*!< GPIO peripheral base pointer */
#define LPUART_DEINITPINS_UART0_RX_GPIO_PIN                                  21U   /*!< GPIO pin number */
#define LPUART_DEINITPINS_UART0_RX_GPIO_PIN_MASK                     (1U << 21U)   /*!< GPIO pin mask */

/* UART0_TX (number AN35), UART0_TX */
/* Routed pin properties */
#define LPUART_DEINITPINS_UART0_TX_PERIPHERAL                        LSIO__GPIO1   /*!< Peripheral name */
#define LPUART_DEINITPINS_UART0_TX_SIGNAL                                gpio_io   /*!< Signal name */
#define LPUART_DEINITPINS_UART0_TX_CHANNEL                                    22   /*!< Signal channel */
#define LPUART_DEINITPINS_UART0_TX_PIN_NAME                             UART0_TX   /*!< Routed pin name */
#define LPUART_DEINITPINS_UART0_TX_PIN_FUNCTION_ID                 SC_P_UART0_TX   /*!< Pin function id */
#define LPUART_DEINITPINS_UART0_TX_LABEL                              "UART0_TX"   /*!< Label */
#define LPUART_DEINITPINS_UART0_TX_NAME                               "UART0_TX"   /*!< Identifier */

/* Symbols to be used with GPIO driver */
#define LPUART_DEINITPINS_UART0_TX_GPIO                              LSIO__GPIO1   /*!< GPIO peripheral base pointer */
#define LPUART_DEINITPINS_UART0_TX_GPIO_PIN                                  22U   /*!< GPIO pin number */
#define LPUART_DEINITPINS_UART0_TX_GPIO_PIN_MASK                     (1U << 22U)   /*!< GPIO pin mask */

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

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 * @param ipc scfw ipchandle.
 *
 */
void LPUART_InitPins(sc_ipc_t ipc);                        /*!< Function assigned for the core: Cortex-M4F[m4] */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 * @param ipc scfw ipchandle.
 *
 */
void LPUART_DeinitPins(sc_ipc_t ipc);                      /*!< Function assigned for the core: Cortex-M4F[m4] */

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
