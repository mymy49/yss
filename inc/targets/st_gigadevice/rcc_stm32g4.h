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
#ifndef __RCC_STM32G4__H_
#define __RCC_STM32G4__H_

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/*
* @brief Specific device feature definitions  (not present on all devices in the STM32G4 serie)
*/

#define RCC_HSI48_SUPPORT
#define RCC_PLLP_DIV_2_31_SUPPORT

/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                     (8U)
#define RCC_CR_HSION_Msk                     (0x1UL << RCC_CR_HSION_Pos)       /*!< 0x00000100 */
#define RCC_CR_HSION                         RCC_CR_HSION_Msk                  /*!< Internal High Speed oscillator (HSI16) clock enable */
#define RCC_CR_HSIKERON_Pos                  (9U)
#define RCC_CR_HSIKERON_Msk                  (0x1UL << RCC_CR_HSIKERON_Pos)    /*!< 0x00000200 */
#define RCC_CR_HSIKERON                      RCC_CR_HSIKERON_Msk               /*!< Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
#define RCC_CR_HSIRDY_Pos                    (10U)
#define RCC_CR_HSIRDY_Msk                    (0x1UL << RCC_CR_HSIRDY_Pos)      /*!< 0x00000400 */
#define RCC_CR_HSIRDY                        RCC_CR_HSIRDY_Msk                 /*!< Internal High Speed oscillator (HSI16) clock ready flag */

#define RCC_CR_HSEON_Pos                     (16U)
#define RCC_CR_HSEON_Msk                     (0x1UL << RCC_CR_HSEON_Pos)       /*!< 0x00010000 */
#define RCC_CR_HSEON                         RCC_CR_HSEON_Msk                  /*!< External High Speed oscillator (HSE) clock enable */
#define RCC_CR_HSERDY_Pos                    (17U)
#define RCC_CR_HSERDY_Msk                    (0x1UL << RCC_CR_HSERDY_Pos)      /*!< 0x00020000 */
#define RCC_CR_HSERDY                        RCC_CR_HSERDY_Msk                 /*!< External High Speed oscillator (HSE) clock ready */
#define RCC_CR_HSEBYP_Pos                    (18U)
#define RCC_CR_HSEBYP_Msk                    (0x1UL << RCC_CR_HSEBYP_Pos)      /*!< 0x00040000 */
#define RCC_CR_HSEBYP                        RCC_CR_HSEBYP_Msk                 /*!< External High Speed oscillator (HSE) clock bypass */
#define RCC_CR_CSSON_Pos                     (19U)
#define RCC_CR_CSSON_Msk                     (0x1UL << RCC_CR_CSSON_Pos)       /*!< 0x00080000 */
#define RCC_CR_CSSON                         RCC_CR_CSSON_Msk                  /*!< HSE Clock Security System enable */

#define RCC_CR_PLLON_Pos                     (24U)
#define RCC_CR_PLLON_Msk                     (0x1UL << RCC_CR_PLLON_Pos)       /*!< 0x01000000 */
#define RCC_CR_PLLON                         RCC_CR_PLLON_Msk                  /*!< System PLL clock enable */
#define RCC_CR_PLLRDY_Pos                    (25U)
#define RCC_CR_PLLRDY_Msk                    (0x1UL << RCC_CR_PLLRDY_Pos)      /*!< 0x02000000 */
#define RCC_CR_PLLRDY                        RCC_CR_PLLRDY_Msk                 /*!< System PLL clock ready */

/********************  Bit definition for RCC_ICSCR register  ***************/
/*!< HSICAL configuration */
#define RCC_ICSCR_HSICAL_Pos                 (16U)
#define RCC_ICSCR_HSICAL_Msk                 (0xFFUL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00FF0000 */
#define RCC_ICSCR_HSICAL                     RCC_ICSCR_HSICAL_Msk              /*!< HSICAL[7:0] bits */
#define RCC_ICSCR_HSICAL_0                   (0x01UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00010000 */
#define RCC_ICSCR_HSICAL_1                   (0x02UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00020000 */
#define RCC_ICSCR_HSICAL_2                   (0x04UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00040000 */
#define RCC_ICSCR_HSICAL_3                   (0x08UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00080000 */
#define RCC_ICSCR_HSICAL_4                   (0x10UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00100000 */
#define RCC_ICSCR_HSICAL_5                   (0x20UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00200000 */
#define RCC_ICSCR_HSICAL_6                   (0x40UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00400000 */
#define RCC_ICSCR_HSICAL_7                   (0x80UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00800000 */

/*!< HSITRIM configuration */
#define RCC_ICSCR_HSITRIM_Pos                (24U)
#define RCC_ICSCR_HSITRIM_Msk                (0x7FUL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x7F000000 */
#define RCC_ICSCR_HSITRIM                    RCC_ICSCR_HSITRIM_Msk             /*!< HSITRIM[6:0] bits */
#define RCC_ICSCR_HSITRIM_0                  (0x01UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x01000000 */
#define RCC_ICSCR_HSITRIM_1                  (0x02UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x02000000 */
#define RCC_ICSCR_HSITRIM_2                  (0x04UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x04000000 */
#define RCC_ICSCR_HSITRIM_3                  (0x08UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x08000000 */
#define RCC_ICSCR_HSITRIM_4                  (0x10UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x10000000 */
#define RCC_ICSCR_HSITRIM_5                  (0x20UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x20000000 */
#define RCC_ICSCR_HSITRIM_6                  (0x40UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x40000000 */

/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                      (0U)
#define RCC_CFGR_SW_Msk                      (0x3UL << RCC_CFGR_SW_Pos)        /*!< 0x00000003 */
#define RCC_CFGR_SW                          RCC_CFGR_SW_Msk                   /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                        (0x1UL << RCC_CFGR_SW_Pos)        /*!< 0x00000001 */
#define RCC_CFGR_SW_1                        (0x2UL << RCC_CFGR_SW_Pos)        /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI                      (0x00000001U)                     /*!< HSI16 oscillator selection as system clock */
#define RCC_CFGR_SW_HSE                      (0x00000002U)                     /*!< HSE oscillator selection as system clock */
#define RCC_CFGR_SW_PLL                      (0x00000003U)                     /*!< PLL selection as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                     (2U)
#define RCC_CFGR_SWS_Msk                     (0x3UL << RCC_CFGR_SWS_Pos)       /*!< 0x0000000C */
#define RCC_CFGR_SWS                         RCC_CFGR_SWS_Msk                  /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                       (0x1UL << RCC_CFGR_SWS_Pos)       /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                       (0x2UL << RCC_CFGR_SWS_Pos)       /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI                     (0x00000004U)                     /*!< HSI16 oscillator used as system clock */
#define RCC_CFGR_SWS_HSE                     (0x00000008U)                     /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL                     (0x0000000CU)                     /*!< PLL used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                    (4U)
#define RCC_CFGR_HPRE_Msk                    (0xFUL << RCC_CFGR_HPRE_Pos)      /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                        RCC_CFGR_HPRE_Msk                 /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                      (0x1UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                      (0x2UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                      (0x4UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                      (0x8UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                   (0x00000000U)                     /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2                   (0x00000080U)                     /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4                   (0x00000090U)                     /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8                   (0x000000A0U)                     /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16                  (0x000000B0U)                     /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64                  (0x000000C0U)                     /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128                 (0x000000D0U)                     /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256                 (0x000000E0U)                     /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512                 (0x000000F0U)                     /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                   (8U)
#define RCC_CFGR_PPRE1_Msk                   (0x7UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000700 */
#define RCC_CFGR_PPRE1                       RCC_CFGR_PPRE1_Msk                /*!< PRE1[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE1_0                     (0x1UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000100 */
#define RCC_CFGR_PPRE1_1                     (0x2UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000200 */
#define RCC_CFGR_PPRE1_2                     (0x4UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000400 */

#define RCC_CFGR_PPRE1_DIV1                  (0x00000000U)                     /*!< HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2                  (0x00000400U)                     /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4                  (0x00000500U)                     /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8                  (0x00000600U)                     /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16                 (0x00000700U)                     /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                   (11U)
#define RCC_CFGR_PPRE2_Msk                   (0x7UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00003800 */
#define RCC_CFGR_PPRE2                       RCC_CFGR_PPRE2_Msk                /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                     (0x1UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00000800 */
#define RCC_CFGR_PPRE2_1                     (0x2UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00001000 */
#define RCC_CFGR_PPRE2_2                     (0x4UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00002000 */

#define RCC_CFGR_PPRE2_DIV1                  (0x00000000U)                     /*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2                  (0x00002000U)                     /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4                  (0x00002800U)                     /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8                  (0x00003000U)                     /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16                 (0x00003800U)                     /*!< HCLK divided by 16 */

/*!< MCOSEL configuration */
#define RCC_CFGR_MCOSEL_Pos                  (24U)
#define RCC_CFGR_MCOSEL_Msk                  (0xFUL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x0F000000 */
#define RCC_CFGR_MCOSEL                      RCC_CFGR_MCOSEL_Msk               /*!< MCOSEL [3:0] bits (Clock output selection) */
#define RCC_CFGR_MCOSEL_0                    (0x1UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x01000000 */
#define RCC_CFGR_MCOSEL_1                    (0x2UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x02000000 */
#define RCC_CFGR_MCOSEL_2                    (0x4UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x04000000 */
#define RCC_CFGR_MCOSEL_3                    (0x8UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x08000000 */

#define RCC_CFGR_MCOPRE_Pos                  (28U)
#define RCC_CFGR_MCOPRE_Msk                  (0x7UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x70000000 */
#define RCC_CFGR_MCOPRE                      RCC_CFGR_MCOPRE_Msk               /*!< MCO prescaler */
#define RCC_CFGR_MCOPRE_0                    (0x1UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x10000000 */
#define RCC_CFGR_MCOPRE_1                    (0x2UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x20000000 */
#define RCC_CFGR_MCOPRE_2                    (0x4UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x40000000 */

#define RCC_CFGR_MCOPRE_DIV1                 (0x00000000U)                     /*!< MCO is divided by 1 */
#define RCC_CFGR_MCOPRE_DIV2                 (0x10000000U)                     /*!< MCO is divided by 2 */
#define RCC_CFGR_MCOPRE_DIV4                 (0x20000000U)                     /*!< MCO is divided by 4 */
#define RCC_CFGR_MCOPRE_DIV8                 (0x30000000U)                     /*!< MCO is divided by 8 */
#define RCC_CFGR_MCOPRE_DIV16                (0x40000000U)                     /*!< MCO is divided by 16 */

/* Legacy aliases */
#define RCC_CFGR_MCO_PRE                     RCC_CFGR_MCOPRE
#define RCC_CFGR_MCO_PRE_1                   RCC_CFGR_MCOPRE_DIV1
#define RCC_CFGR_MCO_PRE_2                   RCC_CFGR_MCOPRE_DIV2
#define RCC_CFGR_MCO_PRE_4                   RCC_CFGR_MCOPRE_DIV4
#define RCC_CFGR_MCO_PRE_8                   RCC_CFGR_MCOPRE_DIV8
#define RCC_CFGR_MCO_PRE_16                  RCC_CFGR_MCOPRE_DIV16

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLSRC_Pos               (0U)
#define RCC_PLLCFGR_PLLSRC_Msk               (0x3UL << RCC_PLLCFGR_PLLSRC_Pos) /*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC                   RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_0                 (0x1UL << RCC_PLLCFGR_PLLSRC_Pos) /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLSRC_1                 (0x2UL << RCC_PLLCFGR_PLLSRC_Pos) /*!< 0x00000002 */

#define RCC_PLLCFGR_PLLSRC_HSI_Pos           (1U)
#define RCC_PLLCFGR_PLLSRC_HSI_Msk           (0x1UL << RCC_PLLCFGR_PLLSRC_HSI_Pos)/*!< 0x00000002 */
#define RCC_PLLCFGR_PLLSRC_HSI               RCC_PLLCFGR_PLLSRC_HSI_Msk        /*!< HSI16 oscillator source clock selected */
#define RCC_PLLCFGR_PLLSRC_HSE_Pos           (0U)
#define RCC_PLLCFGR_PLLSRC_HSE_Msk           (0x3UL << RCC_PLLCFGR_PLLSRC_HSE_Pos)/*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC_HSE               RCC_PLLCFGR_PLLSRC_HSE_Msk        /*!< HSE oscillator source clock selected */

#define RCC_PLLCFGR_PLLM_Pos                 (4U)
#define RCC_PLLCFGR_PLLM_Msk                 (0xFUL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x000000F0 */
#define RCC_PLLCFGR_PLLM                     RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0                   (0x1UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_1                   (0x2UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLM_2                   (0x4UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLM_3                   (0x8UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000080 */

#define RCC_PLLCFGR_PLLN_Pos                 (8U)
#define RCC_PLLCFGR_PLLN_Msk                 (0x7FUL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00007F00 */
#define RCC_PLLCFGR_PLLN                     RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0                   (0x01UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_1                   (0x02UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_2                   (0x04UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_3                   (0x08UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_4                   (0x10UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_5                   (0x20UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_6                   (0x40UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLPEN_Pos               (16U)
#define RCC_PLLCFGR_PLLPEN_Msk               (0x1UL << RCC_PLLCFGR_PLLPEN_Pos) /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLPEN                   RCC_PLLCFGR_PLLPEN_Msk
#define RCC_PLLCFGR_PLLP_Pos                 (17U)
#define RCC_PLLCFGR_PLLP_Msk                 (0x1UL << RCC_PLLCFGR_PLLP_Pos)   /*!< 0x00020000 */
#define RCC_PLLCFGR_PLLP                     RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLQEN_Pos               (20U)
#define RCC_PLLCFGR_PLLQEN_Msk               (0x1UL << RCC_PLLCFGR_PLLQEN_Pos) /*!< 0x00100000 */
#define RCC_PLLCFGR_PLLQEN                   RCC_PLLCFGR_PLLQEN_Msk

#define RCC_PLLCFGR_PLLQ_Pos                 (21U)
#define RCC_PLLCFGR_PLLQ_Msk                 (0x3UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00600000 */
#define RCC_PLLCFGR_PLLQ                     RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0                   (0x1UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00200000 */
#define RCC_PLLCFGR_PLLQ_1                   (0x2UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00400000 */

#define RCC_PLLCFGR_PLLREN_Pos               (24U)
#define RCC_PLLCFGR_PLLREN_Msk               (0x1UL << RCC_PLLCFGR_PLLREN_Pos) /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLREN                   RCC_PLLCFGR_PLLREN_Msk
#define RCC_PLLCFGR_PLLR_Pos                 (25U)
#define RCC_PLLCFGR_PLLR_Msk                 (0x3UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x06000000 */
#define RCC_PLLCFGR_PLLR                     RCC_PLLCFGR_PLLR_Msk
#define RCC_PLLCFGR_PLLR_0                   (0x1UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLR_1                   (0x2UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x04000000 */

#define RCC_PLLCFGR_PLLPDIV_Pos              (27U)
#define RCC_PLLCFGR_PLLPDIV_Msk              (0x1FUL << RCC_PLLCFGR_PLLPDIV_Pos)/*!< 0xF8000000 */
#define RCC_PLLCFGR_PLLPDIV                  RCC_PLLCFGR_PLLPDIV_Msk
#define RCC_PLLCFGR_PLLPDIV_0                (0x01UL << RCC_PLLCFGR_PLLPDIV_Pos)/*!< 0x08000000 */
#define RCC_PLLCFGR_PLLPDIV_1                (0x02UL << RCC_PLLCFGR_PLLPDIV_Pos)/*!< 0x10000000 */
#define RCC_PLLCFGR_PLLPDIV_2                (0x04UL << RCC_PLLCFGR_PLLPDIV_Pos)/*!< 0x20000000 */
#define RCC_PLLCFGR_PLLPDIV_3                (0x08UL << RCC_PLLCFGR_PLLPDIV_Pos)/*!< 0x40000000 */
#define RCC_PLLCFGR_PLLPDIV_4                (0x10UL << RCC_PLLCFGR_PLLPDIV_Pos)/*!< 0x80000000 */

/********************  Bit definition for RCC_CIER register  ******************/
#define RCC_CIER_LSIRDYIE_Pos                (0U)
#define RCC_CIER_LSIRDYIE_Msk                (0x1UL << RCC_CIER_LSIRDYIE_Pos)  /*!< 0x00000001 */
#define RCC_CIER_LSIRDYIE                    RCC_CIER_LSIRDYIE_Msk
#define RCC_CIER_LSERDYIE_Pos                (1U)
#define RCC_CIER_LSERDYIE_Msk                (0x1UL << RCC_CIER_LSERDYIE_Pos)  /*!< 0x00000002 */
#define RCC_CIER_LSERDYIE                    RCC_CIER_LSERDYIE_Msk
#define RCC_CIER_HSIRDYIE_Pos                (3U)
#define RCC_CIER_HSIRDYIE_Msk                (0x1UL << RCC_CIER_HSIRDYIE_Pos)  /*!< 0x00000008 */
#define RCC_CIER_HSIRDYIE                    RCC_CIER_HSIRDYIE_Msk
#define RCC_CIER_HSERDYIE_Pos                (4U)
#define RCC_CIER_HSERDYIE_Msk                (0x1UL << RCC_CIER_HSERDYIE_Pos)  /*!< 0x00000010 */
#define RCC_CIER_HSERDYIE                    RCC_CIER_HSERDYIE_Msk
#define RCC_CIER_PLLRDYIE_Pos                (5U)
#define RCC_CIER_PLLRDYIE_Msk                (0x1UL << RCC_CIER_PLLRDYIE_Pos)  /*!< 0x00000020 */
#define RCC_CIER_PLLRDYIE                    RCC_CIER_PLLRDYIE_Msk
#define RCC_CIER_LSECSSIE_Pos                (9U)
#define RCC_CIER_LSECSSIE_Msk                (0x1UL << RCC_CIER_LSECSSIE_Pos)  /*!< 0x00000200 */
#define RCC_CIER_LSECSSIE                    RCC_CIER_LSECSSIE_Msk
#define RCC_CIER_HSI48RDYIE_Pos              (10U)
#define RCC_CIER_HSI48RDYIE_Msk              (0x1UL << RCC_CIER_HSI48RDYIE_Pos)/*!< 0x00000400 */
#define RCC_CIER_HSI48RDYIE                  RCC_CIER_HSI48RDYIE_Msk

/********************  Bit definition for RCC_CIFR register  ******************/
#define RCC_CIFR_LSIRDYF_Pos                 (0U)
#define RCC_CIFR_LSIRDYF_Msk                 (0x1UL << RCC_CIFR_LSIRDYF_Pos)   /*!< 0x00000001 */
#define RCC_CIFR_LSIRDYF                     RCC_CIFR_LSIRDYF_Msk
#define RCC_CIFR_LSERDYF_Pos                 (1U)
#define RCC_CIFR_LSERDYF_Msk                 (0x1UL << RCC_CIFR_LSERDYF_Pos)   /*!< 0x00000002 */
#define RCC_CIFR_LSERDYF                     RCC_CIFR_LSERDYF_Msk
#define RCC_CIFR_HSIRDYF_Pos                 (3U)
#define RCC_CIFR_HSIRDYF_Msk                 (0x1UL << RCC_CIFR_HSIRDYF_Pos)   /*!< 0x00000008 */
#define RCC_CIFR_HSIRDYF                     RCC_CIFR_HSIRDYF_Msk
#define RCC_CIFR_HSERDYF_Pos                 (4U)
#define RCC_CIFR_HSERDYF_Msk                 (0x1UL << RCC_CIFR_HSERDYF_Pos)   /*!< 0x00000010 */
#define RCC_CIFR_HSERDYF                     RCC_CIFR_HSERDYF_Msk
#define RCC_CIFR_PLLRDYF_Pos                 (5U)
#define RCC_CIFR_PLLRDYF_Msk                 (0x1UL << RCC_CIFR_PLLRDYF_Pos)   /*!< 0x00000020 */
#define RCC_CIFR_PLLRDYF                     RCC_CIFR_PLLRDYF_Msk
#define RCC_CIFR_CSSF_Pos                    (8U)
#define RCC_CIFR_CSSF_Msk                    (0x1UL << RCC_CIFR_CSSF_Pos)      /*!< 0x00000100 */
#define RCC_CIFR_CSSF                        RCC_CIFR_CSSF_Msk
#define RCC_CIFR_LSECSSF_Pos                 (9U)
#define RCC_CIFR_LSECSSF_Msk                 (0x1UL << RCC_CIFR_LSECSSF_Pos)   /*!< 0x00000200 */
#define RCC_CIFR_LSECSSF                     RCC_CIFR_LSECSSF_Msk
#define RCC_CIFR_HSI48RDYF_Pos               (10U)
#define RCC_CIFR_HSI48RDYF_Msk               (0x1UL << RCC_CIFR_HSI48RDYF_Pos) /*!< 0x00000400 */
#define RCC_CIFR_HSI48RDYF                   RCC_CIFR_HSI48RDYF_Msk

