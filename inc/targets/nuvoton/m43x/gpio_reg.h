/**************************************************************************//**
 * @file     gpio_reg.h
 * @version  V1.00
 * @brief    GPIO register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __GPIO_REG_H__
#define __GPIO_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
    @addtogroup GPIO_CONST GPIO Bit Field Definition
    Constant Definitions for GPIO Controller
@{ */

#define GPIO_MODE_MODE0_Pos              (0)                                               /*!< GPIO_T::MODE: MODE0 Position              */
#define GPIO_MODE_MODE0_Msk              (0x3ul << GPIO_MODE_MODE0_Pos)                    /*!< GPIO_T::MODE: MODE0 Mask                  */

#define GPIO_MODE_MODE1_Pos              (2)                                               /*!< GPIO_T::MODE: MODE1 Position              */
#define GPIO_MODE_MODE1_Msk              (0x3ul << GPIO_MODE_MODE1_Pos)                    /*!< GPIO_T::MODE: MODE1 Mask                  */

#define GPIO_MODE_MODE2_Pos              (4)                                               /*!< GPIO_T::MODE: MODE2 Position              */
#define GPIO_MODE_MODE2_Msk              (0x3ul << GPIO_MODE_MODE2_Pos)                    /*!< GPIO_T::MODE: MODE2 Mask                  */

#define GPIO_MODE_MODE3_Pos              (6)                                               /*!< GPIO_T::MODE: MODE3 Position              */
#define GPIO_MODE_MODE3_Msk              (0x3ul << GPIO_MODE_MODE3_Pos)                    /*!< GPIO_T::MODE: MODE3 Mask                  */

#define GPIO_MODE_MODE4_Pos              (8)                                               /*!< GPIO_T::MODE: MODE4 Position              */
#define GPIO_MODE_MODE4_Msk              (0x3ul << GPIO_MODE_MODE4_Pos)                    /*!< GPIO_T::MODE: MODE4 Mask                  */

#define GPIO_MODE_MODE5_Pos              (10)                                              /*!< GPIO_T::MODE: MODE5 Position              */
#define GPIO_MODE_MODE5_Msk              (0x3ul << GPIO_MODE_MODE5_Pos)                    /*!< GPIO_T::MODE: MODE5 Mask                  */

#define GPIO_MODE_MODE6_Pos              (12)                                              /*!< GPIO_T::MODE: MODE6 Position              */
#define GPIO_MODE_MODE6_Msk              (0x3ul << GPIO_MODE_MODE6_Pos)                    /*!< GPIO_T::MODE: MODE6 Mask                  */

#define GPIO_MODE_MODE7_Pos              (14)                                              /*!< GPIO_T::MODE: MODE7 Position              */
#define GPIO_MODE_MODE7_Msk              (0x3ul << GPIO_MODE_MODE7_Pos)                    /*!< GPIO_T::MODE: MODE7 Mask                  */

#define GPIO_MODE_MODE8_Pos              (16)                                              /*!< GPIO_T::MODE: MODE8 Position              */
#define GPIO_MODE_MODE8_Msk              (0x3ul << GPIO_MODE_MODE8_Pos)                    /*!< GPIO_T::MODE: MODE8 Mask                  */

#define GPIO_MODE_MODE9_Pos              (18)                                              /*!< GPIO_T::MODE: MODE9 Position              */
#define GPIO_MODE_MODE9_Msk              (0x3ul << GPIO_MODE_MODE9_Pos)                    /*!< GPIO_T::MODE: MODE9 Mask                  */

#define GPIO_MODE_MODE10_Pos             (20)                                              /*!< GPIO_T::MODE: MODE10 Position             */
#define GPIO_MODE_MODE10_Msk             (0x3ul << GPIO_MODE_MODE10_Pos)                   /*!< GPIO_T::MODE: MODE10 Mask                 */

#define GPIO_MODE_MODE11_Pos             (22)                                              /*!< GPIO_T::MODE: MODE11 Position             */
#define GPIO_MODE_MODE11_Msk             (0x3ul << GPIO_MODE_MODE11_Pos)                   /*!< GPIO_T::MODE: MODE11 Mask                 */

#define GPIO_MODE_MODE12_Pos             (24)                                              /*!< GPIO_T::MODE: MODE12 Position             */
#define GPIO_MODE_MODE12_Msk             (0x3ul << GPIO_MODE_MODE12_Pos)                   /*!< GPIO_T::MODE: MODE12 Mask                 */

#define GPIO_MODE_MODE13_Pos             (26)                                              /*!< GPIO_T::MODE: MODE13 Position             */
#define GPIO_MODE_MODE13_Msk             (0x3ul << GPIO_MODE_MODE13_Pos)                   /*!< GPIO_T::MODE: MODE13 Mask                 */

#define GPIO_MODE_MODE14_Pos             (28)                                              /*!< GPIO_T::MODE: MODE14 Position             */
#define GPIO_MODE_MODE14_Msk             (0x3ul << GPIO_MODE_MODE14_Pos)                   /*!< GPIO_T::MODE: MODE14 Mask                 */

#define GPIO_MODE_MODE15_Pos             (30)                                              /*!< GPIO_T::MODE: MODE15 Position             */
#define GPIO_MODE_MODE15_Msk             (0x3ul << GPIO_MODE_MODE15_Pos)                   /*!< GPIO_T::MODE: MODE15 Mask                 */

#define GPIO_DINOFF_DINOFF0_Pos          (16)                                              /*!< GPIO_T::DINOFF: DINOFF0 Position          */
#define GPIO_DINOFF_DINOFF0_Msk          (0x1ul << GPIO_DINOFF_DINOFF0_Pos)                /*!< GPIO_T::DINOFF: DINOFF0 Mask              */

#define GPIO_DINOFF_DINOFF1_Pos          (17)                                              /*!< GPIO_T::DINOFF: DINOFF1 Position          */
#define GPIO_DINOFF_DINOFF1_Msk          (0x1ul << GPIO_DINOFF_DINOFF1_Pos)                /*!< GPIO_T::DINOFF: DINOFF1 Mask              */

#define GPIO_DINOFF_DINOFF2_Pos          (18)                                              /*!< GPIO_T::DINOFF: DINOFF2 Position          */
#define GPIO_DINOFF_DINOFF2_Msk          (0x1ul << GPIO_DINOFF_DINOFF2_Pos)                /*!< GPIO_T::DINOFF: DINOFF2 Mask              */

#define GPIO_DINOFF_DINOFF3_Pos          (19)                                              /*!< GPIO_T::DINOFF: DINOFF3 Position          */
#define GPIO_DINOFF_DINOFF3_Msk          (0x1ul << GPIO_DINOFF_DINOFF3_Pos)                /*!< GPIO_T::DINOFF: DINOFF3 Mask              */

#define GPIO_DINOFF_DINOFF4_Pos          (20)                                              /*!< GPIO_T::DINOFF: DINOFF4 Position          */
#define GPIO_DINOFF_DINOFF4_Msk          (0x1ul << GPIO_DINOFF_DINOFF4_Pos)                /*!< GPIO_T::DINOFF: DINOFF4 Mask              */

#define GPIO_DINOFF_DINOFF5_Pos          (21)                                              /*!< GPIO_T::DINOFF: DINOFF5 Position          */
#define GPIO_DINOFF_DINOFF5_Msk          (0x1ul << GPIO_DINOFF_DINOFF5_Pos)                /*!< GPIO_T::DINOFF: DINOFF5 Mask              */

#define GPIO_DINOFF_DINOFF6_Pos          (22)                                              /*!< GPIO_T::DINOFF: DINOFF6 Position          */
#define GPIO_DINOFF_DINOFF6_Msk          (0x1ul << GPIO_DINOFF_DINOFF6_Pos)                /*!< GPIO_T::DINOFF: DINOFF6 Mask              */

#define GPIO_DINOFF_DINOFF7_Pos          (23)                                              /*!< GPIO_T::DINOFF: DINOFF7 Position          */
#define GPIO_DINOFF_DINOFF7_Msk          (0x1ul << GPIO_DINOFF_DINOFF7_Pos)                /*!< GPIO_T::DINOFF: DINOFF7 Mask              */

#define GPIO_DINOFF_DINOFF8_Pos          (24)                                              /*!< GPIO_T::DINOFF: DINOFF8 Position          */
#define GPIO_DINOFF_DINOFF8_Msk          (0x1ul << GPIO_DINOFF_DINOFF8_Pos)                /*!< GPIO_T::DINOFF: DINOFF8 Mask              */

#define GPIO_DINOFF_DINOFF9_Pos          (25)                                              /*!< GPIO_T::DINOFF: DINOFF9 Position          */
#define GPIO_DINOFF_DINOFF9_Msk          (0x1ul << GPIO_DINOFF_DINOFF9_Pos)                /*!< GPIO_T::DINOFF: DINOFF9 Mask              */

#define GPIO_DINOFF_DINOFF10_Pos         (26)                                              /*!< GPIO_T::DINOFF: DINOFF10 Position         */
#define GPIO_DINOFF_DINOFF10_Msk         (0x1ul << GPIO_DINOFF_DINOFF10_Pos)               /*!< GPIO_T::DINOFF: DINOFF10 Mask             */

