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
#ifndef __FLASH_STM32L1__H_
#define __FLASH_STM32L1__H_

/******************************************************************************/
/*                                                                            */
/*                FLASH, DATA EEPROM and Option Bytes Registers               */
/*                        (FLASH, DATA_EEPROM, OB)                            */
/*                                                                            */
/******************************************************************************/
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32L1 serie)
 */
#define FLASH_CUT5

/*******************  Bit definition for FLASH_ACR register  ******************/
#define FLASH_ACR_LATENCY_Pos                (0U)                              
#define FLASH_ACR_LATENCY_Msk                (0x1UL << FLASH_ACR_LATENCY_Pos)   /*!< 0x00000001 */
#define FLASH_ACR_LATENCY                    FLASH_ACR_LATENCY_Msk             /*!< Latency */
#define FLASH_ACR_PRFTEN_Pos                 (1U)                              
#define FLASH_ACR_PRFTEN_Msk                 (0x1UL << FLASH_ACR_PRFTEN_Pos)    /*!< 0x00000002 */
#define FLASH_ACR_PRFTEN                     FLASH_ACR_PRFTEN_Msk              /*!< Prefetch Buffer Enable */
#define FLASH_ACR_ACC64_Pos                  (2U)                              
#define FLASH_ACR_ACC64_Msk                  (0x1UL << FLASH_ACR_ACC64_Pos)     /*!< 0x00000004 */
#define FLASH_ACR_ACC64                      FLASH_ACR_ACC64_Msk               /*!< Access 64 bits */
#define FLASH_ACR_SLEEP_PD_Pos               (3U)                              
#define FLASH_ACR_SLEEP_PD_Msk               (0x1UL << FLASH_ACR_SLEEP_PD_Pos)  /*!< 0x00000008 */
#define FLASH_ACR_SLEEP_PD                   FLASH_ACR_SLEEP_PD_Msk            /*!< Flash mode during sleep mode */
#define FLASH_ACR_RUN_PD_Pos                 (4U)                              
#define FLASH_ACR_RUN_PD_Msk                 (0x1UL << FLASH_ACR_RUN_PD_Pos)    /*!< 0x00000010 */
#define FLASH_ACR_RUN_PD                     FLASH_ACR_RUN_PD_Msk              /*!< Flash mode during RUN mode */

