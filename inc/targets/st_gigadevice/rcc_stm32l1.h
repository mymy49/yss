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
#ifndef __RCC_STM32_GD32F1__H_
#define __RCC_STM32_GD32F1__H_

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                      Reset and Clock Control (RCC)                         */
/*                                                                            */
/******************************************************************************/
/*
* @brief Specific device feature definitions  (not present on all devices in the STM32F0 serie)
*/
#define RCC_LSECSS_SUPPORT          /*!< LSE CSS feature support */

/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                    (0U)                               
#define RCC_CR_HSION_Msk                    (0x1UL << RCC_CR_HSION_Pos)         /*!< 0x00000001 */
#define RCC_CR_HSION                        RCC_CR_HSION_Msk                   /*!< Internal High Speed clock enable */
#define RCC_CR_HSIRDY_Pos                   (1U)                               
#define RCC_CR_HSIRDY_Msk                   (0x1UL << RCC_CR_HSIRDY_Pos)        /*!< 0x00000002 */
#define RCC_CR_HSIRDY                       RCC_CR_HSIRDY_Msk                  /*!< Internal High Speed clock ready flag */

#define RCC_CR_MSION_Pos                    (8U)                               
#define RCC_CR_MSION_Msk                    (0x1UL << RCC_CR_MSION_Pos)         /*!< 0x00000100 */
#define RCC_CR_MSION                        RCC_CR_MSION_Msk                   /*!< Internal Multi Speed clock enable */
#define RCC_CR_MSIRDY_Pos                   (9U)                               
#define RCC_CR_MSIRDY_Msk                   (0x1UL << RCC_CR_MSIRDY_Pos)        /*!< 0x00000200 */
#define RCC_CR_MSIRDY                       RCC_CR_MSIRDY_Msk                  /*!< Internal Multi Speed clock ready flag */

#define RCC_CR_HSEON_Pos                    (16U)                              
#define RCC_CR_HSEON_Msk                    (0x1UL << RCC_CR_HSEON_Pos)         /*!< 0x00010000 */
#define RCC_CR_HSEON                        RCC_CR_HSEON_Msk                   /*!< External High Speed clock enable */
#define RCC_CR_HSERDY_Pos                   (17U)                              
#define RCC_CR_HSERDY_Msk                   (0x1UL << RCC_CR_HSERDY_Pos)        /*!< 0x00020000 */
#define RCC_CR_HSERDY                       RCC_CR_HSERDY_Msk                  /*!< External High Speed clock ready flag */
#define RCC_CR_HSEBYP_Pos                   (18U)                              
#define RCC_CR_HSEBYP_Msk                   (0x1UL << RCC_CR_HSEBYP_Pos)        /*!< 0x00040000 */
#define RCC_CR_HSEBYP                       RCC_CR_HSEBYP_Msk                  /*!< External High Speed clock Bypass */

#define RCC_CR_PLLON_Pos                    (24U)                              
#define RCC_CR_PLLON_Msk                    (0x1UL << RCC_CR_PLLON_Pos)         /*!< 0x01000000 */
#define RCC_CR_PLLON                        RCC_CR_PLLON_Msk                   /*!< PLL enable */
#define RCC_CR_PLLRDY_Pos                   (25U)                              
#define RCC_CR_PLLRDY_Msk                   (0x1UL << RCC_CR_PLLRDY_Pos)        /*!< 0x02000000 */
#define RCC_CR_PLLRDY                       RCC_CR_PLLRDY_Msk                  /*!< PLL clock ready flag */
#define RCC_CR_CSSON_Pos                    (28U)                              
#define RCC_CR_CSSON_Msk                    (0x1UL << RCC_CR_CSSON_Pos)         /*!< 0x10000000 */
#define RCC_CR_CSSON                        RCC_CR_CSSON_Msk                   /*!< Clock Security System enable */

#define RCC_CR_RTCPRE_Pos                   (29U)                              
#define RCC_CR_RTCPRE_Msk                   (0x3UL << RCC_CR_RTCPRE_Pos)        /*!< 0x60000000 */
#define RCC_CR_RTCPRE                       RCC_CR_RTCPRE_Msk                  /*!< RTC/LCD Prescaler */
#define RCC_CR_RTCPRE_0                     (0x20000000U)                      /*!< Bit0 */
#define RCC_CR_RTCPRE_1                     (0x40000000U)                      /*!< Bit1 */

/********************  Bit definition for RCC_ICSCR register  *****************/
#define RCC_ICSCR_HSICAL_Pos                (0U)                               
#define RCC_ICSCR_HSICAL_Msk                (0xFFUL << RCC_ICSCR_HSICAL_Pos)    /*!< 0x000000FF */
#define RCC_ICSCR_HSICAL                    RCC_ICSCR_HSICAL_Msk               /*!< Internal High Speed clock Calibration */
#define RCC_ICSCR_HSITRIM_Pos               (8U)                               
#define RCC_ICSCR_HSITRIM_Msk               (0x1FUL << RCC_ICSCR_HSITRIM_Pos)   /*!< 0x00001F00 */
#define RCC_ICSCR_HSITRIM                   RCC_ICSCR_HSITRIM_Msk              /*!< Internal High Speed clock trimming */

#define RCC_ICSCR_MSIRANGE_Pos              (13U)                              
#define RCC_ICSCR_MSIRANGE_Msk              (0x7UL << RCC_ICSCR_MSIRANGE_Pos)   /*!< 0x0000E000 */
#define RCC_ICSCR_MSIRANGE                  RCC_ICSCR_MSIRANGE_Msk             /*!< Internal Multi Speed clock Range */
#define RCC_ICSCR_MSIRANGE_0                (0x0UL << RCC_ICSCR_MSIRANGE_Pos)   /*!< 0x00000000 */
#define RCC_ICSCR_MSIRANGE_1                (0x1UL << RCC_ICSCR_MSIRANGE_Pos)   /*!< 0x00002000 */
#define RCC_ICSCR_MSIRANGE_2                (0x2UL << RCC_ICSCR_MSIRANGE_Pos)   /*!< 0x00004000 */
#define RCC_ICSCR_MSIRANGE_3                (0x3UL << RCC_ICSCR_MSIRANGE_Pos)   /*!< 0x00006000 */
#define RCC_ICSCR_MSIRANGE_4                (0x4UL << RCC_ICSCR_MSIRANGE_Pos)   /*!< 0x00008000 */
#define RCC_ICSCR_MSIRANGE_5                (0x5UL << RCC_ICSCR_MSIRANGE_Pos)   /*!< 0x0000A000 */
#define RCC_ICSCR_MSIRANGE_6                (0x6UL << RCC_ICSCR_MSIRANGE_Pos)   /*!< 0x0000C000 */
#define RCC_ICSCR_MSICAL_Pos                (16U)                              
#define RCC_ICSCR_MSICAL_Msk                (0xFFUL << RCC_ICSCR_MSICAL_Pos)    /*!< 0x00FF0000 */
#define RCC_ICSCR_MSICAL                    RCC_ICSCR_MSICAL_Msk               /*!< Internal Multi Speed clock Calibration */
#define RCC_ICSCR_MSITRIM_Pos               (24U)                              
#define RCC_ICSCR_MSITRIM_Msk               (0xFFUL << RCC_ICSCR_MSITRIM_Pos)   /*!< 0xFF000000 */
#define RCC_ICSCR_MSITRIM                   RCC_ICSCR_MSITRIM_Msk              /*!< Internal Multi Speed clock trimming */

/********************  Bit definition for RCC_CFGR register  ******************/
#define RCC_CFGR_SW_Pos                     (0U)                               
#define RCC_CFGR_SW_Msk                     (0x3UL << RCC_CFGR_SW_Pos)          /*!< 0x00000003 */
#define RCC_CFGR_SW                         RCC_CFGR_SW_Msk                    /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                       (0x1UL << RCC_CFGR_SW_Pos)          /*!< 0x00000001 */
#define RCC_CFGR_SW_1                       (0x2UL << RCC_CFGR_SW_Pos)          /*!< 0x00000002 */

/*!< SW configuration */
#define RCC_CFGR_SW_MSI                     (0x00000000U)                      /*!< MSI selected as system clock */
#define RCC_CFGR_SW_HSI                     (0x00000001U)                      /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                     (0x00000002U)                      /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                     (0x00000003U)                      /*!< PLL selected as system clock */

#define RCC_CFGR_SWS_Pos                    (2U)                               
#define RCC_CFGR_SWS_Msk                    (0x3UL << RCC_CFGR_SWS_Pos)         /*!< 0x0000000C */
#define RCC_CFGR_SWS                        RCC_CFGR_SWS_Msk                   /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                      (0x1UL << RCC_CFGR_SWS_Pos)         /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                      (0x2UL << RCC_CFGR_SWS_Pos)         /*!< 0x00000008 */

/*!< SWS configuration */
#define RCC_CFGR_SWS_MSI                    (0x00000000U)                      /*!< MSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSI                    (0x00000004U)                      /*!< HSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSE                    (0x00000008U)                      /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL                    (0x0000000CU)                      /*!< PLL used as system clock */

#define RCC_CFGR_HPRE_Pos                   (4U)                               
#define RCC_CFGR_HPRE_Msk                   (0xFUL << RCC_CFGR_HPRE_Pos)        /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                       RCC_CFGR_HPRE_Msk                  /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                     (0x1UL << RCC_CFGR_HPRE_Pos)        /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                     (0x2UL << RCC_CFGR_HPRE_Pos)        /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                     (0x4UL << RCC_CFGR_HPRE_Pos)        /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                     (0x8UL << RCC_CFGR_HPRE_Pos)        /*!< 0x00000080 */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_DIV1                  (0x00000000U)                      /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2                  (0x00000080U)                      /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4                  (0x00000090U)                      /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8                  (0x000000A0U)                      /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16                 (0x000000B0U)                      /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64                 (0x000000C0U)                      /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128                (0x000000D0U)                      /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256                (0x000000E0U)                      /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512                (0x000000F0U)                      /*!< SYSCLK divided by 512 */

#define RCC_CFGR_PPRE1_Pos                  (8U)                               
#define RCC_CFGR_PPRE1_Msk                  (0x7UL << RCC_CFGR_PPRE1_Pos)       /*!< 0x00000700 */
#define RCC_CFGR_PPRE1                      RCC_CFGR_PPRE1_Msk                 /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                    (0x1UL << RCC_CFGR_PPRE1_Pos)       /*!< 0x00000100 */
#define RCC_CFGR_PPRE1_1                    (0x2UL << RCC_CFGR_PPRE1_Pos)       /*!< 0x00000200 */
#define RCC_CFGR_PPRE1_2                    (0x4UL << RCC_CFGR_PPRE1_Pos)       /*!< 0x00000400 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_DIV1                 (0x00000000U)                      /*!< HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2                 (0x00000400U)                      /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4                 (0x00000500U)                      /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8                 (0x00000600U)                      /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16                (0x00000700U)                      /*!< HCLK divided by 16 */

