/**************************************************************************//**
 * @file     bpwm_reg.h
 * @version  V1.00
 * @brief    BPWM register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __BPWM_REG_H__
#define __BPWM_REG_H__


#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup BPWM_CONST BPWM Bit Field Definition
    Constant Definitions for BPWM Controller
@{ */

#define BPWM_CTL0_CTRLD0_Pos            (0)                                               /*!< BPWM_T::CTL0: CTRLD0 Position         */
#define BPWM_CTL0_CTRLD0_Msk            (0x1ul << BPWM_CTL0_CTRLD0_Pos)                   /*!< BPWM_T::CTL0: CTRLD0 Mask             */

#define BPWM_CTL0_CTRLD1_Pos            (1)                                               /*!< BPWM_T::CTL0: CTRLD1 Position         */
#define BPWM_CTL0_CTRLD1_Msk            (0x1ul << BPWM_CTL0_CTRLD1_Pos)                   /*!< BPWM_T::CTL0: CTRLD1 Mask             */

#define BPWM_CTL0_CTRLD2_Pos            (2)                                               /*!< BPWM_T::CTL0: CTRLD2 Position         */
#define BPWM_CTL0_CTRLD2_Msk            (0x1ul << BPWM_CTL0_CTRLD2_Pos)                   /*!< BPWM_T::CTL0: CTRLD2 Mask             */

#define BPWM_CTL0_CTRLD3_Pos            (3)                                               /*!< BPWM_T::CTL0: CTRLD3 Position         */
#define BPWM_CTL0_CTRLD3_Msk            (0x1ul << BPWM_CTL0_CTRLD3_Pos)                   /*!< BPWM_T::CTL0: CTRLD3 Mask             */

#define BPWM_CTL0_CTRLD4_Pos            (4)                                               /*!< BPWM_T::CTL0: CTRLD4 Position         */
#define BPWM_CTL0_CTRLD4_Msk            (0x1ul << BPWM_CTL0_CTRLD4_Pos)                   /*!< BPWM_T::CTL0: CTRLD4 Mask             */

#define BPWM_CTL0_CTRLD5_Pos            (5)                                               /*!< BPWM_T::CTL0: CTRLD5 Position         */
#define BPWM_CTL0_CTRLD5_Msk            (0x1ul << BPWM_CTL0_CTRLD5_Pos)                   /*!< BPWM_T::CTL0: CTRLD5 Mask             */

#define BPWM_CTL0_IMMLDEN0_Pos          (16)                                              /*!< BPWM_T::CTL0: IMMLDEN0 Position       */
#define BPWM_CTL0_IMMLDEN0_Msk          (0x1ul << BPWM_CTL0_IMMLDEN0_Pos)                 /*!< BPWM_T::CTL0: IMMLDEN0 Mask           */

#define BPWM_CTL0_IMMLDEN1_Pos          (17)                                              /*!< BPWM_T::CTL0: IMMLDEN1 Position       */
#define BPWM_CTL0_IMMLDEN1_Msk          (0x1ul << BPWM_CTL0_IMMLDEN1_Pos)                 /*!< BPWM_T::CTL0: IMMLDEN1 Mask           */

#define BPWM_CTL0_IMMLDEN2_Pos          (18)                                              /*!< BPWM_T::CTL0: IMMLDEN2 Position       */
#define BPWM_CTL0_IMMLDEN2_Msk          (0x1ul << BPWM_CTL0_IMMLDEN2_Pos)                 /*!< BPWM_T::CTL0: IMMLDEN2 Mask           */

#define BPWM_CTL0_IMMLDEN3_Pos          (19)                                              /*!< BPWM_T::CTL0: IMMLDEN3 Position       */
#define BPWM_CTL0_IMMLDEN3_Msk          (0x1ul << BPWM_CTL0_IMMLDEN3_Pos)                 /*!< BPWM_T::CTL0: IMMLDEN3 Mask           */

#define BPWM_CTL0_IMMLDEN4_Pos          (20)                                              /*!< BPWM_T::CTL0: IMMLDEN4 Position       */
#define BPWM_CTL0_IMMLDEN4_Msk          (0x1ul << BPWM_CTL0_IMMLDEN4_Pos)                 /*!< BPWM_T::CTL0: IMMLDEN4 Mask           */

#define BPWM_CTL0_IMMLDEN5_Pos          (21)                                              /*!< BPWM_T::CTL0: IMMLDEN5 Position       */
#define BPWM_CTL0_IMMLDEN5_Msk          (0x1ul << BPWM_CTL0_IMMLDEN5_Pos)                 /*!< BPWM_T::CTL0: IMMLDEN5 Mask           */

#define BPWM_CTL0_DBGHALT_Pos           (30)                                              /*!< BPWM_T::CTL0: DBGHALT Position        */
#define BPWM_CTL0_DBGHALT_Msk           (0x1ul << BPWM_CTL0_DBGHALT_Pos)                  /*!< BPWM_T::CTL0: DBGHALT Mask            */

#define BPWM_CTL0_DBGTRIOFF_Pos         (31)                                              /*!< BPWM_T::CTL0: DBGTRIOFF Position      */
#define BPWM_CTL0_DBGTRIOFF_Msk         (0x1ul << BPWM_CTL0_DBGTRIOFF_Pos)                /*!< BPWM_T::CTL0: DBGTRIOFF Mask          */

#define BPWM_CTL1_CNTTYPE0_Pos          (0)                                               /*!< BPWM_T::CTL1: CNTTYPE0 Position       */
#define BPWM_CTL1_CNTTYPE0_Msk          (0x3ul << BPWM_CTL1_CNTTYPE0_Pos)                 /*!< BPWM_T::CTL1: CNTTYPE0 Mask           */

#define BPWM_CLKSRC_ECLKSRC0_Pos        (0)                                               /*!< BPWM_T::CLKSRC: ECLKSRC0 Position     */
#define BPWM_CLKSRC_ECLKSRC0_Msk        (0x7ul << BPWM_CLKSRC_ECLKSRC0_Pos)               /*!< BPWM_T::CLKSRC: ECLKSRC0 Mask         */

#define BPWM_CLKPSC_CLKPSC_Pos          (0)                                               /*!< BPWM_T::CLKPSC: CLKPSC Position       */
#define BPWM_CLKPSC_CLKPSC_Msk          (0xffful << BPWM_CLKPSC_CLKPSC_Pos)               /*!< BPWM_T::CLKPSC: CLKPSC Mask           */

#define BPWM_CNTEN_CNTEN0_Pos           (0)                                               /*!< BPWM_T::CNTEN: CNTEN0 Position        */
#define BPWM_CNTEN_CNTEN0_Msk           (0x1ul << BPWM_CNTEN_CNTEN0_Pos)                  /*!< BPWM_T::CNTEN: CNTEN0 Mask            */

#define BPWM_CNTCLR_CNTCLR0_Pos         (0)                                               /*!< BPWM_T::CNTCLR: CNTCLR0 Position      */
#define BPWM_CNTCLR_CNTCLR0_Msk         (0x1ul << BPWM_CNTCLR_CNTCLR0_Pos)                /*!< BPWM_T::CNTCLR: CNTCLR0 Mask          */

#define BPWM_PERIOD_PERIOD_Pos          (0)                                               /*!< BPWM_T::PERIOD: PERIOD Position       */
#define BPWM_PERIOD_PERIOD_Msk          (0xfffful << BPWM_PERIOD_PERIOD_Pos)              /*!< BPWM_T::PERIOD: PERIOD Mask           */

#define BPWM_CMPDAT_CMPDAT_Pos          (0)                                               /*!< BPWM_T::CMPDAT0: CMPDAT Position      */
#define BPWM_CMPDAT_CMPDAT_Msk          (0xfffful << BPWM_CMPDAT_CMPDAT_Pos)              /*!< BPWM_T::CMPDAT0: CMPDAT Mask          */

#define BPWM_CNT_CNT_Pos                (0)                                               /*!< BPWM_T::CNT: CNT Position             */
#define BPWM_CNT_CNT_Msk                (0xfffful << BPWM_CNT_CNT_Pos)                    /*!< BPWM_T::CNT: CNT Mask                 */

#define BPWM_CNT_DIRF_Pos               (16)                                              /*!< BPWM_T::CNT: DIRF Position            */
#define BPWM_CNT_DIRF_Msk               (0x1ul << BPWM_CNT_DIRF_Pos)                      /*!< BPWM_T::CNT: DIRF Mask                */

#define BPWM_WGCTL0_ZPCTL0_Pos          (0)                                               /*!< BPWM_T::WGCTL0: ZPCTL0 Position       */
#define BPWM_WGCTL0_ZPCTL0_Msk          (0x3ul << BPWM_WGCTL0_ZPCTL0_Pos)                 /*!< BPWM_T::WGCTL0: ZPCTL0 Mask           */

#define BPWM_WGCTL0_ZPCTL1_Pos          (2)                                               /*!< BPWM_T::WGCTL0: ZPCTL1 Position       */
#define BPWM_WGCTL0_ZPCTL1_Msk          (0x3ul << BPWM_WGCTL0_ZPCTL1_Pos)                 /*!< BPWM_T::WGCTL0: ZPCTL1 Mask           */

