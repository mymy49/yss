/**************************************************************************//**
 * @file     clk_reg.h
 * @version  V1.00
 * @brief    CLK register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __CLK_REG_H__
#define __CLK_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/


/**
    @addtogroup CLK_CONST CLK Bit Field Definition
    Constant Definitions for CLK Controller
@{ */

#define CLK_PWRCTL_HXTEN_Pos             (0)                                               /*!< CLK_T::PWRCTL: HXTEN Position          */
#define CLK_PWRCTL_HXTEN_Msk             (0x1ul << CLK_PWRCTL_HXTEN_Pos)                   /*!< CLK_T::PWRCTL: HXTEN Mask              */

#define CLK_PWRCTL_LXTEN_Pos             (1)                                               /*!< CLK_T::PWRCTL: LXTEN Position          */
#define CLK_PWRCTL_LXTEN_Msk             (0x1ul << CLK_PWRCTL_LXTEN_Pos)                   /*!< CLK_T::PWRCTL: LXTEN Mask              */

#define CLK_PWRCTL_HIRCEN_Pos            (2)                                               /*!< CLK_T::PWRCTL: HIRCEN Position         */
#define CLK_PWRCTL_HIRCEN_Msk            (0x1ul << CLK_PWRCTL_HIRCEN_Pos)                  /*!< CLK_T::PWRCTL: HIRCEN Mask             */

#define CLK_PWRCTL_LIRCEN_Pos            (3)                                               /*!< CLK_T::PWRCTL: LIRCEN Position         */
#define CLK_PWRCTL_LIRCEN_Msk            (0x1ul << CLK_PWRCTL_LIRCEN_Pos)                  /*!< CLK_T::PWRCTL: LIRCEN Mask             */

#define CLK_PWRCTL_PDWKDLY_Pos           (4)                                               /*!< CLK_T::PWRCTL: PDWKDLY Position        */
#define CLK_PWRCTL_PDWKDLY_Msk           (0x1ul << CLK_PWRCTL_PDWKDLY_Pos)                 /*!< CLK_T::PWRCTL: PDWKDLY Mask            */

#define CLK_PWRCTL_PDWKIEN_Pos           (5)                                               /*!< CLK_T::PWRCTL: PDWKIEN Position        */
#define CLK_PWRCTL_PDWKIEN_Msk           (0x1ul << CLK_PWRCTL_PDWKIEN_Pos)                 /*!< CLK_T::PWRCTL: PDWKIEN Mask            */

#define CLK_PWRCTL_PDWKIF_Pos            (6)                                               /*!< CLK_T::PWRCTL: PDWKIF Position         */
#define CLK_PWRCTL_PDWKIF_Msk            (0x1ul << CLK_PWRCTL_PDWKIF_Pos)                  /*!< CLK_T::PWRCTL: PDWKIF Mask             */

#define CLK_PWRCTL_PDEN_Pos              (7)                                               /*!< CLK_T::PWRCTL: PDEN Position           */
#define CLK_PWRCTL_PDEN_Msk              (0x1ul << CLK_PWRCTL_PDEN_Pos)                    /*!< CLK_T::PWRCTL: PDEN Mask               */

#define CLK_PWRCTL_MIRCEN_Pos            (19)                                              /*!< CLK_T::PWRCTL: MIRCEN Position         */
#define CLK_PWRCTL_MIRCEN_Msk            (0x1ul << CLK_PWRCTL_MIRCEN_Pos)                  /*!< CLK_T::PWRCTL: MIRCEN Mask             */

#define CLK_PWRCTL_HXTGAIN_Pos           (20)                                              /*!< CLK_T::PWRCTL: HXTGAIN Position        */
#define CLK_PWRCTL_HXTGAIN_Msk           (0x7ul << CLK_PWRCTL_HXTGAIN_Pos)                /*!< CLK_T::PWRCTL: HXTGAIN Mask            */

#define CLK_AHBCLK_PDMACKEN_Pos          (1)                                               /*!< CLK_T::AHBCLK: PDMACKEN Position       */
#define CLK_AHBCLK_PDMACKEN_Msk          (0x1ul << CLK_AHBCLK_PDMACKEN_Pos)                /*!< CLK_T::AHBCLK: PDMACKEN Mask           */

#define CLK_AHBCLK_ISPCKEN_Pos           (2)                                               /*!< CLK_T::AHBCLK: ISPCKEN Position        */
#define CLK_AHBCLK_ISPCKEN_Msk           (0x1ul << CLK_AHBCLK_ISPCKEN_Pos)                 /*!< CLK_T::AHBCLK: ISPCKEN Mask            */

#define CLK_AHBCLK_EBICKEN_Pos           (3)                                               /*!< CLK_T::AHBCLK: EBICKEN Position        */
#define CLK_AHBCLK_EBICKEN_Msk           (0x1ul << CLK_AHBCLK_EBICKEN_Pos)                 /*!< CLK_T::AHBCLK: EBICKEN Mask            */

#define CLK_AHBCLK_EXSTCKEN_Pos          (4)                                               /*!< CLK_T::AHBCLK: EXSTCKEN Position       */
#define CLK_AHBCLK_EXSTCKEN_Msk          (0x1ul << CLK_AHBCLK_EXSTCKEN_Pos)                /*!< CLK_T::AHBCLK: EXSTCKEN Mask           */

#define CLK_AHBCLK_CRCCKEN_Pos           (7)                                               /*!< CLK_T::AHBCLK: CRCCKEN Position        */
#define CLK_AHBCLK_CRCCKEN_Msk           (0x1ul << CLK_AHBCLK_CRCCKEN_Pos)                 /*!< CLK_T::AHBCLK: CRCCKEN Mask            */

#define CLK_AHBCLK_CRPTCKEN_Pos          (12)                                              /*!< CLK_T::AHBCLK: CRPTCKEN Position       */
#define CLK_AHBCLK_CRPTCKEN_Msk          (0x1ul << CLK_AHBCLK_CRPTCKEN_Pos)                /*!< CLK_T::AHBCLK: CRPTCKEN Mask           */

#define CLK_AHBCLK_FMCIDLE_Pos           (15)                                              /*!< CLK_T::AHBCLK: FMCIDLE Position        */
#define CLK_AHBCLK_FMCIDLE_Msk           (0x1ul << CLK_AHBCLK_FMCIDLE_Pos)                 /*!< CLK_T::AHBCLK: FMCIDLE Mask            */

