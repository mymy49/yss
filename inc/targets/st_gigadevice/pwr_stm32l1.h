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
#ifndef __PWR_STM32L1__H_
#define __PWR_STM32L1__H_

/******************************************************************************/
/*                                                                            */
/*                          Power Control (PWR)                               */
/*                                                                            */
/******************************************************************************/

#define PWR_PVD_SUPPORT                       /*!< PWR feature available only on specific devices: Power Voltage Detection feature */

/********************  Bit definition for PWR_CR register  ********************/
#define PWR_CR_LPSDSR_Pos                   (0U)                               
#define PWR_CR_LPSDSR_Msk                   (0x1UL << PWR_CR_LPSDSR_Pos)        /*!< 0x00000001 */
#define PWR_CR_LPSDSR                       PWR_CR_LPSDSR_Msk                  /*!< Low-power deepsleep/sleep/low power run */
#define PWR_CR_PDDS_Pos                     (1U)                               
#define PWR_CR_PDDS_Msk                     (0x1UL << PWR_CR_PDDS_Pos)          /*!< 0x00000002 */
#define PWR_CR_PDDS                         PWR_CR_PDDS_Msk                    /*!< Power Down Deepsleep */
#define PWR_CR_CWUF_Pos                     (2U)                               
#define PWR_CR_CWUF_Msk                     (0x1UL << PWR_CR_CWUF_Pos)          /*!< 0x00000004 */
#define PWR_CR_CWUF                         PWR_CR_CWUF_Msk                    /*!< Clear Wakeup Flag */
#define PWR_CR_CSBF_Pos                     (3U)                               
#define PWR_CR_CSBF_Msk                     (0x1UL << PWR_CR_CSBF_Pos)          /*!< 0x00000008 */
#define PWR_CR_CSBF                         PWR_CR_CSBF_Msk                    /*!< Clear Standby Flag */
#define PWR_CR_PVDE_Pos                     (4U)                               
#define PWR_CR_PVDE_Msk                     (0x1UL << PWR_CR_PVDE_Pos)          /*!< 0x00000010 */
#define PWR_CR_PVDE                         PWR_CR_PVDE_Msk                    /*!< Power Voltage Detector Enable */

#define PWR_CR_PLS_Pos                      (5U)                               
#define PWR_CR_PLS_Msk                      (0x7UL << PWR_CR_PLS_Pos)           /*!< 0x000000E0 */
#define PWR_CR_PLS                          PWR_CR_PLS_Msk                     /*!< PLS[2:0] bits (PVD Level Selection) */
#define PWR_CR_PLS_0                        (0x1UL << PWR_CR_PLS_Pos)           /*!< 0x00000020 */
#define PWR_CR_PLS_1                        (0x2UL << PWR_CR_PLS_Pos)           /*!< 0x00000040 */
#define PWR_CR_PLS_2                        (0x4UL << PWR_CR_PLS_Pos)           /*!< 0x00000080 */

/*!< PVD level configuration */
#define PWR_CR_PLS_LEV0                     (0x00000000U)                      /*!< PVD level 0 */
#define PWR_CR_PLS_LEV1                     (0x00000020U)                      /*!< PVD level 1 */
#define PWR_CR_PLS_LEV2                     (0x00000040U)                      /*!< PVD level 2 */
#define PWR_CR_PLS_LEV3                     (0x00000060U)                      /*!< PVD level 3 */
#define PWR_CR_PLS_LEV4                     (0x00000080U)                      /*!< PVD level 4 */
#define PWR_CR_PLS_LEV5                     (0x000000A0U)                      /*!< PVD level 5 */
#define PWR_CR_PLS_LEV6                     (0x000000C0U)                      /*!< PVD level 6 */
#define PWR_CR_PLS_LEV7                     (0x000000E0U)                      /*!< PVD level 7 */

#define PWR_CR_DBP_Pos                      (8U)                               
#define PWR_CR_DBP_Msk                      (0x1UL << PWR_CR_DBP_Pos)           /*!< 0x00000100 */
#define PWR_CR_DBP                          PWR_CR_DBP_Msk                     /*!< Disable Backup Domain write protection */
#define PWR_CR_ULP_Pos                      (9U)                               
#define PWR_CR_ULP_Msk                      (0x1UL << PWR_CR_ULP_Pos)           /*!< 0x00000200 */
#define PWR_CR_ULP                          PWR_CR_ULP_Msk                     /*!< Ultra Low Power mode */
#define PWR_CR_FWU_Pos                      (10U)                              
#define PWR_CR_FWU_Msk                      (0x1UL << PWR_CR_FWU_Pos)           /*!< 0x00000400 */
#define PWR_CR_FWU                          PWR_CR_FWU_Msk                     /*!< Fast wakeup */