/*******************  Bit definition for FLASH_PECR register  ******************/
#define FLASH_PECR_PELOCK_Pos                (0U)                              
#define FLASH_PECR_PELOCK_Msk                (0x1UL << FLASH_PECR_PELOCK_Pos)   /*!< 0x00000001 */
#define FLASH_PECR_PELOCK                    FLASH_PECR_PELOCK_Msk             /*!< FLASH_PECR and Flash data Lock */
#define FLASH_PECR_PRGLOCK_Pos               (1U)                              
#define FLASH_PECR_PRGLOCK_Msk               (0x1UL << FLASH_PECR_PRGLOCK_Pos)  /*!< 0x00000002 */
#define FLASH_PECR_PRGLOCK                   FLASH_PECR_PRGLOCK_Msk            /*!< Program matrix Lock */
#define FLASH_PECR_OPTLOCK_Pos               (2U)                              
#define FLASH_PECR_OPTLOCK_Msk               (0x1UL << FLASH_PECR_OPTLOCK_Pos)  /*!< 0x00000004 */
#define FLASH_PECR_OPTLOCK                   FLASH_PECR_OPTLOCK_Msk            /*!< Option byte matrix Lock */
#define FLASH_PECR_PROG_Pos                  (3U)                              
#define FLASH_PECR_PROG_Msk                  (0x1UL << FLASH_PECR_PROG_Pos)     /*!< 0x00000008 */
#define FLASH_PECR_PROG                      FLASH_PECR_PROG_Msk               /*!< Program matrix selection */
#define FLASH_PECR_DATA_Pos                  (4U)                              
#define FLASH_PECR_DATA_Msk                  (0x1UL << FLASH_PECR_DATA_Pos)     /*!< 0x00000010 */
#define FLASH_PECR_DATA                      FLASH_PECR_DATA_Msk               /*!< Data matrix selection */
#define FLASH_PECR_FTDW_Pos                  (8U)                              
#define FLASH_PECR_FTDW_Msk                  (0x1UL << FLASH_PECR_FTDW_Pos)     /*!< 0x00000100 */
#define FLASH_PECR_FTDW                      FLASH_PECR_FTDW_Msk               /*!< Fixed Time Data write for Word/Half Word/Byte programming */
#define FLASH_PECR_ERASE_Pos                 (9U)                              
#define FLASH_PECR_ERASE_Msk                 (0x1UL << FLASH_PECR_ERASE_Pos)    /*!< 0x00000200 */
#define FLASH_PECR_ERASE                     FLASH_PECR_ERASE_Msk              /*!< Page erasing mode */
#define FLASH_PECR_FPRG_Pos                  (10U)                             
#define FLASH_PECR_FPRG_Msk                  (0x1UL << FLASH_PECR_FPRG_Pos)     /*!< 0x00000400 */
#define FLASH_PECR_FPRG                      FLASH_PECR_FPRG_Msk               /*!< Fast Page/Half Page programming mode */
#define FLASH_PECR_PARALLBANK_Pos            (15U)                             
#define FLASH_PECR_PARALLBANK_Msk            (0x1UL << FLASH_PECR_PARALLBANK_Pos) /*!< 0x00008000 */
#define FLASH_PECR_PARALLBANK                FLASH_PECR_PARALLBANK_Msk         /*!< Parallel Bank mode */
#define FLASH_PECR_EOPIE_Pos                 (16U)                             
#define FLASH_PECR_EOPIE_Msk                 (0x1UL << FLASH_PECR_EOPIE_Pos)    /*!< 0x00010000 */
#define FLASH_PECR_EOPIE                     FLASH_PECR_EOPIE_Msk              /*!< End of programming interrupt */ 
#define FLASH_PECR_ERRIE_Pos                 (17U)                             
#define FLASH_PECR_ERRIE_Msk                 (0x1UL << FLASH_PECR_ERRIE_Pos)    /*!< 0x00020000 */
#define FLASH_PECR_ERRIE                     FLASH_PECR_ERRIE_Msk              /*!< Error interrupt */ 
#define FLASH_PECR_OBL_LAUNCH_Pos            (18U)                             
#define FLASH_PECR_OBL_LAUNCH_Msk            (0x1UL << FLASH_PECR_OBL_LAUNCH_Pos) /*!< 0x00040000 */
#define FLASH_PECR_OBL_LAUNCH                FLASH_PECR_OBL_LAUNCH_Msk         /*!< Launch the option byte loading */ 

/******************  Bit definition for FLASH_PDKEYR register  ******************/
#define FLASH_PDKEYR_PDKEYR_Pos              (0U)                              
#define FLASH_PDKEYR_PDKEYR_Msk              (0xFFFFFFFFUL << FLASH_PDKEYR_PDKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_PDKEYR_PDKEYR                  FLASH_PDKEYR_PDKEYR_Msk           /*!< FLASH_PEC and data matrix Key */

/******************  Bit definition for FLASH_PEKEYR register  ******************/
#define FLASH_PEKEYR_PEKEYR_Pos              (0U)                              
#define FLASH_PEKEYR_PEKEYR_Msk              (0xFFFFFFFFUL << FLASH_PEKEYR_PEKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_PEKEYR_PEKEYR                  FLASH_PEKEYR_PEKEYR_Msk           /*!< FLASH_PEC and data matrix Key */

/******************  Bit definition for FLASH_PRGKEYR register  ******************/
#define FLASH_PRGKEYR_PRGKEYR_Pos            (0U)                              
#define FLASH_PRGKEYR_PRGKEYR_Msk            (0xFFFFFFFFUL << FLASH_PRGKEYR_PRGKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_PRGKEYR_PRGKEYR                FLASH_PRGKEYR_PRGKEYR_Msk         /*!< Program matrix Key */

/******************  Bit definition for FLASH_OPTKEYR register  ******************/
#define FLASH_OPTKEYR_OPTKEYR_Pos            (0U)                              
#define FLASH_OPTKEYR_OPTKEYR_Msk            (0xFFFFFFFFUL << FLASH_OPTKEYR_OPTKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_OPTKEYR_OPTKEYR                FLASH_OPTKEYR_OPTKEYR_Msk         /*!< Option bytes matrix Key */

