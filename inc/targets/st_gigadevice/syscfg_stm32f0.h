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
#ifndef __SYSCFG_STM32F0__H_
#define __SYSCFG_STM32F0__H_

/*****************************************************************************/
/*                                                                           */
/*                       System Configuration (SYSCFG)                       */
/*                                                                           */
/*****************************************************************************/
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3UL << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1UL << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2UL << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */


#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1UL << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1UL << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1UL << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1UL << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1UL << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1UL << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1UL << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

/*****************  Bit definition for SYSCFG_EXTICR1 register  **************/
#define SYSCFG_EXTICR1_EXTI0_Pos             (0U)                              
#define SYSCFG_EXTICR1_EXTI0_Msk             (0xFUL << SYSCFG_EXTICR1_EXTI0_Pos) /*!< 0x0000000F */
#define SYSCFG_EXTICR1_EXTI0                 SYSCFG_EXTICR1_EXTI0_Msk          /*!< EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1_Pos             (4U)                              
#define SYSCFG_EXTICR1_EXTI1_Msk             (0xFUL << SYSCFG_EXTICR1_EXTI1_Pos) /*!< 0x000000F0 */
#define SYSCFG_EXTICR1_EXTI1                 SYSCFG_EXTICR1_EXTI1_Msk          /*!< EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2_Pos             (8U)                              
#define SYSCFG_EXTICR1_EXTI2_Msk             (0xFUL << SYSCFG_EXTICR1_EXTI2_Pos) /*!< 0x00000F00 */
#define SYSCFG_EXTICR1_EXTI2                 SYSCFG_EXTICR1_EXTI2_Msk          /*!< EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3_Pos             (12U)                             
#define SYSCFG_EXTICR1_EXTI3_Msk             (0xFUL << SYSCFG_EXTICR1_EXTI3_Pos) /*!< 0x0000F000 */
#define SYSCFG_EXTICR1_EXTI3                 SYSCFG_EXTICR1_EXTI3_Msk          /*!< EXTI 3 configuration */

/** 
  * @brief  EXTI0 configuration
  */
#define SYSCFG_EXTICR1_EXTI0_PA              (0x00000000U)                     /*!< PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB              (0x00000001U)                     /*!< PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC              (0x00000002U)                     /*!< PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD              (0x00000003U)                     /*!< PD[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PE              (0x00000004U)                     /*!< PE[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PF              (0x00000005U)                     /*!< PF[0] pin */

/** 
  * @brief  EXTI1 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI1_PA              (0x00000000U)                     /*!< PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB              (0x00000010U)                     /*!< PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC              (0x00000020U)                     /*!< PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD              (0x00000030U)                     /*!< PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE              (0x00000040U)                     /*!< PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF              (0x00000050U)                     /*!< PF[1] pin */

/** 
  * @brief  EXTI2 configuration  
  */
#define SYSCFG_EXTICR1_EXTI2_PA              (0x00000000U)                     /*!< PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB              (0x00000100U)                     /*!< PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC              (0x00000200U)                     /*!< PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD              (0x00000300U)                     /*!< PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE              (0x00000400U)                     /*!< PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF              (0x00000500U)                     /*!< PF[2] pin */

/** 
  * @brief  EXTI3 configuration  
  */
#define SYSCFG_EXTICR1_EXTI3_PA              (0x00000000U)                     /*!< PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB              (0x00001000U)                     /*!< PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC              (0x00002000U)                     /*!< PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD              (0x00003000U)                     /*!< PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE              (0x00004000U)                     /*!< PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PF              (0x00005000U)                     /*!< PF[3] pin */

/*****************  Bit definition for SYSCFG_EXTICR2 register  **************/
#define SYSCFG_EXTICR2_EXTI4_Pos             (0U)                              
#define SYSCFG_EXTICR2_EXTI4_Msk             (0xFUL << SYSCFG_EXTICR2_EXTI4_Pos) /*!< 0x0000000F */
#define SYSCFG_EXTICR2_EXTI4                 SYSCFG_EXTICR2_EXTI4_Msk          /*!< EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5_Pos             (4U)                              
#define SYSCFG_EXTICR2_EXTI5_Msk             (0xFUL << SYSCFG_EXTICR2_EXTI5_Pos) /*!< 0x000000F0 */
#define SYSCFG_EXTICR2_EXTI5                 SYSCFG_EXTICR2_EXTI5_Msk          /*!< EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6_Pos             (8U)                              
#define SYSCFG_EXTICR2_EXTI6_Msk             (0xFUL << SYSCFG_EXTICR2_EXTI6_Pos) /*!< 0x00000F00 */
#define SYSCFG_EXTICR2_EXTI6                 SYSCFG_EXTICR2_EXTI6_Msk          /*!< EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7_Pos             (12U)                             
#define SYSCFG_EXTICR2_EXTI7_Msk             (0xFUL << SYSCFG_EXTICR2_EXTI7_Pos) /*!< 0x0000F000 */
#define SYSCFG_EXTICR2_EXTI7                 SYSCFG_EXTICR2_EXTI7_Msk          /*!< EXTI 7 configuration */

