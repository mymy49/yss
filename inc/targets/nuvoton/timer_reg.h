/**************************************************************************//**
 * @file     timer_reg.h
 * @version  V1.00
 * @brief    TIMER register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __TIMER_REG_H__
#define __TIMER_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/**
    @addtogroup TIMER_CONST TIMER Bit Field Definition
    Constant Definitions for TIMER Controller
@{ */

#define TIMER_CTL_PSC_Pos                (0)                                               /*!< TIMER_T::CTL: PSC Position             */
#define TIMER_CTL_PSC_Msk                (0xfful << TIMER_CTL_PSC_Pos)                     /*!< TIMER_T::CTL: PSC Mask                 */

#define TIMER_CTL_INTRGEN_Pos            (19)                                              /*!< TIMER_T::CTL: INTRGEN Position         */
#define TIMER_CTL_INTRGEN_Msk            (0x1ul << TIMER_CTL_INTRGEN_Pos)                  /*!< TIMER_T::CTL: INTRGEN Mask             */

#define TIMER_CTL_PERIOSEL_Pos           (20)                                              /*!< TIMER_T::CTL: PERIOSEL Position        */
#define TIMER_CTL_PERIOSEL_Msk           (0x1ul << TIMER_CTL_PERIOSEL_Pos)                 /*!< TIMER_T::CTL: PERIOSEL Mask            */

#define TIMER_CTL_TGLPINSEL_Pos          (21)                                              /*!< TIMER_T::CTL: TGLPINSEL Position       */
#define TIMER_CTL_TGLPINSEL_Msk          (0x1ul << TIMER_CTL_TGLPINSEL_Pos)                /*!< TIMER_T::CTL: TGLPINSEL Mask           */

#define TIMER_CTL_CAPSRC_Pos             (22)                                              /*!< TIMER_T::CTL: CAPSRC Position          */
#define TIMER_CTL_CAPSRC_Msk             (0x1ul << TIMER_CTL_CAPSRC_Pos)                   /*!< TIMER_T::CTL: CAPSRC Mask              */

#define TIMER_CTL_WKEN_Pos               (23)                                              /*!< TIMER_T::CTL: WKEN Position            */
#define TIMER_CTL_WKEN_Msk               (0x1ul << TIMER_CTL_WKEN_Pos)                     /*!< TIMER_T::CTL: WKEN Mask                */

#define TIMER_CTL_EXTCNTEN_Pos           (24)                                              /*!< TIMER_T::CTL: EXTCNTEN Position        */
#define TIMER_CTL_EXTCNTEN_Msk           (0x1ul << TIMER_CTL_EXTCNTEN_Pos)                 /*!< TIMER_T::CTL: EXTCNTEN Mask            */

#define TIMER_CTL_ACTSTS_Pos             (25)                                              /*!< TIMER_T::CTL: ACTSTS Position          */
#define TIMER_CTL_ACTSTS_Msk             (0x1ul << TIMER_CTL_ACTSTS_Pos)                   /*!< TIMER_T::CTL: ACTSTS Mask              */

#define TIMER_CTL_OPMODE_Pos             (27)                                              /*!< TIMER_T::CTL: OPMODE Position          */
#define TIMER_CTL_OPMODE_Msk             (0x3ul << TIMER_CTL_OPMODE_Pos)                   /*!< TIMER_T::CTL: OPMODE Mask              */

#define TIMER_CTL_INTEN_Pos              (29)                                              /*!< TIMER_T::CTL: INTEN Position           */
#define TIMER_CTL_INTEN_Msk              (0x1ul << TIMER_CTL_INTEN_Pos)                    /*!< TIMER_T::CTL: INTEN Mask               */

#define TIMER_CTL_CNTEN_Pos              (30)                                              /*!< TIMER_T::CTL: CNTEN Position           */
#define TIMER_CTL_CNTEN_Msk              (0x1ul << TIMER_CTL_CNTEN_Pos)                    /*!< TIMER_T::CTL: CNTEN Mask               */

#define TIMER_CTL_ICEDEBUG_Pos           (31)                                              /*!< TIMER_T::CTL: ICEDEBUG Position        */
#define TIMER_CTL_ICEDEBUG_Msk           (0x1ul << TIMER_CTL_ICEDEBUG_Pos)                 /*!< TIMER_T::CTL: ICEDEBUG Mask            */

#define TIMER_CMP_CMPDAT_Pos             (0)                                               /*!< TIMER_T::CMP: CMPDAT Position          */
#define TIMER_CMP_CMPDAT_Msk             (0xfffffful << TIMER_CMP_CMPDAT_Pos)              /*!< TIMER_T::CMP: CMPDAT Mask              */

#define TIMER_INTSTS_TIF_Pos             (0)                                               /*!< TIMER_T::INTSTS: TIF Position          */
#define TIMER_INTSTS_TIF_Msk             (0x1ul << TIMER_INTSTS_TIF_Pos)                   /*!< TIMER_T::INTSTS: TIF Mask              */

#define TIMER_INTSTS_TWKF_Pos            (1)                                               /*!< TIMER_T::INTSTS: TWKF Position         */
#define TIMER_INTSTS_TWKF_Msk            (0x1ul << TIMER_INTSTS_TWKF_Pos)                  /*!< TIMER_T::INTSTS: TWKF Mask             */