/******************  Bit definition for FLASH_SR register  *******************/
#define FLASH_SR_BSY_Pos                     (0U)                              
#define FLASH_SR_BSY_Msk                     (0x1UL << FLASH_SR_BSY_Pos)        /*!< 0x00000001 */
#define FLASH_SR_BSY                         FLASH_SR_BSY_Msk                  /*!< Busy */
#define FLASH_SR_EOP_Pos                     (1U)                              
#define FLASH_SR_EOP_Msk                     (0x1UL << FLASH_SR_EOP_Pos)        /*!< 0x00000002 */
#define FLASH_SR_EOP                         FLASH_SR_EOP_Msk                  /*!< End Of Programming*/
#define FLASH_SR_ENDHV_Pos                   (2U)                              
#define FLASH_SR_ENDHV_Msk                   (0x1UL << FLASH_SR_ENDHV_Pos)      /*!< 0x00000004 */
#define FLASH_SR_ENDHV                       FLASH_SR_ENDHV_Msk                /*!< End of high voltage */
#define FLASH_SR_READY_Pos                   (3U)                              
#define FLASH_SR_READY_Msk                   (0x1UL << FLASH_SR_READY_Pos)      /*!< 0x00000008 */
#define FLASH_SR_READY                       FLASH_SR_READY_Msk                /*!< Flash ready after low power mode */

#define FLASH_SR_WRPERR_Pos                  (8U)                              
#define FLASH_SR_WRPERR_Msk                  (0x1UL << FLASH_SR_WRPERR_Pos)     /*!< 0x00000100 */
#define FLASH_SR_WRPERR                      FLASH_SR_WRPERR_Msk               /*!< Write protected error */
#define FLASH_SR_PGAERR_Pos                  (9U)                              
#define FLASH_SR_PGAERR_Msk                  (0x1UL << FLASH_SR_PGAERR_Pos)     /*!< 0x00000200 */
#define FLASH_SR_PGAERR                      FLASH_SR_PGAERR_Msk               /*!< Programming Alignment Error */
#define FLASH_SR_SIZERR_Pos                  (10U)                             
#define FLASH_SR_SIZERR_Msk                  (0x1UL << FLASH_SR_SIZERR_Pos)     /*!< 0x00000400 */
#define FLASH_SR_SIZERR                      FLASH_SR_SIZERR_Msk               /*!< Size error */
#define FLASH_SR_OPTVERR_Pos                 (11U)                             
#define FLASH_SR_OPTVERR_Msk                 (0x1UL << FLASH_SR_OPTVERR_Pos)    /*!< 0x00000800 */
#define FLASH_SR_OPTVERR                     FLASH_SR_OPTVERR_Msk              /*!< Option validity error */
#define FLASH_SR_OPTVERRUSR_Pos              (12U)                             
#define FLASH_SR_OPTVERRUSR_Msk              (0x1UL << FLASH_SR_OPTVERRUSR_Pos) /*!< 0x00001000 */
#define FLASH_SR_OPTVERRUSR                  FLASH_SR_OPTVERRUSR_Msk           /*!< Option User validity error */

/******************  Bit definition for FLASH_OBR register  *******************/
#define FLASH_OBR_RDPRT_Pos                  (0U)                              
#define FLASH_OBR_RDPRT_Msk                  (0xFFUL << FLASH_OBR_RDPRT_Pos)    /*!< 0x000000FF */
#define FLASH_OBR_RDPRT                      FLASH_OBR_RDPRT_Msk               /*!< Read Protection */
#define FLASH_OBR_BOR_LEV_Pos                (16U)                             
#define FLASH_OBR_BOR_LEV_Msk                (0xFUL << FLASH_OBR_BOR_LEV_Pos)   /*!< 0x000F0000 */
#define FLASH_OBR_BOR_LEV                    FLASH_OBR_BOR_LEV_Msk             /*!< BOR_LEV[3:0] Brown Out Reset Threshold Level*/
#define FLASH_OBR_USER_Pos                   (20U)                             
#define FLASH_OBR_USER_Msk                   (0xFUL << FLASH_OBR_USER_Pos)      /*!< 0x00F00000 */
#define FLASH_OBR_USER                       FLASH_OBR_USER_Msk                /*!< User Option Bytes */
#define FLASH_OBR_IWDG_SW_Pos                (20U)                             
#define FLASH_OBR_IWDG_SW_Msk                (0x1UL << FLASH_OBR_IWDG_SW_Pos)   /*!< 0x00100000 */
#define FLASH_OBR_IWDG_SW                    FLASH_OBR_IWDG_SW_Msk             /*!< IWDG_SW */
#define FLASH_OBR_nRST_STOP_Pos              (21U)                             
#define FLASH_OBR_nRST_STOP_Msk              (0x1UL << FLASH_OBR_nRST_STOP_Pos) /*!< 0x00200000 */
#define FLASH_OBR_nRST_STOP                  FLASH_OBR_nRST_STOP_Msk           /*!< nRST_STOP */
#define FLASH_OBR_nRST_STDBY_Pos             (22U)                             
#define FLASH_OBR_nRST_STDBY_Msk             (0x1UL << FLASH_OBR_nRST_STDBY_Pos) /*!< 0x00400000 */
#define FLASH_OBR_nRST_STDBY                 FLASH_OBR_nRST_STDBY_Msk          /*!< nRST_STDBY */
#define FLASH_OBR_nRST_BFB2_Pos              (23U)                             
#define FLASH_OBR_nRST_BFB2_Msk              (0x1UL << FLASH_OBR_nRST_BFB2_Pos) /*!< 0x00800000 */
#define FLASH_OBR_nRST_BFB2                  FLASH_OBR_nRST_BFB2_Msk           /*!< BFB2 */

