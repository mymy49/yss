/**************************************************************************//**
 * @file     i2c_reg.h
 * @version  V1.00
 * @brief    I2C register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __I2C_REG_H__
#define __I2C_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/


/**
    @addtogroup I2C_CONST I2C Bit Field Definition
    Constant Definitions for I2C Controller
@{ */

#define I2C_CTL0_AA_Pos                  (2)                                               /*!< I2C_T::CTL: AA Position                */
#define I2C_CTL0_AA_Msk                  (0x1ul << I2C_CTL0_AA_Pos)                        /*!< I2C_T::CTL: AA Mask                    */

#define I2C_CTL0_SI_Pos                  (3)                                               /*!< I2C_T::CTL: SI Position                */
#define I2C_CTL0_SI_Msk                  (0x1ul << I2C_CTL0_SI_Pos)                        /*!< I2C_T::CTL: SI Mask                    */

#define I2C_CTL0_STO_Pos                 (4)                                               /*!< I2C_T::CTL: STO Position               */
#define I2C_CTL0_STO_Msk                 (0x1ul << I2C_CTL0_STO_Pos)                       /*!< I2C_T::CTL: STO Mask                   */

#define I2C_CTL0_STA_Pos                 (5)                                               /*!< I2C_T::CTL: STA Position               */
#define I2C_CTL0_STA_Msk                 (0x1ul << I2C_CTL0_STA_Pos)                       /*!< I2C_T::CTL: STA Mask                   */

#define I2C_CTL0_I2CEN_Pos               (6)                                               /*!< I2C_T::CTL: I2CEN Position             */
#define I2C_CTL0_I2CEN_Msk               (0x1ul << I2C_CTL0_I2CEN_Pos)                     /*!< I2C_T::CTL: I2CEN Mask                 */

#define I2C_CTL0_INTEN_Pos               (7)                                               /*!< I2C_T::CTL: INTEN Position             */
#define I2C_CTL0_INTEN_Msk               (0x1ul << I2C_CTL0_INTEN_Pos)                     /*!< I2C_T::CTL: INTEN Mask                 */

#define I2C_ADDR0_GC_Pos                 (0)                                               /*!< I2C_T::ADDR0: GC Position              */
#define I2C_ADDR0_GC_Msk                 (0x1ul << I2C_ADDR0_GC_Pos)                       /*!< I2C_T::ADDR0: GC Mask                  */

#define I2C_ADDR0_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR0: ADDR Position            */
#define I2C_ADDR0_ADDR_Msk               (0x3fful << I2C_ADDR0_ADDR_Pos)                   /*!< I2C_T::ADDR0: ADDR Mask                */

#define I2C_DAT_DAT_Pos                  (0)                                               /*!< I2C_T::DAT: DAT Position               */
#define I2C_DAT_DAT_Msk                  (0xfful << I2C_DAT_DAT_Pos)                       /*!< I2C_T::DAT: DAT Mask                   */

#define I2C_STATUS0_STATUS_Pos           (0)                                               /*!< I2C_T::STATUS: STATUS Position         */
#define I2C_STATUS0_STATUS_Msk           (0xfful << I2C_STATUS_STATUS0_Pos)                /*!< I2C_T::STATUS: STATUS Mask             */

#define I2C_CLKDIV_DIVIDER_Pos           (0)                                               /*!< I2C_T::CLKDIV: DIVIDER Position        */
#define I2C_CLKDIV_DIVIDER_Msk           (0x3fful << I2C_CLKDIV_DIVIDER_Pos)               /*!< I2C_T::CLKDIV: DIVIDER Mask            */

#define I2C_TOCTL_TOIF_Pos               (0)                                               /*!< I2C_T::TOCTL: TOIF Position            */
#define I2C_TOCTL_TOIF_Msk               (0x1ul << I2C_TOCTL_TOIF_Pos)                     /*!< I2C_T::TOCTL: TOIF Mask                */

