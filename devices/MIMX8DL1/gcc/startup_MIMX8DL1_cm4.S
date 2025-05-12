/* ------------------------------------------------------------------------- */
/*  @file:    startup_MIMX8DL1_cm4.s                                         */
/*  @purpose: CMSIS Cortex-M4 Core Device Startup File                       */
/*            MIMX8DL1_cm4                                                   */
/*  @version: 4.0                                                            */
/*  @date:    2020-10-30                                                     */
/*  @build:   b201113                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 1997-2016 Freescale Semiconductor, Inc.                         */
/* Copyright 2016-2020 NXP                                                   */
/* All rights reserved.                                                      */
/*                                                                           */
/* SPDX-License-Identifier: BSD-3-Clause                                     */
/*****************************************************************************/
/* Version: GCC for ARM Embedded Processors                                  */
/*****************************************************************************/
    .syntax unified
    .arch armv7-m

    .section .isr_vector, "a"
    .align 2
    .globl __isr_vector
__isr_vector:
    .long   __StackTop                                      /* Top of Stack */
#ifdef __STARTUP_CONFIG_DDR_ALIAS
    .long   Reset_Handler+0x80000000
#else
    .long   Reset_Handler                                   /* Reset Handler */
#endif
    .long   NMI_Handler                                     /* NMI Handler*/
    .long   HardFault_Handler                               /* Hard Fault Handler*/
    .long   MemManage_Handler                               /* MPU Fault Handler*/
    .long   BusFault_Handler                                /* Bus Fault Handler*/
    .long   UsageFault_Handler                              /* Usage Fault Handler*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   SVC_Handler                                     /* SVCall Handler*/
    .long   DebugMon_Handler                                /* Debug Monitor Handler*/
    .long   0                                               /* Reserved*/
    .long   PendSV_Handler                                  /* PendSV Handler*/
    .long   SysTick_Handler                                 /* SysTick Handler*/

                                                            /* External Interrupts*/
    .long   Reserved16_IRQHandler                           /* Reserved*/
    .long   Reserved17_IRQHandler                           /* Reserved*/
    .long   Reserved18_IRQHandler                           /* Reserved*/
    .long   Reserved19_IRQHandler                           /* Reserved*/
    .long   Reserved20_IRQHandler                           /* Reserved*/
    .long   M4_MCM_IRQHandler                               /* MCM IRQ*/
    .long   Reserved22_IRQHandler                           /* Reserved*/
    .long   Reserved23_IRQHandler                           /* Reserved*/
    .long   Reserved24_IRQHandler                           /* Reserved*/
    .long   Reserved25_IRQHandler                           /* Reserved*/
    .long   Reserved26_IRQHandler                           /* Reserved*/
    .long   Reserved27_IRQHandler                           /* Reserved*/
    .long   Reserved28_IRQHandler                           /* Reserved*/
    .long   Reserved29_IRQHandler                           /* Reserved*/
    .long   Reserved30_IRQHandler                           /* Reserved*/
    .long   Reserved31_IRQHandler                           /* Reserved*/
    .long   Reserved32_IRQHandler                           /* Reserved*/
    .long   Reserved33_IRQHandler                           /* Reserved*/
    .long   Reserved34_IRQHandler                           /* Reserved*/
    .long   M4_TPM_IRQHandler                               /* Timer PWM Module*/
    .long   Reserved36_IRQHandler                           /* Reserved*/
    .long   Reserved37_IRQHandler                           /* Reserved*/
    .long   M4_LPIT_IRQHandler                              /* Low-Power Periodic Interrupt Timer*/
    .long   Reserved39_IRQHandler                           /* Reserved*/
    .long   Reserved40_IRQHandler                           /* Reserved*/
    .long   M4_LPUART_IRQHandler                            /* Low Power UART*/
    .long   Reserved42_IRQHandler                           /* Reserved*/
    .long   M4_LPI2C_IRQHandler                             /* Low-Power I2C - Logical OR of master and slave interrupts*/
    .long   Reserved44_IRQHandler                           /* Reserved*/
    .long   M4_MU0_B0_IRQHandler                            /* Messaging Unit 0 (IPC with other subsystems) - Side B (local), Port 0, Logical OR of all general-purpose, TX, and RX interrupts*/
    .long   Reserved46_IRQHandler                           /* Reserved*/
    .long   Reserved47_IRQHandler                           /* Reserved*/
    .long   IRQSTEER_0_IRQHandler                           /* External interrupt 0*/
    .long   IRQSTEER_1_IRQHandler                           /* External interrupt 1*/
    .long   IRQSTEER_2_IRQHandler                           /* External interrupt 2*/
    .long   IRQSTEER_3_IRQHandler                           /* External interrupt 3*/
    .long   IRQSTEER_4_IRQHandler                           /* External interrupt 4*/
    .long   IRQSTEER_5_IRQHandler                           /* External interrupt 5*/
    .long   Reserved54_IRQHandler                           /* xxx Interrupt 54*/
    .long   Reserved55_IRQHandler                           /* xxx Interrupt 55*/
    .long   Reserved56_IRQHandler                           /* Reserved*/
    .long   Reserved57_IRQHandler                           /* Reserved*/
    .long   Reserved58_IRQHandler                           /* Reserved*/
    .long   Reserved59_IRQHandler                           /* Reserved*/
    .long   M4_MU0_B1_IRQHandler                            /* Messaging Unit 0 (IPC with other subsystems) - Side B (local), Port 1, Logical OR of all general-purpose, TX, and RX interrupts*/
    .long   M4_MU0_B2_IRQHandler                            /* Messaging Unit 0 (IPC with other subsystems) - Side B (local), Port 2, Logical OR of all general-purpose, TX, and RX interrupts*/
    .long   M4_MU0_B3_IRQHandler                            /* Messaging Unit 0 (IPC with other subsystems) - Side B (local), Port 3, Logical OR of all general-purpose, TX, and RX interrupts*/
    .long   Reserved63_IRQHandler                           /* Reserved*/
    .long   Reserved64_IRQHandler                           /* Reserved*/
    .long   M4_MU1_A_IRQHandler                             /* Messaging Unit 1 (IPC with System Controller) - Side A (MCU), Logical OR of all general-purpose, TX, and RX interrupts*/
    .long   M4_SW_IRQHandler                                /* Software interrupt (asserted/cleared via NVIC registers, INTISR[50] input tied low)*/
    .long   Reserved67_IRQHandler                           /* xxx Interrupt 67*/
    .long   Reserved68_IRQHandler                           /* xxx Interrupt 68*/
    .long   Reserved69_IRQHandler                           /* xxx Interrupt 69*/
    .long   Reserved70_IRQHandler                           /* xxx Interrupt 70*/
    .long   Reserved71_IRQHandler                           /* xxx Interrupt 71*/
    .long   Reserved72_IRQHandler                           /* xxx Interrupt 72*/
    .long   Reserved73_IRQHandler                           /* xxx Interrupt 73*/
    .long   Reserved74_IRQHandler                           /* xxx Interrupt 74*/
    .long   Reserved75_IRQHandler                           /* xxx Interrupt 75*/
    .long   Reserved76_IRQHandler                           /* xxx Interrupt 76*/
    .long   Reserved77_IRQHandler                           /* xxx Interrupt 77*/
    .long   Reserved78_IRQHandler                           /* xxx Interrupt 78*/
    .long   Reserved79_IRQHandler                           /* xxx Interrupt 79*/
    .long   Reserved80_IRQHandler                           /* xxx Interrupt 80*/
    .long   Reserved81_IRQHandler                           /* xxx Interrupt 81*/
    .long   Reserved82_IRQHandler                           /* xxx Interrupt 82*/
    .long   Reserved83_IRQHandler                           /* xxx Interrupt 83*/
    .long   Reserved84_IRQHandler                           /* xxx Interrupt 84*/
    .long   Reserved85_IRQHandler                           /* xxx Interrupt 85*/
    .long   Reserved86_IRQHandler                           /* xxx Interrupt 86*/
    .long   Reserved87_IRQHandler                           /* xxx Interrupt 87*/
    .long   Reserved88_IRQHandler                           /* xxx Interrupt 88*/
    .long   Reserved89_IRQHandler                           /* xxx Interrupt 89*/
    .long   Reserved90_IRQHandler                           /* xxx Interrupt 90*/
    .long   Reserved91_IRQHandler                           /* xxx Interrupt 91*/
    .long   Reserved92_IRQHandler                           /* xxx Interrupt 92*/
    .long   Reserved93_IRQHandler                           /* xxx Interrupt 93*/
    .long   Reserved94_IRQHandler                           /* xxx Interrupt 94*/
    .long   Reserved95_IRQHandler                           /* xxx Interrupt 95*/
    .long   Reserved96_IRQHandler                           /* xxx Interrupt 96*/
    .long   Reserved97_IRQHandler                           /* xxx Interrupt 97*/
    .long   Reserved98_IRQHandler                           /* xxx Interrupt 98*/
    .long   A35_NINTERRIRQ_IRQHandler                       /* Shared Int Source nINTERRIRQ from A35 Sub-System*/
    .long   A35_NEXTERRIRQ_IRQHandler                       /* Shared Int Source nEXTERRIRQ from A35 Sub-System*/
    .long   Reserved101_IRQHandler                          /* xxx Interrupt 101*/
    .long   Reserved102_IRQHandler                          /* xxx Interrupt 102*/
    .long   Reserved103_IRQHandler                          /* xxx Interrupt 103*/
    .long   Reserved104_IRQHandler                          /* xxx Interrupt 104*/
    .long   Reserved105_IRQHandler                          /* xxx Interrupt 105*/
    .long   Reserved106_IRQHandler                          /* xxx Interrupt 106*/
    .long   M4_INT_OUT0_IRQHandler                          /* Shared Int Source INT_OUT[0] from M4 Sub-System*/
    .long   M4_INT_OUT1_IRQHandler                          /* Shared Int Source INT_OUT[1] from M4 Sub-System*/
    .long   M4_INT_OUT2_IRQHandler                          /* Shared Int Source INT_OUT[2] from M4 Sub-System*/
    .long   M4_INT_OUT3_IRQHandler                          /* Shared Int Source INT_OUT[3] from M4 Sub-System*/
    .long   M4_INT_OUT4_IRQHandler                          /* Shared Int Source INT_OUT[4] from M4 Sub-System*/
    .long   M4_INT_OUT5_IRQHandler                          /* Shared Int Source INT_OUT[5] from M4 Sub-System*/
    .long   M4_INT_OUT6_IRQHandler                          /* Shared Int Source INT_OUT[6] from M4 Sub-System*/
    .long   M4_INT_OUT7_IRQHandler                          /* Shared Int Source INT_OUT[7] from M4 Sub-System*/
    .long   Reserved115_IRQHandler                          /* xxx Interrupt 115*/
    .long   Reserved116_IRQHandler                          /* xxx Interrupt 116*/
    .long   LCD_MOD_INT_IRQHandler                          /* Shared Int Source INT_OUT from ADMA Sub-System*/
    .long   LCD_PWM_INT_IRQHandler                          /* Shared Int Source INT_OUT from ADMA Sub-System*/
    .long   ADMA_EDMA2_INT_IRQHandler                       /* Shared Int Source eDMA2_INT from ADMA Sub-System*/
    .long   ADMA_EDMA2_ERR_INT_IRQHandler                   /* Shared Int Source eDMA2_ERR_INT from ADMA Sub-System*/
    .long   ADMA_EDMA3_INT_IRQHandler                       /* Shared Int Source eDMA3_INT from ADMA Sub-System*/
    .long   ADMA_EDMA3_ERR_INT_IRQHandler                   /* Shared Int Source eDMA3_ERR_INT from ADMA Sub-System*/
    .long   Reserved123_IRQHandler                          /* xxx Interrupt 123*/
    .long   Reserved124_IRQHandler                          /* xxx Interrupt 124*/
    .long   Reserved125_IRQHandler                          /* xxx Interrupt 125*/
    .long   Reserved126_IRQHandler                          /* xxx Interrupt 126*/
    .long   LSIO_GPT0_INT_IRQHandler                        /* Shared Int Source GPT0_INT from LSIO Sub-System*/
    .long   LSIO_GPT1_INT_IRQHandler                        /* Shared Int Source GPT1_INT from LSIO Sub-System*/
    .long   LSIO_GPT2_INT_IRQHandler                        /* Shared Int Source GPT2_INT from LSIO Sub-System*/
    .long   LSIO_GPT3_INT_IRQHandler                        /* Shared Int Source GPT3_INT from LSIO Sub-System*/
    .long   LSIO_GPT4_INT_IRQHandler                        /* Shared Int Source GPT4_INT from LSIO Sub-System*/
    .long   LSIO_KPP_INT_IRQHandler                         /* Shared Int Source KPP_INT from LSIO Sub-System*/
    .long   LSIO_OCTASPI0_INT_IRQHandler                    /* Shared Int Source OctaSPI0_INT from LSIO Sub-System*/
    .long   LSIO_OCTASPI1_INT_IRQHandler                    /* Shared Int Source OctaSPI1_INT from LSIO Sub-System*/
    .long   LSIO_PWM0_INT_IRQHandler                        /* Shared Int Source PWM0_INT from LSIO Sub-System*/
    .long   LSIO_PWM1_INT_IRQHandler                        /* Shared Int Source PWM1_INT from LSIO Sub-System*/
    .long   LSIO_PWM2_INT_IRQHandler                        /* Shared Int Source PWM2_INT from LSIO Sub-System*/
    .long   LSIO_PWM3_INT_IRQHandler                        /* Shared Int Source PWM3_INT from LSIO Sub-System*/
    .long   LSIO_PWM4_INT_IRQHandler                        /* Shared Int Source PWM4_INT from LSIO Sub-System*/
    .long   LSIO_PWM5_INT_IRQHandler                        /* Shared Int Source PWM5_INT from LSIO Sub-System*/
    .long   LSIO_PWM6_INT_IRQHandler                        /* Shared Int Source PWM6_INT from LSIO Sub-System*/
    .long   LSIO_PWM7_INT_IRQHandler                        /* Shared Int Source PWM7_INT from LSIO Sub-System*/
    .long   HSIO_PCIEB_MSI_CTRL_INT_IRQHandler              /* Shared Int Source PCIeB_MSI_CTRL_INT from HSIO Sub-System*/
    .long   HSIO_PCIEB_CLK_REQ_INT_IRQHandler               /* Shared Int Source PCIeB_CLK_REQ_INT from HSIO Sub-System*/
    .long   HSIO_PCIEB_DMA_INT_IRQHandler                   /* Shared Int Source PCIeB_DMA_INT from HSIO Sub-System*/
    .long   HSIO_PCIEB_INT_A_IRQHandler                     /* Shared Int Source PCIeB_INT_A from HSIO Sub-System*/
    .long   HSIO_PCIEB_INT_B_IRQHandler                     /* Shared Int Source PCIeB_INT_B from HSIO Sub-System*/
    .long   HSIO_PCIEB_INT_C_IRQHandler                     /* Shared Int Source PCIeB_INT_C from HSIO Sub-System*/
    .long   HSIO_PCIEB_INT_D_IRQHandler                     /* Shared Int Source PCIeB_INT_D from HSIO Sub-System*/
    .long   HSIO_PCIEB_SMLH_REQ_RST_IRQHandler              /* Shared Int Source PCIeB_SMLH_REQ_RST from HSIO Sub-System*/
    .long   HSIO_PCIEB_GPIO_WAKEUP0_IRQHandler              /* Shared Int Source PCIeB_GPIO_WAKEUP[0] from HSIO Sub-System*/
    .long   HSIO_PCIEB_GPIO_WAKEUP1_IRQHandler              /* Shared Int Source PCIeB_GPIO_WAKEUP[1] from HSIO Sub-System*/
    .long   SCU_INT_OUT0_IRQHandler                         /* Shared Int Source INT_OUT[0] from SCU Sub-System*/
    .long   SCU_INT_OUT1_IRQHandler                         /* Shared Int Source INT_OUT[1] from SCU Sub-System*/
    .long   SCU_INT_OUT2_IRQHandler                         /* Shared Int Source INT_OUT[2] from SCU Sub-System*/
    .long   SCU_INT_OUT3_IRQHandler                         /* Shared Int Source INT_OUT[3] from SCU Sub-System*/
    .long   SCU_INT_OUT4_IRQHandler                         /* Shared Int Source INT_OUT[4] from SCU Sub-System*/
    .long   SCU_INT_OUT5_IRQHandler                         /* Shared Int Source INT_OUT[5] from SCU Sub-System*/
    .long   SCU_INT_OUT6_IRQHandler                         /* Shared Int Source INT_OUT[6] from SCU Sub-System*/
    .long   SCU_INT_OUT7_IRQHandler                         /* Shared Int Source INT_OUT[7] from SCU Sub-System*/
    .long   SCU_SYS_COUNT_INT0_IRQHandler                   /* Shared Int Source SYS_COUNT_INT0 from SCU Sub-System*/
    .long   SCU_SYS_COUNT_INT1_IRQHandler                   /* Shared Int Source SYS_COUNT_INT1 from SCU Sub-System*/
    .long   SCU_SYS_COUNT_INT2_IRQHandler                   /* Shared Int Source SYS_COUNT_INT2 from SCU Sub-System*/
    .long   SCU_SYS_COUNT_INT3_IRQHandler                   /* Shared Int Source SYS_COUNT_INT3 from SCU Sub-System*/
    .long   Reserved165_IRQHandler                          /* xxx Interrupt 165*/
    .long   Reserved166_IRQHandler                          /* xxx Interrupt 166*/
    .long   DRC_ECC_CORRECT_INT_IRQHandler                  /* Shared Int Source ECC_CORRECT_INT from DRC Sub-System*/
    .long   DRC_ECC_NCORRECT_INT_IRQHandler                 /* Shared Int Source ECC_NCORRECT_INT from DRC Sub-System*/
    .long   DRC_SBR_DONE_INT_IRQHandler                     /* Shared Int Source SBR_DONE_INT from DRC Sub-System*/
    .long   DRC_PERF_CNT_INT_IRQHandler                     /* Shared Int Source PERF_CNT_INT from DRC Sub-System*/
    .long   DRC_ECC_AP_ERR_INT_IRQHandler                   /* Shared Int Source ECC_AP_ERR from DRC Sub-System*/
    .long   DRC_DERATE_TEMP_LIMIT_INT_IRQHandler            /* Shared Int Source DERATE_TEMP_LIMIT from DRC Sub-System*/
    .long   Reserved173_IRQHandler                          /* xxx Interrupt 173*/
    .long   Reserved174_IRQHandler                          /* xxx Interrupt 174*/
    .long   Reserved175_IRQHandler                          /* xxx Interrupt 175*/
    .long   Reserved176_IRQHandler                          /* xxx Interrupt 176*/
    .long   LSIO_GPIO_INT0_IRQHandler                       /* Shared Int Source GPIO_INT[0] from LSIO Sub-System*/
    .long   LSIO_GPIO_INT1_IRQHandler                       /* Shared Int Source GPIO_INT[1] from LSIO Sub-System*/
    .long   LSIO_GPIO_INT2_IRQHandler                       /* Shared Int Source GPIO_INT[2] from LSIO Sub-System*/
    .long   LSIO_GPIO_INT3_IRQHandler                       /* Shared Int Source GPIO_INT[3] from LSIO Sub-System*/
    .long   LSIO_GPIO_INT4_IRQHandler                       /* Shared Int Source GPIO_INT[4] from LSIO Sub-System*/
    .long   LSIO_GPIO_INT5_IRQHandler                       /* Shared Int Source GPIO_INT[5] from LSIO Sub-System*/
    .long   LSIO_GPIO_INT6_IRQHandler                       /* Shared Int Source GPIO_INT[6] from LSIO Sub-System*/
    .long   LSIO_GPIO_INT7_IRQHandler                       /* Shared Int Source GPIO_INT[7] from LSIO Sub-System*/
    .long   LSIO_MU0_INT_IRQHandler                         /* Shared Int Source MU0_INT from LSIO Sub-System*/
    .long   LSIO_MU1_INT_IRQHandler                         /* Shared Int Source MU1_INT from LSIO Sub-System*/
    .long   LSIO_MU2_INT_IRQHandler                         /* Shared Int Source MU2_INT from LSIO Sub-System*/
    .long   LSIO_MU3_INT_IRQHandler                         /* Shared Int Source MU3_INT from LSIO Sub-System*/
    .long   LSIO_MU4_INT_IRQHandler                         /* Shared Int Source MU4_INT from LSIO Sub-System*/
    .long   LSIO_MU5_INT_A_IRQHandler                       /* Shared Int Source MU5_INT_A from LSIO Sub-System*/
    .long   LSIO_MU6_INT_A_IRQHandler                       /* Shared Int Source MU6_INT_A from LSIO Sub-System*/
    .long   LSIO_MU7_INT_A_IRQHandler                       /* Shared Int Source MU7_INT_A from LSIO Sub-System*/
    .long   LSIO_MU8_INT_A_IRQHandler                       /* Shared Int Source MU8_INT_A from LSIO Sub-System*/
    .long   LSIO_MU9_INT_A_IRQHandler                       /* Shared Int Source MU9_INT_A from LSIO Sub-System*/
    .long   LSIO_MU10_INT_A_IRQHandler                      /* Shared Int Source MU10_INT_A from LSIO Sub-System*/
    .long   LSIO_MU11_INT_A_IRQHandler                      /* Shared Int Source MU11_INT_A from LSIO Sub-System*/
    .long   LSIO_MU12_INT_A_IRQHandler                      /* Shared Int Source MU12_INT_A from LSIO Sub-System*/
    .long   LSIO_MU13_INT_A_IRQHandler                      /* Shared Int Source MU13_INT_A from LSIO Sub-System*/
    .long   LSIO_MU5_INT_B_IRQHandler                       /* Shared Int Source MU5_INT_B from LSIO Sub-System*/
    .long   LSIO_MU6_INT_B_IRQHandler                       /* Shared Int Source MU6_INT_B from LSIO Sub-System*/
    .long   LSIO_MU7_INT_B_IRQHandler                       /* Shared Int Source MU7_INT_B from LSIO Sub-System*/
    .long   LSIO_MU8_INT_B_IRQHandler                       /* Shared Int Source MU8_INT_B from LSIO Sub-System*/
    .long   LSIO_MU9_INT_B_IRQHandler                       /* Shared Int Source MU9_INT_B from LSIO Sub-System*/
    .long   LSIO_MU10_INT_B_IRQHandler                      /* Shared Int Source MU10_INT_B from LSIO Sub-System*/
    .long   LSIO_MU11_INT_B_IRQHandler                      /* Shared Int Source MU11_INT_B from LSIO Sub-System*/
    .long   LSIO_MU12_INT_B_IRQHandler                      /* Shared Int Source MU12_INT_B from LSIO Sub-System*/
    .long   LSIO_MU13_INT_B_IRQHandler                      /* Shared Int Source MU13_INT_B from LSIO Sub-System*/
    .long   Reserved208_IRQHandler                          /* xxx Interrupt 208*/
    .long   Reserved209_IRQHandler                          /* xxx Interrupt 209*/
    .long   Reserved210_IRQHandler                          /* xxx Interrupt 210*/
    .long   Reserved211_IRQHandler                          /* xxx Interrupt 211*/
    .long   Reserved212_IRQHandler                          /* xxx Interrupt 212*/
    .long   Reserved213_IRQHandler                          /* xxx Interrupt 213*/
    .long   Reserved214_IRQHandler                          /* xxx Interrupt 214*/
    .long   Reserved215_IRQHandler                          /* xxx Interrupt 215*/
    .long   Reserved216_IRQHandler                          /* xxx Interrupt 216*/
    .long   ADMA_SPI0_INT_IRQHandler                        /* Shared Int Source SPI0_INT from ADMA Sub-System*/
    .long   ADMA_SPI1_INT_IRQHandler                        /* Shared Int Source SPI1_INT from ADMA Sub-System*/
    .long   ADMA_SPI2_INT_IRQHandler                        /* Shared Int Source SPI2_INT from ADMA Sub-System*/
    .long   ADMA_SPI3_INT_IRQHandler                        /* Shared Int Source SPI3_INT from ADMA Sub-System*/
    .long   ADMA_I2C0_INT_IRQHandler                        /* Shared Int Source I2C0_INT from ADMA Sub-System*/
    .long   ADMA_I2C1_INT_IRQHandler                        /* Shared Int Source I2C1_INT from ADMA Sub-System*/
    .long   ADMA_I2C2_INT_IRQHandler                        /* Shared Int Source I2C2_INT from ADMA Sub-System*/
    .long   ADMA_I2C3_INT_IRQHandler                        /* Shared Int Source I2C3_INT from ADMA Sub-System*/
    .long   ADMA_UART0_INT_IRQHandler                       /* Shared Int Source UART0_INT from ADMA Sub-System*/
    .long   ADMA_UART1_INT_IRQHandler                       /* Shared Int Source UART1_INT from ADMA Sub-System*/
    .long   ADMA_UART2_INT_IRQHandler                       /* Shared Int Source UART2_INT from ADMA Sub-System*/
    .long   ADMA_UART3_INT_IRQHandler                       /* Shared Int Source UART3_INT from ADMA Sub-System*/
    .long   Reserved229_IRQHandler                          /* xxx Interrupt 229*/
    .long   Reserved230_IRQHandler                          /* xxx Interrupt 230*/
    .long   Reserved231_IRQHandler                          /* xxx Interrupt 231*/
    .long   Reserved232_IRQHandler                          /* xxx Interrupt 232*/
    .long   Reserved233_IRQHandler                          /* xxx Interrupt 233*/
    .long   Reserved234_IRQHandler                          /* xxx Interrupt 234*/
    .long   Reserved235_IRQHandler                          /* xxx Interrupt 235*/
    .long   Reserved236_IRQHandler                          /* xxx Interrupt 236*/
    .long   CONNECTIVITY_USDHC0_INT_IRQHandler              /* Shared Int Source uSDHC0_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_USDHC1_INT_IRQHandler              /* Shared Int Source uSDHC1_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_USDHC2_INT_IRQHandler              /* Shared Int Source uSDHC2_INT from Connectivity Sub-System*/
    .long   ADMA_FLEXCAN0_INT_IRQHandler                    /* Shared Int Source FlexCAN0_INT from ADMA Sub-System*/
    .long   ADMA_FLEXCAN1_INT_IRQHandler                    /* Shared Int Source FlexCAN1_INT from ADMA Sub-System*/
    .long   ADMA_FLEXCAN2_INT_IRQHandler                    /* Shared Int Source FlexCAN2_INT from ADMA Sub-System*/
    .long   ADMA_FTM0_INT_IRQHandler                        /* Shared Int Source FTM0_INT from ADMA Sub-System*/
    .long   ADMA_FTM1_INT_IRQHandler                        /* Shared Int Source FTM1_INT from ADMA Sub-System*/
    .long   ADMA_ADC0_INT_IRQHandler                        /* Shared Int Source ADC0_INT from ADMA Sub-System*/
    .long   Reserved246_IRQHandler                          /* xxx Interrupt 246*/
    .long   ADMA_EXTERNAL_DMA_INT_0_IRQHandler              /* Shared Int Source EXTERNAL_DMA_INT_0 from ADMA Sub-System*/
    .long   ADMA_EXTERNAL_DMA_INT_1_IRQHandler              /* Shared Int Source EXTERNAL_DMA_INT_1 from ADMA Sub-System*/
    .long   ADMA_EXTERNAL_DMA_INT_2_IRQHandler              /* Shared Int Source EXTERNAL_DMA_INT_2 from ADMA Sub-System*/
    .long   ADMA_EXTERNAL_DMA_INT_3_IRQHandler              /* Shared Int Source EXTERNAL_DMA_INT_3 from ADMA Sub-System*/
    .long   ADMA_EXTERNAL_DMA_INT_4_IRQHandler              /* Shared Int Source EXTERNAL_DMA_INT_4 from ADMA Sub-System*/
    .long   ADMA_EXTERNAL_DMA_INT_5_IRQHandler              /* Shared Int Source EXTERNAL_DMA_INT_5 from ADMA Sub-System*/
    .long   Reserved253_IRQHandler                          /* xxx Interrupt 253*/
    .long   Reserved254_IRQHandler                          /* xxx Interrupt 254*/
    .long   Reserved255_IRQHandler                          /* xxx Interrupt 255*/
    .long   Reserved256_IRQHandler                          /* xxx Interrupt 256*/
    .long   CONNECTIVITY_ENET0_FRAME1_INT_IRQHandler        /* Shared Int Source ENET0_FRAME1_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_ENET0_FRAME2_INT_IRQHandler        /* Shared Int Source ENET0_FRAME2_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_ENET0_FRAME0_EVENT_INT_IRQHandler  /* Shared Int Source ENET0_FRAME0_EVENT_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_ENET0_TIMER_INT_IRQHandler         /* Shared Int Source ENET0_TIMER_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_EQOS_INT_IRQHandler                /* Shared Int Source EQOS_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_EQOS_PMT_INT_IRQHandler            /* Shared Int Source EQOS_PMT_INT from Connectivity Sub-System*/
    .long   Reserved263_IRQHandler                          /* xxx Interrupt 263*/
    .long   Reserved264_IRQHandler                          /* xxx Interrupt 264*/
    .long   CONNECTIVITY_USB_OTG2_INT_IRQHandler            /* Shared Int Source USB2_OTG_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_UTM2_INT_IRQHandler                /* Shared Int Source UTM2_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_WAKEUP2_INT_IRQHandler             /* Shared Int Source WAKEUP2_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_USB_OTG1_INT_IRQHandler            /* Shared Int Source USB1_OTG_INT from Connectivity Sub-System*/
    .long   Reserved269_IRQHandler                          /* xxx Interrupt 269*/
    .long   CONNECTIVITY_UTM1_INT_IRQHandler                /* Shared Int Source UTM1_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_WAKEUP1_INT_IRQHandler             /* Shared Int Source WAKEUP1_INT from Connectivity Sub-System*/
    .long   Reserved272_IRQHandler                          /* xxx Interrupt 272*/
    .long   CONNECTIVITY_ND_FLASH_BCH_INT_IRQHandler        /* Shared Int Source ND_FLASH_BCH_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_ND_FLASH_GPMI_INT_IRQHandler       /* Shared Int Source ND_FLASH_GPMI_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_APBHDMA_IRQHandler                 /* Shared Int Source APBHDMA from Connectivity Sub-System*/
    .long   Reserved276_IRQHandler                          /* xxx Interrupt 276*/
    .long   CONNECTIVITY_ENET0_QUEUE0_INT_IRQHandler        /* Shared Int ENET0_QUEUE0_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_ENET0_QUEUE1_INT_IRQHandler        /* Shared Int ENET0_QUEUE1_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_ENET0_QUEUE2_INT_IRQHandler        /* Shared Int ENET0_QUEUE2_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_EQOS_DMA_CH0_INT_IRQHandler        /* Shared Int EQOS_DMA_CH0_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_EQOS_DMA_CH1_INT_IRQHandler        /* Shared Int EQOS_DMA_CH1_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_EQOS_DMA_CH2_INT_IRQHandler        /* Shared Int EQOS_DMA_CH2_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_EQOS_DMA_CH3_INT_IRQHandler        /* Shared Int EQOS_DMA_CH3_INT from Connectivity Sub-System*/
    .long   CONNECTIVITY_EQOS_DMA_CH4_INT_IRQHandler        /* Shared Int EQOS_DMA_CH4_INT from Connectivity Sub-System*/
    .long   Reserved285_IRQHandler                          /* xxx Interrupt 285*/
    .long   Reserved286_IRQHandler                          /* xxx Interrupt 286*/
    .long   ADMA_SAI0_MOD_INT_IRQHandler                    /* Shared Int Source SAI0_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SAI0_DMA_INT_IRQHandler                    /* Shared Int Source SAI0_DMA_INT from ADMA Sub-System*/
    .long   ADMA_SAI1_MOD_INT_IRQHandler                    /* Shared Int Source SAI1_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SAI1_DMA_INT_IRQHandler                    /* Shared Int Source SAI1_DMA_INT from ADMA Sub-System*/
    .long   ADMA_SAI2_MOD_INT_IRQHandler                    /* Shared Int Source SAI2_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SAI2_DMA_INT_IRQHandler                    /* Shared Int Source SAI2_DMA_INT from ADMA Sub-System*/
    .long   Reserved293_IRQHandler                          /* xxx Interrupt 293*/
    .long   Reserved294_IRQHandler                          /* xxx Interrupt 294*/
    .long   Reserved295_IRQHandler                          /* xxx Interrupt 295*/
    .long   Reserved296_IRQHandler                          /* xxx Interrupt 296*/
    .long   ADMA_SAI3_MOD_INT_IRQHandler                    /* Shared Int Source SAI3_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SAI3_DMA_INT_IRQHandler                    /* Shared Int Source SAI3_DMA_INT from ADMA Sub-System*/
    .long   Reserved299_IRQHandler                          /* xxx Interrupt 299*/
    .long   Reserved300_IRQHandler                          /* xxx Interrupt 300*/
    .long   Reserved301_IRQHandler                          /* xxx Interrupt 301*/
    .long   Reserved302_IRQHandler                          /* xxx Interrupt 302*/
    .long   Reserved303_IRQHandler                          /* xxx Interrupt 303*/
    .long   Reserved304_IRQHandler                          /* xxx Interrupt 304*/
    .long   Reserved305_IRQHandler                          /* xxx Interrupt 305*/
    .long   Reserved306_IRQHandler                          /* xxx Interrupt 306*/
    .long   Reserved307_IRQHandler                          /* xxx Interrupt 307*/
    .long   Reserved308_IRQHandler                          /* xxx Interrupt 308*/
    .long   Reserved309_IRQHandler                          /* xxx Interrupt 309*/
    .long   Reserved310_IRQHandler                          /* xxx Interrupt 310*/
    .long   Reserved311_IRQHandler                          /* xxx Interrupt 311*/
    .long   Reserved312_IRQHandler                          /* xxx Interrupt 312*/
    .long   Reserved313_IRQHandler                          /* xxx Interrupt 313*/
    .long   Reserved314_IRQHandler                          /* xxx Interrupt 314*/
    .long   Reserved315_IRQHandler                          /* xxx Interrupt 315*/
    .long   Reserved316_IRQHandler                          /* xxx Interrupt 316*/
    .long   ADMA_SPI0_MOD_INT_IRQHandler                    /* Shared Int Source SPI0_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SPI1_MOD_INT_IRQHandler                    /* Shared Int Source SPI1_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SPI2_MOD_INT_IRQHandler                    /* Shared Int Source SPI2_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SPI3_MOD_INT_IRQHandler                    /* Shared Int Source SPI3_MOD_INT from ADMA Sub-System*/
    .long   ADMA_I2C0_MOD_INT_IRQHandler                    /* Shared Int Source I2C0_MOD_INT from ADMA Sub-System*/
    .long   ADMA_I2C1_MOD_INT_IRQHandler                    /* Shared Int Source I2C1_MOD_INT from ADMA Sub-System*/
    .long   ADMA_I2C2_MOD_INT_IRQHandler                    /* Shared Int Source I2C2_MOD_INT from ADMA Sub-System*/
    .long   ADMA_I2C3_MOD_INT_IRQHandler                    /* Shared Int Source I2C3_MOD_INT from ADMA Sub-System*/
    .long   Reserved325_IRQHandler                          /* xxx Interrupt 325*/
    .long   Reserved326_IRQHandler                          /* xxx Interrupt 326*/
    .long   ADMA_UART0_MOD_INT_IRQHandler                   /* Shared Int Source UART0_MOD_INT from ADMA Sub-System*/
    .long   ADMA_UART1_MOD_INT_IRQHandler                   /* Shared Int Source UART1_MOD_INT from ADMA Sub-System*/
    .long   ADMA_UART2_MOD_INT_IRQHandler                   /* Shared Int Source UART2_MOD_INT from ADMA Sub-System*/
    .long   ADMA_UART3_MOD_INT_IRQHandler                   /* Shared Int Source UART3_MOD_INT from ADMA Sub-System*/
    .long   Reserved331_IRQHandler                          /* xxx Interrupt 331*/
    .long   Reserved332_IRQHandler                          /* xxx Interrupt 332*/
    .long   Reserved333_IRQHandler                          /* xxx Interrupt 333*/
    .long   Reserved334_IRQHandler                          /* xxx Interrupt 334*/
    .long   Reserved335_IRQHandler                          /* xxx Interrupt 335*/
    .long   Reserved336_IRQHandler                          /* xxx Interrupt 336*/
    .long   ADMA_FLEXCAN0_MOD_INT_IRQHandler                /* Shared Int Source FLEXCAN0_MOD_INT from ADMA Sub-System*/
    .long   ADMA_FLEXCAN1_MOD_INT_IRQHandler                /* Shared Int Source FLEXCAN1_MOD_INT from ADMA Sub-System*/
    .long   ADMA_FLEXCAN2_MOD_INT_IRQHandler                /* Shared Int Source FLEXCAN2_MOD_INT from ADMA Sub-System*/
    .long   ADMA_FTM0_MOD_INT_IRQHandler                    /* Shared Int Source FTM0_MOD_INT from ADMA Sub-System*/
    .long   ADMA_FTM1_MOD_INT_IRQHandler                    /* Shared Int Source FTM1_MOD_INT from ADMA Sub-System*/
    .long   ADMA_ADC0_MOD_INT_IRQHandler                    /* Shared Int Source ADC0_MOD_INT from ADMA Sub-System*/
    .long   Reserved343_IRQHandler                          /* xxx Interrupt 343*/
    .long   Reserved344_IRQHandler                          /* xxx Interrupt 344*/
    .long   Reserved345_IRQHandler                          /* xxx Interrupt 345*/
    .long   Reserved346_IRQHandler                          /* xxx Interrupt 346*/
    .long   ADMA_FLEXCAN0_DMA_INT_IRQHandler                /* Shared Int Source FLEXCAN0_DMA_INT from ADMA Sub-System*/
    .long   ADMA_FLEXCAN1_DMA_INT_IRQHandler                /* Shared Int Source FLEXCAN1_DMA_INT from ADMA Sub-System*/
    .long   ADMA_FLEXCAN2_DMA_INT_IRQHandler                /* Shared Int Source FLEXCAN2_DMA_INT from ADMA Sub-System*/
    .long   ADMA_FTM0_DMA_INT_IRQHandler                    /* Shared Int Source FTM0_DMA_INT from ADMA Sub-System*/
    .long   ADMA_FTM1_DMA_INT_IRQHandler                    /* Shared Int Source FTM1_DMA_INT from ADMA Sub-System*/
    .long   ADMA_ADC0_DMA_INT_IRQHandler                    /* Shared Int Source ADC0_DMA_INT from ADMA Sub-System*/
    .long   Reserved353_IRQHandler                          /* xxx Interrupt 353*/
    .long   Reserved354_IRQHandler                          /* xxx Interrupt 354*/
    .long   Reserved355_IRQHandler                          /* xxx Interrupt 355*/
    .long   Reserved356_IRQHandler                          /* xxx Interrupt 356*/
    .long   ADMA_EDMA0_INT_IRQHandler                       /* Shared Int Source eDMA0_INT from ADMA Sub-System*/
    .long   ADMA_EDMA0_ERR_INT_IRQHandler                   /* Shared Int Source eDMA0_ERR_INT from ADMA Sub-System*/
    .long   ADMA_ASRC0_INT1_IRQHandler                      /* Shared Int Source ASRC0_INT1 from ADMA Sub-System*/
    .long   ADMA_ASRC0_INT2_IRQHandler                      /* Shared Int Source ASRC0_INT2 from ADMA Sub-System*/
    .long   ADMA_DMA0_CH0_INT_IRQHandler                    /* Shared Int Source DMA0_CH0_INT from ADMA Sub-System*/
    .long   ADMA_DMA0_CH1_INT_IRQHandler                    /* Shared Int Source DMA0_CH1_INT from ADMA Sub-System*/
    .long   ADMA_DMA0_CH2_INT_IRQHandler                    /* Shared Int Source DMA0_CH2_INT from ADMA Sub-System*/
    .long   ADMA_DMA0_CH3_INT_IRQHandler                    /* Shared Int Source DMA0_CH3_INT from ADMA Sub-System*/
    .long   ADMA_DMA0_CH4_INT_IRQHandler                    /* Shared Int Source DMA0_CH4_INT from ADMA Sub-System*/
    .long   ADMA_DMA0_CH5_INT_IRQHandler                    /* Shared Int Source DMA0_CH5_INT from ADMA Sub-System*/
    .long   ADMA_GPT0_INT_IRQHandler                        /* Shared Int Source GPT0_INT from ADMA Sub-System*/
    .long   ADMA_GPT1_INT_IRQHandler                        /* Shared Int Source GPT1_INT from ADMA Sub-System*/
    .long   ADMA_GPT2_INT_IRQHandler                        /* Shared Int Source GPT2_INT from ADMA Sub-System*/
    .long   ADMA_GPT3_INT_IRQHandler                        /* Shared Int Source GPT3_INT from ADMA Sub-System*/
    .long   Reserved371_IRQHandler                          /* xxx Interrupt 371*/
    .long   Reserved372_IRQHandler                          /* xxx Interrupt 372*/
    .long   ADMA_SAI0_INT_IRQHandler                        /* Shared Int Source SAI0_INT from ADMA Sub-System*/
    .long   ADMA_SAI1_INT_IRQHandler                        /* Shared Int Source SAI1_INT from ADMA Sub-System*/
    .long   ADMA_SAI2_INT_IRQHandler                        /* Shared Int Source SAI2_INT from ADMA Sub-System*/
    .long   ADMA_SAI3_INT_IRQHandler                        /* Shared Int Source SAI3_INT from ADMA Sub-System*/
    .long   ADMA_SPDIF0_RX_INT_IRQHandler                   /* Shared Int Source SPDIF0_RX_INT from ADMA Sub-System*/
    .long   ADMA_SPDIF0_TX_INT_IRQHandler                   /* Shared Int Source SPDIF0_TX_INT from ADMA Sub-System*/
    .long   Reserved379_IRQHandler                          /* xxx Interrupt 379*/
    .long   Reserved380_IRQHandler                          /* xxx Interrupt 380*/
    .long   Reserved381_IRQHandler                          /* xxx Interrupt 381*/
    .long   Reserved382_IRQHandler                          /* xxx Interrupt 382*/
    .long   Reserved383_IRQHandler                          /* xxx Interrupt 383*/
    .long   Reserved384_IRQHandler                          /* xxx Interrupt 384*/
    .long   Reserved385_IRQHandler                          /* xxx Interrupt 385*/
    .long   Reserved386_IRQHandler                          /* xxx Interrupt 386*/
    .long   ADMA_SPI0_DMA_RX_INT_IRQHandler                 /* Shared Int Source SPI0_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_SPI0_DMA_TX_INT_IRQHandler                 /* Shared Int Source SPI0_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_SPI1_DMA_RX_INT_IRQHandler                 /* Shared Int Source SPI1_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_SPI1_DMA_TX_INT_IRQHandler                 /* Shared Int Source SPI1_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_SPI2_DMA_RX_INT_IRQHandler                 /* Shared Int Source SPI2_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_SPI2_DMA_TX_INT_IRQHandler                 /* Shared Int Source SPI2_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_SPI3_DMA_RX_INT_IRQHandler                 /* Shared Int Source SPI3_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_SPI3_DMA_TX_INT_IRQHandler                 /* Shared Int Source SPI3_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_I2C0_DMA_RX_INT_IRQHandler                 /* Shared Int Source I2C0_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_I2C0_DMA_TX_INT_IRQHandler                 /* Shared Int Source I2C0_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_I2C1_DMA_RX_INT_IRQHandler                 /* Shared Int Source I2C1_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_I2C1_DMA_TX_INT_IRQHandler                 /* Shared Int Source I2C1_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_I2C2_DMA_RX_INT_IRQHandler                 /* Shared Int Source I2C2_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_I2C2_DMA_TX_INT_IRQHandler                 /* Shared Int Source I2C2_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_I2C3_DMA_RX_INT_IRQHandler                 /* Shared Int Source I2C3_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_I2C3_DMA_TX_INT_IRQHandler                 /* Shared Int Source I2C3_DMA_TX_INT from ADMA Sub-System*/
    .long   Reserved403_IRQHandler                          /* xxx Interrupt 403*/
    .long   Reserved404_IRQHandler                          /* xxx Interrupt 404*/
    .long   Reserved405_IRQHandler                          /* xxx Interrupt 405*/
    .long   Reserved406_IRQHandler                          /* xxx Interrupt 406*/
    .long   ADMA_UART0_DMA_RX_INT_IRQHandler                /* Shared Int Source UART0_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_UART0_DMA_TX_INT_IRQHandler                /* Shared Int Source UART0_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_UART1_DMA_RX_INT_IRQHandler                /* Shared Int Source UART1_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_UART1_DMA_TX_INT_IRQHandler                /* Shared Int Source UART1_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_UART2_DMA_RX_INT_IRQHandler                /* Shared Int Source UART2_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_UART2_DMA_TX_INT_IRQHandler                /* Shared Int Source UART2_DMA_TX_INT from ADMA Sub-System*/
    .long   ADMA_UART3_DMA_RX_INT_IRQHandler                /* Shared Int Source UART3_DMA_RX_INT from ADMA Sub-System*/
    .long   ADMA_UART3_DMA_TX_INT_IRQHandler                /* Shared Int Source UART3_DMA_TX_INT from ADMA Sub-System*/
    .long   Reserved415_IRQHandler                          /* xxx Interrupt 415*/
    .long   Reserved416_IRQHandler                          /* xxx Interrupt 416*/
    .long   SECURITY_MU1_A_INT_IRQHandler                   /* Shared Int Source MU1_A_INT from Security Sub-System*/
    .long   SECURITY_MU2_A_INT_IRQHandler                   /* Shared Int Source MU2_A_INT from Security Sub-System*/
    .long   SECURITY_MU3_A_INT_IRQHandler                   /* Shared Int Source MU3_A_INT from Security Sub-System*/
    .long   SECURITY_CAAM_INT0_IRQHandler                   /* Shared Int Source CAAM_INT0 from Security Sub-System*/
    .long   SECURITY_CAAM_INT1_IRQHandler                   /* Shared Int Source CAAM_INT1 from Security Sub-System*/
    .long   SECURITY_CAAM_INT2_IRQHandler                   /* Shared Int Source CAAM_INT2 from Security Sub-System*/
    .long   SECURITY_CAAM_INT3_IRQHandler                   /* Shared Int Source CAAM_INT3 from Security Sub-System*/
    .long   SECURITY_CAAM_RTIC_INT_IRQHandler               /* Shared Int Source CAAM_RTIC_INT from Security Sub-System*/
    .long   ADMA_SPDIF0_RX_MOD_INT_IRQHandler               /* Shared Int Source SPDIF0_RX_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SPDIF0_RX_DMA_INT_IRQHandler               /* Shared Int Source SPDIF0_RX_DMA_INT from ADMA Sub-System*/
    .long   ADMA_SPDIF0_TX_MOD_INT_IRQHandler               /* Shared Int Source SPDIF0_TX_MOD_INT from ADMA Sub-System*/
    .long   ADMA_SPDIF0_TX_DMA_INT_IRQHandler               /* Shared Int Source SPDIF0_TX_DMA_INT from ADMA Sub-System*/
    .long   Reserved429_IRQHandler                          /* xxx Interrupt 429*/
    .long   Reserved430_IRQHandler                          /* xxx Interrupt 430*/
    .long   Reserved431_IRQHandler                          /* xxx Interrupt 431*/
    .long   Reserved432_IRQHandler                          /* xxx Interrupt 432*/
    .long   Reserved433_IRQHandler                          /* xxx Interrupt 433*/
    .long   Reserved434_IRQHandler                          /* xxx Interrupt 434*/
    .long   Reserved435_IRQHandler                          /* xxx Interrupt 435*/
    .long   Reserved436_IRQHandler                          /* xxx Interrupt 436*/
    .long   DB_PERF_CNT_FULL_IRQHandler                     /* Shared Int Source DB_PERF_CNT_FULL from DB Sub-System*/
    .long   V2X_AP_INT0_IRQHandler                          /* Shared Int Source V2X_AP_INT0 from DB Sub-System*/
    .long   V2X_AP_INT1_IRQHandler                          /* Shared Int Source V2X_AP_INT1 from DB Sub-System*/
    .long   V2X_AP_INT2_IRQHandler                          /* Shared Int Source V2X_AP_INT2 from DB Sub-System*/
    .long   V2X_AP_INT3_IRQHandler                          /* Shared Int Source V2X_AP_INT3 from DB Sub-System*/
    .long   V2X_AP_INT4_IRQHandler                          /* Shared Int Source V2X_AP_INT4 from DB Sub-System*/
    .long   V2X_AP_INT5_IRQHandler                          /* Shared Int Source V2X_AP_INT5 from DB Sub-System*/
    .long   V2X_AP_INT6_IRQHandler                          /* Shared Int Source V2X_AP_INT6 from DB Sub-System*/
    .long   V2X_AP_INT7_IRQHandler                          /* Shared Int Source V2X_AP_INT7 from DB Sub-System*/
    .long   V2X_AP_INT8_IRQHandler                          /* Shared Int Source V2X_AP_INT8 from DB Sub-System*/
    .long   V2X_AP_INT9_IRQHandler                          /* Shared Int Source V2X_AP_INT9 from DB Sub-System*/
    .long   V2X_AP_INT10_IRQHandler                         /* Shared Int Source V2X_AP_INT10 from DB Sub-System*/
    .long   V2X_AP_INT11_IRQHandler                         /* Shared Int Source V2X_AP_INT11 from DB Sub-System*/
    .long   Reserved450_IRQHandler                          /* xxx Interrupt 450*/
    .long   Reserved451_IRQHandler                          /* xxx Interrupt 451*/
    .long   Reserved452_IRQHandler                          /* xxx Interrupt 452*/
    .long   Reserved453_IRQHandler                          /* xxx Interrupt 453*/
    .long   Reserved454_IRQHandler                          /* xxx Interrupt 454*/
    .long   Reserved455_IRQHandler                          /* xxx Interrupt 455*/
    .long   Reserved456_IRQHandler                          /* xxx Interrupt 456*/
    .long   Reserved457_IRQHandler                          /* xxx Interrupt 457*/
    .long   Reserved458_IRQHandler                          /* xxx Interrupt 458*/
    .long   Reserved459_IRQHandler                          /* xxx Interrupt 459*/
    .long   Reserved460_IRQHandler                          /* xxx Interrupt 460*/
    .long   Reserved461_IRQHandler                          /* xxx Interrupt 461*/
    .long   M4_INTMUX_SOURCE_TPM_IRQHandler                 /* INTMUX Input source: TPM Interrupt*/
    .long   Reserved463_IRQHandler                          /* xxx Interrupt 463*/
    .long   Reserved464_IRQHandler                          /* xxx Interrupt 464*/
    .long   M4_INTMUX_SOURCE_LPIT_IRQHandler                /* INTMUX Input source: LPIT Interrupt*/
    .long   Reserved466_IRQHandler                          /* xxx Interrupt 466*/
    .long   Reserved467_IRQHandler                          /* xxx Interrupt 467*/
    .long   M4_INTMUX_SOURCE_LPUART_IRQHandler              /* INTMUX Input source: LPUART Interrupt*/
    .long   Reserved469_IRQHandler                          /* xxx Interrupt 469*/
    .long   M4_INTMUX_SOURCE_LPI2C_IRQHandler               /* INTMUX Input source: LPI2C Interrupt*/
    .long   Reserved471_IRQHandler                          /* xxx Interrupt 471*/
    .long   Reserved472_IRQHandler                          /* xxx Interrupt 472*/
    .long   Reserved473_IRQHandler                          /* xxx Interrupt 473*/
    .long   Reserved474_IRQHandler                          /* xxx Interrupt 474*/
    .long   Reserved475_IRQHandler                          /* xxx Interrupt 475*/
    .long   Reserved476_IRQHandler                          /* xxx Interrupt 476*/
    .long   Reserved477_IRQHandler                          /* xxx Interrupt 477*/
    .long   Reserved478_IRQHandler                          /* xxx Interrupt 478*/
    .long   Reserved479_IRQHandler                          /* xxx Interrupt 479*/
    .long   Reserved480_IRQHandler                          /* xxx Interrupt 480*/
    .long   Reserved481_IRQHandler                          /* xxx Interrupt 481*/
    .long   Reserved482_IRQHandler                          /* xxx Interrupt 482*/
    .long   Reserved483_IRQHandler                          /* xxx Interrupt 483*/
    .long   Reserved484_IRQHandler                          /* xxx Interrupt 484*/
    .long   Reserved485_IRQHandler                          /* xxx Interrupt 485*/
    .long   Reserved486_IRQHandler                          /* xxx Interrupt 486*/
    .long   Reserved487_IRQHandler                          /* xxx Interrupt 487*/
    .long   Reserved488_IRQHandler                          /* xxx Interrupt 488*/
    .long   M4_INTMUX_SOURCE_MU0_A3_IRQHandler              /* INTMUX Input source: MU0_A3 Interrupt*/
    .long   M4_INTMUX_SOURCE_MU0_A2_IRQHandler              /* INTMUX Input source: MU0_A2 Interrupt*/
    .long   M4_INTMUX_SOURCE_MU0_A1_IRQHandler              /* INTMUX Input source: MU0_A1 Interrupt*/
    .long   M4_INTMUX_SOURCE_MU0_A0_IRQHandler              /* INTMUX Input source: MU0_A0 Interrupt*/

    .size    __isr_vector, . - __isr_vector

    .text
    .thumb