#define BPWM_WGCTL0_ZPCTL2_Pos          (4)                                               /*!< BPWM_T::WGCTL0: ZPCTL2 Position       */
#define BPWM_WGCTL0_ZPCTL2_Msk          (0x3ul << BPWM_WGCTL0_ZPCTL2_Pos)                 /*!< BPWM_T::WGCTL0: ZPCTL2 Mask           */

#define BPWM_WGCTL0_ZPCTL3_Pos          (6)                                               /*!< BPWM_T::WGCTL0: ZPCTL3 Position       */
#define BPWM_WGCTL0_ZPCTL3_Msk          (0x3ul << BPWM_WGCTL0_ZPCTL3_Pos)                 /*!< BPWM_T::WGCTL0: ZPCTL3 Mask           */

#define BPWM_WGCTL0_ZPCTL4_Pos          (8)                                               /*!< BPWM_T::WGCTL0: ZPCTL4 Position       */
#define BPWM_WGCTL0_ZPCTL4_Msk          (0x3ul << BPWM_WGCTL0_ZPCTL4_Pos)                 /*!< BPWM_T::WGCTL0: ZPCTL4 Mask           */

#define BPWM_WGCTL0_ZPCTL5_Pos          (10)                                              /*!< BPWM_T::WGCTL0: ZPCTL5 Position       */
#define BPWM_WGCTL0_ZPCTL5_Msk          (0x3ul << BPWM_WGCTL0_ZPCTL5_Pos)                 /*!< BPWM_T::WGCTL0: ZPCTL5 Mask           */

#define BPWM_WGCTL0_PRDPCTL0_Pos        (16)                                              /*!< BPWM_T::WGCTL0: PRDPCTL0 Position     */
#define BPWM_WGCTL0_PRDPCTL0_Msk        (0x3ul << BPWM_WGCTL0_PRDPCTL0_Pos)               /*!< BPWM_T::WGCTL0: PRDPCTL0 Mask         */

#define BPWM_WGCTL0_PRDPCTL1_Pos        (18)                                              /*!< BPWM_T::WGCTL0: PRDPCTL1 Position     */
#define BPWM_WGCTL0_PRDPCTL1_Msk        (0x3ul << BPWM_WGCTL0_PRDPCTL1_Pos)               /*!< BPWM_T::WGCTL0: PRDPCTL1 Mask         */

#define BPWM_WGCTL0_PRDPCTL2_Pos        (20)                                              /*!< BPWM_T::WGCTL0: PRDPCTL2 Position     */
#define BPWM_WGCTL0_PRDPCTL2_Msk        (0x3ul << BPWM_WGCTL0_PRDPCTL2_Pos)               /*!< BPWM_T::WGCTL0: PRDPCTL2 Mask         */

#define BPWM_WGCTL0_PRDPCTL3_Pos        (22)                                              /*!< BPWM_T::WGCTL0: PRDPCTL3 Position     */
#define BPWM_WGCTL0_PRDPCTL3_Msk        (0x3ul << BPWM_WGCTL0_PRDPCTL3_Pos)               /*!< BPWM_T::WGCTL0: PRDPCTL3 Mask         */

#define BPWM_WGCTL0_PRDPCTL4_Pos        (24)                                              /*!< BPWM_T::WGCTL0: PRDPCTL4 Position     */
#define BPWM_WGCTL0_PRDPCTL4_Msk        (0x3ul << BPWM_WGCTL0_PRDPCTL4_Pos)               /*!< BPWM_T::WGCTL0: PRDPCTL4 Mask         */

#define BPWM_WGCTL0_PRDPCTL5_Pos        (26)                                              /*!< BPWM_T::WGCTL0: PRDPCTL5 Position     */
#define BPWM_WGCTL0_PRDPCTL5_Msk        (0x3ul << BPWM_WGCTL0_PRDPCTL5_Pos)               /*!< BPWM_T::WGCTL0: PRDPCTL5 Mask         */

#define BPWM_WGCTL1_CMPUCTL0_Pos        (0)                                               /*!< BPWM_T::WGCTL1: CMPUCTL0 Position     */
#define BPWM_WGCTL1_CMPUCTL0_Msk        (0x3ul << BPWM_WGCTL1_CMPUCTL0_Pos)               /*!< BPWM_T::WGCTL1: CMPUCTL0 Mask         */

#define BPWM_WGCTL1_CMPUCTL1_Pos        (2)                                               /*!< BPWM_T::WGCTL1: CMPUCTL1 Position     */
#define BPWM_WGCTL1_CMPUCTL1_Msk        (0x3ul << BPWM_WGCTL1_CMPUCTL1_Pos)               /*!< BPWM_T::WGCTL1: CMPUCTL1 Mask         */

#define BPWM_WGCTL1_CMPUCTL2_Pos        (4)                                               /*!< BPWM_T::WGCTL1: CMPUCTL2 Position     */
#define BPWM_WGCTL1_CMPUCTL2_Msk        (0x3ul << BPWM_WGCTL1_CMPUCTL2_Pos)               /*!< BPWM_T::WGCTL1: CMPUCTL2 Mask         */

#define BPWM_WGCTL1_CMPUCTL3_Pos        (6)                                               /*!< BPWM_T::WGCTL1: CMPUCTL3 Position     */
#define BPWM_WGCTL1_CMPUCTL3_Msk        (0x3ul << BPWM_WGCTL1_CMPUCTL3_Pos)               /*!< BPWM_T::WGCTL1: CMPUCTL3 Mask         */

#define BPWM_WGCTL1_CMPUCTL4_Pos        (8)                                               /*!< BPWM_T::WGCTL1: CMPUCTL4 Position     */
#define BPWM_WGCTL1_CMPUCTL4_Msk        (0x3ul << BPWM_WGCTL1_CMPUCTL4_Pos)               /*!< BPWM_T::WGCTL1: CMPUCTL4 Mask         */

#define BPWM_WGCTL1_CMPUCTL5_Pos        (10)                                              /*!< BPWM_T::WGCTL1: CMPUCTL5 Position     */
#define BPWM_WGCTL1_CMPUCTL5_Msk        (0x3ul << BPWM_WGCTL1_CMPUCTL5_Pos)               /*!< BPWM_T::WGCTL1: CMPUCTL5 Mask         */

#define BPWM_WGCTL1_CMPDCTL0_Pos        (16)                                              /*!< BPWM_T::WGCTL1: CMPDCTL0 Position     */
#define BPWM_WGCTL1_CMPDCTL0_Msk        (0x3ul << BPWM_WGCTL1_CMPDCTL0_Pos)               /*!< BPWM_T::WGCTL1: CMPDCTL0 Mask         */

#define BPWM_WGCTL1_CMPDCTL1_Pos        (18)                                              /*!< BPWM_T::WGCTL1: CMPDCTL1 Position     */
#define BPWM_WGCTL1_CMPDCTL1_Msk        (0x3ul << BPWM_WGCTL1_CMPDCTL1_Pos)               /*!< BPWM_T::WGCTL1: CMPDCTL1 Mask         */

#define BPWM_WGCTL1_CMPDCTL2_Pos        (20)                                              /*!< BPWM_T::WGCTL1: CMPDCTL2 Position     */
#define BPWM_WGCTL1_CMPDCTL2_Msk        (0x3ul << BPWM_WGCTL1_CMPDCTL2_Pos)               /*!< BPWM_T::WGCTL1: CMPDCTL2 Mask         */

#define BPWM_WGCTL1_CMPDCTL3_Pos        (22)                                              /*!< BPWM_T::WGCTL1: CMPDCTL3 Position     */
#define BPWM_WGCTL1_CMPDCTL3_Msk        (0x3ul << BPWM_WGCTL1_CMPDCTL3_Pos)               /*!< BPWM_T::WGCTL1: CMPDCTL3 Mask         */

#define BPWM_WGCTL1_CMPDCTL4_Pos        (24)                                              /*!< BPWM_T::WGCTL1: CMPDCTL4 Position     */
#define BPWM_WGCTL1_CMPDCTL4_Msk        (0x3ul << BPWM_WGCTL1_CMPDCTL4_Pos)               /*!< BPWM_T::WGCTL1: CMPDCTL4 Mask         */

#define BPWM_WGCTL1_CMPDCTL5_Pos        (26)                                              /*!< BPWM_T::WGCTL1: CMPDCTL5 Position     */
#define BPWM_WGCTL1_CMPDCTL5_Msk        (0x3ul << BPWM_WGCTL1_CMPDCTL5_Pos)               /*!< BPWM_T::WGCTL1: CMPDCTL5 Mask         */

#define BPWM_MSKEN_MSKEN0_Pos           (0)                                               /*!< BPWM_T::MSKEN: MSKEN0 Position        */
#define BPWM_MSKEN_MSKEN0_Msk           (0x1ul << BPWM_MSKEN_MSKEN0_Pos)                  /*!< BPWM_T::MSKEN: MSKEN0 Mask            */

#define BPWM_MSKEN_MSKEN1_Pos           (1)                                               /*!< BPWM_T::MSKEN: MSKEN1 Position        */
#define BPWM_MSKEN_MSKEN1_Msk           (0x1ul << BPWM_MSKEN_MSKEN1_Pos)                  /*!< BPWM_T::MSKEN: MSKEN1 Mask            */