#define TIMER_CNT_CNT_Pos                (0)                                               /*!< TIMER_T::CNT: CNT Position             */
#define TIMER_CNT_CNT_Msk                (0xfffffful << TIMER_CNT_CNT_Pos)                 /*!< TIMER_T::CNT: CNT Mask                 */

#define TIMER_CNT_RSTACT_Pos             (31)                                              /*!< TIMER_T::CNT: RSTACT Position          */
#define TIMER_CNT_RSTACT_Msk             (0x1ul << TIMER_CNT_RSTACT_Pos)                   /*!< TIMER_T::CNT: RSTACT Mask              */

#define TIMER_CAP_CAPDAT_Pos             (0)                                               /*!< TIMER_T::CAP: CAPDAT Position          */
#define TIMER_CAP_CAPDAT_Msk             (0xfffffful << TIMER_CAP_CAPDAT_Pos)              /*!< TIMER_T::CAP: CAPDAT Mask              */

#define TIMER_EXTCTL_CNTPHASE_Pos        (0)                                               /*!< TIMER_T::EXTCTL: CNTPHASE Position     */
#define TIMER_EXTCTL_CNTPHASE_Msk        (0x1ul << TIMER_EXTCTL_CNTPHASE_Pos)              /*!< TIMER_T::EXTCTL: CNTPHASE Mask         */

#define TIMER_EXTCTL_CAPEN_Pos           (3)                                               /*!< TIMER_T::EXTCTL: CAPEN Position        */
#define TIMER_EXTCTL_CAPEN_Msk           (0x1ul << TIMER_EXTCTL_CAPEN_Pos)                 /*!< TIMER_T::EXTCTL: CAPEN Mask            */

#define TIMER_EXTCTL_CAPFUNCS_Pos        (4)                                               /*!< TIMER_T::EXTCTL: CAPFUNCS Position     */
#define TIMER_EXTCTL_CAPFUNCS_Msk        (0x1ul << TIMER_EXTCTL_CAPFUNCS_Pos)              /*!< TIMER_T::EXTCTL: CAPFUNCS Mask         */

#define TIMER_EXTCTL_CAPIEN_Pos          (5)                                               /*!< TIMER_T::EXTCTL: CAPIEN Position       */
#define TIMER_EXTCTL_CAPIEN_Msk          (0x1ul << TIMER_EXTCTL_CAPIEN_Pos)                /*!< TIMER_T::EXTCTL: CAPIEN Mask           */

#define TIMER_EXTCTL_CAPDBEN_Pos         (6)                                               /*!< TIMER_T::EXTCTL: CAPDBEN Position      */
#define TIMER_EXTCTL_CAPDBEN_Msk         (0x1ul << TIMER_EXTCTL_CAPDBEN_Pos)               /*!< TIMER_T::EXTCTL: CAPDBEN Mask          */

#define TIMER_EXTCTL_CNTDBEN_Pos         (7)                                               /*!< TIMER_T::EXTCTL: CNTDBEN Position      */
#define TIMER_EXTCTL_CNTDBEN_Msk         (0x1ul << TIMER_EXTCTL_CNTDBEN_Pos)               /*!< TIMER_T::EXTCTL: CNTDBEN Mask          */

#define TIMER_EXTCTL_ICAPSEL_Pos         (8)                                               /*!< TIMER_T::EXTCTL: ICAPSEL Position      */
#define TIMER_EXTCTL_ICAPSEL_Msk         (0x7ul << TIMER_EXTCTL_ICAPSEL_Pos)               /*!< TIMER_T::EXTCTL: ICAPSEL Mask          */

#define TIMER_EXTCTL_CAPEDGE_Pos         (12)                                              /*!< TIMER_T::EXTCTL: CAPEDGE Position      */
#define TIMER_EXTCTL_CAPEDGE_Msk         (0x7ul << TIMER_EXTCTL_CAPEDGE_Pos)               /*!< TIMER_T::EXTCTL: CAPEDGE Mask          */

#define TIMER_EXTCTL_ECNTSSEL_Pos        (16)                                              /*!< TIMER_T::EXTCTL: ECNTSSEL Position     */
#define TIMER_EXTCTL_ECNTSSEL_Msk        (0x1ul << TIMER_EXTCTL_ECNTSSEL_Pos)              /*!< TIMER_T::EXTCTL: ECNTSSEL Mask         */

#define TIMER_EXTCTL_CAPDIVSCL_Pos       (28)                                              /*!< TIMER_T::EXTCTL: CAPDIVSCL Position     */
#define TIMER_EXTCTL_CAPDIVSCL_Msk       (0xful << TIMER_EXTCTL_CAPDIVSCL_Pos)             /*!< TIMER_T::EXTCTL: CAPDIVSCL Mask         */

#define TIMER_EINTSTS_CAPIF_Pos          (0)                                               /*!< TIMER_T::EINTSTS: CAPIF Position       */
#define TIMER_EINTSTS_CAPIF_Msk          (0x1ul << TIMER_EINTSTS_CAPIF_Pos)                /*!< TIMER_T::EINTSTS: CAPIF Mask           */

