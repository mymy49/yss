/**
  ******************************************************************************
  * @file    stm32f103xg.h
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


/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f103xg
  * @{
  */
    
#ifndef __STM32F103xG_H
#define __STM32F103xG_H

#ifdef __cplusplus
 extern "C" {
#endif 

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */
/**
  * @brief Configuration of the Cortex-M3 Processor and Core Peripherals 
 */
#define __CM3_REV                  0x0200U  /*!< Core Revision r2p0                           */
 #define __MPU_PRESENT             1U       /*!< STM32 XL-density devices provide an MPU      */
#define __NVIC_PRIO_BITS           4U       /*!< STM32 uses 4 Bits for the Priority Levels    */
#define __Vendor_SysTickConfig     0U       /*!< Set to 1 if different SysTick Config is used */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief STM32F10x Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */

 /*!< Interrupt Number Definition */
typedef enum
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                     */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */

/******  STM32 specific Interrupt Numbers *********************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
  TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                     */
  RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                 */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                 */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                 */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                 */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                 */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                 */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                 */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break Interrupt and TIM9 global Interrupt       */
  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global Interrupt     */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
  USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
  TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global Interrupt      */
  TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global Interrupt     */
  TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                       */
  ADC3_IRQn                   = 47,     /*!< ADC3 global Interrupt                                */
  FSMC_IRQn                   = 48,     /*!< FSMC global Interrupt                                */
  SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                */
  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */
  TIM6_IRQn                   = 54,     /*!< TIM6 global Interrupt                                */
  TIM7_IRQn                   = 55,     /*!< TIM7 global Interrupt                                */
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
  DMA2_Channel4_5_IRQn        = 59,     /*!< DMA2 Channel 4 and Channel 5 global Interrupt        */
} IRQn_Type;

/**
  * @}
  */

#include "../../cmsis/core_cm3.h"
#include "system_stm32f1xx.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Backup Registers  
  */

typedef struct
{
  uint32_t  RESERVED0;
  __IO uint32_t DR1;
  __IO uint32_t DR2;
  __IO uint32_t DR3;
  __IO uint32_t DR4;
  __IO uint32_t DR5;
  __IO uint32_t DR6;
  __IO uint32_t DR7;
  __IO uint32_t DR8;
  __IO uint32_t DR9;
  __IO uint32_t DR10;
  __IO uint32_t RTCCR;
  __IO uint32_t CR;
  __IO uint32_t CSR;
  uint32_t  RESERVED13[2];
  __IO uint32_t DR11;
  __IO uint32_t DR12;
  __IO uint32_t DR13;
  __IO uint32_t DR14;
  __IO uint32_t DR15;
  __IO uint32_t DR16;
  __IO uint32_t DR17;
  __IO uint32_t DR18;
  __IO uint32_t DR19;
  __IO uint32_t DR20;
  __IO uint32_t DR21;
  __IO uint32_t DR22;
  __IO uint32_t DR23;
  __IO uint32_t DR24;
  __IO uint32_t DR25;
  __IO uint32_t DR26;
  __IO uint32_t DR27;
  __IO uint32_t DR28;
  __IO uint32_t DR29;
  __IO uint32_t DR30;
  __IO uint32_t DR31;
  __IO uint32_t DR32;
  __IO uint32_t DR33;
  __IO uint32_t DR34;
  __IO uint32_t DR35;
  __IO uint32_t DR36;
  __IO uint32_t DR37;
  __IO uint32_t DR38;
  __IO uint32_t DR39;
  __IO uint32_t DR40;
  __IO uint32_t DR41;
  __IO uint32_t DR42;
} BKP_TypeDef;
  
/** 
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;
  __IO uint32_t CR;
}DBGMCU_TypeDef;

/** 
  * @brief Option Bytes Registers
  */
  
typedef struct
{
  __IO uint16_t RDP;
  __IO uint16_t USER;
  __IO uint16_t Data0;
  __IO uint16_t Data1;
  __IO uint16_t WRP0;
  __IO uint16_t WRP1;
  __IO uint16_t WRP2;
  __IO uint16_t WRP3;
} OB_TypeDef;

/** 
  * @brief Flexible Static Memory Controller
  */

typedef struct
{
  __IO uint32_t BTCR[8];   
} FSMC_Bank1_TypeDef; 

/** 
  * @brief Flexible Static Memory Controller Bank1E
  */
  
typedef struct
{
  __IO uint32_t BWTR[7];
} FSMC_Bank1E_TypeDef;

/** 
  * @brief Flexible Static Memory Controller Bank2
  */
  
typedef struct
{
  __IO uint32_t PCR2;       /*!< NAND Flash control register 2,                       Address offset: 0x60 */
  __IO uint32_t SR2;        /*!< NAND Flash FIFO status and interrupt register 2,     Address offset: 0x64 */
  __IO uint32_t PMEM2;      /*!< NAND Flash Common memory space timing register 2,    Address offset: 0x68 */
  __IO uint32_t PATT2;      /*!< NAND Flash Attribute memory space timing register 2, Address offset: 0x6C */
  uint32_t      RESERVED0;  /*!< Reserved, 0x70                                                            */
  __IO uint32_t ECCR2;      /*!< NAND Flash ECC result registers 2,                   Address offset: 0x74 */
  uint32_t      RESERVED1;  /*!< Reserved, 0x78                                                            */
  uint32_t      RESERVED2;  /*!< Reserved, 0x7C                                                            */
  __IO uint32_t PCR3;       /*!< NAND Flash control register 3,                       Address offset: 0x80 */
  __IO uint32_t SR3;        /*!< NAND Flash FIFO status and interrupt register 3,     Address offset: 0x84 */
  __IO uint32_t PMEM3;      /*!< NAND Flash Common memory space timing register 3,    Address offset: 0x88 */
  __IO uint32_t PATT3;      /*!< NAND Flash Attribute memory space timing register 3, Address offset: 0x8C */
  uint32_t      RESERVED3;  /*!< Reserved, 0x90                                                            */
  __IO uint32_t ECCR3;      /*!< NAND Flash ECC result registers 3,                   Address offset: 0x94 */
} FSMC_Bank2_3_TypeDef;  

/** 
  * @brief Flexible Static Memory Controller Bank4
  */
  
typedef struct
{
  __IO uint32_t PCR4;
  __IO uint32_t SR4;
  __IO uint32_t PMEM4;
  __IO uint32_t PATT4;
  __IO uint32_t PIO4; 
} FSMC_Bank4_TypeDef; 

/** 
  * @brief Independent WATCHDOG
  */

typedef struct
{
  __IO uint32_t KR;           /*!< Key register,                                Address offset: 0x00 */
  __IO uint32_t PR;           /*!< Prescaler register,                          Address offset: 0x04 */
  __IO uint32_t RLR;          /*!< Reload register,                             Address offset: 0x08 */
  __IO uint32_t SR;           /*!< Status register,                             Address offset: 0x0C */
} IWDG_TypeDef;

/** 
  * @brief Power Control
  */

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CSR;
} PWR_TypeDef;

/** 
  * @brief Real-Time Clock
  */

typedef struct
{
  __IO uint32_t CRH;
  __IO uint32_t CRL;
  __IO uint32_t PRLH;
  __IO uint32_t PRLL;
  __IO uint32_t DIVH;
  __IO uint32_t DIVL;
  __IO uint32_t CNTH;
  __IO uint32_t CNTL;
  __IO uint32_t ALRH;
  __IO uint32_t ALRL;
} RTC_TypeDef;

/** 
  * @brief Universal Serial Bus Full Speed Device
  */
  
typedef struct
{
  __IO uint16_t EP0R;                 /*!< USB Endpoint 0 register,                   Address offset: 0x00 */ 
  __IO uint16_t RESERVED0;            /*!< Reserved */     
  __IO uint16_t EP1R;                 /*!< USB Endpoint 1 register,                   Address offset: 0x04 */
  __IO uint16_t RESERVED1;            /*!< Reserved */       
  __IO uint16_t EP2R;                 /*!< USB Endpoint 2 register,                   Address offset: 0x08 */
  __IO uint16_t RESERVED2;            /*!< Reserved */       
  __IO uint16_t EP3R;                 /*!< USB Endpoint 3 register,                   Address offset: 0x0C */ 
  __IO uint16_t RESERVED3;            /*!< Reserved */       
  __IO uint16_t EP4R;                 /*!< USB Endpoint 4 register,                   Address offset: 0x10 */
  __IO uint16_t RESERVED4;            /*!< Reserved */       
  __IO uint16_t EP5R;                 /*!< USB Endpoint 5 register,                   Address offset: 0x14 */
  __IO uint16_t RESERVED5;            /*!< Reserved */       
  __IO uint16_t EP6R;                 /*!< USB Endpoint 6 register,                   Address offset: 0x18 */
  __IO uint16_t RESERVED6;            /*!< Reserved */       
  __IO uint16_t EP7R;                 /*!< USB Endpoint 7 register,                   Address offset: 0x1C */
  __IO uint16_t RESERVED7[17];        /*!< Reserved */     
  __IO uint16_t CNTR;                 /*!< Control register,                          Address offset: 0x40 */
  __IO uint16_t RESERVED8;            /*!< Reserved */       
  __IO uint16_t ISTR;                 /*!< Interrupt status register,                 Address offset: 0x44 */
  __IO uint16_t RESERVED9;            /*!< Reserved */       
  __IO uint16_t FNR;                  /*!< Frame number register,                     Address offset: 0x48 */
  __IO uint16_t RESERVEDA;            /*!< Reserved */       
  __IO uint16_t DADDR;                /*!< Device address register,                   Address offset: 0x4C */
  __IO uint16_t RESERVEDB;            /*!< Reserved */       
  __IO uint16_t BTABLE;               /*!< Buffer Table address register,             Address offset: 0x50 */
  __IO uint16_t RESERVEDC;            /*!< Reserved */       
} USB_TypeDef;


/** 
  * @brief Window WATCHDOG
  */

typedef struct
{
  __IO uint32_t CR;   /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;  /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;   /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;

/**
  * @}
  */
  
/** @addtogroup Peripheral_memory_map
  * @{
  */


#define FLASH_BASE            0x08000000UL /*!< FLASH base address in the alias region */
#define FLASH_BANK1_END       0x0807FFFFUL /*!< FLASH END address of bank1 */
#define FLASH_BANK2_END       0x080FFFFFUL /*!< FLASH END address of bank2 */
#define SRAM_BASE             0x20000000UL /*!< SRAM base address in the alias region */
#define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region */

#define SRAM_BB_BASE          0x22000000UL /*!< SRAM base address in the bit-band region */
#define PERIPH_BB_BASE        0x42000000UL /*!< Peripheral base address in the bit-band region */

#define FSMC_BASE             0x60000000UL /*!< FSMC base address */
#define FSMC_R_BASE           0xA0000000UL /*!< FSMC registers base address */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x00000000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x00000400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x00000800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x00000C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x00001000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x00001400UL)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x00001800UL)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x00001C00UL)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x00002000UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x00002800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x00002C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x00003000UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x00003800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x00003C00UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x00004400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x00004800UL)
#define UART4_BASE            (APB1PERIPH_BASE + 0x00004C00UL)
#define UART5_BASE            (APB1PERIPH_BASE + 0x00005000UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x00005400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x00005800UL)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x00006400UL)
#define BKP_BASE              (APB1PERIPH_BASE + 0x00006C00UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x00007000UL)
#define DAC_BASE              (APB1PERIPH_BASE + 0x00007400UL)
#define AFIO_BASE             (APB2PERIPH_BASE + 0x00000000UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00000400UL)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x00000800UL)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x00000C00UL)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x00001000UL)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x00001400UL)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x00001800UL)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x00001C00UL)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x00002000UL)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x00002400UL)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x00002800UL)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x00002C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x00003400UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800UL)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x00003C00UL)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x00004C00UL)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x00005000UL)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x00005400UL)

#define SDIO_BASE             (PERIPH_BASE + 0x00018000UL)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000UL)
#define DMA1_Channel1_BASE    (AHBPERIPH_BASE + 0x00000008UL)
#define DMA1_Channel2_BASE    (AHBPERIPH_BASE + 0x0000001CUL)
#define DMA1_Channel3_BASE    (AHBPERIPH_BASE + 0x00000030UL)
#define DMA1_Channel4_BASE    (AHBPERIPH_BASE + 0x00000044UL)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x00000058UL)
#define DMA1_Channel6_BASE    (AHBPERIPH_BASE + 0x0000006CUL)
#define DMA1_Channel7_BASE    (AHBPERIPH_BASE + 0x00000080UL)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x00000400UL)
#define DMA2_Channel1_BASE    (AHBPERIPH_BASE + 0x00000408UL)
#define DMA2_Channel2_BASE    (AHBPERIPH_BASE + 0x0000041CUL)
#define DMA2_Channel3_BASE    (AHBPERIPH_BASE + 0x00000430UL)
#define DMA2_Channel4_BASE    (AHBPERIPH_BASE + 0x00000444UL)
#define DMA2_Channel5_BASE    (AHBPERIPH_BASE + 0x00000458UL)
#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000UL)
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000UL)

#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000UL) /*!< Flash registers base address */
#define FLASHSIZE_BASE        0x1FFFF7E0UL    /*!< FLASH Size register base address */
#define UID_BASE              0x1FFFF7E8UL    /*!< Unique device ID register base address */
#define OB_BASE               0x1FFFF800UL    /*!< Flash Option Bytes base address */


#define FSMC_BANK1            (FSMC_BASE)               /*!< FSMC Bank1 base address */
#define FSMC_BANK1_1          (FSMC_BANK1)              /*!< FSMC Bank1_1 base address */
#define FSMC_BANK1_2          (FSMC_BANK1 + 0x04000000UL) /*!< FSMC Bank1_2 base address */
#define FSMC_BANK1_3          (FSMC_BANK1 + 0x08000000UL) /*!< FSMC Bank1_3 base address */
#define FSMC_BANK1_4          (FSMC_BANK1 + 0x0C000000UL) /*!< FSMC Bank1_4 base address */

#define FSMC_BANK2            (FSMC_BASE + 0x10000000UL)  /*!< FSMC Bank2 base address */
#define FSMC_BANK3            (FSMC_BASE + 0x20000000UL)  /*!< FSMC Bank3 base address */
#define FSMC_BANK4            (FSMC_BASE + 0x30000000UL)  /*!< FSMC Bank4 base address */

#define FSMC_BANK1_R_BASE     (FSMC_R_BASE + 0x00000000UL)    /*!< FSMC Bank1 registers base address */
#define FSMC_BANK1E_R_BASE    (FSMC_R_BASE + 0x00000104UL)    /*!< FSMC Bank1E registers base address */
#define FSMC_BANK2_3_R_BASE   (FSMC_R_BASE + 0x00000060UL)    /*!< FSMC Bank2/Bank3 registers base address */
#define FSMC_BANK4_R_BASE     (FSMC_R_BASE + 0x000000A0UL)    /*!< FSMC Bank4 registers base address */

#define DBGMCU_BASE          0xE0042000UL /*!< Debug MCU registers base address */

/* USB device FS */
#define USB_BASE              (APB1PERIPH_BASE + 0x00005C00UL) /*!< USB_IP Peripheral Registers base address */
#define USB_PMAADDR           (APB1PERIPH_BASE + 0x00006000UL) /*!< USB_IP Packet Memory Area base address */


/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */  

#define TIM2                ((volatile uint32_t *)TIM2_BASE)
#define TIM3                ((volatile uint32_t *)TIM3_BASE)
#define TIM4                ((volatile uint32_t *)TIM4_BASE)
#define TIM5                ((volatile uint32_t *)TIM5_BASE)
#define TIM6                ((volatile uint32_t *)TIM6_BASE)
#define TIM7                ((volatile uint32_t *)TIM7_BASE)
#define TIM12               ((volatile uint32_t *)TIM12_BASE)
#define TIM13               ((volatile uint32_t *)TIM13_BASE)
#define TIM14               ((volatile uint32_t *)TIM14_BASE)
#define RTC                 ((RTC_TypeDef *)RTC_BASE)
#define WWDG                ((WWDG_TypeDef *)WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *)IWDG_BASE)
#define SPI2                ((volatile uint32_t *)SPI2_BASE)
#define SPI3                ((volatile uint32_t *)SPI3_BASE)
#define USART2              ((volatile uint32_t *)USART2_BASE)
#define USART3              ((volatile uint32_t *)USART3_BASE)
#define UART4               ((volatile uint32_t *)UART4_BASE)
#define UART5               ((volatile uint32_t *)UART5_BASE)
#define I2C1                ((volatile uint32_t *)I2C1_BASE)
#define I2C2                ((volatile uint32_t *)I2C2_BASE)
#define USB                 ((USB_TypeDef *)USB_BASE)
#define CAN1                ((volatile uint32_t *)CAN1_BASE)
#define BKP                 ((BKP_TypeDef *)BKP_BASE)
#define PWR                 ((PWR_TypeDef *)PWR_BASE)
#define DAC1                ((volatile uint32_t *)DAC_BASE)
#define DAC                 ((volatile uint32_t *)DAC_BASE) /* Kept for legacy purpose */
#define AFIO                ((volatile uint32_t *)AFIO_BASE)
#define EXTI                ((volatile uint32_t *)EXTI_BASE)
#define GPIOA               ((volatile uint32_t *)GPIOA_BASE)
#define GPIOB               ((volatile uint32_t *)GPIOB_BASE)
#define GPIOC               ((volatile uint32_t *)GPIOC_BASE)
#define GPIOD               ((volatile uint32_t *)GPIOD_BASE)
#define GPIOE               ((volatile uint32_t *)GPIOE_BASE)
#define GPIOF               ((volatile uint32_t *)GPIOF_BASE)
#define GPIOG               ((volatile uint32_t *)GPIOG_BASE)
#define ADC1                ((volatile uint32_t *)ADC1_BASE)
#define ADC2                ((volatile uint32_t *)ADC2_BASE)
#define ADC3                ((volatile uint32_t *)ADC3_BASE)
#define ADC12_COMMON        ((ADC_Common_TypeDef *)ADC1_BASE)
#define TIM1                ((volatile uint32_t *)TIM1_BASE)
#define SPI1                ((volatile uint32_t *)SPI1_BASE)
#define TIM8                ((volatile uint32_t *)TIM8_BASE)
#define USART1              ((volatile uint32_t *)USART1_BASE)
#define TIM9                ((volatile uint32_t *)TIM9_BASE)
#define TIM10               ((volatile uint32_t *)TIM10_BASE)
#define TIM11               ((volatile uint32_t *)TIM11_BASE)
#define SDIO                ((volatile uint32_t *)SDIO_BASE)
#define DMA1                ((volatile uint32_t *)DMA1_BASE)
#define DMA2                ((volatile uint32_t *)DMA2_BASE)
#define DMA1_Channel1       ((volatile uint32_t *)DMA1_Channel1_BASE)
#define DMA1_Channel2       ((volatile uint32_t *)DMA1_Channel2_BASE)
#define DMA1_Channel3       ((volatile uint32_t *)DMA1_Channel3_BASE)
#define DMA1_Channel4       ((volatile uint32_t *)DMA1_Channel4_BASE)
#define DMA1_Channel5       ((volatile uint32_t *)DMA1_Channel5_BASE)
#define DMA1_Channel6       ((volatile uint32_t *)DMA1_Channel6_BASE)
#define DMA1_Channel7       ((volatile uint32_t *)DMA1_Channel7_BASE)
#define DMA2_Channel1       ((volatile uint32_t *)DMA2_Channel1_BASE)
#define DMA2_Channel2       ((volatile uint32_t *)DMA2_Channel2_BASE)
#define DMA2_Channel3       ((volatile uint32_t *)DMA2_Channel3_BASE)
#define DMA2_Channel4       ((volatile uint32_t *)DMA2_Channel4_BASE)
#define DMA2_Channel5       ((volatile uint32_t *)DMA2_Channel5_BASE)
#define RCC                 ((volatile uint32_t *)RCC_BASE)
#define CRC                 ((volatile uint32_t *)CRC_BASE)
#define FLASH               ((volatile uint32_t *)FLASH_R_BASE)
#define OB                  ((OB_TypeDef *)OB_BASE)
#define FSMC_Bank1          ((FSMC_Bank1_TypeDef *)FSMC_BANK1_R_BASE)
#define FSMC_Bank1E         ((FSMC_Bank1E_TypeDef *)FSMC_BANK1E_R_BASE)
#define FSMC_Bank2_3        ((FSMC_Bank2_3_TypeDef *)FSMC_BANK2_3_R_BASE)
#define FSMC_Bank4          ((FSMC_Bank4_TypeDef *)FSMC_BANK4_R_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *)DBGMCU_BASE)


/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */
  
  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */
    
/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                       CRC calculation unit (CRC)                           */
/*                                                                            */
/******************************************************************************/

///*******************  Bit definition for CRC_DR register  *********************/
//#define CRC_DR_DR_Pos                       (0U)                               
//#define CRC_DR_DR_Msk                       (0xFFFFFFFFUL << CRC_DR_DR_Pos)     /*!< 0xFFFFFFFF */
//#define CRC_DR_DR                           CRC_DR_DR_Msk                      /*!< Data register bits */

///*******************  Bit definition for CRC_IDR register  ********************/
//#define CRC_IDR_IDR_Pos                     (0U)                               
//#define CRC_IDR_IDR_Msk                     (0xFFUL << CRC_IDR_IDR_Pos)         /*!< 0x000000FF */
//#define CRC_IDR_IDR                         CRC_IDR_IDR_Msk                    /*!< General-purpose 8-bit data register bits */

///********************  Bit definition for CRC_CR register  ********************/
//#define CRC_CR_RESET_Pos                    (0U)                               
//#define CRC_CR_RESET_Msk                    (0x1UL << CRC_CR_RESET_Pos)         /*!< 0x00000001 */
//#define CRC_CR_RESET                        CRC_CR_RESET_Msk                   /*!< RESET bit */

/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for PWR_CR register  ********************/
#define PWR_CR_LPDS_Pos                     (0U)                               
#define PWR_CR_LPDS_Msk                     (0x1UL << PWR_CR_LPDS_Pos)          /*!< 0x00000001 */
#define PWR_CR_LPDS                         PWR_CR_LPDS_Msk                    /*!< Low-Power Deepsleep */
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
#define PWR_CR_PLS_LEV0                      0x00000000U                           /*!< PVD level 2.2V */
#define PWR_CR_PLS_LEV1                      0x00000020U                           /*!< PVD level 2.3V */
#define PWR_CR_PLS_LEV2                      0x00000040U                           /*!< PVD level 2.4V */
#define PWR_CR_PLS_LEV3                      0x00000060U                           /*!< PVD level 2.5V */
#define PWR_CR_PLS_LEV4                      0x00000080U                           /*!< PVD level 2.6V */
#define PWR_CR_PLS_LEV5                      0x000000A0U                           /*!< PVD level 2.7V */
#define PWR_CR_PLS_LEV6                      0x000000C0U                           /*!< PVD level 2.8V */
#define PWR_CR_PLS_LEV7                      0x000000E0U                           /*!< PVD level 2.9V */

/* Legacy defines */
#define PWR_CR_PLS_2V2                       PWR_CR_PLS_LEV0
#define PWR_CR_PLS_2V3                       PWR_CR_PLS_LEV1
#define PWR_CR_PLS_2V4                       PWR_CR_PLS_LEV2
#define PWR_CR_PLS_2V5                       PWR_CR_PLS_LEV3
#define PWR_CR_PLS_2V6                       PWR_CR_PLS_LEV4
#define PWR_CR_PLS_2V7                       PWR_CR_PLS_LEV5
#define PWR_CR_PLS_2V8                       PWR_CR_PLS_LEV6
#define PWR_CR_PLS_2V9                       PWR_CR_PLS_LEV7