#define GPIO_DINOFF_DINOFF11_Pos         (27)                                              /*!< GPIO_T::DINOFF: DINOFF11 Position         */
#define GPIO_DINOFF_DINOFF11_Msk         (0x1ul << GPIO_DINOFF_DINOFF11_Pos)               /*!< GPIO_T::DINOFF: DINOFF11 Mask             */

#define GPIO_DINOFF_DINOFF12_Pos         (28)                                              /*!< GPIO_T::DINOFF: DINOFF12 Position         */
#define GPIO_DINOFF_DINOFF12_Msk         (0x1ul << GPIO_DINOFF_DINOFF12_Pos)               /*!< GPIO_T::DINOFF: DINOFF12 Mask             */

#define GPIO_DINOFF_DINOFF13_Pos         (29)                                              /*!< GPIO_T::DINOFF: DINOFF13 Position         */
#define GPIO_DINOFF_DINOFF13_Msk         (0x1ul << GPIO_DINOFF_DINOFF13_Pos)               /*!< GPIO_T::DINOFF: DINOFF13 Mask             */

#define GPIO_DINOFF_DINOFF14_Pos         (30)                                              /*!< GPIO_T::DINOFF: DINOFF14 Position         */
#define GPIO_DINOFF_DINOFF14_Msk         (0x1ul << GPIO_DINOFF_DINOFF14_Pos)               /*!< GPIO_T::DINOFF: DINOFF14 Mask             */

#define GPIO_DINOFF_DINOFF15_Pos         (31)                                              /*!< GPIO_T::DINOFF: DINOFF15 Position         */
#define GPIO_DINOFF_DINOFF15_Msk         (0x1ul << GPIO_DINOFF_DINOFF15_Pos)               /*!< GPIO_T::DINOFF: DINOFF15 Mask             */

#define GPIO_DOUT_DOUT0_Pos              (0)                                               /*!< GPIO_T::DOUT: DOUT0 Position              */
#define GPIO_DOUT_DOUT0_Msk              (0x1ul << GPIO_DOUT_DOUT0_Pos)                    /*!< GPIO_T::DOUT: DOUT0 Mask                  */

#define GPIO_DOUT_DOUT1_Pos              (1)                                               /*!< GPIO_T::DOUT: DOUT1 Position              */
#define GPIO_DOUT_DOUT1_Msk              (0x1ul << GPIO_DOUT_DOUT1_Pos)                    /*!< GPIO_T::DOUT: DOUT1 Mask                  */

#define GPIO_DOUT_DOUT2_Pos              (2)                                               /*!< GPIO_T::DOUT: DOUT2 Position              */
#define GPIO_DOUT_DOUT2_Msk              (0x1ul << GPIO_DOUT_DOUT2_Pos)                    /*!< GPIO_T::DOUT: DOUT2 Mask                  */

#define GPIO_DOUT_DOUT3_Pos              (3)                                               /*!< GPIO_T::DOUT: DOUT3 Position              */
#define GPIO_DOUT_DOUT3_Msk              (0x1ul << GPIO_DOUT_DOUT3_Pos)                    /*!< GPIO_T::DOUT: DOUT3 Mask                  */

#define GPIO_DOUT_DOUT4_Pos              (4)                                               /*!< GPIO_T::DOUT: DOUT4 Position              */
#define GPIO_DOUT_DOUT4_Msk              (0x1ul << GPIO_DOUT_DOUT4_Pos)                    /*!< GPIO_T::DOUT: DOUT4 Mask                  */

#define GPIO_DOUT_DOUT5_Pos              (5)                                               /*!< GPIO_T::DOUT: DOUT5 Position              */
#define GPIO_DOUT_DOUT5_Msk              (0x1ul << GPIO_DOUT_DOUT5_Pos)                    /*!< GPIO_T::DOUT: DOUT5 Mask                  */

#define GPIO_DOUT_DOUT6_Pos              (6)                                               /*!< GPIO_T::DOUT: DOUT6 Position              */
#define GPIO_DOUT_DOUT6_Msk              (0x1ul << GPIO_DOUT_DOUT6_Pos)                    /*!< GPIO_T::DOUT: DOUT6 Mask                  */

#define GPIO_DOUT_DOUT7_Pos              (7)                                               /*!< GPIO_T::DOUT: DOUT7 Position              */
#define GPIO_DOUT_DOUT7_Msk              (0x1ul << GPIO_DOUT_DOUT7_Pos)                    /*!< GPIO_T::DOUT: DOUT7 Mask                  */

#define GPIO_DOUT_DOUT8_Pos              (8)                                               /*!< GPIO_T::DOUT: DOUT8 Position              */
#define GPIO_DOUT_DOUT8_Msk              (0x1ul << GPIO_DOUT_DOUT8_Pos)                    /*!< GPIO_T::DOUT: DOUT8 Mask                  */

#define GPIO_DOUT_DOUT9_Pos              (9)                                               /*!< GPIO_T::DOUT: DOUT9 Position              */
#define GPIO_DOUT_DOUT9_Msk              (0x1ul << GPIO_DOUT_DOUT9_Pos)                    /*!< GPIO_T::DOUT: DOUT9 Mask                  */

#define GPIO_DOUT_DOUT10_Pos             (10)                                              /*!< GPIO_T::DOUT: DOUT10 Position             */
#define GPIO_DOUT_DOUT10_Msk             (0x1ul << GPIO_DOUT_DOUT10_Pos)                   /*!< GPIO_T::DOUT: DOUT10 Mask                 */

#define GPIO_DOUT_DOUT11_Pos             (11)                                              /*!< GPIO_T::DOUT: DOUT11 Position             */
#define GPIO_DOUT_DOUT11_Msk             (0x1ul << GPIO_DOUT_DOUT11_Pos)                   /*!< GPIO_T::DOUT: DOUT11 Mask                 */

#define GPIO_DOUT_DOUT12_Pos             (12)                                              /*!< GPIO_T::DOUT: DOUT12 Position             */
#define GPIO_DOUT_DOUT12_Msk             (0x1ul << GPIO_DOUT_DOUT12_Pos)                   /*!< GPIO_T::DOUT: DOUT12 Mask                 */

#define GPIO_DOUT_DOUT13_Pos             (13)                                              /*!< GPIO_T::DOUT: DOUT13 Position             */
#define GPIO_DOUT_DOUT13_Msk             (0x1ul << GPIO_DOUT_DOUT13_Pos)                   /*!< GPIO_T::DOUT: DOUT13 Mask                 */

#define GPIO_DOUT_DOUT14_Pos             (14)                                              /*!< GPIO_T::DOUT: DOUT14 Position             */
#define GPIO_DOUT_DOUT14_Msk             (0x1ul << GPIO_DOUT_DOUT14_Pos)                   /*!< GPIO_T::DOUT: DOUT14 Mask                 */

#define GPIO_DOUT_DOUT15_Pos             (15)                                              /*!< GPIO_T::DOUT: DOUT15 Position             */
#define GPIO_DOUT_DOUT15_Msk             (0x1ul << GPIO_DOUT_DOUT15_Pos)                   /*!< GPIO_T::DOUT: DOUT15 Mask                 */

#define GPIO_DATMSK_DATMSK0_Pos          (0)                                               /*!< GPIO_T::DATMSK: DATMSK0 Position       */
#define GPIO_DATMSK_DATMSK0_Msk          (0x1ul << GPIO_DATMSK_DATMSK0_Pos)                /*!< GPIO_T::DATMSK: DATMSK0 Mask           */

#define GPIO_DATMSK_DATMSK1_Pos          (1)                                               /*!< GPIO_T::DATMSK: DATMSK1 Position       */
#define GPIO_DATMSK_DATMSK1_Msk          (0x1ul << GPIO_DATMSK_DATMSK1_Pos)                /*!< GPIO_T::DATMSK: DATMSK1 Mask           */

#define GPIO_DATMSK_DATMSK2_Pos          (2)                                               /*!< GPIO_T::DATMSK: DATMSK2 Position       */
#define GPIO_DATMSK_DATMSK2_Msk          (0x1ul << GPIO_DATMSK_DATMSK2_Pos)                /*!< GPIO_T::DATMSK: DATMSK2 Mask           */

#define GPIO_DATMSK_DATMSK3_Pos          (3)                                               /*!< GPIO_T::DATMSK: DATMSK3 Position       */
#define GPIO_DATMSK_DATMSK3_Msk          (0x1ul << GPIO_DATMSK_DATMSK3_Pos)                /*!< GPIO_T::DATMSK: DATMSK3 Mask           */

#define GPIO_DATMSK_DATMSK4_Pos          (4)                                               /*!< GPIO_T::DATMSK: DATMSK4 Position       */
#define GPIO_DATMSK_DATMSK4_Msk          (0x1ul << GPIO_DATMSK_DATMSK4_Pos)                /*!< GPIO_T::DATMSK: DATMSK4 Mask           */

