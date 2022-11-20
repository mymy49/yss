/**
  ******************************************************************************
  * @file    stm32f103x6.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral register's definitions, bits 
  *          definitions and memory mapping for STM32F1xx devices.            
  *            
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripherals registers hardware
  *  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DMA2D_STM32_GD32F4_F7__H_
#define __DMA2D_STM32_GD32F4_F7__H_

/******************************************************************************/
/*                                                                            */
/*                         AHB Master DMA2D Controller (DMA2D)                */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DMA2D_CR register  ******************/

#define DMA2D_CR_START_Pos         (0U)
#define DMA2D_CR_START_Msk         (0x1UL << DMA2D_CR_START_Pos)                /*!< 0x00000001 */
#define DMA2D_CR_START             DMA2D_CR_START_Msk                          /*!< Start transfer                          */
#define DMA2D_CR_SUSP_Pos          (1U)
#define DMA2D_CR_SUSP_Msk          (0x1UL << DMA2D_CR_SUSP_Pos)                 /*!< 0x00000002 */
#define DMA2D_CR_SUSP              DMA2D_CR_SUSP_Msk                           /*!< Suspend transfer                        */
#define DMA2D_CR_ABORT_Pos         (2U)
#define DMA2D_CR_ABORT_Msk         (0x1UL << DMA2D_CR_ABORT_Pos)                /*!< 0x00000004 */
#define DMA2D_CR_ABORT             DMA2D_CR_ABORT_Msk                          /*!< Abort transfer                          */
#define DMA2D_CR_TEIE_Pos          (8U)
#define DMA2D_CR_TEIE_Msk          (0x1UL << DMA2D_CR_TEIE_Pos)                 /*!< 0x00000100 */
#define DMA2D_CR_TEIE              DMA2D_CR_TEIE_Msk                           /*!< Transfer Error Interrupt Enable         */
#define DMA2D_CR_TCIE_Pos          (9U)
#define DMA2D_CR_TCIE_Msk          (0x1UL << DMA2D_CR_TCIE_Pos)                 /*!< 0x00000200 */
#define DMA2D_CR_TCIE              DMA2D_CR_TCIE_Msk                           /*!< Transfer Complete Interrupt Enable      */
#define DMA2D_CR_TWIE_Pos          (10U)
#define DMA2D_CR_TWIE_Msk          (0x1UL << DMA2D_CR_TWIE_Pos)                 /*!< 0x00000400 */
#define DMA2D_CR_TWIE              DMA2D_CR_TWIE_Msk                           /*!< Transfer Watermark Interrupt Enable     */
#define DMA2D_CR_CAEIE_Pos         (11U)
#define DMA2D_CR_CAEIE_Msk         (0x1UL << DMA2D_CR_CAEIE_Pos)                /*!< 0x00000800 */
#define DMA2D_CR_CAEIE             DMA2D_CR_CAEIE_Msk                          /*!< CLUT Access Error Interrupt Enable      */
#define DMA2D_CR_CTCIE_Pos         (12U)
#define DMA2D_CR_CTCIE_Msk         (0x1UL << DMA2D_CR_CTCIE_Pos)                /*!< 0x00001000 */
#define DMA2D_CR_CTCIE             DMA2D_CR_CTCIE_Msk                          /*!< CLUT Transfer Complete Interrupt Enable */
#define DMA2D_CR_CEIE_Pos          (13U)
#define DMA2D_CR_CEIE_Msk          (0x1UL << DMA2D_CR_CEIE_Pos)                 /*!< 0x00002000 */
#define DMA2D_CR_CEIE              DMA2D_CR_CEIE_Msk                           /*!< Configuration Error Interrupt Enable    */
#define DMA2D_CR_MODE_Pos          (16U)
#define DMA2D_CR_MODE_Msk          (0x3UL << DMA2D_CR_MODE_Pos)                 /*!< 0x00030000 */
#define DMA2D_CR_MODE              DMA2D_CR_MODE_Msk                           /*!< DMA2D Mode[1:0]                         */
#define DMA2D_CR_MODE_0            (0x1UL << DMA2D_CR_MODE_Pos)                 /*!< 0x00010000 */
#define DMA2D_CR_MODE_1            (0x2UL << DMA2D_CR_MODE_Pos)                 /*!< 0x00020000 */

