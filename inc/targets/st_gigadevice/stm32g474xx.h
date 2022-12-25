/**
  ******************************************************************************
  * @file    stm32g474xx.h
  * @author  MCD Application Team
  * @brief   CMSIS STM32G474xx Device Peripheral Access Layer Header File.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripherals registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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

/** @addtogroup stm32g474xx
  * @{
  */

#ifndef __STM32G474xx_H
#define __STM32G474xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief Configuration of the Cortex-M4 Processor and Core Peripherals
   */
#define __CM4_REV                 0x0001  /*!< Cortex-M4 revision r0p1                       */
#define __MPU_PRESENT             1       /*!< STM32G4XX provides an MPU                     */
#define __NVIC_PRIO_BITS          4       /*!< STM32G4XX uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1       /*!< FPU present                                   */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief STM32G4XX Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
typedef enum
{
/******  Cortex-M4 Processor Exceptions Numbers *********************************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Cortex-M4 Non Maskable Interrupt                                                 */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M4 Hard Fault Interrupt                                                   */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                                            */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                                    */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                                  */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                                     */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                                               */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                                     */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                                 */
/******  STM32 specific Interrupt Numbers ***************************************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                                          */
  PVD_PVM_IRQn                = 1,      /*!< PVD/PVM1/PVM2/PVM3/PVM4 through EXTI Line detection Interrupts                     */
  RTC_TAMP_LSECSS_IRQn        = 2,      /*!< RTC Tamper and TimeStamp and RCC LSE CSS interrupts through the EXTI               */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                                         */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                                             */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                                               */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                                               */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                                               */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                                               */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                                               */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                                               */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                                                    */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                                                    */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                                                    */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                                                    */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                                                    */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                                                    */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                                                    */
  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                                                     */
  USB_HP_IRQn                 = 19,     /*!< USB HP Interrupt                                                                   */
  USB_LP_IRQn                 = 20,     /*!< USB LP  Interrupt                                                                  */
  FDCAN1_IT0_IRQn             = 21,     /*!< FDCAN1 IT0 Interrupt                                                               */
  FDCAN1_IT1_IRQn             = 22,     /*!< FDCAN1 IT1 Interrupt                                                               */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                                      */
  TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 Break, Transition error, Index error and TIM15 global interrupt               */
  TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM16 global interrupt                                   */
  TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 TIM1 Trigger, Commutation, Direction change, Index and TIM17 global interrupt */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                                     */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                                              */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                                              */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                                              */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                                               */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                                               */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                                               */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                                               */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                                              */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                                              */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                                            */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                                            */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                                            */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                                    */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                                    */
  USBWakeUp_IRQn              = 42,     /*!< USB Wakeup through EXTI line Interrupt                                             */
  TIM8_BRK_IRQn               = 43,     /*!< TIM8 Break, Transition error and Index error Interrupt                             */
  TIM8_UP_IRQn                = 44,     /*!< TIM8 Update Interrupt                                                              */
  TIM8_TRG_COM_IRQn           = 45,     /*!< TIM8 Trigger, Commutation, Direction change and Index Interrupt                    */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                                     */
  ADC3_IRQn                   = 47,     /*!< ADC3 global  Interrupt                                                             */
  FMC_IRQn                    = 48,     /*!< FMC global Interrupt                                                               */
  LPTIM1_IRQn                 = 49,     /*!< LP TIM1 Interrupt                                                                  */
  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                                              */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                                              */
  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                                             */
  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                                             */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&3 underrun error  interrupts                                  */
  TIM7_DAC_IRQn               = 55,     /*!< TIM7 global and DAC2&4 underrun error  interrupts                                  */
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                                                    */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                                                    */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                                                    */
  DMA2_Channel4_IRQn          = 59,     /*!< DMA2 Channel 4 global Interrupt                                                    */
  DMA2_Channel5_IRQn          = 60,     /*!< DMA2 Channel 5 global Interrupt                                                    */
  ADC4_IRQn                   = 61,     /*!< ADC4 global Interrupt                                                              */
  ADC5_IRQn                   = 62,     /*!< ADC5 global Interrupt                                                              */
  UCPD1_IRQn                  = 63,     /*!< UCPD global Interrupt                                                              */
  COMP1_2_3_IRQn              = 64,     /*!< COMP1, COMP2 and COMP3 Interrupts                                                  */
  COMP4_5_6_IRQn              = 65,     /*!< COMP4, COMP5 and COMP6                                                             */
  COMP7_IRQn                  = 66,     /*!< COMP7 Interrupt                                                                    */
  HRTIM1_Master_IRQn          = 67,     /*!< HRTIM Master Timer global Interrupt                                                */
  HRTIM1_TIMA_IRQn            = 68,     /*!< HRTIM Timer A global Interrupt                                                     */
  HRTIM1_TIMB_IRQn            = 69,     /*!< HRTIM Timer B global Interrupt                                                     */
  HRTIM1_TIMC_IRQn            = 70,     /*!< HRTIM Timer C global Interrupt                                                     */
  HRTIM1_TIMD_IRQn            = 71,     /*!< HRTIM Timer D global Interrupt                                                     */
  HRTIM1_TIME_IRQn            = 72,     /*!< HRTIM Timer E global Interrupt                                                     */
  HRTIM1_FLT_IRQn             = 73,     /*!< HRTIM Fault global Interrupt                                                       */
  HRTIM1_TIMF_IRQn            = 74,     /*!< HRTIM Timer F global Interrupt                                                     */
  CRS_IRQn                    = 75,     /*!< CRS global interrupt                                                               */
  SAI1_IRQn                   = 76,     /*!< Serial Audio Interface global interrupt                                            */
  TIM20_BRK_IRQn              = 77,     /*!< TIM20 Break, Transition error and Index error Interrupt                            */
  TIM20_UP_IRQn               = 78,     /*!< TIM20 Update interrupt                                                             */
  TIM20_TRG_COM_IRQn          = 79,     /*!< TIM20 Trigger, Commutation, Direction change and Index Interrupt                   */
  TIM20_CC_IRQn               = 80,     /*!< TIM20 Capture Compare interrupt                                                    */
  FPU_IRQn                    = 81,     /*!< FPU global interrupt                                                               */
  I2C4_EV_IRQn                = 82,     /*!< I2C4 Event interrupt                                                               */
  I2C4_ER_IRQn                = 83,     /*!< I2C4 Error interrupt                                                               */
  SPI4_IRQn                   = 84,     /*!< SPI4 Event interrupt                                                               */
  FDCAN2_IT0_IRQn             = 86,     /*!< FDCAN2 interrupt line 0 interrupt                                                  */
  FDCAN2_IT1_IRQn             = 87,     /*!< FDCAN2 interrupt line 1 interrupt                                                  */
  FDCAN3_IT0_IRQn             = 88,     /*!< FDCAN3 interrupt line 0 interrupt                                                  */
  FDCAN3_IT1_IRQn             = 89,     /*!< FDCAN3 interrupt line 1 interrupt                                                  */
  RNG_IRQn                    = 90,     /*!< RNG global interrupt                                                               */
  LPUART1_IRQn                = 91,     /*!< LP UART 1 Interrupt                                                                */
  I2C3_EV_IRQn                = 92,     /*!< I2C3 Event Interrupt                                                               */
  I2C3_ER_IRQn                = 93,     /*!< I2C3 Error interrupt                                                               */
  DMAMUX_OVR_IRQn             = 94,     /*!< DMAMUX overrun global interrupt                                                    */
  QUADSPI_IRQn                = 95,     /*!< QUADSPI interrupt                                                                  */
  DMA1_Channel8_IRQn          = 96,     /*!< DMA1 Channel 8 interrupt                                                           */
  DMA2_Channel6_IRQn          = 97,     /*!< DMA2 Channel 6 interrupt                                                           */
  DMA2_Channel7_IRQn          = 98,     /*!< DMA2 Channel 7 interrupt                                                           */
  DMA2_Channel8_IRQn          = 99,     /*!< DMA2 Channel 8 interrupt                                                           */
  CORDIC_IRQn                 = 100,    /*!< CORDIC global Interrupt                                                            */
  FMAC_IRQn                   = 101     /*!< FMAC global Interrupt                                                              */
} IRQn_Type;

/**
  * @}
  */

#include "../../cmsis/core_cm4.h"             /* Cortex-M4 processor and core peripherals */
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */

typedef struct
{
  __IO uint32_t ISR;          /*!< ADC interrupt and status register,             Address offset: 0x00 */
  __IO uint32_t IER;          /*!< ADC interrupt enable register,                 Address offset: 0x04 */
  __IO uint32_t CR;           /*!< ADC control register,                          Address offset: 0x08 */
  __IO uint32_t CFGR;         /*!< ADC configuration register 1,                  Address offset: 0x0C */
  __IO uint32_t CFGR2;        /*!< ADC configuration register 2,                  Address offset: 0x10 */
  __IO uint32_t SMPR1;        /*!< ADC sampling time register 1,                  Address offset: 0x14 */
  __IO uint32_t SMPR2;        /*!< ADC sampling time register 2,                  Address offset: 0x18 */
       uint32_t RESERVED1;    /*!< Reserved,                                                      0x1C */
  __IO uint32_t TR1;          /*!< ADC analog watchdog 1 threshold register,      Address offset: 0x20 */
  __IO uint32_t TR2;          /*!< ADC analog watchdog 2 threshold register,      Address offset: 0x24 */
  __IO uint32_t TR3;          /*!< ADC analog watchdog 3 threshold register,      Address offset: 0x28 */
       uint32_t RESERVED2;    /*!< Reserved,                                                      0x2C */
  __IO uint32_t SQR1;         /*!< ADC group regular sequencer register 1,        Address offset: 0x30 */
  __IO uint32_t SQR2;         /*!< ADC group regular sequencer register 2,        Address offset: 0x34 */
  __IO uint32_t SQR3;         /*!< ADC group regular sequencer register 3,        Address offset: 0x38 */
  __IO uint32_t SQR4;         /*!< ADC group regular sequencer register 4,        Address offset: 0x3C */
  __IO uint32_t DR;           /*!< ADC group regular data register,               Address offset: 0x40 */
       uint32_t RESERVED3;    /*!< Reserved,                                                      0x44 */
       uint32_t RESERVED4;    /*!< Reserved,                                                      0x48 */
  __IO uint32_t JSQR;         /*!< ADC group injected sequencer register,         Address offset: 0x4C */
       uint32_t RESERVED5[4]; /*!< Reserved,                                               0x50 - 0x5C */
  __IO uint32_t OFR1;         /*!< ADC offset register 1,                         Address offset: 0x60 */
  __IO uint32_t OFR2;         /*!< ADC offset register 2,                         Address offset: 0x64 */
  __IO uint32_t OFR3;         /*!< ADC offset register 3,                         Address offset: 0x68 */
  __IO uint32_t OFR4;         /*!< ADC offset register 4,                         Address offset: 0x6C */
       uint32_t RESERVED6[4]; /*!< Reserved,                                               0x70 - 0x7C */
  __IO uint32_t JDR1;         /*!< ADC group injected rank 1 data register,       Address offset: 0x80 */
  __IO uint32_t JDR2;         /*!< ADC group injected rank 2 data register,       Address offset: 0x84 */
  __IO uint32_t JDR3;         /*!< ADC group injected rank 3 data register,       Address offset: 0x88 */
  __IO uint32_t JDR4;         /*!< ADC group injected rank 4 data register,       Address offset: 0x8C */
       uint32_t RESERVED7[4]; /*!< Reserved,                                             0x090 - 0x09C */
  __IO uint32_t AWD2CR;       /*!< ADC analog watchdog 2 configuration register,  Address offset: 0xA0 */
  __IO uint32_t AWD3CR;       /*!< ADC analog watchdog 3 Configuration Register,  Address offset: 0xA4 */
       uint32_t RESERVED8;    /*!< Reserved,                                                     0x0A8 */
       uint32_t RESERVED9;    /*!< Reserved,                                                     0x0AC */
  __IO uint32_t DIFSEL;       /*!< ADC differential mode selection register,      Address offset: 0xB0 */
  __IO uint32_t CALFACT;      /*!< ADC calibration factors,                       Address offset: 0xB4 */
       uint32_t RESERVED10[2];/*!< Reserved,                                             0x0B8 - 0x0BC */
  __IO uint32_t GCOMP;        /*!< ADC calibration factors,                       Address offset: 0xC0 */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSR;          /*!< ADC common status register,            Address offset: 0x300 + 0x00 */
  uint32_t      RESERVED1;    /*!< Reserved,                              Address offset: 0x300 + 0x04 */
  __IO uint32_t CCR;          /*!< ADC common configuration register,     Address offset: 0x300 + 0x08 */
  __IO uint32_t CDR;          /*!< ADC common group regular data register Address offset: 0x300 + 0x0C */
} ADC_Common_TypeDef;

