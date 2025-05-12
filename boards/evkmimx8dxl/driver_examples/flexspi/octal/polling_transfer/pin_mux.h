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

/* QSPI0A_DATA0 (number AR11), QSPI0_DATA0 */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DATA0_PERIPHERAL                       LSIO__QSPI_A   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DATA0_SIGNAL                            qspi_a_data   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DATA0_CHANNEL                                     0   /*!< Signal channel */
#define BOARD_INITPINS_QSPI0_DATA0_PIN_NAME                         QSPI0A_DATA0   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DATA0_PIN_FUNCTION_ID             SC_P_QSPI0A_DATA0   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DATA0_LABEL                           "QSPI0_DATA0"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DATA0_NAME                            "QSPI0_DATA0"   /*!< Identifier */

/* QSPI0A_DATA1 (number AN13), QSPI0_DATA1 */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DATA1_PERIPHERAL                       LSIO__QSPI_A   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DATA1_SIGNAL                            qspi_a_data   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DATA1_CHANNEL                                     1   /*!< Signal channel */
#define BOARD_INITPINS_QSPI0_DATA1_PIN_NAME                         QSPI0A_DATA1   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DATA1_PIN_FUNCTION_ID             SC_P_QSPI0A_DATA1   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DATA1_LABEL                           "QSPI0_DATA1"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DATA1_NAME                            "QSPI0_DATA1"   /*!< Identifier */

/* QSPI0A_DATA2 (number AN9), QSPI0_DATA2 */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DATA2_PERIPHERAL                       LSIO__QSPI_A   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DATA2_SIGNAL                            qspi_a_data   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DATA2_CHANNEL                                     2   /*!< Signal channel */
#define BOARD_INITPINS_QSPI0_DATA2_PIN_NAME                         QSPI0A_DATA2   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DATA2_PIN_FUNCTION_ID             SC_P_QSPI0A_DATA2   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DATA2_LABEL                           "QSPI0_DATA2"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DATA2_NAME                            "QSPI0_DATA2"   /*!< Identifier */

/* QSPI0A_DATA3 (number AN11), QSPI0_DATA3 */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DATA3_PERIPHERAL                       LSIO__QSPI_A   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DATA3_SIGNAL                            qspi_a_data   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DATA3_CHANNEL                                     3   /*!< Signal channel */
#define BOARD_INITPINS_QSPI0_DATA3_PIN_NAME                         QSPI0A_DATA3   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DATA3_PIN_FUNCTION_ID             SC_P_QSPI0A_DATA3   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DATA3_LABEL                           "QSPI0_DATA3"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DATA3_NAME                            "QSPI0_DATA3"   /*!< Identifier */

/* QSPI0A_SCLK (number AP8), QSPI0A_SCLK */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0A_SCLK_PERIPHERAL                       LSIO__QSPI_A   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0A_SCLK_SIGNAL                            qspi_a_sclk   /*!< Signal name */
#define BOARD_INITPINS_QSPI0A_SCLK_PIN_NAME                          QSPI0A_SCLK   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0A_SCLK_PIN_FUNCTION_ID              SC_P_QSPI0A_SCLK   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0A_SCLK_LABEL                           "QSPI0A_SCLK"   /*!< Label */
#define BOARD_INITPINS_QSPI0A_SCLK_NAME                            "QSPI0A_SCLK"   /*!< Identifier */

/* QSPI0A_SS0_B (number AN7), QSPI0A_SS0_B */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0A_SS0_B_PERIPHERAL                      LSIO__QSPI_A   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0A_SS0_B_SIGNAL                          qspi_a_ss0_b   /*!< Signal name */
#define BOARD_INITPINS_QSPI0A_SS0_B_PIN_NAME                        QSPI0A_SS0_B   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0A_SS0_B_PIN_FUNCTION_ID            SC_P_QSPI0A_SS0_B   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0A_SS0_B_LABEL                         "QSPI0A_SS0_B"   /*!< Label */
#define BOARD_INITPINS_QSPI0A_SS0_B_NAME                          "QSPI0A_SS0_B"   /*!< Identifier */

/* QSPI0B_DATA0 (number AP10), QSPI0_DATA4 */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DATA4_PERIPHERAL                       LSIO__QSPI_B   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DATA4_SIGNAL                            qspi_b_data   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DATA4_CHANNEL                                     0   /*!< Signal channel */
#define BOARD_INITPINS_QSPI0_DATA4_PIN_NAME                         QSPI0B_DATA0   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DATA4_PIN_FUNCTION_ID             SC_P_QSPI0B_DATA0   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DATA4_LABEL                           "QSPI0_DATA4"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DATA4_NAME                            "QSPI0_DATA4"   /*!< Identifier */

/* QSPI0B_DATA1 (number AP12), QSPI0_DATA5 */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DATA5_PERIPHERAL                       LSIO__QSPI_B   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DATA5_SIGNAL                            qspi_b_data   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DATA5_CHANNEL                                     1   /*!< Signal channel */
#define BOARD_INITPINS_QSPI0_DATA5_PIN_NAME                         QSPI0B_DATA1   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DATA5_PIN_FUNCTION_ID             SC_P_QSPI0B_DATA1   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DATA5_LABEL                           "QSPI0_DATA5"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DATA5_NAME                            "QSPI0_DATA5"   /*!< Identifier */

/* QSPI0B_DATA2 (number AR13), QSPI0_DATA6 */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DATA6_PERIPHERAL                       LSIO__QSPI_B   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DATA6_SIGNAL                            qspi_b_data   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DATA6_CHANNEL                                     2   /*!< Signal channel */
#define BOARD_INITPINS_QSPI0_DATA6_PIN_NAME                         QSPI0B_DATA2   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DATA6_PIN_FUNCTION_ID             SC_P_QSPI0B_DATA2   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DATA6_LABEL                           "QSPI0_DATA6"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DATA6_NAME                            "QSPI0_DATA6"   /*!< Identifier */

/* QSPI0B_DATA3 (number AP14), QSPI0_DATA7 */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DATA7_PERIPHERAL                       LSIO__QSPI_B   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DATA7_SIGNAL                            qspi_b_data   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DATA7_CHANNEL                                     3   /*!< Signal channel */
#define BOARD_INITPINS_QSPI0_DATA7_PIN_NAME                         QSPI0B_DATA3   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DATA7_PIN_FUNCTION_ID             SC_P_QSPI0B_DATA3   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DATA7_LABEL                           "QSPI0_DATA7"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DATA7_NAME                            "QSPI0_DATA7"   /*!< Identifier */

/* QSPI0A_DQS (number AR9), QSPI0_DQS */
/* Routed pin properties */
#define BOARD_INITPINS_QSPI0_DQS_PERIPHERAL                         LSIO__QSPI_A   /*!< Peripheral name */
#define BOARD_INITPINS_QSPI0_DQS_SIGNAL                               qspi_a_dqs   /*!< Signal name */
#define BOARD_INITPINS_QSPI0_DQS_PIN_NAME                             QSPI0A_DQS   /*!< Routed pin name */
#define BOARD_INITPINS_QSPI0_DQS_PIN_FUNCTION_ID                 SC_P_QSPI0A_DQS   /*!< Pin function id */
#define BOARD_INITPINS_QSPI0_DQS_LABEL                               "QSPI0_DQS"   /*!< Label */
#define BOARD_INITPINS_QSPI0_DQS_NAME                                "QSPI0_DQS"   /*!< Identifier */

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
