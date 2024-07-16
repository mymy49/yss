/**************************************************************************//**
 * @file     pdma_reg.h
 * @version  V1.00
 * @brief    PDMA register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __PDMA_REG_H__
#define __PDMA_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/**
    @addtogroup PDMA_CONST PDMA Bit Field Definition
    Constant Definitions for PDMA Controller
@{ */

#define PDMA_DSCT_CTL_OPMODE_Pos        (0)                                               /*!< PDMA_T::DSCT_CTL: OPMODE Position     */
#define PDMA_DSCT_CTL_OPMODE_Msk        (0x3ul << PDMA_DSCT_CTL_OPMODE_Pos)               /*!< PDMA_T::DSCT_CTL: OPMODE Mask         */

#define PDMA_DSCT_CTL_TXTYPE_Pos        (2)                                               /*!< PDMA_T::DSCT_CTL: TXTYPE Position     */
#define PDMA_DSCT_CTL_TXTYPE_Msk        (0x1ul << PDMA_DSCT_CTL_TXTYPE_Pos)               /*!< PDMA_T::DSCT_CTL: TXTYPE Mask         */

#define PDMA_DSCT_CTL_BURSIZE_Pos       (4)                                               /*!< PDMA_T::DSCT_CTL: BURSIZE Position    */
#define PDMA_DSCT_CTL_BURSIZE_Msk       (0x7ul << PDMA_DSCT_CTL_BURSIZE_Pos)              /*!< PDMA_T::DSCT_CTL: BURSIZE Mask        */

#define PDMA_DSCT_CTL_TBINTDIS_Pos      (7)                                               /*!< PDMA_T::DSCT_CTL: TBINTDIS Position      */
#define PDMA_DSCT_CTL_TBINTDIS_Msk      (0x1ul << PDMA_DSCT_CTL_TBINTDIS_Pos)             /*!< PDMA_T::DSCT_CTL: TBINTDIS Mask          */

#define PDMA_DSCT_CTL_SAINC_Pos         (8)                                               /*!< PDMA_T::DSCT_CTL: SAINC Position      */
#define PDMA_DSCT_CTL_SAINC_Msk         (0x3ul << PDMA_DSCT_CTL_SAINC_Pos)                /*!< PDMA_T::DSCT_CTL: SAINC Mask          */

#define PDMA_DSCT_CTL_DAINC_Pos         (10)                                              /*!< PDMA_T::DSCT_CTL: DAINC Position      */
#define PDMA_DSCT_CTL_DAINC_Msk         (0x3ul << PDMA_DSCT_CTL_DAINC_Pos)                /*!< PDMA_T::DSCT_CTL: DAINC Mask          */

#define PDMA_DSCT_CTL_TXWIDTH_Pos       (12)                                              /*!< PDMA_T::DSCT_CTL: TXWIDTH Position    */
#define PDMA_DSCT_CTL_TXWIDTH_Msk       (0x3ul << PDMA_DSCT_CTL_TXWIDTH_Pos)              /*!< PDMA_T::DSCT_CTL: TXWIDTH Mask        */

#define PDMA_DSCT_CTL_TXACK_Pos         (14)                                              /*!< PDMA_T::DSCT_CTL: TXACK Position      */
#define PDMA_DSCT_CTL_TXACK_Msk         (0x1ul << PDMA_DSCT_CTL_TXACK_Pos)                /*!< PDMA_T::DSCT_CTL: TXACK Mask          */

#define PDMA_DSCT_CTL_STRIDEEN_Pos     (15)                                               /*!< PDMA_T::DSCT_CTL: STRIDEEN Position  */
#define PDMA_DSCT_CTL_STRIDEEN_Msk     (0x1ul << PDMA_DSCT_CTL_STRIDEEN_Pos)              /*!< PDMA_T::DSCT_CTL: STRIDEEN Mask      */

#define PDMA_DSCT_CTL_TXCNT_Pos         (16)                                              /*!< PDMA_T::DSCT_CTL: TXCNT Position      */
#define PDMA_DSCT_CTL_TXCNT_Msk         (0xfffful << PDMA_DSCT_CTL_TXCNT_Pos)             /*!< PDMA_T::DSCT_CTL: TXCNT Mask          */