#define GPIO_DATMSK_DATMSK5_Pos          (5)                                               /*!< GPIO_T::DATMSK: DATMSK5 Position       */
#define GPIO_DATMSK_DATMSK5_Msk          (0x1ul << GPIO_DATMSK_DATMSK5_Pos)                /*!< GPIO_T::DATMSK: DATMSK5 Mask           */

#define GPIO_DATMSK_DATMSK6_Pos          (6)                                               /*!< GPIO_T::DATMSK: DATMSK6 Position       */
#define GPIO_DATMSK_DATMSK6_Msk          (0x1ul << GPIO_DATMSK_DATMSK6_Pos)                /*!< GPIO_T::DATMSK: DATMSK6 Mask           */

#define GPIO_DATMSK_DATMSK7_Pos          (7)                                               /*!< GPIO_T::DATMSK: DATMSK7 Position       */
#define GPIO_DATMSK_DATMSK7_Msk          (0x1ul << GPIO_DATMSK_DATMSK7_Pos)                /*!< GPIO_T::DATMSK: DATMSK7 Mask           */

#define GPIO_DATMSK_DATMSK8_Pos          (8)                                               /*!< GPIO_T::DATMSK: DATMSK8 Position       */
#define GPIO_DATMSK_DATMSK8_Msk          (0x1ul << GPIO_DATMSK_DATMSK8_Pos)                /*!< GPIO_T::DATMSK: DATMSK8 Mask           */

#define GPIO_DATMSK_DATMSK9_Pos          (9)                                               /*!< GPIO_T::DATMSK: DATMSK9 Position       */
#define GPIO_DATMSK_DATMSK9_Msk          (0x1ul << GPIO_DATMSK_DATMSK9_Pos)                /*!< GPIO_T::DATMSK: DATMSK9 Mask           */

#define GPIO_DATMSK_DATMSK10_Pos         (10)                                              /*!< GPIO_T::DATMSK: DATMSK10 Position      */
#define GPIO_DATMSK_DATMSK10_Msk         (0x1ul << GPIO_DATMSK_DATMSK10_Pos)               /*!< GPIO_T::DATMSK: DATMSK10 Mask          */

#define GPIO_DATMSK_DATMSK11_Pos         (11)                                              /*!< GPIO_T::DATMSK: DATMSK11 Position      */
#define GPIO_DATMSK_DATMSK11_Msk         (0x1ul << GPIO_DATMSK_DATMSK11_Pos)               /*!< GPIO_T::DATMSK: DATMSK11 Mask          */

#define GPIO_DATMSK_DATMSK12_Pos         (12)                                              /*!< GPIO_T::DATMSK: DATMSK12 Position      */
#define GPIO_DATMSK_DATMSK12_Msk         (0x1ul << GPIO_DATMSK_DATMSK12_Pos)               /*!< GPIO_T::DATMSK: DATMSK12 Mask          */

#define GPIO_DATMSK_DATMSK13_Pos         (13)                                              /*!< GPIO_T::DATMSK: DATMSK13 Position      */
#define GPIO_DATMSK_DATMSK13_Msk         (0x1ul << GPIO_DATMSK_DATMSK13_Pos)               /*!< GPIO_T::DATMSK: DATMSK13 Mask          */

#define GPIO_DATMSK_DATMSK14_Pos         (14)                                              /*!< GPIO_T::DATMSK: DATMSK14 Position      */
#define GPIO_DATMSK_DATMSK14_Msk         (0x1ul << GPIO_DATMSK_DATMSK14_Pos)               /*!< GPIO_T::DATMSK: DATMSK14 Mask          */

#define GPIO_DATMSK_DATMSK15_Pos         (15)                                              /*!< GPIO_T::DATMSK: DATMSK15 Position      */
#define GPIO_DATMSK_DATMSK15_Msk         (0x1ul << GPIO_DATMSK_DATMSK15_Pos)               /*!< GPIO_T::DATMSK: DATMSK15 Mask          */

#define GPIO_PIN_PIN0_Pos                (0)                                               /*!< GPIO_T::PIN: PIN0 Position             */
#define GPIO_PIN_PIN0_Msk                (0x1ul << GPIO_PIN_PIN0_Pos)                      /*!< GPIO_T::PIN: PIN0 Mask                 */

#define GPIO_PIN_PIN1_Pos                (1)                                               /*!< GPIO_T::PIN: PIN1 Position             */
#define GPIO_PIN_PIN1_Msk                (0x1ul << GPIO_PIN_PIN1_Pos)                      /*!< GPIO_T::PIN: PIN1 Mask                 */

#define GPIO_PIN_PIN2_Pos                (2)                                               /*!< GPIO_T::PIN: PIN2 Position             */
#define GPIO_PIN_PIN2_Msk                (0x1ul << GPIO_PIN_PIN2_Pos)                      /*!< GPIO_T::PIN: PIN2 Mask                 */

#define GPIO_PIN_PIN3_Pos                (3)                                               /*!< GPIO_T::PIN: PIN3 Position             */
#define GPIO_PIN_PIN3_Msk                (0x1ul << GPIO_PIN_PIN3_Pos)                      /*!< GPIO_T::PIN: PIN3 Mask                 */

#define GPIO_PIN_PIN4_Pos                (4)                                               /*!< GPIO_T::PIN: PIN4 Position             */
#define GPIO_PIN_PIN4_Msk                (0x1ul << GPIO_PIN_PIN4_Pos)                      /*!< GPIO_T::PIN: PIN4 Mask                 */

#define GPIO_PIN_PIN5_Pos                (5)                                               /*!< GPIO_T::PIN: PIN5 Position             */
#define GPIO_PIN_PIN5_Msk                (0x1ul << GPIO_PIN_PIN5_Pos)                      /*!< GPIO_T::PIN: PIN5 Mask                 */

#define GPIO_PIN_PIN6_Pos                (6)                                               /*!< GPIO_T::PIN: PIN6 Position             */
#define GPIO_PIN_PIN6_Msk                (0x1ul << GPIO_PIN_PIN6_Pos)                      /*!< GPIO_T::PIN: PIN6 Mask                 */

#define GPIO_PIN_PIN7_Pos                (7)                                               /*!< GPIO_T::PIN: PIN7 Position             */
#define GPIO_PIN_PIN7_Msk                (0x1ul << GPIO_PIN_PIN7_Pos)                      /*!< GPIO_T::PIN: PIN7 Mask                 */

#define GPIO_PIN_PIN8_Pos                (8)                                               /*!< GPIO_T::PIN: PIN8 Position             */
#define GPIO_PIN_PIN8_Msk                (0x1ul << GPIO_PIN_PIN8_Pos)                      /*!< GPIO_T::PIN: PIN8 Mask                 */

#define GPIO_PIN_PIN9_Pos                (9)                                               /*!< GPIO_T::PIN: PIN9 Position             */
#define GPIO_PIN_PIN9_Msk                (0x1ul << GPIO_PIN_PIN9_Pos)                      /*!< GPIO_T::PIN: PIN9 Mask                 */

#define GPIO_PIN_PIN10_Pos               (10)                                              /*!< GPIO_T::PIN: PIN10 Position            */
#define GPIO_PIN_PIN10_Msk               (0x1ul << GPIO_PIN_PIN10_Pos)                     /*!< GPIO_T::PIN: PIN10 Mask                */

#define GPIO_PIN_PIN11_Pos               (11)                                              /*!< GPIO_T::PIN: PIN11 Position            */
#define GPIO_PIN_PIN11_Msk               (0x1ul << GPIO_PIN_PIN11_Pos)                     /*!< GPIO_T::PIN: PIN11 Mask                */

#define GPIO_PIN_PIN12_Pos               (12)                                              /*!< GPIO_T::PIN: PIN12 Position            */
#define GPIO_PIN_PIN12_Msk               (0x1ul << GPIO_PIN_PIN12_Pos)                     /*!< GPIO_T::PIN: PIN12 Mask                */

#define GPIO_PIN_PIN13_Pos               (13)                                              /*!< GPIO_T::PIN: PIN13 Position            */
#define GPIO_PIN_PIN13_Msk               (0x1ul << GPIO_PIN_PIN13_Pos)                     /*!< GPIO_T::PIN: PIN13 Mask                */

#define GPIO_PIN_PIN14_Pos               (14)                                              /*!< GPIO_T::PIN: PIN14 Position            */
#define GPIO_PIN_PIN14_Msk               (0x1ul << GPIO_PIN_PIN14_Pos)                     /*!< GPIO_T::PIN: PIN14 Mask                */

#define GPIO_PIN_PIN15_Pos               (15)                                              /*!< GPIO_T::PIN: PIN15 Position            */
#define GPIO_PIN_PIN15_Msk               (0x1ul << GPIO_PIN_PIN15_Pos)                     /*!< GPIO_T::PIN: PIN15 Mask                */

#define GPIO_DBEN_DBEN0_Pos              (0)                                               /*!< GPIO_T::DBEN: DBEN0 Position           */
#define GPIO_DBEN_DBEN0_Msk              (0x1ul << GPIO_DBEN_DBEN0_Pos)                    /*!< GPIO_T::DBEN: DBEN0 Mask               */

