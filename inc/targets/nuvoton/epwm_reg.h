/**************************************************************************//**
 * @file     epwm_reg.h
 * @version  V1.00
 * @brief    EPWM register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __EPWM_REG_H__
#define __EPWM_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/**
    @addtogroup EPWM_CONST EPWM Bit Field Definition
    Constant Definitions for EPWM Controller
@{ */

#define EPWM_CTL0_CTRLD0_Pos              (0)                                               /*!< EPWM_T::CTL0: CTRLD0 Position           */
#define EPWM_CTL0_CTRLD0_Msk              (0x1ul << EPWM_CTL0_CTRLD0_Pos)                   /*!< EPWM_T::CTL0: CTRLD0 Mask               */

#define EPWM_CTL0_CTRLD1_Pos              (1)                                               /*!< EPWM_T::CTL0: CTRLD1 Position           */
#define EPWM_CTL0_CTRLD1_Msk              (0x1ul << EPWM_CTL0_CTRLD1_Pos)                   /*!< EPWM_T::CTL0: CTRLD1 Mask               */

#define EPWM_CTL0_CTRLD2_Pos              (2)                                               /*!< EPWM_T::CTL0: CTRLD2 Position           */
#define EPWM_CTL0_CTRLD2_Msk              (0x1ul << EPWM_CTL0_CTRLD2_Pos)                    /*!< EPWM_T::CTL0: CTRLD2 Mask               */

#define EPWM_CTL0_CTRLD3_Pos              (3)                                               /*!< EPWM_T::CTL0: CTRLD3 Position           */
#define EPWM_CTL0_CTRLD3_Msk              (0x1ul << EPWM_CTL0_CTRLD3_Pos)                    /*!< EPWM_T::CTL0: CTRLD3 Mask               */

#define EPWM_CTL0_CTRLD4_Pos              (4)                                               /*!< EPWM_T::CTL0: CTRLD4 Position           */
#define EPWM_CTL0_CTRLD4_Msk              (0x1ul << EPWM_CTL0_CTRLD4_Pos)                    /*!< EPWM_T::CTL0: CTRLD4 Mask               */

#define EPWM_CTL0_CTRLD5_Pos              (5)                                               /*!< EPWM_T::CTL0: CTRLD5 Position           */
#define EPWM_CTL0_CTRLD5_Msk              (0x1ul << EPWM_CTL0_CTRLD5_Pos)                    /*!< EPWM_T::CTL0: CTRLD5 Mask               */

#define EPWM_CTL0_WINLDEN0_Pos            (8)                                               /*!< EPWM_T::CTL0: WINLDEN0 Position         */
#define EPWM_CTL0_WINLDEN0_Msk            (0x1ul << EPWM_CTL0_WINLDEN0_Pos)                  /*!< EPWM_T::CTL0: WINLDEN0 Mask             */

#define EPWM_CTL0_WINLDEN1_Pos            (9)                                               /*!< EPWM_T::CTL0: WINLDEN1 Position         */
#define EPWM_CTL0_WINLDEN1_Msk            (0x1ul << EPWM_CTL0_WINLDEN1_Pos)                  /*!< EPWM_T::CTL0: WINLDEN1 Mask             */

#define EPWM_CTL0_WINLDEN2_Pos            (10)                                              /*!< EPWM_T::CTL0: WINLDEN2 Position         */
#define EPWM_CTL0_WINLDEN2_Msk            (0x1ul << EPWM_CTL0_WINLDEN2_Pos)                  /*!< EPWM_T::CTL0: WINLDEN2 Mask             */

#define EPWM_CTL0_WINLDEN3_Pos            (11)                                              /*!< EPWM_T::CTL0: WINLDEN3 Position         */
#define EPWM_CTL0_WINLDEN3_Msk            (0x1ul << EPWM_CTL0_WINLDEN3_Pos)                  /*!< EPWM_T::CTL0: WINLDEN3 Mask             */

#define EPWM_CTL0_WINLDEN4_Pos            (12)                                              /*!< EPWM_T::CTL0: WINLDEN4 Position         */
#define EPWM_CTL0_WINLDEN4_Msk            (0x1ul << EPWM_CTL0_WINLDEN4_Pos)                  /*!< EPWM_T::CTL0: WINLDEN4 Mask             */

#define EPWM_CTL0_WINLDEN5_Pos            (13)                                              /*!< EPWM_T::CTL0: WINLDEN5 Position         */
#define EPWM_CTL0_WINLDEN5_Msk            (0x1ul << EPWM_CTL0_WINLDEN5_Pos)                  /*!< EPWM_T::CTL0: WINLDEN5 Mask             */

#define EPWM_CTL0_IMMLDEN0_Pos            (16)                                              /*!< EPWM_T::CTL0: IMMLDEN0 Position         */
#define EPWM_CTL0_IMMLDEN0_Msk            (0x1ul << EPWM_CTL0_IMMLDEN0_Pos)                  /*!< EPWM_T::CTL0: IMMLDEN0 Mask             */

#define EPWM_CTL0_IMMLDEN1_Pos            (17)                                              /*!< EPWM_T::CTL0: IMMLDEN1 Position         */
#define EPWM_CTL0_IMMLDEN1_Msk            (0x1ul << EPWM_CTL0_IMMLDEN1_Pos)                  /*!< EPWM_T::CTL0: IMMLDEN1 Mask             */

#define EPWM_CTL0_IMMLDEN2_Pos            (18)                                              /*!< EPWM_T::CTL0: IMMLDEN2 Position         */
#define EPWM_CTL0_IMMLDEN2_Msk            (0x1ul << EPWM_CTL0_IMMLDEN2_Pos)                  /*!< EPWM_T::CTL0: IMMLDEN2 Mask             */

#define EPWM_CTL0_IMMLDEN3_Pos            (19)                                              /*!< EPWM_T::CTL0: IMMLDEN3 Position         */
#define EPWM_CTL0_IMMLDEN3_Msk            (0x1ul << EPWM_CTL0_IMMLDEN3_Pos)                  /*!< EPWM_T::CTL0: IMMLDEN3 Mask             */

#define EPWM_CTL0_IMMLDEN4_Pos            (20)                                              /*!< EPWM_T::CTL0: IMMLDEN4 Position         */
#define EPWM_CTL0_IMMLDEN4_Msk            (0x1ul << EPWM_CTL0_IMMLDEN4_Pos)                  /*!< EPWM_T::CTL0: IMMLDEN4 Mask             */

#define EPWM_CTL0_IMMLDEN5_Pos            (21)                                              /*!< EPWM_T::CTL0: IMMLDEN5 Position         */
#define EPWM_CTL0_IMMLDEN5_Msk            (0x1ul << EPWM_CTL0_IMMLDEN5_Pos)                  /*!< EPWM_T::CTL0: IMMLDEN5 Mask             */

#define EPWM_CTL0_GROUPEN_Pos             (24)                                              /*!< EPWM_T::CTL0: GROUPEN Position          */
#define EPWM_CTL0_GROUPEN_Msk             (0x1ul << EPWM_CTL0_GROUPEN_Pos)                   /*!< EPWM_T::CTL0: GROUPEN Mask              */

#define EPWM_CTL0_DBGHALT_Pos             (30)                                              /*!< EPWM_T::CTL0: DBGHALT Position          */
#define EPWM_CTL0_DBGHALT_Msk             (0x1ul << EPWM_CTL0_DBGHALT_Pos)                   /*!< EPWM_T::CTL0: DBGHALT Mask              */

#define EPWM_CTL0_DBGTRIOFF_Pos           (31)                                              /*!< EPWM_T::CTL0: DBGTRIOFF Position        */
#define EPWM_CTL0_DBGTRIOFF_Msk           (0x1ul << EPWM_CTL0_DBGTRIOFF_Pos)                 /*!< EPWM_T::CTL0: DBGTRIOFF Mask            */

#define EPWM_CTL1_CNTTYPE0_Pos            (0)                                               /*!< EPWM_T::CTL1: CNTTYPE0 Position         */
#define EPWM_CTL1_CNTTYPE0_Msk            (0x3ul << EPWM_CTL1_CNTTYPE0_Pos)                  /*!< EPWM_T::CTL1: CNTTYPE0 Mask             */

#define EPWM_CTL1_CNTTYPE1_Pos            (2)                                               /*!< EPWM_T::CTL1: CNTTYPE1 Position         */
#define EPWM_CTL1_CNTTYPE1_Msk            (0x3ul << EPWM_CTL1_CNTTYPE1_Pos)                  /*!< EPWM_T::CTL1: CNTTYPE1 Mask             */

#define EPWM_CTL1_CNTTYPE2_Pos            (4)                                               /*!< EPWM_T::CTL1: CNTTYPE2 Position         */
#define EPWM_CTL1_CNTTYPE2_Msk            (0x3ul << EPWM_CTL1_CNTTYPE2_Pos)                  /*!< EPWM_T::CTL1: CNTTYPE2 Mask             */

#define EPWM_CTL1_CNTTYPE3_Pos            (6)                                               /*!< EPWM_T::CTL1: CNTTYPE3 Position         */
#define EPWM_CTL1_CNTTYPE3_Msk            (0x3ul << EPWM_CTL1_CNTTYPE3_Pos)                  /*!< EPWM_T::CTL1: CNTTYPE3 Mask             */

#define EPWM_CTL1_CNTTYPE4_Pos            (8)                                               /*!< EPWM_T::CTL1: CNTTYPE4 Position         */
#define EPWM_CTL1_CNTTYPE4_Msk            (0x3ul << EPWM_CTL1_CNTTYPE4_Pos)                  /*!< EPWM_T::CTL1: CNTTYPE4 Mask             */

#define EPWM_CTL1_CNTTYPE5_Pos            (10)                                              /*!< EPWM_T::CTL1: CNTTYPE5 Position         */
#define EPWM_CTL1_CNTTYPE5_Msk            (0x3ul << EPWM_CTL1_CNTTYPE5_Pos)                  /*!< EPWM_T::CTL1: CNTTYPE5 Mask             */

#define EPWM_CTL1_CNTMODE0_Pos            (16)                                              /*!< EPWM_T::CTL1: CNTMODE0 Position         */
#define EPWM_CTL1_CNTMODE0_Msk            (0x1ul << EPWM_CTL1_CNTMODE0_Pos)                  /*!< EPWM_T::CTL1: CNTMODE0 Mask             */

#define EPWM_CTL1_CNTMODE1_Pos            (17)                                              /*!< EPWM_T::CTL1: CNTMODE1 Position         */
#define EPWM_CTL1_CNTMODE1_Msk            (0x1ul << EPWM_CTL1_CNTMODE1_Pos)                  /*!< EPWM_T::CTL1: CNTMODE1 Mask             */

#define EPWM_CTL1_CNTMODE2_Pos            (18)                                              /*!< EPWM_T::CTL1: CNTMODE2 Position         */
#define EPWM_CTL1_CNTMODE2_Msk            (0x1ul << EPWM_CTL1_CNTMODE2_Pos)                  /*!< EPWM_T::CTL1: CNTMODE2 Mask             */

#define EPWM_CTL1_CNTMODE3_Pos            (19)                                              /*!< EPWM_T::CTL1: CNTMODE3 Position         */
#define EPWM_CTL1_CNTMODE3_Msk            (0x1ul << EPWM_CTL1_CNTMODE3_Pos)                  /*!< EPWM_T::CTL1: CNTMODE3 Mask             */

#define EPWM_CTL1_CNTMODE4_Pos            (20)                                              /*!< EPWM_T::CTL1: CNTMODE4 Position         */
#define EPWM_CTL1_CNTMODE4_Msk            (0x1ul << EPWM_CTL1_CNTMODE4_Pos)                  /*!< EPWM_T::CTL1: CNTMODE4 Mask             */

#define EPWM_CTL1_CNTMODE5_Pos            (21)                                              /*!< EPWM_T::CTL1: CNTMODE5 Position         */
#define EPWM_CTL1_CNTMODE5_Msk            (0x1ul << EPWM_CTL1_CNTMODE5_Pos)                  /*!< EPWM_T::CTL1: CNTMODE5 Mask             */

#define EPWM_CTL1_OUTMODE0_Pos            (24)                                              /*!< EPWM_T::CTL1: OUTMODE0 Position         */
#define EPWM_CTL1_OUTMODE0_Msk            (0x1ul << EPWM_CTL1_OUTMODE0_Pos)                  /*!< EPWM_T::CTL1: OUTMODE0 Mask             */

#define EPWM_CTL1_OUTMODE2_Pos            (25)                                              /*!< EPWM_T::CTL1: OUTMODE2 Position         */
#define EPWM_CTL1_OUTMODE2_Msk            (0x1ul << EPWM_CTL1_OUTMODE2_Pos)                  /*!< EPWM_T::CTL1: OUTMODE2 Mask             */

#define EPWM_CTL1_OUTMODE4_Pos            (26)                                              /*!< EPWM_T::CTL1: OUTMODE4 Position         */
#define EPWM_CTL1_OUTMODE4_Msk            (0x1ul << EPWM_CTL1_OUTMODE4_Pos)                  /*!< EPWM_T::CTL1: OUTMODE4 Mask             */

#define EPWM_SYNC_PHSEN0_Pos              (0)                                               /*!< EPWM_T::SYNC: PHSEN0 Position           */
#define EPWM_SYNC_PHSEN0_Msk              (0x1ul << EPWM_SYNC_PHSEN0_Pos)                    /*!< EPWM_T::SYNC: PHSEN0 Mask               */

#define EPWM_SYNC_PHSEN2_Pos              (1)                                               /*!< EPWM_T::SYNC: PHSEN2 Position           */
#define EPWM_SYNC_PHSEN2_Msk              (0x1ul << EPWM_SYNC_PHSEN2_Pos)                    /*!< EPWM_T::SYNC: PHSEN2 Mask               */

#define EPWM_SYNC_PHSEN4_Pos              (2)                                               /*!< EPWM_T::SYNC: PHSEN4 Position           */
#define EPWM_SYNC_PHSEN4_Msk              (0x1ul << EPWM_SYNC_PHSEN4_Pos)                    /*!< EPWM_T::SYNC: PHSEN4 Mask               */

#define EPWM_SYNC_SINSRC0_Pos             (8)                                               /*!< EPWM_T::SYNC: SINSRC0 Position          */
#define EPWM_SYNC_SINSRC0_Msk             (0x3ul << EPWM_SYNC_SINSRC0_Pos)                   /*!< EPWM_T::SYNC: SINSRC0 Mask              */

#define EPWM_SYNC_SINSRC2_Pos             (10)                                              /*!< EPWM_T::SYNC: SINSRC2 Position          */
#define EPWM_SYNC_SINSRC2_Msk             (0x3ul << EPWM_SYNC_SINSRC2_Pos)                   /*!< EPWM_T::SYNC: SINSRC2 Mask              */

#define EPWM_SYNC_SINSRC4_Pos             (12)                                              /*!< EPWM_T::SYNC: SINSRC4 Position          */
#define EPWM_SYNC_SINSRC4_Msk             (0x3ul << EPWM_SYNC_SINSRC4_Pos)                   /*!< EPWM_T::SYNC: SINSRC4 Mask              */

#define EPWM_SYNC_SNFLTEN_Pos             (16)                                              /*!< EPWM_T::SYNC: SNFLTEN Position          */
#define EPWM_SYNC_SNFLTEN_Msk             (0x1ul << EPWM_SYNC_SNFLTEN_Pos)                   /*!< EPWM_T::SYNC: SNFLTEN Mask              */

#define EPWM_SYNC_SFLTCSEL_Pos            (17)                                              /*!< EPWM_T::SYNC: SFLTCSEL Position         */
#define EPWM_SYNC_SFLTCSEL_Msk            (0x7ul << EPWM_SYNC_SFLTCSEL_Pos)                  /*!< EPWM_T::SYNC: SFLTCSEL Mask             */

#define EPWM_SYNC_SFLTCNT_Pos             (20)                                              /*!< EPWM_T::SYNC: SFLTCNT Position          */
#define EPWM_SYNC_SFLTCNT_Msk             (0x7ul << EPWM_SYNC_SFLTCNT_Pos)                   /*!< EPWM_T::SYNC: SFLTCNT Mask              */

#define EPWM_SYNC_SINPINV_Pos             (23)                                              /*!< EPWM_T::SYNC: SINPINV Position          */
#define EPWM_SYNC_SINPINV_Msk             (0x1ul << EPWM_SYNC_SINPINV_Pos)                   /*!< EPWM_T::SYNC: SINPINV Mask              */

#define EPWM_SYNC_PHSDIR0_Pos             (24)                                              /*!< EPWM_T::SYNC: PHSDIR0 Position          */
#define EPWM_SYNC_PHSDIR0_Msk             (0x1ul << EPWM_SYNC_PHSDIR0_Pos)                   /*!< EPWM_T::SYNC: PHSDIR0 Mask              */

#define EPWM_SYNC_PHSDIR2_Pos             (25)                                              /*!< EPWM_T::SYNC: PHSDIR2 Position          */
#define EPWM_SYNC_PHSDIR2_Msk             (0x1ul << EPWM_SYNC_PHSDIR2_Pos)                   /*!< EPWM_T::SYNC: PHSDIR2 Mask              */

#define EPWM_SYNC_PHSDIR4_Pos             (26)                                              /*!< EPWM_T::SYNC: PHSDIR4 Position          */
#define EPWM_SYNC_PHSDIR4_Msk             (0x1ul << EPWM_SYNC_PHSDIR4_Pos)                   /*!< EPWM_T::SYNC: PHSDIR4 Mask              */

#define EPWM_SWSYNC_SWSYNC0_Pos           (0)                                               /*!< EPWM_T::SWSYNC: SWSYNC0 Position        */
#define EPWM_SWSYNC_SWSYNC0_Msk           (0x1ul << EPWM_SWSYNC_SWSYNC0_Pos)                 /*!< EPWM_T::SWSYNC: SWSYNC0 Mask            */

#define EPWM_SWSYNC_SWSYNC2_Pos           (1)                                               /*!< EPWM_T::SWSYNC: SWSYNC2 Position        */
#define EPWM_SWSYNC_SWSYNC2_Msk           (0x1ul << EPWM_SWSYNC_SWSYNC2_Pos)                 /*!< EPWM_T::SWSYNC: SWSYNC2 Mask            */

#define EPWM_SWSYNC_SWSYNC4_Pos           (2)                                               /*!< EPWM_T::SWSYNC: SWSYNC4 Position        */
#define EPWM_SWSYNC_SWSYNC4_Msk           (0x1ul << EPWM_SWSYNC_SWSYNC4_Pos)                 /*!< EPWM_T::SWSYNC: SWSYNC4 Mask            */

#define EPWM_CLKSRC_ECLKSRC0_Pos          (0)                                               /*!< EPWM_T::CLKSRC: ECLKSRC0 Position       */
#define EPWM_CLKSRC_ECLKSRC0_Msk          (0x7ul << EPWM_CLKSRC_ECLKSRC0_Pos)                /*!< EPWM_T::CLKSRC: ECLKSRC0 Mask           */

#define EPWM_CLKSRC_ECLKSRC2_Pos          (8)                                               /*!< EPWM_T::CLKSRC: ECLKSRC2 Position       */
#define EPWM_CLKSRC_ECLKSRC2_Msk          (0x7ul << EPWM_CLKSRC_ECLKSRC2_Pos)                /*!< EPWM_T::CLKSRC: ECLKSRC2 Mask           */

#define EPWM_CLKSRC_ECLKSRC4_Pos          (16)                                              /*!< EPWM_T::CLKSRC: ECLKSRC4 Position       */
#define EPWM_CLKSRC_ECLKSRC4_Msk          (0x7ul << EPWM_CLKSRC_ECLKSRC4_Pos)                /*!< EPWM_T::CLKSRC: ECLKSRC4 Mask           */

#define EPWM_CLKPSC0_1_CLKPSC_Pos         (0)                                               /*!< EPWM_T::CLKPSC0_1: CLKPSC Position      */
#define EPWM_CLKPSC0_1_CLKPSC_Msk         (0xffful << EPWM_CLKPSC0_1_CLKPSC_Pos)             /*!< EPWM_T::CLKPSC0_1: CLKPSC Mask          */

#define EPWM_CLKPSC2_3_CLKPSC_Pos         (0)                                               /*!< EPWM_T::CLKPSC2_3: CLKPSC Position      */
#define EPWM_CLKPSC2_3_CLKPSC_Msk         (0xffful << EPWM_CLKPSC2_3_CLKPSC_Pos)             /*!< EPWM_T::CLKPSC2_3: CLKPSC Mask          */

#define EPWM_CLKPSC4_5_CLKPSC_Pos         (0)                                               /*!< EPWM_T::CLKPSC4_5: CLKPSC Position      */
#define EPWM_CLKPSC4_5_CLKPSC_Msk         (0xffful << EPWM_CLKPSC4_5_CLKPSC_Pos)             /*!< EPWM_T::CLKPSC4_5: CLKPSC Mask          */

#define EPWM_CNTEN_CNTEN0_Pos             (0)                                               /*!< EPWM_T::CNTEN: CNTEN0 Position          */
#define EPWM_CNTEN_CNTEN0_Msk             (0x1ul << EPWM_CNTEN_CNTEN0_Pos)                   /*!< EPWM_T::CNTEN: CNTEN0 Mask              */

#define EPWM_CNTEN_CNTEN1_Pos             (1)                                               /*!< EPWM_T::CNTEN: CNTEN1 Position          */
#define EPWM_CNTEN_CNTEN1_Msk             (0x1ul << EPWM_CNTEN_CNTEN1_Pos)                   /*!< EPWM_T::CNTEN: CNTEN1 Mask              */

#define EPWM_CNTEN_CNTEN2_Pos             (2)                                               /*!< EPWM_T::CNTEN: CNTEN2 Position          */
#define EPWM_CNTEN_CNTEN2_Msk             (0x1ul << EPWM_CNTEN_CNTEN2_Pos)                   /*!< EPWM_T::CNTEN: CNTEN2 Mask              */

#define EPWM_CNTEN_CNTEN3_Pos             (3)                                               /*!< EPWM_T::CNTEN: CNTEN3 Position          */
#define EPWM_CNTEN_CNTEN3_Msk             (0x1ul << EPWM_CNTEN_CNTEN3_Pos)                   /*!< EPWM_T::CNTEN: CNTEN3 Mask              */

#define EPWM_CNTEN_CNTEN4_Pos             (4)                                               /*!< EPWM_T::CNTEN: CNTEN4 Position          */
#define EPWM_CNTEN_CNTEN4_Msk             (0x1ul << EPWM_CNTEN_CNTEN4_Pos)                   /*!< EPWM_T::CNTEN: CNTEN4 Mask              */

#define EPWM_CNTEN_CNTEN5_Pos             (5)                                               /*!< EPWM_T::CNTEN: CNTEN5 Position          */
#define EPWM_CNTEN_CNTEN5_Msk             (0x1ul << EPWM_CNTEN_CNTEN5_Pos)                   /*!< EPWM_T::CNTEN: CNTEN5 Mask              */

#define EPWM_CNTCLR_CNTCLR0_Pos           (0)                                               /*!< EPWM_T::CNTCLR: CNTCLR0 Position        */
#define EPWM_CNTCLR_CNTCLR0_Msk           (0x1ul << EPWM_CNTCLR_CNTCLR0_Pos)                 /*!< EPWM_T::CNTCLR: CNTCLR0 Mask            */

#define EPWM_CNTCLR_CNTCLR1_Pos           (1)                                               /*!< EPWM_T::CNTCLR: CNTCLR1 Position        */
#define EPWM_CNTCLR_CNTCLR1_Msk           (0x1ul << EPWM_CNTCLR_CNTCLR1_Pos)                 /*!< EPWM_T::CNTCLR: CNTCLR1 Mask            */

#define EPWM_CNTCLR_CNTCLR2_Pos           (2)                                               /*!< EPWM_T::CNTCLR: CNTCLR2 Position        */
#define EPWM_CNTCLR_CNTCLR2_Msk           (0x1ul << EPWM_CNTCLR_CNTCLR2_Pos)                 /*!< EPWM_T::CNTCLR: CNTCLR2 Mask            */

#define EPWM_CNTCLR_CNTCLR3_Pos           (3)                                               /*!< EPWM_T::CNTCLR: CNTCLR3 Position        */
#define EPWM_CNTCLR_CNTCLR3_Msk           (0x1ul << EPWM_CNTCLR_CNTCLR3_Pos)                 /*!< EPWM_T::CNTCLR: CNTCLR3 Mask            */

#define EPWM_CNTCLR_CNTCLR4_Pos           (4)                                               /*!< EPWM_T::CNTCLR: CNTCLR4 Position        */
#define EPWM_CNTCLR_CNTCLR4_Msk           (0x1ul << EPWM_CNTCLR_CNTCLR4_Pos)                 /*!< EPWM_T::CNTCLR: CNTCLR4 Mask            */

#define EPWM_CNTCLR_CNTCLR5_Pos           (5)                                               /*!< EPWM_T::CNTCLR: CNTCLR5 Position        */
#define EPWM_CNTCLR_CNTCLR5_Msk           (0x1ul << EPWM_CNTCLR_CNTCLR5_Pos)                 /*!< EPWM_T::CNTCLR: CNTCLR5 Mask            */

#define EPWM_LOAD_LOAD0_Pos               (0)                                               /*!< EPWM_T::LOAD: LOAD0 Position            */
#define EPWM_LOAD_LOAD0_Msk               (0x1ul << EPWM_LOAD_LOAD0_Pos)                     /*!< EPWM_T::LOAD: LOAD0 Mask                */

#define EPWM_LOAD_LOAD1_Pos               (1)                                               /*!< EPWM_T::LOAD: LOAD1 Position            */
#define EPWM_LOAD_LOAD1_Msk               (0x1ul << EPWM_LOAD_LOAD1_Pos)                     /*!< EPWM_T::LOAD: LOAD1 Mask                */

#define EPWM_LOAD_LOAD2_Pos               (2)                                               /*!< EPWM_T::LOAD: LOAD2 Position            */
#define EPWM_LOAD_LOAD2_Msk               (0x1ul << EPWM_LOAD_LOAD2_Pos)                     /*!< EPWM_T::LOAD: LOAD2 Mask                */

#define EPWM_LOAD_LOAD3_Pos               (3)                                               /*!< EPWM_T::LOAD: LOAD3 Position            */
#define EPWM_LOAD_LOAD3_Msk               (0x1ul << EPWM_LOAD_LOAD3_Pos)                     /*!< EPWM_T::LOAD: LOAD3 Mask                */

#define EPWM_LOAD_LOAD4_Pos               (4)                                               /*!< EPWM_T::LOAD: LOAD4 Position            */
#define EPWM_LOAD_LOAD4_Msk               (0x1ul << EPWM_LOAD_LOAD4_Pos)                     /*!< EPWM_T::LOAD: LOAD4 Mask                */

#define EPWM_LOAD_LOAD5_Pos               (5)                                               /*!< EPWM_T::LOAD: LOAD5 Position            */
#define EPWM_LOAD_LOAD5_Msk               (0x1ul << EPWM_LOAD_LOAD5_Pos)                     /*!< EPWM_T::LOAD: LOAD5 Mask                */

#define EPWM_PERIOD0_PERIOD_Pos           (0)                                               /*!< EPWM_T::PERIOD0: PERIOD Position        */
#define EPWM_PERIOD0_PERIOD_Msk           (0xfffful << EPWM_PERIOD0_PERIOD_Pos)              /*!< EPWM_T::PERIOD0: PERIOD Mask            */

