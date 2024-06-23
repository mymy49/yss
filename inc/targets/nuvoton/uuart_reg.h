/**************************************************************************//**
 * @file     uuart_reg.h
 * @version  V1.00
 * @brief    UUART register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __UUART_REG_H__
#define __UUART_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/**
    @addtogroup UUART_CONST UUART Bit Field Definition
    Constant Definitions for UUART Controller
@{ */

#define UUART_CTL_FUNMODE_Pos            (0)                                               /*!< UUART_T::CTL: FUNMODE Position         */
#define UUART_CTL_FUNMODE_Msk            (0x7ul << UUART_CTL_FUNMODE_Pos)                  /*!< UUART_T::CTL: FUNMODE Mask             */

#define UUART_INTEN_TXSTIEN_Pos          (1)                                               /*!< UUART_T::INTEN: TXSTIEN Position       */
#define UUART_INTEN_TXSTIEN_Msk          (0x1ul << UUART_INTEN_TXSTIEN_Pos)                /*!< UUART_T::INTEN: TXSTIEN Mask           */

#define UUART_INTEN_TXENDIEN_Pos         (2)                                               /*!< UUART_T::INTEN: TXENDIEN Position      */
#define UUART_INTEN_TXENDIEN_Msk         (0x1ul << UUART_INTEN_TXENDIEN_Pos)               /*!< UUART_T::INTEN: TXENDIEN Mask          */

#define UUART_INTEN_RXSTIEN_Pos          (3)                                               /*!< UUART_T::INTEN: RXSTIEN Position       */
#define UUART_INTEN_RXSTIEN_Msk          (0x1ul << UUART_INTEN_RXSTIEN_Pos)                /*!< UUART_T::INTEN: RXSTIEN Mask           */

#define UUART_INTEN_RXENDIEN_Pos         (4)                                               /*!< UUART_T::INTEN: RXENDIEN Position      */
#define UUART_INTEN_RXENDIEN_Msk         (0x1ul << UUART_INTEN_RXENDIEN_Pos)               /*!< UUART_T::INTEN: RXENDIEN Mask          */

#define UUART_BRGEN_RCLKSEL_Pos          (0)                                               /*!< UUART_T::BRGEN: RCLKSEL Position       */
#define UUART_BRGEN_RCLKSEL_Msk          (0x1ul << UUART_BRGEN_RCLKSEL_Pos)                /*!< UUART_T::BRGEN: RCLKSEL Mask           */

#define UUART_BRGEN_PTCLKSEL_Pos         (1)                                               /*!< UUART_T::BRGEN: PTCLKSEL Position      */
#define UUART_BRGEN_PTCLKSEL_Msk         (0x1ul << UUART_BRGEN_PTCLKSEL_Pos)               /*!< UUART_T::BRGEN: PTCLKSEL Mask          */

#define UUART_BRGEN_SPCLKSEL_Pos         (2)                                               /*!< UUART_T::BRGEN: SPCLKSEL Position      */
#define UUART_BRGEN_SPCLKSEL_Msk         (0x3ul << UUART_BRGEN_SPCLKSEL_Pos)               /*!< UUART_T::BRGEN: SPCLKSEL Mask          */

#define UUART_BRGEN_TMCNTEN_Pos          (4)                                               /*!< UUART_T::BRGEN: TMCNTEN Position       */
#define UUART_BRGEN_TMCNTEN_Msk          (0x1ul << UUART_BRGEN_TMCNTEN_Pos)                /*!< UUART_T::BRGEN: TMCNTEN Mask           */

#define UUART_BRGEN_TMCNTSRC_Pos         (5)                                               /*!< UUART_T::BRGEN: TMCNTSRC Position      */
#define UUART_BRGEN_TMCNTSRC_Msk         (0x1ul << UUART_BRGEN_TMCNTSRC_Pos)               /*!< UUART_T::BRGEN: TMCNTSRC Mask          */

#define UUART_BRGEN_PDSCNT_Pos           (8)                                               /*!< UUART_T::BRGEN: PDSCNT Position        */
#define UUART_BRGEN_PDSCNT_Msk           (0x3ul << UUART_BRGEN_PDSCNT_Pos)                 /*!< UUART_T::BRGEN: PDSCNT Mask            */