#define I2C_TOCTL_TOCDIV4_Pos            (1)                                               /*!< I2C_T::TOCTL: TOCDIV4 Position         */
#define I2C_TOCTL_TOCDIV4_Msk            (0x1ul << I2C_TOCTL_TOCDIV4_Pos)                  /*!< I2C_T::TOCTL: TOCDIV4 Mask             */

#define I2C_TOCTL_TOCEN_Pos              (2)                                               /*!< I2C_T::TOCTL: TOCEN Position           */
#define I2C_TOCTL_TOCEN_Msk              (0x1ul << I2C_TOCTL_TOCEN_Pos)                    /*!< I2C_T::TOCTL: TOCEN Mask               */

#define I2C_ADDR1_GC_Pos                 (0)                                               /*!< I2C_T::ADDR1: GC Position              */
#define I2C_ADDR1_GC_Msk                 (0x1ul << I2C_ADDR1_GC_Pos)                       /*!< I2C_T::ADDR1: GC Mask                  */

#define I2C_ADDR1_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR1: ADDR Position            */
#define I2C_ADDR1_ADDR_Msk               (0x3fful << I2C_ADDR1_ADDR_Pos)                   /*!< I2C_T::ADDR1: ADDR Mask                */

#define I2C_ADDR2_GC_Pos                 (0)                                               /*!< I2C_T::ADDR2: GC Position              */
#define I2C_ADDR2_GC_Msk                 (0x1ul << I2C_ADDR2_GC_Pos)                       /*!< I2C_T::ADDR2: GC Mask                  */

#define I2C_ADDR2_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR2: ADDR Position            */
#define I2C_ADDR2_ADDR_Msk               (0x3fful << I2C_ADDR2_ADDR_Pos)                   /*!< I2C_T::ADDR2: ADDR Mask                */

#define I2C_ADDR3_GC_Pos                 (0)                                               /*!< I2C_T::ADDR3: GC Position              */
#define I2C_ADDR3_GC_Msk                 (0x1ul << I2C_ADDR3_GC_Pos)                       /*!< I2C_T::ADDR3: GC Mask                  */

#define I2C_ADDR3_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR3: ADDR Position            */
#define I2C_ADDR3_ADDR_Msk               (0x3fful << I2C_ADDR3_ADDR_Pos)                   /*!< I2C_T::ADDR3: ADDR Mask                */

#define I2C_ADDRMSK0_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK0: ADDRMSK Position      */
#define I2C_ADDRMSK0_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK0_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK0: ADDRMSK Mask          */

#define I2C_ADDRMSK1_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK1: ADDRMSK Position      */
#define I2C_ADDRMSK1_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK1_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK1: ADDRMSK Mask          */

#define I2C_ADDRMSK2_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK2: ADDRMSK Position      */
#define I2C_ADDRMSK2_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK2_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK2: ADDRMSK Mask          */

#define I2C_ADDRMSK3_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK3: ADDRMSK Position      */
#define I2C_ADDRMSK3_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK3_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK3: ADDRMSK Mask          */

#define I2C_WKCTL_WKEN_Pos               (0)                                               /*!< I2C_T::WKCTL: WKEN Position            */
#define I2C_WKCTL_WKEN_Msk               (0x1ul << I2C_WKCTL_WKEN_Pos)                     /*!< I2C_T::WKCTL: WKEN Mask                */

#define I2C_WKCTL_NHDBUSEN_Pos           (7)                                               /*!< I2C_T::WKCTL: NHDBUSEN Position        */
#define I2C_WKCTL_NHDBUSEN_Msk           (0x1ul << I2C_WKCTL_NHDBUSEN_Pos)                 /*!< I2C_T::WKCTL: NHDBUSEN Mask            */

#define I2C_WKSTS_WKIF_Pos               (0)                                               /*!< I2C_T::WKSTS: WKIF Position            */
#define I2C_WKSTS_WKIF_Msk               (0x1ul << I2C_WKSTS_WKIF_Pos)                     /*!< I2C_T::WKSTS: WKIF Mask                */