#define EPWM_PERIOD1_PERIOD_Pos           (0)                                               /*!< EPWM_T::PERIOD1: PERIOD Position        */
#define EPWM_PERIOD1_PERIOD_Msk           (0xfffful << EPWM_PERIOD1_PERIOD_Pos)              /*!< EPWM_T::PERIOD1: PERIOD Mask            */

#define EPWM_PERIOD2_PERIOD_Pos           (0)                                               /*!< EPWM_T::PERIOD2: PERIOD Position        */
#define EPWM_PERIOD2_PERIOD_Msk           (0xfffful << EPWM_PERIOD2_PERIOD_Pos)              /*!< EPWM_T::PERIOD2: PERIOD Mask            */

#define EPWM_PERIOD3_PERIOD_Pos           (0)                                               /*!< EPWM_T::PERIOD3: PERIOD Position        */
#define EPWM_PERIOD3_PERIOD_Msk           (0xfffful << EPWM_PERIOD3_PERIOD_Pos)              /*!< EPWM_T::PERIOD3: PERIOD Mask            */

#define EPWM_PERIOD4_PERIOD_Pos           (0)                                               /*!< EPWM_T::PERIOD4: PERIOD Position        */
#define EPWM_PERIOD4_PERIOD_Msk           (0xfffful << EPWM_PERIOD4_PERIOD_Pos)              /*!< EPWM_T::PERIOD4: PERIOD Mask            */

#define EPWM_PERIOD5_PERIOD_Pos           (0)                                               /*!< EPWM_T::PERIOD5: PERIOD Position        */
#define EPWM_PERIOD5_PERIOD_Msk           (0xfffful << EPWM_PERIOD5_PERIOD_Pos)              /*!< EPWM_T::PERIOD5: PERIOD Mask            */

#define EPWM_CMPDAT0_CMP_Pos              (0)                                               /*!< EPWM_T::CMPDAT0: CMP Position           */
#define EPWM_CMPDAT0_CMP_Msk              (0xfffful << EPWM_CMPDAT0_CMP_Pos)                 /*!< EPWM_T::CMPDAT0: CMP Mask               */

#define EPWM_CMPDAT1_CMP_Pos              (0)                                               /*!< EPWM_T::CMPDAT1: CMP Position           */
#define EPWM_CMPDAT1_CMP_Msk              (0xfffful << EPWM_CMPDAT1_CMP_Pos)                 /*!< EPWM_T::CMPDAT1: CMP Mask               */

#define EPWM_CMPDAT2_CMP_Pos              (0)                                               /*!< EPWM_T::CMPDAT2: CMP Position           */
#define EPWM_CMPDAT2_CMP_Msk              (0xfffful << EPWM_CMPDAT2_CMP_Pos)                 /*!< EPWM_T::CMPDAT2: CMP Mask               */

#define EPWM_CMPDAT3_CMP_Pos              (0)                                               /*!< EPWM_T::CMPDAT3: CMP Position           */
#define EPWM_CMPDAT3_CMP_Msk              (0xfffful << EPWM_CMPDAT3_CMP_Pos)                 /*!< EPWM_T::CMPDAT3: CMP Mask               */

#define EPWM_CMPDAT4_CMP_Pos              (0)                                               /*!< EPWM_T::CMPDAT4: CMP Position           */
#define EPWM_CMPDAT4_CMP_Msk              (0xfffful << EPWM_CMPDAT4_CMP_Pos)                 /*!< EPWM_T::CMPDAT4: CMP Mask               */

#define EPWM_CMPDAT5_CMP_Pos              (0)                                               /*!< EPWM_T::CMPDAT5: CMP Position           */
#define EPWM_CMPDAT5_CMP_Msk              (0xfffful << EPWM_CMPDAT5_CMP_Pos)                 /*!< EPWM_T::CMPDAT5: CMP Mask               */

#define EPWM_DTCTL0_1_DTCNT_Pos           (0)                                               /*!< EPWM_T::DTCTL0_1: DTCNT Position        */
#define EPWM_DTCTL0_1_DTCNT_Msk           (0xffful << EPWM_DTCTL0_1_DTCNT_Pos)               /*!< EPWM_T::DTCTL0_1: DTCNT Mask            */

#define EPWM_DTCTL0_1_DTEN_Pos            (16)                                              /*!< EPWM_T::DTCTL0_1: DTEN Position         */
#define EPWM_DTCTL0_1_DTEN_Msk            (0x1ul << EPWM_DTCTL0_1_DTEN_Pos)                  /*!< EPWM_T::DTCTL0_1: DTEN Mask             */

#define EPWM_DTCTL0_1_DTCKSEL_Pos         (24)                                              /*!< EPWM_T::DTCTL0_1: DTCKSEL Position      */
#define EPWM_DTCTL0_1_DTCKSEL_Msk         (0x1ul << EPWM_DTCTL0_1_DTCKSEL_Pos)               /*!< EPWM_T::DTCTL0_1: DTCKSEL Mask          */

#define EPWM_DTCTL2_3_DTCNT_Pos           (0)                                               /*!< EPWM_T::DTCTL2_3: DTCNT Position        */
#define EPWM_DTCTL2_3_DTCNT_Msk           (0xffful << EPWM_DTCTL2_3_DTCNT_Pos)               /*!< EPWM_T::DTCTL2_3: DTCNT Mask            */

#define EPWM_DTCTL2_3_DTEN_Pos            (16)                                              /*!< EPWM_T::DTCTL2_3: DTEN Position         */
#define EPWM_DTCTL2_3_DTEN_Msk            (0x1ul << EPWM_DTCTL2_3_DTEN_Pos)                  /*!< EPWM_T::DTCTL2_3: DTEN Mask             */

#define EPWM_DTCTL2_3_DTCKSEL_Pos         (24)                                              /*!< EPWM_T::DTCTL2_3: DTCKSEL Position      */
#define EPWM_DTCTL2_3_DTCKSEL_Msk         (0x1ul << EPWM_DTCTL2_3_DTCKSEL_Pos)               /*!< EPWM_T::DTCTL2_3: DTCKSEL Mask          */

#define EPWM_DTCTL4_5_DTCNT_Pos           (0)                                               /*!< EPWM_T::DTCTL4_5: DTCNT Position        */
#define EPWM_DTCTL4_5_DTCNT_Msk           (0xffful << EPWM_DTCTL4_5_DTCNT_Pos)               /*!< EPWM_T::DTCTL4_5: DTCNT Mask            */

#define EPWM_DTCTL4_5_DTEN_Pos            (16)                                              /*!< EPWM_T::DTCTL4_5: DTEN Position         */
#define EPWM_DTCTL4_5_DTEN_Msk            (0x1ul << EPWM_DTCTL4_5_DTEN_Pos)                  /*!< EPWM_T::DTCTL4_5: DTEN Mask             */

#define EPWM_DTCTL4_5_DTCKSEL_Pos         (24)                                              /*!< EPWM_T::DTCTL4_5: DTCKSEL Position      */
#define EPWM_DTCTL4_5_DTCKSEL_Msk         (0x1ul << EPWM_DTCTL4_5_DTCKSEL_Pos)               /*!< EPWM_T::DTCTL4_5: DTCKSEL Mask          */

#define EPWM_PHS0_1_PHS_Pos               (0)                                               /*!< EPWM_T::PHS0_1: PHS Position            */
#define EPWM_PHS0_1_PHS_Msk               (0xfffful << EPWM_PHS0_1_PHS_Pos)                  /*!< EPWM_T::PHS0_1: PHS Mask                */

#define EPWM_PHS2_3_PHS_Pos               (0)                                               /*!< EPWM_T::PHS2_3: PHS Position            */
#define EPWM_PHS2_3_PHS_Msk               (0xfffful << EPWM_PHS2_3_PHS_Pos)                  /*!< EPWM_T::PHS2_3: PHS Mask                */

#define EPWM_PHS4_5_PHS_Pos               (0)                                               /*!< EPWM_T::PHS4_5: PHS Position            */
#define EPWM_PHS4_5_PHS_Msk               (0xfffful << EPWM_PHS4_5_PHS_Pos)                  /*!< EPWM_T::PHS4_5: PHS Mask                */

#define EPWM_CNT0_CNT_Pos                 (0)                                               /*!< EPWM_T::CNT0: CNT Position              */
#define EPWM_CNT0_CNT_Msk                 (0xfffful << EPWM_CNT0_CNT_Pos)                    /*!< EPWM_T::CNT0: CNT Mask                  */

#define EPWM_CNT0_DIRF_Pos                (16)                                              /*!< EPWM_T::CNT0: DIRF Position             */
#define EPWM_CNT0_DIRF_Msk                (0x1ul << EPWM_CNT0_DIRF_Pos)                      /*!< EPWM_T::CNT0: DIRF Mask                 */

#define EPWM_CNT1_CNT_Pos                 (0)                                               /*!< EPWM_T::CNT1: CNT Position              */
#define EPWM_CNT1_CNT_Msk                 (0xfffful << EPWM_CNT1_CNT_Pos)                    /*!< EPWM_T::CNT1: CNT Mask                  */

#define EPWM_CNT1_DIRF_Pos                (16)                                              /*!< EPWM_T::CNT1: DIRF Position             */
#define EPWM_CNT1_DIRF_Msk                (0x1ul << EPWM_CNT1_DIRF_Pos)                      /*!< EPWM_T::CNT1: DIRF Mask                 */

#define EPWM_CNT2_CNT_Pos                 (0)                                               /*!< EPWM_T::CNT2: CNT Position              */
#define EPWM_CNT2_CNT_Msk                 (0xfffful << EPWM_CNT2_CNT_Pos)                    /*!< EPWM_T::CNT2: CNT Mask                  */

#define EPWM_CNT2_DIRF_Pos                (16)                                              /*!< EPWM_T::CNT2: DIRF Position             */
#define EPWM_CNT2_DIRF_Msk                (0x1ul << EPWM_CNT2_DIRF_Pos)                      /*!< EPWM_T::CNT2: DIRF Mask                 */

#define EPWM_CNT3_CNT_Pos                 (0)                                               /*!< EPWM_T::CNT3: CNT Position              */
#define EPWM_CNT3_CNT_Msk                 (0xfffful << EPWM_CNT3_CNT_Pos)                    /*!< EPWM_T::CNT3: CNT Mask                  */

#define EPWM_CNT3_DIRF_Pos                (16)                                              /*!< EPWM_T::CNT3: DIRF Position             */
#define EPWM_CNT3_DIRF_Msk                (0x1ul << EPWM_CNT3_DIRF_Pos)                      /*!< EPWM_T::CNT3: DIRF Mask                 */

#define EPWM_CNT4_CNT_Pos                 (0)                                               /*!< EPWM_T::CNT4: CNT Position              */
#define EPWM_CNT4_CNT_Msk                 (0xfffful << EPWM_CNT4_CNT_Pos)                    /*!< EPWM_T::CNT4: CNT Mask                  */

#define EPWM_CNT4_DIRF_Pos                (16)                                              /*!< EPWM_T::CNT4: DIRF Position             */
#define EPWM_CNT4_DIRF_Msk                (0x1ul << EPWM_CNT4_DIRF_Pos)                      /*!< EPWM_T::CNT4: DIRF Mask                 */

#define EPWM_CNT5_CNT_Pos                 (0)                                               /*!< EPWM_T::CNT5: CNT Position              */
#define EPWM_CNT5_CNT_Msk                 (0xfffful << EPWM_CNT5_CNT_Pos)                    /*!< EPWM_T::CNT5: CNT Mask                  */

#define EPWM_CNT5_DIRF_Pos                (16)                                              /*!< EPWM_T::CNT5: DIRF Position             */
#define EPWM_CNT5_DIRF_Msk                (0x1ul << EPWM_CNT5_DIRF_Pos)                      /*!< EPWM_T::CNT5: DIRF Mask                 */

#define EPWM_WGCTL0_ZPCTL0_Pos            (0)                                               /*!< EPWM_T::WGCTL0: ZPCTL0 Position         */
#define EPWM_WGCTL0_ZPCTL0_Msk            (0x3ul << EPWM_WGCTL0_ZPCTL0_Pos)                  /*!< EPWM_T::WGCTL0: ZPCTL0 Mask             */

#define EPWM_WGCTL0_ZPCTL1_Pos            (2)                                               /*!< EPWM_T::WGCTL0: ZPCTL1 Position         */
#define EPWM_WGCTL0_ZPCTL1_Msk            (0x3ul << EPWM_WGCTL0_ZPCTL1_Pos)                  /*!< EPWM_T::WGCTL0: ZPCTL1 Mask             */

#define EPWM_WGCTL0_ZPCTL2_Pos            (4)                                               /*!< EPWM_T::WGCTL0: ZPCTL2 Position         */
#define EPWM_WGCTL0_ZPCTL2_Msk            (0x3ul << EPWM_WGCTL0_ZPCTL2_Pos)                  /*!< EPWM_T::WGCTL0: ZPCTL2 Mask             */

#define EPWM_WGCTL0_ZPCTL3_Pos            (6)                                               /*!< EPWM_T::WGCTL0: ZPCTL3 Position         */
#define EPWM_WGCTL0_ZPCTL3_Msk            (0x3ul << EPWM_WGCTL0_ZPCTL3_Pos)                  /*!< EPWM_T::WGCTL0: ZPCTL3 Mask             */

#define EPWM_WGCTL0_ZPCTL4_Pos            (8)                                               /*!< EPWM_T::WGCTL0: ZPCTL4 Position         */
#define EPWM_WGCTL0_ZPCTL4_Msk            (0x3ul << EPWM_WGCTL0_ZPCTL4_Pos)                  /*!< EPWM_T::WGCTL0: ZPCTL4 Mask             */

#define EPWM_WGCTL0_ZPCTL5_Pos            (10)                                              /*!< EPWM_T::WGCTL0: ZPCTL5 Position         */
#define EPWM_WGCTL0_ZPCTL5_Msk            (0x3ul << EPWM_WGCTL0_ZPCTL5_Pos)                  /*!< EPWM_T::WGCTL0: ZPCTL5 Mask             */

#define EPWM_WGCTL0_PRDPCTL0_Pos          (16)                                              /*!< EPWM_T::WGCTL0: PRDPCTL0 Position       */
#define EPWM_WGCTL0_PRDPCTL0_Msk          (0x3ul << EPWM_WGCTL0_PRDPCTL0_Pos)                /*!< EPWM_T::WGCTL0: PRDPCTL0 Mask           */

#define EPWM_WGCTL0_PRDPCTL1_Pos          (18)                                              /*!< EPWM_T::WGCTL0: PRDPCTL1 Position       */
#define EPWM_WGCTL0_PRDPCTL1_Msk          (0x3ul << EPWM_WGCTL0_PRDPCTL1_Pos)                /*!< EPWM_T::WGCTL0: PRDPCTL1 Mask           */

#define EPWM_WGCTL0_PRDPCTL2_Pos          (20)                                              /*!< EPWM_T::WGCTL0: PRDPCTL2 Position       */
#define EPWM_WGCTL0_PRDPCTL2_Msk          (0x3ul << EPWM_WGCTL0_PRDPCTL2_Pos)                /*!< EPWM_T::WGCTL0: PRDPCTL2 Mask           */

#define EPWM_WGCTL0_PRDPCTL3_Pos          (22)                                              /*!< EPWM_T::WGCTL0: PRDPCTL3 Position       */
#define EPWM_WGCTL0_PRDPCTL3_Msk          (0x3ul << EPWM_WGCTL0_PRDPCTL3_Pos)                /*!< EPWM_T::WGCTL0: PRDPCTL3 Mask           */

#define EPWM_WGCTL0_PRDPCTL4_Pos          (24)                                              /*!< EPWM_T::WGCTL0: PRDPCTL4 Position       */
#define EPWM_WGCTL0_PRDPCTL4_Msk          (0x3ul << EPWM_WGCTL0_PRDPCTL4_Pos)                /*!< EPWM_T::WGCTL0: PRDPCTL4 Mask           */

#define EPWM_WGCTL0_PRDPCTL5_Pos          (26)                                              /*!< EPWM_T::WGCTL0: PRDPCTL5 Position       */
#define EPWM_WGCTL0_PRDPCTL5_Msk          (0x3ul << EPWM_WGCTL0_PRDPCTL5_Pos)                /*!< EPWM_T::WGCTL0: PRDPCTL5 Mask           */

#define EPWM_WGCTL1_CMPUCTL0_Pos          (0)                                               /*!< EPWM_T::WGCTL1: CMPUCTL0 Position       */
#define EPWM_WGCTL1_CMPUCTL0_Msk          (0x3ul << EPWM_WGCTL1_CMPUCTL0_Pos)                /*!< EPWM_T::WGCTL1: CMPUCTL0 Mask           */

#define EPWM_WGCTL1_CMPUCTL1_Pos          (2)                                               /*!< EPWM_T::WGCTL1: CMPUCTL1 Position       */
#define EPWM_WGCTL1_CMPUCTL1_Msk          (0x3ul << EPWM_WGCTL1_CMPUCTL1_Pos)                /*!< EPWM_T::WGCTL1: CMPUCTL1 Mask           */

#define EPWM_WGCTL1_CMPUCTL2_Pos          (4)                                               /*!< EPWM_T::WGCTL1: CMPUCTL2 Position       */
#define EPWM_WGCTL1_CMPUCTL2_Msk          (0x3ul << EPWM_WGCTL1_CMPUCTL2_Pos)                /*!< EPWM_T::WGCTL1: CMPUCTL2 Mask           */

#define EPWM_WGCTL1_CMPUCTL3_Pos          (6)                                               /*!< EPWM_T::WGCTL1: CMPUCTL3 Position       */
#define EPWM_WGCTL1_CMPUCTL3_Msk          (0x3ul << EPWM_WGCTL1_CMPUCTL3_Pos)                /*!< EPWM_T::WGCTL1: CMPUCTL3 Mask           */

#define EPWM_WGCTL1_CMPUCTL4_Pos          (8)                                               /*!< EPWM_T::WGCTL1: CMPUCTL4 Position       */
#define EPWM_WGCTL1_CMPUCTL4_Msk          (0x3ul << EPWM_WGCTL1_CMPUCTL4_Pos)                /*!< EPWM_T::WGCTL1: CMPUCTL4 Mask           */

#define EPWM_WGCTL1_CMPUCTL5_Pos          (10)                                              /*!< EPWM_T::WGCTL1: CMPUCTL5 Position       */
#define EPWM_WGCTL1_CMPUCTL5_Msk          (0x3ul << EPWM_WGCTL1_CMPUCTL5_Pos)                /*!< EPWM_T::WGCTL1: CMPUCTL5 Mask           */

#define EPWM_WGCTL1_CMPDCTL0_Pos          (16)                                              /*!< EPWM_T::WGCTL1: CMPDCTL0 Position       */
#define EPWM_WGCTL1_CMPDCTL0_Msk          (0x3ul << EPWM_WGCTL1_CMPDCTL0_Pos)                /*!< EPWM_T::WGCTL1: CMPDCTL0 Mask           */

#define EPWM_WGCTL1_CMPDCTL1_Pos          (18)                                              /*!< EPWM_T::WGCTL1: CMPDCTL1 Position       */
#define EPWM_WGCTL1_CMPDCTL1_Msk          (0x3ul << EPWM_WGCTL1_CMPDCTL1_Pos)                /*!< EPWM_T::WGCTL1: CMPDCTL1 Mask           */

#define EPWM_WGCTL1_CMPDCTL2_Pos          (20)                                              /*!< EPWM_T::WGCTL1: CMPDCTL2 Position       */
#define EPWM_WGCTL1_CMPDCTL2_Msk          (0x3ul << EPWM_WGCTL1_CMPDCTL2_Pos)                /*!< EPWM_T::WGCTL1: CMPDCTL2 Mask           */

#define EPWM_WGCTL1_CMPDCTL3_Pos          (22)                                              /*!< EPWM_T::WGCTL1: CMPDCTL3 Position       */
#define EPWM_WGCTL1_CMPDCTL3_Msk          (0x3ul << EPWM_WGCTL1_CMPDCTL3_Pos)                /*!< EPWM_T::WGCTL1: CMPDCTL3 Mask           */

#define EPWM_WGCTL1_CMPDCTL4_Pos          (24)                                              /*!< EPWM_T::WGCTL1: CMPDCTL4 Position       */
#define EPWM_WGCTL1_CMPDCTL4_Msk          (0x3ul << EPWM_WGCTL1_CMPDCTL4_Pos)                /*!< EPWM_T::WGCTL1: CMPDCTL4 Mask           */

#define EPWM_WGCTL1_CMPDCTL5_Pos          (26)                                              /*!< EPWM_T::WGCTL1: CMPDCTL5 Position       */
#define EPWM_WGCTL1_CMPDCTL5_Msk          (0x3ul << EPWM_WGCTL1_CMPDCTL5_Pos)                /*!< EPWM_T::WGCTL1: CMPDCTL5 Mask           */

#define EPWM_MSKEN_MSKEN0_Pos             (0)                                               /*!< EPWM_T::MSKEN: MSKEN0 Position          */
#define EPWM_MSKEN_MSKEN0_Msk             (0x1ul << EPWM_MSKEN_MSKEN0_Pos)                   /*!< EPWM_T::MSKEN: MSKEN0 Mask              */

#define EPWM_MSKEN_MSKEN1_Pos             (1)                                               /*!< EPWM_T::MSKEN: MSKEN1 Position          */
#define EPWM_MSKEN_MSKEN1_Msk             (0x1ul << EPWM_MSKEN_MSKEN1_Pos)                   /*!< EPWM_T::MSKEN: MSKEN1 Mask              */

#define EPWM_MSKEN_MSKEN2_Pos             (2)                                               /*!< EPWM_T::MSKEN: MSKEN2 Position          */
#define EPWM_MSKEN_MSKEN2_Msk             (0x1ul << EPWM_MSKEN_MSKEN2_Pos)                   /*!< EPWM_T::MSKEN: MSKEN2 Mask              */

#define EPWM_MSKEN_MSKEN3_Pos             (3)                                               /*!< EPWM_T::MSKEN: MSKEN3 Position          */
#define EPWM_MSKEN_MSKEN3_Msk             (0x1ul << EPWM_MSKEN_MSKEN3_Pos)                   /*!< EPWM_T::MSKEN: MSKEN3 Mask              */

#define EPWM_MSKEN_MSKEN4_Pos             (4)                                               /*!< EPWM_T::MSKEN: MSKEN4 Position          */
#define EPWM_MSKEN_MSKEN4_Msk             (0x1ul << EPWM_MSKEN_MSKEN4_Pos)                   /*!< EPWM_T::MSKEN: MSKEN4 Mask              */

#define EPWM_MSKEN_MSKEN5_Pos             (5)                                               /*!< EPWM_T::MSKEN: MSKEN5 Position          */
#define EPWM_MSKEN_MSKEN5_Msk             (0x1ul << EPWM_MSKEN_MSKEN5_Pos)                   /*!< EPWM_T::MSKEN: MSKEN5 Mask              */

#define EPWM_MSK_MSKDAT0_Pos              (0)                                               /*!< EPWM_T::MSK: MSKDAT0 Position           */
#define EPWM_MSK_MSKDAT0_Msk              (0x1ul << EPWM_MSK_MSKDAT0_Pos)                    /*!< EPWM_T::MSK: MSKDAT0 Mask               */

#define EPWM_MSK_MSKDAT1_Pos              (1)                                               /*!< EPWM_T::MSK: MSKDAT1 Position           */
#define EPWM_MSK_MSKDAT1_Msk              (0x1ul << EPWM_MSK_MSKDAT1_Pos)                    /*!< EPWM_T::MSK: MSKDAT1 Mask               */

#define EPWM_MSK_MSKDAT2_Pos              (2)                                               /*!< EPWM_T::MSK: MSKDAT2 Position           */
#define EPWM_MSK_MSKDAT2_Msk              (0x1ul << EPWM_MSK_MSKDAT2_Pos)                    /*!< EPWM_T::MSK: MSKDAT2 Mask               */

#define EPWM_MSK_MSKDAT3_Pos              (3)                                               /*!< EPWM_T::MSK: MSKDAT3 Position           */
#define EPWM_MSK_MSKDAT3_Msk              (0x1ul << EPWM_MSK_MSKDAT3_Pos)                    /*!< EPWM_T::MSK: MSKDAT3 Mask               */

#define EPWM_MSK_MSKDAT4_Pos              (4)                                               /*!< EPWM_T::MSK: MSKDAT4 Position           */
#define EPWM_MSK_MSKDAT4_Msk              (0x1ul << EPWM_MSK_MSKDAT4_Pos)                    /*!< EPWM_T::MSK: MSKDAT4 Mask               */

#define EPWM_MSK_MSKDAT5_Pos              (5)                                               /*!< EPWM_T::MSK: MSKDAT5 Position           */
#define EPWM_MSK_MSKDAT5_Msk              (0x1ul << EPWM_MSK_MSKDAT5_Pos)                    /*!< EPWM_T::MSK: MSKDAT5 Mask               */

#define EPWM_BNF_BRK0NFEN_Pos             (0)                                               /*!< EPWM_T::BNF: BRK0NFEN Position          */
#define EPWM_BNF_BRK0NFEN_Msk             (0x1ul << EPWM_BNF_BRK0NFEN_Pos)                   /*!< EPWM_T::BNF: BRK0NFEN Mask              */

#define EPWM_BNF_BRK0NFSEL_Pos            (1)                                               /*!< EPWM_T::BNF: BRK0NFSEL Position         */
#define EPWM_BNF_BRK0NFSEL_Msk            (0x7ul << EPWM_BNF_BRK0NFSEL_Pos)                  /*!< EPWM_T::BNF: BRK0NFSEL Mask             */

#define EPWM_BNF_BRK0FCNT_Pos             (4)                                               /*!< EPWM_T::BNF: BRK0FCNT Position          */
#define EPWM_BNF_BRK0FCNT_Msk             (0x7ul << EPWM_BNF_BRK0FCNT_Pos)                   /*!< EPWM_T::BNF: BRK0FCNT Mask              */

#define EPWM_BNF_BRK0PINV_Pos             (7)                                               /*!< EPWM_T::BNF: BRK0PINV Position          */
#define EPWM_BNF_BRK0PINV_Msk             (0x1ul << EPWM_BNF_BRK0PINV_Pos)                   /*!< EPWM_T::BNF: BRK0PINV Mask              */

#define EPWM_BNF_BRK1NFEN_Pos             (8)                                               /*!< EPWM_T::BNF: BRK1NFEN Position          */
#define EPWM_BNF_BRK1NFEN_Msk             (0x1ul << EPWM_BNF_BRK1NFEN_Pos)                   /*!< EPWM_T::BNF: BRK1NFEN Mask              */

#define EPWM_BNF_BRK1NFSEL_Pos            (9)                                               /*!< EPWM_T::BNF: BRK1NFSEL Position         */
#define EPWM_BNF_BRK1NFSEL_Msk            (0x7ul << EPWM_BNF_BRK1NFSEL_Pos)                  /*!< EPWM_T::BNF: BRK1NFSEL Mask             */

#define EPWM_BNF_BRK1FCNT_Pos             (12)                                              /*!< EPWM_T::BNF: BRK1FCNT Position          */
#define EPWM_BNF_BRK1FCNT_Msk             (0x7ul << EPWM_BNF_BRK1FCNT_Pos)                   /*!< EPWM_T::BNF: BRK1FCNT Mask              */

#define EPWM_BNF_BRK1PINV_Pos             (15)                                              /*!< EPWM_T::BNF: BRK1PINV Position          */
#define EPWM_BNF_BRK1PINV_Msk             (0x1ul << EPWM_BNF_BRK1PINV_Pos)                   /*!< EPWM_T::BNF: BRK1PINV Mask              */

