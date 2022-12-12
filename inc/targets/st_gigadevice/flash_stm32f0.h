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
#ifndef __FLASH_STM32_GD32F0__H_
#define __FLASH_STM32_GD32F0__H_

/******************************************************************************/
/*                                                                            */
/*                      FLASH and Option Bytes Registers                      */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for FLASH_ACR register  ******************/
#define FLASH_ACR_LATENCY_Pos             (0U)                                 
#define FLASH_ACR_LATENCY_Msk             (0x1UL << FLASH_ACR_LATENCY_Pos)      /*!< 0x00000001 */
#define FLASH_ACR_LATENCY                 FLASH_ACR_LATENCY_Msk                /*!< LATENCY bit (Latency) */

#define FLASH_ACR_HLFCYA_Pos              (3U)                               
#define FLASH_ACR_HLFCYA_Msk              (0x1UL << FLASH_ACR_HLFCYA_Pos)      /*!< 0x00000008 */
#define FLASH_ACR_HLFCYA                  FLASH_ACR_HLFCYA_Msk                 /*!< Flash Half Cycle Access Enable */
#define FLASH_ACR_PRFTBE_Pos              (4U)                                 
#define FLASH_ACR_PRFTBE_Msk              (0x1UL << FLASH_ACR_PRFTBE_Pos)       /*!< 0x00000010 */
#define FLASH_ACR_PRFTBE                  FLASH_ACR_PRFTBE_Msk                 /*!< Prefetch Buffer Enable */
#define FLASH_ACR_PRFTBS_Pos              (5U)                                 
#define FLASH_ACR_PRFTBS_Msk              (0x1UL << FLASH_ACR_PRFTBS_Pos)       /*!< 0x00000020 */
#define FLASH_ACR_PRFTBS                  FLASH_ACR_PRFTBS_Msk                 /*!< Prefetch Buffer Status */

/******************  Bit definition for FLASH_KEYR register  ******************/
#define FLASH_KEYR_FKEYR_Pos              (0U)                                 
#define FLASH_KEYR_FKEYR_Msk              (0xFFFFFFFFUL << FLASH_KEYR_FKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_KEYR_FKEYR                  FLASH_KEYR_FKEYR_Msk                 /*!< FPEC Key */

/*****************  Bit definition for FLASH_OPTKEYR register  ****************/
#define FLASH_OPTKEYR_OPTKEYR_Pos         (0U)                                 
#define FLASH_OPTKEYR_OPTKEYR_Msk         (0xFFFFFFFFUL << FLASH_OPTKEYR_OPTKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_OPTKEYR_OPTKEYR             FLASH_OPTKEYR_OPTKEYR_Msk            /*!< Option Byte Key */

/******************  FLASH Keys  **********************************************/
#define FLASH_KEY1_Pos                    (0U)                                 
#define FLASH_KEY1_Msk                    (0x45670123UL << FLASH_KEY1_Pos)      /*!< 0x45670123 */
#define FLASH_KEY1                        FLASH_KEY1_Msk                       /*!< Flash program erase key1 */
#define FLASH_KEY2_Pos                    (0U)                                 
#define FLASH_KEY2_Msk                    (0xCDEF89ABUL << FLASH_KEY2_Pos)      /*!< 0xCDEF89AB */
#define FLASH_KEY2                        FLASH_KEY2_Msk                       /*!< Flash program erase key2: used with FLASH_PEKEY1
                                                                                to unlock the write access to the FPEC. */
                                                               
#define FLASH_OPTKEY1_Pos                 (0U)                                 
#define FLASH_OPTKEY1_Msk                 (0x45670123UL << FLASH_OPTKEY1_Pos)   /*!< 0x45670123 */
#define FLASH_OPTKEY1                     FLASH_OPTKEY1_Msk                    /*!< Flash option key1 */
#define FLASH_OPTKEY2_Pos                 (0U)                                 
#define FLASH_OPTKEY2_Msk                 (0xCDEF89ABUL << FLASH_OPTKEY2_Pos)   /*!< 0xCDEF89AB */
#define FLASH_OPTKEY2                     FLASH_OPTKEY2_Msk                    /*!< Flash option key2: used with FLASH_OPTKEY1 to
                                                                                unlock the write access to the option byte block */

