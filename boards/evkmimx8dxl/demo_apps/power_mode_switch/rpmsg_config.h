/*
 * Copyright (c) 2014, Mentor Graphics Corporation
 * Copyright (c) 2015 Xilinx, Inc.
 * Copyright (c) 2016 Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _RPMSG_CONFIG_H
#define _RPMSG_CONFIG_H

/*!
 * @addtogroup config
 * @{
 * @file
 */

//! @name Configuration options
//@{

//! @def RL_MS_PER_INTERVAL
//!
//! Delay in milliseconds used in non-blocking API functions for polling.
//! The default value is 1.
#define RL_MS_PER_INTERVAL (1)

//! @def RL_BUFFER_PAYLOAD_SIZE
//!
//! Size of the buffer payload, it must be equal to (240, 496, 1008, ...)
//! [2^n - 16].
//! The default value is 496.
#define RL_BUFFER_PAYLOAD_SIZE (496)

//! @def RL_BUFFER_COUNT
//!
//! Number of the buffers, it must be power of two (2, 4, ...).
//! The default value is 2.
#define RL_BUFFER_COUNT (256)

//! @def RL_API_HAS_ZEROCOPY
//!
//! Zero-copy API functions enabled/disabled.
//! The default value is 1 (enabled).
#define RL_API_HAS_ZEROCOPY (1)

//! @def RL_USE_STATIC_API
//!
//! Static API functions (no dynamic allocation) enabled/disabled.
//! The default value is 0 (static API disabled).
#define RL_USE_STATIC_API (0)

//! @def RL_CLEAR_USED_BUFFERS
//!
//! Clearing used buffers before returning back to the pool of free buffers
//! enabled/disabled.
//! The default value is 0 (disabled).
#define RL_CLEAR_USED_BUFFERS (0)

//! @def RL_USE_MCMGR_IPC_ISR_HANDLER
//!
//! When enabled IPC interrupts are managed by the Multicore Manager (IPC
//! interrupts router), when disabled RPMsg-Lite manages IPC interrupts
//! by itself.
//! The default value is 0 (no MCMGR IPC ISR handler used).
#define RL_USE_MCMGR_IPC_ISR_HANDLER (0)

//@}

#endif /* _RPMSG_CONFIG_H */
