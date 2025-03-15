/**************************************************************************//**
 * @file     spi_reg.h
 * @version  V1.00
 * @brief    SPI register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __SPI_REG_H__
#define __SPI_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/**
    @addtogroup SPI_CONST SPI Bit Field Definition
    Constant Definitions for SPI Controller
@{ */

#define SPI_CTL_SPIEN_Pos                (0)                                               /*!< SPI_T::CTL: SPIEN Position             */
#define SPI_CTL_SPIEN_Msk                (0x1ul << SPI_CTL_SPIEN_Pos)                      /*!< SPI_T::CTL: SPIEN Mask                 */

#define SPI_CTL_RXNEG_Pos                (1)                                               /*!< SPI_T::CTL: RXNEG Position             */
#define SPI_CTL_RXNEG_Msk                (0x1ul << SPI_CTL_RXNEG_Pos)                      /*!< SPI_T::CTL: RXNEG Mask                 */

#define SPI_CTL_TXNEG_Pos                (2)                                               /*!< SPI_T::CTL: TXNEG Position             */
#define SPI_CTL_TXNEG_Msk                (0x1ul << SPI_CTL_TXNEG_Pos)                      /*!< SPI_T::CTL: TXNEG Mask                 */

#define SPI_CTL_CLKPOL_Pos               (3)                                               /*!< SPI_T::CTL: CLKPOL Position            */
#define SPI_CTL_CLKPOL_Msk               (0x1ul << SPI_CTL_CLKPOL_Pos)                     /*!< SPI_T::CTL: CLKPOL Mask                */

#define SPI_CTL_SUSPITV_Pos              (4)                                               /*!< SPI_T::CTL: SUSPITV Position           */
#define SPI_CTL_SUSPITV_Msk              (0xful << SPI_CTL_SUSPITV_Pos)                    /*!< SPI_T::CTL: SUSPITV Mask               */

#define SPI_CTL_DWIDTH_Pos               (8)                                               /*!< SPI_T::CTL: DWIDTH Position            */
#define SPI_CTL_DWIDTH_Msk               (0x1ful << SPI_CTL_DWIDTH_Pos)                    /*!< SPI_T::CTL: DWIDTH Mask                */

#define SPI_CTL_LSB_Pos                  (13)                                              /*!< SPI_T::CTL: LSB Position               */
#define SPI_CTL_LSB_Msk                  (0x1ul << SPI_CTL_LSB_Pos)                        /*!< SPI_T::CTL: LSB Mask                   */

#define SPI_CTL_HALFDPX_Pos              (14)                                              /*!< SPI_T::CTL: HALFDPX Position           */
#define SPI_CTL_HALFDPX_Msk              (0x1ul << SPI_CTL_HALFDPX_Pos)                    /*!< SPI_T::CTL: HALFDPX Mask               */

#define SPI_CTL_RXONLY_Pos               (15)                                              /*!< SPI_T::CTL: RXONLY Position            */
#define SPI_CTL_RXONLY_Msk               (0x1ul << SPI_CTL_RXONLY_Pos)                     /*!< SPI_T::CTL: RXONLY Mask                */

#define SPI_CTL_UNITIEN_Pos              (17)                                              /*!< SPI_T::CTL: UNITIEN Position           */
#define SPI_CTL_UNITIEN_Msk              (0x1ul << SPI_CTL_UNITIEN_Pos)                    /*!< SPI_T::CTL: UNITIEN Mask               */

#define SPI_CTL_SLAVE_Pos                (18)                                              /*!< SPI_T::CTL: SLAVE Position             */
#define SPI_CTL_SLAVE_Msk                (0x1ul << SPI_CTL_SLAVE_Pos)                      /*!< SPI_T::CTL: SLAVE Mask                 */

#define SPI_CTL_REORDER_Pos              (19)                                              /*!< SPI_T::CTL: REORDER Position           */
#define SPI_CTL_REORDER_Msk              (0x1ul << SPI_CTL_REORDER_Pos)                    /*!< SPI_T::CTL: REORDER Mask               */

