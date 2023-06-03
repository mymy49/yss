/**
  ******************************************************************************
  * @file    gd32f10x.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File..
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_H
#define __GD32F10X_H

#ifdef __cplusplus
 extern "C" {
#endif 
  
#if !defined (GD32F10X_MD)&&!defined (GD32F10X_HD)&&!defined (GD32F10X_XD)&&!defined (GD32F10X_CL)
 #error "Please select first the target gd32f10x device used in your application (in gd32f10x.h file)"
#endif /* GD32F10X */

/**
 * @brief Configuration of the Cortex-M3 Processor and Core Peripherals 
 */
#define __MPU_PRESENT             0        /*!< GD32 devices does not provide an MPU */
#define __NVIC_PRIO_BITS          4        /*!< GD32F10X uses 4 Bits for the Priority Levels             */
#define __Vendor_SysTickConfig    0        /*!< Set to 1 if different SysTick Config is used             */

/*!< Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
    NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
    MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
    BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
    UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
    SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
    DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
    PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
    SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */

/******  GD32 specific Interrupt Numbers *********************************************************/
    WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
    LVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
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

#ifdef GD32F10X_MD
    ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
    USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
    USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
    CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
    CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
    TIM1_BRK_IRQn               = 24,     /*!< TIMER1 Break Interrupt                               */
    TIM1_UP_IRQn                = 25,     /*!< TIMER1 Update Interrupt                              */
    TIM1_TRG_COM_IRQn           = 26,     /*!< TIMER1 Trigger and Commutation Interrupt             */
    TIM1_CC_IRQn                = 27,     /*!< TIMER1 Capture Compare Interrupt                     */
    TIM2_IRQn                   = 28,     /*!< TIMER2 global Interrupt                              */
    TIM3_IRQn                   = 29,     /*!< TIMER3 global Interrupt                              */
    TIM4_IRQn                   = 30,     /*!< TIMER4 global Interrupt                              */
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
    RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
    USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
    EXMC_IRQn                   = 48     /*!< EXMC global Interrupt                                */  
#endif /* GD32F10X_MD */  

#ifdef GD32F10X_HD
    ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
    USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
    USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
    CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
    CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
    TIM1_BRK_IRQn               = 24,     /*!< TIMER1 Break Interrupt                               */
    TIM1_UP_IRQn                = 25,     /*!< TIMER1 Update Interrupt                              */
    TIM1_TRG_COM_IRQn           = 26,     /*!< TIMER1 Trigger and Commutation Interrupt             */
    TIM1_CC_IRQn                = 27,     /*!< TIMER1 Capture Compare Interrupt                     */
    TIM2_IRQn                   = 28,     /*!< TIMER2 global Interrupt                              */
    TIM3_IRQn                   = 29,     /*!< TIMER3 global Interrupt                              */
    TIM4_IRQn                   = 30,     /*!< TIMER4 global Interrupt                              */
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
    RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
    USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
    TIM8_BRK_IRQn               = 43,     /*!< TIMER8 Break Interrupt                               */
    TIM8_UP_IRQn                = 44,     /*!< TIMER8 Update Interrupt                              */
    TIM8_TRG_COM_IRQn           = 45,     /*!< TIMER8 Trigger and Commutation Interrupt             */
    TIM8_CC_IRQn                = 46,     /*!< TIMER8 Capture Compare Interrupt                     */
    ADC3_IRQn                   = 47,     /*!< ADC3 global Interrupt                                */
    EXMC_IRQn                   = 48,     /*!< EXMC global Interrupt                                */
    SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                */
    TIM5_IRQn                   = 50,     /*!< TIMER5 global Interrupt                              */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
    UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
    UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */
    TIM6_IRQn                   = 54,     /*!< TIMER6 global Interrupt                              */
    TIM7_IRQn                   = 55,     /*!< TIMER7 global Interrupt                              */
    DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
    DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
    DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
    DMA2_Channel4_5_IRQn        = 59      /*!< DMA2 Channel 4 and Channel 5 global Interrupt        */
#endif /* GD32F10X_HD */  