/* Reset Handler */

    .thumb_func
    .align 2
    .globl   Reset_Handler
    .weak    Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:
#ifdef __STARTUP_CONFIG_DDR_ALIAS
    .equ    _MCM_PID, 0xE0080030
    ldr     r0, =_MCM_PID
    movs    r1, 0x7E
    str     r1, [r0]
    isb
    ldr     r0,=alias_start
    mov     pc,r0
alias_start:
#endif
    cpsid   i               /* Mask interrupts */
    .equ    VTOR, 0xE000ED08
    ldr     r0, =VTOR
    ldr     r1, =__isr_vector
    str     r1, [r0]
    ldr     r2, [r1]
    msr     msp, r2
#ifndef __NO_SYSTEM_INIT
    ldr   r0,=SystemInit
    blx   r0
#endif
/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      __etext: End of code section, i.e., begin of data sections to copy from.
 *      __data_start__/__data_end__: RAM address range that data should be
 *      __noncachedata_start__/__noncachedata_end__ : none cachable region
 *      copied to. Both must be aligned to 4 bytes boundary.  */

    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

#if 1
/* Here are two copies of loop implemenations. First one favors code size
 * and the second one favors performance. Default uses the first one.
 * Change to "#if 0" to use the second one */
.LC0:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC0
#else
    subs    r3, r2
    ble    .LC1