#define EPWM_BNF_BK0SRC_Pos               (16)                                              /*!< EPWM_T::BNF: BK0SRC Position            */
#define EPWM_BNF_BK0SRC_Msk               (0x1ul << EPWM_BNF_BK0SRC_Pos)                     /*!< EPWM_T::BNF: BK0SRC Mask                */

#define EPWM_BNF_BK1SRC_Pos               (24)                                              /*!< EPWM_T::BNF: BK1SRC Position            */
#define EPWM_BNF_BK1SRC_Msk               (0x1ul << EPWM_BNF_BK1SRC_Pos)                     /*!< EPWM_T::BNF: BK1SRC Mask                */

#define EPWM_FAILBRK_CSSBRKEN_Pos         (0)                                               /*!< EPWM_T::FAILBRK: CSSBRKEN Position      */
#define EPWM_FAILBRK_CSSBRKEN_Msk         (0x1ul << EPWM_FAILBRK_CSSBRKEN_Pos)               /*!< EPWM_T::FAILBRK: CSSBRKEN Mask          */

#define EPWM_FAILBRK_BODBRKEN_Pos         (1)                                               /*!< EPWM_T::FAILBRK: BODBRKEN Position      */
#define EPWM_FAILBRK_BODBRKEN_Msk         (0x1ul << EPWM_FAILBRK_BODBRKEN_Pos)               /*!< EPWM_T::FAILBRK: BODBRKEN Mask          */

#define EPWM_FAILBRK_RAMBRKEN_Pos         (2)                                               /*!< EPWM_T::FAILBRK: RAMBRKEN Position      */
#define EPWM_FAILBRK_RAMBRKEN_Msk         (0x1ul << EPWM_FAILBRK_RAMBRKEN_Pos)               /*!< EPWM_T::FAILBRK: RAMBRKEN Mask          */

#define EPWM_FAILBRK_CORBRKEN_Pos         (3)                                               /*!< EPWM_T::FAILBRK: CORBRKEN Position      */
#define EPWM_FAILBRK_CORBRKEN_Msk         (0x1ul << EPWM_FAILBRK_CORBRKEN_Pos)               /*!< EPWM_T::FAILBRK: CORBRKEN Mask          */

#define EPWM_BRKCTL0_1_CPO0EBEN_Pos       (0)                                               /*!< EPWM_T::BRKCTL0_1: CPO0EBEN Position    */
#define EPWM_BRKCTL0_1_CPO0EBEN_Msk       (0x1ul << EPWM_BRKCTL0_1_CPO0EBEN_Pos)             /*!< EPWM_T::BRKCTL0_1: CPO0EBEN Mask        */

#define EPWM_BRKCTL0_1_CPO1EBEN_Pos       (1)                                               /*!< EPWM_T::BRKCTL0_1: CPO1EBEN Position    */
#define EPWM_BRKCTL0_1_CPO1EBEN_Msk       (0x1ul << EPWM_BRKCTL0_1_CPO1EBEN_Pos)             /*!< EPWM_T::BRKCTL0_1: CPO1EBEN Mask        */

#define EPWM_BRKCTL0_1_BRKP0EEN_Pos       (4)                                               /*!< EPWM_T::BRKCTL0_1: BRKP0EEN Position    */
#define EPWM_BRKCTL0_1_BRKP0EEN_Msk       (0x1ul << EPWM_BRKCTL0_1_BRKP0EEN_Pos)             /*!< EPWM_T::BRKCTL0_1: BRKP0EEN Mask        */

#define EPWM_BRKCTL0_1_BRKP1EEN_Pos       (5)                                               /*!< EPWM_T::BRKCTL0_1: BRKP1EEN Position    */
#define EPWM_BRKCTL0_1_BRKP1EEN_Msk       (0x1ul << EPWM_BRKCTL0_1_BRKP1EEN_Pos)             /*!< EPWM_T::BRKCTL0_1: BRKP1EEN Mask        */

#define EPWM_BRKCTL0_1_SYSEBEN_Pos        (7)                                               /*!< EPWM_T::BRKCTL0_1: SYSEBEN Position     */
#define EPWM_BRKCTL0_1_SYSEBEN_Msk        (0x1ul << EPWM_BRKCTL0_1_SYSEBEN_Pos)              /*!< EPWM_T::BRKCTL0_1: SYSEBEN Mask         */

#define EPWM_BRKCTL0_1_CPO0LBEN_Pos       (8)                                               /*!< EPWM_T::BRKCTL0_1: CPO0LBEN Position    */
#define EPWM_BRKCTL0_1_CPO0LBEN_Msk       (0x1ul << EPWM_BRKCTL0_1_CPO0LBEN_Pos)             /*!< EPWM_T::BRKCTL0_1: CPO0LBEN Mask        */

#define EPWM_BRKCTL0_1_CPO1LBEN_Pos       (9)                                               /*!< EPWM_T::BRKCTL0_1: CPO1LBEN Position    */
#define EPWM_BRKCTL0_1_CPO1LBEN_Msk       (0x1ul << EPWM_BRKCTL0_1_CPO1LBEN_Pos)             /*!< EPWM_T::BRKCTL0_1: CPO1LBEN Mask        */

#define EPWM_BRKCTL0_1_BRKP0LEN_Pos       (12)                                              /*!< EPWM_T::BRKCTL0_1: BRKP0LEN Position    */
#define EPWM_BRKCTL0_1_BRKP0LEN_Msk       (0x1ul << EPWM_BRKCTL0_1_BRKP0LEN_Pos)             /*!< EPWM_T::BRKCTL0_1: BRKP0LEN Mask        */

#define EPWM_BRKCTL0_1_BRKP1LEN_Pos       (13)                                              /*!< EPWM_T::BRKCTL0_1: BRKP1LEN Position    */
#define EPWM_BRKCTL0_1_BRKP1LEN_Msk       (0x1ul << EPWM_BRKCTL0_1_BRKP1LEN_Pos)             /*!< EPWM_T::BRKCTL0_1: BRKP1LEN Mask        */

#define EPWM_BRKCTL0_1_SYSLBEN_Pos        (15)                                              /*!< EPWM_T::BRKCTL0_1: SYSLBEN Position     */
#define EPWM_BRKCTL0_1_SYSLBEN_Msk        (0x1ul << EPWM_BRKCTL0_1_SYSLBEN_Pos)              /*!< EPWM_T::BRKCTL0_1: SYSLBEN Mask         */

#define EPWM_BRKCTL0_1_BRKAEVEN_Pos       (16)                                              /*!< EPWM_T::BRKCTL0_1: BRKAEVEN Position    */
#define EPWM_BRKCTL0_1_BRKAEVEN_Msk       (0x3ul << EPWM_BRKCTL0_1_BRKAEVEN_Pos)             /*!< EPWM_T::BRKCTL0_1: BRKAEVEN Mask        */

#define EPWM_BRKCTL0_1_BRKAODD_Pos        (18)                                              /*!< EPWM_T::BRKCTL0_1: BRKAODD Position     */
#define EPWM_BRKCTL0_1_BRKAODD_Msk        (0x3ul << EPWM_BRKCTL0_1_BRKAODD_Pos)              /*!< EPWM_T::BRKCTL0_1: BRKAODD Mask         */

#define EPWM_BRKCTL0_1_EADCEBEN_Pos       (20)                                              /*!< EPWM_T::BRKCTL0_1: EADCEBEN Position    */
#define EPWM_BRKCTL0_1_EADCEBEN_Msk       (0x1ul << EPWM_BRKCTL0_1_EADCEBEN_Pos)             /*!< EPWM_T::BRKCTL0_1: EADCEBEN Mask        */

#define EPWM_BRKCTL0_1_EADCLBEN_Pos       (28)                                              /*!< EPWM_T::BRKCTL0_1: EADCLBEN Position    */
#define EPWM_BRKCTL0_1_EADCLBEN_Msk       (0x1ul << EPWM_BRKCTL0_1_EADCLBEN_Pos)             /*!< EPWM_T::BRKCTL0_1: EADCLBEN Mask        */

#define EPWM_BRKCTL2_3_CPO0EBEN_Pos       (0)                                               /*!< EPWM_T::BRKCTL2_3: CPO0EBEN Position    */
#define EPWM_BRKCTL2_3_CPO0EBEN_Msk       (0x1ul << EPWM_BRKCTL2_3_CPO0EBEN_Pos)             /*!< EPWM_T::BRKCTL2_3: CPO0EBEN Mask        */

#define EPWM_BRKCTL2_3_CPO1EBEN_Pos       (1)                                               /*!< EPWM_T::BRKCTL2_3: CPO1EBEN Position    */
#define EPWM_BRKCTL2_3_CPO1EBEN_Msk       (0x1ul << EPWM_BRKCTL2_3_CPO1EBEN_Pos)             /*!< EPWM_T::BRKCTL2_3: CPO1EBEN Mask        */

#define EPWM_BRKCTL2_3_BRKP0EEN_Pos       (4)                                               /*!< EPWM_T::BRKCTL2_3: BRKP0EEN Position    */
#define EPWM_BRKCTL2_3_BRKP0EEN_Msk       (0x1ul << EPWM_BRKCTL2_3_BRKP0EEN_Pos)             /*!< EPWM_T::BRKCTL2_3: BRKP0EEN Mask        */

#define EPWM_BRKCTL2_3_BRKP1EEN_Pos       (5)                                               /*!< EPWM_T::BRKCTL2_3: BRKP1EEN Position    */
#define EPWM_BRKCTL2_3_BRKP1EEN_Msk       (0x1ul << EPWM_BRKCTL2_3_BRKP1EEN_Pos)             /*!< EPWM_T::BRKCTL2_3: BRKP1EEN Mask        */

#define EPWM_BRKCTL2_3_SYSEBEN_Pos        (7)                                               /*!< EPWM_T::BRKCTL2_3: SYSEBEN Position     */
#define EPWM_BRKCTL2_3_SYSEBEN_Msk        (0x1ul << EPWM_BRKCTL2_3_SYSEBEN_Pos)              /*!< EPWM_T::BRKCTL2_3: SYSEBEN Mask         */

#define EPWM_BRKCTL2_3_CPO0LBEN_Pos       (8)                                               /*!< EPWM_T::BRKCTL2_3: CPO0LBEN Position    */
#define EPWM_BRKCTL2_3_CPO0LBEN_Msk       (0x1ul << EPWM_BRKCTL2_3_CPO0LBEN_Pos)             /*!< EPWM_T::BRKCTL2_3: CPO0LBEN Mask        */

#define EPWM_BRKCTL2_3_CPO1LBEN_Pos       (9)                                               /*!< EPWM_T::BRKCTL2_3: CPO1LBEN Position    */
#define EPWM_BRKCTL2_3_CPO1LBEN_Msk       (0x1ul << EPWM_BRKCTL2_3_CPO1LBEN_Pos)             /*!< EPWM_T::BRKCTL2_3: CPO1LBEN Mask        */

#define EPWM_BRKCTL2_3_BRKP0LEN_Pos       (12)                                              /*!< EPWM_T::BRKCTL2_3: BRKP0LEN Position    */
#define EPWM_BRKCTL2_3_BRKP0LEN_Msk       (0x1ul << EPWM_BRKCTL2_3_BRKP0LEN_Pos)             /*!< EPWM_T::BRKCTL2_3: BRKP0LEN Mask        */

#define EPWM_BRKCTL2_3_BRKP1LEN_Pos       (13)                                              /*!< EPWM_T::BRKCTL2_3: BRKP1LEN Position    */
#define EPWM_BRKCTL2_3_BRKP1LEN_Msk       (0x1ul << EPWM_BRKCTL2_3_BRKP1LEN_Pos)             /*!< EPWM_T::BRKCTL2_3: BRKP1LEN Mask        */

#define EPWM_BRKCTL2_3_SYSLBEN_Pos        (15)                                              /*!< EPWM_T::BRKCTL2_3: SYSLBEN Position     */
#define EPWM_BRKCTL2_3_SYSLBEN_Msk        (0x1ul << EPWM_BRKCTL2_3_SYSLBEN_Pos)              /*!< EPWM_T::BRKCTL2_3: SYSLBEN Mask         */

#define EPWM_BRKCTL2_3_BRKAEVEN_Pos       (16)                                              /*!< EPWM_T::BRKCTL2_3: BRKAEVEN Position    */
#define EPWM_BRKCTL2_3_BRKAEVEN_Msk       (0x3ul << EPWM_BRKCTL2_3_BRKAEVEN_Pos)             /*!< EPWM_T::BRKCTL2_3: BRKAEVEN Mask        */

#define EPWM_BRKCTL2_3_BRKAODD_Pos        (18)                                              /*!< EPWM_T::BRKCTL2_3: BRKAODD Position     */
#define EPWM_BRKCTL2_3_BRKAODD_Msk        (0x3ul << EPWM_BRKCTL2_3_BRKAODD_Pos)              /*!< EPWM_T::BRKCTL2_3: BRKAODD Mask         */

#define EPWM_BRKCTL2_3_EADCEBEN_Pos       (20)                                              /*!< EPWM_T::BRKCTL2_3: EADCEBEN Position    */
#define EPWM_BRKCTL2_3_EADCEBEN_Msk       (0x1ul << EPWM_BRKCTL2_3_EADCEBEN_Pos)             /*!< EPWM_T::BRKCTL2_3: EADCEBEN Mask        */

#define EPWM_BRKCTL2_3_EADCLBEN_Pos       (28)                                              /*!< EPWM_T::BRKCTL2_3: EADCLBEN Position    */
#define EPWM_BRKCTL2_3_EADCLBEN_Msk       (0x1ul << EPWM_BRKCTL2_3_EADCLBEN_Pos)             /*!< EPWM_T::BRKCTL2_3: EADCLBEN Mask        */

#define EPWM_BRKCTL4_5_CPO0EBEN_Pos       (0)                                               /*!< EPWM_T::BRKCTL4_5: CPO0EBEN Position    */
#define EPWM_BRKCTL4_5_CPO0EBEN_Msk       (0x1ul << EPWM_BRKCTL4_5_CPO0EBEN_Pos)             /*!< EPWM_T::BRKCTL4_5: CPO0EBEN Mask        */

#define EPWM_BRKCTL4_5_CPO1EBEN_Pos       (1)                                               /*!< EPWM_T::BRKCTL4_5: CPO1EBEN Position    */
#define EPWM_BRKCTL4_5_CPO1EBEN_Msk       (0x1ul << EPWM_BRKCTL4_5_CPO1EBEN_Pos)             /*!< EPWM_T::BRKCTL4_5: CPO1EBEN Mask        */

#define EPWM_BRKCTL4_5_BRKP0EEN_Pos       (4)                                               /*!< EPWM_T::BRKCTL4_5: BRKP0EEN Position    */
#define EPWM_BRKCTL4_5_BRKP0EEN_Msk       (0x1ul << EPWM_BRKCTL4_5_BRKP0EEN_Pos)             /*!< EPWM_T::BRKCTL4_5: BRKP0EEN Mask        */

#define EPWM_BRKCTL4_5_BRKP1EEN_Pos       (5)                                               /*!< EPWM_T::BRKCTL4_5: BRKP1EEN Position    */
#define EPWM_BRKCTL4_5_BRKP1EEN_Msk       (0x1ul << EPWM_BRKCTL4_5_BRKP1EEN_Pos)             /*!< EPWM_T::BRKCTL4_5: BRKP1EEN Mask        */

#define EPWM_BRKCTL4_5_SYSEBEN_Pos        (7)                                               /*!< EPWM_T::BRKCTL4_5: SYSEBEN Position     */
#define EPWM_BRKCTL4_5_SYSEBEN_Msk        (0x1ul << EPWM_BRKCTL4_5_SYSEBEN_Pos)              /*!< EPWM_T::BRKCTL4_5: SYSEBEN Mask         */

#define EPWM_BRKCTL4_5_CPO0LBEN_Pos       (8)                                               /*!< EPWM_T::BRKCTL4_5: CPO0LBEN Position    */
#define EPWM_BRKCTL4_5_CPO0LBEN_Msk       (0x1ul << EPWM_BRKCTL4_5_CPO0LBEN_Pos)             /*!< EPWM_T::BRKCTL4_5: CPO0LBEN Mask        */

#define EPWM_BRKCTL4_5_CPO1LBEN_Pos       (9)                                               /*!< EPWM_T::BRKCTL4_5: CPO1LBEN Position    */
#define EPWM_BRKCTL4_5_CPO1LBEN_Msk       (0x1ul << EPWM_BRKCTL4_5_CPO1LBEN_Pos)             /*!< EPWM_T::BRKCTL4_5: CPO1LBEN Mask        */

#define EPWM_BRKCTL4_5_BRKP0LEN_Pos       (12)                                              /*!< EPWM_T::BRKCTL4_5: BRKP0LEN Position    */
#define EPWM_BRKCTL4_5_BRKP0LEN_Msk       (0x1ul << EPWM_BRKCTL4_5_BRKP0LEN_Pos)             /*!< EPWM_T::BRKCTL4_5: BRKP0LEN Mask        */

#define EPWM_BRKCTL4_5_BRKP1LEN_Pos       (13)                                              /*!< EPWM_T::BRKCTL4_5: BRKP1LEN Position    */
#define EPWM_BRKCTL4_5_BRKP1LEN_Msk       (0x1ul << EPWM_BRKCTL4_5_BRKP1LEN_Pos)             /*!< EPWM_T::BRKCTL4_5: BRKP1LEN Mask        */

#define EPWM_BRKCTL4_5_SYSLBEN_Pos        (15)                                              /*!< EPWM_T::BRKCTL4_5: SYSLBEN Position     */
#define EPWM_BRKCTL4_5_SYSLBEN_Msk        (0x1ul << EPWM_BRKCTL4_5_SYSLBEN_Pos)              /*!< EPWM_T::BRKCTL4_5: SYSLBEN Mask         */

#define EPWM_BRKCTL4_5_BRKAEVEN_Pos       (16)                                              /*!< EPWM_T::BRKCTL4_5: BRKAEVEN Position    */
#define EPWM_BRKCTL4_5_BRKAEVEN_Msk       (0x3ul << EPWM_BRKCTL4_5_BRKAEVEN_Pos)             /*!< EPWM_T::BRKCTL4_5: BRKAEVEN Mask        */

#define EPWM_BRKCTL4_5_BRKAODD_Pos        (18)                                              /*!< EPWM_T::BRKCTL4_5: BRKAODD Position     */
#define EPWM_BRKCTL4_5_BRKAODD_Msk        (0x3ul << EPWM_BRKCTL4_5_BRKAODD_Pos)              /*!< EPWM_T::BRKCTL4_5: BRKAODD Mask         */

#define EPWM_BRKCTL4_5_EADCEBEN_Pos       (20)                                              /*!< EPWM_T::BRKCTL4_5: EADCEBEN Position    */
#define EPWM_BRKCTL4_5_EADCEBEN_Msk       (0x1ul << EPWM_BRKCTL4_5_EADCEBEN_Pos)             /*!< EPWM_T::BRKCTL4_5: EADCEBEN Mask        */

#define EPWM_BRKCTL4_5_EADCLBEN_Pos       (28)                                              /*!< EPWM_T::BRKCTL4_5: EADCLBEN Position    */
#define EPWM_BRKCTL4_5_EADCLBEN_Msk       (0x1ul << EPWM_BRKCTL4_5_EADCLBEN_Pos)             /*!< EPWM_T::BRKCTL4_5: EADCLBEN Mask        */

#define EPWM_POLCTL_PINV0_Pos             (0)                                               /*!< EPWM_T::POLCTL: PINV0 Position          */
#define EPWM_POLCTL_PINV0_Msk             (0x1ul << EPWM_POLCTL_PINV0_Pos)                   /*!< EPWM_T::POLCTL: PINV0 Mask              */

#define EPWM_POLCTL_PINV1_Pos             (1)                                               /*!< EPWM_T::POLCTL: PINV1 Position          */
#define EPWM_POLCTL_PINV1_Msk             (0x1ul << EPWM_POLCTL_PINV1_Pos)                   /*!< EPWM_T::POLCTL: PINV1 Mask              */

#define EPWM_POLCTL_PINV2_Pos             (2)                                               /*!< EPWM_T::POLCTL: PINV2 Position          */
#define EPWM_POLCTL_PINV2_Msk             (0x1ul << EPWM_POLCTL_PINV2_Pos)                   /*!< EPWM_T::POLCTL: PINV2 Mask              */

#define EPWM_POLCTL_PINV3_Pos             (3)                                               /*!< EPWM_T::POLCTL: PINV3 Position          */
#define EPWM_POLCTL_PINV3_Msk             (0x1ul << EPWM_POLCTL_PINV3_Pos)                   /*!< EPWM_T::POLCTL: PINV3 Mask              */

#define EPWM_POLCTL_PINV4_Pos             (4)                                               /*!< EPWM_T::POLCTL: PINV4 Position          */
#define EPWM_POLCTL_PINV4_Msk             (0x1ul << EPWM_POLCTL_PINV4_Pos)                   /*!< EPWM_T::POLCTL: PINV4 Mask              */

#define EPWM_POLCTL_PINV5_Pos             (5)                                               /*!< EPWM_T::POLCTL: PINV5 Position          */
#define EPWM_POLCTL_PINV5_Msk             (0x1ul << EPWM_POLCTL_PINV5_Pos)                   /*!< EPWM_T::POLCTL: PINV5 Mask              */

#define EPWM_POEN_POEN0_Pos               (0)                                               /*!< EPWM_T::POEN: POEN0 Position            */
#define EPWM_POEN_POEN0_Msk               (0x1ul << EPWM_POEN_POEN0_Pos)                     /*!< EPWM_T::POEN: POEN0 Mask                */

#define EPWM_POEN_POEN1_Pos               (1)                                               /*!< EPWM_T::POEN: POEN1 Position            */
#define EPWM_POEN_POEN1_Msk               (0x1ul << EPWM_POEN_POEN1_Pos)                     /*!< EPWM_T::POEN: POEN1 Mask                */

#define EPWM_POEN_POEN2_Pos               (2)                                               /*!< EPWM_T::POEN: POEN2 Position            */
#define EPWM_POEN_POEN2_Msk               (0x1ul << EPWM_POEN_POEN2_Pos)                     /*!< EPWM_T::POEN: POEN2 Mask                */

#define EPWM_POEN_POEN3_Pos               (3)                                               /*!< EPWM_T::POEN: POEN3 Position            */
#define EPWM_POEN_POEN3_Msk               (0x1ul << EPWM_POEN_POEN3_Pos)                     /*!< EPWM_T::POEN: POEN3 Mask                */

#define EPWM_POEN_POEN4_Pos               (4)                                               /*!< EPWM_T::POEN: POEN4 Position            */
#define EPWM_POEN_POEN4_Msk               (0x1ul << EPWM_POEN_POEN4_Pos)                     /*!< EPWM_T::POEN: POEN4 Mask                */

#define EPWM_POEN_POEN5_Pos               (5)                                               /*!< EPWM_T::POEN: POEN5 Position            */
#define EPWM_POEN_POEN5_Msk               (0x1ul << EPWM_POEN_POEN5_Pos)                     /*!< EPWM_T::POEN: POEN5 Mask                */

#define EPWM_SWBRK_BRKETRG0_Pos           (0)                                               /*!< EPWM_T::SWBRK: BRKETRG0 Position        */
#define EPWM_SWBRK_BRKETRG0_Msk           (0x1ul << EPWM_SWBRK_BRKETRG0_Pos)                 /*!< EPWM_T::SWBRK: BRKETRG0 Mask            */

#define EPWM_SWBRK_BRKETRG2_Pos           (1)                                               /*!< EPWM_T::SWBRK: BRKETRG2 Position        */
#define EPWM_SWBRK_BRKETRG2_Msk           (0x1ul << EPWM_SWBRK_BRKETRG2_Pos)                 /*!< EPWM_T::SWBRK: BRKETRG2 Mask            */

#define EPWM_SWBRK_BRKETRG4_Pos           (2)                                               /*!< EPWM_T::SWBRK: BRKETRG4 Position        */
#define EPWM_SWBRK_BRKETRG4_Msk           (0x1ul << EPWM_SWBRK_BRKETRG4_Pos)                 /*!< EPWM_T::SWBRK: BRKETRG4 Mask            */

#define EPWM_SWBRK_BRKLTRG0_Pos           (8)                                               /*!< EPWM_T::SWBRK: BRKLTRG0 Position        */
#define EPWM_SWBRK_BRKLTRG0_Msk           (0x1ul << EPWM_SWBRK_BRKLTRG0_Pos)                 /*!< EPWM_T::SWBRK: BRKLTRG0 Mask            */

#define EPWM_SWBRK_BRKLTRG2_Pos           (9)                                               /*!< EPWM_T::SWBRK: BRKLTRG2 Position        */
#define EPWM_SWBRK_BRKLTRG2_Msk           (0x1ul << EPWM_SWBRK_BRKLTRG2_Pos)                 /*!< EPWM_T::SWBRK: BRKLTRG2 Mask            */

#define EPWM_SWBRK_BRKLTRG4_Pos           (10)                                              /*!< EPWM_T::SWBRK: BRKLTRG4 Position        */
#define EPWM_SWBRK_BRKLTRG4_Msk           (0x1ul << EPWM_SWBRK_BRKLTRG4_Pos)                 /*!< EPWM_T::SWBRK: BRKLTRG4 Mask            */

#define EPWM_INTEN0_ZIEN0_Pos             (0)                                               /*!< EPWM_T::INTEN0: ZIEN0 Position          */
#define EPWM_INTEN0_ZIEN0_Msk             (0x1ul << EPWM_INTEN0_ZIEN0_Pos)                   /*!< EPWM_T::INTEN0: ZIEN0 Mask              */

#define EPWM_INTEN0_ZIEN1_Pos             (1)                                               /*!< EPWM_T::INTEN0: ZIEN1 Position          */
#define EPWM_INTEN0_ZIEN1_Msk             (0x1ul << EPWM_INTEN0_ZIEN1_Pos)                   /*!< EPWM_T::INTEN0: ZIEN1 Mask              */

#define EPWM_INTEN0_ZIEN2_Pos             (2)                                               /*!< EPWM_T::INTEN0: ZIEN2 Position          */
#define EPWM_INTEN0_ZIEN2_Msk             (0x1ul << EPWM_INTEN0_ZIEN2_Pos)                   /*!< EPWM_T::INTEN0: ZIEN2 Mask              */

#define EPWM_INTEN0_ZIEN3_Pos             (3)                                               /*!< EPWM_T::INTEN0: ZIEN3 Position          */
#define EPWM_INTEN0_ZIEN3_Msk             (0x1ul << EPWM_INTEN0_ZIEN3_Pos)                   /*!< EPWM_T::INTEN0: ZIEN3 Mask              */

#define EPWM_INTEN0_ZIEN4_Pos             (4)                                               /*!< EPWM_T::INTEN0: ZIEN4 Position          */
#define EPWM_INTEN0_ZIEN4_Msk             (0x1ul << EPWM_INTEN0_ZIEN4_Pos)                   /*!< EPWM_T::INTEN0: ZIEN4 Mask              */

#define EPWM_INTEN0_ZIEN5_Pos             (5)                                               /*!< EPWM_T::INTEN0: ZIEN5 Position          */
#define EPWM_INTEN0_ZIEN5_Msk             (0x1ul << EPWM_INTEN0_ZIEN5_Pos)                   /*!< EPWM_T::INTEN0: ZIEN5 Mask              */