#define TIMER_TRGCTL_TRGSSEL_Pos         (0)                                               /*!< TIMER_T::TRGCTL: TRGSSEL Position      */
#define TIMER_TRGCTL_TRGSSEL_Msk         (0x1ul << TIMER_TRGCTL_TRGSSEL_Pos)               /*!< TIMER_T::TRGCTL: TRGSSEL Mask          */

#define TIMER_TRGCTL_TRGEPWM_Pos         (1)                                               /*!< TIMER_T::TRGCTL: TRGEPWM Position      */
#define TIMER_TRGCTL_TRGEPWM_Msk         (0x1ul << TIMER_TRGCTL_TRGEPWM_Pos)               /*!< TIMER_T::TRGCTL: TRGEPWM Mask          */

#define TIMER_TRGCTL_TRGEADC_Pos         (2)                                               /*!< TIMER_T::TRGCTL: TRGEADC Position      */
#define TIMER_TRGCTL_TRGEADC_Msk         (0x1ul << TIMER_TRGCTL_TRGEADC_Pos)               /*!< TIMER_T::TRGCTL: TRGEADC Mask          */

#define TIMER_TRGCTL_TRGDAC_Pos          (3)                                               /*!< TIMER_T::TRGCTL: TRGDAC Position       */
#define TIMER_TRGCTL_TRGDAC_Msk          (0x1ul << TIMER_TRGCTL_TRGDAC_Pos)                /*!< TIMER_T::TRGCTL: TRGDAC Mask           */

#define TIMER_TRGCTL_TRGPDMA_Pos         (4)                                               /*!< TIMER_T::TRGCTL: TRGPDMA Position      */
#define TIMER_TRGCTL_TRGPDMA_Msk         (0x1ul << TIMER_TRGCTL_TRGPDMA_Pos)               /*!< TIMER_T::TRGCTL: TRGPDMA Mask          */

#define TIMER_ALTCTL_FUNCSEL_Pos         (0)                                               /*!< TIMER_T::ALTCTL: FUNCSEL Position      */
#define TIMER_ALTCTL_FUNCSEL_Msk         (0x1ul << TIMER_ALTCTL_FUNCSEL_Pos)               /*!< TIMER_T::ALTCTL: FUNCSEL Mask          */

#define TIMER_PWMCTL_CNTEN_Pos           (0)                                               /*!< TIMER_T::PWMCTL: CNTEN Position        */
#define TIMER_PWMCTL_CNTEN_Msk           (0x1ul << TIMER_PWMCTL_CNTEN_Pos)                 /*!< TIMER_T::PWMCTL: CNTEN Mask            */

#define TIMER_PWMCTL_CNTTYPE_Pos         (1)                                               /*!< TIMER_T::PWMCTL: CNTTYPE Position      */
#define TIMER_PWMCTL_CNTTYPE_Msk         (0x3ul << TIMER_PWMCTL_CNTTYPE_Pos)               /*!< TIMER_T::PWMCTL: CNTTYPE Mask          */

#define TIMER_PWMCTL_CNTMODE_Pos         (3)                                               /*!< TIMER_T::PWMCTL: CNTMODE Position      */
#define TIMER_PWMCTL_CNTMODE_Msk         (0x1ul << TIMER_PWMCTL_CNTMODE_Pos)               /*!< TIMER_T::PWMCTL: CNTMODE Mask          */

#define TIMER_PWMCTL_CTRLD_Pos           (8)                                               /*!< TIMER_T::PWMCTL: CTRLD Position        */
#define TIMER_PWMCTL_CTRLD_Msk           (0x1ul << TIMER_PWMCTL_CTRLD_Pos)                 /*!< TIMER_T::PWMCTL: CTRLD Mask            */

#define TIMER_PWMCTL_IMMLDEN_Pos         (9)                                               /*!< TIMER_T::PWMCTL: IMMLDEN Position      */
#define TIMER_PWMCTL_IMMLDEN_Msk         (0x1ul << TIMER_PWMCTL_IMMLDEN_Pos)               /*!< TIMER_T::PWMCTL: IMMLDEN Mask          */

#define TIMER_PWMCTL_OUTMODE_Pos         (16)                                              /*!< TIMER_T::PWMCTL: OUTMODE Position      */
#define TIMER_PWMCTL_OUTMODE_Msk         (0x1ul << TIMER_PWMCTL_OUTMODE_Pos)               /*!< TIMER_T::PWMCTL: OUTMODE Mask          */

#define TIMER_PWMCTL_DBGHALT_Pos         (30)                                              /*!< TIMER_T::PWMCTL: DBGHALT Position      */
#define TIMER_PWMCTL_DBGHALT_Msk         (0x1ul << TIMER_PWMCTL_DBGHALT_Pos)               /*!< TIMER_T::PWMCTL: DBGHALT Mask          */

#define TIMER_PWMCTL_DBGTRIOFF_Pos       (31)                                              /*!< TIMER_T::PWMCTL: DBGTRIOFF Position    */
#define TIMER_PWMCTL_DBGTRIOFF_Msk       (0x1ul << TIMER_PWMCTL_DBGTRIOFF_Pos)             /*!< TIMER_T::PWMCTL: DBGTRIOFF Mask        */

