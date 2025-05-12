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

/* ENET1_RGMII_TX_CTL (coord R29), ENET1_RGMII_TX_CTL */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_TX_CTL_PERIPHERAL                 CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_TX_CTL_SIGNAL               enet_rgmii_tx_ctl   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_TX_CTL_PIN_NAME            ENET1_RGMII_TX_CTL   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_TX_CTL_PIN_FUNCTION_ID SC_P_ENET1_RGMII_TX_CTL  /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_TX_CTL_LABEL             "ENET1_RGMII_TX_CTL"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_TX_CTL_NAME              "ENET1_RGMII_TX_CTL"   /*!< Identifier */

/* ENET1_RGMII_RXC (coord G33), ENET1_RGMII_RXC */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_RXC_PERIPHERAL                    CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_RXC_SIGNAL                     enet_rgmii_rxc   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_RXC_PIN_NAME                  ENET1_RGMII_RXC   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_RXC_PIN_FUNCTION_ID      SC_P_ENET1_RGMII_RXC   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_RXC_LABEL                   "ENET1_RGMII_RXC"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_RXC_NAME                    "ENET1_RGMII_RXC"   /*!< Identifier */

/* ENET1_RGMII_RXD0 (coord J33), ENET1_RGMII_RXD0 */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_RXD0_PERIPHERAL                   CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_RXD0_SIGNAL                    enet_rgmii_rxd   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_RXD0_CHANNEL                                0   /*!< Signal channel */
#define BOARD_INITPINS_ENET1_RGMII_RXD0_PIN_NAME                ENET1_RGMII_RXD0   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_RXD0_PIN_FUNCTION_ID    SC_P_ENET1_RGMII_RXD0   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_RXD0_LABEL                 "ENET1_RGMII_RXD0"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_RXD0_NAME                  "ENET1_RGMII_RXD0"   /*!< Identifier */

/* ENET1_RGMII_TXD3 (coord L33), ENET1_RGMII_TXD3 */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_TXD3_PERIPHERAL                   CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_TXD3_SIGNAL                    enet_rgmii_txd   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_TXD3_CHANNEL                                3   /*!< Signal channel */
#define BOARD_INITPINS_ENET1_RGMII_TXD3_PIN_NAME                ENET1_RGMII_TXD3   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_TXD3_PIN_FUNCTION_ID    SC_P_ENET1_RGMII_TXD3   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_TXD3_LABEL                 "ENET1_RGMII_TXD3"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_TXD3_NAME                  "ENET1_RGMII_TXD3"   /*!< Identifier */

/* ENET1_RGMII_TXD0 (coord N33), ENET1_RGMII_TXD0 */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_TXD0_PERIPHERAL                   CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_TXD0_SIGNAL                    enet_rgmii_txd   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_TXD0_CHANNEL                                0   /*!< Signal channel */
#define BOARD_INITPINS_ENET1_RGMII_TXD0_PIN_NAME                ENET1_RGMII_TXD0   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_TXD0_PIN_FUNCTION_ID    SC_P_ENET1_RGMII_TXD0   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_TXD0_LABEL                 "ENET1_RGMII_TXD0"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_TXD0_NAME                  "ENET1_RGMII_TXD0"   /*!< Identifier */

/* ENET1_RGMII_RXD1 (coord F34), ENET1_RGMII_RXD1 */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_RXD1_PERIPHERAL                   CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_RXD1_SIGNAL                    enet_rgmii_rxd   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_RXD1_CHANNEL                                1   /*!< Signal channel */
#define BOARD_INITPINS_ENET1_RGMII_RXD1_PIN_NAME                ENET1_RGMII_RXD1   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_RXD1_PIN_FUNCTION_ID    SC_P_ENET1_RGMII_RXD1   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_RXD1_LABEL                 "ENET1_RGMII_RXD1"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_RXD1_NAME                  "ENET1_RGMII_RXD1"   /*!< Identifier */

/* ENET1_RGMII_RXD2 (coord H34), ENET1_RGMII_RXD2 */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_RXD2_PERIPHERAL                   CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_RXD2_SIGNAL                    enet_rgmii_rxd   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_RXD2_CHANNEL                                2   /*!< Signal channel */
#define BOARD_INITPINS_ENET1_RGMII_RXD2_PIN_NAME                ENET1_RGMII_RXD2   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_RXD2_PIN_FUNCTION_ID    SC_P_ENET1_RGMII_RXD2   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_RXD2_LABEL                 "ENET1_RGMII_RXD2"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_RXD2_NAME                  "ENET1_RGMII_RXD2"   /*!< Identifier */

/* ENET1_RGMII_TXD2 (coord M34), ENET1_RGMII_TXD2 */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_TXD2_PERIPHERAL                   CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_TXD2_SIGNAL                    enet_rgmii_txd   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_TXD2_CHANNEL                                2   /*!< Signal channel */
#define BOARD_INITPINS_ENET1_RGMII_TXD2_PIN_NAME                ENET1_RGMII_TXD2   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_TXD2_PIN_FUNCTION_ID    SC_P_ENET1_RGMII_TXD2   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_TXD2_LABEL                 "ENET1_RGMII_TXD2"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_TXD2_NAME                  "ENET1_RGMII_TXD2"   /*!< Identifier */