#define EPWM_INTEN0_PIEN0_Pos             (8)                                               /*!< EPWM_T::INTEN0: PIEN0 Position          */
#define EPWM_INTEN0_PIEN0_Msk             (0x1ul << EPWM_INTEN0_PIEN0_Pos)                   /*!< EPWM_T::INTEN0: PIEN0 Mask              */

#define EPWM_INTEN0_PIEN1_Pos             (9)                                               /*!< EPWM_T::INTEN0: PIEN1 Position          */
#define EPWM_INTEN0_PIEN1_Msk             (0x1ul << EPWM_INTEN0_PIEN1_Pos)                   /*!< EPWM_T::INTEN0: PIEN1 Mask              */

#define EPWM_INTEN0_PIEN2_Pos             (10)                                              /*!< EPWM_T::INTEN0: PIEN2 Position          */
#define EPWM_INTEN0_PIEN2_Msk             (0x1ul << EPWM_INTEN0_PIEN2_Pos)                   /*!< EPWM_T::INTEN0: PIEN2 Mask              */

#define EPWM_INTEN0_PIEN3_Pos             (11)                                              /*!< EPWM_T::INTEN0: PIEN3 Position          */
#define EPWM_INTEN0_PIEN3_Msk             (0x1ul << EPWM_INTEN0_PIEN3_Pos)                   /*!< EPWM_T::INTEN0: PIEN3 Mask              */

#define EPWM_INTEN0_PIEN4_Pos             (12)                                              /*!< EPWM_T::INTEN0: PIEN4 Position          */
#define EPWM_INTEN0_PIEN4_Msk             (0x1ul << EPWM_INTEN0_PIEN4_Pos)                   /*!< EPWM_T::INTEN0: PIEN4 Mask              */

#define EPWM_INTEN0_PIEN5_Pos             (13)                                              /*!< EPWM_T::INTEN0: PIEN5 Position          */
#define EPWM_INTEN0_PIEN5_Msk             (0x1ul << EPWM_INTEN0_PIEN5_Pos)                   /*!< EPWM_T::INTEN0: PIEN5 Mask              */

#define EPWM_INTEN0_CMPUIEN0_Pos          (16)                                              /*!< EPWM_T::INTEN0: CMPUIEN0 Position       */
#define EPWM_INTEN0_CMPUIEN0_Msk          (0x1ul << EPWM_INTEN0_CMPUIEN0_Pos)                /*!< EPWM_T::INTEN0: CMPUIEN0 Mask           */

#define EPWM_INTEN0_CMPUIEN1_Pos          (17)                                              /*!< EPWM_T::INTEN0: CMPUIEN1 Position       */
#define EPWM_INTEN0_CMPUIEN1_Msk          (0x1ul << EPWM_INTEN0_CMPUIEN1_Pos)                /*!< EPWM_T::INTEN0: CMPUIEN1 Mask           */

#define EPWM_INTEN0_CMPUIEN2_Pos          (18)                                              /*!< EPWM_T::INTEN0: CMPUIEN2 Position       */
#define EPWM_INTEN0_CMPUIEN2_Msk          (0x1ul << EPWM_INTEN0_CMPUIEN2_Pos)                /*!< EPWM_T::INTEN0: CMPUIEN2 Mask           */

#define EPWM_INTEN0_CMPUIEN3_Pos          (19)                                              /*!< EPWM_T::INTEN0: CMPUIEN3 Position       */
#define EPWM_INTEN0_CMPUIEN3_Msk          (0x1ul << EPWM_INTEN0_CMPUIEN3_Pos)                /*!< EPWM_T::INTEN0: CMPUIEN3 Mask           */

#define EPWM_INTEN0_CMPUIEN4_Pos          (20)                                              /*!< EPWM_T::INTEN0: CMPUIEN4 Position       */
#define EPWM_INTEN0_CMPUIEN4_Msk          (0x1ul << EPWM_INTEN0_CMPUIEN4_Pos)                /*!< EPWM_T::INTEN0: CMPUIEN4 Mask           */

#define EPWM_INTEN0_CMPUIEN5_Pos          (21)                                              /*!< EPWM_T::INTEN0: CMPUIEN5 Position       */
#define EPWM_INTEN0_CMPUIEN5_Msk          (0x1ul << EPWM_INTEN0_CMPUIEN5_Pos)                /*!< EPWM_T::INTEN0: CMPUIEN5 Mask           */

#define EPWM_INTEN0_CMPDIEN0_Pos          (24)                                              /*!< EPWM_T::INTEN0: CMPDIEN0 Position       */
#define EPWM_INTEN0_CMPDIEN0_Msk          (0x1ul << EPWM_INTEN0_CMPDIEN0_Pos)                /*!< EPWM_T::INTEN0: CMPDIEN0 Mask           */

#define EPWM_INTEN0_CMPDIEN1_Pos          (25)                                              /*!< EPWM_T::INTEN0: CMPDIEN1 Position       */
#define EPWM_INTEN0_CMPDIEN1_Msk          (0x1ul << EPWM_INTEN0_CMPDIEN1_Pos)                /*!< EPWM_T::INTEN0: CMPDIEN1 Mask           */

#define EPWM_INTEN0_CMPDIEN2_Pos          (26)                                              /*!< EPWM_T::INTEN0: CMPDIEN2 Position       */
#define EPWM_INTEN0_CMPDIEN2_Msk          (0x1ul << EPWM_INTEN0_CMPDIEN2_Pos)                /*!< EPWM_T::INTEN0: CMPDIEN2 Mask           */

#define EPWM_INTEN0_CMPDIEN3_Pos          (27)                                              /*!< EPWM_T::INTEN0: CMPDIEN3 Position       */
#define EPWM_INTEN0_CMPDIEN3_Msk          (0x1ul << EPWM_INTEN0_CMPDIEN3_Pos)                /*!< EPWM_T::INTEN0: CMPDIEN3 Mask           */

#define EPWM_INTEN0_CMPDIEN4_Pos          (28)                                              /*!< EPWM_T::INTEN0: CMPDIEN4 Position       */
#define EPWM_INTEN0_CMPDIEN4_Msk          (0x1ul << EPWM_INTEN0_CMPDIEN4_Pos)                /*!< EPWM_T::INTEN0: CMPDIEN4 Mask           */

#define EPWM_INTEN0_CMPDIEN5_Pos          (29)                                              /*!< EPWM_T::INTEN0: CMPDIEN5 Position       */
#define EPWM_INTEN0_CMPDIEN5_Msk          (0x1ul << EPWM_INTEN0_CMPDIEN5_Pos)                /*!< EPWM_T::INTEN0: CMPDIEN5 Mask           */

#define EPWM_INTEN1_BRKEIEN0_1_Pos        (0)                                               /*!< EPWM_T::INTEN1: BRKEIEN0_1 Position     */
#define EPWM_INTEN1_BRKEIEN0_1_Msk        (0x1ul << EPWM_INTEN1_BRKEIEN0_1_Pos)              /*!< EPWM_T::INTEN1: BRKEIEN0_1 Mask         */

#define EPWM_INTEN1_BRKEIEN2_3_Pos        (1)                                               /*!< EPWM_T::INTEN1: BRKEIEN2_3 Position     */
#define EPWM_INTEN1_BRKEIEN2_3_Msk        (0x1ul << EPWM_INTEN1_BRKEIEN2_3_Pos)              /*!< EPWM_T::INTEN1: BRKEIEN2_3 Mask         */

#define EPWM_INTEN1_BRKEIEN4_5_Pos        (2)                                               /*!< EPWM_T::INTEN1: BRKEIEN4_5 Position     */
#define EPWM_INTEN1_BRKEIEN4_5_Msk        (0x1ul << EPWM_INTEN1_BRKEIEN4_5_Pos)              /*!< EPWM_T::INTEN1: BRKEIEN4_5 Mask         */

#define EPWM_INTEN1_BRKLIEN0_1_Pos        (8)                                               /*!< EPWM_T::INTEN1: BRKLIEN0_1 Position     */
#define EPWM_INTEN1_BRKLIEN0_1_Msk        (0x1ul << EPWM_INTEN1_BRKLIEN0_1_Pos)              /*!< EPWM_T::INTEN1: BRKLIEN0_1 Mask         */

#define EPWM_INTEN1_BRKLIEN2_3_Pos        (9)                                               /*!< EPWM_T::INTEN1: BRKLIEN2_3 Position     */
#define EPWM_INTEN1_BRKLIEN2_3_Msk        (0x1ul << EPWM_INTEN1_BRKLIEN2_3_Pos)              /*!< EPWM_T::INTEN1: BRKLIEN2_3 Mask         */

#define EPWM_INTEN1_BRKLIEN4_5_Pos        (10)                                              /*!< EPWM_T::INTEN1: BRKLIEN4_5 Position     */
#define EPWM_INTEN1_BRKLIEN4_5_Msk        (0x1ul << EPWM_INTEN1_BRKLIEN4_5_Pos)              /*!< EPWM_T::INTEN1: BRKLIEN4_5 Mask         */

#define EPWM_INTSTS0_ZIF0_Pos             (0)                                               /*!< EPWM_T::INTSTS0: ZIF0 Position          */
#define EPWM_INTSTS0_ZIF0_Msk             (0x1ul << EPWM_INTSTS0_ZIF0_Pos)                   /*!< EPWM_T::INTSTS0: ZIF0 Mask              */

#define EPWM_INTSTS0_ZIF1_Pos             (1)                                               /*!< EPWM_T::INTSTS0: ZIF1 Position          */
#define EPWM_INTSTS0_ZIF1_Msk             (0x1ul << EPWM_INTSTS0_ZIF1_Pos)                   /*!< EPWM_T::INTSTS0: ZIF1 Mask              */

#define EPWM_INTSTS0_ZIF2_Pos             (2)                                               /*!< EPWM_T::INTSTS0: ZIF2 Position          */
#define EPWM_INTSTS0_ZIF2_Msk             (0x1ul << EPWM_INTSTS0_ZIF2_Pos)                   /*!< EPWM_T::INTSTS0: ZIF2 Mask              */

#define EPWM_INTSTS0_ZIF3_Pos             (3)                                               /*!< EPWM_T::INTSTS0: ZIF3 Position          */
#define EPWM_INTSTS0_ZIF3_Msk             (0x1ul << EPWM_INTSTS0_ZIF3_Pos)                   /*!< EPWM_T::INTSTS0: ZIF3 Mask              */

#define EPWM_INTSTS0_ZIF4_Pos             (4)                                               /*!< EPWM_T::INTSTS0: ZIF4 Position          */
#define EPWM_INTSTS0_ZIF4_Msk             (0x1ul << EPWM_INTSTS0_ZIF4_Pos)                   /*!< EPWM_T::INTSTS0: ZIF4 Mask              */

#define EPWM_INTSTS0_ZIF5_Pos             (5)                                               /*!< EPWM_T::INTSTS0: ZIF5 Position          */
#define EPWM_INTSTS0_ZIF5_Msk             (0x1ul << EPWM_INTSTS0_ZIF5_Pos)                   /*!< EPWM_T::INTSTS0: ZIF5 Mask              */

#define EPWM_INTSTS0_PIF0_Pos             (8)                                               /*!< EPWM_T::INTSTS0: PIF0 Position          */
#define EPWM_INTSTS0_PIF0_Msk             (0x1ul << EPWM_INTSTS0_PIF0_Pos)                   /*!< EPWM_T::INTSTS0: PIF0 Mask              */

#define EPWM_INTSTS0_PIF1_Pos             (9)                                               /*!< EPWM_T::INTSTS0: PIF1 Position          */
#define EPWM_INTSTS0_PIF1_Msk             (0x1ul << EPWM_INTSTS0_PIF1_Pos)                   /*!< EPWM_T::INTSTS0: PIF1 Mask              */

#define EPWM_INTSTS0_PIF2_Pos             (10)                                              /*!< EPWM_T::INTSTS0: PIF2 Position          */
#define EPWM_INTSTS0_PIF2_Msk             (0x1ul << EPWM_INTSTS0_PIF2_Pos)                   /*!< EPWM_T::INTSTS0: PIF2 Mask              */

#define EPWM_INTSTS0_PIF3_Pos             (11)                                              /*!< EPWM_T::INTSTS0: PIF3 Position          */
#define EPWM_INTSTS0_PIF3_Msk             (0x1ul << EPWM_INTSTS0_PIF3_Pos)                   /*!< EPWM_T::INTSTS0: PIF3 Mask              */

#define EPWM_INTSTS0_PIF4_Pos             (12)                                              /*!< EPWM_T::INTSTS0: PIF4 Position          */
#define EPWM_INTSTS0_PIF4_Msk             (0x1ul << EPWM_INTSTS0_PIF4_Pos)                   /*!< EPWM_T::INTSTS0: PIF4 Mask              */

#define EPWM_INTSTS0_PIF5_Pos             (13)                                              /*!< EPWM_T::INTSTS0: PIF5 Position          */
#define EPWM_INTSTS0_PIF5_Msk             (0x1ul << EPWM_INTSTS0_PIF5_Pos)                   /*!< EPWM_T::INTSTS0: PIF5 Mask              */

#define EPWM_INTSTS0_CMPUIF0_Pos          (16)                                              /*!< EPWM_T::INTSTS0: CMPUIF0 Position       */
#define EPWM_INTSTS0_CMPUIF0_Msk          (0x1ul << EPWM_INTSTS0_CMPUIF0_Pos)                /*!< EPWM_T::INTSTS0: CMPUIF0 Mask           */

#define EPWM_INTSTS0_CMPUIF1_Pos          (17)                                              /*!< EPWM_T::INTSTS0: CMPUIF1 Position       */
#define EPWM_INTSTS0_CMPUIF1_Msk          (0x1ul << EPWM_INTSTS0_CMPUIF1_Pos)                /*!< EPWM_T::INTSTS0: CMPUIF1 Mask           */

#define EPWM_INTSTS0_CMPUIF2_Pos          (18)                                              /*!< EPWM_T::INTSTS0: CMPUIF2 Position       */
#define EPWM_INTSTS0_CMPUIF2_Msk          (0x1ul << EPWM_INTSTS0_CMPUIF2_Pos)                /*!< EPWM_T::INTSTS0: CMPUIF2 Mask           */

#define EPWM_INTSTS0_CMPUIF3_Pos          (19)                                              /*!< EPWM_T::INTSTS0: CMPUIF3 Position       */
#define EPWM_INTSTS0_CMPUIF3_Msk          (0x1ul << EPWM_INTSTS0_CMPUIF3_Pos)                /*!< EPWM_T::INTSTS0: CMPUIF3 Mask           */

#define EPWM_INTSTS0_CMPUIF4_Pos          (20)                                              /*!< EPWM_T::INTSTS0: CMPUIF4 Position       */
#define EPWM_INTSTS0_CMPUIF4_Msk          (0x1ul << EPWM_INTSTS0_CMPUIF4_Pos)                /*!< EPWM_T::INTSTS0: CMPUIF4 Mask           */

#define EPWM_INTSTS0_CMPUIF5_Pos          (21)                                              /*!< EPWM_T::INTSTS0: CMPUIF5 Position       */
#define EPWM_INTSTS0_CMPUIF5_Msk          (0x1ul << EPWM_INTSTS0_CMPUIF5_Pos)                /*!< EPWM_T::INTSTS0: CMPUIF5 Mask           */

#define EPWM_INTSTS0_CMPDIF0_Pos          (24)                                              /*!< EPWM_T::INTSTS0: CMPDIF0 Position       */
#define EPWM_INTSTS0_CMPDIF0_Msk          (0x1ul << EPWM_INTSTS0_CMPDIF0_Pos)                /*!< EPWM_T::INTSTS0: CMPDIF0 Mask           */

#define EPWM_INTSTS0_CMPDIF1_Pos          (25)                                              /*!< EPWM_T::INTSTS0: CMPDIF1 Position       */
#define EPWM_INTSTS0_CMPDIF1_Msk          (0x1ul << EPWM_INTSTS0_CMPDIF1_Pos)                /*!< EPWM_T::INTSTS0: CMPDIF1 Mask           */

#define EPWM_INTSTS0_CMPDIF2_Pos          (26)                                              /*!< EPWM_T::INTSTS0: CMPDIF2 Position       */
#define EPWM_INTSTS0_CMPDIF2_Msk          (0x1ul << EPWM_INTSTS0_CMPDIF2_Pos)                /*!< EPWM_T::INTSTS0: CMPDIF2 Mask           */

#define EPWM_INTSTS0_CMPDIF3_Pos          (27)                                              /*!< EPWM_T::INTSTS0: CMPDIF3 Position       */
#define EPWM_INTSTS0_CMPDIF3_Msk          (0x1ul << EPWM_INTSTS0_CMPDIF3_Pos)                /*!< EPWM_T::INTSTS0: CMPDIF3 Mask           */

#define EPWM_INTSTS0_CMPDIF4_Pos          (28)                                              /*!< EPWM_T::INTSTS0: CMPDIF4 Position       */
#define EPWM_INTSTS0_CMPDIF4_Msk          (0x1ul << EPWM_INTSTS0_CMPDIF4_Pos)                /*!< EPWM_T::INTSTS0: CMPDIF4 Mask           */

#define EPWM_INTSTS0_CMPDIF5_Pos          (29)                                              /*!< EPWM_T::INTSTS0: CMPDIF5 Position       */
#define EPWM_INTSTS0_CMPDIF5_Msk          (0x1ul << EPWM_INTSTS0_CMPDIF5_Pos)                /*!< EPWM_T::INTSTS0: CMPDIF5 Mask           */

#define EPWM_INTSTS1_BRKEIF0_Pos          (0)                                               /*!< EPWM_T::INTSTS1: BRKEIF0 Position       */
#define EPWM_INTSTS1_BRKEIF0_Msk          (0x1ul << EPWM_INTSTS1_BRKEIF0_Pos)                /*!< EPWM_T::INTSTS1: BRKEIF0 Mask           */

#define EPWM_INTSTS1_BRKEIF1_Pos          (1)                                               /*!< EPWM_T::INTSTS1: BRKEIF1 Position       */
#define EPWM_INTSTS1_BRKEIF1_Msk          (0x1ul << EPWM_INTSTS1_BRKEIF1_Pos)                /*!< EPWM_T::INTSTS1: BRKEIF1 Mask           */

#define EPWM_INTSTS1_BRKEIF2_Pos          (2)                                               /*!< EPWM_T::INTSTS1: BRKEIF2 Position       */
#define EPWM_INTSTS1_BRKEIF2_Msk          (0x1ul << EPWM_INTSTS1_BRKEIF2_Pos)                /*!< EPWM_T::INTSTS1: BRKEIF2 Mask           */

#define EPWM_INTSTS1_BRKEIF3_Pos          (3)                                               /*!< EPWM_T::INTSTS1: BRKEIF3 Position       */
#define EPWM_INTSTS1_BRKEIF3_Msk          (0x1ul << EPWM_INTSTS1_BRKEIF3_Pos)                /*!< EPWM_T::INTSTS1: BRKEIF3 Mask           */

#define EPWM_INTSTS1_BRKEIF4_Pos          (4)                                               /*!< EPWM_T::INTSTS1: BRKEIF4 Position       */
#define EPWM_INTSTS1_BRKEIF4_Msk          (0x1ul << EPWM_INTSTS1_BRKEIF4_Pos)                /*!< EPWM_T::INTSTS1: BRKEIF4 Mask           */

#define EPWM_INTSTS1_BRKEIF5_Pos          (5)                                               /*!< EPWM_T::INTSTS1: BRKEIF5 Position       */
#define EPWM_INTSTS1_BRKEIF5_Msk          (0x1ul << EPWM_INTSTS1_BRKEIF5_Pos)                /*!< EPWM_T::INTSTS1: BRKEIF5 Mask           */

#define EPWM_INTSTS1_BRKLIF0_Pos          (8)                                               /*!< EPWM_T::INTSTS1: BRKLIF0 Position       */
#define EPWM_INTSTS1_BRKLIF0_Msk          (0x1ul << EPWM_INTSTS1_BRKLIF0_Pos)                /*!< EPWM_T::INTSTS1: BRKLIF0 Mask           */

#define EPWM_INTSTS1_BRKLIF1_Pos          (9)                                               /*!< EPWM_T::INTSTS1: BRKLIF1 Position       */
#define EPWM_INTSTS1_BRKLIF1_Msk          (0x1ul << EPWM_INTSTS1_BRKLIF1_Pos)                /*!< EPWM_T::INTSTS1: BRKLIF1 Mask           */

#define EPWM_INTSTS1_BRKLIF2_Pos          (10)                                              /*!< EPWM_T::INTSTS1: BRKLIF2 Position       */
#define EPWM_INTSTS1_BRKLIF2_Msk          (0x1ul << EPWM_INTSTS1_BRKLIF2_Pos)                /*!< EPWM_T::INTSTS1: BRKLIF2 Mask           */

#define EPWM_INTSTS1_BRKLIF3_Pos          (11)                                              /*!< EPWM_T::INTSTS1: BRKLIF3 Position       */
#define EPWM_INTSTS1_BRKLIF3_Msk          (0x1ul << EPWM_INTSTS1_BRKLIF3_Pos)                /*!< EPWM_T::INTSTS1: BRKLIF3 Mask           */

#define EPWM_INTSTS1_BRKLIF4_Pos          (12)                                              /*!< EPWM_T::INTSTS1: BRKLIF4 Position       */
#define EPWM_INTSTS1_BRKLIF4_Msk          (0x1ul << EPWM_INTSTS1_BRKLIF4_Pos)                /*!< EPWM_T::INTSTS1: BRKLIF4 Mask           */

#define EPWM_INTSTS1_BRKLIF5_Pos          (13)                                              /*!< EPWM_T::INTSTS1: BRKLIF5 Position       */
#define EPWM_INTSTS1_BRKLIF5_Msk          (0x1ul << EPWM_INTSTS1_BRKLIF5_Pos)                /*!< EPWM_T::INTSTS1: BRKLIF5 Mask           */

#define EPWM_INTSTS1_BRKESTS0_Pos         (16)                                              /*!< EPWM_T::INTSTS1: BRKESTS0 Position      */
#define EPWM_INTSTS1_BRKESTS0_Msk         (0x1ul << EPWM_INTSTS1_BRKESTS0_Pos)               /*!< EPWM_T::INTSTS1: BRKESTS0 Mask          */

#define EPWM_INTSTS1_BRKESTS1_Pos         (17)                                              /*!< EPWM_T::INTSTS1: BRKESTS1 Position      */
#define EPWM_INTSTS1_BRKESTS1_Msk         (0x1ul << EPWM_INTSTS1_BRKESTS1_Pos)               /*!< EPWM_T::INTSTS1: BRKESTS1 Mask          */

#define EPWM_INTSTS1_BRKESTS2_Pos         (18)                                              /*!< EPWM_T::INTSTS1: BRKESTS2 Position      */
#define EPWM_INTSTS1_BRKESTS2_Msk         (0x1ul << EPWM_INTSTS1_BRKESTS2_Pos)               /*!< EPWM_T::INTSTS1: BRKESTS2 Mask          */

#define EPWM_INTSTS1_BRKESTS3_Pos         (19)                                              /*!< EPWM_T::INTSTS1: BRKESTS3 Position      */
#define EPWM_INTSTS1_BRKESTS3_Msk         (0x1ul << EPWM_INTSTS1_BRKESTS3_Pos)               /*!< EPWM_T::INTSTS1: BRKESTS3 Mask          */

#define EPWM_INTSTS1_BRKESTS4_Pos         (20)                                              /*!< EPWM_T::INTSTS1: BRKESTS4 Position      */
#define EPWM_INTSTS1_BRKESTS4_Msk         (0x1ul << EPWM_INTSTS1_BRKESTS4_Pos)               /*!< EPWM_T::INTSTS1: BRKESTS4 Mask          */

#define EPWM_INTSTS1_BRKESTS5_Pos         (21)                                              /*!< EPWM_T::INTSTS1: BRKESTS5 Position      */
#define EPWM_INTSTS1_BRKESTS5_Msk         (0x1ul << EPWM_INTSTS1_BRKESTS5_Pos)               /*!< EPWM_T::INTSTS1: BRKESTS5 Mask          */

#define EPWM_INTSTS1_BRKLSTS0_Pos         (24)                                              /*!< EPWM_T::INTSTS1: BRKLSTS0 Position      */
#define EPWM_INTSTS1_BRKLSTS0_Msk         (0x1ul << EPWM_INTSTS1_BRKLSTS0_Pos)               /*!< EPWM_T::INTSTS1: BRKLSTS0 Mask          */

#define EPWM_INTSTS1_BRKLSTS1_Pos         (25)                                              /*!< EPWM_T::INTSTS1: BRKLSTS1 Position      */
#define EPWM_INTSTS1_BRKLSTS1_Msk         (0x1ul << EPWM_INTSTS1_BRKLSTS1_Pos)               /*!< EPWM_T::INTSTS1: BRKLSTS1 Mask          */

#define EPWM_INTSTS1_BRKLSTS2_Pos         (26)                                              /*!< EPWM_T::INTSTS1: BRKLSTS2 Position      */
#define EPWM_INTSTS1_BRKLSTS2_Msk         (0x1ul << EPWM_INTSTS1_BRKLSTS2_Pos)               /*!< EPWM_T::INTSTS1: BRKLSTS2 Mask          */

#define EPWM_INTSTS1_BRKLSTS3_Pos         (27)                                              /*!< EPWM_T::INTSTS1: BRKLSTS3 Position      */
#define EPWM_INTSTS1_BRKLSTS3_Msk         (0x1ul << EPWM_INTSTS1_BRKLSTS3_Pos)               /*!< EPWM_T::INTSTS1: BRKLSTS3 Mask          */

#define EPWM_INTSTS1_BRKLSTS4_Pos         (28)                                              /*!< EPWM_T::INTSTS1: BRKLSTS4 Position      */
#define EPWM_INTSTS1_BRKLSTS4_Msk         (0x1ul << EPWM_INTSTS1_BRKLSTS4_Pos)               /*!< EPWM_T::INTSTS1: BRKLSTS4 Mask          */

#define EPWM_INTSTS1_BRKLSTS5_Pos         (29)                                              /*!< EPWM_T::INTSTS1: BRKLSTS5 Position      */
#define EPWM_INTSTS1_BRKLSTS5_Msk         (0x1ul << EPWM_INTSTS1_BRKLSTS5_Pos)               /*!< EPWM_T::INTSTS1: BRKLSTS5 Mask          */

#define EPWM_DACTRGEN_ZTE0_Pos            (0)                                               /*!< EPWM_T::DACTRGEN: ZTE0 Position         */
#define EPWM_DACTRGEN_ZTE0_Msk            (0x1ul << EPWM_DACTRGEN_ZTE0_Pos)                  /*!< EPWM_T::DACTRGEN: ZTE0 Mask             */

#define EPWM_DACTRGEN_ZTE1_Pos            (1)                                               /*!< EPWM_T::DACTRGEN: ZTE1 Position         */
#define EPWM_DACTRGEN_ZTE1_Msk            (0x1ul << EPWM_DACTRGEN_ZTE1_Pos)                  /*!< EPWM_T::DACTRGEN: ZTE1 Mask             */

#define EPWM_DACTRGEN_ZTE2_Pos            (2)                                               /*!< EPWM_T::DACTRGEN: ZTE2 Position         */
#define EPWM_DACTRGEN_ZTE2_Msk            (0x1ul << EPWM_DACTRGEN_ZTE2_Pos)                  /*!< EPWM_T::DACTRGEN: ZTE2 Mask             */