/********************  Bit definition for DMA2D_ISR register  *****************/

#define DMA2D_ISR_TEIF_Pos         (0U)
#define DMA2D_ISR_TEIF_Msk         (0x1UL << DMA2D_ISR_TEIF_Pos)                /*!< 0x00000001 */
#define DMA2D_ISR_TEIF             DMA2D_ISR_TEIF_Msk                          /*!< Transfer Error Interrupt Flag         */
#define DMA2D_ISR_TCIF_Pos         (1U)
#define DMA2D_ISR_TCIF_Msk         (0x1UL << DMA2D_ISR_TCIF_Pos)                /*!< 0x00000002 */
#define DMA2D_ISR_TCIF             DMA2D_ISR_TCIF_Msk                          /*!< Transfer Complete Interrupt Flag      */
#define DMA2D_ISR_TWIF_Pos         (2U)
#define DMA2D_ISR_TWIF_Msk         (0x1UL << DMA2D_ISR_TWIF_Pos)                /*!< 0x00000004 */
#define DMA2D_ISR_TWIF             DMA2D_ISR_TWIF_Msk                          /*!< Transfer Watermark Interrupt Flag     */
#define DMA2D_ISR_CAEIF_Pos        (3U)
#define DMA2D_ISR_CAEIF_Msk        (0x1UL << DMA2D_ISR_CAEIF_Pos)               /*!< 0x00000008 */
#define DMA2D_ISR_CAEIF            DMA2D_ISR_CAEIF_Msk                         /*!< CLUT Access Error Interrupt Flag      */
#define DMA2D_ISR_CTCIF_Pos        (4U)
#define DMA2D_ISR_CTCIF_Msk        (0x1UL << DMA2D_ISR_CTCIF_Pos)               /*!< 0x00000010 */
#define DMA2D_ISR_CTCIF            DMA2D_ISR_CTCIF_Msk                         /*!< CLUT Transfer Complete Interrupt Flag */
#define DMA2D_ISR_CEIF_Pos         (5U)
#define DMA2D_ISR_CEIF_Msk         (0x1UL << DMA2D_ISR_CEIF_Pos)                /*!< 0x00000020 */
#define DMA2D_ISR_CEIF             DMA2D_ISR_CEIF_Msk                          /*!< Configuration Error Interrupt Flag    */

/********************  Bit definition for DMA2D_IFCR register  ****************/