#define RCC_CFGR_PPRE2_Pos                  (11U)                              
#define RCC_CFGR_PPRE2_Msk                  (0x7UL << RCC_CFGR_PPRE2_Pos)       /*!< 0x00003800 */
#define RCC_CFGR_PPRE2                      RCC_CFGR_PPRE2_Msk                 /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                    (0x1UL << RCC_CFGR_PPRE2_Pos)       /*!< 0x00000800 */
#define RCC_CFGR_PPRE2_1                    (0x2UL << RCC_CFGR_PPRE2_Pos)       /*!< 0x00001000 */
#define RCC_CFGR_PPRE2_2                    (0x4UL << RCC_CFGR_PPRE2_Pos)       /*!< 0x00002000 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_DIV1                 (0x00000000U)                      /*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2                 (0x00002000U)                      /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4                 (0x00002800U)                      /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8                 (0x00003000U)                      /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16                (0x00003800U)                      /*!< HCLK divided by 16 */

/*!< PLL entry clock source*/
#define RCC_CFGR_PLLSRC_Pos                 (16U)                              
#define RCC_CFGR_PLLSRC_Msk                 (0x1UL << RCC_CFGR_PLLSRC_Pos)      /*!< 0x00010000 */
#define RCC_CFGR_PLLSRC                     RCC_CFGR_PLLSRC_Msk                /*!< PLL entry clock source */

#define RCC_CFGR_PLLSRC_HSI                 (0x00000000U)                      /*!< HSI as PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSE                 (0x00010000U)                      /*!< HSE as PLL entry clock source */


/*!< PLLMUL configuration */
#define RCC_CFGR_PLLMUL_Pos                 (18U)                              
#define RCC_CFGR_PLLMUL_Msk                 (0xFUL << RCC_CFGR_PLLMUL_Pos)      /*!< 0x003C0000 */
#define RCC_CFGR_PLLMUL                     RCC_CFGR_PLLMUL_Msk                /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define RCC_CFGR_PLLMUL_0                   (0x1UL << RCC_CFGR_PLLMUL_Pos)      /*!< 0x00040000 */
#define RCC_CFGR_PLLMUL_1                   (0x2UL << RCC_CFGR_PLLMUL_Pos)      /*!< 0x00080000 */
#define RCC_CFGR_PLLMUL_2                   (0x4UL << RCC_CFGR_PLLMUL_Pos)      /*!< 0x00100000 */
#define RCC_CFGR_PLLMUL_3                   (0x8UL << RCC_CFGR_PLLMUL_Pos)      /*!< 0x00200000 */

/*!< PLLMUL configuration */
#define RCC_CFGR_PLLMUL3                    (0x00000000U)                      /*!< PLL input clock * 3 */
#define RCC_CFGR_PLLMUL4                    (0x00040000U)                      /*!< PLL input clock * 4 */
#define RCC_CFGR_PLLMUL6                    (0x00080000U)                      /*!< PLL input clock * 6 */
#define RCC_CFGR_PLLMUL8                    (0x000C0000U)                      /*!< PLL input clock * 8 */
#define RCC_CFGR_PLLMUL12                   (0x00100000U)                      /*!< PLL input clock * 12 */
#define RCC_CFGR_PLLMUL16                   (0x00140000U)                      /*!< PLL input clock * 16 */
#define RCC_CFGR_PLLMUL24                   (0x00180000U)                      /*!< PLL input clock * 24 */
#define RCC_CFGR_PLLMUL32                   (0x001C0000U)                      /*!< PLL input clock * 32 */
#define RCC_CFGR_PLLMUL48                   (0x00200000U)                      /*!< PLL input clock * 48 */

/*!< PLLDIV configuration */
#define RCC_CFGR_PLLDIV_Pos                 (22U)                              
#define RCC_CFGR_PLLDIV_Msk                 (0x3UL << RCC_CFGR_PLLDIV_Pos)      /*!< 0x00C00000 */
#define RCC_CFGR_PLLDIV                     RCC_CFGR_PLLDIV_Msk                /*!< PLLDIV[1:0] bits (PLL Output Division) */
#define RCC_CFGR_PLLDIV_0                   (0x1UL << RCC_CFGR_PLLDIV_Pos)      /*!< 0x00400000 */
#define RCC_CFGR_PLLDIV_1                   (0x2UL << RCC_CFGR_PLLDIV_Pos)      /*!< 0x00800000 */


/*!< PLLDIV configuration */
#define RCC_CFGR_PLLDIV1                    (0x00000000U)                      /*!< PLL clock output = CKVCO / 1 */
#define RCC_CFGR_PLLDIV2_Pos                (22U)                              
#define RCC_CFGR_PLLDIV2_Msk                (0x1UL << RCC_CFGR_PLLDIV2_Pos)     /*!< 0x00400000 */
#define RCC_CFGR_PLLDIV2                    RCC_CFGR_PLLDIV2_Msk               /*!< PLL clock output = CKVCO / 2 */
#define RCC_CFGR_PLLDIV3_Pos                (23U)                              
#define RCC_CFGR_PLLDIV3_Msk                (0x1UL << RCC_CFGR_PLLDIV3_Pos)     /*!< 0x00800000 */
#define RCC_CFGR_PLLDIV3                    RCC_CFGR_PLLDIV3_Msk               /*!< PLL clock output = CKVCO / 3 */
#define RCC_CFGR_PLLDIV4_Pos                (22U)                              
#define RCC_CFGR_PLLDIV4_Msk                (0x3UL << RCC_CFGR_PLLDIV4_Pos)     /*!< 0x00C00000 */
#define RCC_CFGR_PLLDIV4                    RCC_CFGR_PLLDIV4_Msk               /*!< PLL clock output = CKVCO / 4 */


#define RCC_CFGR_MCOSEL_Pos                 (24U)                              
#define RCC_CFGR_MCOSEL_Msk                 (0x7UL << RCC_CFGR_MCOSEL_Pos)      /*!< 0x07000000 */
#define RCC_CFGR_MCOSEL                     RCC_CFGR_MCOSEL_Msk                /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define RCC_CFGR_MCOSEL_0                   (0x1UL << RCC_CFGR_MCOSEL_Pos)      /*!< 0x01000000 */
#define RCC_CFGR_MCOSEL_1                   (0x2UL << RCC_CFGR_MCOSEL_Pos)      /*!< 0x02000000 */
#define RCC_CFGR_MCOSEL_2                   (0x4UL << RCC_CFGR_MCOSEL_Pos)      /*!< 0x04000000 */

/*!< MCO configuration */
#define RCC_CFGR_MCOSEL_NOCLOCK             (0x00000000U)                      /*!< No clock */
#define RCC_CFGR_MCOSEL_SYSCLK_Pos          (24U)                              
#define RCC_CFGR_MCOSEL_SYSCLK_Msk          (0x1UL << RCC_CFGR_MCOSEL_SYSCLK_Pos) /*!< 0x01000000 */
#define RCC_CFGR_MCOSEL_SYSCLK              RCC_CFGR_MCOSEL_SYSCLK_Msk         /*!< System clock selected */
#define RCC_CFGR_MCOSEL_HSI_Pos             (25U)                              
#define RCC_CFGR_MCOSEL_HSI_Msk             (0x1UL << RCC_CFGR_MCOSEL_HSI_Pos)  /*!< 0x02000000 */
#define RCC_CFGR_MCOSEL_HSI                 RCC_CFGR_MCOSEL_HSI_Msk            /*!< Internal 16 MHz RC oscillator clock selected */
#define RCC_CFGR_MCOSEL_MSI_Pos             (24U)                              
#define RCC_CFGR_MCOSEL_MSI_Msk             (0x3UL << RCC_CFGR_MCOSEL_MSI_Pos)  /*!< 0x03000000 */
#define RCC_CFGR_MCOSEL_MSI                 RCC_CFGR_MCOSEL_MSI_Msk            /*!< Internal Medium Speed RC oscillator clock selected */
#define RCC_CFGR_MCOSEL_HSE_Pos             (26U)                              
#define RCC_CFGR_MCOSEL_HSE_Msk             (0x1UL << RCC_CFGR_MCOSEL_HSE_Pos)  /*!< 0x04000000 */
#define RCC_CFGR_MCOSEL_HSE                 RCC_CFGR_MCOSEL_HSE_Msk            /*!< External 1-25 MHz oscillator clock selected */
#define RCC_CFGR_MCOSEL_PLL_Pos             (24U)                              
#define RCC_CFGR_MCOSEL_PLL_Msk             (0x5UL << RCC_CFGR_MCOSEL_PLL_Pos)  /*!< 0x05000000 */
#define RCC_CFGR_MCOSEL_PLL                 RCC_CFGR_MCOSEL_PLL_Msk            /*!< PLL clock divided */
#define RCC_CFGR_MCOSEL_LSI_Pos             (25U)                              
#define RCC_CFGR_MCOSEL_LSI_Msk             (0x3UL << RCC_CFGR_MCOSEL_LSI_Pos)  /*!< 0x06000000 */
#define RCC_CFGR_MCOSEL_LSI                 RCC_CFGR_MCOSEL_LSI_Msk            /*!< LSI selected */
#define RCC_CFGR_MCOSEL_LSE_Pos             (24U)                              
#define RCC_CFGR_MCOSEL_LSE_Msk             (0x7UL << RCC_CFGR_MCOSEL_LSE_Pos)  /*!< 0x07000000 */
#define RCC_CFGR_MCOSEL_LSE                 RCC_CFGR_MCOSEL_LSE_Msk            /*!< LSE selected */

#define RCC_CFGR_MCOPRE_Pos                 (28U)                              
#define RCC_CFGR_MCOPRE_Msk                 (0x7UL << RCC_CFGR_MCOPRE_Pos)      /*!< 0x70000000 */
#define RCC_CFGR_MCOPRE                     RCC_CFGR_MCOPRE_Msk                /*!< MCOPRE[2:0] bits (Microcontroller Clock Output Prescaler) */
#define RCC_CFGR_MCOPRE_0                   (0x1UL << RCC_CFGR_MCOPRE_Pos)      /*!< 0x10000000 */
#define RCC_CFGR_MCOPRE_1                   (0x2UL << RCC_CFGR_MCOPRE_Pos)      /*!< 0x20000000 */
#define RCC_CFGR_MCOPRE_2                   (0x4UL << RCC_CFGR_MCOPRE_Pos)      /*!< 0x40000000 */

