/**************************************************************************//**
 * @file     sys_reg.h
 * @version  V1.00
 * @brief    SYS register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __SYS_REG_H__
#define __SYS_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup SYS_CONST SYS Bit Field Definition
    Constant Definitions for SYS Controller
@{ */

#define SYS_PDID_PDID_Pos                (0)                                               /*!< SYS_T::PDID: PDID Position             */
#define SYS_PDID_PDID_Msk                (0xfffffffful << SYS_PDID_PDID_Pos)               /*!< SYS_T::PDID: PDID Mask                 */

#define SYS_RSTSTS_PORF_Pos              (0)                                               /*!< SYS_T::RSTSTS: PORF Position           */
#define SYS_RSTSTS_PORF_Msk              (0x1ul << SYS_RSTSTS_PORF_Pos)                    /*!< SYS_T::RSTSTS: PORF Mask               */

#define SYS_RSTSTS_PINRF_Pos             (1)                                               /*!< SYS_T::RSTSTS: PINRF Position          */
#define SYS_RSTSTS_PINRF_Msk             (0x1ul << SYS_RSTSTS_PINRF_Pos)                   /*!< SYS_T::RSTSTS: PINRF Mask              */

#define SYS_RSTSTS_WDTRF_Pos             (2)                                               /*!< SYS_T::RSTSTS: WDTRF Position          */
#define SYS_RSTSTS_WDTRF_Msk             (0x1ul << SYS_RSTSTS_WDTRF_Pos)                   /*!< SYS_T::RSTSTS: WDTRF Mask              */

#define SYS_RSTSTS_LVRF_Pos              (3)                                               /*!< SYS_T::RSTSTS: LVRF Position           */
#define SYS_RSTSTS_LVRF_Msk              (0x1ul << SYS_RSTSTS_LVRF_Pos)                    /*!< SYS_T::RSTSTS: LVRF Mask               */

#define SYS_RSTSTS_BODRF_Pos             (4)                                               /*!< SYS_T::RSTSTS: BODRF Position          */
#define SYS_RSTSTS_BODRF_Msk             (0x1ul << SYS_RSTSTS_BODRF_Pos)                   /*!< SYS_T::RSTSTS: BODRF Mask              */

#define SYS_RSTSTS_SYSRF_Pos             (5)                                               /*!< SYS_T::RSTSTS: SYSRF Position          */
#define SYS_RSTSTS_SYSRF_Msk             (0x1ul << SYS_RSTSTS_SYSRF_Pos)                   /*!< SYS_T::RSTSTS: SYSRF Mask              */

#define SYS_RSTSTS_PMURF_Pos             (6)                                               /*!< SYS_T::RSTSTS: PMURF Position          */
#define SYS_RSTSTS_PMURF_Msk             (0x1ul << SYS_RSTSTS_PMURF_Pos)                   /*!< SYS_T::RSTSTS: PMURF Mask              */

#define SYS_RSTSTS_CPURF_Pos             (7)                                               /*!< SYS_T::RSTSTS: CPURF Position          */
#define SYS_RSTSTS_CPURF_Msk             (0x1ul << SYS_RSTSTS_CPURF_Pos)                   /*!< SYS_T::RSTSTS: CPURF Mask              */

#define SYS_RSTSTS_CPULKRF_Pos           (8)                                               /*!< SYS_T::RSTSTS: CPULKRF Position        */
#define SYS_RSTSTS_CPULKRF_Msk           (0x1ul << SYS_RSTSTS_CPULKRF_Pos)                 /*!< SYS_T::RSTSTS: CPULKRF Mask            */

#define SYS_RSTSTS_VBATLVRF_Pos          (9)                                               /*!< SYS_T::RSTSTS: VBATLVRF Position        */
#define SYS_RSTSTS_VBATLVRF_Msk          (0x1ul << SYS_RSTSTS_VBATLVRF_Pos)                /*!< SYS_T::RSTSTS: VBATLVRF Mask            */

#define SYS_IPRST0_CHIPRST_Pos           (0)                                               /*!< SYS_T::IPRST0: CHIPRST Position        */
#define SYS_IPRST0_CHIPRST_Msk           (0x1ul << SYS_IPRST0_CHIPRST_Pos)                 /*!< SYS_T::IPRST0: CHIPRST Mask            */

#define SYS_IPRST0_CPURST_Pos            (1)                                               /*!< SYS_T::IPRST0: CPURST Position         */
#define SYS_IPRST0_CPURST_Msk            (0x1ul << SYS_IPRST0_CPURST_Pos)                  /*!< SYS_T::IPRST0: CPURST Mask             */

#define SYS_IPRST0_PDMARST_Pos           (2)                                               /*!< SYS_T::IPRST0: PDMARST Position        */
#define SYS_IPRST0_PDMARST_Msk           (0x1ul << SYS_IPRST0_PDMARST_Pos)                 /*!< SYS_T::IPRST0: PDMARST Mask            */

#define SYS_IPRST0_EBIRST_Pos            (3)                                               /*!< SYS_T::IPRST0: EBIRST Position         */
#define SYS_IPRST0_EBIRST_Msk            (0x1ul << SYS_IPRST0_EBIRST_Pos)                  /*!< SYS_T::IPRST0: EBIRST Mask             */

#define SYS_IPRST0_CRCRST_Pos            (7)                                               /*!< SYS_T::IPRST0: CRCRST Position         */
#define SYS_IPRST0_CRCRST_Msk            (0x1ul << SYS_IPRST0_CRCRST_Pos)                  /*!< SYS_T::IPRST0: CRCRST Mask             */

#define SYS_IPRST0_CRYPTRST_Pos          (12)                                              /*!< SYS_T::IPRST0: CRYPTRST Position       */
#define SYS_IPRST0_CRYPTRST_Msk          (0x1ul << SYS_IPRST0_CRYPTRST_Pos)                /*!< SYS_T::IPRST0: CRYPTRST Mask           */

#define SYS_IPRST1_GPIORST_Pos           (1)                                               /*!< SYS_T::IPRST1: GPIORST Position        */
#define SYS_IPRST1_GPIORST_Msk           (0x1ul << SYS_IPRST1_GPIORST_Pos)                 /*!< SYS_T::IPRST1: GPIORST Mask            */

#define SYS_IPRST1_TMR0RST_Pos           (2)                                               /*!< SYS_T::IPRST1: TMR0RST Position        */
#define SYS_IPRST1_TMR0RST_Msk           (0x1ul << SYS_IPRST1_TMR0RST_Pos)                 /*!< SYS_T::IPRST1: TMR0RST Mask            */

#define SYS_IPRST1_TMR1RST_Pos           (3)                                               /*!< SYS_T::IPRST1: TMR1RST Position        */
#define SYS_IPRST1_TMR1RST_Msk           (0x1ul << SYS_IPRST1_TMR1RST_Pos)                 /*!< SYS_T::IPRST1: TMR1RST Mask            */

#define SYS_IPRST1_TMR2RST_Pos           (4)                                               /*!< SYS_T::IPRST1: TMR2RST Position        */
#define SYS_IPRST1_TMR2RST_Msk           (0x1ul << SYS_IPRST1_TMR2RST_Pos)                 /*!< SYS_T::IPRST1: TMR2RST Mask            */

#define SYS_IPRST1_TMR3RST_Pos           (5)                                               /*!< SYS_T::IPRST1: TMR3RST Position        */
#define SYS_IPRST1_TMR3RST_Msk           (0x1ul << SYS_IPRST1_TMR3RST_Pos)                 /*!< SYS_T::IPRST1: TMR3RST Mask            */

#define SYS_IPRST1_ACMP01RST_Pos         (7)                                               /*!< SYS_T::IPRST1: ACMP01RST Position      */
#define SYS_IPRST1_ACMP01RST_Msk         (0x1ul << SYS_IPRST1_ACMP01RST_Pos)               /*!< SYS_T::IPRST1: ACMP01RST Mask          */

#define SYS_IPRST1_I2C0RST_Pos           (8)                                               /*!< SYS_T::IPRST1: I2C0RST Position        */
#define SYS_IPRST1_I2C0RST_Msk           (0x1ul << SYS_IPRST1_I2C0RST_Pos)                 /*!< SYS_T::IPRST1: I2C0RST Mask            */

#define SYS_IPRST1_I2C1RST_Pos           (9)                                               /*!< SYS_T::IPRST1: I2C1RST Position        */
#define SYS_IPRST1_I2C1RST_Msk           (0x1ul << SYS_IPRST1_I2C1RST_Pos)                 /*!< SYS_T::IPRST1: I2C1RST Mask            */

#define SYS_IPRST1_QSPI0RST_Pos          (12)                                              /*!< SYS_T::IPRST1: QSPI0RST Position       */
#define SYS_IPRST1_QSPI0RST_Msk          (0x1ul << SYS_IPRST1_QSPI0RST_Pos)                /*!< SYS_T::IPRST1: QSPI0RST Mask           */

#define SYS_IPRST1_SPI0RST_Pos           (13)                                              /*!< SYS_T::IPRST1: SPI0RST Position        */
#define SYS_IPRST1_SPI0RST_Msk           (0x1ul << SYS_IPRST1_SPI0RST_Pos)                 /*!< SYS_T::IPRST1: SPI0RST Mask            */

#define SYS_IPRST1_SPI1RST_Pos           (14)                                              /*!< SYS_T::IPRST1: SPI1RST Position        */
#define SYS_IPRST1_SPI1RST_Msk           (0x1ul << SYS_IPRST1_SPI1RST_Pos)                 /*!< SYS_T::IPRST1: SPI1RST Mask            */

#define SYS_IPRST1_UART0RST_Pos          (16)                                              /*!< SYS_T::IPRST1: UART0RST Position       */
#define SYS_IPRST1_UART0RST_Msk          (0x1ul << SYS_IPRST1_UART0RST_Pos)                /*!< SYS_T::IPRST1: UART0RST Mask           */

#define SYS_IPRST1_UART1RST_Pos          (17)                                              /*!< SYS_T::IPRST1: UART1RST Position       */
#define SYS_IPRST1_UART1RST_Msk          (0x1ul << SYS_IPRST1_UART1RST_Pos)                /*!< SYS_T::IPRST1: UART1RST Mask           */

#define SYS_IPRST1_UART2RST_Pos          (18)                                              /*!< SYS_T::IPRST1: UART2RST Position       */
#define SYS_IPRST1_UART2RST_Msk          (0x1ul << SYS_IPRST1_UART2RST_Pos)                /*!< SYS_T::IPRST1: UART2RST Mask           */

#define SYS_IPRST1_UART3RST_Pos          (19)                                              /*!< SYS_T::IPRST1: UART3RST Position       */
#define SYS_IPRST1_UART3RST_Msk          (0x1ul << SYS_IPRST1_UART3RST_Pos)                /*!< SYS_T::IPRST1: UART3RST Mask           */

#define SYS_IPRST1_USBDRST_Pos           (27)                                              /*!< SYS_T::IPRST1: USBDRST Position        */
#define SYS_IPRST1_USBDRST_Msk           (0x1ul << SYS_IPRST1_USBDRST_Pos)                 /*!< SYS_T::IPRST1: USBDRST Mask            */

#define SYS_IPRST1_EADCRST_Pos           (28)                                              /*!< SYS_T::IPRST1: EADCRST Position        */
#define SYS_IPRST1_EADCRST_Msk           (0x1ul << SYS_IPRST1_EADCRST_Pos)                 /*!< SYS_T::IPRST1: EADCRST Mask            */

#define SYS_IPRST2_SC0RST_Pos            (0)                                               /*!< SYS_T::IPRST2: SC0RST Position         */
#define SYS_IPRST2_SC0RST_Msk            (0x1ul << SYS_IPRST2_SC0RST_Pos)                  /*!< SYS_T::IPRST2: SC0RST Mask             */

#define SYS_IPRST2_USCI0RST_Pos          (8)                                               /*!< SYS_T::IPRST2: USCI0RST Position       */
#define SYS_IPRST2_USCI0RST_Msk          (0x1ul << SYS_IPRST2_USCI0RST_Pos)                /*!< SYS_T::IPRST2: USCI0RST Mask           */

#define SYS_IPRST2_USCI1RST_Pos          (9)                                               /*!< SYS_T::IPRST2: USCI1RST Position       */
#define SYS_IPRST2_USCI1RST_Msk          (0x1ul << SYS_IPRST2_USCI1RST_Pos)                /*!< SYS_T::IPRST2: USCI1RST Mask           */

#define SYS_IPRST2_USCI2RST_Pos          (10)                                              /*!< SYS_T::IPRST2: USCI2RST Position       */
#define SYS_IPRST2_USCI2RST_Msk          (0x1ul << SYS_IPRST2_USCI2RST_Pos)                /*!< SYS_T::IPRST2: USCI2RST Mask           */

#define SYS_IPRST2_DACRST_Pos            (12)                                              /*!< SYS_T::IPRST2: DACRST Position         */
#define SYS_IPRST2_DACRST_Msk            (0x1ul << SYS_IPRST2_DACRST_Pos)                  /*!< SYS_T::IPRST2: DACRST Mask             */

#define SYS_IPRST2_LCDRST_Pos            (14)                                              /*!< SYS_T::IPRST2: LCDRST Position         */
#define SYS_IPRST2_LCDRST_Msk            (0x1ul << SYS_IPRST2_LCDRST_Pos)                  /*!< SYS_T::IPRST2: LCDRST Mask             */

