/**
  ******************************************************************************
  * @file    stm32l152xe.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral register's definitions, bits 
  *          definitions and memory mapping for STM32L1xx devices.            
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

/** @addtogroup stm32l152xe
  * @{
  */
    
#ifndef __STM32L152xE_H
#define __STM32L152xE_H

#ifdef __cplusplus
 extern "C" {
#endif 
  

  /** @addtogroup Configuration_section_for_CMSIS
  * @{
  */
/**
  * @brief Configuration of the Cortex-M3 Processor and Core Peripherals 
 */
#define __CM3_REV                 0x200U /*!< Cortex-M3 Revision r2p0                  */
#define __MPU_PRESENT             1U     /*!< STM32L1xx provides MPU                          */
#define __NVIC_PRIO_BITS          4U     /*!< STM32L1xx uses 4 Bits for the Priority Levels    */
#define __Vendor_SysTickConfig    0U     /*!< Set to 1 if different SysTick Config is used */
 
/**
  * @}
  */
   
/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief STM32L1xx Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */

 /*!< Interrupt Number Definition */
typedef enum
{
/******  Cortex-M3 Processor Exceptions Numbers ******************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                        */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt                 */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                         */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                       */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                          */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                    */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                          */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                      */

/******  STM32L specific Interrupt Numbers ***********************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt               */
  TAMPER_STAMP_IRQn           = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line   */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup Timer through EXTI Line Interrupt            */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                  */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                    */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                    */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                    */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                    */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                    */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                    */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                         */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                         */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                         */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                         */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                         */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                         */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                         */
  ADC1_IRQn                   = 18,     /*!< ADC1 global Interrupt                                   */
  USB_HP_IRQn                 = 19,     /*!< USB High Priority Interrupt                             */
  USB_LP_IRQn                 = 20,     /*!< USB Low Priority Interrupt                              */
  DAC_IRQn                    = 21,     /*!< DAC Interrupt                                           */
  COMP_IRQn                   = 22,     /*!< Comparator through EXTI Line Interrupt                  */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                           */
  LCD_IRQn                    = 24,     /*!< LCD Interrupt                                           */
  TIM9_IRQn                   = 25,     /*!< TIM9 global Interrupt                                   */
  TIM10_IRQn                  = 26,     /*!< TIM10 global Interrupt                                  */
  TIM11_IRQn                  = 27,     /*!< TIM11 global Interrupt                                  */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                   */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                   */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                   */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                    */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                    */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                    */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                    */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                   */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                   */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                 */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                 */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                 */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                         */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm through EXTI Line Interrupt                   */
  USB_FS_WKUP_IRQn            = 42,     /*!< USB FS WakeUp from suspend through EXTI Line Interrupt  */
  TIM6_IRQn                   = 43,     /*!< TIM6 global Interrupt                                   */
  TIM7_IRQn                   = 44,     /*!< TIM7 global Interrupt                                   */
  TIM5_IRQn                   = 46,     /*!< TIM5 global Interrupt                                   */
  SPI3_IRQn                   = 47,     /*!< SPI3 global Interrupt                                   */
  UART4_IRQn                  = 48,     /*!< UART4 global Interrupt                                  */
  UART5_IRQn                  = 49,     /*!< UART5 global Interrupt                                  */
  DMA2_Channel1_IRQn          = 50,     /*!< DMA2 Channel 1 global Interrupt                         */
  DMA2_Channel2_IRQn          = 51,     /*!< DMA2 Channel 2 global Interrupt                         */
  DMA2_Channel3_IRQn          = 52,     /*!< DMA2 Channel 3 global Interrupt                         */
  DMA2_Channel4_IRQn          = 53,     /*!< DMA2 Channel 4 global Interrupt                         */
  DMA2_Channel5_IRQn          = 54,     /*!< DMA2 Channel 5 global Interrupt                         */
  COMP_ACQ_IRQn               = 56      /*!< Comparator Channel Acquisition global Interrupt         */
} IRQn_Type;

/**
  * @}
  */

#include "../../cmsis/core_cm3.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Analog to Digital Converter
  */

typedef struct
{
  __IO uint32_t SR;           /*!< ADC status register,                         Address offset: 0x00 */
  __IO uint32_t CR1;          /*!< ADC control register 1,                      Address offset: 0x04 */
  __IO uint32_t CR2;          /*!< ADC control register 2,                      Address offset: 0x08 */
  __IO uint32_t SMPR1;        /*!< ADC sample time register 1,                  Address offset: 0x0C */
  __IO uint32_t SMPR2;        /*!< ADC sample time register 2,                  Address offset: 0x10 */
  __IO uint32_t SMPR3;        /*!< ADC sample time register 3,                  Address offset: 0x14 */
  __IO uint32_t JOFR1;        /*!< ADC injected channel data offset register 1, Address offset: 0x18 */
  __IO uint32_t JOFR2;        /*!< ADC injected channel data offset register 2, Address offset: 0x1C */
  __IO uint32_t JOFR3;        /*!< ADC injected channel data offset register 3, Address offset: 0x20 */
  __IO uint32_t JOFR4;        /*!< ADC injected channel data offset register 4, Address offset: 0x24 */
  __IO uint32_t HTR;          /*!< ADC watchdog higher threshold register,      Address offset: 0x28 */
  __IO uint32_t LTR;          /*!< ADC watchdog lower threshold register,       Address offset: 0x2C */
  __IO uint32_t SQR1;         /*!< ADC regular sequence register 1,             Address offset: 0x30 */
  __IO uint32_t SQR2;         /*!< ADC regular sequence register 2,             Address offset: 0x34 */
  __IO uint32_t SQR3;         /*!< ADC regular sequence register 3,             Address offset: 0x38 */
  __IO uint32_t SQR4;         /*!< ADC regular sequence register 4,             Address offset: 0x3C */
  __IO uint32_t SQR5;         /*!< ADC regular sequence register 5,             Address offset: 0x40 */
  __IO uint32_t JSQR;         /*!< ADC injected sequence register,              Address offset: 0x44 */
  __IO uint32_t JDR1;         /*!< ADC injected data register 1,                Address offset: 0x48 */
  __IO uint32_t JDR2;         /*!< ADC injected data register 2,                Address offset: 0x4C */
  __IO uint32_t JDR3;         /*!< ADC injected data register 3,                Address offset: 0x50 */
  __IO uint32_t JDR4;         /*!< ADC injected data register 4,                Address offset: 0x54 */
  __IO uint32_t DR;           /*!< ADC regular data register,                   Address offset: 0x58 */
  __IO uint32_t SMPR0;        /*!< ADC sample time register 0,                  Address offset: 0x5C */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSR;          /*!< ADC common status register,                  Address offset: ADC1 base address + 0x300 */
  __IO uint32_t CCR;          /*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
} ADC_Common_TypeDef;

/** 
  * @brief Comparator 
  */

typedef struct
{
  __IO uint32_t CSR;         /*!< COMP control and status register, Address offset: 0x00 */
} COMP_TypeDef;

typedef struct
{
  __IO uint32_t CSR;         /*!< COMP control and status register, used for bits common to several COMP instances, Address offset: 0x00 */
} COMP_Common_TypeDef;

/** 
  * @brief CRC calculation unit
  */

typedef struct
{
  __IO uint32_t DR;           /*!< CRC Data register,                           Address offset: 0x00 */
  __IO uint8_t  IDR;          /*!< CRC Independent data register,               Address offset: 0x04 */
  uint8_t       RESERVED0;    /*!< Reserved,                                    Address offset: 0x05 */
  uint16_t      RESERVED1;    /*!< Reserved,                                    Address offset: 0x06 */ 
  __IO uint32_t CR;           /*!< CRC Control register,                        Address offset: 0x08 */ 
} CRC_TypeDef;

/** 
  * @brief Digital to Analog Converter
  */

typedef struct
{
  __IO uint32_t CR;           /*!< DAC control register,                                     Address offset: 0x00 */
  __IO uint32_t SWTRIGR;      /*!< DAC software trigger register,                            Address offset: 0x04 */
  __IO uint32_t DHR12R1;      /*!< DAC channel1 12-bit right-aligned data holding register,  Address offset: 0x08 */
  __IO uint32_t DHR12L1;      /*!< DAC channel1 12-bit left aligned data holding register,   Address offset: 0x0C */
  __IO uint32_t DHR8R1;       /*!< DAC channel1 8-bit right aligned data holding register,   Address offset: 0x10 */
  __IO uint32_t DHR12R2;      /*!< DAC channel2 12-bit right aligned data holding register,  Address offset: 0x14 */
  __IO uint32_t DHR12L2;      /*!< DAC channel2 12-bit left aligned data holding register,   Address offset: 0x18 */
  __IO uint32_t DHR8R2;       /*!< DAC channel2 8-bit right-aligned data holding register,   Address offset: 0x1C */
  __IO uint32_t DHR12RD;      /*!< Dual DAC 12-bit right-aligned data holding register,      Address offset: 0x20 */
  __IO uint32_t DHR12LD;      /*!< DUAL DAC 12-bit left aligned data holding register,       Address offset: 0x24 */
  __IO uint32_t DHR8RD;       /*!< DUAL DAC 8-bit right aligned data holding register,       Address offset: 0x28 */
  __IO uint32_t DOR1;         /*!< DAC channel1 data output register,                        Address offset: 0x2C */
  __IO uint32_t DOR2;         /*!< DAC channel2 data output register,                        Address offset: 0x30 */
  __IO uint32_t SR;           /*!< DAC status register,                                      Address offset: 0x34 */
} DAC_TypeDef;

/** 
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;       /*!< MCU device ID code,                          Address offset: 0x00 */
  __IO uint32_t CR;           /*!< Debug MCU configuration register,            Address offset: 0x04 */
  __IO uint32_t APB1FZ;       /*!< Debug MCU APB1 freeze register,              Address offset: 0x08 */
  __IO uint32_t APB2FZ;       /*!< Debug MCU APB2 freeze register,              Address offset: 0x0C */
}DBGMCU_TypeDef;

/** 
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CCR;          /*!< DMA channel x configuration register        */
  __IO uint32_t CNDTR;        /*!< DMA channel x number of data register       */
  __IO uint32_t CPAR;         /*!< DMA channel x peripheral address register   */
  __IO uint32_t CMAR;         /*!< DMA channel x memory address register       */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;          /*!< DMA interrupt status register,               Address offset: 0x00 */
  __IO uint32_t IFCR;         /*!< DMA interrupt flag clear register,           Address offset: 0x04 */
} DMA_TypeDef;

/** 
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t IMR;          /*!<EXTI Interrupt mask register,                 Address offset: 0x00 */
  __IO uint32_t EMR;          /*!<EXTI Event mask register,                     Address offset: 0x04 */
  __IO uint32_t RTSR;         /*!<EXTI Rising trigger selection register ,      Address offset: 0x08 */
  __IO uint32_t FTSR;         /*!<EXTI Falling trigger selection register,      Address offset: 0x0C */
  __IO uint32_t SWIER;        /*!<EXTI Software interrupt event register,       Address offset: 0x10 */
  __IO uint32_t PR;           /*!<EXTI Pending register,                        Address offset: 0x14 */
} EXTI_TypeDef;

/** 
  * @brief Option Bytes Registers
  */
typedef struct
{
  __IO uint32_t RDP;              /*!< Read protection register,               Address offset: 0x00 */
  __IO uint32_t USER;             /*!< user register,                          Address offset: 0x04 */
  __IO uint32_t WRP01;            /*!< write protection register 0 1,          Address offset: 0x08 */
  __IO uint32_t WRP23;            /*!< write protection register 2 3,          Address offset: 0x0C */
  __IO uint32_t WRP45;            /*!< write protection register 4 5,          Address offset: 0x10 */
  __IO uint32_t WRP67;            /*!< write protection register 6 7,          Address offset: 0x14 */
  __IO uint32_t WRP89;            /*!< write protection register 8 9,          Address offset: 0x18 */
  __IO uint32_t WRP1011;          /*!< write protection register 10 11,        Address offset: 0x1C */
  uint32_t   RESERVED[24];        /*!< Reserved,                                    0x20 -> 0x7C    */
  __IO uint32_t WRP1213;          /*!< write protection register 12 13,        Address offset: 0x80 */
  __IO uint32_t WRP1415;          /*!< write protection register 14 15,        Address offset: 0x84 */
} OB_TypeDef;

/** 
  * @brief Operational Amplifier (OPAMP)
  */
typedef struct
{
  __IO uint32_t CSR;          /*!< OPAMP control and status register,                 Address offset: 0x00 */
  __IO uint32_t OTR;          /*!< OPAMP offset trimming register for normal mode,    Address offset: 0x04 */ 
  __IO uint32_t LPOTR;        /*!< OPAMP offset trimming register for low power mode, Address offset: 0x08 */
} OPAMP_TypeDef;

typedef struct
{
  __IO uint32_t CSR;          /*!< OPAMP control and status register, used for bits common to several OPAMP instances,              Address offset: 0x00 */
  __IO uint32_t OTR;          /*!< OPAMP offset trimming register for normal mode, used for bits common to several OPAMP instances, Address offset: 0x04 */ 
} OPAMP_Common_TypeDef;

/** 
  * @brief General Purpose IO
  */

typedef struct
{
  __IO uint32_t MODER;        /*!< GPIO port mode register,                     Address offset: 0x00      */
  __IO uint32_t OTYPER;       /*!< GPIO port output type register,              Address offset: 0x04      */
  __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,             Address offset: 0x08      */
  __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,        Address offset: 0x0C      */
  __IO uint32_t IDR;          /*!< GPIO port input data register,               Address offset: 0x10      */
  __IO uint32_t ODR;          /*!< GPIO port output data register,              Address offset: 0x14      */
  __IO uint32_t BSRR;         /*!< GPIO port bit set/reset registerBSRR,        Address offset: 0x18      */
  __IO uint32_t LCKR;         /*!< GPIO port configuration lock register,       Address offset: 0x1C      */
  __IO uint32_t AFR[2];       /*!< GPIO alternate function register,            Address offset: 0x20-0x24 */
  __IO uint32_t BRR;          /*!< GPIO bit reset register,                     Address offset: 0x28      */
} GPIO_TypeDef;

/** 
  * @brief SysTem Configuration
  */

typedef struct
{
  __IO uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  __IO uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  __IO uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
} SYSCFG_TypeDef;

/** 
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;          /*!< I2C Control register 1,                      Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< I2C Control register 2,                      Address offset: 0x04 */
  __IO uint32_t OAR1;         /*!< I2C Own address register 1,                  Address offset: 0x08 */
  __IO uint32_t OAR2;         /*!< I2C Own address register 2,                  Address offset: 0x0C */
  __IO uint32_t DR;           /*!< I2C Data register,                           Address offset: 0x10 */
  __IO uint32_t SR1;          /*!< I2C Status register 1,                       Address offset: 0x14 */
  __IO uint32_t SR2;          /*!< I2C Status register 2,                       Address offset: 0x18 */
  __IO uint32_t CCR;          /*!< I2C Clock control register,                  Address offset: 0x1C */
  __IO uint32_t TRISE;        /*!< I2C TRISE register,                          Address offset: 0x20 */
} I2C_TypeDef;

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
  * @brief LCD
  */

typedef struct
{
  __IO uint32_t CR;        /*!< LCD control register,                           Address offset: 0x00 */
  __IO uint32_t FCR;       /*!< LCD frame control register,                     Address offset: 0x04 */
  __IO uint32_t SR;        /*!< LCD status register,                            Address offset: 0x08 */
  __IO uint32_t CLR;       /*!< LCD clear register,                             Address offset: 0x0C */
  uint32_t RESERVED;       /*!< Reserved,                                       Address offset: 0x10 */
  __IO uint32_t RAM[16];   /*!< LCD display memory,                             Address offset: 0x14-0x50 */
} LCD_TypeDef;


/** 
  * @brief Routing Interface 
  */

typedef struct
{
  __IO uint32_t ICR;        /*!< RI input capture register,                     Address offset: 0x00 */
  __IO uint32_t ASCR1;      /*!< RI analog switches control register,           Address offset: 0x04 */
  __IO uint32_t ASCR2;      /*!< RI analog switch control register 2,           Address offset: 0x08 */
  __IO uint32_t HYSCR1;     /*!< RI hysteresis control register,                Address offset: 0x0C */
  __IO uint32_t HYSCR2;     /*!< RI Hysteresis control register,                Address offset: 0x10 */
  __IO uint32_t HYSCR3;     /*!< RI Hysteresis control register,                Address offset: 0x14 */
  __IO uint32_t HYSCR4;     /*!< RI Hysteresis control register,                Address offset: 0x18 */
  __IO uint32_t ASMR1;      /*!< RI Analog switch mode register 1,              Address offset: 0x1C */
  __IO uint32_t CMR1;       /*!< RI Channel mask register 1,                    Address offset: 0x20 */
  __IO uint32_t CICR1;      /*!< RI Channel Iden for capture register 1,        Address offset: 0x24 */
  __IO uint32_t ASMR2;      /*!< RI Analog switch mode register 2,              Address offset: 0x28 */
  __IO uint32_t CMR2;       /*!< RI Channel mask register 2,                    Address offset: 0x2C */
  __IO uint32_t CICR2;      /*!< RI Channel Iden for capture register 2,        Address offset: 0x30 */
  __IO uint32_t ASMR3;      /*!< RI Analog switch mode register 3,              Address offset: 0x34 */
  __IO uint32_t CMR3;       /*!< RI Channel mask register 3,                    Address offset: 0x38 */
  __IO uint32_t CICR3;      /*!< RI Channel Iden for capture register 3,        Address offset: 0x3C */
  __IO uint32_t ASMR4;      /*!< RI Analog switch mode register 4,              Address offset: 0x40 */
  __IO uint32_t CMR4;       /*!< RI Channel mask register 4,                    Address offset: 0x44 */
  __IO uint32_t CICR4;      /*!< RI Channel Iden for capture register 4,        Address offset: 0x48 */
  __IO uint32_t ASMR5;      /*!< RI Analog switch mode register 5,              Address offset: 0x4C */
  __IO uint32_t CMR5;       /*!< RI Channel mask register 5,                    Address offset: 0x50 */
  __IO uint32_t CICR5;      /*!< RI Channel Iden for capture register 5,        Address offset: 0x54 */
} RI_TypeDef;

/** 
  * @brief Real-Time Clock
  */
typedef struct
{
  __IO uint32_t TR;         /*!< RTC time register,                                         Address offset: 0x00 */
  __IO uint32_t DR;         /*!< RTC date register,                                         Address offset: 0x04 */
  __IO uint32_t CR;         /*!< RTC control register,                                      Address offset: 0x08 */                                                                                            
  __IO uint32_t ISR;        /*!< RTC initialization and status register,                    Address offset: 0x0C */
  __IO uint32_t PRER;       /*!< RTC prescaler register,                                    Address offset: 0x10 */
  __IO uint32_t WUTR;       /*!< RTC wakeup timer register,                                 Address offset: 0x14 */
  __IO uint32_t CALIBR;     /*!< RTC calibration register,                                  Address offset: 0x18 */
  __IO uint32_t ALRMAR;     /*!< RTC alarm A register,                                      Address offset: 0x1C */
  __IO uint32_t ALRMBR;     /*!< RTC alarm B register,                                      Address offset: 0x20 */
  __IO uint32_t WPR;        /*!< RTC write protection register,                             Address offset: 0x24 */
  __IO uint32_t SSR;        /*!< RTC sub second register,                                   Address offset: 0x28 */
  __IO uint32_t SHIFTR;     /*!< RTC shift control register,                                Address offset: 0x2C */
  __IO uint32_t TSTR;       /*!< RTC time stamp time register,                              Address offset: 0x30 */
  __IO uint32_t TSDR;       /*!< RTC time stamp date register,                              Address offset: 0x34 */
  __IO uint32_t TSSSR;      /*!< RTC time-stamp sub second register,                        Address offset: 0x38 */
  __IO uint32_t CALR;       /*!< RRTC calibration register,                                 Address offset: 0x3C */
  __IO uint32_t TAFCR;      /*!< RTC tamper and alternate function configuration register,  Address offset: 0x40 */
  __IO uint32_t ALRMASSR;   /*!< RTC alarm A sub second register,                           Address offset: 0x44 */
  __IO uint32_t ALRMBSSR;   /*!< RTC alarm B sub second register,                           Address offset: 0x48 */
  uint32_t RESERVED7;       /*!< Reserved, 0x4C                                                                  */
  __IO uint32_t BKP0R;      /*!< RTC backup register 0,                                     Address offset: 0x50 */
  __IO uint32_t BKP1R;      /*!< RTC backup register 1,                                     Address offset: 0x54 */
  __IO uint32_t BKP2R;      /*!< RTC backup register 2,                                     Address offset: 0x58 */
  __IO uint32_t BKP3R;      /*!< RTC backup register 3,                                     Address offset: 0x5C */
  __IO uint32_t BKP4R;      /*!< RTC backup register 4,                                     Address offset: 0x60 */
  __IO uint32_t BKP5R;      /*!< RTC backup register 5,                                     Address offset: 0x64 */
  __IO uint32_t BKP6R;      /*!< RTC backup register 6,                                     Address offset: 0x68 */
  __IO uint32_t BKP7R;      /*!< RTC backup register 7,                                     Address offset: 0x6C */
  __IO uint32_t BKP8R;      /*!< RTC backup register 8,                                     Address offset: 0x70 */
  __IO uint32_t BKP9R;      /*!< RTC backup register 9,                                     Address offset: 0x74 */
  __IO uint32_t BKP10R;     /*!< RTC backup register 10,                                    Address offset: 0x78 */
  __IO uint32_t BKP11R;     /*!< RTC backup register 11,                                    Address offset: 0x7C */
  __IO uint32_t BKP12R;     /*!< RTC backup register 12,                                    Address offset: 0x80 */
  __IO uint32_t BKP13R;     /*!< RTC backup register 13,                                    Address offset: 0x84 */
  __IO uint32_t BKP14R;     /*!< RTC backup register 14,                                    Address offset: 0x88 */
  __IO uint32_t BKP15R;     /*!< RTC backup register 15,                                    Address offset: 0x8C */
  __IO uint32_t BKP16R;     /*!< RTC backup register 16,                                    Address offset: 0x90 */
  __IO uint32_t BKP17R;     /*!< RTC backup register 17,                                    Address offset: 0x94 */
  __IO uint32_t BKP18R;     /*!< RTC backup register 18,                                    Address offset: 0x98 */
  __IO uint32_t BKP19R;     /*!< RTC backup register 19,                                    Address offset: 0x9C */
  __IO uint32_t BKP20R;     /*!< RTC backup register 20,                                    Address offset: 0xA0 */
  __IO uint32_t BKP21R;     /*!< RTC backup register 21,                                    Address offset: 0xA4 */
  __IO uint32_t BKP22R;     /*!< RTC backup register 22,                                    Address offset: 0xA8 */
  __IO uint32_t BKP23R;     /*!< RTC backup register 23,                                    Address offset: 0xAC */
  __IO uint32_t BKP24R;     /*!< RTC backup register 24,                                    Address offset: 0xB0 */
  __IO uint32_t BKP25R;     /*!< RTC backup register 25,                                    Address offset: 0xB4 */
  __IO uint32_t BKP26R;     /*!< RTC backup register 26,                                    Address offset: 0xB8 */
  __IO uint32_t BKP27R;     /*!< RTC backup register 27,                                    Address offset: 0xBC */
  __IO uint32_t BKP28R;     /*!< RTC backup register 28,                                    Address offset: 0xC0 */
  __IO uint32_t BKP29R;     /*!< RTC backup register 29,                                    Address offset: 0xC4 */
  __IO uint32_t BKP30R;     /*!< RTC backup register 30,                                    Address offset: 0xC8 */
  __IO uint32_t BKP31R;     /*!< RTC backup register 31,                                    Address offset: 0xCC */
} RTC_TypeDef;

/** 
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR1;        /*!< SPI Control register 1 (not used in I2S mode),      Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< SPI Control register 2,                             Address offset: 0x04 */
  __IO uint32_t SR;         /*!< SPI Status register,                                Address offset: 0x08 */
  __IO uint32_t DR;         /*!< SPI data register,                                  Address offset: 0x0C */
  __IO uint32_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  __IO uint32_t RXCRCR;     /*!< SPI Rx CRC register (not used in I2S mode),         Address offset: 0x14 */
  __IO uint32_t TXCRCR;     /*!< SPI Tx CRC register (not used in I2S mode),         Address offset: 0x18 */
  __IO uint32_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  __IO uint32_t I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
} SPI_TypeDef;

/** 
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
 
typedef struct
{
  __IO uint32_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
  __IO uint32_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
  __IO uint32_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
  __IO uint32_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
  __IO uint32_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
  __IO uint32_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
  __IO uint32_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} USART_TypeDef;

/** 
  * @brief Universal Serial Bus Full Speed Device
  */
  
typedef struct
{
  __IO uint16_t EP0R;            /*!< USB Endpoint 0 register,                Address offset: 0x00 */ 
  __IO uint16_t RESERVED0;       /*!< Reserved */     
  __IO uint16_t EP1R;            /*!< USB Endpoint 1 register,                Address offset: 0x04 */
  __IO uint16_t RESERVED1;       /*!< Reserved */       
  __IO uint16_t EP2R;            /*!< USB Endpoint 2 register,                Address offset: 0x08 */
  __IO uint16_t RESERVED2;       /*!< Reserved */       
  __IO uint16_t EP3R;            /*!< USB Endpoint 3 register,                Address offset: 0x0C */ 
  __IO uint16_t RESERVED3;       /*!< Reserved */       
  __IO uint16_t EP4R;            /*!< USB Endpoint 4 register,                Address offset: 0x10 */
  __IO uint16_t RESERVED4;       /*!< Reserved */       
  __IO uint16_t EP5R;            /*!< USB Endpoint 5 register,                Address offset: 0x14 */
  __IO uint16_t RESERVED5;       /*!< Reserved */       
  __IO uint16_t EP6R;            /*!< USB Endpoint 6 register,                Address offset: 0x18 */
  __IO uint16_t RESERVED6;       /*!< Reserved */       
  __IO uint16_t EP7R;            /*!< USB Endpoint 7 register,                Address offset: 0x1C */
  __IO uint16_t RESERVED7[17];   /*!< Reserved */     
  __IO uint16_t CNTR;            /*!< Control register,                       Address offset: 0x40 */
  __IO uint16_t RESERVED8;       /*!< Reserved */       
  __IO uint16_t ISTR;            /*!< Interrupt status register,              Address offset: 0x44 */
  __IO uint16_t RESERVED9;       /*!< Reserved */       
  __IO uint16_t FNR;             /*!< Frame number register,                  Address offset: 0x48 */
  __IO uint16_t RESERVEDA;       /*!< Reserved */       
  __IO uint16_t DADDR;           /*!< Device address register,                Address offset: 0x4C */
  __IO uint16_t RESERVEDB;       /*!< Reserved */       
  __IO uint16_t BTABLE;          /*!< Buffer Table address register,          Address offset: 0x50 */
  __IO uint16_t RESERVEDC;       /*!< Reserved */       
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
  * @brief Universal Serial Bus Full Speed Device
  */
/** 
  * @}
  */
  
/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE            (0x08000000UL)              /*!< FLASH base address in the alias region */
#define FLASH_EEPROM_BASE     (FLASH_BASE + 0x80000UL)    /*!< FLASH EEPROM base address in the alias region */
#define SRAM_BASE             (0x20000000UL)              /*!< SRAM base address in the alias region */
#define PERIPH_BASE           (0x40000000UL)              /*!< Peripheral base address in the alias region */
#define SRAM_BB_BASE          (0x22000000UL)              /*!< SRAM base address in the bit-band region */
#define PERIPH_BB_BASE        (0x42000000UL)              /*!< Peripheral base address in the bit-band region */
#define FLASH_BANK2_BASE      (0x08040000UL)              /*!< FLASH BANK2 base address in the alias region */
#define FLASH_BANK1_END       (0x0803FFFFUL)              /*!< Program end FLASH BANK1 address  */
#define FLASH_BANK2_END       (0x0807FFFFUL)              /*!< Program end FLASH BANK2 address  */
#define FLASH_END             (0x0807FFFFUL)              /*!< Program end FLASH address for Cat5 */
#define FLASH_EEPROM_END      (0x08083FFFUL)              /*!< FLASH EEPROM end address (16KB) */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)

/*!< APB1 peripherals */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x00000000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x00000400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x00000800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x00000C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x00001000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x00001400UL)
#define LCD_BASE              (APB1PERIPH_BASE + 0x00002400UL)
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

/* USB device FS */
#define USB_BASE              (APB1PERIPH_BASE + 0x00005C00UL) /*!< USB_IP Peripheral Registers base address */
#define USB_PMAADDR           (APB1PERIPH_BASE + 0x00006000UL) /*!< USB_IP Packet Memory Area base address */

/* USB device FS SRAM */
#define PWR_BASE              (APB1PERIPH_BASE + 0x00007000UL)
#define DAC_BASE              (APB1PERIPH_BASE + 0x00007400UL)
#define COMP_BASE             (APB1PERIPH_BASE + 0x00007C00UL)
#define RI_BASE               (APB1PERIPH_BASE + 0x00007C04UL)
#define OPAMP_BASE            (APB1PERIPH_BASE + 0x00007C5CUL)

/*!< APB2 peripherals */
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x00000000UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00000400UL)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x00000800UL)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x00000C00UL)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x00001000UL)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x00002400UL)
#define ADC_BASE              (APB2PERIPH_BASE + 0x00002700UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800UL)

/*!< AHB peripherals */
#define GPIOA_BASE            (AHBPERIPH_BASE + 0x00000000UL)
#define GPIOB_BASE            (AHBPERIPH_BASE + 0x00000400UL)
#define GPIOC_BASE            (AHBPERIPH_BASE + 0x00000800UL)
#define GPIOD_BASE            (AHBPERIPH_BASE + 0x00000C00UL)
#define GPIOE_BASE            (AHBPERIPH_BASE + 0x00001000UL)
#define GPIOH_BASE            (AHBPERIPH_BASE + 0x00001400UL)
#define GPIOF_BASE            (AHBPERIPH_BASE + 0x00001800UL)
#define GPIOG_BASE            (AHBPERIPH_BASE + 0x00001C00UL)
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000UL)
#define RCC_BASE              (AHBPERIPH_BASE + 0x00003800UL)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00003C00UL) /*!< FLASH registers base address */
#define OB_BASE               (0x1FF80000UL)                  /*!< FLASH Option Bytes base address */
#define FLASHSIZE_BASE        (0x1FF800CCUL)                  /*!< FLASH Size register base address for Cat.3, Cat.4, Cat.5 and Cat.6 devices */
#define UID_BASE              (0x1FF800D0UL)                  /*!< Unique device ID register base address for Cat.3, Cat.4, Cat.5 and Cat.6 devices */
#define DMA1_BASE             (AHBPERIPH_BASE + 0x00006000UL)
#define DMA1_Channel1_BASE    (DMA1_BASE + 0x00000008UL)
#define DMA1_Channel2_BASE    (DMA1_BASE + 0x0000001CUL)
#define DMA1_Channel3_BASE    (DMA1_BASE + 0x00000030UL)
#define DMA1_Channel4_BASE    (DMA1_BASE + 0x00000044UL)
#define DMA1_Channel5_BASE    (DMA1_BASE + 0x00000058UL)
#define DMA1_Channel6_BASE    (DMA1_BASE + 0x0000006CUL)
#define DMA1_Channel7_BASE    (DMA1_BASE + 0x00000080UL)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x00006400UL)
#define DMA2_Channel1_BASE    (DMA2_BASE + 0x00000008UL)
#define DMA2_Channel2_BASE    (DMA2_BASE + 0x0000001CUL)
#define DMA2_Channel3_BASE    (DMA2_BASE + 0x00000030UL)
#define DMA2_Channel4_BASE    (DMA2_BASE + 0x00000044UL)
#define DMA2_Channel5_BASE    (DMA2_BASE + 0x00000058UL)
#define DBGMCU_BASE           (0xE0042000UL)     /*!< Debug MCU registers base address */

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */  

#define TIM2                ((volatile uint32_t *) TIM2_BASE)
#define TIM3                ((volatile uint32_t *) TIM3_BASE)
#define TIM4                ((volatile uint32_t *) TIM4_BASE)
#define TIM5                ((volatile uint32_t *) TIM5_BASE)
#define TIM6                ((volatile uint32_t *) TIM6_BASE)
#define TIM7                ((volatile uint32_t *) TIM7_BASE)
#define LCD                 ((LCD_TypeDef *) LCD_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define UART4               ((USART_TypeDef *) UART4_BASE)
#define UART5               ((USART_TypeDef *) UART5_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
/* USB device FS */
#define USB                   ((USB_TypeDef *) USB_BASE)
/* USB device FS SRAM */
#define PWR                 ((volatile uint32_t *) PWR_BASE)

#define DAC1                ((DAC_TypeDef *) DAC_BASE)
/* Legacy define */
#define DAC                 DAC1

#define COMP                ((COMP_TypeDef *) COMP_BASE)                 /* COMP generic instance include bits of COMP1 and COMP2 mixed in the same register */
#define COMP1               ((COMP_TypeDef *) COMP_BASE)                 /* COMP1 instance definition to differentiate COMP1 and COMP2, not to be used to access comparator register */
#define COMP2               ((COMP_TypeDef *) (COMP_BASE + 0x00000001U)) /* COMP2 instance definition to differentiate COMP1 and COMP2, not to be used to access comparator register */
#define COMP12_COMMON       ((COMP_Common_TypeDef *) COMP_BASE)          /* COMP common instance definition to access comparator register bits used by both comparator instances (window mode) */

#define RI                  ((RI_TypeDef *) RI_BASE)

#define OPAMP               ((OPAMP_TypeDef *) OPAMP_BASE)
#define OPAMP1              ((OPAMP_TypeDef *) OPAMP_BASE)
#define OPAMP2              ((OPAMP_TypeDef *) (OPAMP_BASE + 0x00000001U))
#define OPAMP12_COMMON      ((OPAMP_Common_TypeDef *) OPAMP_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define TIM9                ((volatile uint32_t *) TIM9_BASE)
#define TIM10               ((volatile uint32_t *) TIM10_BASE)
#define TIM11               ((volatile uint32_t *) TIM11_BASE)

#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC1_COMMON         ((ADC_Common_TypeDef *) ADC_BASE)
/* Legacy defines */
#define ADC                 ADC1_COMMON

#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define RCC                 ((volatile uint32_t *) RCC_BASE)
#define FLASH               ((volatile uint32_t *) FLASH_R_BASE)
#define OB                  ((OB_TypeDef *) OB_BASE) 
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#define DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
#define DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
#define DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
#define DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
#define DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)

 /**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

  /** @addtogroup Hardware_Constant_Definition
    * @{
    */
#define LSI_STARTUP_TIME 200U /*!< LSI Maximum startup time in us */

  /**
    * @}
    */

/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */
    
/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/
#define VREFINT_CAL_ADDR_CMSIS                    0x1FF800F8      /*!<Internal voltage reference, address of parameter VREFINT_CAL: VrefInt ADC raw data acquired at temperature 30 DegC (tolerance: +-5 DegC), Vref+ = 3.0 V (tolerance: +-10 mV).                      */
#define TEMPSENSOR_CAL1_ADDR_CMSIS                0x1FF800FA      /*!<Internal temperature sensor, address of parameter TS_CAL1: On STM32L1, temperature sensor ADC raw data acquired at temperature  30 DegC (tolerance: +-5 DegC), Vref+ = 3.0 V (tolerance: +-10 mV). */
#define TEMPSENSOR_CAL2_ADDR_CMSIS                0x1FF800FE      /*!<Internal temperature sensor, address of parameter TS_CAL2: On STM32L1, temperature sensor ADC raw data acquired at temperature 110 DegC (tolerance: +-5 DegC), Vref+ = 3.0 V (tolerance: +-10 mV). */

/********************  Bit definition for ADC_SR register  ********************/
#define ADC_SR_AWD_Pos                       (0U)                              
#define ADC_SR_AWD_Msk                       (0x1UL << ADC_SR_AWD_Pos)          /*!< 0x00000001 */
#define ADC_SR_AWD                           ADC_SR_AWD_Msk                    /*!< ADC analog watchdog 1 flag */
#define ADC_SR_EOCS_Pos                      (1U)                              
#define ADC_SR_EOCS_Msk                      (0x1UL << ADC_SR_EOCS_Pos)         /*!< 0x00000002 */
#define ADC_SR_EOCS                          ADC_SR_EOCS_Msk                   /*!< ADC group regular end of unitary conversion or end of sequence conversions flag */
#define ADC_SR_JEOS_Pos                      (2U)                              
#define ADC_SR_JEOS_Msk                      (0x1UL << ADC_SR_JEOS_Pos)         /*!< 0x00000004 */
#define ADC_SR_JEOS                          ADC_SR_JEOS_Msk                   /*!< ADC group injected end of sequence conversions flag */
#define ADC_SR_JSTRT_Pos                     (3U)                              
#define ADC_SR_JSTRT_Msk                     (0x1UL << ADC_SR_JSTRT_Pos)        /*!< 0x00000008 */
#define ADC_SR_JSTRT                         ADC_SR_JSTRT_Msk                  /*!< ADC group injected conversion start flag */
#define ADC_SR_STRT_Pos                      (4U)                              
#define ADC_SR_STRT_Msk                      (0x1UL << ADC_SR_STRT_Pos)         /*!< 0x00000010 */
#define ADC_SR_STRT                          ADC_SR_STRT_Msk                   /*!< ADC group regular conversion start flag */
#define ADC_SR_OVR_Pos                       (5U)                              
#define ADC_SR_OVR_Msk                       (0x1UL << ADC_SR_OVR_Pos)          /*!< 0x00000020 */
#define ADC_SR_OVR                           ADC_SR_OVR_Msk                    /*!< ADC group regular overrun flag */
#define ADC_SR_ADONS_Pos                     (6U)                              
#define ADC_SR_ADONS_Msk                     (0x1UL << ADC_SR_ADONS_Pos)        /*!< 0x00000040 */
#define ADC_SR_ADONS                         ADC_SR_ADONS_Msk                  /*!< ADC ready flag */
#define ADC_SR_RCNR_Pos                      (8U)                              
#define ADC_SR_RCNR_Msk                      (0x1UL << ADC_SR_RCNR_Pos)         /*!< 0x00000100 */
#define ADC_SR_RCNR                          ADC_SR_RCNR_Msk                   /*!< ADC group regular not ready flag */
#define ADC_SR_JCNR_Pos                      (9U)                              
#define ADC_SR_JCNR_Msk                      (0x1UL << ADC_SR_JCNR_Pos)         /*!< 0x00000200 */
#define ADC_SR_JCNR                          ADC_SR_JCNR_Msk                   /*!< ADC group injected not ready flag */

/* Legacy defines */
#define  ADC_SR_EOC                          (ADC_SR_EOCS)
#define  ADC_SR_JEOC                         (ADC_SR_JEOS)

/*******************  Bit definition for ADC_CR1 register  ********************/
#define ADC_CR1_AWDCH_Pos                    (0U)                              
#define ADC_CR1_AWDCH_Msk                    (0x1FUL << ADC_CR1_AWDCH_Pos)      /*!< 0x0000001F */
#define ADC_CR1_AWDCH                        ADC_CR1_AWDCH_Msk                 /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CR1_AWDCH_0                      (0x01UL << ADC_CR1_AWDCH_Pos)      /*!< 0x00000001 */
#define ADC_CR1_AWDCH_1                      (0x02UL << ADC_CR1_AWDCH_Pos)      /*!< 0x00000002 */
#define ADC_CR1_AWDCH_2                      (0x04UL << ADC_CR1_AWDCH_Pos)      /*!< 0x00000004 */
#define ADC_CR1_AWDCH_3                      (0x08UL << ADC_CR1_AWDCH_Pos)      /*!< 0x00000008 */
#define ADC_CR1_AWDCH_4                      (0x10UL << ADC_CR1_AWDCH_Pos)      /*!< 0x00000010 */

#define ADC_CR1_EOCSIE_Pos                   (5U)                              
#define ADC_CR1_EOCSIE_Msk                   (0x1UL << ADC_CR1_EOCSIE_Pos)      /*!< 0x00000020 */
#define ADC_CR1_EOCSIE                       ADC_CR1_EOCSIE_Msk                /*!< ADC group regular end of unitary conversion or end of sequence conversions interrupt */
#define ADC_CR1_AWDIE_Pos                    (6U)                              
#define ADC_CR1_AWDIE_Msk                    (0x1UL << ADC_CR1_AWDIE_Pos)       /*!< 0x00000040 */
#define ADC_CR1_AWDIE                        ADC_CR1_AWDIE_Msk                 /*!< ADC analog watchdog 1 interrupt */
#define ADC_CR1_JEOSIE_Pos                   (7U)                              
#define ADC_CR1_JEOSIE_Msk                   (0x1UL << ADC_CR1_JEOSIE_Pos)      /*!< 0x00000080 */
#define ADC_CR1_JEOSIE                       ADC_CR1_JEOSIE_Msk                /*!< ADC group injected end of sequence conversions interrupt */
#define ADC_CR1_SCAN_Pos                     (8U)                              
#define ADC_CR1_SCAN_Msk                     (0x1UL << ADC_CR1_SCAN_Pos)        /*!< 0x00000100 */
#define ADC_CR1_SCAN                         ADC_CR1_SCAN_Msk                  /*!< ADC scan mode */
#define ADC_CR1_AWDSGL_Pos                   (9U)                              
#define ADC_CR1_AWDSGL_Msk                   (0x1UL << ADC_CR1_AWDSGL_Pos)      /*!< 0x00000200 */
#define ADC_CR1_AWDSGL                       ADC_CR1_AWDSGL_Msk                /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CR1_JAUTO_Pos                    (10U)                             
#define ADC_CR1_JAUTO_Msk                    (0x1UL << ADC_CR1_JAUTO_Pos)       /*!< 0x00000400 */
#define ADC_CR1_JAUTO                        ADC_CR1_JAUTO_Msk                 /*!< ADC group injected automatic trigger mode */
#define ADC_CR1_DISCEN_Pos                   (11U)                             
#define ADC_CR1_DISCEN_Msk                   (0x1UL << ADC_CR1_DISCEN_Pos)      /*!< 0x00000800 */
#define ADC_CR1_DISCEN                       ADC_CR1_DISCEN_Msk                /*!< ADC group regular sequencer discontinuous mode */
#define ADC_CR1_JDISCEN_Pos                  (12U)                             
#define ADC_CR1_JDISCEN_Msk                  (0x1UL << ADC_CR1_JDISCEN_Pos)     /*!< 0x00001000 */
#define ADC_CR1_JDISCEN                      ADC_CR1_JDISCEN_Msk               /*!< ADC group injected sequencer discontinuous mode */

#define ADC_CR1_DISCNUM_Pos                  (13U)                             
#define ADC_CR1_DISCNUM_Msk                  (0x7UL << ADC_CR1_DISCNUM_Pos)     /*!< 0x0000E000 */
#define ADC_CR1_DISCNUM                      ADC_CR1_DISCNUM_Msk               /*!< ADC group regular sequencer discontinuous number of ranks */
#define ADC_CR1_DISCNUM_0                    (0x1UL << ADC_CR1_DISCNUM_Pos)     /*!< 0x00002000 */
#define ADC_CR1_DISCNUM_1                    (0x2UL << ADC_CR1_DISCNUM_Pos)     /*!< 0x00004000 */
#define ADC_CR1_DISCNUM_2                    (0x4UL << ADC_CR1_DISCNUM_Pos)     /*!< 0x00008000 */

#define ADC_CR1_PDD_Pos                      (16U)                             
#define ADC_CR1_PDD_Msk                      (0x1UL << ADC_CR1_PDD_Pos)         /*!< 0x00010000 */
#define ADC_CR1_PDD                          ADC_CR1_PDD_Msk                   /*!< ADC power down during auto delay phase */
#define ADC_CR1_PDI_Pos                      (17U)                             
#define ADC_CR1_PDI_Msk                      (0x1UL << ADC_CR1_PDI_Pos)         /*!< 0x00020000 */
#define ADC_CR1_PDI                          ADC_CR1_PDI_Msk                   /*!< ADC power down during idle phase */

#define ADC_CR1_JAWDEN_Pos                   (22U)                             
#define ADC_CR1_JAWDEN_Msk                   (0x1UL << ADC_CR1_JAWDEN_Pos)      /*!< 0x00400000 */
#define ADC_CR1_JAWDEN                       ADC_CR1_JAWDEN_Msk                /*!< ADC analog watchdog 1 enable on scope ADC group injected */
#define ADC_CR1_AWDEN_Pos                    (23U)                             
#define ADC_CR1_AWDEN_Msk                    (0x1UL << ADC_CR1_AWDEN_Pos)       /*!< 0x00800000 */
#define ADC_CR1_AWDEN                        ADC_CR1_AWDEN_Msk                 /*!< ADC analog watchdog 1 enable on scope ADC group regular */

#define ADC_CR1_RES_Pos                      (24U)                             
#define ADC_CR1_RES_Msk                      (0x3UL << ADC_CR1_RES_Pos)         /*!< 0x03000000 */
#define ADC_CR1_RES                          ADC_CR1_RES_Msk                   /*!< ADC resolution */
#define ADC_CR1_RES_0                        (0x1UL << ADC_CR1_RES_Pos)         /*!< 0x01000000 */
#define ADC_CR1_RES_1                        (0x2UL << ADC_CR1_RES_Pos)         /*!< 0x02000000 */

#define ADC_CR1_OVRIE_Pos                    (26U)                             
#define ADC_CR1_OVRIE_Msk                    (0x1UL << ADC_CR1_OVRIE_Pos)       /*!< 0x04000000 */
#define ADC_CR1_OVRIE                        ADC_CR1_OVRIE_Msk                 /*!< ADC group regular overrun interrupt */

/* Legacy defines */
#define  ADC_CR1_EOCIE                       (ADC_CR1_EOCSIE)
#define  ADC_CR1_JEOCIE                      (ADC_CR1_JEOSIE)

/*******************  Bit definition for ADC_CR2 register  ********************/
#define ADC_CR2_ADON_Pos                     (0U)                              
#define ADC_CR2_ADON_Msk                     (0x1UL << ADC_CR2_ADON_Pos)        /*!< 0x00000001 */
#define ADC_CR2_ADON                         ADC_CR2_ADON_Msk                  /*!< ADC enable */
#define ADC_CR2_CONT_Pos                     (1U)                              
#define ADC_CR2_CONT_Msk                     (0x1UL << ADC_CR2_CONT_Pos)        /*!< 0x00000002 */
#define ADC_CR2_CONT                         ADC_CR2_CONT_Msk                  /*!< ADC group regular continuous conversion mode */
#define ADC_CR2_CFG_Pos                      (2U)                              
#define ADC_CR2_CFG_Msk                      (0x1UL << ADC_CR2_CFG_Pos)         /*!< 0x00000004 */
#define ADC_CR2_CFG                          ADC_CR2_CFG_Msk                   /*!< ADC channels bank selection */

#define ADC_CR2_DELS_Pos                     (4U)                              
#define ADC_CR2_DELS_Msk                     (0x7UL << ADC_CR2_DELS_Pos)        /*!< 0x00000070 */
#define ADC_CR2_DELS                         ADC_CR2_DELS_Msk                  /*!< ADC auto delay selection */
#define ADC_CR2_DELS_0                       (0x1UL << ADC_CR2_DELS_Pos)        /*!< 0x00000010 */
#define ADC_CR2_DELS_1                       (0x2UL << ADC_CR2_DELS_Pos)        /*!< 0x00000020 */
#define ADC_CR2_DELS_2                       (0x4UL << ADC_CR2_DELS_Pos)        /*!< 0x00000040 */

#define ADC_CR2_DMA_Pos                      (8U)                              
#define ADC_CR2_DMA_Msk                      (0x1UL << ADC_CR2_DMA_Pos)         /*!< 0x00000100 */
#define ADC_CR2_DMA                          ADC_CR2_DMA_Msk                   /*!< ADC DMA transfer enable */
#define ADC_CR2_DDS_Pos                      (9U)                              
#define ADC_CR2_DDS_Msk                      (0x1UL << ADC_CR2_DDS_Pos)         /*!< 0x00000200 */
#define ADC_CR2_DDS                          ADC_CR2_DDS_Msk                   /*!< ADC DMA transfer configuration */
#define ADC_CR2_EOCS_Pos                     (10U)                             
#define ADC_CR2_EOCS_Msk                     (0x1UL << ADC_CR2_EOCS_Pos)        /*!< 0x00000400 */
#define ADC_CR2_EOCS                         ADC_CR2_EOCS_Msk                  /*!< ADC end of unitary or end of sequence conversions selection */
#define ADC_CR2_ALIGN_Pos                    (11U)                             
#define ADC_CR2_ALIGN_Msk                    (0x1UL << ADC_CR2_ALIGN_Pos)       /*!< 0x00000800 */
#define ADC_CR2_ALIGN                        ADC_CR2_ALIGN_Msk                 /*!< ADC data alignement */

#define ADC_CR2_JEXTSEL_Pos                  (16U)                             
#define ADC_CR2_JEXTSEL_Msk                  (0xFUL << ADC_CR2_JEXTSEL_Pos)     /*!< 0x000F0000 */
#define ADC_CR2_JEXTSEL                      ADC_CR2_JEXTSEL_Msk               /*!< ADC group injected external trigger source */
#define ADC_CR2_JEXTSEL_0                    (0x1UL << ADC_CR2_JEXTSEL_Pos)     /*!< 0x00010000 */
#define ADC_CR2_JEXTSEL_1                    (0x2UL << ADC_CR2_JEXTSEL_Pos)     /*!< 0x00020000 */
#define ADC_CR2_JEXTSEL_2                    (0x4UL << ADC_CR2_JEXTSEL_Pos)     /*!< 0x00040000 */
#define ADC_CR2_JEXTSEL_3                    (0x8UL << ADC_CR2_JEXTSEL_Pos)     /*!< 0x00080000 */

#define ADC_CR2_JEXTEN_Pos                   (20U)                             
#define ADC_CR2_JEXTEN_Msk                   (0x3UL << ADC_CR2_JEXTEN_Pos)      /*!< 0x00300000 */
#define ADC_CR2_JEXTEN                       ADC_CR2_JEXTEN_Msk                /*!< ADC group injected external trigger polarity */
#define ADC_CR2_JEXTEN_0                     (0x1UL << ADC_CR2_JEXTEN_Pos)      /*!< 0x00100000 */
#define ADC_CR2_JEXTEN_1                     (0x2UL << ADC_CR2_JEXTEN_Pos)      /*!< 0x00200000 */

#define ADC_CR2_JSWSTART_Pos                 (22U)                             
#define ADC_CR2_JSWSTART_Msk                 (0x1UL << ADC_CR2_JSWSTART_Pos)    /*!< 0x00400000 */
#define ADC_CR2_JSWSTART                     ADC_CR2_JSWSTART_Msk              /*!< ADC group injected conversion start */

#define ADC_CR2_EXTSEL_Pos                   (24U)                             
#define ADC_CR2_EXTSEL_Msk                   (0xFUL << ADC_CR2_EXTSEL_Pos)      /*!< 0x0F000000 */
#define ADC_CR2_EXTSEL                       ADC_CR2_EXTSEL_Msk                /*!< ADC group regular external trigger source */
#define ADC_CR2_EXTSEL_0                     (0x1UL << ADC_CR2_EXTSEL_Pos)      /*!< 0x01000000 */
#define ADC_CR2_EXTSEL_1                     (0x2UL << ADC_CR2_EXTSEL_Pos)      /*!< 0x02000000 */
#define ADC_CR2_EXTSEL_2                     (0x4UL << ADC_CR2_EXTSEL_Pos)      /*!< 0x04000000 */
#define ADC_CR2_EXTSEL_3                     (0x8UL << ADC_CR2_EXTSEL_Pos)      /*!< 0x08000000 */

#define ADC_CR2_EXTEN_Pos                    (28U)                             
#define ADC_CR2_EXTEN_Msk                    (0x3UL << ADC_CR2_EXTEN_Pos)       /*!< 0x30000000 */
#define ADC_CR2_EXTEN                        ADC_CR2_EXTEN_Msk                 /*!< ADC group regular external trigger polarity */
#define ADC_CR2_EXTEN_0                      (0x1UL << ADC_CR2_EXTEN_Pos)       /*!< 0x10000000 */
#define ADC_CR2_EXTEN_1                      (0x2UL << ADC_CR2_EXTEN_Pos)       /*!< 0x20000000 */

#define ADC_CR2_SWSTART_Pos                  (30U)                             
#define ADC_CR2_SWSTART_Msk                  (0x1UL << ADC_CR2_SWSTART_Pos)     /*!< 0x40000000 */
#define ADC_CR2_SWSTART                      ADC_CR2_SWSTART_Msk               /*!< ADC group regular conversion start */

/******************  Bit definition for ADC_SMPR1 register  *******************/
#define ADC_SMPR1_SMP20_Pos                  (0U)                              
#define ADC_SMPR1_SMP20_Msk                  (0x7UL << ADC_SMPR1_SMP20_Pos)     /*!< 0x00000007 */
#define ADC_SMPR1_SMP20                      ADC_SMPR1_SMP20_Msk               /*!< ADC channel 20 sampling time selection */
#define ADC_SMPR1_SMP20_0                    (0x1UL << ADC_SMPR1_SMP20_Pos)     /*!< 0x00000001 */
#define ADC_SMPR1_SMP20_1                    (0x2UL << ADC_SMPR1_SMP20_Pos)     /*!< 0x00000002 */
#define ADC_SMPR1_SMP20_2                    (0x4UL << ADC_SMPR1_SMP20_Pos)     /*!< 0x00000004 */

#define ADC_SMPR1_SMP21_Pos                  (3U)                              
#define ADC_SMPR1_SMP21_Msk                  (0x7UL << ADC_SMPR1_SMP21_Pos)     /*!< 0x00000038 */
#define ADC_SMPR1_SMP21                      ADC_SMPR1_SMP21_Msk               /*!< ADC channel 21 sampling time selection */
#define ADC_SMPR1_SMP21_0                    (0x1UL << ADC_SMPR1_SMP21_Pos)     /*!< 0x00000008 */
#define ADC_SMPR1_SMP21_1                    (0x2UL << ADC_SMPR1_SMP21_Pos)     /*!< 0x00000010 */
#define ADC_SMPR1_SMP21_2                    (0x4UL << ADC_SMPR1_SMP21_Pos)     /*!< 0x00000020 */

#define ADC_SMPR1_SMP22_Pos                  (6U)                              
#define ADC_SMPR1_SMP22_Msk                  (0x7UL << ADC_SMPR1_SMP22_Pos)     /*!< 0x000001C0 */
#define ADC_SMPR1_SMP22                      ADC_SMPR1_SMP22_Msk               /*!< ADC channel 22 sampling time selection */
#define ADC_SMPR1_SMP22_0                    (0x1UL << ADC_SMPR1_SMP22_Pos)     /*!< 0x00000040 */
#define ADC_SMPR1_SMP22_1                    (0x2UL << ADC_SMPR1_SMP22_Pos)     /*!< 0x00000080 */
#define ADC_SMPR1_SMP22_2                    (0x4UL << ADC_SMPR1_SMP22_Pos)     /*!< 0x00000100 */

#define ADC_SMPR1_SMP23_Pos                  (9U)                              
#define ADC_SMPR1_SMP23_Msk                  (0x7UL << ADC_SMPR1_SMP23_Pos)     /*!< 0x00000E00 */
#define ADC_SMPR1_SMP23                      ADC_SMPR1_SMP23_Msk               /*!< ADC channel 23 sampling time selection */
#define ADC_SMPR1_SMP23_0                    (0x1UL << ADC_SMPR1_SMP23_Pos)     /*!< 0x00000200 */
#define ADC_SMPR1_SMP23_1                    (0x2UL << ADC_SMPR1_SMP23_Pos)     /*!< 0x00000400 */
#define ADC_SMPR1_SMP23_2                    (0x4UL << ADC_SMPR1_SMP23_Pos)     /*!< 0x00000800 */

#define ADC_SMPR1_SMP24_Pos                  (12U)                             
#define ADC_SMPR1_SMP24_Msk                  (0x7UL << ADC_SMPR1_SMP24_Pos)     /*!< 0x00007000 */
#define ADC_SMPR1_SMP24                      ADC_SMPR1_SMP24_Msk               /*!< ADC channel 24 sampling time selection */
#define ADC_SMPR1_SMP24_0                    (0x1UL << ADC_SMPR1_SMP24_Pos)     /*!< 0x00001000 */
#define ADC_SMPR1_SMP24_1                    (0x2UL << ADC_SMPR1_SMP24_Pos)     /*!< 0x00002000 */
#define ADC_SMPR1_SMP24_2                    (0x4UL << ADC_SMPR1_SMP24_Pos)     /*!< 0x00004000 */

#define ADC_SMPR1_SMP25_Pos                  (15U)                             
#define ADC_SMPR1_SMP25_Msk                  (0x7UL << ADC_SMPR1_SMP25_Pos)     /*!< 0x00038000 */
#define ADC_SMPR1_SMP25                      ADC_SMPR1_SMP25_Msk               /*!< ADC channel 25 sampling time selection */
#define ADC_SMPR1_SMP25_0                    (0x1UL << ADC_SMPR1_SMP25_Pos)     /*!< 0x00008000 */
#define ADC_SMPR1_SMP25_1                    (0x2UL << ADC_SMPR1_SMP25_Pos)     /*!< 0x00010000 */
#define ADC_SMPR1_SMP25_2                    (0x4UL << ADC_SMPR1_SMP25_Pos)     /*!< 0x00020000 */

#define ADC_SMPR1_SMP26_Pos                  (18U)                             
#define ADC_SMPR1_SMP26_Msk                  (0x7UL << ADC_SMPR1_SMP26_Pos)     /*!< 0x001C0000 */
#define ADC_SMPR1_SMP26                      ADC_SMPR1_SMP26_Msk               /*!< ADC channel 26 sampling time selection */
#define ADC_SMPR1_SMP26_0                    (0x1UL << ADC_SMPR1_SMP26_Pos)     /*!< 0x00040000 */
#define ADC_SMPR1_SMP26_1                    (0x2UL << ADC_SMPR1_SMP26_Pos)     /*!< 0x00080000 */
#define ADC_SMPR1_SMP26_2                    (0x4UL << ADC_SMPR1_SMP26_Pos)     /*!< 0x00100000 */

#define ADC_SMPR1_SMP27_Pos                  (21U)                             
#define ADC_SMPR1_SMP27_Msk                  (0x7UL << ADC_SMPR1_SMP27_Pos)     /*!< 0x00E00000 */
#define ADC_SMPR1_SMP27                      ADC_SMPR1_SMP27_Msk               /*!< ADC channel 27 sampling time selection */
#define ADC_SMPR1_SMP27_0                    (0x1UL << ADC_SMPR1_SMP27_Pos)     /*!< 0x00200000 */
#define ADC_SMPR1_SMP27_1                    (0x2UL << ADC_SMPR1_SMP27_Pos)     /*!< 0x00400000 */
#define ADC_SMPR1_SMP27_2                    (0x4UL << ADC_SMPR1_SMP27_Pos)     /*!< 0x00800000 */

#define ADC_SMPR1_SMP28_Pos                  (24U)                             
#define ADC_SMPR1_SMP28_Msk                  (0x7UL << ADC_SMPR1_SMP28_Pos)     /*!< 0x07000000 */
#define ADC_SMPR1_SMP28                      ADC_SMPR1_SMP28_Msk               /*!< ADC channel 28 sampling time selection */
#define ADC_SMPR1_SMP28_0                    (0x1UL << ADC_SMPR1_SMP28_Pos)     /*!< 0x01000000 */
#define ADC_SMPR1_SMP28_1                    (0x2UL << ADC_SMPR1_SMP28_Pos)     /*!< 0x02000000 */
#define ADC_SMPR1_SMP28_2                    (0x4UL << ADC_SMPR1_SMP28_Pos)     /*!< 0x04000000 */

#define ADC_SMPR1_SMP29_Pos                  (27U)                             
#define ADC_SMPR1_SMP29_Msk                  (0x7UL << ADC_SMPR1_SMP29_Pos)     /*!< 0x38000000 */
#define ADC_SMPR1_SMP29                      ADC_SMPR1_SMP29_Msk               /*!< ADC channel 29 sampling time selection */
#define ADC_SMPR1_SMP29_0                    (0x1UL << ADC_SMPR1_SMP29_Pos)     /*!< 0x08000000 */
#define ADC_SMPR1_SMP29_1                    (0x2UL << ADC_SMPR1_SMP29_Pos)     /*!< 0x10000000 */
#define ADC_SMPR1_SMP29_2                    (0x4UL << ADC_SMPR1_SMP29_Pos)     /*!< 0x20000000 */

/******************  Bit definition for ADC_SMPR2 register  *******************/
#define ADC_SMPR2_SMP10_Pos                  (0U)                              
#define ADC_SMPR2_SMP10_Msk                  (0x7UL << ADC_SMPR2_SMP10_Pos)     /*!< 0x00000007 */
#define ADC_SMPR2_SMP10                      ADC_SMPR2_SMP10_Msk               /*!< ADC channel 10 sampling time selection */
#define ADC_SMPR2_SMP10_0                    (0x1UL << ADC_SMPR2_SMP10_Pos)     /*!< 0x00000001 */
#define ADC_SMPR2_SMP10_1                    (0x2UL << ADC_SMPR2_SMP10_Pos)     /*!< 0x00000002 */
#define ADC_SMPR2_SMP10_2                    (0x4UL << ADC_SMPR2_SMP10_Pos)     /*!< 0x00000004 */

#define ADC_SMPR2_SMP11_Pos                  (3U)                              
#define ADC_SMPR2_SMP11_Msk                  (0x7UL << ADC_SMPR2_SMP11_Pos)     /*!< 0x00000038 */
#define ADC_SMPR2_SMP11                      ADC_SMPR2_SMP11_Msk               /*!< ADC channel 11 sampling time selection */
#define ADC_SMPR2_SMP11_0                    (0x1UL << ADC_SMPR2_SMP11_Pos)     /*!< 0x00000008 */
#define ADC_SMPR2_SMP11_1                    (0x2UL << ADC_SMPR2_SMP11_Pos)     /*!< 0x00000010 */
#define ADC_SMPR2_SMP11_2                    (0x4UL << ADC_SMPR2_SMP11_Pos)     /*!< 0x00000020 */

#define ADC_SMPR2_SMP12_Pos                  (6U)                              
#define ADC_SMPR2_SMP12_Msk                  (0x7UL << ADC_SMPR2_SMP12_Pos)     /*!< 0x000001C0 */
#define ADC_SMPR2_SMP12                      ADC_SMPR2_SMP12_Msk               /*!< ADC channel 12 sampling time selection */
#define ADC_SMPR2_SMP12_0                    (0x1UL << ADC_SMPR2_SMP12_Pos)     /*!< 0x00000040 */
#define ADC_SMPR2_SMP12_1                    (0x2UL << ADC_SMPR2_SMP12_Pos)     /*!< 0x00000080 */
#define ADC_SMPR2_SMP12_2                    (0x4UL << ADC_SMPR2_SMP12_Pos)     /*!< 0x00000100 */

#define ADC_SMPR2_SMP13_Pos                  (9U)                              
#define ADC_SMPR2_SMP13_Msk                  (0x7UL << ADC_SMPR2_SMP13_Pos)     /*!< 0x00000E00 */
#define ADC_SMPR2_SMP13                      ADC_SMPR2_SMP13_Msk               /*!< ADC channel 13 sampling time selection */
#define ADC_SMPR2_SMP13_0                    (0x1UL << ADC_SMPR2_SMP13_Pos)     /*!< 0x00000200 */
#define ADC_SMPR2_SMP13_1                    (0x2UL << ADC_SMPR2_SMP13_Pos)     /*!< 0x00000400 */
#define ADC_SMPR2_SMP13_2                    (0x4UL << ADC_SMPR2_SMP13_Pos)     /*!< 0x00000800 */

#define ADC_SMPR2_SMP14_Pos                  (12U)                             
#define ADC_SMPR2_SMP14_Msk                  (0x7UL << ADC_SMPR2_SMP14_Pos)     /*!< 0x00007000 */
#define ADC_SMPR2_SMP14                      ADC_SMPR2_SMP14_Msk               /*!< ADC channel 14 sampling time selection */
#define ADC_SMPR2_SMP14_0                    (0x1UL << ADC_SMPR2_SMP14_Pos)     /*!< 0x00001000 */
#define ADC_SMPR2_SMP14_1                    (0x2UL << ADC_SMPR2_SMP14_Pos)     /*!< 0x00002000 */
#define ADC_SMPR2_SMP14_2                    (0x4UL << ADC_SMPR2_SMP14_Pos)     /*!< 0x00004000 */

#define ADC_SMPR2_SMP15_Pos                  (15U)                             
#define ADC_SMPR2_SMP15_Msk                  (0x7UL << ADC_SMPR2_SMP15_Pos)     /*!< 0x00038000 */
#define ADC_SMPR2_SMP15                      ADC_SMPR2_SMP15_Msk               /*!< ADC channel 5 sampling time selection */
#define ADC_SMPR2_SMP15_0                    (0x1UL << ADC_SMPR2_SMP15_Pos)     /*!< 0x00008000 */
#define ADC_SMPR2_SMP15_1                    (0x2UL << ADC_SMPR2_SMP15_Pos)     /*!< 0x00010000 */
#define ADC_SMPR2_SMP15_2                    (0x4UL << ADC_SMPR2_SMP15_Pos)     /*!< 0x00020000 */

#define ADC_SMPR2_SMP16_Pos                  (18U)                             
#define ADC_SMPR2_SMP16_Msk                  (0x7UL << ADC_SMPR2_SMP16_Pos)     /*!< 0x001C0000 */
#define ADC_SMPR2_SMP16                      ADC_SMPR2_SMP16_Msk               /*!< ADC channel 16 sampling time selection */
#define ADC_SMPR2_SMP16_0                    (0x1UL << ADC_SMPR2_SMP16_Pos)     /*!< 0x00040000 */
#define ADC_SMPR2_SMP16_1                    (0x2UL << ADC_SMPR2_SMP16_Pos)     /*!< 0x00080000 */
#define ADC_SMPR2_SMP16_2                    (0x4UL << ADC_SMPR2_SMP16_Pos)     /*!< 0x00100000 */

#define ADC_SMPR2_SMP17_Pos                  (21U)                             
#define ADC_SMPR2_SMP17_Msk                  (0x7UL << ADC_SMPR2_SMP17_Pos)     /*!< 0x00E00000 */
#define ADC_SMPR2_SMP17                      ADC_SMPR2_SMP17_Msk               /*!< ADC channel 17 sampling time selection */
#define ADC_SMPR2_SMP17_0                    (0x1UL << ADC_SMPR2_SMP17_Pos)     /*!< 0x00200000 */
#define ADC_SMPR2_SMP17_1                    (0x2UL << ADC_SMPR2_SMP17_Pos)     /*!< 0x00400000 */
#define ADC_SMPR2_SMP17_2                    (0x4UL << ADC_SMPR2_SMP17_Pos)     /*!< 0x00800000 */

#define ADC_SMPR2_SMP18_Pos                  (24U)                             
#define ADC_SMPR2_SMP18_Msk                  (0x7UL << ADC_SMPR2_SMP18_Pos)     /*!< 0x07000000 */
#define ADC_SMPR2_SMP18                      ADC_SMPR2_SMP18_Msk               /*!< ADC channel 18 sampling time selection */
#define ADC_SMPR2_SMP18_0                    (0x1UL << ADC_SMPR2_SMP18_Pos)     /*!< 0x01000000 */
#define ADC_SMPR2_SMP18_1                    (0x2UL << ADC_SMPR2_SMP18_Pos)     /*!< 0x02000000 */
#define ADC_SMPR2_SMP18_2                    (0x4UL << ADC_SMPR2_SMP18_Pos)     /*!< 0x04000000 */

#define ADC_SMPR2_SMP19_Pos                  (27U)                             
#define ADC_SMPR2_SMP19_Msk                  (0x7UL << ADC_SMPR2_SMP19_Pos)     /*!< 0x38000000 */
#define ADC_SMPR2_SMP19                      ADC_SMPR2_SMP19_Msk               /*!< ADC channel 19 sampling time selection */
#define ADC_SMPR2_SMP19_0                    (0x1UL << ADC_SMPR2_SMP19_Pos)     /*!< 0x08000000 */
#define ADC_SMPR2_SMP19_1                    (0x2UL << ADC_SMPR2_SMP19_Pos)     /*!< 0x10000000 */
#define ADC_SMPR2_SMP19_2                    (0x4UL << ADC_SMPR2_SMP19_Pos)     /*!< 0x20000000 */

/******************  Bit definition for ADC_SMPR3 register  *******************/
#define ADC_SMPR3_SMP0_Pos                   (0U)                              
#define ADC_SMPR3_SMP0_Msk                   (0x7UL << ADC_SMPR3_SMP0_Pos)      /*!< 0x00000007 */
#define ADC_SMPR3_SMP0                       ADC_SMPR3_SMP0_Msk                /*!< ADC channel 0 sampling time selection */
#define ADC_SMPR3_SMP0_0                     (0x1UL << ADC_SMPR3_SMP0_Pos)      /*!< 0x00000001 */
#define ADC_SMPR3_SMP0_1                     (0x2UL << ADC_SMPR3_SMP0_Pos)      /*!< 0x00000002 */
#define ADC_SMPR3_SMP0_2                     (0x4UL << ADC_SMPR3_SMP0_Pos)      /*!< 0x00000004 */
 
#define ADC_SMPR3_SMP1_Pos                   (3U)                              
#define ADC_SMPR3_SMP1_Msk                   (0x7UL << ADC_SMPR3_SMP1_Pos)      /*!< 0x00000038 */
#define ADC_SMPR3_SMP1                       ADC_SMPR3_SMP1_Msk                /*!< ADC channel 1 sampling time selection */
#define ADC_SMPR3_SMP1_0                     (0x1UL << ADC_SMPR3_SMP1_Pos)      /*!< 0x00000008 */
#define ADC_SMPR3_SMP1_1                     (0x2UL << ADC_SMPR3_SMP1_Pos)      /*!< 0x00000010 */
#define ADC_SMPR3_SMP1_2                     (0x4UL << ADC_SMPR3_SMP1_Pos)      /*!< 0x00000020 */

#define ADC_SMPR3_SMP2_Pos                   (6U)                              
#define ADC_SMPR3_SMP2_Msk                   (0x7UL << ADC_SMPR3_SMP2_Pos)      /*!< 0x000001C0 */
#define ADC_SMPR3_SMP2                       ADC_SMPR3_SMP2_Msk                /*!< ADC channel 2 sampling time selection */
#define ADC_SMPR3_SMP2_0                     (0x1UL << ADC_SMPR3_SMP2_Pos)      /*!< 0x00000040 */
#define ADC_SMPR3_SMP2_1                     (0x2UL << ADC_SMPR3_SMP2_Pos)      /*!< 0x00000080 */
#define ADC_SMPR3_SMP2_2                     (0x4UL << ADC_SMPR3_SMP2_Pos)      /*!< 0x00000100 */

#define ADC_SMPR3_SMP3_Pos                   (9U)                              
#define ADC_SMPR3_SMP3_Msk                   (0x7UL << ADC_SMPR3_SMP3_Pos)      /*!< 0x00000E00 */
#define ADC_SMPR3_SMP3                       ADC_SMPR3_SMP3_Msk                /*!< ADC channel 3 sampling time selection */
#define ADC_SMPR3_SMP3_0                     (0x1UL << ADC_SMPR3_SMP3_Pos)      /*!< 0x00000200 */
#define ADC_SMPR3_SMP3_1                     (0x2UL << ADC_SMPR3_SMP3_Pos)      /*!< 0x00000400 */
#define ADC_SMPR3_SMP3_2                     (0x4UL << ADC_SMPR3_SMP3_Pos)      /*!< 0x00000800 */

#define ADC_SMPR3_SMP4_Pos                   (12U)                             
#define ADC_SMPR3_SMP4_Msk                   (0x7UL << ADC_SMPR3_SMP4_Pos)      /*!< 0x00007000 */
#define ADC_SMPR3_SMP4                       ADC_SMPR3_SMP4_Msk                /*!< ADC channel 4 sampling time selection */
#define ADC_SMPR3_SMP4_0                     (0x1UL << ADC_SMPR3_SMP4_Pos)      /*!< 0x00001000 */
#define ADC_SMPR3_SMP4_1                     (0x2UL << ADC_SMPR3_SMP4_Pos)      /*!< 0x00002000 */
#define ADC_SMPR3_SMP4_2                     (0x4UL << ADC_SMPR3_SMP4_Pos)      /*!< 0x00004000 */

#define ADC_SMPR3_SMP5_Pos                   (15U)                             
#define ADC_SMPR3_SMP5_Msk                   (0x7UL << ADC_SMPR3_SMP5_Pos)      /*!< 0x00038000 */
#define ADC_SMPR3_SMP5                       ADC_SMPR3_SMP5_Msk                /*!< ADC channel 5 sampling time selection */
#define ADC_SMPR3_SMP5_0                     (0x1UL << ADC_SMPR3_SMP5_Pos)      /*!< 0x00008000 */
#define ADC_SMPR3_SMP5_1                     (0x2UL << ADC_SMPR3_SMP5_Pos)      /*!< 0x00010000 */
#define ADC_SMPR3_SMP5_2                     (0x4UL << ADC_SMPR3_SMP5_Pos)      /*!< 0x00020000 */

#define ADC_SMPR3_SMP6_Pos                   (18U)                             
#define ADC_SMPR3_SMP6_Msk                   (0x7UL << ADC_SMPR3_SMP6_Pos)      /*!< 0x001C0000 */
#define ADC_SMPR3_SMP6                       ADC_SMPR3_SMP6_Msk                /*!< ADC channel 6 sampling time selection */
#define ADC_SMPR3_SMP6_0                     (0x1UL << ADC_SMPR3_SMP6_Pos)      /*!< 0x00040000 */
#define ADC_SMPR3_SMP6_1                     (0x2UL << ADC_SMPR3_SMP6_Pos)      /*!< 0x00080000 */
#define ADC_SMPR3_SMP6_2                     (0x4UL << ADC_SMPR3_SMP6_Pos)      /*!< 0x00100000 */

#define ADC_SMPR3_SMP7_Pos                   (21U)                             
#define ADC_SMPR3_SMP7_Msk                   (0x7UL << ADC_SMPR3_SMP7_Pos)      /*!< 0x00E00000 */
#define ADC_SMPR3_SMP7                       ADC_SMPR3_SMP7_Msk                /*!< ADC channel 7 sampling time selection */
#define ADC_SMPR3_SMP7_0                     (0x1UL << ADC_SMPR3_SMP7_Pos)      /*!< 0x00200000 */
#define ADC_SMPR3_SMP7_1                     (0x2UL << ADC_SMPR3_SMP7_Pos)      /*!< 0x00400000 */
#define ADC_SMPR3_SMP7_2                     (0x4UL << ADC_SMPR3_SMP7_Pos)      /*!< 0x00800000 */

#define ADC_SMPR3_SMP8_Pos                   (24U)                             
#define ADC_SMPR3_SMP8_Msk                   (0x7UL << ADC_SMPR3_SMP8_Pos)      /*!< 0x07000000 */
#define ADC_SMPR3_SMP8                       ADC_SMPR3_SMP8_Msk                /*!< ADC channel 8 sampling time selection */
#define ADC_SMPR3_SMP8_0                     (0x1UL << ADC_SMPR3_SMP8_Pos)      /*!< 0x01000000 */
#define ADC_SMPR3_SMP8_1                     (0x2UL << ADC_SMPR3_SMP8_Pos)      /*!< 0x02000000 */
#define ADC_SMPR3_SMP8_2                     (0x4UL << ADC_SMPR3_SMP8_Pos)      /*!< 0x04000000 */

#define ADC_SMPR3_SMP9_Pos                   (27U)                             
#define ADC_SMPR3_SMP9_Msk                   (0x7UL << ADC_SMPR3_SMP9_Pos)      /*!< 0x38000000 */
#define ADC_SMPR3_SMP9                       ADC_SMPR3_SMP9_Msk                /*!< ADC channel 9 sampling time selection */
#define ADC_SMPR3_SMP9_0                     (0x1UL << ADC_SMPR3_SMP9_Pos)      /*!< 0x08000000 */
#define ADC_SMPR3_SMP9_1                     (0x2UL << ADC_SMPR3_SMP9_Pos)      /*!< 0x10000000 */
#define ADC_SMPR3_SMP9_2                     (0x4UL << ADC_SMPR3_SMP9_Pos)      /*!< 0x20000000 */

/******************  Bit definition for ADC_JOFR1 register  *******************/
#define ADC_JOFR1_JOFFSET1_Pos               (0U)                              
#define ADC_JOFR1_JOFFSET1_Msk               (0xFFFUL << ADC_JOFR1_JOFFSET1_Pos) /*!< 0x00000FFF */
#define ADC_JOFR1_JOFFSET1                   ADC_JOFR1_JOFFSET1_Msk            /*!< ADC group injected sequencer rank 1 offset value */

/******************  Bit definition for ADC_JOFR2 register  *******************/
#define ADC_JOFR2_JOFFSET2_Pos               (0U)                              
#define ADC_JOFR2_JOFFSET2_Msk               (0xFFFUL << ADC_JOFR2_JOFFSET2_Pos) /*!< 0x00000FFF */
#define ADC_JOFR2_JOFFSET2                   ADC_JOFR2_JOFFSET2_Msk            /*!< ADC group injected sequencer rank 2 offset value */

/******************  Bit definition for ADC_JOFR3 register  *******************/
#define ADC_JOFR3_JOFFSET3_Pos               (0U)                              
#define ADC_JOFR3_JOFFSET3_Msk               (0xFFFUL << ADC_JOFR3_JOFFSET3_Pos) /*!< 0x00000FFF */
#define ADC_JOFR3_JOFFSET3                   ADC_JOFR3_JOFFSET3_Msk            /*!< ADC group injected sequencer rank 3 offset value */

/******************  Bit definition for ADC_JOFR4 register  *******************/
#define ADC_JOFR4_JOFFSET4_Pos               (0U)                              
#define ADC_JOFR4_JOFFSET4_Msk               (0xFFFUL << ADC_JOFR4_JOFFSET4_Pos) /*!< 0x00000FFF */
#define ADC_JOFR4_JOFFSET4                   ADC_JOFR4_JOFFSET4_Msk            /*!< ADC group injected sequencer rank 4 offset value */

/*******************  Bit definition for ADC_HTR register  ********************/
#define ADC_HTR_HT_Pos                       (0U)                              
#define ADC_HTR_HT_Msk                       (0xFFFUL << ADC_HTR_HT_Pos)        /*!< 0x00000FFF */
#define ADC_HTR_HT                           ADC_HTR_HT_Msk                    /*!< ADC analog watchdog 1 threshold high */

/*******************  Bit definition for ADC_LTR register  ********************/
#define ADC_LTR_LT_Pos                       (0U)                              
#define ADC_LTR_LT_Msk                       (0xFFFUL << ADC_LTR_LT_Pos)        /*!< 0x00000FFF */
#define ADC_LTR_LT                           ADC_LTR_LT_Msk                    /*!< ADC analog watchdog 1 threshold low */

/*******************  Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_L_Pos                       (20U)                             
#define ADC_SQR1_L_Msk                       (0x1FUL << ADC_SQR1_L_Pos)         /*!< 0x01F00000 */
#define ADC_SQR1_L                           ADC_SQR1_L_Msk                    /*!< ADC group regular sequencer scan length */
#define ADC_SQR1_L_0                         (0x01UL << ADC_SQR1_L_Pos)         /*!< 0x00100000 */
#define ADC_SQR1_L_1                         (0x02UL << ADC_SQR1_L_Pos)         /*!< 0x00200000 */
#define ADC_SQR1_L_2                         (0x04UL << ADC_SQR1_L_Pos)         /*!< 0x00400000 */
#define ADC_SQR1_L_3                         (0x08UL << ADC_SQR1_L_Pos)         /*!< 0x00800000 */
#define ADC_SQR1_L_4                         (0x10UL << ADC_SQR1_L_Pos)         /*!< 0x01000000 */

#define ADC_SQR1_SQ28_Pos                    (15U)                             
#define ADC_SQR1_SQ28_Msk                    (0x1FUL << ADC_SQR1_SQ28_Pos)      /*!< 0x000F8000 */
#define ADC_SQR1_SQ28                        ADC_SQR1_SQ28_Msk                 /*!< ADC group regular sequencer rank 28 */
#define ADC_SQR1_SQ28_0                      (0x01UL << ADC_SQR1_SQ28_Pos)      /*!< 0x00008000 */
#define ADC_SQR1_SQ28_1                      (0x02UL << ADC_SQR1_SQ28_Pos)      /*!< 0x00010000 */
#define ADC_SQR1_SQ28_2                      (0x04UL << ADC_SQR1_SQ28_Pos)      /*!< 0x00020000 */
#define ADC_SQR1_SQ28_3                      (0x08UL << ADC_SQR1_SQ28_Pos)      /*!< 0x00040000 */
#define ADC_SQR1_SQ28_4                      (0x10UL << ADC_SQR1_SQ28_Pos)      /*!< 0x00080000 */

#define ADC_SQR1_SQ27_Pos                    (10U)                             
#define ADC_SQR1_SQ27_Msk                    (0x1FUL << ADC_SQR1_SQ27_Pos)      /*!< 0x00007C00 */
#define ADC_SQR1_SQ27                        ADC_SQR1_SQ27_Msk                 /*!< ADC group regular sequencer rank 27 */
#define ADC_SQR1_SQ27_0                      (0x01UL << ADC_SQR1_SQ27_Pos)      /*!< 0x00000400 */
#define ADC_SQR1_SQ27_1                      (0x02UL << ADC_SQR1_SQ27_Pos)      /*!< 0x00000800 */
#define ADC_SQR1_SQ27_2                      (0x04UL << ADC_SQR1_SQ27_Pos)      /*!< 0x00001000 */
#define ADC_SQR1_SQ27_3                      (0x08UL << ADC_SQR1_SQ27_Pos)      /*!< 0x00002000 */
#define ADC_SQR1_SQ27_4                      (0x10UL << ADC_SQR1_SQ27_Pos)      /*!< 0x00004000 */

#define ADC_SQR1_SQ26_Pos                    (5U)                              
#define ADC_SQR1_SQ26_Msk                    (0x1FUL << ADC_SQR1_SQ26_Pos)      /*!< 0x000003E0 */
#define ADC_SQR1_SQ26                        ADC_SQR1_SQ26_Msk                 /*!< ADC group regular sequencer rank 26 */
#define ADC_SQR1_SQ26_0                      (0x01UL << ADC_SQR1_SQ26_Pos)      /*!< 0x00000020 */
#define ADC_SQR1_SQ26_1                      (0x02UL << ADC_SQR1_SQ26_Pos)      /*!< 0x00000040 */
#define ADC_SQR1_SQ26_2                      (0x04UL << ADC_SQR1_SQ26_Pos)      /*!< 0x00000080 */
#define ADC_SQR1_SQ26_3                      (0x08UL << ADC_SQR1_SQ26_Pos)      /*!< 0x00000100 */
#define ADC_SQR1_SQ26_4                      (0x10UL << ADC_SQR1_SQ26_Pos)      /*!< 0x00000200 */

#define ADC_SQR1_SQ25_Pos                    (0U)                              
#define ADC_SQR1_SQ25_Msk                    (0x1FUL << ADC_SQR1_SQ25_Pos)      /*!< 0x0000001F */
#define ADC_SQR1_SQ25                        ADC_SQR1_SQ25_Msk                 /*!< ADC group regular sequencer rank 25 */
#define ADC_SQR1_SQ25_0                      (0x01UL << ADC_SQR1_SQ25_Pos)      /*!< 0x00000001 */
#define ADC_SQR1_SQ25_1                      (0x02UL << ADC_SQR1_SQ25_Pos)      /*!< 0x00000002 */
#define ADC_SQR1_SQ25_2                      (0x04UL << ADC_SQR1_SQ25_Pos)      /*!< 0x00000004 */
#define ADC_SQR1_SQ25_3                      (0x08UL << ADC_SQR1_SQ25_Pos)      /*!< 0x00000008 */
#define ADC_SQR1_SQ25_4                      (0x10UL << ADC_SQR1_SQ25_Pos)      /*!< 0x00000010 */

/*******************  Bit definition for ADC_SQR2 register  *******************/
#define ADC_SQR2_SQ19_Pos                    (0U)                              
#define ADC_SQR2_SQ19_Msk                    (0x1FUL << ADC_SQR2_SQ19_Pos)      /*!< 0x0000001F */
#define ADC_SQR2_SQ19                        ADC_SQR2_SQ19_Msk                 /*!< ADC group regular sequencer rank 19 */
#define ADC_SQR2_SQ19_0                      (0x01UL << ADC_SQR2_SQ19_Pos)      /*!< 0x00000001 */
#define ADC_SQR2_SQ19_1                      (0x02UL << ADC_SQR2_SQ19_Pos)      /*!< 0x00000002 */
#define ADC_SQR2_SQ19_2                      (0x04UL << ADC_SQR2_SQ19_Pos)      /*!< 0x00000004 */
#define ADC_SQR2_SQ19_3                      (0x08UL << ADC_SQR2_SQ19_Pos)      /*!< 0x00000008 */
#define ADC_SQR2_SQ19_4                      (0x10UL << ADC_SQR2_SQ19_Pos)      /*!< 0x00000010 */

#define ADC_SQR2_SQ20_Pos                    (5U)                              
#define ADC_SQR2_SQ20_Msk                    (0x1FUL << ADC_SQR2_SQ20_Pos)      /*!< 0x000003E0 */
#define ADC_SQR2_SQ20                        ADC_SQR2_SQ20_Msk                 /*!< ADC group regular sequencer rank 20 */
#define ADC_SQR2_SQ20_0                      (0x01UL << ADC_SQR2_SQ20_Pos)      /*!< 0x00000020 */
#define ADC_SQR2_SQ20_1                      (0x02UL << ADC_SQR2_SQ20_Pos)      /*!< 0x00000040 */
#define ADC_SQR2_SQ20_2                      (0x04UL << ADC_SQR2_SQ20_Pos)      /*!< 0x00000080 */
#define ADC_SQR2_SQ20_3                      (0x08UL << ADC_SQR2_SQ20_Pos)      /*!< 0x00000100 */
#define ADC_SQR2_SQ20_4                      (0x10UL << ADC_SQR2_SQ20_Pos)      /*!< 0x00000200 */

#define ADC_SQR2_SQ21_Pos                    (10U)                             
#define ADC_SQR2_SQ21_Msk                    (0x1FUL << ADC_SQR2_SQ21_Pos)      /*!< 0x00007C00 */
#define ADC_SQR2_SQ21                        ADC_SQR2_SQ21_Msk                 /*!< ADC group regular sequencer rank 21 */
#define ADC_SQR2_SQ21_0                      (0x01UL << ADC_SQR2_SQ21_Pos)      /*!< 0x00000400 */
#define ADC_SQR2_SQ21_1                      (0x02UL << ADC_SQR2_SQ21_Pos)      /*!< 0x00000800 */
#define ADC_SQR2_SQ21_2                      (0x04UL << ADC_SQR2_SQ21_Pos)      /*!< 0x00001000 */
#define ADC_SQR2_SQ21_3                      (0x08UL << ADC_SQR2_SQ21_Pos)      /*!< 0x00002000 */
#define ADC_SQR2_SQ21_4                      (0x10UL << ADC_SQR2_SQ21_Pos)      /*!< 0x00004000 */

#define ADC_SQR2_SQ22_Pos                    (15U)                             
#define ADC_SQR2_SQ22_Msk                    (0x1FUL << ADC_SQR2_SQ22_Pos)      /*!< 0x000F8000 */
#define ADC_SQR2_SQ22                        ADC_SQR2_SQ22_Msk                 /*!< ADC group regular sequencer rank 22 */
#define ADC_SQR2_SQ22_0                      (0x01UL << ADC_SQR2_SQ22_Pos)      /*!< 0x00008000 */
#define ADC_SQR2_SQ22_1                      (0x02UL << ADC_SQR2_SQ22_Pos)      /*!< 0x00010000 */
#define ADC_SQR2_SQ22_2                      (0x04UL << ADC_SQR2_SQ22_Pos)      /*!< 0x00020000 */
#define ADC_SQR2_SQ22_3                      (0x08UL << ADC_SQR2_SQ22_Pos)      /*!< 0x00040000 */
#define ADC_SQR2_SQ22_4                      (0x10UL << ADC_SQR2_SQ22_Pos)      /*!< 0x00080000 */

#define ADC_SQR2_SQ23_Pos                    (20U)                             
#define ADC_SQR2_SQ23_Msk                    (0x1FUL << ADC_SQR2_SQ23_Pos)      /*!< 0x01F00000 */
#define ADC_SQR2_SQ23                        ADC_SQR2_SQ23_Msk                 /*!< ADC group regular sequencer rank 23 */
#define ADC_SQR2_SQ23_0                      (0x01UL << ADC_SQR2_SQ23_Pos)      /*!< 0x00100000 */
#define ADC_SQR2_SQ23_1                      (0x02UL << ADC_SQR2_SQ23_Pos)      /*!< 0x00200000 */
#define ADC_SQR2_SQ23_2                      (0x04UL << ADC_SQR2_SQ23_Pos)      /*!< 0x00400000 */
#define ADC_SQR2_SQ23_3                      (0x08UL << ADC_SQR2_SQ23_Pos)      /*!< 0x00800000 */
#define ADC_SQR2_SQ23_4                      (0x10UL << ADC_SQR2_SQ23_Pos)      /*!< 0x01000000 */

#define ADC_SQR2_SQ24_Pos                    (25U)                             
#define ADC_SQR2_SQ24_Msk                    (0x1FUL << ADC_SQR2_SQ24_Pos)      /*!< 0x3E000000 */
#define ADC_SQR2_SQ24                        ADC_SQR2_SQ24_Msk                 /*!< ADC group regular sequencer rank 24 */
#define ADC_SQR2_SQ24_0                      (0x01UL << ADC_SQR2_SQ24_Pos)      /*!< 0x02000000 */
#define ADC_SQR2_SQ24_1                      (0x02UL << ADC_SQR2_SQ24_Pos)      /*!< 0x04000000 */
#define ADC_SQR2_SQ24_2                      (0x04UL << ADC_SQR2_SQ24_Pos)      /*!< 0x08000000 */
#define ADC_SQR2_SQ24_3                      (0x08UL << ADC_SQR2_SQ24_Pos)      /*!< 0x10000000 */
#define ADC_SQR2_SQ24_4                      (0x10UL << ADC_SQR2_SQ24_Pos)      /*!< 0x20000000 */

/*******************  Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ13_Pos                    (0U)                              
#define ADC_SQR3_SQ13_Msk                    (0x1FUL << ADC_SQR3_SQ13_Pos)      /*!< 0x0000001F */
#define ADC_SQR3_SQ13                        ADC_SQR3_SQ13_Msk                 /*!< ADC group regular sequencer rank 13 */
#define ADC_SQR3_SQ13_0                      (0x01UL << ADC_SQR3_SQ13_Pos)      /*!< 0x00000001 */
#define ADC_SQR3_SQ13_1                      (0x02UL << ADC_SQR3_SQ13_Pos)      /*!< 0x00000002 */
#define ADC_SQR3_SQ13_2                      (0x04UL << ADC_SQR3_SQ13_Pos)      /*!< 0x00000004 */
#define ADC_SQR3_SQ13_3                      (0x08UL << ADC_SQR3_SQ13_Pos)      /*!< 0x00000008 */
#define ADC_SQR3_SQ13_4                      (0x10UL << ADC_SQR3_SQ13_Pos)      /*!< 0x00000010 */

#define ADC_SQR3_SQ14_Pos                    (5U)                              
#define ADC_SQR3_SQ14_Msk                    (0x1FUL << ADC_SQR3_SQ14_Pos)      /*!< 0x000003E0 */
#define ADC_SQR3_SQ14                        ADC_SQR3_SQ14_Msk                 /*!< ADC group regular sequencer rank 14 */
#define ADC_SQR3_SQ14_0                      (0x01UL << ADC_SQR3_SQ14_Pos)      /*!< 0x00000020 */
#define ADC_SQR3_SQ14_1                      (0x02UL << ADC_SQR3_SQ14_Pos)      /*!< 0x00000040 */
#define ADC_SQR3_SQ14_2                      (0x04UL << ADC_SQR3_SQ14_Pos)      /*!< 0x00000080 */
#define ADC_SQR3_SQ14_3                      (0x08UL << ADC_SQR3_SQ14_Pos)      /*!< 0x00000100 */
#define ADC_SQR3_SQ14_4                      (0x10UL << ADC_SQR3_SQ14_Pos)      /*!< 0x00000200 */

#define ADC_SQR3_SQ15_Pos                    (10U)                             
#define ADC_SQR3_SQ15_Msk                    (0x1FUL << ADC_SQR3_SQ15_Pos)      /*!< 0x00007C00 */
#define ADC_SQR3_SQ15                        ADC_SQR3_SQ15_Msk                 /*!< ADC group regular sequencer rank 15 */
#define ADC_SQR3_SQ15_0                      (0x01UL << ADC_SQR3_SQ15_Pos)      /*!< 0x00000400 */
#define ADC_SQR3_SQ15_1                      (0x02UL << ADC_SQR3_SQ15_Pos)      /*!< 0x00000800 */
#define ADC_SQR3_SQ15_2                      (0x04UL << ADC_SQR3_SQ15_Pos)      /*!< 0x00001000 */
#define ADC_SQR3_SQ15_3                      (0x08UL << ADC_SQR3_SQ15_Pos)      /*!< 0x00002000 */
#define ADC_SQR3_SQ15_4                      (0x10UL << ADC_SQR3_SQ15_Pos)      /*!< 0x00004000 */

#define ADC_SQR3_SQ16_Pos                    (15U)                             
#define ADC_SQR3_SQ16_Msk                    (0x1FUL << ADC_SQR3_SQ16_Pos)      /*!< 0x000F8000 */
#define ADC_SQR3_SQ16                        ADC_SQR3_SQ16_Msk                 /*!< ADC group regular sequencer rank 16 */
#define ADC_SQR3_SQ16_0                      (0x01UL << ADC_SQR3_SQ16_Pos)      /*!< 0x00008000 */
#define ADC_SQR3_SQ16_1                      (0x02UL << ADC_SQR3_SQ16_Pos)      /*!< 0x00010000 */
#define ADC_SQR3_SQ16_2                      (0x04UL << ADC_SQR3_SQ16_Pos)      /*!< 0x00020000 */
#define ADC_SQR3_SQ16_3                      (0x08UL << ADC_SQR3_SQ16_Pos)      /*!< 0x00040000 */
#define ADC_SQR3_SQ16_4                      (0x10UL << ADC_SQR3_SQ16_Pos)      /*!< 0x00080000 */

#define ADC_SQR3_SQ17_Pos                    (20U)                             
#define ADC_SQR3_SQ17_Msk                    (0x1FUL << ADC_SQR3_SQ17_Pos)      /*!< 0x01F00000 */
#define ADC_SQR3_SQ17                        ADC_SQR3_SQ17_Msk                 /*!< ADC group regular sequencer rank 17 */
#define ADC_SQR3_SQ17_0                      (0x01UL << ADC_SQR3_SQ17_Pos)      /*!< 0x00100000 */
#define ADC_SQR3_SQ17_1                      (0x02UL << ADC_SQR3_SQ17_Pos)      /*!< 0x00200000 */
#define ADC_SQR3_SQ17_2                      (0x04UL << ADC_SQR3_SQ17_Pos)      /*!< 0x00400000 */
#define ADC_SQR3_SQ17_3                      (0x08UL << ADC_SQR3_SQ17_Pos)      /*!< 0x00800000 */
#define ADC_SQR3_SQ17_4                      (0x10UL << ADC_SQR3_SQ17_Pos)      /*!< 0x01000000 */

#define ADC_SQR3_SQ18_Pos                    (25U)                             
#define ADC_SQR3_SQ18_Msk                    (0x1FUL << ADC_SQR3_SQ18_Pos)      /*!< 0x3E000000 */
#define ADC_SQR3_SQ18                        ADC_SQR3_SQ18_Msk                 /*!< ADC group regular sequencer rank 18 */
#define ADC_SQR3_SQ18_0                      (0x01UL << ADC_SQR3_SQ18_Pos)      /*!< 0x02000000 */
#define ADC_SQR3_SQ18_1                      (0x02UL << ADC_SQR3_SQ18_Pos)      /*!< 0x04000000 */
#define ADC_SQR3_SQ18_2                      (0x04UL << ADC_SQR3_SQ18_Pos)      /*!< 0x08000000 */
#define ADC_SQR3_SQ18_3                      (0x08UL << ADC_SQR3_SQ18_Pos)      /*!< 0x10000000 */
#define ADC_SQR3_SQ18_4                      (0x10UL << ADC_SQR3_SQ18_Pos)      /*!< 0x20000000 */

/*******************  Bit definition for ADC_SQR4 register  *******************/
#define ADC_SQR4_SQ7_Pos                     (0U)                              
#define ADC_SQR4_SQ7_Msk                     (0x1FUL << ADC_SQR4_SQ7_Pos)       /*!< 0x0000001F */
#define ADC_SQR4_SQ7                         ADC_SQR4_SQ7_Msk                  /*!< ADC group regular sequencer rank 7 */
#define ADC_SQR4_SQ7_0                       (0x01UL << ADC_SQR4_SQ7_Pos)       /*!< 0x00000001 */
#define ADC_SQR4_SQ7_1                       (0x02UL << ADC_SQR4_SQ7_Pos)       /*!< 0x00000002 */
#define ADC_SQR4_SQ7_2                       (0x04UL << ADC_SQR4_SQ7_Pos)       /*!< 0x00000004 */
#define ADC_SQR4_SQ7_3                       (0x08UL << ADC_SQR4_SQ7_Pos)       /*!< 0x00000008 */
#define ADC_SQR4_SQ7_4                       (0x10UL << ADC_SQR4_SQ7_Pos)       /*!< 0x00000010 */

#define ADC_SQR4_SQ8_Pos                     (5U)                              
#define ADC_SQR4_SQ8_Msk                     (0x1FUL << ADC_SQR4_SQ8_Pos)       /*!< 0x000003E0 */
#define ADC_SQR4_SQ8                         ADC_SQR4_SQ8_Msk                  /*!< ADC group regular sequencer rank 8 */
#define ADC_SQR4_SQ8_0                       (0x01UL << ADC_SQR4_SQ8_Pos)       /*!< 0x00000020 */
#define ADC_SQR4_SQ8_1                       (0x02UL << ADC_SQR4_SQ8_Pos)       /*!< 0x00000040 */
#define ADC_SQR4_SQ8_2                       (0x04UL << ADC_SQR4_SQ8_Pos)       /*!< 0x00000080 */
#define ADC_SQR4_SQ8_3                       (0x08UL << ADC_SQR4_SQ8_Pos)       /*!< 0x00000100 */
#define ADC_SQR4_SQ8_4                       (0x10UL << ADC_SQR4_SQ8_Pos)       /*!< 0x00000200 */

#define ADC_SQR4_SQ9_Pos                     (10U)                             
#define ADC_SQR4_SQ9_Msk                     (0x1FUL << ADC_SQR4_SQ9_Pos)       /*!< 0x00007C00 */
#define ADC_SQR4_SQ9                         ADC_SQR4_SQ9_Msk                  /*!< ADC group regular sequencer rank 9 */
#define ADC_SQR4_SQ9_0                       (0x01UL << ADC_SQR4_SQ9_Pos)       /*!< 0x00000400 */
#define ADC_SQR4_SQ9_1                       (0x02UL << ADC_SQR4_SQ9_Pos)       /*!< 0x00000800 */
#define ADC_SQR4_SQ9_2                       (0x04UL << ADC_SQR4_SQ9_Pos)       /*!< 0x00001000 */
#define ADC_SQR4_SQ9_3                       (0x08UL << ADC_SQR4_SQ9_Pos)       /*!< 0x00002000 */
#define ADC_SQR4_SQ9_4                       (0x10UL << ADC_SQR4_SQ9_Pos)       /*!< 0x00004000 */

#define ADC_SQR4_SQ10_Pos                    (15U)                             
#define ADC_SQR4_SQ10_Msk                    (0x1FUL << ADC_SQR4_SQ10_Pos)      /*!< 0x000F8000 */
#define ADC_SQR4_SQ10                        ADC_SQR4_SQ10_Msk                 /*!< ADC group regular sequencer rank 10 */
#define ADC_SQR4_SQ10_0                      (0x01UL << ADC_SQR4_SQ10_Pos)      /*!< 0x00008000 */
#define ADC_SQR4_SQ10_1                      (0x02UL << ADC_SQR4_SQ10_Pos)      /*!< 0x00010000 */
#define ADC_SQR4_SQ10_2                      (0x04UL << ADC_SQR4_SQ10_Pos)      /*!< 0x00020000 */
#define ADC_SQR4_SQ10_3                      (0x08UL << ADC_SQR4_SQ10_Pos)      /*!< 0x00040000 */
#define ADC_SQR4_SQ10_4                      (0x10UL << ADC_SQR4_SQ10_Pos)      /*!< 0x00080000 */

#define ADC_SQR4_SQ11_Pos                    (20U)                             
#define ADC_SQR4_SQ11_Msk                    (0x1FUL << ADC_SQR4_SQ11_Pos)      /*!< 0x01F00000 */
#define ADC_SQR4_SQ11                        ADC_SQR4_SQ11_Msk                 /*!< ADC group regular sequencer rank 11 */
#define ADC_SQR4_SQ11_0                      (0x01UL << ADC_SQR4_SQ11_Pos)      /*!< 0x00100000 */
#define ADC_SQR4_SQ11_1                      (0x02UL << ADC_SQR4_SQ11_Pos)      /*!< 0x00200000 */
#define ADC_SQR4_SQ11_2                      (0x04UL << ADC_SQR4_SQ11_Pos)      /*!< 0x00400000 */
#define ADC_SQR4_SQ11_3                      (0x08UL << ADC_SQR4_SQ11_Pos)      /*!< 0x00800000 */
#define ADC_SQR4_SQ11_4                      (0x10UL << ADC_SQR4_SQ11_Pos)      /*!< 0x01000000 */

#define ADC_SQR4_SQ12_Pos                    (25U)                             
#define ADC_SQR4_SQ12_Msk                    (0x1FUL << ADC_SQR4_SQ12_Pos)      /*!< 0x3E000000 */
#define ADC_SQR4_SQ12                        ADC_SQR4_SQ12_Msk                 /*!< ADC group regular sequencer rank 12 */
#define ADC_SQR4_SQ12_0                      (0x01UL << ADC_SQR4_SQ12_Pos)      /*!< 0x02000000 */
#define ADC_SQR4_SQ12_1                      (0x02UL << ADC_SQR4_SQ12_Pos)      /*!< 0x04000000 */
#define ADC_SQR4_SQ12_2                      (0x04UL << ADC_SQR4_SQ12_Pos)      /*!< 0x08000000 */
#define ADC_SQR4_SQ12_3                      (0x08UL << ADC_SQR4_SQ12_Pos)      /*!< 0x10000000 */
#define ADC_SQR4_SQ12_4                      (0x10UL << ADC_SQR4_SQ12_Pos)      /*!< 0x20000000 */

/*******************  Bit definition for ADC_SQR5 register  *******************/
#define ADC_SQR5_SQ1_Pos                     (0U)                              
#define ADC_SQR5_SQ1_Msk                     (0x1FUL << ADC_SQR5_SQ1_Pos)       /*!< 0x0000001F */
#define ADC_SQR5_SQ1                         ADC_SQR5_SQ1_Msk                  /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR5_SQ1_0                       (0x01UL << ADC_SQR5_SQ1_Pos)       /*!< 0x00000001 */
#define ADC_SQR5_SQ1_1                       (0x02UL << ADC_SQR5_SQ1_Pos)       /*!< 0x00000002 */
#define ADC_SQR5_SQ1_2                       (0x04UL << ADC_SQR5_SQ1_Pos)       /*!< 0x00000004 */
#define ADC_SQR5_SQ1_3                       (0x08UL << ADC_SQR5_SQ1_Pos)       /*!< 0x00000008 */
#define ADC_SQR5_SQ1_4                       (0x10UL << ADC_SQR5_SQ1_Pos)       /*!< 0x00000010 */

#define ADC_SQR5_SQ2_Pos                     (5U)                              
#define ADC_SQR5_SQ2_Msk                     (0x1FUL << ADC_SQR5_SQ2_Pos)       /*!< 0x000003E0 */
#define ADC_SQR5_SQ2                         ADC_SQR5_SQ2_Msk                  /*!< ADC group regular sequencer rank 2 */
#define ADC_SQR5_SQ2_0                       (0x01UL << ADC_SQR5_SQ2_Pos)       /*!< 0x00000020 */
#define ADC_SQR5_SQ2_1                       (0x02UL << ADC_SQR5_SQ2_Pos)       /*!< 0x00000040 */
#define ADC_SQR5_SQ2_2                       (0x04UL << ADC_SQR5_SQ2_Pos)       /*!< 0x00000080 */
#define ADC_SQR5_SQ2_3                       (0x08UL << ADC_SQR5_SQ2_Pos)       /*!< 0x00000100 */
#define ADC_SQR5_SQ2_4                       (0x10UL << ADC_SQR5_SQ2_Pos)       /*!< 0x00000200 */

#define ADC_SQR5_SQ3_Pos                     (10U)                             
#define ADC_SQR5_SQ3_Msk                     (0x1FUL << ADC_SQR5_SQ3_Pos)       /*!< 0x00007C00 */
#define ADC_SQR5_SQ3                         ADC_SQR5_SQ3_Msk                  /*!< ADC group regular sequencer rank 3 */
#define ADC_SQR5_SQ3_0                       (0x01UL << ADC_SQR5_SQ3_Pos)       /*!< 0x00000400 */
#define ADC_SQR5_SQ3_1                       (0x02UL << ADC_SQR5_SQ3_Pos)       /*!< 0x00000800 */
#define ADC_SQR5_SQ3_2                       (0x04UL << ADC_SQR5_SQ3_Pos)       /*!< 0x00001000 */
#define ADC_SQR5_SQ3_3                       (0x08UL << ADC_SQR5_SQ3_Pos)       /*!< 0x00002000 */
#define ADC_SQR5_SQ3_4                       (0x10UL << ADC_SQR5_SQ3_Pos)       /*!< 0x00004000 */

#define ADC_SQR5_SQ4_Pos                     (15U)                             
#define ADC_SQR5_SQ4_Msk                     (0x1FUL << ADC_SQR5_SQ4_Pos)       /*!< 0x000F8000 */
#define ADC_SQR5_SQ4                         ADC_SQR5_SQ4_Msk                  /*!< ADC group regular sequencer rank 4 */
#define ADC_SQR5_SQ4_0                       (0x01UL << ADC_SQR5_SQ4_Pos)       /*!< 0x00008000 */
#define ADC_SQR5_SQ4_1                       (0x02UL << ADC_SQR5_SQ4_Pos)       /*!< 0x00010000 */
#define ADC_SQR5_SQ4_2                       (0x04UL << ADC_SQR5_SQ4_Pos)       /*!< 0x00020000 */
#define ADC_SQR5_SQ4_3                       (0x08UL << ADC_SQR5_SQ4_Pos)       /*!< 0x00040000 */
#define ADC_SQR5_SQ4_4                       (0x10UL << ADC_SQR5_SQ4_Pos)       /*!< 0x00080000 */

#define ADC_SQR5_SQ5_Pos                     (20U)                             
#define ADC_SQR5_SQ5_Msk                     (0x1FUL << ADC_SQR5_SQ5_Pos)       /*!< 0x01F00000 */
#define ADC_SQR5_SQ5                         ADC_SQR5_SQ5_Msk                  /*!< ADC group regular sequencer rank 5 */
#define ADC_SQR5_SQ5_0                       (0x01UL << ADC_SQR5_SQ5_Pos)       /*!< 0x00100000 */
#define ADC_SQR5_SQ5_1                       (0x02UL << ADC_SQR5_SQ5_Pos)       /*!< 0x00200000 */
#define ADC_SQR5_SQ5_2                       (0x04UL << ADC_SQR5_SQ5_Pos)       /*!< 0x00400000 */
#define ADC_SQR5_SQ5_3                       (0x08UL << ADC_SQR5_SQ5_Pos)       /*!< 0x00800000 */
#define ADC_SQR5_SQ5_4                       (0x10UL << ADC_SQR5_SQ5_Pos)       /*!< 0x01000000 */

#define ADC_SQR5_SQ6_Pos                     (25U)                             
#define ADC_SQR5_SQ6_Msk                     (0x1FUL << ADC_SQR5_SQ6_Pos)       /*!< 0x3E000000 */
#define ADC_SQR5_SQ6                         ADC_SQR5_SQ6_Msk                  /*!< ADC group regular sequencer rank 6 */
#define ADC_SQR5_SQ6_0                       (0x01UL << ADC_SQR5_SQ6_Pos)       /*!< 0x02000000 */
#define ADC_SQR5_SQ6_1                       (0x02UL << ADC_SQR5_SQ6_Pos)       /*!< 0x04000000 */
#define ADC_SQR5_SQ6_2                       (0x04UL << ADC_SQR5_SQ6_Pos)       /*!< 0x08000000 */
#define ADC_SQR5_SQ6_3                       (0x08UL << ADC_SQR5_SQ6_Pos)       /*!< 0x10000000 */
#define ADC_SQR5_SQ6_4                       (0x10UL << ADC_SQR5_SQ6_Pos)       /*!< 0x20000000 */


/*******************  Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ1_Pos                    (0U)                              
#define ADC_JSQR_JSQ1_Msk                    (0x1FUL << ADC_JSQR_JSQ1_Pos)      /*!< 0x0000001F */
#define ADC_JSQR_JSQ1                        ADC_JSQR_JSQ1_Msk                 /*!< ADC group injected sequencer rank 1 */
#define ADC_JSQR_JSQ1_0                      (0x01UL << ADC_JSQR_JSQ1_Pos)      /*!< 0x00000001 */
#define ADC_JSQR_JSQ1_1                      (0x02UL << ADC_JSQR_JSQ1_Pos)      /*!< 0x00000002 */
#define ADC_JSQR_JSQ1_2                      (0x04UL << ADC_JSQR_JSQ1_Pos)      /*!< 0x00000004 */
#define ADC_JSQR_JSQ1_3                      (0x08UL << ADC_JSQR_JSQ1_Pos)      /*!< 0x00000008 */
#define ADC_JSQR_JSQ1_4                      (0x10UL << ADC_JSQR_JSQ1_Pos)      /*!< 0x00000010 */

#define ADC_JSQR_JSQ2_Pos                    (5U)                              
#define ADC_JSQR_JSQ2_Msk                    (0x1FUL << ADC_JSQR_JSQ2_Pos)      /*!< 0x000003E0 */
#define ADC_JSQR_JSQ2                        ADC_JSQR_JSQ2_Msk                 /*!< ADC group injected sequencer rank 2 */
#define ADC_JSQR_JSQ2_0                      (0x01UL << ADC_JSQR_JSQ2_Pos)      /*!< 0x00000020 */
#define ADC_JSQR_JSQ2_1                      (0x02UL << ADC_JSQR_JSQ2_Pos)      /*!< 0x00000040 */
#define ADC_JSQR_JSQ2_2                      (0x04UL << ADC_JSQR_JSQ2_Pos)      /*!< 0x00000080 */
#define ADC_JSQR_JSQ2_3                      (0x08UL << ADC_JSQR_JSQ2_Pos)      /*!< 0x00000100 */
#define ADC_JSQR_JSQ2_4                      (0x10UL << ADC_JSQR_JSQ2_Pos)      /*!< 0x00000200 */

#define ADC_JSQR_JSQ3_Pos                    (10U)                             
#define ADC_JSQR_JSQ3_Msk                    (0x1FUL << ADC_JSQR_JSQ3_Pos)      /*!< 0x00007C00 */
#define ADC_JSQR_JSQ3                        ADC_JSQR_JSQ3_Msk                 /*!< ADC group injected sequencer rank 3 */
#define ADC_JSQR_JSQ3_0                      (0x01UL << ADC_JSQR_JSQ3_Pos)      /*!< 0x00000400 */
#define ADC_JSQR_JSQ3_1                      (0x02UL << ADC_JSQR_JSQ3_Pos)      /*!< 0x00000800 */
#define ADC_JSQR_JSQ3_2                      (0x04UL << ADC_JSQR_JSQ3_Pos)      /*!< 0x00001000 */
#define ADC_JSQR_JSQ3_3                      (0x08UL << ADC_JSQR_JSQ3_Pos)      /*!< 0x00002000 */
#define ADC_JSQR_JSQ3_4                      (0x10UL << ADC_JSQR_JSQ3_Pos)      /*!< 0x00004000 */

#define ADC_JSQR_JSQ4_Pos                    (15U)                             
#define ADC_JSQR_JSQ4_Msk                    (0x1FUL << ADC_JSQR_JSQ4_Pos)      /*!< 0x000F8000 */
#define ADC_JSQR_JSQ4                        ADC_JSQR_JSQ4_Msk                 /*!< ADC group injected sequencer rank 4 */
#define ADC_JSQR_JSQ4_0                      (0x01UL << ADC_JSQR_JSQ4_Pos)      /*!< 0x00008000 */
#define ADC_JSQR_JSQ4_1                      (0x02UL << ADC_JSQR_JSQ4_Pos)      /*!< 0x00010000 */
#define ADC_JSQR_JSQ4_2                      (0x04UL << ADC_JSQR_JSQ4_Pos)      /*!< 0x00020000 */
#define ADC_JSQR_JSQ4_3                      (0x08UL << ADC_JSQR_JSQ4_Pos)      /*!< 0x00040000 */
#define ADC_JSQR_JSQ4_4                      (0x10UL << ADC_JSQR_JSQ4_Pos)      /*!< 0x00080000 */

#define ADC_JSQR_JL_Pos                      (20U)                             
#define ADC_JSQR_JL_Msk                      (0x3UL << ADC_JSQR_JL_Pos)         /*!< 0x00300000 */
#define ADC_JSQR_JL                          ADC_JSQR_JL_Msk                   /*!< ADC group injected sequencer scan length */
#define ADC_JSQR_JL_0                        (0x1UL << ADC_JSQR_JL_Pos)         /*!< 0x00100000 */
#define ADC_JSQR_JL_1                        (0x2UL << ADC_JSQR_JL_Pos)         /*!< 0x00200000 */

/*******************  Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA_Pos                   (0U)                              
#define ADC_JDR1_JDATA_Msk                   (0xFFFFUL << ADC_JDR1_JDATA_Pos)   /*!< 0x0000FFFF */
#define ADC_JDR1_JDATA                       ADC_JDR1_JDATA_Msk                /*!< ADC group injected sequencer rank 1 conversion data */

/*******************  Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA_Pos                   (0U)                              
#define ADC_JDR2_JDATA_Msk                   (0xFFFFUL << ADC_JDR2_JDATA_Pos)   /*!< 0x0000FFFF */
#define ADC_JDR2_JDATA                       ADC_JDR2_JDATA_Msk                /*!< ADC group injected sequencer rank 2 conversion data */

/*******************  Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA_Pos                   (0U)                              
#define ADC_JDR3_JDATA_Msk                   (0xFFFFUL << ADC_JDR3_JDATA_Pos)   /*!< 0x0000FFFF */
#define ADC_JDR3_JDATA                       ADC_JDR3_JDATA_Msk                /*!< ADC group injected sequencer rank 3 conversion data */

/*******************  Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA_Pos                   (0U)                              
#define ADC_JDR4_JDATA_Msk                   (0xFFFFUL << ADC_JDR4_JDATA_Pos)   /*!< 0x0000FFFF */
#define ADC_JDR4_JDATA                       ADC_JDR4_JDATA_Msk                /*!< ADC group injected sequencer rank 4 conversion data */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos                      (0U)                              
#define ADC_DR_DATA_Msk                      (0xFFFFUL << ADC_DR_DATA_Pos)      /*!< 0x0000FFFF */
#define ADC_DR_DATA                          ADC_DR_DATA_Msk                   /*!< ADC group regular conversion data */

/******************  Bit definition for ADC_SMPR0 register  *******************/
#define ADC_SMPR0_SMP30_Pos                  (0U)                              
#define ADC_SMPR0_SMP30_Msk                  (0x7UL << ADC_SMPR0_SMP30_Pos)     /*!< 0x00000007 */
#define ADC_SMPR0_SMP30                      ADC_SMPR0_SMP30_Msk               /*!< ADC channel 30 sampling time selection */
#define ADC_SMPR0_SMP30_0                    (0x1UL << ADC_SMPR0_SMP30_Pos)     /*!< 0x00000001 */
#define ADC_SMPR0_SMP30_1                    (0x2UL << ADC_SMPR0_SMP30_Pos)     /*!< 0x00000002 */
#define ADC_SMPR0_SMP30_2                    (0x4UL << ADC_SMPR0_SMP30_Pos)     /*!< 0x00000004 */
 
#define ADC_SMPR0_SMP31_Pos                  (3U)                              
#define ADC_SMPR0_SMP31_Msk                  (0x7UL << ADC_SMPR0_SMP31_Pos)     /*!< 0x00000038 */
#define ADC_SMPR0_SMP31                      ADC_SMPR0_SMP31_Msk               /*!< ADC channel 31 sampling time selection */
#define ADC_SMPR0_SMP31_0                    (0x1UL << ADC_SMPR0_SMP31_Pos)     /*!< 0x00000008 */
#define ADC_SMPR0_SMP31_1                    (0x2UL << ADC_SMPR0_SMP31_Pos)     /*!< 0x00000010 */
#define ADC_SMPR0_SMP31_2                    (0x4UL << ADC_SMPR0_SMP31_Pos)     /*!< 0x00000020 */

/*******************  Bit definition for ADC_CSR register  ********************/
#define ADC_CSR_AWD1_Pos                     (0U)                              
#define ADC_CSR_AWD1_Msk                     (0x1UL << ADC_CSR_AWD1_Pos)        /*!< 0x00000001 */
#define ADC_CSR_AWD1                         ADC_CSR_AWD1_Msk                  /*!< ADC multimode master analog watchdog 1 flag */
#define ADC_CSR_EOCS1_Pos                    (1U)                              
#define ADC_CSR_EOCS1_Msk                    (0x1UL << ADC_CSR_EOCS1_Pos)       /*!< 0x00000002 */
#define ADC_CSR_EOCS1                        ADC_CSR_EOCS1_Msk                 /*!< ADC multimode master group regular end of unitary conversion or end of sequence conversions flag */
#define ADC_CSR_JEOS1_Pos                    (2U)                              
#define ADC_CSR_JEOS1_Msk                    (0x1UL << ADC_CSR_JEOS1_Pos)       /*!< 0x00000004 */
#define ADC_CSR_JEOS1                        ADC_CSR_JEOS1_Msk                 /*!< ADC multimode master group injected end of sequence conversions flag */
#define ADC_CSR_JSTRT1_Pos                   (3U)                              
#define ADC_CSR_JSTRT1_Msk                   (0x1UL << ADC_CSR_JSTRT1_Pos)      /*!< 0x00000008 */
#define ADC_CSR_JSTRT1                       ADC_CSR_JSTRT1_Msk                /*!< ADC multimode master group injected conversion start flag */
#define ADC_CSR_STRT1_Pos                    (4U)                              
#define ADC_CSR_STRT1_Msk                    (0x1UL << ADC_CSR_STRT1_Pos)       /*!< 0x00000010 */
#define ADC_CSR_STRT1                        ADC_CSR_STRT1_Msk                 /*!< ADC multimode master group regular conversion start flag */
#define ADC_CSR_OVR1_Pos                     (5U)                              
#define ADC_CSR_OVR1_Msk                     (0x1UL << ADC_CSR_OVR1_Pos)        /*!< 0x00000020 */
#define ADC_CSR_OVR1                         ADC_CSR_OVR1_Msk                  /*!< ADC multimode master group regular overrun flag */
#define ADC_CSR_ADONS1_Pos                   (6U)                              
#define ADC_CSR_ADONS1_Msk                   (0x1UL << ADC_CSR_ADONS1_Pos)      /*!< 0x00000040 */
#define ADC_CSR_ADONS1                       ADC_CSR_ADONS1_Msk                /*!< ADC multimode master ready flag */

/* Legacy defines */
#define  ADC_CSR_EOC1                        (ADC_CSR_EOCS1)
#define  ADC_CSR_JEOC1                       (ADC_CSR_JEOS1)

/*******************  Bit definition for ADC_CCR register  ********************/
#define ADC_CCR_ADCPRE_Pos                   (16U)                             
#define ADC_CCR_ADCPRE_Msk                   (0x3UL << ADC_CCR_ADCPRE_Pos)      /*!< 0x00030000 */
#define ADC_CCR_ADCPRE                       ADC_CCR_ADCPRE_Msk                /*!< ADC clock source asynchronous prescaler */
#define ADC_CCR_ADCPRE_0                     (0x1UL << ADC_CCR_ADCPRE_Pos)      /*!< 0x00010000 */
#define ADC_CCR_ADCPRE_1                     (0x2UL << ADC_CCR_ADCPRE_Pos)      /*!< 0x00020000 */
#define ADC_CCR_TSVREFE_Pos                  (23U)                             
#define ADC_CCR_TSVREFE_Msk                  (0x1UL << ADC_CCR_TSVREFE_Pos)     /*!< 0x00800000 */
#define ADC_CCR_TSVREFE                      ADC_CCR_TSVREFE_Msk               /*!< ADC internal path to VrefInt and temperature sensor enable */

/******************************************************************************/
/*                                                                            */
/*                      Analog Comparators (COMP)                             */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for COMP_CSR register  ********************/
#define COMP_CSR_10KPU                      (0x00000001U)                      /*!< Comparator 1 input plus 10K pull-up resistor */
#define COMP_CSR_400KPU                     (0x00000002U)                      /*!< Comparator 1 input plus 400K pull-up resistor */
#define COMP_CSR_10KPD                      (0x00000004U)                      /*!< Comparator 1 input plus 10K pull-down resistor */
#define COMP_CSR_400KPD                     (0x00000008U)                      /*!< Comparator 1 input plus 400K pull-down resistor */
#define COMP_CSR_CMP1EN_Pos                 (4U)                               
#define COMP_CSR_CMP1EN_Msk                 (0x1UL << COMP_CSR_CMP1EN_Pos)      /*!< 0x00000010 */
#define COMP_CSR_CMP1EN                     COMP_CSR_CMP1EN_Msk                /*!< Comparator 1 enable */
#define COMP_CSR_CMP1OUT_Pos                (7U)                               
#define COMP_CSR_CMP1OUT_Msk                (0x1UL << COMP_CSR_CMP1OUT_Pos)     /*!< 0x00000080 */
#define COMP_CSR_CMP1OUT                    COMP_CSR_CMP1OUT_Msk               /*!< Comparator 1 output level */
#define COMP_CSR_SPEED_Pos                  (12U)                              
#define COMP_CSR_SPEED_Msk                  (0x1UL << COMP_CSR_SPEED_Pos)       /*!< 0x00001000 */
#define COMP_CSR_SPEED                      COMP_CSR_SPEED_Msk                 /*!< Comparator 2 power mode */
#define COMP_CSR_CMP2OUT_Pos                (13U)                              
#define COMP_CSR_CMP2OUT_Msk                (0x1UL << COMP_CSR_CMP2OUT_Pos)     /*!< 0x00002000 */
#define COMP_CSR_CMP2OUT                    COMP_CSR_CMP2OUT_Msk               /*!< Comparator 2 output level */

#define COMP_CSR_WNDWE_Pos                  (17U)                              
#define COMP_CSR_WNDWE_Msk                  (0x1UL << COMP_CSR_WNDWE_Pos)       /*!< 0x00020000 */
#define COMP_CSR_WNDWE                      COMP_CSR_WNDWE_Msk                 /*!< Pair of comparators window mode. Bit intended to be used with COMP common instance (COMP_Common_TypeDef)  */

#define COMP_CSR_INSEL_Pos                  (18U)                              
#define COMP_CSR_INSEL_Msk                  (0x7UL << COMP_CSR_INSEL_Pos)       /*!< 0x001C0000 */
#define COMP_CSR_INSEL                      COMP_CSR_INSEL_Msk                 /*!< Comparator 2 input minus selection */
#define COMP_CSR_INSEL_0                    (0x1UL << COMP_CSR_INSEL_Pos)       /*!< 0x00040000 */
#define COMP_CSR_INSEL_1                    (0x2UL << COMP_CSR_INSEL_Pos)       /*!< 0x00080000 */
#define COMP_CSR_INSEL_2                    (0x4UL << COMP_CSR_INSEL_Pos)       /*!< 0x00100000 */
#define COMP_CSR_OUTSEL_Pos                 (21U)                              
#define COMP_CSR_OUTSEL_Msk                 (0x7UL << COMP_CSR_OUTSEL_Pos)      /*!< 0x00E00000 */
#define COMP_CSR_OUTSEL                     COMP_CSR_OUTSEL_Msk                /*!< Comparator 2 output redirection */
#define COMP_CSR_OUTSEL_0                   (0x1UL << COMP_CSR_OUTSEL_Pos)      /*!< 0x00200000 */
#define COMP_CSR_OUTSEL_1                   (0x2UL << COMP_CSR_OUTSEL_Pos)      /*!< 0x00400000 */
#define COMP_CSR_OUTSEL_2                   (0x4UL << COMP_CSR_OUTSEL_Pos)      /*!< 0x00800000 */

/* Bits present in COMP register but not related to comparator */
/* (or partially related to comparator, in addition to other peripherals) */
#define COMP_CSR_SW1_Pos                    (5U)                               
#define COMP_CSR_SW1_Msk                    (0x1UL << COMP_CSR_SW1_Pos)         /*!< 0x00000020 */
#define COMP_CSR_SW1                        COMP_CSR_SW1_Msk                   /*!< SW1 analog switch enable */
#define COMP_CSR_VREFOUTEN_Pos              (16U)                              
#define COMP_CSR_VREFOUTEN_Msk              (0x1UL << COMP_CSR_VREFOUTEN_Pos)   /*!< 0x00010000 */
#define COMP_CSR_VREFOUTEN                  COMP_CSR_VREFOUTEN_Msk             /*!< VrefInt output enable on GPIO group 3 */

#define COMP_CSR_FCH3_Pos                   (26U)                              
#define COMP_CSR_FCH3_Msk                   (0x1UL << COMP_CSR_FCH3_Pos)        /*!< 0x04000000 */
#define COMP_CSR_FCH3                       COMP_CSR_FCH3_Msk                  /*!< Bit 26 */
#define COMP_CSR_FCH8_Pos                   (27U)                              
#define COMP_CSR_FCH8_Msk                   (0x1UL << COMP_CSR_FCH8_Pos)        /*!< 0x08000000 */
#define COMP_CSR_FCH8                       COMP_CSR_FCH8_Msk                  /*!< Bit 27 */
#define COMP_CSR_RCH13_Pos                  (28U)                              
#define COMP_CSR_RCH13_Msk                  (0x1UL << COMP_CSR_RCH13_Pos)       /*!< 0x10000000 */
#define COMP_CSR_RCH13                      COMP_CSR_RCH13_Msk                 /*!< Bit 28 */

#define COMP_CSR_CAIE_Pos                   (29U)                              
#define COMP_CSR_CAIE_Msk                   (0x1UL << COMP_CSR_CAIE_Pos)        /*!< 0x20000000 */
#define COMP_CSR_CAIE                       COMP_CSR_CAIE_Msk                  /*!< Bit 29 */
#define COMP_CSR_CAIF_Pos                   (30U)                              
#define COMP_CSR_CAIF_Msk                   (0x1UL << COMP_CSR_CAIF_Pos)        /*!< 0x40000000 */
#define COMP_CSR_CAIF                       COMP_CSR_CAIF_Msk                  /*!< Bit 30 */
#define COMP_CSR_TSUSP_Pos                  (31U)                              
#define COMP_CSR_TSUSP_Msk                  (0x1UL << COMP_CSR_TSUSP_Pos)       /*!< 0x80000000 */
#define COMP_CSR_TSUSP                      COMP_CSR_TSUSP_Msk                 /*!< Bit 31 */

/******************************************************************************/
/*                                                                            */
/*                         Operational Amplifier (OPAMP)                      */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for OPAMP_CSR register  ******************/
#define OPAMP_CSR_OPA1PD_Pos                  (0U)                             
#define OPAMP_CSR_OPA1PD_Msk                  (0x1UL << OPAMP_CSR_OPA1PD_Pos)   /*!< 0x00000001 */
#define OPAMP_CSR_OPA1PD                      OPAMP_CSR_OPA1PD_Msk             /*!< OPAMP1 disable */
#define OPAMP_CSR_S3SEL1_Pos                  (1U)                             
#define OPAMP_CSR_S3SEL1_Msk                  (0x1UL << OPAMP_CSR_S3SEL1_Pos)   /*!< 0x00000002 */
#define OPAMP_CSR_S3SEL1                      OPAMP_CSR_S3SEL1_Msk             /*!< Switch 3 for OPAMP1 Enable */
#define OPAMP_CSR_S4SEL1_Pos                  (2U)                             
#define OPAMP_CSR_S4SEL1_Msk                  (0x1UL << OPAMP_CSR_S4SEL1_Pos)   /*!< 0x00000004 */
#define OPAMP_CSR_S4SEL1                      OPAMP_CSR_S4SEL1_Msk             /*!< Switch 4 for OPAMP1 Enable */
#define OPAMP_CSR_S5SEL1_Pos                  (3U)                             
#define OPAMP_CSR_S5SEL1_Msk                  (0x1UL << OPAMP_CSR_S5SEL1_Pos)   /*!< 0x00000008 */
#define OPAMP_CSR_S5SEL1                      OPAMP_CSR_S5SEL1_Msk             /*!< Switch 5 for OPAMP1 Enable */
#define OPAMP_CSR_S6SEL1_Pos                  (4U)                             
#define OPAMP_CSR_S6SEL1_Msk                  (0x1UL << OPAMP_CSR_S6SEL1_Pos)   /*!< 0x00000010 */
#define OPAMP_CSR_S6SEL1                      OPAMP_CSR_S6SEL1_Msk             /*!< Switch 6 for OPAMP1 Enable */
#define OPAMP_CSR_OPA1CAL_L_Pos               (5U)                             
#define OPAMP_CSR_OPA1CAL_L_Msk               (0x1UL << OPAMP_CSR_OPA1CAL_L_Pos) /*!< 0x00000020 */
#define OPAMP_CSR_OPA1CAL_L                   OPAMP_CSR_OPA1CAL_L_Msk          /*!< OPAMP1 Offset calibration for P differential pair */
#define OPAMP_CSR_OPA1CAL_H_Pos               (6U)                             
#define OPAMP_CSR_OPA1CAL_H_Msk               (0x1UL << OPAMP_CSR_OPA1CAL_H_Pos) /*!< 0x00000040 */
#define OPAMP_CSR_OPA1CAL_H                   OPAMP_CSR_OPA1CAL_H_Msk          /*!< OPAMP1 Offset calibration for N differential pair */
#define OPAMP_CSR_OPA1LPM_Pos                 (7U)                             
#define OPAMP_CSR_OPA1LPM_Msk                 (0x1UL << OPAMP_CSR_OPA1LPM_Pos)  /*!< 0x00000080 */
#define OPAMP_CSR_OPA1LPM                     OPAMP_CSR_OPA1LPM_Msk            /*!< OPAMP1 Low power enable */
#define OPAMP_CSR_OPA2PD_Pos                  (8U)                             
#define OPAMP_CSR_OPA2PD_Msk                  (0x1UL << OPAMP_CSR_OPA2PD_Pos)   /*!< 0x00000100 */
#define OPAMP_CSR_OPA2PD                      OPAMP_CSR_OPA2PD_Msk             /*!< OPAMP2 disable */
#define OPAMP_CSR_S3SEL2_Pos                  (9U)                             
#define OPAMP_CSR_S3SEL2_Msk                  (0x1UL << OPAMP_CSR_S3SEL2_Pos)   /*!< 0x00000200 */
#define OPAMP_CSR_S3SEL2                      OPAMP_CSR_S3SEL2_Msk             /*!< Switch 3 for OPAMP2 Enable */
#define OPAMP_CSR_S4SEL2_Pos                  (10U)                            
#define OPAMP_CSR_S4SEL2_Msk                  (0x1UL << OPAMP_CSR_S4SEL2_Pos)   /*!< 0x00000400 */
#define OPAMP_CSR_S4SEL2                      OPAMP_CSR_S4SEL2_Msk             /*!< Switch 4 for OPAMP2 Enable */
#define OPAMP_CSR_S5SEL2_Pos                  (11U)                            
#define OPAMP_CSR_S5SEL2_Msk                  (0x1UL << OPAMP_CSR_S5SEL2_Pos)   /*!< 0x00000800 */
#define OPAMP_CSR_S5SEL2                      OPAMP_CSR_S5SEL2_Msk             /*!< Switch 5 for OPAMP2 Enable */
#define OPAMP_CSR_S6SEL2_Pos                  (12U)                            
#define OPAMP_CSR_S6SEL2_Msk                  (0x1UL << OPAMP_CSR_S6SEL2_Pos)   /*!< 0x00001000 */
#define OPAMP_CSR_S6SEL2                      OPAMP_CSR_S6SEL2_Msk             /*!< Switch 6 for OPAMP2 Enable */
#define OPAMP_CSR_OPA2CAL_L_Pos               (13U)                            
#define OPAMP_CSR_OPA2CAL_L_Msk               (0x1UL << OPAMP_CSR_OPA2CAL_L_Pos) /*!< 0x00002000 */
#define OPAMP_CSR_OPA2CAL_L                   OPAMP_CSR_OPA2CAL_L_Msk          /*!< OPAMP2 Offset calibration for P differential pair */
#define OPAMP_CSR_OPA2CAL_H_Pos               (14U)                            
#define OPAMP_CSR_OPA2CAL_H_Msk               (0x1UL << OPAMP_CSR_OPA2CAL_H_Pos) /*!< 0x00004000 */
#define OPAMP_CSR_OPA2CAL_H                   OPAMP_CSR_OPA2CAL_H_Msk          /*!< OPAMP2 Offset calibration for N differential pair */
#define OPAMP_CSR_OPA2LPM_Pos                 (15U)                            
#define OPAMP_CSR_OPA2LPM_Msk                 (0x1UL << OPAMP_CSR_OPA2LPM_Pos)  /*!< 0x00008000 */
#define OPAMP_CSR_OPA2LPM                     OPAMP_CSR_OPA2LPM_Msk            /*!< OPAMP2 Low power enable */
#define OPAMP_CSR_ANAWSEL1_Pos                (24U)                            
#define OPAMP_CSR_ANAWSEL1_Msk                (0x1UL << OPAMP_CSR_ANAWSEL1_Pos) /*!< 0x01000000 */
#define OPAMP_CSR_ANAWSEL1                    OPAMP_CSR_ANAWSEL1_Msk           /*!< Switch ANA Enable for OPAMP1 */ 
#define OPAMP_CSR_ANAWSEL2_Pos                (25U)                            
#define OPAMP_CSR_ANAWSEL2_Msk                (0x1UL << OPAMP_CSR_ANAWSEL2_Pos) /*!< 0x02000000 */
#define OPAMP_CSR_ANAWSEL2                    OPAMP_CSR_ANAWSEL2_Msk           /*!< Switch ANA Enable for OPAMP2 */
#define OPAMP_CSR_S7SEL2_Pos                  (27U)                            
#define OPAMP_CSR_S7SEL2_Msk                  (0x1UL << OPAMP_CSR_S7SEL2_Pos)   /*!< 0x08000000 */
#define OPAMP_CSR_S7SEL2                      OPAMP_CSR_S7SEL2_Msk             /*!< Switch 7 for OPAMP2 Enable */
#define OPAMP_CSR_AOP_RANGE_Pos               (28U)                            
#define OPAMP_CSR_AOP_RANGE_Msk               (0x1UL << OPAMP_CSR_AOP_RANGE_Pos) /*!< 0x10000000 */
#define OPAMP_CSR_AOP_RANGE                   OPAMP_CSR_AOP_RANGE_Msk          /*!< Common to several OPAMP instances: Operational amplifier voltage supply range. Bit intended to be used with OPAMP common instance (OPAMP_Common_TypeDef) */
#define OPAMP_CSR_OPA1CALOUT_Pos              (29U)                            
#define OPAMP_CSR_OPA1CALOUT_Msk              (0x1UL << OPAMP_CSR_OPA1CALOUT_Pos) /*!< 0x20000000 */
#define OPAMP_CSR_OPA1CALOUT                  OPAMP_CSR_OPA1CALOUT_Msk         /*!< OPAMP1 calibration output */
#define OPAMP_CSR_OPA2CALOUT_Pos              (30U)                            
#define OPAMP_CSR_OPA2CALOUT_Msk              (0x1UL << OPAMP_CSR_OPA2CALOUT_Pos) /*!< 0x40000000 */
#define OPAMP_CSR_OPA2CALOUT                  OPAMP_CSR_OPA2CALOUT_Msk         /*!< OPAMP2 calibration output */

/*******************  Bit definition for OPAMP_OTR register  ******************/
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LOW_Pos (0U)                             
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LOW_Msk (0x1FUL << OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LOW_Pos) /*!< 0x0000001F */
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LOW     OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LOW_Msk /*!< Offset trim for transistors differential pair PMOS of OPAMP1 */
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_HIGH_Pos (5U)                            
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_HIGH_Msk (0x1FUL << OPAMP_OTR_AO1_OPT_OFFSET_TRIM_HIGH_Pos) /*!< 0x000003E0 */
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_HIGH    OPAMP_OTR_AO1_OPT_OFFSET_TRIM_HIGH_Msk /*!< Offset trim for transistors differential pair NMOS of OPAMP1 */
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LOW_Pos (10U)                            
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LOW_Msk (0x1FUL << OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LOW_Pos) /*!< 0x00007C00 */
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LOW     OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LOW_Msk /*!< Offset trim for transistors differential pair PMOS of OPAMP2 */
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_HIGH_Pos (15U)                           
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_HIGH_Msk (0x1FUL << OPAMP_OTR_AO2_OPT_OFFSET_TRIM_HIGH_Pos) /*!< 0x000F8000 */
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_HIGH    OPAMP_OTR_AO2_OPT_OFFSET_TRIM_HIGH_Msk /*!< Offset trim for transistors differential pair NMOS of OPAMP2 */
#define OPAMP_OTR_OT_USER_Pos                 (31U)                            
#define OPAMP_OTR_OT_USER_Msk                 (0x1UL << OPAMP_OTR_OT_USER_Pos)  /*!< 0x80000000 */
#define OPAMP_OTR_OT_USER                     OPAMP_OTR_OT_USER_Msk            /*!< Switch to OPAMP offset user trimmed values */

/*******************  Bit definition for OPAMP_LPOTR register  ****************/
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_LOW_Pos (0U)                          
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_LOW_Msk (0x1FUL << OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_LOW_Pos) /*!< 0x0000001F */
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_LOW  OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_LOW_Msk /*!< Offset trim for transistors differential pair PMOS of OPAMP1 */
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_HIGH_Pos (5U)                         
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_HIGH_Msk (0x1FUL << OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_HIGH_Pos) /*!< 0x000003E0 */
#define OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_HIGH OPAMP_OTR_AO1_OPT_OFFSET_TRIM_LP_HIGH_Msk /*!< Offset trim for transistors differential pair NMOS of OPAMP1 */
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_LOW_Pos (10U)                         
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_LOW_Msk (0x1FUL << OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_LOW_Pos) /*!< 0x00007C00 */
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_LOW  OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_LOW_Msk /*!< Offset trim for transistors differential pair PMOS of OPAMP2 */
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_HIGH_Pos (15U)                        
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_HIGH_Msk (0x1FUL << OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_HIGH_Pos) /*!< 0x000F8000 */
#define OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_HIGH OPAMP_OTR_AO2_OPT_OFFSET_TRIM_LP_HIGH_Msk /*!< Offset trim for transistors differential pair NMOS of OPAMP2 */

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

/******************************************************************************/
/*                                                                            */
/*                    Digital to Analog Converter (DAC)                       */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for DAC_CR register  ********************/
#define DAC_CR_EN1_Pos                      (0U)                               
#define DAC_CR_EN1_Msk                      (0x1UL << DAC_CR_EN1_Pos)           /*!< 0x00000001 */
#define DAC_CR_EN1                          DAC_CR_EN1_Msk                     /*!<DAC channel1 enable */
#define DAC_CR_BOFF1_Pos                    (1U)                               
#define DAC_CR_BOFF1_Msk                    (0x1UL << DAC_CR_BOFF1_Pos)         /*!< 0x00000002 */
#define DAC_CR_BOFF1                        DAC_CR_BOFF1_Msk                   /*!<DAC channel1 output buffer disable */
#define DAC_CR_TEN1_Pos                     (2U)                               
#define DAC_CR_TEN1_Msk                     (0x1UL << DAC_CR_TEN1_Pos)          /*!< 0x00000004 */
#define DAC_CR_TEN1                         DAC_CR_TEN1_Msk                    /*!<DAC channel1 Trigger enable */

#define DAC_CR_TSEL1_Pos                    (3U)                               
#define DAC_CR_TSEL1_Msk                    (0x7UL << DAC_CR_TSEL1_Pos)         /*!< 0x00000038 */
#define DAC_CR_TSEL1                        DAC_CR_TSEL1_Msk                   /*!<TSEL1[2:0] (DAC channel1 Trigger selection) */
#define DAC_CR_TSEL1_0                      (0x1UL << DAC_CR_TSEL1_Pos)         /*!< 0x00000008 */
#define DAC_CR_TSEL1_1                      (0x2UL << DAC_CR_TSEL1_Pos)         /*!< 0x00000010 */
#define DAC_CR_TSEL1_2                      (0x4UL << DAC_CR_TSEL1_Pos)         /*!< 0x00000020 */

#define DAC_CR_WAVE1_Pos                    (6U)                               
#define DAC_CR_WAVE1_Msk                    (0x3UL << DAC_CR_WAVE1_Pos)         /*!< 0x000000C0 */
#define DAC_CR_WAVE1                        DAC_CR_WAVE1_Msk                   /*!<WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
#define DAC_CR_WAVE1_0                      (0x1UL << DAC_CR_WAVE1_Pos)         /*!< 0x00000040 */
#define DAC_CR_WAVE1_1                      (0x2UL << DAC_CR_WAVE1_Pos)         /*!< 0x00000080 */

#define DAC_CR_MAMP1_Pos                    (8U)                               
#define DAC_CR_MAMP1_Msk                    (0xFUL << DAC_CR_MAMP1_Pos)         /*!< 0x00000F00 */
#define DAC_CR_MAMP1                        DAC_CR_MAMP1_Msk                   /*!<MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
#define DAC_CR_MAMP1_0                      (0x1UL << DAC_CR_MAMP1_Pos)         /*!< 0x00000100 */
#define DAC_CR_MAMP1_1                      (0x2UL << DAC_CR_MAMP1_Pos)         /*!< 0x00000200 */
#define DAC_CR_MAMP1_2                      (0x4UL << DAC_CR_MAMP1_Pos)         /*!< 0x00000400 */
#define DAC_CR_MAMP1_3                      (0x8UL << DAC_CR_MAMP1_Pos)         /*!< 0x00000800 */

#define DAC_CR_DMAEN1_Pos                   (12U)                              
#define DAC_CR_DMAEN1_Msk                   (0x1UL << DAC_CR_DMAEN1_Pos)        /*!< 0x00001000 */
#define DAC_CR_DMAEN1                       DAC_CR_DMAEN1_Msk                  /*!<DAC channel1 DMA enable */
#define DAC_CR_DMAUDRIE1_Pos                (13U)                              
#define DAC_CR_DMAUDRIE1_Msk                (0x1UL << DAC_CR_DMAUDRIE1_Pos)     /*!< 0x00002000 */
#define DAC_CR_DMAUDRIE1                    DAC_CR_DMAUDRIE1_Msk               /*!<DAC channel1 DMA Interrupt enable */
#define DAC_CR_EN2_Pos                      (16U)                              
#define DAC_CR_EN2_Msk                      (0x1UL << DAC_CR_EN2_Pos)           /*!< 0x00010000 */
#define DAC_CR_EN2                          DAC_CR_EN2_Msk                     /*!<DAC channel2 enable */
#define DAC_CR_BOFF2_Pos                    (17U)                              
#define DAC_CR_BOFF2_Msk                    (0x1UL << DAC_CR_BOFF2_Pos)         /*!< 0x00020000 */
#define DAC_CR_BOFF2                        DAC_CR_BOFF2_Msk                   /*!<DAC channel2 output buffer disable */
#define DAC_CR_TEN2_Pos                     (18U)                              
#define DAC_CR_TEN2_Msk                     (0x1UL << DAC_CR_TEN2_Pos)          /*!< 0x00040000 */
#define DAC_CR_TEN2                         DAC_CR_TEN2_Msk                    /*!<DAC channel2 Trigger enable */

#define DAC_CR_TSEL2_Pos                    (19U)                              
#define DAC_CR_TSEL2_Msk                    (0x7UL << DAC_CR_TSEL2_Pos)         /*!< 0x00380000 */
#define DAC_CR_TSEL2                        DAC_CR_TSEL2_Msk                   /*!<TSEL2[2:0] (DAC channel2 Trigger selection) */
#define DAC_CR_TSEL2_0                      (0x1UL << DAC_CR_TSEL2_Pos)         /*!< 0x00080000 */
#define DAC_CR_TSEL2_1                      (0x2UL << DAC_CR_TSEL2_Pos)         /*!< 0x00100000 */
#define DAC_CR_TSEL2_2                      (0x4UL << DAC_CR_TSEL2_Pos)         /*!< 0x00200000 */

#define DAC_CR_WAVE2_Pos                    (22U)                              
#define DAC_CR_WAVE2_Msk                    (0x3UL << DAC_CR_WAVE2_Pos)         /*!< 0x00C00000 */
#define DAC_CR_WAVE2                        DAC_CR_WAVE2_Msk                   /*!<WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define DAC_CR_WAVE2_0                      (0x1UL << DAC_CR_WAVE2_Pos)         /*!< 0x00400000 */
#define DAC_CR_WAVE2_1                      (0x2UL << DAC_CR_WAVE2_Pos)         /*!< 0x00800000 */

#define DAC_CR_MAMP2_Pos                    (24U)                              
#define DAC_CR_MAMP2_Msk                    (0xFUL << DAC_CR_MAMP2_Pos)         /*!< 0x0F000000 */
#define DAC_CR_MAMP2                        DAC_CR_MAMP2_Msk                   /*!<MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define DAC_CR_MAMP2_0                      (0x1UL << DAC_CR_MAMP2_Pos)         /*!< 0x01000000 */
#define DAC_CR_MAMP2_1                      (0x2UL << DAC_CR_MAMP2_Pos)         /*!< 0x02000000 */
#define DAC_CR_MAMP2_2                      (0x4UL << DAC_CR_MAMP2_Pos)         /*!< 0x04000000 */
#define DAC_CR_MAMP2_3                      (0x8UL << DAC_CR_MAMP2_Pos)         /*!< 0x08000000 */

#define DAC_CR_DMAEN2_Pos                   (28U)                              
#define DAC_CR_DMAEN2_Msk                   (0x1UL << DAC_CR_DMAEN2_Pos)        /*!< 0x10000000 */
#define DAC_CR_DMAEN2                       DAC_CR_DMAEN2_Msk                  /*!<DAC channel2 DMA enabled */
#define DAC_CR_DMAUDRIE2_Pos                (29U)                              
#define DAC_CR_DMAUDRIE2_Msk                (0x1UL << DAC_CR_DMAUDRIE2_Pos)     /*!< 0x20000000 */
#define DAC_CR_DMAUDRIE2                    DAC_CR_DMAUDRIE2_Msk               /*!<DAC channel2 DMA underrun interrupt enable */
/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define DAC_SWTRIGR_SWTRIG1_Pos             (0U)                               
#define DAC_SWTRIGR_SWTRIG1_Msk             (0x1UL << DAC_SWTRIGR_SWTRIG1_Pos)  /*!< 0x00000001 */
#define DAC_SWTRIGR_SWTRIG1                 DAC_SWTRIGR_SWTRIG1_Msk            /*!<DAC channel1 software trigger */
#define DAC_SWTRIGR_SWTRIG2_Pos             (1U)                               
#define DAC_SWTRIGR_SWTRIG2_Msk             (0x1UL << DAC_SWTRIGR_SWTRIG2_Pos)  /*!< 0x00000002 */
#define DAC_SWTRIGR_SWTRIG2                 DAC_SWTRIGR_SWTRIG2_Msk            /*!<DAC channel2 software trigger */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define DAC_DHR12R1_DACC1DHR_Pos            (0U)                               
#define DAC_DHR12R1_DACC1DHR_Msk            (0xFFFUL << DAC_DHR12R1_DACC1DHR_Pos) /*!< 0x00000FFF */
#define DAC_DHR12R1_DACC1DHR                DAC_DHR12R1_DACC1DHR_Msk           /*!<DAC channel1 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define DAC_DHR12L1_DACC1DHR_Pos            (4U)                               
#define DAC_DHR12L1_DACC1DHR_Msk            (0xFFFUL << DAC_DHR12L1_DACC1DHR_Pos) /*!< 0x0000FFF0 */
#define DAC_DHR12L1_DACC1DHR                DAC_DHR12L1_DACC1DHR_Msk           /*!<DAC channel1 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define DAC_DHR8R1_DACC1DHR_Pos             (0U)                               
#define DAC_DHR8R1_DACC1DHR_Msk             (0xFFUL << DAC_DHR8R1_DACC1DHR_Pos) /*!< 0x000000FF */
#define DAC_DHR8R1_DACC1DHR                 DAC_DHR8R1_DACC1DHR_Msk            /*!<DAC channel1 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define DAC_DHR12R2_DACC2DHR_Pos            (0U)                               
#define DAC_DHR12R2_DACC2DHR_Msk            (0xFFFUL << DAC_DHR12R2_DACC2DHR_Pos) /*!< 0x00000FFF */
#define DAC_DHR12R2_DACC2DHR                DAC_DHR12R2_DACC2DHR_Msk           /*!<DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define DAC_DHR12L2_DACC2DHR_Pos            (4U)                               
#define DAC_DHR12L2_DACC2DHR_Msk            (0xFFFUL << DAC_DHR12L2_DACC2DHR_Pos) /*!< 0x0000FFF0 */
#define DAC_DHR12L2_DACC2DHR                DAC_DHR12L2_DACC2DHR_Msk           /*!<DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define DAC_DHR8R2_DACC2DHR_Pos             (0U)                               
#define DAC_DHR8R2_DACC2DHR_Msk             (0xFFUL << DAC_DHR8R2_DACC2DHR_Pos) /*!< 0x000000FF */
#define DAC_DHR8R2_DACC2DHR                 DAC_DHR8R2_DACC2DHR_Msk            /*!<DAC channel2 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define DAC_DHR12RD_DACC1DHR_Pos            (0U)                               
#define DAC_DHR12RD_DACC1DHR_Msk            (0xFFFUL << DAC_DHR12RD_DACC1DHR_Pos) /*!< 0x00000FFF */
#define DAC_DHR12RD_DACC1DHR                DAC_DHR12RD_DACC1DHR_Msk           /*!<DAC channel1 12-bit Right aligned data */
#define DAC_DHR12RD_DACC2DHR_Pos            (16U)                              
#define DAC_DHR12RD_DACC2DHR_Msk            (0xFFFUL << DAC_DHR12RD_DACC2DHR_Pos) /*!< 0x0FFF0000 */
#define DAC_DHR12RD_DACC2DHR                DAC_DHR12RD_DACC2DHR_Msk           /*!<DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define DAC_DHR12LD_DACC1DHR_Pos            (4U)                               
#define DAC_DHR12LD_DACC1DHR_Msk            (0xFFFUL << DAC_DHR12LD_DACC1DHR_Pos) /*!< 0x0000FFF0 */
#define DAC_DHR12LD_DACC1DHR                DAC_DHR12LD_DACC1DHR_Msk           /*!<DAC channel1 12-bit Left aligned data */
#define DAC_DHR12LD_DACC2DHR_Pos            (20U)                              
#define DAC_DHR12LD_DACC2DHR_Msk            (0xFFFUL << DAC_DHR12LD_DACC2DHR_Pos) /*!< 0xFFF00000 */
#define DAC_DHR12LD_DACC2DHR                DAC_DHR12LD_DACC2DHR_Msk           /*!<DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8RD register  ******************/
#define DAC_DHR8RD_DACC1DHR_Pos             (0U)                               
#define DAC_DHR8RD_DACC1DHR_Msk             (0xFFUL << DAC_DHR8RD_DACC1DHR_Pos) /*!< 0x000000FF */
#define DAC_DHR8RD_DACC1DHR                 DAC_DHR8RD_DACC1DHR_Msk            /*!<DAC channel1 8-bit Right aligned data */
#define DAC_DHR8RD_DACC2DHR_Pos             (8U)                               
#define DAC_DHR8RD_DACC2DHR_Msk             (0xFFUL << DAC_DHR8RD_DACC2DHR_Pos) /*!< 0x0000FF00 */
#define DAC_DHR8RD_DACC2DHR                 DAC_DHR8RD_DACC2DHR_Msk            /*!<DAC channel2 8-bit Right aligned data */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define DAC_DOR1_DACC1DOR_Pos               (0U)                               
#define DAC_DOR1_DACC1DOR_Msk               (0xFFFUL << DAC_DOR1_DACC1DOR_Pos)  /*!< 0x00000FFF */
#define DAC_DOR1_DACC1DOR                   DAC_DOR1_DACC1DOR_Msk              /*!<DAC channel1 data output */

/*******************  Bit definition for DAC_DOR2 register  *******************/
#define DAC_DOR2_DACC2DOR_Pos               (0U)                               
#define DAC_DOR2_DACC2DOR_Msk               (0xFFFUL << DAC_DOR2_DACC2DOR_Pos)  /*!< 0x00000FFF */
#define DAC_DOR2_DACC2DOR                   DAC_DOR2_DACC2DOR_Msk              /*!<DAC channel2 data output */

/********************  Bit definition for DAC_SR register  ********************/
#define DAC_SR_DMAUDR1_Pos                  (13U)                              
#define DAC_SR_DMAUDR1_Msk                  (0x1UL << DAC_SR_DMAUDR1_Pos)       /*!< 0x00002000 */
#define DAC_SR_DMAUDR1                      DAC_SR_DMAUDR1_Msk                 /*!<DAC channel1 DMA underrun flag */
#define DAC_SR_DMAUDR2_Pos                  (29U)                              
#define DAC_SR_DMAUDR2_Msk                  (0x1UL << DAC_SR_DMAUDR2_Pos)       /*!< 0x20000000 */
#define DAC_SR_DMAUDR2                      DAC_SR_DMAUDR2_Msk                 /*!<DAC channel2 DMA underrun flag */

/******************************************************************************/
/*                                                                            */
/*                           Debug MCU (DBGMCU)                               */
/*                                                                            */
/******************************************************************************/

/****************  Bit definition for DBGMCU_IDCODE register  *****************/
#define DBGMCU_IDCODE_DEV_ID_Pos                 (0U)                          
#define DBGMCU_IDCODE_DEV_ID_Msk                 (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos) /*!< 0x00000FFF */
#define DBGMCU_IDCODE_DEV_ID                     DBGMCU_IDCODE_DEV_ID_Msk      /*!< Device Identifier */

#define DBGMCU_IDCODE_REV_ID_Pos                 (16U)                         
#define DBGMCU_IDCODE_REV_ID_Msk                 (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0xFFFF0000 */
#define DBGMCU_IDCODE_REV_ID                     DBGMCU_IDCODE_REV_ID_Msk      /*!< REV_ID[15:0] bits (Revision Identifier) */
#define DBGMCU_IDCODE_REV_ID_0                   (0x0001UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00010000 */
#define DBGMCU_IDCODE_REV_ID_1                   (0x0002UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00020000 */
#define DBGMCU_IDCODE_REV_ID_2                   (0x0004UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00040000 */
#define DBGMCU_IDCODE_REV_ID_3                   (0x0008UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00080000 */
#define DBGMCU_IDCODE_REV_ID_4                   (0x0010UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00100000 */
#define DBGMCU_IDCODE_REV_ID_5                   (0x0020UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00200000 */
#define DBGMCU_IDCODE_REV_ID_6                   (0x0040UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00400000 */
#define DBGMCU_IDCODE_REV_ID_7                   (0x0080UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00800000 */
#define DBGMCU_IDCODE_REV_ID_8                   (0x0100UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x01000000 */
#define DBGMCU_IDCODE_REV_ID_9                   (0x0200UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x02000000 */
#define DBGMCU_IDCODE_REV_ID_10                  (0x0400UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x04000000 */
#define DBGMCU_IDCODE_REV_ID_11                  (0x0800UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x08000000 */
#define DBGMCU_IDCODE_REV_ID_12                  (0x1000UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x10000000 */
#define DBGMCU_IDCODE_REV_ID_13                  (0x2000UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x20000000 */
#define DBGMCU_IDCODE_REV_ID_14                  (0x4000UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x40000000 */
#define DBGMCU_IDCODE_REV_ID_15                  (0x8000UL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x80000000 */

/******************  Bit definition for DBGMCU_CR register  *******************/
#define DBGMCU_CR_DBG_SLEEP_Pos                  (0U)                          
#define DBGMCU_CR_DBG_SLEEP_Msk                  (0x1UL << DBGMCU_CR_DBG_SLEEP_Pos) /*!< 0x00000001 */
#define DBGMCU_CR_DBG_SLEEP                      DBGMCU_CR_DBG_SLEEP_Msk       /*!< Debug Sleep Mode */
#define DBGMCU_CR_DBG_STOP_Pos                   (1U)                          
#define DBGMCU_CR_DBG_STOP_Msk                   (0x1UL << DBGMCU_CR_DBG_STOP_Pos) /*!< 0x00000002 */
#define DBGMCU_CR_DBG_STOP                       DBGMCU_CR_DBG_STOP_Msk        /*!< Debug Stop Mode */
#define DBGMCU_CR_DBG_STANDBY_Pos                (2U)                          
#define DBGMCU_CR_DBG_STANDBY_Msk                (0x1UL << DBGMCU_CR_DBG_STANDBY_Pos) /*!< 0x00000004 */
#define DBGMCU_CR_DBG_STANDBY                    DBGMCU_CR_DBG_STANDBY_Msk     /*!< Debug Standby mode */
#define DBGMCU_CR_TRACE_IOEN_Pos                 (5U)                          
#define DBGMCU_CR_TRACE_IOEN_Msk                 (0x1UL << DBGMCU_CR_TRACE_IOEN_Pos) /*!< 0x00000020 */
#define DBGMCU_CR_TRACE_IOEN                     DBGMCU_CR_TRACE_IOEN_Msk      /*!< Trace Pin Assignment Control */

#define DBGMCU_CR_TRACE_MODE_Pos                 (6U)                          
#define DBGMCU_CR_TRACE_MODE_Msk                 (0x3UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x000000C0 */
#define DBGMCU_CR_TRACE_MODE                     DBGMCU_CR_TRACE_MODE_Msk      /*!< TRACE_MODE[1:0] bits (Trace Pin Assignment Control) */
#define DBGMCU_CR_TRACE_MODE_0                   (0x1UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x00000040 */
#define DBGMCU_CR_TRACE_MODE_1                   (0x2UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x00000080 */

/******************  Bit definition for DBGMCU_APB1_FZ register  **************/

#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos         (0U)                          
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk         (0x1UL << DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos) /*!< 0x00000001 */
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP             DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk /*!< TIM2 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos         (1U)                          
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk         (0x1UL << DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos) /*!< 0x00000002 */
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP             DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk /*!< TIM3 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP_Pos         (2U)                          
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP_Msk         (0x1UL << DBGMCU_APB1_FZ_DBG_TIM4_STOP_Pos) /*!< 0x00000004 */
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP             DBGMCU_APB1_FZ_DBG_TIM4_STOP_Msk /*!< TIM4 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP_Pos         (3U)                          
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP_Msk         (0x1UL << DBGMCU_APB1_FZ_DBG_TIM5_STOP_Pos) /*!< 0x00000008 */
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP             DBGMCU_APB1_FZ_DBG_TIM5_STOP_Msk /*!< TIM5 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos         (4U)                          
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk         (0x1UL << DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos) /*!< 0x00000010 */
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP             DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk /*!< TIM6 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos         (5U)                          
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk         (0x1UL << DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos) /*!< 0x00000020 */
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP             DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk /*!< TIM7 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos          (10U)                         
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk          (0x1UL << DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos) /*!< 0x00000400 */
#define DBGMCU_APB1_FZ_DBG_RTC_STOP              DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk /*!< RTC Counter stopped when Core is halted */
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos         (11U)                         
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk         (0x1UL << DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos) /*!< 0x00000800 */
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP             DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk /*!< Debug Window Watchdog stopped when Core is halted */
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos         (12U)                         
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk         (0x1UL << DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos) /*!< 0x00001000 */
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP             DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk /*!< Debug Independent Watchdog stopped when Core is halted */
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos (21U)                        
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk (0x1UL << DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos) /*!< 0x00200000 */
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT    DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk /*!< SMBUS timeout mode stopped when Core is halted */
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Pos (22U)                        
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Msk (0x1UL << DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Pos) /*!< 0x00400000 */
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT    DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Msk /*!< SMBUS timeout mode stopped when Core is halted */

/******************  Bit definition for DBGMCU_APB2_FZ register  **************/

#define DBGMCU_APB2_FZ_DBG_TIM9_STOP_Pos         (2U)                          
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP_Msk         (0x1UL << DBGMCU_APB2_FZ_DBG_TIM9_STOP_Pos) /*!< 0x00000004 */
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP             DBGMCU_APB2_FZ_DBG_TIM9_STOP_Msk /*!< TIM9 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP_Pos        (3U)                          
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP_Msk        (0x1UL << DBGMCU_APB2_FZ_DBG_TIM10_STOP_Pos) /*!< 0x00000008 */
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP            DBGMCU_APB2_FZ_DBG_TIM10_STOP_Msk /*!< TIM10 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP_Pos        (4U)                          
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP_Msk        (0x1UL << DBGMCU_APB2_FZ_DBG_TIM11_STOP_Pos) /*!< 0x00000010 */
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP            DBGMCU_APB2_FZ_DBG_TIM11_STOP_Msk /*!< TIM11 counter stopped when core is halted */

/******************************************************************************/
/*                                                                            */
/*                           DMA Controller (DMA)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for DMA_ISR register  ********************/
#define DMA_ISR_GIF1_Pos                    (0U)                               
#define DMA_ISR_GIF1_Msk                    (0x1UL << DMA_ISR_GIF1_Pos)         /*!< 0x00000001 */
#define DMA_ISR_GIF1                        DMA_ISR_GIF1_Msk                   /*!< Channel 1 Global interrupt flag */
#define DMA_ISR_TCIF1_Pos                   (1U)                               
#define DMA_ISR_TCIF1_Msk                   (0x1UL << DMA_ISR_TCIF1_Pos)        /*!< 0x00000002 */
#define DMA_ISR_TCIF1                       DMA_ISR_TCIF1_Msk                  /*!< Channel 1 Transfer Complete flag */
#define DMA_ISR_HTIF1_Pos                   (2U)                               
#define DMA_ISR_HTIF1_Msk                   (0x1UL << DMA_ISR_HTIF1_Pos)        /*!< 0x00000004 */
#define DMA_ISR_HTIF1                       DMA_ISR_HTIF1_Msk                  /*!< Channel 1 Half Transfer flag */
#define DMA_ISR_TEIF1_Pos                   (3U)                               
#define DMA_ISR_TEIF1_Msk                   (0x1UL << DMA_ISR_TEIF1_Pos)        /*!< 0x00000008 */
#define DMA_ISR_TEIF1                       DMA_ISR_TEIF1_Msk                  /*!< Channel 1 Transfer Error flag */
#define DMA_ISR_GIF2_Pos                    (4U)                               
#define DMA_ISR_GIF2_Msk                    (0x1UL << DMA_ISR_GIF2_Pos)         /*!< 0x00000010 */
#define DMA_ISR_GIF2                        DMA_ISR_GIF2_Msk                   /*!< Channel 2 Global interrupt flag */
#define DMA_ISR_TCIF2_Pos                   (5U)                               
#define DMA_ISR_TCIF2_Msk                   (0x1UL << DMA_ISR_TCIF2_Pos)        /*!< 0x00000020 */
#define DMA_ISR_TCIF2                       DMA_ISR_TCIF2_Msk                  /*!< Channel 2 Transfer Complete flag */
#define DMA_ISR_HTIF2_Pos                   (6U)                               
#define DMA_ISR_HTIF2_Msk                   (0x1UL << DMA_ISR_HTIF2_Pos)        /*!< 0x00000040 */
#define DMA_ISR_HTIF2                       DMA_ISR_HTIF2_Msk                  /*!< Channel 2 Half Transfer flag */
#define DMA_ISR_TEIF2_Pos                   (7U)                               
#define DMA_ISR_TEIF2_Msk                   (0x1UL << DMA_ISR_TEIF2_Pos)        /*!< 0x00000080 */
#define DMA_ISR_TEIF2                       DMA_ISR_TEIF2_Msk                  /*!< Channel 2 Transfer Error flag */
#define DMA_ISR_GIF3_Pos                    (8U)                               
#define DMA_ISR_GIF3_Msk                    (0x1UL << DMA_ISR_GIF3_Pos)         /*!< 0x00000100 */
#define DMA_ISR_GIF3                        DMA_ISR_GIF3_Msk                   /*!< Channel 3 Global interrupt flag */
#define DMA_ISR_TCIF3_Pos                   (9U)                               
#define DMA_ISR_TCIF3_Msk                   (0x1UL << DMA_ISR_TCIF3_Pos)        /*!< 0x00000200 */
#define DMA_ISR_TCIF3                       DMA_ISR_TCIF3_Msk                  /*!< Channel 3 Transfer Complete flag */
#define DMA_ISR_HTIF3_Pos                   (10U)                              
#define DMA_ISR_HTIF3_Msk                   (0x1UL << DMA_ISR_HTIF3_Pos)        /*!< 0x00000400 */
#define DMA_ISR_HTIF3                       DMA_ISR_HTIF3_Msk                  /*!< Channel 3 Half Transfer flag */
#define DMA_ISR_TEIF3_Pos                   (11U)                              
#define DMA_ISR_TEIF3_Msk                   (0x1UL << DMA_ISR_TEIF3_Pos)        /*!< 0x00000800 */
#define DMA_ISR_TEIF3                       DMA_ISR_TEIF3_Msk                  /*!< Channel 3 Transfer Error flag */
#define DMA_ISR_GIF4_Pos                    (12U)                              
#define DMA_ISR_GIF4_Msk                    (0x1UL << DMA_ISR_GIF4_Pos)         /*!< 0x00001000 */
#define DMA_ISR_GIF4                        DMA_ISR_GIF4_Msk                   /*!< Channel 4 Global interrupt flag */
#define DMA_ISR_TCIF4_Pos                   (13U)                              
#define DMA_ISR_TCIF4_Msk                   (0x1UL << DMA_ISR_TCIF4_Pos)        /*!< 0x00002000 */
#define DMA_ISR_TCIF4                       DMA_ISR_TCIF4_Msk                  /*!< Channel 4 Transfer Complete flag */
#define DMA_ISR_HTIF4_Pos                   (14U)                              
#define DMA_ISR_HTIF4_Msk                   (0x1UL << DMA_ISR_HTIF4_Pos)        /*!< 0x00004000 */
#define DMA_ISR_HTIF4                       DMA_ISR_HTIF4_Msk                  /*!< Channel 4 Half Transfer flag */
#define DMA_ISR_TEIF4_Pos                   (15U)                              
#define DMA_ISR_TEIF4_Msk                   (0x1UL << DMA_ISR_TEIF4_Pos)        /*!< 0x00008000 */
#define DMA_ISR_TEIF4                       DMA_ISR_TEIF4_Msk                  /*!< Channel 4 Transfer Error flag */
#define DMA_ISR_GIF5_Pos                    (16U)                              
#define DMA_ISR_GIF5_Msk                    (0x1UL << DMA_ISR_GIF5_Pos)         /*!< 0x00010000 */
#define DMA_ISR_GIF5                        DMA_ISR_GIF5_Msk                   /*!< Channel 5 Global interrupt flag */
#define DMA_ISR_TCIF5_Pos                   (17U)                              
#define DMA_ISR_TCIF5_Msk                   (0x1UL << DMA_ISR_TCIF5_Pos)        /*!< 0x00020000 */
#define DMA_ISR_TCIF5                       DMA_ISR_TCIF5_Msk                  /*!< Channel 5 Transfer Complete flag */
#define DMA_ISR_HTIF5_Pos                   (18U)                              
#define DMA_ISR_HTIF5_Msk                   (0x1UL << DMA_ISR_HTIF5_Pos)        /*!< 0x00040000 */
#define DMA_ISR_HTIF5                       DMA_ISR_HTIF5_Msk                  /*!< Channel 5 Half Transfer flag */
#define DMA_ISR_TEIF5_Pos                   (19U)                              
#define DMA_ISR_TEIF5_Msk                   (0x1UL << DMA_ISR_TEIF5_Pos)        /*!< 0x00080000 */
#define DMA_ISR_TEIF5                       DMA_ISR_TEIF5_Msk                  /*!< Channel 5 Transfer Error flag */
#define DMA_ISR_GIF6_Pos                    (20U)                              
#define DMA_ISR_GIF6_Msk                    (0x1UL << DMA_ISR_GIF6_Pos)         /*!< 0x00100000 */
#define DMA_ISR_GIF6                        DMA_ISR_GIF6_Msk                   /*!< Channel 6 Global interrupt flag */
#define DMA_ISR_TCIF6_Pos                   (21U)                              
#define DMA_ISR_TCIF6_Msk                   (0x1UL << DMA_ISR_TCIF6_Pos)        /*!< 0x00200000 */
#define DMA_ISR_TCIF6                       DMA_ISR_TCIF6_Msk                  /*!< Channel 6 Transfer Complete flag */
#define DMA_ISR_HTIF6_Pos                   (22U)                              
#define DMA_ISR_HTIF6_Msk                   (0x1UL << DMA_ISR_HTIF6_Pos)        /*!< 0x00400000 */
#define DMA_ISR_HTIF6                       DMA_ISR_HTIF6_Msk                  /*!< Channel 6 Half Transfer flag */
#define DMA_ISR_TEIF6_Pos                   (23U)                              
#define DMA_ISR_TEIF6_Msk                   (0x1UL << DMA_ISR_TEIF6_Pos)        /*!< 0x00800000 */
#define DMA_ISR_TEIF6                       DMA_ISR_TEIF6_Msk                  /*!< Channel 6 Transfer Error flag */
#define DMA_ISR_GIF7_Pos                    (24U)                              
#define DMA_ISR_GIF7_Msk                    (0x1UL << DMA_ISR_GIF7_Pos)         /*!< 0x01000000 */
#define DMA_ISR_GIF7                        DMA_ISR_GIF7_Msk                   /*!< Channel 7 Global interrupt flag */
#define DMA_ISR_TCIF7_Pos                   (25U)                              
#define DMA_ISR_TCIF7_Msk                   (0x1UL << DMA_ISR_TCIF7_Pos)        /*!< 0x02000000 */
#define DMA_ISR_TCIF7                       DMA_ISR_TCIF7_Msk                  /*!< Channel 7 Transfer Complete flag */
#define DMA_ISR_HTIF7_Pos                   (26U)                              
#define DMA_ISR_HTIF7_Msk                   (0x1UL << DMA_ISR_HTIF7_Pos)        /*!< 0x04000000 */
#define DMA_ISR_HTIF7                       DMA_ISR_HTIF7_Msk                  /*!< Channel 7 Half Transfer flag */
#define DMA_ISR_TEIF7_Pos                   (27U)                              
#define DMA_ISR_TEIF7_Msk                   (0x1UL << DMA_ISR_TEIF7_Pos)        /*!< 0x08000000 */
#define DMA_ISR_TEIF7                       DMA_ISR_TEIF7_Msk                  /*!< Channel 7 Transfer Error flag */

/*******************  Bit definition for DMA_IFCR register  *******************/
#define DMA_IFCR_CGIF1_Pos                  (0U)                               
#define DMA_IFCR_CGIF1_Msk                  (0x1UL << DMA_IFCR_CGIF1_Pos)       /*!< 0x00000001 */
#define DMA_IFCR_CGIF1                      DMA_IFCR_CGIF1_Msk                 /*!< Channel 1 Global interrupt clear */
#define DMA_IFCR_CTCIF1_Pos                 (1U)                               
#define DMA_IFCR_CTCIF1_Msk                 (0x1UL << DMA_IFCR_CTCIF1_Pos)      /*!< 0x00000002 */
#define DMA_IFCR_CTCIF1                     DMA_IFCR_CTCIF1_Msk                /*!< Channel 1 Transfer Complete clear */
#define DMA_IFCR_CHTIF1_Pos                 (2U)                               
#define DMA_IFCR_CHTIF1_Msk                 (0x1UL << DMA_IFCR_CHTIF1_Pos)      /*!< 0x00000004 */
#define DMA_IFCR_CHTIF1                     DMA_IFCR_CHTIF1_Msk                /*!< Channel 1 Half Transfer clear */
#define DMA_IFCR_CTEIF1_Pos                 (3U)                               
#define DMA_IFCR_CTEIF1_Msk                 (0x1UL << DMA_IFCR_CTEIF1_Pos)      /*!< 0x00000008 */
#define DMA_IFCR_CTEIF1                     DMA_IFCR_CTEIF1_Msk                /*!< Channel 1 Transfer Error clear */
#define DMA_IFCR_CGIF2_Pos                  (4U)                               
#define DMA_IFCR_CGIF2_Msk                  (0x1UL << DMA_IFCR_CGIF2_Pos)       /*!< 0x00000010 */
#define DMA_IFCR_CGIF2                      DMA_IFCR_CGIF2_Msk                 /*!< Channel 2 Global interrupt clear */
#define DMA_IFCR_CTCIF2_Pos                 (5U)                               
#define DMA_IFCR_CTCIF2_Msk                 (0x1UL << DMA_IFCR_CTCIF2_Pos)      /*!< 0x00000020 */
#define DMA_IFCR_CTCIF2                     DMA_IFCR_CTCIF2_Msk                /*!< Channel 2 Transfer Complete clear */
#define DMA_IFCR_CHTIF2_Pos                 (6U)                               
#define DMA_IFCR_CHTIF2_Msk                 (0x1UL << DMA_IFCR_CHTIF2_Pos)      /*!< 0x00000040 */
#define DMA_IFCR_CHTIF2                     DMA_IFCR_CHTIF2_Msk                /*!< Channel 2 Half Transfer clear */
#define DMA_IFCR_CTEIF2_Pos                 (7U)                               
#define DMA_IFCR_CTEIF2_Msk                 (0x1UL << DMA_IFCR_CTEIF2_Pos)      /*!< 0x00000080 */
#define DMA_IFCR_CTEIF2                     DMA_IFCR_CTEIF2_Msk                /*!< Channel 2 Transfer Error clear */
#define DMA_IFCR_CGIF3_Pos                  (8U)                               
#define DMA_IFCR_CGIF3_Msk                  (0x1UL << DMA_IFCR_CGIF3_Pos)       /*!< 0x00000100 */
#define DMA_IFCR_CGIF3                      DMA_IFCR_CGIF3_Msk                 /*!< Channel 3 Global interrupt clear */
#define DMA_IFCR_CTCIF3_Pos                 (9U)                               
#define DMA_IFCR_CTCIF3_Msk                 (0x1UL << DMA_IFCR_CTCIF3_Pos)      /*!< 0x00000200 */
#define DMA_IFCR_CTCIF3                     DMA_IFCR_CTCIF3_Msk                /*!< Channel 3 Transfer Complete clear */
#define DMA_IFCR_CHTIF3_Pos                 (10U)                              
#define DMA_IFCR_CHTIF3_Msk                 (0x1UL << DMA_IFCR_CHTIF3_Pos)      /*!< 0x00000400 */
#define DMA_IFCR_CHTIF3                     DMA_IFCR_CHTIF3_Msk                /*!< Channel 3 Half Transfer clear */
#define DMA_IFCR_CTEIF3_Pos                 (11U)                              
#define DMA_IFCR_CTEIF3_Msk                 (0x1UL << DMA_IFCR_CTEIF3_Pos)      /*!< 0x00000800 */
#define DMA_IFCR_CTEIF3                     DMA_IFCR_CTEIF3_Msk                /*!< Channel 3 Transfer Error clear */
#define DMA_IFCR_CGIF4_Pos                  (12U)                              
#define DMA_IFCR_CGIF4_Msk                  (0x1UL << DMA_IFCR_CGIF4_Pos)       /*!< 0x00001000 */
#define DMA_IFCR_CGIF4                      DMA_IFCR_CGIF4_Msk                 /*!< Channel 4 Global interrupt clear */
#define DMA_IFCR_CTCIF4_Pos                 (13U)                              
#define DMA_IFCR_CTCIF4_Msk                 (0x1UL << DMA_IFCR_CTCIF4_Pos)      /*!< 0x00002000 */
#define DMA_IFCR_CTCIF4                     DMA_IFCR_CTCIF4_Msk                /*!< Channel 4 Transfer Complete clear */
#define DMA_IFCR_CHTIF4_Pos                 (14U)                              
#define DMA_IFCR_CHTIF4_Msk                 (0x1UL << DMA_IFCR_CHTIF4_Pos)      /*!< 0x00004000 */
#define DMA_IFCR_CHTIF4                     DMA_IFCR_CHTIF4_Msk                /*!< Channel 4 Half Transfer clear */
#define DMA_IFCR_CTEIF4_Pos                 (15U)                              
#define DMA_IFCR_CTEIF4_Msk                 (0x1UL << DMA_IFCR_CTEIF4_Pos)      /*!< 0x00008000 */
#define DMA_IFCR_CTEIF4                     DMA_IFCR_CTEIF4_Msk                /*!< Channel 4 Transfer Error clear */
#define DMA_IFCR_CGIF5_Pos                  (16U)                              
#define DMA_IFCR_CGIF5_Msk                  (0x1UL << DMA_IFCR_CGIF5_Pos)       /*!< 0x00010000 */
#define DMA_IFCR_CGIF5                      DMA_IFCR_CGIF5_Msk                 /*!< Channel 5 Global interrupt clear */
#define DMA_IFCR_CTCIF5_Pos                 (17U)                              
#define DMA_IFCR_CTCIF5_Msk                 (0x1UL << DMA_IFCR_CTCIF5_Pos)      /*!< 0x00020000 */
#define DMA_IFCR_CTCIF5                     DMA_IFCR_CTCIF5_Msk                /*!< Channel 5 Transfer Complete clear */
#define DMA_IFCR_CHTIF5_Pos                 (18U)                              
#define DMA_IFCR_CHTIF5_Msk                 (0x1UL << DMA_IFCR_CHTIF5_Pos)      /*!< 0x00040000 */
#define DMA_IFCR_CHTIF5                     DMA_IFCR_CHTIF5_Msk                /*!< Channel 5 Half Transfer clear */
#define DMA_IFCR_CTEIF5_Pos                 (19U)                              
#define DMA_IFCR_CTEIF5_Msk                 (0x1UL << DMA_IFCR_CTEIF5_Pos)      /*!< 0x00080000 */
#define DMA_IFCR_CTEIF5                     DMA_IFCR_CTEIF5_Msk                /*!< Channel 5 Transfer Error clear */
#define DMA_IFCR_CGIF6_Pos                  (20U)                              
#define DMA_IFCR_CGIF6_Msk                  (0x1UL << DMA_IFCR_CGIF6_Pos)       /*!< 0x00100000 */
#define DMA_IFCR_CGIF6                      DMA_IFCR_CGIF6_Msk                 /*!< Channel 6 Global interrupt clear */
#define DMA_IFCR_CTCIF6_Pos                 (21U)                              
#define DMA_IFCR_CTCIF6_Msk                 (0x1UL << DMA_IFCR_CTCIF6_Pos)      /*!< 0x00200000 */
#define DMA_IFCR_CTCIF6                     DMA_IFCR_CTCIF6_Msk                /*!< Channel 6 Transfer Complete clear */
#define DMA_IFCR_CHTIF6_Pos                 (22U)                              
#define DMA_IFCR_CHTIF6_Msk                 (0x1UL << DMA_IFCR_CHTIF6_Pos)      /*!< 0x00400000 */
#define DMA_IFCR_CHTIF6                     DMA_IFCR_CHTIF6_Msk                /*!< Channel 6 Half Transfer clear */
#define DMA_IFCR_CTEIF6_Pos                 (23U)                              
#define DMA_IFCR_CTEIF6_Msk                 (0x1UL << DMA_IFCR_CTEIF6_Pos)      /*!< 0x00800000 */
#define DMA_IFCR_CTEIF6                     DMA_IFCR_CTEIF6_Msk                /*!< Channel 6 Transfer Error clear */
#define DMA_IFCR_CGIF7_Pos                  (24U)                              
#define DMA_IFCR_CGIF7_Msk                  (0x1UL << DMA_IFCR_CGIF7_Pos)       /*!< 0x01000000 */
#define DMA_IFCR_CGIF7                      DMA_IFCR_CGIF7_Msk                 /*!< Channel 7 Global interrupt clear */
#define DMA_IFCR_CTCIF7_Pos                 (25U)                              
#define DMA_IFCR_CTCIF7_Msk                 (0x1UL << DMA_IFCR_CTCIF7_Pos)      /*!< 0x02000000 */
#define DMA_IFCR_CTCIF7                     DMA_IFCR_CTCIF7_Msk                /*!< Channel 7 Transfer Complete clear */
#define DMA_IFCR_CHTIF7_Pos                 (26U)                              
#define DMA_IFCR_CHTIF7_Msk                 (0x1UL << DMA_IFCR_CHTIF7_Pos)      /*!< 0x04000000 */
#define DMA_IFCR_CHTIF7                     DMA_IFCR_CHTIF7_Msk                /*!< Channel 7 Half Transfer clear */
#define DMA_IFCR_CTEIF7_Pos                 (27U)                              
#define DMA_IFCR_CTEIF7_Msk                 (0x1UL << DMA_IFCR_CTEIF7_Pos)      /*!< 0x08000000 */
#define DMA_IFCR_CTEIF7                     DMA_IFCR_CTEIF7_Msk                /*!< Channel 7 Transfer Error clear */

/*******************  Bit definition for DMA_CCR register  *******************/
#define DMA_CCR_EN_Pos                      (0U)                               
#define DMA_CCR_EN_Msk                      (0x1UL << DMA_CCR_EN_Pos)           /*!< 0x00000001 */
#define DMA_CCR_EN                          DMA_CCR_EN_Msk                     /*!< Channel enable*/
#define DMA_CCR_TCIE_Pos                    (1U)                               
#define DMA_CCR_TCIE_Msk                    (0x1UL << DMA_CCR_TCIE_Pos)         /*!< 0x00000002 */
#define DMA_CCR_TCIE                        DMA_CCR_TCIE_Msk                   /*!< Transfer complete interrupt enable */
#define DMA_CCR_HTIE_Pos                    (2U)                               
#define DMA_CCR_HTIE_Msk                    (0x1UL << DMA_CCR_HTIE_Pos)         /*!< 0x00000004 */
#define DMA_CCR_HTIE                        DMA_CCR_HTIE_Msk                   /*!< Half Transfer interrupt enable */
#define DMA_CCR_TEIE_Pos                    (3U)                               
#define DMA_CCR_TEIE_Msk                    (0x1UL << DMA_CCR_TEIE_Pos)         /*!< 0x00000008 */
#define DMA_CCR_TEIE                        DMA_CCR_TEIE_Msk                   /*!< Transfer error interrupt enable */
#define DMA_CCR_DIR_Pos                     (4U)                               
#define DMA_CCR_DIR_Msk                     (0x1UL << DMA_CCR_DIR_Pos)          /*!< 0x00000010 */
#define DMA_CCR_DIR                         DMA_CCR_DIR_Msk                    /*!< Data transfer direction */
#define DMA_CCR_CIRC_Pos                    (5U)                               
#define DMA_CCR_CIRC_Msk                    (0x1UL << DMA_CCR_CIRC_Pos)         /*!< 0x00000020 */
#define DMA_CCR_CIRC                        DMA_CCR_CIRC_Msk                   /*!< Circular mode */
#define DMA_CCR_PINC_Pos                    (6U)                               
#define DMA_CCR_PINC_Msk                    (0x1UL << DMA_CCR_PINC_Pos)         /*!< 0x00000040 */
#define DMA_CCR_PINC                        DMA_CCR_PINC_Msk                   /*!< Peripheral increment mode */
#define DMA_CCR_MINC_Pos                    (7U)                               
#define DMA_CCR_MINC_Msk                    (0x1UL << DMA_CCR_MINC_Pos)         /*!< 0x00000080 */
#define DMA_CCR_MINC                        DMA_CCR_MINC_Msk                   /*!< Memory increment mode */

#define DMA_CCR_PSIZE_Pos                   (8U)                               
#define DMA_CCR_PSIZE_Msk                   (0x3UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000300 */
#define DMA_CCR_PSIZE                       DMA_CCR_PSIZE_Msk                  /*!< PSIZE[1:0] bits (Peripheral size) */
#define DMA_CCR_PSIZE_0                     (0x1UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000100 */
#define DMA_CCR_PSIZE_1                     (0x2UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000200 */

#define DMA_CCR_MSIZE_Pos                   (10U)                              
#define DMA_CCR_MSIZE_Msk                   (0x3UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000C00 */
#define DMA_CCR_MSIZE                       DMA_CCR_MSIZE_Msk                  /*!< MSIZE[1:0] bits (Memory size) */
#define DMA_CCR_MSIZE_0                     (0x1UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000400 */
#define DMA_CCR_MSIZE_1                     (0x2UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000800 */

#define DMA_CCR_PL_Pos                      (12U)                              
#define DMA_CCR_PL_Msk                      (0x3UL << DMA_CCR_PL_Pos)           /*!< 0x00003000 */
#define DMA_CCR_PL                          DMA_CCR_PL_Msk                     /*!< PL[1:0] bits(Channel Priority level) */
#define DMA_CCR_PL_0                        (0x1UL << DMA_CCR_PL_Pos)           /*!< 0x00001000 */
#define DMA_CCR_PL_1                        (0x2UL << DMA_CCR_PL_Pos)           /*!< 0x00002000 */

#define DMA_CCR_MEM2MEM_Pos                 (14U)                              
#define DMA_CCR_MEM2MEM_Msk                 (0x1UL << DMA_CCR_MEM2MEM_Pos)      /*!< 0x00004000 */
#define DMA_CCR_MEM2MEM                     DMA_CCR_MEM2MEM_Msk                /*!< Memory to memory mode */

/******************  Bit definition generic for DMA_CNDTR register  *******************/
#define DMA_CNDTR_NDT_Pos                   (0U)                               
#define DMA_CNDTR_NDT_Msk                   (0xFFFFUL << DMA_CNDTR_NDT_Pos)     /*!< 0x0000FFFF */
#define DMA_CNDTR_NDT                       DMA_CNDTR_NDT_Msk                  /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CNDTR1 register  ******************/
#define DMA_CNDTR1_NDT_Pos                  (0U)                               
#define DMA_CNDTR1_NDT_Msk                  (0xFFFFUL << DMA_CNDTR1_NDT_Pos)    /*!< 0x0000FFFF */
#define DMA_CNDTR1_NDT                      DMA_CNDTR1_NDT_Msk                 /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CNDTR2 register  ******************/
#define DMA_CNDTR2_NDT_Pos                  (0U)                               
#define DMA_CNDTR2_NDT_Msk                  (0xFFFFUL << DMA_CNDTR2_NDT_Pos)    /*!< 0x0000FFFF */
#define DMA_CNDTR2_NDT                      DMA_CNDTR2_NDT_Msk                 /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CNDTR3 register  ******************/
#define DMA_CNDTR3_NDT_Pos                  (0U)                               
#define DMA_CNDTR3_NDT_Msk                  (0xFFFFUL << DMA_CNDTR3_NDT_Pos)    /*!< 0x0000FFFF */
#define DMA_CNDTR3_NDT                      DMA_CNDTR3_NDT_Msk                 /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CNDTR4 register  ******************/
#define DMA_CNDTR4_NDT_Pos                  (0U)                               
#define DMA_CNDTR4_NDT_Msk                  (0xFFFFUL << DMA_CNDTR4_NDT_Pos)    /*!< 0x0000FFFF */
#define DMA_CNDTR4_NDT                      DMA_CNDTR4_NDT_Msk                 /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CNDTR5 register  ******************/
#define DMA_CNDTR5_NDT_Pos                  (0U)                               
#define DMA_CNDTR5_NDT_Msk                  (0xFFFFUL << DMA_CNDTR5_NDT_Pos)    /*!< 0x0000FFFF */
#define DMA_CNDTR5_NDT                      DMA_CNDTR5_NDT_Msk                 /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CNDTR6 register  ******************/
#define DMA_CNDTR6_NDT_Pos                  (0U)                               
#define DMA_CNDTR6_NDT_Msk                  (0xFFFFUL << DMA_CNDTR6_NDT_Pos)    /*!< 0x0000FFFF */
#define DMA_CNDTR6_NDT                      DMA_CNDTR6_NDT_Msk                 /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CNDTR7 register  ******************/
#define DMA_CNDTR7_NDT_Pos                  (0U)                               
#define DMA_CNDTR7_NDT_Msk                  (0xFFFFUL << DMA_CNDTR7_NDT_Pos)    /*!< 0x0000FFFF */
#define DMA_CNDTR7_NDT                      DMA_CNDTR7_NDT_Msk                 /*!< Number of data to Transfer */

/******************  Bit definition generic for DMA_CPAR register  ********************/
#define DMA_CPAR_PA_Pos                     (0U)                               
#define DMA_CPAR_PA_Msk                     (0xFFFFFFFFUL << DMA_CPAR_PA_Pos)   /*!< 0xFFFFFFFF */
#define DMA_CPAR_PA                         DMA_CPAR_PA_Msk                    /*!< Peripheral Address */

/******************  Bit definition for DMA_CPAR1 register  *******************/
#define DMA_CPAR1_PA_Pos                    (0U)                               
#define DMA_CPAR1_PA_Msk                    (0xFFFFFFFFUL << DMA_CPAR1_PA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CPAR1_PA                        DMA_CPAR1_PA_Msk                   /*!< Peripheral Address */

/******************  Bit definition for DMA_CPAR2 register  *******************/
#define DMA_CPAR2_PA_Pos                    (0U)                               
#define DMA_CPAR2_PA_Msk                    (0xFFFFFFFFUL << DMA_CPAR2_PA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CPAR2_PA                        DMA_CPAR2_PA_Msk                   /*!< Peripheral Address */

/******************  Bit definition for DMA_CPAR3 register  *******************/
#define DMA_CPAR3_PA_Pos                    (0U)                               
#define DMA_CPAR3_PA_Msk                    (0xFFFFFFFFUL << DMA_CPAR3_PA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CPAR3_PA                        DMA_CPAR3_PA_Msk                   /*!< Peripheral Address */


/******************  Bit definition for DMA_CPAR4 register  *******************/
#define DMA_CPAR4_PA_Pos                    (0U)                               
#define DMA_CPAR4_PA_Msk                    (0xFFFFFFFFUL << DMA_CPAR4_PA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CPAR4_PA                        DMA_CPAR4_PA_Msk                   /*!< Peripheral Address */

/******************  Bit definition for DMA_CPAR5 register  *******************/
#define DMA_CPAR5_PA_Pos                    (0U)                               
#define DMA_CPAR5_PA_Msk                    (0xFFFFFFFFUL << DMA_CPAR5_PA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CPAR5_PA                        DMA_CPAR5_PA_Msk                   /*!< Peripheral Address */

/******************  Bit definition for DMA_CPAR6 register  *******************/
#define DMA_CPAR6_PA_Pos                    (0U)                               
#define DMA_CPAR6_PA_Msk                    (0xFFFFFFFFUL << DMA_CPAR6_PA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CPAR6_PA                        DMA_CPAR6_PA_Msk                   /*!< Peripheral Address */


/******************  Bit definition for DMA_CPAR7 register  *******************/
#define DMA_CPAR7_PA_Pos                    (0U)                               
#define DMA_CPAR7_PA_Msk                    (0xFFFFFFFFUL << DMA_CPAR7_PA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CPAR7_PA                        DMA_CPAR7_PA_Msk                   /*!< Peripheral Address */

/******************  Bit definition generic for DMA_CMAR register  ********************/
#define DMA_CMAR_MA_Pos                     (0U)                               
#define DMA_CMAR_MA_Msk                     (0xFFFFFFFFUL << DMA_CMAR_MA_Pos)   /*!< 0xFFFFFFFF */
#define DMA_CMAR_MA                         DMA_CMAR_MA_Msk                    /*!< Memory Address */

/******************  Bit definition for DMA_CMAR1 register  *******************/
#define DMA_CMAR1_MA_Pos                    (0U)                               
#define DMA_CMAR1_MA_Msk                    (0xFFFFFFFFUL << DMA_CMAR1_MA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CMAR1_MA                        DMA_CMAR1_MA_Msk                   /*!< Memory Address */

/******************  Bit definition for DMA_CMAR2 register  *******************/
#define DMA_CMAR2_MA_Pos                    (0U)                               
#define DMA_CMAR2_MA_Msk                    (0xFFFFFFFFUL << DMA_CMAR2_MA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CMAR2_MA                        DMA_CMAR2_MA_Msk                   /*!< Memory Address */

/******************  Bit definition for DMA_CMAR3 register  *******************/
#define DMA_CMAR3_MA_Pos                    (0U)                               
#define DMA_CMAR3_MA_Msk                    (0xFFFFFFFFUL << DMA_CMAR3_MA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CMAR3_MA                        DMA_CMAR3_MA_Msk                   /*!< Memory Address */


/******************  Bit definition for DMA_CMAR4 register  *******************/
#define DMA_CMAR4_MA_Pos                    (0U)                               
#define DMA_CMAR4_MA_Msk                    (0xFFFFFFFFUL << DMA_CMAR4_MA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CMAR4_MA                        DMA_CMAR4_MA_Msk                   /*!< Memory Address */

/******************  Bit definition for DMA_CMAR5 register  *******************/
#define DMA_CMAR5_MA_Pos                    (0U)                               
#define DMA_CMAR5_MA_Msk                    (0xFFFFFFFFUL << DMA_CMAR5_MA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CMAR5_MA                        DMA_CMAR5_MA_Msk                   /*!< Memory Address */

/******************  Bit definition for DMA_CMAR6 register  *******************/
#define DMA_CMAR6_MA_Pos                    (0U)                               
#define DMA_CMAR6_MA_Msk                    (0xFFFFFFFFUL << DMA_CMAR6_MA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CMAR6_MA                        DMA_CMAR6_MA_Msk                   /*!< Memory Address */

/******************  Bit definition for DMA_CMAR7 register  *******************/
#define DMA_CMAR7_MA_Pos                    (0U)                               
#define DMA_CMAR7_MA_Msk                    (0xFFFFFFFFUL << DMA_CMAR7_MA_Pos)  /*!< 0xFFFFFFFF */
#define DMA_CMAR7_MA                        DMA_CMAR7_MA_Msk                   /*!< Memory Address */

/******************************************************************************/
/*                                                                            */
/*                  External Interrupt/Event Controller (EXTI)                */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for EXTI_IMR register  *******************/
#define EXTI_IMR_MR0_Pos                    (0U)                               
#define EXTI_IMR_MR0_Msk                    (0x1UL << EXTI_IMR_MR0_Pos)         /*!< 0x00000001 */
#define EXTI_IMR_MR0                        EXTI_IMR_MR0_Msk                   /*!< Interrupt Mask on line 0 */
#define EXTI_IMR_MR1_Pos                    (1U)                               
#define EXTI_IMR_MR1_Msk                    (0x1UL << EXTI_IMR_MR1_Pos)         /*!< 0x00000002 */
#define EXTI_IMR_MR1                        EXTI_IMR_MR1_Msk                   /*!< Interrupt Mask on line 1 */
#define EXTI_IMR_MR2_Pos                    (2U)                               
#define EXTI_IMR_MR2_Msk                    (0x1UL << EXTI_IMR_MR2_Pos)         /*!< 0x00000004 */
#define EXTI_IMR_MR2                        EXTI_IMR_MR2_Msk                   /*!< Interrupt Mask on line 2 */
#define EXTI_IMR_MR3_Pos                    (3U)                               
#define EXTI_IMR_MR3_Msk                    (0x1UL << EXTI_IMR_MR3_Pos)         /*!< 0x00000008 */
#define EXTI_IMR_MR3                        EXTI_IMR_MR3_Msk                   /*!< Interrupt Mask on line 3 */
#define EXTI_IMR_MR4_Pos                    (4U)                               
#define EXTI_IMR_MR4_Msk                    (0x1UL << EXTI_IMR_MR4_Pos)         /*!< 0x00000010 */
#define EXTI_IMR_MR4                        EXTI_IMR_MR4_Msk                   /*!< Interrupt Mask on line 4 */
#define EXTI_IMR_MR5_Pos                    (5U)                               
#define EXTI_IMR_MR5_Msk                    (0x1UL << EXTI_IMR_MR5_Pos)         /*!< 0x00000020 */
#define EXTI_IMR_MR5                        EXTI_IMR_MR5_Msk                   /*!< Interrupt Mask on line 5 */
#define EXTI_IMR_MR6_Pos                    (6U)                               
#define EXTI_IMR_MR6_Msk                    (0x1UL << EXTI_IMR_MR6_Pos)         /*!< 0x00000040 */
#define EXTI_IMR_MR6                        EXTI_IMR_MR6_Msk                   /*!< Interrupt Mask on line 6 */
#define EXTI_IMR_MR7_Pos                    (7U)                               
#define EXTI_IMR_MR7_Msk                    (0x1UL << EXTI_IMR_MR7_Pos)         /*!< 0x00000080 */
#define EXTI_IMR_MR7                        EXTI_IMR_MR7_Msk                   /*!< Interrupt Mask on line 7 */
#define EXTI_IMR_MR8_Pos                    (8U)                               
#define EXTI_IMR_MR8_Msk                    (0x1UL << EXTI_IMR_MR8_Pos)         /*!< 0x00000100 */
#define EXTI_IMR_MR8                        EXTI_IMR_MR8_Msk                   /*!< Interrupt Mask on line 8 */
#define EXTI_IMR_MR9_Pos                    (9U)                               
#define EXTI_IMR_MR9_Msk                    (0x1UL << EXTI_IMR_MR9_Pos)         /*!< 0x00000200 */
#define EXTI_IMR_MR9                        EXTI_IMR_MR9_Msk                   /*!< Interrupt Mask on line 9 */
#define EXTI_IMR_MR10_Pos                   (10U)                              
#define EXTI_IMR_MR10_Msk                   (0x1UL << EXTI_IMR_MR10_Pos)        /*!< 0x00000400 */
#define EXTI_IMR_MR10                       EXTI_IMR_MR10_Msk                  /*!< Interrupt Mask on line 10 */
#define EXTI_IMR_MR11_Pos                   (11U)                              
#define EXTI_IMR_MR11_Msk                   (0x1UL << EXTI_IMR_MR11_Pos)        /*!< 0x00000800 */
#define EXTI_IMR_MR11                       EXTI_IMR_MR11_Msk                  /*!< Interrupt Mask on line 11 */
#define EXTI_IMR_MR12_Pos                   (12U)                              
#define EXTI_IMR_MR12_Msk                   (0x1UL << EXTI_IMR_MR12_Pos)        /*!< 0x00001000 */
#define EXTI_IMR_MR12                       EXTI_IMR_MR12_Msk                  /*!< Interrupt Mask on line 12 */
#define EXTI_IMR_MR13_Pos                   (13U)                              
#define EXTI_IMR_MR13_Msk                   (0x1UL << EXTI_IMR_MR13_Pos)        /*!< 0x00002000 */
#define EXTI_IMR_MR13                       EXTI_IMR_MR13_Msk                  /*!< Interrupt Mask on line 13 */
#define EXTI_IMR_MR14_Pos                   (14U)                              
#define EXTI_IMR_MR14_Msk                   (0x1UL << EXTI_IMR_MR14_Pos)        /*!< 0x00004000 */
#define EXTI_IMR_MR14                       EXTI_IMR_MR14_Msk                  /*!< Interrupt Mask on line 14 */
#define EXTI_IMR_MR15_Pos                   (15U)                              
#define EXTI_IMR_MR15_Msk                   (0x1UL << EXTI_IMR_MR15_Pos)        /*!< 0x00008000 */
#define EXTI_IMR_MR15                       EXTI_IMR_MR15_Msk                  /*!< Interrupt Mask on line 15 */
#define EXTI_IMR_MR16_Pos                   (16U)                              
#define EXTI_IMR_MR16_Msk                   (0x1UL << EXTI_IMR_MR16_Pos)        /*!< 0x00010000 */
#define EXTI_IMR_MR16                       EXTI_IMR_MR16_Msk                  /*!< Interrupt Mask on line 16 */
#define EXTI_IMR_MR17_Pos                   (17U)                              
#define EXTI_IMR_MR17_Msk                   (0x1UL << EXTI_IMR_MR17_Pos)        /*!< 0x00020000 */
#define EXTI_IMR_MR17                       EXTI_IMR_MR17_Msk                  /*!< Interrupt Mask on line 17 */
#define EXTI_IMR_MR18_Pos                   (18U)                              
#define EXTI_IMR_MR18_Msk                   (0x1UL << EXTI_IMR_MR18_Pos)        /*!< 0x00040000 */
#define EXTI_IMR_MR18                       EXTI_IMR_MR18_Msk                  /*!< Interrupt Mask on line 18 */
#define EXTI_IMR_MR19_Pos                   (19U)                              
#define EXTI_IMR_MR19_Msk                   (0x1UL << EXTI_IMR_MR19_Pos)        /*!< 0x00080000 */
#define EXTI_IMR_MR19                       EXTI_IMR_MR19_Msk                  /*!< Interrupt Mask on line 19 */
#define EXTI_IMR_MR20_Pos                   (20U)                              
#define EXTI_IMR_MR20_Msk                   (0x1UL << EXTI_IMR_MR20_Pos)        /*!< 0x00100000 */
#define EXTI_IMR_MR20                       EXTI_IMR_MR20_Msk                  /*!< Interrupt Mask on line 20 */
#define EXTI_IMR_MR21_Pos                   (21U)                              
#define EXTI_IMR_MR21_Msk                   (0x1UL << EXTI_IMR_MR21_Pos)        /*!< 0x00200000 */
#define EXTI_IMR_MR21                       EXTI_IMR_MR21_Msk                  /*!< Interrupt Mask on line 21 */
#define EXTI_IMR_MR22_Pos                   (22U)                              
#define EXTI_IMR_MR22_Msk                   (0x1UL << EXTI_IMR_MR22_Pos)        /*!< 0x00400000 */
#define EXTI_IMR_MR22                       EXTI_IMR_MR22_Msk                  /*!< Interrupt Mask on line 22 */
#define EXTI_IMR_MR23_Pos                   (23U)                              
#define EXTI_IMR_MR23_Msk                   (0x1UL << EXTI_IMR_MR23_Pos)        /*!< 0x00800000 */
#define EXTI_IMR_MR23                       EXTI_IMR_MR23_Msk                  /*!< Interrupt Mask on line 23 */

/* References Defines */
#define  EXTI_IMR_IM0 EXTI_IMR_MR0
#define  EXTI_IMR_IM1 EXTI_IMR_MR1
#define  EXTI_IMR_IM2 EXTI_IMR_MR2
#define  EXTI_IMR_IM3 EXTI_IMR_MR3
#define  EXTI_IMR_IM4 EXTI_IMR_MR4
#define  EXTI_IMR_IM5 EXTI_IMR_MR5
#define  EXTI_IMR_IM6 EXTI_IMR_MR6
#define  EXTI_IMR_IM7 EXTI_IMR_MR7
#define  EXTI_IMR_IM8 EXTI_IMR_MR8
#define  EXTI_IMR_IM9 EXTI_IMR_MR9
#define  EXTI_IMR_IM10 EXTI_IMR_MR10
#define  EXTI_IMR_IM11 EXTI_IMR_MR11
#define  EXTI_IMR_IM12 EXTI_IMR_MR12
#define  EXTI_IMR_IM13 EXTI_IMR_MR13
#define  EXTI_IMR_IM14 EXTI_IMR_MR14
#define  EXTI_IMR_IM15 EXTI_IMR_MR15
#define  EXTI_IMR_IM16 EXTI_IMR_MR16
#define  EXTI_IMR_IM17 EXTI_IMR_MR17
#define  EXTI_IMR_IM18 EXTI_IMR_MR18
#define  EXTI_IMR_IM19 EXTI_IMR_MR19
#define  EXTI_IMR_IM20 EXTI_IMR_MR20
#define  EXTI_IMR_IM21 EXTI_IMR_MR21
#define  EXTI_IMR_IM22 EXTI_IMR_MR22
/* Category 3, 4 & 5 */
#define  EXTI_IMR_IM23 EXTI_IMR_MR23
#define EXTI_IMR_IM_Pos                     (0U)                               
#define EXTI_IMR_IM_Msk                     (0xFFFFFFUL << EXTI_IMR_IM_Pos)     /*!< 0x00FFFFFF */
#define EXTI_IMR_IM                         EXTI_IMR_IM_Msk                    /*!< Interrupt Mask All */

/*******************  Bit definition for EXTI_EMR register  *******************/
#define EXTI_EMR_MR0_Pos                    (0U)                               
#define EXTI_EMR_MR0_Msk                    (0x1UL << EXTI_EMR_MR0_Pos)         /*!< 0x00000001 */
#define EXTI_EMR_MR0                        EXTI_EMR_MR0_Msk                   /*!< Event Mask on line 0 */
#define EXTI_EMR_MR1_Pos                    (1U)                               
#define EXTI_EMR_MR1_Msk                    (0x1UL << EXTI_EMR_MR1_Pos)         /*!< 0x00000002 */
#define EXTI_EMR_MR1                        EXTI_EMR_MR1_Msk                   /*!< Event Mask on line 1 */
#define EXTI_EMR_MR2_Pos                    (2U)                               
#define EXTI_EMR_MR2_Msk                    (0x1UL << EXTI_EMR_MR2_Pos)         /*!< 0x00000004 */
#define EXTI_EMR_MR2                        EXTI_EMR_MR2_Msk                   /*!< Event Mask on line 2 */
#define EXTI_EMR_MR3_Pos                    (3U)                               
#define EXTI_EMR_MR3_Msk                    (0x1UL << EXTI_EMR_MR3_Pos)         /*!< 0x00000008 */
#define EXTI_EMR_MR3                        EXTI_EMR_MR3_Msk                   /*!< Event Mask on line 3 */
#define EXTI_EMR_MR4_Pos                    (4U)                               
#define EXTI_EMR_MR4_Msk                    (0x1UL << EXTI_EMR_MR4_Pos)         /*!< 0x00000010 */
#define EXTI_EMR_MR4                        EXTI_EMR_MR4_Msk                   /*!< Event Mask on line 4 */
#define EXTI_EMR_MR5_Pos                    (5U)                               
#define EXTI_EMR_MR5_Msk                    (0x1UL << EXTI_EMR_MR5_Pos)         /*!< 0x00000020 */
#define EXTI_EMR_MR5                        EXTI_EMR_MR5_Msk                   /*!< Event Mask on line 5 */
#define EXTI_EMR_MR6_Pos                    (6U)                               
#define EXTI_EMR_MR6_Msk                    (0x1UL << EXTI_EMR_MR6_Pos)         /*!< 0x00000040 */
#define EXTI_EMR_MR6                        EXTI_EMR_MR6_Msk                   /*!< Event Mask on line 6 */
#define EXTI_EMR_MR7_Pos                    (7U)                               
#define EXTI_EMR_MR7_Msk                    (0x1UL << EXTI_EMR_MR7_Pos)         /*!< 0x00000080 */
#define EXTI_EMR_MR7                        EXTI_EMR_MR7_Msk                   /*!< Event Mask on line 7 */
#define EXTI_EMR_MR8_Pos                    (8U)                               
#define EXTI_EMR_MR8_Msk                    (0x1UL << EXTI_EMR_MR8_Pos)         /*!< 0x00000100 */
#define EXTI_EMR_MR8                        EXTI_EMR_MR8_Msk                   /*!< Event Mask on line 8 */
#define EXTI_EMR_MR9_Pos                    (9U)                               
#define EXTI_EMR_MR9_Msk                    (0x1UL << EXTI_EMR_MR9_Pos)         /*!< 0x00000200 */
#define EXTI_EMR_MR9                        EXTI_EMR_MR9_Msk                   /*!< Event Mask on line 9 */
#define EXTI_EMR_MR10_Pos                   (10U)                              
#define EXTI_EMR_MR10_Msk                   (0x1UL << EXTI_EMR_MR10_Pos)        /*!< 0x00000400 */
#define EXTI_EMR_MR10                       EXTI_EMR_MR10_Msk                  /*!< Event Mask on line 10 */
#define EXTI_EMR_MR11_Pos                   (11U)                              
#define EXTI_EMR_MR11_Msk                   (0x1UL << EXTI_EMR_MR11_Pos)        /*!< 0x00000800 */
#define EXTI_EMR_MR11                       EXTI_EMR_MR11_Msk                  /*!< Event Mask on line 11 */
#define EXTI_EMR_MR12_Pos                   (12U)                              
#define EXTI_EMR_MR12_Msk                   (0x1UL << EXTI_EMR_MR12_Pos)        /*!< 0x00001000 */
#define EXTI_EMR_MR12                       EXTI_EMR_MR12_Msk                  /*!< Event Mask on line 12 */
#define EXTI_EMR_MR13_Pos                   (13U)                              
#define EXTI_EMR_MR13_Msk                   (0x1UL << EXTI_EMR_MR13_Pos)        /*!< 0x00002000 */
#define EXTI_EMR_MR13                       EXTI_EMR_MR13_Msk                  /*!< Event Mask on line 13 */
#define EXTI_EMR_MR14_Pos                   (14U)                              
#define EXTI_EMR_MR14_Msk                   (0x1UL << EXTI_EMR_MR14_Pos)        /*!< 0x00004000 */
#define EXTI_EMR_MR14                       EXTI_EMR_MR14_Msk                  /*!< Event Mask on line 14 */
#define EXTI_EMR_MR15_Pos                   (15U)                              
#define EXTI_EMR_MR15_Msk                   (0x1UL << EXTI_EMR_MR15_Pos)        /*!< 0x00008000 */
#define EXTI_EMR_MR15                       EXTI_EMR_MR15_Msk                  /*!< Event Mask on line 15 */
#define EXTI_EMR_MR16_Pos                   (16U)                              
#define EXTI_EMR_MR16_Msk                   (0x1UL << EXTI_EMR_MR16_Pos)        /*!< 0x00010000 */
#define EXTI_EMR_MR16                       EXTI_EMR_MR16_Msk                  /*!< Event Mask on line 16 */
#define EXTI_EMR_MR17_Pos                   (17U)                              
#define EXTI_EMR_MR17_Msk                   (0x1UL << EXTI_EMR_MR17_Pos)        /*!< 0x00020000 */
#define EXTI_EMR_MR17                       EXTI_EMR_MR17_Msk                  /*!< Event Mask on line 17 */
#define EXTI_EMR_MR18_Pos                   (18U)                              
#define EXTI_EMR_MR18_Msk                   (0x1UL << EXTI_EMR_MR18_Pos)        /*!< 0x00040000 */
#define EXTI_EMR_MR18                       EXTI_EMR_MR18_Msk                  /*!< Event Mask on line 18 */
#define EXTI_EMR_MR19_Pos                   (19U)                              
#define EXTI_EMR_MR19_Msk                   (0x1UL << EXTI_EMR_MR19_Pos)        /*!< 0x00080000 */
#define EXTI_EMR_MR19                       EXTI_EMR_MR19_Msk                  /*!< Event Mask on line 19 */
#define EXTI_EMR_MR20_Pos                   (20U)                              
#define EXTI_EMR_MR20_Msk                   (0x1UL << EXTI_EMR_MR20_Pos)        /*!< 0x00100000 */
#define EXTI_EMR_MR20                       EXTI_EMR_MR20_Msk                  /*!< Event Mask on line 20 */
#define EXTI_EMR_MR21_Pos                   (21U)                              
#define EXTI_EMR_MR21_Msk                   (0x1UL << EXTI_EMR_MR21_Pos)        /*!< 0x00200000 */
#define EXTI_EMR_MR21                       EXTI_EMR_MR21_Msk                  /*!< Event Mask on line 21 */
#define EXTI_EMR_MR22_Pos                   (22U)                              
#define EXTI_EMR_MR22_Msk                   (0x1UL << EXTI_EMR_MR22_Pos)        /*!< 0x00400000 */
#define EXTI_EMR_MR22                       EXTI_EMR_MR22_Msk                  /*!< Event Mask on line 22 */
#define EXTI_EMR_MR23_Pos                   (23U)                              
#define EXTI_EMR_MR23_Msk                   (0x1UL << EXTI_EMR_MR23_Pos)        /*!< 0x00800000 */
#define EXTI_EMR_MR23                       EXTI_EMR_MR23_Msk                  /*!< Event Mask on line 23 */

/* References Defines */
#define  EXTI_EMR_EM0 EXTI_EMR_MR0
#define  EXTI_EMR_EM1 EXTI_EMR_MR1
#define  EXTI_EMR_EM2 EXTI_EMR_MR2
#define  EXTI_EMR_EM3 EXTI_EMR_MR3
#define  EXTI_EMR_EM4 EXTI_EMR_MR4
#define  EXTI_EMR_EM5 EXTI_EMR_MR5
#define  EXTI_EMR_EM6 EXTI_EMR_MR6
#define  EXTI_EMR_EM7 EXTI_EMR_MR7
#define  EXTI_EMR_EM8 EXTI_EMR_MR8
#define  EXTI_EMR_EM9 EXTI_EMR_MR9
#define  EXTI_EMR_EM10 EXTI_EMR_MR10
#define  EXTI_EMR_EM11 EXTI_EMR_MR11
#define  EXTI_EMR_EM12 EXTI_EMR_MR12
#define  EXTI_EMR_EM13 EXTI_EMR_MR13
#define  EXTI_EMR_EM14 EXTI_EMR_MR14
#define  EXTI_EMR_EM15 EXTI_EMR_MR15
#define  EXTI_EMR_EM16 EXTI_EMR_MR16
#define  EXTI_EMR_EM17 EXTI_EMR_MR17
#define  EXTI_EMR_EM18 EXTI_EMR_MR18
#define  EXTI_EMR_EM19 EXTI_EMR_MR19
#define  EXTI_EMR_EM20 EXTI_EMR_MR20
#define  EXTI_EMR_EM21 EXTI_EMR_MR21
#define  EXTI_EMR_EM22 EXTI_EMR_MR22
#define  EXTI_EMR_EM23 EXTI_EMR_MR23

/******************  Bit definition for EXTI_RTSR register  *******************/
#define EXTI_RTSR_TR0_Pos                   (0U)                               
#define EXTI_RTSR_TR0_Msk                   (0x1UL << EXTI_RTSR_TR0_Pos)        /*!< 0x00000001 */
#define EXTI_RTSR_TR0                       EXTI_RTSR_TR0_Msk                  /*!< Rising trigger event configuration bit of line 0 */
#define EXTI_RTSR_TR1_Pos                   (1U)                               
#define EXTI_RTSR_TR1_Msk                   (0x1UL << EXTI_RTSR_TR1_Pos)        /*!< 0x00000002 */
#define EXTI_RTSR_TR1                       EXTI_RTSR_TR1_Msk                  /*!< Rising trigger event configuration bit of line 1 */
#define EXTI_RTSR_TR2_Pos                   (2U)                               
#define EXTI_RTSR_TR2_Msk                   (0x1UL << EXTI_RTSR_TR2_Pos)        /*!< 0x00000004 */
#define EXTI_RTSR_TR2                       EXTI_RTSR_TR2_Msk                  /*!< Rising trigger event configuration bit of line 2 */
#define EXTI_RTSR_TR3_Pos                   (3U)                               
#define EXTI_RTSR_TR3_Msk                   (0x1UL << EXTI_RTSR_TR3_Pos)        /*!< 0x00000008 */
#define EXTI_RTSR_TR3                       EXTI_RTSR_TR3_Msk                  /*!< Rising trigger event configuration bit of line 3 */
#define EXTI_RTSR_TR4_Pos                   (4U)                               
#define EXTI_RTSR_TR4_Msk                   (0x1UL << EXTI_RTSR_TR4_Pos)        /*!< 0x00000010 */
#define EXTI_RTSR_TR4                       EXTI_RTSR_TR4_Msk                  /*!< Rising trigger event configuration bit of line 4 */
#define EXTI_RTSR_TR5_Pos                   (5U)                               
#define EXTI_RTSR_TR5_Msk                   (0x1UL << EXTI_RTSR_TR5_Pos)        /*!< 0x00000020 */
#define EXTI_RTSR_TR5                       EXTI_RTSR_TR5_Msk                  /*!< Rising trigger event configuration bit of line 5 */
#define EXTI_RTSR_TR6_Pos                   (6U)                               
#define EXTI_RTSR_TR6_Msk                   (0x1UL << EXTI_RTSR_TR6_Pos)        /*!< 0x00000040 */
#define EXTI_RTSR_TR6                       EXTI_RTSR_TR6_Msk                  /*!< Rising trigger event configuration bit of line 6 */
#define EXTI_RTSR_TR7_Pos                   (7U)                               
#define EXTI_RTSR_TR7_Msk                   (0x1UL << EXTI_RTSR_TR7_Pos)        /*!< 0x00000080 */
#define EXTI_RTSR_TR7                       EXTI_RTSR_TR7_Msk                  /*!< Rising trigger event configuration bit of line 7 */
#define EXTI_RTSR_TR8_Pos                   (8U)                               
#define EXTI_RTSR_TR8_Msk                   (0x1UL << EXTI_RTSR_TR8_Pos)        /*!< 0x00000100 */
#define EXTI_RTSR_TR8                       EXTI_RTSR_TR8_Msk                  /*!< Rising trigger event configuration bit of line 8 */
#define EXTI_RTSR_TR9_Pos                   (9U)                               
#define EXTI_RTSR_TR9_Msk                   (0x1UL << EXTI_RTSR_TR9_Pos)        /*!< 0x00000200 */
#define EXTI_RTSR_TR9                       EXTI_RTSR_TR9_Msk                  /*!< Rising trigger event configuration bit of line 9 */
#define EXTI_RTSR_TR10_Pos                  (10U)                              
#define EXTI_RTSR_TR10_Msk                  (0x1UL << EXTI_RTSR_TR10_Pos)       /*!< 0x00000400 */
#define EXTI_RTSR_TR10                      EXTI_RTSR_TR10_Msk                 /*!< Rising trigger event configuration bit of line 10 */
#define EXTI_RTSR_TR11_Pos                  (11U)                              
#define EXTI_RTSR_TR11_Msk                  (0x1UL << EXTI_RTSR_TR11_Pos)       /*!< 0x00000800 */
#define EXTI_RTSR_TR11                      EXTI_RTSR_TR11_Msk                 /*!< Rising trigger event configuration bit of line 11 */
#define EXTI_RTSR_TR12_Pos                  (12U)                              
#define EXTI_RTSR_TR12_Msk                  (0x1UL << EXTI_RTSR_TR12_Pos)       /*!< 0x00001000 */
#define EXTI_RTSR_TR12                      EXTI_RTSR_TR12_Msk                 /*!< Rising trigger event configuration bit of line 12 */
#define EXTI_RTSR_TR13_Pos                  (13U)                              
#define EXTI_RTSR_TR13_Msk                  (0x1UL << EXTI_RTSR_TR13_Pos)       /*!< 0x00002000 */
#define EXTI_RTSR_TR13                      EXTI_RTSR_TR13_Msk                 /*!< Rising trigger event configuration bit of line 13 */
#define EXTI_RTSR_TR14_Pos                  (14U)                              
#define EXTI_RTSR_TR14_Msk                  (0x1UL << EXTI_RTSR_TR14_Pos)       /*!< 0x00004000 */
#define EXTI_RTSR_TR14                      EXTI_RTSR_TR14_Msk                 /*!< Rising trigger event configuration bit of line 14 */
#define EXTI_RTSR_TR15_Pos                  (15U)                              
#define EXTI_RTSR_TR15_Msk                  (0x1UL << EXTI_RTSR_TR15_Pos)       /*!< 0x00008000 */
#define EXTI_RTSR_TR15                      EXTI_RTSR_TR15_Msk                 /*!< Rising trigger event configuration bit of line 15 */
#define EXTI_RTSR_TR16_Pos                  (16U)                              
#define EXTI_RTSR_TR16_Msk                  (0x1UL << EXTI_RTSR_TR16_Pos)       /*!< 0x00010000 */
#define EXTI_RTSR_TR16                      EXTI_RTSR_TR16_Msk                 /*!< Rising trigger event configuration bit of line 16 */
#define EXTI_RTSR_TR17_Pos                  (17U)                              
#define EXTI_RTSR_TR17_Msk                  (0x1UL << EXTI_RTSR_TR17_Pos)       /*!< 0x00020000 */
#define EXTI_RTSR_TR17                      EXTI_RTSR_TR17_Msk                 /*!< Rising trigger event configuration bit of line 17 */
#define EXTI_RTSR_TR18_Pos                  (18U)                              
#define EXTI_RTSR_TR18_Msk                  (0x1UL << EXTI_RTSR_TR18_Pos)       /*!< 0x00040000 */
#define EXTI_RTSR_TR18                      EXTI_RTSR_TR18_Msk                 /*!< Rising trigger event configuration bit of line 18 */
#define EXTI_RTSR_TR19_Pos                  (19U)                              
#define EXTI_RTSR_TR19_Msk                  (0x1UL << EXTI_RTSR_TR19_Pos)       /*!< 0x00080000 */
#define EXTI_RTSR_TR19                      EXTI_RTSR_TR19_Msk                 /*!< Rising trigger event configuration bit of line 19 */
#define EXTI_RTSR_TR20_Pos                  (20U)                              
#define EXTI_RTSR_TR20_Msk                  (0x1UL << EXTI_RTSR_TR20_Pos)       /*!< 0x00100000 */
#define EXTI_RTSR_TR20                      EXTI_RTSR_TR20_Msk                 /*!< Rising trigger event configuration bit of line 20 */
#define EXTI_RTSR_TR21_Pos                  (21U)                              
#define EXTI_RTSR_TR21_Msk                  (0x1UL << EXTI_RTSR_TR21_Pos)       /*!< 0x00200000 */
#define EXTI_RTSR_TR21                      EXTI_RTSR_TR21_Msk                 /*!< Rising trigger event configuration bit of line 21 */
#define EXTI_RTSR_TR22_Pos                  (22U)                              
#define EXTI_RTSR_TR22_Msk                  (0x1UL << EXTI_RTSR_TR22_Pos)       /*!< 0x00400000 */
#define EXTI_RTSR_TR22                      EXTI_RTSR_TR22_Msk                 /*!< Rising trigger event configuration bit of line 22 */
#define EXTI_RTSR_TR23_Pos                  (23U)                              
#define EXTI_RTSR_TR23_Msk                  (0x1UL << EXTI_RTSR_TR23_Pos)       /*!< 0x00800000 */
#define EXTI_RTSR_TR23                      EXTI_RTSR_TR23_Msk                 /*!< Rising trigger event configuration bit of line 23 */

/* References Defines */
#define  EXTI_RTSR_RT0 EXTI_RTSR_TR0
#define  EXTI_RTSR_RT1 EXTI_RTSR_TR1
#define  EXTI_RTSR_RT2 EXTI_RTSR_TR2
#define  EXTI_RTSR_RT3 EXTI_RTSR_TR3
#define  EXTI_RTSR_RT4 EXTI_RTSR_TR4
#define  EXTI_RTSR_RT5 EXTI_RTSR_TR5
#define  EXTI_RTSR_RT6 EXTI_RTSR_TR6
#define  EXTI_RTSR_RT7 EXTI_RTSR_TR7
#define  EXTI_RTSR_RT8 EXTI_RTSR_TR8
#define  EXTI_RTSR_RT9 EXTI_RTSR_TR9
#define  EXTI_RTSR_RT10 EXTI_RTSR_TR10
#define  EXTI_RTSR_RT11 EXTI_RTSR_TR11
#define  EXTI_RTSR_RT12 EXTI_RTSR_TR12
#define  EXTI_RTSR_RT13 EXTI_RTSR_TR13
#define  EXTI_RTSR_RT14 EXTI_RTSR_TR14
#define  EXTI_RTSR_RT15 EXTI_RTSR_TR15
#define  EXTI_RTSR_RT16 EXTI_RTSR_TR16
#define  EXTI_RTSR_RT17 EXTI_RTSR_TR17
#define  EXTI_RTSR_RT18 EXTI_RTSR_TR18
#define  EXTI_RTSR_RT19 EXTI_RTSR_TR19
#define  EXTI_RTSR_RT20 EXTI_RTSR_TR20
#define  EXTI_RTSR_RT21 EXTI_RTSR_TR21
#define  EXTI_RTSR_RT22 EXTI_RTSR_TR22
#define  EXTI_RTSR_RT23 EXTI_RTSR_TR23

/******************  Bit definition for EXTI_FTSR register  *******************/
#define EXTI_FTSR_TR0_Pos                   (0U)                               
#define EXTI_FTSR_TR0_Msk                   (0x1UL << EXTI_FTSR_TR0_Pos)        /*!< 0x00000001 */
#define EXTI_FTSR_TR0                       EXTI_FTSR_TR0_Msk                  /*!< Falling trigger event configuration bit of line 0 */
#define EXTI_FTSR_TR1_Pos                   (1U)                               
#define EXTI_FTSR_TR1_Msk                   (0x1UL << EXTI_FTSR_TR1_Pos)        /*!< 0x00000002 */
#define EXTI_FTSR_TR1                       EXTI_FTSR_TR1_Msk                  /*!< Falling trigger event configuration bit of line 1 */
#define EXTI_FTSR_TR2_Pos                   (2U)                               
#define EXTI_FTSR_TR2_Msk                   (0x1UL << EXTI_FTSR_TR2_Pos)        /*!< 0x00000004 */
#define EXTI_FTSR_TR2                       EXTI_FTSR_TR2_Msk                  /*!< Falling trigger event configuration bit of line 2 */
#define EXTI_FTSR_TR3_Pos                   (3U)                               
#define EXTI_FTSR_TR3_Msk                   (0x1UL << EXTI_FTSR_TR3_Pos)        /*!< 0x00000008 */
#define EXTI_FTSR_TR3                       EXTI_FTSR_TR3_Msk                  /*!< Falling trigger event configuration bit of line 3 */
#define EXTI_FTSR_TR4_Pos                   (4U)                               
#define EXTI_FTSR_TR4_Msk                   (0x1UL << EXTI_FTSR_TR4_Pos)        /*!< 0x00000010 */
#define EXTI_FTSR_TR4                       EXTI_FTSR_TR4_Msk                  /*!< Falling trigger event configuration bit of line 4 */
#define EXTI_FTSR_TR5_Pos                   (5U)                               
#define EXTI_FTSR_TR5_Msk                   (0x1UL << EXTI_FTSR_TR5_Pos)        /*!< 0x00000020 */
#define EXTI_FTSR_TR5                       EXTI_FTSR_TR5_Msk                  /*!< Falling trigger event configuration bit of line 5 */
#define EXTI_FTSR_TR6_Pos                   (6U)                               
#define EXTI_FTSR_TR6_Msk                   (0x1UL << EXTI_FTSR_TR6_Pos)        /*!< 0x00000040 */
#define EXTI_FTSR_TR6                       EXTI_FTSR_TR6_Msk                  /*!< Falling trigger event configuration bit of line 6 */
#define EXTI_FTSR_TR7_Pos                   (7U)                               
#define EXTI_FTSR_TR7_Msk                   (0x1UL << EXTI_FTSR_TR7_Pos)        /*!< 0x00000080 */
#define EXTI_FTSR_TR7                       EXTI_FTSR_TR7_Msk                  /*!< Falling trigger event configuration bit of line 7 */
#define EXTI_FTSR_TR8_Pos                   (8U)                               
#define EXTI_FTSR_TR8_Msk                   (0x1UL << EXTI_FTSR_TR8_Pos)        /*!< 0x00000100 */
#define EXTI_FTSR_TR8                       EXTI_FTSR_TR8_Msk                  /*!< Falling trigger event configuration bit of line 8 */
#define EXTI_FTSR_TR9_Pos                   (9U)                               
#define EXTI_FTSR_TR9_Msk                   (0x1UL << EXTI_FTSR_TR9_Pos)        /*!< 0x00000200 */
#define EXTI_FTSR_TR9                       EXTI_FTSR_TR9_Msk                  /*!< Falling trigger event configuration bit of line 9 */
#define EXTI_FTSR_TR10_Pos                  (10U)                              
#define EXTI_FTSR_TR10_Msk                  (0x1UL << EXTI_FTSR_TR10_Pos)       /*!< 0x00000400 */
#define EXTI_FTSR_TR10                      EXTI_FTSR_TR10_Msk                 /*!< Falling trigger event configuration bit of line 10 */
#define EXTI_FTSR_TR11_Pos                  (11U)                              
#define EXTI_FTSR_TR11_Msk                  (0x1UL << EXTI_FTSR_TR11_Pos)       /*!< 0x00000800 */
#define EXTI_FTSR_TR11                      EXTI_FTSR_TR11_Msk                 /*!< Falling trigger event configuration bit of line 11 */
#define EXTI_FTSR_TR12_Pos                  (12U)                              
#define EXTI_FTSR_TR12_Msk                  (0x1UL << EXTI_FTSR_TR12_Pos)       /*!< 0x00001000 */
#define EXTI_FTSR_TR12                      EXTI_FTSR_TR12_Msk                 /*!< Falling trigger event configuration bit of line 12 */
#define EXTI_FTSR_TR13_Pos                  (13U)                              
#define EXTI_FTSR_TR13_Msk                  (0x1UL << EXTI_FTSR_TR13_Pos)       /*!< 0x00002000 */
#define EXTI_FTSR_TR13                      EXTI_FTSR_TR13_Msk                 /*!< Falling trigger event configuration bit of line 13 */
#define EXTI_FTSR_TR14_Pos                  (14U)                              
#define EXTI_FTSR_TR14_Msk                  (0x1UL << EXTI_FTSR_TR14_Pos)       /*!< 0x00004000 */
#define EXTI_FTSR_TR14                      EXTI_FTSR_TR14_Msk                 /*!< Falling trigger event configuration bit of line 14 */
#define EXTI_FTSR_TR15_Pos                  (15U)                              
#define EXTI_FTSR_TR15_Msk                  (0x1UL << EXTI_FTSR_TR15_Pos)       /*!< 0x00008000 */
#define EXTI_FTSR_TR15                      EXTI_FTSR_TR15_Msk                 /*!< Falling trigger event configuration bit of line 15 */
#define EXTI_FTSR_TR16_Pos                  (16U)                              
#define EXTI_FTSR_TR16_Msk                  (0x1UL << EXTI_FTSR_TR16_Pos)       /*!< 0x00010000 */
#define EXTI_FTSR_TR16                      EXTI_FTSR_TR16_Msk                 /*!< Falling trigger event configuration bit of line 16 */
#define EXTI_FTSR_TR17_Pos                  (17U)                              
#define EXTI_FTSR_TR17_Msk                  (0x1UL << EXTI_FTSR_TR17_Pos)       /*!< 0x00020000 */
#define EXTI_FTSR_TR17                      EXTI_FTSR_TR17_Msk                 /*!< Falling trigger event configuration bit of line 17 */
#define EXTI_FTSR_TR18_Pos                  (18U)                              
#define EXTI_FTSR_TR18_Msk                  (0x1UL << EXTI_FTSR_TR18_Pos)       /*!< 0x00040000 */
#define EXTI_FTSR_TR18                      EXTI_FTSR_TR18_Msk                 /*!< Falling trigger event configuration bit of line 18 */
#define EXTI_FTSR_TR19_Pos                  (19U)                              
#define EXTI_FTSR_TR19_Msk                  (0x1UL << EXTI_FTSR_TR19_Pos)       /*!< 0x00080000 */
#define EXTI_FTSR_TR19                      EXTI_FTSR_TR19_Msk                 /*!< Falling trigger event configuration bit of line 19 */
#define EXTI_FTSR_TR20_Pos                  (20U)                              
#define EXTI_FTSR_TR20_Msk                  (0x1UL << EXTI_FTSR_TR20_Pos)       /*!< 0x00100000 */
#define EXTI_FTSR_TR20                      EXTI_FTSR_TR20_Msk                 /*!< Falling trigger event configuration bit of line 20 */
#define EXTI_FTSR_TR21_Pos                  (21U)                              
#define EXTI_FTSR_TR21_Msk                  (0x1UL << EXTI_FTSR_TR21_Pos)       /*!< 0x00200000 */
#define EXTI_FTSR_TR21                      EXTI_FTSR_TR21_Msk                 /*!< Falling trigger event configuration bit of line 21 */
#define EXTI_FTSR_TR22_Pos                  (22U)                              
#define EXTI_FTSR_TR22_Msk                  (0x1UL << EXTI_FTSR_TR22_Pos)       /*!< 0x00400000 */
#define EXTI_FTSR_TR22                      EXTI_FTSR_TR22_Msk                 /*!< Falling trigger event configuration bit of line 22 */
#define EXTI_FTSR_TR23_Pos                  (23U)                              
#define EXTI_FTSR_TR23_Msk                  (0x1UL << EXTI_FTSR_TR23_Pos)       /*!< 0x00800000 */
#define EXTI_FTSR_TR23                      EXTI_FTSR_TR23_Msk                 /*!< Falling trigger event configuration bit of line 23 */

/* References Defines */
#define  EXTI_FTSR_FT0 EXTI_FTSR_TR0
#define  EXTI_FTSR_FT1 EXTI_FTSR_TR1
#define  EXTI_FTSR_FT2 EXTI_FTSR_TR2
#define  EXTI_FTSR_FT3 EXTI_FTSR_TR3
#define  EXTI_FTSR_FT4 EXTI_FTSR_TR4
#define  EXTI_FTSR_FT5 EXTI_FTSR_TR5
#define  EXTI_FTSR_FT6 EXTI_FTSR_TR6
#define  EXTI_FTSR_FT7 EXTI_FTSR_TR7
#define  EXTI_FTSR_FT8 EXTI_FTSR_TR8
#define  EXTI_FTSR_FT9 EXTI_FTSR_TR9
#define  EXTI_FTSR_FT10 EXTI_FTSR_TR10
#define  EXTI_FTSR_FT11 EXTI_FTSR_TR11
#define  EXTI_FTSR_FT12 EXTI_FTSR_TR12
#define  EXTI_FTSR_FT13 EXTI_FTSR_TR13
#define  EXTI_FTSR_FT14 EXTI_FTSR_TR14
#define  EXTI_FTSR_FT15 EXTI_FTSR_TR15
#define  EXTI_FTSR_FT16 EXTI_FTSR_TR16
#define  EXTI_FTSR_FT17 EXTI_FTSR_TR17
#define  EXTI_FTSR_FT18 EXTI_FTSR_TR18
#define  EXTI_FTSR_FT19 EXTI_FTSR_TR19
#define  EXTI_FTSR_FT20 EXTI_FTSR_TR20
#define  EXTI_FTSR_FT21 EXTI_FTSR_TR21
#define  EXTI_FTSR_FT22 EXTI_FTSR_TR22
#define  EXTI_FTSR_FT23 EXTI_FTSR_TR23

/******************  Bit definition for EXTI_SWIER register  ******************/
#define EXTI_SWIER_SWIER0_Pos               (0U)                               
#define EXTI_SWIER_SWIER0_Msk               (0x1UL << EXTI_SWIER_SWIER0_Pos)    /*!< 0x00000001 */
#define EXTI_SWIER_SWIER0                   EXTI_SWIER_SWIER0_Msk              /*!< Software Interrupt on line 0 */
#define EXTI_SWIER_SWIER1_Pos               (1U)                               
#define EXTI_SWIER_SWIER1_Msk               (0x1UL << EXTI_SWIER_SWIER1_Pos)    /*!< 0x00000002 */
#define EXTI_SWIER_SWIER1                   EXTI_SWIER_SWIER1_Msk              /*!< Software Interrupt on line 1 */
#define EXTI_SWIER_SWIER2_Pos               (2U)                               
#define EXTI_SWIER_SWIER2_Msk               (0x1UL << EXTI_SWIER_SWIER2_Pos)    /*!< 0x00000004 */
#define EXTI_SWIER_SWIER2                   EXTI_SWIER_SWIER2_Msk              /*!< Software Interrupt on line 2 */
#define EXTI_SWIER_SWIER3_Pos               (3U)                               
#define EXTI_SWIER_SWIER3_Msk               (0x1UL << EXTI_SWIER_SWIER3_Pos)    /*!< 0x00000008 */
#define EXTI_SWIER_SWIER3                   EXTI_SWIER_SWIER3_Msk              /*!< Software Interrupt on line 3 */
#define EXTI_SWIER_SWIER4_Pos               (4U)                               
#define EXTI_SWIER_SWIER4_Msk               (0x1UL << EXTI_SWIER_SWIER4_Pos)    /*!< 0x00000010 */
#define EXTI_SWIER_SWIER4                   EXTI_SWIER_SWIER4_Msk              /*!< Software Interrupt on line 4 */
#define EXTI_SWIER_SWIER5_Pos               (5U)                               
#define EXTI_SWIER_SWIER5_Msk               (0x1UL << EXTI_SWIER_SWIER5_Pos)    /*!< 0x00000020 */
#define EXTI_SWIER_SWIER5                   EXTI_SWIER_SWIER5_Msk              /*!< Software Interrupt on line 5 */
#define EXTI_SWIER_SWIER6_Pos               (6U)                               
#define EXTI_SWIER_SWIER6_Msk               (0x1UL << EXTI_SWIER_SWIER6_Pos)    /*!< 0x00000040 */
#define EXTI_SWIER_SWIER6                   EXTI_SWIER_SWIER6_Msk              /*!< Software Interrupt on line 6 */
#define EXTI_SWIER_SWIER7_Pos               (7U)                               
#define EXTI_SWIER_SWIER7_Msk               (0x1UL << EXTI_SWIER_SWIER7_Pos)    /*!< 0x00000080 */
#define EXTI_SWIER_SWIER7                   EXTI_SWIER_SWIER7_Msk              /*!< Software Interrupt on line 7 */
#define EXTI_SWIER_SWIER8_Pos               (8U)                               
#define EXTI_SWIER_SWIER8_Msk               (0x1UL << EXTI_SWIER_SWIER8_Pos)    /*!< 0x00000100 */
#define EXTI_SWIER_SWIER8                   EXTI_SWIER_SWIER8_Msk              /*!< Software Interrupt on line 8 */
#define EXTI_SWIER_SWIER9_Pos               (9U)                               
#define EXTI_SWIER_SWIER9_Msk               (0x1UL << EXTI_SWIER_SWIER9_Pos)    /*!< 0x00000200 */
#define EXTI_SWIER_SWIER9                   EXTI_SWIER_SWIER9_Msk              /*!< Software Interrupt on line 9 */
#define EXTI_SWIER_SWIER10_Pos              (10U)                              
#define EXTI_SWIER_SWIER10_Msk              (0x1UL << EXTI_SWIER_SWIER10_Pos)   /*!< 0x00000400 */
#define EXTI_SWIER_SWIER10                  EXTI_SWIER_SWIER10_Msk             /*!< Software Interrupt on line 10 */
#define EXTI_SWIER_SWIER11_Pos              (11U)                              
#define EXTI_SWIER_SWIER11_Msk              (0x1UL << EXTI_SWIER_SWIER11_Pos)   /*!< 0x00000800 */
#define EXTI_SWIER_SWIER11                  EXTI_SWIER_SWIER11_Msk             /*!< Software Interrupt on line 11 */
#define EXTI_SWIER_SWIER12_Pos              (12U)                              
#define EXTI_SWIER_SWIER12_Msk              (0x1UL << EXTI_SWIER_SWIER12_Pos)   /*!< 0x00001000 */
#define EXTI_SWIER_SWIER12                  EXTI_SWIER_SWIER12_Msk             /*!< Software Interrupt on line 12 */
#define EXTI_SWIER_SWIER13_Pos              (13U)                              
#define EXTI_SWIER_SWIER13_Msk              (0x1UL << EXTI_SWIER_SWIER13_Pos)   /*!< 0x00002000 */
#define EXTI_SWIER_SWIER13                  EXTI_SWIER_SWIER13_Msk             /*!< Software Interrupt on line 13 */
#define EXTI_SWIER_SWIER14_Pos              (14U)                              
#define EXTI_SWIER_SWIER14_Msk              (0x1UL << EXTI_SWIER_SWIER14_Pos)   /*!< 0x00004000 */
#define EXTI_SWIER_SWIER14                  EXTI_SWIER_SWIER14_Msk             /*!< Software Interrupt on line 14 */
#define EXTI_SWIER_SWIER15_Pos              (15U)                              
#define EXTI_SWIER_SWIER15_Msk              (0x1UL << EXTI_SWIER_SWIER15_Pos)   /*!< 0x00008000 */
#define EXTI_SWIER_SWIER15                  EXTI_SWIER_SWIER15_Msk             /*!< Software Interrupt on line 15 */
#define EXTI_SWIER_SWIER16_Pos              (16U)                              
#define EXTI_SWIER_SWIER16_Msk              (0x1UL << EXTI_SWIER_SWIER16_Pos)   /*!< 0x00010000 */
#define EXTI_SWIER_SWIER16                  EXTI_SWIER_SWIER16_Msk             /*!< Software Interrupt on line 16 */
#define EXTI_SWIER_SWIER17_Pos              (17U)                              
#define EXTI_SWIER_SWIER17_Msk              (0x1UL << EXTI_SWIER_SWIER17_Pos)   /*!< 0x00020000 */
#define EXTI_SWIER_SWIER17                  EXTI_SWIER_SWIER17_Msk             /*!< Software Interrupt on line 17 */
#define EXTI_SWIER_SWIER18_Pos              (18U)                              
#define EXTI_SWIER_SWIER18_Msk              (0x1UL << EXTI_SWIER_SWIER18_Pos)   /*!< 0x00040000 */
#define EXTI_SWIER_SWIER18                  EXTI_SWIER_SWIER18_Msk             /*!< Software Interrupt on line 18 */
#define EXTI_SWIER_SWIER19_Pos              (19U)                              
#define EXTI_SWIER_SWIER19_Msk              (0x1UL << EXTI_SWIER_SWIER19_Pos)   /*!< 0x00080000 */
#define EXTI_SWIER_SWIER19                  EXTI_SWIER_SWIER19_Msk             /*!< Software Interrupt on line 19 */
#define EXTI_SWIER_SWIER20_Pos              (20U)                              
#define EXTI_SWIER_SWIER20_Msk              (0x1UL << EXTI_SWIER_SWIER20_Pos)   /*!< 0x00100000 */
#define EXTI_SWIER_SWIER20                  EXTI_SWIER_SWIER20_Msk             /*!< Software Interrupt on line 20 */
#define EXTI_SWIER_SWIER21_Pos              (21U)                              
#define EXTI_SWIER_SWIER21_Msk              (0x1UL << EXTI_SWIER_SWIER21_Pos)   /*!< 0x00200000 */
#define EXTI_SWIER_SWIER21                  EXTI_SWIER_SWIER21_Msk             /*!< Software Interrupt on line 21 */
#define EXTI_SWIER_SWIER22_Pos              (22U)                              
#define EXTI_SWIER_SWIER22_Msk              (0x1UL << EXTI_SWIER_SWIER22_Pos)   /*!< 0x00400000 */
#define EXTI_SWIER_SWIER22                  EXTI_SWIER_SWIER22_Msk             /*!< Software Interrupt on line 22 */
#define EXTI_SWIER_SWIER23_Pos              (23U)                              
#define EXTI_SWIER_SWIER23_Msk              (0x1UL << EXTI_SWIER_SWIER23_Pos)   /*!< 0x00800000 */
#define EXTI_SWIER_SWIER23                  EXTI_SWIER_SWIER23_Msk             /*!< Software Interrupt on line 23 */

/* References Defines */
#define  EXTI_SWIER_SWI0 EXTI_SWIER_SWIER0
#define  EXTI_SWIER_SWI1 EXTI_SWIER_SWIER1
#define  EXTI_SWIER_SWI2 EXTI_SWIER_SWIER2
#define  EXTI_SWIER_SWI3 EXTI_SWIER_SWIER3
#define  EXTI_SWIER_SWI4 EXTI_SWIER_SWIER4
#define  EXTI_SWIER_SWI5 EXTI_SWIER_SWIER5
#define  EXTI_SWIER_SWI6 EXTI_SWIER_SWIER6
#define  EXTI_SWIER_SWI7 EXTI_SWIER_SWIER7
#define  EXTI_SWIER_SWI8 EXTI_SWIER_SWIER8
#define  EXTI_SWIER_SWI9 EXTI_SWIER_SWIER9
#define  EXTI_SWIER_SWI10 EXTI_SWIER_SWIER10
#define  EXTI_SWIER_SWI11 EXTI_SWIER_SWIER11
#define  EXTI_SWIER_SWI12 EXTI_SWIER_SWIER12
#define  EXTI_SWIER_SWI13 EXTI_SWIER_SWIER13
#define  EXTI_SWIER_SWI14 EXTI_SWIER_SWIER14
#define  EXTI_SWIER_SWI15 EXTI_SWIER_SWIER15
#define  EXTI_SWIER_SWI16 EXTI_SWIER_SWIER16
#define  EXTI_SWIER_SWI17 EXTI_SWIER_SWIER17
#define  EXTI_SWIER_SWI18 EXTI_SWIER_SWIER18
#define  EXTI_SWIER_SWI19 EXTI_SWIER_SWIER19
#define  EXTI_SWIER_SWI20 EXTI_SWIER_SWIER20
#define  EXTI_SWIER_SWI21 EXTI_SWIER_SWIER21
#define  EXTI_SWIER_SWI22 EXTI_SWIER_SWIER22
#define  EXTI_SWIER_SWI23 EXTI_SWIER_SWIER23

/*******************  Bit definition for EXTI_PR register  ********************/
#define EXTI_PR_PR0_Pos                     (0U)                               
#define EXTI_PR_PR0_Msk                     (0x1UL << EXTI_PR_PR0_Pos)          /*!< 0x00000001 */
#define EXTI_PR_PR0                         EXTI_PR_PR0_Msk                    /*!< Pending bit for line 0 */
#define EXTI_PR_PR1_Pos                     (1U)                               
#define EXTI_PR_PR1_Msk                     (0x1UL << EXTI_PR_PR1_Pos)          /*!< 0x00000002 */
#define EXTI_PR_PR1                         EXTI_PR_PR1_Msk                    /*!< Pending bit for line 1 */
#define EXTI_PR_PR2_Pos                     (2U)                               
#define EXTI_PR_PR2_Msk                     (0x1UL << EXTI_PR_PR2_Pos)          /*!< 0x00000004 */
#define EXTI_PR_PR2                         EXTI_PR_PR2_Msk                    /*!< Pending bit for line 2 */
#define EXTI_PR_PR3_Pos                     (3U)                               
#define EXTI_PR_PR3_Msk                     (0x1UL << EXTI_PR_PR3_Pos)          /*!< 0x00000008 */
#define EXTI_PR_PR3                         EXTI_PR_PR3_Msk                    /*!< Pending bit for line 3 */
#define EXTI_PR_PR4_Pos                     (4U)                               
#define EXTI_PR_PR4_Msk                     (0x1UL << EXTI_PR_PR4_Pos)          /*!< 0x00000010 */
#define EXTI_PR_PR4                         EXTI_PR_PR4_Msk                    /*!< Pending bit for line 4 */
#define EXTI_PR_PR5_Pos                     (5U)                               
#define EXTI_PR_PR5_Msk                     (0x1UL << EXTI_PR_PR5_Pos)          /*!< 0x00000020 */
#define EXTI_PR_PR5                         EXTI_PR_PR5_Msk                    /*!< Pending bit for line 5 */
#define EXTI_PR_PR6_Pos                     (6U)                               
#define EXTI_PR_PR6_Msk                     (0x1UL << EXTI_PR_PR6_Pos)          /*!< 0x00000040 */
#define EXTI_PR_PR6                         EXTI_PR_PR6_Msk                    /*!< Pending bit for line 6 */
#define EXTI_PR_PR7_Pos                     (7U)                               
#define EXTI_PR_PR7_Msk                     (0x1UL << EXTI_PR_PR7_Pos)          /*!< 0x00000080 */
#define EXTI_PR_PR7                         EXTI_PR_PR7_Msk                    /*!< Pending bit for line 7 */
#define EXTI_PR_PR8_Pos                     (8U)                               
#define EXTI_PR_PR8_Msk                     (0x1UL << EXTI_PR_PR8_Pos)          /*!< 0x00000100 */
#define EXTI_PR_PR8                         EXTI_PR_PR8_Msk                    /*!< Pending bit for line 8 */
#define EXTI_PR_PR9_Pos                     (9U)                               
#define EXTI_PR_PR9_Msk                     (0x1UL << EXTI_PR_PR9_Pos)          /*!< 0x00000200 */
#define EXTI_PR_PR9                         EXTI_PR_PR9_Msk                    /*!< Pending bit for line 9 */
#define EXTI_PR_PR10_Pos                    (10U)                              
#define EXTI_PR_PR10_Msk                    (0x1UL << EXTI_PR_PR10_Pos)         /*!< 0x00000400 */
#define EXTI_PR_PR10                        EXTI_PR_PR10_Msk                   /*!< Pending bit for line 10 */
#define EXTI_PR_PR11_Pos                    (11U)                              
#define EXTI_PR_PR11_Msk                    (0x1UL << EXTI_PR_PR11_Pos)         /*!< 0x00000800 */
#define EXTI_PR_PR11                        EXTI_PR_PR11_Msk                   /*!< Pending bit for line 11 */
#define EXTI_PR_PR12_Pos                    (12U)                              
#define EXTI_PR_PR12_Msk                    (0x1UL << EXTI_PR_PR12_Pos)         /*!< 0x00001000 */
#define EXTI_PR_PR12                        EXTI_PR_PR12_Msk                   /*!< Pending bit for line 12 */
#define EXTI_PR_PR13_Pos                    (13U)                              
#define EXTI_PR_PR13_Msk                    (0x1UL << EXTI_PR_PR13_Pos)         /*!< 0x00002000 */
#define EXTI_PR_PR13                        EXTI_PR_PR13_Msk                   /*!< Pending bit for line 13 */
#define EXTI_PR_PR14_Pos                    (14U)                              
#define EXTI_PR_PR14_Msk                    (0x1UL << EXTI_PR_PR14_Pos)         /*!< 0x00004000 */
#define EXTI_PR_PR14                        EXTI_PR_PR14_Msk                   /*!< Pending bit for line 14 */
#define EXTI_PR_PR15_Pos                    (15U)                              
#define EXTI_PR_PR15_Msk                    (0x1UL << EXTI_PR_PR15_Pos)         /*!< 0x00008000 */
#define EXTI_PR_PR15                        EXTI_PR_PR15_Msk                   /*!< Pending bit for line 15 */
#define EXTI_PR_PR16_Pos                    (16U)                              
#define EXTI_PR_PR16_Msk                    (0x1UL << EXTI_PR_PR16_Pos)         /*!< 0x00010000 */
#define EXTI_PR_PR16                        EXTI_PR_PR16_Msk                   /*!< Pending bit for line 16 */
#define EXTI_PR_PR17_Pos                    (17U)                              
#define EXTI_PR_PR17_Msk                    (0x1UL << EXTI_PR_PR17_Pos)         /*!< 0x00020000 */
#define EXTI_PR_PR17                        EXTI_PR_PR17_Msk                   /*!< Pending bit for line 17 */
#define EXTI_PR_PR18_Pos                    (18U)                              
#define EXTI_PR_PR18_Msk                    (0x1UL << EXTI_PR_PR18_Pos)         /*!< 0x00040000 */
#define EXTI_PR_PR18                        EXTI_PR_PR18_Msk                   /*!< Pending bit for line 18 */
#define EXTI_PR_PR19_Pos                    (19U)                              
#define EXTI_PR_PR19_Msk                    (0x1UL << EXTI_PR_PR19_Pos)         /*!< 0x00080000 */
#define EXTI_PR_PR19                        EXTI_PR_PR19_Msk                   /*!< Pending bit for line 19 */
#define EXTI_PR_PR20_Pos                    (20U)                              
#define EXTI_PR_PR20_Msk                    (0x1UL << EXTI_PR_PR20_Pos)         /*!< 0x00100000 */
#define EXTI_PR_PR20                        EXTI_PR_PR20_Msk                   /*!< Pending bit for line 20 */
#define EXTI_PR_PR21_Pos                    (21U)                              
#define EXTI_PR_PR21_Msk                    (0x1UL << EXTI_PR_PR21_Pos)         /*!< 0x00200000 */
#define EXTI_PR_PR21                        EXTI_PR_PR21_Msk                   /*!< Pending bit for line 21 */
#define EXTI_PR_PR22_Pos                    (22U)                              
#define EXTI_PR_PR22_Msk                    (0x1UL << EXTI_PR_PR22_Pos)         /*!< 0x00400000 */
#define EXTI_PR_PR22                        EXTI_PR_PR22_Msk                   /*!< Pending bit for line 22 */
#define EXTI_PR_PR23_Pos                    (23U)                              
#define EXTI_PR_PR23_Msk                    (0x1UL << EXTI_PR_PR23_Pos)         /*!< 0x00800000 */
#define EXTI_PR_PR23                        EXTI_PR_PR23_Msk                   /*!< Pending bit for line 23 */

/* References Defines */
#define  EXTI_PR_PIF0 EXTI_PR_PR0
#define  EXTI_PR_PIF1 EXTI_PR_PR1
#define  EXTI_PR_PIF2 EXTI_PR_PR2
#define  EXTI_PR_PIF3 EXTI_PR_PR3
#define  EXTI_PR_PIF4 EXTI_PR_PR4
#define  EXTI_PR_PIF5 EXTI_PR_PR5
#define  EXTI_PR_PIF6 EXTI_PR_PR6
#define  EXTI_PR_PIF7 EXTI_PR_PR7
#define  EXTI_PR_PIF8 EXTI_PR_PR8
#define  EXTI_PR_PIF9 EXTI_PR_PR9
#define  EXTI_PR_PIF10 EXTI_PR_PR10
#define  EXTI_PR_PIF11 EXTI_PR_PR11
#define  EXTI_PR_PIF12 EXTI_PR_PR12
#define  EXTI_PR_PIF13 EXTI_PR_PR13
#define  EXTI_PR_PIF14 EXTI_PR_PR14
#define  EXTI_PR_PIF15 EXTI_PR_PR15
#define  EXTI_PR_PIF16 EXTI_PR_PR16
#define  EXTI_PR_PIF17 EXTI_PR_PR17
#define  EXTI_PR_PIF18 EXTI_PR_PR18
#define  EXTI_PR_PIF19 EXTI_PR_PR19
#define  EXTI_PR_PIF20 EXTI_PR_PR20
#define  EXTI_PR_PIF21 EXTI_PR_PR21
#define  EXTI_PR_PIF22 EXTI_PR_PR22
#define  EXTI_PR_PIF23 EXTI_PR_PR23

/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODER0_Pos                (0U)                              
#define GPIO_MODER_MODER0_Msk                (0x3UL << GPIO_MODER_MODER0_Pos)   /*!< 0x00000003 */
#define GPIO_MODER_MODER0                    GPIO_MODER_MODER0_Msk             
#define GPIO_MODER_MODER0_0                  (0x1UL << GPIO_MODER_MODER0_Pos)   /*!< 0x00000001 */
#define GPIO_MODER_MODER0_1                  (0x2UL << GPIO_MODER_MODER0_Pos)   /*!< 0x00000002 */

#define GPIO_MODER_MODER1_Pos                (2U)                              
#define GPIO_MODER_MODER1_Msk                (0x3UL << GPIO_MODER_MODER1_Pos)   /*!< 0x0000000C */
#define GPIO_MODER_MODER1                    GPIO_MODER_MODER1_Msk             
#define GPIO_MODER_MODER1_0                  (0x1UL << GPIO_MODER_MODER1_Pos)   /*!< 0x00000004 */
#define GPIO_MODER_MODER1_1                  (0x2UL << GPIO_MODER_MODER1_Pos)   /*!< 0x00000008 */

#define GPIO_MODER_MODER2_Pos                (4U)                              
#define GPIO_MODER_MODER2_Msk                (0x3UL << GPIO_MODER_MODER2_Pos)   /*!< 0x00000030 */
#define GPIO_MODER_MODER2                    GPIO_MODER_MODER2_Msk             
#define GPIO_MODER_MODER2_0                  (0x1UL << GPIO_MODER_MODER2_Pos)   /*!< 0x00000010 */
#define GPIO_MODER_MODER2_1                  (0x2UL << GPIO_MODER_MODER2_Pos)   /*!< 0x00000020 */

#define GPIO_MODER_MODER3_Pos                (6U)                              
#define GPIO_MODER_MODER3_Msk                (0x3UL << GPIO_MODER_MODER3_Pos)   /*!< 0x000000C0 */
#define GPIO_MODER_MODER3                    GPIO_MODER_MODER3_Msk             
#define GPIO_MODER_MODER3_0                  (0x1UL << GPIO_MODER_MODER3_Pos)   /*!< 0x00000040 */
#define GPIO_MODER_MODER3_1                  (0x2UL << GPIO_MODER_MODER3_Pos)   /*!< 0x00000080 */

#define GPIO_MODER_MODER4_Pos                (8U)                              
#define GPIO_MODER_MODER4_Msk                (0x3UL << GPIO_MODER_MODER4_Pos)   /*!< 0x00000300 */
#define GPIO_MODER_MODER4                    GPIO_MODER_MODER4_Msk             
#define GPIO_MODER_MODER4_0                  (0x1UL << GPIO_MODER_MODER4_Pos)   /*!< 0x00000100 */
#define GPIO_MODER_MODER4_1                  (0x2UL << GPIO_MODER_MODER4_Pos)   /*!< 0x00000200 */

#define GPIO_MODER_MODER5_Pos                (10U)                             
#define GPIO_MODER_MODER5_Msk                (0x3UL << GPIO_MODER_MODER5_Pos)   /*!< 0x00000C00 */
#define GPIO_MODER_MODER5                    GPIO_MODER_MODER5_Msk             
#define GPIO_MODER_MODER5_0                  (0x1UL << GPIO_MODER_MODER5_Pos)   /*!< 0x00000400 */
#define GPIO_MODER_MODER5_1                  (0x2UL << GPIO_MODER_MODER5_Pos)   /*!< 0x00000800 */

#define GPIO_MODER_MODER6_Pos                (12U)                             
#define GPIO_MODER_MODER6_Msk                (0x3UL << GPIO_MODER_MODER6_Pos)   /*!< 0x00003000 */
#define GPIO_MODER_MODER6                    GPIO_MODER_MODER6_Msk             
#define GPIO_MODER_MODER6_0                  (0x1UL << GPIO_MODER_MODER6_Pos)   /*!< 0x00001000 */
#define GPIO_MODER_MODER6_1                  (0x2UL << GPIO_MODER_MODER6_Pos)   /*!< 0x00002000 */

#define GPIO_MODER_MODER7_Pos                (14U)                             
#define GPIO_MODER_MODER7_Msk                (0x3UL << GPIO_MODER_MODER7_Pos)   /*!< 0x0000C000 */
#define GPIO_MODER_MODER7                    GPIO_MODER_MODER7_Msk             
#define GPIO_MODER_MODER7_0                  (0x1UL << GPIO_MODER_MODER7_Pos)   /*!< 0x00004000 */
#define GPIO_MODER_MODER7_1                  (0x2UL << GPIO_MODER_MODER7_Pos)   /*!< 0x00008000 */

#define GPIO_MODER_MODER8_Pos                (16U)                             
#define GPIO_MODER_MODER8_Msk                (0x3UL << GPIO_MODER_MODER8_Pos)   /*!< 0x00030000 */
#define GPIO_MODER_MODER8                    GPIO_MODER_MODER8_Msk             
#define GPIO_MODER_MODER8_0                  (0x1UL << GPIO_MODER_MODER8_Pos)   /*!< 0x00010000 */
#define GPIO_MODER_MODER8_1                  (0x2UL << GPIO_MODER_MODER8_Pos)   /*!< 0x00020000 */

#define GPIO_MODER_MODER9_Pos                (18U)                             
#define GPIO_MODER_MODER9_Msk                (0x3UL << GPIO_MODER_MODER9_Pos)   /*!< 0x000C0000 */
#define GPIO_MODER_MODER9                    GPIO_MODER_MODER9_Msk             
#define GPIO_MODER_MODER9_0                  (0x1UL << GPIO_MODER_MODER9_Pos)   /*!< 0x00040000 */
#define GPIO_MODER_MODER9_1                  (0x2UL << GPIO_MODER_MODER9_Pos)   /*!< 0x00080000 */

#define GPIO_MODER_MODER10_Pos               (20U)                             
#define GPIO_MODER_MODER10_Msk               (0x3UL << GPIO_MODER_MODER10_Pos)  /*!< 0x00300000 */
#define GPIO_MODER_MODER10                   GPIO_MODER_MODER10_Msk            
#define GPIO_MODER_MODER10_0                 (0x1UL << GPIO_MODER_MODER10_Pos)  /*!< 0x00100000 */
#define GPIO_MODER_MODER10_1                 (0x2UL << GPIO_MODER_MODER10_Pos)  /*!< 0x00200000 */

#define GPIO_MODER_MODER11_Pos               (22U)                             
#define GPIO_MODER_MODER11_Msk               (0x3UL << GPIO_MODER_MODER11_Pos)  /*!< 0x00C00000 */
#define GPIO_MODER_MODER11                   GPIO_MODER_MODER11_Msk            
#define GPIO_MODER_MODER11_0                 (0x1UL << GPIO_MODER_MODER11_Pos)  /*!< 0x00400000 */
#define GPIO_MODER_MODER11_1                 (0x2UL << GPIO_MODER_MODER11_Pos)  /*!< 0x00800000 */

#define GPIO_MODER_MODER12_Pos               (24U)                             
#define GPIO_MODER_MODER12_Msk               (0x3UL << GPIO_MODER_MODER12_Pos)  /*!< 0x03000000 */
#define GPIO_MODER_MODER12                   GPIO_MODER_MODER12_Msk            
#define GPIO_MODER_MODER12_0                 (0x1UL << GPIO_MODER_MODER12_Pos)  /*!< 0x01000000 */
#define GPIO_MODER_MODER12_1                 (0x2UL << GPIO_MODER_MODER12_Pos)  /*!< 0x02000000 */

#define GPIO_MODER_MODER13_Pos               (26U)                             
#define GPIO_MODER_MODER13_Msk               (0x3UL << GPIO_MODER_MODER13_Pos)  /*!< 0x0C000000 */
#define GPIO_MODER_MODER13                   GPIO_MODER_MODER13_Msk            
#define GPIO_MODER_MODER13_0                 (0x1UL << GPIO_MODER_MODER13_Pos)  /*!< 0x04000000 */
#define GPIO_MODER_MODER13_1                 (0x2UL << GPIO_MODER_MODER13_Pos)  /*!< 0x08000000 */

#define GPIO_MODER_MODER14_Pos               (28U)                             
#define GPIO_MODER_MODER14_Msk               (0x3UL << GPIO_MODER_MODER14_Pos)  /*!< 0x30000000 */
#define GPIO_MODER_MODER14                   GPIO_MODER_MODER14_Msk            
#define GPIO_MODER_MODER14_0                 (0x1UL << GPIO_MODER_MODER14_Pos)  /*!< 0x10000000 */
#define GPIO_MODER_MODER14_1                 (0x2UL << GPIO_MODER_MODER14_Pos)  /*!< 0x20000000 */

#define GPIO_MODER_MODER15_Pos               (30U)                             
#define GPIO_MODER_MODER15_Msk               (0x3UL << GPIO_MODER_MODER15_Pos)  /*!< 0xC0000000 */
#define GPIO_MODER_MODER15                   GPIO_MODER_MODER15_Msk            
#define GPIO_MODER_MODER15_0                 (0x1UL << GPIO_MODER_MODER15_Pos)  /*!< 0x40000000 */
#define GPIO_MODER_MODER15_1                 (0x2UL << GPIO_MODER_MODER15_Pos)  /*!< 0x80000000 */

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT_0                     (0x00000001U)                     
#define GPIO_OTYPER_OT_1                     (0x00000002U)                     
#define GPIO_OTYPER_OT_2                     (0x00000004U)                     
#define GPIO_OTYPER_OT_3                     (0x00000008U)                     
#define GPIO_OTYPER_OT_4                     (0x00000010U)                     
#define GPIO_OTYPER_OT_5                     (0x00000020U)                     
#define GPIO_OTYPER_OT_6                     (0x00000040U)                     
#define GPIO_OTYPER_OT_7                     (0x00000080U)                     
#define GPIO_OTYPER_OT_8                     (0x00000100U)                     
#define GPIO_OTYPER_OT_9                     (0x00000200U)                     
#define GPIO_OTYPER_OT_10                    (0x00000400U)                     
#define GPIO_OTYPER_OT_11                    (0x00000800U)                     
#define GPIO_OTYPER_OT_12                    (0x00001000U)                     
#define GPIO_OTYPER_OT_13                    (0x00002000U)                     
#define GPIO_OTYPER_OT_14                    (0x00004000U)                     
#define GPIO_OTYPER_OT_15                    (0x00008000U)                     

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDER_OSPEEDR0_Pos           (0U)                              
#define GPIO_OSPEEDER_OSPEEDR0_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR0_Pos) /*!< 0x00000003 */
#define GPIO_OSPEEDER_OSPEEDR0               GPIO_OSPEEDER_OSPEEDR0_Msk        
#define GPIO_OSPEEDER_OSPEEDR0_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR0_Pos) /*!< 0x00000001 */
#define GPIO_OSPEEDER_OSPEEDR0_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR0_Pos) /*!< 0x00000002 */

#define GPIO_OSPEEDER_OSPEEDR1_Pos           (2U)                              
#define GPIO_OSPEEDER_OSPEEDR1_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR1_Pos) /*!< 0x0000000C */
#define GPIO_OSPEEDER_OSPEEDR1               GPIO_OSPEEDER_OSPEEDR1_Msk        
#define GPIO_OSPEEDER_OSPEEDR1_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR1_Pos) /*!< 0x00000004 */
#define GPIO_OSPEEDER_OSPEEDR1_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR1_Pos) /*!< 0x00000008 */

#define GPIO_OSPEEDER_OSPEEDR2_Pos           (4U)                              
#define GPIO_OSPEEDER_OSPEEDR2_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR2_Pos) /*!< 0x00000030 */
#define GPIO_OSPEEDER_OSPEEDR2               GPIO_OSPEEDER_OSPEEDR2_Msk        
#define GPIO_OSPEEDER_OSPEEDR2_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR2_Pos) /*!< 0x00000010 */
#define GPIO_OSPEEDER_OSPEEDR2_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR2_Pos) /*!< 0x00000020 */

#define GPIO_OSPEEDER_OSPEEDR3_Pos           (6U)                              
#define GPIO_OSPEEDER_OSPEEDR3_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR3_Pos) /*!< 0x000000C0 */
#define GPIO_OSPEEDER_OSPEEDR3               GPIO_OSPEEDER_OSPEEDR3_Msk        
#define GPIO_OSPEEDER_OSPEEDR3_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR3_Pos) /*!< 0x00000040 */
#define GPIO_OSPEEDER_OSPEEDR3_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR3_Pos) /*!< 0x00000080 */

#define GPIO_OSPEEDER_OSPEEDR4_Pos           (8U)                              
#define GPIO_OSPEEDER_OSPEEDR4_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR4_Pos) /*!< 0x00000300 */
#define GPIO_OSPEEDER_OSPEEDR4               GPIO_OSPEEDER_OSPEEDR4_Msk        
#define GPIO_OSPEEDER_OSPEEDR4_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR4_Pos) /*!< 0x00000100 */
#define GPIO_OSPEEDER_OSPEEDR4_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR4_Pos) /*!< 0x00000200 */

#define GPIO_OSPEEDER_OSPEEDR5_Pos           (10U)                             
#define GPIO_OSPEEDER_OSPEEDR5_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR5_Pos) /*!< 0x00000C00 */
#define GPIO_OSPEEDER_OSPEEDR5               GPIO_OSPEEDER_OSPEEDR5_Msk        
#define GPIO_OSPEEDER_OSPEEDR5_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR5_Pos) /*!< 0x00000400 */
#define GPIO_OSPEEDER_OSPEEDR5_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR5_Pos) /*!< 0x00000800 */

#define GPIO_OSPEEDER_OSPEEDR6_Pos           (12U)                             
#define GPIO_OSPEEDER_OSPEEDR6_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR6_Pos) /*!< 0x00003000 */
#define GPIO_OSPEEDER_OSPEEDR6               GPIO_OSPEEDER_OSPEEDR6_Msk        
#define GPIO_OSPEEDER_OSPEEDR6_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR6_Pos) /*!< 0x00001000 */
#define GPIO_OSPEEDER_OSPEEDR6_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR6_Pos) /*!< 0x00002000 */

#define GPIO_OSPEEDER_OSPEEDR7_Pos           (14U)                             
#define GPIO_OSPEEDER_OSPEEDR7_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR7_Pos) /*!< 0x0000C000 */
#define GPIO_OSPEEDER_OSPEEDR7               GPIO_OSPEEDER_OSPEEDR7_Msk        
#define GPIO_OSPEEDER_OSPEEDR7_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR7_Pos) /*!< 0x00004000 */
#define GPIO_OSPEEDER_OSPEEDR7_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR7_Pos) /*!< 0x00008000 */

#define GPIO_OSPEEDER_OSPEEDR8_Pos           (16U)                             
#define GPIO_OSPEEDER_OSPEEDR8_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR8_Pos) /*!< 0x00030000 */
#define GPIO_OSPEEDER_OSPEEDR8               GPIO_OSPEEDER_OSPEEDR8_Msk        
#define GPIO_OSPEEDER_OSPEEDR8_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR8_Pos) /*!< 0x00010000 */
#define GPIO_OSPEEDER_OSPEEDR8_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR8_Pos) /*!< 0x00020000 */

#define GPIO_OSPEEDER_OSPEEDR9_Pos           (18U)                             
#define GPIO_OSPEEDER_OSPEEDR9_Msk           (0x3UL << GPIO_OSPEEDER_OSPEEDR9_Pos) /*!< 0x000C0000 */
#define GPIO_OSPEEDER_OSPEEDR9               GPIO_OSPEEDER_OSPEEDR9_Msk        
#define GPIO_OSPEEDER_OSPEEDR9_0             (0x1UL << GPIO_OSPEEDER_OSPEEDR9_Pos) /*!< 0x00040000 */
#define GPIO_OSPEEDER_OSPEEDR9_1             (0x2UL << GPIO_OSPEEDER_OSPEEDR9_Pos) /*!< 0x00080000 */

#define GPIO_OSPEEDER_OSPEEDR10_Pos          (20U)                             
#define GPIO_OSPEEDER_OSPEEDR10_Msk          (0x3UL << GPIO_OSPEEDER_OSPEEDR10_Pos) /*!< 0x00300000 */
#define GPIO_OSPEEDER_OSPEEDR10              GPIO_OSPEEDER_OSPEEDR10_Msk       
#define GPIO_OSPEEDER_OSPEEDR10_0            (0x1UL << GPIO_OSPEEDER_OSPEEDR10_Pos) /*!< 0x00100000 */
#define GPIO_OSPEEDER_OSPEEDR10_1            (0x2UL << GPIO_OSPEEDER_OSPEEDR10_Pos) /*!< 0x00200000 */

#define GPIO_OSPEEDER_OSPEEDR11_Pos          (22U)                             
#define GPIO_OSPEEDER_OSPEEDR11_Msk          (0x3UL << GPIO_OSPEEDER_OSPEEDR11_Pos) /*!< 0x00C00000 */
#define GPIO_OSPEEDER_OSPEEDR11              GPIO_OSPEEDER_OSPEEDR11_Msk       
#define GPIO_OSPEEDER_OSPEEDR11_0            (0x1UL << GPIO_OSPEEDER_OSPEEDR11_Pos) /*!< 0x00400000 */
#define GPIO_OSPEEDER_OSPEEDR11_1            (0x2UL << GPIO_OSPEEDER_OSPEEDR11_Pos) /*!< 0x00800000 */

#define GPIO_OSPEEDER_OSPEEDR12_Pos          (24U)                             
#define GPIO_OSPEEDER_OSPEEDR12_Msk          (0x3UL << GPIO_OSPEEDER_OSPEEDR12_Pos) /*!< 0x03000000 */
#define GPIO_OSPEEDER_OSPEEDR12              GPIO_OSPEEDER_OSPEEDR12_Msk       
#define GPIO_OSPEEDER_OSPEEDR12_0            (0x1UL << GPIO_OSPEEDER_OSPEEDR12_Pos) /*!< 0x01000000 */
#define GPIO_OSPEEDER_OSPEEDR12_1            (0x2UL << GPIO_OSPEEDER_OSPEEDR12_Pos) /*!< 0x02000000 */

#define GPIO_OSPEEDER_OSPEEDR13_Pos          (26U)                             
#define GPIO_OSPEEDER_OSPEEDR13_Msk          (0x3UL << GPIO_OSPEEDER_OSPEEDR13_Pos) /*!< 0x0C000000 */
#define GPIO_OSPEEDER_OSPEEDR13              GPIO_OSPEEDER_OSPEEDR13_Msk       
#define GPIO_OSPEEDER_OSPEEDR13_0            (0x1UL << GPIO_OSPEEDER_OSPEEDR13_Pos) /*!< 0x04000000 */
#define GPIO_OSPEEDER_OSPEEDR13_1            (0x2UL << GPIO_OSPEEDER_OSPEEDR13_Pos) /*!< 0x08000000 */

#define GPIO_OSPEEDER_OSPEEDR14_Pos          (28U)                             
#define GPIO_OSPEEDER_OSPEEDR14_Msk          (0x3UL << GPIO_OSPEEDER_OSPEEDR14_Pos) /*!< 0x30000000 */
#define GPIO_OSPEEDER_OSPEEDR14              GPIO_OSPEEDER_OSPEEDR14_Msk       
#define GPIO_OSPEEDER_OSPEEDR14_0            (0x1UL << GPIO_OSPEEDER_OSPEEDR14_Pos) /*!< 0x10000000 */
#define GPIO_OSPEEDER_OSPEEDR14_1            (0x2UL << GPIO_OSPEEDER_OSPEEDR14_Pos) /*!< 0x20000000 */

#define GPIO_OSPEEDER_OSPEEDR15_Pos          (30U)                             
#define GPIO_OSPEEDER_OSPEEDR15_Msk          (0x3UL << GPIO_OSPEEDER_OSPEEDR15_Pos) /*!< 0xC0000000 */
#define GPIO_OSPEEDER_OSPEEDR15              GPIO_OSPEEDER_OSPEEDR15_Msk       
#define GPIO_OSPEEDER_OSPEEDR15_0            (0x1UL << GPIO_OSPEEDER_OSPEEDR15_Pos) /*!< 0x40000000 */
#define GPIO_OSPEEDER_OSPEEDR15_1            (0x2UL << GPIO_OSPEEDER_OSPEEDR15_Pos) /*!< 0x80000000 */

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPDR0_Pos                (0U)                              
#define GPIO_PUPDR_PUPDR0_Msk                (0x3UL << GPIO_PUPDR_PUPDR0_Pos)   /*!< 0x00000003 */
#define GPIO_PUPDR_PUPDR0                    GPIO_PUPDR_PUPDR0_Msk             
#define GPIO_PUPDR_PUPDR0_0                  (0x1UL << GPIO_PUPDR_PUPDR0_Pos)   /*!< 0x00000001 */
#define GPIO_PUPDR_PUPDR0_1                  (0x2UL << GPIO_PUPDR_PUPDR0_Pos)   /*!< 0x00000002 */

#define GPIO_PUPDR_PUPDR1_Pos                (2U)                              
#define GPIO_PUPDR_PUPDR1_Msk                (0x3UL << GPIO_PUPDR_PUPDR1_Pos)   /*!< 0x0000000C */
#define GPIO_PUPDR_PUPDR1                    GPIO_PUPDR_PUPDR1_Msk             
#define GPIO_PUPDR_PUPDR1_0                  (0x1UL << GPIO_PUPDR_PUPDR1_Pos)   /*!< 0x00000004 */
#define GPIO_PUPDR_PUPDR1_1                  (0x2UL << GPIO_PUPDR_PUPDR1_Pos)   /*!< 0x00000008 */

#define GPIO_PUPDR_PUPDR2_Pos                (4U)                              
#define GPIO_PUPDR_PUPDR2_Msk                (0x3UL << GPIO_PUPDR_PUPDR2_Pos)   /*!< 0x00000030 */
#define GPIO_PUPDR_PUPDR2                    GPIO_PUPDR_PUPDR2_Msk             
#define GPIO_PUPDR_PUPDR2_0                  (0x1UL << GPIO_PUPDR_PUPDR2_Pos)   /*!< 0x00000010 */
#define GPIO_PUPDR_PUPDR2_1                  (0x2UL << GPIO_PUPDR_PUPDR2_Pos)   /*!< 0x00000020 */

#define GPIO_PUPDR_PUPDR3_Pos                (6U)                              
#define GPIO_PUPDR_PUPDR3_Msk                (0x3UL << GPIO_PUPDR_PUPDR3_Pos)   /*!< 0x000000C0 */
#define GPIO_PUPDR_PUPDR3                    GPIO_PUPDR_PUPDR3_Msk             
#define GPIO_PUPDR_PUPDR3_0                  (0x1UL << GPIO_PUPDR_PUPDR3_Pos)   /*!< 0x00000040 */
#define GPIO_PUPDR_PUPDR3_1                  (0x2UL << GPIO_PUPDR_PUPDR3_Pos)   /*!< 0x00000080 */

#define GPIO_PUPDR_PUPDR4_Pos                (8U)                              
#define GPIO_PUPDR_PUPDR4_Msk                (0x3UL << GPIO_PUPDR_PUPDR4_Pos)   /*!< 0x00000300 */
#define GPIO_PUPDR_PUPDR4                    GPIO_PUPDR_PUPDR4_Msk             
#define GPIO_PUPDR_PUPDR4_0                  (0x1UL << GPIO_PUPDR_PUPDR4_Pos)   /*!< 0x00000100 */
#define GPIO_PUPDR_PUPDR4_1                  (0x2UL << GPIO_PUPDR_PUPDR4_Pos)   /*!< 0x00000200 */

#define GPIO_PUPDR_PUPDR5_Pos                (10U)                             
#define GPIO_PUPDR_PUPDR5_Msk                (0x3UL << GPIO_PUPDR_PUPDR5_Pos)   /*!< 0x00000C00 */
#define GPIO_PUPDR_PUPDR5                    GPIO_PUPDR_PUPDR5_Msk             
#define GPIO_PUPDR_PUPDR5_0                  (0x1UL << GPIO_PUPDR_PUPDR5_Pos)   /*!< 0x00000400 */
#define GPIO_PUPDR_PUPDR5_1                  (0x2UL << GPIO_PUPDR_PUPDR5_Pos)   /*!< 0x00000800 */

#define GPIO_PUPDR_PUPDR6_Pos                (12U)                             
#define GPIO_PUPDR_PUPDR6_Msk                (0x3UL << GPIO_PUPDR_PUPDR6_Pos)   /*!< 0x00003000 */
#define GPIO_PUPDR_PUPDR6                    GPIO_PUPDR_PUPDR6_Msk             
#define GPIO_PUPDR_PUPDR6_0                  (0x1UL << GPIO_PUPDR_PUPDR6_Pos)   /*!< 0x00001000 */
#define GPIO_PUPDR_PUPDR6_1                  (0x2UL << GPIO_PUPDR_PUPDR6_Pos)   /*!< 0x00002000 */

#define GPIO_PUPDR_PUPDR7_Pos                (14U)                             
#define GPIO_PUPDR_PUPDR7_Msk                (0x3UL << GPIO_PUPDR_PUPDR7_Pos)   /*!< 0x0000C000 */
#define GPIO_PUPDR_PUPDR7                    GPIO_PUPDR_PUPDR7_Msk             
#define GPIO_PUPDR_PUPDR7_0                  (0x1UL << GPIO_PUPDR_PUPDR7_Pos)   /*!< 0x00004000 */
#define GPIO_PUPDR_PUPDR7_1                  (0x2UL << GPIO_PUPDR_PUPDR7_Pos)   /*!< 0x00008000 */

#define GPIO_PUPDR_PUPDR8_Pos                (16U)                             
#define GPIO_PUPDR_PUPDR8_Msk                (0x3UL << GPIO_PUPDR_PUPDR8_Pos)   /*!< 0x00030000 */
#define GPIO_PUPDR_PUPDR8                    GPIO_PUPDR_PUPDR8_Msk             
#define GPIO_PUPDR_PUPDR8_0                  (0x1UL << GPIO_PUPDR_PUPDR8_Pos)   /*!< 0x00010000 */
#define GPIO_PUPDR_PUPDR8_1                  (0x2UL << GPIO_PUPDR_PUPDR8_Pos)   /*!< 0x00020000 */

#define GPIO_PUPDR_PUPDR9_Pos                (18U)                             
#define GPIO_PUPDR_PUPDR9_Msk                (0x3UL << GPIO_PUPDR_PUPDR9_Pos)   /*!< 0x000C0000 */
#define GPIO_PUPDR_PUPDR9                    GPIO_PUPDR_PUPDR9_Msk             
#define GPIO_PUPDR_PUPDR9_0                  (0x1UL << GPIO_PUPDR_PUPDR9_Pos)   /*!< 0x00040000 */
#define GPIO_PUPDR_PUPDR9_1                  (0x2UL << GPIO_PUPDR_PUPDR9_Pos)   /*!< 0x00080000 */

#define GPIO_PUPDR_PUPDR10_Pos               (20U)                             
#define GPIO_PUPDR_PUPDR10_Msk               (0x3UL << GPIO_PUPDR_PUPDR10_Pos)  /*!< 0x00300000 */
#define GPIO_PUPDR_PUPDR10                   GPIO_PUPDR_PUPDR10_Msk            
#define GPIO_PUPDR_PUPDR10_0                 (0x1UL << GPIO_PUPDR_PUPDR10_Pos)  /*!< 0x00100000 */
#define GPIO_PUPDR_PUPDR10_1                 (0x2UL << GPIO_PUPDR_PUPDR10_Pos)  /*!< 0x00200000 */

#define GPIO_PUPDR_PUPDR11_Pos               (22U)                             
#define GPIO_PUPDR_PUPDR11_Msk               (0x3UL << GPIO_PUPDR_PUPDR11_Pos)  /*!< 0x00C00000 */
#define GPIO_PUPDR_PUPDR11                   GPIO_PUPDR_PUPDR11_Msk            
#define GPIO_PUPDR_PUPDR11_0                 (0x1UL << GPIO_PUPDR_PUPDR11_Pos)  /*!< 0x00400000 */
#define GPIO_PUPDR_PUPDR11_1                 (0x2UL << GPIO_PUPDR_PUPDR11_Pos)  /*!< 0x00800000 */

#define GPIO_PUPDR_PUPDR12_Pos               (24U)                             
#define GPIO_PUPDR_PUPDR12_Msk               (0x3UL << GPIO_PUPDR_PUPDR12_Pos)  /*!< 0x03000000 */
#define GPIO_PUPDR_PUPDR12                   GPIO_PUPDR_PUPDR12_Msk            
#define GPIO_PUPDR_PUPDR12_0                 (0x1UL << GPIO_PUPDR_PUPDR12_Pos)  /*!< 0x01000000 */
#define GPIO_PUPDR_PUPDR12_1                 (0x2UL << GPIO_PUPDR_PUPDR12_Pos)  /*!< 0x02000000 */

#define GPIO_PUPDR_PUPDR13_Pos               (26U)                             
#define GPIO_PUPDR_PUPDR13_Msk               (0x3UL << GPIO_PUPDR_PUPDR13_Pos)  /*!< 0x0C000000 */
#define GPIO_PUPDR_PUPDR13                   GPIO_PUPDR_PUPDR13_Msk            
#define GPIO_PUPDR_PUPDR13_0                 (0x1UL << GPIO_PUPDR_PUPDR13_Pos)  /*!< 0x04000000 */
#define GPIO_PUPDR_PUPDR13_1                 (0x2UL << GPIO_PUPDR_PUPDR13_Pos)  /*!< 0x08000000 */

#define GPIO_PUPDR_PUPDR14_Pos               (28U)                             
#define GPIO_PUPDR_PUPDR14_Msk               (0x3UL << GPIO_PUPDR_PUPDR14_Pos)  /*!< 0x30000000 */
#define GPIO_PUPDR_PUPDR14                   GPIO_PUPDR_PUPDR14_Msk            
#define GPIO_PUPDR_PUPDR14_0                 (0x1UL << GPIO_PUPDR_PUPDR14_Pos)  /*!< 0x10000000 */
#define GPIO_PUPDR_PUPDR14_1                 (0x2UL << GPIO_PUPDR_PUPDR14_Pos)  /*!< 0x20000000 */
#define GPIO_PUPDR_PUPDR15_Pos               (30U)                             
#define GPIO_PUPDR_PUPDR15_Msk               (0x3UL << GPIO_PUPDR_PUPDR15_Pos)  /*!< 0xC0000000 */
#define GPIO_PUPDR_PUPDR15                   GPIO_PUPDR_PUPDR15_Msk            
#define GPIO_PUPDR_PUPDR15_0                 (0x1UL << GPIO_PUPDR_PUPDR15_Pos)  /*!< 0x40000000 */
#define GPIO_PUPDR_PUPDR15_1                 (0x2UL << GPIO_PUPDR_PUPDR15_Pos)  /*!< 0x80000000 */

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_IDR_0                       (0x00000001U)                     
#define GPIO_IDR_IDR_1                       (0x00000002U)                     
#define GPIO_IDR_IDR_2                       (0x00000004U)                     
#define GPIO_IDR_IDR_3                       (0x00000008U)                     
#define GPIO_IDR_IDR_4                       (0x00000010U)                     
#define GPIO_IDR_IDR_5                       (0x00000020U)                     
#define GPIO_IDR_IDR_6                       (0x00000040U)                     
#define GPIO_IDR_IDR_7                       (0x00000080U)                     
#define GPIO_IDR_IDR_8                       (0x00000100U)                     
#define GPIO_IDR_IDR_9                       (0x00000200U)                     
#define GPIO_IDR_IDR_10                      (0x00000400U)                     
#define GPIO_IDR_IDR_11                      (0x00000800U)                     
#define GPIO_IDR_IDR_12                      (0x00001000U)                     
#define GPIO_IDR_IDR_13                      (0x00002000U)                     
#define GPIO_IDR_IDR_14                      (0x00004000U)                     
#define GPIO_IDR_IDR_15                      (0x00008000U)                     

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_ODR_0                       (0x00000001U)                     
#define GPIO_ODR_ODR_1                       (0x00000002U)                     
#define GPIO_ODR_ODR_2                       (0x00000004U)                     
#define GPIO_ODR_ODR_3                       (0x00000008U)                     
#define GPIO_ODR_ODR_4                       (0x00000010U)                     
#define GPIO_ODR_ODR_5                       (0x00000020U)                     
#define GPIO_ODR_ODR_6                       (0x00000040U)                     
#define GPIO_ODR_ODR_7                       (0x00000080U)                     
#define GPIO_ODR_ODR_8                       (0x00000100U)                     
#define GPIO_ODR_ODR_9                       (0x00000200U)                     
#define GPIO_ODR_ODR_10                      (0x00000400U)                     
#define GPIO_ODR_ODR_11                      (0x00000800U)                     
#define GPIO_ODR_ODR_12                      (0x00001000U)                     
#define GPIO_ODR_ODR_13                      (0x00002000U)                     
#define GPIO_ODR_ODR_14                      (0x00004000U)                     
#define GPIO_ODR_ODR_15                      (0x00008000U)                     

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS_0                       (0x00000001U)                     
#define GPIO_BSRR_BS_1                       (0x00000002U)                     
#define GPIO_BSRR_BS_2                       (0x00000004U)                     
#define GPIO_BSRR_BS_3                       (0x00000008U)                     
#define GPIO_BSRR_BS_4                       (0x00000010U)                     
#define GPIO_BSRR_BS_5                       (0x00000020U)                     
#define GPIO_BSRR_BS_6                       (0x00000040U)                     
#define GPIO_BSRR_BS_7                       (0x00000080U)                     
#define GPIO_BSRR_BS_8                       (0x00000100U)                     
#define GPIO_BSRR_BS_9                       (0x00000200U)                     
#define GPIO_BSRR_BS_10                      (0x00000400U)                     
#define GPIO_BSRR_BS_11                      (0x00000800U)                     
#define GPIO_BSRR_BS_12                      (0x00001000U)                     
#define GPIO_BSRR_BS_13                      (0x00002000U)                     
#define GPIO_BSRR_BS_14                      (0x00004000U)                     
#define GPIO_BSRR_BS_15                      (0x00008000U)                     
#define GPIO_BSRR_BR_0                       (0x00010000U)                     
#define GPIO_BSRR_BR_1                       (0x00020000U)                     
#define GPIO_BSRR_BR_2                       (0x00040000U)                     
#define GPIO_BSRR_BR_3                       (0x00080000U)                     
#define GPIO_BSRR_BR_4                       (0x00100000U)                     
#define GPIO_BSRR_BR_5                       (0x00200000U)                     
#define GPIO_BSRR_BR_6                       (0x00400000U)                     
#define GPIO_BSRR_BR_7                       (0x00800000U)                     
#define GPIO_BSRR_BR_8                       (0x01000000U)                     
#define GPIO_BSRR_BR_9                       (0x02000000U)                     
#define GPIO_BSRR_BR_10                      (0x04000000U)                     
#define GPIO_BSRR_BR_11                      (0x08000000U)                     
#define GPIO_BSRR_BR_12                      (0x10000000U)                     
#define GPIO_BSRR_BR_13                      (0x20000000U)                     
#define GPIO_BSRR_BR_14                      (0x40000000U)                     
#define GPIO_BSRR_BR_15                      (0x80000000U)                     

/****************** Bit definition for GPIO_LCKR register  ********************/
#define GPIO_LCKR_LCK0_Pos                   (0U)                              
#define GPIO_LCKR_LCK0_Msk                   (0x1UL << GPIO_LCKR_LCK0_Pos)      /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                       GPIO_LCKR_LCK0_Msk                
#define GPIO_LCKR_LCK1_Pos                   (1U)                              
#define GPIO_LCKR_LCK1_Msk                   (0x1UL << GPIO_LCKR_LCK1_Pos)      /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                       GPIO_LCKR_LCK1_Msk                
#define GPIO_LCKR_LCK2_Pos                   (2U)                              
#define GPIO_LCKR_LCK2_Msk                   (0x1UL << GPIO_LCKR_LCK2_Pos)      /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                       GPIO_LCKR_LCK2_Msk                
#define GPIO_LCKR_LCK3_Pos                   (3U)                              
#define GPIO_LCKR_LCK3_Msk                   (0x1UL << GPIO_LCKR_LCK3_Pos)      /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                       GPIO_LCKR_LCK3_Msk                
#define GPIO_LCKR_LCK4_Pos                   (4U)                              
#define GPIO_LCKR_LCK4_Msk                   (0x1UL << GPIO_LCKR_LCK4_Pos)      /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                       GPIO_LCKR_LCK4_Msk                
#define GPIO_LCKR_LCK5_Pos                   (5U)                              
#define GPIO_LCKR_LCK5_Msk                   (0x1UL << GPIO_LCKR_LCK5_Pos)      /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                       GPIO_LCKR_LCK5_Msk                
#define GPIO_LCKR_LCK6_Pos                   (6U)                              
#define GPIO_LCKR_LCK6_Msk                   (0x1UL << GPIO_LCKR_LCK6_Pos)      /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                       GPIO_LCKR_LCK6_Msk                
#define GPIO_LCKR_LCK7_Pos                   (7U)                              
#define GPIO_LCKR_LCK7_Msk                   (0x1UL << GPIO_LCKR_LCK7_Pos)      /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                       GPIO_LCKR_LCK7_Msk                
#define GPIO_LCKR_LCK8_Pos                   (8U)                              
#define GPIO_LCKR_LCK8_Msk                   (0x1UL << GPIO_LCKR_LCK8_Pos)      /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                       GPIO_LCKR_LCK8_Msk                
#define GPIO_LCKR_LCK9_Pos                   (9U)                              
#define GPIO_LCKR_LCK9_Msk                   (0x1UL << GPIO_LCKR_LCK9_Pos)      /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                       GPIO_LCKR_LCK9_Msk                
#define GPIO_LCKR_LCK10_Pos                  (10U)                             
#define GPIO_LCKR_LCK10_Msk                  (0x1UL << GPIO_LCKR_LCK10_Pos)     /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                      GPIO_LCKR_LCK10_Msk               
#define GPIO_LCKR_LCK11_Pos                  (11U)                             
#define GPIO_LCKR_LCK11_Msk                  (0x1UL << GPIO_LCKR_LCK11_Pos)     /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                      GPIO_LCKR_LCK11_Msk               
#define GPIO_LCKR_LCK12_Pos                  (12U)                             
#define GPIO_LCKR_LCK12_Msk                  (0x1UL << GPIO_LCKR_LCK12_Pos)     /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                      GPIO_LCKR_LCK12_Msk               
#define GPIO_LCKR_LCK13_Pos                  (13U)                             
#define GPIO_LCKR_LCK13_Msk                  (0x1UL << GPIO_LCKR_LCK13_Pos)     /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                      GPIO_LCKR_LCK13_Msk               
#define GPIO_LCKR_LCK14_Pos                  (14U)                             
#define GPIO_LCKR_LCK14_Msk                  (0x1UL << GPIO_LCKR_LCK14_Pos)     /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                      GPIO_LCKR_LCK14_Msk               
#define GPIO_LCKR_LCK15_Pos                  (15U)                             
#define GPIO_LCKR_LCK15_Msk                  (0x1UL << GPIO_LCKR_LCK15_Pos)     /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                      GPIO_LCKR_LCK15_Msk               
#define GPIO_LCKR_LCKK_Pos                   (16U)                             
#define GPIO_LCKR_LCKK_Msk                   (0x1UL << GPIO_LCKR_LCKK_Pos)      /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                       GPIO_LCKR_LCKK_Msk                

/****************** Bit definition for GPIO_AFRL register  ********************/
#define GPIO_AFRL_AFSEL0_Pos                  (0U)                              
#define GPIO_AFRL_AFSEL0_Msk                  (0xFUL << GPIO_AFRL_AFSEL0_Pos)     /*!< 0x0000000F */
#define GPIO_AFRL_AFSEL0                      GPIO_AFRL_AFSEL0_Msk               
#define GPIO_AFRL_AFSEL1_Pos                  (4U)                              
#define GPIO_AFRL_AFSEL1_Msk                  (0xFUL << GPIO_AFRL_AFSEL1_Pos)     /*!< 0x000000F0 */
#define GPIO_AFRL_AFSEL1                      GPIO_AFRL_AFSEL1_Msk               
#define GPIO_AFRL_AFSEL2_Pos                  (8U)                              
#define GPIO_AFRL_AFSEL2_Msk                  (0xFUL << GPIO_AFRL_AFSEL2_Pos)     /*!< 0x00000F00 */
#define GPIO_AFRL_AFSEL2                      GPIO_AFRL_AFSEL2_Msk               
#define GPIO_AFRL_AFSEL3_Pos                  (12U)                             
#define GPIO_AFRL_AFSEL3_Msk                  (0xFUL << GPIO_AFRL_AFSEL3_Pos)     /*!< 0x0000F000 */
#define GPIO_AFRL_AFSEL3                      GPIO_AFRL_AFSEL3_Msk               
#define GPIO_AFRL_AFSEL4_Pos                  (16U)                             
#define GPIO_AFRL_AFSEL4_Msk                  (0xFUL << GPIO_AFRL_AFSEL4_Pos)     /*!< 0x000F0000 */
#define GPIO_AFRL_AFSEL4                      GPIO_AFRL_AFSEL4_Msk               
#define GPIO_AFRL_AFSEL5_Pos                  (20U)                             
#define GPIO_AFRL_AFSEL5_Msk                  (0xFUL << GPIO_AFRL_AFSEL5_Pos)     /*!< 0x00F00000 */
#define GPIO_AFRL_AFSEL5                      GPIO_AFRL_AFSEL5_Msk               
#define GPIO_AFRL_AFSEL6_Pos                  (24U)                             
#define GPIO_AFRL_AFSEL6_Msk                  (0xFUL << GPIO_AFRL_AFSEL6_Pos)     /*!< 0x0F000000 */
#define GPIO_AFRL_AFSEL6                      GPIO_AFRL_AFSEL6_Msk               
#define GPIO_AFRL_AFSEL7_Pos                  (28U)                             
#define GPIO_AFRL_AFSEL7_Msk                  (0xFUL << GPIO_AFRL_AFSEL7_Pos)     /*!< 0xF0000000 */
#define GPIO_AFRL_AFSEL7                      GPIO_AFRL_AFSEL7_Msk               

/****************** Bit definition for GPIO_AFRH register  ********************/
#define GPIO_AFRH_AFSEL8_Pos                  (0U)                              
#define GPIO_AFRH_AFSEL8_Msk                  (0xFUL << GPIO_AFRH_AFSEL8_Pos)     /*!< 0x0000000F */
#define GPIO_AFRH_AFSEL8                      GPIO_AFRH_AFSEL8_Msk               
#define GPIO_AFRH_AFSEL9_Pos                  (4U)                              
#define GPIO_AFRH_AFSEL9_Msk                  (0xFUL << GPIO_AFRH_AFSEL9_Pos)     /*!< 0x000000F0 */
#define GPIO_AFRH_AFSEL9                      GPIO_AFRH_AFSEL9_Msk               
#define GPIO_AFRH_AFSEL10_Pos                  (8U)                              
#define GPIO_AFRH_AFSEL10_Msk                  (0xFUL << GPIO_AFRH_AFSEL10_Pos)     /*!< 0x00000F00 */
#define GPIO_AFRH_AFSEL10                      GPIO_AFRH_AFSEL10_Msk               
#define GPIO_AFRH_AFSEL11_Pos                  (12U)                             
#define GPIO_AFRH_AFSEL11_Msk                  (0xFUL << GPIO_AFRH_AFSEL11_Pos)     /*!< 0x0000F000 */
#define GPIO_AFRH_AFSEL11                      GPIO_AFRH_AFSEL11_Msk               
#define GPIO_AFRH_AFSEL12_Pos                  (16U)                             
#define GPIO_AFRH_AFSEL12_Msk                  (0xFUL << GPIO_AFRH_AFSEL12_Pos)     /*!< 0x000F0000 */
#define GPIO_AFRH_AFSEL12                      GPIO_AFRH_AFSEL12_Msk               
#define GPIO_AFRH_AFSEL13_Pos                  (20U)                             
#define GPIO_AFRH_AFSEL13_Msk                  (0xFUL << GPIO_AFRH_AFSEL13_Pos)     /*!< 0x00F00000 */
#define GPIO_AFRH_AFSEL13                      GPIO_AFRH_AFSEL13_Msk               
#define GPIO_AFRH_AFSEL14_Pos                  (24U)                             
#define GPIO_AFRH_AFSEL14_Msk                  (0xFUL << GPIO_AFRH_AFSEL14_Pos)     /*!< 0x0F000000 */
#define GPIO_AFRH_AFSEL14                      GPIO_AFRH_AFSEL14_Msk               
#define GPIO_AFRH_AFSEL15_Pos                  (28U)                             
#define GPIO_AFRH_AFSEL15_Msk                  (0xFUL << GPIO_AFRH_AFSEL15_Pos)     /*!< 0xF0000000 */
#define GPIO_AFRH_AFSEL15                      GPIO_AFRH_AFSEL15_Msk               

/****************** Bit definition for GPIO_BRR register  *********************/
#define GPIO_BRR_BR_0                        (0x00000001U)                     
#define GPIO_BRR_BR_1                        (0x00000002U)                     
#define GPIO_BRR_BR_2                        (0x00000004U)                     
#define GPIO_BRR_BR_3                        (0x00000008U)                     
#define GPIO_BRR_BR_4                        (0x00000010U)                     
#define GPIO_BRR_BR_5                        (0x00000020U)                     
#define GPIO_BRR_BR_6                        (0x00000040U)                     
#define GPIO_BRR_BR_7                        (0x00000080U)                     
#define GPIO_BRR_BR_8                        (0x00000100U)                     
#define GPIO_BRR_BR_9                        (0x00000200U)                     
#define GPIO_BRR_BR_10                       (0x00000400U)                     
#define GPIO_BRR_BR_11                       (0x00000800U)                     
#define GPIO_BRR_BR_12                       (0x00001000U)                     
#define GPIO_BRR_BR_13                       (0x00002000U)                     
#define GPIO_BRR_BR_14                       (0x00004000U)                     
#define GPIO_BRR_BR_15                       (0x00008000U)                     

/******************************************************************************/
/*                                                                            */
/*                   Inter-integrated Circuit Interface (I2C)                 */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)                               
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)                               
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)                               
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)                               
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)                               
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)                               
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)                               
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)                               
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)                               
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)                              
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)                              
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)                              
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)                              
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)                              
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */

/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)                               
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_FREQ_0                      (0x01UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000001 */
#define I2C_CR2_FREQ_1                      (0x02UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000002 */
#define I2C_CR2_FREQ_2                      (0x04UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000004 */
#define I2C_CR2_FREQ_3                      (0x08UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000008 */
#define I2C_CR2_FREQ_4                      (0x10UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000010 */
#define I2C_CR2_FREQ_5                      (0x20UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000020 */

#define I2C_CR2_ITERREN_Pos                 (8U)                               
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)                               
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)                              
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)                              
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)                              
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */

/*******************  Bit definition for I2C_OAR1 register  *******************/
#define I2C_OAR1_ADD1_7                     (0x000000FEU)                      /*!< Interface Address */
#define I2C_OAR1_ADD8_9                     (0x00000300U)                      /*!< Interface Address */

#define I2C_OAR1_ADD0_Pos                   (0U)                               
#define I2C_OAR1_ADD0_Msk                   (0x1UL << I2C_OAR1_ADD0_Pos)        /*!< 0x00000001 */
#define I2C_OAR1_ADD0                       I2C_OAR1_ADD0_Msk                  /*!< Bit 0 */
#define I2C_OAR1_ADD1_Pos                   (1U)                               
#define I2C_OAR1_ADD1_Msk                   (0x1UL << I2C_OAR1_ADD1_Pos)        /*!< 0x00000002 */
#define I2C_OAR1_ADD1                       I2C_OAR1_ADD1_Msk                  /*!< Bit 1 */
#define I2C_OAR1_ADD2_Pos                   (2U)                               
#define I2C_OAR1_ADD2_Msk                   (0x1UL << I2C_OAR1_ADD2_Pos)        /*!< 0x00000004 */
#define I2C_OAR1_ADD2                       I2C_OAR1_ADD2_Msk                  /*!< Bit 2 */
#define I2C_OAR1_ADD3_Pos                   (3U)                               
#define I2C_OAR1_ADD3_Msk                   (0x1UL << I2C_OAR1_ADD3_Pos)        /*!< 0x00000008 */
#define I2C_OAR1_ADD3                       I2C_OAR1_ADD3_Msk                  /*!< Bit 3 */
#define I2C_OAR1_ADD4_Pos                   (4U)                               
#define I2C_OAR1_ADD4_Msk                   (0x1UL << I2C_OAR1_ADD4_Pos)        /*!< 0x00000010 */
#define I2C_OAR1_ADD4                       I2C_OAR1_ADD4_Msk                  /*!< Bit 4 */
#define I2C_OAR1_ADD5_Pos                   (5U)                               
#define I2C_OAR1_ADD5_Msk                   (0x1UL << I2C_OAR1_ADD5_Pos)        /*!< 0x00000020 */
#define I2C_OAR1_ADD5                       I2C_OAR1_ADD5_Msk                  /*!< Bit 5 */
#define I2C_OAR1_ADD6_Pos                   (6U)                               
#define I2C_OAR1_ADD6_Msk                   (0x1UL << I2C_OAR1_ADD6_Pos)        /*!< 0x00000040 */
#define I2C_OAR1_ADD6                       I2C_OAR1_ADD6_Msk                  /*!< Bit 6 */
#define I2C_OAR1_ADD7_Pos                   (7U)                               
#define I2C_OAR1_ADD7_Msk                   (0x1UL << I2C_OAR1_ADD7_Pos)        /*!< 0x00000080 */
#define I2C_OAR1_ADD7                       I2C_OAR1_ADD7_Msk                  /*!< Bit 7 */
#define I2C_OAR1_ADD8_Pos                   (8U)                               
#define I2C_OAR1_ADD8_Msk                   (0x1UL << I2C_OAR1_ADD8_Pos)        /*!< 0x00000100 */
#define I2C_OAR1_ADD8                       I2C_OAR1_ADD8_Msk                  /*!< Bit 8 */
#define I2C_OAR1_ADD9_Pos                   (9U)                               
#define I2C_OAR1_ADD9_Msk                   (0x1UL << I2C_OAR1_ADD9_Pos)        /*!< 0x00000200 */
#define I2C_OAR1_ADD9                       I2C_OAR1_ADD9_Msk                  /*!< Bit 9 */

#define I2C_OAR1_ADDMODE_Pos                (15U)                              
#define I2C_OAR1_ADDMODE_Msk                (0x1UL << I2C_OAR1_ADDMODE_Pos)     /*!< 0x00008000 */
#define I2C_OAR1_ADDMODE                    I2C_OAR1_ADDMODE_Msk               /*!< Addressing Mode (Slave mode) */

/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)                               
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)                               
#define I2C_OAR2_ADD2_Msk                   (0x7FUL << I2C_OAR2_ADD2_Pos)       /*!< 0x000000FE */
#define I2C_OAR2_ADD2                       I2C_OAR2_ADD2_Msk                  /*!< Interface address */

/********************  Bit definition for I2C_DR register  ********************/
#define I2C_DR_DR_Pos                       (0U)                               
#define I2C_DR_DR_Msk                       (0xFFUL << I2C_DR_DR_Pos)           /*!< 0x000000FF */
#define I2C_DR_DR                           I2C_DR_DR_Msk                      /*!< 8-bit Data Register */

/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)                               
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)                               
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)                               
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)                               
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)                               
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)                               
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)                               
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)                               
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)                               
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)                              
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)                              
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)                              
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)                              
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)                              
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)                               
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)                               
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)                               
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)                               
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)                               
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)                               
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)                               
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)                               
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */

/*******************  Bit definition for I2C_CCR register  ********************/
#define I2C_CCR_CCR_Pos                     (0U)                               
#define I2C_CCR_CCR_Msk                     (0xFFFUL << I2C_CCR_CCR_Pos)        /*!< 0x00000FFF */
#define I2C_CCR_CCR                         I2C_CCR_CCR_Msk                    /*!< Clock Control Register in Fast/Standard mode (Master mode) */
#define I2C_CCR_DUTY_Pos                    (14U)                              
#define I2C_CCR_DUTY_Msk                    (0x1UL << I2C_CCR_DUTY_Pos)         /*!< 0x00004000 */
#define I2C_CCR_DUTY                        I2C_CCR_DUTY_Msk                   /*!< Fast Mode Duty Cycle */
#define I2C_CCR_FS_Pos                      (15U)                              
#define I2C_CCR_FS_Msk                      (0x1UL << I2C_CCR_FS_Pos)           /*!< 0x00008000 */
#define I2C_CCR_FS                          I2C_CCR_FS_Msk                     /*!< I2C Master Mode Selection */

/******************  Bit definition for I2C_TRISE register  *******************/
#define I2C_TRISE_TRISE_Pos                 (0U)                               
#define I2C_TRISE_TRISE_Msk                 (0x3FUL << I2C_TRISE_TRISE_Pos)     /*!< 0x0000003F */
#define I2C_TRISE_TRISE                     I2C_TRISE_TRISE_Msk                /*!< Maximum Rise Time in Fast/Standard mode (Master mode) */

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
/*                          LCD Controller (LCD)                              */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for LCD_CR register  *********************/
#define LCD_CR_LCDEN_Pos           (0U)                                        
#define LCD_CR_LCDEN_Msk           (0x1UL << LCD_CR_LCDEN_Pos)                  /*!< 0x00000001 */
#define LCD_CR_LCDEN               LCD_CR_LCDEN_Msk                            /*!< LCD Enable Bit */
#define LCD_CR_VSEL_Pos            (1U)                                        
#define LCD_CR_VSEL_Msk            (0x1UL << LCD_CR_VSEL_Pos)                   /*!< 0x00000002 */
#define LCD_CR_VSEL                LCD_CR_VSEL_Msk                             /*!< Voltage source selector Bit */

#define LCD_CR_DUTY_Pos            (2U)                                        
#define LCD_CR_DUTY_Msk            (0x7UL << LCD_CR_DUTY_Pos)                   /*!< 0x0000001C */
#define LCD_CR_DUTY                LCD_CR_DUTY_Msk                             /*!< DUTY[2:0] bits (Duty selector) */
#define LCD_CR_DUTY_0              (0x1UL << LCD_CR_DUTY_Pos)                   /*!< 0x00000004 */
#define LCD_CR_DUTY_1              (0x2UL << LCD_CR_DUTY_Pos)                   /*!< 0x00000008 */
#define LCD_CR_DUTY_2              (0x4UL << LCD_CR_DUTY_Pos)                   /*!< 0x00000010 */

#define LCD_CR_BIAS_Pos            (5U)                                        
#define LCD_CR_BIAS_Msk            (0x3UL << LCD_CR_BIAS_Pos)                   /*!< 0x00000060 */
#define LCD_CR_BIAS                LCD_CR_BIAS_Msk                             /*!< BIAS[1:0] bits (Bias selector) */
#define LCD_CR_BIAS_0              (0x1UL << LCD_CR_BIAS_Pos)                   /*!< 0x00000020 */
#define LCD_CR_BIAS_1              (0x2UL << LCD_CR_BIAS_Pos)                   /*!< 0x00000040 */

#define LCD_CR_MUX_SEG_Pos         (7U)                                        
#define LCD_CR_MUX_SEG_Msk         (0x1UL << LCD_CR_MUX_SEG_Pos)                /*!< 0x00000080 */
#define LCD_CR_MUX_SEG             LCD_CR_MUX_SEG_Msk                          /*!< Mux Segment Enable Bit */

/*******************  Bit definition for LCD_FCR register  ********************/
#define LCD_FCR_HD_Pos             (0U)                                        
#define LCD_FCR_HD_Msk             (0x1UL << LCD_FCR_HD_Pos)                    /*!< 0x00000001 */
#define LCD_FCR_HD                 LCD_FCR_HD_Msk                              /*!< High Drive Enable Bit */
#define LCD_FCR_SOFIE_Pos          (1U)                                        
#define LCD_FCR_SOFIE_Msk          (0x1UL << LCD_FCR_SOFIE_Pos)                 /*!< 0x00000002 */
#define LCD_FCR_SOFIE              LCD_FCR_SOFIE_Msk                           /*!< Start of Frame Interrupt Enable Bit */
#define LCD_FCR_UDDIE_Pos          (3U)                                        
#define LCD_FCR_UDDIE_Msk          (0x1UL << LCD_FCR_UDDIE_Pos)                 /*!< 0x00000008 */
#define LCD_FCR_UDDIE              LCD_FCR_UDDIE_Msk                           /*!< Update Display Done Interrupt Enable Bit */

#define LCD_FCR_PON_Pos            (4U)                                        
#define LCD_FCR_PON_Msk            (0x7UL << LCD_FCR_PON_Pos)                   /*!< 0x00000070 */
#define LCD_FCR_PON                LCD_FCR_PON_Msk                             /*!< PON[2:0] bits (Puls ON Duration) */
#define LCD_FCR_PON_0              (0x1UL << LCD_FCR_PON_Pos)                   /*!< 0x00000010 */
#define LCD_FCR_PON_1              (0x2UL << LCD_FCR_PON_Pos)                   /*!< 0x00000020 */
#define LCD_FCR_PON_2              (0x4UL << LCD_FCR_PON_Pos)                   /*!< 0x00000040 */

#define LCD_FCR_DEAD_Pos           (7U)                                        
#define LCD_FCR_DEAD_Msk           (0x7UL << LCD_FCR_DEAD_Pos)                  /*!< 0x00000380 */
#define LCD_FCR_DEAD               LCD_FCR_DEAD_Msk                            /*!< DEAD[2:0] bits (DEAD Time) */
#define LCD_FCR_DEAD_0             (0x1UL << LCD_FCR_DEAD_Pos)                  /*!< 0x00000080 */
#define LCD_FCR_DEAD_1             (0x2UL << LCD_FCR_DEAD_Pos)                  /*!< 0x00000100 */
#define LCD_FCR_DEAD_2             (0x4UL << LCD_FCR_DEAD_Pos)                  /*!< 0x00000200 */

#define LCD_FCR_CC_Pos             (10U)                                       
#define LCD_FCR_CC_Msk             (0x7UL << LCD_FCR_CC_Pos)                    /*!< 0x00001C00 */
#define LCD_FCR_CC                 LCD_FCR_CC_Msk                              /*!< CC[2:0] bits (Contrast Control) */
#define LCD_FCR_CC_0               (0x1UL << LCD_FCR_CC_Pos)                    /*!< 0x00000400 */
#define LCD_FCR_CC_1               (0x2UL << LCD_FCR_CC_Pos)                    /*!< 0x00000800 */
#define LCD_FCR_CC_2               (0x4UL << LCD_FCR_CC_Pos)                    /*!< 0x00001000 */

#define LCD_FCR_BLINKF_Pos         (13U)                                       
#define LCD_FCR_BLINKF_Msk         (0x7UL << LCD_FCR_BLINKF_Pos)                /*!< 0x0000E000 */
#define LCD_FCR_BLINKF             LCD_FCR_BLINKF_Msk                          /*!< BLINKF[2:0] bits (Blink Frequency) */
#define LCD_FCR_BLINKF_0           (0x1UL << LCD_FCR_BLINKF_Pos)                /*!< 0x00002000 */
#define LCD_FCR_BLINKF_1           (0x2UL << LCD_FCR_BLINKF_Pos)                /*!< 0x00004000 */
#define LCD_FCR_BLINKF_2           (0x4UL << LCD_FCR_BLINKF_Pos)                /*!< 0x00008000 */

#define LCD_FCR_BLINK_Pos          (16U)                                       
#define LCD_FCR_BLINK_Msk          (0x3UL << LCD_FCR_BLINK_Pos)                 /*!< 0x00030000 */
#define LCD_FCR_BLINK              LCD_FCR_BLINK_Msk                           /*!< BLINK[1:0] bits (Blink Enable) */
#define LCD_FCR_BLINK_0            (0x1UL << LCD_FCR_BLINK_Pos)                 /*!< 0x00010000 */
#define LCD_FCR_BLINK_1            (0x2UL << LCD_FCR_BLINK_Pos)                 /*!< 0x00020000 */

#define LCD_FCR_DIV_Pos            (18U)                                       
#define LCD_FCR_DIV_Msk            (0xFUL << LCD_FCR_DIV_Pos)                   /*!< 0x003C0000 */
#define LCD_FCR_DIV                LCD_FCR_DIV_Msk                             /*!< DIV[3:0] bits (Divider) */
#define LCD_FCR_PS_Pos             (22U)                                       
#define LCD_FCR_PS_Msk             (0xFUL << LCD_FCR_PS_Pos)                    /*!< 0x03C00000 */
#define LCD_FCR_PS                 LCD_FCR_PS_Msk                              /*!< PS[3:0] bits (Prescaler) */

/*******************  Bit definition for LCD_SR register  *********************/
#define LCD_SR_ENS_Pos             (0U)                                        
#define LCD_SR_ENS_Msk             (0x1UL << LCD_SR_ENS_Pos)                    /*!< 0x00000001 */
#define LCD_SR_ENS                 LCD_SR_ENS_Msk                              /*!< LCD Enabled Bit */
#define LCD_SR_SOF_Pos             (1U)                                        
#define LCD_SR_SOF_Msk             (0x1UL << LCD_SR_SOF_Pos)                    /*!< 0x00000002 */
#define LCD_SR_SOF                 LCD_SR_SOF_Msk                              /*!< Start Of Frame Flag Bit */
#define LCD_SR_UDR_Pos             (2U)                                        
#define LCD_SR_UDR_Msk             (0x1UL << LCD_SR_UDR_Pos)                    /*!< 0x00000004 */
#define LCD_SR_UDR                 LCD_SR_UDR_Msk                              /*!< Update Display Request Bit */
#define LCD_SR_UDD_Pos             (3U)                                        
#define LCD_SR_UDD_Msk             (0x1UL << LCD_SR_UDD_Pos)                    /*!< 0x00000008 */
#define LCD_SR_UDD                 LCD_SR_UDD_Msk                              /*!< Update Display Done Flag Bit */
#define LCD_SR_RDY_Pos             (4U)                                        
#define LCD_SR_RDY_Msk             (0x1UL << LCD_SR_RDY_Pos)                    /*!< 0x00000010 */
#define LCD_SR_RDY                 LCD_SR_RDY_Msk                              /*!< Ready Flag Bit */
#define LCD_SR_FCRSR_Pos           (5U)                                        
#define LCD_SR_FCRSR_Msk           (0x1UL << LCD_SR_FCRSR_Pos)                  /*!< 0x00000020 */
#define LCD_SR_FCRSR               LCD_SR_FCRSR_Msk                            /*!< LCD FCR Register Synchronization Flag Bit */

/*******************  Bit definition for LCD_CLR register  ********************/
#define LCD_CLR_SOFC_Pos           (1U)                                        
#define LCD_CLR_SOFC_Msk           (0x1UL << LCD_CLR_SOFC_Pos)                  /*!< 0x00000002 */
#define LCD_CLR_SOFC               LCD_CLR_SOFC_Msk                            /*!< Start Of Frame Flag Clear Bit */
#define LCD_CLR_UDDC_Pos           (3U)                                        
#define LCD_CLR_UDDC_Msk           (0x1UL << LCD_CLR_UDDC_Pos)                  /*!< 0x00000008 */
#define LCD_CLR_UDDC               LCD_CLR_UDDC_Msk                            /*!< Update Display Done Flag Clear Bit */

/*******************  Bit definition for LCD_RAM register  ********************/
#define LCD_RAM_SEGMENT_DATA_Pos   (0U)                                        
#define LCD_RAM_SEGMENT_DATA_Msk   (0xFFFFFFFFUL << LCD_RAM_SEGMENT_DATA_Pos)   /*!< 0xFFFFFFFF */
#define LCD_RAM_SEGMENT_DATA       LCD_RAM_SEGMENT_DATA_Msk                    /*!< Segment Data Bits */

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/*
* @brief Specific device feature definitions  (not present on all devices in the STM32F0 serie)
*/
#define RTC_TAMPER1_SUPPORT       /*!< TAMPER 1 feature support */
#define RTC_TAMPER2_SUPPORT       /*!< TAMPER 2 feature support */
#define RTC_TAMPER3_SUPPORT       /*!< TAMPER 3 feature support */
#define RTC_BACKUP_SUPPORT        /*!< BACKUP register feature support */
#define RTC_WAKEUP_SUPPORT        /*!< WAKEUP feature support */
#define RTC_SMOOTHCALIB_SUPPORT   /*!< Smooth digital calibration feature support */
#define RTC_SUBSECOND_SUPPORT     /*!< Sub-second feature support */

/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_PM_Pos                        (22U)                             
#define RTC_TR_PM_Msk                        (0x1UL << RTC_TR_PM_Pos)           /*!< 0x00400000 */
#define RTC_TR_PM                            RTC_TR_PM_Msk                     
#define RTC_TR_HT_Pos                        (20U)                             
#define RTC_TR_HT_Msk                        (0x3UL << RTC_TR_HT_Pos)           /*!< 0x00300000 */
#define RTC_TR_HT                            RTC_TR_HT_Msk                     
#define RTC_TR_HT_0                          (0x1UL << RTC_TR_HT_Pos)           /*!< 0x00100000 */
#define RTC_TR_HT_1                          (0x2UL << RTC_TR_HT_Pos)           /*!< 0x00200000 */
#define RTC_TR_HU_Pos                        (16U)                             
#define RTC_TR_HU_Msk                        (0xFUL << RTC_TR_HU_Pos)           /*!< 0x000F0000 */
#define RTC_TR_HU                            RTC_TR_HU_Msk                     
#define RTC_TR_HU_0                          (0x1UL << RTC_TR_HU_Pos)           /*!< 0x00010000 */
#define RTC_TR_HU_1                          (0x2UL << RTC_TR_HU_Pos)           /*!< 0x00020000 */
#define RTC_TR_HU_2                          (0x4UL << RTC_TR_HU_Pos)           /*!< 0x00040000 */
#define RTC_TR_HU_3                          (0x8UL << RTC_TR_HU_Pos)           /*!< 0x00080000 */
#define RTC_TR_MNT_Pos                       (12U)                             
#define RTC_TR_MNT_Msk                       (0x7UL << RTC_TR_MNT_Pos)          /*!< 0x00007000 */
#define RTC_TR_MNT                           RTC_TR_MNT_Msk                    
#define RTC_TR_MNT_0                         (0x1UL << RTC_TR_MNT_Pos)          /*!< 0x00001000 */
#define RTC_TR_MNT_1                         (0x2UL << RTC_TR_MNT_Pos)          /*!< 0x00002000 */
#define RTC_TR_MNT_2                         (0x4UL << RTC_TR_MNT_Pos)          /*!< 0x00004000 */
#define RTC_TR_MNU_Pos                       (8U)                              
#define RTC_TR_MNU_Msk                       (0xFUL << RTC_TR_MNU_Pos)          /*!< 0x00000F00 */
#define RTC_TR_MNU                           RTC_TR_MNU_Msk                    
#define RTC_TR_MNU_0                         (0x1UL << RTC_TR_MNU_Pos)          /*!< 0x00000100 */
#define RTC_TR_MNU_1                         (0x2UL << RTC_TR_MNU_Pos)          /*!< 0x00000200 */
#define RTC_TR_MNU_2                         (0x4UL << RTC_TR_MNU_Pos)          /*!< 0x00000400 */
#define RTC_TR_MNU_3                         (0x8UL << RTC_TR_MNU_Pos)          /*!< 0x00000800 */
#define RTC_TR_ST_Pos                        (4U)                              
#define RTC_TR_ST_Msk                        (0x7UL << RTC_TR_ST_Pos)           /*!< 0x00000070 */
#define RTC_TR_ST                            RTC_TR_ST_Msk                     
#define RTC_TR_ST_0                          (0x1UL << RTC_TR_ST_Pos)           /*!< 0x00000010 */
#define RTC_TR_ST_1                          (0x2UL << RTC_TR_ST_Pos)           /*!< 0x00000020 */
#define RTC_TR_ST_2                          (0x4UL << RTC_TR_ST_Pos)           /*!< 0x00000040 */
#define RTC_TR_SU_Pos                        (0U)                              
#define RTC_TR_SU_Msk                        (0xFUL << RTC_TR_SU_Pos)           /*!< 0x0000000F */
#define RTC_TR_SU                            RTC_TR_SU_Msk                     
#define RTC_TR_SU_0                          (0x1UL << RTC_TR_SU_Pos)           /*!< 0x00000001 */
#define RTC_TR_SU_1                          (0x2UL << RTC_TR_SU_Pos)           /*!< 0x00000002 */
#define RTC_TR_SU_2                          (0x4UL << RTC_TR_SU_Pos)           /*!< 0x00000004 */
#define RTC_TR_SU_3                          (0x8UL << RTC_TR_SU_Pos)           /*!< 0x00000008 */

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_YT_Pos                        (20U)                             
#define RTC_DR_YT_Msk                        (0xFUL << RTC_DR_YT_Pos)           /*!< 0x00F00000 */
#define RTC_DR_YT                            RTC_DR_YT_Msk                     
#define RTC_DR_YT_0                          (0x1UL << RTC_DR_YT_Pos)           /*!< 0x00100000 */
#define RTC_DR_YT_1                          (0x2UL << RTC_DR_YT_Pos)           /*!< 0x00200000 */
#define RTC_DR_YT_2                          (0x4UL << RTC_DR_YT_Pos)           /*!< 0x00400000 */
#define RTC_DR_YT_3                          (0x8UL << RTC_DR_YT_Pos)           /*!< 0x00800000 */
#define RTC_DR_YU_Pos                        (16U)                             
#define RTC_DR_YU_Msk                        (0xFUL << RTC_DR_YU_Pos)           /*!< 0x000F0000 */
#define RTC_DR_YU                            RTC_DR_YU_Msk                     
#define RTC_DR_YU_0                          (0x1UL << RTC_DR_YU_Pos)           /*!< 0x00010000 */
#define RTC_DR_YU_1                          (0x2UL << RTC_DR_YU_Pos)           /*!< 0x00020000 */
#define RTC_DR_YU_2                          (0x4UL << RTC_DR_YU_Pos)           /*!< 0x00040000 */
#define RTC_DR_YU_3                          (0x8UL << RTC_DR_YU_Pos)           /*!< 0x00080000 */
#define RTC_DR_WDU_Pos                       (13U)                             
#define RTC_DR_WDU_Msk                       (0x7UL << RTC_DR_WDU_Pos)          /*!< 0x0000E000 */
#define RTC_DR_WDU                           RTC_DR_WDU_Msk                    
#define RTC_DR_WDU_0                         (0x1UL << RTC_DR_WDU_Pos)          /*!< 0x00002000 */
#define RTC_DR_WDU_1                         (0x2UL << RTC_DR_WDU_Pos)          /*!< 0x00004000 */
#define RTC_DR_WDU_2                         (0x4UL << RTC_DR_WDU_Pos)          /*!< 0x00008000 */
#define RTC_DR_MT_Pos                        (12U)                             
#define RTC_DR_MT_Msk                        (0x1UL << RTC_DR_MT_Pos)           /*!< 0x00001000 */
#define RTC_DR_MT                            RTC_DR_MT_Msk                     
#define RTC_DR_MU_Pos                        (8U)                              
#define RTC_DR_MU_Msk                        (0xFUL << RTC_DR_MU_Pos)           /*!< 0x00000F00 */
#define RTC_DR_MU                            RTC_DR_MU_Msk                     
#define RTC_DR_MU_0                          (0x1UL << RTC_DR_MU_Pos)           /*!< 0x00000100 */
#define RTC_DR_MU_1                          (0x2UL << RTC_DR_MU_Pos)           /*!< 0x00000200 */
#define RTC_DR_MU_2                          (0x4UL << RTC_DR_MU_Pos)           /*!< 0x00000400 */
#define RTC_DR_MU_3                          (0x8UL << RTC_DR_MU_Pos)           /*!< 0x00000800 */
#define RTC_DR_DT_Pos                        (4U)                              
#define RTC_DR_DT_Msk                        (0x3UL << RTC_DR_DT_Pos)           /*!< 0x00000030 */
#define RTC_DR_DT                            RTC_DR_DT_Msk                     
#define RTC_DR_DT_0                          (0x1UL << RTC_DR_DT_Pos)           /*!< 0x00000010 */
#define RTC_DR_DT_1                          (0x2UL << RTC_DR_DT_Pos)           /*!< 0x00000020 */
#define RTC_DR_DU_Pos                        (0U)                              
#define RTC_DR_DU_Msk                        (0xFUL << RTC_DR_DU_Pos)           /*!< 0x0000000F */
#define RTC_DR_DU                            RTC_DR_DU_Msk                     
#define RTC_DR_DU_0                          (0x1UL << RTC_DR_DU_Pos)           /*!< 0x00000001 */
#define RTC_DR_DU_1                          (0x2UL << RTC_DR_DU_Pos)           /*!< 0x00000002 */
#define RTC_DR_DU_2                          (0x4UL << RTC_DR_DU_Pos)           /*!< 0x00000004 */
#define RTC_DR_DU_3                          (0x8UL << RTC_DR_DU_Pos)           /*!< 0x00000008 */

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_COE_Pos                       (23U)                             
#define RTC_CR_COE_Msk                       (0x1UL << RTC_CR_COE_Pos)          /*!< 0x00800000 */
#define RTC_CR_COE                           RTC_CR_COE_Msk                    
#define RTC_CR_OSEL_Pos                      (21U)                             
#define RTC_CR_OSEL_Msk                      (0x3UL << RTC_CR_OSEL_Pos)         /*!< 0x00600000 */
#define RTC_CR_OSEL                          RTC_CR_OSEL_Msk                   
#define RTC_CR_OSEL_0                        (0x1UL << RTC_CR_OSEL_Pos)         /*!< 0x00200000 */
#define RTC_CR_OSEL_1                        (0x2UL << RTC_CR_OSEL_Pos)         /*!< 0x00400000 */
#define RTC_CR_POL_Pos                       (20U)                             
#define RTC_CR_POL_Msk                       (0x1UL << RTC_CR_POL_Pos)          /*!< 0x00100000 */
#define RTC_CR_POL                           RTC_CR_POL_Msk                    
#define RTC_CR_COSEL_Pos                     (19U)                             
#define RTC_CR_COSEL_Msk                     (0x1UL << RTC_CR_COSEL_Pos)        /*!< 0x00080000 */
#define RTC_CR_COSEL                         RTC_CR_COSEL_Msk                  
#define RTC_CR_BKP_Pos                       (18U)                             
#define RTC_CR_BKP_Msk                       (0x1UL << RTC_CR_BKP_Pos)          /*!< 0x00040000 */
#define RTC_CR_BKP                           RTC_CR_BKP_Msk                    
#define RTC_CR_SUB1H_Pos                     (17U)                             
#define RTC_CR_SUB1H_Msk                     (0x1UL << RTC_CR_SUB1H_Pos)        /*!< 0x00020000 */
#define RTC_CR_SUB1H                         RTC_CR_SUB1H_Msk                  
#define RTC_CR_ADD1H_Pos                     (16U)                             
#define RTC_CR_ADD1H_Msk                     (0x1UL << RTC_CR_ADD1H_Pos)        /*!< 0x00010000 */
#define RTC_CR_ADD1H                         RTC_CR_ADD1H_Msk                  
#define RTC_CR_TSIE_Pos                      (15U)                             
#define RTC_CR_TSIE_Msk                      (0x1UL << RTC_CR_TSIE_Pos)         /*!< 0x00008000 */
#define RTC_CR_TSIE                          RTC_CR_TSIE_Msk                   
#define RTC_CR_WUTIE_Pos                     (14U)                             
#define RTC_CR_WUTIE_Msk                     (0x1UL << RTC_CR_WUTIE_Pos)        /*!< 0x00004000 */
#define RTC_CR_WUTIE                         RTC_CR_WUTIE_Msk                  
#define RTC_CR_ALRBIE_Pos                    (13U)                             
#define RTC_CR_ALRBIE_Msk                    (0x1UL << RTC_CR_ALRBIE_Pos)       /*!< 0x00002000 */
#define RTC_CR_ALRBIE                        RTC_CR_ALRBIE_Msk                 
#define RTC_CR_ALRAIE_Pos                    (12U)                             
#define RTC_CR_ALRAIE_Msk                    (0x1UL << RTC_CR_ALRAIE_Pos)       /*!< 0x00001000 */
#define RTC_CR_ALRAIE                        RTC_CR_ALRAIE_Msk                 
#define RTC_CR_TSE_Pos                       (11U)                             
#define RTC_CR_TSE_Msk                       (0x1UL << RTC_CR_TSE_Pos)          /*!< 0x00000800 */
#define RTC_CR_TSE                           RTC_CR_TSE_Msk                    
#define RTC_CR_WUTE_Pos                      (10U)                             
#define RTC_CR_WUTE_Msk                      (0x1UL << RTC_CR_WUTE_Pos)         /*!< 0x00000400 */
#define RTC_CR_WUTE                          RTC_CR_WUTE_Msk                   
#define RTC_CR_ALRBE_Pos                     (9U)                              
#define RTC_CR_ALRBE_Msk                     (0x1UL << RTC_CR_ALRBE_Pos)        /*!< 0x00000200 */
#define RTC_CR_ALRBE                         RTC_CR_ALRBE_Msk                  
#define RTC_CR_ALRAE_Pos                     (8U)                              
#define RTC_CR_ALRAE_Msk                     (0x1UL << RTC_CR_ALRAE_Pos)        /*!< 0x00000100 */
#define RTC_CR_ALRAE                         RTC_CR_ALRAE_Msk                  
#define RTC_CR_DCE_Pos                       (7U)                              
#define RTC_CR_DCE_Msk                       (0x1UL << RTC_CR_DCE_Pos)          /*!< 0x00000080 */
#define RTC_CR_DCE                           RTC_CR_DCE_Msk                    
#define RTC_CR_FMT_Pos                       (6U)                              
#define RTC_CR_FMT_Msk                       (0x1UL << RTC_CR_FMT_Pos)          /*!< 0x00000040 */
#define RTC_CR_FMT                           RTC_CR_FMT_Msk                    
#define RTC_CR_BYPSHAD_Pos                   (5U)                              
#define RTC_CR_BYPSHAD_Msk                   (0x1UL << RTC_CR_BYPSHAD_Pos)      /*!< 0x00000020 */
#define RTC_CR_BYPSHAD                       RTC_CR_BYPSHAD_Msk                
#define RTC_CR_REFCKON_Pos                   (4U)                              
#define RTC_CR_REFCKON_Msk                   (0x1UL << RTC_CR_REFCKON_Pos)      /*!< 0x00000010 */
#define RTC_CR_REFCKON                       RTC_CR_REFCKON_Msk                
#define RTC_CR_TSEDGE_Pos                    (3U)                              
#define RTC_CR_TSEDGE_Msk                    (0x1UL << RTC_CR_TSEDGE_Pos)       /*!< 0x00000008 */
#define RTC_CR_TSEDGE                        RTC_CR_TSEDGE_Msk                 
#define RTC_CR_WUCKSEL_Pos                   (0U)                              
#define RTC_CR_WUCKSEL_Msk                   (0x7UL << RTC_CR_WUCKSEL_Pos)      /*!< 0x00000007 */
#define RTC_CR_WUCKSEL                       RTC_CR_WUCKSEL_Msk                
#define RTC_CR_WUCKSEL_0                     (0x1UL << RTC_CR_WUCKSEL_Pos)      /*!< 0x00000001 */
#define RTC_CR_WUCKSEL_1                     (0x2UL << RTC_CR_WUCKSEL_Pos)      /*!< 0x00000002 */
#define RTC_CR_WUCKSEL_2                     (0x4UL << RTC_CR_WUCKSEL_Pos)      /*!< 0x00000004 */

/* Legacy defines */
#define  RTC_CR_BCK_Pos RTC_CR_BKP_Pos
#define  RTC_CR_BCK_Msk RTC_CR_BKP_Msk
#define  RTC_CR_BCK     RTC_CR_BKP

/********************  Bits definition for RTC_ISR register  ******************/
#define RTC_ISR_RECALPF_Pos                  (16U)                             
#define RTC_ISR_RECALPF_Msk                  (0x1UL << RTC_ISR_RECALPF_Pos)     /*!< 0x00010000 */
#define RTC_ISR_RECALPF                      RTC_ISR_RECALPF_Msk               
#define RTC_ISR_TAMP3F_Pos                   (15U)                             
#define RTC_ISR_TAMP3F_Msk                   (0x1UL << RTC_ISR_TAMP3F_Pos)      /*!< 0x00008000 */
#define RTC_ISR_TAMP3F                       RTC_ISR_TAMP3F_Msk                
#define RTC_ISR_TAMP2F_Pos                   (14U)                             
#define RTC_ISR_TAMP2F_Msk                   (0x1UL << RTC_ISR_TAMP2F_Pos)      /*!< 0x00004000 */
#define RTC_ISR_TAMP2F                       RTC_ISR_TAMP2F_Msk                
#define RTC_ISR_TAMP1F_Pos                   (13U)                             
#define RTC_ISR_TAMP1F_Msk                   (0x1UL << RTC_ISR_TAMP1F_Pos)      /*!< 0x00002000 */
#define RTC_ISR_TAMP1F                       RTC_ISR_TAMP1F_Msk                
#define RTC_ISR_TSOVF_Pos                    (12U)                             
#define RTC_ISR_TSOVF_Msk                    (0x1UL << RTC_ISR_TSOVF_Pos)       /*!< 0x00001000 */
#define RTC_ISR_TSOVF                        RTC_ISR_TSOVF_Msk                 
#define RTC_ISR_TSF_Pos                      (11U)                             
#define RTC_ISR_TSF_Msk                      (0x1UL << RTC_ISR_TSF_Pos)         /*!< 0x00000800 */
#define RTC_ISR_TSF                          RTC_ISR_TSF_Msk                   
#define RTC_ISR_WUTF_Pos                     (10U)                             
#define RTC_ISR_WUTF_Msk                     (0x1UL << RTC_ISR_WUTF_Pos)        /*!< 0x00000400 */
#define RTC_ISR_WUTF                         RTC_ISR_WUTF_Msk                  
#define RTC_ISR_ALRBF_Pos                    (9U)                              
#define RTC_ISR_ALRBF_Msk                    (0x1UL << RTC_ISR_ALRBF_Pos)       /*!< 0x00000200 */
#define RTC_ISR_ALRBF                        RTC_ISR_ALRBF_Msk                 
#define RTC_ISR_ALRAF_Pos                    (8U)                              
#define RTC_ISR_ALRAF_Msk                    (0x1UL << RTC_ISR_ALRAF_Pos)       /*!< 0x00000100 */
#define RTC_ISR_ALRAF                        RTC_ISR_ALRAF_Msk                 
#define RTC_ISR_INIT_Pos                     (7U)                              
#define RTC_ISR_INIT_Msk                     (0x1UL << RTC_ISR_INIT_Pos)        /*!< 0x00000080 */
#define RTC_ISR_INIT                         RTC_ISR_INIT_Msk                  
#define RTC_ISR_INITF_Pos                    (6U)                              
#define RTC_ISR_INITF_Msk                    (0x1UL << RTC_ISR_INITF_Pos)       /*!< 0x00000040 */
#define RTC_ISR_INITF                        RTC_ISR_INITF_Msk                 
#define RTC_ISR_RSF_Pos                      (5U)                              
#define RTC_ISR_RSF_Msk                      (0x1UL << RTC_ISR_RSF_Pos)         /*!< 0x00000020 */
#define RTC_ISR_RSF                          RTC_ISR_RSF_Msk                   
#define RTC_ISR_INITS_Pos                    (4U)                              
#define RTC_ISR_INITS_Msk                    (0x1UL << RTC_ISR_INITS_Pos)       /*!< 0x00000010 */
#define RTC_ISR_INITS                        RTC_ISR_INITS_Msk                 
#define RTC_ISR_SHPF_Pos                     (3U)                              
#define RTC_ISR_SHPF_Msk                     (0x1UL << RTC_ISR_SHPF_Pos)        /*!< 0x00000008 */
#define RTC_ISR_SHPF                         RTC_ISR_SHPF_Msk                  
#define RTC_ISR_WUTWF_Pos                    (2U)                              
#define RTC_ISR_WUTWF_Msk                    (0x1UL << RTC_ISR_WUTWF_Pos)       /*!< 0x00000004 */
#define RTC_ISR_WUTWF                        RTC_ISR_WUTWF_Msk                 
#define RTC_ISR_ALRBWF_Pos                   (1U)                              
#define RTC_ISR_ALRBWF_Msk                   (0x1UL << RTC_ISR_ALRBWF_Pos)      /*!< 0x00000002 */
#define RTC_ISR_ALRBWF                       RTC_ISR_ALRBWF_Msk                
#define RTC_ISR_ALRAWF_Pos                   (0U)                              
#define RTC_ISR_ALRAWF_Msk                   (0x1UL << RTC_ISR_ALRAWF_Pos)      /*!< 0x00000001 */
#define RTC_ISR_ALRAWF                       RTC_ISR_ALRAWF_Msk                

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_A_Pos                (16U)                             
#define RTC_PRER_PREDIV_A_Msk                (0x7FUL << RTC_PRER_PREDIV_A_Pos)  /*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A                    RTC_PRER_PREDIV_A_Msk             
#define RTC_PRER_PREDIV_S_Pos                (0U)                              
#define RTC_PRER_PREDIV_S_Msk                (0x7FFFUL << RTC_PRER_PREDIV_S_Pos) /*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S                    RTC_PRER_PREDIV_S_Msk             

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT_Pos                     (0U)                              
#define RTC_WUTR_WUT_Msk                     (0xFFFFUL << RTC_WUTR_WUT_Pos)     /*!< 0x0000FFFF */
#define RTC_WUTR_WUT                         RTC_WUTR_WUT_Msk                  

/********************  Bits definition for RTC_CALIBR register  ***************/
#define RTC_CALIBR_DCS_Pos                   (7U)                              
#define RTC_CALIBR_DCS_Msk                   (0x1UL << RTC_CALIBR_DCS_Pos)      /*!< 0x00000080 */
#define RTC_CALIBR_DCS                       RTC_CALIBR_DCS_Msk                
#define RTC_CALIBR_DC_Pos                    (0U)                              
#define RTC_CALIBR_DC_Msk                    (0x1FUL << RTC_CALIBR_DC_Pos)      /*!< 0x0000001F */
#define RTC_CALIBR_DC                        RTC_CALIBR_DC_Msk                 

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_MSK4_Pos                  (31U)                             
#define RTC_ALRMAR_MSK4_Msk                  (0x1UL << RTC_ALRMAR_MSK4_Pos)     /*!< 0x80000000 */
#define RTC_ALRMAR_MSK4                      RTC_ALRMAR_MSK4_Msk               
#define RTC_ALRMAR_WDSEL_Pos                 (30U)                             
#define RTC_ALRMAR_WDSEL_Msk                 (0x1UL << RTC_ALRMAR_WDSEL_Pos)    /*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL                     RTC_ALRMAR_WDSEL_Msk              
#define RTC_ALRMAR_DT_Pos                    (28U)                             
#define RTC_ALRMAR_DT_Msk                    (0x3UL << RTC_ALRMAR_DT_Pos)       /*!< 0x30000000 */
#define RTC_ALRMAR_DT                        RTC_ALRMAR_DT_Msk                 
#define RTC_ALRMAR_DT_0                      (0x1UL << RTC_ALRMAR_DT_Pos)       /*!< 0x10000000 */
#define RTC_ALRMAR_DT_1                      (0x2UL << RTC_ALRMAR_DT_Pos)       /*!< 0x20000000 */
#define RTC_ALRMAR_DU_Pos                    (24U)                             
#define RTC_ALRMAR_DU_Msk                    (0xFUL << RTC_ALRMAR_DU_Pos)       /*!< 0x0F000000 */
#define RTC_ALRMAR_DU                        RTC_ALRMAR_DU_Msk                 
#define RTC_ALRMAR_DU_0                      (0x1UL << RTC_ALRMAR_DU_Pos)       /*!< 0x01000000 */
#define RTC_ALRMAR_DU_1                      (0x2UL << RTC_ALRMAR_DU_Pos)       /*!< 0x02000000 */
#define RTC_ALRMAR_DU_2                      (0x4UL << RTC_ALRMAR_DU_Pos)       /*!< 0x04000000 */
#define RTC_ALRMAR_DU_3                      (0x8UL << RTC_ALRMAR_DU_Pos)       /*!< 0x08000000 */
#define RTC_ALRMAR_MSK3_Pos                  (23U)                             
#define RTC_ALRMAR_MSK3_Msk                  (0x1UL << RTC_ALRMAR_MSK3_Pos)     /*!< 0x00800000 */
#define RTC_ALRMAR_MSK3                      RTC_ALRMAR_MSK3_Msk               
#define RTC_ALRMAR_PM_Pos                    (22U)                             
#define RTC_ALRMAR_PM_Msk                    (0x1UL << RTC_ALRMAR_PM_Pos)       /*!< 0x00400000 */
#define RTC_ALRMAR_PM                        RTC_ALRMAR_PM_Msk                 
#define RTC_ALRMAR_HT_Pos                    (20U)                             
#define RTC_ALRMAR_HT_Msk                    (0x3UL << RTC_ALRMAR_HT_Pos)       /*!< 0x00300000 */
#define RTC_ALRMAR_HT                        RTC_ALRMAR_HT_Msk                 
#define RTC_ALRMAR_HT_0                      (0x1UL << RTC_ALRMAR_HT_Pos)       /*!< 0x00100000 */
#define RTC_ALRMAR_HT_1                      (0x2UL << RTC_ALRMAR_HT_Pos)       /*!< 0x00200000 */
#define RTC_ALRMAR_HU_Pos                    (16U)                             
#define RTC_ALRMAR_HU_Msk                    (0xFUL << RTC_ALRMAR_HU_Pos)       /*!< 0x000F0000 */
#define RTC_ALRMAR_HU                        RTC_ALRMAR_HU_Msk                 
#define RTC_ALRMAR_HU_0                      (0x1UL << RTC_ALRMAR_HU_Pos)       /*!< 0x00010000 */
#define RTC_ALRMAR_HU_1                      (0x2UL << RTC_ALRMAR_HU_Pos)       /*!< 0x00020000 */
#define RTC_ALRMAR_HU_2                      (0x4UL << RTC_ALRMAR_HU_Pos)       /*!< 0x00040000 */
#define RTC_ALRMAR_HU_3                      (0x8UL << RTC_ALRMAR_HU_Pos)       /*!< 0x00080000 */
#define RTC_ALRMAR_MSK2_Pos                  (15U)                             
#define RTC_ALRMAR_MSK2_Msk                  (0x1UL << RTC_ALRMAR_MSK2_Pos)     /*!< 0x00008000 */
#define RTC_ALRMAR_MSK2                      RTC_ALRMAR_MSK2_Msk               
#define RTC_ALRMAR_MNT_Pos                   (12U)                             
#define RTC_ALRMAR_MNT_Msk                   (0x7UL << RTC_ALRMAR_MNT_Pos)      /*!< 0x00007000 */
#define RTC_ALRMAR_MNT                       RTC_ALRMAR_MNT_Msk                
#define RTC_ALRMAR_MNT_0                     (0x1UL << RTC_ALRMAR_MNT_Pos)      /*!< 0x00001000 */
#define RTC_ALRMAR_MNT_1                     (0x2UL << RTC_ALRMAR_MNT_Pos)      /*!< 0x00002000 */
#define RTC_ALRMAR_MNT_2                     (0x4UL << RTC_ALRMAR_MNT_Pos)      /*!< 0x00004000 */
#define RTC_ALRMAR_MNU_Pos                   (8U)                              
#define RTC_ALRMAR_MNU_Msk                   (0xFUL << RTC_ALRMAR_MNU_Pos)      /*!< 0x00000F00 */
#define RTC_ALRMAR_MNU                       RTC_ALRMAR_MNU_Msk                
#define RTC_ALRMAR_MNU_0                     (0x1UL << RTC_ALRMAR_MNU_Pos)      /*!< 0x00000100 */
#define RTC_ALRMAR_MNU_1                     (0x2UL << RTC_ALRMAR_MNU_Pos)      /*!< 0x00000200 */
#define RTC_ALRMAR_MNU_2                     (0x4UL << RTC_ALRMAR_MNU_Pos)      /*!< 0x00000400 */
#define RTC_ALRMAR_MNU_3                     (0x8UL << RTC_ALRMAR_MNU_Pos)      /*!< 0x00000800 */
#define RTC_ALRMAR_MSK1_Pos                  (7U)                              
#define RTC_ALRMAR_MSK1_Msk                  (0x1UL << RTC_ALRMAR_MSK1_Pos)     /*!< 0x00000080 */
#define RTC_ALRMAR_MSK1                      RTC_ALRMAR_MSK1_Msk               
#define RTC_ALRMAR_ST_Pos                    (4U)                              
#define RTC_ALRMAR_ST_Msk                    (0x7UL << RTC_ALRMAR_ST_Pos)       /*!< 0x00000070 */
#define RTC_ALRMAR_ST                        RTC_ALRMAR_ST_Msk                 
#define RTC_ALRMAR_ST_0                      (0x1UL << RTC_ALRMAR_ST_Pos)       /*!< 0x00000010 */
#define RTC_ALRMAR_ST_1                      (0x2UL << RTC_ALRMAR_ST_Pos)       /*!< 0x00000020 */
#define RTC_ALRMAR_ST_2                      (0x4UL << RTC_ALRMAR_ST_Pos)       /*!< 0x00000040 */
#define RTC_ALRMAR_SU_Pos                    (0U)                              
#define RTC_ALRMAR_SU_Msk                    (0xFUL << RTC_ALRMAR_SU_Pos)       /*!< 0x0000000F */
#define RTC_ALRMAR_SU                        RTC_ALRMAR_SU_Msk                 
#define RTC_ALRMAR_SU_0                      (0x1UL << RTC_ALRMAR_SU_Pos)       /*!< 0x00000001 */
#define RTC_ALRMAR_SU_1                      (0x2UL << RTC_ALRMAR_SU_Pos)       /*!< 0x00000002 */
#define RTC_ALRMAR_SU_2                      (0x4UL << RTC_ALRMAR_SU_Pos)       /*!< 0x00000004 */
#define RTC_ALRMAR_SU_3                      (0x8UL << RTC_ALRMAR_SU_Pos)       /*!< 0x00000008 */

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_MSK4_Pos                  (31U)                             
#define RTC_ALRMBR_MSK4_Msk                  (0x1UL << RTC_ALRMBR_MSK4_Pos)     /*!< 0x80000000 */
#define RTC_ALRMBR_MSK4                      RTC_ALRMBR_MSK4_Msk               
#define RTC_ALRMBR_WDSEL_Pos                 (30U)                             
#define RTC_ALRMBR_WDSEL_Msk                 (0x1UL << RTC_ALRMBR_WDSEL_Pos)    /*!< 0x40000000 */
#define RTC_ALRMBR_WDSEL                     RTC_ALRMBR_WDSEL_Msk              
#define RTC_ALRMBR_DT_Pos                    (28U)                             
#define RTC_ALRMBR_DT_Msk                    (0x3UL << RTC_ALRMBR_DT_Pos)       /*!< 0x30000000 */
#define RTC_ALRMBR_DT                        RTC_ALRMBR_DT_Msk                 
#define RTC_ALRMBR_DT_0                      (0x1UL << RTC_ALRMBR_DT_Pos)       /*!< 0x10000000 */
#define RTC_ALRMBR_DT_1                      (0x2UL << RTC_ALRMBR_DT_Pos)       /*!< 0x20000000 */
#define RTC_ALRMBR_DU_Pos                    (24U)                             
#define RTC_ALRMBR_DU_Msk                    (0xFUL << RTC_ALRMBR_DU_Pos)       /*!< 0x0F000000 */
#define RTC_ALRMBR_DU                        RTC_ALRMBR_DU_Msk                 
#define RTC_ALRMBR_DU_0                      (0x1UL << RTC_ALRMBR_DU_Pos)       /*!< 0x01000000 */
#define RTC_ALRMBR_DU_1                      (0x2UL << RTC_ALRMBR_DU_Pos)       /*!< 0x02000000 */
#define RTC_ALRMBR_DU_2                      (0x4UL << RTC_ALRMBR_DU_Pos)       /*!< 0x04000000 */
#define RTC_ALRMBR_DU_3                      (0x8UL << RTC_ALRMBR_DU_Pos)       /*!< 0x08000000 */
#define RTC_ALRMBR_MSK3_Pos                  (23U)                             
#define RTC_ALRMBR_MSK3_Msk                  (0x1UL << RTC_ALRMBR_MSK3_Pos)     /*!< 0x00800000 */
#define RTC_ALRMBR_MSK3                      RTC_ALRMBR_MSK3_Msk               
#define RTC_ALRMBR_PM_Pos                    (22U)                             
#define RTC_ALRMBR_PM_Msk                    (0x1UL << RTC_ALRMBR_PM_Pos)       /*!< 0x00400000 */
#define RTC_ALRMBR_PM                        RTC_ALRMBR_PM_Msk                 
#define RTC_ALRMBR_HT_Pos                    (20U)                             
#define RTC_ALRMBR_HT_Msk                    (0x3UL << RTC_ALRMBR_HT_Pos)       /*!< 0x00300000 */
#define RTC_ALRMBR_HT                        RTC_ALRMBR_HT_Msk                 
#define RTC_ALRMBR_HT_0                      (0x1UL << RTC_ALRMBR_HT_Pos)       /*!< 0x00100000 */
#define RTC_ALRMBR_HT_1                      (0x2UL << RTC_ALRMBR_HT_Pos)       /*!< 0x00200000 */
#define RTC_ALRMBR_HU_Pos                    (16U)                             
#define RTC_ALRMBR_HU_Msk                    (0xFUL << RTC_ALRMBR_HU_Pos)       /*!< 0x000F0000 */
#define RTC_ALRMBR_HU                        RTC_ALRMBR_HU_Msk                 
#define RTC_ALRMBR_HU_0                      (0x1UL << RTC_ALRMBR_HU_Pos)       /*!< 0x00010000 */
#define RTC_ALRMBR_HU_1                      (0x2UL << RTC_ALRMBR_HU_Pos)       /*!< 0x00020000 */
#define RTC_ALRMBR_HU_2                      (0x4UL << RTC_ALRMBR_HU_Pos)       /*!< 0x00040000 */
#define RTC_ALRMBR_HU_3                      (0x8UL << RTC_ALRMBR_HU_Pos)       /*!< 0x00080000 */
#define RTC_ALRMBR_MSK2_Pos                  (15U)                             
#define RTC_ALRMBR_MSK2_Msk                  (0x1UL << RTC_ALRMBR_MSK2_Pos)     /*!< 0x00008000 */
#define RTC_ALRMBR_MSK2                      RTC_ALRMBR_MSK2_Msk               
#define RTC_ALRMBR_MNT_Pos                   (12U)                             
#define RTC_ALRMBR_MNT_Msk                   (0x7UL << RTC_ALRMBR_MNT_Pos)      /*!< 0x00007000 */
#define RTC_ALRMBR_MNT                       RTC_ALRMBR_MNT_Msk                
#define RTC_ALRMBR_MNT_0                     (0x1UL << RTC_ALRMBR_MNT_Pos)      /*!< 0x00001000 */
#define RTC_ALRMBR_MNT_1                     (0x2UL << RTC_ALRMBR_MNT_Pos)      /*!< 0x00002000 */
#define RTC_ALRMBR_MNT_2                     (0x4UL << RTC_ALRMBR_MNT_Pos)      /*!< 0x00004000 */
#define RTC_ALRMBR_MNU_Pos                   (8U)                              
#define RTC_ALRMBR_MNU_Msk                   (0xFUL << RTC_ALRMBR_MNU_Pos)      /*!< 0x00000F00 */
#define RTC_ALRMBR_MNU                       RTC_ALRMBR_MNU_Msk                
#define RTC_ALRMBR_MNU_0                     (0x1UL << RTC_ALRMBR_MNU_Pos)      /*!< 0x00000100 */
#define RTC_ALRMBR_MNU_1                     (0x2UL << RTC_ALRMBR_MNU_Pos)      /*!< 0x00000200 */
#define RTC_ALRMBR_MNU_2                     (0x4UL << RTC_ALRMBR_MNU_Pos)      /*!< 0x00000400 */
#define RTC_ALRMBR_MNU_3                     (0x8UL << RTC_ALRMBR_MNU_Pos)      /*!< 0x00000800 */
#define RTC_ALRMBR_MSK1_Pos                  (7U)                              
#define RTC_ALRMBR_MSK1_Msk                  (0x1UL << RTC_ALRMBR_MSK1_Pos)     /*!< 0x00000080 */
#define RTC_ALRMBR_MSK1                      RTC_ALRMBR_MSK1_Msk               
#define RTC_ALRMBR_ST_Pos                    (4U)                              
#define RTC_ALRMBR_ST_Msk                    (0x7UL << RTC_ALRMBR_ST_Pos)       /*!< 0x00000070 */
#define RTC_ALRMBR_ST                        RTC_ALRMBR_ST_Msk                 
#define RTC_ALRMBR_ST_0                      (0x1UL << RTC_ALRMBR_ST_Pos)       /*!< 0x00000010 */
#define RTC_ALRMBR_ST_1                      (0x2UL << RTC_ALRMBR_ST_Pos)       /*!< 0x00000020 */
#define RTC_ALRMBR_ST_2                      (0x4UL << RTC_ALRMBR_ST_Pos)       /*!< 0x00000040 */
#define RTC_ALRMBR_SU_Pos                    (0U)                              
#define RTC_ALRMBR_SU_Msk                    (0xFUL << RTC_ALRMBR_SU_Pos)       /*!< 0x0000000F */
#define RTC_ALRMBR_SU                        RTC_ALRMBR_SU_Msk                 
#define RTC_ALRMBR_SU_0                      (0x1UL << RTC_ALRMBR_SU_Pos)       /*!< 0x00000001 */
#define RTC_ALRMBR_SU_1                      (0x2UL << RTC_ALRMBR_SU_Pos)       /*!< 0x00000002 */
#define RTC_ALRMBR_SU_2                      (0x4UL << RTC_ALRMBR_SU_Pos)       /*!< 0x00000004 */
#define RTC_ALRMBR_SU_3                      (0x8UL << RTC_ALRMBR_SU_Pos)       /*!< 0x00000008 */

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY_Pos                      (0U)                              
#define RTC_WPR_KEY_Msk                      (0xFFUL << RTC_WPR_KEY_Pos)        /*!< 0x000000FF */
#define RTC_WPR_KEY                          RTC_WPR_KEY_Msk                   

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS_Pos                       (0U)                              
#define RTC_SSR_SS_Msk                       (0xFFFFUL << RTC_SSR_SS_Pos)       /*!< 0x0000FFFF */
#define RTC_SSR_SS                           RTC_SSR_SS_Msk                    

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS_Pos                 (0U)                              
#define RTC_SHIFTR_SUBFS_Msk                 (0x7FFFUL << RTC_SHIFTR_SUBFS_Pos) /*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS                     RTC_SHIFTR_SUBFS_Msk              
#define RTC_SHIFTR_ADD1S_Pos                 (31U)                             
#define RTC_SHIFTR_ADD1S_Msk                 (0x1UL << RTC_SHIFTR_ADD1S_Pos)    /*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S                     RTC_SHIFTR_ADD1S_Msk              

/********************  Bits definition for RTC_TSTR register  *****************/
#define RTC_TSTR_PM_Pos                      (22U)                             
#define RTC_TSTR_PM_Msk                      (0x1UL << RTC_TSTR_PM_Pos)         /*!< 0x00400000 */
#define RTC_TSTR_PM                          RTC_TSTR_PM_Msk                   
#define RTC_TSTR_HT_Pos                      (20U)                             
#define RTC_TSTR_HT_Msk                      (0x3UL << RTC_TSTR_HT_Pos)         /*!< 0x00300000 */
#define RTC_TSTR_HT                          RTC_TSTR_HT_Msk                   
#define RTC_TSTR_HT_0                        (0x1UL << RTC_TSTR_HT_Pos)         /*!< 0x00100000 */
#define RTC_TSTR_HT_1                        (0x2UL << RTC_TSTR_HT_Pos)         /*!< 0x00200000 */
#define RTC_TSTR_HU_Pos                      (16U)                             
#define RTC_TSTR_HU_Msk                      (0xFUL << RTC_TSTR_HU_Pos)         /*!< 0x000F0000 */
#define RTC_TSTR_HU                          RTC_TSTR_HU_Msk                   
#define RTC_TSTR_HU_0                        (0x1UL << RTC_TSTR_HU_Pos)         /*!< 0x00010000 */
#define RTC_TSTR_HU_1                        (0x2UL << RTC_TSTR_HU_Pos)         /*!< 0x00020000 */
#define RTC_TSTR_HU_2                        (0x4UL << RTC_TSTR_HU_Pos)         /*!< 0x00040000 */
#define RTC_TSTR_HU_3                        (0x8UL << RTC_TSTR_HU_Pos)         /*!< 0x00080000 */
#define RTC_TSTR_MNT_Pos                     (12U)                             
#define RTC_TSTR_MNT_Msk                     (0x7UL << RTC_TSTR_MNT_Pos)        /*!< 0x00007000 */
#define RTC_TSTR_MNT                         RTC_TSTR_MNT_Msk                  
#define RTC_TSTR_MNT_0                       (0x1UL << RTC_TSTR_MNT_Pos)        /*!< 0x00001000 */
#define RTC_TSTR_MNT_1                       (0x2UL << RTC_TSTR_MNT_Pos)        /*!< 0x00002000 */
#define RTC_TSTR_MNT_2                       (0x4UL << RTC_TSTR_MNT_Pos)        /*!< 0x00004000 */
#define RTC_TSTR_MNU_Pos                     (8U)                              
#define RTC_TSTR_MNU_Msk                     (0xFUL << RTC_TSTR_MNU_Pos)        /*!< 0x00000F00 */
#define RTC_TSTR_MNU                         RTC_TSTR_MNU_Msk                  
#define RTC_TSTR_MNU_0                       (0x1UL << RTC_TSTR_MNU_Pos)        /*!< 0x00000100 */
#define RTC_TSTR_MNU_1                       (0x2UL << RTC_TSTR_MNU_Pos)        /*!< 0x00000200 */
#define RTC_TSTR_MNU_2                       (0x4UL << RTC_TSTR_MNU_Pos)        /*!< 0x00000400 */
#define RTC_TSTR_MNU_3                       (0x8UL << RTC_TSTR_MNU_Pos)        /*!< 0x00000800 */
#define RTC_TSTR_ST_Pos                      (4U)                              
#define RTC_TSTR_ST_Msk                      (0x7UL << RTC_TSTR_ST_Pos)         /*!< 0x00000070 */
#define RTC_TSTR_ST                          RTC_TSTR_ST_Msk                   
#define RTC_TSTR_ST_0                        (0x1UL << RTC_TSTR_ST_Pos)         /*!< 0x00000010 */
#define RTC_TSTR_ST_1                        (0x2UL << RTC_TSTR_ST_Pos)         /*!< 0x00000020 */
#define RTC_TSTR_ST_2                        (0x4UL << RTC_TSTR_ST_Pos)         /*!< 0x00000040 */
#define RTC_TSTR_SU_Pos                      (0U)                              
#define RTC_TSTR_SU_Msk                      (0xFUL << RTC_TSTR_SU_Pos)         /*!< 0x0000000F */
#define RTC_TSTR_SU                          RTC_TSTR_SU_Msk                   
#define RTC_TSTR_SU_0                        (0x1UL << RTC_TSTR_SU_Pos)         /*!< 0x00000001 */
#define RTC_TSTR_SU_1                        (0x2UL << RTC_TSTR_SU_Pos)         /*!< 0x00000002 */
#define RTC_TSTR_SU_2                        (0x4UL << RTC_TSTR_SU_Pos)         /*!< 0x00000004 */
#define RTC_TSTR_SU_3                        (0x8UL << RTC_TSTR_SU_Pos)         /*!< 0x00000008 */

/********************  Bits definition for RTC_TSDR register  *****************/
#define RTC_TSDR_WDU_Pos                     (13U)                             
#define RTC_TSDR_WDU_Msk                     (0x7UL << RTC_TSDR_WDU_Pos)        /*!< 0x0000E000 */
#define RTC_TSDR_WDU                         RTC_TSDR_WDU_Msk                  
#define RTC_TSDR_WDU_0                       (0x1UL << RTC_TSDR_WDU_Pos)        /*!< 0x00002000 */
#define RTC_TSDR_WDU_1                       (0x2UL << RTC_TSDR_WDU_Pos)        /*!< 0x00004000 */
#define RTC_TSDR_WDU_2                       (0x4UL << RTC_TSDR_WDU_Pos)        /*!< 0x00008000 */
#define RTC_TSDR_MT_Pos                      (12U)                             
#define RTC_TSDR_MT_Msk                      (0x1UL << RTC_TSDR_MT_Pos)         /*!< 0x00001000 */
#define RTC_TSDR_MT                          RTC_TSDR_MT_Msk                   
#define RTC_TSDR_MU_Pos                      (8U)                              
#define RTC_TSDR_MU_Msk                      (0xFUL << RTC_TSDR_MU_Pos)         /*!< 0x00000F00 */
#define RTC_TSDR_MU                          RTC_TSDR_MU_Msk                   
#define RTC_TSDR_MU_0                        (0x1UL << RTC_TSDR_MU_Pos)         /*!< 0x00000100 */
#define RTC_TSDR_MU_1                        (0x2UL << RTC_TSDR_MU_Pos)         /*!< 0x00000200 */
#define RTC_TSDR_MU_2                        (0x4UL << RTC_TSDR_MU_Pos)         /*!< 0x00000400 */
#define RTC_TSDR_MU_3                        (0x8UL << RTC_TSDR_MU_Pos)         /*!< 0x00000800 */
#define RTC_TSDR_DT_Pos                      (4U)                              
#define RTC_TSDR_DT_Msk                      (0x3UL << RTC_TSDR_DT_Pos)         /*!< 0x00000030 */
#define RTC_TSDR_DT                          RTC_TSDR_DT_Msk                   
#define RTC_TSDR_DT_0                        (0x1UL << RTC_TSDR_DT_Pos)         /*!< 0x00000010 */
#define RTC_TSDR_DT_1                        (0x2UL << RTC_TSDR_DT_Pos)         /*!< 0x00000020 */
#define RTC_TSDR_DU_Pos                      (0U)                              
#define RTC_TSDR_DU_Msk                      (0xFUL << RTC_TSDR_DU_Pos)         /*!< 0x0000000F */
#define RTC_TSDR_DU                          RTC_TSDR_DU_Msk                   
#define RTC_TSDR_DU_0                        (0x1UL << RTC_TSDR_DU_Pos)         /*!< 0x00000001 */
#define RTC_TSDR_DU_1                        (0x2UL << RTC_TSDR_DU_Pos)         /*!< 0x00000002 */
#define RTC_TSDR_DU_2                        (0x4UL << RTC_TSDR_DU_Pos)         /*!< 0x00000004 */
#define RTC_TSDR_DU_3                        (0x8UL << RTC_TSDR_DU_Pos)         /*!< 0x00000008 */

/********************  Bits definition for RTC_TSSSR register  ****************/
#define RTC_TSSSR_SS_Pos                     (0U)                              
#define RTC_TSSSR_SS_Msk                     (0xFFFFUL << RTC_TSSSR_SS_Pos)     /*!< 0x0000FFFF */
#define RTC_TSSSR_SS                         RTC_TSSSR_SS_Msk                  

/********************  Bits definition for RTC_CAL register  *****************/
#define RTC_CALR_CALP_Pos                    (15U)                             
#define RTC_CALR_CALP_Msk                    (0x1UL << RTC_CALR_CALP_Pos)       /*!< 0x00008000 */
#define RTC_CALR_CALP                        RTC_CALR_CALP_Msk                 
#define RTC_CALR_CALW8_Pos                   (14U)                             
#define RTC_CALR_CALW8_Msk                   (0x1UL << RTC_CALR_CALW8_Pos)      /*!< 0x00004000 */
#define RTC_CALR_CALW8                       RTC_CALR_CALW8_Msk                
#define RTC_CALR_CALW16_Pos                  (13U)                             
#define RTC_CALR_CALW16_Msk                  (0x1UL << RTC_CALR_CALW16_Pos)     /*!< 0x00002000 */
#define RTC_CALR_CALW16                      RTC_CALR_CALW16_Msk               
#define RTC_CALR_CALM_Pos                    (0U)                              
#define RTC_CALR_CALM_Msk                    (0x1FFUL << RTC_CALR_CALM_Pos)     /*!< 0x000001FF */
#define RTC_CALR_CALM                        RTC_CALR_CALM_Msk                 
#define RTC_CALR_CALM_0                      (0x001UL << RTC_CALR_CALM_Pos)     /*!< 0x00000001 */
#define RTC_CALR_CALM_1                      (0x002UL << RTC_CALR_CALM_Pos)     /*!< 0x00000002 */
#define RTC_CALR_CALM_2                      (0x004UL << RTC_CALR_CALM_Pos)     /*!< 0x00000004 */
#define RTC_CALR_CALM_3                      (0x008UL << RTC_CALR_CALM_Pos)     /*!< 0x00000008 */
#define RTC_CALR_CALM_4                      (0x010UL << RTC_CALR_CALM_Pos)     /*!< 0x00000010 */
#define RTC_CALR_CALM_5                      (0x020UL << RTC_CALR_CALM_Pos)     /*!< 0x00000020 */
#define RTC_CALR_CALM_6                      (0x040UL << RTC_CALR_CALM_Pos)     /*!< 0x00000040 */
#define RTC_CALR_CALM_7                      (0x080UL << RTC_CALR_CALM_Pos)     /*!< 0x00000080 */
#define RTC_CALR_CALM_8                      (0x100UL << RTC_CALR_CALM_Pos)     /*!< 0x00000100 */

/********************  Bits definition for RTC_TAFCR register  ****************/
#define RTC_TAFCR_ALARMOUTTYPE_Pos           (18U)                             
#define RTC_TAFCR_ALARMOUTTYPE_Msk           (0x1UL << RTC_TAFCR_ALARMOUTTYPE_Pos) /*!< 0x00040000 */
#define RTC_TAFCR_ALARMOUTTYPE               RTC_TAFCR_ALARMOUTTYPE_Msk        
#define RTC_TAFCR_TAMPPUDIS_Pos              (15U)                             
#define RTC_TAFCR_TAMPPUDIS_Msk              (0x1UL << RTC_TAFCR_TAMPPUDIS_Pos) /*!< 0x00008000 */
#define RTC_TAFCR_TAMPPUDIS                  RTC_TAFCR_TAMPPUDIS_Msk           
#define RTC_TAFCR_TAMPPRCH_Pos               (13U)                             
#define RTC_TAFCR_TAMPPRCH_Msk               (0x3UL << RTC_TAFCR_TAMPPRCH_Pos)  /*!< 0x00006000 */
#define RTC_TAFCR_TAMPPRCH                   RTC_TAFCR_TAMPPRCH_Msk            
#define RTC_TAFCR_TAMPPRCH_0                 (0x1UL << RTC_TAFCR_TAMPPRCH_Pos)  /*!< 0x00002000 */
#define RTC_TAFCR_TAMPPRCH_1                 (0x2UL << RTC_TAFCR_TAMPPRCH_Pos)  /*!< 0x00004000 */
#define RTC_TAFCR_TAMPFLT_Pos                (11U)                             
#define RTC_TAFCR_TAMPFLT_Msk                (0x3UL << RTC_TAFCR_TAMPFLT_Pos)   /*!< 0x00001800 */
#define RTC_TAFCR_TAMPFLT                    RTC_TAFCR_TAMPFLT_Msk             
#define RTC_TAFCR_TAMPFLT_0                  (0x1UL << RTC_TAFCR_TAMPFLT_Pos)   /*!< 0x00000800 */
#define RTC_TAFCR_TAMPFLT_1                  (0x2UL << RTC_TAFCR_TAMPFLT_Pos)   /*!< 0x00001000 */
#define RTC_TAFCR_TAMPFREQ_Pos               (8U)                              
#define RTC_TAFCR_TAMPFREQ_Msk               (0x7UL << RTC_TAFCR_TAMPFREQ_Pos)  /*!< 0x00000700 */
#define RTC_TAFCR_TAMPFREQ                   RTC_TAFCR_TAMPFREQ_Msk            
#define RTC_TAFCR_TAMPFREQ_0                 (0x1UL << RTC_TAFCR_TAMPFREQ_Pos)  /*!< 0x00000100 */
#define RTC_TAFCR_TAMPFREQ_1                 (0x2UL << RTC_TAFCR_TAMPFREQ_Pos)  /*!< 0x00000200 */
#define RTC_TAFCR_TAMPFREQ_2                 (0x4UL << RTC_TAFCR_TAMPFREQ_Pos)  /*!< 0x00000400 */
#define RTC_TAFCR_TAMPTS_Pos                 (7U)                              
#define RTC_TAFCR_TAMPTS_Msk                 (0x1UL << RTC_TAFCR_TAMPTS_Pos)    /*!< 0x00000080 */
#define RTC_TAFCR_TAMPTS                     RTC_TAFCR_TAMPTS_Msk              
#define RTC_TAFCR_TAMP3TRG_Pos               (6U)                              
#define RTC_TAFCR_TAMP3TRG_Msk               (0x1UL << RTC_TAFCR_TAMP3TRG_Pos)  /*!< 0x00000040 */
#define RTC_TAFCR_TAMP3TRG                   RTC_TAFCR_TAMP3TRG_Msk            
#define RTC_TAFCR_TAMP3E_Pos                 (5U)                              
#define RTC_TAFCR_TAMP3E_Msk                 (0x1UL << RTC_TAFCR_TAMP3E_Pos)    /*!< 0x00000020 */
#define RTC_TAFCR_TAMP3E                     RTC_TAFCR_TAMP3E_Msk              
#define RTC_TAFCR_TAMP2TRG_Pos               (4U)                              
#define RTC_TAFCR_TAMP2TRG_Msk               (0x1UL << RTC_TAFCR_TAMP2TRG_Pos)  /*!< 0x00000010 */
#define RTC_TAFCR_TAMP2TRG                   RTC_TAFCR_TAMP2TRG_Msk            
#define RTC_TAFCR_TAMP2E_Pos                 (3U)                              
#define RTC_TAFCR_TAMP2E_Msk                 (0x1UL << RTC_TAFCR_TAMP2E_Pos)    /*!< 0x00000008 */
#define RTC_TAFCR_TAMP2E                     RTC_TAFCR_TAMP2E_Msk              
#define RTC_TAFCR_TAMPIE_Pos                 (2U)                              
#define RTC_TAFCR_TAMPIE_Msk                 (0x1UL << RTC_TAFCR_TAMPIE_Pos)    /*!< 0x00000004 */
#define RTC_TAFCR_TAMPIE                     RTC_TAFCR_TAMPIE_Msk              
#define RTC_TAFCR_TAMP1TRG_Pos               (1U)                              
#define RTC_TAFCR_TAMP1TRG_Msk               (0x1UL << RTC_TAFCR_TAMP1TRG_Pos)  /*!< 0x00000002 */
#define RTC_TAFCR_TAMP1TRG                   RTC_TAFCR_TAMP1TRG_Msk            
#define RTC_TAFCR_TAMP1E_Pos                 (0U)                              
#define RTC_TAFCR_TAMP1E_Msk                 (0x1UL << RTC_TAFCR_TAMP1E_Pos)    /*!< 0x00000001 */
#define RTC_TAFCR_TAMP1E                     RTC_TAFCR_TAMP1E_Msk              

/********************  Bits definition for RTC_ALRMASSR register  *************/
#define RTC_ALRMASSR_MASKSS_Pos              (24U)                             
#define RTC_ALRMASSR_MASKSS_Msk              (0xFUL << RTC_ALRMASSR_MASKSS_Pos) /*!< 0x0F000000 */
#define RTC_ALRMASSR_MASKSS                  RTC_ALRMASSR_MASKSS_Msk           
#define RTC_ALRMASSR_MASKSS_0                (0x1UL << RTC_ALRMASSR_MASKSS_Pos) /*!< 0x01000000 */
#define RTC_ALRMASSR_MASKSS_1                (0x2UL << RTC_ALRMASSR_MASKSS_Pos) /*!< 0x02000000 */
#define RTC_ALRMASSR_MASKSS_2                (0x4UL << RTC_ALRMASSR_MASKSS_Pos) /*!< 0x04000000 */
#define RTC_ALRMASSR_MASKSS_3                (0x8UL << RTC_ALRMASSR_MASKSS_Pos) /*!< 0x08000000 */
#define RTC_ALRMASSR_SS_Pos                  (0U)                              
#define RTC_ALRMASSR_SS_Msk                  (0x7FFFUL << RTC_ALRMASSR_SS_Pos)  /*!< 0x00007FFF */
#define RTC_ALRMASSR_SS                      RTC_ALRMASSR_SS_Msk               

/********************  Bits definition for RTC_ALRMBSSR register  *************/
#define RTC_ALRMBSSR_MASKSS_Pos              (24U)                             
#define RTC_ALRMBSSR_MASKSS_Msk              (0xFUL << RTC_ALRMBSSR_MASKSS_Pos) /*!< 0x0F000000 */
#define RTC_ALRMBSSR_MASKSS                  RTC_ALRMBSSR_MASKSS_Msk           
#define RTC_ALRMBSSR_MASKSS_0                (0x1UL << RTC_ALRMBSSR_MASKSS_Pos) /*!< 0x01000000 */
#define RTC_ALRMBSSR_MASKSS_1                (0x2UL << RTC_ALRMBSSR_MASKSS_Pos) /*!< 0x02000000 */
#define RTC_ALRMBSSR_MASKSS_2                (0x4UL << RTC_ALRMBSSR_MASKSS_Pos) /*!< 0x04000000 */
#define RTC_ALRMBSSR_MASKSS_3                (0x8UL << RTC_ALRMBSSR_MASKSS_Pos) /*!< 0x08000000 */
#define RTC_ALRMBSSR_SS_Pos                  (0U)                              
#define RTC_ALRMBSSR_SS_Msk                  (0x7FFFUL << RTC_ALRMBSSR_SS_Pos)  /*!< 0x00007FFF */
#define RTC_ALRMBSSR_SS                      RTC_ALRMBSSR_SS_Msk               

/********************  Bits definition for RTC_BKP0R register  ****************/
#define RTC_BKP0R_Pos                        (0U)                              
#define RTC_BKP0R_Msk                        (0xFFFFFFFFUL << RTC_BKP0R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP0R                            RTC_BKP0R_Msk                     

/********************  Bits definition for RTC_BKP1R register  ****************/
#define RTC_BKP1R_Pos                        (0U)                              
#define RTC_BKP1R_Msk                        (0xFFFFFFFFUL << RTC_BKP1R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP1R                            RTC_BKP1R_Msk                     

/********************  Bits definition for RTC_BKP2R register  ****************/
#define RTC_BKP2R_Pos                        (0U)                              
#define RTC_BKP2R_Msk                        (0xFFFFFFFFUL << RTC_BKP2R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP2R                            RTC_BKP2R_Msk                     

/********************  Bits definition for RTC_BKP3R register  ****************/
#define RTC_BKP3R_Pos                        (0U)                              
#define RTC_BKP3R_Msk                        (0xFFFFFFFFUL << RTC_BKP3R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP3R                            RTC_BKP3R_Msk                     

/********************  Bits definition for RTC_BKP4R register  ****************/
#define RTC_BKP4R_Pos                        (0U)                              
#define RTC_BKP4R_Msk                        (0xFFFFFFFFUL << RTC_BKP4R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP4R                            RTC_BKP4R_Msk                     

/********************  Bits definition for RTC_BKP5R register  ****************/
#define RTC_BKP5R_Pos                        (0U)                              
#define RTC_BKP5R_Msk                        (0xFFFFFFFFUL << RTC_BKP5R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP5R                            RTC_BKP5R_Msk                     

/********************  Bits definition for RTC_BKP6R register  ****************/
#define RTC_BKP6R_Pos                        (0U)                              
#define RTC_BKP6R_Msk                        (0xFFFFFFFFUL << RTC_BKP6R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP6R                            RTC_BKP6R_Msk                     

/********************  Bits definition for RTC_BKP7R register  ****************/
#define RTC_BKP7R_Pos                        (0U)                              
#define RTC_BKP7R_Msk                        (0xFFFFFFFFUL << RTC_BKP7R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP7R                            RTC_BKP7R_Msk                     

/********************  Bits definition for RTC_BKP8R register  ****************/
#define RTC_BKP8R_Pos                        (0U)                              
#define RTC_BKP8R_Msk                        (0xFFFFFFFFUL << RTC_BKP8R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP8R                            RTC_BKP8R_Msk                     

/********************  Bits definition for RTC_BKP9R register  ****************/
#define RTC_BKP9R_Pos                        (0U)                              
#define RTC_BKP9R_Msk                        (0xFFFFFFFFUL << RTC_BKP9R_Pos)    /*!< 0xFFFFFFFF */
#define RTC_BKP9R                            RTC_BKP9R_Msk                     

/********************  Bits definition for RTC_BKP10R register  ***************/
#define RTC_BKP10R_Pos                       (0U)                              
#define RTC_BKP10R_Msk                       (0xFFFFFFFFUL << RTC_BKP10R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP10R                           RTC_BKP10R_Msk                    

/********************  Bits definition for RTC_BKP11R register  ***************/
#define RTC_BKP11R_Pos                       (0U)                              
#define RTC_BKP11R_Msk                       (0xFFFFFFFFUL << RTC_BKP11R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP11R                           RTC_BKP11R_Msk                    

/********************  Bits definition for RTC_BKP12R register  ***************/
#define RTC_BKP12R_Pos                       (0U)                              
#define RTC_BKP12R_Msk                       (0xFFFFFFFFUL << RTC_BKP12R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP12R                           RTC_BKP12R_Msk                    

/********************  Bits definition for RTC_BKP13R register  ***************/
#define RTC_BKP13R_Pos                       (0U)                              
#define RTC_BKP13R_Msk                       (0xFFFFFFFFUL << RTC_BKP13R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP13R                           RTC_BKP13R_Msk                    

/********************  Bits definition for RTC_BKP14R register  ***************/
#define RTC_BKP14R_Pos                       (0U)                              
#define RTC_BKP14R_Msk                       (0xFFFFFFFFUL << RTC_BKP14R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP14R                           RTC_BKP14R_Msk                    

/********************  Bits definition for RTC_BKP15R register  ***************/
#define RTC_BKP15R_Pos                       (0U)                              
#define RTC_BKP15R_Msk                       (0xFFFFFFFFUL << RTC_BKP15R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP15R                           RTC_BKP15R_Msk                    

/********************  Bits definition for RTC_BKP16R register  ***************/
#define RTC_BKP16R_Pos                       (0U)                              
#define RTC_BKP16R_Msk                       (0xFFFFFFFFUL << RTC_BKP16R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP16R                           RTC_BKP16R_Msk                    

/********************  Bits definition for RTC_BKP17R register  ***************/
#define RTC_BKP17R_Pos                       (0U)                              
#define RTC_BKP17R_Msk                       (0xFFFFFFFFUL << RTC_BKP17R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP17R                           RTC_BKP17R_Msk                    

/********************  Bits definition for RTC_BKP18R register  ***************/
#define RTC_BKP18R_Pos                       (0U)                              
#define RTC_BKP18R_Msk                       (0xFFFFFFFFUL << RTC_BKP18R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP18R                           RTC_BKP18R_Msk                    

/********************  Bits definition for RTC_BKP19R register  ***************/
#define RTC_BKP19R_Pos                       (0U)                              
#define RTC_BKP19R_Msk                       (0xFFFFFFFFUL << RTC_BKP19R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP19R                           RTC_BKP19R_Msk                    

/********************  Bits definition for RTC_BKP20R register  ***************/
#define RTC_BKP20R_Pos                       (0U)                              
#define RTC_BKP20R_Msk                       (0xFFFFFFFFUL << RTC_BKP20R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP20R                           RTC_BKP20R_Msk                    

/********************  Bits definition for RTC_BKP21R register  ***************/
#define RTC_BKP21R_Pos                       (0U)                              
#define RTC_BKP21R_Msk                       (0xFFFFFFFFUL << RTC_BKP21R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP21R                           RTC_BKP21R_Msk                    

/********************  Bits definition for RTC_BKP22R register  ***************/
#define RTC_BKP22R_Pos                       (0U)                              
#define RTC_BKP22R_Msk                       (0xFFFFFFFFUL << RTC_BKP22R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP22R                           RTC_BKP22R_Msk                    

/********************  Bits definition for RTC_BKP23R register  ***************/
#define RTC_BKP23R_Pos                       (0U)                              
#define RTC_BKP23R_Msk                       (0xFFFFFFFFUL << RTC_BKP23R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP23R                           RTC_BKP23R_Msk                    

/********************  Bits definition for RTC_BKP24R register  ***************/
#define RTC_BKP24R_Pos                       (0U)                              
#define RTC_BKP24R_Msk                       (0xFFFFFFFFUL << RTC_BKP24R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP24R                           RTC_BKP24R_Msk                    

/********************  Bits definition for RTC_BKP25R register  ***************/
#define RTC_BKP25R_Pos                       (0U)                              
#define RTC_BKP25R_Msk                       (0xFFFFFFFFUL << RTC_BKP25R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP25R                           RTC_BKP25R_Msk                    

/********************  Bits definition for RTC_BKP26R register  ***************/
#define RTC_BKP26R_Pos                       (0U)                              
#define RTC_BKP26R_Msk                       (0xFFFFFFFFUL << RTC_BKP26R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP26R                           RTC_BKP26R_Msk                    

/********************  Bits definition for RTC_BKP27R register  ***************/
#define RTC_BKP27R_Pos                       (0U)                              
#define RTC_BKP27R_Msk                       (0xFFFFFFFFUL << RTC_BKP27R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP27R                           RTC_BKP27R_Msk                    

/********************  Bits definition for RTC_BKP28R register  ***************/
#define RTC_BKP28R_Pos                       (0U)                              
#define RTC_BKP28R_Msk                       (0xFFFFFFFFUL << RTC_BKP28R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP28R                           RTC_BKP28R_Msk                    

/********************  Bits definition for RTC_BKP29R register  ***************/
#define RTC_BKP29R_Pos                       (0U)                              
#define RTC_BKP29R_Msk                       (0xFFFFFFFFUL << RTC_BKP29R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP29R                           RTC_BKP29R_Msk                    

/********************  Bits definition for RTC_BKP30R register  ***************/
#define RTC_BKP30R_Pos                       (0U)                              
#define RTC_BKP30R_Msk                       (0xFFFFFFFFUL << RTC_BKP30R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP30R                           RTC_BKP30R_Msk                    

/********************  Bits definition for RTC_BKP31R register  ***************/
#define RTC_BKP31R_Pos                       (0U)                              
#define RTC_BKP31R_Msk                       (0xFFFFFFFFUL << RTC_BKP31R_Pos)   /*!< 0xFFFFFFFF */
#define RTC_BKP31R                           RTC_BKP31R_Msk                    

/******************** Number of backup registers ******************************/
#define RTC_BKP_NUMBER 32

/******************************************************************************/
/*                                                                            */
/*                     Serial Peripheral Interface (SPI)                      */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F3 serie)
 */
#define SPI_I2S_SUPPORT    

/*******************  Bit definition for SPI_CR1 register  ********************/
#define SPI_CR1_CPHA_Pos                    (0U)                               
#define SPI_CR1_CPHA_Msk                    (0x1UL << SPI_CR1_CPHA_Pos)         /*!< 0x00000001 */
#define SPI_CR1_CPHA                        SPI_CR1_CPHA_Msk                   /*!< Clock Phase */
#define SPI_CR1_CPOL_Pos                    (1U)                               
#define SPI_CR1_CPOL_Msk                    (0x1UL << SPI_CR1_CPOL_Pos)         /*!< 0x00000002 */
#define SPI_CR1_CPOL                        SPI_CR1_CPOL_Msk                   /*!< Clock Polarity */
#define SPI_CR1_MSTR_Pos                    (2U)                               
#define SPI_CR1_MSTR_Msk                    (0x1UL << SPI_CR1_MSTR_Pos)         /*!< 0x00000004 */
#define SPI_CR1_MSTR                        SPI_CR1_MSTR_Msk                   /*!< Master Selection */

#define SPI_CR1_BR_Pos                      (3U)                               
#define SPI_CR1_BR_Msk                      (0x7UL << SPI_CR1_BR_Pos)           /*!< 0x00000038 */
#define SPI_CR1_BR                          SPI_CR1_BR_Msk                     /*!< BR[2:0] bits (Baud Rate Control) */
#define SPI_CR1_BR_0                        (0x1UL << SPI_CR1_BR_Pos)           /*!< 0x00000008 */
#define SPI_CR1_BR_1                        (0x2UL << SPI_CR1_BR_Pos)           /*!< 0x00000010 */
#define SPI_CR1_BR_2                        (0x4UL << SPI_CR1_BR_Pos)           /*!< 0x00000020 */

#define SPI_CR1_SPE_Pos                     (6U)                               
#define SPI_CR1_SPE_Msk                     (0x1UL << SPI_CR1_SPE_Pos)          /*!< 0x00000040 */
#define SPI_CR1_SPE                         SPI_CR1_SPE_Msk                    /*!< SPI Enable */
#define SPI_CR1_LSBFIRST_Pos                (7U)                               
#define SPI_CR1_LSBFIRST_Msk                (0x1UL << SPI_CR1_LSBFIRST_Pos)     /*!< 0x00000080 */
#define SPI_CR1_LSBFIRST                    SPI_CR1_LSBFIRST_Msk               /*!< Frame Format */
#define SPI_CR1_SSI_Pos                     (8U)                               
#define SPI_CR1_SSI_Msk                     (0x1UL << SPI_CR1_SSI_Pos)          /*!< 0x00000100 */
#define SPI_CR1_SSI                         SPI_CR1_SSI_Msk                    /*!< Internal slave select */
#define SPI_CR1_SSM_Pos                     (9U)                               
#define SPI_CR1_SSM_Msk                     (0x1UL << SPI_CR1_SSM_Pos)          /*!< 0x00000200 */
#define SPI_CR1_SSM                         SPI_CR1_SSM_Msk                    /*!< Software slave management */
#define SPI_CR1_RXONLY_Pos                  (10U)                              
#define SPI_CR1_RXONLY_Msk                  (0x1UL << SPI_CR1_RXONLY_Pos)       /*!< 0x00000400 */
#define SPI_CR1_RXONLY                      SPI_CR1_RXONLY_Msk                 /*!< Receive only */
#define SPI_CR1_DFF_Pos                     (11U)                              
#define SPI_CR1_DFF_Msk                     (0x1UL << SPI_CR1_DFF_Pos)          /*!< 0x00000800 */
#define SPI_CR1_DFF                         SPI_CR1_DFF_Msk                    /*!< Data Frame Format */
#define SPI_CR1_CRCNEXT_Pos                 (12U)                              
#define SPI_CR1_CRCNEXT_Msk                 (0x1UL << SPI_CR1_CRCNEXT_Pos)      /*!< 0x00001000 */
#define SPI_CR1_CRCNEXT                     SPI_CR1_CRCNEXT_Msk                /*!< Transmit CRC next */
#define SPI_CR1_CRCEN_Pos                   (13U)                              
#define SPI_CR1_CRCEN_Msk                   (0x1UL << SPI_CR1_CRCEN_Pos)        /*!< 0x00002000 */
#define SPI_CR1_CRCEN                       SPI_CR1_CRCEN_Msk                  /*!< Hardware CRC calculation enable */
#define SPI_CR1_BIDIOE_Pos                  (14U)                              
#define SPI_CR1_BIDIOE_Msk                  (0x1UL << SPI_CR1_BIDIOE_Pos)       /*!< 0x00004000 */
#define SPI_CR1_BIDIOE                      SPI_CR1_BIDIOE_Msk                 /*!< Output enable in bidirectional mode */
#define SPI_CR1_BIDIMODE_Pos                (15U)                              
#define SPI_CR1_BIDIMODE_Msk                (0x1UL << SPI_CR1_BIDIMODE_Pos)     /*!< 0x00008000 */
#define SPI_CR1_BIDIMODE                    SPI_CR1_BIDIMODE_Msk               /*!< Bidirectional data mode enable */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define SPI_CR2_RXDMAEN_Pos                 (0U)                               
#define SPI_CR2_RXDMAEN_Msk                 (0x1UL << SPI_CR2_RXDMAEN_Pos)      /*!< 0x00000001 */
#define SPI_CR2_RXDMAEN                     SPI_CR2_RXDMAEN_Msk                /*!< Rx Buffer DMA Enable */
#define SPI_CR2_TXDMAEN_Pos                 (1U)                               
#define SPI_CR2_TXDMAEN_Msk                 (0x1UL << SPI_CR2_TXDMAEN_Pos)      /*!< 0x00000002 */
#define SPI_CR2_TXDMAEN                     SPI_CR2_TXDMAEN_Msk                /*!< Tx Buffer DMA Enable */
#define SPI_CR2_SSOE_Pos                    (2U)                               
#define SPI_CR2_SSOE_Msk                    (0x1UL << SPI_CR2_SSOE_Pos)         /*!< 0x00000004 */
#define SPI_CR2_SSOE                        SPI_CR2_SSOE_Msk                   /*!< SS Output Enable */
#define SPI_CR2_FRF_Pos                     (4U)                               
#define SPI_CR2_FRF_Msk                     (0x1UL << SPI_CR2_FRF_Pos)          /*!< 0x00000010 */
#define SPI_CR2_FRF                         SPI_CR2_FRF_Msk                    /*!< Frame format */
#define SPI_CR2_ERRIE_Pos                   (5U)                               
#define SPI_CR2_ERRIE_Msk                   (0x1UL << SPI_CR2_ERRIE_Pos)        /*!< 0x00000020 */
#define SPI_CR2_ERRIE                       SPI_CR2_ERRIE_Msk                  /*!< Error Interrupt Enable */
#define SPI_CR2_RXNEIE_Pos                  (6U)                               
#define SPI_CR2_RXNEIE_Msk                  (0x1UL << SPI_CR2_RXNEIE_Pos)       /*!< 0x00000040 */
#define SPI_CR2_RXNEIE                      SPI_CR2_RXNEIE_Msk                 /*!< RX buffer Not Empty Interrupt Enable */
#define SPI_CR2_TXEIE_Pos                   (7U)                               
#define SPI_CR2_TXEIE_Msk                   (0x1UL << SPI_CR2_TXEIE_Pos)        /*!< 0x00000080 */
#define SPI_CR2_TXEIE                       SPI_CR2_TXEIE_Msk                  /*!< Tx buffer Empty Interrupt Enable */

/********************  Bit definition for SPI_SR register  ********************/
#define SPI_SR_RXNE_Pos                     (0U)                               
#define SPI_SR_RXNE_Msk                     (0x1UL << SPI_SR_RXNE_Pos)          /*!< 0x00000001 */
#define SPI_SR_RXNE                         SPI_SR_RXNE_Msk                    /*!< Receive buffer Not Empty */
#define SPI_SR_TXE_Pos                      (1U)                               
#define SPI_SR_TXE_Msk                      (0x1UL << SPI_SR_TXE_Pos)           /*!< 0x00000002 */
#define SPI_SR_TXE                          SPI_SR_TXE_Msk                     /*!< Transmit buffer Empty */
#define SPI_SR_CHSIDE_Pos                   (2U)                               
#define SPI_SR_CHSIDE_Msk                   (0x1UL << SPI_SR_CHSIDE_Pos)        /*!< 0x00000004 */
#define SPI_SR_CHSIDE                       SPI_SR_CHSIDE_Msk                  /*!< Channel side */
#define SPI_SR_UDR_Pos                      (3U)                               
#define SPI_SR_UDR_Msk                      (0x1UL << SPI_SR_UDR_Pos)           /*!< 0x00000008 */
#define SPI_SR_UDR                          SPI_SR_UDR_Msk                     /*!< Underrun flag */
#define SPI_SR_CRCERR_Pos                   (4U)                               
#define SPI_SR_CRCERR_Msk                   (0x1UL << SPI_SR_CRCERR_Pos)        /*!< 0x00000010 */
#define SPI_SR_CRCERR                       SPI_SR_CRCERR_Msk                  /*!< CRC Error flag */
#define SPI_SR_MODF_Pos                     (5U)                               
#define SPI_SR_MODF_Msk                     (0x1UL << SPI_SR_MODF_Pos)          /*!< 0x00000020 */
#define SPI_SR_MODF                         SPI_SR_MODF_Msk                    /*!< Mode fault */
#define SPI_SR_OVR_Pos                      (6U)                               
#define SPI_SR_OVR_Msk                      (0x1UL << SPI_SR_OVR_Pos)           /*!< 0x00000040 */
#define SPI_SR_OVR                          SPI_SR_OVR_Msk                     /*!< Overrun flag */
#define SPI_SR_BSY_Pos                      (7U)                               
#define SPI_SR_BSY_Msk                      (0x1UL << SPI_SR_BSY_Pos)           /*!< 0x00000080 */
#define SPI_SR_BSY                          SPI_SR_BSY_Msk                     /*!< Busy flag */
#define SPI_SR_FRE_Pos                      (8U)                               
#define SPI_SR_FRE_Msk                      (0x1UL << SPI_SR_FRE_Pos)           /*!< 0x00000100 */
#define SPI_SR_FRE                          SPI_SR_FRE_Msk                     /*!<Frame format error flag  */

/********************  Bit definition for SPI_DR register  ********************/
#define SPI_DR_DR_Pos                       (0U)                               
#define SPI_DR_DR_Msk                       (0xFFFFUL << SPI_DR_DR_Pos)         /*!< 0x0000FFFF */
#define SPI_DR_DR                           SPI_DR_DR_Msk                      /*!< Data Register */

/*******************  Bit definition for SPI_CRCPR register  ******************/
#define SPI_CRCPR_CRCPOLY_Pos               (0U)                               
#define SPI_CRCPR_CRCPOLY_Msk               (0xFFFFUL << SPI_CRCPR_CRCPOLY_Pos) /*!< 0x0000FFFF */
#define SPI_CRCPR_CRCPOLY                   SPI_CRCPR_CRCPOLY_Msk              /*!< CRC polynomial register */

/******************  Bit definition for SPI_RXCRCR register  ******************/
#define SPI_RXCRCR_RXCRC_Pos                (0U)                               
#define SPI_RXCRCR_RXCRC_Msk                (0xFFFFUL << SPI_RXCRCR_RXCRC_Pos)  /*!< 0x0000FFFF */
#define SPI_RXCRCR_RXCRC                    SPI_RXCRCR_RXCRC_Msk               /*!< Rx CRC Register */

/******************  Bit definition for SPI_TXCRCR register  ******************/
#define SPI_TXCRCR_TXCRC_Pos                (0U)                               
#define SPI_TXCRCR_TXCRC_Msk                (0xFFFFUL << SPI_TXCRCR_TXCRC_Pos)  /*!< 0x0000FFFF */
#define SPI_TXCRCR_TXCRC                    SPI_TXCRCR_TXCRC_Msk               /*!< Tx CRC Register */

/******************  Bit definition for SPI_I2SCFGR register  *****************/
#define SPI_I2SCFGR_CHLEN_Pos               (0U)                               
#define SPI_I2SCFGR_CHLEN_Msk               (0x1UL << SPI_I2SCFGR_CHLEN_Pos)    /*!< 0x00000001 */
#define SPI_I2SCFGR_CHLEN                   SPI_I2SCFGR_CHLEN_Msk              /*!<Channel length (number of bits per audio channel) */

#define SPI_I2SCFGR_DATLEN_Pos              (1U)                               
#define SPI_I2SCFGR_DATLEN_Msk              (0x3UL << SPI_I2SCFGR_DATLEN_Pos)   /*!< 0x00000006 */
#define SPI_I2SCFGR_DATLEN                  SPI_I2SCFGR_DATLEN_Msk             /*!<DATLEN[1:0] bits (Data length to be transferred) */
#define SPI_I2SCFGR_DATLEN_0                (0x1UL << SPI_I2SCFGR_DATLEN_Pos)   /*!< 0x00000002 */
#define SPI_I2SCFGR_DATLEN_1                (0x2UL << SPI_I2SCFGR_DATLEN_Pos)   /*!< 0x00000004 */

#define SPI_I2SCFGR_CKPOL_Pos               (3U)                               
#define SPI_I2SCFGR_CKPOL_Msk               (0x1UL << SPI_I2SCFGR_CKPOL_Pos)    /*!< 0x00000008 */
#define SPI_I2SCFGR_CKPOL                   SPI_I2SCFGR_CKPOL_Msk              /*!<steady state clock polarity */

#define SPI_I2SCFGR_I2SSTD_Pos              (4U)                               
#define SPI_I2SCFGR_I2SSTD_Msk              (0x3UL << SPI_I2SCFGR_I2SSTD_Pos)   /*!< 0x00000030 */
#define SPI_I2SCFGR_I2SSTD                  SPI_I2SCFGR_I2SSTD_Msk             /*!<I2SSTD[1:0] bits (I2S standard selection) */
#define SPI_I2SCFGR_I2SSTD_0                (0x1UL << SPI_I2SCFGR_I2SSTD_Pos)   /*!< 0x00000010 */
#define SPI_I2SCFGR_I2SSTD_1                (0x2UL << SPI_I2SCFGR_I2SSTD_Pos)   /*!< 0x00000020 */

#define SPI_I2SCFGR_PCMSYNC_Pos             (7U)                               
#define SPI_I2SCFGR_PCMSYNC_Msk             (0x1UL << SPI_I2SCFGR_PCMSYNC_Pos)  /*!< 0x00000080 */
#define SPI_I2SCFGR_PCMSYNC                 SPI_I2SCFGR_PCMSYNC_Msk            /*!<PCM frame synchronization */

#define SPI_I2SCFGR_I2SCFG_Pos              (8U)                               
#define SPI_I2SCFGR_I2SCFG_Msk              (0x3UL << SPI_I2SCFGR_I2SCFG_Pos)   /*!< 0x00000300 */
#define SPI_I2SCFGR_I2SCFG                  SPI_I2SCFGR_I2SCFG_Msk             /*!<I2SCFG[1:0] bits (I2S configuration mode) */
#define SPI_I2SCFGR_I2SCFG_0                (0x1UL << SPI_I2SCFGR_I2SCFG_Pos)   /*!< 0x00000100 */
#define SPI_I2SCFGR_I2SCFG_1                (0x2UL << SPI_I2SCFGR_I2SCFG_Pos)   /*!< 0x00000200 */

#define SPI_I2SCFGR_I2SE_Pos                (10U)                              
#define SPI_I2SCFGR_I2SE_Msk                (0x1UL << SPI_I2SCFGR_I2SE_Pos)     /*!< 0x00000400 */
#define SPI_I2SCFGR_I2SE                    SPI_I2SCFGR_I2SE_Msk               /*!<I2S Enable */
#define SPI_I2SCFGR_I2SMOD_Pos              (11U)                              
#define SPI_I2SCFGR_I2SMOD_Msk              (0x1UL << SPI_I2SCFGR_I2SMOD_Pos)   /*!< 0x00000800 */
#define SPI_I2SCFGR_I2SMOD                  SPI_I2SCFGR_I2SMOD_Msk             /*!<I2S mode selection */

/******************  Bit definition for SPI_I2SPR register  *******************/
#define SPI_I2SPR_I2SDIV_Pos                (0U)                               
#define SPI_I2SPR_I2SDIV_Msk                (0xFFUL << SPI_I2SPR_I2SDIV_Pos)    /*!< 0x000000FF */
#define SPI_I2SPR_I2SDIV                    SPI_I2SPR_I2SDIV_Msk               /*!<I2S Linear prescaler */
#define SPI_I2SPR_ODD_Pos                   (8U)                               
#define SPI_I2SPR_ODD_Msk                   (0x1UL << SPI_I2SPR_ODD_Pos)        /*!< 0x00000100 */
#define SPI_I2SPR_ODD                       SPI_I2SPR_ODD_Msk                  /*!<Odd factor for the prescaler */
#define SPI_I2SPR_MCKOE_Pos                 (9U)                               
#define SPI_I2SPR_MCKOE_Msk                 (0x1UL << SPI_I2SPR_MCKOE_Pos)      /*!< 0x00000200 */
#define SPI_I2SPR_MCKOE                     SPI_I2SPR_MCKOE_Msk                /*!<Master Clock Output Enable */

/******************************************************************************/
/*                                                                            */
/*                       System Configuration (SYSCFG)                        */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for SYSCFG_MEMRMP register  ****************/
#define SYSCFG_MEMRMP_MEM_MODE_Pos      (0U)                                   
#define SYSCFG_MEMRMP_MEM_MODE_Msk      (0x3UL << SYSCFG_MEMRMP_MEM_MODE_Pos)   /*!< 0x00000003 */
#define SYSCFG_MEMRMP_MEM_MODE          SYSCFG_MEMRMP_MEM_MODE_Msk             /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_MEMRMP_MEM_MODE_0        (0x1UL << SYSCFG_MEMRMP_MEM_MODE_Pos)   /*!< 0x00000001 */
#define SYSCFG_MEMRMP_MEM_MODE_1        (0x2UL << SYSCFG_MEMRMP_MEM_MODE_Pos)   /*!< 0x00000002 */
#define SYSCFG_MEMRMP_BOOT_MODE_Pos     (8U)                                   
#define SYSCFG_MEMRMP_BOOT_MODE_Msk     (0x3UL << SYSCFG_MEMRMP_BOOT_MODE_Pos)  /*!< 0x00000300 */
#define SYSCFG_MEMRMP_BOOT_MODE         SYSCFG_MEMRMP_BOOT_MODE_Msk            /*!< Boot mode Config */
#define SYSCFG_MEMRMP_BOOT_MODE_0       (0x1UL << SYSCFG_MEMRMP_BOOT_MODE_Pos)  /*!< 0x00000100 */
#define SYSCFG_MEMRMP_BOOT_MODE_1       (0x2UL << SYSCFG_MEMRMP_BOOT_MODE_Pos)  /*!< 0x00000200 */

/*****************  Bit definition for SYSCFG_PMC register  *******************/
#define SYSCFG_PMC_USB_PU_Pos           (0U)                                   
#define SYSCFG_PMC_USB_PU_Msk           (0x1UL << SYSCFG_PMC_USB_PU_Pos)        /*!< 0x00000001 */
#define SYSCFG_PMC_USB_PU               SYSCFG_PMC_USB_PU_Msk                  /*!< SYSCFG PMC */
#define SYSCFG_PMC_LCD_CAPA_Pos         (1U)                                   
#define SYSCFG_PMC_LCD_CAPA_Msk         (0x1FUL << SYSCFG_PMC_LCD_CAPA_Pos)     /*!< 0x0000003E */
#define SYSCFG_PMC_LCD_CAPA             SYSCFG_PMC_LCD_CAPA_Msk                /*!< LCD_CAPA decoupling capacitance connection */
#define SYSCFG_PMC_LCD_CAPA_0           (0x01UL << SYSCFG_PMC_LCD_CAPA_Pos)     /*!< 0x00000002 */
#define SYSCFG_PMC_LCD_CAPA_1           (0x02UL << SYSCFG_PMC_LCD_CAPA_Pos)     /*!< 0x00000004 */
#define SYSCFG_PMC_LCD_CAPA_2           (0x04UL << SYSCFG_PMC_LCD_CAPA_Pos)     /*!< 0x00000008 */
#define SYSCFG_PMC_LCD_CAPA_3           (0x08UL << SYSCFG_PMC_LCD_CAPA_Pos)     /*!< 0x00000010 */
#define SYSCFG_PMC_LCD_CAPA_4           (0x10UL << SYSCFG_PMC_LCD_CAPA_Pos)     /*!< 0x00000020 */

/*****************  Bit definition for SYSCFG_EXTICR1 register  ***************/
#define SYSCFG_EXTICR1_EXTI0_Pos        (0U)                                   
#define SYSCFG_EXTICR1_EXTI0_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI0_Pos)     /*!< 0x0000000F */
#define SYSCFG_EXTICR1_EXTI0            SYSCFG_EXTICR1_EXTI0_Msk               /*!< EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1_Pos        (4U)                                   
#define SYSCFG_EXTICR1_EXTI1_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI1_Pos)     /*!< 0x000000F0 */
#define SYSCFG_EXTICR1_EXTI1            SYSCFG_EXTICR1_EXTI1_Msk               /*!< EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2_Pos        (8U)                                   
#define SYSCFG_EXTICR1_EXTI2_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI2_Pos)     /*!< 0x00000F00 */
#define SYSCFG_EXTICR1_EXTI2            SYSCFG_EXTICR1_EXTI2_Msk               /*!< EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3_Pos        (12U)                                  
#define SYSCFG_EXTICR1_EXTI3_Msk        (0xFUL << SYSCFG_EXTICR1_EXTI3_Pos)     /*!< 0x0000F000 */
#define SYSCFG_EXTICR1_EXTI3            SYSCFG_EXTICR1_EXTI3_Msk               /*!< EXTI 3 configuration */

/** 
  * @brief  EXTI0 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI0_PA         (0x00000000U)                          /*!< PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB         (0x00000001U)                          /*!< PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC         (0x00000002U)                          /*!< PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD         (0x00000003U)                          /*!< PD[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PE         (0x00000004U)                          /*!< PE[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PH         (0x00000005U)                          /*!< PH[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PF         (0x00000006U)                          /*!< PF[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PG         (0x00000007U)                          /*!< PG[0] pin */

/** 
  * @brief  EXTI1 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI1_PA         (0x00000000U)                          /*!< PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB         (0x00000010U)                          /*!< PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC         (0x00000020U)                          /*!< PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD         (0x00000030U)                          /*!< PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE         (0x00000040U)                          /*!< PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PH         (0x00000050U)                          /*!< PH[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF         (0x00000060U)                          /*!< PF[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PG         (0x00000070U)                          /*!< PG[1] pin */

/** 
  * @brief  EXTI2 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI2_PA         (0x00000000U)                          /*!< PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB         (0x00000100U)                          /*!< PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC         (0x00000200U)                          /*!< PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD         (0x00000300U)                          /*!< PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE         (0x00000400U)                          /*!< PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PH         (0x00000500U)                          /*!< PH[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF         (0x00000600U)                          /*!< PF[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PG         (0x00000700U)                          /*!< PG[2] pin */

/** 
  * @brief  EXTI3 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI3_PA         (0x00000000U)                          /*!< PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB         (0x00001000U)                          /*!< PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC         (0x00002000U)                          /*!< PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD         (0x00003000U)                          /*!< PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE         (0x00004000U)                          /*!< PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PF         (0x00006000U)                          /*!< PF[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PG         (0x00007000U)                          /*!< PG[3] pin */

/*****************  Bit definition for SYSCFG_EXTICR2 register  *****************/
#define SYSCFG_EXTICR2_EXTI4_Pos        (0U)                                   
#define SYSCFG_EXTICR2_EXTI4_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI4_Pos)     /*!< 0x0000000F */
#define SYSCFG_EXTICR2_EXTI4            SYSCFG_EXTICR2_EXTI4_Msk               /*!< EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5_Pos        (4U)                                   
#define SYSCFG_EXTICR2_EXTI5_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI5_Pos)     /*!< 0x000000F0 */
#define SYSCFG_EXTICR2_EXTI5            SYSCFG_EXTICR2_EXTI5_Msk               /*!< EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6_Pos        (8U)                                   
#define SYSCFG_EXTICR2_EXTI6_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI6_Pos)     /*!< 0x00000F00 */
#define SYSCFG_EXTICR2_EXTI6            SYSCFG_EXTICR2_EXTI6_Msk               /*!< EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7_Pos        (12U)                                  
#define SYSCFG_EXTICR2_EXTI7_Msk        (0xFUL << SYSCFG_EXTICR2_EXTI7_Pos)     /*!< 0x0000F000 */
#define SYSCFG_EXTICR2_EXTI7            SYSCFG_EXTICR2_EXTI7_Msk               /*!< EXTI 7 configuration */

/** 
  * @brief  EXTI4 configuration  
  */ 
#define SYSCFG_EXTICR2_EXTI4_PA         (0x00000000U)                          /*!< PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB         (0x00000001U)                          /*!< PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC         (0x00000002U)                          /*!< PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD         (0x00000003U)                          /*!< PD[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PE         (0x00000004U)                          /*!< PE[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PF         (0x00000006U)                          /*!< PF[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PG         (0x00000007U)                          /*!< PG[4] pin */

/** 
  * @brief  EXTI5 configuration  
  */ 
#define SYSCFG_EXTICR2_EXTI5_PA         (0x00000000U)                          /*!< PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB         (0x00000010U)                          /*!< PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC         (0x00000020U)                          /*!< PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD         (0x00000030U)                          /*!< PD[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PE         (0x00000040U)                          /*!< PE[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PF         (0x00000060U)                          /*!< PF[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PG         (0x00000070U)                          /*!< PG[5] pin */

/** 
  * @brief  EXTI6 configuration  
  */ 
#define SYSCFG_EXTICR2_EXTI6_PA         (0x00000000U)                          /*!< PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB         (0x00000100U)                          /*!< PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC         (0x00000200U)                          /*!< PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD         (0x00000300U)                          /*!< PD[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PE         (0x00000400U)                          /*!< PE[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PF         (0x00000600U)                          /*!< PF[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PG         (0x00000700U)                          /*!< PG[6] pin */

/** 
  * @brief  EXTI7 configuration  
  */ 
#define SYSCFG_EXTICR2_EXTI7_PA         (0x00000000U)                          /*!< PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB         (0x00001000U)                          /*!< PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC         (0x00002000U)                          /*!< PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD         (0x00003000U)                          /*!< PD[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PE         (0x00004000U)                          /*!< PE[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PF         (0x00006000U)                          /*!< PF[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PG         (0x00007000U)                          /*!< PG[7] pin */

/*****************  Bit definition for SYSCFG_EXTICR3 register  *****************/
#define SYSCFG_EXTICR3_EXTI8_Pos        (0U)                                   
#define SYSCFG_EXTICR3_EXTI8_Msk        (0xFUL << SYSCFG_EXTICR3_EXTI8_Pos)     /*!< 0x0000000F */
#define SYSCFG_EXTICR3_EXTI8            SYSCFG_EXTICR3_EXTI8_Msk               /*!< EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9_Pos        (4U)                                   
#define SYSCFG_EXTICR3_EXTI9_Msk        (0xFUL << SYSCFG_EXTICR3_EXTI9_Pos)     /*!< 0x000000F0 */
#define SYSCFG_EXTICR3_EXTI9            SYSCFG_EXTICR3_EXTI9_Msk               /*!< EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10_Pos       (8U)                                   
#define SYSCFG_EXTICR3_EXTI10_Msk       (0xFUL << SYSCFG_EXTICR3_EXTI10_Pos)    /*!< 0x00000F00 */
#define SYSCFG_EXTICR3_EXTI10           SYSCFG_EXTICR3_EXTI10_Msk              /*!< EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11_Pos       (12U)                                  
#define SYSCFG_EXTICR3_EXTI11_Msk       (0xFUL << SYSCFG_EXTICR3_EXTI11_Pos)    /*!< 0x0000F000 */
#define SYSCFG_EXTICR3_EXTI11           SYSCFG_EXTICR3_EXTI11_Msk              /*!< EXTI 11 configuration */

/** 
  * @brief  EXTI8 configuration  
  */ 
#define SYSCFG_EXTICR3_EXTI8_PA         (0x00000000U)                          /*!< PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB         (0x00000001U)                          /*!< PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC         (0x00000002U)                          /*!< PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD         (0x00000003U)                          /*!< PD[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PE         (0x00000004U)                          /*!< PE[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PF         (0x00000006U)                          /*!< PF[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PG         (0x00000007U)                          /*!< PG[8] pin */

/** 
  * @brief  EXTI9 configuration  
  */ 
#define SYSCFG_EXTICR3_EXTI9_PA         (0x00000000U)                          /*!< PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB         (0x00000010U)                          /*!< PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC         (0x00000020U)                          /*!< PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD         (0x00000030U)                          /*!< PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE         (0x00000040U)                          /*!< PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF         (0x00000060U)                          /*!< PF[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PG         (0x00000070U)                          /*!< PG[9] pin */

/** 
  * @brief  EXTI10 configuration  
  */ 
#define SYSCFG_EXTICR3_EXTI10_PA        (0x00000000U)                          /*!< PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB        (0x00000100U)                          /*!< PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC        (0x00000200U)                          /*!< PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD        (0x00000300U)                          /*!< PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE        (0x00000400U)                          /*!< PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF        (0x00000600U)                          /*!< PF[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PG        (0x00000700U)                          /*!< PG[10] pin */

/** 
  * @brief  EXTI11 configuration  
  */ 
#define SYSCFG_EXTICR3_EXTI11_PA        (0x00000000U)                          /*!< PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB        (0x00001000U)                          /*!< PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC        (0x00002000U)                          /*!< PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD        (0x00003000U)                          /*!< PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE        (0x00004000U)                          /*!< PE[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PF        (0x00006000U)                          /*!< PF[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PG        (0x00007000U)                          /*!< PG[11] pin */

/*****************  Bit definition for SYSCFG_EXTICR4 register  *****************/
#define SYSCFG_EXTICR4_EXTI12_Pos       (0U)                                   
#define SYSCFG_EXTICR4_EXTI12_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI12_Pos)    /*!< 0x0000000F */
#define SYSCFG_EXTICR4_EXTI12           SYSCFG_EXTICR4_EXTI12_Msk              /*!< EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13_Pos       (4U)                                   
#define SYSCFG_EXTICR4_EXTI13_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI13_Pos)    /*!< 0x000000F0 */
#define SYSCFG_EXTICR4_EXTI13           SYSCFG_EXTICR4_EXTI13_Msk              /*!< EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14_Pos       (8U)                                   
#define SYSCFG_EXTICR4_EXTI14_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI14_Pos)    /*!< 0x00000F00 */
#define SYSCFG_EXTICR4_EXTI14           SYSCFG_EXTICR4_EXTI14_Msk              /*!< EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15_Pos       (12U)                                  
#define SYSCFG_EXTICR4_EXTI15_Msk       (0xFUL << SYSCFG_EXTICR4_EXTI15_Pos)    /*!< 0x0000F000 */
#define SYSCFG_EXTICR4_EXTI15           SYSCFG_EXTICR4_EXTI15_Msk              /*!< EXTI 15 configuration */

/** 
  * @brief  EXTI12 configuration  
  */ 
#define SYSCFG_EXTICR4_EXTI12_PA        (0x00000000U)                          /*!< PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB        (0x00000001U)                          /*!< PB[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PC        (0x00000002U)                          /*!< PC[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PD        (0x00000003U)                          /*!< PD[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PE        (0x00000004U)                          /*!< PE[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PF        (0x00000006U)                          /*!< PF[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PG        (0x00000007U)                          /*!< PG[12] pin */

/** 
  * @brief  EXTI13 configuration  
  */ 
#define SYSCFG_EXTICR4_EXTI13_PA        (0x00000000U)                          /*!< PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB        (0x00000010U)                          /*!< PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC        (0x00000020U)                          /*!< PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD        (0x00000030U)                          /*!< PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE        (0x00000040U)                          /*!< PE[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PF        (0x00000060U)                          /*!< PF[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PG        (0x00000070U)                          /*!< PG[13] pin */

/** 
  * @brief  EXTI14 configuration  
  */ 
#define SYSCFG_EXTICR4_EXTI14_PA        (0x00000000U)                          /*!< PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB        (0x00000100U)                          /*!< PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC        (0x00000200U)                          /*!< PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD        (0x00000300U)                          /*!< PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE        (0x00000400U)                          /*!< PE[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PF        (0x00000600U)                          /*!< PF[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PG        (0x00000700U)                          /*!< PG[14] pin */

/** 
  * @brief  EXTI15 configuration  
  */ 
#define SYSCFG_EXTICR4_EXTI15_PA        (0x00000000U)                          /*!< PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB        (0x00001000U)                          /*!< PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC        (0x00002000U)                          /*!< PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD        (0x00003000U)                          /*!< PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE        (0x00004000U)                          /*!< PE[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PF        (0x00006000U)                          /*!< PF[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PG        (0x00007000U)                          /*!< PG[15] pin */

/******************************************************************************/
/*                                                                            */
/*                       Routing Interface (RI)                               */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for RI_ICR register  ********************/
#define RI_ICR_IC1OS_Pos                (0U)                                   
#define RI_ICR_IC1OS_Msk                (0xFUL << RI_ICR_IC1OS_Pos)             /*!< 0x0000000F */
#define RI_ICR_IC1OS                    RI_ICR_IC1OS_Msk                       /*!< IC1OS[3:0] bits (Input Capture 1 select bits) */
#define RI_ICR_IC1OS_0                  (0x1UL << RI_ICR_IC1OS_Pos)             /*!< 0x00000001 */
#define RI_ICR_IC1OS_1                  (0x2UL << RI_ICR_IC1OS_Pos)             /*!< 0x00000002 */
#define RI_ICR_IC1OS_2                  (0x4UL << RI_ICR_IC1OS_Pos)             /*!< 0x00000004 */
#define RI_ICR_IC1OS_3                  (0x8UL << RI_ICR_IC1OS_Pos)             /*!< 0x00000008 */

#define RI_ICR_IC2OS_Pos                (4U)                                   
#define RI_ICR_IC2OS_Msk                (0xFUL << RI_ICR_IC2OS_Pos)             /*!< 0x000000F0 */
#define RI_ICR_IC2OS                    RI_ICR_IC2OS_Msk                       /*!< IC2OS[3:0] bits (Input Capture 2 select bits) */
#define RI_ICR_IC2OS_0                  (0x1UL << RI_ICR_IC2OS_Pos)             /*!< 0x00000010 */
#define RI_ICR_IC2OS_1                  (0x2UL << RI_ICR_IC2OS_Pos)             /*!< 0x00000020 */
#define RI_ICR_IC2OS_2                  (0x4UL << RI_ICR_IC2OS_Pos)             /*!< 0x00000040 */
#define RI_ICR_IC2OS_3                  (0x8UL << RI_ICR_IC2OS_Pos)             /*!< 0x00000080 */

#define RI_ICR_IC3OS_Pos                (8U)                                   
#define RI_ICR_IC3OS_Msk                (0xFUL << RI_ICR_IC3OS_Pos)             /*!< 0x00000F00 */
#define RI_ICR_IC3OS                    RI_ICR_IC3OS_Msk                       /*!< IC3OS[3:0] bits (Input Capture 3 select bits) */
#define RI_ICR_IC3OS_0                  (0x1UL << RI_ICR_IC3OS_Pos)             /*!< 0x00000100 */
#define RI_ICR_IC3OS_1                  (0x2UL << RI_ICR_IC3OS_Pos)             /*!< 0x00000200 */
#define RI_ICR_IC3OS_2                  (0x4UL << RI_ICR_IC3OS_Pos)             /*!< 0x00000400 */
#define RI_ICR_IC3OS_3                  (0x8UL << RI_ICR_IC3OS_Pos)             /*!< 0x00000800 */

#define RI_ICR_IC4OS_Pos                (12U)                                  
#define RI_ICR_IC4OS_Msk                (0xFUL << RI_ICR_IC4OS_Pos)             /*!< 0x0000F000 */
#define RI_ICR_IC4OS                    RI_ICR_IC4OS_Msk                       /*!< IC4OS[3:0] bits (Input Capture 4 select bits) */
#define RI_ICR_IC4OS_0                  (0x1UL << RI_ICR_IC4OS_Pos)             /*!< 0x00001000 */
#define RI_ICR_IC4OS_1                  (0x2UL << RI_ICR_IC4OS_Pos)             /*!< 0x00002000 */
#define RI_ICR_IC4OS_2                  (0x4UL << RI_ICR_IC4OS_Pos)             /*!< 0x00004000 */
#define RI_ICR_IC4OS_3                  (0x8UL << RI_ICR_IC4OS_Pos)             /*!< 0x00008000 */

#define RI_ICR_TIM_Pos                  (16U)                                  
#define RI_ICR_TIM_Msk                  (0x3UL << RI_ICR_TIM_Pos)               /*!< 0x00030000 */
#define RI_ICR_TIM                      RI_ICR_TIM_Msk                         /*!< TIM[3:0] bits (Timers select bits) */
#define RI_ICR_TIM_0                    (0x1UL << RI_ICR_TIM_Pos)               /*!< 0x00010000 */
#define RI_ICR_TIM_1                    (0x2UL << RI_ICR_TIM_Pos)               /*!< 0x00020000 */

#define RI_ICR_IC1_Pos                  (18U)                                  
#define RI_ICR_IC1_Msk                  (0x1UL << RI_ICR_IC1_Pos)               /*!< 0x00040000 */
#define RI_ICR_IC1                      RI_ICR_IC1_Msk                         /*!< Input capture 1 */
#define RI_ICR_IC2_Pos                  (19U)                                  
#define RI_ICR_IC2_Msk                  (0x1UL << RI_ICR_IC2_Pos)               /*!< 0x00080000 */
#define RI_ICR_IC2                      RI_ICR_IC2_Msk                         /*!< Input capture 2 */
#define RI_ICR_IC3_Pos                  (20U)                                  
#define RI_ICR_IC3_Msk                  (0x1UL << RI_ICR_IC3_Pos)               /*!< 0x00100000 */
#define RI_ICR_IC3                      RI_ICR_IC3_Msk                         /*!< Input capture 3 */
#define RI_ICR_IC4_Pos                  (21U)                                  
#define RI_ICR_IC4_Msk                  (0x1UL << RI_ICR_IC4_Pos)               /*!< 0x00200000 */
#define RI_ICR_IC4                      RI_ICR_IC4_Msk                         /*!< Input capture 4 */

/********************  Bit definition for RI_ASCR1 register  ********************/
#define RI_ASCR1_CH_Pos                 (0U)                                   
#define RI_ASCR1_CH_Msk                 (0x7BFDFFFFUL << RI_ASCR1_CH_Pos)       /*!< 0x7BFDFFFF */
#define RI_ASCR1_CH                     RI_ASCR1_CH_Msk                        /*!< AS_CH[25:18] & AS_CH[15:0] bits ( Analog switches selection bits) */
#define RI_ASCR1_CH_0                   (0x00000001U)                          /*!< Bit 0 */
#define RI_ASCR1_CH_1                   (0x00000002U)                          /*!< Bit 1 */
#define RI_ASCR1_CH_2                   (0x00000004U)                          /*!< Bit 2 */
#define RI_ASCR1_CH_3                   (0x00000008U)                          /*!< Bit 3 */
#define RI_ASCR1_CH_4                   (0x00000010U)                          /*!< Bit 4 */
#define RI_ASCR1_CH_5                   (0x00000020U)                          /*!< Bit 5 */
#define RI_ASCR1_CH_6                   (0x00000040U)                          /*!< Bit 6 */
#define RI_ASCR1_CH_7                   (0x00000080U)                          /*!< Bit 7 */
#define RI_ASCR1_CH_8                   (0x00000100U)                          /*!< Bit 8 */
#define RI_ASCR1_CH_9                   (0x00000200U)                          /*!< Bit 9 */
#define RI_ASCR1_CH_10                  (0x00000400U)                          /*!< Bit 10 */
#define RI_ASCR1_CH_11                  (0x00000800U)                          /*!< Bit 11 */
#define RI_ASCR1_CH_12                  (0x00001000U)                          /*!< Bit 12 */
#define RI_ASCR1_CH_13                  (0x00002000U)                          /*!< Bit 13 */
#define RI_ASCR1_CH_14                  (0x00004000U)                          /*!< Bit 14 */
#define RI_ASCR1_CH_15                  (0x00008000U)                          /*!< Bit 15 */
#define RI_ASCR1_CH_31                  (0x00010000U)                          /*!< Bit 16 */
#define RI_ASCR1_CH_18                  (0x00040000U)                          /*!< Bit 18 */
#define RI_ASCR1_CH_19                  (0x00080000U)                          /*!< Bit 19 */
#define RI_ASCR1_CH_20                  (0x00100000U)                          /*!< Bit 20 */
#define RI_ASCR1_CH_21                  (0x00200000U)                          /*!< Bit 21 */
#define RI_ASCR1_CH_22                  (0x00400000U)                          /*!< Bit 22 */
#define RI_ASCR1_CH_23                  (0x00800000U)                          /*!< Bit 23 */
#define RI_ASCR1_CH_24                  (0x01000000U)                          /*!< Bit 24 */
#define RI_ASCR1_CH_25                  (0x02000000U)                          /*!< Bit 25 */
#define RI_ASCR1_VCOMP_Pos              (26U)                                  
#define RI_ASCR1_VCOMP_Msk              (0x1UL << RI_ASCR1_VCOMP_Pos)           /*!< 0x04000000 */
#define RI_ASCR1_VCOMP                  RI_ASCR1_VCOMP_Msk                     /*!< ADC analog switch selection for internal node to COMP1 */
#define RI_ASCR1_CH_27                  (0x08000000U)                          /*!< Bit 27 */
#define RI_ASCR1_CH_28                  (0x10000000U)                          /*!< Bit 28 */
#define RI_ASCR1_CH_29                  (0x20000000U)                          /*!< Bit 29 */
#define RI_ASCR1_CH_30                  (0x40000000U)                          /*!< Bit 30 */
#define RI_ASCR1_SCM_Pos                (31U)                                  
#define RI_ASCR1_SCM_Msk                (0x1UL << RI_ASCR1_SCM_Pos)             /*!< 0x80000000 */
#define RI_ASCR1_SCM                    RI_ASCR1_SCM_Msk                       /*!< I/O Switch control mode */

/********************  Bit definition for RI_ASCR2 register  ********************/
#define RI_ASCR2_GR10_1                 (0x00000001U)                          /*!< GR10-1 selection bit */
#define RI_ASCR2_GR10_2                 (0x00000002U)                          /*!< GR10-2 selection bit */
#define RI_ASCR2_GR10_3                 (0x00000004U)                          /*!< GR10-3 selection bit */
#define RI_ASCR2_GR10_4                 (0x00000008U)                          /*!< GR10-4 selection bit */
#define RI_ASCR2_GR6_Pos                (4U)                                   
#define RI_ASCR2_GR6_Msk                (0x1800003UL << RI_ASCR2_GR6_Pos)       /*!< 0x18000030 */
#define RI_ASCR2_GR6                    RI_ASCR2_GR6_Msk                       /*!< GR6 selection bits */
#define RI_ASCR2_GR6_1                  (0x0000001UL << RI_ASCR2_GR6_Pos)       /*!< 0x00000010 */
#define RI_ASCR2_GR6_2                  (0x0000002UL << RI_ASCR2_GR6_Pos)       /*!< 0x00000020 */
#define RI_ASCR2_GR6_3                  (0x0800000UL << RI_ASCR2_GR6_Pos)       /*!< 0x08000000 */
#define RI_ASCR2_GR6_4                  (0x1000000UL << RI_ASCR2_GR6_Pos)       /*!< 0x10000000 */
#define RI_ASCR2_GR5_1                  (0x00000040U)                          /*!< GR5-1 selection bit */
#define RI_ASCR2_GR5_2                  (0x00000080U)                          /*!< GR5-2 selection bit */
#define RI_ASCR2_GR5_3                  (0x00000100U)                          /*!< GR5-3 selection bit */
#define RI_ASCR2_GR4_1                  (0x00000200U)                          /*!< GR4-1 selection bit */
#define RI_ASCR2_GR4_2                  (0x00000400U)                          /*!< GR4-2 selection bit */
#define RI_ASCR2_GR4_3                  (0x00000800U)                          /*!< GR4-3 selection bit */
#define RI_ASCR2_GR4_4                  (0x00008000U)                          /*!< GR4-4 selection bit */
#define RI_ASCR2_CH0b_Pos               (16U)                                  
#define RI_ASCR2_CH0b_Msk               (0x1UL << RI_ASCR2_CH0b_Pos)            /*!< 0x00010000 */
#define RI_ASCR2_CH0b                   RI_ASCR2_CH0b_Msk                      /*!< CH0b selection bit */
#define RI_ASCR2_CH1b_Pos               (17U)                                  
#define RI_ASCR2_CH1b_Msk               (0x1UL << RI_ASCR2_CH1b_Pos)            /*!< 0x00020000 */
#define RI_ASCR2_CH1b                   RI_ASCR2_CH1b_Msk                      /*!< CH1b selection bit */
#define RI_ASCR2_CH2b_Pos               (18U)                                  
#define RI_ASCR2_CH2b_Msk               (0x1UL << RI_ASCR2_CH2b_Pos)            /*!< 0x00040000 */
#define RI_ASCR2_CH2b                   RI_ASCR2_CH2b_Msk                      /*!< CH2b selection bit */
#define RI_ASCR2_CH3b_Pos               (19U)                                  
#define RI_ASCR2_CH3b_Msk               (0x1UL << RI_ASCR2_CH3b_Pos)            /*!< 0x00080000 */
#define RI_ASCR2_CH3b                   RI_ASCR2_CH3b_Msk                      /*!< CH3b selection bit */
#define RI_ASCR2_CH6b_Pos               (20U)                                  
#define RI_ASCR2_CH6b_Msk               (0x1UL << RI_ASCR2_CH6b_Pos)            /*!< 0x00100000 */
#define RI_ASCR2_CH6b                   RI_ASCR2_CH6b_Msk                      /*!< CH6b selection bit */
#define RI_ASCR2_CH7b_Pos               (21U)                                  
#define RI_ASCR2_CH7b_Msk               (0x1UL << RI_ASCR2_CH7b_Pos)            /*!< 0x00200000 */
#define RI_ASCR2_CH7b                   RI_ASCR2_CH7b_Msk                      /*!< CH7b selection bit */
#define RI_ASCR2_CH8b_Pos               (22U)                                  
#define RI_ASCR2_CH8b_Msk               (0x1UL << RI_ASCR2_CH8b_Pos)            /*!< 0x00400000 */
#define RI_ASCR2_CH8b                   RI_ASCR2_CH8b_Msk                      /*!< CH8b selection bit */
#define RI_ASCR2_CH9b_Pos               (23U)                                  
#define RI_ASCR2_CH9b_Msk               (0x1UL << RI_ASCR2_CH9b_Pos)            /*!< 0x00800000 */
#define RI_ASCR2_CH9b                   RI_ASCR2_CH9b_Msk                      /*!< CH9b selection bit */
#define RI_ASCR2_CH10b_Pos              (24U)                                  
#define RI_ASCR2_CH10b_Msk              (0x1UL << RI_ASCR2_CH10b_Pos)           /*!< 0x01000000 */
#define RI_ASCR2_CH10b                  RI_ASCR2_CH10b_Msk                     /*!< CH10b selection bit */
#define RI_ASCR2_CH11b_Pos              (25U)                                  
#define RI_ASCR2_CH11b_Msk              (0x1UL << RI_ASCR2_CH11b_Pos)           /*!< 0x02000000 */
#define RI_ASCR2_CH11b                  RI_ASCR2_CH11b_Msk                     /*!< CH11b selection bit */
#define RI_ASCR2_CH12b_Pos              (26U)                                  
#define RI_ASCR2_CH12b_Msk              (0x1UL << RI_ASCR2_CH12b_Pos)           /*!< 0x04000000 */
#define RI_ASCR2_CH12b                  RI_ASCR2_CH12b_Msk                     /*!< CH12b selection bit */

/********************  Bit definition for RI_HYSCR1 register  ********************/
#define RI_HYSCR1_PA_Pos                (0U)                                   
#define RI_HYSCR1_PA_Msk                (0xFFFFUL << RI_HYSCR1_PA_Pos)          /*!< 0x0000FFFF */
#define RI_HYSCR1_PA                    RI_HYSCR1_PA_Msk                       /*!< PA[15:0] Port A Hysteresis selection */
#define RI_HYSCR1_PA_0                  (0x0001UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000001 */
#define RI_HYSCR1_PA_1                  (0x0002UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000002 */
#define RI_HYSCR1_PA_2                  (0x0004UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000004 */
#define RI_HYSCR1_PA_3                  (0x0008UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000008 */
#define RI_HYSCR1_PA_4                  (0x0010UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000010 */
#define RI_HYSCR1_PA_5                  (0x0020UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000020 */
#define RI_HYSCR1_PA_6                  (0x0040UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000040 */
#define RI_HYSCR1_PA_7                  (0x0080UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000080 */
#define RI_HYSCR1_PA_8                  (0x0100UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000100 */
#define RI_HYSCR1_PA_9                  (0x0200UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000200 */
#define RI_HYSCR1_PA_10                 (0x0400UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000400 */
#define RI_HYSCR1_PA_11                 (0x0800UL << RI_HYSCR1_PA_Pos)          /*!< 0x00000800 */
#define RI_HYSCR1_PA_12                 (0x1000UL << RI_HYSCR1_PA_Pos)          /*!< 0x00001000 */
#define RI_HYSCR1_PA_13                 (0x2000UL << RI_HYSCR1_PA_Pos)          /*!< 0x00002000 */
#define RI_HYSCR1_PA_14                 (0x4000UL << RI_HYSCR1_PA_Pos)          /*!< 0x00004000 */
#define RI_HYSCR1_PA_15                 (0x8000UL << RI_HYSCR1_PA_Pos)          /*!< 0x00008000 */

#define RI_HYSCR1_PB_Pos                (16U)                                  
#define RI_HYSCR1_PB_Msk                (0xFFFFUL << RI_HYSCR1_PB_Pos)          /*!< 0xFFFF0000 */
#define RI_HYSCR1_PB                    RI_HYSCR1_PB_Msk                       /*!< PB[15:0] Port B Hysteresis selection */
#define RI_HYSCR1_PB_0                  (0x0001UL << RI_HYSCR1_PB_Pos)          /*!< 0x00010000 */
#define RI_HYSCR1_PB_1                  (0x0002UL << RI_HYSCR1_PB_Pos)          /*!< 0x00020000 */
#define RI_HYSCR1_PB_2                  (0x0004UL << RI_HYSCR1_PB_Pos)          /*!< 0x00040000 */
#define RI_HYSCR1_PB_3                  (0x0008UL << RI_HYSCR1_PB_Pos)          /*!< 0x00080000 */
#define RI_HYSCR1_PB_4                  (0x0010UL << RI_HYSCR1_PB_Pos)          /*!< 0x00100000 */
#define RI_HYSCR1_PB_5                  (0x0020UL << RI_HYSCR1_PB_Pos)          /*!< 0x00200000 */
#define RI_HYSCR1_PB_6                  (0x0040UL << RI_HYSCR1_PB_Pos)          /*!< 0x00400000 */
#define RI_HYSCR1_PB_7                  (0x0080UL << RI_HYSCR1_PB_Pos)          /*!< 0x00800000 */
#define RI_HYSCR1_PB_8                  (0x0100UL << RI_HYSCR1_PB_Pos)          /*!< 0x01000000 */
#define RI_HYSCR1_PB_9                  (0x0200UL << RI_HYSCR1_PB_Pos)          /*!< 0x02000000 */
#define RI_HYSCR1_PB_10                 (0x0400UL << RI_HYSCR1_PB_Pos)          /*!< 0x04000000 */
#define RI_HYSCR1_PB_11                 (0x0800UL << RI_HYSCR1_PB_Pos)          /*!< 0x08000000 */
#define RI_HYSCR1_PB_12                 (0x1000UL << RI_HYSCR1_PB_Pos)          /*!< 0x10000000 */
#define RI_HYSCR1_PB_13                 (0x2000UL << RI_HYSCR1_PB_Pos)          /*!< 0x20000000 */
#define RI_HYSCR1_PB_14                 (0x4000UL << RI_HYSCR1_PB_Pos)          /*!< 0x40000000 */
#define RI_HYSCR1_PB_15                 (0x8000UL << RI_HYSCR1_PB_Pos)          /*!< 0x80000000 */

/********************  Bit definition for RI_HYSCR2 register  ********************/
#define RI_HYSCR2_PC_Pos                (0U)                                   
#define RI_HYSCR2_PC_Msk                (0xFFFFUL << RI_HYSCR2_PC_Pos)          /*!< 0x0000FFFF */
#define RI_HYSCR2_PC                    RI_HYSCR2_PC_Msk                       /*!< PC[15:0] Port C Hysteresis selection */
#define RI_HYSCR2_PC_0                  (0x0001UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000001 */
#define RI_HYSCR2_PC_1                  (0x0002UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000002 */
#define RI_HYSCR2_PC_2                  (0x0004UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000004 */
#define RI_HYSCR2_PC_3                  (0x0008UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000008 */
#define RI_HYSCR2_PC_4                  (0x0010UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000010 */
#define RI_HYSCR2_PC_5                  (0x0020UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000020 */
#define RI_HYSCR2_PC_6                  (0x0040UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000040 */
#define RI_HYSCR2_PC_7                  (0x0080UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000080 */
#define RI_HYSCR2_PC_8                  (0x0100UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000100 */
#define RI_HYSCR2_PC_9                  (0x0200UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000200 */
#define RI_HYSCR2_PC_10                 (0x0400UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000400 */
#define RI_HYSCR2_PC_11                 (0x0800UL << RI_HYSCR2_PC_Pos)          /*!< 0x00000800 */
#define RI_HYSCR2_PC_12                 (0x1000UL << RI_HYSCR2_PC_Pos)          /*!< 0x00001000 */
#define RI_HYSCR2_PC_13                 (0x2000UL << RI_HYSCR2_PC_Pos)          /*!< 0x00002000 */
#define RI_HYSCR2_PC_14                 (0x4000UL << RI_HYSCR2_PC_Pos)          /*!< 0x00004000 */
#define RI_HYSCR2_PC_15                 (0x8000UL << RI_HYSCR2_PC_Pos)          /*!< 0x00008000 */

#define RI_HYSCR2_PD_Pos                (16U)                                  
#define RI_HYSCR2_PD_Msk                (0xFFFFUL << RI_HYSCR2_PD_Pos)          /*!< 0xFFFF0000 */
#define RI_HYSCR2_PD                    RI_HYSCR2_PD_Msk                       /*!< PD[15:0] Port D Hysteresis selection */
#define RI_HYSCR2_PD_0                  (0x0001UL << RI_HYSCR2_PD_Pos)          /*!< 0x00010000 */
#define RI_HYSCR2_PD_1                  (0x0002UL << RI_HYSCR2_PD_Pos)          /*!< 0x00020000 */
#define RI_HYSCR2_PD_2                  (0x0004UL << RI_HYSCR2_PD_Pos)          /*!< 0x00040000 */
#define RI_HYSCR2_PD_3                  (0x0008UL << RI_HYSCR2_PD_Pos)          /*!< 0x00080000 */
#define RI_HYSCR2_PD_4                  (0x0010UL << RI_HYSCR2_PD_Pos)          /*!< 0x00100000 */
#define RI_HYSCR2_PD_5                  (0x0020UL << RI_HYSCR2_PD_Pos)          /*!< 0x00200000 */
#define RI_HYSCR2_PD_6                  (0x0040UL << RI_HYSCR2_PD_Pos)          /*!< 0x00400000 */
#define RI_HYSCR2_PD_7                  (0x0080UL << RI_HYSCR2_PD_Pos)          /*!< 0x00800000 */
#define RI_HYSCR2_PD_8                  (0x0100UL << RI_HYSCR2_PD_Pos)          /*!< 0x01000000 */
#define RI_HYSCR2_PD_9                  (0x0200UL << RI_HYSCR2_PD_Pos)          /*!< 0x02000000 */
#define RI_HYSCR2_PD_10                 (0x0400UL << RI_HYSCR2_PD_Pos)          /*!< 0x04000000 */
#define RI_HYSCR2_PD_11                 (0x0800UL << RI_HYSCR2_PD_Pos)          /*!< 0x08000000 */
#define RI_HYSCR2_PD_12                 (0x1000UL << RI_HYSCR2_PD_Pos)          /*!< 0x10000000 */
#define RI_HYSCR2_PD_13                 (0x2000UL << RI_HYSCR2_PD_Pos)          /*!< 0x20000000 */
#define RI_HYSCR2_PD_14                 (0x4000UL << RI_HYSCR2_PD_Pos)          /*!< 0x40000000 */
#define RI_HYSCR2_PD_15                 (0x8000UL << RI_HYSCR2_PD_Pos)          /*!< 0x80000000 */

/********************  Bit definition for RI_HYSCR3 register  ********************/
#define RI_HYSCR3_PE_Pos                (0U)                                   
#define RI_HYSCR3_PE_Msk                (0xFFFFUL << RI_HYSCR3_PE_Pos)          /*!< 0x0000FFFF */
#define RI_HYSCR3_PE                    RI_HYSCR3_PE_Msk                       /*!< PE[15:0] Port E Hysteresis selection */
#define RI_HYSCR3_PE_0                  (0x0001UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000001 */
#define RI_HYSCR3_PE_1                  (0x0002UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000002 */
#define RI_HYSCR3_PE_2                  (0x0004UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000004 */
#define RI_HYSCR3_PE_3                  (0x0008UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000008 */
#define RI_HYSCR3_PE_4                  (0x0010UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000010 */
#define RI_HYSCR3_PE_5                  (0x0020UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000020 */
#define RI_HYSCR3_PE_6                  (0x0040UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000040 */
#define RI_HYSCR3_PE_7                  (0x0080UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000080 */
#define RI_HYSCR3_PE_8                  (0x0100UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000100 */
#define RI_HYSCR3_PE_9                  (0x0200UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000200 */
#define RI_HYSCR3_PE_10                 (0x0400UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000400 */
#define RI_HYSCR3_PE_11                 (0x0800UL << RI_HYSCR3_PE_Pos)          /*!< 0x00000800 */
#define RI_HYSCR3_PE_12                 (0x1000UL << RI_HYSCR3_PE_Pos)          /*!< 0x00001000 */
#define RI_HYSCR3_PE_13                 (0x2000UL << RI_HYSCR3_PE_Pos)          /*!< 0x00002000 */
#define RI_HYSCR3_PE_14                 (0x4000UL << RI_HYSCR3_PE_Pos)          /*!< 0x00004000 */
#define RI_HYSCR3_PE_15                 (0x8000UL << RI_HYSCR3_PE_Pos)          /*!< 0x00008000 */
#define RI_HYSCR3_PF_Pos                (16U)                                  
#define RI_HYSCR3_PF_Msk                (0xFFFFUL << RI_HYSCR3_PF_Pos)          /*!< 0xFFFF0000 */
#define RI_HYSCR3_PF                    RI_HYSCR3_PF_Msk                       /*!< PF[15:0] Port F Hysteresis selection */
#define RI_HYSCR3_PF_0                  (0x0001UL << RI_HYSCR3_PF_Pos)          /*!< 0x00010000 */
#define RI_HYSCR3_PF_1                  (0x0002UL << RI_HYSCR3_PF_Pos)          /*!< 0x00020000 */
#define RI_HYSCR3_PF_2                  (0x0004UL << RI_HYSCR3_PF_Pos)          /*!< 0x00040000 */
#define RI_HYSCR3_PF_3                  (0x0008UL << RI_HYSCR3_PF_Pos)          /*!< 0x00080000 */
#define RI_HYSCR3_PF_4                  (0x0010UL << RI_HYSCR3_PF_Pos)          /*!< 0x00100000 */
#define RI_HYSCR3_PF_5                  (0x0020UL << RI_HYSCR3_PF_Pos)          /*!< 0x00200000 */
#define RI_HYSCR3_PF_6                  (0x0040UL << RI_HYSCR3_PF_Pos)          /*!< 0x00400000 */
#define RI_HYSCR3_PF_7                  (0x0080UL << RI_HYSCR3_PF_Pos)          /*!< 0x00800000 */
#define RI_HYSCR3_PF_8                  (0x0100UL << RI_HYSCR3_PF_Pos)          /*!< 0x01000000 */
#define RI_HYSCR3_PF_9                  (0x0200UL << RI_HYSCR3_PF_Pos)          /*!< 0x02000000 */
#define RI_HYSCR3_PF_10                 (0x0400UL << RI_HYSCR3_PF_Pos)          /*!< 0x04000000 */
#define RI_HYSCR3_PF_11                 (0x0800UL << RI_HYSCR3_PF_Pos)          /*!< 0x08000000 */
#define RI_HYSCR3_PF_12                 (0x1000UL << RI_HYSCR3_PF_Pos)          /*!< 0x10000000 */
#define RI_HYSCR3_PF_13                 (0x2000UL << RI_HYSCR3_PF_Pos)          /*!< 0x20000000 */
#define RI_HYSCR3_PF_14                 (0x4000UL << RI_HYSCR3_PF_Pos)          /*!< 0x40000000 */
#define RI_HYSCR3_PF_15                 (0x8000UL << RI_HYSCR3_PF_Pos)          /*!< 0x80000000 */
/********************  Bit definition for RI_HYSCR4 register  ********************/
#define RI_HYSCR4_PG_Pos                (0U)                                   
#define RI_HYSCR4_PG_Msk                (0xFFFFUL << RI_HYSCR4_PG_Pos)          /*!< 0x0000FFFF */
#define RI_HYSCR4_PG                    RI_HYSCR4_PG_Msk                       /*!< PG[15:0] Port G Hysteresis selection */
#define RI_HYSCR4_PG_0                  (0x0001UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000001 */
#define RI_HYSCR4_PG_1                  (0x0002UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000002 */
#define RI_HYSCR4_PG_2                  (0x0004UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000004 */
#define RI_HYSCR4_PG_3                  (0x0008UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000008 */
#define RI_HYSCR4_PG_4                  (0x0010UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000010 */
#define RI_HYSCR4_PG_5                  (0x0020UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000020 */
#define RI_HYSCR4_PG_6                  (0x0040UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000040 */
#define RI_HYSCR4_PG_7                  (0x0080UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000080 */
#define RI_HYSCR4_PG_8                  (0x0100UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000100 */
#define RI_HYSCR4_PG_9                  (0x0200UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000200 */
#define RI_HYSCR4_PG_10                 (0x0400UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000400 */
#define RI_HYSCR4_PG_11                 (0x0800UL << RI_HYSCR4_PG_Pos)          /*!< 0x00000800 */
#define RI_HYSCR4_PG_12                 (0x1000UL << RI_HYSCR4_PG_Pos)          /*!< 0x00001000 */
#define RI_HYSCR4_PG_13                 (0x2000UL << RI_HYSCR4_PG_Pos)          /*!< 0x00002000 */
#define RI_HYSCR4_PG_14                 (0x4000UL << RI_HYSCR4_PG_Pos)          /*!< 0x00004000 */
#define RI_HYSCR4_PG_15                 (0x8000UL << RI_HYSCR4_PG_Pos)          /*!< 0x00008000 */

/********************  Bit definition for RI_ASMR1 register  ********************/
#define RI_ASMR1_PA_Pos                 (0U)                                   
#define RI_ASMR1_PA_Msk                 (0xFFFFUL << RI_ASMR1_PA_Pos)           /*!< 0x0000FFFF */
#define RI_ASMR1_PA                     RI_ASMR1_PA_Msk                        /*!< PA[15:0] Port A selection*/
#define RI_ASMR1_PA_0                   (0x0001UL << RI_ASMR1_PA_Pos)           /*!< 0x00000001 */
#define RI_ASMR1_PA_1                   (0x0002UL << RI_ASMR1_PA_Pos)           /*!< 0x00000002 */
#define RI_ASMR1_PA_2                   (0x0004UL << RI_ASMR1_PA_Pos)           /*!< 0x00000004 */
#define RI_ASMR1_PA_3                   (0x0008UL << RI_ASMR1_PA_Pos)           /*!< 0x00000008 */
#define RI_ASMR1_PA_4                   (0x0010UL << RI_ASMR1_PA_Pos)           /*!< 0x00000010 */
#define RI_ASMR1_PA_5                   (0x0020UL << RI_ASMR1_PA_Pos)           /*!< 0x00000020 */
#define RI_ASMR1_PA_6                   (0x0040UL << RI_ASMR1_PA_Pos)           /*!< 0x00000040 */
#define RI_ASMR1_PA_7                   (0x0080UL << RI_ASMR1_PA_Pos)           /*!< 0x00000080 */
#define RI_ASMR1_PA_8                   (0x0100UL << RI_ASMR1_PA_Pos)           /*!< 0x00000100 */
#define RI_ASMR1_PA_9                   (0x0200UL << RI_ASMR1_PA_Pos)           /*!< 0x00000200 */
#define RI_ASMR1_PA_10                  (0x0400UL << RI_ASMR1_PA_Pos)           /*!< 0x00000400 */
#define RI_ASMR1_PA_11                  (0x0800UL << RI_ASMR1_PA_Pos)           /*!< 0x00000800 */
#define RI_ASMR1_PA_12                  (0x1000UL << RI_ASMR1_PA_Pos)           /*!< 0x00001000 */
#define RI_ASMR1_PA_13                  (0x2000UL << RI_ASMR1_PA_Pos)           /*!< 0x00002000 */
#define RI_ASMR1_PA_14                  (0x4000UL << RI_ASMR1_PA_Pos)           /*!< 0x00004000 */
#define RI_ASMR1_PA_15                  (0x8000UL << RI_ASMR1_PA_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_CMR1 register  ********************/
#define RI_CMR1_PA_Pos                  (0U)                                   
#define RI_CMR1_PA_Msk                  (0xFFFFUL << RI_CMR1_PA_Pos)            /*!< 0x0000FFFF */
#define RI_CMR1_PA                      RI_CMR1_PA_Msk                         /*!< PA[15:0] Port A selection*/
#define RI_CMR1_PA_0                    (0x0001UL << RI_CMR1_PA_Pos)            /*!< 0x00000001 */
#define RI_CMR1_PA_1                    (0x0002UL << RI_CMR1_PA_Pos)            /*!< 0x00000002 */
#define RI_CMR1_PA_2                    (0x0004UL << RI_CMR1_PA_Pos)            /*!< 0x00000004 */
#define RI_CMR1_PA_3                    (0x0008UL << RI_CMR1_PA_Pos)            /*!< 0x00000008 */
#define RI_CMR1_PA_4                    (0x0010UL << RI_CMR1_PA_Pos)            /*!< 0x00000010 */
#define RI_CMR1_PA_5                    (0x0020UL << RI_CMR1_PA_Pos)            /*!< 0x00000020 */
#define RI_CMR1_PA_6                    (0x0040UL << RI_CMR1_PA_Pos)            /*!< 0x00000040 */
#define RI_CMR1_PA_7                    (0x0080UL << RI_CMR1_PA_Pos)            /*!< 0x00000080 */
#define RI_CMR1_PA_8                    (0x0100UL << RI_CMR1_PA_Pos)            /*!< 0x00000100 */
#define RI_CMR1_PA_9                    (0x0200UL << RI_CMR1_PA_Pos)            /*!< 0x00000200 */
#define RI_CMR1_PA_10                   (0x0400UL << RI_CMR1_PA_Pos)            /*!< 0x00000400 */
#define RI_CMR1_PA_11                   (0x0800UL << RI_CMR1_PA_Pos)            /*!< 0x00000800 */
#define RI_CMR1_PA_12                   (0x1000UL << RI_CMR1_PA_Pos)            /*!< 0x00001000 */
#define RI_CMR1_PA_13                   (0x2000UL << RI_CMR1_PA_Pos)            /*!< 0x00002000 */
#define RI_CMR1_PA_14                   (0x4000UL << RI_CMR1_PA_Pos)            /*!< 0x00004000 */
#define RI_CMR1_PA_15                   (0x8000UL << RI_CMR1_PA_Pos)            /*!< 0x00008000 */

/********************  Bit definition for RI_CICR1 register  ********************/
#define RI_CICR1_PA_Pos                 (0U)                                   
#define RI_CICR1_PA_Msk                 (0xFFFFUL << RI_CICR1_PA_Pos)           /*!< 0x0000FFFF */
#define RI_CICR1_PA                     RI_CICR1_PA_Msk                        /*!< PA[15:0] Port A selection*/
#define RI_CICR1_PA_0                   (0x0001UL << RI_CICR1_PA_Pos)           /*!< 0x00000001 */
#define RI_CICR1_PA_1                   (0x0002UL << RI_CICR1_PA_Pos)           /*!< 0x00000002 */
#define RI_CICR1_PA_2                   (0x0004UL << RI_CICR1_PA_Pos)           /*!< 0x00000004 */
#define RI_CICR1_PA_3                   (0x0008UL << RI_CICR1_PA_Pos)           /*!< 0x00000008 */
#define RI_CICR1_PA_4                   (0x0010UL << RI_CICR1_PA_Pos)           /*!< 0x00000010 */
#define RI_CICR1_PA_5                   (0x0020UL << RI_CICR1_PA_Pos)           /*!< 0x00000020 */
#define RI_CICR1_PA_6                   (0x0040UL << RI_CICR1_PA_Pos)           /*!< 0x00000040 */
#define RI_CICR1_PA_7                   (0x0080UL << RI_CICR1_PA_Pos)           /*!< 0x00000080 */
#define RI_CICR1_PA_8                   (0x0100UL << RI_CICR1_PA_Pos)           /*!< 0x00000100 */
#define RI_CICR1_PA_9                   (0x0200UL << RI_CICR1_PA_Pos)           /*!< 0x00000200 */
#define RI_CICR1_PA_10                  (0x0400UL << RI_CICR1_PA_Pos)           /*!< 0x00000400 */
#define RI_CICR1_PA_11                  (0x0800UL << RI_CICR1_PA_Pos)           /*!< 0x00000800 */
#define RI_CICR1_PA_12                  (0x1000UL << RI_CICR1_PA_Pos)           /*!< 0x00001000 */
#define RI_CICR1_PA_13                  (0x2000UL << RI_CICR1_PA_Pos)           /*!< 0x00002000 */
#define RI_CICR1_PA_14                  (0x4000UL << RI_CICR1_PA_Pos)           /*!< 0x00004000 */
#define RI_CICR1_PA_15                  (0x8000UL << RI_CICR1_PA_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_ASMR2 register  ********************/
#define RI_ASMR2_PB_Pos                 (0U)                                   
#define RI_ASMR2_PB_Msk                 (0xFFFFUL << RI_ASMR2_PB_Pos)           /*!< 0x0000FFFF */
#define RI_ASMR2_PB                     RI_ASMR2_PB_Msk                        /*!< PB[15:0] Port B selection */
#define RI_ASMR2_PB_0                   (0x0001UL << RI_ASMR2_PB_Pos)           /*!< 0x00000001 */
#define RI_ASMR2_PB_1                   (0x0002UL << RI_ASMR2_PB_Pos)           /*!< 0x00000002 */
#define RI_ASMR2_PB_2                   (0x0004UL << RI_ASMR2_PB_Pos)           /*!< 0x00000004 */
#define RI_ASMR2_PB_3                   (0x0008UL << RI_ASMR2_PB_Pos)           /*!< 0x00000008 */
#define RI_ASMR2_PB_4                   (0x0010UL << RI_ASMR2_PB_Pos)           /*!< 0x00000010 */
#define RI_ASMR2_PB_5                   (0x0020UL << RI_ASMR2_PB_Pos)           /*!< 0x00000020 */
#define RI_ASMR2_PB_6                   (0x0040UL << RI_ASMR2_PB_Pos)           /*!< 0x00000040 */
#define RI_ASMR2_PB_7                   (0x0080UL << RI_ASMR2_PB_Pos)           /*!< 0x00000080 */
#define RI_ASMR2_PB_8                   (0x0100UL << RI_ASMR2_PB_Pos)           /*!< 0x00000100 */
#define RI_ASMR2_PB_9                   (0x0200UL << RI_ASMR2_PB_Pos)           /*!< 0x00000200 */
#define RI_ASMR2_PB_10                  (0x0400UL << RI_ASMR2_PB_Pos)           /*!< 0x00000400 */
#define RI_ASMR2_PB_11                  (0x0800UL << RI_ASMR2_PB_Pos)           /*!< 0x00000800 */
#define RI_ASMR2_PB_12                  (0x1000UL << RI_ASMR2_PB_Pos)           /*!< 0x00001000 */
#define RI_ASMR2_PB_13                  (0x2000UL << RI_ASMR2_PB_Pos)           /*!< 0x00002000 */
#define RI_ASMR2_PB_14                  (0x4000UL << RI_ASMR2_PB_Pos)           /*!< 0x00004000 */
#define RI_ASMR2_PB_15                  (0x8000UL << RI_ASMR2_PB_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_CMR2 register  ********************/
#define RI_CMR2_PB_Pos                  (0U)                                   
#define RI_CMR2_PB_Msk                  (0xFFFFUL << RI_CMR2_PB_Pos)            /*!< 0x0000FFFF */
#define RI_CMR2_PB                      RI_CMR2_PB_Msk                         /*!< PB[15:0] Port B selection */
#define RI_CMR2_PB_0                    (0x0001UL << RI_CMR2_PB_Pos)            /*!< 0x00000001 */
#define RI_CMR2_PB_1                    (0x0002UL << RI_CMR2_PB_Pos)            /*!< 0x00000002 */
#define RI_CMR2_PB_2                    (0x0004UL << RI_CMR2_PB_Pos)            /*!< 0x00000004 */
#define RI_CMR2_PB_3                    (0x0008UL << RI_CMR2_PB_Pos)            /*!< 0x00000008 */
#define RI_CMR2_PB_4                    (0x0010UL << RI_CMR2_PB_Pos)            /*!< 0x00000010 */
#define RI_CMR2_PB_5                    (0x0020UL << RI_CMR2_PB_Pos)            /*!< 0x00000020 */
#define RI_CMR2_PB_6                    (0x0040UL << RI_CMR2_PB_Pos)            /*!< 0x00000040 */
#define RI_CMR2_PB_7                    (0x0080UL << RI_CMR2_PB_Pos)            /*!< 0x00000080 */
#define RI_CMR2_PB_8                    (0x0100UL << RI_CMR2_PB_Pos)            /*!< 0x00000100 */
#define RI_CMR2_PB_9                    (0x0200UL << RI_CMR2_PB_Pos)            /*!< 0x00000200 */
#define RI_CMR2_PB_10                   (0x0400UL << RI_CMR2_PB_Pos)            /*!< 0x00000400 */
#define RI_CMR2_PB_11                   (0x0800UL << RI_CMR2_PB_Pos)            /*!< 0x00000800 */
#define RI_CMR2_PB_12                   (0x1000UL << RI_CMR2_PB_Pos)            /*!< 0x00001000 */
#define RI_CMR2_PB_13                   (0x2000UL << RI_CMR2_PB_Pos)            /*!< 0x00002000 */
#define RI_CMR2_PB_14                   (0x4000UL << RI_CMR2_PB_Pos)            /*!< 0x00004000 */
#define RI_CMR2_PB_15                   (0x8000UL << RI_CMR2_PB_Pos)            /*!< 0x00008000 */

/********************  Bit definition for RI_CICR2 register  ********************/
#define RI_CICR2_PB_Pos                 (0U)                                   
#define RI_CICR2_PB_Msk                 (0xFFFFUL << RI_CICR2_PB_Pos)           /*!< 0x0000FFFF */
#define RI_CICR2_PB                     RI_CICR2_PB_Msk                        /*!< PB[15:0] Port B selection */
#define RI_CICR2_PB_0                   (0x0001UL << RI_CICR2_PB_Pos)           /*!< 0x00000001 */
#define RI_CICR2_PB_1                   (0x0002UL << RI_CICR2_PB_Pos)           /*!< 0x00000002 */
#define RI_CICR2_PB_2                   (0x0004UL << RI_CICR2_PB_Pos)           /*!< 0x00000004 */
#define RI_CICR2_PB_3                   (0x0008UL << RI_CICR2_PB_Pos)           /*!< 0x00000008 */
#define RI_CICR2_PB_4                   (0x0010UL << RI_CICR2_PB_Pos)           /*!< 0x00000010 */
#define RI_CICR2_PB_5                   (0x0020UL << RI_CICR2_PB_Pos)           /*!< 0x00000020 */
#define RI_CICR2_PB_6                   (0x0040UL << RI_CICR2_PB_Pos)           /*!< 0x00000040 */
#define RI_CICR2_PB_7                   (0x0080UL << RI_CICR2_PB_Pos)           /*!< 0x00000080 */
#define RI_CICR2_PB_8                   (0x0100UL << RI_CICR2_PB_Pos)           /*!< 0x00000100 */
#define RI_CICR2_PB_9                   (0x0200UL << RI_CICR2_PB_Pos)           /*!< 0x00000200 */
#define RI_CICR2_PB_10                  (0x0400UL << RI_CICR2_PB_Pos)           /*!< 0x00000400 */
#define RI_CICR2_PB_11                  (0x0800UL << RI_CICR2_PB_Pos)           /*!< 0x00000800 */
#define RI_CICR2_PB_12                  (0x1000UL << RI_CICR2_PB_Pos)           /*!< 0x00001000 */
#define RI_CICR2_PB_13                  (0x2000UL << RI_CICR2_PB_Pos)           /*!< 0x00002000 */
#define RI_CICR2_PB_14                  (0x4000UL << RI_CICR2_PB_Pos)           /*!< 0x00004000 */
#define RI_CICR2_PB_15                  (0x8000UL << RI_CICR2_PB_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_ASMR3 register  ********************/
#define RI_ASMR3_PC_Pos                 (0U)                                   
#define RI_ASMR3_PC_Msk                 (0xFFFFUL << RI_ASMR3_PC_Pos)           /*!< 0x0000FFFF */
#define RI_ASMR3_PC                     RI_ASMR3_PC_Msk                        /*!< PC[15:0] Port C selection */
#define RI_ASMR3_PC_0                   (0x0001UL << RI_ASMR3_PC_Pos)           /*!< 0x00000001 */
#define RI_ASMR3_PC_1                   (0x0002UL << RI_ASMR3_PC_Pos)           /*!< 0x00000002 */
#define RI_ASMR3_PC_2                   (0x0004UL << RI_ASMR3_PC_Pos)           /*!< 0x00000004 */
#define RI_ASMR3_PC_3                   (0x0008UL << RI_ASMR3_PC_Pos)           /*!< 0x00000008 */
#define RI_ASMR3_PC_4                   (0x0010UL << RI_ASMR3_PC_Pos)           /*!< 0x00000010 */
#define RI_ASMR3_PC_5                   (0x0020UL << RI_ASMR3_PC_Pos)           /*!< 0x00000020 */
#define RI_ASMR3_PC_6                   (0x0040UL << RI_ASMR3_PC_Pos)           /*!< 0x00000040 */
#define RI_ASMR3_PC_7                   (0x0080UL << RI_ASMR3_PC_Pos)           /*!< 0x00000080 */
#define RI_ASMR3_PC_8                   (0x0100UL << RI_ASMR3_PC_Pos)           /*!< 0x00000100 */
#define RI_ASMR3_PC_9                   (0x0200UL << RI_ASMR3_PC_Pos)           /*!< 0x00000200 */
#define RI_ASMR3_PC_10                  (0x0400UL << RI_ASMR3_PC_Pos)           /*!< 0x00000400 */
#define RI_ASMR3_PC_11                  (0x0800UL << RI_ASMR3_PC_Pos)           /*!< 0x00000800 */
#define RI_ASMR3_PC_12                  (0x1000UL << RI_ASMR3_PC_Pos)           /*!< 0x00001000 */
#define RI_ASMR3_PC_13                  (0x2000UL << RI_ASMR3_PC_Pos)           /*!< 0x00002000 */
#define RI_ASMR3_PC_14                  (0x4000UL << RI_ASMR3_PC_Pos)           /*!< 0x00004000 */
#define RI_ASMR3_PC_15                  (0x8000UL << RI_ASMR3_PC_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_CMR3 register  ********************/
#define RI_CMR3_PC_Pos                  (0U)                                   
#define RI_CMR3_PC_Msk                  (0xFFFFUL << RI_CMR3_PC_Pos)            /*!< 0x0000FFFF */
#define RI_CMR3_PC                      RI_CMR3_PC_Msk                         /*!< PC[15:0] Port C selection */
#define RI_CMR3_PC_0                    (0x0001UL << RI_CMR3_PC_Pos)            /*!< 0x00000001 */
#define RI_CMR3_PC_1                    (0x0002UL << RI_CMR3_PC_Pos)            /*!< 0x00000002 */
#define RI_CMR3_PC_2                    (0x0004UL << RI_CMR3_PC_Pos)            /*!< 0x00000004 */
#define RI_CMR3_PC_3                    (0x0008UL << RI_CMR3_PC_Pos)            /*!< 0x00000008 */
#define RI_CMR3_PC_4                    (0x0010UL << RI_CMR3_PC_Pos)            /*!< 0x00000010 */
#define RI_CMR3_PC_5                    (0x0020UL << RI_CMR3_PC_Pos)            /*!< 0x00000020 */
#define RI_CMR3_PC_6                    (0x0040UL << RI_CMR3_PC_Pos)            /*!< 0x00000040 */
#define RI_CMR3_PC_7                    (0x0080UL << RI_CMR3_PC_Pos)            /*!< 0x00000080 */
#define RI_CMR3_PC_8                    (0x0100UL << RI_CMR3_PC_Pos)            /*!< 0x00000100 */
#define RI_CMR3_PC_9                    (0x0200UL << RI_CMR3_PC_Pos)            /*!< 0x00000200 */
#define RI_CMR3_PC_10                   (0x0400UL << RI_CMR3_PC_Pos)            /*!< 0x00000400 */
#define RI_CMR3_PC_11                   (0x0800UL << RI_CMR3_PC_Pos)            /*!< 0x00000800 */
#define RI_CMR3_PC_12                   (0x1000UL << RI_CMR3_PC_Pos)            /*!< 0x00001000 */
#define RI_CMR3_PC_13                   (0x2000UL << RI_CMR3_PC_Pos)            /*!< 0x00002000 */
#define RI_CMR3_PC_14                   (0x4000UL << RI_CMR3_PC_Pos)            /*!< 0x00004000 */
#define RI_CMR3_PC_15                   (0x8000UL << RI_CMR3_PC_Pos)            /*!< 0x00008000 */

/********************  Bit definition for RI_CICR3 register  ********************/
#define RI_CICR3_PC_Pos                 (0U)                                   
#define RI_CICR3_PC_Msk                 (0xFFFFUL << RI_CICR3_PC_Pos)           /*!< 0x0000FFFF */
#define RI_CICR3_PC                     RI_CICR3_PC_Msk                        /*!< PC[15:0] Port C selection */
#define RI_CICR3_PC_0                   (0x0001UL << RI_CICR3_PC_Pos)           /*!< 0x00000001 */
#define RI_CICR3_PC_1                   (0x0002UL << RI_CICR3_PC_Pos)           /*!< 0x00000002 */
#define RI_CICR3_PC_2                   (0x0004UL << RI_CICR3_PC_Pos)           /*!< 0x00000004 */
#define RI_CICR3_PC_3                   (0x0008UL << RI_CICR3_PC_Pos)           /*!< 0x00000008 */
#define RI_CICR3_PC_4                   (0x0010UL << RI_CICR3_PC_Pos)           /*!< 0x00000010 */
#define RI_CICR3_PC_5                   (0x0020UL << RI_CICR3_PC_Pos)           /*!< 0x00000020 */
#define RI_CICR3_PC_6                   (0x0040UL << RI_CICR3_PC_Pos)           /*!< 0x00000040 */
#define RI_CICR3_PC_7                   (0x0080UL << RI_CICR3_PC_Pos)           /*!< 0x00000080 */
#define RI_CICR3_PC_8                   (0x0100UL << RI_CICR3_PC_Pos)           /*!< 0x00000100 */
#define RI_CICR3_PC_9                   (0x0200UL << RI_CICR3_PC_Pos)           /*!< 0x00000200 */
#define RI_CICR3_PC_10                  (0x0400UL << RI_CICR3_PC_Pos)           /*!< 0x00000400 */
#define RI_CICR3_PC_11                  (0x0800UL << RI_CICR3_PC_Pos)           /*!< 0x00000800 */
#define RI_CICR3_PC_12                  (0x1000UL << RI_CICR3_PC_Pos)           /*!< 0x00001000 */
#define RI_CICR3_PC_13                  (0x2000UL << RI_CICR3_PC_Pos)           /*!< 0x00002000 */
#define RI_CICR3_PC_14                  (0x4000UL << RI_CICR3_PC_Pos)           /*!< 0x00004000 */
#define RI_CICR3_PC_15                  (0x8000UL << RI_CICR3_PC_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_ASMR4 register  ********************/
#define RI_ASMR4_PF_Pos                 (0U)                                   
#define RI_ASMR4_PF_Msk                 (0xFFFFUL << RI_ASMR4_PF_Pos)           /*!< 0x0000FFFF */
#define RI_ASMR4_PF                     RI_ASMR4_PF_Msk                        /*!< PF[15:0] Port F selection */
#define RI_ASMR4_PF_0                   (0x0001UL << RI_ASMR4_PF_Pos)           /*!< 0x00000001 */
#define RI_ASMR4_PF_1                   (0x0002UL << RI_ASMR4_PF_Pos)           /*!< 0x00000002 */
#define RI_ASMR4_PF_2                   (0x0004UL << RI_ASMR4_PF_Pos)           /*!< 0x00000004 */
#define RI_ASMR4_PF_3                   (0x0008UL << RI_ASMR4_PF_Pos)           /*!< 0x00000008 */
#define RI_ASMR4_PF_4                   (0x0010UL << RI_ASMR4_PF_Pos)           /*!< 0x00000010 */
#define RI_ASMR4_PF_5                   (0x0020UL << RI_ASMR4_PF_Pos)           /*!< 0x00000020 */
#define RI_ASMR4_PF_6                   (0x0040UL << RI_ASMR4_PF_Pos)           /*!< 0x00000040 */
#define RI_ASMR4_PF_7                   (0x0080UL << RI_ASMR4_PF_Pos)           /*!< 0x00000080 */
#define RI_ASMR4_PF_8                   (0x0100UL << RI_ASMR4_PF_Pos)           /*!< 0x00000100 */
#define RI_ASMR4_PF_9                   (0x0200UL << RI_ASMR4_PF_Pos)           /*!< 0x00000200 */
#define RI_ASMR4_PF_10                  (0x0400UL << RI_ASMR4_PF_Pos)           /*!< 0x00000400 */
#define RI_ASMR4_PF_11                  (0x0800UL << RI_ASMR4_PF_Pos)           /*!< 0x00000800 */
#define RI_ASMR4_PF_12                  (0x1000UL << RI_ASMR4_PF_Pos)           /*!< 0x00001000 */
#define RI_ASMR4_PF_13                  (0x2000UL << RI_ASMR4_PF_Pos)           /*!< 0x00002000 */
#define RI_ASMR4_PF_14                  (0x4000UL << RI_ASMR4_PF_Pos)           /*!< 0x00004000 */
#define RI_ASMR4_PF_15                  (0x8000UL << RI_ASMR4_PF_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_CMR4 register  ********************/
#define RI_CMR4_PF_Pos                  (0U)                                   
#define RI_CMR4_PF_Msk                  (0xFFFFUL << RI_CMR4_PF_Pos)            /*!< 0x0000FFFF */
#define RI_CMR4_PF                      RI_CMR4_PF_Msk                         /*!< PF[15:0] Port F selection */
#define RI_CMR4_PF_0                    (0x0001UL << RI_CMR4_PF_Pos)            /*!< 0x00000001 */
#define RI_CMR4_PF_1                    (0x0002UL << RI_CMR4_PF_Pos)            /*!< 0x00000002 */
#define RI_CMR4_PF_2                    (0x0004UL << RI_CMR4_PF_Pos)            /*!< 0x00000004 */
#define RI_CMR4_PF_3                    (0x0008UL << RI_CMR4_PF_Pos)            /*!< 0x00000008 */
#define RI_CMR4_PF_4                    (0x0010UL << RI_CMR4_PF_Pos)            /*!< 0x00000010 */
#define RI_CMR4_PF_5                    (0x0020UL << RI_CMR4_PF_Pos)            /*!< 0x00000020 */
#define RI_CMR4_PF_6                    (0x0040UL << RI_CMR4_PF_Pos)            /*!< 0x00000040 */
#define RI_CMR4_PF_7                    (0x0080UL << RI_CMR4_PF_Pos)            /*!< 0x00000080 */
#define RI_CMR4_PF_8                    (0x0100UL << RI_CMR4_PF_Pos)            /*!< 0x00000100 */
#define RI_CMR4_PF_9                    (0x0200UL << RI_CMR4_PF_Pos)            /*!< 0x00000200 */
#define RI_CMR4_PF_10                   (0x0400UL << RI_CMR4_PF_Pos)            /*!< 0x00000400 */
#define RI_CMR4_PF_11                   (0x0800UL << RI_CMR4_PF_Pos)            /*!< 0x00000800 */
#define RI_CMR4_PF_12                   (0x1000UL << RI_CMR4_PF_Pos)            /*!< 0x00001000 */
#define RI_CMR4_PF_13                   (0x2000UL << RI_CMR4_PF_Pos)            /*!< 0x00002000 */
#define RI_CMR4_PF_14                   (0x4000UL << RI_CMR4_PF_Pos)            /*!< 0x00004000 */
#define RI_CMR4_PF_15                   (0x8000UL << RI_CMR4_PF_Pos)            /*!< 0x00008000 */

/********************  Bit definition for RI_CICR4 register  ********************/
#define RI_CICR4_PF_Pos                 (0U)                                   
#define RI_CICR4_PF_Msk                 (0xFFFFUL << RI_CICR4_PF_Pos)           /*!< 0x0000FFFF */
#define RI_CICR4_PF                     RI_CICR4_PF_Msk                        /*!< PF[15:0] Port F selection */
#define RI_CICR4_PF_0                   (0x0001UL << RI_CICR4_PF_Pos)           /*!< 0x00000001 */
#define RI_CICR4_PF_1                   (0x0002UL << RI_CICR4_PF_Pos)           /*!< 0x00000002 */
#define RI_CICR4_PF_2                   (0x0004UL << RI_CICR4_PF_Pos)           /*!< 0x00000004 */
#define RI_CICR4_PF_3                   (0x0008UL << RI_CICR4_PF_Pos)           /*!< 0x00000008 */
#define RI_CICR4_PF_4                   (0x0010UL << RI_CICR4_PF_Pos)           /*!< 0x00000010 */
#define RI_CICR4_PF_5                   (0x0020UL << RI_CICR4_PF_Pos)           /*!< 0x00000020 */
#define RI_CICR4_PF_6                   (0x0040UL << RI_CICR4_PF_Pos)           /*!< 0x00000040 */
#define RI_CICR4_PF_7                   (0x0080UL << RI_CICR4_PF_Pos)           /*!< 0x00000080 */
#define RI_CICR4_PF_8                   (0x0100UL << RI_CICR4_PF_Pos)           /*!< 0x00000100 */
#define RI_CICR4_PF_9                   (0x0200UL << RI_CICR4_PF_Pos)           /*!< 0x00000200 */
#define RI_CICR4_PF_10                  (0x0400UL << RI_CICR4_PF_Pos)           /*!< 0x00000400 */
#define RI_CICR4_PF_11                  (0x0800UL << RI_CICR4_PF_Pos)           /*!< 0x00000800 */
#define RI_CICR4_PF_12                  (0x1000UL << RI_CICR4_PF_Pos)           /*!< 0x00001000 */
#define RI_CICR4_PF_13                  (0x2000UL << RI_CICR4_PF_Pos)           /*!< 0x00002000 */
#define RI_CICR4_PF_14                  (0x4000UL << RI_CICR4_PF_Pos)           /*!< 0x00004000 */
#define RI_CICR4_PF_15                  (0x8000UL << RI_CICR4_PF_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_ASMR5 register  ********************/
#define RI_ASMR5_PG_Pos                 (0U)                                   
#define RI_ASMR5_PG_Msk                 (0xFFFFUL << RI_ASMR5_PG_Pos)           /*!< 0x0000FFFF */
#define RI_ASMR5_PG                     RI_ASMR5_PG_Msk                        /*!< PG[15:0] Port G selection */
#define RI_ASMR5_PG_0                   (0x0001UL << RI_ASMR5_PG_Pos)           /*!< 0x00000001 */
#define RI_ASMR5_PG_1                   (0x0002UL << RI_ASMR5_PG_Pos)           /*!< 0x00000002 */
#define RI_ASMR5_PG_2                   (0x0004UL << RI_ASMR5_PG_Pos)           /*!< 0x00000004 */
#define RI_ASMR5_PG_3                   (0x0008UL << RI_ASMR5_PG_Pos)           /*!< 0x00000008 */
#define RI_ASMR5_PG_4                   (0x0010UL << RI_ASMR5_PG_Pos)           /*!< 0x00000010 */
#define RI_ASMR5_PG_5                   (0x0020UL << RI_ASMR5_PG_Pos)           /*!< 0x00000020 */
#define RI_ASMR5_PG_6                   (0x0040UL << RI_ASMR5_PG_Pos)           /*!< 0x00000040 */
#define RI_ASMR5_PG_7                   (0x0080UL << RI_ASMR5_PG_Pos)           /*!< 0x00000080 */
#define RI_ASMR5_PG_8                   (0x0100UL << RI_ASMR5_PG_Pos)           /*!< 0x00000100 */
#define RI_ASMR5_PG_9                   (0x0200UL << RI_ASMR5_PG_Pos)           /*!< 0x00000200 */
#define RI_ASMR5_PG_10                  (0x0400UL << RI_ASMR5_PG_Pos)           /*!< 0x00000400 */
#define RI_ASMR5_PG_11                  (0x0800UL << RI_ASMR5_PG_Pos)           /*!< 0x00000800 */
#define RI_ASMR5_PG_12                  (0x1000UL << RI_ASMR5_PG_Pos)           /*!< 0x00001000 */
#define RI_ASMR5_PG_13                  (0x2000UL << RI_ASMR5_PG_Pos)           /*!< 0x00002000 */
#define RI_ASMR5_PG_14                  (0x4000UL << RI_ASMR5_PG_Pos)           /*!< 0x00004000 */
#define RI_ASMR5_PG_15                  (0x8000UL << RI_ASMR5_PG_Pos)           /*!< 0x00008000 */

/********************  Bit definition for RI_CMR5 register  ********************/
#define RI_CMR5_PG_Pos                  (0U)                                   
#define RI_CMR5_PG_Msk                  (0xFFFFUL << RI_CMR5_PG_Pos)            /*!< 0x0000FFFF */
#define RI_CMR5_PG                      RI_CMR5_PG_Msk                         /*!< PG[15:0] Port G selection */
#define RI_CMR5_PG_0                    (0x0001UL << RI_CMR5_PG_Pos)            /*!< 0x00000001 */
#define RI_CMR5_PG_1                    (0x0002UL << RI_CMR5_PG_Pos)            /*!< 0x00000002 */
#define RI_CMR5_PG_2                    (0x0004UL << RI_CMR5_PG_Pos)            /*!< 0x00000004 */
#define RI_CMR5_PG_3                    (0x0008UL << RI_CMR5_PG_Pos)            /*!< 0x00000008 */
#define RI_CMR5_PG_4                    (0x0010UL << RI_CMR5_PG_Pos)            /*!< 0x00000010 */
#define RI_CMR5_PG_5                    (0x0020UL << RI_CMR5_PG_Pos)            /*!< 0x00000020 */
#define RI_CMR5_PG_6                    (0x0040UL << RI_CMR5_PG_Pos)            /*!< 0x00000040 */
#define RI_CMR5_PG_7                    (0x0080UL << RI_CMR5_PG_Pos)            /*!< 0x00000080 */
#define RI_CMR5_PG_8                    (0x0100UL << RI_CMR5_PG_Pos)            /*!< 0x00000100 */
#define RI_CMR5_PG_9                    (0x0200UL << RI_CMR5_PG_Pos)            /*!< 0x00000200 */
#define RI_CMR5_PG_10                   (0x0400UL << RI_CMR5_PG_Pos)            /*!< 0x00000400 */
#define RI_CMR5_PG_11                   (0x0800UL << RI_CMR5_PG_Pos)            /*!< 0x00000800 */
#define RI_CMR5_PG_12                   (0x1000UL << RI_CMR5_PG_Pos)            /*!< 0x00001000 */
#define RI_CMR5_PG_13                   (0x2000UL << RI_CMR5_PG_Pos)            /*!< 0x00002000 */
#define RI_CMR5_PG_14                   (0x4000UL << RI_CMR5_PG_Pos)            /*!< 0x00004000 */
#define RI_CMR5_PG_15                   (0x8000UL << RI_CMR5_PG_Pos)            /*!< 0x00008000 */

/********************  Bit definition for RI_CICR5 register  ********************/
#define RI_CICR5_PG_Pos                 (0U)                                   
#define RI_CICR5_PG_Msk                 (0xFFFFUL << RI_CICR5_PG_Pos)           /*!< 0x0000FFFF */
#define RI_CICR5_PG                     RI_CICR5_PG_Msk                        /*!< PG[15:0] Port G selection */
#define RI_CICR5_PG_0                   (0x0001UL << RI_CICR5_PG_Pos)           /*!< 0x00000001 */
#define RI_CICR5_PG_1                   (0x0002UL << RI_CICR5_PG_Pos)           /*!< 0x00000002 */
#define RI_CICR5_PG_2                   (0x0004UL << RI_CICR5_PG_Pos)           /*!< 0x00000004 */
#define RI_CICR5_PG_3                   (0x0008UL << RI_CICR5_PG_Pos)           /*!< 0x00000008 */
#define RI_CICR5_PG_4                   (0x0010UL << RI_CICR5_PG_Pos)           /*!< 0x00000010 */
#define RI_CICR5_PG_5                   (0x0020UL << RI_CICR5_PG_Pos)           /*!< 0x00000020 */
#define RI_CICR5_PG_6                   (0x0040UL << RI_CICR5_PG_Pos)           /*!< 0x00000040 */
#define RI_CICR5_PG_7                   (0x0080UL << RI_CICR5_PG_Pos)           /*!< 0x00000080 */
#define RI_CICR5_PG_8                   (0x0100UL << RI_CICR5_PG_Pos)           /*!< 0x00000100 */
#define RI_CICR5_PG_9                   (0x0200UL << RI_CICR5_PG_Pos)           /*!< 0x00000200 */
#define RI_CICR5_PG_10                  (0x0400UL << RI_CICR5_PG_Pos)           /*!< 0x00000400 */
#define RI_CICR5_PG_11                  (0x0800UL << RI_CICR5_PG_Pos)           /*!< 0x00000800 */
#define RI_CICR5_PG_12                  (0x1000UL << RI_CICR5_PG_Pos)           /*!< 0x00001000 */
#define RI_CICR5_PG_13                  (0x2000UL << RI_CICR5_PG_Pos)           /*!< 0x00002000 */
#define RI_CICR5_PG_14                  (0x4000UL << RI_CICR5_PG_Pos)           /*!< 0x00004000 */
#define RI_CICR5_PG_15                  (0x8000UL << RI_CICR5_PG_Pos)           /*!< 0x00008000 */

/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for USART_SR register  *******************/
#define USART_SR_PE_Pos                     (0U)                               
#define USART_SR_PE_Msk                     (0x1UL << USART_SR_PE_Pos)          /*!< 0x00000001 */
#define USART_SR_PE                         USART_SR_PE_Msk                    /*!< Parity Error */
#define USART_SR_FE_Pos                     (1U)                               
#define USART_SR_FE_Msk                     (0x1UL << USART_SR_FE_Pos)          /*!< 0x00000002 */
#define USART_SR_FE                         USART_SR_FE_Msk                    /*!< Framing Error */
#define USART_SR_NE_Pos                     (2U)                               
#define USART_SR_NE_Msk                     (0x1UL << USART_SR_NE_Pos)          /*!< 0x00000004 */
#define USART_SR_NE                         USART_SR_NE_Msk                    /*!< Noise Error Flag */
#define USART_SR_ORE_Pos                    (3U)                               
#define USART_SR_ORE_Msk                    (0x1UL << USART_SR_ORE_Pos)         /*!< 0x00000008 */
#define USART_SR_ORE                        USART_SR_ORE_Msk                   /*!< OverRun Error */
#define USART_SR_IDLE_Pos                   (4U)                               
#define USART_SR_IDLE_Msk                   (0x1UL << USART_SR_IDLE_Pos)        /*!< 0x00000010 */
#define USART_SR_IDLE                       USART_SR_IDLE_Msk                  /*!< IDLE line detected */
#define USART_SR_RXNE_Pos                   (5U)                               
#define USART_SR_RXNE_Msk                   (0x1UL << USART_SR_RXNE_Pos)        /*!< 0x00000020 */
#define USART_SR_RXNE                       USART_SR_RXNE_Msk                  /*!< Read Data Register Not Empty */
#define USART_SR_TC_Pos                     (6U)                               
#define USART_SR_TC_Msk                     (0x1UL << USART_SR_TC_Pos)          /*!< 0x00000040 */
#define USART_SR_TC                         USART_SR_TC_Msk                    /*!< Transmission Complete */
#define USART_SR_TXE_Pos                    (7U)                               
#define USART_SR_TXE_Msk                    (0x1UL << USART_SR_TXE_Pos)         /*!< 0x00000080 */
#define USART_SR_TXE                        USART_SR_TXE_Msk                   /*!< Transmit Data Register Empty */
#define USART_SR_LBD_Pos                    (8U)                               
#define USART_SR_LBD_Msk                    (0x1UL << USART_SR_LBD_Pos)         /*!< 0x00000100 */
#define USART_SR_LBD                        USART_SR_LBD_Msk                   /*!< LIN Break Detection Flag */
#define USART_SR_CTS_Pos                    (9U)                               
#define USART_SR_CTS_Msk                    (0x1UL << USART_SR_CTS_Pos)         /*!< 0x00000200 */
#define USART_SR_CTS                        USART_SR_CTS_Msk                   /*!< CTS Flag */

/*******************  Bit definition for USART_DR register  *******************/
#define USART_DR_DR_Pos                     (0U)                               
#define USART_DR_DR_Msk                     (0x1FFUL << USART_DR_DR_Pos)        /*!< 0x000001FF */
#define USART_DR_DR                         USART_DR_DR_Msk                    /*!< Data value */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_DIV_FRACTION_Pos          (0U)                               
#define USART_BRR_DIV_FRACTION_Msk          (0xFUL << USART_BRR_DIV_FRACTION_Pos) /*!< 0x0000000F */
#define USART_BRR_DIV_FRACTION              USART_BRR_DIV_FRACTION_Msk         /*!< Fraction of USARTDIV */
#define USART_BRR_DIV_MANTISSA_Pos          (4U)                               
#define USART_BRR_DIV_MANTISSA_Msk          (0xFFFUL << USART_BRR_DIV_MANTISSA_Pos) /*!< 0x0000FFF0 */
#define USART_BRR_DIV_MANTISSA              USART_BRR_DIV_MANTISSA_Msk         /*!< Mantissa of USARTDIV */

/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_SBK_Pos                   (0U)                               
#define USART_CR1_SBK_Msk                   (0x1UL << USART_CR1_SBK_Pos)        /*!< 0x00000001 */
#define USART_CR1_SBK                       USART_CR1_SBK_Msk                  /*!< Send Break */
#define USART_CR1_RWU_Pos                   (1U)                               
#define USART_CR1_RWU_Msk                   (0x1UL << USART_CR1_RWU_Pos)        /*!< 0x00000002 */
#define USART_CR1_RWU                       USART_CR1_RWU_Msk                  /*!< Receiver wakeup */
#define USART_CR1_RE_Pos                    (2U)                               
#define USART_CR1_RE_Msk                    (0x1UL << USART_CR1_RE_Pos)         /*!< 0x00000004 */
#define USART_CR1_RE                        USART_CR1_RE_Msk                   /*!< Receiver Enable */
#define USART_CR1_TE_Pos                    (3U)                               
#define USART_CR1_TE_Msk                    (0x1UL << USART_CR1_TE_Pos)         /*!< 0x00000008 */
#define USART_CR1_TE                        USART_CR1_TE_Msk                   /*!< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos                (4U)                               
#define USART_CR1_IDLEIE_Msk                (0x1UL << USART_CR1_IDLEIE_Pos)     /*!< 0x00000010 */
#define USART_CR1_IDLEIE                    USART_CR1_IDLEIE_Msk               /*!< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos                (5U)                               
#define USART_CR1_RXNEIE_Msk                (0x1UL << USART_CR1_RXNEIE_Pos)     /*!< 0x00000020 */
#define USART_CR1_RXNEIE                    USART_CR1_RXNEIE_Msk               /*!< RXNE Interrupt Enable */
#define USART_CR1_TCIE_Pos                  (6U)                               
#define USART_CR1_TCIE_Msk                  (0x1UL << USART_CR1_TCIE_Pos)       /*!< 0x00000040 */
#define USART_CR1_TCIE                      USART_CR1_TCIE_Msk                 /*!< Transmission Complete Interrupt Enable */
#define USART_CR1_TXEIE_Pos                 (7U)                               
#define USART_CR1_TXEIE_Msk                 (0x1UL << USART_CR1_TXEIE_Pos)      /*!< 0x00000080 */
#define USART_CR1_TXEIE                     USART_CR1_TXEIE_Msk                /*!< PE Interrupt Enable */
#define USART_CR1_PEIE_Pos                  (8U)                               
#define USART_CR1_PEIE_Msk                  (0x1UL << USART_CR1_PEIE_Pos)       /*!< 0x00000100 */
#define USART_CR1_PEIE                      USART_CR1_PEIE_Msk                 /*!< PE Interrupt Enable */
#define USART_CR1_PS_Pos                    (9U)                               
#define USART_CR1_PS_Msk                    (0x1UL << USART_CR1_PS_Pos)         /*!< 0x00000200 */
#define USART_CR1_PS                        USART_CR1_PS_Msk                   /*!< Parity Selection */
#define USART_CR1_PCE_Pos                   (10U)                              
#define USART_CR1_PCE_Msk                   (0x1UL << USART_CR1_PCE_Pos)        /*!< 0x00000400 */
#define USART_CR1_PCE                       USART_CR1_PCE_Msk                  /*!< Parity Control Enable */
#define USART_CR1_WAKE_Pos                  (11U)                              
#define USART_CR1_WAKE_Msk                  (0x1UL << USART_CR1_WAKE_Pos)       /*!< 0x00000800 */
#define USART_CR1_WAKE                      USART_CR1_WAKE_Msk                 /*!< Wakeup method */
#define USART_CR1_M_Pos                     (12U)                              
#define USART_CR1_M_Msk                     (0x1UL << USART_CR1_M_Pos)          /*!< 0x00001000 */
#define USART_CR1_M                         USART_CR1_M_Msk                    /*!< Word length */
#define USART_CR1_UE_Pos                    (13U)                              
#define USART_CR1_UE_Msk                    (0x1UL << USART_CR1_UE_Pos)         /*!< 0x00002000 */
#define USART_CR1_UE                        USART_CR1_UE_Msk                   /*!< USART Enable */
#define USART_CR1_OVER8_Pos                 (15U)                              
#define USART_CR1_OVER8_Msk                 (0x1UL << USART_CR1_OVER8_Pos)      /*!< 0x00008000 */
#define USART_CR1_OVER8                     USART_CR1_OVER8_Msk                /*!< Oversampling by 8-bit mode */

/******************  Bit definition for USART_CR2 register  *******************/
#define USART_CR2_ADD_Pos                   (0U)                               
#define USART_CR2_ADD_Msk                   (0xFUL << USART_CR2_ADD_Pos)        /*!< 0x0000000F */
#define USART_CR2_ADD                       USART_CR2_ADD_Msk                  /*!< Address of the USART node */
#define USART_CR2_LBDL_Pos                  (5U)                               
#define USART_CR2_LBDL_Msk                  (0x1UL << USART_CR2_LBDL_Pos)       /*!< 0x00000020 */
#define USART_CR2_LBDL                      USART_CR2_LBDL_Msk                 /*!< LIN Break Detection Length */
#define USART_CR2_LBDIE_Pos                 (6U)                               
#define USART_CR2_LBDIE_Msk                 (0x1UL << USART_CR2_LBDIE_Pos)      /*!< 0x00000040 */
#define USART_CR2_LBDIE                     USART_CR2_LBDIE_Msk                /*!< LIN Break Detection Interrupt Enable */
#define USART_CR2_LBCL_Pos                  (8U)                               
#define USART_CR2_LBCL_Msk                  (0x1UL << USART_CR2_LBCL_Pos)       /*!< 0x00000100 */
#define USART_CR2_LBCL                      USART_CR2_LBCL_Msk                 /*!< Last Bit Clock pulse */
#define USART_CR2_CPHA_Pos                  (9U)                               
#define USART_CR2_CPHA_Msk                  (0x1UL << USART_CR2_CPHA_Pos)       /*!< 0x00000200 */
#define USART_CR2_CPHA                      USART_CR2_CPHA_Msk                 /*!< Clock Phase */
#define USART_CR2_CPOL_Pos                  (10U)                              
#define USART_CR2_CPOL_Msk                  (0x1UL << USART_CR2_CPOL_Pos)       /*!< 0x00000400 */
#define USART_CR2_CPOL                      USART_CR2_CPOL_Msk                 /*!< Clock Polarity */
#define USART_CR2_CLKEN_Pos                 (11U)                              
#define USART_CR2_CLKEN_Msk                 (0x1UL << USART_CR2_CLKEN_Pos)      /*!< 0x00000800 */
#define USART_CR2_CLKEN                     USART_CR2_CLKEN_Msk                /*!< Clock Enable */

#define USART_CR2_STOP_Pos                  (12U)                              
#define USART_CR2_STOP_Msk                  (0x3UL << USART_CR2_STOP_Pos)       /*!< 0x00003000 */
#define USART_CR2_STOP                      USART_CR2_STOP_Msk                 /*!< STOP[1:0] bits (STOP bits) */
#define USART_CR2_STOP_0                    (0x1UL << USART_CR2_STOP_Pos)       /*!< 0x00001000 */
#define USART_CR2_STOP_1                    (0x2UL << USART_CR2_STOP_Pos)       /*!< 0x00002000 */

#define USART_CR2_LINEN_Pos                 (14U)                              
#define USART_CR2_LINEN_Msk                 (0x1UL << USART_CR2_LINEN_Pos)      /*!< 0x00004000 */
#define USART_CR2_LINEN                     USART_CR2_LINEN_Msk                /*!< LIN mode enable */

/******************  Bit definition for USART_CR3 register  *******************/
#define USART_CR3_EIE_Pos                   (0U)                               
#define USART_CR3_EIE_Msk                   (0x1UL << USART_CR3_EIE_Pos)        /*!< 0x00000001 */
#define USART_CR3_EIE                       USART_CR3_EIE_Msk                  /*!< Error Interrupt Enable */
#define USART_CR3_IREN_Pos                  (1U)                               
#define USART_CR3_IREN_Msk                  (0x1UL << USART_CR3_IREN_Pos)       /*!< 0x00000002 */
#define USART_CR3_IREN                      USART_CR3_IREN_Msk                 /*!< IrDA mode Enable */
#define USART_CR3_IRLP_Pos                  (2U)                               
#define USART_CR3_IRLP_Msk                  (0x1UL << USART_CR3_IRLP_Pos)       /*!< 0x00000004 */
#define USART_CR3_IRLP                      USART_CR3_IRLP_Msk                 /*!< IrDA Low-Power */
#define USART_CR3_HDSEL_Pos                 (3U)                               
#define USART_CR3_HDSEL_Msk                 (0x1UL << USART_CR3_HDSEL_Pos)      /*!< 0x00000008 */
#define USART_CR3_HDSEL                     USART_CR3_HDSEL_Msk                /*!< Half-Duplex Selection */
#define USART_CR3_NACK_Pos                  (4U)                               
#define USART_CR3_NACK_Msk                  (0x1UL << USART_CR3_NACK_Pos)       /*!< 0x00000010 */
#define USART_CR3_NACK                      USART_CR3_NACK_Msk                 /*!< Smartcard NACK enable */
#define USART_CR3_SCEN_Pos                  (5U)                               
#define USART_CR3_SCEN_Msk                  (0x1UL << USART_CR3_SCEN_Pos)       /*!< 0x00000020 */
#define USART_CR3_SCEN                      USART_CR3_SCEN_Msk                 /*!< Smartcard mode enable */
#define USART_CR3_DMAR_Pos                  (6U)                               
#define USART_CR3_DMAR_Msk                  (0x1UL << USART_CR3_DMAR_Pos)       /*!< 0x00000040 */
#define USART_CR3_DMAR                      USART_CR3_DMAR_Msk                 /*!< DMA Enable Receiver */
#define USART_CR3_DMAT_Pos                  (7U)                               
#define USART_CR3_DMAT_Msk                  (0x1UL << USART_CR3_DMAT_Pos)       /*!< 0x00000080 */
#define USART_CR3_DMAT                      USART_CR3_DMAT_Msk                 /*!< DMA Enable Transmitter */
#define USART_CR3_RTSE_Pos                  (8U)                               
#define USART_CR3_RTSE_Msk                  (0x1UL << USART_CR3_RTSE_Pos)       /*!< 0x00000100 */
#define USART_CR3_RTSE                      USART_CR3_RTSE_Msk                 /*!< RTS Enable */
#define USART_CR3_CTSE_Pos                  (9U)                               
#define USART_CR3_CTSE_Msk                  (0x1UL << USART_CR3_CTSE_Pos)       /*!< 0x00000200 */
#define USART_CR3_CTSE                      USART_CR3_CTSE_Msk                 /*!< CTS Enable */
#define USART_CR3_CTSIE_Pos                 (10U)                              
#define USART_CR3_CTSIE_Msk                 (0x1UL << USART_CR3_CTSIE_Pos)      /*!< 0x00000400 */
#define USART_CR3_CTSIE                     USART_CR3_CTSIE_Msk                /*!< CTS Interrupt Enable */
#define USART_CR3_ONEBIT_Pos                (11U)                              
#define USART_CR3_ONEBIT_Msk                (0x1UL << USART_CR3_ONEBIT_Pos)     /*!< 0x00000800 */
#define USART_CR3_ONEBIT                    USART_CR3_ONEBIT_Msk               /*!< One sample bit method enable */

/******************  Bit definition for USART_GTPR register  ******************/
#define USART_GTPR_PSC_Pos                  (0U)                               
#define USART_GTPR_PSC_Msk                  (0xFFUL << USART_GTPR_PSC_Pos)      /*!< 0x000000FF */
#define USART_GTPR_PSC                      USART_GTPR_PSC_Msk                 /*!< PSC[7:0] bits (Prescaler value) */
#define USART_GTPR_PSC_0                    (0x01UL << USART_GTPR_PSC_Pos)      /*!< 0x00000001 */
#define USART_GTPR_PSC_1                    (0x02UL << USART_GTPR_PSC_Pos)      /*!< 0x00000002 */
#define USART_GTPR_PSC_2                    (0x04UL << USART_GTPR_PSC_Pos)      /*!< 0x00000004 */
#define USART_GTPR_PSC_3                    (0x08UL << USART_GTPR_PSC_Pos)      /*!< 0x00000008 */
#define USART_GTPR_PSC_4                    (0x10UL << USART_GTPR_PSC_Pos)      /*!< 0x00000010 */
#define USART_GTPR_PSC_5                    (0x20UL << USART_GTPR_PSC_Pos)      /*!< 0x00000020 */
#define USART_GTPR_PSC_6                    (0x40UL << USART_GTPR_PSC_Pos)      /*!< 0x00000040 */
#define USART_GTPR_PSC_7                    (0x80UL << USART_GTPR_PSC_Pos)      /*!< 0x00000080 */

#define USART_GTPR_GT_Pos                   (8U)                               
#define USART_GTPR_GT_Msk                   (0xFFUL << USART_GTPR_GT_Pos)       /*!< 0x0000FF00 */
#define USART_GTPR_GT                       USART_GTPR_GT_Msk                  /*!< Guard time value */

/******************************************************************************/
/*                                                                            */
/*                     Universal Serial Bus (USB)                             */
/*                                                                            */
/******************************************************************************/

/*!<Endpoint-specific registers */

#define  USB_EP0R                              USB_BASE                        /*!< endpoint 0 register address */
#define  USB_EP1R                             (USB_BASE + 0x00000004U)         /*!< endpoint 1 register address */
#define  USB_EP2R                             (USB_BASE + 0x00000008U)         /*!< endpoint 2 register address */
#define  USB_EP3R                             (USB_BASE + 0x0000000CU)         /*!< endpoint 3 register address */
#define  USB_EP4R                             (USB_BASE + 0x00000010U)         /*!< endpoint 4 register address */
#define  USB_EP5R                             (USB_BASE + 0x00000014U)         /*!< endpoint 5 register address */
#define  USB_EP6R                             (USB_BASE + 0x00000018U)         /*!< endpoint 6 register address */
#define  USB_EP7R                             (USB_BASE + 0x0000001CU)         /*!< endpoint 7 register address */

/* bit positions */ 
#define USB_EP_CTR_RX_Pos                     (15U)                            
#define USB_EP_CTR_RX_Msk                     (0x1UL << USB_EP_CTR_RX_Pos)      /*!< 0x00008000 */
#define USB_EP_CTR_RX                         USB_EP_CTR_RX_Msk                /*!<  EndPoint Correct TRansfer RX */
#define USB_EP_DTOG_RX_Pos                    (14U)                            
#define USB_EP_DTOG_RX_Msk                    (0x1UL << USB_EP_DTOG_RX_Pos)     /*!< 0x00004000 */
#define USB_EP_DTOG_RX                        USB_EP_DTOG_RX_Msk               /*!<  EndPoint Data TOGGLE RX */
#define USB_EPRX_STAT_Pos                     (12U)                            
#define USB_EPRX_STAT_Msk                     (0x3UL << USB_EPRX_STAT_Pos)      /*!< 0x00003000 */
#define USB_EPRX_STAT                         USB_EPRX_STAT_Msk                /*!<  EndPoint RX STATus bit field */
#define USB_EP_SETUP_Pos                      (11U)                            
#define USB_EP_SETUP_Msk                      (0x1UL << USB_EP_SETUP_Pos)       /*!< 0x00000800 */
#define USB_EP_SETUP                          USB_EP_SETUP_Msk                 /*!<  EndPoint SETUP */
#define USB_EP_T_FIELD_Pos                    (9U)                             
#define USB_EP_T_FIELD_Msk                    (0x3UL << USB_EP_T_FIELD_Pos)     /*!< 0x00000600 */
#define USB_EP_T_FIELD                        USB_EP_T_FIELD_Msk               /*!<  EndPoint TYPE */
#define USB_EP_KIND_Pos                       (8U)                             
#define USB_EP_KIND_Msk                       (0x1UL << USB_EP_KIND_Pos)        /*!< 0x00000100 */
#define USB_EP_KIND                           USB_EP_KIND_Msk                  /*!<  EndPoint KIND */
#define USB_EP_CTR_TX_Pos                     (7U)                             
#define USB_EP_CTR_TX_Msk                     (0x1UL << USB_EP_CTR_TX_Pos)      /*!< 0x00000080 */
#define USB_EP_CTR_TX                         USB_EP_CTR_TX_Msk                /*!<  EndPoint Correct TRansfer TX */
#define USB_EP_DTOG_TX_Pos                    (6U)                             
#define USB_EP_DTOG_TX_Msk                    (0x1UL << USB_EP_DTOG_TX_Pos)     /*!< 0x00000040 */
#define USB_EP_DTOG_TX                        USB_EP_DTOG_TX_Msk               /*!<  EndPoint Data TOGGLE TX */
#define USB_EPTX_STAT_Pos                     (4U)                             
#define USB_EPTX_STAT_Msk                     (0x3UL << USB_EPTX_STAT_Pos)      /*!< 0x00000030 */
#define USB_EPTX_STAT                         USB_EPTX_STAT_Msk                /*!<  EndPoint TX STATus bit field */
#define USB_EPADDR_FIELD_Pos                  (0U)                             
#define USB_EPADDR_FIELD_Msk                  (0xFUL << USB_EPADDR_FIELD_Pos)   /*!< 0x0000000F */
#define USB_EPADDR_FIELD                      USB_EPADDR_FIELD_Msk             /*!<  EndPoint ADDRess FIELD */

/* EndPoint REGister MASK (no toggle fields) */
#define  USB_EPREG_MASK     (USB_EP_CTR_RX|USB_EP_SETUP|USB_EP_T_FIELD|USB_EP_KIND|USB_EP_CTR_TX|USB_EPADDR_FIELD)
                                                                               /*!< EP_TYPE[1:0] EndPoint TYPE */
#define USB_EP_TYPE_MASK_Pos                  (9U)                             
#define USB_EP_TYPE_MASK_Msk                  (0x3UL << USB_EP_TYPE_MASK_Pos)   /*!< 0x00000600 */
#define USB_EP_TYPE_MASK                      USB_EP_TYPE_MASK_Msk             /*!< EndPoint TYPE Mask */
#define USB_EP_BULK                           (0x00000000U)                    /*!< EndPoint BULK */
#define USB_EP_CONTROL                        (0x00000200U)                    /*!< EndPoint CONTROL */
#define USB_EP_ISOCHRONOUS                    (0x00000400U)                    /*!< EndPoint ISOCHRONOUS */
#define USB_EP_INTERRUPT                      (0x00000600U)                    /*!< EndPoint INTERRUPT */
#define  USB_EP_T_MASK      (~USB_EP_T_FIELD & USB_EPREG_MASK)
                                                                 
#define  USB_EPKIND_MASK    (~USB_EP_KIND & USB_EPREG_MASK)            /*!< EP_KIND EndPoint KIND */
                                                                               /*!< STAT_TX[1:0] STATus for TX transfer */
#define USB_EP_TX_DIS                         (0x00000000U)                    /*!< EndPoint TX DISabled */
#define USB_EP_TX_STALL                       (0x00000010U)                    /*!< EndPoint TX STALLed */
#define USB_EP_TX_NAK                         (0x00000020U)                    /*!< EndPoint TX NAKed */
#define USB_EP_TX_VALID                       (0x00000030U)                    /*!< EndPoint TX VALID */
#define USB_EPTX_DTOG1                        (0x00000010U)                    /*!< EndPoint TX Data TOGgle bit1 */
#define USB_EPTX_DTOG2                        (0x00000020U)                    /*!< EndPoint TX Data TOGgle bit2 */
#define  USB_EPTX_DTOGMASK  (USB_EPTX_STAT|USB_EPREG_MASK)
                                                                               /*!< STAT_RX[1:0] STATus for RX transfer */
#define USB_EP_RX_DIS                         (0x00000000U)                    /*!< EndPoint RX DISabled */
#define USB_EP_RX_STALL                       (0x00001000U)                    /*!< EndPoint RX STALLed */
#define USB_EP_RX_NAK                         (0x00002000U)                    /*!< EndPoint RX NAKed */
#define USB_EP_RX_VALID                       (0x00003000U)                    /*!< EndPoint RX VALID */
#define USB_EPRX_DTOG1                        (0x00001000U)                    /*!< EndPoint RX Data TOGgle bit1 */
#define USB_EPRX_DTOG2                        (0x00002000U)                    /*!< EndPoint RX Data TOGgle bit1 */
#define  USB_EPRX_DTOGMASK  (USB_EPRX_STAT|USB_EPREG_MASK)

/*******************  Bit definition for USB_EP0R register  *******************/
#define USB_EP0R_EA_Pos                       (0U)                             
#define USB_EP0R_EA_Msk                       (0xFUL << USB_EP0R_EA_Pos)        /*!< 0x0000000F */
#define USB_EP0R_EA                           USB_EP0R_EA_Msk                  /*!<Endpoint Address */

#define USB_EP0R_STAT_TX_Pos                  (4U)                             
#define USB_EP0R_STAT_TX_Msk                  (0x3UL << USB_EP0R_STAT_TX_Pos)   /*!< 0x00000030 */
#define USB_EP0R_STAT_TX                      USB_EP0R_STAT_TX_Msk             /*!<STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP0R_STAT_TX_0                    (0x1UL << USB_EP0R_STAT_TX_Pos)   /*!< 0x00000010 */
#define USB_EP0R_STAT_TX_1                    (0x2UL << USB_EP0R_STAT_TX_Pos)   /*!< 0x00000020 */

#define USB_EP0R_DTOG_TX_Pos                  (6U)                             
#define USB_EP0R_DTOG_TX_Msk                  (0x1UL << USB_EP0R_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP0R_DTOG_TX                      USB_EP0R_DTOG_TX_Msk             /*!<Data Toggle, for transmission transfers */
#define USB_EP0R_CTR_TX_Pos                   (7U)                             
#define USB_EP0R_CTR_TX_Msk                   (0x1UL << USB_EP0R_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP0R_CTR_TX                       USB_EP0R_CTR_TX_Msk              /*!<Correct Transfer for transmission */
#define USB_EP0R_EP_KIND_Pos                  (8U)                             
#define USB_EP0R_EP_KIND_Msk                  (0x1UL << USB_EP0R_EP_KIND_Pos)   /*!< 0x00000100 */
#define USB_EP0R_EP_KIND                      USB_EP0R_EP_KIND_Msk             /*!<Endpoint Kind */

#define USB_EP0R_EP_TYPE_Pos                  (9U)                             
#define USB_EP0R_EP_TYPE_Msk                  (0x3UL << USB_EP0R_EP_TYPE_Pos)   /*!< 0x00000600 */
#define USB_EP0R_EP_TYPE                      USB_EP0R_EP_TYPE_Msk             /*!<EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP0R_EP_TYPE_0                    (0x1UL << USB_EP0R_EP_TYPE_Pos)   /*!< 0x00000200 */
#define USB_EP0R_EP_TYPE_1                    (0x2UL << USB_EP0R_EP_TYPE_Pos)   /*!< 0x00000400 */

#define USB_EP0R_SETUP_Pos                    (11U)                            
#define USB_EP0R_SETUP_Msk                    (0x1UL << USB_EP0R_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP0R_SETUP                        USB_EP0R_SETUP_Msk               /*!<Setup transaction completed */

#define USB_EP0R_STAT_RX_Pos                  (12U)                            
#define USB_EP0R_STAT_RX_Msk                  (0x3UL << USB_EP0R_STAT_RX_Pos)   /*!< 0x00003000 */
#define USB_EP0R_STAT_RX                      USB_EP0R_STAT_RX_Msk             /*!<STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP0R_STAT_RX_0                    (0x1UL << USB_EP0R_STAT_RX_Pos)   /*!< 0x00001000 */
#define USB_EP0R_STAT_RX_1                    (0x2UL << USB_EP0R_STAT_RX_Pos)   /*!< 0x00002000 */

#define USB_EP0R_DTOG_RX_Pos                  (14U)                            
#define USB_EP0R_DTOG_RX_Msk                  (0x1UL << USB_EP0R_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP0R_DTOG_RX                      USB_EP0R_DTOG_RX_Msk             /*!<Data Toggle, for reception transfers */
#define USB_EP0R_CTR_RX_Pos                   (15U)                            
#define USB_EP0R_CTR_RX_Msk                   (0x1UL << USB_EP0R_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP0R_CTR_RX                       USB_EP0R_CTR_RX_Msk              /*!<Correct Transfer for reception */

/*******************  Bit definition for USB_EP1R register  *******************/
#define USB_EP1R_EA_Pos                       (0U)                             
#define USB_EP1R_EA_Msk                       (0xFUL << USB_EP1R_EA_Pos)        /*!< 0x0000000F */
#define USB_EP1R_EA                           USB_EP1R_EA_Msk                  /*!<Endpoint Address */

#define USB_EP1R_STAT_TX_Pos                  (4U)                             
#define USB_EP1R_STAT_TX_Msk                  (0x3UL << USB_EP1R_STAT_TX_Pos)   /*!< 0x00000030 */
#define USB_EP1R_STAT_TX                      USB_EP1R_STAT_TX_Msk             /*!<STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP1R_STAT_TX_0                    (0x1UL << USB_EP1R_STAT_TX_Pos)   /*!< 0x00000010 */
#define USB_EP1R_STAT_TX_1                    (0x2UL << USB_EP1R_STAT_TX_Pos)   /*!< 0x00000020 */

#define USB_EP1R_DTOG_TX_Pos                  (6U)                             
#define USB_EP1R_DTOG_TX_Msk                  (0x1UL << USB_EP1R_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP1R_DTOG_TX                      USB_EP1R_DTOG_TX_Msk             /*!<Data Toggle, for transmission transfers */
#define USB_EP1R_CTR_TX_Pos                   (7U)                             
#define USB_EP1R_CTR_TX_Msk                   (0x1UL << USB_EP1R_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP1R_CTR_TX                       USB_EP1R_CTR_TX_Msk              /*!<Correct Transfer for transmission */
#define USB_EP1R_EP_KIND_Pos                  (8U)                             
#define USB_EP1R_EP_KIND_Msk                  (0x1UL << USB_EP1R_EP_KIND_Pos)   /*!< 0x00000100 */
#define USB_EP1R_EP_KIND                      USB_EP1R_EP_KIND_Msk             /*!<Endpoint Kind */

#define USB_EP1R_EP_TYPE_Pos                  (9U)                             
#define USB_EP1R_EP_TYPE_Msk                  (0x3UL << USB_EP1R_EP_TYPE_Pos)   /*!< 0x00000600 */
#define USB_EP1R_EP_TYPE                      USB_EP1R_EP_TYPE_Msk             /*!<EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP1R_EP_TYPE_0                    (0x1UL << USB_EP1R_EP_TYPE_Pos)   /*!< 0x00000200 */
#define USB_EP1R_EP_TYPE_1                    (0x2UL << USB_EP1R_EP_TYPE_Pos)   /*!< 0x00000400 */

#define USB_EP1R_SETUP_Pos                    (11U)                            
#define USB_EP1R_SETUP_Msk                    (0x1UL << USB_EP1R_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP1R_SETUP                        USB_EP1R_SETUP_Msk               /*!<Setup transaction completed */

#define USB_EP1R_STAT_RX_Pos                  (12U)                            
#define USB_EP1R_STAT_RX_Msk                  (0x3UL << USB_EP1R_STAT_RX_Pos)   /*!< 0x00003000 */
#define USB_EP1R_STAT_RX                      USB_EP1R_STAT_RX_Msk             /*!<STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP1R_STAT_RX_0                    (0x1UL << USB_EP1R_STAT_RX_Pos)   /*!< 0x00001000 */
#define USB_EP1R_STAT_RX_1                    (0x2UL << USB_EP1R_STAT_RX_Pos)   /*!< 0x00002000 */

#define USB_EP1R_DTOG_RX_Pos                  (14U)                            
#define USB_EP1R_DTOG_RX_Msk                  (0x1UL << USB_EP1R_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP1R_DTOG_RX                      USB_EP1R_DTOG_RX_Msk             /*!<Data Toggle, for reception transfers */
#define USB_EP1R_CTR_RX_Pos                   (15U)                            
#define USB_EP1R_CTR_RX_Msk                   (0x1UL << USB_EP1R_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP1R_CTR_RX                       USB_EP1R_CTR_RX_Msk              /*!<Correct Transfer for reception */

/*******************  Bit definition for USB_EP2R register  *******************/
#define USB_EP2R_EA_Pos                       (0U)                             
#define USB_EP2R_EA_Msk                       (0xFUL << USB_EP2R_EA_Pos)        /*!< 0x0000000F */
#define USB_EP2R_EA                           USB_EP2R_EA_Msk                  /*!<Endpoint Address */

#define USB_EP2R_STAT_TX_Pos                  (4U)                             
#define USB_EP2R_STAT_TX_Msk                  (0x3UL << USB_EP2R_STAT_TX_Pos)   /*!< 0x00000030 */
#define USB_EP2R_STAT_TX                      USB_EP2R_STAT_TX_Msk             /*!<STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP2R_STAT_TX_0                    (0x1UL << USB_EP2R_STAT_TX_Pos)   /*!< 0x00000010 */
#define USB_EP2R_STAT_TX_1                    (0x2UL << USB_EP2R_STAT_TX_Pos)   /*!< 0x00000020 */

#define USB_EP2R_DTOG_TX_Pos                  (6U)                             
#define USB_EP2R_DTOG_TX_Msk                  (0x1UL << USB_EP2R_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP2R_DTOG_TX                      USB_EP2R_DTOG_TX_Msk             /*!<Data Toggle, for transmission transfers */
#define USB_EP2R_CTR_TX_Pos                   (7U)                             
#define USB_EP2R_CTR_TX_Msk                   (0x1UL << USB_EP2R_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP2R_CTR_TX                       USB_EP2R_CTR_TX_Msk              /*!<Correct Transfer for transmission */
#define USB_EP2R_EP_KIND_Pos                  (8U)                             
#define USB_EP2R_EP_KIND_Msk                  (0x1UL << USB_EP2R_EP_KIND_Pos)   /*!< 0x00000100 */
#define USB_EP2R_EP_KIND                      USB_EP2R_EP_KIND_Msk             /*!<Endpoint Kind */

#define USB_EP2R_EP_TYPE_Pos                  (9U)                             
#define USB_EP2R_EP_TYPE_Msk                  (0x3UL << USB_EP2R_EP_TYPE_Pos)   /*!< 0x00000600 */
#define USB_EP2R_EP_TYPE                      USB_EP2R_EP_TYPE_Msk             /*!<EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP2R_EP_TYPE_0                    (0x1UL << USB_EP2R_EP_TYPE_Pos)   /*!< 0x00000200 */
#define USB_EP2R_EP_TYPE_1                    (0x2UL << USB_EP2R_EP_TYPE_Pos)   /*!< 0x00000400 */

#define USB_EP2R_SETUP_Pos                    (11U)                            
#define USB_EP2R_SETUP_Msk                    (0x1UL << USB_EP2R_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP2R_SETUP                        USB_EP2R_SETUP_Msk               /*!<Setup transaction completed */

#define USB_EP2R_STAT_RX_Pos                  (12U)                            
#define USB_EP2R_STAT_RX_Msk                  (0x3UL << USB_EP2R_STAT_RX_Pos)   /*!< 0x00003000 */
#define USB_EP2R_STAT_RX                      USB_EP2R_STAT_RX_Msk             /*!<STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP2R_STAT_RX_0                    (0x1UL << USB_EP2R_STAT_RX_Pos)   /*!< 0x00001000 */
#define USB_EP2R_STAT_RX_1                    (0x2UL << USB_EP2R_STAT_RX_Pos)   /*!< 0x00002000 */

#define USB_EP2R_DTOG_RX_Pos                  (14U)                            
#define USB_EP2R_DTOG_RX_Msk                  (0x1UL << USB_EP2R_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP2R_DTOG_RX                      USB_EP2R_DTOG_RX_Msk             /*!<Data Toggle, for reception transfers */
#define USB_EP2R_CTR_RX_Pos                   (15U)                            
#define USB_EP2R_CTR_RX_Msk                   (0x1UL << USB_EP2R_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP2R_CTR_RX                       USB_EP2R_CTR_RX_Msk              /*!<Correct Transfer for reception */

/*******************  Bit definition for USB_EP3R register  *******************/
#define USB_EP3R_EA_Pos                       (0U)                             
#define USB_EP3R_EA_Msk                       (0xFUL << USB_EP3R_EA_Pos)        /*!< 0x0000000F */
#define USB_EP3R_EA                           USB_EP3R_EA_Msk                  /*!<Endpoint Address */

#define USB_EP3R_STAT_TX_Pos                  (4U)                             
#define USB_EP3R_STAT_TX_Msk                  (0x3UL << USB_EP3R_STAT_TX_Pos)   /*!< 0x00000030 */
#define USB_EP3R_STAT_TX                      USB_EP3R_STAT_TX_Msk             /*!<STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP3R_STAT_TX_0                    (0x1UL << USB_EP3R_STAT_TX_Pos)   /*!< 0x00000010 */
#define USB_EP3R_STAT_TX_1                    (0x2UL << USB_EP3R_STAT_TX_Pos)   /*!< 0x00000020 */

#define USB_EP3R_DTOG_TX_Pos                  (6U)                             
#define USB_EP3R_DTOG_TX_Msk                  (0x1UL << USB_EP3R_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP3R_DTOG_TX                      USB_EP3R_DTOG_TX_Msk             /*!<Data Toggle, for transmission transfers */
#define USB_EP3R_CTR_TX_Pos                   (7U)                             
#define USB_EP3R_CTR_TX_Msk                   (0x1UL << USB_EP3R_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP3R_CTR_TX                       USB_EP3R_CTR_TX_Msk              /*!<Correct Transfer for transmission */
#define USB_EP3R_EP_KIND_Pos                  (8U)                             
#define USB_EP3R_EP_KIND_Msk                  (0x1UL << USB_EP3R_EP_KIND_Pos)   /*!< 0x00000100 */
#define USB_EP3R_EP_KIND                      USB_EP3R_EP_KIND_Msk             /*!<Endpoint Kind */

#define USB_EP3R_EP_TYPE_Pos                  (9U)                             
#define USB_EP3R_EP_TYPE_Msk                  (0x3UL << USB_EP3R_EP_TYPE_Pos)   /*!< 0x00000600 */
#define USB_EP3R_EP_TYPE                      USB_EP3R_EP_TYPE_Msk             /*!<EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP3R_EP_TYPE_0                    (0x1UL << USB_EP3R_EP_TYPE_Pos)   /*!< 0x00000200 */
#define USB_EP3R_EP_TYPE_1                    (0x2UL << USB_EP3R_EP_TYPE_Pos)   /*!< 0x00000400 */

#define USB_EP3R_SETUP_Pos                    (11U)                            
#define USB_EP3R_SETUP_Msk                    (0x1UL << USB_EP3R_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP3R_SETUP                        USB_EP3R_SETUP_Msk               /*!<Setup transaction completed */

#define USB_EP3R_STAT_RX_Pos                  (12U)                            
#define USB_EP3R_STAT_RX_Msk                  (0x3UL << USB_EP3R_STAT_RX_Pos)   /*!< 0x00003000 */
#define USB_EP3R_STAT_RX                      USB_EP3R_STAT_RX_Msk             /*!<STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP3R_STAT_RX_0                    (0x1UL << USB_EP3R_STAT_RX_Pos)   /*!< 0x00001000 */
#define USB_EP3R_STAT_RX_1                    (0x2UL << USB_EP3R_STAT_RX_Pos)   /*!< 0x00002000 */

#define USB_EP3R_DTOG_RX_Pos                  (14U)                            
#define USB_EP3R_DTOG_RX_Msk                  (0x1UL << USB_EP3R_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP3R_DTOG_RX                      USB_EP3R_DTOG_RX_Msk             /*!<Data Toggle, for reception transfers */
#define USB_EP3R_CTR_RX_Pos                   (15U)                            
#define USB_EP3R_CTR_RX_Msk                   (0x1UL << USB_EP3R_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP3R_CTR_RX                       USB_EP3R_CTR_RX_Msk              /*!<Correct Transfer for reception */

/*******************  Bit definition for USB_EP4R register  *******************/
#define USB_EP4R_EA_Pos                       (0U)                             
#define USB_EP4R_EA_Msk                       (0xFUL << USB_EP4R_EA_Pos)        /*!< 0x0000000F */
#define USB_EP4R_EA                           USB_EP4R_EA_Msk                  /*!<Endpoint Address */

#define USB_EP4R_STAT_TX_Pos                  (4U)                             
#define USB_EP4R_STAT_TX_Msk                  (0x3UL << USB_EP4R_STAT_TX_Pos)   /*!< 0x00000030 */
#define USB_EP4R_STAT_TX                      USB_EP4R_STAT_TX_Msk             /*!<STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP4R_STAT_TX_0                    (0x1UL << USB_EP4R_STAT_TX_Pos)   /*!< 0x00000010 */
#define USB_EP4R_STAT_TX_1                    (0x2UL << USB_EP4R_STAT_TX_Pos)   /*!< 0x00000020 */

#define USB_EP4R_DTOG_TX_Pos                  (6U)                             
#define USB_EP4R_DTOG_TX_Msk                  (0x1UL << USB_EP4R_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP4R_DTOG_TX                      USB_EP4R_DTOG_TX_Msk             /*!<Data Toggle, for transmission transfers */
#define USB_EP4R_CTR_TX_Pos                   (7U)                             
#define USB_EP4R_CTR_TX_Msk                   (0x1UL << USB_EP4R_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP4R_CTR_TX                       USB_EP4R_CTR_TX_Msk              /*!<Correct Transfer for transmission */
#define USB_EP4R_EP_KIND_Pos                  (8U)                             
#define USB_EP4R_EP_KIND_Msk                  (0x1UL << USB_EP4R_EP_KIND_Pos)   /*!< 0x00000100 */
#define USB_EP4R_EP_KIND                      USB_EP4R_EP_KIND_Msk             /*!<Endpoint Kind */

#define USB_EP4R_EP_TYPE_Pos                  (9U)                             
#define USB_EP4R_EP_TYPE_Msk                  (0x3UL << USB_EP4R_EP_TYPE_Pos)   /*!< 0x00000600 */
#define USB_EP4R_EP_TYPE                      USB_EP4R_EP_TYPE_Msk             /*!<EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP4R_EP_TYPE_0                    (0x1UL << USB_EP4R_EP_TYPE_Pos)   /*!< 0x00000200 */
#define USB_EP4R_EP_TYPE_1                    (0x2UL << USB_EP4R_EP_TYPE_Pos)   /*!< 0x00000400 */

#define USB_EP4R_SETUP_Pos                    (11U)                            
#define USB_EP4R_SETUP_Msk                    (0x1UL << USB_EP4R_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP4R_SETUP                        USB_EP4R_SETUP_Msk               /*!<Setup transaction completed */

#define USB_EP4R_STAT_RX_Pos                  (12U)                            
#define USB_EP4R_STAT_RX_Msk                  (0x3UL << USB_EP4R_STAT_RX_Pos)   /*!< 0x00003000 */
#define USB_EP4R_STAT_RX                      USB_EP4R_STAT_RX_Msk             /*!<STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP4R_STAT_RX_0                    (0x1UL << USB_EP4R_STAT_RX_Pos)   /*!< 0x00001000 */
#define USB_EP4R_STAT_RX_1                    (0x2UL << USB_EP4R_STAT_RX_Pos)   /*!< 0x00002000 */

#define USB_EP4R_DTOG_RX_Pos                  (14U)                            
#define USB_EP4R_DTOG_RX_Msk                  (0x1UL << USB_EP4R_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP4R_DTOG_RX                      USB_EP4R_DTOG_RX_Msk             /*!<Data Toggle, for reception transfers */
#define USB_EP4R_CTR_RX_Pos                   (15U)                            
#define USB_EP4R_CTR_RX_Msk                   (0x1UL << USB_EP4R_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP4R_CTR_RX                       USB_EP4R_CTR_RX_Msk              /*!<Correct Transfer for reception */

/*******************  Bit definition for USB_EP5R register  *******************/
#define USB_EP5R_EA_Pos                       (0U)                             
#define USB_EP5R_EA_Msk                       (0xFUL << USB_EP5R_EA_Pos)        /*!< 0x0000000F */
#define USB_EP5R_EA                           USB_EP5R_EA_Msk                  /*!<Endpoint Address */

#define USB_EP5R_STAT_TX_Pos                  (4U)                             
#define USB_EP5R_STAT_TX_Msk                  (0x3UL << USB_EP5R_STAT_TX_Pos)   /*!< 0x00000030 */
#define USB_EP5R_STAT_TX                      USB_EP5R_STAT_TX_Msk             /*!<STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP5R_STAT_TX_0                    (0x1UL << USB_EP5R_STAT_TX_Pos)   /*!< 0x00000010 */
#define USB_EP5R_STAT_TX_1                    (0x2UL << USB_EP5R_STAT_TX_Pos)   /*!< 0x00000020 */

#define USB_EP5R_DTOG_TX_Pos                  (6U)                             
#define USB_EP5R_DTOG_TX_Msk                  (0x1UL << USB_EP5R_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP5R_DTOG_TX                      USB_EP5R_DTOG_TX_Msk             /*!<Data Toggle, for transmission transfers */
#define USB_EP5R_CTR_TX_Pos                   (7U)                             
#define USB_EP5R_CTR_TX_Msk                   (0x1UL << USB_EP5R_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP5R_CTR_TX                       USB_EP5R_CTR_TX_Msk              /*!<Correct Transfer for transmission */
#define USB_EP5R_EP_KIND_Pos                  (8U)                             
#define USB_EP5R_EP_KIND_Msk                  (0x1UL << USB_EP5R_EP_KIND_Pos)   /*!< 0x00000100 */
#define USB_EP5R_EP_KIND                      USB_EP5R_EP_KIND_Msk             /*!<Endpoint Kind */

#define USB_EP5R_EP_TYPE_Pos                  (9U)                             
#define USB_EP5R_EP_TYPE_Msk                  (0x3UL << USB_EP5R_EP_TYPE_Pos)   /*!< 0x00000600 */
#define USB_EP5R_EP_TYPE                      USB_EP5R_EP_TYPE_Msk             /*!<EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP5R_EP_TYPE_0                    (0x1UL << USB_EP5R_EP_TYPE_Pos)   /*!< 0x00000200 */
#define USB_EP5R_EP_TYPE_1                    (0x2UL << USB_EP5R_EP_TYPE_Pos)   /*!< 0x00000400 */

#define USB_EP5R_SETUP_Pos                    (11U)                            
#define USB_EP5R_SETUP_Msk                    (0x1UL << USB_EP5R_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP5R_SETUP                        USB_EP5R_SETUP_Msk               /*!<Setup transaction completed */

#define USB_EP5R_STAT_RX_Pos                  (12U)                            
#define USB_EP5R_STAT_RX_Msk                  (0x3UL << USB_EP5R_STAT_RX_Pos)   /*!< 0x00003000 */
#define USB_EP5R_STAT_RX                      USB_EP5R_STAT_RX_Msk             /*!<STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP5R_STAT_RX_0                    (0x1UL << USB_EP5R_STAT_RX_Pos)   /*!< 0x00001000 */
#define USB_EP5R_STAT_RX_1                    (0x2UL << USB_EP5R_STAT_RX_Pos)   /*!< 0x00002000 */

#define USB_EP5R_DTOG_RX_Pos                  (14U)                            
#define USB_EP5R_DTOG_RX_Msk                  (0x1UL << USB_EP5R_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP5R_DTOG_RX                      USB_EP5R_DTOG_RX_Msk             /*!<Data Toggle, for reception transfers */
#define USB_EP5R_CTR_RX_Pos                   (15U)                            
#define USB_EP5R_CTR_RX_Msk                   (0x1UL << USB_EP5R_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP5R_CTR_RX                       USB_EP5R_CTR_RX_Msk              /*!<Correct Transfer for reception */

/*******************  Bit definition for USB_EP6R register  *******************/
#define USB_EP6R_EA_Pos                       (0U)                             
#define USB_EP6R_EA_Msk                       (0xFUL << USB_EP6R_EA_Pos)        /*!< 0x0000000F */
#define USB_EP6R_EA                           USB_EP6R_EA_Msk                  /*!<Endpoint Address */

#define USB_EP6R_STAT_TX_Pos                  (4U)                             
#define USB_EP6R_STAT_TX_Msk                  (0x3UL << USB_EP6R_STAT_TX_Pos)   /*!< 0x00000030 */
#define USB_EP6R_STAT_TX                      USB_EP6R_STAT_TX_Msk             /*!<STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP6R_STAT_TX_0                    (0x1UL << USB_EP6R_STAT_TX_Pos)   /*!< 0x00000010 */
#define USB_EP6R_STAT_TX_1                    (0x2UL << USB_EP6R_STAT_TX_Pos)   /*!< 0x00000020 */

#define USB_EP6R_DTOG_TX_Pos                  (6U)                             
#define USB_EP6R_DTOG_TX_Msk                  (0x1UL << USB_EP6R_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP6R_DTOG_TX                      USB_EP6R_DTOG_TX_Msk             /*!<Data Toggle, for transmission transfers */
#define USB_EP6R_CTR_TX_Pos                   (7U)                             
#define USB_EP6R_CTR_TX_Msk                   (0x1UL << USB_EP6R_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP6R_CTR_TX                       USB_EP6R_CTR_TX_Msk              /*!<Correct Transfer for transmission */
#define USB_EP6R_EP_KIND_Pos                  (8U)                             
#define USB_EP6R_EP_KIND_Msk                  (0x1UL << USB_EP6R_EP_KIND_Pos)   /*!< 0x00000100 */
#define USB_EP6R_EP_KIND                      USB_EP6R_EP_KIND_Msk             /*!<Endpoint Kind */

#define USB_EP6R_EP_TYPE_Pos                  (9U)                             
#define USB_EP6R_EP_TYPE_Msk                  (0x3UL << USB_EP6R_EP_TYPE_Pos)   /*!< 0x00000600 */
#define USB_EP6R_EP_TYPE                      USB_EP6R_EP_TYPE_Msk             /*!<EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP6R_EP_TYPE_0                    (0x1UL << USB_EP6R_EP_TYPE_Pos)   /*!< 0x00000200 */
#define USB_EP6R_EP_TYPE_1                    (0x2UL << USB_EP6R_EP_TYPE_Pos)   /*!< 0x00000400 */

#define USB_EP6R_SETUP_Pos                    (11U)                            
#define USB_EP6R_SETUP_Msk                    (0x1UL << USB_EP6R_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP6R_SETUP                        USB_EP6R_SETUP_Msk               /*!<Setup transaction completed */

#define USB_EP6R_STAT_RX_Pos                  (12U)                            
#define USB_EP6R_STAT_RX_Msk                  (0x3UL << USB_EP6R_STAT_RX_Pos)   /*!< 0x00003000 */
#define USB_EP6R_STAT_RX                      USB_EP6R_STAT_RX_Msk             /*!<STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP6R_STAT_RX_0                    (0x1UL << USB_EP6R_STAT_RX_Pos)   /*!< 0x00001000 */
#define USB_EP6R_STAT_RX_1                    (0x2UL << USB_EP6R_STAT_RX_Pos)   /*!< 0x00002000 */

#define USB_EP6R_DTOG_RX_Pos                  (14U)                            
#define USB_EP6R_DTOG_RX_Msk                  (0x1UL << USB_EP6R_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP6R_DTOG_RX                      USB_EP6R_DTOG_RX_Msk             /*!<Data Toggle, for reception transfers */
#define USB_EP6R_CTR_RX_Pos                   (15U)                            
#define USB_EP6R_CTR_RX_Msk                   (0x1UL << USB_EP6R_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP6R_CTR_RX                       USB_EP6R_CTR_RX_Msk              /*!<Correct Transfer for reception */

/*******************  Bit definition for USB_EP7R register  *******************/
#define USB_EP7R_EA_Pos                       (0U)                             
#define USB_EP7R_EA_Msk                       (0xFUL << USB_EP7R_EA_Pos)        /*!< 0x0000000F */
#define USB_EP7R_EA                           USB_EP7R_EA_Msk                  /*!<Endpoint Address */

#define USB_EP7R_STAT_TX_Pos                  (4U)                             
#define USB_EP7R_STAT_TX_Msk                  (0x3UL << USB_EP7R_STAT_TX_Pos)   /*!< 0x00000030 */
#define USB_EP7R_STAT_TX                      USB_EP7R_STAT_TX_Msk             /*!<STAT_TX[1:0] bits (Status bits, for transmission transfers) */
#define USB_EP7R_STAT_TX_0                    (0x1UL << USB_EP7R_STAT_TX_Pos)   /*!< 0x00000010 */
#define USB_EP7R_STAT_TX_1                    (0x2UL << USB_EP7R_STAT_TX_Pos)   /*!< 0x00000020 */

#define USB_EP7R_DTOG_TX_Pos                  (6U)                             
#define USB_EP7R_DTOG_TX_Msk                  (0x1UL << USB_EP7R_DTOG_TX_Pos)   /*!< 0x00000040 */
#define USB_EP7R_DTOG_TX                      USB_EP7R_DTOG_TX_Msk             /*!<Data Toggle, for transmission transfers */
#define USB_EP7R_CTR_TX_Pos                   (7U)                             
#define USB_EP7R_CTR_TX_Msk                   (0x1UL << USB_EP7R_CTR_TX_Pos)    /*!< 0x00000080 */
#define USB_EP7R_CTR_TX                       USB_EP7R_CTR_TX_Msk              /*!<Correct Transfer for transmission */
#define USB_EP7R_EP_KIND_Pos                  (8U)                             
#define USB_EP7R_EP_KIND_Msk                  (0x1UL << USB_EP7R_EP_KIND_Pos)   /*!< 0x00000100 */
#define USB_EP7R_EP_KIND                      USB_EP7R_EP_KIND_Msk             /*!<Endpoint Kind */

#define USB_EP7R_EP_TYPE_Pos                  (9U)                             
#define USB_EP7R_EP_TYPE_Msk                  (0x3UL << USB_EP7R_EP_TYPE_Pos)   /*!< 0x00000600 */
#define USB_EP7R_EP_TYPE                      USB_EP7R_EP_TYPE_Msk             /*!<EP_TYPE[1:0] bits (Endpoint type) */
#define USB_EP7R_EP_TYPE_0                    (0x1UL << USB_EP7R_EP_TYPE_Pos)   /*!< 0x00000200 */
#define USB_EP7R_EP_TYPE_1                    (0x2UL << USB_EP7R_EP_TYPE_Pos)   /*!< 0x00000400 */

#define USB_EP7R_SETUP_Pos                    (11U)                            
#define USB_EP7R_SETUP_Msk                    (0x1UL << USB_EP7R_SETUP_Pos)     /*!< 0x00000800 */
#define USB_EP7R_SETUP                        USB_EP7R_SETUP_Msk               /*!<Setup transaction completed */

#define USB_EP7R_STAT_RX_Pos                  (12U)                            
#define USB_EP7R_STAT_RX_Msk                  (0x3UL << USB_EP7R_STAT_RX_Pos)   /*!< 0x00003000 */
#define USB_EP7R_STAT_RX                      USB_EP7R_STAT_RX_Msk             /*!<STAT_RX[1:0] bits (Status bits, for reception transfers) */
#define USB_EP7R_STAT_RX_0                    (0x1UL << USB_EP7R_STAT_RX_Pos)   /*!< 0x00001000 */
#define USB_EP7R_STAT_RX_1                    (0x2UL << USB_EP7R_STAT_RX_Pos)   /*!< 0x00002000 */

#define USB_EP7R_DTOG_RX_Pos                  (14U)                            
#define USB_EP7R_DTOG_RX_Msk                  (0x1UL << USB_EP7R_DTOG_RX_Pos)   /*!< 0x00004000 */
#define USB_EP7R_DTOG_RX                      USB_EP7R_DTOG_RX_Msk             /*!<Data Toggle, for reception transfers */
#define USB_EP7R_CTR_RX_Pos                   (15U)                            
#define USB_EP7R_CTR_RX_Msk                   (0x1UL << USB_EP7R_CTR_RX_Pos)    /*!< 0x00008000 */
#define USB_EP7R_CTR_RX                       USB_EP7R_CTR_RX_Msk              /*!<Correct Transfer for reception */

/*!<Common registers */

#define  USB_CNTR                             (USB_BASE + 0x00000040U)          /*!< Control register */
#define  USB_ISTR                             (USB_BASE + 0x00000044U)          /*!< Interrupt status register */
#define  USB_FNR                              (USB_BASE + 0x00000048U)          /*!< Frame number register */
#define  USB_DADDR                            (USB_BASE + 0x0000004CU)          /*!< Device address register */
#define  USB_BTABLE                           (USB_BASE + 0x00000050U)          /*!< Buffer Table address register */



/*******************  Bit definition for USB_CNTR register  *******************/
#define USB_CNTR_FRES_Pos                     (0U)                             
#define USB_CNTR_FRES_Msk                     (0x1UL << USB_CNTR_FRES_Pos)      /*!< 0x00000001 */
#define USB_CNTR_FRES                         USB_CNTR_FRES_Msk                /*!<Force USB Reset */
#define USB_CNTR_PDWN_Pos                     (1U)                             
#define USB_CNTR_PDWN_Msk                     (0x1UL << USB_CNTR_PDWN_Pos)      /*!< 0x00000002 */
#define USB_CNTR_PDWN                         USB_CNTR_PDWN_Msk                /*!<Power down */
#define USB_CNTR_LPMODE_Pos                   (2U)                             
#define USB_CNTR_LPMODE_Msk                   (0x1UL << USB_CNTR_LPMODE_Pos)    /*!< 0x00000004 */
#define USB_CNTR_LPMODE                       USB_CNTR_LPMODE_Msk              /*!<Low-power mode */
#define USB_CNTR_FSUSP_Pos                    (3U)                             
#define USB_CNTR_FSUSP_Msk                    (0x1UL << USB_CNTR_FSUSP_Pos)     /*!< 0x00000008 */
#define USB_CNTR_FSUSP                        USB_CNTR_FSUSP_Msk               /*!<Force suspend */
#define USB_CNTR_RESUME_Pos                   (4U)                             
#define USB_CNTR_RESUME_Msk                   (0x1UL << USB_CNTR_RESUME_Pos)    /*!< 0x00000010 */
#define USB_CNTR_RESUME                       USB_CNTR_RESUME_Msk              /*!<Resume request */
#define USB_CNTR_ESOFM_Pos                    (8U)                             
#define USB_CNTR_ESOFM_Msk                    (0x1UL << USB_CNTR_ESOFM_Pos)     /*!< 0x00000100 */
#define USB_CNTR_ESOFM                        USB_CNTR_ESOFM_Msk               /*!<Expected Start Of Frame Interrupt Mask */
#define USB_CNTR_SOFM_Pos                     (9U)                             
#define USB_CNTR_SOFM_Msk                     (0x1UL << USB_CNTR_SOFM_Pos)      /*!< 0x00000200 */
#define USB_CNTR_SOFM                         USB_CNTR_SOFM_Msk                /*!<Start Of Frame Interrupt Mask */
#define USB_CNTR_RESETM_Pos                   (10U)                            
#define USB_CNTR_RESETM_Msk                   (0x1UL << USB_CNTR_RESETM_Pos)    /*!< 0x00000400 */
#define USB_CNTR_RESETM                       USB_CNTR_RESETM_Msk              /*!<RESET Interrupt Mask */
#define USB_CNTR_SUSPM_Pos                    (11U)                            
#define USB_CNTR_SUSPM_Msk                    (0x1UL << USB_CNTR_SUSPM_Pos)     /*!< 0x00000800 */
#define USB_CNTR_SUSPM                        USB_CNTR_SUSPM_Msk               /*!<Suspend mode Interrupt Mask */
#define USB_CNTR_WKUPM_Pos                    (12U)                            
#define USB_CNTR_WKUPM_Msk                    (0x1UL << USB_CNTR_WKUPM_Pos)     /*!< 0x00001000 */
#define USB_CNTR_WKUPM                        USB_CNTR_WKUPM_Msk               /*!<Wakeup Interrupt Mask */
#define USB_CNTR_ERRM_Pos                     (13U)                            
#define USB_CNTR_ERRM_Msk                     (0x1UL << USB_CNTR_ERRM_Pos)      /*!< 0x00002000 */
#define USB_CNTR_ERRM                         USB_CNTR_ERRM_Msk                /*!<Error Interrupt Mask */
#define USB_CNTR_PMAOVRM_Pos                  (14U)                            
#define USB_CNTR_PMAOVRM_Msk                  (0x1UL << USB_CNTR_PMAOVRM_Pos)   /*!< 0x00004000 */
#define USB_CNTR_PMAOVRM                      USB_CNTR_PMAOVRM_Msk             /*!<Packet Memory Area Over / Underrun Interrupt Mask */
#define USB_CNTR_CTRM_Pos                     (15U)                            
#define USB_CNTR_CTRM_Msk                     (0x1UL << USB_CNTR_CTRM_Pos)      /*!< 0x00008000 */
#define USB_CNTR_CTRM                         USB_CNTR_CTRM_Msk                /*!<Correct Transfer Interrupt Mask */

/*******************  Bit definition for USB_ISTR register  *******************/
#define USB_ISTR_EP_ID_Pos                    (0U)                             
#define USB_ISTR_EP_ID_Msk                    (0xFUL << USB_ISTR_EP_ID_Pos)     /*!< 0x0000000F */
#define USB_ISTR_EP_ID                        USB_ISTR_EP_ID_Msk               /*!<Endpoint Identifier */
#define USB_ISTR_DIR_Pos                      (4U)                             
#define USB_ISTR_DIR_Msk                      (0x1UL << USB_ISTR_DIR_Pos)       /*!< 0x00000010 */
#define USB_ISTR_DIR                          USB_ISTR_DIR_Msk                 /*!<Direction of transaction */
#define USB_ISTR_ESOF_Pos                     (8U)                             
#define USB_ISTR_ESOF_Msk                     (0x1UL << USB_ISTR_ESOF_Pos)      /*!< 0x00000100 */
#define USB_ISTR_ESOF                         USB_ISTR_ESOF_Msk                /*!<Expected Start Of Frame */
#define USB_ISTR_SOF_Pos                      (9U)                             
#define USB_ISTR_SOF_Msk                      (0x1UL << USB_ISTR_SOF_Pos)       /*!< 0x00000200 */
#define USB_ISTR_SOF                          USB_ISTR_SOF_Msk                 /*!<Start Of Frame */
#define USB_ISTR_RESET_Pos                    (10U)                            
#define USB_ISTR_RESET_Msk                    (0x1UL << USB_ISTR_RESET_Pos)     /*!< 0x00000400 */
#define USB_ISTR_RESET                        USB_ISTR_RESET_Msk               /*!<USB RESET request */
#define USB_ISTR_SUSP_Pos                     (11U)                            
#define USB_ISTR_SUSP_Msk                     (0x1UL << USB_ISTR_SUSP_Pos)      /*!< 0x00000800 */
#define USB_ISTR_SUSP                         USB_ISTR_SUSP_Msk                /*!<Suspend mode request */
#define USB_ISTR_WKUP_Pos                     (12U)                            
#define USB_ISTR_WKUP_Msk                     (0x1UL << USB_ISTR_WKUP_Pos)      /*!< 0x00001000 */
#define USB_ISTR_WKUP                         USB_ISTR_WKUP_Msk                /*!<Wake up */
#define USB_ISTR_ERR_Pos                      (13U)                            
#define USB_ISTR_ERR_Msk                      (0x1UL << USB_ISTR_ERR_Pos)       /*!< 0x00002000 */
#define USB_ISTR_ERR                          USB_ISTR_ERR_Msk                 /*!<Error */
#define USB_ISTR_PMAOVR_Pos                   (14U)                            
#define USB_ISTR_PMAOVR_Msk                   (0x1UL << USB_ISTR_PMAOVR_Pos)    /*!< 0x00004000 */
#define USB_ISTR_PMAOVR                       USB_ISTR_PMAOVR_Msk              /*!<Packet Memory Area Over / Underrun */
#define USB_ISTR_CTR_Pos                      (15U)                            
#define USB_ISTR_CTR_Msk                      (0x1UL << USB_ISTR_CTR_Pos)       /*!< 0x00008000 */
#define USB_ISTR_CTR                          USB_ISTR_CTR_Msk                 /*!<Correct Transfer */

#define  USB_CLR_CTR                          (~USB_ISTR_CTR)                  /*!< clear Correct TRansfer bit */
#define  USB_CLR_PMAOVRM                      (~USB_ISTR_PMAOVR)               /*!< clear DMA OVeR/underrun bit*/
#define  USB_CLR_ERR                          (~USB_ISTR_ERR)                  /*!< clear ERRor bit */
#define  USB_CLR_WKUP                         (~USB_ISTR_WKUP)                 /*!< clear WaKe UP bit */
#define  USB_CLR_SUSP                         (~USB_ISTR_SUSP)                 /*!< clear SUSPend bit */
#define  USB_CLR_RESET                        (~USB_ISTR_RESET)                /*!< clear RESET bit */
#define  USB_CLR_SOF                          (~USB_ISTR_SOF)                  /*!< clear Start Of Frame bit */
#define  USB_CLR_ESOF                         (~USB_ISTR_ESOF)                 /*!< clear Expected Start Of Frame bit */


/*******************  Bit definition for USB_FNR register  ********************/
#define USB_FNR_FN_Pos                        (0U)                             
#define USB_FNR_FN_Msk                        (0x7FFUL << USB_FNR_FN_Pos)       /*!< 0x000007FF */
#define USB_FNR_FN                            USB_FNR_FN_Msk                   /*!<Frame Number */
#define USB_FNR_LSOF_Pos                      (11U)                            
#define USB_FNR_LSOF_Msk                      (0x3UL << USB_FNR_LSOF_Pos)       /*!< 0x00001800 */
#define USB_FNR_LSOF                          USB_FNR_LSOF_Msk                 /*!<Lost SOF */
#define USB_FNR_LCK_Pos                       (13U)                            
#define USB_FNR_LCK_Msk                       (0x1UL << USB_FNR_LCK_Pos)        /*!< 0x00002000 */
#define USB_FNR_LCK                           USB_FNR_LCK_Msk                  /*!<Locked */
#define USB_FNR_RXDM_Pos                      (14U)                            
#define USB_FNR_RXDM_Msk                      (0x1UL << USB_FNR_RXDM_Pos)       /*!< 0x00004000 */
#define USB_FNR_RXDM                          USB_FNR_RXDM_Msk                 /*!<Receive Data - Line Status */
#define USB_FNR_RXDP_Pos                      (15U)                            
#define USB_FNR_RXDP_Msk                      (0x1UL << USB_FNR_RXDP_Pos)       /*!< 0x00008000 */
#define USB_FNR_RXDP                          USB_FNR_RXDP_Msk                 /*!<Receive Data + Line Status */

/******************  Bit definition for USB_DADDR register  *******************/
#define USB_DADDR_ADD_Pos                     (0U)                             
#define USB_DADDR_ADD_Msk                     (0x7FUL << USB_DADDR_ADD_Pos)     /*!< 0x0000007F */
#define USB_DADDR_ADD                         USB_DADDR_ADD_Msk                /*!<ADD[6:0] bits (Device Address) */
#define USB_DADDR_ADD0_Pos                    (0U)                             
#define USB_DADDR_ADD0_Msk                    (0x1UL << USB_DADDR_ADD0_Pos)     /*!< 0x00000001 */
#define USB_DADDR_ADD0                        USB_DADDR_ADD0_Msk               /*!<Bit 0 */
#define USB_DADDR_ADD1_Pos                    (1U)                             
#define USB_DADDR_ADD1_Msk                    (0x1UL << USB_DADDR_ADD1_Pos)     /*!< 0x00000002 */
#define USB_DADDR_ADD1                        USB_DADDR_ADD1_Msk               /*!<Bit 1 */
#define USB_DADDR_ADD2_Pos                    (2U)                             
#define USB_DADDR_ADD2_Msk                    (0x1UL << USB_DADDR_ADD2_Pos)     /*!< 0x00000004 */
#define USB_DADDR_ADD2                        USB_DADDR_ADD2_Msk               /*!<Bit 2 */
#define USB_DADDR_ADD3_Pos                    (3U)                             
#define USB_DADDR_ADD3_Msk                    (0x1UL << USB_DADDR_ADD3_Pos)     /*!< 0x00000008 */
#define USB_DADDR_ADD3                        USB_DADDR_ADD3_Msk               /*!<Bit 3 */
#define USB_DADDR_ADD4_Pos                    (4U)                             
#define USB_DADDR_ADD4_Msk                    (0x1UL << USB_DADDR_ADD4_Pos)     /*!< 0x00000010 */
#define USB_DADDR_ADD4                        USB_DADDR_ADD4_Msk               /*!<Bit 4 */
#define USB_DADDR_ADD5_Pos                    (5U)                             
#define USB_DADDR_ADD5_Msk                    (0x1UL << USB_DADDR_ADD5_Pos)     /*!< 0x00000020 */
#define USB_DADDR_ADD5                        USB_DADDR_ADD5_Msk               /*!<Bit 5 */
#define USB_DADDR_ADD6_Pos                    (6U)                             
#define USB_DADDR_ADD6_Msk                    (0x1UL << USB_DADDR_ADD6_Pos)     /*!< 0x00000040 */
#define USB_DADDR_ADD6                        USB_DADDR_ADD6_Msk               /*!<Bit 6 */

#define USB_DADDR_EF_Pos                      (7U)                             
#define USB_DADDR_EF_Msk                      (0x1UL << USB_DADDR_EF_Pos)       /*!< 0x00000080 */
#define USB_DADDR_EF                          USB_DADDR_EF_Msk                 /*!<Enable Function */

/******************  Bit definition for USB_BTABLE register  ******************/    
#define USB_BTABLE_BTABLE_Pos                 (3U)                             
#define USB_BTABLE_BTABLE_Msk                 (0x1FFFUL << USB_BTABLE_BTABLE_Pos) /*!< 0x0000FFF8 */
#define USB_BTABLE_BTABLE                     USB_BTABLE_BTABLE_Msk            /*!<Buffer Table */

/*!< Buffer descriptor table */
/*****************  Bit definition for USB_ADDR0_TX register  *****************/
#define USB_ADDR0_TX_ADDR0_TX_Pos             (1U)                             
#define USB_ADDR0_TX_ADDR0_TX_Msk             (0x7FFFUL << USB_ADDR0_TX_ADDR0_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR0_TX_ADDR0_TX                 USB_ADDR0_TX_ADDR0_TX_Msk        /*!< Transmission Buffer Address 0 */

/*****************  Bit definition for USB_ADDR1_TX register  *****************/
#define USB_ADDR1_TX_ADDR1_TX_Pos             (1U)                             
#define USB_ADDR1_TX_ADDR1_TX_Msk             (0x7FFFUL << USB_ADDR1_TX_ADDR1_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR1_TX_ADDR1_TX                 USB_ADDR1_TX_ADDR1_TX_Msk        /*!< Transmission Buffer Address 1 */

/*****************  Bit definition for USB_ADDR2_TX register  *****************/
#define USB_ADDR2_TX_ADDR2_TX_Pos             (1U)                             
#define USB_ADDR2_TX_ADDR2_TX_Msk             (0x7FFFUL << USB_ADDR2_TX_ADDR2_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR2_TX_ADDR2_TX                 USB_ADDR2_TX_ADDR2_TX_Msk        /*!< Transmission Buffer Address 2 */

/*****************  Bit definition for USB_ADDR3_TX register  *****************/
#define USB_ADDR3_TX_ADDR3_TX_Pos             (1U)                             
#define USB_ADDR3_TX_ADDR3_TX_Msk             (0x7FFFUL << USB_ADDR3_TX_ADDR3_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR3_TX_ADDR3_TX                 USB_ADDR3_TX_ADDR3_TX_Msk        /*!< Transmission Buffer Address 3 */

/*****************  Bit definition for USB_ADDR4_TX register  *****************/
#define USB_ADDR4_TX_ADDR4_TX_Pos             (1U)                             
#define USB_ADDR4_TX_ADDR4_TX_Msk             (0x7FFFUL << USB_ADDR4_TX_ADDR4_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR4_TX_ADDR4_TX                 USB_ADDR4_TX_ADDR4_TX_Msk        /*!< Transmission Buffer Address 4 */

/*****************  Bit definition for USB_ADDR5_TX register  *****************/
#define USB_ADDR5_TX_ADDR5_TX_Pos             (1U)                             
#define USB_ADDR5_TX_ADDR5_TX_Msk             (0x7FFFUL << USB_ADDR5_TX_ADDR5_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR5_TX_ADDR5_TX                 USB_ADDR5_TX_ADDR5_TX_Msk        /*!< Transmission Buffer Address 5 */

/*****************  Bit definition for USB_ADDR6_TX register  *****************/
#define USB_ADDR6_TX_ADDR6_TX_Pos             (1U)                             
#define USB_ADDR6_TX_ADDR6_TX_Msk             (0x7FFFUL << USB_ADDR6_TX_ADDR6_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR6_TX_ADDR6_TX                 USB_ADDR6_TX_ADDR6_TX_Msk        /*!< Transmission Buffer Address 6 */

/*****************  Bit definition for USB_ADDR7_TX register  *****************/
#define USB_ADDR7_TX_ADDR7_TX_Pos             (1U)                             
#define USB_ADDR7_TX_ADDR7_TX_Msk             (0x7FFFUL << USB_ADDR7_TX_ADDR7_TX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR7_TX_ADDR7_TX                 USB_ADDR7_TX_ADDR7_TX_Msk        /*!< Transmission Buffer Address 7 */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_COUNT0_TX register  ****************/
#define USB_COUNT0_TX_COUNT0_TX_Pos           (0U)                             
#define USB_COUNT0_TX_COUNT0_TX_Msk           (0x3FFUL << USB_COUNT0_TX_COUNT0_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT0_TX_COUNT0_TX               USB_COUNT0_TX_COUNT0_TX_Msk      /*!< Transmission Byte Count 0 */

/*****************  Bit definition for USB_COUNT1_TX register  ****************/
#define USB_COUNT1_TX_COUNT1_TX_Pos           (0U)                             
#define USB_COUNT1_TX_COUNT1_TX_Msk           (0x3FFUL << USB_COUNT1_TX_COUNT1_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT1_TX_COUNT1_TX               USB_COUNT1_TX_COUNT1_TX_Msk      /*!< Transmission Byte Count 1 */

/*****************  Bit definition for USB_COUNT2_TX register  ****************/
#define USB_COUNT2_TX_COUNT2_TX_Pos           (0U)                             
#define USB_COUNT2_TX_COUNT2_TX_Msk           (0x3FFUL << USB_COUNT2_TX_COUNT2_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT2_TX_COUNT2_TX               USB_COUNT2_TX_COUNT2_TX_Msk      /*!< Transmission Byte Count 2 */

/*****************  Bit definition for USB_COUNT3_TX register  ****************/
#define USB_COUNT3_TX_COUNT3_TX_Pos           (0U)                             
#define USB_COUNT3_TX_COUNT3_TX_Msk           (0x3FFUL << USB_COUNT3_TX_COUNT3_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT3_TX_COUNT3_TX               USB_COUNT3_TX_COUNT3_TX_Msk      /*!< Transmission Byte Count 3 */

/*****************  Bit definition for USB_COUNT4_TX register  ****************/
#define USB_COUNT4_TX_COUNT4_TX_Pos           (0U)                             
#define USB_COUNT4_TX_COUNT4_TX_Msk           (0x3FFUL << USB_COUNT4_TX_COUNT4_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT4_TX_COUNT4_TX               USB_COUNT4_TX_COUNT4_TX_Msk      /*!< Transmission Byte Count 4 */

/*****************  Bit definition for USB_COUNT5_TX register  ****************/
#define USB_COUNT5_TX_COUNT5_TX_Pos           (0U)                             
#define USB_COUNT5_TX_COUNT5_TX_Msk           (0x3FFUL << USB_COUNT5_TX_COUNT5_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT5_TX_COUNT5_TX               USB_COUNT5_TX_COUNT5_TX_Msk      /*!< Transmission Byte Count 5 */

/*****************  Bit definition for USB_COUNT6_TX register  ****************/
#define USB_COUNT6_TX_COUNT6_TX_Pos           (0U)                             
#define USB_COUNT6_TX_COUNT6_TX_Msk           (0x3FFUL << USB_COUNT6_TX_COUNT6_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT6_TX_COUNT6_TX               USB_COUNT6_TX_COUNT6_TX_Msk      /*!< Transmission Byte Count 6 */

/*****************  Bit definition for USB_COUNT7_TX register  ****************/
#define USB_COUNT7_TX_COUNT7_TX_Pos           (0U)                             
#define USB_COUNT7_TX_COUNT7_TX_Msk           (0x3FFUL << USB_COUNT7_TX_COUNT7_TX_Pos) /*!< 0x000003FF */
#define USB_COUNT7_TX_COUNT7_TX               USB_COUNT7_TX_COUNT7_TX_Msk      /*!< Transmission Byte Count 7 */

/*----------------------------------------------------------------------------*/

/****************  Bit definition for USB_COUNT0_TX_0 register  ***************/
#define USB_COUNT0_TX_0_COUNT0_TX_0           (0x000003FFU)                    /*!< Transmission Byte Count 0 (low) */

/****************  Bit definition for USB_COUNT0_TX_1 register  ***************/
#define USB_COUNT0_TX_1_COUNT0_TX_1           (0x03FF0000U)                    /*!< Transmission Byte Count 0 (high) */

/****************  Bit definition for USB_COUNT1_TX_0 register  ***************/
#define USB_COUNT1_TX_0_COUNT1_TX_0           (0x000003FFU)                    /*!< Transmission Byte Count 1 (low) */

/****************  Bit definition for USB_COUNT1_TX_1 register  ***************/
#define USB_COUNT1_TX_1_COUNT1_TX_1           (0x03FF0000U)                    /*!< Transmission Byte Count 1 (high) */

/****************  Bit definition for USB_COUNT2_TX_0 register  ***************/
#define USB_COUNT2_TX_0_COUNT2_TX_0           (0x000003FFU)                    /*!< Transmission Byte Count 2 (low) */

/****************  Bit definition for USB_COUNT2_TX_1 register  ***************/
#define USB_COUNT2_TX_1_COUNT2_TX_1           (0x03FF0000U)                    /*!< Transmission Byte Count 2 (high) */

/****************  Bit definition for USB_COUNT3_TX_0 register  ***************/
#define USB_COUNT3_TX_0_COUNT3_TX_0           (0x000003FFU)                    /*!< Transmission Byte Count 3 (low) */

/****************  Bit definition for USB_COUNT3_TX_1 register  ***************/
#define USB_COUNT3_TX_1_COUNT3_TX_1           (0x03FF0000U)                    /*!< Transmission Byte Count 3 (high) */

/****************  Bit definition for USB_COUNT4_TX_0 register  ***************/
#define USB_COUNT4_TX_0_COUNT4_TX_0           (0x000003FFU)                    /*!< Transmission Byte Count 4 (low) */

/****************  Bit definition for USB_COUNT4_TX_1 register  ***************/
#define USB_COUNT4_TX_1_COUNT4_TX_1           (0x03FF0000U)                    /*!< Transmission Byte Count 4 (high) */

/****************  Bit definition for USB_COUNT5_TX_0 register  ***************/
#define USB_COUNT5_TX_0_COUNT5_TX_0           (0x000003FFU)                    /*!< Transmission Byte Count 5 (low) */

/****************  Bit definition for USB_COUNT5_TX_1 register  ***************/
#define USB_COUNT5_TX_1_COUNT5_TX_1           (0x03FF0000U)                    /*!< Transmission Byte Count 5 (high) */

/****************  Bit definition for USB_COUNT6_TX_0 register  ***************/
#define USB_COUNT6_TX_0_COUNT6_TX_0           (0x000003FFU)                    /*!< Transmission Byte Count 6 (low) */

/****************  Bit definition for USB_COUNT6_TX_1 register  ***************/
#define USB_COUNT6_TX_1_COUNT6_TX_1           (0x03FF0000U)                    /*!< Transmission Byte Count 6 (high) */

/****************  Bit definition for USB_COUNT7_TX_0 register  ***************/
#define USB_COUNT7_TX_0_COUNT7_TX_0           (0x000003FFU)                    /*!< Transmission Byte Count 7 (low) */

/****************  Bit definition for USB_COUNT7_TX_1 register  ***************/
#define USB_COUNT7_TX_1_COUNT7_TX_1           (0x03FF0000U)                    /*!< Transmission Byte Count 7 (high) */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_ADDR0_RX register  *****************/
#define USB_ADDR0_RX_ADDR0_RX_Pos             (1U)                             
#define USB_ADDR0_RX_ADDR0_RX_Msk             (0x7FFFUL << USB_ADDR0_RX_ADDR0_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR0_RX_ADDR0_RX                 USB_ADDR0_RX_ADDR0_RX_Msk        /*!< Reception Buffer Address 0 */

/*****************  Bit definition for USB_ADDR1_RX register  *****************/
#define USB_ADDR1_RX_ADDR1_RX_Pos             (1U)                             
#define USB_ADDR1_RX_ADDR1_RX_Msk             (0x7FFFUL << USB_ADDR1_RX_ADDR1_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR1_RX_ADDR1_RX                 USB_ADDR1_RX_ADDR1_RX_Msk        /*!< Reception Buffer Address 1 */

/*****************  Bit definition for USB_ADDR2_RX register  *****************/
#define USB_ADDR2_RX_ADDR2_RX_Pos             (1U)                             
#define USB_ADDR2_RX_ADDR2_RX_Msk             (0x7FFFUL << USB_ADDR2_RX_ADDR2_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR2_RX_ADDR2_RX                 USB_ADDR2_RX_ADDR2_RX_Msk        /*!< Reception Buffer Address 2 */

/*****************  Bit definition for USB_ADDR3_RX register  *****************/
#define USB_ADDR3_RX_ADDR3_RX_Pos             (1U)                             
#define USB_ADDR3_RX_ADDR3_RX_Msk             (0x7FFFUL << USB_ADDR3_RX_ADDR3_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR3_RX_ADDR3_RX                 USB_ADDR3_RX_ADDR3_RX_Msk        /*!< Reception Buffer Address 3 */

/*****************  Bit definition for USB_ADDR4_RX register  *****************/
#define USB_ADDR4_RX_ADDR4_RX_Pos             (1U)                             
#define USB_ADDR4_RX_ADDR4_RX_Msk             (0x7FFFUL << USB_ADDR4_RX_ADDR4_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR4_RX_ADDR4_RX                 USB_ADDR4_RX_ADDR4_RX_Msk        /*!< Reception Buffer Address 4 */

/*****************  Bit definition for USB_ADDR5_RX register  *****************/
#define USB_ADDR5_RX_ADDR5_RX_Pos             (1U)                             
#define USB_ADDR5_RX_ADDR5_RX_Msk             (0x7FFFUL << USB_ADDR5_RX_ADDR5_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR5_RX_ADDR5_RX                 USB_ADDR5_RX_ADDR5_RX_Msk        /*!< Reception Buffer Address 5 */

/*****************  Bit definition for USB_ADDR6_RX register  *****************/
#define USB_ADDR6_RX_ADDR6_RX_Pos             (1U)                             
#define USB_ADDR6_RX_ADDR6_RX_Msk             (0x7FFFUL << USB_ADDR6_RX_ADDR6_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR6_RX_ADDR6_RX                 USB_ADDR6_RX_ADDR6_RX_Msk        /*!< Reception Buffer Address 6 */

/*****************  Bit definition for USB_ADDR7_RX register  *****************/
#define USB_ADDR7_RX_ADDR7_RX_Pos             (1U)                             
#define USB_ADDR7_RX_ADDR7_RX_Msk             (0x7FFFUL << USB_ADDR7_RX_ADDR7_RX_Pos) /*!< 0x0000FFFE */
#define USB_ADDR7_RX_ADDR7_RX                 USB_ADDR7_RX_ADDR7_RX_Msk        /*!< Reception Buffer Address 7 */

/*----------------------------------------------------------------------------*/

/*****************  Bit definition for USB_COUNT0_RX register  ****************/
#define USB_COUNT0_RX_COUNT0_RX_Pos           (0U)                             
#define USB_COUNT0_RX_COUNT0_RX_Msk           (0x3FFUL << USB_COUNT0_RX_COUNT0_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT0_RX_COUNT0_RX               USB_COUNT0_RX_COUNT0_RX_Msk      /*!< Reception Byte Count */

#define USB_COUNT0_RX_NUM_BLOCK_Pos           (10U)                            
#define USB_COUNT0_RX_NUM_BLOCK_Msk           (0x1FUL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT0_RX_NUM_BLOCK               USB_COUNT0_RX_NUM_BLOCK_Msk      /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT0_RX_NUM_BLOCK_0             (0x01UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT0_RX_NUM_BLOCK_1             (0x02UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT0_RX_NUM_BLOCK_2             (0x04UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT0_RX_NUM_BLOCK_3             (0x08UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT0_RX_NUM_BLOCK_4             (0x10UL << USB_COUNT0_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT0_RX_BLSIZE_Pos              (15U)                            
#define USB_COUNT0_RX_BLSIZE_Msk              (0x1UL << USB_COUNT0_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT0_RX_BLSIZE                  USB_COUNT0_RX_BLSIZE_Msk         /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT1_RX register  ****************/
#define USB_COUNT1_RX_COUNT1_RX_Pos           (0U)                             
#define USB_COUNT1_RX_COUNT1_RX_Msk           (0x3FFUL << USB_COUNT1_RX_COUNT1_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT1_RX_COUNT1_RX               USB_COUNT1_RX_COUNT1_RX_Msk      /*!< Reception Byte Count */

#define USB_COUNT1_RX_NUM_BLOCK_Pos           (10U)                            
#define USB_COUNT1_RX_NUM_BLOCK_Msk           (0x1FUL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT1_RX_NUM_BLOCK               USB_COUNT1_RX_NUM_BLOCK_Msk      /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT1_RX_NUM_BLOCK_0             (0x01UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT1_RX_NUM_BLOCK_1             (0x02UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT1_RX_NUM_BLOCK_2             (0x04UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT1_RX_NUM_BLOCK_3             (0x08UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT1_RX_NUM_BLOCK_4             (0x10UL << USB_COUNT1_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT1_RX_BLSIZE_Pos              (15U)                            
#define USB_COUNT1_RX_BLSIZE_Msk              (0x1UL << USB_COUNT1_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT1_RX_BLSIZE                  USB_COUNT1_RX_BLSIZE_Msk         /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT2_RX register  ****************/
#define USB_COUNT2_RX_COUNT2_RX_Pos           (0U)                             
#define USB_COUNT2_RX_COUNT2_RX_Msk           (0x3FFUL << USB_COUNT2_RX_COUNT2_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT2_RX_COUNT2_RX               USB_COUNT2_RX_COUNT2_RX_Msk      /*!< Reception Byte Count */

#define USB_COUNT2_RX_NUM_BLOCK_Pos           (10U)                            
#define USB_COUNT2_RX_NUM_BLOCK_Msk           (0x1FUL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT2_RX_NUM_BLOCK               USB_COUNT2_RX_NUM_BLOCK_Msk      /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT2_RX_NUM_BLOCK_0             (0x01UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT2_RX_NUM_BLOCK_1             (0x02UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT2_RX_NUM_BLOCK_2             (0x04UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT2_RX_NUM_BLOCK_3             (0x08UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT2_RX_NUM_BLOCK_4             (0x10UL << USB_COUNT2_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT2_RX_BLSIZE_Pos              (15U)                            
#define USB_COUNT2_RX_BLSIZE_Msk              (0x1UL << USB_COUNT2_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT2_RX_BLSIZE                  USB_COUNT2_RX_BLSIZE_Msk         /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT3_RX register  ****************/
#define USB_COUNT3_RX_COUNT3_RX_Pos           (0U)                             
#define USB_COUNT3_RX_COUNT3_RX_Msk           (0x3FFUL << USB_COUNT3_RX_COUNT3_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT3_RX_COUNT3_RX               USB_COUNT3_RX_COUNT3_RX_Msk      /*!< Reception Byte Count */

#define USB_COUNT3_RX_NUM_BLOCK_Pos           (10U)                            
#define USB_COUNT3_RX_NUM_BLOCK_Msk           (0x1FUL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT3_RX_NUM_BLOCK               USB_COUNT3_RX_NUM_BLOCK_Msk      /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT3_RX_NUM_BLOCK_0             (0x01UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT3_RX_NUM_BLOCK_1             (0x02UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT3_RX_NUM_BLOCK_2             (0x04UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT3_RX_NUM_BLOCK_3             (0x08UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT3_RX_NUM_BLOCK_4             (0x10UL << USB_COUNT3_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT3_RX_BLSIZE_Pos              (15U)                            
#define USB_COUNT3_RX_BLSIZE_Msk              (0x1UL << USB_COUNT3_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT3_RX_BLSIZE                  USB_COUNT3_RX_BLSIZE_Msk         /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT4_RX register  ****************/
#define USB_COUNT4_RX_COUNT4_RX_Pos           (0U)                             
#define USB_COUNT4_RX_COUNT4_RX_Msk           (0x3FFUL << USB_COUNT4_RX_COUNT4_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT4_RX_COUNT4_RX               USB_COUNT4_RX_COUNT4_RX_Msk      /*!< Reception Byte Count */

#define USB_COUNT4_RX_NUM_BLOCK_Pos           (10U)                            
#define USB_COUNT4_RX_NUM_BLOCK_Msk           (0x1FUL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT4_RX_NUM_BLOCK               USB_COUNT4_RX_NUM_BLOCK_Msk      /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT4_RX_NUM_BLOCK_0             (0x01UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT4_RX_NUM_BLOCK_1             (0x02UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT4_RX_NUM_BLOCK_2             (0x04UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT4_RX_NUM_BLOCK_3             (0x08UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT4_RX_NUM_BLOCK_4             (0x10UL << USB_COUNT4_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT4_RX_BLSIZE_Pos              (15U)                            
#define USB_COUNT4_RX_BLSIZE_Msk              (0x1UL << USB_COUNT4_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT4_RX_BLSIZE                  USB_COUNT4_RX_BLSIZE_Msk         /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT5_RX register  ****************/
#define USB_COUNT5_RX_COUNT5_RX_Pos           (0U)                             
#define USB_COUNT5_RX_COUNT5_RX_Msk           (0x3FFUL << USB_COUNT5_RX_COUNT5_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT5_RX_COUNT5_RX               USB_COUNT5_RX_COUNT5_RX_Msk      /*!< Reception Byte Count */

#define USB_COUNT5_RX_NUM_BLOCK_Pos           (10U)                            
#define USB_COUNT5_RX_NUM_BLOCK_Msk           (0x1FUL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT5_RX_NUM_BLOCK               USB_COUNT5_RX_NUM_BLOCK_Msk      /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT5_RX_NUM_BLOCK_0             (0x01UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT5_RX_NUM_BLOCK_1             (0x02UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT5_RX_NUM_BLOCK_2             (0x04UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT5_RX_NUM_BLOCK_3             (0x08UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT5_RX_NUM_BLOCK_4             (0x10UL << USB_COUNT5_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT5_RX_BLSIZE_Pos              (15U)                            
#define USB_COUNT5_RX_BLSIZE_Msk              (0x1UL << USB_COUNT5_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT5_RX_BLSIZE                  USB_COUNT5_RX_BLSIZE_Msk         /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT6_RX register  ****************/
#define USB_COUNT6_RX_COUNT6_RX_Pos           (0U)                             
#define USB_COUNT6_RX_COUNT6_RX_Msk           (0x3FFUL << USB_COUNT6_RX_COUNT6_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT6_RX_COUNT6_RX               USB_COUNT6_RX_COUNT6_RX_Msk      /*!< Reception Byte Count */

#define USB_COUNT6_RX_NUM_BLOCK_Pos           (10U)                            
#define USB_COUNT6_RX_NUM_BLOCK_Msk           (0x1FUL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT6_RX_NUM_BLOCK               USB_COUNT6_RX_NUM_BLOCK_Msk      /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT6_RX_NUM_BLOCK_0             (0x01UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT6_RX_NUM_BLOCK_1             (0x02UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT6_RX_NUM_BLOCK_2             (0x04UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT6_RX_NUM_BLOCK_3             (0x08UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT6_RX_NUM_BLOCK_4             (0x10UL << USB_COUNT6_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT6_RX_BLSIZE_Pos              (15U)                            
#define USB_COUNT6_RX_BLSIZE_Msk              (0x1UL << USB_COUNT6_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT6_RX_BLSIZE                  USB_COUNT6_RX_BLSIZE_Msk         /*!< BLock SIZE */

/*****************  Bit definition for USB_COUNT7_RX register  ****************/
#define USB_COUNT7_RX_COUNT7_RX_Pos           (0U)                             
#define USB_COUNT7_RX_COUNT7_RX_Msk           (0x3FFUL << USB_COUNT7_RX_COUNT7_RX_Pos) /*!< 0x000003FF */
#define USB_COUNT7_RX_COUNT7_RX               USB_COUNT7_RX_COUNT7_RX_Msk      /*!< Reception Byte Count */

#define USB_COUNT7_RX_NUM_BLOCK_Pos           (10U)                            
#define USB_COUNT7_RX_NUM_BLOCK_Msk           (0x1FUL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00007C00 */
#define USB_COUNT7_RX_NUM_BLOCK               USB_COUNT7_RX_NUM_BLOCK_Msk      /*!< NUM_BLOCK[4:0] bits (Number of blocks) */
#define USB_COUNT7_RX_NUM_BLOCK_0             (0x01UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00000400 */
#define USB_COUNT7_RX_NUM_BLOCK_1             (0x02UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00000800 */
#define USB_COUNT7_RX_NUM_BLOCK_2             (0x04UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00001000 */
#define USB_COUNT7_RX_NUM_BLOCK_3             (0x08UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00002000 */
#define USB_COUNT7_RX_NUM_BLOCK_4             (0x10UL << USB_COUNT7_RX_NUM_BLOCK_Pos) /*!< 0x00004000 */

#define USB_COUNT7_RX_BLSIZE_Pos              (15U)                            
#define USB_COUNT7_RX_BLSIZE_Msk              (0x1UL << USB_COUNT7_RX_BLSIZE_Pos) /*!< 0x00008000 */
#define USB_COUNT7_RX_BLSIZE                  USB_COUNT7_RX_BLSIZE_Msk         /*!< BLock SIZE */

/*----------------------------------------------------------------------------*/

/****************  Bit definition for USB_COUNT0_RX_0 register  ***************/
#define USB_COUNT0_RX_0_COUNT0_RX_0           (0x000003FFU)                    /*!< Reception Byte Count (low) */

#define USB_COUNT0_RX_0_NUM_BLOCK_0           (0x00007C00U)                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_0         (0x00000400U)                    /*!< Bit 0 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_1         (0x00000800U)                    /*!< Bit 1 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_2         (0x00001000U)                    /*!< Bit 2 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_3         (0x00002000U)                    /*!< Bit 3 */
#define USB_COUNT0_RX_0_NUM_BLOCK_0_4         (0x00004000U)                    /*!< Bit 4 */

#define USB_COUNT0_RX_0_BLSIZE_0              (0x00008000U)                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT0_RX_1 register  ***************/
#define USB_COUNT0_RX_1_COUNT0_RX_1           (0x03FF0000U)                    /*!< Reception Byte Count (high) */

#define USB_COUNT0_RX_1_NUM_BLOCK_1           (0x7C000000U)                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_0         (0x04000000U)                    /*!< Bit 1 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_1         (0x08000000U)                    /*!< Bit 1 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_2         (0x10000000U)                    /*!< Bit 2 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_3         (0x20000000U)                    /*!< Bit 3 */
#define USB_COUNT0_RX_1_NUM_BLOCK_1_4         (0x40000000U)                    /*!< Bit 4 */

#define USB_COUNT0_RX_1_BLSIZE_1              (0x80000000U)                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT1_RX_0 register  ***************/
#define USB_COUNT1_RX_0_COUNT1_RX_0           (0x000003FFU)                    /*!< Reception Byte Count (low) */

#define USB_COUNT1_RX_0_NUM_BLOCK_0           (0x00007C00U)                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_0         (0x00000400U)                    /*!< Bit 0 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_1         (0x00000800U)                    /*!< Bit 1 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_2         (0x00001000U)                    /*!< Bit 2 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_3         (0x00002000U)                    /*!< Bit 3 */
#define USB_COUNT1_RX_0_NUM_BLOCK_0_4         (0x00004000U)                    /*!< Bit 4 */

#define USB_COUNT1_RX_0_BLSIZE_0              (0x00008000U)                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT1_RX_1 register  ***************/
#define USB_COUNT1_RX_1_COUNT1_RX_1           (0x03FF0000U)                    /*!< Reception Byte Count (high) */

#define USB_COUNT1_RX_1_NUM_BLOCK_1           (0x7C000000U)                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_0         (0x04000000U)                    /*!< Bit 0 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_1         (0x08000000U)                    /*!< Bit 1 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_2         (0x10000000U)                    /*!< Bit 2 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_3         (0x20000000U)                    /*!< Bit 3 */
#define USB_COUNT1_RX_1_NUM_BLOCK_1_4         (0x40000000U)                    /*!< Bit 4 */

#define USB_COUNT1_RX_1_BLSIZE_1              (0x80000000U)                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT2_RX_0 register  ***************/
#define USB_COUNT2_RX_0_COUNT2_RX_0           (0x000003FFU)                    /*!< Reception Byte Count (low) */

#define USB_COUNT2_RX_0_NUM_BLOCK_0           (0x00007C00U)                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_0         (0x00000400U)                    /*!< Bit 0 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_1         (0x00000800U)                    /*!< Bit 1 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_2         (0x00001000U)                    /*!< Bit 2 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_3         (0x00002000U)                    /*!< Bit 3 */
#define USB_COUNT2_RX_0_NUM_BLOCK_0_4         (0x00004000U)                    /*!< Bit 4 */

#define USB_COUNT2_RX_0_BLSIZE_0              (0x00008000U)                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT2_RX_1 register  ***************/
#define USB_COUNT2_RX_1_COUNT2_RX_1           (0x03FF0000U)                    /*!< Reception Byte Count (high) */

#define USB_COUNT2_RX_1_NUM_BLOCK_1           (0x7C000000U)                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_0         (0x04000000U)                    /*!< Bit 0 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_1         (0x08000000U)                    /*!< Bit 1 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_2         (0x10000000U)                    /*!< Bit 2 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_3         (0x20000000U)                    /*!< Bit 3 */
#define USB_COUNT2_RX_1_NUM_BLOCK_1_4         (0x40000000U)                    /*!< Bit 4 */

#define USB_COUNT2_RX_1_BLSIZE_1              (0x80000000U)                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT3_RX_0 register  ***************/
#define USB_COUNT3_RX_0_COUNT3_RX_0           (0x000003FFU)                    /*!< Reception Byte Count (low) */

#define USB_COUNT3_RX_0_NUM_BLOCK_0           (0x00007C00U)                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_0         (0x00000400U)                    /*!< Bit 0 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_1         (0x00000800U)                    /*!< Bit 1 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_2         (0x00001000U)                    /*!< Bit 2 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_3         (0x00002000U)                    /*!< Bit 3 */
#define USB_COUNT3_RX_0_NUM_BLOCK_0_4         (0x00004000U)                    /*!< Bit 4 */

#define USB_COUNT3_RX_0_BLSIZE_0              (0x00008000U)                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT3_RX_1 register  ***************/
#define USB_COUNT3_RX_1_COUNT3_RX_1           (0x03FF0000U)                    /*!< Reception Byte Count (high) */

#define USB_COUNT3_RX_1_NUM_BLOCK_1           (0x7C000000U)                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_0         (0x04000000U)                    /*!< Bit 0 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_1         (0x08000000U)                    /*!< Bit 1 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_2         (0x10000000U)                    /*!< Bit 2 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_3         (0x20000000U)                    /*!< Bit 3 */
#define USB_COUNT3_RX_1_NUM_BLOCK_1_4         (0x40000000U)                    /*!< Bit 4 */

#define USB_COUNT3_RX_1_BLSIZE_1              (0x80000000U)                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT4_RX_0 register  ***************/
#define USB_COUNT4_RX_0_COUNT4_RX_0           (0x000003FFU)                    /*!< Reception Byte Count (low) */

#define USB_COUNT4_RX_0_NUM_BLOCK_0           (0x00007C00U)                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_0         (0x00000400U)                    /*!< Bit 0 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_1         (0x00000800U)                    /*!< Bit 1 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_2         (0x00001000U)                    /*!< Bit 2 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_3         (0x00002000U)                    /*!< Bit 3 */
#define USB_COUNT4_RX_0_NUM_BLOCK_0_4         (0x00004000U)                    /*!< Bit 4 */

#define USB_COUNT4_RX_0_BLSIZE_0              (0x00008000U)                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT4_RX_1 register  ***************/
#define USB_COUNT4_RX_1_COUNT4_RX_1           (0x03FF0000U)                    /*!< Reception Byte Count (high) */

#define USB_COUNT4_RX_1_NUM_BLOCK_1           (0x7C000000U)                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_0         (0x04000000U)                    /*!< Bit 0 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_1         (0x08000000U)                    /*!< Bit 1 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_2         (0x10000000U)                    /*!< Bit 2 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_3         (0x20000000U)                    /*!< Bit 3 */
#define USB_COUNT4_RX_1_NUM_BLOCK_1_4         (0x40000000U)                    /*!< Bit 4 */

#define USB_COUNT4_RX_1_BLSIZE_1              (0x80000000U)                    /*!< BLock SIZE (high) */

/****************  Bit definition for USB_COUNT5_RX_0 register  ***************/
#define USB_COUNT5_RX_0_COUNT5_RX_0           (0x000003FFU)                    /*!< Reception Byte Count (low) */

#define USB_COUNT5_RX_0_NUM_BLOCK_0           (0x00007C00U)                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_0         (0x00000400U)                    /*!< Bit 0 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_1         (0x00000800U)                    /*!< Bit 1 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_2         (0x00001000U)                    /*!< Bit 2 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_3         (0x00002000U)                    /*!< Bit 3 */
#define USB_COUNT5_RX_0_NUM_BLOCK_0_4         (0x00004000U)                    /*!< Bit 4 */

#define USB_COUNT5_RX_0_BLSIZE_0              (0x00008000U)                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT5_RX_1 register  ***************/
#define USB_COUNT5_RX_1_COUNT5_RX_1           (0x03FF0000U)                    /*!< Reception Byte Count (high) */

#define USB_COUNT5_RX_1_NUM_BLOCK_1           (0x7C000000U)                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_0         (0x04000000U)                    /*!< Bit 0 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_1         (0x08000000U)                    /*!< Bit 1 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_2         (0x10000000U)                    /*!< Bit 2 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_3         (0x20000000U)                    /*!< Bit 3 */
#define USB_COUNT5_RX_1_NUM_BLOCK_1_4         (0x40000000U)                    /*!< Bit 4 */

#define USB_COUNT5_RX_1_BLSIZE_1              (0x80000000U)                    /*!< BLock SIZE (high) */

/***************  Bit definition for USB_COUNT6_RX_0  register  ***************/
#define USB_COUNT6_RX_0_COUNT6_RX_0           (0x000003FFU)                    /*!< Reception Byte Count (low) */

#define USB_COUNT6_RX_0_NUM_BLOCK_0           (0x00007C00U)                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_0         (0x00000400U)                    /*!< Bit 0 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_1         (0x00000800U)                    /*!< Bit 1 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_2         (0x00001000U)                    /*!< Bit 2 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_3         (0x00002000U)                    /*!< Bit 3 */
#define USB_COUNT6_RX_0_NUM_BLOCK_0_4         (0x00004000U)                    /*!< Bit 4 */

#define USB_COUNT6_RX_0_BLSIZE_0              (0x00008000U)                    /*!< BLock SIZE (low) */

/****************  Bit definition for USB_COUNT6_RX_1 register  ***************/
#define USB_COUNT6_RX_1_COUNT6_RX_1           (0x03FF0000U)                    /*!< Reception Byte Count (high) */

#define USB_COUNT6_RX_1_NUM_BLOCK_1           (0x7C000000U)                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_0         (0x04000000U)                    /*!< Bit 0 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_1         (0x08000000U)                    /*!< Bit 1 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_2         (0x10000000U)                    /*!< Bit 2 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_3         (0x20000000U)                    /*!< Bit 3 */
#define USB_COUNT6_RX_1_NUM_BLOCK_1_4         (0x40000000U)                    /*!< Bit 4 */

#define USB_COUNT6_RX_1_BLSIZE_1              (0x80000000U)                    /*!< BLock SIZE (high) */

/***************  Bit definition for USB_COUNT7_RX_0 register  ****************/
#define USB_COUNT7_RX_0_COUNT7_RX_0           (0x000003FFU)                    /*!< Reception Byte Count (low) */

#define USB_COUNT7_RX_0_NUM_BLOCK_0           (0x00007C00U)                    /*!< NUM_BLOCK_0[4:0] bits (Number of blocks) (low) */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_0         (0x00000400U)                    /*!< Bit 0 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_1         (0x00000800U)                    /*!< Bit 1 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_2         (0x00001000U)                    /*!< Bit 2 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_3         (0x00002000U)                    /*!< Bit 3 */
#define USB_COUNT7_RX_0_NUM_BLOCK_0_4         (0x00004000U)                    /*!< Bit 4 */

#define USB_COUNT7_RX_0_BLSIZE_0              (0x00008000U)                    /*!< BLock SIZE (low) */

/***************  Bit definition for USB_COUNT7_RX_1 register  ****************/
#define USB_COUNT7_RX_1_COUNT7_RX_1           (0x03FF0000U)                    /*!< Reception Byte Count (high) */

#define USB_COUNT7_RX_1_NUM_BLOCK_1           (0x7C000000U)                    /*!< NUM_BLOCK_1[4:0] bits (Number of blocks) (high) */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_0         (0x04000000U)                    /*!< Bit 0 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_1         (0x08000000U)                    /*!< Bit 1 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_2         (0x10000000U)                    /*!< Bit 2 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_3         (0x20000000U)                    /*!< Bit 3 */
#define USB_COUNT7_RX_1_NUM_BLOCK_1_4         (0x40000000U)                    /*!< Bit 4 */

#define USB_COUNT7_RX_1_BLSIZE_1              (0x80000000U)                    /*!< BLock SIZE (high) */

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

 /**
  * @}
  */ 
/** @addtogroup Exported_macro
  * @{
  */
      
/****************************** ADC Instances *********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC1_COMMON)

/******************************** COMP Instances ******************************/
#define IS_COMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == COMP1) || \
                                        ((INSTANCE) == COMP2))

#define IS_COMP_COMMON_INSTANCE(COMMON_INSTANCE) ((COMMON_INSTANCE) == COMP12_COMMON)

/****************************** CRC Instances *********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/****************************** DAC Instances *********************************/
#define IS_DAC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DAC)

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
                                        ((INSTANCE) == GPIOG) || \
                                        ((INSTANCE) == GPIOH))

/**************************** GPIO Alternate Function Instances ***************/
#define IS_GPIO_AF_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** GPIO Lock Instances *****************************/
/* On L1, all GPIO Bank support the Lock mechanism */
#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2C1) || \
                                       ((INSTANCE) == I2C2))

/****************************** SMBUS Instances *******************************/
#define IS_SMBUS_ALL_INSTANCE(INSTANCE) IS_I2C_ALL_INSTANCE(INSTANCE)

/******************************** I2S Instances *******************************/
#define IS_I2S_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI2) || \
                                       ((INSTANCE) == SPI3))
/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

/****************************** OPAMP Instances *******************************/
#define IS_OPAMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == OPAMP1) || \
                                         ((INSTANCE) == OPAMP2))

#define IS_OPAMP_COMMON_INSTANCE(COMMON_INSTANCE) ((COMMON_INSTANCE) == OPAMP12_COMMON)

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2) || \
                                       ((INSTANCE) == SPI3))

/****************************** TIM Instances *********************************/ 
#define IS_TIM_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)    || \
                                   ((INSTANCE) == TIM3)    || \
                                   ((INSTANCE) == TIM4)    || \
                                   ((INSTANCE) == TIM5)    || \
                                   ((INSTANCE) == TIM6)    || \
                                   ((INSTANCE) == TIM7)    || \
                                   ((INSTANCE) == TIM9)    || \
                                   ((INSTANCE) == TIM10)   || \
                                   ((INSTANCE) == TIM11))

#define IS_TIM_CC1_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                       ((INSTANCE) == TIM3)  || \
                                       ((INSTANCE) == TIM4)  || \
                                       ((INSTANCE) == TIM5)  || \
                                       ((INSTANCE) == TIM9)  || \
                                       ((INSTANCE) == TIM10) || \
                                       ((INSTANCE) == TIM11))

#define IS_TIM_CC2_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                       ((INSTANCE) == TIM3)  || \
                                       ((INSTANCE) == TIM4)  || \
                                       ((INSTANCE) == TIM5)  || \
                                       ((INSTANCE) == TIM9))

#define IS_TIM_CC3_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                       ((INSTANCE) == TIM3)  || \
                                       ((INSTANCE) == TIM4)  || \
                                       ((INSTANCE) == TIM5))

#define IS_TIM_CC4_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                       ((INSTANCE) == TIM3)  || \
                                       ((INSTANCE) == TIM4)  || \
                                       ((INSTANCE) == TIM5))

#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                                        ((INSTANCE) == TIM3)  || \
                                                        ((INSTANCE) == TIM4)  || \
                                                        ((INSTANCE) == TIM5)  || \
                                                        ((INSTANCE) == TIM9))

#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                                        ((INSTANCE) == TIM3)  || \
                                                        ((INSTANCE) == TIM4)  || \
                                                        ((INSTANCE) == TIM5)  || \
                                                        ((INSTANCE) == TIM9)  || \
                                                        ((INSTANCE) == TIM10) || \
                                                        ((INSTANCE) == TIM11))

#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                                   ((INSTANCE) == TIM3)  || \
                                                   ((INSTANCE) == TIM4)  || \
                                                   ((INSTANCE) == TIM5)  || \
                                                   ((INSTANCE) == TIM9))

#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                                    ((INSTANCE) == TIM3)  || \
                                                    ((INSTANCE) == TIM4)  || \
                                                    ((INSTANCE) == TIM5)  || \
                                                    ((INSTANCE) == TIM9))

#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                                ((INSTANCE) == TIM3)  || \
                                                ((INSTANCE) == TIM4))

#define IS_TIM_XOR_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                       ((INSTANCE) == TIM3)  || \
                                       ((INSTANCE) == TIM4)  || \
                                       ((INSTANCE) == TIM5))
                                       
#define IS_TIM_ETR_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                       ((INSTANCE) == TIM3)  || \
                                       ((INSTANCE) == TIM4)  || \
                                       ((INSTANCE) == TIM5)  || \
                                       ((INSTANCE) == TIM9))


#define IS_TIM_MASTER_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                          ((INSTANCE) == TIM3)  || \
                                          ((INSTANCE) == TIM4)  || \
                                          ((INSTANCE) == TIM5)  || \
                                          ((INSTANCE) == TIM6)  || \
                                          ((INSTANCE) == TIM7)  || \
                                          ((INSTANCE) == TIM9))

#define IS_TIM_SLAVE_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                         ((INSTANCE) == TIM3)  || \
                                         ((INSTANCE) == TIM4)  || \
                                         ((INSTANCE) == TIM9))

#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE) ((INSTANCE) == TIM5)

#define IS_TIM_DMABURST_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                            ((INSTANCE) == TIM3)  || \
                                            ((INSTANCE) == TIM4)  || \
                                            ((INSTANCE) == TIM5))

#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM2) &&                   \
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
    (((INSTANCE) == TIM9) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2)))           \
    ||                                         \
    (((INSTANCE) == TIM10) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TIM11) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1))))

#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                                  ((INSTANCE) == TIM3)  || \
                                                  ((INSTANCE) == TIM4)  || \
                                                  ((INSTANCE) == TIM5)  || \
                                                  ((INSTANCE) == TIM9)  || \
                                                  ((INSTANCE) == TIM10) || \
                                                  ((INSTANCE) == TIM11))

#define IS_TIM_DMA_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)    || \
                                       ((INSTANCE) == TIM3)    || \
                                       ((INSTANCE) == TIM4)    || \
                                       ((INSTANCE) == TIM5)    || \
                                       ((INSTANCE) == TIM6)    || \
                                       ((INSTANCE) == TIM7))
    
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                          ((INSTANCE) == TIM3)  || \
                                          ((INSTANCE) == TIM4)  || \
                                          ((INSTANCE) == TIM5))

#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)    || \
                                                       ((INSTANCE) == TIM3)    || \
                                                       ((INSTANCE) == TIM4)    || \
                                                       ((INSTANCE) == TIM5)    || \
                                                       ((INSTANCE) == TIM9))

#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                                     ((INSTANCE) == TIM3)  || \
                                                     ((INSTANCE) == TIM4)  || \
                                                     ((INSTANCE) == TIM5)  || \
                                                     ((INSTANCE) == TIM9))

#define IS_TIM_REMAP_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)    || \
                                         ((INSTANCE) == TIM3)    || \
                                         ((INSTANCE) == TIM9)    || \
                                         ((INSTANCE) == TIM10)   || \
                                         ((INSTANCE) == TIM11))

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
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                                 ((INSTANCE) == USART2) || \
                                                 ((INSTANCE) == USART3) || \
                                                 ((INSTANCE) == UART4)  || \
                                                 ((INSTANCE) == UART5))                                       

/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
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
#define IS_UART_MULTIPROCESSOR_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                                     ((INSTANCE) == USART2) || \
                                                     ((INSTANCE) == USART3) || \
                                                     ((INSTANCE) == UART4)  || \
                                                     ((INSTANCE) == UART5)) 

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG)


/****************************** LCD Instances ********************************/
#define IS_LCD_ALL_INSTANCE(INSTANCE) ((INSTANCE) == LCD)

/****************************** USB Instances ********************************/
#define IS_USB_ALL_INSTANCE(INSTANCE) ((INSTANCE) == USB)
#define IS_PCD_ALL_INSTANCE           IS_USB_ALL_INSTANCE

/**
  * @}
  */

/******************************************************************************/
/*  For a painless codes migration between the STM32L1xx device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */ 
/*  product lines within the same STM32L1 Family                              */
/******************************************************************************/

/* Aliases for __IRQn */

/* Aliases for __IRQHandler */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32L152xE_H */



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