#define PWR_CR_DBP_Pos                      (8U)                               
#define PWR_CR_DBP_Msk                      (0x1UL << PWR_CR_DBP_Pos)           /*!< 0x00000100 */
#define PWR_CR_DBP                          PWR_CR_DBP_Msk                     /*!< Disable Backup Domain write protection */


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
#define PWR_CSR_EWUP_Pos                    (8U)                               
#define PWR_CSR_EWUP_Msk                    (0x1UL << PWR_CSR_EWUP_Pos)         /*!< 0x00000100 */
#define PWR_CSR_EWUP                        PWR_CSR_EWUP_Msk                   /*!< Enable WKUP pin */

/******************************************************************************/
/*                                                                            */
/*                            Backup registers                                */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for BKP_DR1 register  ********************/
#define BKP_DR1_D_Pos                       (0U)                               
#define BKP_DR1_D_Msk                       (0xFFFFUL << BKP_DR1_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR1_D                           BKP_DR1_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR2 register  ********************/
#define BKP_DR2_D_Pos                       (0U)                               
#define BKP_DR2_D_Msk                       (0xFFFFUL << BKP_DR2_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR2_D                           BKP_DR2_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR3 register  ********************/
#define BKP_DR3_D_Pos                       (0U)                               
#define BKP_DR3_D_Msk                       (0xFFFFUL << BKP_DR3_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR3_D                           BKP_DR3_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR4 register  ********************/
#define BKP_DR4_D_Pos                       (0U)                               
#define BKP_DR4_D_Msk                       (0xFFFFUL << BKP_DR4_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR4_D                           BKP_DR4_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR5 register  ********************/
#define BKP_DR5_D_Pos                       (0U)                               
#define BKP_DR5_D_Msk                       (0xFFFFUL << BKP_DR5_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR5_D                           BKP_DR5_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR6 register  ********************/
#define BKP_DR6_D_Pos                       (0U)                               
#define BKP_DR6_D_Msk                       (0xFFFFUL << BKP_DR6_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR6_D                           BKP_DR6_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR7 register  ********************/
#define BKP_DR7_D_Pos                       (0U)                               
#define BKP_DR7_D_Msk                       (0xFFFFUL << BKP_DR7_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR7_D                           BKP_DR7_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR8 register  ********************/
#define BKP_DR8_D_Pos                       (0U)                               
#define BKP_DR8_D_Msk                       (0xFFFFUL << BKP_DR8_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR8_D                           BKP_DR8_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR9 register  ********************/
#define BKP_DR9_D_Pos                       (0U)                               
#define BKP_DR9_D_Msk                       (0xFFFFUL << BKP_DR9_D_Pos)         /*!< 0x0000FFFF */
#define BKP_DR9_D                           BKP_DR9_D_Msk                      /*!< Backup data */

/*******************  Bit definition for BKP_DR10 register  *******************/
#define BKP_DR10_D_Pos                      (0U)                               
#define BKP_DR10_D_Msk                      (0xFFFFUL << BKP_DR10_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR10_D                          BKP_DR10_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR11 register  *******************/
#define BKP_DR11_D_Pos                      (0U)                               
#define BKP_DR11_D_Msk                      (0xFFFFUL << BKP_DR11_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR11_D                          BKP_DR11_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR12 register  *******************/
#define BKP_DR12_D_Pos                      (0U)                               
#define BKP_DR12_D_Msk                      (0xFFFFUL << BKP_DR12_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR12_D                          BKP_DR12_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR13 register  *******************/
#define BKP_DR13_D_Pos                      (0U)                               
#define BKP_DR13_D_Msk                      (0xFFFFUL << BKP_DR13_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR13_D                          BKP_DR13_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR14 register  *******************/
#define BKP_DR14_D_Pos                      (0U)                               
#define BKP_DR14_D_Msk                      (0xFFFFUL << BKP_DR14_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR14_D                          BKP_DR14_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR15 register  *******************/
#define BKP_DR15_D_Pos                      (0U)                               
#define BKP_DR15_D_Msk                      (0xFFFFUL << BKP_DR15_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR15_D                          BKP_DR15_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR16 register  *******************/
#define BKP_DR16_D_Pos                      (0U)                               
#define BKP_DR16_D_Msk                      (0xFFFFUL << BKP_DR16_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR16_D                          BKP_DR16_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR17 register  *******************/
#define BKP_DR17_D_Pos                      (0U)                               
#define BKP_DR17_D_Msk                      (0xFFFFUL << BKP_DR17_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR17_D                          BKP_DR17_D_Msk                     /*!< Backup data */

/******************  Bit definition for BKP_DR18 register  ********************/
#define BKP_DR18_D_Pos                      (0U)                               
#define BKP_DR18_D_Msk                      (0xFFFFUL << BKP_DR18_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR18_D                          BKP_DR18_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR19 register  *******************/
#define BKP_DR19_D_Pos                      (0U)                               
#define BKP_DR19_D_Msk                      (0xFFFFUL << BKP_DR19_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR19_D                          BKP_DR19_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR20 register  *******************/
#define BKP_DR20_D_Pos                      (0U)                               
#define BKP_DR20_D_Msk                      (0xFFFFUL << BKP_DR20_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR20_D                          BKP_DR20_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR21 register  *******************/
#define BKP_DR21_D_Pos                      (0U)                               
#define BKP_DR21_D_Msk                      (0xFFFFUL << BKP_DR21_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR21_D                          BKP_DR21_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR22 register  *******************/
#define BKP_DR22_D_Pos                      (0U)                               
#define BKP_DR22_D_Msk                      (0xFFFFUL << BKP_DR22_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR22_D                          BKP_DR22_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR23 register  *******************/
#define BKP_DR23_D_Pos                      (0U)                               
#define BKP_DR23_D_Msk                      (0xFFFFUL << BKP_DR23_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR23_D                          BKP_DR23_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR24 register  *******************/
#define BKP_DR24_D_Pos                      (0U)                               
#define BKP_DR24_D_Msk                      (0xFFFFUL << BKP_DR24_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR24_D                          BKP_DR24_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR25 register  *******************/
#define BKP_DR25_D_Pos                      (0U)                               
#define BKP_DR25_D_Msk                      (0xFFFFUL << BKP_DR25_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR25_D                          BKP_DR25_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR26 register  *******************/
#define BKP_DR26_D_Pos                      (0U)                               
#define BKP_DR26_D_Msk                      (0xFFFFUL << BKP_DR26_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR26_D                          BKP_DR26_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR27 register  *******************/
#define BKP_DR27_D_Pos                      (0U)                               
#define BKP_DR27_D_Msk                      (0xFFFFUL << BKP_DR27_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR27_D                          BKP_DR27_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR28 register  *******************/
#define BKP_DR28_D_Pos                      (0U)                               
#define BKP_DR28_D_Msk                      (0xFFFFUL << BKP_DR28_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR28_D                          BKP_DR28_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR29 register  *******************/
#define BKP_DR29_D_Pos                      (0U)                               
#define BKP_DR29_D_Msk                      (0xFFFFUL << BKP_DR29_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR29_D                          BKP_DR29_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR30 register  *******************/
#define BKP_DR30_D_Pos                      (0U)                               
#define BKP_DR30_D_Msk                      (0xFFFFUL << BKP_DR30_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR30_D                          BKP_DR30_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR31 register  *******************/
#define BKP_DR31_D_Pos                      (0U)                               
#define BKP_DR31_D_Msk                      (0xFFFFUL << BKP_DR31_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR31_D                          BKP_DR31_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR32 register  *******************/
#define BKP_DR32_D_Pos                      (0U)                               
#define BKP_DR32_D_Msk                      (0xFFFFUL << BKP_DR32_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR32_D                          BKP_DR32_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR33 register  *******************/
#define BKP_DR33_D_Pos                      (0U)                               
#define BKP_DR33_D_Msk                      (0xFFFFUL << BKP_DR33_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR33_D                          BKP_DR33_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR34 register  *******************/
#define BKP_DR34_D_Pos                      (0U)                               
#define BKP_DR34_D_Msk                      (0xFFFFUL << BKP_DR34_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR34_D                          BKP_DR34_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR35 register  *******************/
#define BKP_DR35_D_Pos                      (0U)                               
#define BKP_DR35_D_Msk                      (0xFFFFUL << BKP_DR35_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR35_D                          BKP_DR35_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR36 register  *******************/
#define BKP_DR36_D_Pos                      (0U)                               
#define BKP_DR36_D_Msk                      (0xFFFFUL << BKP_DR36_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR36_D                          BKP_DR36_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR37 register  *******************/
#define BKP_DR37_D_Pos                      (0U)                               
#define BKP_DR37_D_Msk                      (0xFFFFUL << BKP_DR37_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR37_D                          BKP_DR37_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR38 register  *******************/
#define BKP_DR38_D_Pos                      (0U)                               
#define BKP_DR38_D_Msk                      (0xFFFFUL << BKP_DR38_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR38_D                          BKP_DR38_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR39 register  *******************/
#define BKP_DR39_D_Pos                      (0U)                               
#define BKP_DR39_D_Msk                      (0xFFFFUL << BKP_DR39_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR39_D                          BKP_DR39_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR40 register  *******************/
#define BKP_DR40_D_Pos                      (0U)                               
#define BKP_DR40_D_Msk                      (0xFFFFUL << BKP_DR40_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR40_D                          BKP_DR40_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR41 register  *******************/
#define BKP_DR41_D_Pos                      (0U)                               
#define BKP_DR41_D_Msk                      (0xFFFFUL << BKP_DR41_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR41_D                          BKP_DR41_D_Msk                     /*!< Backup data */

/*******************  Bit definition for BKP_DR42 register  *******************/
#define BKP_DR42_D_Pos                      (0U)                               
#define BKP_DR42_D_Msk                      (0xFFFFUL << BKP_DR42_D_Pos)        /*!< 0x0000FFFF */
#define BKP_DR42_D                          BKP_DR42_D_Msk                     /*!< Backup data */

#define RTC_BKP_NUMBER 42

/******************  Bit definition for BKP_RTCCR register  *******************/
#define BKP_RTCCR_CAL_Pos                   (0U)                               
#define BKP_RTCCR_CAL_Msk                   (0x7FUL << BKP_RTCCR_CAL_Pos)       /*!< 0x0000007F */
#define BKP_RTCCR_CAL                       BKP_RTCCR_CAL_Msk                  /*!< Calibration value */
#define BKP_RTCCR_CCO_Pos                   (7U)                               
#define BKP_RTCCR_CCO_Msk                   (0x1UL << BKP_RTCCR_CCO_Pos)        /*!< 0x00000080 */
#define BKP_RTCCR_CCO                       BKP_RTCCR_CCO_Msk                  /*!< Calibration Clock Output */
#define BKP_RTCCR_ASOE_Pos                  (8U)                               
#define BKP_RTCCR_ASOE_Msk                  (0x1UL << BKP_RTCCR_ASOE_Pos)       /*!< 0x00000100 */
#define BKP_RTCCR_ASOE                      BKP_RTCCR_ASOE_Msk                 /*!< Alarm or Second Output Enable */
#define BKP_RTCCR_ASOS_Pos                  (9U)                               
#define BKP_RTCCR_ASOS_Msk                  (0x1UL << BKP_RTCCR_ASOS_Pos)       /*!< 0x00000200 */
#define BKP_RTCCR_ASOS                      BKP_RTCCR_ASOS_Msk                 /*!< Alarm or Second Output Selection */

/********************  Bit definition for BKP_CR register  ********************/
#define BKP_CR_TPE_Pos                      (0U)                               
#define BKP_CR_TPE_Msk                      (0x1UL << BKP_CR_TPE_Pos)           /*!< 0x00000001 */
#define BKP_CR_TPE                          BKP_CR_TPE_Msk                     /*!< TAMPER pin enable */
#define BKP_CR_TPAL_Pos                     (1U)                               
#define BKP_CR_TPAL_Msk                     (0x1UL << BKP_CR_TPAL_Pos)          /*!< 0x00000002 */
#define BKP_CR_TPAL                         BKP_CR_TPAL_Msk                    /*!< TAMPER pin active level */

/*******************  Bit definition for BKP_CSR register  ********************/
#define BKP_CSR_CTE_Pos                     (0U)                               
#define BKP_CSR_CTE_Msk                     (0x1UL << BKP_CSR_CTE_Pos)          /*!< 0x00000001 */
#define BKP_CSR_CTE                         BKP_CSR_CTE_Msk                    /*!< Clear Tamper event */
#define BKP_CSR_CTI_Pos                     (1U)                               
#define BKP_CSR_CTI_Msk                     (0x1UL << BKP_CSR_CTI_Pos)          /*!< 0x00000002 */
#define BKP_CSR_CTI                         BKP_CSR_CTI_Msk                    /*!< Clear Tamper Interrupt */
#define BKP_CSR_TPIE_Pos                    (2U)                               
#define BKP_CSR_TPIE_Msk                    (0x1UL << BKP_CSR_TPIE_Pos)         /*!< 0x00000004 */
#define BKP_CSR_TPIE                        BKP_CSR_TPIE_Msk                   /*!< TAMPER Pin interrupt enable */
#define BKP_CSR_TEF_Pos                     (8U)                               
#define BKP_CSR_TEF_Msk                     (0x1UL << BKP_CSR_TEF_Pos)          /*!< 0x00000100 */
#define BKP_CSR_TEF                         BKP_CSR_TEF_Msk                    /*!< Tamper Event Flag */
#define BKP_CSR_TIF_Pos                     (9U)                               
#define BKP_CSR_TIF_Msk                     (0x1UL << BKP_CSR_TIF_Pos)          /*!< 0x00000200 */
#define BKP_CSR_TIF                         BKP_CSR_TIF_Msk                    /*!< Tamper Interrupt Flag */

/******************************************************************************/
/*                                                                            */
/*                             Real-Time Clock                                */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for RTC_CRH register  ********************/
#define RTC_CRH_SECIE_Pos                   (0U)                               
#define RTC_CRH_SECIE_Msk                   (0x1UL << RTC_CRH_SECIE_Pos)        /*!< 0x00000001 */
#define RTC_CRH_SECIE                       RTC_CRH_SECIE_Msk                  /*!< Second Interrupt Enable */
#define RTC_CRH_ALRIE_Pos                   (1U)                               
#define RTC_CRH_ALRIE_Msk                   (0x1UL << RTC_CRH_ALRIE_Pos)        /*!< 0x00000002 */
#define RTC_CRH_ALRIE                       RTC_CRH_ALRIE_Msk                  /*!< Alarm Interrupt Enable */
#define RTC_CRH_OWIE_Pos                    (2U)                               
#define RTC_CRH_OWIE_Msk                    (0x1UL << RTC_CRH_OWIE_Pos)         /*!< 0x00000004 */
#define RTC_CRH_OWIE                        RTC_CRH_OWIE_Msk                   /*!< OverfloW Interrupt Enable */

/*******************  Bit definition for RTC_CRL register  ********************/
#define RTC_CRL_SECF_Pos                    (0U)                               
#define RTC_CRL_SECF_Msk                    (0x1UL << RTC_CRL_SECF_Pos)         /*!< 0x00000001 */
#define RTC_CRL_SECF                        RTC_CRL_SECF_Msk                   /*!< Second Flag */
#define RTC_CRL_ALRF_Pos                    (1U)                               
#define RTC_CRL_ALRF_Msk                    (0x1UL << RTC_CRL_ALRF_Pos)         /*!< 0x00000002 */
#define RTC_CRL_ALRF                        RTC_CRL_ALRF_Msk                   /*!< Alarm Flag */
#define RTC_CRL_OWF_Pos                     (2U)                               
#define RTC_CRL_OWF_Msk                     (0x1UL << RTC_CRL_OWF_Pos)          /*!< 0x00000004 */
#define RTC_CRL_OWF                         RTC_CRL_OWF_Msk                    /*!< OverfloW Flag */
#define RTC_CRL_RSF_Pos                     (3U)                               
#define RTC_CRL_RSF_Msk                     (0x1UL << RTC_CRL_RSF_Pos)          /*!< 0x00000008 */
#define RTC_CRL_RSF                         RTC_CRL_RSF_Msk                    /*!< Registers Synchronized Flag */
#define RTC_CRL_CNF_Pos                     (4U)                               
#define RTC_CRL_CNF_Msk                     (0x1UL << RTC_CRL_CNF_Pos)          /*!< 0x00000010 */
#define RTC_CRL_CNF                         RTC_CRL_CNF_Msk                    /*!< Configuration Flag */
#define RTC_CRL_RTOFF_Pos                   (5U)                               
#define RTC_CRL_RTOFF_Msk                   (0x1UL << RTC_CRL_RTOFF_Pos)        /*!< 0x00000020 */
#define RTC_CRL_RTOFF                       RTC_CRL_RTOFF_Msk                  /*!< RTC operation OFF */

/*******************  Bit definition for RTC_PRLH register  *******************/
#define RTC_PRLH_PRL_Pos                    (0U)                               
#define RTC_PRLH_PRL_Msk                    (0xFUL << RTC_PRLH_PRL_Pos)         /*!< 0x0000000F */
#define RTC_PRLH_PRL                        RTC_PRLH_PRL_Msk                   /*!< RTC Prescaler Reload Value High */

/*******************  Bit definition for RTC_PRLL register  *******************/
#define RTC_PRLL_PRL_Pos                    (0U)                               
#define RTC_PRLL_PRL_Msk                    (0xFFFFUL << RTC_PRLL_PRL_Pos)      /*!< 0x0000FFFF */
#define RTC_PRLL_PRL                        RTC_PRLL_PRL_Msk                   /*!< RTC Prescaler Reload Value Low */

/*******************  Bit definition for RTC_DIVH register  *******************/
#define RTC_DIVH_RTC_DIV_Pos                (0U)                               
#define RTC_DIVH_RTC_DIV_Msk                (0xFUL << RTC_DIVH_RTC_DIV_Pos)     /*!< 0x0000000F */
#define RTC_DIVH_RTC_DIV                    RTC_DIVH_RTC_DIV_Msk               /*!< RTC Clock Divider High */

/*******************  Bit definition for RTC_DIVL register  *******************/
#define RTC_DIVL_RTC_DIV_Pos                (0U)                               
#define RTC_DIVL_RTC_DIV_Msk                (0xFFFFUL << RTC_DIVL_RTC_DIV_Pos)  /*!< 0x0000FFFF */
#define RTC_DIVL_RTC_DIV                    RTC_DIVL_RTC_DIV_Msk               /*!< RTC Clock Divider Low */

/*******************  Bit definition for RTC_CNTH register  *******************/
#define RTC_CNTH_RTC_CNT_Pos                (0U)                               
#define RTC_CNTH_RTC_CNT_Msk                (0xFFFFUL << RTC_CNTH_RTC_CNT_Pos)  /*!< 0x0000FFFF */
#define RTC_CNTH_RTC_CNT                    RTC_CNTH_RTC_CNT_Msk               /*!< RTC Counter High */

/*******************  Bit definition for RTC_CNTL register  *******************/
#define RTC_CNTL_RTC_CNT_Pos                (0U)                               
#define RTC_CNTL_RTC_CNT_Msk                (0xFFFFUL << RTC_CNTL_RTC_CNT_Pos)  /*!< 0x0000FFFF */
#define RTC_CNTL_RTC_CNT                    RTC_CNTL_RTC_CNT_Msk               /*!< RTC Counter Low */

/*******************  Bit definition for RTC_ALRH register  *******************/
#define RTC_ALRH_RTC_ALR_Pos                (0U)                               
#define RTC_ALRH_RTC_ALR_Msk                (0xFFFFUL << RTC_ALRH_RTC_ALR_Pos)  /*!< 0x0000FFFF */
#define RTC_ALRH_RTC_ALR                    RTC_ALRH_RTC_ALR_Msk               /*!< RTC Alarm High */

/*******************  Bit definition for RTC_ALRL register  *******************/
#define RTC_ALRL_RTC_ALR_Pos                (0U)                               
#define RTC_ALRL_RTC_ALR_Msk                (0xFFFFUL << RTC_ALRL_RTC_ALR_Pos)  /*!< 0x0000FFFF */
#define RTC_ALRL_RTC_ALR                    RTC_ALRL_RTC_ALR_Msk               /*!< RTC Alarm Low */

/******************************************************************************/
/*                                                                            */
/*                        Independent WATCHDOG (IWDG)                         */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY_Pos                     (0U)                               
#define IWDG_KR_KEY_Msk                     (0xFFFFUL << IWDG_KR_KEY_Pos)       /*!< 0x0000FFFF */
#define IWDG_KR_KEY                         IWDG_KR_KEY_Msk                    /*!< Key value (write only, read 0000h) */

/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR_Pos                      (0U)                               
#define IWDG_PR_PR_Msk                      (0x7UL << IWDG_PR_PR_Pos)           /*!< 0x00000007 */
#define IWDG_PR_PR                          IWDG_PR_PR_Msk                     /*!< PR[2:0] (Prescaler divider) */
#define IWDG_PR_PR_0                        (0x1UL << IWDG_PR_PR_Pos)           /*!< 0x00000001 */
#define IWDG_PR_PR_1                        (0x2UL << IWDG_PR_PR_Pos)           /*!< 0x00000002 */
#define IWDG_PR_PR_2                        (0x4UL << IWDG_PR_PR_Pos)           /*!< 0x00000004 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL_Pos                     (0U)                               
#define IWDG_RLR_RL_Msk                     (0xFFFUL << IWDG_RLR_RL_Pos)        /*!< 0x00000FFF */
#define IWDG_RLR_RL                         IWDG_RLR_RL_Msk                    /*!< Watchdog counter reload value */

/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU_Pos                     (0U)                               
#define IWDG_SR_PVU_Msk                     (0x1UL << IWDG_SR_PVU_Pos)          /*!< 0x00000001 */
#define IWDG_SR_PVU                         IWDG_SR_PVU_Msk                    /*!< Watchdog prescaler value update */
#define IWDG_SR_RVU_Pos                     (1U)                               
#define IWDG_SR_RVU_Msk                     (0x1UL << IWDG_SR_RVU_Pos)          /*!< 0x00000002 */
#define IWDG_SR_RVU                         IWDG_SR_RVU_Msk                    /*!< Watchdog counter reload value update */

/******************************************************************************/
/*                                                                            */
/*                         Window WATCHDOG (WWDG)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for WWDG_CR register  ********************/
#define WWDG_CR_T_Pos                       (0U)                               
#define WWDG_CR_T_Msk                       (0x7FUL << WWDG_CR_T_Pos)           /*!< 0x0000007F */
#define WWDG_CR_T                           WWDG_CR_T_Msk                      /*!< T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define WWDG_CR_T_0                         (0x01UL << WWDG_CR_T_Pos)           /*!< 0x00000001 */
#define WWDG_CR_T_1                         (0x02UL << WWDG_CR_T_Pos)           /*!< 0x00000002 */
#define WWDG_CR_T_2                         (0x04UL << WWDG_CR_T_Pos)           /*!< 0x00000004 */
#define WWDG_CR_T_3                         (0x08UL << WWDG_CR_T_Pos)           /*!< 0x00000008 */
#define WWDG_CR_T_4                         (0x10UL << WWDG_CR_T_Pos)           /*!< 0x00000010 */
#define WWDG_CR_T_5                         (0x20UL << WWDG_CR_T_Pos)           /*!< 0x00000020 */
#define WWDG_CR_T_6                         (0x40UL << WWDG_CR_T_Pos)           /*!< 0x00000040 */

/* Legacy defines */
#define  WWDG_CR_T0 WWDG_CR_T_0
#define  WWDG_CR_T1 WWDG_CR_T_1
#define  WWDG_CR_T2 WWDG_CR_T_2
#define  WWDG_CR_T3 WWDG_CR_T_3
#define  WWDG_CR_T4 WWDG_CR_T_4
#define  WWDG_CR_T5 WWDG_CR_T_5
#define  WWDG_CR_T6 WWDG_CR_T_6

