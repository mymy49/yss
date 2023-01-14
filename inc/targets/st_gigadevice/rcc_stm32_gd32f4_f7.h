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
#ifndef __RCC_STM32F4__H_
#define __RCC_STM32F4__H_

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                   (0U)                                
#define RCC_CR_HSION_Msk                   (0x1UL << RCC_CR_HSION_Pos)          /*!< 0x00000001 */
#define RCC_CR_HSION                       RCC_CR_HSION_Msk                    
#define RCC_CR_HSIRDY_Pos                  (1U)                                
#define RCC_CR_HSIRDY_Msk                  (0x1UL << RCC_CR_HSIRDY_Pos)         /*!< 0x00000002 */
#define RCC_CR_HSIRDY                      RCC_CR_HSIRDY_Msk                   

#define RCC_CR_HSITRIM_Pos                 (3U)                                
#define RCC_CR_HSITRIM_Msk                 (0x1FUL << RCC_CR_HSITRIM_Pos)       /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                     RCC_CR_HSITRIM_Msk                  
#define RCC_CR_HSITRIM_0                   (0x01UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000008 */
#define RCC_CR_HSITRIM_1                   (0x02UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000010 */
#define RCC_CR_HSITRIM_2                   (0x04UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000020 */
#define RCC_CR_HSITRIM_3                   (0x08UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000040 */
#define RCC_CR_HSITRIM_4                   (0x10UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000080 */

#define RCC_CR_HSICAL_Pos                  (8U)                                
#define RCC_CR_HSICAL_Msk                  (0xFFUL << RCC_CR_HSICAL_Pos)        /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                      RCC_CR_HSICAL_Msk                   
#define RCC_CR_HSICAL_0                    (0x01UL << RCC_CR_HSICAL_Pos)        /*!< 0x00000100 */
#define RCC_CR_HSICAL_1                    (0x02UL << RCC_CR_HSICAL_Pos)        /*!< 0x00000200 */
#define RCC_CR_HSICAL_2                    (0x04UL << RCC_CR_HSICAL_Pos)        /*!< 0x00000400 */
#define RCC_CR_HSICAL_3                    (0x08UL << RCC_CR_HSICAL_Pos)        /*!< 0x00000800 */
#define RCC_CR_HSICAL_4                    (0x10UL << RCC_CR_HSICAL_Pos)        /*!< 0x00001000 */
#define RCC_CR_HSICAL_5                    (0x20UL << RCC_CR_HSICAL_Pos)        /*!< 0x00002000 */
#define RCC_CR_HSICAL_6                    (0x40UL << RCC_CR_HSICAL_Pos)        /*!< 0x00004000 */
#define RCC_CR_HSICAL_7                    (0x80UL << RCC_CR_HSICAL_Pos)        /*!< 0x00008000 */

#define RCC_CR_HSEON_Pos                   (16U)                               
#define RCC_CR_HSEON_Msk                   (0x1UL << RCC_CR_HSEON_Pos)          /*!< 0x00010000 */
#define RCC_CR_HSEON                       RCC_CR_HSEON_Msk                    
#define RCC_CR_HSERDY_Pos                  (17U)                               
#define RCC_CR_HSERDY_Msk                  (0x1UL << RCC_CR_HSERDY_Pos)         /*!< 0x00020000 */
#define RCC_CR_HSERDY                      RCC_CR_HSERDY_Msk                   
#define RCC_CR_HSEBYP_Pos                  (18U)                               
#define RCC_CR_HSEBYP_Msk                  (0x1UL << RCC_CR_HSEBYP_Pos)         /*!< 0x00040000 */
#define RCC_CR_HSEBYP                      RCC_CR_HSEBYP_Msk                   
#define RCC_CR_CSSON_Pos                   (19U)                               
#define RCC_CR_CSSON_Msk                   (0x1UL << RCC_CR_CSSON_Pos)          /*!< 0x00080000 */
#define RCC_CR_CSSON                       RCC_CR_CSSON_Msk                    
#define RCC_CR_PLLON_Pos                   (24U)                               
#define RCC_CR_PLLON_Msk                   (0x1UL << RCC_CR_PLLON_Pos)          /*!< 0x01000000 */
#define RCC_CR_PLLON                       RCC_CR_PLLON_Msk                    
#define RCC_CR_PLLRDY_Pos                  (25U)                               
#define RCC_CR_PLLRDY_Msk                  (0x1UL << RCC_CR_PLLRDY_Pos)         /*!< 0x02000000 */
#define RCC_CR_PLLRDY                      RCC_CR_PLLRDY_Msk                   
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_PLLI2S_SUPPORT                                                     /*!< Support PLLI2S oscillator */

#define RCC_CR_PLLI2SON_Pos                (26U)                               
#define RCC_CR_PLLI2SON_Msk                (0x1UL << RCC_CR_PLLI2SON_Pos)       /*!< 0x04000000 */
#define RCC_CR_PLLI2SON                    RCC_CR_PLLI2SON_Msk                 
#define RCC_CR_PLLI2SRDY_Pos               (27U)                               
#define RCC_CR_PLLI2SRDY_Msk               (0x1UL << RCC_CR_PLLI2SRDY_Pos)      /*!< 0x08000000 */
#define RCC_CR_PLLI2SRDY                   RCC_CR_PLLI2SRDY_Msk                
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_PLLSAI_SUPPORT                                                     /*!< Support PLLSAI oscillator */

#define RCC_CR_PLLSAION_Pos                (28U)                               
#define RCC_CR_PLLSAION_Msk                (0x1UL << RCC_CR_PLLSAION_Pos)       /*!< 0x10000000 */
#define RCC_CR_PLLSAION                    RCC_CR_PLLSAION_Msk                 
#define RCC_CR_PLLSAIRDY_Pos               (29U)                               
#define RCC_CR_PLLSAIRDY_Msk               (0x1UL << RCC_CR_PLLSAIRDY_Pos)      /*!< 0x20000000 */
#define RCC_CR_PLLSAIRDY                   RCC_CR_PLLSAIRDY_Msk                

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLM_Pos               (0U)                                
#define RCC_PLLCFGR_PLLM_Msk               (0x3FUL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x0000003F */
#define RCC_PLLCFGR_PLLM                   RCC_PLLCFGR_PLLM_Msk                
#define RCC_PLLCFGR_PLLM_0                 (0x01UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLM_1                 (0x02UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLM_2                 (0x04UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000004 */
#define RCC_PLLCFGR_PLLM_3                 (0x08UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000008 */
#define RCC_PLLCFGR_PLLM_4                 (0x10UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_5                 (0x20UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000020 */

#define RCC_PLLCFGR_PLLN_Pos               (6U)                                
#define RCC_PLLCFGR_PLLN_Msk               (0x1FFUL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00007FC0 */
#define RCC_PLLCFGR_PLLN                   RCC_PLLCFGR_PLLN_Msk                
#define RCC_PLLCFGR_PLLN_0                 (0x001UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLN_1                 (0x002UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000080 */
#define RCC_PLLCFGR_PLLN_2                 (0x004UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_3                 (0x008UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_4                 (0x010UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_5                 (0x020UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_6                 (0x040UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_7                 (0x080UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_8                 (0x100UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLP_Pos               (16U)                               
#define RCC_PLLCFGR_PLLP_Msk               (0x3UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00030000 */
#define RCC_PLLCFGR_PLLP                   RCC_PLLCFGR_PLLP_Msk                
#define RCC_PLLCFGR_PLLP_0                 (0x1UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLP_1                 (0x2UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00020000 */

#define RCC_PLLCFGR_PLLSRC_Pos             (22U)                               
#define RCC_PLLCFGR_PLLSRC_Msk             (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)    /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC                 RCC_PLLCFGR_PLLSRC_Msk              
#define RCC_PLLCFGR_PLLSRC_HSE_Pos         (22U)                               
#define RCC_PLLCFGR_PLLSRC_HSE_Msk         (0x1UL << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC_HSE             RCC_PLLCFGR_PLLSRC_HSE_Msk          
#define RCC_PLLCFGR_PLLSRC_HSI             0x00000000U                         

#define RCC_PLLCFGR_PLLQ_Pos               (24U)                               
#define RCC_PLLCFGR_PLLQ_Msk               (0xFUL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x0F000000 */
#define RCC_PLLCFGR_PLLQ                   RCC_PLLCFGR_PLLQ_Msk                
#define RCC_PLLCFGR_PLLQ_0                 (0x1UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQ_1                 (0x2UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_2                 (0x4UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_3                 (0x8UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x08000000 */

#define RCC_PLLCFGR_PLLR_Pos               (28U)                               
#define RCC_PLLCFGR_PLLR_Msk               (0x7UL << RCC_PLLCFGR_PLLR_Pos)      /*!< 0x70000000 */
#define RCC_PLLCFGR_PLLR                   RCC_PLLCFGR_PLLR_Msk                
#define RCC_PLLCFGR_PLLR_0                 (0x1UL << RCC_PLLCFGR_PLLR_Pos)      /*!< 0x10000000 */
#define RCC_PLLCFGR_PLLR_1                 (0x2UL << RCC_PLLCFGR_PLLR_Pos)      /*!< 0x20000000 */
#define RCC_PLLCFGR_PLLR_2                 (0x4UL << RCC_PLLCFGR_PLLR_Pos)      /*!< 0x40000000 */

/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                    (0U)                                
#define RCC_CFGR_SW_Msk                    (0x3UL << RCC_CFGR_SW_Pos)           /*!< 0x00000003 */
#define RCC_CFGR_SW                        RCC_CFGR_SW_Msk                     /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                      (0x1UL << RCC_CFGR_SW_Pos)           /*!< 0x00000001 */
#define RCC_CFGR_SW_1                      (0x2UL << RCC_CFGR_SW_Pos)           /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI                    0x00000000U                         /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                    0x00000001U                         /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                    0x00000002U                         /*!< PLL selected as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                   (2U)                                
#define RCC_CFGR_SWS_Msk                   (0x3UL << RCC_CFGR_SWS_Pos)          /*!< 0x0000000C */
#define RCC_CFGR_SWS                       RCC_CFGR_SWS_Msk                    /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                     (0x1UL << RCC_CFGR_SWS_Pos)          /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                     (0x2UL << RCC_CFGR_SWS_Pos)          /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI                   0x00000000U                         /*!< HSI oscillator used as system clock        */
#define RCC_CFGR_SWS_HSE                   0x00000004U                         /*!< HSE oscillator used as system clock        */
#define RCC_CFGR_SWS_PLL                   0x00000008U                         /*!< PLL used as system clock                   */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                  (4U)                                
#define RCC_CFGR_HPRE_Msk                  (0xFUL << RCC_CFGR_HPRE_Pos)         /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                      RCC_CFGR_HPRE_Msk                   /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                    (0x1UL << RCC_CFGR_HPRE_Pos)         /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                    (0x2UL << RCC_CFGR_HPRE_Pos)         /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                    (0x4UL << RCC_CFGR_HPRE_Pos)         /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                    (0x8UL << RCC_CFGR_HPRE_Pos)         /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                 0x00000000U                         /*!< SYSCLK not divided    */
#define RCC_CFGR_HPRE_DIV2                 0x00000080U                         /*!< SYSCLK divided by 2   */
#define RCC_CFGR_HPRE_DIV4                 0x00000090U                         /*!< SYSCLK divided by 4   */
#define RCC_CFGR_HPRE_DIV8                 0x000000A0U                         /*!< SYSCLK divided by 8   */
#define RCC_CFGR_HPRE_DIV16                0x000000B0U                         /*!< SYSCLK divided by 16  */
#define RCC_CFGR_HPRE_DIV64                0x000000C0U                         /*!< SYSCLK divided by 64  */
#define RCC_CFGR_HPRE_DIV128               0x000000D0U                         /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256               0x000000E0U                         /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512               0x000000F0U                         /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                 (10U)                               
#define RCC_CFGR_PPRE1_Msk                 (0x7UL << RCC_CFGR_PPRE1_Pos)        /*!< 0x00001C00 */
#define RCC_CFGR_PPRE1                     RCC_CFGR_PPRE1_Msk                  /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                   (0x1UL << RCC_CFGR_PPRE1_Pos)        /*!< 0x00000400 */
#define RCC_CFGR_PPRE1_1                   (0x2UL << RCC_CFGR_PPRE1_Pos)        /*!< 0x00000800 */
#define RCC_CFGR_PPRE1_2                   (0x4UL << RCC_CFGR_PPRE1_Pos)        /*!< 0x00001000 */

#define RCC_CFGR_PPRE1_DIV1                0x00000000U                         /*!< HCLK not divided   */
#define RCC_CFGR_PPRE1_DIV2                0x00001000U                         /*!< HCLK divided by 2  */
#define RCC_CFGR_PPRE1_DIV4                0x00001400U                         /*!< HCLK divided by 4  */
#define RCC_CFGR_PPRE1_DIV8                0x00001800U                         /*!< HCLK divided by 8  */
#define RCC_CFGR_PPRE1_DIV16               0x00001C00U                         /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                 (13U)                               
#define RCC_CFGR_PPRE2_Msk                 (0x7UL << RCC_CFGR_PPRE2_Pos)        /*!< 0x0000E000 */
#define RCC_CFGR_PPRE2                     RCC_CFGR_PPRE2_Msk                  /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                   (0x1UL << RCC_CFGR_PPRE2_Pos)        /*!< 0x00002000 */
#define RCC_CFGR_PPRE2_1                   (0x2UL << RCC_CFGR_PPRE2_Pos)        /*!< 0x00004000 */
#define RCC_CFGR_PPRE2_2                   (0x4UL << RCC_CFGR_PPRE2_Pos)        /*!< 0x00008000 */

#define RCC_CFGR_PPRE2_DIV1                0x00000000U                         /*!< HCLK not divided   */
#define RCC_CFGR_PPRE2_DIV2                0x00008000U                         /*!< HCLK divided by 2  */
#define RCC_CFGR_PPRE2_DIV4                0x0000A000U                         /*!< HCLK divided by 4  */
#define RCC_CFGR_PPRE2_DIV8                0x0000C000U                         /*!< HCLK divided by 8  */
#define RCC_CFGR_PPRE2_DIV16               0x0000E000U                         /*!< HCLK divided by 16 */

/*!< RTCPRE configuration */
#define RCC_CFGR_RTCPRE_Pos                (16U)                               
#define RCC_CFGR_RTCPRE_Msk                (0x1FUL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x001F0000 */
#define RCC_CFGR_RTCPRE                    RCC_CFGR_RTCPRE_Msk                 
#define RCC_CFGR_RTCPRE_0                  (0x01UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00010000 */
#define RCC_CFGR_RTCPRE_1                  (0x02UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00020000 */
#define RCC_CFGR_RTCPRE_2                  (0x04UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00040000 */
#define RCC_CFGR_RTCPRE_3                  (0x08UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00080000 */
#define RCC_CFGR_RTCPRE_4                  (0x10UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00100000 */

/*!< MCO1 configuration */
#define RCC_CFGR_MCO1_Pos                  (21U)                               
#define RCC_CFGR_MCO1_Msk                  (0x3UL << RCC_CFGR_MCO1_Pos)         /*!< 0x00600000 */
#define RCC_CFGR_MCO1                      RCC_CFGR_MCO1_Msk                   
#define RCC_CFGR_MCO1_0                    (0x1UL << RCC_CFGR_MCO1_Pos)         /*!< 0x00200000 */
#define RCC_CFGR_MCO1_1                    (0x2UL << RCC_CFGR_MCO1_Pos)         /*!< 0x00400000 */

#define RCC_CFGR_I2SSRC_Pos                (23U)                               
#define RCC_CFGR_I2SSRC_Msk                (0x1UL << RCC_CFGR_I2SSRC_Pos)       /*!< 0x00800000 */
#define RCC_CFGR_I2SSRC                    RCC_CFGR_I2SSRC_Msk                 

#define RCC_CFGR_MCO1PRE_Pos               (24U)                               
#define RCC_CFGR_MCO1PRE_Msk               (0x7UL << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x07000000 */
#define RCC_CFGR_MCO1PRE                   RCC_CFGR_MCO1PRE_Msk                
#define RCC_CFGR_MCO1PRE_0                 (0x1UL << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x01000000 */
#define RCC_CFGR_MCO1PRE_1                 (0x2UL << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x02000000 */
#define RCC_CFGR_MCO1PRE_2                 (0x4UL << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x04000000 */

#define RCC_CFGR_MCO2PRE_Pos               (27U)                               
#define RCC_CFGR_MCO2PRE_Msk               (0x7UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x38000000 */
#define RCC_CFGR_MCO2PRE                   RCC_CFGR_MCO2PRE_Msk                
#define RCC_CFGR_MCO2PRE_0                 (0x1UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x08000000 */
#define RCC_CFGR_MCO2PRE_1                 (0x2UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x10000000 */
#define RCC_CFGR_MCO2PRE_2                 (0x4UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x20000000 */

