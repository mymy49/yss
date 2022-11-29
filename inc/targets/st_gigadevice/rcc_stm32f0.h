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
#ifndef __RCC_STM32_GD32F0__H_
#define __RCC_STM32_GD32F0__H_

/*****************************************************************************/
/*                                                                           */
/*                         Reset and Clock Control                           */
/*                                                                           */
/*****************************************************************************/
/*
* @brief Specific device feature definitions  (not present on all devices in the STM32F0 serie)
*/
#define RCC_PLLSRC_PREDIV1_SUPPORT  /*!< PREDIV support used as PLL source input  */

/********************  Bit definition for RCC_CR register  *******************/
#define RCC_CR_HSION_Pos                         (0U)                          
#define RCC_CR_HSION_Msk                         (0x1UL << RCC_CR_HSION_Pos)    /*!< 0x00000001 */
#define RCC_CR_HSION                             RCC_CR_HSION_Msk              /*!< Internal High Speed clock enable */
#define RCC_CR_HSIRDY_Pos                        (1U)                          
#define RCC_CR_HSIRDY_Msk                        (0x1UL << RCC_CR_HSIRDY_Pos)   /*!< 0x00000002 */
#define RCC_CR_HSIRDY                            RCC_CR_HSIRDY_Msk             /*!< Internal High Speed clock ready flag */

#define RCC_CR_HSITRIM_Pos                       (3U)                          
#define RCC_CR_HSITRIM_Msk                       (0x1FUL << RCC_CR_HSITRIM_Pos) /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                           RCC_CR_HSITRIM_Msk            /*!< Internal High Speed clock trimming */
#define RCC_CR_HSITRIM_0                         (0x01UL << RCC_CR_HSITRIM_Pos) /*!< 0x00000008 */
#define RCC_CR_HSITRIM_1                         (0x02UL << RCC_CR_HSITRIM_Pos) /*!< 0x00000010 */
#define RCC_CR_HSITRIM_2                         (0x04UL << RCC_CR_HSITRIM_Pos) /*!< 0x00000020 */
#define RCC_CR_HSITRIM_3                         (0x08UL << RCC_CR_HSITRIM_Pos) /*!< 0x00000040 */
#define RCC_CR_HSITRIM_4                         (0x10UL << RCC_CR_HSITRIM_Pos) /*!< 0x00000080 */

#define RCC_CR_HSICAL_Pos                        (8U)                          
#define RCC_CR_HSICAL_Msk                        (0xFFUL << RCC_CR_HSICAL_Pos)  /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                            RCC_CR_HSICAL_Msk             /*!< Internal High Speed clock Calibration */
#define RCC_CR_HSICAL_0                          (0x01UL << RCC_CR_HSICAL_Pos)  /*!< 0x00000100 */
#define RCC_CR_HSICAL_1                          (0x02UL << RCC_CR_HSICAL_Pos)  /*!< 0x00000200 */
#define RCC_CR_HSICAL_2                          (0x04UL << RCC_CR_HSICAL_Pos)  /*!< 0x00000400 */
#define RCC_CR_HSICAL_3                          (0x08UL << RCC_CR_HSICAL_Pos)  /*!< 0x00000800 */
#define RCC_CR_HSICAL_4                          (0x10UL << RCC_CR_HSICAL_Pos)  /*!< 0x00001000 */
#define RCC_CR_HSICAL_5                          (0x20UL << RCC_CR_HSICAL_Pos)  /*!< 0x00002000 */
#define RCC_CR_HSICAL_6                          (0x40UL << RCC_CR_HSICAL_Pos)  /*!< 0x00004000 */
#define RCC_CR_HSICAL_7                          (0x80UL << RCC_CR_HSICAL_Pos)  /*!< 0x00008000 */

#define RCC_CR_HSEON_Pos                         (16U)                         
#define RCC_CR_HSEON_Msk                         (0x1UL << RCC_CR_HSEON_Pos)    /*!< 0x00010000 */
#define RCC_CR_HSEON                             RCC_CR_HSEON_Msk              /*!< External High Speed clock enable */
#define RCC_CR_HSERDY_Pos                        (17U)                         
#define RCC_CR_HSERDY_Msk                        (0x1UL << RCC_CR_HSERDY_Pos)   /*!< 0x00020000 */
#define RCC_CR_HSERDY                            RCC_CR_HSERDY_Msk             /*!< External High Speed clock ready flag */
#define RCC_CR_HSEBYP_Pos                        (18U)                         
#define RCC_CR_HSEBYP_Msk                        (0x1UL << RCC_CR_HSEBYP_Pos)   /*!< 0x00040000 */
#define RCC_CR_HSEBYP                            RCC_CR_HSEBYP_Msk             /*!< External High Speed clock Bypass */
#define RCC_CR_CSSON_Pos                         (19U)                         
#define RCC_CR_CSSON_Msk                         (0x1UL << RCC_CR_CSSON_Pos)    /*!< 0x00080000 */
#define RCC_CR_CSSON                             RCC_CR_CSSON_Msk              /*!< Clock Security System enable */
#define RCC_CR_PLLON_Pos                         (24U)                         
#define RCC_CR_PLLON_Msk                         (0x1UL << RCC_CR_PLLON_Pos)    /*!< 0x01000000 */
#define RCC_CR_PLLON                             RCC_CR_PLLON_Msk              /*!< PLL enable */
#define RCC_CR_PLLRDY_Pos                        (25U)                         
#define RCC_CR_PLLRDY_Msk                        (0x1UL << RCC_CR_PLLRDY_Pos)   /*!< 0x02000000 */
#define RCC_CR_PLLRDY                            RCC_CR_PLLRDY_Msk             /*!< PLL clock ready flag */

/********************  Bit definition for RCC_CFGR register  *****************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                          (0U)                          
#define RCC_CFGR_SW_Msk                          (0x3UL << RCC_CFGR_SW_Pos)     /*!< 0x00000003 */
#define RCC_CFGR_SW                              RCC_CFGR_SW_Msk               /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                            (0x1UL << RCC_CFGR_SW_Pos)     /*!< 0x00000001 */
#define RCC_CFGR_SW_1                            (0x2UL << RCC_CFGR_SW_Pos)     /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI                          (0x00000000U)                 /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                          (0x00000001U)                 /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                          (0x00000002U)                 /*!< PLL selected as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                         (2U)                          
#define RCC_CFGR_SWS_Msk                         (0x3UL << RCC_CFGR_SWS_Pos)    /*!< 0x0000000C */
#define RCC_CFGR_SWS                             RCC_CFGR_SWS_Msk              /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                           (0x1UL << RCC_CFGR_SWS_Pos)    /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                           (0x2UL << RCC_CFGR_SWS_Pos)    /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI                         (0x00000000U)                 /*!< HSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSE                         (0x00000004U)                 /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL                         (0x00000008U)                 /*!< PLL used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                        (4U)                          
#define RCC_CFGR_HPRE_Msk                        (0xFUL << RCC_CFGR_HPRE_Pos)   /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                            RCC_CFGR_HPRE_Msk             /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                          (0x1UL << RCC_CFGR_HPRE_Pos)   /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                          (0x2UL << RCC_CFGR_HPRE_Pos)   /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                          (0x4UL << RCC_CFGR_HPRE_Pos)   /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                          (0x8UL << RCC_CFGR_HPRE_Pos)   /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                       (0x00000000U)                 /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2                       (0x00000080U)                 /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4                       (0x00000090U)                 /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8                       (0x000000A0U)                 /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16                      (0x000000B0U)                 /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64                      (0x000000C0U)                 /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128                     (0x000000D0U)                 /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256                     (0x000000E0U)                 /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512                     (0x000000F0U)                 /*!< SYSCLK divided by 512 */