#define SYS_IPRST2_TKRST_Pos             (15)                                              /*!< SYS_T::IPRST2: TKRST Position          */
#define SYS_IPRST2_TKRST_Msk             (0x1ul << SYS_IPRST2_TKRST_Pos)                   /*!< SYS_T::IPRST2: TKRST Mask              */

#define SYS_IPRST2_PWM0RST_Pos           (16)                                              /*!< SYS_T::IPRST2: PWM0RST Position        */
#define SYS_IPRST2_PWM0RST_Msk           (0x1ul << SYS_IPRST2_PWM0RST_Pos)                 /*!< SYS_T::IPRST2: PWM0RST Mask            */

#define SYS_IPRST2_PWM1RST_Pos           (17)                                              /*!< SYS_T::IPRST2: PWM1RST Position        */
#define SYS_IPRST2_PWM1RST_Msk           (0x1ul << SYS_IPRST2_PWM1RST_Pos)                 /*!< SYS_T::IPRST2: PWM1RST Mask            */

#define SYS_IPRST2_BPWM0RST_Pos          (18)                                              /*!< SYS_T::IPRST2: BPWM0RST Position       */
#define SYS_IPRST2_BPWM0RST_Msk          (0x1ul << SYS_IPRST2_BPWM0RST_Pos)                /*!< SYS_T::IPRST2: BPWM0RST Mask           */

#define SYS_IPRST2_BPWM1RST_Pos          (19)                                              /*!< SYS_T::IPRST2: BPWM1RST Position       */
#define SYS_IPRST2_BPWM1RST_Msk          (0x1ul << SYS_IPRST2_BPWM1RST_Pos)                /*!< SYS_T::IPRST2: BPWM1RST Mask           */

#define SYS_IPRST2_OPARST_Pos            (30)                                              /*!< SYS_T::IPRST2: OPARST Position         */
#define SYS_IPRST2_OPARST_Msk            (0x1ul << SYS_IPRST2_OPARST_Pos)                  /*!< SYS_T::IPRST2: OPARST Mask             */

#define SYS_IPRST2_PSIORST_Pos           (31)                                              /*!< SYS_T::IPRST2: PSIORST Position        */
#define SYS_IPRST2_PSIORST_Msk           (0x1ul << SYS_IPRST2_PSIORST_Pos)                 /*!< SYS_T::IPRST2: PSIORST Mask            */

#define SYS_BODCTL_BODEN_Pos             (0)                                               /*!< SYS_T::BODCTL: BODEN Position          */
#define SYS_BODCTL_BODEN_Msk             (0x1ul << SYS_BODCTL_BODEN_Pos)                   /*!< SYS_T::BODCTL: BODEN Mask              */

#define SYS_BODCTL_BODRSTEN_Pos          (3)                                               /*!< SYS_T::BODCTL: BODRSTEN Position       */
#define SYS_BODCTL_BODRSTEN_Msk          (0x1ul << SYS_BODCTL_BODRSTEN_Pos)                /*!< SYS_T::BODCTL: BODRSTEN Mask           */

#define SYS_BODCTL_BODIF_Pos             (4)                                               /*!< SYS_T::BODCTL: BODIF Position          */
#define SYS_BODCTL_BODIF_Msk             (0x1ul << SYS_BODCTL_BODIF_Pos)                   /*!< SYS_T::BODCTL: BODIF Mask              */

#define SYS_BODCTL_BODLPM_Pos            (5)                                               /*!< SYS_T::BODCTL: BODLPM Position         */
#define SYS_BODCTL_BODLPM_Msk            (0x1ul << SYS_BODCTL_BODLPM_Pos)                  /*!< SYS_T::BODCTL: BODLPM Mask             */

#define SYS_BODCTL_BODOUT_Pos            (6)                                               /*!< SYS_T::BODCTL: BODOUT Position         */
#define SYS_BODCTL_BODOUT_Msk            (0x1ul << SYS_BODCTL_BODOUT_Pos)                  /*!< SYS_T::BODCTL: BODOUT Mask             */

#define SYS_BODCTL_LVREN_Pos             (7)                                               /*!< SYS_T::BODCTL: LVREN Position          */
#define SYS_BODCTL_LVREN_Msk             (0x1ul << SYS_BODCTL_LVREN_Pos)                   /*!< SYS_T::BODCTL: LVREN Mask              */

#define SYS_BODCTL_BODDGSEL_Pos          (8)                                               /*!< SYS_T::BODCTL: BODDGSEL Position       */
#define SYS_BODCTL_BODDGSEL_Msk          (0x7ul << SYS_BODCTL_BODDGSEL_Pos)                /*!< SYS_T::BODCTL: BODDGSEL Mask           */

#define SYS_BODCTL_LVRDGSEL_Pos          (12)                                              /*!< SYS_T::BODCTL: LVRDGSEL Position       */
#define SYS_BODCTL_LVRDGSEL_Msk          (0x7ul << SYS_BODCTL_LVRDGSEL_Pos)                /*!< SYS_T::BODCTL: LVRDGSEL Mask           */

#define SYS_BODCTL_BODVL_Pos             (16)                                              /*!< SYS_T::BODCTL: BODVL Position          */
#define SYS_BODCTL_BODVL_Msk             (0x7ul << SYS_BODCTL_BODVL_Pos)                   /*!< SYS_T::BODCTL: BODVL Mask              */

#define SYS_IVSCTL_VTEMPEN_Pos           (0)                                               /*!< SYS_T::IVSCTL: VTEMPEN Position        */
#define SYS_IVSCTL_VTEMPEN_Msk           (0x1ul << SYS_IVSCTL_VTEMPEN_Pos)                 /*!< SYS_T::IVSCTL: VTEMPEN Mask            */

#define SYS_IVSCTL_VBATUGEN_Pos          (1)                                               /*!< SYS_T::IVSCTL: VBATUGEN Position       */
#define SYS_IVSCTL_VBATUGEN_Msk          (0x1ul << SYS_IVSCTL_VBATUGEN_Pos)                /*!< SYS_T::IVSCTL: VBATUGEN Mask           */

#define SYS_PORCTL0_PORMASK_Pos          (0)                                               /*!< SYS_T::PORCTL0: PORMASK Position         */
#define SYS_PORCTL0_PORMASK_Msk          (0xfffful << SYS_PORCTL0_PORMASK_Pos)             /*!< SYS_T::PORCTL0: PORMASK Mask             */

#define SYS_VREFCTL_IVRS_Pos             (0)                                               /*!< SYS_T::VREFCTL: IVRS Position          */
#define SYS_VREFCTL_IVRS_Msk             (0x7ul << SYS_VREFCTL_IVRS_Pos)                   /*!< SYS_T::VREFCTL: IVRS Mask              */

#define SYS_VREFCTL_IVREN_Pos            (3)                                               /*!< SYS_T::VREFCTL: IVREN Position         */
#define SYS_VREFCTL_IVREN_Msk            (0x1ul << SYS_VREFCTL_IVREN_Pos)                  /*!< SYS_T::VREFCTL: IVREN Mask             */

#define SYS_VREFCTL_PRELOAD_Pos          (10)                                              /*!< SYS_T::VREFCTL: PRELOAD Position       */
#define SYS_VREFCTL_PRELOAD_Msk          (0x1ul << SYS_VREFCTL_PRELOAD_Pos)                /*!< SYS_T::VREFCTL: PRELOAD Mask           */

#define SYS_GPA_MFPL_PA0MFP_Pos          (0)                                               /*!< SYS_T::GPA_MFPL: PA0MFP Position       */
#define SYS_GPA_MFPL_PA0MFP_Msk          (0xful << SYS_GPA_MFPL_PA0MFP_Pos)                /*!< SYS_T::GPA_MFPL: PA0MFP Mask           */

#define SYS_GPA_MFPL_PA1MFP_Pos          (4)                                               /*!< SYS_T::GPA_MFPL: PA1MFP Position       */
#define SYS_GPA_MFPL_PA1MFP_Msk          (0xful << SYS_GPA_MFPL_PA1MFP_Pos)                /*!< SYS_T::GPA_MFPL: PA1MFP Mask           */

#define SYS_GPA_MFPL_PA2MFP_Pos          (8)                                               /*!< SYS_T::GPA_MFPL: PA2MFP Position       */
#define SYS_GPA_MFPL_PA2MFP_Msk          (0xful << SYS_GPA_MFPL_PA2MFP_Pos)                /*!< SYS_T::GPA_MFPL: PA2MFP Mask           */

#define SYS_GPA_MFPL_PA3MFP_Pos          (12)                                              /*!< SYS_T::GPA_MFPL: PA3MFP Position       */
#define SYS_GPA_MFPL_PA3MFP_Msk          (0xful << SYS_GPA_MFPL_PA3MFP_Pos)                /*!< SYS_T::GPA_MFPL: PA3MFP Mask           */

#define SYS_GPA_MFPL_PA4MFP_Pos          (16)                                              /*!< SYS_T::GPA_MFPL: PA4MFP Position       */
#define SYS_GPA_MFPL_PA4MFP_Msk          (0xful << SYS_GPA_MFPL_PA4MFP_Pos)                /*!< SYS_T::GPA_MFPL: PA4MFP Mask           */

#define SYS_GPA_MFPL_PA5MFP_Pos          (20)                                              /*!< SYS_T::GPA_MFPL: PA5MFP Position       */
#define SYS_GPA_MFPL_PA5MFP_Msk          (0xful << SYS_GPA_MFPL_PA5MFP_Pos)                /*!< SYS_T::GPA_MFPL: PA5MFP Mask           */

#define SYS_GPA_MFPL_PA6MFP_Pos          (24)                                              /*!< SYS_T::GPA_MFPL: PA6MFP Position       */
#define SYS_GPA_MFPL_PA6MFP_Msk          (0xful << SYS_GPA_MFPL_PA6MFP_Pos)                /*!< SYS_T::GPA_MFPL: PA6MFP Mask           */

#define SYS_GPA_MFPL_PA7MFP_Pos          (28)                                              /*!< SYS_T::GPA_MFPL: PA7MFP Position       */
#define SYS_GPA_MFPL_PA7MFP_Msk          (0xful << SYS_GPA_MFPL_PA7MFP_Pos)                /*!< SYS_T::GPA_MFPL: PA7MFP Mask           */

#define SYS_GPA_MFPH_PA8MFP_Pos          (0)                                               /*!< SYS_T::GPA_MFPH: PA8MFP Position       */
#define SYS_GPA_MFPH_PA8MFP_Msk          (0xful << SYS_GPA_MFPH_PA8MFP_Pos)                /*!< SYS_T::GPA_MFPH: PA8MFP Mask           */

#define SYS_GPA_MFPH_PA9MFP_Pos          (4)                                               /*!< SYS_T::GPA_MFPH: PA9MFP Position       */
#define SYS_GPA_MFPH_PA9MFP_Msk          (0xful << SYS_GPA_MFPH_PA9MFP_Pos)                /*!< SYS_T::GPA_MFPH: PA9MFP Mask           */

#define SYS_GPA_MFPH_PA10MFP_Pos         (8)                                               /*!< SYS_T::GPA_MFPH: PA10MFP Position      */
#define SYS_GPA_MFPH_PA10MFP_Msk         (0xful << SYS_GPA_MFPH_PA10MFP_Pos)               /*!< SYS_T::GPA_MFPH: PA10MFP Mask          */

#define SYS_GPA_MFPH_PA11MFP_Pos         (12)                                              /*!< SYS_T::GPA_MFPH: PA11MFP Position      */
#define SYS_GPA_MFPH_PA11MFP_Msk         (0xful << SYS_GPA_MFPH_PA11MFP_Pos)               /*!< SYS_T::GPA_MFPH: PA11MFP Mask          */

#define SYS_GPA_MFPH_PA12MFP_Pos         (16)                                              /*!< SYS_T::GPA_MFPH: PA12MFP Position      */
#define SYS_GPA_MFPH_PA12MFP_Msk         (0xful << SYS_GPA_MFPH_PA12MFP_Pos)               /*!< SYS_T::GPA_MFPH: PA12MFP Mask          */

#define SYS_GPA_MFPH_PA13MFP_Pos         (20)                                              /*!< SYS_T::GPA_MFPH: PA13MFP Position      */
#define SYS_GPA_MFPH_PA13MFP_Msk         (0xful << SYS_GPA_MFPH_PA13MFP_Pos)               /*!< SYS_T::GPA_MFPH: PA13MFP Mask          */

#define SYS_GPA_MFPH_PA14MFP_Pos         (24)                                              /*!< SYS_T::GPA_MFPH: PA14MFP Position      */
#define SYS_GPA_MFPH_PA14MFP_Msk         (0xful << SYS_GPA_MFPH_PA14MFP_Pos)               /*!< SYS_T::GPA_MFPH: PA14MFP Mask          */

#define SYS_GPA_MFPH_PA15MFP_Pos         (28)                                              /*!< SYS_T::GPA_MFPH: PA15MFP Position      */
#define SYS_GPA_MFPH_PA15MFP_Msk         (0xful << SYS_GPA_MFPH_PA15MFP_Pos)               /*!< SYS_T::GPA_MFPH: PA15MFP Mask          */

#define SYS_GPB_MFPL_PB0MFP_Pos          (0)                                               /*!< SYS_T::GPB_MFPL: PB0MFP Position       */
#define SYS_GPB_MFPL_PB0MFP_Msk          (0xful << SYS_GPB_MFPL_PB0MFP_Pos)                /*!< SYS_T::GPB_MFPL: PB0MFP Mask           */