#define RCC_CFGR_MCO2_Pos                  (30U)                               
#define RCC_CFGR_MCO2_Msk                  (0x3UL << RCC_CFGR_MCO2_Pos)         /*!< 0xC0000000 */
#define RCC_CFGR_MCO2                      RCC_CFGR_MCO2_Msk                   
#define RCC_CFGR_MCO2_0                    (0x1UL << RCC_CFGR_MCO2_Pos)         /*!< 0x40000000 */
#define RCC_CFGR_MCO2_1                    (0x2UL << RCC_CFGR_MCO2_Pos)         /*!< 0x80000000 */

/********************  Bit definition for RCC_CIR register  *******************/
#define RCC_CIR_LSIRDYF_Pos                (0U)                                
#define RCC_CIR_LSIRDYF_Msk                (0x1UL << RCC_CIR_LSIRDYF_Pos)       /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF                    RCC_CIR_LSIRDYF_Msk                 
#define RCC_CIR_LSERDYF_Pos                (1U)                                
#define RCC_CIR_LSERDYF_Msk                (0x1UL << RCC_CIR_LSERDYF_Pos)       /*!< 0x00000002 */
#define RCC_CIR_LSERDYF                    RCC_CIR_LSERDYF_Msk                 
#define RCC_CIR_HSIRDYF_Pos                (2U)                                
#define RCC_CIR_HSIRDYF_Msk                (0x1UL << RCC_CIR_HSIRDYF_Pos)       /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF                    RCC_CIR_HSIRDYF_Msk                 
#define RCC_CIR_HSERDYF_Pos                (3U)                                
#define RCC_CIR_HSERDYF_Msk                (0x1UL << RCC_CIR_HSERDYF_Pos)       /*!< 0x00000008 */
#define RCC_CIR_HSERDYF                    RCC_CIR_HSERDYF_Msk                 
#define RCC_CIR_PLLRDYF_Pos                (4U)                                
#define RCC_CIR_PLLRDYF_Msk                (0x1UL << RCC_CIR_PLLRDYF_Pos)       /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF                    RCC_CIR_PLLRDYF_Msk                 
#define RCC_CIR_PLLI2SRDYF_Pos             (5U)                                
#define RCC_CIR_PLLI2SRDYF_Msk             (0x1UL << RCC_CIR_PLLI2SRDYF_Pos)    /*!< 0x00000020 */
#define RCC_CIR_PLLI2SRDYF                 RCC_CIR_PLLI2SRDYF_Msk              

#define RCC_CIR_PLLSAIRDYF_Pos             (6U)                                
#define RCC_CIR_PLLSAIRDYF_Msk             (0x1UL << RCC_CIR_PLLSAIRDYF_Pos)    /*!< 0x00000040 */
#define RCC_CIR_PLLSAIRDYF                 RCC_CIR_PLLSAIRDYF_Msk              
#define RCC_CIR_CSSF_Pos                   (7U)                                
#define RCC_CIR_CSSF_Msk                   (0x1UL << RCC_CIR_CSSF_Pos)          /*!< 0x00000080 */
#define RCC_CIR_CSSF                       RCC_CIR_CSSF_Msk                    
#define RCC_CIR_LSIRDYIE_Pos               (8U)                                
#define RCC_CIR_LSIRDYIE_Msk               (0x1UL << RCC_CIR_LSIRDYIE_Pos)      /*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE                   RCC_CIR_LSIRDYIE_Msk                
#define RCC_CIR_LSERDYIE_Pos               (9U)                                
#define RCC_CIR_LSERDYIE_Msk               (0x1UL << RCC_CIR_LSERDYIE_Pos)      /*!< 0x00000200 */
#define RCC_CIR_LSERDYIE                   RCC_CIR_LSERDYIE_Msk                
#define RCC_CIR_HSIRDYIE_Pos               (10U)                               
#define RCC_CIR_HSIRDYIE_Msk               (0x1UL << RCC_CIR_HSIRDYIE_Pos)      /*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE                   RCC_CIR_HSIRDYIE_Msk                
#define RCC_CIR_HSERDYIE_Pos               (11U)                               
#define RCC_CIR_HSERDYIE_Msk               (0x1UL << RCC_CIR_HSERDYIE_Pos)      /*!< 0x00000800 */
#define RCC_CIR_HSERDYIE                   RCC_CIR_HSERDYIE_Msk                
#define RCC_CIR_PLLRDYIE_Pos               (12U)                               
#define RCC_CIR_PLLRDYIE_Msk               (0x1UL << RCC_CIR_PLLRDYIE_Pos)      /*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE                   RCC_CIR_PLLRDYIE_Msk                
#define RCC_CIR_PLLI2SRDYIE_Pos            (13U)                               
#define RCC_CIR_PLLI2SRDYIE_Msk            (0x1UL << RCC_CIR_PLLI2SRDYIE_Pos)   /*!< 0x00002000 */
#define RCC_CIR_PLLI2SRDYIE                RCC_CIR_PLLI2SRDYIE_Msk             

#define RCC_CIR_PLLSAIRDYIE_Pos            (14U)                               
#define RCC_CIR_PLLSAIRDYIE_Msk            (0x1UL << RCC_CIR_PLLSAIRDYIE_Pos)   /*!< 0x00004000 */
#define RCC_CIR_PLLSAIRDYIE                RCC_CIR_PLLSAIRDYIE_Msk             
#define RCC_CIR_LSIRDYC_Pos                (16U)                               
#define RCC_CIR_LSIRDYC_Msk                (0x1UL << RCC_CIR_LSIRDYC_Pos)       /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC                    RCC_CIR_LSIRDYC_Msk                 
#define RCC_CIR_LSERDYC_Pos                (17U)                               
#define RCC_CIR_LSERDYC_Msk                (0x1UL << RCC_CIR_LSERDYC_Pos)       /*!< 0x00020000 */
#define RCC_CIR_LSERDYC                    RCC_CIR_LSERDYC_Msk                 
#define RCC_CIR_HSIRDYC_Pos                (18U)                               
#define RCC_CIR_HSIRDYC_Msk                (0x1UL << RCC_CIR_HSIRDYC_Pos)       /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC                    RCC_CIR_HSIRDYC_Msk                 
#define RCC_CIR_HSERDYC_Pos                (19U)                               
#define RCC_CIR_HSERDYC_Msk                (0x1UL << RCC_CIR_HSERDYC_Pos)       /*!< 0x00080000 */
#define RCC_CIR_HSERDYC                    RCC_CIR_HSERDYC_Msk                 
#define RCC_CIR_PLLRDYC_Pos                (20U)                               
#define RCC_CIR_PLLRDYC_Msk                (0x1UL << RCC_CIR_PLLRDYC_Pos)       /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC                    RCC_CIR_PLLRDYC_Msk                 
#define RCC_CIR_PLLI2SRDYC_Pos             (21U)                               
#define RCC_CIR_PLLI2SRDYC_Msk             (0x1UL << RCC_CIR_PLLI2SRDYC_Pos)    /*!< 0x00200000 */
#define RCC_CIR_PLLI2SRDYC                 RCC_CIR_PLLI2SRDYC_Msk              
#define RCC_CIR_PLLSAIRDYC_Pos             (22U)                               
#define RCC_CIR_PLLSAIRDYC_Msk             (0x1UL << RCC_CIR_PLLSAIRDYC_Pos)    /*!< 0x00400000 */
#define RCC_CIR_PLLSAIRDYC                 RCC_CIR_PLLSAIRDYC_Msk              

#define RCC_CIR_CSSC_Pos                   (23U)                               
#define RCC_CIR_CSSC_Msk                   (0x1UL << RCC_CIR_CSSC_Pos)          /*!< 0x00800000 */
#define RCC_CIR_CSSC                       RCC_CIR_CSSC_Msk                    

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_GPIOARST_Pos          (0U)                                
#define RCC_AHB1RSTR_GPIOARST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOARST_Pos) /*!< 0x00000001 */
#define RCC_AHB1RSTR_GPIOARST              RCC_AHB1RSTR_GPIOARST_Msk           
#define RCC_AHB1RSTR_GPIOBRST_Pos          (1U)                                
#define RCC_AHB1RSTR_GPIOBRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOBRST_Pos) /*!< 0x00000002 */
#define RCC_AHB1RSTR_GPIOBRST              RCC_AHB1RSTR_GPIOBRST_Msk           
#define RCC_AHB1RSTR_GPIOCRST_Pos          (2U)                                
#define RCC_AHB1RSTR_GPIOCRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOCRST_Pos) /*!< 0x00000004 */
#define RCC_AHB1RSTR_GPIOCRST              RCC_AHB1RSTR_GPIOCRST_Msk           
#define RCC_AHB1RSTR_GPIODRST_Pos          (3U)                                
#define RCC_AHB1RSTR_GPIODRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIODRST_Pos) /*!< 0x00000008 */
#define RCC_AHB1RSTR_GPIODRST              RCC_AHB1RSTR_GPIODRST_Msk           
#define RCC_AHB1RSTR_GPIOERST_Pos          (4U)                                
#define RCC_AHB1RSTR_GPIOERST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOERST_Pos) /*!< 0x00000010 */
#define RCC_AHB1RSTR_GPIOERST              RCC_AHB1RSTR_GPIOERST_Msk           
#define RCC_AHB1RSTR_GPIOFRST_Pos          (5U)                                
#define RCC_AHB1RSTR_GPIOFRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOFRST_Pos) /*!< 0x00000020 */
#define RCC_AHB1RSTR_GPIOFRST              RCC_AHB1RSTR_GPIOFRST_Msk           
#define RCC_AHB1RSTR_GPIOGRST_Pos          (6U)                                
#define RCC_AHB1RSTR_GPIOGRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOGRST_Pos) /*!< 0x00000040 */
#define RCC_AHB1RSTR_GPIOGRST              RCC_AHB1RSTR_GPIOGRST_Msk           
#define RCC_AHB1RSTR_GPIOHRST_Pos          (7U)                                
#define RCC_AHB1RSTR_GPIOHRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOHRST_Pos) /*!< 0x00000080 */
#define RCC_AHB1RSTR_GPIOHRST              RCC_AHB1RSTR_GPIOHRST_Msk           
#define RCC_AHB1RSTR_GPIOIRST_Pos          (8U)                                
#define RCC_AHB1RSTR_GPIOIRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOIRST_Pos) /*!< 0x00000100 */
#define RCC_AHB1RSTR_GPIOIRST              RCC_AHB1RSTR_GPIOIRST_Msk           
#define RCC_AHB1RSTR_GPIOJRST_Pos          (9U)                                
#define RCC_AHB1RSTR_GPIOJRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOJRST_Pos) /*!< 0x00000200 */
#define RCC_AHB1RSTR_GPIOJRST              RCC_AHB1RSTR_GPIOJRST_Msk           
#define RCC_AHB1RSTR_GPIOKRST_Pos          (10U)                               
#define RCC_AHB1RSTR_GPIOKRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOKRST_Pos) /*!< 0x00000400 */
#define RCC_AHB1RSTR_GPIOKRST              RCC_AHB1RSTR_GPIOKRST_Msk           
#define RCC_AHB1RSTR_CRCRST_Pos            (12U)                               
#define RCC_AHB1RSTR_CRCRST_Msk            (0x1UL << RCC_AHB1RSTR_CRCRST_Pos)   /*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST                RCC_AHB1RSTR_CRCRST_Msk             
#define RCC_AHB1RSTR_DMA1RST_Pos           (21U)                               
#define RCC_AHB1RSTR_DMA1RST_Msk           (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos)  /*!< 0x00200000 */
#define RCC_AHB1RSTR_DMA1RST               RCC_AHB1RSTR_DMA1RST_Msk            
#define RCC_AHB1RSTR_DMA2RST_Pos           (22U)                               
#define RCC_AHB1RSTR_DMA2RST_Msk           (0x1UL << RCC_AHB1RSTR_DMA2RST_Pos)  /*!< 0x00400000 */
#define RCC_AHB1RSTR_DMA2RST               RCC_AHB1RSTR_DMA2RST_Msk            
#define RCC_AHB1RSTR_DMA2DRST_Pos          (23U)                               
#define RCC_AHB1RSTR_DMA2DRST_Msk          (0x1UL << RCC_AHB1RSTR_DMA2DRST_Pos) /*!< 0x00800000 */
#define RCC_AHB1RSTR_DMA2DRST              RCC_AHB1RSTR_DMA2DRST_Msk           
#define RCC_AHB1RSTR_ETHMACRST_Pos         (25U)                               
#define RCC_AHB1RSTR_ETHMACRST_Msk         (0x1UL << RCC_AHB1RSTR_ETHMACRST_Pos) /*!< 0x02000000 */
#define RCC_AHB1RSTR_ETHMACRST             RCC_AHB1RSTR_ETHMACRST_Msk          
#define RCC_AHB1RSTR_OTGHRST_Pos           (29U)                               
#define RCC_AHB1RSTR_OTGHRST_Msk           (0x1UL << RCC_AHB1RSTR_OTGHRST_Pos)  /*!< 0x20000000 */
#define RCC_AHB1RSTR_OTGHRST               RCC_AHB1RSTR_OTGHRST_Msk            

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_DCMIRST_Pos           (0U)                                
#define RCC_AHB2RSTR_DCMIRST_Msk           (0x1UL << RCC_AHB2RSTR_DCMIRST_Pos)  /*!< 0x00000001 */
#define RCC_AHB2RSTR_DCMIRST               RCC_AHB2RSTR_DCMIRST_Msk            
#define RCC_AHB2RSTR_CRYPRST_Pos           (4U)                                
#define RCC_AHB2RSTR_CRYPRST_Msk           (0x1UL << RCC_AHB2RSTR_CRYPRST_Pos)  /*!< 0x00000010 */
#define RCC_AHB2RSTR_CRYPRST               RCC_AHB2RSTR_CRYPRST_Msk            
#define RCC_AHB2RSTR_HASHRST_Pos           (5U)                                
#define RCC_AHB2RSTR_HASHRST_Msk           (0x1UL << RCC_AHB2RSTR_HASHRST_Pos)  /*!< 0x00000020 */
#define RCC_AHB2RSTR_HASHRST               RCC_AHB2RSTR_HASHRST_Msk            
 /* maintained for legacy purpose */
#define  RCC_AHB2RSTR_HSAHRST                RCC_AHB2RSTR_HASHRST
#define RCC_AHB2RSTR_RNGRST_Pos            (6U)                                
#define RCC_AHB2RSTR_RNGRST_Msk            (0x1UL << RCC_AHB2RSTR_RNGRST_Pos)   /*!< 0x00000040 */
#define RCC_AHB2RSTR_RNGRST                RCC_AHB2RSTR_RNGRST_Msk             
#define RCC_AHB2RSTR_OTGFSRST_Pos          (7U)                                
#define RCC_AHB2RSTR_OTGFSRST_Msk          (0x1UL << RCC_AHB2RSTR_OTGFSRST_Pos) /*!< 0x00000080 */
#define RCC_AHB2RSTR_OTGFSRST              RCC_AHB2RSTR_OTGFSRST_Msk           
/********************  Bit definition for RCC_AHB3RSTR register  **************/
#define RCC_AHB3RSTR_FMCRST_Pos            (0U)                                
#define RCC_AHB3RSTR_FMCRST_Msk            (0x1UL << RCC_AHB3RSTR_FMCRST_Pos)   /*!< 0x00000001 */
#define RCC_AHB3RSTR_FMCRST                RCC_AHB3RSTR_FMCRST_Msk             
#define RCC_AHB3RSTR_QSPIRST_Pos           (1U)                                
#define RCC_AHB3RSTR_QSPIRST_Msk           (0x1UL << RCC_AHB3RSTR_QSPIRST_Pos)  /*!< 0x00000002 */
#define RCC_AHB3RSTR_QSPIRST               RCC_AHB3RSTR_QSPIRST_Msk            