#define TIMER_PWMCLKSRC_CLKSRC_Pos       (0)                                               /*!< TIMER_T::PWMCLKSRC: CLKSRC Position    */
#define TIMER_PWMCLKSRC_CLKSRC_Msk       (0x7ul << TIMER_PWMCLKSRC_CLKSRC_Pos)             /*!< TIMER_T::PWMCLKSRC: CLKSRC Mask        */

#define TIMER_PWMCLKPSC_CLKPSC_Pos       (0)                                               /*!< TIMER_T::PWMCLKPSC: CLKPSC Position    */
#define TIMER_PWMCLKPSC_CLKPSC_Msk       (0xffful << TIMER_PWMCLKPSC_CLKPSC_Pos)           /*!< TIMER_T::PWMCLKPSC: CLKPSC Mask        */

#define TIMER_PWMCNTCLR_CNTCLR_Pos       (0)                                               /*!< TIMER_T::PWMCNTCLR: CNTCLR Position    */
#define TIMER_PWMCNTCLR_CNTCLR_Msk       (0x1ul << TIMER_PWMCNTCLR_CNTCLR_Pos)             /*!< TIMER_T::PWMCNTCLR: CNTCLR Mask        */

#define TIMER_PWMPERIOD_PERIOD_Pos       (0)                                               /*!< TIMER_T::PWMPERIOD: PERIOD Position    */
#define TIMER_PWMPERIOD_PERIOD_Msk       (0xfffful << TIMER_PWMPERIOD_PERIOD_Pos)          /*!< TIMER_T::PWMPERIOD: PERIOD Mask        */

#define TIMER_PWMCMPDAT_CMP_Pos          (0)                                               /*!< TIMER_T::PWMCMPDAT: CMP Position       */
#define TIMER_PWMCMPDAT_CMP_Msk          (0xfffful << TIMER_PWMCMPDAT_CMP_Pos)             /*!< TIMER_T::PWMCMPDAT: CMP Mask           */

#define TIMER_PWMDTCTL_DTCNT_Pos         (0)                                               /*!< TIMER_T::PWMDTCTL: DTCNT Position      */
#define TIMER_PWMDTCTL_DTCNT_Msk         (0xffful << TIMER_PWMDTCTL_DTCNT_Pos)             /*!< TIMER_T::PWMDTCTL: DTCNT Mask          */

#define TIMER_PWMDTCTL_DTEN_Pos          (16)                                              /*!< TIMER_T::PWMDTCTL: DTEN Position       */
#define TIMER_PWMDTCTL_DTEN_Msk          (0x1ul << TIMER_PWMDTCTL_DTEN_Pos)                /*!< TIMER_T::PWMDTCTL: DTEN Mask           */

#define TIMER_PWMDTCTL_DTCKSEL_Pos       (24)                                              /*!< TIMER_T::PWMDTCTL: DTCKSEL Position    */
#define TIMER_PWMDTCTL_DTCKSEL_Msk       (0x1ul << TIMER_PWMDTCTL_DTCKSEL_Pos)             /*!< TIMER_T::PWMDTCTL: DTCKSEL Mask        */

#define TIMER_PWMCNT_CNT_Pos             (0)                                               /*!< TIMER_T::PWMCNT: CNT Position          */
#define TIMER_PWMCNT_CNT_Msk             (0xfffful << TIMER_PWMCNT_CNT_Pos)                /*!< TIMER_T::PWMCNT: CNT Mask              */

#define TIMER_PWMCNT_DIRF_Pos            (16)                                              /*!< TIMER_T::PWMCNT: DIRF Position         */
#define TIMER_PWMCNT_DIRF_Msk            (0x1ul << TIMER_PWMCNT_DIRF_Pos)                  /*!< TIMER_T::PWMCNT: DIRF Mask             */

#define TIMER_PWMMSKEN_MSKEN0_Pos        (0)                                               /*!< TIMER_T::PWMMSKEN: MSKEN0 Position     */
#define TIMER_PWMMSKEN_MSKEN0_Msk        (0x1ul << TIMER_PWMMSKEN_MSKEN0_Pos)              /*!< TIMER_T::PWMMSKEN: MSKEN0 Mask         */

#define TIMER_PWMMSKEN_MSKEN1_Pos        (1)                                               /*!< TIMER_T::PWMMSKEN: MSKEN1 Position     */
#define TIMER_PWMMSKEN_MSKEN1_Msk        (0x1ul << TIMER_PWMMSKEN_MSKEN1_Pos)              /*!< TIMER_T::PWMMSKEN: MSKEN1 Mask         */

#define TIMER_PWMMSK_MSKDAT0_Pos         (0)                                               /*!< TIMER_T::PWMMSK: MSKDAT0 Position      */
#define TIMER_PWMMSK_MSKDAT0_Msk         (0x1ul << TIMER_PWMMSK_MSKDAT0_Pos)               /*!< TIMER_T::PWMMSK: MSKDAT0 Mask          */

#define TIMER_PWMMSK_MSKDAT1_Pos         (1)                                               /*!< TIMER_T::PWMMSK: MSKDAT1 Position      */
#define TIMER_PWMMSK_MSKDAT1_Msk         (0x1ul << TIMER_PWMMSK_MSKDAT1_Pos)               /*!< TIMER_T::PWMMSK: MSKDAT1 Mask          */

