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
#ifndef __DAC_STM32_GD32F1__H_
#define __DAC_STM32_GD32F1__H_

/******************************************************************************/
/*                                                                            */
/*                      Digital to Analog Converter                           */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for DAC_CR register  ********************/
#define DAC_CR_EN1_Pos                      (0U)                               
#define DAC_CR_EN1_Msk                      (0x1UL << DAC_CR_EN1_Pos)           /*!< 0x00000001 */
#define DAC_CR_EN1                          DAC_CR_EN1_Msk                     /*!< DAC channel1 enable */
#define DAC_CR_BOFF1_Pos                    (1U)                               
#define DAC_CR_BOFF1_Msk                    (0x1UL << DAC_CR_BOFF1_Pos)         /*!< 0x00000002 */
#define DAC_CR_BOFF1                        DAC_CR_BOFF1_Msk                   /*!< DAC channel1 output buffer disable */
#define DAC_CR_TEN1_Pos                     (2U)                               
#define DAC_CR_TEN1_Msk                     (0x1UL << DAC_CR_TEN1_Pos)          /*!< 0x00000004 */
#define DAC_CR_TEN1                         DAC_CR_TEN1_Msk                    /*!< DAC channel1 Trigger enable */

#define DAC_CR_TSEL1_Pos                    (3U)                               
#define DAC_CR_TSEL1_Msk                    (0x7UL << DAC_CR_TSEL1_Pos)         /*!< 0x00000038 */
#define DAC_CR_TSEL1                        DAC_CR_TSEL1_Msk                   /*!< TSEL1[2:0] (DAC channel1 Trigger selection) */
#define DAC_CR_TSEL1_0                      (0x1UL << DAC_CR_TSEL1_Pos)         /*!< 0x00000008 */
#define DAC_CR_TSEL1_1                      (0x2UL << DAC_CR_TSEL1_Pos)         /*!< 0x00000010 */
#define DAC_CR_TSEL1_2                      (0x4UL << DAC_CR_TSEL1_Pos)         /*!< 0x00000020 */

#define DAC_CR_WAVE1_Pos                    (6U)                               
#define DAC_CR_WAVE1_Msk                    (0x3UL << DAC_CR_WAVE1_Pos)         /*!< 0x000000C0 */
#define DAC_CR_WAVE1                        DAC_CR_WAVE1_Msk                   /*!< WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
#define DAC_CR_WAVE1_0                      (0x1UL << DAC_CR_WAVE1_Pos)         /*!< 0x00000040 */
#define DAC_CR_WAVE1_1                      (0x2UL << DAC_CR_WAVE1_Pos)         /*!< 0x00000080 */

#define DAC_CR_MAMP1_Pos                    (8U)                               
#define DAC_CR_MAMP1_Msk                    (0xFUL << DAC_CR_MAMP1_Pos)         /*!< 0x00000F00 */
#define DAC_CR_MAMP1                        DAC_CR_MAMP1_Msk                   /*!< MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
#define DAC_CR_MAMP1_0                      (0x1UL << DAC_CR_MAMP1_Pos)         /*!< 0x00000100 */
#define DAC_CR_MAMP1_1                      (0x2UL << DAC_CR_MAMP1_Pos)         /*!< 0x00000200 */
#define DAC_CR_MAMP1_2                      (0x4UL << DAC_CR_MAMP1_Pos)         /*!< 0x00000400 */
#define DAC_CR_MAMP1_3                      (0x8UL << DAC_CR_MAMP1_Pos)         /*!< 0x00000800 */

#define DAC_CR_DMAEN1_Pos                   (12U)                              
#define DAC_CR_DMAEN1_Msk                   (0x1UL << DAC_CR_DMAEN1_Pos)        /*!< 0x00001000 */
#define DAC_CR_DMAEN1                       DAC_CR_DMAEN1_Msk                  /*!< DAC channel1 DMA enable */
#define DAC_CR_EN2_Pos                      (16U)                              
#define DAC_CR_EN2_Msk                      (0x1UL << DAC_CR_EN2_Pos)           /*!< 0x00010000 */
#define DAC_CR_EN2                          DAC_CR_EN2_Msk                     /*!< DAC channel2 enable */
#define DAC_CR_BOFF2_Pos                    (17U)                              
#define DAC_CR_BOFF2_Msk                    (0x1UL << DAC_CR_BOFF2_Pos)         /*!< 0x00020000 */
#define DAC_CR_BOFF2                        DAC_CR_BOFF2_Msk                   /*!< DAC channel2 output buffer disable */
#define DAC_CR_TEN2_Pos                     (18U)                              
#define DAC_CR_TEN2_Msk                     (0x1UL << DAC_CR_TEN2_Pos)          /*!< 0x00040000 */
#define DAC_CR_TEN2                         DAC_CR_TEN2_Msk                    /*!< DAC channel2 Trigger enable */

