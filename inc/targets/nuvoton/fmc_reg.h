/**************************************************************************//**
 * @file     fmc_reg.h
 * @version  V1.00
 * @brief    FMC register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __FMC_REG_H__
#define __FMC_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/**
    @addtogroup FMC_CONST FMC Bit Field Definition
    Constant Definitions for FMC Controller
@{ */

#define FMC_ISPCTL_ISPEN_Pos             (0)                                               /*!< FMC_T::ISPCTL: ISPEN Position          */
#define FMC_ISPCTL_ISPEN_Msk             (0x1ul << FMC_ISPCTL_ISPEN_Pos)                   /*!< FMC_T::ISPCTL: ISPEN Mask              */

#define FMC_ISPCTL_BS_Pos                (1)                                               /*!< FMC_T::ISPCTL: BS Position             */
#define FMC_ISPCTL_BS_Msk                (0x1ul << FMC_ISPCTL_BS_Pos)                      /*!< FMC_T::ISPCTL: BS Mask                 */

#define FMC_ISPCTL_SPUEN_Pos             (2)                                               /*!< FMC_T::ISPCTL: SPUEN Position          */
#define FMC_ISPCTL_SPUEN_Msk             (0x1ul << FMC_ISPCTL_SPUEN_Pos)                   /*!< FMC_T::ISPCTL: SPUEN Mask              */

#define FMC_ISPCTL_APUEN_Pos             (3)                                               /*!< FMC_T::ISPCTL: APUEN Position          */
#define FMC_ISPCTL_APUEN_Msk             (0x1ul << FMC_ISPCTL_APUEN_Pos)                   /*!< FMC_T::ISPCTL: APUEN Mask              */

#define FMC_ISPCTL_CFGUEN_Pos            (4)                                               /*!< FMC_T::ISPCTL: CFGUEN Position         */
#define FMC_ISPCTL_CFGUEN_Msk            (0x1ul << FMC_ISPCTL_CFGUEN_Pos)                  /*!< FMC_T::ISPCTL: CFGUEN Mask             */

#define FMC_ISPCTL_LDUEN_Pos             (5)                                               /*!< FMC_T::ISPCTL: LDUEN Position          */
#define FMC_ISPCTL_LDUEN_Msk             (0x1ul << FMC_ISPCTL_LDUEN_Pos)                   /*!< FMC_T::ISPCTL: LDUEN Mask              */

#define FMC_ISPCTL_ISPFF_Pos             (6)                                               /*!< FMC_T::ISPCTL: ISPFF Position          */
#define FMC_ISPCTL_ISPFF_Msk             (0x1ul << FMC_ISPCTL_ISPFF_Pos)                   /*!< FMC_T::ISPCTL: ISPFF Mask              */

#define FMC_ISPCTL_BL_Pos                (16)                                              /*!< FMC_T::ISPCTL: BL Position             */
#define FMC_ISPCTL_BL_Msk                (0x1ul << FMC_ISPCTL_BL_Pos)                      /*!< FMC_T::ISPCTL: BL Mask                 */

#define FMC_ISPADDR_ISPADDR_Pos          (0)                                               /*!< FMC_T::ISPADDR: ISPADDR Position       */
#define FMC_ISPADDR_ISPADDR_Msk          (0xfffffffful << FMC_ISPADDR_ISPADDR_Pos)         /*!< FMC_T::ISPADDR: ISPADDR Mask           */

#define FMC_ISPDAT_ISPDAT_Pos            (0)                                               /*!< FMC_T::ISPDAT: ISPDAT Position         */
#define FMC_ISPDAT_ISPDAT_Msk            (0xfffffffful << FMC_ISPDAT_ISPDAT_Pos)           /*!< FMC_T::ISPDAT: ISPDAT Mask             */

#define FMC_ISPCMD_CMD_Pos               (0)                                               /*!< FMC_T::ISPCMD: CMD Position            */
#define FMC_ISPCMD_CMD_Msk               (0x7ful << FMC_ISPCMD_CMD_Pos)                    /*!< FMC_T::ISPCMD: CMD Mask                */