/******************  Bit definition for FLASH_SR register  *******************/
#define FLASH_SR_BSY_Pos                  (0U)                                 
#define FLASH_SR_BSY_Msk                  (0x1UL << FLASH_SR_BSY_Pos)           /*!< 0x00000001 */
#define FLASH_SR_BSY                      FLASH_SR_BSY_Msk                     /*!< Busy */
#define FLASH_SR_PGERR_Pos                (2U)                                 
#define FLASH_SR_PGERR_Msk                (0x1UL << FLASH_SR_PGERR_Pos)         /*!< 0x00000004 */
#define FLASH_SR_PGERR                    FLASH_SR_PGERR_Msk                   /*!< Programming Error */
#define FLASH_SR_WRPRTERR_Pos             (4U)                                 
#define FLASH_SR_WRPRTERR_Msk             (0x1UL << FLASH_SR_WRPRTERR_Pos)      /*!< 0x00000010 */
#define FLASH_SR_WRPRTERR                 FLASH_SR_WRPRTERR_Msk                /*!< Write Protection Error */
#define FLASH_SR_EOP_Pos                  (5U)                                 
#define FLASH_SR_EOP_Msk                  (0x1UL << FLASH_SR_EOP_Pos)           /*!< 0x00000020 */
#define FLASH_SR_EOP                      FLASH_SR_EOP_Msk                     /*!< End of operation */
#define  FLASH_SR_WRPERR                     FLASH_SR_WRPRTERR             /*!< Legacy of Write Protection Error */

/*******************  Bit definition for FLASH_CR register  *******************/
#define FLASH_CR_PG_Pos                   (0U)                                 
#define FLASH_CR_PG_Msk                   (0x1UL << FLASH_CR_PG_Pos)            /*!< 0x00000001 */
#define FLASH_CR_PG                       FLASH_CR_PG_Msk                      /*!< Programming */
#define FLASH_CR_PER_Pos                  (1U)                                 
#define FLASH_CR_PER_Msk                  (0x1UL << FLASH_CR_PER_Pos)           /*!< 0x00000002 */
#define FLASH_CR_PER                      FLASH_CR_PER_Msk                     /*!< Page Erase */
#define FLASH_CR_MER_Pos                  (2U)                                 
#define FLASH_CR_MER_Msk                  (0x1UL << FLASH_CR_MER_Pos)           /*!< 0x00000004 */
#define FLASH_CR_MER                      FLASH_CR_MER_Msk                     /*!< Mass Erase */
#define FLASH_CR_OPTPG_Pos                (4U)                                 
#define FLASH_CR_OPTPG_Msk                (0x1UL << FLASH_CR_OPTPG_Pos)         /*!< 0x00000010 */
#define FLASH_CR_OPTPG                    FLASH_CR_OPTPG_Msk                   /*!< Option Byte Programming */
#define FLASH_CR_OPTER_Pos                (5U)                                 
#define FLASH_CR_OPTER_Msk                (0x1UL << FLASH_CR_OPTER_Pos)         /*!< 0x00000020 */
#define FLASH_CR_OPTER                    FLASH_CR_OPTER_Msk                   /*!< Option Byte Erase */
#define FLASH_CR_STRT_Pos                 (6U)                                 
#define FLASH_CR_STRT_Msk                 (0x1UL << FLASH_CR_STRT_Pos)          /*!< 0x00000040 */
#define FLASH_CR_STRT                     FLASH_CR_STRT_Msk                    /*!< Start */
#define FLASH_CR_LOCK_Pos                 (7U)                                 
#define FLASH_CR_LOCK_Msk                 (0x1UL << FLASH_CR_LOCK_Pos)          /*!< 0x00000080 */
#define FLASH_CR_LOCK                     FLASH_CR_LOCK_Msk                    /*!< Lock */
#define FLASH_CR_OPTWRE_Pos               (9U)                                 
#define FLASH_CR_OPTWRE_Msk               (0x1UL << FLASH_CR_OPTWRE_Pos)        /*!< 0x00000200 */
#define FLASH_CR_OPTWRE                   FLASH_CR_OPTWRE_Msk                  /*!< Option Bytes Write Enable */
#define FLASH_CR_ERRIE_Pos                (10U)                                
#define FLASH_CR_ERRIE_Msk                (0x1UL << FLASH_CR_ERRIE_Pos)         /*!< 0x00000400 */
#define FLASH_CR_ERRIE                    FLASH_CR_ERRIE_Msk                   /*!< Error Interrupt Enable */
#define FLASH_CR_EOPIE_Pos                (12U)                                
#define FLASH_CR_EOPIE_Msk                (0x1UL << FLASH_CR_EOPIE_Pos)         /*!< 0x00001000 */
#define FLASH_CR_EOPIE                    FLASH_CR_EOPIE_Msk                   /*!< End of operation interrupt enable */
#define FLASH_CR_OBL_LAUNCH_Pos           (13U)                                
#define FLASH_CR_OBL_LAUNCH_Msk           (0x1UL << FLASH_CR_OBL_LAUNCH_Pos)    /*!< 0x00002000 */
#define FLASH_CR_OBL_LAUNCH               FLASH_CR_OBL_LAUNCH_Msk              /*!< Option Bytes Loader Launch */