#define BPWM_MSKEN_MSKEN2_Pos           (2)                                               /*!< BPWM_T::MSKEN: MSKEN2 Position        */
#define BPWM_MSKEN_MSKEN2_Msk           (0x1ul << BPWM_MSKEN_MSKEN2_Pos)                  /*!< BPWM_T::MSKEN: MSKEN2 Mask            */

#define BPWM_MSKEN_MSKEN3_Pos           (3)                                               /*!< BPWM_T::MSKEN: MSKEN3 Position        */
#define BPWM_MSKEN_MSKEN3_Msk           (0x1ul << BPWM_MSKEN_MSKEN3_Pos)                  /*!< BPWM_T::MSKEN: MSKEN3 Mask            */

#define BPWM_MSKEN_MSKEN4_Pos           (4)                                               /*!< BPWM_T::MSKEN: MSKEN4 Position        */
#define BPWM_MSKEN_MSKEN4_Msk           (0x1ul << BPWM_MSKEN_MSKEN4_Pos)                  /*!< BPWM_T::MSKEN: MSKEN4 Mask            */

#define BPWM_MSKEN_MSKEN5_Pos           (5)                                               /*!< BPWM_T::MSKEN: MSKEN5 Position        */
#define BPWM_MSKEN_MSKEN5_Msk           (0x1ul << BPWM_MSKEN_MSKEN5_Pos)                  /*!< BPWM_T::MSKEN: MSKEN5 Mask            */

#define BPWM_MSK_MSKDAT0_Pos            (0)                                               /*!< BPWM_T::MSK: MSKDAT0 Position         */
#define BPWM_MSK_MSKDAT0_Msk            (0x1ul << BPWM_MSK_MSKDAT0_Pos)                   /*!< BPWM_T::MSK: MSKDAT0 Mask             */

#define BPWM_MSK_MSKDAT1_Pos            (1)                                               /*!< BPWM_T::MSK: MSKDAT1 Position         */
#define BPWM_MSK_MSKDAT1_Msk            (0x1ul << BPWM_MSK_MSKDAT1_Pos)                   /*!< BPWM_T::MSK: MSKDAT1 Mask             */

#define BPWM_MSK_MSKDAT2_Pos            (2)                                               /*!< BPWM_T::MSK: MSKDAT2 Position         */
#define BPWM_MSK_MSKDAT2_Msk            (0x1ul << BPWM_MSK_MSKDAT2_Pos)                   /*!< BPWM_T::MSK: MSKDAT2 Mask             */

#define BPWM_MSK_MSKDAT3_Pos            (3)                                               /*!< BPWM_T::MSK: MSKDAT3 Position         */
#define BPWM_MSK_MSKDAT3_Msk            (0x1ul << BPWM_MSK_MSKDAT3_Pos)                   /*!< BPWM_T::MSK: MSKDAT3 Mask             */

#define BPWM_MSK_MSKDAT4_Pos            (4)                                               /*!< BPWM_T::MSK: MSKDAT4 Position         */
#define BPWM_MSK_MSKDAT4_Msk            (0x1ul << BPWM_MSK_MSKDAT4_Pos)                   /*!< BPWM_T::MSK: MSKDAT4 Mask             */

#define BPWM_MSK_MSKDAT5_Pos            (5)                                               /*!< BPWM_T::MSK: MSKDAT5 Position         */
#define BPWM_MSK_MSKDAT5_Msk            (0x1ul << BPWM_MSK_MSKDAT5_Pos)                   /*!< BPWM_T::MSK: MSKDAT5 Mask             */

#define BPWM_POLCTL_PINV0_Pos           (0)                                               /*!< BPWM_T::POLCTL: PINV0 Position        */
#define BPWM_POLCTL_PINV0_Msk           (0x1ul << BPWM_POLCTL_PINV0_Pos)                  /*!< BPWM_T::POLCTL: PINV0 Mask            */

#define BPWM_POLCTL_PINV1_Pos           (1)                                               /*!< BPWM_T::POLCTL: PINV1 Position        */
#define BPWM_POLCTL_PINV1_Msk           (0x1ul << BPWM_POLCTL_PINV1_Pos)                  /*!< BPWM_T::POLCTL: PINV1 Mask            */

#define BPWM_POLCTL_PINV2_Pos           (2)                                               /*!< BPWM_T::POLCTL: PINV2 Position        */
#define BPWM_POLCTL_PINV2_Msk           (0x1ul << BPWM_POLCTL_PINV2_Pos)                  /*!< BPWM_T::POLCTL: PINV2 Mask            */

#define BPWM_POLCTL_PINV3_Pos           (3)                                               /*!< BPWM_T::POLCTL: PINV3 Position        */
#define BPWM_POLCTL_PINV3_Msk           (0x1ul << BPWM_POLCTL_PINV3_Pos)                  /*!< BPWM_T::POLCTL: PINV3 Mask            */

#define BPWM_POLCTL_PINV4_Pos           (4)                                               /*!< BPWM_T::POLCTL: PINV4 Position        */
#define BPWM_POLCTL_PINV4_Msk           (0x1ul << BPWM_POLCTL_PINV4_Pos)                  /*!< BPWM_T::POLCTL: PINV4 Mask            */

#define BPWM_POLCTL_PINV5_Pos           (5)                                               /*!< BPWM_T::POLCTL: PINV5 Position        */
#define BPWM_POLCTL_PINV5_Msk           (0x1ul << BPWM_POLCTL_PINV5_Pos)                  /*!< BPWM_T::POLCTL: PINV5 Mask            */

#define BPWM_POEN_POEN0_Pos             (0)                                               /*!< BPWM_T::POEN: POEN0 Position          */
#define BPWM_POEN_POEN0_Msk             (0x1ul << BPWM_POEN_POEN0_Pos)                    /*!< BPWM_T::POEN: POEN0 Mask              */

#define BPWM_POEN_POEN1_Pos             (1)                                               /*!< BPWM_T::POEN: POEN1 Position          */
#define BPWM_POEN_POEN1_Msk             (0x1ul << BPWM_POEN_POEN1_Pos)                    /*!< BPWM_T::POEN: POEN1 Mask              */

#define BPWM_POEN_POEN2_Pos             (2)                                               /*!< BPWM_T::POEN: POEN2 Position          */
#define BPWM_POEN_POEN2_Msk             (0x1ul << BPWM_POEN_POEN2_Pos)                    /*!< BPWM_T::POEN: POEN2 Mask              */

#define BPWM_POEN_POEN3_Pos             (3)                                               /*!< BPWM_T::POEN: POEN3 Position          */
#define BPWM_POEN_POEN3_Msk             (0x1ul << BPWM_POEN_POEN3_Pos)                    /*!< BPWM_T::POEN: POEN3 Mask              */

#define BPWM_POEN_POEN4_Pos             (4)                                               /*!< BPWM_T::POEN: POEN4 Position          */
#define BPWM_POEN_POEN4_Msk             (0x1ul << BPWM_POEN_POEN4_Pos)                    /*!< BPWM_T::POEN: POEN4 Mask              */

#define BPWM_POEN_POEN5_Pos             (5)                                               /*!< BPWM_T::POEN: POEN5 Position          */
#define BPWM_POEN_POEN5_Msk             (0x1ul << BPWM_POEN_POEN5_Pos)                    /*!< BPWM_T::POEN: POEN5 Mask              */

#define BPWM_INTEN_ZIEN0_Pos            (0)                                               /*!< BPWM_T::INTEN: ZIEN0 Position         */
#define BPWM_INTEN_ZIEN0_Msk            (0x1ul << BPWM_INTEN_ZIEN0_Pos)                   /*!< BPWM_T::INTEN: ZIEN0 Mask             */

#define BPWM_INTEN_PIEN0_Pos            (8)                                               /*!< BPWM_T::INTEN: PIEN0 Position         */
#define BPWM_INTEN_PIEN0_Msk            (0x1ul << BPWM_INTEN_PIEN0_Pos)                   /*!< BPWM_T::INTEN: PIEN0 Mask             */

#define BPWM_INTEN_CMPUIEN0_Pos         (16)                                              /*!< BPWM_T::INTEN: CMPUIEN0 Position      */
#define BPWM_INTEN_CMPUIEN0_Msk         (0x1ul << BPWM_INTEN_CMPUIEN0_Pos)                /*!< BPWM_T::INTEN: CMPUIEN0 Mask          */

#define BPWM_INTEN_CMPUIEN1_Pos         (17)                                              /*!< BPWM_T::INTEN: CMPUIEN1 Position      */
#define BPWM_INTEN_CMPUIEN1_Msk         (0x1ul << BPWM_INTEN_CMPUIEN1_Pos)                /*!< BPWM_T::INTEN: CMPUIEN1 Mask          */

#define BPWM_INTEN_CMPUIEN2_Pos         (18)                                              /*!< BPWM_T::INTEN: CMPUIEN2 Position      */
#define BPWM_INTEN_CMPUIEN2_Msk         (0x1ul << BPWM_INTEN_CMPUIEN2_Pos)                /*!< BPWM_T::INTEN: CMPUIEN2 Mask          */