/** 
  * @brief  EXTI4 configuration  
  */
#define SYSCFG_EXTICR2_EXTI4_PA              (0x00000000U)                     /*!< PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB              (0x00000001U)                     /*!< PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC              (0x00000002U)                     /*!< PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD              (0x00000003U)                     /*!< PD[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PE              (0x00000004U)                     /*!< PE[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PF              (0x00000005U)                     /*!< PF[4] pin */

/** 
  * @brief  EXTI5 configuration  
  */
#define SYSCFG_EXTICR2_EXTI5_PA              (0x00000000U)                     /*!< PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB              (0x00000010U)                     /*!< PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC              (0x00000020U)                     /*!< PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD              (0x00000030U)                     /*!< PD[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PE              (0x00000040U)                     /*!< PE[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PF              (0x00000050U)                     /*!< PF[5] pin */

/** 
  * @brief  EXTI6 configuration  
  */
#define SYSCFG_EXTICR2_EXTI6_PA              (0x00000000U)                     /*!< PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB              (0x00000100U)                     /*!< PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC              (0x00000200U)                     /*!< PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD              (0x00000300U)                     /*!< PD[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PE              (0x00000400U)                     /*!< PE[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PF              (0x00000500U)                     /*!< PF[6] pin */

/** 
  * @brief  EXTI7 configuration  
  */
#define SYSCFG_EXTICR2_EXTI7_PA              (0x00000000U)                     /*!< PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB              (0x00001000U)                     /*!< PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC              (0x00002000U)                     /*!< PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD              (0x00003000U)                     /*!< PD[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PE              (0x00004000U)                     /*!< PE[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PF              (0x00005000U)                     /*!< PF[7] pin */

/*****************  Bit definition for SYSCFG_EXTICR3 register  **************/
#define SYSCFG_EXTICR3_EXTI8_Pos             (0U)                              
#define SYSCFG_EXTICR3_EXTI8_Msk             (0xFUL << SYSCFG_EXTICR3_EXTI8_Pos) /*!< 0x0000000F */
#define SYSCFG_EXTICR3_EXTI8                 SYSCFG_EXTICR3_EXTI8_Msk          /*!< EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9_Pos             (4U)                              
#define SYSCFG_EXTICR3_EXTI9_Msk             (0xFUL << SYSCFG_EXTICR3_EXTI9_Pos) /*!< 0x000000F0 */
#define SYSCFG_EXTICR3_EXTI9                 SYSCFG_EXTICR3_EXTI9_Msk          /*!< EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10_Pos            (8U)                              
#define SYSCFG_EXTICR3_EXTI10_Msk            (0xFUL << SYSCFG_EXTICR3_EXTI10_Pos) /*!< 0x00000F00 */
#define SYSCFG_EXTICR3_EXTI10                SYSCFG_EXTICR3_EXTI10_Msk         /*!< EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11_Pos            (12U)                             
#define SYSCFG_EXTICR3_EXTI11_Msk            (0xFUL << SYSCFG_EXTICR3_EXTI11_Pos) /*!< 0x0000F000 */
#define SYSCFG_EXTICR3_EXTI11                SYSCFG_EXTICR3_EXTI11_Msk         /*!< EXTI 11 configuration */

/** 
  * @brief  EXTI8 configuration  
  */
#define SYSCFG_EXTICR3_EXTI8_PA              (0x00000000U)                     /*!< PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB              (0x00000001U)                     /*!< PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC              (0x00000002U)                     /*!< PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD              (0x00000003U)                     /*!< PD[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PE              (0x00000004U)                     /*!< PE[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PF              (0x00000005U)                     /*!< PF[8] pin */


/** 
  * @brief  EXTI9 configuration  
  */
#define SYSCFG_EXTICR3_EXTI9_PA              (0x00000000U)                     /*!< PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB              (0x00000010U)                     /*!< PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC              (0x00000020U)                     /*!< PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD              (0x00000030U)                     /*!< PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE              (0x00000040U)                     /*!< PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF              (0x00000050U)                     /*!< PF[9] pin */

/** 
  * @brief  EXTI10 configuration  
  */
#define SYSCFG_EXTICR3_EXTI10_PA             (0x00000000U)                     /*!< PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB             (0x00000100U)                     /*!< PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC             (0x00000200U)                     /*!< PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD             (0x00000300U)                     /*!< PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE             (0x00000400U)                     /*!< PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF             (0x00000500U)                     /*!< PF[10] pin */

/** 
  * @brief  EXTI11 configuration  
  */
#define SYSCFG_EXTICR3_EXTI11_PA             (0x00000000U)                     /*!< PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB             (0x00001000U)                     /*!< PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC             (0x00002000U)                     /*!< PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD             (0x00003000U)                     /*!< PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE             (0x00004000U)                     /*!< PE[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PF             (0x00005000U)                     /*!< PF[11] pin */