.LC0:
    subs    r3, #4
    ldr    r0, [r1, r3]
    str    r0, [r2, r3]
    bgt    .LC0
.LC1:
#endif

/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      __quickaccess_start__/__quickaccess_end__: RAM address range that data should be
 *      copied to. Both must be aligned to 4 bytes boundary.  */
#if defined(FSL_SDK_DRIVER_QUICK_ACCESS_ENABLE) && FSL_SDK_DRIVER_QUICK_ACCESS_ENABLE
    ldr    r2, = __quickaccess_start__
    ldr    r3, = __quickaccess_end__
#if 1
.LC2:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC2
#else
    subs    r3, r2
    ble    .LC3
.LC2:
    subs    r3, #4
    ldr     r0, [r1, r3]
    str     r0, [r2, r3]
    bgt    .LC2
.LC3:
#endif
#endif /* FSL_SDK_DRIVER_QUICK_ACCESS_ENABLE */

/*      __resume_mem_start__/__resume_mem_end__: DDR address range that data should be
 *      retained during LPM. Both must be aligned to 4 bytes boundary.  */
#ifdef __STARTUP_INITIALIZE_RESUMEMEM
    ldr    r1, = __RDATA_ROM
    ldr    r2, = __resume_mem_start__
    ldr    r3, = __resume_mem_end__