#define PDMA_DSCT_SA_SA_Pos             (0)                                               /*!< PDMA_T::DSCT_SA: SA Position          */
#define PDMA_DSCT_SA_SA_Msk             (0xfffffffful << PDMA_DSCT_SA_SA_Pos)             /*!< PDMA_T::DSCT_SA: SA Mask              */

#define PDMA_DSCT_DA_DA_Pos             (0)                                               /*!< PDMA_T::DSCT_DA: DA Position          */
#define PDMA_DSCT_DA_DA_Msk             (0xfffffffful << PDMA_DSCT_DA_DA_Pos)             /*!< PDMA_T::DSCT_DA: DA Mask              */

#define PDMA_DSCT_NEXT_NEXT_Pos         (0)                                               /*!< PDMA_T::DSCT_NEXT: NEXT Position      */
#define PDMA_DSCT_NEXT_NEXT_Msk         (0xfffful << PDMA_DSCT_NEXT_NEXT_Pos)             /*!< PDMA_T::DSCT_NEXT: NEXT Mask          */

#define PDMA_DSCT_NEXT_EXENEXT_Pos      (16)                                              /*!< PDMA_T::DSCT_FIRST: NEXT Position     */
#define PDMA_DSCT_NEXT_EXENEXT_Msk      (0xfffful << PDMA_DSCT_NEXT_EXENEXT_Pos)           /*!< PDMA_T::DSCT_FIRST: NEXT Mask         */

#define PDMA_CURSCAT_CURADDR_Pos        (0)                                               /*!< PDMA_T::CURSCAT: CURADDR Position     */
#define PDMA_CURSCAT_CURADDR_Msk        (0xfffffffful << PDMA_CURSCAT_CURADDR_Pos)        /*!< PDMA_T::CURSCAT: CURADDR Mask         */

#define PDMA_CHCTL_CHENn_Pos            (0)                                               /*!< PDMA_T::CHCTL: CHENn Position          */
#define PDMA_CHCTL_CHENn_Msk            (0xfffful << PDMA_CHCTL_CHENn_Pos)                /*!< PDMA_T::CHCTL: CHENn Mask              */

#define PDMA_PAUSE_PAUSEn_Pos           (0)                                               /*!< PDMA_T::PAUSE: PAUSEn Position           */
#define PDMA_PAUSE_PAUSEn_Msk           (0xfffful << PDMA_PAUSE_PAUSEn_Pos)              /*!< PDMA_T::PAUSE: PAUSEn Mask               */

#define PDMA_SWREQ_SWREQn_Pos            (0)                                               /*!< PDMA_T::SWREQ: SWREQn Position         */
#define PDMA_SWREQ_SWREQn_Msk            (0xfffful << PDMA_SWREQ_SWREQn_Pos)               /*!< PDMA_T::SWREQ: SWREQn Mask             */

#define PDMA_TRGSTS_REQSTSn_Pos          (0)                                               /*!< PDMA_T::TRGSTS: REQSTSn Position       */
#define PDMA_TRGSTS_REQSTSn_Msk          (0xfffful << PDMA_TRGSTS_REQSTSn_Pos)             /*!< PDMA_T::TRGSTS: REQSTSn Mask           */

#define PDMA_PRISET_FPRISETn_Pos         (0)                                               /*!< PDMA_T::PRISET: FPRISETn Position      */
#define PDMA_PRISET_FPRISETn_Msk         (0xfffful << PDMA_PRISET_FPRISETn_Pos)            /*!< PDMA_T::PRISET: FPRISETn Mask          */

#define PDMA_PRICLR_FPRICLRn_Pos         (0)                                               /*!< PDMA_T::PRICLR: FPRICLRn Position      */
#define PDMA_PRICLR_FPRICLRn_Msk         (0xfffful << PDMA_PRICLR_FPRICLRn_Pos)            /*!< PDMA_T::PRICLR: FPRICLRn Mask          */