/**
  * @brief FD Controller Area Network
  */

typedef struct
{
  __IO uint32_t CREL;         /*!< FDCAN Core Release register,                                     Address offset: 0x000 */
  __IO uint32_t ENDN;         /*!< FDCAN Endian register,                                           Address offset: 0x004 */
       uint32_t RESERVED1;    /*!< Reserved,                                                                        0x008 */
  __IO uint32_t DBTP;         /*!< FDCAN Data Bit Timing & Prescaler register,                      Address offset: 0x00C */
  __IO uint32_t TEST;         /*!< FDCAN Test register,                                             Address offset: 0x010 */
  __IO uint32_t RWD;          /*!< FDCAN RAM Watchdog register,                                     Address offset: 0x014 */
  __IO uint32_t CCCR;         /*!< FDCAN CC Control register,                                       Address offset: 0x018 */
  __IO uint32_t NBTP;         /*!< FDCAN Nominal Bit Timing & Prescaler register,                   Address offset: 0x01C */
  __IO uint32_t TSCC;         /*!< FDCAN Timestamp Counter Configuration register,                  Address offset: 0x020 */
  __IO uint32_t TSCV;         /*!< FDCAN Timestamp Counter Value register,                          Address offset: 0x024 */
  __IO uint32_t TOCC;         /*!< FDCAN Timeout Counter Configuration register,                    Address offset: 0x028 */
  __IO uint32_t TOCV;         /*!< FDCAN Timeout Counter Value register,                            Address offset: 0x02C */
       uint32_t RESERVED2[4]; /*!< Reserved,                                                                0x030 - 0x03C */
  __IO uint32_t ECR;          /*!< FDCAN Error Counter register,                                    Address offset: 0x040 */
  __IO uint32_t PSR;          /*!< FDCAN Protocol Status register,                                  Address offset: 0x044 */
  __IO uint32_t TDCR;         /*!< FDCAN Transmitter Delay Compensation register,                   Address offset: 0x048 */
       uint32_t RESERVED3;    /*!< Reserved,                                                                        0x04C */
  __IO uint32_t IR;           /*!< FDCAN Interrupt register,                                        Address offset: 0x050 */
  __IO uint32_t IE;           /*!< FDCAN Interrupt Enable register,                                 Address offset: 0x054 */
  __IO uint32_t ILS;          /*!< FDCAN Interrupt Line Select register,                            Address offset: 0x058 */
  __IO uint32_t ILE;          /*!< FDCAN Interrupt Line Enable register,                            Address offset: 0x05C */
       uint32_t RESERVED4[8]; /*!< Reserved,                                                                0x060 - 0x07C */
  __IO uint32_t RXGFC;        /*!< FDCAN Global Filter Configuration register,                      Address offset: 0x080 */
  __IO uint32_t XIDAM;        /*!< FDCAN Extended ID AND Mask register,                             Address offset: 0x084 */
  __IO uint32_t HPMS;         /*!< FDCAN High Priority Message Status register,                     Address offset: 0x088 */
       uint32_t RESERVED5;    /*!< Reserved,                                                                        0x08C */
  __IO uint32_t RXF0S;        /*!< FDCAN Rx FIFO 0 Status register,                                 Address offset: 0x090 */
  __IO uint32_t RXF0A;        /*!< FDCAN Rx FIFO 0 Acknowledge register,                            Address offset: 0x094 */
  __IO uint32_t RXF1S;        /*!< FDCAN Rx FIFO 1 Status register,                                 Address offset: 0x098 */
  __IO uint32_t RXF1A;        /*!< FDCAN Rx FIFO 1 Acknowledge register,                            Address offset: 0x09C */
       uint32_t RESERVED6[8]; /*!< Reserved,                                                                0x0A0 - 0x0BC */
  __IO uint32_t TXBC;         /*!< FDCAN Tx Buffer Configuration register,                          Address offset: 0x0C0 */
  __IO uint32_t TXFQS;        /*!< FDCAN Tx FIFO/Queue Status register,                             Address offset: 0x0C4 */
  __IO uint32_t TXBRP;        /*!< FDCAN Tx Buffer Request Pending register,                        Address offset: 0x0C8 */
  __IO uint32_t TXBAR;        /*!< FDCAN Tx Buffer Add Request register,                            Address offset: 0x0CC */
  __IO uint32_t TXBCR;        /*!< FDCAN Tx Buffer Cancellation Request register,                   Address offset: 0x0D0 */
  __IO uint32_t TXBTO;        /*!< FDCAN Tx Buffer Transmission Occurred register,                  Address offset: 0x0D4 */
  __IO uint32_t TXBCF;        /*!< FDCAN Tx Buffer Cancellation Finished register,                  Address offset: 0x0D8 */
  __IO uint32_t TXBTIE;       /*!< FDCAN Tx Buffer Transmission Interrupt Enable register,          Address offset: 0x0DC */
  __IO uint32_t TXBCIE;       /*!< FDCAN Tx Buffer Cancellation Finished Interrupt Enable register, Address offset: 0x0E0 */
  __IO uint32_t TXEFS;        /*!< FDCAN Tx Event FIFO Status register,                             Address offset: 0x0E4 */
  __IO uint32_t TXEFA;        /*!< FDCAN Tx Event FIFO Acknowledge register,                        Address offset: 0x0E8 */
} FDCAN_GlobalTypeDef;

/**
  * @brief FD Controller Area Network Configuration
  */

typedef struct
{
  __IO uint32_t CKDIV;        /*!< FDCAN clock divider register,                            Address offset: 0x100 + 0x000 */
} FDCAN_Config_TypeDef;

/**
  * @brief Comparator
  */

typedef struct
{
  __IO uint32_t CSR;         /*!< COMP control and status register, Address offset: 0x00 */
} COMP_TypeDef;

/**
  * @brief CRC calculation unit
  */

typedef struct
{
  __IO uint32_t DR;          /*!< CRC Data register,                           Address offset: 0x00 */
  __IO uint32_t IDR;         /*!< CRC Independent data register,               Address offset: 0x04 */
  __IO uint32_t CR;          /*!< CRC Control register,                        Address offset: 0x08 */
  uint32_t      RESERVED0;   /*!< Reserved,                                                    0x0C */
  __IO uint32_t INIT;        /*!< Initial CRC value register,                  Address offset: 0x10 */
  __IO uint32_t POL;         /*!< CRC polynomial register,                     Address offset: 0x14 */
} CRC_TypeDef;

/**
  * @brief Clock Recovery System
  */
typedef struct
{
  __IO uint32_t CR;          /*!< CRS ccontrol register,              Address offset: 0x00 */
  __IO uint32_t CFGR;        /*!< CRS configuration register,         Address offset: 0x04 */
  __IO uint32_t ISR;         /*!< CRS interrupt and status register,  Address offset: 0x08 */
  __IO uint32_t ICR;         /*!< CRS interrupt flag clear register,  Address offset: 0x0C */
} CRS_TypeDef;

/**
  * @brief Digital to Analog Converter
  */

typedef struct
{
  __IO uint32_t CR;          /*!< DAC control register,                                    Address offset: 0x00 */
  __IO uint32_t SWTRIGR;     /*!< DAC software trigger register,                           Address offset: 0x04 */
  __IO uint32_t DHR12R1;     /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
  __IO uint32_t DHR12L1;     /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
  __IO uint32_t DHR8R1;      /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
  __IO uint32_t DHR12R2;     /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
  __IO uint32_t DHR12L2;     /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
  __IO uint32_t DHR8R2;      /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
  __IO uint32_t DHR12RD;     /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
  __IO uint32_t DHR12LD;     /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
  __IO uint32_t DHR8RD;      /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
  __IO uint32_t DOR1;        /*!< DAC channel1 data output register,                       Address offset: 0x2C */
  __IO uint32_t DOR2;        /*!< DAC channel2 data output register,                       Address offset: 0x30 */
  __IO uint32_t SR;          /*!< DAC status register,                                     Address offset: 0x34 */
  __IO uint32_t CCR;         /*!< DAC calibration control register,                        Address offset: 0x38 */
  __IO uint32_t MCR;         /*!< DAC mode control register,                               Address offset: 0x3C */
  __IO uint32_t SHSR1;       /*!< DAC Sample and Hold sample time register 1,              Address offset: 0x40 */
  __IO uint32_t SHSR2;       /*!< DAC Sample and Hold sample time register 2,              Address offset: 0x44 */
  __IO uint32_t SHHR;        /*!< DAC Sample and Hold hold time register,                  Address offset: 0x48 */
  __IO uint32_t SHRR;        /*!< DAC Sample and Hold refresh time register,               Address offset: 0x4C */
  __IO uint32_t RESERVED[2];
  __IO uint32_t STR1;        /*!< DAC Sawtooth register,                                   Address offset: 0x58 */
  __IO uint32_t STR2;        /*!< DAC Sawtooth register,                                   Address offset: 0x5C */
  __IO uint32_t STMODR;      /*!< DAC Sawtooth Mode register,                              Address offset: 0x60 */
} DAC_TypeDef;