#define SPI_CTL_DATDIR_Pos               (20)                                              /*!< SPI_T::CTL: DATDIR Position            */
#define SPI_CTL_DATDIR_Msk               (0x1ul << SPI_CTL_DATDIR_Pos)                     /*!< SPI_T::CTL: DATDIR Mask                */

#define SPI_CLKDIV_DIVIDER_Pos           (0)                                               /*!< SPI_T::CLKDIV: DIVIDER Position        */
#define SPI_CLKDIV_DIVIDER_Msk           (0x1fful << SPI_CLKDIV_DIVIDER_Pos)               /*!< SPI_T::CLKDIV: DIVIDER Mask            */

#define SPI_SSCTL_SS_Pos                 (0)                                               /*!< SPI_T::SSCTL: SS Position              */
#define SPI_SSCTL_SS_Msk                 (0x1ul << SPI_SSCTL_SS_Pos)                       /*!< SPI_T::SSCTL: SS Mask                  */

#define SPI_SSCTL_SSACTPOL_Pos           (2)                                               /*!< SPI_T::SSCTL: SSACTPOL Position        */
#define SPI_SSCTL_SSACTPOL_Msk           (0x1ul << SPI_SSCTL_SSACTPOL_Pos)                 /*!< SPI_T::SSCTL: SSACTPOL Mask            */

#define SPI_SSCTL_AUTOSS_Pos             (3)                                               /*!< SPI_T::SSCTL: AUTOSS Position          */
#define SPI_SSCTL_AUTOSS_Msk             (0x1ul << SPI_SSCTL_AUTOSS_Pos)                   /*!< SPI_T::SSCTL: AUTOSS Mask              */

#define SPI_SSCTL_SLVBEIEN_Pos           (8)                                               /*!< SPI_T::SSCTL: SLVBEIEN Position        */
#define SPI_SSCTL_SLVBEIEN_Msk           (0x1ul << SPI_SSCTL_SLVBEIEN_Pos)                 /*!< SPI_T::SSCTL: SLVBEIEN Mask            */

#define SPI_SSCTL_SLVURIEN_Pos           (9)                                               /*!< SPI_T::SSCTL: SLVURIEN Position        */
#define SPI_SSCTL_SLVURIEN_Msk           (0x1ul << SPI_SSCTL_SLVURIEN_Pos)                 /*!< SPI_T::SSCTL: SLVURIEN Mask            */

#define SPI_SSCTL_SSACTIEN_Pos           (12)                                              /*!< SPI_T::SSCTL: SSACTIEN Position        */
#define SPI_SSCTL_SSACTIEN_Msk           (0x1ul << SPI_SSCTL_SSACTIEN_Pos)                 /*!< SPI_T::SSCTL: SSACTIEN Mask            */

#define SPI_SSCTL_SSINAIEN_Pos           (13)                                              /*!< SPI_T::SSCTL: SSINAIEN Position        */
#define SPI_SSCTL_SSINAIEN_Msk           (0x1ul << SPI_SSCTL_SSINAIEN_Pos)                 /*!< SPI_T::SSCTL: SSINAIEN Mask            */

#define SPI_SSCTL_SLVTOCNT_Pos           (16)                                              /*!< SPI_T::SSCTL: SLVTOCNT Position        */
#define SPI_SSCTL_SLVTOCNT_Msk           (0xfffful << SPI_SSCTL_SLVTOCNT_Pos)              /*!< SPI_T::SSCTL: SLVTOCNT Mask            */

#define SPI_PDMACTL_TXPDMAEN_Pos         (0)                                               /*!< SPI_T::PDMACTL: TXPDMAEN Position      */
#define SPI_PDMACTL_TXPDMAEN_Msk         (0x1ul << SPI_PDMACTL_TXPDMAEN_Pos)               /*!< SPI_T::PDMACTL: TXPDMAEN Mask          */