#define SYS_GPB_MFPL_PB1MFP_Pos          (4)                                               /*!< SYS_T::GPB_MFPL: PB1MFP Position       */
#define SYS_GPB_MFPL_PB1MFP_Msk          (0xful << SYS_GPB_MFPL_PB1MFP_Pos)                /*!< SYS_T::GPB_MFPL: PB1MFP Mask           */

#define SYS_GPB_MFPL_PB2MFP_Pos          (8)                                               /*!< SYS_T::GPB_MFPL: PB2MFP Position       */
#define SYS_GPB_MFPL_PB2MFP_Msk          (0xful << SYS_GPB_MFPL_PB2MFP_Pos)                /*!< SYS_T::GPB_MFPL: PB2MFP Mask           */

#define SYS_GPB_MFPL_PB3MFP_Pos          (12)                                              /*!< SYS_T::GPB_MFPL: PB3MFP Position       */
#define SYS_GPB_MFPL_PB3MFP_Msk          (0xful << SYS_GPB_MFPL_PB3MFP_Pos)                /*!< SYS_T::GPB_MFPL: PB3MFP Mask           */

#define SYS_GPB_MFPL_PB4MFP_Pos          (16)                                              /*!< SYS_T::GPB_MFPL: PB4MFP Position       */
#define SYS_GPB_MFPL_PB4MFP_Msk          (0xful << SYS_GPB_MFPL_PB4MFP_Pos)                /*!< SYS_T::GPB_MFPL: PB4MFP Mask           */

#define SYS_GPB_MFPL_PB5MFP_Pos          (20)                                              /*!< SYS_T::GPB_MFPL: PB5MFP Position       */
#define SYS_GPB_MFPL_PB5MFP_Msk          (0xful << SYS_GPB_MFPL_PB5MFP_Pos)                /*!< SYS_T::GPB_MFPL: PB5MFP Mask           */

#define SYS_GPB_MFPL_PB6MFP_Pos          (24)                                              /*!< SYS_T::GPB_MFPL: PB6MFP Position       */
#define SYS_GPB_MFPL_PB6MFP_Msk          (0xful << SYS_GPB_MFPL_PB6MFP_Pos)                /*!< SYS_T::GPB_MFPL: PB6MFP Mask           */

#define SYS_GPB_MFPL_PB7MFP_Pos          (28)                                              /*!< SYS_T::GPB_MFPL: PB7MFP Position       */
#define SYS_GPB_MFPL_PB7MFP_Msk          (0xful << SYS_GPB_MFPL_PB7MFP_Pos)                /*!< SYS_T::GPB_MFPL: PB7MFP Mask           */

#define SYS_GPB_MFPH_PB8MFP_Pos          (0)                                               /*!< SYS_T::GPB_MFPH: PB8MFP Position       */
#define SYS_GPB_MFPH_PB8MFP_Msk          (0xful << SYS_GPB_MFPH_PB8MFP_Pos)                /*!< SYS_T::GPB_MFPH: PB8MFP Mask           */

#define SYS_GPB_MFPH_PB9MFP_Pos          (4)                                               /*!< SYS_T::GPB_MFPH: PB9MFP Position       */
#define SYS_GPB_MFPH_PB9MFP_Msk          (0xful << SYS_GPB_MFPH_PB9MFP_Pos)                /*!< SYS_T::GPB_MFPH: PB9MFP Mask           */

#define SYS_GPB_MFPH_PB10MFP_Pos         (8)                                               /*!< SYS_T::GPB_MFPH: PB10MFP Position      */
#define SYS_GPB_MFPH_PB10MFP_Msk         (0xful << SYS_GPB_MFPH_PB10MFP_Pos)               /*!< SYS_T::GPB_MFPH: PB10MFP Mask          */

#define SYS_GPB_MFPH_PB11MFP_Pos         (12)                                              /*!< SYS_T::GPB_MFPH: PB11MFP Position      */
#define SYS_GPB_MFPH_PB11MFP_Msk         (0xful << SYS_GPB_MFPH_PB11MFP_Pos)               /*!< SYS_T::GPB_MFPH: PB11MFP Mask          */

#define SYS_GPB_MFPH_PB12MFP_Pos         (16)                                              /*!< SYS_T::GPB_MFPH: PB12MFP Position      */
#define SYS_GPB_MFPH_PB12MFP_Msk         (0xful << SYS_GPB_MFPH_PB12MFP_Pos)               /*!< SYS_T::GPB_MFPH: PB12MFP Mask          */

#define SYS_GPB_MFPH_PB13MFP_Pos         (20)                                              /*!< SYS_T::GPB_MFPH: PB13MFP Position      */
#define SYS_GPB_MFPH_PB13MFP_Msk         (0xful << SYS_GPB_MFPH_PB13MFP_Pos)               /*!< SYS_T::GPB_MFPH: PB13MFP Mask          */

#define SYS_GPB_MFPH_PB14MFP_Pos         (24)                                              /*!< SYS_T::GPB_MFPH: PB14MFP Position      */
#define SYS_GPB_MFPH_PB14MFP_Msk         (0xful << SYS_GPB_MFPH_PB14MFP_Pos)               /*!< SYS_T::GPB_MFPH: PB14MFP Mask          */

#define SYS_GPB_MFPH_PB15MFP_Pos         (28)                                              /*!< SYS_T::GPB_MFPH: PB15MFP Position      */
#define SYS_GPB_MFPH_PB15MFP_Msk         (0xful << SYS_GPB_MFPH_PB15MFP_Pos)               /*!< SYS_T::GPB_MFPH: PB15MFP Mask          */

#define SYS_GPC_MFPL_PC0MFP_Pos          (0)                                               /*!< SYS_T::GPC_MFPL: PC0MFP Position       */
#define SYS_GPC_MFPL_PC0MFP_Msk          (0xful << SYS_GPC_MFPL_PC0MFP_Pos)                /*!< SYS_T::GPC_MFPL: PC0MFP Mask           */

#define SYS_GPC_MFPL_PC1MFP_Pos          (4)                                               /*!< SYS_T::GPC_MFPL: PC1MFP Position       */
#define SYS_GPC_MFPL_PC1MFP_Msk          (0xful << SYS_GPC_MFPL_PC1MFP_Pos)                /*!< SYS_T::GPC_MFPL: PC1MFP Mask           */

#define SYS_GPC_MFPL_PC2MFP_Pos          (8)                                               /*!< SYS_T::GPC_MFPL: PC2MFP Position       */
#define SYS_GPC_MFPL_PC2MFP_Msk          (0xful << SYS_GPC_MFPL_PC2MFP_Pos)                /*!< SYS_T::GPC_MFPL: PC2MFP Mask           */

#define SYS_GPC_MFPL_PC3MFP_Pos          (12)                                              /*!< SYS_T::GPC_MFPL: PC3MFP Position       */
#define SYS_GPC_MFPL_PC3MFP_Msk          (0xful << SYS_GPC_MFPL_PC3MFP_Pos)                /*!< SYS_T::GPC_MFPL: PC3MFP Mask           */

#define SYS_GPC_MFPL_PC4MFP_Pos          (16)                                              /*!< SYS_T::GPC_MFPL: PC4MFP Position       */
#define SYS_GPC_MFPL_PC4MFP_Msk          (0xful << SYS_GPC_MFPL_PC4MFP_Pos)                /*!< SYS_T::GPC_MFPL: PC4MFP Mask           */

#define SYS_GPC_MFPL_PC5MFP_Pos          (20)                                              /*!< SYS_T::GPC_MFPL: PC5MFP Position       */
#define SYS_GPC_MFPL_PC5MFP_Msk          (0xful << SYS_GPC_MFPL_PC5MFP_Pos)                /*!< SYS_T::GPC_MFPL: PC5MFP Mask           */

#define SYS_GPC_MFPL_PC6MFP_Pos          (24)                                              /*!< SYS_T::GPC_MFPL: PC6MFP Position       */
#define SYS_GPC_MFPL_PC6MFP_Msk          (0xful << SYS_GPC_MFPL_PC6MFP_Pos)                /*!< SYS_T::GPC_MFPL: PC6MFP Mask           */

#define SYS_GPC_MFPL_PC7MFP_Pos          (28)                                              /*!< SYS_T::GPC_MFPL: PC7MFP Position       */
#define SYS_GPC_MFPL_PC7MFP_Msk          (0xful << SYS_GPC_MFPL_PC7MFP_Pos)                /*!< SYS_T::GPC_MFPL: PC7MFP Mask           */

#define SYS_GPC_MFPH_PC8MFP_Pos          (0)                                               /*!< SYS_T::GPC_MFPH: PC8MFP Position       */
#define SYS_GPC_MFPH_PC8MFP_Msk          (0xful << SYS_GPC_MFPH_PC8MFP_Pos)                /*!< SYS_T::GPC_MFPH: PC8MFP Mask           */

#define SYS_GPC_MFPH_PC9MFP_Pos          (4)                                               /*!< SYS_T::GPC_MFPH: PC9MFP Position       */
#define SYS_GPC_MFPH_PC9MFP_Msk          (0xful << SYS_GPC_MFPH_PC9MFP_Pos)                /*!< SYS_T::GPC_MFPH: PC9MFP Mask           */

#define SYS_GPC_MFPH_PC10MFP_Pos         (8)                                               /*!< SYS_T::GPC_MFPH: PC10MFP Position      */
#define SYS_GPC_MFPH_PC10MFP_Msk         (0xful << SYS_GPC_MFPH_PC10MFP_Pos)               /*!< SYS_T::GPC_MFPH: PC10MFP Mask          */

#define SYS_GPC_MFPH_PC11MFP_Pos         (12)                                              /*!< SYS_T::GPC_MFPH: PC11MFP Position      */
#define SYS_GPC_MFPH_PC11MFP_Msk         (0xful << SYS_GPC_MFPH_PC11MFP_Pos)               /*!< SYS_T::GPC_MFPH: PC11MFP Mask          */

#define SYS_GPC_MFPH_PC12MFP_Pos         (16)                                              /*!< SYS_T::GPC_MFPH: PC12MFP Position      */
#define SYS_GPC_MFPH_PC12MFP_Msk         (0xful << SYS_GPC_MFPH_PC12MFP_Pos)               /*!< SYS_T::GPC_MFPH: PC12MFP Mask          */

#define SYS_GPC_MFPH_PC13MFP_Pos         (20)                                              /*!< SYS_T::GPC_MFPH: PC13MFP Position      */
#define SYS_GPC_MFPH_PC13MFP_Msk         (0xful << SYS_GPC_MFPH_PC13MFP_Pos)               /*!< SYS_T::GPC_MFPH: PC13MFP Mask          */

#define SYS_GPC_MFPH_PC14MFP_Pos         (24)                                              /*!< SYS_T::GPC_MFPH: PC14MFP Position      */
#define SYS_GPC_MFPH_PC14MFP_Msk         (0xful << SYS_GPC_MFPH_PC14MFP_Pos)               /*!< SYS_T::GPC_MFPH: PC14MFP Mask          */

#define SYS_GPC_MFPH_PC15MFP_Pos         (28)                                              /*!< SYS_T::GPC_MFPH: PC15MFP Position      */
#define SYS_GPC_MFPH_PC15MFP_Msk         (0xful << SYS_GPC_MFPH_PC15MFP_Pos)               /*!< SYS_T::GPC_MFPH: PC15MFP Mask          */

#define SYS_GPD_MFPL_PD0MFP_Pos          (0)                                               /*!< SYS_T::GPD_MFPL: PD0MFP Position       */
#define SYS_GPD_MFPL_PD0MFP_Msk          (0xful << SYS_GPD_MFPL_PD0MFP_Pos)                /*!< SYS_T::GPD_MFPL: PD0MFP Mask           */

#define SYS_GPD_MFPL_PD1MFP_Pos          (4)                                               /*!< SYS_T::GPD_MFPL: PD1MFP Position       */
#define SYS_GPD_MFPL_PD1MFP_Msk          (0xful << SYS_GPD_MFPL_PD1MFP_Pos)                /*!< SYS_T::GPD_MFPL: PD1MFP Mask           */

#define SYS_GPD_MFPL_PD2MFP_Pos          (8)                                               /*!< SYS_T::GPD_MFPL: PD2MFP Position       */
#define SYS_GPD_MFPL_PD2MFP_Msk          (0xful << SYS_GPD_MFPL_PD2MFP_Pos)                /*!< SYS_T::GPD_MFPL: PD2MFP Mask           */

#define SYS_GPD_MFPL_PD3MFP_Pos          (12)                                              /*!< SYS_T::GPD_MFPL: PD3MFP Position       */
#define SYS_GPD_MFPL_PD3MFP_Msk          (0xful << SYS_GPD_MFPL_PD3MFP_Pos)                /*!< SYS_T::GPD_MFPL: PD3MFP Mask           */

#define SYS_GPD_MFPL_PD4MFP_Pos          (16)                                              /*!< SYS_T::GPD_MFPL: PD4MFP Position       */
#define SYS_GPD_MFPL_PD4MFP_Msk          (0xful << SYS_GPD_MFPL_PD4MFP_Pos)                /*!< SYS_T::GPD_MFPL: PD4MFP Mask           */

#define SYS_GPD_MFPL_PD5MFP_Pos          (20)                                              /*!< SYS_T::GPD_MFPL: PD5MFP Position       */
#define SYS_GPD_MFPL_PD5MFP_Msk          (0xful << SYS_GPD_MFPL_PD5MFP_Pos)                /*!< SYS_T::GPD_MFPL: PD5MFP Mask           */

