/**
  ******************************************************************************
  * @file    stm32f446xx.h
  * @author  MCD Application Team
  * @brief   CMSIS STM32F446xx Device Peripheral Access Layer Header File.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - peripherals registers declarations and bits definition
  *           - Macros to access peripheral’s registers hardware
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

/** @addtogroup CMSIS_Device
  * @{
  */

/** @addtogroup stm32f446xx
  * @{
  */
    
#ifndef __STM32F446xx_H
#define __STM32F446xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief Configuration of the Cortex-M4 Processor and Core Peripherals 
  */
#define __CM4_REV                 0x0001U  /*!< Core revision r0p1                            */
#define __MPU_PRESENT             1U       /*!< STM32F4XX provides an MPU                     */
#define __NVIC_PRIO_BITS          4U       /*!< STM32F4XX uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0U       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1U       /*!< FPU present                                   */

/**
  * @}
  */
  
/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief STM32F4XX Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
typedef enum
{
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
  DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
  DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
  DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
  DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
  DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
  DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
  ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
  CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                                 */
  CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                                */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
  TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
  TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
  TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare global interrupt                             */
  DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
  FMC_IRQn                    = 48,     /*!< FMC global Interrupt                                              */
  SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                             */
  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
  TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
  DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
  DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
  DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
  DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
  DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
  CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                                 */
  CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                                */
  CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                                */
  CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                                */
  OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
  DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
  DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
  DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
  USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
  I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
  I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
  OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global interrupt                       */
  OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global interrupt                        */
  OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
  OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global interrupt                                       */
  DCMI_IRQn                   = 78,     /*!< DCMI global interrupt                                             */
  FPU_IRQn                    = 81,     /*!< FPU global interrupt                                              */
  SPI4_IRQn                   = 84,     /*!< SPI4 global Interrupt                                             */
  SAI1_IRQn                   = 87,     /*!< SAI1 global Interrupt                                             */
  SAI2_IRQn                   = 91,     /*!< SAI2 global Interrupt                                             */
  QUADSPI_IRQn                = 92,     /*!< QuadSPI global Interrupt                                          */
  CEC_IRQn                    = 93,     /*!< CEC global Interrupt                                              */
  SPDIF_RX_IRQn               = 94,     /*!< SPDIF-RX global Interrupt                                          */
  FMPI2C1_EV_IRQn             = 95,     /*!< FMPI2C1 Event Interrupt                                           */
  FMPI2C1_ER_IRQn             = 96      /*!< FMPI2C1 Error Interrupt                                           */  
} IRQn_Type;

/**
  * @}
  */

#include "../../cmsis/core_cm4.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Analog to Digital Converter  
  */

typedef struct
{
  __IO uint32_t SR;     /*!< ADC status register,                         Address offset: 0x00 */
  __IO uint32_t CR1;    /*!< ADC control register 1,                      Address offset: 0x04 */
  __IO uint32_t CR2;    /*!< ADC control register 2,                      Address offset: 0x08 */
  __IO uint32_t SMPR1;  /*!< ADC sample time register 1,                  Address offset: 0x0C */
  __IO uint32_t SMPR2;  /*!< ADC sample time register 2,                  Address offset: 0x10 */
  __IO uint32_t JOFR1;  /*!< ADC injected channel data offset register 1, Address offset: 0x14 */
  __IO uint32_t JOFR2;  /*!< ADC injected channel data offset register 2, Address offset: 0x18 */
  __IO uint32_t JOFR3;  /*!< ADC injected channel data offset register 3, Address offset: 0x1C */
  __IO uint32_t JOFR4;  /*!< ADC injected channel data offset register 4, Address offset: 0x20 */
  __IO uint32_t HTR;    /*!< ADC watchdog higher threshold register,      Address offset: 0x24 */
  __IO uint32_t LTR;    /*!< ADC watchdog lower threshold register,       Address offset: 0x28 */
  __IO uint32_t SQR1;   /*!< ADC regular sequence register 1,             Address offset: 0x2C */
  __IO uint32_t SQR2;   /*!< ADC regular sequence register 2,             Address offset: 0x30 */
  __IO uint32_t SQR3;   /*!< ADC regular sequence register 3,             Address offset: 0x34 */
  __IO uint32_t JSQR;   /*!< ADC injected sequence register,              Address offset: 0x38*/
  __IO uint32_t JDR1;   /*!< ADC injected data register 1,                Address offset: 0x3C */
  __IO uint32_t JDR2;   /*!< ADC injected data register 2,                Address offset: 0x40 */
  __IO uint32_t JDR3;   /*!< ADC injected data register 3,                Address offset: 0x44 */
  __IO uint32_t JDR4;   /*!< ADC injected data register 4,                Address offset: 0x48 */
  __IO uint32_t DR;     /*!< ADC regular data register,                   Address offset: 0x4C */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSR;    /*!< ADC Common status register,                  Address offset: ADC1 base address + 0x300 */
  __IO uint32_t CCR;    /*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
  __IO uint32_t CDR;    /*!< ADC common regular data register for dual
                             AND triple modes,                            Address offset: ADC1 base address + 0x308 */
} ADC_Common_TypeDef;


/** 
  * @brief Controller Area Network TxMailBox 
  */

typedef struct
{
  __IO uint32_t TIR;  /*!< CAN TX mailbox identifier register */
  __IO uint32_t TDTR; /*!< CAN mailbox data length control and time stamp register */
  __IO uint32_t TDLR; /*!< CAN mailbox data low register */
  __IO uint32_t TDHR; /*!< CAN mailbox data high register */
} CAN_TxMailBox_TypeDef;

/** 
  * @brief Controller Area Network FIFOMailBox 
  */
  
typedef struct
{
  __IO uint32_t RIR;  /*!< CAN receive FIFO mailbox identifier register */
  __IO uint32_t RDTR; /*!< CAN receive FIFO mailbox data length control and time stamp register */
  __IO uint32_t RDLR; /*!< CAN receive FIFO mailbox data low register */
  __IO uint32_t RDHR; /*!< CAN receive FIFO mailbox data high register */
} CAN_FIFOMailBox_TypeDef;

/** 
  * @brief Controller Area Network FilterRegister 
  */
  
typedef struct
{
  __IO uint32_t FR1; /*!< CAN Filter bank register 1 */
  __IO uint32_t FR2; /*!< CAN Filter bank register 1 */
} CAN_FilterRegister_TypeDef;

/** 
  * @brief Controller Area Network 
  */
  