#define UUART_BRGEN_DSCNT_Pos            (10)                                              /*!< UUART_T::BRGEN: DSCNT Position         */
#define UUART_BRGEN_DSCNT_Msk            (0x1ful << UUART_BRGEN_DSCNT_Pos)                 /*!< UUART_T::BRGEN: DSCNT Mask             */

#define UUART_BRGEN_CLKDIV_Pos           (16)                                              /*!< UUART_T::BRGEN: CLKDIV Position        */
#define UUART_BRGEN_CLKDIV_Msk           (0x3fful << UUART_BRGEN_CLKDIV_Pos)               /*!< UUART_T::BRGEN: CLKDIV Mask            */

#define UUART_DATIN0_SYNCSEL_Pos         (0)                                               /*!< UUART_T::DATIN0: SYNCSEL Position      */
#define UUART_DATIN0_SYNCSEL_Msk         (0x1ul << UUART_DATIN0_SYNCSEL_Pos)               /*!< UUART_T::DATIN0: SYNCSEL Mask          */

#define UUART_DATIN0_ININV_Pos           (2)                                               /*!< UUART_T::DATIN0: ININV Position        */
#define UUART_DATIN0_ININV_Msk           (0x1ul << UUART_DATIN0_ININV_Pos)                 /*!< UUART_T::DATIN0: ININV Mask            */

#define UUART_DATIN0_EDGEDET_Pos         (3)                                               /*!< UUART_T::DATIN0: EDGEDET Position      */
#define UUART_DATIN0_EDGEDET_Msk         (0x3ul << UUART_DATIN0_EDGEDET_Pos)               /*!< UUART_T::DATIN0: EDGEDET Mask          */

#define UUART_CTLIN0_SYNCSEL_Pos         (0)                                               /*!< UUART_T::CTLIN0: SYNCSEL Position      */
#define UUART_CTLIN0_SYNCSEL_Msk         (0x1ul << UUART_CTLIN0_SYNCSEL_Pos)               /*!< UUART_T::CTLIN0: SYNCSEL Mask          */

#define UUART_CTLIN0_ININV_Pos           (2)                                               /*!< UUART_T::CTLIN0: ININV Position        */
#define UUART_CTLIN0_ININV_Msk           (0x1ul << UUART_CTLIN0_ININV_Pos)                 /*!< UUART_T::CTLIN0: ININV Mask            */

#define UUART_CLKIN_SYNCSEL_Pos          (0)                                               /*!< UUART_T::CLKIN: SYNCSEL Position       */
#define UUART_CLKIN_SYNCSEL_Msk          (0x1ul << UUART_CLKIN_SYNCSEL_Pos)                /*!< UUART_T::CLKIN: SYNCSEL Mask           */

#define UUART_LINECTL_LSB_Pos            (0)                                               /*!< UUART_T::LINECTL: LSB Position         */
#define UUART_LINECTL_LSB_Msk            (0x1ul << UUART_LINECTL_LSB_Pos)                  /*!< UUART_T::LINECTL: LSB Mask             */

#define UUART_LINECTL_DATOINV_Pos        (5)                                               /*!< UUART_T::LINECTL: DATOINV Position     */
#define UUART_LINECTL_DATOINV_Msk        (0x1ul << UUART_LINECTL_DATOINV_Pos)              /*!< UUART_T::LINECTL: DATOINV Mask         */

#define UUART_LINECTL_CTLOINV_Pos        (7)                                               /*!< UUART_T::LINECTL: CTLOINV Position     */
#define UUART_LINECTL_CTLOINV_Msk        (0x1ul << UUART_LINECTL_CTLOINV_Pos)              /*!< UUART_T::LINECTL: CTLOINV Mask         */

#define UUART_LINECTL_DWIDTH_Pos         (8)                                               /*!< UUART_T::LINECTL: DWIDTH Position      */
#define UUART_LINECTL_DWIDTH_Msk         (0xful << UUART_LINECTL_DWIDTH_Pos)               /*!< UUART_T::LINECTL: DWIDTH Mask          */