#define FMC_ISPCMD_FLASH_READ					(0x00)
#define FMC_ISPCME_FLASH_READ_64BIT				(0x40)
#define FMC_ISPCMD_READ_UNIQUE_ID				(0x04)
#define FMC_ISPCMD_READ_FLASH_ALL_ONE_READ		(0x08)
#define FMC_ISPCMD_READ_COMPANY_ID				(0x0B)
#define FMC_ISPCMD_READ_DEVICE_ID				(0x0C)
#define FMC_ISPCMD_READ_CHECKSUM				(0x0D)
#define FMC_ISPCMD_FLASH_32BIT_PROGRAM			(0x21)
#define FMC_ISPCMD_FLASH_PAGE_ERASE				(0x22)
#define FMC_ISPCMD_FLASH_BANK_ERASE				(0x23)
#define FMC_ISPCMD_FLASH_BLOCK_ERASE			(0x25)
#define FMC_ISPCMD_FLASH_MULTI_WORD				(0x27)

#define FMC_ISPTRG_ISPGO_Pos             (0)                                               /*!< FMC_T::ISPTRG: ISPGO Position          */
#define FMC_ISPTRG_ISPGO_Msk             (0x1ul << FMC_ISPTRG_ISPGO_Pos)                   /*!< FMC_T::ISPTRG: ISPGO Mask              */

#define FMC_DFBA_DFBA_Pos                (0)                                               /*!< FMC_T::DFBA: DFBA Position             */
#define FMC_DFBA_DFBA_Msk                (0xfffffffful << FMC_DFBA_DFBA_Pos)               /*!< FMC_T::DFBA: DFBA Mask                 */

#define FMC_ISPSTS_ISPBUSY_Pos           (0)                                               /*!< FMC_T::ISPSTS: ISPBUSY Position        */
#define FMC_ISPSTS_ISPBUSY_Msk           (0x1ul << FMC_ISPSTS_ISPBUSY_Pos)                 /*!< FMC_T::ISPSTS: ISPBUSY Mask            */

#define FMC_ISPSTS_CBS_Pos               (1)                                               /*!< FMC_T::ISPSTS: CBS Position            */
#define FMC_ISPSTS_CBS_Msk               (0x3ul << FMC_ISPSTS_CBS_Pos)                     /*!< FMC_T::ISPSTS: CBS Mask                */

#define FMC_ISPSTS_MBS_Pos               (3)                                               /*!< FMC_T::ISPSTS: MBS Position            */
#define FMC_ISPSTS_MBS_Msk               (0x1ul << FMC_ISPSTS_MBS_Pos)                     /*!< FMC_T::ISPSTS: MBS Mask                */

#define FMC_ISPSTS_FCYCDIS_Pos           (4)                                               /*!< FMC_T::ISPSTS: FCYCDIS Position        */
#define FMC_ISPSTS_FCYCDIS_Msk           (0x1ul << FMC_ISPSTS_FCYCDIS_Pos)                 /*!< FMC_T::ISPSTS: FCYCDIS Mask            */

#define FMC_ISPSTS_PGFF_Pos              (5)                                               /*!< FMC_T::ISPSTS: PGFF Position           */
#define FMC_ISPSTS_PGFF_Msk              (0x1ul << FMC_ISPSTS_PGFF_Pos)                    /*!< FMC_T::ISPSTS: PGFF Mask               */

#define FMC_ISPSTS_ISPFF_Pos             (6)                                               /*!< FMC_T::ISPSTS: ISPFF Position          */
#define FMC_ISPSTS_ISPFF_Msk             (0x1ul << FMC_ISPSTS_ISPFF_Pos)                   /*!< FMC_T::ISPSTS: ISPFF Mask              */