/********************  Bit definition for RCC_CICR register  ******************/
#define RCC_CICR_LSIRDYC_Pos                 (0U)
#define RCC_CICR_LSIRDYC_Msk                 (0x1UL << RCC_CICR_LSIRDYC_Pos)   /*!< 0x00000001 */
#define RCC_CICR_LSIRDYC                     RCC_CICR_LSIRDYC_Msk
#define RCC_CICR_LSERDYC_Pos                 (1U)
#define RCC_CICR_LSERDYC_Msk                 (0x1UL << RCC_CICR_LSERDYC_Pos)   /*!< 0x00000002 */
#define RCC_CICR_LSERDYC                     RCC_CICR_LSERDYC_Msk
#define RCC_CICR_HSIRDYC_Pos                 (3U)
#define RCC_CICR_HSIRDYC_Msk                 (0x1UL << RCC_CICR_HSIRDYC_Pos)   /*!< 0x00000008 */
#define RCC_CICR_HSIRDYC                     RCC_CICR_HSIRDYC_Msk
#define RCC_CICR_HSERDYC_Pos                 (4U)
#define RCC_CICR_HSERDYC_Msk                 (0x1UL << RCC_CICR_HSERDYC_Pos)   /*!< 0x00000010 */
#define RCC_CICR_HSERDYC                     RCC_CICR_HSERDYC_Msk
#define RCC_CICR_PLLRDYC_Pos                 (5U)
#define RCC_CICR_PLLRDYC_Msk                 (0x1UL << RCC_CICR_PLLRDYC_Pos)   /*!< 0x00000020 */
#define RCC_CICR_PLLRDYC                     RCC_CICR_PLLRDYC_Msk
#define RCC_CICR_CSSC_Pos                    (8U)
#define RCC_CICR_CSSC_Msk                    (0x1UL << RCC_CICR_CSSC_Pos)      /*!< 0x00000100 */
#define RCC_CICR_CSSC                        RCC_CICR_CSSC_Msk
#define RCC_CICR_LSECSSC_Pos                 (9U)
#define RCC_CICR_LSECSSC_Msk                 (0x1UL << RCC_CICR_LSECSSC_Pos)   /*!< 0x00000200 */
#define RCC_CICR_LSECSSC                     RCC_CICR_LSECSSC_Msk
#define RCC_CICR_HSI48RDYC_Pos               (10U)
#define RCC_CICR_HSI48RDYC_Msk               (0x1UL << RCC_CICR_HSI48RDYC_Pos) /*!< 0x00000400 */
#define RCC_CICR_HSI48RDYC                   RCC_CICR_HSI48RDYC_Msk

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_DMA1RST_Pos             (0U)
#define RCC_AHB1RSTR_DMA1RST_Msk             (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos)/*!< 0x00000001 */
#define RCC_AHB1RSTR_DMA1RST                 RCC_AHB1RSTR_DMA1RST_Msk
#define RCC_AHB1RSTR_DMA2RST_Pos             (1U)
#define RCC_AHB1RSTR_DMA2RST_Msk             (0x1UL << RCC_AHB1RSTR_DMA2RST_Pos)/*!< 0x00000002 */
#define RCC_AHB1RSTR_DMA2RST                 RCC_AHB1RSTR_DMA2RST_Msk
#define RCC_AHB1RSTR_DMAMUX1RST_Pos          (2U)
#define RCC_AHB1RSTR_DMAMUX1RST_Msk          (0x1UL << RCC_AHB1RSTR_DMAMUX1RST_Pos)/*!< 0x00000004 */
#define RCC_AHB1RSTR_DMAMUX1RST              RCC_AHB1RSTR_DMAMUX1RST_Msk
#define RCC_AHB1RSTR_CORDICRST_Pos           (3U)
#define RCC_AHB1RSTR_CORDICRST_Msk           (0x1UL << RCC_AHB1RSTR_CORDICRST_Pos)/*!< 0x00000008 */
#define RCC_AHB1RSTR_CORDICRST               RCC_AHB1RSTR_CORDICRST_Msk
#define RCC_AHB1RSTR_FMACRST_Pos             (4U)
#define RCC_AHB1RSTR_FMACRST_Msk             (0x1UL << RCC_AHB1RSTR_FMACRST_Pos)  /*!< 0x00000010 */
#define RCC_AHB1RSTR_FMACRST                 RCC_AHB1RSTR_FMACRST_Msk
#define RCC_AHB1RSTR_FLASHRST_Pos            (8U)
#define RCC_AHB1RSTR_FLASHRST_Msk            (0x1UL << RCC_AHB1RSTR_FLASHRST_Pos)/*!< 0x00000100 */
#define RCC_AHB1RSTR_FLASHRST                RCC_AHB1RSTR_FLASHRST_Msk
#define RCC_AHB1RSTR_CRCRST_Pos              (12U)
#define RCC_AHB1RSTR_CRCRST_Msk              (0x1UL << RCC_AHB1RSTR_CRCRST_Pos)/*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST                  RCC_AHB1RSTR_CRCRST_Msk

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_GPIOARST_Pos            (0U)
#define RCC_AHB2RSTR_GPIOARST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOARST_Pos)/*!< 0x00000001 */
#define RCC_AHB2RSTR_GPIOARST                RCC_AHB2RSTR_GPIOARST_Msk
#define RCC_AHB2RSTR_GPIOBRST_Pos            (1U)
#define RCC_AHB2RSTR_GPIOBRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOBRST_Pos)/*!< 0x00000002 */
#define RCC_AHB2RSTR_GPIOBRST                RCC_AHB2RSTR_GPIOBRST_Msk
#define RCC_AHB2RSTR_GPIOCRST_Pos            (2U)
#define RCC_AHB2RSTR_GPIOCRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOCRST_Pos)/*!< 0x00000004 */
#define RCC_AHB2RSTR_GPIOCRST                RCC_AHB2RSTR_GPIOCRST_Msk
#define RCC_AHB2RSTR_GPIODRST_Pos            (3U)
#define RCC_AHB2RSTR_GPIODRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIODRST_Pos)/*!< 0x00000008 */
#define RCC_AHB2RSTR_GPIODRST                RCC_AHB2RSTR_GPIODRST_Msk
#define RCC_AHB2RSTR_GPIOERST_Pos            (4U)
#define RCC_AHB2RSTR_GPIOERST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOERST_Pos)/*!< 0x00000010 */
#define RCC_AHB2RSTR_GPIOERST                RCC_AHB2RSTR_GPIOERST_Msk
#define RCC_AHB2RSTR_GPIOFRST_Pos            (5U)
#define RCC_AHB2RSTR_GPIOFRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOFRST_Pos)/*!< 0x00000020 */
#define RCC_AHB2RSTR_GPIOFRST                RCC_AHB2RSTR_GPIOFRST_Msk
#define RCC_AHB2RSTR_GPIOGRST_Pos            (6U)
#define RCC_AHB2RSTR_GPIOGRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOGRST_Pos)/*!< 0x00000040 */
#define RCC_AHB2RSTR_GPIOGRST                RCC_AHB2RSTR_GPIOGRST_Msk
#define RCC_AHB2RSTR_ADC12RST_Pos            (13U)
#define RCC_AHB2RSTR_ADC12RST_Msk            (0x1UL << RCC_AHB2RSTR_ADC12RST_Pos)/*!< 0x00002000 */
#define RCC_AHB2RSTR_ADC12RST                RCC_AHB2RSTR_ADC12RST_Msk
#define RCC_AHB2RSTR_ADC345RST_Pos           (14U)
#define RCC_AHB2RSTR_ADC345RST_Msk           (0x1UL << RCC_AHB2RSTR_ADC345RST_Pos)/*!< 0x00004000 */
#define RCC_AHB2RSTR_ADC345RST               RCC_AHB2RSTR_ADC345RST_Msk
#define RCC_AHB2RSTR_DAC1RST_Pos             (16U)
#define RCC_AHB2RSTR_DAC1RST_Msk             (0x1UL << RCC_AHB2RSTR_DAC1RST_Pos)/*!< 0x00010000 */
#define RCC_AHB2RSTR_DAC1RST                 RCC_AHB2RSTR_DAC1RST_Msk
#define RCC_AHB2RSTR_DAC2RST_Pos             (17U)
#define RCC_AHB2RSTR_DAC2RST_Msk             (0x1UL << RCC_AHB2RSTR_DAC2RST_Pos)/*!< 0x00020000 */
#define RCC_AHB2RSTR_DAC2RST                 RCC_AHB2RSTR_DAC2RST_Msk
#define RCC_AHB2RSTR_DAC3RST_Pos             (18U)
#define RCC_AHB2RSTR_DAC3RST_Msk             (0x1UL << RCC_AHB2RSTR_DAC3RST_Pos)/*!< 0x00040000 */
#define RCC_AHB2RSTR_DAC3RST                 RCC_AHB2RSTR_DAC3RST_Msk
#define RCC_AHB2RSTR_DAC4RST_Pos             (19U)
#define RCC_AHB2RSTR_DAC4RST_Msk             (0x1UL << RCC_AHB2RSTR_DAC4RST_Pos)/*!< 0x00080000 */
#define RCC_AHB2RSTR_DAC4RST                 RCC_AHB2RSTR_DAC4RST_Msk
#define RCC_AHB2RSTR_RNGRST_Pos              (26U)
#define RCC_AHB2RSTR_RNGRST_Msk              (0x1UL << RCC_AHB2RSTR_RNGRST_Pos)/*!< 0x04000000 */
#define RCC_AHB2RSTR_RNGRST                  RCC_AHB2RSTR_RNGRST_Msk

/********************  Bit definition for RCC_AHB3RSTR register  **************/
#define RCC_AHB3RSTR_FMCRST_Pos              (0U)
#define RCC_AHB3RSTR_FMCRST_Msk              (0x1UL << RCC_AHB3RSTR_FMCRST_Pos)/*!< 0x00000001 */
#define RCC_AHB3RSTR_FMCRST                  RCC_AHB3RSTR_FMCRST_Msk
#define RCC_AHB3RSTR_QSPIRST_Pos             (8U)
#define RCC_AHB3RSTR_QSPIRST_Msk             (0x1UL << RCC_AHB3RSTR_QSPIRST_Pos)/*!< 0x00000100 */
#define RCC_AHB3RSTR_QSPIRST                 RCC_AHB3RSTR_QSPIRST_Msk

/********************  Bit definition for RCC_APB1RSTR1 register  **************/
#define RCC_APB1RSTR1_TIM2RST_Pos            (0U)
#define RCC_APB1RSTR1_TIM2RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM2RST_Pos)/*!< 0x00000001 */
#define RCC_APB1RSTR1_TIM2RST                RCC_APB1RSTR1_TIM2RST_Msk
#define RCC_APB1RSTR1_TIM3RST_Pos            (1U)
#define RCC_APB1RSTR1_TIM3RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM3RST_Pos)/*!< 0x00000002 */
#define RCC_APB1RSTR1_TIM3RST                RCC_APB1RSTR1_TIM3RST_Msk
#define RCC_APB1RSTR1_TIM4RST_Pos            (2U)
#define RCC_APB1RSTR1_TIM4RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM4RST_Pos)/*!< 0x00000004 */
#define RCC_APB1RSTR1_TIM4RST                RCC_APB1RSTR1_TIM4RST_Msk
#define RCC_APB1RSTR1_TIM5RST_Pos            (3U)
#define RCC_APB1RSTR1_TIM5RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM5RST_Pos)/*!< 0x00000008 */
#define RCC_APB1RSTR1_TIM5RST                RCC_APB1RSTR1_TIM5RST_Msk
#define RCC_APB1RSTR1_TIM6RST_Pos            (4U)
#define RCC_APB1RSTR1_TIM6RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM6RST_Pos)/*!< 0x00000010 */
#define RCC_APB1RSTR1_TIM6RST                RCC_APB1RSTR1_TIM6RST_Msk
#define RCC_APB1RSTR1_TIM7RST_Pos            (5U)
#define RCC_APB1RSTR1_TIM7RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM7RST_Pos)/*!< 0x00000020 */
#define RCC_APB1RSTR1_TIM7RST                RCC_APB1RSTR1_TIM7RST_Msk
#define RCC_APB1RSTR1_CRSRST_Pos             (8U)
#define RCC_APB1RSTR1_CRSRST_Msk             (0x1UL << RCC_APB1RSTR1_CRSRST_Pos)/*!< 0x00000100 */
#define RCC_APB1RSTR1_CRSRST                 RCC_APB1RSTR1_CRSRST_Msk
#define RCC_APB1RSTR1_SPI2RST_Pos            (14U)
#define RCC_APB1RSTR1_SPI2RST_Msk            (0x1UL << RCC_APB1RSTR1_SPI2RST_Pos)/*!< 0x00004000 */
#define RCC_APB1RSTR1_SPI2RST                RCC_APB1RSTR1_SPI2RST_Msk
#define RCC_APB1RSTR1_SPI3RST_Pos            (15U)
#define RCC_APB1RSTR1_SPI3RST_Msk            (0x1UL << RCC_APB1RSTR1_SPI3RST_Pos)/*!< 0x00008000 */
#define RCC_APB1RSTR1_SPI3RST                RCC_APB1RSTR1_SPI3RST_Msk
#define RCC_APB1RSTR1_USART2RST_Pos          (17U)
#define RCC_APB1RSTR1_USART2RST_Msk          (0x1UL << RCC_APB1RSTR1_USART2RST_Pos)/*!< 0x00020000 */
#define RCC_APB1RSTR1_USART2RST              RCC_APB1RSTR1_USART2RST_Msk
#define RCC_APB1RSTR1_USART3RST_Pos          (18U)
#define RCC_APB1RSTR1_USART3RST_Msk          (0x1UL << RCC_APB1RSTR1_USART3RST_Pos)/*!< 0x00040000 */
#define RCC_APB1RSTR1_USART3RST              RCC_APB1RSTR1_USART3RST_Msk
#define RCC_APB1RSTR1_UART4RST_Pos           (19U)
#define RCC_APB1RSTR1_UART4RST_Msk           (0x1UL << RCC_APB1RSTR1_UART4RST_Pos)/*!< 0x00080000 */
#define RCC_APB1RSTR1_UART4RST               RCC_APB1RSTR1_UART4RST_Msk
#define RCC_APB1RSTR1_UART5RST_Pos           (20U)
#define RCC_APB1RSTR1_UART5RST_Msk           (0x1UL << RCC_APB1RSTR1_UART5RST_Pos)/*!< 0x00100000 */
#define RCC_APB1RSTR1_UART5RST               RCC_APB1RSTR1_UART5RST_Msk
#define RCC_APB1RSTR1_I2C1RST_Pos            (21U)
#define RCC_APB1RSTR1_I2C1RST_Msk            (0x1UL << RCC_APB1RSTR1_I2C1RST_Pos)/*!< 0x00200000 */
#define RCC_APB1RSTR1_I2C1RST                RCC_APB1RSTR1_I2C1RST_Msk
#define RCC_APB1RSTR1_I2C2RST_Pos            (22U)
#define RCC_APB1RSTR1_I2C2RST_Msk            (0x1UL << RCC_APB1RSTR1_I2C2RST_Pos)/*!< 0x00400000 */
#define RCC_APB1RSTR1_I2C2RST                RCC_APB1RSTR1_I2C2RST_Msk
#define RCC_APB1RSTR1_USBRST_Pos             (23U)
#define RCC_APB1RSTR1_USBRST_Msk             (0x1UL << RCC_APB1RSTR1_USBRST_Pos)/*!< 0x00800000 */
#define RCC_APB1RSTR1_USBRST                 RCC_APB1RSTR1_USBRST_Msk
#define RCC_APB1RSTR1_FDCANRST_Pos           (25U)
#define RCC_APB1RSTR1_FDCANRST_Msk           (0x1UL << RCC_APB1RSTR1_FDCANRST_Pos)/*!< 0x02000000 */
#define RCC_APB1RSTR1_FDCANRST               RCC_APB1RSTR1_FDCANRST_Msk
#define RCC_APB1RSTR1_PWRRST_Pos             (28U)
#define RCC_APB1RSTR1_PWRRST_Msk             (0x1UL << RCC_APB1RSTR1_PWRRST_Pos)/*!< 0x10000000 */
#define RCC_APB1RSTR1_PWRRST                 RCC_APB1RSTR1_PWRRST_Msk
#define RCC_APB1RSTR1_I2C3RST_Pos            (30U)
#define RCC_APB1RSTR1_I2C3RST_Msk            (0x1UL << RCC_APB1RSTR1_I2C3RST_Pos)/*!< 0x40000000 */
#define RCC_APB1RSTR1_I2C3RST                RCC_APB1RSTR1_I2C3RST_Msk
#define RCC_APB1RSTR1_LPTIM1RST_Pos          (31U)
#define RCC_APB1RSTR1_LPTIM1RST_Msk          (0x1UL << RCC_APB1RSTR1_LPTIM1RST_Pos)/*!< 0x80000000 */
#define RCC_APB1RSTR1_LPTIM1RST              RCC_APB1RSTR1_LPTIM1RST_Msk

/********************  Bit definition for RCC_APB1RSTR2 register  **************/
#define RCC_APB1RSTR2_LPUART1RST_Pos         (0U)
#define RCC_APB1RSTR2_LPUART1RST_Msk         (0x1UL << RCC_APB1RSTR2_LPUART1RST_Pos)/*!< 0x00000001 */
#define RCC_APB1RSTR2_LPUART1RST             RCC_APB1RSTR2_LPUART1RST_Msk
#define RCC_APB1RSTR2_I2C4RST_Pos            (1U)
#define RCC_APB1RSTR2_I2C4RST_Msk            (0x1UL << RCC_APB1RSTR2_I2C4RST_Pos)/*!< 0x00000002 */
#define RCC_APB1RSTR2_I2C4RST                RCC_APB1RSTR2_I2C4RST_Msk
#define RCC_APB1RSTR2_UCPD1RST_Pos           (8U)
#define RCC_APB1RSTR2_UCPD1RST_Msk           (0x1UL << RCC_APB1RSTR2_UCPD1RST_Pos)/*!< 0x00000100 */
#define RCC_APB1RSTR2_UCPD1RST               RCC_APB1RSTR2_UCPD1RST_Msk

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_SYSCFGRST_Pos           (0U)
#define RCC_APB2RSTR_SYSCFGRST_Msk           (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos)/*!< 0x00000001 */
#define RCC_APB2RSTR_SYSCFGRST               RCC_APB2RSTR_SYSCFGRST_Msk
#define RCC_APB2RSTR_TIM1RST_Pos             (11U)
#define RCC_APB2RSTR_TIM1RST_Msk             (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)/*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST                 RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_SPI1RST_Pos             (12U)
#define RCC_APB2RSTR_SPI1RST_Msk             (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)/*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST                 RCC_APB2RSTR_SPI1RST_Msk
#define RCC_APB2RSTR_TIM8RST_Pos             (13U)
#define RCC_APB2RSTR_TIM8RST_Msk             (0x1UL << RCC_APB2RSTR_TIM8RST_Pos)/*!< 0x00002000 */
#define RCC_APB2RSTR_TIM8RST                 RCC_APB2RSTR_TIM8RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos           (14U)
#define RCC_APB2RSTR_USART1RST_Msk           (0x1UL << RCC_APB2RSTR_USART1RST_Pos)/*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST               RCC_APB2RSTR_USART1RST_Msk
#define RCC_APB2RSTR_SPI4RST_Pos             (15U)
#define RCC_APB2RSTR_SPI4RST_Msk             (0x1UL << RCC_APB2RSTR_SPI4RST_Pos)/*!< 0x00008000 */
#define RCC_APB2RSTR_SPI4RST                 RCC_APB2RSTR_SPI4RST_Msk
#define RCC_APB2RSTR_TIM15RST_Pos            (16U)
#define RCC_APB2RSTR_TIM15RST_Msk            (0x1UL << RCC_APB2RSTR_TIM15RST_Pos)/*!< 0x00010000 */
#define RCC_APB2RSTR_TIM15RST                RCC_APB2RSTR_TIM15RST_Msk
#define RCC_APB2RSTR_TIM16RST_Pos            (17U)
#define RCC_APB2RSTR_TIM16RST_Msk            (0x1UL << RCC_APB2RSTR_TIM16RST_Pos)/*!< 0x00020000 */
#define RCC_APB2RSTR_TIM16RST                RCC_APB2RSTR_TIM16RST_Msk
#define RCC_APB2RSTR_TIM17RST_Pos            (18U)
#define RCC_APB2RSTR_TIM17RST_Msk            (0x1UL << RCC_APB2RSTR_TIM17RST_Pos)/*!< 0x00040000 */
#define RCC_APB2RSTR_TIM17RST                RCC_APB2RSTR_TIM17RST_Msk
#define RCC_APB2RSTR_TIM20RST_Pos            (20U)
#define RCC_APB2RSTR_TIM20RST_Msk            (0x1UL << RCC_APB2RSTR_TIM20RST_Pos)/*!< 0x00100000 */
#define RCC_APB2RSTR_TIM20RST                RCC_APB2RSTR_TIM20RST_Msk
#define RCC_APB2RSTR_SAI1RST_Pos             (21U)
#define RCC_APB2RSTR_SAI1RST_Msk             (0x1UL << RCC_APB2RSTR_SAI1RST_Pos)/*!< 0x00200000 */
#define RCC_APB2RSTR_SAI1RST                 RCC_APB2RSTR_SAI1RST_Msk
#define RCC_APB2RSTR_HRTIM1RST_Pos           (26U)
#define RCC_APB2RSTR_HRTIM1RST_Msk           (0x1UL << RCC_APB2RSTR_HRTIM1RST_Pos)/*!< 0x04000000 */
#define RCC_APB2RSTR_HRTIM1RST               RCC_APB2RSTR_HRTIM1RST_Msk

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_DMA1EN_Pos               (0U)
#define RCC_AHB1ENR_DMA1EN_Msk               (0x1UL << RCC_AHB1ENR_DMA1EN_Pos) /*!< 0x00000001 */
#define RCC_AHB1ENR_DMA1EN                   RCC_AHB1ENR_DMA1EN_Msk
#define RCC_AHB1ENR_DMA2EN_Pos               (1U)
#define RCC_AHB1ENR_DMA2EN_Msk               (0x1UL << RCC_AHB1ENR_DMA2EN_Pos) /*!< 0x00000002 */
#define RCC_AHB1ENR_DMA2EN                   RCC_AHB1ENR_DMA2EN_Msk
#define RCC_AHB1ENR_DMAMUX1EN_Pos            (2U)
#define RCC_AHB1ENR_DMAMUX1EN_Msk            (0x1UL << RCC_AHB1ENR_DMAMUX1EN_Pos)/*!< 0x00000004 */
#define RCC_AHB1ENR_DMAMUX1EN                RCC_AHB1ENR_DMAMUX1EN_Msk
#define RCC_AHB1ENR_CORDICEN_Pos             (3U)
#define RCC_AHB1ENR_CORDICEN_Msk             (0x1UL << RCC_AHB1ENR_CORDICEN_Pos)/*!< 0x00000008 */
#define RCC_AHB1ENR_CORDICEN                 RCC_AHB1ENR_CORDICEN_Msk
#define RCC_AHB1ENR_FMACEN_Pos               (4U)
#define RCC_AHB1ENR_FMACEN_Msk               (0x1UL << RCC_AHB1ENR_FMACEN_Pos)  /*!< 0x00000010 */
#define RCC_AHB1ENR_FMACEN                   RCC_AHB1ENR_FMACEN_Msk
#define RCC_AHB1ENR_FLASHEN_Pos              (8U)
#define RCC_AHB1ENR_FLASHEN_Msk              (0x1UL << RCC_AHB1ENR_FLASHEN_Pos)/*!< 0x00000100 */
#define RCC_AHB1ENR_FLASHEN                  RCC_AHB1ENR_FLASHEN_Msk
#define RCC_AHB1ENR_CRCEN_Pos                (12U)
#define RCC_AHB1ENR_CRCEN_Msk                (0x1UL << RCC_AHB1ENR_CRCEN_Pos)  /*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN                    RCC_AHB1ENR_CRCEN_Msk

/********************  Bit definition for RCC_AHB2ENR register  ***************/
#define RCC_AHB2ENR_GPIOAEN_Pos              (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOAEN_Pos)/*!< 0x00000001 */
#define RCC_AHB2ENR_GPIOAEN                  RCC_AHB2ENR_GPIOAEN_Msk
#define RCC_AHB2ENR_GPIOBEN_Pos              (1U)
#define RCC_AHB2ENR_GPIOBEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOBEN_Pos)/*!< 0x00000002 */
#define RCC_AHB2ENR_GPIOBEN                  RCC_AHB2ENR_GPIOBEN_Msk
#define RCC_AHB2ENR_GPIOCEN_Pos              (2U)
#define RCC_AHB2ENR_GPIOCEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOCEN_Pos)/*!< 0x00000004 */
#define RCC_AHB2ENR_GPIOCEN                  RCC_AHB2ENR_GPIOCEN_Msk
#define RCC_AHB2ENR_GPIODEN_Pos              (3U)
#define RCC_AHB2ENR_GPIODEN_Msk              (0x1UL << RCC_AHB2ENR_GPIODEN_Pos)/*!< 0x00000008 */
#define RCC_AHB2ENR_GPIODEN                  RCC_AHB2ENR_GPIODEN_Msk
#define RCC_AHB2ENR_GPIOEEN_Pos              (4U)
#define RCC_AHB2ENR_GPIOEEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOEEN_Pos)/*!< 0x00000010 */
#define RCC_AHB2ENR_GPIOEEN                  RCC_AHB2ENR_GPIOEEN_Msk
#define RCC_AHB2ENR_GPIOFEN_Pos              (5U)
#define RCC_AHB2ENR_GPIOFEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOFEN_Pos)/*!< 0x00000020 */
#define RCC_AHB2ENR_GPIOFEN                  RCC_AHB2ENR_GPIOFEN_Msk
#define RCC_AHB2ENR_GPIOGEN_Pos              (6U)
#define RCC_AHB2ENR_GPIOGEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOGEN_Pos)/*!< 0x00000040 */
#define RCC_AHB2ENR_GPIOGEN                  RCC_AHB2ENR_GPIOGEN_Msk
#define RCC_AHB2ENR_ADC12EN_Pos              (13U)
#define RCC_AHB2ENR_ADC12EN_Msk              (0x1UL << RCC_AHB2ENR_ADC12EN_Pos)  /*!< 0x00002000 */
#define RCC_AHB2ENR_ADC12EN                  RCC_AHB2ENR_ADC12EN_Msk
#define RCC_AHB2ENR_ADC345EN_Pos             (14U)
#define RCC_AHB2ENR_ADC345EN_Msk             (0x1UL << RCC_AHB2ENR_ADC345EN_Pos)  /*!< 0x00004000 */
#define RCC_AHB2ENR_ADC345EN                 RCC_AHB2ENR_ADC345EN_Msk
#define RCC_AHB2ENR_DAC1EN_Pos               (16U)
#define RCC_AHB2ENR_DAC1EN_Msk               (0x1UL << RCC_AHB2ENR_DAC1EN_Pos)  /*!< 0x00010000 */
#define RCC_AHB2ENR_DAC1EN                   RCC_AHB2ENR_DAC1EN_Msk
#define RCC_AHB2ENR_DAC2EN_Pos               (17U)
#define RCC_AHB2ENR_DAC2EN_Msk               (0x1UL << RCC_AHB2ENR_DAC2EN_Pos)  /*!< 0x00020000 */
#define RCC_AHB2ENR_DAC2EN                   RCC_AHB2ENR_DAC2EN_Msk
#define RCC_AHB2ENR_DAC3EN_Pos               (18U)
#define RCC_AHB2ENR_DAC3EN_Msk               (0x1UL << RCC_AHB2ENR_DAC3EN_Pos)  /*!< 0x00040000 */
#define RCC_AHB2ENR_DAC3EN                   RCC_AHB2ENR_DAC3EN_Msk
#define RCC_AHB2ENR_DAC4EN_Pos               (19U)
#define RCC_AHB2ENR_DAC4EN_Msk               (0x1UL << RCC_AHB2ENR_DAC4EN_Pos)  /*!< 0x00080000 */
#define RCC_AHB2ENR_DAC4EN                   RCC_AHB2ENR_DAC4EN_Msk
#define RCC_AHB2ENR_RNGEN_Pos                (26U)
#define RCC_AHB2ENR_RNGEN_Msk                (0x1UL << RCC_AHB2ENR_RNGEN_Pos)  /*!< 0x04000000 */
#define RCC_AHB2ENR_RNGEN                    RCC_AHB2ENR_RNGEN_Msk

/********************  Bit definition for RCC_AHB3ENR register  ***************/
#define RCC_AHB3ENR_FMCEN_Pos                (0U)
#define RCC_AHB3ENR_FMCEN_Msk                (0x1UL << RCC_AHB3ENR_FMCEN_Pos)  /*!< 0x00000001 */
#define RCC_AHB3ENR_FMCEN                    RCC_AHB3ENR_FMCEN_Msk
#define RCC_AHB3ENR_QSPIEN_Pos               (8U)
#define RCC_AHB3ENR_QSPIEN_Msk               (0x1UL << RCC_AHB3ENR_QSPIEN_Pos)  /*!< 0x00000100 */
#define RCC_AHB3ENR_QSPIEN                   RCC_AHB3ENR_QSPIEN_Msk