#define PDMA_INTEN_INTENn_Pos            (0)                                               /*!< PDMA_T::INTEN: INTENn Position         */
#define PDMA_INTEN_INTENn_Msk            (0xfffful << PDMA_INTEN_INTENn_Pos)               /*!< PDMA_T::INTEN: INTENn Mask             */

#define PDMA_INTSTS_ABTIF_Pos            (0)                                               /*!< PDMA_T::INTSTS: ABTIF Position         */
#define PDMA_INTSTS_ABTIF_Msk            (0x1ul << PDMA_INTSTS_ABTIF_Pos)                  /*!< PDMA_T::INTSTS: ABTIF Mask             */

#define PDMA_INTSTS_TDIF_Pos             (1)                                               /*!< PDMA_T::INTSTS: TDIF Position          */
#define PDMA_INTSTS_TDIF_Msk             (0x1ul << PDMA_INTSTS_TDIF_Pos)                   /*!< PDMA_T::INTSTS: TDIF Mask              */

#define PDMA_INTSTS_ALIGNF_Pos           (2)                                               /*!< PDMA_T::INTSTS: ALIGNF Position        */
#define PDMA_INTSTS_ALIGNF_Msk           (0x1ul << PDMA_INTSTS_ALIGNF_Pos)                 /*!< PDMA_T::INTSTS: ALIGNF Mask            */

#define PDMA_INTSTS_REQTOF0_Pos          (8)                                               /*!< PDMA_T::INTSTS: REQTOF0 Position       */
#define PDMA_INTSTS_REQTOF0_Msk          (0x1ul << PDMA_INTSTS_REQTOF0_Pos)                /*!< PDMA_T::INTSTS: REQTOF0 Mask           */

#define PDMA_INTSTS_REQTOF1_Pos          (9)                                               /*!< PDMA_T::INTSTS: REQTOF1 Position       */
#define PDMA_INTSTS_REQTOF1_Msk          (0x1ul << PDMA_INTSTS_REQTOF1_Pos)                /*!< PDMA_T::INTSTS: REQTOF1 Mask           */

#define PDMA_ABTSTS_ABTIF0_Pos           (0)                                               /*!< PDMA_T::ABTSTS: ABTIF0 Position        */
#define PDMA_ABTSTS_ABTIF0_Msk           (0x1ul << PDMA_ABTSTS_ABTIF0_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF0 Mask            */

#define PDMA_ABTSTS_ABTIF1_Pos           (1)                                               /*!< PDMA_T::ABTSTS: ABTIF1 Position        */
#define PDMA_ABTSTS_ABTIF1_Msk           (0x1ul << PDMA_ABTSTS_ABTIF1_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF1 Mask            */

#define PDMA_ABTSTS_ABTIF2_Pos           (2)                                               /*!< PDMA_T::ABTSTS: ABTIF2 Position        */
#define PDMA_ABTSTS_ABTIF2_Msk           (0x1ul << PDMA_ABTSTS_ABTIF2_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF2 Mask            */

#define PDMA_ABTSTS_ABTIF3_Pos           (3)                                               /*!< PDMA_T::ABTSTS: ABTIF3 Position        */
#define PDMA_ABTSTS_ABTIF3_Msk           (0x1ul << PDMA_ABTSTS_ABTIF3_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF3 Mask            */

#define PDMA_ABTSTS_ABTIF4_Pos           (4)                                               /*!< PDMA_T::ABTSTS: ABTIF4 Position        */
#define PDMA_ABTSTS_ABTIF4_Msk           (0x1ul << PDMA_ABTSTS_ABTIF4_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF4 Mask            */

#define PDMA_ABTSTS_ABTIF5_Pos           (5)                                               /*!< PDMA_T::ABTSTS: ABTIF5 Position        */
#define PDMA_ABTSTS_ABTIF5_Msk           (0x1ul << PDMA_ABTSTS_ABTIF5_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF5 Mask            */

#define PDMA_ABTSTS_ABTIF6_Pos           (6)                                               /*!< PDMA_T::ABTSTS: ABTIF6 Position        */
#define PDMA_ABTSTS_ABTIF6_Msk           (0x1ul << PDMA_ABTSTS_ABTIF6_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF6 Mask            */