#ifdef GD32F10X_XD
    ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
    USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
    USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
    CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
    CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
    TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIMER1 Break Interrupt and TIMER9 global Interrupt   */
    TIM1_UP_TIM10_IRQn          = 25,     /*!< TIMER1 Update Interrupt and TIMER10 global Interrupt */
    TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIMER1 Trigger and Commutation Interrupt and TIMER11 global interrupt */
    TIM1_CC_IRQn                = 27,     /*!< TIMER1 Capture Compare Interrupt                     */
    TIM2_IRQn                   = 28,     /*!< TIMER2 global Interrupt                              */
    TIM3_IRQn                   = 29,     /*!< TIMER3 global Interrupt                              */
    TIM4_IRQn                   = 30,     /*!< TIMER4 global Interrupt                              */
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
    RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
    USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
    TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIMER8 Break Interrupt and TIMER12 global Interrupt  */
    TIM8_UP_TIM13_IRQn          = 44,     /*!< TIMER8 Update Interrupt and TIMER13 global Interrupt */
    TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIMER8 Trigger and Commutation Interrupt and TIMER14 global interrupt */
    TIM8_CC_IRQn                = 46,     /*!< TIMER8 Capture Compare Interrupt                     */
    ADC3_IRQn                   = 47,     /*!< ADC3 global Interrupt                                */
    EXMC_IRQn                   = 48,     /*!< EXMC global Interrupt                                */
    SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                */
    TIM5_IRQn                   = 50,     /*!< TIMER5 global Interrupt                              */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
    UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
    UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */
    TIM6_IRQn                   = 54,     /*!< TIMER6 global Interrupt                              */
    TIM7_IRQn                   = 55,     /*!< TIMER7 global Interrupt                              */
    DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
    DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
    DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
    DMA2_Channel4_5_IRQn        = 59      /*!< DMA2 Channel 4 and Channel 5 global Interrupt        */
#endif /* GD32F10X_XD */  

#ifdef GD32F10X_CL
    ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
    CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupts                                   */
    CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupts                                  */
    CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
    CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
    TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIMER1 Break Interrupt and TIMER9 global Interrupt   */
    TIM1_UP_TIM10_IRQn          = 25,     /*!< TIMER1 Update Interrupt and TIMER10 global Interrupt */
    TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIMER1 Trigger and Commutation Interrupt and TIMER11 global interrupt */
    TIM1_CC_IRQn                = 27,     /*!< TIMER1 Capture Compare Interrupt                     */
    TIM2_IRQn                   = 28,     /*!< TIMER2 global Interrupt                              */
    TIM3_IRQn                   = 29,     /*!< TIMER3 global Interrupt                              */
    TIM4_IRQn                   = 30,     /*!< TIMER4 global Interrupt                              */
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
    RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
    OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS WakeUp from suspend through EXTI Line Interrupt */
    TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIMER8 Break Interrupt and TIMER12 global Interrupt  */
    TIM8_UP_TIM13_IRQn          = 44,     /*!< TIMER8 Update Interrupt and TIMER13 global Interrupt */
    TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIMER8 Trigger and Commutation Interrupt and TIMER14 global interrupt */
    TIM8_CC_IRQn                = 46,     /*!< TIMER8 Capture Compare Interrupt                     */
    ADC3_IRQn                   = 47,     /*!< ADC3 global Interrupt                                */
    EXMC_IRQn                   = 48,     /*!< EXMC global Interrupt                                */
    TIM5_IRQn                   = 50,     /*!< TIMER5 global Interrupt                              */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
    UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
    UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */
    TIM6_IRQn                   = 54,     /*!< TIMER6 global Interrupt                              */
    TIM7_IRQn                   = 55,     /*!< TIMER7 global Interrupt                              */
    DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
    DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
    DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
    DMA2_Channel4_IRQn          = 59,     /*!< DMA2 Channel 4 global Interrupt                      */
    DMA2_Channel5_IRQn          = 60,     /*!< DMA2 Channel 5 global Interrupt                      */
    ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                            */
    ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt          */
    CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                    */
    CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                   */
    CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                   */
    CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                   */
    OTG_FS_IRQn                 = 67      /*!< USB OTG FS global Interrupt                          */