#define BPWM_INTEN_CMPUIEN3_Pos         (19)                                              /*!< BPWM_T::INTEN: CMPUIEN3 Position      */
#define BPWM_INTEN_CMPUIEN3_Msk         (0x1ul << BPWM_INTEN_CMPUIEN3_Pos)                /*!< BPWM_T::INTEN: CMPUIEN3 Mask          */

#define BPWM_INTEN_CMPUIEN4_Pos         (20)                                              /*!< BPWM_T::INTEN: CMPUIEN4 Position      */
#define BPWM_INTEN_CMPUIEN4_Msk         (0x1ul << BPWM_INTEN_CMPUIEN4_Pos)                /*!< BPWM_T::INTEN: CMPUIEN4 Mask          */

#define BPWM_INTEN_CMPUIEN5_Pos         (21)                                              /*!< BPWM_T::INTEN: CMPUIEN5 Position      */
#define BPWM_INTEN_CMPUIEN5_Msk         (0x1ul << BPWM_INTEN_CMPUIEN5_Pos)                /*!< BPWM_T::INTEN: CMPUIEN5 Mask          */

#define BPWM_INTEN_CMPDIEN0_Pos         (24)                                              /*!< BPWM_T::INTEN: CMPDIEN0 Position      */
#define BPWM_INTEN_CMPDIEN0_Msk         (0x1ul << BPWM_INTEN_CMPDIEN0_Pos)                /*!< BPWM_T::INTEN: CMPDIEN0 Mask          */

#define BPWM_INTEN_CMPDIEN1_Pos         (25)                                              /*!< BPWM_T::INTEN: CMPDIEN1 Position      */
#define BPWM_INTEN_CMPDIEN1_Msk         (0x1ul << BPWM_INTEN_CMPDIEN1_Pos)                /*!< BPWM_T::INTEN: CMPDIEN1 Mask          */

#define BPWM_INTEN_CMPDIEN2_Pos         (26)                                              /*!< BPWM_T::INTEN: CMPDIEN2 Position      */
#define BPWM_INTEN_CMPDIEN2_Msk         (0x1ul << BPWM_INTEN_CMPDIEN2_Pos)                /*!< BPWM_T::INTEN: CMPDIEN2 Mask          */

#define BPWM_INTEN_CMPDIEN3_Pos         (27)                                              /*!< BPWM_T::INTEN: CMPDIEN3 Position      */
#define BPWM_INTEN_CMPDIEN3_Msk         (0x1ul << BPWM_INTEN_CMPDIEN3_Pos)                /*!< BPWM_T::INTEN: CMPDIEN3 Mask          */

#define BPWM_INTEN_CMPDIEN4_Pos         (28)                                              /*!< BPWM_T::INTEN: CMPDIEN4 Position      */
#define BPWM_INTEN_CMPDIEN4_Msk         (0x1ul << BPWM_INTEN_CMPDIEN4_Pos)                /*!< BPWM_T::INTEN: CMPDIEN4 Mask          */

#define BPWM_INTEN_CMPDIEN5_Pos         (29)                                              /*!< BPWM_T::INTEN: CMPDIEN5 Position      */
#define BPWM_INTEN_CMPDIEN5_Msk         (0x1ul << BPWM_INTEN_CMPDIEN5_Pos)                /*!< BPWM_T::INTEN: CMPDIEN5 Mask          */

#define BPWM_INTSTS_ZIF0_Pos            (0)                                               /*!< BPWM_T::INTSTS: ZIF0 Position         */
#define BPWM_INTSTS_ZIF0_Msk            (0x1ul << BPWM_INTSTS_ZIF0_Pos)                   /*!< BPWM_T::INTSTS: ZIF0 Mask             */

#define BPWM_INTSTS_PIF0_Pos            (8)                                               /*!< BPWM_T::INTSTS: PIF0 Position         */
#define BPWM_INTSTS_PIF0_Msk            (0x1ul << BPWM_INTSTS_PIF0_Pos)                   /*!< BPWM_T::INTSTS: PIF0 Mask             */

#define BPWM_INTSTS_CMPUIF0_Pos         (16)                                              /*!< BPWM_T::INTSTS: CMPUIF0 Position      */
#define BPWM_INTSTS_CMPUIF0_Msk         (0x1ul << BPWM_INTSTS_CMPUIF0_Pos)                /*!< BPWM_T::INTSTS: CMPUIF0 Mask          */

#define BPWM_INTSTS_CMPUIF1_Pos         (17)                                              /*!< BPWM_T::INTSTS: CMPUIF1 Position      */
#define BPWM_INTSTS_CMPUIF1_Msk         (0x1ul << BPWM_INTSTS_CMPUIF1_Pos)                /*!< BPWM_T::INTSTS: CMPUIF1 Mask          */

#define BPWM_INTSTS_CMPUIF2_Pos         (18)                                              /*!< BPWM_T::INTSTS: CMPUIF2 Position      */
#define BPWM_INTSTS_CMPUIF2_Msk         (0x1ul << BPWM_INTSTS_CMPUIF2_Pos)                /*!< BPWM_T::INTSTS: CMPUIF2 Mask          */

#define BPWM_INTSTS_CMPUIF3_Pos         (19)                                              /*!< BPWM_T::INTSTS: CMPUIF3 Position      */
#define BPWM_INTSTS_CMPUIF3_Msk         (0x1ul << BPWM_INTSTS_CMPUIF3_Pos)                /*!< BPWM_T::INTSTS: CMPUIF3 Mask          */

#define BPWM_INTSTS_CMPUIF4_Pos         (20)                                              /*!< BPWM_T::INTSTS: CMPUIF4 Position      */
#define BPWM_INTSTS_CMPUIF4_Msk         (0x1ul << BPWM_INTSTS_CMPUIF4_Pos)                /*!< BPWM_T::INTSTS: CMPUIF4 Mask          */

#define BPWM_INTSTS_CMPUIF5_Pos         (21)                                              /*!< BPWM_T::INTSTS: CMPUIF5 Position      */
#define BPWM_INTSTS_CMPUIF5_Msk         (0x1ul << BPWM_INTSTS_CMPUIF5_Pos)                /*!< BPWM_T::INTSTS: CMPUIF5 Mask          */

#define BPWM_INTSTS_CMPDIF0_Pos         (24)                                              /*!< BPWM_T::INTSTS: CMPDIF0 Position      */
#define BPWM_INTSTS_CMPDIF0_Msk         (0x1ul << BPWM_INTSTS_CMPDIF0_Pos)                /*!< BPWM_T::INTSTS: CMPDIF0 Mask          */

#define BPWM_INTSTS_CMPDIF1_Pos         (25)                                              /*!< BPWM_T::INTSTS: CMPDIF1 Position      */
#define BPWM_INTSTS_CMPDIF1_Msk         (0x1ul << BPWM_INTSTS_CMPDIF1_Pos)                /*!< BPWM_T::INTSTS: CMPDIF1 Mask          */

#define BPWM_INTSTS_CMPDIF2_Pos         (26)                                              /*!< BPWM_T::INTSTS: CMPDIF2 Position      */
#define BPWM_INTSTS_CMPDIF2_Msk         (0x1ul << BPWM_INTSTS_CMPDIF2_Pos)                /*!< BPWM_T::INTSTS: CMPDIF2 Mask          */

#define BPWM_INTSTS_CMPDIF3_Pos         (27)                                              /*!< BPWM_T::INTSTS: CMPDIF3 Position      */
#define BPWM_INTSTS_CMPDIF3_Msk         (0x1ul << BPWM_INTSTS_CMPDIF3_Pos)                /*!< BPWM_T::INTSTS: CMPDIF3 Mask          */

#define BPWM_INTSTS_CMPDIF4_Pos         (28)                                              /*!< BPWM_T::INTSTS: CMPDIF4 Position      */
#define BPWM_INTSTS_CMPDIF4_Msk         (0x1ul << BPWM_INTSTS_CMPDIF4_Pos)                /*!< BPWM_T::INTSTS: CMPDIF4 Mask          */

#define BPWM_INTSTS_CMPDIF5_Pos         (29)                                              /*!< BPWM_T::INTSTS: CMPDIF5 Position      */
#define BPWM_INTSTS_CMPDIF5_Msk         (0x1ul << BPWM_INTSTS_CMPDIF5_Pos)                /*!< BPWM_T::INTSTS: CMPDIF5 Mask          */

#define BPWM_EADCTS0_TRGSEL0_Pos        (0)                                               /*!< BPWM_T::EADCTS0: TRGSEL0 Position     */
#define BPWM_EADCTS0_TRGSEL0_Msk        (0xful << BPWM_EADCTS0_TRGSEL0_Pos)               /*!< BPWM_T::EADCTS0: TRGSEL0 Mask         */

#define BPWM_EADCTS0_TRGEN0_Pos         (7)                                               /*!< BPWM_T::EADCTS0: TRGEN0 Position      */
#define BPWM_EADCTS0_TRGEN0_Msk         (0x1ul << BPWM_EADCTS0_TRGEN0_Pos)                /*!< BPWM_T::EADCTS0: TRGEN0 Mask          */