#define UUART_TXDAT_TXDAT_Pos            (0)                                               /*!< UUART_T::TXDAT: TXDAT Position         */
#define UUART_TXDAT_TXDAT_Msk            (0xfffful << UUART_TXDAT_TXDAT_Pos)               /*!< UUART_T::TXDAT: TXDAT Mask             */

#define UUART_RXDAT_RXDAT_Pos            (0)                                               /*!< UUART_T::RXDAT: RXDAT Position         */
#define UUART_RXDAT_RXDAT_Msk            (0xfffful << UUART_RXDAT_RXDAT_Pos)               /*!< UUART_T::RXDAT: RXDAT Mask             */

#define UUART_BUFCTL_TXCLR_Pos           (7)                                               /*!< UUART_T::BUFCTL: TXCLR Position        */
#define UUART_BUFCTL_TXCLR_Msk           (0x1ul << UUART_BUFCTL_TXCLR_Pos)                 /*!< UUART_T::BUFCTL: TXCLR Mask            */

#define UUART_BUFCTL_RXOVIEN_Pos         (14)                                              /*!< UUART_T::BUFCTL: RXOVIEN Position      */
#define UUART_BUFCTL_RXOVIEN_Msk         (0x1ul << UUART_BUFCTL_RXOVIEN_Pos)               /*!< UUART_T::BUFCTL: RXOVIEN Mask          */

#define UUART_BUFCTL_RXCLR_Pos           (15)                                              /*!< UUART_T::BUFCTL: RXCLR Position        */
#define UUART_BUFCTL_RXCLR_Msk           (0x1ul << UUART_BUFCTL_RXCLR_Pos)                 /*!< UUART_T::BUFCTL: RXCLR Mask            */

#define UUART_BUFCTL_TXRST_Pos           (16)                                              /*!< UUART_T::BUFCTL: TXRST Position        */
#define UUART_BUFCTL_TXRST_Msk           (0x1ul << UUART_BUFCTL_TXRST_Pos)                 /*!< UUART_T::BUFCTL: TXRST Mask            */

#define UUART_BUFCTL_RXRST_Pos           (17)                                              /*!< UUART_T::BUFCTL: RXRST Position        */
#define UUART_BUFCTL_RXRST_Msk           (0x1ul << UUART_BUFCTL_RXRST_Pos)                 /*!< UUART_T::BUFCTL: RXRST Mask            */

#define UUART_BUFSTS_RXEMPTY_Pos         (0)                                               /*!< UUART_T::BUFSTS: RXEMPTY Position      */
#define UUART_BUFSTS_RXEMPTY_Msk         (0x1ul << UUART_BUFSTS_RXEMPTY_Pos)               /*!< UUART_T::BUFSTS: RXEMPTY Mask          */

#define UUART_BUFSTS_RXFULL_Pos          (1)                                               /*!< UUART_T::BUFSTS: RXFULL Position       */
#define UUART_BUFSTS_RXFULL_Msk          (0x1ul << UUART_BUFSTS_RXFULL_Pos)                /*!< UUART_T::BUFSTS: RXFULL Mask           */

#define UUART_BUFSTS_RXOVIF_Pos          (3)                                               /*!< UUART_T::BUFSTS: RXOVIF Position       */
#define UUART_BUFSTS_RXOVIF_Msk          (0x1ul << UUART_BUFSTS_RXOVIF_Pos)                /*!< UUART_T::BUFSTS: RXOVIF Mask           */

#define UUART_BUFSTS_TXEMPTY_Pos         (8)                                               /*!< UUART_T::BUFSTS: TXEMPTY Position      */
#define UUART_BUFSTS_TXEMPTY_Msk         (0x1ul << UUART_BUFSTS_TXEMPTY_Pos)               /*!< UUART_T::BUFSTS: TXEMPTY Mask          */

#define UUART_BUFSTS_TXFULL_Pos          (9)                                               /*!< UUART_T::BUFSTS: TXFULL Position       */
#define UUART_BUFSTS_TXFULL_Msk          (0x1ul << UUART_BUFSTS_TXFULL_Pos)                /*!< UUART_T::BUFSTS: TXFULL Mask           */