/*!< MCO Prescaler configuration */ 
#define RCC_CFGR_MCOPRE_DIV1                (0x00000000U)                      /*!< MCO is divided by 1 */
#define RCC_CFGR_MCOPRE_DIV2                (0x10000000U)                      /*!< MCO is divided by 2 */
#define RCC_CFGR_MCOPRE_DIV4                (0x20000000U)                      /*!< MCO is divided by 4 */
#define RCC_CFGR_MCOPRE_DIV8                (0x30000000U)                      /*!< MCO is divided by 8 */
#define RCC_CFGR_MCOPRE_DIV16               (0x40000000U)                      /*!< MCO is divided by 16 */
 
/* Legacy aliases */
#define  RCC_CFGR_MCO_DIV1                  RCC_CFGR_MCOPRE_DIV1
#define  RCC_CFGR_MCO_DIV2                  RCC_CFGR_MCOPRE_DIV2
#define  RCC_CFGR_MCO_DIV4                  RCC_CFGR_MCOPRE_DIV4
#define  RCC_CFGR_MCO_DIV8                  RCC_CFGR_MCOPRE_DIV8
#define  RCC_CFGR_MCO_DIV16                 RCC_CFGR_MCOPRE_DIV16
#define  RCC_CFGR_MCO_NOCLOCK               RCC_CFGR_MCOSEL_NOCLOCK
#define  RCC_CFGR_MCO_SYSCLK                RCC_CFGR_MCOSEL_SYSCLK
#define  RCC_CFGR_MCO_HSI                   RCC_CFGR_MCOSEL_HSI
#define  RCC_CFGR_MCO_MSI                   RCC_CFGR_MCOSEL_MSI
#define  RCC_CFGR_MCO_HSE                   RCC_CFGR_MCOSEL_HSE
#define  RCC_CFGR_MCO_PLL                   RCC_CFGR_MCOSEL_PLL
#define  RCC_CFGR_MCO_LSI                   RCC_CFGR_MCOSEL_LSI
#define  RCC_CFGR_MCO_LSE                   RCC_CFGR_MCOSEL_LSE

/*!<******************  Bit definition for RCC_CIR register  ********************/
#define RCC_CIR_LSIRDYF_Pos                 (0U)                               
#define RCC_CIR_LSIRDYF_Msk                 (0x1UL << RCC_CIR_LSIRDYF_Pos)      /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF                     RCC_CIR_LSIRDYF_Msk                /*!< LSI Ready Interrupt flag */
#define RCC_CIR_LSERDYF_Pos                 (1U)                               
#define RCC_CIR_LSERDYF_Msk                 (0x1UL << RCC_CIR_LSERDYF_Pos)      /*!< 0x00000002 */
#define RCC_CIR_LSERDYF                     RCC_CIR_LSERDYF_Msk                /*!< LSE Ready Interrupt flag */
#define RCC_CIR_HSIRDYF_Pos                 (2U)                               
#define RCC_CIR_HSIRDYF_Msk                 (0x1UL << RCC_CIR_HSIRDYF_Pos)      /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF                     RCC_CIR_HSIRDYF_Msk                /*!< HSI Ready Interrupt flag */
#define RCC_CIR_HSERDYF_Pos                 (3U)                               
#define RCC_CIR_HSERDYF_Msk                 (0x1UL << RCC_CIR_HSERDYF_Pos)      /*!< 0x00000008 */
#define RCC_CIR_HSERDYF                     RCC_CIR_HSERDYF_Msk                /*!< HSE Ready Interrupt flag */
#define RCC_CIR_PLLRDYF_Pos                 (4U)                               
#define RCC_CIR_PLLRDYF_Msk                 (0x1UL << RCC_CIR_PLLRDYF_Pos)      /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF                     RCC_CIR_PLLRDYF_Msk                /*!< PLL Ready Interrupt flag */
#define RCC_CIR_MSIRDYF_Pos                 (5U)                               
#define RCC_CIR_MSIRDYF_Msk                 (0x1UL << RCC_CIR_MSIRDYF_Pos)      /*!< 0x00000020 */
#define RCC_CIR_MSIRDYF                     RCC_CIR_MSIRDYF_Msk                /*!< MSI Ready Interrupt flag */
#define RCC_CIR_LSECSSF_Pos                 (6U)                               
#define RCC_CIR_LSECSSF_Msk                 (0x1UL << RCC_CIR_LSECSSF_Pos)      /*!< 0x00000040 */
#define RCC_CIR_LSECSSF                     RCC_CIR_LSECSSF_Msk                /*!< LSE CSS Interrupt flag */
#define RCC_CIR_CSSF_Pos                    (7U)                               
#define RCC_CIR_CSSF_Msk                    (0x1UL << RCC_CIR_CSSF_Pos)         /*!< 0x00000080 */
#define RCC_CIR_CSSF                        RCC_CIR_CSSF_Msk                   /*!< Clock Security System Interrupt flag */

#define RCC_CIR_LSIRDYIE_Pos                (8U)                               
#define RCC_CIR_LSIRDYIE_Msk                (0x1UL << RCC_CIR_LSIRDYIE_Pos)     /*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE                    RCC_CIR_LSIRDYIE_Msk               /*!< LSI Ready Interrupt Enable */
#define RCC_CIR_LSERDYIE_Pos                (9U)                               
#define RCC_CIR_LSERDYIE_Msk                (0x1UL << RCC_CIR_LSERDYIE_Pos)     /*!< 0x00000200 */
#define RCC_CIR_LSERDYIE                    RCC_CIR_LSERDYIE_Msk               /*!< LSE Ready Interrupt Enable */
#define RCC_CIR_HSIRDYIE_Pos                (10U)                              
#define RCC_CIR_HSIRDYIE_Msk                (0x1UL << RCC_CIR_HSIRDYIE_Pos)     /*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE                    RCC_CIR_HSIRDYIE_Msk               /*!< HSI Ready Interrupt Enable */
#define RCC_CIR_HSERDYIE_Pos                (11U)                              
#define RCC_CIR_HSERDYIE_Msk                (0x1UL << RCC_CIR_HSERDYIE_Pos)     /*!< 0x00000800 */
#define RCC_CIR_HSERDYIE                    RCC_CIR_HSERDYIE_Msk               /*!< HSE Ready Interrupt Enable */
#define RCC_CIR_PLLRDYIE_Pos                (12U)                              
#define RCC_CIR_PLLRDYIE_Msk                (0x1UL << RCC_CIR_PLLRDYIE_Pos)     /*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE                    RCC_CIR_PLLRDYIE_Msk               /*!< PLL Ready Interrupt Enable */
#define RCC_CIR_MSIRDYIE_Pos                (13U)                              
#define RCC_CIR_MSIRDYIE_Msk                (0x1UL << RCC_CIR_MSIRDYIE_Pos)     /*!< 0x00002000 */
#define RCC_CIR_MSIRDYIE                    RCC_CIR_MSIRDYIE_Msk               /*!< MSI Ready Interrupt Enable */
#define RCC_CIR_LSECSSIE_Pos                (14U)                              
#define RCC_CIR_LSECSSIE_Msk                (0x1UL << RCC_CIR_LSECSSIE_Pos)     /*!< 0x00004000 */
#define RCC_CIR_LSECSSIE                    RCC_CIR_LSECSSIE_Msk               /*!< LSE CSS Interrupt Enable */

#define RCC_CIR_LSIRDYC_Pos                 (16U)                              
#define RCC_CIR_LSIRDYC_Msk                 (0x1UL << RCC_CIR_LSIRDYC_Pos)      /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC                     RCC_CIR_LSIRDYC_Msk                /*!< LSI Ready Interrupt Clear */
#define RCC_CIR_LSERDYC_Pos                 (17U)                              
#define RCC_CIR_LSERDYC_Msk                 (0x1UL << RCC_CIR_LSERDYC_Pos)      /*!< 0x00020000 */
#define RCC_CIR_LSERDYC                     RCC_CIR_LSERDYC_Msk                /*!< LSE Ready Interrupt Clear */
#define RCC_CIR_HSIRDYC_Pos                 (18U)                              
#define RCC_CIR_HSIRDYC_Msk                 (0x1UL << RCC_CIR_HSIRDYC_Pos)      /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC                     RCC_CIR_HSIRDYC_Msk                /*!< HSI Ready Interrupt Clear */
#define RCC_CIR_HSERDYC_Pos                 (19U)                              
#define RCC_CIR_HSERDYC_Msk                 (0x1UL << RCC_CIR_HSERDYC_Pos)      /*!< 0x00080000 */
#define RCC_CIR_HSERDYC                     RCC_CIR_HSERDYC_Msk                /*!< HSE Ready Interrupt Clear */
#define RCC_CIR_PLLRDYC_Pos                 (20U)                              
#define RCC_CIR_PLLRDYC_Msk                 (0x1UL << RCC_CIR_PLLRDYC_Pos)      /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC                     RCC_CIR_PLLRDYC_Msk                /*!< PLL Ready Interrupt Clear */
#define RCC_CIR_MSIRDYC_Pos                 (21U)                              
#define RCC_CIR_MSIRDYC_Msk                 (0x1UL << RCC_CIR_MSIRDYC_Pos)      /*!< 0x00200000 */
#define RCC_CIR_MSIRDYC                     RCC_CIR_MSIRDYC_Msk                /*!< MSI Ready Interrupt Clear */
#define RCC_CIR_LSECSSC_Pos                 (22U)                              
#define RCC_CIR_LSECSSC_Msk                 (0x1UL << RCC_CIR_LSECSSC_Pos)      /*!< 0x00400000 */
#define RCC_CIR_LSECSSC                     RCC_CIR_LSECSSC_Msk                /*!< LSE CSS Interrupt Clear */
#define RCC_CIR_CSSC_Pos                    (23U)                              
#define RCC_CIR_CSSC_Msk                    (0x1UL << RCC_CIR_CSSC_Pos)         /*!< 0x00800000 */
#define RCC_CIR_CSSC                        RCC_CIR_CSSC_Msk                   /*!< Clock Security System Interrupt Clear */