/********************  Bit definition for RCC_APB1ENR1 register  ***************/
#define RCC_APB1ENR1_TIM2EN_Pos              (0U)
#define RCC_APB1ENR1_TIM2EN_Msk              (0x1UL << RCC_APB1ENR1_TIM2EN_Pos)/*!< 0x00000001 */
#define RCC_APB1ENR1_TIM2EN                  RCC_APB1ENR1_TIM2EN_Msk
#define RCC_APB1ENR1_TIM3EN_Pos              (1U)
#define RCC_APB1ENR1_TIM3EN_Msk              (0x1UL << RCC_APB1ENR1_TIM3EN_Pos)/*!< 0x00000002 */
#define RCC_APB1ENR1_TIM3EN                  RCC_APB1ENR1_TIM3EN_Msk
#define RCC_APB1ENR1_TIM4EN_Pos              (2U)
#define RCC_APB1ENR1_TIM4EN_Msk              (0x1UL << RCC_APB1ENR1_TIM4EN_Pos)/*!< 0x00000004 */
#define RCC_APB1ENR1_TIM4EN                  RCC_APB1ENR1_TIM4EN_Msk
#define RCC_APB1ENR1_TIM5EN_Pos              (3U)
#define RCC_APB1ENR1_TIM5EN_Msk              (0x1UL << RCC_APB1ENR1_TIM5EN_Pos)/*!< 0x00000008 */
#define RCC_APB1ENR1_TIM5EN                  RCC_APB1ENR1_TIM5EN_Msk
#define RCC_APB1ENR1_TIM6EN_Pos              (4U)
#define RCC_APB1ENR1_TIM6EN_Msk              (0x1UL << RCC_APB1ENR1_TIM6EN_Pos)/*!< 0x00000010 */
#define RCC_APB1ENR1_TIM6EN                  RCC_APB1ENR1_TIM6EN_Msk
#define RCC_APB1ENR1_TIM7EN_Pos              (5U)
#define RCC_APB1ENR1_TIM7EN_Msk              (0x1UL << RCC_APB1ENR1_TIM7EN_Pos)/*!< 0x00000020 */
#define RCC_APB1ENR1_TIM7EN                  RCC_APB1ENR1_TIM7EN_Msk
#define RCC_APB1ENR1_CRSEN_Pos               (8U)
#define RCC_APB1ENR1_CRSEN_Msk               (0x1UL << RCC_APB1ENR1_CRSEN_Pos) /*!< 0x00000100 */
#define RCC_APB1ENR1_CRSEN                   RCC_APB1ENR1_CRSEN_Msk
#define RCC_APB1ENR1_RTCAPBEN_Pos            (10U)
#define RCC_APB1ENR1_RTCAPBEN_Msk            (0x1UL << RCC_APB1ENR1_RTCAPBEN_Pos)/*!< 0x00000400 */
#define RCC_APB1ENR1_RTCAPBEN                RCC_APB1ENR1_RTCAPBEN_Msk
#define RCC_APB1ENR1_WWDGEN_Pos              (11U)
#define RCC_APB1ENR1_WWDGEN_Msk              (0x1UL << RCC_APB1ENR1_WWDGEN_Pos)/*!< 0x00000800 */
#define RCC_APB1ENR1_WWDGEN                  RCC_APB1ENR1_WWDGEN_Msk
#define RCC_APB1ENR1_SPI2EN_Pos              (14U)
#define RCC_APB1ENR1_SPI2EN_Msk              (0x1UL << RCC_APB1ENR1_SPI2EN_Pos)/*!< 0x00004000 */
#define RCC_APB1ENR1_SPI2EN                  RCC_APB1ENR1_SPI2EN_Msk
#define RCC_APB1ENR1_SPI3EN_Pos              (15U)
#define RCC_APB1ENR1_SPI3EN_Msk              (0x1UL << RCC_APB1ENR1_SPI3EN_Pos)/*!< 0x00008000 */
#define RCC_APB1ENR1_SPI3EN                  RCC_APB1ENR1_SPI3EN_Msk
#define RCC_APB1ENR1_USART2EN_Pos            (17U)
#define RCC_APB1ENR1_USART2EN_Msk            (0x1UL << RCC_APB1ENR1_USART2EN_Pos)/*!< 0x00020000 */
#define RCC_APB1ENR1_USART2EN                RCC_APB1ENR1_USART2EN_Msk
#define RCC_APB1ENR1_USART3EN_Pos            (18U)
#define RCC_APB1ENR1_USART3EN_Msk            (0x1UL << RCC_APB1ENR1_USART3EN_Pos)/*!< 0x00040000 */
#define RCC_APB1ENR1_USART3EN                RCC_APB1ENR1_USART3EN_Msk
#define RCC_APB1ENR1_UART4EN_Pos             (19U)
#define RCC_APB1ENR1_UART4EN_Msk             (0x1UL << RCC_APB1ENR1_UART4EN_Pos)/*!< 0x00080000 */
#define RCC_APB1ENR1_UART4EN                 RCC_APB1ENR1_UART4EN_Msk
#define RCC_APB1ENR1_UART5EN_Pos             (20U)
#define RCC_APB1ENR1_UART5EN_Msk             (0x1UL << RCC_APB1ENR1_UART5EN_Pos)/*!< 0x00100000 */
#define RCC_APB1ENR1_UART5EN                 RCC_APB1ENR1_UART5EN_Msk
#define RCC_APB1ENR1_I2C1EN_Pos              (21U)
#define RCC_APB1ENR1_I2C1EN_Msk              (0x1UL << RCC_APB1ENR1_I2C1EN_Pos)/*!< 0x00200000 */
#define RCC_APB1ENR1_I2C1EN                  RCC_APB1ENR1_I2C1EN_Msk
#define RCC_APB1ENR1_I2C2EN_Pos              (22U)
#define RCC_APB1ENR1_I2C2EN_Msk              (0x1UL << RCC_APB1ENR1_I2C2EN_Pos)/*!< 0x00400000 */
#define RCC_APB1ENR1_I2C2EN                  RCC_APB1ENR1_I2C2EN_Msk
#define RCC_APB1ENR1_USBEN_Pos               (23U)
#define RCC_APB1ENR1_USBEN_Msk               (0x1UL << RCC_APB1ENR1_USBEN_Pos)/*!< 0x00800000 */
#define RCC_APB1ENR1_USBEN                   RCC_APB1ENR1_USBEN_Msk
#define RCC_APB1ENR1_FDCANEN_Pos             (25U)
#define RCC_APB1ENR1_FDCANEN_Msk             (0x1UL << RCC_APB1ENR1_FDCANEN_Pos)/*!< 0x02000000 */
#define RCC_APB1ENR1_FDCANEN                 RCC_APB1ENR1_FDCANEN_Msk
#define RCC_APB1ENR1_PWREN_Pos               (28U)
#define RCC_APB1ENR1_PWREN_Msk               (0x1UL << RCC_APB1ENR1_PWREN_Pos) /*!< 0x10000000 */
#define RCC_APB1ENR1_PWREN                   RCC_APB1ENR1_PWREN_Msk
#define RCC_APB1ENR1_I2C3EN_Pos              (30U)
#define RCC_APB1ENR1_I2C3EN_Msk              (0x1UL << RCC_APB1ENR1_I2C3EN_Pos)/*!< 0x40000000 */
#define RCC_APB1ENR1_I2C3EN                  RCC_APB1ENR1_I2C3EN_Msk
#define RCC_APB1ENR1_LPTIM1EN_Pos            (31U)
#define RCC_APB1ENR1_LPTIM1EN_Msk            (0x1UL << RCC_APB1ENR1_LPTIM1EN_Pos)/*!< 0x80000000 */
#define RCC_APB1ENR1_LPTIM1EN                RCC_APB1ENR1_LPTIM1EN_Msk

/********************  Bit definition for RCC_APB1RSTR2 register  **************/
#define RCC_APB1ENR2_LPUART1EN_Pos           (0U)
#define RCC_APB1ENR2_LPUART1EN_Msk           (0x1UL << RCC_APB1ENR2_LPUART1EN_Pos)/*!< 0x00000001 */
#define RCC_APB1ENR2_LPUART1EN               RCC_APB1ENR2_LPUART1EN_Msk
#define RCC_APB1ENR2_I2C4EN_Pos              (1U)
#define RCC_APB1ENR2_I2C4EN_Msk              (0x1UL << RCC_APB1ENR2_I2C4EN_Pos)/*!< 0x00000002 */
#define RCC_APB1ENR2_I2C4EN                  RCC_APB1ENR2_I2C4EN_Msk
#define RCC_APB1ENR2_UCPD1EN_Pos             (8U)
#define RCC_APB1ENR2_UCPD1EN_Msk             (0x1UL << RCC_APB1ENR2_UCPD1EN_Pos)/*!< 0x00000100 */
#define RCC_APB1ENR2_UCPD1EN                 RCC_APB1ENR2_UCPD1EN_Msk

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_SYSCFGEN_Pos             (0U)
#define RCC_APB2ENR_SYSCFGEN_Msk             (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)/*!< 0x00000001 */
#define RCC_APB2ENR_SYSCFGEN                 RCC_APB2ENR_SYSCFGEN_Msk
#define RCC_APB2ENR_TIM1EN_Pos               (11U)
#define RCC_APB2ENR_TIM1EN_Msk               (0x1UL << RCC_APB2ENR_TIM1EN_Pos) /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                   RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_SPI1EN_Pos               (12U)
#define RCC_APB2ENR_SPI1EN_Msk               (0x1UL << RCC_APB2ENR_SPI1EN_Pos) /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                   RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_TIM8EN_Pos               (13U)
#define RCC_APB2ENR_TIM8EN_Msk               (0x1UL << RCC_APB2ENR_TIM8EN_Pos) /*!< 0x00002000 */
#define RCC_APB2ENR_TIM8EN                   RCC_APB2ENR_TIM8EN_Msk
#define RCC_APB2ENR_USART1EN_Pos             (14U)
#define RCC_APB2ENR_USART1EN_Msk             (0x1UL << RCC_APB2ENR_USART1EN_Pos)/*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                 RCC_APB2ENR_USART1EN_Msk
#define RCC_APB2ENR_SPI4EN_Pos               (15U)
#define RCC_APB2ENR_SPI4EN_Msk               (0x1UL << RCC_APB2ENR_SPI4EN_Pos) /*!< 0x00008000 */
#define RCC_APB2ENR_SPI4EN                   RCC_APB2ENR_SPI4EN_Msk
#define RCC_APB2ENR_TIM15EN_Pos              (16U)
#define RCC_APB2ENR_TIM15EN_Msk              (0x1UL << RCC_APB2ENR_TIM15EN_Pos)/*!< 0x00010000 */
#define RCC_APB2ENR_TIM15EN                  RCC_APB2ENR_TIM15EN_Msk
#define RCC_APB2ENR_TIM16EN_Pos              (17U)
#define RCC_APB2ENR_TIM16EN_Msk              (0x1UL << RCC_APB2ENR_TIM16EN_Pos)/*!< 0x00020000 */
#define RCC_APB2ENR_TIM16EN                  RCC_APB2ENR_TIM16EN_Msk
#define RCC_APB2ENR_TIM17EN_Pos              (18U)
#define RCC_APB2ENR_TIM17EN_Msk              (0x1UL << RCC_APB2ENR_TIM17EN_Pos)/*!< 0x00040000 */
#define RCC_APB2ENR_TIM17EN                  RCC_APB2ENR_TIM17EN_Msk
#define RCC_APB2ENR_TIM20EN_Pos              (20U)
#define RCC_APB2ENR_TIM20EN_Msk              (0x1UL << RCC_APB2ENR_TIM20EN_Pos)/*!< 0x00100000 */
#define RCC_APB2ENR_TIM20EN                  RCC_APB2ENR_TIM20EN_Msk
#define RCC_APB2ENR_SAI1EN_Pos               (21U)
#define RCC_APB2ENR_SAI1EN_Msk               (0x1UL << RCC_APB2ENR_SAI1EN_Pos)/*!< 0x00200000 */
#define RCC_APB2ENR_SAI1EN                   RCC_APB2ENR_SAI1EN_Msk
#define RCC_APB2ENR_HRTIM1EN_Pos              (26U)
#define RCC_APB2ENR_HRTIM1EN_Msk              (0x1UL << RCC_APB2ENR_HRTIM1EN_Pos)/*!< 0x04000000 */
#define RCC_APB2ENR_HRTIM1EN                  RCC_APB2ENR_HRTIM1EN_Msk

/********************  Bit definition for RCC_AHB1SMENR register  ***************/
#define RCC_AHB1SMENR_DMA1SMEN_Pos           (0U)
#define RCC_AHB1SMENR_DMA1SMEN_Msk           (0x1UL << RCC_AHB1SMENR_DMA1SMEN_Pos)/*!< 0x00000001 */
#define RCC_AHB1SMENR_DMA1SMEN               RCC_AHB1SMENR_DMA1SMEN_Msk
#define RCC_AHB1SMENR_DMA2SMEN_Pos           (1U)
#define RCC_AHB1SMENR_DMA2SMEN_Msk           (0x1UL << RCC_AHB1SMENR_DMA2SMEN_Pos)/*!< 0x00000002 */
#define RCC_AHB1SMENR_DMA2SMEN               RCC_AHB1SMENR_DMA2SMEN_Msk
#define RCC_AHB1SMENR_DMAMUX1SMEN_Pos        (2U)
#define RCC_AHB1SMENR_DMAMUX1SMEN_Msk        (0x1UL << RCC_AHB1SMENR_DMAMUX1SMEN_Pos)/*!< 0x00000004 */
#define RCC_AHB1SMENR_DMAMUX1SMEN            RCC_AHB1SMENR_DMAMUX1SMEN_Msk
#define RCC_AHB1SMENR_CORDICSMEN_Pos         (3U)
#define RCC_AHB1SMENR_CORDICSMEN_Msk         (0x1UL << RCC_AHB1SMENR_CORDICSMEN_Pos)/*!< 0x00000008 */
#define RCC_AHB1SMENR_CORDICSMEN             RCC_AHB1SMENR_CORDICSMEN_Msk
#define RCC_AHB1SMENR_FMACSMEN_Pos           (4U)
#define RCC_AHB1SMENR_FMACSMEN_Msk           (0x1UL << RCC_AHB1SMENR_FMACSMEN_Pos)  /*!< 0x00000010 */
#define RCC_AHB1SMENR_FMACSMEN               RCC_AHB1SMENR_FMACSMEN_Msk
#define RCC_AHB1SMENR_FLASHSMEN_Pos          (8U)
#define RCC_AHB1SMENR_FLASHSMEN_Msk          (0x1UL << RCC_AHB1SMENR_FLASHSMEN_Pos)/*!< 0x00000100 */
#define RCC_AHB1SMENR_FLASHSMEN              RCC_AHB1SMENR_FLASHSMEN_Msk
#define RCC_AHB1SMENR_SRAM1SMEN_Pos          (9U)
#define RCC_AHB1SMENR_SRAM1SMEN_Msk          (0x1UL << RCC_AHB1SMENR_SRAM1SMEN_Pos)/*!< 0x00000200 */
#define RCC_AHB1SMENR_SRAM1SMEN              RCC_AHB1SMENR_SRAM1SMEN_Msk
#define RCC_AHB1SMENR_CRCSMEN_Pos            (12U)
#define RCC_AHB1SMENR_CRCSMEN_Msk            (0x1UL << RCC_AHB1SMENR_CRCSMEN_Pos)/*!< 0x00001000 */
#define RCC_AHB1SMENR_CRCSMEN                RCC_AHB1SMENR_CRCSMEN_Msk

/********************  Bit definition for RCC_AHB2SMENR register  *************/
#define RCC_AHB2SMENR_GPIOASMEN_Pos          (0U)
#define RCC_AHB2SMENR_GPIOASMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOASMEN_Pos)/*!< 0x00000001 */
#define RCC_AHB2SMENR_GPIOASMEN              RCC_AHB2SMENR_GPIOASMEN_Msk
#define RCC_AHB2SMENR_GPIOBSMEN_Pos          (1U)
#define RCC_AHB2SMENR_GPIOBSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOBSMEN_Pos)/*!< 0x00000002 */
#define RCC_AHB2SMENR_GPIOBSMEN              RCC_AHB2SMENR_GPIOBSMEN_Msk
#define RCC_AHB2SMENR_GPIOCSMEN_Pos          (2U)
#define RCC_AHB2SMENR_GPIOCSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOCSMEN_Pos)/*!< 0x00000004 */
#define RCC_AHB2SMENR_GPIOCSMEN              RCC_AHB2SMENR_GPIOCSMEN_Msk
#define RCC_AHB2SMENR_GPIODSMEN_Pos          (3U)
#define RCC_AHB2SMENR_GPIODSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIODSMEN_Pos)/*!< 0x00000008 */
#define RCC_AHB2SMENR_GPIODSMEN              RCC_AHB2SMENR_GPIODSMEN_Msk
#define RCC_AHB2SMENR_GPIOESMEN_Pos          (4U)
#define RCC_AHB2SMENR_GPIOESMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOESMEN_Pos)/*!< 0x00000010 */
#define RCC_AHB2SMENR_GPIOESMEN              RCC_AHB2SMENR_GPIOESMEN_Msk
#define RCC_AHB2SMENR_GPIOFSMEN_Pos          (5U)
#define RCC_AHB2SMENR_GPIOFSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOFSMEN_Pos)/*!< 0x00000020 */
#define RCC_AHB2SMENR_GPIOFSMEN              RCC_AHB2SMENR_GPIOFSMEN_Msk
#define RCC_AHB2SMENR_GPIOGSMEN_Pos          (6U)
#define RCC_AHB2SMENR_GPIOGSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOGSMEN_Pos)/*!< 0x00000040 */
#define RCC_AHB2SMENR_GPIOGSMEN              RCC_AHB2SMENR_GPIOGSMEN_Msk
#define RCC_AHB2SMENR_CCMSRAMSMEN_Pos        (9U)
#define RCC_AHB2SMENR_CCMSRAMSMEN_Msk        (0x1UL << RCC_AHB2SMENR_CCMSRAMSMEN_Pos)  /*!< 0x00000200 */
#define RCC_AHB2SMENR_CCMSRAMSMEN            RCC_AHB2SMENR_CCMSRAMSMEN_Msk
#define RCC_AHB2SMENR_SRAM2SMEN_Pos          (10U)
#define RCC_AHB2SMENR_SRAM2SMEN_Msk          (0x1UL << RCC_AHB2SMENR_SRAM2SMEN_Pos)/*!< 0x00000400 */
#define RCC_AHB2SMENR_SRAM2SMEN              RCC_AHB2SMENR_SRAM2SMEN_Msk
#define RCC_AHB2SMENR_ADC12SMEN_Pos          (13U)
#define RCC_AHB2SMENR_ADC12SMEN_Msk          (0x1UL << RCC_AHB2SMENR_ADC12SMEN_Pos)/*!< 0x00002000 */
#define RCC_AHB2SMENR_ADC12SMEN              RCC_AHB2SMENR_ADC12SMEN_Msk
#define RCC_AHB2SMENR_ADC345SMEN_Pos         (14U)
#define RCC_AHB2SMENR_ADC345SMEN_Msk         (0x1UL << RCC_AHB2SMENR_ADC345SMEN_Pos)/*!< 0x00004000 */
#define RCC_AHB2SMENR_ADC345SMEN             RCC_AHB2SMENR_ADC345SMEN_Msk
#define RCC_AHB2SMENR_DAC1SMEN_Pos           (16U)
#define RCC_AHB2SMENR_DAC1SMEN_Msk           (0x1UL << RCC_AHB2SMENR_DAC1SMEN_Pos)/*!< 0x00010000 */
#define RCC_AHB2SMENR_DAC1SMEN               RCC_AHB2SMENR_DAC1SMEN_Msk
#define RCC_AHB2SMENR_DAC2SMEN_Pos           (17U)
#define RCC_AHB2SMENR_DAC2SMEN_Msk           (0x1UL << RCC_AHB2SMENR_DAC2SMEN_Pos)/*!< 0x00020000 */
#define RCC_AHB2SMENR_DAC2SMEN               RCC_AHB2SMENR_DAC2SMEN_Msk
#define RCC_AHB2SMENR_DAC3SMEN_Pos           (18U)
#define RCC_AHB2SMENR_DAC3SMEN_Msk           (0x1UL << RCC_AHB2SMENR_DAC3SMEN_Pos)/*!< 0x00040000 */
#define RCC_AHB2SMENR_DAC3SMEN               RCC_AHB2SMENR_DAC3SMEN_Msk
#define RCC_AHB2SMENR_DAC4SMEN_Pos           (19U)
#define RCC_AHB2SMENR_DAC4SMEN_Msk           (0x1UL << RCC_AHB2SMENR_DAC4SMEN_Pos)/*!< 0x00080000 */
#define RCC_AHB2SMENR_DAC4SMEN               RCC_AHB2SMENR_DAC4SMEN_Msk
#define RCC_AHB2SMENR_RNGSMEN_Pos            (26U)
#define RCC_AHB2SMENR_RNGSMEN_Msk            (0x1UL << RCC_AHB2SMENR_RNGSMEN_Pos)/*!< 0x04000000 */
#define RCC_AHB2SMENR_RNGSMEN                RCC_AHB2SMENR_RNGSMEN_Msk

/********************  Bit definition for RCC_AHB3SMENR register  *************/
#define RCC_AHB3SMENR_FMCSMEN_Pos            (0U)
#define RCC_AHB3SMENR_FMCSMEN_Msk            (0x1UL << RCC_AHB3SMENR_FMCSMEN_Pos)/*!< 0x00000001 */
#define RCC_AHB3SMENR_FMCSMEN                RCC_AHB3SMENR_FMCSMEN_Msk
#define RCC_AHB3SMENR_QSPISMEN_Pos           (8U)
#define RCC_AHB3SMENR_QSPISMEN_Msk           (0x1UL << RCC_AHB3SMENR_QSPISMEN_Pos)/*!< 0x00000100 */
#define RCC_AHB3SMENR_QSPISMEN               RCC_AHB3SMENR_QSPISMEN_Msk