typedef struct
{
  __IO uint32_t              MCR;                 /*!< CAN master control register,         Address offset: 0x00          */
  __IO uint32_t              MSR;                 /*!< CAN master status register,          Address offset: 0x04          */
  __IO uint32_t              TSR;                 /*!< CAN transmit status register,        Address offset: 0x08          */
  __IO uint32_t              RF0R;                /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
  __IO uint32_t              RF1R;                /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
  __IO uint32_t              IER;                 /*!< CAN interrupt enable register,       Address offset: 0x14          */
  __IO uint32_t              ESR;                 /*!< CAN error status register,           Address offset: 0x18          */
  __IO uint32_t              BTR;                 /*!< CAN bit timing register,             Address offset: 0x1C          */
  uint32_t                   RESERVED0[88];       /*!< Reserved, 0x020 - 0x17F                                            */
  CAN_TxMailBox_TypeDef      sTxMailBox[3];       /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];     /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
  uint32_t                   RESERVED1[12];       /*!< Reserved, 0x1D0 - 0x1FF                                            */
  __IO uint32_t              FMR;                 /*!< CAN filter master register,          Address offset: 0x200         */
  __IO uint32_t              FM1R;                /*!< CAN filter mode register,            Address offset: 0x204         */
  uint32_t                   RESERVED2;           /*!< Reserved, 0x208                                                    */
  __IO uint32_t              FS1R;                /*!< CAN filter scale register,           Address offset: 0x20C         */
  uint32_t                   RESERVED3;           /*!< Reserved, 0x210                                                    */
  __IO uint32_t              FFA1R;               /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
  uint32_t                   RESERVED4;           /*!< Reserved, 0x218                                                    */
  __IO uint32_t              FA1R;                /*!< CAN filter activation register,      Address offset: 0x21C         */
  uint32_t                   RESERVED5[8];        /*!< Reserved, 0x220-0x23F                                              */ 
  CAN_FilterRegister_TypeDef sFilterRegister[28]; /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
} CAN_TypeDef;


/**
  * @brief Consumer Electronics Control
  */

typedef struct
{
  __IO uint32_t CR;           /*!< CEC control register,              Address offset:0x00 */
  __IO uint32_t CFGR;         /*!< CEC configuration register,        Address offset:0x04 */
  __IO uint32_t TXDR;         /*!< CEC Tx data register ,             Address offset:0x08 */
  __IO uint32_t RXDR;         /*!< CEC Rx Data Register,              Address offset:0x0C */
  __IO uint32_t ISR;          /*!< CEC Interrupt and Status Register, Address offset:0x10 */
  __IO uint32_t IER;          /*!< CEC interrupt enable register,     Address offset:0x14 */
}CEC_TypeDef;
/** 
  * @brief CRC calculation unit 
  */

typedef struct
{
  __IO uint32_t DR;         /*!< CRC Data register,             Address offset: 0x00 */
  __IO uint8_t  IDR;        /*!< CRC Independent data register, Address offset: 0x04 */
  uint8_t       RESERVED0;  /*!< Reserved, 0x05                                      */
  uint16_t      RESERVED1;  /*!< Reserved, 0x06                                      */
  __IO uint32_t CR;         /*!< CRC Control register,          Address offset: 0x08 */
} CRC_TypeDef;

/** 
  * @brief Digital to Analog Converter
  */

typedef struct
{
  __IO uint32_t CR;       /*!< DAC control register,                                    Address offset: 0x00 */
  __IO uint32_t SWTRIGR;  /*!< DAC software trigger register,                           Address offset: 0x04 */
  __IO uint32_t DHR12R1;  /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
  __IO uint32_t DHR12L1;  /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
  __IO uint32_t DHR8R1;   /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
  __IO uint32_t DHR12R2;  /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
  __IO uint32_t DHR12L2;  /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
  __IO uint32_t DHR8R2;   /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
  __IO uint32_t DHR12RD;  /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
  __IO uint32_t DHR12LD;  /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
  __IO uint32_t DHR8RD;   /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
  __IO uint32_t DOR1;     /*!< DAC channel1 data output register,                       Address offset: 0x2C */
  __IO uint32_t DOR2;     /*!< DAC channel2 data output register,                       Address offset: 0x30 */
  __IO uint32_t SR;       /*!< DAC status register,                                     Address offset: 0x34 */
} DAC_TypeDef;

/** 
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;  /*!< MCU device ID code,               Address offset: 0x00 */
  __IO uint32_t CR;      /*!< Debug MCU configuration register, Address offset: 0x04 */
  __IO uint32_t APB1FZ;  /*!< Debug MCU APB1 freeze register,   Address offset: 0x08 */
  __IO uint32_t APB2FZ;  /*!< Debug MCU APB2 freeze register,   Address offset: 0x0C */
}DBGMCU_TypeDef;

/** 
  * @brief DCMI
  */

typedef struct
{
  __IO uint32_t CR;       /*!< DCMI control register 1,                       Address offset: 0x00 */
  __IO uint32_t SR;       /*!< DCMI status register,                          Address offset: 0x04 */
  __IO uint32_t RISR;     /*!< DCMI raw interrupt status register,            Address offset: 0x08 */
  __IO uint32_t IER;      /*!< DCMI interrupt enable register,                Address offset: 0x0C */
  __IO uint32_t MISR;     /*!< DCMI masked interrupt status register,         Address offset: 0x10 */
  __IO uint32_t ICR;      /*!< DCMI interrupt clear register,                 Address offset: 0x14 */
  __IO uint32_t ESCR;     /*!< DCMI embedded synchronization code register,   Address offset: 0x18 */
  __IO uint32_t ESUR;     /*!< DCMI embedded synchronization unmask register, Address offset: 0x1C */
  __IO uint32_t CWSTRTR;  /*!< DCMI crop window start,                        Address offset: 0x20 */
  __IO uint32_t CWSIZER;  /*!< DCMI crop window size,                         Address offset: 0x24 */
  __IO uint32_t DR;       /*!< DCMI data register,                            Address offset: 0x28 */
} DCMI_TypeDef;

/** 
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CR;     /*!< DMA stream x configuration register      */
  __IO uint32_t NDTR;   /*!< DMA stream x number of data register     */
  __IO uint32_t PAR;    /*!< DMA stream x peripheral address register */
  __IO uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
  __IO uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
  __IO uint32_t FCR;    /*!< DMA stream x FIFO control register       */
} DMA_Stream_TypeDef;

typedef struct
{
  __IO uint32_t LISR;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
  __IO uint32_t HISR;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
  __IO uint32_t LIFCR;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
  __IO uint32_t HIFCR;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
} DMA_TypeDef;

/** 
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
  __IO uint32_t EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
  __IO uint32_t RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
  __IO uint32_t FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
  __IO uint32_t SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
  __IO uint32_t PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_TypeDef;

/** 
  * @brief FLASH Registers
  */