#define SYS_GPD_MFPL_PD6MFP_Pos          (24)                                              /*!< SYS_T::GPD_MFPL: PD6MFP Position       */
#define SYS_GPD_MFPL_PD6MFP_Msk          (0xful << SYS_GPD_MFPL_PD6MFP_Pos)                /*!< SYS_T::GPD_MFPL: PD6MFP Mask           */

#define SYS_GPD_MFPL_PD7MFP_Pos          (28)                                              /*!< SYS_T::GPD_MFPL: PD7MFP Position       */
#define SYS_GPD_MFPL_PD7MFP_Msk          (0xful << SYS_GPD_MFPL_PD7MFP_Pos)                /*!< SYS_T::GPD_MFPL: PD7MFP Mask           */

#define SYS_GPD_MFPH_PD8MFP_Pos          (0)                                               /*!< SYS_T::GPD_MFPH: PD8MFP Position       */
#define SYS_GPD_MFPH_PD8MFP_Msk          (0xful << SYS_GPD_MFPH_PD8MFP_Pos)                /*!< SYS_T::GPD_MFPH: PD8MFP Mask           */

#define SYS_GPD_MFPH_PD9MFP_Pos          (4)                                               /*!< SYS_T::GPD_MFPH: PD9MFP Position       */
#define SYS_GPD_MFPH_PD9MFP_Msk          (0xful << SYS_GPD_MFPH_PD9MFP_Pos)                /*!< SYS_T::GPD_MFPH: PD9MFP Mask           */

#define SYS_GPD_MFPH_PD10MFP_Pos         (8)                                               /*!< SYS_T::GPD_MFPH: PD10MFP Position      */
#define SYS_GPD_MFPH_PD10MFP_Msk         (0xful << SYS_GPD_MFPH_PD10MFP_Pos)               /*!< SYS_T::GPD_MFPH: PD10MFP Mask          */

#define SYS_GPD_MFPH_PD11MFP_Pos         (12)                                              /*!< SYS_T::GPD_MFPH: PD11MFP Position      */
#define SYS_GPD_MFPH_PD11MFP_Msk         (0xful << SYS_GPD_MFPH_PD11MFP_Pos)               /*!< SYS_T::GPD_MFPH: PD11MFP Mask          */

#define SYS_GPD_MFPH_PD12MFP_Pos         (16)                                              /*!< SYS_T::GPD_MFPH: PD12MFP Position      */
#define SYS_GPD_MFPH_PD12MFP_Msk         (0xful << SYS_GPD_MFPH_PD12MFP_Pos)               /*!< SYS_T::GPD_MFPH: PD12MFP Mask          */

#define SYS_GPD_MFPH_PD13MFP_Pos         (20)                                              /*!< SYS_T::GPD_MFPH: PD13MFP Position      */
#define SYS_GPD_MFPH_PD13MFP_Msk         (0xful << SYS_GPD_MFPH_PD13MFP_Pos)               /*!< SYS_T::GPD_MFPH: PD13MFP Mask          */

#define SYS_GPD_MFPH_PD14MFP_Pos         (24)                                              /*!< SYS_T::GPD_MFPH: PD14MFP Position      */
#define SYS_GPD_MFPH_PD14MFP_Msk         (0xful << SYS_GPD_MFPH_PD14MFP_Pos)               /*!< SYS_T::GPD_MFPH: PD14MFP Mask          */

#define SYS_GPD_MFPH_PD15MFP_Pos         (28)                                              /*!< SYS_T::GPD_MFPH: PD15MFP Position      */
#define SYS_GPD_MFPH_PD15MFP_Msk         (0xful << SYS_GPD_MFPH_PD15MFP_Pos)               /*!< SYS_T::GPD_MFPH: PD15MFP Mask          */

#define SYS_GPE_MFPL_PE0MFP_Pos          (0)                                               /*!< SYS_T::GPE_MFPL: PE0MFP Position       */
#define SYS_GPE_MFPL_PE0MFP_Msk          (0xful << SYS_GPE_MFPL_PE0MFP_Pos)                /*!< SYS_T::GPE_MFPL: PE0MFP Mask           */

#define SYS_GPE_MFPL_PE1MFP_Pos          (4)                                               /*!< SYS_T::GPE_MFPL: PE1MFP Position       */
#define SYS_GPE_MFPL_PE1MFP_Msk          (0xful << SYS_GPE_MFPL_PE1MFP_Pos)                /*!< SYS_T::GPE_MFPL: PE1MFP Mask           */

#define SYS_GPE_MFPL_PE2MFP_Pos          (8)                                               /*!< SYS_T::GPE_MFPL: PE2MFP Position       */
#define SYS_GPE_MFPL_PE2MFP_Msk          (0xful << SYS_GPE_MFPL_PE2MFP_Pos)                /*!< SYS_T::GPE_MFPL: PE2MFP Mask           */

#define SYS_GPE_MFPL_PE3MFP_Pos          (12)                                              /*!< SYS_T::GPE_MFPL: PE3MFP Position       */
#define SYS_GPE_MFPL_PE3MFP_Msk          (0xful << SYS_GPE_MFPL_PE3MFP_Pos)                /*!< SYS_T::GPE_MFPL: PE3MFP Mask           */

#define SYS_GPE_MFPL_PE4MFP_Pos          (16)                                              /*!< SYS_T::GPE_MFPL: PE4MFP Position       */
#define SYS_GPE_MFPL_PE4MFP_Msk          (0xful << SYS_GPE_MFPL_PE4MFP_Pos)                /*!< SYS_T::GPE_MFPL: PE4MFP Mask           */

#define SYS_GPE_MFPL_PE5MFP_Pos          (20)                                              /*!< SYS_T::GPE_MFPL: PE5MFP Position       */
#define SYS_GPE_MFPL_PE5MFP_Msk          (0xful << SYS_GPE_MFPL_PE5MFP_Pos)                /*!< SYS_T::GPE_MFPL: PE5MFP Mask           */

#define SYS_GPE_MFPL_PE6MFP_Pos          (24)                                              /*!< SYS_T::GPE_MFPL: PE6MFP Position       */
#define SYS_GPE_MFPL_PE6MFP_Msk          (0xful << SYS_GPE_MFPL_PE6MFP_Pos)                /*!< SYS_T::GPE_MFPL: PE6MFP Mask           */

#define SYS_GPE_MFPL_PE7MFP_Pos          (28)                                              /*!< SYS_T::GPE_MFPL: PE7MFP Position       */
#define SYS_GPE_MFPL_PE7MFP_Msk          (0xful << SYS_GPE_MFPL_PE7MFP_Pos)                /*!< SYS_T::GPE_MFPL: PE7MFP Mask           */

#define SYS_GPE_MFPH_PE8MFP_Pos          (0)                                               /*!< SYS_T::GPE_MFPH: PE8MFP Position       */
#define SYS_GPE_MFPH_PE8MFP_Msk          (0xful << SYS_GPE_MFPH_PE8MFP_Pos)                /*!< SYS_T::GPE_MFPH: PE8MFP Mask           */

#define SYS_GPE_MFPH_PE9MFP_Pos          (4)                                               /*!< SYS_T::GPE_MFPH: PE9MFP Position       */
#define SYS_GPE_MFPH_PE9MFP_Msk          (0xful << SYS_GPE_MFPH_PE9MFP_Pos)                /*!< SYS_T::GPE_MFPH: PE9MFP Mask           */

#define SYS_GPE_MFPH_PE10MFP_Pos         (8)                                               /*!< SYS_T::GPE_MFPH: PE10MFP Position      */
#define SYS_GPE_MFPH_PE10MFP_Msk         (0xful << SYS_GPE_MFPH_PE10MFP_Pos)               /*!< SYS_T::GPE_MFPH: PE10MFP Mask          */

#define SYS_GPE_MFPH_PE11MFP_Pos         (12)                                              /*!< SYS_T::GPE_MFPH: PE11MFP Position      */
#define SYS_GPE_MFPH_PE11MFP_Msk         (0xful << SYS_GPE_MFPH_PE11MFP_Pos)               /*!< SYS_T::GPE_MFPH: PE11MFP Mask          */

#define SYS_GPE_MFPH_PE12MFP_Pos         (16)                                              /*!< SYS_T::GPE_MFPH: PE12MFP Position      */
#define SYS_GPE_MFPH_PE12MFP_Msk         (0xful << SYS_GPE_MFPH_PE12MFP_Pos)               /*!< SYS_T::GPE_MFPH: PE12MFP Mask          */

#define SYS_GPE_MFPH_PE13MFP_Pos         (20)                                              /*!< SYS_T::GPE_MFPH: PE13MFP Position      */
#define SYS_GPE_MFPH_PE13MFP_Msk         (0xful << SYS_GPE_MFPH_PE13MFP_Pos)               /*!< SYS_T::GPE_MFPH: PE13MFP Mask          */

#define SYS_GPE_MFPH_PE14MFP_Pos        (24)                                              /*!< SYS_T::GPE_MFPH: PE14_MFP Position     */
#define SYS_GPE_MFPH_PE14MFP_Msk        (0xful << SYS_GPE_MFPH_PE14MFP_Pos)              /*!< SYS_T::GPE_MFPH: PE14_MFP Mask         */

#define SYS_GPE_MFPH_PE15MFP_Pos        (28)                                              /*!< SYS_T::GPE_MFPH: PE15_MFP Position     */
#define SYS_GPE_MFPH_PE15MFP_Msk        (0xful << SYS_GPE_MFPH_PE15MFP_Pos)              /*!< SYS_T::GPE_MFPH: PE15_MFP Mask         */

#define SYS_GPF_MFPL_PF0MFP_Pos          (0)                                               /*!< SYS_T::GPF_MFPL: PF0MFP Position       */
#define SYS_GPF_MFPL_PF0MFP_Msk          (0xful << SYS_GPF_MFPL_PF0MFP_Pos)                /*!< SYS_T::GPF_MFPL: PF0MFP Mask           */

#define SYS_GPF_MFPL_PF1MFP_Pos          (4)                                               /*!< SYS_T::GPF_MFPL: PF1MFP Position       */
#define SYS_GPF_MFPL_PF1MFP_Msk          (0xful << SYS_GPF_MFPL_PF1MFP_Pos)                /*!< SYS_T::GPF_MFPL: PF1MFP Mask           */

#define SYS_GPF_MFPL_PF2MFP_Pos          (8)                                               /*!< SYS_T::GPF_MFPL: PF2MFP Position       */
#define SYS_GPF_MFPL_PF2MFP_Msk          (0xful << SYS_GPF_MFPL_PF2MFP_Pos)                /*!< SYS_T::GPF_MFPL: PF2MFP Mask           */

#define SYS_GPF_MFPL_PF3MFP_Pos          (12)                                              /*!< SYS_T::GPF_MFPL: PF3MFP Position       */
#define SYS_GPF_MFPL_PF3MFP_Msk          (0xful << SYS_GPF_MFPL_PF3MFP_Pos)                /*!< SYS_T::GPF_MFPL: PF3MFP Mask           */

#define SYS_GPF_MFPL_PF4MFP_Pos          (16)                                              /*!< SYS_T::GPF_MFPL: PF4MFP Position       */
#define SYS_GPF_MFPL_PF4MFP_Msk          (0xful << SYS_GPF_MFPL_PF4MFP_Pos)                /*!< SYS_T::GPF_MFPL: PF4MFP Mask           */

#define SYS_GPF_MFPL_PF5MFP_Pos          (20)                                              /*!< SYS_T::GPF_MFPL: PF5MFP Position       */
#define SYS_GPF_MFPL_PF5MFP_Msk          (0xful << SYS_GPF_MFPL_PF5MFP_Pos)                /*!< SYS_T::GPF_MFPL: PF5MFP Mask           */

#define SYS_GPF_MFPL_PF6MFP_Pos          (24)                                              /*!< SYS_T::GPF_MFPL: PF6MFP Position       */
#define SYS_GPF_MFPL_PF6MFP_Msk          (0xful << SYS_GPF_MFPL_PF6MFP_Pos)                /*!< SYS_T::GPF_MFPL: PF6MFP Mask           */

#define SYS_GPF_MFPL_PF7MFP_Pos          (28)                                              /*!< SYS_T::GPF_MFPL: PF7MFP Position       */
#define SYS_GPF_MFPL_PF7MFP_Msk          (0xful << SYS_GPF_MFPL_PF7MFP_Pos)                /*!< SYS_T::GPF_MFPL: PF7MFP Mask           */

#define SYS_GPF_MFPH_PF8MFP_Pos          (0)                                               /*!< SYS_T::GPF_MFPH: PF8MFP Position       */
#define SYS_GPF_MFPH_PF8MFP_Msk          (0xful << SYS_GPF_MFPH_PF8MFP_Pos)                /*!< SYS_T::GPF_MFPH: PF8MFP Mask           */

#define SYS_GPF_MFPH_PF9MFP_Pos          (4)                                               /*!< SYS_T::GPF_MFPH: PF9MFP Position       */
#define SYS_GPF_MFPH_PF9MFP_Msk          (0xful << SYS_GPF_MFPH_PF9MFP_Pos)                /*!< SYS_T::GPF_MFPH: PF9MFP Mask           */