#define TIMER_PWMBNF_BRKNFEN_Pos         (0)                                               /*!< TIMER_T::PWMBNF: BRKNFEN Position      */
#define TIMER_PWMBNF_BRKNFEN_Msk         (0x1ul << TIMER_PWMBNF_BRKNFEN_Pos)               /*!< TIMER_T::PWMBNF: BRKNFEN Mask          */

#define TIMER_PWMBNF_BRKNFSEL_Pos        (1)                                               /*!< TIMER_T::PWMBNF: BRKNFSEL Position     */
#define TIMER_PWMBNF_BRKNFSEL_Msk        (0x7ul << TIMER_PWMBNF_BRKNFSEL_Pos)              /*!< TIMER_T::PWMBNF: BRKNFSEL Mask         */

#define TIMER_PWMBNF_BRKFCNT_Pos         (4)                                               /*!< TIMER_T::PWMBNF: BRKFCNT Position      */
#define TIMER_PWMBNF_BRKFCNT_Msk         (0x7ul << TIMER_PWMBNF_BRKFCNT_Pos)               /*!< TIMER_T::PWMBNF: BRKFCNT Mask          */

#define TIMER_PWMBNF_BRKPINV_Pos         (7)                                               /*!< TIMER_T::PWMBNF: BRKPINV Position      */
#define TIMER_PWMBNF_BRKPINV_Msk         (0x1ul << TIMER_PWMBNF_BRKPINV_Pos)               /*!< TIMER_T::PWMBNF: BRKPINV Mask          */

#define TIMER_PWMBNF_BKPINSRC_Pos        (16)                                              /*!< TIMER_T::PWMBNF: BKPINSRC Position     */
#define TIMER_PWMBNF_BKPINSRC_Msk        (0x3ul << TIMER_PWMBNF_BKPINSRC_Pos)              /*!< TIMER_T::PWMBNF: BKPINSRC Mask         */

#define TIMER_PWMFAILBRK_CSSBRKEN_Pos    (0)                                               /*!< TIMER_T::PWMFAILBRK: CSSBRKEN Position */
#define TIMER_PWMFAILBRK_CSSBRKEN_Msk    (0x1ul << TIMER_PWMFAILBRK_CSSBRKEN_Pos)          /*!< TIMER_T::PWMFAILBRK: CSSBRKEN Mask     */

#define TIMER_PWMFAILBRK_BODBRKEN_Pos    (1)                                               /*!< TIMER_T::PWMFAILBRK: BODBRKEN Position */
#define TIMER_PWMFAILBRK_BODBRKEN_Msk    (0x1ul << TIMER_PWMFAILBRK_BODBRKEN_Pos)          /*!< TIMER_T::PWMFAILBRK: BODBRKEN Mask     */

#define TIMER_PWMFAILBRK_RAMBRKEN_Pos    (2)                                               /*!< TIMER_T::PWMFAILBRK: RAMBRKEN Position */
#define TIMER_PWMFAILBRK_RAMBRKEN_Msk    (0x1ul << TIMER_PWMFAILBRK_RAMBRKEN_Pos)          /*!< TIMER_T::PWMFAILBRK: RAMBRKEN Mask     */

#define TIMER_PWMFAILBRK_CORBRKEN_Pos    (3)                                               /*!< TIMER_T::PWMFAILBRK: CORBRKEN Position */
#define TIMER_PWMFAILBRK_CORBRKEN_Msk    (0x1ul << TIMER_PWMFAILBRK_CORBRKEN_Pos)          /*!< TIMER_T::PWMFAILBRK: CORBRKEN Mask     */

#define TIMER_PWMBRKCTL_CPO0EBEN_Pos     (0)                                               /*!< TIMER_T::PWMBRKCTL: CPO0EBEN Position  */
#define TIMER_PWMBRKCTL_CPO0EBEN_Msk     (0x1ul << TIMER_PWMBRKCTL_CPO0EBEN_Pos)           /*!< TIMER_T::PWMBRKCTL: CPO0EBEN Mask      */

#define TIMER_PWMBRKCTL_CPO1EBEN_Pos     (1)                                               /*!< TIMER_T::PWMBRKCTL: CPO1EBEN Position  */
#define TIMER_PWMBRKCTL_CPO1EBEN_Msk     (0x1ul << TIMER_PWMBRKCTL_CPO1EBEN_Pos)           /*!< TIMER_T::PWMBRKCTL: CPO1EBEN Mask      */

#define TIMER_PWMBRKCTL_BRKPEEN_Pos      (4)                                               /*!< TIMER_T::PWMBRKCTL: BRKPEEN Position   */
#define TIMER_PWMBRKCTL_BRKPEEN_Msk      (0x1ul << TIMER_PWMBRKCTL_BRKPEEN_Pos)            /*!< TIMER_T::PWMBRKCTL: BRKPEEN Mask       */

#define TIMER_PWMBRKCTL_SYSEBEN_Pos      (7)                                               /*!< TIMER_T::PWMBRKCTL: SYSEBEN Position   */
#define TIMER_PWMBRKCTL_SYSEBEN_Msk      (0x1ul << TIMER_PWMBRKCTL_SYSEBEN_Pos)            /*!< TIMER_T::PWMBRKCTL: SYSEBEN Mask       */