/*****************  Bit definition for RCC_AHBRSTR register  ******************/
#define RCC_AHBRSTR_GPIOARST_Pos            (0U)                               
#define RCC_AHBRSTR_GPIOARST_Msk            (0x1UL << RCC_AHBRSTR_GPIOARST_Pos) /*!< 0x00000001 */
#define RCC_AHBRSTR_GPIOARST                RCC_AHBRSTR_GPIOARST_Msk           /*!< GPIO port A reset */
#define RCC_AHBRSTR_GPIOBRST_Pos            (1U)                               
#define RCC_AHBRSTR_GPIOBRST_Msk            (0x1UL << RCC_AHBRSTR_GPIOBRST_Pos) /*!< 0x00000002 */
#define RCC_AHBRSTR_GPIOBRST                RCC_AHBRSTR_GPIOBRST_Msk           /*!< GPIO port B reset */
#define RCC_AHBRSTR_GPIOCRST_Pos            (2U)                               
#define RCC_AHBRSTR_GPIOCRST_Msk            (0x1UL << RCC_AHBRSTR_GPIOCRST_Pos) /*!< 0x00000004 */
#define RCC_AHBRSTR_GPIOCRST                RCC_AHBRSTR_GPIOCRST_Msk           /*!< GPIO port C reset */
#define RCC_AHBRSTR_GPIODRST_Pos            (3U)                               
#define RCC_AHBRSTR_GPIODRST_Msk            (0x1UL << RCC_AHBRSTR_GPIODRST_Pos) /*!< 0x00000008 */
#define RCC_AHBRSTR_GPIODRST                RCC_AHBRSTR_GPIODRST_Msk           /*!< GPIO port D reset */
#define RCC_AHBRSTR_GPIOERST_Pos            (4U)                               
#define RCC_AHBRSTR_GPIOERST_Msk            (0x1UL << RCC_AHBRSTR_GPIOERST_Pos) /*!< 0x00000010 */
#define RCC_AHBRSTR_GPIOERST                RCC_AHBRSTR_GPIOERST_Msk           /*!< GPIO port E reset */
#define RCC_AHBRSTR_GPIOHRST_Pos            (5U)                               
#define RCC_AHBRSTR_GPIOHRST_Msk            (0x1UL << RCC_AHBRSTR_GPIOHRST_Pos) /*!< 0x00000020 */
#define RCC_AHBRSTR_GPIOHRST                RCC_AHBRSTR_GPIOHRST_Msk           /*!< GPIO port H reset */
#define RCC_AHBRSTR_GPIOFRST_Pos            (6U)                               
#define RCC_AHBRSTR_GPIOFRST_Msk            (0x1UL << RCC_AHBRSTR_GPIOFRST_Pos) /*!< 0x00000040 */
#define RCC_AHBRSTR_GPIOFRST                RCC_AHBRSTR_GPIOFRST_Msk           /*!< GPIO port F reset */
#define RCC_AHBRSTR_GPIOGRST_Pos            (7U)                               
#define RCC_AHBRSTR_GPIOGRST_Msk            (0x1UL << RCC_AHBRSTR_GPIOGRST_Pos) /*!< 0x00000080 */
#define RCC_AHBRSTR_GPIOGRST                RCC_AHBRSTR_GPIOGRST_Msk           /*!< GPIO port G reset */
#define RCC_AHBRSTR_CRCRST_Pos              (12U)                              
#define RCC_AHBRSTR_CRCRST_Msk              (0x1UL << RCC_AHBRSTR_CRCRST_Pos)   /*!< 0x00001000 */
#define RCC_AHBRSTR_CRCRST                  RCC_AHBRSTR_CRCRST_Msk             /*!< CRC reset */
#define RCC_AHBRSTR_FLITFRST_Pos            (15U)                              
#define RCC_AHBRSTR_FLITFRST_Msk            (0x1UL << RCC_AHBRSTR_FLITFRST_Pos) /*!< 0x00008000 */
#define RCC_AHBRSTR_FLITFRST                RCC_AHBRSTR_FLITFRST_Msk           /*!< FLITF reset */
#define RCC_AHBRSTR_DMA1RST_Pos             (24U)                              
#define RCC_AHBRSTR_DMA1RST_Msk             (0x1UL << RCC_AHBRSTR_DMA1RST_Pos)  /*!< 0x01000000 */
#define RCC_AHBRSTR_DMA1RST                 RCC_AHBRSTR_DMA1RST_Msk            /*!< DMA1 reset */
#define RCC_AHBRSTR_DMA2RST_Pos             (25U)                              
#define RCC_AHBRSTR_DMA2RST_Msk             (0x1UL << RCC_AHBRSTR_DMA2RST_Pos)  /*!< 0x02000000 */
#define RCC_AHBRSTR_DMA2RST                 RCC_AHBRSTR_DMA2RST_Msk            /*!< DMA2 reset */
 
/*****************  Bit definition for RCC_APB2RSTR register  *****************/
#define RCC_APB2RSTR_SYSCFGRST_Pos          (0U)                               
#define RCC_APB2RSTR_SYSCFGRST_Msk          (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos) /*!< 0x00000001 */
#define RCC_APB2RSTR_SYSCFGRST              RCC_APB2RSTR_SYSCFGRST_Msk         /*!< System Configuration SYSCFG reset */
#define RCC_APB2RSTR_TIM9RST_Pos            (2U)                               
#define RCC_APB2RSTR_TIM9RST_Msk            (0x1UL << RCC_APB2RSTR_TIM9RST_Pos) /*!< 0x00000004 */
#define RCC_APB2RSTR_TIM9RST                RCC_APB2RSTR_TIM9RST_Msk           /*!< TIM9 reset */
#define RCC_APB2RSTR_TIM10RST_Pos           (3U)                               
#define RCC_APB2RSTR_TIM10RST_Msk           (0x1UL << RCC_APB2RSTR_TIM10RST_Pos) /*!< 0x00000008 */
#define RCC_APB2RSTR_TIM10RST               RCC_APB2RSTR_TIM10RST_Msk          /*!< TIM10 reset */
#define RCC_APB2RSTR_TIM11RST_Pos           (4U)                               
#define RCC_APB2RSTR_TIM11RST_Msk           (0x1UL << RCC_APB2RSTR_TIM11RST_Pos) /*!< 0x00000010 */
#define RCC_APB2RSTR_TIM11RST               RCC_APB2RSTR_TIM11RST_Msk          /*!< TIM11 reset */
#define RCC_APB2RSTR_ADC1RST_Pos            (9U)                               
#define RCC_APB2RSTR_ADC1RST_Msk            (0x1UL << RCC_APB2RSTR_ADC1RST_Pos) /*!< 0x00000200 */
#define RCC_APB2RSTR_ADC1RST                RCC_APB2RSTR_ADC1RST_Msk           /*!< ADC1 reset */
#define RCC_APB2RSTR_SPI1RST_Pos            (12U)                              
#define RCC_APB2RSTR_SPI1RST_Msk            (0x1UL << RCC_APB2RSTR_SPI1RST_Pos) /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST                RCC_APB2RSTR_SPI1RST_Msk           /*!< SPI1 reset */
#define RCC_APB2RSTR_USART1RST_Pos          (14U)                              
#define RCC_APB2RSTR_USART1RST_Msk          (0x1UL << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST              RCC_APB2RSTR_USART1RST_Msk         /*!< USART1 reset */

/*****************  Bit definition for RCC_APB1RSTR register  *****************/
#define RCC_APB1RSTR_TIM2RST_Pos            (0U)                               
#define RCC_APB1RSTR_TIM2RST_Msk            (0x1UL << RCC_APB1RSTR_TIM2RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST                RCC_APB1RSTR_TIM2RST_Msk           /*!< Timer 2 reset */
#define RCC_APB1RSTR_TIM3RST_Pos            (1U)                               
#define RCC_APB1RSTR_TIM3RST_Msk            (0x1UL << RCC_APB1RSTR_TIM3RST_Pos) /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST                RCC_APB1RSTR_TIM3RST_Msk           /*!< Timer 3 reset */
#define RCC_APB1RSTR_TIM4RST_Pos            (2U)                               
#define RCC_APB1RSTR_TIM4RST_Msk            (0x1UL << RCC_APB1RSTR_TIM4RST_Pos) /*!< 0x00000004 */
#define RCC_APB1RSTR_TIM4RST                RCC_APB1RSTR_TIM4RST_Msk           /*!< Timer 4 reset */
#define RCC_APB1RSTR_TIM5RST_Pos            (3U)                               
#define RCC_APB1RSTR_TIM5RST_Msk            (0x1UL << RCC_APB1RSTR_TIM5RST_Pos) /*!< 0x00000008 */
#define RCC_APB1RSTR_TIM5RST                RCC_APB1RSTR_TIM5RST_Msk           /*!< Timer 5 reset */
#define RCC_APB1RSTR_TIM6RST_Pos            (4U)                               
#define RCC_APB1RSTR_TIM6RST_Msk            (0x1UL << RCC_APB1RSTR_TIM6RST_Pos) /*!< 0x00000010 */
#define RCC_APB1RSTR_TIM6RST                RCC_APB1RSTR_TIM6RST_Msk           /*!< Timer 6 reset */
#define RCC_APB1RSTR_TIM7RST_Pos            (5U)                               
#define RCC_APB1RSTR_TIM7RST_Msk            (0x1UL << RCC_APB1RSTR_TIM7RST_Pos) /*!< 0x00000020 */
#define RCC_APB1RSTR_TIM7RST                RCC_APB1RSTR_TIM7RST_Msk           /*!< Timer 7 reset */
#define RCC_APB1RSTR_LCDRST_Pos             (9U)                               
#define RCC_APB1RSTR_LCDRST_Msk             (0x1UL << RCC_APB1RSTR_LCDRST_Pos)  /*!< 0x00000200 */
#define RCC_APB1RSTR_LCDRST                 RCC_APB1RSTR_LCDRST_Msk            /*!< LCD reset */
#define RCC_APB1RSTR_WWDGRST_Pos            (11U)                              
#define RCC_APB1RSTR_WWDGRST_Msk            (0x1UL << RCC_APB1RSTR_WWDGRST_Pos) /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST                RCC_APB1RSTR_WWDGRST_Msk           /*!< Window Watchdog reset */
#define RCC_APB1RSTR_SPI2RST_Pos            (14U)                              
#define RCC_APB1RSTR_SPI2RST_Msk            (0x1UL << RCC_APB1RSTR_SPI2RST_Pos) /*!< 0x00004000 */
#define RCC_APB1RSTR_SPI2RST                RCC_APB1RSTR_SPI2RST_Msk           /*!< SPI 2 reset */
#define RCC_APB1RSTR_SPI3RST_Pos            (15U)                              
#define RCC_APB1RSTR_SPI3RST_Msk            (0x1UL << RCC_APB1RSTR_SPI3RST_Pos) /*!< 0x00008000 */
#define RCC_APB1RSTR_SPI3RST                RCC_APB1RSTR_SPI3RST_Msk           /*!< SPI 3 reset */
#define RCC_APB1RSTR_USART2RST_Pos          (17U)                              
#define RCC_APB1RSTR_USART2RST_Msk          (0x1UL << RCC_APB1RSTR_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST              RCC_APB1RSTR_USART2RST_Msk         /*!< USART 2 reset */
#define RCC_APB1RSTR_USART3RST_Pos          (18U)                              
#define RCC_APB1RSTR_USART3RST_Msk          (0x1UL << RCC_APB1RSTR_USART3RST_Pos) /*!< 0x00040000 */
#define RCC_APB1RSTR_USART3RST              RCC_APB1RSTR_USART3RST_Msk         /*!< USART 3 reset */
#define RCC_APB1RSTR_UART4RST_Pos           (19U)                              
#define RCC_APB1RSTR_UART4RST_Msk           (0x1UL << RCC_APB1RSTR_UART4RST_Pos) /*!< 0x00080000 */
#define RCC_APB1RSTR_UART4RST               RCC_APB1RSTR_UART4RST_Msk          /*!< UART 4 reset */
#define RCC_APB1RSTR_UART5RST_Pos           (20U)                              
#define RCC_APB1RSTR_UART5RST_Msk           (0x1UL << RCC_APB1RSTR_UART5RST_Pos) /*!< 0x00100000 */
#define RCC_APB1RSTR_UART5RST               RCC_APB1RSTR_UART5RST_Msk          /*!< UART 5 reset */
#define RCC_APB1RSTR_I2C1RST_Pos            (21U)                              
#define RCC_APB1RSTR_I2C1RST_Msk            (0x1UL << RCC_APB1RSTR_I2C1RST_Pos) /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST                RCC_APB1RSTR_I2C1RST_Msk           /*!< I2C 1 reset */
#define RCC_APB1RSTR_I2C2RST_Pos            (22U)                              
#define RCC_APB1RSTR_I2C2RST_Msk            (0x1UL << RCC_APB1RSTR_I2C2RST_Pos) /*!< 0x00400000 */
#define RCC_APB1RSTR_I2C2RST                RCC_APB1RSTR_I2C2RST_Msk           /*!< I2C 2 reset */
#define RCC_APB1RSTR_USBRST_Pos             (23U)                              
#define RCC_APB1RSTR_USBRST_Msk             (0x1UL << RCC_APB1RSTR_USBRST_Pos)  /*!< 0x00800000 */
#define RCC_APB1RSTR_USBRST                 RCC_APB1RSTR_USBRST_Msk            /*!< USB reset */
#define RCC_APB1RSTR_PWRRST_Pos             (28U)                              
#define RCC_APB1RSTR_PWRRST_Msk             (0x1UL << RCC_APB1RSTR_PWRRST_Pos)  /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST                 RCC_APB1RSTR_PWRRST_Msk            /*!< Power interface reset */
#define RCC_APB1RSTR_DACRST_Pos             (29U)                              
#define RCC_APB1RSTR_DACRST_Msk             (0x1UL << RCC_APB1RSTR_DACRST_Pos)  /*!< 0x20000000 */
#define RCC_APB1RSTR_DACRST                 RCC_APB1RSTR_DACRST_Msk            /*!< DAC interface reset */
#define RCC_APB1RSTR_COMPRST_Pos            (31U)                              
#define RCC_APB1RSTR_COMPRST_Msk            (0x1UL << RCC_APB1RSTR_COMPRST_Pos) /*!< 0x80000000 */
#define RCC_APB1RSTR_COMPRST                RCC_APB1RSTR_COMPRST_Msk           /*!< Comparator interface reset */