#define CLK_AHBCLK_GPACKEN_Pos           (24)                                              /*!< CLK_T::AHBCLK: GPACKEN Position        */
#define CLK_AHBCLK_GPACKEN_Msk           (0x1ul << CLK_AHBCLK_GPACKEN_Pos)                 /*!< CLK_T::AHBCLK: GPACKEN Mask            */

#define CLK_AHBCLK_GPBCKEN_Pos           (25)                                              /*!< CLK_T::AHBCLK: GPBCKEN Position        */
#define CLK_AHBCLK_GPBCKEN_Msk           (0x1ul << CLK_AHBCLK_GPBCKEN_Pos)                 /*!< CLK_T::AHBCLK: GPBCKEN Mask            */

#define CLK_AHBCLK_GPCCKEN_Pos           (26)                                              /*!< CLK_T::AHBCLK: GPCCKEN Position        */
#define CLK_AHBCLK_GPCCKEN_Msk           (0x1ul << CLK_AHBCLK_GPCCKEN_Pos)                 /*!< CLK_T::AHBCLK: GPCCKEN Mask            */

#define CLK_AHBCLK_GPDCKEN_Pos           (27)                                              /*!< CLK_T::AHBCLK: GPDCKEN Position        */
#define CLK_AHBCLK_GPDCKEN_Msk           (0x1ul << CLK_AHBCLK_GPDCKEN_Pos)                 /*!< CLK_T::AHBCLK: GPDCKEN Mask            */

#define CLK_AHBCLK_GPECKEN_Pos           (28)                                              /*!< CLK_T::AHBCLK: GPECKEN Position        */
#define CLK_AHBCLK_GPECKEN_Msk           (0x1ul << CLK_AHBCLK_GPECKEN_Pos)                 /*!< CLK_T::AHBCLK: GPECKEN Mask            */

#define CLK_AHBCLK_GPFCKEN_Pos           (29)                                              /*!< CLK_T::AHBCLK: GPFCKEN Position        */
#define CLK_AHBCLK_GPFCKEN_Msk           (0x1ul << CLK_AHBCLK_GPFCKEN_Pos)                 /*!< CLK_T::AHBCLK: GPFCKEN Mask            */

#define CLK_APBCLK0_WDTCKEN_Pos          (0)                                               /*!< CLK_T::APBCLK0: WDTCKEN Position       */
#define CLK_APBCLK0_WDTCKEN_Msk          (0x1ul << CLK_APBCLK0_WDTCKEN_Pos)                /*!< CLK_T::APBCLK0: WDTCKEN Mask           */

#define CLK_APBCLK0_RTCCKEN_Pos          (1)                                               /*!< CLK_T::APBCLK0: RTCCKEN Position       */
#define CLK_APBCLK0_RTCCKEN_Msk          (0x1ul << CLK_APBCLK0_RTCCKEN_Pos)                /*!< CLK_T::APBCLK0: RTCCKEN Mask           */

#define CLK_APBCLK0_TMR0CKEN_Pos         (2)                                               /*!< CLK_T::APBCLK0: TMR0CKEN Position      */
#define CLK_APBCLK0_TMR0CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR0CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR0CKEN Mask          */

#define CLK_APBCLK0_TMR1CKEN_Pos         (3)                                               /*!< CLK_T::APBCLK0: TMR1CKEN Position      */
#define CLK_APBCLK0_TMR1CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR1CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR1CKEN Mask          */

#define CLK_APBCLK0_TMR2CKEN_Pos         (4)                                               /*!< CLK_T::APBCLK0: TMR2CKEN Position      */
#define CLK_APBCLK0_TMR2CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR2CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR2CKEN Mask          */

#define CLK_APBCLK0_TMR3CKEN_Pos         (5)                                               /*!< CLK_T::APBCLK0: TMR3CKEN Position      */
#define CLK_APBCLK0_TMR3CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR3CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR3CKEN Mask          */

#define CLK_APBCLK0_CLKOCKEN_Pos         (6)                                               /*!< CLK_T::APBCLK0: CLKOCKEN Position      */
#define CLK_APBCLK0_CLKOCKEN_Msk         (0x1ul << CLK_APBCLK0_CLKOCKEN_Pos)               /*!< CLK_T::APBCLK0: CLKOCKEN Mask          */

#define CLK_APBCLK0_ACMP01CKEN_Pos       (7)                                               /*!< CLK_T::APBCLK0: ACMP01CKEN Position    */
#define CLK_APBCLK0_ACMP01CKEN_Msk       (0x1ul << CLK_APBCLK0_ACMP01CKEN_Pos)             /*!< CLK_T::APBCLK0: ACMP01CKEN Mask        */

#define CLK_APBCLK0_I2C0CKEN_Pos         (8)                                               /*!< CLK_T::APBCLK0: I2C0CKEN Position      */
#define CLK_APBCLK0_I2C0CKEN_Msk         (0x1ul << CLK_APBCLK0_I2C0CKEN_Pos)               /*!< CLK_T::APBCLK0: I2C0CKEN Mask          */

#define CLK_APBCLK0_I2C1CKEN_Pos         (9)                                               /*!< CLK_T::APBCLK0: I2C1CKEN Position      */
#define CLK_APBCLK0_I2C1CKEN_Msk         (0x1ul << CLK_APBCLK0_I2C1CKEN_Pos)               /*!< CLK_T::APBCLK0: I2C1CKEN Mask          */

#define CLK_APBCLK0_QSPI0CKEN_Pos        (12)                                              /*!< CLK_T::APBCLK0: QSPI0CKEN Position     */
#define CLK_APBCLK0_QSPI0CKEN_Msk        (0x1ul << CLK_APBCLK0_QSPI0CKEN_Pos)              /*!< CLK_T::APBCLK0: QSPI0CKEN Mask         */

#define CLK_APBCLK0_SPI0CKEN_Pos         (13)                                              /*!< CLK_T::APBCLK0: SPI0CKEN Position      */
#define CLK_APBCLK0_SPI0CKEN_Msk         (0x1ul << CLK_APBCLK0_SPI0CKEN_Pos)               /*!< CLK_T::APBCLK0: SPI0CKEN Mask          */

#define CLK_APBCLK0_SPI1CKEN_Pos         (14)                                              /*!< CLK_T::APBCLK0: SPI1CKEN Position      */
#define CLK_APBCLK0_SPI1CKEN_Msk         (0x1ul << CLK_APBCLK0_SPI1CKEN_Pos)               /*!< CLK_T::APBCLK0: SPI1CKEN Mask          */