/*!< PPRE configuration */
#define RCC_CFGR_PPRE_Pos                        (8U)                          
#define RCC_CFGR_PPRE_Msk                        (0x7UL << RCC_CFGR_PPRE_Pos)   /*!< 0x00000700 */
#define RCC_CFGR_PPRE                            RCC_CFGR_PPRE_Msk             /*!< PRE[2:0] bits (APB prescaler) */
#define RCC_CFGR_PPRE_0                          (0x1UL << RCC_CFGR_PPRE_Pos)   /*!< 0x00000100 */
#define RCC_CFGR_PPRE_1                          (0x2UL << RCC_CFGR_PPRE_Pos)   /*!< 0x00000200 */
#define RCC_CFGR_PPRE_2                          (0x4UL << RCC_CFGR_PPRE_Pos)   /*!< 0x00000400 */

#define RCC_CFGR_PPRE_DIV1                       (0x00000000U)                 /*!< HCLK not divided */
#define RCC_CFGR_PPRE_DIV2_Pos                   (10U)                         
#define RCC_CFGR_PPRE_DIV2_Msk                   (0x1UL << RCC_CFGR_PPRE_DIV2_Pos) /*!< 0x00000400 */
#define RCC_CFGR_PPRE_DIV2                       RCC_CFGR_PPRE_DIV2_Msk        /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE_DIV4_Pos                   (8U)                          
#define RCC_CFGR_PPRE_DIV4_Msk                   (0x5UL << RCC_CFGR_PPRE_DIV4_Pos) /*!< 0x00000500 */
#define RCC_CFGR_PPRE_DIV4                       RCC_CFGR_PPRE_DIV4_Msk        /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE_DIV8_Pos                   (9U)                          
#define RCC_CFGR_PPRE_DIV8_Msk                   (0x3UL << RCC_CFGR_PPRE_DIV8_Pos) /*!< 0x00000600 */
#define RCC_CFGR_PPRE_DIV8                       RCC_CFGR_PPRE_DIV8_Msk        /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE_DIV16_Pos                  (8U)                          
#define RCC_CFGR_PPRE_DIV16_Msk                  (0x7UL << RCC_CFGR_PPRE_DIV16_Pos) /*!< 0x00000700 */
#define RCC_CFGR_PPRE_DIV16                      RCC_CFGR_PPRE_DIV16_Msk       /*!< HCLK divided by 16 */

/*!< ADCPPRE configuration */
#define RCC_CFGR_ADCPRE_Pos                      (14U)                             
#define RCC_CFGR_ADCPRE_Msk                      (0x1UL << RCC_CFGR_ADCPRE_Pos)     /*!< 0x0000C000 */
#define RCC_CFGR_ADCPRE                          RCC_CFGR_ADCPRE_Msk               /*!< ADCPRE[1:0] bits (ADC prescaler) */

#define RCC_CFGR_ADCPRE_DIV2                     0x00000000U                       /*!< PCLK2 divided by 2 */
#define RCC_CFGR_ADCPRE_DIV4                     0x00004000U                       /*!< PCLK2 divided by 4 */

#define RCC_CFGR_PLLSRC_Pos                      (16U)                         
#define RCC_CFGR_PLLSRC_Msk                      (0x1UL << RCC_CFGR_PLLSRC_Pos) /*!< 0x00010000 */
#define RCC_CFGR_PLLSRC                          RCC_CFGR_PLLSRC_Msk           /*!< PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSI_DIV2                 (0x00000000U)                 /*!< HSI clock divided by 2 selected as PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSI_PREDIV               (0x00008000U)                 /*!< HSI/PREDIV clock selected as PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSE_PREDIV               (0x00010000U)                 /*!< HSE/PREDIV clock selected as PLL entry clock source */

#define RCC_CFGR_PLLXTPRE_Pos                    (17U)                         
#define RCC_CFGR_PLLXTPRE_Msk                    (0x1UL << RCC_CFGR_PLLXTPRE_Pos) /*!< 0x00020000 */
#define RCC_CFGR_PLLXTPRE                        RCC_CFGR_PLLXTPRE_Msk         /*!< HSE divider for PLL entry */
#define RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV1        (0x00000000U)                 /*!< HSE/PREDIV clock not divided for PLL entry */
#define RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV2        (0x00020000U)                 /*!< HSE/PREDIV clock divided by 2 for PLL entry */

/*!< PLLMUL configuration */
#define RCC_CFGR_PLLMUL_Pos                      (18U)                         
#define RCC_CFGR_PLLMUL_Msk                      (0xFUL << RCC_CFGR_PLLMUL_Pos) /*!< 0x003C0000 */
#define RCC_CFGR_PLLMUL                          RCC_CFGR_PLLMUL_Msk           /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define RCC_CFGR_PLLMUL_0                        (0x1UL << RCC_CFGR_PLLMUL_Pos) /*!< 0x00040000 */
#define RCC_CFGR_PLLMUL_1                        (0x2UL << RCC_CFGR_PLLMUL_Pos) /*!< 0x00080000 */
#define RCC_CFGR_PLLMUL_2                        (0x4UL << RCC_CFGR_PLLMUL_Pos) /*!< 0x00100000 */
#define RCC_CFGR_PLLMUL_3                        (0x8UL << RCC_CFGR_PLLMUL_Pos) /*!< 0x00200000 */

#define RCC_CFGR_PLLMUL2                         (0x00000000U)                 /*!< PLL input clock*2 */
#define RCC_CFGR_PLLMUL3                         (0x00040000U)                 /*!< PLL input clock*3 */
#define RCC_CFGR_PLLMUL4                         (0x00080000U)                 /*!< PLL input clock*4 */
#define RCC_CFGR_PLLMUL5                         (0x000C0000U)                 /*!< PLL input clock*5 */
#define RCC_CFGR_PLLMUL6                         (0x00100000U)                 /*!< PLL input clock*6 */
#define RCC_CFGR_PLLMUL7                         (0x00140000U)                 /*!< PLL input clock*7 */
#define RCC_CFGR_PLLMUL8                         (0x00180000U)                 /*!< PLL input clock*8 */
#define RCC_CFGR_PLLMUL9                         (0x001C0000U)                 /*!< PLL input clock*9 */
#define RCC_CFGR_PLLMUL10                        (0x00200000U)                 /*!< PLL input clock10 */
#define RCC_CFGR_PLLMUL11                        (0x00240000U)                 /*!< PLL input clock*11 */
#define RCC_CFGR_PLLMUL12                        (0x00280000U)                 /*!< PLL input clock*12 */
#define RCC_CFGR_PLLMUL13                        (0x002C0000U)                 /*!< PLL input clock*13 */
#define RCC_CFGR_PLLMUL14                        (0x00300000U)                 /*!< PLL input clock*14 */
#define RCC_CFGR_PLLMUL15                        (0x00340000U)                 /*!< PLL input clock*15 */
#define RCC_CFGR_PLLMUL16                        (0x00380000U)                 /*!< PLL input clock*16 */

/*!< MCO configuration */
#define RCC_CFGR_MCO_Pos                         (24U)                         
#define RCC_CFGR_MCO_Msk                         (0xFUL << RCC_CFGR_MCO_Pos)    /*!< 0x0F000000 */
#define RCC_CFGR_MCO                             RCC_CFGR_MCO_Msk              /*!< MCO[3:0] bits (Microcontroller Clock Output) */
#define RCC_CFGR_MCO_0                           (0x1UL << RCC_CFGR_MCO_Pos)    /*!< 0x01000000 */
#define RCC_CFGR_MCO_1                           (0x2UL << RCC_CFGR_MCO_Pos)    /*!< 0x02000000 */
#define RCC_CFGR_MCO_2                           (0x4UL << RCC_CFGR_MCO_Pos)    /*!< 0x04000000 */

#define RCC_CFGR_MCO_NOCLOCK                     (0x00000000U)                 /*!< No clock */
#define RCC_CFGR_MCO_HSI14                       (0x01000000U)                 /*!< HSI14 clock selected as MCO source */
#define RCC_CFGR_MCO_LSI                         (0x02000000U)                 /*!< LSI clock selected as MCO source */
#define RCC_CFGR_MCO_LSE                         (0x03000000U)                 /*!< LSE clock selected as MCO source */
#define RCC_CFGR_MCO_SYSCLK                      (0x04000000U)                 /*!< System clock selected as MCO source */
#define RCC_CFGR_MCO_HSI                         (0x05000000U)                 /*!< HSI clock selected as MCO source */
#define RCC_CFGR_MCO_HSE                         (0x06000000U)                 /*!< HSE clock selected as MCO source  */
#define RCC_CFGR_MCO_PLL                         (0x07000000U)                 /*!< PLL clock divided by 2 selected as MCO source */