/******************  Bit definition for RCC_AHBENR register  ******************/
#define RCC_AHBENR_GPIOAEN_Pos              (0U)                               
#define RCC_AHBENR_GPIOAEN_Msk              (0x1UL << RCC_AHBENR_GPIOAEN_Pos)   /*!< 0x00000001 */
#define RCC_AHBENR_GPIOAEN                  RCC_AHBENR_GPIOAEN_Msk             /*!< GPIO port A clock enable */
#define RCC_AHBENR_GPIOBEN_Pos              (1U)                               
#define RCC_AHBENR_GPIOBEN_Msk              (0x1UL << RCC_AHBENR_GPIOBEN_Pos)   /*!< 0x00000002 */
#define RCC_AHBENR_GPIOBEN                  RCC_AHBENR_GPIOBEN_Msk             /*!< GPIO port B clock enable */
#define RCC_AHBENR_GPIOCEN_Pos              (2U)                               
#define RCC_AHBENR_GPIOCEN_Msk              (0x1UL << RCC_AHBENR_GPIOCEN_Pos)   /*!< 0x00000004 */
#define RCC_AHBENR_GPIOCEN                  RCC_AHBENR_GPIOCEN_Msk             /*!< GPIO port C clock enable */
#define RCC_AHBENR_GPIODEN_Pos              (3U)                               
#define RCC_AHBENR_GPIODEN_Msk              (0x1UL << RCC_AHBENR_GPIODEN_Pos)   /*!< 0x00000008 */
#define RCC_AHBENR_GPIODEN                  RCC_AHBENR_GPIODEN_Msk             /*!< GPIO port D clock enable */
#define RCC_AHBENR_GPIOEEN_Pos              (4U)                               
#define RCC_AHBENR_GPIOEEN_Msk              (0x1UL << RCC_AHBENR_GPIOEEN_Pos)   /*!< 0x00000010 */
#define RCC_AHBENR_GPIOEEN                  RCC_AHBENR_GPIOEEN_Msk             /*!< GPIO port E clock enable */
#define RCC_AHBENR_GPIOHEN_Pos              (5U)                               
#define RCC_AHBENR_GPIOHEN_Msk              (0x1UL << RCC_AHBENR_GPIOHEN_Pos)   /*!< 0x00000020 */
#define RCC_AHBENR_GPIOHEN                  RCC_AHBENR_GPIOHEN_Msk             /*!< GPIO port H clock enable */
#define RCC_AHBENR_GPIOFEN_Pos              (6U)                               
#define RCC_AHBENR_GPIOFEN_Msk              (0x1UL << RCC_AHBENR_GPIOFEN_Pos)   /*!< 0x00000040 */
#define RCC_AHBENR_GPIOFEN                  RCC_AHBENR_GPIOFEN_Msk             /*!< GPIO port F clock enable */
#define RCC_AHBENR_GPIOGEN_Pos              (7U)                               
#define RCC_AHBENR_GPIOGEN_Msk              (0x1UL << RCC_AHBENR_GPIOGEN_Pos)   /*!< 0x00000080 */
#define RCC_AHBENR_GPIOGEN                  RCC_AHBENR_GPIOGEN_Msk             /*!< GPIO port G clock enable */
#define RCC_AHBENR_CRCEN_Pos                (12U)                              
#define RCC_AHBENR_CRCEN_Msk                (0x1UL << RCC_AHBENR_CRCEN_Pos)     /*!< 0x00001000 */
#define RCC_AHBENR_CRCEN                    RCC_AHBENR_CRCEN_Msk               /*!< CRC clock enable */
#define RCC_AHBENR_FLITFEN_Pos              (15U)                              
#define RCC_AHBENR_FLITFEN_Msk              (0x1UL << RCC_AHBENR_FLITFEN_Pos)   /*!< 0x00008000 */
#define RCC_AHBENR_FLITFEN                  RCC_AHBENR_FLITFEN_Msk             /*!< FLITF clock enable (has effect only when
                                                                                the Flash memory is in power down mode) */
#define RCC_AHBENR_DMA1EN_Pos               (24U)                              
#define RCC_AHBENR_DMA1EN_Msk               (0x1UL << RCC_AHBENR_DMA1EN_Pos)    /*!< 0x01000000 */
#define RCC_AHBENR_DMA1EN                   RCC_AHBENR_DMA1EN_Msk              /*!< DMA1 clock enable */
#define RCC_AHBENR_DMA2EN_Pos               (25U)                              
#define RCC_AHBENR_DMA2EN_Msk               (0x1UL << RCC_AHBENR_DMA2EN_Pos)    /*!< 0x02000000 */
#define RCC_AHBENR_DMA2EN                   RCC_AHBENR_DMA2EN_Msk              /*!< DMA2 clock enable */

/******************  Bit definition for RCC_APB2ENR register  *****************/
#define RCC_APB2ENR_SYSCFGEN_Pos            (0U)                               
#define RCC_APB2ENR_SYSCFGEN_Msk            (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos) /*!< 0x00000001 */
#define RCC_APB2ENR_SYSCFGEN                RCC_APB2ENR_SYSCFGEN_Msk           /*!< System Configuration SYSCFG clock enable */
#define RCC_APB2ENR_TIM9EN_Pos              (2U)                               
#define RCC_APB2ENR_TIM9EN_Msk              (0x1UL << RCC_APB2ENR_TIM9EN_Pos)   /*!< 0x00000004 */
#define RCC_APB2ENR_TIM9EN                  RCC_APB2ENR_TIM9EN_Msk             /*!< TIM9 interface clock enable */
#define RCC_APB2ENR_TIM10EN_Pos             (3U)                               
#define RCC_APB2ENR_TIM10EN_Msk             (0x1UL << RCC_APB2ENR_TIM10EN_Pos)  /*!< 0x00000008 */
#define RCC_APB2ENR_TIM10EN                 RCC_APB2ENR_TIM10EN_Msk            /*!< TIM10 interface clock enable */
#define RCC_APB2ENR_TIM11EN_Pos             (4U)                               
#define RCC_APB2ENR_TIM11EN_Msk             (0x1UL << RCC_APB2ENR_TIM11EN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_TIM11EN                 RCC_APB2ENR_TIM11EN_Msk            /*!< TIM11 Timer clock enable */
#define RCC_APB2ENR_ADC1EN_Pos              (9U)                               
#define RCC_APB2ENR_ADC1EN_Msk              (0x1UL << RCC_APB2ENR_ADC1EN_Pos)   /*!< 0x00000200 */
#define RCC_APB2ENR_ADC1EN                  RCC_APB2ENR_ADC1EN_Msk             /*!< ADC1 clock enable */
#define RCC_APB2ENR_SPI1EN_Pos              (12U)                              
#define RCC_APB2ENR_SPI1EN_Msk              (0x1UL << RCC_APB2ENR_SPI1EN_Pos)   /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                  RCC_APB2ENR_SPI1EN_Msk             /*!< SPI1 clock enable */
#define RCC_APB2ENR_USART1EN_Pos            (14U)                              
#define RCC_APB2ENR_USART1EN_Msk            (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                RCC_APB2ENR_USART1EN_Msk           /*!< USART1 clock enable */