#define BPWM_EADCTS0_TRGSEL1_Pos        (8)                                               /*!< BPWM_T::EADCTS0: TRGSEL1 Position     */
#define BPWM_EADCTS0_TRGSEL1_Msk        (0xful << BPWM_EADCTS0_TRGSEL1_Pos)               /*!< BPWM_T::EADCTS0: TRGSEL1 Mask         */

#define BPWM_EADCTS0_TRGEN1_Pos         (15)                                              /*!< BPWM_T::EADCTS0: TRGEN1 Position      */
#define BPWM_EADCTS0_TRGEN1_Msk         (0x1ul << BPWM_EADCTS0_TRGEN1_Pos)                /*!< BPWM_T::EADCTS0: TRGEN1 Mask          */

#define BPWM_EADCTS0_TRGSEL2_Pos        (16)                                              /*!< BPWM_T::EADCTS0: TRGSEL2 Position     */
#define BPWM_EADCTS0_TRGSEL2_Msk        (0xful << BPWM_EADCTS0_TRGSEL2_Pos)               /*!< BPWM_T::EADCTS0: TRGSEL2 Mask         */

#define BPWM_EADCTS0_TRGEN2_Pos         (23)                                              /*!< BPWM_T::EADCTS0: TRGEN2 Position      */
#define BPWM_EADCTS0_TRGEN2_Msk         (0x1ul << BPWM_EADCTS0_TRGEN2_Pos)                /*!< BPWM_T::EADCTS0: TRGEN2 Mask          */

#define BPWM_EADCTS0_TRGSEL3_Pos        (24)                                              /*!< BPWM_T::EADCTS0: TRGSEL3 Position     */
#define BPWM_EADCTS0_TRGSEL3_Msk        (0xful << BPWM_EADCTS0_TRGSEL3_Pos)               /*!< BPWM_T::EADCTS0: TRGSEL3 Mask         */

#define BPWM_EADCTS0_TRGEN3_Pos         (31)                                              /*!< BPWM_T::EADCTS0: TRGEN3 Position      */
#define BPWM_EADCTS0_TRGEN3_Msk         (0x1ul << BPWM_EADCTS0_TRGEN3_Pos)                /*!< BPWM_T::EADCTS0: TRGEN3 Mask          */

#define BPWM_EADCTS1_TRGSEL4_Pos        (0)                                               /*!< BPWM_T::EADCTS1: TRGSEL4 Position     */
#define BPWM_EADCTS1_TRGSEL4_Msk        (0xful << BPWM_EADCTS1_TRGSEL4_Pos)               /*!< BPWM_T::EADCTS1: TRGSEL4 Mask         */

#define BPWM_EADCTS1_TRGEN4_Pos         (7)                                               /*!< BPWM_T::EADCTS1: TRGEN4 Position      */
#define BPWM_EADCTS1_TRGEN4_Msk         (0x1ul << BPWM_EADCTS1_TRGEN4_Pos)                /*!< BPWM_T::EADCTS1: TRGEN4 Mask          */

#define BPWM_EADCTS1_TRGSEL5_Pos        (8)                                               /*!< BPWM_T::EADCTS1: TRGSEL5 Position     */
#define BPWM_EADCTS1_TRGSEL5_Msk        (0xful << BPWM_EADCTS1_TRGSEL5_Pos)               /*!< BPWM_T::EADCTS1: TRGSEL5 Mask         */

#define BPWM_EADCTS1_TRGEN5_Pos         (15)                                              /*!< BPWM_T::EADCTS1: TRGEN5 Position      */
#define BPWM_EADCTS1_TRGEN5_Msk         (0x1ul << BPWM_EADCTS1_TRGEN5_Pos)                /*!< BPWM_T::EADCTS1: TRGEN5 Mask          */

#define BPWM_SSCTL_SSEN0_Pos            (0)                                               /*!< BPWM_T::SSCTL: SSEN0 Position         */
#define BPWM_SSCTL_SSEN0_Msk            (0x1ul << BPWM_SSCTL_SSEN0_Pos)                   /*!< BPWM_T::SSCTL: SSEN0 Mask             */

#define BPWM_SSCTL_SSRC_Pos             (8)                                               /*!< BPWM_T::SSCTL: SSRC Position          */
#define BPWM_SSCTL_SSRC_Msk             (0x3ul << BPWM_SSCTL_SSRC_Pos)                    /*!< BPWM_T::SSCTL: SSRC Mask              */

#define BPWM_SSTRG_CNTSEN_Pos           (0)                                               /*!< BPWM_T::SSTRG: CNTSEN Position        */
#define BPWM_SSTRG_CNTSEN_Msk           (0x1ul << BPWM_SSTRG_CNTSEN_Pos)                  /*!< BPWM_T::SSTRG: CNTSEN Mask            */

#define BPWM_STATUS_CNTMAX0_Pos         (0)                                               /*!< BPWM_T::STATUS: CNTMAX0 Position      */
#define BPWM_STATUS_CNTMAX0_Msk         (0x1ul << BPWM_STATUS_CNTMAX0_Pos)                /*!< BPWM_T::STATUS: CNTMAX0 Mask          */

#define BPWM_STATUS_EADCTRG0_Pos        (16)                                              /*!< BPWM_T::STATUS: EADCTRG0 Position     */
#define BPWM_STATUS_EADCTRG0_Msk        (0x1ul << BPWM_STATUS_EADCTRG0_Pos)               /*!< BPWM_T::STATUS: EADCTRG0 Mask         */

#define BPWM_STATUS_EADCTRG1_Pos        (17)                                              /*!< BPWM_T::STATUS: EADCTRG1 Position     */
#define BPWM_STATUS_EADCTRG1_Msk        (0x1ul << BPWM_STATUS_EADCTRG1_Pos)               /*!< BPWM_T::STATUS: EADCTRG1 Mask         */

#define BPWM_STATUS_EADCTRG2_Pos        (18)                                              /*!< BPWM_T::STATUS: EADCTRG2 Position     */
#define BPWM_STATUS_EADCTRG2_Msk        (0x1ul << BPWM_STATUS_EADCTRG2_Pos)               /*!< BPWM_T::STATUS: EADCTRG2 Mask         */

#define BPWM_STATUS_EADCTRG3_Pos        (19)                                              /*!< BPWM_T::STATUS: EADCTRG3 Position     */
#define BPWM_STATUS_EADCTRG3_Msk        (0x1ul << BPWM_STATUS_EADCTRG3_Pos)               /*!< BPWM_T::STATUS: EADCTRG3 Mask         */

#define BPWM_STATUS_EADCTRG4_Pos        (20)                                              /*!< BPWM_T::STATUS: EADCTRG4 Position     */
#define BPWM_STATUS_EADCTRG4_Msk        (0x1ul << BPWM_STATUS_EADCTRG4_Pos)               /*!< BPWM_T::STATUS: EADCTRG4 Mask         */

#define BPWM_STATUS_EADCTRG5_Pos        (21)                                              /*!< BPWM_T::STATUS: EADCTRG5 Position     */
#define BPWM_STATUS_EADCTRG5_Msk        (0x1ul << BPWM_STATUS_EADCTRG5_Pos)               /*!< BPWM_T::STATUS: EADCTRG5 Mask         */

#define BPWM_CAPINEN_CAPINEN0_Pos       (0)                                               /*!< BPWM_T::CAPINEN: CAPINEN0 Position    */
#define BPWM_CAPINEN_CAPINEN0_Msk       (0x1ul << BPWM_CAPINEN_CAPINEN0_Pos)              /*!< BPWM_T::CAPINEN: CAPINEN0 Mask        */

#define BPWM_CAPINEN_CAPINEN1_Pos       (1)                                               /*!< BPWM_T::CAPINEN: CAPINEN1 Position    */
#define BPWM_CAPINEN_CAPINEN1_Msk       (0x1ul << BPWM_CAPINEN_CAPINEN1_Pos)              /*!< BPWM_T::CAPINEN: CAPINEN1 Mask        */

#define BPWM_CAPINEN_CAPINEN2_Pos       (2)                                               /*!< BPWM_T::CAPINEN: CAPINEN2 Position    */
#define BPWM_CAPINEN_CAPINEN2_Msk       (0x1ul << BPWM_CAPINEN_CAPINEN2_Pos)              /*!< BPWM_T::CAPINEN: CAPINEN2 Mask        */

#define BPWM_CAPINEN_CAPINEN3_Pos       (3)                                               /*!< BPWM_T::CAPINEN: CAPINEN3 Position    */
#define BPWM_CAPINEN_CAPINEN3_Msk       (0x1ul << BPWM_CAPINEN_CAPINEN3_Pos)              /*!< BPWM_T::CAPINEN: CAPINEN3 Mask        */

#define BPWM_CAPINEN_CAPINEN4_Pos       (4)                                               /*!< BPWM_T::CAPINEN: CAPINEN4 Position    */
#define BPWM_CAPINEN_CAPINEN4_Msk       (0x1ul << BPWM_CAPINEN_CAPINEN4_Pos)              /*!< BPWM_T::CAPINEN: CAPINEN4 Mask        */

#define BPWM_CAPINEN_CAPINEN5_Pos       (5)                                               /*!< BPWM_T::CAPINEN: CAPINEN5 Position    */
#define BPWM_CAPINEN_CAPINEN5_Msk       (0x1ul << BPWM_CAPINEN_CAPINEN5_Pos)              /*!< BPWM_T::CAPINEN: CAPINEN5 Mask        */