#define SYS_GPF_MFPH_PF10MFP_Pos         (8)                                               /*!< SYS_T::GPF_MFPH: PF10MFP Position      */
#define SYS_GPF_MFPH_PF10MFP_Msk         (0xful << SYS_GPF_MFPH_PF10MFP_Pos)               /*!< SYS_T::GPF_MFPH: PF10MFP Mask          */

#define SYS_GPF_MFPH_PF11MFP_Pos         (12)                                              /*!< SYS_T::GPF_MFPH: PF11MFP Position      */
#define SYS_GPF_MFPH_PF11MFP_Msk         (0xful << SYS_GPF_MFPH_PF11MFP_Pos)               /*!< SYS_T::GPF_MFPH: PF11MFP Mask          */

#define SYS_GPF_MFPH_PF12MFP_Pos         (16)                                              /*!< SYS_T::GPF_MFPH: PF12MFP Position      */
#define SYS_GPF_MFPH_PF12MFP_Msk         (0xful << SYS_GPF_MFPH_PF12MFP_Pos)               /*!< SYS_T::GPF_MFPH: PF12MFP Mask          */

#define SYS_GPF_MFPH_PF13MFP_Pos         (20)                                              /*!< SYS_T::GPF_MFPH: PF13MFP Position      */
#define SYS_GPF_MFPH_PF13MFP_Msk         (0xful << SYS_GPF_MFPH_PF13MFP_Pos)               /*!< SYS_T::GPF_MFPH: PF13MFP Mask          */

#define SYS_GPF_MFPH_PF14MFP_Pos         (24)                                              /*!< SYS_T::GPF_MFPH: PF14MFP Position      */
#define SYS_GPF_MFPH_PF14MFP_Msk         (0xful << SYS_GPF_MFPH_PF14MFP_Pos)               /*!< SYS_T::GPF_MFPH: PF14MFP Mask          */

#define SYS_GPF_MFPH_PF15MFP_Pos         (28)                                              /*!< SYS_T::GPF_MFPH: PF15MFP Position      */
#define SYS_GPF_MFPH_PF15MFP_Msk         (0xful << SYS_GPF_MFPH_PF15MFP_Pos)               /*!< SYS_T::GPF_MFPH: PF15MFP Mask          */

#define SYS_GPA_MFOS_MFOS0_Pos           (0)                                               /*!< SYS_T::GPA_MFOS: MFOS0 Position        */
#define SYS_GPA_MFOS_MFOS0_Msk           (0x1ul << SYS_GPA_MFOS_MFOS0_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS0 Mask            */

#define SYS_GPA_MFOS_MFOS1_Pos           (1)                                               /*!< SYS_T::GPA_MFOS: MFOS1 Position        */
#define SYS_GPA_MFOS_MFOS1_Msk           (0x1ul << SYS_GPA_MFOS_MFOS1_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS1 Mask            */

#define SYS_GPA_MFOS_MFOS2_Pos           (2)                                               /*!< SYS_T::GPA_MFOS: MFOS2 Position        */
#define SYS_GPA_MFOS_MFOS2_Msk           (0x1ul << SYS_GPA_MFOS_MFOS2_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS2 Mask            */

#define SYS_GPA_MFOS_MFOS3_Pos           (3)                                               /*!< SYS_T::GPA_MFOS: MFOS3 Position        */
#define SYS_GPA_MFOS_MFOS3_Msk           (0x1ul << SYS_GPA_MFOS_MFOS3_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS3 Mask            */

#define SYS_GPA_MFOS_MFOS4_Pos           (4)                                               /*!< SYS_T::GPA_MFOS: MFOS4 Position        */
#define SYS_GPA_MFOS_MFOS4_Msk           (0x1ul << SYS_GPA_MFOS_MFOS4_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS4 Mask            */

#define SYS_GPA_MFOS_MFOS5_Pos           (5)                                               /*!< SYS_T::GPA_MFOS: MFOS5 Position        */
#define SYS_GPA_MFOS_MFOS5_Msk           (0x1ul << SYS_GPA_MFOS_MFOS5_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS5 Mask            */

#define SYS_GPA_MFOS_MFOS6_Pos           (6)                                               /*!< SYS_T::GPA_MFOS: MFOS6 Position        */
#define SYS_GPA_MFOS_MFOS6_Msk           (0x1ul << SYS_GPA_MFOS_MFOS6_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS6 Mask            */

#define SYS_GPA_MFOS_MFOS7_Pos           (7)                                               /*!< SYS_T::GPA_MFOS: MFOS7 Position        */
#define SYS_GPA_MFOS_MFOS7_Msk           (0x1ul << SYS_GPA_MFOS_MFOS7_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS7 Mask            */

#define SYS_GPA_MFOS_MFOS8_Pos           (8)                                               /*!< SYS_T::GPA_MFOS: MFOS8 Position        */
#define SYS_GPA_MFOS_MFOS8_Msk           (0x1ul << SYS_GPA_MFOS_MFOS8_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS8 Mask            */

#define SYS_GPA_MFOS_MFOS9_Pos           (9)                                               /*!< SYS_T::GPA_MFOS: MFOS9 Position        */
#define SYS_GPA_MFOS_MFOS9_Msk           (0x1ul << SYS_GPA_MFOS_MFOS9_Pos)                 /*!< SYS_T::GPA_MFOS: MFOS9 Mask            */

#define SYS_GPA_MFOS_MFOS10_Pos          (10)                                              /*!< SYS_T::GPA_MFOS: MFOS10 Position       */
#define SYS_GPA_MFOS_MFOS10_Msk          (0x1ul << SYS_GPA_MFOS_MFOS10_Pos)                /*!< SYS_T::GPA_MFOS: MFOS10 Mask           */

#define SYS_GPA_MFOS_MFOS11_Pos          (11)                                              /*!< SYS_T::GPA_MFOS: MFOS11 Position       */
#define SYS_GPA_MFOS_MFOS11_Msk          (0x1ul << SYS_GPA_MFOS_MFOS11_Pos)                /*!< SYS_T::GPA_MFOS: MFOS11 Mask           */

#define SYS_GPA_MFOS_MFOS12_Pos          (12)                                              /*!< SYS_T::GPA_MFOS: MFOS12 Position       */
#define SYS_GPA_MFOS_MFOS12_Msk          (0x1ul << SYS_GPA_MFOS_MFOS12_Pos)                /*!< SYS_T::GPA_MFOS: MFOS12 Mask           */

#define SYS_GPA_MFOS_MFOS13_Pos          (13)                                              /*!< SYS_T::GPA_MFOS: MFOS13 Position       */
#define SYS_GPA_MFOS_MFOS13_Msk          (0x1ul << SYS_GPA_MFOS_MFOS13_Pos)                /*!< SYS_T::GPA_MFOS: MFOS13 Mask           */

#define SYS_GPA_MFOS_MFOS14_Pos          (14)                                              /*!< SYS_T::GPA_MFOS: MFOS14 Position       */
#define SYS_GPA_MFOS_MFOS14_Msk          (0x1ul << SYS_GPA_MFOS_MFOS14_Pos)                /*!< SYS_T::GPA_MFOS: MFOS14 Mask           */

#define SYS_GPA_MFOS_MFOS15_Pos          (15)                                              /*!< SYS_T::GPA_MFOS: MFOS15 Position       */
#define SYS_GPA_MFOS_MFOS15_Msk          (0x1ul << SYS_GPA_MFOS_MFOS15_Pos)                /*!< SYS_T::GPA_MFOS: MFOS15 Mask           */

#define SYS_GPB_MFOS_MFOS0_Pos           (0)                                               /*!< SYS_T::GPB_MFOS: MFOS0 Position        */
#define SYS_GPB_MFOS_MFOS0_Msk           (0x1ul << SYS_GPB_MFOS_MFOS0_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS0 Mask            */

#define SYS_GPB_MFOS_MFOS1_Pos           (1)                                               /*!< SYS_T::GPB_MFOS: MFOS1 Position        */
#define SYS_GPB_MFOS_MFOS1_Msk           (0x1ul << SYS_GPB_MFOS_MFOS1_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS1 Mask            */

#define SYS_GPB_MFOS_MFOS2_Pos           (2)                                               /*!< SYS_T::GPB_MFOS: MFOS2 Position        */
#define SYS_GPB_MFOS_MFOS2_Msk           (0x1ul << SYS_GPB_MFOS_MFOS2_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS2 Mask            */

#define SYS_GPB_MFOS_MFOS3_Pos           (3)                                               /*!< SYS_T::GPB_MFOS: MFOS3 Position        */
#define SYS_GPB_MFOS_MFOS3_Msk           (0x1ul << SYS_GPB_MFOS_MFOS3_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS3 Mask            */

#define SYS_GPB_MFOS_MFOS4_Pos           (4)                                               /*!< SYS_T::GPB_MFOS: MFOS4 Position        */
#define SYS_GPB_MFOS_MFOS4_Msk           (0x1ul << SYS_GPB_MFOS_MFOS4_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS4 Mask            */

#define SYS_GPB_MFOS_MFOS5_Pos           (5)                                               /*!< SYS_T::GPB_MFOS: MFOS5 Position        */
#define SYS_GPB_MFOS_MFOS5_Msk           (0x1ul << SYS_GPB_MFOS_MFOS5_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS5 Mask            */

#define SYS_GPB_MFOS_MFOS6_Pos           (6)                                               /*!< SYS_T::GPB_MFOS: MFOS6 Position        */
#define SYS_GPB_MFOS_MFOS6_Msk           (0x1ul << SYS_GPB_MFOS_MFOS6_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS6 Mask            */

#define SYS_GPB_MFOS_MFOS7_Pos           (7)                                               /*!< SYS_T::GPB_MFOS: MFOS7 Position        */
#define SYS_GPB_MFOS_MFOS7_Msk           (0x1ul << SYS_GPB_MFOS_MFOS7_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS7 Mask            */

#define SYS_GPB_MFOS_MFOS8_Pos           (8)                                               /*!< SYS_T::GPB_MFOS: MFOS8 Position        */
#define SYS_GPB_MFOS_MFOS8_Msk           (0x1ul << SYS_GPB_MFOS_MFOS8_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS8 Mask            */

#define SYS_GPB_MFOS_MFOS9_Pos           (9)                                               /*!< SYS_T::GPB_MFOS: MFOS9 Position        */
#define SYS_GPB_MFOS_MFOS9_Msk           (0x1ul << SYS_GPB_MFOS_MFOS9_Pos)                 /*!< SYS_T::GPB_MFOS: MFOS9 Mask            */

#define SYS_GPB_MFOS_MFOS10_Pos          (10)                                              /*!< SYS_T::GPB_MFOS: MFOS10 Position       */
#define SYS_GPB_MFOS_MFOS10_Msk          (0x1ul << SYS_GPB_MFOS_MFOS10_Pos)                /*!< SYS_T::GPB_MFOS: MFOS10 Mask           */

#define SYS_GPB_MFOS_MFOS11_Pos          (11)                                              /*!< SYS_T::GPB_MFOS: MFOS11 Position       */
#define SYS_GPB_MFOS_MFOS11_Msk          (0x1ul << SYS_GPB_MFOS_MFOS11_Pos)                /*!< SYS_T::GPB_MFOS: MFOS11 Mask           */

#define SYS_GPB_MFOS_MFOS12_Pos          (12)                                              /*!< SYS_T::GPB_MFOS: MFOS12 Position       */
#define SYS_GPB_MFOS_MFOS12_Msk          (0x1ul << SYS_GPB_MFOS_MFOS12_Pos)                /*!< SYS_T::GPB_MFOS: MFOS12 Mask           */

#define SYS_GPB_MFOS_MFOS13_Pos          (13)                                              /*!< SYS_T::GPB_MFOS: MFOS13 Position       */
#define SYS_GPB_MFOS_MFOS13_Msk          (0x1ul << SYS_GPB_MFOS_MFOS13_Pos)                /*!< SYS_T::GPB_MFOS: MFOS13 Mask           */

#define SYS_GPB_MFOS_MFOS14_Pos          (14)                                              /*!< SYS_T::GPB_MFOS: MFOS14 Position       */
#define SYS_GPB_MFOS_MFOS14_Msk          (0x1ul << SYS_GPB_MFOS_MFOS14_Pos)                /*!< SYS_T::GPB_MFOS: MFOS14 Mask           */

#define SYS_GPB_MFOS_MFOS15_Pos          (15)                                              /*!< SYS_T::GPB_MFOS: MFOS15 Position       */
#define SYS_GPB_MFOS_MFOS15_Msk          (0x1ul << SYS_GPB_MFOS_MFOS15_Pos)                /*!< SYS_T::GPB_MFOS: MFOS15 Mask           */

#define SYS_GPC_MFOS_MFOS0_Pos           (0)                                               /*!< SYS_T::GPC_MFOS: MFOS0 Position        */
#define SYS_GPC_MFOS_MFOS0_Msk           (0x1ul << SYS_GPC_MFOS_MFOS0_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS0 Mask            */

#define SYS_GPC_MFOS_MFOS1_Pos           (1)                                               /*!< SYS_T::GPC_MFOS: MFOS1 Position        */
#define SYS_GPC_MFOS_MFOS1_Msk           (0x1ul << SYS_GPC_MFOS_MFOS1_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS1 Mask            */

#define SYS_GPC_MFOS_MFOS2_Pos           (2)                                               /*!< SYS_T::GPC_MFOS: MFOS2 Position        */
#define SYS_GPC_MFOS_MFOS2_Msk           (0x1ul << SYS_GPC_MFOS_MFOS2_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS2 Mask            */