/********************  Bit definition for RCC_APB1SMENR1 register  *************/
#define RCC_APB1SMENR1_TIM2SMEN_Pos          (0U)
#define RCC_APB1SMENR1_TIM2SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM2SMEN_Pos)/*!< 0x00000001 */
#define RCC_APB1SMENR1_TIM2SMEN              RCC_APB1SMENR1_TIM2SMEN_Msk
#define RCC_APB1SMENR1_TIM3SMEN_Pos          (1U)
#define RCC_APB1SMENR1_TIM3SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM3SMEN_Pos)/*!< 0x00000002 */
#define RCC_APB1SMENR1_TIM3SMEN              RCC_APB1SMENR1_TIM3SMEN_Msk
#define RCC_APB1SMENR1_TIM4SMEN_Pos          (2U)
#define RCC_APB1SMENR1_TIM4SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM4SMEN_Pos)/*!< 0x00000004 */
#define RCC_APB1SMENR1_TIM4SMEN              RCC_APB1SMENR1_TIM4SMEN_Msk
#define RCC_APB1SMENR1_TIM5SMEN_Pos          (3U)
#define RCC_APB1SMENR1_TIM5SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM5SMEN_Pos)/*!< 0x00000008 */
#define RCC_APB1SMENR1_TIM5SMEN              RCC_APB1SMENR1_TIM5SMEN_Msk
#define RCC_APB1SMENR1_TIM6SMEN_Pos          (4U)
#define RCC_APB1SMENR1_TIM6SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM6SMEN_Pos)/*!< 0x00000010 */
#define RCC_APB1SMENR1_TIM6SMEN              RCC_APB1SMENR1_TIM6SMEN_Msk
#define RCC_APB1SMENR1_TIM7SMEN_Pos          (5U)
#define RCC_APB1SMENR1_TIM7SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM7SMEN_Pos)/*!< 0x00000020 */
#define RCC_APB1SMENR1_TIM7SMEN              RCC_APB1SMENR1_TIM7SMEN_Msk
#define RCC_APB1SMENR1_CRSSMEN_Pos           (8U)
#define RCC_APB1SMENR1_CRSSMEN_Msk           (0x1UL << RCC_APB1SMENR1_CRSSMEN_Pos)/*!< 0x00000100 */
#define RCC_APB1SMENR1_CRSSMEN               RCC_APB1SMENR1_CRSSMEN_Msk
#define RCC_APB1SMENR1_RTCAPBSMEN_Pos        (10U)
#define RCC_APB1SMENR1_RTCAPBSMEN_Msk        (0x1UL << RCC_APB1SMENR1_RTCAPBSMEN_Pos)/*!< 0x00000400 */
#define RCC_APB1SMENR1_RTCAPBSMEN            RCC_APB1SMENR1_RTCAPBSMEN_Msk
#define RCC_APB1SMENR1_WWDGSMEN_Pos          (11U)
#define RCC_APB1SMENR1_WWDGSMEN_Msk          (0x1UL << RCC_APB1SMENR1_WWDGSMEN_Pos)/*!< 0x00000800 */
#define RCC_APB1SMENR1_WWDGSMEN              RCC_APB1SMENR1_WWDGSMEN_Msk
#define RCC_APB1SMENR1_SPI2SMEN_Pos          (14U)
#define RCC_APB1SMENR1_SPI2SMEN_Msk          (0x1UL << RCC_APB1SMENR1_SPI2SMEN_Pos)/*!< 0x00004000 */
#define RCC_APB1SMENR1_SPI2SMEN              RCC_APB1SMENR1_SPI2SMEN_Msk
#define RCC_APB1SMENR1_SPI3SMEN_Pos          (15U)
#define RCC_APB1SMENR1_SPI3SMEN_Msk          (0x1UL << RCC_APB1SMENR1_SPI3SMEN_Pos)/*!< 0x00008000 */
#define RCC_APB1SMENR1_SPI3SMEN              RCC_APB1SMENR1_SPI3SMEN_Msk
#define RCC_APB1SMENR1_USART2SMEN_Pos        (17U)
#define RCC_APB1SMENR1_USART2SMEN_Msk        (0x1UL << RCC_APB1SMENR1_USART2SMEN_Pos)/*!< 0x00020000 */
#define RCC_APB1SMENR1_USART2SMEN            RCC_APB1SMENR1_USART2SMEN_Msk
#define RCC_APB1SMENR1_USART3SMEN_Pos        (18U)
#define RCC_APB1SMENR1_USART3SMEN_Msk        (0x1UL << RCC_APB1SMENR1_USART3SMEN_Pos)/*!< 0x00040000 */
#define RCC_APB1SMENR1_USART3SMEN            RCC_APB1SMENR1_USART3SMEN_Msk
#define RCC_APB1SMENR1_UART4SMEN_Pos         (19U)
#define RCC_APB1SMENR1_UART4SMEN_Msk         (0x1UL << RCC_APB1SMENR1_UART4SMEN_Pos)/*!< 0x00080000 */
#define RCC_APB1SMENR1_UART4SMEN             RCC_APB1SMENR1_UART4SMEN_Msk
#define RCC_APB1SMENR1_UART5SMEN_Pos         (20U)
#define RCC_APB1SMENR1_UART5SMEN_Msk         (0x1UL << RCC_APB1SMENR1_UART5SMEN_Pos)/*!< 0x00100000 */
#define RCC_APB1SMENR1_UART5SMEN             RCC_APB1SMENR1_UART5SMEN_Msk
#define RCC_APB1SMENR1_I2C1SMEN_Pos          (21U)
#define RCC_APB1SMENR1_I2C1SMEN_Msk          (0x1UL << RCC_APB1SMENR1_I2C1SMEN_Pos)/*!< 0x00200000 */
#define RCC_APB1SMENR1_I2C1SMEN              RCC_APB1SMENR1_I2C1SMEN_Msk
#define RCC_APB1SMENR1_I2C2SMEN_Pos          (22U)
#define RCC_APB1SMENR1_I2C2SMEN_Msk          (0x1UL << RCC_APB1SMENR1_I2C2SMEN_Pos)/*!< 0x00400000 */
#define RCC_APB1SMENR1_I2C2SMEN              RCC_APB1SMENR1_I2C2SMEN_Msk
#define RCC_APB1SMENR1_USBSMEN_Pos           (23U)
#define RCC_APB1SMENR1_USBSMEN_Msk           (0x1UL << RCC_APB1SMENR1_USBSMEN_Pos)/*!< 0x00800000 */
#define RCC_APB1SMENR1_USBSMEN               RCC_APB1SMENR1_USBSMEN_Msk
#define RCC_APB1SMENR1_FDCANSMEN_Pos         (25U)
#define RCC_APB1SMENR1_FDCANSMEN_Msk         (0x1UL << RCC_APB1SMENR1_FDCANSMEN_Pos)/*!< 0x02000000 */
#define RCC_APB1SMENR1_FDCANSMEN             RCC_APB1SMENR1_FDCANSMEN_Msk
#define RCC_APB1SMENR1_PWRSMEN_Pos           (28U)
#define RCC_APB1SMENR1_PWRSMEN_Msk           (0x1UL << RCC_APB1SMENR1_PWRSMEN_Pos)/*!< 0x10000000 */
#define RCC_APB1SMENR1_PWRSMEN               RCC_APB1SMENR1_PWRSMEN_Msk
#define RCC_APB1SMENR1_I2C3SMEN_Pos          (30U)
#define RCC_APB1SMENR1_I2C3SMEN_Msk          (0x1UL << RCC_APB1SMENR1_I2C3SMEN_Pos)/*!< 0x40000000 */
#define RCC_APB1SMENR1_I2C3SMEN              RCC_APB1SMENR1_I2C3SMEN_Msk
#define RCC_APB1SMENR1_LPTIM1SMEN_Pos        (31U)
#define RCC_APB1SMENR1_LPTIM1SMEN_Msk        (0x1UL << RCC_APB1SMENR1_LPTIM1SMEN_Pos)/*!< 0x80000000 */
#define RCC_APB1SMENR1_LPTIM1SMEN            RCC_APB1SMENR1_LPTIM1SMEN_Msk

/********************  Bit definition for RCC_APB1SMENR2 register  *************/
#define RCC_APB1SMENR2_LPUART1SMEN_Pos       (0U)
#define RCC_APB1SMENR2_LPUART1SMEN_Msk       (0x1UL << RCC_APB1SMENR2_LPUART1SMEN_Pos)/*!< 0x00000001 */
#define RCC_APB1SMENR2_LPUART1SMEN           RCC_APB1SMENR2_LPUART1SMEN_Msk
#define RCC_APB1SMENR2_I2C4SMEN_Pos          (1U)
#define RCC_APB1SMENR2_I2C4SMEN_Msk          (0x1UL << RCC_APB1SMENR2_I2C4SMEN_Pos)/*!< 0x00000002 */
#define RCC_APB1SMENR2_I2C4SMEN              RCC_APB1SMENR2_I2C4SMEN_Msk
#define RCC_APB1SMENR2_UCPD1SMEN_Pos         (8U)
#define RCC_APB1SMENR2_UCPD1SMEN_Msk         (0x1UL << RCC_APB1SMENR2_UCPD1SMEN_Pos)/*!< 0x00000100 */
#define RCC_APB1SMENR2_UCPD1SMEN             RCC_APB1SMENR2_UCPD1SMEN_Msk

/********************  Bit definition for RCC_APB2SMENR register  *************/
#define RCC_APB2SMENR_SYSCFGSMEN_Pos         (0U)
#define RCC_APB2SMENR_SYSCFGSMEN_Msk         (0x1UL << RCC_APB2SMENR_SYSCFGSMEN_Pos)/*!< 0x00000001 */
#define RCC_APB2SMENR_SYSCFGSMEN             RCC_APB2SMENR_SYSCFGSMEN_Msk
#define RCC_APB2SMENR_TIM1SMEN_Pos           (11U)
#define RCC_APB2SMENR_TIM1SMEN_Msk           (0x1UL << RCC_APB2SMENR_TIM1SMEN_Pos)/*!< 0x00000800 */
#define RCC_APB2SMENR_TIM1SMEN               RCC_APB2SMENR_TIM1SMEN_Msk
#define RCC_APB2SMENR_SPI1SMEN_Pos           (12U)
#define RCC_APB2SMENR_SPI1SMEN_Msk           (0x1UL << RCC_APB2SMENR_SPI1SMEN_Pos)/*!< 0x00001000 */
#define RCC_APB2SMENR_SPI1SMEN               RCC_APB2SMENR_SPI1SMEN_Msk
#define RCC_APB2SMENR_TIM8SMEN_Pos           (13U)
#define RCC_APB2SMENR_TIM8SMEN_Msk           (0x1UL << RCC_APB2SMENR_TIM8SMEN_Pos)/*!< 0x00002000 */
#define RCC_APB2SMENR_TIM8SMEN               RCC_APB2SMENR_TIM8SMEN_Msk
#define RCC_APB2SMENR_USART1SMEN_Pos         (14U)
#define RCC_APB2SMENR_USART1SMEN_Msk         (0x1UL << RCC_APB2SMENR_USART1SMEN_Pos)/*!< 0x00004000 */
#define RCC_APB2SMENR_USART1SMEN             RCC_APB2SMENR_USART1SMEN_Msk
#define RCC_APB2SMENR_SPI4SMEN_Pos           (15U)
#define RCC_APB2SMENR_SPI4SMEN_Msk           (0x1UL << RCC_APB2SMENR_SPI4SMEN_Pos)/*!< 0x00008000 */
#define RCC_APB2SMENR_SPI4SMEN               RCC_APB2SMENR_SPI4SMEN_Msk
#define RCC_APB2SMENR_TIM15SMEN_Pos          (16U)
#define RCC_APB2SMENR_TIM15SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM15SMEN_Pos)/*!< 0x00010000 */
#define RCC_APB2SMENR_TIM15SMEN              RCC_APB2SMENR_TIM15SMEN_Msk
#define RCC_APB2SMENR_TIM16SMEN_Pos          (17U)
#define RCC_APB2SMENR_TIM16SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM16SMEN_Pos)/*!< 0x00020000 */
#define RCC_APB2SMENR_TIM16SMEN              RCC_APB2SMENR_TIM16SMEN_Msk
#define RCC_APB2SMENR_TIM17SMEN_Pos          (18U)
#define RCC_APB2SMENR_TIM17SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM17SMEN_Pos)/*!< 0x00040000 */
#define RCC_APB2SMENR_TIM17SMEN              RCC_APB2SMENR_TIM17SMEN_Msk
#define RCC_APB2SMENR_TIM20SMEN_Pos          (20U)
#define RCC_APB2SMENR_TIM20SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM20SMEN_Pos)/*!< 0x00100000 */
#define RCC_APB2SMENR_TIM20SMEN              RCC_APB2SMENR_TIM20SMEN_Msk
#define RCC_APB2SMENR_SAI1SMEN_Pos           (21U)
#define RCC_APB2SMENR_SAI1SMEN_Msk           (0x1UL << RCC_APB2SMENR_SAI1SMEN_Pos)/*!< 0x00200000 */
#define RCC_APB2SMENR_SAI1SMEN               RCC_APB2SMENR_SAI1SMEN_Msk
#define RCC_APB2SMENR_HRTIM1SMEN_Pos          (26U)
#define RCC_APB2SMENR_HRTIM1SMEN_Msk          (0x1UL << RCC_APB2SMENR_HRTIM1SMEN_Pos)/*!< 0x04000000 */
#define RCC_APB2SMENR_HRTIM1SMEN              RCC_APB2SMENR_HRTIM1SMEN_Msk

/********************  Bit definition for RCC_CCIPR register  ******************/
#define RCC_CCIPR_USART1SEL_Pos              (0U)
#define RCC_CCIPR_USART1SEL_Msk              (0x3UL << RCC_CCIPR_USART1SEL_Pos)/*!< 0x00000003 */
#define RCC_CCIPR_USART1SEL                  RCC_CCIPR_USART1SEL_Msk
#define RCC_CCIPR_USART1SEL_0                (0x1UL << RCC_CCIPR_USART1SEL_Pos)/*!< 0x00000001 */
#define RCC_CCIPR_USART1SEL_1                (0x2UL << RCC_CCIPR_USART1SEL_Pos)/*!< 0x00000002 */

#define RCC_CCIPR_USART2SEL_Pos              (2U)
#define RCC_CCIPR_USART2SEL_Msk              (0x3UL << RCC_CCIPR_USART2SEL_Pos)/*!< 0x0000000C */
#define RCC_CCIPR_USART2SEL                  RCC_CCIPR_USART2SEL_Msk
#define RCC_CCIPR_USART2SEL_0                (0x1UL << RCC_CCIPR_USART2SEL_Pos)/*!< 0x00000004 */
#define RCC_CCIPR_USART2SEL_1                (0x2UL << RCC_CCIPR_USART2SEL_Pos)/*!< 0x00000008 */

#define RCC_CCIPR_USART3SEL_Pos              (4U)
#define RCC_CCIPR_USART3SEL_Msk              (0x3UL << RCC_CCIPR_USART3SEL_Pos)/*!< 0x00000030 */
#define RCC_CCIPR_USART3SEL                  RCC_CCIPR_USART3SEL_Msk
#define RCC_CCIPR_USART3SEL_0                (0x1UL << RCC_CCIPR_USART3SEL_Pos)/*!< 0x00000010 */
#define RCC_CCIPR_USART3SEL_1                (0x2UL << RCC_CCIPR_USART3SEL_Pos)/*!< 0x00000020 */

#define RCC_CCIPR_UART4SEL_Pos               (6U)
#define RCC_CCIPR_UART4SEL_Msk               (0x3UL << RCC_CCIPR_UART4SEL_Pos) /*!< 0x000000C0 */
#define RCC_CCIPR_UART4SEL                   RCC_CCIPR_UART4SEL_Msk
#define RCC_CCIPR_UART4SEL_0                 (0x1UL << RCC_CCIPR_UART4SEL_Pos) /*!< 0x00000040 */
#define RCC_CCIPR_UART4SEL_1                 (0x2UL << RCC_CCIPR_UART4SEL_Pos) /*!< 0x00000080 */

#define RCC_CCIPR_UART5SEL_Pos               (8U)
#define RCC_CCIPR_UART5SEL_Msk               (0x3UL << RCC_CCIPR_UART5SEL_Pos) /*!< 0x00000300 */
#define RCC_CCIPR_UART5SEL                   RCC_CCIPR_UART5SEL_Msk
#define RCC_CCIPR_UART5SEL_0                 (0x1UL << RCC_CCIPR_UART5SEL_Pos) /*!< 0x00000100 */
#define RCC_CCIPR_UART5SEL_1                 (0x2UL << RCC_CCIPR_UART5SEL_Pos) /*!< 0x00000200 */

#define RCC_CCIPR_LPUART1SEL_Pos             (10U)
#define RCC_CCIPR_LPUART1SEL_Msk             (0x3UL << RCC_CCIPR_LPUART1SEL_Pos)/*!< 0x00000C00 */
#define RCC_CCIPR_LPUART1SEL                 RCC_CCIPR_LPUART1SEL_Msk
#define RCC_CCIPR_LPUART1SEL_0               (0x1UL << RCC_CCIPR_LPUART1SEL_Pos)/*!< 0x00000400 */
#define RCC_CCIPR_LPUART1SEL_1               (0x2UL << RCC_CCIPR_LPUART1SEL_Pos)/*!< 0x00000800 */

#define RCC_CCIPR_I2C1SEL_Pos                (12U)
#define RCC_CCIPR_I2C1SEL_Msk                (0x3UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00003000 */
#define RCC_CCIPR_I2C1SEL                    RCC_CCIPR_I2C1SEL_Msk
#define RCC_CCIPR_I2C1SEL_0                  (0x1UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00001000 */
#define RCC_CCIPR_I2C1SEL_1                  (0x2UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00002000 */

#define RCC_CCIPR_I2C2SEL_Pos                (14U)
#define RCC_CCIPR_I2C2SEL_Msk                (0x3UL << RCC_CCIPR_I2C2SEL_Pos)  /*!< 0x0000C000 */
#define RCC_CCIPR_I2C2SEL                    RCC_CCIPR_I2C2SEL_Msk
#define RCC_CCIPR_I2C2SEL_0                  (0x1UL << RCC_CCIPR_I2C2SEL_Pos)  /*!< 0x00004000 */
#define RCC_CCIPR_I2C2SEL_1                  (0x2UL << RCC_CCIPR_I2C2SEL_Pos)  /*!< 0x00008000 */

#define RCC_CCIPR_I2C3SEL_Pos                (16U)
#define RCC_CCIPR_I2C3SEL_Msk                (0x3UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00030000 */
#define RCC_CCIPR_I2C3SEL                    RCC_CCIPR_I2C3SEL_Msk
#define RCC_CCIPR_I2C3SEL_0                  (0x1UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00010000 */
#define RCC_CCIPR_I2C3SEL_1                  (0x2UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00020000 */

#define RCC_CCIPR_LPTIM1SEL_Pos              (18U)
#define RCC_CCIPR_LPTIM1SEL_Msk              (0x3UL << RCC_CCIPR_LPTIM1SEL_Pos)/*!< 0x000C0000 */
#define RCC_CCIPR_LPTIM1SEL                  RCC_CCIPR_LPTIM1SEL_Msk
#define RCC_CCIPR_LPTIM1SEL_0                (0x1UL << RCC_CCIPR_LPTIM1SEL_Pos)/*!< 0x00040000 */
#define RCC_CCIPR_LPTIM1SEL_1                (0x2UL << RCC_CCIPR_LPTIM1SEL_Pos)/*!< 0x00080000 */

#define RCC_CCIPR_SAI1SEL_Pos                (20U)
#define RCC_CCIPR_SAI1SEL_Msk                (0x3UL << RCC_CCIPR_SAI1SEL_Pos)/*!< 0x00300000 */
#define RCC_CCIPR_SAI1SEL                    RCC_CCIPR_SAI1SEL_Msk
#define RCC_CCIPR_SAI1SEL_0                  (0x1UL << RCC_CCIPR_SAI1SEL_Pos)/*!< 0x00100000 */
#define RCC_CCIPR_SAI1SEL_1                  (0x2UL << RCC_CCIPR_SAI1SEL_Pos)/*!< 0x00200000 */

#define RCC_CCIPR_I2S23SEL_Pos               (22U)
#define RCC_CCIPR_I2S23SEL_Msk               (0x3UL << RCC_CCIPR_I2S23SEL_Pos)/*!< 0x00C00000 */
#define RCC_CCIPR_I2S23SEL                   RCC_CCIPR_I2S23SEL_Msk
#define RCC_CCIPR_I2S23SEL_0                 (0x1UL << RCC_CCIPR_I2S23SEL_Pos)/*!< 0x00400000 */
#define RCC_CCIPR_I2S23SEL_1                 (0x2UL << RCC_CCIPR_I2S23SEL_Pos)/*!< 0x00800000 */

#define RCC_CCIPR_FDCANSEL_Pos               (24U)
#define RCC_CCIPR_FDCANSEL_Msk               (0x3UL << RCC_CCIPR_FDCANSEL_Pos) /*!< 0x03000000 */
#define RCC_CCIPR_FDCANSEL                   RCC_CCIPR_FDCANSEL_Msk
#define RCC_CCIPR_FDCANSEL_0                 (0x1UL << RCC_CCIPR_FDCANSEL_Pos) /*!< 0x01000000 */
#define RCC_CCIPR_FDCANSEL_1                 (0x2UL << RCC_CCIPR_FDCANSEL_Pos) /*!< 0x02000000 */

#define RCC_CCIPR_CLK48SEL_Pos               (26U)
#define RCC_CCIPR_CLK48SEL_Msk               (0x3UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x0C000000 */
#define RCC_CCIPR_CLK48SEL                   RCC_CCIPR_CLK48SEL_Msk
#define RCC_CCIPR_CLK48SEL_0                 (0x1UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x04000000 */
#define RCC_CCIPR_CLK48SEL_1                 (0x2UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x08000000 */

#define RCC_CCIPR_ADC12SEL_Pos               (28U)
#define RCC_CCIPR_ADC12SEL_Msk               (0x3UL << RCC_CCIPR_ADC12SEL_Pos)   /*!< 0x30000000 */
#define RCC_CCIPR_ADC12SEL                   RCC_CCIPR_ADC12SEL_Msk
#define RCC_CCIPR_ADC12SEL_0                 (0x1UL << RCC_CCIPR_ADC12SEL_Pos)   /*!< 0x10000000 */
#define RCC_CCIPR_ADC12SEL_1                 (0x2UL << RCC_CCIPR_ADC12SEL_Pos)   /*!< 0x20000000 */

#define RCC_CCIPR_ADC345SEL_Pos              (30U)
#define RCC_CCIPR_ADC345SEL_Msk              (0x3UL << RCC_CCIPR_ADC345SEL_Pos)   /*!< 0x80000000 */
#define RCC_CCIPR_ADC345SEL                  RCC_CCIPR_ADC345SEL_Msk
#define RCC_CCIPR_ADC345SEL_0                (0x1UL << RCC_CCIPR_ADC345SEL_Pos)   /*!< 0x40000000 */
#define RCC_CCIPR_ADC345SEL_1                (0x2UL << RCC_CCIPR_ADC345SEL_Pos)   /*!< 0x80000000 */

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                   (0U)
#define RCC_BDCR_LSEON_Msk                   (0x1UL << RCC_BDCR_LSEON_Pos)     /*!< 0x00000001 */
#define RCC_BDCR_LSEON                       RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos                  (1U)
#define RCC_BDCR_LSERDY_Msk                  (0x1UL << RCC_BDCR_LSERDY_Pos)    /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                      RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos                  (2U)
#define RCC_BDCR_LSEBYP_Msk                  (0x1UL << RCC_BDCR_LSEBYP_Pos)    /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                      RCC_BDCR_LSEBYP_Msk

#define RCC_BDCR_LSEDRV_Pos                  (3U)
#define RCC_BDCR_LSEDRV_Msk                  (0x3UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000018 */
#define RCC_BDCR_LSEDRV                      RCC_BDCR_LSEDRV_Msk
#define RCC_BDCR_LSEDRV_0                    (0x1UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000008 */
#define RCC_BDCR_LSEDRV_1                    (0x2UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000010 */

#define RCC_BDCR_LSECSSON_Pos                (5U)
#define RCC_BDCR_LSECSSON_Msk                (0x1UL << RCC_BDCR_LSECSSON_Pos)  /*!< 0x00000020 */
#define RCC_BDCR_LSECSSON                    RCC_BDCR_LSECSSON_Msk
#define RCC_BDCR_LSECSSD_Pos                 (6U)
#define RCC_BDCR_LSECSSD_Msk                 (0x1UL << RCC_BDCR_LSECSSD_Pos)   /*!< 0x00000040 */
#define RCC_BDCR_LSECSSD                     RCC_BDCR_LSECSSD_Msk

#define RCC_BDCR_RTCSEL_Pos                  (8U)
#define RCC_BDCR_RTCSEL_Msk                  (0x3UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                      RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0                    (0x1UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                    (0x2UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000200 */

#define RCC_BDCR_RTCEN_Pos                   (15U)
#define RCC_BDCR_RTCEN_Msk                   (0x1UL << RCC_BDCR_RTCEN_Pos)     /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                       RCC_BDCR_RTCEN_Msk
#define RCC_BDCR_BDRST_Pos                   (16U)
#define RCC_BDCR_BDRST_Msk                   (0x1UL << RCC_BDCR_BDRST_Pos)     /*!< 0x00010000 */
#define RCC_BDCR_BDRST                       RCC_BDCR_BDRST_Msk
#define RCC_BDCR_LSCOEN_Pos                  (24U)
#define RCC_BDCR_LSCOEN_Msk                  (0x1UL << RCC_BDCR_LSCOEN_Pos)    /*!< 0x01000000 */
#define RCC_BDCR_LSCOEN                      RCC_BDCR_LSCOEN_Msk
#define RCC_BDCR_LSCOSEL_Pos                 (25U)
#define RCC_BDCR_LSCOSEL_Msk                 (0x1UL << RCC_BDCR_LSCOSEL_Pos)   /*!< 0x02000000 */
#define RCC_BDCR_LSCOSEL                     RCC_BDCR_LSCOSEL_Msk

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                    (0U)
#define RCC_CSR_LSION_Msk                    (0x1UL << RCC_CSR_LSION_Pos)      /*!< 0x00000001 */
#define RCC_CSR_LSION                        RCC_CSR_LSION_Msk
#define RCC_CSR_LSIRDY_Pos                   (1U)
#define RCC_CSR_LSIRDY_Msk                   (0x1UL << RCC_CSR_LSIRDY_Pos)     /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                       RCC_CSR_LSIRDY_Msk

#define RCC_CSR_RMVF_Pos                     (23U)
#define RCC_CSR_RMVF_Msk                     (0x1UL << RCC_CSR_RMVF_Pos)       /*!< 0x00800000 */
#define RCC_CSR_RMVF                         RCC_CSR_RMVF_Msk
#define RCC_CSR_OBLRSTF_Pos                  (25U)
#define RCC_CSR_OBLRSTF_Msk                  (0x1UL << RCC_CSR_OBLRSTF_Pos)    /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                      RCC_CSR_OBLRSTF_Msk
#define RCC_CSR_PINRSTF_Pos                  (26U)
#define RCC_CSR_PINRSTF_Msk                  (0x1UL << RCC_CSR_PINRSTF_Pos)    /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                      RCC_CSR_PINRSTF_Msk
#define RCC_CSR_BORRSTF_Pos                  (27U)
#define RCC_CSR_BORRSTF_Msk                  (0x1UL << RCC_CSR_BORRSTF_Pos)    /*!< 0x08000000 */
#define RCC_CSR_BORRSTF                      RCC_CSR_BORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos                  (28U)
#define RCC_CSR_SFTRSTF_Msk                  (0x1UL << RCC_CSR_SFTRSTF_Pos)    /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                      RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos                 (29U)
#define RCC_CSR_IWDGRSTF_Msk                 (0x1UL << RCC_CSR_IWDGRSTF_Pos)   /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                     RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos                 (30U)
#define RCC_CSR_WWDGRSTF_Msk                 (0x1UL << RCC_CSR_WWDGRSTF_Pos)   /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                     RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos                 (31U)
#define RCC_CSR_LPWRRSTF_Msk                 (0x1UL << RCC_CSR_LPWRRSTF_Pos)   /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                     RCC_CSR_LPWRRSTF_Msk