#define PDMA_ABTSTS_ABTIF7_Pos           (7)                                               /*!< PDMA_T::ABTSTS: ABTIF7 Position        */
#define PDMA_ABTSTS_ABTIF7_Msk           (0x1ul << PDMA_ABTSTS_ABTIF7_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF7 Mask            */

#define PDMA_ABTSTS_ABTIF8_Pos           (8)                                               /*!< PDMA_T::ABTSTS: ABTIF8 Position        */
#define PDMA_ABTSTS_ABTIF8_Msk           (0x1ul << PDMA_ABTSTS_ABTIF8_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF8 Mask            */

#define PDMA_ABTSTS_ABTIF9_Pos           (9)                                               /*!< PDMA_T::ABTSTS: ABTIF9 Position        */
#define PDMA_ABTSTS_ABTIF9_Msk           (0x1ul << PDMA_ABTSTS_ABTIF9_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF9 Mask            */

#define PDMA_ABTSTS_ABTIF10_Pos           (10)                                               /*!< PDMA_T::ABTSTS: ABTIF10 Position        */
#define PDMA_ABTSTS_ABTIF10_Msk           (0x1ul << PDMA_ABTSTS_ABTIF10_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF10 Mask            */

#define PDMA_ABTSTS_ABTIF11_Pos           (11)                                               /*!< PDMA_T::ABTSTS: ABTIF11 Position        */
#define PDMA_ABTSTS_ABTIF11_Msk           (0x1ul << PDMA_ABTSTS_ABTIF11_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF11 Mask            */

#define PDMA_ABTSTS_ABTIF12_Pos           (12)                                               /*!< PDMA_T::ABTSTS: ABTIF12 Position        */
#define PDMA_ABTSTS_ABTIF12_Msk           (0x1ul << PDMA_ABTSTS_ABTIF12_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF12 Mask            */

#define PDMA_ABTSTS_ABTIF13_Pos           (13)                                               /*!< PDMA_T::ABTSTS: ABTIF13 Position        */
#define PDMA_ABTSTS_ABTIF13_Msk           (0x1ul << PDMA_ABTSTS_ABTIF13_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF13 Mask            */

#define PDMA_ABTSTS_ABTIF14_Pos           (14)                                               /*!< PDMA_T::ABTSTS: ABTIF14 Position        */
#define PDMA_ABTSTS_ABTIF14_Msk           (0x1ul << PDMA_ABTSTS_ABTIF14_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF14 Mask            */

#define PDMA_ABTSTS_ABTIF15_Pos           (15)                                               /*!< PDMA_T::ABTSTS: ABTIF15 Position        */
#define PDMA_ABTSTS_ABTIF15_Msk           (0x1ul << PDMA_ABTSTS_ABTIF15_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF15 Mask            */

#define PDMA_TDSTS_TDIF0_Pos           (0)                                               /*!< PDMA_T::TDSTS: TDIF0 Position        */
#define PDMA_TDSTS_TDIF0_Msk           (0x1ul << PDMA_TDSTS_TDIF0_Pos)                   /*!< PDMA_T::TDSTS: TDIF0 Mask            */

#define PDMA_TDSTS_TDIF1_Pos           (1)                                               /*!< PDMA_T::TDSTS: TDIF1 Position        */
#define PDMA_TDSTS_TDIF1_Msk           (0x1ul << PDMA_TDSTS_TDIF1_Pos)                   /*!< PDMA_T::TDSTS: TDIF1 Mask            */

#define PDMA_TDSTS_TDIF2_Pos           (2)                                               /*!< PDMA_T::TDSTS: TDIF2 Position        */
#define PDMA_TDSTS_TDIF2_Msk           (0x1ul << PDMA_TDSTS_TDIF2_Pos)                   /*!< PDMA_T::TDSTS: TDIF2 Mask            */

#define PDMA_TDSTS_TDIF3_Pos           (3)                                               /*!< PDMA_T::TDSTS: TDIF3 Position        */
#define PDMA_TDSTS_TDIF3_Msk           (0x1ul << PDMA_TDSTS_TDIF3_Pos)                   /*!< PDMA_T::TDSTS: TDIF3 Mask            */