#define SYS_GPC_MFOS_MFOS3_Pos           (3)                                               /*!< SYS_T::GPC_MFOS: MFOS3 Position        */
#define SYS_GPC_MFOS_MFOS3_Msk           (0x1ul << SYS_GPC_MFOS_MFOS3_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS3 Mask            */

#define SYS_GPC_MFOS_MFOS4_Pos           (4)                                               /*!< SYS_T::GPC_MFOS: MFOS4 Position        */
#define SYS_GPC_MFOS_MFOS4_Msk           (0x1ul << SYS_GPC_MFOS_MFOS4_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS4 Mask            */

#define SYS_GPC_MFOS_MFOS5_Pos           (5)                                               /*!< SYS_T::GPC_MFOS: MFOS5 Position        */
#define SYS_GPC_MFOS_MFOS5_Msk           (0x1ul << SYS_GPC_MFOS_MFOS5_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS5 Mask            */

#define SYS_GPC_MFOS_MFOS6_Pos           (6)                                               /*!< SYS_T::GPC_MFOS: MFOS6 Position        */
#define SYS_GPC_MFOS_MFOS6_Msk           (0x1ul << SYS_GPC_MFOS_MFOS6_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS6 Mask            */

#define SYS_GPC_MFOS_MFOS7_Pos           (7)                                               /*!< SYS_T::GPC_MFOS: MFOS7 Position        */
#define SYS_GPC_MFOS_MFOS7_Msk           (0x1ul << SYS_GPC_MFOS_MFOS7_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS7 Mask            */

#define SYS_GPC_MFOS_MFOS8_Pos           (8)                                               /*!< SYS_T::GPC_MFOS: MFOS8 Position        */
#define SYS_GPC_MFOS_MFOS8_Msk           (0x1ul << SYS_GPC_MFOS_MFOS8_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS8 Mask            */

#define SYS_GPC_MFOS_MFOS9_Pos           (9)                                               /*!< SYS_T::GPC_MFOS: MFOS9 Position        */
#define SYS_GPC_MFOS_MFOS9_Msk           (0x1ul << SYS_GPC_MFOS_MFOS9_Pos)                 /*!< SYS_T::GPC_MFOS: MFOS9 Mask            */

#define SYS_GPC_MFOS_MFOS10_Pos          (10)                                              /*!< SYS_T::GPC_MFOS: MFOS10 Position       */
#define SYS_GPC_MFOS_MFOS10_Msk          (0x1ul << SYS_GPC_MFOS_MFOS10_Pos)                /*!< SYS_T::GPC_MFOS: MFOS10 Mask           */

#define SYS_GPC_MFOS_MFOS11_Pos          (11)                                              /*!< SYS_T::GPC_MFOS: MFOS11 Position       */
#define SYS_GPC_MFOS_MFOS11_Msk          (0x1ul << SYS_GPC_MFOS_MFOS11_Pos)                /*!< SYS_T::GPC_MFOS: MFOS11 Mask           */

#define SYS_GPC_MFOS_MFOS12_Pos          (12)                                              /*!< SYS_T::GPC_MFOS: MFOS12 Position       */
#define SYS_GPC_MFOS_MFOS12_Msk          (0x1ul << SYS_GPC_MFOS_MFOS12_Pos)                /*!< SYS_T::GPC_MFOS: MFOS12 Mask           */

#define SYS_GPC_MFOS_MFOS13_Pos          (13)                                              /*!< SYS_T::GPC_MFOS: MFOS13 Position       */
#define SYS_GPC_MFOS_MFOS13_Msk          (0x1ul << SYS_GPC_MFOS_MFOS13_Pos)                /*!< SYS_T::GPC_MFOS: MFOS13 Mask           */

#define SYS_GPC_MFOS_MFOS14_Pos          (14)                                              /*!< SYS_T::GPC_MFOS: MFOS14 Position       */
#define SYS_GPC_MFOS_MFOS14_Msk          (0x1ul << SYS_GPC_MFOS_MFOS14_Pos)                /*!< SYS_T::GPC_MFOS: MFOS14 Mask           */

#define SYS_GPC_MFOS_MFOS15_Pos          (15)                                              /*!< SYS_T::GPC_MFOS: MFOS15 Position       */
#define SYS_GPC_MFOS_MFOS15_Msk          (0x1ul << SYS_GPC_MFOS_MFOS15_Pos)                /*!< SYS_T::GPC_MFOS: MFOS15 Mask           */

#define SYS_GPD_MFOS_MFOS0_Pos           (0)                                               /*!< SYS_T::GPD_MFOS: MFOS0 Position        */
#define SYS_GPD_MFOS_MFOS0_Msk           (0x1ul << SYS_GPD_MFOS_MFOS0_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS0 Mask            */

#define SYS_GPD_MFOS_MFOS1_Pos           (1)                                               /*!< SYS_T::GPD_MFOS: MFOS1 Position        */
#define SYS_GPD_MFOS_MFOS1_Msk           (0x1ul << SYS_GPD_MFOS_MFOS1_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS1 Mask            */

#define SYS_GPD_MFOS_MFOS2_Pos           (2)                                               /*!< SYS_T::GPD_MFOS: MFOS2 Position        */
#define SYS_GPD_MFOS_MFOS2_Msk           (0x1ul << SYS_GPD_MFOS_MFOS2_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS2 Mask            */

#define SYS_GPD_MFOS_MFOS3_Pos           (3)                                               /*!< SYS_T::GPD_MFOS: MFOS3 Position        */
#define SYS_GPD_MFOS_MFOS3_Msk           (0x1ul << SYS_GPD_MFOS_MFOS3_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS3 Mask            */

#define SYS_GPD_MFOS_MFOS4_Pos           (4)                                               /*!< SYS_T::GPD_MFOS: MFOS4 Position        */
#define SYS_GPD_MFOS_MFOS4_Msk           (0x1ul << SYS_GPD_MFOS_MFOS4_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS4 Mask            */

#define SYS_GPD_MFOS_MFOS5_Pos           (5)                                               /*!< SYS_T::GPD_MFOS: MFOS5 Position        */
#define SYS_GPD_MFOS_MFOS5_Msk           (0x1ul << SYS_GPD_MFOS_MFOS5_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS5 Mask            */

#define SYS_GPD_MFOS_MFOS6_Pos           (6)                                               /*!< SYS_T::GPD_MFOS: MFOS6 Position        */
#define SYS_GPD_MFOS_MFOS6_Msk           (0x1ul << SYS_GPD_MFOS_MFOS6_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS6 Mask            */

#define SYS_GPD_MFOS_MFOS7_Pos           (7)                                               /*!< SYS_T::GPD_MFOS: MFOS7 Position        */
#define SYS_GPD_MFOS_MFOS7_Msk           (0x1ul << SYS_GPD_MFOS_MFOS7_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS7 Mask            */

#define SYS_GPD_MFOS_MFOS8_Pos           (8)                                               /*!< SYS_T::GPD_MFOS: MFOS8 Position        */
#define SYS_GPD_MFOS_MFOS8_Msk           (0x1ul << SYS_GPD_MFOS_MFOS8_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS8 Mask            */

#define SYS_GPD_MFOS_MFOS9_Pos           (9)                                               /*!< SYS_T::GPD_MFOS: MFOS9 Position        */
#define SYS_GPD_MFOS_MFOS9_Msk           (0x1ul << SYS_GPD_MFOS_MFOS9_Pos)                 /*!< SYS_T::GPD_MFOS: MFOS9 Mask            */

#define SYS_GPD_MFOS_MFOS10_Pos          (10)                                              /*!< SYS_T::GPD_MFOS: MFOS10 Position       */
#define SYS_GPD_MFOS_MFOS10_Msk          (0x1ul << SYS_GPD_MFOS_MFOS10_Pos)                /*!< SYS_T::GPD_MFOS: MFOS10 Mask           */

#define SYS_GPD_MFOS_MFOS11_Pos          (11)                                              /*!< SYS_T::GPD_MFOS: MFOS11 Position       */
#define SYS_GPD_MFOS_MFOS11_Msk          (0x1ul << SYS_GPD_MFOS_MFOS11_Pos)                /*!< SYS_T::GPD_MFOS: MFOS11 Mask           */

#define SYS_GPD_MFOS_MFOS12_Pos          (12)                                              /*!< SYS_T::GPD_MFOS: MFOS12 Position       */
#define SYS_GPD_MFOS_MFOS12_Msk          (0x1ul << SYS_GPD_MFOS_MFOS12_Pos)                /*!< SYS_T::GPD_MFOS: MFOS12 Mask           */

#define SYS_GPD_MFOS_MFOS13_Pos          (13)                                              /*!< SYS_T::GPD_MFOS: MFOS13 Position       */
#define SYS_GPD_MFOS_MFOS13_Msk          (0x1ul << SYS_GPD_MFOS_MFOS13_Pos)                /*!< SYS_T::GPD_MFOS: MFOS13 Mask           */

#define SYS_GPD_MFOS_MFOS14_Pos          (14)                                              /*!< SYS_T::GPD_MFOS: MFOS14 Position       */
#define SYS_GPD_MFOS_MFOS14_Msk          (0x1ul << SYS_GPD_MFOS_MFOS14_Pos)                /*!< SYS_T::GPD_MFOS: MFOS14 Mask           */

#define SYS_GPD_MFOS_MFOS15_Pos          (15)                                              /*!< SYS_T::GPD_MFOS: MFOS15 Position       */
#define SYS_GPD_MFOS_MFOS15_Msk          (0x1ul << SYS_GPD_MFOS_MFOS15_Pos)                /*!< SYS_T::GPD_MFOS: MFOS15 Mask           */

#define SYS_GPE_MFOS_MFOS0_Pos           (0)                                               /*!< SYS_T::GPE_MFOS: MFOS0 Position        */
#define SYS_GPE_MFOS_MFOS0_Msk           (0x1ul << SYS_GPE_MFOS_MFOS0_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS0 Mask            */

#define SYS_GPE_MFOS_MFOS1_Pos           (1)                                               /*!< SYS_T::GPE_MFOS: MFOS1 Position        */
#define SYS_GPE_MFOS_MFOS1_Msk           (0x1ul << SYS_GPE_MFOS_MFOS1_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS1 Mask            */

#define SYS_GPE_MFOS_MFOS2_Pos           (2)                                               /*!< SYS_T::GPE_MFOS: MFOS2 Position        */
#define SYS_GPE_MFOS_MFOS2_Msk           (0x1ul << SYS_GPE_MFOS_MFOS2_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS2 Mask            */

#define SYS_GPE_MFOS_MFOS3_Pos           (3)                                               /*!< SYS_T::GPE_MFOS: MFOS3 Position        */
#define SYS_GPE_MFOS_MFOS3_Msk           (0x1ul << SYS_GPE_MFOS_MFOS3_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS3 Mask            */

#define SYS_GPE_MFOS_MFOS4_Pos           (4)                                               /*!< SYS_T::GPE_MFOS: MFOS4 Position        */
#define SYS_GPE_MFOS_MFOS4_Msk           (0x1ul << SYS_GPE_MFOS_MFOS4_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS4 Mask            */

#define SYS_GPE_MFOS_MFOS5_Pos           (5)                                               /*!< SYS_T::GPE_MFOS: MFOS5 Position        */
#define SYS_GPE_MFOS_MFOS5_Msk           (0x1ul << SYS_GPE_MFOS_MFOS5_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS5 Mask            */

#define SYS_GPE_MFOS_MFOS6_Pos           (6)                                               /*!< SYS_T::GPE_MFOS: MFOS6 Position        */
#define SYS_GPE_MFOS_MFOS6_Msk           (0x1ul << SYS_GPE_MFOS_MFOS6_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS6 Mask            */

#define SYS_GPE_MFOS_MFOS7_Pos           (7)                                               /*!< SYS_T::GPE_MFOS: MFOS7 Position        */
#define SYS_GPE_MFOS_MFOS7_Msk           (0x1ul << SYS_GPE_MFOS_MFOS7_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS7 Mask            */

#define SYS_GPE_MFOS_MFOS8_Pos           (8)                                               /*!< SYS_T::GPE_MFOS: MFOS8 Position        */
#define SYS_GPE_MFOS_MFOS8_Msk           (0x1ul << SYS_GPE_MFOS_MFOS8_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS8 Mask            */

#define SYS_GPE_MFOS_MFOS9_Pos           (9)                                               /*!< SYS_T::GPE_MFOS: MFOS9 Position        */
#define SYS_GPE_MFOS_MFOS9_Msk           (0x1ul << SYS_GPE_MFOS_MFOS9_Pos)                 /*!< SYS_T::GPE_MFOS: MFOS9 Mask            */

#define SYS_GPE_MFOS_MFOS10_Pos          (10)                                              /*!< SYS_T::GPE_MFOS: MFOS10 Position       */
#define SYS_GPE_MFOS_MFOS10_Msk          (0x1ul << SYS_GPE_MFOS_MFOS10_Pos)                /*!< SYS_T::GPE_MFOS: MFOS10 Mask           */

#define SYS_GPE_MFOS_MFOS11_Pos          (11)                                              /*!< SYS_T::GPE_MFOS: MFOS11 Position       */
#define SYS_GPE_MFOS_MFOS11_Msk          (0x1ul << SYS_GPE_MFOS_MFOS11_Pos)                /*!< SYS_T::GPE_MFOS: MFOS11 Mask           */