/********************  Bit definition for RCC_CRRCR register  *****************/
#define RCC_CRRCR_HSI48ON_Pos                (0U)
#define RCC_CRRCR_HSI48ON_Msk                (0x1UL << RCC_CRRCR_HSI48ON_Pos)  /*!< 0x00000001 */
#define RCC_CRRCR_HSI48ON                    RCC_CRRCR_HSI48ON_Msk
#define RCC_CRRCR_HSI48RDY_Pos               (1U)
#define RCC_CRRCR_HSI48RDY_Msk               (0x1UL << RCC_CRRCR_HSI48RDY_Pos) /*!< 0x00000002 */
#define RCC_CRRCR_HSI48RDY                   RCC_CRRCR_HSI48RDY_Msk

/*!< HSI48CAL configuration */
#define RCC_CRRCR_HSI48CAL_Pos               (7U)
#define RCC_CRRCR_HSI48CAL_Msk               (0x1FFUL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x0000FF80 */
#define RCC_CRRCR_HSI48CAL                   RCC_CRRCR_HSI48CAL_Msk             /*!< HSI48CAL[8:0] bits */
#define RCC_CRRCR_HSI48CAL_0                 (0x001UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00000080 */
#define RCC_CRRCR_HSI48CAL_1                 (0x002UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00000100 */
#define RCC_CRRCR_HSI48CAL_2                 (0x004UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00000200 */
#define RCC_CRRCR_HSI48CAL_3                 (0x008UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00000400 */
#define RCC_CRRCR_HSI48CAL_4                 (0x010UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00000800 */
#define RCC_CRRCR_HSI48CAL_5                 (0x020UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00001000 */
#define RCC_CRRCR_HSI48CAL_6                 (0x040UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00002000 */
#define RCC_CRRCR_HSI48CAL_7                 (0x080UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00004000 */
#define RCC_CRRCR_HSI48CAL_8                 (0x100UL << RCC_CRRCR_HSI48CAL_Pos)/*!< 0x00008000 */

/********************  Bit definition for RCC_CCIPR2 register  ******************/
#define RCC_CCIPR2_I2C4SEL_Pos               (0U)
#define RCC_CCIPR2_I2C4SEL_Msk               (0x3UL << RCC_CCIPR2_I2C4SEL_Pos) /*!< 0x00000003 */
#define RCC_CCIPR2_I2C4SEL                   RCC_CCIPR2_I2C4SEL_Msk
#define RCC_CCIPR2_I2C4SEL_0                 (0x1UL << RCC_CCIPR2_I2C4SEL_Pos) /*!< 0x00000001 */
#define RCC_CCIPR2_I2C4SEL_1                 (0x2UL << RCC_CCIPR2_I2C4SEL_Pos) /*!< 0x00000002 */

#define RCC_CCIPR2_QSPISEL_Pos               (20U)
#define RCC_CCIPR2_QSPISEL_Msk               (0x3UL << RCC_CCIPR2_QSPISEL_Pos) /*!< 0x00030000 */
#define RCC_CCIPR2_QSPISEL                   RCC_CCIPR2_QSPISEL_Msk
#define RCC_CCIPR2_QSPISEL_0                 (0x1UL << RCC_CCIPR2_QSPISEL_Pos) /*!< 0x00010000 */
#define RCC_CCIPR2_QSPISEL_1                 (0x2UL << RCC_CCIPR2_QSPISEL_Pos) /*!< 0x00020000 */


/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for PWR_CR1 register  ********************/

#define PWR_CR1_LPR_Pos              (14U)
#define PWR_CR1_LPR_Msk              (0x1UL << PWR_CR1_LPR_Pos)                /*!< 0x00004000 */
#define PWR_CR1_LPR                  PWR_CR1_LPR_Msk                           /*!< Regulator low-power mode */
#define PWR_CR1_VOS_Pos              (9U)
#define PWR_CR1_VOS_Msk              (0x3UL << PWR_CR1_VOS_Pos)                /*!< 0x00000600 */
#define PWR_CR1_VOS                  PWR_CR1_VOS_Msk                           /*!< VOS[1:0] bits (Regulator voltage scaling output selection) */
#define PWR_CR1_VOS_0                (0x1UL << PWR_CR1_VOS_Pos)                /*!< 0x00000200 */
#define PWR_CR1_VOS_1                (0x2UL << PWR_CR1_VOS_Pos)                /*!< 0x00000400 */
#define PWR_CR1_DBP_Pos              (8U)
#define PWR_CR1_DBP_Msk              (0x1UL << PWR_CR1_DBP_Pos)                /*!< 0x00000100 */
#define PWR_CR1_DBP                  PWR_CR1_DBP_Msk                           /*!< Disable Back-up domain Protection */
#define PWR_CR1_LPMS_Pos             (0U)
#define PWR_CR1_LPMS_Msk             (0x7UL << PWR_CR1_LPMS_Pos)               /*!< 0x00000007 */
#define PWR_CR1_LPMS                 PWR_CR1_LPMS_Msk                          /*!< Low-power mode selection field */
#define PWR_CR1_LPMS_STOP0           (0x00000000U)                             /*!< Stop 0 mode */
#define PWR_CR1_LPMS_STOP1_Pos       (0U)
#define PWR_CR1_LPMS_STOP1_Msk       (0x1UL << PWR_CR1_LPMS_STOP1_Pos)         /*!< 0x00000001 */
#define PWR_CR1_LPMS_STOP1           PWR_CR1_LPMS_STOP1_Msk                    /*!< Stop 1 mode */
#define PWR_CR1_LPMS_STANDBY_Pos     (0U)
#define PWR_CR1_LPMS_STANDBY_Msk     (0x3UL << PWR_CR1_LPMS_STANDBY_Pos)       /*!< 0x00000003 */
#define PWR_CR1_LPMS_STANDBY         PWR_CR1_LPMS_STANDBY_Msk                  /*!< Stand-by mode */
#define PWR_CR1_LPMS_SHUTDOWN_Pos    (2U)
#define PWR_CR1_LPMS_SHUTDOWN_Msk    (0x1UL << PWR_CR1_LPMS_SHUTDOWN_Pos)      /*!< 0x00000004 */
#define PWR_CR1_LPMS_SHUTDOWN        PWR_CR1_LPMS_SHUTDOWN_Msk                 /*!< Shut-down mode */


/********************  Bit definition for PWR_CR2 register  ********************/

/*!< PVME  Peripheral Voltage Monitor Enable */
#define PWR_CR2_PVME_Pos             (4U)
#define PWR_CR2_PVME_Msk             (0xFUL << PWR_CR2_PVME_Pos)               /*!< 0x000000F0 */
#define PWR_CR2_PVME                 PWR_CR2_PVME_Msk                          /*!< PVM bits field */
#define PWR_CR2_PVME4_Pos            (7U)
#define PWR_CR2_PVME4_Msk            (0x1UL << PWR_CR2_PVME4_Pos)              /*!< 0x00000080 */
#define PWR_CR2_PVME4                PWR_CR2_PVME4_Msk                         /*!< PVM 4 Enable */
#define PWR_CR2_PVME3_Pos            (6U)
#define PWR_CR2_PVME3_Msk            (0x1UL << PWR_CR2_PVME3_Pos)              /*!< 0x00000040 */
#define PWR_CR2_PVME3                PWR_CR2_PVME3_Msk                         /*!< PVM 3 Enable */
#define PWR_CR2_PVME2_Pos            (5U)
#define PWR_CR2_PVME2_Msk            (0x1UL << PWR_CR2_PVME2_Pos)              /*!< 0x00000020 */
#define PWR_CR2_PVME2                PWR_CR2_PVME2_Msk                         /*!< PVM 2 Enable */
#define PWR_CR2_PVME1_Pos            (4U)
#define PWR_CR2_PVME1_Msk            (0x1UL << PWR_CR2_PVME1_Pos)              /*!< 0x00000010 */
#define PWR_CR2_PVME1                PWR_CR2_PVME1_Msk                         /*!< PVM 1 Enable */

/*!< PVD level configuration */
#define PWR_CR2_PLS_Pos              (1U)
#define PWR_CR2_PLS_Msk              (0x7UL << PWR_CR2_PLS_Pos)                /*!< 0x0000000E */
#define PWR_CR2_PLS                  PWR_CR2_PLS_Msk                           /*!< PVD level selection */
#define PWR_CR2_PLS_LEV0             (0x00000000U)                             /*!< PVD level 0 */
#define PWR_CR2_PLS_LEV1_Pos         (1U)
#define PWR_CR2_PLS_LEV1_Msk         (0x1UL << PWR_CR2_PLS_LEV1_Pos)           /*!< 0x00000002 */
#define PWR_CR2_PLS_LEV1             PWR_CR2_PLS_LEV1_Msk                      /*!< PVD level 1 */
#define PWR_CR2_PLS_LEV2_Pos         (2U)
#define PWR_CR2_PLS_LEV2_Msk         (0x1UL << PWR_CR2_PLS_LEV2_Pos)           /*!< 0x00000004 */
#define PWR_CR2_PLS_LEV2             PWR_CR2_PLS_LEV2_Msk                      /*!< PVD level 2 */
#define PWR_CR2_PLS_LEV3_Pos         (1U)
#define PWR_CR2_PLS_LEV3_Msk         (0x3UL << PWR_CR2_PLS_LEV3_Pos)           /*!< 0x00000006 */
#define PWR_CR2_PLS_LEV3             PWR_CR2_PLS_LEV3_Msk                      /*!< PVD level 3 */
#define PWR_CR2_PLS_LEV4_Pos         (3U)
#define PWR_CR2_PLS_LEV4_Msk         (0x1UL << PWR_CR2_PLS_LEV4_Pos)           /*!< 0x00000008 */
#define PWR_CR2_PLS_LEV4             PWR_CR2_PLS_LEV4_Msk                      /*!< PVD level 4 */
#define PWR_CR2_PLS_LEV5_Pos         (1U)
#define PWR_CR2_PLS_LEV5_Msk         (0x5UL << PWR_CR2_PLS_LEV5_Pos)           /*!< 0x0000000A */
#define PWR_CR2_PLS_LEV5             PWR_CR2_PLS_LEV5_Msk                      /*!< PVD level 5 */
#define PWR_CR2_PLS_LEV6_Pos         (2U)
#define PWR_CR2_PLS_LEV6_Msk         (0x3UL << PWR_CR2_PLS_LEV6_Pos)           /*!< 0x0000000C */
#define PWR_CR2_PLS_LEV6             PWR_CR2_PLS_LEV6_Msk                      /*!< PVD level 6 */
#define PWR_CR2_PLS_LEV7_Pos         (1U)
#define PWR_CR2_PLS_LEV7_Msk         (0x7UL << PWR_CR2_PLS_LEV7_Pos)           /*!< 0x0000000E */
#define PWR_CR2_PLS_LEV7             PWR_CR2_PLS_LEV7_Msk                      /*!< PVD level 7 */
#define PWR_CR2_PVDE_Pos             (0U)
#define PWR_CR2_PVDE_Msk             (0x1UL << PWR_CR2_PVDE_Pos)               /*!< 0x00000001 */
#define PWR_CR2_PVDE                 PWR_CR2_PVDE_Msk                          /*!< Power Voltage Detector Enable */

/********************  Bit definition for PWR_CR3 register  ********************/
#define PWR_CR3_EIWF_Pos             (15U)
#define PWR_CR3_EIWF_Msk             (0x1UL << PWR_CR3_EIWF_Pos)               /*!< 0x00008000 */
#define PWR_CR3_EIWF                 PWR_CR3_EIWF_Msk                          /*!< Enable Internal Wake-up line */
#define PWR_CR3_UCPD_DBDIS_Pos       (14U)
#define PWR_CR3_UCPD_DBDIS_Msk       (0x1UL << PWR_CR3_UCPD_DBDIS_Pos)         /*!< 0x00004000 */
#define PWR_CR3_UCPD_DBDIS           PWR_CR3_UCPD_DBDIS_Msk                    /*!< USB Type-C and Power Delivery Dead Battery disable. */
#define PWR_CR3_UCPD_STDBY_Pos       (13U)
#define PWR_CR3_UCPD_STDBY_Msk       (0x1UL << PWR_CR3_UCPD_STDBY_Pos)         /*!< 0x00002000 */
#define PWR_CR3_UCPD_STDBY           PWR_CR3_UCPD_STDBY_Msk                    /*!< USB Type-C and Power Delivery standby mode. */
#define PWR_CR3_APC_Pos              (10U)
#define PWR_CR3_APC_Msk              (0x1UL << PWR_CR3_APC_Pos)                /*!< 0x00000400 */
#define PWR_CR3_APC                  PWR_CR3_APC_Msk                           /*!< Apply pull-up and pull-down configuration */
#define PWR_CR3_RRS_Pos              (8U)
#define PWR_CR3_RRS_Msk              (0x1UL << PWR_CR3_RRS_Pos)                /*!< 0x00000100 */
#define PWR_CR3_RRS                  PWR_CR3_RRS_Msk                           /*!< SRAM2 Retention in Stand-by mode */
#define PWR_CR3_EWUP5_Pos            (4U)
#define PWR_CR3_EWUP5_Msk            (0x1UL << PWR_CR3_EWUP5_Pos)              /*!< 0x00000010 */
#define PWR_CR3_EWUP5                PWR_CR3_EWUP5_Msk                         /*!< Enable Wake-Up Pin 5 */
#define PWR_CR3_EWUP4_Pos            (3U)
#define PWR_CR3_EWUP4_Msk            (0x1UL << PWR_CR3_EWUP4_Pos)              /*!< 0x00000008 */
#define PWR_CR3_EWUP4                PWR_CR3_EWUP4_Msk                         /*!< Enable Wake-Up Pin 4 */
#define PWR_CR3_EWUP3_Pos            (2U)
#define PWR_CR3_EWUP3_Msk            (0x1UL << PWR_CR3_EWUP3_Pos)              /*!< 0x00000004 */
#define PWR_CR3_EWUP3                PWR_CR3_EWUP3_Msk                         /*!< Enable Wake-Up Pin 3 */
#define PWR_CR3_EWUP2_Pos            (1U)
#define PWR_CR3_EWUP2_Msk            (0x1UL << PWR_CR3_EWUP2_Pos)              /*!< 0x00000002 */
#define PWR_CR3_EWUP2                PWR_CR3_EWUP2_Msk                         /*!< Enable Wake-Up Pin 2 */
#define PWR_CR3_EWUP1_Pos            (0U)
#define PWR_CR3_EWUP1_Msk            (0x1UL << PWR_CR3_EWUP1_Pos)              /*!< 0x00000001 */
#define PWR_CR3_EWUP1                PWR_CR3_EWUP1_Msk                         /*!< Enable Wake-Up Pin 1 */
#define PWR_CR3_EWUP_Pos             (0U)
#define PWR_CR3_EWUP_Msk             (0x1FUL << PWR_CR3_EWUP_Pos)              /*!< 0x0000001F */
#define PWR_CR3_EWUP                 PWR_CR3_EWUP_Msk                          /*!< Enable Wake-Up Pins  */

/********************  Bit definition for PWR_CR4 register  ********************/
#define PWR_CR4_VBRS_Pos             (9U)
#define PWR_CR4_VBRS_Msk             (0x1UL << PWR_CR4_VBRS_Pos)               /*!< 0x00000200 */
#define PWR_CR4_VBRS                 PWR_CR4_VBRS_Msk                          /*!< VBAT Battery charging Resistor Selection */
#define PWR_CR4_VBE_Pos              (8U)
#define PWR_CR4_VBE_Msk              (0x1UL << PWR_CR4_VBE_Pos)                /*!< 0x00000100 */
#define PWR_CR4_VBE                  PWR_CR4_VBE_Msk                           /*!< VBAT Battery charging Enable  */
#define PWR_CR4_WP5_Pos              (4U)
#define PWR_CR4_WP5_Msk              (0x1UL << PWR_CR4_WP5_Pos)                /*!< 0x00000010 */
#define PWR_CR4_WP5                  PWR_CR4_WP5_Msk                           /*!< Wake-Up Pin 5 polarity */
#define PWR_CR4_WP4_Pos              (3U)
#define PWR_CR4_WP4_Msk              (0x1UL << PWR_CR4_WP4_Pos)                /*!< 0x00000008 */
#define PWR_CR4_WP4                  PWR_CR4_WP4_Msk                           /*!< Wake-Up Pin 4 polarity */
#define PWR_CR4_WP3_Pos              (2U)
#define PWR_CR4_WP3_Msk              (0x1UL << PWR_CR4_WP3_Pos)                /*!< 0x00000004 */
#define PWR_CR4_WP3                  PWR_CR4_WP3_Msk                           /*!< Wake-Up Pin 3 polarity */
#define PWR_CR4_WP2_Pos              (1U)
#define PWR_CR4_WP2_Msk              (0x1UL << PWR_CR4_WP2_Pos)                /*!< 0x00000002 */
#define PWR_CR4_WP2                  PWR_CR4_WP2_Msk                           /*!< Wake-Up Pin 2 polarity */
#define PWR_CR4_WP1_Pos              (0U)
#define PWR_CR4_WP1_Msk              (0x1UL << PWR_CR4_WP1_Pos)                /*!< 0x00000001 */
#define PWR_CR4_WP1                  PWR_CR4_WP1_Msk                           /*!< Wake-Up Pin 1 polarity */

/********************  Bit definition for PWR_SR1 register  ********************/
#define PWR_SR1_WUFI_Pos             (15U)
#define PWR_SR1_WUFI_Msk             (0x1UL << PWR_SR1_WUFI_Pos)               /*!< 0x00008000 */
#define PWR_SR1_WUFI                 PWR_SR1_WUFI_Msk                          /*!< Wake-Up Flag Internal */
#define PWR_SR1_SBF_Pos              (8U)
#define PWR_SR1_SBF_Msk              (0x1UL << PWR_SR1_SBF_Pos)                /*!< 0x00000100 */
#define PWR_SR1_SBF                  PWR_SR1_SBF_Msk                           /*!< Stand-By Flag */
#define PWR_SR1_WUF_Pos              (0U)
#define PWR_SR1_WUF_Msk              (0x1FUL << PWR_SR1_WUF_Pos)               /*!< 0x0000001F */
#define PWR_SR1_WUF                  PWR_SR1_WUF_Msk                           /*!< Wake-up Flags */
#define PWR_SR1_WUF5_Pos             (4U)
#define PWR_SR1_WUF5_Msk             (0x1UL << PWR_SR1_WUF5_Pos)               /*!< 0x00000010 */
#define PWR_SR1_WUF5                 PWR_SR1_WUF5_Msk                          /*!< Wake-up Flag 5 */
#define PWR_SR1_WUF4_Pos             (3U)
#define PWR_SR1_WUF4_Msk             (0x1UL << PWR_SR1_WUF4_Pos)               /*!< 0x00000008 */
#define PWR_SR1_WUF4                 PWR_SR1_WUF4_Msk                          /*!< Wake-up Flag 4 */
#define PWR_SR1_WUF3_Pos             (2U)
#define PWR_SR1_WUF3_Msk             (0x1UL << PWR_SR1_WUF3_Pos)               /*!< 0x00000004 */
#define PWR_SR1_WUF3                 PWR_SR1_WUF3_Msk                          /*!< Wake-up Flag 3 */
#define PWR_SR1_WUF2_Pos             (1U)
#define PWR_SR1_WUF2_Msk             (0x1UL << PWR_SR1_WUF2_Pos)               /*!< 0x00000002 */
#define PWR_SR1_WUF2                 PWR_SR1_WUF2_Msk                          /*!< Wake-up Flag 2 */
#define PWR_SR1_WUF1_Pos             (0U)
#define PWR_SR1_WUF1_Msk             (0x1UL << PWR_SR1_WUF1_Pos)               /*!< 0x00000001 */
#define PWR_SR1_WUF1                 PWR_SR1_WUF1_Msk                          /*!< Wake-up Flag 1 */

/********************  Bit definition for PWR_SR2 register  ********************/
#define PWR_SR2_PVMO4_Pos            (15U)
#define PWR_SR2_PVMO4_Msk            (0x1UL << PWR_SR2_PVMO4_Pos)              /*!< 0x00008000 */
#define PWR_SR2_PVMO4                PWR_SR2_PVMO4_Msk                         /*!< Peripheral Voltage Monitoring Output 4 */
#define PWR_SR2_PVMO3_Pos            (14U)
#define PWR_SR2_PVMO3_Msk            (0x1UL << PWR_SR2_PVMO3_Pos)              /*!< 0x00004000 */
#define PWR_SR2_PVMO3                PWR_SR2_PVMO3_Msk                         /*!< Peripheral Voltage Monitoring Output 3 */
#define PWR_SR2_PVMO2_Pos            (13U)
#define PWR_SR2_PVMO2_Msk            (0x1UL << PWR_SR2_PVMO2_Pos)              /*!< 0x00002000 */
#define PWR_SR2_PVMO2                PWR_SR2_PVMO2_Msk                         /*!< Peripheral Voltage Monitoring Output 2 */
#define PWR_SR2_PVMO1_Pos            (12U)
#define PWR_SR2_PVMO1_Msk            (0x1UL << PWR_SR2_PVMO1_Pos)              /*!< 0x00001000 */
#define PWR_SR2_PVMO1                PWR_SR2_PVMO1_Msk                         /*!< Peripheral Voltage Monitoring Output 1 */
#define PWR_SR2_PVDO_Pos             (11U)
#define PWR_SR2_PVDO_Msk             (0x1UL << PWR_SR2_PVDO_Pos)               /*!< 0x00000800 */
#define PWR_SR2_PVDO                 PWR_SR2_PVDO_Msk                          /*!< Power Voltage Detector Output */
#define PWR_SR2_VOSF_Pos             (10U)
#define PWR_SR2_VOSF_Msk             (0x1UL << PWR_SR2_VOSF_Pos)               /*!< 0x00000400 */
#define PWR_SR2_VOSF                 PWR_SR2_VOSF_Msk                          /*!< Voltage Scaling Flag */
#define PWR_SR2_REGLPF_Pos           (9U)
#define PWR_SR2_REGLPF_Msk           (0x1UL << PWR_SR2_REGLPF_Pos)             /*!< 0x00000200 */
#define PWR_SR2_REGLPF               PWR_SR2_REGLPF_Msk                        /*!< Low-power Regulator Flag */
#define PWR_SR2_REGLPS_Pos           (8U)
#define PWR_SR2_REGLPS_Msk           (0x1UL << PWR_SR2_REGLPS_Pos)             /*!< 0x00000100 */
#define PWR_SR2_REGLPS               PWR_SR2_REGLPS_Msk                        /*!< Low-power Regulator Started */

/********************  Bit definition for PWR_SCR register  ********************/
#define PWR_SCR_CSBF_Pos             (8U)
#define PWR_SCR_CSBF_Msk             (0x1UL << PWR_SCR_CSBF_Pos)               /*!< 0x00000100 */
#define PWR_SCR_CSBF                 PWR_SCR_CSBF_Msk                          /*!< Clear Stand-By Flag */
#define PWR_SCR_CWUF_Pos             (0U)
#define PWR_SCR_CWUF_Msk             (0x1FUL << PWR_SCR_CWUF_Pos)              /*!< 0x0000001F */
#define PWR_SCR_CWUF                 PWR_SCR_CWUF_Msk                          /*!< Clear Wake-up Flags  */
#define PWR_SCR_CWUF5_Pos            (4U)
#define PWR_SCR_CWUF5_Msk            (0x1UL << PWR_SCR_CWUF5_Pos)              /*!< 0x00000010 */
#define PWR_SCR_CWUF5                PWR_SCR_CWUF5_Msk                         /*!< Clear Wake-up Flag 5 */
#define PWR_SCR_CWUF4_Pos            (3U)
#define PWR_SCR_CWUF4_Msk            (0x1UL << PWR_SCR_CWUF4_Pos)              /*!< 0x00000008 */
#define PWR_SCR_CWUF4                PWR_SCR_CWUF4_Msk                         /*!< Clear Wake-up Flag 4 */
#define PWR_SCR_CWUF3_Pos            (2U)
#define PWR_SCR_CWUF3_Msk            (0x1UL << PWR_SCR_CWUF3_Pos)              /*!< 0x00000004 */
#define PWR_SCR_CWUF3                PWR_SCR_CWUF3_Msk                         /*!< Clear Wake-up Flag 3 */
#define PWR_SCR_CWUF2_Pos            (1U)
#define PWR_SCR_CWUF2_Msk            (0x1UL << PWR_SCR_CWUF2_Pos)              /*!< 0x00000002 */
#define PWR_SCR_CWUF2                PWR_SCR_CWUF2_Msk                         /*!< Clear Wake-up Flag 2 */
#define PWR_SCR_CWUF1_Pos            (0U)
#define PWR_SCR_CWUF1_Msk            (0x1UL << PWR_SCR_CWUF1_Pos)              /*!< 0x00000001 */
#define PWR_SCR_CWUF1                PWR_SCR_CWUF1_Msk                         /*!< Clear Wake-up Flag 1 */