/**
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;      /*!< MCU device ID code,                 Address offset: 0x00 */
  __IO uint32_t CR;          /*!< Debug MCU configuration register,   Address offset: 0x04 */
  __IO uint32_t APB1FZR1;    /*!< Debug MCU APB1 freeze register 1,   Address offset: 0x08 */
  __IO uint32_t APB1FZR2;    /*!< Debug MCU APB1 freeze register 2,   Address offset: 0x0C */
  __IO uint32_t APB2FZ;      /*!< Debug MCU APB2 freeze register,     Address offset: 0x10 */
} DBGMCU_TypeDef;

/**
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CCR;         /*!< DMA channel x configuration register        */
  __IO uint32_t CNDTR;       /*!< DMA channel x number of data register       */
  __IO uint32_t CPAR;        /*!< DMA channel x peripheral address register   */
  __IO uint32_t CMAR;        /*!< DMA channel x memory address register       */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;         /*!< DMA interrupt status register,                 Address offset: 0x00 */
  __IO uint32_t IFCR;        /*!< DMA interrupt flag clear register,             Address offset: 0x04 */
} DMA_TypeDef;

/**
  * @brief DMA Multiplexer
  */

typedef struct
{
  __IO uint32_t   CCR;       /*!< DMA Multiplexer Channel x Control Register    Address offset: 0x0004 * (channel x) */
}DMAMUX_Channel_TypeDef;

typedef struct
{
  __IO uint32_t   CSR;      /*!< DMA Channel Status Register                    Address offset: 0x0080   */
  __IO uint32_t   CFR;      /*!< DMA Channel Clear Flag Register                Address offset: 0x0084   */
}DMAMUX_ChannelStatus_TypeDef;

typedef struct
{
  __IO uint32_t   RGCR;        /*!< DMA Request Generator x Control Register     Address offset: 0x0100 + 0x0004 * (Req Gen x) */
}DMAMUX_RequestGen_TypeDef;

typedef struct
{
  __IO uint32_t   RGSR;        /*!< DMA Request Generator Status Register        Address offset: 0x0140   */
  __IO uint32_t   RGCFR;        /*!< DMA Request Generator Clear Flag Register    Address offset: 0x0144   */
}DMAMUX_RequestGenStatus_TypeDef;

/**
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t IMR1;        /*!< EXTI Interrupt mask register 1,             Address offset: 0x00 */
  __IO uint32_t EMR1;        /*!< EXTI Event mask register 1,                 Address offset: 0x04 */
  __IO uint32_t RTSR1;       /*!< EXTI Rising trigger selection register 1,   Address offset: 0x08 */
  __IO uint32_t FTSR1;       /*!< EXTI Falling trigger selection register 1,  Address offset: 0x0C */
  __IO uint32_t SWIER1;      /*!< EXTI Software interrupt event register 1,   Address offset: 0x10 */
  __IO uint32_t PR1;         /*!< EXTI Pending register 1,                    Address offset: 0x14 */
  uint32_t      RESERVED1;   /*!< Reserved, 0x18                                                   */
  uint32_t      RESERVED2;   /*!< Reserved, 0x1C                                                   */
  __IO uint32_t IMR2;        /*!< EXTI Interrupt mask register 2,             Address offset: 0x20 */
  __IO uint32_t EMR2;        /*!< EXTI Event mask register 2,                 Address offset: 0x24 */
  __IO uint32_t RTSR2;       /*!< EXTI Rising trigger selection register 2,   Address offset: 0x28 */
  __IO uint32_t FTSR2;       /*!< EXTI Falling trigger selection register 2,  Address offset: 0x2C */
  __IO uint32_t SWIER2;      /*!< EXTI Software interrupt event register 2,   Address offset: 0x30 */
  __IO uint32_t PR2;         /*!< EXTI Pending register 2,                    Address offset: 0x34 */
} EXTI_TypeDef;

/**
  * @brief FLASH Registers
  */

typedef struct
{
  __IO uint32_t ACR;              /*!< FLASH access control register,            Address offset: 0x00 */
  __IO uint32_t PDKEYR;           /*!< FLASH power down key register,            Address offset: 0x04 */
  __IO uint32_t KEYR;             /*!< FLASH key register,                       Address offset: 0x08 */
  __IO uint32_t OPTKEYR;          /*!< FLASH option key register,                Address offset: 0x0C */
  __IO uint32_t SR;               /*!< FLASH status register,                    Address offset: 0x10 */
  __IO uint32_t CR;               /*!< FLASH control register,                   Address offset: 0x14 */
  __IO uint32_t ECCR;             /*!< FLASH ECC register,                       Address offset: 0x18 */
       uint32_t RESERVED1;        /*!< Reserved1,                                Address offset: 0x1C */
  __IO uint32_t OPTR;             /*!< FLASH option register,                    Address offset: 0x20 */
  __IO uint32_t PCROP1SR;         /*!< FLASH bank1 PCROP start address register, Address offset: 0x24 */
  __IO uint32_t PCROP1ER;         /*!< FLASH bank1 PCROP end address register,   Address offset: 0x28 */
  __IO uint32_t WRP1AR;           /*!< FLASH bank1 WRP area A address register,  Address offset: 0x2C */
  __IO uint32_t WRP1BR;           /*!< FLASH bank1 WRP area B address register,  Address offset: 0x30 */
       uint32_t RESERVED2[4];     /*!< Reserved2,                                Address offset: 0x34 */
  __IO uint32_t PCROP2SR;         /*!< FLASH bank2 PCROP start address register, Address offset: 0x44 */
  __IO uint32_t PCROP2ER;         /*!< FLASH bank2 PCROP end address register,   Address offset: 0x48 */
  __IO uint32_t WRP2AR;           /*!< FLASH bank2 WRP area A address register,  Address offset: 0x4C */
  __IO uint32_t WRP2BR;           /*!< FLASH bank2 WRP area B address register,  Address offset: 0x50 */
       uint32_t RESERVED3[7];     /*!< Reserved3,                                Address offset: 0x54 */
  __IO uint32_t SEC1R;            /*!< FLASH Securable memory register bank1,    Address offset: 0x70 */
  __IO uint32_t SEC2R;            /*!< FLASH Securable memory register bank2,    Address offset: 0x74 */
} FLASH_TypeDef;

/**
  * @brief FMAC
  */
typedef struct
{
  __IO uint32_t X1BUFCFG;        /*!< FMAC X1 Buffer Configuration register, Address offset: 0x00          */
  __IO uint32_t X2BUFCFG;        /*!< FMAC X2 Buffer Configuration register, Address offset: 0x04          */
  __IO uint32_t YBUFCFG;         /*!< FMAC Y Buffer Configuration register,  Address offset: 0x08          */
  __IO uint32_t PARAM;           /*!< FMAC Parameter register,               Address offset: 0x0C          */
  __IO uint32_t CR;              /*!< FMAC Control register,                 Address offset: 0x10          */
  __IO uint32_t SR;              /*!< FMAC Status register,                  Address offset: 0x14          */
  __IO uint32_t WDATA;           /*!< FMAC Write Data register,              Address offset: 0x18          */
  __IO uint32_t RDATA;           /*!< FMAC Read Data register,               Address offset: 0x1C          */
} FMAC_TypeDef;

/**
  * @brief Flexible Memory Controller
  */

typedef struct
{
  __IO uint32_t BTCR[8];     /*!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */
  __IO uint32_t PCSCNTR;     /*!< PSRAM chip-select counter register,                                               Address offset:    0x20 */
} FMC_Bank1_TypeDef;

/**
  * @brief Flexible Memory Controller Bank1E
  */

typedef struct
{
  __IO uint32_t BWTR[7];     /*!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */
} FMC_Bank1E_TypeDef;

/**
  * @brief Flexible Memory Controller Bank3
  */

typedef struct
{
  __IO uint32_t PCR;        /*!< NAND Flash control register,                       Address offset: 0x80 */
  __IO uint32_t SR;         /*!< NAND Flash FIFO status and interrupt register,     Address offset: 0x84 */
  __IO uint32_t PMEM;       /*!< NAND Flash Common memory space timing register,    Address offset: 0x88 */
  __IO uint32_t PATT;       /*!< NAND Flash Attribute memory space timing register, Address offset: 0x8C */
  uint32_t      RESERVED0;  /*!< Reserved, 0x90                                                            */
  __IO uint32_t ECCR;       /*!< NAND Flash ECC result registers,                   Address offset: 0x94 */
} FMC_Bank3_TypeDef;

/**
  * @brief General Purpose I/O
  */

typedef struct
{
  __IO uint32_t MODER;       /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;      /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;     /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;       /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;         /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;         /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;        /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
  __IO uint32_t LCKR;        /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];      /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  __IO uint32_t BRR;         /*!< GPIO Bit Reset register,               Address offset: 0x28      */
} GPIO_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;         /*!< I2C Control register 1,            Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< I2C Control register 2,            Address offset: 0x04 */
  __IO uint32_t OAR1;        /*!< I2C Own address 1 register,        Address offset: 0x08 */
  __IO uint32_t OAR2;        /*!< I2C Own address 2 register,        Address offset: 0x0C */
  __IO uint32_t TIMINGR;     /*!< I2C Timing register,               Address offset: 0x10 */
  __IO uint32_t TIMEOUTR;    /*!< I2C Timeout register,              Address offset: 0x14 */
  __IO uint32_t ISR;         /*!< I2C Interrupt and status register, Address offset: 0x18 */
  __IO uint32_t ICR;         /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  __IO uint32_t PECR;        /*!< I2C PEC register,                  Address offset: 0x20 */
  __IO uint32_t RXDR;        /*!< I2C Receive data register,         Address offset: 0x24 */
  __IO uint32_t TXDR;        /*!< I2C Transmit data register,        Address offset: 0x28 */
} I2C_TypeDef;

/**
  * @brief Independent WATCHDOG
  */

typedef struct
{
  __IO uint32_t KR;          /*!< IWDG Key register,       Address offset: 0x00 */
  __IO uint32_t PR;          /*!< IWDG Prescaler register, Address offset: 0x04 */
  __IO uint32_t RLR;         /*!< IWDG Reload register,    Address offset: 0x08 */
  __IO uint32_t SR;          /*!< IWDG Status register,    Address offset: 0x0C */
  __IO uint32_t WINR;        /*!< IWDG Window register,    Address offset: 0x10 */
} IWDG_TypeDef;

/**
  * @brief LPTIMER
  */

typedef struct
{
  __IO uint32_t ISR;              /*!< LPTIM Interrupt and Status register,                Address offset: 0x00 */
  __IO uint32_t ICR;              /*!< LPTIM Interrupt Clear register,                     Address offset: 0x04 */
  __IO uint32_t IER;              /*!< LPTIM Interrupt Enable register,                    Address offset: 0x08 */
  __IO uint32_t CFGR;             /*!< LPTIM Configuration register,                       Address offset: 0x0C */
  __IO uint32_t CR;               /*!< LPTIM Control register,                             Address offset: 0x10 */
  __IO uint32_t CMP;              /*!< LPTIM Compare register,                             Address offset: 0x14 */
  __IO uint32_t ARR;              /*!< LPTIM Autoreload register,                          Address offset: 0x18 */
  __IO uint32_t CNT;              /*!< LPTIM Counter register,                             Address offset: 0x1C */
  __IO uint32_t OR;               /*!< LPTIM Option register,                              Address offset: 0x20 */
} LPTIM_TypeDef;