typedef struct
{
  __IO uint32_t ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
  __IO uint32_t KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
  __IO uint32_t OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
  __IO uint32_t SR;       /*!< FLASH status register,           Address offset: 0x0C */
  __IO uint32_t CR;       /*!< FLASH control register,          Address offset: 0x10 */
  __IO uint32_t OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
  __IO uint32_t OPTCR1;   /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;

/** 
  * @brief Flexible Memory Controller
  */

typedef struct
{
  __IO uint32_t BTCR[8];    /*!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */
} FMC_Bank1_TypeDef; 

/** 
  * @brief Flexible Memory Controller Bank1E
  */
  
typedef struct
{
  __IO uint32_t BWTR[7];    /*!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */
} FMC_Bank1E_TypeDef;

/** 
  * @brief Flexible Memory Controller Bank3
  */
 
typedef struct
{
  __IO uint32_t PCR;       /*!< NAND Flash control register,                       Address offset: 0x80 */
  __IO uint32_t SR;        /*!< NAND Flash FIFO status and interrupt register,     Address offset: 0x84 */
  __IO uint32_t PMEM;      /*!< NAND Flash Common memory space timing register,    Address offset: 0x88 */
  __IO uint32_t PATT;      /*!< NAND Flash Attribute memory space timing register, Address offset: 0x8C */
  uint32_t      RESERVED;  /*!< Reserved, 0x90                                                          */
  __IO uint32_t ECCR;      /*!< NAND Flash ECC result registers,                   Address offset: 0x94 */
} FMC_Bank3_TypeDef;

/** 
  * @brief Flexible Memory Controller Bank5_6
  */
  
typedef struct
{
  __IO uint32_t SDCR[2];        /*!< SDRAM Control registers ,      Address offset: 0x140-0x144  */
  __IO uint32_t SDTR[2];        /*!< SDRAM Timing registers ,       Address offset: 0x148-0x14C  */
  __IO uint32_t SDCMR;          /*!< SDRAM Command Mode register,   Address offset: 0x150        */
  __IO uint32_t SDRTR;          /*!< SDRAM Refresh Timer register,  Address offset: 0x154        */
  __IO uint32_t SDSR;           /*!< SDRAM Status register,         Address offset: 0x158        */
} FMC_Bank5_6_TypeDef;

/** 
  * @brief General Purpose I/O
  */

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/** 
  * @brief System configuration controller
  */

typedef struct
{
  __IO uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  __IO uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  __IO uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
  uint32_t      RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
  __IO uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
  uint32_t      RESERVED1[2]; /*!< Reserved, 0x24-0x28                                                          */
  __IO uint32_t CFGR;         /*!< SYSCFG Configuration register,                     Address offset: 0x2C      */
} SYSCFG_TypeDef;

/** 
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;        /*!< I2C Control register 1,     Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< I2C Control register 2,     Address offset: 0x04 */
  __IO uint32_t OAR1;       /*!< I2C Own address register 1, Address offset: 0x08 */
  __IO uint32_t OAR2;       /*!< I2C Own address register 2, Address offset: 0x0C */
  __IO uint32_t DR;         /*!< I2C Data register,          Address offset: 0x10 */
  __IO uint32_t SR1;        /*!< I2C Status register 1,      Address offset: 0x14 */
  __IO uint32_t SR2;        /*!< I2C Status register 2,      Address offset: 0x18 */
  __IO uint32_t CCR;        /*!< I2C Clock control register, Address offset: 0x1C */
  __IO uint32_t TRISE;      /*!< I2C TRISE register,         Address offset: 0x20 */
  __IO uint32_t FLTR;       /*!< I2C FLTR register,          Address offset: 0x24 */
} I2C_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;         /*!< FMPI2C Control register 1,            Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< FMPI2C Control register 2,            Address offset: 0x04 */
  __IO uint32_t OAR1;        /*!< FMPI2C Own address 1 register,        Address offset: 0x08 */
  __IO uint32_t OAR2;        /*!< FMPI2C Own address 2 register,        Address offset: 0x0C */
  __IO uint32_t TIMINGR;     /*!< FMPI2C Timing register,               Address offset: 0x10 */
  __IO uint32_t TIMEOUTR;    /*!< FMPI2C Timeout register,              Address offset: 0x14 */
  __IO uint32_t ISR;         /*!< FMPI2C Interrupt and status register, Address offset: 0x18 */
  __IO uint32_t ICR;         /*!< FMPI2C Interrupt clear register,      Address offset: 0x1C */
  __IO uint32_t PECR;        /*!< FMPI2C PEC register,                  Address offset: 0x20 */
  __IO uint32_t RXDR;        /*!< FMPI2C Receive data register,         Address offset: 0x24 */
  __IO uint32_t TXDR;        /*!< FMPI2C Transmit data register,        Address offset: 0x28 */
} FMPI2C_TypeDef;

/** 
  * @brief Independent WATCHDOG
  */

typedef struct
{
  __IO uint32_t KR;   /*!< IWDG Key register,       Address offset: 0x00 */
  __IO uint32_t PR;   /*!< IWDG Prescaler register, Address offset: 0x04 */
  __IO uint32_t RLR;  /*!< IWDG Reload register,    Address offset: 0x08 */
  __IO uint32_t SR;   /*!< IWDG Status register,    Address offset: 0x0C */
} IWDG_TypeDef;


/** 
  * @brief Power Control
  */

