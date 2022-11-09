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
#ifndef __SYSCFG_STM32F7__H_
#define __SYSCFG_STM32F7__H_

/******************************************************************************/
/*                                                                            */
/*                                 SYSCFG                                     */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SYSCFG_MEMRMP register  ***************/
#define SYSCFG_MEMRMP_MEM_BOOT_Pos      (0U)
#define SYSCFG_MEMRMP_MEM_BOOT_Msk      (0x1UL << SYSCFG_MEMRMP_MEM_BOOT_Pos)   /*!< 0x00000001 */
#define SYSCFG_MEMRMP_MEM_BOOT          SYSCFG_MEMRMP_MEM_BOOT_Msk             /*!< Boot information after Reset */


#define SYSCFG_MEMRMP_SWP_FMC_Pos       (10U)
#define SYSCFG_MEMRMP_SWP_FMC_Msk       (0x3UL << SYSCFG_MEMRMP_SWP_FMC_Pos)    /*!< 0x00000C00 */
#define SYSCFG_MEMRMP_SWP_FMC           SYSCFG_MEMRMP_SWP_FMC_Msk              /*!< FMC Memory Mapping swapping */
#define SYSCFG_MEMRMP_SWP_FMC_0         (0x1UL << SYSCFG_MEMRMP_SWP_FMC_Pos)    /*!< 0x00000400 */
#define SYSCFG_MEMRMP_SWP_FMC_1         (0x2UL << SYSCFG_MEMRMP_SWP_FMC_Pos)    /*!< 0x00000800 */

/******************  Bit definition for SYSCFG_PMC register  ******************/
#define SYSCFG_PMC_I2C1_FMP_Pos         (0U)
#define SYSCFG_PMC_I2C1_FMP_Msk         (0x1UL << SYSCFG_PMC_I2C1_FMP_Pos)      /*!< 0x00000001 */
#define SYSCFG_PMC_I2C1_FMP             SYSCFG_PMC_I2C1_FMP_Msk                /*!< I2C1_FMP I2C1 Fast Mode + Enable */
#define SYSCFG_PMC_I2C2_FMP_Pos         (1U)
#define SYSCFG_PMC_I2C2_FMP_Msk         (0x1UL << SYSCFG_PMC_I2C2_FMP_Pos)      /*!< 0x00000002 */
#define SYSCFG_PMC_I2C2_FMP             SYSCFG_PMC_I2C2_FMP_Msk                /*!< I2C2_FMP I2C2 Fast Mode + Enable */
#define SYSCFG_PMC_I2C3_FMP_Pos         (2U)
#define SYSCFG_PMC_I2C3_FMP_Msk         (0x1UL << SYSCFG_PMC_I2C3_FMP_Pos)      /*!< 0x00000004 */
#define SYSCFG_PMC_I2C3_FMP             SYSCFG_PMC_I2C3_FMP_Msk                /*!< I2C3_FMP I2C3 Fast Mode + Enable */
#define SYSCFG_PMC_I2C4_FMP_Pos         (3U)
#define SYSCFG_PMC_I2C4_FMP_Msk         (0x1UL << SYSCFG_PMC_I2C4_FMP_Pos)      /*!< 0x00000008 */
#define SYSCFG_PMC_I2C4_FMP             SYSCFG_PMC_I2C4_FMP_Msk                /*!< I2C4_FMP I2C4 Fast Mode + Enable */
#define SYSCFG_PMC_I2C_PB6_FMP_Pos      (4U)
#define SYSCFG_PMC_I2C_PB6_FMP_Msk      (0x1UL << SYSCFG_PMC_I2C_PB6_FMP_Pos)   /*!< 0x00000010 */
#define SYSCFG_PMC_I2C_PB6_FMP          SYSCFG_PMC_I2C_PB6_FMP_Msk             /*!< PB6_FMP Fast Mode + Enable */
#define SYSCFG_PMC_I2C_PB7_FMP_Pos      (5U)
#define SYSCFG_PMC_I2C_PB7_FMP_Msk      (0x1UL << SYSCFG_PMC_I2C_PB7_FMP_Pos)   /*!< 0x00000020 */
#define SYSCFG_PMC_I2C_PB7_FMP          SYSCFG_PMC_I2C_PB7_FMP_Msk             /*!< PB7_FMP Fast Mode + Enable */
#define SYSCFG_PMC_I2C_PB8_FMP_Pos      (6U)
#define SYSCFG_PMC_I2C_PB8_FMP_Msk      (0x1UL << SYSCFG_PMC_I2C_PB8_FMP_Pos)   /*!< 0x00000040 */
#define SYSCFG_PMC_I2C_PB8_FMP          SYSCFG_PMC_I2C_PB8_FMP_Msk             /*!< PB8_FMP Fast Mode + Enable */
#define SYSCFG_PMC_I2C_PB9_FMP_Pos      (7U)
#define SYSCFG_PMC_I2C_PB9_FMP_Msk      (0x1UL << SYSCFG_PMC_I2C_PB9_FMP_Pos)   /*!< 0x00000080 */
#define SYSCFG_PMC_I2C_PB9_FMP          SYSCFG_PMC_I2C_PB9_FMP_Msk             /*!< PB9_FMP Fast Mode + Enable */