#define SPI_PDMACTL_RXPDMAEN_Pos         (1)                                               /*!< SPI_T::PDMACTL: RXPDMAEN Position      */
#define SPI_PDMACTL_RXPDMAEN_Msk         (0x1ul << SPI_PDMACTL_RXPDMAEN_Pos)               /*!< SPI_T::PDMACTL: RXPDMAEN Mask          */

#define SPI_PDMACTL_PDMARST_Pos          (2)                                               /*!< SPI_T::PDMACTL: PDMARST Position       */
#define SPI_PDMACTL_PDMARST_Msk          (0x1ul << SPI_PDMACTL_PDMARST_Pos)                /*!< SPI_T::PDMACTL: PDMARST Mask           */

#define SPI_FIFOCTL_RXRST_Pos            (0)                                               /*!< SPI_T::FIFOCTL: RXRST Position         */
#define SPI_FIFOCTL_RXRST_Msk            (0x1ul << SPI_FIFOCTL_RXRST_Pos)                  /*!< SPI_T::FIFOCTL: RXRST Mask             */

#define SPI_FIFOCTL_TXRST_Pos            (1)                                               /*!< SPI_T::FIFOCTL: TXRST Position         */
#define SPI_FIFOCTL_TXRST_Msk            (0x1ul << SPI_FIFOCTL_TXRST_Pos)                  /*!< SPI_T::FIFOCTL: TXRST Mask             */

#define SPI_FIFOCTL_RXTHIEN_Pos          (2)                                               /*!< SPI_T::FIFOCTL: RXTHIEN Position       */
#define SPI_FIFOCTL_RXTHIEN_Msk          (0x1ul << SPI_FIFOCTL_RXTHIEN_Pos)                /*!< SPI_T::FIFOCTL: RXTHIEN Mask           */

#define SPI_FIFOCTL_TXTHIEN_Pos          (3)                                               /*!< SPI_T::FIFOCTL: TXTHIEN Position       */
#define SPI_FIFOCTL_TXTHIEN_Msk          (0x1ul << SPI_FIFOCTL_TXTHIEN_Pos)                /*!< SPI_T::FIFOCTL: TXTHIEN Mask           */

#define SPI_FIFOCTL_RXTOIEN_Pos          (4)                                               /*!< SPI_T::FIFOCTL: RXTOIEN Position       */
#define SPI_FIFOCTL_RXTOIEN_Msk          (0x1ul << SPI_FIFOCTL_RXTOIEN_Pos)                /*!< SPI_T::FIFOCTL: RXTOIEN Mask           */

#define SPI_FIFOCTL_RXOVIEN_Pos          (5)                                               /*!< SPI_T::FIFOCTL: RXOVIEN Position       */
#define SPI_FIFOCTL_RXOVIEN_Msk          (0x1ul << SPI_FIFOCTL_RXOVIEN_Pos)                /*!< SPI_T::FIFOCTL: RXOVIEN Mask           */

#define SPI_FIFOCTL_TXUFPOL_Pos          (6)                                               /*!< SPI_T::FIFOCTL: TXUFPOL Position       */
#define SPI_FIFOCTL_TXUFPOL_Msk          (0x1ul << SPI_FIFOCTL_TXUFPOL_Pos)                /*!< SPI_T::FIFOCTL: TXUFPOL Mask           */

#define SPI_FIFOCTL_TXUFIEN_Pos          (7)                                               /*!< SPI_T::FIFOCTL: TXUFIEN Position       */
#define SPI_FIFOCTL_TXUFIEN_Msk          (0x1ul << SPI_FIFOCTL_TXUFIEN_Pos)                /*!< SPI_T::FIFOCTL: TXUFIEN Mask           */

#define SPI_FIFOCTL_RXFBCLR_Pos          (8)                                               /*!< SPI_T::FIFOCTL: RXFBCLR Position       */
#define SPI_FIFOCTL_RXFBCLR_Msk          (0x1ul << SPI_FIFOCTL_RXFBCLR_Pos)                /*!< SPI_T::FIFOCTL: RXFBCLR Mask           */