/*******************  Bit definition for FLASH_AR register  *******************/
#define FLASH_AR_FAR_Pos                  (0U)                                 
#define FLASH_AR_FAR_Msk                  (0xFFFFFFFFUL << FLASH_AR_FAR_Pos)    /*!< 0xFFFFFFFF */
#define FLASH_AR_FAR                      FLASH_AR_FAR_Msk                     /*!< Flash Address */

/******************  Bit definition for FLASH_OBR register  *******************/
#define FLASH_OBR_OPTERR_Pos              (0U)                                 
#define FLASH_OBR_OPTERR_Msk              (0x1UL << FLASH_OBR_OPTERR_Pos)       /*!< 0x00000001 */
#define FLASH_OBR_OPTERR                  FLASH_OBR_OPTERR_Msk                 /*!< Option Byte Error */
#define FLASH_OBR_RDPRT1_Pos              (1U)                                 
#define FLASH_OBR_RDPRT1_Msk              (0x1UL << FLASH_OBR_RDPRT1_Pos)       /*!< 0x00000002 */
#define FLASH_OBR_RDPRT1                  FLASH_OBR_RDPRT1_Msk                 /*!< Read protection Level 1 */
#define FLASH_OBR_RDPRT2_Pos              (2U)                                 
#define FLASH_OBR_RDPRT2_Msk              (0x1UL << FLASH_OBR_RDPRT2_Pos)       /*!< 0x00000004 */
#define FLASH_OBR_RDPRT2                  FLASH_OBR_RDPRT2_Msk                 /*!< Read protection Level 2 */