#define EPWM_DACTRGEN_ZTE3_Pos            (3)                                               /*!< EPWM_T::DACTRGEN: ZTE3 Position         */
#define EPWM_DACTRGEN_ZTE3_Msk            (0x1ul << EPWM_DACTRGEN_ZTE3_Pos)                  /*!< EPWM_T::DACTRGEN: ZTE3 Mask             */

#define EPWM_DACTRGEN_ZTE4_Pos            (4)                                               /*!< EPWM_T::DACTRGEN: ZTE4 Position         */
#define EPWM_DACTRGEN_ZTE4_Msk            (0x1ul << EPWM_DACTRGEN_ZTE4_Pos)                  /*!< EPWM_T::DACTRGEN: ZTE4 Mask             */

#define EPWM_DACTRGEN_ZTE5_Pos            (5)                                               /*!< EPWM_T::DACTRGEN: ZTE5 Position         */
#define EPWM_DACTRGEN_ZTE5_Msk            (0x1ul << EPWM_DACTRGEN_ZTE5_Pos)                  /*!< EPWM_T::DACTRGEN: ZTE5 Mask             */

#define EPWM_DACTRGEN_PTE0_Pos            (8)                                               /*!< EPWM_T::DACTRGEN: PTE0 Position         */
#define EPWM_DACTRGEN_PTE0_Msk            (0x1ul << EPWM_DACTRGEN_PTE0_Pos)                  /*!< EPWM_T::DACTRGEN: PTE0 Mask             */

#define EPWM_DACTRGEN_PTE1_Pos            (9)                                               /*!< EPWM_T::DACTRGEN: PTE1 Position         */
#define EPWM_DACTRGEN_PTE1_Msk            (0x1ul << EPWM_DACTRGEN_PTE1_Pos)                  /*!< EPWM_T::DACTRGEN: PTE1 Mask             */

#define EPWM_DACTRGEN_PTE2_Pos            (10)                                              /*!< EPWM_T::DACTRGEN: PTE2 Position         */
#define EPWM_DACTRGEN_PTE2_Msk            (0x1ul << EPWM_DACTRGEN_PTE2_Pos)                  /*!< EPWM_T::DACTRGEN: PTE2 Mask             */

#define EPWM_DACTRGEN_PTE3_Pos            (11)                                              /*!< EPWM_T::DACTRGEN: PTE3 Position         */
#define EPWM_DACTRGEN_PTE3_Msk            (0x1ul << EPWM_DACTRGEN_PTE3_Pos)                  /*!< EPWM_T::DACTRGEN: PTE3 Mask             */

#define EPWM_DACTRGEN_PTE4_Pos            (12)                                              /*!< EPWM_T::DACTRGEN: PTE4 Position         */
#define EPWM_DACTRGEN_PTE4_Msk            (0x1ul << EPWM_DACTRGEN_PTE4_Pos)                  /*!< EPWM_T::DACTRGEN: PTE4 Mask             */

#define EPWM_DACTRGEN_PTE5_Pos            (13)                                              /*!< EPWM_T::DACTRGEN: PTE5 Position         */
#define EPWM_DACTRGEN_PTE5_Msk            (0x1ul << EPWM_DACTRGEN_PTE5_Pos)                  /*!< EPWM_T::DACTRGEN: PTE5 Mask             */

#define EPWM_DACTRGEN_CUTRGE0_Pos         (16)                                              /*!< EPWM_T::DACTRGEN: CUTRGE0 Position      */
#define EPWM_DACTRGEN_CUTRGE0_Msk         (0x1ul << EPWM_DACTRGEN_CUTRGE0_Pos)               /*!< EPWM_T::DACTRGEN: CUTRGE0 Mask          */

#define EPWM_DACTRGEN_CUTRGE1_Pos         (17)                                              /*!< EPWM_T::DACTRGEN: CUTRGE1 Position      */
#define EPWM_DACTRGEN_CUTRGE1_Msk         (0x1ul << EPWM_DACTRGEN_CUTRGE1_Pos)               /*!< EPWM_T::DACTRGEN: CUTRGE1 Mask          */

#define EPWM_DACTRGEN_CUTRGE2_Pos         (18)                                              /*!< EPWM_T::DACTRGEN: CUTRGE2 Position      */
#define EPWM_DACTRGEN_CUTRGE2_Msk         (0x1ul << EPWM_DACTRGEN_CUTRGE2_Pos)               /*!< EPWM_T::DACTRGEN: CUTRGE2 Mask          */

#define EPWM_DACTRGEN_CUTRGE3_Pos         (19)                                              /*!< EPWM_T::DACTRGEN: CUTRGE3 Position      */
#define EPWM_DACTRGEN_CUTRGE3_Msk         (0x1ul << EPWM_DACTRGEN_CUTRGE3_Pos)               /*!< EPWM_T::DACTRGEN: CUTRGE3 Mask          */

#define EPWM_DACTRGEN_CUTRGE4_Pos         (20)                                              /*!< EPWM_T::DACTRGEN: CUTRGE4 Position      */
#define EPWM_DACTRGEN_CUTRGE4_Msk         (0x1ul << EPWM_DACTRGEN_CUTRGE4_Pos)               /*!< EPWM_T::DACTRGEN: CUTRGE4 Mask          */

#define EPWM_DACTRGEN_CUTRGE5_Pos         (21)                                              /*!< EPWM_T::DACTRGEN: CUTRGE5 Position      */
#define EPWM_DACTRGEN_CUTRGE5_Msk         (0x1ul << EPWM_DACTRGEN_CUTRGE5_Pos)               /*!< EPWM_T::DACTRGEN: CUTRGE5 Mask          */

#define EPWM_DACTRGEN_CDTRGE0_Pos         (24)                                              /*!< EPWM_T::DACTRGEN: CDTRGE0 Position      */
#define EPWM_DACTRGEN_CDTRGE0_Msk         (0x1ul << EPWM_DACTRGEN_CDTRGE0_Pos)               /*!< EPWM_T::DACTRGEN: CDTRGE0 Mask          */

#define EPWM_DACTRGEN_CDTRGE1_Pos         (25)                                              /*!< EPWM_T::DACTRGEN: CDTRGE1 Position      */
#define EPWM_DACTRGEN_CDTRGE1_Msk         (0x1ul << EPWM_DACTRGEN_CDTRGE1_Pos)               /*!< EPWM_T::DACTRGEN: CDTRGE1 Mask          */

#define EPWM_DACTRGEN_CDTRGE2_Pos         (26)                                              /*!< EPWM_T::DACTRGEN: CDTRGE2 Position      */
#define EPWM_DACTRGEN_CDTRGE2_Msk         (0x1ul << EPWM_DACTRGEN_CDTRGE2_Pos)               /*!< EPWM_T::DACTRGEN: CDTRGE2 Mask          */

#define EPWM_DACTRGEN_CDTRGE3_Pos         (27)                                              /*!< EPWM_T::DACTRGEN: CDTRGE3 Position      */
#define EPWM_DACTRGEN_CDTRGE3_Msk         (0x1ul << EPWM_DACTRGEN_CDTRGE3_Pos)               /*!< EPWM_T::DACTRGEN: CDTRGE3 Mask          */

#define EPWM_DACTRGEN_CDTRGE4_Pos         (28)                                              /*!< EPWM_T::DACTRGEN: CDTRGE4 Position      */
#define EPWM_DACTRGEN_CDTRGE4_Msk         (0x1ul << EPWM_DACTRGEN_CDTRGE4_Pos)               /*!< EPWM_T::DACTRGEN: CDTRGE4 Mask          */

#define EPWM_DACTRGEN_CDTRGE5_Pos         (29)                                              /*!< EPWM_T::DACTRGEN: CDTRGE5 Position      */
#define EPWM_DACTRGEN_CDTRGE5_Msk         (0x1ul << EPWM_DACTRGEN_CDTRGE5_Pos)               /*!< EPWM_T::DACTRGEN: CDTRGE5 Mask          */

#define EPWM_EADCTS0_TRGSEL0_Pos          (0)                                               /*!< EPWM_T::EADCTS0: TRGSEL0 Position       */
#define EPWM_EADCTS0_TRGSEL0_Msk          (0xful << EPWM_EADCTS0_TRGSEL0_Pos)                /*!< EPWM_T::EADCTS0: TRGSEL0 Mask           */

#define EPWM_EADCTS0_TRGEN0_Pos           (7)                                               /*!< EPWM_T::EADCTS0: TRGEN0 Position        */
#define EPWM_EADCTS0_TRGEN0_Msk           (0x1ul << EPWM_EADCTS0_TRGEN0_Pos)                 /*!< EPWM_T::EADCTS0: TRGEN0 Mask            */

#define EPWM_EADCTS0_TRGSEL1_Pos          (8)                                               /*!< EPWM_T::EADCTS0: TRGSEL1 Position       */
#define EPWM_EADCTS0_TRGSEL1_Msk          (0xful << EPWM_EADCTS0_TRGSEL1_Pos)                /*!< EPWM_T::EADCTS0: TRGSEL1 Mask           */

#define EPWM_EADCTS0_TRGEN1_Pos           (15)                                              /*!< EPWM_T::EADCTS0: TRGEN1 Position        */
#define EPWM_EADCTS0_TRGEN1_Msk           (0x1ul << EPWM_EADCTS0_TRGEN1_Pos)                 /*!< EPWM_T::EADCTS0: TRGEN1 Mask            */

#define EPWM_EADCTS0_TRGSEL2_Pos          (16)                                              /*!< EPWM_T::EADCTS0: TRGSEL2 Position       */
#define EPWM_EADCTS0_TRGSEL2_Msk          (0xful << EPWM_EADCTS0_TRGSEL2_Pos)                /*!< EPWM_T::EADCTS0: TRGSEL2 Mask           */

#define EPWM_EADCTS0_TRGEN2_Pos           (23)                                              /*!< EPWM_T::EADCTS0: TRGEN2 Position        */
#define EPWM_EADCTS0_TRGEN2_Msk           (0x1ul << EPWM_EADCTS0_TRGEN2_Pos)                 /*!< EPWM_T::EADCTS0: TRGEN2 Mask            */

#define EPWM_EADCTS0_TRGSEL3_Pos          (24)                                              /*!< EPWM_T::EADCTS0: TRGSEL3 Position       */
#define EPWM_EADCTS0_TRGSEL3_Msk          (0xful << EPWM_EADCTS0_TRGSEL3_Pos)                /*!< EPWM_T::EADCTS0: TRGSEL3 Mask           */

#define EPWM_EADCTS0_TRGEN3_Pos           (31)                                              /*!< EPWM_T::EADCTS0: TRGEN3 Position        */
#define EPWM_EADCTS0_TRGEN3_Msk           (0x1ul << EPWM_EADCTS0_TRGEN3_Pos)                 /*!< EPWM_T::EADCTS0: TRGEN3 Mask            */

#define EPWM_EADCTS1_TRGSEL4_Pos          (0)                                               /*!< EPWM_T::EADCTS1: TRGSEL4 Position       */
#define EPWM_EADCTS1_TRGSEL4_Msk          (0xful << EPWM_EADCTS1_TRGSEL4_Pos)                /*!< EPWM_T::EADCTS1: TRGSEL4 Mask           */

#define EPWM_EADCTS1_TRGEN4_Pos           (7)                                               /*!< EPWM_T::EADCTS1: TRGEN4 Position        */
#define EPWM_EADCTS1_TRGEN4_Msk           (0x1ul << EPWM_EADCTS1_TRGEN4_Pos)                 /*!< EPWM_T::EADCTS1: TRGEN4 Mask            */

#define EPWM_EADCTS1_TRGSEL5_Pos          (8)                                               /*!< EPWM_T::EADCTS1: TRGSEL5 Position       */
#define EPWM_EADCTS1_TRGSEL5_Msk          (0xful << EPWM_EADCTS1_TRGSEL5_Pos)                /*!< EPWM_T::EADCTS1: TRGSEL5 Mask           */

#define EPWM_EADCTS1_TRGEN5_Pos           (15)                                              /*!< EPWM_T::EADCTS1: TRGEN5 Position        */
#define EPWM_EADCTS1_TRGEN5_Msk           (0x1ul << EPWM_EADCTS1_TRGEN5_Pos)                 /*!< EPWM_T::EADCTS1: TRGEN5 Mask            */

#define EPWM_FTCMPDAT0_1_FTCMP_Pos        (0)                                               /*!< EPWM_T::FTCMPDAT0_1: FTCMP Position     */
#define EPWM_FTCMPDAT0_1_FTCMP_Msk        (0xfffful << EPWM_FTCMPDAT0_1_FTCMP_Pos)           /*!< EPWM_T::FTCMPDAT0_1: FTCMP Mask         */

#define EPWM_FTCMPDAT2_3_FTCMP_Pos        (0)                                               /*!< EPWM_T::FTCMPDAT2_3: FTCMP Position     */
#define EPWM_FTCMPDAT2_3_FTCMP_Msk        (0xfffful << EPWM_FTCMPDAT2_3_FTCMP_Pos)           /*!< EPWM_T::FTCMPDAT2_3: FTCMP Mask         */

#define EPWM_FTCMPDAT4_5_FTCMP_Pos        (0)                                               /*!< EPWM_T::FTCMPDAT4_5: FTCMP Position     */
#define EPWM_FTCMPDAT4_5_FTCMP_Msk        (0xfffful << EPWM_FTCMPDAT4_5_FTCMP_Pos)           /*!< EPWM_T::FTCMPDAT4_5: FTCMP Mask         */

#define EPWM_SSCTL_SSEN0_Pos              (0)                                               /*!< EPWM_T::SSCTL: SSEN0 Position           */
#define EPWM_SSCTL_SSEN0_Msk              (0x1ul << EPWM_SSCTL_SSEN0_Pos)                    /*!< EPWM_T::SSCTL: SSEN0 Mask               */

#define EPWM_SSCTL_SSEN1_Pos              (1)                                               /*!< EPWM_T::SSCTL: SSEN1 Position           */
#define EPWM_SSCTL_SSEN1_Msk              (0x1ul << EPWM_SSCTL_SSEN1_Pos)                    /*!< EPWM_T::SSCTL: SSEN1 Mask               */

#define EPWM_SSCTL_SSEN2_Pos              (2)                                               /*!< EPWM_T::SSCTL: SSEN2 Position           */
#define EPWM_SSCTL_SSEN2_Msk              (0x1ul << EPWM_SSCTL_SSEN2_Pos)                    /*!< EPWM_T::SSCTL: SSEN2 Mask               */

#define EPWM_SSCTL_SSEN3_Pos              (3)                                               /*!< EPWM_T::SSCTL: SSEN3 Position           */
#define EPWM_SSCTL_SSEN3_Msk              (0x1ul << EPWM_SSCTL_SSEN3_Pos)                    /*!< EPWM_T::SSCTL: SSEN3 Mask               */

#define EPWM_SSCTL_SSEN4_Pos              (4)                                               /*!< EPWM_T::SSCTL: SSEN4 Position           */
#define EPWM_SSCTL_SSEN4_Msk              (0x1ul << EPWM_SSCTL_SSEN4_Pos)                    /*!< EPWM_T::SSCTL: SSEN4 Mask               */

#define EPWM_SSCTL_SSEN5_Pos              (5)                                               /*!< EPWM_T::SSCTL: SSEN5 Position           */
#define EPWM_SSCTL_SSEN5_Msk              (0x1ul << EPWM_SSCTL_SSEN5_Pos)                    /*!< EPWM_T::SSCTL: SSEN5 Mask               */

#define EPWM_SSCTL_SSRC_Pos               (8)                                               /*!< EPWM_T::SSCTL: SSRC Position            */
#define EPWM_SSCTL_SSRC_Msk               (0x3ul << EPWM_SSCTL_SSRC_Pos)                     /*!< EPWM_T::SSCTL: SSRC Mask                */

#define EPWM_SSTRG_CNTSEN_Pos             (0)                                               /*!< EPWM_T::SSTRG: CNTSEN Position          */
#define EPWM_SSTRG_CNTSEN_Msk             (0x1ul << EPWM_SSTRG_CNTSEN_Pos)                   /*!< EPWM_T::SSTRG: CNTSEN Mask              */

#define EPWM_LEBCTL_LEBEN_Pos             (0)                                               /*!< EPWM_T::LEBCTL: LEBEN Position          */
#define EPWM_LEBCTL_LEBEN_Msk             (0x1ul << EPWM_LEBCTL_LEBEN_Pos)                   /*!< EPWM_T::LEBCTL: LEBEN Mask              */

#define EPWM_LEBCTL_SRCEN0_Pos            (8)                                               /*!< EPWM_T::LEBCTL: SRCEN0 Position         */
#define EPWM_LEBCTL_SRCEN0_Msk            (0x1ul << EPWM_LEBCTL_SRCEN0_Pos)                  /*!< EPWM_T::LEBCTL: SRCEN0 Mask             */

#define EPWM_LEBCTL_SRCEN2_Pos            (9)                                               /*!< EPWM_T::LEBCTL: SRCEN2 Position         */
#define EPWM_LEBCTL_SRCEN2_Msk            (0x1ul << EPWM_LEBCTL_SRCEN2_Pos)                  /*!< EPWM_T::LEBCTL: SRCEN2 Mask             */

#define EPWM_LEBCTL_SRCEN4_Pos            (10)                                              /*!< EPWM_T::LEBCTL: SRCEN4 Position         */
#define EPWM_LEBCTL_SRCEN4_Msk            (0x1ul << EPWM_LEBCTL_SRCEN4_Pos)                  /*!< EPWM_T::LEBCTL: SRCEN4 Mask             */

#define EPWM_LEBCTL_TRGTYPE_Pos           (16)                                              /*!< EPWM_T::LEBCTL: TRGTYPE Position        */
#define EPWM_LEBCTL_TRGTYPE_Msk           (0x3ul << EPWM_LEBCTL_TRGTYPE_Pos)                 /*!< EPWM_T::LEBCTL: TRGTYPE Mask            */

#define EPWM_LEBCNT_LEBCNT_Pos            (0)                                               /*!< EPWM_T::LEBCNT: LEBCNT Position         */
#define EPWM_LEBCNT_LEBCNT_Msk            (0x1fful << EPWM_LEBCNT_LEBCNT_Pos)                /*!< EPWM_T::LEBCNT: LEBCNT Mask             */

#define EPWM_STATUS_CNTMAXF0_Pos          (0)                                               /*!< EPWM_T::STATUS: CNTMAXF0 Position       */
#define EPWM_STATUS_CNTMAXF0_Msk          (0x1ul << EPWM_STATUS_CNTMAXF0_Pos)                /*!< EPWM_T::STATUS: CNTMAXF0 Mask           */

#define EPWM_STATUS_CNTMAXF1_Pos          (1)                                               /*!< EPWM_T::STATUS: CNTMAXF1 Position       */
#define EPWM_STATUS_CNTMAXF1_Msk          (0x1ul << EPWM_STATUS_CNTMAXF1_Pos)                /*!< EPWM_T::STATUS: CNTMAXF1 Mask           */

#define EPWM_STATUS_CNTMAXF2_Pos          (2)                                               /*!< EPWM_T::STATUS: CNTMAXF2 Position       */
#define EPWM_STATUS_CNTMAXF2_Msk          (0x1ul << EPWM_STATUS_CNTMAXF2_Pos)                /*!< EPWM_T::STATUS: CNTMAXF2 Mask           */

#define EPWM_STATUS_CNTMAXF3_Pos          (3)                                               /*!< EPWM_T::STATUS: CNTMAXF3 Position       */
#define EPWM_STATUS_CNTMAXF3_Msk          (0x1ul << EPWM_STATUS_CNTMAXF3_Pos)                /*!< EPWM_T::STATUS: CNTMAXF3 Mask           */

#define EPWM_STATUS_CNTMAXF4_Pos          (4)                                               /*!< EPWM_T::STATUS: CNTMAXF4 Position       */
#define EPWM_STATUS_CNTMAXF4_Msk          (0x1ul << EPWM_STATUS_CNTMAXF4_Pos)                /*!< EPWM_T::STATUS: CNTMAXF4 Mask           */

#define EPWM_STATUS_CNTMAXF5_Pos          (5)                                               /*!< EPWM_T::STATUS: CNTMAXF5 Position       */
#define EPWM_STATUS_CNTMAXF5_Msk          (0x1ul << EPWM_STATUS_CNTMAXF5_Pos)                /*!< EPWM_T::STATUS: CNTMAXF5 Mask           */

#define EPWM_STATUS_SYNCINF0_Pos          (8)                                               /*!< EPWM_T::STATUS: SYNCINF0 Position       */
#define EPWM_STATUS_SYNCINF0_Msk          (0x1ul << EPWM_STATUS_SYNCINF0_Pos)                /*!< EPWM_T::STATUS: SYNCINF0 Mask           */

#define EPWM_STATUS_SYNCINF2_Pos          (9)                                               /*!< EPWM_T::STATUS: SYNCINF2 Position       */
#define EPWM_STATUS_SYNCINF2_Msk          (0x1ul << EPWM_STATUS_SYNCINF2_Pos)                /*!< EPWM_T::STATUS: SYNCINF2 Mask           */

#define EPWM_STATUS_SYNCINF4_Pos          (10)                                              /*!< EPWM_T::STATUS: SYNCINF4 Position       */
#define EPWM_STATUS_SYNCINF4_Msk          (0x1ul << EPWM_STATUS_SYNCINF4_Pos)                /*!< EPWM_T::STATUS: SYNCINF4 Mask           */

#define EPWM_STATUS_EADCTRGF0_Pos         (16)                                              /*!< EPWM_T::STATUS: EADCTRGF0 Position      */
#define EPWM_STATUS_EADCTRGF0_Msk         (0x1ul << EPWM_STATUS_EADCTRGF0_Pos)               /*!< EPWM_T::STATUS: EADCTRGF0 Mask          */

#define EPWM_STATUS_EADCTRGF1_Pos         (17)                                              /*!< EPWM_T::STATUS: EADCTRGF1 Position      */
#define EPWM_STATUS_EADCTRGF1_Msk         (0x1ul << EPWM_STATUS_EADCTRGF1_Pos)               /*!< EPWM_T::STATUS: EADCTRGF1 Mask          */

#define EPWM_STATUS_EADCTRGF2_Pos         (18)                                              /*!< EPWM_T::STATUS: EADCTRGF2 Position      */
#define EPWM_STATUS_EADCTRGF2_Msk         (0x1ul << EPWM_STATUS_EADCTRGF2_Pos)               /*!< EPWM_T::STATUS: EADCTRGF2 Mask          */

#define EPWM_STATUS_EADCTRGF3_Pos         (19)                                              /*!< EPWM_T::STATUS: EADCTRGF3 Position      */
#define EPWM_STATUS_EADCTRGF3_Msk         (0x1ul << EPWM_STATUS_EADCTRGF3_Pos)               /*!< EPWM_T::STATUS: EADCTRGF3 Mask          */

#define EPWM_STATUS_EADCTRGF4_Pos         (20)                                              /*!< EPWM_T::STATUS: EADCTRGF4 Position      */
#define EPWM_STATUS_EADCTRGF4_Msk         (0x1ul << EPWM_STATUS_EADCTRGF4_Pos)               /*!< EPWM_T::STATUS: EADCTRGF4 Mask          */

#define EPWM_STATUS_EADCTRGF5_Pos         (21)                                              /*!< EPWM_T::STATUS: EADCTRGF5 Position      */
#define EPWM_STATUS_EADCTRGF5_Msk         (0x1ul << EPWM_STATUS_EADCTRGF5_Pos)               /*!< EPWM_T::STATUS: EADCTRGF5 Mask          */

#define EPWM_STATUS_DACTRGF_Pos           (24)                                              /*!< EPWM_T::STATUS: DACTRGF Position        */
#define EPWM_STATUS_DACTRGF_Msk           (0x1ul << EPWM_STATUS_DACTRGF_Pos)                 /*!< EPWM_T::STATUS: DACTRGF Mask            */

#define EPWM_IFA0_IFACNT_Pos              (0)                                               /*!< EPWM_T::IFA0: IFACNT Position           */
#define EPWM_IFA0_IFACNT_Msk              (0xfffful << EPWM_IFA0_IFACNT_Pos)                 /*!< EPWM_T::IFA0: IFACNT Mask               */

#define EPWM_IFA0_STPMOD_Pos              (24)                                              /*!< EPWM_T::IFA0: STPMOD Position           */
#define EPWM_IFA0_STPMOD_Msk              (0x1ul << EPWM_IFA0_STPMOD_Pos)                    /*!< EPWM_T::IFA0: STPMOD Mask               */

#define EPWM_IFA0_IFASEL_Pos              (28)                                              /*!< EPWM_T::IFA0: IFASEL Position           */
#define EPWM_IFA0_IFASEL_Msk              (0x3ul << EPWM_IFA0_IFASEL_Pos)                    /*!< EPWM_T::IFA0: IFASEL Mask               */

#define EPWM_IFA0_IFAEN_Pos               (31)                                              /*!< EPWM_T::IFA0: IFAEN Position            */
#define EPWM_IFA0_IFAEN_Msk               (0x1ul << EPWM_IFA0_IFAEN_Pos)                     /*!< EPWM_T::IFA0: IFAEN Mask                */

#define EPWM_IFA1_IFACNT_Pos              (0)                                               /*!< EPWM_T::IFA1: IFACNT Position           */
#define EPWM_IFA1_IFACNT_Msk              (0xfffful << EPWM_IFA1_IFACNT_Pos)                 /*!< EPWM_T::IFA1: IFACNT Mask               */

#define EPWM_IFA1_STPMOD_Pos              (24)                                              /*!< EPWM_T::IFA1: STPMOD Position           */
#define EPWM_IFA1_STPMOD_Msk              (0x1ul << EPWM_IFA1_STPMOD_Pos)                    /*!< EPWM_T::IFA1: STPMOD Mask               */

#define EPWM_IFA1_IFASEL_Pos              (28)                                              /*!< EPWM_T::IFA1: IFASEL Position           */
#define EPWM_IFA1_IFASEL_Msk              (0x3ul << EPWM_IFA1_IFASEL_Pos)                    /*!< EPWM_T::IFA1: IFASEL Mask               */

#define EPWM_IFA1_IFAEN_Pos               (31)                                              /*!< EPWM_T::IFA1: IFAEN Position            */
#define EPWM_IFA1_IFAEN_Msk               (0x1ul << EPWM_IFA1_IFAEN_Pos)                     /*!< EPWM_T::IFA1: IFAEN Mask                */

#define EPWM_IFA2_IFACNT_Pos              (0)                                               /*!< EPWM_T::IFA2: IFACNT Position           */
#define EPWM_IFA2_IFACNT_Msk              (0xfffful << EPWM_IFA2_IFACNT_Pos)                 /*!< EPWM_T::IFA2: IFACNT Mask               */

#define EPWM_IFA2_STPMOD_Pos              (24)                                              /*!< EPWM_T::IFA2: STPMOD Position           */
#define EPWM_IFA2_STPMOD_Msk              (0x1ul << EPWM_IFA2_STPMOD_Pos)                    /*!< EPWM_T::IFA2: STPMOD Mask               */

#define EPWM_IFA2_IFASEL_Pos              (28)                                              /*!< EPWM_T::IFA2: IFASEL Position           */
#define EPWM_IFA2_IFASEL_Msk              (0x3ul << EPWM_IFA2_IFASEL_Pos)                    /*!< EPWM_T::IFA2: IFASEL Mask               */