#define RCC_CFGR_MCOPRE_Pos                      (28U)                         
#define RCC_CFGR_MCOPRE_Msk                      (0x7UL << RCC_CFGR_MCOPRE_Pos) /*!< 0x70000000 */
#define RCC_CFGR_MCOPRE                          RCC_CFGR_MCOPRE_Msk           /*!< MCO prescaler  */
#define RCC_CFGR_MCOPRE_DIV1                     (0x00000000U)                 /*!< MCO is divided by 1  */
#define RCC_CFGR_MCOPRE_DIV2                     (0x10000000U)                 /*!< MCO is divided by 2  */
#define RCC_CFGR_MCOPRE_DIV4                     (0x20000000U)                 /*!< MCO is divided by 4  */
#define RCC_CFGR_MCOPRE_DIV8                     (0x30000000U)                 /*!< MCO is divided by 8  */
#define RCC_CFGR_MCOPRE_DIV16                    (0x40000000U)                 /*!< MCO is divided by 16  */
#define RCC_CFGR_MCOPRE_DIV32                    (0x50000000U)                 /*!< MCO is divided by 32  */
#define RCC_CFGR_MCOPRE_DIV64                    (0x60000000U)                 /*!< MCO is divided by 64  */
#define RCC_CFGR_MCOPRE_DIV128                   (0x70000000U)                 /*!< MCO is divided by 128  */

#define RCC_CFGR_PLLNODIV_Pos                    (31U)                         
#define RCC_CFGR_PLLNODIV_Msk                    (0x1UL << RCC_CFGR_PLLNODIV_Pos) /*!< 0x80000000 */
#define RCC_CFGR_PLLNODIV                        RCC_CFGR_PLLNODIV_Msk         /*!< PLL is not divided to MCO  */

/* Reference defines */
#define RCC_CFGR_MCOSEL                      RCC_CFGR_MCO
#define RCC_CFGR_MCOSEL_0                    RCC_CFGR_MCO_0
#define RCC_CFGR_MCOSEL_1                    RCC_CFGR_MCO_1
#define RCC_CFGR_MCOSEL_2                    RCC_CFGR_MCO_2
#define RCC_CFGR_MCOSEL_NOCLOCK              RCC_CFGR_MCO_NOCLOCK
#define RCC_CFGR_MCOSEL_HSI14                RCC_CFGR_MCO_HSI14
#define RCC_CFGR_MCOSEL_LSI                  RCC_CFGR_MCO_LSI
#define RCC_CFGR_MCOSEL_LSE                  RCC_CFGR_MCO_LSE
#define RCC_CFGR_MCOSEL_SYSCLK               RCC_CFGR_MCO_SYSCLK
#define RCC_CFGR_MCOSEL_HSI                  RCC_CFGR_MCO_HSI
#define RCC_CFGR_MCOSEL_HSE                  RCC_CFGR_MCO_HSE
#define RCC_CFGR_MCOSEL_PLL_DIV2             RCC_CFGR_MCO_PLL

/*!<******************  Bit definition for RCC_CIR register  *****************/
#define RCC_CIR_LSIRDYF_Pos                      (0U)                          
#define RCC_CIR_LSIRDYF_Msk                      (0x1UL << RCC_CIR_LSIRDYF_Pos) /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF                          RCC_CIR_LSIRDYF_Msk           /*!< LSI Ready Interrupt flag */
#define RCC_CIR_LSERDYF_Pos                      (1U)                          
#define RCC_CIR_LSERDYF_Msk                      (0x1UL << RCC_CIR_LSERDYF_Pos) /*!< 0x00000002 */
#define RCC_CIR_LSERDYF                          RCC_CIR_LSERDYF_Msk           /*!< LSE Ready Interrupt flag */
#define RCC_CIR_HSIRDYF_Pos                      (2U)                          
#define RCC_CIR_HSIRDYF_Msk                      (0x1UL << RCC_CIR_HSIRDYF_Pos) /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF                          RCC_CIR_HSIRDYF_Msk           /*!< HSI Ready Interrupt flag */
#define RCC_CIR_HSERDYF_Pos                      (3U)                          
#define RCC_CIR_HSERDYF_Msk                      (0x1UL << RCC_CIR_HSERDYF_Pos) /*!< 0x00000008 */
#define RCC_CIR_HSERDYF                          RCC_CIR_HSERDYF_Msk           /*!< HSE Ready Interrupt flag */
#define RCC_CIR_PLLRDYF_Pos                      (4U)                          
#define RCC_CIR_PLLRDYF_Msk                      (0x1UL << RCC_CIR_PLLRDYF_Pos) /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF                          RCC_CIR_PLLRDYF_Msk           /*!< PLL Ready Interrupt flag */
#define RCC_CIR_HSI14RDYF_Pos                    (5U)                          
#define RCC_CIR_HSI14RDYF_Msk                    (0x1UL << RCC_CIR_HSI14RDYF_Pos) /*!< 0x00000020 */
#define RCC_CIR_HSI14RDYF                        RCC_CIR_HSI14RDYF_Msk         /*!< HSI14 Ready Interrupt flag */
#define RCC_CIR_CSSF_Pos                         (7U)                          
#define RCC_CIR_CSSF_Msk                         (0x1UL << RCC_CIR_CSSF_Pos)    /*!< 0x00000080 */
#define RCC_CIR_CSSF                             RCC_CIR_CSSF_Msk              /*!< Clock Security System Interrupt flag */
#define RCC_CIR_LSIRDYIE_Pos                     (8U)                          
#define RCC_CIR_LSIRDYIE_Msk                     (0x1UL << RCC_CIR_LSIRDYIE_Pos) /*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE                         RCC_CIR_LSIRDYIE_Msk          /*!< LSI Ready Interrupt Enable */
#define RCC_CIR_LSERDYIE_Pos                     (9U)                          
#define RCC_CIR_LSERDYIE_Msk                     (0x1UL << RCC_CIR_LSERDYIE_Pos) /*!< 0x00000200 */
#define RCC_CIR_LSERDYIE                         RCC_CIR_LSERDYIE_Msk          /*!< LSE Ready Interrupt Enable */
#define RCC_CIR_HSIRDYIE_Pos                     (10U)                         
#define RCC_CIR_HSIRDYIE_Msk                     (0x1UL << RCC_CIR_HSIRDYIE_Pos) /*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE                         RCC_CIR_HSIRDYIE_Msk          /*!< HSI Ready Interrupt Enable */
#define RCC_CIR_HSERDYIE_Pos                     (11U)                         
#define RCC_CIR_HSERDYIE_Msk                     (0x1UL << RCC_CIR_HSERDYIE_Pos) /*!< 0x00000800 */
#define RCC_CIR_HSERDYIE                         RCC_CIR_HSERDYIE_Msk          /*!< HSE Ready Interrupt Enable */
#define RCC_CIR_PLLRDYIE_Pos                     (12U)                         
#define RCC_CIR_PLLRDYIE_Msk                     (0x1UL << RCC_CIR_PLLRDYIE_Pos) /*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE                         RCC_CIR_PLLRDYIE_Msk          /*!< PLL Ready Interrupt Enable */
#define RCC_CIR_HSI14RDYIE_Pos                   (13U)                         
#define RCC_CIR_HSI14RDYIE_Msk                   (0x1UL << RCC_CIR_HSI14RDYIE_Pos) /*!< 0x00002000 */
#define RCC_CIR_HSI14RDYIE                       RCC_CIR_HSI14RDYIE_Msk        /*!< HSI14 Ready Interrupt Enable */
#define RCC_CIR_LSIRDYC_Pos                      (16U)                         
#define RCC_CIR_LSIRDYC_Msk                      (0x1UL << RCC_CIR_LSIRDYC_Pos) /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC                          RCC_CIR_LSIRDYC_Msk           /*!< LSI Ready Interrupt Clear */
#define RCC_CIR_LSERDYC_Pos                      (17U)                         
#define RCC_CIR_LSERDYC_Msk                      (0x1UL << RCC_CIR_LSERDYC_Pos) /*!< 0x00020000 */
#define RCC_CIR_LSERDYC                          RCC_CIR_LSERDYC_Msk           /*!< LSE Ready Interrupt Clear */
#define RCC_CIR_HSIRDYC_Pos                      (18U)                         
#define RCC_CIR_HSIRDYC_Msk                      (0x1UL << RCC_CIR_HSIRDYC_Pos) /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC                          RCC_CIR_HSIRDYC_Msk           /*!< HSI Ready Interrupt Clear */
#define RCC_CIR_HSERDYC_Pos                      (19U)                         
#define RCC_CIR_HSERDYC_Msk                      (0x1UL << RCC_CIR_HSERDYC_Pos) /*!< 0x00080000 */
#define RCC_CIR_HSERDYC                          RCC_CIR_HSERDYC_Msk           /*!< HSE Ready Interrupt Clear */
#define RCC_CIR_PLLRDYC_Pos                      (20U)                         
#define RCC_CIR_PLLRDYC_Msk                      (0x1UL << RCC_CIR_PLLRDYC_Pos) /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC                          RCC_CIR_PLLRDYC_Msk           /*!< PLL Ready Interrupt Clear */
#define RCC_CIR_HSI14RDYC_Pos                    (21U)                         
#define RCC_CIR_HSI14RDYC_Msk                    (0x1UL << RCC_CIR_HSI14RDYC_Pos) /*!< 0x00200000 */
#define RCC_CIR_HSI14RDYC                        RCC_CIR_HSI14RDYC_Msk         /*!< HSI14 Ready Interrupt Clear */
#define RCC_CIR_CSSC_Pos                         (23U)                         
#define RCC_CIR_CSSC_Msk                         (0x1UL << RCC_CIR_CSSC_Pos)    /*!< 0x00800000 */
#define RCC_CIR_CSSC                             RCC_CIR_CSSC_Msk              /*!< Clock Security System Interrupt Clear */

