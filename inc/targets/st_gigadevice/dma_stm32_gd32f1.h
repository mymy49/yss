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
#ifndef __DMA_STM32_GD32F1__H_
#define __DMA_STM32_GD32F1__H_

/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for DMA_ISR register  ********************/
#define DMA_ISR_GIF1_Pos                    (0U)                               
#define DMA_ISR_GIF1_Msk                    (0x1UL << DMA_ISR_GIF1_Pos)         /*!< 0x00000001 */
#define DMA_ISR_GIF1                        DMA_ISR_GIF1_Msk                   /*!< Channel 1 Global interrupt flag */
#define DMA_ISR_TCIF1_Pos                   (1U)                               
#define DMA_ISR_TCIF1_Msk                   (0x1UL << DMA_ISR_TCIF1_Pos)        /*!< 0x00000002 */
#define DMA_ISR_TCIF1                       DMA_ISR_TCIF1_Msk                  /*!< Channel 1 Transfer Complete flag */
#define DMA_ISR_HTIF1_Pos                   (2U)                               
#define DMA_ISR_HTIF1_Msk                   (0x1UL << DMA_ISR_HTIF1_Pos)        /*!< 0x00000004 */
#define DMA_ISR_HTIF1                       DMA_ISR_HTIF1_Msk                  /*!< Channel 1 Half Transfer flag */
#define DMA_ISR_TEIF1_Pos                   (3U)                               
#define DMA_ISR_TEIF1_Msk                   (0x1UL << DMA_ISR_TEIF1_Pos)        /*!< 0x00000008 */
#define DMA_ISR_TEIF1                       DMA_ISR_TEIF1_Msk                  /*!< Channel 1 Transfer Error flag */
#define DMA_ISR_GIF2_Pos                    (4U)                               
#define DMA_ISR_GIF2_Msk                    (0x1UL << DMA_ISR_GIF2_Pos)         /*!< 0x00000010 */
#define DMA_ISR_GIF2                        DMA_ISR_GIF2_Msk                   /*!< Channel 2 Global interrupt flag */
#define DMA_ISR_TCIF2_Pos                   (5U)                               
#define DMA_ISR_TCIF2_Msk                   (0x1UL << DMA_ISR_TCIF2_Pos)        /*!< 0x00000020 */
#define DMA_ISR_TCIF2                       DMA_ISR_TCIF2_Msk                  /*!< Channel 2 Transfer Complete flag */
#define DMA_ISR_HTIF2_Pos                   (6U)                               
#define DMA_ISR_HTIF2_Msk                   (0x1UL << DMA_ISR_HTIF2_Pos)        /*!< 0x00000040 */
#define DMA_ISR_HTIF2                       DMA_ISR_HTIF2_Msk                  /*!< Channel 2 Half Transfer flag */
#define DMA_ISR_TEIF2_Pos                   (7U)                               
#define DMA_ISR_TEIF2_Msk                   (0x1UL << DMA_ISR_TEIF2_Pos)        /*!< 0x00000080 */
#define DMA_ISR_TEIF2                       DMA_ISR_TEIF2_Msk                  /*!< Channel 2 Transfer Error flag */
#define DMA_ISR_GIF3_Pos                    (8U)                               
#define DMA_ISR_GIF3_Msk                    (0x1UL << DMA_ISR_GIF3_Pos)         /*!< 0x00000100 */
#define DMA_ISR_GIF3                        DMA_ISR_GIF3_Msk                   /*!< Channel 3 Global interrupt flag */
#define DMA_ISR_TCIF3_Pos                   (9U)                               
#define DMA_ISR_TCIF3_Msk                   (0x1UL << DMA_ISR_TCIF3_Pos)        /*!< 0x00000200 */
#define DMA_ISR_TCIF3                       DMA_ISR_TCIF3_Msk                  /*!< Channel 3 Transfer Complete flag */
#define DMA_ISR_HTIF3_Pos                   (10U)                              
#define DMA_ISR_HTIF3_Msk                   (0x1UL << DMA_ISR_HTIF3_Pos)        /*!< 0x00000400 */
#define DMA_ISR_HTIF3                       DMA_ISR_HTIF3_Msk                  /*!< Channel 3 Half Transfer flag */
#define DMA_ISR_TEIF3_Pos                   (11U)                              
#define DMA_ISR_TEIF3_Msk                   (0x1UL << DMA_ISR_TEIF3_Pos)        /*!< 0x00000800 */
#define DMA_ISR_TEIF3                       DMA_ISR_TEIF3_Msk                  /*!< Channel 3 Transfer Error flag */
#define DMA_ISR_GIF4_Pos                    (12U)                              
#define DMA_ISR_GIF4_Msk                    (0x1UL << DMA_ISR_GIF4_Pos)         /*!< 0x00001000 */
#define DMA_ISR_GIF4                        DMA_ISR_GIF4_Msk                   /*!< Channel 4 Global interrupt flag */
#define DMA_ISR_TCIF4_Pos                   (13U)                              
#define DMA_ISR_TCIF4_Msk                   (0x1UL << DMA_ISR_TCIF4_Pos)        /*!< 0x00002000 */
#define DMA_ISR_TCIF4                       DMA_ISR_TCIF4_Msk                  /*!< Channel 4 Transfer Complete flag */
#define DMA_ISR_HTIF4_Pos                   (14U)                              
#define DMA_ISR_HTIF4_Msk                   (0x1UL << DMA_ISR_HTIF4_Pos)        /*!< 0x00004000 */
#define DMA_ISR_HTIF4                       DMA_ISR_HTIF4_Msk                  /*!< Channel 4 Half Transfer flag */
#define DMA_ISR_TEIF4_Pos                   (15U)                              
#define DMA_ISR_TEIF4_Msk                   (0x1UL << DMA_ISR_TEIF4_Pos)        /*!< 0x00008000 */
#define DMA_ISR_TEIF4                       DMA_ISR_TEIF4_Msk                  /*!< Channel 4 Transfer Error flag */
#define DMA_ISR_GIF5_Pos                    (16U)                              
#define DMA_ISR_GIF5_Msk                    (0x1UL << DMA_ISR_GIF5_Pos)         /*!< 0x00010000 */
#define DMA_ISR_GIF5                        DMA_ISR_GIF5_Msk                   /*!< Channel 5 Global interrupt flag */
#define DMA_ISR_TCIF5_Pos                   (17U)                              
#define DMA_ISR_TCIF5_Msk                   (0x1UL << DMA_ISR_TCIF5_Pos)        /*!< 0x00020000 */
#define DMA_ISR_TCIF5                       DMA_ISR_TCIF5_Msk                  /*!< Channel 5 Transfer Complete flag */
#define DMA_ISR_HTIF5_Pos                   (18U)                              
#define DMA_ISR_HTIF5_Msk                   (0x1UL << DMA_ISR_HTIF5_Pos)        /*!< 0x00040000 */
#define DMA_ISR_HTIF5                       DMA_ISR_HTIF5_Msk                  /*!< Channel 5 Half Transfer flag */
#define DMA_ISR_TEIF5_Pos                   (19U)                              
#define DMA_ISR_TEIF5_Msk                   (0x1UL << DMA_ISR_TEIF5_Pos)        /*!< 0x00080000 */
#define DMA_ISR_TEIF5                       DMA_ISR_TEIF5_Msk                  /*!< Channel 5 Transfer Error flag */
#define DMA_ISR_GIF6_Pos                    (20U)                              
#define DMA_ISR_GIF6_Msk                    (0x1UL << DMA_ISR_GIF6_Pos)         /*!< 0x00100000 */
#define DMA_ISR_GIF6                        DMA_ISR_GIF6_Msk                   /*!< Channel 6 Global interrupt flag */
#define DMA_ISR_TCIF6_Pos                   (21U)                              
#define DMA_ISR_TCIF6_Msk                   (0x1UL << DMA_ISR_TCIF6_Pos)        /*!< 0x00200000 */
#define DMA_ISR_TCIF6                       DMA_ISR_TCIF6_Msk                  /*!< Channel 6 Transfer Complete flag */
#define DMA_ISR_HTIF6_Pos                   (22U)                              
#define DMA_ISR_HTIF6_Msk                   (0x1UL << DMA_ISR_HTIF6_Pos)        /*!< 0x00400000 */
#define DMA_ISR_HTIF6                       DMA_ISR_HTIF6_Msk                  /*!< Channel 6 Half Transfer flag */
#define DMA_ISR_TEIF6_Pos                   (23U)                              
#define DMA_ISR_TEIF6_Msk                   (0x1UL << DMA_ISR_TEIF6_Pos)        /*!< 0x00800000 */
#define DMA_ISR_TEIF6                       DMA_ISR_TEIF6_Msk                  /*!< Channel 6 Transfer Error flag */
#define DMA_ISR_GIF7_Pos                    (24U)                              
#define DMA_ISR_GIF7_Msk                    (0x1UL << DMA_ISR_GIF7_Pos)         /*!< 0x01000000 */
#define DMA_ISR_GIF7                        DMA_ISR_GIF7_Msk                   /*!< Channel 7 Global interrupt flag */
#define DMA_ISR_TCIF7_Pos                   (25U)                              
#define DMA_ISR_TCIF7_Msk                   (0x1UL << DMA_ISR_TCIF7_Pos)        /*!< 0x02000000 */
#define DMA_ISR_TCIF7                       DMA_ISR_TCIF7_Msk                  /*!< Channel 7 Transfer Complete flag */
#define DMA_ISR_HTIF7_Pos                   (26U)                              
#define DMA_ISR_HTIF7_Msk                   (0x1UL << DMA_ISR_HTIF7_Pos)        /*!< 0x04000000 */
#define DMA_ISR_HTIF7                       DMA_ISR_HTIF7_Msk                  /*!< Channel 7 Half Transfer flag */
#define DMA_ISR_TEIF7_Pos                   (27U)                              
#define DMA_ISR_TEIF7_Msk                   (0x1UL << DMA_ISR_TEIF7_Pos)        /*!< 0x08000000 */
#define DMA_ISR_TEIF7                       DMA_ISR_TEIF7_Msk                  /*!< Channel 7 Transfer Error flag */