#define FLASH_OBR_USER_Pos                (8U)                                 
#define FLASH_OBR_USER_Msk                (0x77UL << FLASH_OBR_USER_Pos)        /*!< 0x00007700 */
#define FLASH_OBR_USER                    FLASH_OBR_USER_Msk                   /*!< User Option Bytes */
#define FLASH_OBR_IWDG_SW_Pos             (8U)                                 
#define FLASH_OBR_IWDG_SW_Msk             (0x1UL << FLASH_OBR_IWDG_SW_Pos)      /*!< 0x00000100 */
#define FLASH_OBR_IWDG_SW                 FLASH_OBR_IWDG_SW_Msk                /*!< IWDG SW */
#define FLASH_OBR_nRST_STOP_Pos           (9U)                                 
#define FLASH_OBR_nRST_STOP_Msk           (0x1UL << FLASH_OBR_nRST_STOP_Pos)    /*!< 0x00000200 */
#define FLASH_OBR_nRST_STOP               FLASH_OBR_nRST_STOP_Msk              /*!< nRST_STOP */
#define FLASH_OBR_nRST_STDBY_Pos          (10U)                                
#define FLASH_OBR_nRST_STDBY_Msk          (0x1UL << FLASH_OBR_nRST_STDBY_Pos)   /*!< 0x00000400 */
#define FLASH_OBR_nRST_STDBY              FLASH_OBR_nRST_STDBY_Msk             /*!< nRST_STDBY */
#define FLASH_OBR_nBOOT1_Pos              (12U)                                
#define FLASH_OBR_nBOOT1_Msk              (0x1UL << FLASH_OBR_nBOOT1_Pos)       /*!< 0x00001000 */
#define FLASH_OBR_nBOOT1                  FLASH_OBR_nBOOT1_Msk                 /*!< nBOOT1 */
#define FLASH_OBR_VDDA_MONITOR_Pos        (13U)                                
#define FLASH_OBR_VDDA_MONITOR_Msk        (0x1UL << FLASH_OBR_VDDA_MONITOR_Pos) /*!< 0x00002000 */
#define FLASH_OBR_VDDA_MONITOR            FLASH_OBR_VDDA_MONITOR_Msk           /*!< VDDA power supply supervisor */
#define FLASH_OBR_RAM_PARITY_CHECK_Pos    (14U)                                
#define FLASH_OBR_RAM_PARITY_CHECK_Msk    (0x1UL << FLASH_OBR_RAM_PARITY_CHECK_Pos) /*!< 0x00004000 */
#define FLASH_OBR_RAM_PARITY_CHECK        FLASH_OBR_RAM_PARITY_CHECK_Msk       /*!< RAM parity check */
#define FLASH_OBR_DATA0_Pos               (16U)                                
#define FLASH_OBR_DATA0_Msk               (0xFFUL << FLASH_OBR_DATA0_Pos)       /*!< 0x00FF0000 */
#define FLASH_OBR_DATA0                   FLASH_OBR_DATA0_Msk                  /*!< Data0 */
#define FLASH_OBR_DATA1_Pos               (24U)                                
#define FLASH_OBR_DATA1_Msk               (0xFFUL << FLASH_OBR_DATA1_Pos)       /*!< 0xFF000000 */
#define FLASH_OBR_DATA1                   FLASH_OBR_DATA1_Msk                  /*!< Data1 */

/* Old BOOT1 bit definition, maintained for legacy purpose */
#define FLASH_OBR_BOOT1                      FLASH_OBR_nBOOT1

/* Old OBR_VDDA bit definition, maintained for legacy purpose */
#define FLASH_OBR_VDDA_ANALOG                FLASH_OBR_VDDA_MONITOR

/******************  Bit definition for FLASH_WRPR register  ******************/
#define FLASH_WRPR_WRP_Pos                (0U)                                 
#define FLASH_WRPR_WRP_Msk                (0xFFFFUL << FLASH_WRPR_WRP_Pos)      /*!< 0x0000FFFF */
#define FLASH_WRPR_WRP                    FLASH_WRPR_WRP_Msk                   /*!< Write Protect */

/*----------------------------------------------------------------------------*/

/******************  Bit definition for OB_RDP register  **********************/
#define OB_RDP_RDP_Pos       (0U)                                              
#define OB_RDP_RDP_Msk       (0xFFUL << OB_RDP_RDP_Pos)                         /*!< 0x000000FF */
#define OB_RDP_RDP           OB_RDP_RDP_Msk                                    /*!< Read protection option byte */
#define OB_RDP_nRDP_Pos      (8U)                                              
#define OB_RDP_nRDP_Msk      (0xFFUL << OB_RDP_nRDP_Pos)                        /*!< 0x0000FF00 */
#define OB_RDP_nRDP          OB_RDP_nRDP_Msk                                   /*!< Read protection complemented option byte */