/**
  * @brief Operational Amplifier (OPAMP)
  */

typedef struct
{
  __IO uint32_t CSR;           /*!< OPAMP control/status register,                     Address offset: 0x00 */
  __IO uint32_t RESERVED[5];   /*!< OPAMP offset trimming register for normal mode,    Address offset: 0x04 */
  __IO uint32_t TCMR;          /*!< OPAMP timer controlled mux mode register,          Address offset: 0x18 */
} OPAMP_TypeDef;

/**
  * @brief Power Control
  */

typedef struct
{
  __IO uint32_t CR1;      /*!< PWR power control register 1,        Address offset: 0x00 */
  __IO uint32_t CR2;      /*!< PWR power control register 2,        Address offset: 0x04 */
  __IO uint32_t CR3;      /*!< PWR power control register 3,        Address offset: 0x08 */
  __IO uint32_t CR4;      /*!< PWR power control register 4,        Address offset: 0x0C */
  __IO uint32_t SR1;      /*!< PWR power status register 1,         Address offset: 0x10 */
  __IO uint32_t SR2;      /*!< PWR power status register 2,         Address offset: 0x14 */
  __IO uint32_t SCR;      /*!< PWR power status reset register,     Address offset: 0x18 */
  uint32_t RESERVED;      /*!< Reserved,                            Address offset: 0x1C */
  __IO uint32_t PUCRA;    /*!< Pull_up control register of portA,   Address offset: 0x20 */
  __IO uint32_t PDCRA;    /*!< Pull_Down control register of portA, Address offset: 0x24 */
  __IO uint32_t PUCRB;    /*!< Pull_up control register of portB,   Address offset: 0x28 */
  __IO uint32_t PDCRB;    /*!< Pull_Down control register of portB, Address offset: 0x2C */
  __IO uint32_t PUCRC;    /*!< Pull_up control register of portC,   Address offset: 0x30 */
  __IO uint32_t PDCRC;    /*!< Pull_Down control register of portC, Address offset: 0x34 */
  __IO uint32_t PUCRD;    /*!< Pull_up control register of portD,   Address offset: 0x38 */
  __IO uint32_t PDCRD;    /*!< Pull_Down control register of portD, Address offset: 0x3C */
  __IO uint32_t PUCRE;    /*!< Pull_up control register of portE,   Address offset: 0x40 */
  __IO uint32_t PDCRE;    /*!< Pull_Down control register of portE, Address offset: 0x44 */
  __IO uint32_t PUCRF;    /*!< Pull_up control register of portF,   Address offset: 0x48 */
  __IO uint32_t PDCRF;    /*!< Pull_Down control register of portF, Address offset: 0x4C */
  __IO uint32_t PUCRG;    /*!< Pull_up control register of portG,   Address offset: 0x50 */
  __IO uint32_t PDCRG;    /*!< Pull_Down control register of portG, Address offset: 0x54 */
  uint32_t RESERVED1[10]; /*!< Reserved                             Address offset: 0x58 - 0x7C */
  __IO uint32_t CR5;      /*!< PWR power control register 5,        Address offset: 0x80 */
} PWR_TypeDef;

/**
  * @brief QUAD Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR;          /*!< QUADSPI Control register,                           Address offset: 0x00 */
  __IO uint32_t DCR;         /*!< QUADSPI Device Configuration register,              Address offset: 0x04 */
  __IO uint32_t SR;          /*!< QUADSPI Status register,                            Address offset: 0x08 */
  __IO uint32_t FCR;         /*!< QUADSPI Flag Clear register,                        Address offset: 0x0C */
  __IO uint32_t DLR;         /*!< QUADSPI Data Length register,                       Address offset: 0x10 */
  __IO uint32_t CCR;         /*!< QUADSPI Communication Configuration register,       Address offset: 0x14 */
  __IO uint32_t AR;          /*!< QUADSPI Address register,                           Address offset: 0x18 */
  __IO uint32_t ABR;         /*!< QUADSPI Alternate Bytes register,                   Address offset: 0x1C */
  __IO uint32_t DR;          /*!< QUADSPI Data register,                              Address offset: 0x20 */
  __IO uint32_t PSMKR;       /*!< QUADSPI Polling Status Mask register,               Address offset: 0x24 */
  __IO uint32_t PSMAR;       /*!< QUADSPI Polling Status Match register,              Address offset: 0x28 */
  __IO uint32_t PIR;         /*!< QUADSPI Polling Interval register,                  Address offset: 0x2C */
  __IO uint32_t LPTR;        /*!< QUADSPI Low Power Timeout register,                 Address offset: 0x30 */
} QUADSPI_TypeDef;

/**
  * @brief Real-Time Clock
  */
/*
* @brief Specific device feature definitions
*/
#define RTC_TAMP_INT_6_SUPPORT
#define RTC_TAMP_INT_NB        4u

#define RTC_TAMP_NB            3u
#define RTC_BACKUP_NB          32u


typedef struct
{
  __IO uint32_t TR;          /*!< RTC time register,                                         Address offset: 0x00 */
  __IO uint32_t DR;          /*!< RTC date register,                                         Address offset: 0x04 */
  __IO uint32_t SSR;         /*!< RTC sub second register,                                   Address offset: 0x08 */
  __IO uint32_t ICSR;        /*!< RTC initialization control and status register,            Address offset: 0x0C */
  __IO uint32_t PRER;        /*!< RTC prescaler register,                                    Address offset: 0x10 */
  __IO uint32_t WUTR;        /*!< RTC wakeup timer register,                                 Address offset: 0x14 */
  __IO uint32_t CR;          /*!< RTC control register,                                      Address offset: 0x18 */
       uint32_t RESERVED0;   /*!< Reserved                                                   Address offset: 0x1C */
       uint32_t RESERVED1;   /*!< Reserved                                                   Address offset: 0x20 */
  __IO uint32_t WPR;         /*!< RTC write protection register,                             Address offset: 0x24 */
  __IO uint32_t CALR;        /*!< RTC calibration register,                                  Address offset: 0x28 */
  __IO uint32_t SHIFTR;      /*!< RTC shift control register,                                Address offset: 0x2C */
  __IO uint32_t TSTR;        /*!< RTC time stamp time register,                              Address offset: 0x30 */
  __IO uint32_t TSDR;        /*!< RTC time stamp date register,                              Address offset: 0x34 */
  __IO uint32_t TSSSR;       /*!< RTC time-stamp sub second register,                        Address offset: 0x38 */
       uint32_t RESERVED2;   /*!< Reserved                                                   Address offset: 0x3C */
  __IO uint32_t ALRMAR;      /*!< RTC alarm A register,                                      Address offset: 0x40 */
  __IO uint32_t ALRMASSR;    /*!< RTC alarm A sub second register,                           Address offset: 0x44 */
  __IO uint32_t ALRMBR;      /*!< RTC alarm B register,                                      Address offset: 0x48 */
  __IO uint32_t ALRMBSSR;    /*!< RTC alarm B sub second register,                           Address offset: 0x4C */
  __IO uint32_t SR;          /*!< RTC Status register,                                       Address offset: 0x50 */
  __IO uint32_t MISR;        /*!< RTC Masked Interrupt Status register,                      Address offset: 0x54 */
       uint32_t RESERVED3;   /*!< Reserved                                                   Address offset: 0x58 */
  __IO uint32_t SCR;         /*!< RTC Status Clear register,                                 Address offset: 0x5C */
} RTC_TypeDef;

/**
  * @brief Tamper and backup registers
  */

typedef struct
{
  __IO uint32_t CR1;                     /*!< TAMP configuration register 1,          Address offset: 0x00 */
  __IO uint32_t CR2;                     /*!< TAMP configuration register 2,          Address offset: 0x04 */
       uint32_t RESERVED0;               /*!< no configuration register 3,            Address offset: 0x08 */
  __IO uint32_t FLTCR;                   /*!< TAMP filter control register,           Address offset: 0x0C */
       uint32_t RESERVED1[6];            /*!< Reserved                                Address offset: 0x10 - 0x24 */
       uint32_t RESERVED2;               /*!< Reserved                                Address offset: 0x28 */
  __IO uint32_t IER;                     /*!< TAMP Interrupt enable register,         Address offset: 0x2C */
  __IO uint32_t SR;                      /*!< TAMP Status register,                   Address offset: 0x30 */
  __IO uint32_t MISR;                    /*!< TAMP Masked Interrupt Status register   Address offset: 0x34 */
       uint32_t RESERVED3;               /*!< Reserved                                Address offset: 0x38 */
  __IO uint32_t SCR;                     /*!< TAMP Status clear register,             Address offset: 0x3C */
       uint32_t RESERVED4[48];           /*!< Reserved                                Address offset: 0x040 - 0xFC */
  __IO uint32_t BKP0R;                   /*!< TAMP backup register 0,                 Address offset: 0x100 */
  __IO uint32_t BKP1R;                   /*!< TAMP backup register 1,                 Address offset: 0x104 */
  __IO uint32_t BKP2R;                   /*!< TAMP backup register 2,                 Address offset: 0x108 */
  __IO uint32_t BKP3R;                   /*!< TAMP backup register 3,                 Address offset: 0x10C */
  __IO uint32_t BKP4R;                   /*!< TAMP backup register 4,                 Address offset: 0x110 */
  __IO uint32_t BKP5R;                   /*!< TAMP backup register 5,                 Address offset: 0x114 */
  __IO uint32_t BKP6R;                   /*!< TAMP backup register 6,                 Address offset: 0x118 */
  __IO uint32_t BKP7R;                   /*!< TAMP backup register 7,                 Address offset: 0x11C */
  __IO uint32_t BKP8R;                   /*!< TAMP backup register 8,                 Address offset: 0x120 */
  __IO uint32_t BKP9R;                   /*!< TAMP backup register 9,                 Address offset: 0x124 */
  __IO uint32_t BKP10R;                  /*!< TAMP backup register 10,                Address offset: 0x128 */
  __IO uint32_t BKP11R;                  /*!< TAMP backup register 11,                Address offset: 0x12C */
  __IO uint32_t BKP12R;                  /*!< TAMP backup register 12,                Address offset: 0x130 */
  __IO uint32_t BKP13R;                  /*!< TAMP backup register 13,                Address offset: 0x134 */
  __IO uint32_t BKP14R;                  /*!< TAMP backup register 14,                Address offset: 0x138 */
  __IO uint32_t BKP15R;                  /*!< TAMP backup register 15,                Address offset: 0x13C */
  __IO uint32_t BKP16R;                  /*!< TAMP backup register 16,                Address offset: 0x140 */
  __IO uint32_t BKP17R;                  /*!< TAMP backup register 17,                Address offset: 0x144 */
  __IO uint32_t BKP18R;                  /*!< TAMP backup register 18,                Address offset: 0x148 */
  __IO uint32_t BKP19R;                  /*!< TAMP backup register 19,                Address offset: 0x14C */
  __IO uint32_t BKP20R;                  /*!< TAMP backup register 20,                Address offset: 0x150 */
  __IO uint32_t BKP21R;                  /*!< TAMP backup register 21,                Address offset: 0x154 */
  __IO uint32_t BKP22R;                  /*!< TAMP backup register 22,                Address offset: 0x158 */
  __IO uint32_t BKP23R;                  /*!< TAMP backup register 23,                Address offset: 0x15C */
  __IO uint32_t BKP24R;                  /*!< TAMP backup register 24,                Address offset: 0x160 */
  __IO uint32_t BKP25R;                  /*!< TAMP backup register 25,                Address offset: 0x164 */
  __IO uint32_t BKP26R;                  /*!< TAMP backup register 26,                Address offset: 0x168 */
  __IO uint32_t BKP27R;                  /*!< TAMP backup register 27,                Address offset: 0x16C */
  __IO uint32_t BKP28R;                  /*!< TAMP backup register 28,                Address offset: 0x170 */
  __IO uint32_t BKP29R;                  /*!< TAMP backup register 29,                Address offset: 0x174 */
  __IO uint32_t BKP30R;                  /*!< TAMP backup register 30,                Address offset: 0x178 */
  __IO uint32_t BKP31R;                  /*!< TAMP backup register 31,                Address offset: 0x17C */
} TAMP_TypeDef;