#define SPI_FIFOCTL_TXFBCLR_Pos          (9)                                               /*!< SPI_T::FIFOCTL: TXFBCLR Position       */
#define SPI_FIFOCTL_TXFBCLR_Msk          (0x1ul << SPI_FIFOCTL_TXFBCLR_Pos)                /*!< SPI_T::FIFOCTL: TXFBCLR Mask           */

#define SPI_FIFOCTL_RXTH_Pos             (24)                                              /*!< SPI_T::FIFOCTL: RXTH Position          */
#define SPI_FIFOCTL_RXTH_Msk             (0x7ul << SPI_FIFOCTL_RXTH_Pos)                   /*!< SPI_T::FIFOCTL: RXTH Mask              */

#define SPI_FIFOCTL_TXTH_Pos             (28)                                              /*!< SPI_T::FIFOCTL: TXTH Position          */
#define SPI_FIFOCTL_TXTH_Msk             (0x7ul << SPI_FIFOCTL_TXTH_Pos)                   /*!< SPI_T::FIFOCTL: TXTH Mask              */

#define SPI_STATUS_BUSY_Pos              (0)                                               /*!< SPI_T::STATUS: BUSY Position           */
#define SPI_STATUS_BUSY_Msk              (0x1ul << SPI_STATUS_BUSY_Pos)                    /*!< SPI_T::STATUS: BUSY Mask               */

#define SPI_STATUS_UNITIF_Pos            (1)                                               /*!< SPI_T::STATUS: UNITIF Position         */
#define SPI_STATUS_UNITIF_Msk            (0x1ul << SPI_STATUS_UNITIF_Pos)                  /*!< SPI_T::STATUS: UNITIF Mask             */

#define SPI_STATUS_SSACTIF_Pos           (2)                                               /*!< SPI_T::STATUS: SSACTIF Position        */
#define SPI_STATUS_SSACTIF_Msk           (0x1ul << SPI_STATUS_SSACTIF_Pos)                 /*!< SPI_T::STATUS: SSACTIF Mask            */

#define SPI_STATUS_SSINAIF_Pos           (3)                                               /*!< SPI_T::STATUS: SSINAIF Position        */
#define SPI_STATUS_SSINAIF_Msk           (0x1ul << SPI_STATUS_SSINAIF_Pos)                 /*!< SPI_T::STATUS: SSINAIF Mask            */

#define SPI_STATUS_SSLINE_Pos            (4)                                               /*!< SPI_T::STATUS: SSLINE Position         */
#define SPI_STATUS_SSLINE_Msk            (0x1ul << SPI_STATUS_SSLINE_Pos)                  /*!< SPI_T::STATUS: SSLINE Mask             */

#define SPI_STATUS_SLVBEIF_Pos           (6)                                               /*!< SPI_T::STATUS: SLVBEIF Position        */
#define SPI_STATUS_SLVBEIF_Msk           (0x1ul << SPI_STATUS_SLVBEIF_Pos)                 /*!< SPI_T::STATUS: SLVBEIF Mask            */

#define SPI_STATUS_SLVURIF_Pos           (7)                                               /*!< SPI_T::STATUS: SLVURIF Position        */
#define SPI_STATUS_SLVURIF_Msk           (0x1ul << SPI_STATUS_SLVURIF_Pos)                 /*!< SPI_T::STATUS: SLVURIF Mask            */

#define SPI_STATUS_RXEMPTY_Pos           (8)                                               /*!< SPI_T::STATUS: RXEMPTY Position        */
#define SPI_STATUS_RXEMPTY_Msk           (0x1ul << SPI_STATUS_RXEMPTY_Pos)                 /*!< SPI_T::STATUS: RXEMPTY Mask            */

#define SPI_STATUS_RXFULL_Pos            (9)                                               /*!< SPI_T::STATUS: RXFULL Position         */
#define SPI_STATUS_RXFULL_Msk            (0x1ul << SPI_STATUS_RXFULL_Pos)                  /*!< SPI_T::STATUS: RXFULL Mask             */