/********************  Bit definition for RCC_APB1RSTR register  **************/
#define RCC_APB1RSTR_TIM2RST_Pos           (0U)                                
#define RCC_APB1RSTR_TIM2RST_Msk           (0x1UL << RCC_APB1RSTR_TIM2RST_Pos)  /*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST               RCC_APB1RSTR_TIM2RST_Msk            
#define RCC_APB1RSTR_TIM3RST_Pos           (1U)                                
#define RCC_APB1RSTR_TIM3RST_Msk           (0x1UL << RCC_APB1RSTR_TIM3RST_Pos)  /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST               RCC_APB1RSTR_TIM3RST_Msk            
#define RCC_APB1RSTR_TIM4RST_Pos           (2U)                                
#define RCC_APB1RSTR_TIM4RST_Msk           (0x1UL << RCC_APB1RSTR_TIM4RST_Pos)  /*!< 0x00000004 */
#define RCC_APB1RSTR_TIM4RST               RCC_APB1RSTR_TIM4RST_Msk            
#define RCC_APB1RSTR_TIM5RST_Pos           (3U)                                
#define RCC_APB1RSTR_TIM5RST_Msk           (0x1UL << RCC_APB1RSTR_TIM5RST_Pos)  /*!< 0x00000008 */
#define RCC_APB1RSTR_TIM5RST               RCC_APB1RSTR_TIM5RST_Msk            
#define RCC_APB1RSTR_TIM6RST_Pos           (4U)                                
#define RCC_APB1RSTR_TIM6RST_Msk           (0x1UL << RCC_APB1RSTR_TIM6RST_Pos)  /*!< 0x00000010 */
#define RCC_APB1RSTR_TIM6RST               RCC_APB1RSTR_TIM6RST_Msk            
#define RCC_APB1RSTR_TIM7RST_Pos           (5U)                                
#define RCC_APB1RSTR_TIM7RST_Msk           (0x1UL << RCC_APB1RSTR_TIM7RST_Pos)  /*!< 0x00000020 */
#define RCC_APB1RSTR_TIM7RST               RCC_APB1RSTR_TIM7RST_Msk            
#define RCC_APB1RSTR_TIM12RST_Pos          (6U)                                
#define RCC_APB1RSTR_TIM12RST_Msk          (0x1UL << RCC_APB1RSTR_TIM12RST_Pos) /*!< 0x00000040 */
#define RCC_APB1RSTR_TIM12RST              RCC_APB1RSTR_TIM12RST_Msk           
#define RCC_APB1RSTR_TIM13RST_Pos          (7U)                                
#define RCC_APB1RSTR_TIM13RST_Msk          (0x1UL << RCC_APB1RSTR_TIM13RST_Pos) /*!< 0x00000080 */
#define RCC_APB1RSTR_TIM13RST              RCC_APB1RSTR_TIM13RST_Msk           
#define RCC_APB1RSTR_TIM14RST_Pos          (8U)                                
#define RCC_APB1RSTR_TIM14RST_Msk          (0x1UL << RCC_APB1RSTR_TIM14RST_Pos) /*!< 0x00000100 */
#define RCC_APB1RSTR_TIM14RST              RCC_APB1RSTR_TIM14RST_Msk           
#define RCC_APB1RSTR_WWDGRST_Pos           (11U)                               
#define RCC_APB1RSTR_WWDGRST_Msk           (0x1UL << RCC_APB1RSTR_WWDGRST_Pos)  /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST               RCC_APB1RSTR_WWDGRST_Msk            
#define RCC_APB1RSTR_SPI2RST_Pos           (14U)                               
#define RCC_APB1RSTR_SPI2RST_Msk           (0x1UL << RCC_APB1RSTR_SPI2RST_Pos)  /*!< 0x00004000 */
#define RCC_APB1RSTR_SPI2RST               RCC_APB1RSTR_SPI2RST_Msk            
#define RCC_APB1RSTR_SPI3RST_Pos           (15U)                               
#define RCC_APB1RSTR_SPI3RST_Msk           (0x1UL << RCC_APB1RSTR_SPI3RST_Pos)  /*!< 0x00008000 */
#define RCC_APB1RSTR_SPI3RST               RCC_APB1RSTR_SPI3RST_Msk            
#define RCC_APB1RSTR_USART2RST_Pos         (17U)                               
#define RCC_APB1RSTR_USART2RST_Msk         (0x1UL << RCC_APB1RSTR_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST             RCC_APB1RSTR_USART2RST_Msk          
#define RCC_APB1RSTR_USART3RST_Pos         (18U)                               
#define RCC_APB1RSTR_USART3RST_Msk         (0x1UL << RCC_APB1RSTR_USART3RST_Pos) /*!< 0x00040000 */
#define RCC_APB1RSTR_USART3RST             RCC_APB1RSTR_USART3RST_Msk          
#define RCC_APB1RSTR_UART4RST_Pos          (19U)                               
#define RCC_APB1RSTR_UART4RST_Msk          (0x1UL << RCC_APB1RSTR_UART4RST_Pos) /*!< 0x00080000 */
#define RCC_APB1RSTR_UART4RST              RCC_APB1RSTR_UART4RST_Msk           
#define RCC_APB1RSTR_UART5RST_Pos          (20U)                               
#define RCC_APB1RSTR_UART5RST_Msk          (0x1UL << RCC_APB1RSTR_UART5RST_Pos) /*!< 0x00100000 */
#define RCC_APB1RSTR_UART5RST              RCC_APB1RSTR_UART5RST_Msk           
#define RCC_APB1RSTR_I2C1RST_Pos           (21U)                               
#define RCC_APB1RSTR_I2C1RST_Msk           (0x1UL << RCC_APB1RSTR_I2C1RST_Pos)  /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST               RCC_APB1RSTR_I2C1RST_Msk            
#define RCC_APB1RSTR_I2C2RST_Pos           (22U)                               
#define RCC_APB1RSTR_I2C2RST_Msk           (0x1UL << RCC_APB1RSTR_I2C2RST_Pos)  /*!< 0x00400000 */
#define RCC_APB1RSTR_I2C2RST               RCC_APB1RSTR_I2C2RST_Msk            
#define RCC_APB1RSTR_I2C3RST_Pos           (23U)                               
#define RCC_APB1RSTR_I2C3RST_Msk           (0x1UL << RCC_APB1RSTR_I2C3RST_Pos)  /*!< 0x00800000 */
#define RCC_APB1RSTR_I2C3RST               RCC_APB1RSTR_I2C3RST_Msk            
#define RCC_APB1RSTR_I2C4RST_Pos           (24U)
#define RCC_APB1RSTR_I2C4RST_Msk           (0x1UL << RCC_APB1RSTR_I2C4RST_Pos)  /*!< 0x01000000 */
#define RCC_APB1RSTR_I2C4RST               RCC_APB1RSTR_I2C4RST_Msk
#define RCC_APB1RSTR_CAN1RST_Pos           (25U)                               
#define RCC_APB1RSTR_CAN1RST_Msk           (0x1UL << RCC_APB1RSTR_CAN1RST_Pos)  /*!< 0x02000000 */
#define RCC_APB1RSTR_CAN1RST               RCC_APB1RSTR_CAN1RST_Msk            
#define RCC_APB1RSTR_CAN2RST_Pos           (26U)                               
#define RCC_APB1RSTR_CAN2RST_Msk           (0x1UL << RCC_APB1RSTR_CAN2RST_Pos)  /*!< 0x04000000 */
#define RCC_APB1RSTR_CAN2RST               RCC_APB1RSTR_CAN2RST_Msk            
#define RCC_APB1RSTR_PWRRST_Pos            (28U)                               
#define RCC_APB1RSTR_PWRRST_Msk            (0x1UL << RCC_APB1RSTR_PWRRST_Pos)   /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST                RCC_APB1RSTR_PWRRST_Msk             
#define RCC_APB1RSTR_DACRST_Pos            (29U)                               
#define RCC_APB1RSTR_DACRST_Msk            (0x1UL << RCC_APB1RSTR_DACRST_Pos)   /*!< 0x20000000 */
#define RCC_APB1RSTR_DACRST                RCC_APB1RSTR_DACRST_Msk             
#define RCC_APB1RSTR_UART7RST_Pos          (30U)                               
#define RCC_APB1RSTR_UART7RST_Msk          (0x1UL << RCC_APB1RSTR_UART7RST_Pos) /*!< 0x40000000 */
#define RCC_APB1RSTR_UART7RST              RCC_APB1RSTR_UART7RST_Msk           
#define RCC_APB1RSTR_UART8RST_Pos          (31U)                               
#define RCC_APB1RSTR_UART8RST_Msk          (0x1UL << RCC_APB1RSTR_UART8RST_Pos) /*!< 0x80000000 */
#define RCC_APB1RSTR_UART8RST              RCC_APB1RSTR_UART8RST_Msk           

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_TIM1RST_Pos           (0U)                                
#define RCC_APB2RSTR_TIM1RST_Msk           (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)  /*!< 0x00000001 */
#define RCC_APB2RSTR_TIM1RST               RCC_APB2RSTR_TIM1RST_Msk            
#define RCC_APB2RSTR_TIM8RST_Pos           (1U)                                
#define RCC_APB2RSTR_TIM8RST_Msk           (0x1UL << RCC_APB2RSTR_TIM8RST_Pos)  /*!< 0x00000002 */
#define RCC_APB2RSTR_TIM8RST               RCC_APB2RSTR_TIM8RST_Msk            
#define RCC_APB2RSTR_USART1RST_Pos         (4U)                                
#define RCC_APB2RSTR_USART1RST_Msk         (0x1UL << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00000010 */
#define RCC_APB2RSTR_USART1RST             RCC_APB2RSTR_USART1RST_Msk          
#define RCC_APB2RSTR_USART6RST_Pos         (5U)                                
#define RCC_APB2RSTR_USART6RST_Msk         (0x1UL << RCC_APB2RSTR_USART6RST_Pos) /*!< 0x00000020 */
#define RCC_APB2RSTR_USART6RST             RCC_APB2RSTR_USART6RST_Msk          
#define RCC_APB2RSTR_ADCRST_Pos            (8U)                                
#define RCC_APB2RSTR_ADCRST_Msk            (0x1UL << RCC_APB2RSTR_ADCRST_Pos)   /*!< 0x00000100 */
#define RCC_APB2RSTR_ADCRST                RCC_APB2RSTR_ADCRST_Msk             
#define RCC_APB2RSTR_SDIORST_Pos           (11U)                               
#define RCC_APB2RSTR_SDIORST_Msk           (0x1UL << RCC_APB2RSTR_SDIORST_Pos)  /*!< 0x00000800 */
#define RCC_APB2RSTR_SDIORST               RCC_APB2RSTR_SDIORST_Msk            
#define RCC_APB2RSTR_SPI1RST_Pos           (12U)                               
#define RCC_APB2RSTR_SPI1RST_Msk           (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)  /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST               RCC_APB2RSTR_SPI1RST_Msk            
#define RCC_APB2RSTR_SPI4RST_Pos           (13U)                               
#define RCC_APB2RSTR_SPI4RST_Msk           (0x1UL << RCC_APB2RSTR_SPI4RST_Pos)  /*!< 0x00002000 */
#define RCC_APB2RSTR_SPI4RST               RCC_APB2RSTR_SPI4RST_Msk            
#define RCC_APB2RSTR_SYSCFGRST_Pos         (14U)                               
#define RCC_APB2RSTR_SYSCFGRST_Msk         (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_SYSCFGRST             RCC_APB2RSTR_SYSCFGRST_Msk          
#define RCC_APB2RSTR_TIM9RST_Pos           (16U)                               
#define RCC_APB2RSTR_TIM9RST_Msk           (0x1UL << RCC_APB2RSTR_TIM9RST_Pos)  /*!< 0x00010000 */
#define RCC_APB2RSTR_TIM9RST               RCC_APB2RSTR_TIM9RST_Msk            
#define RCC_APB2RSTR_TIM10RST_Pos          (17U)                               
#define RCC_APB2RSTR_TIM10RST_Msk          (0x1UL << RCC_APB2RSTR_TIM10RST_Pos) /*!< 0x00020000 */
#define RCC_APB2RSTR_TIM10RST              RCC_APB2RSTR_TIM10RST_Msk           
#define RCC_APB2RSTR_TIM11RST_Pos          (18U)                               
#define RCC_APB2RSTR_TIM11RST_Msk          (0x1UL << RCC_APB2RSTR_TIM11RST_Pos) /*!< 0x00040000 */
#define RCC_APB2RSTR_TIM11RST              RCC_APB2RSTR_TIM11RST_Msk           
#define RCC_APB2RSTR_SPI5RST_Pos           (20U)                               
#define RCC_APB2RSTR_SPI5RST_Msk           (0x1UL << RCC_APB2RSTR_SPI5RST_Pos)  /*!< 0x00100000 */
#define RCC_APB2RSTR_SPI5RST               RCC_APB2RSTR_SPI5RST_Msk            
#define RCC_APB2RSTR_SPI6RST_Pos           (21U)                               
#define RCC_APB2RSTR_SPI6RST_Msk           (0x1UL << RCC_APB2RSTR_SPI6RST_Pos)  /*!< 0x00200000 */
#define RCC_APB2RSTR_SPI6RST               RCC_APB2RSTR_SPI6RST_Msk            
#define RCC_APB2RSTR_SAI1RST_Pos           (22U)                               
#define RCC_APB2RSTR_SAI1RST_Msk           (0x1UL << RCC_APB2RSTR_SAI1RST_Pos)  /*!< 0x00400000 */
#define RCC_APB2RSTR_SAI1RST               RCC_APB2RSTR_SAI1RST_Msk            
#define RCC_APB2RSTR_LTDCRST_Pos           (26U)                               
#define RCC_APB2RSTR_LTDCRST_Msk           (0x1UL << RCC_APB2RSTR_LTDCRST_Pos)  /*!< 0x04000000 */
#define RCC_APB2RSTR_LTDCRST               RCC_APB2RSTR_LTDCRST_Msk            
#define RCC_APB2RSTR_DSIRST_Pos            (27U)                               
#define RCC_APB2RSTR_DSIRST_Msk            (0x1UL << RCC_APB2RSTR_DSIRST_Pos)   /*!< 0x08000000 */
#define RCC_APB2RSTR_DSIRST                RCC_APB2RSTR_DSIRST_Msk             