#define TIMER_PWMBRKCTL_CPO0LBEN_Pos     (8)                                               /*!< TIMER_T::PWMBRKCTL: CPO0LBEN Position  */
#define TIMER_PWMBRKCTL_CPO0LBEN_Msk     (0x1ul << TIMER_PWMBRKCTL_CPO0LBEN_Pos)           /*!< TIMER_T::PWMBRKCTL: CPO0LBEN Mask      */

#define TIMER_PWMBRKCTL_CPO1LBEN_Pos     (9)                                               /*!< TIMER_T::PWMBRKCTL: CPO1LBEN Position  */
#define TIMER_PWMBRKCTL_CPO1LBEN_Msk     (0x1ul << TIMER_PWMBRKCTL_CPO1LBEN_Pos)           /*!< TIMER_T::PWMBRKCTL: CPO1LBEN Mask      */

#define TIMER_PWMBRKCTL_BRKPLEN_Pos      (12)                                              /*!< TIMER_T::PWMBRKCTL: BRKPLEN Position   */
#define TIMER_PWMBRKCTL_BRKPLEN_Msk      (0x1ul << TIMER_PWMBRKCTL_BRKPLEN_Pos)            /*!< TIMER_T::PWMBRKCTL: BRKPLEN Mask       */

#define TIMER_PWMBRKCTL_SYSLBEN_Pos      (15)                                              /*!< TIMER_T::PWMBRKCTL: SYSLBEN Position   */
#define TIMER_PWMBRKCTL_SYSLBEN_Msk      (0x1ul << TIMER_PWMBRKCTL_SYSLBEN_Pos)            /*!< TIMER_T::PWMBRKCTL: SYSLBEN Mask       */

#define TIMER_PWMBRKCTL_BRKAEVEN_Pos     (16)                                              /*!< TIMER_T::PWMBRKCTL: BRKAEVEN Position  */
#define TIMER_PWMBRKCTL_BRKAEVEN_Msk     (0x3ul << TIMER_PWMBRKCTL_BRKAEVEN_Pos)           /*!< TIMER_T::PWMBRKCTL: BRKAEVEN Mask      */

#define TIMER_PWMBRKCTL_BRKAODD_Pos      (18)                                              /*!< TIMER_T::PWMBRKCTL: BRKAODD Position   */
#define TIMER_PWMBRKCTL_BRKAODD_Msk      (0x3ul << TIMER_PWMBRKCTL_BRKAODD_Pos)            /*!< TIMER_T::PWMBRKCTL: BRKAODD Mask       */

#define TIMER_PWMPOLCTL_PINV0_Pos        (0)                                               /*!< TIMER_T::PWMPOLCTL: PINV0 Position     */
#define TIMER_PWMPOLCTL_PINV0_Msk        (0x1ul << TIMER_PWMPOLCTL_PINV0_Pos)              /*!< TIMER_T::PWMPOLCTL: PINV0 Mask         */

#define TIMER_PWMPOLCTL_PINV1_Pos        (1)                                               /*!< TIMER_T::PWMPOLCTL: PINV1 Position     */
#define TIMER_PWMPOLCTL_PINV1_Msk        (0x1ul << TIMER_PWMPOLCTL_PINV1_Pos)              /*!< TIMER_T::PWMPOLCTL: PINV1 Mask         */

#define TIMER_PWMPOEN_POEN0_Pos          (0)                                               /*!< TIMER_T::PWMPOEN: POEN0 Position       */
#define TIMER_PWMPOEN_POEN0_Msk          (0x1ul << TIMER_PWMPOEN_POEN0_Pos)                /*!< TIMER_T::PWMPOEN: POEN0 Mask           */

#define TIMER_PWMPOEN_POEN1_Pos          (1)                                               /*!< TIMER_T::PWMPOEN: POEN1 Position       */
#define TIMER_PWMPOEN_POEN1_Msk          (0x1ul << TIMER_PWMPOEN_POEN1_Pos)                /*!< TIMER_T::PWMPOEN: POEN1 Mask           */

#define TIMER_PWMSWBRK_BRKETRG_Pos       (0)                                               /*!< TIMER_T::PWMSWBRK: BRKETRG Position    */
#define TIMER_PWMSWBRK_BRKETRG_Msk       (0x1ul << TIMER_PWMSWBRK_BRKETRG_Pos)             /*!< TIMER_T::PWMSWBRK: BRKETRG Mask        */

#define TIMER_PWMSWBRK_BRKLTRG_Pos       (8)                                               /*!< TIMER_T::PWMSWBRK: BRKLTRG Position    */
#define TIMER_PWMSWBRK_BRKLTRG_Msk       (0x1ul << TIMER_PWMSWBRK_BRKLTRG_Pos)             /*!< TIMER_T::PWMSWBRK: BRKLTRG Mask        */

#define TIMER_PWMINTEN0_ZIEN_Pos         (0)                                               /*!< TIMER_T::PWMINTEN0: ZIEN Position      */
#define TIMER_PWMINTEN0_ZIEN_Msk         (0x1ul << TIMER_PWMINTEN0_ZIEN_Pos)               /*!< TIMER_T::PWMINTEN0: ZIEN Mask          */