#define DMA2D_IFCR_CTEIF_Pos       (0U)
#define DMA2D_IFCR_CTEIF_Msk       (0x1UL << DMA2D_IFCR_CTEIF_Pos)              /*!< 0x00000001 */
#define DMA2D_IFCR_CTEIF           DMA2D_IFCR_CTEIF_Msk                        /*!< Clears Transfer Error Interrupt Flag         */
#define DMA2D_IFCR_CTCIF_Pos       (1U)
#define DMA2D_IFCR_CTCIF_Msk       (0x1UL << DMA2D_IFCR_CTCIF_Pos)              /*!< 0x00000002 */
#define DMA2D_IFCR_CTCIF           DMA2D_IFCR_CTCIF_Msk                        /*!< Clears Transfer Complete Interrupt Flag      */
#define DMA2D_IFCR_CTWIF_Pos       (2U)
#define DMA2D_IFCR_CTWIF_Msk       (0x1UL << DMA2D_IFCR_CTWIF_Pos)              /*!< 0x00000004 */
#define DMA2D_IFCR_CTWIF           DMA2D_IFCR_CTWIF_Msk                        /*!< Clears Transfer Watermark Interrupt Flag     */
#define DMA2D_IFCR_CAECIF_Pos      (3U)
#define DMA2D_IFCR_CAECIF_Msk      (0x1UL << DMA2D_IFCR_CAECIF_Pos)             /*!< 0x00000008 */
#define DMA2D_IFCR_CAECIF          DMA2D_IFCR_CAECIF_Msk                       /*!< Clears CLUT Access Error Interrupt Flag      */
#define DMA2D_IFCR_CCTCIF_Pos      (4U)
#define DMA2D_IFCR_CCTCIF_Msk      (0x1UL << DMA2D_IFCR_CCTCIF_Pos)             /*!< 0x00000010 */
#define DMA2D_IFCR_CCTCIF          DMA2D_IFCR_CCTCIF_Msk                       /*!< Clears CLUT Transfer Complete Interrupt Flag */
#define DMA2D_IFCR_CCEIF_Pos       (5U)
#define DMA2D_IFCR_CCEIF_Msk       (0x1UL << DMA2D_IFCR_CCEIF_Pos)              /*!< 0x00000020 */
#define DMA2D_IFCR_CCEIF           DMA2D_IFCR_CCEIF_Msk                        /*!< Clears Configuration Error Interrupt Flag    */

/* Legacy defines */
#define DMA2D_IFSR_CTEIF                   DMA2D_IFCR_CTEIF                     /*!< Clears Transfer Error Interrupt Flag         */
#define DMA2D_IFSR_CTCIF                   DMA2D_IFCR_CTCIF                     /*!< Clears Transfer Complete Interrupt Flag      */
#define DMA2D_IFSR_CTWIF                   DMA2D_IFCR_CTWIF                     /*!< Clears Transfer Watermark Interrupt Flag     */
#define DMA2D_IFSR_CCAEIF                  DMA2D_IFCR_CAECIF                    /*!< Clears CLUT Access Error Interrupt Flag      */
#define DMA2D_IFSR_CCTCIF                  DMA2D_IFCR_CCTCIF                    /*!< Clears CLUT Transfer Complete Interrupt Flag */
#define DMA2D_IFSR_CCEIF                   DMA2D_IFCR_CCEIF                     /*!< Clears Configuration Error Interrupt Flag    */

/********************  Bit definition for DMA2D_FGMAR register  ***************/

#define DMA2D_FGMAR_MA_Pos         (0U)
#define DMA2D_FGMAR_MA_Msk         (0xFFFFFFFFUL << DMA2D_FGMAR_MA_Pos)         /*!< 0xFFFFFFFF */
#define DMA2D_FGMAR_MA             DMA2D_FGMAR_MA_Msk                          /*!< Memory Address */

/********************  Bit definition for DMA2D_FGOR register  ****************/

#define DMA2D_FGOR_LO_Pos          (0U)
#define DMA2D_FGOR_LO_Msk          (0x3FFFUL << DMA2D_FGOR_LO_Pos)              /*!< 0x00003FFF */
#define DMA2D_FGOR_LO              DMA2D_FGOR_LO_Msk                           /*!< Line Offset */

/********************  Bit definition for DMA2D_BGMAR register  ***************/

#define DMA2D_BGMAR_MA_Pos         (0U)
#define DMA2D_BGMAR_MA_Msk         (0xFFFFFFFFUL << DMA2D_BGMAR_MA_Pos)         /*!< 0xFFFFFFFF */
#define DMA2D_BGMAR_MA             DMA2D_BGMAR_MA_Msk                          /*!< Memory Address */

/********************  Bit definition for DMA2D_BGOR register  ****************/

#define DMA2D_BGOR_LO_Pos          (0U)
#define DMA2D_BGOR_LO_Msk          (0x3FFFUL << DMA2D_BGOR_LO_Pos)              /*!< 0x00003FFF */
#define DMA2D_BGOR_LO              DMA2D_BGOR_LO_Msk                           /*!< Line Offset */