#define GPIO_DBEN_DBEN1_Pos              (1)                                               /*!< GPIO_T::DBEN: DBEN1 Position           */
#define GPIO_DBEN_DBEN1_Msk              (0x1ul << GPIO_DBEN_DBEN1_Pos)                    /*!< GPIO_T::DBEN: DBEN1 Mask               */

#define GPIO_DBEN_DBEN2_Pos              (2)                                               /*!< GPIO_T::DBEN: DBEN2 Position           */
#define GPIO_DBEN_DBEN2_Msk              (0x1ul << GPIO_DBEN_DBEN2_Pos)                    /*!< GPIO_T::DBEN: DBEN2 Mask               */

#define GPIO_DBEN_DBEN3_Pos              (3)                                               /*!< GPIO_T::DBEN: DBEN3 Position           */
#define GPIO_DBEN_DBEN3_Msk              (0x1ul << GPIO_DBEN_DBEN3_Pos)                    /*!< GPIO_T::DBEN: DBEN3 Mask               */

#define GPIO_DBEN_DBEN4_Pos              (4)                                               /*!< GPIO_T::DBEN: DBEN4 Position           */
#define GPIO_DBEN_DBEN4_Msk              (0x1ul << GPIO_DBEN_DBEN4_Pos)                    /*!< GPIO_T::DBEN: DBEN4 Mask               */

#define GPIO_DBEN_DBEN5_Pos              (5)                                               /*!< GPIO_T::DBEN: DBEN5 Position           */
#define GPIO_DBEN_DBEN5_Msk              (0x1ul << GPIO_DBEN_DBEN5_Pos)                    /*!< GPIO_T::DBEN: DBEN5 Mask               */

#define GPIO_DBEN_DBEN6_Pos              (6)                                               /*!< GPIO_T::DBEN: DBEN6 Position           */
#define GPIO_DBEN_DBEN6_Msk              (0x1ul << GPIO_DBEN_DBEN6_Pos)                    /*!< GPIO_T::DBEN: DBEN6 Mask               */

#define GPIO_DBEN_DBEN7_Pos              (7)                                               /*!< GPIO_T::DBEN: DBEN7 Position           */
#define GPIO_DBEN_DBEN7_Msk              (0x1ul << GPIO_DBEN_DBEN7_Pos)                    /*!< GPIO_T::DBEN: DBEN7 Mask               */

#define GPIO_DBEN_DBEN8_Pos              (8)                                               /*!< GPIO_T::DBEN: DBEN8 Position           */
#define GPIO_DBEN_DBEN8_Msk              (0x1ul << GPIO_DBEN_DBEN8_Pos)                    /*!< GPIO_T::DBEN: DBEN8 Mask               */

#define GPIO_DBEN_DBEN9_Pos              (9)                                               /*!< GPIO_T::DBEN: DBEN9 Position           */
#define GPIO_DBEN_DBEN9_Msk              (0x1ul << GPIO_DBEN_DBEN9_Pos)                    /*!< GPIO_T::DBEN: DBEN9 Mask               */

#define GPIO_DBEN_DBEN10_Pos             (10)                                              /*!< GPIO_T::DBEN: DBEN10 Position          */
#define GPIO_DBEN_DBEN10_Msk             (0x1ul << GPIO_DBEN_DBEN10_Pos)                   /*!< GPIO_T::DBEN: DBEN10 Mask              */

#define GPIO_DBEN_DBEN11_Pos             (11)                                              /*!< GPIO_T::DBEN: DBEN11 Position          */
#define GPIO_DBEN_DBEN11_Msk             (0x1ul << GPIO_DBEN_DBEN11_Pos)                   /*!< GPIO_T::DBEN: DBEN11 Mask              */

#define GPIO_DBEN_DBEN12_Pos             (12)                                              /*!< GPIO_T::DBEN: DBEN12 Position          */
#define GPIO_DBEN_DBEN12_Msk             (0x1ul << GPIO_DBEN_DBEN12_Pos)                   /*!< GPIO_T::DBEN: DBEN12 Mask              */

#define GPIO_DBEN_DBEN13_Pos             (13)                                              /*!< GPIO_T::DBEN: DBEN13 Position          */
#define GPIO_DBEN_DBEN13_Msk             (0x1ul << GPIO_DBEN_DBEN13_Pos)                   /*!< GPIO_T::DBEN: DBEN13 Mask              */

#define GPIO_DBEN_DBEN14_Pos             (14)                                              /*!< GPIO_T::DBEN: DBEN14 Position          */
#define GPIO_DBEN_DBEN14_Msk             (0x1ul << GPIO_DBEN_DBEN14_Pos)                   /*!< GPIO_T::DBEN: DBEN14 Mask              */

#define GPIO_DBEN_DBEN15_Pos             (15)                                              /*!< GPIO_T::DBEN: DBEN15 Position          */
#define GPIO_DBEN_DBEN15_Msk             (0x1ul << GPIO_DBEN_DBEN15_Pos)                   /*!< GPIO_T::DBEN: DBEN15 Mask              */

#define GPIO_INTTYPE_TYPE0_Pos           (0)                                               /*!< GPIO_T::INTTYPE: TYPE0 Position        */
#define GPIO_INTTYPE_TYPE0_Msk           (0x1ul << GPIO_INTTYPE_TYPE0_Pos)                 /*!< GPIO_T::INTTYPE: TYPE0 Mask            */

#define GPIO_INTTYPE_TYPE1_Pos           (1)                                               /*!< GPIO_T::INTTYPE: TYPE1 Position        */
#define GPIO_INTTYPE_TYPE1_Msk           (0x1ul << GPIO_INTTYPE_TYPE1_Pos)                 /*!< GPIO_T::INTTYPE: TYPE1 Mask            */

#define GPIO_INTTYPE_TYPE2_Pos           (2)                                               /*!< GPIO_T::INTTYPE: TYPE2 Position        */
#define GPIO_INTTYPE_TYPE2_Msk           (0x1ul << GPIO_INTTYPE_TYPE2_Pos)                 /*!< GPIO_T::INTTYPE: TYPE2 Mask            */

#define GPIO_INTTYPE_TYPE3_Pos           (3)                                               /*!< GPIO_T::INTTYPE: TYPE3 Position        */
#define GPIO_INTTYPE_TYPE3_Msk           (0x1ul << GPIO_INTTYPE_TYPE3_Pos)                 /*!< GPIO_T::INTTYPE: TYPE3 Mask            */

#define GPIO_INTTYPE_TYPE4_Pos           (4)                                               /*!< GPIO_T::INTTYPE: TYPE4 Position        */
#define GPIO_INTTYPE_TYPE4_Msk           (0x1ul << GPIO_INTTYPE_TYPE4_Pos)                 /*!< GPIO_T::INTTYPE: TYPE4 Mask            */

#define GPIO_INTTYPE_TYPE5_Pos           (5)                                               /*!< GPIO_T::INTTYPE: TYPE5 Position        */
#define GPIO_INTTYPE_TYPE5_Msk           (0x1ul << GPIO_INTTYPE_TYPE5_Pos)                 /*!< GPIO_T::INTTYPE: TYPE5 Mask            */

#define GPIO_INTTYPE_TYPE6_Pos           (6)                                               /*!< GPIO_T::INTTYPE: TYPE6 Position        */
#define GPIO_INTTYPE_TYPE6_Msk           (0x1ul << GPIO_INTTYPE_TYPE6_Pos)                 /*!< GPIO_T::INTTYPE: TYPE6 Mask            */

#define GPIO_INTTYPE_TYPE7_Pos           (7)                                               /*!< GPIO_T::INTTYPE: TYPE7 Position        */
#define GPIO_INTTYPE_TYPE7_Msk           (0x1ul << GPIO_INTTYPE_TYPE7_Pos)                 /*!< GPIO_T::INTTYPE: TYPE7 Mask            */

#define GPIO_INTTYPE_TYPE8_Pos           (8)                                               /*!< GPIO_T::INTTYPE: TYPE8 Position        */
#define GPIO_INTTYPE_TYPE8_Msk           (0x1ul << GPIO_INTTYPE_TYPE8_Pos)                 /*!< GPIO_T::INTTYPE: TYPE8 Mask            */

#define GPIO_INTTYPE_TYPE9_Pos           (9)                                               /*!< GPIO_T::INTTYPE: TYPE9 Position        */
#define GPIO_INTTYPE_TYPE9_Msk           (0x1ul << GPIO_INTTYPE_TYPE9_Pos)                 /*!< GPIO_T::INTTYPE: TYPE9 Mask            */

#define GPIO_INTTYPE_TYPE10_Pos          (10)                                              /*!< GPIO_T::INTTYPE: TYPE10 Position       */
#define GPIO_INTTYPE_TYPE10_Msk          (0x1ul << GPIO_INTTYPE_TYPE10_Pos)                /*!< GPIO_T::INTTYPE: TYPE10 Mask           */

#define GPIO_INTTYPE_TYPE11_Pos          (11)                                              /*!< GPIO_T::INTTYPE: TYPE11 Position       */
#define GPIO_INTTYPE_TYPE11_Msk          (0x1ul << GPIO_INTTYPE_TYPE11_Pos)                /*!< GPIO_T::INTTYPE: TYPE11 Mask           */