/*******************  Bit definition for DMA_IFCR register  *******************/
#define DMA_IFCR_CGIF1_Pos                  (0U)                               
#define DMA_IFCR_CGIF1_Msk                  (0x1UL << DMA_IFCR_CGIF1_Pos)       /*!< 0x00000001 */
#define DMA_IFCR_CGIF1                      DMA_IFCR_CGIF1_Msk                 /*!< Channel 1 Global interrupt clear */
#define DMA_IFCR_CTCIF1_Pos                 (1U)                               
#define DMA_IFCR_CTCIF1_Msk                 (0x1UL << DMA_IFCR_CTCIF1_Pos)      /*!< 0x00000002 */
#define DMA_IFCR_CTCIF1                     DMA_IFCR_CTCIF1_Msk                /*!< Channel 1 Transfer Complete clear */
#define DMA_IFCR_CHTIF1_Pos                 (2U)                               
#define DMA_IFCR_CHTIF1_Msk                 (0x1UL << DMA_IFCR_CHTIF1_Pos)      /*!< 0x00000004 */
#define DMA_IFCR_CHTIF1                     DMA_IFCR_CHTIF1_Msk                /*!< Channel 1 Half Transfer clear */
#define DMA_IFCR_CTEIF1_Pos                 (3U)                               
#define DMA_IFCR_CTEIF1_Msk                 (0x1UL << DMA_IFCR_CTEIF1_Pos)      /*!< 0x00000008 */
#define DMA_IFCR_CTEIF1                     DMA_IFCR_CTEIF1_Msk                /*!< Channel 1 Transfer Error clear */
#define DMA_IFCR_CGIF2_Pos                  (4U)                               
#define DMA_IFCR_CGIF2_Msk                  (0x1UL << DMA_IFCR_CGIF2_Pos)       /*!< 0x00000010 */
#define DMA_IFCR_CGIF2                      DMA_IFCR_CGIF2_Msk                 /*!< Channel 2 Global interrupt clear */
#define DMA_IFCR_CTCIF2_Pos                 (5U)                               
#define DMA_IFCR_CTCIF2_Msk                 (0x1UL << DMA_IFCR_CTCIF2_Pos)      /*!< 0x00000020 */
#define DMA_IFCR_CTCIF2                     DMA_IFCR_CTCIF2_Msk                /*!< Channel 2 Transfer Complete clear */
#define DMA_IFCR_CHTIF2_Pos                 (6U)                               
#define DMA_IFCR_CHTIF2_Msk                 (0x1UL << DMA_IFCR_CHTIF2_Pos)      /*!< 0x00000040 */
#define DMA_IFCR_CHTIF2                     DMA_IFCR_CHTIF2_Msk                /*!< Channel 2 Half Transfer clear */
#define DMA_IFCR_CTEIF2_Pos                 (7U)                               
#define DMA_IFCR_CTEIF2_Msk                 (0x1UL << DMA_IFCR_CTEIF2_Pos)      /*!< 0x00000080 */
#define DMA_IFCR_CTEIF2                     DMA_IFCR_CTEIF2_Msk                /*!< Channel 2 Transfer Error clear */
#define DMA_IFCR_CGIF3_Pos                  (8U)                               
#define DMA_IFCR_CGIF3_Msk                  (0x1UL << DMA_IFCR_CGIF3_Pos)       /*!< 0x00000100 */
#define DMA_IFCR_CGIF3                      DMA_IFCR_CGIF3_Msk                 /*!< Channel 3 Global interrupt clear */
#define DMA_IFCR_CTCIF3_Pos                 (9U)                               
#define DMA_IFCR_CTCIF3_Msk                 (0x1UL << DMA_IFCR_CTCIF3_Pos)      /*!< 0x00000200 */
#define DMA_IFCR_CTCIF3                     DMA_IFCR_CTCIF3_Msk                /*!< Channel 3 Transfer Complete clear */
#define DMA_IFCR_CHTIF3_Pos                 (10U)                              
#define DMA_IFCR_CHTIF3_Msk                 (0x1UL << DMA_IFCR_CHTIF3_Pos)      /*!< 0x00000400 */
#define DMA_IFCR_CHTIF3                     DMA_IFCR_CHTIF3_Msk                /*!< Channel 3 Half Transfer clear */
#define DMA_IFCR_CTEIF3_Pos                 (11U)                              
#define DMA_IFCR_CTEIF3_Msk                 (0x1UL << DMA_IFCR_CTEIF3_Pos)      /*!< 0x00000800 */
#define DMA_IFCR_CTEIF3                     DMA_IFCR_CTEIF3_Msk                /*!< Channel 3 Transfer Error clear */
#define DMA_IFCR_CGIF4_Pos                  (12U)                              
#define DMA_IFCR_CGIF4_Msk                  (0x1UL << DMA_IFCR_CGIF4_Pos)       /*!< 0x00001000 */
#define DMA_IFCR_CGIF4                      DMA_IFCR_CGIF4_Msk                 /*!< Channel 4 Global interrupt clear */
#define DMA_IFCR_CTCIF4_Pos                 (13U)                              
#define DMA_IFCR_CTCIF4_Msk                 (0x1UL << DMA_IFCR_CTCIF4_Pos)      /*!< 0x00002000 */
#define DMA_IFCR_CTCIF4                     DMA_IFCR_CTCIF4_Msk                /*!< Channel 4 Transfer Complete clear */
#define DMA_IFCR_CHTIF4_Pos                 (14U)                              
#define DMA_IFCR_CHTIF4_Msk                 (0x1UL << DMA_IFCR_CHTIF4_Pos)      /*!< 0x00004000 */
#define DMA_IFCR_CHTIF4                     DMA_IFCR_CHTIF4_Msk                /*!< Channel 4 Half Transfer clear */
#define DMA_IFCR_CTEIF4_Pos                 (15U)                              
#define DMA_IFCR_CTEIF4_Msk                 (0x1UL << DMA_IFCR_CTEIF4_Pos)      /*!< 0x00008000 */
#define DMA_IFCR_CTEIF4                     DMA_IFCR_CTEIF4_Msk                /*!< Channel 4 Transfer Error clear */
#define DMA_IFCR_CGIF5_Pos                  (16U)                              
#define DMA_IFCR_CGIF5_Msk                  (0x1UL << DMA_IFCR_CGIF5_Pos)       /*!< 0x00010000 */
#define DMA_IFCR_CGIF5                      DMA_IFCR_CGIF5_Msk                 /*!< Channel 5 Global interrupt clear */
#define DMA_IFCR_CTCIF5_Pos                 (17U)                              
#define DMA_IFCR_CTCIF5_Msk                 (0x1UL << DMA_IFCR_CTCIF5_Pos)      /*!< 0x00020000 */
#define DMA_IFCR_CTCIF5                     DMA_IFCR_CTCIF5_Msk                /*!< Channel 5 Transfer Complete clear */
#define DMA_IFCR_CHTIF5_Pos                 (18U)                              
#define DMA_IFCR_CHTIF5_Msk                 (0x1UL << DMA_IFCR_CHTIF5_Pos)      /*!< 0x00040000 */
#define DMA_IFCR_CHTIF5                     DMA_IFCR_CHTIF5_Msk                /*!< Channel 5 Half Transfer clear */
#define DMA_IFCR_CTEIF5_Pos                 (19U)                              
#define DMA_IFCR_CTEIF5_Msk                 (0x1UL << DMA_IFCR_CTEIF5_Pos)      /*!< 0x00080000 */
#define DMA_IFCR_CTEIF5                     DMA_IFCR_CTEIF5_Msk                /*!< Channel 5 Transfer Error clear */
#define DMA_IFCR_CGIF6_Pos                  (20U)                              
#define DMA_IFCR_CGIF6_Msk                  (0x1UL << DMA_IFCR_CGIF6_Pos)       /*!< 0x00100000 */
#define DMA_IFCR_CGIF6                      DMA_IFCR_CGIF6_Msk                 /*!< Channel 6 Global interrupt clear */
#define DMA_IFCR_CTCIF6_Pos                 (21U)                              
#define DMA_IFCR_CTCIF6_Msk                 (0x1UL << DMA_IFCR_CTCIF6_Pos)      /*!< 0x00200000 */
#define DMA_IFCR_CTCIF6                     DMA_IFCR_CTCIF6_Msk                /*!< Channel 6 Transfer Complete clear */
#define DMA_IFCR_CHTIF6_Pos                 (22U)                              
#define DMA_IFCR_CHTIF6_Msk                 (0x1UL << DMA_IFCR_CHTIF6_Pos)      /*!< 0x00400000 */
#define DMA_IFCR_CHTIF6                     DMA_IFCR_CHTIF6_Msk                /*!< Channel 6 Half Transfer clear */
#define DMA_IFCR_CTEIF6_Pos                 (23U)                              
#define DMA_IFCR_CTEIF6_Msk                 (0x1UL << DMA_IFCR_CTEIF6_Pos)      /*!< 0x00800000 */
#define DMA_IFCR_CTEIF6                     DMA_IFCR_CTEIF6_Msk                /*!< Channel 6 Transfer Error clear */
#define DMA_IFCR_CGIF7_Pos                  (24U)                              
#define DMA_IFCR_CGIF7_Msk                  (0x1UL << DMA_IFCR_CGIF7_Pos)       /*!< 0x01000000 */
#define DMA_IFCR_CGIF7                      DMA_IFCR_CGIF7_Msk                 /*!< Channel 7 Global interrupt clear */
#define DMA_IFCR_CTCIF7_Pos                 (25U)                              
#define DMA_IFCR_CTCIF7_Msk                 (0x1UL << DMA_IFCR_CTCIF7_Pos)      /*!< 0x02000000 */
#define DMA_IFCR_CTCIF7                     DMA_IFCR_CTCIF7_Msk                /*!< Channel 7 Transfer Complete clear */
#define DMA_IFCR_CHTIF7_Pos                 (26U)                              
#define DMA_IFCR_CHTIF7_Msk                 (0x1UL << DMA_IFCR_CHTIF7_Pos)      /*!< 0x04000000 */
#define DMA_IFCR_CHTIF7                     DMA_IFCR_CHTIF7_Msk                /*!< Channel 7 Half Transfer clear */
#define DMA_IFCR_CTEIF7_Pos                 (27U)                              
#define DMA_IFCR_CTEIF7_Msk                 (0x1UL << DMA_IFCR_CTEIF7_Pos)      /*!< 0x08000000 */
#define DMA_IFCR_CTEIF7                     DMA_IFCR_CTEIF7_Msk                /*!< Channel 7 Transfer Error clear */

