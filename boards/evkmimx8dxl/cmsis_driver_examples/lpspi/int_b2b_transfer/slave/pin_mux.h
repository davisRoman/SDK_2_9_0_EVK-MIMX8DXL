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

/* SPI3_CS1 (coord U29), SPI3_CS1 */
/* Routed pin properties */
#define LPSPI_INITPINS_SPI3_CS1_PERIPHERAL                            ADMA__SPI3   /*!< Peripheral name */
#define LPSPI_INITPINS_SPI3_CS1_SIGNAL                                    spi_cs   /*!< Signal name */
#define LPSPI_INITPINS_SPI3_CS1_CHANNEL                                        1   /*!< Signal channel */
#define LPSPI_INITPINS_SPI3_CS1_PIN_NAME                                SPI3_CS1   /*!< Routed pin name */
#define LPSPI_INITPINS_SPI3_CS1_PIN_FUNCTION_ID                    SC_P_SPI3_CS1   /*!< Pin function id */
#define LPSPI_INITPINS_SPI3_CS1_LABEL                                 "SPI3_CS1"   /*!< Label */
#define LPSPI_INITPINS_SPI3_CS1_NAME                                  "SPI3_CS1"   /*!< Identifier */

/* SPI3_SCK (coord P34), SPI3_SCK */
/* Routed pin properties */
#define LPSPI_INITPINS_SPI3_SCK_PERIPHERAL                            ADMA__SPI3   /*!< Peripheral name */
#define LPSPI_INITPINS_SPI3_SCK_SIGNAL                                   spi_sck   /*!< Signal name */
#define LPSPI_INITPINS_SPI3_SCK_PIN_NAME                                SPI3_SCK   /*!< Routed pin name */
#define LPSPI_INITPINS_SPI3_SCK_PIN_FUNCTION_ID                    SC_P_SPI3_SCK   /*!< Pin function id */
#define LPSPI_INITPINS_SPI3_SCK_LABEL                                 "SPI3_SCK"   /*!< Label */
#define LPSPI_INITPINS_SPI3_SCK_NAME                                  "SPI3_SCK"   /*!< Identifier */

/* SPI3_SDI (coord R33), SPI3_SDI */
/* Routed pin properties */
#define LPSPI_INITPINS_SPI3_SDI_PERIPHERAL                            ADMA__SPI3   /*!< Peripheral name */
#define LPSPI_INITPINS_SPI3_SDI_SIGNAL                                   spi_sdi   /*!< Signal name */
#define LPSPI_INITPINS_SPI3_SDI_PIN_NAME                                SPI3_SDI   /*!< Routed pin name */
#define LPSPI_INITPINS_SPI3_SDI_PIN_FUNCTION_ID                    SC_P_SPI3_SDI   /*!< Pin function id */
#define LPSPI_INITPINS_SPI3_SDI_LABEL                                 "SPI3_SDI"   /*!< Label */
#define LPSPI_INITPINS_SPI3_SDI_NAME                                  "SPI3_SDI"   /*!< Identifier */

/* SPI3_SDO (coord R35), SPI3_SDO */
/* Routed pin properties */
#define LPSPI_INITPINS_SPI3_SDO_PERIPHERAL                            ADMA__SPI3   /*!< Peripheral name */
#define LPSPI_INITPINS_SPI3_SDO_SIGNAL                                   spi_sdo   /*!< Signal name */
#define LPSPI_INITPINS_SPI3_SDO_PIN_NAME                                SPI3_SDO   /*!< Routed pin name */
#define LPSPI_INITPINS_SPI3_SDO_PIN_FUNCTION_ID                    SC_P_SPI3_SDO   /*!< Pin function id */
#define LPSPI_INITPINS_SPI3_SDO_LABEL                                 "SPI3_SDO"   /*!< Label */
#define LPSPI_INITPINS_SPI3_SDO_NAME                                  "SPI3_SDO"   /*!< Identifier */

/* SPI3_CS1 (coord U29), SPI3_CS1 */
/* Routed pin properties */
#define LPSPI_DEINITPINS_SPI3_CS1_PERIPHERAL                         ADMA__LCDIF   /*!< Peripheral name */
#define LPSPI_DEINITPINS_SPI3_CS1_SIGNAL                                 lcdif_d   /*!< Signal name */
#define LPSPI_DEINITPINS_SPI3_CS1_CHANNEL                                     16   /*!< Signal channel */
#define LPSPI_DEINITPINS_SPI3_CS1_PIN_NAME                              SPI3_CS1   /*!< Routed pin name */
#define LPSPI_DEINITPINS_SPI3_CS1_PIN_FUNCTION_ID                  SC_P_SPI3_CS1   /*!< Pin function id */
#define LPSPI_DEINITPINS_SPI3_CS1_LABEL                               "SPI3_CS1"   /*!< Label */
#define LPSPI_DEINITPINS_SPI3_CS1_NAME                                "SPI3_CS1"   /*!< Identifier */