#define CLK_APBCLK0_UART0CKEN_Pos        (16)                                              /*!< CLK_T::APBCLK0: UART0CKEN Position     */
#define CLK_APBCLK0_UART0CKEN_Msk        (0x1ul << CLK_APBCLK0_UART0CKEN_Pos)              /*!< CLK_T::APBCLK0: UART0CKEN Mask         */

#define CLK_APBCLK0_UART1CKEN_Pos        (17)                                              /*!< CLK_T::APBCLK0: UART1CKEN Position     */
#define CLK_APBCLK0_UART1CKEN_Msk        (0x1ul << CLK_APBCLK0_UART1CKEN_Pos)              /*!< CLK_T::APBCLK0: UART1CKEN Mask         */

#define CLK_APBCLK0_UART2CKEN_Pos        (18)                                              /*!< CLK_T::APBCLK0: UART2CKEN Position     */
#define CLK_APBCLK0_UART2CKEN_Msk        (0x1ul << CLK_APBCLK0_UART2CKEN_Pos)              /*!< CLK_T::APBCLK0: UART2CKEN Mask         */

#define CLK_APBCLK0_UART3CKEN_Pos        (19)                                              /*!< CLK_T::APBCLK0: UART3CKEN Position     */
#define CLK_APBCLK0_UART3CKEN_Msk        (0x1ul << CLK_APBCLK0_UART3CKEN_Pos)              /*!< CLK_T::APBCLK0: UART3CKEN Mask         */

#define CLK_APBCLK0_USBDCKEN_Pos         (27)                                              /*!< CLK_T::APBCLK0: USBDCKEN Position      */
#define CLK_APBCLK0_USBDCKEN_Msk         (0x1ul << CLK_APBCLK0_USBDCKEN_Pos)               /*!< CLK_T::APBCLK0: USBDCKEN Mask          */

#define CLK_APBCLK0_EADCCKEN_Pos         (28)                                              /*!< CLK_T::APBCLK0: EADCCKEN Position      */
#define CLK_APBCLK0_EADCCKEN_Msk         (0x1ul << CLK_APBCLK0_EADCCKEN_Pos)               /*!< CLK_T::APBCLK0: EADCCKEN Mask          */

#define CLK_APBCLK0_TKCKEN_Pos           (29)                                              /*!< CLK_T::APBCLK0: TKCKEN Position        */
#define CLK_APBCLK0_TKCKEN_Msk           (0x1ul << CLK_APBCLK0_TKCKEN_Pos)                 /*!< CLK_T::APBCLK0: TKCKEN Mask            */

#define CLK_APBCLK1_SC0CKEN_Pos          (0)                                               /*!< CLK_T::APBCLK1: SC0CKEN Position       */
#define CLK_APBCLK1_SC0CKEN_Msk          (0x1ul << CLK_APBCLK1_SC0CKEN_Pos)                /*!< CLK_T::APBCLK1: SC0CKEN Mask           */

#define CLK_APBCLK1_USCI0CKEN_Pos        (8)                                               /*!< CLK_T::APBCLK1: USCI0CKEN Position     */
#define CLK_APBCLK1_USCI0CKEN_Msk        (0x1ul << CLK_APBCLK1_USCI0CKEN_Pos)              /*!< CLK_T::APBCLK1: USCI0CKEN Mask         */

#define CLK_APBCLK1_USCI1CKEN_Pos        (9)                                               /*!< CLK_T::APBCLK1: USCI1CKEN Position     */
#define CLK_APBCLK1_USCI1CKEN_Msk        (0x1ul << CLK_APBCLK1_USCI1CKEN_Pos)              /*!< CLK_T::APBCLK1: USCI1CKEN Mask         */

#define CLK_APBCLK1_USCI2CKEN_Pos        (10)                                              /*!< CLK_T::APBCLK1: USCI2CKEN Position     */
#define CLK_APBCLK1_USCI2CKEN_Msk        (0x1ul << CLK_APBCLK1_USCI2CKEN_Pos)              /*!< CLK_T::APBCLK1: USCI2CKEN Mask         */

#define CLK_APBCLK1_DACCKEN_Pos          (12)                                              /*!< CLK_T::APBCLK1: DACCKEN Position       */
#define CLK_APBCLK1_DACCKEN_Msk          (0x1ul << CLK_APBCLK1_DACCKEN_Pos)                /*!< CLK_T::APBCLK1: DACCKEN Mask           */

#define CLK_APBCLK1_LCDCKEN_Pos          (14)                                              /*!< CLK_T::APBCLK1: LCDCKEN Position       */
#define CLK_APBCLK1_LCDCKEN_Msk          (0x1ul << CLK_APBCLK1_LCDCKEN_Pos)                /*!< CLK_T::APBCLK1: LCDCKEN Mask           */

#define CLK_APBCLK1_LCDCPCKEN_Pos        (15)                                              /*!< CLK_T::APBCLK1: LCDCPCKEN Position     */
#define CLK_APBCLK1_LCDCPCKEN_Msk        (0x1ul << CLK_APBCLK1_LCDCPCKEN_Pos)              /*!< CLK_T::APBCLK1: LCDCPCKEN Mask         */

#define CLK_APBCLK1_PWM0CKEN_Pos         (16)                                              /*!< CLK_T::APBCLK1: PWM0CKEN Position      */
#define CLK_APBCLK1_PWM0CKEN_Msk         (0x1ul << CLK_APBCLK1_PWM0CKEN_Pos)               /*!< CLK_T::APBCLK1: PWM0CKEN Mask          */

#define CLK_APBCLK1_PWM1CKEN_Pos         (17)                                              /*!< CLK_T::APBCLK1: PWM1CKEN Position      */
#define CLK_APBCLK1_PWM1CKEN_Msk         (0x1ul << CLK_APBCLK1_PWM1CKEN_Pos)               /*!< CLK_T::APBCLK1: PWM1CKEN Mask          */

#define CLK_APBCLK1_BPWM0CKEN_Pos        (18)                                              /*!< CLK_T::APBCLK1: BPWM0CKEN Position     */
#define CLK_APBCLK1_BPWM0CKEN_Msk        (0x1ul << CLK_APBCLK1_BPWM0CKEN_Pos)              /*!< CLK_T::APBCLK1: BPWM0CKEN Mask         */