#if 1
.LC4:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC4
#else
    subs    r3, r2
    ble    .LC5
.LC4:
    subs    r3, #4
    ldr     r0, [r1, r3]
    str     r0, [r2, r3]
    bgt    .LC4
.LC5:
#endif
#endif /* __STARTUP_INITIALIZE_RESUMEMEM */

#ifdef __STARTUP_INITIALIZE_NONCACHEDATA
    ldr    r1, =__NDATA_ROM
    ldr    r2, =__noncachedata_start__
    ldr    r3, =__noncachedata_init_end__
#if 1
.LC6:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC6
#else
    subs    r3, r2
    ble    .LC7
.LC6:
    subs    r3, #4
    ldr     r0, [r1, r3]
    str     r0, [r2, r3]
    bgt    .LC6
.LC7:
#endif
/* Add ncache section initializaiton */
    ldr r3, =__noncachedata_end__
    movs    r0, 0
.LC8:
    cmp     r2, r3
    itt    lt
    strlt   r0, [r2], #4
    blt    .LC8
#endif /* __STARTUP_INITIALIZE_NONCACHEDATA */

#ifdef __STARTUP_CLEAR_BSS
/*     This part of work usually is done in C library startup code. Otherwise,
 *     define this macro to enable it in this startup.
 *
 *     Loop to zero out BSS section, which uses following symbols
 *     in linker script:
 *      __bss_start__: start of BSS section. Must align to 4
 *      __bss_end__: end of BSS section. Must align to 4
 */
    ldr r1, =__bss_start__
    ldr r2, =__bss_end__

    movs    r0, 0
.LC9:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .LC9
#endif /* __STARTUP_CLEAR_BSS */

/* Add stack / heap initializaiton */
    movs    r0, 0
    ldr     r1, =__HeapBase
    ldr     r2, =__HeapLimit
.LC10:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .LC10

    ldr     r1, =__StackLimit
    ldr     r2, =__StackTop
.LC11:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .LC11

/*End of stack / heap initializaiton */
    cpsie   i               /* Unmask interrupts */
#ifndef __START
#define __START _start
#endif
#ifndef __ATOLLIC__
    ldr   r0,=__START
    blx   r0
#else
    ldr   r0,=__libc_init_array
    blx   r0
    ldr   r0,=main
    bx    r0
#endif
    .pool
    .size Reset_Handler, . - Reset_Handler

    .align  1
    .thumb_func
    .weak DefaultISR
    .type DefaultISR, %function
DefaultISR:
    b DefaultISR
    .size DefaultISR, . - DefaultISR

    .align 1
    .thumb_func
    .weak NMI_Handler
    .type NMI_Handler, %function
NMI_Handler:
    ldr   r0,=NMI_Handler
    bx    r0
    .size NMI_Handler, . - NMI_Handler

    .align 1
    .thumb_func
    .weak HardFault_Handler
    .type HardFault_Handler, %function
HardFault_Handler:
    ldr   r0,=HardFault_Handler
    bx    r0
    .size HardFault_Handler, . - HardFault_Handler

    .align 1
    .thumb_func
    .weak SVC_Handler
    .type SVC_Handler, %function
SVC_Handler:
    ldr   r0,=SVC_Handler
    bx    r0
    .size SVC_Handler, . - SVC_Handler

    .align 1
    .thumb_func
    .weak PendSV_Handler
    .type PendSV_Handler, %function
PendSV_Handler:
    ldr   r0,=PendSV_Handler
    bx    r0
    .size PendSV_Handler, . - PendSV_Handler

    .align 1
    .thumb_func
    .weak SysTick_Handler
    .type SysTick_Handler, %function
SysTick_Handler:
    ldr   r0,=SysTick_Handler
    bx    r0
    .size SysTick_Handler, . - SysTick_Handler

    .align 1
    .thumb_func
    .weak M4_LPUART_IRQHandler
    .type M4_LPUART_IRQHandler, %function
M4_LPUART_IRQHandler:
    ldr   r0,=M4_LPUART_DriverIRQHandler
    bx    r0
    .size M4_LPUART_IRQHandler, . - M4_LPUART_IRQHandler

    .align 1
    .thumb_func
    .weak M4_LPI2C_IRQHandler
    .type M4_LPI2C_IRQHandler, %function
M4_LPI2C_IRQHandler:
    ldr   r0,=M4_LPI2C_DriverIRQHandler
    bx    r0
    .size M4_LPI2C_IRQHandler, . - M4_LPI2C_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEER_0_IRQHandler
    .type IRQSTEER_0_IRQHandler, %function
IRQSTEER_0_IRQHandler:
    ldr   r0,=IRQSTEER_0_DriverIRQHandler
    bx    r0
    .size IRQSTEER_0_IRQHandler, . - IRQSTEER_0_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEER_1_IRQHandler
    .type IRQSTEER_1_IRQHandler, %function
IRQSTEER_1_IRQHandler:
    ldr   r0,=IRQSTEER_1_DriverIRQHandler
    bx    r0
    .size IRQSTEER_1_IRQHandler, . - IRQSTEER_1_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEER_2_IRQHandler
    .type IRQSTEER_2_IRQHandler, %function
IRQSTEER_2_IRQHandler:
    ldr   r0,=IRQSTEER_2_DriverIRQHandler
    bx    r0
    .size IRQSTEER_2_IRQHandler, . - IRQSTEER_2_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEER_3_IRQHandler
    .type IRQSTEER_3_IRQHandler, %function
IRQSTEER_3_IRQHandler:
    ldr   r0,=IRQSTEER_3_DriverIRQHandler
    bx    r0
    .size IRQSTEER_3_IRQHandler, . - IRQSTEER_3_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEER_4_IRQHandler
    .type IRQSTEER_4_IRQHandler, %function
IRQSTEER_4_IRQHandler:
    ldr   r0,=IRQSTEER_4_DriverIRQHandler
    bx    r0
    .size IRQSTEER_4_IRQHandler, . - IRQSTEER_4_IRQHandler

    .align 1
    .thumb_func
    .weak IRQSTEER_5_IRQHandler
    .type IRQSTEER_5_IRQHandler, %function
IRQSTEER_5_IRQHandler:
    ldr   r0,=IRQSTEER_5_DriverIRQHandler
    bx    r0
    .size IRQSTEER_5_IRQHandler, . - IRQSTEER_5_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EDMA2_INT_IRQHandler
    .type ADMA_EDMA2_INT_IRQHandler, %function
ADMA_EDMA2_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EDMA2_INT_IRQHandler, . - ADMA_EDMA2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EDMA2_ERR_INT_IRQHandler
    .type ADMA_EDMA2_ERR_INT_IRQHandler, %function
ADMA_EDMA2_ERR_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EDMA2_ERR_INT_IRQHandler, . - ADMA_EDMA2_ERR_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EDMA3_INT_IRQHandler
    .type ADMA_EDMA3_INT_IRQHandler, %function
ADMA_EDMA3_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EDMA3_INT_IRQHandler, . - ADMA_EDMA3_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EDMA3_ERR_INT_IRQHandler
    .type ADMA_EDMA3_ERR_INT_IRQHandler, %function
ADMA_EDMA3_ERR_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EDMA3_ERR_INT_IRQHandler, . - ADMA_EDMA3_ERR_INT_IRQHandler

    .align 1
    .thumb_func
    .weak LSIO_OCTASPI0_INT_IRQHandler
    .type LSIO_OCTASPI0_INT_IRQHandler, %function
LSIO_OCTASPI0_INT_IRQHandler:
    ldr   r0,=LSIO_OCTASPI0_INT_DriverIRQHandler
    bx    r0
    .size LSIO_OCTASPI0_INT_IRQHandler, . - LSIO_OCTASPI0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak LSIO_OCTASPI1_INT_IRQHandler
    .type LSIO_OCTASPI1_INT_IRQHandler, %function