#define PDMA_TDSTS_TDIF4_Pos           (4)                                               /*!< PDMA_T::TDSTS: TDIF4 Position        */
#define PDMA_TDSTS_TDIF4_Msk           (0x1ul << PDMA_TDSTS_TDIF4_Pos)                   /*!< PDMA_T::TDSTS: TDIF4 Mask            */

#define PDMA_TDSTS_TDIF5_Pos           (5)                                               /*!< PDMA_T::TDSTS: TDIF5 Position        */
#define PDMA_TDSTS_TDIF5_Msk           (0x1ul << PDMA_TDSTS_TDIF5_Pos)                   /*!< PDMA_T::TDSTS: TDIF5 Mask            */

#define PDMA_TDSTS_TDIF6_Pos           (6)                                               /*!< PDMA_T::TDSTS: TDIF6 Position        */
#define PDMA_TDSTS_TDIF6_Msk           (0x1ul << PDMA_TDSTS_TDIF6_Pos)                   /*!< PDMA_T::TDSTS: TDIF6 Mask            */

#define PDMA_TDSTS_TDIF7_Pos           (7)                                               /*!< PDMA_T::TDSTS: TDIF7 Position        */
#define PDMA_TDSTS_TDIF7_Msk           (0x1ul << PDMA_TDSTS_TDIF7_Pos)                   /*!< PDMA_T::TDSTS: TDIF7 Mask            */

#define PDMA_TDSTS_TDIF8_Pos           (8)                                               /*!< PDMA_T::TDSTS: TDIF8 Position        */
#define PDMA_TDSTS_TDIF8_Msk           (0x1ul << PDMA_TDSTS_TDIF8_Pos)                   /*!< PDMA_T::TDSTS: TDIF8 Mask            */

#define PDMA_TDSTS_TDIF9_Pos           (9)                                               /*!< PDMA_T::TDSTS: TDIF9 Position        */
#define PDMA_TDSTS_TDIF9_Msk           (0x1ul << PDMA_TDSTS_TDIF9_Pos)                   /*!< PDMA_T::TDSTS: TDIF9 Mask            */

#define PDMA_TDSTS_TDIF10_Pos           (10)                                               /*!< PDMA_T::TDSTS: TDIF10 Position        */
#define PDMA_TDSTS_TDIF10_Msk           (0x1ul << PDMA_TDSTS_TDIF10_Pos)                   /*!< PDMA_T::TDSTS: TDIF10 Mask            */

#define PDMA_TDSTS_TDIF11_Pos           (11)                                               /*!< PDMA_T::TDSTS: TDIF11 Position        */
#define PDMA_TDSTS_TDIF11_Msk           (0x1ul << PDMA_TDSTS_TDIF11_Pos)                   /*!< PDMA_T::TDSTS: TDIF11 Mask            */

#define PDMA_TDSTS_TDIF12_Pos           (12)                                               /*!< PDMA_T::TDSTS: TDIF12 Position        */
#define PDMA_TDSTS_TDIF12_Msk           (0x1ul << PDMA_TDSTS_TDIF12_Pos)                   /*!< PDMA_T::TDSTS: TDIF12 Mask            */

#define PDMA_TDSTS_TDIF13_Pos           (13)                                               /*!< PDMA_T::TDSTS: TDIF13 Position        */
#define PDMA_TDSTS_TDIF13_Msk           (0x1ul << PDMA_TDSTS_TDIF13_Pos)                   /*!< PDMA_T::TDSTS: TDIF13 Mask            */

#define PDMA_TDSTS_TDIF14_Pos           (14)                                               /*!< PDMA_T::TDSTS: TDIF14 Position        */
#define PDMA_TDSTS_TDIF14_Msk           (0x1ul << PDMA_TDSTS_TDIF14_Pos)                   /*!< PDMA_T::TDSTS: TDIF14 Mask            */