#define UUART_PDMACTL_PDMARST_Pos        (0)                                               /*!< UUART_T::PDMACTL: PDMARST Position     */
#define UUART_PDMACTL_PDMARST_Msk        (0x1ul << UUART_PDMACTL_PDMARST_Pos)              /*!< UUART_T::PDMACTL: PDMARST Mask         */

#define UUART_PDMACTL_TXPDMAEN_Pos       (1)                                               /*!< UUART_T::PDMACTL: TXPDMAEN Position    */
#define UUART_PDMACTL_TXPDMAEN_Msk       (0x1ul << UUART_PDMACTL_TXPDMAEN_Pos)             /*!< UUART_T::PDMACTL: TXPDMAEN Mask        */

#define UUART_PDMACTL_RXPDMAEN_Pos       (2)                                               /*!< UUART_T::PDMACTL: RXPDMAEN Position    */
#define UUART_PDMACTL_RXPDMAEN_Msk       (0x1ul << UUART_PDMACTL_RXPDMAEN_Pos)             /*!< UUART_T::PDMACTL: RXPDMAEN Mask        */

#define UUART_PDMACTL_PDMAEN_Pos         (3)                                               /*!< UUART_T::PDMACTL: PDMAEN Position      */
#define UUART_PDMACTL_PDMAEN_Msk         (0x1ul << UUART_PDMACTL_PDMAEN_Pos)               /*!< UUART_T::PDMACTL: PDMAEN Mask          */

#define UUART_WKCTL_WKEN_Pos             (0)                                               /*!< UUART_T::WKCTL: WKEN Position          */
#define UUART_WKCTL_WKEN_Msk             (0x1ul << UUART_WKCTL_WKEN_Pos)                   /*!< UUART_T::WKCTL: WKEN Mask              */

#define UUART_WKCTL_PDBOPT_Pos           (2)                                               /*!< UUART_T::WKCTL: PDBOPT Position        */
#define UUART_WKCTL_PDBOPT_Msk           (0x1ul << UUART_WKCTL_PDBOPT_Pos)                 /*!< UUART_T::WKCTL: PDBOPT Mask            */

#define UUART_WKSTS_WKF_Pos              (0)                                               /*!< UUART_T::WKSTS: WKF Position           */
#define UUART_WKSTS_WKF_Msk              (0x1ul << UUART_WKSTS_WKF_Pos)                    /*!< UUART_T::WKSTS: WKF Mask               */

#define UUART_PROTCTL_STOPB_Pos          (0)                                               /*!< UUART_T::PROTCTL: STOPB Position       */
#define UUART_PROTCTL_STOPB_Msk          (0x1ul << UUART_PROTCTL_STOPB_Pos)                /*!< UUART_T::PROTCTL: STOPB Mask           */

#define UUART_PROTCTL_PARITYEN_Pos       (1)                                               /*!< UUART_T::PROTCTL: PARITYEN Position    */
#define UUART_PROTCTL_PARITYEN_Msk       (0x1ul << UUART_PROTCTL_PARITYEN_Pos)             /*!< UUART_T::PROTCTL: PARITYEN Mask        */

#define UUART_PROTCTL_EVENPARITY_Pos     (2)                                               /*!< UUART_T::PROTCTL: EVENPARITY Position  */
#define UUART_PROTCTL_EVENPARITY_Msk     (0x1ul << UUART_PROTCTL_EVENPARITY_Pos)           /*!< UUART_T::PROTCTL: EVENPARITY Mask      */

#define UUART_PROTCTL_RTSAUTOEN_Pos      (3)                                               /*!< UUART_T::PROTCTL: RTSAUTOEN Position   */
#define UUART_PROTCTL_RTSAUTOEN_Msk      (0x1ul << UUART_PROTCTL_RTSAUTOEN_Pos)            /*!< UUART_T::PROTCTL: RTSAUTOEN Mask       */

#define UUART_PROTCTL_CTSAUTOEN_Pos      (4)                                               /*!< UUART_T::PROTCTL: CTSAUTOEN Position   */
#define UUART_PROTCTL_CTSAUTOEN_Msk      (0x1ul << UUART_PROTCTL_CTSAUTOEN_Pos)            /*!< UUART_T::PROTCTL: CTSAUTOEN Mask       */