#define CLK_APBCLK1_BPWM1CKEN_Pos        (19)                                              /*!< CLK_T::APBCLK1: BPWM1CKEN Position     */
#define CLK_APBCLK1_BPWM1CKEN_Msk        (0x1ul << CLK_APBCLK1_BPWM1CKEN_Pos)              /*!< CLK_T::APBCLK1: BPWM1CKEN Mask         */

#define CLK_APBCLK1_OPACKEN_Pos          (30)                                              /*!< CLK_T::APBCLK1: OPACKEN Position       */
#define CLK_APBCLK1_OPACKEN_Msk          (0x1ul << CLK_APBCLK1_OPACKEN_Pos)                /*!< CLK_T::APBCLK1: OPACKEN Mask           */

#define CLK_APBCLK1_PSIOCKEN_Pos         (31)                                              /*!< CLK_T::APBCLK1: PSIOCKEN Position      */
#define CLK_APBCLK1_PSIOCKEN_Msk         (0x1ul << CLK_APBCLK1_PSIOCKEN_Pos)               /*!< CLK_T::APBCLK1: PSIOCKEN Mask          */

#define CLK_CLKSEL0_HCLKSEL_Pos          (0)                                               /*!< CLK_T::CLKSEL0: HCLKSEL Position       */
#define CLK_CLKSEL0_HCLKSEL_Msk          (0x7ul << CLK_CLKSEL0_HCLKSEL_Pos)                /*!< CLK_T::CLKSEL0: HCLKSEL Mask           */

#define CLK_CLKSEL0_STCLKSEL_Pos         (3)                                               /*!< CLK_T::CLKSEL0: STCLKSEL Position      */
#define CLK_CLKSEL0_STCLKSEL_Msk         (0x7ul << CLK_CLKSEL0_STCLKSEL_Pos)               /*!< CLK_T::CLKSEL0: STCLKSEL Mask          */

#define CLK_CLKSEL0_USBDSEL_Pos          (8)                                               /*!< CLK_T::CLKSEL0: USBDSEL Position       */
#define CLK_CLKSEL0_USBDSEL_Msk          (0x1ul << CLK_CLKSEL0_USBDSEL_Pos)                /*!< CLK_T::CLKSEL0: USBDSEL Mask           */

#define CLK_CLKSEL1_WDTSEL_Pos           (0)                                               /*!< CLK_T::CLKSEL1: WDTSEL Position        */
#define CLK_CLKSEL1_WDTSEL_Msk           (0x3ul << CLK_CLKSEL1_WDTSEL_Pos)                 /*!< CLK_T::CLKSEL1: WDTSEL Mask            */

#define CLK_CLKSEL1_WWDTSEL_Pos          (2)                                               /*!< CLK_T::CLKSEL1: WWDTSEL Position       */
#define CLK_CLKSEL1_WWDTSEL_Msk          (0x3ul << CLK_CLKSEL1_WWDTSEL_Pos)                /*!< CLK_T::CLKSEL1: WWDTSEL Mask           */

#define CLK_CLKSEL1_CLKOSEL_Pos          (4)                                               /*!< CLK_T::CLKSEL1: CLKOSEL Position       */
#define CLK_CLKSEL1_CLKOSEL_Msk          (0x7ul << CLK_CLKSEL1_CLKOSEL_Pos)                /*!< CLK_T::CLKSEL1: CLKOSEL Mask           */

#define CLK_CLKSEL1_TMR0SEL_Pos          (8)                                               /*!< CLK_T::CLKSEL1: TMR0SEL Position       */
#define CLK_CLKSEL1_TMR0SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR0SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR0SEL Mask           */

#define CLK_CLKSEL1_TMR1SEL_Pos          (12)                                              /*!< CLK_T::CLKSEL1: TMR1SEL Position       */
#define CLK_CLKSEL1_TMR1SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR1SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR1SEL Mask           */

#define CLK_CLKSEL1_TMR2SEL_Pos          (16)                                              /*!< CLK_T::CLKSEL1: TMR2SEL Position       */
#define CLK_CLKSEL1_TMR2SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR2SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR2SEL Mask           */

#define CLK_CLKSEL1_TMR3SEL_Pos          (20)                                              /*!< CLK_T::CLKSEL1: TMR3SEL Position       */
#define CLK_CLKSEL1_TMR3SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR3SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR3SEL Mask           */

#define CLK_CLKSEL1_UART0SEL_Pos         (24)                                              /*!< CLK_T::CLKSEL1: UART0SEL Position      */
#define CLK_CLKSEL1_UART0SEL_Msk         (0x7ul << CLK_CLKSEL1_UART0SEL_Pos)               /*!< CLK_T::CLKSEL1: UART0SEL Mask          */

#define CLK_CLKSEL1_UART1SEL_Pos         (28)                                              /*!< CLK_T::CLKSEL1: UART1SEL Position      */
#define CLK_CLKSEL1_UART1SEL_Msk         (0x7ul << CLK_CLKSEL1_UART1SEL_Pos)               /*!< CLK_T::CLKSEL1: UART1SEL Mask          */

#define CLK_CLKSEL2_PWM0SEL_Pos          (0)                                               /*!< CLK_T::CLKSEL2: PWM0SEL Position       */
#define CLK_CLKSEL2_PWM0SEL_Msk          (0x1ul << CLK_CLKSEL2_PWM0SEL_Pos)                /*!< CLK_T::CLKSEL2: PWM0SEL Mask           */

#define CLK_CLKSEL2_PWM1SEL_Pos          (1)                                               /*!< CLK_T::CLKSEL2: PWM1SEL Position       */
#define CLK_CLKSEL2_PWM1SEL_Msk          (0x1ul << CLK_CLKSEL2_PWM1SEL_Pos)                /*!< CLK_T::CLKSEL2: PWM1SEL Mask           */

#define CLK_CLKSEL2_QSPI0SEL_Pos         (2)                                               /*!< CLK_T::CLKSEL2: QSPI0SEL Position      */
#define CLK_CLKSEL2_QSPI0SEL_Msk         (0x3ul << CLK_CLKSEL2_QSPI0SEL_Pos)               /*!< CLK_T::CLKSEL2: QSPI0SEL Mask          */

#define CLK_CLKSEL2_SPI0SEL_Pos          (4)                                               /*!< CLK_T::CLKSEL2: SPI0SEL Position       */
#define CLK_CLKSEL2_SPI0SEL_Msk          (0x3ul << CLK_CLKSEL2_SPI0SEL_Pos)                /*!< CLK_T::CLKSEL2: SPI0SEL Mask           */