LSIO_OCTASPI1_INT_IRQHandler:
    ldr   r0,=LSIO_OCTASPI1_INT_DriverIRQHandler
    bx    r0
    .size LSIO_OCTASPI1_INT_IRQHandler, . - LSIO_OCTASPI1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak HSIO_PCIEB_DMA_INT_IRQHandler
    .type HSIO_PCIEB_DMA_INT_IRQHandler, %function
HSIO_PCIEB_DMA_INT_IRQHandler:
    ldr   r0,=HSIO_PCIEB_DMA_INT_DriverIRQHandler
    bx    r0
    .size HSIO_PCIEB_DMA_INT_IRQHandler, . - HSIO_PCIEB_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI0_INT_IRQHandler
    .type ADMA_SPI0_INT_IRQHandler, %function
ADMA_SPI0_INT_IRQHandler:
    ldr   r0,=ADMA_SPI0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI0_INT_IRQHandler, . - ADMA_SPI0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI1_INT_IRQHandler
    .type ADMA_SPI1_INT_IRQHandler, %function
ADMA_SPI1_INT_IRQHandler:
    ldr   r0,=ADMA_SPI1_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI1_INT_IRQHandler, . - ADMA_SPI1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI2_INT_IRQHandler
    .type ADMA_SPI2_INT_IRQHandler, %function
ADMA_SPI2_INT_IRQHandler:
    ldr   r0,=ADMA_SPI2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI2_INT_IRQHandler, . - ADMA_SPI2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI3_INT_IRQHandler
    .type ADMA_SPI3_INT_IRQHandler, %function
ADMA_SPI3_INT_IRQHandler:
    ldr   r0,=ADMA_SPI3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI3_INT_IRQHandler, . - ADMA_SPI3_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C0_INT_IRQHandler
    .type ADMA_I2C0_INT_IRQHandler, %function
ADMA_I2C0_INT_IRQHandler:
    ldr   r0,=ADMA_I2C0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C0_INT_IRQHandler, . - ADMA_I2C0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C1_INT_IRQHandler
    .type ADMA_I2C1_INT_IRQHandler, %function
ADMA_I2C1_INT_IRQHandler:
    ldr   r0,=ADMA_I2C1_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C1_INT_IRQHandler, . - ADMA_I2C1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C2_INT_IRQHandler
    .type ADMA_I2C2_INT_IRQHandler, %function
ADMA_I2C2_INT_IRQHandler:
    ldr   r0,=ADMA_I2C2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C2_INT_IRQHandler, . - ADMA_I2C2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C3_INT_IRQHandler
    .type ADMA_I2C3_INT_IRQHandler, %function
ADMA_I2C3_INT_IRQHandler:
    ldr   r0,=ADMA_I2C3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C3_INT_IRQHandler, . - ADMA_I2C3_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART0_INT_IRQHandler
    .type ADMA_UART0_INT_IRQHandler, %function
ADMA_UART0_INT_IRQHandler:
    ldr   r0,=ADMA_UART0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART0_INT_IRQHandler, . - ADMA_UART0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART1_INT_IRQHandler
    .type ADMA_UART1_INT_IRQHandler, %function
ADMA_UART1_INT_IRQHandler:
    ldr   r0,=ADMA_UART1_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART1_INT_IRQHandler, . - ADMA_UART1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART2_INT_IRQHandler
    .type ADMA_UART2_INT_IRQHandler, %function
ADMA_UART2_INT_IRQHandler:
    ldr   r0,=ADMA_UART2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART2_INT_IRQHandler, . - ADMA_UART2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART3_INT_IRQHandler
    .type ADMA_UART3_INT_IRQHandler, %function
ADMA_UART3_INT_IRQHandler:
    ldr   r0,=ADMA_UART3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART3_INT_IRQHandler, . - ADMA_UART3_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_USDHC0_INT_IRQHandler
    .type CONNECTIVITY_USDHC0_INT_IRQHandler, %function
CONNECTIVITY_USDHC0_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_USDHC0_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_USDHC0_INT_IRQHandler, . - CONNECTIVITY_USDHC0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_USDHC1_INT_IRQHandler
    .type CONNECTIVITY_USDHC1_INT_IRQHandler, %function
CONNECTIVITY_USDHC1_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_USDHC1_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_USDHC1_INT_IRQHandler, . - CONNECTIVITY_USDHC1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_USDHC2_INT_IRQHandler
    .type CONNECTIVITY_USDHC2_INT_IRQHandler, %function
CONNECTIVITY_USDHC2_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_USDHC2_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_USDHC2_INT_IRQHandler, . - CONNECTIVITY_USDHC2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN0_INT_IRQHandler
    .type ADMA_FLEXCAN0_INT_IRQHandler, %function
ADMA_FLEXCAN0_INT_IRQHandler:
    ldr   r0,=ADMA_FLEXCAN0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN0_INT_IRQHandler, . - ADMA_FLEXCAN0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN1_INT_IRQHandler
    .type ADMA_FLEXCAN1_INT_IRQHandler, %function
ADMA_FLEXCAN1_INT_IRQHandler:
    ldr   r0,=ADMA_FLEXCAN1_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN1_INT_IRQHandler, . - ADMA_FLEXCAN1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN2_INT_IRQHandler
    .type ADMA_FLEXCAN2_INT_IRQHandler, %function
ADMA_FLEXCAN2_INT_IRQHandler:
    ldr   r0,=ADMA_FLEXCAN2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN2_INT_IRQHandler, . - ADMA_FLEXCAN2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FTM0_INT_IRQHandler
    .type ADMA_FTM0_INT_IRQHandler, %function
ADMA_FTM0_INT_IRQHandler:
    ldr   r0,=ADMA_FTM0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FTM0_INT_IRQHandler, . - ADMA_FTM0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FTM1_INT_IRQHandler
    .type ADMA_FTM1_INT_IRQHandler, %function
ADMA_FTM1_INT_IRQHandler:
    ldr   r0,=ADMA_FTM1_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FTM1_INT_IRQHandler, . - ADMA_FTM1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_ADC0_INT_IRQHandler
    .type ADMA_ADC0_INT_IRQHandler, %function
ADMA_ADC0_INT_IRQHandler:
    ldr   r0,=ADMA_ADC0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_ADC0_INT_IRQHandler, . - ADMA_ADC0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EXTERNAL_DMA_INT_0_IRQHandler
    .type ADMA_EXTERNAL_DMA_INT_0_IRQHandler, %function
ADMA_EXTERNAL_DMA_INT_0_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EXTERNAL_DMA_INT_0_IRQHandler, . - ADMA_EXTERNAL_DMA_INT_0_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EXTERNAL_DMA_INT_1_IRQHandler
    .type ADMA_EXTERNAL_DMA_INT_1_IRQHandler, %function
ADMA_EXTERNAL_DMA_INT_1_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EXTERNAL_DMA_INT_1_IRQHandler, . - ADMA_EXTERNAL_DMA_INT_1_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EXTERNAL_DMA_INT_2_IRQHandler
    .type ADMA_EXTERNAL_DMA_INT_2_IRQHandler, %function
ADMA_EXTERNAL_DMA_INT_2_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EXTERNAL_DMA_INT_2_IRQHandler, . - ADMA_EXTERNAL_DMA_INT_2_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EXTERNAL_DMA_INT_3_IRQHandler
    .type ADMA_EXTERNAL_DMA_INT_3_IRQHandler, %function
ADMA_EXTERNAL_DMA_INT_3_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EXTERNAL_DMA_INT_3_IRQHandler, . - ADMA_EXTERNAL_DMA_INT_3_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EXTERNAL_DMA_INT_4_IRQHandler
    .type ADMA_EXTERNAL_DMA_INT_4_IRQHandler, %function
ADMA_EXTERNAL_DMA_INT_4_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EXTERNAL_DMA_INT_4_IRQHandler, . - ADMA_EXTERNAL_DMA_INT_4_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EXTERNAL_DMA_INT_5_IRQHandler
    .type ADMA_EXTERNAL_DMA_INT_5_IRQHandler, %function
ADMA_EXTERNAL_DMA_INT_5_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EXTERNAL_DMA_INT_5_IRQHandler, . - ADMA_EXTERNAL_DMA_INT_5_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_ENET0_FRAME1_INT_IRQHandler
    .type CONNECTIVITY_ENET0_FRAME1_INT_IRQHandler, %function
CONNECTIVITY_ENET0_FRAME1_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_ENET0_FRAME1_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_ENET0_FRAME1_INT_IRQHandler, . - CONNECTIVITY_ENET0_FRAME1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_ENET0_FRAME2_INT_IRQHandler
    .type CONNECTIVITY_ENET0_FRAME2_INT_IRQHandler, %function
CONNECTIVITY_ENET0_FRAME2_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_ENET0_FRAME2_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_ENET0_FRAME2_INT_IRQHandler, . - CONNECTIVITY_ENET0_FRAME2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_ENET0_FRAME0_EVENT_INT_IRQHandler
    .type CONNECTIVITY_ENET0_FRAME0_EVENT_INT_IRQHandler, %function
CONNECTIVITY_ENET0_FRAME0_EVENT_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_ENET0_FRAME0_EVENT_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_ENET0_FRAME0_EVENT_INT_IRQHandler, . - CONNECTIVITY_ENET0_FRAME0_EVENT_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_ENET0_TIMER_INT_IRQHandler
    .type CONNECTIVITY_ENET0_TIMER_INT_IRQHandler, %function
CONNECTIVITY_ENET0_TIMER_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_ENET0_TIMER_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_ENET0_TIMER_INT_IRQHandler, . - CONNECTIVITY_ENET0_TIMER_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_EQOS_INT_IRQHandler
    .type CONNECTIVITY_EQOS_INT_IRQHandler, %function
CONNECTIVITY_EQOS_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_EQOS_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_EQOS_INT_IRQHandler, . - CONNECTIVITY_EQOS_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_EQOS_PMT_INT_IRQHandler
    .type CONNECTIVITY_EQOS_PMT_INT_IRQHandler, %function
CONNECTIVITY_EQOS_PMT_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_EQOS_PMT_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_EQOS_PMT_INT_IRQHandler, . - CONNECTIVITY_EQOS_PMT_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_APBHDMA_IRQHandler
    .type CONNECTIVITY_APBHDMA_IRQHandler, %function
CONNECTIVITY_APBHDMA_IRQHandler:
    ldr   r0,=CONNECTIVITY_APBHDMA_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_APBHDMA_IRQHandler, . - CONNECTIVITY_APBHDMA_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_ENET0_QUEUE0_INT_IRQHandler
    .type CONNECTIVITY_ENET0_QUEUE0_INT_IRQHandler, %function
CONNECTIVITY_ENET0_QUEUE0_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_ENET0_QUEUE0_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_ENET0_QUEUE0_INT_IRQHandler, . - CONNECTIVITY_ENET0_QUEUE0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_ENET0_QUEUE1_INT_IRQHandler
    .type CONNECTIVITY_ENET0_QUEUE1_INT_IRQHandler, %function
CONNECTIVITY_ENET0_QUEUE1_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_ENET0_QUEUE1_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_ENET0_QUEUE1_INT_IRQHandler, . - CONNECTIVITY_ENET0_QUEUE1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_ENET0_QUEUE2_INT_IRQHandler
    .type CONNECTIVITY_ENET0_QUEUE2_INT_IRQHandler, %function
CONNECTIVITY_ENET0_QUEUE2_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_ENET0_QUEUE2_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_ENET0_QUEUE2_INT_IRQHandler, . - CONNECTIVITY_ENET0_QUEUE2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_EQOS_DMA_CH0_INT_IRQHandler
    .type CONNECTIVITY_EQOS_DMA_CH0_INT_IRQHandler, %function
CONNECTIVITY_EQOS_DMA_CH0_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_EQOS_DMA_CH0_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_EQOS_DMA_CH0_INT_IRQHandler, . - CONNECTIVITY_EQOS_DMA_CH0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_EQOS_DMA_CH1_INT_IRQHandler
    .type CONNECTIVITY_EQOS_DMA_CH1_INT_IRQHandler, %function
CONNECTIVITY_EQOS_DMA_CH1_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_EQOS_DMA_CH1_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_EQOS_DMA_CH1_INT_IRQHandler, . - CONNECTIVITY_EQOS_DMA_CH1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_EQOS_DMA_CH2_INT_IRQHandler
    .type CONNECTIVITY_EQOS_DMA_CH2_INT_IRQHandler, %function
CONNECTIVITY_EQOS_DMA_CH2_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_EQOS_DMA_CH2_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_EQOS_DMA_CH2_INT_IRQHandler, . - CONNECTIVITY_EQOS_DMA_CH2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_EQOS_DMA_CH3_INT_IRQHandler
    .type CONNECTIVITY_EQOS_DMA_CH3_INT_IRQHandler, %function
CONNECTIVITY_EQOS_DMA_CH3_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_EQOS_DMA_CH3_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_EQOS_DMA_CH3_INT_IRQHandler, . - CONNECTIVITY_EQOS_DMA_CH3_INT_IRQHandler

    .align 1
    .thumb_func
    .weak CONNECTIVITY_EQOS_DMA_CH4_INT_IRQHandler
    .type CONNECTIVITY_EQOS_DMA_CH4_INT_IRQHandler, %function
CONNECTIVITY_EQOS_DMA_CH4_INT_IRQHandler:
    ldr   r0,=CONNECTIVITY_EQOS_DMA_CH4_INT_DriverIRQHandler
    bx    r0
    .size CONNECTIVITY_EQOS_DMA_CH4_INT_IRQHandler, . - CONNECTIVITY_EQOS_DMA_CH4_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI0_MOD_INT_IRQHandler
    .type ADMA_SAI0_MOD_INT_IRQHandler, %function
ADMA_SAI0_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SAI0_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI0_MOD_INT_IRQHandler, . - ADMA_SAI0_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI0_DMA_INT_IRQHandler
    .type ADMA_SAI0_DMA_INT_IRQHandler, %function
ADMA_SAI0_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI0_DMA_INT_IRQHandler, . - ADMA_SAI0_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI1_MOD_INT_IRQHandler
    .type ADMA_SAI1_MOD_INT_IRQHandler, %function
ADMA_SAI1_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SAI1_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI1_MOD_INT_IRQHandler, . - ADMA_SAI1_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI1_DMA_INT_IRQHandler
    .type ADMA_SAI1_DMA_INT_IRQHandler, %function
ADMA_SAI1_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI1_DMA_INT_IRQHandler, . - ADMA_SAI1_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI2_MOD_INT_IRQHandler
    .type ADMA_SAI2_MOD_INT_IRQHandler, %function
ADMA_SAI2_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SAI2_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI2_MOD_INT_IRQHandler, . - ADMA_SAI2_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI2_DMA_INT_IRQHandler
    .type ADMA_SAI2_DMA_INT_IRQHandler, %function
ADMA_SAI2_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI2_DMA_INT_IRQHandler, . - ADMA_SAI2_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI3_MOD_INT_IRQHandler
    .type ADMA_SAI3_MOD_INT_IRQHandler, %function
ADMA_SAI3_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SAI3_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI3_MOD_INT_IRQHandler, . - ADMA_SAI3_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI3_DMA_INT_IRQHandler
    .type ADMA_SAI3_DMA_INT_IRQHandler, %function
ADMA_SAI3_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI3_DMA_INT_IRQHandler, . - ADMA_SAI3_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI0_MOD_INT_IRQHandler
    .type ADMA_SPI0_MOD_INT_IRQHandler, %function
ADMA_SPI0_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SPI0_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI0_MOD_INT_IRQHandler, . - ADMA_SPI0_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI1_MOD_INT_IRQHandler
    .type ADMA_SPI1_MOD_INT_IRQHandler, %function
ADMA_SPI1_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SPI1_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI1_MOD_INT_IRQHandler, . - ADMA_SPI1_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI2_MOD_INT_IRQHandler
    .type ADMA_SPI2_MOD_INT_IRQHandler, %function
ADMA_SPI2_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SPI2_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI2_MOD_INT_IRQHandler, . - ADMA_SPI2_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI3_MOD_INT_IRQHandler
    .type ADMA_SPI3_MOD_INT_IRQHandler, %function