/********************  Bit definition for DMA2D_FGPFCCR register  *************/

#define DMA2D_FGPFCCR_CM_Pos       (0U)
#define DMA2D_FGPFCCR_CM_Msk       (0xFUL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x0000000F */
#define DMA2D_FGPFCCR_CM           DMA2D_FGPFCCR_CM_Msk                        /*!< Input color mode CM[3:0] */
#define DMA2D_FGPFCCR_CM_0         (0x1UL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x00000001 */
#define DMA2D_FGPFCCR_CM_1         (0x2UL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x00000002 */
#define DMA2D_FGPFCCR_CM_2         (0x4UL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x00000004 */
#define DMA2D_FGPFCCR_CM_3         (0x8UL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x00000008 */
#define DMA2D_FGPFCCR_CCM_Pos      (4U)
#define DMA2D_FGPFCCR_CCM_Msk      (0x1UL << DMA2D_FGPFCCR_CCM_Pos)             /*!< 0x00000010 */
#define DMA2D_FGPFCCR_CCM          DMA2D_FGPFCCR_CCM_Msk                       /*!< CLUT Color mode */
#define DMA2D_FGPFCCR_START_Pos    (5U)
#define DMA2D_FGPFCCR_START_Msk    (0x1UL << DMA2D_FGPFCCR_START_Pos)           /*!< 0x00000020 */
#define DMA2D_FGPFCCR_START        DMA2D_FGPFCCR_START_Msk                     /*!< Start */
#define DMA2D_FGPFCCR_CS_Pos       (8U)
#define DMA2D_FGPFCCR_CS_Msk       (0xFFUL << DMA2D_FGPFCCR_CS_Pos)             /*!< 0x0000FF00 */
#define DMA2D_FGPFCCR_CS           DMA2D_FGPFCCR_CS_Msk                        /*!< CLUT size */
#define DMA2D_FGPFCCR_AM_Pos       (16U)
#define DMA2D_FGPFCCR_AM_Msk       (0x3UL << DMA2D_FGPFCCR_AM_Pos)              /*!< 0x00030000 */
#define DMA2D_FGPFCCR_AM           DMA2D_FGPFCCR_AM_Msk                        /*!< Alpha mode AM[1:0] */
#define DMA2D_FGPFCCR_AM_0         (0x1UL << DMA2D_FGPFCCR_AM_Pos)              /*!< 0x00010000 */
#define DMA2D_FGPFCCR_AM_1         (0x2UL << DMA2D_FGPFCCR_AM_Pos)              /*!< 0x00020000 */
#define DMA2D_FGPFCCR_ALPHA_Pos    (24U)
#define DMA2D_FGPFCCR_ALPHA_Msk    (0xFFUL << DMA2D_FGPFCCR_ALPHA_Pos)          /*!< 0xFF000000 */
#define DMA2D_FGPFCCR_ALPHA        DMA2D_FGPFCCR_ALPHA_Msk                     /*!< Alpha value */

/********************  Bit definition for DMA2D_FGCOLR register  **************/

#define DMA2D_FGCOLR_BLUE_Pos      (0U)
#define DMA2D_FGCOLR_BLUE_Msk      (0xFFUL << DMA2D_FGCOLR_BLUE_Pos)            /*!< 0x000000FF */
#define DMA2D_FGCOLR_BLUE          DMA2D_FGCOLR_BLUE_Msk                       /*!< Blue Value */
#define DMA2D_FGCOLR_GREEN_Pos     (8U)
#define DMA2D_FGCOLR_GREEN_Msk     (0xFFUL << DMA2D_FGCOLR_GREEN_Pos)           /*!< 0x0000FF00 */
#define DMA2D_FGCOLR_GREEN         DMA2D_FGCOLR_GREEN_Msk                      /*!< Green Value */
#define DMA2D_FGCOLR_RED_Pos       (16U)
#define DMA2D_FGCOLR_RED_Msk       (0xFFUL << DMA2D_FGCOLR_RED_Pos)             /*!< 0x00FF0000 */
#define DMA2D_FGCOLR_RED           DMA2D_FGCOLR_RED_Msk                        /*!< Red Value */