#define I2C_WKSTS_WKAKDONE_Pos           (1)                                               /*!< I2C_T::WKSTS: WKAKDONE Position        */
#define I2C_WKSTS_WKAKDONE_Msk           (0x1ul << I2C_WKSTS_WKAKDONE_Pos)                 /*!< I2C_T::WKSTS: WKAKDONE Mask            */

#define I2C_WKSTS_WRSTSWK_Pos            (2)                                               /*!< I2C_T::WKSTS: WRSTSWK Position         */
#define I2C_WKSTS_WRSTSWK_Msk            (0x1ul << I2C_WKSTS_WRSTSWK_Pos)                  /*!< I2C_T::WKSTS: WRSTSWK Mask             */

#define I2C_CTL1_TXPDMAEN_Pos            (0)                                               /*!< I2C_T::CTL1: TXPDMAEN Position         */
#define I2C_CTL1_TXPDMAEN_Msk            (0x1ul << I2C_CTL1_TXPDMAEN_Pos)                  /*!< I2C_T::CTL1: TXPDMAEN Mask             */

#define I2C_CTL1_RXPDMAEN_Pos            (1)                                               /*!< I2C_T::CTL1: RXPDMAEN Position         */
#define I2C_CTL1_RXPDMAEN_Msk            (0x1ul << I2C_CTL1_RXPDMAEN_Pos)                  /*!< I2C_T::CTL1: RXPDMAEN Mask             */

#define I2C_CTL1_PDMARST_Pos             (2)                                               /*!< I2C_T::CTL1: PDMARST Position          */
#define I2C_CTL1_PDMARST_Msk             (0x1ul << I2C_CTL1_PDMARST_Pos)                   /*!< I2C_T::CTL1: PDMARST Mask              */

#define I2C_CTL1_PDMASTR_Pos             (8)                                               /*!< I2C_T::CTL1: PDMASTR Position          */
#define I2C_CTL1_PDMASTR_Msk             (0x1ul << I2C_CTL1_PDMASTR_Pos)                   /*!< I2C_T::CTL1: PDMASTR Mask              */

#define I2C_CTL1_ADDR10EN_Pos            (9)                                               /*!< I2C_T::CTL1: ADDR10EN Position         */
#define I2C_CTL1_ADDR10EN_Msk            (0x1ul << I2C_CTL1_ADDR10EN_Pos)                  /*!< I2C_T::CTL1: ADDR10EN Mask             */

#define I2C_STATUS1_ADMAT0_Pos           (0)                                               /*!< I2C_T::STATUS1: ADMAT0 Position        */
#define I2C_STATUS1_ADMAT0_Msk           (0x1ul << I2C_STATUS1_ADMAT0_Pos)                 /*!< I2C_T::STATUS1: ADMAT0 Mask            */

#define I2C_STATUS1_ADMAT1_Pos           (1)                                               /*!< I2C_T::STATUS1: ADMAT1 Position        */
#define I2C_STATUS1_ADMAT1_Msk           (0x1ul << I2C_STATUS1_ADMAT1_Pos)                 /*!< I2C_T::STATUS1: ADMAT1 Mask            */

#define I2C_STATUS1_ADMAT2_Pos           (2)                                               /*!< I2C_T::STATUS1: ADMAT2 Position        */
#define I2C_STATUS1_ADMAT2_Msk           (0x1ul << I2C_STATUS1_ADMAT2_Pos)                 /*!< I2C_T::STATUS1: ADMAT2 Mask            */

#define I2C_STATUS1_ADMAT3_Pos           (3)                                               /*!< I2C_T::STATUS1: ADMAT3 Position        */
#define I2C_STATUS1_ADMAT3_Msk           (0x1ul << I2C_STATUS1_ADMAT3_Pos)                 /*!< I2C_T::STATUS1: ADMAT3 Mask            */

#define I2C_STATUS1_ONBUSY_Pos           (8)                                               /*!< I2C_T::STATUS1: ONBUSY Position        */
#define I2C_STATUS1_ONBUSY_Msk           (0x1ul << I2C_STATUS1_ONBUSY_Pos)                 /*!< I2C_T::STATUS1: ONBUSY Mask            */