/* Old SPI1RST bit definition, maintained for legacy purpose */
#define  RCC_APB2RSTR_SPI1                   RCC_APB2RSTR_SPI1RST

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_GPIOAEN_Pos            (0U)                                
#define RCC_AHB1ENR_GPIOAEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)   /*!< 0x00000001 */
#define RCC_AHB1ENR_GPIOAEN                RCC_AHB1ENR_GPIOAEN_Msk             
#define RCC_AHB1ENR_GPIOBEN_Pos            (1U)                                
#define RCC_AHB1ENR_GPIOBEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)   /*!< 0x00000002 */
#define RCC_AHB1ENR_GPIOBEN                RCC_AHB1ENR_GPIOBEN_Msk             
#define RCC_AHB1ENR_GPIOCEN_Pos            (2U)                                
#define RCC_AHB1ENR_GPIOCEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOCEN_Pos)   /*!< 0x00000004 */
#define RCC_AHB1ENR_GPIOCEN                RCC_AHB1ENR_GPIOCEN_Msk             
#define RCC_AHB1ENR_GPIODEN_Pos            (3U)                                
#define RCC_AHB1ENR_GPIODEN_Msk            (0x1UL << RCC_AHB1ENR_GPIODEN_Pos)   /*!< 0x00000008 */
#define RCC_AHB1ENR_GPIODEN                RCC_AHB1ENR_GPIODEN_Msk             
#define RCC_AHB1ENR_GPIOEEN_Pos            (4U)                                
#define RCC_AHB1ENR_GPIOEEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOEEN_Pos)   /*!< 0x00000010 */
#define RCC_AHB1ENR_GPIOEEN                RCC_AHB1ENR_GPIOEEN_Msk             
#define RCC_AHB1ENR_GPIOFEN_Pos            (5U)                                
#define RCC_AHB1ENR_GPIOFEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOFEN_Pos)   /*!< 0x00000020 */
#define RCC_AHB1ENR_GPIOFEN                RCC_AHB1ENR_GPIOFEN_Msk             
#define RCC_AHB1ENR_GPIOGEN_Pos            (6U)                                
#define RCC_AHB1ENR_GPIOGEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOGEN_Pos)   /*!< 0x00000040 */
#define RCC_AHB1ENR_GPIOGEN                RCC_AHB1ENR_GPIOGEN_Msk             
#define RCC_AHB1ENR_GPIOHEN_Pos            (7U)                                
#define RCC_AHB1ENR_GPIOHEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOHEN_Pos)   /*!< 0x00000080 */
#define RCC_AHB1ENR_GPIOHEN                RCC_AHB1ENR_GPIOHEN_Msk             
#define RCC_AHB1ENR_GPIOIEN_Pos            (8U)                                
#define RCC_AHB1ENR_GPIOIEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOIEN_Pos)   /*!< 0x00000100 */
#define RCC_AHB1ENR_GPIOIEN                RCC_AHB1ENR_GPIOIEN_Msk             
#define RCC_AHB1ENR_GPIOJEN_Pos            (9U)                                
#define RCC_AHB1ENR_GPIOJEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOJEN_Pos)   /*!< 0x00000200 */
#define RCC_AHB1ENR_GPIOJEN                RCC_AHB1ENR_GPIOJEN_Msk             
#define RCC_AHB1ENR_GPIOKEN_Pos            (10U)                               
#define RCC_AHB1ENR_GPIOKEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOKEN_Pos)   /*!< 0x00000400 */
#define RCC_AHB1ENR_GPIOKEN                RCC_AHB1ENR_GPIOKEN_Msk             
#define RCC_AHB1ENR_CRCEN_Pos              (12U)                               
#define RCC_AHB1ENR_CRCEN_Msk              (0x1UL << RCC_AHB1ENR_CRCEN_Pos)     /*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN                  RCC_AHB1ENR_CRCEN_Msk               
#define RCC_AHB1ENR_BKPSRAMEN_Pos          (18U)                               
#define RCC_AHB1ENR_BKPSRAMEN_Msk          (0x1UL << RCC_AHB1ENR_BKPSRAMEN_Pos) /*!< 0x00040000 */
#define RCC_AHB1ENR_BKPSRAMEN              RCC_AHB1ENR_BKPSRAMEN_Msk           
#define RCC_AHB1ENR_CCMDATARAMEN_Pos       (20U)                               
#define RCC_AHB1ENR_CCMDATARAMEN_Msk       (0x1UL << RCC_AHB1ENR_CCMDATARAMEN_Pos) /*!< 0x00100000 */
#define RCC_AHB1ENR_CCMDATARAMEN           RCC_AHB1ENR_CCMDATARAMEN_Msk        
#define RCC_AHB1ENR_DMA1EN_Pos             (21U)                               
#define RCC_AHB1ENR_DMA1EN_Msk             (0x1UL << RCC_AHB1ENR_DMA1EN_Pos)    /*!< 0x00200000 */
#define RCC_AHB1ENR_DMA1EN                 RCC_AHB1ENR_DMA1EN_Msk              
#define RCC_AHB1ENR_DMA2EN_Pos             (22U)                               
#define RCC_AHB1ENR_DMA2EN_Msk             (0x1UL << RCC_AHB1ENR_DMA2EN_Pos)    /*!< 0x00400000 */
#define RCC_AHB1ENR_DMA2EN                 RCC_AHB1ENR_DMA2EN_Msk              
#define RCC_AHB1ENR_DMA2DEN_Pos            (23U)                               
#define RCC_AHB1ENR_DMA2DEN_Msk            (0x1UL << RCC_AHB1ENR_DMA2DEN_Pos)   /*!< 0x00800000 */
#define RCC_AHB1ENR_DMA2DEN                RCC_AHB1ENR_DMA2DEN_Msk             
#define RCC_AHB1ENR_ETHMACEN_Pos           (25U)                               
#define RCC_AHB1ENR_ETHMACEN_Msk           (0x1UL << RCC_AHB1ENR_ETHMACEN_Pos)  /*!< 0x02000000 */
#define RCC_AHB1ENR_ETHMACEN               RCC_AHB1ENR_ETHMACEN_Msk            
#define RCC_AHB1ENR_ETHMACTXEN_Pos         (26U)                               
#define RCC_AHB1ENR_ETHMACTXEN_Msk         (0x1UL << RCC_AHB1ENR_ETHMACTXEN_Pos) /*!< 0x04000000 */
#define RCC_AHB1ENR_ETHMACTXEN             RCC_AHB1ENR_ETHMACTXEN_Msk          
#define RCC_AHB1ENR_ETHMACRXEN_Pos         (27U)                               
#define RCC_AHB1ENR_ETHMACRXEN_Msk         (0x1UL << RCC_AHB1ENR_ETHMACRXEN_Pos) /*!< 0x08000000 */
#define RCC_AHB1ENR_ETHMACRXEN             RCC_AHB1ENR_ETHMACRXEN_Msk          
#define RCC_AHB1ENR_ETHMACPTPEN_Pos        (28U)                               
#define RCC_AHB1ENR_ETHMACPTPEN_Msk        (0x1UL << RCC_AHB1ENR_ETHMACPTPEN_Pos) /*!< 0x10000000 */
#define RCC_AHB1ENR_ETHMACPTPEN            RCC_AHB1ENR_ETHMACPTPEN_Msk         
#define RCC_AHB1ENR_OTGHSEN_Pos            (29U)                               
#define RCC_AHB1ENR_OTGHSEN_Msk            (0x1UL << RCC_AHB1ENR_OTGHSEN_Pos)   /*!< 0x20000000 */
#define RCC_AHB1ENR_OTGHSEN                RCC_AHB1ENR_OTGHSEN_Msk             
#define RCC_AHB1ENR_OTGHSULPIEN_Pos        (30U)                               
#define RCC_AHB1ENR_OTGHSULPIEN_Msk        (0x1UL << RCC_AHB1ENR_OTGHSULPIEN_Pos) /*!< 0x40000000 */
#define RCC_AHB1ENR_OTGHSULPIEN            RCC_AHB1ENR_OTGHSULPIEN_Msk         
/********************  Bit definition for RCC_AHB2ENR register  ***************/
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_AHB2_SUPPORT                   /*!< AHB2 Bus is supported */

#define RCC_AHB2ENR_DCMIEN_Pos             (0U)                                
#define RCC_AHB2ENR_DCMIEN_Msk             (0x1UL << RCC_AHB2ENR_DCMIEN_Pos)    /*!< 0x00000001 */
#define RCC_AHB2ENR_DCMIEN                 RCC_AHB2ENR_DCMIEN_Msk              
#define RCC_AHB2ENR_CRYPEN_Pos             (4U)                                
#define RCC_AHB2ENR_CRYPEN_Msk             (0x1UL << RCC_AHB2ENR_CRYPEN_Pos)    /*!< 0x00000010 */
#define RCC_AHB2ENR_CRYPEN                 RCC_AHB2ENR_CRYPEN_Msk              
#define RCC_AHB2ENR_HASHEN_Pos             (5U)                                
#define RCC_AHB2ENR_HASHEN_Msk             (0x1UL << RCC_AHB2ENR_HASHEN_Pos)    /*!< 0x00000020 */
#define RCC_AHB2ENR_HASHEN                 RCC_AHB2ENR_HASHEN_Msk              
#define RCC_AHB2ENR_RNGEN_Pos              (6U)                                
#define RCC_AHB2ENR_RNGEN_Msk              (0x1UL << RCC_AHB2ENR_RNGEN_Pos)     /*!< 0x00000040 */
#define RCC_AHB2ENR_RNGEN                  RCC_AHB2ENR_RNGEN_Msk               
#define RCC_AHB2ENR_OTGFSEN_Pos            (7U)                                
#define RCC_AHB2ENR_OTGFSEN_Msk            (0x1UL << RCC_AHB2ENR_OTGFSEN_Pos)   /*!< 0x00000080 */
#define RCC_AHB2ENR_OTGFSEN                RCC_AHB2ENR_OTGFSEN_Msk             

/********************  Bit definition for RCC_AHB3ENR register  ***************/
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_AHB3_SUPPORT                   /*!< AHB3 Bus is supported */

#define RCC_AHB3ENR_FMCEN_Pos              (0U)                                
#define RCC_AHB3ENR_FMCEN_Msk              (0x1UL << RCC_AHB3ENR_FMCEN_Pos)     /*!< 0x00000001 */
#define RCC_AHB3ENR_FMCEN                  RCC_AHB3ENR_FMCEN_Msk               
#define RCC_AHB3ENR_QSPIEN_Pos             (1U)                                
#define RCC_AHB3ENR_QSPIEN_Msk             (0x1UL << RCC_AHB3ENR_QSPIEN_Pos)    /*!< 0x00000002 */
#define RCC_AHB3ENR_QSPIEN                 RCC_AHB3ENR_QSPIEN_Msk              

/********************  Bit definition for RCC_APB1ENR register  ***************/
#define RCC_APB1ENR_TIM2EN_Pos             (0U)                                
#define RCC_APB1ENR_TIM2EN_Msk             (0x1UL << RCC_APB1ENR_TIM2EN_Pos)    /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                 RCC_APB1ENR_TIM2EN_Msk              
#define RCC_APB1ENR_TIM3EN_Pos             (1U)                                
#define RCC_APB1ENR_TIM3EN_Msk             (0x1UL << RCC_APB1ENR_TIM3EN_Pos)    /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                 RCC_APB1ENR_TIM3EN_Msk              
#define RCC_APB1ENR_TIM4EN_Pos             (2U)                                
#define RCC_APB1ENR_TIM4EN_Msk             (0x1UL << RCC_APB1ENR_TIM4EN_Pos)    /*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN                 RCC_APB1ENR_TIM4EN_Msk              
#define RCC_APB1ENR_TIM5EN_Pos             (3U)                                
#define RCC_APB1ENR_TIM5EN_Msk             (0x1UL << RCC_APB1ENR_TIM5EN_Pos)    /*!< 0x00000008 */
#define RCC_APB1ENR_TIM5EN                 RCC_APB1ENR_TIM5EN_Msk              
#define RCC_APB1ENR_TIM6EN_Pos             (4U)                                
#define RCC_APB1ENR_TIM6EN_Msk             (0x1UL << RCC_APB1ENR_TIM6EN_Pos)    /*!< 0x00000010 */
#define RCC_APB1ENR_TIM6EN                 RCC_APB1ENR_TIM6EN_Msk              
#define RCC_APB1ENR_TIM7EN_Pos             (5U)                                
#define RCC_APB1ENR_TIM7EN_Msk             (0x1UL << RCC_APB1ENR_TIM7EN_Pos)    /*!< 0x00000020 */
#define RCC_APB1ENR_TIM7EN                 RCC_APB1ENR_TIM7EN_Msk              
#define RCC_APB1ENR_TIM12EN_Pos            (6U)                                
#define RCC_APB1ENR_TIM12EN_Msk            (0x1UL << RCC_APB1ENR_TIM12EN_Pos)   /*!< 0x00000040 */
#define RCC_APB1ENR_TIM12EN                RCC_APB1ENR_TIM12EN_Msk             
#define RCC_APB1ENR_TIM13EN_Pos            (7U)                                
#define RCC_APB1ENR_TIM13EN_Msk            (0x1UL << RCC_APB1ENR_TIM13EN_Pos)   /*!< 0x00000080 */
#define RCC_APB1ENR_TIM13EN                RCC_APB1ENR_TIM13EN_Msk             
#define RCC_APB1ENR_TIM14EN_Pos            (8U)                                
#define RCC_APB1ENR_TIM14EN_Msk            (0x1UL << RCC_APB1ENR_TIM14EN_Pos)   /*!< 0x00000100 */
#define RCC_APB1ENR_TIM14EN                RCC_APB1ENR_TIM14EN_Msk             
#define RCC_APB1ENR_WWDGEN_Pos             (11U)                               
#define RCC_APB1ENR_WWDGEN_Msk             (0x1UL << RCC_APB1ENR_WWDGEN_Pos)    /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                 RCC_APB1ENR_WWDGEN_Msk              
#define RCC_APB1ENR_SPI2EN_Pos             (14U)                               
#define RCC_APB1ENR_SPI2EN_Msk             (0x1UL << RCC_APB1ENR_SPI2EN_Pos)    /*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN                 RCC_APB1ENR_SPI2EN_Msk              
#define RCC_APB1ENR_SPI3EN_Pos             (15U)                               
#define RCC_APB1ENR_SPI3EN_Msk             (0x1UL << RCC_APB1ENR_SPI3EN_Pos)    /*!< 0x00008000 */
#define RCC_APB1ENR_SPI3EN                 RCC_APB1ENR_SPI3EN_Msk              
#define RCC_APB1ENR_USART2EN_Pos           (17U)                               
#define RCC_APB1ENR_USART2EN_Msk           (0x1UL << RCC_APB1ENR_USART2EN_Pos)  /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN               RCC_APB1ENR_USART2EN_Msk            
#define RCC_APB1ENR_USART3EN_Pos           (18U)                               
#define RCC_APB1ENR_USART3EN_Msk           (0x1UL << RCC_APB1ENR_USART3EN_Pos)  /*!< 0x00040000 */
#define RCC_APB1ENR_USART3EN               RCC_APB1ENR_USART3EN_Msk            
#define RCC_APB1ENR_UART4EN_Pos            (19U)                               
#define RCC_APB1ENR_UART4EN_Msk            (0x1UL << RCC_APB1ENR_UART4EN_Pos)   /*!< 0x00080000 */
#define RCC_APB1ENR_UART4EN                RCC_APB1ENR_UART4EN_Msk             
#define RCC_APB1ENR_UART5EN_Pos            (20U)                               
#define RCC_APB1ENR_UART5EN_Msk            (0x1UL << RCC_APB1ENR_UART5EN_Pos)   /*!< 0x00100000 */
#define RCC_APB1ENR_UART5EN                RCC_APB1ENR_UART5EN_Msk             
#define RCC_APB1ENR_I2C1EN_Pos             (21U)                               
#define RCC_APB1ENR_I2C1EN_Msk             (0x1UL << RCC_APB1ENR_I2C1EN_Pos)    /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                 RCC_APB1ENR_I2C1EN_Msk              
#define RCC_APB1ENR_I2C2EN_Pos             (22U)                               
#define RCC_APB1ENR_I2C2EN_Msk             (0x1UL << RCC_APB1ENR_I2C2EN_Pos)    /*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN                 RCC_APB1ENR_I2C2EN_Msk              
#define RCC_APB1ENR_I2C3EN_Pos             (23U)                               
#define RCC_APB1ENR_I2C3EN_Msk             (0x1UL << RCC_APB1ENR_I2C3EN_Pos)    /*!< 0x00800000 */
#define RCC_APB1ENR_I2C3EN                 RCC_APB1ENR_I2C3EN_Msk              
#define RCC_APB1ENR_I2C4EN_Pos             (24U)
#define RCC_APB1ENR_I2C4EN_Msk             (0x1UL << RCC_APB1ENR_I2C4EN_Pos)    /*!< 0x01000000 */
#define RCC_APB1ENR_I2C4EN                 RCC_APB1ENR_I2C4EN_Msk
#define RCC_APB1ENR_CAN1EN_Pos             (25U)                               
#define RCC_APB1ENR_CAN1EN_Msk             (0x1UL << RCC_APB1ENR_CAN1EN_Pos)    /*!< 0x02000000 */
#define RCC_APB1ENR_CAN1EN                 RCC_APB1ENR_CAN1EN_Msk              
#define RCC_APB1ENR_CAN2EN_Pos             (26U)                               
#define RCC_APB1ENR_CAN2EN_Msk             (0x1UL << RCC_APB1ENR_CAN2EN_Pos)    /*!< 0x04000000 */
#define RCC_APB1ENR_CAN2EN                 RCC_APB1ENR_CAN2EN_Msk              
#define RCC_APB1ENR_PWREN_Pos              (28U)                               
#define RCC_APB1ENR_PWREN_Msk              (0x1UL << RCC_APB1ENR_PWREN_Pos)     /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                  RCC_APB1ENR_PWREN_Msk               
#define RCC_APB1ENR_DACEN_Pos              (29U)                               
#define RCC_APB1ENR_DACEN_Msk              (0x1UL << RCC_APB1ENR_DACEN_Pos)     /*!< 0x20000000 */
#define RCC_APB1ENR_DACEN                  RCC_APB1ENR_DACEN_Msk               
#define RCC_APB1ENR_UART7EN_Pos            (30U)                               
#define RCC_APB1ENR_UART7EN_Msk            (0x1UL << RCC_APB1ENR_UART7EN_Pos)   /*!< 0x40000000 */
#define RCC_APB1ENR_UART7EN                RCC_APB1ENR_UART7EN_Msk             
#define RCC_APB1ENR_UART8EN_Pos            (31U)                               
#define RCC_APB1ENR_UART8EN_Msk            (0x1UL << RCC_APB1ENR_UART8EN_Pos)   /*!< 0x80000000 */
#define RCC_APB1ENR_UART8EN                RCC_APB1ENR_UART8EN_Msk             

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_TIM1EN_Pos             (0U)                                
#define RCC_APB2ENR_TIM1EN_Msk             (0x1UL << RCC_APB2ENR_TIM1EN_Pos)    /*!< 0x00000001 */
#define RCC_APB2ENR_TIM1EN                 RCC_APB2ENR_TIM1EN_Msk              
#define RCC_APB2ENR_TIM8EN_Pos             (1U)                                
#define RCC_APB2ENR_TIM8EN_Msk             (0x1UL << RCC_APB2ENR_TIM8EN_Pos)    /*!< 0x00000002 */
#define RCC_APB2ENR_TIM8EN                 RCC_APB2ENR_TIM8EN_Msk              
#define RCC_APB2ENR_USART1EN_Pos           (4U)                                
#define RCC_APB2ENR_USART1EN_Msk           (0x1UL << RCC_APB2ENR_USART1EN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_USART1EN               RCC_APB2ENR_USART1EN_Msk            
#define RCC_APB2ENR_USART6EN_Pos           (5U)                                
#define RCC_APB2ENR_USART6EN_Msk           (0x1UL << RCC_APB2ENR_USART6EN_Pos)  /*!< 0x00000020 */
#define RCC_APB2ENR_USART6EN               RCC_APB2ENR_USART6EN_Msk            
#define RCC_APB2ENR_ADC1EN_Pos             (8U)                                
#define RCC_APB2ENR_ADC1EN_Msk             (0x1UL << RCC_APB2ENR_ADC1EN_Pos)    /*!< 0x00000100 */
#define RCC_APB2ENR_ADC1EN                 RCC_APB2ENR_ADC1EN_Msk              
#define RCC_APB2ENR_ADC2EN_Pos             (9U)                                
#define RCC_APB2ENR_ADC2EN_Msk             (0x1UL << RCC_APB2ENR_ADC2EN_Pos)    /*!< 0x00000200 */
#define RCC_APB2ENR_ADC2EN                 RCC_APB2ENR_ADC2EN_Msk              
#define RCC_APB2ENR_ADC3EN_Pos             (10U)                               
#define RCC_APB2ENR_ADC3EN_Msk             (0x1UL << RCC_APB2ENR_ADC3EN_Pos)    /*!< 0x00000400 */
#define RCC_APB2ENR_ADC3EN                 RCC_APB2ENR_ADC3EN_Msk              
#define RCC_APB2ENR_SDIOEN_Pos             (11U)                               
#define RCC_APB2ENR_SDIOEN_Msk             (0x1UL << RCC_APB2ENR_SDIOEN_Pos)    /*!< 0x00000800 */
#define RCC_APB2ENR_SDIOEN                 RCC_APB2ENR_SDIOEN_Msk              
#define RCC_APB2ENR_SPI1EN_Pos             (12U)                               
#define RCC_APB2ENR_SPI1EN_Msk             (0x1UL << RCC_APB2ENR_SPI1EN_Pos)    /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                 RCC_APB2ENR_SPI1EN_Msk              
#define RCC_APB2ENR_SPI4EN_Pos             (13U)                               
#define RCC_APB2ENR_SPI4EN_Msk             (0x1UL << RCC_APB2ENR_SPI4EN_Pos)    /*!< 0x00002000 */
#define RCC_APB2ENR_SPI4EN                 RCC_APB2ENR_SPI4EN_Msk              
#define RCC_APB2ENR_SYSCFGEN_Pos           (14U)                               
#define RCC_APB2ENR_SYSCFGEN_Msk           (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)  /*!< 0x00004000 */
#define RCC_APB2ENR_SYSCFGEN               RCC_APB2ENR_SYSCFGEN_Msk            
#define RCC_APB2ENR_TIM9EN_Pos             (16U)                               
#define RCC_APB2ENR_TIM9EN_Msk             (0x1UL << RCC_APB2ENR_TIM9EN_Pos)    /*!< 0x00010000 */
#define RCC_APB2ENR_TIM9EN                 RCC_APB2ENR_TIM9EN_Msk              
#define RCC_APB2ENR_TIM10EN_Pos            (17U)                               
#define RCC_APB2ENR_TIM10EN_Msk            (0x1UL << RCC_APB2ENR_TIM10EN_Pos)   /*!< 0x00020000 */
#define RCC_APB2ENR_TIM10EN                RCC_APB2ENR_TIM10EN_Msk             
#define RCC_APB2ENR_TIM11EN_Pos            (18U)                               
#define RCC_APB2ENR_TIM11EN_Msk            (0x1UL << RCC_APB2ENR_TIM11EN_Pos)   /*!< 0x00040000 */
#define RCC_APB2ENR_TIM11EN                RCC_APB2ENR_TIM11EN_Msk             
#define RCC_APB2ENR_SPI5EN_Pos             (20U)                               
#define RCC_APB2ENR_SPI5EN_Msk             (0x1UL << RCC_APB2ENR_SPI5EN_Pos)    /*!< 0x00100000 */
#define RCC_APB2ENR_SPI5EN                 RCC_APB2ENR_SPI5EN_Msk              
#define RCC_APB2ENR_SPI6EN_Pos             (21U)                               
#define RCC_APB2ENR_SPI6EN_Msk             (0x1UL << RCC_APB2ENR_SPI6EN_Pos)    /*!< 0x00200000 */
#define RCC_APB2ENR_SPI6EN                 RCC_APB2ENR_SPI6EN_Msk              
#define RCC_APB2ENR_SAI1EN_Pos             (22U)                               
#define RCC_APB2ENR_SAI1EN_Msk             (0x1UL << RCC_APB2ENR_SAI1EN_Pos)    /*!< 0x00400000 */
#define RCC_APB2ENR_SAI1EN                 RCC_APB2ENR_SAI1EN_Msk              
#define RCC_APB2ENR_LTDCEN_Pos             (26U)                               
#define RCC_APB2ENR_LTDCEN_Msk             (0x1UL << RCC_APB2ENR_LTDCEN_Pos)    /*!< 0x04000000 */
#define RCC_APB2ENR_LTDCEN                 RCC_APB2ENR_LTDCEN_Msk              
#define RCC_APB2ENR_DSIEN_Pos              (27U)                               
#define RCC_APB2ENR_DSIEN_Msk              (0x1UL << RCC_APB2ENR_DSIEN_Pos)     /*!< 0x08000000 */
#define RCC_APB2ENR_DSIEN                  RCC_APB2ENR_DSIEN_Msk               