#define EPWM_IFA2_IFAEN_Pos               (31)                                              /*!< EPWM_T::IFA2: IFAEN Position            */
#define EPWM_IFA2_IFAEN_Msk               (0x1ul << EPWM_IFA2_IFAEN_Pos)                     /*!< EPWM_T::IFA2: IFAEN Mask                */

#define EPWM_IFA3_IFACNT_Pos              (0)                                               /*!< EPWM_T::IFA3: IFACNT Position           */
#define EPWM_IFA3_IFACNT_Msk              (0xfffful << EPWM_IFA3_IFACNT_Pos)                 /*!< EPWM_T::IFA3: IFACNT Mask               */

#define EPWM_IFA3_STPMOD_Pos              (24)                                              /*!< EPWM_T::IFA3: STPMOD Position           */
#define EPWM_IFA3_STPMOD_Msk              (0x1ul << EPWM_IFA3_STPMOD_Pos)                    /*!< EPWM_T::IFA3: STPMOD Mask               */

#define EPWM_IFA3_IFASEL_Pos              (28)                                              /*!< EPWM_T::IFA3: IFASEL Position           */
#define EPWM_IFA3_IFASEL_Msk              (0x3ul << EPWM_IFA3_IFASEL_Pos)                    /*!< EPWM_T::IFA3: IFASEL Mask               */

#define EPWM_IFA3_IFAEN_Pos               (31)                                              /*!< EPWM_T::IFA3: IFAEN Position            */
#define EPWM_IFA3_IFAEN_Msk               (0x1ul << EPWM_IFA3_IFAEN_Pos)                     /*!< EPWM_T::IFA3: IFAEN Mask                */

#define EPWM_IFA4_IFACNT_Pos              (0)                                               /*!< EPWM_T::IFA4: IFACNT Position           */
#define EPWM_IFA4_IFACNT_Msk              (0xfffful << EPWM_IFA4_IFACNT_Pos)                 /*!< EPWM_T::IFA4: IFACNT Mask               */

#define EPWM_IFA4_STPMOD_Pos              (24)                                              /*!< EPWM_T::IFA4: STPMOD Position           */
#define EPWM_IFA4_STPMOD_Msk              (0x1ul << EPWM_IFA4_STPMOD_Pos)                    /*!< EPWM_T::IFA4: STPMOD Mask               */

#define EPWM_IFA4_IFASEL_Pos              (28)                                              /*!< EPWM_T::IFA4: IFASEL Position           */
#define EPWM_IFA4_IFASEL_Msk              (0x3ul << EPWM_IFA4_IFASEL_Pos)                    /*!< EPWM_T::IFA4: IFASEL Mask               */

#define EPWM_IFA4_IFAEN_Pos               (31)                                              /*!< EPWM_T::IFA4: IFAEN Position            */
#define EPWM_IFA4_IFAEN_Msk               (0x1ul << EPWM_IFA4_IFAEN_Pos)                     /*!< EPWM_T::IFA4: IFAEN Mask                */

#define EPWM_IFA5_IFACNT_Pos              (0)                                               /*!< EPWM_T::IFA5: IFACNT Position           */
#define EPWM_IFA5_IFACNT_Msk              (0xfffful << EPWM_IFA5_IFACNT_Pos)                 /*!< EPWM_T::IFA5: IFACNT Mask               */

#define EPWM_IFA5_STPMOD_Pos              (24)                                              /*!< EPWM_T::IFA5: STPMOD Position           */
#define EPWM_IFA5_STPMOD_Msk              (0x1ul << EPWM_IFA5_STPMOD_Pos)                    /*!< EPWM_T::IFA5: STPMOD Mask               */

#define EPWM_IFA5_IFASEL_Pos              (28)                                              /*!< EPWM_T::IFA5: IFASEL Position           */
#define EPWM_IFA5_IFASEL_Msk              (0x3ul << EPWM_IFA5_IFASEL_Pos)                    /*!< EPWM_T::IFA5: IFASEL Mask               */

#define EPWM_IFA5_IFAEN_Pos               (31)                                              /*!< EPWM_T::IFA5: IFAEN Position            */
#define EPWM_IFA5_IFAEN_Msk               (0x1ul << EPWM_IFA5_IFAEN_Pos)                     /*!< EPWM_T::IFA5: IFAEN Mask                */

#define EPWM_AINTSTS_IFAIF0_Pos           (0)                                               /*!< EPWM_T::AINTSTS: IFAIF0 Position        */
#define EPWM_AINTSTS_IFAIF0_Msk           (0x1ul << EPWM_AINTSTS_IFAIF0_Pos)                 /*!< EPWM_T::AINTSTS: IFAIF0 Mask            */

#define EPWM_AINTSTS_IFAIF1_Pos           (1)                                               /*!< EPWM_T::AINTSTS: IFAIF1 Position        */
#define EPWM_AINTSTS_IFAIF1_Msk           (0x1ul << EPWM_AINTSTS_IFAIF1_Pos)                 /*!< EPWM_T::AINTSTS: IFAIF1 Mask            */

#define EPWM_AINTSTS_IFAIF2_Pos           (2)                                               /*!< EPWM_T::AINTSTS: IFAIF2 Position        */
#define EPWM_AINTSTS_IFAIF2_Msk           (0x1ul << EPWM_AINTSTS_IFAIF2_Pos)                 /*!< EPWM_T::AINTSTS: IFAIF2 Mask            */

#define EPWM_AINTSTS_IFAIF3_Pos           (3)                                               /*!< EPWM_T::AINTSTS: IFAIF3 Position        */
#define EPWM_AINTSTS_IFAIF3_Msk           (0x1ul << EPWM_AINTSTS_IFAIF3_Pos)                 /*!< EPWM_T::AINTSTS: IFAIF3 Mask            */

#define EPWM_AINTSTS_IFAIF4_Pos           (4)                                               /*!< EPWM_T::AINTSTS: IFAIF4 Position        */
#define EPWM_AINTSTS_IFAIF4_Msk           (0x1ul << EPWM_AINTSTS_IFAIF4_Pos)                 /*!< EPWM_T::AINTSTS: IFAIF4 Mask            */

#define EPWM_AINTSTS_IFAIF5_Pos           (5)                                               /*!< EPWM_T::AINTSTS: IFAIF5 Position        */
#define EPWM_AINTSTS_IFAIF5_Msk           (0x1ul << EPWM_AINTSTS_IFAIF5_Pos)                 /*!< EPWM_T::AINTSTS: IFAIF5 Mask            */

#define EPWM_AINTEN_IFAIEN0_Pos           (0)                                               /*!< EPWM_T::AINTEN: IFAIEN0 Position        */
#define EPWM_AINTEN_IFAIEN0_Msk           (0x1ul << EPWM_AINTEN_IFAIEN0_Pos)                 /*!< EPWM_T::AINTEN: IFAIEN0 Mask            */

#define EPWM_AINTEN_IFAIEN1_Pos           (1)                                               /*!< EPWM_T::AINTEN: IFAIEN1 Position        */
#define EPWM_AINTEN_IFAIEN1_Msk           (0x1ul << EPWM_AINTEN_IFAIEN1_Pos)                 /*!< EPWM_T::AINTEN: IFAIEN1 Mask            */

#define EPWM_AINTEN_IFAIEN2_Pos           (2)                                               /*!< EPWM_T::AINTEN: IFAIEN2 Position        */
#define EPWM_AINTEN_IFAIEN2_Msk           (0x1ul << EPWM_AINTEN_IFAIEN2_Pos)                 /*!< EPWM_T::AINTEN: IFAIEN2 Mask            */

#define EPWM_AINTEN_IFAIEN3_Pos           (3)                                               /*!< EPWM_T::AINTEN: IFAIEN3 Position        */
#define EPWM_AINTEN_IFAIEN3_Msk           (0x1ul << EPWM_AINTEN_IFAIEN3_Pos)                 /*!< EPWM_T::AINTEN: IFAIEN3 Mask            */

#define EPWM_AINTEN_IFAIEN4_Pos           (4)                                               /*!< EPWM_T::AINTEN: IFAIEN4 Position        */
#define EPWM_AINTEN_IFAIEN4_Msk           (0x1ul << EPWM_AINTEN_IFAIEN4_Pos)                 /*!< EPWM_T::AINTEN: IFAIEN4 Mask            */

#define EPWM_AINTEN_IFAIEN5_Pos           (5)                                               /*!< EPWM_T::AINTEN: IFAIEN5 Position        */
#define EPWM_AINTEN_IFAIEN5_Msk           (0x1ul << EPWM_AINTEN_IFAIEN5_Pos)                 /*!< EPWM_T::AINTEN: IFAIEN5 Mask            */

#define EPWM_APDMACTL_APDMAEN0_Pos        (0)                                               /*!< EPWM_T::APDMACTL: APDMAEN0 Position     */
#define EPWM_APDMACTL_APDMAEN0_Msk        (0x1ul << EPWM_APDMACTL_APDMAEN0_Pos)              /*!< EPWM_T::APDMACTL: APDMAEN0 Mask         */

#define EPWM_APDMACTL_APDMAEN1_Pos        (1)                                               /*!< EPWM_T::APDMACTL: APDMAEN1 Position     */
#define EPWM_APDMACTL_APDMAEN1_Msk        (0x1ul << EPWM_APDMACTL_APDMAEN1_Pos)              /*!< EPWM_T::APDMACTL: APDMAEN1 Mask         */

#define EPWM_APDMACTL_APDMAEN2_Pos        (2)                                               /*!< EPWM_T::APDMACTL: APDMAEN2 Position     */
#define EPWM_APDMACTL_APDMAEN2_Msk        (0x1ul << EPWM_APDMACTL_APDMAEN2_Pos)              /*!< EPWM_T::APDMACTL: APDMAEN2 Mask         */

#define EPWM_APDMACTL_APDMAEN3_Pos        (3)                                               /*!< EPWM_T::APDMACTL: APDMAEN3 Position     */
#define EPWM_APDMACTL_APDMAEN3_Msk        (0x1ul << EPWM_APDMACTL_APDMAEN3_Pos)              /*!< EPWM_T::APDMACTL: APDMAEN3 Mask         */

#define EPWM_APDMACTL_APDMAEN4_Pos        (4)                                               /*!< EPWM_T::APDMACTL: APDMAEN4 Position     */
#define EPWM_APDMACTL_APDMAEN4_Msk        (0x1ul << EPWM_APDMACTL_APDMAEN4_Pos)              /*!< EPWM_T::APDMACTL: APDMAEN4 Mask         */

#define EPWM_APDMACTL_APDMAEN5_Pos        (5)                                               /*!< EPWM_T::APDMACTL: APDMAEN5 Position     */
#define EPWM_APDMACTL_APDMAEN5_Msk        (0x1ul << EPWM_APDMACTL_APDMAEN5_Pos)              /*!< EPWM_T::APDMACTL: APDMAEN5 Mask         */

#define EPWM_FDEN_FDEN0_Pos               (0)                                               /*!< EPWM_T::FDEN: FDEN0 Position            */
#define EPWM_FDEN_FDEN0_Msk               (0x1ul << EPWM_FDEN_FDEN0_Pos)                     /*!< EPWM_T::FDEN: FDEN0 Mask                */

#define EPWM_FDEN_FDEN1_Pos               (1)                                               /*!< EPWM_T::FDEN: FDEN1 Position            */
#define EPWM_FDEN_FDEN1_Msk               (0x1ul << EPWM_FDEN_FDEN1_Pos)                     /*!< EPWM_T::FDEN: FDEN1 Mask                */

#define EPWM_FDEN_FDEN2_Pos               (2)                                               /*!< EPWM_T::FDEN: FDEN2 Position            */
#define EPWM_FDEN_FDEN2_Msk               (0x1ul << EPWM_FDEN_FDEN2_Pos)                     /*!< EPWM_T::FDEN: FDEN2 Mask                */

#define EPWM_FDEN_FDEN3_Pos               (3)                                               /*!< EPWM_T::FDEN: FDEN3 Position            */
#define EPWM_FDEN_FDEN3_Msk               (0x1ul << EPWM_FDEN_FDEN3_Pos)                     /*!< EPWM_T::FDEN: FDEN3 Mask                */

#define EPWM_FDEN_FDEN4_Pos               (4)                                               /*!< EPWM_T::FDEN: FDEN4 Position            */
#define EPWM_FDEN_FDEN4_Msk               (0x1ul << EPWM_FDEN_FDEN4_Pos)                     /*!< EPWM_T::FDEN: FDEN4 Mask                */

#define EPWM_FDEN_FDEN5_Pos               (5)                                               /*!< EPWM_T::FDEN: FDEN5 Position            */
#define EPWM_FDEN_FDEN5_Msk               (0x1ul << EPWM_FDEN_FDEN5_Pos)                     /*!< EPWM_T::FDEN: FDEN5 Mask                */

#define EPWM_FDEN_FDODIS0_Pos             (8)                                               /*!< EPWM_T::FDEN: FDODIS0 Position          */
#define EPWM_FDEN_FDODIS0_Msk             (0x1ul << EPWM_FDEN_FDODIS0_Pos)                   /*!< EPWM_T::FDEN: FDODIS0 Mask              */

#define EPWM_FDEN_FDODIS1_Pos             (9)                                               /*!< EPWM_T::FDEN: FDODIS1 Position          */
#define EPWM_FDEN_FDODIS1_Msk             (0x1ul << EPWM_FDEN_FDODIS1_Pos)                   /*!< EPWM_T::FDEN: FDODIS1 Mask              */

#define EPWM_FDEN_FDODIS2_Pos             (10)                                              /*!< EPWM_T::FDEN: FDODIS2 Position          */
#define EPWM_FDEN_FDODIS2_Msk             (0x1ul << EPWM_FDEN_FDODIS2_Pos)                   /*!< EPWM_T::FDEN: FDODIS2 Mask              */

#define EPWM_FDEN_FDODIS3_Pos             (11)                                              /*!< EPWM_T::FDEN: FDODIS3 Position          */
#define EPWM_FDEN_FDODIS3_Msk             (0x1ul << EPWM_FDEN_FDODIS3_Pos)                   /*!< EPWM_T::FDEN: FDODIS3 Mask              */

#define EPWM_FDEN_FDODIS4_Pos             (12)                                              /*!< EPWM_T::FDEN: FDODIS4 Position          */
#define EPWM_FDEN_FDODIS4_Msk             (0x1ul << EPWM_FDEN_FDODIS4_Pos)                   /*!< EPWM_T::FDEN: FDODIS4 Mask              */

#define EPWM_FDEN_FDODIS5_Pos             (13)                                              /*!< EPWM_T::FDEN: FDODIS5 Position          */
#define EPWM_FDEN_FDODIS5_Msk             (0x1ul << EPWM_FDEN_FDODIS5_Pos)                   /*!< EPWM_T::FDEN: FDODIS5 Mask              */

#define EPWM_FDEN_FDCKS0_Pos              (16)                                              /*!< EPWM_T::FDEN: FDCKS0 Position           */
#define EPWM_FDEN_FDCKS0_Msk              (0x1ul << EPWM_FDEN_FDCKS0_Pos)                    /*!< EPWM_T::FDEN: FDCKS0 Mask               */

#define EPWM_FDEN_FDCKS1_Pos              (17)                                              /*!< EPWM_T::FDEN: FDCKS1 Position           */
#define EPWM_FDEN_FDCKS1_Msk              (0x1ul << EPWM_FDEN_FDCKS1_Pos)                    /*!< EPWM_T::FDEN: FDCKS1 Mask               */

#define EPWM_FDEN_FDCKS2_Pos              (18)                                              /*!< EPWM_T::FDEN: FDCKS2 Position           */
#define EPWM_FDEN_FDCKS2_Msk              (0x1ul << EPWM_FDEN_FDCKS2_Pos)                    /*!< EPWM_T::FDEN: FDCKS2 Mask               */

#define EPWM_FDEN_FDCKS3_Pos              (19)                                              /*!< EPWM_T::FDEN: FDCKS3 Position           */
#define EPWM_FDEN_FDCKS3_Msk              (0x1ul << EPWM_FDEN_FDCKS3_Pos)                    /*!< EPWM_T::FDEN: FDCKS3 Mask               */

#define EPWM_FDEN_FDCKS4_Pos              (20)                                              /*!< EPWM_T::FDEN: FDCKS4 Position           */
#define EPWM_FDEN_FDCKS4_Msk              (0x1ul << EPWM_FDEN_FDCKS4_Pos)                    /*!< EPWM_T::FDEN: FDCKS4 Mask               */

#define EPWM_FDEN_FDCKS5_Pos              (21)                                              /*!< EPWM_T::FDEN: FDCKS5 Position           */
#define EPWM_FDEN_FDCKS5_Msk              (0x1ul << EPWM_FDEN_FDCKS5_Pos)                    /*!< EPWM_T::FDEN: FDCKS5 Mask               */

#define EPWM_FDCTL0_TRMSKCNT_Pos          (0)                                               /*!< EPWM_T::FDCTL0: TRMSKCNT Position       */
#define EPWM_FDCTL0_TRMSKCNT_Msk          (0x7ful << EPWM_FDCTL0_TRMSKCNT_Pos)               /*!< EPWM_T::FDCTL0: TRMSKCNT Mask           */

#define EPWM_FDCTL0_FDMSKEN_Pos           (15)                                              /*!< EPWM_T::FDCTL0: FDMSKEN Position        */
#define EPWM_FDCTL0_FDMSKEN_Msk           (0x1ul << EPWM_FDCTL0_FDMSKEN_Pos)                 /*!< EPWM_T::FDCTL0: FDMSKEN Mask            */

#define EPWM_FDCTL0_DGSMPCYC_Pos          (16)                                              /*!< EPWM_T::FDCTL0: DGSMPCYC Position       */
#define EPWM_FDCTL0_DGSMPCYC_Msk          (0x7ul << EPWM_FDCTL0_DGSMPCYC_Pos)                /*!< EPWM_T::FDCTL0: DGSMPCYC Mask           */

#define EPWM_FDCTL0_FDCKSEL_Pos           (28)                                              /*!< EPWM_T::FDCTL0: FDCKSEL Position        */
#define EPWM_FDCTL0_FDCKSEL_Msk           (0x3ul << EPWM_FDCTL0_FDCKSEL_Pos)                 /*!< EPWM_T::FDCTL0: FDCKSEL Mask            */

#define EPWM_FDCTL0_FDDGEN_Pos            (31)                                              /*!< EPWM_T::FDCTL0: FDDGEN Position         */
#define EPWM_FDCTL0_FDDGEN_Msk            (0x1ul << EPWM_FDCTL0_FDDGEN_Pos)                  /*!< EPWM_T::FDCTL0: FDDGEN Mask             */

#define EPWM_FDCTL1_TRMSKCNT_Pos          (0)                                               /*!< EPWM_T::FDCTL1: TRMSKCNT Position       */
#define EPWM_FDCTL1_TRMSKCNT_Msk          (0x7ful << EPWM_FDCTL1_TRMSKCNT_Pos)               /*!< EPWM_T::FDCTL1: TRMSKCNT Mask           */

#define EPWM_FDCTL1_FDMSKEN_Pos           (15)                                              /*!< EPWM_T::FDCTL1: FDMSKEN Position        */
#define EPWM_FDCTL1_FDMSKEN_Msk           (0x1ul << EPWM_FDCTL1_FDMSKEN_Pos)                 /*!< EPWM_T::FDCTL1: FDMSKEN Mask            */

#define EPWM_FDCTL1_DGSMPCYC_Pos          (16)                                              /*!< EPWM_T::FDCTL1: DGSMPCYC Position       */
#define EPWM_FDCTL1_DGSMPCYC_Msk          (0x7ul << EPWM_FDCTL1_DGSMPCYC_Pos)                /*!< EPWM_T::FDCTL1: DGSMPCYC Mask           */

#define EPWM_FDCTL1_FDCKSEL_Pos           (28)                                              /*!< EPWM_T::FDCTL1: FDCKSEL Position        */
#define EPWM_FDCTL1_FDCKSEL_Msk           (0x3ul << EPWM_FDCTL1_FDCKSEL_Pos)                 /*!< EPWM_T::FDCTL1: FDCKSEL Mask            */

#define EPWM_FDCTL1_FDDGEN_Pos            (31)                                              /*!< EPWM_T::FDCTL1: FDDGEN Position         */
#define EPWM_FDCTL1_FDDGEN_Msk            (0x1ul << EPWM_FDCTL1_FDDGEN_Pos)                  /*!< EPWM_T::FDCTL1: FDDGEN Mask             */

#define EPWM_FDCTL2_TRMSKCNT_Pos          (0)                                               /*!< EPWM_T::FDCTL2: TRMSKCNT Position       */
#define EPWM_FDCTL2_TRMSKCNT_Msk          (0x7ful << EPWM_FDCTL2_TRMSKCNT_Pos)               /*!< EPWM_T::FDCTL2: TRMSKCNT Mask           */

#define EPWM_FDCTL2_FDMSKEN_Pos           (15)                                              /*!< EPWM_T::FDCTL2: FDMSKEN Position        */
#define EPWM_FDCTL2_FDMSKEN_Msk           (0x1ul << EPWM_FDCTL2_FDMSKEN_Pos)                 /*!< EPWM_T::FDCTL2: FDMSKEN Mask            */

#define EPWM_FDCTL2_DGSMPCYC_Pos          (16)                                              /*!< EPWM_T::FDCTL2: DGSMPCYC Position       */
#define EPWM_FDCTL2_DGSMPCYC_Msk          (0x7ul << EPWM_FDCTL2_DGSMPCYC_Pos)                /*!< EPWM_T::FDCTL2: DGSMPCYC Mask           */

#define EPWM_FDCTL2_FDCKSEL_Pos           (28)                                              /*!< EPWM_T::FDCTL2: FDCKSEL Position        */
#define EPWM_FDCTL2_FDCKSEL_Msk           (0x3ul << EPWM_FDCTL2_FDCKSEL_Pos)                 /*!< EPWM_T::FDCTL2: FDCKSEL Mask            */

#define EPWM_FDCTL2_FDDGEN_Pos            (31)                                              /*!< EPWM_T::FDCTL2: FDDGEN Position         */
#define EPWM_FDCTL2_FDDGEN_Msk            (0x1ul << EPWM_FDCTL2_FDDGEN_Pos)                  /*!< EPWM_T::FDCTL2: FDDGEN Mask             */

#define EPWM_FDCTL3_TRMSKCNT_Pos          (0)                                               /*!< EPWM_T::FDCTL3: TRMSKCNT Position       */
#define EPWM_FDCTL3_TRMSKCNT_Msk          (0x7ful << EPWM_FDCTL3_TRMSKCNT_Pos)               /*!< EPWM_T::FDCTL3: TRMSKCNT Mask           */

#define EPWM_FDCTL3_FDMSKEN_Pos           (15)                                              /*!< EPWM_T::FDCTL3: FDMSKEN Position        */
#define EPWM_FDCTL3_FDMSKEN_Msk           (0x1ul << EPWM_FDCTL3_FDMSKEN_Pos)                 /*!< EPWM_T::FDCTL3: FDMSKEN Mask            */

#define EPWM_FDCTL3_DGSMPCYC_Pos          (16)                                              /*!< EPWM_T::FDCTL3: DGSMPCYC Position       */
#define EPWM_FDCTL3_DGSMPCYC_Msk          (0x7ul << EPWM_FDCTL3_DGSMPCYC_Pos)                /*!< EPWM_T::FDCTL3: DGSMPCYC Mask           */

#define EPWM_FDCTL3_FDCKSEL_Pos           (28)                                              /*!< EPWM_T::FDCTL3: FDCKSEL Position        */
#define EPWM_FDCTL3_FDCKSEL_Msk           (0x3ul << EPWM_FDCTL3_FDCKSEL_Pos)                 /*!< EPWM_T::FDCTL3: FDCKSEL Mask            */

#define EPWM_FDCTL3_FDDGEN_Pos            (31)                                              /*!< EPWM_T::FDCTL3: FDDGEN Position         */
#define EPWM_FDCTL3_FDDGEN_Msk            (0x1ul << EPWM_FDCTL3_FDDGEN_Pos)                  /*!< EPWM_T::FDCTL3: FDDGEN Mask             */

#define EPWM_FDCTL4_TRMSKCNT_Pos          (0)                                               /*!< EPWM_T::FDCTL4: TRMSKCNT Position       */
#define EPWM_FDCTL4_TRMSKCNT_Msk          (0x7ful << EPWM_FDCTL4_TRMSKCNT_Pos)               /*!< EPWM_T::FDCTL4: TRMSKCNT Mask           */

#define EPWM_FDCTL4_FDMSKEN_Pos           (15)                                              /*!< EPWM_T::FDCTL4: FDMSKEN Position        */
#define EPWM_FDCTL4_FDMSKEN_Msk           (0x1ul << EPWM_FDCTL4_FDMSKEN_Pos)                 /*!< EPWM_T::FDCTL4: FDMSKEN Mask            */

#define EPWM_FDCTL4_DGSMPCYC_Pos          (16)                                              /*!< EPWM_T::FDCTL4: DGSMPCYC Position       */
#define EPWM_FDCTL4_DGSMPCYC_Msk          (0x7ul << EPWM_FDCTL4_DGSMPCYC_Pos)                /*!< EPWM_T::FDCTL4: DGSMPCYC Mask           */

#define EPWM_FDCTL4_FDCKSEL_Pos           (28)                                              /*!< EPWM_T::FDCTL4: FDCKSEL Position        */
#define EPWM_FDCTL4_FDCKSEL_Msk           (0x3ul << EPWM_FDCTL4_FDCKSEL_Pos)                 /*!< EPWM_T::FDCTL4: FDCKSEL Mask            */

#define EPWM_FDCTL4_FDDGEN_Pos            (31)                                              /*!< EPWM_T::FDCTL4: FDDGEN Position         */
#define EPWM_FDCTL4_FDDGEN_Msk            (0x1ul << EPWM_FDCTL4_FDDGEN_Pos)                  /*!< EPWM_T::FDCTL4: FDDGEN Mask             */

#define EPWM_FDCTL5_TRMSKCNT_Pos          (0)                                               /*!< EPWM_T::FDCTL5: TRMSKCNT Position       */
#define EPWM_FDCTL5_TRMSKCNT_Msk          (0x7ful << EPWM_FDCTL5_TRMSKCNT_Pos)               /*!< EPWM_T::FDCTL5: TRMSKCNT Mask           */

#define EPWM_FDCTL5_FDMSKEN_Pos           (15)                                              /*!< EPWM_T::FDCTL5: FDMSKEN Position        */
#define EPWM_FDCTL5_FDMSKEN_Msk           (0x1ul << EPWM_FDCTL5_FDMSKEN_Pos)                 /*!< EPWM_T::FDCTL5: FDMSKEN Mask            */

#define EPWM_FDCTL5_DGSMPCYC_Pos          (16)                                              /*!< EPWM_T::FDCTL5: DGSMPCYC Position       */
#define EPWM_FDCTL5_DGSMPCYC_Msk          (0x7ul << EPWM_FDCTL5_DGSMPCYC_Pos)                /*!< EPWM_T::FDCTL5: DGSMPCYC Mask           */

#define EPWM_FDCTL5_FDCKSEL_Pos           (28)                                              /*!< EPWM_T::FDCTL5: FDCKSEL Position        */
#define EPWM_FDCTL5_FDCKSEL_Msk           (0x3ul << EPWM_FDCTL5_FDCKSEL_Pos)                 /*!< EPWM_T::FDCTL5: FDCKSEL Mask            */

#define EPWM_FDCTL5_FDDGEN_Pos            (31)                                              /*!< EPWM_T::FDCTL5: FDDGEN Position         */
#define EPWM_FDCTL5_FDDGEN_Msk            (0x1ul << EPWM_FDCTL5_FDDGEN_Pos)                  /*!< EPWM_T::FDCTL5: FDDGEN Mask             */