#define SYS_GPE_MFOS_MFOS12_Pos          (12)                                              /*!< SYS_T::GPE_MFOS: MFOS12 Position       */
#define SYS_GPE_MFOS_MFOS12_Msk          (0x1ul << SYS_GPE_MFOS_MFOS12_Pos)                /*!< SYS_T::GPE_MFOS: MFOS12 Mask           */

#define SYS_GPE_MFOS_MFOS13_Pos          (13)                                              /*!< SYS_T::GPE_MFOS: MFOS13 Position       */
#define SYS_GPE_MFOS_MFOS13_Msk          (0x1ul << SYS_GPE_MFOS_MFOS13_Pos)                /*!< SYS_T::GPE_MFOS: MFOS13 Mask           */

#define SYS_GPE_MFOS_MFOS14_Pos          (14)                                              /*!< SYS_T::GPE_MFOS: MFOS14 Position       */
#define SYS_GPE_MFOS_MFOS14_Msk          (0x1ul << SYS_GPE_MFOS_MFOS14_Pos)                /*!< SYS_T::GPE_MFOS: MFOS14 Mask           */

#define SYS_GPE_MFOS_MFOS15_Pos          (15)                                              /*!< SYS_T::GPE_MFOS: MFOS15 Position       */
#define SYS_GPE_MFOS_MFOS15_Msk          (0x1ul << SYS_GPE_MFOS_MFOS15_Pos)                /*!< SYS_T::GPE_MFOS: MFOS15 Mask           */

#define SYS_GPF_MFOS_MFOS0_Pos           (0)                                               /*!< SYS_T::GPF_MFOS: MFOS0 Position        */
#define SYS_GPF_MFOS_MFOS0_Msk           (0x1ul << SYS_GPF_MFOS_MFOS0_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS0 Mask            */

#define SYS_GPF_MFOS_MFOS1_Pos           (1)                                               /*!< SYS_T::GPF_MFOS: MFOS1 Position        */
#define SYS_GPF_MFOS_MFOS1_Msk           (0x1ul << SYS_GPF_MFOS_MFOS1_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS1 Mask            */

#define SYS_GPF_MFOS_MFOS2_Pos           (2)                                               /*!< SYS_T::GPF_MFOS: MFOS2 Position        */
#define SYS_GPF_MFOS_MFOS2_Msk           (0x1ul << SYS_GPF_MFOS_MFOS2_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS2 Mask            */

#define SYS_GPF_MFOS_MFOS3_Pos           (3)                                               /*!< SYS_T::GPF_MFOS: MFOS3 Position        */
#define SYS_GPF_MFOS_MFOS3_Msk           (0x1ul << SYS_GPF_MFOS_MFOS3_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS3 Mask            */

#define SYS_GPF_MFOS_MFOS4_Pos           (4)                                               /*!< SYS_T::GPF_MFOS: MFOS4 Position        */
#define SYS_GPF_MFOS_MFOS4_Msk           (0x1ul << SYS_GPF_MFOS_MFOS4_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS4 Mask            */

#define SYS_GPF_MFOS_MFOS5_Pos           (5)                                               /*!< SYS_T::GPF_MFOS: MFOS5 Position        */
#define SYS_GPF_MFOS_MFOS5_Msk           (0x1ul << SYS_GPF_MFOS_MFOS5_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS5 Mask            */

#define SYS_GPF_MFOS_MFOS6_Pos           (6)                                               /*!< SYS_T::GPF_MFOS: MFOS6 Position        */
#define SYS_GPF_MFOS_MFOS6_Msk           (0x1ul << SYS_GPF_MFOS_MFOS6_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS6 Mask            */

#define SYS_GPF_MFOS_MFOS7_Pos           (7)                                               /*!< SYS_T::GPF_MFOS: MFOS7 Position        */
#define SYS_GPF_MFOS_MFOS7_Msk           (0x1ul << SYS_GPF_MFOS_MFOS7_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS7 Mask            */

#define SYS_GPF_MFOS_MFOS8_Pos           (8)                                               /*!< SYS_T::GPF_MFOS: MFOS8 Position        */
#define SYS_GPF_MFOS_MFOS8_Msk           (0x1ul << SYS_GPF_MFOS_MFOS8_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS8 Mask            */

#define SYS_GPF_MFOS_MFOS9_Pos           (9)                                               /*!< SYS_T::GPF_MFOS: MFOS9 Position        */
#define SYS_GPF_MFOS_MFOS9_Msk           (0x1ul << SYS_GPF_MFOS_MFOS9_Pos)                 /*!< SYS_T::GPF_MFOS: MFOS9 Mask            */

#define SYS_GPF_MFOS_MFOS10_Pos          (10)                                              /*!< SYS_T::GPF_MFOS: MFOS10 Position       */
#define SYS_GPF_MFOS_MFOS10_Msk          (0x1ul << SYS_GPF_MFOS_MFOS10_Pos)                /*!< SYS_T::GPF_MFOS: MFOS10 Mask           */

#define SYS_GPF_MFOS_MFOS11_Pos          (11)                                              /*!< SYS_T::GPF_MFOS: MFOS11 Position       */
#define SYS_GPF_MFOS_MFOS11_Msk          (0x1ul << SYS_GPF_MFOS_MFOS11_Pos)                /*!< SYS_T::GPF_MFOS: MFOS11 Mask           */

#define SYS_GPF_MFOS_MFOS12_Pos          (12)                                              /*!< SYS_T::GPF_MFOS: MFOS12 Position       */
#define SYS_GPF_MFOS_MFOS12_Msk          (0x1ul << SYS_GPF_MFOS_MFOS12_Pos)                /*!< SYS_T::GPF_MFOS: MFOS12 Mask           */

#define SYS_GPF_MFOS_MFOS13_Pos          (13)                                              /*!< SYS_T::GPF_MFOS: MFOS13 Position       */
#define SYS_GPF_MFOS_MFOS13_Msk          (0x1ul << SYS_GPF_MFOS_MFOS13_Pos)                /*!< SYS_T::GPF_MFOS: MFOS13 Mask           */

#define SYS_GPF_MFOS_MFOS14_Pos          (14)                                              /*!< SYS_T::GPF_MFOS: MFOS14 Position       */
#define SYS_GPF_MFOS_MFOS14_Msk          (0x1ul << SYS_GPF_MFOS_MFOS14_Pos)                /*!< SYS_T::GPF_MFOS: MFOS14 Mask           */

#define SYS_GPF_MFOS_MFOS15_Pos          (15)                                              /*!< SYS_T::GPF_MFOS: MFOS15 Position       */
#define SYS_GPF_MFOS_MFOS15_Msk          (0x1ul << SYS_GPF_MFOS_MFOS15_Pos)                /*!< SYS_T::GPF_MFOS: MFOS15 Mask           */

#define SYS_MODCTL_MODEN_Pos             (0)                                               /*!< SYS_T::MODCTL: MODEN Position          */
#define SYS_MODCTL_MODEN_Msk             (0x1ul << SYS_MODCTL_MODEN_Pos)                   /*!< SYS_T::MODCTL: MODEN Mask              */

#define SYS_MODCTL_MODH_Pos              (1)                                               /*!< SYS_T::MODCTL: MODH Position           */
#define SYS_MODCTL_MODH_Msk              (0x1ul << SYS_MODCTL_MODH_Pos)                    /*!< SYS_T::MODCTL: MODH Mask               */

#define SYS_MODCTL_MODPWMSEL_Pos         (4)                                               /*!< SYS_T::MODCTL: MODPWMSEL Position      */
#define SYS_MODCTL_MODPWMSEL_Msk         (0xful << SYS_MODCTL_MODPWMSEL_Pos)               /*!< SYS_T::MODCTL: MODPWMSEL Mask          */

#define SYS_SRAM_BISTCTL_SRBIST_Pos      (0)                                               /*!< SYS_T::SRAM_BISTCTL: SRBIST Position   */
#define SYS_SRAM_BISTCTL_SRBIST_Msk      (0x1ul << SYS_SRAM_BISTCTL_SRBIST_Pos)            /*!< SYS_T::SRAM_BISTCTL: SRBIST Mask       */

#define SYS_SRAM_BISTCTL_FMCBIST_Pos     (2)                                               /*!< SYS_T::SRAM_BISTCTL: FMCBIST Position  */
#define SYS_SRAM_BISTCTL_FMCBIST_Msk     (0x1ul << SYS_SRAM_BISTCTL_FMCBIST_Pos)           /*!< SYS_T::SRAM_BISTCTL: FMCBIST Mask      */

#define SYS_SRAM_BISTCTL_USBBIST_Pos     (4)                                               /*!< SYS_T::SRAM_BISTCTL: USBBIST Position  */
#define SYS_SRAM_BISTCTL_USBBIST_Msk     (0x1ul << SYS_SRAM_BISTCTL_USBBIST_Pos)           /*!< SYS_T::SRAM_BISTCTL: USBBIST Mask      */

#define SYS_SRAM_BISTCTL_PDMABIST_Pos    (7)                                               /*!< SYS_T::SRAM_BISTCTL: PDMABIST Position */
#define SYS_SRAM_BISTCTL_PDMABIST_Msk    (0x1ul << SYS_SRAM_BISTCTL_PDMABIST_Pos)          /*!< SYS_T::SRAM_BISTCTL: PDMABIST Mask     */

#define SYS_SRAM_BISTSTS_SRBISTEF_Pos    (0)                                               /*!< SYS_T::SRAM_BISTSTS: SRBISTEF Position */
#define SYS_SRAM_BISTSTS_SRBISTEF_Msk    (0x1ul << SYS_SRAM_BISTSTS_SRBISTEF_Pos)          /*!< SYS_T::SRAM_BISTSTS: SRBISTEF Mask     */

#define SYS_SRAM_BISTSTS_CR0BISTEF_Pos   (1)                                               /*!< SYS_T::SRAM_BISTSTS: CR0BISTEF Position*/
#define SYS_SRAM_BISTSTS_CR0BISTEF_Msk   (0x1ul << SYS_SRAM_BISTSTS_CR0BISTEF_Pos)         /*!< SYS_T::SRAM_BISTSTS: CR0BISTEF Mask    */

#define SYS_SRAM_BISTSTS_CR1BISTEF_Pos   (2)                                               /*!< SYS_T::SRAM_BISTSTS: CR1BISTEF Position*/
#define SYS_SRAM_BISTSTS_CR1BISTEF_Msk   (0x1ul << SYS_SRAM_BISTSTS_CR1BISTEF_Pos)         /*!< SYS_T::SRAM_BISTSTS: CR1BISTEF Mask    */

#define SYS_SRAM_BISTSTS_USBBEF_Pos      (4)                                               /*!< SYS_T::SRAM_BISTSTS: USBBEF Position   */
#define SYS_SRAM_BISTSTS_USBBEF_Msk      (0x1ul << SYS_SRAM_BISTSTS_USBBEF_Pos)            /*!< SYS_T::SRAM_BISTSTS: USBBEF Mask       */

#define SYS_SRAM_BISTSTS_PDMABISTF_Pos   (7)                                               /*!< SYS_T::SRAM_BISTSTS: PDMABISTF Position*/
#define SYS_SRAM_BISTSTS_PDMABISTF_Msk   (0x1ul << SYS_SRAM_BISTSTS_PDMABISTF_Pos)         /*!< SYS_T::SRAM_BISTSTS: PDMABISTF Mask    */

#define SYS_SRAM_BISTSTS_SRBEND_Pos      (16)                                              /*!< SYS_T::SRAM_BISTSTS: SRBEND Position   */
#define SYS_SRAM_BISTSTS_SRBEND_Msk      (0x1ul << SYS_SRAM_BISTSTS_SRBEND_Pos)            /*!< SYS_T::SRAM_BISTSTS: SRBEND Mask       */

#define SYS_SRAM_BISTSTS_CR0BEND_Pos     (17)                                              /*!< SYS_T::SRAM_BISTSTS: CR0BEND Position  */
#define SYS_SRAM_BISTSTS_CR0BEND_Msk     (0x1ul << SYS_SRAM_BISTSTS_CR0BEND_Pos)           /*!< SYS_T::SRAM_BISTSTS: CR0BEND Mask      */

#define SYS_SRAM_BISTSTS_CR1BEND_Pos     (18)                                              /*!< SYS_T::SRAM_BISTSTS: CR1BEND Position  */
#define SYS_SRAM_BISTSTS_CR1BEND_Msk     (0x1ul << SYS_SRAM_BISTSTS_CR1BEND_Pos)           /*!< SYS_T::SRAM_BISTSTS: CR1BEND Mask      */

#define SYS_SRAM_BISTSTS_USBBEND_Pos     (20)                                              /*!< SYS_T::SRAM_BISTSTS: USBBEND Position  */
#define SYS_SRAM_BISTSTS_USBBEND_Msk     (0x1ul << SYS_SRAM_BISTSTS_USBBEND_Pos)           /*!< SYS_T::SRAM_BISTSTS: USBBEND Mask      */

#define SYS_SRAM_BISTSTS_PDMAEND_Pos     (23)                                              /*!< SYS_T::SRAM_BISTSTS: PDMAEND Position  */
#define SYS_SRAM_BISTSTS_PDMAEND_Msk     (0x1ul << SYS_SRAM_BISTSTS_PDMAEND_Pos)           /*!< SYS_T::SRAM_BISTSTS: PDMAEND Mask      */