#define CLK_CLKSEL2_SPI1SEL_Pos          (6)                                               /*!< CLK_T::CLKSEL2: SPI1SEL Position       */
#define CLK_CLKSEL2_SPI1SEL_Msk          (0x3ul << CLK_CLKSEL2_SPI1SEL_Pos)                /*!< CLK_T::CLKSEL2: SPI1SEL Mask           */

#define CLK_CLKSEL2_BPWM0SEL_Pos         (8)                                               /*!< CLK_T::CLKSEL2: BPWM0SEL Position      */
#define CLK_CLKSEL2_BPWM0SEL_Msk         (0x1ul << CLK_CLKSEL2_BPWM0SEL_Pos)               /*!< CLK_T::CLKSEL2: BPWM0SEL Mask          */

#define CLK_CLKSEL2_BPWM1SEL_Pos         (9)                                               /*!< CLK_T::CLKSEL2: BPWM1SEL Position      */
#define CLK_CLKSEL2_BPWM1SEL_Msk         (0x1ul << CLK_CLKSEL2_BPWM1SEL_Pos)               /*!< CLK_T::CLKSEL2: BPWM1SEL Mask          */

#define CLK_CLKSEL2_LCDSEL_Pos           (24)                                              /*!< CLK_T::CLKSEL2: LCDSEL Position        */
#define CLK_CLKSEL2_LCDSEL_Msk           (0x1ul << CLK_CLKSEL2_LCDSEL_Pos)                 /*!< CLK_T::CLKSEL2: LCDSEL Mask            */

#define CLK_CLKSEL2_LCDCPSEL_Pos         (25)                                              /*!< CLK_T::CLKSEL2: LCDCPSEL Position      */
#define CLK_CLKSEL2_LCDCPSEL_Msk         (0x1ul << CLK_CLKSEL2_LCDCPSEL_Pos)               /*!< CLK_T::CLKSEL2: LCDCPSEL Mask          */

#define CLK_CLKSEL2_PSIOSEL_Pos          (28)                                              /*!< CLK_T::CLKSEL2: PSIOSEL Position       */
#define CLK_CLKSEL2_PSIOSEL_Msk          (0x7ul << CLK_CLKSEL2_PSIOSEL_Pos)                /*!< CLK_T::CLKSEL2: PSIOSEL Mask           */

#define CLK_CLKSEL3_SC0SEL_Pos           (0)                                               /*!< CLK_T::CLKSEL3: SC0SEL Position        */
#define CLK_CLKSEL3_SC0SEL_Msk           (0x3ul << CLK_CLKSEL3_SC0SEL_Pos)                 /*!< CLK_T::CLKSEL3: SC0SEL Mask            */

#define CLK_CLKSEL3_UART2SEL_Pos         (24)                                              /*!< CLK_T::CLKSEL3: UART2SEL Position      */
#define CLK_CLKSEL3_UART2SEL_Msk         (0x7ul << CLK_CLKSEL3_UART2SEL_Pos)               /*!< CLK_T::CLKSEL3: UART2SEL Mask          */

#define CLK_CLKSEL3_UART3SEL_Pos         (28)                                              /*!< CLK_T::CLKSEL3: UART3SEL Position      */
#define CLK_CLKSEL3_UART3SEL_Msk         (0x7ul << CLK_CLKSEL3_UART3SEL_Pos)               /*!< CLK_T::CLKSEL3: UART3SEL Mask          */

#define CLK_CLKDIV0_HCLKDIV_Pos          (0)                                               /*!< CLK_T::CLKDIV0: HCLKDIV Position       */
#define CLK_CLKDIV0_HCLKDIV_Msk          (0xful << CLK_CLKDIV0_HCLKDIV_Pos)                /*!< CLK_T::CLKDIV0: HCLKDIV Mask           */

#define CLK_CLKDIV0_USBDIV_Pos           (4)                                               /*!< CLK_T::CLKDIV0: USBDIV Position        */
#define CLK_CLKDIV0_USBDIV_Msk           (0xful << CLK_CLKDIV0_USBDIV_Pos)                 /*!< CLK_T::CLKDIV0: USBDIV Mask            */

#define CLK_CLKDIV0_UART0DIV_Pos         (8)                                               /*!< CLK_T::CLKDIV0: UART0DIV Position      */
#define CLK_CLKDIV0_UART0DIV_Msk         (0xful << CLK_CLKDIV0_UART0DIV_Pos)               /*!< CLK_T::CLKDIV0: UART0DIV Mask          */

#define CLK_CLKDIV0_UART1DIV_Pos         (12)                                              /*!< CLK_T::CLKDIV0: UART1DIV Position      */
#define CLK_CLKDIV0_UART1DIV_Msk         (0xful << CLK_CLKDIV0_UART1DIV_Pos)               /*!< CLK_T::CLKDIV0: UART1DIV Mask          */

#define CLK_CLKDIV0_EADCDIV_Pos          (16)                                              /*!< CLK_T::CLKDIV0: EADCDIV Position       */
#define CLK_CLKDIV0_EADCDIV_Msk          (0xfful << CLK_CLKDIV0_EADCDIV_Pos)               /*!< CLK_T::CLKDIV0: EADCDIV Mask           */

#define CLK_CLKDIV1_SC0DIV_Pos           (0)                                               /*!< CLK_T::CLKDIV1: SC0DIV Position        */
#define CLK_CLKDIV1_SC0DIV_Msk           (0xfful << CLK_CLKDIV1_SC0DIV_Pos)                /*!< CLK_T::CLKDIV1: SC0DIV Mask            */

#define CLK_CLKDIV1_PSIODIV_Pos          (24)                                              /*!< CLK_T::CLKDIV1: PSIODIV Position       */
#define CLK_CLKDIV1_PSIODIV_Msk          (0xfful << CLK_CLKDIV1_PSIODIV_Pos)               /*!< CLK_T::CLKDIV1: PSIODIV Mask           */

#define CLK_CLKDIV4_UART2DIV_Pos         (0)                                               /*!< CLK_T::CLKDIV4: UART2DIV Position      */
#define CLK_CLKDIV4_UART2DIV_Msk         (0xful << CLK_CLKDIV4_UART2DIV_Pos)               /*!< CLK_T::CLKDIV4: UART2DIV Mask          */