#define EPWM_FDIEN_FDIEN0_Pos             (0)                                               /*!< EPWM_T::FDIEN: FDIEN0 Position          */
#define EPWM_FDIEN_FDIEN0_Msk             (0x1ul << EPWM_FDIEN_FDIEN0_Pos)                   /*!< EPWM_T::FDIEN: FDIEN0 Mask              */

#define EPWM_FDIEN_FDIEN1_Pos             (1)                                               /*!< EPWM_T::FDIEN: FDIEN1 Position          */
#define EPWM_FDIEN_FDIEN1_Msk             (0x1ul << EPWM_FDIEN_FDIEN1_Pos)                   /*!< EPWM_T::FDIEN: FDIEN1 Mask              */

#define EPWM_FDIEN_FDIEN2_Pos             (2)                                               /*!< EPWM_T::FDIEN: FDIEN2 Position          */
#define EPWM_FDIEN_FDIEN2_Msk             (0x1ul << EPWM_FDIEN_FDIEN2_Pos)                   /*!< EPWM_T::FDIEN: FDIEN2 Mask              */

#define EPWM_FDIEN_FDIEN3_Pos             (3)                                               /*!< EPWM_T::FDIEN: FDIEN3 Position          */
#define EPWM_FDIEN_FDIEN3_Msk             (0x1ul << EPWM_FDIEN_FDIEN3_Pos)                   /*!< EPWM_T::FDIEN: FDIEN3 Mask              */

#define EPWM_FDIEN_FDIEN4_Pos             (4)                                               /*!< EPWM_T::FDIEN: FDIEN4 Position          */
#define EPWM_FDIEN_FDIEN4_Msk             (0x1ul << EPWM_FDIEN_FDIEN4_Pos)                   /*!< EPWM_T::FDIEN: FDIEN4 Mask              */

#define EPWM_FDIEN_FDIEN5_Pos             (5)                                               /*!< EPWM_T::FDIEN: FDIEN5 Position          */
#define EPWM_FDIEN_FDIEN5_Msk             (0x1ul << EPWM_FDIEN_FDIEN5_Pos)                   /*!< EPWM_T::FDIEN: FDIEN5 Mask              */

#define EPWM_FDSTS_FDIF0_Pos              (0)                                               /*!< EPWM_T::FDSTS: FDIF0 Position           */
#define EPWM_FDSTS_FDIF0_Msk              (0x1ul << EPWM_FDSTS_FDIF0_Pos)                    /*!< EPWM_T::FDSTS: FDIF0 Mask               */

#define EPWM_FDSTS_FDIF1_Pos              (1)                                               /*!< EPWM_T::FDSTS: FDIF1 Position           */
#define EPWM_FDSTS_FDIF1_Msk              (0x1ul << EPWM_FDSTS_FDIF1_Pos)                    /*!< EPWM_T::FDSTS: FDIF1 Mask               */

#define EPWM_FDSTS_FDIF2_Pos              (2)                                               /*!< EPWM_T::FDSTS: FDIF2 Position           */
#define EPWM_FDSTS_FDIF2_Msk              (0x1ul << EPWM_FDSTS_FDIF2_Pos)                    /*!< EPWM_T::FDSTS: FDIF2 Mask               */

#define EPWM_FDSTS_FDIF3_Pos              (3)                                               /*!< EPWM_T::FDSTS: FDIF3 Position           */
#define EPWM_FDSTS_FDIF3_Msk              (0x1ul << EPWM_FDSTS_FDIF3_Pos)                    /*!< EPWM_T::FDSTS: FDIF3 Mask               */

#define EPWM_FDSTS_FDIF4_Pos              (4)                                               /*!< EPWM_T::FDSTS: FDIF4 Position           */
#define EPWM_FDSTS_FDIF4_Msk              (0x1ul << EPWM_FDSTS_FDIF4_Pos)                    /*!< EPWM_T::FDSTS: FDIF4 Mask               */

#define EPWM_FDSTS_FDIF5_Pos              (5)                                               /*!< EPWM_T::FDSTS: FDIF5 Position           */
#define EPWM_FDSTS_FDIF5_Msk              (0x1ul << EPWM_FDSTS_FDIF5_Pos)                    /*!< EPWM_T::FDSTS: FDIF5 Mask               */

#define EPWM_EADCPSCCTL_PSCEN0_Pos        (0)                                               /*!< EPWM_T::EADCPSCCTL: PSCEN0 Position     */
#define EPWM_EADCPSCCTL_PSCEN0_Msk        (0x1ul << EPWM_EADCPSCCTL_PSCEN0_Pos)              /*!< EPWM_T::EADCPSCCTL: PSCEN0 Mask         */

#define EPWM_EADCPSCCTL_PSCEN1_Pos        (1)                                               /*!< EPWM_T::EADCPSCCTL: PSCEN1 Position     */
#define EPWM_EADCPSCCTL_PSCEN1_Msk        (0x1ul << EPWM_EADCPSCCTL_PSCEN1_Pos)              /*!< EPWM_T::EADCPSCCTL: PSCEN1 Mask         */

#define EPWM_EADCPSCCTL_PSCEN2_Pos        (2)                                               /*!< EPWM_T::EADCPSCCTL: PSCEN2 Position     */
#define EPWM_EADCPSCCTL_PSCEN2_Msk        (0x1ul << EPWM_EADCPSCCTL_PSCEN2_Pos)              /*!< EPWM_T::EADCPSCCTL: PSCEN2 Mask         */

#define EPWM_EADCPSCCTL_PSCEN3_Pos        (3)                                               /*!< EPWM_T::EADCPSCCTL: PSCEN3 Position     */
#define EPWM_EADCPSCCTL_PSCEN3_Msk        (0x1ul << EPWM_EADCPSCCTL_PSCEN3_Pos)              /*!< EPWM_T::EADCPSCCTL: PSCEN3 Mask         */

#define EPWM_EADCPSCCTL_PSCEN4_Pos        (4)                                               /*!< EPWM_T::EADCPSCCTL: PSCEN4 Position     */
#define EPWM_EADCPSCCTL_PSCEN4_Msk        (0x1ul << EPWM_EADCPSCCTL_PSCEN4_Pos)              /*!< EPWM_T::EADCPSCCTL: PSCEN4 Mask         */

#define EPWM_EADCPSCCTL_PSCEN5_Pos        (5)                                               /*!< EPWM_T::EADCPSCCTL: PSCEN5 Position     */
#define EPWM_EADCPSCCTL_PSCEN5_Msk        (0x1ul << EPWM_EADCPSCCTL_PSCEN5_Pos)              /*!< EPWM_T::EADCPSCCTL: PSCEN5 Mask         */

#define EPWM_EADCPSC0_EADCPSC0_Pos        (0)                                               /*!< EPWM_T::EADCPSC0: EADCPSC0 Position     */
#define EPWM_EADCPSC0_EADCPSC0_Msk        (0xful << EPWM_EADCPSC0_EADCPSC0_Pos)              /*!< EPWM_T::EADCPSC0: EADCPSC0 Mask         */

#define EPWM_EADCPSC0_EADCPSC1_Pos        (8)                                               /*!< EPWM_T::EADCPSC0: EADCPSC1 Position     */
#define EPWM_EADCPSC0_EADCPSC1_Msk        (0xful << EPWM_EADCPSC0_EADCPSC1_Pos)              /*!< EPWM_T::EADCPSC0: EADCPSC1 Mask         */

#define EPWM_EADCPSC0_EADCPSC2_Pos        (16)                                              /*!< EPWM_T::EADCPSC0: EADCPSC2 Position     */
#define EPWM_EADCPSC0_EADCPSC2_Msk        (0xful << EPWM_EADCPSC0_EADCPSC2_Pos)              /*!< EPWM_T::EADCPSC0: EADCPSC2 Mask         */

#define EPWM_EADCPSC0_EADCPSC3_Pos        (24)                                              /*!< EPWM_T::EADCPSC0: EADCPSC3 Position     */
#define EPWM_EADCPSC0_EADCPSC3_Msk        (0xful << EPWM_EADCPSC0_EADCPSC3_Pos)              /*!< EPWM_T::EADCPSC0: EADCPSC3 Mask         */

#define EPWM_EADCPSC1_EADCPSC4_Pos        (0)                                               /*!< EPWM_T::EADCPSC1: EADCPSC4 Position     */
#define EPWM_EADCPSC1_EADCPSC4_Msk        (0xful << EPWM_EADCPSC1_EADCPSC4_Pos)              /*!< EPWM_T::EADCPSC1: EADCPSC4 Mask         */

#define EPWM_EADCPSC1_EADCPSC5_Pos        (8)                                               /*!< EPWM_T::EADCPSC1: EADCPSC5 Position     */
#define EPWM_EADCPSC1_EADCPSC5_Msk        (0xful << EPWM_EADCPSC1_EADCPSC5_Pos)              /*!< EPWM_T::EADCPSC1: EADCPSC5 Mask         */

#define EPWM_EADCPSCNT0_PSCNT0_Pos        (0)                                               /*!< EPWM_T::EADCPSCNT0: PSCNT0 Position     */
#define EPWM_EADCPSCNT0_PSCNT0_Msk        (0xful << EPWM_EADCPSCNT0_PSCNT0_Pos)              /*!< EPWM_T::EADCPSCNT0: PSCNT0 Mask         */

#define EPWM_EADCPSCNT0_PSCNT1_Pos        (8)                                               /*!< EPWM_T::EADCPSCNT0: PSCNT1 Position     */
#define EPWM_EADCPSCNT0_PSCNT1_Msk        (0xful << EPWM_EADCPSCNT0_PSCNT1_Pos)              /*!< EPWM_T::EADCPSCNT0: PSCNT1 Mask         */

#define EPWM_EADCPSCNT0_PSCNT2_Pos        (16)                                              /*!< EPWM_T::EADCPSCNT0: PSCNT2 Position     */
#define EPWM_EADCPSCNT0_PSCNT2_Msk        (0xful << EPWM_EADCPSCNT0_PSCNT2_Pos)              /*!< EPWM_T::EADCPSCNT0: PSCNT2 Mask         */

#define EPWM_EADCPSCNT0_PSCNT3_Pos        (24)                                              /*!< EPWM_T::EADCPSCNT0: PSCNT3 Position     */
#define EPWM_EADCPSCNT0_PSCNT3_Msk        (0xful << EPWM_EADCPSCNT0_PSCNT3_Pos)              /*!< EPWM_T::EADCPSCNT0: PSCNT3 Mask         */

#define EPWM_EADCPSCNT1_PSCNT4_Pos        (0)                                               /*!< EPWM_T::EADCPSCNT1: PSCNT4 Position     */
#define EPWM_EADCPSCNT1_PSCNT4_Msk        (0xful << EPWM_EADCPSCNT1_PSCNT4_Pos)              /*!< EPWM_T::EADCPSCNT1: PSCNT4 Mask         */

#define EPWM_EADCPSCNT1_PSCNT5_Pos        (8)                                               /*!< EPWM_T::EADCPSCNT1: PSCNT5 Position     */
#define EPWM_EADCPSCNT1_PSCNT5_Msk        (0xful << EPWM_EADCPSCNT1_PSCNT5_Pos)              /*!< EPWM_T::EADCPSCNT1: PSCNT5 Mask         */

#define EPWM_CAPINEN_CAPINEN0_Pos         (0)                                               /*!< EPWM_T::CAPINEN: CAPINEN0 Position      */
#define EPWM_CAPINEN_CAPINEN0_Msk         (0x1ul << EPWM_CAPINEN_CAPINEN0_Pos)               /*!< EPWM_T::CAPINEN: CAPINEN0 Mask          */

#define EPWM_CAPINEN_CAPINEN1_Pos         (1)                                               /*!< EPWM_T::CAPINEN: CAPINEN1 Position      */
#define EPWM_CAPINEN_CAPINEN1_Msk         (0x1ul << EPWM_CAPINEN_CAPINEN1_Pos)               /*!< EPWM_T::CAPINEN: CAPINEN1 Mask          */

#define EPWM_CAPINEN_CAPINEN2_Pos         (2)                                               /*!< EPWM_T::CAPINEN: CAPINEN2 Position      */
#define EPWM_CAPINEN_CAPINEN2_Msk         (0x1ul << EPWM_CAPINEN_CAPINEN2_Pos)               /*!< EPWM_T::CAPINEN: CAPINEN2 Mask          */

#define EPWM_CAPINEN_CAPINEN3_Pos         (3)                                               /*!< EPWM_T::CAPINEN: CAPINEN3 Position      */
#define EPWM_CAPINEN_CAPINEN3_Msk         (0x1ul << EPWM_CAPINEN_CAPINEN3_Pos)               /*!< EPWM_T::CAPINEN: CAPINEN3 Mask          */

#define EPWM_CAPINEN_CAPINEN4_Pos         (4)                                               /*!< EPWM_T::CAPINEN: CAPINEN4 Position      */
#define EPWM_CAPINEN_CAPINEN4_Msk         (0x1ul << EPWM_CAPINEN_CAPINEN4_Pos)               /*!< EPWM_T::CAPINEN: CAPINEN4 Mask          */

#define EPWM_CAPINEN_CAPINEN5_Pos         (5)                                               /*!< EPWM_T::CAPINEN: CAPINEN5 Position      */
#define EPWM_CAPINEN_CAPINEN5_Msk         (0x1ul << EPWM_CAPINEN_CAPINEN5_Pos)               /*!< EPWM_T::CAPINEN: CAPINEN5 Mask          */

#define EPWM_CAPCTL_CAPEN0_Pos            (0)                                               /*!< EPWM_T::CAPCTL: CAPEN0 Position         */
#define EPWM_CAPCTL_CAPEN0_Msk            (0x1ul << EPWM_CAPCTL_CAPEN0_Pos)                  /*!< EPWM_T::CAPCTL: CAPEN0 Mask             */

#define EPWM_CAPCTL_CAPEN1_Pos            (1)                                               /*!< EPWM_T::CAPCTL: CAPEN1 Position         */
#define EPWM_CAPCTL_CAPEN1_Msk            (0x1ul << EPWM_CAPCTL_CAPEN1_Pos)                  /*!< EPWM_T::CAPCTL: CAPEN1 Mask             */

#define EPWM_CAPCTL_CAPEN2_Pos            (2)                                               /*!< EPWM_T::CAPCTL: CAPEN2 Position         */
#define EPWM_CAPCTL_CAPEN2_Msk            (0x1ul << EPWM_CAPCTL_CAPEN2_Pos)                  /*!< EPWM_T::CAPCTL: CAPEN2 Mask             */

#define EPWM_CAPCTL_CAPEN3_Pos            (3)                                               /*!< EPWM_T::CAPCTL: CAPEN3 Position         */
#define EPWM_CAPCTL_CAPEN3_Msk            (0x1ul << EPWM_CAPCTL_CAPEN3_Pos)                  /*!< EPWM_T::CAPCTL: CAPEN3 Mask             */

#define EPWM_CAPCTL_CAPEN4_Pos            (4)                                               /*!< EPWM_T::CAPCTL: CAPEN4 Position         */
#define EPWM_CAPCTL_CAPEN4_Msk            (0x1ul << EPWM_CAPCTL_CAPEN4_Pos)                  /*!< EPWM_T::CAPCTL: CAPEN4 Mask             */

#define EPWM_CAPCTL_CAPEN5_Pos            (5)                                               /*!< EPWM_T::CAPCTL: CAPEN5 Position         */
#define EPWM_CAPCTL_CAPEN5_Msk            (0x1ul << EPWM_CAPCTL_CAPEN5_Pos)                  /*!< EPWM_T::CAPCTL: CAPEN5 Mask             */

#define EPWM_CAPCTL_CAPINV0_Pos           (8)                                               /*!< EPWM_T::CAPCTL: CAPINV0 Position        */
#define EPWM_CAPCTL_CAPINV0_Msk           (0x1ul << EPWM_CAPCTL_CAPINV0_Pos)                 /*!< EPWM_T::CAPCTL: CAPINV0 Mask            */

#define EPWM_CAPCTL_CAPINV1_Pos           (9)                                               /*!< EPWM_T::CAPCTL: CAPINV1 Position        */
#define EPWM_CAPCTL_CAPINV1_Msk           (0x1ul << EPWM_CAPCTL_CAPINV1_Pos)                 /*!< EPWM_T::CAPCTL: CAPINV1 Mask            */

#define EPWM_CAPCTL_CAPINV2_Pos           (10)                                              /*!< EPWM_T::CAPCTL: CAPINV2 Position        */
#define EPWM_CAPCTL_CAPINV2_Msk           (0x1ul << EPWM_CAPCTL_CAPINV2_Pos)                 /*!< EPWM_T::CAPCTL: CAPINV2 Mask            */

#define EPWM_CAPCTL_CAPINV3_Pos           (11)                                              /*!< EPWM_T::CAPCTL: CAPINV3 Position        */
#define EPWM_CAPCTL_CAPINV3_Msk           (0x1ul << EPWM_CAPCTL_CAPINV3_Pos)                 /*!< EPWM_T::CAPCTL: CAPINV3 Mask            */

#define EPWM_CAPCTL_CAPINV4_Pos           (12)                                              /*!< EPWM_T::CAPCTL: CAPINV4 Position        */
#define EPWM_CAPCTL_CAPINV4_Msk           (0x1ul << EPWM_CAPCTL_CAPINV4_Pos)                 /*!< EPWM_T::CAPCTL: CAPINV4 Mask            */

#define EPWM_CAPCTL_CAPINV5_Pos           (13)                                              /*!< EPWM_T::CAPCTL: CAPINV5 Position        */
#define EPWM_CAPCTL_CAPINV5_Msk           (0x1ul << EPWM_CAPCTL_CAPINV5_Pos)                 /*!< EPWM_T::CAPCTL: CAPINV5 Mask            */

#define EPWM_CAPCTL_RCRLDEN0_Pos          (16)                                              /*!< EPWM_T::CAPCTL: RCRLDEN0 Position       */
#define EPWM_CAPCTL_RCRLDEN0_Msk          (0x1ul << EPWM_CAPCTL_RCRLDEN0_Pos)                /*!< EPWM_T::CAPCTL: RCRLDEN0 Mask           */

#define EPWM_CAPCTL_RCRLDEN1_Pos          (17)                                              /*!< EPWM_T::CAPCTL: RCRLDEN1 Position       */
#define EPWM_CAPCTL_RCRLDEN1_Msk          (0x1ul << EPWM_CAPCTL_RCRLDEN1_Pos)                /*!< EPWM_T::CAPCTL: RCRLDEN1 Mask           */

#define EPWM_CAPCTL_RCRLDEN2_Pos          (18)                                              /*!< EPWM_T::CAPCTL: RCRLDEN2 Position       */
#define EPWM_CAPCTL_RCRLDEN2_Msk          (0x1ul << EPWM_CAPCTL_RCRLDEN2_Pos)                /*!< EPWM_T::CAPCTL: RCRLDEN2 Mask           */

#define EPWM_CAPCTL_RCRLDEN3_Pos          (19)                                              /*!< EPWM_T::CAPCTL: RCRLDEN3 Position       */
#define EPWM_CAPCTL_RCRLDEN3_Msk          (0x1ul << EPWM_CAPCTL_RCRLDEN3_Pos)                /*!< EPWM_T::CAPCTL: RCRLDEN3 Mask           */

#define EPWM_CAPCTL_RCRLDEN4_Pos          (20)                                              /*!< EPWM_T::CAPCTL: RCRLDEN4 Position       */
#define EPWM_CAPCTL_RCRLDEN4_Msk          (0x1ul << EPWM_CAPCTL_RCRLDEN4_Pos)                /*!< EPWM_T::CAPCTL: RCRLDEN4 Mask           */

#define EPWM_CAPCTL_RCRLDEN5_Pos          (21)                                              /*!< EPWM_T::CAPCTL: RCRLDEN5 Position       */
#define EPWM_CAPCTL_RCRLDEN5_Msk          (0x1ul << EPWM_CAPCTL_RCRLDEN5_Pos)                /*!< EPWM_T::CAPCTL: RCRLDEN5 Mask           */

#define EPWM_CAPCTL_FCRLDEN0_Pos          (24)                                              /*!< EPWM_T::CAPCTL: FCRLDEN0 Position       */
#define EPWM_CAPCTL_FCRLDEN0_Msk          (0x1ul << EPWM_CAPCTL_FCRLDEN0_Pos)                /*!< EPWM_T::CAPCTL: FCRLDEN0 Mask           */

#define EPWM_CAPCTL_FCRLDEN1_Pos          (25)                                              /*!< EPWM_T::CAPCTL: FCRLDEN1 Position       */
#define EPWM_CAPCTL_FCRLDEN1_Msk          (0x1ul << EPWM_CAPCTL_FCRLDEN1_Pos)                /*!< EPWM_T::CAPCTL: FCRLDEN1 Mask           */

#define EPWM_CAPCTL_FCRLDEN2_Pos          (26)                                              /*!< EPWM_T::CAPCTL: FCRLDEN2 Position       */
#define EPWM_CAPCTL_FCRLDEN2_Msk          (0x1ul << EPWM_CAPCTL_FCRLDEN2_Pos)                /*!< EPWM_T::CAPCTL: FCRLDEN2 Mask           */

#define EPWM_CAPCTL_FCRLDEN3_Pos          (27)                                              /*!< EPWM_T::CAPCTL: FCRLDEN3 Position       */
#define EPWM_CAPCTL_FCRLDEN3_Msk          (0x1ul << EPWM_CAPCTL_FCRLDEN3_Pos)                /*!< EPWM_T::CAPCTL: FCRLDEN3 Mask           */

#define EPWM_CAPCTL_FCRLDEN4_Pos          (28)                                              /*!< EPWM_T::CAPCTL: FCRLDEN4 Position       */
#define EPWM_CAPCTL_FCRLDEN4_Msk          (0x1ul << EPWM_CAPCTL_FCRLDEN4_Pos)                /*!< EPWM_T::CAPCTL: FCRLDEN4 Mask           */

#define EPWM_CAPCTL_FCRLDEN5_Pos          (29)                                              /*!< EPWM_T::CAPCTL: FCRLDEN5 Position       */
#define EPWM_CAPCTL_FCRLDEN5_Msk          (0x1ul << EPWM_CAPCTL_FCRLDEN5_Pos)                /*!< EPWM_T::CAPCTL: FCRLDEN5 Mask           */

#define EPWM_CAPSTS_CRLIFOV0_Pos          (0)                                               /*!< EPWM_T::CAPSTS: CRLIFOV0 Position       */
#define EPWM_CAPSTS_CRLIFOV0_Msk          (0x1ul << EPWM_CAPSTS_CRLIFOV0_Pos)                /*!< EPWM_T::CAPSTS: CRLIFOV0 Mask           */

#define EPWM_CAPSTS_CRLIFOV1_Pos          (1)                                               /*!< EPWM_T::CAPSTS: CRLIFOV1 Position       */
#define EPWM_CAPSTS_CRLIFOV1_Msk          (0x1ul << EPWM_CAPSTS_CRLIFOV1_Pos)                /*!< EPWM_T::CAPSTS: CRLIFOV1 Mask           */

#define EPWM_CAPSTS_CRLIFOV2_Pos          (2)                                               /*!< EPWM_T::CAPSTS: CRLIFOV2 Position       */
#define EPWM_CAPSTS_CRLIFOV2_Msk          (0x1ul << EPWM_CAPSTS_CRLIFOV2_Pos)                /*!< EPWM_T::CAPSTS: CRLIFOV2 Mask           */

#define EPWM_CAPSTS_CRLIFOV3_Pos          (3)                                               /*!< EPWM_T::CAPSTS: CRLIFOV3 Position       */
#define EPWM_CAPSTS_CRLIFOV3_Msk          (0x1ul << EPWM_CAPSTS_CRLIFOV3_Pos)                /*!< EPWM_T::CAPSTS: CRLIFOV3 Mask           */

#define EPWM_CAPSTS_CRLIFOV4_Pos          (4)                                               /*!< EPWM_T::CAPSTS: CRLIFOV4 Position       */
#define EPWM_CAPSTS_CRLIFOV4_Msk          (0x1ul << EPWM_CAPSTS_CRLIFOV4_Pos)                /*!< EPWM_T::CAPSTS: CRLIFOV4 Mask           */

#define EPWM_CAPSTS_CRLIFOV5_Pos          (5)                                               /*!< EPWM_T::CAPSTS: CRLIFOV5 Position       */
#define EPWM_CAPSTS_CRLIFOV5_Msk          (0x1ul << EPWM_CAPSTS_CRLIFOV5_Pos)                /*!< EPWM_T::CAPSTS: CRLIFOV5 Mask           */

#define EPWM_CAPSTS_CFLIFOV0_Pos          (8)                                               /*!< EPWM_T::CAPSTS: CFLIFOV0 Position       */
#define EPWM_CAPSTS_CFLIFOV0_Msk          (0x1ul << EPWM_CAPSTS_CFLIFOV0_Pos)                /*!< EPWM_T::CAPSTS: CFLIFOV0 Mask           */

#define EPWM_CAPSTS_CFLIFOV1_Pos          (9)                                               /*!< EPWM_T::CAPSTS: CFLIFOV1 Position       */
#define EPWM_CAPSTS_CFLIFOV1_Msk          (0x1ul << EPWM_CAPSTS_CFLIFOV1_Pos)                /*!< EPWM_T::CAPSTS: CFLIFOV1 Mask           */

#define EPWM_CAPSTS_CFLIFOV2_Pos          (10)                                              /*!< EPWM_T::CAPSTS: CFLIFOV2 Position       */
#define EPWM_CAPSTS_CFLIFOV2_Msk          (0x1ul << EPWM_CAPSTS_CFLIFOV2_Pos)                /*!< EPWM_T::CAPSTS: CFLIFOV2 Mask           */

#define EPWM_CAPSTS_CFLIFOV3_Pos          (11)                                              /*!< EPWM_T::CAPSTS: CFLIFOV3 Position       */
#define EPWM_CAPSTS_CFLIFOV3_Msk          (0x1ul << EPWM_CAPSTS_CFLIFOV3_Pos)                /*!< EPWM_T::CAPSTS: CFLIFOV3 Mask           */

#define EPWM_CAPSTS_CFLIFOV4_Pos          (12)                                              /*!< EPWM_T::CAPSTS: CFLIFOV4 Position       */
#define EPWM_CAPSTS_CFLIFOV4_Msk          (0x1ul << EPWM_CAPSTS_CFLIFOV4_Pos)                /*!< EPWM_T::CAPSTS: CFLIFOV4 Mask           */

#define EPWM_CAPSTS_CFLIFOV5_Pos          (13)                                              /*!< EPWM_T::CAPSTS: CFLIFOV5 Position       */
#define EPWM_CAPSTS_CFLIFOV5_Msk          (0x1ul << EPWM_CAPSTS_CFLIFOV5_Pos)                /*!< EPWM_T::CAPSTS: CFLIFOV5 Mask           */

#define EPWM_RCAPDAT0_RCAPDAT_Pos         (0)                                               /*!< EPWM_T::RCAPDAT0: RCAPDAT Position      */
#define EPWM_RCAPDAT0_RCAPDAT_Msk         (0xfffful << EPWM_RCAPDAT0_RCAPDAT_Pos)            /*!< EPWM_T::RCAPDAT0: RCAPDAT Mask          */