/********************  Bit definition for RCC_AHB1LPENR register  *************/
#define RCC_AHB1LPENR_GPIOALPEN_Pos        (0U)                                
#define RCC_AHB1LPENR_GPIOALPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOALPEN_Pos) /*!< 0x00000001 */
#define RCC_AHB1LPENR_GPIOALPEN            RCC_AHB1LPENR_GPIOALPEN_Msk         
#define RCC_AHB1LPENR_GPIOBLPEN_Pos        (1U)                                
#define RCC_AHB1LPENR_GPIOBLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOBLPEN_Pos) /*!< 0x00000002 */
#define RCC_AHB1LPENR_GPIOBLPEN            RCC_AHB1LPENR_GPIOBLPEN_Msk         
#define RCC_AHB1LPENR_GPIOCLPEN_Pos        (2U)                                
#define RCC_AHB1LPENR_GPIOCLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOCLPEN_Pos) /*!< 0x00000004 */
#define RCC_AHB1LPENR_GPIOCLPEN            RCC_AHB1LPENR_GPIOCLPEN_Msk         
#define RCC_AHB1LPENR_GPIODLPEN_Pos        (3U)                                
#define RCC_AHB1LPENR_GPIODLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIODLPEN_Pos) /*!< 0x00000008 */
#define RCC_AHB1LPENR_GPIODLPEN            RCC_AHB1LPENR_GPIODLPEN_Msk         
#define RCC_AHB1LPENR_GPIOELPEN_Pos        (4U)                                
#define RCC_AHB1LPENR_GPIOELPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOELPEN_Pos) /*!< 0x00000010 */
#define RCC_AHB1LPENR_GPIOELPEN            RCC_AHB1LPENR_GPIOELPEN_Msk         
#define RCC_AHB1LPENR_GPIOFLPEN_Pos        (5U)                                
#define RCC_AHB1LPENR_GPIOFLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOFLPEN_Pos) /*!< 0x00000020 */
#define RCC_AHB1LPENR_GPIOFLPEN            RCC_AHB1LPENR_GPIOFLPEN_Msk         
#define RCC_AHB1LPENR_GPIOGLPEN_Pos        (6U)                                
#define RCC_AHB1LPENR_GPIOGLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOGLPEN_Pos) /*!< 0x00000040 */
#define RCC_AHB1LPENR_GPIOGLPEN            RCC_AHB1LPENR_GPIOGLPEN_Msk         
#define RCC_AHB1LPENR_GPIOHLPEN_Pos        (7U)                                
#define RCC_AHB1LPENR_GPIOHLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOHLPEN_Pos) /*!< 0x00000080 */
#define RCC_AHB1LPENR_GPIOHLPEN            RCC_AHB1LPENR_GPIOHLPEN_Msk         
#define RCC_AHB1LPENR_GPIOILPEN_Pos        (8U)                                
#define RCC_AHB1LPENR_GPIOILPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOILPEN_Pos) /*!< 0x00000100 */
#define RCC_AHB1LPENR_GPIOILPEN            RCC_AHB1LPENR_GPIOILPEN_Msk         
#define RCC_AHB1LPENR_GPIOJLPEN_Pos        (9U)                                
#define RCC_AHB1LPENR_GPIOJLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOJLPEN_Pos) /*!< 0x00000200 */
#define RCC_AHB1LPENR_GPIOJLPEN            RCC_AHB1LPENR_GPIOJLPEN_Msk         
#define RCC_AHB1LPENR_GPIOKLPEN_Pos        (10U)                               
#define RCC_AHB1LPENR_GPIOKLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOKLPEN_Pos) /*!< 0x00000400 */
#define RCC_AHB1LPENR_GPIOKLPEN            RCC_AHB1LPENR_GPIOKLPEN_Msk         
#define RCC_AHB1LPENR_CRCLPEN_Pos          (12U)                               
#define RCC_AHB1LPENR_CRCLPEN_Msk          (0x1UL << RCC_AHB1LPENR_CRCLPEN_Pos) /*!< 0x00001000 */
#define RCC_AHB1LPENR_CRCLPEN              RCC_AHB1LPENR_CRCLPEN_Msk           
#define RCC_AHB1LPENR_FLITFLPEN_Pos        (15U)                               
#define RCC_AHB1LPENR_FLITFLPEN_Msk        (0x1UL << RCC_AHB1LPENR_FLITFLPEN_Pos) /*!< 0x00008000 */
#define RCC_AHB1LPENR_FLITFLPEN            RCC_AHB1LPENR_FLITFLPEN_Msk         
#define RCC_AHB1LPENR_SRAM1LPEN_Pos        (16U)                               
#define RCC_AHB1LPENR_SRAM1LPEN_Msk        (0x1UL << RCC_AHB1LPENR_SRAM1LPEN_Pos) /*!< 0x00010000 */
#define RCC_AHB1LPENR_SRAM1LPEN            RCC_AHB1LPENR_SRAM1LPEN_Msk         
#define RCC_AHB1LPENR_SRAM2LPEN_Pos        (17U)                               
#define RCC_AHB1LPENR_SRAM2LPEN_Msk        (0x1UL << RCC_AHB1LPENR_SRAM2LPEN_Pos) /*!< 0x00020000 */
#define RCC_AHB1LPENR_SRAM2LPEN            RCC_AHB1LPENR_SRAM2LPEN_Msk         
#define RCC_AHB1LPENR_BKPSRAMLPEN_Pos      (18U)                               
#define RCC_AHB1LPENR_BKPSRAMLPEN_Msk      (0x1UL << RCC_AHB1LPENR_BKPSRAMLPEN_Pos) /*!< 0x00040000 */
#define RCC_AHB1LPENR_BKPSRAMLPEN          RCC_AHB1LPENR_BKPSRAMLPEN_Msk       
#define RCC_AHB1LPENR_SRAM3LPEN_Pos        (19U)                               
#define RCC_AHB1LPENR_SRAM3LPEN_Msk        (0x1UL << RCC_AHB1LPENR_SRAM3LPEN_Pos) /*!< 0x00080000 */
#define RCC_AHB1LPENR_SRAM3LPEN            RCC_AHB1LPENR_SRAM3LPEN_Msk         
#define RCC_AHB1LPENR_DMA1LPEN_Pos         (21U)                               
#define RCC_AHB1LPENR_DMA1LPEN_Msk         (0x1UL << RCC_AHB1LPENR_DMA1LPEN_Pos) /*!< 0x00200000 */
#define RCC_AHB1LPENR_DMA1LPEN             RCC_AHB1LPENR_DMA1LPEN_Msk          
#define RCC_AHB1LPENR_DMA2LPEN_Pos         (22U)                               
#define RCC_AHB1LPENR_DMA2LPEN_Msk         (0x1UL << RCC_AHB1LPENR_DMA2LPEN_Pos) /*!< 0x00400000 */
#define RCC_AHB1LPENR_DMA2LPEN             RCC_AHB1LPENR_DMA2LPEN_Msk          
#define RCC_AHB1LPENR_DMA2DLPEN_Pos        (23U)                               
#define RCC_AHB1LPENR_DMA2DLPEN_Msk        (0x1UL << RCC_AHB1LPENR_DMA2DLPEN_Pos) /*!< 0x00800000 */
#define RCC_AHB1LPENR_DMA2DLPEN            RCC_AHB1LPENR_DMA2DLPEN_Msk         

#define RCC_AHB1LPENR_ETHMACLPEN_Pos       (25U)                               
#define RCC_AHB1LPENR_ETHMACLPEN_Msk       (0x1UL << RCC_AHB1LPENR_ETHMACLPEN_Pos) /*!< 0x02000000 */
#define RCC_AHB1LPENR_ETHMACLPEN           RCC_AHB1LPENR_ETHMACLPEN_Msk        
#define RCC_AHB1LPENR_ETHMACTXLPEN_Pos     (26U)                               
#define RCC_AHB1LPENR_ETHMACTXLPEN_Msk     (0x1UL << RCC_AHB1LPENR_ETHMACTXLPEN_Pos) /*!< 0x04000000 */
#define RCC_AHB1LPENR_ETHMACTXLPEN         RCC_AHB1LPENR_ETHMACTXLPEN_Msk      
#define RCC_AHB1LPENR_ETHMACRXLPEN_Pos     (27U)                               
#define RCC_AHB1LPENR_ETHMACRXLPEN_Msk     (0x1UL << RCC_AHB1LPENR_ETHMACRXLPEN_Pos) /*!< 0x08000000 */
#define RCC_AHB1LPENR_ETHMACRXLPEN         RCC_AHB1LPENR_ETHMACRXLPEN_Msk      
#define RCC_AHB1LPENR_ETHMACPTPLPEN_Pos    (28U)                               
#define RCC_AHB1LPENR_ETHMACPTPLPEN_Msk    (0x1UL << RCC_AHB1LPENR_ETHMACPTPLPEN_Pos) /*!< 0x10000000 */
#define RCC_AHB1LPENR_ETHMACPTPLPEN        RCC_AHB1LPENR_ETHMACPTPLPEN_Msk     
#define RCC_AHB1LPENR_OTGHSLPEN_Pos        (29U)                               
#define RCC_AHB1LPENR_OTGHSLPEN_Msk        (0x1UL << RCC_AHB1LPENR_OTGHSLPEN_Pos) /*!< 0x20000000 */
#define RCC_AHB1LPENR_OTGHSLPEN            RCC_AHB1LPENR_OTGHSLPEN_Msk         
#define RCC_AHB1LPENR_OTGHSULPILPEN_Pos    (30U)                               
#define RCC_AHB1LPENR_OTGHSULPILPEN_Msk    (0x1UL << RCC_AHB1LPENR_OTGHSULPILPEN_Pos) /*!< 0x40000000 */
#define RCC_AHB1LPENR_OTGHSULPILPEN        RCC_AHB1LPENR_OTGHSULPILPEN_Msk     

/********************  Bit definition for RCC_AHB2LPENR register  *************/
#define RCC_AHB2LPENR_DCMILPEN_Pos         (0U)                                
#define RCC_AHB2LPENR_DCMILPEN_Msk         (0x1UL << RCC_AHB2LPENR_DCMILPEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2LPENR_DCMILPEN             RCC_AHB2LPENR_DCMILPEN_Msk          
#define RCC_AHB2LPENR_CRYPLPEN_Pos         (4U)                                
#define RCC_AHB2LPENR_CRYPLPEN_Msk         (0x1UL << RCC_AHB2LPENR_CRYPLPEN_Pos) /*!< 0x00000010 */
#define RCC_AHB2LPENR_CRYPLPEN             RCC_AHB2LPENR_CRYPLPEN_Msk          
#define RCC_AHB2LPENR_HASHLPEN_Pos         (5U)                                
#define RCC_AHB2LPENR_HASHLPEN_Msk         (0x1UL << RCC_AHB2LPENR_HASHLPEN_Pos) /*!< 0x00000020 */
#define RCC_AHB2LPENR_HASHLPEN             RCC_AHB2LPENR_HASHLPEN_Msk          
#define RCC_AHB2LPENR_RNGLPEN_Pos          (6U)                                
#define RCC_AHB2LPENR_RNGLPEN_Msk          (0x1UL << RCC_AHB2LPENR_RNGLPEN_Pos) /*!< 0x00000040 */
#define RCC_AHB2LPENR_RNGLPEN              RCC_AHB2LPENR_RNGLPEN_Msk           
#define RCC_AHB2LPENR_OTGFSLPEN_Pos        (7U)                                
#define RCC_AHB2LPENR_OTGFSLPEN_Msk        (0x1UL << RCC_AHB2LPENR_OTGFSLPEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2LPENR_OTGFSLPEN            RCC_AHB2LPENR_OTGFSLPEN_Msk         

/********************  Bit definition for RCC_AHB3LPENR register  *************/
#define RCC_AHB3LPENR_FMCLPEN_Pos          (0U)                                
#define RCC_AHB3LPENR_FMCLPEN_Msk          (0x1UL << RCC_AHB3LPENR_FMCLPEN_Pos) /*!< 0x00000001 */
#define RCC_AHB3LPENR_FMCLPEN              RCC_AHB3LPENR_FMCLPEN_Msk           
#define RCC_AHB3LPENR_QSPILPEN_Pos         (1U)                                
#define RCC_AHB3LPENR_QSPILPEN_Msk         (0x1UL << RCC_AHB3LPENR_QSPILPEN_Pos) /*!< 0x00000002 */
#define RCC_AHB3LPENR_QSPILPEN             RCC_AHB3LPENR_QSPILPEN_Msk          