#define I2C_TMCTL_STCTL_Pos              (0)                                               /*!< I2C_T::TMCTL: STCTL Position           */
#define I2C_TMCTL_STCTL_Msk              (0x1fful << I2C_TMCTL_STCTL_Pos)                  /*!< I2C_T::TMCTL: STCTL Mask               */

#define I2C_TMCTL_HTCTL_Pos              (16)                                              /*!< I2C_T::TMCTL: HTCTL Position           */
#define I2C_TMCTL_HTCTL_Msk              (0x1fful << I2C_TMCTL_HTCTL_Pos)                  /*!< I2C_T::TMCTL: HTCTL Mask               */

#define I2C_BUSCTL_ACKMEN_Pos            (0)                                               /*!< I2C_T::BUSCTL: ACKMEN Position         */
#define I2C_BUSCTL_ACKMEN_Msk            (0x1ul << I2C_BUSCTL_ACKMEN_Pos)                  /*!< I2C_T::BUSCTL: ACKMEN Mask             */

#define I2C_BUSCTL_PECEN_Pos             (1)                                               /*!< I2C_T::BUSCTL: PECEN Position          */
#define I2C_BUSCTL_PECEN_Msk             (0x1ul << I2C_BUSCTL_PECEN_Pos)                   /*!< I2C_T::BUSCTL: PECEN Mask              */

#define I2C_BUSCTL_BMDEN_Pos             (2)                                               /*!< I2C_T::BUSCTL: BMDEN Position          */
#define I2C_BUSCTL_BMDEN_Msk             (0x1ul << I2C_BUSCTL_BMDEN_Pos)                   /*!< I2C_T::BUSCTL: BMDEN Mask              */

#define I2C_BUSCTL_BMHEN_Pos             (3)                                               /*!< I2C_T::BUSCTL: BMHEN Position          */
#define I2C_BUSCTL_BMHEN_Msk             (0x1ul << I2C_BUSCTL_BMHEN_Pos)                   /*!< I2C_T::BUSCTL: BMHEN Mask              */

#define I2C_BUSCTL_ALERTEN_Pos           (4)                                               /*!< I2C_T::BUSCTL: ALERTEN Position        */
#define I2C_BUSCTL_ALERTEN_Msk           (0x1ul << I2C_BUSCTL_ALERTEN_Pos)                 /*!< I2C_T::BUSCTL: ALERTEN Mask            */

#define I2C_BUSCTL_SCTLOSTS_Pos          (5)                                               /*!< I2C_T::BUSCTL: SCTLOSTS Position       */
#define I2C_BUSCTL_SCTLOSTS_Msk          (0x1ul << I2C_BUSCTL_SCTLOSTS_Pos)                /*!< I2C_T::BUSCTL: SCTLOSTS Mask           */

#define I2C_BUSCTL_SCTLOEN_Pos           (6)                                               /*!< I2C_T::BUSCTL: SCTLOEN Position        */
#define I2C_BUSCTL_SCTLOEN_Msk           (0x1ul << I2C_BUSCTL_SCTLOEN_Pos)                 /*!< I2C_T::BUSCTL: SCTLOEN Mask            */

#define I2C_BUSCTL_BUSEN_Pos             (7)                                               /*!< I2C_T::BUSCTL: BUSEN Position          */
#define I2C_BUSCTL_BUSEN_Msk             (0x1ul << I2C_BUSCTL_BUSEN_Pos)                   /*!< I2C_T::BUSCTL: BUSEN Mask              */

#define I2C_BUSCTL_PECTXEN_Pos           (8)                                               /*!< I2C_T::BUSCTL: PECTXEN Position        */
#define I2C_BUSCTL_PECTXEN_Msk           (0x1ul << I2C_BUSCTL_PECTXEN_Pos)                 /*!< I2C_T::BUSCTL: PECTXEN Mask            */