/*******************  Bit definition for DMA_CCR register   *******************/
#define DMA_CCR_EN_Pos                      (0U)                               
#define DMA_CCR_EN_Msk                      (0x1UL << DMA_CCR_EN_Pos)           /*!< 0x00000001 */
#define DMA_CCR_EN                          DMA_CCR_EN_Msk                     /*!< Channel enable */
#define DMA_CCR_TCIE_Pos                    (1U)                               
#define DMA_CCR_TCIE_Msk                    (0x1UL << DMA_CCR_TCIE_Pos)         /*!< 0x00000002 */
#define DMA_CCR_TCIE                        DMA_CCR_TCIE_Msk                   /*!< Transfer complete interrupt enable */
#define DMA_CCR_HTIE_Pos                    (2U)                               
#define DMA_CCR_HTIE_Msk                    (0x1UL << DMA_CCR_HTIE_Pos)         /*!< 0x00000004 */
#define DMA_CCR_HTIE                        DMA_CCR_HTIE_Msk                   /*!< Half Transfer interrupt enable */
#define DMA_CCR_TEIE_Pos                    (3U)                               
#define DMA_CCR_TEIE_Msk                    (0x1UL << DMA_CCR_TEIE_Pos)         /*!< 0x00000008 */
#define DMA_CCR_TEIE                        DMA_CCR_TEIE_Msk                   /*!< Transfer error interrupt enable */
#define DMA_CCR_DIR_Pos                     (4U)                               
#define DMA_CCR_DIR_Msk                     (0x1UL << DMA_CCR_DIR_Pos)          /*!< 0x00000010 */
#define DMA_CCR_DIR                         DMA_CCR_DIR_Msk                    /*!< Data transfer direction */
#define DMA_CCR_CIRC_Pos                    (5U)                               
#define DMA_CCR_CIRC_Msk                    (0x1UL << DMA_CCR_CIRC_Pos)         /*!< 0x00000020 */
#define DMA_CCR_CIRC                        DMA_CCR_CIRC_Msk                   /*!< Circular mode */
#define DMA_CCR_PINC_Pos                    (6U)                               
#define DMA_CCR_PINC_Msk                    (0x1UL << DMA_CCR_PINC_Pos)         /*!< 0x00000040 */
#define DMA_CCR_PINC                        DMA_CCR_PINC_Msk                   /*!< Peripheral increment mode */
#define DMA_CCR_MINC_Pos                    (7U)                               
#define DMA_CCR_MINC_Msk                    (0x1UL << DMA_CCR_MINC_Pos)         /*!< 0x00000080 */
#define DMA_CCR_MINC                        DMA_CCR_MINC_Msk                   /*!< Memory increment mode */