/******************  Bit definition for FLASH_WRPR register  ******************/
#define FLASH_WRPR1_WRP_Pos                  (0U)                              
#define FLASH_WRPR1_WRP_Msk                  (0xFFFFFFFFUL << FLASH_WRPR1_WRP_Pos) /*!< 0xFFFFFFFF */
#define FLASH_WRPR1_WRP                      FLASH_WRPR1_WRP_Msk               /*!< Write Protect sectors 0  to 31  */
#define FLASH_WRPR2_WRP_Pos                  (0U)                              
#define FLASH_WRPR2_WRP_Msk                  (0xFFFFFFFFUL << FLASH_WRPR2_WRP_Pos) /*!< 0xFFFFFFFF */
#define FLASH_WRPR2_WRP                      FLASH_WRPR2_WRP_Msk               /*!< Write Protect sectors 32 to 63  */             
#define FLASH_WRPR3_WRP_Pos                  (0U)                              
#define FLASH_WRPR3_WRP_Msk                  (0xFFFFFFFFUL << FLASH_WRPR3_WRP_Pos) /*!< 0xFFFFFFFF */
#define FLASH_WRPR3_WRP                      FLASH_WRPR3_WRP_Msk               /*!< Write Protect sectors 64 to 95  */ 
#define FLASH_WRPR4_WRP_Pos                  (0U)                              
#define FLASH_WRPR4_WRP_Msk                  (0xFFFFFFFFUL << FLASH_WRPR4_WRP_Pos) /*!< 0xFFFFFFFF */
#define FLASH_WRPR4_WRP                      FLASH_WRPR4_WRP_Msk               /*!< Write Protect sectors 96 to 127 */ 

/** 
  * @brief FLASH Registers
  */
typedef struct
{
  __IO uint32_t ACR;          /*!< Access control register,                     Address offset: 0x00 */
  __IO uint32_t PECR;         /*!< Program/erase control register,              Address offset: 0x04 */
  __IO uint32_t PDKEYR;       /*!< Power down key register,                     Address offset: 0x08 */
  __IO uint32_t PEKEYR;       /*!< Program/erase key register,                  Address offset: 0x0c */
  __IO uint32_t PRGKEYR;      /*!< Program memory key register,                 Address offset: 0x10 */
  __IO uint32_t OPTKEYR;      /*!< Option byte key register,                    Address offset: 0x14 */
  __IO uint32_t SR;           /*!< Status register,                             Address offset: 0x18 */
  __IO uint32_t OBR;          /*!< Option byte register,                        Address offset: 0x1c */
  __IO uint32_t WRPR1;        /*!< Write protection register 1,                 Address offset: 0x20 */
  uint32_t   RESERVED[23];    /*!< Reserved,                                    Address offset: 0x24 */
  __IO uint32_t WRPR2;        /*!< Write protection register 2,                 Address offset: 0x80 */
  __IO uint32_t WRPR3;        /*!< Write protection register 3,                 Address offset: 0x84 */
  __IO uint32_t WRPR4;        /*!< Write protection register 4,                 Address offset: 0x88 */
} FLASH_TypeDef;

// 레지스터 목록
namespace FLASH_REG
{
enum
{
	ACR = 0,		PECR,			PDKEYR,			PEKEYR,			PRGKEYR, 
	OPTKEYR,		SR,				OBR,			WRPR1,				
									WRPR2 = 32,		WRPR3,			WRPR4
};
}

#endif