#define PDMA_TDSTS_TDIF15_Pos           (15)                                               /*!< PDMA_T::TDSTS: TDIF15 Position        */
#define PDMA_TDSTS_TDIF15_Msk           (0x1ul << PDMA_TDSTS_TDIF15_Pos)                   /*!< PDMA_T::TDSTS: TDIF15 Mask            */

#define PDMA_ALIGN_ALIGNn_Pos           (0)                                                /*!< PDMA_T::ALIGN: ALIGNn Position        */
#define PDMA_ALIGN_ALIGNn_Msk           (0xfffful << PDMA_ALIGN_ALIGNn_Pos)                /*!< PDMA_T::ALIGN: ALIGNn Mask            */

#define PDMA_TACTSTS_TXACTFn_Pos         (0)                                               /*!< PDMA_T::TACTSTS: TXACTFn Position      */
#define PDMA_TACTSTS_TXACTFn_Msk         (0xfffful << PDMA_TACTSTS_TXACTFn_Pos)            /*!< PDMA_T::TACTSTS: TXACTFn Mask          */

#define PDMA_TOUTPSC_TOUTPSC0_Pos        (0)                                               /*!< PDMA_T::TOUTPSC: TOUTPSC0 Position     */
#define PDMA_TOUTPSC_TOUTPSC0_Msk        (0x7ul << PDMA_TOUTPSC_TOUTPSC0_Pos)              /*!< PDMA_T::TOUTPSC: TOUTPSC0 Mask         */

#define PDMA_TOUTPSC_TOUTPSC1_Pos        (4)                                               /*!< PDMA_T::TOUTPSC: TOUTPSC1 Position     */
#define PDMA_TOUTPSC_TOUTPSC1_Msk        (0x7ul << PDMA_TOUTPSC_TOUTPSC1_Pos)              /*!< PDMA_T::TOUTPSC: TOUTPSC1 Mask         */

#define PDMA_TOUTEN_TOUTENn_Pos          (0)                                               /*!< PDMA_T::TOUTEN: TOUTENn Position       */
#define PDMA_TOUTEN_TOUTENn_Msk          (0x3ul << PDMA_TOUTEN_TOUTENn_Pos)                /*!< PDMA_T::TOUTEN: TOUTENn Mask           */

#define PDMA_TOUTIEN_TOUTIENn_Pos        (0)                                               /*!< PDMA_T::TOUTIEN: TOUTIENn Position     */
#define PDMA_TOUTIEN_TOUTIENn_Msk        (0x3ul << PDMA_TOUTIEN_TOUTIENn_Pos)              /*!< PDMA_T::TOUTIEN: TOUTIENn Mask         */

#define PDMA_SCATBA_SCATBA_Pos           (16)                                              /*!< PDMA_T::SCATBA: SCATBA Position        */
#define PDMA_SCATBA_SCATBA_Msk           (0xfffful << PDMA_SCATBA_SCATBA_Pos)              /*!< PDMA_T::SCATBA: SCATBA Mask            */

#define PDMA_TOC0_1_TOC0_Pos             (0)                                               /*!< PDMA_T::TOC0_1: TOC0 Position          */
#define PDMA_TOC0_1_TOC0_Msk             (0xfffful << PDMA_TOC0_1_TOC0_Pos)                /*!< PDMA_T::TOC0_1: TOC0 Mask              */

#define PDMA_TOC0_1_TOC1_Pos             (16)                                              /*!< PDMA_T::TOC0_1: TOC1 Position          */
#define PDMA_TOC0_1_TOC1_Msk             (0xfffful << PDMA_TOC0_1_TOC1_Pos)                /*!< PDMA_T::TOC0_1: TOC1 Mask              */

#define PDMA_CHRST_CHnRST_Pos            (0)                                               /*!< PDMA_T::CHRST: CHnRST Position         */
#define PDMA_CHRST_CHnRST_Msk            (0xfffful << PDMA_CHRST_CHnRST_Pos)               /*!< PDMA_T::CHRST: CHnRST Mask             */

#define PDMA_REQSEL0_3_REQSRC0_Pos       (0)                                               /*!< PDMA_T::REQSEL0_3: REQSRC0 Position    */
#define PDMA_REQSEL0_3_REQSRC0_Msk       (0x7ful << PDMA_REQSEL0_3_REQSRC0_Pos)            /*!< PDMA_T::REQSEL0_3: REQSRC0 Mask        */