#define WWDG_CR_WDGA_Pos                    (7U)                               
#define WWDG_CR_WDGA_Msk                    (0x1UL << WWDG_CR_WDGA_Pos)         /*!< 0x00000080 */
#define WWDG_CR_WDGA                        WWDG_CR_WDGA_Msk                   /*!< Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define WWDG_CFR_W_Pos                      (0U)                               
#define WWDG_CFR_W_Msk                      (0x7FUL << WWDG_CFR_W_Pos)          /*!< 0x0000007F */
#define WWDG_CFR_W                          WWDG_CFR_W_Msk                     /*!< W[6:0] bits (7-bit window value) */
#define WWDG_CFR_W_0                        (0x01UL << WWDG_CFR_W_Pos)          /*!< 0x00000001 */
#define WWDG_CFR_W_1                        (0x02UL << WWDG_CFR_W_Pos)          /*!< 0x00000002 */
#define WWDG_CFR_W_2                        (0x04UL << WWDG_CFR_W_Pos)          /*!< 0x00000004 */
#define WWDG_CFR_W_3                        (0x08UL << WWDG_CFR_W_Pos)          /*!< 0x00000008 */
#define WWDG_CFR_W_4                        (0x10UL << WWDG_CFR_W_Pos)          /*!< 0x00000010 */
#define WWDG_CFR_W_5                        (0x20UL << WWDG_CFR_W_Pos)          /*!< 0x00000020 */
#define WWDG_CFR_W_6                        (0x40UL << WWDG_CFR_W_Pos)          /*!< 0x00000040 */

/* Legacy defines */
#define  WWDG_CFR_W0 WWDG_CFR_W_0
#define  WWDG_CFR_W1 WWDG_CFR_W_1
#define  WWDG_CFR_W2 WWDG_CFR_W_2
#define  WWDG_CFR_W3 WWDG_CFR_W_3
#define  WWDG_CFR_W4 WWDG_CFR_W_4
#define  WWDG_CFR_W5 WWDG_CFR_W_5
#define  WWDG_CFR_W6 WWDG_CFR_W_6

#define WWDG_CFR_WDGTB_Pos                  (7U)                               
#define WWDG_CFR_WDGTB_Msk                  (0x3UL << WWDG_CFR_WDGTB_Pos)       /*!< 0x00000180 */
#define WWDG_CFR_WDGTB                      WWDG_CFR_WDGTB_Msk                 /*!< WDGTB[1:0] bits (Timer Base) */
#define WWDG_CFR_WDGTB_0                    (0x1UL << WWDG_CFR_WDGTB_Pos)       /*!< 0x00000080 */
#define WWDG_CFR_WDGTB_1                    (0x2UL << WWDG_CFR_WDGTB_Pos)       /*!< 0x00000100 */

/* Legacy defines */
#define  WWDG_CFR_WDGTB0 WWDG_CFR_WDGTB_0
#define  WWDG_CFR_WDGTB1 WWDG_CFR_WDGTB_1

#define WWDG_CFR_EWI_Pos                    (9U)                               
#define WWDG_CFR_EWI_Msk                    (0x1UL << WWDG_CFR_EWI_Pos)         /*!< 0x00000200 */
#define WWDG_CFR_EWI                        WWDG_CFR_EWI_Msk                   /*!< Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_SR register  ********************/
#define WWDG_SR_EWIF_Pos                    (0U)                               
#define WWDG_SR_EWIF_Msk                    (0x1UL << WWDG_SR_EWIF_Pos)         /*!< 0x00000001 */
#define WWDG_SR_EWIF                        WWDG_SR_EWIF_Msk                   /*!< Early Wakeup Interrupt Flag */

/******************************************************************************/
/*                                                                            */
/*                       Flexible Static Memory Controller                    */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for FSMC_BCRx (x=1..4) register  **********/
#define FSMC_BCRx_MBKEN_Pos                 (0U)                               
#define FSMC_BCRx_MBKEN_Msk                 (0x1UL << FSMC_BCRx_MBKEN_Pos)      /*!< 0x00000001 */
#define FSMC_BCRx_MBKEN                     FSMC_BCRx_MBKEN_Msk                /*!< Memory bank enable bit */
#define FSMC_BCRx_MUXEN_Pos                 (1U)                               
#define FSMC_BCRx_MUXEN_Msk                 (0x1UL << FSMC_BCRx_MUXEN_Pos)      /*!< 0x00000002 */
#define FSMC_BCRx_MUXEN                     FSMC_BCRx_MUXEN_Msk                /*!< Address/data multiplexing enable bit */

#define FSMC_BCRx_MTYP_Pos                  (2U)                               
#define FSMC_BCRx_MTYP_Msk                  (0x3UL << FSMC_BCRx_MTYP_Pos)       /*!< 0x0000000C */
#define FSMC_BCRx_MTYP                      FSMC_BCRx_MTYP_Msk                 /*!< MTYP[1:0] bits (Memory type) */
#define FSMC_BCRx_MTYP_0                    (0x1UL << FSMC_BCRx_MTYP_Pos)       /*!< 0x00000004 */
#define FSMC_BCRx_MTYP_1                    (0x2UL << FSMC_BCRx_MTYP_Pos)       /*!< 0x00000008 */

#define FSMC_BCRx_MWID_Pos                  (4U)                               
#define FSMC_BCRx_MWID_Msk                  (0x3UL << FSMC_BCRx_MWID_Pos)       /*!< 0x00000030 */
#define FSMC_BCRx_MWID                      FSMC_BCRx_MWID_Msk                 /*!< MWID[1:0] bits (Memory data bus width) */
#define FSMC_BCRx_MWID_0                    (0x1UL << FSMC_BCRx_MWID_Pos)       /*!< 0x00000010 */
#define FSMC_BCRx_MWID_1                    (0x2UL << FSMC_BCRx_MWID_Pos)       /*!< 0x00000020 */

#define FSMC_BCRx_FACCEN_Pos                (6U)                               
#define FSMC_BCRx_FACCEN_Msk                (0x1UL << FSMC_BCRx_FACCEN_Pos)     /*!< 0x00000040 */
#define FSMC_BCRx_FACCEN                    FSMC_BCRx_FACCEN_Msk               /*!< Flash access enable */
#define FSMC_BCRx_BURSTEN_Pos               (8U)                               
#define FSMC_BCRx_BURSTEN_Msk               (0x1UL << FSMC_BCRx_BURSTEN_Pos)    /*!< 0x00000100 */
#define FSMC_BCRx_BURSTEN                   FSMC_BCRx_BURSTEN_Msk              /*!< Burst enable bit */
#define FSMC_BCRx_WAITPOL_Pos               (9U)                               
#define FSMC_BCRx_WAITPOL_Msk               (0x1UL << FSMC_BCRx_WAITPOL_Pos)    /*!< 0x00000200 */
#define FSMC_BCRx_WAITPOL                   FSMC_BCRx_WAITPOL_Msk              /*!< Wait signal polarity bit */
#define FSMC_BCRx_WRAPMOD_Pos               (10U)                              
#define FSMC_BCRx_WRAPMOD_Msk               (0x1UL << FSMC_BCRx_WRAPMOD_Pos)    /*!< 0x00000400 */
#define FSMC_BCRx_WRAPMOD                   FSMC_BCRx_WRAPMOD_Msk              /*!< Wrapped burst mode support */
#define FSMC_BCRx_WAITCFG_Pos               (11U)                              
#define FSMC_BCRx_WAITCFG_Msk               (0x1UL << FSMC_BCRx_WAITCFG_Pos)    /*!< 0x00000800 */
#define FSMC_BCRx_WAITCFG                   FSMC_BCRx_WAITCFG_Msk              /*!< Wait timing configuration */
#define FSMC_BCRx_WREN_Pos                  (12U)                              
#define FSMC_BCRx_WREN_Msk                  (0x1UL << FSMC_BCRx_WREN_Pos)       /*!< 0x00001000 */
#define FSMC_BCRx_WREN                      FSMC_BCRx_WREN_Msk                 /*!< Write enable bit */
#define FSMC_BCRx_WAITEN_Pos                (13U)                              
#define FSMC_BCRx_WAITEN_Msk                (0x1UL << FSMC_BCRx_WAITEN_Pos)     /*!< 0x00002000 */
#define FSMC_BCRx_WAITEN                    FSMC_BCRx_WAITEN_Msk               /*!< Wait enable bit */
#define FSMC_BCRx_EXTMOD_Pos                (14U)                              
#define FSMC_BCRx_EXTMOD_Msk                (0x1UL << FSMC_BCRx_EXTMOD_Pos)     /*!< 0x00004000 */
#define FSMC_BCRx_EXTMOD                    FSMC_BCRx_EXTMOD_Msk               /*!< Extended mode enable */
#define FSMC_BCRx_ASYNCWAIT_Pos             (15U)                              
#define FSMC_BCRx_ASYNCWAIT_Msk             (0x1UL << FSMC_BCRx_ASYNCWAIT_Pos)  /*!< 0x00008000 */
#define FSMC_BCRx_ASYNCWAIT                 FSMC_BCRx_ASYNCWAIT_Msk            /*!< Asynchronous wait */
#define FSMC_BCRx_CBURSTRW_Pos              (19U)                              
#define FSMC_BCRx_CBURSTRW_Msk              (0x1UL << FSMC_BCRx_CBURSTRW_Pos)   /*!< 0x00080000 */
#define FSMC_BCRx_CBURSTRW                  FSMC_BCRx_CBURSTRW_Msk             /*!< Write burst enable */

/******************  Bit definition for FSMC_BTRx (x=1..4) register  ******/
#define FSMC_BTRx_ADDSET_Pos                (0U)                               
#define FSMC_BTRx_ADDSET_Msk                (0xFUL << FSMC_BTRx_ADDSET_Pos)     /*!< 0x0000000F */
#define FSMC_BTRx_ADDSET                    FSMC_BTRx_ADDSET_Msk               /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define FSMC_BTRx_ADDSET_0                  (0x1UL << FSMC_BTRx_ADDSET_Pos)     /*!< 0x00000001 */
#define FSMC_BTRx_ADDSET_1                  (0x2UL << FSMC_BTRx_ADDSET_Pos)     /*!< 0x00000002 */
#define FSMC_BTRx_ADDSET_2                  (0x4UL << FSMC_BTRx_ADDSET_Pos)     /*!< 0x00000004 */
#define FSMC_BTRx_ADDSET_3                  (0x8UL << FSMC_BTRx_ADDSET_Pos)     /*!< 0x00000008 */

#define FSMC_BTRx_ADDHLD_Pos                (4U)                               
#define FSMC_BTRx_ADDHLD_Msk                (0xFUL << FSMC_BTRx_ADDHLD_Pos)     /*!< 0x000000F0 */
#define FSMC_BTRx_ADDHLD                    FSMC_BTRx_ADDHLD_Msk               /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define FSMC_BTRx_ADDHLD_0                  (0x1UL << FSMC_BTRx_ADDHLD_Pos)     /*!< 0x00000010 */
#define FSMC_BTRx_ADDHLD_1                  (0x2UL << FSMC_BTRx_ADDHLD_Pos)     /*!< 0x00000020 */
#define FSMC_BTRx_ADDHLD_2                  (0x4UL << FSMC_BTRx_ADDHLD_Pos)     /*!< 0x00000040 */
#define FSMC_BTRx_ADDHLD_3                  (0x8UL << FSMC_BTRx_ADDHLD_Pos)     /*!< 0x00000080 */

#define FSMC_BTRx_DATAST_Pos                (8U)                               
#define FSMC_BTRx_DATAST_Msk                (0xFFUL << FSMC_BTRx_DATAST_Pos)    /*!< 0x0000FF00 */
#define FSMC_BTRx_DATAST                    FSMC_BTRx_DATAST_Msk               /*!< DATAST [3:0] bits (Data-phase duration) */
#define FSMC_BTRx_DATAST_0                  (0x01UL << FSMC_BTRx_DATAST_Pos)    /*!< 0x00000100 */
#define FSMC_BTRx_DATAST_1                  (0x02UL << FSMC_BTRx_DATAST_Pos)    /*!< 0x00000200 */
#define FSMC_BTRx_DATAST_2                  (0x04UL << FSMC_BTRx_DATAST_Pos)    /*!< 0x00000400 */
#define FSMC_BTRx_DATAST_3                  (0x08UL << FSMC_BTRx_DATAST_Pos)    /*!< 0x00000800 */
#define FSMC_BTRx_DATAST_4                  (0x10UL << FSMC_BTRx_DATAST_Pos)    /*!< 0x00001000 */
#define FSMC_BTRx_DATAST_5                  (0x20UL << FSMC_BTRx_DATAST_Pos)    /*!< 0x00002000 */
#define FSMC_BTRx_DATAST_6                  (0x40UL << FSMC_BTRx_DATAST_Pos)    /*!< 0x00004000 */
#define FSMC_BTRx_DATAST_7                  (0x80UL << FSMC_BTRx_DATAST_Pos)    /*!< 0x00008000 */

#define FSMC_BTRx_BUSTURN_Pos               (16U)                              
#define FSMC_BTRx_BUSTURN_Msk               (0xFUL << FSMC_BTRx_BUSTURN_Pos)    /*!< 0x000F0000 */
#define FSMC_BTRx_BUSTURN                   FSMC_BTRx_BUSTURN_Msk              /*!< BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FSMC_BTRx_BUSTURN_0                 (0x1UL << FSMC_BTRx_BUSTURN_Pos)    /*!< 0x00010000 */
#define FSMC_BTRx_BUSTURN_1                 (0x2UL << FSMC_BTRx_BUSTURN_Pos)    /*!< 0x00020000 */
#define FSMC_BTRx_BUSTURN_2                 (0x4UL << FSMC_BTRx_BUSTURN_Pos)    /*!< 0x00040000 */
#define FSMC_BTRx_BUSTURN_3                 (0x8UL << FSMC_BTRx_BUSTURN_Pos)    /*!< 0x00080000 */

#define FSMC_BTRx_CLKDIV_Pos                (20U)                              
#define FSMC_BTRx_CLKDIV_Msk                (0xFUL << FSMC_BTRx_CLKDIV_Pos)     /*!< 0x00F00000 */
#define FSMC_BTRx_CLKDIV                    FSMC_BTRx_CLKDIV_Msk               /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define FSMC_BTRx_CLKDIV_0                  (0x1UL << FSMC_BTRx_CLKDIV_Pos)     /*!< 0x00100000 */
#define FSMC_BTRx_CLKDIV_1                  (0x2UL << FSMC_BTRx_CLKDIV_Pos)     /*!< 0x00200000 */
#define FSMC_BTRx_CLKDIV_2                  (0x4UL << FSMC_BTRx_CLKDIV_Pos)     /*!< 0x00400000 */
#define FSMC_BTRx_CLKDIV_3                  (0x8UL << FSMC_BTRx_CLKDIV_Pos)     /*!< 0x00800000 */

#define FSMC_BTRx_DATLAT_Pos                (24U)                              
#define FSMC_BTRx_DATLAT_Msk                (0xFUL << FSMC_BTRx_DATLAT_Pos)     /*!< 0x0F000000 */
#define FSMC_BTRx_DATLAT                    FSMC_BTRx_DATLAT_Msk               /*!< DATLA[3:0] bits (Data latency) */
#define FSMC_BTRx_DATLAT_0                  (0x1UL << FSMC_BTRx_DATLAT_Pos)     /*!< 0x01000000 */
#define FSMC_BTRx_DATLAT_1                  (0x2UL << FSMC_BTRx_DATLAT_Pos)     /*!< 0x02000000 */
#define FSMC_BTRx_DATLAT_2                  (0x4UL << FSMC_BTRx_DATLAT_Pos)     /*!< 0x04000000 */
#define FSMC_BTRx_DATLAT_3                  (0x8UL << FSMC_BTRx_DATLAT_Pos)     /*!< 0x08000000 */

#define FSMC_BTRx_ACCMOD_Pos                (28U)                              
#define FSMC_BTRx_ACCMOD_Msk                (0x3UL << FSMC_BTRx_ACCMOD_Pos)     /*!< 0x30000000 */
#define FSMC_BTRx_ACCMOD                    FSMC_BTRx_ACCMOD_Msk               /*!< ACCMOD[1:0] bits (Access mode) */
#define FSMC_BTRx_ACCMOD_0                  (0x1UL << FSMC_BTRx_ACCMOD_Pos)     /*!< 0x10000000 */
#define FSMC_BTRx_ACCMOD_1                  (0x2UL << FSMC_BTRx_ACCMOD_Pos)     /*!< 0x20000000 */

/******************  Bit definition for FSMC_BWTRx (x=1..4) register  ******/
#define FSMC_BWTRx_ADDSET_Pos               (0U)                               
#define FSMC_BWTRx_ADDSET_Msk               (0xFUL << FSMC_BWTRx_ADDSET_Pos)    /*!< 0x0000000F */
#define FSMC_BWTRx_ADDSET                   FSMC_BWTRx_ADDSET_Msk              /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define FSMC_BWTRx_ADDSET_0                 (0x1UL << FSMC_BWTRx_ADDSET_Pos)    /*!< 0x00000001 */
#define FSMC_BWTRx_ADDSET_1                 (0x2UL << FSMC_BWTRx_ADDSET_Pos)    /*!< 0x00000002 */
#define FSMC_BWTRx_ADDSET_2                 (0x4UL << FSMC_BWTRx_ADDSET_Pos)    /*!< 0x00000004 */
#define FSMC_BWTRx_ADDSET_3                 (0x8UL << FSMC_BWTRx_ADDSET_Pos)    /*!< 0x00000008 */

#define FSMC_BWTRx_ADDHLD_Pos               (4U)                               
#define FSMC_BWTRx_ADDHLD_Msk               (0xFUL << FSMC_BWTRx_ADDHLD_Pos)    /*!< 0x000000F0 */
#define FSMC_BWTRx_ADDHLD                   FSMC_BWTRx_ADDHLD_Msk              /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define FSMC_BWTRx_ADDHLD_0                 (0x1UL << FSMC_BWTRx_ADDHLD_Pos)    /*!< 0x00000010 */
#define FSMC_BWTRx_ADDHLD_1                 (0x2UL << FSMC_BWTRx_ADDHLD_Pos)    /*!< 0x00000020 */
#define FSMC_BWTRx_ADDHLD_2                 (0x4UL << FSMC_BWTRx_ADDHLD_Pos)    /*!< 0x00000040 */
#define FSMC_BWTRx_ADDHLD_3                 (0x8UL << FSMC_BWTRx_ADDHLD_Pos)    /*!< 0x00000080 */

#define FSMC_BWTRx_DATAST_Pos               (8U)                               
#define FSMC_BWTRx_DATAST_Msk               (0xFFUL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x0000FF00 */
#define FSMC_BWTRx_DATAST                   FSMC_BWTRx_DATAST_Msk              /*!< DATAST [3:0] bits (Data-phase duration) */
#define FSMC_BWTRx_DATAST_0                 (0x01UL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x00000100 */
#define FSMC_BWTRx_DATAST_1                 (0x02UL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x00000200 */
#define FSMC_BWTRx_DATAST_2                 (0x04UL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x00000400 */
#define FSMC_BWTRx_DATAST_3                 (0x08UL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x00000800 */
#define FSMC_BWTRx_DATAST_4                 (0x10UL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x00001000 */
#define FSMC_BWTRx_DATAST_5                 (0x20UL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x00002000 */
#define FSMC_BWTRx_DATAST_6                 (0x40UL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x00004000 */
#define FSMC_BWTRx_DATAST_7                 (0x80UL << FSMC_BWTRx_DATAST_Pos)   /*!< 0x00008000 */

#define FSMC_BWTRx_BUSTURN_Pos              (16U)                              
#define FSMC_BWTRx_BUSTURN_Msk              (0xFUL << FSMC_BWTRx_BUSTURN_Pos)   /*!< 0x000F0000 */
#define FSMC_BWTRx_BUSTURN                  FSMC_BWTRx_BUSTURN_Msk             /*!< BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FSMC_BWTRx_BUSTURN_0                (0x1UL << FSMC_BWTRx_BUSTURN_Pos)   /*!< 0x00010000 */
#define FSMC_BWTRx_BUSTURN_1                (0x2UL << FSMC_BWTRx_BUSTURN_Pos)   /*!< 0x00020000 */
#define FSMC_BWTRx_BUSTURN_2                (0x4UL << FSMC_BWTRx_BUSTURN_Pos)   /*!< 0x00040000 */
#define FSMC_BWTRx_BUSTURN_3                (0x8UL << FSMC_BWTRx_BUSTURN_Pos)   /*!< 0x00080000 */

#define FSMC_BWTRx_ACCMOD_Pos               (28U)                              
#define FSMC_BWTRx_ACCMOD_Msk               (0x3UL << FSMC_BWTRx_ACCMOD_Pos)    /*!< 0x30000000 */
#define FSMC_BWTRx_ACCMOD                   FSMC_BWTRx_ACCMOD_Msk              /*!< ACCMOD[1:0] bits (Access mode) */
#define FSMC_BWTRx_ACCMOD_0                 (0x1UL << FSMC_BWTRx_ACCMOD_Pos)    /*!< 0x10000000 */
#define FSMC_BWTRx_ACCMOD_1                 (0x2UL << FSMC_BWTRx_ACCMOD_Pos)    /*!< 0x20000000 */

/******************  Bit definition for FSMC_PCRx (x = 2 to 4) register  *******************/
#define FSMC_PCRx_PWAITEN_Pos               (1U)                               
#define FSMC_PCRx_PWAITEN_Msk               (0x1UL << FSMC_PCRx_PWAITEN_Pos)    /*!< 0x00000002 */
#define FSMC_PCRx_PWAITEN                   FSMC_PCRx_PWAITEN_Msk              /*!< Wait feature enable bit */
#define FSMC_PCRx_PBKEN_Pos                 (2U)                               
#define FSMC_PCRx_PBKEN_Msk                 (0x1UL << FSMC_PCRx_PBKEN_Pos)      /*!< 0x00000004 */
#define FSMC_PCRx_PBKEN                     FSMC_PCRx_PBKEN_Msk                /*!< PC Card/NAND Flash memory bank enable bit */
#define FSMC_PCRx_PTYP_Pos                  (3U)                               
#define FSMC_PCRx_PTYP_Msk                  (0x1UL << FSMC_PCRx_PTYP_Pos)       /*!< 0x00000008 */
#define FSMC_PCRx_PTYP                      FSMC_PCRx_PTYP_Msk                 /*!< Memory type */

#define FSMC_PCRx_PWID_Pos                  (4U)                               
#define FSMC_PCRx_PWID_Msk                  (0x3UL << FSMC_PCRx_PWID_Pos)       /*!< 0x00000030 */
#define FSMC_PCRx_PWID                      FSMC_PCRx_PWID_Msk                 /*!< PWID[1:0] bits (NAND Flash databus width) */
#define FSMC_PCRx_PWID_0                    (0x1UL << FSMC_PCRx_PWID_Pos)       /*!< 0x00000010 */
#define FSMC_PCRx_PWID_1                    (0x2UL << FSMC_PCRx_PWID_Pos)       /*!< 0x00000020 */

#define FSMC_PCRx_ECCEN_Pos                 (6U)                               
#define FSMC_PCRx_ECCEN_Msk                 (0x1UL << FSMC_PCRx_ECCEN_Pos)      /*!< 0x00000040 */
#define FSMC_PCRx_ECCEN                     FSMC_PCRx_ECCEN_Msk                /*!< ECC computation logic enable bit */

#define FSMC_PCRx_TCLR_Pos                  (9U)                               
#define FSMC_PCRx_TCLR_Msk                  (0xFUL << FSMC_PCRx_TCLR_Pos)       /*!< 0x00001E00 */
#define FSMC_PCRx_TCLR                      FSMC_PCRx_TCLR_Msk                 /*!< TCLR[3:0] bits (CLE to RE delay) */
#define FSMC_PCRx_TCLR_0                    (0x1UL << FSMC_PCRx_TCLR_Pos)       /*!< 0x00000200 */
#define FSMC_PCRx_TCLR_1                    (0x2UL << FSMC_PCRx_TCLR_Pos)       /*!< 0x00000400 */
#define FSMC_PCRx_TCLR_2                    (0x4UL << FSMC_PCRx_TCLR_Pos)       /*!< 0x00000800 */
#define FSMC_PCRx_TCLR_3                    (0x8UL << FSMC_PCRx_TCLR_Pos)       /*!< 0x00001000 */