#define GPIO_INTTYPE_TYPE12_Pos          (12)                                              /*!< GPIO_T::INTTYPE: TYPE12 Position       */
#define GPIO_INTTYPE_TYPE12_Msk          (0x1ul << GPIO_INTTYPE_TYPE12_Pos)                /*!< GPIO_T::INTTYPE: TYPE12 Mask           */

#define GPIO_INTTYPE_TYPE13_Pos          (13)                                              /*!< GPIO_T::INTTYPE: TYPE13 Position       */
#define GPIO_INTTYPE_TYPE13_Msk          (0x1ul << GPIO_INTTYPE_TYPE13_Pos)                /*!< GPIO_T::INTTYPE: TYPE13 Mask           */

#define GPIO_INTTYPE_TYPE14_Pos          (14)                                              /*!< GPIO_T::INTTYPE: TYPE14 Position       */
#define GPIO_INTTYPE_TYPE14_Msk          (0x1ul << GPIO_INTTYPE_TYPE14_Pos)                /*!< GPIO_T::INTTYPE: TYPE14 Mask           */

#define GPIO_INTTYPE_TYPE15_Pos          (15)                                              /*!< GPIO_T::INTTYPE: TYPE15 Position       */
#define GPIO_INTTYPE_TYPE15_Msk          (0x1ul << GPIO_INTTYPE_TYPE15_Pos)                /*!< GPIO_T::INTTYPE: TYPE15 Mask           */

#define GPIO_INTEN_FLIEN0_Pos            (0)                                               /*!< GPIO_T::INTEN: FLIEN0 Position         */
#define GPIO_INTEN_FLIEN0_Msk            (0x1ul << GPIO_INTEN_FLIEN0_Pos)                  /*!< GPIO_T::INTEN: FLIEN0 Mask             */

#define GPIO_INTEN_FLIEN1_Pos            (1)                                               /*!< GPIO_T::INTEN: FLIEN1 Position         */
#define GPIO_INTEN_FLIEN1_Msk            (0x1ul << GPIO_INTEN_FLIEN1_Pos)                  /*!< GPIO_T::INTEN: FLIEN1 Mask             */

#define GPIO_INTEN_FLIEN2_Pos            (2)                                               /*!< GPIO_T::INTEN: FLIEN2 Position         */
#define GPIO_INTEN_FLIEN2_Msk            (0x1ul << GPIO_INTEN_FLIEN2_Pos)                  /*!< GPIO_T::INTEN: FLIEN2 Mask             */

#define GPIO_INTEN_FLIEN3_Pos            (3)                                               /*!< GPIO_T::INTEN: FLIEN3 Position         */
#define GPIO_INTEN_FLIEN3_Msk            (0x1ul << GPIO_INTEN_FLIEN3_Pos)                  /*!< GPIO_T::INTEN: FLIEN3 Mask             */

#define GPIO_INTEN_FLIEN4_Pos            (4)                                               /*!< GPIO_T::INTEN: FLIEN4 Position         */
#define GPIO_INTEN_FLIEN4_Msk            (0x1ul << GPIO_INTEN_FLIEN4_Pos)                  /*!< GPIO_T::INTEN: FLIEN4 Mask             */

#define GPIO_INTEN_FLIEN5_Pos            (5)                                               /*!< GPIO_T::INTEN: FLIEN5 Position         */
#define GPIO_INTEN_FLIEN5_Msk            (0x1ul << GPIO_INTEN_FLIEN5_Pos)                  /*!< GPIO_T::INTEN: FLIEN5 Mask             */

#define GPIO_INTEN_FLIEN6_Pos            (6)                                               /*!< GPIO_T::INTEN: FLIEN6 Position         */
#define GPIO_INTEN_FLIEN6_Msk            (0x1ul << GPIO_INTEN_FLIEN6_Pos)                  /*!< GPIO_T::INTEN: FLIEN6 Mask             */

#define GPIO_INTEN_FLIEN7_Pos            (7)                                               /*!< GPIO_T::INTEN: FLIEN7 Position         */
#define GPIO_INTEN_FLIEN7_Msk            (0x1ul << GPIO_INTEN_FLIEN7_Pos)                  /*!< GPIO_T::INTEN: FLIEN7 Mask             */

#define GPIO_INTEN_FLIEN8_Pos            (8)                                               /*!< GPIO_T::INTEN: FLIEN8 Position         */
#define GPIO_INTEN_FLIEN8_Msk            (0x1ul << GPIO_INTEN_FLIEN8_Pos)                  /*!< GPIO_T::INTEN: FLIEN8 Mask             */

#define GPIO_INTEN_FLIEN9_Pos            (9)                                               /*!< GPIO_T::INTEN: FLIEN9 Position         */
#define GPIO_INTEN_FLIEN9_Msk            (0x1ul << GPIO_INTEN_FLIEN9_Pos)                  /*!< GPIO_T::INTEN: FLIEN9 Mask             */

#define GPIO_INTEN_FLIEN10_Pos           (10)                                              /*!< GPIO_T::INTEN: FLIEN10 Position        */
#define GPIO_INTEN_FLIEN10_Msk           (0x1ul << GPIO_INTEN_FLIEN10_Pos)                 /*!< GPIO_T::INTEN: FLIEN10 Mask            */

#define GPIO_INTEN_FLIEN11_Pos           (11)                                              /*!< GPIO_T::INTEN: FLIEN11 Position        */
#define GPIO_INTEN_FLIEN11_Msk           (0x1ul << GPIO_INTEN_FLIEN11_Pos)                 /*!< GPIO_T::INTEN: FLIEN11 Mask            */

#define GPIO_INTEN_FLIEN12_Pos           (12)                                              /*!< GPIO_T::INTEN: FLIEN12 Position        */
#define GPIO_INTEN_FLIEN12_Msk           (0x1ul << GPIO_INTEN_FLIEN12_Pos)                 /*!< GPIO_T::INTEN: FLIEN12 Mask            */

#define GPIO_INTEN_FLIEN13_Pos           (13)                                              /*!< GPIO_T::INTEN: FLIEN13 Position        */
#define GPIO_INTEN_FLIEN13_Msk           (0x1ul << GPIO_INTEN_FLIEN13_Pos)                 /*!< GPIO_T::INTEN: FLIEN13 Mask            */

#define GPIO_INTEN_FLIEN14_Pos           (14)                                              /*!< GPIO_T::INTEN: FLIEN14 Position        */
#define GPIO_INTEN_FLIEN14_Msk           (0x1ul << GPIO_INTEN_FLIEN14_Pos)                 /*!< GPIO_T::INTEN: FLIEN14 Mask            */

#define GPIO_INTEN_FLIEN15_Pos           (15)                                              /*!< GPIO_T::INTEN: FLIEN15 Position        */
#define GPIO_INTEN_FLIEN15_Msk           (0x1ul << GPIO_INTEN_FLIEN15_Pos)                 /*!< GPIO_T::INTEN: FLIEN15 Mask            */

#define GPIO_INTEN_RHIEN0_Pos            (16)                                              /*!< GPIO_T::INTEN: RHIEN0 Position         */
#define GPIO_INTEN_RHIEN0_Msk            (0x1ul << GPIO_INTEN_RHIEN0_Pos)                  /*!< GPIO_T::INTEN: RHIEN0 Mask             */

#define GPIO_INTEN_RHIEN1_Pos            (17)                                              /*!< GPIO_T::INTEN: RHIEN1 Position         */
#define GPIO_INTEN_RHIEN1_Msk            (0x1ul << GPIO_INTEN_RHIEN1_Pos)                  /*!< GPIO_T::INTEN: RHIEN1 Mask             */

#define GPIO_INTEN_RHIEN2_Pos            (18)                                              /*!< GPIO_T::INTEN: RHIEN2 Position         */
#define GPIO_INTEN_RHIEN2_Msk            (0x1ul << GPIO_INTEN_RHIEN2_Pos)                  /*!< GPIO_T::INTEN: RHIEN2 Mask             */

#define GPIO_INTEN_RHIEN3_Pos            (19)                                              /*!< GPIO_T::INTEN: RHIEN3 Position         */
#define GPIO_INTEN_RHIEN3_Msk            (0x1ul << GPIO_INTEN_RHIEN3_Pos)                  /*!< GPIO_T::INTEN: RHIEN3 Mask             */

#define GPIO_INTEN_RHIEN4_Pos            (20)                                              /*!< GPIO_T::INTEN: RHIEN4 Position         */
#define GPIO_INTEN_RHIEN4_Msk            (0x1ul << GPIO_INTEN_RHIEN4_Pos)                  /*!< GPIO_T::INTEN: RHIEN4 Mask             */

#define GPIO_INTEN_RHIEN5_Pos            (21)                                              /*!< GPIO_T::INTEN: RHIEN5 Position         */
#define GPIO_INTEN_RHIEN5_Msk            (0x1ul << GPIO_INTEN_RHIEN5_Pos)                  /*!< GPIO_T::INTEN: RHIEN5 Mask             */

#define GPIO_INTEN_RHIEN6_Pos            (22)                                              /*!< GPIO_T::INTEN: RHIEN6 Position         */
#define GPIO_INTEN_RHIEN6_Msk            (0x1ul << GPIO_INTEN_RHIEN6_Pos)                  /*!< GPIO_T::INTEN: RHIEN6 Mask             */