/*****************  Bit definition for RCC_APB1ENR register  ******************/
#define RCC_APB1ENR_TIM2EN_Pos              (0U)                               
#define RCC_APB1ENR_TIM2EN_Msk              (0x1UL << RCC_APB1ENR_TIM2EN_Pos)   /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                  RCC_APB1ENR_TIM2EN_Msk             /*!< Timer 2 clock enabled*/
#define RCC_APB1ENR_TIM3EN_Pos              (1U)                               
#define RCC_APB1ENR_TIM3EN_Msk              (0x1UL << RCC_APB1ENR_TIM3EN_Pos)   /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                  RCC_APB1ENR_TIM3EN_Msk             /*!< Timer 3 clock enable */
#define RCC_APB1ENR_TIM4EN_Pos              (2U)                               
#define RCC_APB1ENR_TIM4EN_Msk              (0x1UL << RCC_APB1ENR_TIM4EN_Pos)   /*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN                  RCC_APB1ENR_TIM4EN_Msk             /*!< Timer 4 clock enable */
#define RCC_APB1ENR_TIM5EN_Pos              (3U)                               
#define RCC_APB1ENR_TIM5EN_Msk              (0x1UL << RCC_APB1ENR_TIM5EN_Pos)   /*!< 0x00000008 */
#define RCC_APB1ENR_TIM5EN                  RCC_APB1ENR_TIM5EN_Msk             /*!< Timer 5 clock enable */
#define RCC_APB1ENR_TIM6EN_Pos              (4U)                               
#define RCC_APB1ENR_TIM6EN_Msk              (0x1UL << RCC_APB1ENR_TIM6EN_Pos)   /*!< 0x00000010 */
#define RCC_APB1ENR_TIM6EN                  RCC_APB1ENR_TIM6EN_Msk             /*!< Timer 6 clock enable */
#define RCC_APB1ENR_TIM7EN_Pos              (5U)                               
#define RCC_APB1ENR_TIM7EN_Msk              (0x1UL << RCC_APB1ENR_TIM7EN_Pos)   /*!< 0x00000020 */
#define RCC_APB1ENR_TIM7EN                  RCC_APB1ENR_TIM7EN_Msk             /*!< Timer 7 clock enable */
#define RCC_APB1ENR_LCDEN_Pos               (9U)                               
#define RCC_APB1ENR_LCDEN_Msk               (0x1UL << RCC_APB1ENR_LCDEN_Pos)    /*!< 0x00000200 */
#define RCC_APB1ENR_LCDEN                   RCC_APB1ENR_LCDEN_Msk              /*!< LCD clock enable */
#define RCC_APB1ENR_WWDGEN_Pos              (11U)                              
#define RCC_APB1ENR_WWDGEN_Msk              (0x1UL << RCC_APB1ENR_WWDGEN_Pos)   /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                  RCC_APB1ENR_WWDGEN_Msk             /*!< Window Watchdog clock enable */
#define RCC_APB1ENR_SPI2EN_Pos              (14U)                              
#define RCC_APB1ENR_SPI2EN_Msk              (0x1UL << RCC_APB1ENR_SPI2EN_Pos)   /*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN                  RCC_APB1ENR_SPI2EN_Msk             /*!< SPI 2 clock enable */
#define RCC_APB1ENR_SPI3EN_Pos              (15U)                              
#define RCC_APB1ENR_SPI3EN_Msk              (0x1UL << RCC_APB1ENR_SPI3EN_Pos)   /*!< 0x00008000 */
#define RCC_APB1ENR_SPI3EN                  RCC_APB1ENR_SPI3EN_Msk             /*!< SPI 3 clock enable */
#define RCC_APB1ENR_USART2EN_Pos            (17U)                              
#define RCC_APB1ENR_USART2EN_Msk            (0x1UL << RCC_APB1ENR_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN                RCC_APB1ENR_USART2EN_Msk           /*!< USART 2 clock enable */
#define RCC_APB1ENR_USART3EN_Pos            (18U)                              
#define RCC_APB1ENR_USART3EN_Msk            (0x1UL << RCC_APB1ENR_USART3EN_Pos) /*!< 0x00040000 */
#define RCC_APB1ENR_USART3EN                RCC_APB1ENR_USART3EN_Msk           /*!< USART 3 clock enable */
#define RCC_APB1ENR_UART4EN_Pos             (19U)                              
#define RCC_APB1ENR_UART4EN_Msk             (0x1UL << RCC_APB1ENR_UART4EN_Pos)  /*!< 0x00080000 */
#define RCC_APB1ENR_UART4EN                 RCC_APB1ENR_UART4EN_Msk            /*!< UART 4 clock enable */
#define RCC_APB1ENR_UART5EN_Pos             (20U)                              
#define RCC_APB1ENR_UART5EN_Msk             (0x1UL << RCC_APB1ENR_UART5EN_Pos)  /*!< 0x00100000 */
#define RCC_APB1ENR_UART5EN                 RCC_APB1ENR_UART5EN_Msk            /*!< UART 5 clock enable */
#define RCC_APB1ENR_I2C1EN_Pos              (21U)                              
#define RCC_APB1ENR_I2C1EN_Msk              (0x1UL << RCC_APB1ENR_I2C1EN_Pos)   /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                  RCC_APB1ENR_I2C1EN_Msk             /*!< I2C 1 clock enable */
#define RCC_APB1ENR_I2C2EN_Pos              (22U)                              
#define RCC_APB1ENR_I2C2EN_Msk              (0x1UL << RCC_APB1ENR_I2C2EN_Pos)   /*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN                  RCC_APB1ENR_I2C2EN_Msk             /*!< I2C 2 clock enable */
#define RCC_APB1ENR_USBEN_Pos               (23U)                              
#define RCC_APB1ENR_USBEN_Msk               (0x1UL << RCC_APB1ENR_USBEN_Pos)    /*!< 0x00800000 */
#define RCC_APB1ENR_USBEN                   RCC_APB1ENR_USBEN_Msk              /*!< USB clock enable */
#define RCC_APB1ENR_PWREN_Pos               (28U)                              
#define RCC_APB1ENR_PWREN_Msk               (0x1UL << RCC_APB1ENR_PWREN_Pos)    /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                   RCC_APB1ENR_PWREN_Msk              /*!< Power interface clock enable */
#define RCC_APB1ENR_DACEN_Pos               (29U)                              
#define RCC_APB1ENR_DACEN_Msk               (0x1UL << RCC_APB1ENR_DACEN_Pos)    /*!< 0x20000000 */
#define RCC_APB1ENR_DACEN                   RCC_APB1ENR_DACEN_Msk              /*!< DAC interface clock enable */
#define RCC_APB1ENR_COMPEN_Pos              (31U)                              
#define RCC_APB1ENR_COMPEN_Msk              (0x1UL << RCC_APB1ENR_COMPEN_Pos)   /*!< 0x80000000 */
#define RCC_APB1ENR_COMPEN                  RCC_APB1ENR_COMPEN_Msk             /*!< Comparator interface clock enable */

/******************  Bit definition for RCC_AHBLPENR register  ****************/
#define RCC_AHBLPENR_GPIOALPEN_Pos          (0U)                               
#define RCC_AHBLPENR_GPIOALPEN_Msk          (0x1UL << RCC_AHBLPENR_GPIOALPEN_Pos) /*!< 0x00000001 */
#define RCC_AHBLPENR_GPIOALPEN              RCC_AHBLPENR_GPIOALPEN_Msk         /*!< GPIO port A clock enabled in sleep mode */
#define RCC_AHBLPENR_GPIOBLPEN_Pos          (1U)                               
#define RCC_AHBLPENR_GPIOBLPEN_Msk          (0x1UL << RCC_AHBLPENR_GPIOBLPEN_Pos) /*!< 0x00000002 */
#define RCC_AHBLPENR_GPIOBLPEN              RCC_AHBLPENR_GPIOBLPEN_Msk         /*!< GPIO port B clock enabled in sleep mode */
#define RCC_AHBLPENR_GPIOCLPEN_Pos          (2U)                               
#define RCC_AHBLPENR_GPIOCLPEN_Msk          (0x1UL << RCC_AHBLPENR_GPIOCLPEN_Pos) /*!< 0x00000004 */
#define RCC_AHBLPENR_GPIOCLPEN              RCC_AHBLPENR_GPIOCLPEN_Msk         /*!< GPIO port C clock enabled in sleep mode */
#define RCC_AHBLPENR_GPIODLPEN_Pos          (3U)                               
#define RCC_AHBLPENR_GPIODLPEN_Msk          (0x1UL << RCC_AHBLPENR_GPIODLPEN_Pos) /*!< 0x00000008 */
#define RCC_AHBLPENR_GPIODLPEN              RCC_AHBLPENR_GPIODLPEN_Msk         /*!< GPIO port D clock enabled in sleep mode */
#define RCC_AHBLPENR_GPIOELPEN_Pos          (4U)                               
#define RCC_AHBLPENR_GPIOELPEN_Msk          (0x1UL << RCC_AHBLPENR_GPIOELPEN_Pos) /*!< 0x00000010 */
#define RCC_AHBLPENR_GPIOELPEN              RCC_AHBLPENR_GPIOELPEN_Msk         /*!< GPIO port E clock enabled in sleep mode */
#define RCC_AHBLPENR_GPIOHLPEN_Pos          (5U)                               
#define RCC_AHBLPENR_GPIOHLPEN_Msk          (0x1UL << RCC_AHBLPENR_GPIOHLPEN_Pos) /*!< 0x00000020 */
#define RCC_AHBLPENR_GPIOHLPEN              RCC_AHBLPENR_GPIOHLPEN_Msk         /*!< GPIO port H clock enabled in sleep mode */
#define RCC_AHBLPENR_GPIOFLPEN_Pos          (6U)                               
#define RCC_AHBLPENR_GPIOFLPEN_Msk          (0x1UL << RCC_AHBLPENR_GPIOFLPEN_Pos) /*!< 0x00000040 */
#define RCC_AHBLPENR_GPIOFLPEN              RCC_AHBLPENR_GPIOFLPEN_Msk         /*!< GPIO port F clock enabled in sleep mode */
#define RCC_AHBLPENR_GPIOGLPEN_Pos          (7U)                               
#define RCC_AHBLPENR_GPIOGLPEN_Msk          (0x1UL << RCC_AHBLPENR_GPIOGLPEN_Pos) /*!< 0x00000080 */
#define RCC_AHBLPENR_GPIOGLPEN              RCC_AHBLPENR_GPIOGLPEN_Msk         /*!< GPIO port G clock enabled in sleep mode */
#define RCC_AHBLPENR_CRCLPEN_Pos            (12U)                              
#define RCC_AHBLPENR_CRCLPEN_Msk            (0x1UL << RCC_AHBLPENR_CRCLPEN_Pos) /*!< 0x00001000 */
#define RCC_AHBLPENR_CRCLPEN                RCC_AHBLPENR_CRCLPEN_Msk           /*!< CRC clock enabled in sleep mode */
#define RCC_AHBLPENR_FLITFLPEN_Pos          (15U)                              
#define RCC_AHBLPENR_FLITFLPEN_Msk          (0x1UL << RCC_AHBLPENR_FLITFLPEN_Pos) /*!< 0x00008000 */
#define RCC_AHBLPENR_FLITFLPEN              RCC_AHBLPENR_FLITFLPEN_Msk         /*!< Flash Interface clock enabled in sleep mode
                                                                                (has effect only when the Flash memory is
                                                                                 in power down mode) */