/********************  Bit definition for PWR_PUCRA register  ********************/
#define PWR_PUCRA_PA15_Pos           (15U)
#define PWR_PUCRA_PA15_Msk           (0x1UL << PWR_PUCRA_PA15_Pos)             /*!< 0x00008000 */
#define PWR_PUCRA_PA15               PWR_PUCRA_PA15_Msk                        /*!< Port PA15 Pull-Up set */
#define PWR_PUCRA_PA13_Pos           (13U)
#define PWR_PUCRA_PA13_Msk           (0x1UL << PWR_PUCRA_PA13_Pos)             /*!< 0x00002000 */
#define PWR_PUCRA_PA13               PWR_PUCRA_PA13_Msk                        /*!< Port PA13 Pull-Up set */
#define PWR_PUCRA_PA12_Pos           (12U)
#define PWR_PUCRA_PA12_Msk           (0x1UL << PWR_PUCRA_PA12_Pos)             /*!< 0x00001000 */
#define PWR_PUCRA_PA12               PWR_PUCRA_PA12_Msk                        /*!< Port PA12 Pull-Up set */
#define PWR_PUCRA_PA11_Pos           (11U)
#define PWR_PUCRA_PA11_Msk           (0x1UL << PWR_PUCRA_PA11_Pos)             /*!< 0x00000800 */
#define PWR_PUCRA_PA11               PWR_PUCRA_PA11_Msk                        /*!< Port PA11 Pull-Up set */
#define PWR_PUCRA_PA10_Pos           (10U)
#define PWR_PUCRA_PA10_Msk           (0x1UL << PWR_PUCRA_PA10_Pos)             /*!< 0x00000400 */
#define PWR_PUCRA_PA10               PWR_PUCRA_PA10_Msk                        /*!< Port PA10 Pull-Up set */
#define PWR_PUCRA_PA9_Pos            (9U)
#define PWR_PUCRA_PA9_Msk            (0x1UL << PWR_PUCRA_PA9_Pos)              /*!< 0x00000200 */
#define PWR_PUCRA_PA9                PWR_PUCRA_PA9_Msk                         /*!< Port PA9 Pull-Up set  */
#define PWR_PUCRA_PA8_Pos            (8U)
#define PWR_PUCRA_PA8_Msk            (0x1UL << PWR_PUCRA_PA8_Pos)              /*!< 0x00000100 */
#define PWR_PUCRA_PA8                PWR_PUCRA_PA8_Msk                         /*!< Port PA8 Pull-Up set  */
#define PWR_PUCRA_PA7_Pos            (7U)
#define PWR_PUCRA_PA7_Msk            (0x1UL << PWR_PUCRA_PA7_Pos)              /*!< 0x00000080 */
#define PWR_PUCRA_PA7                PWR_PUCRA_PA7_Msk                         /*!< Port PA7 Pull-Up set  */
#define PWR_PUCRA_PA6_Pos            (6U)
#define PWR_PUCRA_PA6_Msk            (0x1UL << PWR_PUCRA_PA6_Pos)              /*!< 0x00000040 */
#define PWR_PUCRA_PA6                PWR_PUCRA_PA6_Msk                         /*!< Port PA6 Pull-Up set  */
#define PWR_PUCRA_PA5_Pos            (5U)
#define PWR_PUCRA_PA5_Msk            (0x1UL << PWR_PUCRA_PA5_Pos)              /*!< 0x00000020 */
#define PWR_PUCRA_PA5                PWR_PUCRA_PA5_Msk                         /*!< Port PA5 Pull-Up set  */
#define PWR_PUCRA_PA4_Pos            (4U)
#define PWR_PUCRA_PA4_Msk            (0x1UL << PWR_PUCRA_PA4_Pos)              /*!< 0x00000010 */
#define PWR_PUCRA_PA4                PWR_PUCRA_PA4_Msk                         /*!< Port PA4 Pull-Up set  */
#define PWR_PUCRA_PA3_Pos            (3U)
#define PWR_PUCRA_PA3_Msk            (0x1UL << PWR_PUCRA_PA3_Pos)              /*!< 0x00000008 */
#define PWR_PUCRA_PA3                PWR_PUCRA_PA3_Msk                         /*!< Port PA3 Pull-Up set  */
#define PWR_PUCRA_PA2_Pos            (2U)
#define PWR_PUCRA_PA2_Msk            (0x1UL << PWR_PUCRA_PA2_Pos)              /*!< 0x00000004 */
#define PWR_PUCRA_PA2                PWR_PUCRA_PA2_Msk                         /*!< Port PA2 Pull-Up set  */
#define PWR_PUCRA_PA1_Pos            (1U)
#define PWR_PUCRA_PA1_Msk            (0x1UL << PWR_PUCRA_PA1_Pos)              /*!< 0x00000002 */
#define PWR_PUCRA_PA1                PWR_PUCRA_PA1_Msk                         /*!< Port PA1 Pull-Up set  */
#define PWR_PUCRA_PA0_Pos            (0U)
#define PWR_PUCRA_PA0_Msk            (0x1UL << PWR_PUCRA_PA0_Pos)              /*!< 0x00000001 */
#define PWR_PUCRA_PA0                PWR_PUCRA_PA0_Msk                         /*!< Port PA0 Pull-Up set  */

/********************  Bit definition for PWR_PDCRA register  ********************/
#define PWR_PDCRA_PA14_Pos           (14U)
#define PWR_PDCRA_PA14_Msk           (0x1UL << PWR_PDCRA_PA14_Pos)             /*!< 0x00004000 */
#define PWR_PDCRA_PA14               PWR_PDCRA_PA14_Msk                        /*!< Port PA14 Pull-Down set */
#define PWR_PDCRA_PA12_Pos           (12U)
#define PWR_PDCRA_PA12_Msk           (0x1UL << PWR_PDCRA_PA12_Pos)             /*!< 0x00001000 */
#define PWR_PDCRA_PA12               PWR_PDCRA_PA12_Msk                        /*!< Port PA12 Pull-Down set */
#define PWR_PDCRA_PA11_Pos           (11U)
#define PWR_PDCRA_PA11_Msk           (0x1UL << PWR_PDCRA_PA11_Pos)             /*!< 0x00000800 */
#define PWR_PDCRA_PA11               PWR_PDCRA_PA11_Msk                        /*!< Port PA11 Pull-Down set */
#define PWR_PDCRA_PA10_Pos           (10U)
#define PWR_PDCRA_PA10_Msk           (0x1UL << PWR_PDCRA_PA10_Pos)             /*!< 0x00000400 */
#define PWR_PDCRA_PA10               PWR_PDCRA_PA10_Msk                        /*!< Port PA10 Pull-Down set */
#define PWR_PDCRA_PA9_Pos            (9U)
#define PWR_PDCRA_PA9_Msk            (0x1UL << PWR_PDCRA_PA9_Pos)              /*!< 0x00000200 */
#define PWR_PDCRA_PA9                PWR_PDCRA_PA9_Msk                         /*!< Port PA9 Pull-Down set  */
#define PWR_PDCRA_PA8_Pos            (8U)
#define PWR_PDCRA_PA8_Msk            (0x1UL << PWR_PDCRA_PA8_Pos)              /*!< 0x00000100 */
#define PWR_PDCRA_PA8                PWR_PDCRA_PA8_Msk                         /*!< Port PA8 Pull-Down set  */
#define PWR_PDCRA_PA7_Pos            (7U)
#define PWR_PDCRA_PA7_Msk            (0x1UL << PWR_PDCRA_PA7_Pos)              /*!< 0x00000080 */
#define PWR_PDCRA_PA7                PWR_PDCRA_PA7_Msk                         /*!< Port PA7 Pull-Down set  */
#define PWR_PDCRA_PA6_Pos            (6U)
#define PWR_PDCRA_PA6_Msk            (0x1UL << PWR_PDCRA_PA6_Pos)              /*!< 0x00000040 */
#define PWR_PDCRA_PA6                PWR_PDCRA_PA6_Msk                         /*!< Port PA6 Pull-Down set  */
#define PWR_PDCRA_PA5_Pos            (5U)
#define PWR_PDCRA_PA5_Msk            (0x1UL << PWR_PDCRA_PA5_Pos)              /*!< 0x00000020 */
#define PWR_PDCRA_PA5                PWR_PDCRA_PA5_Msk                         /*!< Port PA5 Pull-Down set  */
#define PWR_PDCRA_PA4_Pos            (4U)
#define PWR_PDCRA_PA4_Msk            (0x1UL << PWR_PDCRA_PA4_Pos)              /*!< 0x00000010 */
#define PWR_PDCRA_PA4                PWR_PDCRA_PA4_Msk                         /*!< Port PA4 Pull-Down set  */
#define PWR_PDCRA_PA3_Pos            (3U)
#define PWR_PDCRA_PA3_Msk            (0x1UL << PWR_PDCRA_PA3_Pos)              /*!< 0x00000008 */
#define PWR_PDCRA_PA3                PWR_PDCRA_PA3_Msk                         /*!< Port PA3 Pull-Down set  */
#define PWR_PDCRA_PA2_Pos            (2U)
#define PWR_PDCRA_PA2_Msk            (0x1UL << PWR_PDCRA_PA2_Pos)              /*!< 0x00000004 */
#define PWR_PDCRA_PA2                PWR_PDCRA_PA2_Msk                         /*!< Port PA2 Pull-Down set  */
#define PWR_PDCRA_PA1_Pos            (1U)
#define PWR_PDCRA_PA1_Msk            (0x1UL << PWR_PDCRA_PA1_Pos)              /*!< 0x00000002 */
#define PWR_PDCRA_PA1                PWR_PDCRA_PA1_Msk                         /*!< Port PA1 Pull-Down set  */
#define PWR_PDCRA_PA0_Pos            (0U)
#define PWR_PDCRA_PA0_Msk            (0x1UL << PWR_PDCRA_PA0_Pos)              /*!< 0x00000001 */
#define PWR_PDCRA_PA0                PWR_PDCRA_PA0_Msk                         /*!< Port PA0 Pull-Down set  */

/********************  Bit definition for PWR_PUCRB register  ********************/

#define PWR_PUCRB_PB15_Pos           (15U)
#define PWR_PUCRB_PB15_Msk           (0x1UL << PWR_PUCRB_PB15_Pos)             /*!< 0x00008000 */
#define PWR_PUCRB_PB15               PWR_PUCRB_PB15_Msk                        /*!< Port PB15 Pull-Up set */
#define PWR_PUCRB_PB14_Pos           (14U)
#define PWR_PUCRB_PB14_Msk           (0x1UL << PWR_PUCRB_PB14_Pos)             /*!< 0x00004000 */
#define PWR_PUCRB_PB14               PWR_PUCRB_PB14_Msk                        /*!< Port PB14 Pull-Up set */
#define PWR_PUCRB_PB13_Pos           (13U)
#define PWR_PUCRB_PB13_Msk           (0x1UL << PWR_PUCRB_PB13_Pos)             /*!< 0x00002000 */
#define PWR_PUCRB_PB13               PWR_PUCRB_PB13_Msk                        /*!< Port PB13 Pull-Up set */
#define PWR_PUCRB_PB12_Pos           (12U)
#define PWR_PUCRB_PB12_Msk           (0x1UL << PWR_PUCRB_PB12_Pos)             /*!< 0x00001000 */
#define PWR_PUCRB_PB12               PWR_PUCRB_PB12_Msk                        /*!< Port PB12 Pull-Up set */
#define PWR_PUCRB_PB11_Pos           (11U)
#define PWR_PUCRB_PB11_Msk           (0x1UL << PWR_PUCRB_PB11_Pos)             /*!< 0x00000800 */
#define PWR_PUCRB_PB11               PWR_PUCRB_PB11_Msk                        /*!< Port PB11 Pull-Up set */
#define PWR_PUCRB_PB10_Pos           (10U)
#define PWR_PUCRB_PB10_Msk           (0x1UL << PWR_PUCRB_PB10_Pos)             /*!< 0x00000400 */
#define PWR_PUCRB_PB10               PWR_PUCRB_PB10_Msk                        /*!< Port PB10 Pull-Up set */
#define PWR_PUCRB_PB9_Pos            (9U)
#define PWR_PUCRB_PB9_Msk            (0x1UL << PWR_PUCRB_PB9_Pos)              /*!< 0x00000200 */
#define PWR_PUCRB_PB9                PWR_PUCRB_PB9_Msk                         /*!< Port PB9 Pull-Up set  */
#define PWR_PUCRB_PB8_Pos            (8U)
#define PWR_PUCRB_PB8_Msk            (0x1UL << PWR_PUCRB_PB8_Pos)              /*!< 0x00000100 */
#define PWR_PUCRB_PB8                PWR_PUCRB_PB8_Msk                         /*!< Port PB8 Pull-Up set  */
#define PWR_PUCRB_PB7_Pos            (7U)
#define PWR_PUCRB_PB7_Msk            (0x1UL << PWR_PUCRB_PB7_Pos)              /*!< 0x00000080 */
#define PWR_PUCRB_PB7                PWR_PUCRB_PB7_Msk                         /*!< Port PB7 Pull-Up set  */
#define PWR_PUCRB_PB6_Pos            (6U)
#define PWR_PUCRB_PB6_Msk            (0x1UL << PWR_PUCRB_PB6_Pos)              /*!< 0x00000040 */
#define PWR_PUCRB_PB6                PWR_PUCRB_PB6_Msk                         /*!< Port PB6 Pull-Up set  */
#define PWR_PUCRB_PB5_Pos            (5U)
#define PWR_PUCRB_PB5_Msk            (0x1UL << PWR_PUCRB_PB5_Pos)              /*!< 0x00000020 */
#define PWR_PUCRB_PB5                PWR_PUCRB_PB5_Msk                         /*!< Port PB5 Pull-Up set  */
#define PWR_PUCRB_PB4_Pos            (4U)
#define PWR_PUCRB_PB4_Msk            (0x1UL << PWR_PUCRB_PB4_Pos)              /*!< 0x00000010 */
#define PWR_PUCRB_PB4                PWR_PUCRB_PB4_Msk                         /*!< Port PB4 Pull-Up set  */
#define PWR_PUCRB_PB3_Pos            (3U)
#define PWR_PUCRB_PB3_Msk            (0x1UL << PWR_PUCRB_PB3_Pos)              /*!< 0x00000008 */
#define PWR_PUCRB_PB3                PWR_PUCRB_PB3_Msk                         /*!< Port PB3 Pull-Up set  */
#define PWR_PUCRB_PB2_Pos            (2U)
#define PWR_PUCRB_PB2_Msk            (0x1UL << PWR_PUCRB_PB2_Pos)              /*!< 0x00000004 */
#define PWR_PUCRB_PB2                PWR_PUCRB_PB2_Msk                         /*!< Port PB2 Pull-Up set  */
#define PWR_PUCRB_PB1_Pos            (1U)
#define PWR_PUCRB_PB1_Msk            (0x1UL << PWR_PUCRB_PB1_Pos)              /*!< 0x00000002 */
#define PWR_PUCRB_PB1                PWR_PUCRB_PB1_Msk                         /*!< Port PB1 Pull-Up set  */
#define PWR_PUCRB_PB0_Pos            (0U)
#define PWR_PUCRB_PB0_Msk            (0x1UL << PWR_PUCRB_PB0_Pos)              /*!< 0x00000001 */
#define PWR_PUCRB_PB0                PWR_PUCRB_PB0_Msk                         /*!< Port PB0 Pull-Up set  */

/********************  Bit definition for PWR_PDCRB register  ********************/
#define PWR_PDCRB_PB15_Pos           (15U)
#define PWR_PDCRB_PB15_Msk           (0x1UL << PWR_PDCRB_PB15_Pos)             /*!< 0x00008000 */
#define PWR_PDCRB_PB15               PWR_PDCRB_PB15_Msk                        /*!< Port PB15 Pull-Down set */
#define PWR_PDCRB_PB14_Pos           (14U)
#define PWR_PDCRB_PB14_Msk           (0x1UL << PWR_PDCRB_PB14_Pos)             /*!< 0x00004000 */
#define PWR_PDCRB_PB14               PWR_PDCRB_PB14_Msk                        /*!< Port PB14 Pull-Down set */
#define PWR_PDCRB_PB13_Pos           (13U)
#define PWR_PDCRB_PB13_Msk           (0x1UL << PWR_PDCRB_PB13_Pos)             /*!< 0x00002000 */
#define PWR_PDCRB_PB13               PWR_PDCRB_PB13_Msk                        /*!< Port PB13 Pull-Down set */
#define PWR_PDCRB_PB12_Pos           (12U)
#define PWR_PDCRB_PB12_Msk           (0x1UL << PWR_PDCRB_PB12_Pos)             /*!< 0x00001000 */
#define PWR_PDCRB_PB12               PWR_PDCRB_PB12_Msk                        /*!< Port PB12 Pull-Down set */
#define PWR_PDCRB_PB11_Pos           (11U)
#define PWR_PDCRB_PB11_Msk           (0x1UL << PWR_PDCRB_PB11_Pos)             /*!< 0x00000800 */
#define PWR_PDCRB_PB11               PWR_PDCRB_PB11_Msk                        /*!< Port PB11 Pull-Down set */
#define PWR_PDCRB_PB10_Pos           (10U)
#define PWR_PDCRB_PB10_Msk           (0x1UL << PWR_PDCRB_PB10_Pos)             /*!< 0x00000400 */
#define PWR_PDCRB_PB10               PWR_PDCRB_PB10_Msk                        /*!< Port PB10 Pull-Down set */
#define PWR_PDCRB_PB9_Pos            (9U)
#define PWR_PDCRB_PB9_Msk            (0x1UL << PWR_PDCRB_PB9_Pos)              /*!< 0x00000200 */
#define PWR_PDCRB_PB9                PWR_PDCRB_PB9_Msk                         /*!< Port PB9 Pull-Down set  */
#define PWR_PDCRB_PB8_Pos            (8U)
#define PWR_PDCRB_PB8_Msk            (0x1UL << PWR_PDCRB_PB8_Pos)              /*!< 0x00000100 */
#define PWR_PDCRB_PB8                PWR_PDCRB_PB8_Msk                         /*!< Port PB8 Pull-Down set  */
#define PWR_PDCRB_PB7_Pos            (7U)
#define PWR_PDCRB_PB7_Msk            (0x1UL << PWR_PDCRB_PB7_Pos)              /*!< 0x00000080 */
#define PWR_PDCRB_PB7                PWR_PDCRB_PB7_Msk                         /*!< Port PB7 Pull-Down set  */
#define PWR_PDCRB_PB6_Pos            (6U)
#define PWR_PDCRB_PB6_Msk            (0x1UL << PWR_PDCRB_PB6_Pos)              /*!< 0x00000040 */
#define PWR_PDCRB_PB6                PWR_PDCRB_PB6_Msk                         /*!< Port PB6 Pull-Down set  */
#define PWR_PDCRB_PB5_Pos            (5U)
#define PWR_PDCRB_PB5_Msk            (0x1UL << PWR_PDCRB_PB5_Pos)              /*!< 0x00000020 */
#define PWR_PDCRB_PB5                PWR_PDCRB_PB5_Msk                         /*!< Port PB5 Pull-Down set  */
#define PWR_PDCRB_PB3_Pos            (3U)
#define PWR_PDCRB_PB3_Msk            (0x1UL << PWR_PDCRB_PB3_Pos)              /*!< 0x00000008 */
#define PWR_PDCRB_PB3                PWR_PDCRB_PB3_Msk                         /*!< Port PB3 Pull-Down set  */
#define PWR_PDCRB_PB2_Pos            (2U)
#define PWR_PDCRB_PB2_Msk            (0x1UL << PWR_PDCRB_PB2_Pos)              /*!< 0x00000004 */
#define PWR_PDCRB_PB2                PWR_PDCRB_PB2_Msk                         /*!< Port PB2 Pull-Down set  */
#define PWR_PDCRB_PB1_Pos            (1U)
#define PWR_PDCRB_PB1_Msk            (0x1UL << PWR_PDCRB_PB1_Pos)              /*!< 0x00000002 */
#define PWR_PDCRB_PB1                PWR_PDCRB_PB1_Msk                         /*!< Port PB1 Pull-Down set  */
#define PWR_PDCRB_PB0_Pos            (0U)
#define PWR_PDCRB_PB0_Msk            (0x1UL << PWR_PDCRB_PB0_Pos)              /*!< 0x00000001 */
#define PWR_PDCRB_PB0                PWR_PDCRB_PB0_Msk                         /*!< Port PB0 Pull-Down set  */

/********************  Bit definition for PWR_PUCRC register  ********************/
#define PWR_PUCRC_PC15_Pos           (15U)
#define PWR_PUCRC_PC15_Msk           (0x1UL << PWR_PUCRC_PC15_Pos)             /*!< 0x00008000 */
#define PWR_PUCRC_PC15               PWR_PUCRC_PC15_Msk                        /*!< Port PC15 Pull-Up set */
#define PWR_PUCRC_PC14_Pos           (14U)
#define PWR_PUCRC_PC14_Msk           (0x1UL << PWR_PUCRC_PC14_Pos)             /*!< 0x00004000 */
#define PWR_PUCRC_PC14               PWR_PUCRC_PC14_Msk                        /*!< Port PC14 Pull-Up set */
#define PWR_PUCRC_PC13_Pos           (13U)
#define PWR_PUCRC_PC13_Msk           (0x1UL << PWR_PUCRC_PC13_Pos)             /*!< 0x00002000 */
#define PWR_PUCRC_PC13               PWR_PUCRC_PC13_Msk                        /*!< Port PC13 Pull-Up set */
#define PWR_PUCRC_PC12_Pos           (12U)
#define PWR_PUCRC_PC12_Msk           (0x1UL << PWR_PUCRC_PC12_Pos)             /*!< 0x00001000 */
#define PWR_PUCRC_PC12               PWR_PUCRC_PC12_Msk                        /*!< Port PC12 Pull-Up set */
#define PWR_PUCRC_PC11_Pos           (11U)
#define PWR_PUCRC_PC11_Msk           (0x1UL << PWR_PUCRC_PC11_Pos)             /*!< 0x00000800 */
#define PWR_PUCRC_PC11               PWR_PUCRC_PC11_Msk                        /*!< Port PC11 Pull-Up set */
#define PWR_PUCRC_PC10_Pos           (10U)
#define PWR_PUCRC_PC10_Msk           (0x1UL << PWR_PUCRC_PC10_Pos)             /*!< 0x00000400 */
#define PWR_PUCRC_PC10               PWR_PUCRC_PC10_Msk                        /*!< Port PC10 Pull-Up set */
#define PWR_PUCRC_PC9_Pos            (9U)
#define PWR_PUCRC_PC9_Msk            (0x1UL << PWR_PUCRC_PC9_Pos)              /*!< 0x00000200 */
#define PWR_PUCRC_PC9                PWR_PUCRC_PC9_Msk                         /*!< Port PC9 Pull-Up set  */
#define PWR_PUCRC_PC8_Pos            (8U)
#define PWR_PUCRC_PC8_Msk            (0x1UL << PWR_PUCRC_PC8_Pos)              /*!< 0x00000100 */
#define PWR_PUCRC_PC8                PWR_PUCRC_PC8_Msk                         /*!< Port PC8 Pull-Up set  */
#define PWR_PUCRC_PC7_Pos            (7U)
#define PWR_PUCRC_PC7_Msk            (0x1UL << PWR_PUCRC_PC7_Pos)              /*!< 0x00000080 */
#define PWR_PUCRC_PC7                PWR_PUCRC_PC7_Msk                         /*!< Port PC7 Pull-Up set  */
#define PWR_PUCRC_PC6_Pos            (6U)
#define PWR_PUCRC_PC6_Msk            (0x1UL << PWR_PUCRC_PC6_Pos)              /*!< 0x00000040 */
#define PWR_PUCRC_PC6                PWR_PUCRC_PC6_Msk                         /*!< Port PC6 Pull-Up set  */
#define PWR_PUCRC_PC5_Pos            (5U)
#define PWR_PUCRC_PC5_Msk            (0x1UL << PWR_PUCRC_PC5_Pos)              /*!< 0x00000020 */
#define PWR_PUCRC_PC5                PWR_PUCRC_PC5_Msk                         /*!< Port PC5 Pull-Up set  */
#define PWR_PUCRC_PC4_Pos            (4U)
#define PWR_PUCRC_PC4_Msk            (0x1UL << PWR_PUCRC_PC4_Pos)              /*!< 0x00000010 */
#define PWR_PUCRC_PC4                PWR_PUCRC_PC4_Msk                         /*!< Port PC4 Pull-Up set  */
#define PWR_PUCRC_PC3_Pos            (3U)
#define PWR_PUCRC_PC3_Msk            (0x1UL << PWR_PUCRC_PC3_Pos)              /*!< 0x00000008 */
#define PWR_PUCRC_PC3                PWR_PUCRC_PC3_Msk                         /*!< Port PC3 Pull-Up set  */
#define PWR_PUCRC_PC2_Pos            (2U)
#define PWR_PUCRC_PC2_Msk            (0x1UL << PWR_PUCRC_PC2_Pos)              /*!< 0x00000004 */
#define PWR_PUCRC_PC2                PWR_PUCRC_PC2_Msk                         /*!< Port PC2 Pull-Up set  */
#define PWR_PUCRC_PC1_Pos            (1U)
#define PWR_PUCRC_PC1_Msk            (0x1UL << PWR_PUCRC_PC1_Pos)              /*!< 0x00000002 */
#define PWR_PUCRC_PC1                PWR_PUCRC_PC1_Msk                         /*!< Port PC1 Pull-Up set  */
#define PWR_PUCRC_PC0_Pos            (0U)
#define PWR_PUCRC_PC0_Msk            (0x1UL << PWR_PUCRC_PC0_Pos)              /*!< 0x00000001 */
#define PWR_PUCRC_PC0                PWR_PUCRC_PC0_Msk                         /*!< Port PC0 Pull-Up set  */