#define FSMC_PCRx_TAR_Pos                   (13U)                              
#define FSMC_PCRx_TAR_Msk                   (0xFUL << FSMC_PCRx_TAR_Pos)        /*!< 0x0001E000 */
#define FSMC_PCRx_TAR                       FSMC_PCRx_TAR_Msk                  /*!< TAR[3:0] bits (ALE to RE delay) */
#define FSMC_PCRx_TAR_0                     (0x1UL << FSMC_PCRx_TAR_Pos)        /*!< 0x00002000 */
#define FSMC_PCRx_TAR_1                     (0x2UL << FSMC_PCRx_TAR_Pos)        /*!< 0x00004000 */
#define FSMC_PCRx_TAR_2                     (0x4UL << FSMC_PCRx_TAR_Pos)        /*!< 0x00008000 */
#define FSMC_PCRx_TAR_3                     (0x8UL << FSMC_PCRx_TAR_Pos)        /*!< 0x00010000 */

#define FSMC_PCRx_ECCPS_Pos                 (17U)                              
#define FSMC_PCRx_ECCPS_Msk                 (0x7UL << FSMC_PCRx_ECCPS_Pos)      /*!< 0x000E0000 */
#define FSMC_PCRx_ECCPS                     FSMC_PCRx_ECCPS_Msk                /*!< ECCPS[1:0] bits (ECC page size) */
#define FSMC_PCRx_ECCPS_0                   (0x1UL << FSMC_PCRx_ECCPS_Pos)      /*!< 0x00020000 */
#define FSMC_PCRx_ECCPS_1                   (0x2UL << FSMC_PCRx_ECCPS_Pos)      /*!< 0x00040000 */
#define FSMC_PCRx_ECCPS_2                   (0x4UL << FSMC_PCRx_ECCPS_Pos)      /*!< 0x00080000 */

/*******************  Bit definition for FSMC_SRx (x = 2 to 4) register  *******************/
#define FSMC_SRx_IRS_Pos                    (0U)                               
#define FSMC_SRx_IRS_Msk                    (0x1UL << FSMC_SRx_IRS_Pos)         /*!< 0x00000001 */
#define FSMC_SRx_IRS                        FSMC_SRx_IRS_Msk                   /*!< Interrupt Rising Edge status */
#define FSMC_SRx_ILS_Pos                    (1U)                               
#define FSMC_SRx_ILS_Msk                    (0x1UL << FSMC_SRx_ILS_Pos)         /*!< 0x00000002 */
#define FSMC_SRx_ILS                        FSMC_SRx_ILS_Msk                   /*!< Interrupt Level status */
#define FSMC_SRx_IFS_Pos                    (2U)                               
#define FSMC_SRx_IFS_Msk                    (0x1UL << FSMC_SRx_IFS_Pos)         /*!< 0x00000004 */
#define FSMC_SRx_IFS                        FSMC_SRx_IFS_Msk                   /*!< Interrupt Falling Edge status */
#define FSMC_SRx_IREN_Pos                   (3U)                               
#define FSMC_SRx_IREN_Msk                   (0x1UL << FSMC_SRx_IREN_Pos)        /*!< 0x00000008 */
#define FSMC_SRx_IREN                       FSMC_SRx_IREN_Msk                  /*!< Interrupt Rising Edge detection Enable bit */
#define FSMC_SRx_ILEN_Pos                   (4U)                               
#define FSMC_SRx_ILEN_Msk                   (0x1UL << FSMC_SRx_ILEN_Pos)        /*!< 0x00000010 */
#define FSMC_SRx_ILEN                       FSMC_SRx_ILEN_Msk                  /*!< Interrupt Level detection Enable bit */
#define FSMC_SRx_IFEN_Pos                   (5U)                               
#define FSMC_SRx_IFEN_Msk                   (0x1UL << FSMC_SRx_IFEN_Pos)        /*!< 0x00000020 */
#define FSMC_SRx_IFEN                       FSMC_SRx_IFEN_Msk                  /*!< Interrupt Falling Edge detection Enable bit */
#define FSMC_SRx_FEMPT_Pos                  (6U)                               
#define FSMC_SRx_FEMPT_Msk                  (0x1UL << FSMC_SRx_FEMPT_Pos)       /*!< 0x00000040 */
#define FSMC_SRx_FEMPT                      FSMC_SRx_FEMPT_Msk                 /*!< FIFO empty */

/******************  Bit definition for FSMC_PMEMx (x = 2 to 4) register  ******************/
#define FSMC_PMEMx_MEMSETx_Pos              (0U)                               
#define FSMC_PMEMx_MEMSETx_Msk              (0xFFUL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x000000FF */
#define FSMC_PMEMx_MEMSETx                  FSMC_PMEMx_MEMSETx_Msk             /*!< MEMSETx[7:0] bits (Common memory x setup time) */
#define FSMC_PMEMx_MEMSETx_0                (0x01UL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x00000001 */
#define FSMC_PMEMx_MEMSETx_1                (0x02UL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x00000002 */
#define FSMC_PMEMx_MEMSETx_2                (0x04UL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x00000004 */
#define FSMC_PMEMx_MEMSETx_3                (0x08UL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x00000008 */
#define FSMC_PMEMx_MEMSETx_4                (0x10UL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x00000010 */
#define FSMC_PMEMx_MEMSETx_5                (0x20UL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x00000020 */
#define FSMC_PMEMx_MEMSETx_6                (0x40UL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x00000040 */
#define FSMC_PMEMx_MEMSETx_7                (0x80UL << FSMC_PMEMx_MEMSETx_Pos)  /*!< 0x00000080 */

#define FSMC_PMEMx_MEMWAITx_Pos             (8U)                               
#define FSMC_PMEMx_MEMWAITx_Msk             (0xFFUL << FSMC_PMEMx_MEMWAITx_Pos) /*!< 0x0000FF00 */
#define FSMC_PMEMx_MEMWAITx                 FSMC_PMEMx_MEMWAITx_Msk            /*!< MEMWAITx[7:0] bits (Common memory x wait time) */
#define FSMC_PMEMx_MEMWAIT2_0               0x00000100U                        /*!< Bit 0 */
#define FSMC_PMEMx_MEMWAITx_1               0x00000200U                        /*!< Bit 1 */
#define FSMC_PMEMx_MEMWAITx_2               0x00000400U                        /*!< Bit 2 */
#define FSMC_PMEMx_MEMWAITx_3               0x00000800U                        /*!< Bit 3 */
#define FSMC_PMEMx_MEMWAITx_4               0x00001000U                        /*!< Bit 4 */
#define FSMC_PMEMx_MEMWAITx_5               0x00002000U                        /*!< Bit 5 */
#define FSMC_PMEMx_MEMWAITx_6               0x00004000U                        /*!< Bit 6 */
#define FSMC_PMEMx_MEMWAITx_7               0x00008000U                        /*!< Bit 7 */

#define FSMC_PMEMx_MEMHOLDx_Pos             (16U)                              
#define FSMC_PMEMx_MEMHOLDx_Msk             (0xFFUL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00FF0000 */
#define FSMC_PMEMx_MEMHOLDx                 FSMC_PMEMx_MEMHOLDx_Msk            /*!< MEMHOLDx[7:0] bits (Common memory x hold time) */
#define FSMC_PMEMx_MEMHOLDx_0               (0x01UL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00010000 */
#define FSMC_PMEMx_MEMHOLDx_1               (0x02UL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00020000 */
#define FSMC_PMEMx_MEMHOLDx_2               (0x04UL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00040000 */
#define FSMC_PMEMx_MEMHOLDx_3               (0x08UL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00080000 */
#define FSMC_PMEMx_MEMHOLDx_4               (0x10UL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00100000 */
#define FSMC_PMEMx_MEMHOLDx_5               (0x20UL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00200000 */
#define FSMC_PMEMx_MEMHOLDx_6               (0x40UL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00400000 */
#define FSMC_PMEMx_MEMHOLDx_7               (0x80UL << FSMC_PMEMx_MEMHOLDx_Pos) /*!< 0x00800000 */

#define FSMC_PMEMx_MEMHIZx_Pos              (24U)                              
#define FSMC_PMEMx_MEMHIZx_Msk              (0xFFUL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0xFF000000 */
#define FSMC_PMEMx_MEMHIZx                  FSMC_PMEMx_MEMHIZx_Msk             /*!< MEMHIZx[7:0] bits (Common memory x databus HiZ time) */
#define FSMC_PMEMx_MEMHIZx_0                (0x01UL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0x01000000 */
#define FSMC_PMEMx_MEMHIZx_1                (0x02UL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0x02000000 */
#define FSMC_PMEMx_MEMHIZx_2                (0x04UL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0x04000000 */
#define FSMC_PMEMx_MEMHIZx_3                (0x08UL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0x08000000 */
#define FSMC_PMEMx_MEMHIZx_4                (0x10UL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0x10000000 */
#define FSMC_PMEMx_MEMHIZx_5                (0x20UL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0x20000000 */
#define FSMC_PMEMx_MEMHIZx_6                (0x40UL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0x40000000 */
#define FSMC_PMEMx_MEMHIZx_7                (0x80UL << FSMC_PMEMx_MEMHIZx_Pos)  /*!< 0x80000000 */

/******************  Bit definition for FSMC_PATTx (x = 2 to 4) register  ******************/
#define FSMC_PATTx_ATTSETx_Pos              (0U)                               
#define FSMC_PATTx_ATTSETx_Msk              (0xFFUL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x000000FF */
#define FSMC_PATTx_ATTSETx                  FSMC_PATTx_ATTSETx_Msk             /*!< ATTSETx[7:0] bits (Attribute memory x setup time) */
#define FSMC_PATTx_ATTSETx_0                (0x01UL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x00000001 */
#define FSMC_PATTx_ATTSETx_1                (0x02UL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x00000002 */
#define FSMC_PATTx_ATTSETx_2                (0x04UL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x00000004 */
#define FSMC_PATTx_ATTSETx_3                (0x08UL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x00000008 */
#define FSMC_PATTx_ATTSETx_4                (0x10UL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x00000010 */
#define FSMC_PATTx_ATTSETx_5                (0x20UL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x00000020 */
#define FSMC_PATTx_ATTSETx_6                (0x40UL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x00000040 */
#define FSMC_PATTx_ATTSETx_7                (0x80UL << FSMC_PATTx_ATTSETx_Pos)  /*!< 0x00000080 */

#define FSMC_PATTx_ATTWAITx_Pos             (8U)                               
#define FSMC_PATTx_ATTWAITx_Msk             (0xFFUL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x0000FF00 */
#define FSMC_PATTx_ATTWAITx                 FSMC_PATTx_ATTWAITx_Msk            /*!< ATTWAITx[7:0] bits (Attribute memory x wait time) */
#define FSMC_PATTx_ATTWAITx_0               (0x01UL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x00000100 */
#define FSMC_PATTx_ATTWAITx_1               (0x02UL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x00000200 */
#define FSMC_PATTx_ATTWAITx_2               (0x04UL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x00000400 */
#define FSMC_PATTx_ATTWAITx_3               (0x08UL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x00000800 */
#define FSMC_PATTx_ATTWAITx_4               (0x10UL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x00001000 */
#define FSMC_PATTx_ATTWAITx_5               (0x20UL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x00002000 */
#define FSMC_PATTx_ATTWAITx_6               (0x40UL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x00004000 */
#define FSMC_PATTx_ATTWAITx_7               (0x80UL << FSMC_PATTx_ATTWAITx_Pos) /*!< 0x00008000 */

#define FSMC_PATTx_ATTHOLDx_Pos             (16U)                              
#define FSMC_PATTx_ATTHOLDx_Msk             (0xFFUL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00FF0000 */
#define FSMC_PATTx_ATTHOLDx                 FSMC_PATTx_ATTHOLDx_Msk            /*!< ATTHOLDx[7:0] bits (Attribute memory x hold time) */
#define FSMC_PATTx_ATTHOLDx_0               (0x01UL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00010000 */
#define FSMC_PATTx_ATTHOLDx_1               (0x02UL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00020000 */
#define FSMC_PATTx_ATTHOLDx_2               (0x04UL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00040000 */
#define FSMC_PATTx_ATTHOLDx_3               (0x08UL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00080000 */
#define FSMC_PATTx_ATTHOLDx_4               (0x10UL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00100000 */
#define FSMC_PATTx_ATTHOLDx_5               (0x20UL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00200000 */
#define FSMC_PATTx_ATTHOLDx_6               (0x40UL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00400000 */
#define FSMC_PATTx_ATTHOLDx_7               (0x80UL << FSMC_PATTx_ATTHOLDx_Pos) /*!< 0x00800000 */

#define FSMC_PATTx_ATTHIZx_Pos              (24U)                              
#define FSMC_PATTx_ATTHIZx_Msk              (0xFFUL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0xFF000000 */
#define FSMC_PATTx_ATTHIZx                  FSMC_PATTx_ATTHIZx_Msk             /*!< ATTHIZx[7:0] bits (Attribute memory x databus HiZ time) */
#define FSMC_PATTx_ATTHIZx_0                (0x01UL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0x01000000 */
#define FSMC_PATTx_ATTHIZx_1                (0x02UL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0x02000000 */
#define FSMC_PATTx_ATTHIZx_2                (0x04UL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0x04000000 */
#define FSMC_PATTx_ATTHIZx_3                (0x08UL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0x08000000 */
#define FSMC_PATTx_ATTHIZx_4                (0x10UL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0x10000000 */
#define FSMC_PATTx_ATTHIZx_5                (0x20UL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0x20000000 */
#define FSMC_PATTx_ATTHIZx_6                (0x40UL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0x40000000 */
#define FSMC_PATTx_ATTHIZx_7                (0x80UL << FSMC_PATTx_ATTHIZx_Pos)  /*!< 0x80000000 */

/******************  Bit definition for FSMC_PIO4 register  *******************/
#define FSMC_PIO4_IOSET4_Pos                (0U)                               
#define FSMC_PIO4_IOSET4_Msk                (0xFFUL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x000000FF */
#define FSMC_PIO4_IOSET4                    FSMC_PIO4_IOSET4_Msk               /*!< IOSET4[7:0] bits (I/O 4 setup time) */
#define FSMC_PIO4_IOSET4_0                  (0x01UL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x00000001 */
#define FSMC_PIO4_IOSET4_1                  (0x02UL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x00000002 */
#define FSMC_PIO4_IOSET4_2                  (0x04UL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x00000004 */
#define FSMC_PIO4_IOSET4_3                  (0x08UL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x00000008 */
#define FSMC_PIO4_IOSET4_4                  (0x10UL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x00000010 */
#define FSMC_PIO4_IOSET4_5                  (0x20UL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x00000020 */
#define FSMC_PIO4_IOSET4_6                  (0x40UL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x00000040 */
#define FSMC_PIO4_IOSET4_7                  (0x80UL << FSMC_PIO4_IOSET4_Pos)    /*!< 0x00000080 */

#define FSMC_PIO4_IOWAIT4_Pos               (8U)                               
#define FSMC_PIO4_IOWAIT4_Msk               (0xFFUL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x0000FF00 */
#define FSMC_PIO4_IOWAIT4                   FSMC_PIO4_IOWAIT4_Msk              /*!< IOWAIT4[7:0] bits (I/O 4 wait time) */
#define FSMC_PIO4_IOWAIT4_0                 (0x01UL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x00000100 */
#define FSMC_PIO4_IOWAIT4_1                 (0x02UL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x00000200 */
#define FSMC_PIO4_IOWAIT4_2                 (0x04UL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x00000400 */
#define FSMC_PIO4_IOWAIT4_3                 (0x08UL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x00000800 */
#define FSMC_PIO4_IOWAIT4_4                 (0x10UL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x00001000 */
#define FSMC_PIO4_IOWAIT4_5                 (0x20UL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x00002000 */
#define FSMC_PIO4_IOWAIT4_6                 (0x40UL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x00004000 */
#define FSMC_PIO4_IOWAIT4_7                 (0x80UL << FSMC_PIO4_IOWAIT4_Pos)   /*!< 0x00008000 */

#define FSMC_PIO4_IOHOLD4_Pos               (16U)                              
#define FSMC_PIO4_IOHOLD4_Msk               (0xFFUL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00FF0000 */
#define FSMC_PIO4_IOHOLD4                   FSMC_PIO4_IOHOLD4_Msk              /*!< IOHOLD4[7:0] bits (I/O 4 hold time) */
#define FSMC_PIO4_IOHOLD4_0                 (0x01UL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00010000 */
#define FSMC_PIO4_IOHOLD4_1                 (0x02UL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00020000 */
#define FSMC_PIO4_IOHOLD4_2                 (0x04UL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00040000 */
#define FSMC_PIO4_IOHOLD4_3                 (0x08UL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00080000 */
#define FSMC_PIO4_IOHOLD4_4                 (0x10UL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00100000 */
#define FSMC_PIO4_IOHOLD4_5                 (0x20UL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00200000 */
#define FSMC_PIO4_IOHOLD4_6                 (0x40UL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00400000 */
#define FSMC_PIO4_IOHOLD4_7                 (0x80UL << FSMC_PIO4_IOHOLD4_Pos)   /*!< 0x00800000 */

#define FSMC_PIO4_IOHIZ4_Pos                (24U)                              
#define FSMC_PIO4_IOHIZ4_Msk                (0xFFUL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0xFF000000 */
#define FSMC_PIO4_IOHIZ4                    FSMC_PIO4_IOHIZ4_Msk               /*!< IOHIZ4[7:0] bits (I/O 4 databus HiZ time) */
#define FSMC_PIO4_IOHIZ4_0                  (0x01UL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0x01000000 */
#define FSMC_PIO4_IOHIZ4_1                  (0x02UL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0x02000000 */
#define FSMC_PIO4_IOHIZ4_2                  (0x04UL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0x04000000 */
#define FSMC_PIO4_IOHIZ4_3                  (0x08UL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0x08000000 */
#define FSMC_PIO4_IOHIZ4_4                  (0x10UL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0x10000000 */
#define FSMC_PIO4_IOHIZ4_5                  (0x20UL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0x20000000 */
#define FSMC_PIO4_IOHIZ4_6                  (0x40UL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0x40000000 */
#define FSMC_PIO4_IOHIZ4_7                  (0x80UL << FSMC_PIO4_IOHIZ4_Pos)    /*!< 0x80000000 */

/******************  Bit definition for FSMC_ECCR2 register  ******************/
#define FSMC_ECCR2_ECC2_Pos                 (0U)                               
#define FSMC_ECCR2_ECC2_Msk                 (0xFFFFFFFFUL << FSMC_ECCR2_ECC2_Pos) /*!< 0xFFFFFFFF */
#define FSMC_ECCR2_ECC2                     FSMC_ECCR2_ECC2_Msk                /*!< ECC result */

/******************  Bit definition for FSMC_ECCR3 register  ******************/
#define FSMC_ECCR3_ECC3_Pos                 (0U)                               
#define FSMC_ECCR3_ECC3_Msk                 (0xFFFFFFFFUL << FSMC_ECCR3_ECC3_Pos) /*!< 0xFFFFFFFF */
#define FSMC_ECCR3_ECC3                     FSMC_ECCR3_ECC3_Msk                /*!< ECC result */


/******************************************************************************/
/*                                                                            */
/*                                   USB Device FS                            */
/*                                                                            */
/******************************************************************************/

/*!< Endpoint-specific registers */
#define  USB_EP0R                            USB_BASE                      /*!< Endpoint 0 register address */
#define  USB_EP1R                            (USB_BASE + 0x00000004)       /*!< Endpoint 1 register address */
#define  USB_EP2R                            (USB_BASE + 0x00000008)       /*!< Endpoint 2 register address */
#define  USB_EP3R                            (USB_BASE + 0x0000000C)       /*!< Endpoint 3 register address */
#define  USB_EP4R                            (USB_BASE + 0x00000010)       /*!< Endpoint 4 register address */
#define  USB_EP5R                            (USB_BASE + 0x00000014)       /*!< Endpoint 5 register address */
#define  USB_EP6R                            (USB_BASE + 0x00000018)       /*!< Endpoint 6 register address */
#define  USB_EP7R                            (USB_BASE + 0x0000001C)       /*!< Endpoint 7 register address */

/* bit positions */ 
#define USB_EP_CTR_RX_Pos                       (15U)                          
#define USB_EP_CTR_RX_Msk                       (0x1UL << USB_EP_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP_CTR_RX                           USB_EP_CTR_RX_Msk              /*!< EndPoint Correct TRansfer RX */
#define USB_EP_DTOG_RX_Pos                      (14U)                          
#define USB_EP_DTOG_RX_Msk                      (0x1UL << USB_EP_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP_DTOG_RX                          USB_EP_DTOG_RX_Msk             /*!< EndPoint Data TOGGLE RX */
#define USB_EPRX_STAT_Pos                       (12U)                          
#define USB_EPRX_STAT_Msk                       (0x3UL << USB_EPRX_STAT_Pos)    /*!< 0x00003000 */
#define USB_EPRX_STAT                           USB_EPRX_STAT_Msk              /*!< EndPoint RX STATus bit field */
#define USB_EP_SETUP_Pos                        (11U)                          
#define USB_EP_SETUP_Msk                        (0x1UL << USB_EP_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP_SETUP                            USB_EP_SETUP_Msk               /*!< EndPoint SETUP */
#define USB_EP_T_FIELD_Pos                      (9U)                           
#define USB_EP_T_FIELD_Msk                      (0x3UL << USB_EP_T_FIELD_Pos)   /*!< 0x00000600 */
#define USB_EP_T_FIELD                          USB_EP_T_FIELD_Msk             /*!< EndPoint TYPE */
#define USB_EP_KIND_Pos                         (8U)                           
#define USB_EP_KIND_Msk                         (0x1UL << USB_EP_KIND_Pos)      /*!< 0x00000100 */
#define USB_EP_KIND                             USB_EP_KIND_Msk                /*!< EndPoint KIND */
#define USB_EP_CTR_TX_Pos                       (7U)                           
#define USB_EP_CTR_TX_Msk                       (0x1UL << USB_EP_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP_CTR_TX                           USB_EP_CTR_TX_Msk              /*!< EndPoint Correct TRansfer TX */
#define USB_EP_DTOG_TX_Pos                      (6U)                           
#define USB_EP_DTOG_TX_Msk                      (0x1UL << USB_EP_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP_DTOG_TX                          USB_EP_DTOG_TX_Msk             /*!< EndPoint Data TOGGLE TX */
#define USB_EPTX_STAT_Pos                       (4U)                           
#define USB_EPTX_STAT_Msk                       (0x3UL << USB_EPTX_STAT_Pos)    /*!< 0x00000030 */
#define USB_EPTX_STAT                           USB_EPTX_STAT_Msk              /*!< EndPoint TX STATus bit field */
#define USB_EPADDR_FIELD_Pos                    (0U)                           
#define USB_EPADDR_FIELD_Msk                    (0xFUL << USB_EPADDR_FIELD_Pos) /*!< 0x0000000F */
#define USB_EPADDR_FIELD                        USB_EPADDR_FIELD_Msk           /*!< EndPoint ADDRess FIELD */

/* EndPoint REGister MASK (no toggle fields) */
#define  USB_EPREG_MASK                      (USB_EP_CTR_RX|USB_EP_SETUP|USB_EP_T_FIELD|USB_EP_KIND|USB_EP_CTR_TX|USB_EPADDR_FIELD)
                                                                           /*!< EP_TYPE[1:0] EndPoint TYPE */