#define CLK_CLKDIV4_UART3DIV_Pos         (4)                                               /*!< CLK_T::CLKDIV4: UART3DIV Position      */
#define CLK_CLKDIV4_UART3DIV_Msk         (0xful << CLK_CLKDIV4_UART3DIV_Pos)               /*!< CLK_T::CLKDIV4: UART3DIV Mask          */

#define CLK_PCLKDIV_APB0DIV_Pos          (0)                                               /*!< CLK_T::PCLKDIV: APB0DIV Position       */
#define CLK_PCLKDIV_APB0DIV_Msk          (0x7ul << CLK_PCLKDIV_APB0DIV_Pos)                /*!< CLK_T::PCLKDIV: APB0DIV Mask           */

#define CLK_PCLKDIV_APB1DIV_Pos          (4)                                               /*!< CLK_T::PCLKDIV: APB1DIV Position       */
#define CLK_PCLKDIV_APB1DIV_Msk          (0x7ul << CLK_PCLKDIV_APB1DIV_Pos)                /*!< CLK_T::PCLKDIV: APB1DIV Mask           */

#define CLK_PLLCTL_FBDIV_Pos             (0)                                               /*!< CLK_T::PLLCTL: FBDIV Position          */
#define CLK_PLLCTL_FBDIV_Msk             (0x3ful << CLK_PLLCTL_FBDIV_Pos)                  /*!< CLK_T::PLLCTL: FBDIV Mask              */

#define CLK_PLLCTL_INDIV_Pos             (9)                                               /*!< CLK_T::PLLCTL: INDIV Position          */
#define CLK_PLLCTL_INDIV_Msk             (0xful << CLK_PLLCTL_INDIV_Pos)                   /*!< CLK_T::PLLCTL: INDIV Mask              */

#define CLK_PLLCTL_OUTDIV_Pos            (14)                                              /*!< CLK_T::PLLCTL: OUTDIV Position         */
#define CLK_PLLCTL_OUTDIV_Msk            (0x3ul << CLK_PLLCTL_OUTDIV_Pos)                  /*!< CLK_T::PLLCTL: OUTDIV Mask             */

#define CLK_PLLCTL_PD_Pos                (16)                                              /*!< CLK_T::PLLCTL: PD Position             */
#define CLK_PLLCTL_PD_Msk                (0x1ul << CLK_PLLCTL_PD_Pos)                      /*!< CLK_T::PLLCTL: PD Mask                 */

#define CLK_PLLCTL_BP_Pos                (17)                                              /*!< CLK_T::PLLCTL: BP Position             */
#define CLK_PLLCTL_BP_Msk                (0x1ul << CLK_PLLCTL_BP_Pos)                      /*!< CLK_T::PLLCTL: BP Mask                 */

#define CLK_PLLCTL_OE_Pos                (18)                                              /*!< CLK_T::PLLCTL: OE Position             */
#define CLK_PLLCTL_OE_Msk                (0x1ul << CLK_PLLCTL_OE_Pos)                      /*!< CLK_T::PLLCTL: OE Mask                 */

#define CLK_PLLCTL_PLLSRC_Pos            (19)                                              /*!< CLK_T::PLLCTL: PLLSRC Position         */
#define CLK_PLLCTL_PLLSRC_Msk            (0x1ul << CLK_PLLCTL_PLLSRC_Pos)                  /*!< CLK_T::PLLCTL: PLLSRC Mask             */

#define CLK_PLLCTL_STBSEL_Pos            (23)                                              /*!< CLK_T::PLLCTL: STBSEL Position         */
#define CLK_PLLCTL_STBSEL_Msk            (0x1ul << CLK_PLLCTL_STBSEL_Pos)                  /*!< CLK_T::PLLCTL: STBSEL Mask             */

#define CLK_PLLCTL_PLL_CLF_EN_Pos        (24)                                              /*!< CLK_T::PLLCTL: PLL_CLF_EN Position     */
#define CLK_PLLCTL_PLL_CLF_EN_Msk        (0x1ul << CLK_PLLCTL_PLL_CLF_EN_Pos)              /*!< CLK_T::PLLCTL: PLL_CLF_EN Mask         */

#define CLK_STATUS_HXTSTB_Pos            (0)                                               /*!< CLK_T::STATUS: HXTSTB Position         */
#define CLK_STATUS_HXTSTB_Msk            (0x1ul << CLK_STATUS_HXTSTB_Pos)                  /*!< CLK_T::STATUS: HXTSTB Mask             */

#define CLK_STATUS_LXTSTB_Pos            (1)                                               /*!< CLK_T::STATUS: LXTSTB Position         */
#define CLK_STATUS_LXTSTB_Msk            (0x1ul << CLK_STATUS_LXTSTB_Pos)                  /*!< CLK_T::STATUS: LXTSTB Mask             */

#define CLK_STATUS_PLLSTB_Pos            (2)                                               /*!< CLK_T::STATUS: PLLSTB Position         */
#define CLK_STATUS_PLLSTB_Msk            (0x1ul << CLK_STATUS_PLLSTB_Pos)                  /*!< CLK_T::STATUS: PLLSTB Mask             */

#define CLK_STATUS_LIRCSTB_Pos           (3)                                               /*!< CLK_T::STATUS: LIRCSTB Position        */
#define CLK_STATUS_LIRCSTB_Msk           (0x1ul << CLK_STATUS_LIRCSTB_Pos)                 /*!< CLK_T::STATUS: LIRCSTB Mask            */

#define CLK_STATUS_HIRCSTB_Pos           (4)                                               /*!< CLK_T::STATUS: HIRCSTB Position        */
#define CLK_STATUS_HIRCSTB_Msk           (0x1ul << CLK_STATUS_HIRCSTB_Pos)                 /*!< CLK_T::STATUS: HIRCSTB Mask            */

#define CLK_STATUS_MIRCSTB_Pos           (6)                                               /*!< CLK_T::STATUS: MIRCSTB Position        */
#define CLK_STATUS_MIRCSTB_Msk           (0x1ul << CLK_STATUS_MIRCSTB_Pos)                 /*!< CLK_T::STATUS: MIRCSTB Mask            */

#define CLK_STATUS_CLKSFAIL_Pos          (7)                                               /*!< CLK_T::STATUS: CLKSFAIL Position       */
#define CLK_STATUS_CLKSFAIL_Msk          (0x1ul << CLK_STATUS_CLKSFAIL_Pos)                /*!< CLK_T::STATUS: CLKSFAIL Mask           */