/**
  * @brief Serial Audio Interface
  */

typedef struct
{
  __IO uint32_t GCR;          /*!< SAI global configuration register,        Address offset: 0x00 */
  uint32_t      RESERVED[16]; /*!< Reserved,                         Address offset: 0x04 to 0x40 */
  __IO uint32_t PDMCR;        /*!< SAI PDM control register,                 Address offset: 0x44 */
  __IO uint32_t PDMDLY;       /*!< SAI PDM delay register,                   Address offset: 0x48 */
} SAI_TypeDef;

typedef struct
{
  __IO uint32_t CR1;         /*!< SAI block x configuration register 1,     Address offset: 0x04 */
  __IO uint32_t CR2;         /*!< SAI block x configuration register 2,     Address offset: 0x08 */
  __IO uint32_t FRCR;        /*!< SAI block x frame configuration register, Address offset: 0x0C */
  __IO uint32_t SLOTR;       /*!< SAI block x slot register,                Address offset: 0x10 */
  __IO uint32_t IMR;         /*!< SAI block x interrupt mask register,      Address offset: 0x14 */
  __IO uint32_t SR;          /*!< SAI block x status register,              Address offset: 0x18 */
  __IO uint32_t CLRFR;       /*!< SAI block x clear flag register,          Address offset: 0x1C */
  __IO uint32_t DR;          /*!< SAI block x data register,                Address offset: 0x20 */
} SAI_Block_TypeDef;

/**
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR1;         /*!< SPI Control register 1,                              Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< SPI Control register 2,                              Address offset: 0x04 */
  __IO uint32_t SR;          /*!< SPI Status register,                                 Address offset: 0x08 */
  __IO uint32_t DR;          /*!< SPI data register,                                  Address offset: 0x0C */
  __IO uint32_t CRCPR;       /*!< SPI CRC polynomial register,                         Address offset: 0x10 */
  __IO uint32_t RXCRCR;      /*!< SPI Rx CRC register,                                 Address offset: 0x14 */
  __IO uint32_t TXCRCR;      /*!< SPI Tx CRC register,                                 Address offset: 0x18 */
  __IO uint32_t I2SCFGR;     /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
  __IO uint32_t I2SPR;       /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */
} SPI_TypeDef;

/**
  * @brief System configuration controller
  */

typedef struct
{
  __IO uint32_t MEMRMP;      /*!< SYSCFG memory remap register,                        Address offset: 0x00      */
  __IO uint32_t CFGR1;       /*!< SYSCFG configuration register 1,                     Address offset: 0x04      */
  __IO uint32_t EXTICR[4];   /*!< SYSCFG external interrupt configuration registers,   Address offset: 0x08-0x14 */
  __IO uint32_t SCSR;        /*!< SYSCFG CCMSRAM control and status register,          Address offset: 0x18      */
  __IO uint32_t CFGR2;       /*!< SYSCFG configuration register 2,                     Address offset: 0x1C      */
  __IO uint32_t SWPR;        /*!< SYSCFG CCMSRAM write protection register,            Address offset: 0x20      */
  __IO uint32_t SKR;         /*!< SYSCFG CCMSRAM Key Register,                         Address offset: 0x24      */
} SYSCFG_TypeDef;

/**
  * @brief TIM
  */

typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,                   Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,                   Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,          Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,        Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                      Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,            Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1,      Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2,      Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register,      Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                     Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler,                            Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,                 Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,          Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,           Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,           Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,           Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,           Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,         Address offset: 0x44 */
  __IO uint32_t CCR5;        /*!< TIM capture/compare register 5,           Address offset: 0x48 */
  __IO uint32_t CCR6;        /*!< TIM capture/compare register 6,           Address offset: 0x4C */
  __IO uint32_t CCMR3;       /*!< TIM capture/compare mode register 3,      Address offset: 0x50 */
  __IO uint32_t DTR2;        /*!< TIM deadtime register 2,                  Address offset: 0x54 */
  __IO uint32_t ECR;         /*!< TIM encoder control register,             Address offset: 0x58 */
  __IO uint32_t TISEL;       /*!< TIM Input Selection register,             Address offset: 0x5C */
  __IO uint32_t AF1;         /*!< TIM alternate function option register 1, Address offset: 0x60 */
  __IO uint32_t AF2;         /*!< TIM alternate function option register 2, Address offset: 0x64 */
  __IO uint32_t OR ;         /*!< TIM option register,                      Address offset: 0x68 */
       uint32_t RESERVED0[220];/*!< Reserved,                               Address offset: 0x6C */
  __IO uint32_t DCR;         /*!< TIM DMA control register,                 Address offset: 0x3DC */
  __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,        Address offset: 0x3E0 */
} TIM_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< USART Control register 1,                 Address offset: 0x00  */
  __IO uint32_t CR2;         /*!< USART Control register 2,                 Address offset: 0x04  */
  __IO uint32_t CR3;         /*!< USART Control register 3,                 Address offset: 0x08  */
  __IO uint32_t BRR;         /*!< USART Baud rate register,                 Address offset: 0x0C  */
  __IO uint32_t GTPR;        /*!< USART Guard time and prescaler register,  Address offset: 0x10  */
  __IO uint32_t RTOR;        /*!< USART Receiver Timeout register,          Address offset: 0x14  */
  __IO uint32_t RQR;         /*!< USART Request register,                   Address offset: 0x18  */
  __IO uint32_t ISR;         /*!< USART Interrupt and status register,      Address offset: 0x1C  */
  __IO uint32_t ICR;         /*!< USART Interrupt flag Clear register,      Address offset: 0x20  */
  __IO uint32_t RDR;         /*!< USART Receive Data register,              Address offset: 0x24  */
  __IO uint32_t TDR;         /*!< USART Transmit Data register,             Address offset: 0x28  */
  __IO uint32_t PRESC;       /*!< USART Prescaler register,                 Address offset: 0x2C  */
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
  __IO uint16_t LPMCSR;          /*!< LPM Control and Status register,        Address offset: 0x54 */
  __IO uint16_t RESERVEDD;       /*!< Reserved */
  __IO uint16_t BCDR;            /*!< Battery Charging detector register,     Address offset: 0x58 */
  __IO uint16_t RESERVEDE;       /*!< Reserved */
} USB_TypeDef;

/**
  * @brief VREFBUF
  */

typedef struct
{
  __IO uint32_t CSR;         /*!< VREFBUF control and status register,         Address offset: 0x00 */
  __IO uint32_t CCR;         /*!< VREFBUF calibration and control register,    Address offset: 0x04 */
} VREFBUF_TypeDef;

/**
  * @brief Window WATCHDOG
  */