/********************  Bit definition for DMA2D_BGPFCCR register  *************/

#define DMA2D_BGPFCCR_CM_Pos       (0U)
#define DMA2D_BGPFCCR_CM_Msk       (0xFUL << DMA2D_BGPFCCR_CM_Pos)              /*!< 0x0000000F */
#define DMA2D_BGPFCCR_CM           DMA2D_BGPFCCR_CM_Msk                        /*!< Input color mode CM[3:0] */
#define DMA2D_BGPFCCR_CM_0         (0x1UL << DMA2D_BGPFCCR_CM_Pos)              /*!< 0x00000001 */
#define DMA2D_BGPFCCR_CM_1         (0x2UL << DMA2D_BGPFCCR_CM_Pos)              /*!< 0x00000002 */
#define DMA2D_BGPFCCR_CM_2         (0x4UL << DMA2D_BGPFCCR_CM_Pos)              /*!< 0x00000004 */
#define DMA2D_BGPFCCR_CM_3         0x00000008U                                 /*!< Input color mode CM bit 3 */
#define DMA2D_BGPFCCR_CCM_Pos      (4U)
#define DMA2D_BGPFCCR_CCM_Msk      (0x1UL << DMA2D_BGPFCCR_CCM_Pos)             /*!< 0x00000010 */
#define DMA2D_BGPFCCR_CCM          DMA2D_BGPFCCR_CCM_Msk                       /*!< CLUT Color mode */
#define DMA2D_BGPFCCR_START_Pos    (5U)
#define DMA2D_BGPFCCR_START_Msk    (0x1UL << DMA2D_BGPFCCR_START_Pos)           /*!< 0x00000020 */
#define DMA2D_BGPFCCR_START        DMA2D_BGPFCCR_START_Msk                     /*!< Start */
#define DMA2D_BGPFCCR_CS_Pos       (8U)
#define DMA2D_BGPFCCR_CS_Msk       (0xFFUL << DMA2D_BGPFCCR_CS_Pos)             /*!< 0x0000FF00 */
#define DMA2D_BGPFCCR_CS           DMA2D_BGPFCCR_CS_Msk                        /*!< CLUT size */
#define DMA2D_BGPFCCR_AM_Pos       (16U)
#define DMA2D_BGPFCCR_AM_Msk       (0x3UL << DMA2D_BGPFCCR_AM_Pos)              /*!< 0x00030000 */
#define DMA2D_BGPFCCR_AM           DMA2D_BGPFCCR_AM_Msk                        /*!< Alpha mode AM[1:0] */
#define DMA2D_BGPFCCR_AM_0         (0x1UL << DMA2D_BGPFCCR_AM_Pos)              /*!< 0x00010000 */
#define DMA2D_BGPFCCR_AM_1         (0x2UL << DMA2D_BGPFCCR_AM_Pos)              /*!< 0x00020000 */
#define DMA2D_BGPFCCR_ALPHA_Pos    (24U)
#define DMA2D_BGPFCCR_ALPHA_Msk    (0xFFUL << DMA2D_BGPFCCR_ALPHA_Pos)          /*!< 0xFF000000 */
#define DMA2D_BGPFCCR_ALPHA        DMA2D_BGPFCCR_ALPHA_Msk                     /*!< background Input Alpha value */

/********************  Bit definition for DMA2D_BGCOLR register  **************/