#define BPWM_CAPCTL_CAPEN0_Pos          (0)                                               /*!< BPWM_T::CAPCTL: CAPEN0 Position       */
#define BPWM_CAPCTL_CAPEN0_Msk          (0x1ul << BPWM_CAPCTL_CAPEN0_Pos)                 /*!< BPWM_T::CAPCTL: CAPEN0 Mask           */

#define BPWM_CAPCTL_CAPEN1_Pos          (1)                                               /*!< BPWM_T::CAPCTL: CAPEN1 Position       */
#define BPWM_CAPCTL_CAPEN1_Msk          (0x1ul << BPWM_CAPCTL_CAPEN1_Pos)                 /*!< BPWM_T::CAPCTL: CAPEN1 Mask           */

#define BPWM_CAPCTL_CAPEN2_Pos          (2)                                               /*!< BPWM_T::CAPCTL: CAPEN2 Position       */
#define BPWM_CAPCTL_CAPEN2_Msk          (0x1ul << BPWM_CAPCTL_CAPEN2_Pos)                 /*!< BPWM_T::CAPCTL: CAPEN2 Mask           */

#define BPWM_CAPCTL_CAPEN3_Pos          (3)                                               /*!< BPWM_T::CAPCTL: CAPEN3 Position       */
#define BPWM_CAPCTL_CAPEN3_Msk          (0x1ul << BPWM_CAPCTL_CAPEN3_Pos)                 /*!< BPWM_T::CAPCTL: CAPEN3 Mask           */

#define BPWM_CAPCTL_CAPEN4_Pos          (4)                                               /*!< BPWM_T::CAPCTL: CAPEN4 Position       */
#define BPWM_CAPCTL_CAPEN4_Msk          (0x1ul << BPWM_CAPCTL_CAPEN4_Pos)                 /*!< BPWM_T::CAPCTL: CAPEN4 Mask           */

#define BPWM_CAPCTL_CAPEN5_Pos          (5)                                               /*!< BPWM_T::CAPCTL: CAPEN5 Position       */
#define BPWM_CAPCTL_CAPEN5_Msk          (0x1ul << BPWM_CAPCTL_CAPEN5_Pos)                 /*!< BPWM_T::CAPCTL: CAPEN5 Mask           */

#define BPWM_CAPCTL_CAPINV0_Pos         (8)                                               /*!< BPWM_T::CAPCTL: CAPINV0 Position      */
#define BPWM_CAPCTL_CAPINV0_Msk         (0x1ul << BPWM_CAPCTL_CAPINV0_Pos)                /*!< BPWM_T::CAPCTL: CAPINV0 Mask          */

#define BPWM_CAPCTL_CAPINV1_Pos         (9)                                               /*!< BPWM_T::CAPCTL: CAPINV1 Position      */
#define BPWM_CAPCTL_CAPINV1_Msk         (0x1ul << BPWM_CAPCTL_CAPINV1_Pos)                /*!< BPWM_T::CAPCTL: CAPINV1 Mask          */

#define BPWM_CAPCTL_CAPINV2_Pos         (10)                                              /*!< BPWM_T::CAPCTL: CAPINV2 Position      */
#define BPWM_CAPCTL_CAPINV2_Msk         (0x1ul << BPWM_CAPCTL_CAPINV2_Pos)                /*!< BPWM_T::CAPCTL: CAPINV2 Mask          */

#define BPWM_CAPCTL_CAPINV3_Pos         (11)                                              /*!< BPWM_T::CAPCTL: CAPINV3 Position      */
#define BPWM_CAPCTL_CAPINV3_Msk         (0x1ul << BPWM_CAPCTL_CAPINV3_Pos)                /*!< BPWM_T::CAPCTL: CAPINV3 Mask          */

#define BPWM_CAPCTL_CAPINV4_Pos         (12)                                              /*!< BPWM_T::CAPCTL: CAPINV4 Position      */
#define BPWM_CAPCTL_CAPINV4_Msk         (0x1ul << BPWM_CAPCTL_CAPINV4_Pos)                /*!< BPWM_T::CAPCTL: CAPINV4 Mask          */

#define BPWM_CAPCTL_CAPINV5_Pos         (13)                                              /*!< BPWM_T::CAPCTL: CAPINV5 Position      */
#define BPWM_CAPCTL_CAPINV5_Msk         (0x1ul << BPWM_CAPCTL_CAPINV5_Pos)                /*!< BPWM_T::CAPCTL: CAPINV5 Mask          */

#define BPWM_CAPCTL_RCRLDEN0_Pos        (16)                                              /*!< BPWM_T::CAPCTL: RCRLDEN0 Position     */
#define BPWM_CAPCTL_RCRLDEN0_Msk        (0x1ul << BPWM_CAPCTL_RCRLDEN0_Pos)               /*!< BPWM_T::CAPCTL: RCRLDEN0 Mask         */

#define BPWM_CAPCTL_RCRLDEN1_Pos        (17)                                              /*!< BPWM_T::CAPCTL: RCRLDEN1 Position     */
#define BPWM_CAPCTL_RCRLDEN1_Msk        (0x1ul << BPWM_CAPCTL_RCRLDEN1_Pos)               /*!< BPWM_T::CAPCTL: RCRLDEN1 Mask         */

#define BPWM_CAPCTL_RCRLDEN2_Pos        (18)                                              /*!< BPWM_T::CAPCTL: RCRLDEN2 Position     */
#define BPWM_CAPCTL_RCRLDEN2_Msk        (0x1ul << BPWM_CAPCTL_RCRLDEN2_Pos)               /*!< BPWM_T::CAPCTL: RCRLDEN2 Mask         */

#define BPWM_CAPCTL_RCRLDEN3_Pos        (19)                                              /*!< BPWM_T::CAPCTL: RCRLDEN3 Position     */
#define BPWM_CAPCTL_RCRLDEN3_Msk        (0x1ul << BPWM_CAPCTL_RCRLDEN3_Pos)               /*!< BPWM_T::CAPCTL: RCRLDEN3 Mask         */

#define BPWM_CAPCTL_RCRLDEN4_Pos        (20)                                              /*!< BPWM_T::CAPCTL: RCRLDEN4 Position     */
#define BPWM_CAPCTL_RCRLDEN4_Msk        (0x1ul << BPWM_CAPCTL_RCRLDEN4_Pos)               /*!< BPWM_T::CAPCTL: RCRLDEN4 Mask         */

#define BPWM_CAPCTL_RCRLDEN5_Pos        (21)                                              /*!< BPWM_T::CAPCTL: RCRLDEN5 Position     */
#define BPWM_CAPCTL_RCRLDEN5_Msk        (0x1ul << BPWM_CAPCTL_RCRLDEN5_Pos)               /*!< BPWM_T::CAPCTL: RCRLDEN5 Mask         */

#define BPWM_CAPCTL_FCRLDEN0_Pos        (24)                                              /*!< BPWM_T::CAPCTL: FCRLDEN0 Position     */
#define BPWM_CAPCTL_FCRLDEN0_Msk        (0x1ul << BPWM_CAPCTL_FCRLDEN0_Pos)               /*!< BPWM_T::CAPCTL: FCRLDEN0 Mask         */

#define BPWM_CAPCTL_FCRLDEN1_Pos        (25)                                              /*!< BPWM_T::CAPCTL: FCRLDEN1 Position     */
#define BPWM_CAPCTL_FCRLDEN1_Msk        (0x1ul << BPWM_CAPCTL_FCRLDEN1_Pos)               /*!< BPWM_T::CAPCTL: FCRLDEN1 Mask         */

#define BPWM_CAPCTL_FCRLDEN2_Pos        (26)                                              /*!< BPWM_T::CAPCTL: FCRLDEN2 Position     */
#define BPWM_CAPCTL_FCRLDEN2_Msk        (0x1ul << BPWM_CAPCTL_FCRLDEN2_Pos)               /*!< BPWM_T::CAPCTL: FCRLDEN2 Mask         */

#define BPWM_CAPCTL_FCRLDEN3_Pos        (27)                                              /*!< BPWM_T::CAPCTL: FCRLDEN3 Position     */
#define BPWM_CAPCTL_FCRLDEN3_Msk        (0x1ul << BPWM_CAPCTL_FCRLDEN3_Pos)               /*!< BPWM_T::CAPCTL: FCRLDEN3 Mask         */

#define BPWM_CAPCTL_FCRLDEN4_Pos        (28)                                              /*!< BPWM_T::CAPCTL: FCRLDEN4 Position     */
#define BPWM_CAPCTL_FCRLDEN4_Msk        (0x1ul << BPWM_CAPCTL_FCRLDEN4_Pos)               /*!< BPWM_T::CAPCTL: FCRLDEN4 Mask         */

#define BPWM_CAPCTL_FCRLDEN5_Pos        (29)                                              /*!< BPWM_T::CAPCTL: FCRLDEN5 Position     */
#define BPWM_CAPCTL_FCRLDEN5_Msk        (0x1ul << BPWM_CAPCTL_FCRLDEN5_Pos)               /*!< BPWM_T::CAPCTL: FCRLDEN5 Mask         */

