/*
** ###################################################################
**     Processor:           MIMX8DL1AVNFZ
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX8DXLRM, Rev. C, 07/2020
**     Version:             rev. 4.0, 2020-10-30
**     Build:               b201109
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2020 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-11-13)
**         Initial version.
**     - rev. 2.0 (2020-03-17)
**         Header EAR
**     - rev. 3.0 (2020-07-16)
**         Header PRC
**     - rev. 4.0 (2020-10-30)
**         Header RFP
**
** ###################################################################
*/

/*!
 * @file MIMX8DL1_cm4
 * @version 1.0
 * @date 091120
 * @brief Device specific configuration file for MIMX8DL1_cm4 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */
#ifndef _SYSTEM_MIMX8DL1_CM4_H_
#define _SYSTEM_MIMX8DL1_CM4_H_                    /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "main/rpc.h"
#include "svc/pm/pm_api.h"

#ifndef DISABLE_WDOG
#define DISABLE_WDOG 1
#endif

#define DEFAULT_SYSTEM_CLOCK 264000000u /* Default System clock value */

/**
 * @brief System clock frequency (core clock)
 *
 * The system clock frequency supplied to the SysTick timer and the processor
 * core clock. This variable can be used by the user application to setup the
 * SysTick timer or configure other parameters. It may also be used by debugger to
 * query the frequency of the debug timer or configure the trace clock speed
 * SystemCoreClock is initialized with a correct predefined value.
 */
extern uint32_t SystemCoreClock;

/**
 * @brief Setup the microcontroller system.
 *
 * Typically this function configures the oscillator (PLL) that is part of the
 * microcontroller device. For systems with variable clock speed it also updates
 * the variable SystemCoreClock. SystemInit is called from startup_device file.
 */
void SystemInit(void);

/**
 * @brief Updates the SystemCoreClock variable.
 *
 * It must be called whenever the core clock is changed during program
 * execution. SystemCoreClockUpdate() evaluates the clock register settings and calculates
 * the current core clock.
 */
void SystemCoreClockUpdate(void);

/**
 * @brief Open the SCFW IPC channel.
 *
 * Typically this function opens the IPC channel between current Subsystem and SCU.
 * This function uses SCFW API to initialize the MU channel.  SystemInitScfwIpc should
 * be called before using SCFW API.
 */
void SystemInitScfwIpc(void);

/**
 * @brief Get the SCFW IPC handle.
 *
 * This function gets the IPC handle which could be used to communicate with SCFW.
 * SystemGetScfwIpcHandle should be called after SCFW IPC channel is initialized.
 */
sc_ipc_t SystemGetScfwIpcHandle(void);

#ifdef __cplusplus
}
#endif

#endif  /* _SYSTEM_MIMX8DL1_CM4_H_ */