#define UUART_PROTCTL_RTSAUDIREN_Pos     (5)                                               /*!< UUART_T::PROTCTL: RTSAUDIREN Position  */
#define UUART_PROTCTL_RTSAUDIREN_Msk     (0x1ul << UUART_PROTCTL_RTSAUDIREN_Pos)           /*!< UUART_T::PROTCTL: RTSAUDIREN Mask      */

#define UUART_PROTCTL_ABREN_Pos          (6)                                               /*!< UUART_T::PROTCTL: ABREN Position       */
#define UUART_PROTCTL_ABREN_Msk          (0x1ul << UUART_PROTCTL_ABREN_Pos)                /*!< UUART_T::PROTCTL: ABREN Mask           */

#define UUART_PROTCTL_DATWKEN_Pos        (9)                                               /*!< UUART_T::PROTCTL: DATWKEN Position     */
#define UUART_PROTCTL_DATWKEN_Msk        (0x1ul << UUART_PROTCTL_DATWKEN_Pos)              /*!< UUART_T::PROTCTL: DATWKEN Mask         */

#define UUART_PROTCTL_CTSWKEN_Pos        (10)                                              /*!< UUART_T::PROTCTL: CTSWKEN Position     */
#define UUART_PROTCTL_CTSWKEN_Msk        (0x1ul << UUART_PROTCTL_CTSWKEN_Pos)              /*!< UUART_T::PROTCTL: CTSWKEN Mask         */

#define UUART_PROTCTL_WAKECNT_Pos        (11)                                              /*!< UUART_T::PROTCTL: WAKECNT Position     */
#define UUART_PROTCTL_WAKECNT_Msk        (0xful << UUART_PROTCTL_WAKECNT_Pos)              /*!< UUART_T::PROTCTL: WAKECNT Mask         */

#define UUART_PROTCTL_BRDETITV_Pos       (16)                                              /*!< UUART_T::PROTCTL: BRDETITV Position    */
#define UUART_PROTCTL_BRDETITV_Msk       (0x1fful << UUART_PROTCTL_BRDETITV_Pos)           /*!< UUART_T::PROTCTL: BRDETITV Mask        */

#define UUART_PROTCTL_STICKEN_Pos        (26)                                              /*!< UUART_T::PROTCTL: STICKEN Position     */
#define UUART_PROTCTL_STICKEN_Msk        (0x1ul << UUART_PROTCTL_STICKEN_Pos)              /*!< UUART_T::PROTCTL: STICKEN Mask         */

#define UUART_PROTCTL_BCEN_Pos           (29)                                              /*!< UUART_T::PROTCTL: BCEN Position        */
#define UUART_PROTCTL_BCEN_Msk           (0x1ul << UUART_PROTCTL_BCEN_Pos)                 /*!< UUART_T::PROTCTL: BCEN Mask            */

#define UUART_PROTCTL_PROTEN_Pos         (31)                                              /*!< UUART_T::PROTCTL: PROTEN Position      */
#define UUART_PROTCTL_PROTEN_Msk         (0x1ul << UUART_PROTCTL_PROTEN_Pos)               /*!< UUART_T::PROTCTL: PROTEN Mask          */

#define UUART_PROTIEN_ABRIEN_Pos         (1)                                               /*!< UUART_T::PROTIEN: ABRIEN Position      */
#define UUART_PROTIEN_ABRIEN_Msk         (0x1ul << UUART_PROTIEN_ABRIEN_Pos)               /*!< UUART_T::PROTIEN: ABRIEN Mask          */

#define UUART_PROTIEN_RLSIEN_Pos         (2)                                               /*!< UUART_T::PROTIEN: RLSIEN Position      */
#define UUART_PROTIEN_RLSIEN_Msk         (0x1ul << UUART_PROTIEN_RLSIEN_Pos)               /*!< UUART_T::PROTIEN: RLSIEN Mask          */

#define UUART_PROTSTS_TXSTIF_Pos         (1)                                               /*!< UUART_T::PROTSTS: TXSTIF Position      */
#define UUART_PROTSTS_TXSTIF_Msk         (0x1ul << UUART_PROTSTS_TXSTIF_Pos)               /*!< UUART_T::PROTSTS: TXSTIF Mask          */