#define SPI_STATUS_RXTHIF_Pos            (10)                                              /*!< SPI_T::STATUS: RXTHIF Position         */
#define SPI_STATUS_RXTHIF_Msk            (0x1ul << SPI_STATUS_RXTHIF_Pos)                  /*!< SPI_T::STATUS: RXTHIF Mask             */

#define SPI_STATUS_RXOVIF_Pos            (11)                                              /*!< SPI_T::STATUS: RXOVIF Position         */
#define SPI_STATUS_RXOVIF_Msk            (0x1ul << SPI_STATUS_RXOVIF_Pos)                  /*!< SPI_T::STATUS: RXOVIF Mask             */

#define SPI_STATUS_RXTOIF_Pos            (12)                                              /*!< SPI_T::STATUS: RXTOIF Position         */
#define SPI_STATUS_RXTOIF_Msk            (0x1ul << SPI_STATUS_RXTOIF_Pos)                  /*!< SPI_T::STATUS: RXTOIF Mask             */

#define SPI_STATUS_SPIENSTS_Pos          (15)                                              /*!< SPI_T::STATUS: SPIENSTS Position       */
#define SPI_STATUS_SPIENSTS_Msk          (0x1ul << SPI_STATUS_SPIENSTS_Pos)                /*!< SPI_T::STATUS: SPIENSTS Mask           */

#define SPI_STATUS_TXEMPTY_Pos           (16)                                              /*!< SPI_T::STATUS: TXEMPTY Position        */
#define SPI_STATUS_TXEMPTY_Msk           (0x1ul << SPI_STATUS_TXEMPTY_Pos)                 /*!< SPI_T::STATUS: TXEMPTY Mask            */

#define SPI_STATUS_TXFULL_Pos            (17)                                              /*!< SPI_T::STATUS: TXFULL Position         */
#define SPI_STATUS_TXFULL_Msk            (0x1ul << SPI_STATUS_TXFULL_Pos)                  /*!< SPI_T::STATUS: TXFULL Mask             */

#define SPI_STATUS_TXTHIF_Pos            (18)                                              /*!< SPI_T::STATUS: TXTHIF Position         */
#define SPI_STATUS_TXTHIF_Msk            (0x1ul << SPI_STATUS_TXTHIF_Pos)                  /*!< SPI_T::STATUS: TXTHIF Mask             */

#define SPI_STATUS_TXUFIF_Pos            (19)                                              /*!< SPI_T::STATUS: TXUFIF Position         */
#define SPI_STATUS_TXUFIF_Msk            (0x1ul << SPI_STATUS_TXUFIF_Pos)                  /*!< SPI_T::STATUS: TXUFIF Mask             */

#define SPI_STATUS_TXRXRST_Pos           (23)                                              /*!< SPI_T::STATUS: TXRXRST Position        */
#define SPI_STATUS_TXRXRST_Msk           (0x1ul << SPI_STATUS_TXRXRST_Pos)                 /*!< SPI_T::STATUS: TXRXRST Mask            */

#define SPI_STATUS_RXCNT_Pos             (24)                                              /*!< SPI_T::STATUS: RXCNT Position          */
#define SPI_STATUS_RXCNT_Msk             (0xful << SPI_STATUS_RXCNT_Pos)                   /*!< SPI_T::STATUS: RXCNT Mask              */

#define SPI_STATUS_TXCNT_Pos             (28)                                              /*!< SPI_T::STATUS: TXCNT Position          */
#define SPI_STATUS_TXCNT_Msk             (0xful << SPI_STATUS_TXCNT_Pos)                   /*!< SPI_T::STATUS: TXCNT Mask              */

#define SPI_TX_TX_Pos                    (0)                                               /*!< SPI_T::TX: TX Position                 */
#define SPI_TX_TX_Msk                    (0xfffffffful << SPI_TX_TX_Pos)                   /*!< SPI_T::TX: TX Mask                     */