#endif /* GD32F10X_CL */     
} IRQn_Type;

/**
  * @}
  */

/* Includes ------------------------------------------------------------------*/
#include "../../cmsis/core_cm3.h"
#include <stdint.h>

/** @addtogroup Exported_types
  * @{
  */  
typedef enum {ERROR = 0, SUCCESS = !ERROR, RESET = 0, SET = !RESET, DISABLE = 0, ENABLE = !DISABLE} TypeState;
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< Read Only */
typedef const int16_t sc16;  /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< Read Only */
typedef __I int16_t vsc16;  /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< Read Only */
typedef const uint16_t uc16;  /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< Read Only */
typedef __I uint16_t vuc16;  /*!< Read Only */
typedef __I uint8_t vuc8;   /*!< Read Only */

/** @addtogroup Peripheral_memory_map
  * @{
  */


#define FLASH_BASE            ((uint32_t)0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE             ((uint32_t)0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */

#define SRAM_BB_BASE          ((uint32_t)0x22000000) /*!< SRAM base address in the bit-band region */
#define PERIPH_BB_BASE        ((uint32_t)0x42000000) /*!< Peripheral base address in the bit-band region */

#define EXMC_R_BASE           ((uint32_t)0xA0000000) /*!< EXMC registers base address */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define TIMER2_BASE           (APB1PERIPH_BASE + 0x0000)
#define TIMER3_BASE           (APB1PERIPH_BASE + 0x0400)
#define TIMER4_BASE           (APB1PERIPH_BASE + 0x0800)
#define TIMER5_BASE           (APB1PERIPH_BASE + 0x0C00)
#define TIMER6_BASE           (APB1PERIPH_BASE + 0x1000)
#define TIMER7_BASE           (APB1PERIPH_BASE + 0x1400)
#define TIMER12_BASE          (APB1PERIPH_BASE + 0x1800)
#define TIMER13_BASE          (APB1PERIPH_BASE + 0x1C00)
#define TIMER14_BASE          (APB1PERIPH_BASE + 0x2000)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800)
#define BKP_BASE              (APB1PERIPH_BASE + 0x6C00)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400)
#define AFIO_BASE             (APB2PERIPH_BASE + 0x0000)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2400)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2800)
#define TIMER1_BASE           (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define TIMER8_BASE           (APB2PERIPH_BASE + 0x3400)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x3C00)
#define TIMER15_BASE          (APB2PERIPH_BASE + 0x4000)
#define TIMER16_BASE          (APB2PERIPH_BASE + 0x4400)
#define TIMER17_BASE          (APB2PERIPH_BASE + 0x4800)
#define TIMER9_BASE           (APB2PERIPH_BASE + 0x4C00)
#define TIMER10_BASE          (APB2PERIPH_BASE + 0x5000)
#define TIMER11_BASE          (APB2PERIPH_BASE + 0x5400)

#define SDIO_BASE             (PERIPH_BASE + 0x18000)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x0000)
#define DMA1_CHANNEL1_BASE    (AHBPERIPH_BASE + 0x0008)
#define DMA1_CHANNEL2_BASE    (AHBPERIPH_BASE + 0x001C)
#define DMA1_CHANNEL3_BASE    (AHBPERIPH_BASE + 0x0030)
#define DMA1_CHANNEL4_BASE    (AHBPERIPH_BASE + 0x0044)
#define DMA1_CHANNEL5_BASE    (AHBPERIPH_BASE + 0x0058)
#define DMA1_CHANNEL6_BASE    (AHBPERIPH_BASE + 0x006C)
#define DMA1_CHANNEL7_BASE    (AHBPERIPH_BASE + 0x0080)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x0400)
#define DMA2_CHANNEL1_BASE    (AHBPERIPH_BASE + 0x0408)
#define DMA2_CHANNEL2_BASE    (AHBPERIPH_BASE + 0x041C)
#define DMA2_CHANNEL3_BASE    (AHBPERIPH_BASE + 0x0430)
#define DMA2_CHANNEL4_BASE    (AHBPERIPH_BASE + 0x0444)
#define DMA2_CHANNEL5_BASE    (AHBPERIPH_BASE + 0x0458)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define CRC_BASE              (AHBPERIPH_BASE + 0x3000)

