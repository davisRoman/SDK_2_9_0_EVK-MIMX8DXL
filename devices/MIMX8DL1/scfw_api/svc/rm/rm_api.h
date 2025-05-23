/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2017-2020 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * Header file containing the public API for the System Controller (SC)
 * Resource Management (RM) function. This includes functions for
 * partitioning resources, pads, and memory regions.
 *
 * @addtogroup RM_SVC RM: Resource Management Service
 *
 * @brief Module for the Resource Management (RM) service.
 *
 * @includedoc rm/details.dox
 *
 * @{
 */

#ifndef SC_RM_API_H
#define SC_RM_API_H

/* Includes */

#include "main/types.h"

/* Defines */

/*!
 * @name Defines for type widths
 */
/** @{ */
#define SC_RM_PARTITION_W 5U /*!< Width of sc_rm_pt_t */
#define SC_RM_MEMREG_W    6U /*!< Width of sc_rm_mr_t */
#define SC_RM_DID_W       4U /*!< Width of sc_rm_did_t */
#define SC_RM_SID_W       6U /*!< Width of sc_rm_sid_t */
#define SC_RM_SPA_W       2U /*!< Width of sc_rm_spa_t */
#define SC_RM_PERM_W      3U /*!< Width of sc_rm_perm_t */
#define SC_RM_DET_W       1U /*!< Width of sc_rm_det_t */
#define SC_RM_RMSG_W      4U /*!< Width of sc_rm_rmsg_t */
/** @} */

/*!
 * @name Defines for ALL parameters
 */
/** @{ */
#define SC_RM_PT_ALL ((sc_rm_pt_t)UINT8_MAX) /*!< All partitions */
#define SC_RM_MR_ALL ((sc_rm_mr_t)UINT8_MAX) /*!< All memory regions */
/** @} */

/*!
 * @name Defines for sc_rm_spa_t
 */
/** @{ */
#define SC_RM_SPA_PASSTHRU 0U /*!< Pass through (attribute driven by master) */
#define SC_RM_SPA_PASSSID  1U /*!< Pass through and output on SID */
#define SC_RM_SPA_ASSERT   2U /*!< Assert (force to be secure/privileged) */
#define SC_RM_SPA_NEGATE   3U /*!< Negate (force to be non-secure/user) */
/** @} */

/*!
 * @name Defines for sc_rm_perm_t
 */
/** @{ */
#define SC_RM_PERM_NONE       0U /*!< No access */
#define SC_RM_PERM_SEC_R      1U /*!< Secure RO */
#define SC_RM_PERM_SECPRIV_RW 2U /*!< Secure privilege R/W */
#define SC_RM_PERM_SEC_RW     3U /*!< Secure R/W */
#define SC_RM_PERM_NSPRIV_R   4U /*!< Secure R/W, non-secure privilege RO */
#define SC_RM_PERM_NS_R       5U /*!< Secure R/W, non-secure RO */
#define SC_RM_PERM_NSPRIV_RW  6U /*!< Secure R/W, non-secure privilege R/W */
#define SC_RM_PERM_FULL       7U /*!< Full access */
/** @} */

/* Types */

/*!
 * This type is used to declare a resource partition.
 */
typedef uint8_t sc_rm_pt_t;

/*!
 * This type is used to declare a memory region.
 */
typedef uint8_t sc_rm_mr_t;

/*!
 * This type is used to declare a resource domain ID used by the
 * isolation HW.
 */
typedef uint8_t sc_rm_did_t;

/*!
 * This type is used to declare an SMMU StreamID.
 */
typedef uint16_t sc_rm_sid_t;

/*!
 * This type is a used to declare master transaction attributes.
 */
typedef uint8_t sc_rm_spa_t;

/*!
 * This type is used to declare a resource/memory region access permission.
 * Refer to the XRDC2 Block Guide for more information.
 */
typedef uint8_t sc_rm_perm_t;

/*!
 * This type is used to indicate memory region transactions should detour
 * to the IEE.
 */
typedef uint8_t sc_rm_det_t;

/*!
 * This type is used to assign an RMSG value to a memory region. This value
 * is sent to the IEE.
 */
typedef uint8_t sc_rm_rmsg_t;

/* Functions */

/*!
 * @name Partition Functions
 * @{
 */

/*!
 * This function requests that the SC create a new resource partition.
 *
 * @param[in]     ipc          IPC handle
 * @param[out]    pt           return handle for partition;
                               used for subsequent function
 *                             calls associated with this partition
 * @param[in]     secure       boolean indicating if this partition should be secure;
                               only valid if caller is secure
 * @param[in]     isolated     boolean indicating if this partition should be HW isolated
 *                             via XRDC; set SC_TRUE if new DID is desired
 * @param[in]     restricted   boolean indicating if this partition should be restricted;
 *                             set SC_TRUE if masters in this partition cannot create new partitions
 * @param[in]     grant        boolean indicating if this partition should always grant
 *                             access and control to the parent
 * @param[in]     coherent     boolean indicating if this partition is coherent;
 *                             set SC_TRUE if only this partition will contain both AP clusters
 *                             and they will be coherent via the CCI
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_ERR_PARM if caller's partition is not secure but a new secure partition is requested,
 * - SC_ERR_LOCKED if caller's partition is locked,
 * - SC_ERR_UNAVAILABLE if partition table is full (no more allocation space)
 *
 * Marking as non-secure prevents subsequent functions from configuring masters in this
 * partition to assert the secure signal. Basically, if TrustZone SW is used, the Cortex-A
 * cores and peripherals the TZ SW will use should be in a secure partition. Almost all
 * other partitions (for a non-secure OS or MCU cores) should be in non-secure partitions.
 *
 * Isolated should be true for almost all partitions. The exception is the non-secure
 * partition for a Cortex-A core used to run a non-secure OS. This isn't isolated by
 * domain but is instead isolated by the TZ security hardware.
 *
 * If restricted then the new partition is limited in what functions it can call,
 * especially those associated with managing partitions.
 *
 * The grant option is usually used to isolate a bus master's traffic to specific
 * memory without isolating the peripheral interface of the master or the API
 * controls of that master. This is only used when creating a sub-partition with
 * no CPU. It's useful to separate out a master and the memory it uses.
 */
sc_err_t sc_rm_partition_alloc(sc_ipc_t ipc,
                               sc_rm_pt_t *pt,
                               sc_bool_t secure,
                               sc_bool_t isolated,
                               sc_bool_t restricted,
                               sc_bool_t grant,
                               sc_bool_t coherent);

/*!
 * This function makes a partition confidential.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition that is granting
 * @param[in]     retro       retroactive
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if \a pt out of range,
 * - SC_ERR_NOACCESS if caller's not allowed to change \a pt
 * - SC_ERR_LOCKED if partition \a pt is locked
 *
 * Call to make a partition confidential. Confidential means only this
 * partition should be able to grant access permissions to this partition.
 *
 * If retroactive, then all resources owned by other partitions will have
 * access rights for this partition removed, even if locked.
 */
sc_err_t sc_rm_set_confidential(sc_ipc_t ipc, sc_rm_pt_t pt, sc_bool_t retro);

/*!
 * This function frees a partition and assigns all resources to the caller.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition to free
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_PARM if \a pt out of range or invalid,
 * - SC_ERR_NOACCESS if \a pt is the SC partition,
 * - SC_ERR_NOACCESS if caller's partition is not the parent of \a pt,
 * - SC_ERR_LOCKED if \a pt or caller's partition is locked
 *
 * All resources, memory regions, and pads are assigned to the caller/parent.
 * The partition watchdog is disabled (even if locked). DID is freed.
 */
sc_err_t sc_rm_partition_free(sc_ipc_t ipc, sc_rm_pt_t pt);

/*!
 * This function returns the DID of a partition.
 *
 * @param[in]     ipc         IPC handle
 *
 * @return Returns the domain ID (DID) of the caller's partition.
 *
 * The DID is a SoC-specific internal ID used by the HW resource
 * protection mechanism. It is only required by clients when using the
 * SEMA42 module as the DID is sometimes connected to the master ID.
 */
sc_rm_did_t sc_rm_get_did(sc_ipc_t ipc);

/*!
 * This function forces a partition to use a specific static DID.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition to assign \a did
 * @param[in]     did         static DID to assign
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_PARM if \a pt or \a did out of range,
 * - SC_ERR_NOACCESS if caller's partition is not the parent of \a pt,
 * - SC_ERR_LOCKED if \a pt is locked
 *
 * Assumes no assigned resources or memory regions yet! The number of static
 * DID is fixed by the SC at boot.
 */
sc_err_t sc_rm_partition_static(sc_ipc_t ipc, sc_rm_pt_t pt, sc_rm_did_t did);

/*!
 * This function locks a partition.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition to lock
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if \a pt out of range,
 * - SC_ERR_NOACCESS if caller's partition is not the parent of \a pt
 *
 * If a partition is locked it cannot be freed, have resources/pads assigned
 * to/from it, memory regions created/assigned, DID changed, or parent changed.
 */
sc_err_t sc_rm_partition_lock(sc_ipc_t ipc, sc_rm_pt_t pt);

/*!
 * This function gets the partition handle of the caller.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    pt          return handle for caller's partition
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 */
sc_err_t sc_rm_get_partition(sc_ipc_t ipc, sc_rm_pt_t *pt);

/*!
 * This function sets a new parent for a partition.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition for which parent is to be changed
 * @param[in]     pt_parent   handle of partition to set as parent
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the parent of \a pt,
 * - SC_ERR_LOCKED if either partition is locked
 */
sc_err_t sc_rm_set_parent(sc_ipc_t ipc, sc_rm_pt_t pt, sc_rm_pt_t pt_parent);

/*!
 * This function moves all movable resources/pads owned by a source partition
 * to a destination partition. It can be used to more quickly set up a new
 * partition if a majority of the caller's resources are to be moved to a
 * new partition.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt_src      handle of partition from which resources should be moved from
 * @param[in]     pt_dst      handle of partition to which resources should be moved to
 * @param[in]     move_rsrc   boolean to indicate if resources should be moved
 * @param[in]     move_pads   boolean to indicate if pads should be moved
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * By default, all resources are movable. This can be changed using the
 * sc_rm_set_resource_movable() function. Note all masters defaulted to SMMU
 * bypass.
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not \a pt_src or the
 *   parent of \a pt_src,
 * - SC_ERR_LOCKED if either partition is locked
 */
sc_err_t sc_rm_move_all(sc_ipc_t ipc, sc_rm_pt_t pt_src, sc_rm_pt_t pt_dst, sc_bool_t move_rsrc, sc_bool_t move_pads);

/** @} */

/*!
 * @name Resource Functions
 * @{
 */

/*!
 * This function assigns ownership of a resource to a partition.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition to which resource should be assigned
 * @param[in]     resource    resource to assign
 *
 * This function assigned a resource to a partition. This partition is then
 * the owner. All resources always have an owner (one owner). The owner
 * has various rights to make API calls affecting the resource. Ownership
 * does not imply access to the peripheral itself (that is based on access
 * rights).
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * This action resets the resource's master and peripheral attributes.
 * Privilege attribute will be PASSTHRU, security attribute will be
 * ASSERT if the partition is secure and NEGATE if it is not, and
 * masters will defaulted to SMMU bypass. Access permissions will reset
 * to SEC_RW for the owning partition only for secure partitions, FULL for
 * non-secure. Default is no access by other partitions.
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the resource owner or parent
 *   of the owner,
 * - SC_ERR_LOCKED if the owning partition or \a pt is locked
 */
sc_err_t sc_rm_assign_resource(sc_ipc_t ipc, sc_rm_pt_t pt, sc_rsrc_t resource);

/*!
 * This function flags resources as movable or not.
 *
 * @param[in]     ipc           IPC handle
 * @param[in]     resource_fst  first resource for which flag should be set
 * @param[in]     resource_lst  last resource for which flag should be set
 * @param[in]     movable       movable flag (SC_TRUE is movable)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if resources are out of range,
 * - SC_ERR_NOACCESS if caller's partition is not a parent of a resource owner,
 * - SC_ERR_LOCKED if the owning partition is locked
 *
 * This function is used to determine the set of resources that will be
 * moved using the sc_rm_move_all() function. All resources are movable
 * by default so this function is normally used to prevent a set of
 * resources from moving.
 */
sc_err_t sc_rm_set_resource_movable(sc_ipc_t ipc, sc_rsrc_t resource_fst, sc_rsrc_t resource_lst, sc_bool_t movable);

/*!
 * This function flags all of a subsystem's resources as movable
 * or not.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource to use to identify subsystem
 * @param[in]     movable     movable flag (SC_TRUE is movable)
 *
 * A subsystem is a physical grouping within the chip of related resources;
 * this is SoC specific. This function is used to optimize moving resource
 * for these groupings, for instance, an MCU core and its associated resources.
 * The list of subsystems and associated resources can be found in the
 * SoC-specific API document [Resources](@ref RESOURCES) chapter.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if a function argument is out of range
 *
 * Note \a resource is used to find the associated subsystem. Only
 * resources owned by the caller are set.
 */
sc_err_t sc_rm_set_subsys_rsrc_movable(sc_ipc_t ipc, sc_rsrc_t resource, sc_bool_t movable);

/*!
 * This function sets attributes for a resource which is a bus master (i.e.
 * capable of DMA).
 *
 * @param[in]     ipc          IPC handle
 * @param[in]     resource     master resource for which attributes should apply
 * @param[in]     sa           security attribute
 * @param[in]     pa           privilege attribute
 * @param[in]     smmu_bypass  SMMU bypass mode
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not a parent of the resource owner,
 * - SC_ERR_LOCKED if the owning partition is locked
 *
 * Masters are IP blocks that generate bus transactions. This function configures
 * how the isolation HW will define these bus transactions from the specified master.
 * Note the security attribute will only be changed if the caller's partition is
 * secure.
 *
 * Note an IP block can be both a master and peripheral (have both a programming model
 * and generate bus transactions).
 */
sc_err_t sc_rm_set_master_attributes(
    sc_ipc_t ipc, sc_rsrc_t resource, sc_rm_spa_t sa, sc_rm_spa_t pa, sc_bool_t smmu_bypass);

/*!
 * This function sets the StreamID for a resource which is a bus master (i.e.
 * capable of DMA).
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    master resource for which attributes should apply
 * @param[in]     sid         StreamID
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the resource owner or parent
 *   of the owner,
 * - SC_ERR_LOCKED if the owning partition is locked
 *
 * This function configures the SID attribute associated with all bus transactions
 * from this master. Note 0 is not a valid SID as it is reserved to indicate
 * bypass.
 */
sc_err_t sc_rm_set_master_sid(sc_ipc_t ipc, sc_rsrc_t resource, sc_rm_sid_t sid);

/*!
 * This function sets access permissions for a peripheral resource.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    peripheral resource for which permissions should apply
 * @param[in]     pt          handle of partition \a perm should by applied for
 * @param[in]     perm        permissions to apply to \a resource for \a pt
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the resource owner or parent
 *   of the owner,
 * - SC_ERR_LOCKED if the owning partition is locked
 * - SC_ERR_LOCKED if the \a pt is confidential and the caller isn't \a pt
 *
 * Peripherals are IP blocks that have a programming model that can be
 * accessed.
 *
 * This function configures how the isolation HW will restrict access to a
 * peripheral based on the attributes of a transaction from bus master. It
 * also allows the access permissions of SC_R_SYSTEM to be set.
 *
 * Note an IP block can be both a master and peripheral (have both a programming
 * model and generate bus transactions).
 */
sc_err_t sc_rm_set_peripheral_permissions(sc_ipc_t ipc, sc_rsrc_t resource, sc_rm_pt_t pt, sc_rm_perm_t perm);

/*!
 * This function gets ownership status of a resource.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource to check
 *
 * @return Returns a boolean (SC_TRUE if caller's partition owns the resource).
 *
 * If \a resource is out of range then SC_FALSE is returned.
 */
sc_bool_t sc_rm_is_resource_owned(sc_ipc_t ipc, sc_rsrc_t resource);

/*!
 * This function is used to get the owner of a resource.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource to check
 * @param[out]    pt          pointer to return owning partition
 *
 * @return Returns a boolean (SC_TRUE if the resource is a bus master).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid
 *
 * If \a resource is out of range then SC_ERR_PARM is returned.
 */
sc_err_t sc_rm_get_resource_owner(sc_ipc_t ipc, sc_rsrc_t resource, sc_rm_pt_t *pt);

/*!
 * This function is used to test if a resource is a bus master.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource to check
 *
 * Masters are IP blocks that generate bus transactions. Note an IP block
 * can be both a master and peripheral (have both a programming model
 * and generate bus transactions).
 *
 * @return Returns a boolean (SC_TRUE if the resource is a bus master).
 *
 * If \a resource is out of range then SC_FALSE is returned.
 */
sc_bool_t sc_rm_is_resource_master(sc_ipc_t ipc, sc_rsrc_t resource);

/*!
 * This function is used to test if a resource is a peripheral.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource to check
 *
 * Peripherals are IP blocks that have a programming model that can be
 * accessed. Note an IP block can be both a master and peripheral (have
 * both a programming model and generate bus transactions)
 *
 * @return Returns a boolean (SC_TRUE if the resource is a peripheral).
 *
 * If \a resource is out of range then SC_FALSE is returned.
 */
sc_bool_t sc_rm_is_resource_peripheral(sc_ipc_t ipc, sc_rsrc_t resource);

/*!
 * This function is used to obtain info about a resource.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     resource    resource to inquire about
 * @param[out]    sid         pointer to return StreamID
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if \a resource is out of range
 */
sc_err_t sc_rm_get_resource_info(sc_ipc_t ipc, sc_rsrc_t resource, sc_rm_sid_t *sid);

/** @} */

/*!
 * @name Memory Region Functions
 * @{
 */

/*!
 * This function requests that the SC create a new memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    mr          return handle for region;
                              used for subsequent function calls
 *                            associated with this region
 * @param[in]     addr_start  start address of region (physical)
 * @param[in]     addr_end    end address of region (physical)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if the new memory region is misaligned,
 * - SC_ERR_LOCKED if caller's partition is locked,
 * - SC_ERR_PARM if the new memory region spans multiple existing regions,
 * - SC_ERR_NOACCESS if caller's partition does not own the memory containing
 *   the new region,
 * - SC_ERR_UNAVAILABLE if memory region table is full (no more allocation
 *   space)
 *
 * This function will create a new memory region. The area covered by the
 * new region must already exist in a memory region owned by the caller. The
 * result will be two memory regions, the new one overlapping the existing
 * one. The new region has higher priority. See the XRDC2 MRC documentation
 * for how it resolves access permissions in this case. By default,
 * permissions will mirror the parent region.
 */
sc_err_t sc_rm_memreg_alloc(sc_ipc_t ipc, sc_rm_mr_t *mr, sc_faddr_t addr_start, sc_faddr_t addr_end);

/*!
 * This function requests that the SC split an existing memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     mr          handle of memory region to split
 * @param[out]    mr_ret      return handle for new region;
                              used for subsequent function calls
 *                            associated with this region
 * @param[in]     addr_start  start address of region (physical)
 * @param[in]     addr_end    end address of region (physical)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_PARM if the new memory region is not start/end part of mr,
 * - SC_ERR_LOCKED if caller's partition is locked,
 * - SC_ERR_PARM if the new memory region spans multiple existing regions,
 * - SC_ERR_NOACCESS if caller's partition does not own the memory containing
 *   the new region,
 * - SC_ERR_BUSY if the region is coincident with another region,
 * - SC_ERR_UNAVAILABLE if memory region table is full (no more allocation
 *   space)
 *
 * This function will take an existing region and split it into two,
 * non-overlapping regions. Note the new region must start or end on the
 * split region. Permissions will mirror the parent region.
 */
sc_err_t sc_rm_memreg_split(
    sc_ipc_t ipc, sc_rm_mr_t mr, sc_rm_mr_t *mr_ret, sc_faddr_t addr_start, sc_faddr_t addr_end);

/*!
 * This function requests that the SC fragment a memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    mr_ret      return handle for new region;
                              used for subsequent function calls
 *                            associated with this region
 * @param[in]     addr_start  start address of region (physical)
 * @param[in]     addr_end    end address of region (physical)
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_LOCKED if caller's partition is locked,
 * - SC_ERR_PARM if the new memory region spans multiple existing regions,
 * - SC_ERR_NOACCESS if caller's partition does not own the memory containing
 *   the new region,
 * - SC_ERR_BUSY if the region is coincident with another region,
 * - SC_ERR_UNAVAILABLE if memory region table is full (no more allocation
 *   space)
 *
 * This function finds the memory region containing the address range.
 * It then splits it as required and returns the extracted region. The
 * result is 2-3 non-overlapping regions, depending on how the new region
 * aligns with existing regions. Permissions will mirror the parent region.
 */
sc_err_t sc_rm_memreg_frag(sc_ipc_t ipc, sc_rm_mr_t *mr_ret, sc_faddr_t addr_start, sc_faddr_t addr_end);

/*!
 * This function frees a memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     mr          handle of memory region to free
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if \a mr out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not a parent of \a mr,
 * - SC_ERR_LOCKED if the owning partition of \a mr is locked
 */
sc_err_t sc_rm_memreg_free(sc_ipc_t ipc, sc_rm_mr_t mr);

/*!
 * Internal SC function to find a memory region.
 *
 * @see sc_rm_find_memreg().
 */
/*!
 * This function finds a memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[out]    mr          return handle for region;
                              used for subsequent function calls
 *                            associated with this region
 * @param[in]     addr_start  start address of region to search for
 * @param[in]     addr_end    end address of region to search for
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NOTFOUND if region not found,
 *
 * Searches only for regions owned by the caller. Finds first
 * region containing the range specified.
 */
sc_err_t sc_rm_find_memreg(sc_ipc_t ipc, sc_rm_mr_t *mr, sc_faddr_t addr_start, sc_faddr_t addr_end);

/*!
 * This function assigns ownership of a memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition
                              to which memory region should be assigned
 * @param[in]     mr          handle of memory region to assign
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * This function assigns a memory region to a partition. This partition is then
 * the owner. All regions always have an owner (one owner). The owner
 * has various rights to make API calls affecting the region. Ownership
 * does not imply access to the memory itself (that is based on access
 * rights).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the \a mr owner or parent
 *   of the owner,
 * - SC_ERR_LOCKED if the owning partition or \a pt is locked
 */
sc_err_t sc_rm_assign_memreg(sc_ipc_t ipc, sc_rm_pt_t pt, sc_rm_mr_t mr);

/*!
 * This function sets access permissions for a memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     mr          handle of memory region
                              for which permissions should apply
 * @param[in]     pt          handle of partition \a perm should by
 *                            applied for
 * @param[in]     perm        permissions to apply to \a mr for \a pt
 *
 * This operates on the memory region specified. If SC_RM_PT_ALL is specified
 * then it operates on all the regions owned by the caller that exist at the
 * time of the call.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the region owner or parent
 *   of the owner,
 * - SC_ERR_LOCKED if the owning partition is locked
 * - SC_ERR_LOCKED if the \a pt is confidential and the caller isn't \a pt
 *
 * This function configures how the HW isolation will restrict access to a
 * memory region based on the attributes of a transaction from bus master.
 */
sc_err_t sc_rm_set_memreg_permissions(sc_ipc_t ipc, sc_rm_mr_t mr, sc_rm_pt_t pt, sc_rm_perm_t perm);

/*!
 * This function configures the IEE parameters for a memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     mr          handle of memory region to check
 * @param[in]     det         0 = normal, 1 = encrypted
 * @param[in]     rmsg        IEE region (0-7)
 *
 * Caller must own SC_R_IEE_Rn where n is rmsg.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_LOCKED if the owning partition is locked
 * - SC_ERR_NOACCESS if caller's partition is not the region owner or parent
 *   of the owner
 * - SC_ERR_UNAVAILABLE if caller's partition is not the IEE region resource
 *   owner
 */
sc_err_t sc_rm_set_memreg_iee(sc_ipc_t ipc, sc_rm_mr_t mr, sc_rm_det_t det, sc_rm_rmsg_t rmsg);

/*!
 * This function gets ownership status of a memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     mr          handle of memory region to check
 *
 * @return Returns a boolean (SC_TRUE if caller's partition owns the
 * memory region).
 *
 * If \a mr is out of range then SC_FALSE is returned.
 */
sc_bool_t sc_rm_is_memreg_owned(sc_ipc_t ipc, sc_rm_mr_t mr);

/*!
 * This function is used to obtain info about a memory region.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     mr          handle of memory region to inquire about
 * @param[out]    addr_start  pointer to return start address
 * @param[out]    addr_end    pointer to return end address
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if \a mr is out of range
 */
sc_err_t sc_rm_get_memreg_info(sc_ipc_t ipc, sc_rm_mr_t mr, sc_faddr_t *addr_start, sc_faddr_t *addr_end);

/** @} */

/*!
 * @name Pad Functions
 * @{
 */

/*!
 * This function assigns ownership of a pad to a partition.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pt          handle of partition
                              to which pad should be assigned
 * @param[in]     pad         pad to assign
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_ERR_NOACCESS if caller's partition is restricted,
 * - SC_PARM if arguments out of range or invalid,
 * - SC_ERR_NOACCESS if caller's partition is not the pad owner or parent
 *   of the owner,
 * - SC_ERR_LOCKED if the owning partition or \a pt is locked
 */
sc_err_t sc_rm_assign_pad(sc_ipc_t ipc, sc_rm_pt_t pt, sc_pad_t pad);

/*!
 * This function flags pads as movable or not.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pad_fst     first pad for which flag should be set
 * @param[in]     pad_lst     last pad for which flag should be set
 * @param[in]     movable     movable flag (SC_TRUE is movable)
 *
 * This function assigned a pad to a partition. This partition is then
 * the owner. All pads always have an owner (one owner). The owner
 * has various rights to make API calls affecting the pad.
 *
 * @return Returns an error code (SC_ERR_NONE = success).
 *
 * Return errors:
 * - SC_PARM if pads are out of range,
 * - SC_ERR_NOACCESS if caller's partition is not a parent of a pad owner,
 * - SC_ERR_LOCKED if the owning partition is locked
 *
 * This function is used to determine the set of pads that will be
 * moved using the sc_rm_move_all() function. All pads are movable
 * by default so this function is normally used to prevent a set of
 * pads from moving.
 */
sc_err_t sc_rm_set_pad_movable(sc_ipc_t ipc, sc_pad_t pad_fst, sc_pad_t pad_lst, sc_bool_t movable);

/*!
 * This function gets ownership status of a pad.
 *
 * @param[in]     ipc         IPC handle
 * @param[in]     pad         pad to check
 *
 * @return Returns a boolean (SC_TRUE if caller's partition owns the pad).
 *
 * If \a pad is out of range then SC_FALSE is returned.
 */
sc_bool_t sc_rm_is_pad_owned(sc_ipc_t ipc, sc_pad_t pad);

/** @} */

/*!
 * @name Debug Functions
 * @{
 */

/*!
 * This function dumps the RM state for debug.
 *
 * @param[in]     ipc         IPC handle
 */
void sc_rm_dump(sc_ipc_t ipc);

/** @} */

#endif /* SC_RM_API_H */

/** @} */