/*****************  Bit definition for RCC_APB2RSTR register  ****************/
#define RCC_APB2RSTR_SYSCFGRST_Pos               (0U)                          
#define RCC_APB2RSTR_SYSCFGRST_Msk               (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos) /*!< 0x00000001 */
#define RCC_APB2RSTR_SYSCFGRST                   RCC_APB2RSTR_SYSCFGRST_Msk    /*!< SYSCFG reset */
#define RCC_APB2RSTR_USART6RST_Pos               (5U)                          
#define RCC_APB2RSTR_USART6RST_Msk               (0x1UL << RCC_APB2RSTR_USART6RST_Pos) /*!< 0x00000020 */
#define RCC_APB2RSTR_USART6RST                   RCC_APB2RSTR_USART6RST_Msk    /*!< USART6 reset */
#define RCC_APB2RSTR_ADCRST_Pos                  (9U)                          
#define RCC_APB2RSTR_ADCRST_Msk                  (0x1UL << RCC_APB2RSTR_ADCRST_Pos) /*!< 0x00000200 */
#define RCC_APB2RSTR_ADCRST                      RCC_APB2RSTR_ADCRST_Msk       /*!< ADC reset */
#define RCC_APB2RSTR_TIM1RST_Pos                 (11U)                         
#define RCC_APB2RSTR_TIM1RST_Msk                 (0x1UL << RCC_APB2RSTR_TIM1RST_Pos) /*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST                     RCC_APB2RSTR_TIM1RST_Msk      /*!< TIM1 reset */
#define RCC_APB2RSTR_SPI1RST_Pos                 (12U)                         
#define RCC_APB2RSTR_SPI1RST_Msk                 (0x1UL << RCC_APB2RSTR_SPI1RST_Pos) /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST                     RCC_APB2RSTR_SPI1RST_Msk      /*!< SPI1 reset */
#define RCC_APB2RSTR_USART1RST_Pos               (14U)                         
#define RCC_APB2RSTR_USART1RST_Msk               (0x1UL << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST                   RCC_APB2RSTR_USART1RST_Msk    /*!< USART1 reset */
#define RCC_APB2RSTR_TIM15RST_Pos                (16U)                         
#define RCC_APB2RSTR_TIM15RST_Msk                (0x1UL << RCC_APB2RSTR_TIM15RST_Pos) /*!< 0x00010000 */
#define RCC_APB2RSTR_TIM15RST                    RCC_APB2RSTR_TIM15RST_Msk     /*!< TIM15 reset */
#define RCC_APB2RSTR_TIM16RST_Pos                (17U)                         
#define RCC_APB2RSTR_TIM16RST_Msk                (0x1UL << RCC_APB2RSTR_TIM16RST_Pos) /*!< 0x00020000 */
#define RCC_APB2RSTR_TIM16RST                    RCC_APB2RSTR_TIM16RST_Msk     /*!< TIM16 reset */
#define RCC_APB2RSTR_TIM17RST_Pos                (18U)                         
#define RCC_APB2RSTR_TIM17RST_Msk                (0x1UL << RCC_APB2RSTR_TIM17RST_Pos) /*!< 0x00040000 */
#define RCC_APB2RSTR_TIM17RST                    RCC_APB2RSTR_TIM17RST_Msk     /*!< TIM17 reset */
#define RCC_APB2RSTR_DBGMCURST_Pos               (22U)                         
#define RCC_APB2RSTR_DBGMCURST_Msk               (0x1UL << RCC_APB2RSTR_DBGMCURST_Pos) /*!< 0x00400000 */
#define RCC_APB2RSTR_DBGMCURST                   RCC_APB2RSTR_DBGMCURST_Msk    /*!< DBGMCU reset */

/*!< Old ADC1 reset bit definition maintained for legacy purpose */
#define  RCC_APB2RSTR_ADC1RST                RCC_APB2RSTR_ADCRST          