#define SYSCFG_PMC_ADCxDC2_Pos          (16U)
#define SYSCFG_PMC_ADCxDC2_Msk          (0x7UL << SYSCFG_PMC_ADCxDC2_Pos)       /*!< 0x00070000 */
#define SYSCFG_PMC_ADCxDC2              SYSCFG_PMC_ADCxDC2_Msk                 /*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC1DC2_Pos          (16U)
#define SYSCFG_PMC_ADC1DC2_Msk          (0x1UL << SYSCFG_PMC_ADC1DC2_Pos)       /*!< 0x00010000 */
#define SYSCFG_PMC_ADC1DC2              SYSCFG_PMC_ADC1DC2_Msk                 /*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC2DC2_Pos          (17U)
#define SYSCFG_PMC_ADC2DC2_Msk          (0x1UL << SYSCFG_PMC_ADC2DC2_Pos)       /*!< 0x00020000 */
#define SYSCFG_PMC_ADC2DC2              SYSCFG_PMC_ADC2DC2_Msk                 /*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC3DC2_Pos          (18U)
#define SYSCFG_PMC_ADC3DC2_Msk          (0x1UL << SYSCFG_PMC_ADC3DC2_Pos)       /*!< 0x00040000 */
#define SYSCFG_PMC_ADC3DC2              SYSCFG_PMC_ADC3DC2_Msk                 /*!< Refer to AN4073 on how to use this bit  */

#define SYSCFG_PMC_MII_RMII_SEL_Pos     (23U)
#define SYSCFG_PMC_MII_RMII_SEL_Msk     (0x1UL << SYSCFG_PMC_MII_RMII_SEL_Pos)  /*!< 0x00800000 */
#define SYSCFG_PMC_MII_RMII_SEL         SYSCFG_PMC_MII_RMII_SEL_Msk            /*!<Ethernet PHY interface selection */

/*****************  Bit definition for SYSCFG_EXTICR1 register  ***************/
#define SYSCFG_EXTICR1_EXTI0_Pos        (0U)
#define SYSCFG_EXTICR1_EXTI0_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI0_Pos)     /*!< 0x0000000F */
#define SYSCFG_EXTICR1_EXTI0            SYSCFG_EXTICR1_EXTI0_Msk               /*!<EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1_Pos        (4U)
#define SYSCFG_EXTICR1_EXTI1_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI1_Pos)     /*!< 0x000000F0 */
#define SYSCFG_EXTICR1_EXTI1            SYSCFG_EXTICR1_EXTI1_Msk               /*!<EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2_Pos        (8U)
#define SYSCFG_EXTICR1_EXTI2_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI2_Pos)     /*!< 0x00000F00 */
#define SYSCFG_EXTICR1_EXTI2            SYSCFG_EXTICR1_EXTI2_Msk               /*!<EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3_Pos        (12U)
#define SYSCFG_EXTICR1_EXTI3_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI3_Pos)     /*!< 0x0000F000 */
#define SYSCFG_EXTICR1_EXTI3            SYSCFG_EXTICR1_EXTI3_Msk               /*!<EXTI 3 configuration */
/**
  * @brief   EXTI0 configuration
  */
#define SYSCFG_EXTICR1_EXTI0_PA         0x0000U                                /*!<PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB         0x0001U                                /*!<PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC         0x0002U                                /*!<PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD         0x0003U                                /*!<PD[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PE         0x0004U                                /*!<PE[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PF         0x0005U                                /*!<PF[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PG         0x0006U                                /*!<PG[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PH         0x0007U                                /*!<PH[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PI         0x0008U                                /*!<PI[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PJ         0x0009U                                /*!<PJ[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PK         0x000AU                                /*!<PK[0] pin */

/**
  * @brief   EXTI1 configuration
  */