#define SPI_RX_RX_Pos                    (0)                                               /*!< SPI_T::RX: RX Position                 */
#define SPI_RX_RX_Msk                    (0xfffffffful << SPI_RX_RX_Pos)                   /*!< SPI_T::RX: RX Mask                     */

#define SPI_I2SCTL_I2SEN_Pos             (0)                                               /*!< SPI_T::I2SCTL: I2SEN Position          */
#define SPI_I2SCTL_I2SEN_Msk             (0x1ul << SPI_I2SCTL_I2SEN_Pos)                   /*!< SPI_T::I2SCTL: I2SEN Mask              */

#define SPI_I2SCTL_TXEN_Pos              (1)                                               /*!< SPI_T::I2SCTL: TXEN Position           */
#define SPI_I2SCTL_TXEN_Msk              (0x1ul << SPI_I2SCTL_TXEN_Pos)                    /*!< SPI_T::I2SCTL: TXEN Mask               */

#define SPI_I2SCTL_RXEN_Pos              (2)                                               /*!< SPI_T::I2SCTL: RXEN Position           */
#define SPI_I2SCTL_RXEN_Msk              (0x1ul << SPI_I2SCTL_RXEN_Pos)                    /*!< SPI_T::I2SCTL: RXEN Mask               */

#define SPI_I2SCTL_MUTE_Pos              (3)                                               /*!< SPI_T::I2SCTL: MUTE Position           */
#define SPI_I2SCTL_MUTE_Msk              (0x1ul << SPI_I2SCTL_MUTE_Pos)                    /*!< SPI_T::I2SCTL: MUTE Mask               */

#define SPI_I2SCTL_WDWIDTH_Pos           (4)                                               /*!< SPI_T::I2SCTL: WDWIDTH Position        */
#define SPI_I2SCTL_WDWIDTH_Msk           (0x3ul << SPI_I2SCTL_WDWIDTH_Pos)                 /*!< SPI_T::I2SCTL: WDWIDTH Mask            */

#define SPI_I2SCTL_MONO_Pos              (6)                                               /*!< SPI_T::I2SCTL: MONO Position           */
#define SPI_I2SCTL_MONO_Msk              (0x1ul << SPI_I2SCTL_MONO_Pos)                    /*!< SPI_T::I2SCTL: MONO Mask               */

#define SPI_I2SCTL_ORDER_Pos             (7)                                               /*!< SPI_T::I2SCTL: ORDER Position          */
#define SPI_I2SCTL_ORDER_Msk             (0x1ul << SPI_I2SCTL_ORDER_Pos)                   /*!< SPI_T::I2SCTL: ORDER Mask              */

#define SPI_I2SCTL_SLAVE_Pos             (8)                                               /*!< SPI_T::I2SCTL: SLAVE Position          */
#define SPI_I2SCTL_SLAVE_Msk             (0x1ul << SPI_I2SCTL_SLAVE_Pos)                   /*!< SPI_T::I2SCTL: SLAVE Mask              */

#define SPI_I2SCTL_MCLKEN_Pos            (15)                                              /*!< SPI_T::I2SCTL: MCLKEN Position         */
#define SPI_I2SCTL_MCLKEN_Msk            (0x1ul << SPI_I2SCTL_MCLKEN_Pos)                  /*!< SPI_T::I2SCTL: MCLKEN Mask             */

#define SPI_I2SCTL_RZCEN_Pos             (16)                                              /*!< SPI_T::I2SCTL: RZCEN Position          */
#define SPI_I2SCTL_RZCEN_Msk             (0x1ul << SPI_I2SCTL_RZCEN_Pos)                   /*!< SPI_T::I2SCTL: RZCEN Mask              */

#define SPI_I2SCTL_LZCEN_Pos             (17)                                              /*!< SPI_T::I2SCTL: LZCEN Position          */
#define SPI_I2SCTL_LZCEN_Msk             (0x1ul << SPI_I2SCTL_LZCEN_Pos)                   /*!< SPI_T::I2SCTL: LZCEN Mask              */