/******************  Bit definition for OB_USER register  *********************/
#define OB_USER_USER_Pos     (16U)                                             
#define OB_USER_USER_Msk     (0xFFUL << OB_USER_USER_Pos)                       /*!< 0x00FF0000 */
#define OB_USER_USER         OB_USER_USER_Msk                                  /*!< User option byte */
#define OB_USER_nUSER_Pos    (24U)                                             
#define OB_USER_nUSER_Msk    (0xFFUL << OB_USER_nUSER_Pos)                      /*!< 0xFF000000 */
#define OB_USER_nUSER        OB_USER_nUSER_Msk                                 /*!< User complemented option byte */

/******************  Bit definition for OB_WRP0 register  *********************/
#define OB_WRP0_WRP0_Pos     (0U)                                              
#define OB_WRP0_WRP0_Msk     (0xFFUL << OB_WRP0_WRP0_Pos)                       /*!< 0x000000FF */
#define OB_WRP0_WRP0         OB_WRP0_WRP0_Msk                                  /*!< Flash memory write protection option bytes */
#define OB_WRP0_nWRP0_Pos    (8U)                                              
#define OB_WRP0_nWRP0_Msk    (0xFFUL << OB_WRP0_nWRP0_Pos)                      /*!< 0x0000FF00 */
#define OB_WRP0_nWRP0        OB_WRP0_nWRP0_Msk                                 /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for OB_WRP1 register  *********************/
#define OB_WRP1_WRP1_Pos     (16U)                                             
#define OB_WRP1_WRP1_Msk     (0xFFUL << OB_WRP1_WRP1_Pos)                       /*!< 0x00FF0000 */
#define OB_WRP1_WRP1         OB_WRP1_WRP1_Msk                                  /*!< Flash memory write protection option bytes */
#define OB_WRP1_nWRP1_Pos    (24U)                                             
#define OB_WRP1_nWRP1_Msk    (0xFFUL << OB_WRP1_nWRP1_Pos)                      /*!< 0xFF000000 */
#define OB_WRP1_nWRP1        OB_WRP1_nWRP1_Msk                                 /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for OB_WRP2 register  *********************/
#define OB_WRP2_WRP2_Pos     (0U)                                              
#define OB_WRP2_WRP2_Msk     (0xFFUL << OB_WRP2_WRP2_Pos)                       /*!< 0x000000FF */
#define OB_WRP2_WRP2         OB_WRP2_WRP2_Msk                                  /*!< Flash memory write protection option bytes */
#define OB_WRP2_nWRP2_Pos    (8U)                                              
#define OB_WRP2_nWRP2_Msk    (0xFFUL << OB_WRP2_nWRP2_Pos)                      /*!< 0x0000FF00 */
#define OB_WRP2_nWRP2        OB_WRP2_nWRP2_Msk                                 /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for OB_WRP3 register  *********************/
#define OB_WRP3_WRP3_Pos     (16U)                                             
#define OB_WRP3_WRP3_Msk     (0xFFUL << OB_WRP3_WRP3_Pos)                       /*!< 0x00FF0000 */
#define OB_WRP3_WRP3         OB_WRP3_WRP3_Msk                                  /*!< Flash memory write protection option bytes */
#define OB_WRP3_nWRP3_Pos    (24U)                                             
#define OB_WRP3_nWRP3_Msk    (0xFFUL << OB_WRP3_nWRP3_Pos)                      /*!< 0xFF000000 */
#define OB_WRP3_nWRP3        OB_WRP3_nWRP3_Msk                                 /*!< Flash memory write protection complemented option bytes */

// 레지스터 목록
namespace FLASH_REG
{
enum
{
	ACR = 0,	KEYR,		OPTKEYR,		SR,			CR,
	AR,			OBR,		WRPR,
};
}

#endif