#define I2C_BUSCTL_TIDLE_Pos             (9)                                               /*!< I2C_T::BUSCTL: TIDLE Position          */
#define I2C_BUSCTL_TIDLE_Msk             (0x1ul << I2C_BUSCTL_TIDLE_Pos)                   /*!< I2C_T::BUSCTL: TIDLE Mask              */

#define I2C_BUSCTL_PECCLR_Pos            (10)                                              /*!< I2C_T::BUSCTL: PECCLR Position         */
#define I2C_BUSCTL_PECCLR_Msk            (0x1ul << I2C_BUSCTL_PECCLR_Pos)                  /*!< I2C_T::BUSCTL: PECCLR Mask             */

#define I2C_BUSCTL_ACKM9SI_Pos           (11)                                              /*!< I2C_T::BUSCTL: ACKM9SI Position        */
#define I2C_BUSCTL_ACKM9SI_Msk           (0x1ul << I2C_BUSCTL_ACKM9SI_Pos)                 /*!< I2C_T::BUSCTL: ACKM9SI Mask            */

#define I2C_BUSCTL_BCDIEN_Pos            (12)                                              /*!< I2C_T::BUSCTL: BCDIEN Position         */
#define I2C_BUSCTL_BCDIEN_Msk            (0x1ul << I2C_BUSCTL_BCDIEN_Pos)                  /*!< I2C_T::BUSCTL: BCDIEN Mask             */

#define I2C_BUSCTL_PECDIEN_Pos           (13)                                              /*!< I2C_T::BUSCTL: PECDIEN Position        */
#define I2C_BUSCTL_PECDIEN_Msk           (0x1ul << I2C_BUSCTL_PECDIEN_Pos)                 /*!< I2C_T::BUSCTL: PECDIEN Mask            */

#define I2C_BUSTCTL_BUSTOEN_Pos          (0)                                               /*!< I2C_T::BUSTCTL: BUSTOEN Position       */
#define I2C_BUSTCTL_BUSTOEN_Msk          (0x1ul << I2C_BUSTCTL_BUSTOEN_Pos)                /*!< I2C_T::BUSTCTL: BUSTOEN Mask           */

#define I2C_BUSTCTL_CLKTOEN_Pos          (1)                                               /*!< I2C_T::BUSTCTL: CLKTOEN Position       */
#define I2C_BUSTCTL_CLKTOEN_Msk          (0x1ul << I2C_BUSTCTL_CLKTOEN_Pos)                /*!< I2C_T::BUSTCTL: CLKTOEN Mask           */

#define I2C_BUSTCTL_BUSTOIEN_Pos         (2)                                               /*!< I2C_T::BUSTCTL: BUSTOIEN Position      */
#define I2C_BUSTCTL_BUSTOIEN_Msk         (0x1ul << I2C_BUSTCTL_BUSTOIEN_Pos)               /*!< I2C_T::BUSTCTL: BUSTOIEN Mask          */

#define I2C_BUSTCTL_CLKTOIEN_Pos         (3)                                               /*!< I2C_T::BUSTCTL: CLKTOIEN Position      */
#define I2C_BUSTCTL_CLKTOIEN_Msk         (0x1ul << I2C_BUSTCTL_CLKTOIEN_Pos)               /*!< I2C_T::BUSTCTL: CLKTOIEN Mask          */

#define I2C_BUSTCTL_TORSTEN_Pos          (4)                                               /*!< I2C_T::BUSTCTL: TORSTEN Position       */
#define I2C_BUSTCTL_TORSTEN_Msk          (0x1ul << I2C_BUSTCTL_TORSTEN_Pos)                /*!< I2C_T::BUSTCTL: TORSTEN Mask           */

#define I2C_BUSSTS_BUSY_Pos              (0)                                               /*!< I2C_T::BUSSTS: BUSY Position           */
#define I2C_BUSSTS_BUSY_Msk              (0x1ul << I2C_BUSSTS_BUSY_Pos)                    /*!< I2C_T::BUSSTS: BUSY Mask               */