#define USB_EP_TYPE_MASK_Pos                    (9U)                           
#define USB_EP_TYPE_MASK_Msk                    (0x3UL << USB_EP_TYPE_MASK_Pos) /*!< 0x00000600 */
#define USB_EP_TYPE_MASK                        USB_EP_TYPE_MASK_Msk           /*!< EndPoint TYPE Mask */
#define USB_EP_BULK                             0x00000000U                    /*!< EndPoint BULK */
#define USB_EP_CONTROL                          0x00000200U                    /*!< EndPoint CONTROL */
#define USB_EP_ISOCHRONOUS                      0x00000400U                    /*!< EndPoint ISOCHRONOUS */
#define USB_EP_INTERRUPT                        0x00000600U                    /*!< EndPoint INTERRUPT */
#define  USB_EP_T_MASK                          (~USB_EP_T_FIELD & USB_EPREG_MASK)

#define  USB_EPKIND_MASK                        (~USB_EP_KIND & USB_EPREG_MASK)  /*!< EP_KIND EndPoint KIND */
                                                                               /*!< STAT_TX[1:0] STATus for TX transfer */
#define USB_EP_TX_DIS                           0x00000000U                    /*!< EndPoint TX DISabled */
#define USB_EP_TX_STALL                         0x00000010U                    /*!< EndPoint TX STALLed */
#define USB_EP_TX_NAK                           0x00000020U                    /*!< EndPoint TX NAKed */
#define USB_EP_TX_VALID                         0x00000030U                    /*!< EndPoint TX VALID */
#define USB_EPTX_DTOG1                          0x00000010U                    /*!< EndPoint TX Data TOGgle bit1 */
#define USB_EPTX_DTOG2                          0x00000020U                    /*!< EndPoint TX Data TOGgle bit2 */
#define  USB_EPTX_DTOGMASK  (USB_EPTX_STAT|USB_EPREG_MASK)
                                                                               /*!< STAT_RX[1:0] STATus for RX transfer */
#define USB_EP_RX_DIS                           0x00000000U                    /*!< EndPoint RX DISabled */
#define USB_EP_RX_STALL                         0x00001000U                    /*!< EndPoint RX STALLed */
#define USB_EP_RX_NAK                           0x00002000U                    /*!< EndPoint RX NAKed */
#define USB_EP_RX_VALID                         0x00003000U                    /*!< EndPoint RX VALID */
#define USB_EPRX_DTOG1                          0x00001000U                    /*!< EndPoint RX Data TOGgle bit1 */
#define USB_EPRX_DTOG2                          0x00002000U                    /*!< EndPoint RX Data TOGgle bit1 */
#define  USB_EPRX_DTOGMASK  (USB_EPRX_STAT|USB_EPREG_MASK)

/*******************  Bit definition for USB_EP0R register  *******************/
#define USB_EP0R_EA_Pos                         (0U)                           
#define USB_EP0R_EA_Msk                         (0xFUL << USB_EP0R_EA_Pos)      /*!< 0x0000000F */
#define USB_EP0R_EA                             USB_EP0R_EA_Msk                /*!< Endpoint Address */

#define USB_EP0R_STAT_TX_Pos                    (4U)                           
#define USB_EP0R_STAT_TX_Msk                    (0x3UL << USB_EP0R_STAT_TX_Pos) /*!< 0x00000030 */
#define USB_EP0R_STAT_TX                        USB_EP0R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP0R_STAT_TX_0                      (0x1UL << USB_EP0R_STAT_TX_Pos) /*!< 0x00000010 */
#define USB_EP0R_STAT_TX_1                      (0x2UL << USB_EP0R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP0R_DTOG_TX_Pos                    (6U)                           
#define USB_EP0R_DTOG_TX_Msk                    (0x1UL << USB_EP0R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP0R_DTOG_TX                        USB_EP0R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP0R_CTR_TX_Pos                     (7U)                           
#define USB_EP0R_CTR_TX_Msk                     (0x1UL << USB_EP0R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP0R_CTR_TX                         USB_EP0R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP0R_EP_KIND_Pos                    (8U)                           
#define USB_EP0R_EP_KIND_Msk                    (0x1UL << USB_EP0R_EP_KIND_Pos) /*!< 0x00000100 */
#define USB_EP0R_EP_KIND                        USB_EP0R_EP_KIND_Msk           /*!< Endpoint Kind */
                                                                           
#define USB_EP0R_EP_TYPE_Pos                    (9U)                           
#define USB_EP0R_EP_TYPE_Msk                    (0x3UL << USB_EP0R_EP_TYPE_Pos) /*!< 0x00000600 */
#define USB_EP0R_EP_TYPE                        USB_EP0R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP0R_EP_TYPE_0                      (0x1UL << USB_EP0R_EP_TYPE_Pos) /*!< 0x00000200 */
#define USB_EP0R_EP_TYPE_1                      (0x2UL << USB_EP0R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP0R_SETUP_Pos                      (11U)                          
#define USB_EP0R_SETUP_Msk                      (0x1UL << USB_EP0R_SETUP_Pos)   /*!< 0x00000800 */
#define USB_EP0R_SETUP                          USB_EP0R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP0R_STAT_RX_Pos                    (12U)                          
#define USB_EP0R_STAT_RX_Msk                    (0x3UL << USB_EP0R_STAT_RX_Pos) /*!< 0x00003000 */
#define USB_EP0R_STAT_RX                        USB_EP0R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP0R_STAT_RX_0                      (0x1UL << USB_EP0R_STAT_RX_Pos) /*!< 0x00001000 */
#define USB_EP0R_STAT_RX_1                      (0x2UL << USB_EP0R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP0R_DTOG_RX_Pos                    (14U)                          
#define USB_EP0R_DTOG_RX_Msk                    (0x1UL << USB_EP0R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP0R_DTOG_RX                        USB_EP0R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP0R_CTR_RX_Pos                     (15U)                          
#define USB_EP0R_CTR_RX_Msk                     (0x1UL << USB_EP0R_CTR_RX_Pos)  /*!< 0x00008000 */
#define USB_EP0R_CTR_RX                         USB_EP0R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP1R register  *******************/
#define USB_EP1R_EA_Pos                         (0U)                           
#define USB_EP1R_EA_Msk                         (0xFUL << USB_EP1R_EA_Pos)      /*!< 0x0000000F */
#define USB_EP1R_EA                             USB_EP1R_EA_Msk                /*!< Endpoint Address */
                                                                          
#define USB_EP1R_STAT_TX_Pos                    (4U)                           
#define USB_EP1R_STAT_TX_Msk                    (0x3UL << USB_EP1R_STAT_TX_Pos) /*!< 0x00000030 */
#define USB_EP1R_STAT_TX                        USB_EP1R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP1R_STAT_TX_0                      (0x1UL << USB_EP1R_STAT_TX_Pos) /*!< 0x00000010 */
#define USB_EP1R_STAT_TX_1                      (0x2UL << USB_EP1R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP1R_DTOG_TX_Pos                    (6U)                           
#define USB_EP1R_DTOG_TX_Msk                    (0x1UL << USB_EP1R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP1R_DTOG_TX                        USB_EP1R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP1R_CTR_TX_Pos                     (7U)                           
#define USB_EP1R_CTR_TX_Msk                     (0x1UL << USB_EP1R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP1R_CTR_TX                         USB_EP1R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP1R_EP_KIND_Pos                    (8U)                           
#define USB_EP1R_EP_KIND_Msk                    (0x1UL << USB_EP1R_EP_KIND_Pos) /*!< 0x00000100 */
#define USB_EP1R_EP_KIND                        USB_EP1R_EP_KIND_Msk           /*!< Endpoint Kind */

#define USB_EP1R_EP_TYPE_Pos                    (9U)                           
#define USB_EP1R_EP_TYPE_Msk                    (0x3UL << USB_EP1R_EP_TYPE_Pos) /*!< 0x00000600 */
#define USB_EP1R_EP_TYPE                        USB_EP1R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP1R_EP_TYPE_0                      (0x1UL << USB_EP1R_EP_TYPE_Pos) /*!< 0x00000200 */
#define USB_EP1R_EP_TYPE_1                      (0x2UL << USB_EP1R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP1R_SETUP_Pos                      (11U)                          
#define USB_EP1R_SETUP_Msk                      (0x1UL << USB_EP1R_SETUP_Pos)   /*!< 0x00000800 */
#define USB_EP1R_SETUP                          USB_EP1R_SETUP_Msk             /*!< Setup transaction completed */
                                                                           
#define USB_EP1R_STAT_RX_Pos                    (12U)                          
#define USB_EP1R_STAT_RX_Msk                    (0x3UL << USB_EP1R_STAT_RX_Pos) /*!< 0x00003000 */
#define USB_EP1R_STAT_RX                        USB_EP1R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP1R_STAT_RX_0                      (0x1UL << USB_EP1R_STAT_RX_Pos) /*!< 0x00001000 */
#define USB_EP1R_STAT_RX_1                      (0x2UL << USB_EP1R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP1R_DTOG_RX_Pos                    (14U)                          
#define USB_EP1R_DTOG_RX_Msk                    (0x1UL << USB_EP1R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP1R_DTOG_RX                        USB_EP1R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP1R_CTR_RX_Pos                     (15U)                          
#define USB_EP1R_CTR_RX_Msk                     (0x1UL << USB_EP1R_CTR_RX_Pos)  /*!< 0x00008000 */
#define USB_EP1R_CTR_RX                         USB_EP1R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP2R register  *******************/
#define USB_EP2R_EA_Pos                         (0U)                           
#define USB_EP2R_EA_Msk                         (0xFUL << USB_EP2R_EA_Pos)      /*!< 0x0000000F */
#define USB_EP2R_EA                             USB_EP2R_EA_Msk                /*!< Endpoint Address */

#define USB_EP2R_STAT_TX_Pos                    (4U)                           
#define USB_EP2R_STAT_TX_Msk                    (0x3UL << USB_EP2R_STAT_TX_Pos) /*!< 0x00000030 */
#define USB_EP2R_STAT_TX                        USB_EP2R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP2R_STAT_TX_0                      (0x1UL << USB_EP2R_STAT_TX_Pos) /*!< 0x00000010 */
#define USB_EP2R_STAT_TX_1                      (0x2UL << USB_EP2R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP2R_DTOG_TX_Pos                    (6U)                           
#define USB_EP2R_DTOG_TX_Msk                    (0x1UL << USB_EP2R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP2R_DTOG_TX                        USB_EP2R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP2R_CTR_TX_Pos                     (7U)                           
#define USB_EP2R_CTR_TX_Msk                     (0x1UL << USB_EP2R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP2R_CTR_TX                         USB_EP2R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP2R_EP_KIND_Pos                    (8U)                           
#define USB_EP2R_EP_KIND_Msk                    (0x1UL << USB_EP2R_EP_KIND_Pos) /*!< 0x00000100 */
#define USB_EP2R_EP_KIND                        USB_EP2R_EP_KIND_Msk           /*!< Endpoint Kind */

#define USB_EP2R_EP_TYPE_Pos                    (9U)                           
#define USB_EP2R_EP_TYPE_Msk                    (0x3UL << USB_EP2R_EP_TYPE_Pos) /*!< 0x00000600 */
#define USB_EP2R_EP_TYPE                        USB_EP2R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP2R_EP_TYPE_0                      (0x1UL << USB_EP2R_EP_TYPE_Pos) /*!< 0x00000200 */
#define USB_EP2R_EP_TYPE_1                      (0x2UL << USB_EP2R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP2R_SETUP_Pos                      (11U)                          
#define USB_EP2R_SETUP_Msk                      (0x1UL << USB_EP2R_SETUP_Pos)   /*!< 0x00000800 */
#define USB_EP2R_SETUP                          USB_EP2R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP2R_STAT_RX_Pos                    (12U)                          
#define USB_EP2R_STAT_RX_Msk                    (0x3UL << USB_EP2R_STAT_RX_Pos) /*!< 0x00003000 */
#define USB_EP2R_STAT_RX                        USB_EP2R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP2R_STAT_RX_0                      (0x1UL << USB_EP2R_STAT_RX_Pos) /*!< 0x00001000 */
#define USB_EP2R_STAT_RX_1                      (0x2UL << USB_EP2R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP2R_DTOG_RX_Pos                    (14U)                          
#define USB_EP2R_DTOG_RX_Msk                    (0x1UL << USB_EP2R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP2R_DTOG_RX                        USB_EP2R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP2R_CTR_RX_Pos                     (15U)                          
#define USB_EP2R_CTR_RX_Msk                     (0x1UL << USB_EP2R_CTR_RX_Pos)  /*!< 0x00008000 */
#define USB_EP2R_CTR_RX                         USB_EP2R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP3R register  *******************/
#define USB_EP3R_EA_Pos                         (0U)                           
#define USB_EP3R_EA_Msk                         (0xFUL << USB_EP3R_EA_Pos)      /*!< 0x0000000F */
#define USB_EP3R_EA                             USB_EP3R_EA_Msk                /*!< Endpoint Address */

#define USB_EP3R_STAT_TX_Pos                    (4U)                           
#define USB_EP3R_STAT_TX_Msk                    (0x3UL << USB_EP3R_STAT_TX_Pos) /*!< 0x00000030 */
#define USB_EP3R_STAT_TX                        USB_EP3R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP3R_STAT_TX_0                      (0x1UL << USB_EP3R_STAT_TX_Pos) /*!< 0x00000010 */
#define USB_EP3R_STAT_TX_1                      (0x2UL << USB_EP3R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP3R_DTOG_TX_Pos                    (6U)                           
#define USB_EP3R_DTOG_TX_Msk                    (0x1UL << USB_EP3R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP3R_DTOG_TX                        USB_EP3R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP3R_CTR_TX_Pos                     (7U)                           
#define USB_EP3R_CTR_TX_Msk                     (0x1UL << USB_EP3R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP3R_CTR_TX                         USB_EP3R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP3R_EP_KIND_Pos                    (8U)                           
#define USB_EP3R_EP_KIND_Msk                    (0x1UL << USB_EP3R_EP_KIND_Pos) /*!< 0x00000100 */
#define USB_EP3R_EP_KIND                        USB_EP3R_EP_KIND_Msk           /*!< Endpoint Kind */

#define USB_EP3R_EP_TYPE_Pos                    (9U)                           
#define USB_EP3R_EP_TYPE_Msk                    (0x3UL << USB_EP3R_EP_TYPE_Pos) /*!< 0x00000600 */
#define USB_EP3R_EP_TYPE                        USB_EP3R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP3R_EP_TYPE_0                      (0x1UL << USB_EP3R_EP_TYPE_Pos) /*!< 0x00000200 */
#define USB_EP3R_EP_TYPE_1                      (0x2UL << USB_EP3R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP3R_SETUP_Pos                      (11U)                          
#define USB_EP3R_SETUP_Msk                      (0x1UL << USB_EP3R_SETUP_Pos)   /*!< 0x00000800 */
#define USB_EP3R_SETUP                          USB_EP3R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP3R_STAT_RX_Pos                    (12U)                          
#define USB_EP3R_STAT_RX_Msk                    (0x3UL << USB_EP3R_STAT_RX_Pos) /*!< 0x00003000 */
#define USB_EP3R_STAT_RX                        USB_EP3R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP3R_STAT_RX_0                      (0x1UL << USB_EP3R_STAT_RX_Pos) /*!< 0x00001000 */
#define USB_EP3R_STAT_RX_1                      (0x2UL << USB_EP3R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP3R_DTOG_RX_Pos                    (14U)                          
#define USB_EP3R_DTOG_RX_Msk                    (0x1UL << USB_EP3R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP3R_DTOG_RX                        USB_EP3R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP3R_CTR_RX_Pos                     (15U)                          
#define USB_EP3R_CTR_RX_Msk                     (0x1UL << USB_EP3R_CTR_RX_Pos)  /*!< 0x00008000 */
#define USB_EP3R_CTR_RX                         USB_EP3R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP4R register  *******************/
#define USB_EP4R_EA_Pos                         (0U)                           
#define USB_EP4R_EA_Msk                         (0xFUL << USB_EP4R_EA_Pos)      /*!< 0x0000000F */
#define USB_EP4R_EA                             USB_EP4R_EA_Msk                /*!< Endpoint Address */

#define USB_EP4R_STAT_TX_Pos                    (4U)                           
#define USB_EP4R_STAT_TX_Msk                    (0x3UL << USB_EP4R_STAT_TX_Pos) /*!< 0x00000030 */
#define USB_EP4R_STAT_TX                        USB_EP4R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP4R_STAT_TX_0                      (0x1UL << USB_EP4R_STAT_TX_Pos) /*!< 0x00000010 */
#define USB_EP4R_STAT_TX_1                      (0x2UL << USB_EP4R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP4R_DTOG_TX_Pos                    (6U)                           
#define USB_EP4R_DTOG_TX_Msk                    (0x1UL << USB_EP4R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP4R_DTOG_TX                        USB_EP4R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP4R_CTR_TX_Pos                     (7U)                           
#define USB_EP4R_CTR_TX_Msk                     (0x1UL << USB_EP4R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP4R_CTR_TX                         USB_EP4R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP4R_EP_KIND_Pos                    (8U)                           
#define USB_EP4R_EP_KIND_Msk                    (0x1UL << USB_EP4R_EP_KIND_Pos) /*!< 0x00000100 */
#define USB_EP4R_EP_KIND                        USB_EP4R_EP_KIND_Msk           /*!< Endpoint Kind */

#define USB_EP4R_EP_TYPE_Pos                    (9U)                           
#define USB_EP4R_EP_TYPE_Msk                    (0x3UL << USB_EP4R_EP_TYPE_Pos) /*!< 0x00000600 */
#define USB_EP4R_EP_TYPE                        USB_EP4R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP4R_EP_TYPE_0                      (0x1UL << USB_EP4R_EP_TYPE_Pos) /*!< 0x00000200 */
#define USB_EP4R_EP_TYPE_1                      (0x2UL << USB_EP4R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP4R_SETUP_Pos                      (11U)                          
#define USB_EP4R_SETUP_Msk                      (0x1UL << USB_EP4R_SETUP_Pos)   /*!< 0x00000800 */
#define USB_EP4R_SETUP                          USB_EP4R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP4R_STAT_RX_Pos                    (12U)                          
#define USB_EP4R_STAT_RX_Msk                    (0x3UL << USB_EP4R_STAT_RX_Pos) /*!< 0x00003000 */
#define USB_EP4R_STAT_RX                        USB_EP4R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP4R_STAT_RX_0                      (0x1UL << USB_EP4R_STAT_RX_Pos) /*!< 0x00001000 */
#define USB_EP4R_STAT_RX_1                      (0x2UL << USB_EP4R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP4R_DTOG_RX_Pos                    (14U)                          
#define USB_EP4R_DTOG_RX_Msk                    (0x1UL << USB_EP4R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP4R_DTOG_RX                        USB_EP4R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP4R_CTR_RX_Pos                     (15U)                          
#define USB_EP4R_CTR_RX_Msk                     (0x1UL << USB_EP4R_CTR_RX_Pos)  /*!< 0x00008000 */
#define USB_EP4R_CTR_RX                         USB_EP4R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP5R register  *******************/
#define USB_EP5R_EA_Pos                         (0U)                           
#define USB_EP5R_EA_Msk                         (0xFUL << USB_EP5R_EA_Pos)      /*!< 0x0000000F */
#define USB_EP5R_EA                             USB_EP5R_EA_Msk                /*!< Endpoint Address */

#define USB_EP5R_STAT_TX_Pos                    (4U)                           
#define USB_EP5R_STAT_TX_Msk                    (0x3UL << USB_EP5R_STAT_TX_Pos) /*!< 0x00000030 */
#define USB_EP5R_STAT_TX                        USB_EP5R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP5R_STAT_TX_0                      (0x1UL << USB_EP5R_STAT_TX_Pos) /*!< 0x00000010 */
#define USB_EP5R_STAT_TX_1                      (0x2UL << USB_EP5R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP5R_DTOG_TX_Pos                    (6U)                           
#define USB_EP5R_DTOG_TX_Msk                    (0x1UL << USB_EP5R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP5R_DTOG_TX                        USB_EP5R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP5R_CTR_TX_Pos                     (7U)                           
#define USB_EP5R_CTR_TX_Msk                     (0x1UL << USB_EP5R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP5R_CTR_TX                         USB_EP5R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP5R_EP_KIND_Pos                    (8U)                           
#define USB_EP5R_EP_KIND_Msk                    (0x1UL << USB_EP5R_EP_KIND_Pos) /*!< 0x00000100 */
#define USB_EP5R_EP_KIND                        USB_EP5R_EP_KIND_Msk           /*!< Endpoint Kind */

#define USB_EP5R_EP_TYPE_Pos                    (9U)                           
#define USB_EP5R_EP_TYPE_Msk                    (0x3UL << USB_EP5R_EP_TYPE_Pos) /*!< 0x00000600 */
#define USB_EP5R_EP_TYPE                        USB_EP5R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP5R_EP_TYPE_0                      (0x1UL << USB_EP5R_EP_TYPE_Pos) /*!< 0x00000200 */
#define USB_EP5R_EP_TYPE_1                      (0x2UL << USB_EP5R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP5R_SETUP_Pos                      (11U)                          
#define USB_EP5R_SETUP_Msk                      (0x1UL << USB_EP5R_SETUP_Pos)   /*!< 0x00000800 */
#define USB_EP5R_SETUP                          USB_EP5R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP5R_STAT_RX_Pos                    (12U)                          
#define USB_EP5R_STAT_RX_Msk                    (0x3UL << USB_EP5R_STAT_RX_Pos) /*!< 0x00003000 */
#define USB_EP5R_STAT_RX                        USB_EP5R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP5R_STAT_RX_0                      (0x1UL << USB_EP5R_STAT_RX_Pos) /*!< 0x00001000 */
#define USB_EP5R_STAT_RX_1                      (0x2UL << USB_EP5R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP5R_DTOG_RX_Pos                    (14U)                          
#define USB_EP5R_DTOG_RX_Msk                    (0x1UL << USB_EP5R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP5R_DTOG_RX                        USB_EP5R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP5R_CTR_RX_Pos                     (15U)                          
#define USB_EP5R_CTR_RX_Msk                     (0x1UL << USB_EP5R_CTR_RX_Pos)  /*!< 0x00008000 */
#define USB_EP5R_CTR_RX                         USB_EP5R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP6R register  *******************/
#define USB_EP6R_EA_Pos                         (0U)                           
#define USB_EP6R_EA_Msk                         (0xFUL << USB_EP6R_EA_Pos)      /*!< 0x0000000F */
#define USB_EP6R_EA                             USB_EP6R_EA_Msk                /*!< Endpoint Address */

#define USB_EP6R_STAT_TX_Pos                    (4U)                           
#define USB_EP6R_STAT_TX_Msk                    (0x3UL << USB_EP6R_STAT_TX_Pos) /*!< 0x00000030 */
#define USB_EP6R_STAT_TX                        USB_EP6R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP6R_STAT_TX_0                      (0x1UL << USB_EP6R_STAT_TX_Pos) /*!< 0x00000010 */
#define USB_EP6R_STAT_TX_1                      (0x2UL << USB_EP6R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP6R_DTOG_TX_Pos                    (6U)                           
#define USB_EP6R_DTOG_TX_Msk                    (0x1UL << USB_EP6R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP6R_DTOG_TX                        USB_EP6R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP6R_CTR_TX_Pos                     (7U)                           
#define USB_EP6R_CTR_TX_Msk                     (0x1UL << USB_EP6R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP6R_CTR_TX                         USB_EP6R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP6R_EP_KIND_Pos                    (8U)                           
#define USB_EP6R_EP_KIND_Msk                    (0x1UL << USB_EP6R_EP_KIND_Pos) /*!< 0x00000100 */
#define USB_EP6R_EP_KIND                        USB_EP6R_EP_KIND_Msk           /*!< Endpoint Kind */