#define TIMER_PWMINTEN0_PIEN_Pos         (1)                                               /*!< TIMER_T::PWMINTEN0: PIEN Position      */
#define TIMER_PWMINTEN0_PIEN_Msk         (0x1ul << TIMER_PWMINTEN0_PIEN_Pos)               /*!< TIMER_T::PWMINTEN0: PIEN Mask          */

#define TIMER_PWMINTEN0_CMPUIEN_Pos      (2)                                               /*!< TIMER_T::PWMINTEN0: CMPUIEN Position   */
#define TIMER_PWMINTEN0_CMPUIEN_Msk      (0x1ul << TIMER_PWMINTEN0_CMPUIEN_Pos)            /*!< TIMER_T::PWMINTEN0: CMPUIEN Mask       */

#define TIMER_PWMINTEN0_CMPDIEN_Pos      (3)                                               /*!< TIMER_T::PWMINTEN0: CMPDIEN Position   */
#define TIMER_PWMINTEN0_CMPDIEN_Msk      (0x1ul << TIMER_PWMINTEN0_CMPDIEN_Pos)            /*!< TIMER_T::PWMINTEN0: CMPDIEN Mask       */

#define TIMER_PWMINTEN1_BRKEIEN_Pos      (0)                                               /*!< TIMER_T::PWMINTEN1: BRKEIEN Position   */
#define TIMER_PWMINTEN1_BRKEIEN_Msk      (0x1ul << TIMER_PWMINTEN1_BRKEIEN_Pos)            /*!< TIMER_T::PWMINTEN1: BRKEIEN Mask       */

#define TIMER_PWMINTEN1_BRKLIEN_Pos      (8)                                               /*!< TIMER_T::PWMINTEN1: BRKLIEN Position   */
#define TIMER_PWMINTEN1_BRKLIEN_Msk      (0x1ul << TIMER_PWMINTEN1_BRKLIEN_Pos)            /*!< TIMER_T::PWMINTEN1: BRKLIEN Mask       */

#define TIMER_PWMINTSTS0_ZIF_Pos         (0)                                               /*!< TIMER_T::PWMINTSTS0: ZIF Position      */
#define TIMER_PWMINTSTS0_ZIF_Msk         (0x1ul << TIMER_PWMINTSTS0_ZIF_Pos)               /*!< TIMER_T::PWMINTSTS0: ZIF Mask          */

#define TIMER_PWMINTSTS0_PIF_Pos         (1)                                               /*!< TIMER_T::PWMINTSTS0: PIF Position      */
#define TIMER_PWMINTSTS0_PIF_Msk         (0x1ul << TIMER_PWMINTSTS0_PIF_Pos)               /*!< TIMER_T::PWMINTSTS0: PIF Mask          */

#define TIMER_PWMINTSTS0_CMPUIF_Pos      (2)                                               /*!< TIMER_T::PWMINTSTS0: CMPUIF Position   */
#define TIMER_PWMINTSTS0_CMPUIF_Msk      (0x1ul << TIMER_PWMINTSTS0_CMPUIF_Pos)            /*!< TIMER_T::PWMINTSTS0: CMPUIF Mask       */

#define TIMER_PWMINTSTS0_CMPDIF_Pos      (3)                                               /*!< TIMER_T::PWMINTSTS0: CMPDIF Position   */
#define TIMER_PWMINTSTS0_CMPDIF_Msk      (0x1ul << TIMER_PWMINTSTS0_CMPDIF_Pos)            /*!< TIMER_T::PWMINTSTS0: CMPDIF Mask       */

#define TIMER_PWMINTSTS1_BRKEIF0_Pos     (0)                                               /*!< TIMER_T::PWMINTSTS1: BRKEIF0 Position  */
#define TIMER_PWMINTSTS1_BRKEIF0_Msk     (0x1ul << TIMER_PWMINTSTS1_BRKEIF0_Pos)           /*!< TIMER_T::PWMINTSTS1: BRKEIF0 Mask      */

#define TIMER_PWMINTSTS1_BRKEIF1_Pos     (1)                                               /*!< TIMER_T::PWMINTSTS1: BRKEIF1 Position  */
#define TIMER_PWMINTSTS1_BRKEIF1_Msk     (0x1ul << TIMER_PWMINTSTS1_BRKEIF1_Pos)           /*!< TIMER_T::PWMINTSTS1: BRKEIF1 Mask      */

#define TIMER_PWMINTSTS1_BRKLIF0_Pos     (8)                                               /*!< TIMER_T::PWMINTSTS1: BRKLIF0 Position  */
#define TIMER_PWMINTSTS1_BRKLIF0_Msk     (0x1ul << TIMER_PWMINTSTS1_BRKLIF0_Pos)           /*!< TIMER_T::PWMINTSTS1: BRKLIF0 Mask      */

#define TIMER_PWMINTSTS1_BRKLIF1_Pos     (9)                                               /*!< TIMER_T::PWMINTSTS1: BRKLIF1 Position  */
#define TIMER_PWMINTSTS1_BRKLIF1_Msk     (0x1ul << TIMER_PWMINTSTS1_BRKLIF1_Pos)           /*!< TIMER_T::PWMINTSTS1: BRKLIF1 Mask      */