ADMA_SPI3_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SPI3_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI3_MOD_INT_IRQHandler, . - ADMA_SPI3_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C0_MOD_INT_IRQHandler
    .type ADMA_I2C0_MOD_INT_IRQHandler, %function
ADMA_I2C0_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_I2C0_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C0_MOD_INT_IRQHandler, . - ADMA_I2C0_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C1_MOD_INT_IRQHandler
    .type ADMA_I2C1_MOD_INT_IRQHandler, %function
ADMA_I2C1_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_I2C1_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C1_MOD_INT_IRQHandler, . - ADMA_I2C1_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C2_MOD_INT_IRQHandler
    .type ADMA_I2C2_MOD_INT_IRQHandler, %function
ADMA_I2C2_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_I2C2_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C2_MOD_INT_IRQHandler, . - ADMA_I2C2_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C3_MOD_INT_IRQHandler
    .type ADMA_I2C3_MOD_INT_IRQHandler, %function
ADMA_I2C3_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_I2C3_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C3_MOD_INT_IRQHandler, . - ADMA_I2C3_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART0_MOD_INT_IRQHandler
    .type ADMA_UART0_MOD_INT_IRQHandler, %function
ADMA_UART0_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_UART0_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART0_MOD_INT_IRQHandler, . - ADMA_UART0_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART1_MOD_INT_IRQHandler
    .type ADMA_UART1_MOD_INT_IRQHandler, %function
ADMA_UART1_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_UART1_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART1_MOD_INT_IRQHandler, . - ADMA_UART1_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART2_MOD_INT_IRQHandler
    .type ADMA_UART2_MOD_INT_IRQHandler, %function
ADMA_UART2_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_UART2_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART2_MOD_INT_IRQHandler, . - ADMA_UART2_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART3_MOD_INT_IRQHandler
    .type ADMA_UART3_MOD_INT_IRQHandler, %function
ADMA_UART3_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_UART3_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART3_MOD_INT_IRQHandler, . - ADMA_UART3_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN0_MOD_INT_IRQHandler
    .type ADMA_FLEXCAN0_MOD_INT_IRQHandler, %function
ADMA_FLEXCAN0_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_FLEXCAN0_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN0_MOD_INT_IRQHandler, . - ADMA_FLEXCAN0_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN1_MOD_INT_IRQHandler
    .type ADMA_FLEXCAN1_MOD_INT_IRQHandler, %function
ADMA_FLEXCAN1_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_FLEXCAN1_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN1_MOD_INT_IRQHandler, . - ADMA_FLEXCAN1_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN2_MOD_INT_IRQHandler
    .type ADMA_FLEXCAN2_MOD_INT_IRQHandler, %function
ADMA_FLEXCAN2_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_FLEXCAN2_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN2_MOD_INT_IRQHandler, . - ADMA_FLEXCAN2_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FTM0_MOD_INT_IRQHandler
    .type ADMA_FTM0_MOD_INT_IRQHandler, %function
ADMA_FTM0_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_FTM0_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FTM0_MOD_INT_IRQHandler, . - ADMA_FTM0_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FTM1_MOD_INT_IRQHandler
    .type ADMA_FTM1_MOD_INT_IRQHandler, %function
ADMA_FTM1_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_FTM1_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FTM1_MOD_INT_IRQHandler, . - ADMA_FTM1_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_ADC0_MOD_INT_IRQHandler
    .type ADMA_ADC0_MOD_INT_IRQHandler, %function
ADMA_ADC0_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_ADC0_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_ADC0_MOD_INT_IRQHandler, . - ADMA_ADC0_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN0_DMA_INT_IRQHandler
    .type ADMA_FLEXCAN0_DMA_INT_IRQHandler, %function
ADMA_FLEXCAN0_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN0_DMA_INT_IRQHandler, . - ADMA_FLEXCAN0_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN1_DMA_INT_IRQHandler
    .type ADMA_FLEXCAN1_DMA_INT_IRQHandler, %function
ADMA_FLEXCAN1_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN1_DMA_INT_IRQHandler, . - ADMA_FLEXCAN1_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FLEXCAN2_DMA_INT_IRQHandler
    .type ADMA_FLEXCAN2_DMA_INT_IRQHandler, %function
ADMA_FLEXCAN2_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FLEXCAN2_DMA_INT_IRQHandler, . - ADMA_FLEXCAN2_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FTM0_DMA_INT_IRQHandler
    .type ADMA_FTM0_DMA_INT_IRQHandler, %function
ADMA_FTM0_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FTM0_DMA_INT_IRQHandler, . - ADMA_FTM0_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_FTM1_DMA_INT_IRQHandler
    .type ADMA_FTM1_DMA_INT_IRQHandler, %function
ADMA_FTM1_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_FTM1_DMA_INT_IRQHandler, . - ADMA_FTM1_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_ADC0_DMA_INT_IRQHandler
    .type ADMA_ADC0_DMA_INT_IRQHandler, %function
ADMA_ADC0_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_ADC0_DMA_INT_IRQHandler, . - ADMA_ADC0_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EDMA0_INT_IRQHandler
    .type ADMA_EDMA0_INT_IRQHandler, %function
ADMA_EDMA0_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EDMA0_INT_IRQHandler, . - ADMA_EDMA0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_EDMA0_ERR_INT_IRQHandler
    .type ADMA_EDMA0_ERR_INT_IRQHandler, %function
ADMA_EDMA0_ERR_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_EDMA0_ERR_INT_IRQHandler, . - ADMA_EDMA0_ERR_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_ASRC0_INT1_IRQHandler
    .type ADMA_ASRC0_INT1_IRQHandler, %function
ADMA_ASRC0_INT1_IRQHandler:
    ldr   r0,=ADMA_ASRC0_INT1_DriverIRQHandler
    bx    r0
    .size ADMA_ASRC0_INT1_IRQHandler, . - ADMA_ASRC0_INT1_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_ASRC0_INT2_IRQHandler
    .type ADMA_ASRC0_INT2_IRQHandler, %function
ADMA_ASRC0_INT2_IRQHandler:
    ldr   r0,=ADMA_ASRC0_INT2_DriverIRQHandler
    bx    r0
    .size ADMA_ASRC0_INT2_IRQHandler, . - ADMA_ASRC0_INT2_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_DMA0_CH0_INT_IRQHandler
    .type ADMA_DMA0_CH0_INT_IRQHandler, %function
ADMA_DMA0_CH0_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_DMA0_CH0_INT_IRQHandler, . - ADMA_DMA0_CH0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_DMA0_CH1_INT_IRQHandler
    .type ADMA_DMA0_CH1_INT_IRQHandler, %function
ADMA_DMA0_CH1_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_DMA0_CH1_INT_IRQHandler, . - ADMA_DMA0_CH1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_DMA0_CH2_INT_IRQHandler
    .type ADMA_DMA0_CH2_INT_IRQHandler, %function
ADMA_DMA0_CH2_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_DMA0_CH2_INT_IRQHandler, . - ADMA_DMA0_CH2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_DMA0_CH3_INT_IRQHandler
    .type ADMA_DMA0_CH3_INT_IRQHandler, %function
ADMA_DMA0_CH3_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_DMA0_CH3_INT_IRQHandler, . - ADMA_DMA0_CH3_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_DMA0_CH4_INT_IRQHandler
    .type ADMA_DMA0_CH4_INT_IRQHandler, %function
ADMA_DMA0_CH4_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_DMA0_CH4_INT_IRQHandler, . - ADMA_DMA0_CH4_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_DMA0_CH5_INT_IRQHandler
    .type ADMA_DMA0_CH5_INT_IRQHandler, %function
ADMA_DMA0_CH5_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_DMA0_CH5_INT_IRQHandler, . - ADMA_DMA0_CH5_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_GPT0_INT_IRQHandler
    .type ADMA_GPT0_INT_IRQHandler, %function
ADMA_GPT0_INT_IRQHandler:
    ldr   r0,=ADMA_GPT0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_GPT0_INT_IRQHandler, . - ADMA_GPT0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_GPT1_INT_IRQHandler
    .type ADMA_GPT1_INT_IRQHandler, %function
ADMA_GPT1_INT_IRQHandler:
    ldr   r0,=ADMA_GPT1_INT_DriverIRQHandler
    bx    r0
    .size ADMA_GPT1_INT_IRQHandler, . - ADMA_GPT1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_GPT2_INT_IRQHandler
    .type ADMA_GPT2_INT_IRQHandler, %function
ADMA_GPT2_INT_IRQHandler:
    ldr   r0,=ADMA_GPT2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_GPT2_INT_IRQHandler, . - ADMA_GPT2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_GPT3_INT_IRQHandler
    .type ADMA_GPT3_INT_IRQHandler, %function
ADMA_GPT3_INT_IRQHandler:
    ldr   r0,=ADMA_GPT3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_GPT3_INT_IRQHandler, . - ADMA_GPT3_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI0_INT_IRQHandler
    .type ADMA_SAI0_INT_IRQHandler, %function
ADMA_SAI0_INT_IRQHandler:
    ldr   r0,=ADMA_SAI0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI0_INT_IRQHandler, . - ADMA_SAI0_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI1_INT_IRQHandler
    .type ADMA_SAI1_INT_IRQHandler, %function
ADMA_SAI1_INT_IRQHandler:
    ldr   r0,=ADMA_SAI1_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI1_INT_IRQHandler, . - ADMA_SAI1_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI2_INT_IRQHandler
    .type ADMA_SAI2_INT_IRQHandler, %function
ADMA_SAI2_INT_IRQHandler:
    ldr   r0,=ADMA_SAI2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI2_INT_IRQHandler, . - ADMA_SAI2_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SAI3_INT_IRQHandler
    .type ADMA_SAI3_INT_IRQHandler, %function
ADMA_SAI3_INT_IRQHandler:
    ldr   r0,=ADMA_SAI3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SAI3_INT_IRQHandler, . - ADMA_SAI3_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPDIF0_RX_INT_IRQHandler
    .type ADMA_SPDIF0_RX_INT_IRQHandler, %function
ADMA_SPDIF0_RX_INT_IRQHandler:
    ldr   r0,=ADMA_SPDIF0_RX_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPDIF0_RX_INT_IRQHandler, . - ADMA_SPDIF0_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPDIF0_TX_INT_IRQHandler
    .type ADMA_SPDIF0_TX_INT_IRQHandler, %function
ADMA_SPDIF0_TX_INT_IRQHandler:
    ldr   r0,=ADMA_SPDIF0_TX_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPDIF0_TX_INT_IRQHandler, . - ADMA_SPDIF0_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI0_DMA_RX_INT_IRQHandler
    .type ADMA_SPI0_DMA_RX_INT_IRQHandler, %function
ADMA_SPI0_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI0_DMA_RX_INT_IRQHandler, . - ADMA_SPI0_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI0_DMA_TX_INT_IRQHandler
    .type ADMA_SPI0_DMA_TX_INT_IRQHandler, %function
ADMA_SPI0_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI0_DMA_TX_INT_IRQHandler, . - ADMA_SPI0_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI1_DMA_RX_INT_IRQHandler
    .type ADMA_SPI1_DMA_RX_INT_IRQHandler, %function
ADMA_SPI1_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI1_DMA_RX_INT_IRQHandler, . - ADMA_SPI1_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI1_DMA_TX_INT_IRQHandler
    .type ADMA_SPI1_DMA_TX_INT_IRQHandler, %function
ADMA_SPI1_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI1_DMA_TX_INT_IRQHandler, . - ADMA_SPI1_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI2_DMA_RX_INT_IRQHandler
    .type ADMA_SPI2_DMA_RX_INT_IRQHandler, %function
ADMA_SPI2_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI2_DMA_RX_INT_IRQHandler, . - ADMA_SPI2_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI2_DMA_TX_INT_IRQHandler
    .type ADMA_SPI2_DMA_TX_INT_IRQHandler, %function
ADMA_SPI2_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI2_DMA_TX_INT_IRQHandler, . - ADMA_SPI2_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI3_DMA_RX_INT_IRQHandler
    .type ADMA_SPI3_DMA_RX_INT_IRQHandler, %function
ADMA_SPI3_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI3_DMA_RX_INT_IRQHandler, . - ADMA_SPI3_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPI3_DMA_TX_INT_IRQHandler
    .type ADMA_SPI3_DMA_TX_INT_IRQHandler, %function
ADMA_SPI3_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPI3_DMA_TX_INT_IRQHandler, . - ADMA_SPI3_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C0_DMA_RX_INT_IRQHandler
    .type ADMA_I2C0_DMA_RX_INT_IRQHandler, %function
ADMA_I2C0_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C0_DMA_RX_INT_IRQHandler, . - ADMA_I2C0_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C0_DMA_TX_INT_IRQHandler
    .type ADMA_I2C0_DMA_TX_INT_IRQHandler, %function
ADMA_I2C0_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C0_DMA_TX_INT_IRQHandler, . - ADMA_I2C0_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C1_DMA_RX_INT_IRQHandler
    .type ADMA_I2C1_DMA_RX_INT_IRQHandler, %function
ADMA_I2C1_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C1_DMA_RX_INT_IRQHandler, . - ADMA_I2C1_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C1_DMA_TX_INT_IRQHandler
    .type ADMA_I2C1_DMA_TX_INT_IRQHandler, %function
ADMA_I2C1_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C1_DMA_TX_INT_IRQHandler, . - ADMA_I2C1_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C2_DMA_RX_INT_IRQHandler
    .type ADMA_I2C2_DMA_RX_INT_IRQHandler, %function
ADMA_I2C2_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C2_DMA_RX_INT_IRQHandler, . - ADMA_I2C2_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C2_DMA_TX_INT_IRQHandler
    .type ADMA_I2C2_DMA_TX_INT_IRQHandler, %function
ADMA_I2C2_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C2_DMA_TX_INT_IRQHandler, . - ADMA_I2C2_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C3_DMA_RX_INT_IRQHandler
    .type ADMA_I2C3_DMA_RX_INT_IRQHandler, %function
ADMA_I2C3_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C3_DMA_RX_INT_IRQHandler, . - ADMA_I2C3_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_I2C3_DMA_TX_INT_IRQHandler
    .type ADMA_I2C3_DMA_TX_INT_IRQHandler, %function
ADMA_I2C3_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA3_INT_DriverIRQHandler
    bx    r0
    .size ADMA_I2C3_DMA_TX_INT_IRQHandler, . - ADMA_I2C3_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART0_DMA_RX_INT_IRQHandler
    .type ADMA_UART0_DMA_RX_INT_IRQHandler, %function
ADMA_UART0_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART0_DMA_RX_INT_IRQHandler, . - ADMA_UART0_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART0_DMA_TX_INT_IRQHandler
    .type ADMA_UART0_DMA_TX_INT_IRQHandler, %function
ADMA_UART0_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART0_DMA_TX_INT_IRQHandler, . - ADMA_UART0_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART1_DMA_RX_INT_IRQHandler
    .type ADMA_UART1_DMA_RX_INT_IRQHandler, %function
ADMA_UART1_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART1_DMA_RX_INT_IRQHandler, . - ADMA_UART1_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART1_DMA_TX_INT_IRQHandler
    .type ADMA_UART1_DMA_TX_INT_IRQHandler, %function
ADMA_UART1_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART1_DMA_TX_INT_IRQHandler, . - ADMA_UART1_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART2_DMA_RX_INT_IRQHandler
    .type ADMA_UART2_DMA_RX_INT_IRQHandler, %function
ADMA_UART2_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART2_DMA_RX_INT_IRQHandler, . - ADMA_UART2_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART2_DMA_TX_INT_IRQHandler
    .type ADMA_UART2_DMA_TX_INT_IRQHandler, %function
ADMA_UART2_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART2_DMA_TX_INT_IRQHandler, . - ADMA_UART2_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART3_DMA_RX_INT_IRQHandler
    .type ADMA_UART3_DMA_RX_INT_IRQHandler, %function
ADMA_UART3_DMA_RX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART3_DMA_RX_INT_IRQHandler, . - ADMA_UART3_DMA_RX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_UART3_DMA_TX_INT_IRQHandler
    .type ADMA_UART3_DMA_TX_INT_IRQHandler, %function