#define SYSCFG_EXTICR1_EXTI1_PA         0x0000U                                /*!<PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB         0x0010U                                /*!<PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC         0x0020U                                /*!<PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD         0x0030U                                /*!<PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE         0x0040U                                /*!<PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF         0x0050U                                /*!<PF[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PG         0x0060U                                /*!<PG[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PH         0x0070U                                /*!<PH[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PI         0x0080U                                /*!<PI[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PJ         0x0090U                                /*!<PJ[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PK         0x00A0U                                /*!<PK[1] pin */

/**
  * @brief   EXTI2 configuration
  */
#define SYSCFG_EXTICR1_EXTI2_PA         0x0000U                                /*!<PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB         0x0100U                                /*!<PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC         0x0200U                                /*!<PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD         0x0300U                                /*!<PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE         0x0400U                                /*!<PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF         0x0500U                                /*!<PF[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PG         0x0600U                                /*!<PG[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PH         0x0700U                                /*!<PH[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PI         0x0800U                                /*!<PI[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PJ         0x0900U                                /*!<PJ[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PK         0x0A00U                                /*!<PK[2] pin */

/**
  * @brief   EXTI3 configuration
  */
#define SYSCFG_EXTICR1_EXTI3_PA         0x0000U                                /*!<PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB         0x1000U                                /*!<PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC         0x2000U                                /*!<PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD         0x3000U                                /*!<PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE         0x4000U                                /*!<PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PF         0x5000U                                /*!<PF[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PG         0x6000U                                /*!<PG[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PH         0x7000U                                /*!<PH[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PI         0x8000U                                /*!<PI[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PJ         0x9000U                                /*!<PJ[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PK         0xA000U                                /*!<PK[3] pin */

/*****************  Bit definition for SYSCFG_EXTICR2 register  ***************/
#define SYSCFG_EXTICR2_EXTI4_Pos        (0U)
#define SYSCFG_EXTICR2_EXTI4_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI4_Pos)     /*!< 0x0000000F */
#define SYSCFG_EXTICR2_EXTI4            SYSCFG_EXTICR2_EXTI4_Msk               /*!<EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5_Pos        (4U)
#define SYSCFG_EXTICR2_EXTI5_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI5_Pos)     /*!< 0x000000F0 */
#define SYSCFG_EXTICR2_EXTI5            SYSCFG_EXTICR2_EXTI5_Msk               /*!<EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6_Pos        (8U)
#define SYSCFG_EXTICR2_EXTI6_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI6_Pos)     /*!< 0x00000F00 */
#define SYSCFG_EXTICR2_EXTI6            SYSCFG_EXTICR2_EXTI6_Msk               /*!<EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7_Pos        (12U)
#define SYSCFG_EXTICR2_EXTI7_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI7_Pos)     /*!< 0x0000F000 */
#define SYSCFG_EXTICR2_EXTI7            SYSCFG_EXTICR2_EXTI7_Msk               /*!<EXTI 7 configuration */
/**
  * @brief   EXTI4 configuration
  */
#define SYSCFG_EXTICR2_EXTI4_PA         0x0000U                                /*!<PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB         0x0001U                                /*!<PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC         0x0002U                                /*!<PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD         0x0003U                                /*!<PD[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PE         0x0004U                                /*!<PE[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PF         0x0005U                                /*!<PF[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PG         0x0006U                                /*!<PG[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PH         0x0007U                                /*!<PH[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PI         0x0008U                                /*!<PI[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PJ         0x0009U                                /*!<PJ[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PK         0x000AU                                /*!<PK[4] pin */

/**
  * @brief   EXTI5 configuration
  */
#define SYSCFG_EXTICR2_EXTI5_PA         0x0000U                                /*!<PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB         0x0010U                                /*!<PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC         0x0020U                                /*!<PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD         0x0030U                                /*!<PD[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PE         0x0040U                                /*!<PE[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PF         0x0050U                                /*!<PF[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PG         0x0060U                                /*!<PG[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PH         0x0070U                                /*!<PH[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PI         0x0080U                                /*!<PI[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PJ         0x0090U                                /*!<PJ[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PK         0x00A0U                                /*!<PK[5] pin */

/**
  * @brief   EXTI6 configuration
  */
#define SYSCFG_EXTICR2_EXTI6_PA         0x0000U                                /*!<PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB         0x0100U                                /*!<PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC         0x0200U                                /*!<PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD         0x0300U                                /*!<PD[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PE         0x0400U                                /*!<PE[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PF         0x0500U                                /*!<PF[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PG         0x0600U                                /*!<PG[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PH         0x0700U                                /*!<PH[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PI         0x0800U                                /*!<PI[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PJ         0x0900U                                /*!<PJ[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PK         0x0A00U                                /*!<PK[6] pin */