#define FMC_ISPSTS_ALLONE_Pos            (7)                                               /*!< FMC_T::ISPSTS: ALLONE Position         */
#define FMC_ISPSTS_ALLONE_Msk            (0x1ul << FMC_ISPSTS_ALLONE_Pos)                  /*!< FMC_T::ISPSTS: ALLONE Mask             */

#define FMC_ISPSTS_VECMAP_Pos            (9)                                               /*!< FMC_T::ISPSTS: VECMAP Position         */
#define FMC_ISPSTS_VECMAP_Msk            (0x7ffful << FMC_ISPSTS_VECMAP_Pos)               /*!< FMC_T::ISPSTS: VECMAP Mask             */

#define FMC_ISPSTS_SCODE_Pos             (31)                                              /*!< FMC_T::ISPSTS: SCODE Position          */
#define FMC_ISPSTS_SCODE_Msk             (0x1ul << FMC_ISPSTS_SCODE_Pos)                   /*!< FMC_T::ISPSTS: SCODE Mask              */

#define FMC_CYCCTL_CYCLE_Pos             (0)                                               /*!< FMC_T::CYCCTL: CYCLE Position          */
#define FMC_CYCCTL_CYCLE_Msk             (0xful << FMC_CYCCTL_CYCLE_Pos)                   /*!< FMC_T::CYCCTL: CYCLE Mask              */

#define FMC_KPKEY0_KPKEY0_Pos            (0)                                               /*!< FMC_T::KPKEY0: KPKEY0 Position         */
#define FMC_KPKEY0_KPKEY0_Msk            (0xfffffffful << FMC_KPKEY0_KPKEY0_Pos)           /*!< FMC_T::KPKEY0: KPKEY0 Mask             */

#define FMC_KPKEY1_KPKEY1_Pos            (0)                                               /*!< FMC_T::KPKEY1: KPKEY1 Position         */
#define FMC_KPKEY1_KPKEY1_Msk            (0xfffffffful << FMC_KPKEY1_KPKEY1_Pos)           /*!< FMC_T::KPKEY1: KPKEY1 Mask             */

#define FMC_KPKEY2_KPKEY2_Pos            (0)                                               /*!< FMC_T::KPKEY2: KPKEY2 Position         */
#define FMC_KPKEY2_KPKEY2_Msk            (0xfffffffful << FMC_KPKEY2_KPKEY2_Pos)           /*!< FMC_T::KPKEY2: KPKEY2 Mask             */

#define FMC_KPKEYTRG_KPKEYGO_Pos         (0)                                               /*!< FMC_T::KPKEYTRG: KPKEYGO Position      */
#define FMC_KPKEYTRG_KPKEYGO_Msk         (0x1ul << FMC_KPKEYTRG_KPKEYGO_Pos)               /*!< FMC_T::KPKEYTRG: KPKEYGO Mask          */

#define FMC_KPKEYTRG_TCEN_Pos            (1)                                               /*!< FMC_T::KPKEYTRG: TCEN Position         */
#define FMC_KPKEYTRG_TCEN_Msk            (0x1ul << FMC_KPKEYTRG_TCEN_Pos)                  /*!< FMC_T::KPKEYTRG: TCEN Mask             */

#define FMC_KPKEYSTS_KEYBUSY_Pos         (0)                                               /*!< FMC_T::KPKEYSTS: KEYBUSY Position      */
#define FMC_KPKEYSTS_KEYBUSY_Msk         (0x1ul << FMC_KPKEYSTS_KEYBUSY_Pos)               /*!< FMC_T::KPKEYSTS: KEYBUSY Mask          */

#define FMC_KPKEYSTS_KEYLOCK_Pos         (1)                                               /*!< FMC_T::KPKEYSTS: KEYLOCK Position      */
#define FMC_KPKEYSTS_KEYLOCK_Msk         (0x1ul << FMC_KPKEYSTS_KEYLOCK_Pos)               /*!< FMC_T::KPKEYSTS: KEYLOCK Mask          */