#define USB_EP6R_EP_TYPE_Pos                    (9U)                           
#define USB_EP6R_EP_TYPE_Msk                    (0x3UL << USB_EP6R_EP_TYPE_Pos) /*!< 0x00000600 */
#define USB_EP6R_EP_TYPE                        USB_EP6R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP6R_EP_TYPE_0                      (0x1UL << USB_EP6R_EP_TYPE_Pos) /*!< 0x00000200 */
#define USB_EP6R_EP_TYPE_1                      (0x2UL << USB_EP6R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP6R_SETUP_Pos                      (11U)                          
#define USB_EP6R_SETUP_Msk                      (0x1UL << USB_EP6R_SETUP_Pos)   /*!< 0x00000800 */
#define USB_EP6R_SETUP                          USB_EP6R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP6R_STAT_RX_Pos                    (12U)                          
#define USB_EP6R_STAT_RX_Msk                    (0x3UL << USB_EP6R_STAT_RX_Pos) /*!< 0x00003000 */
#define USB_EP6R_STAT_RX                        USB_EP6R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP6R_STAT_RX_0                      (0x1UL << USB_EP6R_STAT_RX_Pos) /*!< 0x00001000 */
#define USB_EP6R_STAT_RX_1                      (0x2UL << USB_EP6R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP6R_DTOG_RX_Pos                    (14U)                          
#define USB_EP6R_DTOG_RX_Msk                    (0x1UL << USB_EP6R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP6R_DTOG_RX                        USB_EP6R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP6R_CTR_RX_Pos                     (15U)                          
#define USB_EP6R_CTR_RX_Msk                     (0x1UL << USB_EP6R_CTR_RX_Pos)  /*!< 0x00008000 */
#define USB_EP6R_CTR_RX                         USB_EP6R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*******************  Bit definition for USB_EP7R register  *******************/
#define USB_EP7R_EA_Pos                         (0U)                           
#define USB_EP7R_EA_Msk                         (0xFUL << USB_EP7R_EA_Pos)      /*!< 0x0000000F */
#define USB_EP7R_EA                             USB_EP7R_EA_Msk                /*!< Endpoint Address */

#define USB_EP7R_STAT_TX_Pos                    (4U)                           
#define USB_EP7R_STAT_TX_Msk                    (0x3UL << USB_EP7R_STAT_TX_Pos) /*!< 0x00000030 */
#define USB_EP7R_STAT_TX                        USB_EP7R_STAT_TX_Msk           /*!< STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP7R_STAT_TX_0                      (0x1UL << USB_EP7R_STAT_TX_Pos) /*!< 0x00000010 */
#define USB_EP7R_STAT_TX_1                      (0x2UL << USB_EP7R_STAT_TX_Pos) /*!< 0x00000020 */

#define USB_EP7R_DTOG_TX_Pos                    (6U)                           
#define USB_EP7R_DTOG_TX_Msk                    (0x1UL << USB_EP7R_DTOG_TX_Pos) /*!< 0x00000040 */
#define USB_EP7R_DTOG_TX                        USB_EP7R_DTOG_TX_Msk           /*!< Data Toggle, for transmission transfers */
#define USB_EP7R_CTR_TX_Pos                     (7U)                           
#define USB_EP7R_CTR_TX_Msk                     (0x1UL << USB_EP7R_CTR_TX_Pos)  /*!< 0x00000080 */
#define USB_EP7R_CTR_TX                         USB_EP7R_CTR_TX_Msk            /*!< Correct Transfer for transmission */
#define USB_EP7R_EP_KIND_Pos                    (8U)                           
#define USB_EP7R_EP_KIND_Msk                    (0x1UL << USB_EP7R_EP_KIND_Pos) /*!< 0x00000100 */
#define USB_EP7R_EP_KIND                        USB_EP7R_EP_KIND_Msk           /*!< Endpoint Kind */

#define USB_EP7R_EP_TYPE_Pos                    (9U)                           
#define USB_EP7R_EP_TYPE_Msk                    (0x3UL << USB_EP7R_EP_TYPE_Pos) /*!< 0x00000600 */
#define USB_EP7R_EP_TYPE                        USB_EP7R_EP_TYPE_Msk           /*!< EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP7R_EP_TYPE_0                      (0x1UL << USB_EP7R_EP_TYPE_Pos) /*!< 0x00000200 */
#define USB_EP7R_EP_TYPE_1                      (0x2UL << USB_EP7R_EP_TYPE_Pos) /*!< 0x00000400 */

#define USB_EP7R_SETUP_Pos                      (11U)                          
#define USB_EP7R_SETUP_Msk                      (0x1UL << USB_EP7R_SETUP_Pos)   /*!< 0x00000800 */
#define USB_EP7R_SETUP                          USB_EP7R_SETUP_Msk             /*!< Setup transaction completed */

#define USB_EP7R_STAT_RX_Pos                    (12U)                          
#define USB_EP7R_STAT_RX_Msk                    (0x3UL << USB_EP7R_STAT_RX_Pos) /*!< 0x00003000 */
#define USB_EP7R_STAT_RX                        USB_EP7R_STAT_RX_Msk           /*!< STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP7R_STAT_RX_0                      (0x1UL << USB_EP7R_STAT_RX_Pos) /*!< 0x00001000 */
#define USB_EP7R_STAT_RX_1                      (0x2UL << USB_EP7R_STAT_RX_Pos) /*!< 0x00002000 */

#define USB_EP7R_DTOG_RX_Pos                    (14U)                          
#define USB_EP7R_DTOG_RX_Msk                    (0x1UL << USB_EP7R_DTOG_RX_Pos) /*!< 0x00004000 */
#define USB_EP7R_DTOG_RX                        USB_EP7R_DTOG_RX_Msk           /*!< Data Toggle, for reception transfers */
#define USB_EP7R_CTR_RX_Pos                     (15U)                          
#define USB_EP7R_CTR_RX_Msk                     (0x1UL << USB_EP7R_CTR_RX_Pos)  /*!< 0x00008000 */
#define USB_EP7R_CTR_RX                         USB_EP7R_CTR_RX_Msk            /*!< Correct Transfer for reception */

/*!< Common registers */
/*******************  Bit definition for USB_CNTR register  *******************/
#define USB_CNTR_FRES_Pos                       (0U)                           
#define USB_CNTR_FRES_Msk                       (0x1UL << USB_CNTR_FRES_Pos)    /*!< 0x00000001 */
#define USB_CNTR_FRES                           USB_CNTR_FRES_Msk              /*!< Force USB Reset */
#define USB_CNTR_PDWN_Pos                       (1U)                           
#define USB_CNTR_PDWN_Msk                       (0x1UL << USB_CNTR_PDWN_Pos)    /*!< 0x00000002 */
#define USB_CNTR_PDWN                           USB_CNTR_PDWN_Msk              /*!< Power down */
#define USB_CNTR_LP_MODE_Pos                    (2U)                           
#define USB_CNTR_LP_MODE_Msk                    (0x1UL << USB_CNTR_LP_MODE_Pos) /*!< 0x00000004 */
#define USB_CNTR_LP_MODE                        USB_CNTR_LP_MODE_Msk           /*!< Low-power mode */
#define USB_CNTR_FSUSP_Pos                      (3U)                           
#define USB_CNTR_FSUSP_Msk                      (0x1UL << USB_CNTR_FSUSP_Pos)   /*!< 0x00000008 */
#define USB_CNTR_FSUSP                          USB_CNTR_FSUSP_Msk             /*!< Force suspend */
#define USB_CNTR_RESUME_Pos                     (4U)                           
#define USB_CNTR_RESUME_Msk                     (0x1UL << USB_CNTR_RESUME_Pos)  /*!< 0x00000010 */
#define USB_CNTR_RESUME                         USB_CNTR_RESUME_Msk            /*!< Resume request */
#define USB_CNTR_ESOFM_Pos                      (8U)                           
#define USB_CNTR_ESOFM_Msk                      (0x1UL << USB_CNTR_ESOFM_Pos)   /*!< 0x00000100 */
#define USB_CNTR_ESOFM                          USB_CNTR_ESOFM_Msk             /*!< Expected Start Of Frame Interrupt Mask */
#define USB_CNTR_SOFM_Pos                       (9U)                           
#define USB_CNTR_SOFM_Msk                       (0x1UL << USB_CNTR_SOFM_Pos)    /*!< 0x00000200 */
#define USB_CNTR_SOFM                           USB_CNTR_SOFM_Msk              /*!< Start Of Frame Interrupt Mask */
#define USB_CNTR_RESETM_Pos                     (10U)                          
#define USB_CNTR_RESETM_Msk                     (0x1UL << USB_CNTR_RESETM_Pos)  /*!< 0x00000400 */
#define USB_CNTR_RESETM                         USB_CNTR_RESETM_Msk            /*!< RESET Interrupt Mask */
#define USB_CNTR_SUSPM_Pos                      (11U)                          
#define USB_CNTR_SUSPM_Msk                      (0x1UL << USB_CNTR_SUSPM_Pos)   /*!< 0x00000800 */
#define USB_CNTR_SUSPM                          USB_CNTR_SUSPM_Msk             /*!< Suspend mode Interrupt Mask */
#define USB_CNTR_WKUPM_Pos                      (12U)                          
#define USB_CNTR_WKUPM_Msk                      (0x1UL << USB_CNTR_WKUPM_Pos)   /*!< 0x00001000 */
#define USB_CNTR_WKUPM                          USB_CNTR_WKUPM_Msk             /*!< Wakeup Interrupt Mask */
#define USB_CNTR_ERRM_Pos                       (13U)                          
#define USB_CNTR_ERRM_Msk                       (0x1UL << USB_CNTR_ERRM_Pos)    /*!< 0x00002000 */
#define USB_CNTR_ERRM                           USB_CNTR_ERRM_Msk              /*!< Error Interrupt Mask */
#define USB_CNTR_PMAOVRM_Pos                    (14U)                          
#define USB_CNTR_PMAOVRM_Msk                    (0x1UL << USB_CNTR_PMAOVRM_Pos) /*!< 0x00004000 */
#define USB_CNTR_PMAOVRM                        USB_CNTR_PMAOVRM_Msk           /*!< Packet Memory Area Over / Underrun Interrupt Mask */
#define USB_CNTR_CTRM_Pos                       (15U)                          
#define USB_CNTR_CTRM_Msk                       (0x1UL << USB_CNTR_CTRM_Pos)    /*!< 0x00008000 */
#define USB_CNTR_CTRM                           USB_CNTR_CTRM_Msk              /*!< Correct Transfer Interrupt Mask */

/*******************  Bit definition for USB_ISTR register  *******************/
#define USB_ISTR_EP_ID_Pos                      (0U)                           
#define USB_ISTR_EP_ID_Msk                      (0xFUL << USB_ISTR_EP_ID_Pos)   /*!< 0x0000000F */
#define USB_ISTR_EP_ID                          USB_ISTR_EP_ID_Msk             /*!< Endpoint Identifier */
#define USB_ISTR_DIR_Pos                        (4U)                           
#define USB_ISTR_DIR_Msk                        (0x1UL << USB_ISTR_DIR_Pos)     /*!< 0x00000010 */
#define USB_ISTR_DIR                            USB_ISTR_DIR_Msk               /*!< Direction of transaction */
#define USB_ISTR_ESOF_Pos                       (8U)                           
#define USB_ISTR_ESOF_Msk                       (0x1UL << USB_ISTR_ESOF_Pos)    /*!< 0x00000100 */
#define USB_ISTR_ESOF                           USB_ISTR_ESOF_Msk              /*!< Expected Start Of Frame */
#define USB_ISTR_SOF_Pos                        (9U)                           
#define USB_ISTR_SOF_Msk                        (0x1UL << USB_ISTR_SOF_Pos)     /*!< 0x00000200 */
#define USB_ISTR_SOF                            USB_ISTR_SOF_Msk               /*!< Start Of Frame */
#define USB_ISTR_RESET_Pos                      (10U)                          
#define USB_ISTR_RESET_Msk                      (0x1UL << USB_ISTR_RESET_Pos)   /*!< 0x00000400 */
#define USB_ISTR_RESET                          USB_ISTR_RESET_Msk             /*!< USB RESET request */
#define USB_ISTR_SUSP_Pos                       (11U)                          
#define USB_ISTR_SUSP_Msk                       (0x1UL << USB_ISTR_SUSP_Pos)    /*!< 0x00000800 */
#define USB_ISTR_SUSP                           USB_ISTR_SUSP_Msk              /*!< Suspend mode request */
#define USB_ISTR_WKUP_Pos                       (12U)                          
#define USB_ISTR_WKUP_Msk                       (0x1UL << USB_ISTR_WKUP_Pos)    /*!< 0x00001000 */
#define USB_ISTR_WKUP                           USB_ISTR_WKUP_Msk              /*!< Wake up */
#define USB_ISTR_ERR_Pos                        (13U)                          
#define USB_ISTR_ERR_Msk                        (0x1UL << USB_ISTR_ERR_Pos)     /*!< 0x00002000 */
#define USB_ISTR_ERR                            USB_ISTR_ERR_Msk               /*!< Error */
#define USB_ISTR_PMAOVR_Pos                     (14U)                          
#define USB_ISTR_PMAOVR_Msk                     (0x1UL << USB_ISTR_PMAOVR_Pos)  /*!< 0x00004000 */
#define USB_ISTR_PMAOVR                         USB_ISTR_PMAOVR_Msk            /*!< Packet Memory Area Over / Underrun */
#define USB_ISTR_CTR_Pos                        (15U)                          
#define USB_ISTR_CTR_Msk                        (0x1UL << USB_ISTR_CTR_Pos)     /*!< 0x00008000 */
#define USB_ISTR_CTR                            USB_ISTR_CTR_Msk               /*!< Correct Transfer */

/*******************  Bit definition for USB_FNR register  ********************/
#define USB_FNR_FN_Pos                          (0U)                           
#define USB_FNR_FN_Msk                          (0x7FFUL << USB_FNR_FN_Pos)     /*!< 0x000007FF */
#define USB_FNR_FN                              USB_FNR_FN_Msk                 /*!< Frame Number */
#define USB_FNR_LSOF_Pos                        (11U)                          
#define USB_FNR_LSOF_Msk                        (0x3UL << USB_FNR_LSOF_Pos)     /*!< 0x00001800 */
#define USB_FNR_LSOF                            USB_FNR_LSOF_Msk               /*!< Lost SOF */
#define USB_FNR_LCK_Pos                         (13U)                          
#define USB_FNR_LCK_Msk                         (0x1UL << USB_FNR_LCK_Pos)      /*!< 0x00002000 */
#define USB_FNR_LCK                             USB_FNR_LCK_Msk                /*!< Locked */
#define USB_FNR_RXDM_Pos                        (14U)                          
#define USB_FNR_RXDM_Msk                        (0x1UL << USB_FNR_RXDM_Pos)     /*!< 0x00004000 */
#define USB_FNR_RXDM                            USB_FNR_RXDM_Msk               /*!< Receive Data - Line Status */
#define USB_FNR_RXDP_Pos                        (15U)                          
#define USB_FNR_RXDP_Msk                        (0x1UL << USB_FNR_RXDP_Pos)     /*!< 0x00008000 */
#define USB_FNR_RXDP                            USB_FNR_RXDP_Msk               /*!< Receive Data + Line Status */

/******************  Bit definition for USB_DADDR register  *******************/
#define USB_DADDR_ADD_Pos                       (0U)                           
#define USB_DADDR_ADD_Msk                       (0x7FUL << USB_DADDR_ADD_Pos)   /*!< 0x0000007F */
#define USB_DADDR_ADD                           USB_DADDR_ADD_Msk              /*!< ADD[6:0] bits (Device Address) */
#define USB_DADDR_ADD0_Pos                      (0U)                           
#define USB_DADDR_ADD0_Msk                      (0x1UL << USB_DADDR_ADD0_Pos)   /*!< 0x00000001 */
#define USB_DADDR_ADD0                          USB_DADDR_ADD0_Msk             /*!< Bit 0 */
#define USB_DADDR_ADD1_Pos                      (1U)                           
#define USB_DADDR_ADD1_Msk                      (0x1UL << USB_DADDR_ADD1_Pos)   /*!< 0x00000002 */
#define USB_DADDR_ADD1                          USB_DADDR_ADD1_Msk             /*!< Bit 1 */
#define USB_DADDR_ADD2_Pos                      (2U)                           
#define USB_DADDR_ADD2_Msk                      (0x1UL << USB_DADDR_ADD2_Pos)   /*!< 0x00000004 */
#define USB_DADDR_ADD2                          USB_DADDR_ADD2_Msk             /*!< Bit 2 */
#define USB_DADDR_ADD3_Pos                      (3U)                           
#define USB_DADDR_ADD3_Msk                      (0x1UL << USB_DADDR_ADD3_Pos)   /*!< 0x00000008 */
#define USB_DADDR_ADD3                          USB_DADDR_ADD3_Msk             /*!< Bit 3 */
#define USB_DADDR_ADD4_Pos                      (4U)                           
#define USB_DADDR_ADD4_Msk                      (0x1UL << USB_DADDR_ADD4_Pos)   /*!< 0x00000010 */
#define USB_DADDR_ADD4                          USB_DADDR_ADD4_Msk             /*!< Bit 4 */
#define USB_DADDR_ADD5_Pos                      (5U)                           
#define USB_DADDR_ADD5_Msk                      (0x1UL << USB_DADDR_ADD5_Pos)   /*!< 0x00000020 */
#define USB_DADDR_ADD5                          USB_DADDR_ADD5_Msk             /*!< Bit 5 */
#define USB_DADDR_ADD6_Pos                      (6U)                           
#define USB_DADDR_ADD6_Msk                      (0x1UL << USB_DADDR_ADD6_Pos)   /*!< 0x00000040 */
#define USB_DADDR_ADD6                          USB_DADDR_ADD6_Msk             /*!< Bit 6 */

#define USB_DADDR_EF_Pos                        (7U)                           
#define USB_DADDR_EF_Msk                        (0x1UL << USB_DADDR_EF_Pos)     /*!< 0x00000080 */
#define USB_DADDR_EF                            USB_DADDR_EF_Msk               /*!< Enable Function */

/******************  Bit definition for USB_BTABLE register  ******************/    
#define USB_BTABLE_BTABLE_Pos                   (3U)                           
#define USB_BTABLE_BTABLE_Msk                   (0x1FFFUL << USB_BTABLE_BTABLE_Pos) /*!< 0x0000FFF8 */
#define USB_BTABLE_BTABLE                       USB_BTABLE_BTABLE_Msk          /*!< Buffer Table */

/*!< Buffer descriptor table */
/*****************  Bit definition for USB_ADDR0_TX register  *****************/
#define USB_ADDR0_TX_ADDR0_TX_Pos               (1U)                           
#define USB_ADDR0_TX_ADDR0_TX_Msk               (0x7FFFUL << USB_ADDR0_TX_ADDR0_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR0_TX_ADDR0_TX                   USB_ADDR0_TX_ADDR0_TX_Msk      /*!< Transmission Buffer Address 0 */

/*****************  Bit definition for USB_ADDR1_TX register  *****************/
#define USB_ADDR1_TX_ADDR1_TX_Pos               (1U)                           
#define USB_ADDR1_TX_ADDR1_TX_Msk               (0x7FFFUL << USB_ADDR1_TX_ADDR1_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR1_TX_ADDR1_TX                   USB_ADDR1_TX_ADDR1_TX_Msk      /*!< Transmission Buffer Address 1 */

/*****************  Bit definition for USB_ADDR2_TX register  *****************/
#define USB_ADDR2_TX_ADDR2_TX_Pos               (1U)                           
#define USB_ADDR2_TX_ADDR2_TX_Msk               (0x7FFFUL << USB_ADDR2_TX_ADDR2_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR2_TX_ADDR2_TX                   USB_ADDR2_TX_ADDR2_TX_Msk      /*!< Transmission Buffer Address 2 */

/*****************  Bit definition for USB_ADDR3_TX register  *****************/
#define USB_ADDR3_TX_ADDR3_TX_Pos               (1U)                           
#define USB_ADDR3_TX_ADDR3_TX_Msk               (0x7FFFUL << USB_ADDR3_TX_ADDR3_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR3_TX_ADDR3_TX                   USB_ADDR3_TX_ADDR3_TX_Msk      /*!< Transmission Buffer Address 3 */

/*****************  Bit definition for USB_ADDR4_TX register  *****************/
#define USB_ADDR4_TX_ADDR4_TX_Pos               (1U)                           
#define USB_ADDR4_TX_ADDR4_TX_Msk               (0x7FFFUL << USB_ADDR4_TX_ADDR4_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR4_TX_ADDR4_TX                   USB_ADDR4_TX_ADDR4_TX_Msk      /*!< Transmission Buffer Address 4 */

/*****************  Bit definition for USB_ADDR5_TX register  *****************/
#define USB_ADDR5_TX_ADDR5_TX_Pos               (1U)                           
#define USB_ADDR5_TX_ADDR5_TX_Msk               (0x7FFFUL << USB_ADDR5_TX_ADDR5_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR5_TX_ADDR5_TX                   USB_ADDR5_TX_ADDR5_TX_Msk      /*!< Transmission Buffer Address 5 */

/*****************  Bit definition for USB_ADDR6_TX register  *****************/
#define USB_ADDR6_TX_ADDR6_TX_Pos               (1U)                           
#define USB_ADDR6_TX_ADDR6_TX_Msk               (0x7FFFUL << USB_ADDR6_TX_ADDR6_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR6_TX_ADDR6_TX                   USB_ADDR6_TX_ADDR6_TX_Msk      /*!< Transmission Buffer Address 6 */

/*****************  Bit definition for USB_ADDR7_TX register  *****************/
#define USB_ADDR7_TX_ADDR7_TX_Pos               (1U)                           
#define USB_ADDR7_TX_ADDR7_TX_Msk               (0x7FFFUL << USB_ADDR7_TX_ADDR7_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR7_TX_ADDR7_TX                   USB_ADDR7_TX_ADDR7_TX_Msk      /*!< Transmission Buffer Address 7 */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_COUNT0_TX register  ****************/
#define USB_COUNT0_TX_COUNT0_TX_Pos             (0U)                           
#define USB_COUNT0_TX_COUNT0_TX_Msk             (0x3FFUL << USB_COUNT0_TX_COUNT0_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT0_TX_COUNT0_TX                 USB_COUNT0_TX_COUNT0_TX_Msk    /*!< Transmission Byte Count 0 */

/*****************  Bit definition for USB_COUNT1_TX register  ****************/
#define USB_COUNT1_TX_COUNT1_TX_Pos             (0U)                           
#define USB_COUNT1_TX_COUNT1_TX_Msk             (0x3FFUL << USB_COUNT1_TX_COUNT1_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT1_TX_COUNT1_TX                 USB_COUNT1_TX_COUNT1_TX_Msk    /*!< Transmission Byte Count 1 */

/*****************  Bit definition for USB_COUNT2_TX register  ****************/
#define USB_COUNT2_TX_COUNT2_TX_Pos             (0U)                           
#define USB_COUNT2_TX_COUNT2_TX_Msk             (0x3FFUL << USB_COUNT2_TX_COUNT2_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT2_TX_COUNT2_TX                 USB_COUNT2_TX_COUNT2_TX_Msk    /*!< Transmission Byte Count 2 */

/*****************  Bit definition for USB_COUNT3_TX register  ****************/
#define USB_COUNT3_TX_COUNT3_TX_Pos             (0U)                           
#define USB_COUNT3_TX_COUNT3_TX_Msk             (0x3FFUL << USB_COUNT3_TX_COUNT3_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT3_TX_COUNT3_TX                 USB_COUNT3_TX_COUNT3_TX_Msk    /*!< Transmission Byte Count 3 */