#define CLK_CLKOCTL_FREQSEL_Pos          (0)                                               /*!< CLK_T::CLKOCTL: FREQSEL Position       */
#define CLK_CLKOCTL_FREQSEL_Msk          (0xful << CLK_CLKOCTL_FREQSEL_Pos)                /*!< CLK_T::CLKOCTL: FREQSEL Mask           */

#define CLK_CLKOCTL_CLKOEN_Pos           (4)                                               /*!< CLK_T::CLKOCTL: CLKOEN Position        */
#define CLK_CLKOCTL_CLKOEN_Msk           (0x1ul << CLK_CLKOCTL_CLKOEN_Pos)                 /*!< CLK_T::CLKOCTL: CLKOEN Mask            */

#define CLK_CLKOCTL_DIV1EN_Pos           (5)                                               /*!< CLK_T::CLKOCTL: DIV1EN Position        */
#define CLK_CLKOCTL_DIV1EN_Msk           (0x1ul << CLK_CLKOCTL_DIV1EN_Pos)                 /*!< CLK_T::CLKOCTL: DIV1EN Mask            */

#define CLK_CLKOCTL_CLK1HZEN_Pos         (6)                                               /*!< CLK_T::CLKOCTL: CLK1HZEN Position      */
#define CLK_CLKOCTL_CLK1HZEN_Msk         (0x1ul << CLK_CLKOCTL_CLK1HZEN_Pos)               /*!< CLK_T::CLKOCTL: CLK1HZEN Mask          */

#define CLK_CLKDCTL_HXTFDEN_Pos          (4)                                               /*!< CLK_T::CLKDCTL: HXTFDEN Position       */
#define CLK_CLKDCTL_HXTFDEN_Msk          (0x1ul << CLK_CLKDCTL_HXTFDEN_Pos)                /*!< CLK_T::CLKDCTL: HXTFDEN Mask           */

#define CLK_CLKDCTL_HXTFIEN_Pos          (5)                                               /*!< CLK_T::CLKDCTL: HXTFIEN Position       */
#define CLK_CLKDCTL_HXTFIEN_Msk          (0x1ul << CLK_CLKDCTL_HXTFIEN_Pos)                /*!< CLK_T::CLKDCTL: HXTFIEN Mask           */

#define CLK_CLKDCTL_LXTFDEN_Pos          (12)                                              /*!< CLK_T::CLKDCTL: LXTFDEN Position       */
#define CLK_CLKDCTL_LXTFDEN_Msk          (0x1ul << CLK_CLKDCTL_LXTFDEN_Pos)                /*!< CLK_T::CLKDCTL: LXTFDEN Mask           */

#define CLK_CLKDCTL_LXTFIEN_Pos          (13)                                              /*!< CLK_T::CLKDCTL: LXTFIEN Position       */
#define CLK_CLKDCTL_LXTFIEN_Msk          (0x1ul << CLK_CLKDCTL_LXTFIEN_Pos)                /*!< CLK_T::CLKDCTL: LXTFIEN Mask           */

#define CLK_CLKDCTL_HXTFQDEN_Pos         (16)                                              /*!< CLK_T::CLKDCTL: HXTFQDEN Position      */
#define CLK_CLKDCTL_HXTFQDEN_Msk         (0x1ul << CLK_CLKDCTL_HXTFQDEN_Pos)               /*!< CLK_T::CLKDCTL: HXTFQDEN Mask          */

#define CLK_CLKDCTL_HXTFQIEN_Pos         (17)                                              /*!< CLK_T::CLKDCTL: HXTFQIEN Position      */
#define CLK_CLKDCTL_HXTFQIEN_Msk         (0x1ul << CLK_CLKDCTL_HXTFQIEN_Pos)               /*!< CLK_T::CLKDCTL: HXTFQIEN Mask          */

#define CLK_CLKDSTS_HXTFIF_Pos           (0)                                               /*!< CLK_T::CLKDSTS: HXTFIF Position        */
#define CLK_CLKDSTS_HXTFIF_Msk           (0x1ul << CLK_CLKDSTS_HXTFIF_Pos)                 /*!< CLK_T::CLKDSTS: HXTFIF Mask            */

#define CLK_CLKDSTS_LXTFIF_Pos           (1)                                               /*!< CLK_T::CLKDSTS: LXTFIF Position        */
#define CLK_CLKDSTS_LXTFIF_Msk           (0x1ul << CLK_CLKDSTS_LXTFIF_Pos)                 /*!< CLK_T::CLKDSTS: LXTFIF Mask            */

#define CLK_CLKDSTS_HXTFQIF_Pos          (8)                                               /*!< CLK_T::CLKDSTS: HXTFQIF Position       */
#define CLK_CLKDSTS_HXTFQIF_Msk          (0x1ul << CLK_CLKDSTS_HXTFQIF_Pos)                /*!< CLK_T::CLKDSTS: HXTFQIF Mask           */

#define CLK_CDUPB_UPERBD_Pos             (0)                                               /*!< CLK_T::CDUPB: UPERBD Position          */
#define CLK_CDUPB_UPERBD_Msk             (0x3fful << CLK_CDUPB_UPERBD_Pos)                 /*!< CLK_T::CDUPB: UPERBD Mask              */

#define CLK_CDLOWB_LOWERBD_Pos           (0)                                               /*!< CLK_T::CDLOWB: LOWERBD Position        */
#define CLK_CDLOWB_LOWERBD_Msk           (0x3fful << CLK_CDLOWB_LOWERBD_Pos)               /*!< CLK_T::CDLOWB: LOWERBD Mask            */

#define CLK_PMUCTL_PDMSEL_Pos            (0)                                               /*!< CLK_T::PMUCTL: PDMSEL Position         */
#define CLK_PMUCTL_PDMSEL_Msk            (0x7ul << CLK_PMUCTL_PDMSEL_Pos)                  /*!< CLK_T::PMUCTL: PDMSEL Mask             */

#define CLK_PMUCTL_WKTMREN_Pos           (8)                                               /*!< CLK_T::PMUCTL: WKTMREN Position        */
#define CLK_PMUCTL_WKTMREN_Msk           (0x1ul << CLK_PMUCTL_WKTMREN_Pos)                 /*!< CLK_T::PMUCTL: WKTMREN Mask            */