#define DMA2D_BGCOLR_BLUE_Pos      (0U)
#define DMA2D_BGCOLR_BLUE_Msk      (0xFFUL << DMA2D_BGCOLR_BLUE_Pos)            /*!< 0x000000FF */
#define DMA2D_BGCOLR_BLUE          DMA2D_BGCOLR_BLUE_Msk                       /*!< Blue Value */
#define DMA2D_BGCOLR_GREEN_Pos     (8U)
#define DMA2D_BGCOLR_GREEN_Msk     (0xFFUL << DMA2D_BGCOLR_GREEN_Pos)           /*!< 0x0000FF00 */
#define DMA2D_BGCOLR_GREEN         DMA2D_BGCOLR_GREEN_Msk                      /*!< Green Value */
#define DMA2D_BGCOLR_RED_Pos       (16U)
#define DMA2D_BGCOLR_RED_Msk       (0xFFUL << DMA2D_BGCOLR_RED_Pos)             /*!< 0x00FF0000 */
#define DMA2D_BGCOLR_RED           DMA2D_BGCOLR_RED_Msk                        /*!< Red Value */

/********************  Bit definition for DMA2D_FGCMAR register  **************/

#define DMA2D_FGCMAR_MA_Pos        (0U)
#define DMA2D_FGCMAR_MA_Msk        (0xFFFFFFFFUL << DMA2D_FGCMAR_MA_Pos)        /*!< 0xFFFFFFFF */
#define DMA2D_FGCMAR_MA            DMA2D_FGCMAR_MA_Msk                         /*!< Memory Address */

/********************  Bit definition for DMA2D_BGCMAR register  **************/

#define DMA2D_BGCMAR_MA_Pos        (0U)
#define DMA2D_BGCMAR_MA_Msk        (0xFFFFFFFFUL << DMA2D_BGCMAR_MA_Pos)        /*!< 0xFFFFFFFF */
#define DMA2D_BGCMAR_MA            DMA2D_BGCMAR_MA_Msk                         /*!< Memory Address */

/********************  Bit definition for DMA2D_OPFCCR register  **************/

#define DMA2D_OPFCCR_CM_Pos        (0U)
#define DMA2D_OPFCCR_CM_Msk        (0x7UL << DMA2D_OPFCCR_CM_Pos)               /*!< 0x00000007 */
#define DMA2D_OPFCCR_CM            DMA2D_OPFCCR_CM_Msk                         /*!< Color mode CM[2:0] */
#define DMA2D_OPFCCR_CM_0          (0x1UL << DMA2D_OPFCCR_CM_Pos)               /*!< 0x00000001 */
#define DMA2D_OPFCCR_CM_1          (0x2UL << DMA2D_OPFCCR_CM_Pos)               /*!< 0x00000002 */
#define DMA2D_OPFCCR_CM_2          (0x4UL << DMA2D_OPFCCR_CM_Pos)               /*!< 0x00000004 */

/********************  Bit definition for DMA2D_OCOLR register  ***************/

/*!<Mode_ARGB8888/RGB888 */

#define DMA2D_OCOLR_BLUE_1         0x000000FFU                                 /*!< BLUE Value */
#define DMA2D_OCOLR_GREEN_1        0x0000FF00U                                 /*!< GREEN Value  */
#define DMA2D_OCOLR_RED_1          0x00FF0000U                                 /*!< Red Value */
#define DMA2D_OCOLR_ALPHA_1        0xFF000000U                                 /*!< Alpha Channel Value */

/*!<Mode_RGB565 */
#define DMA2D_OCOLR_BLUE_2         0x0000001FU                                 /*!< BLUE Value */
#define DMA2D_OCOLR_GREEN_2        0x000007E0U                                 /*!< GREEN Value  */
#define DMA2D_OCOLR_RED_2          0x0000F800U                                 /*!< Red Value */