#define RCC_AHBLPENR_SRAMLPEN_Pos           (16U)                              
#define RCC_AHBLPENR_SRAMLPEN_Msk           (0x1UL << RCC_AHBLPENR_SRAMLPEN_Pos) /*!< 0x00010000 */
#define RCC_AHBLPENR_SRAMLPEN               RCC_AHBLPENR_SRAMLPEN_Msk          /*!< SRAM clock enabled in sleep mode */
#define RCC_AHBLPENR_DMA1LPEN_Pos           (24U)                              
#define RCC_AHBLPENR_DMA1LPEN_Msk           (0x1UL << RCC_AHBLPENR_DMA1LPEN_Pos) /*!< 0x01000000 */
#define RCC_AHBLPENR_DMA1LPEN               RCC_AHBLPENR_DMA1LPEN_Msk          /*!< DMA1 clock enabled in sleep mode */
#define RCC_AHBLPENR_DMA2LPEN_Pos           (25U)                              
#define RCC_AHBLPENR_DMA2LPEN_Msk           (0x1UL << RCC_AHBLPENR_DMA2LPEN_Pos) /*!< 0x02000000 */
#define RCC_AHBLPENR_DMA2LPEN               RCC_AHBLPENR_DMA2LPEN_Msk          /*!< DMA2 clock enabled in sleep mode */

/******************  Bit definition for RCC_APB2LPENR register  ***************/
#define RCC_APB2LPENR_SYSCFGLPEN_Pos        (0U)                               
#define RCC_APB2LPENR_SYSCFGLPEN_Msk        (0x1UL << RCC_APB2LPENR_SYSCFGLPEN_Pos) /*!< 0x00000001 */
#define RCC_APB2LPENR_SYSCFGLPEN            RCC_APB2LPENR_SYSCFGLPEN_Msk       /*!< System Configuration SYSCFG clock enabled in sleep mode */
#define RCC_APB2LPENR_TIM9LPEN_Pos          (2U)                               
#define RCC_APB2LPENR_TIM9LPEN_Msk          (0x1UL << RCC_APB2LPENR_TIM9LPEN_Pos) /*!< 0x00000004 */
#define RCC_APB2LPENR_TIM9LPEN              RCC_APB2LPENR_TIM9LPEN_Msk         /*!< TIM9 interface clock enabled in sleep mode */
#define RCC_APB2LPENR_TIM10LPEN_Pos         (3U)                               
#define RCC_APB2LPENR_TIM10LPEN_Msk         (0x1UL << RCC_APB2LPENR_TIM10LPEN_Pos) /*!< 0x00000008 */
#define RCC_APB2LPENR_TIM10LPEN             RCC_APB2LPENR_TIM10LPEN_Msk        /*!< TIM10 interface clock enabled in sleep mode */
#define RCC_APB2LPENR_TIM11LPEN_Pos         (4U)                               
#define RCC_APB2LPENR_TIM11LPEN_Msk         (0x1UL << RCC_APB2LPENR_TIM11LPEN_Pos) /*!< 0x00000010 */
#define RCC_APB2LPENR_TIM11LPEN             RCC_APB2LPENR_TIM11LPEN_Msk        /*!< TIM11 Timer clock enabled in sleep mode */
#define RCC_APB2LPENR_ADC1LPEN_Pos          (9U)                               
#define RCC_APB2LPENR_ADC1LPEN_Msk          (0x1UL << RCC_APB2LPENR_ADC1LPEN_Pos) /*!< 0x00000200 */
#define RCC_APB2LPENR_ADC1LPEN              RCC_APB2LPENR_ADC1LPEN_Msk         /*!< ADC1 clock enabled in sleep mode */
#define RCC_APB2LPENR_SPI1LPEN_Pos          (12U)                              
#define RCC_APB2LPENR_SPI1LPEN_Msk          (0x1UL << RCC_APB2LPENR_SPI1LPEN_Pos) /*!< 0x00001000 */
#define RCC_APB2LPENR_SPI1LPEN              RCC_APB2LPENR_SPI1LPEN_Msk         /*!< SPI1 clock enabled in sleep mode */
#define RCC_APB2LPENR_USART1LPEN_Pos        (14U)                              
#define RCC_APB2LPENR_USART1LPEN_Msk        (0x1UL << RCC_APB2LPENR_USART1LPEN_Pos) /*!< 0x00004000 */
#define RCC_APB2LPENR_USART1LPEN            RCC_APB2LPENR_USART1LPEN_Msk       /*!< USART1 clock enabled in sleep mode */

/*****************  Bit definition for RCC_APB1LPENR register  ****************/
#define RCC_APB1LPENR_TIM2LPEN_Pos          (0U)                               
#define RCC_APB1LPENR_TIM2LPEN_Msk          (0x1UL << RCC_APB1LPENR_TIM2LPEN_Pos) /*!< 0x00000001 */
#define RCC_APB1LPENR_TIM2LPEN              RCC_APB1LPENR_TIM2LPEN_Msk         /*!< Timer 2 clock enabled in sleep mode */
#define RCC_APB1LPENR_TIM3LPEN_Pos          (1U)                               
#define RCC_APB1LPENR_TIM3LPEN_Msk          (0x1UL << RCC_APB1LPENR_TIM3LPEN_Pos) /*!< 0x00000002 */
#define RCC_APB1LPENR_TIM3LPEN              RCC_APB1LPENR_TIM3LPEN_Msk         /*!< Timer 3 clock enabled in sleep mode */
#define RCC_APB1LPENR_TIM4LPEN_Pos          (2U)                               
#define RCC_APB1LPENR_TIM4LPEN_Msk          (0x1UL << RCC_APB1LPENR_TIM4LPEN_Pos) /*!< 0x00000004 */
#define RCC_APB1LPENR_TIM4LPEN              RCC_APB1LPENR_TIM4LPEN_Msk         /*!< Timer 4 clock enabled in sleep mode */
#define RCC_APB1LPENR_TIM5LPEN_Pos          (3U)                               
#define RCC_APB1LPENR_TIM5LPEN_Msk          (0x1UL << RCC_APB1LPENR_TIM5LPEN_Pos) /*!< 0x00000008 */
#define RCC_APB1LPENR_TIM5LPEN              RCC_APB1LPENR_TIM5LPEN_Msk         /*!< Timer 5 clock enabled in sleep mode */
#define RCC_APB1LPENR_TIM6LPEN_Pos          (4U)                               
#define RCC_APB1LPENR_TIM6LPEN_Msk          (0x1UL << RCC_APB1LPENR_TIM6LPEN_Pos) /*!< 0x00000010 */
#define RCC_APB1LPENR_TIM6LPEN              RCC_APB1LPENR_TIM6LPEN_Msk         /*!< Timer 6 clock enabled in sleep mode */
#define RCC_APB1LPENR_TIM7LPEN_Pos          (5U)                               
#define RCC_APB1LPENR_TIM7LPEN_Msk          (0x1UL << RCC_APB1LPENR_TIM7LPEN_Pos) /*!< 0x00000020 */
#define RCC_APB1LPENR_TIM7LPEN              RCC_APB1LPENR_TIM7LPEN_Msk         /*!< Timer 7 clock enabled in sleep mode */
#define RCC_APB1LPENR_LCDLPEN_Pos           (9U)                               
#define RCC_APB1LPENR_LCDLPEN_Msk           (0x1UL << RCC_APB1LPENR_LCDLPEN_Pos) /*!< 0x00000200 */
#define RCC_APB1LPENR_LCDLPEN               RCC_APB1LPENR_LCDLPEN_Msk          /*!< LCD clock enabled in sleep mode */
#define RCC_APB1LPENR_WWDGLPEN_Pos          (11U)                              
#define RCC_APB1LPENR_WWDGLPEN_Msk          (0x1UL << RCC_APB1LPENR_WWDGLPEN_Pos) /*!< 0x00000800 */
#define RCC_APB1LPENR_WWDGLPEN              RCC_APB1LPENR_WWDGLPEN_Msk         /*!< Window Watchdog clock enabled in sleep mode */
#define RCC_APB1LPENR_SPI2LPEN_Pos          (14U)                              
#define RCC_APB1LPENR_SPI2LPEN_Msk          (0x1UL << RCC_APB1LPENR_SPI2LPEN_Pos) /*!< 0x00004000 */
#define RCC_APB1LPENR_SPI2LPEN              RCC_APB1LPENR_SPI2LPEN_Msk         /*!< SPI 2 clock enabled in sleep mode */
#define RCC_APB1LPENR_SPI3LPEN_Pos          (15U)                              
#define RCC_APB1LPENR_SPI3LPEN_Msk          (0x1UL << RCC_APB1LPENR_SPI3LPEN_Pos) /*!< 0x00008000 */
#define RCC_APB1LPENR_SPI3LPEN              RCC_APB1LPENR_SPI3LPEN_Msk         /*!< SPI 3 clock enabled in sleep mode */
#define RCC_APB1LPENR_USART2LPEN_Pos        (17U)                              
#define RCC_APB1LPENR_USART2LPEN_Msk        (0x1UL << RCC_APB1LPENR_USART2LPEN_Pos) /*!< 0x00020000 */
#define RCC_APB1LPENR_USART2LPEN            RCC_APB1LPENR_USART2LPEN_Msk       /*!< USART 2 clock enabled in sleep mode */
#define RCC_APB1LPENR_USART3LPEN_Pos        (18U)                              
#define RCC_APB1LPENR_USART3LPEN_Msk        (0x1UL << RCC_APB1LPENR_USART3LPEN_Pos) /*!< 0x00040000 */
#define RCC_APB1LPENR_USART3LPEN            RCC_APB1LPENR_USART3LPEN_Msk       /*!< USART 3 clock enabled in sleep mode */
#define RCC_APB1LPENR_UART4LPEN_Pos         (19U)                              
#define RCC_APB1LPENR_UART4LPEN_Msk         (0x1UL << RCC_APB1LPENR_UART4LPEN_Pos) /*!< 0x00080000 */
#define RCC_APB1LPENR_UART4LPEN             RCC_APB1LPENR_UART4LPEN_Msk        /*!< UART 4 clock enabled in sleep mode */
#define RCC_APB1LPENR_UART5LPEN_Pos         (20U)                              
#define RCC_APB1LPENR_UART5LPEN_Msk         (0x1UL << RCC_APB1LPENR_UART5LPEN_Pos) /*!< 0x00100000 */
#define RCC_APB1LPENR_UART5LPEN             RCC_APB1LPENR_UART5LPEN_Msk        /*!< UART 5 clock enabled in sleep mode */
#define RCC_APB1LPENR_I2C1LPEN_Pos          (21U)                              
#define RCC_APB1LPENR_I2C1LPEN_Msk          (0x1UL << RCC_APB1LPENR_I2C1LPEN_Pos) /*!< 0x00200000 */
#define RCC_APB1LPENR_I2C1LPEN              RCC_APB1LPENR_I2C1LPEN_Msk         /*!< I2C 1 clock enabled in sleep mode */
#define RCC_APB1LPENR_I2C2LPEN_Pos          (22U)                              
#define RCC_APB1LPENR_I2C2LPEN_Msk          (0x1UL << RCC_APB1LPENR_I2C2LPEN_Pos) /*!< 0x00400000 */
#define RCC_APB1LPENR_I2C2LPEN              RCC_APB1LPENR_I2C2LPEN_Msk         /*!< I2C 2 clock enabled in sleep mode */
#define RCC_APB1LPENR_USBLPEN_Pos           (23U)                              
#define RCC_APB1LPENR_USBLPEN_Msk           (0x1UL << RCC_APB1LPENR_USBLPEN_Pos) /*!< 0x00800000 */
#define RCC_APB1LPENR_USBLPEN               RCC_APB1LPENR_USBLPEN_Msk          /*!< USB clock enabled in sleep mode */
#define RCC_APB1LPENR_PWRLPEN_Pos           (28U)                              
#define RCC_APB1LPENR_PWRLPEN_Msk           (0x1UL << RCC_APB1LPENR_PWRLPEN_Pos) /*!< 0x10000000 */
#define RCC_APB1LPENR_PWRLPEN               RCC_APB1LPENR_PWRLPEN_Msk          /*!< Power interface clock enabled in sleep mode */
#define RCC_APB1LPENR_DACLPEN_Pos           (29U)                              
#define RCC_APB1LPENR_DACLPEN_Msk           (0x1UL << RCC_APB1LPENR_DACLPEN_Pos) /*!< 0x20000000 */
#define RCC_APB1LPENR_DACLPEN               RCC_APB1LPENR_DACLPEN_Msk          /*!< DAC interface clock enabled in sleep mode */
#define RCC_APB1LPENR_COMPLPEN_Pos          (31U)                              
#define RCC_APB1LPENR_COMPLPEN_Msk          (0x1UL << RCC_APB1LPENR_COMPLPEN_Pos) /*!< 0x80000000 */
#define RCC_APB1LPENR_COMPLPEN              RCC_APB1LPENR_COMPLPEN_Msk         /*!< Comparator interface clock enabled in sleep mode*/