#define PWR_CR_VOS_Pos                      (11U)                              
#define PWR_CR_VOS_Msk                      (0x3UL << PWR_CR_VOS_Pos)           /*!< 0x00001800 */
#define PWR_CR_VOS                          PWR_CR_VOS_Msk                     /*!< VOS[1:0] bits (Voltage scaling range selection) */
#define PWR_CR_VOS_0                        (0x1UL << PWR_CR_VOS_Pos)           /*!< 0x00000800 */
#define PWR_CR_VOS_1                        (0x2UL << PWR_CR_VOS_Pos)           /*!< 0x00001000 */
#define PWR_CR_LPRUN_Pos                    (14U)                              
#define PWR_CR_LPRUN_Msk                    (0x1UL << PWR_CR_LPRUN_Pos)         /*!< 0x00004000 */
#define PWR_CR_LPRUN                        PWR_CR_LPRUN_Msk                   /*!< Low power run mode */

/*******************  Bit definition for PWR_CSR register  ********************/
#define PWR_CSR_WUF_Pos                     (0U)                               
#define PWR_CSR_WUF_Msk                     (0x1UL << PWR_CSR_WUF_Pos)          /*!< 0x00000001 */
#define PWR_CSR_WUF                         PWR_CSR_WUF_Msk                    /*!< Wakeup Flag */
#define PWR_CSR_SBF_Pos                     (1U)                               
#define PWR_CSR_SBF_Msk                     (0x1UL << PWR_CSR_SBF_Pos)          /*!< 0x00000002 */
#define PWR_CSR_SBF                         PWR_CSR_SBF_Msk                    /*!< Standby Flag */
#define PWR_CSR_PVDO_Pos                    (2U)                               
#define PWR_CSR_PVDO_Msk                    (0x1UL << PWR_CSR_PVDO_Pos)         /*!< 0x00000004 */
#define PWR_CSR_PVDO                        PWR_CSR_PVDO_Msk                   /*!< PVD Output */
#define PWR_CSR_VREFINTRDYF_Pos             (3U)                               
#define PWR_CSR_VREFINTRDYF_Msk             (0x1UL << PWR_CSR_VREFINTRDYF_Pos)  /*!< 0x00000008 */
#define PWR_CSR_VREFINTRDYF                 PWR_CSR_VREFINTRDYF_Msk            /*!< Internal voltage reference (VREFINT) ready flag */
#define PWR_CSR_VOSF_Pos                    (4U)                               
#define PWR_CSR_VOSF_Msk                    (0x1UL << PWR_CSR_VOSF_Pos)         /*!< 0x00000010 */
#define PWR_CSR_VOSF                        PWR_CSR_VOSF_Msk                   /*!< Voltage Scaling select flag */
#define PWR_CSR_REGLPF_Pos                  (5U)                               
#define PWR_CSR_REGLPF_Msk                  (0x1UL << PWR_CSR_REGLPF_Pos)       /*!< 0x00000020 */
#define PWR_CSR_REGLPF                      PWR_CSR_REGLPF_Msk                 /*!< Regulator LP flag */

#define PWR_CSR_EWUP1_Pos                   (8U)                               
#define PWR_CSR_EWUP1_Msk                   (0x1UL << PWR_CSR_EWUP1_Pos)        /*!< 0x00000100 */
#define PWR_CSR_EWUP1                       PWR_CSR_EWUP1_Msk                  /*!< Enable WKUP pin 1 */
#define PWR_CSR_EWUP2_Pos                   (9U)                               
#define PWR_CSR_EWUP2_Msk                   (0x1UL << PWR_CSR_EWUP2_Pos)        /*!< 0x00000200 */
#define PWR_CSR_EWUP2                       PWR_CSR_EWUP2_Msk                  /*!< Enable WKUP pin 2 */
#define PWR_CSR_EWUP3_Pos                   (10U)                              
#define PWR_CSR_EWUP3_Msk                   (0x1UL << PWR_CSR_EWUP3_Pos)        /*!< 0x00000400 */
#define PWR_CSR_EWUP3                       PWR_CSR_EWUP3_Msk                  /*!< Enable WKUP pin 3 */

// 레지스터 목록
namespace PWR_REG
{
enum
{
	CR = 0, CSR
};
}

#endif

