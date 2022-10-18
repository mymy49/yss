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


/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f103x6
  * @{
  */
    
#ifndef __STM32F103x6_H
#define __STM32F103x6_H

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
 #define __MPU_PRESENT             0U       /*!< Other STM32 devices does not provide an MPU  */
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
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
  USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm3.h"
#include "system_stm32f1xx.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Analog to Digital Converter  
  */

typedef struct
{
  __IO uint32_t SR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SMPR1;
  __IO uint32_t SMPR2;
  __IO uint32_t JOFR1;
  __IO uint32_t JOFR2;
  __IO uint32_t JOFR3;
  __IO uint32_t JOFR4;
  __IO uint32_t HTR;
  __IO uint32_t LTR;
  __IO uint32_t SQR1;
  __IO uint32_t SQR2;
  __IO uint32_t SQR3;
  __IO uint32_t JSQR;
  __IO uint32_t JDR1;
  __IO uint32_t JDR2;
  __IO uint32_t JDR3;
  __IO uint32_t JDR4;
  __IO uint32_t DR;
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t SR;               /*!< ADC status register,    used for ADC multimode (bits common to several ADC instances). Address offset: ADC1 base address         */
  __IO uint32_t CR1;              /*!< ADC control register 1, used for ADC multimode (bits common to several ADC instances). Address offset: ADC1 base address + 0x04  */
  __IO uint32_t CR2;              /*!< ADC control register 2, used for ADC multimode (bits common to several ADC instances). Address offset: ADC1 base address + 0x08  */
  uint32_t  RESERVED[16];
  __IO uint32_t DR;               /*!< ADC data register,      used for ADC multimode (bits common to several ADC instances). Address offset: ADC1 base address + 0x4C  */
} ADC_Common_TypeDef;

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
} BKP_TypeDef;
  
/** 
  * @brief Controller Area Network TxMailBox 
  */

typedef struct
{
  __IO uint32_t TIR;
  __IO uint32_t TDTR;
  __IO uint32_t TDLR;
  __IO uint32_t TDHR;
} CAN_TxMailBox_TypeDef;

/** 
  * @brief Controller Area Network FIFOMailBox 
  */
  
typedef struct
{
  __IO uint32_t RIR;
  __IO uint32_t RDTR;
  __IO uint32_t RDLR;
  __IO uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;

/** 
  * @brief Controller Area Network FilterRegister 
  */
  
typedef struct
{
  __IO uint32_t FR1;
  __IO uint32_t FR2;
} CAN_FilterRegister_TypeDef;

/** 
  * @brief Controller Area Network 
  */
  
typedef struct
{
  __IO uint32_t MCR;
  __IO uint32_t MSR;
  __IO uint32_t TSR;
  __IO uint32_t RF0R;
  __IO uint32_t RF1R;
  __IO uint32_t IER;
  __IO uint32_t ESR;
  __IO uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  __IO uint32_t FMR;
  __IO uint32_t FM1R;
  uint32_t  RESERVED2;
  __IO uint32_t FS1R;
  uint32_t  RESERVED3;
  __IO uint32_t FFA1R;
  uint32_t  RESERVED4;
  __IO uint32_t FA1R;
  uint32_t  RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;

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
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;
  __IO uint32_t CR;
}DBGMCU_TypeDef;

/** 
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CCR;
  __IO uint32_t CNDTR;
  __IO uint32_t CPAR;
  __IO uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;
  __IO uint32_t IFCR;
} DMA_TypeDef;



/** 
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t IMR;
  __IO uint32_t EMR;
  __IO uint32_t RTSR;
  __IO uint32_t FTSR;
  __IO uint32_t SWIER;
  __IO uint32_t PR;
} EXTI_TypeDef;

/** 
  * @brief FLASH Registers
  */

typedef struct
{
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;
  __IO uint32_t RESERVED;
  __IO uint32_t OBR;
  __IO uint32_t WRPR;
} FLASH_TypeDef;

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
  * @brief General Purpose I/O
  */

typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_TypeDef;

/** 
  * @brief Alternate Function I/O
  */

typedef struct
{
  __IO uint32_t EVCR;
  __IO uint32_t MAPR;
  __IO uint32_t EXTICR[4];
  uint32_t RESERVED0;
  __IO uint32_t MAPR2;  
} AFIO_TypeDef;
/** 
  * @brief Inter Integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t OAR1;
  __IO uint32_t OAR2;
  __IO uint32_t DR;
  __IO uint32_t SR1;
  __IO uint32_t SR2;
  __IO uint32_t CCR;
  __IO uint32_t TRISE;
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
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SR;
  __IO uint32_t DR;
  __IO uint32_t CRCPR;
  __IO uint32_t RXCRCR;
  __IO uint32_t TXCRCR;
  __IO uint32_t I2SCFGR;
} SPI_TypeDef;

/**
  * @brief TIM Timers
  */
typedef struct
{
  __IO uint32_t CR1;             /*!< TIM control register 1,                      Address offset: 0x00 */
  __IO uint32_t CR2;             /*!< TIM control register 2,                      Address offset: 0x04 */
  __IO uint32_t SMCR;            /*!< TIM slave Mode Control register,             Address offset: 0x08 */
  __IO uint32_t DIER;            /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
  __IO uint32_t SR;              /*!< TIM status register,                         Address offset: 0x10 */
  __IO uint32_t EGR;             /*!< TIM event generation register,               Address offset: 0x14 */
  __IO uint32_t CCMR1;           /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
  __IO uint32_t CCMR2;           /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
  __IO uint32_t CCER;            /*!< TIM capture/compare enable register,         Address offset: 0x20 */
  __IO uint32_t CNT;             /*!< TIM counter register,                        Address offset: 0x24 */
  __IO uint32_t PSC;             /*!< TIM prescaler register,                      Address offset: 0x28 */
  __IO uint32_t ARR;             /*!< TIM auto-reload register,                    Address offset: 0x2C */
  __IO uint32_t RCR;             /*!< TIM  repetition counter register,            Address offset: 0x30 */
  __IO uint32_t CCR1;            /*!< TIM capture/compare register 1,              Address offset: 0x34 */
  __IO uint32_t CCR2;            /*!< TIM capture/compare register 2,              Address offset: 0x38 */
  __IO uint32_t CCR3;            /*!< TIM capture/compare register 3,              Address offset: 0x3C */
  __IO uint32_t CCR4;            /*!< TIM capture/compare register 4,              Address offset: 0x40 */
  __IO uint32_t BDTR;            /*!< TIM break and dead-time register,            Address offset: 0x44 */
  __IO uint32_t DCR;             /*!< TIM DMA control register,                    Address offset: 0x48 */
  __IO uint32_t DMAR;            /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
  __IO uint32_t OR;              /*!< TIM option register,                         Address offset: 0x50 */
}TIM_TypeDef;


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
#define FLASH_BANK1_END       0x08007FFFUL /*!< FLASH END address of bank1 */
#define SRAM_BASE             0x20000000UL /*!< SRAM base address in the alias region */
#define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region */

#define SRAM_BB_BASE          0x22000000UL /*!< SRAM base address in the bit-band region */
#define PERIPH_BB_BASE        0x42000000UL /*!< Peripheral base address in the bit-band region */


/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x00000000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x00000400UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x00002800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x00002C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x00003000UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x00004400UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x00005400UL)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x00006400UL)
#define BKP_BASE              (APB1PERIPH_BASE + 0x00006C00UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x00007000UL)
#define AFIO_BASE             (APB2PERIPH_BASE + 0x00000000UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00000400UL)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x00000800UL)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x00000C00UL)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x00001000UL)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x00001400UL)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x00002400UL)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x00002800UL)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x00002C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800UL)


#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000UL)
#define DMA1_Channel1_BASE    (AHBPERIPH_BASE + 0x00000008UL)
#define DMA1_Channel2_BASE    (AHBPERIPH_BASE + 0x0000001CUL)
#define DMA1_Channel3_BASE    (AHBPERIPH_BASE + 0x00000030UL)
#define DMA1_Channel4_BASE    (AHBPERIPH_BASE + 0x00000044UL)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x00000058UL)
#define DMA1_Channel6_BASE    (AHBPERIPH_BASE + 0x0000006CUL)
#define DMA1_Channel7_BASE    (AHBPERIPH_BASE + 0x00000080UL)
#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000UL)
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000UL)

#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000UL) /*!< Flash registers base address */
#define FLASHSIZE_BASE        0x1FFFF7E0UL    /*!< FLASH Size register base address */
#define UID_BASE              0x1FFFF7E8UL    /*!< Unique device ID register base address */
#define OB_BASE               0x1FFFF800UL    /*!< Flash Option Bytes base address */



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

#define TIM2                ((TIM_TypeDef *)TIM2_BASE)
#define TIM3                ((TIM_TypeDef *)TIM3_BASE)
#define RTC                 ((RTC_TypeDef *)RTC_BASE)
#define WWDG                ((WWDG_TypeDef *)WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *)IWDG_BASE)
#define USART2              ((USART_TypeDef *)USART2_BASE)
#define I2C1                ((I2C_TypeDef *)I2C1_BASE)
#define USB                 ((USB_TypeDef *)USB_BASE)
#define CAN1                ((CAN_TypeDef *)CAN1_BASE)
#define BKP                 ((BKP_TypeDef *)BKP_BASE)
#define PWR                 ((PWR_TypeDef *)PWR_BASE)
#define AFIO                ((AFIO_TypeDef *)AFIO_BASE)
#define EXTI                ((EXTI_TypeDef *)EXTI_BASE)
#define GPIOA               ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *)GPIOD_BASE)
#define ADC1                ((ADC_TypeDef *)ADC1_BASE)
#define ADC2                ((ADC_TypeDef *)ADC2_BASE)
#define ADC12_COMMON        ((ADC_Common_TypeDef *)ADC1_BASE)
#define TIM1                ((TIM_TypeDef *)TIM1_BASE)
#define SPI1                ((SPI_TypeDef *)SPI1_BASE)
#define USART1              ((USART_TypeDef *)USART1_BASE)
#define DMA1                ((DMA_TypeDef *)DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *)DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *)DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *)DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *)DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *)DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *)DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *)DMA1_Channel7_BASE)
#define RCC                 ((RCC_TypeDef *)RCC_BASE)
#define CRC                 ((CRC_TypeDef *)CRC_BASE)
#define FLASH               ((FLASH_TypeDef *)FLASH_R_BASE)
#define OB                  ((OB_TypeDef *)OB_BASE)
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

#define RTC_BKP_NUMBER 10

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
/*                General Purpose and Alternate Function I/O                  */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for GPIO_CRL register  *******************/
#define GPIO_CRL_MODE_Pos                    (0U)                              
#define GPIO_CRL_MODE_Msk                    (0x33333333UL << GPIO_CRL_MODE_Pos) /*!< 0x33333333 */
#define GPIO_CRL_MODE                        GPIO_CRL_MODE_Msk                 /*!< Port x mode bits */

#define GPIO_CRL_MODE0_Pos                   (0U)                              
#define GPIO_CRL_MODE0_Msk                   (0x3UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000003 */
#define GPIO_CRL_MODE0                       GPIO_CRL_MODE0_Msk                /*!< MODE0[1:0] bits (Port x mode bits, pin 0) */
#define GPIO_CRL_MODE0_0                     (0x1UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000001 */
#define GPIO_CRL_MODE0_1                     (0x2UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000002 */

#define GPIO_CRL_MODE1_Pos                   (4U)                              
#define GPIO_CRL_MODE1_Msk                   (0x3UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000030 */
#define GPIO_CRL_MODE1                       GPIO_CRL_MODE1_Msk                /*!< MODE1[1:0] bits (Port x mode bits, pin 1) */
#define GPIO_CRL_MODE1_0                     (0x1UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000010 */
#define GPIO_CRL_MODE1_1                     (0x2UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000020 */

#define GPIO_CRL_MODE2_Pos                   (8U)                              
#define GPIO_CRL_MODE2_Msk                   (0x3UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000300 */
#define GPIO_CRL_MODE2                       GPIO_CRL_MODE2_Msk                /*!< MODE2[1:0] bits (Port x mode bits, pin 2) */
#define GPIO_CRL_MODE2_0                     (0x1UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000100 */
#define GPIO_CRL_MODE2_1                     (0x2UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000200 */

#define GPIO_CRL_MODE3_Pos                   (12U)                             
#define GPIO_CRL_MODE3_Msk                   (0x3UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00003000 */
#define GPIO_CRL_MODE3                       GPIO_CRL_MODE3_Msk                /*!< MODE3[1:0] bits (Port x mode bits, pin 3) */
#define GPIO_CRL_MODE3_0                     (0x1UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00001000 */
#define GPIO_CRL_MODE3_1                     (0x2UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00002000 */

#define GPIO_CRL_MODE4_Pos                   (16U)                             
#define GPIO_CRL_MODE4_Msk                   (0x3UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00030000 */
#define GPIO_CRL_MODE4                       GPIO_CRL_MODE4_Msk                /*!< MODE4[1:0] bits (Port x mode bits, pin 4) */
#define GPIO_CRL_MODE4_0                     (0x1UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00010000 */
#define GPIO_CRL_MODE4_1                     (0x2UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00020000 */

#define GPIO_CRL_MODE5_Pos                   (20U)                             
#define GPIO_CRL_MODE5_Msk                   (0x3UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00300000 */
#define GPIO_CRL_MODE5                       GPIO_CRL_MODE5_Msk                /*!< MODE5[1:0] bits (Port x mode bits, pin 5) */
#define GPIO_CRL_MODE5_0                     (0x1UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00100000 */
#define GPIO_CRL_MODE5_1                     (0x2UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00200000 */

#define GPIO_CRL_MODE6_Pos                   (24U)                             
#define GPIO_CRL_MODE6_Msk                   (0x3UL << GPIO_CRL_MODE6_Pos)      /*!< 0x03000000 */
#define GPIO_CRL_MODE6                       GPIO_CRL_MODE6_Msk                /*!< MODE6[1:0] bits (Port x mode bits, pin 6) */
#define GPIO_CRL_MODE6_0                     (0x1UL << GPIO_CRL_MODE6_Pos)      /*!< 0x01000000 */
#define GPIO_CRL_MODE6_1                     (0x2UL << GPIO_CRL_MODE6_Pos)      /*!< 0x02000000 */

#define GPIO_CRL_MODE7_Pos                   (28U)                             
#define GPIO_CRL_MODE7_Msk                   (0x3UL << GPIO_CRL_MODE7_Pos)      /*!< 0x30000000 */
#define GPIO_CRL_MODE7                       GPIO_CRL_MODE7_Msk                /*!< MODE7[1:0] bits (Port x mode bits, pin 7) */
#define GPIO_CRL_MODE7_0                     (0x1UL << GPIO_CRL_MODE7_Pos)      /*!< 0x10000000 */
#define GPIO_CRL_MODE7_1                     (0x2UL << GPIO_CRL_MODE7_Pos)      /*!< 0x20000000 */

#define GPIO_CRL_CNF_Pos                     (2U)                              
#define GPIO_CRL_CNF_Msk                     (0x33333333UL << GPIO_CRL_CNF_Pos) /*!< 0xCCCCCCCC */
#define GPIO_CRL_CNF                         GPIO_CRL_CNF_Msk                  /*!< Port x configuration bits */

#define GPIO_CRL_CNF0_Pos                    (2U)                              
#define GPIO_CRL_CNF0_Msk                    (0x3UL << GPIO_CRL_CNF0_Pos)       /*!< 0x0000000C */
#define GPIO_CRL_CNF0                        GPIO_CRL_CNF0_Msk                 /*!< CNF0[1:0] bits (Port x configuration bits, pin 0) */
#define GPIO_CRL_CNF0_0                      (0x1UL << GPIO_CRL_CNF0_Pos)       /*!< 0x00000004 */
#define GPIO_CRL_CNF0_1                      (0x2UL << GPIO_CRL_CNF0_Pos)       /*!< 0x00000008 */

#define GPIO_CRL_CNF1_Pos                    (6U)                              
#define GPIO_CRL_CNF1_Msk                    (0x3UL << GPIO_CRL_CNF1_Pos)       /*!< 0x000000C0 */
#define GPIO_CRL_CNF1                        GPIO_CRL_CNF1_Msk                 /*!< CNF1[1:0] bits (Port x configuration bits, pin 1) */
#define GPIO_CRL_CNF1_0                      (0x1UL << GPIO_CRL_CNF1_Pos)       /*!< 0x00000040 */
#define GPIO_CRL_CNF1_1                      (0x2UL << GPIO_CRL_CNF1_Pos)       /*!< 0x00000080 */

#define GPIO_CRL_CNF2_Pos                    (10U)                             
#define GPIO_CRL_CNF2_Msk                    (0x3UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000C00 */
#define GPIO_CRL_CNF2                        GPIO_CRL_CNF2_Msk                 /*!< CNF2[1:0] bits (Port x configuration bits, pin 2) */
#define GPIO_CRL_CNF2_0                      (0x1UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000400 */
#define GPIO_CRL_CNF2_1                      (0x2UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000800 */

#define GPIO_CRL_CNF3_Pos                    (14U)                             
#define GPIO_CRL_CNF3_Msk                    (0x3UL << GPIO_CRL_CNF3_Pos)       /*!< 0x0000C000 */
#define GPIO_CRL_CNF3                        GPIO_CRL_CNF3_Msk                 /*!< CNF3[1:0] bits (Port x configuration bits, pin 3) */
#define GPIO_CRL_CNF3_0                      (0x1UL << GPIO_CRL_CNF3_Pos)       /*!< 0x00004000 */
#define GPIO_CRL_CNF3_1                      (0x2UL << GPIO_CRL_CNF3_Pos)       /*!< 0x00008000 */

#define GPIO_CRL_CNF4_Pos                    (18U)                             
#define GPIO_CRL_CNF4_Msk                    (0x3UL << GPIO_CRL_CNF4_Pos)       /*!< 0x000C0000 */
#define GPIO_CRL_CNF4                        GPIO_CRL_CNF4_Msk                 /*!< CNF4[1:0] bits (Port x configuration bits, pin 4) */
#define GPIO_CRL_CNF4_0                      (0x1UL << GPIO_CRL_CNF4_Pos)       /*!< 0x00040000 */
#define GPIO_CRL_CNF4_1                      (0x2UL << GPIO_CRL_CNF4_Pos)       /*!< 0x00080000 */

#define GPIO_CRL_CNF5_Pos                    (22U)                             
#define GPIO_CRL_CNF5_Msk                    (0x3UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00C00000 */
#define GPIO_CRL_CNF5                        GPIO_CRL_CNF5_Msk                 /*!< CNF5[1:0] bits (Port x configuration bits, pin 5) */
#define GPIO_CRL_CNF5_0                      (0x1UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00400000 */
#define GPIO_CRL_CNF5_1                      (0x2UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00800000 */

#define GPIO_CRL_CNF6_Pos                    (26U)                             
#define GPIO_CRL_CNF6_Msk                    (0x3UL << GPIO_CRL_CNF6_Pos)       /*!< 0x0C000000 */
#define GPIO_CRL_CNF6                        GPIO_CRL_CNF6_Msk                 /*!< CNF6[1:0] bits (Port x configuration bits, pin 6) */
#define GPIO_CRL_CNF6_0                      (0x1UL << GPIO_CRL_CNF6_Pos)       /*!< 0x04000000 */
#define GPIO_CRL_CNF6_1                      (0x2UL << GPIO_CRL_CNF6_Pos)       /*!< 0x08000000 */

#define GPIO_CRL_CNF7_Pos                    (30U)                             
#define GPIO_CRL_CNF7_Msk                    (0x3UL << GPIO_CRL_CNF7_Pos)       /*!< 0xC0000000 */
#define GPIO_CRL_CNF7                        GPIO_CRL_CNF7_Msk                 /*!< CNF7[1:0] bits (Port x configuration bits, pin 7) */
#define GPIO_CRL_CNF7_0                      (0x1UL << GPIO_CRL_CNF7_Pos)       /*!< 0x40000000 */
#define GPIO_CRL_CNF7_1                      (0x2UL << GPIO_CRL_CNF7_Pos)       /*!< 0x80000000 */

/*******************  Bit definition for GPIO_CRH register  *******************/
#define GPIO_CRH_MODE_Pos                    (0U)                              
#define GPIO_CRH_MODE_Msk                    (0x33333333UL << GPIO_CRH_MODE_Pos) /*!< 0x33333333 */
#define GPIO_CRH_MODE                        GPIO_CRH_MODE_Msk                 /*!< Port x mode bits */

#define GPIO_CRH_MODE8_Pos                   (0U)                              
#define GPIO_CRH_MODE8_Msk                   (0x3UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000003 */
#define GPIO_CRH_MODE8                       GPIO_CRH_MODE8_Msk                /*!< MODE8[1:0] bits (Port x mode bits, pin 8) */
#define GPIO_CRH_MODE8_0                     (0x1UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000001 */
#define GPIO_CRH_MODE8_1                     (0x2UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000002 */

#define GPIO_CRH_MODE9_Pos                   (4U)                              
#define GPIO_CRH_MODE9_Msk                   (0x3UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000030 */
#define GPIO_CRH_MODE9                       GPIO_CRH_MODE9_Msk                /*!< MODE9[1:0] bits (Port x mode bits, pin 9) */
#define GPIO_CRH_MODE9_0                     (0x1UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000010 */
#define GPIO_CRH_MODE9_1                     (0x2UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000020 */

#define GPIO_CRH_MODE10_Pos                  (8U)                              
#define GPIO_CRH_MODE10_Msk                  (0x3UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000300 */
#define GPIO_CRH_MODE10                      GPIO_CRH_MODE10_Msk               /*!< MODE10[1:0] bits (Port x mode bits, pin 10) */
#define GPIO_CRH_MODE10_0                    (0x1UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000100 */
#define GPIO_CRH_MODE10_1                    (0x2UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000200 */

#define GPIO_CRH_MODE11_Pos                  (12U)                             
#define GPIO_CRH_MODE11_Msk                  (0x3UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00003000 */
#define GPIO_CRH_MODE11                      GPIO_CRH_MODE11_Msk               /*!< MODE11[1:0] bits (Port x mode bits, pin 11) */
#define GPIO_CRH_MODE11_0                    (0x1UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00001000 */
#define GPIO_CRH_MODE11_1                    (0x2UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00002000 */

#define GPIO_CRH_MODE12_Pos                  (16U)                             
#define GPIO_CRH_MODE12_Msk                  (0x3UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00030000 */
#define GPIO_CRH_MODE12                      GPIO_CRH_MODE12_Msk               /*!< MODE12[1:0] bits (Port x mode bits, pin 12) */
#define GPIO_CRH_MODE12_0                    (0x1UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00010000 */
#define GPIO_CRH_MODE12_1                    (0x2UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00020000 */

#define GPIO_CRH_MODE13_Pos                  (20U)                             
#define GPIO_CRH_MODE13_Msk                  (0x3UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00300000 */
#define GPIO_CRH_MODE13                      GPIO_CRH_MODE13_Msk               /*!< MODE13[1:0] bits (Port x mode bits, pin 13) */
#define GPIO_CRH_MODE13_0                    (0x1UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00100000 */
#define GPIO_CRH_MODE13_1                    (0x2UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00200000 */

#define GPIO_CRH_MODE14_Pos                  (24U)                             
#define GPIO_CRH_MODE14_Msk                  (0x3UL << GPIO_CRH_MODE14_Pos)     /*!< 0x03000000 */
#define GPIO_CRH_MODE14                      GPIO_CRH_MODE14_Msk               /*!< MODE14[1:0] bits (Port x mode bits, pin 14) */
#define GPIO_CRH_MODE14_0                    (0x1UL << GPIO_CRH_MODE14_Pos)     /*!< 0x01000000 */
#define GPIO_CRH_MODE14_1                    (0x2UL << GPIO_CRH_MODE14_Pos)     /*!< 0x02000000 */

#define GPIO_CRH_MODE15_Pos                  (28U)                             
#define GPIO_CRH_MODE15_Msk                  (0x3UL << GPIO_CRH_MODE15_Pos)     /*!< 0x30000000 */
#define GPIO_CRH_MODE15                      GPIO_CRH_MODE15_Msk               /*!< MODE15[1:0] bits (Port x mode bits, pin 15) */
#define GPIO_CRH_MODE15_0                    (0x1UL << GPIO_CRH_MODE15_Pos)     /*!< 0x10000000 */
#define GPIO_CRH_MODE15_1                    (0x2UL << GPIO_CRH_MODE15_Pos)     /*!< 0x20000000 */

#define GPIO_CRH_CNF_Pos                     (2U)                              
#define GPIO_CRH_CNF_Msk                     (0x33333333UL << GPIO_CRH_CNF_Pos) /*!< 0xCCCCCCCC */
#define GPIO_CRH_CNF                         GPIO_CRH_CNF_Msk                  /*!< Port x configuration bits */

#define GPIO_CRH_CNF8_Pos                    (2U)                              
#define GPIO_CRH_CNF8_Msk                    (0x3UL << GPIO_CRH_CNF8_Pos)       /*!< 0x0000000C */
#define GPIO_CRH_CNF8                        GPIO_CRH_CNF8_Msk                 /*!< CNF8[1:0] bits (Port x configuration bits, pin 8) */
#define GPIO_CRH_CNF8_0                      (0x1UL << GPIO_CRH_CNF8_Pos)       /*!< 0x00000004 */
#define GPIO_CRH_CNF8_1                      (0x2UL << GPIO_CRH_CNF8_Pos)       /*!< 0x00000008 */

#define GPIO_CRH_CNF9_Pos                    (6U)                              
#define GPIO_CRH_CNF9_Msk                    (0x3UL << GPIO_CRH_CNF9_Pos)       /*!< 0x000000C0 */
#define GPIO_CRH_CNF9                        GPIO_CRH_CNF9_Msk                 /*!< CNF9[1:0] bits (Port x configuration bits, pin 9) */
#define GPIO_CRH_CNF9_0                      (0x1UL << GPIO_CRH_CNF9_Pos)       /*!< 0x00000040 */
#define GPIO_CRH_CNF9_1                      (0x2UL << GPIO_CRH_CNF9_Pos)       /*!< 0x00000080 */

#define GPIO_CRH_CNF10_Pos                   (10U)                             
#define GPIO_CRH_CNF10_Msk                   (0x3UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000C00 */
#define GPIO_CRH_CNF10                       GPIO_CRH_CNF10_Msk                /*!< CNF10[1:0] bits (Port x configuration bits, pin 10) */
#define GPIO_CRH_CNF10_0                     (0x1UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000400 */
#define GPIO_CRH_CNF10_1                     (0x2UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000800 */

#define GPIO_CRH_CNF11_Pos                   (14U)                             
#define GPIO_CRH_CNF11_Msk                   (0x3UL << GPIO_CRH_CNF11_Pos)      /*!< 0x0000C000 */
#define GPIO_CRH_CNF11                       GPIO_CRH_CNF11_Msk                /*!< CNF11[1:0] bits (Port x configuration bits, pin 11) */
#define GPIO_CRH_CNF11_0                     (0x1UL << GPIO_CRH_CNF11_Pos)      /*!< 0x00004000 */
#define GPIO_CRH_CNF11_1                     (0x2UL << GPIO_CRH_CNF11_Pos)      /*!< 0x00008000 */

#define GPIO_CRH_CNF12_Pos                   (18U)                             
#define GPIO_CRH_CNF12_Msk                   (0x3UL << GPIO_CRH_CNF12_Pos)      /*!< 0x000C0000 */
#define GPIO_CRH_CNF12                       GPIO_CRH_CNF12_Msk                /*!< CNF12[1:0] bits (Port x configuration bits, pin 12) */
#define GPIO_CRH_CNF12_0                     (0x1UL << GPIO_CRH_CNF12_Pos)      /*!< 0x00040000 */
#define GPIO_CRH_CNF12_1                     (0x2UL << GPIO_CRH_CNF12_Pos)      /*!< 0x00080000 */

#define GPIO_CRH_CNF13_Pos                   (22U)                             
#define GPIO_CRH_CNF13_Msk                   (0x3UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00C00000 */
#define GPIO_CRH_CNF13                       GPIO_CRH_CNF13_Msk                /*!< CNF13[1:0] bits (Port x configuration bits, pin 13) */
#define GPIO_CRH_CNF13_0                     (0x1UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00400000 */
#define GPIO_CRH_CNF13_1                     (0x2UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00800000 */

#define GPIO_CRH_CNF14_Pos                   (26U)                             
#define GPIO_CRH_CNF14_Msk                   (0x3UL << GPIO_CRH_CNF14_Pos)      /*!< 0x0C000000 */
#define GPIO_CRH_CNF14                       GPIO_CRH_CNF14_Msk                /*!< CNF14[1:0] bits (Port x configuration bits, pin 14) */
#define GPIO_CRH_CNF14_0                     (0x1UL << GPIO_CRH_CNF14_Pos)      /*!< 0x04000000 */
#define GPIO_CRH_CNF14_1                     (0x2UL << GPIO_CRH_CNF14_Pos)      /*!< 0x08000000 */

#define GPIO_CRH_CNF15_Pos                   (30U)                             
#define GPIO_CRH_CNF15_Msk                   (0x3UL << GPIO_CRH_CNF15_Pos)      /*!< 0xC0000000 */
#define GPIO_CRH_CNF15                       GPIO_CRH_CNF15_Msk                /*!< CNF15[1:0] bits (Port x configuration bits, pin 15) */
#define GPIO_CRH_CNF15_0                     (0x1UL << GPIO_CRH_CNF15_Pos)      /*!< 0x40000000 */
#define GPIO_CRH_CNF15_1                     (0x2UL << GPIO_CRH_CNF15_Pos)      /*!< 0x80000000 */

/*!<******************  Bit definition for GPIO_IDR register  *******************/
#define GPIO_IDR_IDR0_Pos                    (0U)                              
#define GPIO_IDR_IDR0_Msk                    (0x1UL << GPIO_IDR_IDR0_Pos)       /*!< 0x00000001 */
#define GPIO_IDR_IDR0                        GPIO_IDR_IDR0_Msk                 /*!< Port input data, bit 0 */
#define GPIO_IDR_IDR1_Pos                    (1U)                              
#define GPIO_IDR_IDR1_Msk                    (0x1UL << GPIO_IDR_IDR1_Pos)       /*!< 0x00000002 */
#define GPIO_IDR_IDR1                        GPIO_IDR_IDR1_Msk                 /*!< Port input data, bit 1 */
#define GPIO_IDR_IDR2_Pos                    (2U)                              
#define GPIO_IDR_IDR2_Msk                    (0x1UL << GPIO_IDR_IDR2_Pos)       /*!< 0x00000004 */
#define GPIO_IDR_IDR2                        GPIO_IDR_IDR2_Msk                 /*!< Port input data, bit 2 */
#define GPIO_IDR_IDR3_Pos                    (3U)                              
#define GPIO_IDR_IDR3_Msk                    (0x1UL << GPIO_IDR_IDR3_Pos)       /*!< 0x00000008 */
#define GPIO_IDR_IDR3                        GPIO_IDR_IDR3_Msk                 /*!< Port input data, bit 3 */
#define GPIO_IDR_IDR4_Pos                    (4U)                              
#define GPIO_IDR_IDR4_Msk                    (0x1UL << GPIO_IDR_IDR4_Pos)       /*!< 0x00000010 */
#define GPIO_IDR_IDR4                        GPIO_IDR_IDR4_Msk                 /*!< Port input data, bit 4 */
#define GPIO_IDR_IDR5_Pos                    (5U)                              
#define GPIO_IDR_IDR5_Msk                    (0x1UL << GPIO_IDR_IDR5_Pos)       /*!< 0x00000020 */
#define GPIO_IDR_IDR5                        GPIO_IDR_IDR5_Msk                 /*!< Port input data, bit 5 */
#define GPIO_IDR_IDR6_Pos                    (6U)                              
#define GPIO_IDR_IDR6_Msk                    (0x1UL << GPIO_IDR_IDR6_Pos)       /*!< 0x00000040 */
#define GPIO_IDR_IDR6                        GPIO_IDR_IDR6_Msk                 /*!< Port input data, bit 6 */
#define GPIO_IDR_IDR7_Pos                    (7U)                              
#define GPIO_IDR_IDR7_Msk                    (0x1UL << GPIO_IDR_IDR7_Pos)       /*!< 0x00000080 */
#define GPIO_IDR_IDR7                        GPIO_IDR_IDR7_Msk                 /*!< Port input data, bit 7 */
#define GPIO_IDR_IDR8_Pos                    (8U)                              
#define GPIO_IDR_IDR8_Msk                    (0x1UL << GPIO_IDR_IDR8_Pos)       /*!< 0x00000100 */
#define GPIO_IDR_IDR8                        GPIO_IDR_IDR8_Msk                 /*!< Port input data, bit 8 */
#define GPIO_IDR_IDR9_Pos                    (9U)                              
#define GPIO_IDR_IDR9_Msk                    (0x1UL << GPIO_IDR_IDR9_Pos)       /*!< 0x00000200 */
#define GPIO_IDR_IDR9                        GPIO_IDR_IDR9_Msk                 /*!< Port input data, bit 9 */
#define GPIO_IDR_IDR10_Pos                   (10U)                             
#define GPIO_IDR_IDR10_Msk                   (0x1UL << GPIO_IDR_IDR10_Pos)      /*!< 0x00000400 */
#define GPIO_IDR_IDR10                       GPIO_IDR_IDR10_Msk                /*!< Port input data, bit 10 */
#define GPIO_IDR_IDR11_Pos                   (11U)                             
#define GPIO_IDR_IDR11_Msk                   (0x1UL << GPIO_IDR_IDR11_Pos)      /*!< 0x00000800 */
#define GPIO_IDR_IDR11                       GPIO_IDR_IDR11_Msk                /*!< Port input data, bit 11 */
#define GPIO_IDR_IDR12_Pos                   (12U)                             
#define GPIO_IDR_IDR12_Msk                   (0x1UL << GPIO_IDR_IDR12_Pos)      /*!< 0x00001000 */
#define GPIO_IDR_IDR12                       GPIO_IDR_IDR12_Msk                /*!< Port input data, bit 12 */
#define GPIO_IDR_IDR13_Pos                   (13U)                             
#define GPIO_IDR_IDR13_Msk                   (0x1UL << GPIO_IDR_IDR13_Pos)      /*!< 0x00002000 */
#define GPIO_IDR_IDR13                       GPIO_IDR_IDR13_Msk                /*!< Port input data, bit 13 */
#define GPIO_IDR_IDR14_Pos                   (14U)                             
#define GPIO_IDR_IDR14_Msk                   (0x1UL << GPIO_IDR_IDR14_Pos)      /*!< 0x00004000 */
#define GPIO_IDR_IDR14                       GPIO_IDR_IDR14_Msk                /*!< Port input data, bit 14 */
#define GPIO_IDR_IDR15_Pos                   (15U)                             
#define GPIO_IDR_IDR15_Msk                   (0x1UL << GPIO_IDR_IDR15_Pos)      /*!< 0x00008000 */
#define GPIO_IDR_IDR15                       GPIO_IDR_IDR15_Msk                /*!< Port input data, bit 15 */

/*******************  Bit definition for GPIO_ODR register  *******************/
#define GPIO_ODR_ODR0_Pos                    (0U)                              
#define GPIO_ODR_ODR0_Msk                    (0x1UL << GPIO_ODR_ODR0_Pos)       /*!< 0x00000001 */
#define GPIO_ODR_ODR0                        GPIO_ODR_ODR0_Msk                 /*!< Port output data, bit 0 */
#define GPIO_ODR_ODR1_Pos                    (1U)                              
#define GPIO_ODR_ODR1_Msk                    (0x1UL << GPIO_ODR_ODR1_Pos)       /*!< 0x00000002 */
#define GPIO_ODR_ODR1                        GPIO_ODR_ODR1_Msk                 /*!< Port output data, bit 1 */
#define GPIO_ODR_ODR2_Pos                    (2U)                              
#define GPIO_ODR_ODR2_Msk                    (0x1UL << GPIO_ODR_ODR2_Pos)       /*!< 0x00000004 */
#define GPIO_ODR_ODR2                        GPIO_ODR_ODR2_Msk                 /*!< Port output data, bit 2 */
#define GPIO_ODR_ODR3_Pos                    (3U)                              
#define GPIO_ODR_ODR3_Msk                    (0x1UL << GPIO_ODR_ODR3_Pos)       /*!< 0x00000008 */
#define GPIO_ODR_ODR3                        GPIO_ODR_ODR3_Msk                 /*!< Port output data, bit 3 */
#define GPIO_ODR_ODR4_Pos                    (4U)                              
#define GPIO_ODR_ODR4_Msk                    (0x1UL << GPIO_ODR_ODR4_Pos)       /*!< 0x00000010 */
#define GPIO_ODR_ODR4                        GPIO_ODR_ODR4_Msk                 /*!< Port output data, bit 4 */
#define GPIO_ODR_ODR5_Pos                    (5U)                              
#define GPIO_ODR_ODR5_Msk                    (0x1UL << GPIO_ODR_ODR5_Pos)       /*!< 0x00000020 */
#define GPIO_ODR_ODR5                        GPIO_ODR_ODR5_Msk                 /*!< Port output data, bit 5 */
#define GPIO_ODR_ODR6_Pos                    (6U)                              
#define GPIO_ODR_ODR6_Msk                    (0x1UL << GPIO_ODR_ODR6_Pos)       /*!< 0x00000040 */
#define GPIO_ODR_ODR6                        GPIO_ODR_ODR6_Msk                 /*!< Port output data, bit 6 */
#define GPIO_ODR_ODR7_Pos                    (7U)                              
#define GPIO_ODR_ODR7_Msk                    (0x1UL << GPIO_ODR_ODR7_Pos)       /*!< 0x00000080 */
#define GPIO_ODR_ODR7                        GPIO_ODR_ODR7_Msk                 /*!< Port output data, bit 7 */
#define GPIO_ODR_ODR8_Pos                    (8U)                              
#define GPIO_ODR_ODR8_Msk                    (0x1UL << GPIO_ODR_ODR8_Pos)       /*!< 0x00000100 */
#define GPIO_ODR_ODR8                        GPIO_ODR_ODR8_Msk                 /*!< Port output data, bit 8 */
#define GPIO_ODR_ODR9_Pos                    (9U)                              
#define GPIO_ODR_ODR9_Msk                    (0x1UL << GPIO_ODR_ODR9_Pos)       /*!< 0x00000200 */
#define GPIO_ODR_ODR9                        GPIO_ODR_ODR9_Msk                 /*!< Port output data, bit 9 */
#define GPIO_ODR_ODR10_Pos                   (10U)                             
#define GPIO_ODR_ODR10_Msk                   (0x1UL << GPIO_ODR_ODR10_Pos)      /*!< 0x00000400 */
#define GPIO_ODR_ODR10                       GPIO_ODR_ODR10_Msk                /*!< Port output data, bit 10 */
#define GPIO_ODR_ODR11_Pos                   (11U)                             
#define GPIO_ODR_ODR11_Msk                   (0x1UL << GPIO_ODR_ODR11_Pos)      /*!< 0x00000800 */
#define GPIO_ODR_ODR11                       GPIO_ODR_ODR11_Msk                /*!< Port output data, bit 11 */
#define GPIO_ODR_ODR12_Pos                   (12U)                             
#define GPIO_ODR_ODR12_Msk                   (0x1UL << GPIO_ODR_ODR12_Pos)      /*!< 0x00001000 */
#define GPIO_ODR_ODR12                       GPIO_ODR_ODR12_Msk                /*!< Port output data, bit 12 */
#define GPIO_ODR_ODR13_Pos                   (13U)                             
#define GPIO_ODR_ODR13_Msk                   (0x1UL << GPIO_ODR_ODR13_Pos)      /*!< 0x00002000 */
#define GPIO_ODR_ODR13                       GPIO_ODR_ODR13_Msk                /*!< Port output data, bit 13 */
#define GPIO_ODR_ODR14_Pos                   (14U)                             
#define GPIO_ODR_ODR14_Msk                   (0x1UL << GPIO_ODR_ODR14_Pos)      /*!< 0x00004000 */
#define GPIO_ODR_ODR14                       GPIO_ODR_ODR14_Msk                /*!< Port output data, bit 14 */
#define GPIO_ODR_ODR15_Pos                   (15U)                             
#define GPIO_ODR_ODR15_Msk                   (0x1UL << GPIO_ODR_ODR15_Pos)      /*!< 0x00008000 */
#define GPIO_ODR_ODR15                       GPIO_ODR_ODR15_Msk                /*!< Port output data, bit 15 */

/******************  Bit definition for GPIO_BSRR register  *******************/
#define GPIO_BSRR_BS0_Pos                    (0U)                              
#define GPIO_BSRR_BS0_Msk                    (0x1UL << GPIO_BSRR_BS0_Pos)       /*!< 0x00000001 */
#define GPIO_BSRR_BS0                        GPIO_BSRR_BS0_Msk                 /*!< Port x Set bit 0 */
#define GPIO_BSRR_BS1_Pos                    (1U)                              
#define GPIO_BSRR_BS1_Msk                    (0x1UL << GPIO_BSRR_BS1_Pos)       /*!< 0x00000002 */
#define GPIO_BSRR_BS1                        GPIO_BSRR_BS1_Msk                 /*!< Port x Set bit 1 */
#define GPIO_BSRR_BS2_Pos                    (2U)                              
#define GPIO_BSRR_BS2_Msk                    (0x1UL << GPIO_BSRR_BS2_Pos)       /*!< 0x00000004 */
#define GPIO_BSRR_BS2                        GPIO_BSRR_BS2_Msk                 /*!< Port x Set bit 2 */
#define GPIO_BSRR_BS3_Pos                    (3U)                              
#define GPIO_BSRR_BS3_Msk                    (0x1UL << GPIO_BSRR_BS3_Pos)       /*!< 0x00000008 */
#define GPIO_BSRR_BS3                        GPIO_BSRR_BS3_Msk                 /*!< Port x Set bit 3 */
#define GPIO_BSRR_BS4_Pos                    (4U)                              
#define GPIO_BSRR_BS4_Msk                    (0x1UL << GPIO_BSRR_BS4_Pos)       /*!< 0x00000010 */
#define GPIO_BSRR_BS4                        GPIO_BSRR_BS4_Msk                 /*!< Port x Set bit 4 */
#define GPIO_BSRR_BS5_Pos                    (5U)                              
#define GPIO_BSRR_BS5_Msk                    (0x1UL << GPIO_BSRR_BS5_Pos)       /*!< 0x00000020 */
#define GPIO_BSRR_BS5                        GPIO_BSRR_BS5_Msk                 /*!< Port x Set bit 5 */
#define GPIO_BSRR_BS6_Pos                    (6U)                              
#define GPIO_BSRR_BS6_Msk                    (0x1UL << GPIO_BSRR_BS6_Pos)       /*!< 0x00000040 */
#define GPIO_BSRR_BS6                        GPIO_BSRR_BS6_Msk                 /*!< Port x Set bit 6 */
#define GPIO_BSRR_BS7_Pos                    (7U)                              
#define GPIO_BSRR_BS7_Msk                    (0x1UL << GPIO_BSRR_BS7_Pos)       /*!< 0x00000080 */
#define GPIO_BSRR_BS7                        GPIO_BSRR_BS7_Msk                 /*!< Port x Set bit 7 */
#define GPIO_BSRR_BS8_Pos                    (8U)                              
#define GPIO_BSRR_BS8_Msk                    (0x1UL << GPIO_BSRR_BS8_Pos)       /*!< 0x00000100 */
#define GPIO_BSRR_BS8                        GPIO_BSRR_BS8_Msk                 /*!< Port x Set bit 8 */
#define GPIO_BSRR_BS9_Pos                    (9U)                              
#define GPIO_BSRR_BS9_Msk                    (0x1UL << GPIO_BSRR_BS9_Pos)       /*!< 0x00000200 */
#define GPIO_BSRR_BS9                        GPIO_BSRR_BS9_Msk                 /*!< Port x Set bit 9 */
#define GPIO_BSRR_BS10_Pos                   (10U)                             
#define GPIO_BSRR_BS10_Msk                   (0x1UL << GPIO_BSRR_BS10_Pos)      /*!< 0x00000400 */
#define GPIO_BSRR_BS10                       GPIO_BSRR_BS10_Msk                /*!< Port x Set bit 10 */
#define GPIO_BSRR_BS11_Pos                   (11U)                             
#define GPIO_BSRR_BS11_Msk                   (0x1UL << GPIO_BSRR_BS11_Pos)      /*!< 0x00000800 */
#define GPIO_BSRR_BS11                       GPIO_BSRR_BS11_Msk                /*!< Port x Set bit 11 */
#define GPIO_BSRR_BS12_Pos                   (12U)                             
#define GPIO_BSRR_BS12_Msk                   (0x1UL << GPIO_BSRR_BS12_Pos)      /*!< 0x00001000 */
#define GPIO_BSRR_BS12                       GPIO_BSRR_BS12_Msk                /*!< Port x Set bit 12 */
#define GPIO_BSRR_BS13_Pos                   (13U)                             
#define GPIO_BSRR_BS13_Msk                   (0x1UL << GPIO_BSRR_BS13_Pos)      /*!< 0x00002000 */
#define GPIO_BSRR_BS13                       GPIO_BSRR_BS13_Msk                /*!< Port x Set bit 13 */
#define GPIO_BSRR_BS14_Pos                   (14U)                             
#define GPIO_BSRR_BS14_Msk                   (0x1UL << GPIO_BSRR_BS14_Pos)      /*!< 0x00004000 */
#define GPIO_BSRR_BS14                       GPIO_BSRR_BS14_Msk                /*!< Port x Set bit 14 */
#define GPIO_BSRR_BS15_Pos                   (15U)                             
#define GPIO_BSRR_BS15_Msk                   (0x1UL << GPIO_BSRR_BS15_Pos)      /*!< 0x00008000 */
#define GPIO_BSRR_BS15                       GPIO_BSRR_BS15_Msk                /*!< Port x Set bit 15 */

#define GPIO_BSRR_BR0_Pos                    (16U)                             
#define GPIO_BSRR_BR0_Msk                    (0x1UL << GPIO_BSRR_BR0_Pos)       /*!< 0x00010000 */
#define GPIO_BSRR_BR0                        GPIO_BSRR_BR0_Msk                 /*!< Port x Reset bit 0 */
#define GPIO_BSRR_BR1_Pos                    (17U)                             
#define GPIO_BSRR_BR1_Msk                    (0x1UL << GPIO_BSRR_BR1_Pos)       /*!< 0x00020000 */
#define GPIO_BSRR_BR1                        GPIO_BSRR_BR1_Msk                 /*!< Port x Reset bit 1 */
#define GPIO_BSRR_BR2_Pos                    (18U)                             
#define GPIO_BSRR_BR2_Msk                    (0x1UL << GPIO_BSRR_BR2_Pos)       /*!< 0x00040000 */
#define GPIO_BSRR_BR2                        GPIO_BSRR_BR2_Msk                 /*!< Port x Reset bit 2 */
#define GPIO_BSRR_BR3_Pos                    (19U)                             
#define GPIO_BSRR_BR3_Msk                    (0x1UL << GPIO_BSRR_BR3_Pos)       /*!< 0x00080000 */
#define GPIO_BSRR_BR3                        GPIO_BSRR_BR3_Msk                 /*!< Port x Reset bit 3 */
#define GPIO_BSRR_BR4_Pos                    (20U)                             
#define GPIO_BSRR_BR4_Msk                    (0x1UL << GPIO_BSRR_BR4_Pos)       /*!< 0x00100000 */
#define GPIO_BSRR_BR4                        GPIO_BSRR_BR4_Msk                 /*!< Port x Reset bit 4 */
#define GPIO_BSRR_BR5_Pos                    (21U)                             
#define GPIO_BSRR_BR5_Msk                    (0x1UL << GPIO_BSRR_BR5_Pos)       /*!< 0x00200000 */
#define GPIO_BSRR_BR5                        GPIO_BSRR_BR5_Msk                 /*!< Port x Reset bit 5 */
#define GPIO_BSRR_BR6_Pos                    (22U)                             
#define GPIO_BSRR_BR6_Msk                    (0x1UL << GPIO_BSRR_BR6_Pos)       /*!< 0x00400000 */
#define GPIO_BSRR_BR6                        GPIO_BSRR_BR6_Msk                 /*!< Port x Reset bit 6 */
#define GPIO_BSRR_BR7_Pos                    (23U)                             
#define GPIO_BSRR_BR7_Msk                    (0x1UL << GPIO_BSRR_BR7_Pos)       /*!< 0x00800000 */
#define GPIO_BSRR_BR7                        GPIO_BSRR_BR7_Msk                 /*!< Port x Reset bit 7 */
#define GPIO_BSRR_BR8_Pos                    (24U)                             
#define GPIO_BSRR_BR8_Msk                    (0x1UL << GPIO_BSRR_BR8_Pos)       /*!< 0x01000000 */
#define GPIO_BSRR_BR8                        GPIO_BSRR_BR8_Msk                 /*!< Port x Reset bit 8 */
#define GPIO_BSRR_BR9_Pos                    (25U)                             
#define GPIO_BSRR_BR9_Msk                    (0x1UL << GPIO_BSRR_BR9_Pos)       /*!< 0x02000000 */
#define GPIO_BSRR_BR9                        GPIO_BSRR_BR9_Msk                 /*!< Port x Reset bit 9 */
#define GPIO_BSRR_BR10_Pos                   (26U)                             
#define GPIO_BSRR_BR10_Msk                   (0x1UL << GPIO_BSRR_BR10_Pos)      /*!< 0x04000000 */
#define GPIO_BSRR_BR10                       GPIO_BSRR_BR10_Msk                /*!< Port x Reset bit 10 */
#define GPIO_BSRR_BR11_Pos                   (27U)                             
#define GPIO_BSRR_BR11_Msk                   (0x1UL << GPIO_BSRR_BR11_Pos)      /*!< 0x08000000 */
#define GPIO_BSRR_BR11                       GPIO_BSRR_BR11_Msk                /*!< Port x Reset bit 11 */
#define GPIO_BSRR_BR12_Pos                   (28U)                             
#define GPIO_BSRR_BR12_Msk                   (0x1UL << GPIO_BSRR_BR12_Pos)      /*!< 0x10000000 */
#define GPIO_BSRR_BR12                       GPIO_BSRR_BR12_Msk                /*!< Port x Reset bit 12 */
#define GPIO_BSRR_BR13_Pos                   (29U)                             
#define GPIO_BSRR_BR13_Msk                   (0x1UL << GPIO_BSRR_BR13_Pos)      /*!< 0x20000000 */
#define GPIO_BSRR_BR13                       GPIO_BSRR_BR13_Msk                /*!< Port x Reset bit 13 */
#define GPIO_BSRR_BR14_Pos                   (30U)                             
#define GPIO_BSRR_BR14_Msk                   (0x1UL << GPIO_BSRR_BR14_Pos)      /*!< 0x40000000 */
#define GPIO_BSRR_BR14                       GPIO_BSRR_BR14_Msk                /*!< Port x Reset bit 14 */
#define GPIO_BSRR_BR15_Pos                   (31U)                             
#define GPIO_BSRR_BR15_Msk                   (0x1UL << GPIO_BSRR_BR15_Pos)      /*!< 0x80000000 */
#define GPIO_BSRR_BR15                       GPIO_BSRR_BR15_Msk                /*!< Port x Reset bit 15 */

/*******************  Bit definition for GPIO_BRR register  *******************/
#define GPIO_BRR_BR0_Pos                     (0U)                              
#define GPIO_BRR_BR0_Msk                     (0x1UL << GPIO_BRR_BR0_Pos)        /*!< 0x00000001 */
#define GPIO_BRR_BR0                         GPIO_BRR_BR0_Msk                  /*!< Port x Reset bit 0 */
#define GPIO_BRR_BR1_Pos                     (1U)                              
#define GPIO_BRR_BR1_Msk                     (0x1UL << GPIO_BRR_BR1_Pos)        /*!< 0x00000002 */
#define GPIO_BRR_BR1                         GPIO_BRR_BR1_Msk                  /*!< Port x Reset bit 1 */
#define GPIO_BRR_BR2_Pos                     (2U)                              
#define GPIO_BRR_BR2_Msk                     (0x1UL << GPIO_BRR_BR2_Pos)        /*!< 0x00000004 */
#define GPIO_BRR_BR2                         GPIO_BRR_BR2_Msk                  /*!< Port x Reset bit 2 */
#define GPIO_BRR_BR3_Pos                     (3U)                              
#define GPIO_BRR_BR3_Msk                     (0x1UL << GPIO_BRR_BR3_Pos)        /*!< 0x00000008 */
#define GPIO_BRR_BR3                         GPIO_BRR_BR3_Msk                  /*!< Port x Reset bit 3 */
#define GPIO_BRR_BR4_Pos                     (4U)                              
#define GPIO_BRR_BR4_Msk                     (0x1UL << GPIO_BRR_BR4_Pos)        /*!< 0x00000010 */
#define GPIO_BRR_BR4                         GPIO_BRR_BR4_Msk                  /*!< Port x Reset bit 4 */
#define GPIO_BRR_BR5_Pos                     (5U)                              
#define GPIO_BRR_BR5_Msk                     (0x1UL << GPIO_BRR_BR5_Pos)        /*!< 0x00000020 */
#define GPIO_BRR_BR5                         GPIO_BRR_BR5_Msk                  /*!< Port x Reset bit 5 */
#define GPIO_BRR_BR6_Pos                     (6U)                              
#define GPIO_BRR_BR6_Msk                     (0x1UL << GPIO_BRR_BR6_Pos)        /*!< 0x00000040 */
#define GPIO_BRR_BR6                         GPIO_BRR_BR6_Msk                  /*!< Port x Reset bit 6 */
#define GPIO_BRR_BR7_Pos                     (7U)                              
#define GPIO_BRR_BR7_Msk                     (0x1UL << GPIO_BRR_BR7_Pos)        /*!< 0x00000080 */
#define GPIO_BRR_BR7                         GPIO_BRR_BR7_Msk                  /*!< Port x Reset bit 7 */
#define GPIO_BRR_BR8_Pos                     (8U)                              
#define GPIO_BRR_BR8_Msk                     (0x1UL << GPIO_BRR_BR8_Pos)        /*!< 0x00000100 */
#define GPIO_BRR_BR8                         GPIO_BRR_BR8_Msk                  /*!< Port x Reset bit 8 */
#define GPIO_BRR_BR9_Pos                     (9U)                              
#define GPIO_BRR_BR9_Msk                     (0x1UL << GPIO_BRR_BR9_Pos)        /*!< 0x00000200 */
#define GPIO_BRR_BR9                         GPIO_BRR_BR9_Msk                  /*!< Port x Reset bit 9 */
#define GPIO_BRR_BR10_Pos                    (10U)                             
#define GPIO_BRR_BR10_Msk                    (0x1UL << GPIO_BRR_BR10_Pos)       /*!< 0x00000400 */
#define GPIO_BRR_BR10                        GPIO_BRR_BR10_Msk                 /*!< Port x Reset bit 10 */
#define GPIO_BRR_BR11_Pos                    (11U)                             
#define GPIO_BRR_BR11_Msk                    (0x1UL << GPIO_BRR_BR11_Pos)       /*!< 0x00000800 */
#define GPIO_BRR_BR11                        GPIO_BRR_BR11_Msk                 /*!< Port x Reset bit 11 */
#define GPIO_BRR_BR12_Pos                    (12U)                             
#define GPIO_BRR_BR12_Msk                    (0x1UL << GPIO_BRR_BR12_Pos)       /*!< 0x00001000 */
#define GPIO_BRR_BR12                        GPIO_BRR_BR12_Msk                 /*!< Port x Reset bit 12 */
#define GPIO_BRR_BR13_Pos                    (13U)                             
#define GPIO_BRR_BR13_Msk                    (0x1UL << GPIO_BRR_BR13_Pos)       /*!< 0x00002000 */
#define GPIO_BRR_BR13                        GPIO_BRR_BR13_Msk                 /*!< Port x Reset bit 13 */
#define GPIO_BRR_BR14_Pos                    (14U)                             
#define GPIO_BRR_BR14_Msk                    (0x1UL << GPIO_BRR_BR14_Pos)       /*!< 0x00004000 */
#define GPIO_BRR_BR14                        GPIO_BRR_BR14_Msk                 /*!< Port x Reset bit 14 */
#define GPIO_BRR_BR15_Pos                    (15U)                             
#define GPIO_BRR_BR15_Msk                    (0x1UL << GPIO_BRR_BR15_Pos)       /*!< 0x00008000 */
#define GPIO_BRR_BR15                        GPIO_BRR_BR15_Msk                 /*!< Port x Reset bit 15 */

/******************  Bit definition for GPIO_LCKR register  *******************/
#define GPIO_LCKR_LCK0_Pos                   (0U)                              
#define GPIO_LCKR_LCK0_Msk                   (0x1UL << GPIO_LCKR_LCK0_Pos)      /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                       GPIO_LCKR_LCK0_Msk                /*!< Port x Lock bit 0 */
#define GPIO_LCKR_LCK1_Pos                   (1U)                              
#define GPIO_LCKR_LCK1_Msk                   (0x1UL << GPIO_LCKR_LCK1_Pos)      /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                       GPIO_LCKR_LCK1_Msk                /*!< Port x Lock bit 1 */
#define GPIO_LCKR_LCK2_Pos                   (2U)                              
#define GPIO_LCKR_LCK2_Msk                   (0x1UL << GPIO_LCKR_LCK2_Pos)      /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                       GPIO_LCKR_LCK2_Msk                /*!< Port x Lock bit 2 */
#define GPIO_LCKR_LCK3_Pos                   (3U)                              
#define GPIO_LCKR_LCK3_Msk                   (0x1UL << GPIO_LCKR_LCK3_Pos)      /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                       GPIO_LCKR_LCK3_Msk                /*!< Port x Lock bit 3 */
#define GPIO_LCKR_LCK4_Pos                   (4U)                              
#define GPIO_LCKR_LCK4_Msk                   (0x1UL << GPIO_LCKR_LCK4_Pos)      /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                       GPIO_LCKR_LCK4_Msk                /*!< Port x Lock bit 4 */
#define GPIO_LCKR_LCK5_Pos                   (5U)                              
#define GPIO_LCKR_LCK5_Msk                   (0x1UL << GPIO_LCKR_LCK5_Pos)      /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                       GPIO_LCKR_LCK5_Msk                /*!< Port x Lock bit 5 */
#define GPIO_LCKR_LCK6_Pos                   (6U)                              
#define GPIO_LCKR_LCK6_Msk                   (0x1UL << GPIO_LCKR_LCK6_Pos)      /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                       GPIO_LCKR_LCK6_Msk                /*!< Port x Lock bit 6 */
#define GPIO_LCKR_LCK7_Pos                   (7U)                              
#define GPIO_LCKR_LCK7_Msk                   (0x1UL << GPIO_LCKR_LCK7_Pos)      /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                       GPIO_LCKR_LCK7_Msk                /*!< Port x Lock bit 7 */
#define GPIO_LCKR_LCK8_Pos                   (8U)                              
#define GPIO_LCKR_LCK8_Msk                   (0x1UL << GPIO_LCKR_LCK8_Pos)      /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                       GPIO_LCKR_LCK8_Msk                /*!< Port x Lock bit 8 */
#define GPIO_LCKR_LCK9_Pos                   (9U)                              
#define GPIO_LCKR_LCK9_Msk                   (0x1UL << GPIO_LCKR_LCK9_Pos)      /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                       GPIO_LCKR_LCK9_Msk                /*!< Port x Lock bit 9 */
#define GPIO_LCKR_LCK10_Pos                  (10U)                             
#define GPIO_LCKR_LCK10_Msk                  (0x1UL << GPIO_LCKR_LCK10_Pos)     /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                      GPIO_LCKR_LCK10_Msk               /*!< Port x Lock bit 10 */
#define GPIO_LCKR_LCK11_Pos                  (11U)                             
#define GPIO_LCKR_LCK11_Msk                  (0x1UL << GPIO_LCKR_LCK11_Pos)     /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                      GPIO_LCKR_LCK11_Msk               /*!< Port x Lock bit 11 */
#define GPIO_LCKR_LCK12_Pos                  (12U)                             
#define GPIO_LCKR_LCK12_Msk                  (0x1UL << GPIO_LCKR_LCK12_Pos)     /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                      GPIO_LCKR_LCK12_Msk               /*!< Port x Lock bit 12 */
#define GPIO_LCKR_LCK13_Pos                  (13U)                             
#define GPIO_LCKR_LCK13_Msk                  (0x1UL << GPIO_LCKR_LCK13_Pos)     /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                      GPIO_LCKR_LCK13_Msk               /*!< Port x Lock bit 13 */
#define GPIO_LCKR_LCK14_Pos                  (14U)                             
#define GPIO_LCKR_LCK14_Msk                  (0x1UL << GPIO_LCKR_LCK14_Pos)     /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                      GPIO_LCKR_LCK14_Msk               /*!< Port x Lock bit 14 */
#define GPIO_LCKR_LCK15_Pos                  (15U)                             
#define GPIO_LCKR_LCK15_Msk                  (0x1UL << GPIO_LCKR_LCK15_Pos)     /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                      GPIO_LCKR_LCK15_Msk               /*!< Port x Lock bit 15 */
#define GPIO_LCKR_LCKK_Pos                   (16U)                             
#define GPIO_LCKR_LCKK_Msk                   (0x1UL << GPIO_LCKR_LCKK_Pos)      /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                       GPIO_LCKR_LCKK_Msk                /*!< Lock key */

/*----------------------------------------------------------------------------*/

/******************  Bit definition for AFIO_EVCR register  *******************/
#define AFIO_EVCR_PIN_Pos                    (0U)                              
#define AFIO_EVCR_PIN_Msk                    (0xFUL << AFIO_EVCR_PIN_Pos)       /*!< 0x0000000F */
#define AFIO_EVCR_PIN                        AFIO_EVCR_PIN_Msk                 /*!< PIN[3:0] bits (Pin selection) */
#define AFIO_EVCR_PIN_0                      (0x1UL << AFIO_EVCR_PIN_Pos)       /*!< 0x00000001 */
#define AFIO_EVCR_PIN_1                      (0x2UL << AFIO_EVCR_PIN_Pos)       /*!< 0x00000002 */
#define AFIO_EVCR_PIN_2                      (0x4UL << AFIO_EVCR_PIN_Pos)       /*!< 0x00000004 */
#define AFIO_EVCR_PIN_3                      (0x8UL << AFIO_EVCR_PIN_Pos)       /*!< 0x00000008 */

/*!< PIN configuration */
#define AFIO_EVCR_PIN_PX0                    0x00000000U                       /*!< Pin 0 selected */
#define AFIO_EVCR_PIN_PX1_Pos                (0U)                              
#define AFIO_EVCR_PIN_PX1_Msk                (0x1UL << AFIO_EVCR_PIN_PX1_Pos)   /*!< 0x00000001 */
#define AFIO_EVCR_PIN_PX1                    AFIO_EVCR_PIN_PX1_Msk             /*!< Pin 1 selected */
#define AFIO_EVCR_PIN_PX2_Pos                (1U)                              
#define AFIO_EVCR_PIN_PX2_Msk                (0x1UL << AFIO_EVCR_PIN_PX2_Pos)   /*!< 0x00000002 */
#define AFIO_EVCR_PIN_PX2                    AFIO_EVCR_PIN_PX2_Msk             /*!< Pin 2 selected */
#define AFIO_EVCR_PIN_PX3_Pos                (0U)                              
#define AFIO_EVCR_PIN_PX3_Msk                (0x3UL << AFIO_EVCR_PIN_PX3_Pos)   /*!< 0x00000003 */
#define AFIO_EVCR_PIN_PX3                    AFIO_EVCR_PIN_PX3_Msk             /*!< Pin 3 selected */
#define AFIO_EVCR_PIN_PX4_Pos                (2U)                              
#define AFIO_EVCR_PIN_PX4_Msk                (0x1UL << AFIO_EVCR_PIN_PX4_Pos)   /*!< 0x00000004 */
#define AFIO_EVCR_PIN_PX4                    AFIO_EVCR_PIN_PX4_Msk             /*!< Pin 4 selected */
#define AFIO_EVCR_PIN_PX5_Pos                (0U)                              
#define AFIO_EVCR_PIN_PX5_Msk                (0x5UL << AFIO_EVCR_PIN_PX5_Pos)   /*!< 0x00000005 */
#define AFIO_EVCR_PIN_PX5                    AFIO_EVCR_PIN_PX5_Msk             /*!< Pin 5 selected */
#define AFIO_EVCR_PIN_PX6_Pos                (1U)                              
#define AFIO_EVCR_PIN_PX6_Msk                (0x3UL << AFIO_EVCR_PIN_PX6_Pos)   /*!< 0x00000006 */
#define AFIO_EVCR_PIN_PX6                    AFIO_EVCR_PIN_PX6_Msk             /*!< Pin 6 selected */
#define AFIO_EVCR_PIN_PX7_Pos                (0U)                              
#define AFIO_EVCR_PIN_PX7_Msk                (0x7UL << AFIO_EVCR_PIN_PX7_Pos)   /*!< 0x00000007 */
#define AFIO_EVCR_PIN_PX7                    AFIO_EVCR_PIN_PX7_Msk             /*!< Pin 7 selected */
#define AFIO_EVCR_PIN_PX8_Pos                (3U)                              
#define AFIO_EVCR_PIN_PX8_Msk                (0x1UL << AFIO_EVCR_PIN_PX8_Pos)   /*!< 0x00000008 */
#define AFIO_EVCR_PIN_PX8                    AFIO_EVCR_PIN_PX8_Msk             /*!< Pin 8 selected */
#define AFIO_EVCR_PIN_PX9_Pos                (0U)                              
#define AFIO_EVCR_PIN_PX9_Msk                (0x9UL << AFIO_EVCR_PIN_PX9_Pos)   /*!< 0x00000009 */
#define AFIO_EVCR_PIN_PX9                    AFIO_EVCR_PIN_PX9_Msk             /*!< Pin 9 selected */
#define AFIO_EVCR_PIN_PX10_Pos               (1U)                              
#define AFIO_EVCR_PIN_PX10_Msk               (0x5UL << AFIO_EVCR_PIN_PX10_Pos)  /*!< 0x0000000A */
#define AFIO_EVCR_PIN_PX10                   AFIO_EVCR_PIN_PX10_Msk            /*!< Pin 10 selected */
#define AFIO_EVCR_PIN_PX11_Pos               (0U)                              
#define AFIO_EVCR_PIN_PX11_Msk               (0xBUL << AFIO_EVCR_PIN_PX11_Pos)  /*!< 0x0000000B */
#define AFIO_EVCR_PIN_PX11                   AFIO_EVCR_PIN_PX11_Msk            /*!< Pin 11 selected */
#define AFIO_EVCR_PIN_PX12_Pos               (2U)                              
#define AFIO_EVCR_PIN_PX12_Msk               (0x3UL << AFIO_EVCR_PIN_PX12_Pos)  /*!< 0x0000000C */
#define AFIO_EVCR_PIN_PX12                   AFIO_EVCR_PIN_PX12_Msk            /*!< Pin 12 selected */
#define AFIO_EVCR_PIN_PX13_Pos               (0U)                              
#define AFIO_EVCR_PIN_PX13_Msk               (0xDUL << AFIO_EVCR_PIN_PX13_Pos)  /*!< 0x0000000D */
#define AFIO_EVCR_PIN_PX13                   AFIO_EVCR_PIN_PX13_Msk            /*!< Pin 13 selected */
#define AFIO_EVCR_PIN_PX14_Pos               (1U)                              
#define AFIO_EVCR_PIN_PX14_Msk               (0x7UL << AFIO_EVCR_PIN_PX14_Pos)  /*!< 0x0000000E */
#define AFIO_EVCR_PIN_PX14                   AFIO_EVCR_PIN_PX14_Msk            /*!< Pin 14 selected */
#define AFIO_EVCR_PIN_PX15_Pos               (0U)                              
#define AFIO_EVCR_PIN_PX15_Msk               (0xFUL << AFIO_EVCR_PIN_PX15_Pos)  /*!< 0x0000000F */
#define AFIO_EVCR_PIN_PX15                   AFIO_EVCR_PIN_PX15_Msk            /*!< Pin 15 selected */

#define AFIO_EVCR_PORT_Pos                   (4U)                              
#define AFIO_EVCR_PORT_Msk                   (0x7UL << AFIO_EVCR_PORT_Pos)      /*!< 0x00000070 */
#define AFIO_EVCR_PORT                       AFIO_EVCR_PORT_Msk                /*!< PORT[2:0] bits (Port selection) */
#define AFIO_EVCR_PORT_0                     (0x1UL << AFIO_EVCR_PORT_Pos)      /*!< 0x00000010 */
#define AFIO_EVCR_PORT_1                     (0x2UL << AFIO_EVCR_PORT_Pos)      /*!< 0x00000020 */
#define AFIO_EVCR_PORT_2                     (0x4UL << AFIO_EVCR_PORT_Pos)      /*!< 0x00000040 */

/*!< PORT configuration */
#define AFIO_EVCR_PORT_PA                    0x00000000                        /*!< Port A selected */
#define AFIO_EVCR_PORT_PB_Pos                (4U)                              
#define AFIO_EVCR_PORT_PB_Msk                (0x1UL << AFIO_EVCR_PORT_PB_Pos)   /*!< 0x00000010 */
#define AFIO_EVCR_PORT_PB                    AFIO_EVCR_PORT_PB_Msk             /*!< Port B selected */
#define AFIO_EVCR_PORT_PC_Pos                (5U)                              
#define AFIO_EVCR_PORT_PC_Msk                (0x1UL << AFIO_EVCR_PORT_PC_Pos)   /*!< 0x00000020 */
#define AFIO_EVCR_PORT_PC                    AFIO_EVCR_PORT_PC_Msk             /*!< Port C selected */
#define AFIO_EVCR_PORT_PD_Pos                (4U)                              
#define AFIO_EVCR_PORT_PD_Msk                (0x3UL << AFIO_EVCR_PORT_PD_Pos)   /*!< 0x00000030 */
#define AFIO_EVCR_PORT_PD                    AFIO_EVCR_PORT_PD_Msk             /*!< Port D selected */
#define AFIO_EVCR_PORT_PE_Pos                (6U)                              
#define AFIO_EVCR_PORT_PE_Msk                (0x1UL << AFIO_EVCR_PORT_PE_Pos)   /*!< 0x00000040 */
#define AFIO_EVCR_PORT_PE                    AFIO_EVCR_PORT_PE_Msk             /*!< Port E selected */

#define AFIO_EVCR_EVOE_Pos                   (7U)                              
#define AFIO_EVCR_EVOE_Msk                   (0x1UL << AFIO_EVCR_EVOE_Pos)      /*!< 0x00000080 */
#define AFIO_EVCR_EVOE                       AFIO_EVCR_EVOE_Msk                /*!< Event Output Enable */

/******************  Bit definition for AFIO_MAPR register  *******************/
#define AFIO_MAPR_SPI1_REMAP_Pos             (0U)                              
#define AFIO_MAPR_SPI1_REMAP_Msk             (0x1UL << AFIO_MAPR_SPI1_REMAP_Pos) /*!< 0x00000001 */
#define AFIO_MAPR_SPI1_REMAP                 AFIO_MAPR_SPI1_REMAP_Msk          /*!< SPI1 remapping */
#define AFIO_MAPR_I2C1_REMAP_Pos             (1U)                              
#define AFIO_MAPR_I2C1_REMAP_Msk             (0x1UL << AFIO_MAPR_I2C1_REMAP_Pos) /*!< 0x00000002 */
#define AFIO_MAPR_I2C1_REMAP                 AFIO_MAPR_I2C1_REMAP_Msk          /*!< I2C1 remapping */
#define AFIO_MAPR_USART1_REMAP_Pos           (2U)                              
#define AFIO_MAPR_USART1_REMAP_Msk           (0x1UL << AFIO_MAPR_USART1_REMAP_Pos) /*!< 0x00000004 */
#define AFIO_MAPR_USART1_REMAP               AFIO_MAPR_USART1_REMAP_Msk        /*!< USART1 remapping */
#define AFIO_MAPR_USART2_REMAP_Pos           (3U)                              
#define AFIO_MAPR_USART2_REMAP_Msk           (0x1UL << AFIO_MAPR_USART2_REMAP_Pos) /*!< 0x00000008 */
#define AFIO_MAPR_USART2_REMAP               AFIO_MAPR_USART2_REMAP_Msk        /*!< USART2 remapping */


#define AFIO_MAPR_TIM1_REMAP_Pos             (6U)                              
#define AFIO_MAPR_TIM1_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM1_REMAP_Pos) /*!< 0x000000C0 */
#define AFIO_MAPR_TIM1_REMAP                 AFIO_MAPR_TIM1_REMAP_Msk          /*!< TIM1_REMAP[1:0] bits (TIM1 remapping) */
#define AFIO_MAPR_TIM1_REMAP_0               (0x1UL << AFIO_MAPR_TIM1_REMAP_Pos) /*!< 0x00000040 */
#define AFIO_MAPR_TIM1_REMAP_1               (0x2UL << AFIO_MAPR_TIM1_REMAP_Pos) /*!< 0x00000080 */

/*!< TIM1_REMAP configuration */
#define AFIO_MAPR_TIM1_REMAP_NOREMAP         0x00000000U                          /*!< No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15) */
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Pos (6U)                             
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Msk (0x1UL << AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Pos) /*!< 0x00000040 */
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP    AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Msk /*!< Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1) */
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP_Pos   (6U)                              
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM1_REMAP_FULLREMAP_Pos) /*!< 0x000000C0 */
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP       AFIO_MAPR_TIM1_REMAP_FULLREMAP_Msk /*!< Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12) */

#define AFIO_MAPR_TIM2_REMAP_Pos             (8U)                              
#define AFIO_MAPR_TIM2_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM2_REMAP_Pos) /*!< 0x00000300 */
#define AFIO_MAPR_TIM2_REMAP                 AFIO_MAPR_TIM2_REMAP_Msk          /*!< TIM2_REMAP[1:0] bits (TIM2 remapping) */
#define AFIO_MAPR_TIM2_REMAP_0               (0x1UL << AFIO_MAPR_TIM2_REMAP_Pos) /*!< 0x00000100 */
#define AFIO_MAPR_TIM2_REMAP_1               (0x2UL << AFIO_MAPR_TIM2_REMAP_Pos) /*!< 0x00000200 */

/*!< TIM2_REMAP configuration */
#define AFIO_MAPR_TIM2_REMAP_NOREMAP         0x00000000U                          /*!< No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3) */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Pos (8U)                            
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Msk (0x1UL << AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Pos) /*!< 0x00000100 */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1   AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Msk /*!< Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3) */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Pos (9U)                            
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Msk (0x1UL << AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Pos) /*!< 0x00000200 */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2   AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Msk /*!< Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11) */
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP_Pos   (8U)                              
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM2_REMAP_FULLREMAP_Pos) /*!< 0x00000300 */
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP       AFIO_MAPR_TIM2_REMAP_FULLREMAP_Msk /*!< Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11) */

#define AFIO_MAPR_TIM3_REMAP_Pos             (10U)                             
#define AFIO_MAPR_TIM3_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM3_REMAP_Pos) /*!< 0x00000C00 */
#define AFIO_MAPR_TIM3_REMAP                 AFIO_MAPR_TIM3_REMAP_Msk          /*!< TIM3_REMAP[1:0] bits (TIM3 remapping) */
#define AFIO_MAPR_TIM3_REMAP_0               (0x1UL << AFIO_MAPR_TIM3_REMAP_Pos) /*!< 0x00000400 */
#define AFIO_MAPR_TIM3_REMAP_1               (0x2UL << AFIO_MAPR_TIM3_REMAP_Pos) /*!< 0x00000800 */

/*!< TIM3_REMAP configuration */
#define AFIO_MAPR_TIM3_REMAP_NOREMAP         0x00000000U                          /*!< No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1) */
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Pos (11U)                            
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Msk (0x1UL << AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Pos) /*!< 0x00000800 */
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP    AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Msk /*!< Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1) */
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP_Pos   (10U)                             
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM3_REMAP_FULLREMAP_Pos) /*!< 0x00000C00 */
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP       AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk /*!< Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9) */


#define AFIO_MAPR_CAN_REMAP_Pos              (13U)                             
#define AFIO_MAPR_CAN_REMAP_Msk              (0x3UL << AFIO_MAPR_CAN_REMAP_Pos) /*!< 0x00006000 */
#define AFIO_MAPR_CAN_REMAP                  AFIO_MAPR_CAN_REMAP_Msk           /*!< CAN_REMAP[1:0] bits (CAN Alternate function remapping) */
#define AFIO_MAPR_CAN_REMAP_0                (0x1UL << AFIO_MAPR_CAN_REMAP_Pos) /*!< 0x00002000 */
#define AFIO_MAPR_CAN_REMAP_1                (0x2UL << AFIO_MAPR_CAN_REMAP_Pos) /*!< 0x00004000 */

/*!< CAN_REMAP configuration */
#define AFIO_MAPR_CAN_REMAP_REMAP1           0x00000000U                          /*!< CANRX mapped to PA11, CANTX mapped to PA12 */
#define AFIO_MAPR_CAN_REMAP_REMAP2_Pos       (14U)                             
#define AFIO_MAPR_CAN_REMAP_REMAP2_Msk       (0x1UL << AFIO_MAPR_CAN_REMAP_REMAP2_Pos) /*!< 0x00004000 */
#define AFIO_MAPR_CAN_REMAP_REMAP2           AFIO_MAPR_CAN_REMAP_REMAP2_Msk    /*!< CANRX mapped to PB8, CANTX mapped to PB9 */
#define AFIO_MAPR_CAN_REMAP_REMAP3_Pos       (13U)                             
#define AFIO_MAPR_CAN_REMAP_REMAP3_Msk       (0x3UL << AFIO_MAPR_CAN_REMAP_REMAP3_Pos) /*!< 0x00006000 */
#define AFIO_MAPR_CAN_REMAP_REMAP3           AFIO_MAPR_CAN_REMAP_REMAP3_Msk    /*!< CANRX mapped to PD0, CANTX mapped to PD1 */

#define AFIO_MAPR_PD01_REMAP_Pos             (15U)                             
#define AFIO_MAPR_PD01_REMAP_Msk             (0x1UL << AFIO_MAPR_PD01_REMAP_Pos) /*!< 0x00008000 */
#define AFIO_MAPR_PD01_REMAP                 AFIO_MAPR_PD01_REMAP_Msk          /*!< Port D0/Port D1 mapping on OSC_IN/OSC_OUT */

/*!< SWJ_CFG configuration */
#define AFIO_MAPR_SWJ_CFG_Pos                (24U)                             
#define AFIO_MAPR_SWJ_CFG_Msk                (0x7UL << AFIO_MAPR_SWJ_CFG_Pos)   /*!< 0x07000000 */
#define AFIO_MAPR_SWJ_CFG                    AFIO_MAPR_SWJ_CFG_Msk             /*!< SWJ_CFG[2:0] bits (Serial Wire JTAG configuration) */
#define AFIO_MAPR_SWJ_CFG_0                  (0x1UL << AFIO_MAPR_SWJ_CFG_Pos)   /*!< 0x01000000 */
#define AFIO_MAPR_SWJ_CFG_1                  (0x2UL << AFIO_MAPR_SWJ_CFG_Pos)   /*!< 0x02000000 */
#define AFIO_MAPR_SWJ_CFG_2                  (0x4UL << AFIO_MAPR_SWJ_CFG_Pos)   /*!< 0x04000000 */

#define AFIO_MAPR_SWJ_CFG_RESET              0x00000000U                          /*!< Full SWJ (JTAG-DP + SW-DP) : Reset State */
#define AFIO_MAPR_SWJ_CFG_NOJNTRST_Pos       (24U)                             
#define AFIO_MAPR_SWJ_CFG_NOJNTRST_Msk       (0x1UL << AFIO_MAPR_SWJ_CFG_NOJNTRST_Pos) /*!< 0x01000000 */
#define AFIO_MAPR_SWJ_CFG_NOJNTRST           AFIO_MAPR_SWJ_CFG_NOJNTRST_Msk    /*!< Full SWJ (JTAG-DP + SW-DP) but without JNTRST */
#define AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Pos    (25U)                             
#define AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Msk    (0x1UL << AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Pos) /*!< 0x02000000 */
#define AFIO_MAPR_SWJ_CFG_JTAGDISABLE        AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Msk /*!< JTAG-DP Disabled and SW-DP Enabled */
#define AFIO_MAPR_SWJ_CFG_DISABLE_Pos        (26U)                             
#define AFIO_MAPR_SWJ_CFG_DISABLE_Msk        (0x1UL << AFIO_MAPR_SWJ_CFG_DISABLE_Pos) /*!< 0x04000000 */
#define AFIO_MAPR_SWJ_CFG_DISABLE            AFIO_MAPR_SWJ_CFG_DISABLE_Msk     /*!< JTAG-DP Disabled and SW-DP Disabled */


/*****************  Bit definition for AFIO_EXTICR1 register  *****************/
#define AFIO_EXTICR1_EXTI0_Pos               (0U)                              
#define AFIO_EXTICR1_EXTI0_Msk               (0xFUL << AFIO_EXTICR1_EXTI0_Pos)  /*!< 0x0000000F */
#define AFIO_EXTICR1_EXTI0                   AFIO_EXTICR1_EXTI0_Msk            /*!< EXTI 0 configuration */
#define AFIO_EXTICR1_EXTI1_Pos               (4U)                              
#define AFIO_EXTICR1_EXTI1_Msk               (0xFUL << AFIO_EXTICR1_EXTI1_Pos)  /*!< 0x000000F0 */
#define AFIO_EXTICR1_EXTI1                   AFIO_EXTICR1_EXTI1_Msk            /*!< EXTI 1 configuration */
#define AFIO_EXTICR1_EXTI2_Pos               (8U)                              
#define AFIO_EXTICR1_EXTI2_Msk               (0xFUL << AFIO_EXTICR1_EXTI2_Pos)  /*!< 0x00000F00 */
#define AFIO_EXTICR1_EXTI2                   AFIO_EXTICR1_EXTI2_Msk            /*!< EXTI 2 configuration */
#define AFIO_EXTICR1_EXTI3_Pos               (12U)                             
#define AFIO_EXTICR1_EXTI3_Msk               (0xFUL << AFIO_EXTICR1_EXTI3_Pos)  /*!< 0x0000F000 */
#define AFIO_EXTICR1_EXTI3                   AFIO_EXTICR1_EXTI3_Msk            /*!< EXTI 3 configuration */

/*!< EXTI0 configuration */
#define AFIO_EXTICR1_EXTI0_PA                0x00000000U                          /*!< PA[0] pin */
#define AFIO_EXTICR1_EXTI0_PB_Pos            (0U)                              
#define AFIO_EXTICR1_EXTI0_PB_Msk            (0x1UL << AFIO_EXTICR1_EXTI0_PB_Pos) /*!< 0x00000001 */
#define AFIO_EXTICR1_EXTI0_PB                AFIO_EXTICR1_EXTI0_PB_Msk         /*!< PB[0] pin */
#define AFIO_EXTICR1_EXTI0_PC_Pos            (1U)                              
#define AFIO_EXTICR1_EXTI0_PC_Msk            (0x1UL << AFIO_EXTICR1_EXTI0_PC_Pos) /*!< 0x00000002 */
#define AFIO_EXTICR1_EXTI0_PC                AFIO_EXTICR1_EXTI0_PC_Msk         /*!< PC[0] pin */
#define AFIO_EXTICR1_EXTI0_PD_Pos            (0U)                              
#define AFIO_EXTICR1_EXTI0_PD_Msk            (0x3UL << AFIO_EXTICR1_EXTI0_PD_Pos) /*!< 0x00000003 */
#define AFIO_EXTICR1_EXTI0_PD                AFIO_EXTICR1_EXTI0_PD_Msk         /*!< PD[0] pin */
#define AFIO_EXTICR1_EXTI0_PE_Pos            (2U)                              
#define AFIO_EXTICR1_EXTI0_PE_Msk            (0x1UL << AFIO_EXTICR1_EXTI0_PE_Pos) /*!< 0x00000004 */
#define AFIO_EXTICR1_EXTI0_PE                AFIO_EXTICR1_EXTI0_PE_Msk         /*!< PE[0] pin */
#define AFIO_EXTICR1_EXTI0_PF_Pos            (0U)                              
#define AFIO_EXTICR1_EXTI0_PF_Msk            (0x5UL << AFIO_EXTICR1_EXTI0_PF_Pos) /*!< 0x00000005 */
#define AFIO_EXTICR1_EXTI0_PF                AFIO_EXTICR1_EXTI0_PF_Msk         /*!< PF[0] pin */
#define AFIO_EXTICR1_EXTI0_PG_Pos            (1U)                              
#define AFIO_EXTICR1_EXTI0_PG_Msk            (0x3UL << AFIO_EXTICR1_EXTI0_PG_Pos) /*!< 0x00000006 */
#define AFIO_EXTICR1_EXTI0_PG                AFIO_EXTICR1_EXTI0_PG_Msk         /*!< PG[0] pin */

/*!< EXTI1 configuration */
#define AFIO_EXTICR1_EXTI1_PA                0x00000000U                          /*!< PA[1] pin */
#define AFIO_EXTICR1_EXTI1_PB_Pos            (4U)                              
#define AFIO_EXTICR1_EXTI1_PB_Msk            (0x1UL << AFIO_EXTICR1_EXTI1_PB_Pos) /*!< 0x00000010 */
#define AFIO_EXTICR1_EXTI1_PB                AFIO_EXTICR1_EXTI1_PB_Msk         /*!< PB[1] pin */
#define AFIO_EXTICR1_EXTI1_PC_Pos            (5U)                              
#define AFIO_EXTICR1_EXTI1_PC_Msk            (0x1UL << AFIO_EXTICR1_EXTI1_PC_Pos) /*!< 0x00000020 */
#define AFIO_EXTICR1_EXTI1_PC                AFIO_EXTICR1_EXTI1_PC_Msk         /*!< PC[1] pin */
#define AFIO_EXTICR1_EXTI1_PD_Pos            (4U)                              
#define AFIO_EXTICR1_EXTI1_PD_Msk            (0x3UL << AFIO_EXTICR1_EXTI1_PD_Pos) /*!< 0x00000030 */
#define AFIO_EXTICR1_EXTI1_PD                AFIO_EXTICR1_EXTI1_PD_Msk         /*!< PD[1] pin */
#define AFIO_EXTICR1_EXTI1_PE_Pos            (6U)                              
#define AFIO_EXTICR1_EXTI1_PE_Msk            (0x1UL << AFIO_EXTICR1_EXTI1_PE_Pos) /*!< 0x00000040 */
#define AFIO_EXTICR1_EXTI1_PE                AFIO_EXTICR1_EXTI1_PE_Msk         /*!< PE[1] pin */
#define AFIO_EXTICR1_EXTI1_PF_Pos            (4U)                              
#define AFIO_EXTICR1_EXTI1_PF_Msk            (0x5UL << AFIO_EXTICR1_EXTI1_PF_Pos) /*!< 0x00000050 */
#define AFIO_EXTICR1_EXTI1_PF                AFIO_EXTICR1_EXTI1_PF_Msk         /*!< PF[1] pin */
#define AFIO_EXTICR1_EXTI1_PG_Pos            (5U)                              
#define AFIO_EXTICR1_EXTI1_PG_Msk            (0x3UL << AFIO_EXTICR1_EXTI1_PG_Pos) /*!< 0x00000060 */
#define AFIO_EXTICR1_EXTI1_PG                AFIO_EXTICR1_EXTI1_PG_Msk         /*!< PG[1] pin */

/*!< EXTI2 configuration */  
#define AFIO_EXTICR1_EXTI2_PA                0x00000000U                          /*!< PA[2] pin */
#define AFIO_EXTICR1_EXTI2_PB_Pos            (8U)                              
#define AFIO_EXTICR1_EXTI2_PB_Msk            (0x1UL << AFIO_EXTICR1_EXTI2_PB_Pos) /*!< 0x00000100 */
#define AFIO_EXTICR1_EXTI2_PB                AFIO_EXTICR1_EXTI2_PB_Msk         /*!< PB[2] pin */
#define AFIO_EXTICR1_EXTI2_PC_Pos            (9U)                              
#define AFIO_EXTICR1_EXTI2_PC_Msk            (0x1UL << AFIO_EXTICR1_EXTI2_PC_Pos) /*!< 0x00000200 */
#define AFIO_EXTICR1_EXTI2_PC                AFIO_EXTICR1_EXTI2_PC_Msk         /*!< PC[2] pin */
#define AFIO_EXTICR1_EXTI2_PD_Pos            (8U)                              
#define AFIO_EXTICR1_EXTI2_PD_Msk            (0x3UL << AFIO_EXTICR1_EXTI2_PD_Pos) /*!< 0x00000300 */
#define AFIO_EXTICR1_EXTI2_PD                AFIO_EXTICR1_EXTI2_PD_Msk         /*!< PD[2] pin */
#define AFIO_EXTICR1_EXTI2_PE_Pos            (10U)                             
#define AFIO_EXTICR1_EXTI2_PE_Msk            (0x1UL << AFIO_EXTICR1_EXTI2_PE_Pos) /*!< 0x00000400 */
#define AFIO_EXTICR1_EXTI2_PE                AFIO_EXTICR1_EXTI2_PE_Msk         /*!< PE[2] pin */
#define AFIO_EXTICR1_EXTI2_PF_Pos            (8U)                              
#define AFIO_EXTICR1_EXTI2_PF_Msk            (0x5UL << AFIO_EXTICR1_EXTI2_PF_Pos) /*!< 0x00000500 */
#define AFIO_EXTICR1_EXTI2_PF                AFIO_EXTICR1_EXTI2_PF_Msk         /*!< PF[2] pin */
#define AFIO_EXTICR1_EXTI2_PG_Pos            (9U)                              
#define AFIO_EXTICR1_EXTI2_PG_Msk            (0x3UL << AFIO_EXTICR1_EXTI2_PG_Pos) /*!< 0x00000600 */
#define AFIO_EXTICR1_EXTI2_PG                AFIO_EXTICR1_EXTI2_PG_Msk         /*!< PG[2] pin */

/*!< EXTI3 configuration */
#define AFIO_EXTICR1_EXTI3_PA                0x00000000U                          /*!< PA[3] pin */
#define AFIO_EXTICR1_EXTI3_PB_Pos            (12U)                             
#define AFIO_EXTICR1_EXTI3_PB_Msk            (0x1UL << AFIO_EXTICR1_EXTI3_PB_Pos) /*!< 0x00001000 */
#define AFIO_EXTICR1_EXTI3_PB                AFIO_EXTICR1_EXTI3_PB_Msk         /*!< PB[3] pin */
#define AFIO_EXTICR1_EXTI3_PC_Pos            (13U)                             
#define AFIO_EXTICR1_EXTI3_PC_Msk            (0x1UL << AFIO_EXTICR1_EXTI3_PC_Pos) /*!< 0x00002000 */
#define AFIO_EXTICR1_EXTI3_PC                AFIO_EXTICR1_EXTI3_PC_Msk         /*!< PC[3] pin */
#define AFIO_EXTICR1_EXTI3_PD_Pos            (12U)                             
#define AFIO_EXTICR1_EXTI3_PD_Msk            (0x3UL << AFIO_EXTICR1_EXTI3_PD_Pos) /*!< 0x00003000 */
#define AFIO_EXTICR1_EXTI3_PD                AFIO_EXTICR1_EXTI3_PD_Msk         /*!< PD[3] pin */
#define AFIO_EXTICR1_EXTI3_PE_Pos            (14U)                             
#define AFIO_EXTICR1_EXTI3_PE_Msk            (0x1UL << AFIO_EXTICR1_EXTI3_PE_Pos) /*!< 0x00004000 */
#define AFIO_EXTICR1_EXTI3_PE                AFIO_EXTICR1_EXTI3_PE_Msk         /*!< PE[3] pin */
#define AFIO_EXTICR1_EXTI3_PF_Pos            (12U)                             
#define AFIO_EXTICR1_EXTI3_PF_Msk            (0x5UL << AFIO_EXTICR1_EXTI3_PF_Pos) /*!< 0x00005000 */
#define AFIO_EXTICR1_EXTI3_PF                AFIO_EXTICR1_EXTI3_PF_Msk         /*!< PF[3] pin */
#define AFIO_EXTICR1_EXTI3_PG_Pos            (13U)                             
#define AFIO_EXTICR1_EXTI3_PG_Msk            (0x3UL << AFIO_EXTICR1_EXTI3_PG_Pos) /*!< 0x00006000 */
#define AFIO_EXTICR1_EXTI3_PG                AFIO_EXTICR1_EXTI3_PG_Msk         /*!< PG[3] pin */

/*****************  Bit definition for AFIO_EXTICR2 register  *****************/
#define AFIO_EXTICR2_EXTI4_Pos               (0U)                              
#define AFIO_EXTICR2_EXTI4_Msk               (0xFUL << AFIO_EXTICR2_EXTI4_Pos)  /*!< 0x0000000F */
#define AFIO_EXTICR2_EXTI4                   AFIO_EXTICR2_EXTI4_Msk            /*!< EXTI 4 configuration */
#define AFIO_EXTICR2_EXTI5_Pos               (4U)                              
#define AFIO_EXTICR2_EXTI5_Msk               (0xFUL << AFIO_EXTICR2_EXTI5_Pos)  /*!< 0x000000F0 */
#define AFIO_EXTICR2_EXTI5                   AFIO_EXTICR2_EXTI5_Msk            /*!< EXTI 5 configuration */
#define AFIO_EXTICR2_EXTI6_Pos               (8U)                              
#define AFIO_EXTICR2_EXTI6_Msk               (0xFUL << AFIO_EXTICR2_EXTI6_Pos)  /*!< 0x00000F00 */
#define AFIO_EXTICR2_EXTI6                   AFIO_EXTICR2_EXTI6_Msk            /*!< EXTI 6 configuration */
#define AFIO_EXTICR2_EXTI7_Pos               (12U)                             
#define AFIO_EXTICR2_EXTI7_Msk               (0xFUL << AFIO_EXTICR2_EXTI7_Pos)  /*!< 0x0000F000 */
#define AFIO_EXTICR2_EXTI7                   AFIO_EXTICR2_EXTI7_Msk            /*!< EXTI 7 configuration */

/*!< EXTI4 configuration */
#define AFIO_EXTICR2_EXTI4_PA                0x00000000U                          /*!< PA[4] pin */
#define AFIO_EXTICR2_EXTI4_PB_Pos            (0U)                              
#define AFIO_EXTICR2_EXTI4_PB_Msk            (0x1UL << AFIO_EXTICR2_EXTI4_PB_Pos) /*!< 0x00000001 */
#define AFIO_EXTICR2_EXTI4_PB                AFIO_EXTICR2_EXTI4_PB_Msk         /*!< PB[4] pin */
#define AFIO_EXTICR2_EXTI4_PC_Pos            (1U)                              
#define AFIO_EXTICR2_EXTI4_PC_Msk            (0x1UL << AFIO_EXTICR2_EXTI4_PC_Pos) /*!< 0x00000002 */
#define AFIO_EXTICR2_EXTI4_PC                AFIO_EXTICR2_EXTI4_PC_Msk         /*!< PC[4] pin */
#define AFIO_EXTICR2_EXTI4_PD_Pos            (0U)                              
#define AFIO_EXTICR2_EXTI4_PD_Msk            (0x3UL << AFIO_EXTICR2_EXTI4_PD_Pos) /*!< 0x00000003 */
#define AFIO_EXTICR2_EXTI4_PD                AFIO_EXTICR2_EXTI4_PD_Msk         /*!< PD[4] pin */
#define AFIO_EXTICR2_EXTI4_PE_Pos            (2U)                              
#define AFIO_EXTICR2_EXTI4_PE_Msk            (0x1UL << AFIO_EXTICR2_EXTI4_PE_Pos) /*!< 0x00000004 */
#define AFIO_EXTICR2_EXTI4_PE                AFIO_EXTICR2_EXTI4_PE_Msk         /*!< PE[4] pin */
#define AFIO_EXTICR2_EXTI4_PF_Pos            (0U)                              
#define AFIO_EXTICR2_EXTI4_PF_Msk            (0x5UL << AFIO_EXTICR2_EXTI4_PF_Pos) /*!< 0x00000005 */
#define AFIO_EXTICR2_EXTI4_PF                AFIO_EXTICR2_EXTI4_PF_Msk         /*!< PF[4] pin */
#define AFIO_EXTICR2_EXTI4_PG_Pos            (1U)                              
#define AFIO_EXTICR2_EXTI4_PG_Msk            (0x3UL << AFIO_EXTICR2_EXTI4_PG_Pos) /*!< 0x00000006 */
#define AFIO_EXTICR2_EXTI4_PG                AFIO_EXTICR2_EXTI4_PG_Msk         /*!< PG[4] pin */

/* EXTI5 configuration */
#define AFIO_EXTICR2_EXTI5_PA                0x00000000U                          /*!< PA[5] pin */
#define AFIO_EXTICR2_EXTI5_PB_Pos            (4U)                              
#define AFIO_EXTICR2_EXTI5_PB_Msk            (0x1UL << AFIO_EXTICR2_EXTI5_PB_Pos) /*!< 0x00000010 */
#define AFIO_EXTICR2_EXTI5_PB                AFIO_EXTICR2_EXTI5_PB_Msk         /*!< PB[5] pin */
#define AFIO_EXTICR2_EXTI5_PC_Pos            (5U)                              
#define AFIO_EXTICR2_EXTI5_PC_Msk            (0x1UL << AFIO_EXTICR2_EXTI5_PC_Pos) /*!< 0x00000020 */
#define AFIO_EXTICR2_EXTI5_PC                AFIO_EXTICR2_EXTI5_PC_Msk         /*!< PC[5] pin */
#define AFIO_EXTICR2_EXTI5_PD_Pos            (4U)                              
#define AFIO_EXTICR2_EXTI5_PD_Msk            (0x3UL << AFIO_EXTICR2_EXTI5_PD_Pos) /*!< 0x00000030 */
#define AFIO_EXTICR2_EXTI5_PD                AFIO_EXTICR2_EXTI5_PD_Msk         /*!< PD[5] pin */
#define AFIO_EXTICR2_EXTI5_PE_Pos            (6U)                              
#define AFIO_EXTICR2_EXTI5_PE_Msk            (0x1UL << AFIO_EXTICR2_EXTI5_PE_Pos) /*!< 0x00000040 */
#define AFIO_EXTICR2_EXTI5_PE                AFIO_EXTICR2_EXTI5_PE_Msk         /*!< PE[5] pin */
#define AFIO_EXTICR2_EXTI5_PF_Pos            (4U)                              
#define AFIO_EXTICR2_EXTI5_PF_Msk            (0x5UL << AFIO_EXTICR2_EXTI5_PF_Pos) /*!< 0x00000050 */
#define AFIO_EXTICR2_EXTI5_PF                AFIO_EXTICR2_EXTI5_PF_Msk         /*!< PF[5] pin */
#define AFIO_EXTICR2_EXTI5_PG_Pos            (5U)                              
#define AFIO_EXTICR2_EXTI5_PG_Msk            (0x3UL << AFIO_EXTICR2_EXTI5_PG_Pos) /*!< 0x00000060 */
#define AFIO_EXTICR2_EXTI5_PG                AFIO_EXTICR2_EXTI5_PG_Msk         /*!< PG[5] pin */

/*!< EXTI6 configuration */  
#define AFIO_EXTICR2_EXTI6_PA                0x00000000U                          /*!< PA[6] pin */
#define AFIO_EXTICR2_EXTI6_PB_Pos            (8U)                              
#define AFIO_EXTICR2_EXTI6_PB_Msk            (0x1UL << AFIO_EXTICR2_EXTI6_PB_Pos) /*!< 0x00000100 */
#define AFIO_EXTICR2_EXTI6_PB                AFIO_EXTICR2_EXTI6_PB_Msk         /*!< PB[6] pin */
#define AFIO_EXTICR2_EXTI6_PC_Pos            (9U)                              
#define AFIO_EXTICR2_EXTI6_PC_Msk            (0x1UL << AFIO_EXTICR2_EXTI6_PC_Pos) /*!< 0x00000200 */
#define AFIO_EXTICR2_EXTI6_PC                AFIO_EXTICR2_EXTI6_PC_Msk         /*!< PC[6] pin */
#define AFIO_EXTICR2_EXTI6_PD_Pos            (8U)                              
#define AFIO_EXTICR2_EXTI6_PD_Msk            (0x3UL << AFIO_EXTICR2_EXTI6_PD_Pos) /*!< 0x00000300 */
#define AFIO_EXTICR2_EXTI6_PD                AFIO_EXTICR2_EXTI6_PD_Msk         /*!< PD[6] pin */
#define AFIO_EXTICR2_EXTI6_PE_Pos            (10U)                             
#define AFIO_EXTICR2_EXTI6_PE_Msk            (0x1UL << AFIO_EXTICR2_EXTI6_PE_Pos) /*!< 0x00000400 */
#define AFIO_EXTICR2_EXTI6_PE                AFIO_EXTICR2_EXTI6_PE_Msk         /*!< PE[6] pin */
#define AFIO_EXTICR2_EXTI6_PF_Pos            (8U)                              
#define AFIO_EXTICR2_EXTI6_PF_Msk            (0x5UL << AFIO_EXTICR2_EXTI6_PF_Pos) /*!< 0x00000500 */
#define AFIO_EXTICR2_EXTI6_PF                AFIO_EXTICR2_EXTI6_PF_Msk         /*!< PF[6] pin */
#define AFIO_EXTICR2_EXTI6_PG_Pos            (9U)                              
#define AFIO_EXTICR2_EXTI6_PG_Msk            (0x3UL << AFIO_EXTICR2_EXTI6_PG_Pos) /*!< 0x00000600 */
#define AFIO_EXTICR2_EXTI6_PG                AFIO_EXTICR2_EXTI6_PG_Msk         /*!< PG[6] pin */

/*!< EXTI7 configuration */
#define AFIO_EXTICR2_EXTI7_PA                0x00000000U                          /*!< PA[7] pin */
#define AFIO_EXTICR2_EXTI7_PB_Pos            (12U)                             
#define AFIO_EXTICR2_EXTI7_PB_Msk            (0x1UL << AFIO_EXTICR2_EXTI7_PB_Pos) /*!< 0x00001000 */
#define AFIO_EXTICR2_EXTI7_PB                AFIO_EXTICR2_EXTI7_PB_Msk         /*!< PB[7] pin */
#define AFIO_EXTICR2_EXTI7_PC_Pos            (13U)                             
#define AFIO_EXTICR2_EXTI7_PC_Msk            (0x1UL << AFIO_EXTICR2_EXTI7_PC_Pos) /*!< 0x00002000 */
#define AFIO_EXTICR2_EXTI7_PC                AFIO_EXTICR2_EXTI7_PC_Msk         /*!< PC[7] pin */
#define AFIO_EXTICR2_EXTI7_PD_Pos            (12U)                             
#define AFIO_EXTICR2_EXTI7_PD_Msk            (0x3UL << AFIO_EXTICR2_EXTI7_PD_Pos) /*!< 0x00003000 */
#define AFIO_EXTICR2_EXTI7_PD                AFIO_EXTICR2_EXTI7_PD_Msk         /*!< PD[7] pin */
#define AFIO_EXTICR2_EXTI7_PE_Pos            (14U)                             
#define AFIO_EXTICR2_EXTI7_PE_Msk            (0x1UL << AFIO_EXTICR2_EXTI7_PE_Pos) /*!< 0x00004000 */
#define AFIO_EXTICR2_EXTI7_PE                AFIO_EXTICR2_EXTI7_PE_Msk         /*!< PE[7] pin */
#define AFIO_EXTICR2_EXTI7_PF_Pos            (12U)                             
#define AFIO_EXTICR2_EXTI7_PF_Msk            (0x5UL << AFIO_EXTICR2_EXTI7_PF_Pos) /*!< 0x00005000 */
#define AFIO_EXTICR2_EXTI7_PF                AFIO_EXTICR2_EXTI7_PF_Msk         /*!< PF[7] pin */
#define AFIO_EXTICR2_EXTI7_PG_Pos            (13U)                             
#define AFIO_EXTICR2_EXTI7_PG_Msk            (0x3UL << AFIO_EXTICR2_EXTI7_PG_Pos) /*!< 0x00006000 */
#define AFIO_EXTICR2_EXTI7_PG                AFIO_EXTICR2_EXTI7_PG_Msk         /*!< PG[7] pin */

/*****************  Bit definition for AFIO_EXTICR3 register  *****************/
#define AFIO_EXTICR3_EXTI8_Pos               (0U)                              
#define AFIO_EXTICR3_EXTI8_Msk               (0xFUL << AFIO_EXTICR3_EXTI8_Pos)  /*!< 0x0000000F */
#define AFIO_EXTICR3_EXTI8                   AFIO_EXTICR3_EXTI8_Msk            /*!< EXTI 8 configuration */
#define AFIO_EXTICR3_EXTI9_Pos               (4U)                              
#define AFIO_EXTICR3_EXTI9_Msk               (0xFUL << AFIO_EXTICR3_EXTI9_Pos)  /*!< 0x000000F0 */
#define AFIO_EXTICR3_EXTI9                   AFIO_EXTICR3_EXTI9_Msk            /*!< EXTI 9 configuration */
#define AFIO_EXTICR3_EXTI10_Pos              (8U)                              
#define AFIO_EXTICR3_EXTI10_Msk              (0xFUL << AFIO_EXTICR3_EXTI10_Pos) /*!< 0x00000F00 */
#define AFIO_EXTICR3_EXTI10                  AFIO_EXTICR3_EXTI10_Msk           /*!< EXTI 10 configuration */
#define AFIO_EXTICR3_EXTI11_Pos              (12U)                             
#define AFIO_EXTICR3_EXTI11_Msk              (0xFUL << AFIO_EXTICR3_EXTI11_Pos) /*!< 0x0000F000 */
#define AFIO_EXTICR3_EXTI11                  AFIO_EXTICR3_EXTI11_Msk           /*!< EXTI 11 configuration */

/*!< EXTI8 configuration */
#define AFIO_EXTICR3_EXTI8_PA                0x00000000U                          /*!< PA[8] pin */
#define AFIO_EXTICR3_EXTI8_PB_Pos            (0U)                              
#define AFIO_EXTICR3_EXTI8_PB_Msk            (0x1UL << AFIO_EXTICR3_EXTI8_PB_Pos) /*!< 0x00000001 */
#define AFIO_EXTICR3_EXTI8_PB                AFIO_EXTICR3_EXTI8_PB_Msk         /*!< PB[8] pin */
#define AFIO_EXTICR3_EXTI8_PC_Pos            (1U)                              
#define AFIO_EXTICR3_EXTI8_PC_Msk            (0x1UL << AFIO_EXTICR3_EXTI8_PC_Pos) /*!< 0x00000002 */
#define AFIO_EXTICR3_EXTI8_PC                AFIO_EXTICR3_EXTI8_PC_Msk         /*!< PC[8] pin */
#define AFIO_EXTICR3_EXTI8_PD_Pos            (0U)                              
#define AFIO_EXTICR3_EXTI8_PD_Msk            (0x3UL << AFIO_EXTICR3_EXTI8_PD_Pos) /*!< 0x00000003 */
#define AFIO_EXTICR3_EXTI8_PD                AFIO_EXTICR3_EXTI8_PD_Msk         /*!< PD[8] pin */
#define AFIO_EXTICR3_EXTI8_PE_Pos            (2U)                              
#define AFIO_EXTICR3_EXTI8_PE_Msk            (0x1UL << AFIO_EXTICR3_EXTI8_PE_Pos) /*!< 0x00000004 */
#define AFIO_EXTICR3_EXTI8_PE                AFIO_EXTICR3_EXTI8_PE_Msk         /*!< PE[8] pin */
#define AFIO_EXTICR3_EXTI8_PF_Pos            (0U)                              
#define AFIO_EXTICR3_EXTI8_PF_Msk            (0x5UL << AFIO_EXTICR3_EXTI8_PF_Pos) /*!< 0x00000005 */
#define AFIO_EXTICR3_EXTI8_PF                AFIO_EXTICR3_EXTI8_PF_Msk         /*!< PF[8] pin */
#define AFIO_EXTICR3_EXTI8_PG_Pos            (1U)                              
#define AFIO_EXTICR3_EXTI8_PG_Msk            (0x3UL << AFIO_EXTICR3_EXTI8_PG_Pos) /*!< 0x00000006 */
#define AFIO_EXTICR3_EXTI8_PG                AFIO_EXTICR3_EXTI8_PG_Msk         /*!< PG[8] pin */

/*!< EXTI9 configuration */
#define AFIO_EXTICR3_EXTI9_PA                0x00000000U                          /*!< PA[9] pin */
#define AFIO_EXTICR3_EXTI9_PB_Pos            (4U)                              
#define AFIO_EXTICR3_EXTI9_PB_Msk            (0x1UL << AFIO_EXTICR3_EXTI9_PB_Pos) /*!< 0x00000010 */
#define AFIO_EXTICR3_EXTI9_PB                AFIO_EXTICR3_EXTI9_PB_Msk         /*!< PB[9] pin */
#define AFIO_EXTICR3_EXTI9_PC_Pos            (5U)                              
#define AFIO_EXTICR3_EXTI9_PC_Msk            (0x1UL << AFIO_EXTICR3_EXTI9_PC_Pos) /*!< 0x00000020 */
#define AFIO_EXTICR3_EXTI9_PC                AFIO_EXTICR3_EXTI9_PC_Msk         /*!< PC[9] pin */
#define AFIO_EXTICR3_EXTI9_PD_Pos            (4U)                              
#define AFIO_EXTICR3_EXTI9_PD_Msk            (0x3UL << AFIO_EXTICR3_EXTI9_PD_Pos) /*!< 0x00000030 */
#define AFIO_EXTICR3_EXTI9_PD                AFIO_EXTICR3_EXTI9_PD_Msk         /*!< PD[9] pin */
#define AFIO_EXTICR3_EXTI9_PE_Pos            (6U)                              
#define AFIO_EXTICR3_EXTI9_PE_Msk            (0x1UL << AFIO_EXTICR3_EXTI9_PE_Pos) /*!< 0x00000040 */
#define AFIO_EXTICR3_EXTI9_PE                AFIO_EXTICR3_EXTI9_PE_Msk         /*!< PE[9] pin */
#define AFIO_EXTICR3_EXTI9_PF_Pos            (4U)                              
#define AFIO_EXTICR3_EXTI9_PF_Msk            (0x5UL << AFIO_EXTICR3_EXTI9_PF_Pos) /*!< 0x00000050 */
#define AFIO_EXTICR3_EXTI9_PF                AFIO_EXTICR3_EXTI9_PF_Msk         /*!< PF[9] pin */
#define AFIO_EXTICR3_EXTI9_PG_Pos            (5U)                              
#define AFIO_EXTICR3_EXTI9_PG_Msk            (0x3UL << AFIO_EXTICR3_EXTI9_PG_Pos) /*!< 0x00000060 */
#define AFIO_EXTICR3_EXTI9_PG                AFIO_EXTICR3_EXTI9_PG_Msk         /*!< PG[9] pin */

/*!< EXTI10 configuration */  
#define AFIO_EXTICR3_EXTI10_PA               0x00000000U                          /*!< PA[10] pin */
#define AFIO_EXTICR3_EXTI10_PB_Pos           (8U)                              
#define AFIO_EXTICR3_EXTI10_PB_Msk           (0x1UL << AFIO_EXTICR3_EXTI10_PB_Pos) /*!< 0x00000100 */
#define AFIO_EXTICR3_EXTI10_PB               AFIO_EXTICR3_EXTI10_PB_Msk        /*!< PB[10] pin */
#define AFIO_EXTICR3_EXTI10_PC_Pos           (9U)                              
#define AFIO_EXTICR3_EXTI10_PC_Msk           (0x1UL << AFIO_EXTICR3_EXTI10_PC_Pos) /*!< 0x00000200 */
#define AFIO_EXTICR3_EXTI10_PC               AFIO_EXTICR3_EXTI10_PC_Msk        /*!< PC[10] pin */
#define AFIO_EXTICR3_EXTI10_PD_Pos           (8U)                              
#define AFIO_EXTICR3_EXTI10_PD_Msk           (0x3UL << AFIO_EXTICR3_EXTI10_PD_Pos) /*!< 0x00000300 */
#define AFIO_EXTICR3_EXTI10_PD               AFIO_EXTICR3_EXTI10_PD_Msk        /*!< PD[10] pin */
#define AFIO_EXTICR3_EXTI10_PE_Pos           (10U)                             
#define AFIO_EXTICR3_EXTI10_PE_Msk           (0x1UL << AFIO_EXTICR3_EXTI10_PE_Pos) /*!< 0x00000400 */
#define AFIO_EXTICR3_EXTI10_PE               AFIO_EXTICR3_EXTI10_PE_Msk        /*!< PE[10] pin */
#define AFIO_EXTICR3_EXTI10_PF_Pos           (8U)                              
#define AFIO_EXTICR3_EXTI10_PF_Msk           (0x5UL << AFIO_EXTICR3_EXTI10_PF_Pos) /*!< 0x00000500 */
#define AFIO_EXTICR3_EXTI10_PF               AFIO_EXTICR3_EXTI10_PF_Msk        /*!< PF[10] pin */
#define AFIO_EXTICR3_EXTI10_PG_Pos           (9U)                              
#define AFIO_EXTICR3_EXTI10_PG_Msk           (0x3UL << AFIO_EXTICR3_EXTI10_PG_Pos) /*!< 0x00000600 */
#define AFIO_EXTICR3_EXTI10_PG               AFIO_EXTICR3_EXTI10_PG_Msk        /*!< PG[10] pin */

/*!< EXTI11 configuration */
#define AFIO_EXTICR3_EXTI11_PA               0x00000000U                          /*!< PA[11] pin */
#define AFIO_EXTICR3_EXTI11_PB_Pos           (12U)                             
#define AFIO_EXTICR3_EXTI11_PB_Msk           (0x1UL << AFIO_EXTICR3_EXTI11_PB_Pos) /*!< 0x00001000 */
#define AFIO_EXTICR3_EXTI11_PB               AFIO_EXTICR3_EXTI11_PB_Msk        /*!< PB[11] pin */
#define AFIO_EXTICR3_EXTI11_PC_Pos           (13U)                             
#define AFIO_EXTICR3_EXTI11_PC_Msk           (0x1UL << AFIO_EXTICR3_EXTI11_PC_Pos) /*!< 0x00002000 */
#define AFIO_EXTICR3_EXTI11_PC               AFIO_EXTICR3_EXTI11_PC_Msk        /*!< PC[11] pin */
#define AFIO_EXTICR3_EXTI11_PD_Pos           (12U)                             
#define AFIO_EXTICR3_EXTI11_PD_Msk           (0x3UL << AFIO_EXTICR3_EXTI11_PD_Pos) /*!< 0x00003000 */
#define AFIO_EXTICR3_EXTI11_PD               AFIO_EXTICR3_EXTI11_PD_Msk        /*!< PD[11] pin */
#define AFIO_EXTICR3_EXTI11_PE_Pos           (14U)                             
#define AFIO_EXTICR3_EXTI11_PE_Msk           (0x1UL << AFIO_EXTICR3_EXTI11_PE_Pos) /*!< 0x00004000 */
#define AFIO_EXTICR3_EXTI11_PE               AFIO_EXTICR3_EXTI11_PE_Msk        /*!< PE[11] pin */
#define AFIO_EXTICR3_EXTI11_PF_Pos           (12U)                             
#define AFIO_EXTICR3_EXTI11_PF_Msk           (0x5UL << AFIO_EXTICR3_EXTI11_PF_Pos) /*!< 0x00005000 */
#define AFIO_EXTICR3_EXTI11_PF               AFIO_EXTICR3_EXTI11_PF_Msk        /*!< PF[11] pin */
#define AFIO_EXTICR3_EXTI11_PG_Pos           (13U)                             
#define AFIO_EXTICR3_EXTI11_PG_Msk           (0x3UL << AFIO_EXTICR3_EXTI11_PG_Pos) /*!< 0x00006000 */
#define AFIO_EXTICR3_EXTI11_PG               AFIO_EXTICR3_EXTI11_PG_Msk        /*!< PG[11] pin */

/*****************  Bit definition for AFIO_EXTICR4 register  *****************/
#define AFIO_EXTICR4_EXTI12_Pos              (0U)                              
#define AFIO_EXTICR4_EXTI12_Msk              (0xFUL << AFIO_EXTICR4_EXTI12_Pos) /*!< 0x0000000F */
#define AFIO_EXTICR4_EXTI12                  AFIO_EXTICR4_EXTI12_Msk           /*!< EXTI 12 configuration */
#define AFIO_EXTICR4_EXTI13_Pos              (4U)                              
#define AFIO_EXTICR4_EXTI13_Msk              (0xFUL << AFIO_EXTICR4_EXTI13_Pos) /*!< 0x000000F0 */
#define AFIO_EXTICR4_EXTI13                  AFIO_EXTICR4_EXTI13_Msk           /*!< EXTI 13 configuration */
#define AFIO_EXTICR4_EXTI14_Pos              (8U)                              
#define AFIO_EXTICR4_EXTI14_Msk              (0xFUL << AFIO_EXTICR4_EXTI14_Pos) /*!< 0x00000F00 */
#define AFIO_EXTICR4_EXTI14                  AFIO_EXTICR4_EXTI14_Msk           /*!< EXTI 14 configuration */
#define AFIO_EXTICR4_EXTI15_Pos              (12U)                             
#define AFIO_EXTICR4_EXTI15_Msk              (0xFUL << AFIO_EXTICR4_EXTI15_Pos) /*!< 0x0000F000 */
#define AFIO_EXTICR4_EXTI15                  AFIO_EXTICR4_EXTI15_Msk           /*!< EXTI 15 configuration */

/* EXTI12 configuration */
#define AFIO_EXTICR4_EXTI12_PA               0x00000000U                          /*!< PA[12] pin */
#define AFIO_EXTICR4_EXTI12_PB_Pos           (0U)                              
#define AFIO_EXTICR4_EXTI12_PB_Msk           (0x1UL << AFIO_EXTICR4_EXTI12_PB_Pos) /*!< 0x00000001 */
#define AFIO_EXTICR4_EXTI12_PB               AFIO_EXTICR4_EXTI12_PB_Msk        /*!< PB[12] pin */
#define AFIO_EXTICR4_EXTI12_PC_Pos           (1U)                              
#define AFIO_EXTICR4_EXTI12_PC_Msk           (0x1UL << AFIO_EXTICR4_EXTI12_PC_Pos) /*!< 0x00000002 */
#define AFIO_EXTICR4_EXTI12_PC               AFIO_EXTICR4_EXTI12_PC_Msk        /*!< PC[12] pin */
#define AFIO_EXTICR4_EXTI12_PD_Pos           (0U)                              
#define AFIO_EXTICR4_EXTI12_PD_Msk           (0x3UL << AFIO_EXTICR4_EXTI12_PD_Pos) /*!< 0x00000003 */
#define AFIO_EXTICR4_EXTI12_PD               AFIO_EXTICR4_EXTI12_PD_Msk        /*!< PD[12] pin */
#define AFIO_EXTICR4_EXTI12_PE_Pos           (2U)                              
#define AFIO_EXTICR4_EXTI12_PE_Msk           (0x1UL << AFIO_EXTICR4_EXTI12_PE_Pos) /*!< 0x00000004 */
#define AFIO_EXTICR4_EXTI12_PE               AFIO_EXTICR4_EXTI12_PE_Msk        /*!< PE[12] pin */
#define AFIO_EXTICR4_EXTI12_PF_Pos           (0U)                              
#define AFIO_EXTICR4_EXTI12_PF_Msk           (0x5UL << AFIO_EXTICR4_EXTI12_PF_Pos) /*!< 0x00000005 */
#define AFIO_EXTICR4_EXTI12_PF               AFIO_EXTICR4_EXTI12_PF_Msk        /*!< PF[12] pin */
#define AFIO_EXTICR4_EXTI12_PG_Pos           (1U)                              
#define AFIO_EXTICR4_EXTI12_PG_Msk           (0x3UL << AFIO_EXTICR4_EXTI12_PG_Pos) /*!< 0x00000006 */
#define AFIO_EXTICR4_EXTI12_PG               AFIO_EXTICR4_EXTI12_PG_Msk        /*!< PG[12] pin */

/* EXTI13 configuration */
#define AFIO_EXTICR4_EXTI13_PA               0x00000000U                          /*!< PA[13] pin */
#define AFIO_EXTICR4_EXTI13_PB_Pos           (4U)                              
#define AFIO_EXTICR4_EXTI13_PB_Msk           (0x1UL << AFIO_EXTICR4_EXTI13_PB_Pos) /*!< 0x00000010 */
#define AFIO_EXTICR4_EXTI13_PB               AFIO_EXTICR4_EXTI13_PB_Msk        /*!< PB[13] pin */
#define AFIO_EXTICR4_EXTI13_PC_Pos           (5U)                              
#define AFIO_EXTICR4_EXTI13_PC_Msk           (0x1UL << AFIO_EXTICR4_EXTI13_PC_Pos) /*!< 0x00000020 */
#define AFIO_EXTICR4_EXTI13_PC               AFIO_EXTICR4_EXTI13_PC_Msk        /*!< PC[13] pin */
#define AFIO_EXTICR4_EXTI13_PD_Pos           (4U)                              
#define AFIO_EXTICR4_EXTI13_PD_Msk           (0x3UL << AFIO_EXTICR4_EXTI13_PD_Pos) /*!< 0x00000030 */
#define AFIO_EXTICR4_EXTI13_PD               AFIO_EXTICR4_EXTI13_PD_Msk        /*!< PD[13] pin */
#define AFIO_EXTICR4_EXTI13_PE_Pos           (6U)                              
#define AFIO_EXTICR4_EXTI13_PE_Msk           (0x1UL << AFIO_EXTICR4_EXTI13_PE_Pos) /*!< 0x00000040 */
#define AFIO_EXTICR4_EXTI13_PE               AFIO_EXTICR4_EXTI13_PE_Msk        /*!< PE[13] pin */
#define AFIO_EXTICR4_EXTI13_PF_Pos           (4U)                              
#define AFIO_EXTICR4_EXTI13_PF_Msk           (0x5UL << AFIO_EXTICR4_EXTI13_PF_Pos) /*!< 0x00000050 */
#define AFIO_EXTICR4_EXTI13_PF               AFIO_EXTICR4_EXTI13_PF_Msk        /*!< PF[13] pin */
#define AFIO_EXTICR4_EXTI13_PG_Pos           (5U)                              
#define AFIO_EXTICR4_EXTI13_PG_Msk           (0x3UL << AFIO_EXTICR4_EXTI13_PG_Pos) /*!< 0x00000060 */
#define AFIO_EXTICR4_EXTI13_PG               AFIO_EXTICR4_EXTI13_PG_Msk        /*!< PG[13] pin */

/*!< EXTI14 configuration */  
#define AFIO_EXTICR4_EXTI14_PA               0x00000000U                          /*!< PA[14] pin */
#define AFIO_EXTICR4_EXTI14_PB_Pos           (8U)                              
#define AFIO_EXTICR4_EXTI14_PB_Msk           (0x1UL << AFIO_EXTICR4_EXTI14_PB_Pos) /*!< 0x00000100 */
#define AFIO_EXTICR4_EXTI14_PB               AFIO_EXTICR4_EXTI14_PB_Msk        /*!< PB[14] pin */
#define AFIO_EXTICR4_EXTI14_PC_Pos           (9U)                              
#define AFIO_EXTICR4_EXTI14_PC_Msk           (0x1UL << AFIO_EXTICR4_EXTI14_PC_Pos) /*!< 0x00000200 */
#define AFIO_EXTICR4_EXTI14_PC               AFIO_EXTICR4_EXTI14_PC_Msk        /*!< PC[14] pin */
#define AFIO_EXTICR4_EXTI14_PD_Pos           (8U)                              
#define AFIO_EXTICR4_EXTI14_PD_Msk           (0x3UL << AFIO_EXTICR4_EXTI14_PD_Pos) /*!< 0x00000300 */
#define AFIO_EXTICR4_EXTI14_PD               AFIO_EXTICR4_EXTI14_PD_Msk        /*!< PD[14] pin */
#define AFIO_EXTICR4_EXTI14_PE_Pos           (10U)                             
#define AFIO_EXTICR4_EXTI14_PE_Msk           (0x1UL << AFIO_EXTICR4_EXTI14_PE_Pos) /*!< 0x00000400 */
#define AFIO_EXTICR4_EXTI14_PE               AFIO_EXTICR4_EXTI14_PE_Msk        /*!< PE[14] pin */
#define AFIO_EXTICR4_EXTI14_PF_Pos           (8U)                              
#define AFIO_EXTICR4_EXTI14_PF_Msk           (0x5UL << AFIO_EXTICR4_EXTI14_PF_Pos) /*!< 0x00000500 */
#define AFIO_EXTICR4_EXTI14_PF               AFIO_EXTICR4_EXTI14_PF_Msk        /*!< PF[14] pin */
#define AFIO_EXTICR4_EXTI14_PG_Pos           (9U)                              
#define AFIO_EXTICR4_EXTI14_PG_Msk           (0x3UL << AFIO_EXTICR4_EXTI14_PG_Pos) /*!< 0x00000600 */
#define AFIO_EXTICR4_EXTI14_PG               AFIO_EXTICR4_EXTI14_PG_Msk        /*!< PG[14] pin */

/*!< EXTI15 configuration */
#define AFIO_EXTICR4_EXTI15_PA               0x00000000U                          /*!< PA[15] pin */
#define AFIO_EXTICR4_EXTI15_PB_Pos           (12U)                             
#define AFIO_EXTICR4_EXTI15_PB_Msk           (0x1UL << AFIO_EXTICR4_EXTI15_PB_Pos) /*!< 0x00001000 */
#define AFIO_EXTICR4_EXTI15_PB               AFIO_EXTICR4_EXTI15_PB_Msk        /*!< PB[15] pin */
#define AFIO_EXTICR4_EXTI15_PC_Pos           (13U)                             
#define AFIO_EXTICR4_EXTI15_PC_Msk           (0x1UL << AFIO_EXTICR4_EXTI15_PC_Pos) /*!< 0x00002000 */
#define AFIO_EXTICR4_EXTI15_PC               AFIO_EXTICR4_EXTI15_PC_Msk        /*!< PC[15] pin */
#define AFIO_EXTICR4_EXTI15_PD_Pos           (12U)                             
#define AFIO_EXTICR4_EXTI15_PD_Msk           (0x3UL << AFIO_EXTICR4_EXTI15_PD_Pos) /*!< 0x00003000 */
#define AFIO_EXTICR4_EXTI15_PD               AFIO_EXTICR4_EXTI15_PD_Msk        /*!< PD[15] pin */
#define AFIO_EXTICR4_EXTI15_PE_Pos           (14U)                             
#define AFIO_EXTICR4_EXTI15_PE_Msk           (0x1UL << AFIO_EXTICR4_EXTI15_PE_Pos) /*!< 0x00004000 */
#define AFIO_EXTICR4_EXTI15_PE               AFIO_EXTICR4_EXTI15_PE_Msk        /*!< PE[15] pin */
#define AFIO_EXTICR4_EXTI15_PF_Pos           (12U)                             
#define AFIO_EXTICR4_EXTI15_PF_Msk           (0x5UL << AFIO_EXTICR4_EXTI15_PF_Pos) /*!< 0x00005000 */
#define AFIO_EXTICR4_EXTI15_PF               AFIO_EXTICR4_EXTI15_PF_Msk        /*!< PF[15] pin */
#define AFIO_EXTICR4_EXTI15_PG_Pos           (13U)                             
#define AFIO_EXTICR4_EXTI15_PG_Msk           (0x3UL << AFIO_EXTICR4_EXTI15_PG_Pos) /*!< 0x00006000 */
#define AFIO_EXTICR4_EXTI15_PG               AFIO_EXTICR4_EXTI15_PG_Msk        /*!< PG[15] pin */

/******************  Bit definition for AFIO_MAPR2 register  ******************/



/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller                     */
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
#define  EXTI_IMR_IM   0x0007FFFFU        /*!< Interrupt Mask All */
 
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

/******************************************************************************/
/*                                                                            */
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F1 family)
 */
#define ADC_MULTIMODE_SUPPORT                          /*!< ADC feature available only on specific devices: multimode available on devices with several ADC instances */

/********************  Bit definition for ADC_SR register  ********************/
#define ADC_SR_AWD_Pos                      (0U)                               
#define ADC_SR_AWD_Msk                      (0x1UL << ADC_SR_AWD_Pos)           /*!< 0x00000001 */
#define ADC_SR_AWD                          ADC_SR_AWD_Msk                     /*!< ADC analog watchdog 1 flag */
#define ADC_SR_EOS_Pos                      (1U)                               
#define ADC_SR_EOS_Msk                      (0x1UL << ADC_SR_EOS_Pos)           /*!< 0x00000002 */
#define ADC_SR_EOS                          ADC_SR_EOS_Msk                     /*!< ADC group regular end of sequence conversions flag */
#define ADC_SR_JEOS_Pos                     (2U)                               
#define ADC_SR_JEOS_Msk                     (0x1UL << ADC_SR_JEOS_Pos)          /*!< 0x00000004 */
#define ADC_SR_JEOS                         ADC_SR_JEOS_Msk                    /*!< ADC group injected end of sequence conversions flag */
#define ADC_SR_JSTRT_Pos                    (3U)                               
#define ADC_SR_JSTRT_Msk                    (0x1UL << ADC_SR_JSTRT_Pos)         /*!< 0x00000008 */
#define ADC_SR_JSTRT                        ADC_SR_JSTRT_Msk                   /*!< ADC group injected conversion start flag */
#define ADC_SR_STRT_Pos                     (4U)                               
#define ADC_SR_STRT_Msk                     (0x1UL << ADC_SR_STRT_Pos)          /*!< 0x00000010 */
#define ADC_SR_STRT                         ADC_SR_STRT_Msk                    /*!< ADC group regular conversion start flag */

/* Legacy defines */
#define  ADC_SR_EOC                          (ADC_SR_EOS)
#define  ADC_SR_JEOC                         (ADC_SR_JEOS)

/*******************  Bit definition for ADC_CR1 register  ********************/
#define ADC_CR1_AWDCH_Pos                   (0U)                               
#define ADC_CR1_AWDCH_Msk                   (0x1FUL << ADC_CR1_AWDCH_Pos)       /*!< 0x0000001F */
#define ADC_CR1_AWDCH                       ADC_CR1_AWDCH_Msk                  /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CR1_AWDCH_0                     (0x01UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000001 */
#define ADC_CR1_AWDCH_1                     (0x02UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000002 */
#define ADC_CR1_AWDCH_2                     (0x04UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000004 */
#define ADC_CR1_AWDCH_3                     (0x08UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000008 */
#define ADC_CR1_AWDCH_4                     (0x10UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000010 */

#define ADC_CR1_EOSIE_Pos                   (5U)                               
#define ADC_CR1_EOSIE_Msk                   (0x1UL << ADC_CR1_EOSIE_Pos)        /*!< 0x00000020 */
#define ADC_CR1_EOSIE                       ADC_CR1_EOSIE_Msk                  /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_CR1_AWDIE_Pos                   (6U)                               
#define ADC_CR1_AWDIE_Msk                   (0x1UL << ADC_CR1_AWDIE_Pos)        /*!< 0x00000040 */
#define ADC_CR1_AWDIE                       ADC_CR1_AWDIE_Msk                  /*!< ADC analog watchdog 1 interrupt */
#define ADC_CR1_JEOSIE_Pos                  (7U)                               
#define ADC_CR1_JEOSIE_Msk                  (0x1UL << ADC_CR1_JEOSIE_Pos)       /*!< 0x00000080 */
#define ADC_CR1_JEOSIE                      ADC_CR1_JEOSIE_Msk                 /*!< ADC group injected end of sequence conversions interrupt */
#define ADC_CR1_SCAN_Pos                    (8U)                               
#define ADC_CR1_SCAN_Msk                    (0x1UL << ADC_CR1_SCAN_Pos)         /*!< 0x00000100 */
#define ADC_CR1_SCAN                        ADC_CR1_SCAN_Msk                   /*!< ADC scan mode */
#define ADC_CR1_AWDSGL_Pos                  (9U)                               
#define ADC_CR1_AWDSGL_Msk                  (0x1UL << ADC_CR1_AWDSGL_Pos)       /*!< 0x00000200 */
#define ADC_CR1_AWDSGL                      ADC_CR1_AWDSGL_Msk                 /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CR1_JAUTO_Pos                   (10U)                              
#define ADC_CR1_JAUTO_Msk                   (0x1UL << ADC_CR1_JAUTO_Pos)        /*!< 0x00000400 */
#define ADC_CR1_JAUTO                       ADC_CR1_JAUTO_Msk                  /*!< ADC group injected automatic trigger mode */
#define ADC_CR1_DISCEN_Pos                  (11U)                              
#define ADC_CR1_DISCEN_Msk                  (0x1UL << ADC_CR1_DISCEN_Pos)       /*!< 0x00000800 */
#define ADC_CR1_DISCEN                      ADC_CR1_DISCEN_Msk                 /*!< ADC group regular sequencer discontinuous mode */
#define ADC_CR1_JDISCEN_Pos                 (12U)                              
#define ADC_CR1_JDISCEN_Msk                 (0x1UL << ADC_CR1_JDISCEN_Pos)      /*!< 0x00001000 */
#define ADC_CR1_JDISCEN                     ADC_CR1_JDISCEN_Msk                /*!< ADC group injected sequencer discontinuous mode */

#define ADC_CR1_DISCNUM_Pos                 (13U)                              
#define ADC_CR1_DISCNUM_Msk                 (0x7UL << ADC_CR1_DISCNUM_Pos)      /*!< 0x0000E000 */
#define ADC_CR1_DISCNUM                     ADC_CR1_DISCNUM_Msk                /*!< ADC group regular sequencer discontinuous number of ranks */
#define ADC_CR1_DISCNUM_0                   (0x1UL << ADC_CR1_DISCNUM_Pos)      /*!< 0x00002000 */
#define ADC_CR1_DISCNUM_1                   (0x2UL << ADC_CR1_DISCNUM_Pos)      /*!< 0x00004000 */
#define ADC_CR1_DISCNUM_2                   (0x4UL << ADC_CR1_DISCNUM_Pos)      /*!< 0x00008000 */

#define ADC_CR1_DUALMOD_Pos                 (16U)                              
#define ADC_CR1_DUALMOD_Msk                 (0xFUL << ADC_CR1_DUALMOD_Pos)      /*!< 0x000F0000 */
#define ADC_CR1_DUALMOD                     ADC_CR1_DUALMOD_Msk                /*!< ADC multimode mode selection */
#define ADC_CR1_DUALMOD_0                   (0x1UL << ADC_CR1_DUALMOD_Pos)      /*!< 0x00010000 */
#define ADC_CR1_DUALMOD_1                   (0x2UL << ADC_CR1_DUALMOD_Pos)      /*!< 0x00020000 */
#define ADC_CR1_DUALMOD_2                   (0x4UL << ADC_CR1_DUALMOD_Pos)      /*!< 0x00040000 */
#define ADC_CR1_DUALMOD_3                   (0x8UL << ADC_CR1_DUALMOD_Pos)      /*!< 0x00080000 */

#define ADC_CR1_JAWDEN_Pos                  (22U)                              
#define ADC_CR1_JAWDEN_Msk                  (0x1UL << ADC_CR1_JAWDEN_Pos)       /*!< 0x00400000 */
#define ADC_CR1_JAWDEN                      ADC_CR1_JAWDEN_Msk                 /*!< ADC analog watchdog 1 enable on scope ADC group injected */
#define ADC_CR1_AWDEN_Pos                   (23U)                              
#define ADC_CR1_AWDEN_Msk                   (0x1UL << ADC_CR1_AWDEN_Pos)        /*!< 0x00800000 */
#define ADC_CR1_AWDEN                       ADC_CR1_AWDEN_Msk                  /*!< ADC analog watchdog 1 enable on scope ADC group regular */

/* Legacy defines */
#define  ADC_CR1_EOCIE                       (ADC_CR1_EOSIE)
#define  ADC_CR1_JEOCIE                      (ADC_CR1_JEOSIE)

/*******************  Bit definition for ADC_CR2 register  ********************/
#define ADC_CR2_ADON_Pos                    (0U)                               
#define ADC_CR2_ADON_Msk                    (0x1UL << ADC_CR2_ADON_Pos)         /*!< 0x00000001 */
#define ADC_CR2_ADON                        ADC_CR2_ADON_Msk                   /*!< ADC enable */
#define ADC_CR2_CONT_Pos                    (1U)                               
#define ADC_CR2_CONT_Msk                    (0x1UL << ADC_CR2_CONT_Pos)         /*!< 0x00000002 */
#define ADC_CR2_CONT                        ADC_CR2_CONT_Msk                   /*!< ADC group regular continuous conversion mode */
#define ADC_CR2_CAL_Pos                     (2U)                               
#define ADC_CR2_CAL_Msk                     (0x1UL << ADC_CR2_CAL_Pos)          /*!< 0x00000004 */
#define ADC_CR2_CAL                         ADC_CR2_CAL_Msk                    /*!< ADC calibration start */
#define ADC_CR2_RSTCAL_Pos                  (3U)                               
#define ADC_CR2_RSTCAL_Msk                  (0x1UL << ADC_CR2_RSTCAL_Pos)       /*!< 0x00000008 */
#define ADC_CR2_RSTCAL                      ADC_CR2_RSTCAL_Msk                 /*!< ADC calibration reset */
#define ADC_CR2_DMA_Pos                     (8U)                               
#define ADC_CR2_DMA_Msk                     (0x1UL << ADC_CR2_DMA_Pos)          /*!< 0x00000100 */
#define ADC_CR2_DMA                         ADC_CR2_DMA_Msk                    /*!< ADC DMA transfer enable */
#define ADC_CR2_ALIGN_Pos                   (11U)                              
#define ADC_CR2_ALIGN_Msk                   (0x1UL << ADC_CR2_ALIGN_Pos)        /*!< 0x00000800 */
#define ADC_CR2_ALIGN                       ADC_CR2_ALIGN_Msk                  /*!< ADC data alignement */

#define ADC_CR2_JEXTSEL_Pos                 (12U)                              
#define ADC_CR2_JEXTSEL_Msk                 (0x7UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00007000 */
#define ADC_CR2_JEXTSEL                     ADC_CR2_JEXTSEL_Msk                /*!< ADC group injected external trigger source */
#define ADC_CR2_JEXTSEL_0                   (0x1UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00001000 */
#define ADC_CR2_JEXTSEL_1                   (0x2UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00002000 */
#define ADC_CR2_JEXTSEL_2                   (0x4UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00004000 */

#define ADC_CR2_JEXTTRIG_Pos                (15U)                              
#define ADC_CR2_JEXTTRIG_Msk                (0x1UL << ADC_CR2_JEXTTRIG_Pos)     /*!< 0x00008000 */
#define ADC_CR2_JEXTTRIG                    ADC_CR2_JEXTTRIG_Msk               /*!< ADC group injected external trigger enable */

#define ADC_CR2_EXTSEL_Pos                  (17U)                              
#define ADC_CR2_EXTSEL_Msk                  (0x7UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x000E0000 */
#define ADC_CR2_EXTSEL                      ADC_CR2_EXTSEL_Msk                 /*!< ADC group regular external trigger source */
#define ADC_CR2_EXTSEL_0                    (0x1UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00020000 */
#define ADC_CR2_EXTSEL_1                    (0x2UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00040000 */
#define ADC_CR2_EXTSEL_2                    (0x4UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00080000 */

#define ADC_CR2_EXTTRIG_Pos                 (20U)                              
#define ADC_CR2_EXTTRIG_Msk                 (0x1UL << ADC_CR2_EXTTRIG_Pos)      /*!< 0x00100000 */
#define ADC_CR2_EXTTRIG                     ADC_CR2_EXTTRIG_Msk                /*!< ADC group regular external trigger enable */
#define ADC_CR2_JSWSTART_Pos                (21U)                              
#define ADC_CR2_JSWSTART_Msk                (0x1UL << ADC_CR2_JSWSTART_Pos)     /*!< 0x00200000 */
#define ADC_CR2_JSWSTART                    ADC_CR2_JSWSTART_Msk               /*!< ADC group injected conversion start */
#define ADC_CR2_SWSTART_Pos                 (22U)                              
#define ADC_CR2_SWSTART_Msk                 (0x1UL << ADC_CR2_SWSTART_Pos)      /*!< 0x00400000 */
#define ADC_CR2_SWSTART                     ADC_CR2_SWSTART_Msk                /*!< ADC group regular conversion start */
#define ADC_CR2_TSVREFE_Pos                 (23U)                              
#define ADC_CR2_TSVREFE_Msk                 (0x1UL << ADC_CR2_TSVREFE_Pos)      /*!< 0x00800000 */
#define ADC_CR2_TSVREFE                     ADC_CR2_TSVREFE_Msk                /*!< ADC internal path to VrefInt and temperature sensor enable */

/******************  Bit definition for ADC_SMPR1 register  *******************/
#define ADC_SMPR1_SMP10_Pos                 (0U)                               
#define ADC_SMPR1_SMP10_Msk                 (0x7UL << ADC_SMPR1_SMP10_Pos)      /*!< 0x00000007 */
#define ADC_SMPR1_SMP10                     ADC_SMPR1_SMP10_Msk                /*!< ADC channel 10 sampling time selection  */
#define ADC_SMPR1_SMP10_0                   (0x1UL << ADC_SMPR1_SMP10_Pos)      /*!< 0x00000001 */
#define ADC_SMPR1_SMP10_1                   (0x2UL << ADC_SMPR1_SMP10_Pos)      /*!< 0x00000002 */
#define ADC_SMPR1_SMP10_2                   (0x4UL << ADC_SMPR1_SMP10_Pos)      /*!< 0x00000004 */

#define ADC_SMPR1_SMP11_Pos                 (3U)                               
#define ADC_SMPR1_SMP11_Msk                 (0x7UL << ADC_SMPR1_SMP11_Pos)      /*!< 0x00000038 */
#define ADC_SMPR1_SMP11                     ADC_SMPR1_SMP11_Msk                /*!< ADC channel 11 sampling time selection  */
#define ADC_SMPR1_SMP11_0                   (0x1UL << ADC_SMPR1_SMP11_Pos)      /*!< 0x00000008 */
#define ADC_SMPR1_SMP11_1                   (0x2UL << ADC_SMPR1_SMP11_Pos)      /*!< 0x00000010 */
#define ADC_SMPR1_SMP11_2                   (0x4UL << ADC_SMPR1_SMP11_Pos)      /*!< 0x00000020 */

#define ADC_SMPR1_SMP12_Pos                 (6U)                               
#define ADC_SMPR1_SMP12_Msk                 (0x7UL << ADC_SMPR1_SMP12_Pos)      /*!< 0x000001C0 */
#define ADC_SMPR1_SMP12                     ADC_SMPR1_SMP12_Msk                /*!< ADC channel 12 sampling time selection  */
#define ADC_SMPR1_SMP12_0                   (0x1UL << ADC_SMPR1_SMP12_Pos)      /*!< 0x00000040 */
#define ADC_SMPR1_SMP12_1                   (0x2UL << ADC_SMPR1_SMP12_Pos)      /*!< 0x00000080 */
#define ADC_SMPR1_SMP12_2                   (0x4UL << ADC_SMPR1_SMP12_Pos)      /*!< 0x00000100 */

#define ADC_SMPR1_SMP13_Pos                 (9U)                               
#define ADC_SMPR1_SMP13_Msk                 (0x7UL << ADC_SMPR1_SMP13_Pos)      /*!< 0x00000E00 */
#define ADC_SMPR1_SMP13                     ADC_SMPR1_SMP13_Msk                /*!< ADC channel 13 sampling time selection  */
#define ADC_SMPR1_SMP13_0                   (0x1UL << ADC_SMPR1_SMP13_Pos)      /*!< 0x00000200 */
#define ADC_SMPR1_SMP13_1                   (0x2UL << ADC_SMPR1_SMP13_Pos)      /*!< 0x00000400 */
#define ADC_SMPR1_SMP13_2                   (0x4UL << ADC_SMPR1_SMP13_Pos)      /*!< 0x00000800 */

#define ADC_SMPR1_SMP14_Pos                 (12U)                              
#define ADC_SMPR1_SMP14_Msk                 (0x7UL << ADC_SMPR1_SMP14_Pos)      /*!< 0x00007000 */
#define ADC_SMPR1_SMP14                     ADC_SMPR1_SMP14_Msk                /*!< ADC channel 14 sampling time selection  */
#define ADC_SMPR1_SMP14_0                   (0x1UL << ADC_SMPR1_SMP14_Pos)      /*!< 0x00001000 */
#define ADC_SMPR1_SMP14_1                   (0x2UL << ADC_SMPR1_SMP14_Pos)      /*!< 0x00002000 */
#define ADC_SMPR1_SMP14_2                   (0x4UL << ADC_SMPR1_SMP14_Pos)      /*!< 0x00004000 */

#define ADC_SMPR1_SMP15_Pos                 (15U)                              
#define ADC_SMPR1_SMP15_Msk                 (0x7UL << ADC_SMPR1_SMP15_Pos)      /*!< 0x00038000 */
#define ADC_SMPR1_SMP15                     ADC_SMPR1_SMP15_Msk                /*!< ADC channel 15 sampling time selection  */
#define ADC_SMPR1_SMP15_0                   (0x1UL << ADC_SMPR1_SMP15_Pos)      /*!< 0x00008000 */
#define ADC_SMPR1_SMP15_1                   (0x2UL << ADC_SMPR1_SMP15_Pos)      /*!< 0x00010000 */
#define ADC_SMPR1_SMP15_2                   (0x4UL << ADC_SMPR1_SMP15_Pos)      /*!< 0x00020000 */

#define ADC_SMPR1_SMP16_Pos                 (18U)                              
#define ADC_SMPR1_SMP16_Msk                 (0x7UL << ADC_SMPR1_SMP16_Pos)      /*!< 0x001C0000 */
#define ADC_SMPR1_SMP16                     ADC_SMPR1_SMP16_Msk                /*!< ADC channel 16 sampling time selection  */
#define ADC_SMPR1_SMP16_0                   (0x1UL << ADC_SMPR1_SMP16_Pos)      /*!< 0x00040000 */
#define ADC_SMPR1_SMP16_1                   (0x2UL << ADC_SMPR1_SMP16_Pos)      /*!< 0x00080000 */
#define ADC_SMPR1_SMP16_2                   (0x4UL << ADC_SMPR1_SMP16_Pos)      /*!< 0x00100000 */

#define ADC_SMPR1_SMP17_Pos                 (21U)                              
#define ADC_SMPR1_SMP17_Msk                 (0x7UL << ADC_SMPR1_SMP17_Pos)      /*!< 0x00E00000 */
#define ADC_SMPR1_SMP17                     ADC_SMPR1_SMP17_Msk                /*!< ADC channel 17 sampling time selection  */
#define ADC_SMPR1_SMP17_0                   (0x1UL << ADC_SMPR1_SMP17_Pos)      /*!< 0x00200000 */
#define ADC_SMPR1_SMP17_1                   (0x2UL << ADC_SMPR1_SMP17_Pos)      /*!< 0x00400000 */
#define ADC_SMPR1_SMP17_2                   (0x4UL << ADC_SMPR1_SMP17_Pos)      /*!< 0x00800000 */

/******************  Bit definition for ADC_SMPR2 register  *******************/
#define ADC_SMPR2_SMP0_Pos                  (0U)                               
#define ADC_SMPR2_SMP0_Msk                  (0x7UL << ADC_SMPR2_SMP0_Pos)       /*!< 0x00000007 */
#define ADC_SMPR2_SMP0                      ADC_SMPR2_SMP0_Msk                 /*!< ADC channel 0 sampling time selection  */
#define ADC_SMPR2_SMP0_0                    (0x1UL << ADC_SMPR2_SMP0_Pos)       /*!< 0x00000001 */
#define ADC_SMPR2_SMP0_1                    (0x2UL << ADC_SMPR2_SMP0_Pos)       /*!< 0x00000002 */
#define ADC_SMPR2_SMP0_2                    (0x4UL << ADC_SMPR2_SMP0_Pos)       /*!< 0x00000004 */

#define ADC_SMPR2_SMP1_Pos                  (3U)                               
#define ADC_SMPR2_SMP1_Msk                  (0x7UL << ADC_SMPR2_SMP1_Pos)       /*!< 0x00000038 */
#define ADC_SMPR2_SMP1                      ADC_SMPR2_SMP1_Msk                 /*!< ADC channel 1 sampling time selection  */
#define ADC_SMPR2_SMP1_0                    (0x1UL << ADC_SMPR2_SMP1_Pos)       /*!< 0x00000008 */
#define ADC_SMPR2_SMP1_1                    (0x2UL << ADC_SMPR2_SMP1_Pos)       /*!< 0x00000010 */
#define ADC_SMPR2_SMP1_2                    (0x4UL << ADC_SMPR2_SMP1_Pos)       /*!< 0x00000020 */

#define ADC_SMPR2_SMP2_Pos                  (6U)                               
#define ADC_SMPR2_SMP2_Msk                  (0x7UL << ADC_SMPR2_SMP2_Pos)       /*!< 0x000001C0 */
#define ADC_SMPR2_SMP2                      ADC_SMPR2_SMP2_Msk                 /*!< ADC channel 2 sampling time selection  */
#define ADC_SMPR2_SMP2_0                    (0x1UL << ADC_SMPR2_SMP2_Pos)       /*!< 0x00000040 */
#define ADC_SMPR2_SMP2_1                    (0x2UL << ADC_SMPR2_SMP2_Pos)       /*!< 0x00000080 */
#define ADC_SMPR2_SMP2_2                    (0x4UL << ADC_SMPR2_SMP2_Pos)       /*!< 0x00000100 */

#define ADC_SMPR2_SMP3_Pos                  (9U)                               
#define ADC_SMPR2_SMP3_Msk                  (0x7UL << ADC_SMPR2_SMP3_Pos)       /*!< 0x00000E00 */
#define ADC_SMPR2_SMP3                      ADC_SMPR2_SMP3_Msk                 /*!< ADC channel 3 sampling time selection  */
#define ADC_SMPR2_SMP3_0                    (0x1UL << ADC_SMPR2_SMP3_Pos)       /*!< 0x00000200 */
#define ADC_SMPR2_SMP3_1                    (0x2UL << ADC_SMPR2_SMP3_Pos)       /*!< 0x00000400 */
#define ADC_SMPR2_SMP3_2                    (0x4UL << ADC_SMPR2_SMP3_Pos)       /*!< 0x00000800 */

#define ADC_SMPR2_SMP4_Pos                  (12U)                              
#define ADC_SMPR2_SMP4_Msk                  (0x7UL << ADC_SMPR2_SMP4_Pos)       /*!< 0x00007000 */
#define ADC_SMPR2_SMP4                      ADC_SMPR2_SMP4_Msk                 /*!< ADC channel 4 sampling time selection  */
#define ADC_SMPR2_SMP4_0                    (0x1UL << ADC_SMPR2_SMP4_Pos)       /*!< 0x00001000 */
#define ADC_SMPR2_SMP4_1                    (0x2UL << ADC_SMPR2_SMP4_Pos)       /*!< 0x00002000 */
#define ADC_SMPR2_SMP4_2                    (0x4UL << ADC_SMPR2_SMP4_Pos)       /*!< 0x00004000 */

#define ADC_SMPR2_SMP5_Pos                  (15U)                              
#define ADC_SMPR2_SMP5_Msk                  (0x7UL << ADC_SMPR2_SMP5_Pos)       /*!< 0x00038000 */
#define ADC_SMPR2_SMP5                      ADC_SMPR2_SMP5_Msk                 /*!< ADC channel 5 sampling time selection  */
#define ADC_SMPR2_SMP5_0                    (0x1UL << ADC_SMPR2_SMP5_Pos)       /*!< 0x00008000 */
#define ADC_SMPR2_SMP5_1                    (0x2UL << ADC_SMPR2_SMP5_Pos)       /*!< 0x00010000 */
#define ADC_SMPR2_SMP5_2                    (0x4UL << ADC_SMPR2_SMP5_Pos)       /*!< 0x00020000 */

#define ADC_SMPR2_SMP6_Pos                  (18U)                              
#define ADC_SMPR2_SMP6_Msk                  (0x7UL << ADC_SMPR2_SMP6_Pos)       /*!< 0x001C0000 */
#define ADC_SMPR2_SMP6                      ADC_SMPR2_SMP6_Msk                 /*!< ADC channel 6 sampling time selection  */
#define ADC_SMPR2_SMP6_0                    (0x1UL << ADC_SMPR2_SMP6_Pos)       /*!< 0x00040000 */
#define ADC_SMPR2_SMP6_1                    (0x2UL << ADC_SMPR2_SMP6_Pos)       /*!< 0x00080000 */
#define ADC_SMPR2_SMP6_2                    (0x4UL << ADC_SMPR2_SMP6_Pos)       /*!< 0x00100000 */

#define ADC_SMPR2_SMP7_Pos                  (21U)                              
#define ADC_SMPR2_SMP7_Msk                  (0x7UL << ADC_SMPR2_SMP7_Pos)       /*!< 0x00E00000 */
#define ADC_SMPR2_SMP7                      ADC_SMPR2_SMP7_Msk                 /*!< ADC channel 7 sampling time selection  */
#define ADC_SMPR2_SMP7_0                    (0x1UL << ADC_SMPR2_SMP7_Pos)       /*!< 0x00200000 */
#define ADC_SMPR2_SMP7_1                    (0x2UL << ADC_SMPR2_SMP7_Pos)       /*!< 0x00400000 */
#define ADC_SMPR2_SMP7_2                    (0x4UL << ADC_SMPR2_SMP7_Pos)       /*!< 0x00800000 */

#define ADC_SMPR2_SMP8_Pos                  (24U)                              
#define ADC_SMPR2_SMP8_Msk                  (0x7UL << ADC_SMPR2_SMP8_Pos)       /*!< 0x07000000 */
#define ADC_SMPR2_SMP8                      ADC_SMPR2_SMP8_Msk                 /*!< ADC channel 8 sampling time selection  */
#define ADC_SMPR2_SMP8_0                    (0x1UL << ADC_SMPR2_SMP8_Pos)       /*!< 0x01000000 */
#define ADC_SMPR2_SMP8_1                    (0x2UL << ADC_SMPR2_SMP8_Pos)       /*!< 0x02000000 */
#define ADC_SMPR2_SMP8_2                    (0x4UL << ADC_SMPR2_SMP8_Pos)       /*!< 0x04000000 */

#define ADC_SMPR2_SMP9_Pos                  (27U)                              
#define ADC_SMPR2_SMP9_Msk                  (0x7UL << ADC_SMPR2_SMP9_Pos)       /*!< 0x38000000 */
#define ADC_SMPR2_SMP9                      ADC_SMPR2_SMP9_Msk                 /*!< ADC channel 9 sampling time selection  */
#define ADC_SMPR2_SMP9_0                    (0x1UL << ADC_SMPR2_SMP9_Pos)       /*!< 0x08000000 */
#define ADC_SMPR2_SMP9_1                    (0x2UL << ADC_SMPR2_SMP9_Pos)       /*!< 0x10000000 */
#define ADC_SMPR2_SMP9_2                    (0x4UL << ADC_SMPR2_SMP9_Pos)       /*!< 0x20000000 */

/******************  Bit definition for ADC_JOFR1 register  *******************/
#define ADC_JOFR1_JOFFSET1_Pos              (0U)                               
#define ADC_JOFR1_JOFFSET1_Msk              (0xFFFUL << ADC_JOFR1_JOFFSET1_Pos) /*!< 0x00000FFF */
#define ADC_JOFR1_JOFFSET1                  ADC_JOFR1_JOFFSET1_Msk             /*!< ADC group injected sequencer rank 1 offset value */

/******************  Bit definition for ADC_JOFR2 register  *******************/
#define ADC_JOFR2_JOFFSET2_Pos              (0U)                               
#define ADC_JOFR2_JOFFSET2_Msk              (0xFFFUL << ADC_JOFR2_JOFFSET2_Pos) /*!< 0x00000FFF */
#define ADC_JOFR2_JOFFSET2                  ADC_JOFR2_JOFFSET2_Msk             /*!< ADC group injected sequencer rank 2 offset value */

/******************  Bit definition for ADC_JOFR3 register  *******************/
#define ADC_JOFR3_JOFFSET3_Pos              (0U)                               
#define ADC_JOFR3_JOFFSET3_Msk              (0xFFFUL << ADC_JOFR3_JOFFSET3_Pos) /*!< 0x00000FFF */
#define ADC_JOFR3_JOFFSET3                  ADC_JOFR3_JOFFSET3_Msk             /*!< ADC group injected sequencer rank 3 offset value */

/******************  Bit definition for ADC_JOFR4 register  *******************/
#define ADC_JOFR4_JOFFSET4_Pos              (0U)                               
#define ADC_JOFR4_JOFFSET4_Msk              (0xFFFUL << ADC_JOFR4_JOFFSET4_Pos) /*!< 0x00000FFF */
#define ADC_JOFR4_JOFFSET4                  ADC_JOFR4_JOFFSET4_Msk             /*!< ADC group injected sequencer rank 4 offset value */

/*******************  Bit definition for ADC_HTR register  ********************/
#define ADC_HTR_HT_Pos                      (0U)                               
#define ADC_HTR_HT_Msk                      (0xFFFUL << ADC_HTR_HT_Pos)         /*!< 0x00000FFF */
#define ADC_HTR_HT                          ADC_HTR_HT_Msk                     /*!< ADC analog watchdog 1 threshold high */

/*******************  Bit definition for ADC_LTR register  ********************/
#define ADC_LTR_LT_Pos                      (0U)                               
#define ADC_LTR_LT_Msk                      (0xFFFUL << ADC_LTR_LT_Pos)         /*!< 0x00000FFF */
#define ADC_LTR_LT                          ADC_LTR_LT_Msk                     /*!< ADC analog watchdog 1 threshold low */

/*******************  Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_SQ13_Pos                   (0U)                               
#define ADC_SQR1_SQ13_Msk                   (0x1FUL << ADC_SQR1_SQ13_Pos)       /*!< 0x0000001F */
#define ADC_SQR1_SQ13                       ADC_SQR1_SQ13_Msk                  /*!< ADC group regular sequencer rank 13 */
#define ADC_SQR1_SQ13_0                     (0x01UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000001 */
#define ADC_SQR1_SQ13_1                     (0x02UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000002 */
#define ADC_SQR1_SQ13_2                     (0x04UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000004 */
#define ADC_SQR1_SQ13_3                     (0x08UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000008 */
#define ADC_SQR1_SQ13_4                     (0x10UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000010 */

#define ADC_SQR1_SQ14_Pos                   (5U)                               
#define ADC_SQR1_SQ14_Msk                   (0x1FUL << ADC_SQR1_SQ14_Pos)       /*!< 0x000003E0 */
#define ADC_SQR1_SQ14                       ADC_SQR1_SQ14_Msk                  /*!< ADC group regular sequencer rank 14 */
#define ADC_SQR1_SQ14_0                     (0x01UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000020 */
#define ADC_SQR1_SQ14_1                     (0x02UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000040 */
#define ADC_SQR1_SQ14_2                     (0x04UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000080 */
#define ADC_SQR1_SQ14_3                     (0x08UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000100 */
#define ADC_SQR1_SQ14_4                     (0x10UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000200 */

#define ADC_SQR1_SQ15_Pos                   (10U)                              
#define ADC_SQR1_SQ15_Msk                   (0x1FUL << ADC_SQR1_SQ15_Pos)       /*!< 0x00007C00 */
#define ADC_SQR1_SQ15                       ADC_SQR1_SQ15_Msk                  /*!< ADC group regular sequencer rank 15 */
#define ADC_SQR1_SQ15_0                     (0x01UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00000400 */
#define ADC_SQR1_SQ15_1                     (0x02UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00000800 */
#define ADC_SQR1_SQ15_2                     (0x04UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00001000 */
#define ADC_SQR1_SQ15_3                     (0x08UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00002000 */
#define ADC_SQR1_SQ15_4                     (0x10UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00004000 */

#define ADC_SQR1_SQ16_Pos                   (15U)                              
#define ADC_SQR1_SQ16_Msk                   (0x1FUL << ADC_SQR1_SQ16_Pos)       /*!< 0x000F8000 */
#define ADC_SQR1_SQ16                       ADC_SQR1_SQ16_Msk                  /*!< ADC group regular sequencer rank 16 */
#define ADC_SQR1_SQ16_0                     (0x01UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00008000 */
#define ADC_SQR1_SQ16_1                     (0x02UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00010000 */
#define ADC_SQR1_SQ16_2                     (0x04UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00020000 */
#define ADC_SQR1_SQ16_3                     (0x08UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00040000 */
#define ADC_SQR1_SQ16_4                     (0x10UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00080000 */

#define ADC_SQR1_L_Pos                      (20U)                              
#define ADC_SQR1_L_Msk                      (0xFUL << ADC_SQR1_L_Pos)           /*!< 0x00F00000 */
#define ADC_SQR1_L                          ADC_SQR1_L_Msk                     /*!< ADC group regular sequencer scan length */
#define ADC_SQR1_L_0                        (0x1UL << ADC_SQR1_L_Pos)           /*!< 0x00100000 */
#define ADC_SQR1_L_1                        (0x2UL << ADC_SQR1_L_Pos)           /*!< 0x00200000 */
#define ADC_SQR1_L_2                        (0x4UL << ADC_SQR1_L_Pos)           /*!< 0x00400000 */
#define ADC_SQR1_L_3                        (0x8UL << ADC_SQR1_L_Pos)           /*!< 0x00800000 */

/*******************  Bit definition for ADC_SQR2 register  *******************/
#define ADC_SQR2_SQ7_Pos                    (0U)                               
#define ADC_SQR2_SQ7_Msk                    (0x1FUL << ADC_SQR2_SQ7_Pos)        /*!< 0x0000001F */
#define ADC_SQR2_SQ7                        ADC_SQR2_SQ7_Msk                   /*!< ADC group regular sequencer rank 7 */
#define ADC_SQR2_SQ7_0                      (0x01UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000001 */
#define ADC_SQR2_SQ7_1                      (0x02UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000002 */
#define ADC_SQR2_SQ7_2                      (0x04UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000004 */
#define ADC_SQR2_SQ7_3                      (0x08UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000008 */
#define ADC_SQR2_SQ7_4                      (0x10UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000010 */

#define ADC_SQR2_SQ8_Pos                    (5U)                               
#define ADC_SQR2_SQ8_Msk                    (0x1FUL << ADC_SQR2_SQ8_Pos)        /*!< 0x000003E0 */
#define ADC_SQR2_SQ8                        ADC_SQR2_SQ8_Msk                   /*!< ADC group regular sequencer rank 8 */
#define ADC_SQR2_SQ8_0                      (0x01UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000020 */
#define ADC_SQR2_SQ8_1                      (0x02UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000040 */
#define ADC_SQR2_SQ8_2                      (0x04UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000080 */
#define ADC_SQR2_SQ8_3                      (0x08UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000100 */
#define ADC_SQR2_SQ8_4                      (0x10UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000200 */

#define ADC_SQR2_SQ9_Pos                    (10U)                              
#define ADC_SQR2_SQ9_Msk                    (0x1FUL << ADC_SQR2_SQ9_Pos)        /*!< 0x00007C00 */
#define ADC_SQR2_SQ9                        ADC_SQR2_SQ9_Msk                   /*!< ADC group regular sequencer rank 9 */
#define ADC_SQR2_SQ9_0                      (0x01UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00000400 */
#define ADC_SQR2_SQ9_1                      (0x02UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00000800 */
#define ADC_SQR2_SQ9_2                      (0x04UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00001000 */
#define ADC_SQR2_SQ9_3                      (0x08UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00002000 */
#define ADC_SQR2_SQ9_4                      (0x10UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00004000 */

#define ADC_SQR2_SQ10_Pos                   (15U)                              
#define ADC_SQR2_SQ10_Msk                   (0x1FUL << ADC_SQR2_SQ10_Pos)       /*!< 0x000F8000 */
#define ADC_SQR2_SQ10                       ADC_SQR2_SQ10_Msk                  /*!< ADC group regular sequencer rank 10 */
#define ADC_SQR2_SQ10_0                     (0x01UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00008000 */
#define ADC_SQR2_SQ10_1                     (0x02UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00010000 */
#define ADC_SQR2_SQ10_2                     (0x04UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00020000 */
#define ADC_SQR2_SQ10_3                     (0x08UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00040000 */
#define ADC_SQR2_SQ10_4                     (0x10UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00080000 */

#define ADC_SQR2_SQ11_Pos                   (20U)                              
#define ADC_SQR2_SQ11_Msk                   (0x1FUL << ADC_SQR2_SQ11_Pos)       /*!< 0x01F00000 */
#define ADC_SQR2_SQ11                       ADC_SQR2_SQ11_Msk                  /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR2_SQ11_0                     (0x01UL << ADC_SQR2_SQ11_Pos)       /*!< 0x00100000 */
#define ADC_SQR2_SQ11_1                     (0x02UL << ADC_SQR2_SQ11_Pos)       /*!< 0x00200000 */
#define ADC_SQR2_SQ11_2                     (0x04UL << ADC_SQR2_SQ11_Pos)       /*!< 0x00400000 */
#define ADC_SQR2_SQ11_3                     (0x08UL << ADC_SQR2_SQ11_Pos)       /*!< 0x00800000 */
#define ADC_SQR2_SQ11_4                     (0x10UL << ADC_SQR2_SQ11_Pos)       /*!< 0x01000000 */

#define ADC_SQR2_SQ12_Pos                   (25U)                              
#define ADC_SQR2_SQ12_Msk                   (0x1FUL << ADC_SQR2_SQ12_Pos)       /*!< 0x3E000000 */
#define ADC_SQR2_SQ12                       ADC_SQR2_SQ12_Msk                  /*!< ADC group regular sequencer rank 12 */
#define ADC_SQR2_SQ12_0                     (0x01UL << ADC_SQR2_SQ12_Pos)       /*!< 0x02000000 */
#define ADC_SQR2_SQ12_1                     (0x02UL << ADC_SQR2_SQ12_Pos)       /*!< 0x04000000 */
#define ADC_SQR2_SQ12_2                     (0x04UL << ADC_SQR2_SQ12_Pos)       /*!< 0x08000000 */
#define ADC_SQR2_SQ12_3                     (0x08UL << ADC_SQR2_SQ12_Pos)       /*!< 0x10000000 */
#define ADC_SQR2_SQ12_4                     (0x10UL << ADC_SQR2_SQ12_Pos)       /*!< 0x20000000 */

/*******************  Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ1_Pos                    (0U)                               
#define ADC_SQR3_SQ1_Msk                    (0x1FUL << ADC_SQR3_SQ1_Pos)        /*!< 0x0000001F */
#define ADC_SQR3_SQ1                        ADC_SQR3_SQ1_Msk                   /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR3_SQ1_0                      (0x01UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000001 */
#define ADC_SQR3_SQ1_1                      (0x02UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000002 */
#define ADC_SQR3_SQ1_2                      (0x04UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000004 */
#define ADC_SQR3_SQ1_3                      (0x08UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000008 */
#define ADC_SQR3_SQ1_4                      (0x10UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000010 */

#define ADC_SQR3_SQ2_Pos                    (5U)                               
#define ADC_SQR3_SQ2_Msk                    (0x1FUL << ADC_SQR3_SQ2_Pos)        /*!< 0x000003E0 */
#define ADC_SQR3_SQ2                        ADC_SQR3_SQ2_Msk                   /*!< ADC group regular sequencer rank 2 */
#define ADC_SQR3_SQ2_0                      (0x01UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000020 */
#define ADC_SQR3_SQ2_1                      (0x02UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000040 */
#define ADC_SQR3_SQ2_2                      (0x04UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000080 */
#define ADC_SQR3_SQ2_3                      (0x08UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000100 */
#define ADC_SQR3_SQ2_4                      (0x10UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000200 */

#define ADC_SQR3_SQ3_Pos                    (10U)                              
#define ADC_SQR3_SQ3_Msk                    (0x1FUL << ADC_SQR3_SQ3_Pos)        /*!< 0x00007C00 */
#define ADC_SQR3_SQ3                        ADC_SQR3_SQ3_Msk                   /*!< ADC group regular sequencer rank 3 */
#define ADC_SQR3_SQ3_0                      (0x01UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00000400 */
#define ADC_SQR3_SQ3_1                      (0x02UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00000800 */
#define ADC_SQR3_SQ3_2                      (0x04UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00001000 */
#define ADC_SQR3_SQ3_3                      (0x08UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00002000 */
#define ADC_SQR3_SQ3_4                      (0x10UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00004000 */

#define ADC_SQR3_SQ4_Pos                    (15U)                              
#define ADC_SQR3_SQ4_Msk                    (0x1FUL << ADC_SQR3_SQ4_Pos)        /*!< 0x000F8000 */
#define ADC_SQR3_SQ4                        ADC_SQR3_SQ4_Msk                   /*!< ADC group regular sequencer rank 4 */
#define ADC_SQR3_SQ4_0                      (0x01UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00008000 */
#define ADC_SQR3_SQ4_1                      (0x02UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00010000 */
#define ADC_SQR3_SQ4_2                      (0x04UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00020000 */
#define ADC_SQR3_SQ4_3                      (0x08UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00040000 */
#define ADC_SQR3_SQ4_4                      (0x10UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00080000 */

#define ADC_SQR3_SQ5_Pos                    (20U)                              
#define ADC_SQR3_SQ5_Msk                    (0x1FUL << ADC_SQR3_SQ5_Pos)        /*!< 0x01F00000 */
#define ADC_SQR3_SQ5                        ADC_SQR3_SQ5_Msk                   /*!< ADC group regular sequencer rank 5 */
#define ADC_SQR3_SQ5_0                      (0x01UL << ADC_SQR3_SQ5_Pos)        /*!< 0x00100000 */
#define ADC_SQR3_SQ5_1                      (0x02UL << ADC_SQR3_SQ5_Pos)        /*!< 0x00200000 */
#define ADC_SQR3_SQ5_2                      (0x04UL << ADC_SQR3_SQ5_Pos)        /*!< 0x00400000 */
#define ADC_SQR3_SQ5_3                      (0x08UL << ADC_SQR3_SQ5_Pos)        /*!< 0x00800000 */
#define ADC_SQR3_SQ5_4                      (0x10UL << ADC_SQR3_SQ5_Pos)        /*!< 0x01000000 */

#define ADC_SQR3_SQ6_Pos                    (25U)                              
#define ADC_SQR3_SQ6_Msk                    (0x1FUL << ADC_SQR3_SQ6_Pos)        /*!< 0x3E000000 */
#define ADC_SQR3_SQ6                        ADC_SQR3_SQ6_Msk                   /*!< ADC group regular sequencer rank 6 */
#define ADC_SQR3_SQ6_0                      (0x01UL << ADC_SQR3_SQ6_Pos)        /*!< 0x02000000 */
#define ADC_SQR3_SQ6_1                      (0x02UL << ADC_SQR3_SQ6_Pos)        /*!< 0x04000000 */
#define ADC_SQR3_SQ6_2                      (0x04UL << ADC_SQR3_SQ6_Pos)        /*!< 0x08000000 */
#define ADC_SQR3_SQ6_3                      (0x08UL << ADC_SQR3_SQ6_Pos)        /*!< 0x10000000 */
#define ADC_SQR3_SQ6_4                      (0x10UL << ADC_SQR3_SQ6_Pos)        /*!< 0x20000000 */

/*******************  Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ1_Pos                   (0U)                               
#define ADC_JSQR_JSQ1_Msk                   (0x1FUL << ADC_JSQR_JSQ1_Pos)       /*!< 0x0000001F */
#define ADC_JSQR_JSQ1                       ADC_JSQR_JSQ1_Msk                  /*!< ADC group injected sequencer rank 1 */
#define ADC_JSQR_JSQ1_0                     (0x01UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000001 */
#define ADC_JSQR_JSQ1_1                     (0x02UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000002 */
#define ADC_JSQR_JSQ1_2                     (0x04UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000004 */
#define ADC_JSQR_JSQ1_3                     (0x08UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000008 */
#define ADC_JSQR_JSQ1_4                     (0x10UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000010 */

#define ADC_JSQR_JSQ2_Pos                   (5U)                               
#define ADC_JSQR_JSQ2_Msk                   (0x1FUL << ADC_JSQR_JSQ2_Pos)       /*!< 0x000003E0 */
#define ADC_JSQR_JSQ2                       ADC_JSQR_JSQ2_Msk                  /*!< ADC group injected sequencer rank 2 */
#define ADC_JSQR_JSQ2_0                     (0x01UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000020 */
#define ADC_JSQR_JSQ2_1                     (0x02UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000040 */
#define ADC_JSQR_JSQ2_2                     (0x04UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000080 */
#define ADC_JSQR_JSQ2_3                     (0x08UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000100 */
#define ADC_JSQR_JSQ2_4                     (0x10UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000200 */

#define ADC_JSQR_JSQ3_Pos                   (10U)                              
#define ADC_JSQR_JSQ3_Msk                   (0x1FUL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00007C00 */
#define ADC_JSQR_JSQ3                       ADC_JSQR_JSQ3_Msk                  /*!< ADC group injected sequencer rank 3 */
#define ADC_JSQR_JSQ3_0                     (0x01UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00000400 */
#define ADC_JSQR_JSQ3_1                     (0x02UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00000800 */
#define ADC_JSQR_JSQ3_2                     (0x04UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00001000 */
#define ADC_JSQR_JSQ3_3                     (0x08UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00002000 */
#define ADC_JSQR_JSQ3_4                     (0x10UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00004000 */

#define ADC_JSQR_JSQ4_Pos                   (15U)                              
#define ADC_JSQR_JSQ4_Msk                   (0x1FUL << ADC_JSQR_JSQ4_Pos)       /*!< 0x000F8000 */
#define ADC_JSQR_JSQ4                       ADC_JSQR_JSQ4_Msk                  /*!< ADC group injected sequencer rank 4 */
#define ADC_JSQR_JSQ4_0                     (0x01UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00008000 */
#define ADC_JSQR_JSQ4_1                     (0x02UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00010000 */
#define ADC_JSQR_JSQ4_2                     (0x04UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00020000 */
#define ADC_JSQR_JSQ4_3                     (0x08UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00040000 */
#define ADC_JSQR_JSQ4_4                     (0x10UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00080000 */

#define ADC_JSQR_JL_Pos                     (20U)                              
#define ADC_JSQR_JL_Msk                     (0x3UL << ADC_JSQR_JL_Pos)          /*!< 0x00300000 */
#define ADC_JSQR_JL                         ADC_JSQR_JL_Msk                    /*!< ADC group injected sequencer scan length */
#define ADC_JSQR_JL_0                       (0x1UL << ADC_JSQR_JL_Pos)          /*!< 0x00100000 */
#define ADC_JSQR_JL_1                       (0x2UL << ADC_JSQR_JL_Pos)          /*!< 0x00200000 */

/*******************  Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA_Pos                  (0U)                               
#define ADC_JDR1_JDATA_Msk                  (0xFFFFUL << ADC_JDR1_JDATA_Pos)    /*!< 0x0000FFFF */
#define ADC_JDR1_JDATA                      ADC_JDR1_JDATA_Msk                 /*!< ADC group injected sequencer rank 1 conversion data */

/*******************  Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA_Pos                  (0U)                               
#define ADC_JDR2_JDATA_Msk                  (0xFFFFUL << ADC_JDR2_JDATA_Pos)    /*!< 0x0000FFFF */
#define ADC_JDR2_JDATA                      ADC_JDR2_JDATA_Msk                 /*!< ADC group injected sequencer rank 2 conversion data */

/*******************  Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA_Pos                  (0U)                               
#define ADC_JDR3_JDATA_Msk                  (0xFFFFUL << ADC_JDR3_JDATA_Pos)    /*!< 0x0000FFFF */
#define ADC_JDR3_JDATA                      ADC_JDR3_JDATA_Msk                 /*!< ADC group injected sequencer rank 3 conversion data */

/*******************  Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA_Pos                  (0U)                               
#define ADC_JDR4_JDATA_Msk                  (0xFFFFUL << ADC_JDR4_JDATA_Pos)    /*!< 0x0000FFFF */
#define ADC_JDR4_JDATA                      ADC_JDR4_JDATA_Msk                 /*!< ADC group injected sequencer rank 4 conversion data */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos                     (0U)                               
#define ADC_DR_DATA_Msk                     (0xFFFFUL << ADC_DR_DATA_Pos)       /*!< 0x0000FFFF */
#define ADC_DR_DATA                         ADC_DR_DATA_Msk                    /*!< ADC group regular conversion data */
#define ADC_DR_ADC2DATA_Pos                 (16U)                              
#define ADC_DR_ADC2DATA_Msk                 (0xFFFFUL << ADC_DR_ADC2DATA_Pos)   /*!< 0xFFFF0000 */
#define ADC_DR_ADC2DATA                     ADC_DR_ADC2DATA_Msk                /*!< ADC group regular conversion data for ADC slave, in multimode */



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
/*                         Controller Area Network                            */
/*                                                                            */
/******************************************************************************/

/*!< CAN control and status registers */
/*******************  Bit definition for CAN_MCR register  ********************/
#define CAN_MCR_INRQ_Pos                     (0U)                              
#define CAN_MCR_INRQ_Msk                     (0x1UL << CAN_MCR_INRQ_Pos)        /*!< 0x00000001 */
#define CAN_MCR_INRQ                         CAN_MCR_INRQ_Msk                  /*!< Initialization Request */
#define CAN_MCR_SLEEP_Pos                    (1U)                              
#define CAN_MCR_SLEEP_Msk                    (0x1UL << CAN_MCR_SLEEP_Pos)       /*!< 0x00000002 */
#define CAN_MCR_SLEEP                        CAN_MCR_SLEEP_Msk                 /*!< Sleep Mode Request */
#define CAN_MCR_TXFP_Pos                     (2U)                              
#define CAN_MCR_TXFP_Msk                     (0x1UL << CAN_MCR_TXFP_Pos)        /*!< 0x00000004 */
#define CAN_MCR_TXFP                         CAN_MCR_TXFP_Msk                  /*!< Transmit FIFO Priority */
#define CAN_MCR_RFLM_Pos                     (3U)                              
#define CAN_MCR_RFLM_Msk                     (0x1UL << CAN_MCR_RFLM_Pos)        /*!< 0x00000008 */
#define CAN_MCR_RFLM                         CAN_MCR_RFLM_Msk                  /*!< Receive FIFO Locked Mode */
#define CAN_MCR_NART_Pos                     (4U)                              
#define CAN_MCR_NART_Msk                     (0x1UL << CAN_MCR_NART_Pos)        /*!< 0x00000010 */
#define CAN_MCR_NART                         CAN_MCR_NART_Msk                  /*!< No Automatic Retransmission */
#define CAN_MCR_AWUM_Pos                     (5U)                              
#define CAN_MCR_AWUM_Msk                     (0x1UL << CAN_MCR_AWUM_Pos)        /*!< 0x00000020 */
#define CAN_MCR_AWUM                         CAN_MCR_AWUM_Msk                  /*!< Automatic Wakeup Mode */
#define CAN_MCR_ABOM_Pos                     (6U)                              
#define CAN_MCR_ABOM_Msk                     (0x1UL << CAN_MCR_ABOM_Pos)        /*!< 0x00000040 */
#define CAN_MCR_ABOM                         CAN_MCR_ABOM_Msk                  /*!< Automatic Bus-Off Management */
#define CAN_MCR_TTCM_Pos                     (7U)                              
#define CAN_MCR_TTCM_Msk                     (0x1UL << CAN_MCR_TTCM_Pos)        /*!< 0x00000080 */
#define CAN_MCR_TTCM                         CAN_MCR_TTCM_Msk                  /*!< Time Triggered Communication Mode */
#define CAN_MCR_RESET_Pos                    (15U)                             
#define CAN_MCR_RESET_Msk                    (0x1UL << CAN_MCR_RESET_Pos)       /*!< 0x00008000 */
#define CAN_MCR_RESET                        CAN_MCR_RESET_Msk                 /*!< CAN software master reset */
#define CAN_MCR_DBF_Pos                      (16U)                             
#define CAN_MCR_DBF_Msk                      (0x1UL << CAN_MCR_DBF_Pos)         /*!< 0x00010000 */
#define CAN_MCR_DBF                          CAN_MCR_DBF_Msk                   /*!< CAN Debug freeze */

/*******************  Bit definition for CAN_MSR register  ********************/
#define CAN_MSR_INAK_Pos                     (0U)                              
#define CAN_MSR_INAK_Msk                     (0x1UL << CAN_MSR_INAK_Pos)        /*!< 0x00000001 */
#define CAN_MSR_INAK                         CAN_MSR_INAK_Msk                  /*!< Initialization Acknowledge */
#define CAN_MSR_SLAK_Pos                     (1U)                              
#define CAN_MSR_SLAK_Msk                     (0x1UL << CAN_MSR_SLAK_Pos)        /*!< 0x00000002 */
#define CAN_MSR_SLAK                         CAN_MSR_SLAK_Msk                  /*!< Sleep Acknowledge */
#define CAN_MSR_ERRI_Pos                     (2U)                              
#define CAN_MSR_ERRI_Msk                     (0x1UL << CAN_MSR_ERRI_Pos)        /*!< 0x00000004 */
#define CAN_MSR_ERRI                         CAN_MSR_ERRI_Msk                  /*!< Error Interrupt */
#define CAN_MSR_WKUI_Pos                     (3U)                              
#define CAN_MSR_WKUI_Msk                     (0x1UL << CAN_MSR_WKUI_Pos)        /*!< 0x00000008 */
#define CAN_MSR_WKUI                         CAN_MSR_WKUI_Msk                  /*!< Wakeup Interrupt */
#define CAN_MSR_SLAKI_Pos                    (4U)                              
#define CAN_MSR_SLAKI_Msk                    (0x1UL << CAN_MSR_SLAKI_Pos)       /*!< 0x00000010 */
#define CAN_MSR_SLAKI                        CAN_MSR_SLAKI_Msk                 /*!< Sleep Acknowledge Interrupt */
#define CAN_MSR_TXM_Pos                      (8U)                              
#define CAN_MSR_TXM_Msk                      (0x1UL << CAN_MSR_TXM_Pos)         /*!< 0x00000100 */
#define CAN_MSR_TXM                          CAN_MSR_TXM_Msk                   /*!< Transmit Mode */
#define CAN_MSR_RXM_Pos                      (9U)                              
#define CAN_MSR_RXM_Msk                      (0x1UL << CAN_MSR_RXM_Pos)         /*!< 0x00000200 */
#define CAN_MSR_RXM                          CAN_MSR_RXM_Msk                   /*!< Receive Mode */
#define CAN_MSR_SAMP_Pos                     (10U)                             
#define CAN_MSR_SAMP_Msk                     (0x1UL << CAN_MSR_SAMP_Pos)        /*!< 0x00000400 */
#define CAN_MSR_SAMP                         CAN_MSR_SAMP_Msk                  /*!< Last Sample Point */
#define CAN_MSR_RX_Pos                       (11U)                             
#define CAN_MSR_RX_Msk                       (0x1UL << CAN_MSR_RX_Pos)          /*!< 0x00000800 */
#define CAN_MSR_RX                           CAN_MSR_RX_Msk                    /*!< CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define CAN_TSR_RQCP0_Pos                    (0U)                              
#define CAN_TSR_RQCP0_Msk                    (0x1UL << CAN_TSR_RQCP0_Pos)       /*!< 0x00000001 */
#define CAN_TSR_RQCP0                        CAN_TSR_RQCP0_Msk                 /*!< Request Completed Mailbox0 */
#define CAN_TSR_TXOK0_Pos                    (1U)                              
#define CAN_TSR_TXOK0_Msk                    (0x1UL << CAN_TSR_TXOK0_Pos)       /*!< 0x00000002 */
#define CAN_TSR_TXOK0                        CAN_TSR_TXOK0_Msk                 /*!< Transmission OK of Mailbox0 */
#define CAN_TSR_ALST0_Pos                    (2U)                              
#define CAN_TSR_ALST0_Msk                    (0x1UL << CAN_TSR_ALST0_Pos)       /*!< 0x00000004 */
#define CAN_TSR_ALST0                        CAN_TSR_ALST0_Msk                 /*!< Arbitration Lost for Mailbox0 */
#define CAN_TSR_TERR0_Pos                    (3U)                              
#define CAN_TSR_TERR0_Msk                    (0x1UL << CAN_TSR_TERR0_Pos)       /*!< 0x00000008 */
#define CAN_TSR_TERR0                        CAN_TSR_TERR0_Msk                 /*!< Transmission Error of Mailbox0 */
#define CAN_TSR_ABRQ0_Pos                    (7U)                              
#define CAN_TSR_ABRQ0_Msk                    (0x1UL << CAN_TSR_ABRQ0_Pos)       /*!< 0x00000080 */
#define CAN_TSR_ABRQ0                        CAN_TSR_ABRQ0_Msk                 /*!< Abort Request for Mailbox0 */
#define CAN_TSR_RQCP1_Pos                    (8U)                              
#define CAN_TSR_RQCP1_Msk                    (0x1UL << CAN_TSR_RQCP1_Pos)       /*!< 0x00000100 */
#define CAN_TSR_RQCP1                        CAN_TSR_RQCP1_Msk                 /*!< Request Completed Mailbox1 */
#define CAN_TSR_TXOK1_Pos                    (9U)                              
#define CAN_TSR_TXOK1_Msk                    (0x1UL << CAN_TSR_TXOK1_Pos)       /*!< 0x00000200 */
#define CAN_TSR_TXOK1                        CAN_TSR_TXOK1_Msk                 /*!< Transmission OK of Mailbox1 */
#define CAN_TSR_ALST1_Pos                    (10U)                             
#define CAN_TSR_ALST1_Msk                    (0x1UL << CAN_TSR_ALST1_Pos)       /*!< 0x00000400 */
#define CAN_TSR_ALST1                        CAN_TSR_ALST1_Msk                 /*!< Arbitration Lost for Mailbox1 */
#define CAN_TSR_TERR1_Pos                    (11U)                             
#define CAN_TSR_TERR1_Msk                    (0x1UL << CAN_TSR_TERR1_Pos)       /*!< 0x00000800 */
#define CAN_TSR_TERR1                        CAN_TSR_TERR1_Msk                 /*!< Transmission Error of Mailbox1 */
#define CAN_TSR_ABRQ1_Pos                    (15U)                             
#define CAN_TSR_ABRQ1_Msk                    (0x1UL << CAN_TSR_ABRQ1_Pos)       /*!< 0x00008000 */
#define CAN_TSR_ABRQ1                        CAN_TSR_ABRQ1_Msk                 /*!< Abort Request for Mailbox 1 */
#define CAN_TSR_RQCP2_Pos                    (16U)                             
#define CAN_TSR_RQCP2_Msk                    (0x1UL << CAN_TSR_RQCP2_Pos)       /*!< 0x00010000 */
#define CAN_TSR_RQCP2                        CAN_TSR_RQCP2_Msk                 /*!< Request Completed Mailbox2 */
#define CAN_TSR_TXOK2_Pos                    (17U)                             
#define CAN_TSR_TXOK2_Msk                    (0x1UL << CAN_TSR_TXOK2_Pos)       /*!< 0x00020000 */
#define CAN_TSR_TXOK2                        CAN_TSR_TXOK2_Msk                 /*!< Transmission OK of Mailbox 2 */
#define CAN_TSR_ALST2_Pos                    (18U)                             
#define CAN_TSR_ALST2_Msk                    (0x1UL << CAN_TSR_ALST2_Pos)       /*!< 0x00040000 */
#define CAN_TSR_ALST2                        CAN_TSR_ALST2_Msk                 /*!< Arbitration Lost for mailbox 2 */
#define CAN_TSR_TERR2_Pos                    (19U)                             
#define CAN_TSR_TERR2_Msk                    (0x1UL << CAN_TSR_TERR2_Pos)       /*!< 0x00080000 */
#define CAN_TSR_TERR2                        CAN_TSR_TERR2_Msk                 /*!< Transmission Error of Mailbox 2 */
#define CAN_TSR_ABRQ2_Pos                    (23U)                             
#define CAN_TSR_ABRQ2_Msk                    (0x1UL << CAN_TSR_ABRQ2_Pos)       /*!< 0x00800000 */
#define CAN_TSR_ABRQ2                        CAN_TSR_ABRQ2_Msk                 /*!< Abort Request for Mailbox 2 */
#define CAN_TSR_CODE_Pos                     (24U)                             
#define CAN_TSR_CODE_Msk                     (0x3UL << CAN_TSR_CODE_Pos)        /*!< 0x03000000 */
#define CAN_TSR_CODE                         CAN_TSR_CODE_Msk                  /*!< Mailbox Code */

#define CAN_TSR_TME_Pos                      (26U)                             
#define CAN_TSR_TME_Msk                      (0x7UL << CAN_TSR_TME_Pos)         /*!< 0x1C000000 */
#define CAN_TSR_TME                          CAN_TSR_TME_Msk                   /*!< TME[2:0] bits */
#define CAN_TSR_TME0_Pos                     (26U)                             
#define CAN_TSR_TME0_Msk                     (0x1UL << CAN_TSR_TME0_Pos)        /*!< 0x04000000 */
#define CAN_TSR_TME0                         CAN_TSR_TME0_Msk                  /*!< Transmit Mailbox 0 Empty */
#define CAN_TSR_TME1_Pos                     (27U)                             
#define CAN_TSR_TME1_Msk                     (0x1UL << CAN_TSR_TME1_Pos)        /*!< 0x08000000 */
#define CAN_TSR_TME1                         CAN_TSR_TME1_Msk                  /*!< Transmit Mailbox 1 Empty */
#define CAN_TSR_TME2_Pos                     (28U)                             
#define CAN_TSR_TME2_Msk                     (0x1UL << CAN_TSR_TME2_Pos)        /*!< 0x10000000 */
#define CAN_TSR_TME2                         CAN_TSR_TME2_Msk                  /*!< Transmit Mailbox 2 Empty */

#define CAN_TSR_LOW_Pos                      (29U)                             
#define CAN_TSR_LOW_Msk                      (0x7UL << CAN_TSR_LOW_Pos)         /*!< 0xE0000000 */
#define CAN_TSR_LOW                          CAN_TSR_LOW_Msk                   /*!< LOW[2:0] bits */
#define CAN_TSR_LOW0_Pos                     (29U)                             
#define CAN_TSR_LOW0_Msk                     (0x1UL << CAN_TSR_LOW0_Pos)        /*!< 0x20000000 */
#define CAN_TSR_LOW0                         CAN_TSR_LOW0_Msk                  /*!< Lowest Priority Flag for Mailbox 0 */
#define CAN_TSR_LOW1_Pos                     (30U)                             
#define CAN_TSR_LOW1_Msk                     (0x1UL << CAN_TSR_LOW1_Pos)        /*!< 0x40000000 */
#define CAN_TSR_LOW1                         CAN_TSR_LOW1_Msk                  /*!< Lowest Priority Flag for Mailbox 1 */
#define CAN_TSR_LOW2_Pos                     (31U)                             
#define CAN_TSR_LOW2_Msk                     (0x1UL << CAN_TSR_LOW2_Pos)        /*!< 0x80000000 */
#define CAN_TSR_LOW2                         CAN_TSR_LOW2_Msk                  /*!< Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define CAN_RF0R_FMP0_Pos                    (0U)                              
#define CAN_RF0R_FMP0_Msk                    (0x3UL << CAN_RF0R_FMP0_Pos)       /*!< 0x00000003 */
#define CAN_RF0R_FMP0                        CAN_RF0R_FMP0_Msk                 /*!< FIFO 0 Message Pending */
#define CAN_RF0R_FULL0_Pos                   (3U)                              
#define CAN_RF0R_FULL0_Msk                   (0x1UL << CAN_RF0R_FULL0_Pos)      /*!< 0x00000008 */
#define CAN_RF0R_FULL0                       CAN_RF0R_FULL0_Msk                /*!< FIFO 0 Full */
#define CAN_RF0R_FOVR0_Pos                   (4U)                              
#define CAN_RF0R_FOVR0_Msk                   (0x1UL << CAN_RF0R_FOVR0_Pos)      /*!< 0x00000010 */
#define CAN_RF0R_FOVR0                       CAN_RF0R_FOVR0_Msk                /*!< FIFO 0 Overrun */
#define CAN_RF0R_RFOM0_Pos                   (5U)                              
#define CAN_RF0R_RFOM0_Msk                   (0x1UL << CAN_RF0R_RFOM0_Pos)      /*!< 0x00000020 */
#define CAN_RF0R_RFOM0                       CAN_RF0R_RFOM0_Msk                /*!< Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define CAN_RF1R_FMP1_Pos                    (0U)                              
#define CAN_RF1R_FMP1_Msk                    (0x3UL << CAN_RF1R_FMP1_Pos)       /*!< 0x00000003 */
#define CAN_RF1R_FMP1                        CAN_RF1R_FMP1_Msk                 /*!< FIFO 1 Message Pending */
#define CAN_RF1R_FULL1_Pos                   (3U)                              
#define CAN_RF1R_FULL1_Msk                   (0x1UL << CAN_RF1R_FULL1_Pos)      /*!< 0x00000008 */
#define CAN_RF1R_FULL1                       CAN_RF1R_FULL1_Msk                /*!< FIFO 1 Full */
#define CAN_RF1R_FOVR1_Pos                   (4U)                              
#define CAN_RF1R_FOVR1_Msk                   (0x1UL << CAN_RF1R_FOVR1_Pos)      /*!< 0x00000010 */
#define CAN_RF1R_FOVR1                       CAN_RF1R_FOVR1_Msk                /*!< FIFO 1 Overrun */
#define CAN_RF1R_RFOM1_Pos                   (5U)                              
#define CAN_RF1R_RFOM1_Msk                   (0x1UL << CAN_RF1R_RFOM1_Pos)      /*!< 0x00000020 */
#define CAN_RF1R_RFOM1                       CAN_RF1R_RFOM1_Msk                /*!< Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define CAN_IER_TMEIE_Pos                    (0U)                              
#define CAN_IER_TMEIE_Msk                    (0x1UL << CAN_IER_TMEIE_Pos)       /*!< 0x00000001 */
#define CAN_IER_TMEIE                        CAN_IER_TMEIE_Msk                 /*!< Transmit Mailbox Empty Interrupt Enable */
#define CAN_IER_FMPIE0_Pos                   (1U)                              
#define CAN_IER_FMPIE0_Msk                   (0x1UL << CAN_IER_FMPIE0_Pos)      /*!< 0x00000002 */
#define CAN_IER_FMPIE0                       CAN_IER_FMPIE0_Msk                /*!< FIFO Message Pending Interrupt Enable */
#define CAN_IER_FFIE0_Pos                    (2U)                              
#define CAN_IER_FFIE0_Msk                    (0x1UL << CAN_IER_FFIE0_Pos)       /*!< 0x00000004 */
#define CAN_IER_FFIE0                        CAN_IER_FFIE0_Msk                 /*!< FIFO Full Interrupt Enable */
#define CAN_IER_FOVIE0_Pos                   (3U)                              
#define CAN_IER_FOVIE0_Msk                   (0x1UL << CAN_IER_FOVIE0_Pos)      /*!< 0x00000008 */
#define CAN_IER_FOVIE0                       CAN_IER_FOVIE0_Msk                /*!< FIFO Overrun Interrupt Enable */
#define CAN_IER_FMPIE1_Pos                   (4U)                              
#define CAN_IER_FMPIE1_Msk                   (0x1UL << CAN_IER_FMPIE1_Pos)      /*!< 0x00000010 */
#define CAN_IER_FMPIE1                       CAN_IER_FMPIE1_Msk                /*!< FIFO Message Pending Interrupt Enable */
#define CAN_IER_FFIE1_Pos                    (5U)                              
#define CAN_IER_FFIE1_Msk                    (0x1UL << CAN_IER_FFIE1_Pos)       /*!< 0x00000020 */
#define CAN_IER_FFIE1                        CAN_IER_FFIE1_Msk                 /*!< FIFO Full Interrupt Enable */
#define CAN_IER_FOVIE1_Pos                   (6U)                              
#define CAN_IER_FOVIE1_Msk                   (0x1UL << CAN_IER_FOVIE1_Pos)      /*!< 0x00000040 */
#define CAN_IER_FOVIE1                       CAN_IER_FOVIE1_Msk                /*!< FIFO Overrun Interrupt Enable */
#define CAN_IER_EWGIE_Pos                    (8U)                              
#define CAN_IER_EWGIE_Msk                    (0x1UL << CAN_IER_EWGIE_Pos)       /*!< 0x00000100 */
#define CAN_IER_EWGIE                        CAN_IER_EWGIE_Msk                 /*!< Error Warning Interrupt Enable */
#define CAN_IER_EPVIE_Pos                    (9U)                              
#define CAN_IER_EPVIE_Msk                    (0x1UL << CAN_IER_EPVIE_Pos)       /*!< 0x00000200 */
#define CAN_IER_EPVIE                        CAN_IER_EPVIE_Msk                 /*!< Error Passive Interrupt Enable */
#define CAN_IER_BOFIE_Pos                    (10U)                             
#define CAN_IER_BOFIE_Msk                    (0x1UL << CAN_IER_BOFIE_Pos)       /*!< 0x00000400 */
#define CAN_IER_BOFIE                        CAN_IER_BOFIE_Msk                 /*!< Bus-Off Interrupt Enable */
#define CAN_IER_LECIE_Pos                    (11U)                             
#define CAN_IER_LECIE_Msk                    (0x1UL << CAN_IER_LECIE_Pos)       /*!< 0x00000800 */
#define CAN_IER_LECIE                        CAN_IER_LECIE_Msk                 /*!< Last Error Code Interrupt Enable */
#define CAN_IER_ERRIE_Pos                    (15U)                             
#define CAN_IER_ERRIE_Msk                    (0x1UL << CAN_IER_ERRIE_Pos)       /*!< 0x00008000 */
#define CAN_IER_ERRIE                        CAN_IER_ERRIE_Msk                 /*!< Error Interrupt Enable */
#define CAN_IER_WKUIE_Pos                    (16U)                             
#define CAN_IER_WKUIE_Msk                    (0x1UL << CAN_IER_WKUIE_Pos)       /*!< 0x00010000 */
#define CAN_IER_WKUIE                        CAN_IER_WKUIE_Msk                 /*!< Wakeup Interrupt Enable */
#define CAN_IER_SLKIE_Pos                    (17U)                             
#define CAN_IER_SLKIE_Msk                    (0x1UL << CAN_IER_SLKIE_Pos)       /*!< 0x00020000 */
#define CAN_IER_SLKIE                        CAN_IER_SLKIE_Msk                 /*!< Sleep Interrupt Enable */

/********************  Bit definition for CAN_ESR register  *******************/
#define CAN_ESR_EWGF_Pos                     (0U)                              
#define CAN_ESR_EWGF_Msk                     (0x1UL << CAN_ESR_EWGF_Pos)        /*!< 0x00000001 */
#define CAN_ESR_EWGF                         CAN_ESR_EWGF_Msk                  /*!< Error Warning Flag */
#define CAN_ESR_EPVF_Pos                     (1U)                              
#define CAN_ESR_EPVF_Msk                     (0x1UL << CAN_ESR_EPVF_Pos)        /*!< 0x00000002 */
#define CAN_ESR_EPVF                         CAN_ESR_EPVF_Msk                  /*!< Error Passive Flag */
#define CAN_ESR_BOFF_Pos                     (2U)                              
#define CAN_ESR_BOFF_Msk                     (0x1UL << CAN_ESR_BOFF_Pos)        /*!< 0x00000004 */
#define CAN_ESR_BOFF                         CAN_ESR_BOFF_Msk                  /*!< Bus-Off Flag */

#define CAN_ESR_LEC_Pos                      (4U)                              
#define CAN_ESR_LEC_Msk                      (0x7UL << CAN_ESR_LEC_Pos)         /*!< 0x00000070 */
#define CAN_ESR_LEC                          CAN_ESR_LEC_Msk                   /*!< LEC[2:0] bits (Last Error Code) */
#define CAN_ESR_LEC_0                        (0x1UL << CAN_ESR_LEC_Pos)         /*!< 0x00000010 */
#define CAN_ESR_LEC_1                        (0x2UL << CAN_ESR_LEC_Pos)         /*!< 0x00000020 */
#define CAN_ESR_LEC_2                        (0x4UL << CAN_ESR_LEC_Pos)         /*!< 0x00000040 */

#define CAN_ESR_TEC_Pos                      (16U)                             
#define CAN_ESR_TEC_Msk                      (0xFFUL << CAN_ESR_TEC_Pos)        /*!< 0x00FF0000 */
#define CAN_ESR_TEC                          CAN_ESR_TEC_Msk                   /*!< Least significant byte of the 9-bit Transmit Error Counter */
#define CAN_ESR_REC_Pos                      (24U)                             
#define CAN_ESR_REC_Msk                      (0xFFUL << CAN_ESR_REC_Pos)        /*!< 0xFF000000 */
#define CAN_ESR_REC                          CAN_ESR_REC_Msk                   /*!< Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define CAN_BTR_BRP_Pos                      (0U)                              
#define CAN_BTR_BRP_Msk                      (0x3FFUL << CAN_BTR_BRP_Pos)       /*!< 0x000003FF */
#define CAN_BTR_BRP                          CAN_BTR_BRP_Msk                   /*!<Baud Rate Prescaler */
#define CAN_BTR_TS1_Pos                      (16U)                             
#define CAN_BTR_TS1_Msk                      (0xFUL << CAN_BTR_TS1_Pos)         /*!< 0x000F0000 */
#define CAN_BTR_TS1                          CAN_BTR_TS1_Msk                   /*!<Time Segment 1 */
#define CAN_BTR_TS1_0                        (0x1UL << CAN_BTR_TS1_Pos)         /*!< 0x00010000 */
#define CAN_BTR_TS1_1                        (0x2UL << CAN_BTR_TS1_Pos)         /*!< 0x00020000 */
#define CAN_BTR_TS1_2                        (0x4UL << CAN_BTR_TS1_Pos)         /*!< 0x00040000 */
#define CAN_BTR_TS1_3                        (0x8UL << CAN_BTR_TS1_Pos)         /*!< 0x00080000 */
#define CAN_BTR_TS2_Pos                      (20U)                             
#define CAN_BTR_TS2_Msk                      (0x7UL << CAN_BTR_TS2_Pos)         /*!< 0x00700000 */
#define CAN_BTR_TS2                          CAN_BTR_TS2_Msk                   /*!<Time Segment 2 */
#define CAN_BTR_TS2_0                        (0x1UL << CAN_BTR_TS2_Pos)         /*!< 0x00100000 */
#define CAN_BTR_TS2_1                        (0x2UL << CAN_BTR_TS2_Pos)         /*!< 0x00200000 */
#define CAN_BTR_TS2_2                        (0x4UL << CAN_BTR_TS2_Pos)         /*!< 0x00400000 */
#define CAN_BTR_SJW_Pos                      (24U)                             
#define CAN_BTR_SJW_Msk                      (0x3UL << CAN_BTR_SJW_Pos)         /*!< 0x03000000 */
#define CAN_BTR_SJW                          CAN_BTR_SJW_Msk                   /*!<Resynchronization Jump Width */
#define CAN_BTR_SJW_0                        (0x1UL << CAN_BTR_SJW_Pos)         /*!< 0x01000000 */
#define CAN_BTR_SJW_1                        (0x2UL << CAN_BTR_SJW_Pos)         /*!< 0x02000000 */
#define CAN_BTR_LBKM_Pos                     (30U)                             
#define CAN_BTR_LBKM_Msk                     (0x1UL << CAN_BTR_LBKM_Pos)        /*!< 0x40000000 */
#define CAN_BTR_LBKM                         CAN_BTR_LBKM_Msk                  /*!<Loop Back Mode (Debug) */
#define CAN_BTR_SILM_Pos                     (31U)                             
#define CAN_BTR_SILM_Msk                     (0x1UL << CAN_BTR_SILM_Pos)        /*!< 0x80000000 */
#define CAN_BTR_SILM                         CAN_BTR_SILM_Msk                  /*!<Silent Mode */

/*!< Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define CAN_TI0R_TXRQ_Pos                    (0U)                              
#define CAN_TI0R_TXRQ_Msk                    (0x1UL << CAN_TI0R_TXRQ_Pos)       /*!< 0x00000001 */
#define CAN_TI0R_TXRQ                        CAN_TI0R_TXRQ_Msk                 /*!< Transmit Mailbox Request */
#define CAN_TI0R_RTR_Pos                     (1U)                              
#define CAN_TI0R_RTR_Msk                     (0x1UL << CAN_TI0R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_TI0R_RTR                         CAN_TI0R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_TI0R_IDE_Pos                     (2U)                              
#define CAN_TI0R_IDE_Msk                     (0x1UL << CAN_TI0R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_TI0R_IDE                         CAN_TI0R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_TI0R_EXID_Pos                    (3U)                              
#define CAN_TI0R_EXID_Msk                    (0x3FFFFUL << CAN_TI0R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_TI0R_EXID                        CAN_TI0R_EXID_Msk                 /*!< Extended Identifier */
#define CAN_TI0R_STID_Pos                    (21U)                             
#define CAN_TI0R_STID_Msk                    (0x7FFUL << CAN_TI0R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_TI0R_STID                        CAN_TI0R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define CAN_TDT0R_DLC_Pos                    (0U)                              
#define CAN_TDT0R_DLC_Msk                    (0xFUL << CAN_TDT0R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_TDT0R_DLC                        CAN_TDT0R_DLC_Msk                 /*!< Data Length Code */
#define CAN_TDT0R_TGT_Pos                    (8U)                              
#define CAN_TDT0R_TGT_Msk                    (0x1UL << CAN_TDT0R_TGT_Pos)       /*!< 0x00000100 */
#define CAN_TDT0R_TGT                        CAN_TDT0R_TGT_Msk                 /*!< Transmit Global Time */
#define CAN_TDT0R_TIME_Pos                   (16U)                             
#define CAN_TDT0R_TIME_Msk                   (0xFFFFUL << CAN_TDT0R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_TDT0R_TIME                       CAN_TDT0R_TIME_Msk                /*!< Message Time Stamp */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define CAN_TDL0R_DATA0_Pos                  (0U)                              
#define CAN_TDL0R_DATA0_Msk                  (0xFFUL << CAN_TDL0R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_TDL0R_DATA0                      CAN_TDL0R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_TDL0R_DATA1_Pos                  (8U)                              
#define CAN_TDL0R_DATA1_Msk                  (0xFFUL << CAN_TDL0R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_TDL0R_DATA1                      CAN_TDL0R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_TDL0R_DATA2_Pos                  (16U)                             
#define CAN_TDL0R_DATA2_Msk                  (0xFFUL << CAN_TDL0R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_TDL0R_DATA2                      CAN_TDL0R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_TDL0R_DATA3_Pos                  (24U)                             
#define CAN_TDL0R_DATA3_Msk                  (0xFFUL << CAN_TDL0R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_TDL0R_DATA3                      CAN_TDL0R_DATA3_Msk               /*!< Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define CAN_TDH0R_DATA4_Pos                  (0U)                              
#define CAN_TDH0R_DATA4_Msk                  (0xFFUL << CAN_TDH0R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_TDH0R_DATA4                      CAN_TDH0R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_TDH0R_DATA5_Pos                  (8U)                              
#define CAN_TDH0R_DATA5_Msk                  (0xFFUL << CAN_TDH0R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_TDH0R_DATA5                      CAN_TDH0R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_TDH0R_DATA6_Pos                  (16U)                             
#define CAN_TDH0R_DATA6_Msk                  (0xFFUL << CAN_TDH0R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_TDH0R_DATA6                      CAN_TDH0R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_TDH0R_DATA7_Pos                  (24U)                             
#define CAN_TDH0R_DATA7_Msk                  (0xFFUL << CAN_TDH0R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_TDH0R_DATA7                      CAN_TDH0R_DATA7_Msk               /*!< Data byte 7 */

/*******************  Bit definition for CAN_TI1R register  *******************/
#define CAN_TI1R_TXRQ_Pos                    (0U)                              
#define CAN_TI1R_TXRQ_Msk                    (0x1UL << CAN_TI1R_TXRQ_Pos)       /*!< 0x00000001 */
#define CAN_TI1R_TXRQ                        CAN_TI1R_TXRQ_Msk                 /*!< Transmit Mailbox Request */
#define CAN_TI1R_RTR_Pos                     (1U)                              
#define CAN_TI1R_RTR_Msk                     (0x1UL << CAN_TI1R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_TI1R_RTR                         CAN_TI1R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_TI1R_IDE_Pos                     (2U)                              
#define CAN_TI1R_IDE_Msk                     (0x1UL << CAN_TI1R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_TI1R_IDE                         CAN_TI1R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_TI1R_EXID_Pos                    (3U)                              
#define CAN_TI1R_EXID_Msk                    (0x3FFFFUL << CAN_TI1R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_TI1R_EXID                        CAN_TI1R_EXID_Msk                 /*!< Extended Identifier */
#define CAN_TI1R_STID_Pos                    (21U)                             
#define CAN_TI1R_STID_Msk                    (0x7FFUL << CAN_TI1R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_TI1R_STID                        CAN_TI1R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define CAN_TDT1R_DLC_Pos                    (0U)                              
#define CAN_TDT1R_DLC_Msk                    (0xFUL << CAN_TDT1R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_TDT1R_DLC                        CAN_TDT1R_DLC_Msk                 /*!< Data Length Code */
#define CAN_TDT1R_TGT_Pos                    (8U)                              
#define CAN_TDT1R_TGT_Msk                    (0x1UL << CAN_TDT1R_TGT_Pos)       /*!< 0x00000100 */
#define CAN_TDT1R_TGT                        CAN_TDT1R_TGT_Msk                 /*!< Transmit Global Time */
#define CAN_TDT1R_TIME_Pos                   (16U)                             
#define CAN_TDT1R_TIME_Msk                   (0xFFFFUL << CAN_TDT1R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_TDT1R_TIME                       CAN_TDT1R_TIME_Msk                /*!< Message Time Stamp */

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define CAN_TDL1R_DATA0_Pos                  (0U)                              
#define CAN_TDL1R_DATA0_Msk                  (0xFFUL << CAN_TDL1R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_TDL1R_DATA0                      CAN_TDL1R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_TDL1R_DATA1_Pos                  (8U)                              
#define CAN_TDL1R_DATA1_Msk                  (0xFFUL << CAN_TDL1R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_TDL1R_DATA1                      CAN_TDL1R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_TDL1R_DATA2_Pos                  (16U)                             
#define CAN_TDL1R_DATA2_Msk                  (0xFFUL << CAN_TDL1R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_TDL1R_DATA2                      CAN_TDL1R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_TDL1R_DATA3_Pos                  (24U)                             
#define CAN_TDL1R_DATA3_Msk                  (0xFFUL << CAN_TDL1R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_TDL1R_DATA3                      CAN_TDL1R_DATA3_Msk               /*!< Data byte 3 */

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define CAN_TDH1R_DATA4_Pos                  (0U)                              
#define CAN_TDH1R_DATA4_Msk                  (0xFFUL << CAN_TDH1R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_TDH1R_DATA4                      CAN_TDH1R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_TDH1R_DATA5_Pos                  (8U)                              
#define CAN_TDH1R_DATA5_Msk                  (0xFFUL << CAN_TDH1R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_TDH1R_DATA5                      CAN_TDH1R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_TDH1R_DATA6_Pos                  (16U)                             
#define CAN_TDH1R_DATA6_Msk                  (0xFFUL << CAN_TDH1R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_TDH1R_DATA6                      CAN_TDH1R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_TDH1R_DATA7_Pos                  (24U)                             
#define CAN_TDH1R_DATA7_Msk                  (0xFFUL << CAN_TDH1R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_TDH1R_DATA7                      CAN_TDH1R_DATA7_Msk               /*!< Data byte 7 */

/*******************  Bit definition for CAN_TI2R register  *******************/
#define CAN_TI2R_TXRQ_Pos                    (0U)                              
#define CAN_TI2R_TXRQ_Msk                    (0x1UL << CAN_TI2R_TXRQ_Pos)       /*!< 0x00000001 */
#define CAN_TI2R_TXRQ                        CAN_TI2R_TXRQ_Msk                 /*!< Transmit Mailbox Request */
#define CAN_TI2R_RTR_Pos                     (1U)                              
#define CAN_TI2R_RTR_Msk                     (0x1UL << CAN_TI2R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_TI2R_RTR                         CAN_TI2R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_TI2R_IDE_Pos                     (2U)                              
#define CAN_TI2R_IDE_Msk                     (0x1UL << CAN_TI2R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_TI2R_IDE                         CAN_TI2R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_TI2R_EXID_Pos                    (3U)                              
#define CAN_TI2R_EXID_Msk                    (0x3FFFFUL << CAN_TI2R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_TI2R_EXID                        CAN_TI2R_EXID_Msk                 /*!< Extended identifier */
#define CAN_TI2R_STID_Pos                    (21U)                             
#define CAN_TI2R_STID_Msk                    (0x7FFUL << CAN_TI2R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_TI2R_STID                        CAN_TI2R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT2R register  ******************/  
#define CAN_TDT2R_DLC_Pos                    (0U)                              
#define CAN_TDT2R_DLC_Msk                    (0xFUL << CAN_TDT2R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_TDT2R_DLC                        CAN_TDT2R_DLC_Msk                 /*!< Data Length Code */
#define CAN_TDT2R_TGT_Pos                    (8U)                              
#define CAN_TDT2R_TGT_Msk                    (0x1UL << CAN_TDT2R_TGT_Pos)       /*!< 0x00000100 */
#define CAN_TDT2R_TGT                        CAN_TDT2R_TGT_Msk                 /*!< Transmit Global Time */
#define CAN_TDT2R_TIME_Pos                   (16U)                             
#define CAN_TDT2R_TIME_Msk                   (0xFFFFUL << CAN_TDT2R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_TDT2R_TIME                       CAN_TDT2R_TIME_Msk                /*!< Message Time Stamp */

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define CAN_TDL2R_DATA0_Pos                  (0U)                              
#define CAN_TDL2R_DATA0_Msk                  (0xFFUL << CAN_TDL2R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_TDL2R_DATA0                      CAN_TDL2R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_TDL2R_DATA1_Pos                  (8U)                              
#define CAN_TDL2R_DATA1_Msk                  (0xFFUL << CAN_TDL2R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_TDL2R_DATA1                      CAN_TDL2R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_TDL2R_DATA2_Pos                  (16U)                             
#define CAN_TDL2R_DATA2_Msk                  (0xFFUL << CAN_TDL2R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_TDL2R_DATA2                      CAN_TDL2R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_TDL2R_DATA3_Pos                  (24U)                             
#define CAN_TDL2R_DATA3_Msk                  (0xFFUL << CAN_TDL2R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_TDL2R_DATA3                      CAN_TDL2R_DATA3_Msk               /*!< Data byte 3 */

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define CAN_TDH2R_DATA4_Pos                  (0U)                              
#define CAN_TDH2R_DATA4_Msk                  (0xFFUL << CAN_TDH2R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_TDH2R_DATA4                      CAN_TDH2R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_TDH2R_DATA5_Pos                  (8U)                              
#define CAN_TDH2R_DATA5_Msk                  (0xFFUL << CAN_TDH2R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_TDH2R_DATA5                      CAN_TDH2R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_TDH2R_DATA6_Pos                  (16U)                             
#define CAN_TDH2R_DATA6_Msk                  (0xFFUL << CAN_TDH2R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_TDH2R_DATA6                      CAN_TDH2R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_TDH2R_DATA7_Pos                  (24U)                             
#define CAN_TDH2R_DATA7_Msk                  (0xFFUL << CAN_TDH2R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_TDH2R_DATA7                      CAN_TDH2R_DATA7_Msk               /*!< Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define CAN_RI0R_RTR_Pos                     (1U)                              
#define CAN_RI0R_RTR_Msk                     (0x1UL << CAN_RI0R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_RI0R_RTR                         CAN_RI0R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_RI0R_IDE_Pos                     (2U)                              
#define CAN_RI0R_IDE_Msk                     (0x1UL << CAN_RI0R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_RI0R_IDE                         CAN_RI0R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_RI0R_EXID_Pos                    (3U)                              
#define CAN_RI0R_EXID_Msk                    (0x3FFFFUL << CAN_RI0R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_RI0R_EXID                        CAN_RI0R_EXID_Msk                 /*!< Extended Identifier */
#define CAN_RI0R_STID_Pos                    (21U)                             
#define CAN_RI0R_STID_Msk                    (0x7FFUL << CAN_RI0R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_RI0R_STID                        CAN_RI0R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define CAN_RDT0R_DLC_Pos                    (0U)                              
#define CAN_RDT0R_DLC_Msk                    (0xFUL << CAN_RDT0R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_RDT0R_DLC                        CAN_RDT0R_DLC_Msk                 /*!< Data Length Code */
#define CAN_RDT0R_FMI_Pos                    (8U)                              
#define CAN_RDT0R_FMI_Msk                    (0xFFUL << CAN_RDT0R_FMI_Pos)      /*!< 0x0000FF00 */
#define CAN_RDT0R_FMI                        CAN_RDT0R_FMI_Msk                 /*!< Filter Match Index */
#define CAN_RDT0R_TIME_Pos                   (16U)                             
#define CAN_RDT0R_TIME_Msk                   (0xFFFFUL << CAN_RDT0R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_RDT0R_TIME                       CAN_RDT0R_TIME_Msk                /*!< Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define CAN_RDL0R_DATA0_Pos                  (0U)                              
#define CAN_RDL0R_DATA0_Msk                  (0xFFUL << CAN_RDL0R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_RDL0R_DATA0                      CAN_RDL0R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_RDL0R_DATA1_Pos                  (8U)                              
#define CAN_RDL0R_DATA1_Msk                  (0xFFUL << CAN_RDL0R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_RDL0R_DATA1                      CAN_RDL0R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_RDL0R_DATA2_Pos                  (16U)                             
#define CAN_RDL0R_DATA2_Msk                  (0xFFUL << CAN_RDL0R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_RDL0R_DATA2                      CAN_RDL0R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_RDL0R_DATA3_Pos                  (24U)                             
#define CAN_RDL0R_DATA3_Msk                  (0xFFUL << CAN_RDL0R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_RDL0R_DATA3                      CAN_RDL0R_DATA3_Msk               /*!< Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define CAN_RDH0R_DATA4_Pos                  (0U)                              
#define CAN_RDH0R_DATA4_Msk                  (0xFFUL << CAN_RDH0R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_RDH0R_DATA4                      CAN_RDH0R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_RDH0R_DATA5_Pos                  (8U)                              
#define CAN_RDH0R_DATA5_Msk                  (0xFFUL << CAN_RDH0R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_RDH0R_DATA5                      CAN_RDH0R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_RDH0R_DATA6_Pos                  (16U)                             
#define CAN_RDH0R_DATA6_Msk                  (0xFFUL << CAN_RDH0R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_RDH0R_DATA6                      CAN_RDH0R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_RDH0R_DATA7_Pos                  (24U)                             
#define CAN_RDH0R_DATA7_Msk                  (0xFFUL << CAN_RDH0R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_RDH0R_DATA7                      CAN_RDH0R_DATA7_Msk               /*!< Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define CAN_RI1R_RTR_Pos                     (1U)                              
#define CAN_RI1R_RTR_Msk                     (0x1UL << CAN_RI1R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_RI1R_RTR                         CAN_RI1R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_RI1R_IDE_Pos                     (2U)                              
#define CAN_RI1R_IDE_Msk                     (0x1UL << CAN_RI1R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_RI1R_IDE                         CAN_RI1R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_RI1R_EXID_Pos                    (3U)                              
#define CAN_RI1R_EXID_Msk                    (0x3FFFFUL << CAN_RI1R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_RI1R_EXID                        CAN_RI1R_EXID_Msk                 /*!< Extended identifier */
#define CAN_RI1R_STID_Pos                    (21U)                             
#define CAN_RI1R_STID_Msk                    (0x7FFUL << CAN_RI1R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_RI1R_STID                        CAN_RI1R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define CAN_RDT1R_DLC_Pos                    (0U)                              
#define CAN_RDT1R_DLC_Msk                    (0xFUL << CAN_RDT1R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_RDT1R_DLC                        CAN_RDT1R_DLC_Msk                 /*!< Data Length Code */
#define CAN_RDT1R_FMI_Pos                    (8U)                              
#define CAN_RDT1R_FMI_Msk                    (0xFFUL << CAN_RDT1R_FMI_Pos)      /*!< 0x0000FF00 */
#define CAN_RDT1R_FMI                        CAN_RDT1R_FMI_Msk                 /*!< Filter Match Index */
#define CAN_RDT1R_TIME_Pos                   (16U)                             
#define CAN_RDT1R_TIME_Msk                   (0xFFFFUL << CAN_RDT1R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_RDT1R_TIME                       CAN_RDT1R_TIME_Msk                /*!< Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define CAN_RDL1R_DATA0_Pos                  (0U)                              
#define CAN_RDL1R_DATA0_Msk                  (0xFFUL << CAN_RDL1R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_RDL1R_DATA0                      CAN_RDL1R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_RDL1R_DATA1_Pos                  (8U)                              
#define CAN_RDL1R_DATA1_Msk                  (0xFFUL << CAN_RDL1R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_RDL1R_DATA1                      CAN_RDL1R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_RDL1R_DATA2_Pos                  (16U)                             
#define CAN_RDL1R_DATA2_Msk                  (0xFFUL << CAN_RDL1R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_RDL1R_DATA2                      CAN_RDL1R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_RDL1R_DATA3_Pos                  (24U)                             
#define CAN_RDL1R_DATA3_Msk                  (0xFFUL << CAN_RDL1R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_RDL1R_DATA3                      CAN_RDL1R_DATA3_Msk               /*!< Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define CAN_RDH1R_DATA4_Pos                  (0U)                              
#define CAN_RDH1R_DATA4_Msk                  (0xFFUL << CAN_RDH1R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_RDH1R_DATA4                      CAN_RDH1R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_RDH1R_DATA5_Pos                  (8U)                              
#define CAN_RDH1R_DATA5_Msk                  (0xFFUL << CAN_RDH1R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_RDH1R_DATA5                      CAN_RDH1R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_RDH1R_DATA6_Pos                  (16U)                             
#define CAN_RDH1R_DATA6_Msk                  (0xFFUL << CAN_RDH1R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_RDH1R_DATA6                      CAN_RDH1R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_RDH1R_DATA7_Pos                  (24U)                             
#define CAN_RDH1R_DATA7_Msk                  (0xFFUL << CAN_RDH1R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_RDH1R_DATA7                      CAN_RDH1R_DATA7_Msk               /*!< Data byte 7 */

/*!< CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define CAN_FMR_FINIT_Pos                    (0U)                              
#define CAN_FMR_FINIT_Msk                    (0x1UL << CAN_FMR_FINIT_Pos)       /*!< 0x00000001 */
#define CAN_FMR_FINIT                        CAN_FMR_FINIT_Msk                 /*!< Filter Init Mode */
#define CAN_FMR_CAN2SB_Pos                   (8U)                              
#define CAN_FMR_CAN2SB_Msk                   (0x3FUL << CAN_FMR_CAN2SB_Pos)     /*!< 0x00003F00 */
#define CAN_FMR_CAN2SB                       CAN_FMR_CAN2SB_Msk                /*!< CAN2 start bank */

/*******************  Bit definition for CAN_FM1R register  *******************/
#define CAN_FM1R_FBM_Pos                     (0U)                              
#define CAN_FM1R_FBM_Msk                     (0x3FFFUL << CAN_FM1R_FBM_Pos)     /*!< 0x00003FFF */
#define CAN_FM1R_FBM                         CAN_FM1R_FBM_Msk                  /*!< Filter Mode */
#define CAN_FM1R_FBM0_Pos                    (0U)                              
#define CAN_FM1R_FBM0_Msk                    (0x1UL << CAN_FM1R_FBM0_Pos)       /*!< 0x00000001 */
#define CAN_FM1R_FBM0                        CAN_FM1R_FBM0_Msk                 /*!< Filter Init Mode for filter 0 */
#define CAN_FM1R_FBM1_Pos                    (1U)                              
#define CAN_FM1R_FBM1_Msk                    (0x1UL << CAN_FM1R_FBM1_Pos)       /*!< 0x00000002 */
#define CAN_FM1R_FBM1                        CAN_FM1R_FBM1_Msk                 /*!< Filter Init Mode for filter 1 */
#define CAN_FM1R_FBM2_Pos                    (2U)                              
#define CAN_FM1R_FBM2_Msk                    (0x1UL << CAN_FM1R_FBM2_Pos)       /*!< 0x00000004 */
#define CAN_FM1R_FBM2                        CAN_FM1R_FBM2_Msk                 /*!< Filter Init Mode for filter 2 */
#define CAN_FM1R_FBM3_Pos                    (3U)                              
#define CAN_FM1R_FBM3_Msk                    (0x1UL << CAN_FM1R_FBM3_Pos)       /*!< 0x00000008 */
#define CAN_FM1R_FBM3                        CAN_FM1R_FBM3_Msk                 /*!< Filter Init Mode for filter 3 */
#define CAN_FM1R_FBM4_Pos                    (4U)                              
#define CAN_FM1R_FBM4_Msk                    (0x1UL << CAN_FM1R_FBM4_Pos)       /*!< 0x00000010 */
#define CAN_FM1R_FBM4                        CAN_FM1R_FBM4_Msk                 /*!< Filter Init Mode for filter 4 */
#define CAN_FM1R_FBM5_Pos                    (5U)                              
#define CAN_FM1R_FBM5_Msk                    (0x1UL << CAN_FM1R_FBM5_Pos)       /*!< 0x00000020 */
#define CAN_FM1R_FBM5                        CAN_FM1R_FBM5_Msk                 /*!< Filter Init Mode for filter 5 */
#define CAN_FM1R_FBM6_Pos                    (6U)                              
#define CAN_FM1R_FBM6_Msk                    (0x1UL << CAN_FM1R_FBM6_Pos)       /*!< 0x00000040 */
#define CAN_FM1R_FBM6                        CAN_FM1R_FBM6_Msk                 /*!< Filter Init Mode for filter 6 */
#define CAN_FM1R_FBM7_Pos                    (7U)                              
#define CAN_FM1R_FBM7_Msk                    (0x1UL << CAN_FM1R_FBM7_Pos)       /*!< 0x00000080 */
#define CAN_FM1R_FBM7                        CAN_FM1R_FBM7_Msk                 /*!< Filter Init Mode for filter 7 */
#define CAN_FM1R_FBM8_Pos                    (8U)                              
#define CAN_FM1R_FBM8_Msk                    (0x1UL << CAN_FM1R_FBM8_Pos)       /*!< 0x00000100 */
#define CAN_FM1R_FBM8                        CAN_FM1R_FBM8_Msk                 /*!< Filter Init Mode for filter 8 */
#define CAN_FM1R_FBM9_Pos                    (9U)                              
#define CAN_FM1R_FBM9_Msk                    (0x1UL << CAN_FM1R_FBM9_Pos)       /*!< 0x00000200 */
#define CAN_FM1R_FBM9                        CAN_FM1R_FBM9_Msk                 /*!< Filter Init Mode for filter 9 */
#define CAN_FM1R_FBM10_Pos                   (10U)                             
#define CAN_FM1R_FBM10_Msk                   (0x1UL << CAN_FM1R_FBM10_Pos)      /*!< 0x00000400 */
#define CAN_FM1R_FBM10                       CAN_FM1R_FBM10_Msk                /*!< Filter Init Mode for filter 10 */
#define CAN_FM1R_FBM11_Pos                   (11U)                             
#define CAN_FM1R_FBM11_Msk                   (0x1UL << CAN_FM1R_FBM11_Pos)      /*!< 0x00000800 */
#define CAN_FM1R_FBM11                       CAN_FM1R_FBM11_Msk                /*!< Filter Init Mode for filter 11 */
#define CAN_FM1R_FBM12_Pos                   (12U)                             
#define CAN_FM1R_FBM12_Msk                   (0x1UL << CAN_FM1R_FBM12_Pos)      /*!< 0x00001000 */
#define CAN_FM1R_FBM12                       CAN_FM1R_FBM12_Msk                /*!< Filter Init Mode for filter 12 */
#define CAN_FM1R_FBM13_Pos                   (13U)                             
#define CAN_FM1R_FBM13_Msk                   (0x1UL << CAN_FM1R_FBM13_Pos)      /*!< 0x00002000 */
#define CAN_FM1R_FBM13                       CAN_FM1R_FBM13_Msk                /*!< Filter Init Mode for filter 13 */

/*******************  Bit definition for CAN_FS1R register  *******************/
#define CAN_FS1R_FSC_Pos                     (0U)                              
#define CAN_FS1R_FSC_Msk                     (0x3FFFUL << CAN_FS1R_FSC_Pos)     /*!< 0x00003FFF */
#define CAN_FS1R_FSC                         CAN_FS1R_FSC_Msk                  /*!< Filter Scale Configuration */
#define CAN_FS1R_FSC0_Pos                    (0U)                              
#define CAN_FS1R_FSC0_Msk                    (0x1UL << CAN_FS1R_FSC0_Pos)       /*!< 0x00000001 */
#define CAN_FS1R_FSC0                        CAN_FS1R_FSC0_Msk                 /*!< Filter Scale Configuration for filter 0 */
#define CAN_FS1R_FSC1_Pos                    (1U)                              
#define CAN_FS1R_FSC1_Msk                    (0x1UL << CAN_FS1R_FSC1_Pos)       /*!< 0x00000002 */
#define CAN_FS1R_FSC1                        CAN_FS1R_FSC1_Msk                 /*!< Filter Scale Configuration for filter 1 */
#define CAN_FS1R_FSC2_Pos                    (2U)                              
#define CAN_FS1R_FSC2_Msk                    (0x1UL << CAN_FS1R_FSC2_Pos)       /*!< 0x00000004 */
#define CAN_FS1R_FSC2                        CAN_FS1R_FSC2_Msk                 /*!< Filter Scale Configuration for filter 2 */
#define CAN_FS1R_FSC3_Pos                    (3U)                              
#define CAN_FS1R_FSC3_Msk                    (0x1UL << CAN_FS1R_FSC3_Pos)       /*!< 0x00000008 */
#define CAN_FS1R_FSC3                        CAN_FS1R_FSC3_Msk                 /*!< Filter Scale Configuration for filter 3 */
#define CAN_FS1R_FSC4_Pos                    (4U)                              
#define CAN_FS1R_FSC4_Msk                    (0x1UL << CAN_FS1R_FSC4_Pos)       /*!< 0x00000010 */
#define CAN_FS1R_FSC4                        CAN_FS1R_FSC4_Msk                 /*!< Filter Scale Configuration for filter 4 */
#define CAN_FS1R_FSC5_Pos                    (5U)                              
#define CAN_FS1R_FSC5_Msk                    (0x1UL << CAN_FS1R_FSC5_Pos)       /*!< 0x00000020 */
#define CAN_FS1R_FSC5                        CAN_FS1R_FSC5_Msk                 /*!< Filter Scale Configuration for filter 5 */
#define CAN_FS1R_FSC6_Pos                    (6U)                              
#define CAN_FS1R_FSC6_Msk                    (0x1UL << CAN_FS1R_FSC6_Pos)       /*!< 0x00000040 */
#define CAN_FS1R_FSC6                        CAN_FS1R_FSC6_Msk                 /*!< Filter Scale Configuration for filter 6 */
#define CAN_FS1R_FSC7_Pos                    (7U)                              
#define CAN_FS1R_FSC7_Msk                    (0x1UL << CAN_FS1R_FSC7_Pos)       /*!< 0x00000080 */
#define CAN_FS1R_FSC7                        CAN_FS1R_FSC7_Msk                 /*!< Filter Scale Configuration for filter 7 */
#define CAN_FS1R_FSC8_Pos                    (8U)                              
#define CAN_FS1R_FSC8_Msk                    (0x1UL << CAN_FS1R_FSC8_Pos)       /*!< 0x00000100 */
#define CAN_FS1R_FSC8                        CAN_FS1R_FSC8_Msk                 /*!< Filter Scale Configuration for filter 8 */
#define CAN_FS1R_FSC9_Pos                    (9U)                              
#define CAN_FS1R_FSC9_Msk                    (0x1UL << CAN_FS1R_FSC9_Pos)       /*!< 0x00000200 */
#define CAN_FS1R_FSC9                        CAN_FS1R_FSC9_Msk                 /*!< Filter Scale Configuration for filter 9 */
#define CAN_FS1R_FSC10_Pos                   (10U)                             
#define CAN_FS1R_FSC10_Msk                   (0x1UL << CAN_FS1R_FSC10_Pos)      /*!< 0x00000400 */
#define CAN_FS1R_FSC10                       CAN_FS1R_FSC10_Msk                /*!< Filter Scale Configuration for filter 10 */
#define CAN_FS1R_FSC11_Pos                   (11U)                             
#define CAN_FS1R_FSC11_Msk                   (0x1UL << CAN_FS1R_FSC11_Pos)      /*!< 0x00000800 */
#define CAN_FS1R_FSC11                       CAN_FS1R_FSC11_Msk                /*!< Filter Scale Configuration for filter 11 */
#define CAN_FS1R_FSC12_Pos                   (12U)                             
#define CAN_FS1R_FSC12_Msk                   (0x1UL << CAN_FS1R_FSC12_Pos)      /*!< 0x00001000 */
#define CAN_FS1R_FSC12                       CAN_FS1R_FSC12_Msk                /*!< Filter Scale Configuration for filter 12 */
#define CAN_FS1R_FSC13_Pos                   (13U)                             
#define CAN_FS1R_FSC13_Msk                   (0x1UL << CAN_FS1R_FSC13_Pos)      /*!< 0x00002000 */
#define CAN_FS1R_FSC13                       CAN_FS1R_FSC13_Msk                /*!< Filter Scale Configuration for filter 13 */

/******************  Bit definition for CAN_FFA1R register  *******************/
#define CAN_FFA1R_FFA_Pos                    (0U)                              
#define CAN_FFA1R_FFA_Msk                    (0x3FFFUL << CAN_FFA1R_FFA_Pos)    /*!< 0x00003FFF */
#define CAN_FFA1R_FFA                        CAN_FFA1R_FFA_Msk                 /*!< Filter FIFO Assignment */
#define CAN_FFA1R_FFA0_Pos                   (0U)                              
#define CAN_FFA1R_FFA0_Msk                   (0x1UL << CAN_FFA1R_FFA0_Pos)      /*!< 0x00000001 */
#define CAN_FFA1R_FFA0                       CAN_FFA1R_FFA0_Msk                /*!< Filter FIFO Assignment for filter 0 */
#define CAN_FFA1R_FFA1_Pos                   (1U)                              
#define CAN_FFA1R_FFA1_Msk                   (0x1UL << CAN_FFA1R_FFA1_Pos)      /*!< 0x00000002 */
#define CAN_FFA1R_FFA1                       CAN_FFA1R_FFA1_Msk                /*!< Filter FIFO Assignment for filter 1 */
#define CAN_FFA1R_FFA2_Pos                   (2U)                              
#define CAN_FFA1R_FFA2_Msk                   (0x1UL << CAN_FFA1R_FFA2_Pos)      /*!< 0x00000004 */
#define CAN_FFA1R_FFA2                       CAN_FFA1R_FFA2_Msk                /*!< Filter FIFO Assignment for filter 2 */
#define CAN_FFA1R_FFA3_Pos                   (3U)                              
#define CAN_FFA1R_FFA3_Msk                   (0x1UL << CAN_FFA1R_FFA3_Pos)      /*!< 0x00000008 */
#define CAN_FFA1R_FFA3                       CAN_FFA1R_FFA3_Msk                /*!< Filter FIFO Assignment for filter 3 */
#define CAN_FFA1R_FFA4_Pos                   (4U)                              
#define CAN_FFA1R_FFA4_Msk                   (0x1UL << CAN_FFA1R_FFA4_Pos)      /*!< 0x00000010 */
#define CAN_FFA1R_FFA4                       CAN_FFA1R_FFA4_Msk                /*!< Filter FIFO Assignment for filter 4 */
#define CAN_FFA1R_FFA5_Pos                   (5U)                              
#define CAN_FFA1R_FFA5_Msk                   (0x1UL << CAN_FFA1R_FFA5_Pos)      /*!< 0x00000020 */
#define CAN_FFA1R_FFA5                       CAN_FFA1R_FFA5_Msk                /*!< Filter FIFO Assignment for filter 5 */
#define CAN_FFA1R_FFA6_Pos                   (6U)                              
#define CAN_FFA1R_FFA6_Msk                   (0x1UL << CAN_FFA1R_FFA6_Pos)      /*!< 0x00000040 */
#define CAN_FFA1R_FFA6                       CAN_FFA1R_FFA6_Msk                /*!< Filter FIFO Assignment for filter 6 */
#define CAN_FFA1R_FFA7_Pos                   (7U)                              
#define CAN_FFA1R_FFA7_Msk                   (0x1UL << CAN_FFA1R_FFA7_Pos)      /*!< 0x00000080 */
#define CAN_FFA1R_FFA7                       CAN_FFA1R_FFA7_Msk                /*!< Filter FIFO Assignment for filter 7 */
#define CAN_FFA1R_FFA8_Pos                   (8U)                              
#define CAN_FFA1R_FFA8_Msk                   (0x1UL << CAN_FFA1R_FFA8_Pos)      /*!< 0x00000100 */
#define CAN_FFA1R_FFA8                       CAN_FFA1R_FFA8_Msk                /*!< Filter FIFO Assignment for filter 8 */
#define CAN_FFA1R_FFA9_Pos                   (9U)                              
#define CAN_FFA1R_FFA9_Msk                   (0x1UL << CAN_FFA1R_FFA9_Pos)      /*!< 0x00000200 */
#define CAN_FFA1R_FFA9                       CAN_FFA1R_FFA9_Msk                /*!< Filter FIFO Assignment for filter 9 */
#define CAN_FFA1R_FFA10_Pos                  (10U)                             
#define CAN_FFA1R_FFA10_Msk                  (0x1UL << CAN_FFA1R_FFA10_Pos)     /*!< 0x00000400 */
#define CAN_FFA1R_FFA10                      CAN_FFA1R_FFA10_Msk               /*!< Filter FIFO Assignment for filter 10 */
#define CAN_FFA1R_FFA11_Pos                  (11U)                             
#define CAN_FFA1R_FFA11_Msk                  (0x1UL << CAN_FFA1R_FFA11_Pos)     /*!< 0x00000800 */
#define CAN_FFA1R_FFA11                      CAN_FFA1R_FFA11_Msk               /*!< Filter FIFO Assignment for filter 11 */
#define CAN_FFA1R_FFA12_Pos                  (12U)                             
#define CAN_FFA1R_FFA12_Msk                  (0x1UL << CAN_FFA1R_FFA12_Pos)     /*!< 0x00001000 */
#define CAN_FFA1R_FFA12                      CAN_FFA1R_FFA12_Msk               /*!< Filter FIFO Assignment for filter 12 */
#define CAN_FFA1R_FFA13_Pos                  (13U)                             
#define CAN_FFA1R_FFA13_Msk                  (0x1UL << CAN_FFA1R_FFA13_Pos)     /*!< 0x00002000 */
#define CAN_FFA1R_FFA13                      CAN_FFA1R_FFA13_Msk               /*!< Filter FIFO Assignment for filter 13 */

/*******************  Bit definition for CAN_FA1R register  *******************/
#define CAN_FA1R_FACT_Pos                    (0U)                              
#define CAN_FA1R_FACT_Msk                    (0x3FFFUL << CAN_FA1R_FACT_Pos)    /*!< 0x00003FFF */
#define CAN_FA1R_FACT                        CAN_FA1R_FACT_Msk                 /*!< Filter Active */
#define CAN_FA1R_FACT0_Pos                   (0U)                              
#define CAN_FA1R_FACT0_Msk                   (0x1UL << CAN_FA1R_FACT0_Pos)      /*!< 0x00000001 */
#define CAN_FA1R_FACT0                       CAN_FA1R_FACT0_Msk                /*!< Filter 0 Active */
#define CAN_FA1R_FACT1_Pos                   (1U)                              
#define CAN_FA1R_FACT1_Msk                   (0x1UL << CAN_FA1R_FACT1_Pos)      /*!< 0x00000002 */
#define CAN_FA1R_FACT1                       CAN_FA1R_FACT1_Msk                /*!< Filter 1 Active */
#define CAN_FA1R_FACT2_Pos                   (2U)                              
#define CAN_FA1R_FACT2_Msk                   (0x1UL << CAN_FA1R_FACT2_Pos)      /*!< 0x00000004 */
#define CAN_FA1R_FACT2                       CAN_FA1R_FACT2_Msk                /*!< Filter 2 Active */
#define CAN_FA1R_FACT3_Pos                   (3U)                              
#define CAN_FA1R_FACT3_Msk                   (0x1UL << CAN_FA1R_FACT3_Pos)      /*!< 0x00000008 */
#define CAN_FA1R_FACT3                       CAN_FA1R_FACT3_Msk                /*!< Filter 3 Active */
#define CAN_FA1R_FACT4_Pos                   (4U)                              
#define CAN_FA1R_FACT4_Msk                   (0x1UL << CAN_FA1R_FACT4_Pos)      /*!< 0x00000010 */
#define CAN_FA1R_FACT4                       CAN_FA1R_FACT4_Msk                /*!< Filter 4 Active */
#define CAN_FA1R_FACT5_Pos                   (5U)                              
#define CAN_FA1R_FACT5_Msk                   (0x1UL << CAN_FA1R_FACT5_Pos)      /*!< 0x00000020 */
#define CAN_FA1R_FACT5                       CAN_FA1R_FACT5_Msk                /*!< Filter 5 Active */
#define CAN_FA1R_FACT6_Pos                   (6U)                              
#define CAN_FA1R_FACT6_Msk                   (0x1UL << CAN_FA1R_FACT6_Pos)      /*!< 0x00000040 */
#define CAN_FA1R_FACT6                       CAN_FA1R_FACT6_Msk                /*!< Filter 6 Active */
#define CAN_FA1R_FACT7_Pos                   (7U)                              
#define CAN_FA1R_FACT7_Msk                   (0x1UL << CAN_FA1R_FACT7_Pos)      /*!< 0x00000080 */
#define CAN_FA1R_FACT7                       CAN_FA1R_FACT7_Msk                /*!< Filter 7 Active */
#define CAN_FA1R_FACT8_Pos                   (8U)                              
#define CAN_FA1R_FACT8_Msk                   (0x1UL << CAN_FA1R_FACT8_Pos)      /*!< 0x00000100 */
#define CAN_FA1R_FACT8                       CAN_FA1R_FACT8_Msk                /*!< Filter 8 Active */
#define CAN_FA1R_FACT9_Pos                   (9U)                              
#define CAN_FA1R_FACT9_Msk                   (0x1UL << CAN_FA1R_FACT9_Pos)      /*!< 0x00000200 */
#define CAN_FA1R_FACT9                       CAN_FA1R_FACT9_Msk                /*!< Filter 9 Active */
#define CAN_FA1R_FACT10_Pos                  (10U)                             
#define CAN_FA1R_FACT10_Msk                  (0x1UL << CAN_FA1R_FACT10_Pos)     /*!< 0x00000400 */
#define CAN_FA1R_FACT10                      CAN_FA1R_FACT10_Msk               /*!< Filter 10 Active */
#define CAN_FA1R_FACT11_Pos                  (11U)                             
#define CAN_FA1R_FACT11_Msk                  (0x1UL << CAN_FA1R_FACT11_Pos)     /*!< 0x00000800 */
#define CAN_FA1R_FACT11                      CAN_FA1R_FACT11_Msk               /*!< Filter 11 Active */
#define CAN_FA1R_FACT12_Pos                  (12U)                             
#define CAN_FA1R_FACT12_Msk                  (0x1UL << CAN_FA1R_FACT12_Pos)     /*!< 0x00001000 */
#define CAN_FA1R_FACT12                      CAN_FA1R_FACT12_Msk               /*!< Filter 12 Active */
#define CAN_FA1R_FACT13_Pos                  (13U)                             
#define CAN_FA1R_FACT13_Msk                  (0x1UL << CAN_FA1R_FACT13_Pos)     /*!< 0x00002000 */
#define CAN_FA1R_FACT13                      CAN_FA1R_FACT13_Msk               /*!< Filter 13 Active */

/*******************  Bit definition for CAN_F0R1 register  *******************/
#define CAN_F0R1_FB0_Pos                     (0U)                              
#define CAN_F0R1_FB0_Msk                     (0x1UL << CAN_F0R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F0R1_FB0                         CAN_F0R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F0R1_FB1_Pos                     (1U)                              
#define CAN_F0R1_FB1_Msk                     (0x1UL << CAN_F0R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F0R1_FB1                         CAN_F0R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F0R1_FB2_Pos                     (2U)                              
#define CAN_F0R1_FB2_Msk                     (0x1UL << CAN_F0R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F0R1_FB2                         CAN_F0R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F0R1_FB3_Pos                     (3U)                              
#define CAN_F0R1_FB3_Msk                     (0x1UL << CAN_F0R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F0R1_FB3                         CAN_F0R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F0R1_FB4_Pos                     (4U)                              
#define CAN_F0R1_FB4_Msk                     (0x1UL << CAN_F0R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F0R1_FB4                         CAN_F0R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F0R1_FB5_Pos                     (5U)                              
#define CAN_F0R1_FB5_Msk                     (0x1UL << CAN_F0R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F0R1_FB5                         CAN_F0R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F0R1_FB6_Pos                     (6U)                              
#define CAN_F0R1_FB6_Msk                     (0x1UL << CAN_F0R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F0R1_FB6                         CAN_F0R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F0R1_FB7_Pos                     (7U)                              
#define CAN_F0R1_FB7_Msk                     (0x1UL << CAN_F0R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F0R1_FB7                         CAN_F0R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F0R1_FB8_Pos                     (8U)                              
#define CAN_F0R1_FB8_Msk                     (0x1UL << CAN_F0R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F0R1_FB8                         CAN_F0R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F0R1_FB9_Pos                     (9U)                              
#define CAN_F0R1_FB9_Msk                     (0x1UL << CAN_F0R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F0R1_FB9                         CAN_F0R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F0R1_FB10_Pos                    (10U)                             
#define CAN_F0R1_FB10_Msk                    (0x1UL << CAN_F0R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F0R1_FB10                        CAN_F0R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F0R1_FB11_Pos                    (11U)                             
#define CAN_F0R1_FB11_Msk                    (0x1UL << CAN_F0R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F0R1_FB11                        CAN_F0R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F0R1_FB12_Pos                    (12U)                             
#define CAN_F0R1_FB12_Msk                    (0x1UL << CAN_F0R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F0R1_FB12                        CAN_F0R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F0R1_FB13_Pos                    (13U)                             
#define CAN_F0R1_FB13_Msk                    (0x1UL << CAN_F0R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F0R1_FB13                        CAN_F0R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F0R1_FB14_Pos                    (14U)                             
#define CAN_F0R1_FB14_Msk                    (0x1UL << CAN_F0R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F0R1_FB14                        CAN_F0R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F0R1_FB15_Pos                    (15U)                             
#define CAN_F0R1_FB15_Msk                    (0x1UL << CAN_F0R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F0R1_FB15                        CAN_F0R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F0R1_FB16_Pos                    (16U)                             
#define CAN_F0R1_FB16_Msk                    (0x1UL << CAN_F0R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F0R1_FB16                        CAN_F0R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F0R1_FB17_Pos                    (17U)                             
#define CAN_F0R1_FB17_Msk                    (0x1UL << CAN_F0R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F0R1_FB17                        CAN_F0R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F0R1_FB18_Pos                    (18U)                             
#define CAN_F0R1_FB18_Msk                    (0x1UL << CAN_F0R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F0R1_FB18                        CAN_F0R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F0R1_FB19_Pos                    (19U)                             
#define CAN_F0R1_FB19_Msk                    (0x1UL << CAN_F0R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F0R1_FB19                        CAN_F0R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F0R1_FB20_Pos                    (20U)                             
#define CAN_F0R1_FB20_Msk                    (0x1UL << CAN_F0R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F0R1_FB20                        CAN_F0R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F0R1_FB21_Pos                    (21U)                             
#define CAN_F0R1_FB21_Msk                    (0x1UL << CAN_F0R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F0R1_FB21                        CAN_F0R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F0R1_FB22_Pos                    (22U)                             
#define CAN_F0R1_FB22_Msk                    (0x1UL << CAN_F0R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F0R1_FB22                        CAN_F0R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F0R1_FB23_Pos                    (23U)                             
#define CAN_F0R1_FB23_Msk                    (0x1UL << CAN_F0R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F0R1_FB23                        CAN_F0R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F0R1_FB24_Pos                    (24U)                             
#define CAN_F0R1_FB24_Msk                    (0x1UL << CAN_F0R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F0R1_FB24                        CAN_F0R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F0R1_FB25_Pos                    (25U)                             
#define CAN_F0R1_FB25_Msk                    (0x1UL << CAN_F0R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F0R1_FB25                        CAN_F0R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F0R1_FB26_Pos                    (26U)                             
#define CAN_F0R1_FB26_Msk                    (0x1UL << CAN_F0R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F0R1_FB26                        CAN_F0R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F0R1_FB27_Pos                    (27U)                             
#define CAN_F0R1_FB27_Msk                    (0x1UL << CAN_F0R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F0R1_FB27                        CAN_F0R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F0R1_FB28_Pos                    (28U)                             
#define CAN_F0R1_FB28_Msk                    (0x1UL << CAN_F0R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F0R1_FB28                        CAN_F0R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F0R1_FB29_Pos                    (29U)                             
#define CAN_F0R1_FB29_Msk                    (0x1UL << CAN_F0R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F0R1_FB29                        CAN_F0R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F0R1_FB30_Pos                    (30U)                             
#define CAN_F0R1_FB30_Msk                    (0x1UL << CAN_F0R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F0R1_FB30                        CAN_F0R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F0R1_FB31_Pos                    (31U)                             
#define CAN_F0R1_FB31_Msk                    (0x1UL << CAN_F0R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F0R1_FB31                        CAN_F0R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define CAN_F1R1_FB0_Pos                     (0U)                              
#define CAN_F1R1_FB0_Msk                     (0x1UL << CAN_F1R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F1R1_FB0                         CAN_F1R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F1R1_FB1_Pos                     (1U)                              
#define CAN_F1R1_FB1_Msk                     (0x1UL << CAN_F1R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F1R1_FB1                         CAN_F1R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F1R1_FB2_Pos                     (2U)                              
#define CAN_F1R1_FB2_Msk                     (0x1UL << CAN_F1R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F1R1_FB2                         CAN_F1R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F1R1_FB3_Pos                     (3U)                              
#define CAN_F1R1_FB3_Msk                     (0x1UL << CAN_F1R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F1R1_FB3                         CAN_F1R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F1R1_FB4_Pos                     (4U)                              
#define CAN_F1R1_FB4_Msk                     (0x1UL << CAN_F1R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F1R1_FB4                         CAN_F1R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F1R1_FB5_Pos                     (5U)                              
#define CAN_F1R1_FB5_Msk                     (0x1UL << CAN_F1R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F1R1_FB5                         CAN_F1R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F1R1_FB6_Pos                     (6U)                              
#define CAN_F1R1_FB6_Msk                     (0x1UL << CAN_F1R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F1R1_FB6                         CAN_F1R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F1R1_FB7_Pos                     (7U)                              
#define CAN_F1R1_FB7_Msk                     (0x1UL << CAN_F1R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F1R1_FB7                         CAN_F1R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F1R1_FB8_Pos                     (8U)                              
#define CAN_F1R1_FB8_Msk                     (0x1UL << CAN_F1R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F1R1_FB8                         CAN_F1R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F1R1_FB9_Pos                     (9U)                              
#define CAN_F1R1_FB9_Msk                     (0x1UL << CAN_F1R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F1R1_FB9                         CAN_F1R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F1R1_FB10_Pos                    (10U)                             
#define CAN_F1R1_FB10_Msk                    (0x1UL << CAN_F1R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F1R1_FB10                        CAN_F1R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F1R1_FB11_Pos                    (11U)                             
#define CAN_F1R1_FB11_Msk                    (0x1UL << CAN_F1R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F1R1_FB11                        CAN_F1R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F1R1_FB12_Pos                    (12U)                             
#define CAN_F1R1_FB12_Msk                    (0x1UL << CAN_F1R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F1R1_FB12                        CAN_F1R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F1R1_FB13_Pos                    (13U)                             
#define CAN_F1R1_FB13_Msk                    (0x1UL << CAN_F1R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F1R1_FB13                        CAN_F1R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F1R1_FB14_Pos                    (14U)                             
#define CAN_F1R1_FB14_Msk                    (0x1UL << CAN_F1R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F1R1_FB14                        CAN_F1R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F1R1_FB15_Pos                    (15U)                             
#define CAN_F1R1_FB15_Msk                    (0x1UL << CAN_F1R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F1R1_FB15                        CAN_F1R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F1R1_FB16_Pos                    (16U)                             
#define CAN_F1R1_FB16_Msk                    (0x1UL << CAN_F1R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F1R1_FB16                        CAN_F1R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F1R1_FB17_Pos                    (17U)                             
#define CAN_F1R1_FB17_Msk                    (0x1UL << CAN_F1R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F1R1_FB17                        CAN_F1R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F1R1_FB18_Pos                    (18U)                             
#define CAN_F1R1_FB18_Msk                    (0x1UL << CAN_F1R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F1R1_FB18                        CAN_F1R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F1R1_FB19_Pos                    (19U)                             
#define CAN_F1R1_FB19_Msk                    (0x1UL << CAN_F1R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F1R1_FB19                        CAN_F1R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F1R1_FB20_Pos                    (20U)                             
#define CAN_F1R1_FB20_Msk                    (0x1UL << CAN_F1R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F1R1_FB20                        CAN_F1R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F1R1_FB21_Pos                    (21U)                             
#define CAN_F1R1_FB21_Msk                    (0x1UL << CAN_F1R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F1R1_FB21                        CAN_F1R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F1R1_FB22_Pos                    (22U)                             
#define CAN_F1R1_FB22_Msk                    (0x1UL << CAN_F1R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F1R1_FB22                        CAN_F1R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F1R1_FB23_Pos                    (23U)                             
#define CAN_F1R1_FB23_Msk                    (0x1UL << CAN_F1R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F1R1_FB23                        CAN_F1R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F1R1_FB24_Pos                    (24U)                             
#define CAN_F1R1_FB24_Msk                    (0x1UL << CAN_F1R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F1R1_FB24                        CAN_F1R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F1R1_FB25_Pos                    (25U)                             
#define CAN_F1R1_FB25_Msk                    (0x1UL << CAN_F1R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F1R1_FB25                        CAN_F1R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F1R1_FB26_Pos                    (26U)                             
#define CAN_F1R1_FB26_Msk                    (0x1UL << CAN_F1R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F1R1_FB26                        CAN_F1R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F1R1_FB27_Pos                    (27U)                             
#define CAN_F1R1_FB27_Msk                    (0x1UL << CAN_F1R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F1R1_FB27                        CAN_F1R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F1R1_FB28_Pos                    (28U)                             
#define CAN_F1R1_FB28_Msk                    (0x1UL << CAN_F1R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F1R1_FB28                        CAN_F1R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F1R1_FB29_Pos                    (29U)                             
#define CAN_F1R1_FB29_Msk                    (0x1UL << CAN_F1R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F1R1_FB29                        CAN_F1R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F1R1_FB30_Pos                    (30U)                             
#define CAN_F1R1_FB30_Msk                    (0x1UL << CAN_F1R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F1R1_FB30                        CAN_F1R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F1R1_FB31_Pos                    (31U)                             
#define CAN_F1R1_FB31_Msk                    (0x1UL << CAN_F1R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F1R1_FB31                        CAN_F1R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define CAN_F2R1_FB0_Pos                     (0U)                              
#define CAN_F2R1_FB0_Msk                     (0x1UL << CAN_F2R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F2R1_FB0                         CAN_F2R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F2R1_FB1_Pos                     (1U)                              
#define CAN_F2R1_FB1_Msk                     (0x1UL << CAN_F2R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F2R1_FB1                         CAN_F2R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F2R1_FB2_Pos                     (2U)                              
#define CAN_F2R1_FB2_Msk                     (0x1UL << CAN_F2R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F2R1_FB2                         CAN_F2R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F2R1_FB3_Pos                     (3U)                              
#define CAN_F2R1_FB3_Msk                     (0x1UL << CAN_F2R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F2R1_FB3                         CAN_F2R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F2R1_FB4_Pos                     (4U)                              
#define CAN_F2R1_FB4_Msk                     (0x1UL << CAN_F2R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F2R1_FB4                         CAN_F2R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F2R1_FB5_Pos                     (5U)                              
#define CAN_F2R1_FB5_Msk                     (0x1UL << CAN_F2R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F2R1_FB5                         CAN_F2R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F2R1_FB6_Pos                     (6U)                              
#define CAN_F2R1_FB6_Msk                     (0x1UL << CAN_F2R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F2R1_FB6                         CAN_F2R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F2R1_FB7_Pos                     (7U)                              
#define CAN_F2R1_FB7_Msk                     (0x1UL << CAN_F2R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F2R1_FB7                         CAN_F2R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F2R1_FB8_Pos                     (8U)                              
#define CAN_F2R1_FB8_Msk                     (0x1UL << CAN_F2R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F2R1_FB8                         CAN_F2R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F2R1_FB9_Pos                     (9U)                              
#define CAN_F2R1_FB9_Msk                     (0x1UL << CAN_F2R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F2R1_FB9                         CAN_F2R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F2R1_FB10_Pos                    (10U)                             
#define CAN_F2R1_FB10_Msk                    (0x1UL << CAN_F2R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F2R1_FB10                        CAN_F2R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F2R1_FB11_Pos                    (11U)                             
#define CAN_F2R1_FB11_Msk                    (0x1UL << CAN_F2R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F2R1_FB11                        CAN_F2R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F2R1_FB12_Pos                    (12U)                             
#define CAN_F2R1_FB12_Msk                    (0x1UL << CAN_F2R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F2R1_FB12                        CAN_F2R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F2R1_FB13_Pos                    (13U)                             
#define CAN_F2R1_FB13_Msk                    (0x1UL << CAN_F2R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F2R1_FB13                        CAN_F2R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F2R1_FB14_Pos                    (14U)                             
#define CAN_F2R1_FB14_Msk                    (0x1UL << CAN_F2R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F2R1_FB14                        CAN_F2R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F2R1_FB15_Pos                    (15U)                             
#define CAN_F2R1_FB15_Msk                    (0x1UL << CAN_F2R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F2R1_FB15                        CAN_F2R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F2R1_FB16_Pos                    (16U)                             
#define CAN_F2R1_FB16_Msk                    (0x1UL << CAN_F2R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F2R1_FB16                        CAN_F2R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F2R1_FB17_Pos                    (17U)                             
#define CAN_F2R1_FB17_Msk                    (0x1UL << CAN_F2R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F2R1_FB17                        CAN_F2R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F2R1_FB18_Pos                    (18U)                             
#define CAN_F2R1_FB18_Msk                    (0x1UL << CAN_F2R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F2R1_FB18                        CAN_F2R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F2R1_FB19_Pos                    (19U)                             
#define CAN_F2R1_FB19_Msk                    (0x1UL << CAN_F2R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F2R1_FB19                        CAN_F2R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F2R1_FB20_Pos                    (20U)                             
#define CAN_F2R1_FB20_Msk                    (0x1UL << CAN_F2R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F2R1_FB20                        CAN_F2R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F2R1_FB21_Pos                    (21U)                             
#define CAN_F2R1_FB21_Msk                    (0x1UL << CAN_F2R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F2R1_FB21                        CAN_F2R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F2R1_FB22_Pos                    (22U)                             
#define CAN_F2R1_FB22_Msk                    (0x1UL << CAN_F2R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F2R1_FB22                        CAN_F2R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F2R1_FB23_Pos                    (23U)                             
#define CAN_F2R1_FB23_Msk                    (0x1UL << CAN_F2R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F2R1_FB23                        CAN_F2R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F2R1_FB24_Pos                    (24U)                             
#define CAN_F2R1_FB24_Msk                    (0x1UL << CAN_F2R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F2R1_FB24                        CAN_F2R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F2R1_FB25_Pos                    (25U)                             
#define CAN_F2R1_FB25_Msk                    (0x1UL << CAN_F2R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F2R1_FB25                        CAN_F2R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F2R1_FB26_Pos                    (26U)                             
#define CAN_F2R1_FB26_Msk                    (0x1UL << CAN_F2R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F2R1_FB26                        CAN_F2R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F2R1_FB27_Pos                    (27U)                             
#define CAN_F2R1_FB27_Msk                    (0x1UL << CAN_F2R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F2R1_FB27                        CAN_F2R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F2R1_FB28_Pos                    (28U)                             
#define CAN_F2R1_FB28_Msk                    (0x1UL << CAN_F2R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F2R1_FB28                        CAN_F2R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F2R1_FB29_Pos                    (29U)                             
#define CAN_F2R1_FB29_Msk                    (0x1UL << CAN_F2R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F2R1_FB29                        CAN_F2R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F2R1_FB30_Pos                    (30U)                             
#define CAN_F2R1_FB30_Msk                    (0x1UL << CAN_F2R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F2R1_FB30                        CAN_F2R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F2R1_FB31_Pos                    (31U)                             
#define CAN_F2R1_FB31_Msk                    (0x1UL << CAN_F2R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F2R1_FB31                        CAN_F2R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define CAN_F3R1_FB0_Pos                     (0U)                              
#define CAN_F3R1_FB0_Msk                     (0x1UL << CAN_F3R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F3R1_FB0                         CAN_F3R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F3R1_FB1_Pos                     (1U)                              
#define CAN_F3R1_FB1_Msk                     (0x1UL << CAN_F3R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F3R1_FB1                         CAN_F3R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F3R1_FB2_Pos                     (2U)                              
#define CAN_F3R1_FB2_Msk                     (0x1UL << CAN_F3R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F3R1_FB2                         CAN_F3R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F3R1_FB3_Pos                     (3U)                              
#define CAN_F3R1_FB3_Msk                     (0x1UL << CAN_F3R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F3R1_FB3                         CAN_F3R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F3R1_FB4_Pos                     (4U)                              
#define CAN_F3R1_FB4_Msk                     (0x1UL << CAN_F3R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F3R1_FB4                         CAN_F3R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F3R1_FB5_Pos                     (5U)                              
#define CAN_F3R1_FB5_Msk                     (0x1UL << CAN_F3R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F3R1_FB5                         CAN_F3R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F3R1_FB6_Pos                     (6U)                              
#define CAN_F3R1_FB6_Msk                     (0x1UL << CAN_F3R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F3R1_FB6                         CAN_F3R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F3R1_FB7_Pos                     (7U)                              
#define CAN_F3R1_FB7_Msk                     (0x1UL << CAN_F3R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F3R1_FB7                         CAN_F3R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F3R1_FB8_Pos                     (8U)                              
#define CAN_F3R1_FB8_Msk                     (0x1UL << CAN_F3R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F3R1_FB8                         CAN_F3R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F3R1_FB9_Pos                     (9U)                              
#define CAN_F3R1_FB9_Msk                     (0x1UL << CAN_F3R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F3R1_FB9                         CAN_F3R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F3R1_FB10_Pos                    (10U)                             
#define CAN_F3R1_FB10_Msk                    (0x1UL << CAN_F3R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F3R1_FB10                        CAN_F3R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F3R1_FB11_Pos                    (11U)                             
#define CAN_F3R1_FB11_Msk                    (0x1UL << CAN_F3R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F3R1_FB11                        CAN_F3R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F3R1_FB12_Pos                    (12U)                             
#define CAN_F3R1_FB12_Msk                    (0x1UL << CAN_F3R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F3R1_FB12                        CAN_F3R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F3R1_FB13_Pos                    (13U)                             
#define CAN_F3R1_FB13_Msk                    (0x1UL << CAN_F3R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F3R1_FB13                        CAN_F3R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F3R1_FB14_Pos                    (14U)                             
#define CAN_F3R1_FB14_Msk                    (0x1UL << CAN_F3R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F3R1_FB14                        CAN_F3R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F3R1_FB15_Pos                    (15U)                             
#define CAN_F3R1_FB15_Msk                    (0x1UL << CAN_F3R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F3R1_FB15                        CAN_F3R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F3R1_FB16_Pos                    (16U)                             
#define CAN_F3R1_FB16_Msk                    (0x1UL << CAN_F3R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F3R1_FB16                        CAN_F3R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F3R1_FB17_Pos                    (17U)                             
#define CAN_F3R1_FB17_Msk                    (0x1UL << CAN_F3R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F3R1_FB17                        CAN_F3R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F3R1_FB18_Pos                    (18U)                             
#define CAN_F3R1_FB18_Msk                    (0x1UL << CAN_F3R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F3R1_FB18                        CAN_F3R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F3R1_FB19_Pos                    (19U)                             
#define CAN_F3R1_FB19_Msk                    (0x1UL << CAN_F3R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F3R1_FB19                        CAN_F3R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F3R1_FB20_Pos                    (20U)                             
#define CAN_F3R1_FB20_Msk                    (0x1UL << CAN_F3R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F3R1_FB20                        CAN_F3R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F3R1_FB21_Pos                    (21U)                             
#define CAN_F3R1_FB21_Msk                    (0x1UL << CAN_F3R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F3R1_FB21                        CAN_F3R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F3R1_FB22_Pos                    (22U)                             
#define CAN_F3R1_FB22_Msk                    (0x1UL << CAN_F3R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F3R1_FB22                        CAN_F3R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F3R1_FB23_Pos                    (23U)                             
#define CAN_F3R1_FB23_Msk                    (0x1UL << CAN_F3R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F3R1_FB23                        CAN_F3R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F3R1_FB24_Pos                    (24U)                             
#define CAN_F3R1_FB24_Msk                    (0x1UL << CAN_F3R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F3R1_FB24                        CAN_F3R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F3R1_FB25_Pos                    (25U)                             
#define CAN_F3R1_FB25_Msk                    (0x1UL << CAN_F3R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F3R1_FB25                        CAN_F3R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F3R1_FB26_Pos                    (26U)                             
#define CAN_F3R1_FB26_Msk                    (0x1UL << CAN_F3R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F3R1_FB26                        CAN_F3R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F3R1_FB27_Pos                    (27U)                             
#define CAN_F3R1_FB27_Msk                    (0x1UL << CAN_F3R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F3R1_FB27                        CAN_F3R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F3R1_FB28_Pos                    (28U)                             
#define CAN_F3R1_FB28_Msk                    (0x1UL << CAN_F3R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F3R1_FB28                        CAN_F3R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F3R1_FB29_Pos                    (29U)                             
#define CAN_F3R1_FB29_Msk                    (0x1UL << CAN_F3R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F3R1_FB29                        CAN_F3R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F3R1_FB30_Pos                    (30U)                             
#define CAN_F3R1_FB30_Msk                    (0x1UL << CAN_F3R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F3R1_FB30                        CAN_F3R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F3R1_FB31_Pos                    (31U)                             
#define CAN_F3R1_FB31_Msk                    (0x1UL << CAN_F3R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F3R1_FB31                        CAN_F3R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define CAN_F4R1_FB0_Pos                     (0U)                              
#define CAN_F4R1_FB0_Msk                     (0x1UL << CAN_F4R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F4R1_FB0                         CAN_F4R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F4R1_FB1_Pos                     (1U)                              
#define CAN_F4R1_FB1_Msk                     (0x1UL << CAN_F4R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F4R1_FB1                         CAN_F4R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F4R1_FB2_Pos                     (2U)                              
#define CAN_F4R1_FB2_Msk                     (0x1UL << CAN_F4R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F4R1_FB2                         CAN_F4R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F4R1_FB3_Pos                     (3U)                              
#define CAN_F4R1_FB3_Msk                     (0x1UL << CAN_F4R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F4R1_FB3                         CAN_F4R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F4R1_FB4_Pos                     (4U)                              
#define CAN_F4R1_FB4_Msk                     (0x1UL << CAN_F4R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F4R1_FB4                         CAN_F4R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F4R1_FB5_Pos                     (5U)                              
#define CAN_F4R1_FB5_Msk                     (0x1UL << CAN_F4R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F4R1_FB5                         CAN_F4R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F4R1_FB6_Pos                     (6U)                              
#define CAN_F4R1_FB6_Msk                     (0x1UL << CAN_F4R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F4R1_FB6                         CAN_F4R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F4R1_FB7_Pos                     (7U)                              
#define CAN_F4R1_FB7_Msk                     (0x1UL << CAN_F4R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F4R1_FB7                         CAN_F4R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F4R1_FB8_Pos                     (8U)                              
#define CAN_F4R1_FB8_Msk                     (0x1UL << CAN_F4R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F4R1_FB8                         CAN_F4R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F4R1_FB9_Pos                     (9U)                              
#define CAN_F4R1_FB9_Msk                     (0x1UL << CAN_F4R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F4R1_FB9                         CAN_F4R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F4R1_FB10_Pos                    (10U)                             
#define CAN_F4R1_FB10_Msk                    (0x1UL << CAN_F4R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F4R1_FB10                        CAN_F4R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F4R1_FB11_Pos                    (11U)                             
#define CAN_F4R1_FB11_Msk                    (0x1UL << CAN_F4R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F4R1_FB11                        CAN_F4R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F4R1_FB12_Pos                    (12U)                             
#define CAN_F4R1_FB12_Msk                    (0x1UL << CAN_F4R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F4R1_FB12                        CAN_F4R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F4R1_FB13_Pos                    (13U)                             
#define CAN_F4R1_FB13_Msk                    (0x1UL << CAN_F4R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F4R1_FB13                        CAN_F4R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F4R1_FB14_Pos                    (14U)                             
#define CAN_F4R1_FB14_Msk                    (0x1UL << CAN_F4R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F4R1_FB14                        CAN_F4R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F4R1_FB15_Pos                    (15U)                             
#define CAN_F4R1_FB15_Msk                    (0x1UL << CAN_F4R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F4R1_FB15                        CAN_F4R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F4R1_FB16_Pos                    (16U)                             
#define CAN_F4R1_FB16_Msk                    (0x1UL << CAN_F4R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F4R1_FB16                        CAN_F4R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F4R1_FB17_Pos                    (17U)                             
#define CAN_F4R1_FB17_Msk                    (0x1UL << CAN_F4R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F4R1_FB17                        CAN_F4R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F4R1_FB18_Pos                    (18U)                             
#define CAN_F4R1_FB18_Msk                    (0x1UL << CAN_F4R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F4R1_FB18                        CAN_F4R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F4R1_FB19_Pos                    (19U)                             
#define CAN_F4R1_FB19_Msk                    (0x1UL << CAN_F4R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F4R1_FB19                        CAN_F4R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F4R1_FB20_Pos                    (20U)                             
#define CAN_F4R1_FB20_Msk                    (0x1UL << CAN_F4R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F4R1_FB20                        CAN_F4R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F4R1_FB21_Pos                    (21U)                             
#define CAN_F4R1_FB21_Msk                    (0x1UL << CAN_F4R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F4R1_FB21                        CAN_F4R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F4R1_FB22_Pos                    (22U)                             
#define CAN_F4R1_FB22_Msk                    (0x1UL << CAN_F4R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F4R1_FB22                        CAN_F4R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F4R1_FB23_Pos                    (23U)                             
#define CAN_F4R1_FB23_Msk                    (0x1UL << CAN_F4R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F4R1_FB23                        CAN_F4R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F4R1_FB24_Pos                    (24U)                             
#define CAN_F4R1_FB24_Msk                    (0x1UL << CAN_F4R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F4R1_FB24                        CAN_F4R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F4R1_FB25_Pos                    (25U)                             
#define CAN_F4R1_FB25_Msk                    (0x1UL << CAN_F4R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F4R1_FB25                        CAN_F4R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F4R1_FB26_Pos                    (26U)                             
#define CAN_F4R1_FB26_Msk                    (0x1UL << CAN_F4R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F4R1_FB26                        CAN_F4R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F4R1_FB27_Pos                    (27U)                             
#define CAN_F4R1_FB27_Msk                    (0x1UL << CAN_F4R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F4R1_FB27                        CAN_F4R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F4R1_FB28_Pos                    (28U)                             
#define CAN_F4R1_FB28_Msk                    (0x1UL << CAN_F4R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F4R1_FB28                        CAN_F4R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F4R1_FB29_Pos                    (29U)                             
#define CAN_F4R1_FB29_Msk                    (0x1UL << CAN_F4R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F4R1_FB29                        CAN_F4R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F4R1_FB30_Pos                    (30U)                             
#define CAN_F4R1_FB30_Msk                    (0x1UL << CAN_F4R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F4R1_FB30                        CAN_F4R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F4R1_FB31_Pos                    (31U)                             
#define CAN_F4R1_FB31_Msk                    (0x1UL << CAN_F4R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F4R1_FB31                        CAN_F4R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define CAN_F5R1_FB0_Pos                     (0U)                              
#define CAN_F5R1_FB0_Msk                     (0x1UL << CAN_F5R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F5R1_FB0                         CAN_F5R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F5R1_FB1_Pos                     (1U)                              
#define CAN_F5R1_FB1_Msk                     (0x1UL << CAN_F5R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F5R1_FB1                         CAN_F5R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F5R1_FB2_Pos                     (2U)                              
#define CAN_F5R1_FB2_Msk                     (0x1UL << CAN_F5R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F5R1_FB2                         CAN_F5R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F5R1_FB3_Pos                     (3U)                              
#define CAN_F5R1_FB3_Msk                     (0x1UL << CAN_F5R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F5R1_FB3                         CAN_F5R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F5R1_FB4_Pos                     (4U)                              
#define CAN_F5R1_FB4_Msk                     (0x1UL << CAN_F5R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F5R1_FB4                         CAN_F5R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F5R1_FB5_Pos                     (5U)                              
#define CAN_F5R1_FB5_Msk                     (0x1UL << CAN_F5R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F5R1_FB5                         CAN_F5R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F5R1_FB6_Pos                     (6U)                              
#define CAN_F5R1_FB6_Msk                     (0x1UL << CAN_F5R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F5R1_FB6                         CAN_F5R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F5R1_FB7_Pos                     (7U)                              
#define CAN_F5R1_FB7_Msk                     (0x1UL << CAN_F5R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F5R1_FB7                         CAN_F5R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F5R1_FB8_Pos                     (8U)                              
#define CAN_F5R1_FB8_Msk                     (0x1UL << CAN_F5R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F5R1_FB8                         CAN_F5R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F5R1_FB9_Pos                     (9U)                              
#define CAN_F5R1_FB9_Msk                     (0x1UL << CAN_F5R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F5R1_FB9                         CAN_F5R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F5R1_FB10_Pos                    (10U)                             
#define CAN_F5R1_FB10_Msk                    (0x1UL << CAN_F5R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F5R1_FB10                        CAN_F5R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F5R1_FB11_Pos                    (11U)                             
#define CAN_F5R1_FB11_Msk                    (0x1UL << CAN_F5R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F5R1_FB11                        CAN_F5R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F5R1_FB12_Pos                    (12U)                             
#define CAN_F5R1_FB12_Msk                    (0x1UL << CAN_F5R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F5R1_FB12                        CAN_F5R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F5R1_FB13_Pos                    (13U)                             
#define CAN_F5R1_FB13_Msk                    (0x1UL << CAN_F5R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F5R1_FB13                        CAN_F5R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F5R1_FB14_Pos                    (14U)                             
#define CAN_F5R1_FB14_Msk                    (0x1UL << CAN_F5R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F5R1_FB14                        CAN_F5R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F5R1_FB15_Pos                    (15U)                             
#define CAN_F5R1_FB15_Msk                    (0x1UL << CAN_F5R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F5R1_FB15                        CAN_F5R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F5R1_FB16_Pos                    (16U)                             
#define CAN_F5R1_FB16_Msk                    (0x1UL << CAN_F5R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F5R1_FB16                        CAN_F5R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F5R1_FB17_Pos                    (17U)                             
#define CAN_F5R1_FB17_Msk                    (0x1UL << CAN_F5R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F5R1_FB17                        CAN_F5R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F5R1_FB18_Pos                    (18U)                             
#define CAN_F5R1_FB18_Msk                    (0x1UL << CAN_F5R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F5R1_FB18                        CAN_F5R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F5R1_FB19_Pos                    (19U)                             
#define CAN_F5R1_FB19_Msk                    (0x1UL << CAN_F5R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F5R1_FB19                        CAN_F5R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F5R1_FB20_Pos                    (20U)                             
#define CAN_F5R1_FB20_Msk                    (0x1UL << CAN_F5R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F5R1_FB20                        CAN_F5R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F5R1_FB21_Pos                    (21U)                             
#define CAN_F5R1_FB21_Msk                    (0x1UL << CAN_F5R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F5R1_FB21                        CAN_F5R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F5R1_FB22_Pos                    (22U)                             
#define CAN_F5R1_FB22_Msk                    (0x1UL << CAN_F5R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F5R1_FB22                        CAN_F5R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F5R1_FB23_Pos                    (23U)                             
#define CAN_F5R1_FB23_Msk                    (0x1UL << CAN_F5R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F5R1_FB23                        CAN_F5R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F5R1_FB24_Pos                    (24U)                             
#define CAN_F5R1_FB24_Msk                    (0x1UL << CAN_F5R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F5R1_FB24                        CAN_F5R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F5R1_FB25_Pos                    (25U)                             
#define CAN_F5R1_FB25_Msk                    (0x1UL << CAN_F5R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F5R1_FB25                        CAN_F5R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F5R1_FB26_Pos                    (26U)                             
#define CAN_F5R1_FB26_Msk                    (0x1UL << CAN_F5R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F5R1_FB26                        CAN_F5R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F5R1_FB27_Pos                    (27U)                             
#define CAN_F5R1_FB27_Msk                    (0x1UL << CAN_F5R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F5R1_FB27                        CAN_F5R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F5R1_FB28_Pos                    (28U)                             
#define CAN_F5R1_FB28_Msk                    (0x1UL << CAN_F5R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F5R1_FB28                        CAN_F5R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F5R1_FB29_Pos                    (29U)                             
#define CAN_F5R1_FB29_Msk                    (0x1UL << CAN_F5R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F5R1_FB29                        CAN_F5R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F5R1_FB30_Pos                    (30U)                             
#define CAN_F5R1_FB30_Msk                    (0x1UL << CAN_F5R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F5R1_FB30                        CAN_F5R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F5R1_FB31_Pos                    (31U)                             
#define CAN_F5R1_FB31_Msk                    (0x1UL << CAN_F5R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F5R1_FB31                        CAN_F5R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define CAN_F6R1_FB0_Pos                     (0U)                              
#define CAN_F6R1_FB0_Msk                     (0x1UL << CAN_F6R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F6R1_FB0                         CAN_F6R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F6R1_FB1_Pos                     (1U)                              
#define CAN_F6R1_FB1_Msk                     (0x1UL << CAN_F6R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F6R1_FB1                         CAN_F6R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F6R1_FB2_Pos                     (2U)                              
#define CAN_F6R1_FB2_Msk                     (0x1UL << CAN_F6R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F6R1_FB2                         CAN_F6R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F6R1_FB3_Pos                     (3U)                              
#define CAN_F6R1_FB3_Msk                     (0x1UL << CAN_F6R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F6R1_FB3                         CAN_F6R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F6R1_FB4_Pos                     (4U)                              
#define CAN_F6R1_FB4_Msk                     (0x1UL << CAN_F6R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F6R1_FB4                         CAN_F6R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F6R1_FB5_Pos                     (5U)                              
#define CAN_F6R1_FB5_Msk                     (0x1UL << CAN_F6R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F6R1_FB5                         CAN_F6R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F6R1_FB6_Pos                     (6U)                              
#define CAN_F6R1_FB6_Msk                     (0x1UL << CAN_F6R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F6R1_FB6                         CAN_F6R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F6R1_FB7_Pos                     (7U)                              
#define CAN_F6R1_FB7_Msk                     (0x1UL << CAN_F6R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F6R1_FB7                         CAN_F6R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F6R1_FB8_Pos                     (8U)                              
#define CAN_F6R1_FB8_Msk                     (0x1UL << CAN_F6R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F6R1_FB8                         CAN_F6R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F6R1_FB9_Pos                     (9U)                              
#define CAN_F6R1_FB9_Msk                     (0x1UL << CAN_F6R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F6R1_FB9                         CAN_F6R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F6R1_FB10_Pos                    (10U)                             
#define CAN_F6R1_FB10_Msk                    (0x1UL << CAN_F6R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F6R1_FB10                        CAN_F6R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F6R1_FB11_Pos                    (11U)                             
#define CAN_F6R1_FB11_Msk                    (0x1UL << CAN_F6R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F6R1_FB11                        CAN_F6R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F6R1_FB12_Pos                    (12U)                             
#define CAN_F6R1_FB12_Msk                    (0x1UL << CAN_F6R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F6R1_FB12                        CAN_F6R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F6R1_FB13_Pos                    (13U)                             
#define CAN_F6R1_FB13_Msk                    (0x1UL << CAN_F6R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F6R1_FB13                        CAN_F6R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F6R1_FB14_Pos                    (14U)                             
#define CAN_F6R1_FB14_Msk                    (0x1UL << CAN_F6R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F6R1_FB14                        CAN_F6R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F6R1_FB15_Pos                    (15U)                             
#define CAN_F6R1_FB15_Msk                    (0x1UL << CAN_F6R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F6R1_FB15                        CAN_F6R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F6R1_FB16_Pos                    (16U)                             
#define CAN_F6R1_FB16_Msk                    (0x1UL << CAN_F6R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F6R1_FB16                        CAN_F6R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F6R1_FB17_Pos                    (17U)                             
#define CAN_F6R1_FB17_Msk                    (0x1UL << CAN_F6R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F6R1_FB17                        CAN_F6R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F6R1_FB18_Pos                    (18U)                             
#define CAN_F6R1_FB18_Msk                    (0x1UL << CAN_F6R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F6R1_FB18                        CAN_F6R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F6R1_FB19_Pos                    (19U)                             
#define CAN_F6R1_FB19_Msk                    (0x1UL << CAN_F6R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F6R1_FB19                        CAN_F6R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F6R1_FB20_Pos                    (20U)                             
#define CAN_F6R1_FB20_Msk                    (0x1UL << CAN_F6R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F6R1_FB20                        CAN_F6R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F6R1_FB21_Pos                    (21U)                             
#define CAN_F6R1_FB21_Msk                    (0x1UL << CAN_F6R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F6R1_FB21                        CAN_F6R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F6R1_FB22_Pos                    (22U)                             
#define CAN_F6R1_FB22_Msk                    (0x1UL << CAN_F6R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F6R1_FB22                        CAN_F6R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F6R1_FB23_Pos                    (23U)                             
#define CAN_F6R1_FB23_Msk                    (0x1UL << CAN_F6R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F6R1_FB23                        CAN_F6R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F6R1_FB24_Pos                    (24U)                             
#define CAN_F6R1_FB24_Msk                    (0x1UL << CAN_F6R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F6R1_FB24                        CAN_F6R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F6R1_FB25_Pos                    (25U)                             
#define CAN_F6R1_FB25_Msk                    (0x1UL << CAN_F6R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F6R1_FB25                        CAN_F6R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F6R1_FB26_Pos                    (26U)                             
#define CAN_F6R1_FB26_Msk                    (0x1UL << CAN_F6R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F6R1_FB26                        CAN_F6R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F6R1_FB27_Pos                    (27U)                             
#define CAN_F6R1_FB27_Msk                    (0x1UL << CAN_F6R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F6R1_FB27                        CAN_F6R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F6R1_FB28_Pos                    (28U)                             
#define CAN_F6R1_FB28_Msk                    (0x1UL << CAN_F6R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F6R1_FB28                        CAN_F6R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F6R1_FB29_Pos                    (29U)                             
#define CAN_F6R1_FB29_Msk                    (0x1UL << CAN_F6R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F6R1_FB29                        CAN_F6R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F6R1_FB30_Pos                    (30U)                             
#define CAN_F6R1_FB30_Msk                    (0x1UL << CAN_F6R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F6R1_FB30                        CAN_F6R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F6R1_FB31_Pos                    (31U)                             
#define CAN_F6R1_FB31_Msk                    (0x1UL << CAN_F6R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F6R1_FB31                        CAN_F6R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define CAN_F7R1_FB0_Pos                     (0U)                              
#define CAN_F7R1_FB0_Msk                     (0x1UL << CAN_F7R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F7R1_FB0                         CAN_F7R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F7R1_FB1_Pos                     (1U)                              
#define CAN_F7R1_FB1_Msk                     (0x1UL << CAN_F7R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F7R1_FB1                         CAN_F7R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F7R1_FB2_Pos                     (2U)                              
#define CAN_F7R1_FB2_Msk                     (0x1UL << CAN_F7R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F7R1_FB2                         CAN_F7R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F7R1_FB3_Pos                     (3U)                              
#define CAN_F7R1_FB3_Msk                     (0x1UL << CAN_F7R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F7R1_FB3                         CAN_F7R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F7R1_FB4_Pos                     (4U)                              
#define CAN_F7R1_FB4_Msk                     (0x1UL << CAN_F7R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F7R1_FB4                         CAN_F7R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F7R1_FB5_Pos                     (5U)                              
#define CAN_F7R1_FB5_Msk                     (0x1UL << CAN_F7R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F7R1_FB5                         CAN_F7R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F7R1_FB6_Pos                     (6U)                              
#define CAN_F7R1_FB6_Msk                     (0x1UL << CAN_F7R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F7R1_FB6                         CAN_F7R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F7R1_FB7_Pos                     (7U)                              
#define CAN_F7R1_FB7_Msk                     (0x1UL << CAN_F7R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F7R1_FB7                         CAN_F7R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F7R1_FB8_Pos                     (8U)                              
#define CAN_F7R1_FB8_Msk                     (0x1UL << CAN_F7R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F7R1_FB8                         CAN_F7R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F7R1_FB9_Pos                     (9U)                              
#define CAN_F7R1_FB9_Msk                     (0x1UL << CAN_F7R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F7R1_FB9                         CAN_F7R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F7R1_FB10_Pos                    (10U)                             
#define CAN_F7R1_FB10_Msk                    (0x1UL << CAN_F7R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F7R1_FB10                        CAN_F7R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F7R1_FB11_Pos                    (11U)                             
#define CAN_F7R1_FB11_Msk                    (0x1UL << CAN_F7R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F7R1_FB11                        CAN_F7R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F7R1_FB12_Pos                    (12U)                             
#define CAN_F7R1_FB12_Msk                    (0x1UL << CAN_F7R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F7R1_FB12                        CAN_F7R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F7R1_FB13_Pos                    (13U)                             
#define CAN_F7R1_FB13_Msk                    (0x1UL << CAN_F7R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F7R1_FB13                        CAN_F7R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F7R1_FB14_Pos                    (14U)                             
#define CAN_F7R1_FB14_Msk                    (0x1UL << CAN_F7R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F7R1_FB14                        CAN_F7R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F7R1_FB15_Pos                    (15U)                             
#define CAN_F7R1_FB15_Msk                    (0x1UL << CAN_F7R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F7R1_FB15                        CAN_F7R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F7R1_FB16_Pos                    (16U)                             
#define CAN_F7R1_FB16_Msk                    (0x1UL << CAN_F7R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F7R1_FB16                        CAN_F7R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F7R1_FB17_Pos                    (17U)                             
#define CAN_F7R1_FB17_Msk                    (0x1UL << CAN_F7R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F7R1_FB17                        CAN_F7R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F7R1_FB18_Pos                    (18U)                             
#define CAN_F7R1_FB18_Msk                    (0x1UL << CAN_F7R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F7R1_FB18                        CAN_F7R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F7R1_FB19_Pos                    (19U)                             
#define CAN_F7R1_FB19_Msk                    (0x1UL << CAN_F7R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F7R1_FB19                        CAN_F7R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F7R1_FB20_Pos                    (20U)                             
#define CAN_F7R1_FB20_Msk                    (0x1UL << CAN_F7R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F7R1_FB20                        CAN_F7R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F7R1_FB21_Pos                    (21U)                             
#define CAN_F7R1_FB21_Msk                    (0x1UL << CAN_F7R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F7R1_FB21                        CAN_F7R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F7R1_FB22_Pos                    (22U)                             
#define CAN_F7R1_FB22_Msk                    (0x1UL << CAN_F7R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F7R1_FB22                        CAN_F7R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F7R1_FB23_Pos                    (23U)                             
#define CAN_F7R1_FB23_Msk                    (0x1UL << CAN_F7R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F7R1_FB23                        CAN_F7R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F7R1_FB24_Pos                    (24U)                             
#define CAN_F7R1_FB24_Msk                    (0x1UL << CAN_F7R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F7R1_FB24                        CAN_F7R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F7R1_FB25_Pos                    (25U)                             
#define CAN_F7R1_FB25_Msk                    (0x1UL << CAN_F7R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F7R1_FB25                        CAN_F7R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F7R1_FB26_Pos                    (26U)                             
#define CAN_F7R1_FB26_Msk                    (0x1UL << CAN_F7R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F7R1_FB26                        CAN_F7R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F7R1_FB27_Pos                    (27U)                             
#define CAN_F7R1_FB27_Msk                    (0x1UL << CAN_F7R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F7R1_FB27                        CAN_F7R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F7R1_FB28_Pos                    (28U)                             
#define CAN_F7R1_FB28_Msk                    (0x1UL << CAN_F7R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F7R1_FB28                        CAN_F7R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F7R1_FB29_Pos                    (29U)                             
#define CAN_F7R1_FB29_Msk                    (0x1UL << CAN_F7R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F7R1_FB29                        CAN_F7R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F7R1_FB30_Pos                    (30U)                             
#define CAN_F7R1_FB30_Msk                    (0x1UL << CAN_F7R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F7R1_FB30                        CAN_F7R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F7R1_FB31_Pos                    (31U)                             
#define CAN_F7R1_FB31_Msk                    (0x1UL << CAN_F7R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F7R1_FB31                        CAN_F7R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define CAN_F8R1_FB0_Pos                     (0U)                              
#define CAN_F8R1_FB0_Msk                     (0x1UL << CAN_F8R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F8R1_FB0                         CAN_F8R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F8R1_FB1_Pos                     (1U)                              
#define CAN_F8R1_FB1_Msk                     (0x1UL << CAN_F8R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F8R1_FB1                         CAN_F8R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F8R1_FB2_Pos                     (2U)                              
#define CAN_F8R1_FB2_Msk                     (0x1UL << CAN_F8R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F8R1_FB2                         CAN_F8R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F8R1_FB3_Pos                     (3U)                              
#define CAN_F8R1_FB3_Msk                     (0x1UL << CAN_F8R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F8R1_FB3                         CAN_F8R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F8R1_FB4_Pos                     (4U)                              
#define CAN_F8R1_FB4_Msk                     (0x1UL << CAN_F8R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F8R1_FB4                         CAN_F8R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F8R1_FB5_Pos                     (5U)                              
#define CAN_F8R1_FB5_Msk                     (0x1UL << CAN_F8R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F8R1_FB5                         CAN_F8R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F8R1_FB6_Pos                     (6U)                              
#define CAN_F8R1_FB6_Msk                     (0x1UL << CAN_F8R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F8R1_FB6                         CAN_F8R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F8R1_FB7_Pos                     (7U)                              
#define CAN_F8R1_FB7_Msk                     (0x1UL << CAN_F8R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F8R1_FB7                         CAN_F8R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F8R1_FB8_Pos                     (8U)                              
#define CAN_F8R1_FB8_Msk                     (0x1UL << CAN_F8R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F8R1_FB8                         CAN_F8R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F8R1_FB9_Pos                     (9U)                              
#define CAN_F8R1_FB9_Msk                     (0x1UL << CAN_F8R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F8R1_FB9                         CAN_F8R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F8R1_FB10_Pos                    (10U)                             
#define CAN_F8R1_FB10_Msk                    (0x1UL << CAN_F8R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F8R1_FB10                        CAN_F8R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F8R1_FB11_Pos                    (11U)                             
#define CAN_F8R1_FB11_Msk                    (0x1UL << CAN_F8R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F8R1_FB11                        CAN_F8R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F8R1_FB12_Pos                    (12U)                             
#define CAN_F8R1_FB12_Msk                    (0x1UL << CAN_F8R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F8R1_FB12                        CAN_F8R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F8R1_FB13_Pos                    (13U)                             
#define CAN_F8R1_FB13_Msk                    (0x1UL << CAN_F8R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F8R1_FB13                        CAN_F8R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F8R1_FB14_Pos                    (14U)                             
#define CAN_F8R1_FB14_Msk                    (0x1UL << CAN_F8R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F8R1_FB14                        CAN_F8R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F8R1_FB15_Pos                    (15U)                             
#define CAN_F8R1_FB15_Msk                    (0x1UL << CAN_F8R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F8R1_FB15                        CAN_F8R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F8R1_FB16_Pos                    (16U)                             
#define CAN_F8R1_FB16_Msk                    (0x1UL << CAN_F8R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F8R1_FB16                        CAN_F8R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F8R1_FB17_Pos                    (17U)                             
#define CAN_F8R1_FB17_Msk                    (0x1UL << CAN_F8R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F8R1_FB17                        CAN_F8R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F8R1_FB18_Pos                    (18U)                             
#define CAN_F8R1_FB18_Msk                    (0x1UL << CAN_F8R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F8R1_FB18                        CAN_F8R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F8R1_FB19_Pos                    (19U)                             
#define CAN_F8R1_FB19_Msk                    (0x1UL << CAN_F8R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F8R1_FB19                        CAN_F8R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F8R1_FB20_Pos                    (20U)                             
#define CAN_F8R1_FB20_Msk                    (0x1UL << CAN_F8R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F8R1_FB20                        CAN_F8R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F8R1_FB21_Pos                    (21U)                             
#define CAN_F8R1_FB21_Msk                    (0x1UL << CAN_F8R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F8R1_FB21                        CAN_F8R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F8R1_FB22_Pos                    (22U)                             
#define CAN_F8R1_FB22_Msk                    (0x1UL << CAN_F8R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F8R1_FB22                        CAN_F8R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F8R1_FB23_Pos                    (23U)                             
#define CAN_F8R1_FB23_Msk                    (0x1UL << CAN_F8R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F8R1_FB23                        CAN_F8R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F8R1_FB24_Pos                    (24U)                             
#define CAN_F8R1_FB24_Msk                    (0x1UL << CAN_F8R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F8R1_FB24                        CAN_F8R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F8R1_FB25_Pos                    (25U)                             
#define CAN_F8R1_FB25_Msk                    (0x1UL << CAN_F8R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F8R1_FB25                        CAN_F8R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F8R1_FB26_Pos                    (26U)                             
#define CAN_F8R1_FB26_Msk                    (0x1UL << CAN_F8R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F8R1_FB26                        CAN_F8R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F8R1_FB27_Pos                    (27U)                             
#define CAN_F8R1_FB27_Msk                    (0x1UL << CAN_F8R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F8R1_FB27                        CAN_F8R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F8R1_FB28_Pos                    (28U)                             
#define CAN_F8R1_FB28_Msk                    (0x1UL << CAN_F8R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F8R1_FB28                        CAN_F8R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F8R1_FB29_Pos                    (29U)                             
#define CAN_F8R1_FB29_Msk                    (0x1UL << CAN_F8R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F8R1_FB29                        CAN_F8R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F8R1_FB30_Pos                    (30U)                             
#define CAN_F8R1_FB30_Msk                    (0x1UL << CAN_F8R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F8R1_FB30                        CAN_F8R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F8R1_FB31_Pos                    (31U)                             
#define CAN_F8R1_FB31_Msk                    (0x1UL << CAN_F8R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F8R1_FB31                        CAN_F8R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define CAN_F9R1_FB0_Pos                     (0U)                              
#define CAN_F9R1_FB0_Msk                     (0x1UL << CAN_F9R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F9R1_FB0                         CAN_F9R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F9R1_FB1_Pos                     (1U)                              
#define CAN_F9R1_FB1_Msk                     (0x1UL << CAN_F9R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F9R1_FB1                         CAN_F9R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F9R1_FB2_Pos                     (2U)                              
#define CAN_F9R1_FB2_Msk                     (0x1UL << CAN_F9R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F9R1_FB2                         CAN_F9R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F9R1_FB3_Pos                     (3U)                              
#define CAN_F9R1_FB3_Msk                     (0x1UL << CAN_F9R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F9R1_FB3                         CAN_F9R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F9R1_FB4_Pos                     (4U)                              
#define CAN_F9R1_FB4_Msk                     (0x1UL << CAN_F9R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F9R1_FB4                         CAN_F9R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F9R1_FB5_Pos                     (5U)                              
#define CAN_F9R1_FB5_Msk                     (0x1UL << CAN_F9R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F9R1_FB5                         CAN_F9R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F9R1_FB6_Pos                     (6U)                              
#define CAN_F9R1_FB6_Msk                     (0x1UL << CAN_F9R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F9R1_FB6                         CAN_F9R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F9R1_FB7_Pos                     (7U)                              
#define CAN_F9R1_FB7_Msk                     (0x1UL << CAN_F9R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F9R1_FB7                         CAN_F9R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F9R1_FB8_Pos                     (8U)                              
#define CAN_F9R1_FB8_Msk                     (0x1UL << CAN_F9R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F9R1_FB8                         CAN_F9R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F9R1_FB9_Pos                     (9U)                              
#define CAN_F9R1_FB9_Msk                     (0x1UL << CAN_F9R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F9R1_FB9                         CAN_F9R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F9R1_FB10_Pos                    (10U)                             
#define CAN_F9R1_FB10_Msk                    (0x1UL << CAN_F9R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F9R1_FB10                        CAN_F9R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F9R1_FB11_Pos                    (11U)                             
#define CAN_F9R1_FB11_Msk                    (0x1UL << CAN_F9R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F9R1_FB11                        CAN_F9R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F9R1_FB12_Pos                    (12U)                             
#define CAN_F9R1_FB12_Msk                    (0x1UL << CAN_F9R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F9R1_FB12                        CAN_F9R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F9R1_FB13_Pos                    (13U)                             
#define CAN_F9R1_FB13_Msk                    (0x1UL << CAN_F9R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F9R1_FB13                        CAN_F9R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F9R1_FB14_Pos                    (14U)                             
#define CAN_F9R1_FB14_Msk                    (0x1UL << CAN_F9R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F9R1_FB14                        CAN_F9R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F9R1_FB15_Pos                    (15U)                             
#define CAN_F9R1_FB15_Msk                    (0x1UL << CAN_F9R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F9R1_FB15                        CAN_F9R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F9R1_FB16_Pos                    (16U)                             
#define CAN_F9R1_FB16_Msk                    (0x1UL << CAN_F9R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F9R1_FB16                        CAN_F9R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F9R1_FB17_Pos                    (17U)                             
#define CAN_F9R1_FB17_Msk                    (0x1UL << CAN_F9R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F9R1_FB17                        CAN_F9R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F9R1_FB18_Pos                    (18U)                             
#define CAN_F9R1_FB18_Msk                    (0x1UL << CAN_F9R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F9R1_FB18                        CAN_F9R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F9R1_FB19_Pos                    (19U)                             
#define CAN_F9R1_FB19_Msk                    (0x1UL << CAN_F9R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F9R1_FB19                        CAN_F9R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F9R1_FB20_Pos                    (20U)                             
#define CAN_F9R1_FB20_Msk                    (0x1UL << CAN_F9R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F9R1_FB20                        CAN_F9R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F9R1_FB21_Pos                    (21U)                             
#define CAN_F9R1_FB21_Msk                    (0x1UL << CAN_F9R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F9R1_FB21                        CAN_F9R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F9R1_FB22_Pos                    (22U)                             
#define CAN_F9R1_FB22_Msk                    (0x1UL << CAN_F9R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F9R1_FB22                        CAN_F9R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F9R1_FB23_Pos                    (23U)                             
#define CAN_F9R1_FB23_Msk                    (0x1UL << CAN_F9R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F9R1_FB23                        CAN_F9R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F9R1_FB24_Pos                    (24U)                             
#define CAN_F9R1_FB24_Msk                    (0x1UL << CAN_F9R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F9R1_FB24                        CAN_F9R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F9R1_FB25_Pos                    (25U)                             
#define CAN_F9R1_FB25_Msk                    (0x1UL << CAN_F9R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F9R1_FB25                        CAN_F9R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F9R1_FB26_Pos                    (26U)                             
#define CAN_F9R1_FB26_Msk                    (0x1UL << CAN_F9R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F9R1_FB26                        CAN_F9R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F9R1_FB27_Pos                    (27U)                             
#define CAN_F9R1_FB27_Msk                    (0x1UL << CAN_F9R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F9R1_FB27                        CAN_F9R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F9R1_FB28_Pos                    (28U)                             
#define CAN_F9R1_FB28_Msk                    (0x1UL << CAN_F9R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F9R1_FB28                        CAN_F9R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F9R1_FB29_Pos                    (29U)                             
#define CAN_F9R1_FB29_Msk                    (0x1UL << CAN_F9R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F9R1_FB29                        CAN_F9R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F9R1_FB30_Pos                    (30U)                             
#define CAN_F9R1_FB30_Msk                    (0x1UL << CAN_F9R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F9R1_FB30                        CAN_F9R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F9R1_FB31_Pos                    (31U)                             
#define CAN_F9R1_FB31_Msk                    (0x1UL << CAN_F9R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F9R1_FB31                        CAN_F9R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define CAN_F10R1_FB0_Pos                    (0U)                              
#define CAN_F10R1_FB0_Msk                    (0x1UL << CAN_F10R1_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F10R1_FB0                        CAN_F10R1_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F10R1_FB1_Pos                    (1U)                              
#define CAN_F10R1_FB1_Msk                    (0x1UL << CAN_F10R1_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F10R1_FB1                        CAN_F10R1_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F10R1_FB2_Pos                    (2U)                              
#define CAN_F10R1_FB2_Msk                    (0x1UL << CAN_F10R1_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F10R1_FB2                        CAN_F10R1_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F10R1_FB3_Pos                    (3U)                              
#define CAN_F10R1_FB3_Msk                    (0x1UL << CAN_F10R1_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F10R1_FB3                        CAN_F10R1_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F10R1_FB4_Pos                    (4U)                              
#define CAN_F10R1_FB4_Msk                    (0x1UL << CAN_F10R1_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F10R1_FB4                        CAN_F10R1_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F10R1_FB5_Pos                    (5U)                              
#define CAN_F10R1_FB5_Msk                    (0x1UL << CAN_F10R1_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F10R1_FB5                        CAN_F10R1_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F10R1_FB6_Pos                    (6U)                              
#define CAN_F10R1_FB6_Msk                    (0x1UL << CAN_F10R1_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F10R1_FB6                        CAN_F10R1_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F10R1_FB7_Pos                    (7U)                              
#define CAN_F10R1_FB7_Msk                    (0x1UL << CAN_F10R1_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F10R1_FB7                        CAN_F10R1_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F10R1_FB8_Pos                    (8U)                              
#define CAN_F10R1_FB8_Msk                    (0x1UL << CAN_F10R1_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F10R1_FB8                        CAN_F10R1_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F10R1_FB9_Pos                    (9U)                              
#define CAN_F10R1_FB9_Msk                    (0x1UL << CAN_F10R1_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F10R1_FB9                        CAN_F10R1_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F10R1_FB10_Pos                   (10U)                             
#define CAN_F10R1_FB10_Msk                   (0x1UL << CAN_F10R1_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F10R1_FB10                       CAN_F10R1_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F10R1_FB11_Pos                   (11U)                             
#define CAN_F10R1_FB11_Msk                   (0x1UL << CAN_F10R1_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F10R1_FB11                       CAN_F10R1_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F10R1_FB12_Pos                   (12U)                             
#define CAN_F10R1_FB12_Msk                   (0x1UL << CAN_F10R1_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F10R1_FB12                       CAN_F10R1_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F10R1_FB13_Pos                   (13U)                             
#define CAN_F10R1_FB13_Msk                   (0x1UL << CAN_F10R1_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F10R1_FB13                       CAN_F10R1_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F10R1_FB14_Pos                   (14U)                             
#define CAN_F10R1_FB14_Msk                   (0x1UL << CAN_F10R1_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F10R1_FB14                       CAN_F10R1_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F10R1_FB15_Pos                   (15U)                             
#define CAN_F10R1_FB15_Msk                   (0x1UL << CAN_F10R1_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F10R1_FB15                       CAN_F10R1_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F10R1_FB16_Pos                   (16U)                             
#define CAN_F10R1_FB16_Msk                   (0x1UL << CAN_F10R1_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F10R1_FB16                       CAN_F10R1_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F10R1_FB17_Pos                   (17U)                             
#define CAN_F10R1_FB17_Msk                   (0x1UL << CAN_F10R1_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F10R1_FB17                       CAN_F10R1_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F10R1_FB18_Pos                   (18U)                             
#define CAN_F10R1_FB18_Msk                   (0x1UL << CAN_F10R1_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F10R1_FB18                       CAN_F10R1_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F10R1_FB19_Pos                   (19U)                             
#define CAN_F10R1_FB19_Msk                   (0x1UL << CAN_F10R1_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F10R1_FB19                       CAN_F10R1_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F10R1_FB20_Pos                   (20U)                             
#define CAN_F10R1_FB20_Msk                   (0x1UL << CAN_F10R1_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F10R1_FB20                       CAN_F10R1_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F10R1_FB21_Pos                   (21U)                             
#define CAN_F10R1_FB21_Msk                   (0x1UL << CAN_F10R1_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F10R1_FB21                       CAN_F10R1_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F10R1_FB22_Pos                   (22U)                             
#define CAN_F10R1_FB22_Msk                   (0x1UL << CAN_F10R1_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F10R1_FB22                       CAN_F10R1_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F10R1_FB23_Pos                   (23U)                             
#define CAN_F10R1_FB23_Msk                   (0x1UL << CAN_F10R1_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F10R1_FB23                       CAN_F10R1_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F10R1_FB24_Pos                   (24U)                             
#define CAN_F10R1_FB24_Msk                   (0x1UL << CAN_F10R1_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F10R1_FB24                       CAN_F10R1_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F10R1_FB25_Pos                   (25U)                             
#define CAN_F10R1_FB25_Msk                   (0x1UL << CAN_F10R1_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F10R1_FB25                       CAN_F10R1_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F10R1_FB26_Pos                   (26U)                             
#define CAN_F10R1_FB26_Msk                   (0x1UL << CAN_F10R1_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F10R1_FB26                       CAN_F10R1_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F10R1_FB27_Pos                   (27U)                             
#define CAN_F10R1_FB27_Msk                   (0x1UL << CAN_F10R1_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F10R1_FB27                       CAN_F10R1_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F10R1_FB28_Pos                   (28U)                             
#define CAN_F10R1_FB28_Msk                   (0x1UL << CAN_F10R1_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F10R1_FB28                       CAN_F10R1_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F10R1_FB29_Pos                   (29U)                             
#define CAN_F10R1_FB29_Msk                   (0x1UL << CAN_F10R1_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F10R1_FB29                       CAN_F10R1_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F10R1_FB30_Pos                   (30U)                             
#define CAN_F10R1_FB30_Msk                   (0x1UL << CAN_F10R1_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F10R1_FB30                       CAN_F10R1_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F10R1_FB31_Pos                   (31U)                             
#define CAN_F10R1_FB31_Msk                   (0x1UL << CAN_F10R1_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F10R1_FB31                       CAN_F10R1_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define CAN_F11R1_FB0_Pos                    (0U)                              
#define CAN_F11R1_FB0_Msk                    (0x1UL << CAN_F11R1_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F11R1_FB0                        CAN_F11R1_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F11R1_FB1_Pos                    (1U)                              
#define CAN_F11R1_FB1_Msk                    (0x1UL << CAN_F11R1_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F11R1_FB1                        CAN_F11R1_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F11R1_FB2_Pos                    (2U)                              
#define CAN_F11R1_FB2_Msk                    (0x1UL << CAN_F11R1_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F11R1_FB2                        CAN_F11R1_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F11R1_FB3_Pos                    (3U)                              
#define CAN_F11R1_FB3_Msk                    (0x1UL << CAN_F11R1_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F11R1_FB3                        CAN_F11R1_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F11R1_FB4_Pos                    (4U)                              
#define CAN_F11R1_FB4_Msk                    (0x1UL << CAN_F11R1_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F11R1_FB4                        CAN_F11R1_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F11R1_FB5_Pos                    (5U)                              
#define CAN_F11R1_FB5_Msk                    (0x1UL << CAN_F11R1_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F11R1_FB5                        CAN_F11R1_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F11R1_FB6_Pos                    (6U)                              
#define CAN_F11R1_FB6_Msk                    (0x1UL << CAN_F11R1_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F11R1_FB6                        CAN_F11R1_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F11R1_FB7_Pos                    (7U)                              
#define CAN_F11R1_FB7_Msk                    (0x1UL << CAN_F11R1_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F11R1_FB7                        CAN_F11R1_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F11R1_FB8_Pos                    (8U)                              
#define CAN_F11R1_FB8_Msk                    (0x1UL << CAN_F11R1_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F11R1_FB8                        CAN_F11R1_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F11R1_FB9_Pos                    (9U)                              
#define CAN_F11R1_FB9_Msk                    (0x1UL << CAN_F11R1_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F11R1_FB9                        CAN_F11R1_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F11R1_FB10_Pos                   (10U)                             
#define CAN_F11R1_FB10_Msk                   (0x1UL << CAN_F11R1_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F11R1_FB10                       CAN_F11R1_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F11R1_FB11_Pos                   (11U)                             
#define CAN_F11R1_FB11_Msk                   (0x1UL << CAN_F11R1_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F11R1_FB11                       CAN_F11R1_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F11R1_FB12_Pos                   (12U)                             
#define CAN_F11R1_FB12_Msk                   (0x1UL << CAN_F11R1_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F11R1_FB12                       CAN_F11R1_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F11R1_FB13_Pos                   (13U)                             
#define CAN_F11R1_FB13_Msk                   (0x1UL << CAN_F11R1_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F11R1_FB13                       CAN_F11R1_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F11R1_FB14_Pos                   (14U)                             
#define CAN_F11R1_FB14_Msk                   (0x1UL << CAN_F11R1_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F11R1_FB14                       CAN_F11R1_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F11R1_FB15_Pos                   (15U)                             
#define CAN_F11R1_FB15_Msk                   (0x1UL << CAN_F11R1_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F11R1_FB15                       CAN_F11R1_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F11R1_FB16_Pos                   (16U)                             
#define CAN_F11R1_FB16_Msk                   (0x1UL << CAN_F11R1_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F11R1_FB16                       CAN_F11R1_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F11R1_FB17_Pos                   (17U)                             
#define CAN_F11R1_FB17_Msk                   (0x1UL << CAN_F11R1_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F11R1_FB17                       CAN_F11R1_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F11R1_FB18_Pos                   (18U)                             
#define CAN_F11R1_FB18_Msk                   (0x1UL << CAN_F11R1_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F11R1_FB18                       CAN_F11R1_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F11R1_FB19_Pos                   (19U)                             
#define CAN_F11R1_FB19_Msk                   (0x1UL << CAN_F11R1_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F11R1_FB19                       CAN_F11R1_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F11R1_FB20_Pos                   (20U)                             
#define CAN_F11R1_FB20_Msk                   (0x1UL << CAN_F11R1_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F11R1_FB20                       CAN_F11R1_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F11R1_FB21_Pos                   (21U)                             
#define CAN_F11R1_FB21_Msk                   (0x1UL << CAN_F11R1_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F11R1_FB21                       CAN_F11R1_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F11R1_FB22_Pos                   (22U)                             
#define CAN_F11R1_FB22_Msk                   (0x1UL << CAN_F11R1_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F11R1_FB22                       CAN_F11R1_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F11R1_FB23_Pos                   (23U)                             
#define CAN_F11R1_FB23_Msk                   (0x1UL << CAN_F11R1_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F11R1_FB23                       CAN_F11R1_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F11R1_FB24_Pos                   (24U)                             
#define CAN_F11R1_FB24_Msk                   (0x1UL << CAN_F11R1_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F11R1_FB24                       CAN_F11R1_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F11R1_FB25_Pos                   (25U)                             
#define CAN_F11R1_FB25_Msk                   (0x1UL << CAN_F11R1_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F11R1_FB25                       CAN_F11R1_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F11R1_FB26_Pos                   (26U)                             
#define CAN_F11R1_FB26_Msk                   (0x1UL << CAN_F11R1_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F11R1_FB26                       CAN_F11R1_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F11R1_FB27_Pos                   (27U)                             
#define CAN_F11R1_FB27_Msk                   (0x1UL << CAN_F11R1_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F11R1_FB27                       CAN_F11R1_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F11R1_FB28_Pos                   (28U)                             
#define CAN_F11R1_FB28_Msk                   (0x1UL << CAN_F11R1_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F11R1_FB28                       CAN_F11R1_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F11R1_FB29_Pos                   (29U)                             
#define CAN_F11R1_FB29_Msk                   (0x1UL << CAN_F11R1_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F11R1_FB29                       CAN_F11R1_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F11R1_FB30_Pos                   (30U)                             
#define CAN_F11R1_FB30_Msk                   (0x1UL << CAN_F11R1_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F11R1_FB30                       CAN_F11R1_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F11R1_FB31_Pos                   (31U)                             
#define CAN_F11R1_FB31_Msk                   (0x1UL << CAN_F11R1_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F11R1_FB31                       CAN_F11R1_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define CAN_F12R1_FB0_Pos                    (0U)                              
#define CAN_F12R1_FB0_Msk                    (0x1UL << CAN_F12R1_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F12R1_FB0                        CAN_F12R1_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F12R1_FB1_Pos                    (1U)                              
#define CAN_F12R1_FB1_Msk                    (0x1UL << CAN_F12R1_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F12R1_FB1                        CAN_F12R1_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F12R1_FB2_Pos                    (2U)                              
#define CAN_F12R1_FB2_Msk                    (0x1UL << CAN_F12R1_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F12R1_FB2                        CAN_F12R1_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F12R1_FB3_Pos                    (3U)                              
#define CAN_F12R1_FB3_Msk                    (0x1UL << CAN_F12R1_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F12R1_FB3                        CAN_F12R1_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F12R1_FB4_Pos                    (4U)                              
#define CAN_F12R1_FB4_Msk                    (0x1UL << CAN_F12R1_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F12R1_FB4                        CAN_F12R1_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F12R1_FB5_Pos                    (5U)                              
#define CAN_F12R1_FB5_Msk                    (0x1UL << CAN_F12R1_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F12R1_FB5                        CAN_F12R1_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F12R1_FB6_Pos                    (6U)                              
#define CAN_F12R1_FB6_Msk                    (0x1UL << CAN_F12R1_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F12R1_FB6                        CAN_F12R1_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F12R1_FB7_Pos                    (7U)                              
#define CAN_F12R1_FB7_Msk                    (0x1UL << CAN_F12R1_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F12R1_FB7                        CAN_F12R1_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F12R1_FB8_Pos                    (8U)                              
#define CAN_F12R1_FB8_Msk                    (0x1UL << CAN_F12R1_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F12R1_FB8                        CAN_F12R1_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F12R1_FB9_Pos                    (9U)                              
#define CAN_F12R1_FB9_Msk                    (0x1UL << CAN_F12R1_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F12R1_FB9                        CAN_F12R1_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F12R1_FB10_Pos                   (10U)                             
#define CAN_F12R1_FB10_Msk                   (0x1UL << CAN_F12R1_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F12R1_FB10                       CAN_F12R1_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F12R1_FB11_Pos                   (11U)                             
#define CAN_F12R1_FB11_Msk                   (0x1UL << CAN_F12R1_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F12R1_FB11                       CAN_F12R1_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F12R1_FB12_Pos                   (12U)                             
#define CAN_F12R1_FB12_Msk                   (0x1UL << CAN_F12R1_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F12R1_FB12                       CAN_F12R1_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F12R1_FB13_Pos                   (13U)                             
#define CAN_F12R1_FB13_Msk                   (0x1UL << CAN_F12R1_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F12R1_FB13                       CAN_F12R1_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F12R1_FB14_Pos                   (14U)                             
#define CAN_F12R1_FB14_Msk                   (0x1UL << CAN_F12R1_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F12R1_FB14                       CAN_F12R1_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F12R1_FB15_Pos                   (15U)                             
#define CAN_F12R1_FB15_Msk                   (0x1UL << CAN_F12R1_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F12R1_FB15                       CAN_F12R1_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F12R1_FB16_Pos                   (16U)                             
#define CAN_F12R1_FB16_Msk                   (0x1UL << CAN_F12R1_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F12R1_FB16                       CAN_F12R1_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F12R1_FB17_Pos                   (17U)                             
#define CAN_F12R1_FB17_Msk                   (0x1UL << CAN_F12R1_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F12R1_FB17                       CAN_F12R1_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F12R1_FB18_Pos                   (18U)                             
#define CAN_F12R1_FB18_Msk                   (0x1UL << CAN_F12R1_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F12R1_FB18                       CAN_F12R1_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F12R1_FB19_Pos                   (19U)                             
#define CAN_F12R1_FB19_Msk                   (0x1UL << CAN_F12R1_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F12R1_FB19                       CAN_F12R1_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F12R1_FB20_Pos                   (20U)                             
#define CAN_F12R1_FB20_Msk                   (0x1UL << CAN_F12R1_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F12R1_FB20                       CAN_F12R1_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F12R1_FB21_Pos                   (21U)                             
#define CAN_F12R1_FB21_Msk                   (0x1UL << CAN_F12R1_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F12R1_FB21                       CAN_F12R1_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F12R1_FB22_Pos                   (22U)                             
#define CAN_F12R1_FB22_Msk                   (0x1UL << CAN_F12R1_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F12R1_FB22                       CAN_F12R1_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F12R1_FB23_Pos                   (23U)                             
#define CAN_F12R1_FB23_Msk                   (0x1UL << CAN_F12R1_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F12R1_FB23                       CAN_F12R1_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F12R1_FB24_Pos                   (24U)                             
#define CAN_F12R1_FB24_Msk                   (0x1UL << CAN_F12R1_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F12R1_FB24                       CAN_F12R1_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F12R1_FB25_Pos                   (25U)                             
#define CAN_F12R1_FB25_Msk                   (0x1UL << CAN_F12R1_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F12R1_FB25                       CAN_F12R1_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F12R1_FB26_Pos                   (26U)                             
#define CAN_F12R1_FB26_Msk                   (0x1UL << CAN_F12R1_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F12R1_FB26                       CAN_F12R1_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F12R1_FB27_Pos                   (27U)                             
#define CAN_F12R1_FB27_Msk                   (0x1UL << CAN_F12R1_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F12R1_FB27                       CAN_F12R1_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F12R1_FB28_Pos                   (28U)                             
#define CAN_F12R1_FB28_Msk                   (0x1UL << CAN_F12R1_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F12R1_FB28                       CAN_F12R1_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F12R1_FB29_Pos                   (29U)                             
#define CAN_F12R1_FB29_Msk                   (0x1UL << CAN_F12R1_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F12R1_FB29                       CAN_F12R1_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F12R1_FB30_Pos                   (30U)                             
#define CAN_F12R1_FB30_Msk                   (0x1UL << CAN_F12R1_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F12R1_FB30                       CAN_F12R1_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F12R1_FB31_Pos                   (31U)                             
#define CAN_F12R1_FB31_Msk                   (0x1UL << CAN_F12R1_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F12R1_FB31                       CAN_F12R1_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define CAN_F13R1_FB0_Pos                    (0U)                              
#define CAN_F13R1_FB0_Msk                    (0x1UL << CAN_F13R1_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F13R1_FB0                        CAN_F13R1_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F13R1_FB1_Pos                    (1U)                              
#define CAN_F13R1_FB1_Msk                    (0x1UL << CAN_F13R1_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F13R1_FB1                        CAN_F13R1_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F13R1_FB2_Pos                    (2U)                              
#define CAN_F13R1_FB2_Msk                    (0x1UL << CAN_F13R1_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F13R1_FB2                        CAN_F13R1_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F13R1_FB3_Pos                    (3U)                              
#define CAN_F13R1_FB3_Msk                    (0x1UL << CAN_F13R1_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F13R1_FB3                        CAN_F13R1_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F13R1_FB4_Pos                    (4U)                              
#define CAN_F13R1_FB4_Msk                    (0x1UL << CAN_F13R1_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F13R1_FB4                        CAN_F13R1_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F13R1_FB5_Pos                    (5U)                              
#define CAN_F13R1_FB5_Msk                    (0x1UL << CAN_F13R1_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F13R1_FB5                        CAN_F13R1_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F13R1_FB6_Pos                    (6U)                              
#define CAN_F13R1_FB6_Msk                    (0x1UL << CAN_F13R1_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F13R1_FB6                        CAN_F13R1_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F13R1_FB7_Pos                    (7U)                              
#define CAN_F13R1_FB7_Msk                    (0x1UL << CAN_F13R1_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F13R1_FB7                        CAN_F13R1_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F13R1_FB8_Pos                    (8U)                              
#define CAN_F13R1_FB8_Msk                    (0x1UL << CAN_F13R1_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F13R1_FB8                        CAN_F13R1_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F13R1_FB9_Pos                    (9U)                              
#define CAN_F13R1_FB9_Msk                    (0x1UL << CAN_F13R1_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F13R1_FB9                        CAN_F13R1_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F13R1_FB10_Pos                   (10U)                             
#define CAN_F13R1_FB10_Msk                   (0x1UL << CAN_F13R1_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F13R1_FB10                       CAN_F13R1_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F13R1_FB11_Pos                   (11U)                             
#define CAN_F13R1_FB11_Msk                   (0x1UL << CAN_F13R1_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F13R1_FB11                       CAN_F13R1_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F13R1_FB12_Pos                   (12U)                             
#define CAN_F13R1_FB12_Msk                   (0x1UL << CAN_F13R1_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F13R1_FB12                       CAN_F13R1_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F13R1_FB13_Pos                   (13U)                             
#define CAN_F13R1_FB13_Msk                   (0x1UL << CAN_F13R1_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F13R1_FB13                       CAN_F13R1_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F13R1_FB14_Pos                   (14U)                             
#define CAN_F13R1_FB14_Msk                   (0x1UL << CAN_F13R1_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F13R1_FB14                       CAN_F13R1_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F13R1_FB15_Pos                   (15U)                             
#define CAN_F13R1_FB15_Msk                   (0x1UL << CAN_F13R1_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F13R1_FB15                       CAN_F13R1_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F13R1_FB16_Pos                   (16U)                             
#define CAN_F13R1_FB16_Msk                   (0x1UL << CAN_F13R1_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F13R1_FB16                       CAN_F13R1_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F13R1_FB17_Pos                   (17U)                             
#define CAN_F13R1_FB17_Msk                   (0x1UL << CAN_F13R1_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F13R1_FB17                       CAN_F13R1_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F13R1_FB18_Pos                   (18U)                             
#define CAN_F13R1_FB18_Msk                   (0x1UL << CAN_F13R1_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F13R1_FB18                       CAN_F13R1_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F13R1_FB19_Pos                   (19U)                             
#define CAN_F13R1_FB19_Msk                   (0x1UL << CAN_F13R1_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F13R1_FB19                       CAN_F13R1_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F13R1_FB20_Pos                   (20U)                             
#define CAN_F13R1_FB20_Msk                   (0x1UL << CAN_F13R1_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F13R1_FB20                       CAN_F13R1_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F13R1_FB21_Pos                   (21U)                             
#define CAN_F13R1_FB21_Msk                   (0x1UL << CAN_F13R1_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F13R1_FB21                       CAN_F13R1_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F13R1_FB22_Pos                   (22U)                             
#define CAN_F13R1_FB22_Msk                   (0x1UL << CAN_F13R1_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F13R1_FB22                       CAN_F13R1_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F13R1_FB23_Pos                   (23U)                             
#define CAN_F13R1_FB23_Msk                   (0x1UL << CAN_F13R1_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F13R1_FB23                       CAN_F13R1_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F13R1_FB24_Pos                   (24U)                             
#define CAN_F13R1_FB24_Msk                   (0x1UL << CAN_F13R1_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F13R1_FB24                       CAN_F13R1_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F13R1_FB25_Pos                   (25U)                             
#define CAN_F13R1_FB25_Msk                   (0x1UL << CAN_F13R1_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F13R1_FB25                       CAN_F13R1_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F13R1_FB26_Pos                   (26U)                             
#define CAN_F13R1_FB26_Msk                   (0x1UL << CAN_F13R1_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F13R1_FB26                       CAN_F13R1_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F13R1_FB27_Pos                   (27U)                             
#define CAN_F13R1_FB27_Msk                   (0x1UL << CAN_F13R1_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F13R1_FB27                       CAN_F13R1_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F13R1_FB28_Pos                   (28U)                             
#define CAN_F13R1_FB28_Msk                   (0x1UL << CAN_F13R1_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F13R1_FB28                       CAN_F13R1_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F13R1_FB29_Pos                   (29U)                             
#define CAN_F13R1_FB29_Msk                   (0x1UL << CAN_F13R1_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F13R1_FB29                       CAN_F13R1_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F13R1_FB30_Pos                   (30U)                             
#define CAN_F13R1_FB30_Msk                   (0x1UL << CAN_F13R1_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F13R1_FB30                       CAN_F13R1_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F13R1_FB31_Pos                   (31U)                             
#define CAN_F13R1_FB31_Msk                   (0x1UL << CAN_F13R1_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F13R1_FB31                       CAN_F13R1_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define CAN_F0R2_FB0_Pos                     (0U)                              
#define CAN_F0R2_FB0_Msk                     (0x1UL << CAN_F0R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F0R2_FB0                         CAN_F0R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F0R2_FB1_Pos                     (1U)                              
#define CAN_F0R2_FB1_Msk                     (0x1UL << CAN_F0R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F0R2_FB1                         CAN_F0R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F0R2_FB2_Pos                     (2U)                              
#define CAN_F0R2_FB2_Msk                     (0x1UL << CAN_F0R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F0R2_FB2                         CAN_F0R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F0R2_FB3_Pos                     (3U)                              
#define CAN_F0R2_FB3_Msk                     (0x1UL << CAN_F0R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F0R2_FB3                         CAN_F0R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F0R2_FB4_Pos                     (4U)                              
#define CAN_F0R2_FB4_Msk                     (0x1UL << CAN_F0R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F0R2_FB4                         CAN_F0R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F0R2_FB5_Pos                     (5U)                              
#define CAN_F0R2_FB5_Msk                     (0x1UL << CAN_F0R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F0R2_FB5                         CAN_F0R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F0R2_FB6_Pos                     (6U)                              
#define CAN_F0R2_FB6_Msk                     (0x1UL << CAN_F0R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F0R2_FB6                         CAN_F0R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F0R2_FB7_Pos                     (7U)                              
#define CAN_F0R2_FB7_Msk                     (0x1UL << CAN_F0R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F0R2_FB7                         CAN_F0R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F0R2_FB8_Pos                     (8U)                              
#define CAN_F0R2_FB8_Msk                     (0x1UL << CAN_F0R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F0R2_FB8                         CAN_F0R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F0R2_FB9_Pos                     (9U)                              
#define CAN_F0R2_FB9_Msk                     (0x1UL << CAN_F0R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F0R2_FB9                         CAN_F0R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F0R2_FB10_Pos                    (10U)                             
#define CAN_F0R2_FB10_Msk                    (0x1UL << CAN_F0R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F0R2_FB10                        CAN_F0R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F0R2_FB11_Pos                    (11U)                             
#define CAN_F0R2_FB11_Msk                    (0x1UL << CAN_F0R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F0R2_FB11                        CAN_F0R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F0R2_FB12_Pos                    (12U)                             
#define CAN_F0R2_FB12_Msk                    (0x1UL << CAN_F0R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F0R2_FB12                        CAN_F0R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F0R2_FB13_Pos                    (13U)                             
#define CAN_F0R2_FB13_Msk                    (0x1UL << CAN_F0R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F0R2_FB13                        CAN_F0R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F0R2_FB14_Pos                    (14U)                             
#define CAN_F0R2_FB14_Msk                    (0x1UL << CAN_F0R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F0R2_FB14                        CAN_F0R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F0R2_FB15_Pos                    (15U)                             
#define CAN_F0R2_FB15_Msk                    (0x1UL << CAN_F0R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F0R2_FB15                        CAN_F0R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F0R2_FB16_Pos                    (16U)                             
#define CAN_F0R2_FB16_Msk                    (0x1UL << CAN_F0R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F0R2_FB16                        CAN_F0R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F0R2_FB17_Pos                    (17U)                             
#define CAN_F0R2_FB17_Msk                    (0x1UL << CAN_F0R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F0R2_FB17                        CAN_F0R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F0R2_FB18_Pos                    (18U)                             
#define CAN_F0R2_FB18_Msk                    (0x1UL << CAN_F0R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F0R2_FB18                        CAN_F0R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F0R2_FB19_Pos                    (19U)                             
#define CAN_F0R2_FB19_Msk                    (0x1UL << CAN_F0R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F0R2_FB19                        CAN_F0R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F0R2_FB20_Pos                    (20U)                             
#define CAN_F0R2_FB20_Msk                    (0x1UL << CAN_F0R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F0R2_FB20                        CAN_F0R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F0R2_FB21_Pos                    (21U)                             
#define CAN_F0R2_FB21_Msk                    (0x1UL << CAN_F0R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F0R2_FB21                        CAN_F0R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F0R2_FB22_Pos                    (22U)                             
#define CAN_F0R2_FB22_Msk                    (0x1UL << CAN_F0R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F0R2_FB22                        CAN_F0R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F0R2_FB23_Pos                    (23U)                             
#define CAN_F0R2_FB23_Msk                    (0x1UL << CAN_F0R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F0R2_FB23                        CAN_F0R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F0R2_FB24_Pos                    (24U)                             
#define CAN_F0R2_FB24_Msk                    (0x1UL << CAN_F0R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F0R2_FB24                        CAN_F0R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F0R2_FB25_Pos                    (25U)                             
#define CAN_F0R2_FB25_Msk                    (0x1UL << CAN_F0R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F0R2_FB25                        CAN_F0R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F0R2_FB26_Pos                    (26U)                             
#define CAN_F0R2_FB26_Msk                    (0x1UL << CAN_F0R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F0R2_FB26                        CAN_F0R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F0R2_FB27_Pos                    (27U)                             
#define CAN_F0R2_FB27_Msk                    (0x1UL << CAN_F0R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F0R2_FB27                        CAN_F0R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F0R2_FB28_Pos                    (28U)                             
#define CAN_F0R2_FB28_Msk                    (0x1UL << CAN_F0R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F0R2_FB28                        CAN_F0R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F0R2_FB29_Pos                    (29U)                             
#define CAN_F0R2_FB29_Msk                    (0x1UL << CAN_F0R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F0R2_FB29                        CAN_F0R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F0R2_FB30_Pos                    (30U)                             
#define CAN_F0R2_FB30_Msk                    (0x1UL << CAN_F0R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F0R2_FB30                        CAN_F0R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F0R2_FB31_Pos                    (31U)                             
#define CAN_F0R2_FB31_Msk                    (0x1UL << CAN_F0R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F0R2_FB31                        CAN_F0R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define CAN_F1R2_FB0_Pos                     (0U)                              
#define CAN_F1R2_FB0_Msk                     (0x1UL << CAN_F1R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F1R2_FB0                         CAN_F1R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F1R2_FB1_Pos                     (1U)                              
#define CAN_F1R2_FB1_Msk                     (0x1UL << CAN_F1R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F1R2_FB1                         CAN_F1R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F1R2_FB2_Pos                     (2U)                              
#define CAN_F1R2_FB2_Msk                     (0x1UL << CAN_F1R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F1R2_FB2                         CAN_F1R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F1R2_FB3_Pos                     (3U)                              
#define CAN_F1R2_FB3_Msk                     (0x1UL << CAN_F1R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F1R2_FB3                         CAN_F1R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F1R2_FB4_Pos                     (4U)                              
#define CAN_F1R2_FB4_Msk                     (0x1UL << CAN_F1R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F1R2_FB4                         CAN_F1R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F1R2_FB5_Pos                     (5U)                              
#define CAN_F1R2_FB5_Msk                     (0x1UL << CAN_F1R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F1R2_FB5                         CAN_F1R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F1R2_FB6_Pos                     (6U)                              
#define CAN_F1R2_FB6_Msk                     (0x1UL << CAN_F1R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F1R2_FB6                         CAN_F1R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F1R2_FB7_Pos                     (7U)                              
#define CAN_F1R2_FB7_Msk                     (0x1UL << CAN_F1R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F1R2_FB7                         CAN_F1R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F1R2_FB8_Pos                     (8U)                              
#define CAN_F1R2_FB8_Msk                     (0x1UL << CAN_F1R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F1R2_FB8                         CAN_F1R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F1R2_FB9_Pos                     (9U)                              
#define CAN_F1R2_FB9_Msk                     (0x1UL << CAN_F1R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F1R2_FB9                         CAN_F1R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F1R2_FB10_Pos                    (10U)                             
#define CAN_F1R2_FB10_Msk                    (0x1UL << CAN_F1R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F1R2_FB10                        CAN_F1R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F1R2_FB11_Pos                    (11U)                             
#define CAN_F1R2_FB11_Msk                    (0x1UL << CAN_F1R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F1R2_FB11                        CAN_F1R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F1R2_FB12_Pos                    (12U)                             
#define CAN_F1R2_FB12_Msk                    (0x1UL << CAN_F1R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F1R2_FB12                        CAN_F1R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F1R2_FB13_Pos                    (13U)                             
#define CAN_F1R2_FB13_Msk                    (0x1UL << CAN_F1R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F1R2_FB13                        CAN_F1R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F1R2_FB14_Pos                    (14U)                             
#define CAN_F1R2_FB14_Msk                    (0x1UL << CAN_F1R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F1R2_FB14                        CAN_F1R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F1R2_FB15_Pos                    (15U)                             
#define CAN_F1R2_FB15_Msk                    (0x1UL << CAN_F1R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F1R2_FB15                        CAN_F1R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F1R2_FB16_Pos                    (16U)                             
#define CAN_F1R2_FB16_Msk                    (0x1UL << CAN_F1R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F1R2_FB16                        CAN_F1R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F1R2_FB17_Pos                    (17U)                             
#define CAN_F1R2_FB17_Msk                    (0x1UL << CAN_F1R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F1R2_FB17                        CAN_F1R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F1R2_FB18_Pos                    (18U)                             
#define CAN_F1R2_FB18_Msk                    (0x1UL << CAN_F1R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F1R2_FB18                        CAN_F1R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F1R2_FB19_Pos                    (19U)                             
#define CAN_F1R2_FB19_Msk                    (0x1UL << CAN_F1R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F1R2_FB19                        CAN_F1R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F1R2_FB20_Pos                    (20U)                             
#define CAN_F1R2_FB20_Msk                    (0x1UL << CAN_F1R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F1R2_FB20                        CAN_F1R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F1R2_FB21_Pos                    (21U)                             
#define CAN_F1R2_FB21_Msk                    (0x1UL << CAN_F1R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F1R2_FB21                        CAN_F1R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F1R2_FB22_Pos                    (22U)                             
#define CAN_F1R2_FB22_Msk                    (0x1UL << CAN_F1R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F1R2_FB22                        CAN_F1R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F1R2_FB23_Pos                    (23U)                             
#define CAN_F1R2_FB23_Msk                    (0x1UL << CAN_F1R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F1R2_FB23                        CAN_F1R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F1R2_FB24_Pos                    (24U)                             
#define CAN_F1R2_FB24_Msk                    (0x1UL << CAN_F1R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F1R2_FB24                        CAN_F1R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F1R2_FB25_Pos                    (25U)                             
#define CAN_F1R2_FB25_Msk                    (0x1UL << CAN_F1R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F1R2_FB25                        CAN_F1R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F1R2_FB26_Pos                    (26U)                             
#define CAN_F1R2_FB26_Msk                    (0x1UL << CAN_F1R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F1R2_FB26                        CAN_F1R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F1R2_FB27_Pos                    (27U)                             
#define CAN_F1R2_FB27_Msk                    (0x1UL << CAN_F1R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F1R2_FB27                        CAN_F1R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F1R2_FB28_Pos                    (28U)                             
#define CAN_F1R2_FB28_Msk                    (0x1UL << CAN_F1R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F1R2_FB28                        CAN_F1R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F1R2_FB29_Pos                    (29U)                             
#define CAN_F1R2_FB29_Msk                    (0x1UL << CAN_F1R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F1R2_FB29                        CAN_F1R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F1R2_FB30_Pos                    (30U)                             
#define CAN_F1R2_FB30_Msk                    (0x1UL << CAN_F1R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F1R2_FB30                        CAN_F1R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F1R2_FB31_Pos                    (31U)                             
#define CAN_F1R2_FB31_Msk                    (0x1UL << CAN_F1R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F1R2_FB31                        CAN_F1R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define CAN_F2R2_FB0_Pos                     (0U)                              
#define CAN_F2R2_FB0_Msk                     (0x1UL << CAN_F2R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F2R2_FB0                         CAN_F2R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F2R2_FB1_Pos                     (1U)                              
#define CAN_F2R2_FB1_Msk                     (0x1UL << CAN_F2R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F2R2_FB1                         CAN_F2R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F2R2_FB2_Pos                     (2U)                              
#define CAN_F2R2_FB2_Msk                     (0x1UL << CAN_F2R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F2R2_FB2                         CAN_F2R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F2R2_FB3_Pos                     (3U)                              
#define CAN_F2R2_FB3_Msk                     (0x1UL << CAN_F2R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F2R2_FB3                         CAN_F2R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F2R2_FB4_Pos                     (4U)                              
#define CAN_F2R2_FB4_Msk                     (0x1UL << CAN_F2R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F2R2_FB4                         CAN_F2R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F2R2_FB5_Pos                     (5U)                              
#define CAN_F2R2_FB5_Msk                     (0x1UL << CAN_F2R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F2R2_FB5                         CAN_F2R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F2R2_FB6_Pos                     (6U)                              
#define CAN_F2R2_FB6_Msk                     (0x1UL << CAN_F2R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F2R2_FB6                         CAN_F2R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F2R2_FB7_Pos                     (7U)                              
#define CAN_F2R2_FB7_Msk                     (0x1UL << CAN_F2R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F2R2_FB7                         CAN_F2R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F2R2_FB8_Pos                     (8U)                              
#define CAN_F2R2_FB8_Msk                     (0x1UL << CAN_F2R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F2R2_FB8                         CAN_F2R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F2R2_FB9_Pos                     (9U)                              
#define CAN_F2R2_FB9_Msk                     (0x1UL << CAN_F2R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F2R2_FB9                         CAN_F2R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F2R2_FB10_Pos                    (10U)                             
#define CAN_F2R2_FB10_Msk                    (0x1UL << CAN_F2R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F2R2_FB10                        CAN_F2R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F2R2_FB11_Pos                    (11U)                             
#define CAN_F2R2_FB11_Msk                    (0x1UL << CAN_F2R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F2R2_FB11                        CAN_F2R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F2R2_FB12_Pos                    (12U)                             
#define CAN_F2R2_FB12_Msk                    (0x1UL << CAN_F2R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F2R2_FB12                        CAN_F2R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F2R2_FB13_Pos                    (13U)                             
#define CAN_F2R2_FB13_Msk                    (0x1UL << CAN_F2R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F2R2_FB13                        CAN_F2R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F2R2_FB14_Pos                    (14U)                             
#define CAN_F2R2_FB14_Msk                    (0x1UL << CAN_F2R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F2R2_FB14                        CAN_F2R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F2R2_FB15_Pos                    (15U)                             
#define CAN_F2R2_FB15_Msk                    (0x1UL << CAN_F2R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F2R2_FB15                        CAN_F2R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F2R2_FB16_Pos                    (16U)                             
#define CAN_F2R2_FB16_Msk                    (0x1UL << CAN_F2R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F2R2_FB16                        CAN_F2R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F2R2_FB17_Pos                    (17U)                             
#define CAN_F2R2_FB17_Msk                    (0x1UL << CAN_F2R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F2R2_FB17                        CAN_F2R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F2R2_FB18_Pos                    (18U)                             
#define CAN_F2R2_FB18_Msk                    (0x1UL << CAN_F2R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F2R2_FB18                        CAN_F2R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F2R2_FB19_Pos                    (19U)                             
#define CAN_F2R2_FB19_Msk                    (0x1UL << CAN_F2R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F2R2_FB19                        CAN_F2R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F2R2_FB20_Pos                    (20U)                             
#define CAN_F2R2_FB20_Msk                    (0x1UL << CAN_F2R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F2R2_FB20                        CAN_F2R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F2R2_FB21_Pos                    (21U)                             
#define CAN_F2R2_FB21_Msk                    (0x1UL << CAN_F2R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F2R2_FB21                        CAN_F2R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F2R2_FB22_Pos                    (22U)                             
#define CAN_F2R2_FB22_Msk                    (0x1UL << CAN_F2R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F2R2_FB22                        CAN_F2R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F2R2_FB23_Pos                    (23U)                             
#define CAN_F2R2_FB23_Msk                    (0x1UL << CAN_F2R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F2R2_FB23                        CAN_F2R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F2R2_FB24_Pos                    (24U)                             
#define CAN_F2R2_FB24_Msk                    (0x1UL << CAN_F2R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F2R2_FB24                        CAN_F2R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F2R2_FB25_Pos                    (25U)                             
#define CAN_F2R2_FB25_Msk                    (0x1UL << CAN_F2R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F2R2_FB25                        CAN_F2R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F2R2_FB26_Pos                    (26U)                             
#define CAN_F2R2_FB26_Msk                    (0x1UL << CAN_F2R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F2R2_FB26                        CAN_F2R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F2R2_FB27_Pos                    (27U)                             
#define CAN_F2R2_FB27_Msk                    (0x1UL << CAN_F2R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F2R2_FB27                        CAN_F2R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F2R2_FB28_Pos                    (28U)                             
#define CAN_F2R2_FB28_Msk                    (0x1UL << CAN_F2R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F2R2_FB28                        CAN_F2R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F2R2_FB29_Pos                    (29U)                             
#define CAN_F2R2_FB29_Msk                    (0x1UL << CAN_F2R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F2R2_FB29                        CAN_F2R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F2R2_FB30_Pos                    (30U)                             
#define CAN_F2R2_FB30_Msk                    (0x1UL << CAN_F2R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F2R2_FB30                        CAN_F2R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F2R2_FB31_Pos                    (31U)                             
#define CAN_F2R2_FB31_Msk                    (0x1UL << CAN_F2R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F2R2_FB31                        CAN_F2R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define CAN_F3R2_FB0_Pos                     (0U)                              
#define CAN_F3R2_FB0_Msk                     (0x1UL << CAN_F3R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F3R2_FB0                         CAN_F3R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F3R2_FB1_Pos                     (1U)                              
#define CAN_F3R2_FB1_Msk                     (0x1UL << CAN_F3R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F3R2_FB1                         CAN_F3R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F3R2_FB2_Pos                     (2U)                              
#define CAN_F3R2_FB2_Msk                     (0x1UL << CAN_F3R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F3R2_FB2                         CAN_F3R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F3R2_FB3_Pos                     (3U)                              
#define CAN_F3R2_FB3_Msk                     (0x1UL << CAN_F3R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F3R2_FB3                         CAN_F3R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F3R2_FB4_Pos                     (4U)                              
#define CAN_F3R2_FB4_Msk                     (0x1UL << CAN_F3R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F3R2_FB4                         CAN_F3R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F3R2_FB5_Pos                     (5U)                              
#define CAN_F3R2_FB5_Msk                     (0x1UL << CAN_F3R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F3R2_FB5                         CAN_F3R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F3R2_FB6_Pos                     (6U)                              
#define CAN_F3R2_FB6_Msk                     (0x1UL << CAN_F3R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F3R2_FB6                         CAN_F3R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F3R2_FB7_Pos                     (7U)                              
#define CAN_F3R2_FB7_Msk                     (0x1UL << CAN_F3R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F3R2_FB7                         CAN_F3R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F3R2_FB8_Pos                     (8U)                              
#define CAN_F3R2_FB8_Msk                     (0x1UL << CAN_F3R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F3R2_FB8                         CAN_F3R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F3R2_FB9_Pos                     (9U)                              
#define CAN_F3R2_FB9_Msk                     (0x1UL << CAN_F3R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F3R2_FB9                         CAN_F3R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F3R2_FB10_Pos                    (10U)                             
#define CAN_F3R2_FB10_Msk                    (0x1UL << CAN_F3R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F3R2_FB10                        CAN_F3R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F3R2_FB11_Pos                    (11U)                             
#define CAN_F3R2_FB11_Msk                    (0x1UL << CAN_F3R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F3R2_FB11                        CAN_F3R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F3R2_FB12_Pos                    (12U)                             
#define CAN_F3R2_FB12_Msk                    (0x1UL << CAN_F3R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F3R2_FB12                        CAN_F3R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F3R2_FB13_Pos                    (13U)                             
#define CAN_F3R2_FB13_Msk                    (0x1UL << CAN_F3R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F3R2_FB13                        CAN_F3R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F3R2_FB14_Pos                    (14U)                             
#define CAN_F3R2_FB14_Msk                    (0x1UL << CAN_F3R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F3R2_FB14                        CAN_F3R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F3R2_FB15_Pos                    (15U)                             
#define CAN_F3R2_FB15_Msk                    (0x1UL << CAN_F3R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F3R2_FB15                        CAN_F3R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F3R2_FB16_Pos                    (16U)                             
#define CAN_F3R2_FB16_Msk                    (0x1UL << CAN_F3R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F3R2_FB16                        CAN_F3R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F3R2_FB17_Pos                    (17U)                             
#define CAN_F3R2_FB17_Msk                    (0x1UL << CAN_F3R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F3R2_FB17                        CAN_F3R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F3R2_FB18_Pos                    (18U)                             
#define CAN_F3R2_FB18_Msk                    (0x1UL << CAN_F3R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F3R2_FB18                        CAN_F3R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F3R2_FB19_Pos                    (19U)                             
#define CAN_F3R2_FB19_Msk                    (0x1UL << CAN_F3R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F3R2_FB19                        CAN_F3R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F3R2_FB20_Pos                    (20U)                             
#define CAN_F3R2_FB20_Msk                    (0x1UL << CAN_F3R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F3R2_FB20                        CAN_F3R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F3R2_FB21_Pos                    (21U)                             
#define CAN_F3R2_FB21_Msk                    (0x1UL << CAN_F3R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F3R2_FB21                        CAN_F3R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F3R2_FB22_Pos                    (22U)                             
#define CAN_F3R2_FB22_Msk                    (0x1UL << CAN_F3R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F3R2_FB22                        CAN_F3R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F3R2_FB23_Pos                    (23U)                             
#define CAN_F3R2_FB23_Msk                    (0x1UL << CAN_F3R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F3R2_FB23                        CAN_F3R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F3R2_FB24_Pos                    (24U)                             
#define CAN_F3R2_FB24_Msk                    (0x1UL << CAN_F3R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F3R2_FB24                        CAN_F3R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F3R2_FB25_Pos                    (25U)                             
#define CAN_F3R2_FB25_Msk                    (0x1UL << CAN_F3R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F3R2_FB25                        CAN_F3R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F3R2_FB26_Pos                    (26U)                             
#define CAN_F3R2_FB26_Msk                    (0x1UL << CAN_F3R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F3R2_FB26                        CAN_F3R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F3R2_FB27_Pos                    (27U)                             
#define CAN_F3R2_FB27_Msk                    (0x1UL << CAN_F3R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F3R2_FB27                        CAN_F3R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F3R2_FB28_Pos                    (28U)                             
#define CAN_F3R2_FB28_Msk                    (0x1UL << CAN_F3R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F3R2_FB28                        CAN_F3R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F3R2_FB29_Pos                    (29U)                             
#define CAN_F3R2_FB29_Msk                    (0x1UL << CAN_F3R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F3R2_FB29                        CAN_F3R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F3R2_FB30_Pos                    (30U)                             
#define CAN_F3R2_FB30_Msk                    (0x1UL << CAN_F3R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F3R2_FB30                        CAN_F3R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F3R2_FB31_Pos                    (31U)                             
#define CAN_F3R2_FB31_Msk                    (0x1UL << CAN_F3R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F3R2_FB31                        CAN_F3R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define CAN_F4R2_FB0_Pos                     (0U)                              
#define CAN_F4R2_FB0_Msk                     (0x1UL << CAN_F4R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F4R2_FB0                         CAN_F4R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F4R2_FB1_Pos                     (1U)                              
#define CAN_F4R2_FB1_Msk                     (0x1UL << CAN_F4R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F4R2_FB1                         CAN_F4R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F4R2_FB2_Pos                     (2U)                              
#define CAN_F4R2_FB2_Msk                     (0x1UL << CAN_F4R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F4R2_FB2                         CAN_F4R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F4R2_FB3_Pos                     (3U)                              
#define CAN_F4R2_FB3_Msk                     (0x1UL << CAN_F4R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F4R2_FB3                         CAN_F4R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F4R2_FB4_Pos                     (4U)                              
#define CAN_F4R2_FB4_Msk                     (0x1UL << CAN_F4R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F4R2_FB4                         CAN_F4R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F4R2_FB5_Pos                     (5U)                              
#define CAN_F4R2_FB5_Msk                     (0x1UL << CAN_F4R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F4R2_FB5                         CAN_F4R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F4R2_FB6_Pos                     (6U)                              
#define CAN_F4R2_FB6_Msk                     (0x1UL << CAN_F4R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F4R2_FB6                         CAN_F4R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F4R2_FB7_Pos                     (7U)                              
#define CAN_F4R2_FB7_Msk                     (0x1UL << CAN_F4R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F4R2_FB7                         CAN_F4R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F4R2_FB8_Pos                     (8U)                              
#define CAN_F4R2_FB8_Msk                     (0x1UL << CAN_F4R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F4R2_FB8                         CAN_F4R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F4R2_FB9_Pos                     (9U)                              
#define CAN_F4R2_FB9_Msk                     (0x1UL << CAN_F4R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F4R2_FB9                         CAN_F4R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F4R2_FB10_Pos                    (10U)                             
#define CAN_F4R2_FB10_Msk                    (0x1UL << CAN_F4R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F4R2_FB10                        CAN_F4R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F4R2_FB11_Pos                    (11U)                             
#define CAN_F4R2_FB11_Msk                    (0x1UL << CAN_F4R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F4R2_FB11                        CAN_F4R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F4R2_FB12_Pos                    (12U)                             
#define CAN_F4R2_FB12_Msk                    (0x1UL << CAN_F4R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F4R2_FB12                        CAN_F4R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F4R2_FB13_Pos                    (13U)                             
#define CAN_F4R2_FB13_Msk                    (0x1UL << CAN_F4R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F4R2_FB13                        CAN_F4R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F4R2_FB14_Pos                    (14U)                             
#define CAN_F4R2_FB14_Msk                    (0x1UL << CAN_F4R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F4R2_FB14                        CAN_F4R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F4R2_FB15_Pos                    (15U)                             
#define CAN_F4R2_FB15_Msk                    (0x1UL << CAN_F4R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F4R2_FB15                        CAN_F4R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F4R2_FB16_Pos                    (16U)                             
#define CAN_F4R2_FB16_Msk                    (0x1UL << CAN_F4R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F4R2_FB16                        CAN_F4R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F4R2_FB17_Pos                    (17U)                             
#define CAN_F4R2_FB17_Msk                    (0x1UL << CAN_F4R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F4R2_FB17                        CAN_F4R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F4R2_FB18_Pos                    (18U)                             
#define CAN_F4R2_FB18_Msk                    (0x1UL << CAN_F4R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F4R2_FB18                        CAN_F4R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F4R2_FB19_Pos                    (19U)                             
#define CAN_F4R2_FB19_Msk                    (0x1UL << CAN_F4R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F4R2_FB19                        CAN_F4R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F4R2_FB20_Pos                    (20U)                             
#define CAN_F4R2_FB20_Msk                    (0x1UL << CAN_F4R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F4R2_FB20                        CAN_F4R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F4R2_FB21_Pos                    (21U)                             
#define CAN_F4R2_FB21_Msk                    (0x1UL << CAN_F4R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F4R2_FB21                        CAN_F4R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F4R2_FB22_Pos                    (22U)                             
#define CAN_F4R2_FB22_Msk                    (0x1UL << CAN_F4R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F4R2_FB22                        CAN_F4R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F4R2_FB23_Pos                    (23U)                             
#define CAN_F4R2_FB23_Msk                    (0x1UL << CAN_F4R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F4R2_FB23                        CAN_F4R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F4R2_FB24_Pos                    (24U)                             
#define CAN_F4R2_FB24_Msk                    (0x1UL << CAN_F4R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F4R2_FB24                        CAN_F4R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F4R2_FB25_Pos                    (25U)                             
#define CAN_F4R2_FB25_Msk                    (0x1UL << CAN_F4R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F4R2_FB25                        CAN_F4R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F4R2_FB26_Pos                    (26U)                             
#define CAN_F4R2_FB26_Msk                    (0x1UL << CAN_F4R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F4R2_FB26                        CAN_F4R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F4R2_FB27_Pos                    (27U)                             
#define CAN_F4R2_FB27_Msk                    (0x1UL << CAN_F4R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F4R2_FB27                        CAN_F4R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F4R2_FB28_Pos                    (28U)                             
#define CAN_F4R2_FB28_Msk                    (0x1UL << CAN_F4R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F4R2_FB28                        CAN_F4R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F4R2_FB29_Pos                    (29U)                             
#define CAN_F4R2_FB29_Msk                    (0x1UL << CAN_F4R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F4R2_FB29                        CAN_F4R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F4R2_FB30_Pos                    (30U)                             
#define CAN_F4R2_FB30_Msk                    (0x1UL << CAN_F4R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F4R2_FB30                        CAN_F4R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F4R2_FB31_Pos                    (31U)                             
#define CAN_F4R2_FB31_Msk                    (0x1UL << CAN_F4R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F4R2_FB31                        CAN_F4R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define CAN_F5R2_FB0_Pos                     (0U)                              
#define CAN_F5R2_FB0_Msk                     (0x1UL << CAN_F5R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F5R2_FB0                         CAN_F5R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F5R2_FB1_Pos                     (1U)                              
#define CAN_F5R2_FB1_Msk                     (0x1UL << CAN_F5R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F5R2_FB1                         CAN_F5R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F5R2_FB2_Pos                     (2U)                              
#define CAN_F5R2_FB2_Msk                     (0x1UL << CAN_F5R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F5R2_FB2                         CAN_F5R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F5R2_FB3_Pos                     (3U)                              
#define CAN_F5R2_FB3_Msk                     (0x1UL << CAN_F5R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F5R2_FB3                         CAN_F5R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F5R2_FB4_Pos                     (4U)                              
#define CAN_F5R2_FB4_Msk                     (0x1UL << CAN_F5R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F5R2_FB4                         CAN_F5R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F5R2_FB5_Pos                     (5U)                              
#define CAN_F5R2_FB5_Msk                     (0x1UL << CAN_F5R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F5R2_FB5                         CAN_F5R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F5R2_FB6_Pos                     (6U)                              
#define CAN_F5R2_FB6_Msk                     (0x1UL << CAN_F5R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F5R2_FB6                         CAN_F5R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F5R2_FB7_Pos                     (7U)                              
#define CAN_F5R2_FB7_Msk                     (0x1UL << CAN_F5R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F5R2_FB7                         CAN_F5R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F5R2_FB8_Pos                     (8U)                              
#define CAN_F5R2_FB8_Msk                     (0x1UL << CAN_F5R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F5R2_FB8                         CAN_F5R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F5R2_FB9_Pos                     (9U)                              
#define CAN_F5R2_FB9_Msk                     (0x1UL << CAN_F5R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F5R2_FB9                         CAN_F5R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F5R2_FB10_Pos                    (10U)                             
#define CAN_F5R2_FB10_Msk                    (0x1UL << CAN_F5R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F5R2_FB10                        CAN_F5R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F5R2_FB11_Pos                    (11U)                             
#define CAN_F5R2_FB11_Msk                    (0x1UL << CAN_F5R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F5R2_FB11                        CAN_F5R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F5R2_FB12_Pos                    (12U)                             
#define CAN_F5R2_FB12_Msk                    (0x1UL << CAN_F5R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F5R2_FB12                        CAN_F5R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F5R2_FB13_Pos                    (13U)                             
#define CAN_F5R2_FB13_Msk                    (0x1UL << CAN_F5R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F5R2_FB13                        CAN_F5R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F5R2_FB14_Pos                    (14U)                             
#define CAN_F5R2_FB14_Msk                    (0x1UL << CAN_F5R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F5R2_FB14                        CAN_F5R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F5R2_FB15_Pos                    (15U)                             
#define CAN_F5R2_FB15_Msk                    (0x1UL << CAN_F5R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F5R2_FB15                        CAN_F5R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F5R2_FB16_Pos                    (16U)                             
#define CAN_F5R2_FB16_Msk                    (0x1UL << CAN_F5R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F5R2_FB16                        CAN_F5R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F5R2_FB17_Pos                    (17U)                             
#define CAN_F5R2_FB17_Msk                    (0x1UL << CAN_F5R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F5R2_FB17                        CAN_F5R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F5R2_FB18_Pos                    (18U)                             
#define CAN_F5R2_FB18_Msk                    (0x1UL << CAN_F5R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F5R2_FB18                        CAN_F5R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F5R2_FB19_Pos                    (19U)                             
#define CAN_F5R2_FB19_Msk                    (0x1UL << CAN_F5R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F5R2_FB19                        CAN_F5R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F5R2_FB20_Pos                    (20U)                             
#define CAN_F5R2_FB20_Msk                    (0x1UL << CAN_F5R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F5R2_FB20                        CAN_F5R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F5R2_FB21_Pos                    (21U)                             
#define CAN_F5R2_FB21_Msk                    (0x1UL << CAN_F5R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F5R2_FB21                        CAN_F5R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F5R2_FB22_Pos                    (22U)                             
#define CAN_F5R2_FB22_Msk                    (0x1UL << CAN_F5R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F5R2_FB22                        CAN_F5R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F5R2_FB23_Pos                    (23U)                             
#define CAN_F5R2_FB23_Msk                    (0x1UL << CAN_F5R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F5R2_FB23                        CAN_F5R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F5R2_FB24_Pos                    (24U)                             
#define CAN_F5R2_FB24_Msk                    (0x1UL << CAN_F5R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F5R2_FB24                        CAN_F5R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F5R2_FB25_Pos                    (25U)                             
#define CAN_F5R2_FB25_Msk                    (0x1UL << CAN_F5R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F5R2_FB25                        CAN_F5R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F5R2_FB26_Pos                    (26U)                             
#define CAN_F5R2_FB26_Msk                    (0x1UL << CAN_F5R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F5R2_FB26                        CAN_F5R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F5R2_FB27_Pos                    (27U)                             
#define CAN_F5R2_FB27_Msk                    (0x1UL << CAN_F5R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F5R2_FB27                        CAN_F5R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F5R2_FB28_Pos                    (28U)                             
#define CAN_F5R2_FB28_Msk                    (0x1UL << CAN_F5R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F5R2_FB28                        CAN_F5R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F5R2_FB29_Pos                    (29U)                             
#define CAN_F5R2_FB29_Msk                    (0x1UL << CAN_F5R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F5R2_FB29                        CAN_F5R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F5R2_FB30_Pos                    (30U)                             
#define CAN_F5R2_FB30_Msk                    (0x1UL << CAN_F5R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F5R2_FB30                        CAN_F5R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F5R2_FB31_Pos                    (31U)                             
#define CAN_F5R2_FB31_Msk                    (0x1UL << CAN_F5R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F5R2_FB31                        CAN_F5R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define CAN_F6R2_FB0_Pos                     (0U)                              
#define CAN_F6R2_FB0_Msk                     (0x1UL << CAN_F6R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F6R2_FB0                         CAN_F6R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F6R2_FB1_Pos                     (1U)                              
#define CAN_F6R2_FB1_Msk                     (0x1UL << CAN_F6R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F6R2_FB1                         CAN_F6R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F6R2_FB2_Pos                     (2U)                              
#define CAN_F6R2_FB2_Msk                     (0x1UL << CAN_F6R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F6R2_FB2                         CAN_F6R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F6R2_FB3_Pos                     (3U)                              
#define CAN_F6R2_FB3_Msk                     (0x1UL << CAN_F6R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F6R2_FB3                         CAN_F6R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F6R2_FB4_Pos                     (4U)                              
#define CAN_F6R2_FB4_Msk                     (0x1UL << CAN_F6R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F6R2_FB4                         CAN_F6R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F6R2_FB5_Pos                     (5U)                              
#define CAN_F6R2_FB5_Msk                     (0x1UL << CAN_F6R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F6R2_FB5                         CAN_F6R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F6R2_FB6_Pos                     (6U)                              
#define CAN_F6R2_FB6_Msk                     (0x1UL << CAN_F6R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F6R2_FB6                         CAN_F6R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F6R2_FB7_Pos                     (7U)                              
#define CAN_F6R2_FB7_Msk                     (0x1UL << CAN_F6R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F6R2_FB7                         CAN_F6R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F6R2_FB8_Pos                     (8U)                              
#define CAN_F6R2_FB8_Msk                     (0x1UL << CAN_F6R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F6R2_FB8                         CAN_F6R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F6R2_FB9_Pos                     (9U)                              
#define CAN_F6R2_FB9_Msk                     (0x1UL << CAN_F6R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F6R2_FB9                         CAN_F6R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F6R2_FB10_Pos                    (10U)                             
#define CAN_F6R2_FB10_Msk                    (0x1UL << CAN_F6R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F6R2_FB10                        CAN_F6R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F6R2_FB11_Pos                    (11U)                             
#define CAN_F6R2_FB11_Msk                    (0x1UL << CAN_F6R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F6R2_FB11                        CAN_F6R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F6R2_FB12_Pos                    (12U)                             
#define CAN_F6R2_FB12_Msk                    (0x1UL << CAN_F6R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F6R2_FB12                        CAN_F6R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F6R2_FB13_Pos                    (13U)                             
#define CAN_F6R2_FB13_Msk                    (0x1UL << CAN_F6R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F6R2_FB13                        CAN_F6R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F6R2_FB14_Pos                    (14U)                             
#define CAN_F6R2_FB14_Msk                    (0x1UL << CAN_F6R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F6R2_FB14                        CAN_F6R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F6R2_FB15_Pos                    (15U)                             
#define CAN_F6R2_FB15_Msk                    (0x1UL << CAN_F6R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F6R2_FB15                        CAN_F6R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F6R2_FB16_Pos                    (16U)                             
#define CAN_F6R2_FB16_Msk                    (0x1UL << CAN_F6R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F6R2_FB16                        CAN_F6R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F6R2_FB17_Pos                    (17U)                             
#define CAN_F6R2_FB17_Msk                    (0x1UL << CAN_F6R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F6R2_FB17                        CAN_F6R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F6R2_FB18_Pos                    (18U)                             
#define CAN_F6R2_FB18_Msk                    (0x1UL << CAN_F6R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F6R2_FB18                        CAN_F6R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F6R2_FB19_Pos                    (19U)                             
#define CAN_F6R2_FB19_Msk                    (0x1UL << CAN_F6R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F6R2_FB19                        CAN_F6R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F6R2_FB20_Pos                    (20U)                             
#define CAN_F6R2_FB20_Msk                    (0x1UL << CAN_F6R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F6R2_FB20                        CAN_F6R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F6R2_FB21_Pos                    (21U)                             
#define CAN_F6R2_FB21_Msk                    (0x1UL << CAN_F6R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F6R2_FB21                        CAN_F6R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F6R2_FB22_Pos                    (22U)                             
#define CAN_F6R2_FB22_Msk                    (0x1UL << CAN_F6R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F6R2_FB22                        CAN_F6R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F6R2_FB23_Pos                    (23U)                             
#define CAN_F6R2_FB23_Msk                    (0x1UL << CAN_F6R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F6R2_FB23                        CAN_F6R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F6R2_FB24_Pos                    (24U)                             
#define CAN_F6R2_FB24_Msk                    (0x1UL << CAN_F6R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F6R2_FB24                        CAN_F6R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F6R2_FB25_Pos                    (25U)                             
#define CAN_F6R2_FB25_Msk                    (0x1UL << CAN_F6R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F6R2_FB25                        CAN_F6R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F6R2_FB26_Pos                    (26U)                             
#define CAN_F6R2_FB26_Msk                    (0x1UL << CAN_F6R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F6R2_FB26                        CAN_F6R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F6R2_FB27_Pos                    (27U)                             
#define CAN_F6R2_FB27_Msk                    (0x1UL << CAN_F6R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F6R2_FB27                        CAN_F6R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F6R2_FB28_Pos                    (28U)                             
#define CAN_F6R2_FB28_Msk                    (0x1UL << CAN_F6R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F6R2_FB28                        CAN_F6R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F6R2_FB29_Pos                    (29U)                             
#define CAN_F6R2_FB29_Msk                    (0x1UL << CAN_F6R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F6R2_FB29                        CAN_F6R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F6R2_FB30_Pos                    (30U)                             
#define CAN_F6R2_FB30_Msk                    (0x1UL << CAN_F6R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F6R2_FB30                        CAN_F6R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F6R2_FB31_Pos                    (31U)                             
#define CAN_F6R2_FB31_Msk                    (0x1UL << CAN_F6R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F6R2_FB31                        CAN_F6R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define CAN_F7R2_FB0_Pos                     (0U)                              
#define CAN_F7R2_FB0_Msk                     (0x1UL << CAN_F7R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F7R2_FB0                         CAN_F7R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F7R2_FB1_Pos                     (1U)                              
#define CAN_F7R2_FB1_Msk                     (0x1UL << CAN_F7R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F7R2_FB1                         CAN_F7R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F7R2_FB2_Pos                     (2U)                              
#define CAN_F7R2_FB2_Msk                     (0x1UL << CAN_F7R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F7R2_FB2                         CAN_F7R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F7R2_FB3_Pos                     (3U)                              
#define CAN_F7R2_FB3_Msk                     (0x1UL << CAN_F7R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F7R2_FB3                         CAN_F7R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F7R2_FB4_Pos                     (4U)                              
#define CAN_F7R2_FB4_Msk                     (0x1UL << CAN_F7R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F7R2_FB4                         CAN_F7R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F7R2_FB5_Pos                     (5U)                              
#define CAN_F7R2_FB5_Msk                     (0x1UL << CAN_F7R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F7R2_FB5                         CAN_F7R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F7R2_FB6_Pos                     (6U)                              
#define CAN_F7R2_FB6_Msk                     (0x1UL << CAN_F7R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F7R2_FB6                         CAN_F7R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F7R2_FB7_Pos                     (7U)                              
#define CAN_F7R2_FB7_Msk                     (0x1UL << CAN_F7R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F7R2_FB7                         CAN_F7R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F7R2_FB8_Pos                     (8U)                              
#define CAN_F7R2_FB8_Msk                     (0x1UL << CAN_F7R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F7R2_FB8                         CAN_F7R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F7R2_FB9_Pos                     (9U)                              
#define CAN_F7R2_FB9_Msk                     (0x1UL << CAN_F7R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F7R2_FB9                         CAN_F7R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F7R2_FB10_Pos                    (10U)                             
#define CAN_F7R2_FB10_Msk                    (0x1UL << CAN_F7R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F7R2_FB10                        CAN_F7R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F7R2_FB11_Pos                    (11U)                             
#define CAN_F7R2_FB11_Msk                    (0x1UL << CAN_F7R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F7R2_FB11                        CAN_F7R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F7R2_FB12_Pos                    (12U)                             
#define CAN_F7R2_FB12_Msk                    (0x1UL << CAN_F7R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F7R2_FB12                        CAN_F7R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F7R2_FB13_Pos                    (13U)                             
#define CAN_F7R2_FB13_Msk                    (0x1UL << CAN_F7R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F7R2_FB13                        CAN_F7R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F7R2_FB14_Pos                    (14U)                             
#define CAN_F7R2_FB14_Msk                    (0x1UL << CAN_F7R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F7R2_FB14                        CAN_F7R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F7R2_FB15_Pos                    (15U)                             
#define CAN_F7R2_FB15_Msk                    (0x1UL << CAN_F7R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F7R2_FB15                        CAN_F7R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F7R2_FB16_Pos                    (16U)                             
#define CAN_F7R2_FB16_Msk                    (0x1UL << CAN_F7R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F7R2_FB16                        CAN_F7R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F7R2_FB17_Pos                    (17U)                             
#define CAN_F7R2_FB17_Msk                    (0x1UL << CAN_F7R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F7R2_FB17                        CAN_F7R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F7R2_FB18_Pos                    (18U)                             
#define CAN_F7R2_FB18_Msk                    (0x1UL << CAN_F7R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F7R2_FB18                        CAN_F7R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F7R2_FB19_Pos                    (19U)                             
#define CAN_F7R2_FB19_Msk                    (0x1UL << CAN_F7R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F7R2_FB19                        CAN_F7R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F7R2_FB20_Pos                    (20U)                             
#define CAN_F7R2_FB20_Msk                    (0x1UL << CAN_F7R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F7R2_FB20                        CAN_F7R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F7R2_FB21_Pos                    (21U)                             
#define CAN_F7R2_FB21_Msk                    (0x1UL << CAN_F7R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F7R2_FB21                        CAN_F7R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F7R2_FB22_Pos                    (22U)                             
#define CAN_F7R2_FB22_Msk                    (0x1UL << CAN_F7R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F7R2_FB22                        CAN_F7R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F7R2_FB23_Pos                    (23U)                             
#define CAN_F7R2_FB23_Msk                    (0x1UL << CAN_F7R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F7R2_FB23                        CAN_F7R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F7R2_FB24_Pos                    (24U)                             
#define CAN_F7R2_FB24_Msk                    (0x1UL << CAN_F7R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F7R2_FB24                        CAN_F7R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F7R2_FB25_Pos                    (25U)                             
#define CAN_F7R2_FB25_Msk                    (0x1UL << CAN_F7R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F7R2_FB25                        CAN_F7R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F7R2_FB26_Pos                    (26U)                             
#define CAN_F7R2_FB26_Msk                    (0x1UL << CAN_F7R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F7R2_FB26                        CAN_F7R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F7R2_FB27_Pos                    (27U)                             
#define CAN_F7R2_FB27_Msk                    (0x1UL << CAN_F7R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F7R2_FB27                        CAN_F7R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F7R2_FB28_Pos                    (28U)                             
#define CAN_F7R2_FB28_Msk                    (0x1UL << CAN_F7R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F7R2_FB28                        CAN_F7R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F7R2_FB29_Pos                    (29U)                             
#define CAN_F7R2_FB29_Msk                    (0x1UL << CAN_F7R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F7R2_FB29                        CAN_F7R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F7R2_FB30_Pos                    (30U)                             
#define CAN_F7R2_FB30_Msk                    (0x1UL << CAN_F7R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F7R2_FB30                        CAN_F7R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F7R2_FB31_Pos                    (31U)                             
#define CAN_F7R2_FB31_Msk                    (0x1UL << CAN_F7R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F7R2_FB31                        CAN_F7R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define CAN_F8R2_FB0_Pos                     (0U)                              
#define CAN_F8R2_FB0_Msk                     (0x1UL << CAN_F8R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F8R2_FB0                         CAN_F8R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F8R2_FB1_Pos                     (1U)                              
#define CAN_F8R2_FB1_Msk                     (0x1UL << CAN_F8R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F8R2_FB1                         CAN_F8R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F8R2_FB2_Pos                     (2U)                              
#define CAN_F8R2_FB2_Msk                     (0x1UL << CAN_F8R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F8R2_FB2                         CAN_F8R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F8R2_FB3_Pos                     (3U)                              
#define CAN_F8R2_FB3_Msk                     (0x1UL << CAN_F8R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F8R2_FB3                         CAN_F8R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F8R2_FB4_Pos                     (4U)                              
#define CAN_F8R2_FB4_Msk                     (0x1UL << CAN_F8R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F8R2_FB4                         CAN_F8R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F8R2_FB5_Pos                     (5U)                              
#define CAN_F8R2_FB5_Msk                     (0x1UL << CAN_F8R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F8R2_FB5                         CAN_F8R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F8R2_FB6_Pos                     (6U)                              
#define CAN_F8R2_FB6_Msk                     (0x1UL << CAN_F8R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F8R2_FB6                         CAN_F8R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F8R2_FB7_Pos                     (7U)                              
#define CAN_F8R2_FB7_Msk                     (0x1UL << CAN_F8R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F8R2_FB7                         CAN_F8R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F8R2_FB8_Pos                     (8U)                              
#define CAN_F8R2_FB8_Msk                     (0x1UL << CAN_F8R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F8R2_FB8                         CAN_F8R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F8R2_FB9_Pos                     (9U)                              
#define CAN_F8R2_FB9_Msk                     (0x1UL << CAN_F8R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F8R2_FB9                         CAN_F8R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F8R2_FB10_Pos                    (10U)                             
#define CAN_F8R2_FB10_Msk                    (0x1UL << CAN_F8R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F8R2_FB10                        CAN_F8R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F8R2_FB11_Pos                    (11U)                             
#define CAN_F8R2_FB11_Msk                    (0x1UL << CAN_F8R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F8R2_FB11                        CAN_F8R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F8R2_FB12_Pos                    (12U)                             
#define CAN_F8R2_FB12_Msk                    (0x1UL << CAN_F8R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F8R2_FB12                        CAN_F8R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F8R2_FB13_Pos                    (13U)                             
#define CAN_F8R2_FB13_Msk                    (0x1UL << CAN_F8R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F8R2_FB13                        CAN_F8R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F8R2_FB14_Pos                    (14U)                             
#define CAN_F8R2_FB14_Msk                    (0x1UL << CAN_F8R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F8R2_FB14                        CAN_F8R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F8R2_FB15_Pos                    (15U)                             
#define CAN_F8R2_FB15_Msk                    (0x1UL << CAN_F8R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F8R2_FB15                        CAN_F8R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F8R2_FB16_Pos                    (16U)                             
#define CAN_F8R2_FB16_Msk                    (0x1UL << CAN_F8R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F8R2_FB16                        CAN_F8R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F8R2_FB17_Pos                    (17U)                             
#define CAN_F8R2_FB17_Msk                    (0x1UL << CAN_F8R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F8R2_FB17                        CAN_F8R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F8R2_FB18_Pos                    (18U)                             
#define CAN_F8R2_FB18_Msk                    (0x1UL << CAN_F8R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F8R2_FB18                        CAN_F8R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F8R2_FB19_Pos                    (19U)                             
#define CAN_F8R2_FB19_Msk                    (0x1UL << CAN_F8R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F8R2_FB19                        CAN_F8R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F8R2_FB20_Pos                    (20U)                             
#define CAN_F8R2_FB20_Msk                    (0x1UL << CAN_F8R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F8R2_FB20                        CAN_F8R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F8R2_FB21_Pos                    (21U)                             
#define CAN_F8R2_FB21_Msk                    (0x1UL << CAN_F8R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F8R2_FB21                        CAN_F8R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F8R2_FB22_Pos                    (22U)                             
#define CAN_F8R2_FB22_Msk                    (0x1UL << CAN_F8R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F8R2_FB22                        CAN_F8R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F8R2_FB23_Pos                    (23U)                             
#define CAN_F8R2_FB23_Msk                    (0x1UL << CAN_F8R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F8R2_FB23                        CAN_F8R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F8R2_FB24_Pos                    (24U)                             
#define CAN_F8R2_FB24_Msk                    (0x1UL << CAN_F8R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F8R2_FB24                        CAN_F8R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F8R2_FB25_Pos                    (25U)                             
#define CAN_F8R2_FB25_Msk                    (0x1UL << CAN_F8R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F8R2_FB25                        CAN_F8R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F8R2_FB26_Pos                    (26U)                             
#define CAN_F8R2_FB26_Msk                    (0x1UL << CAN_F8R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F8R2_FB26                        CAN_F8R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F8R2_FB27_Pos                    (27U)                             
#define CAN_F8R2_FB27_Msk                    (0x1UL << CAN_F8R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F8R2_FB27                        CAN_F8R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F8R2_FB28_Pos                    (28U)                             
#define CAN_F8R2_FB28_Msk                    (0x1UL << CAN_F8R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F8R2_FB28                        CAN_F8R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F8R2_FB29_Pos                    (29U)                             
#define CAN_F8R2_FB29_Msk                    (0x1UL << CAN_F8R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F8R2_FB29                        CAN_F8R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F8R2_FB30_Pos                    (30U)                             
#define CAN_F8R2_FB30_Msk                    (0x1UL << CAN_F8R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F8R2_FB30                        CAN_F8R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F8R2_FB31_Pos                    (31U)                             
#define CAN_F8R2_FB31_Msk                    (0x1UL << CAN_F8R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F8R2_FB31                        CAN_F8R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define CAN_F9R2_FB0_Pos                     (0U)                              
#define CAN_F9R2_FB0_Msk                     (0x1UL << CAN_F9R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F9R2_FB0                         CAN_F9R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F9R2_FB1_Pos                     (1U)                              
#define CAN_F9R2_FB1_Msk                     (0x1UL << CAN_F9R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F9R2_FB1                         CAN_F9R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F9R2_FB2_Pos                     (2U)                              
#define CAN_F9R2_FB2_Msk                     (0x1UL << CAN_F9R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F9R2_FB2                         CAN_F9R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F9R2_FB3_Pos                     (3U)                              
#define CAN_F9R2_FB3_Msk                     (0x1UL << CAN_F9R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F9R2_FB3                         CAN_F9R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F9R2_FB4_Pos                     (4U)                              
#define CAN_F9R2_FB4_Msk                     (0x1UL << CAN_F9R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F9R2_FB4                         CAN_F9R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F9R2_FB5_Pos                     (5U)                              
#define CAN_F9R2_FB5_Msk                     (0x1UL << CAN_F9R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F9R2_FB5                         CAN_F9R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F9R2_FB6_Pos                     (6U)                              
#define CAN_F9R2_FB6_Msk                     (0x1UL << CAN_F9R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F9R2_FB6                         CAN_F9R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F9R2_FB7_Pos                     (7U)                              
#define CAN_F9R2_FB7_Msk                     (0x1UL << CAN_F9R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F9R2_FB7                         CAN_F9R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F9R2_FB8_Pos                     (8U)                              
#define CAN_F9R2_FB8_Msk                     (0x1UL << CAN_F9R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F9R2_FB8                         CAN_F9R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F9R2_FB9_Pos                     (9U)                              
#define CAN_F9R2_FB9_Msk                     (0x1UL << CAN_F9R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F9R2_FB9                         CAN_F9R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F9R2_FB10_Pos                    (10U)                             
#define CAN_F9R2_FB10_Msk                    (0x1UL << CAN_F9R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F9R2_FB10                        CAN_F9R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F9R2_FB11_Pos                    (11U)                             
#define CAN_F9R2_FB11_Msk                    (0x1UL << CAN_F9R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F9R2_FB11                        CAN_F9R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F9R2_FB12_Pos                    (12U)                             
#define CAN_F9R2_FB12_Msk                    (0x1UL << CAN_F9R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F9R2_FB12                        CAN_F9R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F9R2_FB13_Pos                    (13U)                             
#define CAN_F9R2_FB13_Msk                    (0x1UL << CAN_F9R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F9R2_FB13                        CAN_F9R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F9R2_FB14_Pos                    (14U)                             
#define CAN_F9R2_FB14_Msk                    (0x1UL << CAN_F9R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F9R2_FB14                        CAN_F9R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F9R2_FB15_Pos                    (15U)                             
#define CAN_F9R2_FB15_Msk                    (0x1UL << CAN_F9R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F9R2_FB15                        CAN_F9R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F9R2_FB16_Pos                    (16U)                             
#define CAN_F9R2_FB16_Msk                    (0x1UL << CAN_F9R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F9R2_FB16                        CAN_F9R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F9R2_FB17_Pos                    (17U)                             
#define CAN_F9R2_FB17_Msk                    (0x1UL << CAN_F9R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F9R2_FB17                        CAN_F9R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F9R2_FB18_Pos                    (18U)                             
#define CAN_F9R2_FB18_Msk                    (0x1UL << CAN_F9R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F9R2_FB18                        CAN_F9R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F9R2_FB19_Pos                    (19U)                             
#define CAN_F9R2_FB19_Msk                    (0x1UL << CAN_F9R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F9R2_FB19                        CAN_F9R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F9R2_FB20_Pos                    (20U)                             
#define CAN_F9R2_FB20_Msk                    (0x1UL << CAN_F9R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F9R2_FB20                        CAN_F9R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F9R2_FB21_Pos                    (21U)                             
#define CAN_F9R2_FB21_Msk                    (0x1UL << CAN_F9R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F9R2_FB21                        CAN_F9R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F9R2_FB22_Pos                    (22U)                             
#define CAN_F9R2_FB22_Msk                    (0x1UL << CAN_F9R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F9R2_FB22                        CAN_F9R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F9R2_FB23_Pos                    (23U)                             
#define CAN_F9R2_FB23_Msk                    (0x1UL << CAN_F9R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F9R2_FB23                        CAN_F9R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F9R2_FB24_Pos                    (24U)                             
#define CAN_F9R2_FB24_Msk                    (0x1UL << CAN_F9R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F9R2_FB24                        CAN_F9R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F9R2_FB25_Pos                    (25U)                             
#define CAN_F9R2_FB25_Msk                    (0x1UL << CAN_F9R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F9R2_FB25                        CAN_F9R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F9R2_FB26_Pos                    (26U)                             
#define CAN_F9R2_FB26_Msk                    (0x1UL << CAN_F9R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F9R2_FB26                        CAN_F9R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F9R2_FB27_Pos                    (27U)                             
#define CAN_F9R2_FB27_Msk                    (0x1UL << CAN_F9R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F9R2_FB27                        CAN_F9R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F9R2_FB28_Pos                    (28U)                             
#define CAN_F9R2_FB28_Msk                    (0x1UL << CAN_F9R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F9R2_FB28                        CAN_F9R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F9R2_FB29_Pos                    (29U)                             
#define CAN_F9R2_FB29_Msk                    (0x1UL << CAN_F9R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F9R2_FB29                        CAN_F9R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F9R2_FB30_Pos                    (30U)                             
#define CAN_F9R2_FB30_Msk                    (0x1UL << CAN_F9R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F9R2_FB30                        CAN_F9R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F9R2_FB31_Pos                    (31U)                             
#define CAN_F9R2_FB31_Msk                    (0x1UL << CAN_F9R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F9R2_FB31                        CAN_F9R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define CAN_F10R2_FB0_Pos                    (0U)                              
#define CAN_F10R2_FB0_Msk                    (0x1UL << CAN_F10R2_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F10R2_FB0                        CAN_F10R2_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F10R2_FB1_Pos                    (1U)                              
#define CAN_F10R2_FB1_Msk                    (0x1UL << CAN_F10R2_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F10R2_FB1                        CAN_F10R2_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F10R2_FB2_Pos                    (2U)                              
#define CAN_F10R2_FB2_Msk                    (0x1UL << CAN_F10R2_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F10R2_FB2                        CAN_F10R2_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F10R2_FB3_Pos                    (3U)                              
#define CAN_F10R2_FB3_Msk                    (0x1UL << CAN_F10R2_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F10R2_FB3                        CAN_F10R2_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F10R2_FB4_Pos                    (4U)                              
#define CAN_F10R2_FB4_Msk                    (0x1UL << CAN_F10R2_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F10R2_FB4                        CAN_F10R2_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F10R2_FB5_Pos                    (5U)                              
#define CAN_F10R2_FB5_Msk                    (0x1UL << CAN_F10R2_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F10R2_FB5                        CAN_F10R2_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F10R2_FB6_Pos                    (6U)                              
#define CAN_F10R2_FB6_Msk                    (0x1UL << CAN_F10R2_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F10R2_FB6                        CAN_F10R2_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F10R2_FB7_Pos                    (7U)                              
#define CAN_F10R2_FB7_Msk                    (0x1UL << CAN_F10R2_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F10R2_FB7                        CAN_F10R2_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F10R2_FB8_Pos                    (8U)                              
#define CAN_F10R2_FB8_Msk                    (0x1UL << CAN_F10R2_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F10R2_FB8                        CAN_F10R2_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F10R2_FB9_Pos                    (9U)                              
#define CAN_F10R2_FB9_Msk                    (0x1UL << CAN_F10R2_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F10R2_FB9                        CAN_F10R2_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F10R2_FB10_Pos                   (10U)                             
#define CAN_F10R2_FB10_Msk                   (0x1UL << CAN_F10R2_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F10R2_FB10                       CAN_F10R2_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F10R2_FB11_Pos                   (11U)                             
#define CAN_F10R2_FB11_Msk                   (0x1UL << CAN_F10R2_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F10R2_FB11                       CAN_F10R2_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F10R2_FB12_Pos                   (12U)                             
#define CAN_F10R2_FB12_Msk                   (0x1UL << CAN_F10R2_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F10R2_FB12                       CAN_F10R2_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F10R2_FB13_Pos                   (13U)                             
#define CAN_F10R2_FB13_Msk                   (0x1UL << CAN_F10R2_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F10R2_FB13                       CAN_F10R2_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F10R2_FB14_Pos                   (14U)                             
#define CAN_F10R2_FB14_Msk                   (0x1UL << CAN_F10R2_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F10R2_FB14                       CAN_F10R2_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F10R2_FB15_Pos                   (15U)                             
#define CAN_F10R2_FB15_Msk                   (0x1UL << CAN_F10R2_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F10R2_FB15                       CAN_F10R2_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F10R2_FB16_Pos                   (16U)                             
#define CAN_F10R2_FB16_Msk                   (0x1UL << CAN_F10R2_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F10R2_FB16                       CAN_F10R2_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F10R2_FB17_Pos                   (17U)                             
#define CAN_F10R2_FB17_Msk                   (0x1UL << CAN_F10R2_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F10R2_FB17                       CAN_F10R2_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F10R2_FB18_Pos                   (18U)                             
#define CAN_F10R2_FB18_Msk                   (0x1UL << CAN_F10R2_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F10R2_FB18                       CAN_F10R2_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F10R2_FB19_Pos                   (19U)                             
#define CAN_F10R2_FB19_Msk                   (0x1UL << CAN_F10R2_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F10R2_FB19                       CAN_F10R2_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F10R2_FB20_Pos                   (20U)                             
#define CAN_F10R2_FB20_Msk                   (0x1UL << CAN_F10R2_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F10R2_FB20                       CAN_F10R2_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F10R2_FB21_Pos                   (21U)                             
#define CAN_F10R2_FB21_Msk                   (0x1UL << CAN_F10R2_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F10R2_FB21                       CAN_F10R2_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F10R2_FB22_Pos                   (22U)                             
#define CAN_F10R2_FB22_Msk                   (0x1UL << CAN_F10R2_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F10R2_FB22                       CAN_F10R2_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F10R2_FB23_Pos                   (23U)                             
#define CAN_F10R2_FB23_Msk                   (0x1UL << CAN_F10R2_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F10R2_FB23                       CAN_F10R2_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F10R2_FB24_Pos                   (24U)                             
#define CAN_F10R2_FB24_Msk                   (0x1UL << CAN_F10R2_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F10R2_FB24                       CAN_F10R2_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F10R2_FB25_Pos                   (25U)                             
#define CAN_F10R2_FB25_Msk                   (0x1UL << CAN_F10R2_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F10R2_FB25                       CAN_F10R2_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F10R2_FB26_Pos                   (26U)                             
#define CAN_F10R2_FB26_Msk                   (0x1UL << CAN_F10R2_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F10R2_FB26                       CAN_F10R2_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F10R2_FB27_Pos                   (27U)                             
#define CAN_F10R2_FB27_Msk                   (0x1UL << CAN_F10R2_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F10R2_FB27                       CAN_F10R2_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F10R2_FB28_Pos                   (28U)                             
#define CAN_F10R2_FB28_Msk                   (0x1UL << CAN_F10R2_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F10R2_FB28                       CAN_F10R2_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F10R2_FB29_Pos                   (29U)                             
#define CAN_F10R2_FB29_Msk                   (0x1UL << CAN_F10R2_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F10R2_FB29                       CAN_F10R2_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F10R2_FB30_Pos                   (30U)                             
#define CAN_F10R2_FB30_Msk                   (0x1UL << CAN_F10R2_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F10R2_FB30                       CAN_F10R2_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F10R2_FB31_Pos                   (31U)                             
#define CAN_F10R2_FB31_Msk                   (0x1UL << CAN_F10R2_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F10R2_FB31                       CAN_F10R2_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define CAN_F11R2_FB0_Pos                    (0U)                              
#define CAN_F11R2_FB0_Msk                    (0x1UL << CAN_F11R2_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F11R2_FB0                        CAN_F11R2_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F11R2_FB1_Pos                    (1U)                              
#define CAN_F11R2_FB1_Msk                    (0x1UL << CAN_F11R2_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F11R2_FB1                        CAN_F11R2_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F11R2_FB2_Pos                    (2U)                              
#define CAN_F11R2_FB2_Msk                    (0x1UL << CAN_F11R2_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F11R2_FB2                        CAN_F11R2_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F11R2_FB3_Pos                    (3U)                              
#define CAN_F11R2_FB3_Msk                    (0x1UL << CAN_F11R2_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F11R2_FB3                        CAN_F11R2_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F11R2_FB4_Pos                    (4U)                              
#define CAN_F11R2_FB4_Msk                    (0x1UL << CAN_F11R2_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F11R2_FB4                        CAN_F11R2_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F11R2_FB5_Pos                    (5U)                              
#define CAN_F11R2_FB5_Msk                    (0x1UL << CAN_F11R2_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F11R2_FB5                        CAN_F11R2_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F11R2_FB6_Pos                    (6U)                              
#define CAN_F11R2_FB6_Msk                    (0x1UL << CAN_F11R2_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F11R2_FB6                        CAN_F11R2_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F11R2_FB7_Pos                    (7U)                              
#define CAN_F11R2_FB7_Msk                    (0x1UL << CAN_F11R2_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F11R2_FB7                        CAN_F11R2_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F11R2_FB8_Pos                    (8U)                              
#define CAN_F11R2_FB8_Msk                    (0x1UL << CAN_F11R2_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F11R2_FB8                        CAN_F11R2_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F11R2_FB9_Pos                    (9U)                              
#define CAN_F11R2_FB9_Msk                    (0x1UL << CAN_F11R2_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F11R2_FB9                        CAN_F11R2_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F11R2_FB10_Pos                   (10U)                             
#define CAN_F11R2_FB10_Msk                   (0x1UL << CAN_F11R2_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F11R2_FB10                       CAN_F11R2_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F11R2_FB11_Pos                   (11U)                             
#define CAN_F11R2_FB11_Msk                   (0x1UL << CAN_F11R2_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F11R2_FB11                       CAN_F11R2_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F11R2_FB12_Pos                   (12U)                             
#define CAN_F11R2_FB12_Msk                   (0x1UL << CAN_F11R2_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F11R2_FB12                       CAN_F11R2_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F11R2_FB13_Pos                   (13U)                             
#define CAN_F11R2_FB13_Msk                   (0x1UL << CAN_F11R2_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F11R2_FB13                       CAN_F11R2_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F11R2_FB14_Pos                   (14U)                             
#define CAN_F11R2_FB14_Msk                   (0x1UL << CAN_F11R2_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F11R2_FB14                       CAN_F11R2_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F11R2_FB15_Pos                   (15U)                             
#define CAN_F11R2_FB15_Msk                   (0x1UL << CAN_F11R2_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F11R2_FB15                       CAN_F11R2_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F11R2_FB16_Pos                   (16U)                             
#define CAN_F11R2_FB16_Msk                   (0x1UL << CAN_F11R2_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F11R2_FB16                       CAN_F11R2_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F11R2_FB17_Pos                   (17U)                             
#define CAN_F11R2_FB17_Msk                   (0x1UL << CAN_F11R2_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F11R2_FB17                       CAN_F11R2_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F11R2_FB18_Pos                   (18U)                             
#define CAN_F11R2_FB18_Msk                   (0x1UL << CAN_F11R2_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F11R2_FB18                       CAN_F11R2_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F11R2_FB19_Pos                   (19U)                             
#define CAN_F11R2_FB19_Msk                   (0x1UL << CAN_F11R2_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F11R2_FB19                       CAN_F11R2_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F11R2_FB20_Pos                   (20U)                             
#define CAN_F11R2_FB20_Msk                   (0x1UL << CAN_F11R2_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F11R2_FB20                       CAN_F11R2_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F11R2_FB21_Pos                   (21U)                             
#define CAN_F11R2_FB21_Msk                   (0x1UL << CAN_F11R2_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F11R2_FB21                       CAN_F11R2_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F11R2_FB22_Pos                   (22U)                             
#define CAN_F11R2_FB22_Msk                   (0x1UL << CAN_F11R2_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F11R2_FB22                       CAN_F11R2_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F11R2_FB23_Pos                   (23U)                             
#define CAN_F11R2_FB23_Msk                   (0x1UL << CAN_F11R2_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F11R2_FB23                       CAN_F11R2_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F11R2_FB24_Pos                   (24U)                             
#define CAN_F11R2_FB24_Msk                   (0x1UL << CAN_F11R2_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F11R2_FB24                       CAN_F11R2_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F11R2_FB25_Pos                   (25U)                             
#define CAN_F11R2_FB25_Msk                   (0x1UL << CAN_F11R2_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F11R2_FB25                       CAN_F11R2_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F11R2_FB26_Pos                   (26U)                             
#define CAN_F11R2_FB26_Msk                   (0x1UL << CAN_F11R2_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F11R2_FB26                       CAN_F11R2_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F11R2_FB27_Pos                   (27U)                             
#define CAN_F11R2_FB27_Msk                   (0x1UL << CAN_F11R2_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F11R2_FB27                       CAN_F11R2_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F11R2_FB28_Pos                   (28U)                             
#define CAN_F11R2_FB28_Msk                   (0x1UL << CAN_F11R2_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F11R2_FB28                       CAN_F11R2_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F11R2_FB29_Pos                   (29U)                             
#define CAN_F11R2_FB29_Msk                   (0x1UL << CAN_F11R2_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F11R2_FB29                       CAN_F11R2_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F11R2_FB30_Pos                   (30U)                             
#define CAN_F11R2_FB30_Msk                   (0x1UL << CAN_F11R2_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F11R2_FB30                       CAN_F11R2_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F11R2_FB31_Pos                   (31U)                             
#define CAN_F11R2_FB31_Msk                   (0x1UL << CAN_F11R2_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F11R2_FB31                       CAN_F11R2_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define CAN_F12R2_FB0_Pos                    (0U)                              
#define CAN_F12R2_FB0_Msk                    (0x1UL << CAN_F12R2_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F12R2_FB0                        CAN_F12R2_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F12R2_FB1_Pos                    (1U)                              
#define CAN_F12R2_FB1_Msk                    (0x1UL << CAN_F12R2_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F12R2_FB1                        CAN_F12R2_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F12R2_FB2_Pos                    (2U)                              
#define CAN_F12R2_FB2_Msk                    (0x1UL << CAN_F12R2_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F12R2_FB2                        CAN_F12R2_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F12R2_FB3_Pos                    (3U)                              
#define CAN_F12R2_FB3_Msk                    (0x1UL << CAN_F12R2_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F12R2_FB3                        CAN_F12R2_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F12R2_FB4_Pos                    (4U)                              
#define CAN_F12R2_FB4_Msk                    (0x1UL << CAN_F12R2_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F12R2_FB4                        CAN_F12R2_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F12R2_FB5_Pos                    (5U)                              
#define CAN_F12R2_FB5_Msk                    (0x1UL << CAN_F12R2_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F12R2_FB5                        CAN_F12R2_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F12R2_FB6_Pos                    (6U)                              
#define CAN_F12R2_FB6_Msk                    (0x1UL << CAN_F12R2_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F12R2_FB6                        CAN_F12R2_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F12R2_FB7_Pos                    (7U)                              
#define CAN_F12R2_FB7_Msk                    (0x1UL << CAN_F12R2_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F12R2_FB7                        CAN_F12R2_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F12R2_FB8_Pos                    (8U)                              
#define CAN_F12R2_FB8_Msk                    (0x1UL << CAN_F12R2_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F12R2_FB8                        CAN_F12R2_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F12R2_FB9_Pos                    (9U)                              
#define CAN_F12R2_FB9_Msk                    (0x1UL << CAN_F12R2_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F12R2_FB9                        CAN_F12R2_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F12R2_FB10_Pos                   (10U)                             
#define CAN_F12R2_FB10_Msk                   (0x1UL << CAN_F12R2_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F12R2_FB10                       CAN_F12R2_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F12R2_FB11_Pos                   (11U)                             
#define CAN_F12R2_FB11_Msk                   (0x1UL << CAN_F12R2_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F12R2_FB11                       CAN_F12R2_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F12R2_FB12_Pos                   (12U)                             
#define CAN_F12R2_FB12_Msk                   (0x1UL << CAN_F12R2_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F12R2_FB12                       CAN_F12R2_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F12R2_FB13_Pos                   (13U)                             
#define CAN_F12R2_FB13_Msk                   (0x1UL << CAN_F12R2_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F12R2_FB13                       CAN_F12R2_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F12R2_FB14_Pos                   (14U)                             
#define CAN_F12R2_FB14_Msk                   (0x1UL << CAN_F12R2_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F12R2_FB14                       CAN_F12R2_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F12R2_FB15_Pos                   (15U)                             
#define CAN_F12R2_FB15_Msk                   (0x1UL << CAN_F12R2_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F12R2_FB15                       CAN_F12R2_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F12R2_FB16_Pos                   (16U)                             
#define CAN_F12R2_FB16_Msk                   (0x1UL << CAN_F12R2_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F12R2_FB16                       CAN_F12R2_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F12R2_FB17_Pos                   (17U)                             
#define CAN_F12R2_FB17_Msk                   (0x1UL << CAN_F12R2_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F12R2_FB17                       CAN_F12R2_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F12R2_FB18_Pos                   (18U)                             
#define CAN_F12R2_FB18_Msk                   (0x1UL << CAN_F12R2_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F12R2_FB18                       CAN_F12R2_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F12R2_FB19_Pos                   (19U)                             
#define CAN_F12R2_FB19_Msk                   (0x1UL << CAN_F12R2_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F12R2_FB19                       CAN_F12R2_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F12R2_FB20_Pos                   (20U)                             
#define CAN_F12R2_FB20_Msk                   (0x1UL << CAN_F12R2_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F12R2_FB20                       CAN_F12R2_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F12R2_FB21_Pos                   (21U)                             
#define CAN_F12R2_FB21_Msk                   (0x1UL << CAN_F12R2_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F12R2_FB21                       CAN_F12R2_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F12R2_FB22_Pos                   (22U)                             
#define CAN_F12R2_FB22_Msk                   (0x1UL << CAN_F12R2_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F12R2_FB22                       CAN_F12R2_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F12R2_FB23_Pos                   (23U)                             
#define CAN_F12R2_FB23_Msk                   (0x1UL << CAN_F12R2_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F12R2_FB23                       CAN_F12R2_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F12R2_FB24_Pos                   (24U)                             
#define CAN_F12R2_FB24_Msk                   (0x1UL << CAN_F12R2_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F12R2_FB24                       CAN_F12R2_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F12R2_FB25_Pos                   (25U)                             
#define CAN_F12R2_FB25_Msk                   (0x1UL << CAN_F12R2_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F12R2_FB25                       CAN_F12R2_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F12R2_FB26_Pos                   (26U)                             
#define CAN_F12R2_FB26_Msk                   (0x1UL << CAN_F12R2_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F12R2_FB26                       CAN_F12R2_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F12R2_FB27_Pos                   (27U)                             
#define CAN_F12R2_FB27_Msk                   (0x1UL << CAN_F12R2_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F12R2_FB27                       CAN_F12R2_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F12R2_FB28_Pos                   (28U)                             
#define CAN_F12R2_FB28_Msk                   (0x1UL << CAN_F12R2_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F12R2_FB28                       CAN_F12R2_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F12R2_FB29_Pos                   (29U)                             
#define CAN_F12R2_FB29_Msk                   (0x1UL << CAN_F12R2_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F12R2_FB29                       CAN_F12R2_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F12R2_FB30_Pos                   (30U)                             
#define CAN_F12R2_FB30_Msk                   (0x1UL << CAN_F12R2_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F12R2_FB30                       CAN_F12R2_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F12R2_FB31_Pos                   (31U)                             
#define CAN_F12R2_FB31_Msk                   (0x1UL << CAN_F12R2_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F12R2_FB31                       CAN_F12R2_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define CAN_F13R2_FB0_Pos                    (0U)                              
#define CAN_F13R2_FB0_Msk                    (0x1UL << CAN_F13R2_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F13R2_FB0                        CAN_F13R2_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F13R2_FB1_Pos                    (1U)                              
#define CAN_F13R2_FB1_Msk                    (0x1UL << CAN_F13R2_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F13R2_FB1                        CAN_F13R2_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F13R2_FB2_Pos                    (2U)                              
#define CAN_F13R2_FB2_Msk                    (0x1UL << CAN_F13R2_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F13R2_FB2                        CAN_F13R2_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F13R2_FB3_Pos                    (3U)                              
#define CAN_F13R2_FB3_Msk                    (0x1UL << CAN_F13R2_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F13R2_FB3                        CAN_F13R2_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F13R2_FB4_Pos                    (4U)                              
#define CAN_F13R2_FB4_Msk                    (0x1UL << CAN_F13R2_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F13R2_FB4                        CAN_F13R2_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F13R2_FB5_Pos                    (5U)                              
#define CAN_F13R2_FB5_Msk                    (0x1UL << CAN_F13R2_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F13R2_FB5                        CAN_F13R2_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F13R2_FB6_Pos                    (6U)                              
#define CAN_F13R2_FB6_Msk                    (0x1UL << CAN_F13R2_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F13R2_FB6                        CAN_F13R2_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F13R2_FB7_Pos                    (7U)                              
#define CAN_F13R2_FB7_Msk                    (0x1UL << CAN_F13R2_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F13R2_FB7                        CAN_F13R2_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F13R2_FB8_Pos                    (8U)                              
#define CAN_F13R2_FB8_Msk                    (0x1UL << CAN_F13R2_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F13R2_FB8                        CAN_F13R2_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F13R2_FB9_Pos                    (9U)                              
#define CAN_F13R2_FB9_Msk                    (0x1UL << CAN_F13R2_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F13R2_FB9                        CAN_F13R2_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F13R2_FB10_Pos                   (10U)                             
#define CAN_F13R2_FB10_Msk                   (0x1UL << CAN_F13R2_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F13R2_FB10                       CAN_F13R2_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F13R2_FB11_Pos                   (11U)                             
#define CAN_F13R2_FB11_Msk                   (0x1UL << CAN_F13R2_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F13R2_FB11                       CAN_F13R2_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F13R2_FB12_Pos                   (12U)                             
#define CAN_F13R2_FB12_Msk                   (0x1UL << CAN_F13R2_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F13R2_FB12                       CAN_F13R2_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F13R2_FB13_Pos                   (13U)                             
#define CAN_F13R2_FB13_Msk                   (0x1UL << CAN_F13R2_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F13R2_FB13                       CAN_F13R2_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F13R2_FB14_Pos                   (14U)                             
#define CAN_F13R2_FB14_Msk                   (0x1UL << CAN_F13R2_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F13R2_FB14                       CAN_F13R2_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F13R2_FB15_Pos                   (15U)                             
#define CAN_F13R2_FB15_Msk                   (0x1UL << CAN_F13R2_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F13R2_FB15                       CAN_F13R2_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F13R2_FB16_Pos                   (16U)                             
#define CAN_F13R2_FB16_Msk                   (0x1UL << CAN_F13R2_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F13R2_FB16                       CAN_F13R2_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F13R2_FB17_Pos                   (17U)                             
#define CAN_F13R2_FB17_Msk                   (0x1UL << CAN_F13R2_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F13R2_FB17                       CAN_F13R2_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F13R2_FB18_Pos                   (18U)                             
#define CAN_F13R2_FB18_Msk                   (0x1UL << CAN_F13R2_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F13R2_FB18                       CAN_F13R2_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F13R2_FB19_Pos                   (19U)                             
#define CAN_F13R2_FB19_Msk                   (0x1UL << CAN_F13R2_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F13R2_FB19                       CAN_F13R2_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F13R2_FB20_Pos                   (20U)                             
#define CAN_F13R2_FB20_Msk                   (0x1UL << CAN_F13R2_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F13R2_FB20                       CAN_F13R2_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F13R2_FB21_Pos                   (21U)                             
#define CAN_F13R2_FB21_Msk                   (0x1UL << CAN_F13R2_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F13R2_FB21                       CAN_F13R2_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F13R2_FB22_Pos                   (22U)                             
#define CAN_F13R2_FB22_Msk                   (0x1UL << CAN_F13R2_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F13R2_FB22                       CAN_F13R2_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F13R2_FB23_Pos                   (23U)                             
#define CAN_F13R2_FB23_Msk                   (0x1UL << CAN_F13R2_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F13R2_FB23                       CAN_F13R2_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F13R2_FB24_Pos                   (24U)                             
#define CAN_F13R2_FB24_Msk                   (0x1UL << CAN_F13R2_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F13R2_FB24                       CAN_F13R2_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F13R2_FB25_Pos                   (25U)                             
#define CAN_F13R2_FB25_Msk                   (0x1UL << CAN_F13R2_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F13R2_FB25                       CAN_F13R2_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F13R2_FB26_Pos                   (26U)                             
#define CAN_F13R2_FB26_Msk                   (0x1UL << CAN_F13R2_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F13R2_FB26                       CAN_F13R2_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F13R2_FB27_Pos                   (27U)                             
#define CAN_F13R2_FB27_Msk                   (0x1UL << CAN_F13R2_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F13R2_FB27                       CAN_F13R2_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F13R2_FB28_Pos                   (28U)                             
#define CAN_F13R2_FB28_Msk                   (0x1UL << CAN_F13R2_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F13R2_FB28                       CAN_F13R2_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F13R2_FB29_Pos                   (29U)                             
#define CAN_F13R2_FB29_Msk                   (0x1UL << CAN_F13R2_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F13R2_FB29                       CAN_F13R2_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F13R2_FB30_Pos                   (30U)                             
#define CAN_F13R2_FB30_Msk                   (0x1UL << CAN_F13R2_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F13R2_FB30                       CAN_F13R2_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F13R2_FB31_Pos                   (31U)                             
#define CAN_F13R2_FB31_Msk                   (0x1UL << CAN_F13R2_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F13R2_FB31                       CAN_F13R2_FB31_Msk                /*!< Filter bit 31 */

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface                         */
/*                                                                            */
/******************************************************************************/

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

#define SPI_I2SCFGR_I2SMOD_Pos              (11U)                              
#define SPI_I2SCFGR_I2SMOD_Msk              (0x1UL << SPI_I2SCFGR_I2SMOD_Pos)   /*!< 0x00000800 */
#define SPI_I2SCFGR_I2SMOD                  SPI_I2SCFGR_I2SMOD_Msk             /*!< I2S mode selection */

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface                    */
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
#define I2C_OAR1_ADD1_7                     0x000000FEU             /*!< Interface Address */
#define I2C_OAR1_ADD8_9                     0x00000300U             /*!< Interface Address */

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
#define I2C_DR_DR_Pos             (0U)                                         
#define I2C_DR_DR_Msk             (0xFFUL << I2C_DR_DR_Pos)                     /*!< 0x000000FF */
#define I2C_DR_DR                 I2C_DR_DR_Msk                                /*!< 8-bit Data Register         */

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
#define DBGMCU_CR_DBG_CAN1_STOP_Pos         (14U)                              
#define DBGMCU_CR_DBG_CAN1_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_CAN1_STOP_Pos) /*!< 0x00004000 */
#define DBGMCU_CR_DBG_CAN1_STOP             DBGMCU_CR_DBG_CAN1_STOP_Msk        /*!< Debug CAN1 stopped when Core is halted */
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Pos (15U)                             
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Msk (0x1UL << DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Pos) /*!< 0x00008000 */
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT    DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Msk /*!< SMBUS timeout mode stopped when Core is halted */

/******************************************************************************/
/*                                                                            */
/*                      FLASH and Option Bytes Registers                      */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for FLASH_ACR register  ******************/
#define FLASH_ACR_LATENCY_Pos               (0U)                               
#define FLASH_ACR_LATENCY_Msk               (0x7UL << FLASH_ACR_LATENCY_Pos)    /*!< 0x00000007 */
#define FLASH_ACR_LATENCY                   FLASH_ACR_LATENCY_Msk              /*!< LATENCY[2:0] bits (Latency) */
#define FLASH_ACR_LATENCY_0                 (0x1UL << FLASH_ACR_LATENCY_Pos)    /*!< 0x00000001 */
#define FLASH_ACR_LATENCY_1                 (0x2UL << FLASH_ACR_LATENCY_Pos)    /*!< 0x00000002 */
#define FLASH_ACR_LATENCY_2                 (0x4UL << FLASH_ACR_LATENCY_Pos)    /*!< 0x00000004 */

#define FLASH_ACR_HLFCYA_Pos                (3U)                               
#define FLASH_ACR_HLFCYA_Msk                (0x1UL << FLASH_ACR_HLFCYA_Pos)     /*!< 0x00000008 */
#define FLASH_ACR_HLFCYA                    FLASH_ACR_HLFCYA_Msk               /*!< Flash Half Cycle Access Enable */
#define FLASH_ACR_PRFTBE_Pos                (4U)                               
#define FLASH_ACR_PRFTBE_Msk                (0x1UL << FLASH_ACR_PRFTBE_Pos)     /*!< 0x00000010 */
#define FLASH_ACR_PRFTBE                    FLASH_ACR_PRFTBE_Msk               /*!< Prefetch Buffer Enable */
#define FLASH_ACR_PRFTBS_Pos                (5U)                               
#define FLASH_ACR_PRFTBS_Msk                (0x1UL << FLASH_ACR_PRFTBS_Pos)     /*!< 0x00000020 */
#define FLASH_ACR_PRFTBS                    FLASH_ACR_PRFTBS_Msk               /*!< Prefetch Buffer Status */

/******************  Bit definition for FLASH_KEYR register  ******************/
#define FLASH_KEYR_FKEYR_Pos                (0U)                               
#define FLASH_KEYR_FKEYR_Msk                (0xFFFFFFFFUL << FLASH_KEYR_FKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_KEYR_FKEYR                    FLASH_KEYR_FKEYR_Msk               /*!< FPEC Key */

#define RDP_KEY_Pos                         (0U)                               
#define RDP_KEY_Msk                         (0xA5UL << RDP_KEY_Pos)             /*!< 0x000000A5 */
#define RDP_KEY                             RDP_KEY_Msk                        /*!< RDP Key */
#define FLASH_KEY1_Pos                      (0U)                               
#define FLASH_KEY1_Msk                      (0x45670123UL << FLASH_KEY1_Pos)    /*!< 0x45670123 */
#define FLASH_KEY1                          FLASH_KEY1_Msk                     /*!< FPEC Key1 */
#define FLASH_KEY2_Pos                      (0U)                               
#define FLASH_KEY2_Msk                      (0xCDEF89ABUL << FLASH_KEY2_Pos)    /*!< 0xCDEF89AB */
#define FLASH_KEY2                          FLASH_KEY2_Msk                     /*!< FPEC Key2 */

/*****************  Bit definition for FLASH_OPTKEYR register  ****************/
#define FLASH_OPTKEYR_OPTKEYR_Pos           (0U)                               
#define FLASH_OPTKEYR_OPTKEYR_Msk           (0xFFFFFFFFUL << FLASH_OPTKEYR_OPTKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_OPTKEYR_OPTKEYR               FLASH_OPTKEYR_OPTKEYR_Msk          /*!< Option Byte Key */

#define  FLASH_OPTKEY1                       FLASH_KEY1                    /*!< Option Byte Key1 */
#define  FLASH_OPTKEY2                       FLASH_KEY2                    /*!< Option Byte Key2 */

/******************  Bit definition for FLASH_SR register  ********************/
#define FLASH_SR_BSY_Pos                    (0U)                               
#define FLASH_SR_BSY_Msk                    (0x1UL << FLASH_SR_BSY_Pos)         /*!< 0x00000001 */
#define FLASH_SR_BSY                        FLASH_SR_BSY_Msk                   /*!< Busy */
#define FLASH_SR_PGERR_Pos                  (2U)                               
#define FLASH_SR_PGERR_Msk                  (0x1UL << FLASH_SR_PGERR_Pos)       /*!< 0x00000004 */
#define FLASH_SR_PGERR                      FLASH_SR_PGERR_Msk                 /*!< Programming Error */
#define FLASH_SR_WRPRTERR_Pos               (4U)                               
#define FLASH_SR_WRPRTERR_Msk               (0x1UL << FLASH_SR_WRPRTERR_Pos)    /*!< 0x00000010 */
#define FLASH_SR_WRPRTERR                   FLASH_SR_WRPRTERR_Msk              /*!< Write Protection Error */
#define FLASH_SR_EOP_Pos                    (5U)                               
#define FLASH_SR_EOP_Msk                    (0x1UL << FLASH_SR_EOP_Pos)         /*!< 0x00000020 */
#define FLASH_SR_EOP                        FLASH_SR_EOP_Msk                   /*!< End of operation */

/*******************  Bit definition for FLASH_CR register  *******************/
#define FLASH_CR_PG_Pos                     (0U)                               
#define FLASH_CR_PG_Msk                     (0x1UL << FLASH_CR_PG_Pos)          /*!< 0x00000001 */
#define FLASH_CR_PG                         FLASH_CR_PG_Msk                    /*!< Programming */
#define FLASH_CR_PER_Pos                    (1U)                               
#define FLASH_CR_PER_Msk                    (0x1UL << FLASH_CR_PER_Pos)         /*!< 0x00000002 */
#define FLASH_CR_PER                        FLASH_CR_PER_Msk                   /*!< Page Erase */
#define FLASH_CR_MER_Pos                    (2U)                               
#define FLASH_CR_MER_Msk                    (0x1UL << FLASH_CR_MER_Pos)         /*!< 0x00000004 */
#define FLASH_CR_MER                        FLASH_CR_MER_Msk                   /*!< Mass Erase */
#define FLASH_CR_OPTPG_Pos                  (4U)                               
#define FLASH_CR_OPTPG_Msk                  (0x1UL << FLASH_CR_OPTPG_Pos)       /*!< 0x00000010 */
#define FLASH_CR_OPTPG                      FLASH_CR_OPTPG_Msk                 /*!< Option Byte Programming */
#define FLASH_CR_OPTER_Pos                  (5U)                               
#define FLASH_CR_OPTER_Msk                  (0x1UL << FLASH_CR_OPTER_Pos)       /*!< 0x00000020 */
#define FLASH_CR_OPTER                      FLASH_CR_OPTER_Msk                 /*!< Option Byte Erase */
#define FLASH_CR_STRT_Pos                   (6U)                               
#define FLASH_CR_STRT_Msk                   (0x1UL << FLASH_CR_STRT_Pos)        /*!< 0x00000040 */
#define FLASH_CR_STRT                       FLASH_CR_STRT_Msk                  /*!< Start */
#define FLASH_CR_LOCK_Pos                   (7U)                               
#define FLASH_CR_LOCK_Msk                   (0x1UL << FLASH_CR_LOCK_Pos)        /*!< 0x00000080 */
#define FLASH_CR_LOCK                       FLASH_CR_LOCK_Msk                  /*!< Lock */
#define FLASH_CR_OPTWRE_Pos                 (9U)                               
#define FLASH_CR_OPTWRE_Msk                 (0x1UL << FLASH_CR_OPTWRE_Pos)      /*!< 0x00000200 */
#define FLASH_CR_OPTWRE                     FLASH_CR_OPTWRE_Msk                /*!< Option Bytes Write Enable */
#define FLASH_CR_ERRIE_Pos                  (10U)                              
#define FLASH_CR_ERRIE_Msk                  (0x1UL << FLASH_CR_ERRIE_Pos)       /*!< 0x00000400 */
#define FLASH_CR_ERRIE                      FLASH_CR_ERRIE_Msk                 /*!< Error Interrupt Enable */
#define FLASH_CR_EOPIE_Pos                  (12U)                              
#define FLASH_CR_EOPIE_Msk                  (0x1UL << FLASH_CR_EOPIE_Pos)       /*!< 0x00001000 */
#define FLASH_CR_EOPIE                      FLASH_CR_EOPIE_Msk                 /*!< End of operation interrupt enable */

/*******************  Bit definition for FLASH_AR register  *******************/
#define FLASH_AR_FAR_Pos                    (0U)                               
#define FLASH_AR_FAR_Msk                    (0xFFFFFFFFUL << FLASH_AR_FAR_Pos)  /*!< 0xFFFFFFFF */
#define FLASH_AR_FAR                        FLASH_AR_FAR_Msk                   /*!< Flash Address */

/******************  Bit definition for FLASH_OBR register  *******************/
#define FLASH_OBR_OPTERR_Pos                (0U)                               
#define FLASH_OBR_OPTERR_Msk                (0x1UL << FLASH_OBR_OPTERR_Pos)     /*!< 0x00000001 */
#define FLASH_OBR_OPTERR                    FLASH_OBR_OPTERR_Msk               /*!< Option Byte Error */
#define FLASH_OBR_RDPRT_Pos                 (1U)                               
#define FLASH_OBR_RDPRT_Msk                 (0x1UL << FLASH_OBR_RDPRT_Pos)      /*!< 0x00000002 */
#define FLASH_OBR_RDPRT                     FLASH_OBR_RDPRT_Msk                /*!< Read protection */

#define FLASH_OBR_IWDG_SW_Pos               (2U)                               
#define FLASH_OBR_IWDG_SW_Msk               (0x1UL << FLASH_OBR_IWDG_SW_Pos)    /*!< 0x00000004 */
#define FLASH_OBR_IWDG_SW                   FLASH_OBR_IWDG_SW_Msk              /*!< IWDG SW */
#define FLASH_OBR_nRST_STOP_Pos             (3U)                               
#define FLASH_OBR_nRST_STOP_Msk             (0x1UL << FLASH_OBR_nRST_STOP_Pos)  /*!< 0x00000008 */
#define FLASH_OBR_nRST_STOP                 FLASH_OBR_nRST_STOP_Msk            /*!< nRST_STOP */
#define FLASH_OBR_nRST_STDBY_Pos            (4U)                               
#define FLASH_OBR_nRST_STDBY_Msk            (0x1UL << FLASH_OBR_nRST_STDBY_Pos) /*!< 0x00000010 */
#define FLASH_OBR_nRST_STDBY                FLASH_OBR_nRST_STDBY_Msk           /*!< nRST_STDBY */
#define FLASH_OBR_USER_Pos                  (2U)                               
#define FLASH_OBR_USER_Msk                  (0x7UL << FLASH_OBR_USER_Pos)       /*!< 0x0000001C */
#define FLASH_OBR_USER                      FLASH_OBR_USER_Msk                 /*!< User Option Bytes */
#define FLASH_OBR_DATA0_Pos                 (10U)                              
#define FLASH_OBR_DATA0_Msk                 (0xFFUL << FLASH_OBR_DATA0_Pos)     /*!< 0x0003FC00 */
#define FLASH_OBR_DATA0                     FLASH_OBR_DATA0_Msk                /*!< Data0 */
#define FLASH_OBR_DATA1_Pos                 (18U)                              
#define FLASH_OBR_DATA1_Msk                 (0xFFUL << FLASH_OBR_DATA1_Pos)     /*!< 0x03FC0000 */
#define FLASH_OBR_DATA1                     FLASH_OBR_DATA1_Msk                /*!< Data1 */

/******************  Bit definition for FLASH_WRPR register  ******************/
#define FLASH_WRPR_WRP_Pos                  (0U)                               
#define FLASH_WRPR_WRP_Msk                  (0xFFFFFFFFUL << FLASH_WRPR_WRP_Pos) /*!< 0xFFFFFFFF */
#define FLASH_WRPR_WRP                      FLASH_WRPR_WRP_Msk                 /*!< Write Protect */

/*----------------------------------------------------------------------------*/

/******************  Bit definition for FLASH_RDP register  *******************/
#define FLASH_RDP_RDP_Pos                   (0U)                               
#define FLASH_RDP_RDP_Msk                   (0xFFUL << FLASH_RDP_RDP_Pos)       /*!< 0x000000FF */
#define FLASH_RDP_RDP                       FLASH_RDP_RDP_Msk                  /*!< Read protection option byte */
#define FLASH_RDP_nRDP_Pos                  (8U)                               
#define FLASH_RDP_nRDP_Msk                  (0xFFUL << FLASH_RDP_nRDP_Pos)      /*!< 0x0000FF00 */
#define FLASH_RDP_nRDP                      FLASH_RDP_nRDP_Msk                 /*!< Read protection complemented option byte */

/******************  Bit definition for FLASH_USER register  ******************/
#define FLASH_USER_USER_Pos                 (16U)                              
#define FLASH_USER_USER_Msk                 (0xFFUL << FLASH_USER_USER_Pos)     /*!< 0x00FF0000 */
#define FLASH_USER_USER                     FLASH_USER_USER_Msk                /*!< User option byte */
#define FLASH_USER_nUSER_Pos                (24U)                              
#define FLASH_USER_nUSER_Msk                (0xFFUL << FLASH_USER_nUSER_Pos)    /*!< 0xFF000000 */
#define FLASH_USER_nUSER                    FLASH_USER_nUSER_Msk               /*!< User complemented option byte */

/******************  Bit definition for FLASH_Data0 register  *****************/
#define FLASH_DATA0_DATA0_Pos               (0U)                               
#define FLASH_DATA0_DATA0_Msk               (0xFFUL << FLASH_DATA0_DATA0_Pos)   /*!< 0x000000FF */
#define FLASH_DATA0_DATA0                   FLASH_DATA0_DATA0_Msk              /*!< User data storage option byte */
#define FLASH_DATA0_nDATA0_Pos              (8U)                               
#define FLASH_DATA0_nDATA0_Msk              (0xFFUL << FLASH_DATA0_nDATA0_Pos)  /*!< 0x0000FF00 */
#define FLASH_DATA0_nDATA0                  FLASH_DATA0_nDATA0_Msk             /*!< User data storage complemented option byte */

/******************  Bit definition for FLASH_Data1 register  *****************/
#define FLASH_DATA1_DATA1_Pos               (16U)                              
#define FLASH_DATA1_DATA1_Msk               (0xFFUL << FLASH_DATA1_DATA1_Pos)   /*!< 0x00FF0000 */
#define FLASH_DATA1_DATA1                   FLASH_DATA1_DATA1_Msk              /*!< User data storage option byte */
#define FLASH_DATA1_nDATA1_Pos              (24U)                              
#define FLASH_DATA1_nDATA1_Msk              (0xFFUL << FLASH_DATA1_nDATA1_Pos)  /*!< 0xFF000000 */
#define FLASH_DATA1_nDATA1                  FLASH_DATA1_nDATA1_Msk             /*!< User data storage complemented option byte */

/******************  Bit definition for FLASH_WRP0 register  ******************/
#define FLASH_WRP0_WRP0_Pos                 (0U)                               
#define FLASH_WRP0_WRP0_Msk                 (0xFFUL << FLASH_WRP0_WRP0_Pos)     /*!< 0x000000FF */
#define FLASH_WRP0_WRP0                     FLASH_WRP0_WRP0_Msk                /*!< Flash memory write protection option bytes */
#define FLASH_WRP0_nWRP0_Pos                (8U)                               
#define FLASH_WRP0_nWRP0_Msk                (0xFFUL << FLASH_WRP0_nWRP0_Pos)    /*!< 0x0000FF00 */
#define FLASH_WRP0_nWRP0                    FLASH_WRP0_nWRP0_Msk               /*!< Flash memory write protection complemented option bytes */



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
                                       ((INSTANCE) == ADC2))

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC12_COMMON)

#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_DMA_CAPABILITY_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

/****************************** CAN Instances *********************************/    
#define IS_CAN_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CAN1)

/****************************** CRC Instances *********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/****************************** DAC Instances *********************************/

/****************************** DMA Instances *********************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Channel1) || \
                                       ((INSTANCE) == DMA1_Channel2) || \
                                       ((INSTANCE) == DMA1_Channel3) || \
                                       ((INSTANCE) == DMA1_Channel4) || \
                                       ((INSTANCE) == DMA1_Channel5) || \
                                       ((INSTANCE) == DMA1_Channel6) || \
                                       ((INSTANCE) == DMA1_Channel7))
  
/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOD))

/**************************** GPIO Alternate Function Instances ***************/
#define IS_GPIO_AF_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** GPIO Lock Instances *****************************/
#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) ((INSTANCE) == I2C1)

/******************************* SMBUS Instances ******************************/
#define IS_SMBUS_ALL_INSTANCE         IS_I2C_ALL_INSTANCE

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SPI1)

/****************************** START TIM Instances ***************************/
/****************************** TIM Instances *********************************/
#define IS_TIM_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_ADVANCED_INSTANCE(INSTANCE) ((INSTANCE) == TIM1)

#define IS_TIM_CC1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CC2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CC3_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CC4_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_XOR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_MASTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_SLAVE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_DMABURST_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_BREAK_INSTANCE(INSTANCE)\
  ((INSTANCE) == TIM1)

#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == TIM1) &&                  \
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
      ((CHANNEL) == TIM_CHANNEL_4))))

#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
    (((INSTANCE) == TIM1) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))

#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)\
  ((INSTANCE) == TIM1)

#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_DMA_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))
    
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))
    
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE)\
  ((INSTANCE) == TIM1)

#define IS_TIM_ETR_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1)    || \
                                        ((INSTANCE) == TIM2)    || \
                                        ((INSTANCE) == TIM3))

#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)    || \
                                                         ((INSTANCE) == TIM2)    || \
                                                         ((INSTANCE) == TIM3))

#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE)           0U

/****************************** END TIM Instances *****************************/


/******************** USART Instances : Synchronous mode **********************/                                           
#define IS_USART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2))

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) )

/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                               ((INSTANCE) == USART2) )

/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2) )

/****************** UART Instances : Hardware Flow control ********************/                                    
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2) )

/********************* UART Instances : Smard card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2) )

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) )

/***************** UART Instances : Multi-Processor mode **********************/
#define IS_UART_MULTIPROCESSOR_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                   ((INSTANCE) == USART2) )

/***************** UART Instances : DMA mode available **********************/
#define IS_UART_DMA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2))

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
#define TIM1_BRK_TIM9_IRQn      TIM1_BRK_IRQn
#define TIM1_BRK_TIM15_IRQn     TIM1_BRK_IRQn
#define TIM9_IRQn               TIM1_BRK_IRQn
#define TIM11_IRQn              TIM1_TRG_COM_IRQn
#define TIM1_TRG_COM_TIM17_IRQn TIM1_TRG_COM_IRQn
#define TIM1_TRG_COM_TIM11_IRQn TIM1_TRG_COM_IRQn
#define TIM1_UP_TIM16_IRQn      TIM1_UP_IRQn
#define TIM1_UP_TIM10_IRQn      TIM1_UP_IRQn
#define TIM10_IRQn              TIM1_UP_IRQn
#define OTG_FS_WKUP_IRQn        USBWakeUp_IRQn
#define CEC_IRQn                USBWakeUp_IRQn
#define USB_HP_IRQn             USB_HP_CAN1_TX_IRQn
#define CAN1_TX_IRQn            USB_HP_CAN1_TX_IRQn
#define USB_LP_IRQn             USB_LP_CAN1_RX0_IRQn
#define CAN1_RX0_IRQn           USB_LP_CAN1_RX0_IRQn


/* Aliases for __IRQHandler */
#define ADC1_IRQHandler               ADC1_2_IRQHandler
#define TIM1_BRK_TIM9_IRQHandler      TIM1_BRK_IRQHandler
#define TIM1_BRK_TIM15_IRQHandler     TIM1_BRK_IRQHandler
#define TIM9_IRQHandler               TIM1_BRK_IRQHandler
#define TIM11_IRQHandler              TIM1_TRG_COM_IRQHandler
#define TIM1_TRG_COM_TIM17_IRQHandler TIM1_TRG_COM_IRQHandler
#define TIM1_TRG_COM_TIM11_IRQHandler TIM1_TRG_COM_IRQHandler
#define TIM1_UP_TIM16_IRQHandler      TIM1_UP_IRQHandler
#define TIM1_UP_TIM10_IRQHandler      TIM1_UP_IRQHandler
#define TIM10_IRQHandler              TIM1_UP_IRQHandler
#define OTG_FS_WKUP_IRQHandler        USBWakeUp_IRQHandler
#define CEC_IRQHandler                USBWakeUp_IRQHandler
#define USB_HP_IRQHandler             USB_HP_CAN1_TX_IRQHandler
#define CAN1_TX_IRQHandler            USB_HP_CAN1_TX_IRQHandler
#define USB_LP_IRQHandler             USB_LP_CAN1_RX0_IRQHandler
#define CAN1_RX0_IRQHandler           USB_LP_CAN1_RX0_IRQHandler


/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
  }
#endif /* __cplusplus */
  
#endif /* __STM32F103x6_H */
  
  
  
  /************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