/*****************  Bit definition for RCC_APB1RSTR register  ****************/
#define RCC_APB1RSTR_TIM3RST_Pos                 (1U)                          
#define RCC_APB1RSTR_TIM3RST_Msk                 (0x1UL << RCC_APB1RSTR_TIM3RST_Pos) /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST                     RCC_APB1RSTR_TIM3RST_Msk      /*!< Timer 3 reset */
#define RCC_APB1RSTR_TIM6RST_Pos                 (4U)                          
#define RCC_APB1RSTR_TIM6RST_Msk                 (0x1UL << RCC_APB1RSTR_TIM6RST_Pos) /*!< 0x00000010 */
#define RCC_APB1RSTR_TIM6RST                     RCC_APB1RSTR_TIM6RST_Msk      /*!< Timer 6 reset */
#define RCC_APB1RSTR_TIM7RST_Pos                 (5U)                          
#define RCC_APB1RSTR_TIM7RST_Msk                 (0x1UL << RCC_APB1RSTR_TIM7RST_Pos) /*!< 0x00000020 */
#define RCC_APB1RSTR_TIM7RST                     RCC_APB1RSTR_TIM7RST_Msk      /*!< Timer 7 reset */
#define RCC_APB1RSTR_TIM14RST_Pos                (8U)                          
#define RCC_APB1RSTR_TIM14RST_Msk                (0x1UL << RCC_APB1RSTR_TIM14RST_Pos) /*!< 0x00000100 */
#define RCC_APB1RSTR_TIM14RST                    RCC_APB1RSTR_TIM14RST_Msk     /*!< Timer 14 reset */
#define RCC_APB1RSTR_WWDGRST_Pos                 (11U)                         
#define RCC_APB1RSTR_WWDGRST_Msk                 (0x1UL << RCC_APB1RSTR_WWDGRST_Pos) /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST                     RCC_APB1RSTR_WWDGRST_Msk      /*!< Window Watchdog reset */
#define RCC_APB1RSTR_SPI2RST_Pos                 (14U)                         
#define RCC_APB1RSTR_SPI2RST_Msk                 (0x1UL << RCC_APB1RSTR_SPI2RST_Pos) /*!< 0x00004000 */
#define RCC_APB1RSTR_SPI2RST                     RCC_APB1RSTR_SPI2RST_Msk      /*!< SPI2 reset */
#define RCC_APB1RSTR_USART2RST_Pos               (17U)                         
#define RCC_APB1RSTR_USART2RST_Msk               (0x1UL << RCC_APB1RSTR_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST                   RCC_APB1RSTR_USART2RST_Msk    /*!< USART 2 reset */
#define RCC_APB1RSTR_USART3RST_Pos               (18U)                         
#define RCC_APB1RSTR_USART3RST_Msk               (0x1UL << RCC_APB1RSTR_USART3RST_Pos) /*!< 0x00040000 */
#define RCC_APB1RSTR_USART3RST                   RCC_APB1RSTR_USART3RST_Msk    /*!< USART 3 reset */
#define RCC_APB1RSTR_USART4RST_Pos               (19U)                         
#define RCC_APB1RSTR_USART4RST_Msk               (0x1UL << RCC_APB1RSTR_USART4RST_Pos) /*!< 0x00080000 */
#define RCC_APB1RSTR_USART4RST                   RCC_APB1RSTR_USART4RST_Msk    /*!< USART 4 reset */
#define RCC_APB1RSTR_USART5RST_Pos               (20U)                         
#define RCC_APB1RSTR_USART5RST_Msk               (0x1UL << RCC_APB1RSTR_USART5RST_Pos) /*!< 0x00100000 */
#define RCC_APB1RSTR_USART5RST                   RCC_APB1RSTR_USART5RST_Msk    /*!< USART 5 reset */
#define RCC_APB1RSTR_I2C1RST_Pos                 (21U)                         
#define RCC_APB1RSTR_I2C1RST_Msk                 (0x1UL << RCC_APB1RSTR_I2C1RST_Pos) /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST                     RCC_APB1RSTR_I2C1RST_Msk      /*!< I2C 1 reset */
#define RCC_APB1RSTR_I2C2RST_Pos                 (22U)                         
#define RCC_APB1RSTR_I2C2RST_Msk                 (0x1UL << RCC_APB1RSTR_I2C2RST_Pos) /*!< 0x00400000 */
#define RCC_APB1RSTR_I2C2RST                     RCC_APB1RSTR_I2C2RST_Msk      /*!< I2C 2 reset */
#define RCC_APB1RSTR_PWRRST_Pos                  (28U)                         
#define RCC_APB1RSTR_PWRRST_Msk                  (0x1UL << RCC_APB1RSTR_PWRRST_Pos) /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST                      RCC_APB1RSTR_PWRRST_Msk       /*!< PWR reset */

/******************  Bit definition for RCC_AHBENR register  *****************/
#define RCC_AHBENR_DMAEN_Pos                     (0U)                          
#define RCC_AHBENR_DMAEN_Msk                     (0x1UL << RCC_AHBENR_DMAEN_Pos) /*!< 0x00000001 */
#define RCC_AHBENR_DMAEN                         RCC_AHBENR_DMAEN_Msk          /*!< DMA1 clock enable */
#define RCC_AHBENR_SRAMEN_Pos                    (2U)                          
#define RCC_AHBENR_SRAMEN_Msk                    (0x1UL << RCC_AHBENR_SRAMEN_Pos) /*!< 0x00000004 */
#define RCC_AHBENR_SRAMEN                        RCC_AHBENR_SRAMEN_Msk         /*!< SRAM interface clock enable */
#define RCC_AHBENR_FLITFEN_Pos                   (4U)                          
#define RCC_AHBENR_FLITFEN_Msk                   (0x1UL << RCC_AHBENR_FLITFEN_Pos) /*!< 0x00000010 */
#define RCC_AHBENR_FLITFEN                       RCC_AHBENR_FLITFEN_Msk        /*!< FLITF clock enable */
#define RCC_AHBENR_CRCEN_Pos                     (6U)                          
#define RCC_AHBENR_CRCEN_Msk                     (0x1UL << RCC_AHBENR_CRCEN_Pos) /*!< 0x00000040 */
#define RCC_AHBENR_CRCEN                         RCC_AHBENR_CRCEN_Msk          /*!< CRC clock enable */
#define RCC_AHBENR_GPIOAEN_Pos                   (17U)                         
#define RCC_AHBENR_GPIOAEN_Msk                   (0x1UL << RCC_AHBENR_GPIOAEN_Pos) /*!< 0x00020000 */
#define RCC_AHBENR_GPIOAEN                       RCC_AHBENR_GPIOAEN_Msk        /*!< GPIOA clock enable */
#define RCC_AHBENR_GPIOBEN_Pos                   (18U)                         
#define RCC_AHBENR_GPIOBEN_Msk                   (0x1UL << RCC_AHBENR_GPIOBEN_Pos) /*!< 0x00040000 */
#define RCC_AHBENR_GPIOBEN                       RCC_AHBENR_GPIOBEN_Msk        /*!< GPIOB clock enable */
#define RCC_AHBENR_GPIOCEN_Pos                   (19U)                         
#define RCC_AHBENR_GPIOCEN_Msk                   (0x1UL << RCC_AHBENR_GPIOCEN_Pos) /*!< 0x00080000 */
#define RCC_AHBENR_GPIOCEN                       RCC_AHBENR_GPIOCEN_Msk        /*!< GPIOC clock enable */
#define RCC_AHBENR_GPIODEN_Pos                   (20U)                         
#define RCC_AHBENR_GPIODEN_Msk                   (0x1UL << RCC_AHBENR_GPIODEN_Pos) /*!< 0x00100000 */
#define RCC_AHBENR_GPIODEN                       RCC_AHBENR_GPIODEN_Msk        /*!< GPIOD clock enable */
#define RCC_AHBENR_GPIOFEN_Pos                   (22U)                         
#define RCC_AHBENR_GPIOFEN_Msk                   (0x1UL << RCC_AHBENR_GPIOFEN_Pos) /*!< 0x00400000 */
#define RCC_AHBENR_GPIOFEN                       RCC_AHBENR_GPIOFEN_Msk        /*!< GPIOF clock enable */

/* Old Bit definition maintained for legacy purpose */
#define  RCC_AHBENR_DMA1EN                   RCC_AHBENR_DMAEN        /*!< DMA1 clock enable */

