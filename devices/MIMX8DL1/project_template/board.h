/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "clock_config.h"

/* SCFW includes */
#include "main/rpc.h"
#include "svc/pm/pm_api.h"

#include "main/imx8dxl_pads.h"
#include "svc/pad/pad_api.h"

#if defined(SDK_I2C_BASED_COMPONENT_USED) && SDK_I2C_BASED_COMPONENT_USED
#include "fsl_lpi2c.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The board name */
#define BOARD_NAME "EVKMIMX8DXL"

/* The UART to use for debug messages. */
#define BOARD_DEBUG_UART_TYPE        kSerialPort_Uart
#define BOARD_DEBUG_UART_BAUDRATE    115200u
#define BOARD_DEBUG_UART_BASEADDR    (uint32_t) CM4__LPUART
#define BOARD_DEBUG_UART_INSTANCE    4U
#define BOARD_DEBUG_UART_SC_RSRC     SC_R_M4_0_UART
#define BOARD_DEBUG_UART_CLK_FREQ    6000000u
#define BOARD_UART_IRQ               M4_LPUART_IRQn
#define BOARD_UART_IRQ_HANDLER       LPUART0_IRQHandler
#define BOARD_DEBUG_UART_CLKSRC      kCLOCK_M4_0_Lpuart
#define BOARD_M4_CPU_RSRC            SC_R_M4_0_PID0
#define BOARD_BASEBOARD_PWR_GPIO     LSIO_GPIO5
#define BOARD_BASEBOARD_PWR_GPIO_PIN 9U

#define BOARD_ENET1_PHY_ADDRESS (0x00)

#define BOARD_CODEC_I2C_BASEADDR   ADMA__LPI2C2
#define BOARD_CODEC_I2C_CLOCK_FREQ (24000000U)
#define BOARD_CODEC_I2C_INSTANCE   (2U)

/*
 * Handling of IRQ from SCFW
 */
#define IPC_MU                       CM4__MU1_A
#define IPC_MU_IRQn                  M4_MU1_A_IRQn
#define IPC_MU_RSRC                  SC_R_M4_0_MU_1A
#define SC_RPC_MU_INTERRUPT_PRIORITY (configLIBRARY_LOWEST_INTERRUPT_PRIORITY - 1U)
#define BOARD_MU_IRQHandler          M4_MU1_A_IRQHandler

#define VDEV0_VRING_BASE      (0x90000000U)
#define VDEV1_VRING_BASE      (0x90010000U)
#define RESOURCE_TABLE_OFFSET (0xFF000)

#ifdef BOARD_USE_SCFW_IRQ
/*
 * MU IRQ Enable Mask
 */
#define SC_EVENT_MASK(event) (1 << event)
#endif

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * Typedef
 ******************************************************************************/
#ifdef BOARD_USE_SCFW_IRQ
typedef enum _sc_event_type
{
    kSCEvent_PeerCoreReboot,
    kSCEvent_Button,
    kSCEvent_Pad,
    kSCEvent_SysCtr,
    kSCEvent_Last,
} sc_event_type_t;
#endif

/*******************************************************************************
 * Function prototype
 ******************************************************************************/
#ifdef BOARD_USE_SCFW_IRQ
typedef void (*eventHandler)(void *param);
#endif

/*******************************************************************************
 * API
 ******************************************************************************/
sc_ipc_t BOARD_InitRpc(void);
sc_ipc_t BOARD_GetRpcHandle(void);
void BOARD_InitDebugConsole(void);
void BOARD_InitPinsPre(void);
void BOARD_PowerOnBaseBoard(void);
void BOARD_InitMemory(void);

#if defined(SDK_I2C_BASED_COMPONENT_USED) && SDK_I2C_BASED_COMPONENT_USED
void BOARD_LPI2C_Init(LPI2C_Type *base, uint32_t clkSrc_Hz);
status_t BOARD_LPI2C_Send(LPI2C_Type *base,
                          const uint8_t dev_addr,
                          uint32_t subAddress,
                          uint32_t subAddressSize,
                          uint8_t *txBuff,
                          uint32_t txSize);
status_t BOARD_LPI2C_Receive(LPI2C_Type *base,
                             uint8_t deviceAddress,
                             uint32_t subAddress,
                             uint8_t subaddressSize,
                             uint8_t *rxBuff,
                             uint8_t rxBuffSize);
#endif /* SDK_I2C_BASED_COMPONENT_USED */

#ifdef BOARD_USE_SCFW_IRQ
void BOARD_Enable_SCIRQ(bool enable);
void BOARD_EnableSCEvent(uint32_t mask, bool enable);
void BOARD_RegisterEventHandler(sc_event_type_t event, eventHandler handler, void *param);
void BOARD_EnablePadWakeup(sc_pad_t pad, bool enable, sc_pad_wakeup_t pad_wakeup_config);
static inline void BOARD_UnregisterEventHandeler(sc_event_type_t event)
{
    BOARD_RegisterEventHandler(event, NULL, NULL);
}
#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