typedef struct
{
  __IO uint32_t CR;          /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;         /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;          /*!< WWDG Status register,        Address offset: 0x08 */
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
  * @brief CORDIC
  */

typedef struct
{
  __IO uint32_t CSR;          /*!< CORDIC control and status register,        Address offset: 0x00 */
  __IO uint32_t WDATA;        /*!< CORDIC argument register,                  Address offset: 0x04 */
  __IO uint32_t RDATA;        /*!< CORDIC result register,                    Address offset: 0x08 */
} CORDIC_TypeDef;

/**
  * @brief UCPD
  */

typedef struct
{
  __IO uint32_t CFG1;          /*!< UCPD configuration register 1,             Address offset: 0x00 */
  __IO uint32_t CFG2;          /*!< UCPD configuration register 2,             Address offset: 0x04 */
  __IO uint32_t RESERVED0;     /*!< UCPD reserved register,                    Address offset: 0x08 */
  __IO uint32_t CR;            /*!< UCPD control register,                     Address offset: 0x0C */
  __IO uint32_t IMR;           /*!< UCPD interrupt mask register,              Address offset: 0x10 */
  __IO uint32_t SR;            /*!< UCPD status register,                      Address offset: 0x14 */
  __IO uint32_t ICR;           /*!< UCPD interrupt flag clear register         Address offset: 0x18 */
  __IO uint32_t TX_ORDSET;     /*!< UCPD Tx ordered set type register,         Address offset: 0x1C */
  __IO uint32_t TX_PAYSZ;      /*!< UCPD Tx payload size register,             Address offset: 0x20 */
  __IO uint32_t TXDR;          /*!< UCPD Tx data register,                     Address offset: 0x24 */
  __IO uint32_t RX_ORDSET;     /*!< UCPD Rx ordered set type register,         Address offset: 0x28 */
  __IO uint32_t RX_PAYSZ;      /*!< UCPD Rx payload size register,             Address offset: 0x2C */
  __IO uint32_t RXDR;          /*!< UCPD Rx data register,                     Address offset: 0x30 */
  __IO uint32_t RX_ORDEXT1;    /*!< UCPD Rx ordered set extension 1 register,  Address offset: 0x34 */
  __IO uint32_t RX_ORDEXT2;    /*!< UCPD Rx ordered set extension 2 register,  Address offset: 0x38 */
} UCPD_TypeDef;

/**
  * @brief High resolution Timer (HRTIM)
  */

#define c7amba_hrtim1_v2_0

/* HRTIM master registers definition */
typedef struct
{
  __IO uint32_t MCR;            /*!< HRTIM Master Timer control register,                     Address offset: 0x00 */
  __IO uint32_t MISR;           /*!< HRTIM Master Timer interrupt status register,            Address offset: 0x04 */
  __IO uint32_t MICR;           /*!< HRTIM Master Timer interupt clear register,              Address offset: 0x08 */
  __IO uint32_t MDIER;          /*!< HRTIM Master Timer DMA/interrupt enable register         Address offset: 0x0C */
  __IO uint32_t MCNTR;          /*!< HRTIM Master Timer counter register,                     Address offset: 0x10 */
  __IO uint32_t MPER;           /*!< HRTIM Master Timer period register,                      Address offset: 0x14 */
  __IO uint32_t MREP;           /*!< HRTIM Master Timer repetition register,                  Address offset: 0x18 */
  __IO uint32_t MCMP1R;         /*!< HRTIM Master Timer compare 1 register,                   Address offset: 0x1C */
  uint32_t      RESERVED0;     /*!< Reserved,                                                                0x20 */
  __IO uint32_t MCMP2R;         /*!< HRTIM Master Timer compare 2 register,                   Address offset: 0x24 */
  __IO uint32_t MCMP3R;         /*!< HRTIM Master Timer compare 3 register,                   Address offset: 0x28 */
  __IO uint32_t MCMP4R;         /*!< HRTIM Master Timer compare 4 register,                   Address offset: 0x2C */
  uint32_t      RESERVED1[20];  /*!< Reserved,                                                0x30..0x7C */
}HRTIM_Master_TypeDef;

/* HRTIM Timer A to F registers definition */
typedef struct
{
  __IO uint32_t TIMxCR;     /*!< HRTIM Timerx control register,                              Address offset: 0x00  */
  __IO uint32_t TIMxISR;    /*!< HRTIM Timerx interrupt status register,                     Address offset: 0x04  */
  __IO uint32_t TIMxICR;    /*!< HRTIM Timerx interrupt clear register,                      Address offset: 0x08  */
  __IO uint32_t TIMxDIER;   /*!< HRTIM Timerx DMA/interrupt enable register,                 Address offset: 0x0C  */
  __IO uint32_t CNTxR;      /*!< HRTIM Timerx counter register,                              Address offset: 0x10  */
  __IO uint32_t PERxR;      /*!< HRTIM Timerx period register,                               Address offset: 0x14  */
  __IO uint32_t REPxR;      /*!< HRTIM Timerx repetition register,                           Address offset: 0x18  */
  __IO uint32_t CMP1xR;     /*!< HRTIM Timerx compare 1 register,                            Address offset: 0x1C  */
  __IO uint32_t CMP1CxR;    /*!< HRTIM Timerx compare 1 compound register,                   Address offset: 0x20  */
  __IO uint32_t CMP2xR;     /*!< HRTIM Timerx compare 2 register,                            Address offset: 0x24  */
  __IO uint32_t CMP3xR;     /*!< HRTIM Timerx compare 3 register,                            Address offset: 0x28  */
  __IO uint32_t CMP4xR;     /*!< HRTIM Timerx compare 4 register,                            Address offset: 0x2C  */
  __IO uint32_t CPT1xR;     /*!< HRTIM Timerx capture 1 register,                            Address offset: 0x30  */
  __IO uint32_t CPT2xR;     /*!< HRTIM Timerx capture 2 register,                            Address offset: 0x34 */
  __IO uint32_t DTxR;       /*!< HRTIM Timerx dead time register,                            Address offset: 0x38 */
  __IO uint32_t SETx1R;     /*!< HRTIM Timerx output 1 set register,                         Address offset: 0x3C */
  __IO uint32_t RSTx1R;     /*!< HRTIM Timerx output 1 reset register,                       Address offset: 0x40 */
  __IO uint32_t SETx2R;     /*!< HRTIM Timerx output 2 set register,                         Address offset: 0x44 */
  __IO uint32_t RSTx2R;     /*!< HRTIM Timerx output 2 reset register,                       Address offset: 0x48 */
  __IO uint32_t EEFxR1;     /*!< HRTIM Timerx external event filtering 1 register,           Address offset: 0x4C */
  __IO uint32_t EEFxR2;     /*!< HRTIM Timerx external event filtering 2 register,           Address offset: 0x50 */
  __IO uint32_t RSTxR;      /*!< HRTIM Timerx Reset register,                                Address offset: 0x54 */
  __IO uint32_t CHPxR;      /*!< HRTIM Timerx Chopper register,                              Address offset: 0x58 */
  __IO uint32_t CPT1xCR;    /*!< HRTIM Timerx Capture 1 register,                            Address offset: 0x5C */
  __IO uint32_t CPT2xCR;    /*!< HRTIM Timerx Capture 2 register,                            Address offset: 0x60 */
  __IO uint32_t OUTxR;      /*!< HRTIM Timerx Output register,                               Address offset: 0x64 */
  __IO uint32_t FLTxR;      /*!< HRTIM Timerx Fault register,                                Address offset: 0x68 */
  __IO uint32_t TIMxCR2;    /*!< HRTIM Timerx Control register 2,                            Address offset: 0x6C */
  __IO uint32_t EEFxR3;     /*!< HRTIM Timerx external event filtering 3 register,           Address offset: 0x70 */
  uint32_t   RESERVED0[3];  /*!< Reserved,                                                   0x74..0x7C */
}HRTIM_Timerx_TypeDef;

/* HRTIM common register definition */
typedef struct
{
  __IO uint32_t CR1;        /*!< HRTIM control register1,                                    Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< HRTIM control register2,                                    Address offset: 0x04 */
  __IO uint32_t ISR;        /*!< HRTIM interrupt status register,                            Address offset: 0x08 */
  __IO uint32_t ICR;        /*!< HRTIM interrupt clear register,                             Address offset: 0x0C */
  __IO uint32_t IER;        /*!< HRTIM interrupt enable register,                            Address offset: 0x10 */
  __IO uint32_t OENR;       /*!< HRTIM Output enable register,                               Address offset: 0x14 */
  __IO uint32_t ODISR;      /*!< HRTIM Output disable register,                              Address offset: 0x18 */
  __IO uint32_t ODSR;       /*!< HRTIM Output disable status register,                       Address offset: 0x1C */
  __IO uint32_t BMCR;       /*!< HRTIM Burst mode control register,                          Address offset: 0x20 */
  __IO uint32_t BMTRGR;     /*!< HRTIM Busrt mode trigger register,                          Address offset: 0x24 */
  __IO uint32_t BMCMPR;     /*!< HRTIM Burst mode compare register,                          Address offset: 0x28 */
  __IO uint32_t BMPER;      /*!< HRTIM Burst mode period register,                           Address offset: 0x2C */
  __IO uint32_t EECR1;      /*!< HRTIM Timer external event control register1,               Address offset: 0x30 */
  __IO uint32_t EECR2;      /*!< HRTIM Timer external event control register2,               Address offset: 0x34 */
  __IO uint32_t EECR3;      /*!< HRTIM Timer external event control register3,               Address offset: 0x38 */
  __IO uint32_t ADC1R;      /*!< HRTIM ADC Trigger 1 register,                               Address offset: 0x3C */
  __IO uint32_t ADC2R;      /*!< HRTIM ADC Trigger 2 register,                               Address offset: 0x40 */
  __IO uint32_t ADC3R;      /*!< HRTIM ADC Trigger 3 register,                               Address offset: 0x44 */
  __IO uint32_t ADC4R;      /*!< HRTIM ADC Trigger 4 register,                               Address offset: 0x48 */
  __IO uint32_t DLLCR;      /*!< HRTIM DLL control register,                                 Address offset: 0x4C */
  __IO uint32_t FLTINR1;    /*!< HRTIM Fault input register1,                                Address offset: 0x50 */
  __IO uint32_t FLTINR2;    /*!< HRTIM Fault input register2,                                Address offset: 0x54 */
  __IO uint32_t BDMUPR;     /*!< HRTIM Burst DMA Master Timer update register,               Address offset: 0x58 */
  __IO uint32_t BDTAUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x5C */
  __IO uint32_t BDTBUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x60 */
  __IO uint32_t BDTCUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x64 */
  __IO uint32_t BDTDUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x68 */
  __IO uint32_t BDTEUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x6C */
  __IO uint32_t BDMADR;     /*!< HRTIM Burst DMA Master Data register,                       Address offset: 0x70 */
  __IO uint32_t BDTFUPR;    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x74 */
  __IO uint32_t ADCER;      /*!< HRTIM ADC Extended Trigger register,                        Address offset: 0x78 */
  __IO uint32_t ADCUR;      /*!< HRTIM ADC Trigger Update register,                          Address offset: 0x7C */
  __IO uint32_t ADCPS1;     /*!< HRTIM ADC Post Scaler Register 1,                           Address offset: 0x80 */
  __IO uint32_t ADCPS2;     /*!< HRTIM ADC Post Scaler Register 2,                           Address offset: 0x84 */
  __IO uint32_t FLTINR3;    /*!< HRTIM Fault input register3,                                Address offset: 0x88 */
  __IO uint32_t FLTINR4;    /*!< HRTIM Fault input register4,                                Address offset: 0x8C */
}HRTIM_Common_TypeDef;

/* HRTIM  register definition */
typedef struct {
  HRTIM_Master_TypeDef sMasterRegs;
  HRTIM_Timerx_TypeDef sTimerxRegs[6];
  HRTIM_Common_TypeDef sCommonRegs;
}HRTIM_TypeDef;

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE            (0x08000000UL) /*!< FLASH (up to 512 kB) base address */
#define SRAM1_BASE            (0x20000000UL) /*!< SRAM1(up to 80 KB) base address */
#define SRAM2_BASE            (0x20014000UL) /*!< SRAM2(16 KB) base address */
#define CCMSRAM_BASE          (0x10000000UL) /*!< CCMSRAM(32 KB) base address */
#define PERIPH_BASE           (0x40000000UL) /*!< Peripheral base address */
#define FMC_BASE              (0x60000000UL) /*!< FMC base address */
#define QSPI_BASE             (0x90000000UL) /*!< QUADSPI memories accessible over AHB base address */

#define FMC_R_BASE            (0xA0000000UL) /*!< FMC  control registers base address */
#define QSPI_R_BASE           (0xA0001000UL) /*!< QUADSPI control registers base address */
#define SRAM1_BB_BASE         (0x22000000UL) /*!< SRAM1(80 KB) base address in the bit-band region */
#define SRAM2_BB_BASE         (0x22280000UL) /*!< SRAM2(16 KB) base address in the bit-band region */
#define CCMSRAM_BB_BASE       (0x22300000UL) /*!< CCMSRAM(32 KB) base address in the bit-band region */
#define PERIPH_BB_BASE        (0x42000000UL) /*!< Peripheral base address in the bit-band region */
/* Legacy defines */
#define SRAM_BASE             SRAM1_BASE
#define SRAM_BB_BASE          SRAM1_BB_BASE

#define SRAM1_SIZE_MAX        (0x00014000UL) /*!< maximum SRAM1 size (up to 80 KBytes) */
#define SRAM2_SIZE            (0x00004000UL) /*!< SRAM2 size (16 KBytes) */
#define CCMSRAM_SIZE          (0x00008000UL) /*!< CCMSRAM size (32 KBytes) */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)

#define FMC_BANK1             FMC_BASE
#define FMC_BANK1_1           FMC_BANK1
#define FMC_BANK1_2           (FMC_BANK1 + 0x04000000UL)
#define FMC_BANK1_3           (FMC_BANK1 + 0x08000000UL)
#define FMC_BANK1_4           (FMC_BANK1 + 0x0C000000UL)
#define FMC_BANK3             (FMC_BASE  + 0x20000000UL)

/*!< APB1 peripherals */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400UL)
#define CRS_BASE              (APB1PERIPH_BASE + 0x2000UL)
#define TAMP_BASE             (APB1PERIPH_BASE + 0x2400UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800UL)
#define USB_BASE              (APB1PERIPH_BASE + 0x5C00UL)  /*!< USB_IP Peripheral Registers base address */
#define USB_PMAADDR           (APB1PERIPH_BASE + 0x6000UL)  /*!< USB_IP Packet Memory Area base address */
#define FDCAN1_BASE           (APB1PERIPH_BASE + 0x6400UL)
#define FDCAN_CONFIG_BASE     (APB1PERIPH_BASE + 0x6500UL)  /*!< FDCAN configuration registers base address */
#define FDCAN2_BASE           (APB1PERIPH_BASE + 0x6800UL)
#define FDCAN3_BASE           (APB1PERIPH_BASE + 0x6C00UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000UL)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x7800UL)
#define LPTIM1_BASE           (APB1PERIPH_BASE + 0x7C00UL)
#define LPUART1_BASE          (APB1PERIPH_BASE + 0x8000UL)
#define I2C4_BASE             (APB1PERIPH_BASE + 0x8400UL)
#define UCPD1_BASE            (APB1PERIPH_BASE + 0xA000UL)
#define SRAMCAN_BASE          (APB1PERIPH_BASE + 0xA400UL)