#define GPIO_INTEN_RHIEN7_Pos            (23)                                              /*!< GPIO_T::INTEN: RHIEN7 Position         */
#define GPIO_INTEN_RHIEN7_Msk            (0x1ul << GPIO_INTEN_RHIEN7_Pos)                  /*!< GPIO_T::INTEN: RHIEN7 Mask             */

#define GPIO_INTEN_RHIEN8_Pos            (24)                                              /*!< GPIO_T::INTEN: RHIEN8 Position         */
#define GPIO_INTEN_RHIEN8_Msk            (0x1ul << GPIO_INTEN_RHIEN8_Pos)                  /*!< GPIO_T::INTEN: RHIEN8 Mask             */

#define GPIO_INTEN_RHIEN9_Pos            (25)                                              /*!< GPIO_T::INTEN: RHIEN9 Position         */
#define GPIO_INTEN_RHIEN9_Msk            (0x1ul << GPIO_INTEN_RHIEN9_Pos)                  /*!< GPIO_T::INTEN: RHIEN9 Mask             */

#define GPIO_INTEN_RHIEN10_Pos           (26)                                              /*!< GPIO_T::INTEN: RHIEN10 Position        */
#define GPIO_INTEN_RHIEN10_Msk           (0x1ul << GPIO_INTEN_RHIEN10_Pos)                 /*!< GPIO_T::INTEN: RHIEN10 Mask            */

#define GPIO_INTEN_RHIEN11_Pos           (27)                                              /*!< GPIO_T::INTEN: RHIEN11 Position        */
#define GPIO_INTEN_RHIEN11_Msk           (0x1ul << GPIO_INTEN_RHIEN11_Pos)                 /*!< GPIO_T::INTEN: RHIEN11 Mask            */

#define GPIO_INTEN_RHIEN12_Pos           (28)                                              /*!< GPIO_T::INTEN: RHIEN12 Position        */
#define GPIO_INTEN_RHIEN12_Msk           (0x1ul << GPIO_INTEN_RHIEN12_Pos)                 /*!< GPIO_T::INTEN: RHIEN12 Mask            */

#define GPIO_INTEN_RHIEN13_Pos           (29)                                              /*!< GPIO_T::INTEN: RHIEN13 Position        */
#define GPIO_INTEN_RHIEN13_Msk           (0x1ul << GPIO_INTEN_RHIEN13_Pos)                 /*!< GPIO_T::INTEN: RHIEN13 Mask            */

#define GPIO_INTEN_RHIEN14_Pos           (30)                                              /*!< GPIO_T::INTEN: RHIEN14 Position        */
#define GPIO_INTEN_RHIEN14_Msk           (0x1ul << GPIO_INTEN_RHIEN14_Pos)                 /*!< GPIO_T::INTEN: RHIEN14 Mask            */

#define GPIO_INTEN_RHIEN15_Pos           (31)                                              /*!< GPIO_T::INTEN: RHIEN15 Position        */
#define GPIO_INTEN_RHIEN15_Msk           (0x1ul << GPIO_INTEN_RHIEN15_Pos)                 /*!< GPIO_T::INTEN: RHIEN15 Mask            */

#define GPIO_INTSRC_INTSRC0_Pos          (0)                                               /*!< GPIO_T::INTSRC: INTSRC0 Position       */
#define GPIO_INTSRC_INTSRC0_Msk          (0x1ul << GPIO_INTSRC_INTSRC0_Pos)                /*!< GPIO_T::INTSRC: INTSRC0 Mask           */

#define GPIO_INTSRC_INTSRC1_Pos          (1)                                               /*!< GPIO_T::INTSRC: INTSRC1 Position       */
#define GPIO_INTSRC_INTSRC1_Msk          (0x1ul << GPIO_INTSRC_INTSRC1_Pos)                /*!< GPIO_T::INTSRC: INTSRC1 Mask           */

#define GPIO_INTSRC_INTSRC2_Pos          (2)                                               /*!< GPIO_T::INTSRC: INTSRC2 Position       */
#define GPIO_INTSRC_INTSRC2_Msk          (0x1ul << GPIO_INTSRC_INTSRC2_Pos)                /*!< GPIO_T::INTSRC: INTSRC2 Mask           */

#define GPIO_INTSRC_INTSRC3_Pos          (3)                                               /*!< GPIO_T::INTSRC: INTSRC3 Position       */
#define GPIO_INTSRC_INTSRC3_Msk          (0x1ul << GPIO_INTSRC_INTSRC3_Pos)                /*!< GPIO_T::INTSRC: INTSRC3 Mask           */

#define GPIO_INTSRC_INTSRC4_Pos          (4)                                               /*!< GPIO_T::INTSRC: INTSRC4 Position       */
#define GPIO_INTSRC_INTSRC4_Msk          (0x1ul << GPIO_INTSRC_INTSRC4_Pos)                /*!< GPIO_T::INTSRC: INTSRC4 Mask           */

#define GPIO_INTSRC_INTSRC5_Pos          (5)                                               /*!< GPIO_T::INTSRC: INTSRC5 Position       */
#define GPIO_INTSRC_INTSRC5_Msk          (0x1ul << GPIO_INTSRC_INTSRC5_Pos)                /*!< GPIO_T::INTSRC: INTSRC5 Mask           */

#define GPIO_INTSRC_INTSRC6_Pos          (6)                                               /*!< GPIO_T::INTSRC: INTSRC6 Position       */
#define GPIO_INTSRC_INTSRC6_Msk          (0x1ul << GPIO_INTSRC_INTSRC6_Pos)                /*!< GPIO_T::INTSRC: INTSRC6 Mask           */

#define GPIO_INTSRC_INTSRC7_Pos          (7)                                               /*!< GPIO_T::INTSRC: INTSRC7 Position       */
#define GPIO_INTSRC_INTSRC7_Msk          (0x1ul << GPIO_INTSRC_INTSRC7_Pos)                /*!< GPIO_T::INTSRC: INTSRC7 Mask           */

#define GPIO_INTSRC_INTSRC8_Pos          (8)                                               /*!< GPIO_T::INTSRC: INTSRC8 Position       */
#define GPIO_INTSRC_INTSRC8_Msk          (0x1ul << GPIO_INTSRC_INTSRC8_Pos)                /*!< GPIO_T::INTSRC: INTSRC8 Mask           */

#define GPIO_INTSRC_INTSRC9_Pos          (9)                                               /*!< GPIO_T::INTSRC: INTSRC9 Position       */
#define GPIO_INTSRC_INTSRC9_Msk          (0x1ul << GPIO_INTSRC_INTSRC9_Pos)                /*!< GPIO_T::INTSRC: INTSRC9 Mask           */

#define GPIO_INTSRC_INTSRC10_Pos         (10)                                              /*!< GPIO_T::INTSRC: INTSRC10 Position      */
#define GPIO_INTSRC_INTSRC10_Msk         (0x1ul << GPIO_INTSRC_INTSRC10_Pos)               /*!< GPIO_T::INTSRC: INTSRC10 Mask          */

#define GPIO_INTSRC_INTSRC11_Pos         (11)                                              /*!< GPIO_T::INTSRC: INTSRC11 Position      */
#define GPIO_INTSRC_INTSRC11_Msk         (0x1ul << GPIO_INTSRC_INTSRC11_Pos)               /*!< GPIO_T::INTSRC: INTSRC11 Mask          */

#define GPIO_INTSRC_INTSRC12_Pos         (12)                                              /*!< GPIO_T::INTSRC: INTSRC12 Position      */
#define GPIO_INTSRC_INTSRC12_Msk         (0x1ul << GPIO_INTSRC_INTSRC12_Pos)               /*!< GPIO_T::INTSRC: INTSRC12 Mask          */

#define GPIO_INTSRC_INTSRC13_Pos         (13)                                              /*!< GPIO_T::INTSRC: INTSRC13 Position      */
#define GPIO_INTSRC_INTSRC13_Msk         (0x1ul << GPIO_INTSRC_INTSRC13_Pos)               /*!< GPIO_T::INTSRC: INTSRC13 Mask          */

#define GPIO_INTSRC_INTSRC14_Pos         (14)                                              /*!< GPIO_T::INTSRC: INTSRC14 Position      */
#define GPIO_INTSRC_INTSRC14_Msk         (0x1ul << GPIO_INTSRC_INTSRC14_Pos)               /*!< GPIO_T::INTSRC: INTSRC14 Mask          */

#define GPIO_INTSRC_INTSRC15_Pos         (15)                                              /*!< GPIO_T::INTSRC: INTSRC15 Position      */
#define GPIO_INTSRC_INTSRC15_Msk         (0x1ul << GPIO_INTSRC_INTSRC15_Pos)               /*!< GPIO_T::INTSRC: INTSRC15 Mask          */

#define GPIO_SMTEN_SMTEN0_Pos            (0)                                               /*!< GPIO_T::SMTEN: SMTEN0 Position         */
#define GPIO_SMTEN_SMTEN0_Msk            (0x1ul << GPIO_SMTEN_SMTEN0_Pos)                  /*!< GPIO_T::SMTEN: SMTEN0 Mask             */