typedef struct
{
  __IO uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
  __IO uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;

/** 
  * @brief Reset and Clock Control
  */

typedef struct
{
  __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  __IO uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
  __IO uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
  __IO uint32_t CKGATENR;      /*!< RCC Clocks Gated ENable Register,                            Address offset: 0x90 */
  __IO uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94 */
} RCC_TypeDef;

/** 
  * @brief Real-Time Clock
  */

typedef struct
{
  __IO uint32_t TR;      /*!< RTC time register,                                        Address offset: 0x00 */
  __IO uint32_t DR;      /*!< RTC date register,                                        Address offset: 0x04 */
  __IO uint32_t CR;      /*!< RTC control register,                                     Address offset: 0x08 */
  __IO uint32_t ISR;     /*!< RTC initialization and status register,                   Address offset: 0x0C */
  __IO uint32_t PRER;    /*!< RTC prescaler register,                                   Address offset: 0x10 */
  __IO uint32_t WUTR;    /*!< RTC wakeup timer register,                                Address offset: 0x14 */
  __IO uint32_t CALIBR;  /*!< RTC calibration register,                                 Address offset: 0x18 */
  __IO uint32_t ALRMAR;  /*!< RTC alarm A register,                                     Address offset: 0x1C */
  __IO uint32_t ALRMBR;  /*!< RTC alarm B register,                                     Address offset: 0x20 */
  __IO uint32_t WPR;     /*!< RTC write protection register,                            Address offset: 0x24 */
  __IO uint32_t SSR;     /*!< RTC sub second register,                                  Address offset: 0x28 */
  __IO uint32_t SHIFTR;  /*!< RTC shift control register,                               Address offset: 0x2C */
  __IO uint32_t TSTR;    /*!< RTC time stamp time register,                             Address offset: 0x30 */
  __IO uint32_t TSDR;    /*!< RTC time stamp date register,                             Address offset: 0x34 */
  __IO uint32_t TSSSR;   /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
  __IO uint32_t CALR;    /*!< RTC calibration register,                                 Address offset: 0x3C */
  __IO uint32_t TAFCR;   /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
  __IO uint32_t ALRMASSR;/*!< RTC alarm A sub second register,                          Address offset: 0x44 */
  __IO uint32_t ALRMBSSR;/*!< RTC alarm B sub second register,                          Address offset: 0x48 */
  uint32_t RESERVED7;    /*!< Reserved, 0x4C                                                                 */
  __IO uint32_t BKP0R;   /*!< RTC backup register 1,                                    Address offset: 0x50 */
  __IO uint32_t BKP1R;   /*!< RTC backup register 1,                                    Address offset: 0x54 */
  __IO uint32_t BKP2R;   /*!< RTC backup register 2,                                    Address offset: 0x58 */
  __IO uint32_t BKP3R;   /*!< RTC backup register 3,                                    Address offset: 0x5C */
  __IO uint32_t BKP4R;   /*!< RTC backup register 4,                                    Address offset: 0x60 */
  __IO uint32_t BKP5R;   /*!< RTC backup register 5,                                    Address offset: 0x64 */
  __IO uint32_t BKP6R;   /*!< RTC backup register 6,                                    Address offset: 0x68 */
  __IO uint32_t BKP7R;   /*!< RTC backup register 7,                                    Address offset: 0x6C */
  __IO uint32_t BKP8R;   /*!< RTC backup register 8,                                    Address offset: 0x70 */
  __IO uint32_t BKP9R;   /*!< RTC backup register 9,                                    Address offset: 0x74 */
  __IO uint32_t BKP10R;  /*!< RTC backup register 10,                                   Address offset: 0x78 */
  __IO uint32_t BKP11R;  /*!< RTC backup register 11,                                   Address offset: 0x7C */
  __IO uint32_t BKP12R;  /*!< RTC backup register 12,                                   Address offset: 0x80 */
  __IO uint32_t BKP13R;  /*!< RTC backup register 13,                                   Address offset: 0x84 */
  __IO uint32_t BKP14R;  /*!< RTC backup register 14,                                   Address offset: 0x88 */
  __IO uint32_t BKP15R;  /*!< RTC backup register 15,                                   Address offset: 0x8C */
  __IO uint32_t BKP16R;  /*!< RTC backup register 16,                                   Address offset: 0x90 */
  __IO uint32_t BKP17R;  /*!< RTC backup register 17,                                   Address offset: 0x94 */
  __IO uint32_t BKP18R;  /*!< RTC backup register 18,                                   Address offset: 0x98 */
  __IO uint32_t BKP19R;  /*!< RTC backup register 19,                                   Address offset: 0x9C */
} RTC_TypeDef;

/** 
  * @brief Serial Audio Interface
  */
  
typedef struct
{
  __IO uint32_t GCR;      /*!< SAI global configuration register,        Address offset: 0x00 */
} SAI_TypeDef;

typedef struct
{
  __IO uint32_t CR1;      /*!< SAI block x configuration register 1,     Address offset: 0x04 */
  __IO uint32_t CR2;      /*!< SAI block x configuration register 2,     Address offset: 0x08 */
  __IO uint32_t FRCR;     /*!< SAI block x frame configuration register, Address offset: 0x0C */
  __IO uint32_t SLOTR;    /*!< SAI block x slot register,                Address offset: 0x10 */
  __IO uint32_t IMR;      /*!< SAI block x interrupt mask register,      Address offset: 0x14 */
  __IO uint32_t SR;       /*!< SAI block x status register,              Address offset: 0x18 */
  __IO uint32_t CLRFR;    /*!< SAI block x clear flag register,          Address offset: 0x1C */
  __IO uint32_t DR;       /*!< SAI block x data register,                Address offset: 0x20 */
} SAI_Block_TypeDef;

/** 
  * @brief SD host Interface
  */

typedef struct
{
  __IO uint32_t POWER;                 /*!< SDIO power control register,    Address offset: 0x00 */
  __IO uint32_t CLKCR;                 /*!< SDI clock control register,     Address offset: 0x04 */
  __IO uint32_t ARG;                   /*!< SDIO argument register,         Address offset: 0x08 */
  __IO uint32_t CMD;                   /*!< SDIO command register,          Address offset: 0x0C */
  __IO const uint32_t  RESPCMD;        /*!< SDIO command response register, Address offset: 0x10 */
  __IO const uint32_t  RESP1;          /*!< SDIO response 1 register,       Address offset: 0x14 */
  __IO const uint32_t  RESP2;          /*!< SDIO response 2 register,       Address offset: 0x18 */
  __IO const uint32_t  RESP3;          /*!< SDIO response 3 register,       Address offset: 0x1C */
  __IO const uint32_t  RESP4;          /*!< SDIO response 4 register,       Address offset: 0x20 */
  __IO uint32_t DTIMER;                /*!< SDIO data timer register,       Address offset: 0x24 */
  __IO uint32_t DLEN;                  /*!< SDIO data length register,      Address offset: 0x28 */
  __IO uint32_t DCTRL;                 /*!< SDIO data control register,     Address offset: 0x2C */
  __IO const uint32_t  DCOUNT;         /*!< SDIO data counter register,     Address offset: 0x30 */
  __IO const uint32_t  STA;            /*!< SDIO status register,           Address offset: 0x34 */
  __IO uint32_t ICR;                   /*!< SDIO interrupt clear register,  Address offset: 0x38 */
  __IO uint32_t MASK;                  /*!< SDIO mask register,             Address offset: 0x3C */
  uint32_t      RESERVED0[2];          /*!< Reserved, 0x40-0x44                                  */
  __IO const uint32_t  FIFOCNT;        /*!< SDIO FIFO counter register,     Address offset: 0x48 */
  uint32_t      RESERVED1[13];         /*!< Reserved, 0x4C-0x7C                                  */
  __IO uint32_t FIFO;                  /*!< SDIO data FIFO register,        Address offset: 0x80 */
} SDIO_TypeDef;

/** 
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< SPI control register 2,                             Address offset: 0x04 */
  __IO uint32_t SR;         /*!< SPI status register,                                Address offset: 0x08 */
  __IO uint32_t DR;         /*!< SPI data register,                                  Address offset: 0x0C */
  __IO uint32_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  __IO uint32_t RXCRCR;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
  __IO uint32_t TXCRCR;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
  __IO uint32_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  __IO uint32_t I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
} SPI_TypeDef;