/*****************  Bit definition for RCC_APB2ENR register  *****************/
#define RCC_APB2ENR_SYSCFGCOMPEN_Pos             (0U)                          
#define RCC_APB2ENR_SYSCFGCOMPEN_Msk             (0x1UL << RCC_APB2ENR_SYSCFGCOMPEN_Pos) /*!< 0x00000001 */
#define RCC_APB2ENR_SYSCFGCOMPEN                 RCC_APB2ENR_SYSCFGCOMPEN_Msk  /*!< SYSCFG and comparator clock enable */
#define RCC_APB2ENR_USART6EN_Pos                 (5U)                          
#define RCC_APB2ENR_USART6EN_Msk                 (0x1UL << RCC_APB2ENR_USART6EN_Pos) /*!< 0x00000020 */
#define RCC_APB2ENR_USART6EN                     RCC_APB2ENR_USART6EN_Msk      /*!< USART6 clock enable */
#define RCC_APB2ENR_ADCEN_Pos                    (9U)                          
#define RCC_APB2ENR_ADCEN_Msk                    (0x1UL << RCC_APB2ENR_ADCEN_Pos) /*!< 0x00000200 */
#define RCC_APB2ENR_ADCEN                        RCC_APB2ENR_ADCEN_Msk         /*!< ADC1 clock enable */
#define RCC_APB2ENR_TIM1EN_Pos                   (11U)                         
#define RCC_APB2ENR_TIM1EN_Msk                   (0x1UL << RCC_APB2ENR_TIM1EN_Pos) /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                       RCC_APB2ENR_TIM1EN_Msk        /*!< TIM1 clock enable */
#define RCC_APB2ENR_SPI1EN_Pos                   (12U)                         
#define RCC_APB2ENR_SPI1EN_Msk                   (0x1UL << RCC_APB2ENR_SPI1EN_Pos) /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                       RCC_APB2ENR_SPI1EN_Msk        /*!< SPI1 clock enable */
#define RCC_APB2ENR_USART1EN_Pos                 (14U)                         
#define RCC_APB2ENR_USART1EN_Msk                 (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                     RCC_APB2ENR_USART1EN_Msk      /*!< USART1 clock enable */
#define RCC_APB2ENR_TIM15EN_Pos                  (16U)                         
#define RCC_APB2ENR_TIM15EN_Msk                  (0x1UL << RCC_APB2ENR_TIM15EN_Pos) /*!< 0x00010000 */
#define RCC_APB2ENR_TIM15EN                      RCC_APB2ENR_TIM15EN_Msk       /*!< TIM15 clock enable */
#define RCC_APB2ENR_TIM16EN_Pos                  (17U)                         
#define RCC_APB2ENR_TIM16EN_Msk                  (0x1UL << RCC_APB2ENR_TIM16EN_Pos) /*!< 0x00020000 */
#define RCC_APB2ENR_TIM16EN                      RCC_APB2ENR_TIM16EN_Msk       /*!< TIM16 clock enable */
#define RCC_APB2ENR_TIM17EN_Pos                  (18U)                         
#define RCC_APB2ENR_TIM17EN_Msk                  (0x1UL << RCC_APB2ENR_TIM17EN_Pos) /*!< 0x00040000 */
#define RCC_APB2ENR_TIM17EN                      RCC_APB2ENR_TIM17EN_Msk       /*!< TIM17 clock enable */
#define RCC_APB2ENR_DBGMCUEN_Pos                 (22U)                         
#define RCC_APB2ENR_DBGMCUEN_Msk                 (0x1UL << RCC_APB2ENR_DBGMCUEN_Pos) /*!< 0x00400000 */
#define RCC_APB2ENR_DBGMCUEN                     RCC_APB2ENR_DBGMCUEN_Msk      /*!< DBGMCU clock enable */

/* Old Bit definition maintained for legacy purpose */
#define  RCC_APB2ENR_SYSCFGEN                RCC_APB2ENR_SYSCFGCOMPEN        /*!< SYSCFG clock enable */
#define  RCC_APB2ENR_ADC1EN                  RCC_APB2ENR_ADCEN               /*!< ADC1 clock enable */

/*****************  Bit definition for RCC_APB1ENR register  *****************/
#define RCC_APB1ENR_TIM3EN_Pos                   (1U)                          
#define RCC_APB1ENR_TIM3EN_Msk                   (0x1UL << RCC_APB1ENR_TIM3EN_Pos) /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                       RCC_APB1ENR_TIM3EN_Msk        /*!< Timer 3 clock enable */
#define RCC_APB1ENR_TIM6EN_Pos                   (4U)                          
#define RCC_APB1ENR_TIM6EN_Msk                   (0x1UL << RCC_APB1ENR_TIM6EN_Pos) /*!< 0x00000010 */
#define RCC_APB1ENR_TIM6EN                       RCC_APB1ENR_TIM6EN_Msk        /*!< Timer 6 clock enable */
#define RCC_APB1ENR_TIM7EN_Pos                   (5U)                          
#define RCC_APB1ENR_TIM7EN_Msk                   (0x1UL << RCC_APB1ENR_TIM7EN_Pos) /*!< 0x00000020 */
#define RCC_APB1ENR_TIM7EN                       RCC_APB1ENR_TIM7EN_Msk        /*!< Timer 7 clock enable */
#define RCC_APB1ENR_TIM14EN_Pos                  (8U)                          
#define RCC_APB1ENR_TIM14EN_Msk                  (0x1UL << RCC_APB1ENR_TIM14EN_Pos) /*!< 0x00000100 */
#define RCC_APB1ENR_TIM14EN                      RCC_APB1ENR_TIM14EN_Msk       /*!< Timer 14 clock enable */
#define RCC_APB1ENR_WWDGEN_Pos                   (11U)                         
#define RCC_APB1ENR_WWDGEN_Msk                   (0x1UL << RCC_APB1ENR_WWDGEN_Pos) /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                       RCC_APB1ENR_WWDGEN_Msk        /*!< Window Watchdog clock enable */
#define RCC_APB1ENR_SPI2EN_Pos                   (14U)                         
#define RCC_APB1ENR_SPI2EN_Msk                   (0x1UL << RCC_APB1ENR_SPI2EN_Pos) /*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN                       RCC_APB1ENR_SPI2EN_Msk        /*!< SPI2 clock enable */
#define RCC_APB1ENR_USART2EN_Pos                 (17U)                         
#define RCC_APB1ENR_USART2EN_Msk                 (0x1UL << RCC_APB1ENR_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN                     RCC_APB1ENR_USART2EN_Msk      /*!< USART2 clock enable */
#define RCC_APB1ENR_USART3EN_Pos                 (18U)                         
#define RCC_APB1ENR_USART3EN_Msk                 (0x1UL << RCC_APB1ENR_USART3EN_Pos) /*!< 0x00040000 */
#define RCC_APB1ENR_USART3EN                     RCC_APB1ENR_USART3EN_Msk      /*!< USART3 clock enable */
#define RCC_APB1ENR_USART4EN_Pos                 (19U)                         
#define RCC_APB1ENR_USART4EN_Msk                 (0x1UL << RCC_APB1ENR_USART4EN_Pos) /*!< 0x00080000 */
#define RCC_APB1ENR_USART4EN                     RCC_APB1ENR_USART4EN_Msk      /*!< USART4 clock enable */
#define RCC_APB1ENR_USART5EN_Pos                 (20U)                         
#define RCC_APB1ENR_USART5EN_Msk                 (0x1UL << RCC_APB1ENR_USART5EN_Pos) /*!< 0x00100000 */
#define RCC_APB1ENR_USART5EN                     RCC_APB1ENR_USART5EN_Msk      /*!< USART5 clock enable */
#define RCC_APB1ENR_I2C1EN_Pos                   (21U)                         
#define RCC_APB1ENR_I2C1EN_Msk                   (0x1UL << RCC_APB1ENR_I2C1EN_Pos) /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                       RCC_APB1ENR_I2C1EN_Msk        /*!< I2C1 clock enable */
#define RCC_APB1ENR_I2C2EN_Pos                   (22U)                         
#define RCC_APB1ENR_I2C2EN_Msk                   (0x1UL << RCC_APB1ENR_I2C2EN_Pos) /*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN                       RCC_APB1ENR_I2C2EN_Msk        /*!< I2C2 clock enable */
#define RCC_APB1ENR_PWREN_Pos                    (28U)                         
#define RCC_APB1ENR_PWREN_Msk                    (0x1UL << RCC_APB1ENR_PWREN_Pos) /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                        RCC_APB1ENR_PWREN_Msk         /*!< PWR clock enable */

/*******************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                       (0U)                          
#define RCC_BDCR_LSEON_Msk                       (0x1UL << RCC_BDCR_LSEON_Pos)  /*!< 0x00000001 */
#define RCC_BDCR_LSEON                           RCC_BDCR_LSEON_Msk            /*!< External Low Speed oscillator enable */
#define RCC_BDCR_LSERDY_Pos                      (1U)                          
#define RCC_BDCR_LSERDY_Msk                      (0x1UL << RCC_BDCR_LSERDY_Pos) /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                          RCC_BDCR_LSERDY_Msk           /*!< External Low Speed oscillator Ready */
#define RCC_BDCR_LSEBYP_Pos                      (2U)                          
#define RCC_BDCR_LSEBYP_Msk                      (0x1UL << RCC_BDCR_LSEBYP_Pos) /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                          RCC_BDCR_LSEBYP_Msk           /*!< External Low Speed oscillator Bypass */

