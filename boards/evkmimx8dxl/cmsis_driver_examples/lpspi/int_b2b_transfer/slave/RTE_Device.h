/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _RTE_DEVICE_H
#define _RTE_DEVICE_H

extern void LPSPI3_InitPins();
extern void LPSPI3_DeinitPins();

/* SPI instance name mapping */
#define LPSPI0 ADMA__LPSPI0
#define LPSPI1 ADMA__LPSPI1
#define LPSPI2 ADMA__LPSPI2
#define LPSPI3 ADMA__LPSPI3

/* Driver name mapping. */
/* User needs to provide the implementation of LPSPIX_GetFreq/LPSPIX_InitPins/LPSPIX_DeinitPins for the enabled LPSPI
 * instance. */
#define RTE_SPI3        1
#define RTE_SPI3_DMA_EN 0

/* SPI configuration. */
#define RTE_SPI3_PCS_TO_SCK_DELAY       1000
#define RTE_SPI3_SCK_TO_PSC_DELAY       1000
#define RTE_SPI3_BETWEEN_TRANSFER_DELAY 1000
#define RTE_SPI3_SLAVE_PCS_PIN_SEL      kLPSPI_SlavePcs1
#define RTE_SPI3_PIN_INIT               LPSPI3_InitPins
#define RTE_SPI3_PIN_DEINIT             LPSPI3_DeinitPins
#define RTE_SPI3_DMA_TX_CH              7
#define RTE_SPI3_DMA_TX_PERI_SEL        7
#define RTE_SPI3_DMA_TX_DMA_BASE        ADMA__EDMA2
#define RTE_SPI3_DMA_RX_CH              6
#define RTE_SPI3_DMA_RX_PERI_SEL        6
#define RTE_SPI3_DMA_RX_DMA_BASE        ADMA__EDMA2

#endif /* _RTE_DEVICE_H */