#define SYS_HIRCTRIMCTL_FREQSEL_Pos      (0)                                               /*!< SYS_T::HIRCTRIMCTL: FREQSEL Position   */
#define SYS_HIRCTRIMCTL_FREQSEL_Msk      (0x3ul << SYS_HIRCTRIMCTL_FREQSEL_Pos)            /*!< SYS_T::HIRCTRIMCTL: FREQSEL Mask       */

#define SYS_HIRCTRIMCTL_LOOPSEL_Pos      (4)                                               /*!< SYS_T::HIRCTRIMCTL: LOOPSEL Position   */
#define SYS_HIRCTRIMCTL_LOOPSEL_Msk      (0x3ul << SYS_HIRCTRIMCTL_LOOPSEL_Pos)            /*!< SYS_T::HIRCTRIMCTL: LOOPSEL Mask       */

#define SYS_HIRCTRIMCTL_RETRYCNT_Pos     (6)                                               /*!< SYS_T::HIRCTRIMCTL: RETRYCNT Position  */
#define SYS_HIRCTRIMCTL_RETRYCNT_Msk     (0x3ul << SYS_HIRCTRIMCTL_RETRYCNT_Pos)           /*!< SYS_T::HIRCTRIMCTL: RETRYCNT Mask      */

#define SYS_HIRCTRIMCTL_CESTOPEN_Pos     (8)                                               /*!< SYS_T::HIRCTRIMCTL: CESTOPEN Position  */
#define SYS_HIRCTRIMCTL_CESTOPEN_Msk     (0x1ul << SYS_HIRCTRIMCTL_CESTOPEN_Pos)           /*!< SYS_T::HIRCTRIMCTL: CESTOPEN Mask      */

#define SYS_HIRCTRIMCTL_BOUNDEN_Pos      (9)                                               /*!< SYS_T::HIRCTRIMCTL: BOUNDEN Position   */
#define SYS_HIRCTRIMCTL_BOUNDEN_Msk      (0x1ul << SYS_HIRCTRIMCTL_BOUNDEN_Pos)            /*!< SYS_T::HIRCTRIMCTL: BOUNDEN Mask       */

#define SYS_HIRCTRIMCTL_REFCKSEL_Pos     (10)                                              /*!< SYS_T::HIRCTRIMCTL: REFCKSEL Position  */
#define SYS_HIRCTRIMCTL_REFCKSEL_Msk     (0x1ul << SYS_HIRCTRIMCTL_REFCKSEL_Pos)           /*!< SYS_T::HIRCTRIMCTL: REFCKSEL Mask      */

#define SYS_HIRCTRIMCTL_BOUNDARY_Pos     (16)                                              /*!< SYS_T::HIRCTRIMCTL: BOUNDARY Position  */
#define SYS_HIRCTRIMCTL_BOUNDARY_Msk     (0x1ful << SYS_HIRCTRIMCTL_BOUNDARY_Pos)          /*!< SYS_T::HIRCTRIMCTL: BOUNDARY Mask      */

#define SYS_HIRCTRIMIEN_TFALIEN_Pos      (1)                                               /*!< SYS_T::HIRCTRIMIEN: TFALIEN Position   */
#define SYS_HIRCTRIMIEN_TFALIEN_Msk      (0x1ul << SYS_HIRCTRIMIEN_TFALIEN_Pos)            /*!< SYS_T::HIRCTRIMIEN: TFALIEN Mask       */

#define SYS_HIRCTRIMIEN_CLKEIEN_Pos      (2)                                               /*!< SYS_T::HIRCTRIMIEN: CLKEIEN Position   */
#define SYS_HIRCTRIMIEN_CLKEIEN_Msk      (0x1ul << SYS_HIRCTRIMIEN_CLKEIEN_Pos)            /*!< SYS_T::HIRCTRIMIEN: CLKEIEN Mask       */

#define SYS_HIRCTRIMSTS_FREQLOCK_Pos     (0)                                               /*!< SYS_T::HIRCTRIMSTS: FREQLOCK Position  */
#define SYS_HIRCTRIMSTS_FREQLOCK_Msk     (0x1ul << SYS_HIRCTRIMSTS_FREQLOCK_Pos)           /*!< SYS_T::HIRCTRIMSTS: FREQLOCK Mask      */

#define SYS_HIRCTRIMSTS_TFAILIF_Pos      (1)                                               /*!< SYS_T::HIRCTRIMSTS: TFAILIF Position   */
#define SYS_HIRCTRIMSTS_TFAILIF_Msk      (0x1ul << SYS_HIRCTRIMSTS_TFAILIF_Pos)            /*!< SYS_T::HIRCTRIMSTS: TFAILIF Mask       */

#define SYS_HIRCTRIMSTS_CLKERIF_Pos      (2)                                               /*!< SYS_T::HIRCTRIMSTS: CLKERIF Position   */
#define SYS_HIRCTRIMSTS_CLKERIF_Msk      (0x1ul << SYS_HIRCTRIMSTS_CLKERIF_Pos)            /*!< SYS_T::HIRCTRIMSTS: CLKERIF Mask       */

#define SYS_HIRCTRIMSTS_OVBDIF_Pos       (3)                                               /*!< SYS_T::HIRCTRIMSTS: OVBDIF Position    */
#define SYS_HIRCTRIMSTS_OVBDIF_Msk       (0x1ul << SYS_HIRCTRIMSTS_OVBDIF_Pos)             /*!< SYS_T::HIRCTRIMSTS: OVBDIF Mask        */

#define SYS_REGLCTL_REGLCTL_Pos          (0)                                               /*!< SYS_T::REGLCTL: REGLCTL Position       */
#define SYS_REGLCTL_REGLCTL_Msk          (0xfful << SYS_REGLCTL_REGLCTL_Pos)               /*!< SYS_T::REGLCTL: REGLCTL Mask           */

#define SYS_MIRCTRIMCTL_FREQSEL_Pos      (0)                                               /*!< SYS_T::MIRCTRIMCTL: FREQSEL Position   */
#define SYS_MIRCTRIMCTL_FREQSEL_Msk      (0x3ul << SYS_MIRCTRIMCTL_FREQSEL_Pos)            /*!< SYS_T::MIRCTRIMCTL: FREQSEL Mask       */

#define SYS_MIRCTRIMCTL_LOOPSEL_Pos      (4)                                               /*!< SYS_T::MIRCTRIMCTL: LOOPSEL Position   */
#define SYS_MIRCTRIMCTL_LOOPSEL_Msk      (0x3ul << SYS_MIRCTRIMCTL_LOOPSEL_Pos)            /*!< SYS_T::MIRCTRIMCTL: LOOPSEL Mask       */

#define SYS_MIRCTRIMCTL_RETRYCNT_Pos     (6)                                               /*!< SYS_T::MIRCTRIMCTL: RETRYCNT Position  */
#define SYS_MIRCTRIMCTL_RETRYCNT_Msk     (0x3ul << SYS_MIRCTRIMCTL_RETRYCNT_Pos)           /*!< SYS_T::MIRCTRIMCTL: RETRYCNT Mask      */

#define SYS_MIRCTRIMCTL_CESTOPEN_Pos     (8)                                               /*!< SYS_T::MIRCTRIMCTL: CESTOPEN Position  */
#define SYS_MIRCTRIMCTL_CESTOPEN_Msk     (0x1ul << SYS_MIRCTRIMCTL_CESTOPEN_Pos)           /*!< SYS_T::MIRCTRIMCTL: CESTOPEN Mask      */

#define SYS_MIRCTRIMCTL_BOUNDEN_Pos      (9)                                               /*!< SYS_T::MIRCTRIMCTL: BOUNDEN Position   */
#define SYS_MIRCTRIMCTL_BOUNDEN_Msk      (0x1ul << SYS_MIRCTRIMCTL_BOUNDEN_Pos)            /*!< SYS_T::MIRCTRIMCTL: BOUNDEN Mask       */

#define SYS_MIRCTRIMCTL_REFCKSEL_Pos     (10)                                              /*!< SYS_T::MIRCTRIMCTL: REFCKSEL Position  */
#define SYS_MIRCTRIMCTL_REFCKSEL_Msk     (0x1ul << SYS_MIRCTRIMCTL_REFCKSEL_Pos)           /*!< SYS_T::MIRCTRIMCTL: REFCKSEL Mask      */

#define SYS_MIRCTRIMCTL_BOUNDARY_Pos     (16)                                              /*!< SYS_T::MIRCTRIMCTL: BOUNDARY Position  */
#define SYS_MIRCTRIMCTL_BOUNDARY_Msk     (0x1ful << SYS_MIRCTRIMCTL_BOUNDARY_Pos)          /*!< SYS_T::MIRCTRIMCTL: BOUNDARY Mask      */

#define SYS_MIRCTRIMIEN_TFALIEN_Pos      (1)                                               /*!< SYS_T::MIRCTRIMIEN: TFALIEN Position   */
#define SYS_MIRCTRIMIEN_TFALIEN_Msk      (0x1ul << SYS_MIRCTRIMIEN_TFALIEN_Pos)            /*!< SYS_T::MIRCTRIMIEN: TFALIEN Mask       */

#define SYS_MIRCTRIMIEN_CLKEIEN_Pos      (2)                                               /*!< SYS_T::MIRCTRIMIEN: CLKEIEN Position   */
#define SYS_MIRCTRIMIEN_CLKEIEN_Msk      (0x1ul << SYS_MIRCTRIMIEN_CLKEIEN_Pos)            /*!< SYS_T::MIRCTRIMIEN: CLKEIEN Mask       */

#define SYS_MIRCTRIMSTS_FREQLOCK_Pos     (0)                                               /*!< SYS_T::MIRCTRIMSTS: FREQLOCK Position  */
#define SYS_MIRCTRIMSTS_FREQLOCK_Msk     (0x1ul << SYS_MIRCTRIMSTS_FREQLOCK_Pos)           /*!< SYS_T::MIRCTRIMSTS: FREQLOCK Mask      */

#define SYS_MIRCTRIMSTS_TFAILIF_Pos      (1)                                               /*!< SYS_T::MIRCTRIMSTS: TFAILIF Position   */
#define SYS_MIRCTRIMSTS_TFAILIF_Msk      (0x1ul << SYS_MIRCTRIMSTS_TFAILIF_Pos)            /*!< SYS_T::MIRCTRIMSTS: TFAILIF Mask       */

#define SYS_MIRCTRIMSTS_CLKERIF_Pos      (2)                                               /*!< SYS_T::MIRCTRIMSTS: CLKERIF Position   */
#define SYS_MIRCTRIMSTS_CLKERIF_Msk      (0x1ul << SYS_MIRCTRIMSTS_CLKERIF_Pos)            /*!< SYS_T::MIRCTRIMSTS: CLKERIF Mask       */

#define SYS_MIRCTRIMSTS_OVBDIF_Pos       (3)                                               /*!< SYS_T::MIRCTRIMSTS: OVBDIF Position    */
#define SYS_MIRCTRIMSTS_OVBDIF_Msk       (0x1ul << SYS_MIRCTRIMSTS_OVBDIF_Pos)             /*!< SYS_T::MIRCTRIMSTS: OVBDIF Mask        */

#define SYS_RTCLVRIEN_IE_Pos             (0)                                               /*!< SYS_T::RTCLVRIEN: IE Position     */
#define SYS_RTCLVRIEN_IE_Msk             (0x1ul << SYS_RTCLVRIEN_IE_Pos)                   /*!< SYS_T::RTCLVRIEN: IE Mask         */

#define SYS_RTCLVRSTS_IF_Pos             (0)                                               /*!< SYS_T::RTCLVRSTS: IF Position     */
#define SYS_RTCLVRSTS_IF_Msk             (0x1ul << SYS_RTCLVRSTS_IF_Pos)                   /*!< SYS_T::RTCLVRSTS: IF Mask         */

#define SYS_RTCLVRSTS_RTCLVR_Pos         (8)                                               /*!< SYS_T::RTCLVRSTS: RTCLVR Position     */
#define SYS_RTCLVRSTS_RTCLVR_Msk         (0x1ul << SYS_RTCLVRSTS_RTCLVR_Pos)               /*!< SYS_T::RTCLVRSTS: RTCLVR Mask         */

#define SYS_PORCTL1_POROFF_Pos           (0)                                               /*!< SYS_T::PORCTL1: POROFF Position     */
#define SYS_PORCTL1_POROFF_Msk           (0xfffful << SYS_PORCTL1_POROFF_Pos)              /*!< SYS_T::PORCTL1: POROFF Mask         */

#define SYS_PLCTL_PLSEL_Pos              (0)                                               /*!< SYS_T::PLCTL: PLSEL Position           */
#define SYS_PLCTL_PLSEL_Msk              (0x3ul << SYS_PLCTL_PLSEL_Pos)                    /*!< SYS_T::PLCTL: PLSEL Mask               */

#define SYS_PLSTS_PLCBUSY_Pos            (0)                                               /*!< SYS_T::PLSTS: PLCBUSY Position         */
#define SYS_PLSTS_PLCBUSY_Msk            (0x1ul << SYS_PLSTS_PLCBUSY_Pos)                  /*!< SYS_T::PLSTS: PLCBUSY Mask             */

#define SYS_PLSTS_CURPL_Pos              (8)                                               /*!< SYS_T::PLSTS: CURPL Position           */
#define SYS_PLSTS_CURPL_Msk              (0x3ul << SYS_PLSTS_CURPL_Pos)                    /*!< SYS_T::PLSTS: CURPL Mask               */

/** @} SYS_CONST */
/** @} end of SYS register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __SYS_REG_H__ */