#define RCC_BDCR_LSEDRV_Pos                      (3U)                          
#define RCC_BDCR_LSEDRV_Msk                      (0x3UL << RCC_BDCR_LSEDRV_Pos) /*!< 0x00000018 */
#define RCC_BDCR_LSEDRV                          RCC_BDCR_LSEDRV_Msk           /*!< LSEDRV[1:0] bits (LSE Osc. drive capability) */
#define RCC_BDCR_LSEDRV_0                        (0x1UL << RCC_BDCR_LSEDRV_Pos) /*!< 0x00000008 */
#define RCC_BDCR_LSEDRV_1                        (0x2UL << RCC_BDCR_LSEDRV_Pos) /*!< 0x00000010 */

#define RCC_BDCR_RTCSEL_Pos                      (8U)                          
#define RCC_BDCR_RTCSEL_Msk                      (0x3UL << RCC_BDCR_RTCSEL_Pos) /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                          RCC_BDCR_RTCSEL_Msk           /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define RCC_BDCR_RTCSEL_0                        (0x1UL << RCC_BDCR_RTCSEL_Pos) /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                        (0x2UL << RCC_BDCR_RTCSEL_Pos) /*!< 0x00000200 */

/*!< RTC configuration */
#define RCC_BDCR_RTCSEL_NOCLOCK                  (0x00000000U)                 /*!< No clock */
#define RCC_BDCR_RTCSEL_LSE                      (0x00000100U)                 /*!< LSE oscillator clock used as RTC clock */
#define RCC_BDCR_RTCSEL_LSI                      (0x00000200U)                 /*!< LSI oscillator clock used as RTC clock */
#define RCC_BDCR_RTCSEL_HSE                      (0x00000300U)                 /*!< HSE oscillator clock divided by 128 used as RTC clock */

#define RCC_BDCR_RTCEN_Pos                       (15U)                         
#define RCC_BDCR_RTCEN_Msk                       (0x1UL << RCC_BDCR_RTCEN_Pos)  /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                           RCC_BDCR_RTCEN_Msk            /*!< RTC clock enable */
#define RCC_BDCR_BDRST_Pos                       (16U)                         
#define RCC_BDCR_BDRST_Msk                       (0x1UL << RCC_BDCR_BDRST_Pos)  /*!< 0x00010000 */
#define RCC_BDCR_BDRST                           RCC_BDCR_BDRST_Msk            /*!< Backup domain software reset  */

/*******************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                        (0U)                          
#define RCC_CSR_LSION_Msk                        (0x1UL << RCC_CSR_LSION_Pos)   /*!< 0x00000001 */
#define RCC_CSR_LSION                            RCC_CSR_LSION_Msk             /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY_Pos                       (1U)                          
#define RCC_CSR_LSIRDY_Msk                       (0x1UL << RCC_CSR_LSIRDY_Pos)  /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                           RCC_CSR_LSIRDY_Msk            /*!< Internal Low Speed oscillator Ready */
#define RCC_CSR_V18PWRRSTF_Pos                   (23U)                         
#define RCC_CSR_V18PWRRSTF_Msk                   (0x1UL << RCC_CSR_V18PWRRSTF_Pos) /*!< 0x00800000 */
#define RCC_CSR_V18PWRRSTF                       RCC_CSR_V18PWRRSTF_Msk        /*!< V1.8 power domain reset flag */
#define RCC_CSR_RMVF_Pos                         (24U)                         
#define RCC_CSR_RMVF_Msk                         (0x1UL << RCC_CSR_RMVF_Pos)    /*!< 0x01000000 */
#define RCC_CSR_RMVF                             RCC_CSR_RMVF_Msk              /*!< Remove reset flag */
#define RCC_CSR_OBLRSTF_Pos                      (25U)                         
#define RCC_CSR_OBLRSTF_Msk                      (0x1UL << RCC_CSR_OBLRSTF_Pos) /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                          RCC_CSR_OBLRSTF_Msk           /*!< OBL reset flag */
#define RCC_CSR_PINRSTF_Pos                      (26U)                         
#define RCC_CSR_PINRSTF_Msk                      (0x1UL << RCC_CSR_PINRSTF_Pos) /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                          RCC_CSR_PINRSTF_Msk           /*!< PIN reset flag */
#define RCC_CSR_PORRSTF_Pos                      (27U)                         
#define RCC_CSR_PORRSTF_Msk                      (0x1UL << RCC_CSR_PORRSTF_Pos) /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                          RCC_CSR_PORRSTF_Msk           /*!< POR/PDR reset flag */
#define RCC_CSR_SFTRSTF_Pos                      (28U)                         
#define RCC_CSR_SFTRSTF_Msk                      (0x1UL << RCC_CSR_SFTRSTF_Pos) /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                          RCC_CSR_SFTRSTF_Msk           /*!< Software Reset flag */
#define RCC_CSR_IWDGRSTF_Pos                     (29U)                         
#define RCC_CSR_IWDGRSTF_Msk                     (0x1UL << RCC_CSR_IWDGRSTF_Pos) /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                         RCC_CSR_IWDGRSTF_Msk          /*!< Independent Watchdog reset flag */
#define RCC_CSR_WWDGRSTF_Pos                     (30U)                         
#define RCC_CSR_WWDGRSTF_Msk                     (0x1UL << RCC_CSR_WWDGRSTF_Pos) /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                         RCC_CSR_WWDGRSTF_Msk          /*!< Window watchdog reset flag */
#define RCC_CSR_LPWRRSTF_Pos                     (31U)                         
#define RCC_CSR_LPWRRSTF_Msk                     (0x1UL << RCC_CSR_LPWRRSTF_Pos) /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                         RCC_CSR_LPWRRSTF_Msk          /*!< Low-Power reset flag */

/* Old Bit definition maintained for legacy purpose */
#define  RCC_CSR_OBL                         RCC_CSR_OBLRSTF        /*!< OBL reset flag */

/*******************  Bit definition for RCC_AHBRSTR register  ***************/
#define RCC_AHBRSTR_GPIOARST_Pos                 (17U)                         
#define RCC_AHBRSTR_GPIOARST_Msk                 (0x1UL << RCC_AHBRSTR_GPIOARST_Pos) /*!< 0x00020000 */
#define RCC_AHBRSTR_GPIOARST                     RCC_AHBRSTR_GPIOARST_Msk      /*!< GPIOA reset */
#define RCC_AHBRSTR_GPIOBRST_Pos                 (18U)                         
#define RCC_AHBRSTR_GPIOBRST_Msk                 (0x1UL << RCC_AHBRSTR_GPIOBRST_Pos) /*!< 0x00040000 */
#define RCC_AHBRSTR_GPIOBRST                     RCC_AHBRSTR_GPIOBRST_Msk      /*!< GPIOB reset */
#define RCC_AHBRSTR_GPIOCRST_Pos                 (19U)                         
#define RCC_AHBRSTR_GPIOCRST_Msk                 (0x1UL << RCC_AHBRSTR_GPIOCRST_Pos) /*!< 0x00080000 */
#define RCC_AHBRSTR_GPIOCRST                     RCC_AHBRSTR_GPIOCRST_Msk      /*!< GPIOC reset */
#define RCC_AHBRSTR_GPIODRST_Pos                 (20U)                         
#define RCC_AHBRSTR_GPIODRST_Msk                 (0x1UL << RCC_AHBRSTR_GPIODRST_Pos) /*!< 0x00100000 */
#define RCC_AHBRSTR_GPIODRST                     RCC_AHBRSTR_GPIODRST_Msk      /*!< GPIOD reset */
#define RCC_AHBRSTR_GPIOFRST_Pos                 (22U)                         
#define RCC_AHBRSTR_GPIOFRST_Msk                 (0x1UL << RCC_AHBRSTR_GPIOFRST_Pos) /*!< 0x00400000 */
#define RCC_AHBRSTR_GPIOFRST                     RCC_AHBRSTR_GPIOFRST_Msk      /*!< GPIOF reset */