#define GPIO_SMTEN_SMTEN1_Pos            (1)                                               /*!< GPIO_T::SMTEN: SMTEN1 Position         */
#define GPIO_SMTEN_SMTEN1_Msk            (0x1ul << GPIO_SMTEN_SMTEN1_Pos)                  /*!< GPIO_T::SMTEN: SMTEN1 Mask             */

#define GPIO_SMTEN_SMTEN2_Pos            (2)                                               /*!< GPIO_T::SMTEN: SMTEN2 Position         */
#define GPIO_SMTEN_SMTEN2_Msk            (0x1ul << GPIO_SMTEN_SMTEN2_Pos)                  /*!< GPIO_T::SMTEN: SMTEN2 Mask             */

#define GPIO_SMTEN_SMTEN3_Pos            (3)                                               /*!< GPIO_T::SMTEN: SMTEN3 Position         */
#define GPIO_SMTEN_SMTEN3_Msk            (0x1ul << GPIO_SMTEN_SMTEN3_Pos)                  /*!< GPIO_T::SMTEN: SMTEN3 Mask             */

#define GPIO_SMTEN_SMTEN4_Pos            (4)                                               /*!< GPIO_T::SMTEN: SMTEN4 Position         */
#define GPIO_SMTEN_SMTEN4_Msk            (0x1ul << GPIO_SMTEN_SMTEN4_Pos)                  /*!< GPIO_T::SMTEN: SMTEN4 Mask             */

#define GPIO_SMTEN_SMTEN5_Pos            (5)                                               /*!< GPIO_T::SMTEN: SMTEN5 Position         */
#define GPIO_SMTEN_SMTEN5_Msk            (0x1ul << GPIO_SMTEN_SMTEN5_Pos)                  /*!< GPIO_T::SMTEN: SMTEN5 Mask             */

#define GPIO_SMTEN_SMTEN6_Pos            (6)                                               /*!< GPIO_T::SMTEN: SMTEN6 Position         */
#define GPIO_SMTEN_SMTEN6_Msk            (0x1ul << GPIO_SMTEN_SMTEN6_Pos)                  /*!< GPIO_T::SMTEN: SMTEN6 Mask             */

#define GPIO_SMTEN_SMTEN7_Pos            (7)                                               /*!< GPIO_T::SMTEN: SMTEN7 Position         */
#define GPIO_SMTEN_SMTEN7_Msk            (0x1ul << GPIO_SMTEN_SMTEN7_Pos)                  /*!< GPIO_T::SMTEN: SMTEN7 Mask             */

#define GPIO_SMTEN_SMTEN8_Pos            (8)                                               /*!< GPIO_T::SMTEN: SMTEN8 Position         */
#define GPIO_SMTEN_SMTEN8_Msk            (0x1ul << GPIO_SMTEN_SMTEN8_Pos)                  /*!< GPIO_T::SMTEN: SMTEN8 Mask             */

#define GPIO_SMTEN_SMTEN9_Pos            (9)                                               /*!< GPIO_T::SMTEN: SMTEN9 Position         */
#define GPIO_SMTEN_SMTEN9_Msk            (0x1ul << GPIO_SMTEN_SMTEN9_Pos)                  /*!< GPIO_T::SMTEN: SMTEN9 Mask             */

#define GPIO_SMTEN_SMTEN10_Pos           (10)                                              /*!< GPIO_T::SMTEN: SMTEN10 Position        */
#define GPIO_SMTEN_SMTEN10_Msk           (0x1ul << GPIO_SMTEN_SMTEN10_Pos)                 /*!< GPIO_T::SMTEN: SMTEN10 Mask            */

#define GPIO_SMTEN_SMTEN11_Pos           (11)                                              /*!< GPIO_T::SMTEN: SMTEN11 Position        */
#define GPIO_SMTEN_SMTEN11_Msk           (0x1ul << GPIO_SMTEN_SMTEN11_Pos)                 /*!< GPIO_T::SMTEN: SMTEN11 Mask            */

#define GPIO_SMTEN_SMTEN12_Pos           (12)                                              /*!< GPIO_T::SMTEN: SMTEN12 Position        */
#define GPIO_SMTEN_SMTEN12_Msk           (0x1ul << GPIO_SMTEN_SMTEN12_Pos)                 /*!< GPIO_T::SMTEN: SMTEN12 Mask            */

#define GPIO_SMTEN_SMTEN13_Pos           (13)                                              /*!< GPIO_T::SMTEN: SMTEN13 Position        */
#define GPIO_SMTEN_SMTEN13_Msk           (0x1ul << GPIO_SMTEN_SMTEN13_Pos)                 /*!< GPIO_T::SMTEN: SMTEN13 Mask            */

#define GPIO_SMTEN_SMTEN14_Pos           (14)                                              /*!< GPIO_T::SMTEN: SMTEN14 Position        */
#define GPIO_SMTEN_SMTEN14_Msk           (0x1ul << GPIO_SMTEN_SMTEN14_Pos)                 /*!< GPIO_T::SMTEN: SMTEN14 Mask            */

#define GPIO_SMTEN_SMTEN15_Pos           (15)                                              /*!< GPIO_T::SMTEN: SMTEN15 Position        */
#define GPIO_SMTEN_SMTEN15_Msk           (0x1ul << GPIO_SMTEN_SMTEN15_Pos)                 /*!< GPIO_T::SMTEN: SMTEN15 Mask            */

#define GPIO_SLEWCTL_HSREN0_Pos          (0)                                               /*!< GPIO_T::SLEWCTL: HSREN0 Position       */
#define GPIO_SLEWCTL_HSREN0_Msk          (0x3ul << GPIO_SLEWCTL_HSREN0_Pos)                /*!< GPIO_T::SLEWCTL: HSREN0 Mask           */

#define GPIO_SLEWCTL_HSREN1_Pos          (2)                                               /*!< GPIO_T::SLEWCTL: HSREN1 Position       */
#define GPIO_SLEWCTL_HSREN1_Msk          (0x3ul << GPIO_SLEWCTL_HSREN1_Pos)                /*!< GPIO_T::SLEWCTL: HSREN1 Mask           */

#define GPIO_SLEWCTL_HSREN2_Pos          (4)                                               /*!< GPIO_T::SLEWCTL: HSREN2 Position       */
#define GPIO_SLEWCTL_HSREN2_Msk          (0x3ul << GPIO_SLEWCTL_HSREN2_Pos)                /*!< GPIO_T::SLEWCTL: HSREN2 Mask           */

#define GPIO_SLEWCTL_HSREN3_Pos          (6)                                               /*!< GPIO_T::SLEWCTL: HSREN3 Position       */
#define GPIO_SLEWCTL_HSREN3_Msk          (0x3ul << GPIO_SLEWCTL_HSREN3_Pos)                /*!< GPIO_T::SLEWCTL: HSREN3 Mask           */

#define GPIO_SLEWCTL_HSREN4_Pos          (8)                                               /*!< GPIO_T::SLEWCTL: HSREN4 Position       */
#define GPIO_SLEWCTL_HSREN4_Msk          (0x3ul << GPIO_SLEWCTL_HSREN4_Pos)                /*!< GPIO_T::SLEWCTL: HSREN4 Mask           */

#define GPIO_SLEWCTL_HSREN5_Pos          (10)                                              /*!< GPIO_T::SLEWCTL: HSREN5 Position       */
#define GPIO_SLEWCTL_HSREN5_Msk          (0x3ul << GPIO_SLEWCTL_HSREN5_Pos)                /*!< GPIO_T::SLEWCTL: HSREN5 Mask           */

#define GPIO_SLEWCTL_HSREN6_Pos          (12)                                              /*!< GPIO_T::SLEWCTL: HSREN6 Position       */
#define GPIO_SLEWCTL_HSREN6_Msk          (0x3ul << GPIO_SLEWCTL_HSREN6_Pos)                /*!< GPIO_T::SLEWCTL: HSREN6 Mask           */

#define GPIO_SLEWCTL_HSREN7_Pos          (14)                                              /*!< GPIO_T::SLEWCTL: HSREN7 Position       */
#define GPIO_SLEWCTL_HSREN7_Msk          (0x3ul << GPIO_SLEWCTL_HSREN7_Pos)                /*!< GPIO_T::SLEWCTL: HSREN7 Mask           */

#define GPIO_SLEWCTL_HSREN8_Pos          (16)                                              /*!< GPIO_T::SLEWCTL: HSREN8 Position       */
#define GPIO_SLEWCTL_HSREN8_Msk          (0x3ul << GPIO_SLEWCTL_HSREN8_Pos)                /*!< GPIO_T::SLEWCTL: HSREN8 Mask           */

#define GPIO_SLEWCTL_HSREN9_Pos          (18)                                              /*!< GPIO_T::SLEWCTL: HSREN9 Position       */
#define GPIO_SLEWCTL_HSREN9_Msk          (0x3ul << GPIO_SLEWCTL_HSREN9_Pos)                /*!< GPIO_T::SLEWCTL: HSREN9 Mask           */