/** 
  * @brief QUAD Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR;       /*!< QUADSPI Control register,                           Address offset: 0x00 */
  __IO uint32_t DCR;      /*!< QUADSPI Device Configuration register,              Address offset: 0x04 */
  __IO uint32_t SR;       /*!< QUADSPI Status register,                            Address offset: 0x08 */
  __IO uint32_t FCR;      /*!< QUADSPI Flag Clear register,                        Address offset: 0x0C */
  __IO uint32_t DLR;      /*!< QUADSPI Data Length register,                       Address offset: 0x10 */
  __IO uint32_t CCR;      /*!< QUADSPI Communication Configuration register,       Address offset: 0x14 */
  __IO uint32_t AR;       /*!< QUADSPI Address register,                           Address offset: 0x18 */
  __IO uint32_t ABR;      /*!< QUADSPI Alternate Bytes register,                   Address offset: 0x1C */
  __IO uint32_t DR;       /*!< QUADSPI Data register,                              Address offset: 0x20 */
  __IO uint32_t PSMKR;    /*!< QUADSPI Polling Status Mask register,               Address offset: 0x24 */
  __IO uint32_t PSMAR;    /*!< QUADSPI Polling Status Match register,              Address offset: 0x28 */
  __IO uint32_t PIR;      /*!< QUADSPI Polling Interval register,                  Address offset: 0x2C */
  __IO uint32_t LPTR;     /*!< QUADSPI Low Power Timeout register,                 Address offset: 0x30 */
} QUADSPI_TypeDef;

/** 
  * @brief SPDIFRX Interface
  */

typedef struct
{
  __IO uint32_t   CR;           /*!< Control register,                   Address offset: 0x00 */
  __IO uint16_t   IMR;          /*!< Interrupt mask register,            Address offset: 0x04 */
  uint16_t        RESERVED0;    /*!< Reserved,  0x06                                          */
  __IO uint32_t   SR;           /*!< Status register,                    Address offset: 0x08 */
  __IO uint16_t   IFCR;         /*!< Interrupt Flag Clear register,      Address offset: 0x0C */
  uint16_t        RESERVED1;    /*!< Reserved,  0x0E                                          */
  __IO uint32_t   DR;           /*!< Data input register,                Address offset: 0x10 */
  __IO uint32_t   CSR;          /*!< Channel Status register,            Address offset: 0x14 */
   __IO uint32_t  DIR;          /*!< Debug Information register,         Address offset: 0x18 */
  uint16_t        RESERVED2;    /*!< Reserved,  0x1A                                          */
} SPDIFRX_TypeDef;

/** 
  * @brief TIM
  */

typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
  __IO uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
  __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
  __IO uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
} TIM_TypeDef;

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
  * @brief Window WATCHDOG
  */