/********************  Bit definition for RCC_APB1LPENR register  *************/
#define RCC_APB1LPENR_TIM2LPEN_Pos         (0U)                                
#define RCC_APB1LPENR_TIM2LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM2LPEN_Pos) /*!< 0x00000001 */
#define RCC_APB1LPENR_TIM2LPEN             RCC_APB1LPENR_TIM2LPEN_Msk          
#define RCC_APB1LPENR_TIM3LPEN_Pos         (1U)                                
#define RCC_APB1LPENR_TIM3LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM3LPEN_Pos) /*!< 0x00000002 */
#define RCC_APB1LPENR_TIM3LPEN             RCC_APB1LPENR_TIM3LPEN_Msk          
#define RCC_APB1LPENR_TIM4LPEN_Pos         (2U)                                
#define RCC_APB1LPENR_TIM4LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM4LPEN_Pos) /*!< 0x00000004 */
#define RCC_APB1LPENR_TIM4LPEN             RCC_APB1LPENR_TIM4LPEN_Msk          
#define RCC_APB1LPENR_TIM5LPEN_Pos         (3U)                                
#define RCC_APB1LPENR_TIM5LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM5LPEN_Pos) /*!< 0x00000008 */
#define RCC_APB1LPENR_TIM5LPEN             RCC_APB1LPENR_TIM5LPEN_Msk          
#define RCC_APB1LPENR_TIM6LPEN_Pos         (4U)                                
#define RCC_APB1LPENR_TIM6LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM6LPEN_Pos) /*!< 0x00000010 */
#define RCC_APB1LPENR_TIM6LPEN             RCC_APB1LPENR_TIM6LPEN_Msk          
#define RCC_APB1LPENR_TIM7LPEN_Pos         (5U)                                
#define RCC_APB1LPENR_TIM7LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM7LPEN_Pos) /*!< 0x00000020 */
#define RCC_APB1LPENR_TIM7LPEN             RCC_APB1LPENR_TIM7LPEN_Msk          
#define RCC_APB1LPENR_TIM12LPEN_Pos        (6U)                                
#define RCC_APB1LPENR_TIM12LPEN_Msk        (0x1UL << RCC_APB1LPENR_TIM12LPEN_Pos) /*!< 0x00000040 */
#define RCC_APB1LPENR_TIM12LPEN            RCC_APB1LPENR_TIM12LPEN_Msk         
#define RCC_APB1LPENR_TIM13LPEN_Pos        (7U)                                
#define RCC_APB1LPENR_TIM13LPEN_Msk        (0x1UL << RCC_APB1LPENR_TIM13LPEN_Pos) /*!< 0x00000080 */
#define RCC_APB1LPENR_TIM13LPEN            RCC_APB1LPENR_TIM13LPEN_Msk         
#define RCC_APB1LPENR_TIM14LPEN_Pos        (8U)                                
#define RCC_APB1LPENR_TIM14LPEN_Msk        (0x1UL << RCC_APB1LPENR_TIM14LPEN_Pos) /*!< 0x00000100 */
#define RCC_APB1LPENR_TIM14LPEN            RCC_APB1LPENR_TIM14LPEN_Msk         
#define RCC_APB1LPENR_WWDGLPEN_Pos         (11U)                               
#define RCC_APB1LPENR_WWDGLPEN_Msk         (0x1UL << RCC_APB1LPENR_WWDGLPEN_Pos) /*!< 0x00000800 */
#define RCC_APB1LPENR_WWDGLPEN             RCC_APB1LPENR_WWDGLPEN_Msk          
#define RCC_APB1LPENR_SPI2LPEN_Pos         (14U)                               
#define RCC_APB1LPENR_SPI2LPEN_Msk         (0x1UL << RCC_APB1LPENR_SPI2LPEN_Pos) /*!< 0x00004000 */
#define RCC_APB1LPENR_SPI2LPEN             RCC_APB1LPENR_SPI2LPEN_Msk          
#define RCC_APB1LPENR_SPI3LPEN_Pos         (15U)                               
#define RCC_APB1LPENR_SPI3LPEN_Msk         (0x1UL << RCC_APB1LPENR_SPI3LPEN_Pos) /*!< 0x00008000 */
#define RCC_APB1LPENR_SPI3LPEN             RCC_APB1LPENR_SPI3LPEN_Msk          
#define RCC_APB1LPENR_USART2LPEN_Pos       (17U)                               
#define RCC_APB1LPENR_USART2LPEN_Msk       (0x1UL << RCC_APB1LPENR_USART2LPEN_Pos) /*!< 0x00020000 */
#define RCC_APB1LPENR_USART2LPEN           RCC_APB1LPENR_USART2LPEN_Msk        
#define RCC_APB1LPENR_USART3LPEN_Pos       (18U)                               
#define RCC_APB1LPENR_USART3LPEN_Msk       (0x1UL << RCC_APB1LPENR_USART3LPEN_Pos) /*!< 0x00040000 */
#define RCC_APB1LPENR_USART3LPEN           RCC_APB1LPENR_USART3LPEN_Msk        
#define RCC_APB1LPENR_UART4LPEN_Pos        (19U)                               
#define RCC_APB1LPENR_UART4LPEN_Msk        (0x1UL << RCC_APB1LPENR_UART4LPEN_Pos) /*!< 0x00080000 */
#define RCC_APB1LPENR_UART4LPEN            RCC_APB1LPENR_UART4LPEN_Msk         
#define RCC_APB1LPENR_UART5LPEN_Pos        (20U)                               
#define RCC_APB1LPENR_UART5LPEN_Msk        (0x1UL << RCC_APB1LPENR_UART5LPEN_Pos) /*!< 0x00100000 */
#define RCC_APB1LPENR_UART5LPEN            RCC_APB1LPENR_UART5LPEN_Msk         
#define RCC_APB1LPENR_I2C1LPEN_Pos         (21U)                               
#define RCC_APB1LPENR_I2C1LPEN_Msk         (0x1UL << RCC_APB1LPENR_I2C1LPEN_Pos) /*!< 0x00200000 */
#define RCC_APB1LPENR_I2C1LPEN             RCC_APB1LPENR_I2C1LPEN_Msk          
#define RCC_APB1LPENR_I2C2LPEN_Pos         (22U)                               
#define RCC_APB1LPENR_I2C2LPEN_Msk         (0x1UL << RCC_APB1LPENR_I2C2LPEN_Pos) /*!< 0x00400000 */
#define RCC_APB1LPENR_I2C2LPEN             RCC_APB1LPENR_I2C2LPEN_Msk          
#define RCC_APB1LPENR_I2C3LPEN_Pos         (23U)                               
#define RCC_APB1LPENR_I2C3LPEN_Msk         (0x1UL << RCC_APB1LPENR_I2C3LPEN_Pos) /*!< 0x00800000 */
#define RCC_APB1LPENR_I2C3LPEN             RCC_APB1LPENR_I2C3LPEN_Msk          
#define RCC_APB1LPENR_CAN1LPEN_Pos         (25U)                               
#define RCC_APB1LPENR_CAN1LPEN_Msk         (0x1UL << RCC_APB1LPENR_CAN1LPEN_Pos) /*!< 0x02000000 */
#define RCC_APB1LPENR_CAN1LPEN             RCC_APB1LPENR_CAN1LPEN_Msk          
#define RCC_APB1LPENR_CAN2LPEN_Pos         (26U)                               
#define RCC_APB1LPENR_CAN2LPEN_Msk         (0x1UL << RCC_APB1LPENR_CAN2LPEN_Pos) /*!< 0x04000000 */
#define RCC_APB1LPENR_CAN2LPEN             RCC_APB1LPENR_CAN2LPEN_Msk          
#define RCC_APB1LPENR_PWRLPEN_Pos          (28U)                               
#define RCC_APB1LPENR_PWRLPEN_Msk          (0x1UL << RCC_APB1LPENR_PWRLPEN_Pos) /*!< 0x10000000 */
#define RCC_APB1LPENR_PWRLPEN              RCC_APB1LPENR_PWRLPEN_Msk           
#define RCC_APB1LPENR_DACLPEN_Pos          (29U)                               
#define RCC_APB1LPENR_DACLPEN_Msk          (0x1UL << RCC_APB1LPENR_DACLPEN_Pos) /*!< 0x20000000 */
#define RCC_APB1LPENR_DACLPEN              RCC_APB1LPENR_DACLPEN_Msk           
#define RCC_APB1LPENR_UART7LPEN_Pos        (30U)                               
#define RCC_APB1LPENR_UART7LPEN_Msk        (0x1UL << RCC_APB1LPENR_UART7LPEN_Pos) /*!< 0x40000000 */
#define RCC_APB1LPENR_UART7LPEN            RCC_APB1LPENR_UART7LPEN_Msk         
#define RCC_APB1LPENR_UART8LPEN_Pos        (31U)                               
#define RCC_APB1LPENR_UART8LPEN_Msk        (0x1UL << RCC_APB1LPENR_UART8LPEN_Pos) /*!< 0x80000000 */
#define RCC_APB1LPENR_UART8LPEN            RCC_APB1LPENR_UART8LPEN_Msk         

/********************  Bit definition for RCC_APB2LPENR register  *************/
#define RCC_APB2LPENR_TIM1LPEN_Pos         (0U)                                
#define RCC_APB2LPENR_TIM1LPEN_Msk         (0x1UL << RCC_APB2LPENR_TIM1LPEN_Pos) /*!< 0x00000001 */
#define RCC_APB2LPENR_TIM1LPEN             RCC_APB2LPENR_TIM1LPEN_Msk          
#define RCC_APB2LPENR_TIM8LPEN_Pos         (1U)                                
#define RCC_APB2LPENR_TIM8LPEN_Msk         (0x1UL << RCC_APB2LPENR_TIM8LPEN_Pos) /*!< 0x00000002 */
#define RCC_APB2LPENR_TIM8LPEN             RCC_APB2LPENR_TIM8LPEN_Msk          
#define RCC_APB2LPENR_USART1LPEN_Pos       (4U)                                
#define RCC_APB2LPENR_USART1LPEN_Msk       (0x1UL << RCC_APB2LPENR_USART1LPEN_Pos) /*!< 0x00000010 */
#define RCC_APB2LPENR_USART1LPEN           RCC_APB2LPENR_USART1LPEN_Msk        
#define RCC_APB2LPENR_USART6LPEN_Pos       (5U)                                
#define RCC_APB2LPENR_USART6LPEN_Msk       (0x1UL << RCC_APB2LPENR_USART6LPEN_Pos) /*!< 0x00000020 */
#define RCC_APB2LPENR_USART6LPEN           RCC_APB2LPENR_USART6LPEN_Msk        
#define RCC_APB2LPENR_ADC1LPEN_Pos         (8U)                                
#define RCC_APB2LPENR_ADC1LPEN_Msk         (0x1UL << RCC_APB2LPENR_ADC1LPEN_Pos) /*!< 0x00000100 */
#define RCC_APB2LPENR_ADC1LPEN             RCC_APB2LPENR_ADC1LPEN_Msk          
#define RCC_APB2LPENR_ADC2LPEN_Pos         (9U)                                
#define RCC_APB2LPENR_ADC2LPEN_Msk         (0x1UL << RCC_APB2LPENR_ADC2LPEN_Pos) /*!< 0x00000200 */
#define RCC_APB2LPENR_ADC2LPEN             RCC_APB2LPENR_ADC2LPEN_Msk          
#define RCC_APB2LPENR_ADC3LPEN_Pos         (10U)                               
#define RCC_APB2LPENR_ADC3LPEN_Msk         (0x1UL << RCC_APB2LPENR_ADC3LPEN_Pos) /*!< 0x00000400 */
#define RCC_APB2LPENR_ADC3LPEN             RCC_APB2LPENR_ADC3LPEN_Msk          
#define RCC_APB2LPENR_SDIOLPEN_Pos         (11U)                               
#define RCC_APB2LPENR_SDIOLPEN_Msk         (0x1UL << RCC_APB2LPENR_SDIOLPEN_Pos) /*!< 0x00000800 */
#define RCC_APB2LPENR_SDIOLPEN             RCC_APB2LPENR_SDIOLPEN_Msk          
#define RCC_APB2LPENR_SPI1LPEN_Pos         (12U)                               
#define RCC_APB2LPENR_SPI1LPEN_Msk         (0x1UL << RCC_APB2LPENR_SPI1LPEN_Pos) /*!< 0x00001000 */
#define RCC_APB2LPENR_SPI1LPEN             RCC_APB2LPENR_SPI1LPEN_Msk          
#define RCC_APB2LPENR_SPI4LPEN_Pos         (13U)                               
#define RCC_APB2LPENR_SPI4LPEN_Msk         (0x1UL << RCC_APB2LPENR_SPI4LPEN_Pos) /*!< 0x00002000 */
#define RCC_APB2LPENR_SPI4LPEN             RCC_APB2LPENR_SPI4LPEN_Msk          
#define RCC_APB2LPENR_SYSCFGLPEN_Pos       (14U)                               
#define RCC_APB2LPENR_SYSCFGLPEN_Msk       (0x1UL << RCC_APB2LPENR_SYSCFGLPEN_Pos) /*!< 0x00004000 */
#define RCC_APB2LPENR_SYSCFGLPEN           RCC_APB2LPENR_SYSCFGLPEN_Msk        
#define RCC_APB2LPENR_TIM9LPEN_Pos         (16U)                               
#define RCC_APB2LPENR_TIM9LPEN_Msk         (0x1UL << RCC_APB2LPENR_TIM9LPEN_Pos) /*!< 0x00010000 */
#define RCC_APB2LPENR_TIM9LPEN             RCC_APB2LPENR_TIM9LPEN_Msk          
#define RCC_APB2LPENR_TIM10LPEN_Pos        (17U)                               
#define RCC_APB2LPENR_TIM10LPEN_Msk        (0x1UL << RCC_APB2LPENR_TIM10LPEN_Pos) /*!< 0x00020000 */
#define RCC_APB2LPENR_TIM10LPEN            RCC_APB2LPENR_TIM10LPEN_Msk         
#define RCC_APB2LPENR_TIM11LPEN_Pos        (18U)                               
#define RCC_APB2LPENR_TIM11LPEN_Msk        (0x1UL << RCC_APB2LPENR_TIM11LPEN_Pos) /*!< 0x00040000 */
#define RCC_APB2LPENR_TIM11LPEN            RCC_APB2LPENR_TIM11LPEN_Msk         
#define RCC_APB2LPENR_SPI5LPEN_Pos         (20U)                               
#define RCC_APB2LPENR_SPI5LPEN_Msk         (0x1UL << RCC_APB2LPENR_SPI5LPEN_Pos) /*!< 0x00100000 */
#define RCC_APB2LPENR_SPI5LPEN             RCC_APB2LPENR_SPI5LPEN_Msk          
#define RCC_APB2LPENR_SPI6LPEN_Pos         (21U)                               
#define RCC_APB2LPENR_SPI6LPEN_Msk         (0x1UL << RCC_APB2LPENR_SPI6LPEN_Pos) /*!< 0x00200000 */
#define RCC_APB2LPENR_SPI6LPEN             RCC_APB2LPENR_SPI6LPEN_Msk          
#define RCC_APB2LPENR_SAI1LPEN_Pos         (22U)                               
#define RCC_APB2LPENR_SAI1LPEN_Msk         (0x1UL << RCC_APB2LPENR_SAI1LPEN_Pos) /*!< 0x00400000 */
#define RCC_APB2LPENR_SAI1LPEN             RCC_APB2LPENR_SAI1LPEN_Msk          
#define RCC_APB2LPENR_LTDCLPEN_Pos         (26U)                               
#define RCC_APB2LPENR_LTDCLPEN_Msk         (0x1UL << RCC_APB2LPENR_LTDCLPEN_Pos) /*!< 0x04000000 */
#define RCC_APB2LPENR_LTDCLPEN             RCC_APB2LPENR_LTDCLPEN_Msk          
#define RCC_APB2LPENR_DSILPEN_Pos          (27U)                               
#define RCC_APB2LPENR_DSILPEN_Msk          (0x1UL << RCC_APB2LPENR_DSILPEN_Pos) /*!< 0x08000000 */
#define RCC_APB2LPENR_DSILPEN              RCC_APB2LPENR_DSILPEN_Msk           

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                 (0U)                                
#define RCC_BDCR_LSEON_Msk                 (0x1UL << RCC_BDCR_LSEON_Pos)        /*!< 0x00000001 */
#define RCC_BDCR_LSEON                     RCC_BDCR_LSEON_Msk                  
#define RCC_BDCR_LSERDY_Pos                (1U)                                
#define RCC_BDCR_LSERDY_Msk                (0x1UL << RCC_BDCR_LSERDY_Pos)       /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                    RCC_BDCR_LSERDY_Msk                 
#define RCC_BDCR_LSEBYP_Pos                (2U)                                
#define RCC_BDCR_LSEBYP_Msk                (0x1UL << RCC_BDCR_LSEBYP_Pos)       /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                    RCC_BDCR_LSEBYP_Msk                 
#define RCC_BDCR_LSEMOD_Pos                (3U)                                
#define RCC_BDCR_LSEMOD_Msk                (0x1UL << RCC_BDCR_LSEMOD_Pos)       /*!< 0x00000008 */
#define RCC_BDCR_LSEMOD                    RCC_BDCR_LSEMOD_Msk                 