#define FMC_KPKEYSTS_KEYMATCH_Pos        (2)                                               /*!< FMC_T::KPKEYSTS: KEYMATCH Position     */
#define FMC_KPKEYSTS_KEYMATCH_Msk        (0x1ul << FMC_KPKEYSTS_KEYMATCH_Pos)              /*!< FMC_T::KPKEYSTS: KEYMATCH Mask         */

#define FMC_KPKEYSTS_FORBID_Pos          (3)                                               /*!< FMC_T::KPKEYSTS: FORBID Position       */
#define FMC_KPKEYSTS_FORBID_Msk          (0x1ul << FMC_KPKEYSTS_FORBID_Pos)                /*!< FMC_T::KPKEYSTS: FORBID Mask           */

#define FMC_KPKEYSTS_KEYFLAG_Pos         (4)                                               /*!< FMC_T::KPKEYSTS: KEYFLAG Position      */
#define FMC_KPKEYSTS_KEYFLAG_Msk         (0x1ul << FMC_KPKEYSTS_KEYFLAG_Pos)               /*!< FMC_T::KPKEYSTS: KEYFLAG Mask          */

#define FMC_KPKEYSTS_CFGFLAG_Pos         (5)                                               /*!< FMC_T::KPKEYSTS: CFGFLAG Position      */
#define FMC_KPKEYSTS_CFGFLAG_Msk         (0x1ul << FMC_KPKEYSTS_CFGFLAG_Pos)               /*!< FMC_T::KPKEYSTS: CFGFLAG Mask          */

#define FMC_KPKEYSTS_SPFLAG_Pos          (6)                                               /*!< FMC_T::KPKEYSTS: SPFLAG Position       */
#define FMC_KPKEYSTS_SPFLAG_Msk          (0x1ul << FMC_KPKEYSTS_SPFLAG_Pos)                /*!< FMC_T::KPKEYSTS: SPFLAG Mask           */

#define FMC_KPKEYCNT_KPKECNT_Pos         (0)                                               /*!< FMC_T::KPKEYCNT: KPKECNT Position      */
#define FMC_KPKEYCNT_KPKECNT_Msk         (0x3ful << FMC_KPKEYCNT_KPKECNT_Pos)              /*!< FMC_T::KPKEYCNT: KPKECNT Mask          */

#define FMC_KPKEYCNT_KPKEMAX_Pos         (8)                                               /*!< FMC_T::KPKEYCNT: KPKEMAX Position      */
#define FMC_KPKEYCNT_KPKEMAX_Msk         (0x3ful << FMC_KPKEYCNT_KPKEMAX_Pos)              /*!< FMC_T::KPKEYCNT: KPKEMAX Mask          */

#define FMC_KPCNT_KPCNT_Pos              (0)                                               /*!< FMC_T::KPCNT: KPCNT Position           */
#define FMC_KPCNT_KPCNT_Msk              (0xful << FMC_KPCNT_KPCNT_Pos)                    /*!< FMC_T::KPCNT: KPCNT Mask               */

#define FMC_KPCNT_KPMAX_Pos              (8)                                               /*!< FMC_T::KPCNT: KPMAX Position           */
#define FMC_KPCNT_KPMAX_Msk              (0xful << FMC_KPCNT_KPMAX_Pos)                    /*!< FMC_T::KPCNT: KPMAX Mask               */

#define FMC_MPDAT0_ISPDAT0_Pos           (0)                                               /*!< FMC_T::MPDAT0: ISPDAT0 Position        */
#define FMC_MPDAT0_ISPDAT0_Msk           (0xfffffffful << FMC_MPDAT0_ISPDAT0_Pos)          /*!< FMC_T::MPDAT0: ISPDAT0 Mask            */

#define FMC_MPDAT1_ISPDAT1_Pos           (0)                                               /*!< FMC_T::MPDAT1: ISPDAT1 Position        */
#define FMC_MPDAT1_ISPDAT1_Msk           (0xfffffffful << FMC_MPDAT1_ISPDAT1_Pos)          /*!< FMC_T::MPDAT1: ISPDAT1 Mask            */