#define PDMA_REQSEL0_3_REQSRC1_Pos       (8)                                               /*!< PDMA_T::REQSEL0_3: REQSRC1 Position    */
#define PDMA_REQSEL0_3_REQSRC1_Msk       (0x7ful << PDMA_REQSEL0_3_REQSRC1_Pos)            /*!< PDMA_T::REQSEL0_3: REQSRC1 Mask        */

#define PDMA_REQSEL0_3_REQSRC2_Pos       (16)                                              /*!< PDMA_T::REQSEL0_3: REQSRC2 Position    */
#define PDMA_REQSEL0_3_REQSRC2_Msk       (0x7ful << PDMA_REQSEL0_3_REQSRC2_Pos)            /*!< PDMA_T::REQSEL0_3: REQSRC2 Mask        */

#define PDMA_REQSEL0_3_REQSRC3_Pos       (24)                                              /*!< PDMA_T::REQSEL0_3: REQSRC3 Position    */
#define PDMA_REQSEL0_3_REQSRC3_Msk       (0x7ful << PDMA_REQSEL0_3_REQSRC3_Pos)            /*!< PDMA_T::REQSEL0_3: REQSRC3 Mask        */

#define PDMA_REQSEL4_7_REQSRC4_Pos       (0)                                               /*!< PDMA_T::REQSEL4_7: REQSRC4 Position    */
#define PDMA_REQSEL4_7_REQSRC4_Msk       (0x7ful << PDMA_REQSEL4_7_REQSRC4_Pos)            /*!< PDMA_T::REQSEL4_7: REQSRC4 Mask        */

#define PDMA_REQSEL4_7_REQSRC5_Pos       (8)                                               /*!< PDMA_T::REQSEL4_7: REQSRC5 Position    */
#define PDMA_REQSEL4_7_REQSRC5_Msk       (0x7ful << PDMA_REQSEL4_7_REQSRC5_Pos)            /*!< PDMA_T::REQSEL4_7: REQSRC5 Mask        */

#define PDMA_REQSEL4_7_REQSRC6_Pos       (16)                                              /*!< PDMA_T::REQSEL4_7: REQSRC6 Position    */
#define PDMA_REQSEL4_7_REQSRC6_Msk       (0x7ful << PDMA_REQSEL4_7_REQSRC6_Pos)            /*!< PDMA_T::REQSEL4_7: REQSRC6 Mask        */

#define PDMA_REQSEL4_7_REQSRC7_Pos       (24)                                              /*!< PDMA_T::REQSEL4_7: REQSRC7 Position    */
#define PDMA_REQSEL4_7_REQSRC7_Msk       (0x7ful << PDMA_REQSEL4_7_REQSRC7_Pos)            /*!< PDMA_T::REQSEL4_7: REQSRC7 Mask        */

#define PDMA_REQSEL8_11_REQSRC8_Pos      (0)                                               /*!< PDMA_T::REQSEL8_11: REQSRC8 Position   */
#define PDMA_REQSEL8_11_REQSRC8_Msk      (0x7ful << PDMA_REQSEL8_11_REQSRC8_Pos)           /*!< PDMA_T::REQSEL8_11: REQSRC8 Mask       */

#define PDMA_REQSEL8_11_REQSRC9_Pos      (8)                                               /*!< PDMA_T::REQSEL8_11: REQSRC9 Position   */
#define PDMA_REQSEL8_11_REQSRC9_Msk      (0x7ful << PDMA_REQSEL8_11_REQSRC9_Pos)           /*!< PDMA_T::REQSEL8_11: REQSRC9 Mask       */

#define PDMA_REQSEL8_11_REQSRC10_Pos     (16)                                              /*!< PDMA_T::REQSEL8_11: REQSRC10 Position  */
#define PDMA_REQSEL8_11_REQSRC10_Msk     (0x7ful << PDMA_REQSEL8_11_REQSRC10_Pos)          /*!< PDMA_T::REQSEL8_11: REQSRC10 Mask      */