#define DAC_CR_TSEL2_Pos                    (19U)                              
#define DAC_CR_TSEL2_Msk                    (0x7UL << DAC_CR_TSEL2_Pos)         /*!< 0x00380000 */
#define DAC_CR_TSEL2                        DAC_CR_TSEL2_Msk                   /*!< TSEL2[2:0] (DAC channel2 Trigger selection) */
#define DAC_CR_TSEL2_0                      (0x1UL << DAC_CR_TSEL2_Pos)         /*!< 0x00080000 */
#define DAC_CR_TSEL2_1                      (0x2UL << DAC_CR_TSEL2_Pos)         /*!< 0x00100000 */
#define DAC_CR_TSEL2_2                      (0x4UL << DAC_CR_TSEL2_Pos)         /*!< 0x00200000 */

#define DAC_CR_WAVE2_Pos                    (22U)                              
#define DAC_CR_WAVE2_Msk                    (0x3UL << DAC_CR_WAVE2_Pos)         /*!< 0x00C00000 */
#define DAC_CR_WAVE2                        DAC_CR_WAVE2_Msk                   /*!< WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define DAC_CR_WAVE2_0                      (0x1UL << DAC_CR_WAVE2_Pos)         /*!< 0x00400000 */
#define DAC_CR_WAVE2_1                      (0x2UL << DAC_CR_WAVE2_Pos)         /*!< 0x00800000 */

#define DAC_CR_MAMP2_Pos                    (24U)                              
#define DAC_CR_MAMP2_Msk                    (0xFUL << DAC_CR_MAMP2_Pos)         /*!< 0x0F000000 */
#define DAC_CR_MAMP2                        DAC_CR_MAMP2_Msk                   /*!< MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define DAC_CR_MAMP2_0                      (0x1UL << DAC_CR_MAMP2_Pos)         /*!< 0x01000000 */
#define DAC_CR_MAMP2_1                      (0x2UL << DAC_CR_MAMP2_Pos)         /*!< 0x02000000 */
#define DAC_CR_MAMP2_2                      (0x4UL << DAC_CR_MAMP2_Pos)         /*!< 0x04000000 */
#define DAC_CR_MAMP2_3                      (0x8UL << DAC_CR_MAMP2_Pos)         /*!< 0x08000000 */

#define DAC_CR_DMAEN2_Pos                   (28U)                              
#define DAC_CR_DMAEN2_Msk                   (0x1UL << DAC_CR_DMAEN2_Pos)        /*!< 0x10000000 */
#define DAC_CR_DMAEN2                       DAC_CR_DMAEN2_Msk                  /*!< DAC channel2 DMA enabled */