ADMA_UART3_DMA_TX_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA2_INT_DriverIRQHandler
    bx    r0
    .size ADMA_UART3_DMA_TX_INT_IRQHandler, . - ADMA_UART3_DMA_TX_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPDIF0_RX_MOD_INT_IRQHandler
    .type ADMA_SPDIF0_RX_MOD_INT_IRQHandler, %function
ADMA_SPDIF0_RX_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SPDIF0_RX_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPDIF0_RX_MOD_INT_IRQHandler, . - ADMA_SPDIF0_RX_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPDIF0_RX_DMA_INT_IRQHandler
    .type ADMA_SPDIF0_RX_DMA_INT_IRQHandler, %function
ADMA_SPDIF0_RX_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPDIF0_RX_DMA_INT_IRQHandler, . - ADMA_SPDIF0_RX_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPDIF0_TX_MOD_INT_IRQHandler
    .type ADMA_SPDIF0_TX_MOD_INT_IRQHandler, %function
ADMA_SPDIF0_TX_MOD_INT_IRQHandler:
    ldr   r0,=ADMA_SPDIF0_TX_MOD_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPDIF0_TX_MOD_INT_IRQHandler, . - ADMA_SPDIF0_TX_MOD_INT_IRQHandler

    .align 1
    .thumb_func
    .weak ADMA_SPDIF0_TX_DMA_INT_IRQHandler
    .type ADMA_SPDIF0_TX_DMA_INT_IRQHandler, %function
ADMA_SPDIF0_TX_DMA_INT_IRQHandler:
    ldr   r0,=ADMA_EDMA0_INT_DriverIRQHandler
    bx    r0
    .size ADMA_SPDIF0_TX_DMA_INT_IRQHandler, . - ADMA_SPDIF0_TX_DMA_INT_IRQHandler

    .align 1
    .thumb_func
    .weak M4_INTMUX_SOURCE_TPM_IRQHandler
    .type M4_INTMUX_SOURCE_TPM_IRQHandler, %function
M4_INTMUX_SOURCE_TPM_IRQHandler:
    ldr   r0,=M4_INTMUX_SOURCE_TPM_DriverIRQHandler
    bx    r0
    .size M4_INTMUX_SOURCE_TPM_IRQHandler, . - M4_INTMUX_SOURCE_TPM_IRQHandler

    .align 1
    .thumb_func
    .weak M4_INTMUX_SOURCE_LPIT_IRQHandler
    .type M4_INTMUX_SOURCE_LPIT_IRQHandler, %function
M4_INTMUX_SOURCE_LPIT_IRQHandler:
    ldr   r0,=M4_INTMUX_SOURCE_LPIT_DriverIRQHandler
    bx    r0
    .size M4_INTMUX_SOURCE_LPIT_IRQHandler, . - M4_INTMUX_SOURCE_LPIT_IRQHandler

    .align 1
    .thumb_func
    .weak M4_INTMUX_SOURCE_LPUART_IRQHandler
    .type M4_INTMUX_SOURCE_LPUART_IRQHandler, %function
M4_INTMUX_SOURCE_LPUART_IRQHandler:
    ldr   r0,=M4_INTMUX_SOURCE_LPUART_DriverIRQHandler
    bx    r0
    .size M4_INTMUX_SOURCE_LPUART_IRQHandler, . - M4_INTMUX_SOURCE_LPUART_IRQHandler

    .align 1
    .thumb_func
    .weak M4_INTMUX_SOURCE_LPI2C_IRQHandler
    .type M4_INTMUX_SOURCE_LPI2C_IRQHandler, %function
M4_INTMUX_SOURCE_LPI2C_IRQHandler:
    ldr   r0,=M4_INTMUX_SOURCE_LPI2C_DriverIRQHandler
    bx    r0
    .size M4_INTMUX_SOURCE_LPI2C_IRQHandler, . - M4_INTMUX_SOURCE_LPI2C_IRQHandler

    .align 1
    .thumb_func
    .weak M4_INTMUX_SOURCE_MU0_A3_IRQHandler
    .type M4_INTMUX_SOURCE_MU0_A3_IRQHandler, %function
M4_INTMUX_SOURCE_MU0_A3_IRQHandler:
    ldr   r0,=M4_INTMUX_SOURCE_MU0_A3_DriverIRQHandler
    bx    r0
    .size M4_INTMUX_SOURCE_MU0_A3_IRQHandler, . - M4_INTMUX_SOURCE_MU0_A3_IRQHandler

    .align 1
    .thumb_func
    .weak M4_INTMUX_SOURCE_MU0_A2_IRQHandler
    .type M4_INTMUX_SOURCE_MU0_A2_IRQHandler, %function
M4_INTMUX_SOURCE_MU0_A2_IRQHandler:
    ldr   r0,=M4_INTMUX_SOURCE_MU0_A2_DriverIRQHandler
    bx    r0
    .size M4_INTMUX_SOURCE_MU0_A2_IRQHandler, . - M4_INTMUX_SOURCE_MU0_A2_IRQHandler

    .align 1
    .thumb_func
    .weak M4_INTMUX_SOURCE_MU0_A1_IRQHandler
    .type M4_INTMUX_SOURCE_MU0_A1_IRQHandler, %function
M4_INTMUX_SOURCE_MU0_A1_IRQHandler:
    ldr   r0,=M4_INTMUX_SOURCE_MU0_A1_DriverIRQHandler
    bx    r0
    .size M4_INTMUX_SOURCE_MU0_A1_IRQHandler, . - M4_INTMUX_SOURCE_MU0_A1_IRQHandler

    .align 1
    .thumb_func
    .weak M4_INTMUX_SOURCE_MU0_A0_IRQHandler
    .type M4_INTMUX_SOURCE_MU0_A0_IRQHandler, %function
M4_INTMUX_SOURCE_MU0_A0_IRQHandler:
    ldr   r0,=M4_INTMUX_SOURCE_MU0_A0_DriverIRQHandler
    bx    r0
    .size M4_INTMUX_SOURCE_MU0_A0_IRQHandler, . - M4_INTMUX_SOURCE_MU0_A0_IRQHandler


/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro def_irq_handler  handler_name
    .weak \handler_name
    .set  \handler_name, DefaultISR
    .endm