/*******************  Bit definition for RCC_CFGR2 register  *****************/
/*!< PREDIV configuration */
#define RCC_CFGR2_PREDIV_Pos                     (0U)                          
#define RCC_CFGR2_PREDIV_Msk                     (0xFUL << RCC_CFGR2_PREDIV_Pos) /*!< 0x0000000F */
#define RCC_CFGR2_PREDIV                         RCC_CFGR2_PREDIV_Msk          /*!< PREDIV[3:0] bits */
#define RCC_CFGR2_PREDIV_0                       (0x1UL << RCC_CFGR2_PREDIV_Pos) /*!< 0x00000001 */
#define RCC_CFGR2_PREDIV_1                       (0x2UL << RCC_CFGR2_PREDIV_Pos) /*!< 0x00000002 */
#define RCC_CFGR2_PREDIV_2                       (0x4UL << RCC_CFGR2_PREDIV_Pos) /*!< 0x00000004 */
#define RCC_CFGR2_PREDIV_3                       (0x8UL << RCC_CFGR2_PREDIV_Pos) /*!< 0x00000008 */

#define RCC_CFGR2_PREDIV_DIV1                    (0x00000000U)                 /*!< PREDIV input clock not divided */
#define RCC_CFGR2_PREDIV_DIV2                    (0x00000001U)                 /*!< PREDIV input clock divided by 2 */
#define RCC_CFGR2_PREDIV_DIV3                    (0x00000002U)                 /*!< PREDIV input clock divided by 3 */
#define RCC_CFGR2_PREDIV_DIV4                    (0x00000003U)                 /*!< PREDIV input clock divided by 4 */
#define RCC_CFGR2_PREDIV_DIV5                    (0x00000004U)                 /*!< PREDIV input clock divided by 5 */
#define RCC_CFGR2_PREDIV_DIV6                    (0x00000005U)                 /*!< PREDIV input clock divided by 6 */
#define RCC_CFGR2_PREDIV_DIV7                    (0x00000006U)                 /*!< PREDIV input clock divided by 7 */
#define RCC_CFGR2_PREDIV_DIV8                    (0x00000007U)                 /*!< PREDIV input clock divided by 8 */
#define RCC_CFGR2_PREDIV_DIV9                    (0x00000008U)                 /*!< PREDIV input clock divided by 9 */
#define RCC_CFGR2_PREDIV_DIV10                   (0x00000009U)                 /*!< PREDIV input clock divided by 10 */
#define RCC_CFGR2_PREDIV_DIV11                   (0x0000000AU)                 /*!< PREDIV input clock divided by 11 */
#define RCC_CFGR2_PREDIV_DIV12                   (0x0000000BU)                 /*!< PREDIV input clock divided by 12 */
#define RCC_CFGR2_PREDIV_DIV13                   (0x0000000CU)                 /*!< PREDIV input clock divided by 13 */
#define RCC_CFGR2_PREDIV_DIV14                   (0x0000000DU)                 /*!< PREDIV input clock divided by 14 */
#define RCC_CFGR2_PREDIV_DIV15                   (0x0000000EU)                 /*!< PREDIV input clock divided by 15 */
#define RCC_CFGR2_PREDIV_DIV16                   (0x0000000FU)                 /*!< PREDIV input clock divided by 16 */

/*******************  Bit definition for RCC_CFGR3 register  *****************/
/*!< USART1 Clock source selection */
#define RCC_CFGR3_USART1SW_Pos                   (0U)                          
#define RCC_CFGR3_USART1SW_Msk                   (0x3UL << RCC_CFGR3_USART1SW_Pos) /*!< 0x00000003 */
#define RCC_CFGR3_USART1SW                       RCC_CFGR3_USART1SW_Msk        /*!< USART1SW[1:0] bits */
#define RCC_CFGR3_USART1SW_0                     (0x1UL << RCC_CFGR3_USART1SW_Pos) /*!< 0x00000001 */
#define RCC_CFGR3_USART1SW_1                     (0x2UL << RCC_CFGR3_USART1SW_Pos) /*!< 0x00000002 */

#define RCC_CFGR3_USART1SW_PCLK                  (0x00000000U)                 /*!< PCLK clock used as USART1 clock source */
#define RCC_CFGR3_USART1SW_SYSCLK                (0x00000001U)                 /*!< System clock selected as USART1 clock source */
#define RCC_CFGR3_USART1SW_LSE                   (0x00000002U)                 /*!< LSE oscillator clock used as USART1 clock source */
#define RCC_CFGR3_USART1SW_HSI                   (0x00000003U)                 /*!< HSI oscillator clock used as USART1 clock source */

/*!< I2C1 Clock source selection */
#define RCC_CFGR3_I2C1SW_Pos                     (4U)                          
#define RCC_CFGR3_I2C1SW_Msk                     (0x1UL << RCC_CFGR3_I2C1SW_Pos) /*!< 0x00000010 */
#define RCC_CFGR3_I2C1SW                         RCC_CFGR3_I2C1SW_Msk          /*!< I2C1SW bits */ 

#define RCC_CFGR3_I2C1SW_HSI                     (0x00000000U)                 /*!< HSI oscillator clock used as I2C1 clock source */
#define RCC_CFGR3_I2C1SW_SYSCLK_Pos              (4U)                          
#define RCC_CFGR3_I2C1SW_SYSCLK_Msk              (0x1UL << RCC_CFGR3_I2C1SW_SYSCLK_Pos) /*!< 0x00000010 */
#define RCC_CFGR3_I2C1SW_SYSCLK                  RCC_CFGR3_I2C1SW_SYSCLK_Msk   /*!< System clock selected as I2C1 clock source */

/*******************  Bit definition for RCC_CR2 register  *******************/
#define RCC_CR2_HSI14ON_Pos                      (0U)                          
#define RCC_CR2_HSI14ON_Msk                      (0x1UL << RCC_CR2_HSI14ON_Pos) /*!< 0x00000001 */
#define RCC_CR2_HSI14ON                          RCC_CR2_HSI14ON_Msk           /*!< Internal High Speed 14MHz clock enable */
#define RCC_CR2_HSI14RDY_Pos                     (1U)                          
#define RCC_CR2_HSI14RDY_Msk                     (0x1UL << RCC_CR2_HSI14RDY_Pos) /*!< 0x00000002 */
#define RCC_CR2_HSI14RDY                         RCC_CR2_HSI14RDY_Msk          /*!< Internal High Speed 14MHz clock ready flag */
#define RCC_CR2_HSI14DIS_Pos                     (2U)                          
#define RCC_CR2_HSI14DIS_Msk                     (0x1UL << RCC_CR2_HSI14DIS_Pos) /*!< 0x00000004 */
#define RCC_CR2_HSI14DIS                         RCC_CR2_HSI14DIS_Msk          /*!< Internal High Speed 14MHz clock disable */
#define RCC_CR2_HSI14TRIM_Pos                    (3U)                          
#define RCC_CR2_HSI14TRIM_Msk                    (0x1FUL << RCC_CR2_HSI14TRIM_Pos) /*!< 0x000000F8 */
#define RCC_CR2_HSI14TRIM                        RCC_CR2_HSI14TRIM_Msk         /*!< Internal High Speed 14MHz clock trimming */
#define RCC_CR2_HSI14CAL_Pos                     (8U)                          
#define RCC_CR2_HSI14CAL_Msk                     (0xFFUL << RCC_CR2_HSI14CAL_Pos) /*!< 0x0000FF00 */
#define RCC_CR2_HSI14CAL                         RCC_CR2_HSI14CAL_Msk          /*!< Internal High Speed 14MHz clock Calibration */

// 레지스터 목록
namespace RCC_REG
{
enum
{
	CR = 0, CFGR, CIR, APB2RSTR,
	APB1RSTR, AHBENR, APB2ENR, APB1ENR,
	BDCR, CSR, AHBRSTR
};
}

#endif