/********************  Bit definition for PWR_PDCRC register  ********************/
#define PWR_PDCRC_PC15_Pos           (15U)
#define PWR_PDCRC_PC15_Msk           (0x1UL << PWR_PDCRC_PC15_Pos)             /*!< 0x00008000 */
#define PWR_PDCRC_PC15               PWR_PDCRC_PC15_Msk                        /*!< Port PC15 Pull-Down set */
#define PWR_PDCRC_PC14_Pos           (14U)
#define PWR_PDCRC_PC14_Msk           (0x1UL << PWR_PDCRC_PC14_Pos)             /*!< 0x00004000 */
#define PWR_PDCRC_PC14               PWR_PDCRC_PC14_Msk                        /*!< Port PC14 Pull-Down set */
#define PWR_PDCRC_PC13_Pos           (13U)
#define PWR_PDCRC_PC13_Msk           (0x1UL << PWR_PDCRC_PC13_Pos)             /*!< 0x00002000 */
#define PWR_PDCRC_PC13               PWR_PDCRC_PC13_Msk                        /*!< Port PC13 Pull-Down set */
#define PWR_PDCRC_PC12_Pos           (12U)
#define PWR_PDCRC_PC12_Msk           (0x1UL << PWR_PDCRC_PC12_Pos)             /*!< 0x00001000 */
#define PWR_PDCRC_PC12               PWR_PDCRC_PC12_Msk                        /*!< Port PC12 Pull-Down set */
#define PWR_PDCRC_PC11_Pos           (11U)
#define PWR_PDCRC_PC11_Msk           (0x1UL << PWR_PDCRC_PC11_Pos)             /*!< 0x00000800 */
#define PWR_PDCRC_PC11               PWR_PDCRC_PC11_Msk                        /*!< Port PC11 Pull-Down set */
#define PWR_PDCRC_PC10_Pos           (10U)
#define PWR_PDCRC_PC10_Msk           (0x1UL << PWR_PDCRC_PC10_Pos)             /*!< 0x00000400 */
#define PWR_PDCRC_PC10               PWR_PDCRC_PC10_Msk                        /*!< Port PC10 Pull-Down set */
#define PWR_PDCRC_PC9_Pos            (9U)
#define PWR_PDCRC_PC9_Msk            (0x1UL << PWR_PDCRC_PC9_Pos)              /*!< 0x00000200 */
#define PWR_PDCRC_PC9                PWR_PDCRC_PC9_Msk                         /*!< Port PC9 Pull-Down set  */
#define PWR_PDCRC_PC8_Pos            (8U)
#define PWR_PDCRC_PC8_Msk            (0x1UL << PWR_PDCRC_PC8_Pos)              /*!< 0x00000100 */
#define PWR_PDCRC_PC8                PWR_PDCRC_PC8_Msk                         /*!< Port PC8 Pull-Down set  */
#define PWR_PDCRC_PC7_Pos            (7U)
#define PWR_PDCRC_PC7_Msk            (0x1UL << PWR_PDCRC_PC7_Pos)              /*!< 0x00000080 */
#define PWR_PDCRC_PC7                PWR_PDCRC_PC7_Msk                         /*!< Port PC7 Pull-Down set  */
#define PWR_PDCRC_PC6_Pos            (6U)
#define PWR_PDCRC_PC6_Msk            (0x1UL << PWR_PDCRC_PC6_Pos)              /*!< 0x00000040 */
#define PWR_PDCRC_PC6                PWR_PDCRC_PC6_Msk                         /*!< Port PC6 Pull-Down set  */
#define PWR_PDCRC_PC5_Pos            (5U)
#define PWR_PDCRC_PC5_Msk            (0x1UL << PWR_PDCRC_PC5_Pos)              /*!< 0x00000020 */
#define PWR_PDCRC_PC5                PWR_PDCRC_PC5_Msk                         /*!< Port PC5 Pull-Down set  */
#define PWR_PDCRC_PC4_Pos            (4U)
#define PWR_PDCRC_PC4_Msk            (0x1UL << PWR_PDCRC_PC4_Pos)              /*!< 0x00000010 */
#define PWR_PDCRC_PC4                PWR_PDCRC_PC4_Msk                         /*!< Port PC4 Pull-Down set  */
#define PWR_PDCRC_PC3_Pos            (3U)
#define PWR_PDCRC_PC3_Msk            (0x1UL << PWR_PDCRC_PC3_Pos)              /*!< 0x00000008 */
#define PWR_PDCRC_PC3                PWR_PDCRC_PC3_Msk                         /*!< Port PC3 Pull-Down set  */
#define PWR_PDCRC_PC2_Pos            (2U)
#define PWR_PDCRC_PC2_Msk            (0x1UL << PWR_PDCRC_PC2_Pos)              /*!< 0x00000004 */
#define PWR_PDCRC_PC2                PWR_PDCRC_PC2_Msk                         /*!< Port PC2 Pull-Down set  */
#define PWR_PDCRC_PC1_Pos            (1U)
#define PWR_PDCRC_PC1_Msk            (0x1UL << PWR_PDCRC_PC1_Pos)              /*!< 0x00000002 */
#define PWR_PDCRC_PC1                PWR_PDCRC_PC1_Msk                         /*!< Port PC1 Pull-Down set  */
#define PWR_PDCRC_PC0_Pos            (0U)
#define PWR_PDCRC_PC0_Msk            (0x1UL << PWR_PDCRC_PC0_Pos)              /*!< 0x00000001 */
#define PWR_PDCRC_PC0                PWR_PDCRC_PC0_Msk                         /*!< Port PC0 Pull-Down set  */

/********************  Bit definition for PWR_PUCRD register  ********************/
#define PWR_PUCRD_PD15_Pos           (15U)
#define PWR_PUCRD_PD15_Msk           (0x1UL << PWR_PUCRD_PD15_Pos)             /*!< 0x00008000 */
#define PWR_PUCRD_PD15               PWR_PUCRD_PD15_Msk                        /*!< Port PD15 Pull-Up set */
#define PWR_PUCRD_PD14_Pos           (14U)
#define PWR_PUCRD_PD14_Msk           (0x1UL << PWR_PUCRD_PD14_Pos)             /*!< 0x00004000 */
#define PWR_PUCRD_PD14               PWR_PUCRD_PD14_Msk                        /*!< Port PD14 Pull-Up set */
#define PWR_PUCRD_PD13_Pos           (13U)
#define PWR_PUCRD_PD13_Msk           (0x1UL << PWR_PUCRD_PD13_Pos)             /*!< 0x00002000 */
#define PWR_PUCRD_PD13               PWR_PUCRD_PD13_Msk                        /*!< Port PD13 Pull-Up set */
#define PWR_PUCRD_PD12_Pos           (12U)
#define PWR_PUCRD_PD12_Msk           (0x1UL << PWR_PUCRD_PD12_Pos)             /*!< 0x00001000 */
#define PWR_PUCRD_PD12               PWR_PUCRD_PD12_Msk                        /*!< Port PD12 Pull-Up set */
#define PWR_PUCRD_PD11_Pos           (11U)
#define PWR_PUCRD_PD11_Msk           (0x1UL << PWR_PUCRD_PD11_Pos)             /*!< 0x00000800 */
#define PWR_PUCRD_PD11               PWR_PUCRD_PD11_Msk                        /*!< Port PD11 Pull-Up set */
#define PWR_PUCRD_PD10_Pos           (10U)
#define PWR_PUCRD_PD10_Msk           (0x1UL << PWR_PUCRD_PD10_Pos)             /*!< 0x00000400 */
#define PWR_PUCRD_PD10               PWR_PUCRD_PD10_Msk                        /*!< Port PD10 Pull-Up set */
#define PWR_PUCRD_PD9_Pos            (9U)
#define PWR_PUCRD_PD9_Msk            (0x1UL << PWR_PUCRD_PD9_Pos)              /*!< 0x00000200 */
#define PWR_PUCRD_PD9                PWR_PUCRD_PD9_Msk                         /*!< Port PD9 Pull-Up set  */
#define PWR_PUCRD_PD8_Pos            (8U)
#define PWR_PUCRD_PD8_Msk            (0x1UL << PWR_PUCRD_PD8_Pos)              /*!< 0x00000100 */
#define PWR_PUCRD_PD8                PWR_PUCRD_PD8_Msk                         /*!< Port PD8 Pull-Up set  */
#define PWR_PUCRD_PD7_Pos            (7U)
#define PWR_PUCRD_PD7_Msk            (0x1UL << PWR_PUCRD_PD7_Pos)              /*!< 0x00000080 */
#define PWR_PUCRD_PD7                PWR_PUCRD_PD7_Msk                         /*!< Port PD7 Pull-Up set  */
#define PWR_PUCRD_PD6_Pos            (6U)
#define PWR_PUCRD_PD6_Msk            (0x1UL << PWR_PUCRD_PD6_Pos)              /*!< 0x00000040 */
#define PWR_PUCRD_PD6                PWR_PUCRD_PD6_Msk                         /*!< Port PD6 Pull-Up set  */
#define PWR_PUCRD_PD5_Pos            (5U)
#define PWR_PUCRD_PD5_Msk            (0x1UL << PWR_PUCRD_PD5_Pos)              /*!< 0x00000020 */
#define PWR_PUCRD_PD5                PWR_PUCRD_PD5_Msk                         /*!< Port PD5 Pull-Up set  */
#define PWR_PUCRD_PD4_Pos            (4U)
#define PWR_PUCRD_PD4_Msk            (0x1UL << PWR_PUCRD_PD4_Pos)              /*!< 0x00000010 */
#define PWR_PUCRD_PD4                PWR_PUCRD_PD4_Msk                         /*!< Port PD4 Pull-Up set  */
#define PWR_PUCRD_PD3_Pos            (3U)
#define PWR_PUCRD_PD3_Msk            (0x1UL << PWR_PUCRD_PD3_Pos)              /*!< 0x00000008 */
#define PWR_PUCRD_PD3                PWR_PUCRD_PD3_Msk                         /*!< Port PD3 Pull-Up set  */
#define PWR_PUCRD_PD2_Pos            (2U)
#define PWR_PUCRD_PD2_Msk            (0x1UL << PWR_PUCRD_PD2_Pos)              /*!< 0x00000004 */
#define PWR_PUCRD_PD2                PWR_PUCRD_PD2_Msk                         /*!< Port PD2 Pull-Up set  */
#define PWR_PUCRD_PD1_Pos            (1U)
#define PWR_PUCRD_PD1_Msk            (0x1UL << PWR_PUCRD_PD1_Pos)              /*!< 0x00000002 */
#define PWR_PUCRD_PD1                PWR_PUCRD_PD1_Msk                         /*!< Port PD1 Pull-Up set  */
#define PWR_PUCRD_PD0_Pos            (0U)
#define PWR_PUCRD_PD0_Msk            (0x1UL << PWR_PUCRD_PD0_Pos)              /*!< 0x00000001 */
#define PWR_PUCRD_PD0                PWR_PUCRD_PD0_Msk                         /*!< Port PD0 Pull-Up set  */

/********************  Bit definition for PWR_PDCRD register  ********************/
#define PWR_PDCRD_PD15_Pos           (15U)
#define PWR_PDCRD_PD15_Msk           (0x1UL << PWR_PDCRD_PD15_Pos)             /*!< 0x00008000 */
#define PWR_PDCRD_PD15               PWR_PDCRD_PD15_Msk                        /*!< Port PD15 Pull-Down set */
#define PWR_PDCRD_PD14_Pos           (14U)
#define PWR_PDCRD_PD14_Msk           (0x1UL << PWR_PDCRD_PD14_Pos)             /*!< 0x00004000 */
#define PWR_PDCRD_PD14               PWR_PDCRD_PD14_Msk                        /*!< Port PD14 Pull-Down set */
#define PWR_PDCRD_PD13_Pos           (13U)
#define PWR_PDCRD_PD13_Msk           (0x1UL << PWR_PDCRD_PD13_Pos)             /*!< 0x00002000 */
#define PWR_PDCRD_PD13               PWR_PDCRD_PD13_Msk                        /*!< Port PD13 Pull-Down set */
#define PWR_PDCRD_PD12_Pos           (12U)
#define PWR_PDCRD_PD12_Msk           (0x1UL << PWR_PDCRD_PD12_Pos)             /*!< 0x00001000 */
#define PWR_PDCRD_PD12               PWR_PDCRD_PD12_Msk                        /*!< Port PD12 Pull-Down set */
#define PWR_PDCRD_PD11_Pos           (11U)
#define PWR_PDCRD_PD11_Msk           (0x1UL << PWR_PDCRD_PD11_Pos)             /*!< 0x00000800 */
#define PWR_PDCRD_PD11               PWR_PDCRD_PD11_Msk                        /*!< Port PD11 Pull-Down set */
#define PWR_PDCRD_PD10_Pos           (10U)
#define PWR_PDCRD_PD10_Msk           (0x1UL << PWR_PDCRD_PD10_Pos)             /*!< 0x00000400 */
#define PWR_PDCRD_PD10               PWR_PDCRD_PD10_Msk                        /*!< Port PD10 Pull-Down set */
#define PWR_PDCRD_PD9_Pos            (9U)
#define PWR_PDCRD_PD9_Msk            (0x1UL << PWR_PDCRD_PD9_Pos)              /*!< 0x00000200 */
#define PWR_PDCRD_PD9                PWR_PDCRD_PD9_Msk                         /*!< Port PD9 Pull-Down set  */
#define PWR_PDCRD_PD8_Pos            (8U)
#define PWR_PDCRD_PD8_Msk            (0x1UL << PWR_PDCRD_PD8_Pos)              /*!< 0x00000100 */
#define PWR_PDCRD_PD8                PWR_PDCRD_PD8_Msk                         /*!< Port PD8 Pull-Down set  */
#define PWR_PDCRD_PD7_Pos            (7U)
#define PWR_PDCRD_PD7_Msk            (0x1UL << PWR_PDCRD_PD7_Pos)              /*!< 0x00000080 */
#define PWR_PDCRD_PD7                PWR_PDCRD_PD7_Msk                         /*!< Port PD7 Pull-Down set  */
#define PWR_PDCRD_PD6_Pos            (6U)
#define PWR_PDCRD_PD6_Msk            (0x1UL << PWR_PDCRD_PD6_Pos)              /*!< 0x00000040 */
#define PWR_PDCRD_PD6                PWR_PDCRD_PD6_Msk                         /*!< Port PD6 Pull-Down set  */
#define PWR_PDCRD_PD5_Pos            (5U)
#define PWR_PDCRD_PD5_Msk            (0x1UL << PWR_PDCRD_PD5_Pos)              /*!< 0x00000020 */
#define PWR_PDCRD_PD5                PWR_PDCRD_PD5_Msk                         /*!< Port PD5 Pull-Down set  */
#define PWR_PDCRD_PD4_Pos            (4U)
#define PWR_PDCRD_PD4_Msk            (0x1UL << PWR_PDCRD_PD4_Pos)              /*!< 0x00000010 */
#define PWR_PDCRD_PD4                PWR_PDCRD_PD4_Msk                         /*!< Port PD4 Pull-Down set  */
#define PWR_PDCRD_PD3_Pos            (3U)
#define PWR_PDCRD_PD3_Msk            (0x1UL << PWR_PDCRD_PD3_Pos)              /*!< 0x00000008 */
#define PWR_PDCRD_PD3                PWR_PDCRD_PD3_Msk                         /*!< Port PD3 Pull-Down set  */
#define PWR_PDCRD_PD2_Pos            (2U)
#define PWR_PDCRD_PD2_Msk            (0x1UL << PWR_PDCRD_PD2_Pos)              /*!< 0x00000004 */
#define PWR_PDCRD_PD2                PWR_PDCRD_PD2_Msk                         /*!< Port PD2 Pull-Down set  */
#define PWR_PDCRD_PD1_Pos            (1U)
#define PWR_PDCRD_PD1_Msk            (0x1UL << PWR_PDCRD_PD1_Pos)              /*!< 0x00000002 */
#define PWR_PDCRD_PD1                PWR_PDCRD_PD1_Msk                         /*!< Port PD1 Pull-Down set  */
#define PWR_PDCRD_PD0_Pos            (0U)
#define PWR_PDCRD_PD0_Msk            (0x1UL << PWR_PDCRD_PD0_Pos)              /*!< 0x00000001 */
#define PWR_PDCRD_PD0                PWR_PDCRD_PD0_Msk                         /*!< Port PD0 Pull-Down set  */

/********************  Bit definition for PWR_PUCRE register  ********************/
#define PWR_PUCRE_PE15_Pos           (15U)
#define PWR_PUCRE_PE15_Msk           (0x1UL << PWR_PUCRE_PE15_Pos)             /*!< 0x00008000 */
#define PWR_PUCRE_PE15               PWR_PUCRE_PE15_Msk                        /*!< Port PE15 Pull-Up set */
#define PWR_PUCRE_PE14_Pos           (14U)
#define PWR_PUCRE_PE14_Msk           (0x1UL << PWR_PUCRE_PE14_Pos)             /*!< 0x00004000 */
#define PWR_PUCRE_PE14               PWR_PUCRE_PE14_Msk                        /*!< Port PE14 Pull-Up set */
#define PWR_PUCRE_PE13_Pos           (13U)
#define PWR_PUCRE_PE13_Msk           (0x1UL << PWR_PUCRE_PE13_Pos)             /*!< 0x00002000 */
#define PWR_PUCRE_PE13               PWR_PUCRE_PE13_Msk                        /*!< Port PE13 Pull-Up set */
#define PWR_PUCRE_PE12_Pos           (12U)
#define PWR_PUCRE_PE12_Msk           (0x1UL << PWR_PUCRE_PE12_Pos)             /*!< 0x00001000 */
#define PWR_PUCRE_PE12               PWR_PUCRE_PE12_Msk                        /*!< Port PE12 Pull-Up set */
#define PWR_PUCRE_PE11_Pos           (11U)
#define PWR_PUCRE_PE11_Msk           (0x1UL << PWR_PUCRE_PE11_Pos)             /*!< 0x00000800 */
#define PWR_PUCRE_PE11               PWR_PUCRE_PE11_Msk                        /*!< Port PE11 Pull-Up set */
#define PWR_PUCRE_PE10_Pos           (10U)
#define PWR_PUCRE_PE10_Msk           (0x1UL << PWR_PUCRE_PE10_Pos)             /*!< 0x00000400 */
#define PWR_PUCRE_PE10               PWR_PUCRE_PE10_Msk                        /*!< Port PE10 Pull-Up set */
#define PWR_PUCRE_PE9_Pos            (9U)
#define PWR_PUCRE_PE9_Msk            (0x1UL << PWR_PUCRE_PE9_Pos)              /*!< 0x00000200 */
#define PWR_PUCRE_PE9                PWR_PUCRE_PE9_Msk                         /*!< Port PE9 Pull-Up set  */
#define PWR_PUCRE_PE8_Pos            (8U)
#define PWR_PUCRE_PE8_Msk            (0x1UL << PWR_PUCRE_PE8_Pos)              /*!< 0x00000100 */
#define PWR_PUCRE_PE8                PWR_PUCRE_PE8_Msk                         /*!< Port PE8 Pull-Up set  */
#define PWR_PUCRE_PE7_Pos            (7U)
#define PWR_PUCRE_PE7_Msk            (0x1UL << PWR_PUCRE_PE7_Pos)              /*!< 0x00000080 */
#define PWR_PUCRE_PE7                PWR_PUCRE_PE7_Msk                         /*!< Port PE7 Pull-Up set  */
#define PWR_PUCRE_PE6_Pos            (6U)
#define PWR_PUCRE_PE6_Msk            (0x1UL << PWR_PUCRE_PE6_Pos)              /*!< 0x00000040 */
#define PWR_PUCRE_PE6                PWR_PUCRE_PE6_Msk                         /*!< Port PE6 Pull-Up set  */
#define PWR_PUCRE_PE5_Pos            (5U)
#define PWR_PUCRE_PE5_Msk            (0x1UL << PWR_PUCRE_PE5_Pos)              /*!< 0x00000020 */
#define PWR_PUCRE_PE5                PWR_PUCRE_PE5_Msk                         /*!< Port PE5 Pull-Up set  */
#define PWR_PUCRE_PE4_Pos            (4U)
#define PWR_PUCRE_PE4_Msk            (0x1UL << PWR_PUCRE_PE4_Pos)              /*!< 0x00000010 */
#define PWR_PUCRE_PE4                PWR_PUCRE_PE4_Msk                         /*!< Port PE4 Pull-Up set  */
#define PWR_PUCRE_PE3_Pos            (3U)
#define PWR_PUCRE_PE3_Msk            (0x1UL << PWR_PUCRE_PE3_Pos)              /*!< 0x00000008 */
#define PWR_PUCRE_PE3                PWR_PUCRE_PE3_Msk                         /*!< Port PE3 Pull-Up set  */
#define PWR_PUCRE_PE2_Pos            (2U)
#define PWR_PUCRE_PE2_Msk            (0x1UL << PWR_PUCRE_PE2_Pos)              /*!< 0x00000004 */
#define PWR_PUCRE_PE2                PWR_PUCRE_PE2_Msk                         /*!< Port PE2 Pull-Up set  */
#define PWR_PUCRE_PE1_Pos            (1U)
#define PWR_PUCRE_PE1_Msk            (0x1UL << PWR_PUCRE_PE1_Pos)              /*!< 0x00000002 */
#define PWR_PUCRE_PE1                PWR_PUCRE_PE1_Msk                         /*!< Port PE1 Pull-Up set  */
#define PWR_PUCRE_PE0_Pos            (0U)
#define PWR_PUCRE_PE0_Msk            (0x1UL << PWR_PUCRE_PE0_Pos)              /*!< 0x00000001 */
#define PWR_PUCRE_PE0                PWR_PUCRE_PE0_Msk                         /*!< Port PE0 Pull-Up set  */