#define DMA_CCR_PSIZE_Pos                   (8U)                               
#define DMA_CCR_PSIZE_Msk                   (0x3UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000300 */
#define DMA_CCR_PSIZE                       DMA_CCR_PSIZE_Msk                  /*!< PSIZE[1:0] bits (Peripheral size) */
#define DMA_CCR_PSIZE_0                     (0x1UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000100 */
#define DMA_CCR_PSIZE_1                     (0x2UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000200 */

#define DMA_CCR_MSIZE_Pos                   (10U)                              
#define DMA_CCR_MSIZE_Msk                   (0x3UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000C00 */
#define DMA_CCR_MSIZE                       DMA_CCR_MSIZE_Msk                  /*!< MSIZE[1:0] bits (Memory size) */
#define DMA_CCR_MSIZE_0                     (0x1UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000400 */
#define DMA_CCR_MSIZE_1                     (0x2UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000800 */

#define DMA_CCR_PL_Pos                      (12U)                              
#define DMA_CCR_PL_Msk                      (0x3UL << DMA_CCR_PL_Pos)           /*!< 0x00003000 */
#define DMA_CCR_PL                          DMA_CCR_PL_Msk                     /*!< PL[1:0] bits(Channel Priority level) */
#define DMA_CCR_PL_0                        (0x1UL << DMA_CCR_PL_Pos)           /*!< 0x00001000 */
#define DMA_CCR_PL_1                        (0x2UL << DMA_CCR_PL_Pos)           /*!< 0x00002000 */