#define UUART_PROTSTS_TXENDIF_Pos        (2)                                               /*!< UUART_T::PROTSTS: TXENDIF Position     */
#define UUART_PROTSTS_TXENDIF_Msk        (0x1ul << UUART_PROTSTS_TXENDIF_Pos)              /*!< UUART_T::PROTSTS: TXENDIF Mask         */

#define UUART_PROTSTS_RXSTIF_Pos         (3)                                               /*!< UUART_T::PROTSTS: RXSTIF Position      */
#define UUART_PROTSTS_RXSTIF_Msk         (0x1ul << UUART_PROTSTS_RXSTIF_Pos)               /*!< UUART_T::PROTSTS: RXSTIF Mask          */

#define UUART_PROTSTS_RXENDIF_Pos        (4)                                               /*!< UUART_T::PROTSTS: RXENDIF Position     */
#define UUART_PROTSTS_RXENDIF_Msk        (0x1ul << UUART_PROTSTS_RXENDIF_Pos)              /*!< UUART_T::PROTSTS: RXENDIF Mask         */

#define UUART_PROTSTS_PARITYERR_Pos      (5)                                               /*!< UUART_T::PROTSTS: PARITYERR Position   */
#define UUART_PROTSTS_PARITYERR_Msk      (0x1ul << UUART_PROTSTS_PARITYERR_Pos)            /*!< UUART_T::PROTSTS: PARITYERR Mask       */

#define UUART_PROTSTS_FRMERR_Pos         (6)                                               /*!< UUART_T::PROTSTS: FRMERR Position      */
#define UUART_PROTSTS_FRMERR_Msk         (0x1ul << UUART_PROTSTS_FRMERR_Pos)               /*!< UUART_T::PROTSTS: FRMERR Mask          */

#define UUART_PROTSTS_BREAK_Pos          (7)                                               /*!< UUART_T::PROTSTS: BREAK Position       */
#define UUART_PROTSTS_BREAK_Msk          (0x1ul << UUART_PROTSTS_BREAK_Pos)                /*!< UUART_T::PROTSTS: BREAK Mask           */

#define UUART_PROTSTS_ABRDETIF_Pos       (9)                                               /*!< UUART_T::PROTSTS: ABRDETIF Position    */
#define UUART_PROTSTS_ABRDETIF_Msk       (0x1ul << UUART_PROTSTS_ABRDETIF_Pos)             /*!< UUART_T::PROTSTS: ABRDETIF Mask        */

#define UUART_PROTSTS_RXBUSY_Pos         (10)                                              /*!< UUART_T::PROTSTS: RXBUSY Position      */
#define UUART_PROTSTS_RXBUSY_Msk         (0x1ul << UUART_PROTSTS_RXBUSY_Pos)               /*!< UUART_T::PROTSTS: RXBUSY Mask          */

#define UUART_PROTSTS_ABERRSTS_Pos       (11)                                              /*!< UUART_T::PROTSTS: ABERRSTS Position    */
#define UUART_PROTSTS_ABERRSTS_Msk       (0x1ul << UUART_PROTSTS_ABERRSTS_Pos)             /*!< UUART_T::PROTSTS: ABERRSTS Mask        */

#define UUART_PROTSTS_CTSSYNCLV_Pos      (16)                                              /*!< UUART_T::PROTSTS: CTSSYNCLV Position   */
#define UUART_PROTSTS_CTSSYNCLV_Msk      (0x1ul << UUART_PROTSTS_CTSSYNCLV_Pos)            /*!< UUART_T::PROTSTS: CTSSYNCLV Mask       */

#define UUART_PROTSTS_CTSLV_Pos          (17)                                              /*!< UUART_T::PROTSTS: CTSLV Position       */
#define UUART_PROTSTS_CTSLV_Msk          (0x1ul << UUART_PROTSTS_CTSLV_Pos)                /*!< UUART_T::PROTSTS: CTSLV Mask           */

/**@}*/ /* UUART_CONST */
/**@}*/ /* end of UUART register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __UUART_REG_H__ */