#define EPWM_FCAPDAT0_FCAPDAT_Pos         (0)                                               /*!< EPWM_T::FCAPDAT0: FCAPDAT Position      */
#define EPWM_FCAPDAT0_FCAPDAT_Msk         (0xfffful << EPWM_FCAPDAT0_FCAPDAT_Pos)            /*!< EPWM_T::FCAPDAT0: FCAPDAT Mask          */

#define EPWM_RCAPDAT1_RCAPDAT_Pos         (0)                                               /*!< EPWM_T::RCAPDAT1: RCAPDAT Position      */
#define EPWM_RCAPDAT1_RCAPDAT_Msk         (0xfffful << EPWM_RCAPDAT1_RCAPDAT_Pos)            /*!< EPWM_T::RCAPDAT1: RCAPDAT Mask          */

#define EPWM_FCAPDAT1_FCAPDAT_Pos         (0)                                               /*!< EPWM_T::FCAPDAT1: FCAPDAT Position      */
#define EPWM_FCAPDAT1_FCAPDAT_Msk         (0xfffful << EPWM_FCAPDAT1_FCAPDAT_Pos)            /*!< EPWM_T::FCAPDAT1: FCAPDAT Mask          */

#define EPWM_RCAPDAT2_RCAPDAT_Pos         (0)                                               /*!< EPWM_T::RCAPDAT2: RCAPDAT Position      */
#define EPWM_RCAPDAT2_RCAPDAT_Msk         (0xfffful << EPWM_RCAPDAT2_RCAPDAT_Pos)            /*!< EPWM_T::RCAPDAT2: RCAPDAT Mask          */

#define EPWM_FCAPDAT2_FCAPDAT_Pos         (0)                                               /*!< EPWM_T::FCAPDAT2: FCAPDAT Position      */
#define EPWM_FCAPDAT2_FCAPDAT_Msk         (0xfffful << EPWM_FCAPDAT2_FCAPDAT_Pos)            /*!< EPWM_T::FCAPDAT2: FCAPDAT Mask          */

#define EPWM_RCAPDAT3_RCAPDAT_Pos         (0)                                               /*!< EPWM_T::RCAPDAT3: RCAPDAT Position      */
#define EPWM_RCAPDAT3_RCAPDAT_Msk         (0xfffful << EPWM_RCAPDAT3_RCAPDAT_Pos)            /*!< EPWM_T::RCAPDAT3: RCAPDAT Mask          */

#define EPWM_FCAPDAT3_FCAPDAT_Pos         (0)                                               /*!< EPWM_T::FCAPDAT3: FCAPDAT Position      */
#define EPWM_FCAPDAT3_FCAPDAT_Msk         (0xfffful << EPWM_FCAPDAT3_FCAPDAT_Pos)            /*!< EPWM_T::FCAPDAT3: FCAPDAT Mask          */

#define EPWM_RCAPDAT4_RCAPDAT_Pos         (0)                                               /*!< EPWM_T::RCAPDAT4: RCAPDAT Position      */
#define EPWM_RCAPDAT4_RCAPDAT_Msk         (0xfffful << EPWM_RCAPDAT4_RCAPDAT_Pos)            /*!< EPWM_T::RCAPDAT4: RCAPDAT Mask          */

#define EPWM_FCAPDAT4_FCAPDAT_Pos         (0)                                               /*!< EPWM_T::FCAPDAT4: FCAPDAT Position      */
#define EPWM_FCAPDAT4_FCAPDAT_Msk         (0xfffful << EPWM_FCAPDAT4_FCAPDAT_Pos)            /*!< EPWM_T::FCAPDAT4: FCAPDAT Mask          */

#define EPWM_RCAPDAT5_RCAPDAT_Pos         (0)                                               /*!< EPWM_T::RCAPDAT5: RCAPDAT Position      */
#define EPWM_RCAPDAT5_RCAPDAT_Msk         (0xfffful << EPWM_RCAPDAT5_RCAPDAT_Pos)            /*!< EPWM_T::RCAPDAT5: RCAPDAT Mask          */

#define EPWM_FCAPDAT5_FCAPDAT_Pos         (0)                                               /*!< EPWM_T::FCAPDAT5: FCAPDAT Position      */
#define EPWM_FCAPDAT5_FCAPDAT_Msk         (0xfffful << EPWM_FCAPDAT5_FCAPDAT_Pos)            /*!< EPWM_T::FCAPDAT5: FCAPDAT Mask          */

#define EPWM_PDMACTL_CHEN0_1_Pos          (0)                                               /*!< EPWM_T::PDMACTL: CHEN0_1 Position       */
#define EPWM_PDMACTL_CHEN0_1_Msk          (0x1ul << EPWM_PDMACTL_CHEN0_1_Pos)                /*!< EPWM_T::PDMACTL: CHEN0_1 Mask           */

#define EPWM_PDMACTL_CAPMOD0_1_Pos        (1)                                               /*!< EPWM_T::PDMACTL: CAPMOD0_1 Position     */
#define EPWM_PDMACTL_CAPMOD0_1_Msk        (0x3ul << EPWM_PDMACTL_CAPMOD0_1_Pos)              /*!< EPWM_T::PDMACTL: CAPMOD0_1 Mask         */

#define EPWM_PDMACTL_CAPORD0_1_Pos        (3)                                               /*!< EPWM_T::PDMACTL: CAPORD0_1 Position     */
#define EPWM_PDMACTL_CAPORD0_1_Msk        (0x1ul << EPWM_PDMACTL_CAPORD0_1_Pos)              /*!< EPWM_T::PDMACTL: CAPORD0_1 Mask         */

#define EPWM_PDMACTL_CHSEL0_1_Pos         (4)                                               /*!< EPWM_T::PDMACTL: CHSEL0_1 Position      */
#define EPWM_PDMACTL_CHSEL0_1_Msk         (0x1ul << EPWM_PDMACTL_CHSEL0_1_Pos)               /*!< EPWM_T::PDMACTL: CHSEL0_1 Mask          */

#define EPWM_PDMACTL_CHEN2_3_Pos          (8)                                               /*!< EPWM_T::PDMACTL: CHEN2_3 Position       */
#define EPWM_PDMACTL_CHEN2_3_Msk          (0x1ul << EPWM_PDMACTL_CHEN2_3_Pos)                /*!< EPWM_T::PDMACTL: CHEN2_3 Mask           */

#define EPWM_PDMACTL_CAPMOD2_3_Pos        (9)                                               /*!< EPWM_T::PDMACTL: CAPMOD2_3 Position     */
#define EPWM_PDMACTL_CAPMOD2_3_Msk        (0x3ul << EPWM_PDMACTL_CAPMOD2_3_Pos)              /*!< EPWM_T::PDMACTL: CAPMOD2_3 Mask         */

#define EPWM_PDMACTL_CAPORD2_3_Pos        (11)                                              /*!< EPWM_T::PDMACTL: CAPORD2_3 Position     */
#define EPWM_PDMACTL_CAPORD2_3_Msk        (0x1ul << EPWM_PDMACTL_CAPORD2_3_Pos)              /*!< EPWM_T::PDMACTL: CAPORD2_3 Mask         */

#define EPWM_PDMACTL_CHSEL2_3_Pos         (12)                                              /*!< EPWM_T::PDMACTL: CHSEL2_3 Position      */
#define EPWM_PDMACTL_CHSEL2_3_Msk         (0x1ul << EPWM_PDMACTL_CHSEL2_3_Pos)               /*!< EPWM_T::PDMACTL: CHSEL2_3 Mask          */

#define EPWM_PDMACTL_CHEN4_5_Pos          (16)                                              /*!< EPWM_T::PDMACTL: CHEN4_5 Position       */
#define EPWM_PDMACTL_CHEN4_5_Msk          (0x1ul << EPWM_PDMACTL_CHEN4_5_Pos)                /*!< EPWM_T::PDMACTL: CHEN4_5 Mask           */

#define EPWM_PDMACTL_CAPMOD4_5_Pos        (17)                                              /*!< EPWM_T::PDMACTL: CAPMOD4_5 Position     */
#define EPWM_PDMACTL_CAPMOD4_5_Msk        (0x3ul << EPWM_PDMACTL_CAPMOD4_5_Pos)              /*!< EPWM_T::PDMACTL: CAPMOD4_5 Mask         */

#define EPWM_PDMACTL_CAPORD4_5_Pos        (19)                                              /*!< EPWM_T::PDMACTL: CAPORD4_5 Position     */
#define EPWM_PDMACTL_CAPORD4_5_Msk        (0x1ul << EPWM_PDMACTL_CAPORD4_5_Pos)              /*!< EPWM_T::PDMACTL: CAPORD4_5 Mask         */

#define EPWM_PDMACTL_CHSEL4_5_Pos         (20)                                              /*!< EPWM_T::PDMACTL: CHSEL4_5 Position      */
#define EPWM_PDMACTL_CHSEL4_5_Msk         (0x1ul << EPWM_PDMACTL_CHSEL4_5_Pos)               /*!< EPWM_T::PDMACTL: CHSEL4_5 Mask          */

#define EPWM_PDMACAP0_1_CAPBUF_Pos        (0)                                               /*!< EPWM_T::PDMACAP0_1: CAPBUF Position     */
#define EPWM_PDMACAP0_1_CAPBUF_Msk        (0xfffful << EPWM_PDMACAP0_1_CAPBUF_Pos)           /*!< EPWM_T::PDMACAP0_1: CAPBUF Mask         */

#define EPWM_PDMACAP2_3_CAPBUF_Pos        (0)                                               /*!< EPWM_T::PDMACAP2_3: CAPBUF Position     */
#define EPWM_PDMACAP2_3_CAPBUF_Msk        (0xfffful << EPWM_PDMACAP2_3_CAPBUF_Pos)           /*!< EPWM_T::PDMACAP2_3: CAPBUF Mask         */

#define EPWM_PDMACAP4_5_CAPBUF_Pos        (0)                                               /*!< EPWM_T::PDMACAP4_5: CAPBUF Position     */
#define EPWM_PDMACAP4_5_CAPBUF_Msk        (0xfffful << EPWM_PDMACAP4_5_CAPBUF_Pos)           /*!< EPWM_T::PDMACAP4_5: CAPBUF Mask         */

#define EPWM_CAPIEN_CAPRIEN0_Pos          (0)                                               /*!< EPWM_T::CAPIEN: CAPRIEN0 Position       */
#define EPWM_CAPIEN_CAPRIEN0_Msk          (0x1ul << EPWM_CAPIEN_CAPRIEN0_Pos)                /*!< EPWM_T::CAPIEN: CAPRIEN0 Mask           */

#define EPWM_CAPIEN_CAPRIEN1_Pos          (1)                                               /*!< EPWM_T::CAPIEN: CAPRIEN1 Position       */
#define EPWM_CAPIEN_CAPRIEN1_Msk          (0x1ul << EPWM_CAPIEN_CAPRIEN1_Pos)                /*!< EPWM_T::CAPIEN: CAPRIEN1 Mask           */

#define EPWM_CAPIEN_CAPRIEN2_Pos          (2)                                               /*!< EPWM_T::CAPIEN: CAPRIEN2 Position       */
#define EPWM_CAPIEN_CAPRIEN2_Msk          (0x1ul << EPWM_CAPIEN_CAPRIEN2_Pos)                /*!< EPWM_T::CAPIEN: CAPRIEN2 Mask           */

#define EPWM_CAPIEN_CAPRIEN3_Pos          (3)                                               /*!< EPWM_T::CAPIEN: CAPRIEN3 Position       */
#define EPWM_CAPIEN_CAPRIEN3_Msk          (0x1ul << EPWM_CAPIEN_CAPRIEN3_Pos)                /*!< EPWM_T::CAPIEN: CAPRIEN3 Mask           */

#define EPWM_CAPIEN_CAPRIEN4_Pos          (4)                                               /*!< EPWM_T::CAPIEN: CAPRIEN4 Position       */
#define EPWM_CAPIEN_CAPRIEN4_Msk          (0x1ul << EPWM_CAPIEN_CAPRIEN4_Pos)                /*!< EPWM_T::CAPIEN: CAPRIEN4 Mask           */

#define EPWM_CAPIEN_CAPRIEN5_Pos          (5)                                               /*!< EPWM_T::CAPIEN: CAPRIEN5 Position       */
#define EPWM_CAPIEN_CAPRIEN5_Msk          (0x1ul << EPWM_CAPIEN_CAPRIEN5_Pos)                /*!< EPWM_T::CAPIEN: CAPRIEN5 Mask           */

#define EPWM_CAPIEN_CAPFIEN0_Pos          (8)                                               /*!< EPWM_T::CAPIEN: CAPFIEN0 Position       */
#define EPWM_CAPIEN_CAPFIEN0_Msk          (0x1ul << EPWM_CAPIEN_CAPFIEN0_Pos)                /*!< EPWM_T::CAPIEN: CAPFIEN0 Mask           */

#define EPWM_CAPIEN_CAPFIEN1_Pos          (9)                                               /*!< EPWM_T::CAPIEN: CAPFIEN1 Position       */
#define EPWM_CAPIEN_CAPFIEN1_Msk          (0x1ul << EPWM_CAPIEN_CAPFIEN1_Pos)                /*!< EPWM_T::CAPIEN: CAPFIEN1 Mask           */

#define EPWM_CAPIEN_CAPFIEN2_Pos          (10)                                              /*!< EPWM_T::CAPIEN: CAPFIEN2 Position       */
#define EPWM_CAPIEN_CAPFIEN2_Msk          (0x1ul << EPWM_CAPIEN_CAPFIEN2_Pos)                /*!< EPWM_T::CAPIEN: CAPFIEN2 Mask           */

#define EPWM_CAPIEN_CAPFIEN3_Pos          (11)                                              /*!< EPWM_T::CAPIEN: CAPFIEN3 Position       */
#define EPWM_CAPIEN_CAPFIEN3_Msk          (0x1ul << EPWM_CAPIEN_CAPFIEN3_Pos)                /*!< EPWM_T::CAPIEN: CAPFIEN3 Mask           */

#define EPWM_CAPIEN_CAPFIEN4_Pos          (12)                                              /*!< EPWM_T::CAPIEN: CAPFIEN4 Position       */
#define EPWM_CAPIEN_CAPFIEN4_Msk          (0x1ul << EPWM_CAPIEN_CAPFIEN4_Pos)                /*!< EPWM_T::CAPIEN: CAPFIEN4 Mask           */

#define EPWM_CAPIEN_CAPFIEN5_Pos          (13)                                              /*!< EPWM_T::CAPIEN: CAPFIEN5 Position       */
#define EPWM_CAPIEN_CAPFIEN5_Msk          (0x1ul << EPWM_CAPIEN_CAPFIEN5_Pos)                /*!< EPWM_T::CAPIEN: CAPFIEN5 Mask           */

#define EPWM_CAPIF_CRLIF0_Pos             (0)                                               /*!< EPWM_T::CAPIF: CRLIF0 Position          */
#define EPWM_CAPIF_CRLIF0_Msk             (0x1ul << EPWM_CAPIF_CRLIF0_Pos)                   /*!< EPWM_T::CAPIF: CRLIF0 Mask              */

#define EPWM_CAPIF_CRLIF1_Pos             (1)                                               /*!< EPWM_T::CAPIF: CRLIF1 Position          */
#define EPWM_CAPIF_CRLIF1_Msk             (0x1ul << EPWM_CAPIF_CRLIF1_Pos)                   /*!< EPWM_T::CAPIF: CRLIF1 Mask              */

#define EPWM_CAPIF_CRLIF2_Pos             (2)                                               /*!< EPWM_T::CAPIF: CRLIF2 Position          */
#define EPWM_CAPIF_CRLIF2_Msk             (0x1ul << EPWM_CAPIF_CRLIF2_Pos)                   /*!< EPWM_T::CAPIF: CRLIF2 Mask              */

#define EPWM_CAPIF_CRLIF3_Pos             (3)                                               /*!< EPWM_T::CAPIF: CRLIF3 Position          */
#define EPWM_CAPIF_CRLIF3_Msk             (0x1ul << EPWM_CAPIF_CRLIF3_Pos)                   /*!< EPWM_T::CAPIF: CRLIF3 Mask              */

#define EPWM_CAPIF_CRLIF4_Pos             (4)                                               /*!< EPWM_T::CAPIF: CRLIF4 Position          */
#define EPWM_CAPIF_CRLIF4_Msk             (0x1ul << EPWM_CAPIF_CRLIF4_Pos)                   /*!< EPWM_T::CAPIF: CRLIF4 Mask              */

#define EPWM_CAPIF_CRLIF5_Pos             (5)                                               /*!< EPWM_T::CAPIF: CRLIF5 Position          */
#define EPWM_CAPIF_CRLIF5_Msk             (0x1ul << EPWM_CAPIF_CRLIF5_Pos)                   /*!< EPWM_T::CAPIF: CRLIF5 Mask              */

#define EPWM_CAPIF_CFLIF0_Pos             (8)                                               /*!< EPWM_T::CAPIF: CFLIF0 Position          */
#define EPWM_CAPIF_CFLIF0_Msk             (0x1ul << EPWM_CAPIF_CFLIF0_Pos)                   /*!< EPWM_T::CAPIF: CFLIF0 Mask              */

#define EPWM_CAPIF_CFLIF1_Pos             (9)                                               /*!< EPWM_T::CAPIF: CFLIF1 Position          */
#define EPWM_CAPIF_CFLIF1_Msk             (0x1ul << EPWM_CAPIF_CFLIF1_Pos)                   /*!< EPWM_T::CAPIF: CFLIF1 Mask              */

#define EPWM_CAPIF_CFLIF2_Pos             (10)                                              /*!< EPWM_T::CAPIF: CFLIF2 Position          */
#define EPWM_CAPIF_CFLIF2_Msk             (0x1ul << EPWM_CAPIF_CFLIF2_Pos)                   /*!< EPWM_T::CAPIF: CFLIF2 Mask              */

#define EPWM_CAPIF_CFLIF3_Pos             (11)                                              /*!< EPWM_T::CAPIF: CFLIF3 Position          */
#define EPWM_CAPIF_CFLIF3_Msk             (0x1ul << EPWM_CAPIF_CFLIF3_Pos)                   /*!< EPWM_T::CAPIF: CFLIF3 Mask              */

#define EPWM_CAPIF_CFLIF4_Pos             (12)                                              /*!< EPWM_T::CAPIF: CFLIF4 Position          */
#define EPWM_CAPIF_CFLIF4_Msk             (0x1ul << EPWM_CAPIF_CFLIF4_Pos)                   /*!< EPWM_T::CAPIF: CFLIF4 Mask              */

#define EPWM_CAPIF_CFLIF5_Pos             (13)                                              /*!< EPWM_T::CAPIF: CFLIF5 Position          */
#define EPWM_CAPIF_CFLIF5_Msk             (0x1ul << EPWM_CAPIF_CFLIF5_Pos)                   /*!< EPWM_T::CAPIF: CFLIF5 Mask              */

#define EPWM_PBUF0_PBUF_Pos               (0)                                               /*!< EPWM_T::PBUF0: PBUF Position            */
#define EPWM_PBUF0_PBUF_Msk               (0xfffful << EPWM_PBUF0_PBUF_Pos)                  /*!< EPWM_T::PBUF0: PBUF Mask                */

#define EPWM_PBUF1_PBUF_Pos               (0)                                               /*!< EPWM_T::PBUF1: PBUF Position            */
#define EPWM_PBUF1_PBUF_Msk               (0xfffful << EPWM_PBUF1_PBUF_Pos)                  /*!< EPWM_T::PBUF1: PBUF Mask                */

#define EPWM_PBUF2_PBUF_Pos               (0)                                               /*!< EPWM_T::PBUF2: PBUF Position            */
#define EPWM_PBUF2_PBUF_Msk               (0xfffful << EPWM_PBUF2_PBUF_Pos)                  /*!< EPWM_T::PBUF2: PBUF Mask                */

#define EPWM_PBUF3_PBUF_Pos               (0)                                               /*!< EPWM_T::PBUF3: PBUF Position            */
#define EPWM_PBUF3_PBUF_Msk               (0xfffful << EPWM_PBUF3_PBUF_Pos)                  /*!< EPWM_T::PBUF3: PBUF Mask                */

#define EPWM_PBUF4_PBUF_Pos               (0)                                               /*!< EPWM_T::PBUF4: PBUF Position            */
#define EPWM_PBUF4_PBUF_Msk               (0xfffful << EPWM_PBUF4_PBUF_Pos)                  /*!< EPWM_T::PBUF4: PBUF Mask                */

#define EPWM_PBUF5_PBUF_Pos               (0)                                               /*!< EPWM_T::PBUF5: PBUF Position            */
#define EPWM_PBUF5_PBUF_Msk               (0xfffful << EPWM_PBUF5_PBUF_Pos)                  /*!< EPWM_T::PBUF5: PBUF Mask                */

#define EPWM_CMPBUF0_CMPBUF_Pos           (0)                                               /*!< EPWM_T::CMPBUF0: CMPBUF Position        */
#define EPWM_CMPBUF0_CMPBUF_Msk           (0xfffful << EPWM_CMPBUF0_CMPBUF_Pos)              /*!< EPWM_T::CMPBUF0: CMPBUF Mask            */

#define EPWM_CMPBUF1_CMPBUF_Pos           (0)                                               /*!< EPWM_T::CMPBUF1: CMPBUF Position        */
#define EPWM_CMPBUF1_CMPBUF_Msk           (0xfffful << EPWM_CMPBUF1_CMPBUF_Pos)              /*!< EPWM_T::CMPBUF1: CMPBUF Mask            */

#define EPWM_CMPBUF2_CMPBUF_Pos           (0)                                               /*!< EPWM_T::CMPBUF2: CMPBUF Position        */
#define EPWM_CMPBUF2_CMPBUF_Msk           (0xfffful << EPWM_CMPBUF2_CMPBUF_Pos)              /*!< EPWM_T::CMPBUF2: CMPBUF Mask            */

#define EPWM_CMPBUF3_CMPBUF_Pos           (0)                                               /*!< EPWM_T::CMPBUF3: CMPBUF Position        */
#define EPWM_CMPBUF3_CMPBUF_Msk           (0xfffful << EPWM_CMPBUF3_CMPBUF_Pos)              /*!< EPWM_T::CMPBUF3: CMPBUF Mask            */

#define EPWM_CMPBUF4_CMPBUF_Pos           (0)                                               /*!< EPWM_T::CMPBUF4: CMPBUF Position        */
#define EPWM_CMPBUF4_CMPBUF_Msk           (0xfffful << EPWM_CMPBUF4_CMPBUF_Pos)              /*!< EPWM_T::CMPBUF4: CMPBUF Mask            */

#define EPWM_CMPBUF5_CMPBUF_Pos           (0)                                               /*!< EPWM_T::CMPBUF5: CMPBUF Position        */
#define EPWM_CMPBUF5_CMPBUF_Msk           (0xfffful << EPWM_CMPBUF5_CMPBUF_Pos)              /*!< EPWM_T::CMPBUF5: CMPBUF Mask            */

#define EPWM_CPSCBUF0_1_CPSCBUF_Pos       (0)                                               /*!< EPWM_T::CPSCBUF0_1: CPSCBUF Position    */
#define EPWM_CPSCBUF0_1_CPSCBUF_Msk       (0xffful << EPWM_CPSCBUF0_1_CPSCBUF_Pos)           /*!< EPWM_T::CPSCBUF0_1: CPSCBUF Mask        */

#define EPWM_CPSCBUF2_3_CPSCBUF_Pos       (0)                                               /*!< EPWM_T::CPSCBUF2_3: CPSCBUF Position    */
#define EPWM_CPSCBUF2_3_CPSCBUF_Msk       (0xffful << EPWM_CPSCBUF2_3_CPSCBUF_Pos)           /*!< EPWM_T::CPSCBUF2_3: CPSCBUF Mask        */

#define EPWM_CPSCBUF4_5_CPSCBUF_Pos       (0)                                               /*!< EPWM_T::CPSCBUF4_5: CPSCBUF Position    */
#define EPWM_CPSCBUF4_5_CPSCBUF_Msk       (0xffful << EPWM_CPSCBUF4_5_CPSCBUF_Pos)           /*!< EPWM_T::CPSCBUF4_5: CPSCBUF Mask        */

#define EPWM_FTCBUF0_1_FTCMPBUF_Pos       (0)                                               /*!< EPWM_T::FTCBUF0_1: FTCMPBUF Position    */
#define EPWM_FTCBUF0_1_FTCMPBUF_Msk       (0xfffful << EPWM_FTCBUF0_1_FTCMPBUF_Pos)          /*!< EPWM_T::FTCBUF0_1: FTCMPBUF Mask        */

#define EPWM_FTCBUF2_3_FTCMPBUF_Pos       (0)                                               /*!< EPWM_T::FTCBUF2_3: FTCMPBUF Position    */
#define EPWM_FTCBUF2_3_FTCMPBUF_Msk       (0xfffful << EPWM_FTCBUF2_3_FTCMPBUF_Pos)          /*!< EPWM_T::FTCBUF2_3: FTCMPBUF Mask        */

#define EPWM_FTCBUF4_5_FTCMPBUF_Pos       (0)                                               /*!< EPWM_T::FTCBUF4_5: FTCMPBUF Position    */
#define EPWM_FTCBUF4_5_FTCMPBUF_Msk       (0xfffful << EPWM_FTCBUF4_5_FTCMPBUF_Pos)          /*!< EPWM_T::FTCBUF4_5: FTCMPBUF Mask        */

#define EPWM_FTCI_FTCMU0_Pos              (0)                                               /*!< EPWM_T::FTCI: FTCMU0 Position           */
#define EPWM_FTCI_FTCMU0_Msk              (0x1ul << EPWM_FTCI_FTCMU0_Pos)                    /*!< EPWM_T::FTCI: FTCMU0 Mask               */

#define EPWM_FTCI_FTCMU2_Pos              (1)                                               /*!< EPWM_T::FTCI: FTCMU2 Position           */
#define EPWM_FTCI_FTCMU2_Msk              (0x1ul << EPWM_FTCI_FTCMU2_Pos)                    /*!< EPWM_T::FTCI: FTCMU2 Mask               */

#define EPWM_FTCI_FTCMU4_Pos              (2)                                               /*!< EPWM_T::FTCI: FTCMU4 Position           */
#define EPWM_FTCI_FTCMU4_Msk              (0x1ul << EPWM_FTCI_FTCMU4_Pos)                    /*!< EPWM_T::FTCI: FTCMU4 Mask               */

#define EPWM_FTCI_FTCMD0_Pos              (8)                                               /*!< EPWM_T::FTCI: FTCMD0 Position           */
#define EPWM_FTCI_FTCMD0_Msk              (0x1ul << EPWM_FTCI_FTCMD0_Pos)                    /*!< EPWM_T::FTCI: FTCMD0 Mask               */

#define EPWM_FTCI_FTCMD2_Pos              (9)                                               /*!< EPWM_T::FTCI: FTCMD2 Position           */
#define EPWM_FTCI_FTCMD2_Msk              (0x1ul << EPWM_FTCI_FTCMD2_Pos)                    /*!< EPWM_T::FTCI: FTCMD2 Mask               */

#define EPWM_FTCI_FTCMD4_Pos              (10)                                              /*!< EPWM_T::FTCI: FTCMD4 Position           */
#define EPWM_FTCI_FTCMD4_Msk              (0x1ul << EPWM_FTCI_FTCMD4_Pos)                    /*!< EPWM_T::FTCI: FTCMD4 Mask               */

/**@}*/ /* EPWM_CONST */
/**@}*/ /* end of EPWM register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __EPWM_REG_H__ */
