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
 * Header file used to configure SoC pad list.
 */

#ifndef SC_PADS_H
#define SC_PADS_H

/* Includes */

/* Defines */

/*!
 * @name Pad Definitions
 */
/** @{ */
#define SC_P_PCIE_CTRL0_PERST_B                  0    /*!< HSIO.PCIE0.PERST_B, LSIO.GPIO4.IO00, LSIO.GPIO7.IO00 */
#define SC_P_PCIE_CTRL0_CLKREQ_B                 1    /*!< HSIO.PCIE0.CLKREQ_B, LSIO.GPIO4.IO01, LSIO.GPIO7.IO01 */
#define SC_P_PCIE_CTRL0_WAKE_B                   2    /*!< HSIO.PCIE0.WAKE_B, LSIO.GPIO4.IO02, LSIO.GPIO7.IO02 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_PCIESEP       3    /*!<  */
#define SC_P_USB_SS3_TC0                         4    /*!< ADMA.I2C1.SCL, CONN.USB_OTG1.PWR, CONN.USB_OTG2.PWR, LSIO.GPIO4.IO03, LSIO.GPIO7.IO03 */
#define SC_P_USB_SS3_TC1                         5    /*!< ADMA.I2C1.SCL, CONN.USB_OTG2.PWR, LSIO.GPIO4.IO04, LSIO.GPIO7.IO04 */
#define SC_P_USB_SS3_TC2                         6    /*!< ADMA.I2C1.SDA, CONN.USB_OTG1.OC, CONN.USB_OTG2.OC, LSIO.GPIO4.IO05, LSIO.GPIO7.IO05 */
#define SC_P_USB_SS3_TC3                         7    /*!< ADMA.I2C1.SDA, CONN.USB_OTG2.OC, LSIO.GPIO4.IO06, LSIO.GPIO7.IO06 */
#define SC_P_COMP_CTL_GPIO_3V3_USB3IO            8    /*!<  */
#define SC_P_EMMC0_CLK                           9    /*!< CONN.EMMC0.CLK, CONN.NAND.READY_B, LSIO.GPIO4.IO07 */
#define SC_P_EMMC0_CMD                           10   /*!< CONN.EMMC0.CMD, CONN.NAND.DQS, LSIO.GPIO4.IO08 */
#define SC_P_EMMC0_DATA0                         11   /*!< CONN.EMMC0.DATA0, CONN.NAND.DATA00, LSIO.GPIO4.IO09 */
#define SC_P_EMMC0_DATA1                         12   /*!< CONN.EMMC0.DATA1, CONN.NAND.DATA01, LSIO.GPIO4.IO10 */
#define SC_P_EMMC0_DATA2                         13   /*!< CONN.EMMC0.DATA2, CONN.NAND.DATA02, LSIO.GPIO4.IO11 */
#define SC_P_EMMC0_DATA3                         14   /*!< CONN.EMMC0.DATA3, CONN.NAND.DATA03, LSIO.GPIO4.IO12 */
#define SC_P_EMMC0_DATA4                         15   /*!< CONN.EMMC0.DATA4, CONN.NAND.DATA04, LSIO.GPIO4.IO13 */
#define SC_P_EMMC0_DATA5                         16   /*!< CONN.EMMC0.DATA5, CONN.NAND.DATA05, LSIO.GPIO4.IO14 */
#define SC_P_EMMC0_DATA6                         17   /*!< CONN.EMMC0.DATA6, CONN.NAND.DATA06, LSIO.GPIO4.IO15 */
#define SC_P_EMMC0_DATA7                         18   /*!< CONN.EMMC0.DATA7, CONN.NAND.DATA07, LSIO.GPIO4.IO16 */
#define SC_P_EMMC0_STROBE                        19   /*!< CONN.EMMC0.STROBE, CONN.NAND.CLE, LSIO.GPIO4.IO17 */
#define SC_P_EMMC0_RESET_B                       20   /*!< CONN.EMMC0.RESET_B, CONN.NAND.WP_B, LSIO.GPIO4.IO18 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_SD1FIX0       21   /*!<  */
#define SC_P_USDHC1_RESET_B                      22   /*!< CONN.USDHC1.RESET_B, CONN.NAND.RE_N, ADMA.SPI2.SCK, CONN.NAND.WE_B, LSIO.GPIO4.IO19, LSIO.GPIO7.IO08 */
#define SC_P_USDHC1_VSELECT                      23   /*!< CONN.USDHC1.VSELECT, CONN.NAND.RE_P, ADMA.SPI2.SDO, CONN.NAND.RE_B, LSIO.GPIO4.IO20, LSIO.GPIO7.IO09 */
#define SC_P_CTL_NAND_RE_P_N                     24   /*!<  */
#define SC_P_USDHC1_WP                           25   /*!< CONN.USDHC1.WP, CONN.NAND.DQS_N, ADMA.SPI2.SDI, CONN.NAND.ALE, LSIO.GPIO4.IO21, LSIO.GPIO7.IO10 */
#define SC_P_USDHC1_CD_B                         26   /*!< CONN.USDHC1.CD_B, CONN.NAND.DQS_P, ADMA.SPI2.CS0, CONN.NAND.DQS, LSIO.GPIO4.IO22, LSIO.GPIO7.IO11 */
#define SC_P_CTL_NAND_DQS_P_N                    27   /*!<  */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_VSELSEP       28   /*!<  */
#define SC_P_ENET0_RGMII_TXC                     29   /*!< CONN.ENET0.RGMII_TXC, CONN.ENET0.RCLK50M_OUT, CONN.ENET0.RCLK50M_IN, CONN.NAND.CE1_B, LSIO.GPIO4.IO29, CONN.USDHC2.CLK */
#define SC_P_ENET0_RGMII_TX_CTL                  30   /*!< CONN.ENET0.RGMII_TX_CTL, CONN.USDHC1.RESET_B, LSIO.GPIO4.IO30, CONN.USDHC2.CMD */
#define SC_P_ENET0_RGMII_TXD0                    31   /*!< CONN.ENET0.RGMII_TXD0, CONN.USDHC1.VSELECT, LSIO.GPIO4.IO31, CONN.USDHC2.DATA0 */
#define SC_P_ENET0_RGMII_TXD1                    32   /*!< CONN.ENET0.RGMII_TXD1, CONN.USDHC1.WP, LSIO.GPIO5.IO00, CONN.USDHC2.DATA1 */
#define SC_P_ENET0_RGMII_TXD2                    33   /*!< CONN.ENET0.RGMII_TXD2, CONN.NAND.CE0_B, CONN.USDHC1.CD_B, LSIO.GPIO5.IO01, CONN.USDHC2.DATA2 */
#define SC_P_ENET0_RGMII_TXD3                    34   /*!< CONN.ENET0.RGMII_TXD3, CONN.NAND.RE_B, LSIO.GPIO5.IO02, CONN.USDHC2.DATA3 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_ENET_ENETB0   35   /*!<  */
#define SC_P_ENET0_RGMII_RXC                     36   /*!< CONN.ENET0.RGMII_RXC, CONN.NAND.WE_B, CONN.USDHC1.CLK, LSIO.GPIO5.IO03 */
#define SC_P_ENET0_RGMII_RX_CTL                  37   /*!< CONN.ENET0.RGMII_RX_CTL, CONN.USDHC1.CMD, LSIO.GPIO5.IO04 */
#define SC_P_ENET0_RGMII_RXD0                    38   /*!< CONN.ENET0.RGMII_RXD0, CONN.USDHC1.DATA0, LSIO.GPIO5.IO05 */
#define SC_P_ENET0_RGMII_RXD1                    39   /*!< CONN.ENET0.RGMII_RXD1, CONN.USDHC1.DATA1, LSIO.GPIO5.IO06 */
#define SC_P_ENET0_RGMII_RXD2                    40   /*!< CONN.ENET0.RGMII_RXD2, CONN.ENET0.RMII_RX_ER, CONN.USDHC1.DATA2, LSIO.GPIO5.IO07 */
#define SC_P_ENET0_RGMII_RXD3                    41   /*!< CONN.ENET0.RGMII_RXD3, CONN.NAND.ALE, CONN.USDHC1.DATA3, LSIO.GPIO5.IO08 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_ENET_ENETB1   42   /*!<  */
#define SC_P_ENET0_REFCLK_125M_25M               43   /*!< CONN.ENET0.REFCLK_125M_25M, CONN.ENET0.PPS, CONN.EQOS.PPS_IN, CONN.EQOS.PPS_OUT, LSIO.GPIO5.IO09 */
#define SC_P_ENET0_MDIO                          44   /*!< CONN.ENET0.MDIO, ADMA.I2C3.SDA, CONN.EQOS.MDIO, LSIO.GPIO5.IO10, LSIO.GPIO7.IO16 */
#define SC_P_ENET0_MDC                           45   /*!< CONN.ENET0.MDC, ADMA.I2C3.SCL, CONN.EQOS.MDC, LSIO.GPIO5.IO11, LSIO.GPIO7.IO17 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_GPIOCT        46   /*!<  */
#define SC_P_ENET1_RGMII_TXC                     47   /*!< LSIO.GPIO0.IO00, CONN.EQOS.RCLK50M_OUT, ADMA.LCDIF.D00, CONN.EQOS.RGMII_TXC, CONN.EQOS.RCLK50M_IN */
#define SC_P_ENET1_RGMII_TXD2                    48   /*!< , ADMA.LCDIF.D01, CONN.EQOS.RGMII_TXD2, LSIO.GPIO0.IO01 */
#define SC_P_ENET1_RGMII_TX_CTL                  49   /*!< , ADMA.LCDIF.D02, CONN.EQOS.RGMII_TX_CTL, LSIO.GPIO0.IO02 */
#define SC_P_ENET1_RGMII_TXD3                    50   /*!< , ADMA.LCDIF.D03, CONN.EQOS.RGMII_TXD3, LSIO.GPIO0.IO03 */
#define SC_P_ENET1_RGMII_RXC                     51   /*!< , ADMA.LCDIF.D04, CONN.EQOS.RGMII_RXC, LSIO.GPIO0.IO04 */
#define SC_P_ENET1_RGMII_RXD3                    52   /*!< , ADMA.LCDIF.D05, CONN.EQOS.RGMII_RXD3, LSIO.GPIO0.IO05 */
#define SC_P_ENET1_RGMII_RXD2                    53   /*!< , ADMA.LCDIF.D06, CONN.EQOS.RGMII_RXD2, LSIO.GPIO0.IO06, LSIO.GPIO6.IO00 */
#define SC_P_ENET1_RGMII_RXD1                    54   /*!< , ADMA.LCDIF.D07, CONN.EQOS.RGMII_RXD1, LSIO.GPIO0.IO07, LSIO.GPIO6.IO01 */
#define SC_P_ENET1_RGMII_TXD0                    55   /*!< , ADMA.LCDIF.D08, CONN.EQOS.RGMII_TXD0, LSIO.GPIO0.IO08, LSIO.GPIO6.IO02 */
#define SC_P_ENET1_RGMII_TXD1                    56   /*!< , ADMA.LCDIF.D09, CONN.EQOS.RGMII_TXD1, LSIO.GPIO0.IO09, LSIO.GPIO6.IO03 */
#define SC_P_ENET1_RGMII_RXD0                    57   /*!< ADMA.SPDIF0.RX, ADMA.MQS.R, ADMA.LCDIF.D10, CONN.EQOS.RGMII_RXD0, LSIO.GPIO0.IO10, LSIO.GPIO6.IO04 */
#define SC_P_ENET1_RGMII_RX_CTL                  58   /*!< ADMA.SPDIF0.TX, ADMA.MQS.L, ADMA.LCDIF.D11, CONN.EQOS.RGMII_RX_CTL, LSIO.GPIO0.IO11, LSIO.GPIO6.IO05 */
#define SC_P_ENET1_REFCLK_125M_25M               59   /*!< ADMA.SPDIF0.EXT_CLK, ADMA.LCDIF.D12, CONN.EQOS.REFCLK_125M_25M, LSIO.GPIO0.IO12, LSIO.GPIO6.IO06 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_GPIORHB       60   /*!<  */
#define SC_P_SPI3_SCK                            61   /*!< ADMA.SPI3.SCK, ADMA.LCDIF.D13, LSIO.GPIO0.IO13, ADMA.LCDIF.D00 */
#define SC_P_SPI3_SDO                            62   /*!< ADMA.SPI3.SDO, ADMA.LCDIF.D14, LSIO.GPIO0.IO14, ADMA.LCDIF.D01 */
#define SC_P_SPI3_SDI                            63   /*!< ADMA.SPI3.SDI, ADMA.LCDIF.D15, LSIO.GPIO0.IO15, ADMA.LCDIF.D02 */
#define SC_P_SPI3_CS0                            64   /*!< ADMA.SPI3.CS0, ADMA.ACM.MCLK_OUT1, ADMA.LCDIF.HSYNC, LSIO.GPIO0.IO16, ADMA.LCDIF.CS */
#define SC_P_SPI3_CS1                            65   /*!< ADMA.SPI3.CS1, ADMA.I2C3.SCL, ADMA.LCDIF.RESET, ADMA.SPI2.CS0, ADMA.LCDIF.D16, ADMA.LCDIF.RD_E */
#define SC_P_MCLK_IN1                            66   /*!< ADMA.ACM.MCLK_IN1, ADMA.I2C3.SDA, ADMA.LCDIF.EN, ADMA.SPI2.SCK, ADMA.LCDIF.D17, ADMA.LCDIF.D03 */
#define SC_P_MCLK_IN0                            67   /*!< ADMA.ACM.MCLK_IN0, ADMA.LCDIF.VSYNC, ADMA.SPI2.SDI, LSIO.GPIO0.IO19, ADMA.LCDIF.RS */
#define SC_P_MCLK_OUT0                           68   /*!< ADMA.ACM.MCLK_OUT0, ADMA.LCDIF.CLK, ADMA.SPI2.SDO, LSIO.GPIO0.IO20, ADMA.LCDIF.WR_RWN */
#define SC_P_UART1_TX                            69   /*!< ADMA.UART1.TX, LSIO.PWM0.OUT, LSIO.GPT0.CAPTURE, LSIO.GPIO0.IO21, ADMA.LCDIF.D04 */
#define SC_P_UART1_RX                            70   /*!< ADMA.UART1.RX, LSIO.PWM1.OUT, LSIO.GPT0.COMPARE, LSIO.GPT1.CLK, LSIO.GPIO0.IO22, ADMA.LCDIF.D05 */
#define SC_P_UART1_RTS_B                         71   /*!< ADMA.UART1.RTS_B, LSIO.PWM2.OUT, ADMA.LCDIF.D16, LSIO.GPT1.CAPTURE, LSIO.GPT0.CLK, ADMA.LCDIF.D06 */
#define SC_P_UART1_CTS_B                         72   /*!< ADMA.UART1.CTS_B, LSIO.PWM3.OUT, ADMA.LCDIF.D17, LSIO.GPT1.COMPARE, LSIO.GPIO0.IO24, ADMA.LCDIF.D07 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_GPIORHK       73   /*!<  */
#define SC_P_SPI0_SCK                            74   /*!< ADMA.SPI0.SCK, ADMA.SAI0.TXC, M40.I2C0.SCL, M40.GPIO0.IO00, LSIO.GPIO1.IO04, ADMA.LCDIF.D08 */
#define SC_P_SPI0_SDI                            75   /*!< ADMA.SPI0.SDI, ADMA.SAI0.TXD, M40.TPM0.CH0, M40.GPIO0.IO02, LSIO.GPIO1.IO05, ADMA.LCDIF.D09 */
#define SC_P_SPI0_SDO                            76   /*!< ADMA.SPI0.SDO, ADMA.SAI0.TXFS, M40.I2C0.SDA, M40.GPIO0.IO01, LSIO.GPIO1.IO06, ADMA.LCDIF.D10 */
#define SC_P_SPI0_CS1                            77   /*!< ADMA.SPI0.CS1, ADMA.SAI0.RXC, ADMA.SAI1.TXD, ADMA.LCD_PWM0.OUT, LSIO.GPIO1.IO07, ADMA.LCDIF.D11 */
#define SC_P_SPI0_CS0                            78   /*!< ADMA.SPI0.CS0, ADMA.SAI0.RXD, M40.TPM0.CH1, M40.GPIO0.IO03, LSIO.GPIO1.IO08, ADMA.LCDIF.D12 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_GPIORHT       79   /*!<  */
#define SC_P_ADC_IN1                             80   /*!< ADMA.ADC.IN1, M40.I2C0.SDA, M40.GPIO0.IO01, ADMA.I2C0.SDA, LSIO.GPIO1.IO09, ADMA.LCDIF.D13 */
#define SC_P_ADC_IN0                             81   /*!< ADMA.ADC.IN0, M40.I2C0.SCL, M40.GPIO0.IO00, ADMA.I2C0.SCL, LSIO.GPIO1.IO10, ADMA.LCDIF.D14 */
#define SC_P_ADC_IN3                             82   /*!< ADMA.ADC.IN3, M40.UART0.TX, M40.GPIO0.IO03, ADMA.ACM.MCLK_OUT0, LSIO.GPIO1.IO11, ADMA.LCDIF.D15 */
#define SC_P_ADC_IN2                             83   /*!< ADMA.ADC.IN2, M40.UART0.RX, M40.GPIO0.IO02, ADMA.ACM.MCLK_IN0, LSIO.GPIO1.IO12, ADMA.LCDIF.D16 */
#define SC_P_ADC_IN5                             84   /*!< ADMA.ADC.IN5, M40.TPM0.CH1, M40.GPIO0.IO05, ADMA.LCDIF.LCDBUSY, LSIO.GPIO1.IO13, ADMA.LCDIF.D17 */
#define SC_P_ADC_IN4                             85   /*!< ADMA.ADC.IN4, M40.TPM0.CH0, M40.GPIO0.IO04, ADMA.LCDIF.LCDRESET, LSIO.GPIO1.IO14 */
#define SC_P_FLEXCAN0_RX                         86   /*!< ADMA.FLEXCAN0.RX, ADMA.SAI2.RXC, ADMA.UART0.RTS_B, ADMA.SAI1.TXC, LSIO.GPIO1.IO15, LSIO.GPIO6.IO08 */
#define SC_P_FLEXCAN0_TX                         87   /*!< ADMA.FLEXCAN0.TX, ADMA.SAI2.RXD, ADMA.UART0.CTS_B, ADMA.SAI1.TXFS, LSIO.GPIO1.IO16, LSIO.GPIO6.IO09 */
#define SC_P_FLEXCAN1_RX                         88   /*!< ADMA.FLEXCAN1.RX, ADMA.SAI2.RXFS, ADMA.FTM.CH2, ADMA.SAI1.TXD, LSIO.GPIO1.IO17, LSIO.GPIO6.IO10 */
#define SC_P_FLEXCAN1_TX                         89   /*!< ADMA.FLEXCAN1.TX, ADMA.SAI3.RXC, ADMA.DMA0.REQ_IN0, ADMA.SAI1.RXD, LSIO.GPIO1.IO18, LSIO.GPIO6.IO11 */
#define SC_P_FLEXCAN2_RX                         90   /*!< ADMA.FLEXCAN2.RX, ADMA.SAI3.RXD, ADMA.UART3.RX, ADMA.SAI1.RXFS, LSIO.GPIO1.IO19, LSIO.GPIO6.IO12 */
#define SC_P_FLEXCAN2_TX                         91   /*!< ADMA.FLEXCAN2.TX, ADMA.SAI3.RXFS, ADMA.UART3.TX, ADMA.SAI1.RXC, LSIO.GPIO1.IO20, LSIO.GPIO6.IO13 */
#define SC_P_UART0_RX                            92   /*!< ADMA.UART0.RX, ADMA.MQS.R, ADMA.FLEXCAN0.RX, SCU.UART0.RX, LSIO.GPIO1.IO21, LSIO.GPIO6.IO14 */
#define SC_P_UART0_TX                            93   /*!< ADMA.UART0.TX, ADMA.MQS.L, ADMA.FLEXCAN0.TX, SCU.UART0.TX, LSIO.GPIO1.IO22, LSIO.GPIO6.IO15 */
#define SC_P_UART2_TX                            94   /*!< ADMA.UART2.TX, ADMA.FTM.CH1, ADMA.FLEXCAN1.TX, LSIO.GPIO1.IO23, LSIO.GPIO6.IO16 */
#define SC_P_UART2_RX                            95   /*!< ADMA.UART2.RX, ADMA.FTM.CH0, ADMA.FLEXCAN1.RX, LSIO.GPIO1.IO24, LSIO.GPIO6.IO17 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_GPIOLH        96   /*!<  */
#define SC_P_JTAG_TRST_B                         97   /*!< SCU.JTAG.TRST_B, SCU.WDOG0.WDOG_OUT */
#define SC_P_PMIC_I2C_SCL                        98   /*!< SCU.PMIC_I2C.SCL, SCU.GPIO0.IOXX_PMIC_A35_ON, LSIO.GPIO2.IO01 */
#define SC_P_PMIC_I2C_SDA                        99   /*!< SCU.PMIC_I2C.SDA, SCU.GPIO0.IOXX_PMIC_GPU_ON, LSIO.GPIO2.IO02 */
#define SC_P_PMIC_INT_B                          100  /*!< SCU.DSC.PMIC_INT_B */
#define SC_P_SCU_GPIO0_00                        101  /*!< SCU.GPIO0.IO00, SCU.UART0.RX, M40.UART0.RX, ADMA.UART3.RX, LSIO.GPIO2.IO03 */
#define SC_P_SCU_GPIO0_01                        102  /*!< SCU.GPIO0.IO01, SCU.UART0.TX, M40.UART0.TX, ADMA.UART3.TX, SCU.WDOG0.WDOG_OUT */
#define SC_P_SCU_PMIC_STANDBY                    103  /*!< SCU.DSC.PMIC_STANDBY */
#define SC_P_SCU_BOOT_MODE1                      104  /*!< SCU.DSC.BOOT_MODE1 */
#define SC_P_SCU_BOOT_MODE0                      105  /*!< SCU.DSC.BOOT_MODE0 */
#define SC_P_SCU_BOOT_MODE2                      106  /*!< SCU.DSC.BOOT_MODE2, SCU.DSC.RTC_CLOCK_OUTPUT_32K */
#define SC_P_SNVS_TAMPER_OUT1                    107  /*!< , LSIO.GPIO2.IO05_IN, LSIO.GPIO6.IO19_IN */
#define SC_P_SNVS_TAMPER_OUT2                    108  /*!< , LSIO.GPIO2.IO06_IN, LSIO.GPIO6.IO20_IN */
#define SC_P_SNVS_TAMPER_OUT3                    109  /*!< , ADMA.SAI2.RXC, LSIO.GPIO2.IO07_IN, LSIO.GPIO6.IO21_IN */
#define SC_P_SNVS_TAMPER_OUT4                    110  /*!< , ADMA.SAI2.RXD, LSIO.GPIO2.IO08_IN, LSIO.GPIO6.IO22_IN */
#define SC_P_SNVS_TAMPER_IN0                     111  /*!< , ADMA.SAI2.RXFS, LSIO.GPIO2.IO09_IN, LSIO.GPIO6.IO23_IN */
#define SC_P_SNVS_TAMPER_IN1                     112  /*!< , ADMA.SAI3.RXC, LSIO.GPIO2.IO10_IN, LSIO.GPIO6.IO24_IN */
#define SC_P_SNVS_TAMPER_IN2                     113  /*!< , ADMA.SAI3.RXD, LSIO.GPIO2.IO11_IN, LSIO.GPIO6.IO25_IN */
#define SC_P_SNVS_TAMPER_IN3                     114  /*!< , ADMA.SAI3.RXFS, LSIO.GPIO2.IO12_IN, LSIO.GPIO6.IO26_IN */
#define SC_P_SPI1_SCK                            115  /*!< , ADMA.I2C2.SDA, ADMA.SPI1.SCK, LSIO.GPIO3.IO00 */
#define SC_P_SPI1_SDO                            116  /*!< , ADMA.I2C2.SCL, ADMA.SPI1.SDO, LSIO.GPIO3.IO01 */
#define SC_P_SPI1_SDI                            117  /*!< , ADMA.I2C3.SCL, ADMA.SPI1.SDI, LSIO.GPIO3.IO02 */
#define SC_P_SPI1_CS0                            118  /*!< , ADMA.I2C3.SDA, ADMA.SPI1.CS0, LSIO.GPIO3.IO03 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_GPIORHD       119  /*!<  */
#define SC_P_QSPI0A_DATA1                        120  /*!< LSIO.QSPI0A.DATA1, LSIO.GPIO3.IO10 */
#define SC_P_QSPI0A_DATA0                        121  /*!< LSIO.QSPI0A.DATA0, LSIO.GPIO3.IO09 */
#define SC_P_QSPI0A_DATA3                        122  /*!< LSIO.QSPI0A.DATA3, LSIO.GPIO3.IO12 */
#define SC_P_QSPI0A_DATA2                        123  /*!< LSIO.QSPI0A.DATA2, LSIO.GPIO3.IO11 */
#define SC_P_QSPI0A_SS0_B                        124  /*!< LSIO.QSPI0A.SS0_B, LSIO.GPIO3.IO14 */
#define SC_P_QSPI0A_DQS                          125  /*!< LSIO.QSPI0A.DQS, LSIO.GPIO3.IO13 */
#define SC_P_QSPI0A_SCLK                         126  /*!< LSIO.QSPI0A.SCLK, LSIO.GPIO3.IO16 */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_QSPI0A        127  /*!<  */
#define SC_P_QSPI0B_SCLK                         128  /*!< LSIO.QSPI0B.SCLK, LSIO.GPIO3.IO17 */
#define SC_P_QSPI0B_DQS                          129  /*!< LSIO.QSPI0B.DQS, LSIO.GPIO3.IO22 */
#define SC_P_QSPI0B_DATA1                        130  /*!< LSIO.QSPI0B.DATA1, LSIO.GPIO3.IO19 */
#define SC_P_QSPI0B_DATA0                        131  /*!< LSIO.QSPI0B.DATA0, LSIO.GPIO3.IO18 */
#define SC_P_QSPI0B_DATA3                        132  /*!< LSIO.QSPI0B.DATA3, LSIO.GPIO3.IO21 */
#define SC_P_QSPI0B_DATA2                        133  /*!< LSIO.QSPI0B.DATA2, LSIO.GPIO3.IO20 */
#define SC_P_QSPI0B_SS0_B                        134  /*!< LSIO.QSPI0B.SS0_B, LSIO.GPIO3.IO23, LSIO.QSPI0A.SS1_B */
#define SC_P_COMP_CTL_GPIO_1V8_3V3_QSPI0B        135  /*!<  */
/** @} */

#endif /* SC_PADS_H */