#define FMC_R_BASE            (AHBPERIPH_BASE + 0x2000) /*!< FMC registers base address */
#define OB_BASE               ((uint32_t)0x1FFFF800)    /*!< FMC Option Bytes base address */

#define ETH_BASE              (AHBPERIPH_BASE + 0x8000)
#define ETH_MAC_BASE          (ETH_BASE)
#define ETH_MSC_BASE          (ETH_BASE + 0x0100)
#define ETH_PTP_BASE          (ETH_BASE + 0x0700)
#define ETH_DMA_BASE          (ETH_BASE + 0x1000)

#define EXMC_BANK1_R_BASE     (EXMC_R_BASE + 0x0000) /*!< EXMC Bank1 registers base address */
#define EXMC_BANK1_WT_R_BASE  (EXMC_R_BASE + 0x0104) /*!< EXMC Bank1WT registers base address */
#define EXMC_BANK2_R_BASE     (EXMC_R_BASE + 0x0060) /*!< EXMC Bank2 registers base address */
#define EXMC_BANK3_R_BASE     (EXMC_R_BASE + 0x0080) /*!< EXMC Bank3 registers base address */
#define EXMC_BANK4_R_BASE     (EXMC_R_BASE + 0x00A0) /*!< EXMC Bank4 registers base address */

#define MCUDBG_BASE           ((uint32_t)0xE0042000) /*!< Debug MCU registers base address */

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */  