#define PDMA_REQSEL8_11_REQSRC11_Pos     (24)                                              /*!< PDMA_T::REQSEL8_11: REQSRC11 Position  */
#define PDMA_REQSEL8_11_REQSRC11_Msk     (0x7ful << PDMA_REQSEL8_11_REQSRC11_Pos)          /*!< PDMA_T::REQSEL8_11: REQSRC11 Mask      */

#define PDMA_REQSEL12_15_REQSRC12_Pos    (0)                                               /*!< PDMA_T::REQSEL12_15: REQSRC12 Position */
#define PDMA_REQSEL12_15_REQSRC12_Msk    (0x7ful << PDMA_REQSEL12_15_REQSRC12_Pos)         /*!< PDMA_T::REQSEL12_15: REQSRC12 Mask     */

#define PDMA_REQSEL12_15_REQSRC13_Pos    (8)                                               /*!< PDMA_T::REQSEL12_15: REQSRC13 Position */
#define PDMA_REQSEL12_15_REQSRC13_Msk    (0x7ful << PDMA_REQSEL12_15_REQSRC13_Pos)         /*!< PDMA_T::REQSEL12_15: REQSRC13 Mask     */

#define PDMA_REQSEL12_15_REQSRC14_Pos    (16)                                              /*!< PDMA_T::REQSEL12_15: REQSRC14 Position */
#define PDMA_REQSEL12_15_REQSRC14_Msk    (0x7ful << PDMA_REQSEL12_15_REQSRC14_Pos)         /*!< PDMA_T::REQSEL12_15: REQSRC14 Mask     */

#define PDMA_REQSEL12_15_REQSRC15_Pos    (24)                                              /*!< PDMA_T::REQSEL12_15: REQSRC15 Position */
#define PDMA_REQSEL12_15_REQSRC15_Msk    (0x7ful << PDMA_REQSEL12_15_REQSRC15_Pos)         /*!< PDMA_T::REQSEL12_15: REQSRC15 Mask     */

#define PDMA_STCRn_STC_Pos               (0)                                               /*!< PDMA_T::STCRn: STC Position            */
#define PDMA_STCRn_STC_Msk               (0xfffful << PDMA_STCRn_STC_Pos)                  /*!< PDMA_T::STCRn: STC Mask                */

#define PDMA_ASOCRn_SASOL_Pos            (0)                                               /*!< PDMA_T::ASOCRn: SASOL Position         */
#define PDMA_ASOCRn_SASOL_Msk            (0xfffful << PDMA_ASOCRn_SASOL_Pos)               /*!< PDMA_T::ASOCRn: SASOL Mask             */

#define PDMA_ASOCRn_DASOL_Pos            (16)                                              /*!< PDMA_T::ASOCRn: DASOL Position         */
#define PDMA_ASOCRn_DASOL_Msk            (0xfffful << PDMA_ASOCRn_DASOL_Pos)               /*!< PDMA_T::ASOCRn: DASOL Mask             */

#define PDMA_RCNTn_RCNT_Pos              (0)                                               /*!< PDMA_T::RCNTn: RCNT Position            */
#define PDMA_RCNTn_RCNT_Msk              (0xfffful << PDMA_STCRn_RCNT_Pos)                 /*!< PDMA_T::RCNTn: RCNT Mask                */

#define PDMA_AICTLn_SAICNT_Pos           (0)                                               /*!< PDMA_T::AICTLn: SAICNT Position         */
#define PDMA_AICTLn_SAICNT_Msk           (0xfffful << PDMA_ASOCRn_SASOL_Pos)               /*!< PDMA_T::AICTLn: SAICNT Mask             */

#define PDMA_AICTLn_DAICNT_Pos           (16)                                              /*!< PDMA_T::AICTLn: DAICNT Position         */
#define PDMA_AICTLn_DAICNT_Msk           (0xfffful << PDMA_ASOCRn_DASOL_Pos)               /*!< PDMA_T::AICTLn: DAICNT Mask             */

/**@}*/ /* PDMA_CONST */
/**@}*/ /* end of PDMA register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __PDMA_REG_H__ */
