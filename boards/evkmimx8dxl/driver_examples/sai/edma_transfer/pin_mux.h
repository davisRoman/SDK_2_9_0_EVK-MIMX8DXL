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

/* SPI3_CS0 (coord T34), SPI3_CS0 */
/* Routed pin properties */
#define BOARD_INITPINS_SPI3_CS0_PERIPHERAL                             ADMA__ACM   /*!< Peripheral name */
#define BOARD_INITPINS_SPI3_CS0_SIGNAL                              acm_mclk_out   /*!< Signal name */
#define BOARD_INITPINS_SPI3_CS0_CHANNEL                                        1   /*!< Signal channel */
#define BOARD_INITPINS_SPI3_CS0_PIN_NAME                                SPI3_CS0   /*!< Routed pin name */
#define BOARD_INITPINS_SPI3_CS0_PIN_FUNCTION_ID                    SC_P_SPI3_CS0   /*!< Pin function id */
#define BOARD_INITPINS_SPI3_CS0_LABEL                                 "SPI3_CS0"   /*!< Label */
#define BOARD_INITPINS_SPI3_CS0_NAME                                  "SPI3_CS0"   /*!< Identifier */

/* FLEXCAN0_RX (number AH34), SAI1_TXC */
/* Routed pin properties */
#define BOARD_INITPINS_SAI1_TXC_PERIPHERAL                            ADMA__SAI1   /*!< Peripheral name */
#define BOARD_INITPINS_SAI1_TXC_SIGNAL                                   sai_txc   /*!< Signal name */
#define BOARD_INITPINS_SAI1_TXC_PIN_NAME                             FLEXCAN0_RX   /*!< Routed pin name */
#define BOARD_INITPINS_SAI1_TXC_PIN_FUNCTION_ID                 SC_P_FLEXCAN0_RX   /*!< Pin function id */
#define BOARD_INITPINS_SAI1_TXC_LABEL                                 "SAI1_TXC"   /*!< Label */
#define BOARD_INITPINS_SAI1_TXC_NAME                                  "SAI1_TXC"   /*!< Identifier */

/* FLEXCAN0_TX (number AJ35), SAI1_TXFS */
/* Routed pin properties */
#define BOARD_INITPINS_SAI1_TXFS_PERIPHERAL                           ADMA__SAI1   /*!< Peripheral name */
#define BOARD_INITPINS_SAI1_TXFS_SIGNAL                                 sai_txfs   /*!< Signal name */
#define BOARD_INITPINS_SAI1_TXFS_PIN_NAME                            FLEXCAN0_TX   /*!< Routed pin name */
#define BOARD_INITPINS_SAI1_TXFS_PIN_FUNCTION_ID                SC_P_FLEXCAN0_TX   /*!< Pin function id */
#define BOARD_INITPINS_SAI1_TXFS_LABEL                               "SAI1_TXFS"   /*!< Label */
#define BOARD_INITPINS_SAI1_TXFS_NAME                                "SAI1_TXFS"   /*!< Identifier */

/* FLEXCAN1_RX (number AJ33), SAI1_TXD */
/* Routed pin properties */
#define BOARD_INITPINS_SAI1_TXD_PERIPHERAL                            ADMA__SAI1   /*!< Peripheral name */
#define BOARD_INITPINS_SAI1_TXD_SIGNAL                                   sai_txd   /*!< Signal name */
#define BOARD_INITPINS_SAI1_TXD_PIN_NAME                             FLEXCAN1_RX   /*!< Routed pin name */
#define BOARD_INITPINS_SAI1_TXD_PIN_FUNCTION_ID                 SC_P_FLEXCAN1_RX   /*!< Pin function id */
#define BOARD_INITPINS_SAI1_TXD_LABEL                                 "SAI1_TXD"   /*!< Label */
#define BOARD_INITPINS_SAI1_TXD_NAME                                  "SAI1_TXD"   /*!< Identifier */

/* FLEXCAN1_TX (number AK34), SAI1_RXD */
/* Routed pin properties */
#define BOARD_INITPINS_SAI1_RXD_PERIPHERAL                            ADMA__SAI1   /*!< Peripheral name */
#define BOARD_INITPINS_SAI1_RXD_SIGNAL                                   sai_rxd   /*!< Signal name */
#define BOARD_INITPINS_SAI1_RXD_PIN_NAME                             FLEXCAN1_TX   /*!< Routed pin name */
#define BOARD_INITPINS_SAI1_RXD_PIN_FUNCTION_ID                 SC_P_FLEXCAN1_TX   /*!< Pin function id */
#define BOARD_INITPINS_SAI1_RXD_LABEL                                 "SAI1_RXD"   /*!< Label */
#define BOARD_INITPINS_SAI1_RXD_NAME                                  "SAI1_RXD"   /*!< Identifier */

/* SPI1_SDO (number AR17), I2C2_SCL */
/* Routed pin properties */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_PERIPHERAL                   ADMA__I2C2   /*!< Peripheral name */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_SIGNAL                          i2c_scl   /*!< Signal name */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_PIN_NAME                       SPI1_SDO   /*!< Routed pin name */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_PIN_FUNCTION_ID           SC_P_SPI1_SDO   /*!< Pin function id */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_LABEL                        "I2C2_SCL"   /*!< Label */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_NAME                         "I2C2_SCL"   /*!< Identifier */

/* SPI1_SCK (number AP16), I2C2_SDA */
/* Routed pin properties */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_PERIPHERAL                   ADMA__I2C2   /*!< Peripheral name */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_SIGNAL                          i2c_sda   /*!< Signal name */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_PIN_NAME                       SPI1_SCK   /*!< Routed pin name */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_PIN_FUNCTION_ID           SC_P_SPI1_SCK   /*!< Pin function id */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_LABEL                        "I2C2_SDA"   /*!< Label */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_NAME                         "I2C2_SDA"   /*!< Identifier */

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
void BOARD_I2C_ConfigurePins(sc_ipc_t ipc);                /*!< Function assigned for the core: Cortex-M4F[m4] */

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