/*******************  Bit definition for RCC_CSR register  ********************/
#define RCC_CSR_LSION_Pos                   (0U)                               
#define RCC_CSR_LSION_Msk                   (0x1UL << RCC_CSR_LSION_Pos)        /*!< 0x00000001 */
#define RCC_CSR_LSION                       RCC_CSR_LSION_Msk                  /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY_Pos                  (1U)                               
#define RCC_CSR_LSIRDY_Msk                  (0x1UL << RCC_CSR_LSIRDY_Pos)       /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                      RCC_CSR_LSIRDY_Msk                 /*!< Internal Low Speed oscillator Ready */

#define RCC_CSR_LSEON_Pos                   (8U)                               
#define RCC_CSR_LSEON_Msk                   (0x1UL << RCC_CSR_LSEON_Pos)        /*!< 0x00000100 */
#define RCC_CSR_LSEON                       RCC_CSR_LSEON_Msk                  /*!< External Low Speed oscillator enable */
#define RCC_CSR_LSERDY_Pos                  (9U)                               
#define RCC_CSR_LSERDY_Msk                  (0x1UL << RCC_CSR_LSERDY_Pos)       /*!< 0x00000200 */
#define RCC_CSR_LSERDY                      RCC_CSR_LSERDY_Msk                 /*!< External Low Speed oscillator Ready */
#define RCC_CSR_LSEBYP_Pos                  (10U)                              
#define RCC_CSR_LSEBYP_Msk                  (0x1UL << RCC_CSR_LSEBYP_Pos)       /*!< 0x00000400 */
#define RCC_CSR_LSEBYP                      RCC_CSR_LSEBYP_Msk                 /*!< External Low Speed oscillator Bypass */

#define RCC_CSR_LSECSSON_Pos                (11U)                              
#define RCC_CSR_LSECSSON_Msk                (0x1UL << RCC_CSR_LSECSSON_Pos)     /*!< 0x00000800 */
#define RCC_CSR_LSECSSON                    RCC_CSR_LSECSSON_Msk               /*!< External Low Speed oscillator CSS Enable */
#define RCC_CSR_LSECSSD_Pos                 (12U)                              
#define RCC_CSR_LSECSSD_Msk                 (0x1UL << RCC_CSR_LSECSSD_Pos)      /*!< 0x00001000 */
#define RCC_CSR_LSECSSD                     RCC_CSR_LSECSSD_Msk                /*!< External Low Speed oscillator CSS Detected */

#define RCC_CSR_RTCSEL_Pos                  (16U)                              
#define RCC_CSR_RTCSEL_Msk                  (0x3UL << RCC_CSR_RTCSEL_Pos)       /*!< 0x00030000 */
#define RCC_CSR_RTCSEL                      RCC_CSR_RTCSEL_Msk                 /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define RCC_CSR_RTCSEL_0                    (0x1UL << RCC_CSR_RTCSEL_Pos)       /*!< 0x00010000 */
#define RCC_CSR_RTCSEL_1                    (0x2UL << RCC_CSR_RTCSEL_Pos)       /*!< 0x00020000 */

/*!< RTC congiguration */
#define RCC_CSR_RTCSEL_NOCLOCK              (0x00000000U)                      /*!< No clock */
#define RCC_CSR_RTCSEL_LSE_Pos              (16U)                              
#define RCC_CSR_RTCSEL_LSE_Msk              (0x1UL << RCC_CSR_RTCSEL_LSE_Pos)   /*!< 0x00010000 */
#define RCC_CSR_RTCSEL_LSE                  RCC_CSR_RTCSEL_LSE_Msk             /*!< LSE oscillator clock used as RTC clock */
#define RCC_CSR_RTCSEL_LSI_Pos              (17U)                              
#define RCC_CSR_RTCSEL_LSI_Msk              (0x1UL << RCC_CSR_RTCSEL_LSI_Pos)   /*!< 0x00020000 */
#define RCC_CSR_RTCSEL_LSI                  RCC_CSR_RTCSEL_LSI_Msk             /*!< LSI oscillator clock used as RTC clock */
#define RCC_CSR_RTCSEL_HSE_Pos              (16U)                              
#define RCC_CSR_RTCSEL_HSE_Msk              (0x3UL << RCC_CSR_RTCSEL_HSE_Pos)   /*!< 0x00030000 */
#define RCC_CSR_RTCSEL_HSE                  RCC_CSR_RTCSEL_HSE_Msk             /*!< HSE oscillator clock divided by 2, 4, 8 or 16 by RTCPRE used as RTC clock */

#define RCC_CSR_RTCEN_Pos                   (22U)                              
#define RCC_CSR_RTCEN_Msk                   (0x1UL << RCC_CSR_RTCEN_Pos)        /*!< 0x00400000 */
#define RCC_CSR_RTCEN                       RCC_CSR_RTCEN_Msk                  /*!< RTC clock enable */
#define RCC_CSR_RTCRST_Pos                  (23U)                              
#define RCC_CSR_RTCRST_Msk                  (0x1UL << RCC_CSR_RTCRST_Pos)       /*!< 0x00800000 */
#define RCC_CSR_RTCRST                      RCC_CSR_RTCRST_Msk                 /*!< RTC reset  */
 
#define RCC_CSR_RMVF_Pos                    (24U)                              
#define RCC_CSR_RMVF_Msk                    (0x1UL << RCC_CSR_RMVF_Pos)         /*!< 0x01000000 */
#define RCC_CSR_RMVF                        RCC_CSR_RMVF_Msk                   /*!< Remove reset flag */
#define RCC_CSR_OBLRSTF_Pos                 (25U)                              
#define RCC_CSR_OBLRSTF_Msk                 (0x1UL << RCC_CSR_OBLRSTF_Pos)      /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                     RCC_CSR_OBLRSTF_Msk                /*!< Option Bytes Loader reset flag */
#define RCC_CSR_PINRSTF_Pos                 (26U)                              
#define RCC_CSR_PINRSTF_Msk                 (0x1UL << RCC_CSR_PINRSTF_Pos)      /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                     RCC_CSR_PINRSTF_Msk                /*!< PIN reset flag */
#define RCC_CSR_PORRSTF_Pos                 (27U)                              
#define RCC_CSR_PORRSTF_Msk                 (0x1UL << RCC_CSR_PORRSTF_Pos)      /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                     RCC_CSR_PORRSTF_Msk                /*!< POR/PDR reset flag */
#define RCC_CSR_SFTRSTF_Pos                 (28U)                              
#define RCC_CSR_SFTRSTF_Msk                 (0x1UL << RCC_CSR_SFTRSTF_Pos)      /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                     RCC_CSR_SFTRSTF_Msk                /*!< Software Reset flag */
#define RCC_CSR_IWDGRSTF_Pos                (29U)                              
#define RCC_CSR_IWDGRSTF_Msk                (0x1UL << RCC_CSR_IWDGRSTF_Pos)     /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                    RCC_CSR_IWDGRSTF_Msk               /*!< Independent Watchdog reset flag */
#define RCC_CSR_WWDGRSTF_Pos                (30U)                              
#define RCC_CSR_WWDGRSTF_Msk                (0x1UL << RCC_CSR_WWDGRSTF_Pos)     /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                    RCC_CSR_WWDGRSTF_Msk               /*!< Window watchdog reset flag */
#define RCC_CSR_LPWRRSTF_Pos                (31U)                              
#define RCC_CSR_LPWRRSTF_Msk                (0x1UL << RCC_CSR_LPWRRSTF_Pos)     /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                    RCC_CSR_LPWRRSTF_Msk               /*!< Low-Power reset flag */

// 레지스터 목록
namespace RCC_REG
{
enum
{
	CR = 0,			ICSCR,			CFGR,			CIR,			AHBRSTR,
	APB2RSTR,		APB1RSTR,		AHBENR,			APB2ENR,		APB1ENR, 
	AHBLPENR,		APB2LPENR,		APB1LPENR,		CSR
};
}

#endif