#define SPI_I2SCTL_RXLCH_Pos             (23)                                              /*!< SPI_T::I2SCTL: RXLCH Position          */
#define SPI_I2SCTL_RXLCH_Msk             (0x1ul << SPI_I2SCTL_RXLCH_Pos)                   /*!< SPI_T::I2SCTL: RXLCH Mask              */

#define SPI_I2SCTL_RZCIEN_Pos            (24)                                              /*!< SPI_T::I2SCTL: RZCIEN Position         */
#define SPI_I2SCTL_RZCIEN_Msk            (0x1ul << SPI_I2SCTL_RZCIEN_Pos)                  /*!< SPI_T::I2SCTL: RZCIEN Mask             */

#define SPI_I2SCTL_LZCIEN_Pos            (25)                                              /*!< SPI_T::I2SCTL: LZCIEN Position         */
#define SPI_I2SCTL_LZCIEN_Msk            (0x1ul << SPI_I2SCTL_LZCIEN_Pos)                  /*!< SPI_T::I2SCTL: LZCIEN Mask             */

#define SPI_I2SCTL_FORMAT_Pos            (28)                                              /*!< SPI_T::I2SCTL: FORMAT Position         */
#define SPI_I2SCTL_FORMAT_Msk            (0x3ul << SPI_I2SCTL_FORMAT_Pos)                  /*!< SPI_T::I2SCTL: FORMAT Mask             */

#define SPI_I2SCLK_MCLKDIV_Pos           (0)                                               /*!< SPI_T::I2SCLK: MCLKDIV Position        */
#define SPI_I2SCLK_MCLKDIV_Msk           (0x7ful << SPI_I2SCLK_MCLKDIV_Pos)                /*!< SPI_T::I2SCLK: MCLKDIV Mask            */

#define SPI_I2SCLK_BCLKDIV_Pos           (8)                                               /*!< SPI_T::I2SCLK: BCLKDIV Position        */
#define SPI_I2SCLK_BCLKDIV_Msk           (0x3fful << SPI_I2SCLK_BCLKDIV_Pos)               /*!< SPI_T::I2SCLK: BCLKDIV Mask            */

#define SPI_I2SSTS_RIGHT_Pos             (4)                                               /*!< SPI_T::I2SSTS: RIGHT Position          */
#define SPI_I2SSTS_RIGHT_Msk             (0x1ul << SPI_I2SSTS_RIGHT_Pos)                   /*!< SPI_T::I2SSTS: RIGHT Mask              */

#define SPI_I2SSTS_RXEMPTY_Pos           (8)                                               /*!< SPI_T::I2SSTS: RXEMPTY Position        */
#define SPI_I2SSTS_RXEMPTY_Msk           (0x1ul << SPI_I2SSTS_RXEMPTY_Pos)                 /*!< SPI_T::I2SSTS: RXEMPTY Mask            */

#define SPI_I2SSTS_RXFULL_Pos            (9)                                               /*!< SPI_T::I2SSTS: RXFULL Position         */
#define SPI_I2SSTS_RXFULL_Msk            (0x1ul << SPI_I2SSTS_RXFULL_Pos)                  /*!< SPI_T::I2SSTS: RXFULL Mask             */

#define SPI_I2SSTS_RXTHIF_Pos            (10)                                              /*!< SPI_T::I2SSTS: RXTHIF Position         */
#define SPI_I2SSTS_RXTHIF_Msk            (0x1ul << SPI_I2SSTS_RXTHIF_Pos)                  /*!< SPI_T::I2SSTS: RXTHIF Mask             */

#define SPI_I2SSTS_RXOVIF_Pos            (11)                                              /*!< SPI_T::I2SSTS: RXOVIF Position         */
#define SPI_I2SSTS_RXOVIF_Msk            (0x1ul << SPI_I2SSTS_RXOVIF_Pos)                  /*!< SPI_T::I2SSTS: RXOVIF Mask             */