#define TIM2                  ((volatile uint32_t *) TIMER2_BASE)
#define TIM3                  ((volatile uint32_t *) TIMER3_BASE)
#define TIM4                  ((volatile uint32_t *) TIMER4_BASE)
#define TIM5                  ((volatile uint32_t *) TIMER5_BASE)
#define TIM6                  ((volatile uint32_t *) TIMER6_BASE)
#define TIM7                  ((volatile uint32_t *) TIMER7_BASE)
#define TIM12                 ((volatile uint32_t *) TIMER12_BASE)
#define TIM13                 ((volatile uint32_t *) TIMER13_BASE)
#define TIM14                 ((volatile uint32_t *) TIMER14_BASE)
#define RTC                   ((RTC_TypeDef *) RTC_BASE)
#define WWDG                  ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                  ((IWDG_TypeDef *) IWDG_BASE)
#define SPI2                  ((volatile uint32_t *) SPI2_BASE)
#define SPI3                  ((volatile uint32_t *) SPI3_BASE)
#define USART2                ((volatile uint32_t *) USART2_BASE)
#define USART3                ((volatile uint32_t *) USART3_BASE)
#define UART4                 ((volatile uint32_t *) UART4_BASE)
#define UART5                 ((volatile uint32_t *) UART5_BASE)
#define I2C1                  ((volatile uint32_t *) I2C1_BASE)
#define I2C2                  ((volatile uint32_t *) I2C2_BASE)
#define CAN1                  ((volatile uint32_t *) CAN1_BASE)
#define CAN2                  ((volatile uint32_t *) CAN2_BASE)
#define BKP                   ((BKP_TypeDef *) BKP_BASE)
#define PWR                   ((PWR_TypeDef *) PWR_BASE)
#define DAC                   ((volatile uint32_t *) DAC_BASE)
#define CEC                   ((CEC_TypeDef *) CEC_BASE)
#define AFIO                  ((volatile uint32_t *) AFIO_BASE)
#define EXTI                  ((volatile uint32_t *) EXTI_BASE)
#define GPIOA                 ((volatile uint32_t *) GPIOA_BASE)
#define GPIOB                 ((volatile uint32_t *) GPIOB_BASE)
#define GPIOC                 ((volatile uint32_t *) GPIOC_BASE)
#define GPIOD                 ((volatile uint32_t *) GPIOD_BASE)
#define GPIOE                 ((volatile uint32_t *) GPIOE_BASE)
#define GPIOF                 ((volatile uint32_t *) GPIOF_BASE)
#define GPIOG                 ((volatile uint32_t *) GPIOG_BASE)
#define ADC1                  ((volatile uint32_t *) ADC1_BASE)
#define ADC2                  ((volatile uint32_t *) ADC2_BASE)
#define TIM1                  ((volatile uint32_t *) TIMER1_BASE)
#define SPI1                  ((volatile uint32_t *) SPI1_BASE)
#define TIM8                  ((volatile uint32_t *) TIMER8_BASE)
#define USART1                ((volatile uint32_t *) USART1_BASE)
#define ADC3                  ((volatile uint32_t *) ADC3_BASE)
#define TIM15                 ((volatile uint32_t *) TIMER15_BASE)
#define TIM16                 ((volatile uint32_t *) TIMER16_BASE)
#define TIM17                 ((volatile uint32_t *) TIMER17_BASE)
#define TIM9                  ((volatile uint32_t *) TIMER9_BASE)
#define TIM10                 ((volatile uint32_t *) TIMER10_BASE)
#define TIM11                 ((volatile uint32_t *) TIMER11_BASE)
#define SDIO                  ((volatile uint32_t *) SDIO_BASE)
#define DMA1                  ((volatile uint32_t *) DMA1_BASE)
#define DMA2                  ((volatile uint32_t *) DMA2_BASE)
#define DMA1_CHANNEL1         ((volatile uint32_t *) DMA1_CHANNEL1_BASE)
#define DMA1_CHANNEL2         ((volatile uint32_t *) DMA1_CHANNEL2_BASE)
#define DMA1_CHANNEL3         ((volatile uint32_t *) DMA1_CHANNEL3_BASE)
#define DMA1_CHANNEL4         ((volatile uint32_t *) DMA1_CHANNEL4_BASE)
#define DMA1_CHANNEL5         ((volatile uint32_t *) DMA1_CHANNEL5_BASE)
#define DMA1_CHANNEL6         ((volatile uint32_t *) DMA1_CHANNEL6_BASE)
#define DMA1_CHANNEL7         ((volatile uint32_t *) DMA1_CHANNEL7_BASE)
#if defined(GD32F10X_HD) || defined(GD32F10X_XD)
#define DMA2_CHANNEL1         ((volatile uint32_t *) DMA2_CHANNEL1_BASE)
#define DMA2_CHANNEL2         ((volatile uint32_t *) DMA2_CHANNEL2_BASE)
#define DMA2_CHANNEL3         ((volatile uint32_t *) DMA2_CHANNEL3_BASE)
#define DMA2_CHANNEL4         ((volatile uint32_t *) DMA2_CHANNEL4_BASE)
#define DMA2_CHANNEL5         ((volatile uint32_t *) DMA2_CHANNEL5_BASE)
#endif
#define RCC                   ((volatile uint32_t *) RCC_BASE)
#define CRC                   ((volatile uint32_t *) CRC_BASE)
#define FMC                   ((volatile uint32_t *) FMC_R_BASE)
#define OB                    ((OB_TypeDef *) OB_BASE) 
#define EXMC_BANK1            ((EXMC_Bank1_TypeDef *) EXMC_BANK1_R_BASE)
#define EXMC_BANK1_WT         ((EXMC_Bank1_WT_TypeDef *) EXMC_BANK1_WT_R_BASE)
#define EXMC_BANK2            ((EXMC_Bank2_TypeDef *) EXMC_BANK2_R_BASE)
#define EXMC_BANK3            ((EXMC_Bank3_TypeDef *) EXMC_BANK3_R_BASE)
#define EXMC_BANK4            ((EXMC_Bank4_TypeDef *) EXMC_BANK4_R_BASE)
#define MCUDBG                ((MCUDBG_TypeDef *) MCUDBG_BASE)
#define ETH_MAC               ((ETH_MAC_TypeDef *) ETH_MAC_BASE)
#define ETH_MSC               ((ETH_MSC_TypeDef *) ETH_MSC_BASE)
#define ETH_PTP               ((ETH_PTP_TypeDef *) ETH_PTP_BASE)
#define ETH_DMA               ((ETH_DMA_Typedef *) ETH_DMA_BASE)
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GD32F10X_H */

/******************* (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