/* SPI3_SCK (coord P34), SPI3_SCK */
/* Routed pin properties */
#define LPSPI_DEINITPINS_SPI3_SCK_PERIPHERAL                         LSIO__GPIO0   /*!< Peripheral name */
#define LPSPI_DEINITPINS_SPI3_SCK_SIGNAL                                 gpio_io   /*!< Signal name */
#define LPSPI_DEINITPINS_SPI3_SCK_CHANNEL                                     13   /*!< Signal channel */
#define LPSPI_DEINITPINS_SPI3_SCK_PIN_NAME                              SPI3_SCK   /*!< Routed pin name */
#define LPSPI_DEINITPINS_SPI3_SCK_PIN_FUNCTION_ID                  SC_P_SPI3_SCK   /*!< Pin function id */
#define LPSPI_DEINITPINS_SPI3_SCK_LABEL                               "SPI3_SCK"   /*!< Label */
#define LPSPI_DEINITPINS_SPI3_SCK_NAME                                "SPI3_SCK"   /*!< Identifier */

/* Symbols to be used with GPIO driver */
#define LPSPI_DEINITPINS_SPI3_SCK_GPIO                               LSIO__GPIO0   /*!< GPIO peripheral base pointer */
#define LPSPI_DEINITPINS_SPI3_SCK_GPIO_PIN                                   13U   /*!< GPIO pin number */
#define LPSPI_DEINITPINS_SPI3_SCK_GPIO_PIN_MASK                      (1U << 13U)   /*!< GPIO pin mask */

/* SPI3_SDI (coord R33), SPI3_SDI */
/* Routed pin properties */
#define LPSPI_DEINITPINS_SPI3_SDI_PERIPHERAL                         LSIO__GPIO0   /*!< Peripheral name */
#define LPSPI_DEINITPINS_SPI3_SDI_SIGNAL                                 gpio_io   /*!< Signal name */
#define LPSPI_DEINITPINS_SPI3_SDI_CHANNEL                                     15   /*!< Signal channel */
#define LPSPI_DEINITPINS_SPI3_SDI_PIN_NAME                              SPI3_SDI   /*!< Routed pin name */
#define LPSPI_DEINITPINS_SPI3_SDI_PIN_FUNCTION_ID                  SC_P_SPI3_SDI   /*!< Pin function id */
#define LPSPI_DEINITPINS_SPI3_SDI_LABEL                               "SPI3_SDI"   /*!< Label */
#define LPSPI_DEINITPINS_SPI3_SDI_NAME                                "SPI3_SDI"   /*!< Identifier */

/* Symbols to be used with GPIO driver */
#define LPSPI_DEINITPINS_SPI3_SDI_GPIO                               LSIO__GPIO0   /*!< GPIO peripheral base pointer */
#define LPSPI_DEINITPINS_SPI3_SDI_GPIO_PIN                                   15U   /*!< GPIO pin number */
#define LPSPI_DEINITPINS_SPI3_SDI_GPIO_PIN_MASK                      (1U << 15U)   /*!< GPIO pin mask */

/* SPI3_SDO (coord R35), SPI3_SDO */
/* Routed pin properties */
#define LPSPI_DEINITPINS_SPI3_SDO_PERIPHERAL                         LSIO__GPIO0   /*!< Peripheral name */
#define LPSPI_DEINITPINS_SPI3_SDO_SIGNAL                                 gpio_io   /*!< Signal name */
#define LPSPI_DEINITPINS_SPI3_SDO_CHANNEL                                     14   /*!< Signal channel */
#define LPSPI_DEINITPINS_SPI3_SDO_PIN_NAME                              SPI3_SDO   /*!< Routed pin name */
#define LPSPI_DEINITPINS_SPI3_SDO_PIN_FUNCTION_ID                  SC_P_SPI3_SDO   /*!< Pin function id */
#define LPSPI_DEINITPINS_SPI3_SDO_LABEL                               "SPI3_SDO"   /*!< Label */
#define LPSPI_DEINITPINS_SPI3_SDO_NAME                                "SPI3_SDO"   /*!< Identifier */

/* Symbols to be used with GPIO driver */
#define LPSPI_DEINITPINS_SPI3_SDO_GPIO                               LSIO__GPIO0   /*!< GPIO peripheral base pointer */
#define LPSPI_DEINITPINS_SPI3_SDO_GPIO_PIN                                   14U   /*!< GPIO pin number */
#define LPSPI_DEINITPINS_SPI3_SDO_GPIO_PIN_MASK                      (1U << 14U)   /*!< GPIO pin mask */

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
void LPSPI_InitPins(sc_ipc_t ipc);                         /*!< Function assigned for the core: Cortex-M4F[m4] */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 * @param ipc scfw ipchandle.
 *
 */
void LPSPI_DeinitPins(sc_ipc_t ipc);                       /*!< Function assigned for the core: Cortex-M4F[m4] */

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