/* ENET1_RGMII_RXD3 (coord G35), ENET1_RGMII_RXD3 */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_RXD3_PERIPHERAL                   CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_RXD3_SIGNAL                    enet_rgmii_rxd   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_RXD3_CHANNEL                                3   /*!< Signal channel */
#define BOARD_INITPINS_ENET1_RGMII_RXD3_PIN_NAME                ENET1_RGMII_RXD3   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_RXD3_PIN_FUNCTION_ID    SC_P_ENET1_RGMII_RXD3   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_RXD3_LABEL                 "ENET1_RGMII_RXD3"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_RXD3_NAME                  "ENET1_RGMII_RXD3"   /*!< Identifier */

/* ENET1_RGMII_RX_CTL (coord J35), ENET1_RGMII_RX_CTL */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_RX_CTL_PERIPHERAL                 CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_RX_CTL_SIGNAL               enet_rgmii_rx_ctl   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_RX_CTL_PIN_NAME            ENET1_RGMII_RX_CTL   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_RX_CTL_PIN_FUNCTION_ID SC_P_ENET1_RGMII_RX_CTL  /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_RX_CTL_LABEL             "ENET1_RGMII_RX_CTL"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_RX_CTL_NAME              "ENET1_RGMII_RX_CTL"   /*!< Identifier */

/* ENET1_RGMII_TXC (coord L35), ENET1_RGMII_TXC */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_TXC_PERIPHERAL                    CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_TXC_SIGNAL                     enet_rgmii_txc   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_TXC_PIN_NAME                  ENET1_RGMII_TXC   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_TXC_PIN_FUNCTION_ID      SC_P_ENET1_RGMII_TXC   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_TXC_LABEL                   "ENET1_RGMII_TXC"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_TXC_NAME                    "ENET1_RGMII_TXC"   /*!< Identifier */

/* ENET1_RGMII_TXD1 (coord N35), ENET1_RGMII_TXD1 */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_RGMII_TXD1_PERIPHERAL                   CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_RGMII_TXD1_SIGNAL                    enet_rgmii_txd   /*!< Signal name */
#define BOARD_INITPINS_ENET1_RGMII_TXD1_CHANNEL                                1   /*!< Signal channel */
#define BOARD_INITPINS_ENET1_RGMII_TXD1_PIN_NAME                ENET1_RGMII_TXD1   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_RGMII_TXD1_PIN_FUNCTION_ID    SC_P_ENET1_RGMII_TXD1   /*!< Pin function id */
#define BOARD_INITPINS_ENET1_RGMII_TXD1_LABEL                 "ENET1_RGMII_TXD1"   /*!< Label */
#define BOARD_INITPINS_ENET1_RGMII_TXD1_NAME                  "ENET1_RGMII_TXD1"   /*!< Identifier */

/* ENET1_REFCLK_125M_25M (coord K34), ENET1_REFCLK_125M_25M */
/* Routed pin properties */
#define BOARD_INITPINS_ENET1_REFCLK_125M_25M_PERIPHERAL              CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET1_REFCLK_125M_25M_SIGNAL         enet_refclk_125m_25m   /*!< Signal name */
#define BOARD_INITPINS_ENET1_REFCLK_125M_25M_PIN_NAME      ENET1_REFCLK_125M_25M   /*!< Routed pin name */
#define BOARD_INITPINS_ENET1_REFCLK_125M_25M_PIN_FUNCTION_ID SC_P_ENET1_REFCLK_125M_25M /*!< Pin function id */
#define BOARD_INITPINS_ENET1_REFCLK_125M_25M_LABEL       "ENET1_REFCLK_125M_25M"   /*!< Label */
#define BOARD_INITPINS_ENET1_REFCLK_125M_25M_NAME        "ENET1_REFCLK_125M_25M"   /*!< Identifier */

/* ENET0_MDC (coord E33), ENET0_MDC */
/* Routed pin properties */
#define BOARD_INITPINS_ENET0_MDC_PERIPHERAL                          CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET0_MDC_SIGNAL                                 enet_mdc   /*!< Signal name */
#define BOARD_INITPINS_ENET0_MDC_PIN_NAME                              ENET0_MDC   /*!< Routed pin name */
#define BOARD_INITPINS_ENET0_MDC_PIN_FUNCTION_ID                  SC_P_ENET0_MDC   /*!< Pin function id */
#define BOARD_INITPINS_ENET0_MDC_LABEL                               "ENET0_MDC"   /*!< Label */
#define BOARD_INITPINS_ENET0_MDC_NAME                                "ENET0_MDC"   /*!< Identifier */

/* ENET0_MDIO (coord E35), ENET0_MDIO */
/* Routed pin properties */
#define BOARD_INITPINS_ENET0_MDIO_PERIPHERAL                         CONN__ENET1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET0_MDIO_SIGNAL                               enet_mdio   /*!< Signal name */
#define BOARD_INITPINS_ENET0_MDIO_PIN_NAME                            ENET0_MDIO   /*!< Routed pin name */
#define BOARD_INITPINS_ENET0_MDIO_PIN_FUNCTION_ID                SC_P_ENET0_MDIO   /*!< Pin function id */
#define BOARD_INITPINS_ENET0_MDIO_LABEL                             "ENET0_MDIO"   /*!< Label */
#define BOARD_INITPINS_ENET0_MDIO_NAME                              "ENET0_MDIO"   /*!< Identifier */

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