#define RCC_BDCR_RTCSEL_Pos                (8U)                                
#define RCC_BDCR_RTCSEL_Msk                (0x3UL << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                    RCC_BDCR_RTCSEL_Msk                 
#define RCC_BDCR_RTCSEL_0                  (0x1UL << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                  (0x2UL << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000200 */

#define RCC_BDCR_RTCEN_Pos                 (15U)                               
#define RCC_BDCR_RTCEN_Msk                 (0x1UL << RCC_BDCR_RTCEN_Pos)        /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                     RCC_BDCR_RTCEN_Msk                  
#define RCC_BDCR_BDRST_Pos                 (16U)                               
#define RCC_BDCR_BDRST_Msk                 (0x1UL << RCC_BDCR_BDRST_Pos)        /*!< 0x00010000 */
#define RCC_BDCR_BDRST                     RCC_BDCR_BDRST_Msk                  

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                  (0U)                                
#define RCC_CSR_LSION_Msk                  (0x1UL << RCC_CSR_LSION_Pos)         /*!< 0x00000001 */
#define RCC_CSR_LSION                      RCC_CSR_LSION_Msk                   
#define RCC_CSR_LSIRDY_Pos                 (1U)                                
#define RCC_CSR_LSIRDY_Msk                 (0x1UL << RCC_CSR_LSIRDY_Pos)        /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                     RCC_CSR_LSIRDY_Msk                  
#define RCC_CSR_RMVF_Pos                   (24U)                               
#define RCC_CSR_RMVF_Msk                   (0x1UL << RCC_CSR_RMVF_Pos)          /*!< 0x01000000 */
#define RCC_CSR_RMVF                       RCC_CSR_RMVF_Msk                    
#define RCC_CSR_BORRSTF_Pos                (25U)                               
#define RCC_CSR_BORRSTF_Msk                (0x1UL << RCC_CSR_BORRSTF_Pos)       /*!< 0x02000000 */
#define RCC_CSR_BORRSTF                    RCC_CSR_BORRSTF_Msk                 
#define RCC_CSR_PINRSTF_Pos                (26U)
#define RCC_CSR_PINRSTF_Msk                (0x1UL << RCC_CSR_PINRSTF_Pos)       /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                    RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PORRSTF_Pos                (27U)                               
#define RCC_CSR_PORRSTF_Msk                (0x1UL << RCC_CSR_PORRSTF_Pos)       /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                    RCC_CSR_PORRSTF_Msk                 
#define RCC_CSR_SFTRSTF_Pos                (28U)                               
#define RCC_CSR_SFTRSTF_Msk                (0x1UL << RCC_CSR_SFTRSTF_Pos)       /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                    RCC_CSR_SFTRSTF_Msk                 
#define RCC_CSR_IWDGRSTF_Pos               (29U)
#define RCC_CSR_IWDGRSTF_Msk               (0x1UL << RCC_CSR_IWDGRSTF_Pos)      /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                   RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos               (30U)                               
#define RCC_CSR_WWDGRSTF_Msk               (0x1UL << RCC_CSR_WWDGRSTF_Pos)      /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                   RCC_CSR_WWDGRSTF_Msk                
#define RCC_CSR_LPWRRSTF_Pos               (31U)                               
#define RCC_CSR_LPWRRSTF_Msk               (0x1UL << RCC_CSR_LPWRRSTF_Pos)      /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                   RCC_CSR_LPWRRSTF_Msk
/* Legacy defines */
#define RCC_CSR_PADRSTF                    RCC_CSR_PINRSTF
#define RCC_CSR_WDGRSTF                    RCC_CSR_IWDGRSTF

/********************  Bit definition for RCC_SSCGR register  *****************/
#define RCC_SSCGR_MODPER_Pos               (0U)                                
#define RCC_SSCGR_MODPER_Msk               (0x1FFFUL << RCC_SSCGR_MODPER_Pos)   /*!< 0x00001FFF */
#define RCC_SSCGR_MODPER                   RCC_SSCGR_MODPER_Msk                
#define RCC_SSCGR_INCSTEP_Pos              (13U)                               
#define RCC_SSCGR_INCSTEP_Msk              (0x7FFFUL << RCC_SSCGR_INCSTEP_Pos)  /*!< 0x0FFFE000 */
#define RCC_SSCGR_INCSTEP                  RCC_SSCGR_INCSTEP_Msk               
#define RCC_SSCGR_SPREADSEL_Pos            (30U)                               
#define RCC_SSCGR_SPREADSEL_Msk            (0x1UL << RCC_SSCGR_SPREADSEL_Pos)   /*!< 0x40000000 */
#define RCC_SSCGR_SPREADSEL                RCC_SSCGR_SPREADSEL_Msk             
#define RCC_SSCGR_SSCGEN_Pos               (31U)                               
#define RCC_SSCGR_SSCGEN_Msk               (0x1UL << RCC_SSCGR_SSCGEN_Pos)      /*!< 0x80000000 */
#define RCC_SSCGR_SSCGEN                   RCC_SSCGR_SSCGEN_Msk                

/********************  Bit definition for RCC_PLLI2SCFGR register  ************/
#define RCC_PLLI2SCFGR_PLLI2SN_Pos         (6U)
#define RCC_PLLI2SCFGR_PLLI2SN_Msk         (0x1FFUL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00007FC0 */
#define RCC_PLLI2SCFGR_PLLI2SN             RCC_PLLI2SCFGR_PLLI2SN_Msk
#define RCC_PLLI2SCFGR_PLLI2SN_0           (0x001UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000040 */
#define RCC_PLLI2SCFGR_PLLI2SN_1           (0x002UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000080 */
#define RCC_PLLI2SCFGR_PLLI2SN_2           (0x004UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000100 */
#define RCC_PLLI2SCFGR_PLLI2SN_3           (0x008UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000200 */
#define RCC_PLLI2SCFGR_PLLI2SN_4           (0x010UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000400 */
#define RCC_PLLI2SCFGR_PLLI2SN_5           (0x020UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000800 */
#define RCC_PLLI2SCFGR_PLLI2SN_6           (0x040UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00001000 */
#define RCC_PLLI2SCFGR_PLLI2SN_7           (0x080UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00002000 */
#define RCC_PLLI2SCFGR_PLLI2SN_8           (0x100UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00004000 */
#define RCC_PLLI2SCFGR_PLLI2SP_Pos         (16U)
#define RCC_PLLI2SCFGR_PLLI2SP_Msk         (0x3UL << RCC_PLLI2SCFGR_PLLI2SP_Pos) /*!< 0x00030000 */
#define RCC_PLLI2SCFGR_PLLI2SP             RCC_PLLI2SCFGR_PLLI2SP_Msk
#define RCC_PLLI2SCFGR_PLLI2SP_0           (0x1UL << RCC_PLLI2SCFGR_PLLI2SP_Pos) /*!< 0x00010000 */
#define RCC_PLLI2SCFGR_PLLI2SP_1           (0x2UL << RCC_PLLI2SCFGR_PLLI2SP_Pos) /*!< 0x00020000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_Pos         (24U)
#define RCC_PLLI2SCFGR_PLLI2SQ_Msk         (0xFUL << RCC_PLLI2SCFGR_PLLI2SQ_Pos) /*!< 0x0F000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ             RCC_PLLI2SCFGR_PLLI2SQ_Msk
#define RCC_PLLI2SCFGR_PLLI2SQ_0           (0x1UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos) /*!< 0x01000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_1           (0x2UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos) /*!< 0x02000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_2           (0x4UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos) /*!< 0x04000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_3           (0x8UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos) /*!< 0x08000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_Pos         (28U)
#define RCC_PLLI2SCFGR_PLLI2SR_Msk         (0x7UL << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x70000000 */
#define RCC_PLLI2SCFGR_PLLI2SR             RCC_PLLI2SCFGR_PLLI2SR_Msk
#define RCC_PLLI2SCFGR_PLLI2SR_0           (0x1UL << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x10000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_1           (0x2UL << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x20000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_2           (0x4UL << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x40000000 */

/********************  Bit definition for RCC_PLLSAICFGR register  ************/
#define RCC_PLLSAICFGR_PLLSAIN_Pos         (6U)                                
#define RCC_PLLSAICFGR_PLLSAIN_Msk         (0x1FFUL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00007FC0 */
#define RCC_PLLSAICFGR_PLLSAIN             RCC_PLLSAICFGR_PLLSAIN_Msk          
#define RCC_PLLSAICFGR_PLLSAIN_0           (0x001UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00000040 */
#define RCC_PLLSAICFGR_PLLSAIN_1           (0x002UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00000080 */
#define RCC_PLLSAICFGR_PLLSAIN_2           (0x004UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00000100 */
#define RCC_PLLSAICFGR_PLLSAIN_3           (0x008UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00000200 */
#define RCC_PLLSAICFGR_PLLSAIN_4           (0x010UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00000400 */
#define RCC_PLLSAICFGR_PLLSAIN_5           (0x020UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00000800 */
#define RCC_PLLSAICFGR_PLLSAIN_6           (0x040UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00001000 */
#define RCC_PLLSAICFGR_PLLSAIN_7           (0x080UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00002000 */
#define RCC_PLLSAICFGR_PLLSAIN_8           (0x100UL << RCC_PLLSAICFGR_PLLSAIN_Pos) /*!< 0x00004000 */

#define RCC_PLLSAICFGR_PLLSAIP_Pos         (16U)                               
#define RCC_PLLSAICFGR_PLLSAIP_Msk         (0x3UL << RCC_PLLSAICFGR_PLLSAIP_Pos) /*!< 0x00030000 */
#define RCC_PLLSAICFGR_PLLSAIP             RCC_PLLSAICFGR_PLLSAIP_Msk          
#define RCC_PLLSAICFGR_PLLSAIP_0           (0x1UL << RCC_PLLSAICFGR_PLLSAIP_Pos) /*!< 0x00010000 */
#define RCC_PLLSAICFGR_PLLSAIP_1           (0x2UL << RCC_PLLSAICFGR_PLLSAIP_Pos) /*!< 0x00020000 */

#define RCC_PLLSAICFGR_PLLSAIQ_Pos         (24U)                               
#define RCC_PLLSAICFGR_PLLSAIQ_Msk         (0xFUL << RCC_PLLSAICFGR_PLLSAIQ_Pos) /*!< 0x0F000000 */
#define RCC_PLLSAICFGR_PLLSAIQ             RCC_PLLSAICFGR_PLLSAIQ_Msk          
#define RCC_PLLSAICFGR_PLLSAIQ_0           (0x1UL << RCC_PLLSAICFGR_PLLSAIQ_Pos) /*!< 0x01000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_1           (0x2UL << RCC_PLLSAICFGR_PLLSAIQ_Pos) /*!< 0x02000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_2           (0x4UL << RCC_PLLSAICFGR_PLLSAIQ_Pos) /*!< 0x04000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_3           (0x8UL << RCC_PLLSAICFGR_PLLSAIQ_Pos) /*!< 0x08000000 */

#define RCC_PLLSAICFGR_PLLSAIR_Pos         (28U)                               
#define RCC_PLLSAICFGR_PLLSAIR_Msk         (0x7UL << RCC_PLLSAICFGR_PLLSAIR_Pos) /*!< 0x70000000 */
#define RCC_PLLSAICFGR_PLLSAIR             RCC_PLLSAICFGR_PLLSAIR_Msk          
#define RCC_PLLSAICFGR_PLLSAIR_0           (0x1UL << RCC_PLLSAICFGR_PLLSAIR_Pos) /*!< 0x10000000 */
#define RCC_PLLSAICFGR_PLLSAIR_1           (0x2UL << RCC_PLLSAICFGR_PLLSAIR_Pos) /*!< 0x20000000 */
#define RCC_PLLSAICFGR_PLLSAIR_2           (0x4UL << RCC_PLLSAICFGR_PLLSAIR_Pos) /*!< 0x40000000 */

#if defined(STM32F4) || defined(GD32F4)
/********************  Bit definition for RCC_DCKCFGR register  ***************/
#define RCC_DCKCFGR_PLLI2SDIVQ_Pos        (0U)                                
#define RCC_DCKCFGR_PLLI2SDIVQ_Msk        (0x1FUL << RCC_DCKCFGR_PLLI2SDIVQ_Pos) /*!< 0x0000001F */
#define RCC_DCKCFGR_PLLI2SDIVQ            RCC_DCKCFGR_PLLI2SDIVQ_Msk         
#define RCC_DCKCFGR_PLLI2SDIVQ_0          (0x01UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos) /*!< 0x00000001 */
#define RCC_DCKCFGR_PLLI2SDIVQ_1          (0x02UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos) /*!< 0x00000002 */
#define RCC_DCKCFGR_PLLI2SDIVQ_2          (0x04UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos) /*!< 0x00000004 */
#define RCC_DCKCFGR_PLLI2SDIVQ_3          (0x08UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos) /*!< 0x00000008 */
#define RCC_DCKCFGR_PLLI2SDIVQ_4          (0x10UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos) /*!< 0x00000010 */
                   
#define RCC_DCKCFGR_PLLSAIDIVQ_Pos        (8U)                                
#define RCC_DCKCFGR_PLLSAIDIVQ_Msk        (0x1FUL << RCC_DCKCFGR_PLLSAIDIVQ_Pos) /*!< 0x00001F00 */
#define RCC_DCKCFGR_PLLSAIDIVQ            RCC_DCKCFGR_PLLSAIDIVQ_Msk         
#define RCC_DCKCFGR_PLLSAIDIVQ_0          (0x01UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos) /*!< 0x00000100 */
#define RCC_DCKCFGR_PLLSAIDIVQ_1          (0x02UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos) /*!< 0x00000200 */
#define RCC_DCKCFGR_PLLSAIDIVQ_2          (0x04UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos) /*!< 0x00000400 */
#define RCC_DCKCFGR_PLLSAIDIVQ_3          (0x08UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos) /*!< 0x00000800 */
#define RCC_DCKCFGR_PLLSAIDIVQ_4          (0x10UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos) /*!< 0x00001000 */
#define RCC_DCKCFGR_PLLSAIDIVR_Pos        (16U)                               
#define RCC_DCKCFGR_PLLSAIDIVR_Msk        (0x3UL << RCC_DCKCFGR_PLLSAIDIVR_Pos) /*!< 0x00030000 */
#define RCC_DCKCFGR_PLLSAIDIVR            RCC_DCKCFGR_PLLSAIDIVR_Msk         
#define RCC_DCKCFGR_PLLSAIDIVR_0          (0x1UL << RCC_DCKCFGR_PLLSAIDIVR_Pos) /*!< 0x00010000 */
#define RCC_DCKCFGR_PLLSAIDIVR_1          (0x2UL << RCC_DCKCFGR_PLLSAIDIVR_Pos) /*!< 0x00020000 */

