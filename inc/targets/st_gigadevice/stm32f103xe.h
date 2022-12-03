/**
  ******************************************************************************
  * @file    stm32f103xe.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral register's definitions, bits 
  *          definitions and memory mapping for STM32F1xx devices.            
  *            
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral�s registers hardware
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

/** @addtogroup stm32f103xe
  * @{
  */
    
#ifndef __STM32F103xE_H
#define __STM32F103xE_H

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
  TIM8_BRK_IRQn               = 43,     /*!< TIM8 Break Interrupt                                 */
  TIM8_UP_IRQn                = 44,     /*!< TIM8 Update Interrupt                                */
  TIM8_TRG_COM_IRQn           = 45,     /*!< TIM8 Trigger and Commutation Interrupt               */
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
#include <stdint.h>

/** @addtogroup Peripheral_memory_map
  * @{
  */


#define FLASH_BASE            0x08000000UL /*!< FLASH base address in the alias region */
#define FLASH_BANK1_END       0x0807FFFFUL /*!< FLASH END address of bank1 */
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
#define RTC                 ((volatile uint32_t *)RTC_BASE)
#define WWDG                ((volatile uint32_t *)WWDG_BASE)
#define IWDG                ((volatile uint32_t *)IWDG_BASE)
#define SPI2                ((volatile uint32_t *)SPI2_BASE)
#define SPI3                ((volatile uint32_t *)SPI3_BASE)
#define USART2              ((volatile uint32_t *)USART2_BASE)
#define USART3              ((volatile uint32_t *)USART3_BASE)
#define UART4               ((volatile uint32_t *)UART4_BASE)
#define UART5               ((volatile uint32_t *)UART5_BASE)
#define I2C1                ((volatile uint32_t *)I2C1_BASE)
#define I2C2                ((volatile uint32_t *)I2C2_BASE)
#define USB                 ((volatile uint32_t *)USB_BASE)
#define CAN1                ((volatile uint32_t *)CAN1_BASE)
#define BKP                 ((volatile uint32_t *)BKP_BASE)
#define PWR                 ((volatile uint32_t *)PWR_BASE)
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
#define ADC12_COMMON        ((volatile uint32_t *)ADC1_BASE)
#define TIM1                ((volatile uint32_t *)TIM1_BASE)
#define SPI1                ((volatile uint32_t *)SPI1_BASE)
#define TIM8                ((volatile uint32_t *)TIM8_BASE)
#define USART1              ((volatile uint32_t *)USART1_BASE)
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
#define OB                  ((volatile uint32_t *)OB_BASE)
#define FSMC_Bank1          ((volatile uint32_t *)FSMC_BANK1_R_BASE)
#define FSMC_Bank1E         ((volatile uint32_t *)FSMC_BANK1E_R_BASE)
#define FSMC_Bank2_3        ((volatile uint32_t *)FSMC_BANK2_3_R_BASE)
#define FSMC_Bank4          ((volatile uint32_t *)FSMC_BANK4_R_BASE)
#define DBGMCU              ((volatile uint32_t *)DBGMCU_BASE)


/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */
  
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
#define TIM1_BRK_TIM9_IRQn      TIM1_BRK_IRQn
#define TIM9_IRQn               TIM1_BRK_IRQn
#define TIM1_BRK_TIM15_IRQn     TIM1_BRK_IRQn
#define TIM11_IRQn              TIM1_TRG_COM_IRQn
#define TIM1_TRG_COM_TIM11_IRQn TIM1_TRG_COM_IRQn
#define TIM1_TRG_COM_TIM17_IRQn TIM1_TRG_COM_IRQn
#define TIM1_UP_TIM10_IRQn      TIM1_UP_IRQn
#define TIM1_UP_TIM16_IRQn      TIM1_UP_IRQn
#define TIM10_IRQn              TIM1_UP_IRQn
#define TIM6_DAC_IRQn           TIM6_IRQn
#define TIM8_BRK_TIM12_IRQn     TIM8_BRK_IRQn
#define TIM12_IRQn              TIM8_BRK_IRQn
#define TIM14_IRQn              TIM8_TRG_COM_IRQn
#define TIM8_TRG_COM_TIM14_IRQn TIM8_TRG_COM_IRQn
#define TIM8_UP_TIM13_IRQn      TIM8_UP_IRQn
#define TIM13_IRQn              TIM8_UP_IRQn
#define CEC_IRQn                USBWakeUp_IRQn
#define OTG_FS_WKUP_IRQn        USBWakeUp_IRQn
#define USB_HP_IRQn             USB_HP_CAN1_TX_IRQn
#define CAN1_TX_IRQn            USB_HP_CAN1_TX_IRQn
#define USB_LP_IRQn             USB_LP_CAN1_RX0_IRQn
#define CAN1_RX0_IRQn           USB_LP_CAN1_RX0_IRQn


/* Aliases for __IRQHandler */
#define ADC1_IRQHandler               ADC1_2_IRQHandler
#define DMA2_Channel4_IRQHandler      DMA2_Channel4_5_IRQHandler
#define TIM1_BRK_TIM9_IRQHandler      TIM1_BRK_IRQHandler
#define TIM9_IRQHandler               TIM1_BRK_IRQHandler
#define TIM1_BRK_TIM15_IRQHandler     TIM1_BRK_IRQHandler
#define TIM11_IRQHandler              TIM1_TRG_COM_IRQHandler
#define TIM1_TRG_COM_TIM11_IRQHandler TIM1_TRG_COM_IRQHandler
#define TIM1_TRG_COM_TIM17_IRQHandler TIM1_TRG_COM_IRQHandler
#define TIM1_UP_TIM10_IRQHandler      TIM1_UP_IRQHandler
#define TIM1_UP_TIM16_IRQHandler      TIM1_UP_IRQHandler
#define TIM10_IRQHandler              TIM1_UP_IRQHandler
#define TIM6_DAC_IRQHandler           TIM6_IRQHandler
#define TIM8_BRK_TIM12_IRQHandler     TIM8_BRK_IRQHandler
#define TIM12_IRQHandler              TIM8_BRK_IRQHandler
#define TIM14_IRQHandler              TIM8_TRG_COM_IRQHandler
#define TIM8_TRG_COM_TIM14_IRQHandler TIM8_TRG_COM_IRQHandler
#define TIM8_UP_TIM13_IRQHandler      TIM8_UP_IRQHandler
#define TIM13_IRQHandler              TIM8_UP_IRQHandler
#define CEC_IRQHandler                USBWakeUp_IRQHandler
#define OTG_FS_WKUP_IRQHandler        USBWakeUp_IRQHandler
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
  
#endif /* __STM32F103xE_H */
  
  
  
  /************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