#define GPIO_SLEWCTL_HSREN10_Pos         (20)                                              /*!< GPIO_T::SLEWCTL: HSREN10 Position      */
#define GPIO_SLEWCTL_HSREN10_Msk         (0x3ul << GPIO_SLEWCTL_HSREN10_Pos)               /*!< GPIO_T::SLEWCTL: HSREN10 Mask          */

#define GPIO_SLEWCTL_HSREN11_Pos         (22)                                              /*!< GPIO_T::SLEWCTL: HSREN11 Position      */
#define GPIO_SLEWCTL_HSREN11_Msk         (0x3ul << GPIO_SLEWCTL_HSREN11_Pos)               /*!< GPIO_T::SLEWCTL: HSREN11 Mask          */

#define GPIO_SLEWCTL_HSREN12_Pos         (24)                                              /*!< GPIO_T::SLEWCTL: HSREN12 Position      */
#define GPIO_SLEWCTL_HSREN12_Msk         (0x3ul << GPIO_SLEWCTL_HSREN12_Pos)               /*!< GPIO_T::SLEWCTL: HSREN12 Mask          */

#define GPIO_SLEWCTL_HSREN13_Pos         (26)                                              /*!< GPIO_T::SLEWCTL: HSREN13 Position      */
#define GPIO_SLEWCTL_HSREN13_Msk         (0x3ul << GPIO_SLEWCTL_HSREN13_Pos)               /*!< GPIO_T::SLEWCTL: HSREN13 Mask          */

#define GPIO_SLEWCTL_HSREN14_Pos         (28)                                              /*!< GPIO_T::SLEWCTL: HSREN14 Position      */
#define GPIO_SLEWCTL_HSREN14_Msk         (0x3ul << GPIO_SLEWCTL_HSREN14_Pos)               /*!< GPIO_T::SLEWCTL: HSREN14 Mask          */

#define GPIO_SLEWCTL_HSREN15_Pos         (30)                                              /*!< GPIO_T::SLEWCTL: HSREN15 Position      */
#define GPIO_SLEWCTL_HSREN15_Msk         (0x3ul << GPIO_SLEWCTL_HSREN15_Pos)               /*!< GPIO_T::SLEWCTL: HSREN15 Mask          */

#define GPIO_PUSEL_PUSEL0_Pos            (0)                                               /*!< GPIO_T::PUSEL: PUSEL0 Position         */
#define GPIO_PUSEL_PUSEL0_Msk            (0x3ul << GPIO_PUSEL_PUSEL0_Pos)                  /*!< GPIO_T::PUSEL: PUSEL0 Mask             */

#define GPIO_PUSEL_PUSEL1_Pos            (2)                                               /*!< GPIO_T::PUSEL: PUSEL1 Position         */
#define GPIO_PUSEL_PUSEL1_Msk            (0x3ul << GPIO_PUSEL_PUSEL1_Pos)                  /*!< GPIO_T::PUSEL: PUSEL1 Mask             */

#define GPIO_PUSEL_PUSEL2_Pos            (4)                                               /*!< GPIO_T::PUSEL: PUSEL2 Position         */
#define GPIO_PUSEL_PUSEL2_Msk            (0x3ul << GPIO_PUSEL_PUSEL2_Pos)                  /*!< GPIO_T::PUSEL: PUSEL2 Mask             */

#define GPIO_PUSEL_PUSEL3_Pos            (6)                                               /*!< GPIO_T::PUSEL: PUSEL3 Position         */
#define GPIO_PUSEL_PUSEL3_Msk            (0x3ul << GPIO_PUSEL_PUSEL3_Pos)                  /*!< GPIO_T::PUSEL: PUSEL3 Mask             */

#define GPIO_PUSEL_PUSEL4_Pos            (8)                                               /*!< GPIO_T::PUSEL: PUSEL4 Position         */
#define GPIO_PUSEL_PUSEL4_Msk            (0x3ul << GPIO_PUSEL_PUSEL4_Pos)                  /*!< GPIO_T::PUSEL: PUSEL4 Mask             */

#define GPIO_PUSEL_PUSEL5_Pos            (10)                                              /*!< GPIO_T::PUSEL: PUSEL5 Position         */
#define GPIO_PUSEL_PUSEL5_Msk            (0x3ul << GPIO_PUSEL_PUSEL5_Pos)                  /*!< GPIO_T::PUSEL: PUSEL5 Mask             */

#define GPIO_PUSEL_PUSEL6_Pos            (12)                                              /*!< GPIO_T::PUSEL: PUSEL6 Position         */
#define GPIO_PUSEL_PUSEL6_Msk            (0x3ul << GPIO_PUSEL_PUSEL6_Pos)                  /*!< GPIO_T::PUSEL: PUSEL6 Mask             */

#define GPIO_PUSEL_PUSEL7_Pos            (14)                                              /*!< GPIO_T::PUSEL: PUSEL7 Position         */
#define GPIO_PUSEL_PUSEL7_Msk            (0x3ul << GPIO_PUSEL_PUSEL7_Pos)                  /*!< GPIO_T::PUSEL: PUSEL7 Mask             */

#define GPIO_PUSEL_PUSEL8_Pos            (16)                                              /*!< GPIO_T::PUSEL: PUSEL8 Position         */
#define GPIO_PUSEL_PUSEL8_Msk            (0x3ul << GPIO_PUSEL_PUSEL8_Pos)                  /*!< GPIO_T::PUSEL: PUSEL8 Mask             */

#define GPIO_PUSEL_PUSEL9_Pos            (18)                                              /*!< GPIO_T::PUSEL: PUSEL9 Position         */
#define GPIO_PUSEL_PUSEL9_Msk            (0x3ul << GPIO_PUSEL_PUSEL9_Pos)                  /*!< GPIO_T::PUSEL: PUSEL9 Mask             */

#define GPIO_PUSEL_PUSEL10_Pos           (20)                                              /*!< GPIO_T::PUSEL: PUSEL10 Position        */
#define GPIO_PUSEL_PUSEL10_Msk           (0x3ul << GPIO_PUSEL_PUSEL10_Pos)                 /*!< GPIO_T::PUSEL: PUSEL10 Mask            */

#define GPIO_PUSEL_PUSEL11_Pos           (22)                                              /*!< GPIO_T::PUSEL: PUSEL11 Position        */
#define GPIO_PUSEL_PUSEL11_Msk           (0x3ul << GPIO_PUSEL_PUSEL11_Pos)                 /*!< GPIO_T::PUSEL: PUSEL11 Mask            */

#define GPIO_PUSEL_PUSEL12_Pos           (24)                                              /*!< GPIO_T::PUSEL: PUSEL12 Position        */
#define GPIO_PUSEL_PUSEL12_Msk           (0x3ul << GPIO_PUSEL_PUSEL12_Pos)                 /*!< GPIO_T::PUSEL: PUSEL12 Mask            */

#define GPIO_PUSEL_PUSEL13_Pos           (26)                                              /*!< GPIO_T::PUSEL: PUSEL13 Position        */
#define GPIO_PUSEL_PUSEL13_Msk           (0x3ul << GPIO_PUSEL_PUSEL13_Pos)                 /*!< GPIO_T::PUSEL: PUSEL13 Mask            */

#define GPIO_PUSEL_PUSEL14_Pos           (28)                                              /*!< GPIO_T::PUSEL: PUSEL14 Position        */
#define GPIO_PUSEL_PUSEL14_Msk           (0x3ul << GPIO_PUSEL_PUSEL14_Pos)                 /*!< GPIO_T::PUSEL: PUSEL14 Mask            */

#define GPIO_PUSEL_PUSEL15_Pos           (30)                                              /*!< GPIO_T::PUSEL: PUSEL15 Position        */
#define GPIO_PUSEL_PUSEL15_Msk           (0x3ul << GPIO_PUSEL_PUSEL15_Pos)                 /*!< GPIO_T::PUSEL: PUSEL15 Mask            */

#define GPIO_DBCTL_DBCLKSEL_Pos          (0)                                               /*!< GPIO_T::DBCTL: DBCLKSEL Position          */
#define GPIO_DBCTL_DBCLKSEL_Msk          (0xFul << GPIO_DBCTL_DBCLKSEL_Pos)                /*!< GPIO_T::DBCTL: DBCLKSEL Mask              */

#define GPIO_DBCTL_DBCLKSRC_Pos          (4)                                               /*!< GPIO_T::DBCTL: DBCLKSRC Position          */
#define GPIO_DBCTL_DBCLKSRC_Msk          (1ul << GPIO_DBCTL_DBCLKSRC_Pos)                  /*!< GPIO_T::DBCTL: DBCLKSRC Mask              */

#define GPIO_DBCTL_ICLKON_Pos            (5)                                               /*!< GPIO_T::DBCTL: ICLKON Position            */
#define GPIO_DBCTL_ICLKON_Msk            (1ul << GPIO_DBCTL_ICLKON_Pos)                    /*!< GPIO_T::DBCTL: ICLKON Mask                */

/**@}*/ /* GPIO_CONST */
/**@}*/ /* end of GPIO register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __GPIO_REG_H__ */