#define BPWM_CAPSTS_CRIFOV0_Pos         (0)                                               /*!< BPWM_T::CAPSTS: CRIFOV0 Position      */
#define BPWM_CAPSTS_CRIFOV0_Msk         (0x1ul << BPWM_CAPSTS_CRIFOV0_Pos)                /*!< BPWM_T::CAPSTS: CRIFOV0 Mask          */

#define BPWM_CAPSTS_CRIFOV1_Pos         (1)                                               /*!< BPWM_T::CAPSTS: CRIFOV1 Position      */
#define BPWM_CAPSTS_CRIFOV1_Msk         (0x1ul << BPWM_CAPSTS_CRIFOV1_Pos)                /*!< BPWM_T::CAPSTS: CRIFOV1 Mask          */

#define BPWM_CAPSTS_CRIFOV2_Pos         (2)                                               /*!< BPWM_T::CAPSTS: CRIFOV2 Position      */
#define BPWM_CAPSTS_CRIFOV2_Msk         (0x1ul << BPWM_CAPSTS_CRIFOV2_Pos)                /*!< BPWM_T::CAPSTS: CRIFOV2 Mask          */

#define BPWM_CAPSTS_CRIFOV3_Pos         (3)                                               /*!< BPWM_T::CAPSTS: CRIFOV3 Position      */
#define BPWM_CAPSTS_CRIFOV3_Msk         (0x1ul << BPWM_CAPSTS_CRIFOV3_Pos)                /*!< BPWM_T::CAPSTS: CRIFOV3 Mask          */

#define BPWM_CAPSTS_CRIFOV4_Pos         (4)                                               /*!< BPWM_T::CAPSTS: CRIFOV4 Position      */
#define BPWM_CAPSTS_CRIFOV4_Msk         (0x1ul << BPWM_CAPSTS_CRIFOV4_Pos)                /*!< BPWM_T::CAPSTS: CRIFOV4 Mask          */

#define BPWM_CAPSTS_CRIFOV5_Pos         (5)                                               /*!< BPWM_T::CAPSTS: CRIFOV5 Position      */
#define BPWM_CAPSTS_CRIFOV5_Msk         (0x1ul << BPWM_CAPSTS_CRIFOV5_Pos)                /*!< BPWM_T::CAPSTS: CRIFOV5 Mask          */

#define BPWM_CAPSTS_CFIFOV0_Pos         (8)                                               /*!< BPWM_T::CAPSTS: CFIFOV0 Position      */
#define BPWM_CAPSTS_CFIFOV0_Msk         (0x1ul << BPWM_CAPSTS_CFIFOV0_Pos)                /*!< BPWM_T::CAPSTS: CFIFOV0 Mask          */

#define BPWM_CAPSTS_CFIFOV1_Pos         (9)                                               /*!< BPWM_T::CAPSTS: CFIFOV1 Position      */
#define BPWM_CAPSTS_CFIFOV1_Msk         (0x1ul << BPWM_CAPSTS_CFIFOV1_Pos)                /*!< BPWM_T::CAPSTS: CFIFOV1 Mask          */

#define BPWM_CAPSTS_CFIFOV2_Pos         (10)                                              /*!< BPWM_T::CAPSTS: CFIFOV2 Position      */
#define BPWM_CAPSTS_CFIFOV2_Msk         (0x1ul << BPWM_CAPSTS_CFIFOV2_Pos)                /*!< BPWM_T::CAPSTS: CFIFOV2 Mask          */

#define BPWM_CAPSTS_CFIFOV3_Pos         (11)                                              /*!< BPWM_T::CAPSTS: CFIFOV3 Position      */
#define BPWM_CAPSTS_CFIFOV3_Msk         (0x1ul << BPWM_CAPSTS_CFIFOV3_Pos)                /*!< BPWM_T::CAPSTS: CFIFOV3 Mask          */

#define BPWM_CAPSTS_CFIFOV4_Pos         (12)                                              /*!< BPWM_T::CAPSTS: CFIFOV4 Position      */
#define BPWM_CAPSTS_CFIFOV4_Msk         (0x1ul << BPWM_CAPSTS_CFIFOV4_Pos)                /*!< BPWM_T::CAPSTS: CFIFOV4 Mask          */

#define BPWM_CAPSTS_CFIFOV5_Pos         (13)                                              /*!< BPWM_T::CAPSTS: CFIFOV5 Position      */
#define BPWM_CAPSTS_CFIFOV5_Msk         (0x1ul << BPWM_CAPSTS_CFIFOV5_Pos)                /*!< BPWM_T::CAPSTS: CFIFOV5 Mask          */

#define BPWM_RCAPDAT_RCAPDAT_Pos        (0)                                               /*!< BPWM_T::RCAPDAT: RCAPDAT Position     */
#define BPWM_RCAPDAT_RCAPDAT_Msk        (0xfffful << BPWM_RCAPDAT_RCAPDAT_Pos)            /*!< BPWM_T::RCAPDAT: RCAPDAT Mask         */

#define BPWM_FCAPDAT_FCAPDAT_Pos        (0)                                               /*!< BPWM_T::FCAPDAT: FCAPDAT Position     */
#define BPWM_FCAPDAT_FCAPDAT_Msk        (0xfffful << BPWM_FCAPDAT_FCAPDAT_Pos)            /*!< BPWM_T::FCAPDAT: FCAPDAT Mask         */

#define BPWM_RCAPDAT0_RCAPDAT_Pos       (0)                                               /*!< BPWM_T::RCAPDAT0: RCAPDAT Position    */
#define BPWM_RCAPDAT0_RCAPDAT_Msk       (0xfffful << BPWM_RCAPDAT0_RCAPDAT_Pos)           /*!< BPWM_T::RCAPDAT0: RCAPDAT Mask        */

#define BPWM_FCAPDAT0_FCAPDAT_Pos       (0)                                               /*!< BPWM_T::FCAPDAT0: FCAPDAT Position    */
#define BPWM_FCAPDAT0_FCAPDAT_Msk       (0xfffful << BPWM_FCAPDAT0_FCAPDAT_Pos)           /*!< BPWM_T::FCAPDAT0: FCAPDAT Mask        */

#define BPWM_RCAPDAT1_RCAPDAT_Pos       (0)                                               /*!< BPWM_T::RCAPDAT1: RCAPDAT Position    */
#define BPWM_RCAPDAT1_RCAPDAT_Msk       (0xfffful << BPWM_RCAPDAT1_RCAPDAT_Pos)           /*!< BPWM_T::RCAPDAT1: RCAPDAT Mask        */

#define BPWM_FCAPDAT1_FCAPDAT_Pos       (0)                                               /*!< BPWM_T::FCAPDAT1: FCAPDAT Position    */
#define BPWM_FCAPDAT1_FCAPDAT_Msk       (0xfffful << BPWM_FCAPDAT1_FCAPDAT_Pos)           /*!< BPWM_T::FCAPDAT1: FCAPDAT Mask        */

#define BPWM_RCAPDAT2_RCAPDAT_Pos       (0)                                               /*!< BPWM_T::RCAPDAT2: RCAPDAT Position    */
#define BPWM_RCAPDAT2_RCAPDAT_Msk       (0xfffful << BPWM_RCAPDAT2_RCAPDAT_Pos)           /*!< BPWM_T::RCAPDAT2: RCAPDAT Mask        */

#define BPWM_FCAPDAT2_FCAPDAT_Pos       (0)                                               /*!< BPWM_T::FCAPDAT2: FCAPDAT Position    */
#define BPWM_FCAPDAT2_FCAPDAT_Msk       (0xfffful << BPWM_FCAPDAT2_FCAPDAT_Pos)           /*!< BPWM_T::FCAPDAT2: FCAPDAT Mask        */

#define BPWM_RCAPDAT3_RCAPDAT_Pos       (0)                                               /*!< BPWM_T::RCAPDAT3: RCAPDAT Position    */
#define BPWM_RCAPDAT3_RCAPDAT_Msk       (0xfffful << BPWM_RCAPDAT3_RCAPDAT_Pos)           /*!< BPWM_T::RCAPDAT3: RCAPDAT Mask        */

#define BPWM_FCAPDAT3_FCAPDAT_Pos       (0)                                               /*!< BPWM_T::FCAPDAT3: FCAPDAT Position    */
#define BPWM_FCAPDAT3_FCAPDAT_Msk       (0xfffful << BPWM_FCAPDAT3_FCAPDAT_Pos)           /*!< BPWM_T::FCAPDAT3: FCAPDAT Mask        */

#define BPWM_RCAPDAT4_RCAPDAT_Pos       (0)                                               /*!< BPWM_T::RCAPDAT4: RCAPDAT Position    */
#define BPWM_RCAPDAT4_RCAPDAT_Msk       (0xfffful << BPWM_RCAPDAT4_RCAPDAT_Pos)           /*!< BPWM_T::RCAPDAT4: RCAPDAT Mask        */