/*****************  Bit definition for USB_COUNT4_TX register  ****************/
#define USB_COUNT4_TX_COUNT4_TX_Pos             (0U)                           
#define USB_COUNT4_TX_COUNT4_TX_Msk             (0x3FFUL << USB_COUNT4_TX_COUNT4_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT4_TX_COUNT4_TX                 USB_COUNT4_TX_COUNT4_TX_Msk    /*!< Transmission Byte Count 4 */

/*****************  Bit definition for USB_COUNT5_TX register  ****************/
#define USB_COUNT5_TX_COUNT5_TX_Pos             (0U)                           
#define USB_COUNT5_TX_COUNT5_TX_Msk             (0x3FFUL << USB_COUNT5_TX_COUNT5_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT5_TX_COUNT5_TX                 USB_COUNT5_TX_COUNT5_TX_Msk    /*!< Transmission Byte Count 5 */

/*****************  Bit definition for USB_COUNT6_TX register  ****************/
#define USB_COUNT6_TX_COUNT6_TX_Pos             (0U)                           
#define USB_COUNT6_TX_COUNT6_TX_Msk             (0x3FFUL << USB_COUNT6_TX_COUNT6_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT6_TX_COUNT6_TX                 USB_COUNT6_TX_COUNT6_TX_Msk    /*!< Transmission Byte Count 6 */

/*****************  Bit definition for USB_COUNT7_TX register  ****************/
#define USB_COUNT7_TX_COUNT7_TX_Pos             (0U)                           
#define USB_COUNT7_TX_COUNT7_TX_Msk             (0x3FFUL << USB_COUNT7_TX_COUNT7_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT7_TX_COUNT7_TX                 USB_COUNT7_TX_COUNT7_TX_Msk    /*!< Transmission Byte Count 7 */

/*----------------------------------------------------------------------------*/

/****************  Bit definition for USB_COUNT0_TX_0 register  ***************/
#define USB_COUNT0_TX_0_COUNT0_TX_0             0x000003FFU         /*!< Transmission Byte Count 0 (low) */

/****************  Bit definition for USB_COUNT0_TX_1 register  ***************/
#define USB_COUNT0_TX_1_COUNT0_TX_1             0x03FF0000U         /*!< Transmission Byte Count 0 (high) */

/****************  Bit definition for USB_COUNT1_TX_0 register  ***************/
#define USB_COUNT1_TX_0_COUNT1_TX_0             0x000003FFU         /*!< Transmission Byte Count 1 (low) */

/****************  Bit definition for USB_COUNT1_TX_1 register  ***************/
#define USB_COUNT1_TX_1_COUNT1_TX_1             0x03FF0000U         /*!< Transmission Byte Count 1 (high) */

/****************  Bit definition for USB_COUNT2_TX_0 register  ***************/
#define USB_COUNT2_TX_0_COUNT2_TX_0             0x000003FFU         /*!< Transmission Byte Count 2 (low) */

/****************  Bit definition for USB_COUNT2_TX_1 register  ***************/
#define USB_COUNT2_TX_1_COUNT2_TX_1             0x03FF0000U         /*!< Transmission Byte Count 2 (high) */

/****************  Bit definition for USB_COUNT3_TX_0 register  ***************/
#define USB_COUNT3_TX_0_COUNT3_TX_0             0x000003FFU         /*!< Transmission Byte Count 3 (low) */

/****************  Bit definition for USB_COUNT3_TX_1 register  ***************/
#define USB_COUNT3_TX_1_COUNT3_TX_1             0x03FF0000U         /*!< Transmission Byte Count 3 (high) */

/****************  Bit definition for USB_COUNT4_TX_0 register  ***************/
#define USB_COUNT4_TX_0_COUNT4_TX_0             0x000003FFU         /*!< Transmission Byte Count 4 (low) */

/****************  Bit definition for USB_COUNT4_TX_1 register  ***************/
#define USB_COUNT4_TX_1_COUNT4_TX_1             0x03FF0000U         /*!< Transmission Byte Count 4 (high) */

/****************  Bit definition for USB_COUNT5_TX_0 register  ***************/
#define USB_COUNT5_TX_0_COUNT5_TX_0             0x000003FFU         /*!< Transmission Byte Count 5 (low) */

/****************  Bit definition for USB_COUNT5_TX_1 register  ***************/
#define USB_COUNT5_TX_1_COUNT5_TX_1             0x03FF0000U         /*!< Transmission Byte Count 5 (high) */

/****************  Bit definition for USB_COUNT6_TX_0 register  ***************/
#define USB_COUNT6_TX_0_COUNT6_TX_0             0x000003FFU         /*!< Transmission Byte Count 6 (low) */

/****************  Bit definition for USB_COUNT6_TX_1 register  ***************/
#define USB_COUNT6_TX_1_COUNT6_TX_1             0x03FF0000U         /*!< Transmission Byte Count 6 (high) */

/****************  Bit definition for USB_COUNT7_TX_0 register  ***************/
#define USB_COUNT7_TX_0_COUNT7_TX_0             0x000003FFU         /*!< Transmission Byte Count 7 (low) */

/****************  Bit definition for USB_COUNT7_TX_1 register  ***************/
#define USB_COUNT7_TX_1_COUNT7_TX_1             0x03FF0000U         /*!< Transmission Byte Count 7 (high) */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_ADDR0_RX register  *****************/
#define USB_ADDR0_RX_ADDR0_RX_Pos               (1U)                           
#define USB_ADDR0_RX_ADDR0_RX_Msk               (0x7FFFUL << USB_ADDR0_RX_ADDR0_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR0_RX_ADDR0_RX                   USB_ADDR0_RX_ADDR0_RX_Msk      /*!< Reception Buffer Address 0 */

/*****************  Bit definition for USB_ADDR1_RX register  *****************/
#define USB_ADDR1_RX_ADDR1_RX_Pos               (1U)                           
#define USB_ADDR1_RX_ADDR1_RX_Msk               (0x7FFFUL << USB_ADDR1_RX_ADDR1_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR1_RX_ADDR1_RX                   USB_ADDR1_RX_ADDR1_RX_Msk      /*!< Reception Buffer Address 1 */

/*****************  Bit definition for USB_ADDR2_RX register  *****************/
#define USB_ADDR2_RX_ADDR2_RX_Pos               (1U)                           
#define USB_ADDR2_RX_ADDR2_RX_Msk               (0x7FFFUL << USB_ADDR2_RX_ADDR2_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR2_RX_ADDR2_RX                   USB_ADDR2_RX_ADDR2_RX_Msk      /*!< Reception Buffer Address 2 */

/*****************  Bit definition for USB_ADDR3_RX register  *****************/
#define USB_ADDR3_RX_ADDR3_RX_Pos               (1U)                           
#define USB_ADDR3_RX_ADDR3_RX_Msk               (0x7FFFUL << USB_ADDR3_RX_ADDR3_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR3_RX_ADDR3_RX                   USB_ADDR3_RX_ADDR3_RX_Msk      /*!< Reception Buffer Address 3 */

/*****************  Bit definition for USB_ADDR4_RX register  *****************/
#define USB_ADDR4_RX_ADDR4_RX_Pos               (1U)                           
#define USB_ADDR4_RX_ADDR4_RX_Msk               (0x7FFFUL << USB_ADDR4_RX_ADDR4_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR4_RX_ADDR4_RX                   USB_ADDR4_RX_ADDR4_RX_Msk      /*!< Reception Buffer Address 4 */

/*****************  Bit definition for USB_ADDR5_RX register  *****************/
#define USB_ADDR5_RX_ADDR5_RX_Pos               (1U)                           
#define USB_ADDR5_RX_ADDR5_RX_Msk               (0x7FFFUL << USB_ADDR5_RX_ADDR5_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR5_RX_ADDR5_RX                   USB_ADDR5_RX_ADDR5_RX_Msk      /*!< Reception Buffer Address 5 */

/*****************  Bit definition for USB_ADDR6_RX register  *****************/
#define USB_ADDR6_RX_ADDR6_RX_Pos               (1U)                           
#define USB_ADDR6_RX_ADDR6_RX_Msk               (0x7FFFUL << USB_ADDR6_RX_ADDR6_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR6_RX_ADDR6_RX                   USB_ADDR6_RX_ADDR6_RX_Msk      /*!< Reception Buffer Address 6 */

/*****************  Bit definition for USB_ADDR7_RX register  *****************/
#define USB_ADDR7_RX_ADDR7_RX_Pos               (1U)                           
#define USB_ADDR7_RX_ADDR7_RX_Msk               (0x7FFFUL << USB_ADDR7_RX_ADDR7_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR7_RX_ADDR7_RX                   USB_ADDR7_RX_ADDR7_RX_Msk      /*!< Reception Buffer Address 7 */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_COUNT0_RX register  ****************/
#define USB_COUNT0_RX_COUNT0_RX_Pos             (0U)                           
#define USB_COUNT0_RX_COUNT0_RX_Msk             (0x3FFUL << USB_COUNT0_RX_COUNT0_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT0_RX_COUNT0_RX                 USB_COUNT0_RX_COUNT0_RX_Msk    /*!< Reception Byte Count */

#define USB_COUNT0_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT0_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT0_RX_NUM_BLOCK                 USB_COUNT0_RX_NUM_BLOCK_Msk    /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT0_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT0_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT0_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT0_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT0_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT0_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT0_RX_BLSIZE_Msk                (0x1UL << USB_COUNT0_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT0_RX_BLSIZE                    USB_COUNT0_RX_BLSIZE_Msk       /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT1_RX register  ****************/
#define USB_COUNT1_RX_COUNT1_RX_Pos             (0U)                           
#define USB_COUNT1_RX_COUNT1_RX_Msk             (0x3FFUL << USB_COUNT1_RX_COUNT1_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT1_RX_COUNT1_RX                 USB_COUNT1_RX_COUNT1_RX_Msk    /*!< Reception Byte Count */

#define USB_COUNT1_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT1_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT1_RX_NUM_BLOCK                 USB_COUNT1_RX_NUM_BLOCK_Msk    /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT1_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT1_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT1_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT1_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT1_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT1_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT1_RX_BLSIZE_Msk                (0x1UL << USB_COUNT1_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT1_RX_BLSIZE                    USB_COUNT1_RX_BLSIZE_Msk       /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT2_RX register  ****************/
#define USB_COUNT2_RX_COUNT2_RX_Pos             (0U)                           
#define USB_COUNT2_RX_COUNT2_RX_Msk             (0x3FFUL << USB_COUNT2_RX_COUNT2_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT2_RX_COUNT2_RX                 USB_COUNT2_RX_COUNT2_RX_Msk    /*!< Reception Byte Count */

#define USB_COUNT2_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT2_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT2_RX_NUM_BLOCK                 USB_COUNT2_RX_NUM_BLOCK_Msk    /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT2_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT2_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT2_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT2_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT2_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT2_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT2_RX_BLSIZE_Msk                (0x1UL << USB_COUNT2_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT2_RX_BLSIZE                    USB_COUNT2_RX_BLSIZE_Msk       /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT3_RX register  ****************/
#define USB_COUNT3_RX_COUNT3_RX_Pos             (0U)                           
#define USB_COUNT3_RX_COUNT3_RX_Msk             (0x3FFUL << USB_COUNT3_RX_COUNT3_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT3_RX_COUNT3_RX                 USB_COUNT3_RX_COUNT3_RX_Msk    /*!< Reception Byte Count */

#define USB_COUNT3_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT3_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT3_RX_NUM_BLOCK                 USB_COUNT3_RX_NUM_BLOCK_Msk    /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT3_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT3_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT3_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT3_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT3_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT3_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT3_RX_BLSIZE_Msk                (0x1UL << USB_COUNT3_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT3_RX_BLSIZE                    USB_COUNT3_RX_BLSIZE_Msk       /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT4_RX register  ****************/
#define USB_COUNT4_RX_COUNT4_RX_Pos             (0U)                           
#define USB_COUNT4_RX_COUNT4_RX_Msk             (0x3FFUL << USB_COUNT4_RX_COUNT4_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT4_RX_COUNT4_RX                 USB_COUNT4_RX_COUNT4_RX_Msk    /*!< Reception Byte Count */

#define USB_COUNT4_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT4_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT4_RX_NUM_BLOCK                 USB_COUNT4_RX_NUM_BLOCK_Msk    /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT4_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT4_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT4_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT4_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT4_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT4_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT4_RX_BLSIZE_Msk                (0x1UL << USB_COUNT4_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT4_RX_BLSIZE                    USB_COUNT4_RX_BLSIZE_Msk       /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT5_RX register  ****************/
#define USB_COUNT5_RX_COUNT5_RX_Pos             (0U)                           
#define USB_COUNT5_RX_COUNT5_RX_Msk             (0x3FFUL << USB_COUNT5_RX_COUNT5_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT5_RX_COUNT5_RX                 USB_COUNT5_RX_COUNT5_RX_Msk    /*!< Reception Byte Count */

#define USB_COUNT5_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT5_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT5_RX_NUM_BLOCK                 USB_COUNT5_RX_NUM_BLOCK_Msk    /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT5_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT5_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT5_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT5_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT5_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT5_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT5_RX_BLSIZE_Msk                (0x1UL << USB_COUNT5_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT5_RX_BLSIZE                    USB_COUNT5_RX_BLSIZE_Msk       /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT6_RX register  ****************/
#define USB_COUNT6_RX_COUNT6_RX_Pos             (0U)                           
#define USB_COUNT6_RX_COUNT6_RX_Msk             (0x3FFUL << USB_COUNT6_RX_COUNT6_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT6_RX_COUNT6_RX                 USB_COUNT6_RX_COUNT6_RX_Msk    /*!< Reception Byte Count */

#define USB_COUNT6_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT6_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT6_RX_NUM_BLOCK                 USB_COUNT6_RX_NUM_BLOCK_Msk    /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT6_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT6_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT6_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT6_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT6_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT6_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT6_RX_BLSIZE_Msk                (0x1UL << USB_COUNT6_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT6_RX_BLSIZE                    USB_COUNT6_RX_BLSIZE_Msk       /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT7_RX register  ****************/
#define USB_COUNT7_RX_COUNT7_RX_Pos             (0U)                           
#define USB_COUNT7_RX_COUNT7_RX_Msk             (0x3FFUL << USB_COUNT7_RX_COUNT7_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT7_RX_COUNT7_RX                 USB_COUNT7_RX_COUNT7_RX_Msk    /*!< Reception Byte Count */

#define USB_COUNT7_RX_NUM_BLOCK_Pos             (10U)                          
#define USB_COUNT7_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT7_RX_NUM_BLOCK                 USB_COUNT7_RX_NUM_BLOCK_Msk    /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT7_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT7_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT7_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT7_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT7_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT7_RX_BLSIZE_Pos                (15U)                          
#define USB_COUNT7_RX_BLSIZE_Msk                (0x1UL << USB_COUNT7_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT7_RX_BLSIZE                    USB_COUNT7_RX_BLSIZE_Msk       /*!< BLock SIZE */

/*----------------------------------------------------------------------------*/

/****************  Bit definition for USB_COUNT0_RX_0 register  ***************/
#define USB_COUNT0_RX_0_COUNT0_RX_0             0x000003FFU                    /*!< Reception Byte Count (low) */

#define USB_COUNT0_RX_0_NUM_BLOCK_0             0x00007C00U                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_0           0x00000400U                    /*!< Bit 0 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_1           0x00000800U                    /*!< Bit 1 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_2           0x00001000U                    /*!< Bit 2 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_3           0x00002000U                    /*!< Bit 3 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_4           0x00004000U                    /*!< Bit 4 */

#define USB_COUNT0_RX_0_BLSIZE_0                0x00008000U                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT0_RX_1 register  ***************/
#define USB_COUNT0_RX_1_COUNT0_RX_1             0x03FF0000U                    /*!< Reception Byte Count (high) */

#define USB_COUNT0_RX_1_NUM_BLOCK_1             0x7C000000U                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_0           0x04000000U                    /*!< Bit 1 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_1           0x08000000U                    /*!< Bit 1 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_2           0x10000000U                    /*!< Bit 2 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_3           0x20000000U                    /*!< Bit 3 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_4           0x40000000U                    /*!< Bit 4 */

#define USB_COUNT0_RX_1_BLSIZE_1                0x80000000U                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT1_RX_0 register  ***************/
#define USB_COUNT1_RX_0_COUNT1_RX_0             0x000003FFU                    /*!< Reception Byte Count (low) */

#define USB_COUNT1_RX_0_NUM_BLOCK_0             0x00007C00U                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_0           0x00000400U                    /*!< Bit 0 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_1           0x00000800U                    /*!< Bit 1 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_2           0x00001000U                    /*!< Bit 2 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_3           0x00002000U                    /*!< Bit 3 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_4           0x00004000U                    /*!< Bit 4 */

#define USB_COUNT1_RX_0_BLSIZE_0                0x00008000U                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT1_RX_1 register  ***************/
#define USB_COUNT1_RX_1_COUNT1_RX_1             0x03FF0000U                    /*!< Reception Byte Count (high) */

#define USB_COUNT1_RX_1_NUM_BLOCK_1             0x7C000000U                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_0           0x04000000U                    /*!< Bit 0 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_1           0x08000000U                    /*!< Bit 1 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_2           0x10000000U                    /*!< Bit 2 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_3           0x20000000U                    /*!< Bit 3 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_4           0x40000000U                    /*!< Bit 4 */

#define USB_COUNT1_RX_1_BLSIZE_1                0x80000000U                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT2_RX_0 register  ***************/
#define USB_COUNT2_RX_0_COUNT2_RX_0             0x000003FFU                    /*!< Reception Byte Count (low) */

#define USB_COUNT2_RX_0_NUM_BLOCK_0             0x00007C00U                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_0           0x00000400U                    /*!< Bit 0 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_1           0x00000800U                    /*!< Bit 1 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_2           0x00001000U                    /*!< Bit 2 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_3           0x00002000U                    /*!< Bit 3 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_4           0x00004000U                    /*!< Bit 4 */

#define USB_COUNT2_RX_0_BLSIZE_0                0x00008000U                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT2_RX_1 register  ***************/
#define USB_COUNT2_RX_1_COUNT2_RX_1             0x03FF0000U                    /*!< Reception Byte Count (high) */

#define USB_COUNT2_RX_1_NUM_BLOCK_1             0x7C000000U                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_0           0x04000000U                    /*!< Bit 0 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_1           0x08000000U                    /*!< Bit 1 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_2           0x10000000U                    /*!< Bit 2 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_3           0x20000000U                    /*!< Bit 3 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_4           0x40000000U                    /*!< Bit 4 */

#define USB_COUNT2_RX_1_BLSIZE_1                0x80000000U                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT3_RX_0 register  ***************/
#define USB_COUNT3_RX_0_COUNT3_RX_0             0x000003FFU                    /*!< Reception Byte Count (low) */

#define USB_COUNT3_RX_0_NUM_BLOCK_0             0x00007C00U                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_0           0x00000400U                    /*!< Bit 0 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_1           0x00000800U                    /*!< Bit 1 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_2           0x00001000U                    /*!< Bit 2 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_3           0x00002000U                    /*!< Bit 3 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_4           0x00004000U                    /*!< Bit 4 */

#define USB_COUNT3_RX_0_BLSIZE_0                0x00008000U                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT3_RX_1 register  ***************/
#define USB_COUNT3_RX_1_COUNT3_RX_1             0x03FF0000U                    /*!< Reception Byte Count (high) */

#define USB_COUNT3_RX_1_NUM_BLOCK_1             0x7C000000U                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_0           0x04000000U                    /*!< Bit 0 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_1           0x08000000U                    /*!< Bit 1 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_2           0x10000000U                    /*!< Bit 2 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_3           0x20000000U                    /*!< Bit 3 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_4           0x40000000U                    /*!< Bit 4 */

#define USB_COUNT3_RX_1_BLSIZE_1                0x80000000U                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT4_RX_0 register  ***************/
#define USB_COUNT4_RX_0_COUNT4_RX_0             0x000003FFU                    /*!< Reception Byte Count (low) */

#define USB_COUNT4_RX_0_NUM_BLOCK_0             0x00007C00U                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_0           0x00000400U                    /*!< Bit 0 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_1           0x00000800U                    /*!< Bit 1 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_2           0x00001000U                    /*!< Bit 2 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_3           0x00002000U                    /*!< Bit 3 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_4           0x00004000U                    /*!< Bit 4 */

#define USB_COUNT4_RX_0_BLSIZE_0                0x00008000U                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT4_RX_1 register  ***************/
#define USB_COUNT4_RX_1_COUNT4_RX_1             0x03FF0000U                    /*!< Reception Byte Count (high) */

#define USB_COUNT4_RX_1_NUM_BLOCK_1             0x7C000000U                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_0           0x04000000U                    /*!< Bit 0 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_1           0x08000000U                    /*!< Bit 1 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_2           0x10000000U                    /*!< Bit 2 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_3           0x20000000U                    /*!< Bit 3 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_4           0x40000000U                    /*!< Bit 4 */

#define USB_COUNT4_RX_1_BLSIZE_1                0x80000000U                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT5_RX_0 register  ***************/
#define USB_COUNT5_RX_0_COUNT5_RX_0             0x000003FFU                    /*!< Reception Byte Count (low) */

#define USB_COUNT5_RX_0_NUM_BLOCK_0             0x00007C00U                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_0           0x00000400U                    /*!< Bit 0 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_1           0x00000800U                    /*!< Bit 1 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_2           0x00001000U                    /*!< Bit 2 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_3           0x00002000U                    /*!< Bit 3 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_4           0x00004000U                    /*!< Bit 4 */

#define USB_COUNT5_RX_0_BLSIZE_0                0x00008000U                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT5_RX_1 register  ***************/
#define USB_COUNT5_RX_1_COUNT5_RX_1             0x03FF0000U                    /*!< Reception Byte Count (high) */

#define USB_COUNT5_RX_1_NUM_BLOCK_1             0x7C000000U                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_0           0x04000000U                    /*!< Bit 0 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_1           0x08000000U                    /*!< Bit 1 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_2           0x10000000U                    /*!< Bit 2 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_3           0x20000000U                    /*!< Bit 3 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_4           0x40000000U                    /*!< Bit 4 */

#define USB_COUNT5_RX_1_BLSIZE_1                0x80000000U                    /*!< BLock SIZE (high) */

/***************  Bit definition for USB_COUNT6_RX_0  register  ***************/
#define USB_COUNT6_RX_0_COUNT6_RX_0             0x000003FFU                    /*!< Reception Byte Count (low) */

#define USB_COUNT6_RX_0_NUM_BLOCK_0             0x00007C00U                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_0           0x00000400U                    /*!< Bit 0 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_1           0x00000800U                    /*!< Bit 1 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_2           0x00001000U                    /*!< Bit 2 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_3           0x00002000U                    /*!< Bit 3 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_4           0x00004000U                    /*!< Bit 4 */

#define USB_COUNT6_RX_0_BLSIZE_0                0x00008000U                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT6_RX_1 register  ***************/
#define USB_COUNT6_RX_1_COUNT6_RX_1             0x03FF0000U                   /*!< Reception Byte Count (high) */

#define USB_COUNT6_RX_1_NUM_BLOCK_1             0x7C000000U                   /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_0           0x04000000U                   /*!< Bit 0 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_1           0x08000000U                   /*!< Bit 1 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_2           0x10000000U                   /*!< Bit 2 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_3           0x20000000U                   /*!< Bit 3 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_4           0x40000000U                   /*!< Bit 4 */

#define USB_COUNT6_RX_1_BLSIZE_1                0x80000000U                   /*!< BLock SIZE (high) */

/***************  Bit definition for USB_COUNT7_RX_0 register  ****************/
#define USB_COUNT7_RX_0_COUNT7_RX_0             0x000003FFU                    /*!< Reception Byte Count (low) */

#define USB_COUNT7_RX_0_NUM_BLOCK_0             0x00007C00U                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_0           0x00000400U                    /*!< Bit 0 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_1           0x00000800U                    /*!< Bit 1 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_2           0x00001000U                    /*!< Bit 2 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_3           0x00002000U                    /*!< Bit 3 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_4           0x00004000U                    /*!< Bit 4 */