#define DMA_CCR_MEM2MEM_Pos                 (14U)                              
#define DMA_CCR_MEM2MEM_Msk                 (0x1UL << DMA_CCR_MEM2MEM_Pos)      /*!< 0x00004000 */
#define DMA_CCR_MEM2MEM                     DMA_CCR_MEM2MEM_Msk                /*!< Memory to memory mode */

/******************  Bit definition for DMA_CNDTR  register  ******************/
#define DMA_CNDTR_NDT_Pos                   (0U)                               
#define DMA_CNDTR_NDT_Msk                   (0xFFFFUL << DMA_CNDTR_NDT_Pos)     /*!< 0x0000FFFF */
#define DMA_CNDTR_NDT                       DMA_CNDTR_NDT_Msk                  /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CPAR  register  *******************/
#define DMA_CPAR_PA_Pos                     (0U)                               
#define DMA_CPAR_PA_Msk                     (0xFFFFFFFFUL << DMA_CPAR_PA_Pos)   /*!< 0xFFFFFFFF */
#define DMA_CPAR_PA                         DMA_CPAR_PA_Msk                    /*!< Peripheral Address */

/******************  Bit definition for DMA_CMAR  register  *******************/
#define DMA_CMAR_MA_Pos                     (0U)                               
#define DMA_CMAR_MA_Msk                     (0xFFFFFFFFUL << DMA_CMAR_MA_Pos)   /*!< 0xFFFFFFFF */
#define DMA_CMAR_MA                         DMA_CMAR_MA_Msk                    /*!< Memory Address */

// 레지스터 목록
namespace DMA_REG
{
enum
{
	ISR = 0, IFCR, CSELR = 42,
	CCR = 0, CNDTR, CPAR, CMAR

};
}

#endif