typedef struct
{
  __IO uint32_t CR;   /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;  /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;   /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;
/** 
  * @brief USB_OTG_Core_Registers
  */
typedef struct
{
  __IO uint32_t GOTGCTL;              /*!< USB_OTG Control and Status Register          000h */
  __IO uint32_t GOTGINT;              /*!< USB_OTG Interrupt Register                   004h */
  __IO uint32_t GAHBCFG;              /*!< Core AHB Configuration Register              008h */
  __IO uint32_t GUSBCFG;              /*!< Core USB Configuration Register              00Ch */
  __IO uint32_t GRSTCTL;              /*!< Core Reset Register                          010h */
  __IO uint32_t GINTSTS;              /*!< Core Interrupt Register                      014h */
  __IO uint32_t GINTMSK;              /*!< Core Interrupt Mask Register                 018h */
  __IO uint32_t GRXSTSR;              /*!< Receive Sts Q Read Register                  01Ch */
  __IO uint32_t GRXSTSP;              /*!< Receive Sts Q Read & POP Register            020h */
  __IO uint32_t GRXFSIZ;              /*!< Receive FIFO Size Register                   024h */
  __IO uint32_t DIEPTXF0_HNPTXFSIZ;   /*!< EP0 / Non Periodic Tx FIFO Size Register     028h */
  __IO uint32_t HNPTXSTS;             /*!< Non Periodic Tx FIFO/Queue Sts reg           02Ch */
  uint32_t Reserved30[2];             /*!< Reserved                                     030h */
  __IO uint32_t GCCFG;                /*!< General Purpose IO Register                  038h */
  __IO uint32_t CID;                  /*!< User ID Register                             03Ch */
  uint32_t  Reserved5[3];             /*!< Reserved                                040h-048h */
  __IO uint32_t GHWCFG3;              /*!< User HW config3                              04Ch */
  uint32_t  Reserved6;                /*!< Reserved                                     050h */
  __IO uint32_t GLPMCFG;              /*!< LPM Register                                 054h */
  uint32_t  Reserved;                 /*!< Reserved                                     058h */
  __IO uint32_t GDFIFOCFG;            /*!< DFIFO Software Config Register               05Ch */
  uint32_t  Reserved43[40];           /*!< Reserved                                058h-0FFh */
  __IO uint32_t HPTXFSIZ;             /*!< Host Periodic Tx FIFO Size Reg               100h */
  __IO uint32_t DIEPTXF[0x0F];        /*!< dev Periodic Transmit FIFO                        */
} USB_OTG_GlobalTypeDef;

/** 
  * @brief USB_OTG_device_Registers
  */
typedef struct 
{
  __IO uint32_t DCFG;            /*!< dev Configuration Register   800h */
  __IO uint32_t DCTL;            /*!< dev Control Register         804h */
  __IO uint32_t DSTS;            /*!< dev Status Register (RO)     808h */
  uint32_t Reserved0C;           /*!< Reserved                     80Ch */
  __IO uint32_t DIEPMSK;         /*!< dev IN Endpoint Mask         810h */
  __IO uint32_t DOEPMSK;         /*!< dev OUT Endpoint Mask        814h */
  __IO uint32_t DAINT;           /*!< dev All Endpoints Itr Reg    818h */
  __IO uint32_t DAINTMSK;        /*!< dev All Endpoints Itr Mask   81Ch */
  uint32_t  Reserved20;          /*!< Reserved                     820h */
  uint32_t Reserved9;            /*!< Reserved                     824h */
  __IO uint32_t DVBUSDIS;        /*!< dev VBUS discharge Register  828h */
  __IO uint32_t DVBUSPULSE;      /*!< dev VBUS Pulse Register      82Ch */
  __IO uint32_t DTHRCTL;         /*!< dev threshold                830h */
  __IO uint32_t DIEPEMPMSK;      /*!< dev empty msk                834h */
  __IO uint32_t DEACHINT;        /*!< dedicated EP interrupt       838h */
  __IO uint32_t DEACHMSK;        /*!< dedicated EP msk             83Ch */
  uint32_t Reserved40;           /*!< dedicated EP mask            840h */
  __IO uint32_t DINEP1MSK;       /*!< dedicated EP mask            844h */
  uint32_t  Reserved44[15];      /*!< Reserved                 844-87Ch */
  __IO uint32_t DOUTEP1MSK;      /*!< dedicated EP msk             884h */
} USB_OTG_DeviceTypeDef;

/** 
  * @brief USB_OTG_IN_Endpoint-Specific_Register
  */
typedef struct 
{
  __IO uint32_t DIEPCTL;           /*!< dev IN Endpoint Control Reg    900h + (ep_num * 20h) + 00h */
  uint32_t Reserved04;             /*!< Reserved                       900h + (ep_num * 20h) + 04h */
  __IO uint32_t DIEPINT;           /*!< dev IN Endpoint Itr Reg        900h + (ep_num * 20h) + 08h */
  uint32_t Reserved0C;             /*!< Reserved                       900h + (ep_num * 20h) + 0Ch */
  __IO uint32_t DIEPTSIZ;          /*!< IN Endpoint Txfer Size         900h + (ep_num * 20h) + 10h */
  __IO uint32_t DIEPDMA;           /*!< IN Endpoint DMA Address Reg    900h + (ep_num * 20h) + 14h */
  __IO uint32_t DTXFSTS;           /*!< IN Endpoint Tx FIFO Status Reg 900h + (ep_num * 20h) + 18h */
  uint32_t Reserved18;             /*!< Reserved  900h+(ep_num*20h)+1Ch-900h+ (ep_num * 20h) + 1Ch */
} USB_OTG_INEndpointTypeDef;

/** 
  * @brief USB_OTG_OUT_Endpoint-Specific_Registers
  */
typedef struct 
{
  __IO uint32_t DOEPCTL;       /*!< dev OUT Endpoint Control Reg           B00h + (ep_num * 20h) + 00h */
  uint32_t Reserved04;         /*!< Reserved                               B00h + (ep_num * 20h) + 04h */
  __IO uint32_t DOEPINT;       /*!< dev OUT Endpoint Itr Reg               B00h + (ep_num * 20h) + 08h */
  uint32_t Reserved0C;         /*!< Reserved                               B00h + (ep_num * 20h) + 0Ch */
  __IO uint32_t DOEPTSIZ;      /*!< dev OUT Endpoint Txfer Size            B00h + (ep_num * 20h) + 10h */
  __IO uint32_t DOEPDMA;       /*!< dev OUT Endpoint DMA Address           B00h + (ep_num * 20h) + 14h */
  uint32_t Reserved18[2];      /*!< Reserved B00h + (ep_num * 20h) + 18h - B00h + (ep_num * 20h) + 1Ch */
} USB_OTG_OUTEndpointTypeDef;

/** 
  * @brief USB_OTG_Host_Mode_Register_Structures
  */
typedef struct 
{
  __IO uint32_t HCFG;             /*!< Host Configuration Register          400h */
  __IO uint32_t HFIR;             /*!< Host Frame Interval Register         404h */
  __IO uint32_t HFNUM;            /*!< Host Frame Nbr/Frame Remaining       408h */
  uint32_t Reserved40C;           /*!< Reserved                             40Ch */
  __IO uint32_t HPTXSTS;          /*!< Host Periodic Tx FIFO/ Queue Status  410h */
  __IO uint32_t HAINT;            /*!< Host All Channels Interrupt Register 414h */
  __IO uint32_t HAINTMSK;         /*!< Host All Channels Interrupt Mask     418h */
} USB_OTG_HostTypeDef;

/** 
  * @brief USB_OTG_Host_Channel_Specific_Registers
  */
typedef struct
{
  __IO uint32_t HCCHAR;           /*!< Host Channel Characteristics Register    500h */
  __IO uint32_t HCSPLT;           /*!< Host Channel Split Control Register      504h */
  __IO uint32_t HCINT;            /*!< Host Channel Interrupt Register          508h */
  __IO uint32_t HCINTMSK;         /*!< Host Channel Interrupt Mask Register     50Ch */
  __IO uint32_t HCTSIZ;           /*!< Host Channel Transfer Size Register      510h */
  __IO uint32_t HCDMA;            /*!< Host Channel DMA Address Register        514h */
  uint32_t Reserved[2];           /*!< Reserved                                      */
} USB_OTG_HostChannelTypeDef;

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */
#define FLASH_BASE            0x08000000UL /*!< FLASH(up to 1 MB) base address in the alias region                         */
#define SRAM1_BASE            0x20000000UL /*!< SRAM1(112 KB) base address in the alias region                              */
#define SRAM2_BASE            0x2001C000UL /*!< SRAM2(16 KB) base address in the alias region                              */
#define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region                                */
#define BKPSRAM_BASE          0x40024000UL /*!< Backup SRAM(4 KB) base address in the alias region                         */
#define FMC_R_BASE            0xA0000000UL /*!< FMC registers base address                                                 */
#define QSPI_R_BASE           0xA0001000UL /*!< QuadSPI registers base address                                             */
#define SRAM1_BB_BASE         0x22000000UL /*!< SRAM1(112 KB) base address in the bit-band region                          */
#define SRAM2_BB_BASE         0x22380000UL /*!< SRAM2(16 KB) base address in the bit-band region                           */
#define PERIPH_BB_BASE        0x42000000UL /*!< Peripheral base address in the bit-band region                             */
#define BKPSRAM_BB_BASE       0x42480000UL /*!< Backup SRAM(4 KB) base address in the bit-band region                      */
#define FLASH_END             0x0807FFFFUL /*!< FLASH end address                                                          */
#define FLASH_OTP_BASE        0x1FFF7800UL /*!< Base address of : (up to 528 Bytes) embedded FLASH OTP Area                */
#define FLASH_OTP_END         0x1FFF7A0FUL /*!< End address of : (up to 528 Bytes) embedded FLASH OTP Area                 */

/* Legacy defines */
#define SRAM_BASE             SRAM1_BASE
#define SRAM_BB_BASE          SRAM1_BB_BASE

/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)

/*!< APB1 peripherals */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400UL)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800UL)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00UL)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)
#define SPDIFRX_BASE          (APB1PERIPH_BASE + 0x4000UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x5C00UL)
#define FMPI2C1_BASE          (APB1PERIPH_BASE + 0x6000UL)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400UL)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800UL)
#define CEC_BASE              (APB1PERIPH_BASE + 0x6C00UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000UL)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400UL)

/*!< APB2 peripherals */
#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE           (APB2PERIPH_BASE + 0x1400UL)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000UL)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2100UL)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x2200UL)
#define ADC123_COMMON_BASE    (APB2PERIPH_BASE + 0x2300UL)
/* Legacy define */
#define ADC_BASE               ADC123_COMMON_BASE
#define SDIO_BASE             (APB2PERIPH_BASE + 0x2C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)
#define SPI4_BASE             (APB2PERIPH_BASE + 0x3400UL)
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x3800UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00UL)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000UL)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400UL)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800UL)
#define SAI1_BASE             (APB2PERIPH_BASE + 0x5800UL)
#define SAI1_Block_A_BASE     (SAI1_BASE + 0x004UL)
#define SAI1_Block_B_BASE     (SAI1_BASE + 0x024UL)
#define SAI2_BASE             (APB2PERIPH_BASE + 0x5C00UL)
#define SAI2_Block_A_BASE     (SAI2_BASE + 0x004UL)
#define SAI2_Block_B_BASE     (SAI2_BASE + 0x024UL)