#define USB_COUNT7_RX_0_BLSIZE_0                0x00008000U                    /*!< BLock SIZE (low) */

/***************  Bit definition for USB_COUNT7_RX_1 register  ****************/
#define USB_COUNT7_RX_1_COUNT7_RX_1             0x03FF0000U                    /*!< Reception Byte Count (high) */

#define USB_COUNT7_RX_1_NUM_BLOCK_1             0x7C000000U                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_0           0x04000000U                    /*!< Bit 0 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_1           0x08000000U                    /*!< Bit 1 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_2           0x10000000U                    /*!< Bit 2 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_3           0x20000000U                    /*!< Bit 3 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_4           0x40000000U                    /*!< Bit 4 */

#define USB_COUNT7_RX_1_BLSIZE_1                0x80000000U                    /*!< BLock SIZE (high) */

/******************************************************************************/
/*                                                                            */
/*                                 Debug MCU                                  */
/*                                                                            */
/******************************************************************************/

/****************  Bit definition for DBGMCU_IDCODE register  *****************/
#define DBGMCU_IDCODE_DEV_ID_Pos            (0U)                               
#define DBGMCU_IDCODE_DEV_ID_Msk            (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos) /*!< 0x00000FFF */
#define DBGMCU_IDCODE_DEV_ID                DBGMCU_IDCODE_DEV_ID_Msk           /*!< Device Identifier */

#define DBGMCU_IDCODE_REV_ID_Pos            (16U)                              
#define DBGMCU_IDCODE_REV_ID_Msk            (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0xFFFF0000 */
#define DBGMCU_IDCODE_REV_ID                DBGMCU_IDCODE_REV_ID_Msk           /*!< REV_ID[15:0] bits (Revision Identifier) */
#define DBGMCU_IDCODE_REV_ID_0              (0x0001UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00010000 */
#define DBGMCU_IDCODE_REV_ID_1              (0x0002UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00020000 */
#define DBGMCU_IDCODE_REV_ID_2              (0x0004UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00040000 */
#define DBGMCU_IDCODE_REV_ID_3              (0x0008UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00080000 */
#define DBGMCU_IDCODE_REV_ID_4              (0x0010UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00100000 */
#define DBGMCU_IDCODE_REV_ID_5              (0x0020UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00200000 */
#define DBGMCU_IDCODE_REV_ID_6              (0x0040UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00400000 */
#define DBGMCU_IDCODE_REV_ID_7              (0x0080UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00800000 */
#define DBGMCU_IDCODE_REV_ID_8              (0x0100UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x01000000 */
#define DBGMCU_IDCODE_REV_ID_9              (0x0200UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x02000000 */
#define DBGMCU_IDCODE_REV_ID_10             (0x0400UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x04000000 */
#define DBGMCU_IDCODE_REV_ID_11             (0x0800UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x08000000 */
#define DBGMCU_IDCODE_REV_ID_12             (0x1000UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x10000000 */
#define DBGMCU_IDCODE_REV_ID_13             (0x2000UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x20000000 */
#define DBGMCU_IDCODE_REV_ID_14             (0x4000UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x40000000 */
#define DBGMCU_IDCODE_REV_ID_15             (0x8000UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x80000000 */

/******************  Bit definition for DBGMCU_CR register  *******************/
#define DBGMCU_CR_DBG_SLEEP_Pos             (0U)                               
#define DBGMCU_CR_DBG_SLEEP_Msk             (0x1UL << DBGMCU_CR_DBG_SLEEP_Pos)  /*!< 0x00000001 */
#define DBGMCU_CR_DBG_SLEEP                 DBGMCU_CR_DBG_SLEEP_Msk            /*!< Debug Sleep Mode */
#define DBGMCU_CR_DBG_STOP_Pos              (1U)                               
#define DBGMCU_CR_DBG_STOP_Msk              (0x1UL << DBGMCU_CR_DBG_STOP_Pos)   /*!< 0x00000002 */
#define DBGMCU_CR_DBG_STOP                  DBGMCU_CR_DBG_STOP_Msk             /*!< Debug Stop Mode */
#define DBGMCU_CR_DBG_STANDBY_Pos           (2U)                               
#define DBGMCU_CR_DBG_STANDBY_Msk           (0x1UL << DBGMCU_CR_DBG_STANDBY_Pos) /*!< 0x00000004 */
#define DBGMCU_CR_DBG_STANDBY               DBGMCU_CR_DBG_STANDBY_Msk          /*!< Debug Standby mode */
#define DBGMCU_CR_TRACE_IOEN_Pos            (5U)                               
#define DBGMCU_CR_TRACE_IOEN_Msk            (0x1UL << DBGMCU_CR_TRACE_IOEN_Pos) /*!< 0x00000020 */
#define DBGMCU_CR_TRACE_IOEN                DBGMCU_CR_TRACE_IOEN_Msk           /*!< Trace Pin Assignment Control */

#define DBGMCU_CR_TRACE_MODE_Pos            (6U)                               
#define DBGMCU_CR_TRACE_MODE_Msk            (0x3UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x000000C0 */
#define DBGMCU_CR_TRACE_MODE                DBGMCU_CR_TRACE_MODE_Msk           /*!< TRACE_MODE[1:0] bits (Trace Pin Assignment Control) */
#define DBGMCU_CR_TRACE_MODE_0              (0x1UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x00000040 */
#define DBGMCU_CR_TRACE_MODE_1              (0x2UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x00000080 */

#define DBGMCU_CR_DBG_IWDG_STOP_Pos         (8U)                               
#define DBGMCU_CR_DBG_IWDG_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_IWDG_STOP_Pos) /*!< 0x00000100 */
#define DBGMCU_CR_DBG_IWDG_STOP             DBGMCU_CR_DBG_IWDG_STOP_Msk        /*!< Debug Independent Watchdog stopped when Core is halted */
#define DBGMCU_CR_DBG_WWDG_STOP_Pos         (9U)                               
#define DBGMCU_CR_DBG_WWDG_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_WWDG_STOP_Pos) /*!< 0x00000200 */
#define DBGMCU_CR_DBG_WWDG_STOP             DBGMCU_CR_DBG_WWDG_STOP_Msk        /*!< Debug Window Watchdog stopped when Core is halted */
#define DBGMCU_CR_DBG_TIM1_STOP_Pos         (10U)                              
#define DBGMCU_CR_DBG_TIM1_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM1_STOP_Pos) /*!< 0x00000400 */
#define DBGMCU_CR_DBG_TIM1_STOP             DBGMCU_CR_DBG_TIM1_STOP_Msk        /*!< TIM1 counter stopped when core is halted */
#define DBGMCU_CR_DBG_TIM2_STOP_Pos         (11U)                              
#define DBGMCU_CR_DBG_TIM2_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM2_STOP_Pos) /*!< 0x00000800 */
#define DBGMCU_CR_DBG_TIM2_STOP             DBGMCU_CR_DBG_TIM2_STOP_Msk        /*!< TIM2 counter stopped when core is halted */
#define DBGMCU_CR_DBG_TIM3_STOP_Pos         (12U)                              
#define DBGMCU_CR_DBG_TIM3_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM3_STOP_Pos) /*!< 0x00001000 */
#define DBGMCU_CR_DBG_TIM3_STOP             DBGMCU_CR_DBG_TIM3_STOP_Msk        /*!< TIM3 counter stopped when core is halted */
#define DBGMCU_CR_DBG_TIM4_STOP_Pos         (13U)                              
#define DBGMCU_CR_DBG_TIM4_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM4_STOP_Pos) /*!< 0x00002000 */
#define DBGMCU_CR_DBG_TIM4_STOP             DBGMCU_CR_DBG_TIM4_STOP_Msk        /*!< TIM4 counter stopped when core is halted */
#define DBGMCU_CR_DBG_CAN1_STOP_Pos         (14U)                              
#define DBGMCU_CR_DBG_CAN1_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_CAN1_STOP_Pos) /*!< 0x00004000 */
#define DBGMCU_CR_DBG_CAN1_STOP             DBGMCU_CR_DBG_CAN1_STOP_Msk        /*!< Debug CAN1 stopped when Core is halted */
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Pos (15U)                             
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Msk (0x1UL << DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Pos) /*!< 0x00008000 */
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT    DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Msk /*!< SMBUS timeout mode stopped when Core is halted */
#define DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT_Pos (16U)                             
#define DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT_Msk (0x1UL << DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT_Pos) /*!< 0x00010000 */
#define DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT    DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT_Msk /*!< SMBUS timeout mode stopped when Core is halted */
#define DBGMCU_CR_DBG_TIM8_STOP_Pos         (17U)                              
#define DBGMCU_CR_DBG_TIM8_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM8_STOP_Pos) /*!< 0x00020000 */
#define DBGMCU_CR_DBG_TIM8_STOP             DBGMCU_CR_DBG_TIM8_STOP_Msk        /*!< TIM8 counter stopped when core is halted */
#define DBGMCU_CR_DBG_TIM5_STOP_Pos         (18U)                              
#define DBGMCU_CR_DBG_TIM5_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM5_STOP_Pos) /*!< 0x00040000 */
#define DBGMCU_CR_DBG_TIM5_STOP             DBGMCU_CR_DBG_TIM5_STOP_Msk        /*!< TIM5 counter stopped when core is halted */
#define DBGMCU_CR_DBG_TIM6_STOP_Pos         (19U)                              
#define DBGMCU_CR_DBG_TIM6_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM6_STOP_Pos) /*!< 0x00080000 */
#define DBGMCU_CR_DBG_TIM6_STOP             DBGMCU_CR_DBG_TIM6_STOP_Msk        /*!< TIM6 counter stopped when core is halted */
#define DBGMCU_CR_DBG_TIM7_STOP_Pos         (20U)                              
#define DBGMCU_CR_DBG_TIM7_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM7_STOP_Pos) /*!< 0x00100000 */
#define DBGMCU_CR_DBG_TIM7_STOP             DBGMCU_CR_DBG_TIM7_STOP_Msk        /*!< TIM7 counter stopped when core is halted */
#define DBGMCU_CR_DBG_TIM12_STOP_Pos        (25U)                              
#define DBGMCU_CR_DBG_TIM12_STOP_Msk        (0x1UL << DBGMCU_CR_DBG_TIM12_STOP_Pos) /*!< 0x02000000 */
#define DBGMCU_CR_DBG_TIM12_STOP            DBGMCU_CR_DBG_TIM12_STOP_Msk       /*!< Debug TIM12 stopped when Core is halted */
#define DBGMCU_CR_DBG_TIM13_STOP_Pos        (26U)                              
#define DBGMCU_CR_DBG_TIM13_STOP_Msk        (0x1UL << DBGMCU_CR_DBG_TIM13_STOP_Pos) /*!< 0x04000000 */
#define DBGMCU_CR_DBG_TIM13_STOP            DBGMCU_CR_DBG_TIM13_STOP_Msk       /*!< Debug TIM13 stopped when Core is halted */
#define DBGMCU_CR_DBG_TIM14_STOP_Pos        (27U)                              
#define DBGMCU_CR_DBG_TIM14_STOP_Msk        (0x1UL << DBGMCU_CR_DBG_TIM14_STOP_Pos) /*!< 0x08000000 */
#define DBGMCU_CR_DBG_TIM14_STOP            DBGMCU_CR_DBG_TIM14_STOP_Msk       /*!< Debug TIM14 stopped when Core is halted */
#define DBGMCU_CR_DBG_TIM9_STOP_Pos         (28U)                              
#define DBGMCU_CR_DBG_TIM9_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM9_STOP_Pos) /*!< 0x10000000 */
#define DBGMCU_CR_DBG_TIM9_STOP             DBGMCU_CR_DBG_TIM9_STOP_Msk        /*!< Debug TIM9 stopped when Core is halted */
#define DBGMCU_CR_DBG_TIM10_STOP_Pos        (29U)                              
#define DBGMCU_CR_DBG_TIM10_STOP_Msk        (0x1UL << DBGMCU_CR_DBG_TIM10_STOP_Pos) /*!< 0x20000000 */
#define DBGMCU_CR_DBG_TIM10_STOP            DBGMCU_CR_DBG_TIM10_STOP_Msk       /*!< Debug TIM10 stopped when Core is halted */
#define DBGMCU_CR_DBG_TIM11_STOP_Pos        (30U)                              
#define DBGMCU_CR_DBG_TIM11_STOP_Msk        (0x1UL << DBGMCU_CR_DBG_TIM11_STOP_Pos) /*!< 0x40000000 */
#define DBGMCU_CR_DBG_TIM11_STOP            DBGMCU_CR_DBG_TIM11_STOP_Msk       /*!< Debug TIM11 stopped when Core is halted */




/**
  * @}
*/

/**
  * @}
*/ 

/** @addtogroup Exported_macro
  * @{
  */

/****************************** ADC Instances *********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) (((INSTANCE) == ADC1) || \
                                       ((INSTANCE) == ADC2) || \
                                       ((INSTANCE) == ADC3))
                                       
#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC12_COMMON)

#define IS_ADC_DMA_CAPABILITY_INSTANCE(INSTANCE) (((INSTANCE) == ADC1) || \
                                                  ((INSTANCE) == ADC3))

/****************************** CAN Instances *********************************/    
#define IS_CAN_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CAN1)

/****************************** CRC Instances *********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/****************************** DAC Instances *********************************/
#define IS_DAC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DAC1)

/****************************** DMA Instances *********************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Channel1) || \
                                       ((INSTANCE) == DMA1_Channel2) || \
                                       ((INSTANCE) == DMA1_Channel3) || \
                                       ((INSTANCE) == DMA1_Channel4) || \
                                       ((INSTANCE) == DMA1_Channel5) || \
                                       ((INSTANCE) == DMA1_Channel6) || \
                                       ((INSTANCE) == DMA1_Channel7) || \
                                       ((INSTANCE) == DMA2_Channel1) || \
                                       ((INSTANCE) == DMA2_Channel2) || \
                                       ((INSTANCE) == DMA2_Channel3) || \
                                       ((INSTANCE) == DMA2_Channel4) || \
                                       ((INSTANCE) == DMA2_Channel5))
  
/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOD) || \
                                        ((INSTANCE) == GPIOE) || \
                                        ((INSTANCE) == GPIOF) || \
                                        ((INSTANCE) == GPIOG))

/**************************** GPIO Alternate Function Instances ***************/
#define IS_GPIO_AF_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** GPIO Lock Instances *****************************/
#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2C1) || \
                                       ((INSTANCE) == I2C2))

/******************************* SMBUS Instances ******************************/
#define IS_SMBUS_ALL_INSTANCE         IS_I2C_ALL_INSTANCE

/******************************** I2S Instances *******************************/
#define IS_I2S_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI2) || \
                                       ((INSTANCE) == SPI3))

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

/****************************** SDIO Instances *********************************/
#define IS_SDIO_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SDIO)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2) || \
                                       ((INSTANCE) == SPI3))

/****************************** START TIM Instances ***************************/
/****************************** TIM Instances *********************************/
#define IS_TIM_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7)    || \
   ((INSTANCE) == TIM9)    || \
   ((INSTANCE) == TIM10)   || \
   ((INSTANCE) == TIM11)   || \
   ((INSTANCE) == TIM12)   || \
   ((INSTANCE) == TIM13)   || \
   ((INSTANCE) == TIM14))

#define IS_TIM_ADVANCED_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))

#define IS_TIM_CC1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM9)    || \
   ((INSTANCE) == TIM10)   || \
   ((INSTANCE) == TIM11)   || \
   ((INSTANCE) == TIM12)   || \
   ((INSTANCE) == TIM13)   || \
   ((INSTANCE) == TIM14))

#define IS_TIM_CC2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM9)    || \
   ((INSTANCE) == TIM12))

#define IS_TIM_CC3_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_CC4_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM9)    || \
   ((INSTANCE) == TIM12))

#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM9)    || \
   ((INSTANCE) == TIM12))

#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_XOR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_MASTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7)    || \
   ((INSTANCE) == TIM12))

#define IS_TIM_SLAVE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM9)    || \
   ((INSTANCE) == TIM12))

#define IS_TIM_DMABURST_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_BREAK_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))

#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == TIM1) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM8) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM2) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM3) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM4) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM5) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM9) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2)))           \
    ||                                         \
    (((INSTANCE) == TIM10) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TIM11) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TIM12) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2)))           \
    ||                                         \
    (((INSTANCE) == TIM13) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TIM14) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1))))

#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == TIM1) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))            \
    ||                                          \
    (((INSTANCE) == TIM8) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3))))

#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))

#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))

#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM9)    || \
   ((INSTANCE) == TIM10)   || \
   ((INSTANCE) == TIM11)   || \
   ((INSTANCE) == TIM12)   || \
   ((INSTANCE) == TIM13)   || \
   ((INSTANCE) == TIM14))

#define IS_TIM_DMA_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7))
    
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM5))
    
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))

#define IS_TIM_ETR_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1)    || \
                                        ((INSTANCE) == TIM2)    || \
                                        ((INSTANCE) == TIM3)    || \
                                        ((INSTANCE) == TIM4)    || \
                                        ((INSTANCE) == TIM5)    || \
                                        ((INSTANCE) == TIM8))

#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)    || \
                                                         ((INSTANCE) == TIM2)    || \
                                                         ((INSTANCE) == TIM3)    || \
                                                         ((INSTANCE) == TIM4)    || \
                                                         ((INSTANCE) == TIM5)    || \
                                                         ((INSTANCE) == TIM8))

#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE)           0U

/****************************** END TIM Instances *****************************/


/******************** USART Instances : Synchronous mode **********************/                                           
#define IS_USART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2) || \
                                     ((INSTANCE) == USART3))

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) || \
                                    ((INSTANCE) == USART3) || \
                                    ((INSTANCE) == UART4)  || \
                                    ((INSTANCE) == UART5))

/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                               ((INSTANCE) == USART2) || \
                                               ((INSTANCE) == USART3) || \
                                               ((INSTANCE) == UART4)  || \
                                               ((INSTANCE) == UART5))

/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2) || \
                                        ((INSTANCE) == USART3) || \
                                        ((INSTANCE) == UART4)  || \
                                        ((INSTANCE) == UART5))

/****************** UART Instances : Hardware Flow control ********************/                                    
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2) || \
                                           ((INSTANCE) == USART3))

/********************* UART Instances : Smard card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2) || \
                                         ((INSTANCE) == USART3))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) || \
                                    ((INSTANCE) == USART3) || \
                                    ((INSTANCE) == UART4)  || \
                                    ((INSTANCE) == UART5))

/***************** UART Instances : Multi-Processor mode **********************/
#define IS_UART_MULTIPROCESSOR_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                   ((INSTANCE) == USART2) || \
                                                   ((INSTANCE) == USART3) || \
                                                   ((INSTANCE) == UART4)  || \
                                                   ((INSTANCE) == UART5))

/***************** UART Instances : DMA mode available **********************/
#define IS_UART_DMA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2) || \
                                        ((INSTANCE) == USART3) || \
                                        ((INSTANCE) == UART4))

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

/**************************** WWDG Instances *****************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG)

/****************************** USB Instances ********************************/
#define IS_PCD_ALL_INSTANCE(INSTANCE)   ((INSTANCE) == USB)



#define RCC_HSE_MIN         4000000U
#define RCC_HSE_MAX        16000000U

#define RCC_MAX_FREQUENCY  72000000U

/**
  * @}
  */ 
/******************************************************************************/
/*  For a painless codes migration between the STM32F1xx device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */ 
/*  product lines within the same STM32F1 Family                              */
/******************************************************************************/

/* Aliases for __IRQn */
#define ADC1_IRQn               ADC1_2_IRQn
#define DMA2_Channel4_IRQn      DMA2_Channel4_5_IRQn
#define TIM9_IRQn               TIM1_BRK_TIM9_IRQn
#define TIM1_BRK_IRQn           TIM1_BRK_TIM9_IRQn
#define TIM1_BRK_TIM15_IRQn     TIM1_BRK_TIM9_IRQn
#define TIM1_TRG_COM_TIM17_IRQn TIM1_TRG_COM_TIM11_IRQn
#define TIM1_TRG_COM_IRQn       TIM1_TRG_COM_TIM11_IRQn
#define TIM11_IRQn              TIM1_TRG_COM_TIM11_IRQn
#define TIM10_IRQn              TIM1_UP_TIM10_IRQn
#define TIM1_UP_IRQn            TIM1_UP_TIM10_IRQn
#define TIM1_UP_TIM16_IRQn      TIM1_UP_TIM10_IRQn
#define TIM6_DAC_IRQn           TIM6_IRQn
#define TIM12_IRQn              TIM8_BRK_TIM12_IRQn
#define TIM8_BRK_IRQn           TIM8_BRK_TIM12_IRQn
#define TIM14_IRQn              TIM8_TRG_COM_TIM14_IRQn
#define TIM8_TRG_COM_IRQn       TIM8_TRG_COM_TIM14_IRQn
#define TIM13_IRQn              TIM8_UP_TIM13_IRQn
#define TIM8_UP_IRQn            TIM8_UP_TIM13_IRQn
#define CEC_IRQn                USBWakeUp_IRQn
#define OTG_FS_WKUP_IRQn        USBWakeUp_IRQn
#define CAN1_TX_IRQn            USB_HP_CAN1_TX_IRQn
#define USB_HP_IRQn             USB_HP_CAN1_TX_IRQn
#define CAN1_RX0_IRQn           USB_LP_CAN1_RX0_IRQn
#define USB_LP_IRQn             USB_LP_CAN1_RX0_IRQn


/* Aliases for __IRQHandler */
#define ADC1_IRQHandler               ADC1_2_IRQHandler
#define DMA2_Channel4_IRQHandler      DMA2_Channel4_5_IRQHandler
#define TIM9_IRQHandler               TIM1_BRK_TIM9_IRQHandler
#define TIM1_BRK_IRQHandler           TIM1_BRK_TIM9_IRQHandler
#define TIM1_BRK_TIM15_IRQHandler     TIM1_BRK_TIM9_IRQHandler
#define TIM1_TRG_COM_TIM17_IRQHandler TIM1_TRG_COM_TIM11_IRQHandler
#define TIM1_TRG_COM_IRQHandler       TIM1_TRG_COM_TIM11_IRQHandler
#define TIM11_IRQHandler              TIM1_TRG_COM_TIM11_IRQHandler
#define TIM10_IRQHandler              TIM1_UP_TIM10_IRQHandler
#define TIM1_UP_IRQHandler            TIM1_UP_TIM10_IRQHandler
#define TIM1_UP_TIM16_IRQHandler      TIM1_UP_TIM10_IRQHandler
#define TIM6_DAC_IRQHandler           TIM6_IRQHandler
#define TIM12_IRQHandler              TIM8_BRK_TIM12_IRQHandler
#define TIM8_BRK_IRQHandler           TIM8_BRK_TIM12_IRQHandler
#define TIM14_IRQHandler              TIM8_TRG_COM_TIM14_IRQHandler
#define TIM8_TRG_COM_IRQHandler       TIM8_TRG_COM_TIM14_IRQHandler
#define TIM13_IRQHandler              TIM8_UP_TIM13_IRQHandler
#define TIM8_UP_IRQHandler            TIM8_UP_TIM13_IRQHandler
#define CEC_IRQHandler                USBWakeUp_IRQHandler
#define OTG_FS_WKUP_IRQHandler        USBWakeUp_IRQHandler
#define CAN1_TX_IRQHandler            USB_HP_CAN1_TX_IRQHandler
#define USB_HP_IRQHandler             USB_HP_CAN1_TX_IRQHandler
#define CAN1_RX0_IRQHandler           USB_LP_CAN1_RX0_IRQHandler
#define USB_LP_IRQHandler             USB_LP_CAN1_RX0_IRQHandler


/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
  }
#endif /* __cplusplus */
  
#endif /* __STM32F103xG_H */
  
  
  
  /************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