/**
  * @brief   EXTI7 configuration
  */
#define SYSCFG_EXTICR2_EXTI7_PA         0x0000U                                /*!<PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB         0x1000U                                /*!<PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC         0x2000U                                /*!<PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD         0x3000U                                /*!<PD[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PE         0x4000U                                /*!<PE[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PF         0x5000U                                /*!<PF[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PG         0x6000U                                /*!<PG[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PH         0x7000U                                /*!<PH[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PI         0x8000U                                /*!<PI[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PJ         0x9000U                                /*!<PJ[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PK         0xA000U                                /*!<PK[7] pin */

/*****************  Bit definition for SYSCFG_EXTICR3 register  ***************/
#define SYSCFG_EXTICR3_EXTI8_Pos        (0U)
#define SYSCFG_EXTICR3_EXTI8_Msk        (0xFUL << SYSCFG_EXTICR3_EXTI8_Pos)     /*!< 0x0000000F */
#define SYSCFG_EXTICR3_EXTI8            SYSCFG_EXTICR3_EXTI8_Msk               /*!<EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9_Pos        (4U)
#define SYSCFG_EXTICR3_EXTI9_Msk        (0xFUL << SYSCFG_EXTICR3_EXTI9_Pos)     /*!< 0x000000F0 */
#define SYSCFG_EXTICR3_EXTI9            SYSCFG_EXTICR3_EXTI9_Msk               /*!<EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10_Pos       (8U)
#define SYSCFG_EXTICR3_EXTI10_Msk       (0xFUL << SYSCFG_EXTICR3_EXTI10_Pos)    /*!< 0x00000F00 */
#define SYSCFG_EXTICR3_EXTI10           SYSCFG_EXTICR3_EXTI10_Msk              /*!<EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11_Pos       (12U)
#define SYSCFG_EXTICR3_EXTI11_Msk       (0xFUL << SYSCFG_EXTICR3_EXTI11_Pos)    /*!< 0x0000F000 */
#define SYSCFG_EXTICR3_EXTI11           SYSCFG_EXTICR3_EXTI11_Msk              /*!<EXTI 11 configuration */

/**
  * @brief   EXTI8 configuration
  */
#define SYSCFG_EXTICR3_EXTI8_PA         0x0000U                                /*!<PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB         0x0001U                                /*!<PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC         0x0002U                                /*!<PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD         0x0003U                                /*!<PD[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PE         0x0004U                                /*!<PE[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PF         0x0005U                                /*!<PF[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PG         0x0006U                                /*!<PG[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PH         0x0007U                                /*!<PH[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PI         0x0008U                                /*!<PI[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PJ         0x0009U                                /*!<PJ[8] pin */

/**
  * @brief   EXTI9 configuration
  */
#define SYSCFG_EXTICR3_EXTI9_PA         0x0000U                                /*!<PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB         0x0010U                                /*!<PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC         0x0020U                                /*!<PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD         0x0030U                                /*!<PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE         0x0040U                                /*!<PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF         0x0050U                                /*!<PF[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PG         0x0060U                                /*!<PG[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PH         0x0070U                                /*!<PH[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PI         0x0080U                                /*!<PI[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PJ         0x0090U                                /*!<PJ[9] pin */

/**
  * @brief   EXTI10 configuration
  */
#define SYSCFG_EXTICR3_EXTI10_PA        0x0000U                                /*!<PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB        0x0100U                                /*!<PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC        0x0200U                                /*!<PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD        0x0300U                                /*!<PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE        0x0400U                                /*!<PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF        0x0500U                                /*!<PF[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PG        0x0600U                                /*!<PG[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PH        0x0700U                                /*!<PH[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PI        0x0800U                                /*!<PI[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PJ        0x0900U                                /*!<PJ[10] pin */

/**
  * @brief   EXTI11 configuration
  */
#define SYSCFG_EXTICR3_EXTI11_PA        0x0000U                                /*!<PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB        0x1000U                                /*!<PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC        0x2000U                                /*!<PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD        0x3000U                                /*!<PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE        0x4000U                                /*!<PE[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PF        0x5000U                                /*!<PF[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PG        0x6000U                                /*!<PG[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PH        0x7000U                                /*!<PH[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PI        0x8000U                                /*!<PI[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PJ        0x9000U                                /*!<PJ[11] pin */