/*!<Mode_ARGB1555 */
#define DMA2D_OCOLR_BLUE_3         0x0000001FU                                 /*!< BLUE Value */
#define DMA2D_OCOLR_GREEN_3        0x000003E0U                                 /*!< GREEN Value  */
#define DMA2D_OCOLR_RED_3          0x00007C00U                                 /*!< Red Value */
#define DMA2D_OCOLR_ALPHA_3        0x00008000U                                 /*!< Alpha Channel Value */

/*!<Mode_ARGB4444 */
#define DMA2D_OCOLR_BLUE_4         0x0000000FU                                 /*!< BLUE Value */
#define DMA2D_OCOLR_GREEN_4        0x000000F0U                                 /*!< GREEN Value  */
#define DMA2D_OCOLR_RED_4          0x00000F00U                                 /*!< Red Value */
#define DMA2D_OCOLR_ALPHA_4        0x0000F000U                                 /*!< Alpha Channel Value */

/********************  Bit definition for DMA2D_OMAR register  ****************/

#define DMA2D_OMAR_MA_Pos          (0U)
#define DMA2D_OMAR_MA_Msk          (0xFFFFFFFFUL << DMA2D_OMAR_MA_Pos)          /*!< 0xFFFFFFFF */
#define DMA2D_OMAR_MA              DMA2D_OMAR_MA_Msk                           /*!< Memory Address */

/********************  Bit definition for DMA2D_OOR register  *****************/

#define DMA2D_OOR_LO_Pos           (0U)
#define DMA2D_OOR_LO_Msk           (0x3FFFUL << DMA2D_OOR_LO_Pos)               /*!< 0x00003FFF */
#define DMA2D_OOR_LO               DMA2D_OOR_LO_Msk                            /*!< Line Offset */

/********************  Bit definition for DMA2D_NLR register  *****************/

#define DMA2D_NLR_NL_Pos           (0U)
#define DMA2D_NLR_NL_Msk           (0xFFFFUL << DMA2D_NLR_NL_Pos)               /*!< 0x0000FFFF */
#define DMA2D_NLR_NL               DMA2D_NLR_NL_Msk                            /*!< Number of Lines */
#define DMA2D_NLR_PL_Pos           (16U)
#define DMA2D_NLR_PL_Msk           (0x3FFFUL << DMA2D_NLR_PL_Pos)               /*!< 0x3FFF0000 */
#define DMA2D_NLR_PL               DMA2D_NLR_PL_Msk                            /*!< Pixel per Lines */

/********************  Bit definition for DMA2D_LWR register  *****************/

#define DMA2D_LWR_LW_Pos           (0U)
#define DMA2D_LWR_LW_Msk           (0xFFFFUL << DMA2D_LWR_LW_Pos)               /*!< 0x0000FFFF */
#define DMA2D_LWR_LW               DMA2D_LWR_LW_Msk                            /*!< Line Watermark */

/********************  Bit definition for DMA2D_AMTCR register  ***************/

#define DMA2D_AMTCR_EN_Pos         (0U)
#define DMA2D_AMTCR_EN_Msk         (0x1UL << DMA2D_AMTCR_EN_Pos)                /*!< 0x00000001 */
#define DMA2D_AMTCR_EN             DMA2D_AMTCR_EN_Msk                          /*!< Enable */
#define DMA2D_AMTCR_DT_Pos         (8U)
#define DMA2D_AMTCR_DT_Msk         (0xFFUL << DMA2D_AMTCR_DT_Pos)               /*!< 0x0000FF00 */
#define DMA2D_AMTCR_DT             DMA2D_AMTCR_DT_Msk                          /*!< Dead Time */

// 레지스터 목록
namespace DMA2D_REG
{
enum
{
	CR = 0,		ISR,		IFCR,		FGMAR,		FGOR,		
	BGMAR,		BGOR,		FGPFCCR, 	FGCOLR,		BGPFCCR,	
	BGCOLR,		FGCMAR,		BGCMAR,		OPFCCR,		OCOLR,		
	OMAR,		OOR,		NLR,		LWR,		AMTCR
};
}

#endif