#define RCC_DCKCFGR_SAI1ASRC_Pos           (20U)                               
#define RCC_DCKCFGR_SAI1ASRC_Msk           (0x3UL << RCC_DCKCFGR_SAI1ASRC_Pos)  /*!< 0x00300000 */
#define RCC_DCKCFGR_SAI1ASRC               RCC_DCKCFGR_SAI1ASRC_Msk            
#define RCC_DCKCFGR_SAI1ASRC_0             (0x1UL << RCC_DCKCFGR_SAI1ASRC_Pos)  /*!< 0x00100000 */
#define RCC_DCKCFGR_SAI1ASRC_1             (0x2UL << RCC_DCKCFGR_SAI1ASRC_Pos)  /*!< 0x00200000 */
#define RCC_DCKCFGR_SAI1BSRC_Pos           (22U)                               
#define RCC_DCKCFGR_SAI1BSRC_Msk           (0x3UL << RCC_DCKCFGR_SAI1BSRC_Pos)  /*!< 0x00C00000 */
#define RCC_DCKCFGR_SAI1BSRC               RCC_DCKCFGR_SAI1BSRC_Msk            
#define RCC_DCKCFGR_SAI1BSRC_0             (0x1UL << RCC_DCKCFGR_SAI1BSRC_Pos)  /*!< 0x00400000 */
#define RCC_DCKCFGR_SAI1BSRC_1             (0x2UL << RCC_DCKCFGR_SAI1BSRC_Pos)  /*!< 0x00800000 */
#define RCC_DCKCFGR_TIMPRE_Pos             (24U)                               
#define RCC_DCKCFGR_TIMPRE_Msk             (0x1UL << RCC_DCKCFGR_TIMPRE_Pos)    /*!< 0x01000000 */
#define RCC_DCKCFGR_TIMPRE                 RCC_DCKCFGR_TIMPRE_Msk              
#define RCC_DCKCFGR_CK48MSEL_Pos           (27U)                               
#define RCC_DCKCFGR_CK48MSEL_Msk           (0x1UL << RCC_DCKCFGR_CK48MSEL_Pos)  /*!< 0x08000000 */
#define RCC_DCKCFGR_CK48MSEL               RCC_DCKCFGR_CK48MSEL_Msk            
#define RCC_DCKCFGR_SDIOSEL_Pos            (28U)                               
#define RCC_DCKCFGR_SDIOSEL_Msk            (0x1UL << RCC_DCKCFGR_SDIOSEL_Pos)   /*!< 0x10000000 */
#define RCC_DCKCFGR_SDIOSEL                RCC_DCKCFGR_SDIOSEL_Msk             
#define RCC_DCKCFGR_DSISEL_Pos             (29U)                               
#define RCC_DCKCFGR_DSISEL_Msk             (0x1UL << RCC_DCKCFGR_DSISEL_Pos)    /*!< 0x20000000 */
#define RCC_DCKCFGR_DSISEL                 RCC_DCKCFGR_DSISEL_Msk              
#elif defined(STM32F7)
/********************  Bit definition for RCC_DCKCFGR1 register  ***************/
#define RCC_DCKCFGR1_PLLI2SDIVQ_Pos        (0U)
#define RCC_DCKCFGR1_PLLI2SDIVQ_Msk        (0x1FUL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos) /*!< 0x0000001F */
#define RCC_DCKCFGR1_PLLI2SDIVQ            RCC_DCKCFGR1_PLLI2SDIVQ_Msk
#define RCC_DCKCFGR1_PLLI2SDIVQ_0          (0x01UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos) /*!< 0x00000001 */
#define RCC_DCKCFGR1_PLLI2SDIVQ_1          (0x02UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos) /*!< 0x00000002 */
#define RCC_DCKCFGR1_PLLI2SDIVQ_2          (0x04UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos) /*!< 0x00000004 */
#define RCC_DCKCFGR1_PLLI2SDIVQ_3          (0x08UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos) /*!< 0x00000008 */
#define RCC_DCKCFGR1_PLLI2SDIVQ_4          (0x10UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos) /*!< 0x00000010 */

#define RCC_DCKCFGR1_PLLSAIDIVQ_Pos        (8U)
#define RCC_DCKCFGR1_PLLSAIDIVQ_Msk        (0x1FUL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos) /*!< 0x00001F00 */
#define RCC_DCKCFGR1_PLLSAIDIVQ            RCC_DCKCFGR1_PLLSAIDIVQ_Msk
#define RCC_DCKCFGR1_PLLSAIDIVQ_0          (0x01UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos) /*!< 0x00000100 */
#define RCC_DCKCFGR1_PLLSAIDIVQ_1          (0x02UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos) /*!< 0x00000200 */
#define RCC_DCKCFGR1_PLLSAIDIVQ_2          (0x04UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos) /*!< 0x00000400 */
#define RCC_DCKCFGR1_PLLSAIDIVQ_3          (0x08UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos) /*!< 0x00000800 */
#define RCC_DCKCFGR1_PLLSAIDIVQ_4          (0x10UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos) /*!< 0x00001000 */

#define RCC_DCKCFGR1_PLLSAIDIVR_Pos        (16U)
#define RCC_DCKCFGR1_PLLSAIDIVR_Msk        (0x3UL << RCC_DCKCFGR1_PLLSAIDIVR_Pos) /*!< 0x00030000 */
#define RCC_DCKCFGR1_PLLSAIDIVR            RCC_DCKCFGR1_PLLSAIDIVR_Msk
#define RCC_DCKCFGR1_PLLSAIDIVR_0          (0x1UL << RCC_DCKCFGR1_PLLSAIDIVR_Pos) /*!< 0x00010000 */
#define RCC_DCKCFGR1_PLLSAIDIVR_1          (0x2UL << RCC_DCKCFGR1_PLLSAIDIVR_Pos) /*!< 0x00020000 */

#define RCC_DCKCFGR1_SAI1SEL_Pos           (20U)
#define RCC_DCKCFGR1_SAI1SEL_Msk           (0x3UL << RCC_DCKCFGR1_SAI1SEL_Pos)  /*!< 0x00300000 */
#define RCC_DCKCFGR1_SAI1SEL               RCC_DCKCFGR1_SAI1SEL_Msk
#define RCC_DCKCFGR1_SAI1SEL_0             (0x1UL << RCC_DCKCFGR1_SAI1SEL_Pos)  /*!< 0x00100000 */
#define RCC_DCKCFGR1_SAI1SEL_1             (0x2UL << RCC_DCKCFGR1_SAI1SEL_Pos)  /*!< 0x00200000 */

#define RCC_DCKCFGR1_SAI2SEL_Pos           (22U)
#define RCC_DCKCFGR1_SAI2SEL_Msk           (0x3UL << RCC_DCKCFGR1_SAI2SEL_Pos)  /*!< 0x00C00000 */
#define RCC_DCKCFGR1_SAI2SEL               RCC_DCKCFGR1_SAI2SEL_Msk
#define RCC_DCKCFGR1_SAI2SEL_0             (0x1UL << RCC_DCKCFGR1_SAI2SEL_Pos)  /*!< 0x00400000 */
#define RCC_DCKCFGR1_SAI2SEL_1             (0x2UL << RCC_DCKCFGR1_SAI2SEL_Pos)  /*!< 0x00800000 */

#define RCC_DCKCFGR1_TIMPRE_Pos            (24U)
#define RCC_DCKCFGR1_TIMPRE_Msk            (0x1UL << RCC_DCKCFGR1_TIMPRE_Pos)   /*!< 0x01000000 */
#define RCC_DCKCFGR1_TIMPRE                RCC_DCKCFGR1_TIMPRE_Msk

/********************  Bit definition for RCC_DCKCFGR2 register  ***************/
#define RCC_DCKCFGR2_USART1SEL_Pos         (0U)
#define RCC_DCKCFGR2_USART1SEL_Msk         (0x3UL << RCC_DCKCFGR2_USART1SEL_Pos) /*!< 0x00000003 */
#define RCC_DCKCFGR2_USART1SEL             RCC_DCKCFGR2_USART1SEL_Msk
#define RCC_DCKCFGR2_USART1SEL_0           (0x1UL << RCC_DCKCFGR2_USART1SEL_Pos) /*!< 0x00000001 */
#define RCC_DCKCFGR2_USART1SEL_1           (0x2UL << RCC_DCKCFGR2_USART1SEL_Pos) /*!< 0x00000002 */
#define RCC_DCKCFGR2_USART2SEL_Pos         (2U)
#define RCC_DCKCFGR2_USART2SEL_Msk         (0x3UL << RCC_DCKCFGR2_USART2SEL_Pos) /*!< 0x0000000C */
#define RCC_DCKCFGR2_USART2SEL             RCC_DCKCFGR2_USART2SEL_Msk
#define RCC_DCKCFGR2_USART2SEL_0           (0x1UL << RCC_DCKCFGR2_USART2SEL_Pos) /*!< 0x00000004 */
#define RCC_DCKCFGR2_USART2SEL_1           (0x2UL << RCC_DCKCFGR2_USART2SEL_Pos) /*!< 0x00000008 */
#define RCC_DCKCFGR2_USART3SEL_Pos         (4U)
#define RCC_DCKCFGR2_USART3SEL_Msk         (0x3UL << RCC_DCKCFGR2_USART3SEL_Pos) /*!< 0x00000030 */
#define RCC_DCKCFGR2_USART3SEL             RCC_DCKCFGR2_USART3SEL_Msk
#define RCC_DCKCFGR2_USART3SEL_0           (0x1UL << RCC_DCKCFGR2_USART3SEL_Pos) /*!< 0x00000010 */
#define RCC_DCKCFGR2_USART3SEL_1           (0x2UL << RCC_DCKCFGR2_USART3SEL_Pos) /*!< 0x00000020 */
#define RCC_DCKCFGR2_UART4SEL_Pos          (6U)
#define RCC_DCKCFGR2_UART4SEL_Msk          (0x3UL << RCC_DCKCFGR2_UART4SEL_Pos) /*!< 0x000000C0 */
#define RCC_DCKCFGR2_UART4SEL              RCC_DCKCFGR2_UART4SEL_Msk
#define RCC_DCKCFGR2_UART4SEL_0            (0x1UL << RCC_DCKCFGR2_UART4SEL_Pos) /*!< 0x00000040 */
#define RCC_DCKCFGR2_UART4SEL_1            (0x2UL << RCC_DCKCFGR2_UART4SEL_Pos) /*!< 0x00000080 */
#define RCC_DCKCFGR2_UART5SEL_Pos          (8U)
#define RCC_DCKCFGR2_UART5SEL_Msk          (0x3UL << RCC_DCKCFGR2_UART5SEL_Pos) /*!< 0x00000300 */
#define RCC_DCKCFGR2_UART5SEL              RCC_DCKCFGR2_UART5SEL_Msk
#define RCC_DCKCFGR2_UART5SEL_0            (0x1UL << RCC_DCKCFGR2_UART5SEL_Pos) /*!< 0x00000100 */
#define RCC_DCKCFGR2_UART5SEL_1            (0x2UL << RCC_DCKCFGR2_UART5SEL_Pos) /*!< 0x00000200 */
#define RCC_DCKCFGR2_USART6SEL_Pos         (10U)
#define RCC_DCKCFGR2_USART6SEL_Msk         (0x3UL << RCC_DCKCFGR2_USART6SEL_Pos) /*!< 0x00000C00 */
#define RCC_DCKCFGR2_USART6SEL             RCC_DCKCFGR2_USART6SEL_Msk
#define RCC_DCKCFGR2_USART6SEL_0           (0x1UL << RCC_DCKCFGR2_USART6SEL_Pos) /*!< 0x00000400 */
#define RCC_DCKCFGR2_USART6SEL_1           (0x2UL << RCC_DCKCFGR2_USART6SEL_Pos) /*!< 0x00000800 */
#define RCC_DCKCFGR2_UART7SEL_Pos          (12U)
#define RCC_DCKCFGR2_UART7SEL_Msk          (0x3UL << RCC_DCKCFGR2_UART7SEL_Pos) /*!< 0x00003000 */
#define RCC_DCKCFGR2_UART7SEL              RCC_DCKCFGR2_UART7SEL_Msk
#define RCC_DCKCFGR2_UART7SEL_0            (0x1UL << RCC_DCKCFGR2_UART7SEL_Pos) /*!< 0x00001000 */
#define RCC_DCKCFGR2_UART7SEL_1            (0x2UL << RCC_DCKCFGR2_UART7SEL_Pos) /*!< 0x00002000 */
#define RCC_DCKCFGR2_UART8SEL_Pos          (14U)
#define RCC_DCKCFGR2_UART8SEL_Msk          (0x3UL << RCC_DCKCFGR2_UART8SEL_Pos) /*!< 0x0000C000 */
#define RCC_DCKCFGR2_UART8SEL              RCC_DCKCFGR2_UART8SEL_Msk
#define RCC_DCKCFGR2_UART8SEL_0            (0x1UL << RCC_DCKCFGR2_UART8SEL_Pos) /*!< 0x00004000 */
#define RCC_DCKCFGR2_UART8SEL_1            (0x2UL << RCC_DCKCFGR2_UART8SEL_Pos) /*!< 0x00008000 */
#define RCC_DCKCFGR2_I2C1SEL_Pos           (16U)
#define RCC_DCKCFGR2_I2C1SEL_Msk           (0x3UL << RCC_DCKCFGR2_I2C1SEL_Pos)  /*!< 0x00030000 */
#define RCC_DCKCFGR2_I2C1SEL               RCC_DCKCFGR2_I2C1SEL_Msk
#define RCC_DCKCFGR2_I2C1SEL_0             (0x1UL << RCC_DCKCFGR2_I2C1SEL_Pos)  /*!< 0x00010000 */
#define RCC_DCKCFGR2_I2C1SEL_1             (0x2UL << RCC_DCKCFGR2_I2C1SEL_Pos)  /*!< 0x00020000 */
#define RCC_DCKCFGR2_I2C2SEL_Pos           (18U)
#define RCC_DCKCFGR2_I2C2SEL_Msk           (0x3UL << RCC_DCKCFGR2_I2C2SEL_Pos)  /*!< 0x000C0000 */
#define RCC_DCKCFGR2_I2C2SEL               RCC_DCKCFGR2_I2C2SEL_Msk
#define RCC_DCKCFGR2_I2C2SEL_0             (0x1UL << RCC_DCKCFGR2_I2C2SEL_Pos)  /*!< 0x00040000 */
#define RCC_DCKCFGR2_I2C2SEL_1             (0x2UL << RCC_DCKCFGR2_I2C2SEL_Pos)  /*!< 0x00080000 */
#define RCC_DCKCFGR2_I2C3SEL_Pos           (20U)
#define RCC_DCKCFGR2_I2C3SEL_Msk           (0x3UL << RCC_DCKCFGR2_I2C3SEL_Pos)  /*!< 0x00300000 */
#define RCC_DCKCFGR2_I2C3SEL               RCC_DCKCFGR2_I2C3SEL_Msk
#define RCC_DCKCFGR2_I2C3SEL_0             (0x1UL << RCC_DCKCFGR2_I2C3SEL_Pos)  /*!< 0x00100000 */
#define RCC_DCKCFGR2_I2C3SEL_1             (0x2UL << RCC_DCKCFGR2_I2C3SEL_Pos)  /*!< 0x00200000 */
#define RCC_DCKCFGR2_I2C4SEL_Pos           (22U)
#define RCC_DCKCFGR2_I2C4SEL_Msk           (0x3UL << RCC_DCKCFGR2_I2C4SEL_Pos)  /*!< 0x00C00000 */
#define RCC_DCKCFGR2_I2C4SEL               RCC_DCKCFGR2_I2C4SEL_Msk
#define RCC_DCKCFGR2_I2C4SEL_0             (0x1UL << RCC_DCKCFGR2_I2C4SEL_Pos)  /*!< 0x00400000 */
#define RCC_DCKCFGR2_I2C4SEL_1             (0x2UL << RCC_DCKCFGR2_I2C4SEL_Pos)  /*!< 0x00800000 */
#define RCC_DCKCFGR2_LPTIM1SEL_Pos         (24U)
#define RCC_DCKCFGR2_LPTIM1SEL_Msk         (0x3UL << RCC_DCKCFGR2_LPTIM1SEL_Pos) /*!< 0x03000000 */
#define RCC_DCKCFGR2_LPTIM1SEL             RCC_DCKCFGR2_LPTIM1SEL_Msk
#define RCC_DCKCFGR2_LPTIM1SEL_0           (0x1UL << RCC_DCKCFGR2_LPTIM1SEL_Pos) /*!< 0x01000000 */
#define RCC_DCKCFGR2_LPTIM1SEL_1           (0x2UL << RCC_DCKCFGR2_LPTIM1SEL_Pos) /*!< 0x02000000 */
#define RCC_DCKCFGR2_CECSEL_Pos            (26U)
#define RCC_DCKCFGR2_CECSEL_Msk            (0x1UL << RCC_DCKCFGR2_CECSEL_Pos)   /*!< 0x04000000 */
#define RCC_DCKCFGR2_CECSEL                RCC_DCKCFGR2_CECSEL_Msk
#define RCC_DCKCFGR2_CK48MSEL_Pos          (27U)
#define RCC_DCKCFGR2_CK48MSEL_Msk          (0x1UL << RCC_DCKCFGR2_CK48MSEL_Pos) /*!< 0x08000000 */
#define RCC_DCKCFGR2_CK48MSEL              RCC_DCKCFGR2_CK48MSEL_Msk
#define RCC_DCKCFGR2_SDMMC1SEL_Pos         (28U)
#define RCC_DCKCFGR2_SDMMC1SEL_Msk         (0x1UL << RCC_DCKCFGR2_SDMMC1SEL_Pos) /*!< 0x10000000 */
#define RCC_DCKCFGR2_SDMMC1SEL             RCC_DCKCFGR2_SDMMC1SEL_Msk
#endif

// 레지스터 목록
namespace RCC_REG
{
enum
{
	CR = 0,			PLLCFGR,		CFGR,			CIR,			AHB1RSTR,		
	AHB2RSTR,		AHB3RSTR,						APB1RSTR = 8,	APB2RSTR,
									AHB1ENR = 12,	AHB2ENR,		AHB3ENR,
					APB1ENR = 16,	APB2ENR,		
	AHB1LPENR=20,	AHB2LPENR,		AHB3LPENR,						APB1LPENR = 24,
	APB2LPENR,										BDCR = 28,		CSR,
									SSCGR = 32,		PLLI2SCFGR,		PLLSAICFGR,
#if defined(STM32F4) || defined(GD32F4)
	DCKCFGR
#elif defined(STM32F7)
	DCKCFGR1,		DCKCFGR2
#endif
};
}

#endif

