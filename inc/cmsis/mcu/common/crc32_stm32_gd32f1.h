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
#ifndef __CRC32_STM32_GD32F1__H_
#define __CRC32_STM32_GD32F1__H_

/******************************************************************************/
/*                                                                            */
/*                       CRC calculation unit (CRC)                           */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR_Pos                       (0U)                               
#define CRC_DR_DR_Msk                       (0xFFFFFFFFUL << CRC_DR_DR_Pos)     /*!< 0xFFFFFFFF */
#define CRC_DR_DR                           CRC_DR_DR_Msk                      /*!< Data register bits */

/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR_Pos                     (0U)                               
#define CRC_IDR_IDR_Msk                     (0xFFUL << CRC_IDR_IDR_Pos)         /*!< 0x000000FF */
#define CRC_IDR_IDR                         CRC_IDR_IDR_Msk                    /*!< General-purpose 8-bit data register bits */

/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET_Pos                    (0U)                               
#define CRC_CR_RESET_Msk                    (0x1UL << CRC_CR_RESET_Pos)         /*!< 0x00000001 */
#define CRC_CR_RESET                        CRC_CR_RESET_Msk                   /*!< RESET bit */

// 레지스터 목록
namespace CRC32_REG
{
enum
{
	DR = 0, IDR, CR
};
}

#endif