/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define DAC_SWTRIGR_SWTRIG1_Pos             (0U)                               
#define DAC_SWTRIGR_SWTRIG1_Msk             (0x1UL << DAC_SWTRIGR_SWTRIG1_Pos)  /*!< 0x00000001 */
#define DAC_SWTRIGR_SWTRIG1                 DAC_SWTRIGR_SWTRIG1_Msk            /*!< DAC channel1 software trigger */
#define DAC_SWTRIGR_SWTRIG2_Pos             (1U)                               
#define DAC_SWTRIGR_SWTRIG2_Msk             (0x1UL << DAC_SWTRIGR_SWTRIG2_Pos)  /*!< 0x00000002 */
#define DAC_SWTRIGR_SWTRIG2                 DAC_SWTRIGR_SWTRIG2_Msk            /*!< DAC channel2 software trigger */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define DAC_DHR12R1_DACC1DHR_Pos            (0U)                               
#define DAC_DHR12R1_DACC1DHR_Msk            (0xFFFUL << DAC_DHR12R1_DACC1DHR_Pos) /*!< 0x00000FFF */
#define DAC_DHR12R1_DACC1DHR                DAC_DHR12R1_DACC1DHR_Msk           /*!< DAC channel1 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define DAC_DHR12L1_DACC1DHR_Pos            (4U)                               
#define DAC_DHR12L1_DACC1DHR_Msk            (0xFFFUL << DAC_DHR12L1_DACC1DHR_Pos) /*!< 0x0000FFF0 */
#define DAC_DHR12L1_DACC1DHR                DAC_DHR12L1_DACC1DHR_Msk           /*!< DAC channel1 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define DAC_DHR8R1_DACC1DHR_Pos             (0U)                               
#define DAC_DHR8R1_DACC1DHR_Msk             (0xFFUL << DAC_DHR8R1_DACC1DHR_Pos) /*!< 0x000000FF */
#define DAC_DHR8R1_DACC1DHR                 DAC_DHR8R1_DACC1DHR_Msk            /*!< DAC channel1 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define DAC_DHR12R2_DACC2DHR_Pos            (0U)                               
#define DAC_DHR12R2_DACC2DHR_Msk            (0xFFFUL << DAC_DHR12R2_DACC2DHR_Pos) /*!< 0x00000FFF */
#define DAC_DHR12R2_DACC2DHR                DAC_DHR12R2_DACC2DHR_Msk           /*!< DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define DAC_DHR12L2_DACC2DHR_Pos            (4U)                               
#define DAC_DHR12L2_DACC2DHR_Msk            (0xFFFUL << DAC_DHR12L2_DACC2DHR_Pos) /*!< 0x0000FFF0 */
#define DAC_DHR12L2_DACC2DHR                DAC_DHR12L2_DACC2DHR_Msk           /*!< DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define DAC_DHR8R2_DACC2DHR_Pos             (0U)                               
#define DAC_DHR8R2_DACC2DHR_Msk             (0xFFUL << DAC_DHR8R2_DACC2DHR_Pos) /*!< 0x000000FF */
#define DAC_DHR8R2_DACC2DHR                 DAC_DHR8R2_DACC2DHR_Msk            /*!< DAC channel2 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define DAC_DHR12RD_DACC1DHR_Pos            (0U)                               
#define DAC_DHR12RD_DACC1DHR_Msk            (0xFFFUL << DAC_DHR12RD_DACC1DHR_Pos) /*!< 0x00000FFF */
#define DAC_DHR12RD_DACC1DHR                DAC_DHR12RD_DACC1DHR_Msk           /*!< DAC channel1 12-bit Right aligned data */
#define DAC_DHR12RD_DACC2DHR_Pos            (16U)                              
#define DAC_DHR12RD_DACC2DHR_Msk            (0xFFFUL << DAC_DHR12RD_DACC2DHR_Pos) /*!< 0x0FFF0000 */
#define DAC_DHR12RD_DACC2DHR                DAC_DHR12RD_DACC2DHR_Msk           /*!< DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define DAC_DHR12LD_DACC1DHR_Pos            (4U)                               
#define DAC_DHR12LD_DACC1DHR_Msk            (0xFFFUL << DAC_DHR12LD_DACC1DHR_Pos) /*!< 0x0000FFF0 */
#define DAC_DHR12LD_DACC1DHR                DAC_DHR12LD_DACC1DHR_Msk           /*!< DAC channel1 12-bit Left aligned data */
#define DAC_DHR12LD_DACC2DHR_Pos            (20U)                              
#define DAC_DHR12LD_DACC2DHR_Msk            (0xFFFUL << DAC_DHR12LD_DACC2DHR_Pos) /*!< 0xFFF00000 */
#define DAC_DHR12LD_DACC2DHR                DAC_DHR12LD_DACC2DHR_Msk           /*!< DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8RD register  ******************/
#define DAC_DHR8RD_DACC1DHR_Pos             (0U)                               
#define DAC_DHR8RD_DACC1DHR_Msk             (0xFFUL << DAC_DHR8RD_DACC1DHR_Pos) /*!< 0x000000FF */
#define DAC_DHR8RD_DACC1DHR                 DAC_DHR8RD_DACC1DHR_Msk            /*!< DAC channel1 8-bit Right aligned data */
#define DAC_DHR8RD_DACC2DHR_Pos             (8U)                               
#define DAC_DHR8RD_DACC2DHR_Msk             (0xFFUL << DAC_DHR8RD_DACC2DHR_Pos) /*!< 0x0000FF00 */
#define DAC_DHR8RD_DACC2DHR                 DAC_DHR8RD_DACC2DHR_Msk            /*!< DAC channel2 8-bit Right aligned data */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define DAC_DOR1_DACC1DOR_Pos               (0U)                               
#define DAC_DOR1_DACC1DOR_Msk               (0xFFFUL << DAC_DOR1_DACC1DOR_Pos)  /*!< 0x00000FFF */
#define DAC_DOR1_DACC1DOR                   DAC_DOR1_DACC1DOR_Msk              /*!< DAC channel1 data output */

/*******************  Bit definition for DAC_DOR2 register  *******************/
#define DAC_DOR2_DACC2DOR_Pos               (0U)                               
#define DAC_DOR2_DACC2DOR_Msk               (0xFFFUL << DAC_DOR2_DACC2DOR_Pos)  /*!< 0x00000FFF */
#define DAC_DOR2_DACC2DOR                   DAC_DOR2_DACC2DOR_Msk              /*!< DAC channel2 data output */

// 레지스터 목록
namespace DAC_REG
{
enum
{
	CR = 0, SWTRIGR, DHR12R1, DHR12L1,
	DHR8R1, DHR12R2, DHR12L2, DHR8R2,
	DHR12RD, DHR12LD, DHR8RD, DOR1,
	DOR2
};
}

#endif

