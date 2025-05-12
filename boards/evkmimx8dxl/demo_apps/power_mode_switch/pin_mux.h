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

/* FLEXCAN2_TX (number AL33), FLEXCAN2_TX */
/* Routed pin properties */
#define BOARD_INITPINS_FLEXCAN2_TX_PERIPHERAL                     ADMA__FLEXCAN2   /*!< Peripheral name */
#define BOARD_INITPINS_FLEXCAN2_TX_SIGNAL                             flexcan_tx   /*!< Signal name */
#define BOARD_INITPINS_FLEXCAN2_TX_PIN_NAME                          FLEXCAN2_TX   /*!< Routed pin name */
#define BOARD_INITPINS_FLEXCAN2_TX_PIN_FUNCTION_ID              SC_P_FLEXCAN2_TX   /*!< Pin function id */
#define BOARD_INITPINS_FLEXCAN2_TX_LABEL                           "FLEXCAN2_TX"   /*!< Label */
#define BOARD_INITPINS_FLEXCAN2_TX_NAME                            "FLEXCAN2_TX"   /*!< Identifier */

/* FLEXCAN2_RX (number AL35), FLEXCAN2_RX */
/* Routed pin properties */
#define BOARD_INITPINS_FLEXCAN2_RX_PERIPHERAL                     ADMA__FLEXCAN2   /*!< Peripheral name */
#define BOARD_INITPINS_FLEXCAN2_RX_SIGNAL                             flexcan_rx   /*!< Signal name */
#define BOARD_INITPINS_FLEXCAN2_RX_PIN_NAME                          FLEXCAN2_RX   /*!< Routed pin name */
#define BOARD_INITPINS_FLEXCAN2_RX_PIN_FUNCTION_ID              SC_P_FLEXCAN2_RX   /*!< Pin function id */
#define BOARD_INITPINS_FLEXCAN2_RX_LABEL                           "FLEXCAN2_RX"   /*!< Label */
#define BOARD_INITPINS_FLEXCAN2_RX_NAME                            "FLEXCAN2_RX"   /*!< Identifier */

/* SPI1_SDI (number AP18), I2C3_SCL */
/* Routed pin properties */
#define BOARD_INITPINS_I2C3_SCL_PERIPHERAL                            ADMA__I2C3   /*!< Peripheral name */
#define BOARD_INITPINS_I2C3_SCL_SIGNAL                                   i2c_scl   /*!< Signal name */
#define BOARD_INITPINS_I2C3_SCL_PIN_NAME                                SPI1_SDI   /*!< Routed pin name */
#define BOARD_INITPINS_I2C3_SCL_PIN_FUNCTION_ID                    SC_P_SPI1_SDI   /*!< Pin function id */
#define BOARD_INITPINS_I2C3_SCL_LABEL                                 "I2C3_SCL"   /*!< Label */
#define BOARD_INITPINS_I2C3_SCL_NAME                                  "I2C3_SCL"   /*!< Identifier */

/* SPI1_CS0 (number AR15), I2C3_SDA */
/* Routed pin properties */
#define BOARD_INITPINS_I2C3_SDA_PERIPHERAL                            ADMA__I2C3   /*!< Peripheral name */
#define BOARD_INITPINS_I2C3_SDA_SIGNAL                                   i2c_sda   /*!< Signal name */
#define BOARD_INITPINS_I2C3_SDA_PIN_NAME                                SPI1_CS0   /*!< Routed pin name */
#define BOARD_INITPINS_I2C3_SDA_PIN_FUNCTION_ID                    SC_P_SPI1_CS0   /*!< Pin function id */
#define BOARD_INITPINS_I2C3_SDA_LABEL                                 "I2C3_SDA"   /*!< Label */
#define BOARD_INITPINS_I2C3_SDA_NAME                                  "I2C3_SDA"   /*!< Identifier */

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