#define I2C_BUSSTS_BCDONE_Pos            (1)                                               /*!< I2C_T::BUSSTS: BCDONE Position         */
#define I2C_BUSSTS_BCDONE_Msk            (0x1ul << I2C_BUSSTS_BCDONE_Pos)                  /*!< I2C_T::BUSSTS: BCDONE Mask             */

#define I2C_BUSSTS_PECERR_Pos            (2)                                               /*!< I2C_T::BUSSTS: PECERR Position         */
#define I2C_BUSSTS_PECERR_Msk            (0x1ul << I2C_BUSSTS_PECERR_Pos)                  /*!< I2C_T::BUSSTS: PECERR Mask             */

#define I2C_BUSSTS_ALERT_Pos             (3)                                               /*!< I2C_T::BUSSTS: ALERT Position          */
#define I2C_BUSSTS_ALERT_Msk             (0x1ul << I2C_BUSSTS_ALERT_Pos)                   /*!< I2C_T::BUSSTS: ALERT Mask              */

#define I2C_BUSSTS_SCTLDIN_Pos           (4)                                               /*!< I2C_T::BUSSTS: SCTLDIN Position        */
#define I2C_BUSSTS_SCTLDIN_Msk           (0x1ul << I2C_BUSSTS_SCTLDIN_Pos)                 /*!< I2C_T::BUSSTS: SCTLDIN Mask            */

#define I2C_BUSSTS_BUSTO_Pos             (5)                                               /*!< I2C_T::BUSSTS: BUSTO Position          */
#define I2C_BUSSTS_BUSTO_Msk             (0x1ul << I2C_BUSSTS_BUSTO_Pos)                   /*!< I2C_T::BUSSTS: BUSTO Mask              */

#define I2C_BUSSTS_CLKTO_Pos             (6)                                               /*!< I2C_T::BUSSTS: CLKTO Position          */
#define I2C_BUSSTS_CLKTO_Msk             (0x1ul << I2C_BUSSTS_CLKTO_Pos)                   /*!< I2C_T::BUSSTS: CLKTO Mask              */

#define I2C_BUSSTS_PECDONE_Pos           (7)                                               /*!< I2C_T::BUSSTS: PECDONE Position        */
#define I2C_BUSSTS_PECDONE_Msk           (0x1ul << I2C_BUSSTS_PECDONE_Pos)                 /*!< I2C_T::BUSSTS: PECDONE Mask            */

#define I2C_PKTSIZE_PLDSIZE_Pos          (0)                                               /*!< I2C_T::PKTSIZE: PLDSIZE Position       */
#define I2C_PKTSIZE_PLDSIZE_Msk          (0x1fful << I2C_PKTSIZE_PLDSIZE_Pos)              /*!< I2C_T::PKTSIZE: PLDSIZE Mask           */

#define I2C_PKTCRC_PECCRC_Pos            (0)                                               /*!< I2C_T::PKTCRC: PECCRC Position         */
#define I2C_PKTCRC_PECCRC_Msk            (0xfful << I2C_PKTCRC_PECCRC_Pos)                 /*!< I2C_T::PKTCRC: PECCRC Mask             */

#define I2C_BUSTOUT_BUSTO_Pos            (0)                                               /*!< I2C_T::BUSTOUT: BUSTO Position         */
#define I2C_BUSTOUT_BUSTO_Msk            (0xfful << I2C_BUSTOUT_BUSTO_Pos)                 /*!< I2C_T::BUSTOUT: BUSTO Mask             */

#define I2C_CLKTOUT_CLKTO_Pos            (0)                                               /*!< I2C_T::CLKTOUT: CLKTO Position         */
#define I2C_CLKTOUT_CLKTO_Msk            (0xfful << I2C_CLKTOUT_CLKTO_Pos)                 /*!< I2C_T::CLKTOUT: CLKTO Mask             */

/**@}*/ /* I2C_CONST */
/**@}*/ /* end of I2C register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __I2C_REG_H__ */
