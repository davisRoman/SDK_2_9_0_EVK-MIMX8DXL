/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v8.0
processor: MIMX8DL1xxxFZ
package_id: MIMX8DL1AVNFZ
mcu_data: ksdk2_0
processor_version: 0.8.0
board: MIMX8DXL-EVK
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "pin_mux.h"
#include "fsl_common.h"
#include "main/imx8dxl_pads.h"
#include "svc/pad/pad_api.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
LPUART_InitPins:
- options: {callFromInitBoot: 'false', coreID: m4}
- pin_list:
  - {pin_num: AN35, peripheral: ADMA__UART0, signal: uart_tx, pin_signal: UART0_TX, sw_config: sw_config_0}
  - {pin_num: AM34, peripheral: ADMA__UART0, signal: uart_rx, pin_signal: UART0_RX, sw_config: sw_config_0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : LPUART_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void LPUART_InitPins(sc_ipc_t ipc)                         /*!< Function assigned for the core: Cortex-M4F[m4] */
{
  sc_err_t err = SC_ERR_NONE;

  err = sc_pad_set_all(ipc, LPUART_INITPINS_UART0_RX_PIN_FUNCTION_ID, 0U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x0 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_UART0_RX register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
  err = sc_pad_set_all(ipc, LPUART_INITPINS_UART0_TX_PIN_FUNCTION_ID, 0U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x8 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_UART0_TX register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
LPUART_DeinitPins:
- options: {callFromInitBoot: 'false', coreID: m4}
- pin_list:
  - {pin_num: AM34, peripheral: LSIO__GPIO1, signal: 'gpio_io, 21', pin_signal: UART0_RX, sw_config: sw_config_0}
  - {pin_num: AN35, peripheral: LSIO__GPIO1, signal: 'gpio_io, 22', pin_signal: UART0_TX, sw_config: sw_config_0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : LPUART_DeinitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void LPUART_DeinitPins(sc_ipc_t ipc)                       /*!< Function assigned for the core: Cortex-M4F[m4] */
{
  sc_err_t err = SC_ERR_NONE;

  err = sc_pad_set_all(ipc, LPUART_DEINITPINS_UART0_RX_PIN_FUNCTION_ID, 4U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x0 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_UART0_RX register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
  err = sc_pad_set_all(ipc, LPUART_DEINITPINS_UART0_TX_PIN_FUNCTION_ID, 4U, SC_PAD_CONFIG_NORMAL, SC_PAD_ISO_OFF, 0x8 ,SC_PAD_WAKEUP_OFF);/* IOMUXD_UART0_TX register modification value */
  if (SC_ERR_NONE != err)
  {
      assert(false);
  }
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