/*****************  Bit definition for SYSCFG_EXTICR4 register  ***************/
#define SYSCFG_EXTICR4_EXTI12_Pos       (0U)
#define SYSCFG_EXTICR4_EXTI12_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI12_Pos)    /*!< 0x0000000F */
#define SYSCFG_EXTICR4_EXTI12           SYSCFG_EXTICR4_EXTI12_Msk              /*!<EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13_Pos       (4U)
#define SYSCFG_EXTICR4_EXTI13_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI13_Pos)    /*!< 0x000000F0 */
#define SYSCFG_EXTICR4_EXTI13           SYSCFG_EXTICR4_EXTI13_Msk              /*!<EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14_Pos       (8U)
#define SYSCFG_EXTICR4_EXTI14_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI14_Pos)    /*!< 0x00000F00 */
#define SYSCFG_EXTICR4_EXTI14           SYSCFG_EXTICR4_EXTI14_Msk              /*!<EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15_Pos       (12U)
#define SYSCFG_EXTICR4_EXTI15_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI15_Pos)    /*!< 0x0000F000 */
#define SYSCFG_EXTICR4_EXTI15           SYSCFG_EXTICR4_EXTI15_Msk              /*!<EXTI 15 configuration */
/**
  * @brief   EXTI12 configuration
  */
#define SYSCFG_EXTICR4_EXTI12_PA        0x0000U                                /*!<PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB        0x0001U                                /*!<PB[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PC        0x0002U                                /*!<PC[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PD        0x0003U                                /*!<PD[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PE        0x0004U                                /*!<PE[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PF        0x0005U                                /*!<PF[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PG        0x0006U                                /*!<PG[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PH        0x0007U                                /*!<PH[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PI        0x0008U                                /*!<PI[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PJ        0x0009U                                /*!<PJ[12] pin */

/**
  * @brief   EXTI13 configuration
  */
#define SYSCFG_EXTICR4_EXTI13_PA        0x0000U                                /*!<PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB        0x0010U                                /*!<PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC        0x0020U                                /*!<PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD        0x0030U                                /*!<PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE        0x0040U                                /*!<PE[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PF        0x0050U                                /*!<PF[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PG        0x0060U                                /*!<PG[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PH        0x0070U                                /*!<PH[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PI        0x0080U                                /*!<PI[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PJ        0x0090U                                /*!<PJ[13] pin */

/**
  * @brief   EXTI14 configuration
  */
#define SYSCFG_EXTICR4_EXTI14_PA        0x0000U                                /*!<PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB        0x0100U                                /*!<PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC        0x0200U                                /*!<PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD        0x0300U                                /*!<PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE        0x0400U                                /*!<PE[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PF        0x0500U                                /*!<PF[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PG        0x0600U                                /*!<PG[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PH        0x0700U                                /*!<PH[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PI        0x0800U                                /*!<PI[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PJ        0x0900U                                /*!<PJ[14] pin */

/**
  * @brief   EXTI15 configuration
  */
#define SYSCFG_EXTICR4_EXTI15_PA        0x0000U                                /*!<PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB        0x1000U                                /*!<PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC        0x2000U                                /*!<PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD        0x3000U                                /*!<PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE        0x4000U                                /*!<PE[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PF        0x5000U                                /*!<PF[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PG        0x6000U                                /*!<PG[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PH        0x7000U                                /*!<PH[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PI        0x8000U                                /*!<PI[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PJ        0x9000U                                /*!<PJ[15] pin */


/******************  Bit definition for SYSCFG_CMPCR register  ****************/
#define SYSCFG_CMPCR_CMP_PD_Pos         (0U)
#define SYSCFG_CMPCR_CMP_PD_Msk         (0x1UL << SYSCFG_CMPCR_CMP_PD_Pos)      /*!< 0x00000001 */
#define SYSCFG_CMPCR_CMP_PD             SYSCFG_CMPCR_CMP_PD_Msk                /*!<Compensation cell power-down */
#define SYSCFG_CMPCR_READY_Pos          (8U)
#define SYSCFG_CMPCR_READY_Msk          (0x1UL << SYSCFG_CMPCR_READY_Pos)       /*!< 0x00000100 */
#define SYSCFG_CMPCR_READY              SYSCFG_CMPCR_READY_Msk                 /*!<Compensation cell ready flag */


// 레지스터 목록
namespace SYSCFG_REG
{
enum
{
	MEMRMP = 0,		PMC,		EXTICR0,		EXTICR1,		EXTICR2,
	EXTICR3,		EXTICR4,									CMPCR = 9
};
}

#endif