/*****************  Bit definition for SYSCFG_EXTICR4 register  **************/
#define SYSCFG_EXTICR4_EXTI12_Pos            (0U)                              
#define SYSCFG_EXTICR4_EXTI12_Msk            (0xFUL << SYSCFG_EXTICR4_EXTI12_Pos) /*!< 0x0000000F */
#define SYSCFG_EXTICR4_EXTI12                SYSCFG_EXTICR4_EXTI12_Msk         /*!< EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13_Pos            (4U)                              
#define SYSCFG_EXTICR4_EXTI13_Msk            (0xFUL << SYSCFG_EXTICR4_EXTI13_Pos) /*!< 0x000000F0 */
#define SYSCFG_EXTICR4_EXTI13                SYSCFG_EXTICR4_EXTI13_Msk         /*!< EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14_Pos            (8U)                              
#define SYSCFG_EXTICR4_EXTI14_Msk            (0xFUL << SYSCFG_EXTICR4_EXTI14_Pos) /*!< 0x00000F00 */
#define SYSCFG_EXTICR4_EXTI14                SYSCFG_EXTICR4_EXTI14_Msk         /*!< EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15_Pos            (12U)                             
#define SYSCFG_EXTICR4_EXTI15_Msk            (0xFUL << SYSCFG_EXTICR4_EXTI15_Pos) /*!< 0x0000F000 */
#define SYSCFG_EXTICR4_EXTI15                SYSCFG_EXTICR4_EXTI15_Msk         /*!< EXTI 15 configuration */

/** 
  * @brief  EXTI12 configuration  
  */
#define SYSCFG_EXTICR4_EXTI12_PA             (0x00000000U)                     /*!< PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB             (0x00000001U)                     /*!< PB[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PC             (0x00000002U)                     /*!< PC[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PD             (0x00000003U)                     /*!< PD[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PE             (0x00000004U)                     /*!< PE[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PF             (0x00000005U)                     /*!< PF[12] pin */

/** 
  * @brief  EXTI13 configuration  
  */
#define SYSCFG_EXTICR4_EXTI13_PA             (0x00000000U)                     /*!< PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB             (0x00000010U)                     /*!< PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC             (0x00000020U)                     /*!< PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD             (0x00000030U)                     /*!< PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE             (0x00000040U)                     /*!< PE[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PF             (0x00000050U)                     /*!< PF[13] pin */

/** 
  * @brief  EXTI14 configuration  
  */
#define SYSCFG_EXTICR4_EXTI14_PA             (0x00000000U)                     /*!< PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB             (0x00000100U)                     /*!< PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC             (0x00000200U)                     /*!< PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD             (0x00000300U)                     /*!< PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE             (0x00000400U)                     /*!< PE[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PF             (0x00000500U)                     /*!< PF[14] pin */

/** 
  * @brief  EXTI15 configuration  
  */
#define SYSCFG_EXTICR4_EXTI15_PA             (0x00000000U)                     /*!< PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB             (0x00001000U)                     /*!< PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC             (0x00002000U)                     /*!< PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD             (0x00003000U)                     /*!< PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE             (0x00004000U)                     /*!< PE[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PF             (0x00005000U)                     /*!< PF[15] pin */

/*****************  Bit definition for SYSCFG_CFGR2 register  ****************/
#define SYSCFG_CFGR2_LOCKUP_LOCK_Pos         (0U)                              
#define SYSCFG_CFGR2_LOCKUP_LOCK_Msk         (0x1UL << SYSCFG_CFGR2_LOCKUP_LOCK_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR2_LOCKUP_LOCK             SYSCFG_CFGR2_LOCKUP_LOCK_Msk      /*!< Enables and locks the LOCKUP (Hardfault) output of CortexM0 with Break Input of TIMER1 */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK_Pos    (1U)                              
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK_Msk    (0x1UL << SYSCFG_CFGR2_SRAM_PARITY_LOCK_Pos) /*!< 0x00000002 */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK        SYSCFG_CFGR2_SRAM_PARITY_LOCK_Msk /*!< Enables and locks the SRAM_PARITY error signal with Break Input of TIMER1 */
#define SYSCFG_CFGR2_SRAM_PEF_Pos            (8U)                              
#define SYSCFG_CFGR2_SRAM_PEF_Msk            (0x1UL << SYSCFG_CFGR2_SRAM_PEF_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR2_SRAM_PEF                SYSCFG_CFGR2_SRAM_PEF_Msk         /*!< SRAM Parity error flag */
#define SYSCFG_CFGR2_SRAM_PE                 SYSCFG_CFGR2_SRAM_PEF  /*!< SRAM Parity error flag (define maintained for legacy purpose) */

// 레지스터 목록
namespace SYSCFG_REG
{
enum
{
	CFGR1 = 0,						EXTICR0 = 2,	EXTICR1,		EXTICR2,
	EXTICR3,		CFGR2
};
}

#endif