/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00UL)
#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000UL)
#define DMA1_Stream0_BASE     (DMA1_BASE + 0x010UL)
#define DMA1_Stream1_BASE     (DMA1_BASE + 0x028UL)
#define DMA1_Stream2_BASE     (DMA1_BASE + 0x040UL)
#define DMA1_Stream3_BASE     (DMA1_BASE + 0x058UL)
#define DMA1_Stream4_BASE     (DMA1_BASE + 0x070UL)
#define DMA1_Stream5_BASE     (DMA1_BASE + 0x088UL)
#define DMA1_Stream6_BASE     (DMA1_BASE + 0x0A0UL)
#define DMA1_Stream7_BASE     (DMA1_BASE + 0x0B8UL)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400UL)
#define DMA2_Stream0_BASE     (DMA2_BASE + 0x010UL)
#define DMA2_Stream1_BASE     (DMA2_BASE + 0x028UL)
#define DMA2_Stream2_BASE     (DMA2_BASE + 0x040UL)
#define DMA2_Stream3_BASE     (DMA2_BASE + 0x058UL)
#define DMA2_Stream4_BASE     (DMA2_BASE + 0x070UL)
#define DMA2_Stream5_BASE     (DMA2_BASE + 0x088UL)
#define DMA2_Stream6_BASE     (DMA2_BASE + 0x0A0UL)
#define DMA2_Stream7_BASE     (DMA2_BASE + 0x0B8UL)

/*!< AHB2 peripherals */
#define DCMI_BASE             (AHB2PERIPH_BASE + 0x50000UL)

/*!< FMC Bankx registers base address */
#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000UL)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104UL)
#define FMC_Bank3_R_BASE      (FMC_R_BASE + 0x0080UL)
#define FMC_Bank5_6_R_BASE    (FMC_R_BASE + 0x0140UL)


/*!< Debug MCU registers base address */
#define DBGMCU_BASE           0xE0042000UL
/*!< USB registers base address */
#define USB_OTG_HS_PERIPH_BASE               0x40040000UL
#define USB_OTG_FS_PERIPH_BASE               0x50000000UL

#define USB_OTG_GLOBAL_BASE                  0x000UL
#define USB_OTG_DEVICE_BASE                  0x800UL
#define USB_OTG_IN_ENDPOINT_BASE             0x900UL
#define USB_OTG_OUT_ENDPOINT_BASE            0xB00UL
#define USB_OTG_EP_REG_SIZE                  0x20UL
#define USB_OTG_HOST_BASE                    0x400UL
#define USB_OTG_HOST_PORT_BASE               0x440UL
#define USB_OTG_HOST_CHANNEL_BASE            0x500UL
#define USB_OTG_HOST_CHANNEL_SIZE            0x20UL
#define USB_OTG_PCGCCTL_BASE                 0xE00UL
#define USB_OTG_FIFO_BASE                    0x1000UL
#define USB_OTG_FIFO_SIZE                    0x1000UL