#define CLK_PMUCTL_WKTMRIS_Pos           (9)                                               /*!< CLK_T::PMUCTL: WKTMRIS Position        */
#define CLK_PMUCTL_WKTMRIS_Msk           (0x7ul << CLK_PMUCTL_WKTMRIS_Pos)                 /*!< CLK_T::PMUCTL: WKTMRIS Mask            */

#define CLK_PMUCTL_WKPINEN0_Pos          (16)                                              /*!< CLK_T::PMUCTL: WKPINEN0 Position        */
#define CLK_PMUCTL_WKPINEN0_Msk          (0x3ul << CLK_PMUCTL_WKPINEN0_Pos)                /*!< CLK_T::PMUCTL: WKPINEN0 Mask            */

#define CLK_PMUCTL_WKPINDBEN_Pos         (22)                                              /*!< CLK_T::PMUCTL: WKPINDBEN Position        */
#define CLK_PMUCTL_WKPINDBEN_Msk         (0x1ul << CLK_PMUCTL_WKPINDBEN_Pos)               /*!< CLK_T::PMUCTL: WKPINDBEN Mask            */

#define CLK_PMUCTL_RTCWKEN_Pos           (23)                                              /*!< CLK_T::PMUCTL: RTCWKEN Position        */
#define CLK_PMUCTL_RTCWKEN_Msk           (0x1ul << CLK_PMUCTL_RTCWKEN_Pos)                 /*!< CLK_T::PMUCTL: RTCWKEN Mask            */

#define CLK_PMUCTL_WKPINEN1_Pos          (24)                                              /*!< CLK_T::PMUCTL: WKPINEN1 Position        */
#define CLK_PMUCTL_WKPINEN1_Msk          (0x3ul << CLK_PMUCTL_WKPINEN1_Pos)                /*!< CLK_T::PMUCTL: WKPINEN1 Mask            */

#define CLK_PMUCTL_WKPINEN2_Pos          (26)                                              /*!< CLK_T::PMUCTL: WKPINEN2 Position        */
#define CLK_PMUCTL_WKPINEN2_Msk          (0x3ul << CLK_PMUCTL_WKPINEN2_Pos)                /*!< CLK_T::PMUCTL: WKPINEN2 Mask            */

#define CLK_PMUCTL_WKPINEN3_Pos          (28)                                              /*!< CLK_T::PMUCTL: WKPINEN3 Position        */
#define CLK_PMUCTL_WKPINEN3_Msk          (0x3ul << CLK_PMUCTL_WKPINEN3_Pos)                /*!< CLK_T::PMUCTL: WKPINEN3 Mask            */

#define CLK_PMUCTL_WKPINEN4_Pos          (30)                                              /*!< CLK_T::PMUCTL: WKPINEN4 Position        */
#define CLK_PMUCTL_WKPINEN4_Msk          (0x3ul << CLK_PMUCTL_WKPINEN4_Pos)                /*!< CLK_T::PMUCTL: WKPINEN4 Mask            */

#define CLK_PMUSTS_PINWK0_Pos            (0)                                               /*!< CLK_T::PMUSTS: PINWK0 Position          */
#define CLK_PMUSTS_PINWK0_Msk            (0x1ul << CLK_PMUSTS_PINWK0_Pos)                  /*!< CLK_T::PMUSTS: PINWK0 Mask              */

#define CLK_PMUSTS_TMRWK_Pos             (1)                                               /*!< CLK_T::PMUSTS: TMRWK Position          */
#define CLK_PMUSTS_TMRWK_Msk             (0x1ul << CLK_PMUSTS_TMRWK_Pos)                   /*!< CLK_T::PMUSTS: TMRWK Mask              */

#define CLK_PMUSTS_RTCWK_Pos             (2)                                               /*!< CLK_T::PMUSTS: RTCWK Position          */
#define CLK_PMUSTS_RTCWK_Msk             (0x1ul << CLK_PMUSTS_RTCWK_Pos)                   /*!< CLK_T::PMUSTS: RTCWK Mask              */

#define CLK_PMUSTS_PINWK1_Pos            (3)                                               /*!< CLK_T::PMUSTS: PINWK1 Position          */
#define CLK_PMUSTS_PINWK1_Msk            (0x1ul << CLK_PMUSTS_PINWK1_Pos)                  /*!< CLK_T::PMUSTS: PINWK1 Mask              */

#define CLK_PMUSTS_PINWK2_Pos            (4)                                               /*!< CLK_T::PMUSTS: PINWK2 Position          */
#define CLK_PMUSTS_PINWK2_Msk            (0x1ul << CLK_PMUSTS_PINWK2_Pos)                  /*!< CLK_T::PMUSTS: PINWK2 Mask              */

#define CLK_PMUSTS_PINWK3_Pos            (5)                                               /*!< CLK_T::PMUSTS: PINWK3 Position          */
#define CLK_PMUSTS_PINWK3_Msk            (0x1ul << CLK_PMUSTS_PINWK3_Pos)                  /*!< CLK_T::PMUSTS: PINWK3 Mask              */

#define CLK_PMUSTS_PINWK4_Pos            (6)                                               /*!< CLK_T::PMUSTS: PINWK4 Position          */
#define CLK_PMUSTS_PINWK4_Msk            (0x1ul << CLK_PMUSTS_PINWK4_Pos)                  /*!< CLK_T::PMUSTS: PINWK4 Mask              */

#define CLK_PMUSTS_LVRWK_Pos             (12)                                              /*!< CLK_T::PMUSTS: LVRWK Position          */
#define CLK_PMUSTS_LVRWK_Msk             (0x1ul << CLK_PMUSTS_LVRWK_Pos)                   /*!< CLK_T::PMUSTS: LVRWK Mask              */

#define CLK_PMUSTS_CLRWK_Pos             (31)                                              /*!< CLK_T::PMUSTS: CLRWK Position          */
#define CLK_PMUSTS_CLRWK_Msk             (0x1ul << CLK_PMUSTS_CLRWK_Pos)                   /*!< CLK_T::PMUSTS: CLRWK Mask              */

#define CLK_HXTFSEL_HXTFSEL_Pos          (0)                                               /*!< CLK_T::HXTFSEL: HXTFSEL Position       */
#define CLK_HXTFSEL_HXTFSEL_Msk          (0x1ul << CLK_HXTFSEL_HXTFSEL_Pos)                /*!< CLK_T::HXTFSEL: HXTFSEL Mask           */

/** @} CLK_CONST */
/** @} end of CLK register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __CLK_REG_H__ */