#define SPI_I2SSTS_RXTOIF_Pos            (12)                                              /*!< SPI_T::I2SSTS: RXTOIF Position         */
#define SPI_I2SSTS_RXTOIF_Msk            (0x1ul << SPI_I2SSTS_RXTOIF_Pos)                  /*!< SPI_T::I2SSTS: RXTOIF Mask             */

#define SPI_I2SSTS_I2SENSTS_Pos          (15)                                              /*!< SPI_T::I2SSTS: I2SENSTS Position       */
#define SPI_I2SSTS_I2SENSTS_Msk          (0x1ul << SPI_I2SSTS_I2SENSTS_Pos)                /*!< SPI_T::I2SSTS: I2SENSTS Mask           */

#define SPI_I2SSTS_TXEMPTY_Pos           (16)                                              /*!< SPI_T::I2SSTS: TXEMPTY Position        */
#define SPI_I2SSTS_TXEMPTY_Msk           (0x1ul << SPI_I2SSTS_TXEMPTY_Pos)                 /*!< SPI_T::I2SSTS: TXEMPTY Mask            */

#define SPI_I2SSTS_TXFULL_Pos            (17)                                              /*!< SPI_T::I2SSTS: TXFULL Position         */
#define SPI_I2SSTS_TXFULL_Msk            (0x1ul << SPI_I2SSTS_TXFULL_Pos)                  /*!< SPI_T::I2SSTS: TXFULL Mask             */

#define SPI_I2SSTS_TXTHIF_Pos            (18)                                              /*!< SPI_T::I2SSTS: TXTHIF Position         */
#define SPI_I2SSTS_TXTHIF_Msk            (0x1ul << SPI_I2SSTS_TXTHIF_Pos)                  /*!< SPI_T::I2SSTS: TXTHIF Mask             */

#define SPI_I2SSTS_TXUFIF_Pos            (19)                                              /*!< SPI_T::I2SSTS: TXUFIF Position         */
#define SPI_I2SSTS_TXUFIF_Msk            (0x1ul << SPI_I2SSTS_TXUFIF_Pos)                  /*!< SPI_T::I2SSTS: TXUFIF Mask             */

#define SPI_I2SSTS_RZCIF_Pos             (20)                                              /*!< SPI_T::I2SSTS: RZCIF Position          */
#define SPI_I2SSTS_RZCIF_Msk             (0x1ul << SPI_I2SSTS_RZCIF_Pos)                   /*!< SPI_T::I2SSTS: RZCIF Mask              */

#define SPI_I2SSTS_LZCIF_Pos             (21)                                              /*!< SPI_T::I2SSTS: LZCIF Position          */
#define SPI_I2SSTS_LZCIF_Msk             (0x1ul << SPI_I2SSTS_LZCIF_Pos)                   /*!< SPI_T::I2SSTS: LZCIF Mask              */

#define SPI_I2SSTS_TXRXRST_Pos           (23)                                              /*!< SPI_T::I2SSTS: TXRXRST Position        */
#define SPI_I2SSTS_TXRXRST_Msk           (0x1ul << SPI_I2SSTS_TXRXRST_Pos)                 /*!< SPI_T::I2SSTS: TXRXRST Mask            */

#define SPI_I2SSTS_RXCNT_Pos             (24)                                              /*!< SPI_T::I2SSTS: RXCNT Position          */
#define SPI_I2SSTS_RXCNT_Msk             (0x7ul << SPI_I2SSTS_RXCNT_Pos)                   /*!< SPI_T::I2SSTS: RXCNT Mask              */

#define SPI_I2SSTS_TXCNT_Pos             (28)                                              /*!< SPI_T::I2SSTS: TXCNT Position          */
#define SPI_I2SSTS_TXCNT_Msk             (0x7ul << SPI_I2SSTS_TXCNT_Pos)                   /*!< SPI_T::I2SSTS: TXCNT Mask              */

/**@}*/ /* SPI_CONST */
/**@}*/ /* end of SPI register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __SPI_REG_H__ */