#define UID_BASE                     0x1FFF7A10UL           /*!< Unique device ID register base address */
#define FLASHSIZE_BASE               0x1FFF7A22UL           /*!< FLASH Size register base address       */
#define PACKAGE_BASE                 0x1FFF7BF0UL           /*!< Package size register base address     */
/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */  
#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#define TIM5                ((TIM_TypeDef *) TIM5_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define TIM12               ((TIM_TypeDef *) TIM12_BASE)
#define TIM13               ((TIM_TypeDef *) TIM13_BASE)
#define TIM14               ((TIM_TypeDef *) TIM14_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define I2S2                ((SPI_TypeDef *) SPI2_BASE)
#define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#define I2S3                ((SPI_TypeDef *) SPI3_BASE)
#define SPDIFRX             ((SPDIFRX_TypeDef *) SPDIFRX_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define UART4               ((USART_TypeDef *) UART4_BASE)
#define UART5               ((USART_TypeDef *) UART5_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define I2C3                ((I2C_TypeDef *) I2C3_BASE)
#define FMPI2C1             ((FMPI2C_TypeDef *) FMPI2C1_BASE)
#define CAN1                ((CAN_TypeDef *) CAN1_BASE)
#define CAN2                ((CAN_TypeDef *) CAN2_BASE)
#define CEC                 ((CEC_TypeDef *) CEC_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define DAC1                ((DAC_TypeDef *) DAC_BASE)
#define DAC                 ((DAC_TypeDef *) DAC_BASE) /* Kept for legacy purpose */
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define TIM8                ((TIM_TypeDef *) TIM8_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define USART6              ((USART_TypeDef *) USART6_BASE)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#define ADC3                ((ADC_TypeDef *) ADC3_BASE)
#define ADC123_COMMON       ((ADC_Common_TypeDef *) ADC123_COMMON_BASE)
/* Legacy define */
#define ADC                  ADC123_COMMON
#define SDIO                ((SDIO_TypeDef *) SDIO_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define I2S1                ((SPI_TypeDef *) SPI1_BASE)
#define SPI4                ((SPI_TypeDef *) SPI4_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define TIM9                ((TIM_TypeDef *) TIM9_BASE)
#define TIM10               ((TIM_TypeDef *) TIM10_BASE)
#define TIM11               ((TIM_TypeDef *) TIM11_BASE)
#define SAI1                ((SAI_TypeDef *) SAI1_BASE)
#define SAI1_Block_A        ((SAI_Block_TypeDef *)SAI1_Block_A_BASE)
#define SAI1_Block_B        ((SAI_Block_TypeDef *)SAI1_Block_B_BASE)
#define SAI2                ((SAI_TypeDef *) SAI2_BASE)
#define SAI2_Block_A        ((SAI_Block_TypeDef *)SAI2_Block_A_BASE)
#define SAI2_Block_B        ((SAI_Block_TypeDef *)SAI2_Block_B_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Stream0        ((DMA_Stream_TypeDef *) DMA1_Stream0_BASE)
#define DMA1_Stream1        ((DMA_Stream_TypeDef *) DMA1_Stream1_BASE)
#define DMA1_Stream2        ((DMA_Stream_TypeDef *) DMA1_Stream2_BASE)
#define DMA1_Stream3        ((DMA_Stream_TypeDef *) DMA1_Stream3_BASE)
#define DMA1_Stream4        ((DMA_Stream_TypeDef *) DMA1_Stream4_BASE)
#define DMA1_Stream5        ((DMA_Stream_TypeDef *) DMA1_Stream5_BASE)
#define DMA1_Stream6        ((DMA_Stream_TypeDef *) DMA1_Stream6_BASE)
#define DMA1_Stream7        ((DMA_Stream_TypeDef *) DMA1_Stream7_BASE)
#define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#define DMA2_Stream0        ((DMA_Stream_TypeDef *) DMA2_Stream0_BASE)
#define DMA2_Stream1        ((DMA_Stream_TypeDef *) DMA2_Stream1_BASE)
#define DMA2_Stream2        ((DMA_Stream_TypeDef *) DMA2_Stream2_BASE)
#define DMA2_Stream3        ((DMA_Stream_TypeDef *) DMA2_Stream3_BASE)
#define DMA2_Stream4        ((DMA_Stream_TypeDef *) DMA2_Stream4_BASE)
#define DMA2_Stream5        ((DMA_Stream_TypeDef *) DMA2_Stream5_BASE)
#define DMA2_Stream6        ((DMA_Stream_TypeDef *) DMA2_Stream6_BASE)
#define DMA2_Stream7        ((DMA_Stream_TypeDef *) DMA2_Stream7_BASE)
#define DCMI                ((DCMI_TypeDef *) DCMI_BASE)
#define FMC_Bank1           ((FMC_Bank1_TypeDef *) FMC_Bank1_R_BASE)
#define FMC_Bank1E          ((FMC_Bank1E_TypeDef *) FMC_Bank1E_R_BASE)
#define FMC_Bank3           ((FMC_Bank3_TypeDef *) FMC_Bank3_R_BASE)
#define FMC_Bank5_6         ((FMC_Bank5_6_TypeDef *) FMC_Bank5_6_R_BASE)
#define QUADSPI             ((QUADSPI_TypeDef *) QSPI_R_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#define USB_OTG_FS          ((USB_OTG_GlobalTypeDef *) USB_OTG_FS_PERIPH_BASE)
#define USB_OTG_HS          ((USB_OTG_GlobalTypeDef *) USB_OTG_HS_PERIPH_BASE)

/****************************** USB Exported Constants ************************/
#define USB_OTG_FS_HOST_MAX_CHANNEL_NBR                12U
#define USB_OTG_FS_MAX_IN_ENDPOINTS                    6U    /* Including EP0 */
#define USB_OTG_FS_MAX_OUT_ENDPOINTS                   6U    /* Including EP0 */
#define USB_OTG_FS_TOTAL_FIFO_SIZE                     1280U /* in Bytes */
#define USB_OTG_HS_HOST_MAX_CHANNEL_NBR                16U
#define USB_OTG_HS_MAX_IN_ENDPOINTS                    9U    /* Including EP0 */
#define USB_OTG_HS_MAX_OUT_ENDPOINTS                   9U    /* Including EP0 */
#define USB_OTG_HS_TOTAL_FIFO_SIZE                     4096U /* in Bytes */

/*
 * @brief Specific devices reset values definitions
 */
#define RCC_PLLCFGR_RST_VALUE              0x24003010U
#define RCC_PLLI2SCFGR_RST_VALUE           0x24003010U
#define RCC_PLLSAICFGR_RST_VALUE           0x04003010U

#define RCC_MAX_FREQUENCY           180000000U         /*!< Max frequency of family in Hz*/
#define RCC_MAX_FREQUENCY_SCALE1    RCC_MAX_FREQUENCY  /*!< Maximum frequency for system clock at power scale1, in Hz */
#define RCC_MAX_FREQUENCY_SCALE2    168000000U         /*!< Maximum frequency for system clock at power scale2, in Hz */
#define RCC_MAX_FREQUENCY_SCALE3    120000000U         /*!< Maximum frequency for system clock at power scale3, in Hz */
#define RCC_PLLVCO_OUTPUT_MIN       100000000U       /*!< Frequency min for PLLVCO output, in Hz */
#define RCC_PLLVCO_INPUT_MIN           950000U       /*!< Frequency min for PLLVCO input, in Hz  */
#define RCC_PLLVCO_INPUT_MAX          2100000U       /*!< Frequency max for PLLVCO input, in Hz  */
#define RCC_PLLVCO_OUTPUT_MAX       432000000U       /*!< Frequency max for PLLVCO output, in Hz */

#define RCC_PLLN_MIN_VALUE                 50U
#define RCC_PLLN_MAX_VALUE                432U

#define FLASH_SCALE1_LATENCY1_FREQ   30000000U      /*!< HCLK frequency to set FLASH latency 1 in power scale 1  */
#define FLASH_SCALE1_LATENCY2_FREQ   60000000U      /*!< HCLK frequency to set FLASH latency 2 in power scale 1  */
#define FLASH_SCALE1_LATENCY3_FREQ   90000000U      /*!< HCLK frequency to set FLASH latency 3 in power scale 1  */
#define FLASH_SCALE1_LATENCY4_FREQ   120000000U     /*!< HCLK frequency to set FLASH latency 4 in power scale 1  */
#define FLASH_SCALE1_LATENCY5_FREQ   150000000U     /*!< HCLK frequency to set FLASH latency 5 in power scale 1  */

#define FLASH_SCALE2_LATENCY1_FREQ   30000000U      /*!< HCLK frequency to set FLASH latency 1 in power scale 2  */
#define FLASH_SCALE2_LATENCY2_FREQ   60000000U      /*!< HCLK frequency to set FLASH latency 2 in power scale 2  */
#define FLASH_SCALE2_LATENCY3_FREQ   90000000U      /*!< HCLK frequency to set FLASH latency 3 in power scale 2  */
#define FLASH_SCALE2_LATENCY4_FREQ   12000000U      /*!< HCLK frequency to set FLASH latency 4 in power scale 2  */
#define FLASH_SCALE2_LATENCY5_FREQ   150000000U     /*!< HCLK frequency to set FLASH latency 5 in power scale 2  */

#define FLASH_SCALE3_LATENCY1_FREQ   30000000U      /*!< HCLK frequency to set FLASH latency 1 in power scale 3  */
#define FLASH_SCALE3_LATENCY2_FREQ   60000000U      /*!< HCLK frequency to set FLASH latency 2 in power scale 3  */
#define FLASH_SCALE3_LATENCY3_FREQ   90000000U      /*!< HCLK frequency to set FLASH latency 3 in power scale 3  */

/******************************************************************************/
/*  For a painless codes migration between the STM32F4xx device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */
/*  product lines within the same STM32F4 Family                              */
/******************************************************************************/
/* Aliases for __IRQn */
#define FSMC_IRQn              FMC_IRQn

/* Aliases for __IRQHandler */
#define FSMC_IRQHandler        FMC_IRQHandler
#define QuadSPI_IRQHandler     QUADSPI_IRQHandler

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32F446xx_H */



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