/* Exception Handlers */
    def_irq_handler    MemManage_Handler
    def_irq_handler    BusFault_Handler
    def_irq_handler    UsageFault_Handler
    def_irq_handler    DebugMon_Handler
    def_irq_handler    Reserved16_IRQHandler
    def_irq_handler    Reserved17_IRQHandler
    def_irq_handler    Reserved18_IRQHandler
    def_irq_handler    Reserved19_IRQHandler
    def_irq_handler    Reserved20_IRQHandler
    def_irq_handler    M4_MCM_IRQHandler
    def_irq_handler    Reserved22_IRQHandler
    def_irq_handler    Reserved23_IRQHandler
    def_irq_handler    Reserved24_IRQHandler
    def_irq_handler    Reserved25_IRQHandler
    def_irq_handler    Reserved26_IRQHandler
    def_irq_handler    Reserved27_IRQHandler
    def_irq_handler    Reserved28_IRQHandler
    def_irq_handler    Reserved29_IRQHandler
    def_irq_handler    Reserved30_IRQHandler
    def_irq_handler    Reserved31_IRQHandler
    def_irq_handler    Reserved32_IRQHandler
    def_irq_handler    Reserved33_IRQHandler
    def_irq_handler    Reserved34_IRQHandler
    def_irq_handler    M4_TPM_IRQHandler
    def_irq_handler    Reserved36_IRQHandler
    def_irq_handler    Reserved37_IRQHandler
    def_irq_handler    M4_LPIT_IRQHandler
    def_irq_handler    Reserved39_IRQHandler
    def_irq_handler    Reserved40_IRQHandler
    def_irq_handler    M4_LPUART_DriverIRQHandler
    def_irq_handler    Reserved42_IRQHandler
    def_irq_handler    M4_LPI2C_DriverIRQHandler
    def_irq_handler    Reserved44_IRQHandler
    def_irq_handler    M4_MU0_B0_IRQHandler
    def_irq_handler    Reserved46_IRQHandler
    def_irq_handler    Reserved47_IRQHandler
    def_irq_handler    IRQSTEER_0_DriverIRQHandler
    def_irq_handler    IRQSTEER_1_DriverIRQHandler
    def_irq_handler    IRQSTEER_2_DriverIRQHandler
    def_irq_handler    IRQSTEER_3_DriverIRQHandler
    def_irq_handler    IRQSTEER_4_DriverIRQHandler
    def_irq_handler    IRQSTEER_5_DriverIRQHandler
    def_irq_handler    Reserved54_IRQHandler
    def_irq_handler    Reserved55_IRQHandler
    def_irq_handler    Reserved56_IRQHandler
    def_irq_handler    Reserved57_IRQHandler
    def_irq_handler    Reserved58_IRQHandler
    def_irq_handler    Reserved59_IRQHandler
    def_irq_handler    M4_MU0_B1_IRQHandler
    def_irq_handler    M4_MU0_B2_IRQHandler
    def_irq_handler    M4_MU0_B3_IRQHandler
    def_irq_handler    Reserved63_IRQHandler
    def_irq_handler    Reserved64_IRQHandler
    def_irq_handler    M4_MU1_A_IRQHandler
    def_irq_handler    M4_SW_IRQHandler
    def_irq_handler    Reserved67_IRQHandler
    def_irq_handler    Reserved68_IRQHandler
    def_irq_handler    Reserved69_IRQHandler
    def_irq_handler    Reserved70_IRQHandler
    def_irq_handler    Reserved71_IRQHandler
    def_irq_handler    Reserved72_IRQHandler
    def_irq_handler    Reserved73_IRQHandler
    def_irq_handler    Reserved74_IRQHandler
    def_irq_handler    Reserved75_IRQHandler
    def_irq_handler    Reserved76_IRQHandler
    def_irq_handler    Reserved77_IRQHandler
    def_irq_handler    Reserved78_IRQHandler
    def_irq_handler    Reserved79_IRQHandler
    def_irq_handler    Reserved80_IRQHandler
    def_irq_handler    Reserved81_IRQHandler
    def_irq_handler    Reserved82_IRQHandler
    def_irq_handler    Reserved83_IRQHandler
    def_irq_handler    Reserved84_IRQHandler
    def_irq_handler    Reserved85_IRQHandler
    def_irq_handler    Reserved86_IRQHandler
    def_irq_handler    Reserved87_IRQHandler
    def_irq_handler    Reserved88_IRQHandler
    def_irq_handler    Reserved89_IRQHandler
    def_irq_handler    Reserved90_IRQHandler
    def_irq_handler    Reserved91_IRQHandler
    def_irq_handler    Reserved92_IRQHandler
    def_irq_handler    Reserved93_IRQHandler
    def_irq_handler    Reserved94_IRQHandler
    def_irq_handler    Reserved95_IRQHandler
    def_irq_handler    Reserved96_IRQHandler
    def_irq_handler    Reserved97_IRQHandler
    def_irq_handler    Reserved98_IRQHandler
    def_irq_handler    A35_NINTERRIRQ_IRQHandler
    def_irq_handler    A35_NEXTERRIRQ_IRQHandler
    def_irq_handler    Reserved101_IRQHandler
    def_irq_handler    Reserved102_IRQHandler
    def_irq_handler    Reserved103_IRQHandler
    def_irq_handler    Reserved104_IRQHandler
    def_irq_handler    Reserved105_IRQHandler
    def_irq_handler    Reserved106_IRQHandler
    def_irq_handler    M4_INT_OUT0_IRQHandler
    def_irq_handler    M4_INT_OUT1_IRQHandler
    def_irq_handler    M4_INT_OUT2_IRQHandler
    def_irq_handler    M4_INT_OUT3_IRQHandler
    def_irq_handler    M4_INT_OUT4_IRQHandler
    def_irq_handler    M4_INT_OUT5_IRQHandler
    def_irq_handler    M4_INT_OUT6_IRQHandler
    def_irq_handler    M4_INT_OUT7_IRQHandler
    def_irq_handler    Reserved115_IRQHandler
    def_irq_handler    Reserved116_IRQHandler
    def_irq_handler    LCD_MOD_INT_IRQHandler
    def_irq_handler    LCD_PWM_INT_IRQHandler
    def_irq_handler    ADMA_EDMA2_INT_DriverIRQHandler
    def_irq_handler    ADMA_EDMA3_INT_DriverIRQHandler
    def_irq_handler    Reserved123_IRQHandler
    def_irq_handler    Reserved124_IRQHandler
    def_irq_handler    Reserved125_IRQHandler
    def_irq_handler    Reserved126_IRQHandler
    def_irq_handler    LSIO_GPT0_INT_IRQHandler
    def_irq_handler    LSIO_GPT1_INT_IRQHandler
    def_irq_handler    LSIO_GPT2_INT_IRQHandler
    def_irq_handler    LSIO_GPT3_INT_IRQHandler
    def_irq_handler    LSIO_GPT4_INT_IRQHandler
    def_irq_handler    LSIO_KPP_INT_IRQHandler
    def_irq_handler    LSIO_OCTASPI0_INT_DriverIRQHandler
    def_irq_handler    LSIO_OCTASPI1_INT_DriverIRQHandler
    def_irq_handler    LSIO_PWM0_INT_IRQHandler
    def_irq_handler    LSIO_PWM1_INT_IRQHandler
    def_irq_handler    LSIO_PWM2_INT_IRQHandler
    def_irq_handler    LSIO_PWM3_INT_IRQHandler
    def_irq_handler    LSIO_PWM4_INT_IRQHandler
    def_irq_handler    LSIO_PWM5_INT_IRQHandler
    def_irq_handler    LSIO_PWM6_INT_IRQHandler
    def_irq_handler    LSIO_PWM7_INT_IRQHandler
    def_irq_handler    HSIO_PCIEB_MSI_CTRL_INT_IRQHandler
    def_irq_handler    HSIO_PCIEB_CLK_REQ_INT_IRQHandler
    def_irq_handler    HSIO_PCIEB_DMA_INT_DriverIRQHandler
    def_irq_handler    HSIO_PCIEB_INT_A_IRQHandler
    def_irq_handler    HSIO_PCIEB_INT_B_IRQHandler
    def_irq_handler    HSIO_PCIEB_INT_C_IRQHandler
    def_irq_handler    HSIO_PCIEB_INT_D_IRQHandler
    def_irq_handler    HSIO_PCIEB_SMLH_REQ_RST_IRQHandler
    def_irq_handler    HSIO_PCIEB_GPIO_WAKEUP0_IRQHandler
    def_irq_handler    HSIO_PCIEB_GPIO_WAKEUP1_IRQHandler
    def_irq_handler    SCU_INT_OUT0_IRQHandler
    def_irq_handler    SCU_INT_OUT1_IRQHandler
    def_irq_handler    SCU_INT_OUT2_IRQHandler
    def_irq_handler    SCU_INT_OUT3_IRQHandler
    def_irq_handler    SCU_INT_OUT4_IRQHandler
    def_irq_handler    SCU_INT_OUT5_IRQHandler
    def_irq_handler    SCU_INT_OUT6_IRQHandler
    def_irq_handler    SCU_INT_OUT7_IRQHandler
    def_irq_handler    SCU_SYS_COUNT_INT0_IRQHandler
    def_irq_handler    SCU_SYS_COUNT_INT1_IRQHandler
    def_irq_handler    SCU_SYS_COUNT_INT2_IRQHandler
    def_irq_handler    SCU_SYS_COUNT_INT3_IRQHandler
    def_irq_handler    Reserved165_IRQHandler
    def_irq_handler    Reserved166_IRQHandler
    def_irq_handler    DRC_ECC_CORRECT_INT_IRQHandler
    def_irq_handler    DRC_ECC_NCORRECT_INT_IRQHandler
    def_irq_handler    DRC_SBR_DONE_INT_IRQHandler
    def_irq_handler    DRC_PERF_CNT_INT_IRQHandler
    def_irq_handler    DRC_ECC_AP_ERR_INT_IRQHandler
    def_irq_handler    DRC_DERATE_TEMP_LIMIT_INT_IRQHandler
    def_irq_handler    Reserved173_IRQHandler
    def_irq_handler    Reserved174_IRQHandler
    def_irq_handler    Reserved175_IRQHandler
    def_irq_handler    Reserved176_IRQHandler
    def_irq_handler    LSIO_GPIO_INT0_IRQHandler
    def_irq_handler    LSIO_GPIO_INT1_IRQHandler
    def_irq_handler    LSIO_GPIO_INT2_IRQHandler
    def_irq_handler    LSIO_GPIO_INT3_IRQHandler
    def_irq_handler    LSIO_GPIO_INT4_IRQHandler
    def_irq_handler    LSIO_GPIO_INT5_IRQHandler
    def_irq_handler    LSIO_GPIO_INT6_IRQHandler
    def_irq_handler    LSIO_GPIO_INT7_IRQHandler
    def_irq_handler    LSIO_MU0_INT_IRQHandler
    def_irq_handler    LSIO_MU1_INT_IRQHandler
    def_irq_handler    LSIO_MU2_INT_IRQHandler
    def_irq_handler    LSIO_MU3_INT_IRQHandler
    def_irq_handler    LSIO_MU4_INT_IRQHandler
    def_irq_handler    LSIO_MU5_INT_A_IRQHandler
    def_irq_handler    LSIO_MU6_INT_A_IRQHandler
    def_irq_handler    LSIO_MU7_INT_A_IRQHandler
    def_irq_handler    LSIO_MU8_INT_A_IRQHandler
    def_irq_handler    LSIO_MU9_INT_A_IRQHandler
    def_irq_handler    LSIO_MU10_INT_A_IRQHandler
    def_irq_handler    LSIO_MU11_INT_A_IRQHandler
    def_irq_handler    LSIO_MU12_INT_A_IRQHandler
    def_irq_handler    LSIO_MU13_INT_A_IRQHandler
    def_irq_handler    LSIO_MU5_INT_B_IRQHandler
    def_irq_handler    LSIO_MU6_INT_B_IRQHandler
    def_irq_handler    LSIO_MU7_INT_B_IRQHandler
    def_irq_handler    LSIO_MU8_INT_B_IRQHandler
    def_irq_handler    LSIO_MU9_INT_B_IRQHandler
    def_irq_handler    LSIO_MU10_INT_B_IRQHandler
    def_irq_handler    LSIO_MU11_INT_B_IRQHandler
    def_irq_handler    LSIO_MU12_INT_B_IRQHandler
    def_irq_handler    LSIO_MU13_INT_B_IRQHandler
    def_irq_handler    Reserved208_IRQHandler
    def_irq_handler    Reserved209_IRQHandler
    def_irq_handler    Reserved210_IRQHandler
    def_irq_handler    Reserved211_IRQHandler
    def_irq_handler    Reserved212_IRQHandler
    def_irq_handler    Reserved213_IRQHandler
    def_irq_handler    Reserved214_IRQHandler
    def_irq_handler    Reserved215_IRQHandler
    def_irq_handler    Reserved216_IRQHandler
    def_irq_handler    ADMA_SPI0_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPI1_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPI2_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPI3_INT_DriverIRQHandler
    def_irq_handler    ADMA_I2C0_INT_DriverIRQHandler
    def_irq_handler    ADMA_I2C1_INT_DriverIRQHandler
    def_irq_handler    ADMA_I2C2_INT_DriverIRQHandler
    def_irq_handler    ADMA_I2C3_INT_DriverIRQHandler
    def_irq_handler    ADMA_UART0_INT_DriverIRQHandler
    def_irq_handler    ADMA_UART1_INT_DriverIRQHandler
    def_irq_handler    ADMA_UART2_INT_DriverIRQHandler
    def_irq_handler    ADMA_UART3_INT_DriverIRQHandler
    def_irq_handler    Reserved229_IRQHandler
    def_irq_handler    Reserved230_IRQHandler
    def_irq_handler    Reserved231_IRQHandler
    def_irq_handler    Reserved232_IRQHandler
    def_irq_handler    Reserved233_IRQHandler
    def_irq_handler    Reserved234_IRQHandler
    def_irq_handler    Reserved235_IRQHandler
    def_irq_handler    Reserved236_IRQHandler
    def_irq_handler    CONNECTIVITY_USDHC0_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_USDHC1_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_USDHC2_INT_DriverIRQHandler
    def_irq_handler    ADMA_FLEXCAN0_INT_DriverIRQHandler
    def_irq_handler    ADMA_FLEXCAN1_INT_DriverIRQHandler
    def_irq_handler    ADMA_FLEXCAN2_INT_DriverIRQHandler
    def_irq_handler    ADMA_FTM0_INT_DriverIRQHandler
    def_irq_handler    ADMA_FTM1_INT_DriverIRQHandler
    def_irq_handler    ADMA_ADC0_INT_DriverIRQHandler
    def_irq_handler    Reserved246_IRQHandler
    def_irq_handler    Reserved253_IRQHandler
    def_irq_handler    Reserved254_IRQHandler
    def_irq_handler    Reserved255_IRQHandler
    def_irq_handler    Reserved256_IRQHandler
    def_irq_handler    CONNECTIVITY_ENET0_FRAME1_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_ENET0_FRAME2_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_ENET0_FRAME0_EVENT_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_ENET0_TIMER_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_EQOS_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_EQOS_PMT_INT_DriverIRQHandler
    def_irq_handler    Reserved263_IRQHandler
    def_irq_handler    Reserved264_IRQHandler
    def_irq_handler    CONNECTIVITY_USB_OTG2_INT_IRQHandler
    def_irq_handler    CONNECTIVITY_UTM2_INT_IRQHandler
    def_irq_handler    CONNECTIVITY_WAKEUP2_INT_IRQHandler
    def_irq_handler    CONNECTIVITY_USB_OTG1_INT_IRQHandler
    def_irq_handler    Reserved269_IRQHandler
    def_irq_handler    CONNECTIVITY_UTM1_INT_IRQHandler
    def_irq_handler    CONNECTIVITY_WAKEUP1_INT_IRQHandler
    def_irq_handler    Reserved272_IRQHandler
    def_irq_handler    CONNECTIVITY_ND_FLASH_BCH_INT_IRQHandler
    def_irq_handler    CONNECTIVITY_ND_FLASH_GPMI_INT_IRQHandler
    def_irq_handler    CONNECTIVITY_APBHDMA_DriverIRQHandler
    def_irq_handler    Reserved276_IRQHandler
    def_irq_handler    CONNECTIVITY_ENET0_QUEUE0_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_ENET0_QUEUE1_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_ENET0_QUEUE2_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_EQOS_DMA_CH0_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_EQOS_DMA_CH1_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_EQOS_DMA_CH2_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_EQOS_DMA_CH3_INT_DriverIRQHandler
    def_irq_handler    CONNECTIVITY_EQOS_DMA_CH4_INT_DriverIRQHandler
    def_irq_handler    Reserved285_IRQHandler
    def_irq_handler    Reserved286_IRQHandler
    def_irq_handler    ADMA_SAI0_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_EDMA0_INT_DriverIRQHandler
    def_irq_handler    ADMA_SAI1_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_SAI2_MOD_INT_DriverIRQHandler
    def_irq_handler    Reserved293_IRQHandler
    def_irq_handler    Reserved294_IRQHandler
    def_irq_handler    Reserved295_IRQHandler
    def_irq_handler    Reserved296_IRQHandler
    def_irq_handler    ADMA_SAI3_MOD_INT_DriverIRQHandler
    def_irq_handler    Reserved299_IRQHandler
    def_irq_handler    Reserved300_IRQHandler
    def_irq_handler    Reserved301_IRQHandler
    def_irq_handler    Reserved302_IRQHandler
    def_irq_handler    Reserved303_IRQHandler
    def_irq_handler    Reserved304_IRQHandler
    def_irq_handler    Reserved305_IRQHandler
    def_irq_handler    Reserved306_IRQHandler
    def_irq_handler    Reserved307_IRQHandler
    def_irq_handler    Reserved308_IRQHandler
    def_irq_handler    Reserved309_IRQHandler
    def_irq_handler    Reserved310_IRQHandler
    def_irq_handler    Reserved311_IRQHandler
    def_irq_handler    Reserved312_IRQHandler
    def_irq_handler    Reserved313_IRQHandler
    def_irq_handler    Reserved314_IRQHandler
    def_irq_handler    Reserved315_IRQHandler
    def_irq_handler    Reserved316_IRQHandler
    def_irq_handler    ADMA_SPI0_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPI1_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPI2_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPI3_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_I2C0_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_I2C1_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_I2C2_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_I2C3_MOD_INT_DriverIRQHandler
    def_irq_handler    Reserved325_IRQHandler
    def_irq_handler    Reserved326_IRQHandler
    def_irq_handler    ADMA_UART0_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_UART1_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_UART2_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_UART3_MOD_INT_DriverIRQHandler
    def_irq_handler    Reserved331_IRQHandler
    def_irq_handler    Reserved332_IRQHandler
    def_irq_handler    Reserved333_IRQHandler
    def_irq_handler    Reserved334_IRQHandler
    def_irq_handler    Reserved335_IRQHandler
    def_irq_handler    Reserved336_IRQHandler
    def_irq_handler    ADMA_FLEXCAN0_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_FLEXCAN1_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_FLEXCAN2_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_FTM0_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_FTM1_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_ADC0_MOD_INT_DriverIRQHandler
    def_irq_handler    Reserved343_IRQHandler
    def_irq_handler    Reserved344_IRQHandler
    def_irq_handler    Reserved345_IRQHandler
    def_irq_handler    Reserved346_IRQHandler
    def_irq_handler    Reserved353_IRQHandler
    def_irq_handler    Reserved354_IRQHandler
    def_irq_handler    Reserved355_IRQHandler
    def_irq_handler    Reserved356_IRQHandler
    def_irq_handler    ADMA_ASRC0_INT1_DriverIRQHandler
    def_irq_handler    ADMA_ASRC0_INT2_DriverIRQHandler
    def_irq_handler    ADMA_GPT0_INT_DriverIRQHandler
    def_irq_handler    ADMA_GPT1_INT_DriverIRQHandler
    def_irq_handler    ADMA_GPT2_INT_DriverIRQHandler
    def_irq_handler    ADMA_GPT3_INT_DriverIRQHandler
    def_irq_handler    Reserved371_IRQHandler
    def_irq_handler    Reserved372_IRQHandler
    def_irq_handler    ADMA_SAI0_INT_DriverIRQHandler
    def_irq_handler    ADMA_SAI1_INT_DriverIRQHandler
    def_irq_handler    ADMA_SAI2_INT_DriverIRQHandler
    def_irq_handler    ADMA_SAI3_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPDIF0_RX_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPDIF0_TX_INT_DriverIRQHandler
    def_irq_handler    Reserved379_IRQHandler
    def_irq_handler    Reserved380_IRQHandler
    def_irq_handler    Reserved381_IRQHandler
    def_irq_handler    Reserved382_IRQHandler
    def_irq_handler    Reserved383_IRQHandler
    def_irq_handler    Reserved384_IRQHandler
    def_irq_handler    Reserved385_IRQHandler
    def_irq_handler    Reserved386_IRQHandler
    def_irq_handler    Reserved403_IRQHandler
    def_irq_handler    Reserved404_IRQHandler
    def_irq_handler    Reserved405_IRQHandler
    def_irq_handler    Reserved406_IRQHandler
    def_irq_handler    Reserved415_IRQHandler
    def_irq_handler    Reserved416_IRQHandler
    def_irq_handler    SECURITY_MU1_A_INT_IRQHandler
    def_irq_handler    SECURITY_MU2_A_INT_IRQHandler
    def_irq_handler    SECURITY_MU3_A_INT_IRQHandler
    def_irq_handler    SECURITY_CAAM_INT0_IRQHandler
    def_irq_handler    SECURITY_CAAM_INT1_IRQHandler
    def_irq_handler    SECURITY_CAAM_INT2_IRQHandler
    def_irq_handler    SECURITY_CAAM_INT3_IRQHandler
    def_irq_handler    SECURITY_CAAM_RTIC_INT_IRQHandler
    def_irq_handler    ADMA_SPDIF0_RX_MOD_INT_DriverIRQHandler
    def_irq_handler    ADMA_SPDIF0_TX_MOD_INT_DriverIRQHandler
    def_irq_handler    Reserved429_IRQHandler
    def_irq_handler    Reserved430_IRQHandler
    def_irq_handler    Reserved431_IRQHandler
    def_irq_handler    Reserved432_IRQHandler
    def_irq_handler    Reserved433_IRQHandler
    def_irq_handler    Reserved434_IRQHandler
    def_irq_handler    Reserved435_IRQHandler
    def_irq_handler    Reserved436_IRQHandler
    def_irq_handler    DB_PERF_CNT_FULL_IRQHandler
    def_irq_handler    V2X_AP_INT0_IRQHandler
    def_irq_handler    V2X_AP_INT1_IRQHandler
    def_irq_handler    V2X_AP_INT2_IRQHandler
    def_irq_handler    V2X_AP_INT3_IRQHandler
    def_irq_handler    V2X_AP_INT4_IRQHandler
    def_irq_handler    V2X_AP_INT5_IRQHandler
    def_irq_handler    V2X_AP_INT6_IRQHandler
    def_irq_handler    V2X_AP_INT7_IRQHandler
    def_irq_handler    V2X_AP_INT8_IRQHandler
    def_irq_handler    V2X_AP_INT9_IRQHandler
    def_irq_handler    V2X_AP_INT10_IRQHandler
    def_irq_handler    V2X_AP_INT11_IRQHandler
    def_irq_handler    Reserved450_IRQHandler
    def_irq_handler    Reserved451_IRQHandler
    def_irq_handler    Reserved452_IRQHandler
    def_irq_handler    Reserved453_IRQHandler
    def_irq_handler    Reserved454_IRQHandler
    def_irq_handler    Reserved455_IRQHandler
    def_irq_handler    Reserved456_IRQHandler
    def_irq_handler    Reserved457_IRQHandler
    def_irq_handler    Reserved458_IRQHandler
    def_irq_handler    Reserved459_IRQHandler
    def_irq_handler    Reserved460_IRQHandler
    def_irq_handler    Reserved461_IRQHandler
    def_irq_handler    M4_INTMUX_SOURCE_TPM_DriverIRQHandler
    def_irq_handler    Reserved463_IRQHandler
    def_irq_handler    Reserved464_IRQHandler
    def_irq_handler    M4_INTMUX_SOURCE_LPIT_DriverIRQHandler
    def_irq_handler    Reserved466_IRQHandler
    def_irq_handler    Reserved467_IRQHandler
    def_irq_handler    M4_INTMUX_SOURCE_LPUART_DriverIRQHandler
    def_irq_handler    Reserved469_IRQHandler
    def_irq_handler    M4_INTMUX_SOURCE_LPI2C_DriverIRQHandler
    def_irq_handler    Reserved471_IRQHandler
    def_irq_handler    Reserved472_IRQHandler
    def_irq_handler    Reserved473_IRQHandler
    def_irq_handler    Reserved474_IRQHandler
    def_irq_handler    Reserved475_IRQHandler
    def_irq_handler    Reserved476_IRQHandler
    def_irq_handler    Reserved477_IRQHandler
    def_irq_handler    Reserved478_IRQHandler
    def_irq_handler    Reserved479_IRQHandler
    def_irq_handler    Reserved480_IRQHandler
    def_irq_handler    Reserved481_IRQHandler
    def_irq_handler    Reserved482_IRQHandler
    def_irq_handler    Reserved483_IRQHandler
    def_irq_handler    Reserved484_IRQHandler
    def_irq_handler    Reserved485_IRQHandler
    def_irq_handler    Reserved486_IRQHandler
    def_irq_handler    Reserved487_IRQHandler
    def_irq_handler    Reserved488_IRQHandler
    def_irq_handler    M4_INTMUX_SOURCE_MU0_A3_DriverIRQHandler
    def_irq_handler    M4_INTMUX_SOURCE_MU0_A2_DriverIRQHandler
    def_irq_handler    M4_INTMUX_SOURCE_MU0_A1_DriverIRQHandler
    def_irq_handler    M4_INTMUX_SOURCE_MU0_A0_DriverIRQHandler

    .end