#define FMC_MPDAT2_ISPDAT2_Pos           (0)                                               /*!< FMC_T::MPDAT2: ISPDAT2 Position        */
#define FMC_MPDAT2_ISPDAT2_Msk           (0xfffffffful << FMC_MPDAT2_ISPDAT2_Pos)          /*!< FMC_T::MPDAT2: ISPDAT2 Mask            */

#define FMC_MPDAT3_ISPDAT3_Pos           (0)                                               /*!< FMC_T::MPDAT3: ISPDAT3 Position        */
#define FMC_MPDAT3_ISPDAT3_Msk           (0xfffffffful << FMC_MPDAT3_ISPDAT3_Pos)          /*!< FMC_T::MPDAT3: ISPDAT3 Mask            */

#define FMC_MPSTS_MPBUSY_Pos             (0)                                               /*!< FMC_T::MPSTS: MPBUSY Position          */
#define FMC_MPSTS_MPBUSY_Msk             (0x1ul << FMC_MPSTS_MPBUSY_Pos)                   /*!< FMC_T::MPSTS: MPBUSY Mask              */

#define FMC_MPSTS_PPGO_Pos               (1)                                               /*!< FMC_T::MPSTS: PPGO Position            */
#define FMC_MPSTS_PPGO_Msk               (0x1ul << FMC_MPSTS_PPGO_Pos)                     /*!< FMC_T::MPSTS: PPGO Mask                */

#define FMC_MPSTS_ISPFF_Pos              (2)                                               /*!< FMC_T::MPSTS: ISPFF Position           */
#define FMC_MPSTS_ISPFF_Msk              (0x1ul << FMC_MPSTS_ISPFF_Pos)                    /*!< FMC_T::MPSTS: ISPFF Mask               */

#define FMC_MPSTS_D0_Pos                 (4)                                               /*!< FMC_T::MPSTS: D0 Position              */
#define FMC_MPSTS_D0_Msk                 (0x1ul << FMC_MPSTS_D0_Pos)                       /*!< FMC_T::MPSTS: D0 Mask                  */

#define FMC_MPSTS_D1_Pos                 (5)                                               /*!< FMC_T::MPSTS: D1 Position              */
#define FMC_MPSTS_D1_Msk                 (0x1ul << FMC_MPSTS_D1_Pos)                       /*!< FMC_T::MPSTS: D1 Mask                  */

#define FMC_MPSTS_D2_Pos                 (6)                                               /*!< FMC_T::MPSTS: D2 Position              */
#define FMC_MPSTS_D2_Msk                 (0x1ul << FMC_MPSTS_D2_Pos)                       /*!< FMC_T::MPSTS: D2 Mask                  */

#define FMC_MPSTS_D3_Pos                 (7)                                               /*!< FMC_T::MPSTS: D3 Position              */
#define FMC_MPSTS_D3_Msk                 (0x1ul << FMC_MPSTS_D3_Pos)                       /*!< FMC_T::MPSTS: D3 Mask                  */

#define FMC_MPADDR_MPADDR_Pos            (0)                                               /*!< FMC_T::MPADDR: MPADDR Position         */
#define FMC_MPADDR_MPADDR_Msk            (0xfffffffful << FMC_MPADDR_MPADDR_Pos)           /*!< FMC_T::MPADDR: MPADDR Mask             */

#define FMC_XOMR0STS_SIZE_Pos            (0)                                               /*!< FMC_T::XOMR0STS: SIZE Position         */
#define FMC_XOMR0STS_SIZE_Msk            (0xfful << FMC_XOMR0STS_SIZE_Pos)                 /*!< FMC_T::XOMR0STS: SIZE Mask             */

#define FMC_XOMR0STS_BASE_Pos            (8)                                               /*!< FMC_T::XOMR0STS: BASE Position         */
#define FMC_XOMR0STS_BASE_Msk            (0xfffffful << FMC_XOMR0STS_BASE_Pos)             /*!< FMC_T::XOMR0STS: BASE Mask             */