/********************  Bit definition for PWR_PDCRE register  ********************/
#define PWR_PDCRE_PE15_Pos           (15U)
#define PWR_PDCRE_PE15_Msk           (0x1UL << PWR_PDCRE_PE15_Pos)             /*!< 0x00008000 */
#define PWR_PDCRE_PE15               PWR_PDCRE_PE15_Msk                        /*!< Port PE15 Pull-Down set */
#define PWR_PDCRE_PE14_Pos           (14U)
#define PWR_PDCRE_PE14_Msk           (0x1UL << PWR_PDCRE_PE14_Pos)             /*!< 0x00004000 */
#define PWR_PDCRE_PE14               PWR_PDCRE_PE14_Msk                        /*!< Port PE14 Pull-Down set */
#define PWR_PDCRE_PE13_Pos           (13U)
#define PWR_PDCRE_PE13_Msk           (0x1UL << PWR_PDCRE_PE13_Pos)             /*!< 0x00002000 */
#define PWR_PDCRE_PE13               PWR_PDCRE_PE13_Msk                        /*!< Port PE13 Pull-Down set */
#define PWR_PDCRE_PE12_Pos           (12U)
#define PWR_PDCRE_PE12_Msk           (0x1UL << PWR_PDCRE_PE12_Pos)             /*!< 0x00001000 */
#define PWR_PDCRE_PE12               PWR_PDCRE_PE12_Msk                        /*!< Port PE12 Pull-Down set */
#define PWR_PDCRE_PE11_Pos           (11U)
#define PWR_PDCRE_PE11_Msk           (0x1UL << PWR_PDCRE_PE11_Pos)             /*!< 0x00000800 */
#define PWR_PDCRE_PE11               PWR_PDCRE_PE11_Msk                        /*!< Port PE11 Pull-Down set */
#define PWR_PDCRE_PE10_Pos           (10U)
#define PWR_PDCRE_PE10_Msk           (0x1UL << PWR_PDCRE_PE10_Pos)             /*!< 0x00000400 */
#define PWR_PDCRE_PE10               PWR_PDCRE_PE10_Msk                        /*!< Port PE10 Pull-Down set */
#define PWR_PDCRE_PE9_Pos            (9U)
#define PWR_PDCRE_PE9_Msk            (0x1UL << PWR_PDCRE_PE9_Pos)              /*!< 0x00000200 */
#define PWR_PDCRE_PE9                PWR_PDCRE_PE9_Msk                         /*!< Port PE9 Pull-Down set  */
#define PWR_PDCRE_PE8_Pos            (8U)
#define PWR_PDCRE_PE8_Msk            (0x1UL << PWR_PDCRE_PE8_Pos)              /*!< 0x00000100 */
#define PWR_PDCRE_PE8                PWR_PDCRE_PE8_Msk                         /*!< Port PE8 Pull-Down set  */
#define PWR_PDCRE_PE7_Pos            (7U)
#define PWR_PDCRE_PE7_Msk            (0x1UL << PWR_PDCRE_PE7_Pos)              /*!< 0x00000080 */
#define PWR_PDCRE_PE7                PWR_PDCRE_PE7_Msk                         /*!< Port PE7 Pull-Down set  */
#define PWR_PDCRE_PE6_Pos            (6U)
#define PWR_PDCRE_PE6_Msk            (0x1UL << PWR_PDCRE_PE6_Pos)              /*!< 0x00000040 */
#define PWR_PDCRE_PE6                PWR_PDCRE_PE6_Msk                         /*!< Port PE6 Pull-Down set  */
#define PWR_PDCRE_PE5_Pos            (5U)
#define PWR_PDCRE_PE5_Msk            (0x1UL << PWR_PDCRE_PE5_Pos)              /*!< 0x00000020 */
#define PWR_PDCRE_PE5                PWR_PDCRE_PE5_Msk                         /*!< Port PE5 Pull-Down set  */
#define PWR_PDCRE_PE4_Pos            (4U)
#define PWR_PDCRE_PE4_Msk            (0x1UL << PWR_PDCRE_PE4_Pos)              /*!< 0x00000010 */
#define PWR_PDCRE_PE4                PWR_PDCRE_PE4_Msk                         /*!< Port PE4 Pull-Down set  */
#define PWR_PDCRE_PE3_Pos            (3U)
#define PWR_PDCRE_PE3_Msk            (0x1UL << PWR_PDCRE_PE3_Pos)              /*!< 0x00000008 */
#define PWR_PDCRE_PE3                PWR_PDCRE_PE3_Msk                         /*!< Port PE3 Pull-Down set  */
#define PWR_PDCRE_PE2_Pos            (2U)
#define PWR_PDCRE_PE2_Msk            (0x1UL << PWR_PDCRE_PE2_Pos)              /*!< 0x00000004 */
#define PWR_PDCRE_PE2                PWR_PDCRE_PE2_Msk                         /*!< Port PE2 Pull-Down set  */
#define PWR_PDCRE_PE1_Pos            (1U)
#define PWR_PDCRE_PE1_Msk            (0x1UL << PWR_PDCRE_PE1_Pos)              /*!< 0x00000002 */
#define PWR_PDCRE_PE1                PWR_PDCRE_PE1_Msk                         /*!< Port PE1 Pull-Down set  */
#define PWR_PDCRE_PE0_Pos            (0U)
#define PWR_PDCRE_PE0_Msk            (0x1UL << PWR_PDCRE_PE0_Pos)              /*!< 0x00000001 */
#define PWR_PDCRE_PE0                PWR_PDCRE_PE0_Msk                         /*!< Port PE0 Pull-Down set  */

/********************  Bit definition for PWR_PUCRF register  ********************/
#define PWR_PUCRF_PF15_Pos           (15U)
#define PWR_PUCRF_PF15_Msk           (0x1UL << PWR_PUCRF_PF15_Pos)             /*!< 0x00008000 */
#define PWR_PUCRF_PF15               PWR_PUCRF_PF15_Msk                        /*!< Port PF15 Pull-Up set */
#define PWR_PUCRF_PF14_Pos           (14U)
#define PWR_PUCRF_PF14_Msk           (0x1UL << PWR_PUCRF_PF14_Pos)             /*!< 0x00004000 */
#define PWR_PUCRF_PF14               PWR_PUCRF_PF14_Msk                        /*!< Port PF14 Pull-Up set */
#define PWR_PUCRF_PF13_Pos           (13U)
#define PWR_PUCRF_PF13_Msk           (0x1UL << PWR_PUCRF_PF13_Pos)             /*!< 0x00002000 */
#define PWR_PUCRF_PF13               PWR_PUCRF_PF13_Msk                        /*!< Port PF13 Pull-Up set */
#define PWR_PUCRF_PF12_Pos           (12U)
#define PWR_PUCRF_PF12_Msk           (0x1UL << PWR_PUCRF_PF12_Pos)             /*!< 0x00001000 */
#define PWR_PUCRF_PF12               PWR_PUCRF_PF12_Msk                        /*!< Port PF12 Pull-Up set */
#define PWR_PUCRF_PF11_Pos           (11U)
#define PWR_PUCRF_PF11_Msk           (0x1UL << PWR_PUCRF_PF11_Pos)             /*!< 0x00000800 */
#define PWR_PUCRF_PF11               PWR_PUCRF_PF11_Msk                        /*!< Port PF11 Pull-Up set */
#define PWR_PUCRF_PF10_Pos           (10U)
#define PWR_PUCRF_PF10_Msk           (0x1UL << PWR_PUCRF_PF10_Pos)             /*!< 0x00000400 */
#define PWR_PUCRF_PF10               PWR_PUCRF_PF10_Msk                        /*!< Port PF10 Pull-Up set */
#define PWR_PUCRF_PF9_Pos            (9U)
#define PWR_PUCRF_PF9_Msk            (0x1UL << PWR_PUCRF_PF9_Pos)              /*!< 0x00000200 */
#define PWR_PUCRF_PF9                PWR_PUCRF_PF9_Msk                         /*!< Port PF9 Pull-Up set  */
#define PWR_PUCRF_PF8_Pos            (8U)
#define PWR_PUCRF_PF8_Msk            (0x1UL << PWR_PUCRF_PF8_Pos)              /*!< 0x00000100 */
#define PWR_PUCRF_PF8                PWR_PUCRF_PF8_Msk                         /*!< Port PF8 Pull-Up set  */
#define PWR_PUCRF_PF7_Pos            (7U)
#define PWR_PUCRF_PF7_Msk            (0x1UL << PWR_PUCRF_PF7_Pos)              /*!< 0x00000080 */
#define PWR_PUCRF_PF7                PWR_PUCRF_PF7_Msk                         /*!< Port PF7 Pull-Up set  */
#define PWR_PUCRF_PF6_Pos            (6U)
#define PWR_PUCRF_PF6_Msk            (0x1UL << PWR_PUCRF_PF6_Pos)              /*!< 0x00000040 */
#define PWR_PUCRF_PF6                PWR_PUCRF_PF6_Msk                         /*!< Port PF6 Pull-Up set  */
#define PWR_PUCRF_PF5_Pos            (5U)
#define PWR_PUCRF_PF5_Msk            (0x1UL << PWR_PUCRF_PF5_Pos)              /*!< 0x00000020 */
#define PWR_PUCRF_PF5                PWR_PUCRF_PF5_Msk                         /*!< Port PF5 Pull-Up set  */
#define PWR_PUCRF_PF4_Pos            (4U)
#define PWR_PUCRF_PF4_Msk            (0x1UL << PWR_PUCRF_PF4_Pos)              /*!< 0x00000010 */
#define PWR_PUCRF_PF4                PWR_PUCRF_PF4_Msk                         /*!< Port PF4 Pull-Up set  */
#define PWR_PUCRF_PF3_Pos            (3U)
#define PWR_PUCRF_PF3_Msk            (0x1UL << PWR_PUCRF_PF3_Pos)              /*!< 0x00000008 */
#define PWR_PUCRF_PF3                PWR_PUCRF_PF3_Msk                         /*!< Port PF3 Pull-Up set  */
#define PWR_PUCRF_PF2_Pos            (2U)
#define PWR_PUCRF_PF2_Msk            (0x1UL << PWR_PUCRF_PF2_Pos)              /*!< 0x00000004 */
#define PWR_PUCRF_PF2                PWR_PUCRF_PF2_Msk                         /*!< Port PF2 Pull-Up set  */
#define PWR_PUCRF_PF1_Pos            (1U)
#define PWR_PUCRF_PF1_Msk            (0x1UL << PWR_PUCRF_PF1_Pos)              /*!< 0x00000002 */
#define PWR_PUCRF_PF1                PWR_PUCRF_PF1_Msk                         /*!< Port PF1 Pull-Up set  */
#define PWR_PUCRF_PF0_Pos            (0U)
#define PWR_PUCRF_PF0_Msk            (0x1UL << PWR_PUCRF_PF0_Pos)              /*!< 0x00000001 */
#define PWR_PUCRF_PF0                PWR_PUCRF_PF0_Msk                         /*!< Port PF0 Pull-Up set  */

/********************  Bit definition for PWR_PDCRF register  ********************/
#define PWR_PDCRF_PF15_Pos           (15U)
#define PWR_PDCRF_PF15_Msk           (0x1UL << PWR_PDCRF_PF15_Pos)             /*!< 0x00008000 */
#define PWR_PDCRF_PF15               PWR_PDCRF_PF15_Msk                        /*!< Port PF15 Pull-Down set */
#define PWR_PDCRF_PF14_Pos           (14U)
#define PWR_PDCRF_PF14_Msk           (0x1UL << PWR_PDCRF_PF14_Pos)             /*!< 0x00004000 */
#define PWR_PDCRF_PF14               PWR_PDCRF_PF14_Msk                        /*!< Port PF14 Pull-Down set */
#define PWR_PDCRF_PF13_Pos           (13U)
#define PWR_PDCRF_PF13_Msk           (0x1UL << PWR_PDCRF_PF13_Pos)             /*!< 0x00002000 */
#define PWR_PDCRF_PF13               PWR_PDCRF_PF13_Msk                        /*!< Port PF13 Pull-Down set */
#define PWR_PDCRF_PF12_Pos           (12U)
#define PWR_PDCRF_PF12_Msk           (0x1UL << PWR_PDCRF_PF12_Pos)             /*!< 0x00001000 */
#define PWR_PDCRF_PF12               PWR_PDCRF_PF12_Msk                        /*!< Port PF12 Pull-Down set */
#define PWR_PDCRF_PF11_Pos           (11U)
#define PWR_PDCRF_PF11_Msk           (0x1UL << PWR_PDCRF_PF11_Pos)             /*!< 0x00000800 */
#define PWR_PDCRF_PF11               PWR_PDCRF_PF11_Msk                        /*!< Port PF11 Pull-Down set */
#define PWR_PDCRF_PF10_Pos           (10U)
#define PWR_PDCRF_PF10_Msk           (0x1UL << PWR_PDCRF_PF10_Pos)             /*!< 0x00000400 */
#define PWR_PDCRF_PF10               PWR_PDCRF_PF10_Msk                        /*!< Port PF10 Pull-Down set */
#define PWR_PDCRF_PF9_Pos            (9U)
#define PWR_PDCRF_PF9_Msk            (0x1UL << PWR_PDCRF_PF9_Pos)              /*!< 0x00000200 */
#define PWR_PDCRF_PF9                PWR_PDCRF_PF9_Msk                         /*!< Port PF9 Pull-Down set  */
#define PWR_PDCRF_PF8_Pos            (8U)
#define PWR_PDCRF_PF8_Msk            (0x1UL << PWR_PDCRF_PF8_Pos)              /*!< 0x00000100 */
#define PWR_PDCRF_PF8                PWR_PDCRF_PF8_Msk                         /*!< Port PF8 Pull-Down set  */
#define PWR_PDCRF_PF7_Pos            (7U)
#define PWR_PDCRF_PF7_Msk            (0x1UL << PWR_PDCRF_PF7_Pos)              /*!< 0x00000080 */
#define PWR_PDCRF_PF7                PWR_PDCRF_PF7_Msk                         /*!< Port PF7 Pull-Down set  */
#define PWR_PDCRF_PF6_Pos            (6U)
#define PWR_PDCRF_PF6_Msk            (0x1UL << PWR_PDCRF_PF6_Pos)              /*!< 0x00000040 */
#define PWR_PDCRF_PF6                PWR_PDCRF_PF6_Msk                         /*!< Port PF6 Pull-Down set  */
#define PWR_PDCRF_PF5_Pos            (5U)
#define PWR_PDCRF_PF5_Msk            (0x1UL << PWR_PDCRF_PF5_Pos)              /*!< 0x00000020 */
#define PWR_PDCRF_PF5                PWR_PDCRF_PF5_Msk                         /*!< Port PF5 Pull-Down set  */
#define PWR_PDCRF_PF4_Pos            (4U)
#define PWR_PDCRF_PF4_Msk            (0x1UL << PWR_PDCRF_PF4_Pos)              /*!< 0x00000010 */
#define PWR_PDCRF_PF4                PWR_PDCRF_PF4_Msk                         /*!< Port PF4 Pull-Down set  */
#define PWR_PDCRF_PF3_Pos            (3U)
#define PWR_PDCRF_PF3_Msk            (0x1UL << PWR_PDCRF_PF3_Pos)              /*!< 0x00000008 */
#define PWR_PDCRF_PF3                PWR_PDCRF_PF3_Msk                         /*!< Port PF3 Pull-Down set  */
#define PWR_PDCRF_PF2_Pos            (2U)
#define PWR_PDCRF_PF2_Msk            (0x1UL << PWR_PDCRF_PF2_Pos)              /*!< 0x00000004 */
#define PWR_PDCRF_PF2                PWR_PDCRF_PF2_Msk                         /*!< Port PF2 Pull-Down set  */
#define PWR_PDCRF_PF1_Pos            (1U)
#define PWR_PDCRF_PF1_Msk            (0x1UL << PWR_PDCRF_PF1_Pos)              /*!< 0x00000002 */
#define PWR_PDCRF_PF1                PWR_PDCRF_PF1_Msk                         /*!< Port PF1 Pull-Down set  */
#define PWR_PDCRF_PF0_Pos            (0U)
#define PWR_PDCRF_PF0_Msk            (0x1UL << PWR_PDCRF_PF0_Pos)              /*!< 0x00000001 */
#define PWR_PDCRF_PF0                PWR_PDCRF_PF0_Msk                         /*!< Port PF0 Pull-Down set  */

/********************  Bit definition for PWR_PUCRG register  ********************/
#define PWR_PUCRG_PG15_Pos           (15U)
#define PWR_PUCRG_PG15_Msk           (0x1UL << PWR_PUCRG_PG15_Pos)             /*!< 0x00008000 */
#define PWR_PUCRG_PG15               PWR_PUCRG_PG15_Msk                        /*!< Port PG15 Pull-Up set */
#define PWR_PUCRG_PG14_Pos           (14U)
#define PWR_PUCRG_PG14_Msk           (0x1UL << PWR_PUCRG_PG14_Pos)             /*!< 0x00004000 */
#define PWR_PUCRG_PG14               PWR_PUCRG_PG14_Msk                        /*!< Port PG14 Pull-Up set */
#define PWR_PUCRG_PG13_Pos           (13U)
#define PWR_PUCRG_PG13_Msk           (0x1UL << PWR_PUCRG_PG13_Pos)             /*!< 0x00002000 */
#define PWR_PUCRG_PG13               PWR_PUCRG_PG13_Msk                        /*!< Port PG13 Pull-Up set */
#define PWR_PUCRG_PG12_Pos           (12U)
#define PWR_PUCRG_PG12_Msk           (0x1UL << PWR_PUCRG_PG12_Pos)             /*!< 0x00001000 */
#define PWR_PUCRG_PG12               PWR_PUCRG_PG12_Msk                        /*!< Port PG12 Pull-Up set */
#define PWR_PUCRG_PG11_Pos           (11U)
#define PWR_PUCRG_PG11_Msk           (0x1UL << PWR_PUCRG_PG11_Pos)             /*!< 0x00000800 */
#define PWR_PUCRG_PG11               PWR_PUCRG_PG11_Msk                        /*!< Port PG11 Pull-Up set */
#define PWR_PUCRG_PG10_Pos           (10U)
#define PWR_PUCRG_PG10_Msk           (0x1UL << PWR_PUCRG_PG10_Pos)             /*!< 0x00000400 */
#define PWR_PUCRG_PG10               PWR_PUCRG_PG10_Msk                        /*!< Port PG10 Pull-Up set */
#define PWR_PUCRG_PG9_Pos            (9U)
#define PWR_PUCRG_PG9_Msk            (0x1UL << PWR_PUCRG_PG9_Pos)              /*!< 0x00000200 */
#define PWR_PUCRG_PG9                PWR_PUCRG_PG9_Msk                         /*!< Port PG9 Pull-Up set  */
#define PWR_PUCRG_PG8_Pos            (8U)
#define PWR_PUCRG_PG8_Msk            (0x1UL << PWR_PUCRG_PG8_Pos)              /*!< 0x00000100 */
#define PWR_PUCRG_PG8                PWR_PUCRG_PG8_Msk                         /*!< Port PG8 Pull-Up set  */
#define PWR_PUCRG_PG7_Pos            (7U)
#define PWR_PUCRG_PG7_Msk            (0x1UL << PWR_PUCRG_PG7_Pos)              /*!< 0x00000080 */
#define PWR_PUCRG_PG7                PWR_PUCRG_PG7_Msk                         /*!< Port PG7 Pull-Up set  */
#define PWR_PUCRG_PG6_Pos            (6U)
#define PWR_PUCRG_PG6_Msk            (0x1UL << PWR_PUCRG_PG6_Pos)              /*!< 0x00000040 */
#define PWR_PUCRG_PG6                PWR_PUCRG_PG6_Msk                         /*!< Port PG6 Pull-Up set  */
#define PWR_PUCRG_PG5_Pos            (5U)
#define PWR_PUCRG_PG5_Msk            (0x1UL << PWR_PUCRG_PG5_Pos)              /*!< 0x00000020 */
#define PWR_PUCRG_PG5                PWR_PUCRG_PG5_Msk                         /*!< Port PG5 Pull-Up set  */
#define PWR_PUCRG_PG4_Pos            (4U)
#define PWR_PUCRG_PG4_Msk            (0x1UL << PWR_PUCRG_PG4_Pos)              /*!< 0x00000010 */
#define PWR_PUCRG_PG4                PWR_PUCRG_PG4_Msk                         /*!< Port PG4 Pull-Up set  */
#define PWR_PUCRG_PG3_Pos            (3U)
#define PWR_PUCRG_PG3_Msk            (0x1UL << PWR_PUCRG_PG3_Pos)              /*!< 0x00000008 */
#define PWR_PUCRG_PG3                PWR_PUCRG_PG3_Msk                         /*!< Port PG3 Pull-Up set  */
#define PWR_PUCRG_PG2_Pos            (2U)
#define PWR_PUCRG_PG2_Msk            (0x1UL << PWR_PUCRG_PG2_Pos)              /*!< 0x00000004 */
#define PWR_PUCRG_PG2                PWR_PUCRG_PG2_Msk                         /*!< Port PG2 Pull-Up set  */
#define PWR_PUCRG_PG1_Pos            (1U)
#define PWR_PUCRG_PG1_Msk            (0x1UL << PWR_PUCRG_PG1_Pos)              /*!< 0x00000002 */
#define PWR_PUCRG_PG1                PWR_PUCRG_PG1_Msk                         /*!< Port PG1 Pull-Up set  */
#define PWR_PUCRG_PG0_Pos            (0U)
#define PWR_PUCRG_PG0_Msk            (0x1UL << PWR_PUCRG_PG0_Pos)              /*!< 0x00000001 */
#define PWR_PUCRG_PG0                PWR_PUCRG_PG0_Msk                         /*!< Port PG0 Pull-Up set  */

/********************  Bit definition for PWR_PDCRG register  ********************/
#define PWR_PDCRG_PG10_Pos           (10U)
#define PWR_PDCRG_PG10_Msk           (0x1UL << PWR_PDCRG_PG10_Pos)             /*!< 0x00000400 */
#define PWR_PDCRG_PG10               PWR_PDCRG_PG10_Msk                        /*!< Port PG10 Pull-Down set */
#define PWR_PDCRG_PG9_Pos            (9U)
#define PWR_PDCRG_PG9_Msk            (0x1UL << PWR_PDCRG_PG9_Pos)              /*!< 0x00000200 */
#define PWR_PDCRG_PG9                PWR_PDCRG_PG9_Msk                         /*!< Port PG9 Pull-Down set  */
#define PWR_PDCRG_PG8_Pos            (8U)
#define PWR_PDCRG_PG8_Msk            (0x1UL << PWR_PDCRG_PG8_Pos)              /*!< 0x00000100 */
#define PWR_PDCRG_PG8                PWR_PDCRG_PG8_Msk                         /*!< Port PG8 Pull-Down set  */
#define PWR_PDCRG_PG7_Pos            (7U)
#define PWR_PDCRG_PG7_Msk            (0x1UL << PWR_PDCRG_PG7_Pos)              /*!< 0x00000080 */
#define PWR_PDCRG_PG7                PWR_PDCRG_PG7_Msk                         /*!< Port PG7 Pull-Down set  */
#define PWR_PDCRG_PG6_Pos            (6U)
#define PWR_PDCRG_PG6_Msk            (0x1UL << PWR_PDCRG_PG6_Pos)              /*!< 0x00000040 */
#define PWR_PDCRG_PG6                PWR_PDCRG_PG6_Msk                         /*!< Port PG6 Pull-Down set  */
#define PWR_PDCRG_PG5_Pos            (5U)
#define PWR_PDCRG_PG5_Msk            (0x1UL << PWR_PDCRG_PG5_Pos)              /*!< 0x00000020 */
#define PWR_PDCRG_PG5                PWR_PDCRG_PG5_Msk                         /*!< Port PG5 Pull-Down set  */
#define PWR_PDCRG_PG4_Pos            (4U)
#define PWR_PDCRG_PG4_Msk            (0x1UL << PWR_PDCRG_PG4_Pos)              /*!< 0x00000010 */
#define PWR_PDCRG_PG4                PWR_PDCRG_PG4_Msk                         /*!< Port PG4 Pull-Down set  */
#define PWR_PDCRG_PG3_Pos            (3U)
#define PWR_PDCRG_PG3_Msk            (0x1UL << PWR_PDCRG_PG3_Pos)              /*!< 0x00000008 */
#define PWR_PDCRG_PG3                PWR_PDCRG_PG3_Msk                         /*!< Port PG3 Pull-Down set  */
#define PWR_PDCRG_PG2_Pos            (2U)
#define PWR_PDCRG_PG2_Msk            (0x1UL << PWR_PDCRG_PG2_Pos)              /*!< 0x00000004 */
#define PWR_PDCRG_PG2                PWR_PDCRG_PG2_Msk                         /*!< Port PG2 Pull-Down set  */
#define PWR_PDCRG_PG1_Pos            (1U)
#define PWR_PDCRG_PG1_Msk            (0x1UL << PWR_PDCRG_PG1_Pos)              /*!< 0x00000002 */
#define PWR_PDCRG_PG1                PWR_PDCRG_PG1_Msk                         /*!< Port PG1 Pull-Down set  */
#define PWR_PDCRG_PG0_Pos            (0U)
#define PWR_PDCRG_PG0_Msk            (0x1UL << PWR_PDCRG_PG0_Pos)              /*!< 0x00000001 */
#define PWR_PDCRG_PG0                PWR_PDCRG_PG0_Msk                         /*!< Port PG0 Pull-Down set  */

/********************  Bit definition for PWR_CR5 register  ********************/
#define PWR_CR5_R1MODE_Pos           (8U)
#define PWR_CR5_R1MODE_Msk           (0x1U << PWR_CR5_R1MODE_Pos)              /*!< 0x00000100 */
#define PWR_CR5_R1MODE               PWR_CR5_R1MODE_Msk                        /*!< selection for Main Regulator in Range1 */


// 레지스터 목록
namespace RCC_REG
{
enum
{
	CR = 0,			ICSCR,			CFGR,			PLLCFGR,		
					CIER = 6,		CIFR,			CICR,			
	AHB1RSTR = 10,	AHB2RSTR,		AHB3RSTR,						APB1RSTR1 = 14,	
	APB1RSTR2,		APB2RSTR,						AHB1ENR = 18,	AHB2ENR,		
	AHB3ENR,						APB1ENR1 = 22,	APB1ENR2,		APB2ENR,		
					AHB1SMENR = 26,	AHB2SMENR,		AHB3SMENR,
	APB1SMENR1 = 30,APB1SMENR2,		APB2SMENR,						CCIPR = 35,	
					BDCR = 36,		CSR,			CRRCR,			CCIPR2
};
}

namespace PWR_REG
{
enum
{
	CR1 = 0,		CR2,			CR3,			CR4,			SR1,
	SR2,			SCR,							PUCRA = 8,		PDCRA,			
	PUCRB,			PDCRB,			PUCRC,			PDCRC,			PUCRD,
	PDCRD,			PUCRE,			PDCRE,			PUCRF,			PDCRF,
	PUCRG,			PDCRG,

	CR5 = 33
};
}

#endif

