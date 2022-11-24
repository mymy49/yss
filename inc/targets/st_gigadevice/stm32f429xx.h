  /*******************************************************************************
  * @file    stm32f429xx.h
  * @author  MCD Application Team
  * @brief   CMSIS STM32F429xx Device Peripheral Access Layer Header File.
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

/** @addtogroup stm32f429xx
  * @{
  */
    
#ifndef __STM32F429xx_H
#define __STM32F429xx_H

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
  ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                                         */
  ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
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
  HASH_RNG_IRQn               = 80,     /*!< Hash and Rng global interrupt                                     */
  FPU_IRQn                    = 81,     /*!< FPU global interrupt                                              */
  UART7_IRQn                  = 82,     /*!< UART7 global interrupt                                            */
  UART8_IRQn                  = 83,     /*!< UART8 global interrupt                                            */
  SPI4_IRQn                   = 84,     /*!< SPI4 global Interrupt                                             */
  SPI5_IRQn                   = 85,     /*!< SPI5 global Interrupt                                             */
  SPI6_IRQn                   = 86,     /*!< SPI6 global Interrupt                                             */
  SAI1_IRQn                   = 87,     /*!< SAI1 global Interrupt                                             */
  LTDC_IRQn                   = 88,     /*!< LTDC global Interrupt                                              */
  LTDC_ER_IRQn                = 89,     /*!< LTDC Error global Interrupt                                        */
  DMA2D_IRQn                  = 90      /*!< DMA2D global Interrupt                                            */
} IRQn_Type;

/**
  * @}
  */

#include <cmsis/core_cm4.h>             /* Cortex-M4 processor and core peripherals */
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

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
  * @brief DMA2D Controller
  */

typedef struct
{
  __IO uint32_t CR;            /*!< DMA2D Control Register,                         Address offset: 0x00 */
  __IO uint32_t ISR;           /*!< DMA2D Interrupt Status Register,                Address offset: 0x04 */
  __IO uint32_t IFCR;          /*!< DMA2D Interrupt Flag Clear Register,            Address offset: 0x08 */
  __IO uint32_t FGMAR;         /*!< DMA2D Foreground Memory Address Register,       Address offset: 0x0C */
  __IO uint32_t FGOR;          /*!< DMA2D Foreground Offset Register,               Address offset: 0x10 */
  __IO uint32_t BGMAR;         /*!< DMA2D Background Memory Address Register,       Address offset: 0x14 */
  __IO uint32_t BGOR;          /*!< DMA2D Background Offset Register,               Address offset: 0x18 */
  __IO uint32_t FGPFCCR;       /*!< DMA2D Foreground PFC Control Register,          Address offset: 0x1C */
  __IO uint32_t FGCOLR;        /*!< DMA2D Foreground Color Register,                Address offset: 0x20 */
  __IO uint32_t BGPFCCR;       /*!< DMA2D Background PFC Control Register,          Address offset: 0x24 */
  __IO uint32_t BGCOLR;        /*!< DMA2D Background Color Register,                Address offset: 0x28 */
  __IO uint32_t FGCMAR;        /*!< DMA2D Foreground CLUT Memory Address Register,  Address offset: 0x2C */
  __IO uint32_t BGCMAR;        /*!< DMA2D Background CLUT Memory Address Register,  Address offset: 0x30 */
  __IO uint32_t OPFCCR;        /*!< DMA2D Output PFC Control Register,              Address offset: 0x34 */
  __IO uint32_t OCOLR;         /*!< DMA2D Output Color Register,                    Address offset: 0x38 */
  __IO uint32_t OMAR;          /*!< DMA2D Output Memory Address Register,           Address offset: 0x3C */
  __IO uint32_t OOR;           /*!< DMA2D Output Offset Register,                   Address offset: 0x40 */
  __IO uint32_t NLR;           /*!< DMA2D Number of Line Register,                  Address offset: 0x44 */
  __IO uint32_t LWR;           /*!< DMA2D Line Watermark Register,                  Address offset: 0x48 */
  __IO uint32_t AMTCR;         /*!< DMA2D AHB Master Timer Configuration Register,  Address offset: 0x4C */
  uint32_t      RESERVED[236]; /*!< Reserved, 0x50-0x3FF */
  __IO uint32_t FGCLUT[256];   /*!< DMA2D Foreground CLUT,                          Address offset:400-7FF */
  __IO uint32_t BGCLUT[256];   /*!< DMA2D Background CLUT,                          Address offset:800-BFF */
} DMA2D_TypeDef;

/** 
  * @brief Ethernet MAC
  */

typedef struct
{
  __IO uint32_t MACCR;
  __IO uint32_t MACFFR;
  __IO uint32_t MACHTHR;
  __IO uint32_t MACHTLR;
  __IO uint32_t MACMIIAR;
  __IO uint32_t MACMIIDR;
  __IO uint32_t MACFCR;
  __IO uint32_t MACVLANTR;             /*    8 */
  uint32_t      RESERVED0[2];
  __IO uint32_t MACRWUFFR;             /*   11 */
  __IO uint32_t MACPMTCSR;
  uint32_t      RESERVED1;
  __IO uint32_t MACDBGR;
  __IO uint32_t MACSR;                 /*   15 */
  __IO uint32_t MACIMR;
  __IO uint32_t MACA0HR;
  __IO uint32_t MACA0LR;
  __IO uint32_t MACA1HR;
  __IO uint32_t MACA1LR;
  __IO uint32_t MACA2HR;
  __IO uint32_t MACA2LR;
  __IO uint32_t MACA3HR;
  __IO uint32_t MACA3LR;               /*   24 */
  uint32_t      RESERVED2[40];
  __IO uint32_t MMCCR;                 /*   65 */
  __IO uint32_t MMCRIR;
  __IO uint32_t MMCTIR;
  __IO uint32_t MMCRIMR;
  __IO uint32_t MMCTIMR;               /*   69 */
  uint32_t      RESERVED3[14];
  __IO uint32_t MMCTGFSCCR;            /*   84 */
  __IO uint32_t MMCTGFMSCCR;
  uint32_t      RESERVED4[5];
  __IO uint32_t MMCTGFCR;
  uint32_t      RESERVED5[10];
  __IO uint32_t MMCRFCECR;
  __IO uint32_t MMCRFAECR;
  uint32_t      RESERVED6[10];
  __IO uint32_t MMCRGUFCR;
  uint32_t      RESERVED7[334];
  __IO uint32_t PTPTSCR;
  __IO uint32_t PTPSSIR;
  __IO uint32_t PTPTSHR;
  __IO uint32_t PTPTSLR;
  __IO uint32_t PTPTSHUR;
  __IO uint32_t PTPTSLUR;
  __IO uint32_t PTPTSAR;
  __IO uint32_t PTPTTHR;
  __IO uint32_t PTPTTLR;
  __IO uint32_t RESERVED8;
  __IO uint32_t PTPTSSR;
  uint32_t      RESERVED9[565];
  __IO uint32_t DMABMR;
  __IO uint32_t DMATPDR;
  __IO uint32_t DMARPDR;
  __IO uint32_t DMARDLAR;
  __IO uint32_t DMATDLAR;
  __IO uint32_t DMASR;
  __IO uint32_t DMAOMR;
  __IO uint32_t DMAIER;
  __IO uint32_t DMAMFBOCR;
  __IO uint32_t DMARSWTR;
  uint32_t      RESERVED10[8];
  __IO uint32_t DMACHTDR;
  __IO uint32_t DMACHRDR;
  __IO uint32_t DMACHTBAR;
  __IO uint32_t DMACHRBAR;
} ETH_TypeDef;

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
  * @brief Flexible Memory Controller Bank2
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
} FMC_Bank2_3_TypeDef;

/** 
  * @brief Flexible Memory Controller Bank4
  */
  
typedef struct
{
  __IO uint32_t PCR4;       /*!< PC Card  control register 4,                       Address offset: 0xA0 */
  __IO uint32_t SR4;        /*!< PC Card  FIFO status and interrupt register 4,     Address offset: 0xA4 */
  __IO uint32_t PMEM4;      /*!< PC Card  Common memory space timing register 4,    Address offset: 0xA8 */
  __IO uint32_t PATT4;      /*!< PC Card  Attribute memory space timing register 4, Address offset: 0xAC */
  __IO uint32_t PIO4;       /*!< PC Card  I/O space timing register 4,              Address offset: 0xB0 */
} FMC_Bank4_TypeDef;

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
  * @brief Window WATCHDOG
  */

typedef struct
{
  __IO uint32_t CR;   /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;  /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;   /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;

/** 
  * @brief RNG
  */
  
typedef struct 
{
  __IO uint32_t CR;  /*!< RNG control register, Address offset: 0x00 */
  __IO uint32_t SR;  /*!< RNG status register,  Address offset: 0x04 */
  __IO uint32_t DR;  /*!< RNG data register,    Address offset: 0x08 */
} RNG_TypeDef;

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
  uint32_t  Reserved40[48];           /*!< Reserved                                0x40-0xFF */
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
#define FLASH_BASE            0x08000000UL /*!< FLASH(up to 2 MB) base address in the alias region                         */
#define CCMDATARAM_BASE       0x10000000UL /*!< CCM(core coupled memory) data RAM(64 KB) base address in the alias region  */
#define SRAM1_BASE            0x20000000UL /*!< SRAM1(112 KB) base address in the alias region                              */
#define SRAM2_BASE            0x2001C000UL /*!< SRAM2(16 KB) base address in the alias region                              */
#define SRAM3_BASE            0x20020000UL /*!< SRAM3(64 KB) base address in the alias region                              */
#define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region                                */
#define BKPSRAM_BASE          0x40024000UL /*!< Backup SRAM(4 KB) base address in the alias region                         */
#define FMC_R_BASE            0xA0000000UL /*!< FMC registers base address                                                 */
#define SRAM1_BB_BASE         0x22000000UL /*!< SRAM1(112 KB) base address in the bit-band region                          */
#define SRAM2_BB_BASE         0x22380000UL /*!< SRAM2(16 KB) base address in the bit-band region                           */
#define SRAM3_BB_BASE         0x22400000UL /*!< SRAM3(64 KB) base address in the bit-band region                           */
#define PERIPH_BB_BASE        0x42000000UL /*!< Peripheral base address in the bit-band region                             */
#define BKPSRAM_BB_BASE       0x42480000UL /*!< Backup SRAM(4 KB) base address in the bit-band region                      */
#define FLASH_END             0x081FFFFFUL /*!< FLASH end address                                                          */
#define FLASH_OTP_BASE        0x1FFF7800UL /*!< Base address of : (up to 528 Bytes) embedded FLASH OTP Area                */
#define FLASH_OTP_END         0x1FFF7A0FUL /*!< End address of : (up to 528 Bytes) embedded FLASH OTP Area                 */
#define CCMDATARAM_END        0x1000FFFFUL /*!< CCM data RAM end address                                                   */

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
#define I2S2ext_BASE          (APB1PERIPH_BASE + 0x3400UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)
#define I2S3ext_BASE          (APB1PERIPH_BASE + 0x4000UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x5C00UL)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400UL)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000UL)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400UL)
#define UART7_BASE            (APB1PERIPH_BASE + 0x7800UL)
#define UART8_BASE            (APB1PERIPH_BASE + 0x7C00UL)

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
#define SPI5_BASE             (APB2PERIPH_BASE + 0x5000UL)
#define SPI6_BASE             (APB2PERIPH_BASE + 0x5400UL)
#define SAI1_BASE             (APB2PERIPH_BASE + 0x5800UL)
#define SAI1_Block_A_BASE     (SAI1_BASE + 0x004UL)
#define SAI1_Block_B_BASE     (SAI1_BASE + 0x024UL)
#define LTDC_BASE             (APB2PERIPH_BASE + 0x6800UL)
#define LTDC_Layer1_BASE      (LTDC_BASE + 0x84UL)
#define LTDC_Layer2_BASE      (LTDC_BASE + 0x104UL)

/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000UL)
#define GPIOJ_BASE            (AHB1PERIPH_BASE + 0x2400UL)
#define GPIOK_BASE            (AHB1PERIPH_BASE + 0x2800UL)
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
#define ETH_BASE              (AHB1PERIPH_BASE + 0x8000UL)
#define ETH_MAC_BASE          (ETH_BASE)
#define ETH_MMC_BASE          (ETH_BASE + 0x0100UL)
#define ETH_PTP_BASE          (ETH_BASE + 0x0700UL)
#define ETH_DMA_BASE          (ETH_BASE + 0x1000UL)
#define DMA2D_BASE            (AHB1PERIPH_BASE + 0xB000UL)

/*!< AHB2 peripherals */
#define DCMI_BASE             (AHB2PERIPH_BASE + 0x50000UL)
#define RNG_BASE              (AHB2PERIPH_BASE + 0x60800UL)

/*!< FMC Bankx registers base address */
#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000UL)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104UL)
#define FMC_Bank2_3_R_BASE    (FMC_R_BASE + 0x0060UL)
#define FMC_Bank4_R_BASE      (FMC_R_BASE + 0x00A0UL)
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
#define TIM2                ((volatile uint32_t *) TIM2_BASE)
#define TIM3                ((volatile uint32_t *) TIM3_BASE)
#define TIM4                ((volatile uint32_t *) TIM4_BASE)
#define TIM5                ((volatile uint32_t *) TIM5_BASE)
#define TIM6                ((volatile uint32_t *) TIM6_BASE)
#define TIM7                ((volatile uint32_t *) TIM7_BASE)
#define TIM12               ((volatile uint32_t *) TIM12_BASE)
#define TIM13               ((volatile uint32_t *) TIM13_BASE)
#define TIM14               ((volatile uint32_t *) TIM14_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define I2S2ext             ((volatile uint32_t *) I2S2ext_BASE)
#define SPI2                ((volatile uint32_t *) SPI2_BASE)
#define SPI3                ((volatile uint32_t *) SPI3_BASE)
#define I2S3ext             ((volatile uint32_t *) I2S3ext_BASE)
#define USART2              ((volatile uint32_t *) USART2_BASE)
#define USART3              ((volatile uint32_t *) USART3_BASE)
#define UART4               ((volatile uint32_t *) UART4_BASE)
#define UART5               ((volatile uint32_t *) UART5_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define I2C3                ((I2C_TypeDef *) I2C3_BASE)
#define CAN1                ((CAN_TypeDef *) CAN1_BASE)
#define CAN2                ((CAN_TypeDef *) CAN2_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define DAC1                ((DAC_TypeDef *) DAC_BASE)
#define DAC                 ((DAC_TypeDef *) DAC_BASE) /* Kept for legacy purpose */
#define UART7               ((volatile uint32_t *) UART7_BASE)
#define UART8               ((volatile uint32_t *) UART8_BASE)
#define TIM1                ((volatile uint32_t *) TIM1_BASE)
#define TIM8                ((volatile uint32_t *) TIM8_BASE)
#define USART1              ((volatile uint32_t *) USART1_BASE)
#define USART6              ((volatile uint32_t *) USART6_BASE)
#define ADC1                ((volatile uint32_t *) ADC1_BASE)
#define ADC2                ((volatile uint32_t *) ADC2_BASE)
#define ADC3                ((volatile uint32_t *) ADC3_BASE)
#define ADC123_COMMON       ((volatile uint32_t *) ADC123_COMMON_BASE)
/* Legacy define */
#define ADC                  ADC123_COMMON
#define SDIO                ((SDIO_TypeDef *) SDIO_BASE)
#define SPI1                ((volatile uint32_t *) SPI1_BASE)
#define SPI4                ((volatile uint32_t *) SPI4_BASE)
#define SYSCFG              ((volatile uint32_t *) SYSCFG_BASE)
#define EXTI                ((volatile uint32_t *) EXTI_BASE)
#define TIM9                ((volatile uint32_t *) TIM9_BASE)
#define TIM10               ((volatile uint32_t *) TIM10_BASE)
#define TIM11               ((volatile uint32_t *) TIM11_BASE)
#define SPI5                ((volatile uint32_t *) SPI5_BASE)
#define SPI6                ((volatile uint32_t *) SPI6_BASE)
#define SAI1                ((SAI_TypeDef *) SAI1_BASE)
#define SAI1_Block_A        ((SAI_Block_TypeDef *)SAI1_Block_A_BASE)
#define SAI1_Block_B        ((SAI_Block_TypeDef *)SAI1_Block_B_BASE)
#define LTDC                ((volatile uint32_t *)LTDC_BASE)
#define LTDC_Layer1         ((volatile uint32_t *)LTDC_Layer1_BASE)
#define LTDC_Layer2         ((volatile uint32_t *)LTDC_Layer2_BASE)
#define GPIOA               ((volatile uint32_t *) GPIOA_BASE)
#define GPIOB               ((volatile uint32_t *) GPIOB_BASE)
#define GPIOC               ((volatile uint32_t *) GPIOC_BASE)
#define GPIOD               ((volatile uint32_t *) GPIOD_BASE)
#define GPIOE               ((volatile uint32_t *) GPIOE_BASE)
#define GPIOF               ((volatile uint32_t *) GPIOF_BASE)
#define GPIOG               ((volatile uint32_t *) GPIOG_BASE)
#define GPIOH               ((volatile uint32_t *) GPIOH_BASE)
#define GPIOI               ((volatile uint32_t *) GPIOI_BASE)
#define GPIOJ               ((volatile uint32_t *) GPIOJ_BASE)
#define GPIOK               ((volatile uint32_t *) GPIOK_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define RCC                 ((volatile uint32_t *) RCC_BASE)
#define FLASH               ((volatile uint32_t *) FLASH_R_BASE)
#define DMA1                ((volatile uint32_t *) DMA1_BASE)
#define DMA1_Stream0        ((volatile uint32_t *) DMA1_Stream0_BASE)
#define DMA1_Stream1        ((volatile uint32_t *) DMA1_Stream1_BASE)
#define DMA1_Stream2        ((volatile uint32_t *) DMA1_Stream2_BASE)
#define DMA1_Stream3        ((volatile uint32_t *) DMA1_Stream3_BASE)
#define DMA1_Stream4        ((volatile uint32_t *) DMA1_Stream4_BASE)
#define DMA1_Stream5        ((volatile uint32_t *) DMA1_Stream5_BASE)
#define DMA1_Stream6        ((volatile uint32_t *) DMA1_Stream6_BASE)
#define DMA1_Stream7        ((volatile uint32_t *) DMA1_Stream7_BASE)
#define DMA2                ((volatile uint32_t *) DMA2_BASE)
#define DMA2_Stream0        ((volatile uint32_t *) DMA2_Stream0_BASE)
#define DMA2_Stream1        ((volatile uint32_t *) DMA2_Stream1_BASE)
#define DMA2_Stream2        ((volatile uint32_t *) DMA2_Stream2_BASE)
#define DMA2_Stream3        ((volatile uint32_t *) DMA2_Stream3_BASE)
#define DMA2_Stream4        ((volatile uint32_t *) DMA2_Stream4_BASE)
#define DMA2_Stream5        ((volatile uint32_t *) DMA2_Stream5_BASE)
#define DMA2_Stream6        ((volatile uint32_t *) DMA2_Stream6_BASE)
#define DMA2_Stream7        ((volatile uint32_t *) DMA2_Stream7_BASE)
#define ETH                 ((ETH_TypeDef *) ETH_BASE)  
#define DMA2D               ((DMA2D_TypeDef *)DMA2D_BASE)
#define DCMI                ((DCMI_TypeDef *) DCMI_BASE)
#define RNG                 ((RNG_TypeDef *) RNG_BASE)
#define FMC_Bank1           ((FMC_Bank1_TypeDef *) FMC_Bank1_R_BASE)
#define FMC_Bank1E          ((FMC_Bank1E_TypeDef *) FMC_Bank1E_R_BASE)
#define FMC_Bank2_3         ((FMC_Bank2_3_TypeDef *) FMC_Bank2_3_R_BASE)
#define FMC_Bank4           ((FMC_Bank4_TypeDef *) FMC_Bank4_R_BASE)
#define FMC_Bank5_6         ((volatile uint32_t *) FMC_Bank5_6_R_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#define USB_OTG_FS          ((USB_OTG_GlobalTypeDef *) USB_OTG_FS_PERIPH_BASE)
#define USB_OTG_HS          ((USB_OTG_GlobalTypeDef *) USB_OTG_HS_PERIPH_BASE)

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
/*                         Controller Area Network                            */
/*                                                                            */
/******************************************************************************/
/*!<CAN control and status registers */
/*******************  Bit definition for CAN_MCR register  ********************/
#define CAN_MCR_INRQ_Pos       (0U)                                            
#define CAN_MCR_INRQ_Msk       (0x1UL << CAN_MCR_INRQ_Pos)                      /*!< 0x00000001 */
#define CAN_MCR_INRQ           CAN_MCR_INRQ_Msk                                /*!<Initialization Request */
#define CAN_MCR_SLEEP_Pos      (1U)                                            
#define CAN_MCR_SLEEP_Msk      (0x1UL << CAN_MCR_SLEEP_Pos)                     /*!< 0x00000002 */
#define CAN_MCR_SLEEP          CAN_MCR_SLEEP_Msk                               /*!<Sleep Mode Request */
#define CAN_MCR_TXFP_Pos       (2U)                                            
#define CAN_MCR_TXFP_Msk       (0x1UL << CAN_MCR_TXFP_Pos)                      /*!< 0x00000004 */
#define CAN_MCR_TXFP           CAN_MCR_TXFP_Msk                                /*!<Transmit FIFO Priority */
#define CAN_MCR_RFLM_Pos       (3U)                                            
#define CAN_MCR_RFLM_Msk       (0x1UL << CAN_MCR_RFLM_Pos)                      /*!< 0x00000008 */
#define CAN_MCR_RFLM           CAN_MCR_RFLM_Msk                                /*!<Receive FIFO Locked Mode */
#define CAN_MCR_NART_Pos       (4U)                                            
#define CAN_MCR_NART_Msk       (0x1UL << CAN_MCR_NART_Pos)                      /*!< 0x00000010 */
#define CAN_MCR_NART           CAN_MCR_NART_Msk                                /*!<No Automatic Retransmission */
#define CAN_MCR_AWUM_Pos       (5U)                                            
#define CAN_MCR_AWUM_Msk       (0x1UL << CAN_MCR_AWUM_Pos)                      /*!< 0x00000020 */
#define CAN_MCR_AWUM           CAN_MCR_AWUM_Msk                                /*!<Automatic Wakeup Mode */
#define CAN_MCR_ABOM_Pos       (6U)                                            
#define CAN_MCR_ABOM_Msk       (0x1UL << CAN_MCR_ABOM_Pos)                      /*!< 0x00000040 */
#define CAN_MCR_ABOM           CAN_MCR_ABOM_Msk                                /*!<Automatic Bus-Off Management */
#define CAN_MCR_TTCM_Pos       (7U)                                            
#define CAN_MCR_TTCM_Msk       (0x1UL << CAN_MCR_TTCM_Pos)                      /*!< 0x00000080 */
#define CAN_MCR_TTCM           CAN_MCR_TTCM_Msk                                /*!<Time Triggered Communication Mode */
#define CAN_MCR_RESET_Pos      (15U)                                           
#define CAN_MCR_RESET_Msk      (0x1UL << CAN_MCR_RESET_Pos)                     /*!< 0x00008000 */
#define CAN_MCR_RESET          CAN_MCR_RESET_Msk                               /*!<bxCAN software master reset */
#define CAN_MCR_DBF_Pos        (16U)                                           
#define CAN_MCR_DBF_Msk        (0x1UL << CAN_MCR_DBF_Pos)                       /*!< 0x00010000 */
#define CAN_MCR_DBF            CAN_MCR_DBF_Msk                                 /*!<bxCAN Debug freeze */
/*******************  Bit definition for CAN_MSR register  ********************/
#define CAN_MSR_INAK_Pos       (0U)                                            
#define CAN_MSR_INAK_Msk       (0x1UL << CAN_MSR_INAK_Pos)                      /*!< 0x00000001 */
#define CAN_MSR_INAK           CAN_MSR_INAK_Msk                                /*!<Initialization Acknowledge */
#define CAN_MSR_SLAK_Pos       (1U)                                            
#define CAN_MSR_SLAK_Msk       (0x1UL << CAN_MSR_SLAK_Pos)                      /*!< 0x00000002 */
#define CAN_MSR_SLAK           CAN_MSR_SLAK_Msk                                /*!<Sleep Acknowledge */
#define CAN_MSR_ERRI_Pos       (2U)                                            
#define CAN_MSR_ERRI_Msk       (0x1UL << CAN_MSR_ERRI_Pos)                      /*!< 0x00000004 */
#define CAN_MSR_ERRI           CAN_MSR_ERRI_Msk                                /*!<Error Interrupt */
#define CAN_MSR_WKUI_Pos       (3U)                                            
#define CAN_MSR_WKUI_Msk       (0x1UL << CAN_MSR_WKUI_Pos)                      /*!< 0x00000008 */
#define CAN_MSR_WKUI           CAN_MSR_WKUI_Msk                                /*!<Wakeup Interrupt */
#define CAN_MSR_SLAKI_Pos      (4U)                                            
#define CAN_MSR_SLAKI_Msk      (0x1UL << CAN_MSR_SLAKI_Pos)                     /*!< 0x00000010 */
#define CAN_MSR_SLAKI          CAN_MSR_SLAKI_Msk                               /*!<Sleep Acknowledge Interrupt */
#define CAN_MSR_TXM_Pos        (8U)                                            
#define CAN_MSR_TXM_Msk        (0x1UL << CAN_MSR_TXM_Pos)                       /*!< 0x00000100 */
#define CAN_MSR_TXM            CAN_MSR_TXM_Msk                                 /*!<Transmit Mode */
#define CAN_MSR_RXM_Pos        (9U)                                            
#define CAN_MSR_RXM_Msk        (0x1UL << CAN_MSR_RXM_Pos)                       /*!< 0x00000200 */
#define CAN_MSR_RXM            CAN_MSR_RXM_Msk                                 /*!<Receive Mode */
#define CAN_MSR_SAMP_Pos       (10U)                                           
#define CAN_MSR_SAMP_Msk       (0x1UL << CAN_MSR_SAMP_Pos)                      /*!< 0x00000400 */
#define CAN_MSR_SAMP           CAN_MSR_SAMP_Msk                                /*!<Last Sample Point */
#define CAN_MSR_RX_Pos         (11U)                                           
#define CAN_MSR_RX_Msk         (0x1UL << CAN_MSR_RX_Pos)                        /*!< 0x00000800 */
#define CAN_MSR_RX             CAN_MSR_RX_Msk                                  /*!<CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define CAN_TSR_RQCP0_Pos      (0U)                                            
#define CAN_TSR_RQCP0_Msk      (0x1UL << CAN_TSR_RQCP0_Pos)                     /*!< 0x00000001 */
#define CAN_TSR_RQCP0          CAN_TSR_RQCP0_Msk                               /*!<Request Completed Mailbox0 */
#define CAN_TSR_TXOK0_Pos      (1U)                                            
#define CAN_TSR_TXOK0_Msk      (0x1UL << CAN_TSR_TXOK0_Pos)                     /*!< 0x00000002 */
#define CAN_TSR_TXOK0          CAN_TSR_TXOK0_Msk                               /*!<Transmission OK of Mailbox0 */
#define CAN_TSR_ALST0_Pos      (2U)                                            
#define CAN_TSR_ALST0_Msk      (0x1UL << CAN_TSR_ALST0_Pos)                     /*!< 0x00000004 */
#define CAN_TSR_ALST0          CAN_TSR_ALST0_Msk                               /*!<Arbitration Lost for Mailbox0 */
#define CAN_TSR_TERR0_Pos      (3U)                                            
#define CAN_TSR_TERR0_Msk      (0x1UL << CAN_TSR_TERR0_Pos)                     /*!< 0x00000008 */
#define CAN_TSR_TERR0          CAN_TSR_TERR0_Msk                               /*!<Transmission Error of Mailbox0 */
#define CAN_TSR_ABRQ0_Pos      (7U)                                            
#define CAN_TSR_ABRQ0_Msk      (0x1UL << CAN_TSR_ABRQ0_Pos)                     /*!< 0x00000080 */
#define CAN_TSR_ABRQ0          CAN_TSR_ABRQ0_Msk                               /*!<Abort Request for Mailbox0 */
#define CAN_TSR_RQCP1_Pos      (8U)                                            
#define CAN_TSR_RQCP1_Msk      (0x1UL << CAN_TSR_RQCP1_Pos)                     /*!< 0x00000100 */
#define CAN_TSR_RQCP1          CAN_TSR_RQCP1_Msk                               /*!<Request Completed Mailbox1 */
#define CAN_TSR_TXOK1_Pos      (9U)                                            
#define CAN_TSR_TXOK1_Msk      (0x1UL << CAN_TSR_TXOK1_Pos)                     /*!< 0x00000200 */
#define CAN_TSR_TXOK1          CAN_TSR_TXOK1_Msk                               /*!<Transmission OK of Mailbox1 */
#define CAN_TSR_ALST1_Pos      (10U)                                           
#define CAN_TSR_ALST1_Msk      (0x1UL << CAN_TSR_ALST1_Pos)                     /*!< 0x00000400 */
#define CAN_TSR_ALST1          CAN_TSR_ALST1_Msk                               /*!<Arbitration Lost for Mailbox1 */
#define CAN_TSR_TERR1_Pos      (11U)                                           
#define CAN_TSR_TERR1_Msk      (0x1UL << CAN_TSR_TERR1_Pos)                     /*!< 0x00000800 */
#define CAN_TSR_TERR1          CAN_TSR_TERR1_Msk                               /*!<Transmission Error of Mailbox1 */
#define CAN_TSR_ABRQ1_Pos      (15U)                                           
#define CAN_TSR_ABRQ1_Msk      (0x1UL << CAN_TSR_ABRQ1_Pos)                     /*!< 0x00008000 */
#define CAN_TSR_ABRQ1          CAN_TSR_ABRQ1_Msk                               /*!<Abort Request for Mailbox 1 */
#define CAN_TSR_RQCP2_Pos      (16U)                                           
#define CAN_TSR_RQCP2_Msk      (0x1UL << CAN_TSR_RQCP2_Pos)                     /*!< 0x00010000 */
#define CAN_TSR_RQCP2          CAN_TSR_RQCP2_Msk                               /*!<Request Completed Mailbox2 */
#define CAN_TSR_TXOK2_Pos      (17U)                                           
#define CAN_TSR_TXOK2_Msk      (0x1UL << CAN_TSR_TXOK2_Pos)                     /*!< 0x00020000 */
#define CAN_TSR_TXOK2          CAN_TSR_TXOK2_Msk                               /*!<Transmission OK of Mailbox 2 */
#define CAN_TSR_ALST2_Pos      (18U)                                           
#define CAN_TSR_ALST2_Msk      (0x1UL << CAN_TSR_ALST2_Pos)                     /*!< 0x00040000 */
#define CAN_TSR_ALST2          CAN_TSR_ALST2_Msk                               /*!<Arbitration Lost for mailbox 2 */
#define CAN_TSR_TERR2_Pos      (19U)                                           
#define CAN_TSR_TERR2_Msk      (0x1UL << CAN_TSR_TERR2_Pos)                     /*!< 0x00080000 */
#define CAN_TSR_TERR2          CAN_TSR_TERR2_Msk                               /*!<Transmission Error of Mailbox 2 */
#define CAN_TSR_ABRQ2_Pos      (23U)                                           
#define CAN_TSR_ABRQ2_Msk      (0x1UL << CAN_TSR_ABRQ2_Pos)                     /*!< 0x00800000 */
#define CAN_TSR_ABRQ2          CAN_TSR_ABRQ2_Msk                               /*!<Abort Request for Mailbox 2 */
#define CAN_TSR_CODE_Pos       (24U)                                           
#define CAN_TSR_CODE_Msk       (0x3UL << CAN_TSR_CODE_Pos)                      /*!< 0x03000000 */
#define CAN_TSR_CODE           CAN_TSR_CODE_Msk                                /*!<Mailbox Code */

#define CAN_TSR_TME_Pos        (26U)                                           
#define CAN_TSR_TME_Msk        (0x7UL << CAN_TSR_TME_Pos)                       /*!< 0x1C000000 */
#define CAN_TSR_TME            CAN_TSR_TME_Msk                                 /*!<TME[2:0] bits */
#define CAN_TSR_TME0_Pos       (26U)                                           
#define CAN_TSR_TME0_Msk       (0x1UL << CAN_TSR_TME0_Pos)                      /*!< 0x04000000 */
#define CAN_TSR_TME0           CAN_TSR_TME0_Msk                                /*!<Transmit Mailbox 0 Empty */
#define CAN_TSR_TME1_Pos       (27U)                                           
#define CAN_TSR_TME1_Msk       (0x1UL << CAN_TSR_TME1_Pos)                      /*!< 0x08000000 */
#define CAN_TSR_TME1           CAN_TSR_TME1_Msk                                /*!<Transmit Mailbox 1 Empty */
#define CAN_TSR_TME2_Pos       (28U)                                           
#define CAN_TSR_TME2_Msk       (0x1UL << CAN_TSR_TME2_Pos)                      /*!< 0x10000000 */
#define CAN_TSR_TME2           CAN_TSR_TME2_Msk                                /*!<Transmit Mailbox 2 Empty */

#define CAN_TSR_LOW_Pos        (29U)                                           
#define CAN_TSR_LOW_Msk        (0x7UL << CAN_TSR_LOW_Pos)                       /*!< 0xE0000000 */
#define CAN_TSR_LOW            CAN_TSR_LOW_Msk                                 /*!<LOW[2:0] bits */
#define CAN_TSR_LOW0_Pos       (29U)                                           
#define CAN_TSR_LOW0_Msk       (0x1UL << CAN_TSR_LOW0_Pos)                      /*!< 0x20000000 */
#define CAN_TSR_LOW0           CAN_TSR_LOW0_Msk                                /*!<Lowest Priority Flag for Mailbox 0 */
#define CAN_TSR_LOW1_Pos       (30U)                                           
#define CAN_TSR_LOW1_Msk       (0x1UL << CAN_TSR_LOW1_Pos)                      /*!< 0x40000000 */
#define CAN_TSR_LOW1           CAN_TSR_LOW1_Msk                                /*!<Lowest Priority Flag for Mailbox 1 */
#define CAN_TSR_LOW2_Pos       (31U)                                           
#define CAN_TSR_LOW2_Msk       (0x1UL << CAN_TSR_LOW2_Pos)                      /*!< 0x80000000 */
#define CAN_TSR_LOW2           CAN_TSR_LOW2_Msk                                /*!<Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define CAN_RF0R_FMP0_Pos      (0U)                                            
#define CAN_RF0R_FMP0_Msk      (0x3UL << CAN_RF0R_FMP0_Pos)                     /*!< 0x00000003 */
#define CAN_RF0R_FMP0          CAN_RF0R_FMP0_Msk                               /*!<FIFO 0 Message Pending */
#define CAN_RF0R_FULL0_Pos     (3U)                                            
#define CAN_RF0R_FULL0_Msk     (0x1UL << CAN_RF0R_FULL0_Pos)                    /*!< 0x00000008 */
#define CAN_RF0R_FULL0         CAN_RF0R_FULL0_Msk                              /*!<FIFO 0 Full */
#define CAN_RF0R_FOVR0_Pos     (4U)                                            
#define CAN_RF0R_FOVR0_Msk     (0x1UL << CAN_RF0R_FOVR0_Pos)                    /*!< 0x00000010 */
#define CAN_RF0R_FOVR0         CAN_RF0R_FOVR0_Msk                              /*!<FIFO 0 Overrun */
#define CAN_RF0R_RFOM0_Pos     (5U)                                            
#define CAN_RF0R_RFOM0_Msk     (0x1UL << CAN_RF0R_RFOM0_Pos)                    /*!< 0x00000020 */
#define CAN_RF0R_RFOM0         CAN_RF0R_RFOM0_Msk                              /*!<Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define CAN_RF1R_FMP1_Pos      (0U)                                            
#define CAN_RF1R_FMP1_Msk      (0x3UL << CAN_RF1R_FMP1_Pos)                     /*!< 0x00000003 */
#define CAN_RF1R_FMP1          CAN_RF1R_FMP1_Msk                               /*!<FIFO 1 Message Pending */
#define CAN_RF1R_FULL1_Pos     (3U)                                            
#define CAN_RF1R_FULL1_Msk     (0x1UL << CAN_RF1R_FULL1_Pos)                    /*!< 0x00000008 */
#define CAN_RF1R_FULL1         CAN_RF1R_FULL1_Msk                              /*!<FIFO 1 Full */
#define CAN_RF1R_FOVR1_Pos     (4U)                                            
#define CAN_RF1R_FOVR1_Msk     (0x1UL << CAN_RF1R_FOVR1_Pos)                    /*!< 0x00000010 */
#define CAN_RF1R_FOVR1         CAN_RF1R_FOVR1_Msk                              /*!<FIFO 1 Overrun */
#define CAN_RF1R_RFOM1_Pos     (5U)                                            
#define CAN_RF1R_RFOM1_Msk     (0x1UL << CAN_RF1R_RFOM1_Pos)                    /*!< 0x00000020 */
#define CAN_RF1R_RFOM1         CAN_RF1R_RFOM1_Msk                              /*!<Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define CAN_IER_TMEIE_Pos      (0U)                                            
#define CAN_IER_TMEIE_Msk      (0x1UL << CAN_IER_TMEIE_Pos)                     /*!< 0x00000001 */
#define CAN_IER_TMEIE          CAN_IER_TMEIE_Msk                               /*!<Transmit Mailbox Empty Interrupt Enable */
#define CAN_IER_FMPIE0_Pos     (1U)                                            
#define CAN_IER_FMPIE0_Msk     (0x1UL << CAN_IER_FMPIE0_Pos)                    /*!< 0x00000002 */
#define CAN_IER_FMPIE0         CAN_IER_FMPIE0_Msk                              /*!<FIFO Message Pending Interrupt Enable */
#define CAN_IER_FFIE0_Pos      (2U)                                            
#define CAN_IER_FFIE0_Msk      (0x1UL << CAN_IER_FFIE0_Pos)                     /*!< 0x00000004 */
#define CAN_IER_FFIE0          CAN_IER_FFIE0_Msk                               /*!<FIFO Full Interrupt Enable */
#define CAN_IER_FOVIE0_Pos     (3U)                                            
#define CAN_IER_FOVIE0_Msk     (0x1UL << CAN_IER_FOVIE0_Pos)                    /*!< 0x00000008 */
#define CAN_IER_FOVIE0         CAN_IER_FOVIE0_Msk                              /*!<FIFO Overrun Interrupt Enable */
#define CAN_IER_FMPIE1_Pos     (4U)                                            
#define CAN_IER_FMPIE1_Msk     (0x1UL << CAN_IER_FMPIE1_Pos)                    /*!< 0x00000010 */
#define CAN_IER_FMPIE1         CAN_IER_FMPIE1_Msk                              /*!<FIFO Message Pending Interrupt Enable */
#define CAN_IER_FFIE1_Pos      (5U)                                            
#define CAN_IER_FFIE1_Msk      (0x1UL << CAN_IER_FFIE1_Pos)                     /*!< 0x00000020 */
#define CAN_IER_FFIE1          CAN_IER_FFIE1_Msk                               /*!<FIFO Full Interrupt Enable */
#define CAN_IER_FOVIE1_Pos     (6U)                                            
#define CAN_IER_FOVIE1_Msk     (0x1UL << CAN_IER_FOVIE1_Pos)                    /*!< 0x00000040 */
#define CAN_IER_FOVIE1         CAN_IER_FOVIE1_Msk                              /*!<FIFO Overrun Interrupt Enable */
#define CAN_IER_EWGIE_Pos      (8U)                                            
#define CAN_IER_EWGIE_Msk      (0x1UL << CAN_IER_EWGIE_Pos)                     /*!< 0x00000100 */
#define CAN_IER_EWGIE          CAN_IER_EWGIE_Msk                               /*!<Error Warning Interrupt Enable */
#define CAN_IER_EPVIE_Pos      (9U)                                            
#define CAN_IER_EPVIE_Msk      (0x1UL << CAN_IER_EPVIE_Pos)                     /*!< 0x00000200 */
#define CAN_IER_EPVIE          CAN_IER_EPVIE_Msk                               /*!<Error Passive Interrupt Enable */
#define CAN_IER_BOFIE_Pos      (10U)                                           
#define CAN_IER_BOFIE_Msk      (0x1UL << CAN_IER_BOFIE_Pos)                     /*!< 0x00000400 */
#define CAN_IER_BOFIE          CAN_IER_BOFIE_Msk                               /*!<Bus-Off Interrupt Enable */
#define CAN_IER_LECIE_Pos      (11U)                                           
#define CAN_IER_LECIE_Msk      (0x1UL << CAN_IER_LECIE_Pos)                     /*!< 0x00000800 */
#define CAN_IER_LECIE          CAN_IER_LECIE_Msk                               /*!<Last Error Code Interrupt Enable */
#define CAN_IER_ERRIE_Pos      (15U)                                           
#define CAN_IER_ERRIE_Msk      (0x1UL << CAN_IER_ERRIE_Pos)                     /*!< 0x00008000 */
#define CAN_IER_ERRIE          CAN_IER_ERRIE_Msk                               /*!<Error Interrupt Enable */
#define CAN_IER_WKUIE_Pos      (16U)                                           
#define CAN_IER_WKUIE_Msk      (0x1UL << CAN_IER_WKUIE_Pos)                     /*!< 0x00010000 */
#define CAN_IER_WKUIE          CAN_IER_WKUIE_Msk                               /*!<Wakeup Interrupt Enable */
#define CAN_IER_SLKIE_Pos      (17U)                                           
#define CAN_IER_SLKIE_Msk      (0x1UL << CAN_IER_SLKIE_Pos)                     /*!< 0x00020000 */
#define CAN_IER_SLKIE          CAN_IER_SLKIE_Msk                               /*!<Sleep Interrupt Enable */
#define CAN_IER_EWGIE_Pos      (8U)                                            

/********************  Bit definition for CAN_ESR register  *******************/
#define CAN_ESR_EWGF_Pos       (0U)                                            
#define CAN_ESR_EWGF_Msk       (0x1UL << CAN_ESR_EWGF_Pos)                      /*!< 0x00000001 */
#define CAN_ESR_EWGF           CAN_ESR_EWGF_Msk                                /*!<Error Warning Flag */
#define CAN_ESR_EPVF_Pos       (1U)                                            
#define CAN_ESR_EPVF_Msk       (0x1UL << CAN_ESR_EPVF_Pos)                      /*!< 0x00000002 */
#define CAN_ESR_EPVF           CAN_ESR_EPVF_Msk                                /*!<Error Passive Flag */
#define CAN_ESR_BOFF_Pos       (2U)                                            
#define CAN_ESR_BOFF_Msk       (0x1UL << CAN_ESR_BOFF_Pos)                      /*!< 0x00000004 */
#define CAN_ESR_BOFF           CAN_ESR_BOFF_Msk                                /*!<Bus-Off Flag */

#define CAN_ESR_LEC_Pos        (4U)                                            
#define CAN_ESR_LEC_Msk        (0x7UL << CAN_ESR_LEC_Pos)                       /*!< 0x00000070 */
#define CAN_ESR_LEC            CAN_ESR_LEC_Msk                                 /*!<LEC[2:0] bits (Last Error Code) */
#define CAN_ESR_LEC_0          (0x1UL << CAN_ESR_LEC_Pos)                       /*!< 0x00000010 */
#define CAN_ESR_LEC_1          (0x2UL << CAN_ESR_LEC_Pos)                       /*!< 0x00000020 */
#define CAN_ESR_LEC_2          (0x4UL << CAN_ESR_LEC_Pos)                       /*!< 0x00000040 */

#define CAN_ESR_TEC_Pos        (16U)                                           
#define CAN_ESR_TEC_Msk        (0xFFUL << CAN_ESR_TEC_Pos)                      /*!< 0x00FF0000 */
#define CAN_ESR_TEC            CAN_ESR_TEC_Msk                                 /*!<Least significant byte of the 9-bit Transmit Error Counter */
#define CAN_ESR_REC_Pos        (24U)                                           
#define CAN_ESR_REC_Msk        (0xFFUL << CAN_ESR_REC_Pos)                      /*!< 0xFF000000 */
#define CAN_ESR_REC            CAN_ESR_REC_Msk                                 /*!<Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define CAN_BTR_BRP_Pos        (0U)                                            
#define CAN_BTR_BRP_Msk        (0x3FFUL << CAN_BTR_BRP_Pos)                     /*!< 0x000003FF */
#define CAN_BTR_BRP            CAN_BTR_BRP_Msk                                 /*!<Baud Rate Prescaler */
#define CAN_BTR_TS1_Pos        (16U)                                           
#define CAN_BTR_TS1_Msk        (0xFUL << CAN_BTR_TS1_Pos)                       /*!< 0x000F0000 */
#define CAN_BTR_TS1            CAN_BTR_TS1_Msk                                 /*!<Time Segment 1 */
#define CAN_BTR_TS1_0          (0x1UL << CAN_BTR_TS1_Pos)                       /*!< 0x00010000 */
#define CAN_BTR_TS1_1          (0x2UL << CAN_BTR_TS1_Pos)                       /*!< 0x00020000 */
#define CAN_BTR_TS1_2          (0x4UL << CAN_BTR_TS1_Pos)                       /*!< 0x00040000 */
#define CAN_BTR_TS1_3          (0x8UL << CAN_BTR_TS1_Pos)                       /*!< 0x00080000 */
#define CAN_BTR_TS2_Pos        (20U)                                           
#define CAN_BTR_TS2_Msk        (0x7UL << CAN_BTR_TS2_Pos)                       /*!< 0x00700000 */
#define CAN_BTR_TS2            CAN_BTR_TS2_Msk                                 /*!<Time Segment 2 */
#define CAN_BTR_TS2_0          (0x1UL << CAN_BTR_TS2_Pos)                       /*!< 0x00100000 */
#define CAN_BTR_TS2_1          (0x2UL << CAN_BTR_TS2_Pos)                       /*!< 0x00200000 */
#define CAN_BTR_TS2_2          (0x4UL << CAN_BTR_TS2_Pos)                       /*!< 0x00400000 */
#define CAN_BTR_SJW_Pos        (24U)                                           
#define CAN_BTR_SJW_Msk        (0x3UL << CAN_BTR_SJW_Pos)                       /*!< 0x03000000 */
#define CAN_BTR_SJW            CAN_BTR_SJW_Msk                                 /*!<Resynchronization Jump Width */
#define CAN_BTR_SJW_0          (0x1UL << CAN_BTR_SJW_Pos)                       /*!< 0x01000000 */
#define CAN_BTR_SJW_1          (0x2UL << CAN_BTR_SJW_Pos)                       /*!< 0x02000000 */
#define CAN_BTR_LBKM_Pos       (30U)                                           
#define CAN_BTR_LBKM_Msk       (0x1UL << CAN_BTR_LBKM_Pos)                      /*!< 0x40000000 */
#define CAN_BTR_LBKM           CAN_BTR_LBKM_Msk                                /*!<Loop Back Mode (Debug) */
#define CAN_BTR_SILM_Pos       (31U)                                           
#define CAN_BTR_SILM_Msk       (0x1UL << CAN_BTR_SILM_Pos)                      /*!< 0x80000000 */
#define CAN_BTR_SILM           CAN_BTR_SILM_Msk                                /*!<Silent Mode */


/*!<Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define CAN_TI0R_TXRQ_Pos      (0U)                                            
#define CAN_TI0R_TXRQ_Msk      (0x1UL << CAN_TI0R_TXRQ_Pos)                     /*!< 0x00000001 */
#define CAN_TI0R_TXRQ          CAN_TI0R_TXRQ_Msk                               /*!<Transmit Mailbox Request */
#define CAN_TI0R_RTR_Pos       (1U)                                            
#define CAN_TI0R_RTR_Msk       (0x1UL << CAN_TI0R_RTR_Pos)                      /*!< 0x00000002 */
#define CAN_TI0R_RTR           CAN_TI0R_RTR_Msk                                /*!<Remote Transmission Request */
#define CAN_TI0R_IDE_Pos       (2U)                                            
#define CAN_TI0R_IDE_Msk       (0x1UL << CAN_TI0R_IDE_Pos)                      /*!< 0x00000004 */
#define CAN_TI0R_IDE           CAN_TI0R_IDE_Msk                                /*!<Identifier Extension */
#define CAN_TI0R_EXID_Pos      (3U)                                            
#define CAN_TI0R_EXID_Msk      (0x3FFFFUL << CAN_TI0R_EXID_Pos)                 /*!< 0x001FFFF8 */
#define CAN_TI0R_EXID          CAN_TI0R_EXID_Msk                               /*!<Extended Identifier */
#define CAN_TI0R_STID_Pos      (21U)                                           
#define CAN_TI0R_STID_Msk      (0x7FFUL << CAN_TI0R_STID_Pos)                   /*!< 0xFFE00000 */
#define CAN_TI0R_STID          CAN_TI0R_STID_Msk                               /*!<Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define CAN_TDT0R_DLC_Pos      (0U)                                            
#define CAN_TDT0R_DLC_Msk      (0xFUL << CAN_TDT0R_DLC_Pos)                     /*!< 0x0000000F */
#define CAN_TDT0R_DLC          CAN_TDT0R_DLC_Msk                               /*!<Data Length Code */
#define CAN_TDT0R_TGT_Pos      (8U)                                            
#define CAN_TDT0R_TGT_Msk      (0x1UL << CAN_TDT0R_TGT_Pos)                     /*!< 0x00000100 */
#define CAN_TDT0R_TGT          CAN_TDT0R_TGT_Msk                               /*!<Transmit Global Time */
#define CAN_TDT0R_TIME_Pos     (16U)                                           
#define CAN_TDT0R_TIME_Msk     (0xFFFFUL << CAN_TDT0R_TIME_Pos)                 /*!< 0xFFFF0000 */
#define CAN_TDT0R_TIME         CAN_TDT0R_TIME_Msk                              /*!<Message Time Stamp */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define CAN_TDL0R_DATA0_Pos    (0U)                                            
#define CAN_TDL0R_DATA0_Msk    (0xFFUL << CAN_TDL0R_DATA0_Pos)                  /*!< 0x000000FF */
#define CAN_TDL0R_DATA0        CAN_TDL0R_DATA0_Msk                             /*!<Data byte 0 */
#define CAN_TDL0R_DATA1_Pos    (8U)                                            
#define CAN_TDL0R_DATA1_Msk    (0xFFUL << CAN_TDL0R_DATA1_Pos)                  /*!< 0x0000FF00 */
#define CAN_TDL0R_DATA1        CAN_TDL0R_DATA1_Msk                             /*!<Data byte 1 */
#define CAN_TDL0R_DATA2_Pos    (16U)                                           
#define CAN_TDL0R_DATA2_Msk    (0xFFUL << CAN_TDL0R_DATA2_Pos)                  /*!< 0x00FF0000 */
#define CAN_TDL0R_DATA2        CAN_TDL0R_DATA2_Msk                             /*!<Data byte 2 */
#define CAN_TDL0R_DATA3_Pos    (24U)                                           
#define CAN_TDL0R_DATA3_Msk    (0xFFUL << CAN_TDL0R_DATA3_Pos)                  /*!< 0xFF000000 */
#define CAN_TDL0R_DATA3        CAN_TDL0R_DATA3_Msk                             /*!<Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define CAN_TDH0R_DATA4_Pos    (0U)                                            
#define CAN_TDH0R_DATA4_Msk    (0xFFUL << CAN_TDH0R_DATA4_Pos)                  /*!< 0x000000FF */
#define CAN_TDH0R_DATA4        CAN_TDH0R_DATA4_Msk                             /*!<Data byte 4 */
#define CAN_TDH0R_DATA5_Pos    (8U)                                            
#define CAN_TDH0R_DATA5_Msk    (0xFFUL << CAN_TDH0R_DATA5_Pos)                  /*!< 0x0000FF00 */
#define CAN_TDH0R_DATA5        CAN_TDH0R_DATA5_Msk                             /*!<Data byte 5 */
#define CAN_TDH0R_DATA6_Pos    (16U)                                           
#define CAN_TDH0R_DATA6_Msk    (0xFFUL << CAN_TDH0R_DATA6_Pos)                  /*!< 0x00FF0000 */
#define CAN_TDH0R_DATA6        CAN_TDH0R_DATA6_Msk                             /*!<Data byte 6 */
#define CAN_TDH0R_DATA7_Pos    (24U)                                           
#define CAN_TDH0R_DATA7_Msk    (0xFFUL << CAN_TDH0R_DATA7_Pos)                  /*!< 0xFF000000 */
#define CAN_TDH0R_DATA7        CAN_TDH0R_DATA7_Msk                             /*!<Data byte 7 */

/*******************  Bit definition for CAN_TI1R register  *******************/
#define CAN_TI1R_TXRQ_Pos      (0U)                                            
#define CAN_TI1R_TXRQ_Msk      (0x1UL << CAN_TI1R_TXRQ_Pos)                     /*!< 0x00000001 */
#define CAN_TI1R_TXRQ          CAN_TI1R_TXRQ_Msk                               /*!<Transmit Mailbox Request */
#define CAN_TI1R_RTR_Pos       (1U)                                            
#define CAN_TI1R_RTR_Msk       (0x1UL << CAN_TI1R_RTR_Pos)                      /*!< 0x00000002 */
#define CAN_TI1R_RTR           CAN_TI1R_RTR_Msk                                /*!<Remote Transmission Request */
#define CAN_TI1R_IDE_Pos       (2U)                                            
#define CAN_TI1R_IDE_Msk       (0x1UL << CAN_TI1R_IDE_Pos)                      /*!< 0x00000004 */
#define CAN_TI1R_IDE           CAN_TI1R_IDE_Msk                                /*!<Identifier Extension */
#define CAN_TI1R_EXID_Pos      (3U)                                            
#define CAN_TI1R_EXID_Msk      (0x3FFFFUL << CAN_TI1R_EXID_Pos)                 /*!< 0x001FFFF8 */
#define CAN_TI1R_EXID          CAN_TI1R_EXID_Msk                               /*!<Extended Identifier */
#define CAN_TI1R_STID_Pos      (21U)                                           
#define CAN_TI1R_STID_Msk      (0x7FFUL << CAN_TI1R_STID_Pos)                   /*!< 0xFFE00000 */
#define CAN_TI1R_STID          CAN_TI1R_STID_Msk                               /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define CAN_TDT1R_DLC_Pos      (0U)                                            
#define CAN_TDT1R_DLC_Msk      (0xFUL << CAN_TDT1R_DLC_Pos)                     /*!< 0x0000000F */
#define CAN_TDT1R_DLC          CAN_TDT1R_DLC_Msk                               /*!<Data Length Code */
#define CAN_TDT1R_TGT_Pos      (8U)                                            
#define CAN_TDT1R_TGT_Msk      (0x1UL << CAN_TDT1R_TGT_Pos)                     /*!< 0x00000100 */
#define CAN_TDT1R_TGT          CAN_TDT1R_TGT_Msk                               /*!<Transmit Global Time */
#define CAN_TDT1R_TIME_Pos     (16U)                                           
#define CAN_TDT1R_TIME_Msk     (0xFFFFUL << CAN_TDT1R_TIME_Pos)                 /*!< 0xFFFF0000 */
#define CAN_TDT1R_TIME         CAN_TDT1R_TIME_Msk                              /*!<Message Time Stamp */

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define CAN_TDL1R_DATA0_Pos    (0U)                                            
#define CAN_TDL1R_DATA0_Msk    (0xFFUL << CAN_TDL1R_DATA0_Pos)                  /*!< 0x000000FF */
#define CAN_TDL1R_DATA0        CAN_TDL1R_DATA0_Msk                             /*!<Data byte 0 */
#define CAN_TDL1R_DATA1_Pos    (8U)                                            
#define CAN_TDL1R_DATA1_Msk    (0xFFUL << CAN_TDL1R_DATA1_Pos)                  /*!< 0x0000FF00 */
#define CAN_TDL1R_DATA1        CAN_TDL1R_DATA1_Msk                             /*!<Data byte 1 */
#define CAN_TDL1R_DATA2_Pos    (16U)                                           
#define CAN_TDL1R_DATA2_Msk    (0xFFUL << CAN_TDL1R_DATA2_Pos)                  /*!< 0x00FF0000 */
#define CAN_TDL1R_DATA2        CAN_TDL1R_DATA2_Msk                             /*!<Data byte 2 */
#define CAN_TDL1R_DATA3_Pos    (24U)                                           
#define CAN_TDL1R_DATA3_Msk    (0xFFUL << CAN_TDL1R_DATA3_Pos)                  /*!< 0xFF000000 */
#define CAN_TDL1R_DATA3        CAN_TDL1R_DATA3_Msk                             /*!<Data byte 3 */

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define CAN_TDH1R_DATA4_Pos    (0U)                                            
#define CAN_TDH1R_DATA4_Msk    (0xFFUL << CAN_TDH1R_DATA4_Pos)                  /*!< 0x000000FF */
#define CAN_TDH1R_DATA4        CAN_TDH1R_DATA4_Msk                             /*!<Data byte 4 */
#define CAN_TDH1R_DATA5_Pos    (8U)                                            
#define CAN_TDH1R_DATA5_Msk    (0xFFUL << CAN_TDH1R_DATA5_Pos)                  /*!< 0x0000FF00 */
#define CAN_TDH1R_DATA5        CAN_TDH1R_DATA5_Msk                             /*!<Data byte 5 */
#define CAN_TDH1R_DATA6_Pos    (16U)                                           
#define CAN_TDH1R_DATA6_Msk    (0xFFUL << CAN_TDH1R_DATA6_Pos)                  /*!< 0x00FF0000 */
#define CAN_TDH1R_DATA6        CAN_TDH1R_DATA6_Msk                             /*!<Data byte 6 */
#define CAN_TDH1R_DATA7_Pos    (24U)                                           
#define CAN_TDH1R_DATA7_Msk    (0xFFUL << CAN_TDH1R_DATA7_Pos)                  /*!< 0xFF000000 */
#define CAN_TDH1R_DATA7        CAN_TDH1R_DATA7_Msk                             /*!<Data byte 7 */

/*******************  Bit definition for CAN_TI2R register  *******************/
#define CAN_TI2R_TXRQ_Pos      (0U)                                            
#define CAN_TI2R_TXRQ_Msk      (0x1UL << CAN_TI2R_TXRQ_Pos)                     /*!< 0x00000001 */
#define CAN_TI2R_TXRQ          CAN_TI2R_TXRQ_Msk                               /*!<Transmit Mailbox Request */
#define CAN_TI2R_RTR_Pos       (1U)                                            
#define CAN_TI2R_RTR_Msk       (0x1UL << CAN_TI2R_RTR_Pos)                      /*!< 0x00000002 */
#define CAN_TI2R_RTR           CAN_TI2R_RTR_Msk                                /*!<Remote Transmission Request */
#define CAN_TI2R_IDE_Pos       (2U)                                            
#define CAN_TI2R_IDE_Msk       (0x1UL << CAN_TI2R_IDE_Pos)                      /*!< 0x00000004 */
#define CAN_TI2R_IDE           CAN_TI2R_IDE_Msk                                /*!<Identifier Extension */
#define CAN_TI2R_EXID_Pos      (3U)                                            
#define CAN_TI2R_EXID_Msk      (0x3FFFFUL << CAN_TI2R_EXID_Pos)                 /*!< 0x001FFFF8 */
#define CAN_TI2R_EXID          CAN_TI2R_EXID_Msk                               /*!<Extended identifier */
#define CAN_TI2R_STID_Pos      (21U)                                           
#define CAN_TI2R_STID_Msk      (0x7FFUL << CAN_TI2R_STID_Pos)                   /*!< 0xFFE00000 */
#define CAN_TI2R_STID          CAN_TI2R_STID_Msk                               /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT2R register  ******************/  
#define CAN_TDT2R_DLC_Pos      (0U)                                            
#define CAN_TDT2R_DLC_Msk      (0xFUL << CAN_TDT2R_DLC_Pos)                     /*!< 0x0000000F */
#define CAN_TDT2R_DLC          CAN_TDT2R_DLC_Msk                               /*!<Data Length Code */
#define CAN_TDT2R_TGT_Pos      (8U)                                            
#define CAN_TDT2R_TGT_Msk      (0x1UL << CAN_TDT2R_TGT_Pos)                     /*!< 0x00000100 */
#define CAN_TDT2R_TGT          CAN_TDT2R_TGT_Msk                               /*!<Transmit Global Time */
#define CAN_TDT2R_TIME_Pos     (16U)                                           
#define CAN_TDT2R_TIME_Msk     (0xFFFFUL << CAN_TDT2R_TIME_Pos)                 /*!< 0xFFFF0000 */
#define CAN_TDT2R_TIME         CAN_TDT2R_TIME_Msk                              /*!<Message Time Stamp */

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define CAN_TDL2R_DATA0_Pos    (0U)                                            
#define CAN_TDL2R_DATA0_Msk    (0xFFUL << CAN_TDL2R_DATA0_Pos)                  /*!< 0x000000FF */
#define CAN_TDL2R_DATA0        CAN_TDL2R_DATA0_Msk                             /*!<Data byte 0 */
#define CAN_TDL2R_DATA1_Pos    (8U)                                            
#define CAN_TDL2R_DATA1_Msk    (0xFFUL << CAN_TDL2R_DATA1_Pos)                  /*!< 0x0000FF00 */
#define CAN_TDL2R_DATA1        CAN_TDL2R_DATA1_Msk                             /*!<Data byte 1 */
#define CAN_TDL2R_DATA2_Pos    (16U)                                           
#define CAN_TDL2R_DATA2_Msk    (0xFFUL << CAN_TDL2R_DATA2_Pos)                  /*!< 0x00FF0000 */
#define CAN_TDL2R_DATA2        CAN_TDL2R_DATA2_Msk                             /*!<Data byte 2 */
#define CAN_TDL2R_DATA3_Pos    (24U)                                           
#define CAN_TDL2R_DATA3_Msk    (0xFFUL << CAN_TDL2R_DATA3_Pos)                  /*!< 0xFF000000 */
#define CAN_TDL2R_DATA3        CAN_TDL2R_DATA3_Msk                             /*!<Data byte 3 */

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define CAN_TDH2R_DATA4_Pos    (0U)                                            
#define CAN_TDH2R_DATA4_Msk    (0xFFUL << CAN_TDH2R_DATA4_Pos)                  /*!< 0x000000FF */
#define CAN_TDH2R_DATA4        CAN_TDH2R_DATA4_Msk                             /*!<Data byte 4 */
#define CAN_TDH2R_DATA5_Pos    (8U)                                            
#define CAN_TDH2R_DATA5_Msk    (0xFFUL << CAN_TDH2R_DATA5_Pos)                  /*!< 0x0000FF00 */
#define CAN_TDH2R_DATA5        CAN_TDH2R_DATA5_Msk                             /*!<Data byte 5 */
#define CAN_TDH2R_DATA6_Pos    (16U)                                           
#define CAN_TDH2R_DATA6_Msk    (0xFFUL << CAN_TDH2R_DATA6_Pos)                  /*!< 0x00FF0000 */
#define CAN_TDH2R_DATA6        CAN_TDH2R_DATA6_Msk                             /*!<Data byte 6 */
#define CAN_TDH2R_DATA7_Pos    (24U)                                           
#define CAN_TDH2R_DATA7_Msk    (0xFFUL << CAN_TDH2R_DATA7_Pos)                  /*!< 0xFF000000 */
#define CAN_TDH2R_DATA7        CAN_TDH2R_DATA7_Msk                             /*!<Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define CAN_RI0R_RTR_Pos       (1U)                                            
#define CAN_RI0R_RTR_Msk       (0x1UL << CAN_RI0R_RTR_Pos)                      /*!< 0x00000002 */
#define CAN_RI0R_RTR           CAN_RI0R_RTR_Msk                                /*!<Remote Transmission Request */
#define CAN_RI0R_IDE_Pos       (2U)                                            
#define CAN_RI0R_IDE_Msk       (0x1UL << CAN_RI0R_IDE_Pos)                      /*!< 0x00000004 */
#define CAN_RI0R_IDE           CAN_RI0R_IDE_Msk                                /*!<Identifier Extension */
#define CAN_RI0R_EXID_Pos      (3U)                                            
#define CAN_RI0R_EXID_Msk      (0x3FFFFUL << CAN_RI0R_EXID_Pos)                 /*!< 0x001FFFF8 */
#define CAN_RI0R_EXID          CAN_RI0R_EXID_Msk                               /*!<Extended Identifier */
#define CAN_RI0R_STID_Pos      (21U)                                           
#define CAN_RI0R_STID_Msk      (0x7FFUL << CAN_RI0R_STID_Pos)                   /*!< 0xFFE00000 */
#define CAN_RI0R_STID          CAN_RI0R_STID_Msk                               /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define CAN_RDT0R_DLC_Pos      (0U)                                            
#define CAN_RDT0R_DLC_Msk      (0xFUL << CAN_RDT0R_DLC_Pos)                     /*!< 0x0000000F */
#define CAN_RDT0R_DLC          CAN_RDT0R_DLC_Msk                               /*!<Data Length Code */
#define CAN_RDT0R_FMI_Pos      (8U)                                            
#define CAN_RDT0R_FMI_Msk      (0xFFUL << CAN_RDT0R_FMI_Pos)                    /*!< 0x0000FF00 */
#define CAN_RDT0R_FMI          CAN_RDT0R_FMI_Msk                               /*!<Filter Match Index */
#define CAN_RDT0R_TIME_Pos     (16U)                                           
#define CAN_RDT0R_TIME_Msk     (0xFFFFUL << CAN_RDT0R_TIME_Pos)                 /*!< 0xFFFF0000 */
#define CAN_RDT0R_TIME         CAN_RDT0R_TIME_Msk                              /*!<Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define CAN_RDL0R_DATA0_Pos    (0U)                                            
#define CAN_RDL0R_DATA0_Msk    (0xFFUL << CAN_RDL0R_DATA0_Pos)                  /*!< 0x000000FF */
#define CAN_RDL0R_DATA0        CAN_RDL0R_DATA0_Msk                             /*!<Data byte 0 */
#define CAN_RDL0R_DATA1_Pos    (8U)                                            
#define CAN_RDL0R_DATA1_Msk    (0xFFUL << CAN_RDL0R_DATA1_Pos)                  /*!< 0x0000FF00 */
#define CAN_RDL0R_DATA1        CAN_RDL0R_DATA1_Msk                             /*!<Data byte 1 */
#define CAN_RDL0R_DATA2_Pos    (16U)                                           
#define CAN_RDL0R_DATA2_Msk    (0xFFUL << CAN_RDL0R_DATA2_Pos)                  /*!< 0x00FF0000 */
#define CAN_RDL0R_DATA2        CAN_RDL0R_DATA2_Msk                             /*!<Data byte 2 */
#define CAN_RDL0R_DATA3_Pos    (24U)                                           
#define CAN_RDL0R_DATA3_Msk    (0xFFUL << CAN_RDL0R_DATA3_Pos)                  /*!< 0xFF000000 */
#define CAN_RDL0R_DATA3        CAN_RDL0R_DATA3_Msk                             /*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define CAN_RDH0R_DATA4_Pos    (0U)                                            
#define CAN_RDH0R_DATA4_Msk    (0xFFUL << CAN_RDH0R_DATA4_Pos)                  /*!< 0x000000FF */
#define CAN_RDH0R_DATA4        CAN_RDH0R_DATA4_Msk                             /*!<Data byte 4 */
#define CAN_RDH0R_DATA5_Pos    (8U)                                            
#define CAN_RDH0R_DATA5_Msk    (0xFFUL << CAN_RDH0R_DATA5_Pos)                  /*!< 0x0000FF00 */
#define CAN_RDH0R_DATA5        CAN_RDH0R_DATA5_Msk                             /*!<Data byte 5 */
#define CAN_RDH0R_DATA6_Pos    (16U)                                           
#define CAN_RDH0R_DATA6_Msk    (0xFFUL << CAN_RDH0R_DATA6_Pos)                  /*!< 0x00FF0000 */
#define CAN_RDH0R_DATA6        CAN_RDH0R_DATA6_Msk                             /*!<Data byte 6 */
#define CAN_RDH0R_DATA7_Pos    (24U)                                           
#define CAN_RDH0R_DATA7_Msk    (0xFFUL << CAN_RDH0R_DATA7_Pos)                  /*!< 0xFF000000 */
#define CAN_RDH0R_DATA7        CAN_RDH0R_DATA7_Msk                             /*!<Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define CAN_RI1R_RTR_Pos       (1U)                                            
#define CAN_RI1R_RTR_Msk       (0x1UL << CAN_RI1R_RTR_Pos)                      /*!< 0x00000002 */
#define CAN_RI1R_RTR           CAN_RI1R_RTR_Msk                                /*!<Remote Transmission Request */
#define CAN_RI1R_IDE_Pos       (2U)                                            
#define CAN_RI1R_IDE_Msk       (0x1UL << CAN_RI1R_IDE_Pos)                      /*!< 0x00000004 */
#define CAN_RI1R_IDE           CAN_RI1R_IDE_Msk                                /*!<Identifier Extension */
#define CAN_RI1R_EXID_Pos      (3U)                                            
#define CAN_RI1R_EXID_Msk      (0x3FFFFUL << CAN_RI1R_EXID_Pos)                 /*!< 0x001FFFF8 */
#define CAN_RI1R_EXID          CAN_RI1R_EXID_Msk                               /*!<Extended identifier */
#define CAN_RI1R_STID_Pos      (21U)                                           
#define CAN_RI1R_STID_Msk      (0x7FFUL << CAN_RI1R_STID_Pos)                   /*!< 0xFFE00000 */
#define CAN_RI1R_STID          CAN_RI1R_STID_Msk                               /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define CAN_RDT1R_DLC_Pos      (0U)                                            
#define CAN_RDT1R_DLC_Msk      (0xFUL << CAN_RDT1R_DLC_Pos)                     /*!< 0x0000000F */
#define CAN_RDT1R_DLC          CAN_RDT1R_DLC_Msk                               /*!<Data Length Code */
#define CAN_RDT1R_FMI_Pos      (8U)                                            
#define CAN_RDT1R_FMI_Msk      (0xFFUL << CAN_RDT1R_FMI_Pos)                    /*!< 0x0000FF00 */
#define CAN_RDT1R_FMI          CAN_RDT1R_FMI_Msk                               /*!<Filter Match Index */
#define CAN_RDT1R_TIME_Pos     (16U)                                           
#define CAN_RDT1R_TIME_Msk     (0xFFFFUL << CAN_RDT1R_TIME_Pos)                 /*!< 0xFFFF0000 */
#define CAN_RDT1R_TIME         CAN_RDT1R_TIME_Msk                              /*!<Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define CAN_RDL1R_DATA0_Pos    (0U)                                            
#define CAN_RDL1R_DATA0_Msk    (0xFFUL << CAN_RDL1R_DATA0_Pos)                  /*!< 0x000000FF */
#define CAN_RDL1R_DATA0        CAN_RDL1R_DATA0_Msk                             /*!<Data byte 0 */
#define CAN_RDL1R_DATA1_Pos    (8U)                                            
#define CAN_RDL1R_DATA1_Msk    (0xFFUL << CAN_RDL1R_DATA1_Pos)                  /*!< 0x0000FF00 */
#define CAN_RDL1R_DATA1        CAN_RDL1R_DATA1_Msk                             /*!<Data byte 1 */
#define CAN_RDL1R_DATA2_Pos    (16U)                                           
#define CAN_RDL1R_DATA2_Msk    (0xFFUL << CAN_RDL1R_DATA2_Pos)                  /*!< 0x00FF0000 */
#define CAN_RDL1R_DATA2        CAN_RDL1R_DATA2_Msk                             /*!<Data byte 2 */
#define CAN_RDL1R_DATA3_Pos    (24U)                                           
#define CAN_RDL1R_DATA3_Msk    (0xFFUL << CAN_RDL1R_DATA3_Pos)                  /*!< 0xFF000000 */
#define CAN_RDL1R_DATA3        CAN_RDL1R_DATA3_Msk                             /*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define CAN_RDH1R_DATA4_Pos    (0U)                                            
#define CAN_RDH1R_DATA4_Msk    (0xFFUL << CAN_RDH1R_DATA4_Pos)                  /*!< 0x000000FF */
#define CAN_RDH1R_DATA4        CAN_RDH1R_DATA4_Msk                             /*!<Data byte 4 */
#define CAN_RDH1R_DATA5_Pos    (8U)                                            
#define CAN_RDH1R_DATA5_Msk    (0xFFUL << CAN_RDH1R_DATA5_Pos)                  /*!< 0x0000FF00 */
#define CAN_RDH1R_DATA5        CAN_RDH1R_DATA5_Msk                             /*!<Data byte 5 */
#define CAN_RDH1R_DATA6_Pos    (16U)                                           
#define CAN_RDH1R_DATA6_Msk    (0xFFUL << CAN_RDH1R_DATA6_Pos)                  /*!< 0x00FF0000 */
#define CAN_RDH1R_DATA6        CAN_RDH1R_DATA6_Msk                             /*!<Data byte 6 */
#define CAN_RDH1R_DATA7_Pos    (24U)                                           
#define CAN_RDH1R_DATA7_Msk    (0xFFUL << CAN_RDH1R_DATA7_Pos)                  /*!< 0xFF000000 */
#define CAN_RDH1R_DATA7        CAN_RDH1R_DATA7_Msk                             /*!<Data byte 7 */

/*!<CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define CAN_FMR_FINIT_Pos      (0U)                                            
#define CAN_FMR_FINIT_Msk      (0x1UL << CAN_FMR_FINIT_Pos)                     /*!< 0x00000001 */
#define CAN_FMR_FINIT          CAN_FMR_FINIT_Msk                               /*!<Filter Init Mode */
#define CAN_FMR_CAN2SB_Pos     (8U)                                            
#define CAN_FMR_CAN2SB_Msk     (0x3FUL << CAN_FMR_CAN2SB_Pos)                   /*!< 0x00003F00 */
#define CAN_FMR_CAN2SB         CAN_FMR_CAN2SB_Msk                              /*!<CAN2 start bank */

/*******************  Bit definition for CAN_FM1R register  *******************/
#define CAN_FM1R_FBM_Pos       (0U)                                            
#define CAN_FM1R_FBM_Msk       (0xFFFFFFFUL << CAN_FM1R_FBM_Pos)                /*!< 0x0FFFFFFF */
#define CAN_FM1R_FBM           CAN_FM1R_FBM_Msk                                /*!<Filter Mode */
#define CAN_FM1R_FBM0_Pos      (0U)                                            
#define CAN_FM1R_FBM0_Msk      (0x1UL << CAN_FM1R_FBM0_Pos)                     /*!< 0x00000001 */
#define CAN_FM1R_FBM0          CAN_FM1R_FBM0_Msk                               /*!<Filter Init Mode bit 0 */
#define CAN_FM1R_FBM1_Pos      (1U)                                            
#define CAN_FM1R_FBM1_Msk      (0x1UL << CAN_FM1R_FBM1_Pos)                     /*!< 0x00000002 */
#define CAN_FM1R_FBM1          CAN_FM1R_FBM1_Msk                               /*!<Filter Init Mode bit 1 */
#define CAN_FM1R_FBM2_Pos      (2U)                                            
#define CAN_FM1R_FBM2_Msk      (0x1UL << CAN_FM1R_FBM2_Pos)                     /*!< 0x00000004 */
#define CAN_FM1R_FBM2          CAN_FM1R_FBM2_Msk                               /*!<Filter Init Mode bit 2 */
#define CAN_FM1R_FBM3_Pos      (3U)                                            
#define CAN_FM1R_FBM3_Msk      (0x1UL << CAN_FM1R_FBM3_Pos)                     /*!< 0x00000008 */
#define CAN_FM1R_FBM3          CAN_FM1R_FBM3_Msk                               /*!<Filter Init Mode bit 3 */
#define CAN_FM1R_FBM4_Pos      (4U)                                            
#define CAN_FM1R_FBM4_Msk      (0x1UL << CAN_FM1R_FBM4_Pos)                     /*!< 0x00000010 */
#define CAN_FM1R_FBM4          CAN_FM1R_FBM4_Msk                               /*!<Filter Init Mode bit 4 */
#define CAN_FM1R_FBM5_Pos      (5U)                                            
#define CAN_FM1R_FBM5_Msk      (0x1UL << CAN_FM1R_FBM5_Pos)                     /*!< 0x00000020 */
#define CAN_FM1R_FBM5          CAN_FM1R_FBM5_Msk                               /*!<Filter Init Mode bit 5 */
#define CAN_FM1R_FBM6_Pos      (6U)                                            
#define CAN_FM1R_FBM6_Msk      (0x1UL << CAN_FM1R_FBM6_Pos)                     /*!< 0x00000040 */
#define CAN_FM1R_FBM6          CAN_FM1R_FBM6_Msk                               /*!<Filter Init Mode bit 6 */
#define CAN_FM1R_FBM7_Pos      (7U)                                            
#define CAN_FM1R_FBM7_Msk      (0x1UL << CAN_FM1R_FBM7_Pos)                     /*!< 0x00000080 */
#define CAN_FM1R_FBM7          CAN_FM1R_FBM7_Msk                               /*!<Filter Init Mode bit 7 */
#define CAN_FM1R_FBM8_Pos      (8U)                                            
#define CAN_FM1R_FBM8_Msk      (0x1UL << CAN_FM1R_FBM8_Pos)                     /*!< 0x00000100 */
#define CAN_FM1R_FBM8          CAN_FM1R_FBM8_Msk                               /*!<Filter Init Mode bit 8 */
#define CAN_FM1R_FBM9_Pos      (9U)                                            
#define CAN_FM1R_FBM9_Msk      (0x1UL << CAN_FM1R_FBM9_Pos)                     /*!< 0x00000200 */
#define CAN_FM1R_FBM9          CAN_FM1R_FBM9_Msk                               /*!<Filter Init Mode bit 9 */
#define CAN_FM1R_FBM10_Pos     (10U)                                           
#define CAN_FM1R_FBM10_Msk     (0x1UL << CAN_FM1R_FBM10_Pos)                    /*!< 0x00000400 */
#define CAN_FM1R_FBM10         CAN_FM1R_FBM10_Msk                              /*!<Filter Init Mode bit 10 */
#define CAN_FM1R_FBM11_Pos     (11U)                                           
#define CAN_FM1R_FBM11_Msk     (0x1UL << CAN_FM1R_FBM11_Pos)                    /*!< 0x00000800 */
#define CAN_FM1R_FBM11         CAN_FM1R_FBM11_Msk                              /*!<Filter Init Mode bit 11 */
#define CAN_FM1R_FBM12_Pos     (12U)                                           
#define CAN_FM1R_FBM12_Msk     (0x1UL << CAN_FM1R_FBM12_Pos)                    /*!< 0x00001000 */
#define CAN_FM1R_FBM12         CAN_FM1R_FBM12_Msk                              /*!<Filter Init Mode bit 12 */
#define CAN_FM1R_FBM13_Pos     (13U)                                           
#define CAN_FM1R_FBM13_Msk     (0x1UL << CAN_FM1R_FBM13_Pos)                    /*!< 0x00002000 */
#define CAN_FM1R_FBM13         CAN_FM1R_FBM13_Msk                              /*!<Filter Init Mode bit 13 */
#define CAN_FM1R_FBM14_Pos     (14U)                                           
#define CAN_FM1R_FBM14_Msk     (0x1UL << CAN_FM1R_FBM14_Pos)                    /*!< 0x00004000 */
#define CAN_FM1R_FBM14         CAN_FM1R_FBM14_Msk                              /*!<Filter Init Mode bit 14 */
#define CAN_FM1R_FBM15_Pos     (15U)                                           
#define CAN_FM1R_FBM15_Msk     (0x1UL << CAN_FM1R_FBM15_Pos)                    /*!< 0x00008000 */
#define CAN_FM1R_FBM15         CAN_FM1R_FBM15_Msk                              /*!<Filter Init Mode bit 15 */
#define CAN_FM1R_FBM16_Pos     (16U)                                           
#define CAN_FM1R_FBM16_Msk     (0x1UL << CAN_FM1R_FBM16_Pos)                    /*!< 0x00010000 */
#define CAN_FM1R_FBM16         CAN_FM1R_FBM16_Msk                              /*!<Filter Init Mode bit 16 */
#define CAN_FM1R_FBM17_Pos     (17U)                                           
#define CAN_FM1R_FBM17_Msk     (0x1UL << CAN_FM1R_FBM17_Pos)                    /*!< 0x00020000 */
#define CAN_FM1R_FBM17         CAN_FM1R_FBM17_Msk                              /*!<Filter Init Mode bit 17 */
#define CAN_FM1R_FBM18_Pos     (18U)                                           
#define CAN_FM1R_FBM18_Msk     (0x1UL << CAN_FM1R_FBM18_Pos)                    /*!< 0x00040000 */
#define CAN_FM1R_FBM18         CAN_FM1R_FBM18_Msk                              /*!<Filter Init Mode bit 18 */
#define CAN_FM1R_FBM19_Pos     (19U)                                           
#define CAN_FM1R_FBM19_Msk     (0x1UL << CAN_FM1R_FBM19_Pos)                    /*!< 0x00080000 */
#define CAN_FM1R_FBM19         CAN_FM1R_FBM19_Msk                              /*!<Filter Init Mode bit 19 */
#define CAN_FM1R_FBM20_Pos     (20U)                                           
#define CAN_FM1R_FBM20_Msk     (0x1UL << CAN_FM1R_FBM20_Pos)                    /*!< 0x00100000 */
#define CAN_FM1R_FBM20         CAN_FM1R_FBM20_Msk                              /*!<Filter Init Mode bit 20 */
#define CAN_FM1R_FBM21_Pos     (21U)                                           
#define CAN_FM1R_FBM21_Msk     (0x1UL << CAN_FM1R_FBM21_Pos)                    /*!< 0x00200000 */
#define CAN_FM1R_FBM21         CAN_FM1R_FBM21_Msk                              /*!<Filter Init Mode bit 21 */
#define CAN_FM1R_FBM22_Pos     (22U)                                           
#define CAN_FM1R_FBM22_Msk     (0x1UL << CAN_FM1R_FBM22_Pos)                    /*!< 0x00400000 */
#define CAN_FM1R_FBM22         CAN_FM1R_FBM22_Msk                              /*!<Filter Init Mode bit 22 */
#define CAN_FM1R_FBM23_Pos     (23U)                                           
#define CAN_FM1R_FBM23_Msk     (0x1UL << CAN_FM1R_FBM23_Pos)                    /*!< 0x00800000 */
#define CAN_FM1R_FBM23         CAN_FM1R_FBM23_Msk                              /*!<Filter Init Mode bit 23 */
#define CAN_FM1R_FBM24_Pos     (24U)                                           
#define CAN_FM1R_FBM24_Msk     (0x1UL << CAN_FM1R_FBM24_Pos)                    /*!< 0x01000000 */
#define CAN_FM1R_FBM24         CAN_FM1R_FBM24_Msk                              /*!<Filter Init Mode bit 24 */
#define CAN_FM1R_FBM25_Pos     (25U)                                           
#define CAN_FM1R_FBM25_Msk     (0x1UL << CAN_FM1R_FBM25_Pos)                    /*!< 0x02000000 */
#define CAN_FM1R_FBM25         CAN_FM1R_FBM25_Msk                              /*!<Filter Init Mode bit 25 */
#define CAN_FM1R_FBM26_Pos     (26U)                                           
#define CAN_FM1R_FBM26_Msk     (0x1UL << CAN_FM1R_FBM26_Pos)                    /*!< 0x04000000 */
#define CAN_FM1R_FBM26         CAN_FM1R_FBM26_Msk                              /*!<Filter Init Mode bit 26 */
#define CAN_FM1R_FBM27_Pos     (27U)                                           
#define CAN_FM1R_FBM27_Msk     (0x1UL << CAN_FM1R_FBM27_Pos)                    /*!< 0x08000000 */
#define CAN_FM1R_FBM27         CAN_FM1R_FBM27_Msk                              /*!<Filter Init Mode bit 27 */

/*******************  Bit definition for CAN_FS1R register  *******************/
#define CAN_FS1R_FSC_Pos       (0U)                                            
#define CAN_FS1R_FSC_Msk       (0xFFFFFFFUL << CAN_FS1R_FSC_Pos)                /*!< 0x0FFFFFFF */
#define CAN_FS1R_FSC           CAN_FS1R_FSC_Msk                                /*!<Filter Scale Configuration */
#define CAN_FS1R_FSC0_Pos      (0U)                                            
#define CAN_FS1R_FSC0_Msk      (0x1UL << CAN_FS1R_FSC0_Pos)                     /*!< 0x00000001 */
#define CAN_FS1R_FSC0          CAN_FS1R_FSC0_Msk                               /*!<Filter Scale Configuration bit 0 */
#define CAN_FS1R_FSC1_Pos      (1U)                                            
#define CAN_FS1R_FSC1_Msk      (0x1UL << CAN_FS1R_FSC1_Pos)                     /*!< 0x00000002 */
#define CAN_FS1R_FSC1          CAN_FS1R_FSC1_Msk                               /*!<Filter Scale Configuration bit 1 */
#define CAN_FS1R_FSC2_Pos      (2U)                                            
#define CAN_FS1R_FSC2_Msk      (0x1UL << CAN_FS1R_FSC2_Pos)                     /*!< 0x00000004 */
#define CAN_FS1R_FSC2          CAN_FS1R_FSC2_Msk                               /*!<Filter Scale Configuration bit 2 */
#define CAN_FS1R_FSC3_Pos      (3U)                                            
#define CAN_FS1R_FSC3_Msk      (0x1UL << CAN_FS1R_FSC3_Pos)                     /*!< 0x00000008 */
#define CAN_FS1R_FSC3          CAN_FS1R_FSC3_Msk                               /*!<Filter Scale Configuration bit 3 */
#define CAN_FS1R_FSC4_Pos      (4U)                                            
#define CAN_FS1R_FSC4_Msk      (0x1UL << CAN_FS1R_FSC4_Pos)                     /*!< 0x00000010 */
#define CAN_FS1R_FSC4          CAN_FS1R_FSC4_Msk                               /*!<Filter Scale Configuration bit 4 */
#define CAN_FS1R_FSC5_Pos      (5U)                                            
#define CAN_FS1R_FSC5_Msk      (0x1UL << CAN_FS1R_FSC5_Pos)                     /*!< 0x00000020 */
#define CAN_FS1R_FSC5          CAN_FS1R_FSC5_Msk                               /*!<Filter Scale Configuration bit 5 */
#define CAN_FS1R_FSC6_Pos      (6U)                                            
#define CAN_FS1R_FSC6_Msk      (0x1UL << CAN_FS1R_FSC6_Pos)                     /*!< 0x00000040 */
#define CAN_FS1R_FSC6          CAN_FS1R_FSC6_Msk                               /*!<Filter Scale Configuration bit 6 */
#define CAN_FS1R_FSC7_Pos      (7U)                                            
#define CAN_FS1R_FSC7_Msk      (0x1UL << CAN_FS1R_FSC7_Pos)                     /*!< 0x00000080 */
#define CAN_FS1R_FSC7          CAN_FS1R_FSC7_Msk                               /*!<Filter Scale Configuration bit 7 */
#define CAN_FS1R_FSC8_Pos      (8U)                                            
#define CAN_FS1R_FSC8_Msk      (0x1UL << CAN_FS1R_FSC8_Pos)                     /*!< 0x00000100 */
#define CAN_FS1R_FSC8          CAN_FS1R_FSC8_Msk                               /*!<Filter Scale Configuration bit 8 */
#define CAN_FS1R_FSC9_Pos      (9U)                                            
#define CAN_FS1R_FSC9_Msk      (0x1UL << CAN_FS1R_FSC9_Pos)                     /*!< 0x00000200 */
#define CAN_FS1R_FSC9          CAN_FS1R_FSC9_Msk                               /*!<Filter Scale Configuration bit 9 */
#define CAN_FS1R_FSC10_Pos     (10U)                                           
#define CAN_FS1R_FSC10_Msk     (0x1UL << CAN_FS1R_FSC10_Pos)                    /*!< 0x00000400 */
#define CAN_FS1R_FSC10         CAN_FS1R_FSC10_Msk                              /*!<Filter Scale Configuration bit 10 */
#define CAN_FS1R_FSC11_Pos     (11U)                                           
#define CAN_FS1R_FSC11_Msk     (0x1UL << CAN_FS1R_FSC11_Pos)                    /*!< 0x00000800 */
#define CAN_FS1R_FSC11         CAN_FS1R_FSC11_Msk                              /*!<Filter Scale Configuration bit 11 */
#define CAN_FS1R_FSC12_Pos     (12U)                                           
#define CAN_FS1R_FSC12_Msk     (0x1UL << CAN_FS1R_FSC12_Pos)                    /*!< 0x00001000 */
#define CAN_FS1R_FSC12         CAN_FS1R_FSC12_Msk                              /*!<Filter Scale Configuration bit 12 */
#define CAN_FS1R_FSC13_Pos     (13U)                                           
#define CAN_FS1R_FSC13_Msk     (0x1UL << CAN_FS1R_FSC13_Pos)                    /*!< 0x00002000 */
#define CAN_FS1R_FSC13         CAN_FS1R_FSC13_Msk                              /*!<Filter Scale Configuration bit 13 */
#define CAN_FS1R_FSC14_Pos     (14U)                                           
#define CAN_FS1R_FSC14_Msk     (0x1UL << CAN_FS1R_FSC14_Pos)                    /*!< 0x00004000 */
#define CAN_FS1R_FSC14         CAN_FS1R_FSC14_Msk                              /*!<Filter Scale Configuration bit 14 */
#define CAN_FS1R_FSC15_Pos     (15U)                                           
#define CAN_FS1R_FSC15_Msk     (0x1UL << CAN_FS1R_FSC15_Pos)                    /*!< 0x00008000 */
#define CAN_FS1R_FSC15         CAN_FS1R_FSC15_Msk                              /*!<Filter Scale Configuration bit 15 */
#define CAN_FS1R_FSC16_Pos     (16U)                                           
#define CAN_FS1R_FSC16_Msk     (0x1UL << CAN_FS1R_FSC16_Pos)                    /*!< 0x00010000 */
#define CAN_FS1R_FSC16         CAN_FS1R_FSC16_Msk                              /*!<Filter Scale Configuration bit 16 */
#define CAN_FS1R_FSC17_Pos     (17U)                                           
#define CAN_FS1R_FSC17_Msk     (0x1UL << CAN_FS1R_FSC17_Pos)                    /*!< 0x00020000 */
#define CAN_FS1R_FSC17         CAN_FS1R_FSC17_Msk                              /*!<Filter Scale Configuration bit 17 */
#define CAN_FS1R_FSC18_Pos     (18U)                                           
#define CAN_FS1R_FSC18_Msk     (0x1UL << CAN_FS1R_FSC18_Pos)                    /*!< 0x00040000 */
#define CAN_FS1R_FSC18         CAN_FS1R_FSC18_Msk                              /*!<Filter Scale Configuration bit 18 */
#define CAN_FS1R_FSC19_Pos     (19U)                                           
#define CAN_FS1R_FSC19_Msk     (0x1UL << CAN_FS1R_FSC19_Pos)                    /*!< 0x00080000 */
#define CAN_FS1R_FSC19         CAN_FS1R_FSC19_Msk                              /*!<Filter Scale Configuration bit 19 */
#define CAN_FS1R_FSC20_Pos     (20U)                                           
#define CAN_FS1R_FSC20_Msk     (0x1UL << CAN_FS1R_FSC20_Pos)                    /*!< 0x00100000 */
#define CAN_FS1R_FSC20         CAN_FS1R_FSC20_Msk                              /*!<Filter Scale Configuration bit 20 */
#define CAN_FS1R_FSC21_Pos     (21U)                                           
#define CAN_FS1R_FSC21_Msk     (0x1UL << CAN_FS1R_FSC21_Pos)                    /*!< 0x00200000 */
#define CAN_FS1R_FSC21         CAN_FS1R_FSC21_Msk                              /*!<Filter Scale Configuration bit 21 */
#define CAN_FS1R_FSC22_Pos     (22U)                                           
#define CAN_FS1R_FSC22_Msk     (0x1UL << CAN_FS1R_FSC22_Pos)                    /*!< 0x00400000 */
#define CAN_FS1R_FSC22         CAN_FS1R_FSC22_Msk                              /*!<Filter Scale Configuration bit 22 */
#define CAN_FS1R_FSC23_Pos     (23U)                                           
#define CAN_FS1R_FSC23_Msk     (0x1UL << CAN_FS1R_FSC23_Pos)                    /*!< 0x00800000 */
#define CAN_FS1R_FSC23         CAN_FS1R_FSC23_Msk                              /*!<Filter Scale Configuration bit 23 */
#define CAN_FS1R_FSC24_Pos     (24U)                                           
#define CAN_FS1R_FSC24_Msk     (0x1UL << CAN_FS1R_FSC24_Pos)                    /*!< 0x01000000 */
#define CAN_FS1R_FSC24         CAN_FS1R_FSC24_Msk                              /*!<Filter Scale Configuration bit 24 */
#define CAN_FS1R_FSC25_Pos     (25U)                                           
#define CAN_FS1R_FSC25_Msk     (0x1UL << CAN_FS1R_FSC25_Pos)                    /*!< 0x02000000 */
#define CAN_FS1R_FSC25         CAN_FS1R_FSC25_Msk                              /*!<Filter Scale Configuration bit 25 */
#define CAN_FS1R_FSC26_Pos     (26U)                                           
#define CAN_FS1R_FSC26_Msk     (0x1UL << CAN_FS1R_FSC26_Pos)                    /*!< 0x04000000 */
#define CAN_FS1R_FSC26         CAN_FS1R_FSC26_Msk                              /*!<Filter Scale Configuration bit 26 */
#define CAN_FS1R_FSC27_Pos     (27U)                                           
#define CAN_FS1R_FSC27_Msk     (0x1UL << CAN_FS1R_FSC27_Pos)                    /*!< 0x08000000 */
#define CAN_FS1R_FSC27         CAN_FS1R_FSC27_Msk                              /*!<Filter Scale Configuration bit 27 */

/******************  Bit definition for CAN_FFA1R register  *******************/
#define CAN_FFA1R_FFA_Pos      (0U)                                            
#define CAN_FFA1R_FFA_Msk      (0xFFFFFFFUL << CAN_FFA1R_FFA_Pos)               /*!< 0x0FFFFFFF */
#define CAN_FFA1R_FFA          CAN_FFA1R_FFA_Msk                               /*!<Filter FIFO Assignment */
#define CAN_FFA1R_FFA0_Pos     (0U)                                            
#define CAN_FFA1R_FFA0_Msk     (0x1UL << CAN_FFA1R_FFA0_Pos)                    /*!< 0x00000001 */
#define CAN_FFA1R_FFA0         CAN_FFA1R_FFA0_Msk                              /*!<Filter FIFO Assignment bit 0 */
#define CAN_FFA1R_FFA1_Pos     (1U)                                            
#define CAN_FFA1R_FFA1_Msk     (0x1UL << CAN_FFA1R_FFA1_Pos)                    /*!< 0x00000002 */
#define CAN_FFA1R_FFA1         CAN_FFA1R_FFA1_Msk                              /*!<Filter FIFO Assignment bit 1 */
#define CAN_FFA1R_FFA2_Pos     (2U)                                            
#define CAN_FFA1R_FFA2_Msk     (0x1UL << CAN_FFA1R_FFA2_Pos)                    /*!< 0x00000004 */
#define CAN_FFA1R_FFA2         CAN_FFA1R_FFA2_Msk                              /*!<Filter FIFO Assignment bit 2 */
#define CAN_FFA1R_FFA3_Pos     (3U)                                            
#define CAN_FFA1R_FFA3_Msk     (0x1UL << CAN_FFA1R_FFA3_Pos)                    /*!< 0x00000008 */
#define CAN_FFA1R_FFA3         CAN_FFA1R_FFA3_Msk                              /*!<Filter FIFO Assignment bit 3 */
#define CAN_FFA1R_FFA4_Pos     (4U)                                            
#define CAN_FFA1R_FFA4_Msk     (0x1UL << CAN_FFA1R_FFA4_Pos)                    /*!< 0x00000010 */
#define CAN_FFA1R_FFA4         CAN_FFA1R_FFA4_Msk                              /*!<Filter FIFO Assignment bit 4 */
#define CAN_FFA1R_FFA5_Pos     (5U)                                            
#define CAN_FFA1R_FFA5_Msk     (0x1UL << CAN_FFA1R_FFA5_Pos)                    /*!< 0x00000020 */
#define CAN_FFA1R_FFA5         CAN_FFA1R_FFA5_Msk                              /*!<Filter FIFO Assignment bit 5 */
#define CAN_FFA1R_FFA6_Pos     (6U)                                            
#define CAN_FFA1R_FFA6_Msk     (0x1UL << CAN_FFA1R_FFA6_Pos)                    /*!< 0x00000040 */
#define CAN_FFA1R_FFA6         CAN_FFA1R_FFA6_Msk                              /*!<Filter FIFO Assignment bit 6 */
#define CAN_FFA1R_FFA7_Pos     (7U)                                            
#define CAN_FFA1R_FFA7_Msk     (0x1UL << CAN_FFA1R_FFA7_Pos)                    /*!< 0x00000080 */
#define CAN_FFA1R_FFA7         CAN_FFA1R_FFA7_Msk                              /*!<Filter FIFO Assignment bit 7 */
#define CAN_FFA1R_FFA8_Pos     (8U)                                            
#define CAN_FFA1R_FFA8_Msk     (0x1UL << CAN_FFA1R_FFA8_Pos)                    /*!< 0x00000100 */
#define CAN_FFA1R_FFA8         CAN_FFA1R_FFA8_Msk                              /*!<Filter FIFO Assignment bit 8 */
#define CAN_FFA1R_FFA9_Pos     (9U)                                            
#define CAN_FFA1R_FFA9_Msk     (0x1UL << CAN_FFA1R_FFA9_Pos)                    /*!< 0x00000200 */
#define CAN_FFA1R_FFA9         CAN_FFA1R_FFA9_Msk                              /*!<Filter FIFO Assignment bit 9 */
#define CAN_FFA1R_FFA10_Pos    (10U)                                           
#define CAN_FFA1R_FFA10_Msk    (0x1UL << CAN_FFA1R_FFA10_Pos)                   /*!< 0x00000400 */
#define CAN_FFA1R_FFA10        CAN_FFA1R_FFA10_Msk                             /*!<Filter FIFO Assignment bit 10 */
#define CAN_FFA1R_FFA11_Pos    (11U)                                           
#define CAN_FFA1R_FFA11_Msk    (0x1UL << CAN_FFA1R_FFA11_Pos)                   /*!< 0x00000800 */
#define CAN_FFA1R_FFA11        CAN_FFA1R_FFA11_Msk                             /*!<Filter FIFO Assignment bit 11 */
#define CAN_FFA1R_FFA12_Pos    (12U)                                           
#define CAN_FFA1R_FFA12_Msk    (0x1UL << CAN_FFA1R_FFA12_Pos)                   /*!< 0x00001000 */
#define CAN_FFA1R_FFA12        CAN_FFA1R_FFA12_Msk                             /*!<Filter FIFO Assignment bit 12 */
#define CAN_FFA1R_FFA13_Pos    (13U)                                           
#define CAN_FFA1R_FFA13_Msk    (0x1UL << CAN_FFA1R_FFA13_Pos)                   /*!< 0x00002000 */
#define CAN_FFA1R_FFA13        CAN_FFA1R_FFA13_Msk                             /*!<Filter FIFO Assignment bit 13 */
#define CAN_FFA1R_FFA14_Pos    (14U)                                           
#define CAN_FFA1R_FFA14_Msk    (0x1UL << CAN_FFA1R_FFA14_Pos)                   /*!< 0x00004000 */
#define CAN_FFA1R_FFA14        CAN_FFA1R_FFA14_Msk                             /*!<Filter FIFO Assignment bit 14 */
#define CAN_FFA1R_FFA15_Pos    (15U)                                           
#define CAN_FFA1R_FFA15_Msk    (0x1UL << CAN_FFA1R_FFA15_Pos)                   /*!< 0x00008000 */
#define CAN_FFA1R_FFA15        CAN_FFA1R_FFA15_Msk                             /*!<Filter FIFO Assignment bit 15 */
#define CAN_FFA1R_FFA16_Pos    (16U)                                           
#define CAN_FFA1R_FFA16_Msk    (0x1UL << CAN_FFA1R_FFA16_Pos)                   /*!< 0x00010000 */
#define CAN_FFA1R_FFA16        CAN_FFA1R_FFA16_Msk                             /*!<Filter FIFO Assignment bit 16 */
#define CAN_FFA1R_FFA17_Pos    (17U)                                           
#define CAN_FFA1R_FFA17_Msk    (0x1UL << CAN_FFA1R_FFA17_Pos)                   /*!< 0x00020000 */
#define CAN_FFA1R_FFA17        CAN_FFA1R_FFA17_Msk                             /*!<Filter FIFO Assignment bit 17 */
#define CAN_FFA1R_FFA18_Pos    (18U)                                           
#define CAN_FFA1R_FFA18_Msk    (0x1UL << CAN_FFA1R_FFA18_Pos)                   /*!< 0x00040000 */
#define CAN_FFA1R_FFA18        CAN_FFA1R_FFA18_Msk                             /*!<Filter FIFO Assignment bit 18 */
#define CAN_FFA1R_FFA19_Pos    (19U)                                           
#define CAN_FFA1R_FFA19_Msk    (0x1UL << CAN_FFA1R_FFA19_Pos)                   /*!< 0x00080000 */
#define CAN_FFA1R_FFA19        CAN_FFA1R_FFA19_Msk                             /*!<Filter FIFO Assignment bit 19 */
#define CAN_FFA1R_FFA20_Pos    (20U)                                           
#define CAN_FFA1R_FFA20_Msk    (0x1UL << CAN_FFA1R_FFA20_Pos)                   /*!< 0x00100000 */
#define CAN_FFA1R_FFA20        CAN_FFA1R_FFA20_Msk                             /*!<Filter FIFO Assignment bit 20 */
#define CAN_FFA1R_FFA21_Pos    (21U)                                           
#define CAN_FFA1R_FFA21_Msk    (0x1UL << CAN_FFA1R_FFA21_Pos)                   /*!< 0x00200000 */
#define CAN_FFA1R_FFA21        CAN_FFA1R_FFA21_Msk                             /*!<Filter FIFO Assignment bit 21 */
#define CAN_FFA1R_FFA22_Pos    (22U)                                           
#define CAN_FFA1R_FFA22_Msk    (0x1UL << CAN_FFA1R_FFA22_Pos)                   /*!< 0x00400000 */
#define CAN_FFA1R_FFA22        CAN_FFA1R_FFA22_Msk                             /*!<Filter FIFO Assignment bit 22 */
#define CAN_FFA1R_FFA23_Pos    (23U)                                           
#define CAN_FFA1R_FFA23_Msk    (0x1UL << CAN_FFA1R_FFA23_Pos)                   /*!< 0x00800000 */
#define CAN_FFA1R_FFA23        CAN_FFA1R_FFA23_Msk                             /*!<Filter FIFO Assignment bit 23 */
#define CAN_FFA1R_FFA24_Pos    (24U)                                           
#define CAN_FFA1R_FFA24_Msk    (0x1UL << CAN_FFA1R_FFA24_Pos)                   /*!< 0x01000000 */
#define CAN_FFA1R_FFA24        CAN_FFA1R_FFA24_Msk                             /*!<Filter FIFO Assignment bit 24 */
#define CAN_FFA1R_FFA25_Pos    (25U)                                           
#define CAN_FFA1R_FFA25_Msk    (0x1UL << CAN_FFA1R_FFA25_Pos)                   /*!< 0x02000000 */
#define CAN_FFA1R_FFA25        CAN_FFA1R_FFA25_Msk                             /*!<Filter FIFO Assignment bit 25 */
#define CAN_FFA1R_FFA26_Pos    (26U)                                           
#define CAN_FFA1R_FFA26_Msk    (0x1UL << CAN_FFA1R_FFA26_Pos)                   /*!< 0x04000000 */
#define CAN_FFA1R_FFA26        CAN_FFA1R_FFA26_Msk                             /*!<Filter FIFO Assignment bit 26 */
#define CAN_FFA1R_FFA27_Pos    (27U)                                           
#define CAN_FFA1R_FFA27_Msk    (0x1UL << CAN_FFA1R_FFA27_Pos)                   /*!< 0x08000000 */
#define CAN_FFA1R_FFA27        CAN_FFA1R_FFA27_Msk                             /*!<Filter FIFO Assignment bit 27 */

/*******************  Bit definition for CAN_FA1R register  *******************/
#define CAN_FA1R_FACT_Pos      (0U)                                            
#define CAN_FA1R_FACT_Msk      (0xFFFFFFFUL << CAN_FA1R_FACT_Pos)               /*!< 0x0FFFFFFF */
#define CAN_FA1R_FACT          CAN_FA1R_FACT_Msk                               /*!<Filter Active */
#define CAN_FA1R_FACT0_Pos     (0U)                                            
#define CAN_FA1R_FACT0_Msk     (0x1UL << CAN_FA1R_FACT0_Pos)                    /*!< 0x00000001 */
#define CAN_FA1R_FACT0         CAN_FA1R_FACT0_Msk                              /*!<Filter Active bit 0 */
#define CAN_FA1R_FACT1_Pos     (1U)                                            
#define CAN_FA1R_FACT1_Msk     (0x1UL << CAN_FA1R_FACT1_Pos)                    /*!< 0x00000002 */
#define CAN_FA1R_FACT1         CAN_FA1R_FACT1_Msk                              /*!<Filter Active bit 1 */
#define CAN_FA1R_FACT2_Pos     (2U)                                            
#define CAN_FA1R_FACT2_Msk     (0x1UL << CAN_FA1R_FACT2_Pos)                    /*!< 0x00000004 */
#define CAN_FA1R_FACT2         CAN_FA1R_FACT2_Msk                              /*!<Filter Active bit 2 */
#define CAN_FA1R_FACT3_Pos     (3U)                                            
#define CAN_FA1R_FACT3_Msk     (0x1UL << CAN_FA1R_FACT3_Pos)                    /*!< 0x00000008 */
#define CAN_FA1R_FACT3         CAN_FA1R_FACT3_Msk                              /*!<Filter Active bit 3 */
#define CAN_FA1R_FACT4_Pos     (4U)                                            
#define CAN_FA1R_FACT4_Msk     (0x1UL << CAN_FA1R_FACT4_Pos)                    /*!< 0x00000010 */
#define CAN_FA1R_FACT4         CAN_FA1R_FACT4_Msk                              /*!<Filter Active bit 4 */
#define CAN_FA1R_FACT5_Pos     (5U)                                            
#define CAN_FA1R_FACT5_Msk     (0x1UL << CAN_FA1R_FACT5_Pos)                    /*!< 0x00000020 */
#define CAN_FA1R_FACT5         CAN_FA1R_FACT5_Msk                              /*!<Filter Active bit 5 */
#define CAN_FA1R_FACT6_Pos     (6U)                                            
#define CAN_FA1R_FACT6_Msk     (0x1UL << CAN_FA1R_FACT6_Pos)                    /*!< 0x00000040 */
#define CAN_FA1R_FACT6         CAN_FA1R_FACT6_Msk                              /*!<Filter Active bit 6 */
#define CAN_FA1R_FACT7_Pos     (7U)                                            
#define CAN_FA1R_FACT7_Msk     (0x1UL << CAN_FA1R_FACT7_Pos)                    /*!< 0x00000080 */
#define CAN_FA1R_FACT7         CAN_FA1R_FACT7_Msk                              /*!<Filter Active bit 7 */
#define CAN_FA1R_FACT8_Pos     (8U)                                            
#define CAN_FA1R_FACT8_Msk     (0x1UL << CAN_FA1R_FACT8_Pos)                    /*!< 0x00000100 */
#define CAN_FA1R_FACT8         CAN_FA1R_FACT8_Msk                              /*!<Filter Active bit 8 */
#define CAN_FA1R_FACT9_Pos     (9U)                                            
#define CAN_FA1R_FACT9_Msk     (0x1UL << CAN_FA1R_FACT9_Pos)                    /*!< 0x00000200 */
#define CAN_FA1R_FACT9         CAN_FA1R_FACT9_Msk                              /*!<Filter Active bit 9 */
#define CAN_FA1R_FACT10_Pos    (10U)                                           
#define CAN_FA1R_FACT10_Msk    (0x1UL << CAN_FA1R_FACT10_Pos)                   /*!< 0x00000400 */
#define CAN_FA1R_FACT10        CAN_FA1R_FACT10_Msk                             /*!<Filter Active bit 10 */
#define CAN_FA1R_FACT11_Pos    (11U)                                           
#define CAN_FA1R_FACT11_Msk    (0x1UL << CAN_FA1R_FACT11_Pos)                   /*!< 0x00000800 */
#define CAN_FA1R_FACT11        CAN_FA1R_FACT11_Msk                             /*!<Filter Active bit 11 */
#define CAN_FA1R_FACT12_Pos    (12U)                                           
#define CAN_FA1R_FACT12_Msk    (0x1UL << CAN_FA1R_FACT12_Pos)                   /*!< 0x00001000 */
#define CAN_FA1R_FACT12        CAN_FA1R_FACT12_Msk                             /*!<Filter Active bit 12 */
#define CAN_FA1R_FACT13_Pos    (13U)                                           
#define CAN_FA1R_FACT13_Msk    (0x1UL << CAN_FA1R_FACT13_Pos)                   /*!< 0x00002000 */
#define CAN_FA1R_FACT13        CAN_FA1R_FACT13_Msk                             /*!<Filter Active bit 13 */
#define CAN_FA1R_FACT14_Pos    (14U)                                           
#define CAN_FA1R_FACT14_Msk    (0x1UL << CAN_FA1R_FACT14_Pos)                   /*!< 0x00004000 */
#define CAN_FA1R_FACT14        CAN_FA1R_FACT14_Msk                             /*!<Filter Active bit 14 */
#define CAN_FA1R_FACT15_Pos    (15U)                                           
#define CAN_FA1R_FACT15_Msk    (0x1UL << CAN_FA1R_FACT15_Pos)                   /*!< 0x00008000 */
#define CAN_FA1R_FACT15        CAN_FA1R_FACT15_Msk                             /*!<Filter Active bit 15 */
#define CAN_FA1R_FACT16_Pos    (16U)                                           
#define CAN_FA1R_FACT16_Msk    (0x1UL << CAN_FA1R_FACT16_Pos)                   /*!< 0x00010000 */
#define CAN_FA1R_FACT16        CAN_FA1R_FACT16_Msk                             /*!<Filter Active bit 16 */
#define CAN_FA1R_FACT17_Pos    (17U)                                           
#define CAN_FA1R_FACT17_Msk    (0x1UL << CAN_FA1R_FACT17_Pos)                   /*!< 0x00020000 */
#define CAN_FA1R_FACT17        CAN_FA1R_FACT17_Msk                             /*!<Filter Active bit 17 */
#define CAN_FA1R_FACT18_Pos    (18U)                                           
#define CAN_FA1R_FACT18_Msk    (0x1UL << CAN_FA1R_FACT18_Pos)                   /*!< 0x00040000 */
#define CAN_FA1R_FACT18        CAN_FA1R_FACT18_Msk                             /*!<Filter Active bit 18 */
#define CAN_FA1R_FACT19_Pos    (19U)                                           
#define CAN_FA1R_FACT19_Msk    (0x1UL << CAN_FA1R_FACT19_Pos)                   /*!< 0x00080000 */
#define CAN_FA1R_FACT19        CAN_FA1R_FACT19_Msk                             /*!<Filter Active bit 19 */
#define CAN_FA1R_FACT20_Pos    (20U)                                           
#define CAN_FA1R_FACT20_Msk    (0x1UL << CAN_FA1R_FACT20_Pos)                   /*!< 0x00100000 */
#define CAN_FA1R_FACT20        CAN_FA1R_FACT20_Msk                             /*!<Filter Active bit 20 */
#define CAN_FA1R_FACT21_Pos    (21U)                                           
#define CAN_FA1R_FACT21_Msk    (0x1UL << CAN_FA1R_FACT21_Pos)                   /*!< 0x00200000 */
#define CAN_FA1R_FACT21        CAN_FA1R_FACT21_Msk                             /*!<Filter Active bit 21 */
#define CAN_FA1R_FACT22_Pos    (22U)                                           
#define CAN_FA1R_FACT22_Msk    (0x1UL << CAN_FA1R_FACT22_Pos)                   /*!< 0x00400000 */
#define CAN_FA1R_FACT22        CAN_FA1R_FACT22_Msk                             /*!<Filter Active bit 22 */
#define CAN_FA1R_FACT23_Pos    (23U)                                           
#define CAN_FA1R_FACT23_Msk    (0x1UL << CAN_FA1R_FACT23_Pos)                   /*!< 0x00800000 */
#define CAN_FA1R_FACT23        CAN_FA1R_FACT23_Msk                             /*!<Filter Active bit 23 */
#define CAN_FA1R_FACT24_Pos    (24U)                                           
#define CAN_FA1R_FACT24_Msk    (0x1UL << CAN_FA1R_FACT24_Pos)                   /*!< 0x01000000 */
#define CAN_FA1R_FACT24        CAN_FA1R_FACT24_Msk                             /*!<Filter Active bit 24 */
#define CAN_FA1R_FACT25_Pos    (25U)                                           
#define CAN_FA1R_FACT25_Msk    (0x1UL << CAN_FA1R_FACT25_Pos)                   /*!< 0x02000000 */
#define CAN_FA1R_FACT25        CAN_FA1R_FACT25_Msk                             /*!<Filter Active bit 25 */
#define CAN_FA1R_FACT26_Pos    (26U)                                           
#define CAN_FA1R_FACT26_Msk    (0x1UL << CAN_FA1R_FACT26_Pos)                   /*!< 0x04000000 */
#define CAN_FA1R_FACT26        CAN_FA1R_FACT26_Msk                             /*!<Filter Active bit 26 */
#define CAN_FA1R_FACT27_Pos    (27U)                                           
#define CAN_FA1R_FACT27_Msk    (0x1UL << CAN_FA1R_FACT27_Pos)                   /*!< 0x08000000 */
#define CAN_FA1R_FACT27        CAN_FA1R_FACT27_Msk                             /*!<Filter Active bit 27 */


/*******************  Bit definition for CAN_F0R1 register  *******************/
#define CAN_F0R1_FB0_Pos       (0U)                                            
#define CAN_F0R1_FB0_Msk       (0x1UL << CAN_F0R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F0R1_FB0           CAN_F0R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F0R1_FB1_Pos       (1U)                                            
#define CAN_F0R1_FB1_Msk       (0x1UL << CAN_F0R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F0R1_FB1           CAN_F0R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F0R1_FB2_Pos       (2U)                                            
#define CAN_F0R1_FB2_Msk       (0x1UL << CAN_F0R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F0R1_FB2           CAN_F0R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F0R1_FB3_Pos       (3U)                                            
#define CAN_F0R1_FB3_Msk       (0x1UL << CAN_F0R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F0R1_FB3           CAN_F0R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F0R1_FB4_Pos       (4U)                                            
#define CAN_F0R1_FB4_Msk       (0x1UL << CAN_F0R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F0R1_FB4           CAN_F0R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F0R1_FB5_Pos       (5U)                                            
#define CAN_F0R1_FB5_Msk       (0x1UL << CAN_F0R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F0R1_FB5           CAN_F0R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F0R1_FB6_Pos       (6U)                                            
#define CAN_F0R1_FB6_Msk       (0x1UL << CAN_F0R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F0R1_FB6           CAN_F0R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F0R1_FB7_Pos       (7U)                                            
#define CAN_F0R1_FB7_Msk       (0x1UL << CAN_F0R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F0R1_FB7           CAN_F0R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F0R1_FB8_Pos       (8U)                                            
#define CAN_F0R1_FB8_Msk       (0x1UL << CAN_F0R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F0R1_FB8           CAN_F0R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F0R1_FB9_Pos       (9U)                                            
#define CAN_F0R1_FB9_Msk       (0x1UL << CAN_F0R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F0R1_FB9           CAN_F0R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F0R1_FB10_Pos      (10U)                                           
#define CAN_F0R1_FB10_Msk      (0x1UL << CAN_F0R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F0R1_FB10          CAN_F0R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F0R1_FB11_Pos      (11U)                                           
#define CAN_F0R1_FB11_Msk      (0x1UL << CAN_F0R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F0R1_FB11          CAN_F0R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F0R1_FB12_Pos      (12U)                                           
#define CAN_F0R1_FB12_Msk      (0x1UL << CAN_F0R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F0R1_FB12          CAN_F0R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F0R1_FB13_Pos      (13U)                                           
#define CAN_F0R1_FB13_Msk      (0x1UL << CAN_F0R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F0R1_FB13          CAN_F0R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F0R1_FB14_Pos      (14U)                                           
#define CAN_F0R1_FB14_Msk      (0x1UL << CAN_F0R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F0R1_FB14          CAN_F0R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F0R1_FB15_Pos      (15U)                                           
#define CAN_F0R1_FB15_Msk      (0x1UL << CAN_F0R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F0R1_FB15          CAN_F0R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F0R1_FB16_Pos      (16U)                                           
#define CAN_F0R1_FB16_Msk      (0x1UL << CAN_F0R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F0R1_FB16          CAN_F0R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F0R1_FB17_Pos      (17U)                                           
#define CAN_F0R1_FB17_Msk      (0x1UL << CAN_F0R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F0R1_FB17          CAN_F0R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F0R1_FB18_Pos      (18U)                                           
#define CAN_F0R1_FB18_Msk      (0x1UL << CAN_F0R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F0R1_FB18          CAN_F0R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F0R1_FB19_Pos      (19U)                                           
#define CAN_F0R1_FB19_Msk      (0x1UL << CAN_F0R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F0R1_FB19          CAN_F0R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F0R1_FB20_Pos      (20U)                                           
#define CAN_F0R1_FB20_Msk      (0x1UL << CAN_F0R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F0R1_FB20          CAN_F0R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F0R1_FB21_Pos      (21U)                                           
#define CAN_F0R1_FB21_Msk      (0x1UL << CAN_F0R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F0R1_FB21          CAN_F0R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F0R1_FB22_Pos      (22U)                                           
#define CAN_F0R1_FB22_Msk      (0x1UL << CAN_F0R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F0R1_FB22          CAN_F0R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F0R1_FB23_Pos      (23U)                                           
#define CAN_F0R1_FB23_Msk      (0x1UL << CAN_F0R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F0R1_FB23          CAN_F0R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F0R1_FB24_Pos      (24U)                                           
#define CAN_F0R1_FB24_Msk      (0x1UL << CAN_F0R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F0R1_FB24          CAN_F0R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F0R1_FB25_Pos      (25U)                                           
#define CAN_F0R1_FB25_Msk      (0x1UL << CAN_F0R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F0R1_FB25          CAN_F0R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F0R1_FB26_Pos      (26U)                                           
#define CAN_F0R1_FB26_Msk      (0x1UL << CAN_F0R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F0R1_FB26          CAN_F0R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F0R1_FB27_Pos      (27U)                                           
#define CAN_F0R1_FB27_Msk      (0x1UL << CAN_F0R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F0R1_FB27          CAN_F0R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F0R1_FB28_Pos      (28U)                                           
#define CAN_F0R1_FB28_Msk      (0x1UL << CAN_F0R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F0R1_FB28          CAN_F0R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F0R1_FB29_Pos      (29U)                                           
#define CAN_F0R1_FB29_Msk      (0x1UL << CAN_F0R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F0R1_FB29          CAN_F0R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F0R1_FB30_Pos      (30U)                                           
#define CAN_F0R1_FB30_Msk      (0x1UL << CAN_F0R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F0R1_FB30          CAN_F0R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F0R1_FB31_Pos      (31U)                                           
#define CAN_F0R1_FB31_Msk      (0x1UL << CAN_F0R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F0R1_FB31          CAN_F0R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define CAN_F1R1_FB0_Pos       (0U)                                            
#define CAN_F1R1_FB0_Msk       (0x1UL << CAN_F1R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F1R1_FB0           CAN_F1R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F1R1_FB1_Pos       (1U)                                            
#define CAN_F1R1_FB1_Msk       (0x1UL << CAN_F1R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F1R1_FB1           CAN_F1R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F1R1_FB2_Pos       (2U)                                            
#define CAN_F1R1_FB2_Msk       (0x1UL << CAN_F1R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F1R1_FB2           CAN_F1R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F1R1_FB3_Pos       (3U)                                            
#define CAN_F1R1_FB3_Msk       (0x1UL << CAN_F1R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F1R1_FB3           CAN_F1R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F1R1_FB4_Pos       (4U)                                            
#define CAN_F1R1_FB4_Msk       (0x1UL << CAN_F1R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F1R1_FB4           CAN_F1R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F1R1_FB5_Pos       (5U)                                            
#define CAN_F1R1_FB5_Msk       (0x1UL << CAN_F1R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F1R1_FB5           CAN_F1R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F1R1_FB6_Pos       (6U)                                            
#define CAN_F1R1_FB6_Msk       (0x1UL << CAN_F1R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F1R1_FB6           CAN_F1R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F1R1_FB7_Pos       (7U)                                            
#define CAN_F1R1_FB7_Msk       (0x1UL << CAN_F1R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F1R1_FB7           CAN_F1R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F1R1_FB8_Pos       (8U)                                            
#define CAN_F1R1_FB8_Msk       (0x1UL << CAN_F1R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F1R1_FB8           CAN_F1R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F1R1_FB9_Pos       (9U)                                            
#define CAN_F1R1_FB9_Msk       (0x1UL << CAN_F1R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F1R1_FB9           CAN_F1R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F1R1_FB10_Pos      (10U)                                           
#define CAN_F1R1_FB10_Msk      (0x1UL << CAN_F1R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F1R1_FB10          CAN_F1R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F1R1_FB11_Pos      (11U)                                           
#define CAN_F1R1_FB11_Msk      (0x1UL << CAN_F1R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F1R1_FB11          CAN_F1R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F1R1_FB12_Pos      (12U)                                           
#define CAN_F1R1_FB12_Msk      (0x1UL << CAN_F1R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F1R1_FB12          CAN_F1R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F1R1_FB13_Pos      (13U)                                           
#define CAN_F1R1_FB13_Msk      (0x1UL << CAN_F1R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F1R1_FB13          CAN_F1R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F1R1_FB14_Pos      (14U)                                           
#define CAN_F1R1_FB14_Msk      (0x1UL << CAN_F1R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F1R1_FB14          CAN_F1R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F1R1_FB15_Pos      (15U)                                           
#define CAN_F1R1_FB15_Msk      (0x1UL << CAN_F1R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F1R1_FB15          CAN_F1R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F1R1_FB16_Pos      (16U)                                           
#define CAN_F1R1_FB16_Msk      (0x1UL << CAN_F1R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F1R1_FB16          CAN_F1R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F1R1_FB17_Pos      (17U)                                           
#define CAN_F1R1_FB17_Msk      (0x1UL << CAN_F1R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F1R1_FB17          CAN_F1R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F1R1_FB18_Pos      (18U)                                           
#define CAN_F1R1_FB18_Msk      (0x1UL << CAN_F1R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F1R1_FB18          CAN_F1R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F1R1_FB19_Pos      (19U)                                           
#define CAN_F1R1_FB19_Msk      (0x1UL << CAN_F1R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F1R1_FB19          CAN_F1R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F1R1_FB20_Pos      (20U)                                           
#define CAN_F1R1_FB20_Msk      (0x1UL << CAN_F1R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F1R1_FB20          CAN_F1R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F1R1_FB21_Pos      (21U)                                           
#define CAN_F1R1_FB21_Msk      (0x1UL << CAN_F1R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F1R1_FB21          CAN_F1R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F1R1_FB22_Pos      (22U)                                           
#define CAN_F1R1_FB22_Msk      (0x1UL << CAN_F1R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F1R1_FB22          CAN_F1R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F1R1_FB23_Pos      (23U)                                           
#define CAN_F1R1_FB23_Msk      (0x1UL << CAN_F1R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F1R1_FB23          CAN_F1R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F1R1_FB24_Pos      (24U)                                           
#define CAN_F1R1_FB24_Msk      (0x1UL << CAN_F1R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F1R1_FB24          CAN_F1R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F1R1_FB25_Pos      (25U)                                           
#define CAN_F1R1_FB25_Msk      (0x1UL << CAN_F1R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F1R1_FB25          CAN_F1R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F1R1_FB26_Pos      (26U)                                           
#define CAN_F1R1_FB26_Msk      (0x1UL << CAN_F1R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F1R1_FB26          CAN_F1R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F1R1_FB27_Pos      (27U)                                           
#define CAN_F1R1_FB27_Msk      (0x1UL << CAN_F1R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F1R1_FB27          CAN_F1R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F1R1_FB28_Pos      (28U)                                           
#define CAN_F1R1_FB28_Msk      (0x1UL << CAN_F1R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F1R1_FB28          CAN_F1R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F1R1_FB29_Pos      (29U)                                           
#define CAN_F1R1_FB29_Msk      (0x1UL << CAN_F1R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F1R1_FB29          CAN_F1R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F1R1_FB30_Pos      (30U)                                           
#define CAN_F1R1_FB30_Msk      (0x1UL << CAN_F1R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F1R1_FB30          CAN_F1R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F1R1_FB31_Pos      (31U)                                           
#define CAN_F1R1_FB31_Msk      (0x1UL << CAN_F1R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F1R1_FB31          CAN_F1R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define CAN_F2R1_FB0_Pos       (0U)                                            
#define CAN_F2R1_FB0_Msk       (0x1UL << CAN_F2R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F2R1_FB0           CAN_F2R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F2R1_FB1_Pos       (1U)                                            
#define CAN_F2R1_FB1_Msk       (0x1UL << CAN_F2R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F2R1_FB1           CAN_F2R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F2R1_FB2_Pos       (2U)                                            
#define CAN_F2R1_FB2_Msk       (0x1UL << CAN_F2R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F2R1_FB2           CAN_F2R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F2R1_FB3_Pos       (3U)                                            
#define CAN_F2R1_FB3_Msk       (0x1UL << CAN_F2R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F2R1_FB3           CAN_F2R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F2R1_FB4_Pos       (4U)                                            
#define CAN_F2R1_FB4_Msk       (0x1UL << CAN_F2R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F2R1_FB4           CAN_F2R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F2R1_FB5_Pos       (5U)                                            
#define CAN_F2R1_FB5_Msk       (0x1UL << CAN_F2R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F2R1_FB5           CAN_F2R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F2R1_FB6_Pos       (6U)                                            
#define CAN_F2R1_FB6_Msk       (0x1UL << CAN_F2R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F2R1_FB6           CAN_F2R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F2R1_FB7_Pos       (7U)                                            
#define CAN_F2R1_FB7_Msk       (0x1UL << CAN_F2R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F2R1_FB7           CAN_F2R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F2R1_FB8_Pos       (8U)                                            
#define CAN_F2R1_FB8_Msk       (0x1UL << CAN_F2R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F2R1_FB8           CAN_F2R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F2R1_FB9_Pos       (9U)                                            
#define CAN_F2R1_FB9_Msk       (0x1UL << CAN_F2R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F2R1_FB9           CAN_F2R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F2R1_FB10_Pos      (10U)                                           
#define CAN_F2R1_FB10_Msk      (0x1UL << CAN_F2R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F2R1_FB10          CAN_F2R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F2R1_FB11_Pos      (11U)                                           
#define CAN_F2R1_FB11_Msk      (0x1UL << CAN_F2R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F2R1_FB11          CAN_F2R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F2R1_FB12_Pos      (12U)                                           
#define CAN_F2R1_FB12_Msk      (0x1UL << CAN_F2R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F2R1_FB12          CAN_F2R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F2R1_FB13_Pos      (13U)                                           
#define CAN_F2R1_FB13_Msk      (0x1UL << CAN_F2R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F2R1_FB13          CAN_F2R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F2R1_FB14_Pos      (14U)                                           
#define CAN_F2R1_FB14_Msk      (0x1UL << CAN_F2R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F2R1_FB14          CAN_F2R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F2R1_FB15_Pos      (15U)                                           
#define CAN_F2R1_FB15_Msk      (0x1UL << CAN_F2R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F2R1_FB15          CAN_F2R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F2R1_FB16_Pos      (16U)                                           
#define CAN_F2R1_FB16_Msk      (0x1UL << CAN_F2R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F2R1_FB16          CAN_F2R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F2R1_FB17_Pos      (17U)                                           
#define CAN_F2R1_FB17_Msk      (0x1UL << CAN_F2R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F2R1_FB17          CAN_F2R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F2R1_FB18_Pos      (18U)                                           
#define CAN_F2R1_FB18_Msk      (0x1UL << CAN_F2R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F2R1_FB18          CAN_F2R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F2R1_FB19_Pos      (19U)                                           
#define CAN_F2R1_FB19_Msk      (0x1UL << CAN_F2R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F2R1_FB19          CAN_F2R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F2R1_FB20_Pos      (20U)                                           
#define CAN_F2R1_FB20_Msk      (0x1UL << CAN_F2R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F2R1_FB20          CAN_F2R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F2R1_FB21_Pos      (21U)                                           
#define CAN_F2R1_FB21_Msk      (0x1UL << CAN_F2R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F2R1_FB21          CAN_F2R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F2R1_FB22_Pos      (22U)                                           
#define CAN_F2R1_FB22_Msk      (0x1UL << CAN_F2R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F2R1_FB22          CAN_F2R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F2R1_FB23_Pos      (23U)                                           
#define CAN_F2R1_FB23_Msk      (0x1UL << CAN_F2R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F2R1_FB23          CAN_F2R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F2R1_FB24_Pos      (24U)                                           
#define CAN_F2R1_FB24_Msk      (0x1UL << CAN_F2R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F2R1_FB24          CAN_F2R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F2R1_FB25_Pos      (25U)                                           
#define CAN_F2R1_FB25_Msk      (0x1UL << CAN_F2R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F2R1_FB25          CAN_F2R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F2R1_FB26_Pos      (26U)                                           
#define CAN_F2R1_FB26_Msk      (0x1UL << CAN_F2R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F2R1_FB26          CAN_F2R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F2R1_FB27_Pos      (27U)                                           
#define CAN_F2R1_FB27_Msk      (0x1UL << CAN_F2R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F2R1_FB27          CAN_F2R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F2R1_FB28_Pos      (28U)                                           
#define CAN_F2R1_FB28_Msk      (0x1UL << CAN_F2R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F2R1_FB28          CAN_F2R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F2R1_FB29_Pos      (29U)                                           
#define CAN_F2R1_FB29_Msk      (0x1UL << CAN_F2R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F2R1_FB29          CAN_F2R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F2R1_FB30_Pos      (30U)                                           
#define CAN_F2R1_FB30_Msk      (0x1UL << CAN_F2R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F2R1_FB30          CAN_F2R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F2R1_FB31_Pos      (31U)                                           
#define CAN_F2R1_FB31_Msk      (0x1UL << CAN_F2R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F2R1_FB31          CAN_F2R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define CAN_F3R1_FB0_Pos       (0U)                                            
#define CAN_F3R1_FB0_Msk       (0x1UL << CAN_F3R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F3R1_FB0           CAN_F3R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F3R1_FB1_Pos       (1U)                                            
#define CAN_F3R1_FB1_Msk       (0x1UL << CAN_F3R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F3R1_FB1           CAN_F3R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F3R1_FB2_Pos       (2U)                                            
#define CAN_F3R1_FB2_Msk       (0x1UL << CAN_F3R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F3R1_FB2           CAN_F3R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F3R1_FB3_Pos       (3U)                                            
#define CAN_F3R1_FB3_Msk       (0x1UL << CAN_F3R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F3R1_FB3           CAN_F3R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F3R1_FB4_Pos       (4U)                                            
#define CAN_F3R1_FB4_Msk       (0x1UL << CAN_F3R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F3R1_FB4           CAN_F3R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F3R1_FB5_Pos       (5U)                                            
#define CAN_F3R1_FB5_Msk       (0x1UL << CAN_F3R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F3R1_FB5           CAN_F3R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F3R1_FB6_Pos       (6U)                                            
#define CAN_F3R1_FB6_Msk       (0x1UL << CAN_F3R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F3R1_FB6           CAN_F3R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F3R1_FB7_Pos       (7U)                                            
#define CAN_F3R1_FB7_Msk       (0x1UL << CAN_F3R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F3R1_FB7           CAN_F3R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F3R1_FB8_Pos       (8U)                                            
#define CAN_F3R1_FB8_Msk       (0x1UL << CAN_F3R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F3R1_FB8           CAN_F3R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F3R1_FB9_Pos       (9U)                                            
#define CAN_F3R1_FB9_Msk       (0x1UL << CAN_F3R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F3R1_FB9           CAN_F3R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F3R1_FB10_Pos      (10U)                                           
#define CAN_F3R1_FB10_Msk      (0x1UL << CAN_F3R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F3R1_FB10          CAN_F3R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F3R1_FB11_Pos      (11U)                                           
#define CAN_F3R1_FB11_Msk      (0x1UL << CAN_F3R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F3R1_FB11          CAN_F3R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F3R1_FB12_Pos      (12U)                                           
#define CAN_F3R1_FB12_Msk      (0x1UL << CAN_F3R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F3R1_FB12          CAN_F3R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F3R1_FB13_Pos      (13U)                                           
#define CAN_F3R1_FB13_Msk      (0x1UL << CAN_F3R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F3R1_FB13          CAN_F3R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F3R1_FB14_Pos      (14U)                                           
#define CAN_F3R1_FB14_Msk      (0x1UL << CAN_F3R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F3R1_FB14          CAN_F3R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F3R1_FB15_Pos      (15U)                                           
#define CAN_F3R1_FB15_Msk      (0x1UL << CAN_F3R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F3R1_FB15          CAN_F3R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F3R1_FB16_Pos      (16U)                                           
#define CAN_F3R1_FB16_Msk      (0x1UL << CAN_F3R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F3R1_FB16          CAN_F3R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F3R1_FB17_Pos      (17U)                                           
#define CAN_F3R1_FB17_Msk      (0x1UL << CAN_F3R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F3R1_FB17          CAN_F3R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F3R1_FB18_Pos      (18U)                                           
#define CAN_F3R1_FB18_Msk      (0x1UL << CAN_F3R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F3R1_FB18          CAN_F3R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F3R1_FB19_Pos      (19U)                                           
#define CAN_F3R1_FB19_Msk      (0x1UL << CAN_F3R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F3R1_FB19          CAN_F3R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F3R1_FB20_Pos      (20U)                                           
#define CAN_F3R1_FB20_Msk      (0x1UL << CAN_F3R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F3R1_FB20          CAN_F3R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F3R1_FB21_Pos      (21U)                                           
#define CAN_F3R1_FB21_Msk      (0x1UL << CAN_F3R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F3R1_FB21          CAN_F3R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F3R1_FB22_Pos      (22U)                                           
#define CAN_F3R1_FB22_Msk      (0x1UL << CAN_F3R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F3R1_FB22          CAN_F3R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F3R1_FB23_Pos      (23U)                                           
#define CAN_F3R1_FB23_Msk      (0x1UL << CAN_F3R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F3R1_FB23          CAN_F3R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F3R1_FB24_Pos      (24U)                                           
#define CAN_F3R1_FB24_Msk      (0x1UL << CAN_F3R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F3R1_FB24          CAN_F3R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F3R1_FB25_Pos      (25U)                                           
#define CAN_F3R1_FB25_Msk      (0x1UL << CAN_F3R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F3R1_FB25          CAN_F3R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F3R1_FB26_Pos      (26U)                                           
#define CAN_F3R1_FB26_Msk      (0x1UL << CAN_F3R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F3R1_FB26          CAN_F3R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F3R1_FB27_Pos      (27U)                                           
#define CAN_F3R1_FB27_Msk      (0x1UL << CAN_F3R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F3R1_FB27          CAN_F3R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F3R1_FB28_Pos      (28U)                                           
#define CAN_F3R1_FB28_Msk      (0x1UL << CAN_F3R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F3R1_FB28          CAN_F3R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F3R1_FB29_Pos      (29U)                                           
#define CAN_F3R1_FB29_Msk      (0x1UL << CAN_F3R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F3R1_FB29          CAN_F3R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F3R1_FB30_Pos      (30U)                                           
#define CAN_F3R1_FB30_Msk      (0x1UL << CAN_F3R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F3R1_FB30          CAN_F3R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F3R1_FB31_Pos      (31U)                                           
#define CAN_F3R1_FB31_Msk      (0x1UL << CAN_F3R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F3R1_FB31          CAN_F3R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define CAN_F4R1_FB0_Pos       (0U)                                            
#define CAN_F4R1_FB0_Msk       (0x1UL << CAN_F4R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F4R1_FB0           CAN_F4R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F4R1_FB1_Pos       (1U)                                            
#define CAN_F4R1_FB1_Msk       (0x1UL << CAN_F4R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F4R1_FB1           CAN_F4R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F4R1_FB2_Pos       (2U)                                            
#define CAN_F4R1_FB2_Msk       (0x1UL << CAN_F4R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F4R1_FB2           CAN_F4R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F4R1_FB3_Pos       (3U)                                            
#define CAN_F4R1_FB3_Msk       (0x1UL << CAN_F4R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F4R1_FB3           CAN_F4R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F4R1_FB4_Pos       (4U)                                            
#define CAN_F4R1_FB4_Msk       (0x1UL << CAN_F4R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F4R1_FB4           CAN_F4R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F4R1_FB5_Pos       (5U)                                            
#define CAN_F4R1_FB5_Msk       (0x1UL << CAN_F4R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F4R1_FB5           CAN_F4R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F4R1_FB6_Pos       (6U)                                            
#define CAN_F4R1_FB6_Msk       (0x1UL << CAN_F4R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F4R1_FB6           CAN_F4R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F4R1_FB7_Pos       (7U)                                            
#define CAN_F4R1_FB7_Msk       (0x1UL << CAN_F4R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F4R1_FB7           CAN_F4R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F4R1_FB8_Pos       (8U)                                            
#define CAN_F4R1_FB8_Msk       (0x1UL << CAN_F4R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F4R1_FB8           CAN_F4R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F4R1_FB9_Pos       (9U)                                            
#define CAN_F4R1_FB9_Msk       (0x1UL << CAN_F4R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F4R1_FB9           CAN_F4R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F4R1_FB10_Pos      (10U)                                           
#define CAN_F4R1_FB10_Msk      (0x1UL << CAN_F4R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F4R1_FB10          CAN_F4R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F4R1_FB11_Pos      (11U)                                           
#define CAN_F4R1_FB11_Msk      (0x1UL << CAN_F4R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F4R1_FB11          CAN_F4R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F4R1_FB12_Pos      (12U)                                           
#define CAN_F4R1_FB12_Msk      (0x1UL << CAN_F4R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F4R1_FB12          CAN_F4R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F4R1_FB13_Pos      (13U)                                           
#define CAN_F4R1_FB13_Msk      (0x1UL << CAN_F4R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F4R1_FB13          CAN_F4R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F4R1_FB14_Pos      (14U)                                           
#define CAN_F4R1_FB14_Msk      (0x1UL << CAN_F4R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F4R1_FB14          CAN_F4R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F4R1_FB15_Pos      (15U)                                           
#define CAN_F4R1_FB15_Msk      (0x1UL << CAN_F4R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F4R1_FB15          CAN_F4R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F4R1_FB16_Pos      (16U)                                           
#define CAN_F4R1_FB16_Msk      (0x1UL << CAN_F4R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F4R1_FB16          CAN_F4R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F4R1_FB17_Pos      (17U)                                           
#define CAN_F4R1_FB17_Msk      (0x1UL << CAN_F4R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F4R1_FB17          CAN_F4R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F4R1_FB18_Pos      (18U)                                           
#define CAN_F4R1_FB18_Msk      (0x1UL << CAN_F4R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F4R1_FB18          CAN_F4R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F4R1_FB19_Pos      (19U)                                           
#define CAN_F4R1_FB19_Msk      (0x1UL << CAN_F4R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F4R1_FB19          CAN_F4R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F4R1_FB20_Pos      (20U)                                           
#define CAN_F4R1_FB20_Msk      (0x1UL << CAN_F4R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F4R1_FB20          CAN_F4R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F4R1_FB21_Pos      (21U)                                           
#define CAN_F4R1_FB21_Msk      (0x1UL << CAN_F4R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F4R1_FB21          CAN_F4R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F4R1_FB22_Pos      (22U)                                           
#define CAN_F4R1_FB22_Msk      (0x1UL << CAN_F4R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F4R1_FB22          CAN_F4R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F4R1_FB23_Pos      (23U)                                           
#define CAN_F4R1_FB23_Msk      (0x1UL << CAN_F4R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F4R1_FB23          CAN_F4R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F4R1_FB24_Pos      (24U)                                           
#define CAN_F4R1_FB24_Msk      (0x1UL << CAN_F4R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F4R1_FB24          CAN_F4R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F4R1_FB25_Pos      (25U)                                           
#define CAN_F4R1_FB25_Msk      (0x1UL << CAN_F4R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F4R1_FB25          CAN_F4R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F4R1_FB26_Pos      (26U)                                           
#define CAN_F4R1_FB26_Msk      (0x1UL << CAN_F4R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F4R1_FB26          CAN_F4R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F4R1_FB27_Pos      (27U)                                           
#define CAN_F4R1_FB27_Msk      (0x1UL << CAN_F4R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F4R1_FB27          CAN_F4R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F4R1_FB28_Pos      (28U)                                           
#define CAN_F4R1_FB28_Msk      (0x1UL << CAN_F4R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F4R1_FB28          CAN_F4R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F4R1_FB29_Pos      (29U)                                           
#define CAN_F4R1_FB29_Msk      (0x1UL << CAN_F4R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F4R1_FB29          CAN_F4R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F4R1_FB30_Pos      (30U)                                           
#define CAN_F4R1_FB30_Msk      (0x1UL << CAN_F4R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F4R1_FB30          CAN_F4R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F4R1_FB31_Pos      (31U)                                           
#define CAN_F4R1_FB31_Msk      (0x1UL << CAN_F4R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F4R1_FB31          CAN_F4R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define CAN_F5R1_FB0_Pos       (0U)                                            
#define CAN_F5R1_FB0_Msk       (0x1UL << CAN_F5R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F5R1_FB0           CAN_F5R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F5R1_FB1_Pos       (1U)                                            
#define CAN_F5R1_FB1_Msk       (0x1UL << CAN_F5R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F5R1_FB1           CAN_F5R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F5R1_FB2_Pos       (2U)                                            
#define CAN_F5R1_FB2_Msk       (0x1UL << CAN_F5R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F5R1_FB2           CAN_F5R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F5R1_FB3_Pos       (3U)                                            
#define CAN_F5R1_FB3_Msk       (0x1UL << CAN_F5R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F5R1_FB3           CAN_F5R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F5R1_FB4_Pos       (4U)                                            
#define CAN_F5R1_FB4_Msk       (0x1UL << CAN_F5R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F5R1_FB4           CAN_F5R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F5R1_FB5_Pos       (5U)                                            
#define CAN_F5R1_FB5_Msk       (0x1UL << CAN_F5R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F5R1_FB5           CAN_F5R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F5R1_FB6_Pos       (6U)                                            
#define CAN_F5R1_FB6_Msk       (0x1UL << CAN_F5R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F5R1_FB6           CAN_F5R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F5R1_FB7_Pos       (7U)                                            
#define CAN_F5R1_FB7_Msk       (0x1UL << CAN_F5R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F5R1_FB7           CAN_F5R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F5R1_FB8_Pos       (8U)                                            
#define CAN_F5R1_FB8_Msk       (0x1UL << CAN_F5R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F5R1_FB8           CAN_F5R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F5R1_FB9_Pos       (9U)                                            
#define CAN_F5R1_FB9_Msk       (0x1UL << CAN_F5R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F5R1_FB9           CAN_F5R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F5R1_FB10_Pos      (10U)                                           
#define CAN_F5R1_FB10_Msk      (0x1UL << CAN_F5R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F5R1_FB10          CAN_F5R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F5R1_FB11_Pos      (11U)                                           
#define CAN_F5R1_FB11_Msk      (0x1UL << CAN_F5R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F5R1_FB11          CAN_F5R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F5R1_FB12_Pos      (12U)                                           
#define CAN_F5R1_FB12_Msk      (0x1UL << CAN_F5R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F5R1_FB12          CAN_F5R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F5R1_FB13_Pos      (13U)                                           
#define CAN_F5R1_FB13_Msk      (0x1UL << CAN_F5R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F5R1_FB13          CAN_F5R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F5R1_FB14_Pos      (14U)                                           
#define CAN_F5R1_FB14_Msk      (0x1UL << CAN_F5R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F5R1_FB14          CAN_F5R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F5R1_FB15_Pos      (15U)                                           
#define CAN_F5R1_FB15_Msk      (0x1UL << CAN_F5R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F5R1_FB15          CAN_F5R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F5R1_FB16_Pos      (16U)                                           
#define CAN_F5R1_FB16_Msk      (0x1UL << CAN_F5R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F5R1_FB16          CAN_F5R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F5R1_FB17_Pos      (17U)                                           
#define CAN_F5R1_FB17_Msk      (0x1UL << CAN_F5R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F5R1_FB17          CAN_F5R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F5R1_FB18_Pos      (18U)                                           
#define CAN_F5R1_FB18_Msk      (0x1UL << CAN_F5R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F5R1_FB18          CAN_F5R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F5R1_FB19_Pos      (19U)                                           
#define CAN_F5R1_FB19_Msk      (0x1UL << CAN_F5R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F5R1_FB19          CAN_F5R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F5R1_FB20_Pos      (20U)                                           
#define CAN_F5R1_FB20_Msk      (0x1UL << CAN_F5R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F5R1_FB20          CAN_F5R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F5R1_FB21_Pos      (21U)                                           
#define CAN_F5R1_FB21_Msk      (0x1UL << CAN_F5R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F5R1_FB21          CAN_F5R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F5R1_FB22_Pos      (22U)                                           
#define CAN_F5R1_FB22_Msk      (0x1UL << CAN_F5R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F5R1_FB22          CAN_F5R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F5R1_FB23_Pos      (23U)                                           
#define CAN_F5R1_FB23_Msk      (0x1UL << CAN_F5R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F5R1_FB23          CAN_F5R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F5R1_FB24_Pos      (24U)                                           
#define CAN_F5R1_FB24_Msk      (0x1UL << CAN_F5R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F5R1_FB24          CAN_F5R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F5R1_FB25_Pos      (25U)                                           
#define CAN_F5R1_FB25_Msk      (0x1UL << CAN_F5R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F5R1_FB25          CAN_F5R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F5R1_FB26_Pos      (26U)                                           
#define CAN_F5R1_FB26_Msk      (0x1UL << CAN_F5R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F5R1_FB26          CAN_F5R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F5R1_FB27_Pos      (27U)                                           
#define CAN_F5R1_FB27_Msk      (0x1UL << CAN_F5R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F5R1_FB27          CAN_F5R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F5R1_FB28_Pos      (28U)                                           
#define CAN_F5R1_FB28_Msk      (0x1UL << CAN_F5R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F5R1_FB28          CAN_F5R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F5R1_FB29_Pos      (29U)                                           
#define CAN_F5R1_FB29_Msk      (0x1UL << CAN_F5R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F5R1_FB29          CAN_F5R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F5R1_FB30_Pos      (30U)                                           
#define CAN_F5R1_FB30_Msk      (0x1UL << CAN_F5R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F5R1_FB30          CAN_F5R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F5R1_FB31_Pos      (31U)                                           
#define CAN_F5R1_FB31_Msk      (0x1UL << CAN_F5R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F5R1_FB31          CAN_F5R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define CAN_F6R1_FB0_Pos       (0U)                                            
#define CAN_F6R1_FB0_Msk       (0x1UL << CAN_F6R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F6R1_FB0           CAN_F6R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F6R1_FB1_Pos       (1U)                                            
#define CAN_F6R1_FB1_Msk       (0x1UL << CAN_F6R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F6R1_FB1           CAN_F6R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F6R1_FB2_Pos       (2U)                                            
#define CAN_F6R1_FB2_Msk       (0x1UL << CAN_F6R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F6R1_FB2           CAN_F6R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F6R1_FB3_Pos       (3U)                                            
#define CAN_F6R1_FB3_Msk       (0x1UL << CAN_F6R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F6R1_FB3           CAN_F6R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F6R1_FB4_Pos       (4U)                                            
#define CAN_F6R1_FB4_Msk       (0x1UL << CAN_F6R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F6R1_FB4           CAN_F6R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F6R1_FB5_Pos       (5U)                                            
#define CAN_F6R1_FB5_Msk       (0x1UL << CAN_F6R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F6R1_FB5           CAN_F6R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F6R1_FB6_Pos       (6U)                                            
#define CAN_F6R1_FB6_Msk       (0x1UL << CAN_F6R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F6R1_FB6           CAN_F6R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F6R1_FB7_Pos       (7U)                                            
#define CAN_F6R1_FB7_Msk       (0x1UL << CAN_F6R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F6R1_FB7           CAN_F6R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F6R1_FB8_Pos       (8U)                                            
#define CAN_F6R1_FB8_Msk       (0x1UL << CAN_F6R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F6R1_FB8           CAN_F6R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F6R1_FB9_Pos       (9U)                                            
#define CAN_F6R1_FB9_Msk       (0x1UL << CAN_F6R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F6R1_FB9           CAN_F6R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F6R1_FB10_Pos      (10U)                                           
#define CAN_F6R1_FB10_Msk      (0x1UL << CAN_F6R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F6R1_FB10          CAN_F6R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F6R1_FB11_Pos      (11U)                                           
#define CAN_F6R1_FB11_Msk      (0x1UL << CAN_F6R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F6R1_FB11          CAN_F6R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F6R1_FB12_Pos      (12U)                                           
#define CAN_F6R1_FB12_Msk      (0x1UL << CAN_F6R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F6R1_FB12          CAN_F6R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F6R1_FB13_Pos      (13U)                                           
#define CAN_F6R1_FB13_Msk      (0x1UL << CAN_F6R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F6R1_FB13          CAN_F6R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F6R1_FB14_Pos      (14U)                                           
#define CAN_F6R1_FB14_Msk      (0x1UL << CAN_F6R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F6R1_FB14          CAN_F6R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F6R1_FB15_Pos      (15U)                                           
#define CAN_F6R1_FB15_Msk      (0x1UL << CAN_F6R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F6R1_FB15          CAN_F6R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F6R1_FB16_Pos      (16U)                                           
#define CAN_F6R1_FB16_Msk      (0x1UL << CAN_F6R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F6R1_FB16          CAN_F6R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F6R1_FB17_Pos      (17U)                                           
#define CAN_F6R1_FB17_Msk      (0x1UL << CAN_F6R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F6R1_FB17          CAN_F6R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F6R1_FB18_Pos      (18U)                                           
#define CAN_F6R1_FB18_Msk      (0x1UL << CAN_F6R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F6R1_FB18          CAN_F6R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F6R1_FB19_Pos      (19U)                                           
#define CAN_F6R1_FB19_Msk      (0x1UL << CAN_F6R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F6R1_FB19          CAN_F6R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F6R1_FB20_Pos      (20U)                                           
#define CAN_F6R1_FB20_Msk      (0x1UL << CAN_F6R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F6R1_FB20          CAN_F6R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F6R1_FB21_Pos      (21U)                                           
#define CAN_F6R1_FB21_Msk      (0x1UL << CAN_F6R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F6R1_FB21          CAN_F6R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F6R1_FB22_Pos      (22U)                                           
#define CAN_F6R1_FB22_Msk      (0x1UL << CAN_F6R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F6R1_FB22          CAN_F6R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F6R1_FB23_Pos      (23U)                                           
#define CAN_F6R1_FB23_Msk      (0x1UL << CAN_F6R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F6R1_FB23          CAN_F6R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F6R1_FB24_Pos      (24U)                                           
#define CAN_F6R1_FB24_Msk      (0x1UL << CAN_F6R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F6R1_FB24          CAN_F6R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F6R1_FB25_Pos      (25U)                                           
#define CAN_F6R1_FB25_Msk      (0x1UL << CAN_F6R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F6R1_FB25          CAN_F6R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F6R1_FB26_Pos      (26U)                                           
#define CAN_F6R1_FB26_Msk      (0x1UL << CAN_F6R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F6R1_FB26          CAN_F6R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F6R1_FB27_Pos      (27U)                                           
#define CAN_F6R1_FB27_Msk      (0x1UL << CAN_F6R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F6R1_FB27          CAN_F6R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F6R1_FB28_Pos      (28U)                                           
#define CAN_F6R1_FB28_Msk      (0x1UL << CAN_F6R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F6R1_FB28          CAN_F6R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F6R1_FB29_Pos      (29U)                                           
#define CAN_F6R1_FB29_Msk      (0x1UL << CAN_F6R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F6R1_FB29          CAN_F6R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F6R1_FB30_Pos      (30U)                                           
#define CAN_F6R1_FB30_Msk      (0x1UL << CAN_F6R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F6R1_FB30          CAN_F6R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F6R1_FB31_Pos      (31U)                                           
#define CAN_F6R1_FB31_Msk      (0x1UL << CAN_F6R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F6R1_FB31          CAN_F6R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define CAN_F7R1_FB0_Pos       (0U)                                            
#define CAN_F7R1_FB0_Msk       (0x1UL << CAN_F7R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F7R1_FB0           CAN_F7R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F7R1_FB1_Pos       (1U)                                            
#define CAN_F7R1_FB1_Msk       (0x1UL << CAN_F7R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F7R1_FB1           CAN_F7R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F7R1_FB2_Pos       (2U)                                            
#define CAN_F7R1_FB2_Msk       (0x1UL << CAN_F7R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F7R1_FB2           CAN_F7R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F7R1_FB3_Pos       (3U)                                            
#define CAN_F7R1_FB3_Msk       (0x1UL << CAN_F7R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F7R1_FB3           CAN_F7R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F7R1_FB4_Pos       (4U)                                            
#define CAN_F7R1_FB4_Msk       (0x1UL << CAN_F7R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F7R1_FB4           CAN_F7R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F7R1_FB5_Pos       (5U)                                            
#define CAN_F7R1_FB5_Msk       (0x1UL << CAN_F7R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F7R1_FB5           CAN_F7R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F7R1_FB6_Pos       (6U)                                            
#define CAN_F7R1_FB6_Msk       (0x1UL << CAN_F7R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F7R1_FB6           CAN_F7R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F7R1_FB7_Pos       (7U)                                            
#define CAN_F7R1_FB7_Msk       (0x1UL << CAN_F7R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F7R1_FB7           CAN_F7R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F7R1_FB8_Pos       (8U)                                            
#define CAN_F7R1_FB8_Msk       (0x1UL << CAN_F7R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F7R1_FB8           CAN_F7R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F7R1_FB9_Pos       (9U)                                            
#define CAN_F7R1_FB9_Msk       (0x1UL << CAN_F7R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F7R1_FB9           CAN_F7R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F7R1_FB10_Pos      (10U)                                           
#define CAN_F7R1_FB10_Msk      (0x1UL << CAN_F7R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F7R1_FB10          CAN_F7R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F7R1_FB11_Pos      (11U)                                           
#define CAN_F7R1_FB11_Msk      (0x1UL << CAN_F7R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F7R1_FB11          CAN_F7R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F7R1_FB12_Pos      (12U)                                           
#define CAN_F7R1_FB12_Msk      (0x1UL << CAN_F7R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F7R1_FB12          CAN_F7R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F7R1_FB13_Pos      (13U)                                           
#define CAN_F7R1_FB13_Msk      (0x1UL << CAN_F7R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F7R1_FB13          CAN_F7R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F7R1_FB14_Pos      (14U)                                           
#define CAN_F7R1_FB14_Msk      (0x1UL << CAN_F7R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F7R1_FB14          CAN_F7R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F7R1_FB15_Pos      (15U)                                           
#define CAN_F7R1_FB15_Msk      (0x1UL << CAN_F7R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F7R1_FB15          CAN_F7R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F7R1_FB16_Pos      (16U)                                           
#define CAN_F7R1_FB16_Msk      (0x1UL << CAN_F7R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F7R1_FB16          CAN_F7R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F7R1_FB17_Pos      (17U)                                           
#define CAN_F7R1_FB17_Msk      (0x1UL << CAN_F7R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F7R1_FB17          CAN_F7R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F7R1_FB18_Pos      (18U)                                           
#define CAN_F7R1_FB18_Msk      (0x1UL << CAN_F7R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F7R1_FB18          CAN_F7R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F7R1_FB19_Pos      (19U)                                           
#define CAN_F7R1_FB19_Msk      (0x1UL << CAN_F7R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F7R1_FB19          CAN_F7R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F7R1_FB20_Pos      (20U)                                           
#define CAN_F7R1_FB20_Msk      (0x1UL << CAN_F7R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F7R1_FB20          CAN_F7R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F7R1_FB21_Pos      (21U)                                           
#define CAN_F7R1_FB21_Msk      (0x1UL << CAN_F7R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F7R1_FB21          CAN_F7R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F7R1_FB22_Pos      (22U)                                           
#define CAN_F7R1_FB22_Msk      (0x1UL << CAN_F7R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F7R1_FB22          CAN_F7R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F7R1_FB23_Pos      (23U)                                           
#define CAN_F7R1_FB23_Msk      (0x1UL << CAN_F7R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F7R1_FB23          CAN_F7R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F7R1_FB24_Pos      (24U)                                           
#define CAN_F7R1_FB24_Msk      (0x1UL << CAN_F7R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F7R1_FB24          CAN_F7R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F7R1_FB25_Pos      (25U)                                           
#define CAN_F7R1_FB25_Msk      (0x1UL << CAN_F7R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F7R1_FB25          CAN_F7R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F7R1_FB26_Pos      (26U)                                           
#define CAN_F7R1_FB26_Msk      (0x1UL << CAN_F7R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F7R1_FB26          CAN_F7R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F7R1_FB27_Pos      (27U)                                           
#define CAN_F7R1_FB27_Msk      (0x1UL << CAN_F7R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F7R1_FB27          CAN_F7R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F7R1_FB28_Pos      (28U)                                           
#define CAN_F7R1_FB28_Msk      (0x1UL << CAN_F7R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F7R1_FB28          CAN_F7R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F7R1_FB29_Pos      (29U)                                           
#define CAN_F7R1_FB29_Msk      (0x1UL << CAN_F7R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F7R1_FB29          CAN_F7R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F7R1_FB30_Pos      (30U)                                           
#define CAN_F7R1_FB30_Msk      (0x1UL << CAN_F7R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F7R1_FB30          CAN_F7R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F7R1_FB31_Pos      (31U)                                           
#define CAN_F7R1_FB31_Msk      (0x1UL << CAN_F7R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F7R1_FB31          CAN_F7R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define CAN_F8R1_FB0_Pos       (0U)                                            
#define CAN_F8R1_FB0_Msk       (0x1UL << CAN_F8R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F8R1_FB0           CAN_F8R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F8R1_FB1_Pos       (1U)                                            
#define CAN_F8R1_FB1_Msk       (0x1UL << CAN_F8R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F8R1_FB1           CAN_F8R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F8R1_FB2_Pos       (2U)                                            
#define CAN_F8R1_FB2_Msk       (0x1UL << CAN_F8R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F8R1_FB2           CAN_F8R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F8R1_FB3_Pos       (3U)                                            
#define CAN_F8R1_FB3_Msk       (0x1UL << CAN_F8R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F8R1_FB3           CAN_F8R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F8R1_FB4_Pos       (4U)                                            
#define CAN_F8R1_FB4_Msk       (0x1UL << CAN_F8R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F8R1_FB4           CAN_F8R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F8R1_FB5_Pos       (5U)                                            
#define CAN_F8R1_FB5_Msk       (0x1UL << CAN_F8R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F8R1_FB5           CAN_F8R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F8R1_FB6_Pos       (6U)                                            
#define CAN_F8R1_FB6_Msk       (0x1UL << CAN_F8R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F8R1_FB6           CAN_F8R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F8R1_FB7_Pos       (7U)                                            
#define CAN_F8R1_FB7_Msk       (0x1UL << CAN_F8R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F8R1_FB7           CAN_F8R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F8R1_FB8_Pos       (8U)                                            
#define CAN_F8R1_FB8_Msk       (0x1UL << CAN_F8R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F8R1_FB8           CAN_F8R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F8R1_FB9_Pos       (9U)                                            
#define CAN_F8R1_FB9_Msk       (0x1UL << CAN_F8R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F8R1_FB9           CAN_F8R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F8R1_FB10_Pos      (10U)                                           
#define CAN_F8R1_FB10_Msk      (0x1UL << CAN_F8R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F8R1_FB10          CAN_F8R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F8R1_FB11_Pos      (11U)                                           
#define CAN_F8R1_FB11_Msk      (0x1UL << CAN_F8R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F8R1_FB11          CAN_F8R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F8R1_FB12_Pos      (12U)                                           
#define CAN_F8R1_FB12_Msk      (0x1UL << CAN_F8R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F8R1_FB12          CAN_F8R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F8R1_FB13_Pos      (13U)                                           
#define CAN_F8R1_FB13_Msk      (0x1UL << CAN_F8R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F8R1_FB13          CAN_F8R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F8R1_FB14_Pos      (14U)                                           
#define CAN_F8R1_FB14_Msk      (0x1UL << CAN_F8R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F8R1_FB14          CAN_F8R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F8R1_FB15_Pos      (15U)                                           
#define CAN_F8R1_FB15_Msk      (0x1UL << CAN_F8R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F8R1_FB15          CAN_F8R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F8R1_FB16_Pos      (16U)                                           
#define CAN_F8R1_FB16_Msk      (0x1UL << CAN_F8R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F8R1_FB16          CAN_F8R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F8R1_FB17_Pos      (17U)                                           
#define CAN_F8R1_FB17_Msk      (0x1UL << CAN_F8R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F8R1_FB17          CAN_F8R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F8R1_FB18_Pos      (18U)                                           
#define CAN_F8R1_FB18_Msk      (0x1UL << CAN_F8R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F8R1_FB18          CAN_F8R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F8R1_FB19_Pos      (19U)                                           
#define CAN_F8R1_FB19_Msk      (0x1UL << CAN_F8R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F8R1_FB19          CAN_F8R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F8R1_FB20_Pos      (20U)                                           
#define CAN_F8R1_FB20_Msk      (0x1UL << CAN_F8R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F8R1_FB20          CAN_F8R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F8R1_FB21_Pos      (21U)                                           
#define CAN_F8R1_FB21_Msk      (0x1UL << CAN_F8R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F8R1_FB21          CAN_F8R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F8R1_FB22_Pos      (22U)                                           
#define CAN_F8R1_FB22_Msk      (0x1UL << CAN_F8R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F8R1_FB22          CAN_F8R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F8R1_FB23_Pos      (23U)                                           
#define CAN_F8R1_FB23_Msk      (0x1UL << CAN_F8R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F8R1_FB23          CAN_F8R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F8R1_FB24_Pos      (24U)                                           
#define CAN_F8R1_FB24_Msk      (0x1UL << CAN_F8R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F8R1_FB24          CAN_F8R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F8R1_FB25_Pos      (25U)                                           
#define CAN_F8R1_FB25_Msk      (0x1UL << CAN_F8R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F8R1_FB25          CAN_F8R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F8R1_FB26_Pos      (26U)                                           
#define CAN_F8R1_FB26_Msk      (0x1UL << CAN_F8R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F8R1_FB26          CAN_F8R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F8R1_FB27_Pos      (27U)                                           
#define CAN_F8R1_FB27_Msk      (0x1UL << CAN_F8R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F8R1_FB27          CAN_F8R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F8R1_FB28_Pos      (28U)                                           
#define CAN_F8R1_FB28_Msk      (0x1UL << CAN_F8R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F8R1_FB28          CAN_F8R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F8R1_FB29_Pos      (29U)                                           
#define CAN_F8R1_FB29_Msk      (0x1UL << CAN_F8R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F8R1_FB29          CAN_F8R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F8R1_FB30_Pos      (30U)                                           
#define CAN_F8R1_FB30_Msk      (0x1UL << CAN_F8R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F8R1_FB30          CAN_F8R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F8R1_FB31_Pos      (31U)                                           
#define CAN_F8R1_FB31_Msk      (0x1UL << CAN_F8R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F8R1_FB31          CAN_F8R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define CAN_F9R1_FB0_Pos       (0U)                                            
#define CAN_F9R1_FB0_Msk       (0x1UL << CAN_F9R1_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F9R1_FB0           CAN_F9R1_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F9R1_FB1_Pos       (1U)                                            
#define CAN_F9R1_FB1_Msk       (0x1UL << CAN_F9R1_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F9R1_FB1           CAN_F9R1_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F9R1_FB2_Pos       (2U)                                            
#define CAN_F9R1_FB2_Msk       (0x1UL << CAN_F9R1_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F9R1_FB2           CAN_F9R1_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F9R1_FB3_Pos       (3U)                                            
#define CAN_F9R1_FB3_Msk       (0x1UL << CAN_F9R1_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F9R1_FB3           CAN_F9R1_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F9R1_FB4_Pos       (4U)                                            
#define CAN_F9R1_FB4_Msk       (0x1UL << CAN_F9R1_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F9R1_FB4           CAN_F9R1_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F9R1_FB5_Pos       (5U)                                            
#define CAN_F9R1_FB5_Msk       (0x1UL << CAN_F9R1_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F9R1_FB5           CAN_F9R1_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F9R1_FB6_Pos       (6U)                                            
#define CAN_F9R1_FB6_Msk       (0x1UL << CAN_F9R1_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F9R1_FB6           CAN_F9R1_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F9R1_FB7_Pos       (7U)                                            
#define CAN_F9R1_FB7_Msk       (0x1UL << CAN_F9R1_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F9R1_FB7           CAN_F9R1_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F9R1_FB8_Pos       (8U)                                            
#define CAN_F9R1_FB8_Msk       (0x1UL << CAN_F9R1_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F9R1_FB8           CAN_F9R1_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F9R1_FB9_Pos       (9U)                                            
#define CAN_F9R1_FB9_Msk       (0x1UL << CAN_F9R1_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F9R1_FB9           CAN_F9R1_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F9R1_FB10_Pos      (10U)                                           
#define CAN_F9R1_FB10_Msk      (0x1UL << CAN_F9R1_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F9R1_FB10          CAN_F9R1_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F9R1_FB11_Pos      (11U)                                           
#define CAN_F9R1_FB11_Msk      (0x1UL << CAN_F9R1_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F9R1_FB11          CAN_F9R1_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F9R1_FB12_Pos      (12U)                                           
#define CAN_F9R1_FB12_Msk      (0x1UL << CAN_F9R1_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F9R1_FB12          CAN_F9R1_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F9R1_FB13_Pos      (13U)                                           
#define CAN_F9R1_FB13_Msk      (0x1UL << CAN_F9R1_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F9R1_FB13          CAN_F9R1_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F9R1_FB14_Pos      (14U)                                           
#define CAN_F9R1_FB14_Msk      (0x1UL << CAN_F9R1_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F9R1_FB14          CAN_F9R1_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F9R1_FB15_Pos      (15U)                                           
#define CAN_F9R1_FB15_Msk      (0x1UL << CAN_F9R1_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F9R1_FB15          CAN_F9R1_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F9R1_FB16_Pos      (16U)                                           
#define CAN_F9R1_FB16_Msk      (0x1UL << CAN_F9R1_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F9R1_FB16          CAN_F9R1_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F9R1_FB17_Pos      (17U)                                           
#define CAN_F9R1_FB17_Msk      (0x1UL << CAN_F9R1_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F9R1_FB17          CAN_F9R1_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F9R1_FB18_Pos      (18U)                                           
#define CAN_F9R1_FB18_Msk      (0x1UL << CAN_F9R1_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F9R1_FB18          CAN_F9R1_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F9R1_FB19_Pos      (19U)                                           
#define CAN_F9R1_FB19_Msk      (0x1UL << CAN_F9R1_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F9R1_FB19          CAN_F9R1_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F9R1_FB20_Pos      (20U)                                           
#define CAN_F9R1_FB20_Msk      (0x1UL << CAN_F9R1_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F9R1_FB20          CAN_F9R1_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F9R1_FB21_Pos      (21U)                                           
#define CAN_F9R1_FB21_Msk      (0x1UL << CAN_F9R1_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F9R1_FB21          CAN_F9R1_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F9R1_FB22_Pos      (22U)                                           
#define CAN_F9R1_FB22_Msk      (0x1UL << CAN_F9R1_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F9R1_FB22          CAN_F9R1_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F9R1_FB23_Pos      (23U)                                           
#define CAN_F9R1_FB23_Msk      (0x1UL << CAN_F9R1_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F9R1_FB23          CAN_F9R1_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F9R1_FB24_Pos      (24U)                                           
#define CAN_F9R1_FB24_Msk      (0x1UL << CAN_F9R1_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F9R1_FB24          CAN_F9R1_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F9R1_FB25_Pos      (25U)                                           
#define CAN_F9R1_FB25_Msk      (0x1UL << CAN_F9R1_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F9R1_FB25          CAN_F9R1_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F9R1_FB26_Pos      (26U)                                           
#define CAN_F9R1_FB26_Msk      (0x1UL << CAN_F9R1_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F9R1_FB26          CAN_F9R1_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F9R1_FB27_Pos      (27U)                                           
#define CAN_F9R1_FB27_Msk      (0x1UL << CAN_F9R1_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F9R1_FB27          CAN_F9R1_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F9R1_FB28_Pos      (28U)                                           
#define CAN_F9R1_FB28_Msk      (0x1UL << CAN_F9R1_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F9R1_FB28          CAN_F9R1_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F9R1_FB29_Pos      (29U)                                           
#define CAN_F9R1_FB29_Msk      (0x1UL << CAN_F9R1_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F9R1_FB29          CAN_F9R1_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F9R1_FB30_Pos      (30U)                                           
#define CAN_F9R1_FB30_Msk      (0x1UL << CAN_F9R1_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F9R1_FB30          CAN_F9R1_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F9R1_FB31_Pos      (31U)                                           
#define CAN_F9R1_FB31_Msk      (0x1UL << CAN_F9R1_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F9R1_FB31          CAN_F9R1_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define CAN_F10R1_FB0_Pos      (0U)                                            
#define CAN_F10R1_FB0_Msk      (0x1UL << CAN_F10R1_FB0_Pos)                     /*!< 0x00000001 */
#define CAN_F10R1_FB0          CAN_F10R1_FB0_Msk                               /*!<Filter bit 0 */
#define CAN_F10R1_FB1_Pos      (1U)                                            
#define CAN_F10R1_FB1_Msk      (0x1UL << CAN_F10R1_FB1_Pos)                     /*!< 0x00000002 */
#define CAN_F10R1_FB1          CAN_F10R1_FB1_Msk                               /*!<Filter bit 1 */
#define CAN_F10R1_FB2_Pos      (2U)                                            
#define CAN_F10R1_FB2_Msk      (0x1UL << CAN_F10R1_FB2_Pos)                     /*!< 0x00000004 */
#define CAN_F10R1_FB2          CAN_F10R1_FB2_Msk                               /*!<Filter bit 2 */
#define CAN_F10R1_FB3_Pos      (3U)                                            
#define CAN_F10R1_FB3_Msk      (0x1UL << CAN_F10R1_FB3_Pos)                     /*!< 0x00000008 */
#define CAN_F10R1_FB3          CAN_F10R1_FB3_Msk                               /*!<Filter bit 3 */
#define CAN_F10R1_FB4_Pos      (4U)                                            
#define CAN_F10R1_FB4_Msk      (0x1UL << CAN_F10R1_FB4_Pos)                     /*!< 0x00000010 */
#define CAN_F10R1_FB4          CAN_F10R1_FB4_Msk                               /*!<Filter bit 4 */
#define CAN_F10R1_FB5_Pos      (5U)                                            
#define CAN_F10R1_FB5_Msk      (0x1UL << CAN_F10R1_FB5_Pos)                     /*!< 0x00000020 */
#define CAN_F10R1_FB5          CAN_F10R1_FB5_Msk                               /*!<Filter bit 5 */
#define CAN_F10R1_FB6_Pos      (6U)                                            
#define CAN_F10R1_FB6_Msk      (0x1UL << CAN_F10R1_FB6_Pos)                     /*!< 0x00000040 */
#define CAN_F10R1_FB6          CAN_F10R1_FB6_Msk                               /*!<Filter bit 6 */
#define CAN_F10R1_FB7_Pos      (7U)                                            
#define CAN_F10R1_FB7_Msk      (0x1UL << CAN_F10R1_FB7_Pos)                     /*!< 0x00000080 */
#define CAN_F10R1_FB7          CAN_F10R1_FB7_Msk                               /*!<Filter bit 7 */
#define CAN_F10R1_FB8_Pos      (8U)                                            
#define CAN_F10R1_FB8_Msk      (0x1UL << CAN_F10R1_FB8_Pos)                     /*!< 0x00000100 */
#define CAN_F10R1_FB8          CAN_F10R1_FB8_Msk                               /*!<Filter bit 8 */
#define CAN_F10R1_FB9_Pos      (9U)                                            
#define CAN_F10R1_FB9_Msk      (0x1UL << CAN_F10R1_FB9_Pos)                     /*!< 0x00000200 */
#define CAN_F10R1_FB9          CAN_F10R1_FB9_Msk                               /*!<Filter bit 9 */
#define CAN_F10R1_FB10_Pos     (10U)                                           
#define CAN_F10R1_FB10_Msk     (0x1UL << CAN_F10R1_FB10_Pos)                    /*!< 0x00000400 */
#define CAN_F10R1_FB10         CAN_F10R1_FB10_Msk                              /*!<Filter bit 10 */
#define CAN_F10R1_FB11_Pos     (11U)                                           
#define CAN_F10R1_FB11_Msk     (0x1UL << CAN_F10R1_FB11_Pos)                    /*!< 0x00000800 */
#define CAN_F10R1_FB11         CAN_F10R1_FB11_Msk                              /*!<Filter bit 11 */
#define CAN_F10R1_FB12_Pos     (12U)                                           
#define CAN_F10R1_FB12_Msk     (0x1UL << CAN_F10R1_FB12_Pos)                    /*!< 0x00001000 */
#define CAN_F10R1_FB12         CAN_F10R1_FB12_Msk                              /*!<Filter bit 12 */
#define CAN_F10R1_FB13_Pos     (13U)                                           
#define CAN_F10R1_FB13_Msk     (0x1UL << CAN_F10R1_FB13_Pos)                    /*!< 0x00002000 */
#define CAN_F10R1_FB13         CAN_F10R1_FB13_Msk                              /*!<Filter bit 13 */
#define CAN_F10R1_FB14_Pos     (14U)                                           
#define CAN_F10R1_FB14_Msk     (0x1UL << CAN_F10R1_FB14_Pos)                    /*!< 0x00004000 */
#define CAN_F10R1_FB14         CAN_F10R1_FB14_Msk                              /*!<Filter bit 14 */
#define CAN_F10R1_FB15_Pos     (15U)                                           
#define CAN_F10R1_FB15_Msk     (0x1UL << CAN_F10R1_FB15_Pos)                    /*!< 0x00008000 */
#define CAN_F10R1_FB15         CAN_F10R1_FB15_Msk                              /*!<Filter bit 15 */
#define CAN_F10R1_FB16_Pos     (16U)                                           
#define CAN_F10R1_FB16_Msk     (0x1UL << CAN_F10R1_FB16_Pos)                    /*!< 0x00010000 */
#define CAN_F10R1_FB16         CAN_F10R1_FB16_Msk                              /*!<Filter bit 16 */
#define CAN_F10R1_FB17_Pos     (17U)                                           
#define CAN_F10R1_FB17_Msk     (0x1UL << CAN_F10R1_FB17_Pos)                    /*!< 0x00020000 */
#define CAN_F10R1_FB17         CAN_F10R1_FB17_Msk                              /*!<Filter bit 17 */
#define CAN_F10R1_FB18_Pos     (18U)                                           
#define CAN_F10R1_FB18_Msk     (0x1UL << CAN_F10R1_FB18_Pos)                    /*!< 0x00040000 */
#define CAN_F10R1_FB18         CAN_F10R1_FB18_Msk                              /*!<Filter bit 18 */
#define CAN_F10R1_FB19_Pos     (19U)                                           
#define CAN_F10R1_FB19_Msk     (0x1UL << CAN_F10R1_FB19_Pos)                    /*!< 0x00080000 */
#define CAN_F10R1_FB19         CAN_F10R1_FB19_Msk                              /*!<Filter bit 19 */
#define CAN_F10R1_FB20_Pos     (20U)                                           
#define CAN_F10R1_FB20_Msk     (0x1UL << CAN_F10R1_FB20_Pos)                    /*!< 0x00100000 */
#define CAN_F10R1_FB20         CAN_F10R1_FB20_Msk                              /*!<Filter bit 20 */
#define CAN_F10R1_FB21_Pos     (21U)                                           
#define CAN_F10R1_FB21_Msk     (0x1UL << CAN_F10R1_FB21_Pos)                    /*!< 0x00200000 */
#define CAN_F10R1_FB21         CAN_F10R1_FB21_Msk                              /*!<Filter bit 21 */
#define CAN_F10R1_FB22_Pos     (22U)                                           
#define CAN_F10R1_FB22_Msk     (0x1UL << CAN_F10R1_FB22_Pos)                    /*!< 0x00400000 */
#define CAN_F10R1_FB22         CAN_F10R1_FB22_Msk                              /*!<Filter bit 22 */
#define CAN_F10R1_FB23_Pos     (23U)                                           
#define CAN_F10R1_FB23_Msk     (0x1UL << CAN_F10R1_FB23_Pos)                    /*!< 0x00800000 */
#define CAN_F10R1_FB23         CAN_F10R1_FB23_Msk                              /*!<Filter bit 23 */
#define CAN_F10R1_FB24_Pos     (24U)                                           
#define CAN_F10R1_FB24_Msk     (0x1UL << CAN_F10R1_FB24_Pos)                    /*!< 0x01000000 */
#define CAN_F10R1_FB24         CAN_F10R1_FB24_Msk                              /*!<Filter bit 24 */
#define CAN_F10R1_FB25_Pos     (25U)                                           
#define CAN_F10R1_FB25_Msk     (0x1UL << CAN_F10R1_FB25_Pos)                    /*!< 0x02000000 */
#define CAN_F10R1_FB25         CAN_F10R1_FB25_Msk                              /*!<Filter bit 25 */
#define CAN_F10R1_FB26_Pos     (26U)                                           
#define CAN_F10R1_FB26_Msk     (0x1UL << CAN_F10R1_FB26_Pos)                    /*!< 0x04000000 */
#define CAN_F10R1_FB26         CAN_F10R1_FB26_Msk                              /*!<Filter bit 26 */
#define CAN_F10R1_FB27_Pos     (27U)                                           
#define CAN_F10R1_FB27_Msk     (0x1UL << CAN_F10R1_FB27_Pos)                    /*!< 0x08000000 */
#define CAN_F10R1_FB27         CAN_F10R1_FB27_Msk                              /*!<Filter bit 27 */
#define CAN_F10R1_FB28_Pos     (28U)                                           
#define CAN_F10R1_FB28_Msk     (0x1UL << CAN_F10R1_FB28_Pos)                    /*!< 0x10000000 */
#define CAN_F10R1_FB28         CAN_F10R1_FB28_Msk                              /*!<Filter bit 28 */
#define CAN_F10R1_FB29_Pos     (29U)                                           
#define CAN_F10R1_FB29_Msk     (0x1UL << CAN_F10R1_FB29_Pos)                    /*!< 0x20000000 */
#define CAN_F10R1_FB29         CAN_F10R1_FB29_Msk                              /*!<Filter bit 29 */
#define CAN_F10R1_FB30_Pos     (30U)                                           
#define CAN_F10R1_FB30_Msk     (0x1UL << CAN_F10R1_FB30_Pos)                    /*!< 0x40000000 */
#define CAN_F10R1_FB30         CAN_F10R1_FB30_Msk                              /*!<Filter bit 30 */
#define CAN_F10R1_FB31_Pos     (31U)                                           
#define CAN_F10R1_FB31_Msk     (0x1UL << CAN_F10R1_FB31_Pos)                    /*!< 0x80000000 */
#define CAN_F10R1_FB31         CAN_F10R1_FB31_Msk                              /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define CAN_F11R1_FB0_Pos      (0U)                                            
#define CAN_F11R1_FB0_Msk      (0x1UL << CAN_F11R1_FB0_Pos)                     /*!< 0x00000001 */
#define CAN_F11R1_FB0          CAN_F11R1_FB0_Msk                               /*!<Filter bit 0 */
#define CAN_F11R1_FB1_Pos      (1U)                                            
#define CAN_F11R1_FB1_Msk      (0x1UL << CAN_F11R1_FB1_Pos)                     /*!< 0x00000002 */
#define CAN_F11R1_FB1          CAN_F11R1_FB1_Msk                               /*!<Filter bit 1 */
#define CAN_F11R1_FB2_Pos      (2U)                                            
#define CAN_F11R1_FB2_Msk      (0x1UL << CAN_F11R1_FB2_Pos)                     /*!< 0x00000004 */
#define CAN_F11R1_FB2          CAN_F11R1_FB2_Msk                               /*!<Filter bit 2 */
#define CAN_F11R1_FB3_Pos      (3U)                                            
#define CAN_F11R1_FB3_Msk      (0x1UL << CAN_F11R1_FB3_Pos)                     /*!< 0x00000008 */
#define CAN_F11R1_FB3          CAN_F11R1_FB3_Msk                               /*!<Filter bit 3 */
#define CAN_F11R1_FB4_Pos      (4U)                                            
#define CAN_F11R1_FB4_Msk      (0x1UL << CAN_F11R1_FB4_Pos)                     /*!< 0x00000010 */
#define CAN_F11R1_FB4          CAN_F11R1_FB4_Msk                               /*!<Filter bit 4 */
#define CAN_F11R1_FB5_Pos      (5U)                                            
#define CAN_F11R1_FB5_Msk      (0x1UL << CAN_F11R1_FB5_Pos)                     /*!< 0x00000020 */
#define CAN_F11R1_FB5          CAN_F11R1_FB5_Msk                               /*!<Filter bit 5 */
#define CAN_F11R1_FB6_Pos      (6U)                                            
#define CAN_F11R1_FB6_Msk      (0x1UL << CAN_F11R1_FB6_Pos)                     /*!< 0x00000040 */
#define CAN_F11R1_FB6          CAN_F11R1_FB6_Msk                               /*!<Filter bit 6 */
#define CAN_F11R1_FB7_Pos      (7U)                                            
#define CAN_F11R1_FB7_Msk      (0x1UL << CAN_F11R1_FB7_Pos)                     /*!< 0x00000080 */
#define CAN_F11R1_FB7          CAN_F11R1_FB7_Msk                               /*!<Filter bit 7 */
#define CAN_F11R1_FB8_Pos      (8U)                                            
#define CAN_F11R1_FB8_Msk      (0x1UL << CAN_F11R1_FB8_Pos)                     /*!< 0x00000100 */
#define CAN_F11R1_FB8          CAN_F11R1_FB8_Msk                               /*!<Filter bit 8 */
#define CAN_F11R1_FB9_Pos      (9U)                                            
#define CAN_F11R1_FB9_Msk      (0x1UL << CAN_F11R1_FB9_Pos)                     /*!< 0x00000200 */
#define CAN_F11R1_FB9          CAN_F11R1_FB9_Msk                               /*!<Filter bit 9 */
#define CAN_F11R1_FB10_Pos     (10U)                                           
#define CAN_F11R1_FB10_Msk     (0x1UL << CAN_F11R1_FB10_Pos)                    /*!< 0x00000400 */
#define CAN_F11R1_FB10         CAN_F11R1_FB10_Msk                              /*!<Filter bit 10 */
#define CAN_F11R1_FB11_Pos     (11U)                                           
#define CAN_F11R1_FB11_Msk     (0x1UL << CAN_F11R1_FB11_Pos)                    /*!< 0x00000800 */
#define CAN_F11R1_FB11         CAN_F11R1_FB11_Msk                              /*!<Filter bit 11 */
#define CAN_F11R1_FB12_Pos     (12U)                                           
#define CAN_F11R1_FB12_Msk     (0x1UL << CAN_F11R1_FB12_Pos)                    /*!< 0x00001000 */
#define CAN_F11R1_FB12         CAN_F11R1_FB12_Msk                              /*!<Filter bit 12 */
#define CAN_F11R1_FB13_Pos     (13U)                                           
#define CAN_F11R1_FB13_Msk     (0x1UL << CAN_F11R1_FB13_Pos)                    /*!< 0x00002000 */
#define CAN_F11R1_FB13         CAN_F11R1_FB13_Msk                              /*!<Filter bit 13 */
#define CAN_F11R1_FB14_Pos     (14U)                                           
#define CAN_F11R1_FB14_Msk     (0x1UL << CAN_F11R1_FB14_Pos)                    /*!< 0x00004000 */
#define CAN_F11R1_FB14         CAN_F11R1_FB14_Msk                              /*!<Filter bit 14 */
#define CAN_F11R1_FB15_Pos     (15U)                                           
#define CAN_F11R1_FB15_Msk     (0x1UL << CAN_F11R1_FB15_Pos)                    /*!< 0x00008000 */
#define CAN_F11R1_FB15         CAN_F11R1_FB15_Msk                              /*!<Filter bit 15 */
#define CAN_F11R1_FB16_Pos     (16U)                                           
#define CAN_F11R1_FB16_Msk     (0x1UL << CAN_F11R1_FB16_Pos)                    /*!< 0x00010000 */
#define CAN_F11R1_FB16         CAN_F11R1_FB16_Msk                              /*!<Filter bit 16 */
#define CAN_F11R1_FB17_Pos     (17U)                                           
#define CAN_F11R1_FB17_Msk     (0x1UL << CAN_F11R1_FB17_Pos)                    /*!< 0x00020000 */
#define CAN_F11R1_FB17         CAN_F11R1_FB17_Msk                              /*!<Filter bit 17 */
#define CAN_F11R1_FB18_Pos     (18U)                                           
#define CAN_F11R1_FB18_Msk     (0x1UL << CAN_F11R1_FB18_Pos)                    /*!< 0x00040000 */
#define CAN_F11R1_FB18         CAN_F11R1_FB18_Msk                              /*!<Filter bit 18 */
#define CAN_F11R1_FB19_Pos     (19U)                                           
#define CAN_F11R1_FB19_Msk     (0x1UL << CAN_F11R1_FB19_Pos)                    /*!< 0x00080000 */
#define CAN_F11R1_FB19         CAN_F11R1_FB19_Msk                              /*!<Filter bit 19 */
#define CAN_F11R1_FB20_Pos     (20U)                                           
#define CAN_F11R1_FB20_Msk     (0x1UL << CAN_F11R1_FB20_Pos)                    /*!< 0x00100000 */
#define CAN_F11R1_FB20         CAN_F11R1_FB20_Msk                              /*!<Filter bit 20 */
#define CAN_F11R1_FB21_Pos     (21U)                                           
#define CAN_F11R1_FB21_Msk     (0x1UL << CAN_F11R1_FB21_Pos)                    /*!< 0x00200000 */
#define CAN_F11R1_FB21         CAN_F11R1_FB21_Msk                              /*!<Filter bit 21 */
#define CAN_F11R1_FB22_Pos     (22U)                                           
#define CAN_F11R1_FB22_Msk     (0x1UL << CAN_F11R1_FB22_Pos)                    /*!< 0x00400000 */
#define CAN_F11R1_FB22         CAN_F11R1_FB22_Msk                              /*!<Filter bit 22 */
#define CAN_F11R1_FB23_Pos     (23U)                                           
#define CAN_F11R1_FB23_Msk     (0x1UL << CAN_F11R1_FB23_Pos)                    /*!< 0x00800000 */
#define CAN_F11R1_FB23         CAN_F11R1_FB23_Msk                              /*!<Filter bit 23 */
#define CAN_F11R1_FB24_Pos     (24U)                                           
#define CAN_F11R1_FB24_Msk     (0x1UL << CAN_F11R1_FB24_Pos)                    /*!< 0x01000000 */
#define CAN_F11R1_FB24         CAN_F11R1_FB24_Msk                              /*!<Filter bit 24 */
#define CAN_F11R1_FB25_Pos     (25U)                                           
#define CAN_F11R1_FB25_Msk     (0x1UL << CAN_F11R1_FB25_Pos)                    /*!< 0x02000000 */
#define CAN_F11R1_FB25         CAN_F11R1_FB25_Msk                              /*!<Filter bit 25 */
#define CAN_F11R1_FB26_Pos     (26U)                                           
#define CAN_F11R1_FB26_Msk     (0x1UL << CAN_F11R1_FB26_Pos)                    /*!< 0x04000000 */
#define CAN_F11R1_FB26         CAN_F11R1_FB26_Msk                              /*!<Filter bit 26 */
#define CAN_F11R1_FB27_Pos     (27U)                                           
#define CAN_F11R1_FB27_Msk     (0x1UL << CAN_F11R1_FB27_Pos)                    /*!< 0x08000000 */
#define CAN_F11R1_FB27         CAN_F11R1_FB27_Msk                              /*!<Filter bit 27 */
#define CAN_F11R1_FB28_Pos     (28U)                                           
#define CAN_F11R1_FB28_Msk     (0x1UL << CAN_F11R1_FB28_Pos)                    /*!< 0x10000000 */
#define CAN_F11R1_FB28         CAN_F11R1_FB28_Msk                              /*!<Filter bit 28 */
#define CAN_F11R1_FB29_Pos     (29U)                                           
#define CAN_F11R1_FB29_Msk     (0x1UL << CAN_F11R1_FB29_Pos)                    /*!< 0x20000000 */
#define CAN_F11R1_FB29         CAN_F11R1_FB29_Msk                              /*!<Filter bit 29 */
#define CAN_F11R1_FB30_Pos     (30U)                                           
#define CAN_F11R1_FB30_Msk     (0x1UL << CAN_F11R1_FB30_Pos)                    /*!< 0x40000000 */
#define CAN_F11R1_FB30         CAN_F11R1_FB30_Msk                              /*!<Filter bit 30 */
#define CAN_F11R1_FB31_Pos     (31U)                                           
#define CAN_F11R1_FB31_Msk     (0x1UL << CAN_F11R1_FB31_Pos)                    /*!< 0x80000000 */
#define CAN_F11R1_FB31         CAN_F11R1_FB31_Msk                              /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define CAN_F12R1_FB0_Pos      (0U)                                            
#define CAN_F12R1_FB0_Msk      (0x1UL << CAN_F12R1_FB0_Pos)                     /*!< 0x00000001 */
#define CAN_F12R1_FB0          CAN_F12R1_FB0_Msk                               /*!<Filter bit 0 */
#define CAN_F12R1_FB1_Pos      (1U)                                            
#define CAN_F12R1_FB1_Msk      (0x1UL << CAN_F12R1_FB1_Pos)                     /*!< 0x00000002 */
#define CAN_F12R1_FB1          CAN_F12R1_FB1_Msk                               /*!<Filter bit 1 */
#define CAN_F12R1_FB2_Pos      (2U)                                            
#define CAN_F12R1_FB2_Msk      (0x1UL << CAN_F12R1_FB2_Pos)                     /*!< 0x00000004 */
#define CAN_F12R1_FB2          CAN_F12R1_FB2_Msk                               /*!<Filter bit 2 */
#define CAN_F12R1_FB3_Pos      (3U)                                            
#define CAN_F12R1_FB3_Msk      (0x1UL << CAN_F12R1_FB3_Pos)                     /*!< 0x00000008 */
#define CAN_F12R1_FB3          CAN_F12R1_FB3_Msk                               /*!<Filter bit 3 */
#define CAN_F12R1_FB4_Pos      (4U)                                            
#define CAN_F12R1_FB4_Msk      (0x1UL << CAN_F12R1_FB4_Pos)                     /*!< 0x00000010 */
#define CAN_F12R1_FB4          CAN_F12R1_FB4_Msk                               /*!<Filter bit 4 */
#define CAN_F12R1_FB5_Pos      (5U)                                            
#define CAN_F12R1_FB5_Msk      (0x1UL << CAN_F12R1_FB5_Pos)                     /*!< 0x00000020 */
#define CAN_F12R1_FB5          CAN_F12R1_FB5_Msk                               /*!<Filter bit 5 */
#define CAN_F12R1_FB6_Pos      (6U)                                            
#define CAN_F12R1_FB6_Msk      (0x1UL << CAN_F12R1_FB6_Pos)                     /*!< 0x00000040 */
#define CAN_F12R1_FB6          CAN_F12R1_FB6_Msk                               /*!<Filter bit 6 */
#define CAN_F12R1_FB7_Pos      (7U)                                            
#define CAN_F12R1_FB7_Msk      (0x1UL << CAN_F12R1_FB7_Pos)                     /*!< 0x00000080 */
#define CAN_F12R1_FB7          CAN_F12R1_FB7_Msk                               /*!<Filter bit 7 */
#define CAN_F12R1_FB8_Pos      (8U)                                            
#define CAN_F12R1_FB8_Msk      (0x1UL << CAN_F12R1_FB8_Pos)                     /*!< 0x00000100 */
#define CAN_F12R1_FB8          CAN_F12R1_FB8_Msk                               /*!<Filter bit 8 */
#define CAN_F12R1_FB9_Pos      (9U)                                            
#define CAN_F12R1_FB9_Msk      (0x1UL << CAN_F12R1_FB9_Pos)                     /*!< 0x00000200 */
#define CAN_F12R1_FB9          CAN_F12R1_FB9_Msk                               /*!<Filter bit 9 */
#define CAN_F12R1_FB10_Pos     (10U)                                           
#define CAN_F12R1_FB10_Msk     (0x1UL << CAN_F12R1_FB10_Pos)                    /*!< 0x00000400 */
#define CAN_F12R1_FB10         CAN_F12R1_FB10_Msk                              /*!<Filter bit 10 */
#define CAN_F12R1_FB11_Pos     (11U)                                           
#define CAN_F12R1_FB11_Msk     (0x1UL << CAN_F12R1_FB11_Pos)                    /*!< 0x00000800 */
#define CAN_F12R1_FB11         CAN_F12R1_FB11_Msk                              /*!<Filter bit 11 */
#define CAN_F12R1_FB12_Pos     (12U)                                           
#define CAN_F12R1_FB12_Msk     (0x1UL << CAN_F12R1_FB12_Pos)                    /*!< 0x00001000 */
#define CAN_F12R1_FB12         CAN_F12R1_FB12_Msk                              /*!<Filter bit 12 */
#define CAN_F12R1_FB13_Pos     (13U)                                           
#define CAN_F12R1_FB13_Msk     (0x1UL << CAN_F12R1_FB13_Pos)                    /*!< 0x00002000 */
#define CAN_F12R1_FB13         CAN_F12R1_FB13_Msk                              /*!<Filter bit 13 */
#define CAN_F12R1_FB14_Pos     (14U)                                           
#define CAN_F12R1_FB14_Msk     (0x1UL << CAN_F12R1_FB14_Pos)                    /*!< 0x00004000 */
#define CAN_F12R1_FB14         CAN_F12R1_FB14_Msk                              /*!<Filter bit 14 */
#define CAN_F12R1_FB15_Pos     (15U)                                           
#define CAN_F12R1_FB15_Msk     (0x1UL << CAN_F12R1_FB15_Pos)                    /*!< 0x00008000 */
#define CAN_F12R1_FB15         CAN_F12R1_FB15_Msk                              /*!<Filter bit 15 */
#define CAN_F12R1_FB16_Pos     (16U)                                           
#define CAN_F12R1_FB16_Msk     (0x1UL << CAN_F12R1_FB16_Pos)                    /*!< 0x00010000 */
#define CAN_F12R1_FB16         CAN_F12R1_FB16_Msk                              /*!<Filter bit 16 */
#define CAN_F12R1_FB17_Pos     (17U)                                           
#define CAN_F12R1_FB17_Msk     (0x1UL << CAN_F12R1_FB17_Pos)                    /*!< 0x00020000 */
#define CAN_F12R1_FB17         CAN_F12R1_FB17_Msk                              /*!<Filter bit 17 */
#define CAN_F12R1_FB18_Pos     (18U)                                           
#define CAN_F12R1_FB18_Msk     (0x1UL << CAN_F12R1_FB18_Pos)                    /*!< 0x00040000 */
#define CAN_F12R1_FB18         CAN_F12R1_FB18_Msk                              /*!<Filter bit 18 */
#define CAN_F12R1_FB19_Pos     (19U)                                           
#define CAN_F12R1_FB19_Msk     (0x1UL << CAN_F12R1_FB19_Pos)                    /*!< 0x00080000 */
#define CAN_F12R1_FB19         CAN_F12R1_FB19_Msk                              /*!<Filter bit 19 */
#define CAN_F12R1_FB20_Pos     (20U)                                           
#define CAN_F12R1_FB20_Msk     (0x1UL << CAN_F12R1_FB20_Pos)                    /*!< 0x00100000 */
#define CAN_F12R1_FB20         CAN_F12R1_FB20_Msk                              /*!<Filter bit 20 */
#define CAN_F12R1_FB21_Pos     (21U)                                           
#define CAN_F12R1_FB21_Msk     (0x1UL << CAN_F12R1_FB21_Pos)                    /*!< 0x00200000 */
#define CAN_F12R1_FB21         CAN_F12R1_FB21_Msk                              /*!<Filter bit 21 */
#define CAN_F12R1_FB22_Pos     (22U)                                           
#define CAN_F12R1_FB22_Msk     (0x1UL << CAN_F12R1_FB22_Pos)                    /*!< 0x00400000 */
#define CAN_F12R1_FB22         CAN_F12R1_FB22_Msk                              /*!<Filter bit 22 */
#define CAN_F12R1_FB23_Pos     (23U)                                           
#define CAN_F12R1_FB23_Msk     (0x1UL << CAN_F12R1_FB23_Pos)                    /*!< 0x00800000 */
#define CAN_F12R1_FB23         CAN_F12R1_FB23_Msk                              /*!<Filter bit 23 */
#define CAN_F12R1_FB24_Pos     (24U)                                           
#define CAN_F12R1_FB24_Msk     (0x1UL << CAN_F12R1_FB24_Pos)                    /*!< 0x01000000 */
#define CAN_F12R1_FB24         CAN_F12R1_FB24_Msk                              /*!<Filter bit 24 */
#define CAN_F12R1_FB25_Pos     (25U)                                           
#define CAN_F12R1_FB25_Msk     (0x1UL << CAN_F12R1_FB25_Pos)                    /*!< 0x02000000 */
#define CAN_F12R1_FB25         CAN_F12R1_FB25_Msk                              /*!<Filter bit 25 */
#define CAN_F12R1_FB26_Pos     (26U)                                           
#define CAN_F12R1_FB26_Msk     (0x1UL << CAN_F12R1_FB26_Pos)                    /*!< 0x04000000 */
#define CAN_F12R1_FB26         CAN_F12R1_FB26_Msk                              /*!<Filter bit 26 */
#define CAN_F12R1_FB27_Pos     (27U)                                           
#define CAN_F12R1_FB27_Msk     (0x1UL << CAN_F12R1_FB27_Pos)                    /*!< 0x08000000 */
#define CAN_F12R1_FB27         CAN_F12R1_FB27_Msk                              /*!<Filter bit 27 */
#define CAN_F12R1_FB28_Pos     (28U)                                           
#define CAN_F12R1_FB28_Msk     (0x1UL << CAN_F12R1_FB28_Pos)                    /*!< 0x10000000 */
#define CAN_F12R1_FB28         CAN_F12R1_FB28_Msk                              /*!<Filter bit 28 */
#define CAN_F12R1_FB29_Pos     (29U)                                           
#define CAN_F12R1_FB29_Msk     (0x1UL << CAN_F12R1_FB29_Pos)                    /*!< 0x20000000 */
#define CAN_F12R1_FB29         CAN_F12R1_FB29_Msk                              /*!<Filter bit 29 */
#define CAN_F12R1_FB30_Pos     (30U)                                           
#define CAN_F12R1_FB30_Msk     (0x1UL << CAN_F12R1_FB30_Pos)                    /*!< 0x40000000 */
#define CAN_F12R1_FB30         CAN_F12R1_FB30_Msk                              /*!<Filter bit 30 */
#define CAN_F12R1_FB31_Pos     (31U)                                           
#define CAN_F12R1_FB31_Msk     (0x1UL << CAN_F12R1_FB31_Pos)                    /*!< 0x80000000 */
#define CAN_F12R1_FB31         CAN_F12R1_FB31_Msk                              /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define CAN_F13R1_FB0_Pos      (0U)                                            
#define CAN_F13R1_FB0_Msk      (0x1UL << CAN_F13R1_FB0_Pos)                     /*!< 0x00000001 */
#define CAN_F13R1_FB0          CAN_F13R1_FB0_Msk                               /*!<Filter bit 0 */
#define CAN_F13R1_FB1_Pos      (1U)                                            
#define CAN_F13R1_FB1_Msk      (0x1UL << CAN_F13R1_FB1_Pos)                     /*!< 0x00000002 */
#define CAN_F13R1_FB1          CAN_F13R1_FB1_Msk                               /*!<Filter bit 1 */
#define CAN_F13R1_FB2_Pos      (2U)                                            
#define CAN_F13R1_FB2_Msk      (0x1UL << CAN_F13R1_FB2_Pos)                     /*!< 0x00000004 */
#define CAN_F13R1_FB2          CAN_F13R1_FB2_Msk                               /*!<Filter bit 2 */
#define CAN_F13R1_FB3_Pos      (3U)                                            
#define CAN_F13R1_FB3_Msk      (0x1UL << CAN_F13R1_FB3_Pos)                     /*!< 0x00000008 */
#define CAN_F13R1_FB3          CAN_F13R1_FB3_Msk                               /*!<Filter bit 3 */
#define CAN_F13R1_FB4_Pos      (4U)                                            
#define CAN_F13R1_FB4_Msk      (0x1UL << CAN_F13R1_FB4_Pos)                     /*!< 0x00000010 */
#define CAN_F13R1_FB4          CAN_F13R1_FB4_Msk                               /*!<Filter bit 4 */
#define CAN_F13R1_FB5_Pos      (5U)                                            
#define CAN_F13R1_FB5_Msk      (0x1UL << CAN_F13R1_FB5_Pos)                     /*!< 0x00000020 */
#define CAN_F13R1_FB5          CAN_F13R1_FB5_Msk                               /*!<Filter bit 5 */
#define CAN_F13R1_FB6_Pos      (6U)                                            
#define CAN_F13R1_FB6_Msk      (0x1UL << CAN_F13R1_FB6_Pos)                     /*!< 0x00000040 */
#define CAN_F13R1_FB6          CAN_F13R1_FB6_Msk                               /*!<Filter bit 6 */
#define CAN_F13R1_FB7_Pos      (7U)                                            
#define CAN_F13R1_FB7_Msk      (0x1UL << CAN_F13R1_FB7_Pos)                     /*!< 0x00000080 */
#define CAN_F13R1_FB7          CAN_F13R1_FB7_Msk                               /*!<Filter bit 7 */
#define CAN_F13R1_FB8_Pos      (8U)                                            
#define CAN_F13R1_FB8_Msk      (0x1UL << CAN_F13R1_FB8_Pos)                     /*!< 0x00000100 */
#define CAN_F13R1_FB8          CAN_F13R1_FB8_Msk                               /*!<Filter bit 8 */
#define CAN_F13R1_FB9_Pos      (9U)                                            
#define CAN_F13R1_FB9_Msk      (0x1UL << CAN_F13R1_FB9_Pos)                     /*!< 0x00000200 */
#define CAN_F13R1_FB9          CAN_F13R1_FB9_Msk                               /*!<Filter bit 9 */
#define CAN_F13R1_FB10_Pos     (10U)                                           
#define CAN_F13R1_FB10_Msk     (0x1UL << CAN_F13R1_FB10_Pos)                    /*!< 0x00000400 */
#define CAN_F13R1_FB10         CAN_F13R1_FB10_Msk                              /*!<Filter bit 10 */
#define CAN_F13R1_FB11_Pos     (11U)                                           
#define CAN_F13R1_FB11_Msk     (0x1UL << CAN_F13R1_FB11_Pos)                    /*!< 0x00000800 */
#define CAN_F13R1_FB11         CAN_F13R1_FB11_Msk                              /*!<Filter bit 11 */
#define CAN_F13R1_FB12_Pos     (12U)                                           
#define CAN_F13R1_FB12_Msk     (0x1UL << CAN_F13R1_FB12_Pos)                    /*!< 0x00001000 */
#define CAN_F13R1_FB12         CAN_F13R1_FB12_Msk                              /*!<Filter bit 12 */
#define CAN_F13R1_FB13_Pos     (13U)                                           
#define CAN_F13R1_FB13_Msk     (0x1UL << CAN_F13R1_FB13_Pos)                    /*!< 0x00002000 */
#define CAN_F13R1_FB13         CAN_F13R1_FB13_Msk                              /*!<Filter bit 13 */
#define CAN_F13R1_FB14_Pos     (14U)                                           
#define CAN_F13R1_FB14_Msk     (0x1UL << CAN_F13R1_FB14_Pos)                    /*!< 0x00004000 */
#define CAN_F13R1_FB14         CAN_F13R1_FB14_Msk                              /*!<Filter bit 14 */
#define CAN_F13R1_FB15_Pos     (15U)                                           
#define CAN_F13R1_FB15_Msk     (0x1UL << CAN_F13R1_FB15_Pos)                    /*!< 0x00008000 */
#define CAN_F13R1_FB15         CAN_F13R1_FB15_Msk                              /*!<Filter bit 15 */
#define CAN_F13R1_FB16_Pos     (16U)                                           
#define CAN_F13R1_FB16_Msk     (0x1UL << CAN_F13R1_FB16_Pos)                    /*!< 0x00010000 */
#define CAN_F13R1_FB16         CAN_F13R1_FB16_Msk                              /*!<Filter bit 16 */
#define CAN_F13R1_FB17_Pos     (17U)                                           
#define CAN_F13R1_FB17_Msk     (0x1UL << CAN_F13R1_FB17_Pos)                    /*!< 0x00020000 */
#define CAN_F13R1_FB17         CAN_F13R1_FB17_Msk                              /*!<Filter bit 17 */
#define CAN_F13R1_FB18_Pos     (18U)                                           
#define CAN_F13R1_FB18_Msk     (0x1UL << CAN_F13R1_FB18_Pos)                    /*!< 0x00040000 */
#define CAN_F13R1_FB18         CAN_F13R1_FB18_Msk                              /*!<Filter bit 18 */
#define CAN_F13R1_FB19_Pos     (19U)                                           
#define CAN_F13R1_FB19_Msk     (0x1UL << CAN_F13R1_FB19_Pos)                    /*!< 0x00080000 */
#define CAN_F13R1_FB19         CAN_F13R1_FB19_Msk                              /*!<Filter bit 19 */
#define CAN_F13R1_FB20_Pos     (20U)                                           
#define CAN_F13R1_FB20_Msk     (0x1UL << CAN_F13R1_FB20_Pos)                    /*!< 0x00100000 */
#define CAN_F13R1_FB20         CAN_F13R1_FB20_Msk                              /*!<Filter bit 20 */
#define CAN_F13R1_FB21_Pos     (21U)                                           
#define CAN_F13R1_FB21_Msk     (0x1UL << CAN_F13R1_FB21_Pos)                    /*!< 0x00200000 */
#define CAN_F13R1_FB21         CAN_F13R1_FB21_Msk                              /*!<Filter bit 21 */
#define CAN_F13R1_FB22_Pos     (22U)                                           
#define CAN_F13R1_FB22_Msk     (0x1UL << CAN_F13R1_FB22_Pos)                    /*!< 0x00400000 */
#define CAN_F13R1_FB22         CAN_F13R1_FB22_Msk                              /*!<Filter bit 22 */
#define CAN_F13R1_FB23_Pos     (23U)                                           
#define CAN_F13R1_FB23_Msk     (0x1UL << CAN_F13R1_FB23_Pos)                    /*!< 0x00800000 */
#define CAN_F13R1_FB23         CAN_F13R1_FB23_Msk                              /*!<Filter bit 23 */
#define CAN_F13R1_FB24_Pos     (24U)                                           
#define CAN_F13R1_FB24_Msk     (0x1UL << CAN_F13R1_FB24_Pos)                    /*!< 0x01000000 */
#define CAN_F13R1_FB24         CAN_F13R1_FB24_Msk                              /*!<Filter bit 24 */
#define CAN_F13R1_FB25_Pos     (25U)                                           
#define CAN_F13R1_FB25_Msk     (0x1UL << CAN_F13R1_FB25_Pos)                    /*!< 0x02000000 */
#define CAN_F13R1_FB25         CAN_F13R1_FB25_Msk                              /*!<Filter bit 25 */
#define CAN_F13R1_FB26_Pos     (26U)                                           
#define CAN_F13R1_FB26_Msk     (0x1UL << CAN_F13R1_FB26_Pos)                    /*!< 0x04000000 */
#define CAN_F13R1_FB26         CAN_F13R1_FB26_Msk                              /*!<Filter bit 26 */
#define CAN_F13R1_FB27_Pos     (27U)                                           
#define CAN_F13R1_FB27_Msk     (0x1UL << CAN_F13R1_FB27_Pos)                    /*!< 0x08000000 */
#define CAN_F13R1_FB27         CAN_F13R1_FB27_Msk                              /*!<Filter bit 27 */
#define CAN_F13R1_FB28_Pos     (28U)                                           
#define CAN_F13R1_FB28_Msk     (0x1UL << CAN_F13R1_FB28_Pos)                    /*!< 0x10000000 */
#define CAN_F13R1_FB28         CAN_F13R1_FB28_Msk                              /*!<Filter bit 28 */
#define CAN_F13R1_FB29_Pos     (29U)                                           
#define CAN_F13R1_FB29_Msk     (0x1UL << CAN_F13R1_FB29_Pos)                    /*!< 0x20000000 */
#define CAN_F13R1_FB29         CAN_F13R1_FB29_Msk                              /*!<Filter bit 29 */
#define CAN_F13R1_FB30_Pos     (30U)                                           
#define CAN_F13R1_FB30_Msk     (0x1UL << CAN_F13R1_FB30_Pos)                    /*!< 0x40000000 */
#define CAN_F13R1_FB30         CAN_F13R1_FB30_Msk                              /*!<Filter bit 30 */
#define CAN_F13R1_FB31_Pos     (31U)                                           
#define CAN_F13R1_FB31_Msk     (0x1UL << CAN_F13R1_FB31_Pos)                    /*!< 0x80000000 */
#define CAN_F13R1_FB31         CAN_F13R1_FB31_Msk                              /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define CAN_F0R2_FB0_Pos       (0U)                                            
#define CAN_F0R2_FB0_Msk       (0x1UL << CAN_F0R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F0R2_FB0           CAN_F0R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F0R2_FB1_Pos       (1U)                                            
#define CAN_F0R2_FB1_Msk       (0x1UL << CAN_F0R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F0R2_FB1           CAN_F0R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F0R2_FB2_Pos       (2U)                                            
#define CAN_F0R2_FB2_Msk       (0x1UL << CAN_F0R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F0R2_FB2           CAN_F0R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F0R2_FB3_Pos       (3U)                                            
#define CAN_F0R2_FB3_Msk       (0x1UL << CAN_F0R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F0R2_FB3           CAN_F0R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F0R2_FB4_Pos       (4U)                                            
#define CAN_F0R2_FB4_Msk       (0x1UL << CAN_F0R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F0R2_FB4           CAN_F0R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F0R2_FB5_Pos       (5U)                                            
#define CAN_F0R2_FB5_Msk       (0x1UL << CAN_F0R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F0R2_FB5           CAN_F0R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F0R2_FB6_Pos       (6U)                                            
#define CAN_F0R2_FB6_Msk       (0x1UL << CAN_F0R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F0R2_FB6           CAN_F0R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F0R2_FB7_Pos       (7U)                                            
#define CAN_F0R2_FB7_Msk       (0x1UL << CAN_F0R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F0R2_FB7           CAN_F0R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F0R2_FB8_Pos       (8U)                                            
#define CAN_F0R2_FB8_Msk       (0x1UL << CAN_F0R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F0R2_FB8           CAN_F0R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F0R2_FB9_Pos       (9U)                                            
#define CAN_F0R2_FB9_Msk       (0x1UL << CAN_F0R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F0R2_FB9           CAN_F0R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F0R2_FB10_Pos      (10U)                                           
#define CAN_F0R2_FB10_Msk      (0x1UL << CAN_F0R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F0R2_FB10          CAN_F0R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F0R2_FB11_Pos      (11U)                                           
#define CAN_F0R2_FB11_Msk      (0x1UL << CAN_F0R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F0R2_FB11          CAN_F0R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F0R2_FB12_Pos      (12U)                                           
#define CAN_F0R2_FB12_Msk      (0x1UL << CAN_F0R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F0R2_FB12          CAN_F0R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F0R2_FB13_Pos      (13U)                                           
#define CAN_F0R2_FB13_Msk      (0x1UL << CAN_F0R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F0R2_FB13          CAN_F0R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F0R2_FB14_Pos      (14U)                                           
#define CAN_F0R2_FB14_Msk      (0x1UL << CAN_F0R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F0R2_FB14          CAN_F0R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F0R2_FB15_Pos      (15U)                                           
#define CAN_F0R2_FB15_Msk      (0x1UL << CAN_F0R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F0R2_FB15          CAN_F0R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F0R2_FB16_Pos      (16U)                                           
#define CAN_F0R2_FB16_Msk      (0x1UL << CAN_F0R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F0R2_FB16          CAN_F0R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F0R2_FB17_Pos      (17U)                                           
#define CAN_F0R2_FB17_Msk      (0x1UL << CAN_F0R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F0R2_FB17          CAN_F0R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F0R2_FB18_Pos      (18U)                                           
#define CAN_F0R2_FB18_Msk      (0x1UL << CAN_F0R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F0R2_FB18          CAN_F0R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F0R2_FB19_Pos      (19U)                                           
#define CAN_F0R2_FB19_Msk      (0x1UL << CAN_F0R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F0R2_FB19          CAN_F0R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F0R2_FB20_Pos      (20U)                                           
#define CAN_F0R2_FB20_Msk      (0x1UL << CAN_F0R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F0R2_FB20          CAN_F0R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F0R2_FB21_Pos      (21U)                                           
#define CAN_F0R2_FB21_Msk      (0x1UL << CAN_F0R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F0R2_FB21          CAN_F0R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F0R2_FB22_Pos      (22U)                                           
#define CAN_F0R2_FB22_Msk      (0x1UL << CAN_F0R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F0R2_FB22          CAN_F0R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F0R2_FB23_Pos      (23U)                                           
#define CAN_F0R2_FB23_Msk      (0x1UL << CAN_F0R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F0R2_FB23          CAN_F0R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F0R2_FB24_Pos      (24U)                                           
#define CAN_F0R2_FB24_Msk      (0x1UL << CAN_F0R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F0R2_FB24          CAN_F0R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F0R2_FB25_Pos      (25U)                                           
#define CAN_F0R2_FB25_Msk      (0x1UL << CAN_F0R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F0R2_FB25          CAN_F0R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F0R2_FB26_Pos      (26U)                                           
#define CAN_F0R2_FB26_Msk      (0x1UL << CAN_F0R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F0R2_FB26          CAN_F0R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F0R2_FB27_Pos      (27U)                                           
#define CAN_F0R2_FB27_Msk      (0x1UL << CAN_F0R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F0R2_FB27          CAN_F0R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F0R2_FB28_Pos      (28U)                                           
#define CAN_F0R2_FB28_Msk      (0x1UL << CAN_F0R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F0R2_FB28          CAN_F0R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F0R2_FB29_Pos      (29U)                                           
#define CAN_F0R2_FB29_Msk      (0x1UL << CAN_F0R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F0R2_FB29          CAN_F0R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F0R2_FB30_Pos      (30U)                                           
#define CAN_F0R2_FB30_Msk      (0x1UL << CAN_F0R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F0R2_FB30          CAN_F0R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F0R2_FB31_Pos      (31U)                                           
#define CAN_F0R2_FB31_Msk      (0x1UL << CAN_F0R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F0R2_FB31          CAN_F0R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define CAN_F1R2_FB0_Pos       (0U)                                            
#define CAN_F1R2_FB0_Msk       (0x1UL << CAN_F1R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F1R2_FB0           CAN_F1R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F1R2_FB1_Pos       (1U)                                            
#define CAN_F1R2_FB1_Msk       (0x1UL << CAN_F1R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F1R2_FB1           CAN_F1R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F1R2_FB2_Pos       (2U)                                            
#define CAN_F1R2_FB2_Msk       (0x1UL << CAN_F1R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F1R2_FB2           CAN_F1R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F1R2_FB3_Pos       (3U)                                            
#define CAN_F1R2_FB3_Msk       (0x1UL << CAN_F1R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F1R2_FB3           CAN_F1R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F1R2_FB4_Pos       (4U)                                            
#define CAN_F1R2_FB4_Msk       (0x1UL << CAN_F1R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F1R2_FB4           CAN_F1R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F1R2_FB5_Pos       (5U)                                            
#define CAN_F1R2_FB5_Msk       (0x1UL << CAN_F1R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F1R2_FB5           CAN_F1R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F1R2_FB6_Pos       (6U)                                            
#define CAN_F1R2_FB6_Msk       (0x1UL << CAN_F1R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F1R2_FB6           CAN_F1R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F1R2_FB7_Pos       (7U)                                            
#define CAN_F1R2_FB7_Msk       (0x1UL << CAN_F1R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F1R2_FB7           CAN_F1R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F1R2_FB8_Pos       (8U)                                            
#define CAN_F1R2_FB8_Msk       (0x1UL << CAN_F1R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F1R2_FB8           CAN_F1R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F1R2_FB9_Pos       (9U)                                            
#define CAN_F1R2_FB9_Msk       (0x1UL << CAN_F1R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F1R2_FB9           CAN_F1R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F1R2_FB10_Pos      (10U)                                           
#define CAN_F1R2_FB10_Msk      (0x1UL << CAN_F1R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F1R2_FB10          CAN_F1R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F1R2_FB11_Pos      (11U)                                           
#define CAN_F1R2_FB11_Msk      (0x1UL << CAN_F1R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F1R2_FB11          CAN_F1R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F1R2_FB12_Pos      (12U)                                           
#define CAN_F1R2_FB12_Msk      (0x1UL << CAN_F1R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F1R2_FB12          CAN_F1R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F1R2_FB13_Pos      (13U)                                           
#define CAN_F1R2_FB13_Msk      (0x1UL << CAN_F1R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F1R2_FB13          CAN_F1R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F1R2_FB14_Pos      (14U)                                           
#define CAN_F1R2_FB14_Msk      (0x1UL << CAN_F1R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F1R2_FB14          CAN_F1R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F1R2_FB15_Pos      (15U)                                           
#define CAN_F1R2_FB15_Msk      (0x1UL << CAN_F1R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F1R2_FB15          CAN_F1R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F1R2_FB16_Pos      (16U)                                           
#define CAN_F1R2_FB16_Msk      (0x1UL << CAN_F1R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F1R2_FB16          CAN_F1R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F1R2_FB17_Pos      (17U)                                           
#define CAN_F1R2_FB17_Msk      (0x1UL << CAN_F1R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F1R2_FB17          CAN_F1R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F1R2_FB18_Pos      (18U)                                           
#define CAN_F1R2_FB18_Msk      (0x1UL << CAN_F1R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F1R2_FB18          CAN_F1R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F1R2_FB19_Pos      (19U)                                           
#define CAN_F1R2_FB19_Msk      (0x1UL << CAN_F1R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F1R2_FB19          CAN_F1R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F1R2_FB20_Pos      (20U)                                           
#define CAN_F1R2_FB20_Msk      (0x1UL << CAN_F1R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F1R2_FB20          CAN_F1R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F1R2_FB21_Pos      (21U)                                           
#define CAN_F1R2_FB21_Msk      (0x1UL << CAN_F1R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F1R2_FB21          CAN_F1R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F1R2_FB22_Pos      (22U)                                           
#define CAN_F1R2_FB22_Msk      (0x1UL << CAN_F1R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F1R2_FB22          CAN_F1R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F1R2_FB23_Pos      (23U)                                           
#define CAN_F1R2_FB23_Msk      (0x1UL << CAN_F1R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F1R2_FB23          CAN_F1R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F1R2_FB24_Pos      (24U)                                           
#define CAN_F1R2_FB24_Msk      (0x1UL << CAN_F1R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F1R2_FB24          CAN_F1R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F1R2_FB25_Pos      (25U)                                           
#define CAN_F1R2_FB25_Msk      (0x1UL << CAN_F1R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F1R2_FB25          CAN_F1R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F1R2_FB26_Pos      (26U)                                           
#define CAN_F1R2_FB26_Msk      (0x1UL << CAN_F1R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F1R2_FB26          CAN_F1R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F1R2_FB27_Pos      (27U)                                           
#define CAN_F1R2_FB27_Msk      (0x1UL << CAN_F1R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F1R2_FB27          CAN_F1R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F1R2_FB28_Pos      (28U)                                           
#define CAN_F1R2_FB28_Msk      (0x1UL << CAN_F1R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F1R2_FB28          CAN_F1R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F1R2_FB29_Pos      (29U)                                           
#define CAN_F1R2_FB29_Msk      (0x1UL << CAN_F1R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F1R2_FB29          CAN_F1R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F1R2_FB30_Pos      (30U)                                           
#define CAN_F1R2_FB30_Msk      (0x1UL << CAN_F1R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F1R2_FB30          CAN_F1R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F1R2_FB31_Pos      (31U)                                           
#define CAN_F1R2_FB31_Msk      (0x1UL << CAN_F1R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F1R2_FB31          CAN_F1R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define CAN_F2R2_FB0_Pos       (0U)                                            
#define CAN_F2R2_FB0_Msk       (0x1UL << CAN_F2R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F2R2_FB0           CAN_F2R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F2R2_FB1_Pos       (1U)                                            
#define CAN_F2R2_FB1_Msk       (0x1UL << CAN_F2R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F2R2_FB1           CAN_F2R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F2R2_FB2_Pos       (2U)                                            
#define CAN_F2R2_FB2_Msk       (0x1UL << CAN_F2R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F2R2_FB2           CAN_F2R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F2R2_FB3_Pos       (3U)                                            
#define CAN_F2R2_FB3_Msk       (0x1UL << CAN_F2R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F2R2_FB3           CAN_F2R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F2R2_FB4_Pos       (4U)                                            
#define CAN_F2R2_FB4_Msk       (0x1UL << CAN_F2R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F2R2_FB4           CAN_F2R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F2R2_FB5_Pos       (5U)                                            
#define CAN_F2R2_FB5_Msk       (0x1UL << CAN_F2R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F2R2_FB5           CAN_F2R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F2R2_FB6_Pos       (6U)                                            
#define CAN_F2R2_FB6_Msk       (0x1UL << CAN_F2R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F2R2_FB6           CAN_F2R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F2R2_FB7_Pos       (7U)                                            
#define CAN_F2R2_FB7_Msk       (0x1UL << CAN_F2R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F2R2_FB7           CAN_F2R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F2R2_FB8_Pos       (8U)                                            
#define CAN_F2R2_FB8_Msk       (0x1UL << CAN_F2R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F2R2_FB8           CAN_F2R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F2R2_FB9_Pos       (9U)                                            
#define CAN_F2R2_FB9_Msk       (0x1UL << CAN_F2R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F2R2_FB9           CAN_F2R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F2R2_FB10_Pos      (10U)                                           
#define CAN_F2R2_FB10_Msk      (0x1UL << CAN_F2R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F2R2_FB10          CAN_F2R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F2R2_FB11_Pos      (11U)                                           
#define CAN_F2R2_FB11_Msk      (0x1UL << CAN_F2R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F2R2_FB11          CAN_F2R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F2R2_FB12_Pos      (12U)                                           
#define CAN_F2R2_FB12_Msk      (0x1UL << CAN_F2R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F2R2_FB12          CAN_F2R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F2R2_FB13_Pos      (13U)                                           
#define CAN_F2R2_FB13_Msk      (0x1UL << CAN_F2R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F2R2_FB13          CAN_F2R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F2R2_FB14_Pos      (14U)                                           
#define CAN_F2R2_FB14_Msk      (0x1UL << CAN_F2R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F2R2_FB14          CAN_F2R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F2R2_FB15_Pos      (15U)                                           
#define CAN_F2R2_FB15_Msk      (0x1UL << CAN_F2R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F2R2_FB15          CAN_F2R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F2R2_FB16_Pos      (16U)                                           
#define CAN_F2R2_FB16_Msk      (0x1UL << CAN_F2R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F2R2_FB16          CAN_F2R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F2R2_FB17_Pos      (17U)                                           
#define CAN_F2R2_FB17_Msk      (0x1UL << CAN_F2R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F2R2_FB17          CAN_F2R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F2R2_FB18_Pos      (18U)                                           
#define CAN_F2R2_FB18_Msk      (0x1UL << CAN_F2R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F2R2_FB18          CAN_F2R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F2R2_FB19_Pos      (19U)                                           
#define CAN_F2R2_FB19_Msk      (0x1UL << CAN_F2R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F2R2_FB19          CAN_F2R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F2R2_FB20_Pos      (20U)                                           
#define CAN_F2R2_FB20_Msk      (0x1UL << CAN_F2R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F2R2_FB20          CAN_F2R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F2R2_FB21_Pos      (21U)                                           
#define CAN_F2R2_FB21_Msk      (0x1UL << CAN_F2R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F2R2_FB21          CAN_F2R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F2R2_FB22_Pos      (22U)                                           
#define CAN_F2R2_FB22_Msk      (0x1UL << CAN_F2R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F2R2_FB22          CAN_F2R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F2R2_FB23_Pos      (23U)                                           
#define CAN_F2R2_FB23_Msk      (0x1UL << CAN_F2R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F2R2_FB23          CAN_F2R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F2R2_FB24_Pos      (24U)                                           
#define CAN_F2R2_FB24_Msk      (0x1UL << CAN_F2R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F2R2_FB24          CAN_F2R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F2R2_FB25_Pos      (25U)                                           
#define CAN_F2R2_FB25_Msk      (0x1UL << CAN_F2R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F2R2_FB25          CAN_F2R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F2R2_FB26_Pos      (26U)                                           
#define CAN_F2R2_FB26_Msk      (0x1UL << CAN_F2R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F2R2_FB26          CAN_F2R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F2R2_FB27_Pos      (27U)                                           
#define CAN_F2R2_FB27_Msk      (0x1UL << CAN_F2R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F2R2_FB27          CAN_F2R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F2R2_FB28_Pos      (28U)                                           
#define CAN_F2R2_FB28_Msk      (0x1UL << CAN_F2R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F2R2_FB28          CAN_F2R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F2R2_FB29_Pos      (29U)                                           
#define CAN_F2R2_FB29_Msk      (0x1UL << CAN_F2R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F2R2_FB29          CAN_F2R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F2R2_FB30_Pos      (30U)                                           
#define CAN_F2R2_FB30_Msk      (0x1UL << CAN_F2R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F2R2_FB30          CAN_F2R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F2R2_FB31_Pos      (31U)                                           
#define CAN_F2R2_FB31_Msk      (0x1UL << CAN_F2R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F2R2_FB31          CAN_F2R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define CAN_F3R2_FB0_Pos       (0U)                                            
#define CAN_F3R2_FB0_Msk       (0x1UL << CAN_F3R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F3R2_FB0           CAN_F3R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F3R2_FB1_Pos       (1U)                                            
#define CAN_F3R2_FB1_Msk       (0x1UL << CAN_F3R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F3R2_FB1           CAN_F3R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F3R2_FB2_Pos       (2U)                                            
#define CAN_F3R2_FB2_Msk       (0x1UL << CAN_F3R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F3R2_FB2           CAN_F3R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F3R2_FB3_Pos       (3U)                                            
#define CAN_F3R2_FB3_Msk       (0x1UL << CAN_F3R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F3R2_FB3           CAN_F3R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F3R2_FB4_Pos       (4U)                                            
#define CAN_F3R2_FB4_Msk       (0x1UL << CAN_F3R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F3R2_FB4           CAN_F3R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F3R2_FB5_Pos       (5U)                                            
#define CAN_F3R2_FB5_Msk       (0x1UL << CAN_F3R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F3R2_FB5           CAN_F3R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F3R2_FB6_Pos       (6U)                                            
#define CAN_F3R2_FB6_Msk       (0x1UL << CAN_F3R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F3R2_FB6           CAN_F3R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F3R2_FB7_Pos       (7U)                                            
#define CAN_F3R2_FB7_Msk       (0x1UL << CAN_F3R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F3R2_FB7           CAN_F3R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F3R2_FB8_Pos       (8U)                                            
#define CAN_F3R2_FB8_Msk       (0x1UL << CAN_F3R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F3R2_FB8           CAN_F3R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F3R2_FB9_Pos       (9U)                                            
#define CAN_F3R2_FB9_Msk       (0x1UL << CAN_F3R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F3R2_FB9           CAN_F3R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F3R2_FB10_Pos      (10U)                                           
#define CAN_F3R2_FB10_Msk      (0x1UL << CAN_F3R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F3R2_FB10          CAN_F3R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F3R2_FB11_Pos      (11U)                                           
#define CAN_F3R2_FB11_Msk      (0x1UL << CAN_F3R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F3R2_FB11          CAN_F3R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F3R2_FB12_Pos      (12U)                                           
#define CAN_F3R2_FB12_Msk      (0x1UL << CAN_F3R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F3R2_FB12          CAN_F3R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F3R2_FB13_Pos      (13U)                                           
#define CAN_F3R2_FB13_Msk      (0x1UL << CAN_F3R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F3R2_FB13          CAN_F3R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F3R2_FB14_Pos      (14U)                                           
#define CAN_F3R2_FB14_Msk      (0x1UL << CAN_F3R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F3R2_FB14          CAN_F3R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F3R2_FB15_Pos      (15U)                                           
#define CAN_F3R2_FB15_Msk      (0x1UL << CAN_F3R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F3R2_FB15          CAN_F3R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F3R2_FB16_Pos      (16U)                                           
#define CAN_F3R2_FB16_Msk      (0x1UL << CAN_F3R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F3R2_FB16          CAN_F3R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F3R2_FB17_Pos      (17U)                                           
#define CAN_F3R2_FB17_Msk      (0x1UL << CAN_F3R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F3R2_FB17          CAN_F3R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F3R2_FB18_Pos      (18U)                                           
#define CAN_F3R2_FB18_Msk      (0x1UL << CAN_F3R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F3R2_FB18          CAN_F3R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F3R2_FB19_Pos      (19U)                                           
#define CAN_F3R2_FB19_Msk      (0x1UL << CAN_F3R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F3R2_FB19          CAN_F3R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F3R2_FB20_Pos      (20U)                                           
#define CAN_F3R2_FB20_Msk      (0x1UL << CAN_F3R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F3R2_FB20          CAN_F3R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F3R2_FB21_Pos      (21U)                                           
#define CAN_F3R2_FB21_Msk      (0x1UL << CAN_F3R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F3R2_FB21          CAN_F3R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F3R2_FB22_Pos      (22U)                                           
#define CAN_F3R2_FB22_Msk      (0x1UL << CAN_F3R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F3R2_FB22          CAN_F3R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F3R2_FB23_Pos      (23U)                                           
#define CAN_F3R2_FB23_Msk      (0x1UL << CAN_F3R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F3R2_FB23          CAN_F3R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F3R2_FB24_Pos      (24U)                                           
#define CAN_F3R2_FB24_Msk      (0x1UL << CAN_F3R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F3R2_FB24          CAN_F3R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F3R2_FB25_Pos      (25U)                                           
#define CAN_F3R2_FB25_Msk      (0x1UL << CAN_F3R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F3R2_FB25          CAN_F3R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F3R2_FB26_Pos      (26U)                                           
#define CAN_F3R2_FB26_Msk      (0x1UL << CAN_F3R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F3R2_FB26          CAN_F3R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F3R2_FB27_Pos      (27U)                                           
#define CAN_F3R2_FB27_Msk      (0x1UL << CAN_F3R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F3R2_FB27          CAN_F3R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F3R2_FB28_Pos      (28U)                                           
#define CAN_F3R2_FB28_Msk      (0x1UL << CAN_F3R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F3R2_FB28          CAN_F3R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F3R2_FB29_Pos      (29U)                                           
#define CAN_F3R2_FB29_Msk      (0x1UL << CAN_F3R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F3R2_FB29          CAN_F3R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F3R2_FB30_Pos      (30U)                                           
#define CAN_F3R2_FB30_Msk      (0x1UL << CAN_F3R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F3R2_FB30          CAN_F3R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F3R2_FB31_Pos      (31U)                                           
#define CAN_F3R2_FB31_Msk      (0x1UL << CAN_F3R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F3R2_FB31          CAN_F3R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define CAN_F4R2_FB0_Pos       (0U)                                            
#define CAN_F4R2_FB0_Msk       (0x1UL << CAN_F4R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F4R2_FB0           CAN_F4R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F4R2_FB1_Pos       (1U)                                            
#define CAN_F4R2_FB1_Msk       (0x1UL << CAN_F4R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F4R2_FB1           CAN_F4R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F4R2_FB2_Pos       (2U)                                            
#define CAN_F4R2_FB2_Msk       (0x1UL << CAN_F4R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F4R2_FB2           CAN_F4R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F4R2_FB3_Pos       (3U)                                            
#define CAN_F4R2_FB3_Msk       (0x1UL << CAN_F4R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F4R2_FB3           CAN_F4R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F4R2_FB4_Pos       (4U)                                            
#define CAN_F4R2_FB4_Msk       (0x1UL << CAN_F4R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F4R2_FB4           CAN_F4R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F4R2_FB5_Pos       (5U)                                            
#define CAN_F4R2_FB5_Msk       (0x1UL << CAN_F4R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F4R2_FB5           CAN_F4R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F4R2_FB6_Pos       (6U)                                            
#define CAN_F4R2_FB6_Msk       (0x1UL << CAN_F4R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F4R2_FB6           CAN_F4R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F4R2_FB7_Pos       (7U)                                            
#define CAN_F4R2_FB7_Msk       (0x1UL << CAN_F4R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F4R2_FB7           CAN_F4R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F4R2_FB8_Pos       (8U)                                            
#define CAN_F4R2_FB8_Msk       (0x1UL << CAN_F4R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F4R2_FB8           CAN_F4R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F4R2_FB9_Pos       (9U)                                            
#define CAN_F4R2_FB9_Msk       (0x1UL << CAN_F4R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F4R2_FB9           CAN_F4R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F4R2_FB10_Pos      (10U)                                           
#define CAN_F4R2_FB10_Msk      (0x1UL << CAN_F4R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F4R2_FB10          CAN_F4R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F4R2_FB11_Pos      (11U)                                           
#define CAN_F4R2_FB11_Msk      (0x1UL << CAN_F4R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F4R2_FB11          CAN_F4R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F4R2_FB12_Pos      (12U)                                           
#define CAN_F4R2_FB12_Msk      (0x1UL << CAN_F4R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F4R2_FB12          CAN_F4R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F4R2_FB13_Pos      (13U)                                           
#define CAN_F4R2_FB13_Msk      (0x1UL << CAN_F4R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F4R2_FB13          CAN_F4R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F4R2_FB14_Pos      (14U)                                           
#define CAN_F4R2_FB14_Msk      (0x1UL << CAN_F4R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F4R2_FB14          CAN_F4R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F4R2_FB15_Pos      (15U)                                           
#define CAN_F4R2_FB15_Msk      (0x1UL << CAN_F4R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F4R2_FB15          CAN_F4R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F4R2_FB16_Pos      (16U)                                           
#define CAN_F4R2_FB16_Msk      (0x1UL << CAN_F4R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F4R2_FB16          CAN_F4R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F4R2_FB17_Pos      (17U)                                           
#define CAN_F4R2_FB17_Msk      (0x1UL << CAN_F4R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F4R2_FB17          CAN_F4R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F4R2_FB18_Pos      (18U)                                           
#define CAN_F4R2_FB18_Msk      (0x1UL << CAN_F4R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F4R2_FB18          CAN_F4R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F4R2_FB19_Pos      (19U)                                           
#define CAN_F4R2_FB19_Msk      (0x1UL << CAN_F4R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F4R2_FB19          CAN_F4R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F4R2_FB20_Pos      (20U)                                           
#define CAN_F4R2_FB20_Msk      (0x1UL << CAN_F4R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F4R2_FB20          CAN_F4R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F4R2_FB21_Pos      (21U)                                           
#define CAN_F4R2_FB21_Msk      (0x1UL << CAN_F4R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F4R2_FB21          CAN_F4R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F4R2_FB22_Pos      (22U)                                           
#define CAN_F4R2_FB22_Msk      (0x1UL << CAN_F4R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F4R2_FB22          CAN_F4R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F4R2_FB23_Pos      (23U)                                           
#define CAN_F4R2_FB23_Msk      (0x1UL << CAN_F4R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F4R2_FB23          CAN_F4R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F4R2_FB24_Pos      (24U)                                           
#define CAN_F4R2_FB24_Msk      (0x1UL << CAN_F4R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F4R2_FB24          CAN_F4R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F4R2_FB25_Pos      (25U)                                           
#define CAN_F4R2_FB25_Msk      (0x1UL << CAN_F4R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F4R2_FB25          CAN_F4R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F4R2_FB26_Pos      (26U)                                           
#define CAN_F4R2_FB26_Msk      (0x1UL << CAN_F4R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F4R2_FB26          CAN_F4R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F4R2_FB27_Pos      (27U)                                           
#define CAN_F4R2_FB27_Msk      (0x1UL << CAN_F4R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F4R2_FB27          CAN_F4R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F4R2_FB28_Pos      (28U)                                           
#define CAN_F4R2_FB28_Msk      (0x1UL << CAN_F4R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F4R2_FB28          CAN_F4R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F4R2_FB29_Pos      (29U)                                           
#define CAN_F4R2_FB29_Msk      (0x1UL << CAN_F4R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F4R2_FB29          CAN_F4R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F4R2_FB30_Pos      (30U)                                           
#define CAN_F4R2_FB30_Msk      (0x1UL << CAN_F4R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F4R2_FB30          CAN_F4R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F4R2_FB31_Pos      (31U)                                           
#define CAN_F4R2_FB31_Msk      (0x1UL << CAN_F4R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F4R2_FB31          CAN_F4R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define CAN_F5R2_FB0_Pos       (0U)                                            
#define CAN_F5R2_FB0_Msk       (0x1UL << CAN_F5R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F5R2_FB0           CAN_F5R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F5R2_FB1_Pos       (1U)                                            
#define CAN_F5R2_FB1_Msk       (0x1UL << CAN_F5R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F5R2_FB1           CAN_F5R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F5R2_FB2_Pos       (2U)                                            
#define CAN_F5R2_FB2_Msk       (0x1UL << CAN_F5R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F5R2_FB2           CAN_F5R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F5R2_FB3_Pos       (3U)                                            
#define CAN_F5R2_FB3_Msk       (0x1UL << CAN_F5R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F5R2_FB3           CAN_F5R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F5R2_FB4_Pos       (4U)                                            
#define CAN_F5R2_FB4_Msk       (0x1UL << CAN_F5R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F5R2_FB4           CAN_F5R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F5R2_FB5_Pos       (5U)                                            
#define CAN_F5R2_FB5_Msk       (0x1UL << CAN_F5R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F5R2_FB5           CAN_F5R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F5R2_FB6_Pos       (6U)                                            
#define CAN_F5R2_FB6_Msk       (0x1UL << CAN_F5R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F5R2_FB6           CAN_F5R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F5R2_FB7_Pos       (7U)                                            
#define CAN_F5R2_FB7_Msk       (0x1UL << CAN_F5R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F5R2_FB7           CAN_F5R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F5R2_FB8_Pos       (8U)                                            
#define CAN_F5R2_FB8_Msk       (0x1UL << CAN_F5R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F5R2_FB8           CAN_F5R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F5R2_FB9_Pos       (9U)                                            
#define CAN_F5R2_FB9_Msk       (0x1UL << CAN_F5R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F5R2_FB9           CAN_F5R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F5R2_FB10_Pos      (10U)                                           
#define CAN_F5R2_FB10_Msk      (0x1UL << CAN_F5R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F5R2_FB10          CAN_F5R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F5R2_FB11_Pos      (11U)                                           
#define CAN_F5R2_FB11_Msk      (0x1UL << CAN_F5R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F5R2_FB11          CAN_F5R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F5R2_FB12_Pos      (12U)                                           
#define CAN_F5R2_FB12_Msk      (0x1UL << CAN_F5R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F5R2_FB12          CAN_F5R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F5R2_FB13_Pos      (13U)                                           
#define CAN_F5R2_FB13_Msk      (0x1UL << CAN_F5R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F5R2_FB13          CAN_F5R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F5R2_FB14_Pos      (14U)                                           
#define CAN_F5R2_FB14_Msk      (0x1UL << CAN_F5R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F5R2_FB14          CAN_F5R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F5R2_FB15_Pos      (15U)                                           
#define CAN_F5R2_FB15_Msk      (0x1UL << CAN_F5R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F5R2_FB15          CAN_F5R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F5R2_FB16_Pos      (16U)                                           
#define CAN_F5R2_FB16_Msk      (0x1UL << CAN_F5R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F5R2_FB16          CAN_F5R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F5R2_FB17_Pos      (17U)                                           
#define CAN_F5R2_FB17_Msk      (0x1UL << CAN_F5R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F5R2_FB17          CAN_F5R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F5R2_FB18_Pos      (18U)                                           
#define CAN_F5R2_FB18_Msk      (0x1UL << CAN_F5R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F5R2_FB18          CAN_F5R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F5R2_FB19_Pos      (19U)                                           
#define CAN_F5R2_FB19_Msk      (0x1UL << CAN_F5R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F5R2_FB19          CAN_F5R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F5R2_FB20_Pos      (20U)                                           
#define CAN_F5R2_FB20_Msk      (0x1UL << CAN_F5R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F5R2_FB20          CAN_F5R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F5R2_FB21_Pos      (21U)                                           
#define CAN_F5R2_FB21_Msk      (0x1UL << CAN_F5R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F5R2_FB21          CAN_F5R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F5R2_FB22_Pos      (22U)                                           
#define CAN_F5R2_FB22_Msk      (0x1UL << CAN_F5R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F5R2_FB22          CAN_F5R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F5R2_FB23_Pos      (23U)                                           
#define CAN_F5R2_FB23_Msk      (0x1UL << CAN_F5R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F5R2_FB23          CAN_F5R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F5R2_FB24_Pos      (24U)                                           
#define CAN_F5R2_FB24_Msk      (0x1UL << CAN_F5R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F5R2_FB24          CAN_F5R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F5R2_FB25_Pos      (25U)                                           
#define CAN_F5R2_FB25_Msk      (0x1UL << CAN_F5R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F5R2_FB25          CAN_F5R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F5R2_FB26_Pos      (26U)                                           
#define CAN_F5R2_FB26_Msk      (0x1UL << CAN_F5R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F5R2_FB26          CAN_F5R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F5R2_FB27_Pos      (27U)                                           
#define CAN_F5R2_FB27_Msk      (0x1UL << CAN_F5R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F5R2_FB27          CAN_F5R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F5R2_FB28_Pos      (28U)                                           
#define CAN_F5R2_FB28_Msk      (0x1UL << CAN_F5R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F5R2_FB28          CAN_F5R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F5R2_FB29_Pos      (29U)                                           
#define CAN_F5R2_FB29_Msk      (0x1UL << CAN_F5R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F5R2_FB29          CAN_F5R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F5R2_FB30_Pos      (30U)                                           
#define CAN_F5R2_FB30_Msk      (0x1UL << CAN_F5R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F5R2_FB30          CAN_F5R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F5R2_FB31_Pos      (31U)                                           
#define CAN_F5R2_FB31_Msk      (0x1UL << CAN_F5R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F5R2_FB31          CAN_F5R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define CAN_F6R2_FB0_Pos       (0U)                                            
#define CAN_F6R2_FB0_Msk       (0x1UL << CAN_F6R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F6R2_FB0           CAN_F6R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F6R2_FB1_Pos       (1U)                                            
#define CAN_F6R2_FB1_Msk       (0x1UL << CAN_F6R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F6R2_FB1           CAN_F6R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F6R2_FB2_Pos       (2U)                                            
#define CAN_F6R2_FB2_Msk       (0x1UL << CAN_F6R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F6R2_FB2           CAN_F6R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F6R2_FB3_Pos       (3U)                                            
#define CAN_F6R2_FB3_Msk       (0x1UL << CAN_F6R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F6R2_FB3           CAN_F6R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F6R2_FB4_Pos       (4U)                                            
#define CAN_F6R2_FB4_Msk       (0x1UL << CAN_F6R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F6R2_FB4           CAN_F6R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F6R2_FB5_Pos       (5U)                                            
#define CAN_F6R2_FB5_Msk       (0x1UL << CAN_F6R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F6R2_FB5           CAN_F6R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F6R2_FB6_Pos       (6U)                                            
#define CAN_F6R2_FB6_Msk       (0x1UL << CAN_F6R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F6R2_FB6           CAN_F6R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F6R2_FB7_Pos       (7U)                                            
#define CAN_F6R2_FB7_Msk       (0x1UL << CAN_F6R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F6R2_FB7           CAN_F6R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F6R2_FB8_Pos       (8U)                                            
#define CAN_F6R2_FB8_Msk       (0x1UL << CAN_F6R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F6R2_FB8           CAN_F6R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F6R2_FB9_Pos       (9U)                                            
#define CAN_F6R2_FB9_Msk       (0x1UL << CAN_F6R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F6R2_FB9           CAN_F6R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F6R2_FB10_Pos      (10U)                                           
#define CAN_F6R2_FB10_Msk      (0x1UL << CAN_F6R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F6R2_FB10          CAN_F6R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F6R2_FB11_Pos      (11U)                                           
#define CAN_F6R2_FB11_Msk      (0x1UL << CAN_F6R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F6R2_FB11          CAN_F6R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F6R2_FB12_Pos      (12U)                                           
#define CAN_F6R2_FB12_Msk      (0x1UL << CAN_F6R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F6R2_FB12          CAN_F6R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F6R2_FB13_Pos      (13U)                                           
#define CAN_F6R2_FB13_Msk      (0x1UL << CAN_F6R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F6R2_FB13          CAN_F6R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F6R2_FB14_Pos      (14U)                                           
#define CAN_F6R2_FB14_Msk      (0x1UL << CAN_F6R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F6R2_FB14          CAN_F6R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F6R2_FB15_Pos      (15U)                                           
#define CAN_F6R2_FB15_Msk      (0x1UL << CAN_F6R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F6R2_FB15          CAN_F6R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F6R2_FB16_Pos      (16U)                                           
#define CAN_F6R2_FB16_Msk      (0x1UL << CAN_F6R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F6R2_FB16          CAN_F6R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F6R2_FB17_Pos      (17U)                                           
#define CAN_F6R2_FB17_Msk      (0x1UL << CAN_F6R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F6R2_FB17          CAN_F6R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F6R2_FB18_Pos      (18U)                                           
#define CAN_F6R2_FB18_Msk      (0x1UL << CAN_F6R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F6R2_FB18          CAN_F6R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F6R2_FB19_Pos      (19U)                                           
#define CAN_F6R2_FB19_Msk      (0x1UL << CAN_F6R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F6R2_FB19          CAN_F6R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F6R2_FB20_Pos      (20U)                                           
#define CAN_F6R2_FB20_Msk      (0x1UL << CAN_F6R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F6R2_FB20          CAN_F6R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F6R2_FB21_Pos      (21U)                                           
#define CAN_F6R2_FB21_Msk      (0x1UL << CAN_F6R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F6R2_FB21          CAN_F6R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F6R2_FB22_Pos      (22U)                                           
#define CAN_F6R2_FB22_Msk      (0x1UL << CAN_F6R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F6R2_FB22          CAN_F6R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F6R2_FB23_Pos      (23U)                                           
#define CAN_F6R2_FB23_Msk      (0x1UL << CAN_F6R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F6R2_FB23          CAN_F6R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F6R2_FB24_Pos      (24U)                                           
#define CAN_F6R2_FB24_Msk      (0x1UL << CAN_F6R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F6R2_FB24          CAN_F6R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F6R2_FB25_Pos      (25U)                                           
#define CAN_F6R2_FB25_Msk      (0x1UL << CAN_F6R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F6R2_FB25          CAN_F6R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F6R2_FB26_Pos      (26U)                                           
#define CAN_F6R2_FB26_Msk      (0x1UL << CAN_F6R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F6R2_FB26          CAN_F6R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F6R2_FB27_Pos      (27U)                                           
#define CAN_F6R2_FB27_Msk      (0x1UL << CAN_F6R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F6R2_FB27          CAN_F6R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F6R2_FB28_Pos      (28U)                                           
#define CAN_F6R2_FB28_Msk      (0x1UL << CAN_F6R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F6R2_FB28          CAN_F6R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F6R2_FB29_Pos      (29U)                                           
#define CAN_F6R2_FB29_Msk      (0x1UL << CAN_F6R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F6R2_FB29          CAN_F6R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F6R2_FB30_Pos      (30U)                                           
#define CAN_F6R2_FB30_Msk      (0x1UL << CAN_F6R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F6R2_FB30          CAN_F6R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F6R2_FB31_Pos      (31U)                                           
#define CAN_F6R2_FB31_Msk      (0x1UL << CAN_F6R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F6R2_FB31          CAN_F6R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define CAN_F7R2_FB0_Pos       (0U)                                            
#define CAN_F7R2_FB0_Msk       (0x1UL << CAN_F7R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F7R2_FB0           CAN_F7R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F7R2_FB1_Pos       (1U)                                            
#define CAN_F7R2_FB1_Msk       (0x1UL << CAN_F7R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F7R2_FB1           CAN_F7R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F7R2_FB2_Pos       (2U)                                            
#define CAN_F7R2_FB2_Msk       (0x1UL << CAN_F7R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F7R2_FB2           CAN_F7R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F7R2_FB3_Pos       (3U)                                            
#define CAN_F7R2_FB3_Msk       (0x1UL << CAN_F7R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F7R2_FB3           CAN_F7R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F7R2_FB4_Pos       (4U)                                            
#define CAN_F7R2_FB4_Msk       (0x1UL << CAN_F7R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F7R2_FB4           CAN_F7R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F7R2_FB5_Pos       (5U)                                            
#define CAN_F7R2_FB5_Msk       (0x1UL << CAN_F7R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F7R2_FB5           CAN_F7R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F7R2_FB6_Pos       (6U)                                            
#define CAN_F7R2_FB6_Msk       (0x1UL << CAN_F7R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F7R2_FB6           CAN_F7R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F7R2_FB7_Pos       (7U)                                            
#define CAN_F7R2_FB7_Msk       (0x1UL << CAN_F7R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F7R2_FB7           CAN_F7R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F7R2_FB8_Pos       (8U)                                            
#define CAN_F7R2_FB8_Msk       (0x1UL << CAN_F7R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F7R2_FB8           CAN_F7R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F7R2_FB9_Pos       (9U)                                            
#define CAN_F7R2_FB9_Msk       (0x1UL << CAN_F7R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F7R2_FB9           CAN_F7R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F7R2_FB10_Pos      (10U)                                           
#define CAN_F7R2_FB10_Msk      (0x1UL << CAN_F7R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F7R2_FB10          CAN_F7R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F7R2_FB11_Pos      (11U)                                           
#define CAN_F7R2_FB11_Msk      (0x1UL << CAN_F7R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F7R2_FB11          CAN_F7R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F7R2_FB12_Pos      (12U)                                           
#define CAN_F7R2_FB12_Msk      (0x1UL << CAN_F7R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F7R2_FB12          CAN_F7R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F7R2_FB13_Pos      (13U)                                           
#define CAN_F7R2_FB13_Msk      (0x1UL << CAN_F7R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F7R2_FB13          CAN_F7R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F7R2_FB14_Pos      (14U)                                           
#define CAN_F7R2_FB14_Msk      (0x1UL << CAN_F7R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F7R2_FB14          CAN_F7R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F7R2_FB15_Pos      (15U)                                           
#define CAN_F7R2_FB15_Msk      (0x1UL << CAN_F7R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F7R2_FB15          CAN_F7R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F7R2_FB16_Pos      (16U)                                           
#define CAN_F7R2_FB16_Msk      (0x1UL << CAN_F7R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F7R2_FB16          CAN_F7R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F7R2_FB17_Pos      (17U)                                           
#define CAN_F7R2_FB17_Msk      (0x1UL << CAN_F7R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F7R2_FB17          CAN_F7R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F7R2_FB18_Pos      (18U)                                           
#define CAN_F7R2_FB18_Msk      (0x1UL << CAN_F7R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F7R2_FB18          CAN_F7R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F7R2_FB19_Pos      (19U)                                           
#define CAN_F7R2_FB19_Msk      (0x1UL << CAN_F7R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F7R2_FB19          CAN_F7R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F7R2_FB20_Pos      (20U)                                           
#define CAN_F7R2_FB20_Msk      (0x1UL << CAN_F7R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F7R2_FB20          CAN_F7R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F7R2_FB21_Pos      (21U)                                           
#define CAN_F7R2_FB21_Msk      (0x1UL << CAN_F7R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F7R2_FB21          CAN_F7R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F7R2_FB22_Pos      (22U)                                           
#define CAN_F7R2_FB22_Msk      (0x1UL << CAN_F7R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F7R2_FB22          CAN_F7R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F7R2_FB23_Pos      (23U)                                           
#define CAN_F7R2_FB23_Msk      (0x1UL << CAN_F7R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F7R2_FB23          CAN_F7R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F7R2_FB24_Pos      (24U)                                           
#define CAN_F7R2_FB24_Msk      (0x1UL << CAN_F7R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F7R2_FB24          CAN_F7R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F7R2_FB25_Pos      (25U)                                           
#define CAN_F7R2_FB25_Msk      (0x1UL << CAN_F7R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F7R2_FB25          CAN_F7R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F7R2_FB26_Pos      (26U)                                           
#define CAN_F7R2_FB26_Msk      (0x1UL << CAN_F7R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F7R2_FB26          CAN_F7R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F7R2_FB27_Pos      (27U)                                           
#define CAN_F7R2_FB27_Msk      (0x1UL << CAN_F7R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F7R2_FB27          CAN_F7R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F7R2_FB28_Pos      (28U)                                           
#define CAN_F7R2_FB28_Msk      (0x1UL << CAN_F7R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F7R2_FB28          CAN_F7R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F7R2_FB29_Pos      (29U)                                           
#define CAN_F7R2_FB29_Msk      (0x1UL << CAN_F7R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F7R2_FB29          CAN_F7R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F7R2_FB30_Pos      (30U)                                           
#define CAN_F7R2_FB30_Msk      (0x1UL << CAN_F7R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F7R2_FB30          CAN_F7R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F7R2_FB31_Pos      (31U)                                           
#define CAN_F7R2_FB31_Msk      (0x1UL << CAN_F7R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F7R2_FB31          CAN_F7R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define CAN_F8R2_FB0_Pos       (0U)                                            
#define CAN_F8R2_FB0_Msk       (0x1UL << CAN_F8R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F8R2_FB0           CAN_F8R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F8R2_FB1_Pos       (1U)                                            
#define CAN_F8R2_FB1_Msk       (0x1UL << CAN_F8R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F8R2_FB1           CAN_F8R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F8R2_FB2_Pos       (2U)                                            
#define CAN_F8R2_FB2_Msk       (0x1UL << CAN_F8R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F8R2_FB2           CAN_F8R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F8R2_FB3_Pos       (3U)                                            
#define CAN_F8R2_FB3_Msk       (0x1UL << CAN_F8R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F8R2_FB3           CAN_F8R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F8R2_FB4_Pos       (4U)                                            
#define CAN_F8R2_FB4_Msk       (0x1UL << CAN_F8R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F8R2_FB4           CAN_F8R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F8R2_FB5_Pos       (5U)                                            
#define CAN_F8R2_FB5_Msk       (0x1UL << CAN_F8R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F8R2_FB5           CAN_F8R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F8R2_FB6_Pos       (6U)                                            
#define CAN_F8R2_FB6_Msk       (0x1UL << CAN_F8R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F8R2_FB6           CAN_F8R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F8R2_FB7_Pos       (7U)                                            
#define CAN_F8R2_FB7_Msk       (0x1UL << CAN_F8R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F8R2_FB7           CAN_F8R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F8R2_FB8_Pos       (8U)                                            
#define CAN_F8R2_FB8_Msk       (0x1UL << CAN_F8R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F8R2_FB8           CAN_F8R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F8R2_FB9_Pos       (9U)                                            
#define CAN_F8R2_FB9_Msk       (0x1UL << CAN_F8R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F8R2_FB9           CAN_F8R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F8R2_FB10_Pos      (10U)                                           
#define CAN_F8R2_FB10_Msk      (0x1UL << CAN_F8R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F8R2_FB10          CAN_F8R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F8R2_FB11_Pos      (11U)                                           
#define CAN_F8R2_FB11_Msk      (0x1UL << CAN_F8R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F8R2_FB11          CAN_F8R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F8R2_FB12_Pos      (12U)                                           
#define CAN_F8R2_FB12_Msk      (0x1UL << CAN_F8R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F8R2_FB12          CAN_F8R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F8R2_FB13_Pos      (13U)                                           
#define CAN_F8R2_FB13_Msk      (0x1UL << CAN_F8R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F8R2_FB13          CAN_F8R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F8R2_FB14_Pos      (14U)                                           
#define CAN_F8R2_FB14_Msk      (0x1UL << CAN_F8R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F8R2_FB14          CAN_F8R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F8R2_FB15_Pos      (15U)                                           
#define CAN_F8R2_FB15_Msk      (0x1UL << CAN_F8R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F8R2_FB15          CAN_F8R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F8R2_FB16_Pos      (16U)                                           
#define CAN_F8R2_FB16_Msk      (0x1UL << CAN_F8R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F8R2_FB16          CAN_F8R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F8R2_FB17_Pos      (17U)                                           
#define CAN_F8R2_FB17_Msk      (0x1UL << CAN_F8R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F8R2_FB17          CAN_F8R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F8R2_FB18_Pos      (18U)                                           
#define CAN_F8R2_FB18_Msk      (0x1UL << CAN_F8R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F8R2_FB18          CAN_F8R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F8R2_FB19_Pos      (19U)                                           
#define CAN_F8R2_FB19_Msk      (0x1UL << CAN_F8R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F8R2_FB19          CAN_F8R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F8R2_FB20_Pos      (20U)                                           
#define CAN_F8R2_FB20_Msk      (0x1UL << CAN_F8R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F8R2_FB20          CAN_F8R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F8R2_FB21_Pos      (21U)                                           
#define CAN_F8R2_FB21_Msk      (0x1UL << CAN_F8R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F8R2_FB21          CAN_F8R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F8R2_FB22_Pos      (22U)                                           
#define CAN_F8R2_FB22_Msk      (0x1UL << CAN_F8R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F8R2_FB22          CAN_F8R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F8R2_FB23_Pos      (23U)                                           
#define CAN_F8R2_FB23_Msk      (0x1UL << CAN_F8R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F8R2_FB23          CAN_F8R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F8R2_FB24_Pos      (24U)                                           
#define CAN_F8R2_FB24_Msk      (0x1UL << CAN_F8R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F8R2_FB24          CAN_F8R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F8R2_FB25_Pos      (25U)                                           
#define CAN_F8R2_FB25_Msk      (0x1UL << CAN_F8R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F8R2_FB25          CAN_F8R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F8R2_FB26_Pos      (26U)                                           
#define CAN_F8R2_FB26_Msk      (0x1UL << CAN_F8R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F8R2_FB26          CAN_F8R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F8R2_FB27_Pos      (27U)                                           
#define CAN_F8R2_FB27_Msk      (0x1UL << CAN_F8R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F8R2_FB27          CAN_F8R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F8R2_FB28_Pos      (28U)                                           
#define CAN_F8R2_FB28_Msk      (0x1UL << CAN_F8R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F8R2_FB28          CAN_F8R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F8R2_FB29_Pos      (29U)                                           
#define CAN_F8R2_FB29_Msk      (0x1UL << CAN_F8R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F8R2_FB29          CAN_F8R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F8R2_FB30_Pos      (30U)                                           
#define CAN_F8R2_FB30_Msk      (0x1UL << CAN_F8R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F8R2_FB30          CAN_F8R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F8R2_FB31_Pos      (31U)                                           
#define CAN_F8R2_FB31_Msk      (0x1UL << CAN_F8R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F8R2_FB31          CAN_F8R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define CAN_F9R2_FB0_Pos       (0U)                                            
#define CAN_F9R2_FB0_Msk       (0x1UL << CAN_F9R2_FB0_Pos)                      /*!< 0x00000001 */
#define CAN_F9R2_FB0           CAN_F9R2_FB0_Msk                                /*!<Filter bit 0 */
#define CAN_F9R2_FB1_Pos       (1U)                                            
#define CAN_F9R2_FB1_Msk       (0x1UL << CAN_F9R2_FB1_Pos)                      /*!< 0x00000002 */
#define CAN_F9R2_FB1           CAN_F9R2_FB1_Msk                                /*!<Filter bit 1 */
#define CAN_F9R2_FB2_Pos       (2U)                                            
#define CAN_F9R2_FB2_Msk       (0x1UL << CAN_F9R2_FB2_Pos)                      /*!< 0x00000004 */
#define CAN_F9R2_FB2           CAN_F9R2_FB2_Msk                                /*!<Filter bit 2 */
#define CAN_F9R2_FB3_Pos       (3U)                                            
#define CAN_F9R2_FB3_Msk       (0x1UL << CAN_F9R2_FB3_Pos)                      /*!< 0x00000008 */
#define CAN_F9R2_FB3           CAN_F9R2_FB3_Msk                                /*!<Filter bit 3 */
#define CAN_F9R2_FB4_Pos       (4U)                                            
#define CAN_F9R2_FB4_Msk       (0x1UL << CAN_F9R2_FB4_Pos)                      /*!< 0x00000010 */
#define CAN_F9R2_FB4           CAN_F9R2_FB4_Msk                                /*!<Filter bit 4 */
#define CAN_F9R2_FB5_Pos       (5U)                                            
#define CAN_F9R2_FB5_Msk       (0x1UL << CAN_F9R2_FB5_Pos)                      /*!< 0x00000020 */
#define CAN_F9R2_FB5           CAN_F9R2_FB5_Msk                                /*!<Filter bit 5 */
#define CAN_F9R2_FB6_Pos       (6U)                                            
#define CAN_F9R2_FB6_Msk       (0x1UL << CAN_F9R2_FB6_Pos)                      /*!< 0x00000040 */
#define CAN_F9R2_FB6           CAN_F9R2_FB6_Msk                                /*!<Filter bit 6 */
#define CAN_F9R2_FB7_Pos       (7U)                                            
#define CAN_F9R2_FB7_Msk       (0x1UL << CAN_F9R2_FB7_Pos)                      /*!< 0x00000080 */
#define CAN_F9R2_FB7           CAN_F9R2_FB7_Msk                                /*!<Filter bit 7 */
#define CAN_F9R2_FB8_Pos       (8U)                                            
#define CAN_F9R2_FB8_Msk       (0x1UL << CAN_F9R2_FB8_Pos)                      /*!< 0x00000100 */
#define CAN_F9R2_FB8           CAN_F9R2_FB8_Msk                                /*!<Filter bit 8 */
#define CAN_F9R2_FB9_Pos       (9U)                                            
#define CAN_F9R2_FB9_Msk       (0x1UL << CAN_F9R2_FB9_Pos)                      /*!< 0x00000200 */
#define CAN_F9R2_FB9           CAN_F9R2_FB9_Msk                                /*!<Filter bit 9 */
#define CAN_F9R2_FB10_Pos      (10U)                                           
#define CAN_F9R2_FB10_Msk      (0x1UL << CAN_F9R2_FB10_Pos)                     /*!< 0x00000400 */
#define CAN_F9R2_FB10          CAN_F9R2_FB10_Msk                               /*!<Filter bit 10 */
#define CAN_F9R2_FB11_Pos      (11U)                                           
#define CAN_F9R2_FB11_Msk      (0x1UL << CAN_F9R2_FB11_Pos)                     /*!< 0x00000800 */
#define CAN_F9R2_FB11          CAN_F9R2_FB11_Msk                               /*!<Filter bit 11 */
#define CAN_F9R2_FB12_Pos      (12U)                                           
#define CAN_F9R2_FB12_Msk      (0x1UL << CAN_F9R2_FB12_Pos)                     /*!< 0x00001000 */
#define CAN_F9R2_FB12          CAN_F9R2_FB12_Msk                               /*!<Filter bit 12 */
#define CAN_F9R2_FB13_Pos      (13U)                                           
#define CAN_F9R2_FB13_Msk      (0x1UL << CAN_F9R2_FB13_Pos)                     /*!< 0x00002000 */
#define CAN_F9R2_FB13          CAN_F9R2_FB13_Msk                               /*!<Filter bit 13 */
#define CAN_F9R2_FB14_Pos      (14U)                                           
#define CAN_F9R2_FB14_Msk      (0x1UL << CAN_F9R2_FB14_Pos)                     /*!< 0x00004000 */
#define CAN_F9R2_FB14          CAN_F9R2_FB14_Msk                               /*!<Filter bit 14 */
#define CAN_F9R2_FB15_Pos      (15U)                                           
#define CAN_F9R2_FB15_Msk      (0x1UL << CAN_F9R2_FB15_Pos)                     /*!< 0x00008000 */
#define CAN_F9R2_FB15          CAN_F9R2_FB15_Msk                               /*!<Filter bit 15 */
#define CAN_F9R2_FB16_Pos      (16U)                                           
#define CAN_F9R2_FB16_Msk      (0x1UL << CAN_F9R2_FB16_Pos)                     /*!< 0x00010000 */
#define CAN_F9R2_FB16          CAN_F9R2_FB16_Msk                               /*!<Filter bit 16 */
#define CAN_F9R2_FB17_Pos      (17U)                                           
#define CAN_F9R2_FB17_Msk      (0x1UL << CAN_F9R2_FB17_Pos)                     /*!< 0x00020000 */
#define CAN_F9R2_FB17          CAN_F9R2_FB17_Msk                               /*!<Filter bit 17 */
#define CAN_F9R2_FB18_Pos      (18U)                                           
#define CAN_F9R2_FB18_Msk      (0x1UL << CAN_F9R2_FB18_Pos)                     /*!< 0x00040000 */
#define CAN_F9R2_FB18          CAN_F9R2_FB18_Msk                               /*!<Filter bit 18 */
#define CAN_F9R2_FB19_Pos      (19U)                                           
#define CAN_F9R2_FB19_Msk      (0x1UL << CAN_F9R2_FB19_Pos)                     /*!< 0x00080000 */
#define CAN_F9R2_FB19          CAN_F9R2_FB19_Msk                               /*!<Filter bit 19 */
#define CAN_F9R2_FB20_Pos      (20U)                                           
#define CAN_F9R2_FB20_Msk      (0x1UL << CAN_F9R2_FB20_Pos)                     /*!< 0x00100000 */
#define CAN_F9R2_FB20          CAN_F9R2_FB20_Msk                               /*!<Filter bit 20 */
#define CAN_F9R2_FB21_Pos      (21U)                                           
#define CAN_F9R2_FB21_Msk      (0x1UL << CAN_F9R2_FB21_Pos)                     /*!< 0x00200000 */
#define CAN_F9R2_FB21          CAN_F9R2_FB21_Msk                               /*!<Filter bit 21 */
#define CAN_F9R2_FB22_Pos      (22U)                                           
#define CAN_F9R2_FB22_Msk      (0x1UL << CAN_F9R2_FB22_Pos)                     /*!< 0x00400000 */
#define CAN_F9R2_FB22          CAN_F9R2_FB22_Msk                               /*!<Filter bit 22 */
#define CAN_F9R2_FB23_Pos      (23U)                                           
#define CAN_F9R2_FB23_Msk      (0x1UL << CAN_F9R2_FB23_Pos)                     /*!< 0x00800000 */
#define CAN_F9R2_FB23          CAN_F9R2_FB23_Msk                               /*!<Filter bit 23 */
#define CAN_F9R2_FB24_Pos      (24U)                                           
#define CAN_F9R2_FB24_Msk      (0x1UL << CAN_F9R2_FB24_Pos)                     /*!< 0x01000000 */
#define CAN_F9R2_FB24          CAN_F9R2_FB24_Msk                               /*!<Filter bit 24 */
#define CAN_F9R2_FB25_Pos      (25U)                                           
#define CAN_F9R2_FB25_Msk      (0x1UL << CAN_F9R2_FB25_Pos)                     /*!< 0x02000000 */
#define CAN_F9R2_FB25          CAN_F9R2_FB25_Msk                               /*!<Filter bit 25 */
#define CAN_F9R2_FB26_Pos      (26U)                                           
#define CAN_F9R2_FB26_Msk      (0x1UL << CAN_F9R2_FB26_Pos)                     /*!< 0x04000000 */
#define CAN_F9R2_FB26          CAN_F9R2_FB26_Msk                               /*!<Filter bit 26 */
#define CAN_F9R2_FB27_Pos      (27U)                                           
#define CAN_F9R2_FB27_Msk      (0x1UL << CAN_F9R2_FB27_Pos)                     /*!< 0x08000000 */
#define CAN_F9R2_FB27          CAN_F9R2_FB27_Msk                               /*!<Filter bit 27 */
#define CAN_F9R2_FB28_Pos      (28U)                                           
#define CAN_F9R2_FB28_Msk      (0x1UL << CAN_F9R2_FB28_Pos)                     /*!< 0x10000000 */
#define CAN_F9R2_FB28          CAN_F9R2_FB28_Msk                               /*!<Filter bit 28 */
#define CAN_F9R2_FB29_Pos      (29U)                                           
#define CAN_F9R2_FB29_Msk      (0x1UL << CAN_F9R2_FB29_Pos)                     /*!< 0x20000000 */
#define CAN_F9R2_FB29          CAN_F9R2_FB29_Msk                               /*!<Filter bit 29 */
#define CAN_F9R2_FB30_Pos      (30U)                                           
#define CAN_F9R2_FB30_Msk      (0x1UL << CAN_F9R2_FB30_Pos)                     /*!< 0x40000000 */
#define CAN_F9R2_FB30          CAN_F9R2_FB30_Msk                               /*!<Filter bit 30 */
#define CAN_F9R2_FB31_Pos      (31U)                                           
#define CAN_F9R2_FB31_Msk      (0x1UL << CAN_F9R2_FB31_Pos)                     /*!< 0x80000000 */
#define CAN_F9R2_FB31          CAN_F9R2_FB31_Msk                               /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define CAN_F10R2_FB0_Pos      (0U)                                            
#define CAN_F10R2_FB0_Msk      (0x1UL << CAN_F10R2_FB0_Pos)                     /*!< 0x00000001 */
#define CAN_F10R2_FB0          CAN_F10R2_FB0_Msk                               /*!<Filter bit 0 */
#define CAN_F10R2_FB1_Pos      (1U)                                            
#define CAN_F10R2_FB1_Msk      (0x1UL << CAN_F10R2_FB1_Pos)                     /*!< 0x00000002 */
#define CAN_F10R2_FB1          CAN_F10R2_FB1_Msk                               /*!<Filter bit 1 */
#define CAN_F10R2_FB2_Pos      (2U)                                            
#define CAN_F10R2_FB2_Msk      (0x1UL << CAN_F10R2_FB2_Pos)                     /*!< 0x00000004 */
#define CAN_F10R2_FB2          CAN_F10R2_FB2_Msk                               /*!<Filter bit 2 */
#define CAN_F10R2_FB3_Pos      (3U)                                            
#define CAN_F10R2_FB3_Msk      (0x1UL << CAN_F10R2_FB3_Pos)                     /*!< 0x00000008 */
#define CAN_F10R2_FB3          CAN_F10R2_FB3_Msk                               /*!<Filter bit 3 */
#define CAN_F10R2_FB4_Pos      (4U)                                            
#define CAN_F10R2_FB4_Msk      (0x1UL << CAN_F10R2_FB4_Pos)                     /*!< 0x00000010 */
#define CAN_F10R2_FB4          CAN_F10R2_FB4_Msk                               /*!<Filter bit 4 */
#define CAN_F10R2_FB5_Pos      (5U)                                            
#define CAN_F10R2_FB5_Msk      (0x1UL << CAN_F10R2_FB5_Pos)                     /*!< 0x00000020 */
#define CAN_F10R2_FB5          CAN_F10R2_FB5_Msk                               /*!<Filter bit 5 */
#define CAN_F10R2_FB6_Pos      (6U)                                            
#define CAN_F10R2_FB6_Msk      (0x1UL << CAN_F10R2_FB6_Pos)                     /*!< 0x00000040 */
#define CAN_F10R2_FB6          CAN_F10R2_FB6_Msk                               /*!<Filter bit 6 */
#define CAN_F10R2_FB7_Pos      (7U)                                            
#define CAN_F10R2_FB7_Msk      (0x1UL << CAN_F10R2_FB7_Pos)                     /*!< 0x00000080 */
#define CAN_F10R2_FB7          CAN_F10R2_FB7_Msk                               /*!<Filter bit 7 */
#define CAN_F10R2_FB8_Pos      (8U)                                            
#define CAN_F10R2_FB8_Msk      (0x1UL << CAN_F10R2_FB8_Pos)                     /*!< 0x00000100 */
#define CAN_F10R2_FB8          CAN_F10R2_FB8_Msk                               /*!<Filter bit 8 */
#define CAN_F10R2_FB9_Pos      (9U)                                            
#define CAN_F10R2_FB9_Msk      (0x1UL << CAN_F10R2_FB9_Pos)                     /*!< 0x00000200 */
#define CAN_F10R2_FB9          CAN_F10R2_FB9_Msk                               /*!<Filter bit 9 */
#define CAN_F10R2_FB10_Pos     (10U)                                           
#define CAN_F10R2_FB10_Msk     (0x1UL << CAN_F10R2_FB10_Pos)                    /*!< 0x00000400 */
#define CAN_F10R2_FB10         CAN_F10R2_FB10_Msk                              /*!<Filter bit 10 */
#define CAN_F10R2_FB11_Pos     (11U)                                           
#define CAN_F10R2_FB11_Msk     (0x1UL << CAN_F10R2_FB11_Pos)                    /*!< 0x00000800 */
#define CAN_F10R2_FB11         CAN_F10R2_FB11_Msk                              /*!<Filter bit 11 */
#define CAN_F10R2_FB12_Pos     (12U)                                           
#define CAN_F10R2_FB12_Msk     (0x1UL << CAN_F10R2_FB12_Pos)                    /*!< 0x00001000 */
#define CAN_F10R2_FB12         CAN_F10R2_FB12_Msk                              /*!<Filter bit 12 */
#define CAN_F10R2_FB13_Pos     (13U)                                           
#define CAN_F10R2_FB13_Msk     (0x1UL << CAN_F10R2_FB13_Pos)                    /*!< 0x00002000 */
#define CAN_F10R2_FB13         CAN_F10R2_FB13_Msk                              /*!<Filter bit 13 */
#define CAN_F10R2_FB14_Pos     (14U)                                           
#define CAN_F10R2_FB14_Msk     (0x1UL << CAN_F10R2_FB14_Pos)                    /*!< 0x00004000 */
#define CAN_F10R2_FB14         CAN_F10R2_FB14_Msk                              /*!<Filter bit 14 */
#define CAN_F10R2_FB15_Pos     (15U)                                           
#define CAN_F10R2_FB15_Msk     (0x1UL << CAN_F10R2_FB15_Pos)                    /*!< 0x00008000 */
#define CAN_F10R2_FB15         CAN_F10R2_FB15_Msk                              /*!<Filter bit 15 */
#define CAN_F10R2_FB16_Pos     (16U)                                           
#define CAN_F10R2_FB16_Msk     (0x1UL << CAN_F10R2_FB16_Pos)                    /*!< 0x00010000 */
#define CAN_F10R2_FB16         CAN_F10R2_FB16_Msk                              /*!<Filter bit 16 */
#define CAN_F10R2_FB17_Pos     (17U)                                           
#define CAN_F10R2_FB17_Msk     (0x1UL << CAN_F10R2_FB17_Pos)                    /*!< 0x00020000 */
#define CAN_F10R2_FB17         CAN_F10R2_FB17_Msk                              /*!<Filter bit 17 */
#define CAN_F10R2_FB18_Pos     (18U)                                           
#define CAN_F10R2_FB18_Msk     (0x1UL << CAN_F10R2_FB18_Pos)                    /*!< 0x00040000 */
#define CAN_F10R2_FB18         CAN_F10R2_FB18_Msk                              /*!<Filter bit 18 */
#define CAN_F10R2_FB19_Pos     (19U)                                           
#define CAN_F10R2_FB19_Msk     (0x1UL << CAN_F10R2_FB19_Pos)                    /*!< 0x00080000 */
#define CAN_F10R2_FB19         CAN_F10R2_FB19_Msk                              /*!<Filter bit 19 */
#define CAN_F10R2_FB20_Pos     (20U)                                           
#define CAN_F10R2_FB20_Msk     (0x1UL << CAN_F10R2_FB20_Pos)                    /*!< 0x00100000 */
#define CAN_F10R2_FB20         CAN_F10R2_FB20_Msk                              /*!<Filter bit 20 */
#define CAN_F10R2_FB21_Pos     (21U)                                           
#define CAN_F10R2_FB21_Msk     (0x1UL << CAN_F10R2_FB21_Pos)                    /*!< 0x00200000 */
#define CAN_F10R2_FB21         CAN_F10R2_FB21_Msk                              /*!<Filter bit 21 */
#define CAN_F10R2_FB22_Pos     (22U)                                           
#define CAN_F10R2_FB22_Msk     (0x1UL << CAN_F10R2_FB22_Pos)                    /*!< 0x00400000 */
#define CAN_F10R2_FB22         CAN_F10R2_FB22_Msk                              /*!<Filter bit 22 */
#define CAN_F10R2_FB23_Pos     (23U)                                           
#define CAN_F10R2_FB23_Msk     (0x1UL << CAN_F10R2_FB23_Pos)                    /*!< 0x00800000 */
#define CAN_F10R2_FB23         CAN_F10R2_FB23_Msk                              /*!<Filter bit 23 */
#define CAN_F10R2_FB24_Pos     (24U)                                           
#define CAN_F10R2_FB24_Msk     (0x1UL << CAN_F10R2_FB24_Pos)                    /*!< 0x01000000 */
#define CAN_F10R2_FB24         CAN_F10R2_FB24_Msk                              /*!<Filter bit 24 */
#define CAN_F10R2_FB25_Pos     (25U)                                           
#define CAN_F10R2_FB25_Msk     (0x1UL << CAN_F10R2_FB25_Pos)                    /*!< 0x02000000 */
#define CAN_F10R2_FB25         CAN_F10R2_FB25_Msk                              /*!<Filter bit 25 */
#define CAN_F10R2_FB26_Pos     (26U)                                           
#define CAN_F10R2_FB26_Msk     (0x1UL << CAN_F10R2_FB26_Pos)                    /*!< 0x04000000 */
#define CAN_F10R2_FB26         CAN_F10R2_FB26_Msk                              /*!<Filter bit 26 */
#define CAN_F10R2_FB27_Pos     (27U)                                           
#define CAN_F10R2_FB27_Msk     (0x1UL << CAN_F10R2_FB27_Pos)                    /*!< 0x08000000 */
#define CAN_F10R2_FB27         CAN_F10R2_FB27_Msk                              /*!<Filter bit 27 */
#define CAN_F10R2_FB28_Pos     (28U)                                           
#define CAN_F10R2_FB28_Msk     (0x1UL << CAN_F10R2_FB28_Pos)                    /*!< 0x10000000 */
#define CAN_F10R2_FB28         CAN_F10R2_FB28_Msk                              /*!<Filter bit 28 */
#define CAN_F10R2_FB29_Pos     (29U)                                           
#define CAN_F10R2_FB29_Msk     (0x1UL << CAN_F10R2_FB29_Pos)                    /*!< 0x20000000 */
#define CAN_F10R2_FB29         CAN_F10R2_FB29_Msk                              /*!<Filter bit 29 */
#define CAN_F10R2_FB30_Pos     (30U)                                           
#define CAN_F10R2_FB30_Msk     (0x1UL << CAN_F10R2_FB30_Pos)                    /*!< 0x40000000 */
#define CAN_F10R2_FB30         CAN_F10R2_FB30_Msk                              /*!<Filter bit 30 */
#define CAN_F10R2_FB31_Pos     (31U)                                           
#define CAN_F10R2_FB31_Msk     (0x1UL << CAN_F10R2_FB31_Pos)                    /*!< 0x80000000 */
#define CAN_F10R2_FB31         CAN_F10R2_FB31_Msk                              /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define CAN_F11R2_FB0_Pos      (0U)                                            
#define CAN_F11R2_FB0_Msk      (0x1UL << CAN_F11R2_FB0_Pos)                     /*!< 0x00000001 */
#define CAN_F11R2_FB0          CAN_F11R2_FB0_Msk                               /*!<Filter bit 0 */
#define CAN_F11R2_FB1_Pos      (1U)                                            
#define CAN_F11R2_FB1_Msk      (0x1UL << CAN_F11R2_FB1_Pos)                     /*!< 0x00000002 */
#define CAN_F11R2_FB1          CAN_F11R2_FB1_Msk                               /*!<Filter bit 1 */
#define CAN_F11R2_FB2_Pos      (2U)                                            
#define CAN_F11R2_FB2_Msk      (0x1UL << CAN_F11R2_FB2_Pos)                     /*!< 0x00000004 */
#define CAN_F11R2_FB2          CAN_F11R2_FB2_Msk                               /*!<Filter bit 2 */
#define CAN_F11R2_FB3_Pos      (3U)                                            
#define CAN_F11R2_FB3_Msk      (0x1UL << CAN_F11R2_FB3_Pos)                     /*!< 0x00000008 */
#define CAN_F11R2_FB3          CAN_F11R2_FB3_Msk                               /*!<Filter bit 3 */
#define CAN_F11R2_FB4_Pos      (4U)                                            
#define CAN_F11R2_FB4_Msk      (0x1UL << CAN_F11R2_FB4_Pos)                     /*!< 0x00000010 */
#define CAN_F11R2_FB4          CAN_F11R2_FB4_Msk                               /*!<Filter bit 4 */
#define CAN_F11R2_FB5_Pos      (5U)                                            
#define CAN_F11R2_FB5_Msk      (0x1UL << CAN_F11R2_FB5_Pos)                     /*!< 0x00000020 */
#define CAN_F11R2_FB5          CAN_F11R2_FB5_Msk                               /*!<Filter bit 5 */
#define CAN_F11R2_FB6_Pos      (6U)                                            
#define CAN_F11R2_FB6_Msk      (0x1UL << CAN_F11R2_FB6_Pos)                     /*!< 0x00000040 */
#define CAN_F11R2_FB6          CAN_F11R2_FB6_Msk                               /*!<Filter bit 6 */
#define CAN_F11R2_FB7_Pos      (7U)                                            
#define CAN_F11R2_FB7_Msk      (0x1UL << CAN_F11R2_FB7_Pos)                     /*!< 0x00000080 */
#define CAN_F11R2_FB7          CAN_F11R2_FB7_Msk                               /*!<Filter bit 7 */
#define CAN_F11R2_FB8_Pos      (8U)                                            
#define CAN_F11R2_FB8_Msk      (0x1UL << CAN_F11R2_FB8_Pos)                     /*!< 0x00000100 */
#define CAN_F11R2_FB8          CAN_F11R2_FB8_Msk                               /*!<Filter bit 8 */
#define CAN_F11R2_FB9_Pos      (9U)                                            
#define CAN_F11R2_FB9_Msk      (0x1UL << CAN_F11R2_FB9_Pos)                     /*!< 0x00000200 */
#define CAN_F11R2_FB9          CAN_F11R2_FB9_Msk                               /*!<Filter bit 9 */
#define CAN_F11R2_FB10_Pos     (10U)                                           
#define CAN_F11R2_FB10_Msk     (0x1UL << CAN_F11R2_FB10_Pos)                    /*!< 0x00000400 */
#define CAN_F11R2_FB10         CAN_F11R2_FB10_Msk                              /*!<Filter bit 10 */
#define CAN_F11R2_FB11_Pos     (11U)                                           
#define CAN_F11R2_FB11_Msk     (0x1UL << CAN_F11R2_FB11_Pos)                    /*!< 0x00000800 */
#define CAN_F11R2_FB11         CAN_F11R2_FB11_Msk                              /*!<Filter bit 11 */
#define CAN_F11R2_FB12_Pos     (12U)                                           
#define CAN_F11R2_FB12_Msk     (0x1UL << CAN_F11R2_FB12_Pos)                    /*!< 0x00001000 */
#define CAN_F11R2_FB12         CAN_F11R2_FB12_Msk                              /*!<Filter bit 12 */
#define CAN_F11R2_FB13_Pos     (13U)                                           
#define CAN_F11R2_FB13_Msk     (0x1UL << CAN_F11R2_FB13_Pos)                    /*!< 0x00002000 */
#define CAN_F11R2_FB13         CAN_F11R2_FB13_Msk                              /*!<Filter bit 13 */
#define CAN_F11R2_FB14_Pos     (14U)                                           
#define CAN_F11R2_FB14_Msk     (0x1UL << CAN_F11R2_FB14_Pos)                    /*!< 0x00004000 */
#define CAN_F11R2_FB14         CAN_F11R2_FB14_Msk                              /*!<Filter bit 14 */
#define CAN_F11R2_FB15_Pos     (15U)                                           
#define CAN_F11R2_FB15_Msk     (0x1UL << CAN_F11R2_FB15_Pos)                    /*!< 0x00008000 */
#define CAN_F11R2_FB15         CAN_F11R2_FB15_Msk                              /*!<Filter bit 15 */
#define CAN_F11R2_FB16_Pos     (16U)                                           
#define CAN_F11R2_FB16_Msk     (0x1UL << CAN_F11R2_FB16_Pos)                    /*!< 0x00010000 */
#define CAN_F11R2_FB16         CAN_F11R2_FB16_Msk                              /*!<Filter bit 16 */
#define CAN_F11R2_FB17_Pos     (17U)                                           
#define CAN_F11R2_FB17_Msk     (0x1UL << CAN_F11R2_FB17_Pos)                    /*!< 0x00020000 */
#define CAN_F11R2_FB17         CAN_F11R2_FB17_Msk                              /*!<Filter bit 17 */
#define CAN_F11R2_FB18_Pos     (18U)                                           
#define CAN_F11R2_FB18_Msk     (0x1UL << CAN_F11R2_FB18_Pos)                    /*!< 0x00040000 */
#define CAN_F11R2_FB18         CAN_F11R2_FB18_Msk                              /*!<Filter bit 18 */
#define CAN_F11R2_FB19_Pos     (19U)                                           
#define CAN_F11R2_FB19_Msk     (0x1UL << CAN_F11R2_FB19_Pos)                    /*!< 0x00080000 */
#define CAN_F11R2_FB19         CAN_F11R2_FB19_Msk                              /*!<Filter bit 19 */
#define CAN_F11R2_FB20_Pos     (20U)                                           
#define CAN_F11R2_FB20_Msk     (0x1UL << CAN_F11R2_FB20_Pos)                    /*!< 0x00100000 */
#define CAN_F11R2_FB20         CAN_F11R2_FB20_Msk                              /*!<Filter bit 20 */
#define CAN_F11R2_FB21_Pos     (21U)                                           
#define CAN_F11R2_FB21_Msk     (0x1UL << CAN_F11R2_FB21_Pos)                    /*!< 0x00200000 */
#define CAN_F11R2_FB21         CAN_F11R2_FB21_Msk                              /*!<Filter bit 21 */
#define CAN_F11R2_FB22_Pos     (22U)                                           
#define CAN_F11R2_FB22_Msk     (0x1UL << CAN_F11R2_FB22_Pos)                    /*!< 0x00400000 */
#define CAN_F11R2_FB22         CAN_F11R2_FB22_Msk                              /*!<Filter bit 22 */
#define CAN_F11R2_FB23_Pos     (23U)                                           
#define CAN_F11R2_FB23_Msk     (0x1UL << CAN_F11R2_FB23_Pos)                    /*!< 0x00800000 */
#define CAN_F11R2_FB23         CAN_F11R2_FB23_Msk                              /*!<Filter bit 23 */
#define CAN_F11R2_FB24_Pos     (24U)                                           
#define CAN_F11R2_FB24_Msk     (0x1UL << CAN_F11R2_FB24_Pos)                    /*!< 0x01000000 */
#define CAN_F11R2_FB24         CAN_F11R2_FB24_Msk                              /*!<Filter bit 24 */
#define CAN_F11R2_FB25_Pos     (25U)                                           
#define CAN_F11R2_FB25_Msk     (0x1UL << CAN_F11R2_FB25_Pos)                    /*!< 0x02000000 */
#define CAN_F11R2_FB25         CAN_F11R2_FB25_Msk                              /*!<Filter bit 25 */
#define CAN_F11R2_FB26_Pos     (26U)                                           
#define CAN_F11R2_FB26_Msk     (0x1UL << CAN_F11R2_FB26_Pos)                    /*!< 0x04000000 */
#define CAN_F11R2_FB26         CAN_F11R2_FB26_Msk                              /*!<Filter bit 26 */
#define CAN_F11R2_FB27_Pos     (27U)                                           
#define CAN_F11R2_FB27_Msk     (0x1UL << CAN_F11R2_FB27_Pos)                    /*!< 0x08000000 */
#define CAN_F11R2_FB27         CAN_F11R2_FB27_Msk                              /*!<Filter bit 27 */
#define CAN_F11R2_FB28_Pos     (28U)                                           
#define CAN_F11R2_FB28_Msk     (0x1UL << CAN_F11R2_FB28_Pos)                    /*!< 0x10000000 */
#define CAN_F11R2_FB28         CAN_F11R2_FB28_Msk                              /*!<Filter bit 28 */
#define CAN_F11R2_FB29_Pos     (29U)                                           
#define CAN_F11R2_FB29_Msk     (0x1UL << CAN_F11R2_FB29_Pos)                    /*!< 0x20000000 */
#define CAN_F11R2_FB29         CAN_F11R2_FB29_Msk                              /*!<Filter bit 29 */
#define CAN_F11R2_FB30_Pos     (30U)                                           
#define CAN_F11R2_FB30_Msk     (0x1UL << CAN_F11R2_FB30_Pos)                    /*!< 0x40000000 */
#define CAN_F11R2_FB30         CAN_F11R2_FB30_Msk                              /*!<Filter bit 30 */
#define CAN_F11R2_FB31_Pos     (31U)                                           
#define CAN_F11R2_FB31_Msk     (0x1UL << CAN_F11R2_FB31_Pos)                    /*!< 0x80000000 */
#define CAN_F11R2_FB31         CAN_F11R2_FB31_Msk                              /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define CAN_F12R2_FB0_Pos      (0U)                                            
#define CAN_F12R2_FB0_Msk      (0x1UL << CAN_F12R2_FB0_Pos)                     /*!< 0x00000001 */
#define CAN_F12R2_FB0          CAN_F12R2_FB0_Msk                               /*!<Filter bit 0 */
#define CAN_F12R2_FB1_Pos      (1U)                                            
#define CAN_F12R2_FB1_Msk      (0x1UL << CAN_F12R2_FB1_Pos)                     /*!< 0x00000002 */
#define CAN_F12R2_FB1          CAN_F12R2_FB1_Msk                               /*!<Filter bit 1 */
#define CAN_F12R2_FB2_Pos      (2U)                                            
#define CAN_F12R2_FB2_Msk      (0x1UL << CAN_F12R2_FB2_Pos)                     /*!< 0x00000004 */
#define CAN_F12R2_FB2          CAN_F12R2_FB2_Msk                               /*!<Filter bit 2 */
#define CAN_F12R2_FB3_Pos      (3U)                                            
#define CAN_F12R2_FB3_Msk      (0x1UL << CAN_F12R2_FB3_Pos)                     /*!< 0x00000008 */
#define CAN_F12R2_FB3          CAN_F12R2_FB3_Msk                               /*!<Filter bit 3 */
#define CAN_F12R2_FB4_Pos      (4U)                                            
#define CAN_F12R2_FB4_Msk      (0x1UL << CAN_F12R2_FB4_Pos)                     /*!< 0x00000010 */
#define CAN_F12R2_FB4          CAN_F12R2_FB4_Msk                               /*!<Filter bit 4 */
#define CAN_F12R2_FB5_Pos      (5U)                                            
#define CAN_F12R2_FB5_Msk      (0x1UL << CAN_F12R2_FB5_Pos)                     /*!< 0x00000020 */
#define CAN_F12R2_FB5          CAN_F12R2_FB5_Msk                               /*!<Filter bit 5 */
#define CAN_F12R2_FB6_Pos      (6U)                                            
#define CAN_F12R2_FB6_Msk      (0x1UL << CAN_F12R2_FB6_Pos)                     /*!< 0x00000040 */
#define CAN_F12R2_FB6          CAN_F12R2_FB6_Msk                               /*!<Filter bit 6 */
#define CAN_F12R2_FB7_Pos      (7U)                                            
#define CAN_F12R2_FB7_Msk      (0x1UL << CAN_F12R2_FB7_Pos)                     /*!< 0x00000080 */
#define CAN_F12R2_FB7          CAN_F12R2_FB7_Msk                               /*!<Filter bit 7 */
#define CAN_F12R2_FB8_Pos      (8U)                                            
#define CAN_F12R2_FB8_Msk      (0x1UL << CAN_F12R2_FB8_Pos)                     /*!< 0x00000100 */
#define CAN_F12R2_FB8          CAN_F12R2_FB8_Msk                               /*!<Filter bit 8 */
#define CAN_F12R2_FB9_Pos      (9U)                                            
#define CAN_F12R2_FB9_Msk      (0x1UL << CAN_F12R2_FB9_Pos)                     /*!< 0x00000200 */
#define CAN_F12R2_FB9          CAN_F12R2_FB9_Msk                               /*!<Filter bit 9 */
#define CAN_F12R2_FB10_Pos     (10U)                                           
#define CAN_F12R2_FB10_Msk     (0x1UL << CAN_F12R2_FB10_Pos)                    /*!< 0x00000400 */
#define CAN_F12R2_FB10         CAN_F12R2_FB10_Msk                              /*!<Filter bit 10 */
#define CAN_F12R2_FB11_Pos     (11U)                                           
#define CAN_F12R2_FB11_Msk     (0x1UL << CAN_F12R2_FB11_Pos)                    /*!< 0x00000800 */
#define CAN_F12R2_FB11         CAN_F12R2_FB11_Msk                              /*!<Filter bit 11 */
#define CAN_F12R2_FB12_Pos     (12U)                                           
#define CAN_F12R2_FB12_Msk     (0x1UL << CAN_F12R2_FB12_Pos)                    /*!< 0x00001000 */
#define CAN_F12R2_FB12         CAN_F12R2_FB12_Msk                              /*!<Filter bit 12 */
#define CAN_F12R2_FB13_Pos     (13U)                                           
#define CAN_F12R2_FB13_Msk     (0x1UL << CAN_F12R2_FB13_Pos)                    /*!< 0x00002000 */
#define CAN_F12R2_FB13         CAN_F12R2_FB13_Msk                              /*!<Filter bit 13 */
#define CAN_F12R2_FB14_Pos     (14U)                                           
#define CAN_F12R2_FB14_Msk     (0x1UL << CAN_F12R2_FB14_Pos)                    /*!< 0x00004000 */
#define CAN_F12R2_FB14         CAN_F12R2_FB14_Msk                              /*!<Filter bit 14 */
#define CAN_F12R2_FB15_Pos     (15U)                                           
#define CAN_F12R2_FB15_Msk     (0x1UL << CAN_F12R2_FB15_Pos)                    /*!< 0x00008000 */
#define CAN_F12R2_FB15         CAN_F12R2_FB15_Msk                              /*!<Filter bit 15 */
#define CAN_F12R2_FB16_Pos     (16U)                                           
#define CAN_F12R2_FB16_Msk     (0x1UL << CAN_F12R2_FB16_Pos)                    /*!< 0x00010000 */
#define CAN_F12R2_FB16         CAN_F12R2_FB16_Msk                              /*!<Filter bit 16 */
#define CAN_F12R2_FB17_Pos     (17U)                                           
#define CAN_F12R2_FB17_Msk     (0x1UL << CAN_F12R2_FB17_Pos)                    /*!< 0x00020000 */
#define CAN_F12R2_FB17         CAN_F12R2_FB17_Msk                              /*!<Filter bit 17 */
#define CAN_F12R2_FB18_Pos     (18U)                                           
#define CAN_F12R2_FB18_Msk     (0x1UL << CAN_F12R2_FB18_Pos)                    /*!< 0x00040000 */
#define CAN_F12R2_FB18         CAN_F12R2_FB18_Msk                              /*!<Filter bit 18 */
#define CAN_F12R2_FB19_Pos     (19U)                                           
#define CAN_F12R2_FB19_Msk     (0x1UL << CAN_F12R2_FB19_Pos)                    /*!< 0x00080000 */
#define CAN_F12R2_FB19         CAN_F12R2_FB19_Msk                              /*!<Filter bit 19 */
#define CAN_F12R2_FB20_Pos     (20U)                                           
#define CAN_F12R2_FB20_Msk     (0x1UL << CAN_F12R2_FB20_Pos)                    /*!< 0x00100000 */
#define CAN_F12R2_FB20         CAN_F12R2_FB20_Msk                              /*!<Filter bit 20 */
#define CAN_F12R2_FB21_Pos     (21U)                                           
#define CAN_F12R2_FB21_Msk     (0x1UL << CAN_F12R2_FB21_Pos)                    /*!< 0x00200000 */
#define CAN_F12R2_FB21         CAN_F12R2_FB21_Msk                              /*!<Filter bit 21 */
#define CAN_F12R2_FB22_Pos     (22U)                                           
#define CAN_F12R2_FB22_Msk     (0x1UL << CAN_F12R2_FB22_Pos)                    /*!< 0x00400000 */
#define CAN_F12R2_FB22         CAN_F12R2_FB22_Msk                              /*!<Filter bit 22 */
#define CAN_F12R2_FB23_Pos     (23U)                                           
#define CAN_F12R2_FB23_Msk     (0x1UL << CAN_F12R2_FB23_Pos)                    /*!< 0x00800000 */
#define CAN_F12R2_FB23         CAN_F12R2_FB23_Msk                              /*!<Filter bit 23 */
#define CAN_F12R2_FB24_Pos     (24U)                                           
#define CAN_F12R2_FB24_Msk     (0x1UL << CAN_F12R2_FB24_Pos)                    /*!< 0x01000000 */
#define CAN_F12R2_FB24         CAN_F12R2_FB24_Msk                              /*!<Filter bit 24 */
#define CAN_F12R2_FB25_Pos     (25U)                                           
#define CAN_F12R2_FB25_Msk     (0x1UL << CAN_F12R2_FB25_Pos)                    /*!< 0x02000000 */
#define CAN_F12R2_FB25         CAN_F12R2_FB25_Msk                              /*!<Filter bit 25 */
#define CAN_F12R2_FB26_Pos     (26U)                                           
#define CAN_F12R2_FB26_Msk     (0x1UL << CAN_F12R2_FB26_Pos)                    /*!< 0x04000000 */
#define CAN_F12R2_FB26         CAN_F12R2_FB26_Msk                              /*!<Filter bit 26 */
#define CAN_F12R2_FB27_Pos     (27U)                                           
#define CAN_F12R2_FB27_Msk     (0x1UL << CAN_F12R2_FB27_Pos)                    /*!< 0x08000000 */
#define CAN_F12R2_FB27         CAN_F12R2_FB27_Msk                              /*!<Filter bit 27 */
#define CAN_F12R2_FB28_Pos     (28U)                                           
#define CAN_F12R2_FB28_Msk     (0x1UL << CAN_F12R2_FB28_Pos)                    /*!< 0x10000000 */
#define CAN_F12R2_FB28         CAN_F12R2_FB28_Msk                              /*!<Filter bit 28 */
#define CAN_F12R2_FB29_Pos     (29U)                                           
#define CAN_F12R2_FB29_Msk     (0x1UL << CAN_F12R2_FB29_Pos)                    /*!< 0x20000000 */
#define CAN_F12R2_FB29         CAN_F12R2_FB29_Msk                              /*!<Filter bit 29 */
#define CAN_F12R2_FB30_Pos     (30U)                                           
#define CAN_F12R2_FB30_Msk     (0x1UL << CAN_F12R2_FB30_Pos)                    /*!< 0x40000000 */
#define CAN_F12R2_FB30         CAN_F12R2_FB30_Msk                              /*!<Filter bit 30 */
#define CAN_F12R2_FB31_Pos     (31U)                                           
#define CAN_F12R2_FB31_Msk     (0x1UL << CAN_F12R2_FB31_Pos)                    /*!< 0x80000000 */
#define CAN_F12R2_FB31         CAN_F12R2_FB31_Msk                              /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define CAN_F13R2_FB0_Pos      (0U)                                            
#define CAN_F13R2_FB0_Msk      (0x1UL << CAN_F13R2_FB0_Pos)                     /*!< 0x00000001 */
#define CAN_F13R2_FB0          CAN_F13R2_FB0_Msk                               /*!<Filter bit 0 */
#define CAN_F13R2_FB1_Pos      (1U)                                            
#define CAN_F13R2_FB1_Msk      (0x1UL << CAN_F13R2_FB1_Pos)                     /*!< 0x00000002 */
#define CAN_F13R2_FB1          CAN_F13R2_FB1_Msk                               /*!<Filter bit 1 */
#define CAN_F13R2_FB2_Pos      (2U)                                            
#define CAN_F13R2_FB2_Msk      (0x1UL << CAN_F13R2_FB2_Pos)                     /*!< 0x00000004 */
#define CAN_F13R2_FB2          CAN_F13R2_FB2_Msk                               /*!<Filter bit 2 */
#define CAN_F13R2_FB3_Pos      (3U)                                            
#define CAN_F13R2_FB3_Msk      (0x1UL << CAN_F13R2_FB3_Pos)                     /*!< 0x00000008 */
#define CAN_F13R2_FB3          CAN_F13R2_FB3_Msk                               /*!<Filter bit 3 */
#define CAN_F13R2_FB4_Pos      (4U)                                            
#define CAN_F13R2_FB4_Msk      (0x1UL << CAN_F13R2_FB4_Pos)                     /*!< 0x00000010 */
#define CAN_F13R2_FB4          CAN_F13R2_FB4_Msk                               /*!<Filter bit 4 */
#define CAN_F13R2_FB5_Pos      (5U)                                            
#define CAN_F13R2_FB5_Msk      (0x1UL << CAN_F13R2_FB5_Pos)                     /*!< 0x00000020 */
#define CAN_F13R2_FB5          CAN_F13R2_FB5_Msk                               /*!<Filter bit 5 */
#define CAN_F13R2_FB6_Pos      (6U)                                            
#define CAN_F13R2_FB6_Msk      (0x1UL << CAN_F13R2_FB6_Pos)                     /*!< 0x00000040 */
#define CAN_F13R2_FB6          CAN_F13R2_FB6_Msk                               /*!<Filter bit 6 */
#define CAN_F13R2_FB7_Pos      (7U)                                            
#define CAN_F13R2_FB7_Msk      (0x1UL << CAN_F13R2_FB7_Pos)                     /*!< 0x00000080 */
#define CAN_F13R2_FB7          CAN_F13R2_FB7_Msk                               /*!<Filter bit 7 */
#define CAN_F13R2_FB8_Pos      (8U)                                            
#define CAN_F13R2_FB8_Msk      (0x1UL << CAN_F13R2_FB8_Pos)                     /*!< 0x00000100 */
#define CAN_F13R2_FB8          CAN_F13R2_FB8_Msk                               /*!<Filter bit 8 */
#define CAN_F13R2_FB9_Pos      (9U)                                            
#define CAN_F13R2_FB9_Msk      (0x1UL << CAN_F13R2_FB9_Pos)                     /*!< 0x00000200 */
#define CAN_F13R2_FB9          CAN_F13R2_FB9_Msk                               /*!<Filter bit 9 */
#define CAN_F13R2_FB10_Pos     (10U)                                           
#define CAN_F13R2_FB10_Msk     (0x1UL << CAN_F13R2_FB10_Pos)                    /*!< 0x00000400 */
#define CAN_F13R2_FB10         CAN_F13R2_FB10_Msk                              /*!<Filter bit 10 */
#define CAN_F13R2_FB11_Pos     (11U)                                           
#define CAN_F13R2_FB11_Msk     (0x1UL << CAN_F13R2_FB11_Pos)                    /*!< 0x00000800 */
#define CAN_F13R2_FB11         CAN_F13R2_FB11_Msk                              /*!<Filter bit 11 */
#define CAN_F13R2_FB12_Pos     (12U)                                           
#define CAN_F13R2_FB12_Msk     (0x1UL << CAN_F13R2_FB12_Pos)                    /*!< 0x00001000 */
#define CAN_F13R2_FB12         CAN_F13R2_FB12_Msk                              /*!<Filter bit 12 */
#define CAN_F13R2_FB13_Pos     (13U)                                           
#define CAN_F13R2_FB13_Msk     (0x1UL << CAN_F13R2_FB13_Pos)                    /*!< 0x00002000 */
#define CAN_F13R2_FB13         CAN_F13R2_FB13_Msk                              /*!<Filter bit 13 */
#define CAN_F13R2_FB14_Pos     (14U)                                           
#define CAN_F13R2_FB14_Msk     (0x1UL << CAN_F13R2_FB14_Pos)                    /*!< 0x00004000 */
#define CAN_F13R2_FB14         CAN_F13R2_FB14_Msk                              /*!<Filter bit 14 */
#define CAN_F13R2_FB15_Pos     (15U)                                           
#define CAN_F13R2_FB15_Msk     (0x1UL << CAN_F13R2_FB15_Pos)                    /*!< 0x00008000 */
#define CAN_F13R2_FB15         CAN_F13R2_FB15_Msk                              /*!<Filter bit 15 */
#define CAN_F13R2_FB16_Pos     (16U)                                           
#define CAN_F13R2_FB16_Msk     (0x1UL << CAN_F13R2_FB16_Pos)                    /*!< 0x00010000 */
#define CAN_F13R2_FB16         CAN_F13R2_FB16_Msk                              /*!<Filter bit 16 */
#define CAN_F13R2_FB17_Pos     (17U)                                           
#define CAN_F13R2_FB17_Msk     (0x1UL << CAN_F13R2_FB17_Pos)                    /*!< 0x00020000 */
#define CAN_F13R2_FB17         CAN_F13R2_FB17_Msk                              /*!<Filter bit 17 */
#define CAN_F13R2_FB18_Pos     (18U)                                           
#define CAN_F13R2_FB18_Msk     (0x1UL << CAN_F13R2_FB18_Pos)                    /*!< 0x00040000 */
#define CAN_F13R2_FB18         CAN_F13R2_FB18_Msk                              /*!<Filter bit 18 */
#define CAN_F13R2_FB19_Pos     (19U)                                           
#define CAN_F13R2_FB19_Msk     (0x1UL << CAN_F13R2_FB19_Pos)                    /*!< 0x00080000 */
#define CAN_F13R2_FB19         CAN_F13R2_FB19_Msk                              /*!<Filter bit 19 */
#define CAN_F13R2_FB20_Pos     (20U)                                           
#define CAN_F13R2_FB20_Msk     (0x1UL << CAN_F13R2_FB20_Pos)                    /*!< 0x00100000 */
#define CAN_F13R2_FB20         CAN_F13R2_FB20_Msk                              /*!<Filter bit 20 */
#define CAN_F13R2_FB21_Pos     (21U)                                           
#define CAN_F13R2_FB21_Msk     (0x1UL << CAN_F13R2_FB21_Pos)                    /*!< 0x00200000 */
#define CAN_F13R2_FB21         CAN_F13R2_FB21_Msk                              /*!<Filter bit 21 */
#define CAN_F13R2_FB22_Pos     (22U)                                           
#define CAN_F13R2_FB22_Msk     (0x1UL << CAN_F13R2_FB22_Pos)                    /*!< 0x00400000 */
#define CAN_F13R2_FB22         CAN_F13R2_FB22_Msk                              /*!<Filter bit 22 */
#define CAN_F13R2_FB23_Pos     (23U)                                           
#define CAN_F13R2_FB23_Msk     (0x1UL << CAN_F13R2_FB23_Pos)                    /*!< 0x00800000 */
#define CAN_F13R2_FB23         CAN_F13R2_FB23_Msk                              /*!<Filter bit 23 */
#define CAN_F13R2_FB24_Pos     (24U)                                           
#define CAN_F13R2_FB24_Msk     (0x1UL << CAN_F13R2_FB24_Pos)                    /*!< 0x01000000 */
#define CAN_F13R2_FB24         CAN_F13R2_FB24_Msk                              /*!<Filter bit 24 */
#define CAN_F13R2_FB25_Pos     (25U)                                           
#define CAN_F13R2_FB25_Msk     (0x1UL << CAN_F13R2_FB25_Pos)                    /*!< 0x02000000 */
#define CAN_F13R2_FB25         CAN_F13R2_FB25_Msk                              /*!<Filter bit 25 */
#define CAN_F13R2_FB26_Pos     (26U)                                           
#define CAN_F13R2_FB26_Msk     (0x1UL << CAN_F13R2_FB26_Pos)                    /*!< 0x04000000 */
#define CAN_F13R2_FB26         CAN_F13R2_FB26_Msk                              /*!<Filter bit 26 */
#define CAN_F13R2_FB27_Pos     (27U)                                           
#define CAN_F13R2_FB27_Msk     (0x1UL << CAN_F13R2_FB27_Pos)                    /*!< 0x08000000 */
#define CAN_F13R2_FB27         CAN_F13R2_FB27_Msk                              /*!<Filter bit 27 */
#define CAN_F13R2_FB28_Pos     (28U)                                           
#define CAN_F13R2_FB28_Msk     (0x1UL << CAN_F13R2_FB28_Pos)                    /*!< 0x10000000 */
#define CAN_F13R2_FB28         CAN_F13R2_FB28_Msk                              /*!<Filter bit 28 */
#define CAN_F13R2_FB29_Pos     (29U)                                           
#define CAN_F13R2_FB29_Msk     (0x1UL << CAN_F13R2_FB29_Pos)                    /*!< 0x20000000 */
#define CAN_F13R2_FB29         CAN_F13R2_FB29_Msk                              /*!<Filter bit 29 */
#define CAN_F13R2_FB30_Pos     (30U)                                           
#define CAN_F13R2_FB30_Msk     (0x1UL << CAN_F13R2_FB30_Pos)                    /*!< 0x40000000 */
#define CAN_F13R2_FB30         CAN_F13R2_FB30_Msk                              /*!<Filter bit 30 */
#define CAN_F13R2_FB31_Pos     (31U)                                           
#define CAN_F13R2_FB31_Msk     (0x1UL << CAN_F13R2_FB31_Pos)                    /*!< 0x80000000 */
#define CAN_F13R2_FB31         CAN_F13R2_FB31_Msk                              /*!<Filter bit 31 */

/******************************************************************************/
/*                                                                            */
/*                          CRC calculation unit                              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR_Pos       (0U)                                               
#define CRC_DR_DR_Msk       (0xFFFFFFFFUL << CRC_DR_DR_Pos)                     /*!< 0xFFFFFFFF */
#define CRC_DR_DR           CRC_DR_DR_Msk                                      /*!< Data register bits */


/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR_Pos     (0U)                                               
#define CRC_IDR_IDR_Msk     (0xFFUL << CRC_IDR_IDR_Pos)                         /*!< 0x000000FF */
#define CRC_IDR_IDR         CRC_IDR_IDR_Msk                                    /*!< General-purpose 8-bit data register bits */


/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET_Pos    (0U)                                               
#define CRC_CR_RESET_Msk    (0x1UL << CRC_CR_RESET_Pos)                         /*!< 0x00000001 */
#define CRC_CR_RESET        CRC_CR_RESET_Msk                                   /*!< RESET bit */

/******************************************************************************/
/*                                                                            */
/*                      Digital to Analog Converter                           */
/*                                                                            */
/******************************************************************************/
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define DAC_CHANNEL2_SUPPORT                                    /*!< DAC feature available only on specific devices: availability of DAC channel 2 */
/********************  Bit definition for DAC_CR register  ********************/
#define DAC_CR_EN1_Pos              (0U)                                       
#define DAC_CR_EN1_Msk              (0x1UL << DAC_CR_EN1_Pos)                   /*!< 0x00000001 */
#define DAC_CR_EN1                  DAC_CR_EN1_Msk                             /*!<DAC channel1 enable */
#define DAC_CR_BOFF1_Pos            (1U)                                       
#define DAC_CR_BOFF1_Msk            (0x1UL << DAC_CR_BOFF1_Pos)                 /*!< 0x00000002 */
#define DAC_CR_BOFF1                DAC_CR_BOFF1_Msk                           /*!<DAC channel1 output buffer disable */
#define DAC_CR_TEN1_Pos             (2U)                                       
#define DAC_CR_TEN1_Msk             (0x1UL << DAC_CR_TEN1_Pos)                  /*!< 0x00000004 */
#define DAC_CR_TEN1                 DAC_CR_TEN1_Msk                            /*!<DAC channel1 Trigger enable */

#define DAC_CR_TSEL1_Pos            (3U)                                       
#define DAC_CR_TSEL1_Msk            (0x7UL << DAC_CR_TSEL1_Pos)                 /*!< 0x00000038 */
#define DAC_CR_TSEL1                DAC_CR_TSEL1_Msk                           /*!<TSEL1[2:0] (DAC channel1 Trigger selection) */
#define DAC_CR_TSEL1_0              (0x1UL << DAC_CR_TSEL1_Pos)                 /*!< 0x00000008 */
#define DAC_CR_TSEL1_1              (0x2UL << DAC_CR_TSEL1_Pos)                 /*!< 0x00000010 */
#define DAC_CR_TSEL1_2              (0x4UL << DAC_CR_TSEL1_Pos)                 /*!< 0x00000020 */

#define DAC_CR_WAVE1_Pos            (6U)                                       
#define DAC_CR_WAVE1_Msk            (0x3UL << DAC_CR_WAVE1_Pos)                 /*!< 0x000000C0 */
#define DAC_CR_WAVE1                DAC_CR_WAVE1_Msk                           /*!<WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
#define DAC_CR_WAVE1_0              (0x1UL << DAC_CR_WAVE1_Pos)                 /*!< 0x00000040 */
#define DAC_CR_WAVE1_1              (0x2UL << DAC_CR_WAVE1_Pos)                 /*!< 0x00000080 */

#define DAC_CR_MAMP1_Pos            (8U)                                       
#define DAC_CR_MAMP1_Msk            (0xFUL << DAC_CR_MAMP1_Pos)                 /*!< 0x00000F00 */
#define DAC_CR_MAMP1                DAC_CR_MAMP1_Msk                           /*!<MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
#define DAC_CR_MAMP1_0              (0x1UL << DAC_CR_MAMP1_Pos)                 /*!< 0x00000100 */
#define DAC_CR_MAMP1_1              (0x2UL << DAC_CR_MAMP1_Pos)                 /*!< 0x00000200 */
#define DAC_CR_MAMP1_2              (0x4UL << DAC_CR_MAMP1_Pos)                 /*!< 0x00000400 */
#define DAC_CR_MAMP1_3              (0x8UL << DAC_CR_MAMP1_Pos)                 /*!< 0x00000800 */

#define DAC_CR_DMAEN1_Pos           (12U)                                      
#define DAC_CR_DMAEN1_Msk           (0x1UL << DAC_CR_DMAEN1_Pos)                /*!< 0x00001000 */
#define DAC_CR_DMAEN1               DAC_CR_DMAEN1_Msk                          /*!<DAC channel1 DMA enable */
#define DAC_CR_DMAUDRIE1_Pos        (13U)                                      
#define DAC_CR_DMAUDRIE1_Msk        (0x1UL << DAC_CR_DMAUDRIE1_Pos)             /*!< 0x00002000 */
#define DAC_CR_DMAUDRIE1            DAC_CR_DMAUDRIE1_Msk                       /*!<DAC channel1 DMA underrun interrupt enable*/
#define DAC_CR_EN2_Pos              (16U)                                      
#define DAC_CR_EN2_Msk              (0x1UL << DAC_CR_EN2_Pos)                   /*!< 0x00010000 */
#define DAC_CR_EN2                  DAC_CR_EN2_Msk                             /*!<DAC channel2 enable */
#define DAC_CR_BOFF2_Pos            (17U)                                      
#define DAC_CR_BOFF2_Msk            (0x1UL << DAC_CR_BOFF2_Pos)                 /*!< 0x00020000 */
#define DAC_CR_BOFF2                DAC_CR_BOFF2_Msk                           /*!<DAC channel2 output buffer disable */
#define DAC_CR_TEN2_Pos             (18U)                                      
#define DAC_CR_TEN2_Msk             (0x1UL << DAC_CR_TEN2_Pos)                  /*!< 0x00040000 */
#define DAC_CR_TEN2                 DAC_CR_TEN2_Msk                            /*!<DAC channel2 Trigger enable */

#define DAC_CR_TSEL2_Pos            (19U)                                      
#define DAC_CR_TSEL2_Msk            (0x7UL << DAC_CR_TSEL2_Pos)                 /*!< 0x00380000 */
#define DAC_CR_TSEL2                DAC_CR_TSEL2_Msk                           /*!<TSEL2[2:0] (DAC channel2 Trigger selection) */
#define DAC_CR_TSEL2_0              (0x1UL << DAC_CR_TSEL2_Pos)                 /*!< 0x00080000 */
#define DAC_CR_TSEL2_1              (0x2UL << DAC_CR_TSEL2_Pos)                 /*!< 0x00100000 */
#define DAC_CR_TSEL2_2              (0x4UL << DAC_CR_TSEL2_Pos)                 /*!< 0x00200000 */

#define DAC_CR_WAVE2_Pos            (22U)                                      
#define DAC_CR_WAVE2_Msk            (0x3UL << DAC_CR_WAVE2_Pos)                 /*!< 0x00C00000 */
#define DAC_CR_WAVE2                DAC_CR_WAVE2_Msk                           /*!<WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define DAC_CR_WAVE2_0              (0x1UL << DAC_CR_WAVE2_Pos)                 /*!< 0x00400000 */
#define DAC_CR_WAVE2_1              (0x2UL << DAC_CR_WAVE2_Pos)                 /*!< 0x00800000 */

#define DAC_CR_MAMP2_Pos            (24U)                                      
#define DAC_CR_MAMP2_Msk            (0xFUL << DAC_CR_MAMP2_Pos)                 /*!< 0x0F000000 */
#define DAC_CR_MAMP2                DAC_CR_MAMP2_Msk                           /*!<MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define DAC_CR_MAMP2_0              (0x1UL << DAC_CR_MAMP2_Pos)                 /*!< 0x01000000 */
#define DAC_CR_MAMP2_1              (0x2UL << DAC_CR_MAMP2_Pos)                 /*!< 0x02000000 */
#define DAC_CR_MAMP2_2              (0x4UL << DAC_CR_MAMP2_Pos)                 /*!< 0x04000000 */
#define DAC_CR_MAMP2_3              (0x8UL << DAC_CR_MAMP2_Pos)                 /*!< 0x08000000 */

#define DAC_CR_DMAEN2_Pos           (28U)                                      
#define DAC_CR_DMAEN2_Msk           (0x1UL << DAC_CR_DMAEN2_Pos)                /*!< 0x10000000 */
#define DAC_CR_DMAEN2               DAC_CR_DMAEN2_Msk                          /*!<DAC channel2 DMA enabled */
#define DAC_CR_DMAUDRIE2_Pos        (29U)                                      
#define DAC_CR_DMAUDRIE2_Msk        (0x1UL << DAC_CR_DMAUDRIE2_Pos)             /*!< 0x20000000 */
#define DAC_CR_DMAUDRIE2            DAC_CR_DMAUDRIE2_Msk                       /*!<DAC channel2 DMA underrun interrupt enable*/

/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define DAC_SWTRIGR_SWTRIG1_Pos     (0U)                                       
#define DAC_SWTRIGR_SWTRIG1_Msk     (0x1UL << DAC_SWTRIGR_SWTRIG1_Pos)          /*!< 0x00000001 */
#define DAC_SWTRIGR_SWTRIG1         DAC_SWTRIGR_SWTRIG1_Msk                    /*!<DAC channel1 software trigger */
#define DAC_SWTRIGR_SWTRIG2_Pos     (1U)                                       
#define DAC_SWTRIGR_SWTRIG2_Msk     (0x1UL << DAC_SWTRIGR_SWTRIG2_Pos)          /*!< 0x00000002 */
#define DAC_SWTRIGR_SWTRIG2         DAC_SWTRIGR_SWTRIG2_Msk                    /*!<DAC channel2 software trigger */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define DAC_DHR12R1_DACC1DHR_Pos    (0U)                                       
#define DAC_DHR12R1_DACC1DHR_Msk    (0xFFFUL << DAC_DHR12R1_DACC1DHR_Pos)       /*!< 0x00000FFF */
#define DAC_DHR12R1_DACC1DHR        DAC_DHR12R1_DACC1DHR_Msk                   /*!<DAC channel1 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define DAC_DHR12L1_DACC1DHR_Pos    (4U)                                       
#define DAC_DHR12L1_DACC1DHR_Msk    (0xFFFUL << DAC_DHR12L1_DACC1DHR_Pos)       /*!< 0x0000FFF0 */
#define DAC_DHR12L1_DACC1DHR        DAC_DHR12L1_DACC1DHR_Msk                   /*!<DAC channel1 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define DAC_DHR8R1_DACC1DHR_Pos     (0U)                                       
#define DAC_DHR8R1_DACC1DHR_Msk     (0xFFUL << DAC_DHR8R1_DACC1DHR_Pos)         /*!< 0x000000FF */
#define DAC_DHR8R1_DACC1DHR         DAC_DHR8R1_DACC1DHR_Msk                    /*!<DAC channel1 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define DAC_DHR12R2_DACC2DHR_Pos    (0U)                                       
#define DAC_DHR12R2_DACC2DHR_Msk    (0xFFFUL << DAC_DHR12R2_DACC2DHR_Pos)       /*!< 0x00000FFF */
#define DAC_DHR12R2_DACC2DHR        DAC_DHR12R2_DACC2DHR_Msk                   /*!<DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define DAC_DHR12L2_DACC2DHR_Pos    (4U)                                       
#define DAC_DHR12L2_DACC2DHR_Msk    (0xFFFUL << DAC_DHR12L2_DACC2DHR_Pos)       /*!< 0x0000FFF0 */
#define DAC_DHR12L2_DACC2DHR        DAC_DHR12L2_DACC2DHR_Msk                   /*!<DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define DAC_DHR8R2_DACC2DHR_Pos     (0U)                                       
#define DAC_DHR8R2_DACC2DHR_Msk     (0xFFUL << DAC_DHR8R2_DACC2DHR_Pos)         /*!< 0x000000FF */
#define DAC_DHR8R2_DACC2DHR         DAC_DHR8R2_DACC2DHR_Msk                    /*!<DAC channel2 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define DAC_DHR12RD_DACC1DHR_Pos    (0U)                                       
#define DAC_DHR12RD_DACC1DHR_Msk    (0xFFFUL << DAC_DHR12RD_DACC1DHR_Pos)       /*!< 0x00000FFF */
#define DAC_DHR12RD_DACC1DHR        DAC_DHR12RD_DACC1DHR_Msk                   /*!<DAC channel1 12-bit Right aligned data */
#define DAC_DHR12RD_DACC2DHR_Pos    (16U)                                      
#define DAC_DHR12RD_DACC2DHR_Msk    (0xFFFUL << DAC_DHR12RD_DACC2DHR_Pos)       /*!< 0x0FFF0000 */
#define DAC_DHR12RD_DACC2DHR        DAC_DHR12RD_DACC2DHR_Msk                   /*!<DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define DAC_DHR12LD_DACC1DHR_Pos    (4U)                                       
#define DAC_DHR12LD_DACC1DHR_Msk    (0xFFFUL << DAC_DHR12LD_DACC1DHR_Pos)       /*!< 0x0000FFF0 */
#define DAC_DHR12LD_DACC1DHR        DAC_DHR12LD_DACC1DHR_Msk                   /*!<DAC channel1 12-bit Left aligned data */
#define DAC_DHR12LD_DACC2DHR_Pos    (20U)                                      
#define DAC_DHR12LD_DACC2DHR_Msk    (0xFFFUL << DAC_DHR12LD_DACC2DHR_Pos)       /*!< 0xFFF00000 */
#define DAC_DHR12LD_DACC2DHR        DAC_DHR12LD_DACC2DHR_Msk                   /*!<DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8RD register  ******************/
#define DAC_DHR8RD_DACC1DHR_Pos     (0U)                                       
#define DAC_DHR8RD_DACC1DHR_Msk     (0xFFUL << DAC_DHR8RD_DACC1DHR_Pos)         /*!< 0x000000FF */
#define DAC_DHR8RD_DACC1DHR         DAC_DHR8RD_DACC1DHR_Msk                    /*!<DAC channel1 8-bit Right aligned data */
#define DAC_DHR8RD_DACC2DHR_Pos     (8U)                                       
#define DAC_DHR8RD_DACC2DHR_Msk     (0xFFUL << DAC_DHR8RD_DACC2DHR_Pos)         /*!< 0x0000FF00 */
#define DAC_DHR8RD_DACC2DHR         DAC_DHR8RD_DACC2DHR_Msk                    /*!<DAC channel2 8-bit Right aligned data */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define DAC_DOR1_DACC1DOR_Pos       (0U)                                       
#define DAC_DOR1_DACC1DOR_Msk       (0xFFFUL << DAC_DOR1_DACC1DOR_Pos)          /*!< 0x00000FFF */
#define DAC_DOR1_DACC1DOR           DAC_DOR1_DACC1DOR_Msk                      /*!<DAC channel1 data output */

/*******************  Bit definition for DAC_DOR2 register  *******************/
#define DAC_DOR2_DACC2DOR_Pos       (0U)                                       
#define DAC_DOR2_DACC2DOR_Msk       (0xFFFUL << DAC_DOR2_DACC2DOR_Pos)          /*!< 0x00000FFF */
#define DAC_DOR2_DACC2DOR           DAC_DOR2_DACC2DOR_Msk                      /*!<DAC channel2 data output */

/********************  Bit definition for DAC_SR register  ********************/
#define DAC_SR_DMAUDR1_Pos          (13U)                                      
#define DAC_SR_DMAUDR1_Msk          (0x1UL << DAC_SR_DMAUDR1_Pos)               /*!< 0x00002000 */
#define DAC_SR_DMAUDR1              DAC_SR_DMAUDR1_Msk                         /*!<DAC channel1 DMA underrun flag */
#define DAC_SR_DMAUDR2_Pos          (29U)                                      
#define DAC_SR_DMAUDR2_Msk          (0x1UL << DAC_SR_DMAUDR2_Pos)               /*!< 0x20000000 */
#define DAC_SR_DMAUDR2              DAC_SR_DMAUDR2_Msk                         /*!<DAC channel2 DMA underrun flag */

/******************************************************************************/
/*                                                                            */
/*                                    DCMI                                    */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DCMI_CR register  ******************/
#define DCMI_CR_CAPTURE_Pos        (0U)                                        
#define DCMI_CR_CAPTURE_Msk        (0x1UL << DCMI_CR_CAPTURE_Pos)               /*!< 0x00000001 */
#define DCMI_CR_CAPTURE            DCMI_CR_CAPTURE_Msk                         
#define DCMI_CR_CM_Pos             (1U)                                        
#define DCMI_CR_CM_Msk             (0x1UL << DCMI_CR_CM_Pos)                    /*!< 0x00000002 */
#define DCMI_CR_CM                 DCMI_CR_CM_Msk                              
#define DCMI_CR_CROP_Pos           (2U)                                        
#define DCMI_CR_CROP_Msk           (0x1UL << DCMI_CR_CROP_Pos)                  /*!< 0x00000004 */
#define DCMI_CR_CROP               DCMI_CR_CROP_Msk                            
#define DCMI_CR_JPEG_Pos           (3U)                                        
#define DCMI_CR_JPEG_Msk           (0x1UL << DCMI_CR_JPEG_Pos)                  /*!< 0x00000008 */
#define DCMI_CR_JPEG               DCMI_CR_JPEG_Msk                            
#define DCMI_CR_ESS_Pos            (4U)                                        
#define DCMI_CR_ESS_Msk            (0x1UL << DCMI_CR_ESS_Pos)                   /*!< 0x00000010 */
#define DCMI_CR_ESS                DCMI_CR_ESS_Msk                             
#define DCMI_CR_PCKPOL_Pos         (5U)                                        
#define DCMI_CR_PCKPOL_Msk         (0x1UL << DCMI_CR_PCKPOL_Pos)                /*!< 0x00000020 */
#define DCMI_CR_PCKPOL             DCMI_CR_PCKPOL_Msk                          
#define DCMI_CR_HSPOL_Pos          (6U)                                        
#define DCMI_CR_HSPOL_Msk          (0x1UL << DCMI_CR_HSPOL_Pos)                 /*!< 0x00000040 */
#define DCMI_CR_HSPOL              DCMI_CR_HSPOL_Msk                           
#define DCMI_CR_VSPOL_Pos          (7U)                                        
#define DCMI_CR_VSPOL_Msk          (0x1UL << DCMI_CR_VSPOL_Pos)                 /*!< 0x00000080 */
#define DCMI_CR_VSPOL              DCMI_CR_VSPOL_Msk                           
#define DCMI_CR_FCRC_0             0x00000100U                                 
#define DCMI_CR_FCRC_1             0x00000200U                                 
#define DCMI_CR_EDM_0              0x00000400U                                 
#define DCMI_CR_EDM_1              0x00000800U                                 
#define DCMI_CR_CRE_Pos            (12U)                                       
#define DCMI_CR_CRE_Msk            (0x1UL << DCMI_CR_CRE_Pos)                   /*!< 0x00001000 */
#define DCMI_CR_CRE                DCMI_CR_CRE_Msk                             
#define DCMI_CR_ENABLE_Pos         (14U)                                       
#define DCMI_CR_ENABLE_Msk         (0x1UL << DCMI_CR_ENABLE_Pos)                /*!< 0x00004000 */
#define DCMI_CR_ENABLE             DCMI_CR_ENABLE_Msk                          

/********************  Bits definition for DCMI_SR register  ******************/
#define DCMI_SR_HSYNC_Pos          (0U)                                        
#define DCMI_SR_HSYNC_Msk          (0x1UL << DCMI_SR_HSYNC_Pos)                 /*!< 0x00000001 */
#define DCMI_SR_HSYNC              DCMI_SR_HSYNC_Msk                           
#define DCMI_SR_VSYNC_Pos          (1U)                                        
#define DCMI_SR_VSYNC_Msk          (0x1UL << DCMI_SR_VSYNC_Pos)                 /*!< 0x00000002 */
#define DCMI_SR_VSYNC              DCMI_SR_VSYNC_Msk                           
#define DCMI_SR_FNE_Pos            (2U)                                        
#define DCMI_SR_FNE_Msk            (0x1UL << DCMI_SR_FNE_Pos)                   /*!< 0x00000004 */
#define DCMI_SR_FNE                DCMI_SR_FNE_Msk                             

/********************  Bits definition for DCMI_RIS register  *****************/
#define DCMI_RIS_FRAME_RIS_Pos     (0U)                                        
#define DCMI_RIS_FRAME_RIS_Msk     (0x1UL << DCMI_RIS_FRAME_RIS_Pos)            /*!< 0x00000001 */
#define DCMI_RIS_FRAME_RIS         DCMI_RIS_FRAME_RIS_Msk                      
#define DCMI_RIS_OVR_RIS_Pos       (1U)                                        
#define DCMI_RIS_OVR_RIS_Msk       (0x1UL << DCMI_RIS_OVR_RIS_Pos)              /*!< 0x00000002 */
#define DCMI_RIS_OVR_RIS           DCMI_RIS_OVR_RIS_Msk                        
#define DCMI_RIS_ERR_RIS_Pos       (2U)                                        
#define DCMI_RIS_ERR_RIS_Msk       (0x1UL << DCMI_RIS_ERR_RIS_Pos)              /*!< 0x00000004 */
#define DCMI_RIS_ERR_RIS           DCMI_RIS_ERR_RIS_Msk                        
#define DCMI_RIS_VSYNC_RIS_Pos     (3U)                                        
#define DCMI_RIS_VSYNC_RIS_Msk     (0x1UL << DCMI_RIS_VSYNC_RIS_Pos)            /*!< 0x00000008 */
#define DCMI_RIS_VSYNC_RIS         DCMI_RIS_VSYNC_RIS_Msk                      
#define DCMI_RIS_LINE_RIS_Pos      (4U)                                        
#define DCMI_RIS_LINE_RIS_Msk      (0x1UL << DCMI_RIS_LINE_RIS_Pos)             /*!< 0x00000010 */
#define DCMI_RIS_LINE_RIS          DCMI_RIS_LINE_RIS_Msk                       
/* Legacy defines */
#define DCMI_RISR_FRAME_RIS                  DCMI_RIS_FRAME_RIS
#define DCMI_RISR_OVR_RIS                    DCMI_RIS_OVR_RIS
#define DCMI_RISR_ERR_RIS                    DCMI_RIS_ERR_RIS
#define DCMI_RISR_VSYNC_RIS                  DCMI_RIS_VSYNC_RIS
#define DCMI_RISR_LINE_RIS                   DCMI_RIS_LINE_RIS
#define DCMI_RISR_OVF_RIS                    DCMI_RIS_OVR_RIS

/********************  Bits definition for DCMI_IER register  *****************/
#define DCMI_IER_FRAME_IE_Pos      (0U)                                        
#define DCMI_IER_FRAME_IE_Msk      (0x1UL << DCMI_IER_FRAME_IE_Pos)             /*!< 0x00000001 */
#define DCMI_IER_FRAME_IE          DCMI_IER_FRAME_IE_Msk                       
#define DCMI_IER_OVR_IE_Pos        (1U)                                        
#define DCMI_IER_OVR_IE_Msk        (0x1UL << DCMI_IER_OVR_IE_Pos)               /*!< 0x00000002 */
#define DCMI_IER_OVR_IE            DCMI_IER_OVR_IE_Msk                         
#define DCMI_IER_ERR_IE_Pos        (2U)                                        
#define DCMI_IER_ERR_IE_Msk        (0x1UL << DCMI_IER_ERR_IE_Pos)               /*!< 0x00000004 */
#define DCMI_IER_ERR_IE            DCMI_IER_ERR_IE_Msk                         
#define DCMI_IER_VSYNC_IE_Pos      (3U)                                        
#define DCMI_IER_VSYNC_IE_Msk      (0x1UL << DCMI_IER_VSYNC_IE_Pos)             /*!< 0x00000008 */
#define DCMI_IER_VSYNC_IE          DCMI_IER_VSYNC_IE_Msk                       
#define DCMI_IER_LINE_IE_Pos       (4U)                                        
#define DCMI_IER_LINE_IE_Msk       (0x1UL << DCMI_IER_LINE_IE_Pos)              /*!< 0x00000010 */
#define DCMI_IER_LINE_IE           DCMI_IER_LINE_IE_Msk                        
/* Legacy defines */
#define DCMI_IER_OVF_IE                      DCMI_IER_OVR_IE

/********************  Bits definition for DCMI_MIS register  *****************/
#define DCMI_MIS_FRAME_MIS_Pos     (0U)                                        
#define DCMI_MIS_FRAME_MIS_Msk     (0x1UL << DCMI_MIS_FRAME_MIS_Pos)            /*!< 0x00000001 */
#define DCMI_MIS_FRAME_MIS         DCMI_MIS_FRAME_MIS_Msk                      
#define DCMI_MIS_OVR_MIS_Pos       (1U)                                        
#define DCMI_MIS_OVR_MIS_Msk       (0x1UL << DCMI_MIS_OVR_MIS_Pos)              /*!< 0x00000002 */
#define DCMI_MIS_OVR_MIS           DCMI_MIS_OVR_MIS_Msk                        
#define DCMI_MIS_ERR_MIS_Pos       (2U)                                        
#define DCMI_MIS_ERR_MIS_Msk       (0x1UL << DCMI_MIS_ERR_MIS_Pos)              /*!< 0x00000004 */
#define DCMI_MIS_ERR_MIS           DCMI_MIS_ERR_MIS_Msk                        
#define DCMI_MIS_VSYNC_MIS_Pos     (3U)                                        
#define DCMI_MIS_VSYNC_MIS_Msk     (0x1UL << DCMI_MIS_VSYNC_MIS_Pos)            /*!< 0x00000008 */
#define DCMI_MIS_VSYNC_MIS         DCMI_MIS_VSYNC_MIS_Msk                      
#define DCMI_MIS_LINE_MIS_Pos      (4U)                                        
#define DCMI_MIS_LINE_MIS_Msk      (0x1UL << DCMI_MIS_LINE_MIS_Pos)             /*!< 0x00000010 */
#define DCMI_MIS_LINE_MIS          DCMI_MIS_LINE_MIS_Msk                       

/* Legacy defines */
#define DCMI_MISR_FRAME_MIS                  DCMI_MIS_FRAME_MIS
#define DCMI_MISR_OVF_MIS                    DCMI_MIS_OVR_MIS
#define DCMI_MISR_ERR_MIS                    DCMI_MIS_ERR_MIS
#define DCMI_MISR_VSYNC_MIS                  DCMI_MIS_VSYNC_MIS
#define DCMI_MISR_LINE_MIS                   DCMI_MIS_LINE_MIS

/********************  Bits definition for DCMI_ICR register  *****************/
#define DCMI_ICR_FRAME_ISC_Pos     (0U)                                        
#define DCMI_ICR_FRAME_ISC_Msk     (0x1UL << DCMI_ICR_FRAME_ISC_Pos)            /*!< 0x00000001 */
#define DCMI_ICR_FRAME_ISC         DCMI_ICR_FRAME_ISC_Msk                      
#define DCMI_ICR_OVR_ISC_Pos       (1U)                                        
#define DCMI_ICR_OVR_ISC_Msk       (0x1UL << DCMI_ICR_OVR_ISC_Pos)              /*!< 0x00000002 */
#define DCMI_ICR_OVR_ISC           DCMI_ICR_OVR_ISC_Msk                        
#define DCMI_ICR_ERR_ISC_Pos       (2U)                                        
#define DCMI_ICR_ERR_ISC_Msk       (0x1UL << DCMI_ICR_ERR_ISC_Pos)              /*!< 0x00000004 */
#define DCMI_ICR_ERR_ISC           DCMI_ICR_ERR_ISC_Msk                        
#define DCMI_ICR_VSYNC_ISC_Pos     (3U)                                        
#define DCMI_ICR_VSYNC_ISC_Msk     (0x1UL << DCMI_ICR_VSYNC_ISC_Pos)            /*!< 0x00000008 */
#define DCMI_ICR_VSYNC_ISC         DCMI_ICR_VSYNC_ISC_Msk                      
#define DCMI_ICR_LINE_ISC_Pos      (4U)                                        
#define DCMI_ICR_LINE_ISC_Msk      (0x1UL << DCMI_ICR_LINE_ISC_Pos)             /*!< 0x00000010 */
#define DCMI_ICR_LINE_ISC          DCMI_ICR_LINE_ISC_Msk                       

/* Legacy defines */
#define DCMI_ICR_OVF_ISC                     DCMI_ICR_OVR_ISC

/********************  Bits definition for DCMI_ESCR register  ******************/
#define DCMI_ESCR_FSC_Pos          (0U)                                        
#define DCMI_ESCR_FSC_Msk          (0xFFUL << DCMI_ESCR_FSC_Pos)                /*!< 0x000000FF */
#define DCMI_ESCR_FSC              DCMI_ESCR_FSC_Msk                           
#define DCMI_ESCR_LSC_Pos          (8U)                                        
#define DCMI_ESCR_LSC_Msk          (0xFFUL << DCMI_ESCR_LSC_Pos)                /*!< 0x0000FF00 */
#define DCMI_ESCR_LSC              DCMI_ESCR_LSC_Msk                           
#define DCMI_ESCR_LEC_Pos          (16U)                                       
#define DCMI_ESCR_LEC_Msk          (0xFFUL << DCMI_ESCR_LEC_Pos)                /*!< 0x00FF0000 */
#define DCMI_ESCR_LEC              DCMI_ESCR_LEC_Msk                           
#define DCMI_ESCR_FEC_Pos          (24U)                                       
#define DCMI_ESCR_FEC_Msk          (0xFFUL << DCMI_ESCR_FEC_Pos)                /*!< 0xFF000000 */
#define DCMI_ESCR_FEC              DCMI_ESCR_FEC_Msk                           

/********************  Bits definition for DCMI_ESUR register  ******************/
#define DCMI_ESUR_FSU_Pos          (0U)                                        
#define DCMI_ESUR_FSU_Msk          (0xFFUL << DCMI_ESUR_FSU_Pos)                /*!< 0x000000FF */
#define DCMI_ESUR_FSU              DCMI_ESUR_FSU_Msk                           
#define DCMI_ESUR_LSU_Pos          (8U)                                        
#define DCMI_ESUR_LSU_Msk          (0xFFUL << DCMI_ESUR_LSU_Pos)                /*!< 0x0000FF00 */
#define DCMI_ESUR_LSU              DCMI_ESUR_LSU_Msk                           
#define DCMI_ESUR_LEU_Pos          (16U)                                       
#define DCMI_ESUR_LEU_Msk          (0xFFUL << DCMI_ESUR_LEU_Pos)                /*!< 0x00FF0000 */
#define DCMI_ESUR_LEU              DCMI_ESUR_LEU_Msk                           
#define DCMI_ESUR_FEU_Pos          (24U)                                       
#define DCMI_ESUR_FEU_Msk          (0xFFUL << DCMI_ESUR_FEU_Pos)                /*!< 0xFF000000 */
#define DCMI_ESUR_FEU              DCMI_ESUR_FEU_Msk                           

/********************  Bits definition for DCMI_CWSTRT register  ******************/
#define DCMI_CWSTRT_HOFFCNT_Pos    (0U)                                        
#define DCMI_CWSTRT_HOFFCNT_Msk    (0x3FFFUL << DCMI_CWSTRT_HOFFCNT_Pos)        /*!< 0x00003FFF */
#define DCMI_CWSTRT_HOFFCNT        DCMI_CWSTRT_HOFFCNT_Msk                     
#define DCMI_CWSTRT_VST_Pos        (16U)                                       
#define DCMI_CWSTRT_VST_Msk        (0x1FFFUL << DCMI_CWSTRT_VST_Pos)            /*!< 0x1FFF0000 */
#define DCMI_CWSTRT_VST            DCMI_CWSTRT_VST_Msk                         

/********************  Bits definition for DCMI_CWSIZE register  ******************/
#define DCMI_CWSIZE_CAPCNT_Pos     (0U)                                        
#define DCMI_CWSIZE_CAPCNT_Msk     (0x3FFFUL << DCMI_CWSIZE_CAPCNT_Pos)         /*!< 0x00003FFF */
#define DCMI_CWSIZE_CAPCNT         DCMI_CWSIZE_CAPCNT_Msk                      
#define DCMI_CWSIZE_VLINE_Pos      (16U)                                       
#define DCMI_CWSIZE_VLINE_Msk      (0x3FFFUL << DCMI_CWSIZE_VLINE_Pos)          /*!< 0x3FFF0000 */
#define DCMI_CWSIZE_VLINE          DCMI_CWSIZE_VLINE_Msk                       

/********************  Bits definition for DCMI_DR register  *********************/
#define DCMI_DR_BYTE0_Pos          (0U)                                        
#define DCMI_DR_BYTE0_Msk          (0xFFUL << DCMI_DR_BYTE0_Pos)                /*!< 0x000000FF */
#define DCMI_DR_BYTE0              DCMI_DR_BYTE0_Msk                           
#define DCMI_DR_BYTE1_Pos          (8U)                                        
#define DCMI_DR_BYTE1_Msk          (0xFFUL << DCMI_DR_BYTE1_Pos)                /*!< 0x0000FF00 */
#define DCMI_DR_BYTE1              DCMI_DR_BYTE1_Msk                           
#define DCMI_DR_BYTE2_Pos          (16U)                                       
#define DCMI_DR_BYTE2_Msk          (0xFFUL << DCMI_DR_BYTE2_Pos)                /*!< 0x00FF0000 */
#define DCMI_DR_BYTE2              DCMI_DR_BYTE2_Msk                           
#define DCMI_DR_BYTE3_Pos          (24U)                                       
#define DCMI_DR_BYTE3_Msk          (0xFFUL << DCMI_DR_BYTE3_Pos)                /*!< 0xFF000000 */
#define DCMI_DR_BYTE3              DCMI_DR_BYTE3_Msk                           

/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMA_SxCR register  *****************/
#define DMA_SxCR_CHSEL_Pos       (25U)                                         
#define DMA_SxCR_CHSEL_Msk       (0x7UL << DMA_SxCR_CHSEL_Pos)                  /*!< 0x0E000000 */
#define DMA_SxCR_CHSEL           DMA_SxCR_CHSEL_Msk                            
#define DMA_SxCR_CHSEL_0         0x02000000U                                   
#define DMA_SxCR_CHSEL_1         0x04000000U                                   
#define DMA_SxCR_CHSEL_2         0x08000000U                                   
#define DMA_SxCR_MBURST_Pos      (23U)                                         
#define DMA_SxCR_MBURST_Msk      (0x3UL << DMA_SxCR_MBURST_Pos)                 /*!< 0x01800000 */
#define DMA_SxCR_MBURST          DMA_SxCR_MBURST_Msk                           
#define DMA_SxCR_MBURST_0        (0x1UL << DMA_SxCR_MBURST_Pos)                 /*!< 0x00800000 */
#define DMA_SxCR_MBURST_1        (0x2UL << DMA_SxCR_MBURST_Pos)                 /*!< 0x01000000 */
#define DMA_SxCR_PBURST_Pos      (21U)                                         
#define DMA_SxCR_PBURST_Msk      (0x3UL << DMA_SxCR_PBURST_Pos)                 /*!< 0x00600000 */
#define DMA_SxCR_PBURST          DMA_SxCR_PBURST_Msk                           
#define DMA_SxCR_PBURST_0        (0x1UL << DMA_SxCR_PBURST_Pos)                 /*!< 0x00200000 */
#define DMA_SxCR_PBURST_1        (0x2UL << DMA_SxCR_PBURST_Pos)                 /*!< 0x00400000 */
#define DMA_SxCR_CT_Pos          (19U)                                         
#define DMA_SxCR_CT_Msk          (0x1UL << DMA_SxCR_CT_Pos)                     /*!< 0x00080000 */
#define DMA_SxCR_CT              DMA_SxCR_CT_Msk                               
#define DMA_SxCR_DBM_Pos         (18U)                                         
#define DMA_SxCR_DBM_Msk         (0x1UL << DMA_SxCR_DBM_Pos)                    /*!< 0x00040000 */
#define DMA_SxCR_DBM             DMA_SxCR_DBM_Msk                              
#define DMA_SxCR_PL_Pos          (16U)                                         
#define DMA_SxCR_PL_Msk          (0x3UL << DMA_SxCR_PL_Pos)                     /*!< 0x00030000 */
#define DMA_SxCR_PL              DMA_SxCR_PL_Msk                               
#define DMA_SxCR_PL_0            (0x1UL << DMA_SxCR_PL_Pos)                     /*!< 0x00010000 */
#define DMA_SxCR_PL_1            (0x2UL << DMA_SxCR_PL_Pos)                     /*!< 0x00020000 */
#define DMA_SxCR_PINCOS_Pos      (15U)                                         
#define DMA_SxCR_PINCOS_Msk      (0x1UL << DMA_SxCR_PINCOS_Pos)                 /*!< 0x00008000 */
#define DMA_SxCR_PINCOS          DMA_SxCR_PINCOS_Msk                           
#define DMA_SxCR_MSIZE_Pos       (13U)                                         
#define DMA_SxCR_MSIZE_Msk       (0x3UL << DMA_SxCR_MSIZE_Pos)                  /*!< 0x00006000 */
#define DMA_SxCR_MSIZE           DMA_SxCR_MSIZE_Msk                            
#define DMA_SxCR_MSIZE_0         (0x1UL << DMA_SxCR_MSIZE_Pos)                  /*!< 0x00002000 */
#define DMA_SxCR_MSIZE_1         (0x2UL << DMA_SxCR_MSIZE_Pos)                  /*!< 0x00004000 */
#define DMA_SxCR_PSIZE_Pos       (11U)                                         
#define DMA_SxCR_PSIZE_Msk       (0x3UL << DMA_SxCR_PSIZE_Pos)                  /*!< 0x00001800 */
#define DMA_SxCR_PSIZE           DMA_SxCR_PSIZE_Msk                            
#define DMA_SxCR_PSIZE_0         (0x1UL << DMA_SxCR_PSIZE_Pos)                  /*!< 0x00000800 */
#define DMA_SxCR_PSIZE_1         (0x2UL << DMA_SxCR_PSIZE_Pos)                  /*!< 0x00001000 */
#define DMA_SxCR_MINC_Pos        (10U)                                         
#define DMA_SxCR_MINC_Msk        (0x1UL << DMA_SxCR_MINC_Pos)                   /*!< 0x00000400 */
#define DMA_SxCR_MINC            DMA_SxCR_MINC_Msk                             
#define DMA_SxCR_PINC_Pos        (9U)                                          
#define DMA_SxCR_PINC_Msk        (0x1UL << DMA_SxCR_PINC_Pos)                   /*!< 0x00000200 */
#define DMA_SxCR_PINC            DMA_SxCR_PINC_Msk                             
#define DMA_SxCR_CIRC_Pos        (8U)                                          
#define DMA_SxCR_CIRC_Msk        (0x1UL << DMA_SxCR_CIRC_Pos)                   /*!< 0x00000100 */
#define DMA_SxCR_CIRC            DMA_SxCR_CIRC_Msk                             
#define DMA_SxCR_DIR_Pos         (6U)                                          
#define DMA_SxCR_DIR_Msk         (0x3UL << DMA_SxCR_DIR_Pos)                    /*!< 0x000000C0 */
#define DMA_SxCR_DIR             DMA_SxCR_DIR_Msk                              
#define DMA_SxCR_DIR_0           (0x1UL << DMA_SxCR_DIR_Pos)                    /*!< 0x00000040 */
#define DMA_SxCR_DIR_1           (0x2UL << DMA_SxCR_DIR_Pos)                    /*!< 0x00000080 */
#define DMA_SxCR_PFCTRL_Pos      (5U)                                          
#define DMA_SxCR_PFCTRL_Msk      (0x1UL << DMA_SxCR_PFCTRL_Pos)                 /*!< 0x00000020 */
#define DMA_SxCR_PFCTRL          DMA_SxCR_PFCTRL_Msk                           
#define DMA_SxCR_TCIE_Pos        (4U)                                          
#define DMA_SxCR_TCIE_Msk        (0x1UL << DMA_SxCR_TCIE_Pos)                   /*!< 0x00000010 */
#define DMA_SxCR_TCIE            DMA_SxCR_TCIE_Msk                             
#define DMA_SxCR_HTIE_Pos        (3U)                                          
#define DMA_SxCR_HTIE_Msk        (0x1UL << DMA_SxCR_HTIE_Pos)                   /*!< 0x00000008 */
#define DMA_SxCR_HTIE            DMA_SxCR_HTIE_Msk                             
#define DMA_SxCR_TEIE_Pos        (2U)                                          
#define DMA_SxCR_TEIE_Msk        (0x1UL << DMA_SxCR_TEIE_Pos)                   /*!< 0x00000004 */
#define DMA_SxCR_TEIE            DMA_SxCR_TEIE_Msk                             
#define DMA_SxCR_DMEIE_Pos       (1U)                                          
#define DMA_SxCR_DMEIE_Msk       (0x1UL << DMA_SxCR_DMEIE_Pos)                  /*!< 0x00000002 */
#define DMA_SxCR_DMEIE           DMA_SxCR_DMEIE_Msk                            
#define DMA_SxCR_EN_Pos          (0U)                                          
#define DMA_SxCR_EN_Msk          (0x1UL << DMA_SxCR_EN_Pos)                     /*!< 0x00000001 */
#define DMA_SxCR_EN              DMA_SxCR_EN_Msk                               

/* Legacy defines */
#define DMA_SxCR_ACK_Pos         (20U)                                         
#define DMA_SxCR_ACK_Msk         (0x1UL << DMA_SxCR_ACK_Pos)                    /*!< 0x00100000 */
#define DMA_SxCR_ACK             DMA_SxCR_ACK_Msk                              

/********************  Bits definition for DMA_SxCNDTR register  **************/
#define DMA_SxNDT_Pos            (0U)                                          
#define DMA_SxNDT_Msk            (0xFFFFUL << DMA_SxNDT_Pos)                    /*!< 0x0000FFFF */
#define DMA_SxNDT                DMA_SxNDT_Msk                                 
#define DMA_SxNDT_0              (0x0001UL << DMA_SxNDT_Pos)                    /*!< 0x00000001 */
#define DMA_SxNDT_1              (0x0002UL << DMA_SxNDT_Pos)                    /*!< 0x00000002 */
#define DMA_SxNDT_2              (0x0004UL << DMA_SxNDT_Pos)                    /*!< 0x00000004 */
#define DMA_SxNDT_3              (0x0008UL << DMA_SxNDT_Pos)                    /*!< 0x00000008 */
#define DMA_SxNDT_4              (0x0010UL << DMA_SxNDT_Pos)                    /*!< 0x00000010 */
#define DMA_SxNDT_5              (0x0020UL << DMA_SxNDT_Pos)                    /*!< 0x00000020 */
#define DMA_SxNDT_6              (0x0040UL << DMA_SxNDT_Pos)                    /*!< 0x00000040 */
#define DMA_SxNDT_7              (0x0080UL << DMA_SxNDT_Pos)                    /*!< 0x00000080 */
#define DMA_SxNDT_8              (0x0100UL << DMA_SxNDT_Pos)                    /*!< 0x00000100 */
#define DMA_SxNDT_9              (0x0200UL << DMA_SxNDT_Pos)                    /*!< 0x00000200 */
#define DMA_SxNDT_10             (0x0400UL << DMA_SxNDT_Pos)                    /*!< 0x00000400 */
#define DMA_SxNDT_11             (0x0800UL << DMA_SxNDT_Pos)                    /*!< 0x00000800 */
#define DMA_SxNDT_12             (0x1000UL << DMA_SxNDT_Pos)                    /*!< 0x00001000 */
#define DMA_SxNDT_13             (0x2000UL << DMA_SxNDT_Pos)                    /*!< 0x00002000 */
#define DMA_SxNDT_14             (0x4000UL << DMA_SxNDT_Pos)                    /*!< 0x00004000 */
#define DMA_SxNDT_15             (0x8000UL << DMA_SxNDT_Pos)                    /*!< 0x00008000 */

/********************  Bits definition for DMA_SxFCR register  ****************/ 
#define DMA_SxFCR_FEIE_Pos       (7U)                                          
#define DMA_SxFCR_FEIE_Msk       (0x1UL << DMA_SxFCR_FEIE_Pos)                  /*!< 0x00000080 */
#define DMA_SxFCR_FEIE           DMA_SxFCR_FEIE_Msk                            
#define DMA_SxFCR_FS_Pos         (3U)                                          
#define DMA_SxFCR_FS_Msk         (0x7UL << DMA_SxFCR_FS_Pos)                    /*!< 0x00000038 */
#define DMA_SxFCR_FS             DMA_SxFCR_FS_Msk                              
#define DMA_SxFCR_FS_0           (0x1UL << DMA_SxFCR_FS_Pos)                    /*!< 0x00000008 */
#define DMA_SxFCR_FS_1           (0x2UL << DMA_SxFCR_FS_Pos)                    /*!< 0x00000010 */
#define DMA_SxFCR_FS_2           (0x4UL << DMA_SxFCR_FS_Pos)                    /*!< 0x00000020 */
#define DMA_SxFCR_DMDIS_Pos      (2U)                                          
#define DMA_SxFCR_DMDIS_Msk      (0x1UL << DMA_SxFCR_DMDIS_Pos)                 /*!< 0x00000004 */
#define DMA_SxFCR_DMDIS          DMA_SxFCR_DMDIS_Msk                           
#define DMA_SxFCR_FTH_Pos        (0U)                                          
#define DMA_SxFCR_FTH_Msk        (0x3UL << DMA_SxFCR_FTH_Pos)                   /*!< 0x00000003 */
#define DMA_SxFCR_FTH            DMA_SxFCR_FTH_Msk                             
#define DMA_SxFCR_FTH_0          (0x1UL << DMA_SxFCR_FTH_Pos)                   /*!< 0x00000001 */
#define DMA_SxFCR_FTH_1          (0x2UL << DMA_SxFCR_FTH_Pos)                   /*!< 0x00000002 */

/********************  Bits definition for DMA_LISR register  *****************/ 
#define DMA_LISR_TCIF3_Pos       (27U)                                         
#define DMA_LISR_TCIF3_Msk       (0x1UL << DMA_LISR_TCIF3_Pos)                  /*!< 0x08000000 */
#define DMA_LISR_TCIF3           DMA_LISR_TCIF3_Msk                            
#define DMA_LISR_HTIF3_Pos       (26U)                                         
#define DMA_LISR_HTIF3_Msk       (0x1UL << DMA_LISR_HTIF3_Pos)                  /*!< 0x04000000 */
#define DMA_LISR_HTIF3           DMA_LISR_HTIF3_Msk                            
#define DMA_LISR_TEIF3_Pos       (25U)                                         
#define DMA_LISR_TEIF3_Msk       (0x1UL << DMA_LISR_TEIF3_Pos)                  /*!< 0x02000000 */
#define DMA_LISR_TEIF3           DMA_LISR_TEIF3_Msk                            
#define DMA_LISR_DMEIF3_Pos      (24U)                                         
#define DMA_LISR_DMEIF3_Msk      (0x1UL << DMA_LISR_DMEIF3_Pos)                 /*!< 0x01000000 */
#define DMA_LISR_DMEIF3          DMA_LISR_DMEIF3_Msk                           
#define DMA_LISR_FEIF3_Pos       (22U)                                         
#define DMA_LISR_FEIF3_Msk       (0x1UL << DMA_LISR_FEIF3_Pos)                  /*!< 0x00400000 */
#define DMA_LISR_FEIF3           DMA_LISR_FEIF3_Msk                            
#define DMA_LISR_TCIF2_Pos       (21U)                                         
#define DMA_LISR_TCIF2_Msk       (0x1UL << DMA_LISR_TCIF2_Pos)                  /*!< 0x00200000 */
#define DMA_LISR_TCIF2           DMA_LISR_TCIF2_Msk                            
#define DMA_LISR_HTIF2_Pos       (20U)                                         
#define DMA_LISR_HTIF2_Msk       (0x1UL << DMA_LISR_HTIF2_Pos)                  /*!< 0x00100000 */
#define DMA_LISR_HTIF2           DMA_LISR_HTIF2_Msk                            
#define DMA_LISR_TEIF2_Pos       (19U)                                         
#define DMA_LISR_TEIF2_Msk       (0x1UL << DMA_LISR_TEIF2_Pos)                  /*!< 0x00080000 */
#define DMA_LISR_TEIF2           DMA_LISR_TEIF2_Msk                            
#define DMA_LISR_DMEIF2_Pos      (18U)                                         
#define DMA_LISR_DMEIF2_Msk      (0x1UL << DMA_LISR_DMEIF2_Pos)                 /*!< 0x00040000 */
#define DMA_LISR_DMEIF2          DMA_LISR_DMEIF2_Msk                           
#define DMA_LISR_FEIF2_Pos       (16U)                                         
#define DMA_LISR_FEIF2_Msk       (0x1UL << DMA_LISR_FEIF2_Pos)                  /*!< 0x00010000 */
#define DMA_LISR_FEIF2           DMA_LISR_FEIF2_Msk                            
#define DMA_LISR_TCIF1_Pos       (11U)                                         
#define DMA_LISR_TCIF1_Msk       (0x1UL << DMA_LISR_TCIF1_Pos)                  /*!< 0x00000800 */
#define DMA_LISR_TCIF1           DMA_LISR_TCIF1_Msk                            
#define DMA_LISR_HTIF1_Pos       (10U)                                         
#define DMA_LISR_HTIF1_Msk       (0x1UL << DMA_LISR_HTIF1_Pos)                  /*!< 0x00000400 */
#define DMA_LISR_HTIF1           DMA_LISR_HTIF1_Msk                            
#define DMA_LISR_TEIF1_Pos       (9U)                                          
#define DMA_LISR_TEIF1_Msk       (0x1UL << DMA_LISR_TEIF1_Pos)                  /*!< 0x00000200 */
#define DMA_LISR_TEIF1           DMA_LISR_TEIF1_Msk                            
#define DMA_LISR_DMEIF1_Pos      (8U)                                          
#define DMA_LISR_DMEIF1_Msk      (0x1UL << DMA_LISR_DMEIF1_Pos)                 /*!< 0x00000100 */
#define DMA_LISR_DMEIF1          DMA_LISR_DMEIF1_Msk                           
#define DMA_LISR_FEIF1_Pos       (6U)                                          
#define DMA_LISR_FEIF1_Msk       (0x1UL << DMA_LISR_FEIF1_Pos)                  /*!< 0x00000040 */
#define DMA_LISR_FEIF1           DMA_LISR_FEIF1_Msk                            
#define DMA_LISR_TCIF0_Pos       (5U)                                          
#define DMA_LISR_TCIF0_Msk       (0x1UL << DMA_LISR_TCIF0_Pos)                  /*!< 0x00000020 */
#define DMA_LISR_TCIF0           DMA_LISR_TCIF0_Msk                            
#define DMA_LISR_HTIF0_Pos       (4U)                                          
#define DMA_LISR_HTIF0_Msk       (0x1UL << DMA_LISR_HTIF0_Pos)                  /*!< 0x00000010 */
#define DMA_LISR_HTIF0           DMA_LISR_HTIF0_Msk                            
#define DMA_LISR_TEIF0_Pos       (3U)                                          
#define DMA_LISR_TEIF0_Msk       (0x1UL << DMA_LISR_TEIF0_Pos)                  /*!< 0x00000008 */
#define DMA_LISR_TEIF0           DMA_LISR_TEIF0_Msk                            
#define DMA_LISR_DMEIF0_Pos      (2U)                                          
#define DMA_LISR_DMEIF0_Msk      (0x1UL << DMA_LISR_DMEIF0_Pos)                 /*!< 0x00000004 */
#define DMA_LISR_DMEIF0          DMA_LISR_DMEIF0_Msk                           
#define DMA_LISR_FEIF0_Pos       (0U)                                          
#define DMA_LISR_FEIF0_Msk       (0x1UL << DMA_LISR_FEIF0_Pos)                  /*!< 0x00000001 */
#define DMA_LISR_FEIF0           DMA_LISR_FEIF0_Msk                            

/********************  Bits definition for DMA_HISR register  *****************/ 
#define DMA_HISR_TCIF7_Pos       (27U)                                         
#define DMA_HISR_TCIF7_Msk       (0x1UL << DMA_HISR_TCIF7_Pos)                  /*!< 0x08000000 */
#define DMA_HISR_TCIF7           DMA_HISR_TCIF7_Msk                            
#define DMA_HISR_HTIF7_Pos       (26U)                                         
#define DMA_HISR_HTIF7_Msk       (0x1UL << DMA_HISR_HTIF7_Pos)                  /*!< 0x04000000 */
#define DMA_HISR_HTIF7           DMA_HISR_HTIF7_Msk                            
#define DMA_HISR_TEIF7_Pos       (25U)                                         
#define DMA_HISR_TEIF7_Msk       (0x1UL << DMA_HISR_TEIF7_Pos)                  /*!< 0x02000000 */
#define DMA_HISR_TEIF7           DMA_HISR_TEIF7_Msk                            
#define DMA_HISR_DMEIF7_Pos      (24U)                                         
#define DMA_HISR_DMEIF7_Msk      (0x1UL << DMA_HISR_DMEIF7_Pos)                 /*!< 0x01000000 */
#define DMA_HISR_DMEIF7          DMA_HISR_DMEIF7_Msk                           
#define DMA_HISR_FEIF7_Pos       (22U)                                         
#define DMA_HISR_FEIF7_Msk       (0x1UL << DMA_HISR_FEIF7_Pos)                  /*!< 0x00400000 */
#define DMA_HISR_FEIF7           DMA_HISR_FEIF7_Msk                            
#define DMA_HISR_TCIF6_Pos       (21U)                                         
#define DMA_HISR_TCIF6_Msk       (0x1UL << DMA_HISR_TCIF6_Pos)                  /*!< 0x00200000 */
#define DMA_HISR_TCIF6           DMA_HISR_TCIF6_Msk                            
#define DMA_HISR_HTIF6_Pos       (20U)                                         
#define DMA_HISR_HTIF6_Msk       (0x1UL << DMA_HISR_HTIF6_Pos)                  /*!< 0x00100000 */
#define DMA_HISR_HTIF6           DMA_HISR_HTIF6_Msk                            
#define DMA_HISR_TEIF6_Pos       (19U)                                         
#define DMA_HISR_TEIF6_Msk       (0x1UL << DMA_HISR_TEIF6_Pos)                  /*!< 0x00080000 */
#define DMA_HISR_TEIF6           DMA_HISR_TEIF6_Msk                            
#define DMA_HISR_DMEIF6_Pos      (18U)                                         
#define DMA_HISR_DMEIF6_Msk      (0x1UL << DMA_HISR_DMEIF6_Pos)                 /*!< 0x00040000 */
#define DMA_HISR_DMEIF6          DMA_HISR_DMEIF6_Msk                           
#define DMA_HISR_FEIF6_Pos       (16U)                                         
#define DMA_HISR_FEIF6_Msk       (0x1UL << DMA_HISR_FEIF6_Pos)                  /*!< 0x00010000 */
#define DMA_HISR_FEIF6           DMA_HISR_FEIF6_Msk                            
#define DMA_HISR_TCIF5_Pos       (11U)                                         
#define DMA_HISR_TCIF5_Msk       (0x1UL << DMA_HISR_TCIF5_Pos)                  /*!< 0x00000800 */
#define DMA_HISR_TCIF5           DMA_HISR_TCIF5_Msk                            
#define DMA_HISR_HTIF5_Pos       (10U)                                         
#define DMA_HISR_HTIF5_Msk       (0x1UL << DMA_HISR_HTIF5_Pos)                  /*!< 0x00000400 */
#define DMA_HISR_HTIF5           DMA_HISR_HTIF5_Msk                            
#define DMA_HISR_TEIF5_Pos       (9U)                                          
#define DMA_HISR_TEIF5_Msk       (0x1UL << DMA_HISR_TEIF5_Pos)                  /*!< 0x00000200 */
#define DMA_HISR_TEIF5           DMA_HISR_TEIF5_Msk                            
#define DMA_HISR_DMEIF5_Pos      (8U)                                          
#define DMA_HISR_DMEIF5_Msk      (0x1UL << DMA_HISR_DMEIF5_Pos)                 /*!< 0x00000100 */
#define DMA_HISR_DMEIF5          DMA_HISR_DMEIF5_Msk                           
#define DMA_HISR_FEIF5_Pos       (6U)                                          
#define DMA_HISR_FEIF5_Msk       (0x1UL << DMA_HISR_FEIF5_Pos)                  /*!< 0x00000040 */
#define DMA_HISR_FEIF5           DMA_HISR_FEIF5_Msk                            
#define DMA_HISR_TCIF4_Pos       (5U)                                          
#define DMA_HISR_TCIF4_Msk       (0x1UL << DMA_HISR_TCIF4_Pos)                  /*!< 0x00000020 */
#define DMA_HISR_TCIF4           DMA_HISR_TCIF4_Msk                            
#define DMA_HISR_HTIF4_Pos       (4U)                                          
#define DMA_HISR_HTIF4_Msk       (0x1UL << DMA_HISR_HTIF4_Pos)                  /*!< 0x00000010 */
#define DMA_HISR_HTIF4           DMA_HISR_HTIF4_Msk                            
#define DMA_HISR_TEIF4_Pos       (3U)                                          
#define DMA_HISR_TEIF4_Msk       (0x1UL << DMA_HISR_TEIF4_Pos)                  /*!< 0x00000008 */
#define DMA_HISR_TEIF4           DMA_HISR_TEIF4_Msk                            
#define DMA_HISR_DMEIF4_Pos      (2U)                                          
#define DMA_HISR_DMEIF4_Msk      (0x1UL << DMA_HISR_DMEIF4_Pos)                 /*!< 0x00000004 */
#define DMA_HISR_DMEIF4          DMA_HISR_DMEIF4_Msk                           
#define DMA_HISR_FEIF4_Pos       (0U)                                          
#define DMA_HISR_FEIF4_Msk       (0x1UL << DMA_HISR_FEIF4_Pos)                  /*!< 0x00000001 */
#define DMA_HISR_FEIF4           DMA_HISR_FEIF4_Msk                            

/********************  Bits definition for DMA_LIFCR register  ****************/ 
#define DMA_LIFCR_CTCIF3_Pos     (27U)                                         
#define DMA_LIFCR_CTCIF3_Msk     (0x1UL << DMA_LIFCR_CTCIF3_Pos)                /*!< 0x08000000 */
#define DMA_LIFCR_CTCIF3         DMA_LIFCR_CTCIF3_Msk                          
#define DMA_LIFCR_CHTIF3_Pos     (26U)                                         
#define DMA_LIFCR_CHTIF3_Msk     (0x1UL << DMA_LIFCR_CHTIF3_Pos)                /*!< 0x04000000 */
#define DMA_LIFCR_CHTIF3         DMA_LIFCR_CHTIF3_Msk                          
#define DMA_LIFCR_CTEIF3_Pos     (25U)                                         
#define DMA_LIFCR_CTEIF3_Msk     (0x1UL << DMA_LIFCR_CTEIF3_Pos)                /*!< 0x02000000 */
#define DMA_LIFCR_CTEIF3         DMA_LIFCR_CTEIF3_Msk                          
#define DMA_LIFCR_CDMEIF3_Pos    (24U)                                         
#define DMA_LIFCR_CDMEIF3_Msk    (0x1UL << DMA_LIFCR_CDMEIF3_Pos)               /*!< 0x01000000 */
#define DMA_LIFCR_CDMEIF3        DMA_LIFCR_CDMEIF3_Msk                         
#define DMA_LIFCR_CFEIF3_Pos     (22U)                                         
#define DMA_LIFCR_CFEIF3_Msk     (0x1UL << DMA_LIFCR_CFEIF3_Pos)                /*!< 0x00400000 */
#define DMA_LIFCR_CFEIF3         DMA_LIFCR_CFEIF3_Msk                          
#define DMA_LIFCR_CTCIF2_Pos     (21U)                                         
#define DMA_LIFCR_CTCIF2_Msk     (0x1UL << DMA_LIFCR_CTCIF2_Pos)                /*!< 0x00200000 */
#define DMA_LIFCR_CTCIF2         DMA_LIFCR_CTCIF2_Msk                          
#define DMA_LIFCR_CHTIF2_Pos     (20U)                                         
#define DMA_LIFCR_CHTIF2_Msk     (0x1UL << DMA_LIFCR_CHTIF2_Pos)                /*!< 0x00100000 */
#define DMA_LIFCR_CHTIF2         DMA_LIFCR_CHTIF2_Msk                          
#define DMA_LIFCR_CTEIF2_Pos     (19U)                                         
#define DMA_LIFCR_CTEIF2_Msk     (0x1UL << DMA_LIFCR_CTEIF2_Pos)                /*!< 0x00080000 */
#define DMA_LIFCR_CTEIF2         DMA_LIFCR_CTEIF2_Msk                          
#define DMA_LIFCR_CDMEIF2_Pos    (18U)                                         
#define DMA_LIFCR_CDMEIF2_Msk    (0x1UL << DMA_LIFCR_CDMEIF2_Pos)               /*!< 0x00040000 */
#define DMA_LIFCR_CDMEIF2        DMA_LIFCR_CDMEIF2_Msk                         
#define DMA_LIFCR_CFEIF2_Pos     (16U)                                         
#define DMA_LIFCR_CFEIF2_Msk     (0x1UL << DMA_LIFCR_CFEIF2_Pos)                /*!< 0x00010000 */
#define DMA_LIFCR_CFEIF2         DMA_LIFCR_CFEIF2_Msk                          
#define DMA_LIFCR_CTCIF1_Pos     (11U)                                         
#define DMA_LIFCR_CTCIF1_Msk     (0x1UL << DMA_LIFCR_CTCIF1_Pos)                /*!< 0x00000800 */
#define DMA_LIFCR_CTCIF1         DMA_LIFCR_CTCIF1_Msk                          
#define DMA_LIFCR_CHTIF1_Pos     (10U)                                         
#define DMA_LIFCR_CHTIF1_Msk     (0x1UL << DMA_LIFCR_CHTIF1_Pos)                /*!< 0x00000400 */
#define DMA_LIFCR_CHTIF1         DMA_LIFCR_CHTIF1_Msk                          
#define DMA_LIFCR_CTEIF1_Pos     (9U)                                          
#define DMA_LIFCR_CTEIF1_Msk     (0x1UL << DMA_LIFCR_CTEIF1_Pos)                /*!< 0x00000200 */
#define DMA_LIFCR_CTEIF1         DMA_LIFCR_CTEIF1_Msk                          
#define DMA_LIFCR_CDMEIF1_Pos    (8U)                                          
#define DMA_LIFCR_CDMEIF1_Msk    (0x1UL << DMA_LIFCR_CDMEIF1_Pos)               /*!< 0x00000100 */
#define DMA_LIFCR_CDMEIF1        DMA_LIFCR_CDMEIF1_Msk                         
#define DMA_LIFCR_CFEIF1_Pos     (6U)                                          
#define DMA_LIFCR_CFEIF1_Msk     (0x1UL << DMA_LIFCR_CFEIF1_Pos)                /*!< 0x00000040 */
#define DMA_LIFCR_CFEIF1         DMA_LIFCR_CFEIF1_Msk                          
#define DMA_LIFCR_CTCIF0_Pos     (5U)                                          
#define DMA_LIFCR_CTCIF0_Msk     (0x1UL << DMA_LIFCR_CTCIF0_Pos)                /*!< 0x00000020 */
#define DMA_LIFCR_CTCIF0         DMA_LIFCR_CTCIF0_Msk                          
#define DMA_LIFCR_CHTIF0_Pos     (4U)                                          
#define DMA_LIFCR_CHTIF0_Msk     (0x1UL << DMA_LIFCR_CHTIF0_Pos)                /*!< 0x00000010 */
#define DMA_LIFCR_CHTIF0         DMA_LIFCR_CHTIF0_Msk                          
#define DMA_LIFCR_CTEIF0_Pos     (3U)                                          
#define DMA_LIFCR_CTEIF0_Msk     (0x1UL << DMA_LIFCR_CTEIF0_Pos)                /*!< 0x00000008 */
#define DMA_LIFCR_CTEIF0         DMA_LIFCR_CTEIF0_Msk                          
#define DMA_LIFCR_CDMEIF0_Pos    (2U)                                          
#define DMA_LIFCR_CDMEIF0_Msk    (0x1UL << DMA_LIFCR_CDMEIF0_Pos)               /*!< 0x00000004 */
#define DMA_LIFCR_CDMEIF0        DMA_LIFCR_CDMEIF0_Msk                         
#define DMA_LIFCR_CFEIF0_Pos     (0U)                                          
#define DMA_LIFCR_CFEIF0_Msk     (0x1UL << DMA_LIFCR_CFEIF0_Pos)                /*!< 0x00000001 */
#define DMA_LIFCR_CFEIF0         DMA_LIFCR_CFEIF0_Msk                          

/********************  Bits definition for DMA_HIFCR  register  ****************/ 
#define DMA_HIFCR_CTCIF7_Pos     (27U)                                         
#define DMA_HIFCR_CTCIF7_Msk     (0x1UL << DMA_HIFCR_CTCIF7_Pos)                /*!< 0x08000000 */
#define DMA_HIFCR_CTCIF7         DMA_HIFCR_CTCIF7_Msk                          
#define DMA_HIFCR_CHTIF7_Pos     (26U)                                         
#define DMA_HIFCR_CHTIF7_Msk     (0x1UL << DMA_HIFCR_CHTIF7_Pos)                /*!< 0x04000000 */
#define DMA_HIFCR_CHTIF7         DMA_HIFCR_CHTIF7_Msk                          
#define DMA_HIFCR_CTEIF7_Pos     (25U)                                         
#define DMA_HIFCR_CTEIF7_Msk     (0x1UL << DMA_HIFCR_CTEIF7_Pos)                /*!< 0x02000000 */
#define DMA_HIFCR_CTEIF7         DMA_HIFCR_CTEIF7_Msk                          
#define DMA_HIFCR_CDMEIF7_Pos    (24U)                                         
#define DMA_HIFCR_CDMEIF7_Msk    (0x1UL << DMA_HIFCR_CDMEIF7_Pos)               /*!< 0x01000000 */
#define DMA_HIFCR_CDMEIF7        DMA_HIFCR_CDMEIF7_Msk                         
#define DMA_HIFCR_CFEIF7_Pos     (22U)                                         
#define DMA_HIFCR_CFEIF7_Msk     (0x1UL << DMA_HIFCR_CFEIF7_Pos)                /*!< 0x00400000 */
#define DMA_HIFCR_CFEIF7         DMA_HIFCR_CFEIF7_Msk                          
#define DMA_HIFCR_CTCIF6_Pos     (21U)                                         
#define DMA_HIFCR_CTCIF6_Msk     (0x1UL << DMA_HIFCR_CTCIF6_Pos)                /*!< 0x00200000 */
#define DMA_HIFCR_CTCIF6         DMA_HIFCR_CTCIF6_Msk                          
#define DMA_HIFCR_CHTIF6_Pos     (20U)                                         
#define DMA_HIFCR_CHTIF6_Msk     (0x1UL << DMA_HIFCR_CHTIF6_Pos)                /*!< 0x00100000 */
#define DMA_HIFCR_CHTIF6         DMA_HIFCR_CHTIF6_Msk                          
#define DMA_HIFCR_CTEIF6_Pos     (19U)                                         
#define DMA_HIFCR_CTEIF6_Msk     (0x1UL << DMA_HIFCR_CTEIF6_Pos)                /*!< 0x00080000 */
#define DMA_HIFCR_CTEIF6         DMA_HIFCR_CTEIF6_Msk                          
#define DMA_HIFCR_CDMEIF6_Pos    (18U)                                         
#define DMA_HIFCR_CDMEIF6_Msk    (0x1UL << DMA_HIFCR_CDMEIF6_Pos)               /*!< 0x00040000 */
#define DMA_HIFCR_CDMEIF6        DMA_HIFCR_CDMEIF6_Msk                         
#define DMA_HIFCR_CFEIF6_Pos     (16U)                                         
#define DMA_HIFCR_CFEIF6_Msk     (0x1UL << DMA_HIFCR_CFEIF6_Pos)                /*!< 0x00010000 */
#define DMA_HIFCR_CFEIF6         DMA_HIFCR_CFEIF6_Msk                          
#define DMA_HIFCR_CTCIF5_Pos     (11U)                                         
#define DMA_HIFCR_CTCIF5_Msk     (0x1UL << DMA_HIFCR_CTCIF5_Pos)                /*!< 0x00000800 */
#define DMA_HIFCR_CTCIF5         DMA_HIFCR_CTCIF5_Msk                          
#define DMA_HIFCR_CHTIF5_Pos     (10U)                                         
#define DMA_HIFCR_CHTIF5_Msk     (0x1UL << DMA_HIFCR_CHTIF5_Pos)                /*!< 0x00000400 */
#define DMA_HIFCR_CHTIF5         DMA_HIFCR_CHTIF5_Msk                          
#define DMA_HIFCR_CTEIF5_Pos     (9U)                                          
#define DMA_HIFCR_CTEIF5_Msk     (0x1UL << DMA_HIFCR_CTEIF5_Pos)                /*!< 0x00000200 */
#define DMA_HIFCR_CTEIF5         DMA_HIFCR_CTEIF5_Msk                          
#define DMA_HIFCR_CDMEIF5_Pos    (8U)                                          
#define DMA_HIFCR_CDMEIF5_Msk    (0x1UL << DMA_HIFCR_CDMEIF5_Pos)               /*!< 0x00000100 */
#define DMA_HIFCR_CDMEIF5        DMA_HIFCR_CDMEIF5_Msk                         
#define DMA_HIFCR_CFEIF5_Pos     (6U)                                          
#define DMA_HIFCR_CFEIF5_Msk     (0x1UL << DMA_HIFCR_CFEIF5_Pos)                /*!< 0x00000040 */
#define DMA_HIFCR_CFEIF5         DMA_HIFCR_CFEIF5_Msk                          
#define DMA_HIFCR_CTCIF4_Pos     (5U)                                          
#define DMA_HIFCR_CTCIF4_Msk     (0x1UL << DMA_HIFCR_CTCIF4_Pos)                /*!< 0x00000020 */
#define DMA_HIFCR_CTCIF4         DMA_HIFCR_CTCIF4_Msk                          
#define DMA_HIFCR_CHTIF4_Pos     (4U)                                          
#define DMA_HIFCR_CHTIF4_Msk     (0x1UL << DMA_HIFCR_CHTIF4_Pos)                /*!< 0x00000010 */
#define DMA_HIFCR_CHTIF4         DMA_HIFCR_CHTIF4_Msk                          
#define DMA_HIFCR_CTEIF4_Pos     (3U)                                          
#define DMA_HIFCR_CTEIF4_Msk     (0x1UL << DMA_HIFCR_CTEIF4_Pos)                /*!< 0x00000008 */
#define DMA_HIFCR_CTEIF4         DMA_HIFCR_CTEIF4_Msk                          
#define DMA_HIFCR_CDMEIF4_Pos    (2U)                                          
#define DMA_HIFCR_CDMEIF4_Msk    (0x1UL << DMA_HIFCR_CDMEIF4_Pos)               /*!< 0x00000004 */
#define DMA_HIFCR_CDMEIF4        DMA_HIFCR_CDMEIF4_Msk                         
#define DMA_HIFCR_CFEIF4_Pos     (0U)                                          
#define DMA_HIFCR_CFEIF4_Msk     (0x1UL << DMA_HIFCR_CFEIF4_Pos)                /*!< 0x00000001 */
#define DMA_HIFCR_CFEIF4         DMA_HIFCR_CFEIF4_Msk                          

/******************  Bit definition for DMA_SxPAR register  ********************/
#define DMA_SxPAR_PA_Pos         (0U)                                          
#define DMA_SxPAR_PA_Msk         (0xFFFFFFFFUL << DMA_SxPAR_PA_Pos)             /*!< 0xFFFFFFFF */
#define DMA_SxPAR_PA             DMA_SxPAR_PA_Msk                              /*!< Peripheral Address */

/******************  Bit definition for DMA_SxM0AR register  ********************/
#define DMA_SxM0AR_M0A_Pos       (0U)                                          
#define DMA_SxM0AR_M0A_Msk       (0xFFFFFFFFUL << DMA_SxM0AR_M0A_Pos)           /*!< 0xFFFFFFFF */
#define DMA_SxM0AR_M0A           DMA_SxM0AR_M0A_Msk                            /*!< Memory Address */

/******************  Bit definition for DMA_SxM1AR register  ********************/
#define DMA_SxM1AR_M1A_Pos       (0U)                                          
#define DMA_SxM1AR_M1A_Msk       (0xFFFFFFFFUL << DMA_SxM1AR_M1A_Pos)           /*!< 0xFFFFFFFF */
#define DMA_SxM1AR_M1A           DMA_SxM1AR_M1A_Msk                            /*!< Memory Address */


/******************************************************************************/
/*                                                                            */
/*                         AHB Master DMA2D Controller (DMA2D)                */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for DMA2D_CR register  ******************/

#define DMA2D_CR_START_Pos         (0U)                                        
#define DMA2D_CR_START_Msk         (0x1UL << DMA2D_CR_START_Pos)                /*!< 0x00000001 */
#define DMA2D_CR_START             DMA2D_CR_START_Msk                          /*!< Start transfer */
#define DMA2D_CR_SUSP_Pos          (1U)                                        
#define DMA2D_CR_SUSP_Msk          (0x1UL << DMA2D_CR_SUSP_Pos)                 /*!< 0x00000002 */
#define DMA2D_CR_SUSP              DMA2D_CR_SUSP_Msk                           /*!< Suspend transfer */
#define DMA2D_CR_ABORT_Pos         (2U)                                        
#define DMA2D_CR_ABORT_Msk         (0x1UL << DMA2D_CR_ABORT_Pos)                /*!< 0x00000004 */
#define DMA2D_CR_ABORT             DMA2D_CR_ABORT_Msk                          /*!< Abort transfer */
#define DMA2D_CR_TEIE_Pos          (8U)                                        
#define DMA2D_CR_TEIE_Msk          (0x1UL << DMA2D_CR_TEIE_Pos)                 /*!< 0x00000100 */
#define DMA2D_CR_TEIE              DMA2D_CR_TEIE_Msk                           /*!< Transfer Error Interrupt Enable */
#define DMA2D_CR_TCIE_Pos          (9U)                                        
#define DMA2D_CR_TCIE_Msk          (0x1UL << DMA2D_CR_TCIE_Pos)                 /*!< 0x00000200 */
#define DMA2D_CR_TCIE              DMA2D_CR_TCIE_Msk                           /*!< Transfer Complete Interrupt Enable */
#define DMA2D_CR_TWIE_Pos          (10U)                                       
#define DMA2D_CR_TWIE_Msk          (0x1UL << DMA2D_CR_TWIE_Pos)                 /*!< 0x00000400 */
#define DMA2D_CR_TWIE              DMA2D_CR_TWIE_Msk                           /*!< Transfer Watermark Interrupt Enable */
#define DMA2D_CR_CAEIE_Pos         (11U)                                       
#define DMA2D_CR_CAEIE_Msk         (0x1UL << DMA2D_CR_CAEIE_Pos)                /*!< 0x00000800 */
#define DMA2D_CR_CAEIE             DMA2D_CR_CAEIE_Msk                          /*!< CLUT Access Error Interrupt Enable */
#define DMA2D_CR_CTCIE_Pos         (12U)                                       
#define DMA2D_CR_CTCIE_Msk         (0x1UL << DMA2D_CR_CTCIE_Pos)                /*!< 0x00001000 */
#define DMA2D_CR_CTCIE             DMA2D_CR_CTCIE_Msk                          /*!< CLUT Transfer Complete Interrupt Enable */
#define DMA2D_CR_CEIE_Pos          (13U)                                       
#define DMA2D_CR_CEIE_Msk          (0x1UL << DMA2D_CR_CEIE_Pos)                 /*!< 0x00002000 */
#define DMA2D_CR_CEIE              DMA2D_CR_CEIE_Msk                           /*!< Configuration Error Interrupt Enable */
#define DMA2D_CR_MODE_Pos          (16U)                                       
#define DMA2D_CR_MODE_Msk          (0x3UL << DMA2D_CR_MODE_Pos)                 /*!< 0x00030000 */
#define DMA2D_CR_MODE              DMA2D_CR_MODE_Msk                           /*!< DMA2D Mode[1:0] */
#define DMA2D_CR_MODE_0            (0x1UL << DMA2D_CR_MODE_Pos)                 /*!< 0x00010000 */
#define DMA2D_CR_MODE_1            (0x2UL << DMA2D_CR_MODE_Pos)                 /*!< 0x00020000 */

/********************  Bit definition for DMA2D_ISR register  *****************/

#define DMA2D_ISR_TEIF_Pos         (0U)                                        
#define DMA2D_ISR_TEIF_Msk         (0x1UL << DMA2D_ISR_TEIF_Pos)                /*!< 0x00000001 */
#define DMA2D_ISR_TEIF             DMA2D_ISR_TEIF_Msk                          /*!< Transfer Error Interrupt Flag */
#define DMA2D_ISR_TCIF_Pos         (1U)                                        
#define DMA2D_ISR_TCIF_Msk         (0x1UL << DMA2D_ISR_TCIF_Pos)                /*!< 0x00000002 */
#define DMA2D_ISR_TCIF             DMA2D_ISR_TCIF_Msk                          /*!< Transfer Complete Interrupt Flag */
#define DMA2D_ISR_TWIF_Pos         (2U)                                        
#define DMA2D_ISR_TWIF_Msk         (0x1UL << DMA2D_ISR_TWIF_Pos)                /*!< 0x00000004 */
#define DMA2D_ISR_TWIF             DMA2D_ISR_TWIF_Msk                          /*!< Transfer Watermark Interrupt Flag */
#define DMA2D_ISR_CAEIF_Pos        (3U)                                        
#define DMA2D_ISR_CAEIF_Msk        (0x1UL << DMA2D_ISR_CAEIF_Pos)               /*!< 0x00000008 */
#define DMA2D_ISR_CAEIF            DMA2D_ISR_CAEIF_Msk                         /*!< CLUT Access Error Interrupt Flag */
#define DMA2D_ISR_CTCIF_Pos        (4U)                                        
#define DMA2D_ISR_CTCIF_Msk        (0x1UL << DMA2D_ISR_CTCIF_Pos)               /*!< 0x00000010 */
#define DMA2D_ISR_CTCIF            DMA2D_ISR_CTCIF_Msk                         /*!< CLUT Transfer Complete Interrupt Flag */
#define DMA2D_ISR_CEIF_Pos         (5U)                                        
#define DMA2D_ISR_CEIF_Msk         (0x1UL << DMA2D_ISR_CEIF_Pos)                /*!< 0x00000020 */
#define DMA2D_ISR_CEIF             DMA2D_ISR_CEIF_Msk                          /*!< Configuration Error Interrupt Flag */

/********************  Bit definition for DMA2D_IFCR register  ****************/

#define DMA2D_IFCR_CTEIF_Pos       (0U)                                        
#define DMA2D_IFCR_CTEIF_Msk       (0x1UL << DMA2D_IFCR_CTEIF_Pos)              /*!< 0x00000001 */
#define DMA2D_IFCR_CTEIF           DMA2D_IFCR_CTEIF_Msk                        /*!< Clears Transfer Error Interrupt Flag         */
#define DMA2D_IFCR_CTCIF_Pos       (1U)                                        
#define DMA2D_IFCR_CTCIF_Msk       (0x1UL << DMA2D_IFCR_CTCIF_Pos)              /*!< 0x00000002 */
#define DMA2D_IFCR_CTCIF           DMA2D_IFCR_CTCIF_Msk                        /*!< Clears Transfer Complete Interrupt Flag      */
#define DMA2D_IFCR_CTWIF_Pos       (2U)                                        
#define DMA2D_IFCR_CTWIF_Msk       (0x1UL << DMA2D_IFCR_CTWIF_Pos)              /*!< 0x00000004 */
#define DMA2D_IFCR_CTWIF           DMA2D_IFCR_CTWIF_Msk                        /*!< Clears Transfer Watermark Interrupt Flag     */
#define DMA2D_IFCR_CAECIF_Pos      (3U)                                        
#define DMA2D_IFCR_CAECIF_Msk      (0x1UL << DMA2D_IFCR_CAECIF_Pos)             /*!< 0x00000008 */
#define DMA2D_IFCR_CAECIF          DMA2D_IFCR_CAECIF_Msk                       /*!< Clears CLUT Access Error Interrupt Flag      */
#define DMA2D_IFCR_CCTCIF_Pos      (4U)                                        
#define DMA2D_IFCR_CCTCIF_Msk      (0x1UL << DMA2D_IFCR_CCTCIF_Pos)             /*!< 0x00000010 */
#define DMA2D_IFCR_CCTCIF          DMA2D_IFCR_CCTCIF_Msk                       /*!< Clears CLUT Transfer Complete Interrupt Flag */
#define DMA2D_IFCR_CCEIF_Pos       (5U)                                        
#define DMA2D_IFCR_CCEIF_Msk       (0x1UL << DMA2D_IFCR_CCEIF_Pos)              /*!< 0x00000020 */
#define DMA2D_IFCR_CCEIF           DMA2D_IFCR_CCEIF_Msk                        /*!< Clears Configuration Error Interrupt Flag    */

/* Legacy defines */
#define DMA2D_IFSR_CTEIF                   DMA2D_IFCR_CTEIF                     /*!< Clears Transfer Error Interrupt Flag         */
#define DMA2D_IFSR_CTCIF                   DMA2D_IFCR_CTCIF                     /*!< Clears Transfer Complete Interrupt Flag      */
#define DMA2D_IFSR_CTWIF                   DMA2D_IFCR_CTWIF                     /*!< Clears Transfer Watermark Interrupt Flag     */
#define DMA2D_IFSR_CCAEIF                  DMA2D_IFCR_CAECIF                    /*!< Clears CLUT Access Error Interrupt Flag      */
#define DMA2D_IFSR_CCTCIF                  DMA2D_IFCR_CCTCIF                    /*!< Clears CLUT Transfer Complete Interrupt Flag */
#define DMA2D_IFSR_CCEIF                   DMA2D_IFCR_CCEIF                     /*!< Clears Configuration Error Interrupt Flag    */

/********************  Bit definition for DMA2D_FGMAR register  ***************/

#define DMA2D_FGMAR_MA_Pos         (0U)                                        
#define DMA2D_FGMAR_MA_Msk         (0xFFFFFFFFUL << DMA2D_FGMAR_MA_Pos)         /*!< 0xFFFFFFFF */
#define DMA2D_FGMAR_MA             DMA2D_FGMAR_MA_Msk                          /*!< Memory Address */

/********************  Bit definition for DMA2D_FGOR register  ****************/

#define DMA2D_FGOR_LO_Pos          (0U)                                        
#define DMA2D_FGOR_LO_Msk          (0x3FFFUL << DMA2D_FGOR_LO_Pos)              /*!< 0x00003FFF */
#define DMA2D_FGOR_LO              DMA2D_FGOR_LO_Msk                           /*!< Line Offset */

/********************  Bit definition for DMA2D_BGMAR register  ***************/

#define DMA2D_BGMAR_MA_Pos         (0U)                                        
#define DMA2D_BGMAR_MA_Msk         (0xFFFFFFFFUL << DMA2D_BGMAR_MA_Pos)         /*!< 0xFFFFFFFF */
#define DMA2D_BGMAR_MA             DMA2D_BGMAR_MA_Msk                          /*!< Memory Address */

/********************  Bit definition for DMA2D_BGOR register  ****************/

#define DMA2D_BGOR_LO_Pos          (0U)                                        
#define DMA2D_BGOR_LO_Msk          (0x3FFFUL << DMA2D_BGOR_LO_Pos)              /*!< 0x00003FFF */
#define DMA2D_BGOR_LO              DMA2D_BGOR_LO_Msk                           /*!< Line Offset */

/********************  Bit definition for DMA2D_FGPFCCR register  *************/

#define DMA2D_FGPFCCR_CM_Pos       (0U)                                        
#define DMA2D_FGPFCCR_CM_Msk       (0xFUL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x0000000F */
#define DMA2D_FGPFCCR_CM           DMA2D_FGPFCCR_CM_Msk                        /*!< Input color mode CM[3:0] */
#define DMA2D_FGPFCCR_CM_0         (0x1UL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x00000001 */
#define DMA2D_FGPFCCR_CM_1         (0x2UL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x00000002 */
#define DMA2D_FGPFCCR_CM_2         (0x4UL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x00000004 */
#define DMA2D_FGPFCCR_CM_3         (0x8UL << DMA2D_FGPFCCR_CM_Pos)              /*!< 0x00000008 */
#define DMA2D_FGPFCCR_CCM_Pos      (4U)                                        
#define DMA2D_FGPFCCR_CCM_Msk      (0x1UL << DMA2D_FGPFCCR_CCM_Pos)             /*!< 0x00000010 */
#define DMA2D_FGPFCCR_CCM          DMA2D_FGPFCCR_CCM_Msk                       /*!< CLUT Color mode */
#define DMA2D_FGPFCCR_START_Pos    (5U)                                        
#define DMA2D_FGPFCCR_START_Msk    (0x1UL << DMA2D_FGPFCCR_START_Pos)           /*!< 0x00000020 */
#define DMA2D_FGPFCCR_START        DMA2D_FGPFCCR_START_Msk                     /*!< Start */
#define DMA2D_FGPFCCR_CS_Pos       (8U)                                        
#define DMA2D_FGPFCCR_CS_Msk       (0xFFUL << DMA2D_FGPFCCR_CS_Pos)             /*!< 0x0000FF00 */
#define DMA2D_FGPFCCR_CS           DMA2D_FGPFCCR_CS_Msk                        /*!< CLUT size */
#define DMA2D_FGPFCCR_AM_Pos       (16U)                                       
#define DMA2D_FGPFCCR_AM_Msk       (0x3UL << DMA2D_FGPFCCR_AM_Pos)              /*!< 0x00030000 */
#define DMA2D_FGPFCCR_AM           DMA2D_FGPFCCR_AM_Msk                        /*!< Alpha mode AM[1:0] */
#define DMA2D_FGPFCCR_AM_0         (0x1UL << DMA2D_FGPFCCR_AM_Pos)              /*!< 0x00010000 */
#define DMA2D_FGPFCCR_AM_1         (0x2UL << DMA2D_FGPFCCR_AM_Pos)              /*!< 0x00020000 */
#define DMA2D_FGPFCCR_ALPHA_Pos    (24U)                                       
#define DMA2D_FGPFCCR_ALPHA_Msk    (0xFFUL << DMA2D_FGPFCCR_ALPHA_Pos)          /*!< 0xFF000000 */
#define DMA2D_FGPFCCR_ALPHA        DMA2D_FGPFCCR_ALPHA_Msk                     /*!< Alpha value */

/********************  Bit definition for DMA2D_FGCOLR register  **************/

#define DMA2D_FGCOLR_BLUE_Pos      (0U)                                        
#define DMA2D_FGCOLR_BLUE_Msk      (0xFFUL << DMA2D_FGCOLR_BLUE_Pos)            /*!< 0x000000FF */
#define DMA2D_FGCOLR_BLUE          DMA2D_FGCOLR_BLUE_Msk                       /*!< Blue Value */
#define DMA2D_FGCOLR_GREEN_Pos     (8U)                                        
#define DMA2D_FGCOLR_GREEN_Msk     (0xFFUL << DMA2D_FGCOLR_GREEN_Pos)           /*!< 0x0000FF00 */
#define DMA2D_FGCOLR_GREEN         DMA2D_FGCOLR_GREEN_Msk                      /*!< Green Value */
#define DMA2D_FGCOLR_RED_Pos       (16U)                                       
#define DMA2D_FGCOLR_RED_Msk       (0xFFUL << DMA2D_FGCOLR_RED_Pos)             /*!< 0x00FF0000 */
#define DMA2D_FGCOLR_RED           DMA2D_FGCOLR_RED_Msk                        /*!< Red Value */   

/********************  Bit definition for DMA2D_BGPFCCR register  *************/

#define DMA2D_BGPFCCR_CM_Pos       (0U)                                        
#define DMA2D_BGPFCCR_CM_Msk       (0xFUL << DMA2D_BGPFCCR_CM_Pos)              /*!< 0x0000000F */
#define DMA2D_BGPFCCR_CM           DMA2D_BGPFCCR_CM_Msk                        /*!< Input color mode CM[3:0] */
#define DMA2D_BGPFCCR_CM_0         (0x1UL << DMA2D_BGPFCCR_CM_Pos)              /*!< 0x00000001 */
#define DMA2D_BGPFCCR_CM_1         (0x2UL << DMA2D_BGPFCCR_CM_Pos)              /*!< 0x00000002 */
#define DMA2D_BGPFCCR_CM_2         (0x4UL << DMA2D_BGPFCCR_CM_Pos)              /*!< 0x00000004 */
#define DMA2D_BGPFCCR_CM_3         0x00000008U                                 /*!< Input color mode CM bit 3 */
#define DMA2D_BGPFCCR_CCM_Pos      (4U)                                        
#define DMA2D_BGPFCCR_CCM_Msk      (0x1UL << DMA2D_BGPFCCR_CCM_Pos)             /*!< 0x00000010 */
#define DMA2D_BGPFCCR_CCM          DMA2D_BGPFCCR_CCM_Msk                       /*!< CLUT Color mode */
#define DMA2D_BGPFCCR_START_Pos    (5U)                                        
#define DMA2D_BGPFCCR_START_Msk    (0x1UL << DMA2D_BGPFCCR_START_Pos)           /*!< 0x00000020 */
#define DMA2D_BGPFCCR_START        DMA2D_BGPFCCR_START_Msk                     /*!< Start */
#define DMA2D_BGPFCCR_CS_Pos       (8U)                                        
#define DMA2D_BGPFCCR_CS_Msk       (0xFFUL << DMA2D_BGPFCCR_CS_Pos)             /*!< 0x0000FF00 */
#define DMA2D_BGPFCCR_CS           DMA2D_BGPFCCR_CS_Msk                        /*!< CLUT size */
#define DMA2D_BGPFCCR_AM_Pos       (16U)                                       
#define DMA2D_BGPFCCR_AM_Msk       (0x3UL << DMA2D_BGPFCCR_AM_Pos)              /*!< 0x00030000 */
#define DMA2D_BGPFCCR_AM           DMA2D_BGPFCCR_AM_Msk                        /*!< Alpha mode AM[1:0] */
#define DMA2D_BGPFCCR_AM_0         (0x1UL << DMA2D_BGPFCCR_AM_Pos)              /*!< 0x00010000 */
#define DMA2D_BGPFCCR_AM_1         (0x2UL << DMA2D_BGPFCCR_AM_Pos)              /*!< 0x00020000 */
#define DMA2D_BGPFCCR_ALPHA_Pos    (24U)                                       
#define DMA2D_BGPFCCR_ALPHA_Msk    (0xFFUL << DMA2D_BGPFCCR_ALPHA_Pos)          /*!< 0xFF000000 */
#define DMA2D_BGPFCCR_ALPHA        DMA2D_BGPFCCR_ALPHA_Msk                     /*!< background Input Alpha value */

/********************  Bit definition for DMA2D_BGCOLR register  **************/

#define DMA2D_BGCOLR_BLUE_Pos      (0U)                                        
#define DMA2D_BGCOLR_BLUE_Msk      (0xFFUL << DMA2D_BGCOLR_BLUE_Pos)            /*!< 0x000000FF */
#define DMA2D_BGCOLR_BLUE          DMA2D_BGCOLR_BLUE_Msk                       /*!< Blue Value */
#define DMA2D_BGCOLR_GREEN_Pos     (8U)                                        
#define DMA2D_BGCOLR_GREEN_Msk     (0xFFUL << DMA2D_BGCOLR_GREEN_Pos)           /*!< 0x0000FF00 */
#define DMA2D_BGCOLR_GREEN         DMA2D_BGCOLR_GREEN_Msk                      /*!< Green Value */
#define DMA2D_BGCOLR_RED_Pos       (16U)                                       
#define DMA2D_BGCOLR_RED_Msk       (0xFFUL << DMA2D_BGCOLR_RED_Pos)             /*!< 0x00FF0000 */
#define DMA2D_BGCOLR_RED           DMA2D_BGCOLR_RED_Msk                        /*!< Red Value */

/********************  Bit definition for DMA2D_FGCMAR register  **************/

#define DMA2D_FGCMAR_MA_Pos        (0U)                                        
#define DMA2D_FGCMAR_MA_Msk        (0xFFFFFFFFUL << DMA2D_FGCMAR_MA_Pos)        /*!< 0xFFFFFFFF */
#define DMA2D_FGCMAR_MA            DMA2D_FGCMAR_MA_Msk                         /*!< Memory Address */

/********************  Bit definition for DMA2D_BGCMAR register  **************/

#define DMA2D_BGCMAR_MA_Pos        (0U)                                        
#define DMA2D_BGCMAR_MA_Msk        (0xFFFFFFFFUL << DMA2D_BGCMAR_MA_Pos)        /*!< 0xFFFFFFFF */
#define DMA2D_BGCMAR_MA            DMA2D_BGCMAR_MA_Msk                         /*!< Memory Address */

/********************  Bit definition for DMA2D_OPFCCR register  **************/

#define DMA2D_OPFCCR_CM_Pos        (0U)                                        
#define DMA2D_OPFCCR_CM_Msk        (0x7UL << DMA2D_OPFCCR_CM_Pos)               /*!< 0x00000007 */
#define DMA2D_OPFCCR_CM            DMA2D_OPFCCR_CM_Msk                         /*!< Color mode CM[2:0] */
#define DMA2D_OPFCCR_CM_0          (0x1UL << DMA2D_OPFCCR_CM_Pos)               /*!< 0x00000001 */
#define DMA2D_OPFCCR_CM_1          (0x2UL << DMA2D_OPFCCR_CM_Pos)               /*!< 0x00000002 */
#define DMA2D_OPFCCR_CM_2          (0x4UL << DMA2D_OPFCCR_CM_Pos)               /*!< 0x00000004 */

/********************  Bit definition for DMA2D_OCOLR register  ***************/

/*!<Mode_ARGB8888/RGB888 */

#define DMA2D_OCOLR_BLUE_1         0x000000FFU                                 /*!< BLUE Value */
#define DMA2D_OCOLR_GREEN_1        0x0000FF00U                                 /*!< GREEN Value  */
#define DMA2D_OCOLR_RED_1          0x00FF0000U                                 /*!< Red Value */
#define DMA2D_OCOLR_ALPHA_1        0xFF000000U                                 /*!< Alpha Channel Value */

/*!<Mode_RGB565 */
#define DMA2D_OCOLR_BLUE_2         0x0000001FU                                 /*!< BLUE Value */
#define DMA2D_OCOLR_GREEN_2        0x000007E0U                                 /*!< GREEN Value  */
#define DMA2D_OCOLR_RED_2          0x0000F800U                                 /*!< Red Value */

/*!<Mode_ARGB1555 */
#define DMA2D_OCOLR_BLUE_3         0x0000001FU                                 /*!< BLUE Value */
#define DMA2D_OCOLR_GREEN_3        0x000003E0U                                 /*!< GREEN Value  */
#define DMA2D_OCOLR_RED_3          0x00007C00U                                 /*!< Red Value */
#define DMA2D_OCOLR_ALPHA_3        0x00008000U                                 /*!< Alpha Channel Value */

/*!<Mode_ARGB4444 */
#define DMA2D_OCOLR_BLUE_4         0x0000000FU                                 /*!< BLUE Value */
#define DMA2D_OCOLR_GREEN_4        0x000000F0U                                 /*!< GREEN Value  */
#define DMA2D_OCOLR_RED_4          0x00000F00U                                 /*!< Red Value */
#define DMA2D_OCOLR_ALPHA_4        0x0000F000U                                 /*!< Alpha Channel Value */

/********************  Bit definition for DMA2D_OMAR register  ****************/

#define DMA2D_OMAR_MA_Pos          (0U)                                        
#define DMA2D_OMAR_MA_Msk          (0xFFFFFFFFUL << DMA2D_OMAR_MA_Pos)          /*!< 0xFFFFFFFF */
#define DMA2D_OMAR_MA              DMA2D_OMAR_MA_Msk                           /*!< Memory Address */

/********************  Bit definition for DMA2D_OOR register  *****************/

#define DMA2D_OOR_LO_Pos           (0U)                                        
#define DMA2D_OOR_LO_Msk           (0x3FFFUL << DMA2D_OOR_LO_Pos)               /*!< 0x00003FFF */
#define DMA2D_OOR_LO               DMA2D_OOR_LO_Msk                            /*!< Line Offset */

/********************  Bit definition for DMA2D_NLR register  *****************/

#define DMA2D_NLR_NL_Pos           (0U)                                        
#define DMA2D_NLR_NL_Msk           (0xFFFFUL << DMA2D_NLR_NL_Pos)               /*!< 0x0000FFFF */
#define DMA2D_NLR_NL               DMA2D_NLR_NL_Msk                            /*!< Number of Lines */
#define DMA2D_NLR_PL_Pos           (16U)                                       
#define DMA2D_NLR_PL_Msk           (0x3FFFUL << DMA2D_NLR_PL_Pos)               /*!< 0x3FFF0000 */
#define DMA2D_NLR_PL               DMA2D_NLR_PL_Msk                            /*!< Pixel per Lines */

/********************  Bit definition for DMA2D_LWR register  *****************/

#define DMA2D_LWR_LW_Pos           (0U)                                        
#define DMA2D_LWR_LW_Msk           (0xFFFFUL << DMA2D_LWR_LW_Pos)               /*!< 0x0000FFFF */
#define DMA2D_LWR_LW               DMA2D_LWR_LW_Msk                            /*!< Line Watermark */

/********************  Bit definition for DMA2D_AMTCR register  ***************/

#define DMA2D_AMTCR_EN_Pos         (0U)                                        
#define DMA2D_AMTCR_EN_Msk         (0x1UL << DMA2D_AMTCR_EN_Pos)                /*!< 0x00000001 */
#define DMA2D_AMTCR_EN             DMA2D_AMTCR_EN_Msk                          /*!< Enable */
#define DMA2D_AMTCR_DT_Pos         (8U)                                        
#define DMA2D_AMTCR_DT_Msk         (0xFFUL << DMA2D_AMTCR_DT_Pos)               /*!< 0x0000FF00 */
#define DMA2D_AMTCR_DT             DMA2D_AMTCR_DT_Msk                          /*!< Dead Time */

/********************  Bit definition for DMA2D_FGCLUT register  **************/
                                                                     
/********************  Bit definition for DMA2D_BGCLUT register  **************/


/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos            (0U)                                         
#define I2C_CR1_PE_Msk            (0x1UL << I2C_CR1_PE_Pos)                     /*!< 0x00000001 */
#define I2C_CR1_PE                I2C_CR1_PE_Msk                               /*!<Peripheral Enable                             */
#define I2C_CR1_SMBUS_Pos         (1U)                                         
#define I2C_CR1_SMBUS_Msk         (0x1UL << I2C_CR1_SMBUS_Pos)                  /*!< 0x00000002 */
#define I2C_CR1_SMBUS             I2C_CR1_SMBUS_Msk                            /*!<SMBus Mode                                    */
#define I2C_CR1_SMBTYPE_Pos       (3U)                                         
#define I2C_CR1_SMBTYPE_Msk       (0x1UL << I2C_CR1_SMBTYPE_Pos)                /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE           I2C_CR1_SMBTYPE_Msk                          /*!<SMBus Type                                    */
#define I2C_CR1_ENARP_Pos         (4U)                                         
#define I2C_CR1_ENARP_Msk         (0x1UL << I2C_CR1_ENARP_Pos)                  /*!< 0x00000010 */
#define I2C_CR1_ENARP             I2C_CR1_ENARP_Msk                            /*!<ARP Enable                                    */
#define I2C_CR1_ENPEC_Pos         (5U)                                         
#define I2C_CR1_ENPEC_Msk         (0x1UL << I2C_CR1_ENPEC_Pos)                  /*!< 0x00000020 */
#define I2C_CR1_ENPEC             I2C_CR1_ENPEC_Msk                            /*!<PEC Enable                                    */
#define I2C_CR1_ENGC_Pos          (6U)                                         
#define I2C_CR1_ENGC_Msk          (0x1UL << I2C_CR1_ENGC_Pos)                   /*!< 0x00000040 */
#define I2C_CR1_ENGC              I2C_CR1_ENGC_Msk                             /*!<General Call Enable                           */
#define I2C_CR1_NOSTRETCH_Pos     (7U)                                         
#define I2C_CR1_NOSTRETCH_Msk     (0x1UL << I2C_CR1_NOSTRETCH_Pos)              /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH         I2C_CR1_NOSTRETCH_Msk                        /*!<Clock Stretching Disable (Slave mode)         */
#define I2C_CR1_START_Pos         (8U)                                         
#define I2C_CR1_START_Msk         (0x1UL << I2C_CR1_START_Pos)                  /*!< 0x00000100 */
#define I2C_CR1_START             I2C_CR1_START_Msk                            /*!<Start Generation                              */
#define I2C_CR1_STOP_Pos          (9U)                                         
#define I2C_CR1_STOP_Msk          (0x1UL << I2C_CR1_STOP_Pos)                   /*!< 0x00000200 */
#define I2C_CR1_STOP              I2C_CR1_STOP_Msk                             /*!<Stop Generation                               */
#define I2C_CR1_ACK_Pos           (10U)                                        
#define I2C_CR1_ACK_Msk           (0x1UL << I2C_CR1_ACK_Pos)                    /*!< 0x00000400 */
#define I2C_CR1_ACK               I2C_CR1_ACK_Msk                              /*!<Acknowledge Enable                            */
#define I2C_CR1_POS_Pos           (11U)                                        
#define I2C_CR1_POS_Msk           (0x1UL << I2C_CR1_POS_Pos)                    /*!< 0x00000800 */
#define I2C_CR1_POS               I2C_CR1_POS_Msk                              /*!<Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos           (12U)                                        
#define I2C_CR1_PEC_Msk           (0x1UL << I2C_CR1_PEC_Pos)                    /*!< 0x00001000 */
#define I2C_CR1_PEC               I2C_CR1_PEC_Msk                              /*!<Packet Error Checking                         */
#define I2C_CR1_ALERT_Pos         (13U)                                        
#define I2C_CR1_ALERT_Msk         (0x1UL << I2C_CR1_ALERT_Pos)                  /*!< 0x00002000 */
#define I2C_CR1_ALERT             I2C_CR1_ALERT_Msk                            /*!<SMBus Alert                                   */
#define I2C_CR1_SWRST_Pos         (15U)                                        
#define I2C_CR1_SWRST_Msk         (0x1UL << I2C_CR1_SWRST_Pos)                  /*!< 0x00008000 */
#define I2C_CR1_SWRST             I2C_CR1_SWRST_Msk                            /*!<Software Reset                                */

/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos          (0U)                                         
#define I2C_CR2_FREQ_Msk          (0x3FUL << I2C_CR2_FREQ_Pos)                  /*!< 0x0000003F */
#define I2C_CR2_FREQ              I2C_CR2_FREQ_Msk                             /*!<FREQ[5:0] bits (Peripheral Clock Frequency)   */
#define I2C_CR2_FREQ_0            (0x01UL << I2C_CR2_FREQ_Pos)                  /*!< 0x00000001 */
#define I2C_CR2_FREQ_1            (0x02UL << I2C_CR2_FREQ_Pos)                  /*!< 0x00000002 */
#define I2C_CR2_FREQ_2            (0x04UL << I2C_CR2_FREQ_Pos)                  /*!< 0x00000004 */
#define I2C_CR2_FREQ_3            (0x08UL << I2C_CR2_FREQ_Pos)                  /*!< 0x00000008 */
#define I2C_CR2_FREQ_4            (0x10UL << I2C_CR2_FREQ_Pos)                  /*!< 0x00000010 */
#define I2C_CR2_FREQ_5            (0x20UL << I2C_CR2_FREQ_Pos)                  /*!< 0x00000020 */

#define I2C_CR2_ITERREN_Pos       (8U)                                         
#define I2C_CR2_ITERREN_Msk       (0x1UL << I2C_CR2_ITERREN_Pos)                /*!< 0x00000100 */
#define I2C_CR2_ITERREN           I2C_CR2_ITERREN_Msk                          /*!<Error Interrupt Enable  */
#define I2C_CR2_ITEVTEN_Pos       (9U)                                         
#define I2C_CR2_ITEVTEN_Msk       (0x1UL << I2C_CR2_ITEVTEN_Pos)                /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN           I2C_CR2_ITEVTEN_Msk                          /*!<Event Interrupt Enable  */
#define I2C_CR2_ITBUFEN_Pos       (10U)                                        
#define I2C_CR2_ITBUFEN_Msk       (0x1UL << I2C_CR2_ITBUFEN_Pos)                /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN           I2C_CR2_ITBUFEN_Msk                          /*!<Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos         (11U)                                        
#define I2C_CR2_DMAEN_Msk         (0x1UL << I2C_CR2_DMAEN_Pos)                  /*!< 0x00000800 */
#define I2C_CR2_DMAEN             I2C_CR2_DMAEN_Msk                            /*!<DMA Requests Enable     */
#define I2C_CR2_LAST_Pos          (12U)                                        
#define I2C_CR2_LAST_Msk          (0x1UL << I2C_CR2_LAST_Pos)                   /*!< 0x00001000 */
#define I2C_CR2_LAST              I2C_CR2_LAST_Msk                             /*!<DMA Last Transfer       */

/*******************  Bit definition for I2C_OAR1 register  *******************/
#define I2C_OAR1_ADD1_7           0x000000FEU                                  /*!<Interface Address */
#define I2C_OAR1_ADD8_9           0x00000300U                                  /*!<Interface Address */

#define I2C_OAR1_ADD0_Pos         (0U)                                         
#define I2C_OAR1_ADD0_Msk         (0x1UL << I2C_OAR1_ADD0_Pos)                  /*!< 0x00000001 */
#define I2C_OAR1_ADD0             I2C_OAR1_ADD0_Msk                            /*!<Bit 0 */
#define I2C_OAR1_ADD1_Pos         (1U)                                         
#define I2C_OAR1_ADD1_Msk         (0x1UL << I2C_OAR1_ADD1_Pos)                  /*!< 0x00000002 */
#define I2C_OAR1_ADD1             I2C_OAR1_ADD1_Msk                            /*!<Bit 1 */
#define I2C_OAR1_ADD2_Pos         (2U)                                         
#define I2C_OAR1_ADD2_Msk         (0x1UL << I2C_OAR1_ADD2_Pos)                  /*!< 0x00000004 */
#define I2C_OAR1_ADD2             I2C_OAR1_ADD2_Msk                            /*!<Bit 2 */
#define I2C_OAR1_ADD3_Pos         (3U)                                         
#define I2C_OAR1_ADD3_Msk         (0x1UL << I2C_OAR1_ADD3_Pos)                  /*!< 0x00000008 */
#define I2C_OAR1_ADD3             I2C_OAR1_ADD3_Msk                            /*!<Bit 3 */
#define I2C_OAR1_ADD4_Pos         (4U)                                         
#define I2C_OAR1_ADD4_Msk         (0x1UL << I2C_OAR1_ADD4_Pos)                  /*!< 0x00000010 */
#define I2C_OAR1_ADD4             I2C_OAR1_ADD4_Msk                            /*!<Bit 4 */
#define I2C_OAR1_ADD5_Pos         (5U)                                         
#define I2C_OAR1_ADD5_Msk         (0x1UL << I2C_OAR1_ADD5_Pos)                  /*!< 0x00000020 */
#define I2C_OAR1_ADD5             I2C_OAR1_ADD5_Msk                            /*!<Bit 5 */
#define I2C_OAR1_ADD6_Pos         (6U)                                         
#define I2C_OAR1_ADD6_Msk         (0x1UL << I2C_OAR1_ADD6_Pos)                  /*!< 0x00000040 */
#define I2C_OAR1_ADD6             I2C_OAR1_ADD6_Msk                            /*!<Bit 6 */
#define I2C_OAR1_ADD7_Pos         (7U)                                         
#define I2C_OAR1_ADD7_Msk         (0x1UL << I2C_OAR1_ADD7_Pos)                  /*!< 0x00000080 */
#define I2C_OAR1_ADD7             I2C_OAR1_ADD7_Msk                            /*!<Bit 7 */
#define I2C_OAR1_ADD8_Pos         (8U)                                         
#define I2C_OAR1_ADD8_Msk         (0x1UL << I2C_OAR1_ADD8_Pos)                  /*!< 0x00000100 */
#define I2C_OAR1_ADD8             I2C_OAR1_ADD8_Msk                            /*!<Bit 8 */
#define I2C_OAR1_ADD9_Pos         (9U)                                         
#define I2C_OAR1_ADD9_Msk         (0x1UL << I2C_OAR1_ADD9_Pos)                  /*!< 0x00000200 */
#define I2C_OAR1_ADD9             I2C_OAR1_ADD9_Msk                            /*!<Bit 9 */

#define I2C_OAR1_ADDMODE_Pos      (15U)                                        
#define I2C_OAR1_ADDMODE_Msk      (0x1UL << I2C_OAR1_ADDMODE_Pos)               /*!< 0x00008000 */
#define I2C_OAR1_ADDMODE          I2C_OAR1_ADDMODE_Msk                         /*!<Addressing Mode (Slave mode) */

/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos       (0U)                                         
#define I2C_OAR2_ENDUAL_Msk       (0x1UL << I2C_OAR2_ENDUAL_Pos)                /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL           I2C_OAR2_ENDUAL_Msk                          /*!<Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos         (1U)                                         
#define I2C_OAR2_ADD2_Msk         (0x7FUL << I2C_OAR2_ADD2_Pos)                 /*!< 0x000000FE */
#define I2C_OAR2_ADD2             I2C_OAR2_ADD2_Msk                            /*!<Interface address           */

/********************  Bit definition for I2C_DR register  ********************/
#define I2C_DR_DR_Pos             (0U)                                         
#define I2C_DR_DR_Msk             (0xFFUL << I2C_DR_DR_Pos)                     /*!< 0x000000FF */
#define I2C_DR_DR                 I2C_DR_DR_Msk                                /*!<8-bit Data Register         */

/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos            (0U)                                         
#define I2C_SR1_SB_Msk            (0x1UL << I2C_SR1_SB_Pos)                     /*!< 0x00000001 */
#define I2C_SR1_SB                I2C_SR1_SB_Msk                               /*!<Start Bit (Master mode)                         */
#define I2C_SR1_ADDR_Pos          (1U)                                         
#define I2C_SR1_ADDR_Msk          (0x1UL << I2C_SR1_ADDR_Pos)                   /*!< 0x00000002 */
#define I2C_SR1_ADDR              I2C_SR1_ADDR_Msk                             /*!<Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos           (2U)                                         
#define I2C_SR1_BTF_Msk           (0x1UL << I2C_SR1_BTF_Pos)                    /*!< 0x00000004 */
#define I2C_SR1_BTF               I2C_SR1_BTF_Msk                              /*!<Byte Transfer Finished                          */
#define I2C_SR1_ADD10_Pos         (3U)                                         
#define I2C_SR1_ADD10_Msk         (0x1UL << I2C_SR1_ADD10_Pos)                  /*!< 0x00000008 */
#define I2C_SR1_ADD10             I2C_SR1_ADD10_Msk                            /*!<10-bit header sent (Master mode)                */
#define I2C_SR1_STOPF_Pos         (4U)                                         
#define I2C_SR1_STOPF_Msk         (0x1UL << I2C_SR1_STOPF_Pos)                  /*!< 0x00000010 */
#define I2C_SR1_STOPF             I2C_SR1_STOPF_Msk                            /*!<Stop detection (Slave mode)                     */
#define I2C_SR1_RXNE_Pos          (6U)                                         
#define I2C_SR1_RXNE_Msk          (0x1UL << I2C_SR1_RXNE_Pos)                   /*!< 0x00000040 */
#define I2C_SR1_RXNE              I2C_SR1_RXNE_Msk                             /*!<Data Register not Empty (receivers)             */
#define I2C_SR1_TXE_Pos           (7U)                                         
#define I2C_SR1_TXE_Msk           (0x1UL << I2C_SR1_TXE_Pos)                    /*!< 0x00000080 */
#define I2C_SR1_TXE               I2C_SR1_TXE_Msk                              /*!<Data Register Empty (transmitters)              */
#define I2C_SR1_BERR_Pos          (8U)                                         
#define I2C_SR1_BERR_Msk          (0x1UL << I2C_SR1_BERR_Pos)                   /*!< 0x00000100 */
#define I2C_SR1_BERR              I2C_SR1_BERR_Msk                             /*!<Bus Error                                       */
#define I2C_SR1_ARLO_Pos          (9U)                                         
#define I2C_SR1_ARLO_Msk          (0x1UL << I2C_SR1_ARLO_Pos)                   /*!< 0x00000200 */
#define I2C_SR1_ARLO              I2C_SR1_ARLO_Msk                             /*!<Arbitration Lost (master mode)                  */
#define I2C_SR1_AF_Pos            (10U)                                        
#define I2C_SR1_AF_Msk            (0x1UL << I2C_SR1_AF_Pos)                     /*!< 0x00000400 */
#define I2C_SR1_AF                I2C_SR1_AF_Msk                               /*!<Acknowledge Failure                             */
#define I2C_SR1_OVR_Pos           (11U)                                        
#define I2C_SR1_OVR_Msk           (0x1UL << I2C_SR1_OVR_Pos)                    /*!< 0x00000800 */
#define I2C_SR1_OVR               I2C_SR1_OVR_Msk                              /*!<Overrun/Underrun                                */
#define I2C_SR1_PECERR_Pos        (12U)                                        
#define I2C_SR1_PECERR_Msk        (0x1UL << I2C_SR1_PECERR_Pos)                 /*!< 0x00001000 */
#define I2C_SR1_PECERR            I2C_SR1_PECERR_Msk                           /*!<PEC Error in reception                          */
#define I2C_SR1_TIMEOUT_Pos       (14U)                                        
#define I2C_SR1_TIMEOUT_Msk       (0x1UL << I2C_SR1_TIMEOUT_Pos)                /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT           I2C_SR1_TIMEOUT_Msk                          /*!<Timeout or Tlow Error                           */
#define I2C_SR1_SMBALERT_Pos      (15U)                                        
#define I2C_SR1_SMBALERT_Msk      (0x1UL << I2C_SR1_SMBALERT_Pos)               /*!< 0x00008000 */
#define I2C_SR1_SMBALERT          I2C_SR1_SMBALERT_Msk                         /*!<SMBus Alert                                     */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos           (0U)                                         
#define I2C_SR2_MSL_Msk           (0x1UL << I2C_SR2_MSL_Pos)                    /*!< 0x00000001 */
#define I2C_SR2_MSL               I2C_SR2_MSL_Msk                              /*!<Master/Slave                                    */
#define I2C_SR2_BUSY_Pos          (1U)                                         
#define I2C_SR2_BUSY_Msk          (0x1UL << I2C_SR2_BUSY_Pos)                   /*!< 0x00000002 */
#define I2C_SR2_BUSY              I2C_SR2_BUSY_Msk                             /*!<Bus Busy                                        */
#define I2C_SR2_TRA_Pos           (2U)                                         
#define I2C_SR2_TRA_Msk           (0x1UL << I2C_SR2_TRA_Pos)                    /*!< 0x00000004 */
#define I2C_SR2_TRA               I2C_SR2_TRA_Msk                              /*!<Transmitter/Receiver                            */
#define I2C_SR2_GENCALL_Pos       (4U)                                         
#define I2C_SR2_GENCALL_Msk       (0x1UL << I2C_SR2_GENCALL_Pos)                /*!< 0x00000010 */
#define I2C_SR2_GENCALL           I2C_SR2_GENCALL_Msk                          /*!<General Call Address (Slave mode)               */
#define I2C_SR2_SMBDEFAULT_Pos    (5U)                                         
#define I2C_SR2_SMBDEFAULT_Msk    (0x1UL << I2C_SR2_SMBDEFAULT_Pos)             /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT        I2C_SR2_SMBDEFAULT_Msk                       /*!<SMBus Device Default Address (Slave mode)       */
#define I2C_SR2_SMBHOST_Pos       (6U)                                         
#define I2C_SR2_SMBHOST_Msk       (0x1UL << I2C_SR2_SMBHOST_Pos)                /*!< 0x00000040 */
#define I2C_SR2_SMBHOST           I2C_SR2_SMBHOST_Msk                          /*!<SMBus Host Header (Slave mode)                  */
#define I2C_SR2_DUALF_Pos         (7U)                                         
#define I2C_SR2_DUALF_Msk         (0x1UL << I2C_SR2_DUALF_Pos)                  /*!< 0x00000080 */
#define I2C_SR2_DUALF             I2C_SR2_DUALF_Msk                            /*!<Dual Flag (Slave mode)                          */
#define I2C_SR2_PEC_Pos           (8U)                                         
#define I2C_SR2_PEC_Msk           (0xFFUL << I2C_SR2_PEC_Pos)                   /*!< 0x0000FF00 */
#define I2C_SR2_PEC               I2C_SR2_PEC_Msk                              /*!<Packet Error Checking Register                  */

/*******************  Bit definition for I2C_CCR register  ********************/
#define I2C_CCR_CCR_Pos           (0U)                                         
#define I2C_CCR_CCR_Msk           (0xFFFUL << I2C_CCR_CCR_Pos)                  /*!< 0x00000FFF */
#define I2C_CCR_CCR               I2C_CCR_CCR_Msk                              /*!<Clock Control Register in Fast/Standard mode (Master mode) */
#define I2C_CCR_DUTY_Pos          (14U)                                        
#define I2C_CCR_DUTY_Msk          (0x1UL << I2C_CCR_DUTY_Pos)                   /*!< 0x00004000 */
#define I2C_CCR_DUTY              I2C_CCR_DUTY_Msk                             /*!<Fast Mode Duty Cycle                                       */
#define I2C_CCR_FS_Pos            (15U)                                        
#define I2C_CCR_FS_Msk            (0x1UL << I2C_CCR_FS_Pos)                     /*!< 0x00008000 */
#define I2C_CCR_FS                I2C_CCR_FS_Msk                               /*!<I2C Master Mode Selection                                  */

/******************  Bit definition for I2C_TRISE register  *******************/
#define I2C_TRISE_TRISE_Pos       (0U)                                         
#define I2C_TRISE_TRISE_Msk       (0x3FUL << I2C_TRISE_TRISE_Pos)               /*!< 0x0000003F */
#define I2C_TRISE_TRISE           I2C_TRISE_TRISE_Msk                          /*!<Maximum Rise Time in Fast/Standard mode (Master mode) */

/******************  Bit definition for I2C_FLTR register  *******************/
#define I2C_FLTR_DNF_Pos          (0U)                                         
#define I2C_FLTR_DNF_Msk          (0xFUL << I2C_FLTR_DNF_Pos)                   /*!< 0x0000000F */
#define I2C_FLTR_DNF              I2C_FLTR_DNF_Msk                             /*!<Digital Noise Filter */
#define I2C_FLTR_ANOFF_Pos        (4U)                                         
#define I2C_FLTR_ANOFF_Msk        (0x1UL << I2C_FLTR_ANOFF_Pos)                 /*!< 0x00000010 */
#define I2C_FLTR_ANOFF            I2C_FLTR_ANOFF_Msk                           /*!<Analog Noise Filter OFF */

/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY_Pos     (0U)                                               
#define IWDG_KR_KEY_Msk     (0xFFFFUL << IWDG_KR_KEY_Pos)                       /*!< 0x0000FFFF */
#define IWDG_KR_KEY         IWDG_KR_KEY_Msk                                    /*!<Key value (write only, read 0000h)  */

/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR_Pos      (0U)                                               
#define IWDG_PR_PR_Msk      (0x7UL << IWDG_PR_PR_Pos)                           /*!< 0x00000007 */
#define IWDG_PR_PR          IWDG_PR_PR_Msk                                     /*!<PR[2:0] (Prescaler divider)         */
#define IWDG_PR_PR_0        (0x1UL << IWDG_PR_PR_Pos)                           /*!< 0x01 */
#define IWDG_PR_PR_1        (0x2UL << IWDG_PR_PR_Pos)                           /*!< 0x02 */
#define IWDG_PR_PR_2        (0x4UL << IWDG_PR_PR_Pos)                           /*!< 0x04 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL_Pos     (0U)                                               
#define IWDG_RLR_RL_Msk     (0xFFFUL << IWDG_RLR_RL_Pos)                        /*!< 0x00000FFF */
#define IWDG_RLR_RL         IWDG_RLR_RL_Msk                                    /*!<Watchdog counter reload value        */

/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU_Pos     (0U)                                               
#define IWDG_SR_PVU_Msk     (0x1UL << IWDG_SR_PVU_Pos)                          /*!< 0x00000001 */
#define IWDG_SR_PVU         IWDG_SR_PVU_Msk                                    /*!<Watchdog prescaler value update      */
#define IWDG_SR_RVU_Pos     (1U)                                               
#define IWDG_SR_RVU_Msk     (0x1UL << IWDG_SR_RVU_Pos)                          /*!< 0x00000002 */
#define IWDG_SR_RVU         IWDG_SR_RVU_Msk                                    /*!<Watchdog counter reload value update */


/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWR_CR register  ********************/
#define PWR_CR_LPDS_Pos        (0U)                                            
#define PWR_CR_LPDS_Msk        (0x1UL << PWR_CR_LPDS_Pos)                       /*!< 0x00000001 */
#define PWR_CR_LPDS            PWR_CR_LPDS_Msk                                 /*!< Low-Power Deepsleep                 */
#define PWR_CR_PDDS_Pos        (1U)                                            
#define PWR_CR_PDDS_Msk        (0x1UL << PWR_CR_PDDS_Pos)                       /*!< 0x00000002 */
#define PWR_CR_PDDS            PWR_CR_PDDS_Msk                                 /*!< Power Down Deepsleep                */
#define PWR_CR_CWUF_Pos        (2U)                                            
#define PWR_CR_CWUF_Msk        (0x1UL << PWR_CR_CWUF_Pos)                       /*!< 0x00000004 */
#define PWR_CR_CWUF            PWR_CR_CWUF_Msk                                 /*!< Clear Wakeup Flag                   */
#define PWR_CR_CSBF_Pos        (3U)                                            
#define PWR_CR_CSBF_Msk        (0x1UL << PWR_CR_CSBF_Pos)                       /*!< 0x00000008 */
#define PWR_CR_CSBF            PWR_CR_CSBF_Msk                                 /*!< Clear Standby Flag                  */
#define PWR_CR_PVDE_Pos        (4U)                                            
#define PWR_CR_PVDE_Msk        (0x1UL << PWR_CR_PVDE_Pos)                       /*!< 0x00000010 */
#define PWR_CR_PVDE            PWR_CR_PVDE_Msk                                 /*!< Power Voltage Detector Enable       */

#define PWR_CR_PLS_Pos         (5U)                                            
#define PWR_CR_PLS_Msk         (0x7UL << PWR_CR_PLS_Pos)                        /*!< 0x000000E0 */
#define PWR_CR_PLS             PWR_CR_PLS_Msk                                  /*!< PLS[2:0] bits (PVD Level Selection) */
#define PWR_CR_PLS_0           (0x1UL << PWR_CR_PLS_Pos)                        /*!< 0x00000020 */
#define PWR_CR_PLS_1           (0x2UL << PWR_CR_PLS_Pos)                        /*!< 0x00000040 */
#define PWR_CR_PLS_2           (0x4UL << PWR_CR_PLS_Pos)                        /*!< 0x00000080 */

/*!< PVD level configuration */
#define PWR_CR_PLS_LEV0        0x00000000U                                     /*!< PVD level 0 */
#define PWR_CR_PLS_LEV1        0x00000020U                                     /*!< PVD level 1 */
#define PWR_CR_PLS_LEV2        0x00000040U                                     /*!< PVD level 2 */
#define PWR_CR_PLS_LEV3        0x00000060U                                     /*!< PVD level 3 */
#define PWR_CR_PLS_LEV4        0x00000080U                                     /*!< PVD level 4 */
#define PWR_CR_PLS_LEV5        0x000000A0U                                     /*!< PVD level 5 */
#define PWR_CR_PLS_LEV6        0x000000C0U                                     /*!< PVD level 6 */
#define PWR_CR_PLS_LEV7        0x000000E0U                                     /*!< PVD level 7 */
#define PWR_CR_DBP_Pos         (8U)                                            
#define PWR_CR_DBP_Msk         (0x1UL << PWR_CR_DBP_Pos)                        /*!< 0x00000100 */
#define PWR_CR_DBP             PWR_CR_DBP_Msk                                  /*!< Disable Backup Domain write protection                     */
#define PWR_CR_FPDS_Pos        (9U)                                            
#define PWR_CR_FPDS_Msk        (0x1UL << PWR_CR_FPDS_Pos)                       /*!< 0x00000200 */
#define PWR_CR_FPDS            PWR_CR_FPDS_Msk                                 /*!< Flash power down in Stop mode                              */
#define PWR_CR_LPLVDS_Pos      (10U)                                           
#define PWR_CR_LPLVDS_Msk      (0x1UL << PWR_CR_LPLVDS_Pos)                     /*!< 0x00000400 */
#define PWR_CR_LPLVDS          PWR_CR_LPLVDS_Msk                               /*!< Low-Power Regulator Low Voltage Scaling in Stop mode       */
#define PWR_CR_MRLVDS_Pos      (11U)                                           
#define PWR_CR_MRLVDS_Msk      (0x1UL << PWR_CR_MRLVDS_Pos)                     /*!< 0x00000800 */
#define PWR_CR_MRLVDS          PWR_CR_MRLVDS_Msk                               /*!< Main regulator Low Voltage Scaling in Stop mode            */
#define PWR_CR_ADCDC1_Pos      (13U)                                           
#define PWR_CR_ADCDC1_Msk      (0x1UL << PWR_CR_ADCDC1_Pos)                     /*!< 0x00002000 */
#define PWR_CR_ADCDC1          PWR_CR_ADCDC1_Msk                               /*!< Refer to AN4073 on how to use this bit                     */ 
#define PWR_CR_VOS_Pos         (14U)                                           
#define PWR_CR_VOS_Msk         (0x3UL << PWR_CR_VOS_Pos)                        /*!< 0x0000C000 */
#define PWR_CR_VOS             PWR_CR_VOS_Msk                                  /*!< VOS[1:0] bits (Regulator voltage scaling output selection) */
#define PWR_CR_VOS_0           0x00004000U                                     /*!< Bit 0 */
#define PWR_CR_VOS_1           0x00008000U                                     /*!< Bit 1 */
#define PWR_CR_ODEN_Pos        (16U)                                           
#define PWR_CR_ODEN_Msk        (0x1UL << PWR_CR_ODEN_Pos)                       /*!< 0x00010000 */
#define PWR_CR_ODEN            PWR_CR_ODEN_Msk                                 /*!< Over Drive enable                   */
#define PWR_CR_ODSWEN_Pos      (17U)                                           
#define PWR_CR_ODSWEN_Msk      (0x1UL << PWR_CR_ODSWEN_Pos)                     /*!< 0x00020000 */
#define PWR_CR_ODSWEN          PWR_CR_ODSWEN_Msk                               /*!< Over Drive switch enabled           */
#define PWR_CR_UDEN_Pos        (18U)                                           
#define PWR_CR_UDEN_Msk        (0x3UL << PWR_CR_UDEN_Pos)                       /*!< 0x000C0000 */
#define PWR_CR_UDEN            PWR_CR_UDEN_Msk                                 /*!< Under Drive enable in stop mode     */
#define PWR_CR_UDEN_0          (0x1UL << PWR_CR_UDEN_Pos)                       /*!< 0x00040000 */
#define PWR_CR_UDEN_1          (0x2UL << PWR_CR_UDEN_Pos)                       /*!< 0x00080000 */

/* Legacy define */
#define  PWR_CR_PMODE                        PWR_CR_VOS
#define  PWR_CR_LPUDS                        PWR_CR_LPLVDS     /*!< Low-Power Regulator in deepsleep under-drive mode        */
#define  PWR_CR_MRUDS                        PWR_CR_MRLVDS     /*!< Main regulator in deepsleep under-drive mode             */

/*******************  Bit definition for PWR_CSR register  ********************/
#define PWR_CSR_WUF_Pos        (0U)                                            
#define PWR_CSR_WUF_Msk        (0x1UL << PWR_CSR_WUF_Pos)                       /*!< 0x00000001 */
#define PWR_CSR_WUF            PWR_CSR_WUF_Msk                                 /*!< Wakeup Flag                                      */
#define PWR_CSR_SBF_Pos        (1U)                                            
#define PWR_CSR_SBF_Msk        (0x1UL << PWR_CSR_SBF_Pos)                       /*!< 0x00000002 */
#define PWR_CSR_SBF            PWR_CSR_SBF_Msk                                 /*!< Standby Flag                                     */
#define PWR_CSR_PVDO_Pos       (2U)                                            
#define PWR_CSR_PVDO_Msk       (0x1UL << PWR_CSR_PVDO_Pos)                      /*!< 0x00000004 */
#define PWR_CSR_PVDO           PWR_CSR_PVDO_Msk                                /*!< PVD Output                                       */
#define PWR_CSR_BRR_Pos        (3U)                                            
#define PWR_CSR_BRR_Msk        (0x1UL << PWR_CSR_BRR_Pos)                       /*!< 0x00000008 */
#define PWR_CSR_BRR            PWR_CSR_BRR_Msk                                 /*!< Backup regulator ready                           */
#define PWR_CSR_EWUP_Pos       (8U)                                            
#define PWR_CSR_EWUP_Msk       (0x1UL << PWR_CSR_EWUP_Pos)                      /*!< 0x00000100 */
#define PWR_CSR_EWUP           PWR_CSR_EWUP_Msk                                /*!< Enable WKUP pin                                  */
#define PWR_CSR_BRE_Pos        (9U)                                            
#define PWR_CSR_BRE_Msk        (0x1UL << PWR_CSR_BRE_Pos)                       /*!< 0x00000200 */
#define PWR_CSR_BRE            PWR_CSR_BRE_Msk                                 /*!< Backup regulator enable                          */
#define PWR_CSR_VOSRDY_Pos     (14U)                                           
#define PWR_CSR_VOSRDY_Msk     (0x1UL << PWR_CSR_VOSRDY_Pos)                    /*!< 0x00004000 */
#define PWR_CSR_VOSRDY         PWR_CSR_VOSRDY_Msk                              /*!< Regulator voltage scaling output selection ready */
#define PWR_CSR_ODRDY_Pos      (16U)                                           
#define PWR_CSR_ODRDY_Msk      (0x1UL << PWR_CSR_ODRDY_Pos)                     /*!< 0x00010000 */
#define PWR_CSR_ODRDY          PWR_CSR_ODRDY_Msk                               /*!< Over Drive generator ready                       */
#define PWR_CSR_ODSWRDY_Pos    (17U)                                           
#define PWR_CSR_ODSWRDY_Msk    (0x1UL << PWR_CSR_ODSWRDY_Pos)                   /*!< 0x00020000 */
#define PWR_CSR_ODSWRDY        PWR_CSR_ODSWRDY_Msk                             /*!< Over Drive Switch ready                          */
#define PWR_CSR_UDRDY_Pos      (18U)                                           
#define PWR_CSR_UDRDY_Msk      (0x3UL << PWR_CSR_UDRDY_Pos)                     /*!< 0x000C0000 */
#define PWR_CSR_UDRDY          PWR_CSR_UDRDY_Msk                               /*!< Under Drive ready                                */
/* Legacy define */
#define  PWR_CSR_UDSWRDY                     PWR_CSR_UDRDY

/* Legacy define */
#define  PWR_CSR_REGRDY                      PWR_CSR_VOSRDY

/******************************************************************************/
/*                                                                            */
/*                                    RNG                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RNG_CR register  *******************/
#define RNG_CR_RNGEN_Pos    (2U)                                               
#define RNG_CR_RNGEN_Msk    (0x1UL << RNG_CR_RNGEN_Pos)                         /*!< 0x00000004 */
#define RNG_CR_RNGEN        RNG_CR_RNGEN_Msk                                   
#define RNG_CR_IE_Pos       (3U)                                               
#define RNG_CR_IE_Msk       (0x1UL << RNG_CR_IE_Pos)                            /*!< 0x00000008 */
#define RNG_CR_IE           RNG_CR_IE_Msk                                      

/********************  Bits definition for RNG_SR register  *******************/
#define RNG_SR_DRDY_Pos     (0U)                                               
#define RNG_SR_DRDY_Msk     (0x1UL << RNG_SR_DRDY_Pos)                          /*!< 0x00000001 */
#define RNG_SR_DRDY         RNG_SR_DRDY_Msk                                    
#define RNG_SR_CECS_Pos     (1U)                                               
#define RNG_SR_CECS_Msk     (0x1UL << RNG_SR_CECS_Pos)                          /*!< 0x00000002 */
#define RNG_SR_CECS         RNG_SR_CECS_Msk                                    
#define RNG_SR_SECS_Pos     (2U)                                               
#define RNG_SR_SECS_Msk     (0x1UL << RNG_SR_SECS_Pos)                          /*!< 0x00000004 */
#define RNG_SR_SECS         RNG_SR_SECS_Msk                                    
#define RNG_SR_CEIS_Pos     (5U)                                               
#define RNG_SR_CEIS_Msk     (0x1UL << RNG_SR_CEIS_Pos)                          /*!< 0x00000020 */
#define RNG_SR_CEIS         RNG_SR_CEIS_Msk                                    
#define RNG_SR_SEIS_Pos     (6U)                                               
#define RNG_SR_SEIS_Msk     (0x1UL << RNG_SR_SEIS_Pos)                          /*!< 0x00000040 */
#define RNG_SR_SEIS         RNG_SR_SEIS_Msk                                    

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/*
 * @brief Specific device feature definitions  (not present on all devices in the STM32F4 serie)
 */
#define RTC_TAMPER2_SUPPORT  /*!< TAMPER 2 feature support */
#define RTC_AF2_SUPPORT /*!< RTC Alternate Function 2 mapping support */
/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_PM_Pos                 (22U)                                    
#define RTC_TR_PM_Msk                 (0x1UL << RTC_TR_PM_Pos)                  /*!< 0x00400000 */
#define RTC_TR_PM                     RTC_TR_PM_Msk                            
#define RTC_TR_HT_Pos                 (20U)                                    
#define RTC_TR_HT_Msk                 (0x3UL << RTC_TR_HT_Pos)                  /*!< 0x00300000 */
#define RTC_TR_HT                     RTC_TR_HT_Msk                            
#define RTC_TR_HT_0                   (0x1UL << RTC_TR_HT_Pos)                  /*!< 0x00100000 */
#define RTC_TR_HT_1                   (0x2UL << RTC_TR_HT_Pos)                  /*!< 0x00200000 */
#define RTC_TR_HU_Pos                 (16U)                                    
#define RTC_TR_HU_Msk                 (0xFUL << RTC_TR_HU_Pos)                  /*!< 0x000F0000 */
#define RTC_TR_HU                     RTC_TR_HU_Msk                            
#define RTC_TR_HU_0                   (0x1UL << RTC_TR_HU_Pos)                  /*!< 0x00010000 */
#define RTC_TR_HU_1                   (0x2UL << RTC_TR_HU_Pos)                  /*!< 0x00020000 */
#define RTC_TR_HU_2                   (0x4UL << RTC_TR_HU_Pos)                  /*!< 0x00040000 */
#define RTC_TR_HU_3                   (0x8UL << RTC_TR_HU_Pos)                  /*!< 0x00080000 */
#define RTC_TR_MNT_Pos                (12U)                                    
#define RTC_TR_MNT_Msk                (0x7UL << RTC_TR_MNT_Pos)                 /*!< 0x00007000 */
#define RTC_TR_MNT                    RTC_TR_MNT_Msk                           
#define RTC_TR_MNT_0                  (0x1UL << RTC_TR_MNT_Pos)                 /*!< 0x00001000 */
#define RTC_TR_MNT_1                  (0x2UL << RTC_TR_MNT_Pos)                 /*!< 0x00002000 */
#define RTC_TR_MNT_2                  (0x4UL << RTC_TR_MNT_Pos)                 /*!< 0x00004000 */
#define RTC_TR_MNU_Pos                (8U)                                     
#define RTC_TR_MNU_Msk                (0xFUL << RTC_TR_MNU_Pos)                 /*!< 0x00000F00 */
#define RTC_TR_MNU                    RTC_TR_MNU_Msk                           
#define RTC_TR_MNU_0                  (0x1UL << RTC_TR_MNU_Pos)                 /*!< 0x00000100 */
#define RTC_TR_MNU_1                  (0x2UL << RTC_TR_MNU_Pos)                 /*!< 0x00000200 */
#define RTC_TR_MNU_2                  (0x4UL << RTC_TR_MNU_Pos)                 /*!< 0x00000400 */
#define RTC_TR_MNU_3                  (0x8UL << RTC_TR_MNU_Pos)                 /*!< 0x00000800 */
#define RTC_TR_ST_Pos                 (4U)                                     
#define RTC_TR_ST_Msk                 (0x7UL << RTC_TR_ST_Pos)                  /*!< 0x00000070 */
#define RTC_TR_ST                     RTC_TR_ST_Msk                            
#define RTC_TR_ST_0                   (0x1UL << RTC_TR_ST_Pos)                  /*!< 0x00000010 */
#define RTC_TR_ST_1                   (0x2UL << RTC_TR_ST_Pos)                  /*!< 0x00000020 */
#define RTC_TR_ST_2                   (0x4UL << RTC_TR_ST_Pos)                  /*!< 0x00000040 */
#define RTC_TR_SU_Pos                 (0U)                                     
#define RTC_TR_SU_Msk                 (0xFUL << RTC_TR_SU_Pos)                  /*!< 0x0000000F */
#define RTC_TR_SU                     RTC_TR_SU_Msk                            
#define RTC_TR_SU_0                   (0x1UL << RTC_TR_SU_Pos)                  /*!< 0x00000001 */
#define RTC_TR_SU_1                   (0x2UL << RTC_TR_SU_Pos)                  /*!< 0x00000002 */
#define RTC_TR_SU_2                   (0x4UL << RTC_TR_SU_Pos)                  /*!< 0x00000004 */
#define RTC_TR_SU_3                   (0x8UL << RTC_TR_SU_Pos)                  /*!< 0x00000008 */

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_YT_Pos                 (20U)                                    
#define RTC_DR_YT_Msk                 (0xFUL << RTC_DR_YT_Pos)                  /*!< 0x00F00000 */
#define RTC_DR_YT                     RTC_DR_YT_Msk                            
#define RTC_DR_YT_0                   (0x1UL << RTC_DR_YT_Pos)                  /*!< 0x00100000 */
#define RTC_DR_YT_1                   (0x2UL << RTC_DR_YT_Pos)                  /*!< 0x00200000 */
#define RTC_DR_YT_2                   (0x4UL << RTC_DR_YT_Pos)                  /*!< 0x00400000 */
#define RTC_DR_YT_3                   (0x8UL << RTC_DR_YT_Pos)                  /*!< 0x00800000 */
#define RTC_DR_YU_Pos                 (16U)                                    
#define RTC_DR_YU_Msk                 (0xFUL << RTC_DR_YU_Pos)                  /*!< 0x000F0000 */
#define RTC_DR_YU                     RTC_DR_YU_Msk                            
#define RTC_DR_YU_0                   (0x1UL << RTC_DR_YU_Pos)                  /*!< 0x00010000 */
#define RTC_DR_YU_1                   (0x2UL << RTC_DR_YU_Pos)                  /*!< 0x00020000 */
#define RTC_DR_YU_2                   (0x4UL << RTC_DR_YU_Pos)                  /*!< 0x00040000 */
#define RTC_DR_YU_3                   (0x8UL << RTC_DR_YU_Pos)                  /*!< 0x00080000 */
#define RTC_DR_WDU_Pos                (13U)                                    
#define RTC_DR_WDU_Msk                (0x7UL << RTC_DR_WDU_Pos)                 /*!< 0x0000E000 */
#define RTC_DR_WDU                    RTC_DR_WDU_Msk                           
#define RTC_DR_WDU_0                  (0x1UL << RTC_DR_WDU_Pos)                 /*!< 0x00002000 */
#define RTC_DR_WDU_1                  (0x2UL << RTC_DR_WDU_Pos)                 /*!< 0x00004000 */
#define RTC_DR_WDU_2                  (0x4UL << RTC_DR_WDU_Pos)                 /*!< 0x00008000 */
#define RTC_DR_MT_Pos                 (12U)                                    
#define RTC_DR_MT_Msk                 (0x1UL << RTC_DR_MT_Pos)                  /*!< 0x00001000 */
#define RTC_DR_MT                     RTC_DR_MT_Msk                            
#define RTC_DR_MU_Pos                 (8U)                                     
#define RTC_DR_MU_Msk                 (0xFUL << RTC_DR_MU_Pos)                  /*!< 0x00000F00 */
#define RTC_DR_MU                     RTC_DR_MU_Msk                            
#define RTC_DR_MU_0                   (0x1UL << RTC_DR_MU_Pos)                  /*!< 0x00000100 */
#define RTC_DR_MU_1                   (0x2UL << RTC_DR_MU_Pos)                  /*!< 0x00000200 */
#define RTC_DR_MU_2                   (0x4UL << RTC_DR_MU_Pos)                  /*!< 0x00000400 */
#define RTC_DR_MU_3                   (0x8UL << RTC_DR_MU_Pos)                  /*!< 0x00000800 */
#define RTC_DR_DT_Pos                 (4U)                                     
#define RTC_DR_DT_Msk                 (0x3UL << RTC_DR_DT_Pos)                  /*!< 0x00000030 */
#define RTC_DR_DT                     RTC_DR_DT_Msk                            
#define RTC_DR_DT_0                   (0x1UL << RTC_DR_DT_Pos)                  /*!< 0x00000010 */
#define RTC_DR_DT_1                   (0x2UL << RTC_DR_DT_Pos)                  /*!< 0x00000020 */
#define RTC_DR_DU_Pos                 (0U)                                     
#define RTC_DR_DU_Msk                 (0xFUL << RTC_DR_DU_Pos)                  /*!< 0x0000000F */
#define RTC_DR_DU                     RTC_DR_DU_Msk                            
#define RTC_DR_DU_0                   (0x1UL << RTC_DR_DU_Pos)                  /*!< 0x00000001 */
#define RTC_DR_DU_1                   (0x2UL << RTC_DR_DU_Pos)                  /*!< 0x00000002 */
#define RTC_DR_DU_2                   (0x4UL << RTC_DR_DU_Pos)                  /*!< 0x00000004 */
#define RTC_DR_DU_3                   (0x8UL << RTC_DR_DU_Pos)                  /*!< 0x00000008 */

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_COE_Pos                (23U)                                    
#define RTC_CR_COE_Msk                (0x1UL << RTC_CR_COE_Pos)                 /*!< 0x00800000 */
#define RTC_CR_COE                    RTC_CR_COE_Msk                           
#define RTC_CR_OSEL_Pos               (21U)                                    
#define RTC_CR_OSEL_Msk               (0x3UL << RTC_CR_OSEL_Pos)                /*!< 0x00600000 */
#define RTC_CR_OSEL                   RTC_CR_OSEL_Msk                          
#define RTC_CR_OSEL_0                 (0x1UL << RTC_CR_OSEL_Pos)                /*!< 0x00200000 */
#define RTC_CR_OSEL_1                 (0x2UL << RTC_CR_OSEL_Pos)                /*!< 0x00400000 */
#define RTC_CR_POL_Pos                (20U)                                    
#define RTC_CR_POL_Msk                (0x1UL << RTC_CR_POL_Pos)                 /*!< 0x00100000 */
#define RTC_CR_POL                    RTC_CR_POL_Msk                           
#define RTC_CR_COSEL_Pos              (19U)                                    
#define RTC_CR_COSEL_Msk              (0x1UL << RTC_CR_COSEL_Pos)               /*!< 0x00080000 */
#define RTC_CR_COSEL                  RTC_CR_COSEL_Msk                         
#define RTC_CR_BKP_Pos                 (18U)                                   
#define RTC_CR_BKP_Msk                 (0x1UL << RTC_CR_BKP_Pos)                /*!< 0x00040000 */
#define RTC_CR_BKP                     RTC_CR_BKP_Msk                          
#define RTC_CR_SUB1H_Pos              (17U)                                    
#define RTC_CR_SUB1H_Msk              (0x1UL << RTC_CR_SUB1H_Pos)               /*!< 0x00020000 */
#define RTC_CR_SUB1H                  RTC_CR_SUB1H_Msk                         
#define RTC_CR_ADD1H_Pos              (16U)                                    
#define RTC_CR_ADD1H_Msk              (0x1UL << RTC_CR_ADD1H_Pos)               /*!< 0x00010000 */
#define RTC_CR_ADD1H                  RTC_CR_ADD1H_Msk                         
#define RTC_CR_TSIE_Pos               (15U)                                    
#define RTC_CR_TSIE_Msk               (0x1UL << RTC_CR_TSIE_Pos)                /*!< 0x00008000 */
#define RTC_CR_TSIE                   RTC_CR_TSIE_Msk                          
#define RTC_CR_WUTIE_Pos              (14U)                                    
#define RTC_CR_WUTIE_Msk              (0x1UL << RTC_CR_WUTIE_Pos)               /*!< 0x00004000 */
#define RTC_CR_WUTIE                  RTC_CR_WUTIE_Msk                         
#define RTC_CR_ALRBIE_Pos             (13U)                                    
#define RTC_CR_ALRBIE_Msk             (0x1UL << RTC_CR_ALRBIE_Pos)              /*!< 0x00002000 */
#define RTC_CR_ALRBIE                 RTC_CR_ALRBIE_Msk                        
#define RTC_CR_ALRAIE_Pos             (12U)                                    
#define RTC_CR_ALRAIE_Msk             (0x1UL << RTC_CR_ALRAIE_Pos)              /*!< 0x00001000 */
#define RTC_CR_ALRAIE                 RTC_CR_ALRAIE_Msk                        
#define RTC_CR_TSE_Pos                (11U)                                    
#define RTC_CR_TSE_Msk                (0x1UL << RTC_CR_TSE_Pos)                 /*!< 0x00000800 */
#define RTC_CR_TSE                    RTC_CR_TSE_Msk                           
#define RTC_CR_WUTE_Pos               (10U)                                    
#define RTC_CR_WUTE_Msk               (0x1UL << RTC_CR_WUTE_Pos)                /*!< 0x00000400 */
#define RTC_CR_WUTE                   RTC_CR_WUTE_Msk                          
#define RTC_CR_ALRBE_Pos              (9U)                                     
#define RTC_CR_ALRBE_Msk              (0x1UL << RTC_CR_ALRBE_Pos)               /*!< 0x00000200 */
#define RTC_CR_ALRBE                  RTC_CR_ALRBE_Msk                         
#define RTC_CR_ALRAE_Pos              (8U)                                     
#define RTC_CR_ALRAE_Msk              (0x1UL << RTC_CR_ALRAE_Pos)               /*!< 0x00000100 */
#define RTC_CR_ALRAE                  RTC_CR_ALRAE_Msk                         
#define RTC_CR_DCE_Pos                (7U)                                     
#define RTC_CR_DCE_Msk                (0x1UL << RTC_CR_DCE_Pos)                 /*!< 0x00000080 */
#define RTC_CR_DCE                    RTC_CR_DCE_Msk                           
#define RTC_CR_FMT_Pos                (6U)                                     
#define RTC_CR_FMT_Msk                (0x1UL << RTC_CR_FMT_Pos)                 /*!< 0x00000040 */
#define RTC_CR_FMT                    RTC_CR_FMT_Msk                           
#define RTC_CR_BYPSHAD_Pos            (5U)                                     
#define RTC_CR_BYPSHAD_Msk            (0x1UL << RTC_CR_BYPSHAD_Pos)             /*!< 0x00000020 */
#define RTC_CR_BYPSHAD                RTC_CR_BYPSHAD_Msk                       
#define RTC_CR_REFCKON_Pos            (4U)                                     
#define RTC_CR_REFCKON_Msk            (0x1UL << RTC_CR_REFCKON_Pos)             /*!< 0x00000010 */
#define RTC_CR_REFCKON                RTC_CR_REFCKON_Msk                       
#define RTC_CR_TSEDGE_Pos             (3U)                                     
#define RTC_CR_TSEDGE_Msk             (0x1UL << RTC_CR_TSEDGE_Pos)              /*!< 0x00000008 */
#define RTC_CR_TSEDGE                 RTC_CR_TSEDGE_Msk                        
#define RTC_CR_WUCKSEL_Pos            (0U)                                     
#define RTC_CR_WUCKSEL_Msk            (0x7UL << RTC_CR_WUCKSEL_Pos)             /*!< 0x00000007 */
#define RTC_CR_WUCKSEL                RTC_CR_WUCKSEL_Msk                       
#define RTC_CR_WUCKSEL_0              (0x1UL << RTC_CR_WUCKSEL_Pos)             /*!< 0x00000001 */
#define RTC_CR_WUCKSEL_1              (0x2UL << RTC_CR_WUCKSEL_Pos)             /*!< 0x00000002 */
#define RTC_CR_WUCKSEL_2              (0x4UL << RTC_CR_WUCKSEL_Pos)             /*!< 0x00000004 */

/* Legacy defines */
#define RTC_CR_BCK                     RTC_CR_BKP

/********************  Bits definition for RTC_ISR register  ******************/
#define RTC_ISR_RECALPF_Pos           (16U)                                    
#define RTC_ISR_RECALPF_Msk           (0x1UL << RTC_ISR_RECALPF_Pos)            /*!< 0x00010000 */
#define RTC_ISR_RECALPF               RTC_ISR_RECALPF_Msk                      
#define RTC_ISR_TAMP1F_Pos            (13U)                                    
#define RTC_ISR_TAMP1F_Msk            (0x1UL << RTC_ISR_TAMP1F_Pos)             /*!< 0x00002000 */
#define RTC_ISR_TAMP1F                RTC_ISR_TAMP1F_Msk                       
#define RTC_ISR_TAMP2F_Pos            (14U)                                    
#define RTC_ISR_TAMP2F_Msk            (0x1UL << RTC_ISR_TAMP2F_Pos)             /*!< 0x00004000 */
#define RTC_ISR_TAMP2F                RTC_ISR_TAMP2F_Msk                       
#define RTC_ISR_TSOVF_Pos             (12U)                                    
#define RTC_ISR_TSOVF_Msk             (0x1UL << RTC_ISR_TSOVF_Pos)              /*!< 0x00001000 */
#define RTC_ISR_TSOVF                 RTC_ISR_TSOVF_Msk                        
#define RTC_ISR_TSF_Pos               (11U)                                    
#define RTC_ISR_TSF_Msk               (0x1UL << RTC_ISR_TSF_Pos)                /*!< 0x00000800 */
#define RTC_ISR_TSF                   RTC_ISR_TSF_Msk                          
#define RTC_ISR_WUTF_Pos              (10U)                                    
#define RTC_ISR_WUTF_Msk              (0x1UL << RTC_ISR_WUTF_Pos)               /*!< 0x00000400 */
#define RTC_ISR_WUTF                  RTC_ISR_WUTF_Msk                         
#define RTC_ISR_ALRBF_Pos             (9U)                                     
#define RTC_ISR_ALRBF_Msk             (0x1UL << RTC_ISR_ALRBF_Pos)              /*!< 0x00000200 */
#define RTC_ISR_ALRBF                 RTC_ISR_ALRBF_Msk                        
#define RTC_ISR_ALRAF_Pos             (8U)                                     
#define RTC_ISR_ALRAF_Msk             (0x1UL << RTC_ISR_ALRAF_Pos)              /*!< 0x00000100 */
#define RTC_ISR_ALRAF                 RTC_ISR_ALRAF_Msk                        
#define RTC_ISR_INIT_Pos              (7U)                                     
#define RTC_ISR_INIT_Msk              (0x1UL << RTC_ISR_INIT_Pos)               /*!< 0x00000080 */
#define RTC_ISR_INIT                  RTC_ISR_INIT_Msk                         
#define RTC_ISR_INITF_Pos             (6U)                                     
#define RTC_ISR_INITF_Msk             (0x1UL << RTC_ISR_INITF_Pos)              /*!< 0x00000040 */
#define RTC_ISR_INITF                 RTC_ISR_INITF_Msk                        
#define RTC_ISR_RSF_Pos               (5U)                                     
#define RTC_ISR_RSF_Msk               (0x1UL << RTC_ISR_RSF_Pos)                /*!< 0x00000020 */
#define RTC_ISR_RSF                   RTC_ISR_RSF_Msk                          
#define RTC_ISR_INITS_Pos             (4U)                                     
#define RTC_ISR_INITS_Msk             (0x1UL << RTC_ISR_INITS_Pos)              /*!< 0x00000010 */
#define RTC_ISR_INITS                 RTC_ISR_INITS_Msk                        
#define RTC_ISR_SHPF_Pos              (3U)                                     
#define RTC_ISR_SHPF_Msk              (0x1UL << RTC_ISR_SHPF_Pos)               /*!< 0x00000008 */
#define RTC_ISR_SHPF                  RTC_ISR_SHPF_Msk                         
#define RTC_ISR_WUTWF_Pos             (2U)                                     
#define RTC_ISR_WUTWF_Msk             (0x1UL << RTC_ISR_WUTWF_Pos)              /*!< 0x00000004 */
#define RTC_ISR_WUTWF                 RTC_ISR_WUTWF_Msk                        
#define RTC_ISR_ALRBWF_Pos            (1U)                                     
#define RTC_ISR_ALRBWF_Msk            (0x1UL << RTC_ISR_ALRBWF_Pos)             /*!< 0x00000002 */
#define RTC_ISR_ALRBWF                RTC_ISR_ALRBWF_Msk                       
#define RTC_ISR_ALRAWF_Pos            (0U)                                     
#define RTC_ISR_ALRAWF_Msk            (0x1UL << RTC_ISR_ALRAWF_Pos)             /*!< 0x00000001 */
#define RTC_ISR_ALRAWF                RTC_ISR_ALRAWF_Msk                       

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_A_Pos         (16U)                                    
#define RTC_PRER_PREDIV_A_Msk         (0x7FUL << RTC_PRER_PREDIV_A_Pos)         /*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A             RTC_PRER_PREDIV_A_Msk                    
#define RTC_PRER_PREDIV_S_Pos         (0U)                                     
#define RTC_PRER_PREDIV_S_Msk         (0x7FFFUL << RTC_PRER_PREDIV_S_Pos)       /*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S             RTC_PRER_PREDIV_S_Msk                    

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT_Pos              (0U)                                     
#define RTC_WUTR_WUT_Msk              (0xFFFFUL << RTC_WUTR_WUT_Pos)            /*!< 0x0000FFFF */
#define RTC_WUTR_WUT                  RTC_WUTR_WUT_Msk                         

/********************  Bits definition for RTC_CALIBR register  ***************/
#define RTC_CALIBR_DCS_Pos            (7U)                                     
#define RTC_CALIBR_DCS_Msk            (0x1UL << RTC_CALIBR_DCS_Pos)             /*!< 0x00000080 */
#define RTC_CALIBR_DCS                RTC_CALIBR_DCS_Msk                       
#define RTC_CALIBR_DC_Pos             (0U)                                     
#define RTC_CALIBR_DC_Msk             (0x1FUL << RTC_CALIBR_DC_Pos)             /*!< 0x0000001F */
#define RTC_CALIBR_DC                 RTC_CALIBR_DC_Msk                        

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_MSK4_Pos           (31U)                                    
#define RTC_ALRMAR_MSK4_Msk           (0x1UL << RTC_ALRMAR_MSK4_Pos)            /*!< 0x80000000 */
#define RTC_ALRMAR_MSK4               RTC_ALRMAR_MSK4_Msk                      
#define RTC_ALRMAR_WDSEL_Pos          (30U)                                    
#define RTC_ALRMAR_WDSEL_Msk          (0x1UL << RTC_ALRMAR_WDSEL_Pos)           /*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL              RTC_ALRMAR_WDSEL_Msk                     
#define RTC_ALRMAR_DT_Pos             (28U)                                    
#define RTC_ALRMAR_DT_Msk             (0x3UL << RTC_ALRMAR_DT_Pos)              /*!< 0x30000000 */
#define RTC_ALRMAR_DT                 RTC_ALRMAR_DT_Msk                        
#define RTC_ALRMAR_DT_0               (0x1UL << RTC_ALRMAR_DT_Pos)              /*!< 0x10000000 */
#define RTC_ALRMAR_DT_1               (0x2UL << RTC_ALRMAR_DT_Pos)              /*!< 0x20000000 */
#define RTC_ALRMAR_DU_Pos             (24U)                                    
#define RTC_ALRMAR_DU_Msk             (0xFUL << RTC_ALRMAR_DU_Pos)              /*!< 0x0F000000 */
#define RTC_ALRMAR_DU                 RTC_ALRMAR_DU_Msk                        
#define RTC_ALRMAR_DU_0               (0x1UL << RTC_ALRMAR_DU_Pos)              /*!< 0x01000000 */
#define RTC_ALRMAR_DU_1               (0x2UL << RTC_ALRMAR_DU_Pos)              /*!< 0x02000000 */
#define RTC_ALRMAR_DU_2               (0x4UL << RTC_ALRMAR_DU_Pos)              /*!< 0x04000000 */
#define RTC_ALRMAR_DU_3               (0x8UL << RTC_ALRMAR_DU_Pos)              /*!< 0x08000000 */
#define RTC_ALRMAR_MSK3_Pos           (23U)                                    
#define RTC_ALRMAR_MSK3_Msk           (0x1UL << RTC_ALRMAR_MSK3_Pos)            /*!< 0x00800000 */
#define RTC_ALRMAR_MSK3               RTC_ALRMAR_MSK3_Msk                      
#define RTC_ALRMAR_PM_Pos             (22U)                                    
#define RTC_ALRMAR_PM_Msk             (0x1UL << RTC_ALRMAR_PM_Pos)              /*!< 0x00400000 */
#define RTC_ALRMAR_PM                 RTC_ALRMAR_PM_Msk                        
#define RTC_ALRMAR_HT_Pos             (20U)                                    
#define RTC_ALRMAR_HT_Msk             (0x3UL << RTC_ALRMAR_HT_Pos)              /*!< 0x00300000 */
#define RTC_ALRMAR_HT                 RTC_ALRMAR_HT_Msk                        
#define RTC_ALRMAR_HT_0               (0x1UL << RTC_ALRMAR_HT_Pos)              /*!< 0x00100000 */
#define RTC_ALRMAR_HT_1               (0x2UL << RTC_ALRMAR_HT_Pos)              /*!< 0x00200000 */
#define RTC_ALRMAR_HU_Pos             (16U)                                    
#define RTC_ALRMAR_HU_Msk             (0xFUL << RTC_ALRMAR_HU_Pos)              /*!< 0x000F0000 */
#define RTC_ALRMAR_HU                 RTC_ALRMAR_HU_Msk                        
#define RTC_ALRMAR_HU_0               (0x1UL << RTC_ALRMAR_HU_Pos)              /*!< 0x00010000 */
#define RTC_ALRMAR_HU_1               (0x2UL << RTC_ALRMAR_HU_Pos)              /*!< 0x00020000 */
#define RTC_ALRMAR_HU_2               (0x4UL << RTC_ALRMAR_HU_Pos)              /*!< 0x00040000 */
#define RTC_ALRMAR_HU_3               (0x8UL << RTC_ALRMAR_HU_Pos)              /*!< 0x00080000 */
#define RTC_ALRMAR_MSK2_Pos           (15U)                                    
#define RTC_ALRMAR_MSK2_Msk           (0x1UL << RTC_ALRMAR_MSK2_Pos)            /*!< 0x00008000 */
#define RTC_ALRMAR_MSK2               RTC_ALRMAR_MSK2_Msk                      
#define RTC_ALRMAR_MNT_Pos            (12U)                                    
#define RTC_ALRMAR_MNT_Msk            (0x7UL << RTC_ALRMAR_MNT_Pos)             /*!< 0x00007000 */
#define RTC_ALRMAR_MNT                RTC_ALRMAR_MNT_Msk                       
#define RTC_ALRMAR_MNT_0              (0x1UL << RTC_ALRMAR_MNT_Pos)             /*!< 0x00001000 */
#define RTC_ALRMAR_MNT_1              (0x2UL << RTC_ALRMAR_MNT_Pos)             /*!< 0x00002000 */
#define RTC_ALRMAR_MNT_2              (0x4UL << RTC_ALRMAR_MNT_Pos)             /*!< 0x00004000 */
#define RTC_ALRMAR_MNU_Pos            (8U)                                     
#define RTC_ALRMAR_MNU_Msk            (0xFUL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000F00 */
#define RTC_ALRMAR_MNU                RTC_ALRMAR_MNU_Msk                       
#define RTC_ALRMAR_MNU_0              (0x1UL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000100 */
#define RTC_ALRMAR_MNU_1              (0x2UL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000200 */
#define RTC_ALRMAR_MNU_2              (0x4UL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000400 */
#define RTC_ALRMAR_MNU_3              (0x8UL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000800 */
#define RTC_ALRMAR_MSK1_Pos           (7U)                                     
#define RTC_ALRMAR_MSK1_Msk           (0x1UL << RTC_ALRMAR_MSK1_Pos)            /*!< 0x00000080 */
#define RTC_ALRMAR_MSK1               RTC_ALRMAR_MSK1_Msk                      
#define RTC_ALRMAR_ST_Pos             (4U)                                     
#define RTC_ALRMAR_ST_Msk             (0x7UL << RTC_ALRMAR_ST_Pos)              /*!< 0x00000070 */
#define RTC_ALRMAR_ST                 RTC_ALRMAR_ST_Msk                        
#define RTC_ALRMAR_ST_0               (0x1UL << RTC_ALRMAR_ST_Pos)              /*!< 0x00000010 */
#define RTC_ALRMAR_ST_1               (0x2UL << RTC_ALRMAR_ST_Pos)              /*!< 0x00000020 */
#define RTC_ALRMAR_ST_2               (0x4UL << RTC_ALRMAR_ST_Pos)              /*!< 0x00000040 */
#define RTC_ALRMAR_SU_Pos             (0U)                                     
#define RTC_ALRMAR_SU_Msk             (0xFUL << RTC_ALRMAR_SU_Pos)              /*!< 0x0000000F */
#define RTC_ALRMAR_SU                 RTC_ALRMAR_SU_Msk                        
#define RTC_ALRMAR_SU_0               (0x1UL << RTC_ALRMAR_SU_Pos)              /*!< 0x00000001 */
#define RTC_ALRMAR_SU_1               (0x2UL << RTC_ALRMAR_SU_Pos)              /*!< 0x00000002 */
#define RTC_ALRMAR_SU_2               (0x4UL << RTC_ALRMAR_SU_Pos)              /*!< 0x00000004 */
#define RTC_ALRMAR_SU_3               (0x8UL << RTC_ALRMAR_SU_Pos)              /*!< 0x00000008 */

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_MSK4_Pos           (31U)                                    
#define RTC_ALRMBR_MSK4_Msk           (0x1UL << RTC_ALRMBR_MSK4_Pos)            /*!< 0x80000000 */
#define RTC_ALRMBR_MSK4               RTC_ALRMBR_MSK4_Msk                      
#define RTC_ALRMBR_WDSEL_Pos          (30U)                                    
#define RTC_ALRMBR_WDSEL_Msk          (0x1UL << RTC_ALRMBR_WDSEL_Pos)           /*!< 0x40000000 */
#define RTC_ALRMBR_WDSEL              RTC_ALRMBR_WDSEL_Msk                     
#define RTC_ALRMBR_DT_Pos             (28U)                                    
#define RTC_ALRMBR_DT_Msk             (0x3UL << RTC_ALRMBR_DT_Pos)              /*!< 0x30000000 */
#define RTC_ALRMBR_DT                 RTC_ALRMBR_DT_Msk                        
#define RTC_ALRMBR_DT_0               (0x1UL << RTC_ALRMBR_DT_Pos)              /*!< 0x10000000 */
#define RTC_ALRMBR_DT_1               (0x2UL << RTC_ALRMBR_DT_Pos)              /*!< 0x20000000 */
#define RTC_ALRMBR_DU_Pos             (24U)                                    
#define RTC_ALRMBR_DU_Msk             (0xFUL << RTC_ALRMBR_DU_Pos)              /*!< 0x0F000000 */
#define RTC_ALRMBR_DU                 RTC_ALRMBR_DU_Msk                        
#define RTC_ALRMBR_DU_0               (0x1UL << RTC_ALRMBR_DU_Pos)              /*!< 0x01000000 */
#define RTC_ALRMBR_DU_1               (0x2UL << RTC_ALRMBR_DU_Pos)              /*!< 0x02000000 */
#define RTC_ALRMBR_DU_2               (0x4UL << RTC_ALRMBR_DU_Pos)              /*!< 0x04000000 */
#define RTC_ALRMBR_DU_3               (0x8UL << RTC_ALRMBR_DU_Pos)              /*!< 0x08000000 */
#define RTC_ALRMBR_MSK3_Pos           (23U)                                    
#define RTC_ALRMBR_MSK3_Msk           (0x1UL << RTC_ALRMBR_MSK3_Pos)            /*!< 0x00800000 */
#define RTC_ALRMBR_MSK3               RTC_ALRMBR_MSK3_Msk                      
#define RTC_ALRMBR_PM_Pos             (22U)                                    
#define RTC_ALRMBR_PM_Msk             (0x1UL << RTC_ALRMBR_PM_Pos)              /*!< 0x00400000 */
#define RTC_ALRMBR_PM                 RTC_ALRMBR_PM_Msk                        
#define RTC_ALRMBR_HT_Pos             (20U)                                    
#define RTC_ALRMBR_HT_Msk             (0x3UL << RTC_ALRMBR_HT_Pos)              /*!< 0x00300000 */
#define RTC_ALRMBR_HT                 RTC_ALRMBR_HT_Msk                        
#define RTC_ALRMBR_HT_0               (0x1UL << RTC_ALRMBR_HT_Pos)              /*!< 0x00100000 */
#define RTC_ALRMBR_HT_1               (0x2UL << RTC_ALRMBR_HT_Pos)              /*!< 0x00200000 */
#define RTC_ALRMBR_HU_Pos             (16U)                                    
#define RTC_ALRMBR_HU_Msk             (0xFUL << RTC_ALRMBR_HU_Pos)              /*!< 0x000F0000 */
#define RTC_ALRMBR_HU                 RTC_ALRMBR_HU_Msk                        
#define RTC_ALRMBR_HU_0               (0x1UL << RTC_ALRMBR_HU_Pos)              /*!< 0x00010000 */
#define RTC_ALRMBR_HU_1               (0x2UL << RTC_ALRMBR_HU_Pos)              /*!< 0x00020000 */
#define RTC_ALRMBR_HU_2               (0x4UL << RTC_ALRMBR_HU_Pos)              /*!< 0x00040000 */
#define RTC_ALRMBR_HU_3               (0x8UL << RTC_ALRMBR_HU_Pos)              /*!< 0x00080000 */
#define RTC_ALRMBR_MSK2_Pos           (15U)                                    
#define RTC_ALRMBR_MSK2_Msk           (0x1UL << RTC_ALRMBR_MSK2_Pos)            /*!< 0x00008000 */
#define RTC_ALRMBR_MSK2               RTC_ALRMBR_MSK2_Msk                      
#define RTC_ALRMBR_MNT_Pos            (12U)                                    
#define RTC_ALRMBR_MNT_Msk            (0x7UL << RTC_ALRMBR_MNT_Pos)             /*!< 0x00007000 */
#define RTC_ALRMBR_MNT                RTC_ALRMBR_MNT_Msk                       
#define RTC_ALRMBR_MNT_0              (0x1UL << RTC_ALRMBR_MNT_Pos)             /*!< 0x00001000 */
#define RTC_ALRMBR_MNT_1              (0x2UL << RTC_ALRMBR_MNT_Pos)             /*!< 0x00002000 */
#define RTC_ALRMBR_MNT_2              (0x4UL << RTC_ALRMBR_MNT_Pos)             /*!< 0x00004000 */
#define RTC_ALRMBR_MNU_Pos            (8U)                                     
#define RTC_ALRMBR_MNU_Msk            (0xFUL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000F00 */
#define RTC_ALRMBR_MNU                RTC_ALRMBR_MNU_Msk                       
#define RTC_ALRMBR_MNU_0              (0x1UL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000100 */
#define RTC_ALRMBR_MNU_1              (0x2UL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000200 */
#define RTC_ALRMBR_MNU_2              (0x4UL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000400 */
#define RTC_ALRMBR_MNU_3              (0x8UL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000800 */
#define RTC_ALRMBR_MSK1_Pos           (7U)                                     
#define RTC_ALRMBR_MSK1_Msk           (0x1UL << RTC_ALRMBR_MSK1_Pos)            /*!< 0x00000080 */
#define RTC_ALRMBR_MSK1               RTC_ALRMBR_MSK1_Msk                      
#define RTC_ALRMBR_ST_Pos             (4U)                                     
#define RTC_ALRMBR_ST_Msk             (0x7UL << RTC_ALRMBR_ST_Pos)              /*!< 0x00000070 */
#define RTC_ALRMBR_ST                 RTC_ALRMBR_ST_Msk                        
#define RTC_ALRMBR_ST_0               (0x1UL << RTC_ALRMBR_ST_Pos)              /*!< 0x00000010 */
#define RTC_ALRMBR_ST_1               (0x2UL << RTC_ALRMBR_ST_Pos)              /*!< 0x00000020 */
#define RTC_ALRMBR_ST_2               (0x4UL << RTC_ALRMBR_ST_Pos)              /*!< 0x00000040 */
#define RTC_ALRMBR_SU_Pos             (0U)                                     
#define RTC_ALRMBR_SU_Msk             (0xFUL << RTC_ALRMBR_SU_Pos)              /*!< 0x0000000F */
#define RTC_ALRMBR_SU                 RTC_ALRMBR_SU_Msk                        
#define RTC_ALRMBR_SU_0               (0x1UL << RTC_ALRMBR_SU_Pos)              /*!< 0x00000001 */
#define RTC_ALRMBR_SU_1               (0x2UL << RTC_ALRMBR_SU_Pos)              /*!< 0x00000002 */
#define RTC_ALRMBR_SU_2               (0x4UL << RTC_ALRMBR_SU_Pos)              /*!< 0x00000004 */
#define RTC_ALRMBR_SU_3               (0x8UL << RTC_ALRMBR_SU_Pos)              /*!< 0x00000008 */

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY_Pos               (0U)                                     
#define RTC_WPR_KEY_Msk               (0xFFUL << RTC_WPR_KEY_Pos)               /*!< 0x000000FF */
#define RTC_WPR_KEY                   RTC_WPR_KEY_Msk                          

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS_Pos                (0U)                                     
#define RTC_SSR_SS_Msk                (0xFFFFUL << RTC_SSR_SS_Pos)              /*!< 0x0000FFFF */
#define RTC_SSR_SS                    RTC_SSR_SS_Msk                           

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS_Pos          (0U)                                     
#define RTC_SHIFTR_SUBFS_Msk          (0x7FFFUL << RTC_SHIFTR_SUBFS_Pos)        /*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS              RTC_SHIFTR_SUBFS_Msk                     
#define RTC_SHIFTR_ADD1S_Pos          (31U)                                    
#define RTC_SHIFTR_ADD1S_Msk          (0x1UL << RTC_SHIFTR_ADD1S_Pos)           /*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S              RTC_SHIFTR_ADD1S_Msk                     

/********************  Bits definition for RTC_TSTR register  *****************/
#define RTC_TSTR_PM_Pos               (22U)                                    
#define RTC_TSTR_PM_Msk               (0x1UL << RTC_TSTR_PM_Pos)                /*!< 0x00400000 */
#define RTC_TSTR_PM                   RTC_TSTR_PM_Msk                          
#define RTC_TSTR_HT_Pos               (20U)                                    
#define RTC_TSTR_HT_Msk               (0x3UL << RTC_TSTR_HT_Pos)                /*!< 0x00300000 */
#define RTC_TSTR_HT                   RTC_TSTR_HT_Msk                          
#define RTC_TSTR_HT_0                 (0x1UL << RTC_TSTR_HT_Pos)                /*!< 0x00100000 */
#define RTC_TSTR_HT_1                 (0x2UL << RTC_TSTR_HT_Pos)                /*!< 0x00200000 */
#define RTC_TSTR_HU_Pos               (16U)                                    
#define RTC_TSTR_HU_Msk               (0xFUL << RTC_TSTR_HU_Pos)                /*!< 0x000F0000 */
#define RTC_TSTR_HU                   RTC_TSTR_HU_Msk                          
#define RTC_TSTR_HU_0                 (0x1UL << RTC_TSTR_HU_Pos)                /*!< 0x00010000 */
#define RTC_TSTR_HU_1                 (0x2UL << RTC_TSTR_HU_Pos)                /*!< 0x00020000 */
#define RTC_TSTR_HU_2                 (0x4UL << RTC_TSTR_HU_Pos)                /*!< 0x00040000 */
#define RTC_TSTR_HU_3                 (0x8UL << RTC_TSTR_HU_Pos)                /*!< 0x00080000 */
#define RTC_TSTR_MNT_Pos              (12U)                                    
#define RTC_TSTR_MNT_Msk              (0x7UL << RTC_TSTR_MNT_Pos)               /*!< 0x00007000 */
#define RTC_TSTR_MNT                  RTC_TSTR_MNT_Msk                         
#define RTC_TSTR_MNT_0                (0x1UL << RTC_TSTR_MNT_Pos)               /*!< 0x00001000 */
#define RTC_TSTR_MNT_1                (0x2UL << RTC_TSTR_MNT_Pos)               /*!< 0x00002000 */
#define RTC_TSTR_MNT_2                (0x4UL << RTC_TSTR_MNT_Pos)               /*!< 0x00004000 */
#define RTC_TSTR_MNU_Pos              (8U)                                     
#define RTC_TSTR_MNU_Msk              (0xFUL << RTC_TSTR_MNU_Pos)               /*!< 0x00000F00 */
#define RTC_TSTR_MNU                  RTC_TSTR_MNU_Msk                         
#define RTC_TSTR_MNU_0                (0x1UL << RTC_TSTR_MNU_Pos)               /*!< 0x00000100 */
#define RTC_TSTR_MNU_1                (0x2UL << RTC_TSTR_MNU_Pos)               /*!< 0x00000200 */
#define RTC_TSTR_MNU_2                (0x4UL << RTC_TSTR_MNU_Pos)               /*!< 0x00000400 */
#define RTC_TSTR_MNU_3                (0x8UL << RTC_TSTR_MNU_Pos)               /*!< 0x00000800 */
#define RTC_TSTR_ST_Pos               (4U)                                     
#define RTC_TSTR_ST_Msk               (0x7UL << RTC_TSTR_ST_Pos)                /*!< 0x00000070 */
#define RTC_TSTR_ST                   RTC_TSTR_ST_Msk                          
#define RTC_TSTR_ST_0                 (0x1UL << RTC_TSTR_ST_Pos)                /*!< 0x00000010 */
#define RTC_TSTR_ST_1                 (0x2UL << RTC_TSTR_ST_Pos)                /*!< 0x00000020 */
#define RTC_TSTR_ST_2                 (0x4UL << RTC_TSTR_ST_Pos)                /*!< 0x00000040 */
#define RTC_TSTR_SU_Pos               (0U)                                     
#define RTC_TSTR_SU_Msk               (0xFUL << RTC_TSTR_SU_Pos)                /*!< 0x0000000F */
#define RTC_TSTR_SU                   RTC_TSTR_SU_Msk                          
#define RTC_TSTR_SU_0                 (0x1UL << RTC_TSTR_SU_Pos)                /*!< 0x00000001 */
#define RTC_TSTR_SU_1                 (0x2UL << RTC_TSTR_SU_Pos)                /*!< 0x00000002 */
#define RTC_TSTR_SU_2                 (0x4UL << RTC_TSTR_SU_Pos)                /*!< 0x00000004 */
#define RTC_TSTR_SU_3                 (0x8UL << RTC_TSTR_SU_Pos)                /*!< 0x00000008 */

/********************  Bits definition for RTC_TSDR register  *****************/
#define RTC_TSDR_WDU_Pos              (13U)                                    
#define RTC_TSDR_WDU_Msk              (0x7UL << RTC_TSDR_WDU_Pos)               /*!< 0x0000E000 */
#define RTC_TSDR_WDU                  RTC_TSDR_WDU_Msk                         
#define RTC_TSDR_WDU_0                (0x1UL << RTC_TSDR_WDU_Pos)               /*!< 0x00002000 */
#define RTC_TSDR_WDU_1                (0x2UL << RTC_TSDR_WDU_Pos)               /*!< 0x00004000 */
#define RTC_TSDR_WDU_2                (0x4UL << RTC_TSDR_WDU_Pos)               /*!< 0x00008000 */
#define RTC_TSDR_MT_Pos               (12U)                                    
#define RTC_TSDR_MT_Msk               (0x1UL << RTC_TSDR_MT_Pos)                /*!< 0x00001000 */
#define RTC_TSDR_MT                   RTC_TSDR_MT_Msk                          
#define RTC_TSDR_MU_Pos               (8U)                                     
#define RTC_TSDR_MU_Msk               (0xFUL << RTC_TSDR_MU_Pos)                /*!< 0x00000F00 */
#define RTC_TSDR_MU                   RTC_TSDR_MU_Msk                          
#define RTC_TSDR_MU_0                 (0x1UL << RTC_TSDR_MU_Pos)                /*!< 0x00000100 */
#define RTC_TSDR_MU_1                 (0x2UL << RTC_TSDR_MU_Pos)                /*!< 0x00000200 */
#define RTC_TSDR_MU_2                 (0x4UL << RTC_TSDR_MU_Pos)                /*!< 0x00000400 */
#define RTC_TSDR_MU_3                 (0x8UL << RTC_TSDR_MU_Pos)                /*!< 0x00000800 */
#define RTC_TSDR_DT_Pos               (4U)                                     
#define RTC_TSDR_DT_Msk               (0x3UL << RTC_TSDR_DT_Pos)                /*!< 0x00000030 */
#define RTC_TSDR_DT                   RTC_TSDR_DT_Msk                          
#define RTC_TSDR_DT_0                 (0x1UL << RTC_TSDR_DT_Pos)                /*!< 0x00000010 */
#define RTC_TSDR_DT_1                 (0x2UL << RTC_TSDR_DT_Pos)                /*!< 0x00000020 */
#define RTC_TSDR_DU_Pos               (0U)                                     
#define RTC_TSDR_DU_Msk               (0xFUL << RTC_TSDR_DU_Pos)                /*!< 0x0000000F */
#define RTC_TSDR_DU                   RTC_TSDR_DU_Msk                          
#define RTC_TSDR_DU_0                 (0x1UL << RTC_TSDR_DU_Pos)                /*!< 0x00000001 */
#define RTC_TSDR_DU_1                 (0x2UL << RTC_TSDR_DU_Pos)                /*!< 0x00000002 */
#define RTC_TSDR_DU_2                 (0x4UL << RTC_TSDR_DU_Pos)                /*!< 0x00000004 */
#define RTC_TSDR_DU_3                 (0x8UL << RTC_TSDR_DU_Pos)                /*!< 0x00000008 */

/********************  Bits definition for RTC_TSSSR register  ****************/
#define RTC_TSSSR_SS_Pos              (0U)                                     
#define RTC_TSSSR_SS_Msk              (0xFFFFUL << RTC_TSSSR_SS_Pos)            /*!< 0x0000FFFF */
#define RTC_TSSSR_SS                  RTC_TSSSR_SS_Msk                         

/********************  Bits definition for RTC_CAL register  *****************/
#define RTC_CALR_CALP_Pos             (15U)                                    
#define RTC_CALR_CALP_Msk             (0x1UL << RTC_CALR_CALP_Pos)              /*!< 0x00008000 */
#define RTC_CALR_CALP                 RTC_CALR_CALP_Msk                        
#define RTC_CALR_CALW8_Pos            (14U)                                    
#define RTC_CALR_CALW8_Msk            (0x1UL << RTC_CALR_CALW8_Pos)             /*!< 0x00004000 */
#define RTC_CALR_CALW8                RTC_CALR_CALW8_Msk                       
#define RTC_CALR_CALW16_Pos           (13U)                                    
#define RTC_CALR_CALW16_Msk           (0x1UL << RTC_CALR_CALW16_Pos)            /*!< 0x00002000 */
#define RTC_CALR_CALW16               RTC_CALR_CALW16_Msk                      
#define RTC_CALR_CALM_Pos             (0U)                                     
#define RTC_CALR_CALM_Msk             (0x1FFUL << RTC_CALR_CALM_Pos)            /*!< 0x000001FF */
#define RTC_CALR_CALM                 RTC_CALR_CALM_Msk                        
#define RTC_CALR_CALM_0               (0x001UL << RTC_CALR_CALM_Pos)            /*!< 0x00000001 */
#define RTC_CALR_CALM_1               (0x002UL << RTC_CALR_CALM_Pos)            /*!< 0x00000002 */
#define RTC_CALR_CALM_2               (0x004UL << RTC_CALR_CALM_Pos)            /*!< 0x00000004 */
#define RTC_CALR_CALM_3               (0x008UL << RTC_CALR_CALM_Pos)            /*!< 0x00000008 */
#define RTC_CALR_CALM_4               (0x010UL << RTC_CALR_CALM_Pos)            /*!< 0x00000010 */
#define RTC_CALR_CALM_5               (0x020UL << RTC_CALR_CALM_Pos)            /*!< 0x00000020 */
#define RTC_CALR_CALM_6               (0x040UL << RTC_CALR_CALM_Pos)            /*!< 0x00000040 */
#define RTC_CALR_CALM_7               (0x080UL << RTC_CALR_CALM_Pos)            /*!< 0x00000080 */
#define RTC_CALR_CALM_8               (0x100UL << RTC_CALR_CALM_Pos)            /*!< 0x00000100 */

/********************  Bits definition for RTC_TAFCR register  ****************/
#define RTC_TAFCR_ALARMOUTTYPE_Pos    (18U)                                    
#define RTC_TAFCR_ALARMOUTTYPE_Msk    (0x1UL << RTC_TAFCR_ALARMOUTTYPE_Pos)     /*!< 0x00040000 */
#define RTC_TAFCR_ALARMOUTTYPE        RTC_TAFCR_ALARMOUTTYPE_Msk               
#define RTC_TAFCR_TSINSEL_Pos         (17U)                                    
#define RTC_TAFCR_TSINSEL_Msk         (0x1UL << RTC_TAFCR_TSINSEL_Pos)          /*!< 0x00020000 */
#define RTC_TAFCR_TSINSEL             RTC_TAFCR_TSINSEL_Msk                    
#define RTC_TAFCR_TAMP1INSEL_Pos      (16U)                                    
#define RTC_TAFCR_TAMP1INSEL_Msk      (0x1UL << RTC_TAFCR_TAMP1INSEL_Pos)        /*!< 0x00010000 */
#define RTC_TAFCR_TAMP1INSEL          RTC_TAFCR_TAMP1INSEL_Msk                  
#define RTC_TAFCR_TAMPPUDIS_Pos       (15U)                                    
#define RTC_TAFCR_TAMPPUDIS_Msk       (0x1UL << RTC_TAFCR_TAMPPUDIS_Pos)        /*!< 0x00008000 */
#define RTC_TAFCR_TAMPPUDIS           RTC_TAFCR_TAMPPUDIS_Msk                  
#define RTC_TAFCR_TAMPPRCH_Pos        (13U)                                    
#define RTC_TAFCR_TAMPPRCH_Msk        (0x3UL << RTC_TAFCR_TAMPPRCH_Pos)         /*!< 0x00006000 */
#define RTC_TAFCR_TAMPPRCH            RTC_TAFCR_TAMPPRCH_Msk                   
#define RTC_TAFCR_TAMPPRCH_0          (0x1UL << RTC_TAFCR_TAMPPRCH_Pos)         /*!< 0x00002000 */
#define RTC_TAFCR_TAMPPRCH_1          (0x2UL << RTC_TAFCR_TAMPPRCH_Pos)         /*!< 0x00004000 */
#define RTC_TAFCR_TAMPFLT_Pos         (11U)                                    
#define RTC_TAFCR_TAMPFLT_Msk         (0x3UL << RTC_TAFCR_TAMPFLT_Pos)          /*!< 0x00001800 */
#define RTC_TAFCR_TAMPFLT             RTC_TAFCR_TAMPFLT_Msk                    
#define RTC_TAFCR_TAMPFLT_0           (0x1UL << RTC_TAFCR_TAMPFLT_Pos)          /*!< 0x00000800 */
#define RTC_TAFCR_TAMPFLT_1           (0x2UL << RTC_TAFCR_TAMPFLT_Pos)          /*!< 0x00001000 */
#define RTC_TAFCR_TAMPFREQ_Pos        (8U)                                     
#define RTC_TAFCR_TAMPFREQ_Msk        (0x7UL << RTC_TAFCR_TAMPFREQ_Pos)         /*!< 0x00000700 */
#define RTC_TAFCR_TAMPFREQ            RTC_TAFCR_TAMPFREQ_Msk                   
#define RTC_TAFCR_TAMPFREQ_0          (0x1UL << RTC_TAFCR_TAMPFREQ_Pos)         /*!< 0x00000100 */
#define RTC_TAFCR_TAMPFREQ_1          (0x2UL << RTC_TAFCR_TAMPFREQ_Pos)         /*!< 0x00000200 */
#define RTC_TAFCR_TAMPFREQ_2          (0x4UL << RTC_TAFCR_TAMPFREQ_Pos)         /*!< 0x00000400 */
#define RTC_TAFCR_TAMPTS_Pos          (7U)                                     
#define RTC_TAFCR_TAMPTS_Msk          (0x1UL << RTC_TAFCR_TAMPTS_Pos)           /*!< 0x00000080 */
#define RTC_TAFCR_TAMPTS              RTC_TAFCR_TAMPTS_Msk                     
#define RTC_TAFCR_TAMP2TRG_Pos        (4U)                                     
#define RTC_TAFCR_TAMP2TRG_Msk        (0x1UL << RTC_TAFCR_TAMP2TRG_Pos)         /*!< 0x00000010 */
#define RTC_TAFCR_TAMP2TRG            RTC_TAFCR_TAMP2TRG_Msk                   
#define RTC_TAFCR_TAMP2E_Pos          (3U)                                     
#define RTC_TAFCR_TAMP2E_Msk          (0x1UL << RTC_TAFCR_TAMP2E_Pos)           /*!< 0x00000008 */
#define RTC_TAFCR_TAMP2E              RTC_TAFCR_TAMP2E_Msk                     
#define RTC_TAFCR_TAMPIE_Pos          (2U)                                     
#define RTC_TAFCR_TAMPIE_Msk          (0x1UL << RTC_TAFCR_TAMPIE_Pos)           /*!< 0x00000004 */
#define RTC_TAFCR_TAMPIE              RTC_TAFCR_TAMPIE_Msk                     
#define RTC_TAFCR_TAMP1TRG_Pos        (1U)                                     
#define RTC_TAFCR_TAMP1TRG_Msk        (0x1UL << RTC_TAFCR_TAMP1TRG_Pos)         /*!< 0x00000002 */
#define RTC_TAFCR_TAMP1TRG            RTC_TAFCR_TAMP1TRG_Msk                   
#define RTC_TAFCR_TAMP1E_Pos          (0U)                                     
#define RTC_TAFCR_TAMP1E_Msk          (0x1UL << RTC_TAFCR_TAMP1E_Pos)           /*!< 0x00000001 */
#define RTC_TAFCR_TAMP1E              RTC_TAFCR_TAMP1E_Msk                     

/* Legacy defines */
#define RTC_TAFCR_TAMPINSEL           RTC_TAFCR_TAMP1INSEL

/********************  Bits definition for RTC_ALRMASSR register  *************/
#define RTC_ALRMASSR_MASKSS_Pos       (24U)                                    
#define RTC_ALRMASSR_MASKSS_Msk       (0xFUL << RTC_ALRMASSR_MASKSS_Pos)        /*!< 0x0F000000 */
#define RTC_ALRMASSR_MASKSS           RTC_ALRMASSR_MASKSS_Msk                  
#define RTC_ALRMASSR_MASKSS_0         (0x1UL << RTC_ALRMASSR_MASKSS_Pos)        /*!< 0x01000000 */
#define RTC_ALRMASSR_MASKSS_1         (0x2UL << RTC_ALRMASSR_MASKSS_Pos)        /*!< 0x02000000 */
#define RTC_ALRMASSR_MASKSS_2         (0x4UL << RTC_ALRMASSR_MASKSS_Pos)        /*!< 0x04000000 */
#define RTC_ALRMASSR_MASKSS_3         (0x8UL << RTC_ALRMASSR_MASKSS_Pos)        /*!< 0x08000000 */
#define RTC_ALRMASSR_SS_Pos           (0U)                                     
#define RTC_ALRMASSR_SS_Msk           (0x7FFFUL << RTC_ALRMASSR_SS_Pos)         /*!< 0x00007FFF */
#define RTC_ALRMASSR_SS               RTC_ALRMASSR_SS_Msk                      

/********************  Bits definition for RTC_ALRMBSSR register  *************/
#define RTC_ALRMBSSR_MASKSS_Pos       (24U)                                    
#define RTC_ALRMBSSR_MASKSS_Msk       (0xFUL << RTC_ALRMBSSR_MASKSS_Pos)        /*!< 0x0F000000 */
#define RTC_ALRMBSSR_MASKSS           RTC_ALRMBSSR_MASKSS_Msk                  
#define RTC_ALRMBSSR_MASKSS_0         (0x1UL << RTC_ALRMBSSR_MASKSS_Pos)        /*!< 0x01000000 */
#define RTC_ALRMBSSR_MASKSS_1         (0x2UL << RTC_ALRMBSSR_MASKSS_Pos)        /*!< 0x02000000 */
#define RTC_ALRMBSSR_MASKSS_2         (0x4UL << RTC_ALRMBSSR_MASKSS_Pos)        /*!< 0x04000000 */
#define RTC_ALRMBSSR_MASKSS_3         (0x8UL << RTC_ALRMBSSR_MASKSS_Pos)        /*!< 0x08000000 */
#define RTC_ALRMBSSR_SS_Pos           (0U)                                     
#define RTC_ALRMBSSR_SS_Msk           (0x7FFFUL << RTC_ALRMBSSR_SS_Pos)         /*!< 0x00007FFF */
#define RTC_ALRMBSSR_SS               RTC_ALRMBSSR_SS_Msk                      

/********************  Bits definition for RTC_BKP0R register  ****************/
#define RTC_BKP0R_Pos                 (0U)                                     
#define RTC_BKP0R_Msk                 (0xFFFFFFFFUL << RTC_BKP0R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP0R                     RTC_BKP0R_Msk                            

/********************  Bits definition for RTC_BKP1R register  ****************/
#define RTC_BKP1R_Pos                 (0U)                                     
#define RTC_BKP1R_Msk                 (0xFFFFFFFFUL << RTC_BKP1R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP1R                     RTC_BKP1R_Msk                            

/********************  Bits definition for RTC_BKP2R register  ****************/
#define RTC_BKP2R_Pos                 (0U)                                     
#define RTC_BKP2R_Msk                 (0xFFFFFFFFUL << RTC_BKP2R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP2R                     RTC_BKP2R_Msk                            

/********************  Bits definition for RTC_BKP3R register  ****************/
#define RTC_BKP3R_Pos                 (0U)                                     
#define RTC_BKP3R_Msk                 (0xFFFFFFFFUL << RTC_BKP3R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP3R                     RTC_BKP3R_Msk                            

/********************  Bits definition for RTC_BKP4R register  ****************/
#define RTC_BKP4R_Pos                 (0U)                                     
#define RTC_BKP4R_Msk                 (0xFFFFFFFFUL << RTC_BKP4R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP4R                     RTC_BKP4R_Msk                            

/********************  Bits definition for RTC_BKP5R register  ****************/
#define RTC_BKP5R_Pos                 (0U)                                     
#define RTC_BKP5R_Msk                 (0xFFFFFFFFUL << RTC_BKP5R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP5R                     RTC_BKP5R_Msk                            

/********************  Bits definition for RTC_BKP6R register  ****************/
#define RTC_BKP6R_Pos                 (0U)                                     
#define RTC_BKP6R_Msk                 (0xFFFFFFFFUL << RTC_BKP6R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP6R                     RTC_BKP6R_Msk                            

/********************  Bits definition for RTC_BKP7R register  ****************/
#define RTC_BKP7R_Pos                 (0U)                                     
#define RTC_BKP7R_Msk                 (0xFFFFFFFFUL << RTC_BKP7R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP7R                     RTC_BKP7R_Msk                            

/********************  Bits definition for RTC_BKP8R register  ****************/
#define RTC_BKP8R_Pos                 (0U)                                     
#define RTC_BKP8R_Msk                 (0xFFFFFFFFUL << RTC_BKP8R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP8R                     RTC_BKP8R_Msk                            

/********************  Bits definition for RTC_BKP9R register  ****************/
#define RTC_BKP9R_Pos                 (0U)                                     
#define RTC_BKP9R_Msk                 (0xFFFFFFFFUL << RTC_BKP9R_Pos)           /*!< 0xFFFFFFFF */
#define RTC_BKP9R                     RTC_BKP9R_Msk                            

/********************  Bits definition for RTC_BKP10R register  ***************/
#define RTC_BKP10R_Pos                (0U)                                     
#define RTC_BKP10R_Msk                (0xFFFFFFFFUL << RTC_BKP10R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP10R                    RTC_BKP10R_Msk                           

/********************  Bits definition for RTC_BKP11R register  ***************/
#define RTC_BKP11R_Pos                (0U)                                     
#define RTC_BKP11R_Msk                (0xFFFFFFFFUL << RTC_BKP11R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP11R                    RTC_BKP11R_Msk                           

/********************  Bits definition for RTC_BKP12R register  ***************/
#define RTC_BKP12R_Pos                (0U)                                     
#define RTC_BKP12R_Msk                (0xFFFFFFFFUL << RTC_BKP12R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP12R                    RTC_BKP12R_Msk                           

/********************  Bits definition for RTC_BKP13R register  ***************/
#define RTC_BKP13R_Pos                (0U)                                     
#define RTC_BKP13R_Msk                (0xFFFFFFFFUL << RTC_BKP13R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP13R                    RTC_BKP13R_Msk                           

/********************  Bits definition for RTC_BKP14R register  ***************/
#define RTC_BKP14R_Pos                (0U)                                     
#define RTC_BKP14R_Msk                (0xFFFFFFFFUL << RTC_BKP14R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP14R                    RTC_BKP14R_Msk                           

/********************  Bits definition for RTC_BKP15R register  ***************/
#define RTC_BKP15R_Pos                (0U)                                     
#define RTC_BKP15R_Msk                (0xFFFFFFFFUL << RTC_BKP15R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP15R                    RTC_BKP15R_Msk                           

/********************  Bits definition for RTC_BKP16R register  ***************/
#define RTC_BKP16R_Pos                (0U)                                     
#define RTC_BKP16R_Msk                (0xFFFFFFFFUL << RTC_BKP16R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP16R                    RTC_BKP16R_Msk                           

/********************  Bits definition for RTC_BKP17R register  ***************/
#define RTC_BKP17R_Pos                (0U)                                     
#define RTC_BKP17R_Msk                (0xFFFFFFFFUL << RTC_BKP17R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP17R                    RTC_BKP17R_Msk                           

/********************  Bits definition for RTC_BKP18R register  ***************/
#define RTC_BKP18R_Pos                (0U)                                     
#define RTC_BKP18R_Msk                (0xFFFFFFFFUL << RTC_BKP18R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP18R                    RTC_BKP18R_Msk                           

/********************  Bits definition for RTC_BKP19R register  ***************/
#define RTC_BKP19R_Pos                (0U)                                     
#define RTC_BKP19R_Msk                (0xFFFFFFFFUL << RTC_BKP19R_Pos)          /*!< 0xFFFFFFFF */
#define RTC_BKP19R                    RTC_BKP19R_Msk                           

/******************** Number of backup registers ******************************/
#define RTC_BKP_NUMBER                       0x000000014U
    
/******************************************************************************/
/*                                                                            */
/*                          Serial Audio Interface                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SAI_GCR register  *******************/
#define SAI_GCR_SYNCIN_Pos         (0U)                                        
#define SAI_GCR_SYNCIN_Msk         (0x3UL << SAI_GCR_SYNCIN_Pos)                /*!< 0x00000003 */
#define SAI_GCR_SYNCIN             SAI_GCR_SYNCIN_Msk                          /*!<SYNCIN[1:0] bits (Synchronization Inputs)   */
#define SAI_GCR_SYNCIN_0           (0x1UL << SAI_GCR_SYNCIN_Pos)                /*!< 0x00000001 */
#define SAI_GCR_SYNCIN_1           (0x2UL << SAI_GCR_SYNCIN_Pos)                /*!< 0x00000002 */

#define SAI_GCR_SYNCOUT_Pos        (4U)                                        
#define SAI_GCR_SYNCOUT_Msk        (0x3UL << SAI_GCR_SYNCOUT_Pos)               /*!< 0x00000030 */
#define SAI_GCR_SYNCOUT            SAI_GCR_SYNCOUT_Msk                         /*!<SYNCOUT[1:0] bits (Synchronization Outputs) */
#define SAI_GCR_SYNCOUT_0          (0x1UL << SAI_GCR_SYNCOUT_Pos)               /*!< 0x00000010 */
#define SAI_GCR_SYNCOUT_1          (0x2UL << SAI_GCR_SYNCOUT_Pos)               /*!< 0x00000020 */

/*******************  Bit definition for SAI_xCR1 register  *******************/
#define SAI_xCR1_MODE_Pos          (0U)                                        
#define SAI_xCR1_MODE_Msk          (0x3UL << SAI_xCR1_MODE_Pos)                 /*!< 0x00000003 */
#define SAI_xCR1_MODE              SAI_xCR1_MODE_Msk                           /*!<MODE[1:0] bits (Audio Block Mode)           */
#define SAI_xCR1_MODE_0            (0x1UL << SAI_xCR1_MODE_Pos)                 /*!< 0x00000001 */
#define SAI_xCR1_MODE_1            (0x2UL << SAI_xCR1_MODE_Pos)                 /*!< 0x00000002 */

#define SAI_xCR1_PRTCFG_Pos        (2U)                                        
#define SAI_xCR1_PRTCFG_Msk        (0x3UL << SAI_xCR1_PRTCFG_Pos)               /*!< 0x0000000C */
#define SAI_xCR1_PRTCFG            SAI_xCR1_PRTCFG_Msk                         /*!<PRTCFG[1:0] bits (Protocol Configuration)   */
#define SAI_xCR1_PRTCFG_0          (0x1UL << SAI_xCR1_PRTCFG_Pos)               /*!< 0x00000004 */
#define SAI_xCR1_PRTCFG_1          (0x2UL << SAI_xCR1_PRTCFG_Pos)               /*!< 0x00000008 */

#define SAI_xCR1_DS_Pos            (5U)                                        
#define SAI_xCR1_DS_Msk            (0x7UL << SAI_xCR1_DS_Pos)                   /*!< 0x000000E0 */
#define SAI_xCR1_DS                SAI_xCR1_DS_Msk                             /*!<DS[1:0] bits (Data Size) */
#define SAI_xCR1_DS_0              (0x1UL << SAI_xCR1_DS_Pos)                   /*!< 0x00000020 */
#define SAI_xCR1_DS_1              (0x2UL << SAI_xCR1_DS_Pos)                   /*!< 0x00000040 */
#define SAI_xCR1_DS_2              (0x4UL << SAI_xCR1_DS_Pos)                   /*!< 0x00000080 */

#define SAI_xCR1_LSBFIRST_Pos      (8U)                                        
#define SAI_xCR1_LSBFIRST_Msk      (0x1UL << SAI_xCR1_LSBFIRST_Pos)             /*!< 0x00000100 */
#define SAI_xCR1_LSBFIRST          SAI_xCR1_LSBFIRST_Msk                       /*!<LSB First Configuration  */
#define SAI_xCR1_CKSTR_Pos         (9U)                                        
#define SAI_xCR1_CKSTR_Msk         (0x1UL << SAI_xCR1_CKSTR_Pos)                /*!< 0x00000200 */
#define SAI_xCR1_CKSTR             SAI_xCR1_CKSTR_Msk                          /*!<ClocK STRobing edge      */

#define SAI_xCR1_SYNCEN_Pos        (10U)                                       
#define SAI_xCR1_SYNCEN_Msk        (0x3UL << SAI_xCR1_SYNCEN_Pos)               /*!< 0x00000C00 */
#define SAI_xCR1_SYNCEN            SAI_xCR1_SYNCEN_Msk                         /*!<SYNCEN[1:0](SYNChronization ENable) */
#define SAI_xCR1_SYNCEN_0          (0x1UL << SAI_xCR1_SYNCEN_Pos)               /*!< 0x00000400 */
#define SAI_xCR1_SYNCEN_1          (0x2UL << SAI_xCR1_SYNCEN_Pos)               /*!< 0x00000800 */

#define SAI_xCR1_MONO_Pos          (12U)                                       
#define SAI_xCR1_MONO_Msk          (0x1UL << SAI_xCR1_MONO_Pos)                 /*!< 0x00001000 */
#define SAI_xCR1_MONO              SAI_xCR1_MONO_Msk                           /*!<Mono mode                  */
#define SAI_xCR1_OUTDRIV_Pos       (13U)                                       
#define SAI_xCR1_OUTDRIV_Msk       (0x1UL << SAI_xCR1_OUTDRIV_Pos)              /*!< 0x00002000 */
#define SAI_xCR1_OUTDRIV           SAI_xCR1_OUTDRIV_Msk                        /*!<Output Drive               */
#define SAI_xCR1_SAIEN_Pos         (16U)                                       
#define SAI_xCR1_SAIEN_Msk         (0x1UL << SAI_xCR1_SAIEN_Pos)                /*!< 0x00010000 */
#define SAI_xCR1_SAIEN             SAI_xCR1_SAIEN_Msk                          /*!<Audio Block enable         */
#define SAI_xCR1_DMAEN_Pos         (17U)                                       
#define SAI_xCR1_DMAEN_Msk         (0x1UL << SAI_xCR1_DMAEN_Pos)                /*!< 0x00020000 */
#define SAI_xCR1_DMAEN             SAI_xCR1_DMAEN_Msk                          /*!<DMA enable                 */
#define SAI_xCR1_NODIV_Pos         (19U)                                       
#define SAI_xCR1_NODIV_Msk         (0x1UL << SAI_xCR1_NODIV_Pos)                /*!< 0x00080000 */
#define SAI_xCR1_NODIV             SAI_xCR1_NODIV_Msk                          /*!<No Divider Configuration   */

#define SAI_xCR1_MCKDIV_Pos        (20U)                                       
#define SAI_xCR1_MCKDIV_Msk        (0xFUL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00F00000 */
#define SAI_xCR1_MCKDIV            SAI_xCR1_MCKDIV_Msk                         /*!<MCKDIV[3:0] (Master ClocK Divider)  */
#define SAI_xCR1_MCKDIV_0          (0x1UL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00100000 */
#define SAI_xCR1_MCKDIV_1          (0x2UL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00200000 */
#define SAI_xCR1_MCKDIV_2          (0x4UL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00400000 */
#define SAI_xCR1_MCKDIV_3          (0x8UL << SAI_xCR1_MCKDIV_Pos)               /*!< 0x00800000 */

/*******************  Bit definition for SAI_xCR2 register  *******************/
#define SAI_xCR2_FTH_Pos           (0U)                                        
#define SAI_xCR2_FTH_Msk           (0x7UL << SAI_xCR2_FTH_Pos)                  /*!< 0x00000007 */
#define SAI_xCR2_FTH               SAI_xCR2_FTH_Msk                            /*!<FTH[2:0](Fifo THreshold)  */
#define SAI_xCR2_FTH_0             (0x1UL << SAI_xCR2_FTH_Pos)                  /*!< 0x00000001 */
#define SAI_xCR2_FTH_1             (0x2UL << SAI_xCR2_FTH_Pos)                  /*!< 0x00000002 */
#define SAI_xCR2_FTH_2             (0x4UL << SAI_xCR2_FTH_Pos)                  /*!< 0x00000004 */

#define SAI_xCR2_FFLUSH_Pos        (3U)                                        
#define SAI_xCR2_FFLUSH_Msk        (0x1UL << SAI_xCR2_FFLUSH_Pos)               /*!< 0x00000008 */
#define SAI_xCR2_FFLUSH            SAI_xCR2_FFLUSH_Msk                         /*!<Fifo FLUSH                       */
#define SAI_xCR2_TRIS_Pos          (4U)                                        
#define SAI_xCR2_TRIS_Msk          (0x1UL << SAI_xCR2_TRIS_Pos)                 /*!< 0x00000010 */
#define SAI_xCR2_TRIS              SAI_xCR2_TRIS_Msk                           /*!<TRIState Management on data line */
#define SAI_xCR2_MUTE_Pos          (5U)                                        
#define SAI_xCR2_MUTE_Msk          (0x1UL << SAI_xCR2_MUTE_Pos)                 /*!< 0x00000020 */
#define SAI_xCR2_MUTE              SAI_xCR2_MUTE_Msk                           /*!<Mute mode                        */
#define SAI_xCR2_MUTEVAL_Pos       (6U)                                        
#define SAI_xCR2_MUTEVAL_Msk       (0x1UL << SAI_xCR2_MUTEVAL_Pos)              /*!< 0x00000040 */
#define SAI_xCR2_MUTEVAL           SAI_xCR2_MUTEVAL_Msk                        /*!<Muate value                      */

#define SAI_xCR2_MUTECNT_Pos       (7U)                                        
#define SAI_xCR2_MUTECNT_Msk       (0x3FUL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00001F80 */
#define SAI_xCR2_MUTECNT           SAI_xCR2_MUTECNT_Msk                        /*!<MUTECNT[5:0] (MUTE counter) */
#define SAI_xCR2_MUTECNT_0         (0x01UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000080 */
#define SAI_xCR2_MUTECNT_1         (0x02UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000100 */
#define SAI_xCR2_MUTECNT_2         (0x04UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000200 */
#define SAI_xCR2_MUTECNT_3         (0x08UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000400 */
#define SAI_xCR2_MUTECNT_4         (0x10UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00000800 */
#define SAI_xCR2_MUTECNT_5         (0x20UL << SAI_xCR2_MUTECNT_Pos)             /*!< 0x00001000 */

#define SAI_xCR2_CPL_Pos           (13U)                                       
#define SAI_xCR2_CPL_Msk           (0x1UL << SAI_xCR2_CPL_Pos)                  /*!< 0x00002000 */
#define SAI_xCR2_CPL               SAI_xCR2_CPL_Msk                            /*!< Complement Bit             */

#define SAI_xCR2_COMP_Pos          (14U)                                       
#define SAI_xCR2_COMP_Msk          (0x3UL << SAI_xCR2_COMP_Pos)                 /*!< 0x0000C000 */
#define SAI_xCR2_COMP              SAI_xCR2_COMP_Msk                           /*!<COMP[1:0] (Companding mode) */
#define SAI_xCR2_COMP_0            (0x1UL << SAI_xCR2_COMP_Pos)                 /*!< 0x00004000 */
#define SAI_xCR2_COMP_1            (0x2UL << SAI_xCR2_COMP_Pos)                 /*!< 0x00008000 */

/******************  Bit definition for SAI_xFRCR register  *******************/
#define SAI_xFRCR_FRL_Pos          (0U)                                        
#define SAI_xFRCR_FRL_Msk          (0xFFUL << SAI_xFRCR_FRL_Pos)                /*!< 0x000000FF */
#define SAI_xFRCR_FRL              SAI_xFRCR_FRL_Msk                           /*!<FRL[7:0](Frame length)  */
#define SAI_xFRCR_FRL_0            (0x01UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000001 */
#define SAI_xFRCR_FRL_1            (0x02UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000002 */
#define SAI_xFRCR_FRL_2            (0x04UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000004 */
#define SAI_xFRCR_FRL_3            (0x08UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000008 */
#define SAI_xFRCR_FRL_4            (0x10UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000010 */
#define SAI_xFRCR_FRL_5            (0x20UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000020 */
#define SAI_xFRCR_FRL_6            (0x40UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000040 */
#define SAI_xFRCR_FRL_7            (0x80UL << SAI_xFRCR_FRL_Pos)                /*!< 0x00000080 */

#define SAI_xFRCR_FSALL_Pos        (8U)                                        
#define SAI_xFRCR_FSALL_Msk        (0x7FUL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00007F00 */
#define SAI_xFRCR_FSALL            SAI_xFRCR_FSALL_Msk                         /*!<FRL[6:0] (Frame synchronization active level length)  */
#define SAI_xFRCR_FSALL_0          (0x01UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00000100 */
#define SAI_xFRCR_FSALL_1          (0x02UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00000200 */
#define SAI_xFRCR_FSALL_2          (0x04UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00000400 */
#define SAI_xFRCR_FSALL_3          (0x08UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00000800 */
#define SAI_xFRCR_FSALL_4          (0x10UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00001000 */
#define SAI_xFRCR_FSALL_5          (0x20UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00002000 */
#define SAI_xFRCR_FSALL_6          (0x40UL << SAI_xFRCR_FSALL_Pos)              /*!< 0x00004000 */

#define SAI_xFRCR_FSDEF_Pos        (16U)                                       
#define SAI_xFRCR_FSDEF_Msk        (0x1UL << SAI_xFRCR_FSDEF_Pos)               /*!< 0x00010000 */
#define SAI_xFRCR_FSDEF            SAI_xFRCR_FSDEF_Msk                         /*!< Frame Synchronization Definition */
#define SAI_xFRCR_FSPOL_Pos        (17U)                                       
#define SAI_xFRCR_FSPOL_Msk        (0x1UL << SAI_xFRCR_FSPOL_Pos)               /*!< 0x00020000 */
#define SAI_xFRCR_FSPOL            SAI_xFRCR_FSPOL_Msk                         /*!<Frame Synchronization POLarity    */
#define SAI_xFRCR_FSOFF_Pos        (18U)                                       
#define SAI_xFRCR_FSOFF_Msk        (0x1UL << SAI_xFRCR_FSOFF_Pos)               /*!< 0x00040000 */
#define SAI_xFRCR_FSOFF            SAI_xFRCR_FSOFF_Msk                         /*!<Frame Synchronization OFFset      */
/* Legacy defines */
#define  SAI_xFRCR_FSPO                   SAI_xFRCR_FSPOL

/******************  Bit definition for SAI_xSLOTR register  *******************/
#define SAI_xSLOTR_FBOFF_Pos       (0U)                                        
#define SAI_xSLOTR_FBOFF_Msk       (0x1FUL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x0000001F */
#define SAI_xSLOTR_FBOFF           SAI_xSLOTR_FBOFF_Msk                        /*!<FRL[4:0](First Bit Offset)  */
#define SAI_xSLOTR_FBOFF_0         (0x01UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000001 */
#define SAI_xSLOTR_FBOFF_1         (0x02UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000002 */
#define SAI_xSLOTR_FBOFF_2         (0x04UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000004 */
#define SAI_xSLOTR_FBOFF_3         (0x08UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000008 */
#define SAI_xSLOTR_FBOFF_4         (0x10UL << SAI_xSLOTR_FBOFF_Pos)             /*!< 0x00000010 */

#define SAI_xSLOTR_SLOTSZ_Pos      (6U)                                        
#define SAI_xSLOTR_SLOTSZ_Msk      (0x3UL << SAI_xSLOTR_SLOTSZ_Pos)             /*!< 0x000000C0 */
#define SAI_xSLOTR_SLOTSZ          SAI_xSLOTR_SLOTSZ_Msk                       /*!<SLOTSZ[1:0] (Slot size)  */
#define SAI_xSLOTR_SLOTSZ_0        (0x1UL << SAI_xSLOTR_SLOTSZ_Pos)             /*!< 0x00000040 */
#define SAI_xSLOTR_SLOTSZ_1        (0x2UL << SAI_xSLOTR_SLOTSZ_Pos)             /*!< 0x00000080 */

#define SAI_xSLOTR_NBSLOT_Pos      (8U)                                        
#define SAI_xSLOTR_NBSLOT_Msk      (0xFUL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000F00 */
#define SAI_xSLOTR_NBSLOT          SAI_xSLOTR_NBSLOT_Msk                       /*!<NBSLOT[3:0] (Number of Slot in audio Frame)  */
#define SAI_xSLOTR_NBSLOT_0        (0x1UL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000100 */
#define SAI_xSLOTR_NBSLOT_1        (0x2UL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000200 */
#define SAI_xSLOTR_NBSLOT_2        (0x4UL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000400 */
#define SAI_xSLOTR_NBSLOT_3        (0x8UL << SAI_xSLOTR_NBSLOT_Pos)             /*!< 0x00000800 */

#define SAI_xSLOTR_SLOTEN_Pos      (16U)                                       
#define SAI_xSLOTR_SLOTEN_Msk      (0xFFFFUL << SAI_xSLOTR_SLOTEN_Pos)          /*!< 0xFFFF0000 */
#define SAI_xSLOTR_SLOTEN          SAI_xSLOTR_SLOTEN_Msk                       /*!<SLOTEN[15:0] (Slot Enable)  */

/*******************  Bit definition for SAI_xIMR register  *******************/
#define SAI_xIMR_OVRUDRIE_Pos      (0U)                                        
#define SAI_xIMR_OVRUDRIE_Msk      (0x1UL << SAI_xIMR_OVRUDRIE_Pos)             /*!< 0x00000001 */
#define SAI_xIMR_OVRUDRIE          SAI_xIMR_OVRUDRIE_Msk                       /*!<Overrun underrun interrupt enable                              */
#define SAI_xIMR_MUTEDETIE_Pos     (1U)                                        
#define SAI_xIMR_MUTEDETIE_Msk     (0x1UL << SAI_xIMR_MUTEDETIE_Pos)            /*!< 0x00000002 */
#define SAI_xIMR_MUTEDETIE         SAI_xIMR_MUTEDETIE_Msk                      /*!<Mute detection interrupt enable                                */
#define SAI_xIMR_WCKCFGIE_Pos      (2U)                                        
#define SAI_xIMR_WCKCFGIE_Msk      (0x1UL << SAI_xIMR_WCKCFGIE_Pos)             /*!< 0x00000004 */
#define SAI_xIMR_WCKCFGIE          SAI_xIMR_WCKCFGIE_Msk                       /*!<Wrong Clock Configuration interrupt enable                     */
#define SAI_xIMR_FREQIE_Pos        (3U)                                        
#define SAI_xIMR_FREQIE_Msk        (0x1UL << SAI_xIMR_FREQIE_Pos)               /*!< 0x00000008 */
#define SAI_xIMR_FREQIE            SAI_xIMR_FREQIE_Msk                         /*!<FIFO request interrupt enable                                  */
#define SAI_xIMR_CNRDYIE_Pos       (4U)                                        
#define SAI_xIMR_CNRDYIE_Msk       (0x1UL << SAI_xIMR_CNRDYIE_Pos)              /*!< 0x00000010 */
#define SAI_xIMR_CNRDYIE           SAI_xIMR_CNRDYIE_Msk                        /*!<Codec not ready interrupt enable                               */
#define SAI_xIMR_AFSDETIE_Pos      (5U)                                        
#define SAI_xIMR_AFSDETIE_Msk      (0x1UL << SAI_xIMR_AFSDETIE_Pos)             /*!< 0x00000020 */
#define SAI_xIMR_AFSDETIE          SAI_xIMR_AFSDETIE_Msk                       /*!<Anticipated frame synchronization detection interrupt enable   */
#define SAI_xIMR_LFSDETIE_Pos      (6U)                                        
#define SAI_xIMR_LFSDETIE_Msk      (0x1UL << SAI_xIMR_LFSDETIE_Pos)             /*!< 0x00000040 */
#define SAI_xIMR_LFSDETIE          SAI_xIMR_LFSDETIE_Msk                       /*!<Late frame synchronization detection interrupt enable          */

/********************  Bit definition for SAI_xSR register  *******************/
#define SAI_xSR_OVRUDR_Pos         (0U)                                        
#define SAI_xSR_OVRUDR_Msk         (0x1UL << SAI_xSR_OVRUDR_Pos)                /*!< 0x00000001 */
#define SAI_xSR_OVRUDR             SAI_xSR_OVRUDR_Msk                          /*!<Overrun underrun                               */
#define SAI_xSR_MUTEDET_Pos        (1U)                                        
#define SAI_xSR_MUTEDET_Msk        (0x1UL << SAI_xSR_MUTEDET_Pos)               /*!< 0x00000002 */
#define SAI_xSR_MUTEDET            SAI_xSR_MUTEDET_Msk                         /*!<Mute detection                                 */
#define SAI_xSR_WCKCFG_Pos         (2U)                                        
#define SAI_xSR_WCKCFG_Msk         (0x1UL << SAI_xSR_WCKCFG_Pos)                /*!< 0x00000004 */
#define SAI_xSR_WCKCFG             SAI_xSR_WCKCFG_Msk                          /*!<Wrong Clock Configuration                      */
#define SAI_xSR_FREQ_Pos           (3U)                                        
#define SAI_xSR_FREQ_Msk           (0x1UL << SAI_xSR_FREQ_Pos)                  /*!< 0x00000008 */
#define SAI_xSR_FREQ               SAI_xSR_FREQ_Msk                            /*!<FIFO request                                   */
#define SAI_xSR_CNRDY_Pos          (4U)                                        
#define SAI_xSR_CNRDY_Msk          (0x1UL << SAI_xSR_CNRDY_Pos)                 /*!< 0x00000010 */
#define SAI_xSR_CNRDY              SAI_xSR_CNRDY_Msk                           /*!<Codec not ready                                */
#define SAI_xSR_AFSDET_Pos         (5U)                                        
#define SAI_xSR_AFSDET_Msk         (0x1UL << SAI_xSR_AFSDET_Pos)                /*!< 0x00000020 */
#define SAI_xSR_AFSDET             SAI_xSR_AFSDET_Msk                          /*!<Anticipated frame synchronization detection    */
#define SAI_xSR_LFSDET_Pos         (6U)                                        
#define SAI_xSR_LFSDET_Msk         (0x1UL << SAI_xSR_LFSDET_Pos)                /*!< 0x00000040 */
#define SAI_xSR_LFSDET             SAI_xSR_LFSDET_Msk                          /*!<Late frame synchronization detection           */

#define SAI_xSR_FLVL_Pos           (16U)                                       
#define SAI_xSR_FLVL_Msk           (0x7UL << SAI_xSR_FLVL_Pos)                  /*!< 0x00070000 */
#define SAI_xSR_FLVL               SAI_xSR_FLVL_Msk                            /*!<FLVL[2:0] (FIFO Level Threshold)               */
#define SAI_xSR_FLVL_0             (0x1UL << SAI_xSR_FLVL_Pos)                  /*!< 0x00010000 */
#define SAI_xSR_FLVL_1             (0x2UL << SAI_xSR_FLVL_Pos)                  /*!< 0x00020000 */
#define SAI_xSR_FLVL_2             (0x4UL << SAI_xSR_FLVL_Pos)                  /*!< 0x00040000 */

/******************  Bit definition for SAI_xCLRFR register  ******************/
#define SAI_xCLRFR_COVRUDR_Pos     (0U)                                        
#define SAI_xCLRFR_COVRUDR_Msk     (0x1UL << SAI_xCLRFR_COVRUDR_Pos)            /*!< 0x00000001 */
#define SAI_xCLRFR_COVRUDR         SAI_xCLRFR_COVRUDR_Msk                      /*!<Clear Overrun underrun                               */
#define SAI_xCLRFR_CMUTEDET_Pos    (1U)                                        
#define SAI_xCLRFR_CMUTEDET_Msk    (0x1UL << SAI_xCLRFR_CMUTEDET_Pos)           /*!< 0x00000002 */
#define SAI_xCLRFR_CMUTEDET        SAI_xCLRFR_CMUTEDET_Msk                     /*!<Clear Mute detection                                 */
#define SAI_xCLRFR_CWCKCFG_Pos     (2U)                                        
#define SAI_xCLRFR_CWCKCFG_Msk     (0x1UL << SAI_xCLRFR_CWCKCFG_Pos)            /*!< 0x00000004 */
#define SAI_xCLRFR_CWCKCFG         SAI_xCLRFR_CWCKCFG_Msk                      /*!<Clear Wrong Clock Configuration                      */
#define SAI_xCLRFR_CFREQ_Pos       (3U)                                        
#define SAI_xCLRFR_CFREQ_Msk       (0x1UL << SAI_xCLRFR_CFREQ_Pos)              /*!< 0x00000008 */
#define SAI_xCLRFR_CFREQ           SAI_xCLRFR_CFREQ_Msk                        /*!<Clear FIFO request                                   */
#define SAI_xCLRFR_CCNRDY_Pos      (4U)                                        
#define SAI_xCLRFR_CCNRDY_Msk      (0x1UL << SAI_xCLRFR_CCNRDY_Pos)             /*!< 0x00000010 */
#define SAI_xCLRFR_CCNRDY          SAI_xCLRFR_CCNRDY_Msk                       /*!<Clear Codec not ready                                */
#define SAI_xCLRFR_CAFSDET_Pos     (5U)                                        
#define SAI_xCLRFR_CAFSDET_Msk     (0x1UL << SAI_xCLRFR_CAFSDET_Pos)            /*!< 0x00000020 */
#define SAI_xCLRFR_CAFSDET         SAI_xCLRFR_CAFSDET_Msk                      /*!<Clear Anticipated frame synchronization detection    */
#define SAI_xCLRFR_CLFSDET_Pos     (6U)                                        
#define SAI_xCLRFR_CLFSDET_Msk     (0x1UL << SAI_xCLRFR_CLFSDET_Pos)            /*!< 0x00000040 */
#define SAI_xCLRFR_CLFSDET         SAI_xCLRFR_CLFSDET_Msk                      /*!<Clear Late frame synchronization detection           */

/******************  Bit definition for SAI_xDR register  ******************/
#define SAI_xDR_DATA_Pos           (0U)                                        
#define SAI_xDR_DATA_Msk           (0xFFFFFFFFUL << SAI_xDR_DATA_Pos)           /*!< 0xFFFFFFFF */
#define SAI_xDR_DATA               SAI_xDR_DATA_Msk                            


/******************************************************************************/
/*                                                                            */
/*                          SD host Interface                                 */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SDIO_POWER register  ******************/
#define SDIO_POWER_PWRCTRL_Pos         (0U)                                    
#define SDIO_POWER_PWRCTRL_Msk         (0x3UL << SDIO_POWER_PWRCTRL_Pos)        /*!< 0x00000003 */
#define SDIO_POWER_PWRCTRL             SDIO_POWER_PWRCTRL_Msk                  /*!<PWRCTRL[1:0] bits (Power supply control bits) */
#define SDIO_POWER_PWRCTRL_0           (0x1UL << SDIO_POWER_PWRCTRL_Pos)        /*!< 0x01 */
#define SDIO_POWER_PWRCTRL_1           (0x2UL << SDIO_POWER_PWRCTRL_Pos)        /*!< 0x02 */

/******************  Bit definition for SDIO_CLKCR register  ******************/
#define SDIO_CLKCR_CLKDIV_Pos          (0U)                                    
#define SDIO_CLKCR_CLKDIV_Msk          (0xFFUL << SDIO_CLKCR_CLKDIV_Pos)        /*!< 0x000000FF */
#define SDIO_CLKCR_CLKDIV              SDIO_CLKCR_CLKDIV_Msk                   /*!<Clock divide factor             */
#define SDIO_CLKCR_CLKEN_Pos           (8U)                                    
#define SDIO_CLKCR_CLKEN_Msk           (0x1UL << SDIO_CLKCR_CLKEN_Pos)          /*!< 0x00000100 */
#define SDIO_CLKCR_CLKEN               SDIO_CLKCR_CLKEN_Msk                    /*!<Clock enable bit                */
#define SDIO_CLKCR_PWRSAV_Pos          (9U)                                    
#define SDIO_CLKCR_PWRSAV_Msk          (0x1UL << SDIO_CLKCR_PWRSAV_Pos)         /*!< 0x00000200 */
#define SDIO_CLKCR_PWRSAV              SDIO_CLKCR_PWRSAV_Msk                   /*!<Power saving configuration bit  */
#define SDIO_CLKCR_BYPASS_Pos          (10U)                                   
#define SDIO_CLKCR_BYPASS_Msk          (0x1UL << SDIO_CLKCR_BYPASS_Pos)         /*!< 0x00000400 */
#define SDIO_CLKCR_BYPASS              SDIO_CLKCR_BYPASS_Msk                   /*!<Clock divider bypass enable bit */

#define SDIO_CLKCR_WIDBUS_Pos          (11U)                                   
#define SDIO_CLKCR_WIDBUS_Msk          (0x3UL << SDIO_CLKCR_WIDBUS_Pos)         /*!< 0x00001800 */
#define SDIO_CLKCR_WIDBUS              SDIO_CLKCR_WIDBUS_Msk                   /*!<WIDBUS[1:0] bits (Wide bus mode enable bit) */
#define SDIO_CLKCR_WIDBUS_0            (0x1UL << SDIO_CLKCR_WIDBUS_Pos)         /*!< 0x0800 */
#define SDIO_CLKCR_WIDBUS_1            (0x2UL << SDIO_CLKCR_WIDBUS_Pos)         /*!< 0x1000 */

#define SDIO_CLKCR_NEGEDGE_Pos         (13U)                                   
#define SDIO_CLKCR_NEGEDGE_Msk         (0x1UL << SDIO_CLKCR_NEGEDGE_Pos)        /*!< 0x00002000 */
#define SDIO_CLKCR_NEGEDGE             SDIO_CLKCR_NEGEDGE_Msk                  /*!<SDIO_CK dephasing selection bit */
#define SDIO_CLKCR_HWFC_EN_Pos         (14U)                                   
#define SDIO_CLKCR_HWFC_EN_Msk         (0x1UL << SDIO_CLKCR_HWFC_EN_Pos)        /*!< 0x00004000 */
#define SDIO_CLKCR_HWFC_EN             SDIO_CLKCR_HWFC_EN_Msk                  /*!<HW Flow Control enable          */

/*******************  Bit definition for SDIO_ARG register  *******************/
#define SDIO_ARG_CMDARG_Pos            (0U)                                    
#define SDIO_ARG_CMDARG_Msk            (0xFFFFFFFFUL << SDIO_ARG_CMDARG_Pos)    /*!< 0xFFFFFFFF */
#define SDIO_ARG_CMDARG                SDIO_ARG_CMDARG_Msk                     /*!<Command argument */

/*******************  Bit definition for SDIO_CMD register  *******************/
#define SDIO_CMD_CMDINDEX_Pos          (0U)                                    
#define SDIO_CMD_CMDINDEX_Msk          (0x3FUL << SDIO_CMD_CMDINDEX_Pos)        /*!< 0x0000003F */
#define SDIO_CMD_CMDINDEX              SDIO_CMD_CMDINDEX_Msk                   /*!<Command Index                               */

#define SDIO_CMD_WAITRESP_Pos          (6U)                                    
#define SDIO_CMD_WAITRESP_Msk          (0x3UL << SDIO_CMD_WAITRESP_Pos)         /*!< 0x000000C0 */
#define SDIO_CMD_WAITRESP              SDIO_CMD_WAITRESP_Msk                   /*!<WAITRESP[1:0] bits (Wait for response bits) */
#define SDIO_CMD_WAITRESP_0            (0x1UL << SDIO_CMD_WAITRESP_Pos)         /*!< 0x0040 */
#define SDIO_CMD_WAITRESP_1            (0x2UL << SDIO_CMD_WAITRESP_Pos)         /*!< 0x0080 */

#define SDIO_CMD_WAITINT_Pos           (8U)                                    
#define SDIO_CMD_WAITINT_Msk           (0x1UL << SDIO_CMD_WAITINT_Pos)          /*!< 0x00000100 */
#define SDIO_CMD_WAITINT               SDIO_CMD_WAITINT_Msk                    /*!<CPSM Waits for Interrupt Request                               */
#define SDIO_CMD_WAITPEND_Pos          (9U)                                    
#define SDIO_CMD_WAITPEND_Msk          (0x1UL << SDIO_CMD_WAITPEND_Pos)         /*!< 0x00000200 */
#define SDIO_CMD_WAITPEND              SDIO_CMD_WAITPEND_Msk                   /*!<CPSM Waits for ends of data transfer (CmdPend internal signal) */
#define SDIO_CMD_CPSMEN_Pos            (10U)                                   
#define SDIO_CMD_CPSMEN_Msk            (0x1UL << SDIO_CMD_CPSMEN_Pos)           /*!< 0x00000400 */
#define SDIO_CMD_CPSMEN                SDIO_CMD_CPSMEN_Msk                     /*!<Command path state machine (CPSM) Enable bit                   */
#define SDIO_CMD_SDIOSUSPEND_Pos       (11U)                                   
#define SDIO_CMD_SDIOSUSPEND_Msk       (0x1UL << SDIO_CMD_SDIOSUSPEND_Pos)      /*!< 0x00000800 */
#define SDIO_CMD_SDIOSUSPEND           SDIO_CMD_SDIOSUSPEND_Msk                /*!<SD I/O suspend command                                         */
#define SDIO_CMD_ENCMDCOMPL_Pos        (12U)                                   
#define SDIO_CMD_ENCMDCOMPL_Msk        (0x1UL << SDIO_CMD_ENCMDCOMPL_Pos)       /*!< 0x00001000 */
#define SDIO_CMD_ENCMDCOMPL            SDIO_CMD_ENCMDCOMPL_Msk                 /*!<Enable CMD completion                                          */
#define SDIO_CMD_NIEN_Pos              (13U)                                   
#define SDIO_CMD_NIEN_Msk              (0x1UL << SDIO_CMD_NIEN_Pos)             /*!< 0x00002000 */
#define SDIO_CMD_NIEN                  SDIO_CMD_NIEN_Msk                       /*!<Not Interrupt Enable                                           */
#define SDIO_CMD_CEATACMD_Pos          (14U)                                   
#define SDIO_CMD_CEATACMD_Msk          (0x1UL << SDIO_CMD_CEATACMD_Pos)         /*!< 0x00004000 */
#define SDIO_CMD_CEATACMD              SDIO_CMD_CEATACMD_Msk                   /*!<CE-ATA command                                                 */

/*****************  Bit definition for SDIO_RESPCMD register  *****************/
#define SDIO_RESPCMD_RESPCMD_Pos       (0U)                                    
#define SDIO_RESPCMD_RESPCMD_Msk       (0x3FUL << SDIO_RESPCMD_RESPCMD_Pos)     /*!< 0x0000003F */
#define SDIO_RESPCMD_RESPCMD           SDIO_RESPCMD_RESPCMD_Msk                /*!<Response command index */

/******************  Bit definition for SDIO_RESP0 register  ******************/
#define SDIO_RESP0_CARDSTATUS0_Pos     (0U)                                    
#define SDIO_RESP0_CARDSTATUS0_Msk     (0xFFFFFFFFUL << SDIO_RESP0_CARDSTATUS0_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP0_CARDSTATUS0         SDIO_RESP0_CARDSTATUS0_Msk              /*!<Card Status */

/******************  Bit definition for SDIO_RESP1 register  ******************/
#define SDIO_RESP1_CARDSTATUS1_Pos     (0U)                                    
#define SDIO_RESP1_CARDSTATUS1_Msk     (0xFFFFFFFFUL << SDIO_RESP1_CARDSTATUS1_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP1_CARDSTATUS1         SDIO_RESP1_CARDSTATUS1_Msk              /*!<Card Status */

/******************  Bit definition for SDIO_RESP2 register  ******************/
#define SDIO_RESP2_CARDSTATUS2_Pos     (0U)                                    
#define SDIO_RESP2_CARDSTATUS2_Msk     (0xFFFFFFFFUL << SDIO_RESP2_CARDSTATUS2_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP2_CARDSTATUS2         SDIO_RESP2_CARDSTATUS2_Msk              /*!<Card Status */

/******************  Bit definition for SDIO_RESP3 register  ******************/
#define SDIO_RESP3_CARDSTATUS3_Pos     (0U)                                    
#define SDIO_RESP3_CARDSTATUS3_Msk     (0xFFFFFFFFUL << SDIO_RESP3_CARDSTATUS3_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP3_CARDSTATUS3         SDIO_RESP3_CARDSTATUS3_Msk              /*!<Card Status */

/******************  Bit definition for SDIO_RESP4 register  ******************/
#define SDIO_RESP4_CARDSTATUS4_Pos     (0U)                                    
#define SDIO_RESP4_CARDSTATUS4_Msk     (0xFFFFFFFFUL << SDIO_RESP4_CARDSTATUS4_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RESP4_CARDSTATUS4         SDIO_RESP4_CARDSTATUS4_Msk              /*!<Card Status */

/******************  Bit definition for SDIO_DTIMER register  *****************/
#define SDIO_DTIMER_DATATIME_Pos       (0U)                                    
#define SDIO_DTIMER_DATATIME_Msk       (0xFFFFFFFFUL << SDIO_DTIMER_DATATIME_Pos) /*!< 0xFFFFFFFF */
#define SDIO_DTIMER_DATATIME           SDIO_DTIMER_DATATIME_Msk                /*!<Data timeout period. */

/******************  Bit definition for SDIO_DLEN register  *******************/
#define SDIO_DLEN_DATALENGTH_Pos       (0U)                                    
#define SDIO_DLEN_DATALENGTH_Msk       (0x1FFFFFFUL << SDIO_DLEN_DATALENGTH_Pos) /*!< 0x01FFFFFF */
#define SDIO_DLEN_DATALENGTH           SDIO_DLEN_DATALENGTH_Msk                /*!<Data length value    */

/******************  Bit definition for SDIO_DCTRL register  ******************/
#define SDIO_DCTRL_DTEN_Pos            (0U)                                    
#define SDIO_DCTRL_DTEN_Msk            (0x1UL << SDIO_DCTRL_DTEN_Pos)           /*!< 0x00000001 */
#define SDIO_DCTRL_DTEN                SDIO_DCTRL_DTEN_Msk                     /*!<Data transfer enabled bit         */
#define SDIO_DCTRL_DTDIR_Pos           (1U)                                    
#define SDIO_DCTRL_DTDIR_Msk           (0x1UL << SDIO_DCTRL_DTDIR_Pos)          /*!< 0x00000002 */
#define SDIO_DCTRL_DTDIR               SDIO_DCTRL_DTDIR_Msk                    /*!<Data transfer direction selection */
#define SDIO_DCTRL_DTMODE_Pos          (2U)                                    
#define SDIO_DCTRL_DTMODE_Msk          (0x1UL << SDIO_DCTRL_DTMODE_Pos)         /*!< 0x00000004 */
#define SDIO_DCTRL_DTMODE              SDIO_DCTRL_DTMODE_Msk                   /*!<Data transfer mode selection      */
#define SDIO_DCTRL_DMAEN_Pos           (3U)                                    
#define SDIO_DCTRL_DMAEN_Msk           (0x1UL << SDIO_DCTRL_DMAEN_Pos)          /*!< 0x00000008 */
#define SDIO_DCTRL_DMAEN               SDIO_DCTRL_DMAEN_Msk                    /*!<DMA enabled bit                   */

#define SDIO_DCTRL_DBLOCKSIZE_Pos      (4U)                                    
#define SDIO_DCTRL_DBLOCKSIZE_Msk      (0xFUL << SDIO_DCTRL_DBLOCKSIZE_Pos)     /*!< 0x000000F0 */
#define SDIO_DCTRL_DBLOCKSIZE          SDIO_DCTRL_DBLOCKSIZE_Msk               /*!<DBLOCKSIZE[3:0] bits (Data block size) */
#define SDIO_DCTRL_DBLOCKSIZE_0        (0x1UL << SDIO_DCTRL_DBLOCKSIZE_Pos)     /*!< 0x0010 */
#define SDIO_DCTRL_DBLOCKSIZE_1        (0x2UL << SDIO_DCTRL_DBLOCKSIZE_Pos)     /*!< 0x0020 */
#define SDIO_DCTRL_DBLOCKSIZE_2        (0x4UL << SDIO_DCTRL_DBLOCKSIZE_Pos)     /*!< 0x0040 */
#define SDIO_DCTRL_DBLOCKSIZE_3        (0x8UL << SDIO_DCTRL_DBLOCKSIZE_Pos)     /*!< 0x0080 */

#define SDIO_DCTRL_RWSTART_Pos         (8U)                                    
#define SDIO_DCTRL_RWSTART_Msk         (0x1UL << SDIO_DCTRL_RWSTART_Pos)        /*!< 0x00000100 */
#define SDIO_DCTRL_RWSTART             SDIO_DCTRL_RWSTART_Msk                  /*!<Read wait start         */
#define SDIO_DCTRL_RWSTOP_Pos          (9U)                                    
#define SDIO_DCTRL_RWSTOP_Msk          (0x1UL << SDIO_DCTRL_RWSTOP_Pos)         /*!< 0x00000200 */
#define SDIO_DCTRL_RWSTOP              SDIO_DCTRL_RWSTOP_Msk                   /*!<Read wait stop          */
#define SDIO_DCTRL_RWMOD_Pos           (10U)                                   
#define SDIO_DCTRL_RWMOD_Msk           (0x1UL << SDIO_DCTRL_RWMOD_Pos)          /*!< 0x00000400 */
#define SDIO_DCTRL_RWMOD               SDIO_DCTRL_RWMOD_Msk                    /*!<Read wait mode          */
#define SDIO_DCTRL_SDIOEN_Pos          (11U)                                   
#define SDIO_DCTRL_SDIOEN_Msk          (0x1UL << SDIO_DCTRL_SDIOEN_Pos)         /*!< 0x00000800 */
#define SDIO_DCTRL_SDIOEN              SDIO_DCTRL_SDIOEN_Msk                   /*!<SD I/O enable functions */

/******************  Bit definition for SDIO_DCOUNT register  *****************/
#define SDIO_DCOUNT_DATACOUNT_Pos      (0U)                                    
#define SDIO_DCOUNT_DATACOUNT_Msk      (0x1FFFFFFUL << SDIO_DCOUNT_DATACOUNT_Pos) /*!< 0x01FFFFFF */
#define SDIO_DCOUNT_DATACOUNT          SDIO_DCOUNT_DATACOUNT_Msk               /*!<Data count value */

/******************  Bit definition for SDIO_STA register  ********************/
#define SDIO_STA_CCRCFAIL_Pos          (0U)                                    
#define SDIO_STA_CCRCFAIL_Msk          (0x1UL << SDIO_STA_CCRCFAIL_Pos)         /*!< 0x00000001 */
#define SDIO_STA_CCRCFAIL              SDIO_STA_CCRCFAIL_Msk                   /*!<Command response received (CRC check failed)  */
#define SDIO_STA_DCRCFAIL_Pos          (1U)                                    
#define SDIO_STA_DCRCFAIL_Msk          (0x1UL << SDIO_STA_DCRCFAIL_Pos)         /*!< 0x00000002 */
#define SDIO_STA_DCRCFAIL              SDIO_STA_DCRCFAIL_Msk                   /*!<Data block sent/received (CRC check failed)   */
#define SDIO_STA_CTIMEOUT_Pos          (2U)                                    
#define SDIO_STA_CTIMEOUT_Msk          (0x1UL << SDIO_STA_CTIMEOUT_Pos)         /*!< 0x00000004 */
#define SDIO_STA_CTIMEOUT              SDIO_STA_CTIMEOUT_Msk                   /*!<Command response timeout                      */
#define SDIO_STA_DTIMEOUT_Pos          (3U)                                    
#define SDIO_STA_DTIMEOUT_Msk          (0x1UL << SDIO_STA_DTIMEOUT_Pos)         /*!< 0x00000008 */
#define SDIO_STA_DTIMEOUT              SDIO_STA_DTIMEOUT_Msk                   /*!<Data timeout                                  */
#define SDIO_STA_TXUNDERR_Pos          (4U)                                    
#define SDIO_STA_TXUNDERR_Msk          (0x1UL << SDIO_STA_TXUNDERR_Pos)         /*!< 0x00000010 */
#define SDIO_STA_TXUNDERR              SDIO_STA_TXUNDERR_Msk                   /*!<Transmit FIFO underrun error                  */
#define SDIO_STA_RXOVERR_Pos           (5U)                                    
#define SDIO_STA_RXOVERR_Msk           (0x1UL << SDIO_STA_RXOVERR_Pos)          /*!< 0x00000020 */
#define SDIO_STA_RXOVERR               SDIO_STA_RXOVERR_Msk                    /*!<Received FIFO overrun error                   */
#define SDIO_STA_CMDREND_Pos           (6U)                                    
#define SDIO_STA_CMDREND_Msk           (0x1UL << SDIO_STA_CMDREND_Pos)          /*!< 0x00000040 */
#define SDIO_STA_CMDREND               SDIO_STA_CMDREND_Msk                    /*!<Command response received (CRC check passed)  */
#define SDIO_STA_CMDSENT_Pos           (7U)                                    
#define SDIO_STA_CMDSENT_Msk           (0x1UL << SDIO_STA_CMDSENT_Pos)          /*!< 0x00000080 */
#define SDIO_STA_CMDSENT               SDIO_STA_CMDSENT_Msk                    /*!<Command sent (no response required)           */
#define SDIO_STA_DATAEND_Pos           (8U)                                    
#define SDIO_STA_DATAEND_Msk           (0x1UL << SDIO_STA_DATAEND_Pos)          /*!< 0x00000100 */
#define SDIO_STA_DATAEND               SDIO_STA_DATAEND_Msk                    /*!<Data end (data counter, SDIDCOUNT, is zero)   */
#define SDIO_STA_STBITERR_Pos          (9U)                                    
#define SDIO_STA_STBITERR_Msk          (0x1UL << SDIO_STA_STBITERR_Pos)         /*!< 0x00000200 */
#define SDIO_STA_STBITERR              SDIO_STA_STBITERR_Msk                   /*!<Start bit not detected on all data signals in wide bus mode */
#define SDIO_STA_DBCKEND_Pos           (10U)                                   
#define SDIO_STA_DBCKEND_Msk           (0x1UL << SDIO_STA_DBCKEND_Pos)          /*!< 0x00000400 */
#define SDIO_STA_DBCKEND               SDIO_STA_DBCKEND_Msk                    /*!<Data block sent/received (CRC check passed)   */
#define SDIO_STA_CMDACT_Pos            (11U)                                   
#define SDIO_STA_CMDACT_Msk            (0x1UL << SDIO_STA_CMDACT_Pos)           /*!< 0x00000800 */
#define SDIO_STA_CMDACT                SDIO_STA_CMDACT_Msk                     /*!<Command transfer in progress                  */
#define SDIO_STA_TXACT_Pos             (12U)                                   
#define SDIO_STA_TXACT_Msk             (0x1UL << SDIO_STA_TXACT_Pos)            /*!< 0x00001000 */
#define SDIO_STA_TXACT                 SDIO_STA_TXACT_Msk                      /*!<Data transmit in progress                     */
#define SDIO_STA_RXACT_Pos             (13U)                                   
#define SDIO_STA_RXACT_Msk             (0x1UL << SDIO_STA_RXACT_Pos)            /*!< 0x00002000 */
#define SDIO_STA_RXACT                 SDIO_STA_RXACT_Msk                      /*!<Data receive in progress                      */
#define SDIO_STA_TXFIFOHE_Pos          (14U)                                   
#define SDIO_STA_TXFIFOHE_Msk          (0x1UL << SDIO_STA_TXFIFOHE_Pos)         /*!< 0x00004000 */
#define SDIO_STA_TXFIFOHE              SDIO_STA_TXFIFOHE_Msk                   /*!<Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
#define SDIO_STA_RXFIFOHF_Pos          (15U)                                   
#define SDIO_STA_RXFIFOHF_Msk          (0x1UL << SDIO_STA_RXFIFOHF_Pos)         /*!< 0x00008000 */
#define SDIO_STA_RXFIFOHF              SDIO_STA_RXFIFOHF_Msk                   /*!<Receive FIFO Half Full: there are at least 8 words in the FIFO */
#define SDIO_STA_TXFIFOF_Pos           (16U)                                   
#define SDIO_STA_TXFIFOF_Msk           (0x1UL << SDIO_STA_TXFIFOF_Pos)          /*!< 0x00010000 */
#define SDIO_STA_TXFIFOF               SDIO_STA_TXFIFOF_Msk                    /*!<Transmit FIFO full                            */
#define SDIO_STA_RXFIFOF_Pos           (17U)                                   
#define SDIO_STA_RXFIFOF_Msk           (0x1UL << SDIO_STA_RXFIFOF_Pos)          /*!< 0x00020000 */
#define SDIO_STA_RXFIFOF               SDIO_STA_RXFIFOF_Msk                    /*!<Receive FIFO full                             */
#define SDIO_STA_TXFIFOE_Pos           (18U)                                   
#define SDIO_STA_TXFIFOE_Msk           (0x1UL << SDIO_STA_TXFIFOE_Pos)          /*!< 0x00040000 */
#define SDIO_STA_TXFIFOE               SDIO_STA_TXFIFOE_Msk                    /*!<Transmit FIFO empty                           */
#define SDIO_STA_RXFIFOE_Pos           (19U)                                   
#define SDIO_STA_RXFIFOE_Msk           (0x1UL << SDIO_STA_RXFIFOE_Pos)          /*!< 0x00080000 */
#define SDIO_STA_RXFIFOE               SDIO_STA_RXFIFOE_Msk                    /*!<Receive FIFO empty                            */
#define SDIO_STA_TXDAVL_Pos            (20U)                                   
#define SDIO_STA_TXDAVL_Msk            (0x1UL << SDIO_STA_TXDAVL_Pos)           /*!< 0x00100000 */
#define SDIO_STA_TXDAVL                SDIO_STA_TXDAVL_Msk                     /*!<Data available in transmit FIFO               */
#define SDIO_STA_RXDAVL_Pos            (21U)                                   
#define SDIO_STA_RXDAVL_Msk            (0x1UL << SDIO_STA_RXDAVL_Pos)           /*!< 0x00200000 */
#define SDIO_STA_RXDAVL                SDIO_STA_RXDAVL_Msk                     /*!<Data available in receive FIFO                */
#define SDIO_STA_SDIOIT_Pos            (22U)                                   
#define SDIO_STA_SDIOIT_Msk            (0x1UL << SDIO_STA_SDIOIT_Pos)           /*!< 0x00400000 */
#define SDIO_STA_SDIOIT                SDIO_STA_SDIOIT_Msk                     /*!<SDIO interrupt received                       */
#define SDIO_STA_CEATAEND_Pos          (23U)                                   
#define SDIO_STA_CEATAEND_Msk          (0x1UL << SDIO_STA_CEATAEND_Pos)         /*!< 0x00800000 */
#define SDIO_STA_CEATAEND              SDIO_STA_CEATAEND_Msk                   /*!<CE-ATA command completion signal received for CMD61 */

/*******************  Bit definition for SDIO_ICR register  *******************/
#define SDIO_ICR_CCRCFAILC_Pos         (0U)                                    
#define SDIO_ICR_CCRCFAILC_Msk         (0x1UL << SDIO_ICR_CCRCFAILC_Pos)        /*!< 0x00000001 */
#define SDIO_ICR_CCRCFAILC             SDIO_ICR_CCRCFAILC_Msk                  /*!<CCRCFAIL flag clear bit */
#define SDIO_ICR_DCRCFAILC_Pos         (1U)                                    
#define SDIO_ICR_DCRCFAILC_Msk         (0x1UL << SDIO_ICR_DCRCFAILC_Pos)        /*!< 0x00000002 */
#define SDIO_ICR_DCRCFAILC             SDIO_ICR_DCRCFAILC_Msk                  /*!<DCRCFAIL flag clear bit */
#define SDIO_ICR_CTIMEOUTC_Pos         (2U)                                    
#define SDIO_ICR_CTIMEOUTC_Msk         (0x1UL << SDIO_ICR_CTIMEOUTC_Pos)        /*!< 0x00000004 */
#define SDIO_ICR_CTIMEOUTC             SDIO_ICR_CTIMEOUTC_Msk                  /*!<CTIMEOUT flag clear bit */
#define SDIO_ICR_DTIMEOUTC_Pos         (3U)                                    
#define SDIO_ICR_DTIMEOUTC_Msk         (0x1UL << SDIO_ICR_DTIMEOUTC_Pos)        /*!< 0x00000008 */
#define SDIO_ICR_DTIMEOUTC             SDIO_ICR_DTIMEOUTC_Msk                  /*!<DTIMEOUT flag clear bit */
#define SDIO_ICR_TXUNDERRC_Pos         (4U)                                    
#define SDIO_ICR_TXUNDERRC_Msk         (0x1UL << SDIO_ICR_TXUNDERRC_Pos)        /*!< 0x00000010 */
#define SDIO_ICR_TXUNDERRC             SDIO_ICR_TXUNDERRC_Msk                  /*!<TXUNDERR flag clear bit */
#define SDIO_ICR_RXOVERRC_Pos          (5U)                                    
#define SDIO_ICR_RXOVERRC_Msk          (0x1UL << SDIO_ICR_RXOVERRC_Pos)         /*!< 0x00000020 */
#define SDIO_ICR_RXOVERRC              SDIO_ICR_RXOVERRC_Msk                   /*!<RXOVERR flag clear bit  */
#define SDIO_ICR_CMDRENDC_Pos          (6U)                                    
#define SDIO_ICR_CMDRENDC_Msk          (0x1UL << SDIO_ICR_CMDRENDC_Pos)         /*!< 0x00000040 */
#define SDIO_ICR_CMDRENDC              SDIO_ICR_CMDRENDC_Msk                   /*!<CMDREND flag clear bit  */
#define SDIO_ICR_CMDSENTC_Pos          (7U)                                    
#define SDIO_ICR_CMDSENTC_Msk          (0x1UL << SDIO_ICR_CMDSENTC_Pos)         /*!< 0x00000080 */
#define SDIO_ICR_CMDSENTC              SDIO_ICR_CMDSENTC_Msk                   /*!<CMDSENT flag clear bit  */
#define SDIO_ICR_DATAENDC_Pos          (8U)                                    
#define SDIO_ICR_DATAENDC_Msk          (0x1UL << SDIO_ICR_DATAENDC_Pos)         /*!< 0x00000100 */
#define SDIO_ICR_DATAENDC              SDIO_ICR_DATAENDC_Msk                   /*!<DATAEND flag clear bit  */
#define SDIO_ICR_STBITERRC_Pos         (9U)                                    
#define SDIO_ICR_STBITERRC_Msk         (0x1UL << SDIO_ICR_STBITERRC_Pos)        /*!< 0x00000200 */
#define SDIO_ICR_STBITERRC             SDIO_ICR_STBITERRC_Msk                  /*!<STBITERR flag clear bit */
#define SDIO_ICR_DBCKENDC_Pos          (10U)                                   
#define SDIO_ICR_DBCKENDC_Msk          (0x1UL << SDIO_ICR_DBCKENDC_Pos)         /*!< 0x00000400 */
#define SDIO_ICR_DBCKENDC              SDIO_ICR_DBCKENDC_Msk                   /*!<DBCKEND flag clear bit  */
#define SDIO_ICR_SDIOITC_Pos           (22U)                                   
#define SDIO_ICR_SDIOITC_Msk           (0x1UL << SDIO_ICR_SDIOITC_Pos)          /*!< 0x00400000 */
#define SDIO_ICR_SDIOITC               SDIO_ICR_SDIOITC_Msk                    /*!<SDIOIT flag clear bit   */
#define SDIO_ICR_CEATAENDC_Pos         (23U)                                   
#define SDIO_ICR_CEATAENDC_Msk         (0x1UL << SDIO_ICR_CEATAENDC_Pos)        /*!< 0x00800000 */
#define SDIO_ICR_CEATAENDC             SDIO_ICR_CEATAENDC_Msk                  /*!<CEATAEND flag clear bit */

/******************  Bit definition for SDIO_MASK register  *******************/
#define SDIO_MASK_CCRCFAILIE_Pos       (0U)                                    
#define SDIO_MASK_CCRCFAILIE_Msk       (0x1UL << SDIO_MASK_CCRCFAILIE_Pos)      /*!< 0x00000001 */
#define SDIO_MASK_CCRCFAILIE           SDIO_MASK_CCRCFAILIE_Msk                /*!<Command CRC Fail Interrupt Enable          */
#define SDIO_MASK_DCRCFAILIE_Pos       (1U)                                    
#define SDIO_MASK_DCRCFAILIE_Msk       (0x1UL << SDIO_MASK_DCRCFAILIE_Pos)      /*!< 0x00000002 */
#define SDIO_MASK_DCRCFAILIE           SDIO_MASK_DCRCFAILIE_Msk                /*!<Data CRC Fail Interrupt Enable             */
#define SDIO_MASK_CTIMEOUTIE_Pos       (2U)                                    
#define SDIO_MASK_CTIMEOUTIE_Msk       (0x1UL << SDIO_MASK_CTIMEOUTIE_Pos)      /*!< 0x00000004 */
#define SDIO_MASK_CTIMEOUTIE           SDIO_MASK_CTIMEOUTIE_Msk                /*!<Command TimeOut Interrupt Enable           */
#define SDIO_MASK_DTIMEOUTIE_Pos       (3U)                                    
#define SDIO_MASK_DTIMEOUTIE_Msk       (0x1UL << SDIO_MASK_DTIMEOUTIE_Pos)      /*!< 0x00000008 */
#define SDIO_MASK_DTIMEOUTIE           SDIO_MASK_DTIMEOUTIE_Msk                /*!<Data TimeOut Interrupt Enable              */
#define SDIO_MASK_TXUNDERRIE_Pos       (4U)                                    
#define SDIO_MASK_TXUNDERRIE_Msk       (0x1UL << SDIO_MASK_TXUNDERRIE_Pos)      /*!< 0x00000010 */
#define SDIO_MASK_TXUNDERRIE           SDIO_MASK_TXUNDERRIE_Msk                /*!<Tx FIFO UnderRun Error Interrupt Enable    */
#define SDIO_MASK_RXOVERRIE_Pos        (5U)                                    
#define SDIO_MASK_RXOVERRIE_Msk        (0x1UL << SDIO_MASK_RXOVERRIE_Pos)       /*!< 0x00000020 */
#define SDIO_MASK_RXOVERRIE            SDIO_MASK_RXOVERRIE_Msk                 /*!<Rx FIFO OverRun Error Interrupt Enable     */
#define SDIO_MASK_CMDRENDIE_Pos        (6U)                                    
#define SDIO_MASK_CMDRENDIE_Msk        (0x1UL << SDIO_MASK_CMDRENDIE_Pos)       /*!< 0x00000040 */
#define SDIO_MASK_CMDRENDIE            SDIO_MASK_CMDRENDIE_Msk                 /*!<Command Response Received Interrupt Enable */
#define SDIO_MASK_CMDSENTIE_Pos        (7U)                                    
#define SDIO_MASK_CMDSENTIE_Msk        (0x1UL << SDIO_MASK_CMDSENTIE_Pos)       /*!< 0x00000080 */
#define SDIO_MASK_CMDSENTIE            SDIO_MASK_CMDSENTIE_Msk                 /*!<Command Sent Interrupt Enable              */
#define SDIO_MASK_DATAENDIE_Pos        (8U)                                    
#define SDIO_MASK_DATAENDIE_Msk        (0x1UL << SDIO_MASK_DATAENDIE_Pos)       /*!< 0x00000100 */
#define SDIO_MASK_DATAENDIE            SDIO_MASK_DATAENDIE_Msk                 /*!<Data End Interrupt Enable                  */
#define SDIO_MASK_STBITERRIE_Pos       (9U)                                    
#define SDIO_MASK_STBITERRIE_Msk       (0x1UL << SDIO_MASK_STBITERRIE_Pos)      /*!< 0x00000200 */
#define SDIO_MASK_STBITERRIE           SDIO_MASK_STBITERRIE_Msk                /*!<Start Bit Error Interrupt Enable           */
#define SDIO_MASK_DBCKENDIE_Pos        (10U)                                   
#define SDIO_MASK_DBCKENDIE_Msk        (0x1UL << SDIO_MASK_DBCKENDIE_Pos)       /*!< 0x00000400 */
#define SDIO_MASK_DBCKENDIE            SDIO_MASK_DBCKENDIE_Msk                 /*!<Data Block End Interrupt Enable            */
#define SDIO_MASK_CMDACTIE_Pos         (11U)                                   
#define SDIO_MASK_CMDACTIE_Msk         (0x1UL << SDIO_MASK_CMDACTIE_Pos)        /*!< 0x00000800 */
#define SDIO_MASK_CMDACTIE             SDIO_MASK_CMDACTIE_Msk                  /*!<CCommand Acting Interrupt Enable           */
#define SDIO_MASK_TXACTIE_Pos          (12U)                                   
#define SDIO_MASK_TXACTIE_Msk          (0x1UL << SDIO_MASK_TXACTIE_Pos)         /*!< 0x00001000 */
#define SDIO_MASK_TXACTIE              SDIO_MASK_TXACTIE_Msk                   /*!<Data Transmit Acting Interrupt Enable      */
#define SDIO_MASK_RXACTIE_Pos          (13U)                                   
#define SDIO_MASK_RXACTIE_Msk          (0x1UL << SDIO_MASK_RXACTIE_Pos)         /*!< 0x00002000 */
#define SDIO_MASK_RXACTIE              SDIO_MASK_RXACTIE_Msk                   /*!<Data receive acting interrupt enabled      */
#define SDIO_MASK_TXFIFOHEIE_Pos       (14U)                                   
#define SDIO_MASK_TXFIFOHEIE_Msk       (0x1UL << SDIO_MASK_TXFIFOHEIE_Pos)      /*!< 0x00004000 */
#define SDIO_MASK_TXFIFOHEIE           SDIO_MASK_TXFIFOHEIE_Msk                /*!<Tx FIFO Half Empty interrupt Enable        */
#define SDIO_MASK_RXFIFOHFIE_Pos       (15U)                                   
#define SDIO_MASK_RXFIFOHFIE_Msk       (0x1UL << SDIO_MASK_RXFIFOHFIE_Pos)      /*!< 0x00008000 */
#define SDIO_MASK_RXFIFOHFIE           SDIO_MASK_RXFIFOHFIE_Msk                /*!<Rx FIFO Half Full interrupt Enable         */
#define SDIO_MASK_TXFIFOFIE_Pos        (16U)                                   
#define SDIO_MASK_TXFIFOFIE_Msk        (0x1UL << SDIO_MASK_TXFIFOFIE_Pos)       /*!< 0x00010000 */
#define SDIO_MASK_TXFIFOFIE            SDIO_MASK_TXFIFOFIE_Msk                 /*!<Tx FIFO Full interrupt Enable              */
#define SDIO_MASK_RXFIFOFIE_Pos        (17U)                                   
#define SDIO_MASK_RXFIFOFIE_Msk        (0x1UL << SDIO_MASK_RXFIFOFIE_Pos)       /*!< 0x00020000 */
#define SDIO_MASK_RXFIFOFIE            SDIO_MASK_RXFIFOFIE_Msk                 /*!<Rx FIFO Full interrupt Enable              */
#define SDIO_MASK_TXFIFOEIE_Pos        (18U)                                   
#define SDIO_MASK_TXFIFOEIE_Msk        (0x1UL << SDIO_MASK_TXFIFOEIE_Pos)       /*!< 0x00040000 */
#define SDIO_MASK_TXFIFOEIE            SDIO_MASK_TXFIFOEIE_Msk                 /*!<Tx FIFO Empty interrupt Enable             */
#define SDIO_MASK_RXFIFOEIE_Pos        (19U)                                   
#define SDIO_MASK_RXFIFOEIE_Msk        (0x1UL << SDIO_MASK_RXFIFOEIE_Pos)       /*!< 0x00080000 */
#define SDIO_MASK_RXFIFOEIE            SDIO_MASK_RXFIFOEIE_Msk                 /*!<Rx FIFO Empty interrupt Enable             */
#define SDIO_MASK_TXDAVLIE_Pos         (20U)                                   
#define SDIO_MASK_TXDAVLIE_Msk         (0x1UL << SDIO_MASK_TXDAVLIE_Pos)        /*!< 0x00100000 */
#define SDIO_MASK_TXDAVLIE             SDIO_MASK_TXDAVLIE_Msk                  /*!<Data available in Tx FIFO interrupt Enable */
#define SDIO_MASK_RXDAVLIE_Pos         (21U)                                   
#define SDIO_MASK_RXDAVLIE_Msk         (0x1UL << SDIO_MASK_RXDAVLIE_Pos)        /*!< 0x00200000 */
#define SDIO_MASK_RXDAVLIE             SDIO_MASK_RXDAVLIE_Msk                  /*!<Data available in Rx FIFO interrupt Enable */
#define SDIO_MASK_SDIOITIE_Pos         (22U)                                   
#define SDIO_MASK_SDIOITIE_Msk         (0x1UL << SDIO_MASK_SDIOITIE_Pos)        /*!< 0x00400000 */
#define SDIO_MASK_SDIOITIE             SDIO_MASK_SDIOITIE_Msk                  /*!<SDIO Mode Interrupt Received interrupt Enable */
#define SDIO_MASK_CEATAENDIE_Pos       (23U)                                   
#define SDIO_MASK_CEATAENDIE_Msk       (0x1UL << SDIO_MASK_CEATAENDIE_Pos)      /*!< 0x00800000 */
#define SDIO_MASK_CEATAENDIE           SDIO_MASK_CEATAENDIE_Msk                /*!<CE-ATA command completion signal received Interrupt Enable */

/*****************  Bit definition for SDIO_FIFOCNT register  *****************/
#define SDIO_FIFOCNT_FIFOCOUNT_Pos     (0U)                                    
#define SDIO_FIFOCNT_FIFOCOUNT_Msk     (0xFFFFFFUL << SDIO_FIFOCNT_FIFOCOUNT_Pos) /*!< 0x00FFFFFF */
#define SDIO_FIFOCNT_FIFOCOUNT         SDIO_FIFOCNT_FIFOCOUNT_Msk              /*!<Remaining number of words to be written to or read from the FIFO */

/******************  Bit definition for SDIO_FIFO register  *******************/
#define SDIO_FIFO_FIFODATA_Pos         (0U)                                    
#define SDIO_FIFO_FIFODATA_Msk         (0xFFFFFFFFUL << SDIO_FIFO_FIFODATA_Pos) /*!< 0xFFFFFFFF */
#define SDIO_FIFO_FIFODATA             SDIO_FIFO_FIFODATA_Msk                  /*!<Receive and transmit FIFO data */

/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDG_CR register  ********************/
#define WWDG_CR_T_Pos           (0U)                                           
#define WWDG_CR_T_Msk           (0x7FUL << WWDG_CR_T_Pos)                       /*!< 0x0000007F */
#define WWDG_CR_T               WWDG_CR_T_Msk                                  /*!<T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define WWDG_CR_T_0             (0x01UL << WWDG_CR_T_Pos)                       /*!< 0x01 */
#define WWDG_CR_T_1             (0x02UL << WWDG_CR_T_Pos)                       /*!< 0x02 */
#define WWDG_CR_T_2             (0x04UL << WWDG_CR_T_Pos)                       /*!< 0x04 */
#define WWDG_CR_T_3             (0x08UL << WWDG_CR_T_Pos)                       /*!< 0x08 */
#define WWDG_CR_T_4             (0x10UL << WWDG_CR_T_Pos)                       /*!< 0x10 */
#define WWDG_CR_T_5             (0x20UL << WWDG_CR_T_Pos)                       /*!< 0x20 */
#define WWDG_CR_T_6             (0x40UL << WWDG_CR_T_Pos)                       /*!< 0x40 */
/* Legacy defines */
#define  WWDG_CR_T0                          WWDG_CR_T_0
#define  WWDG_CR_T1                          WWDG_CR_T_1
#define  WWDG_CR_T2                          WWDG_CR_T_2
#define  WWDG_CR_T3                          WWDG_CR_T_3
#define  WWDG_CR_T4                          WWDG_CR_T_4
#define  WWDG_CR_T5                          WWDG_CR_T_5
#define  WWDG_CR_T6                          WWDG_CR_T_6

#define WWDG_CR_WDGA_Pos        (7U)                                           
#define WWDG_CR_WDGA_Msk        (0x1UL << WWDG_CR_WDGA_Pos)                     /*!< 0x00000080 */
#define WWDG_CR_WDGA            WWDG_CR_WDGA_Msk                               /*!<Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define WWDG_CFR_W_Pos          (0U)                                           
#define WWDG_CFR_W_Msk          (0x7FUL << WWDG_CFR_W_Pos)                      /*!< 0x0000007F */
#define WWDG_CFR_W              WWDG_CFR_W_Msk                                 /*!<W[6:0] bits (7-bit window value) */
#define WWDG_CFR_W_0            (0x01UL << WWDG_CFR_W_Pos)                      /*!< 0x0001 */
#define WWDG_CFR_W_1            (0x02UL << WWDG_CFR_W_Pos)                      /*!< 0x0002 */
#define WWDG_CFR_W_2            (0x04UL << WWDG_CFR_W_Pos)                      /*!< 0x0004 */
#define WWDG_CFR_W_3            (0x08UL << WWDG_CFR_W_Pos)                      /*!< 0x0008 */
#define WWDG_CFR_W_4            (0x10UL << WWDG_CFR_W_Pos)                      /*!< 0x0010 */
#define WWDG_CFR_W_5            (0x20UL << WWDG_CFR_W_Pos)                      /*!< 0x0020 */
#define WWDG_CFR_W_6            (0x40UL << WWDG_CFR_W_Pos)                      /*!< 0x0040 */
/* Legacy defines */
#define  WWDG_CFR_W0                         WWDG_CFR_W_0
#define  WWDG_CFR_W1                         WWDG_CFR_W_1
#define  WWDG_CFR_W2                         WWDG_CFR_W_2
#define  WWDG_CFR_W3                         WWDG_CFR_W_3
#define  WWDG_CFR_W4                         WWDG_CFR_W_4
#define  WWDG_CFR_W5                         WWDG_CFR_W_5
#define  WWDG_CFR_W6                         WWDG_CFR_W_6

#define WWDG_CFR_WDGTB_Pos      (7U)                                           
#define WWDG_CFR_WDGTB_Msk      (0x3UL << WWDG_CFR_WDGTB_Pos)                   /*!< 0x00000180 */
#define WWDG_CFR_WDGTB          WWDG_CFR_WDGTB_Msk                             /*!<WDGTB[1:0] bits (Timer Base) */
#define WWDG_CFR_WDGTB_0        (0x1UL << WWDG_CFR_WDGTB_Pos)                   /*!< 0x0080 */
#define WWDG_CFR_WDGTB_1        (0x2UL << WWDG_CFR_WDGTB_Pos)                   /*!< 0x0100 */
/* Legacy defines */
#define  WWDG_CFR_WDGTB0                     WWDG_CFR_WDGTB_0
#define  WWDG_CFR_WDGTB1                     WWDG_CFR_WDGTB_1

#define WWDG_CFR_EWI_Pos        (9U)                                           
#define WWDG_CFR_EWI_Msk        (0x1UL << WWDG_CFR_EWI_Pos)                     /*!< 0x00000200 */
#define WWDG_CFR_EWI            WWDG_CFR_EWI_Msk                               /*!<Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_SR register  ********************/
#define WWDG_SR_EWIF_Pos        (0U)                                           
#define WWDG_SR_EWIF_Msk        (0x1UL << WWDG_SR_EWIF_Pos)                     /*!< 0x00000001 */
#define WWDG_SR_EWIF            WWDG_SR_EWIF_Msk                               /*!<Early Wakeup Interrupt Flag */


/******************************************************************************/
/*                                                                            */
/*                                DBG                                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBGMCU_IDCODE register  *************/
#define DBGMCU_IDCODE_DEV_ID_Pos                     (0U)                      
#define DBGMCU_IDCODE_DEV_ID_Msk                     (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos) /*!< 0x00000FFF */
#define DBGMCU_IDCODE_DEV_ID                         DBGMCU_IDCODE_DEV_ID_Msk  
#define DBGMCU_IDCODE_REV_ID_Pos                     (16U)                     
#define DBGMCU_IDCODE_REV_ID_Msk                     (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0xFFFF0000 */
#define DBGMCU_IDCODE_REV_ID                         DBGMCU_IDCODE_REV_ID_Msk  

/********************  Bit definition for DBGMCU_CR register  *****************/
#define DBGMCU_CR_DBG_SLEEP_Pos                      (0U)                      
#define DBGMCU_CR_DBG_SLEEP_Msk                      (0x1UL << DBGMCU_CR_DBG_SLEEP_Pos) /*!< 0x00000001 */
#define DBGMCU_CR_DBG_SLEEP                          DBGMCU_CR_DBG_SLEEP_Msk   
#define DBGMCU_CR_DBG_STOP_Pos                       (1U)                      
#define DBGMCU_CR_DBG_STOP_Msk                       (0x1UL << DBGMCU_CR_DBG_STOP_Pos) /*!< 0x00000002 */
#define DBGMCU_CR_DBG_STOP                           DBGMCU_CR_DBG_STOP_Msk    
#define DBGMCU_CR_DBG_STANDBY_Pos                    (2U)                      
#define DBGMCU_CR_DBG_STANDBY_Msk                    (0x1UL << DBGMCU_CR_DBG_STANDBY_Pos) /*!< 0x00000004 */
#define DBGMCU_CR_DBG_STANDBY                        DBGMCU_CR_DBG_STANDBY_Msk 
#define DBGMCU_CR_TRACE_IOEN_Pos                     (5U)                      
#define DBGMCU_CR_TRACE_IOEN_Msk                     (0x1UL << DBGMCU_CR_TRACE_IOEN_Pos) /*!< 0x00000020 */
#define DBGMCU_CR_TRACE_IOEN                         DBGMCU_CR_TRACE_IOEN_Msk  

#define DBGMCU_CR_TRACE_MODE_Pos                     (6U)                      
#define DBGMCU_CR_TRACE_MODE_Msk                     (0x3UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x000000C0 */
#define DBGMCU_CR_TRACE_MODE                         DBGMCU_CR_TRACE_MODE_Msk  
#define DBGMCU_CR_TRACE_MODE_0                       (0x1UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x00000040 */
#define DBGMCU_CR_TRACE_MODE_1                       (0x2UL << DBGMCU_CR_TRACE_MODE_Pos) /*!< 0x00000080 */

/********************  Bit definition for DBGMCU_APB1_FZ register  ************/
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos             (0U)                      
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos) /*!< 0x00000001 */
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP                 DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos             (1U)                      
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos) /*!< 0x00000002 */
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP                 DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP_Pos             (2U)                      
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM4_STOP_Pos) /*!< 0x00000004 */
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP                 DBGMCU_APB1_FZ_DBG_TIM4_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP_Pos             (3U)                      
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM5_STOP_Pos) /*!< 0x00000008 */
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP                 DBGMCU_APB1_FZ_DBG_TIM5_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos             (4U)                      
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos) /*!< 0x00000010 */
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP                 DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos             (5U)                      
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos) /*!< 0x00000020 */
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP                 DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_TIM12_STOP_Pos            (6U)                      
#define DBGMCU_APB1_FZ_DBG_TIM12_STOP_Msk            (0x1UL << DBGMCU_APB1_FZ_DBG_TIM12_STOP_Pos) /*!< 0x00000040 */
#define DBGMCU_APB1_FZ_DBG_TIM12_STOP                DBGMCU_APB1_FZ_DBG_TIM12_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_TIM13_STOP_Pos            (7U)                      
#define DBGMCU_APB1_FZ_DBG_TIM13_STOP_Msk            (0x1UL << DBGMCU_APB1_FZ_DBG_TIM13_STOP_Pos) /*!< 0x00000080 */
#define DBGMCU_APB1_FZ_DBG_TIM13_STOP                DBGMCU_APB1_FZ_DBG_TIM13_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP_Pos            (8U)                      
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP_Msk            (0x1UL << DBGMCU_APB1_FZ_DBG_TIM14_STOP_Pos) /*!< 0x00000100 */
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP                DBGMCU_APB1_FZ_DBG_TIM14_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos              (10U)                     
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk              (0x1UL << DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos) /*!< 0x00000400 */
#define DBGMCU_APB1_FZ_DBG_RTC_STOP                  DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos             (11U)                     
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos) /*!< 0x00000800 */
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP                 DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos             (12U)                     
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos) /*!< 0x00001000 */
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP                 DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos    (21U)                     
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk    (0x1UL << DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos) /*!< 0x00200000 */
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT        DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk 
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Pos    (22U)                     
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Msk    (0x1UL << DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Pos) /*!< 0x00400000 */
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT        DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Msk 
#define DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT_Pos    (23U)                     
#define DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT_Msk    (0x1UL << DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT_Pos) /*!< 0x00800000 */
#define DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT        DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT_Msk 
#define DBGMCU_APB1_FZ_DBG_CAN1_STOP_Pos             (25U)                     
#define DBGMCU_APB1_FZ_DBG_CAN1_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_CAN1_STOP_Pos) /*!< 0x02000000 */
#define DBGMCU_APB1_FZ_DBG_CAN1_STOP                 DBGMCU_APB1_FZ_DBG_CAN1_STOP_Msk 
#define DBGMCU_APB1_FZ_DBG_CAN2_STOP_Pos             (26U)                     
#define DBGMCU_APB1_FZ_DBG_CAN2_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_CAN2_STOP_Pos) /*!< 0x04000000 */
#define DBGMCU_APB1_FZ_DBG_CAN2_STOP                 DBGMCU_APB1_FZ_DBG_CAN2_STOP_Msk 
/* Old IWDGSTOP bit definition, maintained for legacy purpose */
#define  DBGMCU_APB1_FZ_DBG_IWDEG_STOP           DBGMCU_APB1_FZ_DBG_IWDG_STOP

/********************  Bit definition for DBGMCU_APB2_FZ register  ************/
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos             (0U)                      
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk             (0x1UL << DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos) /*!< 0x00000001 */
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP                 DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk 
#define DBGMCU_APB2_FZ_DBG_TIM8_STOP_Pos             (1U)                      
#define DBGMCU_APB2_FZ_DBG_TIM8_STOP_Msk             (0x1UL << DBGMCU_APB2_FZ_DBG_TIM8_STOP_Pos) /*!< 0x00000002 */
#define DBGMCU_APB2_FZ_DBG_TIM8_STOP                 DBGMCU_APB2_FZ_DBG_TIM8_STOP_Msk 
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP_Pos             (16U)                     
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP_Msk             (0x1UL << DBGMCU_APB2_FZ_DBG_TIM9_STOP_Pos) /*!< 0x00010000 */
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP                 DBGMCU_APB2_FZ_DBG_TIM9_STOP_Msk 
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP_Pos            (17U)                     
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP_Msk            (0x1UL << DBGMCU_APB2_FZ_DBG_TIM10_STOP_Pos) /*!< 0x00020000 */
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP                DBGMCU_APB2_FZ_DBG_TIM10_STOP_Msk 
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP_Pos            (18U)                     
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP_Msk            (0x1UL << DBGMCU_APB2_FZ_DBG_TIM11_STOP_Pos) /*!< 0x00040000 */
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP                DBGMCU_APB2_FZ_DBG_TIM11_STOP_Msk 

/******************************************************************************/
/*                                                                            */
/*                Ethernet MAC Registers bits definitions                     */
/*                                                                            */
/******************************************************************************/
/* Bit definition for Ethernet MAC Control Register register */
#define ETH_MACCR_WD_Pos                              (23U)                    
#define ETH_MACCR_WD_Msk                              (0x1UL << ETH_MACCR_WD_Pos) /*!< 0x00800000 */
#define ETH_MACCR_WD                                  ETH_MACCR_WD_Msk         /* Watchdog disable */
#define ETH_MACCR_JD_Pos                              (22U)                    
#define ETH_MACCR_JD_Msk                              (0x1UL << ETH_MACCR_JD_Pos) /*!< 0x00400000 */
#define ETH_MACCR_JD                                  ETH_MACCR_JD_Msk         /* Jabber disable */
#define ETH_MACCR_IFG_Pos                             (17U)                    
#define ETH_MACCR_IFG_Msk                             (0x7UL << ETH_MACCR_IFG_Pos) /*!< 0x000E0000 */
#define ETH_MACCR_IFG                                 ETH_MACCR_IFG_Msk        /* Inter-frame gap */
#define ETH_MACCR_IFG_96Bit                           0x00000000U              /* Minimum IFG between frames during transmission is 96Bit */
#define ETH_MACCR_IFG_88Bit                           0x00020000U              /* Minimum IFG between frames during transmission is 88Bit */
#define ETH_MACCR_IFG_80Bit                           0x00040000U              /* Minimum IFG between frames during transmission is 80Bit */
#define ETH_MACCR_IFG_72Bit                           0x00060000U              /* Minimum IFG between frames during transmission is 72Bit */
#define ETH_MACCR_IFG_64Bit                           0x00080000U              /* Minimum IFG between frames during transmission is 64Bit */
#define ETH_MACCR_IFG_56Bit                           0x000A0000U              /* Minimum IFG between frames during transmission is 56Bit */
#define ETH_MACCR_IFG_48Bit                           0x000C0000U              /* Minimum IFG between frames during transmission is 48Bit */
#define ETH_MACCR_IFG_40Bit                           0x000E0000U              /* Minimum IFG between frames during transmission is 40Bit */
#define ETH_MACCR_CSD_Pos                             (16U)                    
#define ETH_MACCR_CSD_Msk                             (0x1UL << ETH_MACCR_CSD_Pos) /*!< 0x00010000 */
#define ETH_MACCR_CSD                                 ETH_MACCR_CSD_Msk        /* Carrier sense disable (during transmission) */
#define ETH_MACCR_FES_Pos                             (14U)                    
#define ETH_MACCR_FES_Msk                             (0x1UL << ETH_MACCR_FES_Pos) /*!< 0x00004000 */
#define ETH_MACCR_FES                                 ETH_MACCR_FES_Msk        /* Fast ethernet speed */
#define ETH_MACCR_ROD_Pos                             (13U)                    
#define ETH_MACCR_ROD_Msk                             (0x1UL << ETH_MACCR_ROD_Pos) /*!< 0x00002000 */
#define ETH_MACCR_ROD                                 ETH_MACCR_ROD_Msk        /* Receive own disable */
#define ETH_MACCR_LM_Pos                              (12U)                    
#define ETH_MACCR_LM_Msk                              (0x1UL << ETH_MACCR_LM_Pos) /*!< 0x00001000 */
#define ETH_MACCR_LM                                  ETH_MACCR_LM_Msk         /* loopback mode */
#define ETH_MACCR_DM_Pos                              (11U)                    
#define ETH_MACCR_DM_Msk                              (0x1UL << ETH_MACCR_DM_Pos) /*!< 0x00000800 */
#define ETH_MACCR_DM                                  ETH_MACCR_DM_Msk         /* Duplex mode */
#define ETH_MACCR_IPCO_Pos                            (10U)                    
#define ETH_MACCR_IPCO_Msk                            (0x1UL << ETH_MACCR_IPCO_Pos) /*!< 0x00000400 */
#define ETH_MACCR_IPCO                                ETH_MACCR_IPCO_Msk       /* IP Checksum offload */
#define ETH_MACCR_RD_Pos                              (9U)                     
#define ETH_MACCR_RD_Msk                              (0x1UL << ETH_MACCR_RD_Pos) /*!< 0x00000200 */
#define ETH_MACCR_RD                                  ETH_MACCR_RD_Msk         /* Retry disable */
#define ETH_MACCR_APCS_Pos                            (7U)                     
#define ETH_MACCR_APCS_Msk                            (0x1UL << ETH_MACCR_APCS_Pos) /*!< 0x00000080 */
#define ETH_MACCR_APCS                                ETH_MACCR_APCS_Msk       /* Automatic Pad/CRC stripping */
#define ETH_MACCR_BL_Pos                              (5U)                     
#define ETH_MACCR_BL_Msk                              (0x3UL << ETH_MACCR_BL_Pos) /*!< 0x00000060 */
#define ETH_MACCR_BL                                  ETH_MACCR_BL_Msk         /* Back-off limit: random integer number (r) of slot time delays before rescheduling
                                                       a transmission attempt during retries after a collision: 0 =< r <2^k */
#define ETH_MACCR_BL_10                               0x00000000U              /* k = min (n, 10) */
#define ETH_MACCR_BL_8                                0x00000020U              /* k = min (n, 8) */
#define ETH_MACCR_BL_4                                0x00000040U              /* k = min (n, 4) */
#define ETH_MACCR_BL_1                                0x00000060U              /* k = min (n, 1) */ 
#define ETH_MACCR_DC_Pos                              (4U)                     
#define ETH_MACCR_DC_Msk                              (0x1UL << ETH_MACCR_DC_Pos) /*!< 0x00000010 */
#define ETH_MACCR_DC                                  ETH_MACCR_DC_Msk         /* Defferal check */
#define ETH_MACCR_TE_Pos                              (3U)                     
#define ETH_MACCR_TE_Msk                              (0x1UL << ETH_MACCR_TE_Pos) /*!< 0x00000008 */
#define ETH_MACCR_TE                                  ETH_MACCR_TE_Msk         /* Transmitter enable */
#define ETH_MACCR_RE_Pos                              (2U)                     
#define ETH_MACCR_RE_Msk                              (0x1UL << ETH_MACCR_RE_Pos) /*!< 0x00000004 */
#define ETH_MACCR_RE                                  ETH_MACCR_RE_Msk         /* Receiver enable */

/* Bit definition for Ethernet MAC Frame Filter Register */
#define ETH_MACFFR_RA_Pos                             (31U)                    
#define ETH_MACFFR_RA_Msk                             (0x1UL << ETH_MACFFR_RA_Pos) /*!< 0x80000000 */
#define ETH_MACFFR_RA                                 ETH_MACFFR_RA_Msk        /* Receive all */
#define ETH_MACFFR_HPF_Pos                            (10U)                    
#define ETH_MACFFR_HPF_Msk                            (0x1UL << ETH_MACFFR_HPF_Pos) /*!< 0x00000400 */
#define ETH_MACFFR_HPF                                ETH_MACFFR_HPF_Msk       /* Hash or perfect filter */
#define ETH_MACFFR_SAF_Pos                            (9U)                     
#define ETH_MACFFR_SAF_Msk                            (0x1UL << ETH_MACFFR_SAF_Pos) /*!< 0x00000200 */
#define ETH_MACFFR_SAF                                ETH_MACFFR_SAF_Msk       /* Source address filter enable */
#define ETH_MACFFR_SAIF_Pos                           (8U)                     
#define ETH_MACFFR_SAIF_Msk                           (0x1UL << ETH_MACFFR_SAIF_Pos) /*!< 0x00000100 */
#define ETH_MACFFR_SAIF                               ETH_MACFFR_SAIF_Msk      /* SA inverse filtering */ 
#define ETH_MACFFR_PCF_Pos                            (6U)                     
#define ETH_MACFFR_PCF_Msk                            (0x3UL << ETH_MACFFR_PCF_Pos) /*!< 0x000000C0 */
#define ETH_MACFFR_PCF                                ETH_MACFFR_PCF_Msk       /* Pass control frames: 3 cases */
#define ETH_MACFFR_PCF_BlockAll_Pos                   (6U)                     
#define ETH_MACFFR_PCF_BlockAll_Msk                   (0x1UL << ETH_MACFFR_PCF_BlockAll_Pos) /*!< 0x00000040 */
#define ETH_MACFFR_PCF_BlockAll                       ETH_MACFFR_PCF_BlockAll_Msk /* MAC filters all control frames from reaching the application */
#define ETH_MACFFR_PCF_ForwardAll_Pos                 (7U)                     
#define ETH_MACFFR_PCF_ForwardAll_Msk                 (0x1UL << ETH_MACFFR_PCF_ForwardAll_Pos) /*!< 0x00000080 */
#define ETH_MACFFR_PCF_ForwardAll                     ETH_MACFFR_PCF_ForwardAll_Msk /* MAC forwards all control frames to application even if they fail the Address Filter */
#define ETH_MACFFR_PCF_ForwardPassedAddrFilter_Pos    (6U)                     
#define ETH_MACFFR_PCF_ForwardPassedAddrFilter_Msk    (0x3UL << ETH_MACFFR_PCF_ForwardPassedAddrFilter_Pos) /*!< 0x000000C0 */
#define ETH_MACFFR_PCF_ForwardPassedAddrFilter        ETH_MACFFR_PCF_ForwardPassedAddrFilter_Msk /* MAC forwards control frames that pass the Address Filter. */ 
#define ETH_MACFFR_BFD_Pos                            (5U)                     
#define ETH_MACFFR_BFD_Msk                            (0x1UL << ETH_MACFFR_BFD_Pos) /*!< 0x00000020 */
#define ETH_MACFFR_BFD                                ETH_MACFFR_BFD_Msk       /* Broadcast frame disable */ 
#define ETH_MACFFR_PAM_Pos                            (4U)                     
#define ETH_MACFFR_PAM_Msk                            (0x1UL << ETH_MACFFR_PAM_Pos) /*!< 0x00000010 */
#define ETH_MACFFR_PAM                                ETH_MACFFR_PAM_Msk       /* Pass all mutlicast */
#define ETH_MACFFR_DAIF_Pos                           (3U)                     
#define ETH_MACFFR_DAIF_Msk                           (0x1UL << ETH_MACFFR_DAIF_Pos) /*!< 0x00000008 */
#define ETH_MACFFR_DAIF                               ETH_MACFFR_DAIF_Msk      /* DA Inverse filtering */
#define ETH_MACFFR_HM_Pos                             (2U)                     
#define ETH_MACFFR_HM_Msk                             (0x1UL << ETH_MACFFR_HM_Pos) /*!< 0x00000004 */
#define ETH_MACFFR_HM                                 ETH_MACFFR_HM_Msk        /* Hash multicast */ 
#define ETH_MACFFR_HU_Pos                             (1U)                     
#define ETH_MACFFR_HU_Msk                             (0x1UL << ETH_MACFFR_HU_Pos) /*!< 0x00000002 */
#define ETH_MACFFR_HU                                 ETH_MACFFR_HU_Msk        /* Hash unicast */
#define ETH_MACFFR_PM_Pos                             (0U)                     
#define ETH_MACFFR_PM_Msk                             (0x1UL << ETH_MACFFR_PM_Pos) /*!< 0x00000001 */
#define ETH_MACFFR_PM                                 ETH_MACFFR_PM_Msk        /* Promiscuous mode */

/* Bit definition for Ethernet MAC Hash Table High Register */
#define ETH_MACHTHR_HTH_Pos                           (0U)                     
#define ETH_MACHTHR_HTH_Msk                           (0xFFFFFFFFUL << ETH_MACHTHR_HTH_Pos) /*!< 0xFFFFFFFF */
#define ETH_MACHTHR_HTH                               ETH_MACHTHR_HTH_Msk      /* Hash table high */

/* Bit definition for Ethernet MAC Hash Table Low Register */
#define ETH_MACHTLR_HTL_Pos                           (0U)                     
#define ETH_MACHTLR_HTL_Msk                           (0xFFFFFFFFUL << ETH_MACHTLR_HTL_Pos) /*!< 0xFFFFFFFF */
#define ETH_MACHTLR_HTL                               ETH_MACHTLR_HTL_Msk      /* Hash table low */

/* Bit definition for Ethernet MAC MII Address Register */
#define ETH_MACMIIAR_PA_Pos                           (11U)                    
#define ETH_MACMIIAR_PA_Msk                           (0x1FUL << ETH_MACMIIAR_PA_Pos) /*!< 0x0000F800 */
#define ETH_MACMIIAR_PA                               ETH_MACMIIAR_PA_Msk      /* Physical layer address */
#define ETH_MACMIIAR_MR_Pos                           (6U)                     
#define ETH_MACMIIAR_MR_Msk                           (0x1FUL << ETH_MACMIIAR_MR_Pos) /*!< 0x000007C0 */
#define ETH_MACMIIAR_MR                               ETH_MACMIIAR_MR_Msk      /* MII register in the selected PHY */
#define ETH_MACMIIAR_CR_Pos                           (2U)                     
#define ETH_MACMIIAR_CR_Msk                           (0x7UL << ETH_MACMIIAR_CR_Pos) /*!< 0x0000001C */
#define ETH_MACMIIAR_CR                               ETH_MACMIIAR_CR_Msk      /* CR clock range: 6 cases */
#define ETH_MACMIIAR_CR_Div42                         0x00000000U              /* HCLK:60-100 MHz; MDC clock= HCLK/42   */
#define ETH_MACMIIAR_CR_Div62_Pos                     (2U)                     
#define ETH_MACMIIAR_CR_Div62_Msk                     (0x1UL << ETH_MACMIIAR_CR_Div62_Pos) /*!< 0x00000004 */
#define ETH_MACMIIAR_CR_Div62                         ETH_MACMIIAR_CR_Div62_Msk /* HCLK:100-150 MHz; MDC clock= HCLK/62  */
#define ETH_MACMIIAR_CR_Div16_Pos                     (3U)                     
#define ETH_MACMIIAR_CR_Div16_Msk                     (0x1UL << ETH_MACMIIAR_CR_Div16_Pos) /*!< 0x00000008 */
#define ETH_MACMIIAR_CR_Div16                         ETH_MACMIIAR_CR_Div16_Msk /* HCLK:20-35 MHz; MDC clock= HCLK/16    */
#define ETH_MACMIIAR_CR_Div26_Pos                     (2U)                     
#define ETH_MACMIIAR_CR_Div26_Msk                     (0x3UL << ETH_MACMIIAR_CR_Div26_Pos) /*!< 0x0000000C */
#define ETH_MACMIIAR_CR_Div26                         ETH_MACMIIAR_CR_Div26_Msk /* HCLK:35-60 MHz; MDC clock= HCLK/26    */
#define ETH_MACMIIAR_CR_Div102_Pos                    (4U)                     
#define ETH_MACMIIAR_CR_Div102_Msk                    (0x1UL << ETH_MACMIIAR_CR_Div102_Pos) /*!< 0x00000010 */
#define ETH_MACMIIAR_CR_Div102                        ETH_MACMIIAR_CR_Div102_Msk /* HCLK:150-168 MHz; MDC clock= HCLK/102 */
#define ETH_MACMIIAR_MW_Pos                           (1U)                     
#define ETH_MACMIIAR_MW_Msk                           (0x1UL << ETH_MACMIIAR_MW_Pos) /*!< 0x00000002 */
#define ETH_MACMIIAR_MW                               ETH_MACMIIAR_MW_Msk      /* MII write */
#define ETH_MACMIIAR_MB_Pos                           (0U)                     
#define ETH_MACMIIAR_MB_Msk                           (0x1UL << ETH_MACMIIAR_MB_Pos) /*!< 0x00000001 */
#define ETH_MACMIIAR_MB                               ETH_MACMIIAR_MB_Msk      /* MII busy  */

/* Bit definition for Ethernet MAC MII Data Register */
#define ETH_MACMIIDR_MD_Pos                           (0U)                     
#define ETH_MACMIIDR_MD_Msk                           (0xFFFFUL << ETH_MACMIIDR_MD_Pos) /*!< 0x0000FFFF */
#define ETH_MACMIIDR_MD                               ETH_MACMIIDR_MD_Msk      /* MII data: read/write data from/to PHY */

/* Bit definition for Ethernet MAC Flow Control Register */
#define ETH_MACFCR_PT_Pos                             (16U)                    
#define ETH_MACFCR_PT_Msk                             (0xFFFFUL << ETH_MACFCR_PT_Pos) /*!< 0xFFFF0000 */
#define ETH_MACFCR_PT                                 ETH_MACFCR_PT_Msk        /* Pause time */
#define ETH_MACFCR_ZQPD_Pos                           (7U)                     
#define ETH_MACFCR_ZQPD_Msk                           (0x1UL << ETH_MACFCR_ZQPD_Pos) /*!< 0x00000080 */
#define ETH_MACFCR_ZQPD                               ETH_MACFCR_ZQPD_Msk      /* Zero-quanta pause disable */
#define ETH_MACFCR_PLT_Pos                            (4U)                     
#define ETH_MACFCR_PLT_Msk                            (0x3UL << ETH_MACFCR_PLT_Pos) /*!< 0x00000030 */
#define ETH_MACFCR_PLT                                ETH_MACFCR_PLT_Msk       /* Pause low threshold: 4 cases */
#define ETH_MACFCR_PLT_Minus4                         0x00000000U              /* Pause time minus 4 slot times   */
#define ETH_MACFCR_PLT_Minus28_Pos                    (4U)                     
#define ETH_MACFCR_PLT_Minus28_Msk                    (0x1UL << ETH_MACFCR_PLT_Minus28_Pos) /*!< 0x00000010 */
#define ETH_MACFCR_PLT_Minus28                        ETH_MACFCR_PLT_Minus28_Msk /* Pause time minus 28 slot times  */
#define ETH_MACFCR_PLT_Minus144_Pos                   (5U)                     
#define ETH_MACFCR_PLT_Minus144_Msk                   (0x1UL << ETH_MACFCR_PLT_Minus144_Pos) /*!< 0x00000020 */
#define ETH_MACFCR_PLT_Minus144                       ETH_MACFCR_PLT_Minus144_Msk /* Pause time minus 144 slot times */
#define ETH_MACFCR_PLT_Minus256_Pos                   (4U)                     
#define ETH_MACFCR_PLT_Minus256_Msk                   (0x3UL << ETH_MACFCR_PLT_Minus256_Pos) /*!< 0x00000030 */
#define ETH_MACFCR_PLT_Minus256                       ETH_MACFCR_PLT_Minus256_Msk /* Pause time minus 256 slot times */
#define ETH_MACFCR_UPFD_Pos                           (3U)                     
#define ETH_MACFCR_UPFD_Msk                           (0x1UL << ETH_MACFCR_UPFD_Pos) /*!< 0x00000008 */
#define ETH_MACFCR_UPFD                               ETH_MACFCR_UPFD_Msk      /* Unicast pause frame detect */
#define ETH_MACFCR_RFCE_Pos                           (2U)                     
#define ETH_MACFCR_RFCE_Msk                           (0x1UL << ETH_MACFCR_RFCE_Pos) /*!< 0x00000004 */
#define ETH_MACFCR_RFCE                               ETH_MACFCR_RFCE_Msk      /* Receive flow control enable */
#define ETH_MACFCR_TFCE_Pos                           (1U)                     
#define ETH_MACFCR_TFCE_Msk                           (0x1UL << ETH_MACFCR_TFCE_Pos) /*!< 0x00000002 */
#define ETH_MACFCR_TFCE                               ETH_MACFCR_TFCE_Msk      /* Transmit flow control enable */
#define ETH_MACFCR_FCBBPA_Pos                         (0U)                     
#define ETH_MACFCR_FCBBPA_Msk                         (0x1UL << ETH_MACFCR_FCBBPA_Pos) /*!< 0x00000001 */
#define ETH_MACFCR_FCBBPA                             ETH_MACFCR_FCBBPA_Msk    /* Flow control busy/backpressure activate */

/* Bit definition for Ethernet MAC VLAN Tag Register */
#define ETH_MACVLANTR_VLANTC_Pos                      (16U)                    
#define ETH_MACVLANTR_VLANTC_Msk                      (0x1UL << ETH_MACVLANTR_VLANTC_Pos) /*!< 0x00010000 */
#define ETH_MACVLANTR_VLANTC                          ETH_MACVLANTR_VLANTC_Msk /* 12-bit VLAN tag comparison */
#define ETH_MACVLANTR_VLANTI_Pos                      (0U)                     
#define ETH_MACVLANTR_VLANTI_Msk                      (0xFFFFUL << ETH_MACVLANTR_VLANTI_Pos) /*!< 0x0000FFFF */
#define ETH_MACVLANTR_VLANTI                          ETH_MACVLANTR_VLANTI_Msk /* VLAN tag identifier (for receive frames) */

/* Bit definition for Ethernet MAC Remote Wake-UpFrame Filter Register */ 
#define ETH_MACRWUFFR_D_Pos                           (0U)                     
#define ETH_MACRWUFFR_D_Msk                           (0xFFFFFFFFUL << ETH_MACRWUFFR_D_Pos) /*!< 0xFFFFFFFF */
#define ETH_MACRWUFFR_D                               ETH_MACRWUFFR_D_Msk      /* Wake-up frame filter register data */
/* Eight sequential Writes to this address (offset 0x28) will write all Wake-UpFrame Filter Registers.
   Eight sequential Reads from this address (offset 0x28) will read all Wake-UpFrame Filter Registers. */
/* Wake-UpFrame Filter Reg0 : Filter 0 Byte Mask
   Wake-UpFrame Filter Reg1 : Filter 1 Byte Mask
   Wake-UpFrame Filter Reg2 : Filter 2 Byte Mask
   Wake-UpFrame Filter Reg3 : Filter 3 Byte Mask
   Wake-UpFrame Filter Reg4 : RSVD - Filter3 Command - RSVD - Filter2 Command - 
                              RSVD - Filter1 Command - RSVD - Filter0 Command
   Wake-UpFrame Filter Re5 : Filter3 Offset - Filter2 Offset - Filter1 Offset - Filter0 Offset
   Wake-UpFrame Filter Re6 : Filter1 CRC16 - Filter0 CRC16
   Wake-UpFrame Filter Re7 : Filter3 CRC16 - Filter2 CRC16 */

/* Bit definition for Ethernet MAC PMT Control and Status Register */ 
#define ETH_MACPMTCSR_WFFRPR_Pos                      (31U)                    
#define ETH_MACPMTCSR_WFFRPR_Msk                      (0x1UL << ETH_MACPMTCSR_WFFRPR_Pos) /*!< 0x80000000 */
#define ETH_MACPMTCSR_WFFRPR                          ETH_MACPMTCSR_WFFRPR_Msk /* Wake-Up Frame Filter Register Pointer Reset */
#define ETH_MACPMTCSR_GU_Pos                          (9U)                     
#define ETH_MACPMTCSR_GU_Msk                          (0x1UL << ETH_MACPMTCSR_GU_Pos) /*!< 0x00000200 */
#define ETH_MACPMTCSR_GU                              ETH_MACPMTCSR_GU_Msk     /* Global Unicast                              */
#define ETH_MACPMTCSR_WFR_Pos                         (6U)                     
#define ETH_MACPMTCSR_WFR_Msk                         (0x1UL << ETH_MACPMTCSR_WFR_Pos) /*!< 0x00000040 */
#define ETH_MACPMTCSR_WFR                             ETH_MACPMTCSR_WFR_Msk    /* Wake-Up Frame Received                      */
#define ETH_MACPMTCSR_MPR_Pos                         (5U)                     
#define ETH_MACPMTCSR_MPR_Msk                         (0x1UL << ETH_MACPMTCSR_MPR_Pos) /*!< 0x00000020 */
#define ETH_MACPMTCSR_MPR                             ETH_MACPMTCSR_MPR_Msk    /* Magic Packet Received                       */
#define ETH_MACPMTCSR_WFE_Pos                         (2U)                     
#define ETH_MACPMTCSR_WFE_Msk                         (0x1UL << ETH_MACPMTCSR_WFE_Pos) /*!< 0x00000004 */
#define ETH_MACPMTCSR_WFE                             ETH_MACPMTCSR_WFE_Msk    /* Wake-Up Frame Enable                        */
#define ETH_MACPMTCSR_MPE_Pos                         (1U)                     
#define ETH_MACPMTCSR_MPE_Msk                         (0x1UL << ETH_MACPMTCSR_MPE_Pos) /*!< 0x00000002 */
#define ETH_MACPMTCSR_MPE                             ETH_MACPMTCSR_MPE_Msk    /* Magic Packet Enable                         */
#define ETH_MACPMTCSR_PD_Pos                          (0U)                     
#define ETH_MACPMTCSR_PD_Msk                          (0x1UL << ETH_MACPMTCSR_PD_Pos) /*!< 0x00000001 */
#define ETH_MACPMTCSR_PD                              ETH_MACPMTCSR_PD_Msk     /* Power Down                                  */

/* Bit definition for Ethernet MAC debug Register */
#define ETH_MACDBGR_TFF_Pos                           (25U)                    
#define ETH_MACDBGR_TFF_Msk                           (0x1UL << ETH_MACDBGR_TFF_Pos) /*!< 0x02000000 */
#define ETH_MACDBGR_TFF                               ETH_MACDBGR_TFF_Msk      /* Tx FIFO full                                                            */
#define ETH_MACDBGR_TFNE_Pos                          (24U)                    
#define ETH_MACDBGR_TFNE_Msk                          (0x1UL << ETH_MACDBGR_TFNE_Pos) /*!< 0x01000000 */
#define ETH_MACDBGR_TFNE                              ETH_MACDBGR_TFNE_Msk     /* Tx FIFO not empty                                                       */
#define ETH_MACDBGR_TFWA_Pos                          (22U)                    
#define ETH_MACDBGR_TFWA_Msk                          (0x1UL << ETH_MACDBGR_TFWA_Pos) /*!< 0x00400000 */
#define ETH_MACDBGR_TFWA                              ETH_MACDBGR_TFWA_Msk     /* Tx FIFO write active                                                    */
#define ETH_MACDBGR_TFRS_Pos                          (20U)                    
#define ETH_MACDBGR_TFRS_Msk                          (0x3UL << ETH_MACDBGR_TFRS_Pos) /*!< 0x00300000 */
#define ETH_MACDBGR_TFRS                              ETH_MACDBGR_TFRS_Msk     /* Tx FIFO read status mask                                                */
#define ETH_MACDBGR_TFRS_WRITING_Pos                  (20U)                    
#define ETH_MACDBGR_TFRS_WRITING_Msk                  (0x3UL << ETH_MACDBGR_TFRS_WRITING_Pos) /*!< 0x00300000 */
#define ETH_MACDBGR_TFRS_WRITING                      ETH_MACDBGR_TFRS_WRITING_Msk /* Writing the received TxStatus or flushing the TxFIFO                    */
#define ETH_MACDBGR_TFRS_WAITING_Pos                  (21U)                    
#define ETH_MACDBGR_TFRS_WAITING_Msk                  (0x1UL << ETH_MACDBGR_TFRS_WAITING_Pos) /*!< 0x00200000 */
#define ETH_MACDBGR_TFRS_WAITING                      ETH_MACDBGR_TFRS_WAITING_Msk /* Waiting for TxStatus from MAC transmitter                               */
#define ETH_MACDBGR_TFRS_READ_Pos                     (20U)                    
#define ETH_MACDBGR_TFRS_READ_Msk                     (0x1UL << ETH_MACDBGR_TFRS_READ_Pos) /*!< 0x00100000 */
#define ETH_MACDBGR_TFRS_READ                         ETH_MACDBGR_TFRS_READ_Msk /* Read state (transferring data to the MAC transmitter)                   */
#define ETH_MACDBGR_TFRS_IDLE                         0x00000000U              /* Idle state                                                              */
#define ETH_MACDBGR_MTP_Pos                           (19U)                    
#define ETH_MACDBGR_MTP_Msk                           (0x1UL << ETH_MACDBGR_MTP_Pos) /*!< 0x00080000 */
#define ETH_MACDBGR_MTP                               ETH_MACDBGR_MTP_Msk      /* MAC transmitter in pause                                                */
#define ETH_MACDBGR_MTFCS_Pos                         (17U)                    
#define ETH_MACDBGR_MTFCS_Msk                         (0x3UL << ETH_MACDBGR_MTFCS_Pos) /*!< 0x00060000 */
#define ETH_MACDBGR_MTFCS                             ETH_MACDBGR_MTFCS_Msk    /* MAC transmit frame controller status mask                               */
#define ETH_MACDBGR_MTFCS_TRANSFERRING_Pos            (17U)                    
#define ETH_MACDBGR_MTFCS_TRANSFERRING_Msk            (0x3UL << ETH_MACDBGR_MTFCS_TRANSFERRING_Pos) /*!< 0x00060000 */
#define ETH_MACDBGR_MTFCS_TRANSFERRING                ETH_MACDBGR_MTFCS_TRANSFERRING_Msk /* Transferring input frame for transmission                               */
#define ETH_MACDBGR_MTFCS_GENERATINGPCF_Pos           (18U)                    
#define ETH_MACDBGR_MTFCS_GENERATINGPCF_Msk           (0x1UL << ETH_MACDBGR_MTFCS_GENERATINGPCF_Pos) /*!< 0x00040000 */
#define ETH_MACDBGR_MTFCS_GENERATINGPCF               ETH_MACDBGR_MTFCS_GENERATINGPCF_Msk /* Generating and transmitting a Pause control frame (in full duplex mode) */
#define ETH_MACDBGR_MTFCS_WAITING_Pos                 (17U)                    
#define ETH_MACDBGR_MTFCS_WAITING_Msk                 (0x1UL << ETH_MACDBGR_MTFCS_WAITING_Pos) /*!< 0x00020000 */
#define ETH_MACDBGR_MTFCS_WAITING                     ETH_MACDBGR_MTFCS_WAITING_Msk /* Waiting for Status of previous frame or IFG/backoff period to be over   */
#define ETH_MACDBGR_MTFCS_IDLE                        0x00000000U              /* Idle                                                                    */
#define ETH_MACDBGR_MMTEA_Pos                         (16U)                    
#define ETH_MACDBGR_MMTEA_Msk                         (0x1UL << ETH_MACDBGR_MMTEA_Pos) /*!< 0x00010000 */
#define ETH_MACDBGR_MMTEA                             ETH_MACDBGR_MMTEA_Msk    /* MAC MII transmit engine active                                          */
#define ETH_MACDBGR_RFFL_Pos                          (8U)                     
#define ETH_MACDBGR_RFFL_Msk                          (0x3UL << ETH_MACDBGR_RFFL_Pos) /*!< 0x00000300 */
#define ETH_MACDBGR_RFFL                              ETH_MACDBGR_RFFL_Msk     /* Rx FIFO fill level mask                                                 */
#define ETH_MACDBGR_RFFL_FULL_Pos                     (8U)                     
#define ETH_MACDBGR_RFFL_FULL_Msk                     (0x3UL << ETH_MACDBGR_RFFL_FULL_Pos) /*!< 0x00000300 */
#define ETH_MACDBGR_RFFL_FULL                         ETH_MACDBGR_RFFL_FULL_Msk /* RxFIFO full                                                             */
#define ETH_MACDBGR_RFFL_ABOVEFCT_Pos                 (9U)                     
#define ETH_MACDBGR_RFFL_ABOVEFCT_Msk                 (0x1UL << ETH_MACDBGR_RFFL_ABOVEFCT_Pos) /*!< 0x00000200 */
#define ETH_MACDBGR_RFFL_ABOVEFCT                     ETH_MACDBGR_RFFL_ABOVEFCT_Msk /* RxFIFO fill-level above flow-control activate threshold                 */
#define ETH_MACDBGR_RFFL_BELOWFCT_Pos                 (8U)                     
#define ETH_MACDBGR_RFFL_BELOWFCT_Msk                 (0x1UL << ETH_MACDBGR_RFFL_BELOWFCT_Pos) /*!< 0x00000100 */
#define ETH_MACDBGR_RFFL_BELOWFCT                     ETH_MACDBGR_RFFL_BELOWFCT_Msk /* RxFIFO fill-level below flow-control de-activate threshold              */
#define ETH_MACDBGR_RFFL_EMPTY                        0x00000000U              /* RxFIFO empty                                                            */
#define ETH_MACDBGR_RFRCS_Pos                         (5U)                     
#define ETH_MACDBGR_RFRCS_Msk                         (0x3UL << ETH_MACDBGR_RFRCS_Pos) /*!< 0x00000060 */
#define ETH_MACDBGR_RFRCS                             ETH_MACDBGR_RFRCS_Msk    /* Rx FIFO read controller status mask                                     */
#define ETH_MACDBGR_RFRCS_FLUSHING_Pos                (5U)                     
#define ETH_MACDBGR_RFRCS_FLUSHING_Msk                (0x3UL << ETH_MACDBGR_RFRCS_FLUSHING_Pos) /*!< 0x00000060 */
#define ETH_MACDBGR_RFRCS_FLUSHING                    ETH_MACDBGR_RFRCS_FLUSHING_Msk /* Flushing the frame data and status                                      */
#define ETH_MACDBGR_RFRCS_STATUSREADING_Pos           (6U)                     
#define ETH_MACDBGR_RFRCS_STATUSREADING_Msk           (0x1UL << ETH_MACDBGR_RFRCS_STATUSREADING_Pos) /*!< 0x00000040 */
#define ETH_MACDBGR_RFRCS_STATUSREADING               ETH_MACDBGR_RFRCS_STATUSREADING_Msk /* Reading frame status (or time-stamp)                                    */
#define ETH_MACDBGR_RFRCS_DATAREADING_Pos             (5U)                     
#define ETH_MACDBGR_RFRCS_DATAREADING_Msk             (0x1UL << ETH_MACDBGR_RFRCS_DATAREADING_Pos) /*!< 0x00000020 */
#define ETH_MACDBGR_RFRCS_DATAREADING                 ETH_MACDBGR_RFRCS_DATAREADING_Msk /* Reading frame data                                                      */
#define ETH_MACDBGR_RFRCS_IDLE                        0x00000000U              /* IDLE state                                                              */
#define ETH_MACDBGR_RFWRA_Pos                         (4U)                     
#define ETH_MACDBGR_RFWRA_Msk                         (0x1UL << ETH_MACDBGR_RFWRA_Pos) /*!< 0x00000010 */
#define ETH_MACDBGR_RFWRA                             ETH_MACDBGR_RFWRA_Msk    /* Rx FIFO write controller active                                         */
#define ETH_MACDBGR_MSFRWCS_Pos                       (1U)                     
#define ETH_MACDBGR_MSFRWCS_Msk                       (0x3UL << ETH_MACDBGR_MSFRWCS_Pos) /*!< 0x00000006 */
#define ETH_MACDBGR_MSFRWCS                           ETH_MACDBGR_MSFRWCS_Msk  /* MAC small FIFO read / write controllers status  mask                    */
#define ETH_MACDBGR_MSFRWCS_1                         (0x2UL << ETH_MACDBGR_MSFRWCS_Pos) /*!< 0x00000004 */
#define ETH_MACDBGR_MSFRWCS_0                         (0x1UL << ETH_MACDBGR_MSFRWCS_Pos) /*!< 0x00000002 */
#define ETH_MACDBGR_MMRPEA_Pos                        (0U)                     
#define ETH_MACDBGR_MMRPEA_Msk                        (0x1UL << ETH_MACDBGR_MMRPEA_Pos) /*!< 0x00000001 */
#define ETH_MACDBGR_MMRPEA                            ETH_MACDBGR_MMRPEA_Msk   /* MAC MII receive protocol engine active                                  */

/* Bit definition for Ethernet MAC Status Register */
#define ETH_MACSR_TSTS_Pos                            (9U)                     
#define ETH_MACSR_TSTS_Msk                            (0x1UL << ETH_MACSR_TSTS_Pos) /*!< 0x00000200 */
#define ETH_MACSR_TSTS                                ETH_MACSR_TSTS_Msk       /* Time stamp trigger status */
#define ETH_MACSR_MMCTS_Pos                           (6U)                     
#define ETH_MACSR_MMCTS_Msk                           (0x1UL << ETH_MACSR_MMCTS_Pos) /*!< 0x00000040 */
#define ETH_MACSR_MMCTS                               ETH_MACSR_MMCTS_Msk      /* MMC transmit status       */
#define ETH_MACSR_MMMCRS_Pos                          (5U)                     
#define ETH_MACSR_MMMCRS_Msk                          (0x1UL << ETH_MACSR_MMMCRS_Pos) /*!< 0x00000020 */
#define ETH_MACSR_MMMCRS                              ETH_MACSR_MMMCRS_Msk     /* MMC receive status        */
#define ETH_MACSR_MMCS_Pos                            (4U)                     
#define ETH_MACSR_MMCS_Msk                            (0x1UL << ETH_MACSR_MMCS_Pos) /*!< 0x00000010 */
#define ETH_MACSR_MMCS                                ETH_MACSR_MMCS_Msk       /* MMC status                */
#define ETH_MACSR_PMTS_Pos                            (3U)                     
#define ETH_MACSR_PMTS_Msk                            (0x1UL << ETH_MACSR_PMTS_Pos) /*!< 0x00000008 */
#define ETH_MACSR_PMTS                                ETH_MACSR_PMTS_Msk       /* PMT status                */

/* Bit definition for Ethernet MAC Interrupt Mask Register */
#define ETH_MACIMR_TSTIM_Pos                          (9U)                     
#define ETH_MACIMR_TSTIM_Msk                          (0x1UL << ETH_MACIMR_TSTIM_Pos) /*!< 0x00000200 */
#define ETH_MACIMR_TSTIM                              ETH_MACIMR_TSTIM_Msk     /* Time stamp trigger interrupt mask */
#define ETH_MACIMR_PMTIM_Pos                          (3U)                     
#define ETH_MACIMR_PMTIM_Msk                          (0x1UL << ETH_MACIMR_PMTIM_Pos) /*!< 0x00000008 */
#define ETH_MACIMR_PMTIM                              ETH_MACIMR_PMTIM_Msk     /* PMT interrupt mask                */

/* Bit definition for Ethernet MAC Address0 High Register */
#define ETH_MACA0HR_MACA0H_Pos                        (0U)                     
#define ETH_MACA0HR_MACA0H_Msk                        (0xFFFFUL << ETH_MACA0HR_MACA0H_Pos) /*!< 0x0000FFFF */
#define ETH_MACA0HR_MACA0H                            ETH_MACA0HR_MACA0H_Msk   /* MAC address0 high */

/* Bit definition for Ethernet MAC Address0 Low Register */
#define ETH_MACA0LR_MACA0L_Pos                        (0U)                     
#define ETH_MACA0LR_MACA0L_Msk                        (0xFFFFFFFFUL << ETH_MACA0LR_MACA0L_Pos) /*!< 0xFFFFFFFF */
#define ETH_MACA0LR_MACA0L                            ETH_MACA0LR_MACA0L_Msk   /* MAC address0 low */

/* Bit definition for Ethernet MAC Address1 High Register */
#define ETH_MACA1HR_AE_Pos                            (31U)                    
#define ETH_MACA1HR_AE_Msk                            (0x1UL << ETH_MACA1HR_AE_Pos) /*!< 0x80000000 */
#define ETH_MACA1HR_AE                                ETH_MACA1HR_AE_Msk       /* Address enable */
#define ETH_MACA1HR_SA_Pos                            (30U)                    
#define ETH_MACA1HR_SA_Msk                            (0x1UL << ETH_MACA1HR_SA_Pos) /*!< 0x40000000 */
#define ETH_MACA1HR_SA                                ETH_MACA1HR_SA_Msk       /* Source address */
#define ETH_MACA1HR_MBC_Pos                           (24U)                    
#define ETH_MACA1HR_MBC_Msk                           (0x3FUL << ETH_MACA1HR_MBC_Pos) /*!< 0x3F000000 */
#define ETH_MACA1HR_MBC                               ETH_MACA1HR_MBC_Msk      /* Mask byte control: bits to mask for comparison of the MAC Address bytes */
#define ETH_MACA1HR_MBC_HBits15_8                     0x20000000U              /* Mask MAC Address high reg bits [15:8] */
#define ETH_MACA1HR_MBC_HBits7_0                      0x10000000U              /* Mask MAC Address high reg bits [7:0]  */
#define ETH_MACA1HR_MBC_LBits31_24                    0x08000000U              /* Mask MAC Address low reg bits [31:24] */
#define ETH_MACA1HR_MBC_LBits23_16                    0x04000000U              /* Mask MAC Address low reg bits [23:16] */
#define ETH_MACA1HR_MBC_LBits15_8                     0x02000000U              /* Mask MAC Address low reg bits [15:8]  */
#define ETH_MACA1HR_MBC_LBits7_0                      0x01000000U              /* Mask MAC Address low reg bits [7:0]   */
#define ETH_MACA1HR_MACA1H_Pos                        (0U)                     
#define ETH_MACA1HR_MACA1H_Msk                        (0xFFFFUL << ETH_MACA1HR_MACA1H_Pos) /*!< 0x0000FFFF */
#define ETH_MACA1HR_MACA1H                            ETH_MACA1HR_MACA1H_Msk   /* MAC address1 high */

/* Bit definition for Ethernet MAC Address1 Low Register */
#define ETH_MACA1LR_MACA1L_Pos                        (0U)                     
#define ETH_MACA1LR_MACA1L_Msk                        (0xFFFFFFFFUL << ETH_MACA1LR_MACA1L_Pos) /*!< 0xFFFFFFFF */
#define ETH_MACA1LR_MACA1L                            ETH_MACA1LR_MACA1L_Msk   /* MAC address1 low */

/* Bit definition for Ethernet MAC Address2 High Register */
#define ETH_MACA2HR_AE_Pos                            (31U)                    
#define ETH_MACA2HR_AE_Msk                            (0x1UL << ETH_MACA2HR_AE_Pos) /*!< 0x80000000 */
#define ETH_MACA2HR_AE                                ETH_MACA2HR_AE_Msk       /* Address enable */
#define ETH_MACA2HR_SA_Pos                            (30U)                    
#define ETH_MACA2HR_SA_Msk                            (0x1UL << ETH_MACA2HR_SA_Pos) /*!< 0x40000000 */
#define ETH_MACA2HR_SA                                ETH_MACA2HR_SA_Msk       /* Source address */
#define ETH_MACA2HR_MBC_Pos                           (24U)                    
#define ETH_MACA2HR_MBC_Msk                           (0x3FUL << ETH_MACA2HR_MBC_Pos) /*!< 0x3F000000 */
#define ETH_MACA2HR_MBC                               ETH_MACA2HR_MBC_Msk      /* Mask byte control */
#define ETH_MACA2HR_MBC_HBits15_8                     0x20000000U              /* Mask MAC Address high reg bits [15:8] */
#define ETH_MACA2HR_MBC_HBits7_0                      0x10000000U              /* Mask MAC Address high reg bits [7:0]  */
#define ETH_MACA2HR_MBC_LBits31_24                    0x08000000U              /* Mask MAC Address low reg bits [31:24] */
#define ETH_MACA2HR_MBC_LBits23_16                    0x04000000U              /* Mask MAC Address low reg bits [23:16] */
#define ETH_MACA2HR_MBC_LBits15_8                     0x02000000U              /* Mask MAC Address low reg bits [15:8]  */
#define ETH_MACA2HR_MBC_LBits7_0                      0x01000000U              /* Mask MAC Address low reg bits [70]    */
#define ETH_MACA2HR_MACA2H_Pos                        (0U)                     
#define ETH_MACA2HR_MACA2H_Msk                        (0xFFFFUL << ETH_MACA2HR_MACA2H_Pos) /*!< 0x0000FFFF */
#define ETH_MACA2HR_MACA2H                            ETH_MACA2HR_MACA2H_Msk   /* MAC address1 high */

/* Bit definition for Ethernet MAC Address2 Low Register */
#define ETH_MACA2LR_MACA2L_Pos                        (0U)                     
#define ETH_MACA2LR_MACA2L_Msk                        (0xFFFFFFFFUL << ETH_MACA2LR_MACA2L_Pos) /*!< 0xFFFFFFFF */
#define ETH_MACA2LR_MACA2L                            ETH_MACA2LR_MACA2L_Msk   /* MAC address2 low */

/* Bit definition for Ethernet MAC Address3 High Register */
#define ETH_MACA3HR_AE_Pos                            (31U)                    
#define ETH_MACA3HR_AE_Msk                            (0x1UL << ETH_MACA3HR_AE_Pos) /*!< 0x80000000 */
#define ETH_MACA3HR_AE                                ETH_MACA3HR_AE_Msk       /* Address enable */
#define ETH_MACA3HR_SA_Pos                            (30U)                    
#define ETH_MACA3HR_SA_Msk                            (0x1UL << ETH_MACA3HR_SA_Pos) /*!< 0x40000000 */
#define ETH_MACA3HR_SA                                ETH_MACA3HR_SA_Msk       /* Source address */
#define ETH_MACA3HR_MBC_Pos                           (24U)                    
#define ETH_MACA3HR_MBC_Msk                           (0x3FUL << ETH_MACA3HR_MBC_Pos) /*!< 0x3F000000 */
#define ETH_MACA3HR_MBC                               ETH_MACA3HR_MBC_Msk      /* Mask byte control */
#define ETH_MACA3HR_MBC_HBits15_8                     0x20000000U              /* Mask MAC Address high reg bits [15:8] */
#define ETH_MACA3HR_MBC_HBits7_0                      0x10000000U              /* Mask MAC Address high reg bits [7:0]  */
#define ETH_MACA3HR_MBC_LBits31_24                    0x08000000U              /* Mask MAC Address low reg bits [31:24] */
#define ETH_MACA3HR_MBC_LBits23_16                    0x04000000U              /* Mask MAC Address low reg bits [23:16] */
#define ETH_MACA3HR_MBC_LBits15_8                     0x02000000U              /* Mask MAC Address low reg bits [15:8]  */
#define ETH_MACA3HR_MBC_LBits7_0                      0x01000000U              /* Mask MAC Address low reg bits [70]    */
#define ETH_MACA3HR_MACA3H_Pos                        (0U)                     
#define ETH_MACA3HR_MACA3H_Msk                        (0xFFFFUL << ETH_MACA3HR_MACA3H_Pos) /*!< 0x0000FFFF */
#define ETH_MACA3HR_MACA3H                            ETH_MACA3HR_MACA3H_Msk   /* MAC address3 high */

/* Bit definition for Ethernet MAC Address3 Low Register */
#define ETH_MACA3LR_MACA3L_Pos                        (0U)                     
#define ETH_MACA3LR_MACA3L_Msk                        (0xFFFFFFFFUL << ETH_MACA3LR_MACA3L_Pos) /*!< 0xFFFFFFFF */
#define ETH_MACA3LR_MACA3L                            ETH_MACA3LR_MACA3L_Msk   /* MAC address3 low */

/******************************************************************************/
/*                Ethernet MMC Registers bits definition                      */
/******************************************************************************/

/* Bit definition for Ethernet MMC Contol Register */
#define ETH_MMCCR_MCFHP_Pos                           (5U)                     
#define ETH_MMCCR_MCFHP_Msk                           (0x1UL << ETH_MMCCR_MCFHP_Pos) /*!< 0x00000020 */
#define ETH_MMCCR_MCFHP                               ETH_MMCCR_MCFHP_Msk      /* MMC counter Full-Half preset */
#define ETH_MMCCR_MCP_Pos                             (4U)                     
#define ETH_MMCCR_MCP_Msk                             (0x1UL << ETH_MMCCR_MCP_Pos) /*!< 0x00000010 */
#define ETH_MMCCR_MCP                                 ETH_MMCCR_MCP_Msk        /* MMC counter preset           */
#define ETH_MMCCR_MCF_Pos                             (3U)                     
#define ETH_MMCCR_MCF_Msk                             (0x1UL << ETH_MMCCR_MCF_Pos) /*!< 0x00000008 */
#define ETH_MMCCR_MCF                                 ETH_MMCCR_MCF_Msk        /* MMC Counter Freeze           */
#define ETH_MMCCR_ROR_Pos                             (2U)                     
#define ETH_MMCCR_ROR_Msk                             (0x1UL << ETH_MMCCR_ROR_Pos) /*!< 0x00000004 */
#define ETH_MMCCR_ROR                                 ETH_MMCCR_ROR_Msk        /* Reset on Read                */
#define ETH_MMCCR_CSR_Pos                             (1U)                     
#define ETH_MMCCR_CSR_Msk                             (0x1UL << ETH_MMCCR_CSR_Pos) /*!< 0x00000002 */
#define ETH_MMCCR_CSR                                 ETH_MMCCR_CSR_Msk        /* Counter Stop Rollover        */
#define ETH_MMCCR_CR_Pos                              (0U)                     
#define ETH_MMCCR_CR_Msk                              (0x1UL << ETH_MMCCR_CR_Pos) /*!< 0x00000001 */
#define ETH_MMCCR_CR                                  ETH_MMCCR_CR_Msk         /* Counters Reset               */

/* Bit definition for Ethernet MMC Receive Interrupt Register */
#define ETH_MMCRIR_RGUFS_Pos                          (17U)                    
#define ETH_MMCRIR_RGUFS_Msk                          (0x1UL << ETH_MMCRIR_RGUFS_Pos) /*!< 0x00020000 */
#define ETH_MMCRIR_RGUFS                              ETH_MMCRIR_RGUFS_Msk     /* Set when Rx good unicast frames counter reaches half the maximum value */
#define ETH_MMCRIR_RFAES_Pos                          (6U)                     
#define ETH_MMCRIR_RFAES_Msk                          (0x1UL << ETH_MMCRIR_RFAES_Pos) /*!< 0x00000040 */
#define ETH_MMCRIR_RFAES                              ETH_MMCRIR_RFAES_Msk     /* Set when Rx alignment error counter reaches half the maximum value */
#define ETH_MMCRIR_RFCES_Pos                          (5U)                     
#define ETH_MMCRIR_RFCES_Msk                          (0x1UL << ETH_MMCRIR_RFCES_Pos) /*!< 0x00000020 */
#define ETH_MMCRIR_RFCES                              ETH_MMCRIR_RFCES_Msk     /* Set when Rx crc error counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmit Interrupt Register */
#define ETH_MMCTIR_TGFS_Pos                           (21U)                    
#define ETH_MMCTIR_TGFS_Msk                           (0x1UL << ETH_MMCTIR_TGFS_Pos) /*!< 0x00200000 */
#define ETH_MMCTIR_TGFS                               ETH_MMCTIR_TGFS_Msk      /* Set when Tx good frame count counter reaches half the maximum value */
#define ETH_MMCTIR_TGFMSCS_Pos                        (15U)                    
#define ETH_MMCTIR_TGFMSCS_Msk                        (0x1UL << ETH_MMCTIR_TGFMSCS_Pos) /*!< 0x00008000 */
#define ETH_MMCTIR_TGFMSCS                            ETH_MMCTIR_TGFMSCS_Msk   /* Set when Tx good multi col counter reaches half the maximum value */
#define ETH_MMCTIR_TGFSCS_Pos                         (14U)                    
#define ETH_MMCTIR_TGFSCS_Msk                         (0x1UL << ETH_MMCTIR_TGFSCS_Pos) /*!< 0x00004000 */
#define ETH_MMCTIR_TGFSCS                             ETH_MMCTIR_TGFSCS_Msk    /* Set when Tx good single col counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Receive Interrupt Mask Register */
#define ETH_MMCRIMR_RGUFM_Pos                         (17U)                    
#define ETH_MMCRIMR_RGUFM_Msk                         (0x1UL << ETH_MMCRIMR_RGUFM_Pos) /*!< 0x00020000 */
#define ETH_MMCRIMR_RGUFM                             ETH_MMCRIMR_RGUFM_Msk    /* Mask the interrupt when Rx good unicast frames counter reaches half the maximum value */
#define ETH_MMCRIMR_RFAEM_Pos                         (6U)                     
#define ETH_MMCRIMR_RFAEM_Msk                         (0x1UL << ETH_MMCRIMR_RFAEM_Pos) /*!< 0x00000040 */
#define ETH_MMCRIMR_RFAEM                             ETH_MMCRIMR_RFAEM_Msk    /* Mask the interrupt when when Rx alignment error counter reaches half the maximum value */
#define ETH_MMCRIMR_RFCEM_Pos                         (5U)                     
#define ETH_MMCRIMR_RFCEM_Msk                         (0x1UL << ETH_MMCRIMR_RFCEM_Pos) /*!< 0x00000020 */
#define ETH_MMCRIMR_RFCEM                             ETH_MMCRIMR_RFCEM_Msk    /* Mask the interrupt when Rx crc error counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmit Interrupt Mask Register */
#define ETH_MMCTIMR_TGFM_Pos                          (21U)                    
#define ETH_MMCTIMR_TGFM_Msk                          (0x1UL << ETH_MMCTIMR_TGFM_Pos) /*!< 0x00200000 */
#define ETH_MMCTIMR_TGFM                              ETH_MMCTIMR_TGFM_Msk     /* Mask the interrupt when Tx good frame count counter reaches half the maximum value */
#define ETH_MMCTIMR_TGFMSCM_Pos                       (15U)                    
#define ETH_MMCTIMR_TGFMSCM_Msk                       (0x1UL << ETH_MMCTIMR_TGFMSCM_Pos) /*!< 0x00008000 */
#define ETH_MMCTIMR_TGFMSCM                           ETH_MMCTIMR_TGFMSCM_Msk  /* Mask the interrupt when Tx good multi col counter reaches half the maximum value */
#define ETH_MMCTIMR_TGFSCM_Pos                        (14U)                    
#define ETH_MMCTIMR_TGFSCM_Msk                        (0x1UL << ETH_MMCTIMR_TGFSCM_Pos) /*!< 0x00004000 */
#define ETH_MMCTIMR_TGFSCM                            ETH_MMCTIMR_TGFSCM_Msk   /* Mask the interrupt when Tx good single col counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmitted Good Frames after Single Collision Counter Register */
#define ETH_MMCTGFSCCR_TGFSCC_Pos                     (0U)                     
#define ETH_MMCTGFSCCR_TGFSCC_Msk                     (0xFFFFFFFFUL << ETH_MMCTGFSCCR_TGFSCC_Pos) /*!< 0xFFFFFFFF */
#define ETH_MMCTGFSCCR_TGFSCC                         ETH_MMCTGFSCCR_TGFSCC_Msk /* Number of successfully transmitted frames after a single collision in Half-duplex mode. */

/* Bit definition for Ethernet MMC Transmitted Good Frames after More than a Single Collision Counter Register */
#define ETH_MMCTGFMSCCR_TGFMSCC_Pos                   (0U)                     
#define ETH_MMCTGFMSCCR_TGFMSCC_Msk                   (0xFFFFFFFFUL << ETH_MMCTGFMSCCR_TGFMSCC_Pos) /*!< 0xFFFFFFFF */
#define ETH_MMCTGFMSCCR_TGFMSCC                       ETH_MMCTGFMSCCR_TGFMSCC_Msk /* Number of successfully transmitted frames after more than a single collision in Half-duplex mode. */

/* Bit definition for Ethernet MMC Transmitted Good Frames Counter Register */
#define ETH_MMCTGFCR_TGFC_Pos                         (0U)                     
#define ETH_MMCTGFCR_TGFC_Msk                         (0xFFFFFFFFUL << ETH_MMCTGFCR_TGFC_Pos) /*!< 0xFFFFFFFF */
#define ETH_MMCTGFCR_TGFC                             ETH_MMCTGFCR_TGFC_Msk    /* Number of good frames transmitted. */

/* Bit definition for Ethernet MMC Received Frames with CRC Error Counter Register */
#define ETH_MMCRFCECR_RFCEC_Pos                       (0U)                     
#define ETH_MMCRFCECR_RFCEC_Msk                       (0xFFFFFFFFUL << ETH_MMCRFCECR_RFCEC_Pos) /*!< 0xFFFFFFFF */
#define ETH_MMCRFCECR_RFCEC                           ETH_MMCRFCECR_RFCEC_Msk  /* Number of frames received with CRC error. */

/* Bit definition for Ethernet MMC Received Frames with Alignement Error Counter Register */
#define ETH_MMCRFAECR_RFAEC_Pos                       (0U)                     
#define ETH_MMCRFAECR_RFAEC_Msk                       (0xFFFFFFFFUL << ETH_MMCRFAECR_RFAEC_Pos) /*!< 0xFFFFFFFF */
#define ETH_MMCRFAECR_RFAEC                           ETH_MMCRFAECR_RFAEC_Msk  /* Number of frames received with alignment (dribble) error */

/* Bit definition for Ethernet MMC Received Good Unicast Frames Counter Register */
#define ETH_MMCRGUFCR_RGUFC_Pos                       (0U)                     
#define ETH_MMCRGUFCR_RGUFC_Msk                       (0xFFFFFFFFUL << ETH_MMCRGUFCR_RGUFC_Pos) /*!< 0xFFFFFFFF */
#define ETH_MMCRGUFCR_RGUFC                           ETH_MMCRGUFCR_RGUFC_Msk  /* Number of good unicast frames received. */

/******************************************************************************/
/*               Ethernet PTP Registers bits definition                       */
/******************************************************************************/

/* Bit definition for Ethernet PTP Time Stamp Contol Register */
#define ETH_PTPTSCR_TSCNT_Pos                         (16U)                    
#define ETH_PTPTSCR_TSCNT_Msk                         (0x3UL << ETH_PTPTSCR_TSCNT_Pos) /*!< 0x00030000 */
#define ETH_PTPTSCR_TSCNT                             ETH_PTPTSCR_TSCNT_Msk    /* Time stamp clock node type */
#define ETH_PTPTSSR_TSSMRME_Pos                       (15U)                    
#define ETH_PTPTSSR_TSSMRME_Msk                       (0x1UL << ETH_PTPTSSR_TSSMRME_Pos) /*!< 0x00008000 */
#define ETH_PTPTSSR_TSSMRME                           ETH_PTPTSSR_TSSMRME_Msk  /* Time stamp snapshot for message relevant to master enable */
#define ETH_PTPTSSR_TSSEME_Pos                        (14U)                    
#define ETH_PTPTSSR_TSSEME_Msk                        (0x1UL << ETH_PTPTSSR_TSSEME_Pos) /*!< 0x00004000 */
#define ETH_PTPTSSR_TSSEME                            ETH_PTPTSSR_TSSEME_Msk   /* Time stamp snapshot for event message enable */
#define ETH_PTPTSSR_TSSIPV4FE_Pos                     (13U)                    
#define ETH_PTPTSSR_TSSIPV4FE_Msk                     (0x1UL << ETH_PTPTSSR_TSSIPV4FE_Pos) /*!< 0x00002000 */
#define ETH_PTPTSSR_TSSIPV4FE                         ETH_PTPTSSR_TSSIPV4FE_Msk /* Time stamp snapshot for IPv4 frames enable */
#define ETH_PTPTSSR_TSSIPV6FE_Pos                     (12U)                    
#define ETH_PTPTSSR_TSSIPV6FE_Msk                     (0x1UL << ETH_PTPTSSR_TSSIPV6FE_Pos) /*!< 0x00001000 */
#define ETH_PTPTSSR_TSSIPV6FE                         ETH_PTPTSSR_TSSIPV6FE_Msk /* Time stamp snapshot for IPv6 frames enable */
#define ETH_PTPTSSR_TSSPTPOEFE_Pos                    (11U)                    
#define ETH_PTPTSSR_TSSPTPOEFE_Msk                    (0x1UL << ETH_PTPTSSR_TSSPTPOEFE_Pos) /*!< 0x00000800 */
#define ETH_PTPTSSR_TSSPTPOEFE                        ETH_PTPTSSR_TSSPTPOEFE_Msk /* Time stamp snapshot for PTP over ethernet frames enable */
#define ETH_PTPTSSR_TSPTPPSV2E_Pos                    (10U)                    
#define ETH_PTPTSSR_TSPTPPSV2E_Msk                    (0x1UL << ETH_PTPTSSR_TSPTPPSV2E_Pos) /*!< 0x00000400 */
#define ETH_PTPTSSR_TSPTPPSV2E                        ETH_PTPTSSR_TSPTPPSV2E_Msk /* Time stamp PTP packet snooping for version2 format enable */
#define ETH_PTPTSSR_TSSSR_Pos                         (9U)                     
#define ETH_PTPTSSR_TSSSR_Msk                         (0x1UL << ETH_PTPTSSR_TSSSR_Pos) /*!< 0x00000200 */
#define ETH_PTPTSSR_TSSSR                             ETH_PTPTSSR_TSSSR_Msk    /* Time stamp Sub-seconds rollover */
#define ETH_PTPTSSR_TSSARFE_Pos                       (8U)                     
#define ETH_PTPTSSR_TSSARFE_Msk                       (0x1UL << ETH_PTPTSSR_TSSARFE_Pos) /*!< 0x00000100 */
#define ETH_PTPTSSR_TSSARFE                           ETH_PTPTSSR_TSSARFE_Msk  /* Time stamp snapshot for all received frames enable */

#define ETH_PTPTSCR_TSARU_Pos                         (5U)                     
#define ETH_PTPTSCR_TSARU_Msk                         (0x1UL << ETH_PTPTSCR_TSARU_Pos) /*!< 0x00000020 */
#define ETH_PTPTSCR_TSARU                             ETH_PTPTSCR_TSARU_Msk    /* Addend register update */
#define ETH_PTPTSCR_TSITE_Pos                         (4U)                     
#define ETH_PTPTSCR_TSITE_Msk                         (0x1UL << ETH_PTPTSCR_TSITE_Pos) /*!< 0x00000010 */
#define ETH_PTPTSCR_TSITE                             ETH_PTPTSCR_TSITE_Msk    /* Time stamp interrupt trigger enable */
#define ETH_PTPTSCR_TSSTU_Pos                         (3U)                     
#define ETH_PTPTSCR_TSSTU_Msk                         (0x1UL << ETH_PTPTSCR_TSSTU_Pos) /*!< 0x00000008 */
#define ETH_PTPTSCR_TSSTU                             ETH_PTPTSCR_TSSTU_Msk    /* Time stamp update */
#define ETH_PTPTSCR_TSSTI_Pos                         (2U)                     
#define ETH_PTPTSCR_TSSTI_Msk                         (0x1UL << ETH_PTPTSCR_TSSTI_Pos) /*!< 0x00000004 */
#define ETH_PTPTSCR_TSSTI                             ETH_PTPTSCR_TSSTI_Msk    /* Time stamp initialize */
#define ETH_PTPTSCR_TSFCU_Pos                         (1U)                     
#define ETH_PTPTSCR_TSFCU_Msk                         (0x1UL << ETH_PTPTSCR_TSFCU_Pos) /*!< 0x00000002 */
#define ETH_PTPTSCR_TSFCU                             ETH_PTPTSCR_TSFCU_Msk    /* Time stamp fine or coarse update */
#define ETH_PTPTSCR_TSE_Pos                           (0U)                     
#define ETH_PTPTSCR_TSE_Msk                           (0x1UL << ETH_PTPTSCR_TSE_Pos) /*!< 0x00000001 */
#define ETH_PTPTSCR_TSE                               ETH_PTPTSCR_TSE_Msk      /* Time stamp enable */

/* Bit definition for Ethernet PTP Sub-Second Increment Register */
#define ETH_PTPSSIR_STSSI_Pos                         (0U)                     
#define ETH_PTPSSIR_STSSI_Msk                         (0xFFUL << ETH_PTPSSIR_STSSI_Pos) /*!< 0x000000FF */
#define ETH_PTPSSIR_STSSI                             ETH_PTPSSIR_STSSI_Msk    /* System time Sub-second increment value */

/* Bit definition for Ethernet PTP Time Stamp High Register */
#define ETH_PTPTSHR_STS_Pos                           (0U)                     
#define ETH_PTPTSHR_STS_Msk                           (0xFFFFFFFFUL << ETH_PTPTSHR_STS_Pos) /*!< 0xFFFFFFFF */
#define ETH_PTPTSHR_STS                               ETH_PTPTSHR_STS_Msk      /* System Time second */

/* Bit definition for Ethernet PTP Time Stamp Low Register */
#define ETH_PTPTSLR_STPNS_Pos                         (31U)                    
#define ETH_PTPTSLR_STPNS_Msk                         (0x1UL << ETH_PTPTSLR_STPNS_Pos) /*!< 0x80000000 */
#define ETH_PTPTSLR_STPNS                             ETH_PTPTSLR_STPNS_Msk    /* System Time Positive or negative time */
#define ETH_PTPTSLR_STSS_Pos                          (0U)                     
#define ETH_PTPTSLR_STSS_Msk                          (0x7FFFFFFFUL << ETH_PTPTSLR_STSS_Pos) /*!< 0x7FFFFFFF */
#define ETH_PTPTSLR_STSS                              ETH_PTPTSLR_STSS_Msk     /* System Time sub-seconds */

/* Bit definition for Ethernet PTP Time Stamp High Update Register */
#define ETH_PTPTSHUR_TSUS_Pos                         (0U)                     
#define ETH_PTPTSHUR_TSUS_Msk                         (0xFFFFFFFFUL << ETH_PTPTSHUR_TSUS_Pos) /*!< 0xFFFFFFFF */
#define ETH_PTPTSHUR_TSUS                             ETH_PTPTSHUR_TSUS_Msk    /* Time stamp update seconds */

/* Bit definition for Ethernet PTP Time Stamp Low Update Register */
#define ETH_PTPTSLUR_TSUPNS_Pos                       (31U)                    
#define ETH_PTPTSLUR_TSUPNS_Msk                       (0x1UL << ETH_PTPTSLUR_TSUPNS_Pos) /*!< 0x80000000 */
#define ETH_PTPTSLUR_TSUPNS                           ETH_PTPTSLUR_TSUPNS_Msk  /* Time stamp update Positive or negative time */
#define ETH_PTPTSLUR_TSUSS_Pos                        (0U)                     
#define ETH_PTPTSLUR_TSUSS_Msk                        (0x7FFFFFFFUL << ETH_PTPTSLUR_TSUSS_Pos) /*!< 0x7FFFFFFF */
#define ETH_PTPTSLUR_TSUSS                            ETH_PTPTSLUR_TSUSS_Msk   /* Time stamp update sub-seconds */

/* Bit definition for Ethernet PTP Time Stamp Addend Register */
#define ETH_PTPTSAR_TSA_Pos                           (0U)                     
#define ETH_PTPTSAR_TSA_Msk                           (0xFFFFFFFFUL << ETH_PTPTSAR_TSA_Pos) /*!< 0xFFFFFFFF */
#define ETH_PTPTSAR_TSA                               ETH_PTPTSAR_TSA_Msk      /* Time stamp addend */

/* Bit definition for Ethernet PTP Target Time High Register */
#define ETH_PTPTTHR_TTSH_Pos                          (0U)                     
#define ETH_PTPTTHR_TTSH_Msk                          (0xFFFFFFFFUL << ETH_PTPTTHR_TTSH_Pos) /*!< 0xFFFFFFFF */
#define ETH_PTPTTHR_TTSH                              ETH_PTPTTHR_TTSH_Msk     /* Target time stamp high */

/* Bit definition for Ethernet PTP Target Time Low Register */
#define ETH_PTPTTLR_TTSL_Pos                          (0U)                     
#define ETH_PTPTTLR_TTSL_Msk                          (0xFFFFFFFFUL << ETH_PTPTTLR_TTSL_Pos) /*!< 0xFFFFFFFF */
#define ETH_PTPTTLR_TTSL                              ETH_PTPTTLR_TTSL_Msk     /* Target time stamp low */

/* Bit definition for Ethernet PTP Time Stamp Status Register */
#define ETH_PTPTSSR_TSTTR_Pos                         (5U)                     
#define ETH_PTPTSSR_TSTTR_Msk                         (0x1UL << ETH_PTPTSSR_TSTTR_Pos) /*!< 0x00000020 */
#define ETH_PTPTSSR_TSTTR                             ETH_PTPTSSR_TSTTR_Msk    /* Time stamp target time reached */
#define ETH_PTPTSSR_TSSO_Pos                          (4U)                     
#define ETH_PTPTSSR_TSSO_Msk                          (0x1UL << ETH_PTPTSSR_TSSO_Pos) /*!< 0x00000010 */
#define ETH_PTPTSSR_TSSO                              ETH_PTPTSSR_TSSO_Msk     /* Time stamp seconds overflow */

/******************************************************************************/
/*                 Ethernet DMA Registers bits definition                     */
/******************************************************************************/

/* Bit definition for Ethernet DMA Bus Mode Register */
#define ETH_DMABMR_AAB_Pos                            (25U)                    
#define ETH_DMABMR_AAB_Msk                            (0x1UL << ETH_DMABMR_AAB_Pos) /*!< 0x02000000 */
#define ETH_DMABMR_AAB                                ETH_DMABMR_AAB_Msk       /* Address-Aligned beats */
#define ETH_DMABMR_FPM_Pos                            (24U)                    
#define ETH_DMABMR_FPM_Msk                            (0x1UL << ETH_DMABMR_FPM_Pos) /*!< 0x01000000 */
#define ETH_DMABMR_FPM                                ETH_DMABMR_FPM_Msk       /* 4xPBL mode */
#define ETH_DMABMR_USP_Pos                            (23U)                    
#define ETH_DMABMR_USP_Msk                            (0x1UL << ETH_DMABMR_USP_Pos) /*!< 0x00800000 */
#define ETH_DMABMR_USP                                ETH_DMABMR_USP_Msk       /* Use separate PBL */
#define ETH_DMABMR_RDP_Pos                            (17U)                    
#define ETH_DMABMR_RDP_Msk                            (0x3FUL << ETH_DMABMR_RDP_Pos) /*!< 0x007E0000 */
#define ETH_DMABMR_RDP                                ETH_DMABMR_RDP_Msk       /* RxDMA PBL */
#define ETH_DMABMR_RDP_1Beat                          0x00020000U              /* maximum number of beats to be transferred in one RxDMA transaction is 1 */
#define ETH_DMABMR_RDP_2Beat                          0x00040000U              /* maximum number of beats to be transferred in one RxDMA transaction is 2 */
#define ETH_DMABMR_RDP_4Beat                          0x00080000U              /* maximum number of beats to be transferred in one RxDMA transaction is 4 */
#define ETH_DMABMR_RDP_8Beat                          0x00100000U              /* maximum number of beats to be transferred in one RxDMA transaction is 8 */
#define ETH_DMABMR_RDP_16Beat                         0x00200000U              /* maximum number of beats to be transferred in one RxDMA transaction is 16 */
#define ETH_DMABMR_RDP_32Beat                         0x00400000U              /* maximum number of beats to be transferred in one RxDMA transaction is 32 */                
#define ETH_DMABMR_RDP_4xPBL_4Beat                    0x01020000U              /* maximum number of beats to be transferred in one RxDMA transaction is 4 */
#define ETH_DMABMR_RDP_4xPBL_8Beat                    0x01040000U              /* maximum number of beats to be transferred in one RxDMA transaction is 8 */
#define ETH_DMABMR_RDP_4xPBL_16Beat                   0x01080000U              /* maximum number of beats to be transferred in one RxDMA transaction is 16 */
#define ETH_DMABMR_RDP_4xPBL_32Beat                   0x01100000U              /* maximum number of beats to be transferred in one RxDMA transaction is 32 */
#define ETH_DMABMR_RDP_4xPBL_64Beat                   0x01200000U              /* maximum number of beats to be transferred in one RxDMA transaction is 64 */
#define ETH_DMABMR_RDP_4xPBL_128Beat                  0x01400000U              /* maximum number of beats to be transferred in one RxDMA transaction is 128 */  
#define ETH_DMABMR_FB_Pos                             (16U)                    
#define ETH_DMABMR_FB_Msk                             (0x1UL << ETH_DMABMR_FB_Pos) /*!< 0x00010000 */
#define ETH_DMABMR_FB                                 ETH_DMABMR_FB_Msk        /* Fixed Burst */
#define ETH_DMABMR_RTPR_Pos                           (14U)                    
#define ETH_DMABMR_RTPR_Msk                           (0x3UL << ETH_DMABMR_RTPR_Pos) /*!< 0x0000C000 */
#define ETH_DMABMR_RTPR                               ETH_DMABMR_RTPR_Msk      /* Rx Tx priority ratio */
#define ETH_DMABMR_RTPR_1_1                           0x00000000U              /* Rx Tx priority ratio */
#define ETH_DMABMR_RTPR_2_1                           0x00004000U              /* Rx Tx priority ratio */
#define ETH_DMABMR_RTPR_3_1                           0x00008000U              /* Rx Tx priority ratio */
#define ETH_DMABMR_RTPR_4_1                           0x0000C000U              /* Rx Tx priority ratio */  
#define ETH_DMABMR_PBL_Pos                            (8U)                     
#define ETH_DMABMR_PBL_Msk                            (0x3FUL << ETH_DMABMR_PBL_Pos) /*!< 0x00003F00 */
#define ETH_DMABMR_PBL                                ETH_DMABMR_PBL_Msk       /* Programmable burst length */
#define ETH_DMABMR_PBL_1Beat                          0x00000100U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 1 */
#define ETH_DMABMR_PBL_2Beat                          0x00000200U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 2 */
#define ETH_DMABMR_PBL_4Beat                          0x00000400U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
#define ETH_DMABMR_PBL_8Beat                          0x00000800U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
#define ETH_DMABMR_PBL_16Beat                         0x00001000U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
#define ETH_DMABMR_PBL_32Beat                         0x00002000U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */                
#define ETH_DMABMR_PBL_4xPBL_4Beat                    0x01000100U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
#define ETH_DMABMR_PBL_4xPBL_8Beat                    0x01000200U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
#define ETH_DMABMR_PBL_4xPBL_16Beat                   0x01000400U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
#define ETH_DMABMR_PBL_4xPBL_32Beat                   0x01000800U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */
#define ETH_DMABMR_PBL_4xPBL_64Beat                   0x01001000U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 64 */
#define ETH_DMABMR_PBL_4xPBL_128Beat                  0x01002000U              /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 128 */
#define ETH_DMABMR_EDE_Pos                            (7U)                     
#define ETH_DMABMR_EDE_Msk                            (0x1UL << ETH_DMABMR_EDE_Pos) /*!< 0x00000080 */
#define ETH_DMABMR_EDE                                ETH_DMABMR_EDE_Msk       /* Enhanced Descriptor Enable */
#define ETH_DMABMR_DSL_Pos                            (2U)                     
#define ETH_DMABMR_DSL_Msk                            (0x1FUL << ETH_DMABMR_DSL_Pos) /*!< 0x0000007C */
#define ETH_DMABMR_DSL                                ETH_DMABMR_DSL_Msk       /* Descriptor Skip Length */
#define ETH_DMABMR_DA_Pos                             (1U)                     
#define ETH_DMABMR_DA_Msk                             (0x1UL << ETH_DMABMR_DA_Pos) /*!< 0x00000002 */
#define ETH_DMABMR_DA                                 ETH_DMABMR_DA_Msk        /* DMA arbitration scheme */
#define ETH_DMABMR_SR_Pos                             (0U)                     
#define ETH_DMABMR_SR_Msk                             (0x1UL << ETH_DMABMR_SR_Pos) /*!< 0x00000001 */
#define ETH_DMABMR_SR                                 ETH_DMABMR_SR_Msk        /* Software reset */

/* Bit definition for Ethernet DMA Transmit Poll Demand Register */
#define ETH_DMATPDR_TPD_Pos                           (0U)                     
#define ETH_DMATPDR_TPD_Msk                           (0xFFFFFFFFUL << ETH_DMATPDR_TPD_Pos) /*!< 0xFFFFFFFF */
#define ETH_DMATPDR_TPD                               ETH_DMATPDR_TPD_Msk      /* Transmit poll demand */

/* Bit definition for Ethernet DMA Receive Poll Demand Register */
#define ETH_DMARPDR_RPD_Pos                           (0U)                     
#define ETH_DMARPDR_RPD_Msk                           (0xFFFFFFFFUL << ETH_DMARPDR_RPD_Pos) /*!< 0xFFFFFFFF */
#define ETH_DMARPDR_RPD                               ETH_DMARPDR_RPD_Msk      /* Receive poll demand  */

/* Bit definition for Ethernet DMA Receive Descriptor List Address Register */
#define ETH_DMARDLAR_SRL_Pos                          (0U)                     
#define ETH_DMARDLAR_SRL_Msk                          (0xFFFFFFFFUL << ETH_DMARDLAR_SRL_Pos) /*!< 0xFFFFFFFF */
#define ETH_DMARDLAR_SRL                              ETH_DMARDLAR_SRL_Msk     /* Start of receive list */

/* Bit definition for Ethernet DMA Transmit Descriptor List Address Register */
#define ETH_DMATDLAR_STL_Pos                          (0U)                     
#define ETH_DMATDLAR_STL_Msk                          (0xFFFFFFFFUL << ETH_DMATDLAR_STL_Pos) /*!< 0xFFFFFFFF */
#define ETH_DMATDLAR_STL                              ETH_DMATDLAR_STL_Msk     /* Start of transmit list */

/* Bit definition for Ethernet DMA Status Register */
#define ETH_DMASR_TSTS_Pos                            (29U)                    
#define ETH_DMASR_TSTS_Msk                            (0x1UL << ETH_DMASR_TSTS_Pos) /*!< 0x20000000 */
#define ETH_DMASR_TSTS                                ETH_DMASR_TSTS_Msk       /* Time-stamp trigger status */
#define ETH_DMASR_PMTS_Pos                            (28U)                    
#define ETH_DMASR_PMTS_Msk                            (0x1UL << ETH_DMASR_PMTS_Pos) /*!< 0x10000000 */
#define ETH_DMASR_PMTS                                ETH_DMASR_PMTS_Msk       /* PMT status */
#define ETH_DMASR_MMCS_Pos                            (27U)                    
#define ETH_DMASR_MMCS_Msk                            (0x1UL << ETH_DMASR_MMCS_Pos) /*!< 0x08000000 */
#define ETH_DMASR_MMCS                                ETH_DMASR_MMCS_Msk       /* MMC status */
#define ETH_DMASR_EBS_Pos                             (23U)                    
#define ETH_DMASR_EBS_Msk                             (0x7UL << ETH_DMASR_EBS_Pos) /*!< 0x03800000 */
#define ETH_DMASR_EBS                                 ETH_DMASR_EBS_Msk        /* Error bits status */
  /* combination with EBS[2:0] for GetFlagStatus function */
#define ETH_DMASR_EBS_DescAccess_Pos                  (25U)                    
#define ETH_DMASR_EBS_DescAccess_Msk                  (0x1UL << ETH_DMASR_EBS_DescAccess_Pos) /*!< 0x02000000 */
#define ETH_DMASR_EBS_DescAccess                      ETH_DMASR_EBS_DescAccess_Msk /* Error bits 0-data buffer, 1-desc. access */
#define ETH_DMASR_EBS_ReadTransf_Pos                  (24U)                    
#define ETH_DMASR_EBS_ReadTransf_Msk                  (0x1UL << ETH_DMASR_EBS_ReadTransf_Pos) /*!< 0x01000000 */
#define ETH_DMASR_EBS_ReadTransf                      ETH_DMASR_EBS_ReadTransf_Msk /* Error bits 0-write trnsf, 1-read transfr */
#define ETH_DMASR_EBS_DataTransfTx_Pos                (23U)                    
#define ETH_DMASR_EBS_DataTransfTx_Msk                (0x1UL << ETH_DMASR_EBS_DataTransfTx_Pos) /*!< 0x00800000 */
#define ETH_DMASR_EBS_DataTransfTx                    ETH_DMASR_EBS_DataTransfTx_Msk /* Error bits 0-Rx DMA, 1-Tx DMA */
#define ETH_DMASR_TPS_Pos                             (20U)                    
#define ETH_DMASR_TPS_Msk                             (0x7UL << ETH_DMASR_TPS_Pos) /*!< 0x00700000 */
#define ETH_DMASR_TPS                                 ETH_DMASR_TPS_Msk        /* Transmit process state */
#define ETH_DMASR_TPS_Stopped                         0x00000000U              /* Stopped - Reset or Stop Tx Command issued  */
#define ETH_DMASR_TPS_Fetching_Pos                    (20U)                    
#define ETH_DMASR_TPS_Fetching_Msk                    (0x1UL << ETH_DMASR_TPS_Fetching_Pos) /*!< 0x00100000 */
#define ETH_DMASR_TPS_Fetching                        ETH_DMASR_TPS_Fetching_Msk /* Running - fetching the Tx descriptor */
#define ETH_DMASR_TPS_Waiting_Pos                     (21U)                    
#define ETH_DMASR_TPS_Waiting_Msk                     (0x1UL << ETH_DMASR_TPS_Waiting_Pos) /*!< 0x00200000 */
#define ETH_DMASR_TPS_Waiting                         ETH_DMASR_TPS_Waiting_Msk /* Running - waiting for status */
#define ETH_DMASR_TPS_Reading_Pos                     (20U)                    
#define ETH_DMASR_TPS_Reading_Msk                     (0x3UL << ETH_DMASR_TPS_Reading_Pos) /*!< 0x00300000 */
#define ETH_DMASR_TPS_Reading                         ETH_DMASR_TPS_Reading_Msk /* Running - reading the data from host memory */
#define ETH_DMASR_TPS_Suspended_Pos                   (21U)                    
#define ETH_DMASR_TPS_Suspended_Msk                   (0x3UL << ETH_DMASR_TPS_Suspended_Pos) /*!< 0x00600000 */
#define ETH_DMASR_TPS_Suspended                       ETH_DMASR_TPS_Suspended_Msk /* Suspended - Tx Descriptor unavailable */
#define ETH_DMASR_TPS_Closing_Pos                     (20U)                    
#define ETH_DMASR_TPS_Closing_Msk                     (0x7UL << ETH_DMASR_TPS_Closing_Pos) /*!< 0x00700000 */
#define ETH_DMASR_TPS_Closing                         ETH_DMASR_TPS_Closing_Msk /* Running - closing Rx descriptor */
#define ETH_DMASR_RPS_Pos                             (17U)                    
#define ETH_DMASR_RPS_Msk                             (0x7UL << ETH_DMASR_RPS_Pos) /*!< 0x000E0000 */
#define ETH_DMASR_RPS                                 ETH_DMASR_RPS_Msk        /* Receive process state */
#define ETH_DMASR_RPS_Stopped                         0x00000000U              /* Stopped - Reset or Stop Rx Command issued */
#define ETH_DMASR_RPS_Fetching_Pos                    (17U)                    
#define ETH_DMASR_RPS_Fetching_Msk                    (0x1UL << ETH_DMASR_RPS_Fetching_Pos) /*!< 0x00020000 */
#define ETH_DMASR_RPS_Fetching                        ETH_DMASR_RPS_Fetching_Msk /* Running - fetching the Rx descriptor */
#define ETH_DMASR_RPS_Waiting_Pos                     (17U)                    
#define ETH_DMASR_RPS_Waiting_Msk                     (0x3UL << ETH_DMASR_RPS_Waiting_Pos) /*!< 0x00060000 */
#define ETH_DMASR_RPS_Waiting                         ETH_DMASR_RPS_Waiting_Msk /* Running - waiting for packet */
#define ETH_DMASR_RPS_Suspended_Pos                   (19U)                    
#define ETH_DMASR_RPS_Suspended_Msk                   (0x1UL << ETH_DMASR_RPS_Suspended_Pos) /*!< 0x00080000 */
#define ETH_DMASR_RPS_Suspended                       ETH_DMASR_RPS_Suspended_Msk /* Suspended - Rx Descriptor unavailable */
#define ETH_DMASR_RPS_Closing_Pos                     (17U)                    
#define ETH_DMASR_RPS_Closing_Msk                     (0x5UL << ETH_DMASR_RPS_Closing_Pos) /*!< 0x000A0000 */
#define ETH_DMASR_RPS_Closing                         ETH_DMASR_RPS_Closing_Msk /* Running - closing descriptor */
#define ETH_DMASR_RPS_Queuing_Pos                     (17U)                    
#define ETH_DMASR_RPS_Queuing_Msk                     (0x7UL << ETH_DMASR_RPS_Queuing_Pos) /*!< 0x000E0000 */
#define ETH_DMASR_RPS_Queuing                         ETH_DMASR_RPS_Queuing_Msk /* Running - queuing the receive frame into host memory */
#define ETH_DMASR_NIS_Pos                             (16U)                    
#define ETH_DMASR_NIS_Msk                             (0x1UL << ETH_DMASR_NIS_Pos) /*!< 0x00010000 */
#define ETH_DMASR_NIS                                 ETH_DMASR_NIS_Msk        /* Normal interrupt summary */
#define ETH_DMASR_AIS_Pos                             (15U)                    
#define ETH_DMASR_AIS_Msk                             (0x1UL << ETH_DMASR_AIS_Pos) /*!< 0x00008000 */
#define ETH_DMASR_AIS                                 ETH_DMASR_AIS_Msk        /* Abnormal interrupt summary */
#define ETH_DMASR_ERS_Pos                             (14U)                    
#define ETH_DMASR_ERS_Msk                             (0x1UL << ETH_DMASR_ERS_Pos) /*!< 0x00004000 */
#define ETH_DMASR_ERS                                 ETH_DMASR_ERS_Msk        /* Early receive status */
#define ETH_DMASR_FBES_Pos                            (13U)                    
#define ETH_DMASR_FBES_Msk                            (0x1UL << ETH_DMASR_FBES_Pos) /*!< 0x00002000 */
#define ETH_DMASR_FBES                                ETH_DMASR_FBES_Msk       /* Fatal bus error status */
#define ETH_DMASR_ETS_Pos                             (10U)                    
#define ETH_DMASR_ETS_Msk                             (0x1UL << ETH_DMASR_ETS_Pos) /*!< 0x00000400 */
#define ETH_DMASR_ETS                                 ETH_DMASR_ETS_Msk        /* Early transmit status */
#define ETH_DMASR_RWTS_Pos                            (9U)                     
#define ETH_DMASR_RWTS_Msk                            (0x1UL << ETH_DMASR_RWTS_Pos) /*!< 0x00000200 */
#define ETH_DMASR_RWTS                                ETH_DMASR_RWTS_Msk       /* Receive watchdog timeout status */
#define ETH_DMASR_RPSS_Pos                            (8U)                     
#define ETH_DMASR_RPSS_Msk                            (0x1UL << ETH_DMASR_RPSS_Pos) /*!< 0x00000100 */
#define ETH_DMASR_RPSS                                ETH_DMASR_RPSS_Msk       /* Receive process stopped status */
#define ETH_DMASR_RBUS_Pos                            (7U)                     
#define ETH_DMASR_RBUS_Msk                            (0x1UL << ETH_DMASR_RBUS_Pos) /*!< 0x00000080 */
#define ETH_DMASR_RBUS                                ETH_DMASR_RBUS_Msk       /* Receive buffer unavailable status */
#define ETH_DMASR_RS_Pos                              (6U)                     
#define ETH_DMASR_RS_Msk                              (0x1UL << ETH_DMASR_RS_Pos) /*!< 0x00000040 */
#define ETH_DMASR_RS                                  ETH_DMASR_RS_Msk         /* Receive status */
#define ETH_DMASR_TUS_Pos                             (5U)                     
#define ETH_DMASR_TUS_Msk                             (0x1UL << ETH_DMASR_TUS_Pos) /*!< 0x00000020 */
#define ETH_DMASR_TUS                                 ETH_DMASR_TUS_Msk        /* Transmit underflow status */
#define ETH_DMASR_ROS_Pos                             (4U)                     
#define ETH_DMASR_ROS_Msk                             (0x1UL << ETH_DMASR_ROS_Pos) /*!< 0x00000010 */
#define ETH_DMASR_ROS                                 ETH_DMASR_ROS_Msk        /* Receive overflow status */
#define ETH_DMASR_TJTS_Pos                            (3U)                     
#define ETH_DMASR_TJTS_Msk                            (0x1UL << ETH_DMASR_TJTS_Pos) /*!< 0x00000008 */
#define ETH_DMASR_TJTS                                ETH_DMASR_TJTS_Msk       /* Transmit jabber timeout status */
#define ETH_DMASR_TBUS_Pos                            (2U)                     
#define ETH_DMASR_TBUS_Msk                            (0x1UL << ETH_DMASR_TBUS_Pos) /*!< 0x00000004 */
#define ETH_DMASR_TBUS                                ETH_DMASR_TBUS_Msk       /* Transmit buffer unavailable status */
#define ETH_DMASR_TPSS_Pos                            (1U)                     
#define ETH_DMASR_TPSS_Msk                            (0x1UL << ETH_DMASR_TPSS_Pos) /*!< 0x00000002 */
#define ETH_DMASR_TPSS                                ETH_DMASR_TPSS_Msk       /* Transmit process stopped status */
#define ETH_DMASR_TS_Pos                              (0U)                     
#define ETH_DMASR_TS_Msk                              (0x1UL << ETH_DMASR_TS_Pos) /*!< 0x00000001 */
#define ETH_DMASR_TS                                  ETH_DMASR_TS_Msk         /* Transmit status */

/* Bit definition for Ethernet DMA Operation Mode Register */
#define ETH_DMAOMR_DTCEFD_Pos                         (26U)                    
#define ETH_DMAOMR_DTCEFD_Msk                         (0x1UL << ETH_DMAOMR_DTCEFD_Pos) /*!< 0x04000000 */
#define ETH_DMAOMR_DTCEFD                             ETH_DMAOMR_DTCEFD_Msk    /* Disable Dropping of TCP/IP checksum error frames */
#define ETH_DMAOMR_RSF_Pos                            (25U)                    
#define ETH_DMAOMR_RSF_Msk                            (0x1UL << ETH_DMAOMR_RSF_Pos) /*!< 0x02000000 */
#define ETH_DMAOMR_RSF                                ETH_DMAOMR_RSF_Msk       /* Receive store and forward */
#define ETH_DMAOMR_DFRF_Pos                           (24U)                    
#define ETH_DMAOMR_DFRF_Msk                           (0x1UL << ETH_DMAOMR_DFRF_Pos) /*!< 0x01000000 */
#define ETH_DMAOMR_DFRF                               ETH_DMAOMR_DFRF_Msk      /* Disable flushing of received frames */
#define ETH_DMAOMR_TSF_Pos                            (21U)                    
#define ETH_DMAOMR_TSF_Msk                            (0x1UL << ETH_DMAOMR_TSF_Pos) /*!< 0x00200000 */
#define ETH_DMAOMR_TSF                                ETH_DMAOMR_TSF_Msk       /* Transmit store and forward */
#define ETH_DMAOMR_FTF_Pos                            (20U)                    
#define ETH_DMAOMR_FTF_Msk                            (0x1UL << ETH_DMAOMR_FTF_Pos) /*!< 0x00100000 */
#define ETH_DMAOMR_FTF                                ETH_DMAOMR_FTF_Msk       /* Flush transmit FIFO */
#define ETH_DMAOMR_TTC_Pos                            (14U)                    
#define ETH_DMAOMR_TTC_Msk                            (0x7UL << ETH_DMAOMR_TTC_Pos) /*!< 0x0001C000 */
#define ETH_DMAOMR_TTC                                ETH_DMAOMR_TTC_Msk       /* Transmit threshold control */
#define ETH_DMAOMR_TTC_64Bytes                        0x00000000U              /* threshold level of the MTL Transmit FIFO is 64 Bytes */
#define ETH_DMAOMR_TTC_128Bytes                       0x00004000U              /* threshold level of the MTL Transmit FIFO is 128 Bytes */
#define ETH_DMAOMR_TTC_192Bytes                       0x00008000U              /* threshold level of the MTL Transmit FIFO is 192 Bytes */
#define ETH_DMAOMR_TTC_256Bytes                       0x0000C000U              /* threshold level of the MTL Transmit FIFO is 256 Bytes */
#define ETH_DMAOMR_TTC_40Bytes                        0x00010000U              /* threshold level of the MTL Transmit FIFO is 40 Bytes */
#define ETH_DMAOMR_TTC_32Bytes                        0x00014000U              /* threshold level of the MTL Transmit FIFO is 32 Bytes */
#define ETH_DMAOMR_TTC_24Bytes                        0x00018000U              /* threshold level of the MTL Transmit FIFO is 24 Bytes */
#define ETH_DMAOMR_TTC_16Bytes                        0x0001C000U              /* threshold level of the MTL Transmit FIFO is 16 Bytes */
#define ETH_DMAOMR_ST_Pos                             (13U)                    
#define ETH_DMAOMR_ST_Msk                             (0x1UL << ETH_DMAOMR_ST_Pos) /*!< 0x00002000 */
#define ETH_DMAOMR_ST                                 ETH_DMAOMR_ST_Msk        /* Start/stop transmission command */
#define ETH_DMAOMR_FEF_Pos                            (7U)                     
#define ETH_DMAOMR_FEF_Msk                            (0x1UL << ETH_DMAOMR_FEF_Pos) /*!< 0x00000080 */
#define ETH_DMAOMR_FEF                                ETH_DMAOMR_FEF_Msk       /* Forward error frames */
#define ETH_DMAOMR_FUGF_Pos                           (6U)                     
#define ETH_DMAOMR_FUGF_Msk                           (0x1UL << ETH_DMAOMR_FUGF_Pos) /*!< 0x00000040 */
#define ETH_DMAOMR_FUGF                               ETH_DMAOMR_FUGF_Msk      /* Forward undersized good frames */
#define ETH_DMAOMR_RTC_Pos                            (3U)                     
#define ETH_DMAOMR_RTC_Msk                            (0x3UL << ETH_DMAOMR_RTC_Pos) /*!< 0x00000018 */
#define ETH_DMAOMR_RTC                                ETH_DMAOMR_RTC_Msk       /* receive threshold control */
#define ETH_DMAOMR_RTC_64Bytes                        0x00000000U              /* threshold level of the MTL Receive FIFO is 64 Bytes */
#define ETH_DMAOMR_RTC_32Bytes                        0x00000008U              /* threshold level of the MTL Receive FIFO is 32 Bytes */
#define ETH_DMAOMR_RTC_96Bytes                        0x00000010U              /* threshold level of the MTL Receive FIFO is 96 Bytes */
#define ETH_DMAOMR_RTC_128Bytes                       0x00000018U              /* threshold level of the MTL Receive FIFO is 128 Bytes */
#define ETH_DMAOMR_OSF_Pos                            (2U)                     
#define ETH_DMAOMR_OSF_Msk                            (0x1UL << ETH_DMAOMR_OSF_Pos) /*!< 0x00000004 */
#define ETH_DMAOMR_OSF                                ETH_DMAOMR_OSF_Msk       /* operate on second frame */
#define ETH_DMAOMR_SR_Pos                             (1U)                     
#define ETH_DMAOMR_SR_Msk                             (0x1UL << ETH_DMAOMR_SR_Pos) /*!< 0x00000002 */
#define ETH_DMAOMR_SR                                 ETH_DMAOMR_SR_Msk        /* Start/stop receive */

/* Bit definition for Ethernet DMA Interrupt Enable Register */
#define ETH_DMAIER_NISE_Pos                           (16U)                    
#define ETH_DMAIER_NISE_Msk                           (0x1UL << ETH_DMAIER_NISE_Pos) /*!< 0x00010000 */
#define ETH_DMAIER_NISE                               ETH_DMAIER_NISE_Msk      /* Normal interrupt summary enable */
#define ETH_DMAIER_AISE_Pos                           (15U)                    
#define ETH_DMAIER_AISE_Msk                           (0x1UL << ETH_DMAIER_AISE_Pos) /*!< 0x00008000 */
#define ETH_DMAIER_AISE                               ETH_DMAIER_AISE_Msk      /* Abnormal interrupt summary enable */
#define ETH_DMAIER_ERIE_Pos                           (14U)                    
#define ETH_DMAIER_ERIE_Msk                           (0x1UL << ETH_DMAIER_ERIE_Pos) /*!< 0x00004000 */
#define ETH_DMAIER_ERIE                               ETH_DMAIER_ERIE_Msk      /* Early receive interrupt enable */
#define ETH_DMAIER_FBEIE_Pos                          (13U)                    
#define ETH_DMAIER_FBEIE_Msk                          (0x1UL << ETH_DMAIER_FBEIE_Pos) /*!< 0x00002000 */
#define ETH_DMAIER_FBEIE                              ETH_DMAIER_FBEIE_Msk     /* Fatal bus error interrupt enable */
#define ETH_DMAIER_ETIE_Pos                           (10U)                    
#define ETH_DMAIER_ETIE_Msk                           (0x1UL << ETH_DMAIER_ETIE_Pos) /*!< 0x00000400 */
#define ETH_DMAIER_ETIE                               ETH_DMAIER_ETIE_Msk      /* Early transmit interrupt enable */
#define ETH_DMAIER_RWTIE_Pos                          (9U)                     
#define ETH_DMAIER_RWTIE_Msk                          (0x1UL << ETH_DMAIER_RWTIE_Pos) /*!< 0x00000200 */
#define ETH_DMAIER_RWTIE                              ETH_DMAIER_RWTIE_Msk     /* Receive watchdog timeout interrupt enable */
#define ETH_DMAIER_RPSIE_Pos                          (8U)                     
#define ETH_DMAIER_RPSIE_Msk                          (0x1UL << ETH_DMAIER_RPSIE_Pos) /*!< 0x00000100 */
#define ETH_DMAIER_RPSIE                              ETH_DMAIER_RPSIE_Msk     /* Receive process stopped interrupt enable */
#define ETH_DMAIER_RBUIE_Pos                          (7U)                     
#define ETH_DMAIER_RBUIE_Msk                          (0x1UL << ETH_DMAIER_RBUIE_Pos) /*!< 0x00000080 */
#define ETH_DMAIER_RBUIE                              ETH_DMAIER_RBUIE_Msk     /* Receive buffer unavailable interrupt enable */
#define ETH_DMAIER_RIE_Pos                            (6U)                     
#define ETH_DMAIER_RIE_Msk                            (0x1UL << ETH_DMAIER_RIE_Pos) /*!< 0x00000040 */
#define ETH_DMAIER_RIE                                ETH_DMAIER_RIE_Msk       /* Receive interrupt enable */
#define ETH_DMAIER_TUIE_Pos                           (5U)                     
#define ETH_DMAIER_TUIE_Msk                           (0x1UL << ETH_DMAIER_TUIE_Pos) /*!< 0x00000020 */
#define ETH_DMAIER_TUIE                               ETH_DMAIER_TUIE_Msk      /* Transmit Underflow interrupt enable */
#define ETH_DMAIER_ROIE_Pos                           (4U)                     
#define ETH_DMAIER_ROIE_Msk                           (0x1UL << ETH_DMAIER_ROIE_Pos) /*!< 0x00000010 */
#define ETH_DMAIER_ROIE                               ETH_DMAIER_ROIE_Msk      /* Receive Overflow interrupt enable */
#define ETH_DMAIER_TJTIE_Pos                          (3U)                     
#define ETH_DMAIER_TJTIE_Msk                          (0x1UL << ETH_DMAIER_TJTIE_Pos) /*!< 0x00000008 */
#define ETH_DMAIER_TJTIE                              ETH_DMAIER_TJTIE_Msk     /* Transmit jabber timeout interrupt enable */
#define ETH_DMAIER_TBUIE_Pos                          (2U)                     
#define ETH_DMAIER_TBUIE_Msk                          (0x1UL << ETH_DMAIER_TBUIE_Pos) /*!< 0x00000004 */
#define ETH_DMAIER_TBUIE                              ETH_DMAIER_TBUIE_Msk     /* Transmit buffer unavailable interrupt enable */
#define ETH_DMAIER_TPSIE_Pos                          (1U)                     
#define ETH_DMAIER_TPSIE_Msk                          (0x1UL << ETH_DMAIER_TPSIE_Pos) /*!< 0x00000002 */
#define ETH_DMAIER_TPSIE                              ETH_DMAIER_TPSIE_Msk     /* Transmit process stopped interrupt enable */
#define ETH_DMAIER_TIE_Pos                            (0U)                     
#define ETH_DMAIER_TIE_Msk                            (0x1UL << ETH_DMAIER_TIE_Pos) /*!< 0x00000001 */
#define ETH_DMAIER_TIE                                ETH_DMAIER_TIE_Msk       /* Transmit interrupt enable */

/* Bit definition for Ethernet DMA Missed Frame and Buffer Overflow Counter Register */
#define ETH_DMAMFBOCR_OFOC_Pos                        (28U)                    
#define ETH_DMAMFBOCR_OFOC_Msk                        (0x1UL << ETH_DMAMFBOCR_OFOC_Pos) /*!< 0x10000000 */
#define ETH_DMAMFBOCR_OFOC                            ETH_DMAMFBOCR_OFOC_Msk   /* Overflow bit for FIFO overflow counter */
#define ETH_DMAMFBOCR_MFA_Pos                         (17U)                    
#define ETH_DMAMFBOCR_MFA_Msk                         (0x7FFUL << ETH_DMAMFBOCR_MFA_Pos) /*!< 0x0FFE0000 */
#define ETH_DMAMFBOCR_MFA                             ETH_DMAMFBOCR_MFA_Msk    /* Number of frames missed by the application */
#define ETH_DMAMFBOCR_OMFC_Pos                        (16U)                    
#define ETH_DMAMFBOCR_OMFC_Msk                        (0x1UL << ETH_DMAMFBOCR_OMFC_Pos) /*!< 0x00010000 */
#define ETH_DMAMFBOCR_OMFC                            ETH_DMAMFBOCR_OMFC_Msk   /* Overflow bit for missed frame counter */
#define ETH_DMAMFBOCR_MFC_Pos                         (0U)                     
#define ETH_DMAMFBOCR_MFC_Msk                         (0xFFFFUL << ETH_DMAMFBOCR_MFC_Pos) /*!< 0x0000FFFF */
#define ETH_DMAMFBOCR_MFC                             ETH_DMAMFBOCR_MFC_Msk    /* Number of frames missed by the controller */

/* Bit definition for Ethernet DMA Current Host Transmit Descriptor Register */
#define ETH_DMACHTDR_HTDAP_Pos                        (0U)                     
#define ETH_DMACHTDR_HTDAP_Msk                        (0xFFFFFFFFUL << ETH_DMACHTDR_HTDAP_Pos) /*!< 0xFFFFFFFF */
#define ETH_DMACHTDR_HTDAP                            ETH_DMACHTDR_HTDAP_Msk   /* Host transmit descriptor address pointer */

/* Bit definition for Ethernet DMA Current Host Receive Descriptor Register */
#define ETH_DMACHRDR_HRDAP_Pos                        (0U)                     
#define ETH_DMACHRDR_HRDAP_Msk                        (0xFFFFFFFFUL << ETH_DMACHRDR_HRDAP_Pos) /*!< 0xFFFFFFFF */
#define ETH_DMACHRDR_HRDAP                            ETH_DMACHRDR_HRDAP_Msk   /* Host receive descriptor address pointer */

/* Bit definition for Ethernet DMA Current Host Transmit Buffer Address Register */
#define ETH_DMACHTBAR_HTBAP_Pos                       (0U)                     
#define ETH_DMACHTBAR_HTBAP_Msk                       (0xFFFFFFFFUL << ETH_DMACHTBAR_HTBAP_Pos) /*!< 0xFFFFFFFF */
#define ETH_DMACHTBAR_HTBAP                           ETH_DMACHTBAR_HTBAP_Msk  /* Host transmit buffer address pointer */

/* Bit definition for Ethernet DMA Current Host Receive Buffer Address Register */
#define ETH_DMACHRBAR_HRBAP_Pos                       (0U)                     
#define ETH_DMACHRBAR_HRBAP_Msk                       (0xFFFFFFFFUL << ETH_DMACHRBAR_HRBAP_Pos) /*!< 0xFFFFFFFF */
#define ETH_DMACHRBAR_HRBAP                           ETH_DMACHRBAR_HRBAP_Msk  /* Host receive buffer address pointer */

/******************************************************************************/
/*                                                                            */
/*                                       USB_OTG                              */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for USB_OTG_GOTGCTL register  ***********/
#define USB_OTG_GOTGCTL_SRQSCS_Pos               (0U)                          
#define USB_OTG_GOTGCTL_SRQSCS_Msk               (0x1UL << USB_OTG_GOTGCTL_SRQSCS_Pos) /*!< 0x00000001 */
#define USB_OTG_GOTGCTL_SRQSCS                   USB_OTG_GOTGCTL_SRQSCS_Msk    /*!< Session request success */
#define USB_OTG_GOTGCTL_SRQ_Pos                  (1U)                          
#define USB_OTG_GOTGCTL_SRQ_Msk                  (0x1UL << USB_OTG_GOTGCTL_SRQ_Pos) /*!< 0x00000002 */
#define USB_OTG_GOTGCTL_SRQ                      USB_OTG_GOTGCTL_SRQ_Msk       /*!< Session request */
#define USB_OTG_GOTGCTL_HNGSCS_Pos               (8U)                          
#define USB_OTG_GOTGCTL_HNGSCS_Msk               (0x1UL << USB_OTG_GOTGCTL_HNGSCS_Pos) /*!< 0x00000100 */
#define USB_OTG_GOTGCTL_HNGSCS                   USB_OTG_GOTGCTL_HNGSCS_Msk    /*!< Host set HNP enable */
#define USB_OTG_GOTGCTL_HNPRQ_Pos                (9U)                          
#define USB_OTG_GOTGCTL_HNPRQ_Msk                (0x1UL << USB_OTG_GOTGCTL_HNPRQ_Pos) /*!< 0x00000200 */
#define USB_OTG_GOTGCTL_HNPRQ                    USB_OTG_GOTGCTL_HNPRQ_Msk     /*!< HNP request */
#define USB_OTG_GOTGCTL_HSHNPEN_Pos              (10U)                         
#define USB_OTG_GOTGCTL_HSHNPEN_Msk              (0x1UL << USB_OTG_GOTGCTL_HSHNPEN_Pos) /*!< 0x00000400 */
#define USB_OTG_GOTGCTL_HSHNPEN                  USB_OTG_GOTGCTL_HSHNPEN_Msk   /*!< Host set HNP enable */
#define USB_OTG_GOTGCTL_DHNPEN_Pos               (11U)                         
#define USB_OTG_GOTGCTL_DHNPEN_Msk               (0x1UL << USB_OTG_GOTGCTL_DHNPEN_Pos) /*!< 0x00000800 */
#define USB_OTG_GOTGCTL_DHNPEN                   USB_OTG_GOTGCTL_DHNPEN_Msk    /*!< Device HNP enabled */
#define USB_OTG_GOTGCTL_CIDSTS_Pos               (16U)                         
#define USB_OTG_GOTGCTL_CIDSTS_Msk               (0x1UL << USB_OTG_GOTGCTL_CIDSTS_Pos) /*!< 0x00010000 */
#define USB_OTG_GOTGCTL_CIDSTS                   USB_OTG_GOTGCTL_CIDSTS_Msk    /*!< Connector ID status */
#define USB_OTG_GOTGCTL_DBCT_Pos                 (17U)                         
#define USB_OTG_GOTGCTL_DBCT_Msk                 (0x1UL << USB_OTG_GOTGCTL_DBCT_Pos) /*!< 0x00020000 */
#define USB_OTG_GOTGCTL_DBCT                     USB_OTG_GOTGCTL_DBCT_Msk      /*!< Long/short debounce time */
#define USB_OTG_GOTGCTL_ASVLD_Pos                (18U)                         
#define USB_OTG_GOTGCTL_ASVLD_Msk                (0x1UL << USB_OTG_GOTGCTL_ASVLD_Pos) /*!< 0x00040000 */
#define USB_OTG_GOTGCTL_ASVLD                    USB_OTG_GOTGCTL_ASVLD_Msk     /*!< A-session valid  */
#define USB_OTG_GOTGCTL_BSVLD_Pos                (19U)                         
#define USB_OTG_GOTGCTL_BSVLD_Msk                (0x1UL << USB_OTG_GOTGCTL_BSVLD_Pos) /*!< 0x00080000 */
#define USB_OTG_GOTGCTL_BSVLD                    USB_OTG_GOTGCTL_BSVLD_Msk     /*!< B-session valid */

/********************  Bit definition forUSB_OTG_HCFG register  ********************/

#define USB_OTG_HCFG_FSLSPCS_Pos                 (0U)                          
#define USB_OTG_HCFG_FSLSPCS_Msk                 (0x3UL << USB_OTG_HCFG_FSLSPCS_Pos) /*!< 0x00000003 */
#define USB_OTG_HCFG_FSLSPCS                     USB_OTG_HCFG_FSLSPCS_Msk      /*!< FS/LS PHY clock select  */
#define USB_OTG_HCFG_FSLSPCS_0                   (0x1UL << USB_OTG_HCFG_FSLSPCS_Pos) /*!< 0x00000001 */
#define USB_OTG_HCFG_FSLSPCS_1                   (0x2UL << USB_OTG_HCFG_FSLSPCS_Pos) /*!< 0x00000002 */
#define USB_OTG_HCFG_FSLSS_Pos                   (2U)                          
#define USB_OTG_HCFG_FSLSS_Msk                   (0x1UL << USB_OTG_HCFG_FSLSS_Pos) /*!< 0x00000004 */
#define USB_OTG_HCFG_FSLSS                       USB_OTG_HCFG_FSLSS_Msk        /*!< FS- and LS-only support */

/********************  Bit definition for USB_OTG_DCFG register  ********************/

#define USB_OTG_DCFG_DSPD_Pos                    (0U)                          
#define USB_OTG_DCFG_DSPD_Msk                    (0x3UL << USB_OTG_DCFG_DSPD_Pos) /*!< 0x00000003 */
#define USB_OTG_DCFG_DSPD                        USB_OTG_DCFG_DSPD_Msk         /*!< Device speed */
#define USB_OTG_DCFG_DSPD_0                      (0x1UL << USB_OTG_DCFG_DSPD_Pos) /*!< 0x00000001 */
#define USB_OTG_DCFG_DSPD_1                      (0x2UL << USB_OTG_DCFG_DSPD_Pos) /*!< 0x00000002 */
#define USB_OTG_DCFG_NZLSOHSK_Pos                (2U)                          
#define USB_OTG_DCFG_NZLSOHSK_Msk                (0x1UL << USB_OTG_DCFG_NZLSOHSK_Pos) /*!< 0x00000004 */
#define USB_OTG_DCFG_NZLSOHSK                    USB_OTG_DCFG_NZLSOHSK_Msk     /*!< Nonzero-length status OUT handshake */

#define USB_OTG_DCFG_DAD_Pos                     (4U)                          
#define USB_OTG_DCFG_DAD_Msk                     (0x7FUL << USB_OTG_DCFG_DAD_Pos) /*!< 0x000007F0 */
#define USB_OTG_DCFG_DAD                         USB_OTG_DCFG_DAD_Msk          /*!< Device address */
#define USB_OTG_DCFG_DAD_0                       (0x01UL << USB_OTG_DCFG_DAD_Pos) /*!< 0x00000010 */
#define USB_OTG_DCFG_DAD_1                       (0x02UL << USB_OTG_DCFG_DAD_Pos) /*!< 0x00000020 */
#define USB_OTG_DCFG_DAD_2                       (0x04UL << USB_OTG_DCFG_DAD_Pos) /*!< 0x00000040 */
#define USB_OTG_DCFG_DAD_3                       (0x08UL << USB_OTG_DCFG_DAD_Pos) /*!< 0x00000080 */
#define USB_OTG_DCFG_DAD_4                       (0x10UL << USB_OTG_DCFG_DAD_Pos) /*!< 0x00000100 */
#define USB_OTG_DCFG_DAD_5                       (0x20UL << USB_OTG_DCFG_DAD_Pos) /*!< 0x00000200 */
#define USB_OTG_DCFG_DAD_6                       (0x40UL << USB_OTG_DCFG_DAD_Pos) /*!< 0x00000400 */

#define USB_OTG_DCFG_PFIVL_Pos                   (11U)                         
#define USB_OTG_DCFG_PFIVL_Msk                   (0x3UL << USB_OTG_DCFG_PFIVL_Pos) /*!< 0x00001800 */
#define USB_OTG_DCFG_PFIVL                       USB_OTG_DCFG_PFIVL_Msk        /*!< Periodic (micro)frame interval */
#define USB_OTG_DCFG_PFIVL_0                     (0x1UL << USB_OTG_DCFG_PFIVL_Pos) /*!< 0x00000800 */
#define USB_OTG_DCFG_PFIVL_1                     (0x2UL << USB_OTG_DCFG_PFIVL_Pos) /*!< 0x00001000 */

#define USB_OTG_DCFG_XCVRDLY_Pos                 (14U)                         
#define USB_OTG_DCFG_XCVRDLY_Msk                 (0x1UL << USB_OTG_DCFG_XCVRDLY_Pos) /*!< 0x00004000 */
#define USB_OTG_DCFG_XCVRDLY                     USB_OTG_DCFG_XCVRDLY_Msk        /*!< Transceiver delay */

#define USB_OTG_DCFG_ERRATIM_Pos                 (15U)                         
#define USB_OTG_DCFG_ERRATIM_Msk                 (0x1UL << USB_OTG_DCFG_ERRATIM_Pos) /*!< 0x00008000 */
#define USB_OTG_DCFG_ERRATIM                     USB_OTG_DCFG_ERRATIM_Msk        /*!< Erratic error interrupt mask */

#define USB_OTG_DCFG_PERSCHIVL_Pos               (24U)                         
#define USB_OTG_DCFG_PERSCHIVL_Msk               (0x3UL << USB_OTG_DCFG_PERSCHIVL_Pos) /*!< 0x03000000 */
#define USB_OTG_DCFG_PERSCHIVL                   USB_OTG_DCFG_PERSCHIVL_Msk    /*!< Periodic scheduling interval */
#define USB_OTG_DCFG_PERSCHIVL_0                 (0x1UL << USB_OTG_DCFG_PERSCHIVL_Pos) /*!< 0x01000000 */
#define USB_OTG_DCFG_PERSCHIVL_1                 (0x2UL << USB_OTG_DCFG_PERSCHIVL_Pos) /*!< 0x02000000 */

/********************  Bit definition for USB_OTG_PCGCR register  ********************/
#define USB_OTG_PCGCR_STPPCLK_Pos                (0U)                          
#define USB_OTG_PCGCR_STPPCLK_Msk                (0x1UL << USB_OTG_PCGCR_STPPCLK_Pos) /*!< 0x00000001 */
#define USB_OTG_PCGCR_STPPCLK                    USB_OTG_PCGCR_STPPCLK_Msk     /*!< Stop PHY clock */
#define USB_OTG_PCGCR_GATEHCLK_Pos               (1U)                          
#define USB_OTG_PCGCR_GATEHCLK_Msk               (0x1UL << USB_OTG_PCGCR_GATEHCLK_Pos) /*!< 0x00000002 */
#define USB_OTG_PCGCR_GATEHCLK                   USB_OTG_PCGCR_GATEHCLK_Msk    /*!< Gate HCLK */
#define USB_OTG_PCGCR_PHYSUSP_Pos                (4U)                          
#define USB_OTG_PCGCR_PHYSUSP_Msk                (0x1UL << USB_OTG_PCGCR_PHYSUSP_Pos) /*!< 0x00000010 */
#define USB_OTG_PCGCR_PHYSUSP                    USB_OTG_PCGCR_PHYSUSP_Msk     /*!< PHY suspended */

/********************  Bit definition for USB_OTG_GOTGINT register  ********************/
#define USB_OTG_GOTGINT_SEDET_Pos                (2U)                          
#define USB_OTG_GOTGINT_SEDET_Msk                (0x1UL << USB_OTG_GOTGINT_SEDET_Pos) /*!< 0x00000004 */
#define USB_OTG_GOTGINT_SEDET                    USB_OTG_GOTGINT_SEDET_Msk     /*!< Session end detected                   */
#define USB_OTG_GOTGINT_SRSSCHG_Pos              (8U)                          
#define USB_OTG_GOTGINT_SRSSCHG_Msk              (0x1UL << USB_OTG_GOTGINT_SRSSCHG_Pos) /*!< 0x00000100 */
#define USB_OTG_GOTGINT_SRSSCHG                  USB_OTG_GOTGINT_SRSSCHG_Msk   /*!< Session request success status change  */
#define USB_OTG_GOTGINT_HNSSCHG_Pos              (9U)                          
#define USB_OTG_GOTGINT_HNSSCHG_Msk              (0x1UL << USB_OTG_GOTGINT_HNSSCHG_Pos) /*!< 0x00000200 */
#define USB_OTG_GOTGINT_HNSSCHG                  USB_OTG_GOTGINT_HNSSCHG_Msk   /*!< Host negotiation success status change */
#define USB_OTG_GOTGINT_HNGDET_Pos               (17U)                         
#define USB_OTG_GOTGINT_HNGDET_Msk               (0x1UL << USB_OTG_GOTGINT_HNGDET_Pos) /*!< 0x00020000 */
#define USB_OTG_GOTGINT_HNGDET                   USB_OTG_GOTGINT_HNGDET_Msk    /*!< Host negotiation detected              */
#define USB_OTG_GOTGINT_ADTOCHG_Pos              (18U)                         
#define USB_OTG_GOTGINT_ADTOCHG_Msk              (0x1UL << USB_OTG_GOTGINT_ADTOCHG_Pos) /*!< 0x00040000 */
#define USB_OTG_GOTGINT_ADTOCHG                  USB_OTG_GOTGINT_ADTOCHG_Msk   /*!< A-device timeout change                */
#define USB_OTG_GOTGINT_DBCDNE_Pos               (19U)                         
#define USB_OTG_GOTGINT_DBCDNE_Msk               (0x1UL << USB_OTG_GOTGINT_DBCDNE_Pos) /*!< 0x00080000 */
#define USB_OTG_GOTGINT_DBCDNE                   USB_OTG_GOTGINT_DBCDNE_Msk    /*!< Debounce done                          */

/********************  Bit definition for USB_OTG_DCTL register  ********************/
#define USB_OTG_DCTL_RWUSIG_Pos                  (0U)                          
#define USB_OTG_DCTL_RWUSIG_Msk                  (0x1UL << USB_OTG_DCTL_RWUSIG_Pos) /*!< 0x00000001 */
#define USB_OTG_DCTL_RWUSIG                      USB_OTG_DCTL_RWUSIG_Msk       /*!< Remote wakeup signaling */
#define USB_OTG_DCTL_SDIS_Pos                    (1U)                          
#define USB_OTG_DCTL_SDIS_Msk                    (0x1UL << USB_OTG_DCTL_SDIS_Pos) /*!< 0x00000002 */
#define USB_OTG_DCTL_SDIS                        USB_OTG_DCTL_SDIS_Msk         /*!< Soft disconnect         */
#define USB_OTG_DCTL_GINSTS_Pos                  (2U)                          
#define USB_OTG_DCTL_GINSTS_Msk                  (0x1UL << USB_OTG_DCTL_GINSTS_Pos) /*!< 0x00000004 */
#define USB_OTG_DCTL_GINSTS                      USB_OTG_DCTL_GINSTS_Msk       /*!< Global IN NAK status    */
#define USB_OTG_DCTL_GONSTS_Pos                  (3U)                          
#define USB_OTG_DCTL_GONSTS_Msk                  (0x1UL << USB_OTG_DCTL_GONSTS_Pos) /*!< 0x00000008 */
#define USB_OTG_DCTL_GONSTS                      USB_OTG_DCTL_GONSTS_Msk       /*!< Global OUT NAK status   */

#define USB_OTG_DCTL_TCTL_Pos                    (4U)                          
#define USB_OTG_DCTL_TCTL_Msk                    (0x7UL << USB_OTG_DCTL_TCTL_Pos) /*!< 0x00000070 */
#define USB_OTG_DCTL_TCTL                        USB_OTG_DCTL_TCTL_Msk         /*!< Test control */
#define USB_OTG_DCTL_TCTL_0                      (0x1UL << USB_OTG_DCTL_TCTL_Pos) /*!< 0x00000010 */
#define USB_OTG_DCTL_TCTL_1                      (0x2UL << USB_OTG_DCTL_TCTL_Pos) /*!< 0x00000020 */
#define USB_OTG_DCTL_TCTL_2                      (0x4UL << USB_OTG_DCTL_TCTL_Pos) /*!< 0x00000040 */
#define USB_OTG_DCTL_SGINAK_Pos                  (7U)                          
#define USB_OTG_DCTL_SGINAK_Msk                  (0x1UL << USB_OTG_DCTL_SGINAK_Pos) /*!< 0x00000080 */
#define USB_OTG_DCTL_SGINAK                      USB_OTG_DCTL_SGINAK_Msk       /*!< Set global IN NAK         */
#define USB_OTG_DCTL_CGINAK_Pos                  (8U)                          
#define USB_OTG_DCTL_CGINAK_Msk                  (0x1UL << USB_OTG_DCTL_CGINAK_Pos) /*!< 0x00000100 */
#define USB_OTG_DCTL_CGINAK                      USB_OTG_DCTL_CGINAK_Msk       /*!< Clear global IN NAK       */
#define USB_OTG_DCTL_SGONAK_Pos                  (9U)                          
#define USB_OTG_DCTL_SGONAK_Msk                  (0x1UL << USB_OTG_DCTL_SGONAK_Pos) /*!< 0x00000200 */
#define USB_OTG_DCTL_SGONAK                      USB_OTG_DCTL_SGONAK_Msk       /*!< Set global OUT NAK        */
#define USB_OTG_DCTL_CGONAK_Pos                  (10U)                         
#define USB_OTG_DCTL_CGONAK_Msk                  (0x1UL << USB_OTG_DCTL_CGONAK_Pos) /*!< 0x00000400 */
#define USB_OTG_DCTL_CGONAK                      USB_OTG_DCTL_CGONAK_Msk       /*!< Clear global OUT NAK      */
#define USB_OTG_DCTL_POPRGDNE_Pos                (11U)                         
#define USB_OTG_DCTL_POPRGDNE_Msk                (0x1UL << USB_OTG_DCTL_POPRGDNE_Pos) /*!< 0x00000800 */
#define USB_OTG_DCTL_POPRGDNE                    USB_OTG_DCTL_POPRGDNE_Msk     /*!< Power-on programming done */

/********************  Bit definition for USB_OTG_HFIR register  ********************/
#define USB_OTG_HFIR_FRIVL_Pos                   (0U)                          
#define USB_OTG_HFIR_FRIVL_Msk                   (0xFFFFUL << USB_OTG_HFIR_FRIVL_Pos) /*!< 0x0000FFFF */
#define USB_OTG_HFIR_FRIVL                       USB_OTG_HFIR_FRIVL_Msk        /*!< Frame interval */

/********************  Bit definition for USB_OTG_HFNUM register  ********************/
#define USB_OTG_HFNUM_FRNUM_Pos                  (0U)                          
#define USB_OTG_HFNUM_FRNUM_Msk                  (0xFFFFUL << USB_OTG_HFNUM_FRNUM_Pos) /*!< 0x0000FFFF */
#define USB_OTG_HFNUM_FRNUM                      USB_OTG_HFNUM_FRNUM_Msk       /*!< Frame number         */
#define USB_OTG_HFNUM_FTREM_Pos                  (16U)                         
#define USB_OTG_HFNUM_FTREM_Msk                  (0xFFFFUL << USB_OTG_HFNUM_FTREM_Pos) /*!< 0xFFFF0000 */
#define USB_OTG_HFNUM_FTREM                      USB_OTG_HFNUM_FTREM_Msk       /*!< Frame time remaining */

/********************  Bit definition for USB_OTG_DSTS register  ********************/
#define USB_OTG_DSTS_SUSPSTS_Pos                 (0U)                          
#define USB_OTG_DSTS_SUSPSTS_Msk                 (0x1UL << USB_OTG_DSTS_SUSPSTS_Pos) /*!< 0x00000001 */
#define USB_OTG_DSTS_SUSPSTS                     USB_OTG_DSTS_SUSPSTS_Msk      /*!< Suspend status   */

#define USB_OTG_DSTS_ENUMSPD_Pos                 (1U)                          
#define USB_OTG_DSTS_ENUMSPD_Msk                 (0x3UL << USB_OTG_DSTS_ENUMSPD_Pos) /*!< 0x00000006 */
#define USB_OTG_DSTS_ENUMSPD                     USB_OTG_DSTS_ENUMSPD_Msk      /*!< Enumerated speed */
#define USB_OTG_DSTS_ENUMSPD_0                   (0x1UL << USB_OTG_DSTS_ENUMSPD_Pos) /*!< 0x00000002 */
#define USB_OTG_DSTS_ENUMSPD_1                   (0x2UL << USB_OTG_DSTS_ENUMSPD_Pos) /*!< 0x00000004 */
#define USB_OTG_DSTS_EERR_Pos                    (3U)                          
#define USB_OTG_DSTS_EERR_Msk                    (0x1UL << USB_OTG_DSTS_EERR_Pos) /*!< 0x00000008 */
#define USB_OTG_DSTS_EERR                        USB_OTG_DSTS_EERR_Msk         /*!< Erratic error     */
#define USB_OTG_DSTS_FNSOF_Pos                   (8U)                          
#define USB_OTG_DSTS_FNSOF_Msk                   (0x3FFFUL << USB_OTG_DSTS_FNSOF_Pos) /*!< 0x003FFF00 */
#define USB_OTG_DSTS_FNSOF                       USB_OTG_DSTS_FNSOF_Msk        /*!< Frame number of the received SOF */

/********************  Bit definition for USB_OTG_GAHBCFG register  ********************/
#define USB_OTG_GAHBCFG_GINT_Pos                 (0U)                          
#define USB_OTG_GAHBCFG_GINT_Msk                 (0x1UL << USB_OTG_GAHBCFG_GINT_Pos) /*!< 0x00000001 */
#define USB_OTG_GAHBCFG_GINT                     USB_OTG_GAHBCFG_GINT_Msk      /*!< Global interrupt mask */
#define USB_OTG_GAHBCFG_HBSTLEN_Pos              (1U)                          
#define USB_OTG_GAHBCFG_HBSTLEN_Msk              (0xFUL << USB_OTG_GAHBCFG_HBSTLEN_Pos) /*!< 0x0000001E */
#define USB_OTG_GAHBCFG_HBSTLEN                  USB_OTG_GAHBCFG_HBSTLEN_Msk   /*!< Burst length/type */
#define USB_OTG_GAHBCFG_HBSTLEN_0                (0x0UL << USB_OTG_GAHBCFG_HBSTLEN_Pos) /*!< Single */
#define USB_OTG_GAHBCFG_HBSTLEN_1                (0x1UL << USB_OTG_GAHBCFG_HBSTLEN_Pos) /*!< INCR */
#define USB_OTG_GAHBCFG_HBSTLEN_2                (0x3UL << USB_OTG_GAHBCFG_HBSTLEN_Pos) /*!< INCR4 */
#define USB_OTG_GAHBCFG_HBSTLEN_3                (0x5UL << USB_OTG_GAHBCFG_HBSTLEN_Pos) /*!< INCR8 */
#define USB_OTG_GAHBCFG_HBSTLEN_4                (0x7UL << USB_OTG_GAHBCFG_HBSTLEN_Pos) /*!< INCR16 */
#define USB_OTG_GAHBCFG_DMAEN_Pos                (5U)                          
#define USB_OTG_GAHBCFG_DMAEN_Msk                (0x1UL << USB_OTG_GAHBCFG_DMAEN_Pos) /*!< 0x00000020 */
#define USB_OTG_GAHBCFG_DMAEN                    USB_OTG_GAHBCFG_DMAEN_Msk     /*!< DMA enable */
#define USB_OTG_GAHBCFG_TXFELVL_Pos              (7U)                          
#define USB_OTG_GAHBCFG_TXFELVL_Msk              (0x1UL << USB_OTG_GAHBCFG_TXFELVL_Pos) /*!< 0x00000080 */
#define USB_OTG_GAHBCFG_TXFELVL                  USB_OTG_GAHBCFG_TXFELVL_Msk   /*!< TxFIFO empty level */
#define USB_OTG_GAHBCFG_PTXFELVL_Pos             (8U)                          
#define USB_OTG_GAHBCFG_PTXFELVL_Msk             (0x1UL << USB_OTG_GAHBCFG_PTXFELVL_Pos) /*!< 0x00000100 */
#define USB_OTG_GAHBCFG_PTXFELVL                 USB_OTG_GAHBCFG_PTXFELVL_Msk  /*!< Periodic TxFIFO empty level */

/********************  Bit definition for USB_OTG_GUSBCFG register  ********************/

#define USB_OTG_GUSBCFG_TOCAL_Pos                (0U)                          
#define USB_OTG_GUSBCFG_TOCAL_Msk                (0x7UL << USB_OTG_GUSBCFG_TOCAL_Pos) /*!< 0x00000007 */
#define USB_OTG_GUSBCFG_TOCAL                    USB_OTG_GUSBCFG_TOCAL_Msk     /*!< FS timeout calibration */
#define USB_OTG_GUSBCFG_TOCAL_0                  (0x1UL << USB_OTG_GUSBCFG_TOCAL_Pos) /*!< 0x00000001 */
#define USB_OTG_GUSBCFG_TOCAL_1                  (0x2UL << USB_OTG_GUSBCFG_TOCAL_Pos) /*!< 0x00000002 */
#define USB_OTG_GUSBCFG_TOCAL_2                  (0x4UL << USB_OTG_GUSBCFG_TOCAL_Pos) /*!< 0x00000004 */
#define USB_OTG_GUSBCFG_PHYSEL_Pos               (6U)                          
#define USB_OTG_GUSBCFG_PHYSEL_Msk               (0x1UL << USB_OTG_GUSBCFG_PHYSEL_Pos) /*!< 0x00000040 */
#define USB_OTG_GUSBCFG_PHYSEL                   USB_OTG_GUSBCFG_PHYSEL_Msk    /*!< USB 2.0 high-speed ULPI PHY or USB 1.1 full-speed serial transceiver select */
#define USB_OTG_GUSBCFG_SRPCAP_Pos               (8U)                          
#define USB_OTG_GUSBCFG_SRPCAP_Msk               (0x1UL << USB_OTG_GUSBCFG_SRPCAP_Pos) /*!< 0x00000100 */
#define USB_OTG_GUSBCFG_SRPCAP                   USB_OTG_GUSBCFG_SRPCAP_Msk    /*!< SRP-capable */
#define USB_OTG_GUSBCFG_HNPCAP_Pos               (9U)                          
#define USB_OTG_GUSBCFG_HNPCAP_Msk               (0x1UL << USB_OTG_GUSBCFG_HNPCAP_Pos) /*!< 0x00000200 */
#define USB_OTG_GUSBCFG_HNPCAP                   USB_OTG_GUSBCFG_HNPCAP_Msk    /*!< HNP-capable */
#define USB_OTG_GUSBCFG_TRDT_Pos                 (10U)                         
#define USB_OTG_GUSBCFG_TRDT_Msk                 (0xFUL << USB_OTG_GUSBCFG_TRDT_Pos) /*!< 0x00003C00 */
#define USB_OTG_GUSBCFG_TRDT                     USB_OTG_GUSBCFG_TRDT_Msk      /*!< USB turnaround time */
#define USB_OTG_GUSBCFG_TRDT_0                   (0x1UL << USB_OTG_GUSBCFG_TRDT_Pos) /*!< 0x00000400 */
#define USB_OTG_GUSBCFG_TRDT_1                   (0x2UL << USB_OTG_GUSBCFG_TRDT_Pos) /*!< 0x00000800 */
#define USB_OTG_GUSBCFG_TRDT_2                   (0x4UL << USB_OTG_GUSBCFG_TRDT_Pos) /*!< 0x00001000 */
#define USB_OTG_GUSBCFG_TRDT_3                   (0x8UL << USB_OTG_GUSBCFG_TRDT_Pos) /*!< 0x00002000 */
#define USB_OTG_GUSBCFG_PHYLPCS_Pos              (15U)                         
#define USB_OTG_GUSBCFG_PHYLPCS_Msk              (0x1UL << USB_OTG_GUSBCFG_PHYLPCS_Pos) /*!< 0x00008000 */
#define USB_OTG_GUSBCFG_PHYLPCS                  USB_OTG_GUSBCFG_PHYLPCS_Msk   /*!< PHY Low-power clock select */
#define USB_OTG_GUSBCFG_ULPIFSLS_Pos             (17U)                         
#define USB_OTG_GUSBCFG_ULPIFSLS_Msk             (0x1UL << USB_OTG_GUSBCFG_ULPIFSLS_Pos) /*!< 0x00020000 */
#define USB_OTG_GUSBCFG_ULPIFSLS                 USB_OTG_GUSBCFG_ULPIFSLS_Msk  /*!< ULPI FS/LS select               */
#define USB_OTG_GUSBCFG_ULPIAR_Pos               (18U)                         
#define USB_OTG_GUSBCFG_ULPIAR_Msk               (0x1UL << USB_OTG_GUSBCFG_ULPIAR_Pos) /*!< 0x00040000 */
#define USB_OTG_GUSBCFG_ULPIAR                   USB_OTG_GUSBCFG_ULPIAR_Msk    /*!< ULPI Auto-resume                */
#define USB_OTG_GUSBCFG_ULPICSM_Pos              (19U)                         
#define USB_OTG_GUSBCFG_ULPICSM_Msk              (0x1UL << USB_OTG_GUSBCFG_ULPICSM_Pos) /*!< 0x00080000 */
#define USB_OTG_GUSBCFG_ULPICSM                  USB_OTG_GUSBCFG_ULPICSM_Msk   /*!< ULPI Clock SuspendM             */
#define USB_OTG_GUSBCFG_ULPIEVBUSD_Pos           (20U)                         
#define USB_OTG_GUSBCFG_ULPIEVBUSD_Msk           (0x1UL << USB_OTG_GUSBCFG_ULPIEVBUSD_Pos) /*!< 0x00100000 */
#define USB_OTG_GUSBCFG_ULPIEVBUSD               USB_OTG_GUSBCFG_ULPIEVBUSD_Msk /*!< ULPI External VBUS Drive        */
#define USB_OTG_GUSBCFG_ULPIEVBUSI_Pos           (21U)                         
#define USB_OTG_GUSBCFG_ULPIEVBUSI_Msk           (0x1UL << USB_OTG_GUSBCFG_ULPIEVBUSI_Pos) /*!< 0x00200000 */
#define USB_OTG_GUSBCFG_ULPIEVBUSI               USB_OTG_GUSBCFG_ULPIEVBUSI_Msk /*!< ULPI external VBUS indicator    */
#define USB_OTG_GUSBCFG_TSDPS_Pos                (22U)                         
#define USB_OTG_GUSBCFG_TSDPS_Msk                (0x1UL << USB_OTG_GUSBCFG_TSDPS_Pos) /*!< 0x00400000 */
#define USB_OTG_GUSBCFG_TSDPS                    USB_OTG_GUSBCFG_TSDPS_Msk     /*!< TermSel DLine pulsing selection */
#define USB_OTG_GUSBCFG_PCCI_Pos                 (23U)                         
#define USB_OTG_GUSBCFG_PCCI_Msk                 (0x1UL << USB_OTG_GUSBCFG_PCCI_Pos) /*!< 0x00800000 */
#define USB_OTG_GUSBCFG_PCCI                     USB_OTG_GUSBCFG_PCCI_Msk      /*!< Indicator complement            */
#define USB_OTG_GUSBCFG_PTCI_Pos                 (24U)                         
#define USB_OTG_GUSBCFG_PTCI_Msk                 (0x1UL << USB_OTG_GUSBCFG_PTCI_Pos) /*!< 0x01000000 */
#define USB_OTG_GUSBCFG_PTCI                     USB_OTG_GUSBCFG_PTCI_Msk      /*!< Indicator pass through          */
#define USB_OTG_GUSBCFG_ULPIIPD_Pos              (25U)                         
#define USB_OTG_GUSBCFG_ULPIIPD_Msk              (0x1UL << USB_OTG_GUSBCFG_ULPIIPD_Pos) /*!< 0x02000000 */
#define USB_OTG_GUSBCFG_ULPIIPD                  USB_OTG_GUSBCFG_ULPIIPD_Msk   /*!< ULPI interface protect disable  */
#define USB_OTG_GUSBCFG_FHMOD_Pos                (29U)                         
#define USB_OTG_GUSBCFG_FHMOD_Msk                (0x1UL << USB_OTG_GUSBCFG_FHMOD_Pos) /*!< 0x20000000 */
#define USB_OTG_GUSBCFG_FHMOD                    USB_OTG_GUSBCFG_FHMOD_Msk     /*!< Forced host mode                */
#define USB_OTG_GUSBCFG_FDMOD_Pos                (30U)                         
#define USB_OTG_GUSBCFG_FDMOD_Msk                (0x1UL << USB_OTG_GUSBCFG_FDMOD_Pos) /*!< 0x40000000 */
#define USB_OTG_GUSBCFG_FDMOD                    USB_OTG_GUSBCFG_FDMOD_Msk     /*!< Forced peripheral mode          */
#define USB_OTG_GUSBCFG_CTXPKT_Pos               (31U)                         
#define USB_OTG_GUSBCFG_CTXPKT_Msk               (0x1UL << USB_OTG_GUSBCFG_CTXPKT_Pos) /*!< 0x80000000 */
#define USB_OTG_GUSBCFG_CTXPKT                   USB_OTG_GUSBCFG_CTXPKT_Msk    /*!< Corrupt Tx packet               */

/********************  Bit definition for USB_OTG_GRSTCTL register  ********************/
#define USB_OTG_GRSTCTL_CSRST_Pos                (0U)                          
#define USB_OTG_GRSTCTL_CSRST_Msk                (0x1UL << USB_OTG_GRSTCTL_CSRST_Pos) /*!< 0x00000001 */
#define USB_OTG_GRSTCTL_CSRST                    USB_OTG_GRSTCTL_CSRST_Msk     /*!< Core soft reset          */
#define USB_OTG_GRSTCTL_HSRST_Pos                (1U)                          
#define USB_OTG_GRSTCTL_HSRST_Msk                (0x1UL << USB_OTG_GRSTCTL_HSRST_Pos) /*!< 0x00000002 */
#define USB_OTG_GRSTCTL_HSRST                    USB_OTG_GRSTCTL_HSRST_Msk     /*!< HCLK soft reset          */
#define USB_OTG_GRSTCTL_FCRST_Pos                (2U)                          
#define USB_OTG_GRSTCTL_FCRST_Msk                (0x1UL << USB_OTG_GRSTCTL_FCRST_Pos) /*!< 0x00000004 */
#define USB_OTG_GRSTCTL_FCRST                    USB_OTG_GRSTCTL_FCRST_Msk     /*!< Host frame counter reset */
#define USB_OTG_GRSTCTL_RXFFLSH_Pos              (4U)                          
#define USB_OTG_GRSTCTL_RXFFLSH_Msk              (0x1UL << USB_OTG_GRSTCTL_RXFFLSH_Pos) /*!< 0x00000010 */
#define USB_OTG_GRSTCTL_RXFFLSH                  USB_OTG_GRSTCTL_RXFFLSH_Msk   /*!< RxFIFO flush             */
#define USB_OTG_GRSTCTL_TXFFLSH_Pos              (5U)                          
#define USB_OTG_GRSTCTL_TXFFLSH_Msk              (0x1UL << USB_OTG_GRSTCTL_TXFFLSH_Pos) /*!< 0x00000020 */
#define USB_OTG_GRSTCTL_TXFFLSH                  USB_OTG_GRSTCTL_TXFFLSH_Msk   /*!< TxFIFO flush             */


#define USB_OTG_GRSTCTL_TXFNUM_Pos               (6U)                          
#define USB_OTG_GRSTCTL_TXFNUM_Msk               (0x1FUL << USB_OTG_GRSTCTL_TXFNUM_Pos) /*!< 0x000007C0 */
#define USB_OTG_GRSTCTL_TXFNUM                   USB_OTG_GRSTCTL_TXFNUM_Msk    /*!< TxFIFO number */
#define USB_OTG_GRSTCTL_TXFNUM_0                 (0x01UL << USB_OTG_GRSTCTL_TXFNUM_Pos) /*!< 0x00000040 */
#define USB_OTG_GRSTCTL_TXFNUM_1                 (0x02UL << USB_OTG_GRSTCTL_TXFNUM_Pos) /*!< 0x00000080 */
#define USB_OTG_GRSTCTL_TXFNUM_2                 (0x04UL << USB_OTG_GRSTCTL_TXFNUM_Pos) /*!< 0x00000100 */
#define USB_OTG_GRSTCTL_TXFNUM_3                 (0x08UL << USB_OTG_GRSTCTL_TXFNUM_Pos) /*!< 0x00000200 */
#define USB_OTG_GRSTCTL_TXFNUM_4                 (0x10UL << USB_OTG_GRSTCTL_TXFNUM_Pos) /*!< 0x00000400 */
#define USB_OTG_GRSTCTL_DMAREQ_Pos               (30U)                         
#define USB_OTG_GRSTCTL_DMAREQ_Msk               (0x1UL << USB_OTG_GRSTCTL_DMAREQ_Pos) /*!< 0x40000000 */
#define USB_OTG_GRSTCTL_DMAREQ                   USB_OTG_GRSTCTL_DMAREQ_Msk    /*!< DMA request signal */
#define USB_OTG_GRSTCTL_AHBIDL_Pos               (31U)                         
#define USB_OTG_GRSTCTL_AHBIDL_Msk               (0x1UL << USB_OTG_GRSTCTL_AHBIDL_Pos) /*!< 0x80000000 */
#define USB_OTG_GRSTCTL_AHBIDL                   USB_OTG_GRSTCTL_AHBIDL_Msk    /*!< AHB master idle */

/********************  Bit definition for USB_OTG_DIEPMSK register  ********************/
#define USB_OTG_DIEPMSK_XFRCM_Pos                (0U)                          
#define USB_OTG_DIEPMSK_XFRCM_Msk                (0x1UL << USB_OTG_DIEPMSK_XFRCM_Pos) /*!< 0x00000001 */
#define USB_OTG_DIEPMSK_XFRCM                    USB_OTG_DIEPMSK_XFRCM_Msk     /*!< Transfer completed interrupt mask                 */
#define USB_OTG_DIEPMSK_EPDM_Pos                 (1U)                          
#define USB_OTG_DIEPMSK_EPDM_Msk                 (0x1UL << USB_OTG_DIEPMSK_EPDM_Pos) /*!< 0x00000002 */
#define USB_OTG_DIEPMSK_EPDM                     USB_OTG_DIEPMSK_EPDM_Msk      /*!< Endpoint disabled interrupt mask                  */
#define USB_OTG_DIEPMSK_TOM_Pos                  (3U)                          
#define USB_OTG_DIEPMSK_TOM_Msk                  (0x1UL << USB_OTG_DIEPMSK_TOM_Pos) /*!< 0x00000008 */
#define USB_OTG_DIEPMSK_TOM                      USB_OTG_DIEPMSK_TOM_Msk       /*!< Timeout condition mask (nonisochronous endpoints) */
#define USB_OTG_DIEPMSK_ITTXFEMSK_Pos            (4U)                          
#define USB_OTG_DIEPMSK_ITTXFEMSK_Msk            (0x1UL << USB_OTG_DIEPMSK_ITTXFEMSK_Pos) /*!< 0x00000010 */
#define USB_OTG_DIEPMSK_ITTXFEMSK                USB_OTG_DIEPMSK_ITTXFEMSK_Msk /*!< IN token received when TxFIFO empty mask          */
#define USB_OTG_DIEPMSK_INEPNMM_Pos              (5U)                          
#define USB_OTG_DIEPMSK_INEPNMM_Msk              (0x1UL << USB_OTG_DIEPMSK_INEPNMM_Pos) /*!< 0x00000020 */
#define USB_OTG_DIEPMSK_INEPNMM                  USB_OTG_DIEPMSK_INEPNMM_Msk   /*!< IN token received with EP mismatch mask           */
#define USB_OTG_DIEPMSK_INEPNEM_Pos              (6U)                          
#define USB_OTG_DIEPMSK_INEPNEM_Msk              (0x1UL << USB_OTG_DIEPMSK_INEPNEM_Pos) /*!< 0x00000040 */
#define USB_OTG_DIEPMSK_INEPNEM                  USB_OTG_DIEPMSK_INEPNEM_Msk   /*!< IN endpoint NAK effective mask                    */
#define USB_OTG_DIEPMSK_TXFURM_Pos               (8U)                          
#define USB_OTG_DIEPMSK_TXFURM_Msk               (0x1UL << USB_OTG_DIEPMSK_TXFURM_Pos) /*!< 0x00000100 */
#define USB_OTG_DIEPMSK_TXFURM                   USB_OTG_DIEPMSK_TXFURM_Msk    /*!< FIFO underrun mask                                */
#define USB_OTG_DIEPMSK_BIM_Pos                  (9U)                          
#define USB_OTG_DIEPMSK_BIM_Msk                  (0x1UL << USB_OTG_DIEPMSK_BIM_Pos) /*!< 0x00000200 */
#define USB_OTG_DIEPMSK_BIM                      USB_OTG_DIEPMSK_BIM_Msk       /*!< BNA interrupt mask                                */

/********************  Bit definition for USB_OTG_HPTXSTS register  ********************/
#define USB_OTG_HPTXSTS_PTXFSAVL_Pos             (0U)                          
#define USB_OTG_HPTXSTS_PTXFSAVL_Msk             (0xFFFFUL << USB_OTG_HPTXSTS_PTXFSAVL_Pos) /*!< 0x0000FFFF */
#define USB_OTG_HPTXSTS_PTXFSAVL                 USB_OTG_HPTXSTS_PTXFSAVL_Msk  /*!< Periodic transmit data FIFO space available     */
#define USB_OTG_HPTXSTS_PTXQSAV_Pos              (16U)                         
#define USB_OTG_HPTXSTS_PTXQSAV_Msk              (0xFFUL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00FF0000 */
#define USB_OTG_HPTXSTS_PTXQSAV                  USB_OTG_HPTXSTS_PTXQSAV_Msk   /*!< Periodic transmit request queue space available */
#define USB_OTG_HPTXSTS_PTXQSAV_0                (0x01UL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00010000 */
#define USB_OTG_HPTXSTS_PTXQSAV_1                (0x02UL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00020000 */
#define USB_OTG_HPTXSTS_PTXQSAV_2                (0x04UL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00040000 */
#define USB_OTG_HPTXSTS_PTXQSAV_3                (0x08UL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00080000 */
#define USB_OTG_HPTXSTS_PTXQSAV_4                (0x10UL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00100000 */
#define USB_OTG_HPTXSTS_PTXQSAV_5                (0x20UL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00200000 */
#define USB_OTG_HPTXSTS_PTXQSAV_6                (0x40UL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00400000 */
#define USB_OTG_HPTXSTS_PTXQSAV_7                (0x80UL << USB_OTG_HPTXSTS_PTXQSAV_Pos) /*!< 0x00800000 */

#define USB_OTG_HPTXSTS_PTXQTOP_Pos              (24U)                         
#define USB_OTG_HPTXSTS_PTXQTOP_Msk              (0xFFUL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0xFF000000 */
#define USB_OTG_HPTXSTS_PTXQTOP                  USB_OTG_HPTXSTS_PTXQTOP_Msk   /*!< Top of the periodic transmit request queue */
#define USB_OTG_HPTXSTS_PTXQTOP_0                (0x01UL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0x01000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_1                (0x02UL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0x02000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_2                (0x04UL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0x04000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_3                (0x08UL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0x08000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_4                (0x10UL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0x10000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_5                (0x20UL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0x20000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_6                (0x40UL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0x40000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_7                (0x80UL << USB_OTG_HPTXSTS_PTXQTOP_Pos) /*!< 0x80000000 */

/********************  Bit definition for USB_OTG_HAINT register  ********************/
#define USB_OTG_HAINT_HAINT_Pos                  (0U)                          
#define USB_OTG_HAINT_HAINT_Msk                  (0xFFFFUL << USB_OTG_HAINT_HAINT_Pos) /*!< 0x0000FFFF */
#define USB_OTG_HAINT_HAINT                      USB_OTG_HAINT_HAINT_Msk       /*!< Channel interrupts */

/********************  Bit definition for USB_OTG_DOEPMSK register  ********************/
#define USB_OTG_DOEPMSK_XFRCM_Pos                (0U)                          
#define USB_OTG_DOEPMSK_XFRCM_Msk                (0x1UL << USB_OTG_DOEPMSK_XFRCM_Pos) /*!< 0x00000001 */
#define USB_OTG_DOEPMSK_XFRCM                    USB_OTG_DOEPMSK_XFRCM_Msk     /*!< Transfer completed interrupt mask              */
#define USB_OTG_DOEPMSK_EPDM_Pos                 (1U)                          
#define USB_OTG_DOEPMSK_EPDM_Msk                 (0x1UL << USB_OTG_DOEPMSK_EPDM_Pos) /*!< 0x00000002 */
#define USB_OTG_DOEPMSK_EPDM                     USB_OTG_DOEPMSK_EPDM_Msk      /*!< Endpoint disabled interrupt mask               */
#define USB_OTG_DOEPMSK_AHBERRM_Pos              (2U)
#define USB_OTG_DOEPMSK_AHBERRM_Msk              (0x1UL << USB_OTG_DOEPMSK_AHBERRM_Pos) /*!< 0x00000004 */
#define USB_OTG_DOEPMSK_AHBERRM                  USB_OTG_DOEPMSK_AHBERRM_Msk   /*!< OUT transaction AHB Error interrupt mask       */
#define USB_OTG_DOEPMSK_STUPM_Pos                (3U)                          
#define USB_OTG_DOEPMSK_STUPM_Msk                (0x1UL << USB_OTG_DOEPMSK_STUPM_Pos) /*!< 0x00000008 */
#define USB_OTG_DOEPMSK_STUPM                    USB_OTG_DOEPMSK_STUPM_Msk     /*!< SETUP phase done mask                          */
#define USB_OTG_DOEPMSK_OTEPDM_Pos               (4U)                          
#define USB_OTG_DOEPMSK_OTEPDM_Msk               (0x1UL << USB_OTG_DOEPMSK_OTEPDM_Pos) /*!< 0x00000010 */
#define USB_OTG_DOEPMSK_OTEPDM                   USB_OTG_DOEPMSK_OTEPDM_Msk    /*!< OUT token received when endpoint disabled mask */
#define USB_OTG_DOEPMSK_OTEPSPRM_Pos             (5U)                          
#define USB_OTG_DOEPMSK_OTEPSPRM_Msk             (0x1UL << USB_OTG_DOEPMSK_OTEPSPRM_Pos) /*!< 0x00000020 */
#define USB_OTG_DOEPMSK_OTEPSPRM                 USB_OTG_DOEPMSK_OTEPSPRM_Msk  /*!< Status Phase Received mask                     */
#define USB_OTG_DOEPMSK_B2BSTUP_Pos              (6U)                          
#define USB_OTG_DOEPMSK_B2BSTUP_Msk              (0x1UL << USB_OTG_DOEPMSK_B2BSTUP_Pos) /*!< 0x00000040 */
#define USB_OTG_DOEPMSK_B2BSTUP                  USB_OTG_DOEPMSK_B2BSTUP_Msk   /*!< Back-to-back SETUP packets received mask       */
#define USB_OTG_DOEPMSK_OPEM_Pos                 (8U)                          
#define USB_OTG_DOEPMSK_OPEM_Msk                 (0x1UL << USB_OTG_DOEPMSK_OPEM_Pos) /*!< 0x00000100 */
#define USB_OTG_DOEPMSK_OPEM                     USB_OTG_DOEPMSK_OPEM_Msk      /*!< OUT packet error mask                          */
#define USB_OTG_DOEPMSK_BOIM_Pos                 (9U)                          
#define USB_OTG_DOEPMSK_BOIM_Msk                 (0x1UL << USB_OTG_DOEPMSK_BOIM_Pos) /*!< 0x00000200 */
#define USB_OTG_DOEPMSK_BOIM                     USB_OTG_DOEPMSK_BOIM_Msk      /*!< BNA interrupt mask                             */
#define USB_OTG_DOEPMSK_BERRM_Pos                (12U)
#define USB_OTG_DOEPMSK_BERRM_Msk                (0x1UL << USB_OTG_DOEPMSK_BERRM_Pos) /*!< 0x00001000 */
#define USB_OTG_DOEPMSK_BERRM                    USB_OTG_DOEPMSK_BERRM_Msk      /*!< Babble error interrupt mask                   */
#define USB_OTG_DOEPMSK_NAKM_Pos                 (13U)
#define USB_OTG_DOEPMSK_NAKM_Msk                 (0x1UL << USB_OTG_DOEPMSK_NAKM_Pos) /*!< 0x00002000 */
#define USB_OTG_DOEPMSK_NAKM                     USB_OTG_DOEPMSK_NAKM_Msk      /*!< OUT Packet NAK interrupt mask                  */
#define USB_OTG_DOEPMSK_NYETM_Pos                (14U)
#define USB_OTG_DOEPMSK_NYETM_Msk                (0x1UL << USB_OTG_DOEPMSK_NYETM_Pos) /*!< 0x00004000 */
#define USB_OTG_DOEPMSK_NYETM                    USB_OTG_DOEPMSK_NYETM_Msk     /*!< NYET interrupt mask                            */
/********************  Bit definition for USB_OTG_GINTSTS register  ********************/
#define USB_OTG_GINTSTS_CMOD_Pos                 (0U)                          
#define USB_OTG_GINTSTS_CMOD_Msk                 (0x1UL << USB_OTG_GINTSTS_CMOD_Pos) /*!< 0x00000001 */
#define USB_OTG_GINTSTS_CMOD                     USB_OTG_GINTSTS_CMOD_Msk      /*!< Current mode of operation                      */
#define USB_OTG_GINTSTS_MMIS_Pos                 (1U)                          
#define USB_OTG_GINTSTS_MMIS_Msk                 (0x1UL << USB_OTG_GINTSTS_MMIS_Pos) /*!< 0x00000002 */
#define USB_OTG_GINTSTS_MMIS                     USB_OTG_GINTSTS_MMIS_Msk      /*!< Mode mismatch interrupt                        */
#define USB_OTG_GINTSTS_OTGINT_Pos               (2U)                          
#define USB_OTG_GINTSTS_OTGINT_Msk               (0x1UL << USB_OTG_GINTSTS_OTGINT_Pos) /*!< 0x00000004 */
#define USB_OTG_GINTSTS_OTGINT                   USB_OTG_GINTSTS_OTGINT_Msk    /*!< OTG interrupt                                  */
#define USB_OTG_GINTSTS_SOF_Pos                  (3U)                          
#define USB_OTG_GINTSTS_SOF_Msk                  (0x1UL << USB_OTG_GINTSTS_SOF_Pos) /*!< 0x00000008 */
#define USB_OTG_GINTSTS_SOF                      USB_OTG_GINTSTS_SOF_Msk       /*!< Start of frame                                 */
#define USB_OTG_GINTSTS_RXFLVL_Pos               (4U)                          
#define USB_OTG_GINTSTS_RXFLVL_Msk               (0x1UL << USB_OTG_GINTSTS_RXFLVL_Pos) /*!< 0x00000010 */
#define USB_OTG_GINTSTS_RXFLVL                   USB_OTG_GINTSTS_RXFLVL_Msk    /*!< RxFIFO nonempty                                */
#define USB_OTG_GINTSTS_NPTXFE_Pos               (5U)                          
#define USB_OTG_GINTSTS_NPTXFE_Msk               (0x1UL << USB_OTG_GINTSTS_NPTXFE_Pos) /*!< 0x00000020 */
#define USB_OTG_GINTSTS_NPTXFE                   USB_OTG_GINTSTS_NPTXFE_Msk    /*!< Nonperiodic TxFIFO empty                       */
#define USB_OTG_GINTSTS_GINAKEFF_Pos             (6U)                          
#define USB_OTG_GINTSTS_GINAKEFF_Msk             (0x1UL << USB_OTG_GINTSTS_GINAKEFF_Pos) /*!< 0x00000040 */
#define USB_OTG_GINTSTS_GINAKEFF                 USB_OTG_GINTSTS_GINAKEFF_Msk  /*!< Global IN nonperiodic NAK effective            */
#define USB_OTG_GINTSTS_BOUTNAKEFF_Pos           (7U)                          
#define USB_OTG_GINTSTS_BOUTNAKEFF_Msk           (0x1UL << USB_OTG_GINTSTS_BOUTNAKEFF_Pos) /*!< 0x00000080 */
#define USB_OTG_GINTSTS_BOUTNAKEFF               USB_OTG_GINTSTS_BOUTNAKEFF_Msk /*!< Global OUT NAK effective                       */
#define USB_OTG_GINTSTS_ESUSP_Pos                (10U)                         
#define USB_OTG_GINTSTS_ESUSP_Msk                (0x1UL << USB_OTG_GINTSTS_ESUSP_Pos) /*!< 0x00000400 */
#define USB_OTG_GINTSTS_ESUSP                    USB_OTG_GINTSTS_ESUSP_Msk     /*!< Early suspend                                  */
#define USB_OTG_GINTSTS_USBSUSP_Pos              (11U)                         
#define USB_OTG_GINTSTS_USBSUSP_Msk              (0x1UL << USB_OTG_GINTSTS_USBSUSP_Pos) /*!< 0x00000800 */
#define USB_OTG_GINTSTS_USBSUSP                  USB_OTG_GINTSTS_USBSUSP_Msk   /*!< USB suspend                                    */
#define USB_OTG_GINTSTS_USBRST_Pos               (12U)                         
#define USB_OTG_GINTSTS_USBRST_Msk               (0x1UL << USB_OTG_GINTSTS_USBRST_Pos) /*!< 0x00001000 */
#define USB_OTG_GINTSTS_USBRST                   USB_OTG_GINTSTS_USBRST_Msk    /*!< USB reset                                      */
#define USB_OTG_GINTSTS_ENUMDNE_Pos              (13U)                         
#define USB_OTG_GINTSTS_ENUMDNE_Msk              (0x1UL << USB_OTG_GINTSTS_ENUMDNE_Pos) /*!< 0x00002000 */
#define USB_OTG_GINTSTS_ENUMDNE                  USB_OTG_GINTSTS_ENUMDNE_Msk   /*!< Enumeration done                               */
#define USB_OTG_GINTSTS_ISOODRP_Pos              (14U)                         
#define USB_OTG_GINTSTS_ISOODRP_Msk              (0x1UL << USB_OTG_GINTSTS_ISOODRP_Pos) /*!< 0x00004000 */
#define USB_OTG_GINTSTS_ISOODRP                  USB_OTG_GINTSTS_ISOODRP_Msk   /*!< Isochronous OUT packet dropped interrupt       */
#define USB_OTG_GINTSTS_EOPF_Pos                 (15U)                         
#define USB_OTG_GINTSTS_EOPF_Msk                 (0x1UL << USB_OTG_GINTSTS_EOPF_Pos) /*!< 0x00008000 */
#define USB_OTG_GINTSTS_EOPF                     USB_OTG_GINTSTS_EOPF_Msk      /*!< End of periodic frame interrupt                */
#define USB_OTG_GINTSTS_IEPINT_Pos               (18U)                         
#define USB_OTG_GINTSTS_IEPINT_Msk               (0x1UL << USB_OTG_GINTSTS_IEPINT_Pos) /*!< 0x00040000 */
#define USB_OTG_GINTSTS_IEPINT                   USB_OTG_GINTSTS_IEPINT_Msk    /*!< IN endpoint interrupt                          */
#define USB_OTG_GINTSTS_OEPINT_Pos               (19U)                         
#define USB_OTG_GINTSTS_OEPINT_Msk               (0x1UL << USB_OTG_GINTSTS_OEPINT_Pos) /*!< 0x00080000 */
#define USB_OTG_GINTSTS_OEPINT                   USB_OTG_GINTSTS_OEPINT_Msk    /*!< OUT endpoint interrupt                         */
#define USB_OTG_GINTSTS_IISOIXFR_Pos             (20U)                         
#define USB_OTG_GINTSTS_IISOIXFR_Msk             (0x1UL << USB_OTG_GINTSTS_IISOIXFR_Pos) /*!< 0x00100000 */
#define USB_OTG_GINTSTS_IISOIXFR                 USB_OTG_GINTSTS_IISOIXFR_Msk  /*!< Incomplete isochronous IN transfer             */
#define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT_Pos    (21U)                         
#define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT_Msk    (0x1UL << USB_OTG_GINTSTS_PXFR_INCOMPISOOUT_Pos) /*!< 0x00200000 */
#define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT        USB_OTG_GINTSTS_PXFR_INCOMPISOOUT_Msk /*!< Incomplete periodic transfer                   */
#define USB_OTG_GINTSTS_DATAFSUSP_Pos            (22U)                         
#define USB_OTG_GINTSTS_DATAFSUSP_Msk            (0x1UL << USB_OTG_GINTSTS_DATAFSUSP_Pos) /*!< 0x00400000 */
#define USB_OTG_GINTSTS_DATAFSUSP                USB_OTG_GINTSTS_DATAFSUSP_Msk /*!< Data fetch suspended                           */
#define USB_OTG_GINTSTS_HPRTINT_Pos              (24U)                         
#define USB_OTG_GINTSTS_HPRTINT_Msk              (0x1UL << USB_OTG_GINTSTS_HPRTINT_Pos) /*!< 0x01000000 */
#define USB_OTG_GINTSTS_HPRTINT                  USB_OTG_GINTSTS_HPRTINT_Msk   /*!< Host port interrupt                            */
#define USB_OTG_GINTSTS_HCINT_Pos                (25U)                         
#define USB_OTG_GINTSTS_HCINT_Msk                (0x1UL << USB_OTG_GINTSTS_HCINT_Pos) /*!< 0x02000000 */
#define USB_OTG_GINTSTS_HCINT                    USB_OTG_GINTSTS_HCINT_Msk     /*!< Host channels interrupt                        */
#define USB_OTG_GINTSTS_PTXFE_Pos                (26U)                         
#define USB_OTG_GINTSTS_PTXFE_Msk                (0x1UL << USB_OTG_GINTSTS_PTXFE_Pos) /*!< 0x04000000 */
#define USB_OTG_GINTSTS_PTXFE                    USB_OTG_GINTSTS_PTXFE_Msk     /*!< Periodic TxFIFO empty                          */
#define USB_OTG_GINTSTS_CIDSCHG_Pos              (28U)                         
#define USB_OTG_GINTSTS_CIDSCHG_Msk              (0x1UL << USB_OTG_GINTSTS_CIDSCHG_Pos) /*!< 0x10000000 */
#define USB_OTG_GINTSTS_CIDSCHG                  USB_OTG_GINTSTS_CIDSCHG_Msk   /*!< Connector ID status change                     */
#define USB_OTG_GINTSTS_DISCINT_Pos              (29U)                         
#define USB_OTG_GINTSTS_DISCINT_Msk              (0x1UL << USB_OTG_GINTSTS_DISCINT_Pos) /*!< 0x20000000 */
#define USB_OTG_GINTSTS_DISCINT                  USB_OTG_GINTSTS_DISCINT_Msk   /*!< Disconnect detected interrupt                  */
#define USB_OTG_GINTSTS_SRQINT_Pos               (30U)                         
#define USB_OTG_GINTSTS_SRQINT_Msk               (0x1UL << USB_OTG_GINTSTS_SRQINT_Pos) /*!< 0x40000000 */
#define USB_OTG_GINTSTS_SRQINT                   USB_OTG_GINTSTS_SRQINT_Msk    /*!< Session request/new session detected interrupt */
#define USB_OTG_GINTSTS_WKUINT_Pos               (31U)                         
#define USB_OTG_GINTSTS_WKUINT_Msk               (0x1UL << USB_OTG_GINTSTS_WKUINT_Pos) /*!< 0x80000000 */
#define USB_OTG_GINTSTS_WKUINT                   USB_OTG_GINTSTS_WKUINT_Msk    /*!< Resume/remote wakeup detected interrupt        */

/********************  Bit definition for USB_OTG_GINTMSK register  ********************/
#define USB_OTG_GINTMSK_MMISM_Pos                (1U)                          
#define USB_OTG_GINTMSK_MMISM_Msk                (0x1UL << USB_OTG_GINTMSK_MMISM_Pos) /*!< 0x00000002 */
#define USB_OTG_GINTMSK_MMISM                    USB_OTG_GINTMSK_MMISM_Msk     /*!< Mode mismatch interrupt mask                        */
#define USB_OTG_GINTMSK_OTGINT_Pos               (2U)                          
#define USB_OTG_GINTMSK_OTGINT_Msk               (0x1UL << USB_OTG_GINTMSK_OTGINT_Pos) /*!< 0x00000004 */
#define USB_OTG_GINTMSK_OTGINT                   USB_OTG_GINTMSK_OTGINT_Msk    /*!< OTG interrupt mask                                  */
#define USB_OTG_GINTMSK_SOFM_Pos                 (3U)                          
#define USB_OTG_GINTMSK_SOFM_Msk                 (0x1UL << USB_OTG_GINTMSK_SOFM_Pos) /*!< 0x00000008 */
#define USB_OTG_GINTMSK_SOFM                     USB_OTG_GINTMSK_SOFM_Msk      /*!< Start of frame mask                                 */
#define USB_OTG_GINTMSK_RXFLVLM_Pos              (4U)                          
#define USB_OTG_GINTMSK_RXFLVLM_Msk              (0x1UL << USB_OTG_GINTMSK_RXFLVLM_Pos) /*!< 0x00000010 */
#define USB_OTG_GINTMSK_RXFLVLM                  USB_OTG_GINTMSK_RXFLVLM_Msk   /*!< Receive FIFO nonempty mask                          */
#define USB_OTG_GINTMSK_NPTXFEM_Pos              (5U)                          
#define USB_OTG_GINTMSK_NPTXFEM_Msk              (0x1UL << USB_OTG_GINTMSK_NPTXFEM_Pos) /*!< 0x00000020 */
#define USB_OTG_GINTMSK_NPTXFEM                  USB_OTG_GINTMSK_NPTXFEM_Msk   /*!< Nonperiodic TxFIFO empty mask                       */
#define USB_OTG_GINTMSK_GINAKEFFM_Pos            (6U)                          
#define USB_OTG_GINTMSK_GINAKEFFM_Msk            (0x1UL << USB_OTG_GINTMSK_GINAKEFFM_Pos) /*!< 0x00000040 */
#define USB_OTG_GINTMSK_GINAKEFFM                USB_OTG_GINTMSK_GINAKEFFM_Msk /*!< Global nonperiodic IN NAK effective mask            */
#define USB_OTG_GINTMSK_GONAKEFFM_Pos            (7U)                          
#define USB_OTG_GINTMSK_GONAKEFFM_Msk            (0x1UL << USB_OTG_GINTMSK_GONAKEFFM_Pos) /*!< 0x00000080 */
#define USB_OTG_GINTMSK_GONAKEFFM                USB_OTG_GINTMSK_GONAKEFFM_Msk /*!< Global OUT NAK effective mask                       */
#define USB_OTG_GINTMSK_ESUSPM_Pos               (10U)                         
#define USB_OTG_GINTMSK_ESUSPM_Msk               (0x1UL << USB_OTG_GINTMSK_ESUSPM_Pos) /*!< 0x00000400 */
#define USB_OTG_GINTMSK_ESUSPM                   USB_OTG_GINTMSK_ESUSPM_Msk    /*!< Early suspend mask                                  */
#define USB_OTG_GINTMSK_USBSUSPM_Pos             (11U)                         
#define USB_OTG_GINTMSK_USBSUSPM_Msk             (0x1UL << USB_OTG_GINTMSK_USBSUSPM_Pos) /*!< 0x00000800 */
#define USB_OTG_GINTMSK_USBSUSPM                 USB_OTG_GINTMSK_USBSUSPM_Msk  /*!< USB suspend mask                                    */
#define USB_OTG_GINTMSK_USBRST_Pos               (12U)                         
#define USB_OTG_GINTMSK_USBRST_Msk               (0x1UL << USB_OTG_GINTMSK_USBRST_Pos) /*!< 0x00001000 */
#define USB_OTG_GINTMSK_USBRST                   USB_OTG_GINTMSK_USBRST_Msk    /*!< USB reset mask                                      */
#define USB_OTG_GINTMSK_ENUMDNEM_Pos             (13U)                         
#define USB_OTG_GINTMSK_ENUMDNEM_Msk             (0x1UL << USB_OTG_GINTMSK_ENUMDNEM_Pos) /*!< 0x00002000 */
#define USB_OTG_GINTMSK_ENUMDNEM                 USB_OTG_GINTMSK_ENUMDNEM_Msk  /*!< Enumeration done mask                               */
#define USB_OTG_GINTMSK_ISOODRPM_Pos             (14U)                         
#define USB_OTG_GINTMSK_ISOODRPM_Msk             (0x1UL << USB_OTG_GINTMSK_ISOODRPM_Pos) /*!< 0x00004000 */
#define USB_OTG_GINTMSK_ISOODRPM                 USB_OTG_GINTMSK_ISOODRPM_Msk  /*!< Isochronous OUT packet dropped interrupt mask       */
#define USB_OTG_GINTMSK_EOPFM_Pos                (15U)                         
#define USB_OTG_GINTMSK_EOPFM_Msk                (0x1UL << USB_OTG_GINTMSK_EOPFM_Pos) /*!< 0x00008000 */
#define USB_OTG_GINTMSK_EOPFM                    USB_OTG_GINTMSK_EOPFM_Msk     /*!< End of periodic frame interrupt mask                */
#define USB_OTG_GINTMSK_EPMISM_Pos               (17U)                         
#define USB_OTG_GINTMSK_EPMISM_Msk               (0x1UL << USB_OTG_GINTMSK_EPMISM_Pos) /*!< 0x00020000 */
#define USB_OTG_GINTMSK_EPMISM                   USB_OTG_GINTMSK_EPMISM_Msk    /*!< Endpoint mismatch interrupt mask                    */
#define USB_OTG_GINTMSK_IEPINT_Pos               (18U)                         
#define USB_OTG_GINTMSK_IEPINT_Msk               (0x1UL << USB_OTG_GINTMSK_IEPINT_Pos) /*!< 0x00040000 */
#define USB_OTG_GINTMSK_IEPINT                   USB_OTG_GINTMSK_IEPINT_Msk    /*!< IN endpoints interrupt mask                         */
#define USB_OTG_GINTMSK_OEPINT_Pos               (19U)                         
#define USB_OTG_GINTMSK_OEPINT_Msk               (0x1UL << USB_OTG_GINTMSK_OEPINT_Pos) /*!< 0x00080000 */
#define USB_OTG_GINTMSK_OEPINT                   USB_OTG_GINTMSK_OEPINT_Msk    /*!< OUT endpoints interrupt mask                        */
#define USB_OTG_GINTMSK_IISOIXFRM_Pos            (20U)                         
#define USB_OTG_GINTMSK_IISOIXFRM_Msk            (0x1UL << USB_OTG_GINTMSK_IISOIXFRM_Pos) /*!< 0x00100000 */
#define USB_OTG_GINTMSK_IISOIXFRM                USB_OTG_GINTMSK_IISOIXFRM_Msk /*!< Incomplete isochronous IN transfer mask             */
#define USB_OTG_GINTMSK_PXFRM_IISOOXFRM_Pos      (21U)                         
#define USB_OTG_GINTMSK_PXFRM_IISOOXFRM_Msk      (0x1UL << USB_OTG_GINTMSK_PXFRM_IISOOXFRM_Pos) /*!< 0x00200000 */
#define USB_OTG_GINTMSK_PXFRM_IISOOXFRM          USB_OTG_GINTMSK_PXFRM_IISOOXFRM_Msk /*!< Incomplete periodic transfer mask                   */
#define USB_OTG_GINTMSK_FSUSPM_Pos               (22U)                         
#define USB_OTG_GINTMSK_FSUSPM_Msk               (0x1UL << USB_OTG_GINTMSK_FSUSPM_Pos) /*!< 0x00400000 */
#define USB_OTG_GINTMSK_FSUSPM                   USB_OTG_GINTMSK_FSUSPM_Msk    /*!< Data fetch suspended mask                           */
#define USB_OTG_GINTMSK_PRTIM_Pos                (24U)                         
#define USB_OTG_GINTMSK_PRTIM_Msk                (0x1UL << USB_OTG_GINTMSK_PRTIM_Pos) /*!< 0x01000000 */
#define USB_OTG_GINTMSK_PRTIM                    USB_OTG_GINTMSK_PRTIM_Msk     /*!< Host port interrupt mask                            */
#define USB_OTG_GINTMSK_HCIM_Pos                 (25U)                         
#define USB_OTG_GINTMSK_HCIM_Msk                 (0x1UL << USB_OTG_GINTMSK_HCIM_Pos) /*!< 0x02000000 */
#define USB_OTG_GINTMSK_HCIM                     USB_OTG_GINTMSK_HCIM_Msk      /*!< Host channels interrupt mask                        */
#define USB_OTG_GINTMSK_PTXFEM_Pos               (26U)                         
#define USB_OTG_GINTMSK_PTXFEM_Msk               (0x1UL << USB_OTG_GINTMSK_PTXFEM_Pos) /*!< 0x04000000 */
#define USB_OTG_GINTMSK_PTXFEM                   USB_OTG_GINTMSK_PTXFEM_Msk    /*!< Periodic TxFIFO empty mask                          */
#define USB_OTG_GINTMSK_CIDSCHGM_Pos             (28U)                         
#define USB_OTG_GINTMSK_CIDSCHGM_Msk             (0x1UL << USB_OTG_GINTMSK_CIDSCHGM_Pos) /*!< 0x10000000 */
#define USB_OTG_GINTMSK_CIDSCHGM                 USB_OTG_GINTMSK_CIDSCHGM_Msk  /*!< Connector ID status change mask                     */
#define USB_OTG_GINTMSK_DISCINT_Pos              (29U)                         
#define USB_OTG_GINTMSK_DISCINT_Msk              (0x1UL << USB_OTG_GINTMSK_DISCINT_Pos) /*!< 0x20000000 */
#define USB_OTG_GINTMSK_DISCINT                  USB_OTG_GINTMSK_DISCINT_Msk   /*!< Disconnect detected interrupt mask                  */
#define USB_OTG_GINTMSK_SRQIM_Pos                (30U)                         
#define USB_OTG_GINTMSK_SRQIM_Msk                (0x1UL << USB_OTG_GINTMSK_SRQIM_Pos) /*!< 0x40000000 */
#define USB_OTG_GINTMSK_SRQIM                    USB_OTG_GINTMSK_SRQIM_Msk     /*!< Session request/new session detected interrupt mask */
#define USB_OTG_GINTMSK_WUIM_Pos                 (31U)                         
#define USB_OTG_GINTMSK_WUIM_Msk                 (0x1UL << USB_OTG_GINTMSK_WUIM_Pos) /*!< 0x80000000 */
#define USB_OTG_GINTMSK_WUIM                     USB_OTG_GINTMSK_WUIM_Msk      /*!< Resume/remote wakeup detected interrupt mask        */

/********************  Bit definition for USB_OTG_DAINT register  ********************/
#define USB_OTG_DAINT_IEPINT_Pos                 (0U)                          
#define USB_OTG_DAINT_IEPINT_Msk                 (0xFFFFUL << USB_OTG_DAINT_IEPINT_Pos) /*!< 0x0000FFFF */
#define USB_OTG_DAINT_IEPINT                     USB_OTG_DAINT_IEPINT_Msk      /*!< IN endpoint interrupt bits  */
#define USB_OTG_DAINT_OEPINT_Pos                 (16U)                         
#define USB_OTG_DAINT_OEPINT_Msk                 (0xFFFFUL << USB_OTG_DAINT_OEPINT_Pos) /*!< 0xFFFF0000 */
#define USB_OTG_DAINT_OEPINT                     USB_OTG_DAINT_OEPINT_Msk      /*!< OUT endpoint interrupt bits */

/********************  Bit definition for USB_OTG_HAINTMSK register  ********************/
#define USB_OTG_HAINTMSK_HAINTM_Pos              (0U)                          
#define USB_OTG_HAINTMSK_HAINTM_Msk              (0xFFFFUL << USB_OTG_HAINTMSK_HAINTM_Pos) /*!< 0x0000FFFF */
#define USB_OTG_HAINTMSK_HAINTM                  USB_OTG_HAINTMSK_HAINTM_Msk   /*!< Channel interrupt mask */

/********************  Bit definition for USB_OTG_GRXSTSP register  ********************/
#define USB_OTG_GRXSTSP_EPNUM_Pos                (0U)                          
#define USB_OTG_GRXSTSP_EPNUM_Msk                (0xFUL << USB_OTG_GRXSTSP_EPNUM_Pos) /*!< 0x0000000F */
#define USB_OTG_GRXSTSP_EPNUM                    USB_OTG_GRXSTSP_EPNUM_Msk     /*!< IN EP interrupt mask bits  */
#define USB_OTG_GRXSTSP_BCNT_Pos                 (4U)                          
#define USB_OTG_GRXSTSP_BCNT_Msk                 (0x7FFUL << USB_OTG_GRXSTSP_BCNT_Pos) /*!< 0x00007FF0 */
#define USB_OTG_GRXSTSP_BCNT                     USB_OTG_GRXSTSP_BCNT_Msk      /*!< OUT EP interrupt mask bits */
#define USB_OTG_GRXSTSP_DPID_Pos                 (15U)                         
#define USB_OTG_GRXSTSP_DPID_Msk                 (0x3UL << USB_OTG_GRXSTSP_DPID_Pos) /*!< 0x00018000 */
#define USB_OTG_GRXSTSP_DPID                     USB_OTG_GRXSTSP_DPID_Msk      /*!< OUT EP interrupt mask bits */
#define USB_OTG_GRXSTSP_PKTSTS_Pos               (17U)                         
#define USB_OTG_GRXSTSP_PKTSTS_Msk               (0xFUL << USB_OTG_GRXSTSP_PKTSTS_Pos) /*!< 0x001E0000 */
#define USB_OTG_GRXSTSP_PKTSTS                   USB_OTG_GRXSTSP_PKTSTS_Msk    /*!< OUT EP interrupt mask bits */

/********************  Bit definition for USB_OTG_DAINTMSK register  ********************/
#define USB_OTG_DAINTMSK_IEPM_Pos                (0U)                          
#define USB_OTG_DAINTMSK_IEPM_Msk                (0xFFFFUL << USB_OTG_DAINTMSK_IEPM_Pos) /*!< 0x0000FFFF */
#define USB_OTG_DAINTMSK_IEPM                    USB_OTG_DAINTMSK_IEPM_Msk     /*!< IN EP interrupt mask bits */
#define USB_OTG_DAINTMSK_OEPM_Pos                (16U)                         
#define USB_OTG_DAINTMSK_OEPM_Msk                (0xFFFFUL << USB_OTG_DAINTMSK_OEPM_Pos) /*!< 0xFFFF0000 */
#define USB_OTG_DAINTMSK_OEPM                    USB_OTG_DAINTMSK_OEPM_Msk     /*!< OUT EP interrupt mask bits */

/********************  Bit definition for USB_OTG_GRXFSIZ register  ********************/
#define USB_OTG_GRXFSIZ_RXFD_Pos                 (0U)                          
#define USB_OTG_GRXFSIZ_RXFD_Msk                 (0xFFFFUL << USB_OTG_GRXFSIZ_RXFD_Pos) /*!< 0x0000FFFF */
#define USB_OTG_GRXFSIZ_RXFD                     USB_OTG_GRXFSIZ_RXFD_Msk      /*!< RxFIFO depth */

/********************  Bit definition for USB_OTG_DVBUSDIS register  ********************/
#define USB_OTG_DVBUSDIS_VBUSDT_Pos              (0U)                          
#define USB_OTG_DVBUSDIS_VBUSDT_Msk              (0xFFFFUL << USB_OTG_DVBUSDIS_VBUSDT_Pos) /*!< 0x0000FFFF */
#define USB_OTG_DVBUSDIS_VBUSDT                  USB_OTG_DVBUSDIS_VBUSDT_Msk   /*!< Device VBUS discharge time */

/********************  Bit definition for OTG register  ********************/
#define USB_OTG_NPTXFSA_Pos                      (0U)                          
#define USB_OTG_NPTXFSA_Msk                      (0xFFFFUL << USB_OTG_NPTXFSA_Pos) /*!< 0x0000FFFF */
#define USB_OTG_NPTXFSA                          USB_OTG_NPTXFSA_Msk           /*!< Nonperiodic transmit RAM start address */
#define USB_OTG_NPTXFD_Pos                       (16U)                         
#define USB_OTG_NPTXFD_Msk                       (0xFFFFUL << USB_OTG_NPTXFD_Pos) /*!< 0xFFFF0000 */
#define USB_OTG_NPTXFD                           USB_OTG_NPTXFD_Msk            /*!< Nonperiodic TxFIFO depth               */
#define USB_OTG_TX0FSA_Pos                       (0U)                          
#define USB_OTG_TX0FSA_Msk                       (0xFFFFUL << USB_OTG_TX0FSA_Pos) /*!< 0x0000FFFF */
#define USB_OTG_TX0FSA                           USB_OTG_TX0FSA_Msk            /*!< Endpoint 0 transmit RAM start address  */
#define USB_OTG_TX0FD_Pos                        (16U)                         
#define USB_OTG_TX0FD_Msk                        (0xFFFFUL << USB_OTG_TX0FD_Pos) /*!< 0xFFFF0000 */
#define USB_OTG_TX0FD                            USB_OTG_TX0FD_Msk             /*!< Endpoint 0 TxFIFO depth                */

/********************  Bit definition forUSB_OTG_DVBUSPULSE register  ********************/
#define USB_OTG_DVBUSPULSE_DVBUSP_Pos            (0U)                          
#define USB_OTG_DVBUSPULSE_DVBUSP_Msk            (0xFFFUL << USB_OTG_DVBUSPULSE_DVBUSP_Pos) /*!< 0x00000FFF */
#define USB_OTG_DVBUSPULSE_DVBUSP                USB_OTG_DVBUSPULSE_DVBUSP_Msk /*!< Device VBUS pulsing time */

/********************  Bit definition for USB_OTG_GNPTXSTS register  ********************/
#define USB_OTG_GNPTXSTS_NPTXFSAV_Pos            (0U)                          
#define USB_OTG_GNPTXSTS_NPTXFSAV_Msk            (0xFFFFUL << USB_OTG_GNPTXSTS_NPTXFSAV_Pos) /*!< 0x0000FFFF */
#define USB_OTG_GNPTXSTS_NPTXFSAV                USB_OTG_GNPTXSTS_NPTXFSAV_Msk /*!< Nonperiodic TxFIFO space available */

#define USB_OTG_GNPTXSTS_NPTQXSAV_Pos            (16U)                         
#define USB_OTG_GNPTXSTS_NPTQXSAV_Msk            (0xFFUL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00FF0000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV                USB_OTG_GNPTXSTS_NPTQXSAV_Msk /*!< Nonperiodic transmit request queue space available */
#define USB_OTG_GNPTXSTS_NPTQXSAV_0              (0x01UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00010000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_1              (0x02UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00020000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_2              (0x04UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00040000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_3              (0x08UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00080000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_4              (0x10UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00100000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_5              (0x20UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00200000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_6              (0x40UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00400000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_7              (0x80UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos) /*!< 0x00800000 */

#define USB_OTG_GNPTXSTS_NPTXQTOP_Pos            (24U)                         
#define USB_OTG_GNPTXSTS_NPTXQTOP_Msk            (0x7FUL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos) /*!< 0x7F000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP                USB_OTG_GNPTXSTS_NPTXQTOP_Msk /*!< Top of the nonperiodic transmit request queue */
#define USB_OTG_GNPTXSTS_NPTXQTOP_0              (0x01UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos) /*!< 0x01000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_1              (0x02UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos) /*!< 0x02000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_2              (0x04UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos) /*!< 0x04000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_3              (0x08UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos) /*!< 0x08000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_4              (0x10UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos) /*!< 0x10000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_5              (0x20UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos) /*!< 0x20000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_6              (0x40UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos) /*!< 0x40000000 */

/********************  Bit definition for USB_OTG_DTHRCTL register  ********************/
#define USB_OTG_DTHRCTL_NONISOTHREN_Pos          (0U)                          
#define USB_OTG_DTHRCTL_NONISOTHREN_Msk          (0x1UL << USB_OTG_DTHRCTL_NONISOTHREN_Pos) /*!< 0x00000001 */
#define USB_OTG_DTHRCTL_NONISOTHREN              USB_OTG_DTHRCTL_NONISOTHREN_Msk /*!< Nonisochronous IN endpoints threshold enable */
#define USB_OTG_DTHRCTL_ISOTHREN_Pos             (1U)                          
#define USB_OTG_DTHRCTL_ISOTHREN_Msk             (0x1UL << USB_OTG_DTHRCTL_ISOTHREN_Pos) /*!< 0x00000002 */
#define USB_OTG_DTHRCTL_ISOTHREN                 USB_OTG_DTHRCTL_ISOTHREN_Msk  /*!< ISO IN endpoint threshold enable */

#define USB_OTG_DTHRCTL_TXTHRLEN_Pos             (2U)                          
#define USB_OTG_DTHRCTL_TXTHRLEN_Msk             (0x1FFUL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x000007FC */
#define USB_OTG_DTHRCTL_TXTHRLEN                 USB_OTG_DTHRCTL_TXTHRLEN_Msk  /*!< Transmit threshold length */
#define USB_OTG_DTHRCTL_TXTHRLEN_0               (0x001UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000004 */
#define USB_OTG_DTHRCTL_TXTHRLEN_1               (0x002UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000008 */
#define USB_OTG_DTHRCTL_TXTHRLEN_2               (0x004UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000010 */
#define USB_OTG_DTHRCTL_TXTHRLEN_3               (0x008UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000020 */
#define USB_OTG_DTHRCTL_TXTHRLEN_4               (0x010UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000040 */
#define USB_OTG_DTHRCTL_TXTHRLEN_5               (0x020UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000080 */
#define USB_OTG_DTHRCTL_TXTHRLEN_6               (0x040UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000100 */
#define USB_OTG_DTHRCTL_TXTHRLEN_7               (0x080UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000200 */
#define USB_OTG_DTHRCTL_TXTHRLEN_8               (0x100UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos) /*!< 0x00000400 */
#define USB_OTG_DTHRCTL_RXTHREN_Pos              (16U)                         
#define USB_OTG_DTHRCTL_RXTHREN_Msk              (0x1UL << USB_OTG_DTHRCTL_RXTHREN_Pos) /*!< 0x00010000 */
#define USB_OTG_DTHRCTL_RXTHREN                  USB_OTG_DTHRCTL_RXTHREN_Msk   /*!< Receive threshold enable */

#define USB_OTG_DTHRCTL_RXTHRLEN_Pos             (17U)                         
#define USB_OTG_DTHRCTL_RXTHRLEN_Msk             (0x1FFUL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x03FE0000 */
#define USB_OTG_DTHRCTL_RXTHRLEN                 USB_OTG_DTHRCTL_RXTHRLEN_Msk  /*!< Receive threshold length */
#define USB_OTG_DTHRCTL_RXTHRLEN_0               (0x001UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x00020000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_1               (0x002UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x00040000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_2               (0x004UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x00080000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_3               (0x008UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x00100000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_4               (0x010UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x00200000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_5               (0x020UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x00400000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_6               (0x040UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x00800000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_7               (0x080UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x01000000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_8               (0x100UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos) /*!< 0x02000000 */
#define USB_OTG_DTHRCTL_ARPEN_Pos                (27U)                         
#define USB_OTG_DTHRCTL_ARPEN_Msk                (0x1UL << USB_OTG_DTHRCTL_ARPEN_Pos) /*!< 0x08000000 */
#define USB_OTG_DTHRCTL_ARPEN                    USB_OTG_DTHRCTL_ARPEN_Msk     /*!< Arbiter parking enable */

/********************  Bit definition for USB_OTG_DIEPEMPMSK register  ********************/
#define USB_OTG_DIEPEMPMSK_INEPTXFEM_Pos         (0U)                          
#define USB_OTG_DIEPEMPMSK_INEPTXFEM_Msk         (0xFFFFUL << USB_OTG_DIEPEMPMSK_INEPTXFEM_Pos) /*!< 0x0000FFFF */
#define USB_OTG_DIEPEMPMSK_INEPTXFEM             USB_OTG_DIEPEMPMSK_INEPTXFEM_Msk /*!< IN EP Tx FIFO empty interrupt mask bits */

/********************  Bit definition for USB_OTG_DEACHINT register  ********************/
#define USB_OTG_DEACHINT_IEP1INT_Pos             (1U)                          
#define USB_OTG_DEACHINT_IEP1INT_Msk             (0x1UL << USB_OTG_DEACHINT_IEP1INT_Pos) /*!< 0x00000002 */
#define USB_OTG_DEACHINT_IEP1INT                 USB_OTG_DEACHINT_IEP1INT_Msk  /*!< IN endpoint 1interrupt bit   */
#define USB_OTG_DEACHINT_OEP1INT_Pos             (17U)                         
#define USB_OTG_DEACHINT_OEP1INT_Msk             (0x1UL << USB_OTG_DEACHINT_OEP1INT_Pos) /*!< 0x00020000 */
#define USB_OTG_DEACHINT_OEP1INT                 USB_OTG_DEACHINT_OEP1INT_Msk  /*!< OUT endpoint 1 interrupt bit */

/********************  Bit definition for USB_OTG_GCCFG register  ********************/
#define USB_OTG_GCCFG_PWRDWN_Pos                 (16U)                         
#define USB_OTG_GCCFG_PWRDWN_Msk                 (0x1UL << USB_OTG_GCCFG_PWRDWN_Pos) /*!< 0x00010000 */
#define USB_OTG_GCCFG_PWRDWN                     USB_OTG_GCCFG_PWRDWN_Msk      /*!< Power down */
#define USB_OTG_GCCFG_I2CPADEN_Pos               (17U)                         
#define USB_OTG_GCCFG_I2CPADEN_Msk               (0x1UL << USB_OTG_GCCFG_I2CPADEN_Pos) /*!< 0x00020000 */
#define USB_OTG_GCCFG_I2CPADEN                   USB_OTG_GCCFG_I2CPADEN_Msk    /*!< Enable I2C bus connection for the external I2C PHY interface*/ 
#define USB_OTG_GCCFG_VBUSASEN_Pos               (18U)                         
#define USB_OTG_GCCFG_VBUSASEN_Msk               (0x1UL << USB_OTG_GCCFG_VBUSASEN_Pos) /*!< 0x00040000 */
#define USB_OTG_GCCFG_VBUSASEN                   USB_OTG_GCCFG_VBUSASEN_Msk    /*!< Enable the VBUS sensing device */
#define USB_OTG_GCCFG_VBUSBSEN_Pos               (19U)                         
#define USB_OTG_GCCFG_VBUSBSEN_Msk               (0x1UL << USB_OTG_GCCFG_VBUSBSEN_Pos) /*!< 0x00080000 */
#define USB_OTG_GCCFG_VBUSBSEN                   USB_OTG_GCCFG_VBUSBSEN_Msk    /*!< Enable the VBUS sensing device */
#define USB_OTG_GCCFG_SOFOUTEN_Pos               (20U)                         
#define USB_OTG_GCCFG_SOFOUTEN_Msk               (0x1UL << USB_OTG_GCCFG_SOFOUTEN_Pos) /*!< 0x00100000 */
#define USB_OTG_GCCFG_SOFOUTEN                   USB_OTG_GCCFG_SOFOUTEN_Msk    /*!< SOF output enable */
#define USB_OTG_GCCFG_NOVBUSSENS_Pos             (21U)                         
#define USB_OTG_GCCFG_NOVBUSSENS_Msk             (0x1UL << USB_OTG_GCCFG_NOVBUSSENS_Pos) /*!< 0x00200000 */
#define USB_OTG_GCCFG_NOVBUSSENS                 USB_OTG_GCCFG_NOVBUSSENS_Msk  /*!< VBUS sensing disable option*/ 

/********************  Bit definition forUSB_OTG_DEACHINTMSK register  ********************/
#define USB_OTG_DEACHINTMSK_IEP1INTM_Pos         (1U)                          
#define USB_OTG_DEACHINTMSK_IEP1INTM_Msk         (0x1UL << USB_OTG_DEACHINTMSK_IEP1INTM_Pos) /*!< 0x00000002 */
#define USB_OTG_DEACHINTMSK_IEP1INTM             USB_OTG_DEACHINTMSK_IEP1INTM_Msk /*!< IN Endpoint 1 interrupt mask bit  */
#define USB_OTG_DEACHINTMSK_OEP1INTM_Pos         (17U)                         
#define USB_OTG_DEACHINTMSK_OEP1INTM_Msk         (0x1UL << USB_OTG_DEACHINTMSK_OEP1INTM_Pos) /*!< 0x00020000 */
#define USB_OTG_DEACHINTMSK_OEP1INTM             USB_OTG_DEACHINTMSK_OEP1INTM_Msk /*!< OUT Endpoint 1 interrupt mask bit */

/********************  Bit definition for USB_OTG_CID register  ********************/
#define USB_OTG_CID_PRODUCT_ID_Pos               (0U)                          
#define USB_OTG_CID_PRODUCT_ID_Msk               (0xFFFFFFFFUL << USB_OTG_CID_PRODUCT_ID_Pos) /*!< 0xFFFFFFFF */
#define USB_OTG_CID_PRODUCT_ID                   USB_OTG_CID_PRODUCT_ID_Msk    /*!< Product ID field */

/********************  Bit definition for USB_OTG_DIEPEACHMSK1 register  ********************/
#define USB_OTG_DIEPEACHMSK1_XFRCM_Pos           (0U)                          
#define USB_OTG_DIEPEACHMSK1_XFRCM_Msk           (0x1UL << USB_OTG_DIEPEACHMSK1_XFRCM_Pos) /*!< 0x00000001 */
#define USB_OTG_DIEPEACHMSK1_XFRCM               USB_OTG_DIEPEACHMSK1_XFRCM_Msk /*!< Transfer completed interrupt mask                 */
#define USB_OTG_DIEPEACHMSK1_EPDM_Pos            (1U)                          
#define USB_OTG_DIEPEACHMSK1_EPDM_Msk            (0x1UL << USB_OTG_DIEPEACHMSK1_EPDM_Pos) /*!< 0x00000002 */
#define USB_OTG_DIEPEACHMSK1_EPDM                USB_OTG_DIEPEACHMSK1_EPDM_Msk /*!< Endpoint disabled interrupt mask                  */
#define USB_OTG_DIEPEACHMSK1_TOM_Pos             (3U)                          
#define USB_OTG_DIEPEACHMSK1_TOM_Msk             (0x1UL << USB_OTG_DIEPEACHMSK1_TOM_Pos) /*!< 0x00000008 */
#define USB_OTG_DIEPEACHMSK1_TOM                 USB_OTG_DIEPEACHMSK1_TOM_Msk  /*!< Timeout condition mask (nonisochronous endpoints) */
#define USB_OTG_DIEPEACHMSK1_ITTXFEMSK_Pos       (4U)                          
#define USB_OTG_DIEPEACHMSK1_ITTXFEMSK_Msk       (0x1UL << USB_OTG_DIEPEACHMSK1_ITTXFEMSK_Pos) /*!< 0x00000010 */
#define USB_OTG_DIEPEACHMSK1_ITTXFEMSK           USB_OTG_DIEPEACHMSK1_ITTXFEMSK_Msk /*!< IN token received when TxFIFO empty mask          */
#define USB_OTG_DIEPEACHMSK1_INEPNMM_Pos         (5U)                          
#define USB_OTG_DIEPEACHMSK1_INEPNMM_Msk         (0x1UL << USB_OTG_DIEPEACHMSK1_INEPNMM_Pos) /*!< 0x00000020 */
#define USB_OTG_DIEPEACHMSK1_INEPNMM             USB_OTG_DIEPEACHMSK1_INEPNMM_Msk /*!< IN token received with EP mismatch mask           */
#define USB_OTG_DIEPEACHMSK1_INEPNEM_Pos         (6U)                          
#define USB_OTG_DIEPEACHMSK1_INEPNEM_Msk         (0x1UL << USB_OTG_DIEPEACHMSK1_INEPNEM_Pos) /*!< 0x00000040 */
#define USB_OTG_DIEPEACHMSK1_INEPNEM             USB_OTG_DIEPEACHMSK1_INEPNEM_Msk /*!< IN endpoint NAK effective mask                    */
#define USB_OTG_DIEPEACHMSK1_TXFURM_Pos          (8U)                          
#define USB_OTG_DIEPEACHMSK1_TXFURM_Msk          (0x1UL << USB_OTG_DIEPEACHMSK1_TXFURM_Pos) /*!< 0x00000100 */
#define USB_OTG_DIEPEACHMSK1_TXFURM              USB_OTG_DIEPEACHMSK1_TXFURM_Msk /*!< FIFO underrun mask                                */
#define USB_OTG_DIEPEACHMSK1_BIM_Pos             (9U)                          
#define USB_OTG_DIEPEACHMSK1_BIM_Msk             (0x1UL << USB_OTG_DIEPEACHMSK1_BIM_Pos) /*!< 0x00000200 */
#define USB_OTG_DIEPEACHMSK1_BIM                 USB_OTG_DIEPEACHMSK1_BIM_Msk  /*!< BNA interrupt mask                                */
#define USB_OTG_DIEPEACHMSK1_NAKM_Pos            (13U)                         
#define USB_OTG_DIEPEACHMSK1_NAKM_Msk            (0x1UL << USB_OTG_DIEPEACHMSK1_NAKM_Pos) /*!< 0x00002000 */
#define USB_OTG_DIEPEACHMSK1_NAKM                USB_OTG_DIEPEACHMSK1_NAKM_Msk /*!< NAK interrupt mask                                */

/********************  Bit definition for USB_OTG_HPRT register  ********************/
#define USB_OTG_HPRT_PCSTS_Pos                   (0U)                          
#define USB_OTG_HPRT_PCSTS_Msk                   (0x1UL << USB_OTG_HPRT_PCSTS_Pos) /*!< 0x00000001 */
#define USB_OTG_HPRT_PCSTS                       USB_OTG_HPRT_PCSTS_Msk        /*!< Port connect status        */
#define USB_OTG_HPRT_PCDET_Pos                   (1U)                          
#define USB_OTG_HPRT_PCDET_Msk                   (0x1UL << USB_OTG_HPRT_PCDET_Pos) /*!< 0x00000002 */
#define USB_OTG_HPRT_PCDET                       USB_OTG_HPRT_PCDET_Msk        /*!< Port connect detected      */
#define USB_OTG_HPRT_PENA_Pos                    (2U)                          
#define USB_OTG_HPRT_PENA_Msk                    (0x1UL << USB_OTG_HPRT_PENA_Pos) /*!< 0x00000004 */
#define USB_OTG_HPRT_PENA                        USB_OTG_HPRT_PENA_Msk         /*!< Port enable                */
#define USB_OTG_HPRT_PENCHNG_Pos                 (3U)                          
#define USB_OTG_HPRT_PENCHNG_Msk                 (0x1UL << USB_OTG_HPRT_PENCHNG_Pos) /*!< 0x00000008 */
#define USB_OTG_HPRT_PENCHNG                     USB_OTG_HPRT_PENCHNG_Msk      /*!< Port enable/disable change */
#define USB_OTG_HPRT_POCA_Pos                    (4U)                          
#define USB_OTG_HPRT_POCA_Msk                    (0x1UL << USB_OTG_HPRT_POCA_Pos) /*!< 0x00000010 */
#define USB_OTG_HPRT_POCA                        USB_OTG_HPRT_POCA_Msk         /*!< Port overcurrent active    */
#define USB_OTG_HPRT_POCCHNG_Pos                 (5U)                          
#define USB_OTG_HPRT_POCCHNG_Msk                 (0x1UL << USB_OTG_HPRT_POCCHNG_Pos) /*!< 0x00000020 */
#define USB_OTG_HPRT_POCCHNG                     USB_OTG_HPRT_POCCHNG_Msk      /*!< Port overcurrent change    */
#define USB_OTG_HPRT_PRES_Pos                    (6U)                          
#define USB_OTG_HPRT_PRES_Msk                    (0x1UL << USB_OTG_HPRT_PRES_Pos) /*!< 0x00000040 */
#define USB_OTG_HPRT_PRES                        USB_OTG_HPRT_PRES_Msk         /*!< Port resume                */
#define USB_OTG_HPRT_PSUSP_Pos                   (7U)                          
#define USB_OTG_HPRT_PSUSP_Msk                   (0x1UL << USB_OTG_HPRT_PSUSP_Pos) /*!< 0x00000080 */
#define USB_OTG_HPRT_PSUSP                       USB_OTG_HPRT_PSUSP_Msk        /*!< Port suspend               */
#define USB_OTG_HPRT_PRST_Pos                    (8U)                          
#define USB_OTG_HPRT_PRST_Msk                    (0x1UL << USB_OTG_HPRT_PRST_Pos) /*!< 0x00000100 */
#define USB_OTG_HPRT_PRST                        USB_OTG_HPRT_PRST_Msk         /*!< Port reset                 */

#define USB_OTG_HPRT_PLSTS_Pos                   (10U)                         
#define USB_OTG_HPRT_PLSTS_Msk                   (0x3UL << USB_OTG_HPRT_PLSTS_Pos) /*!< 0x00000C00 */
#define USB_OTG_HPRT_PLSTS                       USB_OTG_HPRT_PLSTS_Msk        /*!< Port line status           */
#define USB_OTG_HPRT_PLSTS_0                     (0x1UL << USB_OTG_HPRT_PLSTS_Pos) /*!< 0x00000400 */
#define USB_OTG_HPRT_PLSTS_1                     (0x2UL << USB_OTG_HPRT_PLSTS_Pos) /*!< 0x00000800 */
#define USB_OTG_HPRT_PPWR_Pos                    (12U)                         
#define USB_OTG_HPRT_PPWR_Msk                    (0x1UL << USB_OTG_HPRT_PPWR_Pos) /*!< 0x00001000 */
#define USB_OTG_HPRT_PPWR                        USB_OTG_HPRT_PPWR_Msk         /*!< Port power                 */

#define USB_OTG_HPRT_PTCTL_Pos                   (13U)                         
#define USB_OTG_HPRT_PTCTL_Msk                   (0xFUL << USB_OTG_HPRT_PTCTL_Pos) /*!< 0x0001E000 */
#define USB_OTG_HPRT_PTCTL                       USB_OTG_HPRT_PTCTL_Msk        /*!< Port test control          */
#define USB_OTG_HPRT_PTCTL_0                     (0x1UL << USB_OTG_HPRT_PTCTL_Pos) /*!< 0x00002000 */
#define USB_OTG_HPRT_PTCTL_1                     (0x2UL << USB_OTG_HPRT_PTCTL_Pos) /*!< 0x00004000 */
#define USB_OTG_HPRT_PTCTL_2                     (0x4UL << USB_OTG_HPRT_PTCTL_Pos) /*!< 0x00008000 */
#define USB_OTG_HPRT_PTCTL_3                     (0x8UL << USB_OTG_HPRT_PTCTL_Pos) /*!< 0x00010000 */

#define USB_OTG_HPRT_PSPD_Pos                    (17U)                         
#define USB_OTG_HPRT_PSPD_Msk                    (0x3UL << USB_OTG_HPRT_PSPD_Pos) /*!< 0x00060000 */
#define USB_OTG_HPRT_PSPD                        USB_OTG_HPRT_PSPD_Msk         /*!< Port speed                 */
#define USB_OTG_HPRT_PSPD_0                      (0x1UL << USB_OTG_HPRT_PSPD_Pos) /*!< 0x00020000 */
#define USB_OTG_HPRT_PSPD_1                      (0x2UL << USB_OTG_HPRT_PSPD_Pos) /*!< 0x00040000 */

/********************  Bit definition for USB_OTG_DOEPEACHMSK1 register  ********************/
#define USB_OTG_DOEPEACHMSK1_XFRCM_Pos           (0U)                          
#define USB_OTG_DOEPEACHMSK1_XFRCM_Msk           (0x1UL << USB_OTG_DOEPEACHMSK1_XFRCM_Pos) /*!< 0x00000001 */
#define USB_OTG_DOEPEACHMSK1_XFRCM               USB_OTG_DOEPEACHMSK1_XFRCM_Msk /*!< Transfer completed interrupt mask         */
#define USB_OTG_DOEPEACHMSK1_EPDM_Pos            (1U)                          
#define USB_OTG_DOEPEACHMSK1_EPDM_Msk            (0x1UL << USB_OTG_DOEPEACHMSK1_EPDM_Pos) /*!< 0x00000002 */
#define USB_OTG_DOEPEACHMSK1_EPDM                USB_OTG_DOEPEACHMSK1_EPDM_Msk /*!< Endpoint disabled interrupt mask          */
#define USB_OTG_DOEPEACHMSK1_TOM_Pos             (3U)                          
#define USB_OTG_DOEPEACHMSK1_TOM_Msk             (0x1UL << USB_OTG_DOEPEACHMSK1_TOM_Pos) /*!< 0x00000008 */
#define USB_OTG_DOEPEACHMSK1_TOM                 USB_OTG_DOEPEACHMSK1_TOM_Msk  /*!< Timeout condition mask                    */
#define USB_OTG_DOEPEACHMSK1_ITTXFEMSK_Pos       (4U)                          
#define USB_OTG_DOEPEACHMSK1_ITTXFEMSK_Msk       (0x1UL << USB_OTG_DOEPEACHMSK1_ITTXFEMSK_Pos) /*!< 0x00000010 */
#define USB_OTG_DOEPEACHMSK1_ITTXFEMSK           USB_OTG_DOEPEACHMSK1_ITTXFEMSK_Msk /*!< IN token received when TxFIFO empty mask  */
#define USB_OTG_DOEPEACHMSK1_INEPNMM_Pos         (5U)                          
#define USB_OTG_DOEPEACHMSK1_INEPNMM_Msk         (0x1UL << USB_OTG_DOEPEACHMSK1_INEPNMM_Pos) /*!< 0x00000020 */
#define USB_OTG_DOEPEACHMSK1_INEPNMM             USB_OTG_DOEPEACHMSK1_INEPNMM_Msk /*!< IN token received with EP mismatch mask   */
#define USB_OTG_DOEPEACHMSK1_INEPNEM_Pos         (6U)                          
#define USB_OTG_DOEPEACHMSK1_INEPNEM_Msk         (0x1UL << USB_OTG_DOEPEACHMSK1_INEPNEM_Pos) /*!< 0x00000040 */
#define USB_OTG_DOEPEACHMSK1_INEPNEM             USB_OTG_DOEPEACHMSK1_INEPNEM_Msk /*!< IN endpoint NAK effective mask            */
#define USB_OTG_DOEPEACHMSK1_TXFURM_Pos          (8U)                          
#define USB_OTG_DOEPEACHMSK1_TXFURM_Msk          (0x1UL << USB_OTG_DOEPEACHMSK1_TXFURM_Pos) /*!< 0x00000100 */
#define USB_OTG_DOEPEACHMSK1_TXFURM              USB_OTG_DOEPEACHMSK1_TXFURM_Msk /*!< OUT packet error mask                     */
#define USB_OTG_DOEPEACHMSK1_BIM_Pos             (9U)                          
#define USB_OTG_DOEPEACHMSK1_BIM_Msk             (0x1UL << USB_OTG_DOEPEACHMSK1_BIM_Pos) /*!< 0x00000200 */
#define USB_OTG_DOEPEACHMSK1_BIM                 USB_OTG_DOEPEACHMSK1_BIM_Msk  /*!< BNA interrupt mask                        */
#define USB_OTG_DOEPEACHMSK1_BERRM_Pos           (12U)                         
#define USB_OTG_DOEPEACHMSK1_BERRM_Msk           (0x1UL << USB_OTG_DOEPEACHMSK1_BERRM_Pos) /*!< 0x00001000 */
#define USB_OTG_DOEPEACHMSK1_BERRM               USB_OTG_DOEPEACHMSK1_BERRM_Msk /*!< Bubble error interrupt mask               */
#define USB_OTG_DOEPEACHMSK1_NAKM_Pos            (13U)                         
#define USB_OTG_DOEPEACHMSK1_NAKM_Msk            (0x1UL << USB_OTG_DOEPEACHMSK1_NAKM_Pos) /*!< 0x00002000 */
#define USB_OTG_DOEPEACHMSK1_NAKM                USB_OTG_DOEPEACHMSK1_NAKM_Msk /*!< NAK interrupt mask                        */
#define USB_OTG_DOEPEACHMSK1_NYETM_Pos           (14U)                         
#define USB_OTG_DOEPEACHMSK1_NYETM_Msk           (0x1UL << USB_OTG_DOEPEACHMSK1_NYETM_Pos) /*!< 0x00004000 */
#define USB_OTG_DOEPEACHMSK1_NYETM               USB_OTG_DOEPEACHMSK1_NYETM_Msk /*!< NYET interrupt mask                       */

/********************  Bit definition for USB_OTG_HPTXFSIZ register  ********************/
#define USB_OTG_HPTXFSIZ_PTXSA_Pos               (0U)                          
#define USB_OTG_HPTXFSIZ_PTXSA_Msk               (0xFFFFUL << USB_OTG_HPTXFSIZ_PTXSA_Pos) /*!< 0x0000FFFF */
#define USB_OTG_HPTXFSIZ_PTXSA                   USB_OTG_HPTXFSIZ_PTXSA_Msk    /*!< Host periodic TxFIFO start address            */
#define USB_OTG_HPTXFSIZ_PTXFD_Pos               (16U)                         
#define USB_OTG_HPTXFSIZ_PTXFD_Msk               (0xFFFFUL << USB_OTG_HPTXFSIZ_PTXFD_Pos) /*!< 0xFFFF0000 */
#define USB_OTG_HPTXFSIZ_PTXFD                   USB_OTG_HPTXFSIZ_PTXFD_Msk    /*!< Host periodic TxFIFO depth                    */

/********************  Bit definition for USB_OTG_DIEPCTL register  ********************/
#define USB_OTG_DIEPCTL_MPSIZ_Pos                (0U)                          
#define USB_OTG_DIEPCTL_MPSIZ_Msk                (0x7FFUL << USB_OTG_DIEPCTL_MPSIZ_Pos) /*!< 0x000007FF */
#define USB_OTG_DIEPCTL_MPSIZ                    USB_OTG_DIEPCTL_MPSIZ_Msk     /*!< Maximum packet size              */
#define USB_OTG_DIEPCTL_USBAEP_Pos               (15U)                         
#define USB_OTG_DIEPCTL_USBAEP_Msk               (0x1UL << USB_OTG_DIEPCTL_USBAEP_Pos) /*!< 0x00008000 */
#define USB_OTG_DIEPCTL_USBAEP                   USB_OTG_DIEPCTL_USBAEP_Msk    /*!< USB active endpoint              */
#define USB_OTG_DIEPCTL_EONUM_DPID_Pos           (16U)                         
#define USB_OTG_DIEPCTL_EONUM_DPID_Msk           (0x1UL << USB_OTG_DIEPCTL_EONUM_DPID_Pos) /*!< 0x00010000 */
#define USB_OTG_DIEPCTL_EONUM_DPID               USB_OTG_DIEPCTL_EONUM_DPID_Msk /*!< Even/odd frame                   */
#define USB_OTG_DIEPCTL_NAKSTS_Pos               (17U)                         
#define USB_OTG_DIEPCTL_NAKSTS_Msk               (0x1UL << USB_OTG_DIEPCTL_NAKSTS_Pos) /*!< 0x00020000 */
#define USB_OTG_DIEPCTL_NAKSTS                   USB_OTG_DIEPCTL_NAKSTS_Msk    /*!< NAK status                       */

#define USB_OTG_DIEPCTL_EPTYP_Pos                (18U)                         
#define USB_OTG_DIEPCTL_EPTYP_Msk                (0x3UL << USB_OTG_DIEPCTL_EPTYP_Pos) /*!< 0x000C0000 */
#define USB_OTG_DIEPCTL_EPTYP                    USB_OTG_DIEPCTL_EPTYP_Msk     /*!< Endpoint type                    */
#define USB_OTG_DIEPCTL_EPTYP_0                  (0x1UL << USB_OTG_DIEPCTL_EPTYP_Pos) /*!< 0x00040000 */
#define USB_OTG_DIEPCTL_EPTYP_1                  (0x2UL << USB_OTG_DIEPCTL_EPTYP_Pos) /*!< 0x00080000 */
#define USB_OTG_DIEPCTL_STALL_Pos                (21U)                         
#define USB_OTG_DIEPCTL_STALL_Msk                (0x1UL << USB_OTG_DIEPCTL_STALL_Pos) /*!< 0x00200000 */
#define USB_OTG_DIEPCTL_STALL                    USB_OTG_DIEPCTL_STALL_Msk     /*!< STALL handshake                  */

#define USB_OTG_DIEPCTL_TXFNUM_Pos               (22U)                         
#define USB_OTG_DIEPCTL_TXFNUM_Msk               (0xFUL << USB_OTG_DIEPCTL_TXFNUM_Pos) /*!< 0x03C00000 */
#define USB_OTG_DIEPCTL_TXFNUM                   USB_OTG_DIEPCTL_TXFNUM_Msk    /*!< TxFIFO number                    */
#define USB_OTG_DIEPCTL_TXFNUM_0                 (0x1UL << USB_OTG_DIEPCTL_TXFNUM_Pos) /*!< 0x00400000 */
#define USB_OTG_DIEPCTL_TXFNUM_1                 (0x2UL << USB_OTG_DIEPCTL_TXFNUM_Pos) /*!< 0x00800000 */
#define USB_OTG_DIEPCTL_TXFNUM_2                 (0x4UL << USB_OTG_DIEPCTL_TXFNUM_Pos) /*!< 0x01000000 */
#define USB_OTG_DIEPCTL_TXFNUM_3                 (0x8UL << USB_OTG_DIEPCTL_TXFNUM_Pos) /*!< 0x02000000 */
#define USB_OTG_DIEPCTL_CNAK_Pos                 (26U)                         
#define USB_OTG_DIEPCTL_CNAK_Msk                 (0x1UL << USB_OTG_DIEPCTL_CNAK_Pos) /*!< 0x04000000 */
#define USB_OTG_DIEPCTL_CNAK                     USB_OTG_DIEPCTL_CNAK_Msk      /*!< Clear NAK                        */
#define USB_OTG_DIEPCTL_SNAK_Pos                 (27U)                         
#define USB_OTG_DIEPCTL_SNAK_Msk                 (0x1UL << USB_OTG_DIEPCTL_SNAK_Pos) /*!< 0x08000000 */
#define USB_OTG_DIEPCTL_SNAK                     USB_OTG_DIEPCTL_SNAK_Msk      /*!< Set NAK */
#define USB_OTG_DIEPCTL_SD0PID_SEVNFRM_Pos       (28U)                         
#define USB_OTG_DIEPCTL_SD0PID_SEVNFRM_Msk       (0x1UL << USB_OTG_DIEPCTL_SD0PID_SEVNFRM_Pos) /*!< 0x10000000 */
#define USB_OTG_DIEPCTL_SD0PID_SEVNFRM           USB_OTG_DIEPCTL_SD0PID_SEVNFRM_Msk /*!< Set DATA0 PID                    */
#define USB_OTG_DIEPCTL_SODDFRM_Pos              (29U)                         
#define USB_OTG_DIEPCTL_SODDFRM_Msk              (0x1UL << USB_OTG_DIEPCTL_SODDFRM_Pos) /*!< 0x20000000 */
#define USB_OTG_DIEPCTL_SODDFRM                  USB_OTG_DIEPCTL_SODDFRM_Msk   /*!< Set odd frame                    */
#define USB_OTG_DIEPCTL_EPDIS_Pos                (30U)                         
#define USB_OTG_DIEPCTL_EPDIS_Msk                (0x1UL << USB_OTG_DIEPCTL_EPDIS_Pos) /*!< 0x40000000 */
#define USB_OTG_DIEPCTL_EPDIS                    USB_OTG_DIEPCTL_EPDIS_Msk     /*!< Endpoint disable                 */
#define USB_OTG_DIEPCTL_EPENA_Pos                (31U)                         
#define USB_OTG_DIEPCTL_EPENA_Msk                (0x1UL << USB_OTG_DIEPCTL_EPENA_Pos) /*!< 0x80000000 */
#define USB_OTG_DIEPCTL_EPENA                    USB_OTG_DIEPCTL_EPENA_Msk     /*!< Endpoint enable                  */

/********************  Bit definition for USB_OTG_HCCHAR register  ********************/
#define USB_OTG_HCCHAR_MPSIZ_Pos                 (0U)                          
#define USB_OTG_HCCHAR_MPSIZ_Msk                 (0x7FFUL << USB_OTG_HCCHAR_MPSIZ_Pos) /*!< 0x000007FF */
#define USB_OTG_HCCHAR_MPSIZ                     USB_OTG_HCCHAR_MPSIZ_Msk      /*!< Maximum packet size */

#define USB_OTG_HCCHAR_EPNUM_Pos                 (11U)                         
#define USB_OTG_HCCHAR_EPNUM_Msk                 (0xFUL << USB_OTG_HCCHAR_EPNUM_Pos) /*!< 0x00007800 */
#define USB_OTG_HCCHAR_EPNUM                     USB_OTG_HCCHAR_EPNUM_Msk      /*!< Endpoint number */
#define USB_OTG_HCCHAR_EPNUM_0                   (0x1UL << USB_OTG_HCCHAR_EPNUM_Pos) /*!< 0x00000800 */
#define USB_OTG_HCCHAR_EPNUM_1                   (0x2UL << USB_OTG_HCCHAR_EPNUM_Pos) /*!< 0x00001000 */
#define USB_OTG_HCCHAR_EPNUM_2                   (0x4UL << USB_OTG_HCCHAR_EPNUM_Pos) /*!< 0x00002000 */
#define USB_OTG_HCCHAR_EPNUM_3                   (0x8UL << USB_OTG_HCCHAR_EPNUM_Pos) /*!< 0x00004000 */
#define USB_OTG_HCCHAR_EPDIR_Pos                 (15U)                         
#define USB_OTG_HCCHAR_EPDIR_Msk                 (0x1UL << USB_OTG_HCCHAR_EPDIR_Pos) /*!< 0x00008000 */
#define USB_OTG_HCCHAR_EPDIR                     USB_OTG_HCCHAR_EPDIR_Msk      /*!< Endpoint direction */
#define USB_OTG_HCCHAR_LSDEV_Pos                 (17U)                         
#define USB_OTG_HCCHAR_LSDEV_Msk                 (0x1UL << USB_OTG_HCCHAR_LSDEV_Pos) /*!< 0x00020000 */
#define USB_OTG_HCCHAR_LSDEV                     USB_OTG_HCCHAR_LSDEV_Msk      /*!< Low-speed device */

#define USB_OTG_HCCHAR_EPTYP_Pos                 (18U)                         
#define USB_OTG_HCCHAR_EPTYP_Msk                 (0x3UL << USB_OTG_HCCHAR_EPTYP_Pos) /*!< 0x000C0000 */
#define USB_OTG_HCCHAR_EPTYP                     USB_OTG_HCCHAR_EPTYP_Msk      /*!< Endpoint type */
#define USB_OTG_HCCHAR_EPTYP_0                   (0x1UL << USB_OTG_HCCHAR_EPTYP_Pos) /*!< 0x00040000 */
#define USB_OTG_HCCHAR_EPTYP_1                   (0x2UL << USB_OTG_HCCHAR_EPTYP_Pos) /*!< 0x00080000 */

#define USB_OTG_HCCHAR_MC_Pos                    (20U)                         
#define USB_OTG_HCCHAR_MC_Msk                    (0x3UL << USB_OTG_HCCHAR_MC_Pos) /*!< 0x00300000 */
#define USB_OTG_HCCHAR_MC                        USB_OTG_HCCHAR_MC_Msk         /*!< Multi Count (MC) / Error Count (EC) */
#define USB_OTG_HCCHAR_MC_0                      (0x1UL << USB_OTG_HCCHAR_MC_Pos) /*!< 0x00100000 */
#define USB_OTG_HCCHAR_MC_1                      (0x2UL << USB_OTG_HCCHAR_MC_Pos) /*!< 0x00200000 */

#define USB_OTG_HCCHAR_DAD_Pos                   (22U)                         
#define USB_OTG_HCCHAR_DAD_Msk                   (0x7FUL << USB_OTG_HCCHAR_DAD_Pos) /*!< 0x1FC00000 */
#define USB_OTG_HCCHAR_DAD                       USB_OTG_HCCHAR_DAD_Msk        /*!< Device address */
#define USB_OTG_HCCHAR_DAD_0                     (0x01UL << USB_OTG_HCCHAR_DAD_Pos) /*!< 0x00400000 */
#define USB_OTG_HCCHAR_DAD_1                     (0x02UL << USB_OTG_HCCHAR_DAD_Pos) /*!< 0x00800000 */
#define USB_OTG_HCCHAR_DAD_2                     (0x04UL << USB_OTG_HCCHAR_DAD_Pos) /*!< 0x01000000 */
#define USB_OTG_HCCHAR_DAD_3                     (0x08UL << USB_OTG_HCCHAR_DAD_Pos) /*!< 0x02000000 */
#define USB_OTG_HCCHAR_DAD_4                     (0x10UL << USB_OTG_HCCHAR_DAD_Pos) /*!< 0x04000000 */
#define USB_OTG_HCCHAR_DAD_5                     (0x20UL << USB_OTG_HCCHAR_DAD_Pos) /*!< 0x08000000 */
#define USB_OTG_HCCHAR_DAD_6                     (0x40UL << USB_OTG_HCCHAR_DAD_Pos) /*!< 0x10000000 */
#define USB_OTG_HCCHAR_ODDFRM_Pos                (29U)                         
#define USB_OTG_HCCHAR_ODDFRM_Msk                (0x1UL << USB_OTG_HCCHAR_ODDFRM_Pos) /*!< 0x20000000 */
#define USB_OTG_HCCHAR_ODDFRM                    USB_OTG_HCCHAR_ODDFRM_Msk     /*!< Odd frame */
#define USB_OTG_HCCHAR_CHDIS_Pos                 (30U)                         
#define USB_OTG_HCCHAR_CHDIS_Msk                 (0x1UL << USB_OTG_HCCHAR_CHDIS_Pos) /*!< 0x40000000 */
#define USB_OTG_HCCHAR_CHDIS                     USB_OTG_HCCHAR_CHDIS_Msk      /*!< Channel disable */
#define USB_OTG_HCCHAR_CHENA_Pos                 (31U)                         
#define USB_OTG_HCCHAR_CHENA_Msk                 (0x1UL << USB_OTG_HCCHAR_CHENA_Pos) /*!< 0x80000000 */
#define USB_OTG_HCCHAR_CHENA                     USB_OTG_HCCHAR_CHENA_Msk      /*!< Channel enable */

/********************  Bit definition for USB_OTG_HCSPLT register  ********************/

#define USB_OTG_HCSPLT_PRTADDR_Pos               (0U)                          
#define USB_OTG_HCSPLT_PRTADDR_Msk               (0x7FUL << USB_OTG_HCSPLT_PRTADDR_Pos) /*!< 0x0000007F */
#define USB_OTG_HCSPLT_PRTADDR                   USB_OTG_HCSPLT_PRTADDR_Msk    /*!< Port address */
#define USB_OTG_HCSPLT_PRTADDR_0                 (0x01UL << USB_OTG_HCSPLT_PRTADDR_Pos) /*!< 0x00000001 */
#define USB_OTG_HCSPLT_PRTADDR_1                 (0x02UL << USB_OTG_HCSPLT_PRTADDR_Pos) /*!< 0x00000002 */
#define USB_OTG_HCSPLT_PRTADDR_2                 (0x04UL << USB_OTG_HCSPLT_PRTADDR_Pos) /*!< 0x00000004 */
#define USB_OTG_HCSPLT_PRTADDR_3                 (0x08UL << USB_OTG_HCSPLT_PRTADDR_Pos) /*!< 0x00000008 */
#define USB_OTG_HCSPLT_PRTADDR_4                 (0x10UL << USB_OTG_HCSPLT_PRTADDR_Pos) /*!< 0x00000010 */
#define USB_OTG_HCSPLT_PRTADDR_5                 (0x20UL << USB_OTG_HCSPLT_PRTADDR_Pos) /*!< 0x00000020 */
#define USB_OTG_HCSPLT_PRTADDR_6                 (0x40UL << USB_OTG_HCSPLT_PRTADDR_Pos) /*!< 0x00000040 */

#define USB_OTG_HCSPLT_HUBADDR_Pos               (7U)                          
#define USB_OTG_HCSPLT_HUBADDR_Msk               (0x7FUL << USB_OTG_HCSPLT_HUBADDR_Pos) /*!< 0x00003F80 */
#define USB_OTG_HCSPLT_HUBADDR                   USB_OTG_HCSPLT_HUBADDR_Msk    /*!< Hub address */
#define USB_OTG_HCSPLT_HUBADDR_0                 (0x01UL << USB_OTG_HCSPLT_HUBADDR_Pos) /*!< 0x00000080 */
#define USB_OTG_HCSPLT_HUBADDR_1                 (0x02UL << USB_OTG_HCSPLT_HUBADDR_Pos) /*!< 0x00000100 */
#define USB_OTG_HCSPLT_HUBADDR_2                 (0x04UL << USB_OTG_HCSPLT_HUBADDR_Pos) /*!< 0x00000200 */
#define USB_OTG_HCSPLT_HUBADDR_3                 (0x08UL << USB_OTG_HCSPLT_HUBADDR_Pos) /*!< 0x00000400 */
#define USB_OTG_HCSPLT_HUBADDR_4                 (0x10UL << USB_OTG_HCSPLT_HUBADDR_Pos) /*!< 0x00000800 */
#define USB_OTG_HCSPLT_HUBADDR_5                 (0x20UL << USB_OTG_HCSPLT_HUBADDR_Pos) /*!< 0x00001000 */
#define USB_OTG_HCSPLT_HUBADDR_6                 (0x40UL << USB_OTG_HCSPLT_HUBADDR_Pos) /*!< 0x00002000 */

#define USB_OTG_HCSPLT_XACTPOS_Pos               (14U)                         
#define USB_OTG_HCSPLT_XACTPOS_Msk               (0x3UL << USB_OTG_HCSPLT_XACTPOS_Pos) /*!< 0x0000C000 */
#define USB_OTG_HCSPLT_XACTPOS                   USB_OTG_HCSPLT_XACTPOS_Msk    /*!< XACTPOS */
#define USB_OTG_HCSPLT_XACTPOS_0                 (0x1UL << USB_OTG_HCSPLT_XACTPOS_Pos) /*!< 0x00004000 */
#define USB_OTG_HCSPLT_XACTPOS_1                 (0x2UL << USB_OTG_HCSPLT_XACTPOS_Pos) /*!< 0x00008000 */
#define USB_OTG_HCSPLT_COMPLSPLT_Pos             (16U)                         
#define USB_OTG_HCSPLT_COMPLSPLT_Msk             (0x1UL << USB_OTG_HCSPLT_COMPLSPLT_Pos) /*!< 0x00010000 */
#define USB_OTG_HCSPLT_COMPLSPLT                 USB_OTG_HCSPLT_COMPLSPLT_Msk  /*!< Do complete split */
#define USB_OTG_HCSPLT_SPLITEN_Pos               (31U)                         
#define USB_OTG_HCSPLT_SPLITEN_Msk               (0x1UL << USB_OTG_HCSPLT_SPLITEN_Pos) /*!< 0x80000000 */
#define USB_OTG_HCSPLT_SPLITEN                   USB_OTG_HCSPLT_SPLITEN_Msk    /*!< Split enable */

/********************  Bit definition for USB_OTG_HCINT register  ********************/
#define USB_OTG_HCINT_XFRC_Pos                   (0U)                          
#define USB_OTG_HCINT_XFRC_Msk                   (0x1UL << USB_OTG_HCINT_XFRC_Pos) /*!< 0x00000001 */
#define USB_OTG_HCINT_XFRC                       USB_OTG_HCINT_XFRC_Msk        /*!< Transfer completed */
#define USB_OTG_HCINT_CHH_Pos                    (1U)                          
#define USB_OTG_HCINT_CHH_Msk                    (0x1UL << USB_OTG_HCINT_CHH_Pos) /*!< 0x00000002 */
#define USB_OTG_HCINT_CHH                        USB_OTG_HCINT_CHH_Msk         /*!< Channel halted */
#define USB_OTG_HCINT_AHBERR_Pos                 (2U)                          
#define USB_OTG_HCINT_AHBERR_Msk                 (0x1UL << USB_OTG_HCINT_AHBERR_Pos) /*!< 0x00000004 */
#define USB_OTG_HCINT_AHBERR                     USB_OTG_HCINT_AHBERR_Msk      /*!< AHB error */
#define USB_OTG_HCINT_STALL_Pos                  (3U)                          
#define USB_OTG_HCINT_STALL_Msk                  (0x1UL << USB_OTG_HCINT_STALL_Pos) /*!< 0x00000008 */
#define USB_OTG_HCINT_STALL                      USB_OTG_HCINT_STALL_Msk       /*!< STALL response received interrupt */
#define USB_OTG_HCINT_NAK_Pos                    (4U)                          
#define USB_OTG_HCINT_NAK_Msk                    (0x1UL << USB_OTG_HCINT_NAK_Pos) /*!< 0x00000010 */
#define USB_OTG_HCINT_NAK                        USB_OTG_HCINT_NAK_Msk         /*!< NAK response received interrupt */
#define USB_OTG_HCINT_ACK_Pos                    (5U)                          
#define USB_OTG_HCINT_ACK_Msk                    (0x1UL << USB_OTG_HCINT_ACK_Pos) /*!< 0x00000020 */
#define USB_OTG_HCINT_ACK                        USB_OTG_HCINT_ACK_Msk         /*!< ACK response received/transmitted interrupt */
#define USB_OTG_HCINT_NYET_Pos                   (6U)                          
#define USB_OTG_HCINT_NYET_Msk                   (0x1UL << USB_OTG_HCINT_NYET_Pos) /*!< 0x00000040 */
#define USB_OTG_HCINT_NYET                       USB_OTG_HCINT_NYET_Msk        /*!< Response received interrupt */
#define USB_OTG_HCINT_TXERR_Pos                  (7U)                          
#define USB_OTG_HCINT_TXERR_Msk                  (0x1UL << USB_OTG_HCINT_TXERR_Pos) /*!< 0x00000080 */
#define USB_OTG_HCINT_TXERR                      USB_OTG_HCINT_TXERR_Msk       /*!< Transaction error */
#define USB_OTG_HCINT_BBERR_Pos                  (8U)                          
#define USB_OTG_HCINT_BBERR_Msk                  (0x1UL << USB_OTG_HCINT_BBERR_Pos) /*!< 0x00000100 */
#define USB_OTG_HCINT_BBERR                      USB_OTG_HCINT_BBERR_Msk       /*!< Babble error */
#define USB_OTG_HCINT_FRMOR_Pos                  (9U)                          
#define USB_OTG_HCINT_FRMOR_Msk                  (0x1UL << USB_OTG_HCINT_FRMOR_Pos) /*!< 0x00000200 */
#define USB_OTG_HCINT_FRMOR                      USB_OTG_HCINT_FRMOR_Msk       /*!< Frame overrun */
#define USB_OTG_HCINT_DTERR_Pos                  (10U)                         
#define USB_OTG_HCINT_DTERR_Msk                  (0x1UL << USB_OTG_HCINT_DTERR_Pos) /*!< 0x00000400 */
#define USB_OTG_HCINT_DTERR                      USB_OTG_HCINT_DTERR_Msk       /*!< Data toggle error */

/********************  Bit definition for USB_OTG_DIEPINT register  ********************/
#define USB_OTG_DIEPINT_XFRC_Pos                 (0U)                          
#define USB_OTG_DIEPINT_XFRC_Msk                 (0x1UL << USB_OTG_DIEPINT_XFRC_Pos) /*!< 0x00000001 */
#define USB_OTG_DIEPINT_XFRC                     USB_OTG_DIEPINT_XFRC_Msk      /*!< Transfer completed interrupt */
#define USB_OTG_DIEPINT_EPDISD_Pos               (1U)                          
#define USB_OTG_DIEPINT_EPDISD_Msk               (0x1UL << USB_OTG_DIEPINT_EPDISD_Pos) /*!< 0x00000002 */
#define USB_OTG_DIEPINT_EPDISD                   USB_OTG_DIEPINT_EPDISD_Msk    /*!< Endpoint disabled interrupt */
#define USB_OTG_DIEPINT_AHBERR_Pos               (2U)
#define USB_OTG_DIEPINT_AHBERR_Msk               (0x1UL << USB_OTG_DIEPINT_AHBERR_Pos) /*!< 0x00000004 */
#define USB_OTG_DIEPINT_AHBERR                   USB_OTG_DIEPINT_AHBERR_Msk   /*!< AHB Error (AHBErr) during an IN transaction */
#define USB_OTG_DIEPINT_TOC_Pos                  (3U)                          
#define USB_OTG_DIEPINT_TOC_Msk                  (0x1UL << USB_OTG_DIEPINT_TOC_Pos) /*!< 0x00000008 */
#define USB_OTG_DIEPINT_TOC                      USB_OTG_DIEPINT_TOC_Msk       /*!< Timeout condition */
#define USB_OTG_DIEPINT_ITTXFE_Pos               (4U)                          
#define USB_OTG_DIEPINT_ITTXFE_Msk               (0x1UL << USB_OTG_DIEPINT_ITTXFE_Pos) /*!< 0x00000010 */
#define USB_OTG_DIEPINT_ITTXFE                   USB_OTG_DIEPINT_ITTXFE_Msk    /*!< IN token received when TxFIFO is empty */
#define USB_OTG_DIEPINT_INEPNM_Pos               (5U)
#define USB_OTG_DIEPINT_INEPNM_Msk               (0x1UL << USB_OTG_DIEPINT_INEPNM_Pos) /*!< 0x00000004 */
#define USB_OTG_DIEPINT_INEPNM                   USB_OTG_DIEPINT_INEPNM_Msk   /*!< IN token received with EP mismatch */
#define USB_OTG_DIEPINT_INEPNE_Pos               (6U)                          
#define USB_OTG_DIEPINT_INEPNE_Msk               (0x1UL << USB_OTG_DIEPINT_INEPNE_Pos) /*!< 0x00000040 */
#define USB_OTG_DIEPINT_INEPNE                   USB_OTG_DIEPINT_INEPNE_Msk    /*!< IN endpoint NAK effective */
#define USB_OTG_DIEPINT_TXFE_Pos                 (7U)                          
#define USB_OTG_DIEPINT_TXFE_Msk                 (0x1UL << USB_OTG_DIEPINT_TXFE_Pos) /*!< 0x00000080 */
#define USB_OTG_DIEPINT_TXFE                     USB_OTG_DIEPINT_TXFE_Msk      /*!< Transmit FIFO empty */
#define USB_OTG_DIEPINT_TXFIFOUDRN_Pos           (8U)                          
#define USB_OTG_DIEPINT_TXFIFOUDRN_Msk           (0x1UL << USB_OTG_DIEPINT_TXFIFOUDRN_Pos) /*!< 0x00000100 */
#define USB_OTG_DIEPINT_TXFIFOUDRN               USB_OTG_DIEPINT_TXFIFOUDRN_Msk /*!< Transmit Fifo Underrun */
#define USB_OTG_DIEPINT_BNA_Pos                  (9U)                          
#define USB_OTG_DIEPINT_BNA_Msk                  (0x1UL << USB_OTG_DIEPINT_BNA_Pos) /*!< 0x00000200 */
#define USB_OTG_DIEPINT_BNA                      USB_OTG_DIEPINT_BNA_Msk       /*!< Buffer not available interrupt */
#define USB_OTG_DIEPINT_PKTDRPSTS_Pos            (11U)                         
#define USB_OTG_DIEPINT_PKTDRPSTS_Msk            (0x1UL << USB_OTG_DIEPINT_PKTDRPSTS_Pos) /*!< 0x00000800 */
#define USB_OTG_DIEPINT_PKTDRPSTS                USB_OTG_DIEPINT_PKTDRPSTS_Msk /*!< Packet dropped status */
#define USB_OTG_DIEPINT_BERR_Pos                 (12U)                         
#define USB_OTG_DIEPINT_BERR_Msk                 (0x1UL << USB_OTG_DIEPINT_BERR_Pos) /*!< 0x00001000 */
#define USB_OTG_DIEPINT_BERR                     USB_OTG_DIEPINT_BERR_Msk      /*!< Babble error interrupt */
#define USB_OTG_DIEPINT_NAK_Pos                  (13U)                         
#define USB_OTG_DIEPINT_NAK_Msk                  (0x1UL << USB_OTG_DIEPINT_NAK_Pos) /*!< 0x00002000 */
#define USB_OTG_DIEPINT_NAK                      USB_OTG_DIEPINT_NAK_Msk       /*!< NAK interrupt */

/********************  Bit definition forUSB_OTG_HCINTMSK register  ********************/
#define USB_OTG_HCINTMSK_XFRCM_Pos               (0U)                          
#define USB_OTG_HCINTMSK_XFRCM_Msk               (0x1UL << USB_OTG_HCINTMSK_XFRCM_Pos) /*!< 0x00000001 */
#define USB_OTG_HCINTMSK_XFRCM                   USB_OTG_HCINTMSK_XFRCM_Msk    /*!< Transfer completed mask */
#define USB_OTG_HCINTMSK_CHHM_Pos                (1U)                          
#define USB_OTG_HCINTMSK_CHHM_Msk                (0x1UL << USB_OTG_HCINTMSK_CHHM_Pos) /*!< 0x00000002 */
#define USB_OTG_HCINTMSK_CHHM                    USB_OTG_HCINTMSK_CHHM_Msk     /*!< Channel halted mask */
#define USB_OTG_HCINTMSK_AHBERR_Pos              (2U)                          
#define USB_OTG_HCINTMSK_AHBERR_Msk              (0x1UL << USB_OTG_HCINTMSK_AHBERR_Pos) /*!< 0x00000004 */
#define USB_OTG_HCINTMSK_AHBERR                  USB_OTG_HCINTMSK_AHBERR_Msk   /*!< AHB error */
#define USB_OTG_HCINTMSK_STALLM_Pos              (3U)                          
#define USB_OTG_HCINTMSK_STALLM_Msk              (0x1UL << USB_OTG_HCINTMSK_STALLM_Pos) /*!< 0x00000008 */
#define USB_OTG_HCINTMSK_STALLM                  USB_OTG_HCINTMSK_STALLM_Msk   /*!< STALL response received interrupt mask */
#define USB_OTG_HCINTMSK_NAKM_Pos                (4U)                          
#define USB_OTG_HCINTMSK_NAKM_Msk                (0x1UL << USB_OTG_HCINTMSK_NAKM_Pos) /*!< 0x00000010 */
#define USB_OTG_HCINTMSK_NAKM                    USB_OTG_HCINTMSK_NAKM_Msk     /*!< NAK response received interrupt mask */
#define USB_OTG_HCINTMSK_ACKM_Pos                (5U)                          
#define USB_OTG_HCINTMSK_ACKM_Msk                (0x1UL << USB_OTG_HCINTMSK_ACKM_Pos) /*!< 0x00000020 */
#define USB_OTG_HCINTMSK_ACKM                    USB_OTG_HCINTMSK_ACKM_Msk     /*!< ACK response received/transmitted interrupt mask */
#define USB_OTG_HCINTMSK_NYET_Pos                (6U)                          
#define USB_OTG_HCINTMSK_NYET_Msk                (0x1UL << USB_OTG_HCINTMSK_NYET_Pos) /*!< 0x00000040 */
#define USB_OTG_HCINTMSK_NYET                    USB_OTG_HCINTMSK_NYET_Msk     /*!< response received interrupt mask */
#define USB_OTG_HCINTMSK_TXERRM_Pos              (7U)                          
#define USB_OTG_HCINTMSK_TXERRM_Msk              (0x1UL << USB_OTG_HCINTMSK_TXERRM_Pos) /*!< 0x00000080 */
#define USB_OTG_HCINTMSK_TXERRM                  USB_OTG_HCINTMSK_TXERRM_Msk   /*!< Transaction error mask */
#define USB_OTG_HCINTMSK_BBERRM_Pos              (8U)                          
#define USB_OTG_HCINTMSK_BBERRM_Msk              (0x1UL << USB_OTG_HCINTMSK_BBERRM_Pos) /*!< 0x00000100 */
#define USB_OTG_HCINTMSK_BBERRM                  USB_OTG_HCINTMSK_BBERRM_Msk   /*!< Babble error mask */
#define USB_OTG_HCINTMSK_FRMORM_Pos              (9U)                          
#define USB_OTG_HCINTMSK_FRMORM_Msk              (0x1UL << USB_OTG_HCINTMSK_FRMORM_Pos) /*!< 0x00000200 */
#define USB_OTG_HCINTMSK_FRMORM                  USB_OTG_HCINTMSK_FRMORM_Msk   /*!< Frame overrun mask */
#define USB_OTG_HCINTMSK_DTERRM_Pos              (10U)                         
#define USB_OTG_HCINTMSK_DTERRM_Msk              (0x1UL << USB_OTG_HCINTMSK_DTERRM_Pos) /*!< 0x00000400 */
#define USB_OTG_HCINTMSK_DTERRM                  USB_OTG_HCINTMSK_DTERRM_Msk   /*!< Data toggle error mask */

/********************  Bit definition for USB_OTG_DIEPTSIZ register  ********************/

#define USB_OTG_DIEPTSIZ_XFRSIZ_Pos              (0U)                          
#define USB_OTG_DIEPTSIZ_XFRSIZ_Msk              (0x7FFFFUL << USB_OTG_DIEPTSIZ_XFRSIZ_Pos) /*!< 0x0007FFFF */
#define USB_OTG_DIEPTSIZ_XFRSIZ                  USB_OTG_DIEPTSIZ_XFRSIZ_Msk   /*!< Transfer size */
#define USB_OTG_DIEPTSIZ_PKTCNT_Pos              (19U)                         
#define USB_OTG_DIEPTSIZ_PKTCNT_Msk              (0x3FFUL << USB_OTG_DIEPTSIZ_PKTCNT_Pos) /*!< 0x1FF80000 */
#define USB_OTG_DIEPTSIZ_PKTCNT                  USB_OTG_DIEPTSIZ_PKTCNT_Msk   /*!< Packet count */
#define USB_OTG_DIEPTSIZ_MULCNT_Pos              (29U)                         
#define USB_OTG_DIEPTSIZ_MULCNT_Msk              (0x3UL << USB_OTG_DIEPTSIZ_MULCNT_Pos) /*!< 0x60000000 */
#define USB_OTG_DIEPTSIZ_MULCNT                  USB_OTG_DIEPTSIZ_MULCNT_Msk   /*!< Packet count */
/********************  Bit definition for USB_OTG_HCTSIZ register  ********************/
#define USB_OTG_HCTSIZ_XFRSIZ_Pos                (0U)                          
#define USB_OTG_HCTSIZ_XFRSIZ_Msk                (0x7FFFFUL << USB_OTG_HCTSIZ_XFRSIZ_Pos) /*!< 0x0007FFFF */
#define USB_OTG_HCTSIZ_XFRSIZ                    USB_OTG_HCTSIZ_XFRSIZ_Msk     /*!< Transfer size */
#define USB_OTG_HCTSIZ_PKTCNT_Pos                (19U)                         
#define USB_OTG_HCTSIZ_PKTCNT_Msk                (0x3FFUL << USB_OTG_HCTSIZ_PKTCNT_Pos) /*!< 0x1FF80000 */
#define USB_OTG_HCTSIZ_PKTCNT                    USB_OTG_HCTSIZ_PKTCNT_Msk     /*!< Packet count */
#define USB_OTG_HCTSIZ_DOPING_Pos                (31U)                         
#define USB_OTG_HCTSIZ_DOPING_Msk                (0x1UL << USB_OTG_HCTSIZ_DOPING_Pos) /*!< 0x80000000 */
#define USB_OTG_HCTSIZ_DOPING                    USB_OTG_HCTSIZ_DOPING_Msk     /*!< Do PING */
#define USB_OTG_HCTSIZ_DPID_Pos                  (29U)                         
#define USB_OTG_HCTSIZ_DPID_Msk                  (0x3UL << USB_OTG_HCTSIZ_DPID_Pos) /*!< 0x60000000 */
#define USB_OTG_HCTSIZ_DPID                      USB_OTG_HCTSIZ_DPID_Msk       /*!< Data PID */
#define USB_OTG_HCTSIZ_DPID_0                    (0x1UL << USB_OTG_HCTSIZ_DPID_Pos) /*!< 0x20000000 */
#define USB_OTG_HCTSIZ_DPID_1                    (0x2UL << USB_OTG_HCTSIZ_DPID_Pos) /*!< 0x40000000 */

/********************  Bit definition for USB_OTG_DIEPDMA register  ********************/
#define USB_OTG_DIEPDMA_DMAADDR_Pos              (0U)                          
#define USB_OTG_DIEPDMA_DMAADDR_Msk              (0xFFFFFFFFUL << USB_OTG_DIEPDMA_DMAADDR_Pos) /*!< 0xFFFFFFFF */
#define USB_OTG_DIEPDMA_DMAADDR                  USB_OTG_DIEPDMA_DMAADDR_Msk   /*!< DMA address */

/********************  Bit definition for USB_OTG_HCDMA register  ********************/
#define USB_OTG_HCDMA_DMAADDR_Pos                (0U)                          
#define USB_OTG_HCDMA_DMAADDR_Msk                (0xFFFFFFFFUL << USB_OTG_HCDMA_DMAADDR_Pos) /*!< 0xFFFFFFFF */
#define USB_OTG_HCDMA_DMAADDR                    USB_OTG_HCDMA_DMAADDR_Msk     /*!< DMA address */

/********************  Bit definition for USB_OTG_DTXFSTS register  ********************/
#define USB_OTG_DTXFSTS_INEPTFSAV_Pos            (0U)                          
#define USB_OTG_DTXFSTS_INEPTFSAV_Msk            (0xFFFFUL << USB_OTG_DTXFSTS_INEPTFSAV_Pos) /*!< 0x0000FFFF */
#define USB_OTG_DTXFSTS_INEPTFSAV                USB_OTG_DTXFSTS_INEPTFSAV_Msk /*!< IN endpoint TxFIFO space available */

/********************  Bit definition for USB_OTG_DIEPTXF register  ********************/
#define USB_OTG_DIEPTXF_INEPTXSA_Pos             (0U)                          
#define USB_OTG_DIEPTXF_INEPTXSA_Msk             (0xFFFFUL << USB_OTG_DIEPTXF_INEPTXSA_Pos) /*!< 0x0000FFFF */
#define USB_OTG_DIEPTXF_INEPTXSA                 USB_OTG_DIEPTXF_INEPTXSA_Msk  /*!< IN endpoint FIFOx transmit RAM start address */
#define USB_OTG_DIEPTXF_INEPTXFD_Pos             (16U)                         
#define USB_OTG_DIEPTXF_INEPTXFD_Msk             (0xFFFFUL << USB_OTG_DIEPTXF_INEPTXFD_Pos) /*!< 0xFFFF0000 */
#define USB_OTG_DIEPTXF_INEPTXFD                 USB_OTG_DIEPTXF_INEPTXFD_Msk  /*!< IN endpoint TxFIFO depth */

/********************  Bit definition for USB_OTG_DOEPCTL register  ********************/

#define USB_OTG_DOEPCTL_MPSIZ_Pos                (0U)                          
#define USB_OTG_DOEPCTL_MPSIZ_Msk                (0x7FFUL << USB_OTG_DOEPCTL_MPSIZ_Pos) /*!< 0x000007FF */
#define USB_OTG_DOEPCTL_MPSIZ                    USB_OTG_DOEPCTL_MPSIZ_Msk     /*!< Maximum packet size */          /*!<Bit 1 */
#define USB_OTG_DOEPCTL_USBAEP_Pos               (15U)                         
#define USB_OTG_DOEPCTL_USBAEP_Msk               (0x1UL << USB_OTG_DOEPCTL_USBAEP_Pos) /*!< 0x00008000 */
#define USB_OTG_DOEPCTL_USBAEP                   USB_OTG_DOEPCTL_USBAEP_Msk    /*!< USB active endpoint */
#define USB_OTG_DOEPCTL_NAKSTS_Pos               (17U)                         
#define USB_OTG_DOEPCTL_NAKSTS_Msk               (0x1UL << USB_OTG_DOEPCTL_NAKSTS_Pos) /*!< 0x00020000 */
#define USB_OTG_DOEPCTL_NAKSTS                   USB_OTG_DOEPCTL_NAKSTS_Msk    /*!< NAK status */
#define USB_OTG_DOEPCTL_SD0PID_SEVNFRM_Pos       (28U)                         
#define USB_OTG_DOEPCTL_SD0PID_SEVNFRM_Msk       (0x1UL << USB_OTG_DOEPCTL_SD0PID_SEVNFRM_Pos) /*!< 0x10000000 */
#define USB_OTG_DOEPCTL_SD0PID_SEVNFRM           USB_OTG_DOEPCTL_SD0PID_SEVNFRM_Msk /*!< Set DATA0 PID */
#define USB_OTG_DOEPCTL_SODDFRM_Pos              (29U)                         
#define USB_OTG_DOEPCTL_SODDFRM_Msk              (0x1UL << USB_OTG_DOEPCTL_SODDFRM_Pos) /*!< 0x20000000 */
#define USB_OTG_DOEPCTL_SODDFRM                  USB_OTG_DOEPCTL_SODDFRM_Msk   /*!< Set odd frame */
#define USB_OTG_DOEPCTL_EPTYP_Pos                (18U)                         
#define USB_OTG_DOEPCTL_EPTYP_Msk                (0x3UL << USB_OTG_DOEPCTL_EPTYP_Pos) /*!< 0x000C0000 */
#define USB_OTG_DOEPCTL_EPTYP                    USB_OTG_DOEPCTL_EPTYP_Msk     /*!< Endpoint type */
#define USB_OTG_DOEPCTL_EPTYP_0                  (0x1UL << USB_OTG_DOEPCTL_EPTYP_Pos) /*!< 0x00040000 */
#define USB_OTG_DOEPCTL_EPTYP_1                  (0x2UL << USB_OTG_DOEPCTL_EPTYP_Pos) /*!< 0x00080000 */
#define USB_OTG_DOEPCTL_SNPM_Pos                 (20U)                         
#define USB_OTG_DOEPCTL_SNPM_Msk                 (0x1UL << USB_OTG_DOEPCTL_SNPM_Pos) /*!< 0x00100000 */
#define USB_OTG_DOEPCTL_SNPM                     USB_OTG_DOEPCTL_SNPM_Msk      /*!< Snoop mode */
#define USB_OTG_DOEPCTL_STALL_Pos                (21U)                         
#define USB_OTG_DOEPCTL_STALL_Msk                (0x1UL << USB_OTG_DOEPCTL_STALL_Pos) /*!< 0x00200000 */
#define USB_OTG_DOEPCTL_STALL                    USB_OTG_DOEPCTL_STALL_Msk     /*!< STALL handshake */
#define USB_OTG_DOEPCTL_CNAK_Pos                 (26U)                         
#define USB_OTG_DOEPCTL_CNAK_Msk                 (0x1UL << USB_OTG_DOEPCTL_CNAK_Pos) /*!< 0x04000000 */
#define USB_OTG_DOEPCTL_CNAK                     USB_OTG_DOEPCTL_CNAK_Msk      /*!< Clear NAK */
#define USB_OTG_DOEPCTL_SNAK_Pos                 (27U)                         
#define USB_OTG_DOEPCTL_SNAK_Msk                 (0x1UL << USB_OTG_DOEPCTL_SNAK_Pos) /*!< 0x08000000 */
#define USB_OTG_DOEPCTL_SNAK                     USB_OTG_DOEPCTL_SNAK_Msk      /*!< Set NAK */
#define USB_OTG_DOEPCTL_EPDIS_Pos                (30U)                         
#define USB_OTG_DOEPCTL_EPDIS_Msk                (0x1UL << USB_OTG_DOEPCTL_EPDIS_Pos) /*!< 0x40000000 */
#define USB_OTG_DOEPCTL_EPDIS                    USB_OTG_DOEPCTL_EPDIS_Msk     /*!< Endpoint disable */
#define USB_OTG_DOEPCTL_EPENA_Pos                (31U)                         
#define USB_OTG_DOEPCTL_EPENA_Msk                (0x1UL << USB_OTG_DOEPCTL_EPENA_Pos) /*!< 0x80000000 */
#define USB_OTG_DOEPCTL_EPENA                    USB_OTG_DOEPCTL_EPENA_Msk     /*!< Endpoint enable */

/********************  Bit definition for USB_OTG_DOEPINT register  ********************/
#define USB_OTG_DOEPINT_XFRC_Pos                 (0U)                          
#define USB_OTG_DOEPINT_XFRC_Msk                 (0x1UL << USB_OTG_DOEPINT_XFRC_Pos) /*!< 0x00000001 */
#define USB_OTG_DOEPINT_XFRC                     USB_OTG_DOEPINT_XFRC_Msk      /*!< Transfer completed interrupt */
#define USB_OTG_DOEPINT_EPDISD_Pos               (1U)                          
#define USB_OTG_DOEPINT_EPDISD_Msk               (0x1UL << USB_OTG_DOEPINT_EPDISD_Pos) /*!< 0x00000002 */
#define USB_OTG_DOEPINT_EPDISD                   USB_OTG_DOEPINT_EPDISD_Msk    /*!< Endpoint disabled interrupt */
#define USB_OTG_DOEPINT_AHBERR_Pos               (2U)
#define USB_OTG_DOEPINT_AHBERR_Msk               (0x1UL << USB_OTG_DOEPINT_AHBERR_Pos) /*!< 0x00000004 */
#define USB_OTG_DOEPINT_AHBERR                   USB_OTG_DOEPINT_AHBERR_Msk   /*!< AHB Error (AHBErr) during an OUT transaction */
#define USB_OTG_DOEPINT_STUP_Pos                 (3U)                          
#define USB_OTG_DOEPINT_STUP_Msk                 (0x1UL << USB_OTG_DOEPINT_STUP_Pos) /*!< 0x00000008 */
#define USB_OTG_DOEPINT_STUP                     USB_OTG_DOEPINT_STUP_Msk      /*!< SETUP phase done */
#define USB_OTG_DOEPINT_OTEPDIS_Pos              (4U)                          
#define USB_OTG_DOEPINT_OTEPDIS_Msk              (0x1UL << USB_OTG_DOEPINT_OTEPDIS_Pos) /*!< 0x00000010 */
#define USB_OTG_DOEPINT_OTEPDIS                  USB_OTG_DOEPINT_OTEPDIS_Msk   /*!< OUT token received when endpoint disabled */
#define USB_OTG_DOEPINT_OTEPSPR_Pos              (5U)                          
#define USB_OTG_DOEPINT_OTEPSPR_Msk              (0x1UL << USB_OTG_DOEPINT_OTEPSPR_Pos) /*!< 0x00000020 */
#define USB_OTG_DOEPINT_OTEPSPR                  USB_OTG_DOEPINT_OTEPSPR_Msk   /*!< Status Phase Received For Control Write */
#define USB_OTG_DOEPINT_B2BSTUP_Pos              (6U)                          
#define USB_OTG_DOEPINT_B2BSTUP_Msk              (0x1UL << USB_OTG_DOEPINT_B2BSTUP_Pos) /*!< 0x00000040 */
#define USB_OTG_DOEPINT_B2BSTUP                  USB_OTG_DOEPINT_B2BSTUP_Msk   /*!< Back-to-back SETUP packets received */
#define USB_OTG_DOEPINT_OUTPKTERR_Pos            (8U)
#define USB_OTG_DOEPINT_OUTPKTERR_Msk            (0x1UL << USB_OTG_DOEPINT_OUTPKTERR_Pos) /*!< 0x00000100 */
#define USB_OTG_DOEPINT_OUTPKTERR                USB_OTG_DOEPINT_OUTPKTERR_Msk   /*!< OUT packet error */
#define USB_OTG_DOEPINT_NAK_Pos                  (13U)
#define USB_OTG_DOEPINT_NAK_Msk                  (0x1UL << USB_OTG_DOEPINT_NAK_Pos) /*!< 0x00002000 */
#define USB_OTG_DOEPINT_NAK                      USB_OTG_DOEPINT_NAK_Msk   /*!< NAK Packet is transmitted by the device */
#define USB_OTG_DOEPINT_NYET_Pos                 (14U)                         
#define USB_OTG_DOEPINT_NYET_Msk                 (0x1UL << USB_OTG_DOEPINT_NYET_Pos) /*!< 0x00004000 */
#define USB_OTG_DOEPINT_NYET                     USB_OTG_DOEPINT_NYET_Msk      /*!< NYET interrupt */
#define USB_OTG_DOEPINT_STPKTRX_Pos              (15U)
#define USB_OTG_DOEPINT_STPKTRX_Msk              (0x1UL << USB_OTG_DOEPINT_STPKTRX_Pos) /*!< 0x00008000 */
#define USB_OTG_DOEPINT_STPKTRX                  USB_OTG_DOEPINT_STPKTRX_Msk   /*!< Setup Packet Received */
/********************  Bit definition for USB_OTG_DOEPTSIZ register  ********************/

#define USB_OTG_DOEPTSIZ_XFRSIZ_Pos              (0U)                          
#define USB_OTG_DOEPTSIZ_XFRSIZ_Msk              (0x7FFFFUL << USB_OTG_DOEPTSIZ_XFRSIZ_Pos) /*!< 0x0007FFFF */
#define USB_OTG_DOEPTSIZ_XFRSIZ                  USB_OTG_DOEPTSIZ_XFRSIZ_Msk   /*!< Transfer size */
#define USB_OTG_DOEPTSIZ_PKTCNT_Pos              (19U)                         
#define USB_OTG_DOEPTSIZ_PKTCNT_Msk              (0x3FFUL << USB_OTG_DOEPTSIZ_PKTCNT_Pos) /*!< 0x1FF80000 */
#define USB_OTG_DOEPTSIZ_PKTCNT                  USB_OTG_DOEPTSIZ_PKTCNT_Msk   /*!< Packet count */

#define USB_OTG_DOEPTSIZ_STUPCNT_Pos             (29U)                         
#define USB_OTG_DOEPTSIZ_STUPCNT_Msk             (0x3UL << USB_OTG_DOEPTSIZ_STUPCNT_Pos) /*!< 0x60000000 */
#define USB_OTG_DOEPTSIZ_STUPCNT                 USB_OTG_DOEPTSIZ_STUPCNT_Msk  /*!< SETUP packet count */
#define USB_OTG_DOEPTSIZ_STUPCNT_0               (0x1UL << USB_OTG_DOEPTSIZ_STUPCNT_Pos) /*!< 0x20000000 */
#define USB_OTG_DOEPTSIZ_STUPCNT_1               (0x2UL << USB_OTG_DOEPTSIZ_STUPCNT_Pos) /*!< 0x40000000 */

/********************  Bit definition for PCGCCTL register  ********************/
#define USB_OTG_PCGCCTL_STOPCLK_Pos              (0U)                          
#define USB_OTG_PCGCCTL_STOPCLK_Msk              (0x1UL << USB_OTG_PCGCCTL_STOPCLK_Pos) /*!< 0x00000001 */
#define USB_OTG_PCGCCTL_STOPCLK                  USB_OTG_PCGCCTL_STOPCLK_Msk   /*!< SETUP packet count */
#define USB_OTG_PCGCCTL_GATECLK_Pos              (1U)                          
#define USB_OTG_PCGCCTL_GATECLK_Msk              (0x1UL << USB_OTG_PCGCCTL_GATECLK_Pos) /*!< 0x00000002 */
#define USB_OTG_PCGCCTL_GATECLK                  USB_OTG_PCGCCTL_GATECLK_Msk   /*!<Bit 0 */
#define USB_OTG_PCGCCTL_PHYSUSP_Pos              (4U)                          
#define USB_OTG_PCGCCTL_PHYSUSP_Msk              (0x1UL << USB_OTG_PCGCCTL_PHYSUSP_Pos) /*!< 0x00000010 */
#define USB_OTG_PCGCCTL_PHYSUSP                  USB_OTG_PCGCCTL_PHYSUSP_Msk   /*!<Bit 1 */

/* Legacy define */
/********************  Bit definition for OTG register  ********************/
#define USB_OTG_CHNUM_Pos                        (0U)                          
#define USB_OTG_CHNUM_Msk                        (0xFUL << USB_OTG_CHNUM_Pos)   /*!< 0x0000000F */
#define USB_OTG_CHNUM                            USB_OTG_CHNUM_Msk             /*!< Channel number */
#define USB_OTG_CHNUM_0                          (0x1UL << USB_OTG_CHNUM_Pos)   /*!< 0x00000001 */
#define USB_OTG_CHNUM_1                          (0x2UL << USB_OTG_CHNUM_Pos)   /*!< 0x00000002 */
#define USB_OTG_CHNUM_2                          (0x4UL << USB_OTG_CHNUM_Pos)   /*!< 0x00000004 */
#define USB_OTG_CHNUM_3                          (0x8UL << USB_OTG_CHNUM_Pos)   /*!< 0x00000008 */
#define USB_OTG_BCNT_Pos                         (4U)                          
#define USB_OTG_BCNT_Msk                         (0x7FFUL << USB_OTG_BCNT_Pos)  /*!< 0x00007FF0 */
#define USB_OTG_BCNT                             USB_OTG_BCNT_Msk              /*!< Byte count */

#define USB_OTG_DPID_Pos                         (15U)                         
#define USB_OTG_DPID_Msk                         (0x3UL << USB_OTG_DPID_Pos)    /*!< 0x00018000 */
#define USB_OTG_DPID                             USB_OTG_DPID_Msk              /*!< Data PID */
#define USB_OTG_DPID_0                           (0x1UL << USB_OTG_DPID_Pos)    /*!< 0x00008000 */
#define USB_OTG_DPID_1                           (0x2UL << USB_OTG_DPID_Pos)    /*!< 0x00010000 */

#define USB_OTG_PKTSTS_Pos                       (17U)                         
#define USB_OTG_PKTSTS_Msk                       (0xFUL << USB_OTG_PKTSTS_Pos)  /*!< 0x001E0000 */
#define USB_OTG_PKTSTS                           USB_OTG_PKTSTS_Msk            /*!< Packet status */
#define USB_OTG_PKTSTS_0                         (0x1UL << USB_OTG_PKTSTS_Pos)  /*!< 0x00020000 */
#define USB_OTG_PKTSTS_1                         (0x2UL << USB_OTG_PKTSTS_Pos)  /*!< 0x00040000 */
#define USB_OTG_PKTSTS_2                         (0x4UL << USB_OTG_PKTSTS_Pos)  /*!< 0x00080000 */
#define USB_OTG_PKTSTS_3                         (0x8UL << USB_OTG_PKTSTS_Pos)  /*!< 0x00100000 */

#define USB_OTG_EPNUM_Pos                        (0U)                          
#define USB_OTG_EPNUM_Msk                        (0xFUL << USB_OTG_EPNUM_Pos)   /*!< 0x0000000F */
#define USB_OTG_EPNUM                            USB_OTG_EPNUM_Msk             /*!< Endpoint number */
#define USB_OTG_EPNUM_0                          (0x1UL << USB_OTG_EPNUM_Pos)   /*!< 0x00000001 */
#define USB_OTG_EPNUM_1                          (0x2UL << USB_OTG_EPNUM_Pos)   /*!< 0x00000002 */
#define USB_OTG_EPNUM_2                          (0x4UL << USB_OTG_EPNUM_Pos)   /*!< 0x00000004 */
#define USB_OTG_EPNUM_3                          (0x8UL << USB_OTG_EPNUM_Pos)   /*!< 0x00000008 */

#define USB_OTG_FRMNUM_Pos                       (21U)                         
#define USB_OTG_FRMNUM_Msk                       (0xFUL << USB_OTG_FRMNUM_Pos)  /*!< 0x01E00000 */
#define USB_OTG_FRMNUM                           USB_OTG_FRMNUM_Msk            /*!< Frame number */
#define USB_OTG_FRMNUM_0                         (0x1UL << USB_OTG_FRMNUM_Pos)  /*!< 0x00200000 */
#define USB_OTG_FRMNUM_1                         (0x2UL << USB_OTG_FRMNUM_Pos)  /*!< 0x00400000 */
#define USB_OTG_FRMNUM_2                         (0x4UL << USB_OTG_FRMNUM_Pos)  /*!< 0x00800000 */
#define USB_OTG_FRMNUM_3                         (0x8UL << USB_OTG_FRMNUM_Pos)  /*!< 0x01000000 */
/**
  * @}
  */ 

/**
  * @}
  */

/** @addtogroup Exported_macros
  * @{
  */

/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) (((INSTANCE) == ADC1) || \
                                       ((INSTANCE) == ADC2) || \
                                       ((INSTANCE) == ADC3))

#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC123_COMMON)

/******************************* CAN Instances ********************************/
#define IS_CAN_ALL_INSTANCE(INSTANCE) (((INSTANCE) == CAN1) || \
                                       ((INSTANCE) == CAN2))
/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/******************************* DAC Instances ********************************/
#define IS_DAC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DAC1)

/******************************* DCMI Instances *******************************/
#define IS_DCMI_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DCMI)

/******************************* DMA2D Instances *******************************/
#define IS_DMA2D_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DMA2D)

/******************************** DMA Instances *******************************/
#define IS_DMA_STREAM_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Stream0) || \
                                              ((INSTANCE) == DMA1_Stream1) || \
                                              ((INSTANCE) == DMA1_Stream2) || \
                                              ((INSTANCE) == DMA1_Stream3) || \
                                              ((INSTANCE) == DMA1_Stream4) || \
                                              ((INSTANCE) == DMA1_Stream5) || \
                                              ((INSTANCE) == DMA1_Stream6) || \
                                              ((INSTANCE) == DMA1_Stream7) || \
                                              ((INSTANCE) == DMA2_Stream0) || \
                                              ((INSTANCE) == DMA2_Stream1) || \
                                              ((INSTANCE) == DMA2_Stream2) || \
                                              ((INSTANCE) == DMA2_Stream3) || \
                                              ((INSTANCE) == DMA2_Stream4) || \
                                              ((INSTANCE) == DMA2_Stream5) || \
                                              ((INSTANCE) == DMA2_Stream6) || \
                                              ((INSTANCE) == DMA2_Stream7))

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOD) || \
                                        ((INSTANCE) == GPIOE) || \
                                        ((INSTANCE) == GPIOF) || \
                                        ((INSTANCE) == GPIOG) || \
                                        ((INSTANCE) == GPIOH) || \
                                        ((INSTANCE) == GPIOI) || \
                                        ((INSTANCE) == GPIOJ) || \
                                        ((INSTANCE) == GPIOK))

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2C1) || \
                                       ((INSTANCE) == I2C2) || \
                                       ((INSTANCE) == I2C3))

/******************************* SMBUS Instances ******************************/
#define IS_SMBUS_ALL_INSTANCE         IS_I2C_ALL_INSTANCE

/******************************** I2S Instances *******************************/

#define IS_I2S_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == SPI2) || \
                                       ((INSTANCE) == SPI3))

/*************************** I2S Extended Instances ***************************/
#define IS_I2S_EXT_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2S2ext)|| \
                                           ((INSTANCE) == I2S3ext))
/* Legacy Defines */
#define IS_I2S_ALL_INSTANCE_EXT    IS_I2S_EXT_ALL_INSTANCE

/****************************** LTDC Instances ********************************/
#define IS_LTDC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == LTDC)
/******************************* RNG Instances ********************************/
#define IS_RNG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RNG)

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

/******************************* SAI Instances ********************************/
#define IS_SAI_ALL_INSTANCE(PERIPH) (((PERIPH) == SAI1_Block_A) || \
                                     ((PERIPH) == SAI1_Block_B))
/* Legacy define */

#define IS_SAI_BLOCK_PERIPH IS_SAI_ALL_INSTANCE

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1)  || \
                                       ((INSTANCE) == SPI2)  || \
                                       ((INSTANCE) == SPI3)  || \
                                       ((INSTANCE) == SPI4)  || \
                                       ((INSTANCE) == SPI5)  || \
                                       ((INSTANCE) == SPI6))


/****************** TIM Instances : All supported instances *******************/
#define IS_TIM_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)  || \
                                    ((INSTANCE) == TIM2) || \
                                    ((INSTANCE) == TIM3) || \
                                    ((INSTANCE) == TIM4) || \
                                    ((INSTANCE) == TIM5) || \
                                    ((INSTANCE) == TIM6) || \
                                    ((INSTANCE) == TIM7) || \
                                    ((INSTANCE) == TIM8) || \
                                    ((INSTANCE) == TIM9) || \
                                    ((INSTANCE) == TIM10)|| \
                                    ((INSTANCE) == TIM11)|| \
                                    ((INSTANCE) == TIM12)|| \
                                    ((INSTANCE) == TIM13)|| \
                                    ((INSTANCE) == TIM14))

/************* TIM Instances : at least 1 capture/compare channel *************/
#define IS_TIM_CC1_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)  || \
                                         ((INSTANCE) == TIM2)  || \
                                         ((INSTANCE) == TIM3)  || \
                                         ((INSTANCE) == TIM4)  || \
                                         ((INSTANCE) == TIM5)  || \
                                         ((INSTANCE) == TIM8)  || \
                                         ((INSTANCE) == TIM9)  || \
                                         ((INSTANCE) == TIM10) || \
                                         ((INSTANCE) == TIM11) || \
                                         ((INSTANCE) == TIM12) || \
                                         ((INSTANCE) == TIM13) || \
                                         ((INSTANCE) == TIM14))

/************ TIM Instances : at least 2 capture/compare channels *************/
#define IS_TIM_CC2_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                       ((INSTANCE) == TIM2) || \
                                       ((INSTANCE) == TIM3) || \
                                       ((INSTANCE) == TIM4) || \
                                       ((INSTANCE) == TIM5) || \
                                       ((INSTANCE) == TIM8) || \
                                       ((INSTANCE) == TIM9) || \
                                       ((INSTANCE) == TIM12)) 

/************ TIM Instances : at least 3 capture/compare channels *************/
#define IS_TIM_CC3_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIM2) || \
                                         ((INSTANCE) == TIM3) || \
                                         ((INSTANCE) == TIM4) || \
                                         ((INSTANCE) == TIM5) || \
                                         ((INSTANCE) == TIM8))

/************ TIM Instances : at least 4 capture/compare channels *************/
#define IS_TIM_CC4_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                       ((INSTANCE) == TIM2) || \
                                       ((INSTANCE) == TIM3) || \
                                       ((INSTANCE) == TIM4) || \
                                       ((INSTANCE) == TIM5) || \
                                       ((INSTANCE) == TIM8))

/******************** TIM Instances : Advanced-control timers *****************/
#define IS_TIM_ADVANCED_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                           ((INSTANCE) == TIM8))

/******************* TIM Instances : Timer input XOR function *****************/
#define IS_TIM_XOR_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIM2) || \
                                         ((INSTANCE) == TIM3) || \
                                         ((INSTANCE) == TIM4) || \
                                         ((INSTANCE) == TIM5) || \
                                         ((INSTANCE) == TIM8))

/****************** TIM Instances : DMA requests generation (UDE) *************/
#define IS_TIM_DMA_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                       ((INSTANCE) == TIM2) || \
                                       ((INSTANCE) == TIM3) || \
                                       ((INSTANCE) == TIM4) || \
                                       ((INSTANCE) == TIM5) || \
                                       ((INSTANCE) == TIM6) || \
                                       ((INSTANCE) == TIM7) || \
                                       ((INSTANCE) == TIM8))

/************ TIM Instances : DMA requests generation (CCxDE) *****************/
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                          ((INSTANCE) == TIM2) || \
                                          ((INSTANCE) == TIM3) || \
                                          ((INSTANCE) == TIM4) || \
                                          ((INSTANCE) == TIM5) || \
                                          ((INSTANCE) == TIM8))

/************ TIM Instances : DMA requests generation (COMDE) *****************/
#define IS_TIM_CCDMA_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                          ((INSTANCE) == TIM2) || \
                                          ((INSTANCE) == TIM3) || \
                                          ((INSTANCE) == TIM4) || \
                                          ((INSTANCE) == TIM5) || \
                                          ((INSTANCE) == TIM8))

/******************** TIM Instances : DMA burst feature ***********************/
#define IS_TIM_DMABURST_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                             ((INSTANCE) == TIM2) || \
                                             ((INSTANCE) == TIM3) || \
                                             ((INSTANCE) == TIM4) || \
                                             ((INSTANCE) == TIM5) || \
                                             ((INSTANCE) == TIM8))

/****** TIM Instances : master mode available (TIMx_CR2.MMS available )********/
#define IS_TIM_MASTER_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)  || \
                                          ((INSTANCE) == TIM2)  || \
                                          ((INSTANCE) == TIM3)  || \
                                          ((INSTANCE) == TIM4)  || \
                                          ((INSTANCE) == TIM5)  || \
                                          ((INSTANCE) == TIM6)  || \
                                          ((INSTANCE) == TIM7)  || \
                                          ((INSTANCE) == TIM8))

/*********** TIM Instances : Slave mode available (TIMx_SMCR available )*******/
#define IS_TIM_SLAVE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIM2) || \
                                         ((INSTANCE) == TIM3) || \
                                         ((INSTANCE) == TIM4) || \
                                         ((INSTANCE) == TIM5) || \
                                         ((INSTANCE) == TIM8) || \
                                         ((INSTANCE) == TIM9) || \
                                         ((INSTANCE) == TIM12))
/********************** TIM Instances : 32 bit Counter ************************/
#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE)(((INSTANCE) == TIM2) || \
                                              ((INSTANCE) == TIM5))

/***************** TIM Instances : external trigger input availabe ************/
#define IS_TIM_ETR_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                        ((INSTANCE) == TIM2) || \
                                        ((INSTANCE) == TIM3) || \
                                        ((INSTANCE) == TIM4) || \
                                        ((INSTANCE) == TIM5) || \
                                        ((INSTANCE) == TIM8))

/****************** TIM Instances : remapping capability **********************/
#define IS_TIM_REMAP_INSTANCE(INSTANCE) (((INSTANCE) == TIM2)  || \
                                         ((INSTANCE) == TIM5)  || \
                                         ((INSTANCE) == TIM11))

/******************* TIM Instances : output(s) available **********************/
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
    (((INSTANCE) == TIM8) &&                   \
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

/************ TIM Instances : complementary output(s) available ***************/
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

/****************** TIM Instances : supporting counting mode selection ********/
#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM4) || \
                                                        ((INSTANCE) == TIM5) || \
                                                        ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting clock division *****************/
#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)  || \
                                                  ((INSTANCE) == TIM2) || \
                                                  ((INSTANCE) == TIM3) || \
                                                  ((INSTANCE) == TIM4) || \
                                                  ((INSTANCE) == TIM5) || \
                                                  ((INSTANCE) == TIM8) || \
                                                  ((INSTANCE) == TIM9) || \
                                                  ((INSTANCE) == TIM10)|| \
                                                  ((INSTANCE) == TIM11)|| \
                                                  ((INSTANCE) == TIM12)|| \
                                                  ((INSTANCE) == TIM13)|| \
                                                  ((INSTANCE) == TIM14))

/****************** TIM Instances : supporting commutation event generation ***/
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)|| \
                                                     ((INSTANCE) == TIM8))


/****************** TIM Instances : supporting OCxREF clear *******************/
#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)        (((INSTANCE) == TIM1) || \
                                                       ((INSTANCE) == TIM2) || \
                                                       ((INSTANCE) == TIM3) || \
                                                       ((INSTANCE) == TIM4) || \
                                                       ((INSTANCE) == TIM5) || \
                                                       ((INSTANCE) == TIM8))

/****** TIM Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM4) || \
                                                        ((INSTANCE) == TIM5) || \
                                                        ((INSTANCE) == TIM8) || \
                                                        ((INSTANCE) == TIM9) || \
                                                        ((INSTANCE) == TIM12))

/****** TIM Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM4) || \
                                                        ((INSTANCE) == TIM5) || \
                                                        ((INSTANCE) == TIM8))

/****** TIM Instances : supporting external clock mode 1 for TIX inputs ******/
#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM4) || \
                                                        ((INSTANCE) == TIM5) || \
                                                        ((INSTANCE) == TIM8) || \
                                                        ((INSTANCE) == TIM9) || \
                                                        ((INSTANCE) == TIM12))

/********** TIM Instances : supporting internal trigger inputs(ITRX) *********/
#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)     (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2) || \
                                                        ((INSTANCE) == TIM3) || \
                                                        ((INSTANCE) == TIM4) || \
                                                        ((INSTANCE) == TIM5) || \
                                                        ((INSTANCE) == TIM8) || \
                                                        ((INSTANCE) == TIM9) || \
                                                        ((INSTANCE) == TIM12))

/****************** TIM Instances : supporting repetition counter *************/
#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                                       ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting encoder interface **************/
#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                                      ((INSTANCE) == TIM2) || \
                                                      ((INSTANCE) == TIM3) || \
                                                      ((INSTANCE) == TIM4) || \
                                                      ((INSTANCE) == TIM5) || \
                                                      ((INSTANCE) == TIM8) || \
                                                      ((INSTANCE) == TIM9) || \
                                                      ((INSTANCE) == TIM12))
/****************** TIM Instances : supporting Hall sensor interface **********/
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                                          ((INSTANCE) == TIM2) || \
                                                          ((INSTANCE) == TIM3) || \
                                                          ((INSTANCE) == TIM4) || \
                                                          ((INSTANCE) == TIM5) || \
                                                          ((INSTANCE) == TIM8))
/****************** TIM Instances : supporting the break function *************/
#define IS_TIM_BREAK_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                          ((INSTANCE) == TIM8))

/******************** USART Instances : Synchronous mode **********************/
#define IS_USART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2) || \
                                     ((INSTANCE) == USART3) || \
                                     ((INSTANCE) == USART6))

/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                               ((INSTANCE) == USART2) || \
                                               ((INSTANCE) == USART3) || \
                                               ((INSTANCE) == UART4)  || \
                                               ((INSTANCE) == UART5)  || \
                                               ((INSTANCE) == USART6) || \
                                               ((INSTANCE) == UART7)  || \
                                               ((INSTANCE) == UART8))

/* Legacy defines */
#define IS_UART_INSTANCE          IS_UART_HALFDUPLEX_INSTANCE

/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2) || \
                                           ((INSTANCE) == USART3) || \
                                           ((INSTANCE) == USART6))
/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE          IS_UART_HALFDUPLEX_INSTANCE

/********************* UART Instances : Smart card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2) || \
                                         ((INSTANCE) == USART3) || \
                                         ((INSTANCE) == USART6))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) || \
                                    ((INSTANCE) == USART3) || \
                                    ((INSTANCE) == UART4)  || \
                                    ((INSTANCE) == UART5)  || \
                                    ((INSTANCE) == USART6) || \
                                    ((INSTANCE) == UART7)  || \
                                    ((INSTANCE) == UART8))                                     

/*********************** PCD Instances ****************************************/
#define IS_PCD_ALL_INSTANCE(INSTANCE) (((INSTANCE) == USB_OTG_FS) || \
                                       ((INSTANCE) == USB_OTG_HS))

/*********************** HCD Instances ****************************************/
#define IS_HCD_ALL_INSTANCE(INSTANCE) (((INSTANCE) == USB_OTG_FS) || \
                                       ((INSTANCE) == USB_OTG_HS))

/****************************** SDIO Instances ********************************/
#define IS_SDIO_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SDIO)

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG)

/****************************** USB Exported Constants ************************/
#define USB_OTG_FS_HOST_MAX_CHANNEL_NBR                8U
#define USB_OTG_FS_MAX_IN_ENDPOINTS                    4U    /* Including EP0 */
#define USB_OTG_FS_MAX_OUT_ENDPOINTS                   4U    /* Including EP0 */
#define USB_OTG_FS_TOTAL_FIFO_SIZE                     1280U /* in Bytes */

/*
 * @brief Specific devices reset values definitions
 */
#define RCC_PLLCFGR_RST_VALUE              0x24003010U
#define RCC_PLLI2SCFGR_RST_VALUE           0x24003000U
#define RCC_PLLSAICFGR_RST_VALUE           0x24003000U

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

#define USB_OTG_HS_HOST_MAX_CHANNEL_NBR                12U
#define USB_OTG_HS_MAX_IN_ENDPOINTS                    6U    /* Including EP0 */
#define USB_OTG_HS_MAX_OUT_ENDPOINTS                   6U    /* Including EP0 */
#define USB_OTG_HS_TOTAL_FIFO_SIZE                     4096U /* in Bytes */
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

#endif /* __STM32F429xx_H */



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