#define TIMER_PWMINTSTS1_BRKESTS0_Pos    (16)                                              /*!< TIMER_T::PWMINTSTS1: BRKESTS0 Position */
#define TIMER_PWMINTSTS1_BRKESTS0_Msk    (0x1ul << TIMER_PWMINTSTS1_BRKESTS0_Pos)          /*!< TIMER_T::PWMINTSTS1: BRKESTS0 Mask     */

#define TIMER_PWMINTSTS1_BRKESTS1_Pos    (17)                                              /*!< TIMER_T::PWMINTSTS1: BRKESTS1 Position */
#define TIMER_PWMINTSTS1_BRKESTS1_Msk    (0x1ul << TIMER_PWMINTSTS1_BRKESTS1_Pos)          /*!< TIMER_T::PWMINTSTS1: BRKESTS1 Mask     */

#define TIMER_PWMINTSTS1_BRKLSTS0_Pos    (24)                                              /*!< TIMER_T::PWMINTSTS1: BRKLSTS0 Position */
#define TIMER_PWMINTSTS1_BRKLSTS0_Msk    (0x1ul << TIMER_PWMINTSTS1_BRKLSTS0_Pos)          /*!< TIMER_T::PWMINTSTS1: BRKLSTS0 Mask     */

#define TIMER_PWMINTSTS1_BRKLSTS1_Pos    (25)                                              /*!< TIMER_T::PWMINTSTS1: BRKLSTS1 Position */
#define TIMER_PWMINTSTS1_BRKLSTS1_Msk    (0x1ul << TIMER_PWMINTSTS1_BRKLSTS1_Pos)          /*!< TIMER_T::PWMINTSTS1: BRKLSTS1 Mask     */

#define TIMER_PWMEADCTS_TRGSEL_Pos       (0)                                               /*!< TIMER_T::PWMEADCTS: TRGSEL Position    */
#define TIMER_PWMEADCTS_TRGSEL_Msk       (0x7ul << TIMER_PWMEADCTS_TRGSEL_Pos)             /*!< TIMER_T::PWMEADCTS: TRGSEL Mask        */

#define TIMER_PWMEADCTS_TRGEN_Pos        (7)                                               /*!< TIMER_T::PWMEADCTS: TRGEN Position     */
#define TIMER_PWMEADCTS_TRGEN_Msk        (0x1ul << TIMER_PWMEADCTS_TRGEN_Pos)              /*!< TIMER_T::PWMEADCTS: TRGEN Mask         */

#define TIMER_PWMSCTL_SYNCMODE_Pos       (0)                                               /*!< TIMER_T::PWMSCTL: SYNCMODE Position    */
#define TIMER_PWMSCTL_SYNCMODE_Msk       (0x3ul << TIMER_PWMSCTL_SYNCMODE_Pos)             /*!< TIMER_T::PWMSCTL: SYNCMODE Mask        */

#define TIMER_PWMSCTL_SYNCSRC_Pos        (8)                                               /*!< TIMER_T::PWMSCTL: SYNCSRC Position     */
#define TIMER_PWMSCTL_SYNCSRC_Msk        (0x1ul << TIMER_PWMSCTL_SYNCSRC_Pos)              /*!< TIMER_T::PWMSCTL: SYNCSRC Mask         */

#define TIMER_PWMSTRG_STRGEN_Pos         (0)                                               /*!< TIMER_T::PWMSTRG: STRGEN Position      */
#define TIMER_PWMSTRG_STRGEN_Msk         (0x1ul << TIMER_PWMSTRG_STRGEN_Pos)               /*!< TIMER_T::PWMSTRG: STRGEN Mask          */

#define TIMER_PWMSTATUS_CNTMAXF_Pos      (0)                                               /*!< TIMER_T::PWMSTATUS: CNTMAXF Position   */
#define TIMER_PWMSTATUS_CNTMAXF_Msk      (0x1ul << TIMER_PWMSTATUS_CNTMAXF_Pos)            /*!< TIMER_T::PWMSTATUS: CNTMAXF Mask       */

#define TIMER_PWMSTATUS_EADCTRGF_Pos     (16)                                              /*!< TIMER_T::PWMSTATUS: EADCTRGF Position  */
#define TIMER_PWMSTATUS_EADCTRGF_Msk     (0x1ul << TIMER_PWMSTATUS_EADCTRGF_Pos)           /*!< TIMER_T::PWMSTATUS: EADCTRGF Mask      */

#define TIMER_PWMPBUF_PBUF_Pos           (0)                                               /*!< TIMER_T::PWMPBUF: PBUF Position        */
#define TIMER_PWMPBUF_PBUF_Msk           (0xfffful << TIMER_PWMPBUF_PBUF_Pos)              /*!< TIMER_T::PWMPBUF: PBUF Mask            */

#define TIMER_PWMCMPBUF_CMPBUF_Pos       (0)                                               /*!< TIMER_T::PWMCMPBUF: CMPBUF Position    */
#define TIMER_PWMCMPBUF_CMPBUF_Msk       (0xfffful << TIMER_PWMCMPBUF_CMPBUF_Pos)          /*!< TIMER_T::PWMCMPBUF: CMPBUF Mask        */

/**@}*/ /* TIMER_CONST */
/**@}*/ /* end of TIMER register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __TIMER_REG_H__ */