#define BPWM_FCAPDAT4_FCAPDAT_Pos       (0)                                               /*!< BPWM_T::FCAPDAT4: FCAPDAT Position    */
#define BPWM_FCAPDAT4_FCAPDAT_Msk       (0xfffful << BPWM_FCAPDAT4_FCAPDAT_Pos)           /*!< BPWM_T::FCAPDAT4: FCAPDAT Mask        */

#define BPWM_RCAPDAT5_RCAPDAT_Pos       (0)                                               /*!< BPWM_T::RCAPDAT5: RCAPDAT Position    */
#define BPWM_RCAPDAT5_RCAPDAT_Msk       (0xfffful << BPWM_RCAPDAT5_RCAPDAT_Pos)           /*!< BPWM_T::RCAPDAT5: RCAPDAT Mask        */

#define BPWM_FCAPDAT5_FCAPDAT_Pos       (0)                                               /*!< BPWM_T::FCAPDAT5: FCAPDAT Position    */
#define BPWM_FCAPDAT5_FCAPDAT_Msk       (0xfffful << BPWM_FCAPDAT5_FCAPDAT_Pos)           /*!< BPWM_T::FCAPDAT5: FCAPDAT Mask        */

#define BPWM_CAPIEN_CAPRIENn_Pos        (0)                                               /*!< BPWM_T::CAPIEN: CAPRIENn Position     */
#define BPWM_CAPIEN_CAPRIENn_Msk        (0x3ful << BPWM_CAPIEN_CAPRIENn_Pos)              /*!< BPWM_T::CAPIEN: CAPRIENn Mask         */

#define BPWM_CAPIEN_CAPFIENn_Pos        (8)                                               /*!< BPWM_T::CAPIEN: CAPFIENn Position     */
#define BPWM_CAPIEN_CAPFIENn_Msk        (0x3ful << BPWM_CAPIEN_CAPFIENn_Pos)              /*!< BPWM_T::CAPIEN: CAPFIENn Mask         */

#define BPWM_CAPIF_CAPRIF0_Pos          (0)                                               /*!< BPWM_T::CAPIF: CAPRIF0 Position       */
#define BPWM_CAPIF_CAPRIF0_Msk          (0x1ul << BPWM_CAPIF_CAPRIF0_Pos)                 /*!< BPWM_T::CAPIF: CAPRIF0 Mask           */

#define BPWM_CAPIF_CAPRIF1_Pos          (1)                                               /*!< BPWM_T::CAPIF: CAPRIF1 Position       */
#define BPWM_CAPIF_CAPRIF1_Msk          (0x1ul << BPWM_CAPIF_CAPRIF1_Pos)                 /*!< BPWM_T::CAPIF: CAPRIF1 Mask           */

#define BPWM_CAPIF_CAPRIF2_Pos          (2)                                               /*!< BPWM_T::CAPIF: CAPRIF2 Position       */
#define BPWM_CAPIF_CAPRIF2_Msk          (0x1ul << BPWM_CAPIF_CAPRIF2_Pos)                 /*!< BPWM_T::CAPIF: CAPRIF2 Mask           */

#define BPWM_CAPIF_CAPRIF3_Pos          (3)                                               /*!< BPWM_T::CAPIF: CAPRIF3 Position       */
#define BPWM_CAPIF_CAPRIF3_Msk          (0x1ul << BPWM_CAPIF_CAPRIF3_Pos)                 /*!< BPWM_T::CAPIF: CAPRIF3 Mask           */

#define BPWM_CAPIF_CAPRIF4_Pos          (4)                                               /*!< BPWM_T::CAPIF: CAPRIF4 Position       */
#define BPWM_CAPIF_CAPRIF4_Msk          (0x1ul << BPWM_CAPIF_CAPRIF4_Pos)                 /*!< BPWM_T::CAPIF: CAPRIF4 Mask           */

#define BPWM_CAPIF_CAPRIF5_Pos          (5)                                               /*!< BPWM_T::CAPIF: CAPRIF5 Position       */
#define BPWM_CAPIF_CAPRIF5_Msk          (0x1ul << BPWM_CAPIF_CAPRIF5_Pos)                 /*!< BPWM_T::CAPIF: CAPRIF5 Mask           */

#define BPWM_CAPIF_CAPFIF0_Pos          (8)                                               /*!< BPWM_T::CAPIF: CAPFIF0 Position       */
#define BPWM_CAPIF_CAPFIF0_Msk          (0x1ul << BPWM_CAPIF_CAPFIF0_Pos)                 /*!< BPWM_T::CAPIF: CAPFIF0 Mask           */

#define BPWM_CAPIF_CAPFIF1_Pos          (9)                                               /*!< BPWM_T::CAPIF: CAPFIF1 Position       */
#define BPWM_CAPIF_CAPFIF1_Msk          (0x1ul << BPWM_CAPIF_CAPFIF1_Pos)                 /*!< BPWM_T::CAPIF: CAPFIF1 Mask           */

#define BPWM_CAPIF_CAPFIF2_Pos          (10)                                              /*!< BPWM_T::CAPIF: CAPFIF2 Position       */
#define BPWM_CAPIF_CAPFIF2_Msk          (0x1ul << BPWM_CAPIF_CAPFIF2_Pos)                 /*!< BPWM_T::CAPIF: CAPFIF2 Mask           */

#define BPWM_CAPIF_CAPFIF3_Pos          (11)                                              /*!< BPWM_T::CAPIF: CAPFIF3 Position       */
#define BPWM_CAPIF_CAPFIF3_Msk          (0x1ul << BPWM_CAPIF_CAPFIF3_Pos)                 /*!< BPWM_T::CAPIF: CAPFIF3 Mask           */

#define BPWM_CAPIF_CAPFIF4_Pos          (12)                                              /*!< BPWM_T::CAPIF: CAPFIF4 Position       */
#define BPWM_CAPIF_CAPFIF4_Msk          (0x1ul << BPWM_CAPIF_CAPFIF4_Pos)                 /*!< BPWM_T::CAPIF: CAPFIF4 Mask           */

#define BPWM_CAPIF_CAPFIF5_Pos          (13)                                              /*!< BPWM_T::CAPIF: CAPFIF5 Position       */
#define BPWM_CAPIF_CAPFIF5_Msk          (0x1ul << BPWM_CAPIF_CAPFIF5_Pos)                 /*!< BPWM_T::CAPIF: CAPFIF5 Mask           */

#define BPWM_PBUF_PBUF_Pos              (0)                                               /*!< BPWM_T::PBUF: PBUF Position           */
#define BPWM_PBUF_PBUF_Msk              (0xfffful << BPWM_PBUF_PBUF_Pos)                  /*!< BPWM_T::PBUF: PBUF Mask               */

#define BPWM_CMPBUF_CMPBUF_Pos          (0)                                               /*!< BPWM_T::CMPBUF0: CMPBUF Position      */
#define BPWM_CMPBUF_CMPBUF_Msk          (0xfffful << BPWM_CMPBUFn_CMPBUF_Pos)             /*!< BPWM_T::CMPBUF0: CMPBUF Mask          */

#define BPWM_CMPBUF0_CMPBUF_Pos         (0)                                               /*!< BPWM_T::CMPBUF0: CMPBUF Position      */
#define BPWM_CMPBUF0_CMPBUF_Msk         (0xfffful << BPWM_CMPBUF0_CMPBUF_Pos)             /*!< BPWM_T::CMPBUF0: CMPBUF Mask          */

#define BPWM_CMPBUF1_CMPBUF_Pos         (0)                                               /*!< BPWM_T::CMPBUF1: CMPBUF Position      */
#define BPWM_CMPBUF1_CMPBUF_Msk         (0xfffful << BPWM_CMPBUF1_CMPBUF_Pos)             /*!< BPWM_T::CMPBUF1: CMPBUF Mask          */

#define BPWM_CMPBUF2_CMPBUF_Pos         (0)                                               /*!< BPWM_T::CMPBUF2: CMPBUF Position      */
#define BPWM_CMPBUF2_CMPBUF_Msk         (0xfffful << BPWM_CMPBUF2_CMPBUF_Pos)             /*!< BPWM_T::CMPBUF2: CMPBUF Mask          */

#define BPWM_CMPBUF3_CMPBUF_Pos         (0)                                               /*!< BPWM_T::CMPBUF3: CMPBUF Position      */
#define BPWM_CMPBUF3_CMPBUF_Msk         (0xfffful << BPWM_CMPBUF3_CMPBUF_Pos)             /*!< BPWM_T::CMPBUF3: CMPBUF Mask          */

#define BPWM_CMPBUF4_CMPBUF_Pos         (0)                                               /*!< BPWM_T::CMPBUF4: CMPBUF Position      */
#define BPWM_CMPBUF4_CMPBUF_Msk         (0xfffful << BPWM_CMPBUF4_CMPBUF_Pos)             /*!< BPWM_T::CMPBUF4: CMPBUF Mask          */

#define BPWM_CMPBUF5_CMPBUF_Pos         (0)                                               /*!< BPWM_T::CMPBUF5: CMPBUF Position      */
#define BPWM_CMPBUF5_CMPBUF_Msk         (0xfffful << BPWM_CMPBUF5_CMPBUF_Pos)             /*!< BPWM_T::CMPBUF5: CMPBUF Mask          */

/** @} BPWM_CONST */
/** @} end of BPWM register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __BPWM_REG_H__ */