/*!< APB2 peripherals */
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x0000UL)
#define VREFBUF_BASE          (APB2PERIPH_BASE + 0x0030UL)
#define COMP1_BASE            (APB2PERIPH_BASE + 0x0200UL)
#define COMP2_BASE            (APB2PERIPH_BASE + 0x0204UL)
#define COMP3_BASE            (APB2PERIPH_BASE + 0x0208UL)
#define COMP4_BASE            (APB2PERIPH_BASE + 0x020CUL)
#define COMP5_BASE            (APB2PERIPH_BASE + 0x0210UL)
#define COMP6_BASE            (APB2PERIPH_BASE + 0x0214UL)
#define COMP7_BASE            (APB2PERIPH_BASE + 0x0218UL)
#define OPAMP_BASE            (APB2PERIPH_BASE + 0x0300UL)
#define OPAMP1_BASE           (APB2PERIPH_BASE + 0x0300UL)
#define OPAMP2_BASE           (APB2PERIPH_BASE + 0x0304UL)
#define OPAMP3_BASE           (APB2PERIPH_BASE + 0x0308UL)
#define OPAMP4_BASE           (APB2PERIPH_BASE + 0x030CUL)
#define OPAMP5_BASE           (APB2PERIPH_BASE + 0x0310UL)
#define OPAMP6_BASE           (APB2PERIPH_BASE + 0x0314UL)

#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400UL)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x3400UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800UL)
#define SPI4_BASE             (APB2PERIPH_BASE + 0x3C00UL)
#define TIM15_BASE            (APB2PERIPH_BASE + 0x4000UL)
#define TIM16_BASE            (APB2PERIPH_BASE + 0x4400UL)
#define TIM17_BASE            (APB2PERIPH_BASE + 0x4800UL)
#define TIM20_BASE            (APB2PERIPH_BASE + 0x5000UL)
#define SAI1_BASE             (APB2PERIPH_BASE + 0x5400UL)
#define SAI1_Block_A_BASE     (SAI1_BASE + 0x0004UL)
#define SAI1_Block_B_BASE     (SAI1_BASE + 0x0024UL)
#define HRTIM1_BASE           (APB2PERIPH_BASE + 0x6800UL)
#define HRTIM1_TIMA_BASE      (HRTIM1_BASE + 0x0080UL)
#define HRTIM1_TIMB_BASE      (HRTIM1_BASE + 0x0100UL)
#define HRTIM1_TIMC_BASE      (HRTIM1_BASE + 0x0180UL)
#define HRTIM1_TIMD_BASE      (HRTIM1_BASE + 0x0200UL)
#define HRTIM1_TIME_BASE      (HRTIM1_BASE + 0x0280UL)
#define HRTIM1_TIMF_BASE      (HRTIM1_BASE + 0x0300UL)
#define HRTIM1_COMMON_BASE    (HRTIM1_BASE + 0x0380UL)

/*!< AHB1 peripherals */
#define DMA1_BASE             (AHB1PERIPH_BASE)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x0400UL)
#define DMAMUX1_BASE          (AHB1PERIPH_BASE + 0x0800UL)
#define CORDIC_BASE           (AHB1PERIPH_BASE + 0x0C00UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x1000UL)
#define FMAC_BASE             (AHB1PERIPH_BASE + 0x1400UL)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x2000UL)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)

#define DMA1_Channel1_BASE    (DMA1_BASE + 0x0008UL)
#define DMA1_Channel2_BASE    (DMA1_BASE + 0x001CUL)
#define DMA1_Channel3_BASE    (DMA1_BASE + 0x0030UL)
#define DMA1_Channel4_BASE    (DMA1_BASE + 0x0044UL)
#define DMA1_Channel5_BASE    (DMA1_BASE + 0x0058UL)
#define DMA1_Channel6_BASE    (DMA1_BASE + 0x006CUL)
#define DMA1_Channel7_BASE    (DMA1_BASE + 0x0080UL)
#define DMA1_Channel8_BASE    (DMA1_BASE + 0x0094UL)

#define DMA2_Channel1_BASE    (DMA2_BASE + 0x0008UL)
#define DMA2_Channel2_BASE    (DMA2_BASE + 0x001CUL)
#define DMA2_Channel3_BASE    (DMA2_BASE + 0x0030UL)
#define DMA2_Channel4_BASE    (DMA2_BASE + 0x0044UL)
#define DMA2_Channel5_BASE    (DMA2_BASE + 0x0058UL)
#define DMA2_Channel6_BASE    (DMA2_BASE + 0x006CUL)
#define DMA2_Channel7_BASE    (DMA2_BASE + 0x0080UL)
#define DMA2_Channel8_BASE    (DMA2_BASE + 0x0094UL)

#define DMAMUX1_Channel0_BASE    (DMAMUX1_BASE)
#define DMAMUX1_Channel1_BASE    (DMAMUX1_BASE + 0x0004UL)
#define DMAMUX1_Channel2_BASE    (DMAMUX1_BASE + 0x0008UL)
#define DMAMUX1_Channel3_BASE    (DMAMUX1_BASE + 0x000CUL)
#define DMAMUX1_Channel4_BASE    (DMAMUX1_BASE + 0x0010UL)
#define DMAMUX1_Channel5_BASE    (DMAMUX1_BASE + 0x0014UL)
#define DMAMUX1_Channel6_BASE    (DMAMUX1_BASE + 0x0018UL)
#define DMAMUX1_Channel7_BASE    (DMAMUX1_BASE + 0x001CUL)
#define DMAMUX1_Channel8_BASE    (DMAMUX1_BASE + 0x0020UL)
#define DMAMUX1_Channel9_BASE    (DMAMUX1_BASE + 0x0024UL)
#define DMAMUX1_Channel10_BASE   (DMAMUX1_BASE + 0x0028UL)
#define DMAMUX1_Channel11_BASE   (DMAMUX1_BASE + 0x002CUL)
#define DMAMUX1_Channel12_BASE   (DMAMUX1_BASE + 0x0030UL)
#define DMAMUX1_Channel13_BASE   (DMAMUX1_BASE + 0x0034UL)
#define DMAMUX1_Channel14_BASE   (DMAMUX1_BASE + 0x0038UL)
#define DMAMUX1_Channel15_BASE   (DMAMUX1_BASE + 0x003CUL)
#define DMAMUX1_RequestGenerator0_BASE  (DMAMUX1_BASE + 0x0100UL)
#define DMAMUX1_RequestGenerator1_BASE  (DMAMUX1_BASE + 0x0104UL)
#define DMAMUX1_RequestGenerator2_BASE  (DMAMUX1_BASE + 0x0108UL)
#define DMAMUX1_RequestGenerator3_BASE  (DMAMUX1_BASE + 0x010CUL)

#define DMAMUX1_ChannelStatus_BASE      (DMAMUX1_BASE + 0x0080UL)
#define DMAMUX1_RequestGenStatus_BASE   (DMAMUX1_BASE + 0x0140UL)

/*!< AHB2 peripherals */
#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB2PERIPH_BASE + 0x1800UL)

#define ADC1_BASE             (AHB2PERIPH_BASE + 0x08000000UL)
#define ADC2_BASE             (AHB2PERIPH_BASE + 0x08000100UL)
#define ADC12_COMMON_BASE     (AHB2PERIPH_BASE + 0x08000300UL)
#define ADC3_BASE             (AHB2PERIPH_BASE + 0x08000400UL)
#define ADC4_BASE             (AHB2PERIPH_BASE + 0x08000500UL)
#define ADC5_BASE             (AHB2PERIPH_BASE + 0x08000600UL)
#define ADC345_COMMON_BASE    (AHB2PERIPH_BASE + 0x08000700UL)

#define DAC_BASE              (AHB2PERIPH_BASE + 0x08000800UL)
#define DAC1_BASE             (AHB2PERIPH_BASE + 0x08000800UL)
#define DAC2_BASE             (AHB2PERIPH_BASE + 0x08000C00UL)
#define DAC3_BASE             (AHB2PERIPH_BASE + 0x08001000UL)
#define DAC4_BASE             (AHB2PERIPH_BASE + 0x08001400UL)

/*!< FMC Banks registers base  address */
#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000UL)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104UL)
#define FMC_Bank3_R_BASE      (FMC_R_BASE + 0x0080UL)
#define RNG_BASE              (AHB2PERIPH_BASE + 0x08060800UL)
/* Debug MCU registers base address */
#define DBGMCU_BASE           (0xE0042000UL)

#define PACKAGE_BASE          (0x1FFF7500UL)        /*!< Package data register base address     */
#define UID_BASE              (0x1FFF7590UL)        /*!< Unique device ID register base address */
#define FLASHSIZE_BASE        (0x1FFF75E0UL)        /*!< Flash size data register base address  */
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
#define CRS                 ((volatile uint32_t *) CRS_BASE)
#define TAMP                ((volatile uint32_t *) TAMP_BASE)
#define RTC                 ((volatile uint32_t *) RTC_BASE)
#define WWDG                ((volatile uint32_t *) WWDG_BASE)
#define IWDG                ((volatile uint32_t *) IWDG_BASE)
#define SPI2                ((volatile uint32_t *) SPI2_BASE)
#define SPI3                ((volatile uint32_t *) SPI3_BASE)
#define USART2              ((volatile uint32_t *) USART2_BASE)
#define USART3              ((volatile uint32_t *) USART3_BASE)
#define UART4               ((volatile uint32_t *) UART4_BASE)
#define UART5               ((volatile uint32_t *) UART5_BASE)
#define I2C1                ((volatile uint32_t *) I2C1_BASE)
#define I2C2                ((volatile uint32_t *) I2C2_BASE)
#define USB                 ((volatile uint32_t *) USB_BASE)
#define FDCAN1              ((volatile uint32_t *) FDCAN1_BASE)
#define FDCAN_CONFIG        ((volatile uint32_t *) FDCAN_CONFIG_BASE)
#define FDCAN2              ((volatile uint32_t *) FDCAN2_BASE)
#define FDCAN3              ((volatile uint32_t *) FDCAN3_BASE)
#define PWR                 ((volatile uint32_t *) PWR_BASE)
#define I2C3                ((volatile uint32_t *) I2C3_BASE)
#define LPTIM1              ((volatile uint32_t *) LPTIM1_BASE)
#define LPUART1             ((volatile uint32_t *) LPUART1_BASE)
#define I2C4                ((volatile uint32_t *) I2C4_BASE)
#define UCPD1				((volatile uint32_t *) UCPD1_BASE)