#define FMC_XOMR1STS_SIZE_Pos            (0)                                               /*!< FMC_T::XOMR1STS: SIZE Position         */
#define FMC_XOMR1STS_SIZE_Msk            (0xfful << FMC_XOMR1STS_SIZE_Pos)                 /*!< FMC_T::XOMR1STS: SIZE Mask             */

#define FMC_XOMR1STS_BASE_Pos            (8)                                               /*!< FMC_T::XOMR1STS: BASE Position         */
#define FMC_XOMR1STS_BASE_Msk            (0xfffffful << FMC_XOMR1STS_BASE_Pos)             /*!< FMC_T::XOMR1STS: BASE Mask             */

#define FMC_XOMR2STS_SIZE_Pos            (0)                                               /*!< FMC_T::XOMR2STS: SIZE Position         */
#define FMC_XOMR2STS_SIZE_Msk            (0xfful << FMC_XOMR2STS_SIZE_Pos)                 /*!< FMC_T::XOMR2STS: SIZE Mask             */

#define FMC_XOMR2STS_BASE_Pos            (8)                                               /*!< FMC_T::XOMR2STS: BASE Position         */
#define FMC_XOMR2STS_BASE_Msk            (0xfffffful << FMC_XOM20STS_BASE_Pos)             /*!< FMC_T::XOMR2STS: BASE Mask             */

#define FMC_XOMR3STS_SIZE_Pos            (0)                                               /*!< FMC_T::XOMR3STS: SIZE Position         */
#define FMC_XOMR3STS_SIZE_Msk            (0xfful << FMC_XOMR3STS_SIZE_Pos)                 /*!< FMC_T::XOMR3STS: SIZE Mask             */

#define FMC_XOMR3STS_BASE_Pos            (8)                                               /*!< FMC_T::XOMR3STS: BASE Position         */
#define FMC_XOMR3STS_BASE_Msk            (0xfffffful << FMC_XOMR3STS_BASE_Pos)             /*!< FMC_T::XOMR3STS: BASE Mask             */

#define FMC_XOMSTS_XOMR0ON_Pos           (0)                                               /*!< FMC_T::XOMSTS: XOMR0ON Position        */
#define FMC_XOMSTS_XOMR0ON_Msk           (0x1ul << FMC_XOMSTS_XOMR0ON_Pos)                 /*!< FMC_T::XOMSTS: XOMR0ON Mask            */

#define FMC_XOMSTS_XOMR1ON_Pos           (1)                                               /*!< FMC_T::XOMSTS: XOMR1ON Position        */
#define FMC_XOMSTS_XOMR1ON_Msk           (0x1ul << FMC_XOMSTS_XOMR1ON_Pos)                 /*!< FMC_T::XOMSTS: XOMR1ON Mask            */

#define FMC_XOMSTS_XOMR2ON_Pos           (2)                                               /*!< FMC_T::XOMSTS: XOMR2ON Position        */
#define FMC_XOMSTS_XOMR2ON_Msk           (0x1ul << FMC_XOMSTS_XOMR2ON_Pos)                 /*!< FMC_T::XOMSTS: XOMR2ON Mask            */

#define FMC_XOMSTS_XOMR3ON_Pos           (3)                                               /*!< FMC_T::XOMSTS: XOMR3ON Position        */
#define FMC_XOMSTS_XOMR3ON_Msk           (0x1ul << FMC_XOMSTS_XOMR3ON_Pos)                 /*!< FMC_T::XOMSTS: XOMR3ON Mask            */

#define FMC_XOMSTS_XOMPEF_Pos            (4)                                               /*!< FMC_T::XOMSTS: XOMPEF Position         */
#define FMC_XOMSTS_XOMPEF_Msk            (0x1ul << FMC_XOMSTS_XOMPEF_Pos)                  /*!< FMC_T::XOMSTS: XOMPEF Mask             */

/**@}*/ /* FMC_CONST */
/**@}*/ /* end of FMC register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __FMC_REG_H__ */