#define SYSCFG              ((volatile uint32_t *) SYSCFG_BASE)
#define VREFBUF             ((volatile uint32_t *) VREFBUF_BASE)
#define COMP1               ((volatile uint32_t *) COMP1_BASE)
#define COMP2               ((volatile uint32_t *) COMP2_BASE)
#define COMP3               ((volatile uint32_t *) COMP3_BASE)
#define COMP4               ((volatile uint32_t *) COMP4_BASE)
#define COMP5               ((volatile uint32_t *) COMP5_BASE)
#define COMP6               ((volatile uint32_t *) COMP6_BASE)
#define COMP7               ((volatile uint32_t *) COMP7_BASE)

#define OPAMP               ((volatile uint32_t *) OPAMP_BASE)
#define OPAMP1              ((volatile uint32_t *) OPAMP1_BASE)
#define OPAMP2              ((volatile uint32_t *) OPAMP2_BASE)
#define OPAMP3              ((volatile uint32_t *) OPAMP3_BASE)
#define OPAMP4              ((volatile uint32_t *) OPAMP4_BASE)
#define OPAMP5              ((volatile uint32_t *) OPAMP5_BASE)
#define OPAMP6              ((volatile uint32_t *) OPAMP6_BASE)

#define EXTI                ((volatile uint32_t *) EXTI_BASE)
#define TIM1                ((volatile uint32_t *) TIM1_BASE)
#define SPI1                ((volatile uint32_t *) SPI1_BASE)
#define TIM8                ((volatile uint32_t *) TIM8_BASE)
#define USART1              ((volatile uint32_t *) USART1_BASE)
#define SPI4                ((volatile uint32_t *) SPI4_BASE)
#define TIM15               ((volatile uint32_t *) TIM15_BASE)
#define TIM16               ((volatile uint32_t *) TIM16_BASE)
#define TIM17               ((volatile uint32_t *) TIM17_BASE)
#define TIM20               ((volatile uint32_t *) TIM20_BASE)
#define SAI1                ((volatile uint32_t *) SAI1_BASE)
#define SAI1_Block_A        ((volatile uint32_t *)SAI1_Block_A_BASE)
#define SAI1_Block_B        ((volatile uint32_t *)SAI1_Block_B_BASE)
#define HRTIM1              ((volatile uint32_t *) HRTIM1_BASE)
#define HRTIM1_TIMA         ((volatile uint32_t *) HRTIM1_TIMA_BASE)
#define HRTIM1_TIMB         ((volatile uint32_t *) HRTIM1_TIMB_BASE)
#define HRTIM1_TIMC         ((volatile uint32_t *) HRTIM1_TIMC_BASE)
#define HRTIM1_TIMD         ((volatile uint32_t *) HRTIM1_TIMD_BASE)
#define HRTIM1_TIME         ((volatile uint32_t *) HRTIM1_TIME_BASE)
#define HRTIM1_TIMF         ((volatile uint32_t *) HRTIM1_TIMF_BASE)
#define HRTIM1_COMMON       ((volatile uint32_t *) HRTIM1_COMMON_BASE)
#define DMA1                ((volatile uint32_t *) DMA1_BASE)
#define DMA2                ((volatile uint32_t *) DMA2_BASE)
#define DMAMUX1             ((volatile uint32_t *) DMAMUX1_BASE)
#define CORDIC              ((volatile uint32_t *) CORDIC_BASE)
#define RCC                 ((volatile uint32_t *) RCC_BASE)
#define FMAC                ((volatile uint32_t *) FMAC_BASE)
#define FLASH               ((volatile uint32_t *) FLASH_R_BASE)
#define CRC                 ((volatile uint32_t *) CRC_BASE)

#define GPIOA               ((volatile uint32_t *) GPIOA_BASE)
#define GPIOB               ((volatile uint32_t *) GPIOB_BASE)
#define GPIOC               ((volatile uint32_t *) GPIOC_BASE)
#define GPIOD               ((volatile uint32_t *) GPIOD_BASE)
#define GPIOE               ((volatile uint32_t *) GPIOE_BASE)
#define GPIOF               ((volatile uint32_t *) GPIOF_BASE)
#define GPIOG               ((volatile uint32_t *) GPIOG_BASE)
#define ADC1                ((volatile uint32_t *) ADC1_BASE)
#define ADC2                ((volatile uint32_t *) ADC2_BASE)
#define ADC12_COMMON        ((volatile uint32_t *) ADC12_COMMON_BASE)
#define ADC3                ((volatile uint32_t *) ADC3_BASE)
#define ADC4                ((volatile uint32_t *) ADC4_BASE)
#define ADC5                ((volatile uint32_t *) ADC5_BASE)
#define ADC345_COMMON       ((volatile uint32_t *) ADC345_COMMON_BASE)
#define DAC                 ((volatile uint32_t *) DAC_BASE)
#define DAC1                ((volatile uint32_t *) DAC1_BASE)
#define DAC2                ((volatile uint32_t *) DAC2_BASE)
#define DAC3                ((volatile uint32_t *) DAC3_BASE)
#define DAC4                ((volatile uint32_t *) DAC4_BASE)
#define RNG                 ((volatile uint32_t *) RNG_BASE)

#define DMA1_Channel1       ((volatile uint32_t *) DMA1_Channel1_BASE)
#define DMA1_Channel2       ((volatile uint32_t *) DMA1_Channel2_BASE)
#define DMA1_Channel3       ((volatile uint32_t *) DMA1_Channel3_BASE)
#define DMA1_Channel4       ((volatile uint32_t *) DMA1_Channel4_BASE)
#define DMA1_Channel5       ((volatile uint32_t *) DMA1_Channel5_BASE)
#define DMA1_Channel6       ((volatile uint32_t *) DMA1_Channel6_BASE)
#define DMA1_Channel7       ((volatile uint32_t *) DMA1_Channel7_BASE)
#define DMA1_Channel8       ((volatile uint32_t *) DMA1_Channel8_BASE)

#define DMA2_Channel1       ((volatile uint32_t *) DMA2_Channel1_BASE)
#define DMA2_Channel2       ((volatile uint32_t *) DMA2_Channel2_BASE)
#define DMA2_Channel3       ((volatile uint32_t *) DMA2_Channel3_BASE)
#define DMA2_Channel4       ((volatile uint32_t *) DMA2_Channel4_BASE)
#define DMA2_Channel5       ((volatile uint32_t *) DMA2_Channel5_BASE)
#define DMA2_Channel6       ((volatile uint32_t *) DMA2_Channel6_BASE)
#define DMA2_Channel7       ((volatile uint32_t *) DMA2_Channel7_BASE)
#define DMA2_Channel8       ((volatile uint32_t *) DMA2_Channel8_BASE)

#define DMAMUX1_Channel0    ((volatile uint32_t *) DMAMUX1_Channel0_BASE)
#define DMAMUX1_Channel1    ((volatile uint32_t *) DMAMUX1_Channel1_BASE)
#define DMAMUX1_Channel2    ((volatile uint32_t *) DMAMUX1_Channel2_BASE)
#define DMAMUX1_Channel3    ((volatile uint32_t *) DMAMUX1_Channel3_BASE)
#define DMAMUX1_Channel4    ((volatile uint32_t *) DMAMUX1_Channel4_BASE)
#define DMAMUX1_Channel5    ((volatile uint32_t *) DMAMUX1_Channel5_BASE)
#define DMAMUX1_Channel6    ((volatile uint32_t *) DMAMUX1_Channel6_BASE)
#define DMAMUX1_Channel7    ((volatile uint32_t *) DMAMUX1_Channel7_BASE)
#define DMAMUX1_Channel8    ((volatile uint32_t *) DMAMUX1_Channel8_BASE)
#define DMAMUX1_Channel9    ((volatile uint32_t *) DMAMUX1_Channel9_BASE)
#define DMAMUX1_Channel10   ((volatile uint32_t *) DMAMUX1_Channel10_BASE)
#define DMAMUX1_Channel11   ((volatile uint32_t *) DMAMUX1_Channel11_BASE)
#define DMAMUX1_Channel12   ((volatile uint32_t *) DMAMUX1_Channel12_BASE)
#define DMAMUX1_Channel13   ((volatile uint32_t *) DMAMUX1_Channel13_BASE)
#define DMAMUX1_Channel14   ((volatile uint32_t *) DMAMUX1_Channel14_BASE)
#define DMAMUX1_Channel15   ((volatile uint32_t *) DMAMUX1_Channel15_BASE)

#define DMAMUX1_RequestGenerator0  ((volatile uint32_t *) DMAMUX1_RequestGenerator0_BASE)
#define DMAMUX1_RequestGenerator1  ((volatile uint32_t *) DMAMUX1_RequestGenerator1_BASE)
#define DMAMUX1_RequestGenerator2  ((volatile uint32_t *) DMAMUX1_RequestGenerator2_BASE)
#define DMAMUX1_RequestGenerator3  ((volatile uint32_t *) DMAMUX1_RequestGenerator3_BASE)

#define DMAMUX1_ChannelStatus      ((volatile uint32_t *) DMAMUX1_ChannelStatus_BASE)
#define DMAMUX1_RequestGenStatus   ((volatile uint32_t *) DMAMUX1_RequestGenStatus_BASE)

#define FMC_Bank1_R         ((volatile uint32_t *) FMC_Bank1_R_BASE)
#define FMC_Bank1E_R        ((volatile uint32_t *) FMC_Bank1E_R_BASE)
#define FMC_Bank3_R         ((volatile uint32_t *) FMC_Bank3_R_BASE)

#define QUADSPI             ((volatile uint32_t *) QSPI_R_BASE)

#define DBGMCU              ((volatile uint32_t *) DBGMCU_BASE)

/**
  * @}
  */

/******************************************************************************/
/*  For a painless codes migration between the STM32G4xx device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */
/*  product lines within the same STM32G4 Family                              */
/******************************************************************************/

/* Aliases for __IRQn */

/* Aliases for __IRQHandler */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32G474xx_H */

/**
  * @}
  */

  /**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
