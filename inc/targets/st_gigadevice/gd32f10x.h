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

#define TIM1_UP_IRQn	TIM1_UP_TIM10_IRQn
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

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Backup Registers
  */
typedef struct
{
    uint32_t  RESERVED0;
    __IO uint16_t DR1;
    uint16_t  RESERVED1;
    __IO uint16_t DR2;
    uint16_t  RESERVED2;
    __IO uint16_t DR3;
    uint16_t  RESERVED3;
    __IO uint16_t DR4;
    uint16_t  RESERVED4;
    __IO uint16_t DR5;
    uint16_t  RESERVED5;
    __IO uint16_t DR6;
    uint16_t  RESERVED6;
    __IO uint16_t DR7;
    uint16_t  RESERVED7;
    __IO uint16_t DR8;
    uint16_t  RESERVED8;
    __IO uint16_t DR9;
    uint16_t  RESERVED9;
    __IO uint16_t DR10;
    uint16_t  RESERVED10; 
    __IO uint16_t RCCR;
    uint16_t  RESERVED11;
    __IO uint16_t TPCR;
    uint16_t  RESERVED12;
    __IO uint16_t TIER;
    uint16_t  RESERVED13[5];
    __IO uint16_t DR11;
    uint16_t  RESERVED14;
    __IO uint16_t DR12;
    uint16_t  RESERVED15;
    __IO uint16_t DR13;
    uint16_t  RESERVED16;
    __IO uint16_t DR14;
    uint16_t  RESERVED17;
    __IO uint16_t DR15;
    uint16_t  RESERVED18;
    __IO uint16_t DR16;
    uint16_t  RESERVED19;
    __IO uint16_t DR17;
    uint16_t  RESERVED20;
    __IO uint16_t DR18;
    uint16_t  RESERVED21;
    __IO uint16_t DR19;
    uint16_t  RESERVED22;
    __IO uint16_t DR20;
    uint16_t  RESERVED23;
    __IO uint16_t DR21;
    uint16_t  RESERVED24;
    __IO uint16_t DR22;
    uint16_t  RESERVED25;
    __IO uint16_t DR23;
    uint16_t  RESERVED26;
    __IO uint16_t DR24;
    uint16_t  RESERVED27;
    __IO uint16_t DR25;
    uint16_t  RESERVED28;
    __IO uint16_t DR26;
    uint16_t  RESERVED29;
    __IO uint16_t DR27;
    uint16_t  RESERVED30;
    __IO uint16_t DR28;
    uint16_t  RESERVED31;
    __IO uint16_t DR29;
    uint16_t  RESERVED32;
    __IO uint16_t DR30;
    uint16_t  RESERVED33; 
    __IO uint16_t DR31;
    uint16_t  RESERVED34;
    __IO uint16_t DR32;
    uint16_t  RESERVED35;
    __IO uint16_t DR33;
    uint16_t  RESERVED36;
    __IO uint16_t DR34;
    uint16_t  RESERVED37;
    __IO uint16_t DR35;
    uint16_t  RESERVED38;
    __IO uint16_t DR36;
    uint16_t  RESERVED39;
    __IO uint16_t DR37;
    uint16_t  RESERVED40;
    __IO uint16_t DR38;
    uint16_t  RESERVED41;
    __IO uint16_t DR39;
    uint16_t  RESERVED42;
    __IO uint16_t DR40;
    uint16_t  RESERVED43;
    __IO uint16_t DR41;
    uint16_t  RESERVED44;
    __IO uint16_t DR42;
    uint16_t  RESERVED45;
} BKP_TypeDef;

/** 
  * @brief Debug MCU
  */
typedef struct
{
    __IO uint32_t IDR;                 /*!< MCU device ID code,                          Address offset: 0x00 */
    __IO uint32_t CTLR;                /*!< Debug MCU CTLR freeze register,              Address offset: 0x04 */
}MCUDBG_TypeDef;

typedef struct
{
    __IO uint32_t CFR;                 /*!< Ethernet MAC configuration register,  Address offset: 0x00 */    
    __IO uint32_t FRMFR;               /*!< Ethernet MAC frame filter register,  Address offset: 0x04 */    
    __IO uint32_t HLHR;                /*!< Ethernet MAC hash list high register,  Address offset: 0x08 */    
    __IO uint32_t HLLR;                /*!< Ethernet MAC hash list low register,  Address offset: 0x0C */    
    __IO uint32_t PHYAR;               /*!< Ethernet MAC PHY address register,  Address offset: 0x10 */    
    __IO uint32_t PHYDR;               /*!< Ethernet MAC PHY data register,  Address offset: 0x14 */
    __IO uint32_t FCTLR;               /*!< Ethernet MAC flow control register,  Address offset: 0x18 */
    __IO uint32_t VLTR;                /*!< Ethernet MAC VLAN tag register,  Address offset: 0x1C */     
         uint32_t RESERVED0[2];        /*!< Reserved,    0x24 */
    __IO uint32_t RWFFR;               /*!< Ethernet MAC remote wakeup frame filter register,  Address offset: 0x28 */        
    __IO uint32_t WUMR;                /*!< Ethernet MAC wake up management register,  Address offset: 0x2C */
         uint32_t RESERVED1[2];        /*!< Reserved,    0x34 */
    __IO uint32_t ISR;                 /*!< Ethernet MAC interrupt status register,  Address offset: 0x38 */         
    __IO uint32_t IMR;                 /*!< Ethernet MAC interrupt mask register,  Address offset: 0x3C */
    __IO uint32_t ADDR0HR;             /*!< Ethernet MAC address 0 high register,  Address offset: 0x40 */
    __IO uint32_t ADDR0LR;             /*!< Ethernet MAC address 0 low register,  Address offset: 0x44 */
    __IO uint32_t ADDR1HR;             /*!< Ethernet MAC address 1 high register,  Address offset: 0x48 */
    __IO uint32_t ADDR1LR;             /*!< Ethernet MAC address 1 low register,  Address offset: 0x4C */
    __IO uint32_t ADDR2HR;             /*!< Ethernet MAC address 2 high register,  Address offset: 0x50 */
    __IO uint32_t ADDR2LR;             /*!< Ethernet MAC address 2 low register,  Address offset: 0x54 */
    __IO uint32_t ADDR3HR;             /*!< Ethernet MAC address 3 high register,  Address offset: 0x58 */
    __IO uint32_t ADDR3LR;             /*!< Ethernet MAC address 3 low register,  Address offset: 0x5C */            
         uint32_t RESERVED2[1032];     /*!< Reserved,    0x107C */
    __IO uint32_t FCTHR;               /*!< Ethernet MAC flow control threshold register,  Address offset: 0x1080 */ 
} ETH_MAC_TypeDef;

typedef struct
{
    __IO uint32_t CTLR;                /*!< Ethernet MSC control register,  Address offset: 0x100 */ 
    __IO uint32_t RISR;                /*!< Ethernet MSC receive interrupt status register,  Address offset: 0x104 */    
    __IO uint32_t TISR;                /*!< Ethernet MSC transmit interrupt status register,  Address offset: 0x108 */
    __IO uint32_t RIMR;                /*!< Ethernet MSC receive interrupt mask register,  Address offset: 0x10C */
    __IO uint32_t TIMR;                /*!< Ethernet MSC transmit interrupt mask register,  Address offset: 0x110 */       
         uint32_t RESERVED3[14];       /*!< Reserved,    0x148 */
    __IO uint32_t SCCNT;               /*!< Ethernet MSC transmitted good frames after a single collision counterregister,  Address offset: 0x14C */  
    __IO uint32_t MSCCNT;              /*!< Ethernet MSC transmitted good frames after more than a single collision counterregister,  Address offset: 0x150 */    
         uint32_t RESERVED4[5];        /*!< Reserved,    0x164 */
    __IO uint32_t TGFCNT;              /*!< Ethernet MSC transmitted good frames counter register,  Address offset: 0x168 */
         uint32_t RESERVED5[10];       /*!< Reserved,    0x190 */
    __IO uint32_t RFCECNT;             /*!< Ethernet MSC received frames with CRC error counter register,  Address offset: 0x194 */
    __IO uint32_t RFAECNT;             /*!< Ethernet MSC received frames with alignment error counter register,  Address offset: 0x198 */
         uint32_t RESERVED6[10];       /*!< Reserved,    0x1C0 */
    __IO uint32_t RGUFCNT;             /*!< Ethernet MSC received good unicast frames counter register,  Address offset: 0x1C4 */    
} ETH_MSC_TypeDef;

typedef struct
{
    __IO uint32_t TSCTLR;              /*!< Ethernet PTP time stamp control register,  Address offset: 0x700 */
    __IO uint32_t SSINCR;              /*!< Ethernet PTP subsecond increment register,  Address offset: 0x704 */
    __IO uint32_t TMSHR;               /*!< Ethernet PTP time stamp high register,  Address offset: 0x708 */
    __IO uint32_t TMSLR;               /*!< Ethernet PTP time stamp low register,  Address offset: 0x70C */
    __IO uint32_t TMSHUR;              /*!< Ethernet PTP time stamp high update register,  Address offset: 0x710 */
    __IO uint32_t TMSLUR;              /*!< Ethernet PTP time stamp low update register,  Address offset: 0x714 */
    __IO uint32_t TSACNT;              /*!< Ethernet PTP time stamp addend register,  Address offset: 0x718 */
    __IO uint32_t ETHR;                /*!< Ethernet PTP expected time high register,  Address offset: 0x71C */
    __IO uint32_t ETLR;                /*!< Ethernet PTP expected time low register,  Address offset: 0x720 */
} ETH_PTP_TypeDef;

typedef struct
{
    __IO uint32_t BCR;                 /*!< Ethernet DMA bus control register,  Address offset: 0x1000 */
    __IO uint32_t TPER;                /*!< Ethernet DMA transmit poll enable register,  Address offset: 0x1004 */
    __IO uint32_t RPER;                /*!< Ethernet DMA receive poll enable register,  Address offset: 0x1008 */
    __IO uint32_t RDTAR;               /*!< Ethernet DMA receive descriptor tab address register,  Address offset: 0x100C */
    __IO uint32_t TDTAR;               /*!< Ethernet DMA transmit descriptor tab address register,  Address offset: 0x1010 */
    __IO uint32_t STR;                 /*!< Ethernet DMA status register,  Address offset: 0x1014 */
    __IO uint32_t CTLR;                /*!< Ethernet DMA control register,  Address offset: 0x1018 */
    __IO uint32_t IER;                 /*!< Ethernet DMA interrupt enable register,  Address offset: 0x1018 */
    __IO uint32_t MFBOCNT;             /*!< Ethernet DMA missed frame and buffer overflow counter register,  Address offset: 0x101C */
         uint32_t RESERVED7[9];        /*!< Reserved,    0x1044 */
    __IO uint32_t CTDAR;               /*!< Ethernet DMA current transmit descriptor address register,  Address offset: 0x1048 */
    __IO uint32_t CRDAR;               /*!< Ethernet DMA current receive descriptor address register,  Address offset: 0x104C */
    __IO uint32_t CTBAR;               /*!< Ethernet DMA current transmit buffer address register,  Address offset: 0x1050 */
    __IO uint32_t CRBAR;               /*!< Ethernet DMA current receive buffer address register,  Address offset: 0x1054 */
} ETH_DMA_Typedef;

/** 
  * @brief Option Bytes Registers
  */
typedef struct
{
    __IO uint16_t RDP;                 /*!<FMC option byte Read protection,               Address offset: 0x00 */
    __IO uint16_t USER;                /*!<FMC option byte user options,                  Address offset: 0x02 */
    uint16_t RESERVED0;                /*!< Reserved,                                                     0x04 */
    uint16_t RESERVED1;                /*!< Reserved,                                                     0x06 */
    __IO uint16_t WRP0;                /*!<FMC option byte write protection 0,            Address offset: 0x08 */
    __IO uint16_t WRP1;                /*!<FMC option byte write protection 1,            Address offset: 0x0C */
    __IO uint16_t WRP2;                /*!<FMC option byte write protection 2,            Address offset: 0x10 */
    __IO uint16_t WRP3;                /*!<FMC option byte write protection 3,            Address offset: 0x14 */
} OB_TypeDef;
/** 
  * @brief External Memory Controller Bank1
  */
typedef struct
{
    __IO uint32_t SCTLR1;  
    __IO uint32_t STR1; 
    __IO uint32_t SCTLR2; 
    __IO uint32_t STR2; 
    __IO uint32_t SCTLR3; 
    __IO uint32_t STR3;  
    __IO uint32_t SCTLR4; 
    __IO uint32_t STR4; 
} EXMC_Bank1_TypeDef;

/** 
  * @brief External Memory Controller Bank1_WT
  */
typedef struct
{
    __IO uint32_t SWTR1;
    uint32_t  RESERVED0;
    __IO uint32_t SWTR2;
    uint32_t  RESERVED1;
    __IO uint32_t SWTR3;
    uint32_t  RESERVED2;
    __IO uint32_t SWTR4;
} EXMC_Bank1_WT_TypeDef;

/** 
  * @brief External Memory Controller Bank2
  */
typedef struct
{
    __IO uint32_t CTLR2;
    __IO uint32_t SIR2;
    __IO uint32_t COMTR2;
    __IO uint32_t ATTR2;
    uint32_t  RESERVED;   
    __IO uint32_t ECCR2; 
} EXMC_Bank2_TypeDef;

/** 
  * @brief External Memory Controller Bank3
  */
typedef struct
{
    __IO uint32_t CTLR3;
    __IO uint32_t SIR3;
    __IO uint32_t COMTR3;
    __IO uint32_t ATTR3;
    uint32_t  RESERVED;   
    __IO uint32_t ECCR3; 
} EXMC_Bank3_TypeDef;

/** 
  * @brief External Memory Controller Bank4
  */
typedef struct
{
    __IO uint32_t CTLR4;
    __IO uint32_t SIR4;
    __IO uint32_t COMTR4;
    __IO uint32_t ATTR4;
    __IO uint32_t IOTR4; 
} EXMC_Bank4_TypeDef;

/** 
  * @brief Independent WATCHDOG
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< IWDG Key register,                 Address offset: 0x00 */
    __IO uint32_t PSR;                 /*!< IWDG Prescaler register,           Address offset: 0x04 */
    __IO uint32_t RLDR;                /*!< IWDG Reload register,              Address offset: 0x08 */
    __IO uint32_t STR;                 /*!< IWDG Status register,              Address offset: 0x0C */
} IWDG_TypeDef;

/** 
  * @brief Power Control
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< PWR power control register,        Address offset: 0x00 */
    __IO uint32_t STR;                 /*!< PWR power status register,         Address offset: 0x04 */
} PWR_TypeDef;

/** 
  * @brief Real-Time Clock
  */
typedef struct
{
    __IO uint16_t CTLR1;               /*!< RTC Control register1,             Address offset: 0x00 */
    uint16_t  RESERVED0;  
    __IO uint16_t CTLR2;               /*!< RTC Control register2,             Address offset: 0x04 */
    uint16_t  RESERVED1;
    __IO uint16_t PLR1;                /*!< RTC Prescaler Load register1,      Address offset: 0x08 */ 
    uint16_t  RESERVED2;
    __IO uint16_t PLR2;                /*!< RTC Prescaler Load register2,      Address offset: 0x0C */
    uint16_t  RESERVED3; 
    __IO uint16_t PREDIV1;             /*!< RTC Prescaler Divider register1,   Address offset: 0x10 */ 
    uint16_t  RESERVED4;
    __IO uint16_t PREDIV2;             /*!< RTC Prescaler Divider register2,   Address offset: 0x14 */
    uint16_t  RESERVED5;
    __IO uint16_t CNT1;                /*!< RTC Counter register1,             Address offset: 0x18 */
    uint16_t  RESERVED6;
    __IO uint16_t CNT2;                /*!< RTC Counter register2,             Address offset: 0x1C */
    uint16_t  RESERVED7;
    __IO uint16_t ALRMR1;              /*!< RTC Alarm register1,               Address offset: 0x20 */
    uint16_t  RESERVED8;              
    __IO uint16_t ALRMR2;              /*!< RTC Alarm register2,               Address offset: 0x24 */
    uint16_t  RESERVED9;
} RTC_TypeDef;

/** 
  * @brief Window WATCHDOG
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< WWDG Control register,                              Address offset: 0x00 */
    __IO uint32_t CFR;                 /*!< WWDG Configuration register,                        Address offset: 0x04 */
    __IO uint32_t STR;                 /*!< WWDG Status register,                               Address offset: 0x08 */
} WWDG_TypeDef;

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
#define DMA2_CHANNEL1         ((volatile uint32_t *) DMA2_CHANNEL1_BASE)
#define DMA2_CHANNEL2         ((volatile uint32_t *) DMA2_CHANNEL2_BASE)
#define DMA2_CHANNEL3         ((volatile uint32_t *) DMA2_CHANNEL3_BASE)
#define DMA2_CHANNEL4         ((volatile uint32_t *) DMA2_CHANNEL4_BASE)
#define DMA2_CHANNEL5         ((volatile uint32_t *) DMA2_CHANNEL5_BASE)
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

/** @addtogroup Exported_constants
  * @{
  */
  
  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                            Backup registers                                */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for BKP_DRx register  ********************/
#define  BKP_DR1_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR2_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR3_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR4_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR5_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR6_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR7_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR8_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR9_BKD                                ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR10_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR11_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR12_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR13_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR14_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR15_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR16_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR17_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR18_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR19_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR20_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR21_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR22_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR23_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR24_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR25_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR26_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR27_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR28_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR29_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR30_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR31_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR32_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR33_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR34_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR35_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR36_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR37_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR38_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR39_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR40_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR41_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */
#define  BKP_DR42_BKD                               ((uint16_t)0xFFFF)     /*!< Backup data */

/******************  Bit definition for BKP_RCCR register  *******************/
#define  BKP_RCCR_RCCV                              ((uint16_t)0x007F)     /*!< RTC Clock Calibration Value */
#define  BKP_RCCR_RCCOE                             ((uint16_t)0x0080)     /*!< RTC Clock Calibration Output Enable */
#define  BKP_RCCR_ROE                               ((uint16_t)0x0100)     /*!< RTC Output Enable */
#define  BKP_RCCR_ROS                               ((uint16_t)0x0200)     /*!< RTC Output Selection */

/********************  Bit definition for BKP_TPCR register  ********************/
#define  BKP_TPCR_TPE                               ((uint8_t)0x01)        /*!< TAMPER Pin Enable */
#define  BKP_TPCR_TPAL                              ((uint8_t)0x02)        /*!< TAMPER Pin Active Level */

/*******************  Bit definition for BKP_TIER register  ********************/
#define  BKP_TIER_TER                               ((uint16_t)0x0001)     /*!< Tamper Event Reset */
#define  BKP_TIER_TIR                               ((uint16_t)0x0002)     /*!< Tamper Interrupt Reset */
#define  BKP_TIER_TIE                               ((uint16_t)0x0004)     /*!< Tamper Interrupt Enable */
#define  BKP_TIER_TEF                               ((uint16_t)0x0100)     /*!< Tamper Event Flag */
#define  BKP_TIER_TIF                               ((uint16_t)0x0200)     /*!< Tamper Interrupt Flag */

/******************************************************************************/
/*                                                                            */
/*                           Debug MCU (MCUDBG)                               */
/*                                                                            */
/******************************************************************************/

/****************  Bit definition for MCUDBG_IDR register  *****************/
#define  MCUDBG_IDR_DEV_ID                          ((uint32_t)0x00000FFF)      /*!< Device Identifier */
#define  MCUDBG_IDR_REV_ID                          ((uint32_t)0xFFFF0000)      /*!< REV_ID[15:0] bits (Revision Identifier) */
#define  MCUDBG_IDR_REV_ID_0                        ((uint32_t)0x00010000)      /*!< Bit 0 */
#define  MCUDBG_IDR_REV_ID_1                        ((uint32_t)0x00020000)      /*!< Bit 1 */
#define  MCUDBG_IDR_REV_ID_2                        ((uint32_t)0x00040000)      /*!< Bit 2 */
#define  MCUDBG_IDR_REV_ID_3                        ((uint32_t)0x00080000)      /*!< Bit 3 */
#define  MCUDBG_IDR_REV_ID_4                        ((uint32_t)0x00100000)      /*!< Bit 4 */
#define  MCUDBG_IDR_REV_ID_5                        ((uint32_t)0x00200000)      /*!< Bit 5 */
#define  MCUDBG_IDR_REV_ID_6                        ((uint32_t)0x00400000)      /*!< Bit 6 */
#define  MCUDBG_IDR_REV_ID_7                        ((uint32_t)0x00800000)      /*!< Bit 7 */
#define  MCUDBG_IDR_REV_ID_8                        ((uint32_t)0x01000000)      /*!< Bit 8 */
#define  MCUDBG_IDR_REV_ID_9                        ((uint32_t)0x02000000)      /*!< Bit 9 */
#define  MCUDBG_IDR_REV_ID_10                       ((uint32_t)0x04000000)      /*!< Bit 10 */
#define  MCUDBG_IDR_REV_ID_11                       ((uint32_t)0x08000000)      /*!< Bit 11 */
#define  MCUDBG_IDR_REV_ID_12                       ((uint32_t)0x10000000)      /*!< Bit 12 */
#define  MCUDBG_IDR_REV_ID_13                       ((uint32_t)0x20000000)      /*!< Bit 13 */
#define  MCUDBG_IDR_REV_ID_14                       ((uint32_t)0x40000000)      /*!< Bit 14 */
#define  MCUDBG_IDR_REV_ID_15                       ((uint32_t)0x80000000)      /*!< Bit 15 */

/******************  Bit definition for MCUDBG_CR register  *******************/
#define  MCUDBG_CR_DBG_DEEPSLEEP                    ((uint32_t)0x00000002)      /*!< Debug Deep-sleep Mode */
#define  MCUDBG_CR_DBG_STANDBY                      ((uint32_t)0x00000004)      /*!< Debug Standby mode */
										 
/******************  Bit definition for MCUDBG_APB1_FZ register  **************/
#define  MCUDBG_APB1_FZ_DBG_TIMER2_STOP             ((uint32_t)0x00000001)      /*!< TIMER2 counter stopped when core is halted */
#define  MCUDBG_APB1_FZ_DBG_TIMER3_STOP             ((uint32_t)0x00000002)      /*!< TIMER3 counter stopped when core is halted */
#define  MCUDBG_APB1_FZ_DBG_TIMER6_STOP             ((uint32_t)0x00000010)      /*!< TIMER6 counter stopped when core is halted */
#define  MCUDBG_APB1_FZ_DBG_TIMER14_STOP            ((uint32_t)0x00000100)      /*!< TIMER14 counter stopped when core is halted */
#define  MCUDBG_CTLR2_RTC_HOLD                      ((uint32_t)0x00000400)      /*!< RTC Calendar frozen when core is halted */
#define  MCUDBG_APB1_FZ_DBG_WWDG_STOP               ((uint32_t)0x00000800)      /*!< Debug Window Watchdog stopped when Core is halted */
#define  MCUDBG_APB1_FZ_DBG_IWDG_STOP               ((uint32_t)0x00001000)      /*!< Debug Independent Watchdog stopped when Core is halted */
#define  MCUDBG_APB1_FZ_DBG_I2C1_SMBUS_TIMEREOUT    ((uint32_t)0x00200000) /*!< I2C1 SMBUS timeout mode stopped when Core is halted */

/******************  Bit definition for MCUDBG_APB2_FZ register  **************/
#define  MCUDBG_APB2_FZ_DBG_TIMER1_STOP             ((uint32_t)0x00000800)      /*!< TIMER1 counter stopped when core is halted */
#define  MCUDBG_APB2_FZ_DBG_TIMER15_STOP            ((uint32_t)0x00010000)      /*!< TIMER15 counter stopped when core is halted */
#define  MCUDBG_APB2_FZ_DBG_TIMER16_STOP            ((uint32_t)0x00020000)      /*!< TIMER16 counter stopped when core is halted */
#define  MCUDBG_APB2_FZ_DBG_TIMER17_STOP            ((uint32_t)0x00040000)      /*!< TIMER17 counter stopped when core is halted */

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition                */
/******************************************************************************/
/******************************************************************************/
/*                Ethernet MAC Registers bits definitions                     */
/******************************************************************************/

/* Bit definition for Ethernet MAC Configuration register */
#define ETH_MAC_CFR_WDD                             ((uint32_t)0x00800000)  /* Watchdog disable */
#define ETH_MAC_CFR_JBD                             ((uint32_t)0x00400000)  /* Jabber disable */
#define ETH_MAC_CFR_IG                              ((uint32_t)0x000E0000)  /* Inter-frame gap */
#define ETH_MAC_CFR_IG_96BIT                        ((uint32_t)0x00000000)  /* Minimum IG 96Bit */ 
#define ETH_MAC_CFR_IG_88BIT                        ((uint32_t)0x00020000)  /* Minimum IG 88Bit */
#define ETH_MAC_CFR_IG_80BIT                        ((uint32_t)0x00040000)  /* Minimum IG 80Bit */
#define ETH_MAC_CFR_IG_72BIT                        ((uint32_t)0x00060000)  /* Minimum IG 72Bit */
#define ETH_MAC_CFR_IG_64BIT                        ((uint32_t)0x00080000)  /* Minimum IG 64Bit */        
#define ETH_MAC_CFR_IG_56BIT                        ((uint32_t)0x000A0000)  /* Minimum IG 56Bit */
#define ETH_MAC_CFR_IG_48BIT                        ((uint32_t)0x000C0000)  /* Minimum IG 48Bit */
#define ETH_MAC_CFR_IG_40BIT                        ((uint32_t)0x000E0000)  /* Minimum IG 40Bit */              
#define ETH_MAC_CFR_CSD                             ((uint32_t)0x00010000)  /* Carrier sense disable */
#define ETH_MAC_CFR_SPD                             ((uint32_t)0x00004000)  /* Ethernet speed */
#define ETH_MAC_CFR_ROD                             ((uint32_t)0x00002000)  /* Receive own disable */
#define ETH_MAC_CFR_LBM                             ((uint32_t)0x00001000)  /* loopback mode */
#define ETH_MAC_CFR_DPM                             ((uint32_t)0x00000800)  /* Duplex mode */
#define ETH_MAC_CFR_IP4CO                           ((uint32_t)0x00000400)  /* IP Checksum offload */
#define ETH_MAC_CFR_RTD                             ((uint32_t)0x00000200)  /* Retry disable */
#define ETH_MAC_CFR_APCD                            ((uint32_t)0x00000080)  /* automatic pad/CRC drop */
#define ETH_MAC_CFR_BOL                             ((uint32_t)0x00000060)  /* Back-off limit */
#define ETH_MAC_CFR_BOL_10                          ((uint32_t)0x00000000)  /* min (n, 10) */
#define ETH_MAC_CFR_BOL_8                           ((uint32_t)0x00000020)  /* min (n, 8) */
#define ETH_MAC_CFR_BOL_4                           ((uint32_t)0x00000040)  /* min (n, 4) */
#define ETH_MAC_CFR_BOL_1                           ((uint32_t)0x00000060)  /* min (n, 1) */ 
#define ETH_MAC_CFR_DFC                             ((uint32_t)0x00000010)  /* Defferal check */
#define ETH_MAC_CFR_TEN                             ((uint32_t)0x00000008)  /* Transmitter enable */
#define ETH_MAC_CFR_REN                             ((uint32_t)0x00000004)  /* Receiver enable */
  
  /* Bit definition for Ethernet MAC Frame Filter Register */
#define ETH_MAC_FRMFR_FD                            ((uint32_t)0x80000000)  /* Filter disable */ 
#define ETH_MAC_FRMFR_HPFLT                         ((uint32_t)0x00000400)  /* Hash or perfect filter */ 
#define ETH_MAC_FRMFR_SAFLT                         ((uint32_t)0x00000200)  /* Source address filter enable */ 
#define ETH_MAC_FRMFR_SAIFLT                        ((uint32_t)0x00000100)  /* SA inverse filtering enable */ 
#define ETH_MAC_FRMFR_PCFRM                         ((uint32_t)0x000000C0)  /* Pass control frames */
#define ETH_MAC_FRMFR_PCF_BLOCKALL                  ((uint32_t)0x00000040)  /* Prevent all control frames received */
#define ETH_MAC_FRMFR_PCF_FORWARDALL                ((uint32_t)0x00000080)  /* Accept all control frames received */
#define ETH_MAC_FRMFR_PCF_FORWARDPASSEDADDRFILTER   ((uint32_t)0x000000C0)  /* Accept control frames that pass the Address Filter */ 
#define ETH_MAC_FRMFR_BFRMD                         ((uint32_t)0x00000020)  /* Broadcast frame disable */ 
#define ETH_MAC_FRMFR_MFD                           ((uint32_t)0x00000010)  /* Multicast filter disable */ 
#define ETH_MAC_FRMFR_DAIFLT                        ((uint32_t)0x00000008)  /* DA Inverse filtering enable */ 
#define ETH_MAC_FRMFR_HMF                           ((uint32_t)0x00000004)  /* Hash multicast filter enable */ 
#define ETH_MAC_FRMFR_HUF                           ((uint32_t)0x00000002)  /* Hash unicast filter enable */
#define ETH_MAC_FRMFR_PM                            ((uint32_t)0x00000001)  /* Promiscuous mode */
  
/* Bit definition for Ethernet MAC Hash List High Register */
#define ETH_MAC_HLHR_HLH                            ((uint32_t)0xFFFFFFFF)  /* Hash list high */
  
/* Bit definition for Ethernet MAC Hash List Low Register */
#define ETH_MAC_HLLR_HLL                            ((uint32_t)0xFFFFFFFF)  /* Hash list low */
  
/* Bit definition for Ethernet MAC PHY Address Register */
#define ETH_MAC_PHYAR_PA                            ((uint32_t)0x0000F800)  /* PHY address */ 
#define ETH_MAC_PHYAR_PR                            ((uint32_t)0x000007C0)  /* PHY register address  */ 
#define ETH_MAC_PHYAR_CLR                           ((uint32_t)0x0000001C)  /* MDC clock range */ 
#define ETH_MAC_PHYAR_CLR_DIV42                     ((uint32_t)0x00000000)  /* HCLK:60-90 MHz; MDC clock= HCLK/42 */
#define ETH_MAC_PHYAR_CLR_DIV64                     ((uint32_t)0x00000004)  /* HCLK:90-108 MHz; MDC clock= HCLK/64 */
#define ETH_MAC_PHYAR_CLR_DIV16                     ((uint32_t)0x00000008)  /* HCLK:20-35 MHz; MDC clock= HCLK/16 */
#define ETH_MAC_PHYAR_CLR_DIV26                     ((uint32_t)0x0000000C)  /* HCLK:35-60 MHz; MDC clock= HCLK/26 */
#define ETH_MAC_PHYAR_PW                            ((uint32_t)0x00000002)  /* PHY write */ 
#define ETH_MAC_PHYAR_PB                            ((uint32_t)0x00000001)  /* PHY busy */ 
    
/* Bit definition for Ethernet PHY Data Register */
#define ETH_MAC_PHYDR_PD                            ((uint32_t)0x0000FFFF)  /* PHY data: read/write data from/to PHY */
  
/* Bit definition for Ethernet MAC Flow Control Register */
#define ETH_MAC_FCTLR_PTM                           ((uint32_t)0xFFFF0000)  /* Pause time */
#define ETH_MAC_FCTLR_ZQPD                          ((uint32_t)0x00000080)  /* Zero-quanta pause disable */
#define ETH_MAC_FCTLR_PLTS                          ((uint32_t)0x00000030)  /* Pause low threshold */
#define ETH_MAC_FCTLR_PLTS_MINUS4                   ((uint32_t)0x00000000)  /* Pause time minus 4 slot times */
#define ETH_MAC_FCTLR_PLTS_MINUS28                  ((uint32_t)0x00000010)  /* Pause time minus 28 slot times */
#define ETH_MAC_FCTLR_PLTS_MINUS144                 ((uint32_t)0x00000020)  /* Pause time minus 144 slot times */
#define ETH_MAC_FCTLR_PLTS_MINUS256                 ((uint32_t)0x00000030)  /* Pause time minus 256 slot times */      
#define ETH_MAC_FCTLR_UPFDT                         ((uint32_t)0x00000008)  /* Unicast pause frame detect enable*/
#define ETH_MAC_FCTLR_RFCEN                         ((uint32_t)0x00000004)  /* Receive flow control enable */
#define ETH_MAC_FCTLR_TFCEN                         ((uint32_t)0x00000002)  /* Transmit flow control enable */
#define ETH_MAC_FCTLR_FLCBBKPA                      ((uint32_t)0x00000001)  /* Flow control busy(in full duplex mode)/backpressure activate(in half duplex mode) */
  
/* Bit definition for Ethernet MAC VLAN Tag Register */
#define ETH_MAC_VLTR_VLTC                           ((uint32_t)0x00010000)  /* 12-bit VLAN tag comparison enable*/
#define ETH_MAC_VLTR_VLTI                           ((uint32_t)0x0000FFFF)  /* VLAN tag identifier */
  
/* Bit definition for Ethernet MAC Remote Wake-UpFrame Filter Register */ 
#define ETH_MAC_RWUFFR_D                            ((uint32_t)0xFFFFFFFF)  /* Wake-up frame filter register data */
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
  
/* Bit definition for Ethernet MAC WUM Register */ 
#define ETH_MAC_WUMR_WUFFRPR                        ((uint32_t)0x80000000)  /* Wake-Up Frame Filter Register Pointer Reset */
#define ETH_MAC_WUMR_GU                             ((uint32_t)0x00000200)  /* Global Unicast */
#define ETH_MAC_WUMR_WUFR                           ((uint32_t)0x00000040)  /* Wake-Up Frame Received */
#define ETH_MAC_WUMR_MPKR                           ((uint32_t)0x00000020)  /* Magic Packet Received */
#define ETH_MAC_WUMR_WFEN                           ((uint32_t)0x00000004)  /* Wake-Up Frame Enable */
#define ETH_MAC_WUMR_MPEN                           ((uint32_t)0x00000002)  /* Magic Packet Enable */
#define ETH_MAC_WUMR_PWD                            ((uint32_t)0x00000001)  /* Power Down */
  
/* Bit definition for Ethernet MAC Status Register */
#define ETH_MAC_ISR_TMST                            ((uint32_t)0x00000200)  /* Time stamp trigger status */
#define ETH_MAC_ISR_MSCT                            ((uint32_t)0x00000040)  /* MSC transmit status */
#define ETH_MAC_ISR_MSCR                            ((uint32_t)0x00000020)  /* MSC receive status */
#define ETH_MAC_ISR_MSC                             ((uint32_t)0x00000010)  /* MSC status */
#define ETH_MAC_ISR_WUM                             ((uint32_t)0x00000008)  /* WUM status */
  										   
/* Bit definition for Ethernet MAC Interrupt Mask Register */
#define ETH_MAC_IMR_TMSTIM                          ((uint32_t)0x00000200)  /* Time stamp trigger interrupt mask */
#define ETH_MAC_IMR_WUMIM                           ((uint32_t)0x00000008)  /* WUM interrupt mask */
  											   
/* Bit definition for Ethernet MAC Address0 High Register */
#define ETH_MAC_A0HR_ADDR0H                         ((uint32_t)0x0000FFFF)  /* MAC address0 high */
  
  /* Bit definition for Ethernet MAC Address0 Low Register */
#define ETH_MAC_A0HR_ADDR0L                         ((uint32_t)0xFFFFFFFF)  /* MAC address0 low */
  
/* Bit definition for Ethernet MAC Address1 High Register */
#define ETH_MAC_A1HR_AFE                            ((uint32_t)0x80000000)  /* Address filter enable */
#define ETH_MAC_A1HR_SAF                            ((uint32_t)0x40000000)  /* Source address filter */
#define ETH_MAC_A1HR_MB                             ((uint32_t)0x3F000000)  /* Mask byte control */
#define ETH_MAC_A1HR_MB_HBITS15_8                   ((uint32_t)0x20000000)  /* High register bits [15:8] */
#define ETH_MAC_A1HR_MB_HBITS7_0                    ((uint32_t)0x10000000)  /* High register bits [7:0] */
#define ETH_MAC_A1HR_MB_LBITS31_24                  ((uint32_t)0x08000000)  /* Low register bits [31:24] */
#define ETH_MAC_A1HR_MB_LBITS23_16                  ((uint32_t)0x04000000)  /* Low register bits [23:16] */
#define ETH_MAC_A1HR_MB_LBITS15_8                   ((uint32_t)0x02000000)  /* Low register bits [15:8] */
#define ETH_MAC_A1HR_MB_LBITS7_0                    ((uint32_t)0x01000000)  /* Low register bits [7:0] */ 
#define ETH_MAC_A1HR_ADDR1H                         ((uint32_t)0x0000FFFF)  /* MAC address1 high */
  
/* Bit definition for Ethernet MAC Address1 Low Register */
#define ETH_MAC_A1LR_ADDR1L                         ((uint32_t)0xFFFFFFFF)  /* MAC address1 low */
  
/* Bit definition for Ethernet MAC Address2 High Register */
#define ETH_MAC_A2HR_AFE                            ((uint32_t)0x80000000)  /* Address filter enable */
#define ETH_MAC_A2HR_SAF                            ((uint32_t)0x40000000)  /* Source address filter */
#define ETH_MAC_A2HR_MB                             ((uint32_t)0x3F000000)  /* Mask byte control */
#define ETH_MAC_A2HR_MB_HBITS15_8                   ((uint32_t)0x20000000)  /* High register bits [15:8] */
#define ETH_MAC_A2HR_MB_HBITS7_0                    ((uint32_t)0x10000000)  /* High register bits [7:0] */
#define ETH_MAC_A2HR_MB_LBITS31_24                  ((uint32_t)0x08000000)  /* Low register bits [31:24] */
#define ETH_MAC_A2HR_MB_LBITS23_16                  ((uint32_t)0x04000000)  /* Low register bits [23:16] */
#define ETH_MAC_A2HR_MB_LBITS15_8                   ((uint32_t)0x02000000)  /* Low register bits [15:8] */
#define ETH_MAC_A2HR_MB_LBITS7_0                    ((uint32_t)0x01000000)  /* Low register bits [7:0] */
#define ETH_MAC_A2HR_ADDR2H                         ((uint32_t)0x0000FFFF)  /* MAC address2 high */
  
/* Bit definition for Ethernet MAC Address2 Low Register */
#define ETH_MAC_A2LR_ADDR2L                         ((uint32_t)0xFFFFFFFF)  /* MAC address2 low */
  
/* Bit definition for Ethernet MAC Address3 High Register */
#define ETH_MAC_A3HR_AFE                            ((uint32_t)0x80000000)  /* Address filter enable */
#define ETH_MAC_A3HR_SAF                            ((uint32_t)0x40000000)  /* Source address filter */
#define ETH_MAC_A3HR_MB                             ((uint32_t)0x3F000000)  /* Mask byte control */
#define ETH_MAC_A3HR_MB_HBITS15_8                   ((uint32_t)0x20000000)  /* High register bits [15:8] */
#define ETH_MAC_A3HR_MB_HBITS7_0                    ((uint32_t)0x10000000)  /* High register bits [7:0] */
#define ETH_MAC_A3HR_MB_LBITS31_24                  ((uint32_t)0x08000000)  /* Low register bits [31:24] */
#define ETH_MAC_A3HR_MB_LBITS23_16                  ((uint32_t)0x04000000)  /* Low register bits [23:16] */
#define ETH_MAC_A3HR_MB_LBITS15_8                   ((uint32_t)0x02000000)  /* Low register bits [15:8] */
#define ETH_MAC_A3HR_MB_LBITS7_0                    ((uint32_t)0x01000000)  /* Low register bits [7:0] */
#define ETH_MAC_A3HR_ADDR3H                         ((uint32_t)0x0000FFFF)  /* MAC address3 high */
  											    
/* Bit definition for Ethernet MAC Address3 Low Register */
#define ETH_MAC_A3LR_ADDR3L                         ((uint32_t)0xFFFFFFFF)  /* MAC address3 low */
  
/* Bit definition for Ethernet MAC Flow Control threshold Register */
#define ETH_MAC_FCTHR_RFD                           ((uint32_t)0x00000070)  /* Threshold of deactive flow control */
#define ETH_MAC_FCTHR_RFD_256BYTES                  ((uint32_t)0x00000000)  /* Threshold level is 256 bytes */
#define ETH_MAC_FCTHR_RFD_512BYTES                  ((uint32_t)0x00000010)  /* Threshold level is 512 bytes */
#define ETH_MAC_FCTHR_RFD_768BYTES                  ((uint32_t)0x00000020)  /* Threshold level is 768 bytes */
#define ETH_MAC_FCTHR_RFD_1024BYTES                 ((uint32_t)0x00000030)  /* Threshold level is 1024 bytes */
#define ETH_MAC_FCTHR_RFD_1280BYTES                 ((uint32_t)0x00000040)  /* Threshold level is 1280 bytes */
#define ETH_MAC_FCTHR_RFD_1536BYTES                 ((uint32_t)0x00000050)  /* Threshold level is 1536 bytes */
#define ETH_MAC_FCTHR_RFD_1792BYTES                 ((uint32_t)0x00000060)  /* Threshold level is 1792 bytes */
#define ETH_MAC_FCTHR_RFA                           ((uint32_t)0x00000007)  /* Threshold of active flow control */
#define ETH_MAC_FCTHR_RFA_256BYTES                  ((uint32_t)0x00000000)  /* Threshold level is 256 bytes */
#define ETH_MAC_FCTHR_RFA_512BYTES                  ((uint32_t)0x00000001)  /* Threshold level is 512 bytes */
#define ETH_MAC_FCTHR_RFA_768BYTES                  ((uint32_t)0x00000002)  /* Threshold level is 768 bytes */
#define ETH_MAC_FCTHR_RFA_1024BYTES                 ((uint32_t)0x00000003)  /* Threshold level is 1024 bytes */
#define ETH_MAC_FCTHR_RFA_1280BYTES                 ((uint32_t)0x00000004)  /* Threshold level is 1280 bytes */
#define ETH_MAC_FCTHR_RFA_1536BYTES                 ((uint32_t)0x00000005)  /* Threshold level is 1536 bytes */
#define ETH_MAC_FCTHR_RFA_1792BYTES                 ((uint32_t)0x00000006)  /* Threshold level is 1792 bytes */
/******************************************************************************/
/*                Ethernet MSC Registers bits definition                        */
/******************************************************************************/
  
/* Bit definition for Ethernet MSC Contol Register */
#define ETH_MSC_CTLR_MCFZ                           ((uint32_t)0x00000008)  /* MSC Counter Freeze */
#define ETH_MSC_CTLR_RTOR                           ((uint32_t)0x00000004)  /* Reset on Read */
#define ETH_MSC_CTLR_CTSR                           ((uint32_t)0x00000002)  /* Counter Stop Rollover */
#define ETH_MSC_CTLR_CTR                            ((uint32_t)0x00000001)  /* Counters Reset */
  								    
/* Bit definition for Ethernet MSC Receive Interrupt Status Register */
#define ETH_MSC_RISR_RGUF                           ((uint32_t)0x00020000)  /* receive good unicast frames counter reaches half the maximum value */
#define ETH_MSC_RISR_RFAE                           ((uint32_t)0x00000040)  /* receive alignment error counter reaches half the maximum value */
#define ETH_MSC_RISR_RFCE                           ((uint32_t)0x00000020)  /* receive crc error counter reaches half the maximum value */
  
/* Bit definition for Ethernet MSC Transmit Interrupt Status Register */
#define ETH_MSC_TISR_TGF                            ((uint32_t)0x00200000)  /* Transmit good frame count counter reaches half the maximum value */
#define ETH_MSC_TISR_TGFMSC                         ((uint32_t)0x00008000)  /* Transmit good multi col counter reaches half the maximum value */
#define ETH_MSC_TISR_TGFSC                          ((uint32_t)0x00004000)  /* Transmit good single col counter reaches half the maximum value */
  										  
/* Bit definition for Ethernet MSC Receive Interrupt Mask Register */
#define ETH_MSC_RIMR_RGUFIM                         ((uint32_t)0x00020000)  /* RGUF interrupt Mask */
#define ETH_MSC_RIMR_RFAEIM                         ((uint32_t)0x00000040)  /* RFAE interrupt Mask */
#define ETH_MSC_RIMR_RFCEIM                         ((uint32_t)0x00000020)  /* RFCE interrupt Mask */
  
  /* Bit definition for Ethernet MSC Transmit Interrupt Mask Register */
#define ETH_MSC_TIMR_TGFIM                          ((uint32_t)0x00200000)  /* TGF interrupt Mask */
#define ETH_MSC_TIMR_TGFMSCIM                       ((uint32_t)0x00008000)  /* TGFMSC interrupt Mask */
#define ETH_MSC_TIMR_TGFSCIM                        ((uint32_t)0x00004000)  /* TGFSC interrupt Mask */
  
/* Bit definition for Ethernet MSC Transmitted Good Frames after Single Collision Counter Register */
#define ETH_MSC_SCCNT_SCC                           ((uint32_t)0xFFFFFFFF)  /* Transmitted good frames single collision counter */
  
/* Bit definition for Ethernet MSC Transmitted Good Frames after More than a Single Collision Counter Register */
#define ETH_MSC_MSCCNT_MSCC                         ((uint32_t)0xFFFFFFFF)  /* Transmitted good frames after more single collision counter */
  
/* Bit definition for Ethernet MSC Transmitted Good Frames Counter Register */
#define ETH_MSC_TGFCNT_TGF                          ((uint32_t)0xFFFFFFFF)  /* Transmitted good frames counter */
  
/* Bit definition for Ethernet MSC Received Frames with CRC Error Counter Register */
#define ETH_MSC_RFCECNT_RFCER                       ((uint32_t)0xFFFFFFFF)  /* Received frames CRC error counter */
  
/* Bit definition for Ethernet MSC Received Frames with Alignement Error Counter Register */
#define ETH_MSC_RFAECNT_RFAER                       ((uint32_t)0xFFFFFFFF)  /* Received frames alignment error counter */
  
/* Bit definition for Ethernet MSC Received Good Unicast Frames Counter Register */
#define ETH_MSC_RGUFCNT_RGUF                        ((uint32_t)0xFFFFFFFF)  /* Received good unicast frames counter */
  
/******************************************************************************/
/*               Ethernet PTP Registers bits definition                        */
/******************************************************************************/
  
/* Bit definition for Ethernet PTP Time Stamp Contol Register */
#define ETH_PTP_TSCTLR_TMSARU                       ((uint32_t)0x00000020)  /* Time stamp addend register update */
#define ETH_PTP_TSCTLR_TMSITEN                      ((uint32_t)0x00000010)  /* Time stamp interrupt trigger enable */
#define ETH_PTP_TSCTLR_TMSSTU                       ((uint32_t)0x00000008)  /* Time stamp system time update */
#define ETH_PTP_TSCTLR_TMSSTI                       ((uint32_t)0x00000004)  /* Time stamp system time initialize */
#define ETH_PTP_TSCTLR_TMSFCU                       ((uint32_t)0x00000002)  /* Time stamp fine or coarse update */
#define ETH_PTP_TSCTLR_TMSEN                        ((uint32_t)0x00000001)  /* Time stamp enable */
  
/* Bit definition for Ethernet PTP Sub-Second Increment Register */
#define ETH_PTP_SSINCR_STMSSI                       ((uint32_t)0x000000FF)  /* System time Subsecond increment */
  
/* Bit definition for Ethernet PTP Time Stamp High Register */
#define ETH_PTP_TMSHR_STMS                          ((uint32_t)0xFFFFFFFF)  /* System Time second */
  
/* Bit definition for Ethernet PTP Time Stamp Low Register */
#define ETH_PTP_TMSLR_STS                           ((uint32_t)0x80000000)  /* System Time Positive or negative time */
#define ETH_PTP_TMSLR_STMSS                         ((uint32_t)0x7FFFFFFF)  /* System Time subseconds */
  
/* Bit definition for Ethernet PTP Time Stamp High Update Register */
#define ETH_PTP_TMSHUR_TMSUS                        ((uint32_t)0xFFFFFFFF)  /* Time stamp update seconds */
  
/* Bit definition for Ethernet PTP Time Stamp Low Update Register */
#define ETH_PTP_TMSLUR_TMSUPNS                      ((uint32_t)0x80000000)  /* Time stamp update Positive or negative time */
#define ETH_PTP_TMSLUR_TMSUSS                       ((uint32_t)0x7FFFFFFF)  /* Time stamp update subseconds */
  										    
/* Bit definition for Ethernet PTP Time Stamp Addend Register */
#define ETH_PTP_TSACNT_TMSA                         ((uint32_t)0xFFFFFFFF)  /* Time stamp addend */
  
/* Bit definition for Ethernet PTP Expected Time High Register */
#define ETH_PTP_ETHR_ETSH                           ((uint32_t)0xFFFFFFFF)  /* Expected time stamp high */
  
/* Bit definition for Ethernet PTP Expected Time Low Register */
#define ETH_PTP_ETLR_ETSL                           ((uint32_t)0xFFFFFFFF)  /* Expected time stamp low */
  
/******************************************************************************/
/*                 Ethernet DMA Registers bits definition                     */
/******************************************************************************/
  
/* Bit definition for Ethernet DMA Bus Control Register */
#define ETH_DMA_BCR_AA                              ((uint32_t)0x02000000)  /* Address-aligned */
#define ETH_DMA_BCR_FPBL                            ((uint32_t)0x01000000)  /* four x PBL mode */
#define ETH_DMA_BCR_UIP                             ((uint32_t)0x00800000)  /* Use Independent PBL */
#define ETH_DMA_BCR_RXDP                            ((uint32_t)0x007E0000)  /* receive DMA PBL */
#define ETH_DMA_BCR_RXDP_1BEAT                      ((uint32_t)0x00020000)  /* maximum number of beats 1 */
#define ETH_DMA_BCR_RXDP_2BEAT                      ((uint32_t)0x00040000)  /* maximum number of beats 2 */
#define ETH_DMA_BCR_RXDP_4BEAT                      ((uint32_t)0x00080000)  /* maximum number of beats 4 */
#define ETH_DMA_BCR_RXDP_8BEAT                      ((uint32_t)0x00100000)  /* maximum number of beats 8 */
#define ETH_DMA_BCR_RXDP_16BEAT                     ((uint32_t)0x00200000)  /* maximum number of beats 16 */
#define ETH_DMA_BCR_RXDP_32BEAT                     ((uint32_t)0x00400000)  /* maximum number of beats 32 */                
#define ETH_DMA_BCR_RXDP_4xPBL_4BEAT                ((uint32_t)0x01020000)  /* maximum number of beats 4 */
#define ETH_DMA_BCR_RXDP_4xPBL_8BEAT                ((uint32_t)0x01040000)  /* maximum number of beats 8 */
#define ETH_DMA_BCR_RXDP_4xPBL_16BEAT               ((uint32_t)0x01080000)  /* maximum number of beats 16 */
#define ETH_DMA_BCR_RXDP_4xPBL_32BEAT               ((uint32_t)0x01100000)  /* maximum number of beats 32 */
#define ETH_DMA_BCR_RXDP_4xPBL_64BEAT               ((uint32_t)0x01200000)  /* maximum number of beats 64 */
#define ETH_DMA_BCR_RXDP_4xPBL_128BEAT              ((uint32_t)0x01400000)  /* maximum number of beats 128 */  
#define ETH_DMA_BCR_FB                              ((uint32_t)0x00010000)  /* Fixed Burst */
#define ETH_DMA_BCR_RTPR                            ((uint32_t)0x0000C000)  /* receive and transmit priority ratio */
#define ETH_DMA_BCR_RTPR_1_1                        ((uint32_t)0x00000000)  /* receive and transmit priority ratio */
#define ETH_DMA_BCR_RTPR_2_1                        ((uint32_t)0x00004000)  /* receive and transmit priority ratio */
#define ETH_DMA_BCR_RTPR_3_1                        ((uint32_t)0x00008000)  /* receive and transmit priority ratio */
#define ETH_DMA_BCR_RTPR_4_1                        ((uint32_t)0x0000C000)  /* receive and transmit priority ratio */  
#define ETH_DMA_BCR_PGBL                            ((uint32_t)0x00003F00)  /* Programmable burst length */
#define ETH_DMA_BCR_PBL_1BEAT                       ((uint32_t)0x00000100)  /* maximum number of beats is 1 */
#define ETH_DMA_BCR_PBL_2BEAT                       ((uint32_t)0x00000200)  /* maximum number of beats is 2 */
#define ETH_DMA_BCR_PBL_4BEAT                       ((uint32_t)0x00000400)  /* maximum number of beats is 4 */
#define ETH_DMA_BCR_PBL_8BEAT                       ((uint32_t)0x00000800)  /* maximum number of beats is 8 */
#define ETH_DMA_BCR_PBL_16BEAT                      ((uint32_t)0x00001000)  /* maximum number of beats is 16 */
#define ETH_DMA_BCR_PBL_32BEAT                      ((uint32_t)0x00002000)  /* maximum number of beats is 32 */                
#define ETH_DMA_BCR_PBL_4xPBL_4BEAT                 ((uint32_t)0x01000100)  /* maximum number of beats is 4 */
#define ETH_DMA_BCR_PBL_4xPBL_8BEAT                 ((uint32_t)0x01000200)  /* maximum number of beats is 8 */
#define ETH_DMA_BCR_PBL_4xPBL_16BEAT                ((uint32_t)0x01000400)  /* maximum number of beats is 16 */
#define ETH_DMA_BCR_PBL_4xPBL_32BEAT                ((uint32_t)0x01000800)  /* maximum number of beats is 32 */
#define ETH_DMA_BCR_PBL_4xPBL_64BEAT                ((uint32_t)0x01001000)  /* maximum number of beats is 64 */
#define ETH_DMA_BCR_PBL_4xPBL_128BEAT               ((uint32_t)0x01002000)  /* maximum number of beats is 128 */
#define ETH_DMA_BCR_DPSL                            ((uint32_t)0x0000007C)  /* Descriptor Skip Length */
#define ETH_DMA_BCR_DAB                             ((uint32_t)0x00000002)  /* DMA arbitration */
#define ETH_DMA_BCR_SWR                             ((uint32_t)0x00000001)  /* Software reset */
  
/* Bit definition for Ethernet DMA Transmit Poll Enable Register */
#define ETH_DMA_TPER_TPE                            ((uint32_t)0xFFFFFFFF)  /* Transmit poll enable */
  
/* Bit definition for Ethernet DMA Receive Poll Enable Register */
#define ETH_DMA_RPER_RPE                            ((uint32_t)0xFFFFFFFF)  /* Receive poll enable  */
  										   
/* Bit definition for Ethernet DMA Receive Descriptor Tab Address Register */
#define ETH_DMA_RDTAR_SRT                           ((uint32_t)0xFFFFFFFF)  /* Start of receive tab */
  
/* Bit definition for Ethernet DMA Transmit Descriptor Tab Address Register */
#define ETH_DMA_TDTAR_STT                           ((uint32_t)0xFFFFFFFF)  /* Start of transmit tab */
  
/* Bit definition for Ethernet DMA Status Register */
#define ETH_DMA_STR_TST                             ((uint32_t)0x20000000)  /* Time-stamp trigger status */
#define ETH_DMA_STR_WUM                             ((uint32_t)0x10000000)  /* WUM status */
#define ETH_DMA_STR_MSC                             ((uint32_t)0x08000000)  /* MSC status */
#define ETH_DMA_STR_EB                              ((uint32_t)0x03800000)  /* Error bits status */
/* combination with EB[2:0] for GetBitState function */
#define ETH_DMA_STR_EB_DESCACCESS                   ((uint32_t)0x02000000)  /* Error during descriptor or buffer access */
#define ETH_DMA_STR_EB_READTRANSF                   ((uint32_t)0x01000000)  /* Error during write trnsf of read transfr */
#define ETH_DMA_STR_EB_DATATRANSFTX                 ((uint32_t)0x00800000)  /* Error during data transfer by TxDMA or RxDMA */
#define ETH_DMA_STR_TP                              ((uint32_t)0x00700000)  /* Transmit process state */
#define ETH_DMA_STR_TP_STOPPED                      ((uint32_t)0x00000000)  /* Reset or Stop Tx Command issued  */
#define ETH_DMA_STR_TP_FETCHING                     ((uint32_t)0x00100000)  /* fetching the Tx descriptor */
#define ETH_DMA_STR_TP_WAITING                      ((uint32_t)0x00200000)  /* waiting for status */
#define ETH_DMA_STR_TP_READING                      ((uint32_t)0x00300000)  /* reading the data from host memory buffer and queuing it to transmit buffer */
#define ETH_DMA_STR_TP_SUSPENDED                    ((uint32_t)0x00600000)  /* Tx Descriptor unavailabe or transmit buffer underflow */
#define ETH_DMA_STR_TP_CLOSING                      ((uint32_t)0x00700000)  /* closing Tx descriptor */
#define ETH_DMA_STR_RP                              ((uint32_t)0x000E0000)  /* Receive process state */
#define ETH_DMA_STR_RP_STOPPED                      ((uint32_t)0x00000000)  /* Reset or Stop Rx Command issued */
#define ETH_DMA_STR_RP_FETCHING                     ((uint32_t)0x00020000)  /* fetching the Rx descriptor */
#define ETH_DMA_STR_RP_WAITING                      ((uint32_t)0x00060000)  /* waiting for receive packet */
#define ETH_DMA_STR_RP_SUSPENDED                    ((uint32_t)0x00080000)  /* Rx Descriptor unavailable */
#define ETH_DMA_STR_RP_CLOSING                      ((uint32_t)0x000A0000)  /* closing receive descriptor */
#define ETH_DMA_STR_RP_QUEUING                      ((uint32_t)0x000E0000)  /* transferring the receive packet data from recevie buffer to host memory */
#define ETH_DMA_STR_NI                              ((uint32_t)0x00010000)  /* Normal interrupt summary */
#define ETH_DMA_STR_AI                              ((uint32_t)0x00008000)  /* Abnormal interrupt summary */
#define ETH_DMA_STR_ER                              ((uint32_t)0x00004000)  /* Early receive status */
#define ETH_DMA_STR_FBE                             ((uint32_t)0x00002000)  /* Fatal bus error status */
#define ETH_DMA_STR_ET                              ((uint32_t)0x00000400)  /* Early transmit status */
#define ETH_DMA_STR_RWT                             ((uint32_t)0x00000200)  /* Receive watchdog timeout status */
#define ETH_DMA_STR_RPS                             ((uint32_t)0x00000100)  /* Receive process stopped status */
#define ETH_DMA_STR_RBU                             ((uint32_t)0x00000080)  /* Receive buffer unavailable status */
#define ETH_DMA_STR_RS                              ((uint32_t)0x00000040)  /* Receive status */
#define ETH_DMA_STR_TU                              ((uint32_t)0x00000020)  /* Transmit underflow status */
#define ETH_DMA_STR_RO                              ((uint32_t)0x00000010)  /* Receive overflow status */
#define ETH_DMA_STR_TJT                             ((uint32_t)0x00000008)  /* Transmit jabber timeout status */
#define ETH_DMA_STR_TBU                             ((uint32_t)0x00000004)  /* Transmit buffer unavailable status */
#define ETH_DMA_STR_TPS                             ((uint32_t)0x00000002)  /* Transmit process stopped status */
#define ETH_DMA_STR_TS                              ((uint32_t)0x00000001)  /* Transmit status */
 
/* Bit definition for Ethernet DMA Control Register */
#define ETH_DMA_CTLR_DTCERFD                        ((uint32_t)0x04000000)  /* Dropping of TCP/IP checksum error frames disable */
#define ETH_DMA_CTLR_RSFD                           ((uint32_t)0x02000000)  /* Receive store and forward */
#define ETH_DMA_CTLR_DAFRF                          ((uint32_t)0x01000000)  /* Disable flushing of received frames */
#define ETH_DMA_CTLR_TSFD                           ((uint32_t)0x00200000)  /* Transmit store and forward */
#define ETH_DMA_CTLR_FTF                            ((uint32_t)0x00100000)  /* Flush transmit FIFO */
#define ETH_DMA_CTLR_TTHC                           ((uint32_t)0x0001C000)  /* Transmit threshold control */
#define ETH_DMAOMR_TTHC_64BYTES                     ((uint32_t)0x00000000)  /* threshold level is 64 Bytes */
#define ETH_DMAOMR_TTHC_128BYTES                    ((uint32_t)0x00004000)  /* threshold level is 128 Bytes */
#define ETH_DMAOMR_TTHC_192BYTES                    ((uint32_t)0x00008000)  /* threshold level is 192 Bytes */
#define ETH_DMAOMR_TTHC_256BYTES                    ((uint32_t)0x0000C000)  /* threshold level is 256 Bytes */
#define ETH_DMAOMR_TTHC_40BYTES                     ((uint32_t)0x00010000)  /* threshold level is 40 Bytes */
#define ETH_DMAOMR_TTHC_32BYTES                     ((uint32_t)0x00014000)  /* threshold level is 32 Bytes */
#define ETH_DMAOMR_TTHC_24BYTES                     ((uint32_t)0x00018000)  /* threshold level is 24 Bytes */
#define ETH_DMAOMR_TTHC_16BYTES                     ((uint32_t)0x0001C000)  /* threshold level is 16 Bytes */
#define ETH_DMA_CTLR_STE                            ((uint32_t)0x00002000)  /* Start/stop transmission */
#define ETH_DMA_CTLR_FERF                           ((uint32_t)0x00000080)  /* Forward error frames */
#define ETH_DMA_CTLR_FUF                            ((uint32_t)0x00000040)  /* Forward undersized good frames */
#define ETH_DMA_CTLR_RTHC                           ((uint32_t)0x00000018)  /* receive threshold control */
#define ETH_DMAOMR_RTHC_64BYTES                     ((uint32_t)0x00000000)  /* threshold level is 64 Bytes */
#define ETH_DMAOMR_RTHC_32BYTES                     ((uint32_t)0x00000008)  /* threshold level is 32 Bytes */
#define ETH_DMAOMR_RTHC_96BYTES                     ((uint32_t)0x00000010)  /* threshold level is 96 Bytes */
#define ETH_DMAOMR_RTHC_128BYTES                    ((uint32_t)0x00000018)  /* threshold level is 128 Bytes */
#define ETH_DMA_CTLR_OSF                            ((uint32_t)0x00000004)  /* operate on second frame */
#define ETH_DMA_CTLR_SRE                            ((uint32_t)0x00000002)  /* Start/stop receive */
  
/* Bit definition for Ethernet DMA Interrupt Enable Register */
#define ETH_DMA_IER_NISEN                           ((uint32_t)0x00010000)  /* Normal interrupt summary enable */
#define ETH_DMA_IER_AISEN                           ((uint32_t)0x00008000)  /* Abnormal interrupt summary enable */
#define ETH_DMA_IER_ERIEN                           ((uint32_t)0x00004000)  /* Early receive interrupt enable */
#define ETH_DMA_IER_FBEIEN                          ((uint32_t)0x00002000)  /* Fatal bus error interrupt enable */
#define ETH_DMA_IER_ETIEN                           ((uint32_t)0x00000400)  /* Early transmit interrupt enable */
#define ETH_DMA_IER_RWTIEN                          ((uint32_t)0x00000200)  /* Receive watchdog timeout interrupt enable */
#define ETH_DMA_IER_RPSIEN                          ((uint32_t)0x00000100)  /* Receive process stopped interrupt enable */
#define ETH_DMA_IER_RBUIEN                          ((uint32_t)0x00000080)  /* Receive buffer unavailable interrupt enable */
#define ETH_DMA_IER_RIEN                            ((uint32_t)0x00000040)  /* Receive interrupt enable */
#define ETH_DMA_IER_TUIEN                           ((uint32_t)0x00000020)  /* Transmit Underflow interrupt enable */
#define ETH_DMA_IER_ROIEN                           ((uint32_t)0x00000010)  /* Receive Overflow interrupt enable */
#define ETH_DMA_IER_TJTIEN                          ((uint32_t)0x00000008)  /* Transmit jabber timeout interrupt enable */
#define ETH_DMA_IER_TBUIEN                          ((uint32_t)0x00000004)  /* Transmit buffer unavailable interrupt enable */
#define ETH_DMA_IER_TPSIEN                          ((uint32_t)0x00000002)  /* Transmit process stopped interrupt enable */
#define ETH_DMA_IER_TIEN                            ((uint32_t)0x00000001)  /* Transmit interrupt enable */
  
/* Bit definition for Ethernet DMA Missed Frame and Buffer Overflow Counter Register */
#define ETH_DMA_MFBOCNT_OBFOC                       ((uint32_t)0x10000000)  /* Overflow bit for FIFO overflow counter */
#define ETH_DMA_MFBOCNT_MSFA                        ((uint32_t)0x0FFE0000)  /* Missed frames by the application */
#define ETH_DMA_MFBOCNT_OBMFC                       ((uint32_t)0x00010000)  /* Overflow bit for missed frame counter */
#define ETH_DMA_MFBOCNT_MSFC                        ((uint32_t)0x0000FFFF)  /* missed frames by the controller */
  									   
/* Bit definition for Ethernet DMA Current Transmit Descriptor Address Register */
#define ETH_DMA_CTDAR_TDAP                          ((uint32_t)0xFFFFFFFF)  /* Transmit descriptor address pointer */
  
/* Bit definition for Ethernet DMA Current Receive Descriptor Address Register */
#define ETH_DMA_CRDAR_RDAP                          ((uint32_t)0xFFFFFFFF)  /* Receive descriptor address pointer */
  
/* Bit definition for Ethernet DMA Current Transmit Buffer Address Register */
#define ETH_DMA_CTBAR_TBAP                          ((uint32_t)0xFFFFFFFF)  /* Transmit buffer address pointer */
  
/* Bit definition for Ethernet DMA Current Receive Buffer Address Register */
#define ETH_DMA_CRBAR_RBAP                          ((uint32_t)0xFFFFFFFF)  /* Receive buffer address pointer */
/******************************************************************************/
/*                                                                            */
/*                       External Memory Controller                           */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for EXMC_SCTLR1 register  *******************/
#define  EXMC_SCTLR1_BAKEN                          ((uint32_t)0x00000001)        /*!< Memory bank enable */
#define  EXMC_SCTLR1_MULEN                          ((uint32_t)0x00000002)        /*!< Address/data multiplexing enable */

#define  EXMC_SCTLR1_EMTYP                          ((uint32_t)0x0000000C)        /*!< EMTYP[1:0] bits (Memory type) */
#define  EXMC_SCTLR1_EMTYP_0                        ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  EXMC_SCTLR1_EMTYP_1                        ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  EXMC_SCTLR1_EMWID                          ((uint32_t)0x00000030)        /*!< EMWID[1:0] bits (Memory data bus width) */
#define  EXMC_SCTLR1_EMWID_0                        ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_SCTLR1_EMWID_1                        ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  EXMC_SCTLR1_NOREN                          ((uint32_t)0x00000040)        /*!< NOR Flash access enable */
#define  EXMC_SCTLR1_BMODEN                         ((uint32_t)0x00000100)        /*!< Synchronous burst mode enable */
#define  EXMC_SCTLR1_WSIGP                          ((uint32_t)0x00000200)        /*!< NWAIT signal polarity bit */
#define  EXMC_SCTLR1_WRAPEN                         ((uint32_t)0x00000400)        /*!< Wrapped burst mode enable */
#define  EXMC_SCTLR1_WSIGCFG                        ((uint32_t)0x00000800)        /*!< NWAIT signal timing configuration */
#define  EXMC_SCTLR1_WREN                           ((uint32_t)0x00001000)        /*!< Write enable */
#define  EXMC_SCTLR1_WSIGEN                         ((uint32_t)0x00002000)        /*!< NWAIT signal enable */
#define  EXMC_SCTLR1_EXMODEN                        ((uint32_t)0x00004000)        /*!< Extended mode enable */
#define  EXMC_SCTLR1_ASYNCWAIT                      ((uint32_t)0x00008000)        /*!< Asynchronous wait feature enable */
#define  EXMC_SCTLR1_WRMOD                          ((uint32_t)0x00080000)        /*!< write mode select */

/******************  Bit definition for EXMC_SCTLR2 register  *******************/
#define  EXMC_SCTLR2_BAKEN                          ((uint32_t)0x00000001)        /*!< Memory bank enable */
#define  EXMC_SCTLR2_MULEN                          ((uint32_t)0x00000002)        /*!< Address/data multiplexing enable */
							        
#define  EXMC_SCTLR2_EMTYP                          ((uint32_t)0x0000000C)        /*!< EMTYP[1:0] bits (Memory type) */
#define  EXMC_SCTLR2_EMTYP_0                        ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  EXMC_SCTLR2_EMTYP_1                        ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  EXMC_SCTLR2_EMWID                          ((uint32_t)0x00000030)        /*!< EMWID[1:0] bits (Memory data bus width) */
#define  EXMC_SCTLR2_EMWID_0                        ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_SCTLR2_EMWID_1                        ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  EXMC_SCTLR2_NOREN                          ((uint32_t)0x00000040)        /*!< NOR Flash access enable */
#define  EXMC_SCTLR2_BMODEN                         ((uint32_t)0x00000100)        /*!< Synchronous burst mode enable */
#define  EXMC_SCTLR2_WSIGP                          ((uint32_t)0x00000200)        /*!< NWAIT signal polarity */
#define  EXMC_SCTLR2_WRAPEN                         ((uint32_t)0x00000400)        /*!< Wrapped burst mode enable */
#define  EXMC_SCTLR2_WSIGCFG                        ((uint32_t)0x00000800)        /*!< NWAIT signal timing configuration */
#define  EXMC_SCTLR2_WREN                           ((uint32_t)0x00001000)        /*!< Write enable */
#define  EXMC_SCTLR2_WSIGEN                         ((uint32_t)0x00002000)        /*!< NWAIT signal enable */
#define  EXMC_SCTLR2_EXMODEN                        ((uint32_t)0x00004000)        /*!< Extended mode enable */
#define  EXMC_SCTLR2_ASYNCWAIT                      ((uint32_t)0x00008000)        /*!< Asynchronous wait feature enable */
#define  EXMC_SCTLR2_WRMOD                          ((uint32_t)0x00080000)        /*!< write mode select */

/******************  Bit definition for EXMC_SCTLR3 register  *******************/
#define  EXMC_SCTLR3_BAKEN                          ((uint32_t)0x00000001)        /*!< Memory bank enable */
#define  EXMC_SCTLR3_MULEN                          ((uint32_t)0x00000002)        /*!< Address/data multiplexing enable */

#define  EXMC_SCTLR3_EMTYP                          ((uint32_t)0x0000000C)        /*!< EMTYP[1:0] bits (Memory type) */
#define  EXMC_SCTLR3_EMTYP_0                        ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  EXMC_SCTLR3_EMTYP_1                        ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  EXMC_SCTLR3_EMWID                          ((uint32_t)0x00000030)        /*!< EMWID[1:0] bits (Memory data bus width) */
#define  EXMC_SCTLR3_EMWID_0                        ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_SCTLR3_EMWID_1                        ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  EXMC_SCTLR3_NOREN                          ((uint32_t)0x00000040)        /*!< NOR Flash access enable */
#define  EXMC_SCTLR3_BMODEN                         ((uint32_t)0x00000100)        /*!< Synchronous burst mode enable */
#define  EXMC_SCTLR3_WSIGP                          ((uint32_t)0x00000200)        /*!< NWAIT signal polarity */
#define  EXMC_SCTLR3_WRAPEN                         ((uint32_t)0x00000400)        /*!< Wrapped burst mode enable */
#define  EXMC_SCTLR3_WSIGCFG                        ((uint32_t)0x00000800)        /*!< NWAIT signal timing configuration */
#define  EXMC_SCTLR3_WREN                           ((uint32_t)0x00001000)        /*!< Write enable */
#define  EXMC_SCTLR3_WSIGEN                         ((uint32_t)0x00002000)        /*!< NWAIT signal enable */
#define  EXMC_SCTLR3_EXMODEN                        ((uint32_t)0x00004000)        /*!< Extended mode enable */
#define  EXMC_SCTLR3_ASYNCWAIT                      ((uint32_t)0x00008000)        /*!< Asynchronous wait feature enable */
#define  EXMC_SCTLR3_WRMOD                          ((uint32_t)0x00080000)        /*!< write mode select */

/******************  Bit definition for EXMC_SCTLR4 register  *******************/
#define  EXMC_SCTLR4_BAKEN                          ((uint32_t)0x00000001)        /*!< Memory bank enable */
#define  EXMC_SCTLR4_MULEN                          ((uint32_t)0x00000002)        /*!< Address/data multiplexing enable */

#define  EXMC_SCTLR4_EMTYP                          ((uint32_t)0x0000000C)        /*!< EMTYP[1:0] bits (Memory type) */
#define  EXMC_SCTLR4_EMTYP_0                        ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  EXMC_SCTLR4_EMTYP_1                        ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  EXMC_SCTLR4_EMWID                          ((uint32_t)0x00000030)        /*!< EMWID[1:0] bits (Memory data bus width) */
#define  EXMC_SCTLR4_EMWID_0                        ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_SCTLR4_EMWID_1                        ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  EXMC_SCTLR4_NOREN                          ((uint32_t)0x00000040)        /*!< NOR Flash access enable */
#define  EXMC_SCTLR4_BMODEN                         ((uint32_t)0x00000100)        /*!< Synchronous burst mode enable */
#define  EXMC_SCTLR4_WSIGP                          ((uint32_t)0x00000200)        /*!< NWAIT signal polarity */
#define  EXMC_SCTLR4_WRAPEN                         ((uint32_t)0x00000400)        /*!< Wrapped burst mode enable */
#define  EXMC_SCTLR4_WSIGCFG                        ((uint32_t)0x00000800)        /*!< NWAIT signal timing configuration */
#define  EXMC_SCTLR4_WREN                           ((uint32_t)0x00001000)        /*!< Write enable */
#define  EXMC_SCTLR4_WSIGEN                         ((uint32_t)0x00002000)        /*!< NWAIT signal enable */
#define  EXMC_SCTLR4_EXMODEN                        ((uint32_t)0x00004000)        /*!< Extended mode enable */
#define  EXMC_SCTLR4_ASYNCWAIT                      ((uint32_t)0x00008000)        /*!< Asynchronous wait feature enable */
#define  EXMC_SCTLR4_WRMOD                          ((uint32_t)0x00080000)        /*!< write mode select */

/******************  Bit definition for EXMC_STR1 register  ******************/
#define  EXMC_STR1_AST                              ((uint32_t)0x0000000F)        /*!< AST[3:0] bits (Address setup time) */
#define  EXMC_STR1_AST_0                            ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_STR1_AST_1                            ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_STR1_AST_2                            ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_STR1_AST_3                            ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  EXMC_STR1_AHT                              ((uint32_t)0x000000F0)        /*!< AHT[3:0] bits (Address hold time) */
#define  EXMC_STR1_AHT_0                            ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_STR1_AHT_1                            ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  EXMC_STR1_AHT_2                            ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  EXMC_STR1_AHT_3                            ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  EXMC_STR1_DST                              ((uint32_t)0x0000FF00)        /*!< DST [3:0] bits (Data setup time) */
#define  EXMC_STR1_DST_0                            ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_STR1_DST_1                            ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_STR1_DST_2                            ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_STR1_DST_3                            ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  EXMC_STR1_BUSLAT                           ((uint32_t)0x000F0000)        /*!< BUSLAT[3:0] bits (Bus latency) */
#define  EXMC_STR1_BUSLAT_0                         ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_STR1_BUSLAT_1                         ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_STR1_BUSLAT_2                         ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_STR1_BUSLAT_3                         ((uint32_t)0x00080000)        /*!< Bit 3 */

#define  EXMC_STR1_CDIV                             ((uint32_t)0x00F00000)        /*!< CDIV[3:0] bits (Synchronous clock divide ratio) */
#define  EXMC_STR1_CDIV_0                           ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  EXMC_STR1_CDIV_1                           ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  EXMC_STR1_CDIV_2                           ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  EXMC_STR1_CDIV_3                           ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  EXMC_STR1_DLAT                             ((uint32_t)0x0F000000)        /*!< DLAT[3:0] bits (Data latency for nor flash) */
#define  EXMC_STR1_DLAT_0                           ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_STR1_DLAT_1                           ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_STR1_DLAT_2                           ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_STR1_DLAT_3                           ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  EXMC_STR1_ASYNMOD                          ((uint32_t)0x30000000)        /*!< ASYNMOD[1:0] bits (Asynchronous access mode) */
#define  EXMC_STR1_ASYNMOD_0                        ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  EXMC_STR1_ASYNMOD_1                        ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for EXMC_STR2 register  *******************/
#define  EXMC_STR2_AST                              ((uint32_t)0x0000000F)        /*!< AST[3:0] bits (Address setup time) */
#define  EXMC_STR2_AST_0                            ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_STR2_AST_1                            ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_STR2_AST_2                            ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_STR2_AST_3                            ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  EXMC_STR2_AHT                              ((uint32_t)0x000000F0)        /*!< AHT[3:0] bits (Address hold time) */
#define  EXMC_STR2_AHT_0                            ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_STR2_AHT_1                            ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  EXMC_STR2_AHT_2                            ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  EXMC_STR2_AHT_3                            ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  EXMC_STR2_DST                              ((uint32_t)0x0000FF00)        /*!< DST [3:0] bits (Data setup time) */
#define  EXMC_STR2_DST_0                            ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_STR2_DST_1                            ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_STR2_DST_2                            ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_STR2_DST_3                            ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  EXMC_STR2_BUSLAT                           ((uint32_t)0x000F0000)        /*!< BUSLAT[3:0] bits (Bus latency) */
#define  EXMC_STR2_BUSLAT_0                         ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_STR2_BUSLAT_1                         ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_STR2_BUSLAT_2                         ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_STR2_BUSLAT_3                         ((uint32_t)0x00080000)        /*!< Bit 3 */

#define  EXMC_STR2_CDIV                             ((uint32_t)0x00F00000)        /*!< CDIV[3:0] bits (Synchronous clock divide ratio) */
#define  EXMC_STR2_CDIV_0                           ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  EXMC_STR2_CDIV_1                           ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  EXMC_STR2_CDIV_2                           ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  EXMC_STR2_CDIV_3                           ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  EXMC_STR2_DLAT                             ((uint32_t)0x0F000000)        /*!< DLAT[3:0] bits (Data latency for nor flash) */
#define  EXMC_STR2_DLAT_0                           ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_STR2_DLAT_1                           ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_STR2_DLAT_2                           ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_STR2_DLAT_3                           ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  EXMC_STR2_ASYNMOD                          ((uint32_t)0x30000000)        /*!< ASYNMOD[1:0] bits (Asynchronous access mode) */
#define  EXMC_STR2_ASYNMOD_0                        ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  EXMC_STR2_ASYNMOD_1                        ((uint32_t)0x20000000)        /*!< Bit 1 */

/*******************  Bit definition for EXMC_STR3 register  *******************/
#define  EXMC_STR3_AST                              ((uint32_t)0x0000000F)        /*!< AST[3:0] bits (Address setup time) */
#define  EXMC_STR3_AST_0                            ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_STR3_AST_1                            ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_STR3_AST_2                            ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_STR3_AST_3                            ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  EXMC_STR3_AHT                              ((uint32_t)0x000000F0)        /*!< AHT[3:0] bits (Address hold time) */
#define  EXMC_STR3_AHT_0                            ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_STR3_AHT_1                            ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  EXMC_STR3_AHT_2                            ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  EXMC_STR3_AHT_3                            ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  EXMC_STR3_DST                              ((uint32_t)0x0000FF00)        /*!< DST [3:0] bits (Data setup time) */
#define  EXMC_STR3_DST_0                            ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_STR3_DST_1                            ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_STR3_DST_2                            ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_STR3_DST_3                            ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  EXMC_STR3_BUSLAT                           ((uint32_t)0x000F0000)        /*!< BUSLAT[3:0] bits (Bus latency) */
#define  EXMC_STR3_BUSLAT_0                         ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_STR3_BUSLAT_1                         ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_STR3_BUSLAT_2                         ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_STR3_BUSLAT_3                         ((uint32_t)0x00080000)        /*!< Bit 3 */

#define  EXMC_STR3_CDIV                             ((uint32_t)0x00F00000)        /*!< CDIV[3:0] bits (Synchronous clock divide ratio) */
#define  EXMC_STR3_CDIV_0                           ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  EXMC_STR3_CDIV_1                           ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  EXMC_STR3_CDIV_2                           ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  EXMC_STR3_CDIV_3                           ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  EXMC_STR3_DLAT                             ((uint32_t)0x0F000000)        /*!< DLAT[3:0] bits (Data latency for nor flash) */
#define  EXMC_STR3_DLAT_0                           ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_STR3_DLAT_1                           ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_STR3_DLAT_2                           ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_STR3_DLAT_3                           ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  EXMC_STR3_ASYNMOD                          ((uint32_t)0x30000000)        /*!< ASYNMOD[1:0] bits (Asynchronous access mode) */
#define  EXMC_STR3_ASYNMOD_0                        ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  EXMC_STR3_ASYNMOD_1                        ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for EXMC_STR4 register  *******************/
#define  EXMC_STR4_AST                              ((uint32_t)0x0000000F)        /*!< AST[3:0] bits (Address setup time) */
#define  EXMC_STR4_AST_0                            ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_STR4_AST_1                            ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_STR4_AST_2                            ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_STR4_AST_3                            ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  EXMC_STR4_AHT                              ((uint32_t)0x000000F0)        /*!< AHT[3:0] bits (Address hold time) */
#define  EXMC_STR4_AHT_0                            ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_STR4_AHT_1                            ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  EXMC_STR4_AHT_2                            ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  EXMC_STR4_AHT_3                            ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  EXMC_STR4_DST                              ((uint32_t)0x0000FF00)        /*!< DST [3:0] bits (Data setup time) */
#define  EXMC_STR4_DST_0                            ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_STR4_DST_1                            ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_STR4_DST_2                            ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_STR4_DST_3                            ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  EXMC_STR4_BUSLAT                           ((uint32_t)0x000F0000)        /*!< BUSLAT[3:0] bits (Bus latency) */
#define  EXMC_STR4_BUSLAT_0                         ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_STR4_BUSLAT_1                         ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_STR4_BUSLAT_2                         ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_STR4_BUSLAT_3                         ((uint32_t)0x00080000)        /*!< Bit 3 */
								       
#define  EXMC_STR4_CDIV                             ((uint32_t)0x00F00000)        /*!< CDIV[3:0] bits (Synchronous clock divide ratio) */
#define  EXMC_STR4_CDIV_0                           ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  EXMC_STR4_CDIV_1                           ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  EXMC_STR4_CDIV_2                           ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  EXMC_STR4_CDIV_3                           ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  EXMC_STR4_DLAT                             ((uint32_t)0x0F000000)        /*!< DLAT[3:0] bits (Data latency for nor flash) */
#define  EXMC_STR4_DLAT_0                           ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_STR4_DLAT_1                           ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_STR4_DLAT_2                           ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_STR4_DLAT_3                           ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  EXMC_STR4_ASYNMOD                          ((uint32_t)0x30000000)        /*!< ASYNMOD[1:0] bits (Asynchronous access mode) */
#define  EXMC_STR4_ASYNMOD_0                        ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  EXMC_STR4_ASYNMOD_1                        ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for EXMC_SWTR1 register  ******************/
#define  EXMC_SWTR1_AST                             ((uint32_t)0x0000000F)        /*!< AST[3:0] bits (Address setup time) */
#define  EXMC_SWTR1_AST_0                           ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_SWTR1_AST_1                           ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_SWTR1_AST_2                           ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_SWTR1_AST_3                           ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  EXMC_SWTR1_AHT                             ((uint32_t)0x000000F0)        /*!< AHT[3:0] bits (Address hold time) */
#define  EXMC_SWTR1_AHT_0                           ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_SWTR1_AHT_1                           ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  EXMC_SWTR1_AHT_2                           ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  EXMC_SWTR1_AHT_3                           ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  EXMC_SWTR1_DST                             ((uint32_t)0x0000FF00)        /*!< DST [3:0] bits (Data setup time) */
#define  EXMC_SWTR1_DST_0                           ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_SWTR1_DST_1                           ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_SWTR1_DST_2                           ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_SWTR1_DST_3                           ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  EXMC_SWTR1_CDIV                            ((uint32_t)0x00F00000)        /*!< CDIV[3:0] bits (Synchronous clock divide ratio) */
#define  EXMC_SWTR1_CDIV_0                          ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  EXMC_SWTR1_CDIV_1                          ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  EXMC_SWTR1_CDIV_2                          ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  EXMC_SWTR1_CDIV_3                          ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  EXMC_SWTR1_DLAT                            ((uint32_t)0x0F000000)        /*!< DLAT[3:0] bits (Data latency for nor flash) */
#define  EXMC_SWTR1_DLAT_0                          ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_SWTR1_DLAT_1                          ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_SWTR1_DLAT_2                          ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_SWTR1_DLAT_3                          ((uint32_t)0x08000000)        /*!< Bit 3 */
								       
#define  EXMC_SWTR1_ASYNMOD                         ((uint32_t)0x30000000)        /*!< ASYNMOD[1:0] bits (Asynchronous access mode) */
#define  EXMC_SWTR1_ASYNMOD_0                       ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  EXMC_SWTR1_ASYNMOD_1                       ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for EXMC_SWTR2 register  ******************/
#define  EXMC_SWTR2_AST                             ((uint32_t)0x0000000F)        /*!< AST[3:0] bits (Address setup time) */
#define  EXMC_SWTR2_AST_0                           ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_SWTR2_AST_1                           ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_SWTR2_AST_2                           ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_SWTR2_AST_3                           ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  EXMC_SWTR2_AHT                             ((uint32_t)0x000000F0)        /*!< AHT[3:0] bits (Address hold time) */
#define  EXMC_SWTR2_AHT_0                           ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_SWTR2_AHT_1                           ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  EXMC_SWTR2_AHT_2                           ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  EXMC_SWTR2_AHT_3                           ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  EXMC_SWTR2_DST                             ((uint32_t)0x0000FF00)        /*!< DST [3:0] bits (Data setup time) */
#define  EXMC_SWTR2_DST_0                           ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_SWTR2_DST_1                           ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_SWTR2_DST_2                           ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_SWTR2_DST_3                           ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  EXMC_SWTR2_CDIV                            ((uint32_t)0x00F00000)        /*!< CDIV[3:0] bits (Synchronous clock divide ratio) */
#define  EXMC_SWTR2_CDIV_0                          ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  EXMC_SWTR2_CDIV_1                          ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  EXMC_SWTR2_CDIV_2                          ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  EXMC_SWTR2_CDIV_3                          ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  EXMC_SWTR2_DLAT                            ((uint32_t)0x0F000000)        /*!< DLAT[3:0] bits (Data latency for nor flash) */
#define  EXMC_SWTR2_DLAT_0                          ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_SWTR2_DLAT_1                          ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_SWTR2_DLAT_2                          ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_SWTR2_DLAT_3                          ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  EXMC_SWTR2_ASYNMOD                         ((uint32_t)0x30000000)        /*!< ASYNMOD[1:0] bits (Asynchronous access mode) */
#define  EXMC_SWTR2_ASYNMOD_0                       ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  EXMC_SWTR2_ASYNMOD_1                       ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for EXMC_SWTR3 register  ******************/
#define  EXMC_SWTR3_AST                             ((uint32_t)0x0000000F)        /*!< AST[3:0] bits (Address setup time) */
#define  EXMC_SWTR3_AST_0                           ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_SWTR3_AST_1                           ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_SWTR3_AST_2                           ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_SWTR3_AST_3                           ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  EXMC_SWTR3_AHT                             ((uint32_t)0x000000F0)        /*!< AHT[3:0] bits (Address hold time) */
#define  EXMC_SWTR3_AHT_0                           ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_SWTR3_AHT_1                           ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  EXMC_SWTR3_AHT_2                           ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  EXMC_SWTR3_AHT_3                           ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  EXMC_SWTR3_DST                             ((uint32_t)0x0000FF00)        /*!< DST [3:0] bits (Data setup time) */
#define  EXMC_SWTR3_DST_0                           ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_SWTR3_DST_1                           ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_SWTR3_DST_2                           ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_SWTR3_DST_3                           ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  EXMC_SWTR3_CDIV                            ((uint32_t)0x00F00000)        /*!< CDIV[3:0] bits (Synchronous clock divide ratio) */
#define  EXMC_SWTR3_CDIV_0                          ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  EXMC_SWTR3_CDIV_1                          ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  EXMC_SWTR3_CDIV_2                          ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  EXMC_SWTR3_CDIV_3                          ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  EXMC_SWTR3_DLAT                            ((uint32_t)0x0F000000)        /*!< DLAT[3:0] bits (Data latency for nor flash) */
#define  EXMC_SWTR3_DLAT_0                          ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_SWTR3_DLAT_1                          ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_SWTR3_DLAT_2                          ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_SWTR3_DLAT_3                          ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  EXMC_SWTR3_ASYNMOD                         ((uint32_t)0x30000000)        /*!< ASYNMOD[1:0] bits (Asynchronous access mode) */
#define  EXMC_SWTR3_ASYNMOD_0                       ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  EXMC_SWTR3_ASYNMOD_1                       ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for EXMC_SWTR4 register  ******************/
#define  EXMC_SWTR4_AST                             ((uint32_t)0x0000000F)        /*!< AST[3:0] bits (Address setup time) */
#define  EXMC_SWTR4_AST_0                           ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_SWTR4_AST_1                           ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_SWTR4_AST_2                           ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_SWTR4_AST_3                           ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  EXMC_SWTR4_AHT                             ((uint32_t)0x000000F0)        /*!< AHT[3:0] bits (Address hold time) */
#define  EXMC_SWTR4_AHT_0                           ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_SWTR4_AHT_1                           ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  EXMC_SWTR4_AHT_2                           ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  EXMC_SWTR4_AHT_3                           ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  EXMC_SWTR4_DST                             ((uint32_t)0x0000FF00)        /*!< DST [3:0] bits (Data setup time) */
#define  EXMC_SWTR4_DST_0                           ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_SWTR4_DST_1                           ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_SWTR4_DST_2                           ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_SWTR4_DST_3                           ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  EXMC_SWTR4_CDIV                            ((uint32_t)0x00F00000)        /*!< CDIV[3:0] bits (Synchronous clock divide ratio) */
#define  EXMC_SWTR4_CDIV_0                          ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  EXMC_SWTR4_CDIV_1                          ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  EXMC_SWTR4_CDIV_2                          ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  EXMC_SWTR4_CDIV_3                          ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  EXMC_SWTR4_DLAT                            ((uint32_t)0x0F000000)        /*!< DLAT[3:0] bits (Data latency for nor flash) */
#define  EXMC_SWTR4_DLAT_0                          ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_SWTR4_DLAT_1                          ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_SWTR4_DLAT_2                          ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_SWTR4_DLAT_3                          ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  EXMC_SWTR4_ASYNMOD                         ((uint32_t)0x30000000)        /*!< ASYNMOD[1:0] bits (Asynchronous access mode) */
#define  EXMC_SWTR4_ASYNMOD_0                       ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  EXMC_SWTR4_ASYNMOD_1                       ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for EXMC_CTLR2 register  *******************/
#define  EXMC_CTLR2_WSIGEN                          ((uint32_t)0x00000002)        /*!< Wait feature enable */
#define  EXMC_CTLR2_BAKEN                           ((uint32_t)0x00000004)        /*!< Memory bank enable */
#define  EXMC_CTLR2_EMTYP                           ((uint32_t)0x00000008)        /*!< Memory type */

#define  EXMC_CTLR2_EMWID                           ((uint32_t)0x00000030)        /*!< EMWID[1:0] bits (external memory databus width) */
#define  EXMC_CTLR2_EMWID_0                         ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  EXMC_CTLR2_EMWID_1                         ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  EXMC_CTLR2_ECCEN                           ((uint32_t)0x00000040)        /*!< ECC enable */

#define  EXMC_CTLR2_CTR                             ((uint32_t)0x00001E00)        /*!< CTR[3:0] bits (CLE to RE delay) */
#define  EXMC_CTLR2_CTR_0                           ((uint32_t)0x00000200)        /*!< Bit 0 */
#define  EXMC_CTLR2_CTR_1                           ((uint32_t)0x00000400)        /*!< Bit 1 */
#define  EXMC_CTLR2_CTR_2                           ((uint32_t)0x00000800)        /*!< Bit 2 */
#define  EXMC_CTLR2_CTR_3                           ((uint32_t)0x00001000)        /*!< Bit 3 */

#define  EXMC_CTLR2_ATR                             ((uint32_t)0x0001E000)        /*!< ATR[3:0] bits (ALE to RE delay) */
#define  EXMC_CTLR2_ATR_0                           ((uint32_t)0x00002000)        /*!< Bit 0 */
#define  EXMC_CTLR2_ATR_1                           ((uint32_t)0x00004000)        /*!< Bit 1 */
#define  EXMC_CTLR2_ATR_2                           ((uint32_t)0x00008000)        /*!< Bit 2 */
#define  EXMC_CTLR2_ATR_3                           ((uint32_t)0x00010000)        /*!< Bit 3 */

#define  EXMC_CTLR2_ECCSZ                           ((uint32_t)0x000E0000)        /*!< ECCSZ[1:0] bits (ECC size) */
#define  EXMC_CTLR2_ECCSZ_0                         ((uint32_t)0x00020000)        /*!< Bit 0 */
#define  EXMC_CTLR2_ECCSZ_1                         ((uint32_t)0x00040000)        /*!< Bit 1 */
#define  EXMC_CTLR2_ECCSZ_2                         ((uint32_t)0x00080000)        /*!< Bit 2 */

/******************  Bit definition for EXMC_CTLR3 register  *******************/
#define  EXMC_CTLR3_WSIGEN                          ((uint32_t)0x00000002)        /*!< Wait feature enable */                           
#define  EXMC_CTLR3_BAKEN                           ((uint32_t)0x00000004)        /*!< Memory bank enable */                            
#define  EXMC_CTLR3_EMTYP                           ((uint32_t)0x00000008)        /*!< Memory type */                                   
                                                                                                                                 
#define  EXMC_CTLR3_EMWID                           ((uint32_t)0x00000030)        /*!< EMWID[1:0] bits (external memory databus width) */
#define  EXMC_CTLR3_EMWID_0                         ((uint32_t)0x00000010)        /*!< Bit 0 */                                         
#define  EXMC_CTLR3_EMWID_1                         ((uint32_t)0x00000020)        /*!< Bit 1 */                                         
                                                                                                                                       
#define  EXMC_CTLR3_ECCEN                           ((uint32_t)0x00000040)        /*!< ECC enable */                                    
                                                                                                                                 
#define  EXMC_CTLR3_CTR                             ((uint32_t)0x00001E00)        /*!< CTR[3:0] bits (CLE to RE delay) */               
#define  EXMC_CTLR3_CTR_0                           ((uint32_t)0x00000200)        /*!< Bit 0 */                                         
#define  EXMC_CTLR3_CTR_1                           ((uint32_t)0x00000400)        /*!< Bit 1 */                                         
#define  EXMC_CTLR3_CTR_2                           ((uint32_t)0x00000800)        /*!< Bit 2 */                                         
#define  EXMC_CTLR3_CTR_3                           ((uint32_t)0x00001000)        /*!< Bit 3 */                                         
                                                                                                                                 
#define  EXMC_CTLR3_ATR                             ((uint32_t)0x0001E000)        /*!< ATR[3:0] bits (ALE to RE delay) */               
#define  EXMC_CTLR3_ATR_0                           ((uint32_t)0x00002000)        /*!< Bit 0 */                                         
#define  EXMC_CTLR3_ATR_1                           ((uint32_t)0x00004000)        /*!< Bit 1 */                                         
#define  EXMC_CTLR3_ATR_2                           ((uint32_t)0x00008000)        /*!< Bit 2 */                                         
#define  EXMC_CTLR3_ATR_3                           ((uint32_t)0x00010000)        /*!< Bit 3 */                                         
                                                                                                                                 
#define  EXMC_CTLR3_ECCSZ                           ((uint32_t)0x000E0000)        /*!< ECCSZ[1:0] bits (ECC size) */                    
#define  EXMC_CTLR3_ECCSZ_0                         ((uint32_t)0x00020000)        /*!< Bit 0 */                                         
#define  EXMC_CTLR3_ECCSZ_1                         ((uint32_t)0x00040000)        /*!< Bit 1 */                                         
#define  EXMC_CTLR3_ECCSZ_2                         ((uint32_t)0x00080000)        /*!< Bit 2 */                                         

/******************  Bit definition for EXMC_CTLR4 register  *******************/
#define  EXMC_CTLR4_WSIGEN                          ((uint32_t)0x00000002)        /*!< Wait feature enable */                           
#define  EXMC_CTLR4_BAKEN                           ((uint32_t)0x00000004)        /*!< Memory bank enable */                            
#define  EXMC_CTLR4_EMTYP                           ((uint32_t)0x00000008)        /*!< Memory type */                                   
                                                                                                                                 
#define  EXMC_CTLR4_EMWID                           ((uint32_t)0x00000030)        /*!< EMWID[1:0] bits (external memory databus width) */
#define  EXMC_CTLR4_EMWID_0                         ((uint32_t)0x00000010)        /*!< Bit 0 */                                         
#define  EXMC_CTLR4_EMWID_1                         ((uint32_t)0x00000020)        /*!< Bit 1 */                                         
                                                                                                                                
#define  EXMC_CTLR4_ECCEN                           ((uint32_t)0x00000040)        /*!< ECC enable */                                    
                                                                                                                                 
#define  EXMC_CTLR4_CTR                             ((uint32_t)0x00001E00)        /*!< CTR[3:0] bits (CLE to RE delay) */               
#define  EXMC_CTLR4_CTR_0                           ((uint32_t)0x00000200)        /*!< Bit 0 */                                         
#define  EXMC_CTLR4_CTR_1                           ((uint32_t)0x00000400)        /*!< Bit 1 */                                         
#define  EXMC_CTLR4_CTR_2                           ((uint32_t)0x00000800)        /*!< Bit 2 */                                         
#define  EXMC_CTLR4_CTR_3                           ((uint32_t)0x00001000)        /*!< Bit 3 */                                         
                                                                                                                                 
#define  EXMC_CTLR4_ATR                             ((uint32_t)0x0001E000)        /*!< ATR[3:0] bits (ALE to RE delay) */               
#define  EXMC_CTLR4_ATR_0                           ((uint32_t)0x00002000)        /*!< Bit 0 */                                         
#define  EXMC_CTLR4_ATR_1                           ((uint32_t)0x00004000)        /*!< Bit 1 */                                         
#define  EXMC_CTLR4_ATR_2                           ((uint32_t)0x00008000)        /*!< Bit 2 */                                         
#define  EXMC_CTLR4_ATR_3                           ((uint32_t)0x00010000)        /*!< Bit 3 */                                         
                                                                                                                                 
#define  EXMC_CTLR4_ECCSZ                           ((uint32_t)0x000E0000)        /*!< ECCSZ[1:0] bits (ECC size) */                    
#define  EXMC_CTLR4_ECCSZ_0                         ((uint32_t)0x00020000)        /*!< Bit 0 */                                         
#define  EXMC_CTLR4_ECCSZ_1                         ((uint32_t)0x00040000)        /*!< Bit 1 */                                         
#define  EXMC_CTLR4_ECCSZ_2                         ((uint32_t)0x00080000)        /*!< Bit 2 */                                         

/*******************  Bit definition for EXMC_SIR2 register  *******************/
#define  EXMC_SIR2_ITRS                             ((uint8_t)0x01)               /*!< Interrupt rising edge status */
#define  EXMC_SIR2_ITHS                             ((uint8_t)0x02)               /*!< Interrupt high-level status */
#define  EXMC_SIR2_ITFS                             ((uint8_t)0x04)               /*!< Interrupt falling edge status */
#define  EXMC_SIR2_ITREN                            ((uint8_t)0x08)               /*!< Interrupt rising edge detection Enable bit */
#define  EXMC_SIR2_ITHEN                            ((uint8_t)0x10)               /*!< Interrupt high level detection Enable bit */
#define  EXMC_SIR2_ITFEN                            ((uint8_t)0x20)               /*!< Interrupt falling edge detection Enable bit */
#define  EXMC_SIR2_FIFOE                            ((uint8_t)0x40)               /*!< FIFO empty flag */

/*******************  Bit definition for EXMC_SIR3 register  *******************/
#define  EXMC_SIR3_ITRS                             ((uint8_t)0x01)               /*!< Interrupt rising edge status */
#define  EXMC_SIR3_ITHS                             ((uint8_t)0x02)               /*!< Interrupt high-level status */
#define  EXMC_SIR3_ITFS                             ((uint8_t)0x04)               /*!< Interrupt falling edge status */
#define  EXMC_SIR3_ITREN                            ((uint8_t)0x08)               /*!< Interrupt rising edge detection Enable bit */
#define  EXMC_SIR3_ITHEN                            ((uint8_t)0x10)               /*!< Interrupt high level detection Enable bit */
#define  EXMC_SIR3_ITFEN                            ((uint8_t)0x20)               /*!< Interrupt falling edge detection Enable bit */
#define  EXMC_SIR3_FIFOE                            ((uint8_t)0x40)               /*!< FIFO empty flag */

/*******************  Bit definition for EXMC_SIR4 register  *******************/
#define  EXMC_SIR4_ITRS                             ((uint8_t)0x01)               /*!< Interrupt rising edge status */
#define  EXMC_SIR4_ITHS                             ((uint8_t)0x02)               /*!< Interrupt high-level status */
#define  EXMC_SIR4_ITFS                             ((uint8_t)0x04)               /*!< Interrupt falling edge status */
#define  EXMC_SIR4_ITREN                            ((uint8_t)0x08)               /*!< Interrupt rising edge detection Enable bit */
#define  EXMC_SIR4_ITHEN                            ((uint8_t)0x10)               /*!< Interrupt high level detection Enable bit */
#define  EXMC_SIR4_ITFEN                            ((uint8_t)0x20)               /*!< Interrupt falling edge detection Enable bit */
#define  EXMC_SIR4_FIFOE                            ((uint8_t)0x40)               /*!< FIFO empty flag */

/******************  Bit definition for EXMC_COMTR2 register  ******************/
#define  EXMC_COMTR2_COMST                          ((uint32_t)0x000000FF)        /*!< COMST[7:0] bits (Common memory 2 setup time) */
#define  EXMC_COMTR2_COMST_0                        ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_COMTR2_COMST_1                        ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_COMTR2_COMST_2                        ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_COMTR2_COMST_3                        ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  EXMC_COMTR2_COMST_4                        ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  EXMC_COMTR2_COMST_5                        ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  EXMC_COMTR2_COMST_6                        ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  EXMC_COMTR2_COMST_7                        ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  EXMC_COMTR2_COMWT                          ((uint32_t)0x0000FF00)        /*!< COMWT[7:0] bits (Common memory 2 wait time) */
#define  EXMC_COMTR2_COMWT_0                        ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_COMTR2_COMWT_1                        ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_COMTR2_COMWT_2                        ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_COMTR2_COMWT_3                        ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  EXMC_COMTR2_COMWT_4                        ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  EXMC_COMTR2_COMWT_5                        ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  EXMC_COMTR2_COMWT_6                        ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  EXMC_COMTR2_COMWT_7                        ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  EXMC_COMTR2_COMHT                          ((uint32_t)0x00FF0000)        /*!< COMHT[7:0] bits (Common memory 2 hold time) */
#define  EXMC_COMTR2_COMHT_0                        ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_COMTR2_COMHT_1                        ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_COMTR2_COMHT_2                        ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_COMTR2_COMHT_3                        ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  EXMC_COMTR2_COMHT_4                        ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  EXMC_COMTR2_COMHT_5                        ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  EXMC_COMTR2_COMHT_6                        ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  EXMC_COMTR2_COMHT_7                        ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  EXMC_COMTR2_COMHIZT                        ((uint32_t)0xFF000000)        /*!< COMHIZ[7:0] bits (Common memory 2 databus HiZ time) */
#define  EXMC_COMTR2_COMHIZT_0                      ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_COMTR2_COMHIZT_1                      ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_COMTR2_COMHIZT_2                      ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_COMTR2_COMHIZT_3                      ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  EXMC_COMTR2_COMHIZT_4                      ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  EXMC_COMTR2_COMHIZT_5                      ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  EXMC_COMTR2_COMHIZT_6                      ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  EXMC_COMTR2_COMHIZT_7                      ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for EXMC_COMTR3 register  ******************/
#define  EXMC_COMTR3_COMST                          ((uint32_t)0x000000FF)        /*!< COMST[7:0] bits (Common memory 3 setup time) */
#define  EXMC_COMTR3_COMST_0                        ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_COMTR3_COMST_1                        ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_COMTR3_COMST_2                        ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_COMTR3_COMST_3                        ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  EXMC_COMTR3_COMST_4                        ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  EXMC_COMTR3_COMST_5                        ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  EXMC_COMTR3_COMST_6                        ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  EXMC_COMTR3_COMST_7                        ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  EXMC_COMTR3_COMWT                          ((uint32_t)0x0000FF00)        /*!< COMWT[7:0] bits (Common memory 3 wait time) */
#define  EXMC_COMTR3_COMWT_0                        ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_COMTR3_COMWT_1                        ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_COMTR3_COMWT_2                        ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_COMTR3_COMWT_3                        ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  EXMC_COMTR3_COMWT_4                        ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  EXMC_COMTR3_COMWT_5                        ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  EXMC_COMTR3_COMWT_6                        ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  EXMC_COMTR3_COMWT_7                        ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  EXMC_COMTR3_COMHT                          ((uint32_t)0x00FF0000)        /*!< COMHT[7:0] bits (Common memory 3 hold time) */
#define  EXMC_COMTR3_COMHT_0                        ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_COMTR3_COMHT_1                        ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_COMTR3_COMHT_2                        ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_COMTR3_COMHT_3                        ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  EXMC_COMTR3_COMHT_4                        ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  EXMC_COMTR3_COMHT_5                        ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  EXMC_COMTR3_COMHT_6                        ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  EXMC_COMTR3_COMHT_7                        ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  EXMC_COMTR3_COMHIZT                        ((uint32_t)0xFF000000)        /*!< COMHIZ[7:0] bits (Common memory 3 databus HiZ time) */
#define  EXMC_COMTR3_COMHIZT_0                      ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_COMTR3_COMHIZT_1                      ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_COMTR3_COMHIZT_2                      ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_COMTR3_COMHIZT_3                      ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  EXMC_COMTR3_COMHIZT_4                      ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  EXMC_COMTR3_COMHIZT_5                      ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  EXMC_COMTR3_COMHIZT_6                      ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  EXMC_COMTR3_COMHIZT_7                      ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for EXMC_COMTR4 register  ******************/
#define  EXMC_COMTR4_COMST                          ((uint32_t)0x000000FF)        /*!< COMST[7:0] bits (Common memory 4 setup time) */
#define  EXMC_COMTR4_COMST_0                        ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_COMTR4_COMST_1                        ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_COMTR4_COMST_2                        ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_COMTR4_COMST_3                        ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  EXMC_COMTR4_COMST_4                        ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  EXMC_COMTR4_COMST_5                        ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  EXMC_COMTR4_COMST_6                        ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  EXMC_COMTR4_COMST_7                        ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  EXMC_COMTR4_COMWT                          ((uint32_t)0x0000FF00)        /*!< COMWT[7:0] bits (Common memory 4 wait time) */
#define  EXMC_COMTR4_COMWT_0                        ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_COMTR4_COMWT_1                        ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_COMTR4_COMWT_2                        ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_COMTR4_COMWT_3                        ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  EXMC_COMTR4_COMWT_4                        ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  EXMC_COMTR4_COMWT_5                        ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  EXMC_COMTR4_COMWT_6                        ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  EXMC_COMTR4_COMWT_7                        ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  EXMC_COMTR4_COMHT                          ((uint32_t)0x00FF0000)        /*!< COMHT[7:0] bits (Common memory 4 hold time) */
#define  EXMC_COMTR4_COMHT_0                        ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_COMTR4_COMHT_1                        ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_COMTR4_COMHT_2                        ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_COMTR4_COMHT_3                        ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  EXMC_COMTR4_COMHT_4                        ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  EXMC_COMTR4_COMHT_5                        ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  EXMC_COMTR4_COMHT_6                        ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  EXMC_COMTR4_COMHT_7                        ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  EXMC_COMTR4_COMHIZT                        ((uint32_t)0xFF000000)        /*!< COMHIZ[7:0] bits (Common memory 4 databus HiZ time) */
#define  EXMC_COMTR4_COMHIZT_0                      ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_COMTR4_COMHIZT_1                      ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_COMTR4_COMHIZT_2                      ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_COMTR4_COMHIZT_3                      ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  EXMC_COMTR4_COMHIZT_4                      ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  EXMC_COMTR4_COMHIZT_5                      ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  EXMC_COMTR4_COMHIZT_6                      ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  EXMC_COMTR4_COMHIZT_7                      ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for EXMC_ATTR2 register  ******************/
#define  EXMC_ATTR2_ATTST                           ((uint32_t)0x000000FF)        /*!< ATTST[7:0] bits (Attribute memory 2 setup time) */
#define  EXMC_ATTR2_ATTST_0                         ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_ATTR2_ATTST_1                         ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_ATTR2_ATTST_2                         ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_ATTR2_ATTST_3                         ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  EXMC_ATTR2_ATTST_4                         ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  EXMC_ATTR2_ATTST_5                         ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  EXMC_ATTR2_ATTST_6                         ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  EXMC_ATTR2_ATTST_7                         ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  EXMC_ATTR2_ATTWT                           ((uint32_t)0x0000FF00)        /*!< ATTWT[7:0] bits (Attribute memory 2 wait time) */
#define  EXMC_ATTR2_ATTWT_0                         ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_ATTR2_ATTWT_1                         ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_ATTR2_ATTWT_2                         ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_ATTR2_ATTWT_3                         ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  EXMC_ATTR2_ATTWT_4                         ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  EXMC_ATTR2_ATTWT_5                         ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  EXMC_ATTR2_ATTWT_6                         ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  EXMC_ATTR2_ATTWT_7                         ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  EXMC_ATTR2_ATTHT                           ((uint32_t)0x00FF0000)        /*!< ATTHT[7:0] bits (Attribute memory 2 hold time) */
#define  EXMC_ATTR2_ATTHT_0                         ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_ATTR2_ATTHT_1                         ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_ATTR2_ATTHT_2                         ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_ATTR2_ATTHT_3                         ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  EXMC_ATTR2_ATTHT_4                         ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  EXMC_ATTR2_ATTHT_5                         ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  EXMC_ATTR2_ATTHT_6                         ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  EXMC_ATTR2_ATTHT_7                         ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  EXMC_ATTR2_ATTHIZT                         ((uint32_t)0xFF000000)        /*!< ATTHIZ[7:0] bits (Attribute memory 2 databus HiZ time) */
#define  EXMC_ATTR2_ATTHIZT_0                       ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_ATTR2_ATTHIZT_1                       ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_ATTR2_ATTHIZT_2                       ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_ATTR2_ATTHIZT_3                       ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  EXMC_ATTR2_ATTHIZT_4                       ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  EXMC_ATTR2_ATTHIZT_5                       ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  EXMC_ATTR2_ATTHIZT_6                       ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  EXMC_ATTR2_ATTHIZT_7                       ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for EXMC_ATTR3 register  ******************/
#define  EXMC_ATTR3_ATTST                           ((uint32_t)0x000000FF)        /*!< ATTST[7:0] bits (Attribute memory 3 setup time) */
#define  EXMC_ATTR3_ATTST_0                         ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_ATTR3_ATTST_1                         ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_ATTR3_ATTST_2                         ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_ATTR3_ATTST_3                         ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  EXMC_ATTR3_ATTST_4                         ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  EXMC_ATTR3_ATTST_5                         ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  EXMC_ATTR3_ATTST_6                         ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  EXMC_ATTR3_ATTST_7                         ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  EXMC_ATTR3_ATTWT                           ((uint32_t)0x0000FF00)        /*!< ATTWT[7:0] bits (Attribute memory 3 wait time) */
#define  EXMC_ATTR3_ATTWT_0                         ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_ATTR3_ATTWT_1                         ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_ATTR3_ATTWT_2                         ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_ATTR3_ATTWT_3                         ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  EXMC_ATTR3_ATTWT_4                         ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  EXMC_ATTR3_ATTWT_5                         ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  EXMC_ATTR3_ATTWT_6                         ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  EXMC_ATTR3_ATTWT_7                         ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  EXMC_ATTR3_ATTHT                           ((uint32_t)0x00FF0000)        /*!< ATTHT[7:0] bits (Attribute memory 3 hold time) */
#define  EXMC_ATTR3_ATTHT_0                         ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_ATTR3_ATTHT_1                         ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_ATTR3_ATTHT_2                         ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_ATTR3_ATTHT_3                         ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  EXMC_ATTR3_ATTHT_4                         ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  EXMC_ATTR3_ATTHT_5                         ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  EXMC_ATTR3_ATTHT_6                         ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  EXMC_ATTR3_ATTHT_7                         ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  EXMC_ATTR3_ATTHIZT                         ((uint32_t)0xFF000000)        /*!< ATTHIZ[7:0] bits (Attribute memory 3 databus HiZ time) */
#define  EXMC_ATTR3_ATTHIZT_0                       ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_ATTR3_ATTHIZT_1                       ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_ATTR3_ATTHIZT_2                       ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_ATTR3_ATTHIZT_3                       ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  EXMC_ATTR3_ATTHIZT_4                       ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  EXMC_ATTR3_ATTHIZT_5                       ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  EXMC_ATTR3_ATTHIZT_6                       ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  EXMC_ATTR3_ATTHIZT_7                       ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for EXMC_ATTR4 register  ******************/
#define  EXMC_ATTR4_ATTST                           ((uint32_t)0x000000FF)        /*!< ATTST[7:0] bits (Attribute memory 4 setup time) */
#define  EXMC_ATTR4_ATTST_0                         ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_ATTR4_ATTST_1                         ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_ATTR4_ATTST_2                         ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_ATTR4_ATTST_3                         ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  EXMC_ATTR4_ATTST_4                         ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  EXMC_ATTR4_ATTST_5                         ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  EXMC_ATTR4_ATTST_6                         ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  EXMC_ATTR4_ATTST_7                         ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  EXMC_ATTR4_ATTWT                           ((uint32_t)0x0000FF00)        /*!< ATTWT[7:0] bits (Attribute memory 4 wait time) */
#define  EXMC_ATTR4_ATTWT_0                         ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_ATTR4_ATTWT_1                         ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_ATTR4_ATTWT_2                         ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_ATTR4_ATTWT_3                         ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  EXMC_ATTR4_ATTWT_4                         ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  EXMC_ATTR4_ATTWT_5                         ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  EXMC_ATTR4_ATTWT_6                         ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  EXMC_ATTR4_ATTWT_7                         ((uint32_t)0x00008000)        /*!< Bit 7 */
								           
#define  EXMC_ATTR4_ATTHT                           ((uint32_t)0x00FF0000)        /*!< ATTHT[7:0] bits (Attribute memory 4 hold time) */
#define  EXMC_ATTR4_ATTHT_0                         ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_ATTR4_ATTHT_1                         ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_ATTR4_ATTHT_2                         ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_ATTR4_ATTHT_3                         ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  EXMC_ATTR4_ATTHT_4                         ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  EXMC_ATTR4_ATTHT_5                         ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  EXMC_ATTR4_ATTHT_6                         ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  EXMC_ATTR4_ATTHT_7                         ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  EXMC_ATTR4_ATTHIZT                         ((uint32_t)0xFF000000)        /*!< ATTHIZ[7:0] bits (Attribute memory 4 databus HiZ time) */
#define  EXMC_ATTR4_ATTHIZT_0                       ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_ATTR4_ATTHIZT_1                       ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_ATTR4_ATTHIZT_2                       ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_ATTR4_ATTHIZT_3                       ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  EXMC_ATTR4_ATTHIZT_4                       ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  EXMC_ATTR4_ATTHIZT_5                       ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  EXMC_ATTR4_ATTHIZT_6                       ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  EXMC_ATTR3_ATTHIZT_7                       ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for EXMC_IOTR4 register  ******************/
#define  EXMC_IOTR4_IOST                            ((uint32_t)0x000000FF)        /*!< IOST[7:0] bits (I/O memory 4 setup time) */
#define  EXMC_IOTR4_IOST_0                          ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  EXMC_IOTR4_IOST_1                          ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  EXMC_IOTR4_IOST_2                          ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  EXMC_IOTR4_IOST_3                          ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  EXMC_IOTR4_IOST_4                          ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  EXMC_IOTR4_IOST_5                          ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  EXMC_IOTR4_IOST_6                          ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  EXMC_IOTR4_IOST_7                          ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  EXMC_IOTR4_IOWT                            ((uint32_t)0x0000FF00)        /*!< IOWT[7:0] bits (I/O memory 4 wait time) */
#define  EXMC_IOTR4_IOWT_0                          ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  EXMC_IOTR4_IOWT_1                          ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  EXMC_IOTR4_IOWT_2                          ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  EXMC_IOTR4_IOWT_3                          ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  EXMC_IOTR4_IOWT_4                          ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  EXMC_IOTR4_IOWT_5                          ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  EXMC_IOTR4_IOWT_6                          ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  EXMC_IOTR4_IOWT_7                          ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  EXMC_IOTR4_IOHT                            ((uint32_t)0x00FF0000)        /*!< IOHT[7:0] bits (I/O memory 4 hold time) */
#define  EXMC_IOTR4_IOHT_0                          ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  EXMC_IOTR4_IOHT_1                          ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  EXMC_IOTR4_IOHT_2                          ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  EXMC_IOTR4_IOHT_3                          ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  EXMC_IOTR4_IOHT_4                          ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  EXMC_IOTR4_IOHT_5                          ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  EXMC_IOTR4_IOHT_6                          ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  EXMC_IOTR4_IOHT_7                          ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  EXMC_IOTR4_IOHIZT                          ((uint32_t)0xFF000000)        /*!< IOHIZ[7:0] bits (I/O memory 4 databus HiZ time) */
#define  EXMC_IOTR4_IOHIZT_0                        ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  EXMC_IOTR4_IOHIZT_1                        ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  EXMC_IOTR4_IOHIZT_2                        ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  EXMC_IOTR4_IOHIZT_3                        ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  EXMC_IOTR4_IOHIZT_4                        ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  EXMC_IOTR4_IOHIZT_5                        ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  EXMC_IOTR4_IOHIZT_6                        ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  EXMC_IOTR4_IOHIZT_7                        ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for EXMC_ECCR2 register  ******************/
#define  EXMC_ECCR2_ECC                             ((uint32_t)0xFFFFFFFF)        /*!< ECC result */

/******************  Bit definition for EXMC_ECCR3 register  ******************/
#define  EXMC_ECCR3_ECC                             ((uint32_t)0xFFFFFFFF)        /*!< ECC result */


/******************************************************************************/
/*                                                                            */
/*                               SystemTick                                   */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for SysTick_CTRL register  *****************/
#define  SYSTICK_CTRL_ENABLE                        ((uint32_t)0x00000001)        /*!< Counter enable */
#define  SYSTICK_CTRL_TICKINT                       ((uint32_t)0x00000002)        /*!< Counting down to 0 pends the SysTick handler */
#define  SYSTICK_CTRL_CLKSOURCE                     ((uint32_t)0x00000004)        /*!< Clock source */
#define  SYSTICK_CTRL_COUNTFLAG                     ((uint32_t)0x00010000)        /*!< Count Flag */

/*****************  Bit definition for SysTick_LOAD register  *****************/
#define  SYSTICK_LOAD_RELOAD                        ((uint32_t)0x00FFFFFF)        /*!< Value to load into the SysTick Current Value Register when the counter reaches 0 */

/*****************  Bit definition for SysTick_VAL register  ******************/
#define  SYSTICK_VAL_CURRENT                        ((uint32_t)0x00FFFFFF)        /*!< Current value at the time the register is accessed */

/*****************  Bit definition for SysTick_CALIB register  ****************/
#define  SYSTICK_CALIB_TENMS                        ((uint32_t)0x00FFFFFF)        /*!< Reload value to use for 10ms timing */
#define  SYSTICK_CALIB_SKEW                         ((uint32_t)0x40000000)        /*!< Calibration value is not exactly 10 ms */
#define  SYSTICK_CALIB_NOREF                        ((uint32_t)0x80000000)        /*!< The reference clock is not provided */

/******************************************************************************/
/*                                                                            */
/*                  Nested Vectored Interrupt Controller                      */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for NVIC_ISER register  *******************/
#define  NVIC_ISER_SETENA                           ((uint32_t)0xFFFFFFFF)        /*!< Interrupt set enable bits */
#define  NVIC_ISER_SETENA_0                         ((uint32_t)0x00000001)        /*!< bit 0 */
#define  NVIC_ISER_SETENA_1                         ((uint32_t)0x00000002)        /*!< bit 1 */
#define  NVIC_ISER_SETENA_2                         ((uint32_t)0x00000004)        /*!< bit 2 */
#define  NVIC_ISER_SETENA_3                         ((uint32_t)0x00000008)        /*!< bit 3 */
#define  NVIC_ISER_SETENA_4                         ((uint32_t)0x00000010)        /*!< bit 4 */
#define  NVIC_ISER_SETENA_5                         ((uint32_t)0x00000020)        /*!< bit 5 */
#define  NVIC_ISER_SETENA_6                         ((uint32_t)0x00000040)        /*!< bit 6 */
#define  NVIC_ISER_SETENA_7                         ((uint32_t)0x00000080)        /*!< bit 7 */
#define  NVIC_ISER_SETENA_8                         ((uint32_t)0x00000100)        /*!< bit 8 */
#define  NVIC_ISER_SETENA_9                         ((uint32_t)0x00000200)        /*!< bit 9 */
#define  NVIC_ISER_SETENA_10                        ((uint32_t)0x00000400)        /*!< bit 10 */
#define  NVIC_ISER_SETENA_11                        ((uint32_t)0x00000800)        /*!< bit 11 */
#define  NVIC_ISER_SETENA_12                        ((uint32_t)0x00001000)        /*!< bit 12 */
#define  NVIC_ISER_SETENA_13                        ((uint32_t)0x00002000)        /*!< bit 13 */
#define  NVIC_ISER_SETENA_14                        ((uint32_t)0x00004000)        /*!< bit 14 */
#define  NVIC_ISER_SETENA_15                        ((uint32_t)0x00008000)        /*!< bit 15 */
#define  NVIC_ISER_SETENA_16                        ((uint32_t)0x00010000)        /*!< bit 16 */
#define  NVIC_ISER_SETENA_17                        ((uint32_t)0x00020000)        /*!< bit 17 */
#define  NVIC_ISER_SETENA_18                        ((uint32_t)0x00040000)        /*!< bit 18 */
#define  NVIC_ISER_SETENA_19                        ((uint32_t)0x00080000)        /*!< bit 19 */
#define  NVIC_ISER_SETENA_20                        ((uint32_t)0x00100000)        /*!< bit 20 */
#define  NVIC_ISER_SETENA_21                        ((uint32_t)0x00200000)        /*!< bit 21 */
#define  NVIC_ISER_SETENA_22                        ((uint32_t)0x00400000)        /*!< bit 22 */
#define  NVIC_ISER_SETENA_23                        ((uint32_t)0x00800000)        /*!< bit 23 */
#define  NVIC_ISER_SETENA_24                        ((uint32_t)0x01000000)        /*!< bit 24 */
#define  NVIC_ISER_SETENA_25                        ((uint32_t)0x02000000)        /*!< bit 25 */
#define  NVIC_ISER_SETENA_26                        ((uint32_t)0x04000000)        /*!< bit 26 */
#define  NVIC_ISER_SETENA_27                        ((uint32_t)0x08000000)        /*!< bit 27 */
#define  NVIC_ISER_SETENA_28                        ((uint32_t)0x10000000)        /*!< bit 28 */
#define  NVIC_ISER_SETENA_29                        ((uint32_t)0x20000000)        /*!< bit 29 */
#define  NVIC_ISER_SETENA_30                        ((uint32_t)0x40000000)        /*!< bit 30 */
#define  NVIC_ISER_SETENA_31                        ((uint32_t)0x80000000)        /*!< bit 31 */

/******************  Bit definition for NVIC_ICER register  *******************/
#define  NVIC_ICER_CLRENA                           ((uint32_t)0xFFFFFFFF)        /*!< Interrupt clear-enable bits */
#define  NVIC_ICER_CLRENA_0                         ((uint32_t)0x00000001)        /*!< bit 0 */
#define  NVIC_ICER_CLRENA_1                         ((uint32_t)0x00000002)        /*!< bit 1 */
#define  NVIC_ICER_CLRENA_2                         ((uint32_t)0x00000004)        /*!< bit 2 */
#define  NVIC_ICER_CLRENA_3                         ((uint32_t)0x00000008)        /*!< bit 3 */
#define  NVIC_ICER_CLRENA_4                         ((uint32_t)0x00000010)        /*!< bit 4 */
#define  NVIC_ICER_CLRENA_5                         ((uint32_t)0x00000020)        /*!< bit 5 */
#define  NVIC_ICER_CLRENA_6                         ((uint32_t)0x00000040)        /*!< bit 6 */
#define  NVIC_ICER_CLRENA_7                         ((uint32_t)0x00000080)        /*!< bit 7 */
#define  NVIC_ICER_CLRENA_8                         ((uint32_t)0x00000100)        /*!< bit 8 */
#define  NVIC_ICER_CLRENA_9                         ((uint32_t)0x00000200)        /*!< bit 9 */
#define  NVIC_ICER_CLRENA_10                        ((uint32_t)0x00000400)        /*!< bit 10 */
#define  NVIC_ICER_CLRENA_11                        ((uint32_t)0x00000800)        /*!< bit 11 */
#define  NVIC_ICER_CLRENA_12                        ((uint32_t)0x00001000)        /*!< bit 12 */
#define  NVIC_ICER_CLRENA_13                        ((uint32_t)0x00002000)        /*!< bit 13 */
#define  NVIC_ICER_CLRENA_14                        ((uint32_t)0x00004000)        /*!< bit 14 */
#define  NVIC_ICER_CLRENA_15                        ((uint32_t)0x00008000)        /*!< bit 15 */
#define  NVIC_ICER_CLRENA_16                        ((uint32_t)0x00010000)        /*!< bit 16 */
#define  NVIC_ICER_CLRENA_17                        ((uint32_t)0x00020000)        /*!< bit 17 */
#define  NVIC_ICER_CLRENA_18                        ((uint32_t)0x00040000)        /*!< bit 18 */
#define  NVIC_ICER_CLRENA_19                        ((uint32_t)0x00080000)        /*!< bit 19 */
#define  NVIC_ICER_CLRENA_20                        ((uint32_t)0x00100000)        /*!< bit 20 */
#define  NVIC_ICER_CLRENA_21                        ((uint32_t)0x00200000)        /*!< bit 21 */
#define  NVIC_ICER_CLRENA_22                        ((uint32_t)0x00400000)        /*!< bit 22 */
#define  NVIC_ICER_CLRENA_23                        ((uint32_t)0x00800000)        /*!< bit 23 */
#define  NVIC_ICER_CLRENA_24                        ((uint32_t)0x01000000)        /*!< bit 24 */
#define  NVIC_ICER_CLRENA_25                        ((uint32_t)0x02000000)        /*!< bit 25 */
#define  NVIC_ICER_CLRENA_26                        ((uint32_t)0x04000000)        /*!< bit 26 */
#define  NVIC_ICER_CLRENA_27                        ((uint32_t)0x08000000)        /*!< bit 27 */
#define  NVIC_ICER_CLRENA_28                        ((uint32_t)0x10000000)        /*!< bit 28 */
#define  NVIC_ICER_CLRENA_29                        ((uint32_t)0x20000000)        /*!< bit 29 */
#define  NVIC_ICER_CLRENA_30                        ((uint32_t)0x40000000)        /*!< bit 30 */
#define  NVIC_ICER_CLRENA_31                        ((uint32_t)0x80000000)        /*!< bit 31 */

/******************  Bit definition for NVIC_ISPR register  *******************/
#define  NVIC_ISPR_SETPEND                          ((uint32_t)0xFFFFFFFF)        /*!< Interrupt set-pending bits */
#define  NVIC_ISPR_SETPEND_0                        ((uint32_t)0x00000001)        /*!< bit 0 */
#define  NVIC_ISPR_SETPEND_1                        ((uint32_t)0x00000002)        /*!< bit 1 */
#define  NVIC_ISPR_SETPEND_2                        ((uint32_t)0x00000004)        /*!< bit 2 */
#define  NVIC_ISPR_SETPEND_3                        ((uint32_t)0x00000008)        /*!< bit 3 */
#define  NVIC_ISPR_SETPEND_4                        ((uint32_t)0x00000010)        /*!< bit 4 */
#define  NVIC_ISPR_SETPEND_5                        ((uint32_t)0x00000020)        /*!< bit 5 */
#define  NVIC_ISPR_SETPEND_6                        ((uint32_t)0x00000040)        /*!< bit 6 */
#define  NVIC_ISPR_SETPEND_7                        ((uint32_t)0x00000080)        /*!< bit 7 */
#define  NVIC_ISPR_SETPEND_8                        ((uint32_t)0x00000100)        /*!< bit 8 */
#define  NVIC_ISPR_SETPEND_9                        ((uint32_t)0x00000200)        /*!< bit 9 */
#define  NVIC_ISPR_SETPEND_10                       ((uint32_t)0x00000400)        /*!< bit 10 */
#define  NVIC_ISPR_SETPEND_11                       ((uint32_t)0x00000800)        /*!< bit 11 */
#define  NVIC_ISPR_SETPEND_12                       ((uint32_t)0x00001000)        /*!< bit 12 */
#define  NVIC_ISPR_SETPEND_13                       ((uint32_t)0x00002000)        /*!< bit 13 */
#define  NVIC_ISPR_SETPEND_14                       ((uint32_t)0x00004000)        /*!< bit 14 */
#define  NVIC_ISPR_SETPEND_15                       ((uint32_t)0x00008000)        /*!< bit 15 */
#define  NVIC_ISPR_SETPEND_16                       ((uint32_t)0x00010000)        /*!< bit 16 */
#define  NVIC_ISPR_SETPEND_17                       ((uint32_t)0x00020000)        /*!< bit 17 */
#define  NVIC_ISPR_SETPEND_18                       ((uint32_t)0x00040000)        /*!< bit 18 */
#define  NVIC_ISPR_SETPEND_19                       ((uint32_t)0x00080000)        /*!< bit 19 */
#define  NVIC_ISPR_SETPEND_20                       ((uint32_t)0x00100000)        /*!< bit 20 */
#define  NVIC_ISPR_SETPEND_21                       ((uint32_t)0x00200000)        /*!< bit 21 */
#define  NVIC_ISPR_SETPEND_22                       ((uint32_t)0x00400000)        /*!< bit 22 */
#define  NVIC_ISPR_SETPEND_23                       ((uint32_t)0x00800000)        /*!< bit 23 */
#define  NVIC_ISPR_SETPEND_24                       ((uint32_t)0x01000000)        /*!< bit 24 */
#define  NVIC_ISPR_SETPEND_25                       ((uint32_t)0x02000000)        /*!< bit 25 */
#define  NVIC_ISPR_SETPEND_26                       ((uint32_t)0x04000000)        /*!< bit 26 */
#define  NVIC_ISPR_SETPEND_27                       ((uint32_t)0x08000000)        /*!< bit 27 */
#define  NVIC_ISPR_SETPEND_28                       ((uint32_t)0x10000000)        /*!< bit 28 */
#define  NVIC_ISPR_SETPEND_29                       ((uint32_t)0x20000000)        /*!< bit 29 */
#define  NVIC_ISPR_SETPEND_30                       ((uint32_t)0x40000000)        /*!< bit 30 */
#define  NVIC_ISPR_SETPEND_31                       ((uint32_t)0x80000000)        /*!< bit 31 */

/******************  Bit definition for NVIC_ICPR register  *******************/
#define  NVIC_ICPR_CLRPEND                          ((uint32_t)0xFFFFFFFF)        /*!< Interrupt clear-pending bits */
#define  NVIC_ICPR_CLRPEND_0                        ((uint32_t)0x00000001)        /*!< bit 0 */
#define  NVIC_ICPR_CLRPEND_1                        ((uint32_t)0x00000002)        /*!< bit 1 */
#define  NVIC_ICPR_CLRPEND_2                        ((uint32_t)0x00000004)        /*!< bit 2 */
#define  NVIC_ICPR_CLRPEND_3                        ((uint32_t)0x00000008)        /*!< bit 3 */
#define  NVIC_ICPR_CLRPEND_4                        ((uint32_t)0x00000010)        /*!< bit 4 */
#define  NVIC_ICPR_CLRPEND_5                        ((uint32_t)0x00000020)        /*!< bit 5 */
#define  NVIC_ICPR_CLRPEND_6                        ((uint32_t)0x00000040)        /*!< bit 6 */
#define  NVIC_ICPR_CLRPEND_7                        ((uint32_t)0x00000080)        /*!< bit 7 */
#define  NVIC_ICPR_CLRPEND_8                        ((uint32_t)0x00000100)        /*!< bit 8 */
#define  NVIC_ICPR_CLRPEND_9                        ((uint32_t)0x00000200)        /*!< bit 9 */
#define  NVIC_ICPR_CLRPEND_10                       ((uint32_t)0x00000400)        /*!< bit 10 */
#define  NVIC_ICPR_CLRPEND_11                       ((uint32_t)0x00000800)        /*!< bit 11 */
#define  NVIC_ICPR_CLRPEND_12                       ((uint32_t)0x00001000)        /*!< bit 12 */
#define  NVIC_ICPR_CLRPEND_13                       ((uint32_t)0x00002000)        /*!< bit 13 */
#define  NVIC_ICPR_CLRPEND_14                       ((uint32_t)0x00004000)        /*!< bit 14 */
#define  NVIC_ICPR_CLRPEND_15                       ((uint32_t)0x00008000)        /*!< bit 15 */
#define  NVIC_ICPR_CLRPEND_16                       ((uint32_t)0x00010000)        /*!< bit 16 */
#define  NVIC_ICPR_CLRPEND_17                       ((uint32_t)0x00020000)        /*!< bit 17 */
#define  NVIC_ICPR_CLRPEND_18                       ((uint32_t)0x00040000)        /*!< bit 18 */
#define  NVIC_ICPR_CLRPEND_19                       ((uint32_t)0x00080000)        /*!< bit 19 */
#define  NVIC_ICPR_CLRPEND_20                       ((uint32_t)0x00100000)        /*!< bit 20 */
#define  NVIC_ICPR_CLRPEND_21                       ((uint32_t)0x00200000)        /*!< bit 21 */
#define  NVIC_ICPR_CLRPEND_22                       ((uint32_t)0x00400000)        /*!< bit 22 */
#define  NVIC_ICPR_CLRPEND_23                       ((uint32_t)0x00800000)        /*!< bit 23 */
#define  NVIC_ICPR_CLRPEND_24                       ((uint32_t)0x01000000)        /*!< bit 24 */
#define  NVIC_ICPR_CLRPEND_25                       ((uint32_t)0x02000000)        /*!< bit 25 */
#define  NVIC_ICPR_CLRPEND_26                       ((uint32_t)0x04000000)        /*!< bit 26 */
#define  NVIC_ICPR_CLRPEND_27                       ((uint32_t)0x08000000)        /*!< bit 27 */
#define  NVIC_ICPR_CLRPEND_28                       ((uint32_t)0x10000000)        /*!< bit 28 */
#define  NVIC_ICPR_CLRPEND_29                       ((uint32_t)0x20000000)        /*!< bit 29 */
#define  NVIC_ICPR_CLRPEND_30                       ((uint32_t)0x40000000)        /*!< bit 30 */
#define  NVIC_ICPR_CLRPEND_31                       ((uint32_t)0x80000000)        /*!< bit 31 */
								         
/******************  Bit definition for NVIC_IABR register  *******************/
#define  NVIC_IABR_ACTIVE                           ((uint32_t)0xFFFFFFFF)        /*!< Interrupt active flags */
#define  NVIC_IABR_ACTIVE_0                         ((uint32_t)0x00000001)        /*!< bit 0 */
#define  NVIC_IABR_ACTIVE_1                         ((uint32_t)0x00000002)        /*!< bit 1 */
#define  NVIC_IABR_ACTIVE_2                         ((uint32_t)0x00000004)        /*!< bit 2 */
#define  NVIC_IABR_ACTIVE_3                         ((uint32_t)0x00000008)        /*!< bit 3 */
#define  NVIC_IABR_ACTIVE_4                         ((uint32_t)0x00000010)        /*!< bit 4 */
#define  NVIC_IABR_ACTIVE_5                         ((uint32_t)0x00000020)        /*!< bit 5 */
#define  NVIC_IABR_ACTIVE_6                         ((uint32_t)0x00000040)        /*!< bit 6 */
#define  NVIC_IABR_ACTIVE_7                         ((uint32_t)0x00000080)        /*!< bit 7 */
#define  NVIC_IABR_ACTIVE_8                         ((uint32_t)0x00000100)        /*!< bit 8 */
#define  NVIC_IABR_ACTIVE_9                         ((uint32_t)0x00000200)        /*!< bit 9 */
#define  NVIC_IABR_ACTIVE_10                        ((uint32_t)0x00000400)        /*!< bit 10 */
#define  NVIC_IABR_ACTIVE_11                        ((uint32_t)0x00000800)        /*!< bit 11 */
#define  NVIC_IABR_ACTIVE_12                        ((uint32_t)0x00001000)        /*!< bit 12 */
#define  NVIC_IABR_ACTIVE_13                        ((uint32_t)0x00002000)        /*!< bit 13 */
#define  NVIC_IABR_ACTIVE_14                        ((uint32_t)0x00004000)        /*!< bit 14 */
#define  NVIC_IABR_ACTIVE_15                        ((uint32_t)0x00008000)        /*!< bit 15 */
#define  NVIC_IABR_ACTIVE_16                        ((uint32_t)0x00010000)        /*!< bit 16 */
#define  NVIC_IABR_ACTIVE_17                        ((uint32_t)0x00020000)        /*!< bit 17 */
#define  NVIC_IABR_ACTIVE_18                        ((uint32_t)0x00040000)        /*!< bit 18 */
#define  NVIC_IABR_ACTIVE_19                        ((uint32_t)0x00080000)        /*!< bit 19 */
#define  NVIC_IABR_ACTIVE_20                        ((uint32_t)0x00100000)        /*!< bit 20 */
#define  NVIC_IABR_ACTIVE_21                        ((uint32_t)0x00200000)        /*!< bit 21 */
#define  NVIC_IABR_ACTIVE_22                        ((uint32_t)0x00400000)        /*!< bit 22 */
#define  NVIC_IABR_ACTIVE_23                        ((uint32_t)0x00800000)        /*!< bit 23 */
#define  NVIC_IABR_ACTIVE_24                        ((uint32_t)0x01000000)        /*!< bit 24 */
#define  NVIC_IABR_ACTIVE_25                        ((uint32_t)0x02000000)        /*!< bit 25 */
#define  NVIC_IABR_ACTIVE_26                        ((uint32_t)0x04000000)        /*!< bit 26 */
#define  NVIC_IABR_ACTIVE_27                        ((uint32_t)0x08000000)        /*!< bit 27 */
#define  NVIC_IABR_ACTIVE_28                        ((uint32_t)0x10000000)        /*!< bit 28 */
#define  NVIC_IABR_ACTIVE_29                        ((uint32_t)0x20000000)        /*!< bit 29 */
#define  NVIC_IABR_ACTIVE_30                        ((uint32_t)0x40000000)        /*!< bit 30 */
#define  NVIC_IABR_ACTIVE_31                        ((uint32_t)0x80000000)        /*!< bit 31 */

/******************  Bit definition for NVIC_PRI0 register  *******************/
#define  NVIC_IPR0_PRI_0                            ((uint32_t)0x000000FF)        /*!< Priority of interrupt 0 */
#define  NVIC_IPR0_PRI_1                            ((uint32_t)0x0000FF00)        /*!< Priority of interrupt 1 */
#define  NVIC_IPR0_PRI_2                            ((uint32_t)0x00FF0000)        /*!< Priority of interrupt 2 */
#define  NVIC_IPR0_PRI_3                            ((uint32_t)0xFF000000)        /*!< Priority of interrupt 3 */
									        
/******************  Bit definition for NVIC_PRI1 register  *******************/
#define  NVIC_IPR1_PRI_4                            ((uint32_t)0x000000FF)        /*!< Priority of interrupt 4 */
#define  NVIC_IPR1_PRI_5                            ((uint32_t)0x0000FF00)        /*!< Priority of interrupt 5 */
#define  NVIC_IPR1_PRI_6                            ((uint32_t)0x00FF0000)        /*!< Priority of interrupt 6 */
#define  NVIC_IPR1_PRI_7                            ((uint32_t)0xFF000000)        /*!< Priority of interrupt 7 */

/******************  Bit definition for NVIC_PRI2 register  *******************/
#define  NVIC_IPR2_PRI_8                            ((uint32_t)0x000000FF)        /*!< Priority of interrupt 8 */
#define  NVIC_IPR2_PRI_9                            ((uint32_t)0x0000FF00)        /*!< Priority of interrupt 9 */
#define  NVIC_IPR2_PRI_10                           ((uint32_t)0x00FF0000)        /*!< Priority of interrupt 10 */
#define  NVIC_IPR2_PRI_11                           ((uint32_t)0xFF000000)        /*!< Priority of interrupt 11 */
								         
/******************  Bit definition for NVIC_PRI3 register  *******************/
#define  NVIC_IPR3_PRI_12                           ((uint32_t)0x000000FF)        /*!< Priority of interrupt 12 */
#define  NVIC_IPR3_PRI_13                           ((uint32_t)0x0000FF00)        /*!< Priority of interrupt 13 */
#define  NVIC_IPR3_PRI_14                           ((uint32_t)0x00FF0000)        /*!< Priority of interrupt 14 */
#define  NVIC_IPR3_PRI_15                           ((uint32_t)0xFF000000)        /*!< Priority of interrupt 15 */
								         
/******************  Bit definition for NVIC_PRI4 register  *******************/
#define  NVIC_IPR4_PRI_16                           ((uint32_t)0x000000FF)        /*!< Priority of interrupt 16 */
#define  NVIC_IPR4_PRI_17                           ((uint32_t)0x0000FF00)        /*!< Priority of interrupt 17 */
#define  NVIC_IPR4_PRI_18                           ((uint32_t)0x00FF0000)        /*!< Priority of interrupt 18 */
#define  NVIC_IPR4_PRI_19                           ((uint32_t)0xFF000000)        /*!< Priority of interrupt 19 */

/******************  Bit definition for NVIC_PRI5 register  *******************/
#define  NVIC_IPR5_PRI_20                           ((uint32_t)0x000000FF)        /*!< Priority of interrupt 20 */
#define  NVIC_IPR5_PRI_21                           ((uint32_t)0x0000FF00)        /*!< Priority of interrupt 21 */
#define  NVIC_IPR5_PRI_22                           ((uint32_t)0x00FF0000)        /*!< Priority of interrupt 22 */
#define  NVIC_IPR5_PRI_23                           ((uint32_t)0xFF000000)        /*!< Priority of interrupt 23 */

/******************  Bit definition for NVIC_PRI6 register  *******************/
#define  NVIC_IPR6_PRI_24                           ((uint32_t)0x000000FF)        /*!< Priority of interrupt 24 */
#define  NVIC_IPR6_PRI_25                           ((uint32_t)0x0000FF00)        /*!< Priority of interrupt 25 */
#define  NVIC_IPR6_PRI_26                           ((uint32_t)0x00FF0000)        /*!< Priority of interrupt 26 */
#define  NVIC_IPR6_PRI_27                           ((uint32_t)0xFF000000)        /*!< Priority of interrupt 27 */

/******************  Bit definition for NVIC_PRI7 register  *******************/
#define  NVIC_IPR7_PRI_28                           ((uint32_t)0x000000FF)        /*!< Priority of interrupt 28 */
#define  NVIC_IPR7_PRI_29                           ((uint32_t)0x0000FF00)        /*!< Priority of interrupt 29 */
#define  NVIC_IPR7_PRI_30                           ((uint32_t)0x00FF0000)        /*!< Priority of interrupt 30 */
#define  NVIC_IPR7_PRI_31                           ((uint32_t)0xFF000000)        /*!< Priority of interrupt 31 */

/******************  Bit definition for SCB_CPUID register  *******************/
#define  SCB_CPUID_REVISION                         ((uint32_t)0x0000000F)        /*!< Implementation defined revision number */
#define  SCB_CPUID_PARTNO                           ((uint32_t)0x0000FFF0)        /*!< Number of processor within family */
#define  SCB_CPUID_Constant                         ((uint32_t)0x000F0000)        /*!< Reads as 0x0F */
#define  SCB_CPUID_VARIANT                          ((uint32_t)0x00F00000)        /*!< Implementation defined variant number */
#define  SCB_CPUID_IMPLEMENTER                      ((uint32_t)0xFF000000)        /*!< Implementer code. ARM is 0x41 */

/*******************  Bit definition for SCB_ICSR register  *******************/
#define  SCB_ICSR_VECTACTIVE                        ((uint32_t)0x000001FF)        /*!< Active ISR number field */
#define  SCB_ICSR_RETTOBASE                         ((uint32_t)0x00000800)        /*!< All active exceptions minus the IPSR_current_exception yields the empty set */
#define  SCB_ICSR_VECTPENDING                       ((uint32_t)0x003FF000)        /*!< Pending ISR number field */
#define  SCB_ICSR_ISRPENDING                        ((uint32_t)0x00400000)        /*!< Interrupt pending flag */
#define  SCB_ICSR_ISRPREEMPT                        ((uint32_t)0x00800000)        /*!< It indicates that a pending interrupt becomes active in the next running cycle */
#define  SCB_ICSR_PENDSTCLR                         ((uint32_t)0x02000000)        /*!< Clear pending SysTick bit */
#define  SCB_ICSR_PENDSTSET                         ((uint32_t)0x04000000)        /*!< Set pending SysTick bit */
#define  SCB_ICSR_PENDSVCLR                         ((uint32_t)0x08000000)        /*!< Clear pending pendSV bit */
#define  SCB_ICSR_PENDSVSET                         ((uint32_t)0x10000000)        /*!< Set pending pendSV bit */
#define  SCB_ICSR_NMIPENDSET                        ((uint32_t)0x80000000)        /*!< Set pending NMI bit */

/*******************  Bit definition for SCB_VTOR register  *******************/
#define  SCB_VTOR_TBLOFF                            ((uint32_t)0x1FFFFF80)        /*!< Vector table base offset field */
#define  SCB_VTOR_TBLBASE                           ((uint32_t)0x20000000)        /*!< Table base in code(0) or RAM(1) */
									       
/*!<*****************  Bit definition for SCB_AIRCR register  *******************/
#define  SCB_AIRCR_VECTRESET                        ((uint32_t)0x00000001)        /*!< System Reset bit */
#define  SCB_AIRCR_VECTCLRACTIVE                    ((uint32_t)0x00000002)        /*!< Clear active vector bit */
#define  SCB_AIRCR_SYSRESETREQ                      ((uint32_t)0x00000004)        /*!< Requests chip control logic to generate a reset */

#define  SCB_AIRCR_PRIGROUP                         ((uint32_t)0x00000700)        /*!< PRIGROUP[2:0] bits (Priority group) */
#define  SCB_AIRCR_PRIGROUP_0                       ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  SCB_AIRCR_PRIGROUP_1                       ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  SCB_AIRCR_PRIGROUP_2                       ((uint32_t)0x00000400)        /*!< Bit 2  */

/* prority group configuration */
#define  SCB_AIRCR_PRIGROUP0                        ((uint32_t)0x00000000)        /*!< Priority group=0 (7 bits of pre-emption priority, 1 bit of subpriority) */
#define  SCB_AIRCR_PRIGROUP1                        ((uint32_t)0x00000100)        /*!< Priority group=1 (6 bits of pre-emption priority, 2 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP2                        ((uint32_t)0x00000200)        /*!< Priority group=2 (5 bits of pre-emption priority, 3 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP3                        ((uint32_t)0x00000300)        /*!< Priority group=3 (4 bits of pre-emption priority, 4 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP4                        ((uint32_t)0x00000400)        /*!< Priority group=4 (3 bits of pre-emption priority, 5 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP5                        ((uint32_t)0x00000500)        /*!< Priority group=5 (2 bits of pre-emption priority, 6 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP6                        ((uint32_t)0x00000600)        /*!< Priority group=6 (1 bit of pre-emption priority, 7 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP7                        ((uint32_t)0x00000700)        /*!< Priority group=7 (no pre-emption priority, 8 bits of subpriority) */

#define  SCB_AIRCR_ENDIANESS                        ((uint32_t)0x00008000)        /*!< Data endianness bit */
#define  SCB_AIRCR_VECTKEY                          ((uint32_t)0xFFFF0000)        /*!< Register key (VECTKEY) - Reads as 0xFA05 (VECTKEYSTAT) */
								          
/*******************  Bit definition for SCB_SCR register  ********************/
#define  SCB_SCR_SLEEPONEXIT                        ((uint8_t)0x02)               /*!< Sleep on exit bit */
#define  SCB_SCR_SLEEPDEEP                          ((uint8_t)0x04)               /*!< Sleep deep bit */
#define  SCB_SCR_SEVONPEND                          ((uint8_t)0x10)               /*!< Wake up from WFE */

/********************  Bit definition for SCB_CCR register  *******************/
#define  SCB_CCR_NONBASETHRDENA                     ((uint16_t)0x0001)            /*!< Thread mode can be entered from any level in Handler mode by controlled return value */
#define  SCB_CCR_USERSETMPEND                       ((uint16_t)0x0002)            /*!< Enables user code to write the Software Trigger Interrupt register to trigger (pend) a Main exception */
#define  SCB_CCR_UNALIGN_TRP                        ((uint16_t)0x0008)            /*!< Trap for unaligned access */
#define  SCB_CCR_DIV_0_TRP                          ((uint16_t)0x0010)            /*!< Trap on Divide by 0 */
#define  SCB_CCR_BFHFNMIGN                          ((uint16_t)0x0100)            /*!< Handlers running at priority -1 and -2 */
#define  SCB_CCR_STKALIGN                           ((uint16_t)0x0200)            /*!< On exception entry, the SP used prior to the exception is adjusted to be 8-byte aligned */

/*******************  Bit definition for SCB_SHPR register ********************/
#define  SCB_SHPR_PRI_N                             ((uint32_t)0x000000FF)        /*!< Priority of system handler 4,8, and 12. Mem Manage, reserved and Debug Monitor */
#define  SCB_SHPR_PRI_N1                            ((uint32_t)0x0000FF00)        /*!< Priority of system handler 5,9, and 13. Bus Fault, reserved and reserved */
#define  SCB_SHPR_PRI_N2                            ((uint32_t)0x00FF0000)        /*!< Priority of system handler 6,10, and 14. Usage Fault, reserved and PendSV */
#define  SCB_SHPR_PRI_N3                            ((uint32_t)0xFF000000)        /*!< Priority of system handler 7,11, and 15. Reserved, SVCall and SysTick */
									       
/******************  Bit definition for SCB_SHCSR register  *******************/
#define  SCB_SHCSR_MEMFAULTACT                      ((uint32_t)0x00000001)        /*!< MemManage is active */
#define  SCB_SHCSR_BUSFAULTACT                      ((uint32_t)0x00000002)        /*!< BusFault is active */
#define  SCB_SHCSR_USGFAULTACT                      ((uint32_t)0x00000008)        /*!< UsageFault is active */
#define  SCB_SHCSR_SVCALLACT                        ((uint32_t)0x00000080)        /*!< SVCall is active */
#define  SCB_SHCSR_MONITORACT                       ((uint32_t)0x00000100)        /*!< Monitor is active */
#define  SCB_SHCSR_PENDSVACT                        ((uint32_t)0x00000400)        /*!< PendSV is active */
#define  SCB_SHCSR_SYSTICKACT                       ((uint32_t)0x00000800)        /*!< SysTick is active */
#define  SCB_SHCSR_USGFAULTPENDED                   ((uint32_t)0x00001000)        /*!< Usage Fault is pended */
#define  SCB_SHCSR_MEMFAULTPENDED                   ((uint32_t)0x00002000)        /*!< MemManage is pended */
#define  SCB_SHCSR_BUSFAULTPENDED                   ((uint32_t)0x00004000)        /*!< Bus Fault is pended */
#define  SCB_SHCSR_SVCALLPENDED                     ((uint32_t)0x00008000)        /*!< SVCall is pended */
#define  SCB_SHCSR_MEMFAULTENA                      ((uint32_t)0x00010000)        /*!< MemManage enable */
#define  SCB_SHCSR_BUSFAULTENA                      ((uint32_t)0x00020000)        /*!< Bus Fault enable */
#define  SCB_SHCSR_USGFAULTENA                      ((uint32_t)0x00040000)        /*!< UsageFault enable */

/*******************  Bit definition for SCB_CFSR register  *******************/
/*!< MFSR */
#define  SCB_CFSR_IACCVIOL                          ((uint32_t)0x00000001)        /*!< Instruction access violation */
#define  SCB_CFSR_DACCVIOL                          ((uint32_t)0x00000002)        /*!< Data access violation */
#define  SCB_CFSR_MUNSTKERR                         ((uint32_t)0x00000008)        /*!< Unstacking error */
#define  SCB_CFSR_MSTKERR                           ((uint32_t)0x00000010)        /*!< Stacking error */
#define  SCB_CFSR_MMARVALID                         ((uint32_t)0x00000080)        /*!< Memory Manage Address Register address valid flag */
/*!< BFSR */
#define  SCB_CFSR_IBUSERR                           ((uint32_t)0x00000100)        /*!< Instruction bus error flag */
#define  SCB_CFSR_PRECISERR                         ((uint32_t)0x00000200)        /*!< Precise data bus error */
#define  SCB_CFSR_IMPRECISERR                       ((uint32_t)0x00000400)        /*!< Imprecise data bus error */
#define  SCB_CFSR_UNSTKERR                          ((uint32_t)0x00000800)        /*!< Unstacking error */
#define  SCB_CFSR_STKERR                            ((uint32_t)0x00001000)        /*!< Stacking error */
#define  SCB_CFSR_BFARVALID                         ((uint32_t)0x00008000)        /*!< Bus Fault Address Register address valid flag */
/*!< UFSR */
#define  SCB_CFSR_UNDEFINSTR                        ((uint32_t)0x00010000)        /*!< The processor attempt to execute an undefined instruction */
#define  SCB_CFSR_INVSTATE                          ((uint32_t)0x00020000)        /*!< Invalid combination of EPSR and instruction */
#define  SCB_CFSR_INVPC                             ((uint32_t)0x00040000)        /*!< Attempt to load EXC_RETURN into pc illegally */
#define  SCB_CFSR_NOCP                              ((uint32_t)0x00080000)        /*!< Attempt to use a coprocessor instruction */
#define  SCB_CFSR_UNALIGNED                         ((uint32_t)0x01000000)        /*!< Fault occurs when there is an attempt to make an unaligned memory access */
#define  SCB_CFSR_DIVBYZERO                         ((uint32_t)0x02000000)        /*!< Fault occurs when SDIV or DIV instruction is used with a divisor of 0 */

/*******************  Bit definition for SCB_HFSR register  *******************/
#define  SCB_HFSR_VECTTBL                           ((uint32_t)0x00000002)        /*!< Fault occurs because of vector table read on exception processing */
#define  SCB_HFSR_FORCED                            ((uint32_t)0x40000000)        /*!< Hard Fault activated when a configurable Fault was received and cannot activate */
#define  SCB_HFSR_DEBUGEVT                          ((uint32_t)0x80000000)        /*!< Fault related to debug */

/*******************  Bit definition for SCB_DFSR register  *******************/
#define  SCB_DFSR_HALTED                            ((uint8_t)0x01)               /*!< Halt request flag */
#define  SCB_DFSR_BKPT                              ((uint8_t)0x02)               /*!< BKPT flag */
#define  SCB_DFSR_DWTTRAP                           ((uint8_t)0x04)               /*!< Data Watchpoint and Trace (DWT) flag */
#define  SCB_DFSR_VCATCH                            ((uint8_t)0x08)               /*!< Vector catch flag */
#define  SCB_DFSR_EXTERNAL                          ((uint8_t)0x10)               /*!< External debug request flag */

/*******************  Bit definition for SCB_MMFAR register  ******************/
#define  SCB_MMFAR_ADDRESS                          ((uint32_t)0xFFFFFFFF)        /*!< Mem Manage fault address field */

/*******************  Bit definition for SCB_BFAR register  *******************/
#define  SCB_BFAR_ADDRESS                           ((uint32_t)0xFFFFFFFF)        /*!< Bus fault address field */

/*******************  Bit definition for SCB_afsr register  *******************/
#define  SCB_AFSR_IMPDEF                            ((uint32_t)0xFFFFFFFF)        /*!< Implementation defined */

/******************************************************************************/
/*                                                                            */
/*                       General Purpose IOs (GPIO)                           */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for GPIO_CTLR1 register  *******************/
#define  GPIO_CTLR1_MD                              ((uint32_t)0x33333333)        /*!< Port x mode bits */

#define  GPIO_CTLR1_MD0                             ((uint32_t)0x00000003)        /*!< MODE0[1:0] bits (Port x mode bits, pin 0) */
#define  GPIO_CTLR1_MD0_0                           ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  GPIO_CTLR1_MD0_1                           ((uint32_t)0x00000002)        /*!< Bit 1 */
								          
#define  GPIO_CTLR1_MD1                             ((uint32_t)0x00000030)        /*!< MODE1[1:0] bits (Port x mode bits, pin 1) */
#define  GPIO_CTLR1_MD1_0                           ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  GPIO_CTLR1_MD1_1                           ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  GPIO_CTLR1_MD2                             ((uint32_t)0x00000300)        /*!< MODE2[1:0] bits (Port x mode bits, pin 2) */
#define  GPIO_CTLR1_MD2_0                           ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  GPIO_CTLR1_MD2_1                           ((uint32_t)0x00000200)        /*!< Bit 1 */

#define  GPIO_CTLR1_MD3                             ((uint32_t)0x00003000)        /*!< MODE3[1:0] bits (Port x mode bits, pin 3) */
#define  GPIO_CTLR1_MD3_0                           ((uint32_t)0x00001000)        /*!< Bit 0 */
#define  GPIO_CTLR1_MD3_1                           ((uint32_t)0x00002000)        /*!< Bit 1 */

#define  GPIO_CTLR1_MD4                             ((uint32_t)0x00030000)        /*!< MODE4[1:0] bits (Port x mode bits, pin 4) */
#define  GPIO_CTLR1_MD4_0                           ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  GPIO_CTLR1_MD4_1                           ((uint32_t)0x00020000)        /*!< Bit 1 */
								         
#define  GPIO_CTLR1_MD5                             ((uint32_t)0x00300000)        /*!< MODE5[1:0] bits (Port x mode bits, pin 5) */
#define  GPIO_CTLR1_MD5_0                           ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  GPIO_CTLR1_MD5_1                           ((uint32_t)0x00200000)        /*!< Bit 1 */

#define  GPIO_CTLR1_MD6                             ((uint32_t)0x03000000)        /*!< MODE6[1:0] bits (Port x mode bits, pin 6) */
#define  GPIO_CTLR1_MD6_0                           ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  GPIO_CTLR1_MD6_1                           ((uint32_t)0x02000000)        /*!< Bit 1 */

#define  GPIO_CTLR1_MD7                             ((uint32_t)0x30000000)        /*!< MODE7[1:0] bits (Port x mode bits, pin 7) */
#define  GPIO_CTLR1_MD7_0                           ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  GPIO_CTLR1_MD7_1                           ((uint32_t)0x20000000)        /*!< Bit 1 */

#define  GPIO_CTLR1_CF                              ((uint32_t)0xCCCCCCCC)        /*!< Port x configuration bits */

#define  GPIO_CTLR1_CF0                             ((uint32_t)0x0000000C)        /*!< CNF0[1:0] bits (Port x configuration bits, pin 0) */
#define  GPIO_CTLR1_CF0_0                           ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  GPIO_CTLR1_CF0_1                           ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  GPIO_CTLR1_CF1                             ((uint32_t)0x000000C0)        /*!< CNF1[1:0] bits (Port x configuration bits, pin 1) */
#define  GPIO_CTLR1_CF1_0                           ((uint32_t)0x00000040)        /*!< Bit 0 */
#define  GPIO_CTLR1_CF1_1                           ((uint32_t)0x00000080)        /*!< Bit 1 */

#define  GPIO_CTLR1_CF2                             ((uint32_t)0x00000C00)        /*!< CNF2[1:0] bits (Port x configuration bits, pin 2) */
#define  GPIO_CTLR1_CF2_0                           ((uint32_t)0x00000400)        /*!< Bit 0 */
#define  GPIO_CTLR1_CF2_1                           ((uint32_t)0x00000800)        /*!< Bit 1 */

#define  GPIO_CTLR1_CF3                             ((uint32_t)0x0000C000)        /*!< CNF3[1:0] bits (Port x configuration bits, pin 3) */
#define  GPIO_CTLR1_CF3_0                           ((uint32_t)0x00004000)        /*!< Bit 0 */
#define  GPIO_CTLR1_CF3_1                           ((uint32_t)0x00008000)        /*!< Bit 1 */

#define  GPIO_CTLR1_CF4                             ((uint32_t)0x000C0000)        /*!< CNF4[1:0] bits (Port x configuration bits, pin 4) */
#define  GPIO_CTLR1_CF4_0                           ((uint32_t)0x00040000)        /*!< Bit 0 */
#define  GPIO_CTLR1_CF4_1                           ((uint32_t)0x00080000)        /*!< Bit 1 */

#define  GPIO_CTLR1_CF5                             ((uint32_t)0x00C00000)        /*!< CNF5[1:0] bits (Port x configuration bits, pin 5) */
#define  GPIO_CTLR1_CF5_0                           ((uint32_t)0x00400000)        /*!< Bit 0 */
#define  GPIO_CTLR1_CF5_1                           ((uint32_t)0x00800000)        /*!< Bit 1 */

#define  GPIO_CTLR1_CF6                             ((uint32_t)0x0C000000)        /*!< CNF6[1:0] bits (Port x configuration bits, pin 6) */
#define  GPIO_CTLR1_CF6_0                           ((uint32_t)0x04000000)        /*!< Bit 0 */
#define  GPIO_CTLR1_CF6_1                           ((uint32_t)0x08000000)        /*!< Bit 1 */

#define  GPIO_CTLR1_CF7                             ((uint32_t)0xC0000000)        /*!< CNF7[1:0] bits (Port x configuration bits, pin 7) */
#define  GPIO_CTLR1_CF7_0                           ((uint32_t)0x40000000)        /*!< Bit 0 */
#define  GPIO_CTLR1_CF7_1                           ((uint32_t)0x80000000)        /*!< Bit 1 */

/*******************  Bit definition for GPIO_CRH register  *******************/
#define  GPIO_CTLR2_MD                              ((uint32_t)0x33333333)        /*!< Port x mode bits */

#define  GPIO_CTLR2_MD8                             ((uint32_t)0x00000003)        /*!< MODE8[1:0] bits (Port x mode bits, pin 8) */
#define  GPIO_CTLR2_MD8_0                           ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  GPIO_CTLR2_MD8_1                           ((uint32_t)0x00000002)        /*!< Bit 1 */

#define  GPIO_CTLR2_MD9                             ((uint32_t)0x00000030)        /*!< MODE9[1:0] bits (Port x mode bits, pin 9) */
#define  GPIO_CTLR2_MD9_0                           ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  GPIO_CTLR2_MD9_1                           ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  GPIO_CTLR2_MD10                            ((uint32_t)0x00000300)        /*!< MODE10[1:0] bits (Port x mode bits, pin 10) */
#define  GPIO_CTLR2_MD10_0                          ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  GPIO_CTLR2_MD10_1                          ((uint32_t)0x00000200)        /*!< Bit 1 */

#define  GPIO_CTLR2_MD11                            ((uint32_t)0x00003000)        /*!< MODE11[1:0] bits (Port x mode bits, pin 11) */
#define  GPIO_CTLR2_MD11_0                          ((uint32_t)0x00001000)        /*!< Bit 0 */
#define  GPIO_CTLR2_MD11_1                          ((uint32_t)0x00002000)        /*!< Bit 1 */

#define  GPIO_CTLR2_MD12                            ((uint32_t)0x00030000)        /*!< MODE12[1:0] bits (Port x mode bits, pin 12) */
#define  GPIO_CTLR2_MD12_0                          ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  GPIO_CTLR2_MD12_1                          ((uint32_t)0x00020000)        /*!< Bit 1 */

#define  GPIO_CTLR2_MD13                            ((uint32_t)0x00300000)        /*!< MODE13[1:0] bits (Port x mode bits, pin 13) */
#define  GPIO_CTLR2_MD13_0                          ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  GPIO_CTLR2_MD13_1                          ((uint32_t)0x00200000)        /*!< Bit 1 */
                                             
#define  GPIO_CTLR2_MD14                            ((uint32_t)0x03000000)        /*!< MODE14[1:0] bits (Port x mode bits, pin 14) */
#define  GPIO_CTLR2_MD14_0                          ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  GPIO_CTLR2_MD14_1                          ((uint32_t)0x02000000)        /*!< Bit 1 */
							          
#define  GPIO_CTLR2_MD15                            ((uint32_t)0x30000000)        /*!< MODE15[1:0] bits (Port x mode bits, pin 15) */
#define  GPIO_CTLR2_MD15_0                          ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  GPIO_CTLR2_MD15_1                          ((uint32_t)0x20000000)        /*!< Bit 1 */


#define  GPIO_CTLR2_CF                              ((uint32_t)0xCCCCCCCC)        /*!< Port x configuration bits */

#define  GPIO_CTLR2_CF8                             ((uint32_t)0x0000000C)        /*!< CNF8[1:0] bits (Port x configuration bits, pin 8) */
#define  GPIO_CTLR2_CF8_0                           ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  GPIO_CTLR2_CF8_1                           ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  GPIO_CTLR2_CF9                             ((uint32_t)0x000000C0)        /*!< CNF9[1:0] bits (Port x configuration bits, pin 9) */
#define  GPIO_CTLR2_CF9_0                           ((uint32_t)0x00000040)        /*!< Bit 0 */
#define  GPIO_CTLR2_CF9_1                           ((uint32_t)0x00000080)        /*!< Bit 1 */

#define  GPIO_CTLR2_CF10                            ((uint32_t)0x00000C00)        /*!< CNF10[1:0] bits (Port x configuration bits, pin 10) */
#define  GPIO_CTLR2_CF10_0                          ((uint32_t)0x00000400)        /*!< Bit 0 */
#define  GPIO_CTLR2_CF10_1                          ((uint32_t)0x00000800)        /*!< Bit 1 */

#define  GPIO_CTLR2_CF11                            ((uint32_t)0x0000C000)        /*!< CNF11[1:0] bits (Port x configuration bits, pin 11) */
#define  GPIO_CTLR2_CF11_0                          ((uint32_t)0x00004000)        /*!< Bit 0 */
#define  GPIO_CTLR2_CF11_1                          ((uint32_t)0x00008000)        /*!< Bit 1 */

#define  GPIO_CTLR2_CF12                            ((uint32_t)0x000C0000)        /*!< CNF12[1:0] bits (Port x configuration bits, pin 12) */
#define  GPIO_CTLR2_CF12_0                          ((uint32_t)0x00040000)        /*!< Bit 0 */
#define  GPIO_CTLR2_CF12_1                          ((uint32_t)0x00080000)        /*!< Bit 1 */
                                             
#define  GPIO_CTLR2_CF13                            ((uint32_t)0x00C00000)        /*!< CNF13[1:0] bits (Port x configuration bits, pin 13) */
#define  GPIO_CTLR2_CF13_0                          ((uint32_t)0x00400000)        /*!< Bit 0 */
#define  GPIO_CTLR2_CF13_1                          ((uint32_t)0x00800000)        /*!< Bit 1 */
									       
#define  GPIO_CTLR2_CF14                            ((uint32_t)0x0C000000)        /*!< CNF14[1:0] bits (Port x configuration bits, pin 14) */
#define  GPIO_CTLR2_CF14_0                          ((uint32_t)0x04000000)        /*!< Bit 0 */
#define  GPIO_CTLR2_CF14_1                          ((uint32_t)0x08000000)        /*!< Bit 1 */

#define  GPIO_CTLR2_CF15                            ((uint32_t)0xC0000000)        /*!< CNF15[1:0] bits (Port x configuration bits, pin 15) */
#define  GPIO_CTLR2_CF15_0                          ((uint32_t)0x40000000)        /*!< Bit 0 */
#define  GPIO_CTLR2_CF15_1                          ((uint32_t)0x80000000)        /*!< Bit 1 */

/*!<******************  Bit definition for GPIO_DIR register  *******************/
#define  GPIO_DIR_DIR0                              ((uint16_t)0x0001)            /*!< Port input data, bit 0 */
#define  GPIO_DIR_DIR1                              ((uint16_t)0x0002)            /*!< Port input data, bit 1 */
#define  GPIO_DIR_DIR2                              ((uint16_t)0x0004)            /*!< Port input data, bit 2 */
#define  GPIO_DIR_DIR3                              ((uint16_t)0x0008)            /*!< Port input data, bit 3 */
#define  GPIO_DIR_DIR4                              ((uint16_t)0x0010)            /*!< Port input data, bit 4 */
#define  GPIO_DIR_DIR5                              ((uint16_t)0x0020)            /*!< Port input data, bit 5 */
#define  GPIO_DIR_DIR6                              ((uint16_t)0x0040)            /*!< Port input data, bit 6 */
#define  GPIO_DIR_DIR7                              ((uint16_t)0x0080)            /*!< Port input data, bit 7 */
#define  GPIO_DIR_DIR8                              ((uint16_t)0x0100)            /*!< Port input data, bit 8 */
#define  GPIO_DIR_DIR9                              ((uint16_t)0x0200)            /*!< Port input data, bit 9 */
#define  GPIO_DIR_DIR10                             ((uint16_t)0x0400)            /*!< Port input data, bit 10 */
#define  GPIO_DIR_DIR11                             ((uint16_t)0x0800)            /*!< Port input data, bit 11 */
#define  GPIO_DIR_DIR12                             ((uint16_t)0x1000)            /*!< Port input data, bit 12 */
#define  GPIO_DIR_DIR13                             ((uint16_t)0x2000)            /*!< Port input data, bit 13 */
#define  GPIO_DIR_DIR14                             ((uint16_t)0x4000)            /*!< Port input data, bit 14 */
#define  GPIO_DIR_DIR15                             ((uint16_t)0x8000)            /*!< Port input data, bit 15 */
								         
/*******************  Bit definition for GPIO_DOR register  *******************/
#define  GPIO_DOR_DOR0                              ((uint16_t)0x0001)            /*!< Port output data, bit 0 */
#define  GPIO_DOR_DOR1                              ((uint16_t)0x0002)            /*!< Port output data, bit 1 */
#define  GPIO_DOR_DOR2                              ((uint16_t)0x0004)            /*!< Port output data, bit 2 */
#define  GPIO_DOR_DOR3                              ((uint16_t)0x0008)            /*!< Port output data, bit 3 */
#define  GPIO_DOR_DOR4                              ((uint16_t)0x0010)            /*!< Port output data, bit 4 */
#define  GPIO_DOR_DOR5                              ((uint16_t)0x0020)            /*!< Port output data, bit 5 */
#define  GPIO_DOR_DOR6                              ((uint16_t)0x0040)            /*!< Port output data, bit 6 */
#define  GPIO_DOR_DOR7                              ((uint16_t)0x0080)            /*!< Port output data, bit 7 */
#define  GPIO_DOR_DOR8                              ((uint16_t)0x0100)            /*!< Port output data, bit 8 */
#define  GPIO_DOR_DOR9                              ((uint16_t)0x0200)            /*!< Port output data, bit 9 */
#define  GPIO_DOR_DOR10                             ((uint16_t)0x0400)            /*!< Port output data, bit 10 */
#define  GPIO_DOR_DOR11                             ((uint16_t)0x0800)            /*!< Port output data, bit 11 */
#define  GPIO_DOR_DOR12                             ((uint16_t)0x1000)            /*!< Port output data, bit 12 */
#define  GPIO_DOR_DOR13                             ((uint16_t)0x2000)            /*!< Port output data, bit 13 */
#define  GPIO_DOR_DOR14                             ((uint16_t)0x4000)            /*!< Port output data, bit 14 */
#define  GPIO_DOR_DOR15                             ((uint16_t)0x8000)            /*!< Port output data, bit 15 */

/******************  Bit definition for GPIO_BOR register  *******************/
#define  GPIO_BOR_BOR0                              ((uint32_t)0x00000001)        /*!< Port x Set bit 0 */
#define  GPIO_BOR_BOR1                              ((uint32_t)0x00000002)        /*!< Port x Set bit 1 */
#define  GPIO_BOR_BOR2                              ((uint32_t)0x00000004)        /*!< Port x Set bit 2 */
#define  GPIO_BOR_BOR3                              ((uint32_t)0x00000008)        /*!< Port x Set bit 3 */
#define  GPIO_BOR_BOR4                              ((uint32_t)0x00000010)        /*!< Port x Set bit 4 */
#define  GPIO_BOR_BOR5                              ((uint32_t)0x00000020)        /*!< Port x Set bit 5 */
#define  GPIO_BOR_BOR6                              ((uint32_t)0x00000040)        /*!< Port x Set bit 6 */
#define  GPIO_BOR_BOR7                              ((uint32_t)0x00000080)        /*!< Port x Set bit 7 */
#define  GPIO_BOR_BOR8                              ((uint32_t)0x00000100)        /*!< Port x Set bit 8 */
#define  GPIO_BOR_BOR9                              ((uint32_t)0x00000200)        /*!< Port x Set bit 9 */
#define  GPIO_BOR_BOR10                             ((uint32_t)0x00000400)        /*!< Port x Set bit 10 */
#define  GPIO_BOR_BOR11                             ((uint32_t)0x00000800)        /*!< Port x Set bit 11 */
#define  GPIO_BOR_BOR12                             ((uint32_t)0x00001000)        /*!< Port x Set bit 12 */
#define  GPIO_BOR_BOR13                             ((uint32_t)0x00002000)        /*!< Port x Set bit 13 */
#define  GPIO_BOR_BOR14                             ((uint32_t)0x00004000)        /*!< Port x Set bit 14 */
#define  GPIO_BOR_BOR15                             ((uint32_t)0x00008000)        /*!< Port x Set bit 15 */
                                               
#define  GPIO_BOR_COR0                              ((uint32_t)0x00010000)        /*!< Port x Reset bit 0 */
#define  GPIO_BOR_COR1                              ((uint32_t)0x00020000)        /*!< Port x Reset bit 1 */
#define  GPIO_BOR_COR2                              ((uint32_t)0x00040000)        /*!< Port x Reset bit 2 */
#define  GPIO_BOR_COR3                              ((uint32_t)0x00080000)        /*!< Port x Reset bit 3 */
#define  GPIO_BOR_COR4                              ((uint32_t)0x00100000)        /*!< Port x Reset bit 4 */
#define  GPIO_BOR_COR5                              ((uint32_t)0x00200000)        /*!< Port x Reset bit 5 */
#define  GPIO_BOR_COR6                              ((uint32_t)0x00400000)        /*!< Port x Reset bit 6 */
#define  GPIO_BOR_COR7                              ((uint32_t)0x00800000)        /*!< Port x Reset bit 7 */
#define  GPIO_BOR_COR8                              ((uint32_t)0x01000000)        /*!< Port x Reset bit 8 */
#define  GPIO_BOR_COR9                              ((uint32_t)0x02000000)        /*!< Port x Reset bit 9 */
#define  GPIO_BOR_COR10                             ((uint32_t)0x04000000)        /*!< Port x Reset bit 10 */
#define  GPIO_BOR_COR11                             ((uint32_t)0x08000000)        /*!< Port x Reset bit 11 */
#define  GPIO_BOR_COR12                             ((uint32_t)0x10000000)        /*!< Port x Reset bit 12 */
#define  GPIO_BOR_COR13                             ((uint32_t)0x20000000)        /*!< Port x Reset bit 13 */
#define  GPIO_BOR_COR14                             ((uint32_t)0x40000000)        /*!< Port x Reset bit 14 */
#define  GPIO_BOR_COR15                             ((uint32_t)0x80000000)        /*!< Port x Reset bit 15 */

/*******************  Bit definition for GPIO_BCR register  *******************/
#define  GPIO_BCR_BR0                               ((uint16_t)0x0001)            /*!< Port x Reset bit 0 */
#define  GPIO_BCR_BR1                               ((uint16_t)0x0002)            /*!< Port x Reset bit 1 */
#define  GPIO_BCR_BR2                               ((uint16_t)0x0004)            /*!< Port x Reset bit 2 */
#define  GPIO_BCR_BR3                               ((uint16_t)0x0008)            /*!< Port x Reset bit 3 */
#define  GPIO_BCR_BR4                               ((uint16_t)0x0010)            /*!< Port x Reset bit 4 */
#define  GPIO_BCR_BR5                               ((uint16_t)0x0020)            /*!< Port x Reset bit 5 */
#define  GPIO_BCR_BR6                               ((uint16_t)0x0040)            /*!< Port x Reset bit 6 */
#define  GPIO_BCR_BR7                               ((uint16_t)0x0080)            /*!< Port x Reset bit 7 */
#define  GPIO_BCR_BR8                               ((uint16_t)0x0100)            /*!< Port x Reset bit 8 */
#define  GPIO_BCR_BR9                               ((uint16_t)0x0200)            /*!< Port x Reset bit 9 */
#define  GPIO_BCR_BR10                              ((uint16_t)0x0400)            /*!< Port x Reset bit 10 */
#define  GPIO_BCR_BR11                              ((uint16_t)0x0800)            /*!< Port x Reset bit 11 */
#define  GPIO_BCR_BR12                              ((uint16_t)0x1000)            /*!< Port x Reset bit 12 */
#define  GPIO_BCR_BR13                              ((uint16_t)0x2000)            /*!< Port x Reset bit 13 */
#define  GPIO_BCR_BR14                              ((uint16_t)0x4000)            /*!< Port x Reset bit 14 */
#define  GPIO_BCR_BR15                              ((uint16_t)0x8000)            /*!< Port x Reset bit 15 */
		 
/******************  Bit definition for GPIO_LOCKR register  *******************/
#define  GPIO_LOCKR_LK0                             ((uint32_t)0x00000001)        /*!< Port x Lock bit 0 */
#define  GPIO_LOCKR_LK1                             ((uint32_t)0x00000002)        /*!< Port x Lock bit 1 */
#define  GPIO_LOCKR_LK2                             ((uint32_t)0x00000004)        /*!< Port x Lock bit 2 */
#define  GPIO_LOCKR_LK3                             ((uint32_t)0x00000008)        /*!< Port x Lock bit 3 */
#define  GPIO_LOCKR_LK4                             ((uint32_t)0x00000010)        /*!< Port x Lock bit 4 */
#define  GPIO_LOCKR_LK5                             ((uint32_t)0x00000020)        /*!< Port x Lock bit 5 */
#define  GPIO_LOCKR_LK6                             ((uint32_t)0x00000040)        /*!< Port x Lock bit 6 */
#define  GPIO_LOCKR_LK7                             ((uint32_t)0x00000080)        /*!< Port x Lock bit 7 */
#define  GPIO_LOCKR_LK8                             ((uint32_t)0x00000100)        /*!< Port x Lock bit 8 */
#define  GPIO_LOCKR_LK9                             ((uint32_t)0x00000200)        /*!< Port x Lock bit 9 */
#define  GPIO_LOCKR_LK10                            ((uint32_t)0x00000400)        /*!< Port x Lock bit 10 */
#define  GPIO_LOCKR_LK11                            ((uint32_t)0x00000800)        /*!< Port x Lock bit 11 */
#define  GPIO_LOCKR_LK12                            ((uint32_t)0x00001000)        /*!< Port x Lock bit 12 */
#define  GPIO_LOCKR_LK13                            ((uint32_t)0x00002000)        /*!< Port x Lock bit 13 */
#define  GPIO_LOCKR_LK14                            ((uint32_t)0x00004000)        /*!< Port x Lock bit 14 */
#define  GPIO_LOCKR_LK15                            ((uint32_t)0x00008000)        /*!< Port x Lock bit 15 */
#define  GPIO_LOCKR_LKK                             ((uint32_t)0x00010000)        /*!< Lock key */

/*----------------------------------------------------------------------------*/

/******************  Bit definition for AFIO_ECR register  *******************/
#define  AFIO_ECR_PIN                               ((uint8_t)0x0F)               /*!< PIN[3:0] bits (Pin selection) */
#define  AFIO_ECR_PIN_0                             ((uint8_t)0x01)               /*!< Bit 0 */
#define  AFIO_ECR_PIN_1                             ((uint8_t)0x02)               /*!< Bit 1 */
#define  AFIO_ECR_PIN_2                             ((uint8_t)0x04)               /*!< Bit 2 */
#define  AFIO_ECR_PIN_3                             ((uint8_t)0x08)               /*!< Bit 3 */

/*!< PIN configuration */
#define  AFIO_ECR_PIN_PX0                           ((uint8_t)0x00)               /*!< Pin 0 selected */
#define  AFIO_ECR_PIN_PX1                           ((uint8_t)0x01)               /*!< Pin 1 selected */
#define  AFIO_ECR_PIN_PX2                           ((uint8_t)0x02)               /*!< Pin 2 selected */
#define  AFIO_ECR_PIN_PX3                           ((uint8_t)0x03)               /*!< Pin 3 selected */
#define  AFIO_ECR_PIN_PX4                           ((uint8_t)0x04)               /*!< Pin 4 selected */
#define  AFIO_ECR_PIN_PX5                           ((uint8_t)0x05)               /*!< Pin 5 selected */
#define  AFIO_ECR_PIN_PX6                           ((uint8_t)0x06)               /*!< Pin 6 selected */
#define  AFIO_ECR_PIN_PX7                           ((uint8_t)0x07)               /*!< Pin 7 selected */
#define  AFIO_ECR_PIN_PX8                           ((uint8_t)0x08)               /*!< Pin 8 selected */
#define  AFIO_ECR_PIN_PX9                           ((uint8_t)0x09)               /*!< Pin 9 selected */
#define  AFIO_ECR_PIN_PX10                          ((uint8_t)0x0A)               /*!< Pin 10 selected */
#define  AFIO_ECR_PIN_PX11                          ((uint8_t)0x0B)               /*!< Pin 11 selected */
#define  AFIO_ECR_PIN_PX12                          ((uint8_t)0x0C)               /*!< Pin 12 selected */
#define  AFIO_ECR_PIN_PX13                          ((uint8_t)0x0D)               /*!< Pin 13 selected */
#define  AFIO_ECR_PIN_PX14                          ((uint8_t)0x0E)               /*!< Pin 14 selected */
#define  AFIO_ECR_PIN_PX15                          ((uint8_t)0x0F)               /*!< Pin 15 selected */

#define  AFIO_ECR_PORT                              ((uint8_t)0x70)               /*!< PORT[2:0] bits (Port selection) */
#define  AFIO_ECR_PORT_0                            ((uint8_t)0x10)               /*!< Bit 0 */
#define  AFIO_ECR_PORT_1                            ((uint8_t)0x20)               /*!< Bit 1 */
#define  AFIO_ECR_PORT_2                            ((uint8_t)0x40)               /*!< Bit 2 */

/*!< PORT configuration */
#define  AFIO_ECR_PORT_PA                           ((uint8_t)0x00)               /*!< Port A selected */
#define  AFIO_ECR_PORT_PB                           ((uint8_t)0x10)               /*!< Port B selected */
#define  AFIO_ECR_PORT_PC                           ((uint8_t)0x20)               /*!< Port C selected */
#define  AFIO_ECR_PORT_PD                           ((uint8_t)0x30)               /*!< Port D selected */
#define  AFIO_ECR_PORT_PE                           ((uint8_t)0x40)               /*!< Port E selected */

#define  AFIO_ECR_EOE                               ((uint8_t)0x80)               /*!< Event Output Enable */

/******************  Bit definition for AFIO_MAPR register  *******************/
#define  AFIO_PCFR1_SPI1_REMAP                      ((uint32_t)0x00000001)        /*!< SPI1 remapping */
#define  AFIO_PCFR1_I2C1_REMAP                      ((uint32_t)0x00000002)        /*!< I2C1 remapping */
#define  AFIO_PCFR1_USART1_REMAP                    ((uint32_t)0x00000004)        /*!< USART1 remapping */
#define  AFIO_PCFR1_USART2_REMAP                    ((uint32_t)0x00000008)        /*!< USART2 remapping */

#define  AFIO_PCFR1_USART3_REMAP                    ((uint32_t)0x00000030)        /*!< USART3_REMAP[1:0] bits (USART3 remapping) */
#define  AFIO_PCFR1_USART3_REMAP_0                  ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  AFIO_PCFR1_USART3_REMAP_1                  ((uint32_t)0x00000020)        /*!< Bit 1 */

/* USART3_REMAP configuration */
#define  AFIO_PCFR1_USART3_REMAP_NOREMAP            ((uint32_t)0x00000000)        /*!< No remap (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14) */
#define  AFIO_PCFR1_USART3_REMAP_PARTIALREMAP       ((uint32_t)0x00000010)        /*!< Partial remap (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14) */
#define  AFIO_PCFR1_USART3_REMAP_FULLREMAP          ((uint32_t)0x00000030)        /*!< Full remap (TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12) */
		 
#define  AFIO_PCFR1_TIM1_REMAP                      ((uint32_t)0x000000C0)        /*!< TIM1_REMAP[1:0] bits (TIM1 remapping) */
#define  AFIO_PCFR1_TIM1_REMAP_0                    ((uint32_t)0x00000040)        /*!< Bit 0 */
#define  AFIO_PCFR1_TIM1_REMAP_1                    ((uint32_t)0x00000080)        /*!< Bit 1 */

/*!< TIM1_REMAP configuration */
#define  AFIO_PCFR1_TIM1_REMAP_NOREMAP              ((uint32_t)0x00000000)        /*!< No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15) */
#define  AFIO_PCFR1_TIM1_REMAP_PARTIALREMAP         ((uint32_t)0x00000040)        /*!< Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1) */
#define  AFIO_PCFR1_TIM1_REMAP_FULLREMAP            ((uint32_t)0x000000C0)        /*!< Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12) */

#define  AFIO_PCFR1_TIM2_REMAP                      ((uint32_t)0x00000300)        /*!< TIM2_REMAP[1:0] bits (TIM2 remapping) */
#define  AFIO_PCFR1_TIM2_REMAP_0                    ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  AFIO_PCFR1_TIM2_REMAP_1                    ((uint32_t)0x00000200)        /*!< Bit 1 */

/*!< TIM2_REMAP configuration */
#define  AFIO_PCFR1_TIM2_REMAP_NOREMAP              ((uint32_t)0x00000000)        /*!< No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3) */
#define  AFIO_PCFR1_TIM2_REMAP_PARTIALREMAP1        ((uint32_t)0x00000100)        /*!< Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3) */
#define  AFIO_PCFR1_TIM2_REMAP_PARTIALREMAP2        ((uint32_t)0x00000200)        /*!< Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11) */
#define  AFIO_PCFR1_TIM2_REMAP_FULLREMAP            ((uint32_t)0x00000300)        /*!< Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11) */

#define  AFIO_PCFR1_TIM3_REMAP                      ((uint32_t)0x00000C00)        /*!< TIM3_REMAP[1:0] bits (TIM3 remapping) */
#define  AFIO_PCFR1_TIM3_REMAP_0                    ((uint32_t)0x00000400)        /*!< Bit 0 */
#define  AFIO_PCFR1_TIM3_REMAP_1                    ((uint32_t)0x00000800)        /*!< Bit 1 */

/*!< TIM3_REMAP configuration */
#define  AFIO_PCFR1_TIM3_REMAP_NOREMAP              ((uint32_t)0x00000000)        /*!< No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1) */
#define  AFIO_PCFR1_TIM3_REMAP_PARTIALREMAP         ((uint32_t)0x00000800)        /*!< Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1) */
#define  AFIO_PCFR1_TIM3_REMAP_FULLREMAP            ((uint32_t)0x00000C00)        /*!< Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9) */

#define  AFIO_PCFR1_TIM4_REMAP                      ((uint32_t)0x00001000)        /*!< TIM4_REMAP bit (TIM4 remapping) */

#define  AFIO_PCFR1_CAN_REMAP                       ((uint32_t)0x00006000)        /*!< CAN_REMAP[1:0] bits (CAN Alternate function remapping) */
#define  AFIO_PCFR1_CAN_REMAP_0                     ((uint32_t)0x00002000)        /*!< Bit 0 */
#define  AFIO_PCFR1_CAN_REMAP_1                     ((uint32_t)0x00004000)        /*!< Bit 1 */

/*!< CAN_REMAP configuration */
#define  AFIO_PCFR1_CAN_REMAP_REMAP1                ((uint32_t)0x00000000)        /*!< CANRX mapped to PA11, CANTX mapped to PA12 */
#define  AFIO_PCFR1_CAN_REMAP_REMAP2                ((uint32_t)0x00004000)        /*!< CANRX mapped to PB8, CANTX mapped to PB9 */
#define  AFIO_PCFR1_CAN_REMAP_REMAP3                ((uint32_t)0x00006000)        /*!< CANRX mapped to PD0, CANTX mapped to PD1 */

#define  AFIO_PCFR1_PD01_REMAP                      ((uint32_t)0x00008000)        /*!< Port D0/Port D1 mapping on OSC_IN/OSC_OUT */
#define  AFIO_PCFR1_TIM5CH4_IREMAP                  ((uint32_t)0x00010000)        /*!< TIM5 Channel4 Internal Remap */
#define  AFIO_PCFR1_ADC1_ETRGINJ_REMAP              ((uint32_t)0x00020000)        /*!< ADC 1 External Trigger Injected Conversion remapping */
#define  AFIO_PCFR1_ADC1_ETRGREG_REMAP              ((uint32_t)0x00040000)        /*!< ADC 1 External Trigger Regular Conversion remapping */
#define  AFIO_PCFR1_ADC2_ETRGINJ_REMAP              ((uint32_t)0x00080000)        /*!< ADC 2 External Trigger Injected Conversion remapping */
#define  AFIO_PCFR1_ADC2_ETRGREG_REMAP              ((uint32_t)0x00100000)        /*!< ADC 2 External Trigger Regular Conversion remapping */

/*!< SWJ_CFG configuration */
#define  AFIO_PCFR1_SWJ_CFG                         ((uint32_t)0x07000000)        /*!< SWJ_CFG[2:0] bits (Serial Wire JTAG configuration) */
#define  AFIO_PCFR1_SWJ_CFG_0                       ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  AFIO_PCFR1_SWJ_CFG_1                       ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  AFIO_PCFR1_SWJ_CFG_2                       ((uint32_t)0x04000000)        /*!< Bit 2 */
										      
#define  AFIO_PCFR1_SWJ_CFG_RESET                   ((uint32_t)0x00000000)        /*!< Full SWJ (JTAG-DP + SW-DP) : Reset State */
#define  AFIO_PCFR1_SWJ_CFG_NOJNTRST                ((uint32_t)0x01000000)        /*!< Full SWJ (JTAG-DP + SW-DP) but without JNTRST */
#define  AFIO_PCFR1_SWJ_CFG_JTAGDISABLE             ((uint32_t)0x02000000)        /*!< JTAG-DP Disabled and SW-DP Enabled */
#define  AFIO_PCFR1_SWJ_CFG_DISABLE                 ((uint32_t)0x04000000)        /*!< JTAG-DP Disabled and SW-DP Disabled */

#ifdef GD32F10X_CL
/*!< ETH_REMAP configuration */
#define  AFIO_PCFR1_ETH_REMAP                       ((uint32_t)0x00200000)        /*!< SPI3_REMAP bit (Ethernet MAC I/O remapping) */

/*!< CAN2_REMAP configuration */
#define  AFIO_PCFR1_CAN2_REMAP                      ((uint32_t)0x00400000)        /*!< CAN2_REMAP bit (CAN2 I/O remapping) */

/*!< MII_RMII_SEL configuration */
#define  AFIO_PCFR1_MII_RMII_SEL                    ((uint32_t)0x00800000)        /*!< MII_RMII_SEL bit (Ethernet MII or RMII selection) */

/*!< SPI3_REMAP configuration */
#define  AFIO_PCFR1_SPI3_REMAP                      ((uint32_t)0x10000000)        /*!< SPI3_REMAP bit (SPI3 remapping) */

/*!< TIM2ITR1_IREMAP configuration */
#define  AFIO_PCFR1_TIM2ITR1_IREMAP                 ((uint32_t)0x20000000)        /*!< TIM2ITR1_IREMAP bit (TIM2 internal trigger 1 remapping) */

/*!< PTP_PPS_REMAP configuration */
#define  AFIO_PCFR1_PTP_PPS_REMAP                   ((uint32_t)0x40000000)        /*!< PTP_PPS_REMAP bit (Ethernet PTP PPS remapping) */
#endif

/*****************  Bit definition for AFIO_EXTICR1 register  *****************/
#define  AFIO_ESSR1_EXTI0                           ((uint16_t)0x000F)            /*!< EXTI 0 configuration */
#define  AFIO_ESSR1_EXTI1                           ((uint16_t)0x00F0)            /*!< EXTI 1 configuration */
#define  AFIO_ESSR1_EXTI2                           ((uint16_t)0x0F00)            /*!< EXTI 2 configuration */
#define  AFIO_ESSR1_EXTI3                           ((uint16_t)0xF000)            /*!< EXTI 3 configuration */

/*!< EXTI0 configuration */
#define  AFIO_ESSR1_EXTI0_PA                        ((uint16_t)0x0000)            /*!< PA[0] pin */
#define  AFIO_ESSR1_EXTI0_PB                        ((uint16_t)0x0001)            /*!< PB[0] pin */
#define  AFIO_ESSR1_EXTI0_PC                        ((uint16_t)0x0002)            /*!< PC[0] pin */
#define  AFIO_ESSR1_EXTI0_PD                        ((uint16_t)0x0003)            /*!< PD[0] pin */
#define  AFIO_ESSR1_EXTI0_PE                        ((uint16_t)0x0004)            /*!< PE[0] pin */
#define  AFIO_ESSR1_EXTI0_PF                        ((uint16_t)0x0005)            /*!< PF[0] pin */
#define  AFIO_ESSR1_EXTI0_PG                        ((uint16_t)0x0006)            /*!< PG[0] pin */
		 
/*!< EXTI1 configuration */
#define  AFIO_ESSR1_EXTI1_PA                        ((uint16_t)0x0000)            /*!< PA[1] pin */
#define  AFIO_ESSR1_EXTI1_PB                        ((uint16_t)0x0010)            /*!< PB[1] pin */
#define  AFIO_ESSR1_EXTI1_PC                        ((uint16_t)0x0020)            /*!< PC[1] pin */
#define  AFIO_ESSR1_EXTI1_PD                        ((uint16_t)0x0030)            /*!< PD[1] pin */
#define  AFIO_ESSR1_EXTI1_PE                        ((uint16_t)0x0040)            /*!< PE[1] pin */
#define  AFIO_ESSR1_EXTI1_PF                        ((uint16_t)0x0050)            /*!< PF[1] pin */
#define  AFIO_ESSR1_EXTI1_PG                        ((uint16_t)0x0060)            /*!< PG[1] pin */
								       
/*!< EXTI2 configuration */  
#define  AFIO_ESSR1_EXTI2_PA                        ((uint16_t)0x0000)            /*!< PA[2] pin */
#define  AFIO_ESSR1_EXTI2_PB                        ((uint16_t)0x0100)            /*!< PB[2] pin */
#define  AFIO_ESSR1_EXTI2_PC                        ((uint16_t)0x0200)            /*!< PC[2] pin */
#define  AFIO_ESSR1_EXTI2_PD                        ((uint16_t)0x0300)            /*!< PD[2] pin */
#define  AFIO_ESSR1_EXTI2_PE                        ((uint16_t)0x0400)            /*!< PE[2] pin */
#define  AFIO_ESSR1_EXTI2_PF                        ((uint16_t)0x0500)            /*!< PF[2] pin */
#define  AFIO_ESSR1_EXTI2_PG                        ((uint16_t)0x0600)            /*!< PG[2] pin */

/*!< EXTI3 configuration */
#define  AFIO_ESSR1_EXTI3_PA                        ((uint16_t)0x0000)            /*!< PA[3] pin */
#define  AFIO_ESSR1_EXTI3_PB                        ((uint16_t)0x1000)            /*!< PB[3] pin */
#define  AFIO_ESSR1_EXTI3_PC                        ((uint16_t)0x2000)            /*!< PC[3] pin */
#define  AFIO_ESSR1_EXTI3_PD                        ((uint16_t)0x3000)            /*!< PD[3] pin */
#define  AFIO_ESSR1_EXTI3_PE                        ((uint16_t)0x4000)            /*!< PE[3] pin */
#define  AFIO_ESSR1_EXTI3_PF                        ((uint16_t)0x5000)            /*!< PF[3] pin */
#define  AFIO_ESSR1_EXTI3_PG                        ((uint16_t)0x6000)            /*!< PG[3] pin */

/*****************  Bit definition for AFIO_EXTICR2 register  *****************/
#define  AFIO_ESSR2_EXTI4                           ((uint16_t)0x000F)            /*!< EXTI 4 configuration */
#define  AFIO_ESSR2_EXTI5                           ((uint16_t)0x00F0)            /*!< EXTI 5 configuration */
#define  AFIO_ESSR2_EXTI6                           ((uint16_t)0x0F00)            /*!< EXTI 6 configuration */
#define  AFIO_ESSR2_EXTI7                           ((uint16_t)0xF000)            /*!< EXTI 7 configuration */

/*!< EXTI4 configuration */
#define  AFIO_ESSR2_EXTI4_PA                        ((uint16_t)0x0000)            /*!< PA[4] pin */
#define  AFIO_ESSR2_EXTI4_PB                        ((uint16_t)0x0001)            /*!< PB[4] pin */
#define  AFIO_ESSR2_EXTI4_PC                        ((uint16_t)0x0002)            /*!< PC[4] pin */
#define  AFIO_ESSR2_EXTI4_PD                        ((uint16_t)0x0003)            /*!< PD[4] pin */
#define  AFIO_ESSR2_EXTI4_PE                        ((uint16_t)0x0004)            /*!< PE[4] pin */
#define  AFIO_ESSR2_EXTI4_PF                        ((uint16_t)0x0005)            /*!< PF[4] pin */
#define  AFIO_ESSR2_EXTI4_PG                        ((uint16_t)0x0006)            /*!< PG[4] pin */

/* EXTI5 configuration */
#define  AFIO_ESSR2_EXTI5_PA                        ((uint16_t)0x0000)            /*!< PA[5] pin */
#define  AFIO_ESSR2_EXTI5_PB                        ((uint16_t)0x0010)            /*!< PB[5] pin */
#define  AFIO_ESSR2_EXTI5_PC                        ((uint16_t)0x0020)            /*!< PC[5] pin */
#define  AFIO_ESSR2_EXTI5_PD                        ((uint16_t)0x0030)            /*!< PD[5] pin */
#define  AFIO_ESSR2_EXTI5_PE                        ((uint16_t)0x0040)            /*!< PE[5] pin */
#define  AFIO_ESSR2_EXTI5_PF                        ((uint16_t)0x0050)            /*!< PF[5] pin */
#define  AFIO_ESSR2_EXTI5_PG                        ((uint16_t)0x0060)            /*!< PG[5] pin */

/*!< EXTI6 configuration */  
#define  AFIO_ESSR2_EXTI6_PA                        ((uint16_t)0x0000)            /*!< PA[6] pin */
#define  AFIO_ESSR2_EXTI6_PB                        ((uint16_t)0x0100)            /*!< PB[6] pin */
#define  AFIO_ESSR2_EXTI6_PC                        ((uint16_t)0x0200)            /*!< PC[6] pin */
#define  AFIO_ESSR2_EXTI6_PD                        ((uint16_t)0x0300)            /*!< PD[6] pin */
#define  AFIO_ESSR2_EXTI6_PE                        ((uint16_t)0x0400)            /*!< PE[6] pin */
#define  AFIO_ESSR2_EXTI6_PF                        ((uint16_t)0x0500)            /*!< PF[6] pin */
#define  AFIO_ESSR2_EXTI6_PG                        ((uint16_t)0x0600)            /*!< PG[6] pin */

/*!< EXTI7 configuration */
#define  AFIO_ESSR2_EXTI7_PA                        ((uint16_t)0x0000)            /*!< PA[7] pin */
#define  AFIO_ESSR2_EXTI7_PB                        ((uint16_t)0x1000)            /*!< PB[7] pin */
#define  AFIO_ESSR2_EXTI7_PC                        ((uint16_t)0x2000)            /*!< PC[7] pin */
#define  AFIO_ESSR2_EXTI7_PD                        ((uint16_t)0x3000)            /*!< PD[7] pin */
#define  AFIO_ESSR2_EXTI7_PE                        ((uint16_t)0x4000)            /*!< PE[7] pin */
#define  AFIO_ESSR2_EXTI7_PF                        ((uint16_t)0x5000)            /*!< PF[7] pin */
#define  AFIO_ESSR2_EXTI7_PG                        ((uint16_t)0x6000)            /*!< PG[7] pin */

/*****************  Bit definition for AFIO_EXTICR3 register  *****************/
#define  AFIO_ESSR3_EXTI8                           ((uint16_t)0x000F)            /*!< EXTI 8 configuration */
#define  AFIO_ESSR3_EXTI9                           ((uint16_t)0x00F0)            /*!< EXTI 9 configuration */
#define  AFIO_ESSR3_EXTI10                          ((uint16_t)0x0F00)            /*!< EXTI 10 configuration */
#define  AFIO_ESSR3_EXTI11                          ((uint16_t)0xF000)            /*!< EXTI 11 configuration */

/*!< EXTI8 configuration */
#define  AFIO_ESSR3_EXTI8_PA                        ((uint16_t)0x0000)            /*!< PA[8] pin */
#define  AFIO_ESSR3_EXTI8_PB                        ((uint16_t)0x0001)            /*!< PB[8] pin */
#define  AFIO_ESSR3_EXTI8_PC                        ((uint16_t)0x0002)            /*!< PC[8] pin */
#define  AFIO_ESSR3_EXTI8_PD                        ((uint16_t)0x0003)            /*!< PD[8] pin */
#define  AFIO_ESSR3_EXTI8_PE                        ((uint16_t)0x0004)            /*!< PE[8] pin */
#define  AFIO_ESSR3_EXTI8_PF                        ((uint16_t)0x0005)            /*!< PF[8] pin */
#define  AFIO_ESSR3_EXTI8_PG                        ((uint16_t)0x0006)            /*!< PG[8] pin */

/*!< EXTI9 configuration */
#define  AFIO_ESSR3_EXTI9_PA                        ((uint16_t)0x0000)            /*!< PA[9] pin */
#define  AFIO_ESSR3_EXTI9_PB                        ((uint16_t)0x0010)            /*!< PB[9] pin */
#define  AFIO_ESSR3_EXTI9_PC                        ((uint16_t)0x0020)            /*!< PC[9] pin */
#define  AFIO_ESSR3_EXTI9_PD                        ((uint16_t)0x0030)            /*!< PD[9] pin */
#define  AFIO_ESSR3_EXTI9_PE                        ((uint16_t)0x0040)            /*!< PE[9] pin */
#define  AFIO_ESSR3_EXTI9_PF                        ((uint16_t)0x0050)            /*!< PF[9] pin */
#define  AFIO_ESSR3_EXTI9_PG                        ((uint16_t)0x0060)            /*!< PG[9] pin */

/*!< EXTI10 configuration */  
#define  AFIO_ESSR3_EXTI10_PA                       ((uint16_t)0x0000)            /*!< PA[10] pin */
#define  AFIO_ESSR3_EXTI10_PB                       ((uint16_t)0x0100)            /*!< PB[10] pin */
#define  AFIO_ESSR3_EXTI10_PC                       ((uint16_t)0x0200)            /*!< PC[10] pin */
#define  AFIO_ESSR3_EXTI10_PD                       ((uint16_t)0x0300)            /*!< PD[10] pin */
#define  AFIO_ESSR3_EXTI10_PE                       ((uint16_t)0x0400)            /*!< PE[10] pin */
#define  AFIO_ESSR3_EXTI10_PF                       ((uint16_t)0x0500)            /*!< PF[10] pin */
#define  AFIO_ESSR3_EXTI10_PG                       ((uint16_t)0x0600)            /*!< PG[10] pin */

/*!< EXTI11 configuration */
#define  AFIO_ESSR3_EXTI11_PA                       ((uint16_t)0x0000)            /*!< PA[11] pin */
#define  AFIO_ESSR3_EXTI11_PB                       ((uint16_t)0x1000)            /*!< PB[11] pin */
#define  AFIO_ESSR3_EXTI11_PC                       ((uint16_t)0x2000)            /*!< PC[11] pin */
#define  AFIO_ESSR3_EXTI11_PD                       ((uint16_t)0x3000)            /*!< PD[11] pin */
#define  AFIO_ESSR3_EXTI11_PE                       ((uint16_t)0x4000)            /*!< PE[11] pin */
#define  AFIO_ESSR3_EXTI11_PF                       ((uint16_t)0x5000)            /*!< PF[11] pin */
#define  AFIO_ESSR3_EXTI11_PG                       ((uint16_t)0x6000)            /*!< PG[11] pin */

/*****************  Bit definition for AFIO_EXTICR4 register  *****************/
#define  AFIO_ESSR4_EXTI12                          ((uint16_t)0x000F)            /*!< EXTI 12 configuration */
#define  AFIO_ESSR4_EXTI13                          ((uint16_t)0x00F0)            /*!< EXTI 13 configuration */
#define  AFIO_ESSR4_EXTI14                          ((uint16_t)0x0F00)            /*!< EXTI 14 configuration */
#define  AFIO_ESSR4_EXTI15                          ((uint16_t)0xF000)            /*!< EXTI 15 configuration */

/* EXTI12 configuration */
#define  AFIO_ESSR4_EXTI12_PA                       ((uint16_t)0x0000)            /*!< PA[12] pin */
#define  AFIO_ESSR4_EXTI12_PB                       ((uint16_t)0x0001)            /*!< PB[12] pin */
#define  AFIO_ESSR4_EXTI12_PC                       ((uint16_t)0x0002)            /*!< PC[12] pin */
#define  AFIO_ESSR4_EXTI12_PD                       ((uint16_t)0x0003)            /*!< PD[12] pin */
#define  AFIO_ESSR4_EXTI12_PE                       ((uint16_t)0x0004)            /*!< PE[12] pin */
#define  AFIO_ESSR4_EXTI12_PF                       ((uint16_t)0x0005)            /*!< PF[12] pin */
#define  AFIO_ESSR4_EXTI12_PG                       ((uint16_t)0x0006)            /*!< PG[12] pin */

/* EXTI13 configuration */
#define  AFIO_ESSR4_EXTI13_PA                       ((uint16_t)0x0000)            /*!< PA[13] pin */
#define  AFIO_ESSR4_EXTI13_PB                       ((uint16_t)0x0010)            /*!< PB[13] pin */
#define  AFIO_ESSR4_EXTI13_PC                       ((uint16_t)0x0020)            /*!< PC[13] pin */
#define  AFIO_ESSR4_EXTI13_PD                       ((uint16_t)0x0030)            /*!< PD[13] pin */
#define  AFIO_ESSR4_EXTI13_PE                       ((uint16_t)0x0040)            /*!< PE[13] pin */
#define  AFIO_ESSR4_EXTI13_PF                       ((uint16_t)0x0050)            /*!< PF[13] pin */
#define  AFIO_ESSR4_EXTI13_PG                       ((uint16_t)0x0060)            /*!< PG[13] pin */

/*!< EXTI14 configuration */  
#define  AFIO_ESSR4_EXTI14_PA                       ((uint16_t)0x0000)            /*!< PA[14] pin */
#define  AFIO_ESSR4_EXTI14_PB                       ((uint16_t)0x0100)            /*!< PB[14] pin */
#define  AFIO_ESSR4_EXTI14_PC                       ((uint16_t)0x0200)            /*!< PC[14] pin */
#define  AFIO_ESSR4_EXTI14_PD                       ((uint16_t)0x0300)            /*!< PD[14] pin */
#define  AFIO_ESSR4_EXTI14_PE                       ((uint16_t)0x0400)            /*!< PE[14] pin */
#define  AFIO_ESSR4_EXTI14_PF                       ((uint16_t)0x0500)            /*!< PF[14] pin */
#define  AFIO_ESSR4_EXTI14_PG                       ((uint16_t)0x0600)            /*!< PG[14] pin */

/*!< EXTI15 configuration */
#define  AFIO_ESSR4_EXTI15_PA                       ((uint16_t)0x0000)            /*!< PA[15] pin */
#define  AFIO_ESSR4_EXTI15_PB                       ((uint16_t)0x1000)            /*!< PB[15] pin */
#define  AFIO_ESSR4_EXTI15_PC                       ((uint16_t)0x2000)            /*!< PC[15] pin */
#define  AFIO_ESSR4_EXTI15_PD                       ((uint16_t)0x3000)            /*!< PD[15] pin */
#define  AFIO_ESSR4_EXTI15_PE                       ((uint16_t)0x4000)            /*!< PE[15] pin */
#define  AFIO_ESSR4_EXTI15_PF                       ((uint16_t)0x5000)            /*!< PF[15] pin */
#define  AFIO_ESSR4_EXTI15_PG                       ((uint16_t)0x6000)            /*!< PG[15] pin */


#if defined (GD32F10X_MD) || defined (GD32F10X_HD)
/******************  Bit definition for AFIO_MAPR2 register  ******************/
#define  AFIO_PCFR2_TIM15_REMAP                     ((uint32_t)0x00000001)        /*!< TIM15 remapping */
#define  AFIO_PCFR2_TIM16_REMAP                     ((uint32_t)0x00000002)        /*!< TIM16 remapping */
#define  AFIO_PCFR2_TIM17_REMAP                     ((uint32_t)0x00000004)        /*!< TIM17 remapping */
#define  AFIO_PCFR2_CEC_REMAP                       ((uint32_t)0x00000008)        /*!< CEC remapping */
#define  AFIO_PCFR2_TIM1_DMA_REMAP                  ((uint32_t)0x00000010)        /*!< TIM1_DMA remapping */
#endif

#ifdef   GD32F10X_HD
#define  AFIO_PCFR2_TIM13_REMAP                     ((uint32_t)0x00000100)        /*!< TIM13 remapping */
#define  AFIO_PCFR2_TIM14_REMAP                     ((uint32_t)0x00000200)        /*!< TIM14 remapping */
#define  AFIO_PCFR2_EXMC_NADV_REMAP                 ((uint32_t)0x00000400)        /*!< EXMC NADV remapping */
#define  AFIO_PCFR2_TIM67_DAC_DMA_REMAP             ((uint32_t)0x00000800)        /*!< TIM6/TIM7 and DAC DMA remapping */
#define  AFIO_PCFR2_TIM12_REMAP                     ((uint32_t)0x00001000)        /*!< TIM12 remapping */
#define  AFIO_PCFR2_MISC_REMAP                      ((uint32_t)0x00002000)        /*!< Miscellaneous remapping */
#endif

#ifdef   GD32F10X_XD 
/******************  Bit definition for AFIO_MAPR2 register  ******************/
#define  AFIO_PCFR2_TIM9_REMAP                      ((uint32_t)0x00000020)        /*!< TIM9 remapping */
#define  AFIO_PCFR2_TIM10_REMAP                     ((uint32_t)0x00000040)        /*!< TIM10 remapping */
#define  AFIO_PCFR2_TIM11_REMAP                     ((uint32_t)0x00000080)        /*!< TIM11 remapping */
#define  AFIO_PCFR2_TIM13_REMAP                     ((uint32_t)0x00000100)        /*!< TIM13 remapping */
#define  AFIO_PCFR2_TIM14_REMAP                     ((uint32_t)0x00000200)        /*!< TIM14 remapping */
#define  AFIO_PCFR2_EXMC_NADV_REMAP                 ((uint32_t)0x00000400)        /*!< EXMC NADV remapping */
#endif

/******************************************************************************/
/*                                                                            */
/*                        Independent WATCHDOG (IWDG)                         */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for IWDG_CTLR register  ******************/
#define  IWDG_CTLR_CT                               ((uint16_t)0xFFFF)            /*!< Key value (write only, read 0000h) */

/*******************  Bit definition for IWDG_PSR register  ********************/
#define  IWDG_PSR_PS                                ((uint8_t)0x07)               /*!< PS[2:0] (Prescaler divider) */
#define  IWDG_PSR_PS_0                              ((uint8_t)0x01)               /*!< Bit 0 */
#define  IWDG_PSR_PS_1                              ((uint8_t)0x02)               /*!< Bit 1 */
#define  IWDG_PSR_PS_2                              ((uint8_t)0x04)               /*!< Bit 2 */

/*******************  Bit definition for IWDG_RLDR register  *******************/
#define  IWDG_RLDR_RLD                              ((uint16_t)0x0FFF)            /*!< Watchdog counter reload value */

/*******************  Bit definition for IWDG_STR register  ********************/
#define  IWDG_STR_PUD                               ((uint8_t)0x01)               /*!< Watchdog prescaler value update */
#define  IWDG_STR_RUD                               ((uint8_t)0x02)               /*!< Watchdog counter reload value update */
#define  IWDG_STR_WUD                               ((uint8_t)0x04)               /*!< Watchdog counter window value update */


/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for PWR_CTLR register  ********************/
#define  PWR_CTLR_LDOLP                             ((uint16_t)0x0001)     /*!< LDO Low Power Mode */
#define  PWR_CTLR_SDBM                              ((uint16_t)0x0002)     /*!< Standby Mode */
#define  PWR_CTLR_WUFR                              ((uint16_t)0x0004)     /*!< Wakeup Flag Reset */
#define  PWR_CTLR_SBFR                              ((uint16_t)0x0008)     /*!< Standby Flag Reset */
#define  PWR_CTLR_LVDE                              ((uint16_t)0x0010)     /*!< Low Voltage Detector Enable */

#define  PWR_CTLR_LVDT                              ((uint16_t)0x00E0)     /*!< LVDT[2:0] bits (Low Voltage Detector Threshold) */
#define  PWR_CTLR_LVDT_0                            ((uint16_t)0x0020)     /*!< Bit 0 */
#define  PWR_CTLR_LVDT_1                            ((uint16_t)0x0040)     /*!< Bit 1 */
#define  PWR_CTLR_LVDT_2                            ((uint16_t)0x0080)     /*!< Bit 2 */

/*!< LVDT configuration */
#define  PWR_CTLR_LVDT_2V2                          ((uint16_t)0x0000)     /*!< LVDT is 2.2V */
#define  PWR_CTLR_LVDT_2V3                          ((uint16_t)0x0020)     /*!< LVDT is 2.3V */
#define  PWR_CTLR_LVDT_2V4                          ((uint16_t)0x0040)     /*!< LVDT is 2.4V */
#define  PWR_CTLR_LVDT_2V5                          ((uint16_t)0x0060)     /*!< LVDT is 2.5V */
#define  PWR_CTLR_LVDT_2V6                          ((uint16_t)0x0080)     /*!< LVDT is 2.6V */
#define  PWR_CTLR_LVDT_2V7                          ((uint16_t)0x00A0)     /*!< LVDT is 2.7V */
#define  PWR_CTLR_LVDT_2V8                          ((uint16_t)0x00C0)     /*!< LVDT is 2.8V */
#define  PWR_CTLR_LVDT_2V9                          ((uint16_t)0x00E0)     /*!< LVDT is 2.9V */
								        
#define  PWR_CTLR_BKPWE                             ((uint16_t)0x0100)     /*!< Backup Domain Write Enable */

/*******************  Bit definition for PWR_STR register  ********************/
#define  PWR_STR_WUF                                ((uint16_t)0x0001)     /*!< Wakeup Flag */
#define  PWR_STR_SBF                                ((uint16_t)0x0002)     /*!< Standby Flag */
#define  PWR_STR_LVDF                               ((uint16_t)0x0004)     /*!< Low Voltage Detector Status Flag */
#define  PWR_STR_WUPE                               ((uint16_t)0x0100)     /*!< WKUP Pin Enable */

///******************************************************************************/
///*                                                                            */
///*                         Reset and Clock Control                            */
///*                                                                            */
///******************************************************************************/

///********************  Bit definition for RCC_GCCR register  ********************/
//#define  RCC_GCCR_HSIEN                             ((uint32_t)0x00000001)        /*!< Internal High Speed clock enable */
//#define  RCC_GCCR_HSISTB                            ((uint32_t)0x00000002)        /*!< Internal High Speed clock ready flag */
//#define  RCC_GCCR_HSIADJ                            ((uint32_t)0x000000F8)        /*!< Internal High Speed clock trimming */
//#define  RCC_GCCR_HSICALIB                          ((uint32_t)0x0000FF00)        /*!< Internal High Speed clock Calibration */
//#define  RCC_GCCR_HSEEN                             ((uint32_t)0x00010000)        /*!< External High Speed clock enable */
//#define  RCC_GCCR_HSESTB                            ((uint32_t)0x00020000)        /*!< External High Speed clock ready flag */
//#define  RCC_GCCR_HSEBPS                            ((uint32_t)0x00040000)        /*!< External High Speed clock Bypass */
//#define  RCC_GCCR_CKMEN                             ((uint32_t)0x00080000)        /*!< Clock Security System enable */
//#define  RCC_GCCR_PLLEN                             ((uint32_t)0x01000000)        /*!< PLL enable */
//#define  RCC_GCCR_PLLSTB                            ((uint32_t)0x02000000)        /*!< PLL clock ready flag */

//#ifdef GD32F10X_CL
//#define  RCC_GCCR_PLL2EN                            ((uint32_t)0x04000000)        /*!< PLL2 enable */
//#define  RCC_GCCR_PLL2STB                           ((uint32_t)0x08000000)        /*!< PLL2 clock ready flag */
//#define  RCC_GCCR_PLL3EN                            ((uint32_t)0x10000000)        /*!< PLL3 enable */
//#define  RCC_GCCR_PLL3STB                           ((uint32_t)0x20000000)        /*!< PLL3 clock ready flag */
//#endif /* GD32F10X_CL */

///*******************  Bit definition for RCC_GCFGR register  *******************/
///*!< SW configuration */
//#define  RCC_GCFGR_SCS                              ((uint32_t)0x00000003)        /*!< SCS[1:0] bits (System clock Switch) */
//#define  RCC_GCFGR_SCS_0                            ((uint32_t)0x00000001)        /*!< Bit 0 */
//#define  RCC_GCFGR_SCS_1                            ((uint32_t)0x00000002)        /*!< Bit 1 */

//#define  RCC_GCFGR_SCS_HSI                          ((uint32_t)0x00000000)        /*!< HSI selected as system clock */
//#define  RCC_GCFGR_SCS_HSE                          ((uint32_t)0x00000001)        /*!< HSE selected as system clock */
//#define  RCC_GCFGR_SCS_PLL                          ((uint32_t)0x00000002)        /*!< PLL selected as system clock */

///*!< SWS configuration */
//#define  RCC_GCFGR_SCSS                             ((uint32_t)0x0000000C)        /*!< SCSS[1:0] bits (System Clock Switch Status) */
//#define  RCC_GCFGR_SCSS_0                           ((uint32_t)0x00000004)        /*!< Bit 0 */
//#define  RCC_GCFGR_SCSS_1                           ((uint32_t)0x00000008)        /*!< Bit 1 */

//#define  RCC_GCFGR_SCSS_HSI                         ((uint32_t)0x00000000)        /*!< HSI oscillator used as system clock */
//#define  RCC_GCFGR_SCSS_HSE                         ((uint32_t)0x00000004)        /*!< HSE oscillator used as system clock */
//#define  RCC_GCFGR_SCSS_PLL                         ((uint32_t)0x00000008)        /*!< PLL used as system clock */

///*!< AHBPS configuration */
//#define  RCC_GCFGR_AHBPS                            ((uint32_t)0x000000F0)        /*!< AHBPS[3:0] bits (AHB prescaler) */
//#define  RCC_GCFGR_AHBPS_0                          ((uint32_t)0x00000010)        /*!< Bit 0 */
//#define  RCC_GCFGR_AHBPS_1                          ((uint32_t)0x00000020)        /*!< Bit 1 */
//#define  RCC_GCFGR_AHBPS_2                          ((uint32_t)0x00000040)        /*!< Bit 2 */
//#define  RCC_GCFGR_AHBPS_3                          ((uint32_t)0x00000080)        /*!< Bit 3 */

//#define  RCC_GCFGR_AHBPS_DIV1                       ((uint32_t)0x00000000)        /*!< SYSCLK not divided */
//#define  RCC_GCFGR_AHBPS_DIV2                       ((uint32_t)0x00000080)        /*!< SYSCLK divided by 2 */
//#define  RCC_GCFGR_AHBPS_DIV4                       ((uint32_t)0x00000090)        /*!< SYSCLK divided by 4 */
//#define  RCC_GCFGR_AHBPS_DIV8                       ((uint32_t)0x000000A0)        /*!< SYSCLK divided by 8 */
//#define  RCC_GCFGR_AHBPS_DIV16                      ((uint32_t)0x000000B0)        /*!< SYSCLK divided by 16 */
//#define  RCC_GCFGR_AHBPS_DIV64                      ((uint32_t)0x000000C0)        /*!< SYSCLK divided by 64 */
//#define  RCC_GCFGR_AHBPS_DIV128                     ((uint32_t)0x000000D0)        /*!< SYSCLK divided by 128 */
//#define  RCC_GCFGR_AHBPS_DIV256                     ((uint32_t)0x000000E0)        /*!< SYSCLK divided by 256 */
//#define  RCC_GCFGR_AHBPS_DIV512                     ((uint32_t)0x000000F0)        /*!< SYSCLK divided by 512 */
									        
///*!< APB1PS configuration */
//#define  RCC_GCFGR_APB1PS                           ((uint32_t)0x00000700)        /*!< APB1PS[2:0] bits (APB1 prescaler) */
//#define  RCC_GCFGR_APB1PS_0                         ((uint32_t)0x00000100)        /*!< Bit 0 */
//#define  RCC_GCFGR_APB1PS_1                         ((uint32_t)0x00000200)        /*!< Bit 1 */
//#define  RCC_GCFGR_APB1PS_2                         ((uint32_t)0x00000400)        /*!< Bit 2 */

//#define  RCC_GCFGR_APB1PS_DIV1                      ((uint32_t)0x00000000)        /*!< AHB not divided */
//#define  RCC_GCFGR_APB1PS_DIV2                      ((uint32_t)0x00000400)        /*!< AHB divided by 2 */
//#define  RCC_GCFGR_APB1PS_DIV4                      ((uint32_t)0x00000500)        /*!< AHB divided by 4 */
//#define  RCC_GCFGR_APB1PS_DIV8                      ((uint32_t)0x00000600)        /*!< AHB divided by 8 */
//#define  RCC_GCFGR_APB1PS_DIV16                     ((uint32_t)0x00000700)        /*!< AHB divided by 16 */

///*!< APB2PS configuration */
//#define  RCC_GCFGR_APB2PS                           ((uint32_t)0x00003800)        /*!< APB2PS[2:0] bits (APB2 prescaler) */
//#define  RCC_GCFGR_APB2PS_0                         ((uint32_t)0x00000800)        /*!< Bit 0 */
//#define  RCC_GCFGR_APB2PS_1                         ((uint32_t)0x00001000)        /*!< Bit 1 */
//#define  RCC_GCFGR_APB2PS_2                         ((uint32_t)0x00002000)        /*!< Bit 2 */

//#define  RCC_GCFGR_APB2PS_DIV1                      ((uint32_t)0x00000000)        /*!< AHB not divided */
//#define  RCC_GCFGR_APB2PS_DIV2                      ((uint32_t)0x00002000)        /*!< AHB divided by 2 */
//#define  RCC_GCFGR_APB2PS_DIV4                      ((uint32_t)0x00002800)        /*!< AHB divided by 4 */
//#define  RCC_GCFGR_APB2PS_DIV8                      ((uint32_t)0x00003000)        /*!< AHB divided by 8 */
//#define  RCC_GCFGR_APB2PS_DIV16                     ((uint32_t)0x00003800)        /*!< AHB divided by 16 */

///*!< ADCPS configuration */
//#define  RCC_GCFGR_ADCPS                            ((uint32_t)0x1000C000)        /*!< ADCPS[2:0] bits (ADC prescaler) */
//#define  RCC_GCFGR_ADCPS_0                          ((uint32_t)0x00004000)        /*!< Bit 0 */
//#define  RCC_GCFGR_ADCPS_1                          ((uint32_t)0x00008000)        /*!< Bit 1 */
//#define  RCC_GCFGR_ADCPS_2                          ((uint32_t)0x10000000)        /*!< Bit 2 */
									       
//#define  RCC_GCFGR_ADCPS_DIV2                       ((uint32_t)0x00000000)        /*!< APB2 divided by 2 */
//#define  RCC_GCFGR_ADCPS_DIV4                       ((uint32_t)0x00004000)        /*!< APB2 divided by 4 */
//#define  RCC_GCFGR_ADCPS_DIV6                       ((uint32_t)0x00008000)        /*!< APB2 divided by 6 */
//#define  RCC_GCFGR_ADCPS_DIV8                       ((uint32_t)0x0000C000)        /*!< APB2 divided by 8 */
//#define  RCC_GCFGR_ADCPS_DIV12                      ((uint32_t)0x10004000)        /*!< APB2 divided by 12 */
//#define  RCC_GCFGR_ADCPS_DIV16                      ((uint32_t)0x1000C000)        /*!< APB2 divided by 16 */

#ifdef GD32F10X_CL
///*!< PLLSEL configuration */
//#define  RCC_GCFGR_PLLSEL                           ((uint32_t)0x00010000)        /*!< PLLSEL bit for entry clock source */
//#define  RCC_GCFGR_PLLSEL_HSI_DIV2                  ((uint32_t)0x00000000)        /*!< HSI clock divided by 2 selected as PLL entry clock source */
//#define  RCC_GCFGR_PLLSEL_PREDIV1                   ((uint32_t)0x00010000)        /*!< PREDIV1 clock selected as PLL entry clock source */

///*!< PLLPREDV configuration */
//#define  RCC_GCFGR_PLLPREDV                         ((uint32_t)0x00020000)        /*!< PLLPREDV bit for PLL entry */
//#define  RCC_GCFGR_PLLPREDV_PREDIV1                 ((uint32_t)0x00000000)        /*!< PREDIV1 clock not divided for PLL entry */
//#define  RCC_GCFGR_PLLPREDV_PREDIV1_DIV2            ((uint32_t)0x00020000)        /*!< PREDIV1 clock divided by 2 for PLL entry */

///*!< PLLMF configuration */
//#define  RCC_GCFGR_PLLMF                            ((uint32_t)0x203C0000)        /*!< PLLMF[4:0] bits (PLL multiplication factor) */
//#define  RCC_GCFGR_PLLMF_0                          ((uint32_t)0x00040000)        /*!< Bit 0 */
//#define  RCC_GCFGR_PLLMF_1                          ((uint32_t)0x00080000)        /*!< Bit 1 */
//#define  RCC_GCFGR_PLLMF_2                          ((uint32_t)0x00100000)        /*!< Bit 2 */
//#define  RCC_GCFGR_PLLMF_3                          ((uint32_t)0x00200000)        /*!< Bit 3 */
//#define  RCC_GCFGR_PLLMF_4                          ((uint32_t)0x20000000)        /*!< Bit 4 */
								     	       
//#define  RCC_GCFGR_PLLMF2                           ((uint32_t)0x00000000)        /*!< PLL input clock*2 */
//#define  RCC_GCFGR_PLLMF3                           ((uint32_t)0x00040000)        /*!< PLL input clock*3 */
//#define  RCC_GCFGR_PLLMF4                           ((uint32_t)0x00080000)        /*!< PLL input clock*4 */
//#define  RCC_GCFGR_PLLMF5                           ((uint32_t)0x000C0000)        /*!< PLL input clock*5 */
//#define  RCC_GCFGR_PLLMF6                           ((uint32_t)0x00100000)        /*!< PLL input clock*6 */
//#define  RCC_GCFGR_PLLMF7                           ((uint32_t)0x00140000)        /*!< PLL input clock*7 */
//#define  RCC_GCFGR_PLLMF8                           ((uint32_t)0x00180000)        /*!< PLL input clock*8 */
//#define  RCC_GCFGR_PLLMF9                           ((uint32_t)0x001C0000)        /*!< PLL input clock*9 */
//#define  RCC_GCFGR_PLLMF10                          ((uint32_t)0x00200000)        /*!< PLL input clock10 */
//#define  RCC_GCFGR_PLLMF11                          ((uint32_t)0x00240000)        /*!< PLL input clock*11 */
//#define  RCC_GCFGR_PLLMF12                          ((uint32_t)0x00280000)        /*!< PLL input clock*12 */
//#define  RCC_GCFGR_PLLMF13                          ((uint32_t)0x002C0000)        /*!< PLL input clock*13 */
//#define  RCC_GCFGR_PLLMF14                          ((uint32_t)0x00300000)        /*!< PLL input clock*14 */
//#define  RCC_GCFGR_PLLMF6_5                         ((uint32_t)0x00340000)        /*!< PLL input clock*6.5 */
//#define  RCC_GCFGR_PLLMF16                          ((uint32_t)0x00380000)        /*!< PLL input clock*16 */
//#define  RCC_GCFGR_PLLMF17                          ((uint32_t)0x20000000)        /*!< PLL input clock*17 */
//#define  RCC_GCFGR_PLLMF18                          ((uint32_t)0x20040000)        /*!< PLL input clock*18 */
//#define  RCC_GCFGR_PLLMF19                          ((uint32_t)0x20080000)        /*!< PLL input clock*19 */
//#define  RCC_GCFGR_PLLMF20                          ((uint32_t)0x200C0000)        /*!< PLL input clock*20 */
//#define  RCC_GCFGR_PLLMF21                          ((uint32_t)0x20100000)        /*!< PLL input clock*21 */
//#define  RCC_GCFGR_PLLMF22                          ((uint32_t)0x20140000)        /*!< PLL input clock*22 */
//#define  RCC_GCFGR_PLLMF23                          ((uint32_t)0x20180000)        /*!< PLL input clock*23 */
//#define  RCC_GCFGR_PLLMF24                          ((uint32_t)0x201C0000)        /*!< PLL input clock*24 */
//#define  RCC_GCFGR_PLLMF25                          ((uint32_t)0x20200000)        /*!< PLL input clock*25 */
//#define  RCC_GCFGR_PLLMF26                          ((uint32_t)0x20240000)        /*!< PLL input clock*26 */
//#define  RCC_GCFGR_PLLMF27                          ((uint32_t)0x20280000)        /*!< PLL input clock*27 */
//#define  RCC_GCFGR_PLLMF28                          ((uint32_t)0x202C0000)        /*!< PLL input clock*28 */
//#define  RCC_GCFGR_PLLMF29                          ((uint32_t)0x20300000)        /*!< PLL input clock*29 */
//#define  RCC_GCFGR_PLLMF30                          ((uint32_t)0x20340000)        /*!< PLL input clock*30 */
//#define  RCC_GCFGR_PLLMF31                          ((uint32_t)0x20380000)        /*!< PLL input clock*31 */
//#define  RCC_GCFGR_PLLMF32                          ((uint32_t)0x203C0000)        /*!< PLL input clock*32 */

//#define  RCC_GCFGR_OTGFSPS                          ((uint32_t)0x00C00000)        /*!< OTGFSPS[1:0] bits USB OTGDevice prescaler */
//#define  RCC_GCFGR_OTGFSPS_0                        ((uint32_t)0x00400000)        /*!< Bit 0 */
//#define  RCC_GCFGR_OTGFSPS_1                        ((uint32_t)0x00800000)        /*!< Bit 1 */

//#define  RCC_GCFGR_OTGFSPS_Div1_5                   ((uint32_t)0x00000000)        /*!< PLL divided by 1.5 */
//#define  RCC_GCFGR_OTGFSPS_Div1                     ((uint32_t)0x00400000)        /*!< PLL not divided */
//#define  RCC_GCFGR_OTGFSPS_Div2_5                   ((uint32_t)0x00800000)        /*!< PLL divided by 2.5 */
//#define  RCC_GCFGR_OTGFSPS_Div2                     ((uint32_t)0x00C00000)        /*!< PLL divided by 2 */

///*!< CKOUTSEL configuration */		         
//#define  RCC_GCFGR_CKOUTSEL                         ((uint32_t)0x0F000000)        /*!< CKOUTSEL[3:0] bits (Microcontroller Clock Output) */
//#define  RCC_GCFGR_CKOUTSEL_0                       ((uint32_t)0x01000000)        /*!< Bit 0 */
//#define  RCC_GCFGR_CKOUTSEL_1                       ((uint32_t)0x02000000)        /*!< Bit 1 */
//#define  RCC_GCFGR_CKOUTSEL_2                       ((uint32_t)0x04000000)        /*!< Bit 2 */
//#define  RCC_GCFGR_CKOUTSEL_3                       ((uint32_t)0x08000000)        /*!< Bit 3 */

//#define  RCC_GCFGR_CKOUTSEL_NOCLOCK                 ((uint32_t)0x00000000)        /*!< No clock */
//#define  RCC_GCFGR_CKOUTSEL_SYSCLK                  ((uint32_t)0x04000000)        /*!< System clock selected as CKOUTSEL source */
//#define  RCC_GCFGR_CKOUTSEL_HSI                     ((uint32_t)0x05000000)        /*!< HSI clock selected as CKOUTSEL source */
//#define  RCC_GCFGR_CKOUTSEL_HSE                     ((uint32_t)0x06000000)        /*!< HSE clock selected as CKOUTSEL source  */
//#define  RCC_GCFGR_CKOUTSEL_PLL_DIV2                ((uint32_t)0x07000000)        /*!< PLL clock divided by 2 selected as CKOUTSEL source */
//#define  RCC_GCFGR_CKOUTSEL_PLL2                    ((uint32_t)0x08000000)        /*!< PLL2 clock selected as CKOUTSEL source */
//#define  RCC_GCFGR_CKOUTSEL_PLL3_DIV2               ((uint32_t)0x09000000)        /*!< PLL3 clock divided by 2 selected as CKOUTSEL source */
//#define  RCC_GCFGR_CKOUTSEL_EXT1                    ((uint32_t)0x0A000000)        /*!< EXT1 external 3-25 MHz oscillator clock selected as CKOUTSEL source */
//#define  RCC_GCFGR_CKOUTSEL_PLL3                    ((uint32_t)0x0B000000)        /*!< PLL3 clock  selected as CKOUTSEL source */

//#else
//#define  RCC_GCFGR_PLLSEL                           ((uint32_t)0x00010000)        /*!< PLLSEL bit for entry clock source */
//#define  RCC_GCFGR_PLLSEL_HSI_DIV2                  ((uint32_t)0x00000000)        /*!< HSI clock divided by 2 selected as PLL entry clock source */
//#define  RCC_GCFGR_PLLSEL_HSE                       ((uint32_t)0x00010000)        /*!< HSE clock selected as PLL entry clock source */

///*!< PLLPREDV configuration */
//#define  RCC_GCFGR_PLLPREDV                         ((uint32_t)0x00020000)        /*!< PLLPREDV bit for PLL entry */
//#define  RCC_GCFGR_PLLPREDV_HSE                     ((uint32_t)0x00000000)        /*!< HSE clock not divided for PLL entry */
//#define  RCC_GCFGR_PLLPREDV_HSE_DIV2                ((uint32_t)0x00020000)        /*!< HSE clock divided by 2 for PLL entry */

///*!< PLLMF configuration */
//#define  RCC_GCFGR_PLLMF                            ((uint32_t)0x083C0000)        /*!< PLLMF[4:0] bits (PLL multiplication factor) */
//#define  RCC_GCFGR_PLLMF_0                          ((uint32_t)0x00040000)        /*!< Bit 0 */
//#define  RCC_GCFGR_PLLMF_1                          ((uint32_t)0x00080000)        /*!< Bit 1 */
//#define  RCC_GCFGR_PLLMF_2                          ((uint32_t)0x00100000)        /*!< Bit 2 */
//#define  RCC_GCFGR_PLLMF_3                          ((uint32_t)0x00200000)        /*!< Bit 3 */
//#define  RCC_GCFGR_PLLMF_4                          ((uint32_t)0x08000000)        /*!< Bit 4 */

//#define  RCC_GCFGR_PLLMF2                           ((uint32_t)0x00000000)        /*!< PLL input clock*2 */
//#define  RCC_GCFGR_PLLMF3                           ((uint32_t)0x00040000)        /*!< PLL input clock*3 */
//#define  RCC_GCFGR_PLLMF4                           ((uint32_t)0x00080000)        /*!< PLL input clock*4 */
//#define  RCC_GCFGR_PLLMF5                           ((uint32_t)0x000C0000)        /*!< PLL input clock*5 */
//#define  RCC_GCFGR_PLLMF6                           ((uint32_t)0x00100000)        /*!< PLL input clock*6 */
//#define  RCC_GCFGR_PLLMF7                           ((uint32_t)0x00140000)        /*!< PLL input clock*7 */
//#define  RCC_GCFGR_PLLMF8                           ((uint32_t)0x00180000)        /*!< PLL input clock*8 */
//#define  RCC_GCFGR_PLLMF9                           ((uint32_t)0x001C0000)        /*!< PLL input clock*9 */
//#define  RCC_GCFGR_PLLMF10                          ((uint32_t)0x00200000)        /*!< PLL input clock10 */
//#define  RCC_GCFGR_PLLMF11                          ((uint32_t)0x00240000)        /*!< PLL input clock*11 */
//#define  RCC_GCFGR_PLLMF12                          ((uint32_t)0x00280000)        /*!< PLL input clock*12 */
//#define  RCC_GCFGR_PLLMF13                          ((uint32_t)0x002C0000)        /*!< PLL input clock*13 */
//#define  RCC_GCFGR_PLLMF14                          ((uint32_t)0x00300000)        /*!< PLL input clock*14 */
//#define  RCC_GCFGR_PLLMF15                          ((uint32_t)0x00340000)        /*!< PLL input clock*15 */
//#define  RCC_GCFGR_PLLMF16                          ((uint32_t)0x00380000)        /*!< PLL input clock*16 */
//#define  RCC_GCFGR_PLLMF17                          ((uint32_t)0x08000000)        /*!< PLL input clock*17 */
//#define  RCC_GCFGR_PLLMF18                          ((uint32_t)0x08040000)        /*!< PLL input clock*18 */
//#define  RCC_GCFGR_PLLMF19                          ((uint32_t)0x08080000)        /*!< PLL input clock*19 */
//#define  RCC_GCFGR_PLLMF20                          ((uint32_t)0x080C0000)        /*!< PLL input clock*20 */
//#define  RCC_GCFGR_PLLMF21                          ((uint32_t)0x08100000)        /*!< PLL input clock*21 */
//#define  RCC_GCFGR_PLLMF22                          ((uint32_t)0x08140000)        /*!< PLL input clock*22 */
//#define  RCC_GCFGR_PLLMF23                          ((uint32_t)0x08180000)        /*!< PLL input clock*23 */
//#define  RCC_GCFGR_PLLMF24                          ((uint32_t)0x081C0000)        /*!< PLL input clock*24 */
//#define  RCC_GCFGR_PLLMF25                          ((uint32_t)0x08200000)        /*!< PLL input clock*25 */
//#define  RCC_GCFGR_PLLMF26                          ((uint32_t)0x08240000)        /*!< PLL input clock*26 */
//#define  RCC_GCFGR_PLLMF27                          ((uint32_t)0x08280000)        /*!< PLL input clock*27 */
//#define  RCC_GCFGR_PLLMF28                          ((uint32_t)0x082C0000)        /*!< PLL input clock*28 */
//#define  RCC_GCFGR_PLLMF29                          ((uint32_t)0x08300000)        /*!< PLL input clock*29 */
//#define  RCC_GCFGR_PLLMF30                          ((uint32_t)0x08340000)        /*!< PLL input clock*30 */
//#define  RCC_GCFGR_PLLMF31                          ((uint32_t)0x08380000)        /*!< PLL input clock*31 */
//#define  RCC_GCFGR_PLLMF32                          ((uint32_t)0x083C0000)        /*!< PLL input clock*32 */

//#define  RCC_GCFGR_USBPS                            ((uint32_t)0x00C00000)        /*!< USB Device prescaler */
//#define  RCC_GCFGR_USBPS_0                          ((uint32_t)0x00400000)        /*!< Bit 0 */
//#define  RCC_GCFGR_USBPS_1                          ((uint32_t)0x00800000)        /*!< Bit 1 */

//#define  RCC_GCFGR_USBPS_Div1_5                     ((uint32_t)0x00000000)        /*!< PLL divided by 1.5 */
//#define  RCC_GCFGR_USBPS_Div1                       ((uint32_t)0x00400000)        /*!< PLL not divided */
//#define  RCC_GCFGR_USBPS_Div2_5                     ((uint32_t)0x00800000)        /*!< PLL divided by 2.5 */
//#define  RCC_GCFGR_USBPS_Div2                       ((uint32_t)0x00C00000)        /*!< PLL divided by 2 */
									         
///*!< CKOUTSEL configuration */
//#define  RCC_GCFGR_CKOUTSEL                         ((uint32_t)0x07000000)        /*!< CKOUTSRC[2:0] bits (Microcontroller Clock Output) */
//#define  RCC_GCFGR_CKOUTSEL_0                       ((uint32_t)0x01000000)        /*!< Bit 0 */
//#define  RCC_GCFGR_CKOUTSEL_1                       ((uint32_t)0x02000000)        /*!< Bit 1 */
//#define  RCC_GCFGR_CKOUTSEL_2                       ((uint32_t)0x04000000)        /*!< Bit 2 */

//#define  RCC_GCFGR_CKOUTSEL_NOCLOCK                 ((uint32_t)0x00000000)        /*!< No clock */
//#define  RCC_GCFGR_CKOUTSEL_SYSCLK                  ((uint32_t)0x04000000)        /*!< System clock selected as CKOUTSRC source */
//#define  RCC_GCFGR_CKOUTSEL_HSI                     ((uint32_t)0x05000000)        /*!< HSI clock selected as CKOUTSRC source */
//#define  RCC_GCFGR_CKOUTSEL_HSE                     ((uint32_t)0x06000000)        /*!< HSE clock selected as CKOUTSRC source  */
//#define  RCC_GCFGR_CKOUTSEL_PLL_DIV2                ((uint32_t)0x07000000)        /*!< PLL clock divided by 2 selected as CKOUTSRC source */

//#endif /* GD32F10X_CL */

///*!<******************  Bit definition for RCC_GCIR register  ********************/
//#define  RCC_GCIR_LSISTBF                           ((uint32_t)0x00000001)        /*!< LSI Ready Interrupt flag */
//#define  RCC_GCIR_LSESTBF                           ((uint32_t)0x00000002)        /*!< LSE Ready Interrupt flag */
//#define  RCC_GCIR_HSISTBF                           ((uint32_t)0x00000004)        /*!< HSI Ready Interrupt flag */
//#define  RCC_GCIR_HSESTBF                           ((uint32_t)0x00000008)        /*!< HSE Ready Interrupt flag */
//#define  RCC_GCIR_PLLSTBF                           ((uint32_t)0x00000010)        /*!< PLL Ready Interrupt flag */
//#define  RCC_GCIR_CKMF                              ((uint32_t)0x00000080)        /*!< Clock Security System Interrupt flag */
//#define  RCC_GCIR_LSISTBIE                          ((uint32_t)0x00000100)        /*!< LSI Ready Interrupt Enable */
//#define  RCC_GCIR_LSESTBIE                          ((uint32_t)0x00000200)        /*!< LSE Ready Interrupt Enable */
//#define  RCC_GCIR_HSISTBIE                          ((uint32_t)0x00000400)        /*!< HSI Ready Interrupt Enable */
//#define  RCC_GCIR_HSESTBIE                          ((uint32_t)0x00000800)        /*!< HSE Ready Interrupt Enable */
//#define  RCC_GCIR_PLLSTBIE                          ((uint32_t)0x00001000)        /*!< PLL Ready Interrupt Enable */
//#define  RCC_GCIR_LSISTBR                           ((uint32_t)0x00010000)        /*!< LSI Ready Interrupt Clear */
//#define  RCC_GCIR_LSESTBR                           ((uint32_t)0x00020000)        /*!< LSE Ready Interrupt Clear */
//#define  RCC_GCIR_HSISTBR                           ((uint32_t)0x00040000)        /*!< HSI Ready Interrupt Clear */
//#define  RCC_GCIR_HSESTBR                           ((uint32_t)0x00080000)        /*!< HSE Ready Interrupt Clear */
//#define  RCC_GCIR_PLLSTBR                           ((uint32_t)0x00100000)        /*!< PLL Ready Interrupt Clear */
//#define  RCC_GCIR_CKMC                              ((uint32_t)0x00800000)        /*!< Clock Security System Interrupt Clear */

//#ifdef GD32F10X_CL
//#define  RCC_GCIR_PLL2STBF                          ((uint32_t)0x00000020)        /*!< PLL2 Ready Interrupt flag */
//#define  RCC_GCIR_PLL3STBF                          ((uint32_t)0x00000040)        /*!< PLL3 Ready Interrupt flag */
//#define  RCC_GCIR_PLL2STBIE                         ((uint32_t)0x00002000)        /*!< PLL2 Ready Interrupt Enable */
//#define  RCC_GCIR_PLL3STBIE                         ((uint32_t)0x00004000)        /*!< PLL3 Ready Interrupt Enable */
//#define  RCC_GCIR_PLL2STBR                          ((uint32_t)0x00200000)        /*!< PLL2 Ready Interrupt Clear */
//#define  RCC_GCIR_PLL3STBR                          ((uint32_t)0x00400000)        /*!< PLL3 Ready Interrupt Clear */
//#endif /* GD32F10X_CL */

///*****************  Bit definition for RCC_APB2RCR register  *****************/

//#define  RCC_APB2RCR_AFRST                          ((uint32_t)0x00000001)        /*!< Alternate Function I/O clock reset */
//#define  RCC_APB2RCR_PARST                          ((uint32_t)0x00000004)         /*!< GPIOA clock reset */
//#define  RCC_APB2RCR_PBRST                          ((uint32_t)0x00000008)         /*!< GPIOB clock reset */
//#define  RCC_APB2RCR_PCRST                          ((uint32_t)0x00000010)         /*!< GPIOC clock reset */
//#define  RCC_APB2RCR_PDRST                          ((uint32_t)0x00000020)         /*!< GPIOD clock reset */
//#define  RCC_APB2RCR_PERST                          ((uint32_t)0x00000040)         /*!< GPIOE clock reset */
//#define  RCC_APB2RCR_PFRST                          ((uint32_t)0x00000080)         /*!< GPIOF clock reset */
//#define  RCC_APB2RCR_PGRST                          ((uint32_t)0x00000100)         /*!< GPIOF clock reset */
//#define  RCC_APB2RCR_ADC1RST                        ((uint32_t)0x00000200)         /*!< ADC1 clock reset */
//#define  RCC_APB2RCR_ADC2RST                        ((uint32_t)0x00000400)         /*!< ADC2 clock reset */
//#define  RCC_APB2RCR_TIMER1RST                      ((uint32_t)0x00000800)         /*!< TIMER1 clock reset */
//#define  RCC_APB2RCR_SPI1RST                        ((uint32_t)0x00001000)         /*!< SPI1 clock reset */
//#define  RCC_APB2RCR_TIMER8RST                      ((uint32_t)0x00002000)         /*!< TIMER8 clock reset */
//#define  RCC_APB2RCR_USART1RST                      ((uint32_t)0x00004000)         /*!< USART1 clock reset */
//#define  RCC_APB2RCR_ADC3RST                        ((uint32_t)0x00008000)         /*!< ADC3 clock reset */
//#define  RCC_APB2RCR_TIMER9RST                      ((uint32_t)0x00080000)         /*!< TIMER9 clock reset */
//#define  RCC_APB2RCR_TIMER10RST                     ((uint32_t)0x00100000)         /*!< TIMER10 clock reset */
//#define  RCC_APB2RCR_TIMER11RST                     ((uint32_t)0x00200000)         /*!< TIMER11 clock reset */

///*****************  Bit definition for RCC_APB1RCR register  *****************/

//#define  RCC_APB1RCR_TIMER2RST                      ((uint32_t)0x00000001)        /*!< TIMER2 clock reset */
//#define  RCC_APB1RCR_TIMER3RST                      ((uint32_t)0x00000002)        /*!< TIMER3 clock reset */
//#define  RCC_APB1RCR_TIMER4RST                      ((uint32_t)0x00000004)        /*!< TIMER4 clock reset */
//#define  RCC_APB1RCR_TIMER5RST                      ((uint32_t)0x00000008)        /*!< TIMER8 clock reset */
//#define  RCC_APB1RCR_TIMER6RST                      ((uint32_t)0x00000010)        /*!< TIMER6 clock reset */
//#define  RCC_APB1RCR_TIMER7RST                      ((uint32_t)0x00000020)        /*!< TIMER7 clock reset */
//#define  RCC_APB1RCR_TIMER12RST                     ((uint32_t)0x00000040)        /*!< TIMER12 clock reset */
//#define  RCC_APB1RCR_TIMER13RST                     ((uint32_t)0x00000080)        /*!< TIMER13 clock reset */
//#define  RCC_APB1RCR_TIMER14RST                     ((uint32_t)0x00000100)        /*!< TIMER14 clock reset */
//#define  RCC_APB1RCR_WWDGRST                        ((uint32_t)0x00000800)        /*!< Window Watchdog clock reset */
//#define  RCC_APB1RCR_SPI2RST                        ((uint32_t)0x00004000)        /*!< SPI2 clock reset */
//#define  RCC_APB1RCR_SPI3RST                        ((uint32_t)0x00008000)        /*!< SPI3 clock reset */
//#define  RCC_APB1RCR_USART2RST                      ((uint32_t)0x00020000)        /*!< USART 2 clock reset */
//#define  RCC_APB1RCR_USART3RST                      ((uint32_t)0x00040000)        /*!< USART 3 clock reset */
//#define  RCC_APB1RCR_UART4RST                       ((uint32_t)0x00080000)        /*!< UART 4 clock reset */
//#define  RCC_APB1RCR_UART5RST                       ((uint32_t)0x00100000)        /*!< UART 5 clock reset */
//#define  RCC_APB1RCR_I2C1RST                        ((uint32_t)0x00200000)        /*!< I2C 1 clock reset */
//#define  RCC_APB1RCR_I2C2RST                        ((uint32_t)0x00400000)        /*!< I2C 2 clock reset */
//#define  RCC_APB1RCR_USBRST                         ((uint32_t)0x00800000)        /*!< USB Device reset */
//#define  RCC_APB1RCR_CAN1RST                        ((uint32_t)0x02000000)        /*!< CAN1 Device reset */
//#define  RCC_APB1RCR_CAN2RST                        ((uint32_t)0x04000000)        /*!< CAN2 Device reset */
//#define  RCC_APB1RCR_BKPRST                         ((uint32_t)0x08000000)        /*!< BKP Device reset */
//#define  RCC_APB1RCR_PWRRST                         ((uint32_t)0x10000000)        /*!< PWR clock reset */
//#define  RCC_APB1RCR_DACRST                         ((uint32_t)0x20000000)        /*!< DAC clock reset */

///******************  Bit definition for RCC_AHBCCR register  ******************/
//#define  RCC_AHBCCR_DMA1EN                          ((uint32_t)0x00000001)        /*!< DMA1 clock enable */
//#define  RCC_AHBCCR_DMA2EN                          ((uint32_t)0x00000002)        /*!< DMA2 clock enable */
//#define  RCC_AHBCCR_SRAMEN                          ((uint32_t)0x00000004)        /*!< SRAM interface clock enable */
//#define  RCC_AHBCCR_FMCEN                           ((uint32_t)0x00000010)        /*!< FMC clock enable */
//#define  RCC_AHBCCR_CRCEN                           ((uint32_t)0x00000040)        /*!< CRC clock enable */
//#define  RCC_AHBCCR_EXMCEN                          ((uint32_t)0x00000100)        /*!< EXMC clock enable */

//#ifdef GD32F10X_CL
//#define  RCC_AHBCCR_OTGFSEN                         ((uint32_t)0x00001000)        /*!< OTGFS clock enable */
//#define  RCC_AHBCCR_ETHMACEN                        ((uint32_t)0x00004000)        /*!< ETHMAC clock enable */
//#define  RCC_AHBCCR_ETHMACRXEN                      ((uint32_t)0x00008000)        /*!< ETHMACRX clock enable */
//#define  RCC_AHBCCR_ETHMACTXEN                      ((uint32_t)0x00010000)        /*!< ETHMACTX clock enable */

//#else
//#define  RCC_AHBCCR_SDIOEN                          ((uint32_t)0x00000400)        /*!< SDIO clock enable */
//#endif/* GD32F10X_CL */

///*****************  Bit definition for RCC_APB2CCR register  ******************/
//#define  RCC_APB2CCR_AFEN                           ((uint32_t)0x00000001)        /*!< Alternate Function I/O clock enable */
//#define  RCC_APB2CCR_PAEN                           ((uint32_t)0x00000004)         /*!< GPIOA clock enable */
//#define  RCC_APB2CCR_PBEN                           ((uint32_t)0x00000008)         /*!< GPIOB clock enable */
//#define  RCC_APB2CCR_PCEN                           ((uint32_t)0x00000010)         /*!< GPIOC clock enable */
//#define  RCC_APB2CCR_PDEN                           ((uint32_t)0x00000020)         /*!< GPIOD clock enable */
//#define  RCC_APB2CCR_PEEN                           ((uint32_t)0x00000040)         /*!< GPIOE clock enable */
//#define  RCC_APB2CCR_PFEN                           ((uint32_t)0x00000080)         /*!< GPIOF clock enable */
//#define  RCC_APB2CCR_PGEN                           ((uint32_t)0x00000100)         /*!< GPIOF clock enable */
//#define  RCC_APB2CCR_ADC1EN                         ((uint32_t)0x00000200)         /*!< ADC1 clock enable */
//#define  RCC_APB2CCR_ADC2EN                         ((uint32_t)0x00000400)         /*!< ADC2 clock enable */
//#define  RCC_APB2CCR_TIMER1EN                       ((uint32_t)0x00000800)         /*!< TIMER1 clock enable */
//#define  RCC_APB2CCR_SPI1EN                         ((uint32_t)0x00001000)         /*!< SPI1 clock enable */
//#define  RCC_APB2CCR_TIMER8EN                       ((uint32_t)0x00002000)         /*!< TIMER8 clock enable */
//#define  RCC_APB2CCR_USART1EN                       ((uint32_t)0x00004000)         /*!< USART1 clock enable */
//#define  RCC_APB2CCR_ADC3EN                         ((uint32_t)0x00008000)         /*!< ADC3 clock enable */
//#define  RCC_APB2CCR_TIMER9EN                       ((uint32_t)0x00080000)         /*!< TIMER9 clock enable */
//#define  RCC_APB2CCR_TIMER10EN                      ((uint32_t)0x00100000)         /*!< TIMER10 clock enable */
//#define  RCC_APB2CCR_TIMER11EN                      ((uint32_t)0x00200000)         /*!< TIMER11 clock enable */

///*****************  Bit definition for RCC_APB1CCR register  ******************/

//#define  RCC_APB1CCR_TIMER2EN                       ((uint32_t)0x00000001)        /*!< TIMER2 clock enable */
//#define  RCC_APB1CCR_TIMER3EN                       ((uint32_t)0x00000002)        /*!< TIMER3 clock enable */
//#define  RCC_APB1CCR_TIMER4EN                       ((uint32_t)0x00000004)        /*!< TIMER4 clock enable */
//#define  RCC_APB1CCR_TIMER5EN                       ((uint32_t)0x00000008)        /*!< TIMER8 clock enable */
//#define  RCC_APB1CCR_TIMER6EN                       ((uint32_t)0x00000010)        /*!< TIMER6 clock enable */
//#define  RCC_APB1CCR_TIMER7EN                       ((uint32_t)0x00000020)        /*!< TIMER7 clock enable */
//#define  RCC_APB1CCR_TIMER12EN                      ((uint32_t)0x00000040)        /*!< TIMER12 clock enable */
//#define  RCC_APB1CCR_TIMER13EN                      ((uint32_t)0x00000080)        /*!< TIMER13 clock enable */
//#define  RCC_APB1CCR_TIMER14EN                      ((uint32_t)0x00000100)        /*!< TIMER14 clock enable */
//#define  RCC_APB1CCR_WWDGEN                         ((uint32_t)0x00000800)        /*!< Window Watchdog clock enable */
//#define  RCC_APB1CCR_SPI2EN                         ((uint32_t)0x00004000)        /*!< SPI2 clock enable */
//#define  RCC_APB1CCR_SPI3EN                         ((uint32_t)0x00008000)        /*!< SPI3 clock enable*/
//#define  RCC_APB1CCR_USART2EN                       ((uint32_t)0x00020000)        /*!< USART 2 clock enable */
//#define  RCC_APB1CCR_USART3EN                       ((uint32_t)0x00040000)        /*!< USART 3 clock enable */
//#define  RCC_APB1CCR_UART4EN                        ((uint32_t)0x00080000)        /*!< UART 4 clock enable */
//#define  RCC_APB1CCR_UART5EN                        ((uint32_t)0x00100000)        /*!< UART 5 clock enable */
//#define  RCC_APB1CCR_I2C1EN                         ((uint32_t)0x00200000)        /*!< I2C 1 clock enable */
//#define  RCC_APB1CCR_I2C2EN                         ((uint32_t)0x00400000)        /*!< I2C 2 clock enable */
//#define  RCC_APB1CCR_USBEN                          ((uint32_t)0x00800000)        /*!< USB Device enable */
//#define  RCC_APB1CCR_CAN1EN                         ((uint32_t)0x02000000)        /*!< CAN1 Device enable */
//#define  RCC_APB1CCR_CAN2EN                         ((uint32_t)0x04000000)        /*!< CAN2 Device enable */
//#define  RCC_APB1CCR_BKPEN                          ((uint32_t)0x08000000)        /*!< BKP Device enable */
//#define  RCC_APB1CCR_PWREN                          ((uint32_t)0x10000000)        /*!< PWR clock enable */
//#define  RCC_APB1CCR_DACEN                          ((uint32_t)0x20000000)        /*!< DAC clock enable */

///*******************  Bit definition for RCC_BDCR register  *******************/
//#define  RCC_BDCR_LSEEN                             ((uint32_t)0x00000001)        /*!< External Low Speed oscillator enable */
//#define  RCC_BDCR_LSESTB                            ((uint32_t)0x00000002)        /*!< External Low Speed oscillator Ready */
//#define  RCC_BDCR_LSEBPS                            ((uint32_t)0x00000004)        /*!< External Low Speed oscillator Bypass */
									       
//#define  RCC_BDCR_RTCSEL                            ((uint32_t)0x00000300)        /*!< RTCSEL[1:0] bits (RTC clock source selection) */
//#define  RCC_BDCR_RTCSEL_0                          ((uint32_t)0x00000100)        /*!< Bit 0 */
//#define  RCC_BDCR_RTCSEL_1                          ((uint32_t)0x00000200)        /*!< Bit 1 */

///*!< RTC congiguration */
//#define  RCC_BDCR_RTCSEL_NOCLOCK                    ((uint32_t)0x00000000)        /*!< No clock */
//#define  RCC_BDCR_RTCSEL_LSE                        ((uint32_t)0x00000100)        /*!< LSE oscillator clock used as RTC clock */
//#define  RCC_BDCR_RTCSEL_LSI                        ((uint32_t)0x00000200)        /*!< LSI oscillator clock used as RTC clock */
//#define  RCC_BDCR_RTCSEL_HSE128                     ((uint32_t)0x00000300)        /*!< HSE oscillator clock divided by 128 used as RTC clock */

//#define  RCC_BDCR_RTCEN                             ((uint32_t)0x00008000)        /*!< RTC clock enable */
//#define  RCC_BDCR_BKPRST                            ((uint32_t)0x00010000)        /*!< Backup domain software reset  */

///*******************  Bit definition for RCC_GCSR register  ********************/  
//#define  RCC_GCSR_LSIEN                             ((uint32_t)0x00000001)        /*!< Internal Low Speed oscillator enable */
//#define  RCC_GCSR_LSISTB                            ((uint32_t)0x00000002)        /*!< Internal Low Speed oscillator Ready */
//#define  RCC_GCSR_RSTFC                             ((uint32_t)0x01000000)        /*!< Remove reset flag */
//#define  RCC_GCSR_EPRSTF                            ((uint32_t)0x04000000)        /*!< PIN reset flag */
//#define  RCC_GCSR_POPDRSTF                          ((uint32_t)0x08000000)        /*!< POR/PDR reset flag */
//#define  RCC_GCSR_SWRSTF                            ((uint32_t)0x10000000)        /*!< Software Reset flag */
//#define  RCC_GCSR_IWDGRSTF                          ((uint32_t)0x20000000)        /*!< Independent Watchdog reset flag */
//#define  RCC_GCSR_WWDGRSTF                          ((uint32_t)0x40000000)        /*!< Window watchdog reset flag */
//#define  RCC_GCSR_LPRSTF                            ((uint32_t)0x80000000)        /*!< Low-Power reset flag */

///*****************  Bit definition for RCC_DEEPSLEEP_VC register  *****************/
//#define  RCC_DEEPSLEEP_VC_CLEAR                     ((uint32_t)0x00000003)            /*!< RCC_DEEPSLEEP_VC[2:0] bits */
//#define  RCC_DEEPSLEEP_VC_0                         ((uint32_t)0x00000000)            /*!< Bit 0 bits */
//#define  RCC_DEEPSLEEP_VC_1                         ((uint32_t)0x00000002)            /*!< Bit 1 bits */
//#define  RCC_DEEPSLEEP_VC_2                         ((uint32_t)0x00000004)            /*!< Bit 2 bits */
//#define  RCC_DEEPSLEEP_VC1_2                        ((uint32_t)0x00000000)            /*!< The kernel voltage in Deep-sleep mode is 1.2V */
//#define  RCC_DEEPSLEEP_VC1_1                        ((uint32_t)0x00000001)            /*!< The kernel voltage in Deep-sleep is 1.1V */
//#define  RCC_DEEPSLEEP_VC1_0                        ((uint32_t)0x00000002)            /*!< The kernel voltage in Deep-sleep is 1.0V */
//#define  RCC_DEEPSLEEP_VC0_9                        ((uint32_t)0x00000003)            /*!< The kernel voltage in Deep-sleep is 0.9V */


//#ifdef GD32F10X_CL
///*******************  Bit definition for RCC_AHBRCR register  ****************/
//#define  RCC_AHBRCR_OTGFSRST                        ((uint32_t)0x00001000)        /*!< OTGFS clock reset */
//#define  RCC_AHBRCR_ETHMACRST                       ((uint32_t)0x00004000)        /*!< ETHMAC clock reset */

///*******************  Bit definition for RCC_GCFGR2 register  ******************/
///*!< PREDIV1 configuration */
//#define  RCC_GCFGR2_PREDV1                          ((uint32_t)0x0000000F)        /*!< PREDIV1[3:0] bits */
//#define  RCC_GCFGR2_PREDV1_0                        ((uint32_t)0x00000001)        /*!< Bit 0 */
//#define  RCC_GCFGR2_PREDV1_1                        ((uint32_t)0x00000002)        /*!< Bit 1 */
//#define  RCC_GCFGR2_PREDV1_2                        ((uint32_t)0x00000004)        /*!< Bit 2 */
//#define  RCC_GCFGR2_PREDV1_3                        ((uint32_t)0x00000008)        /*!< Bit 3 */

//#define  RCC_GCFGR2_PREDV1_DIV1                     ((uint32_t)0x00000000)        /*!< PREDV1 input clock not divided */
//#define  RCC_GCFGR2_PREDV1_DIV2                     ((uint32_t)0x00000001)        /*!< PREDV1 input clock divided by 2 */
//#define  RCC_GCFGR2_PREDV1_DIV3                     ((uint32_t)0x00000002)        /*!< PREDV1 input clock divided by 3 */
//#define  RCC_GCFGR2_PREDV1_DIV4                     ((uint32_t)0x00000003)        /*!< PREDV1 input clock divided by 4 */
//#define  RCC_GCFGR2_PREDV1_DIV5                     ((uint32_t)0x00000004)        /*!< PREDV1 input clock divided by 5 */
//#define  RCC_GCFGR2_PREDV1_DIV6                     ((uint32_t)0x00000005)        /*!< PREDV1 input clock divided by 6 */
//#define  RCC_GCFGR2_PREDV1_DIV7                     ((uint32_t)0x00000006)        /*!< PREDV1 input clock divided by 7 */
//#define  RCC_GCFGR2_PREDV1_DIV8                     ((uint32_t)0x00000007)        /*!< PREDV1 input clock divided by 8 */
//#define  RCC_GCFGR2_PREDV1_DIV9                     ((uint32_t)0x00000008)        /*!< PREDV1 input clock divided by 9 */
//#define  RCC_GCFGR2_PREDV1_DIV10                    ((uint32_t)0x00000009)        /*!< PREDV1 input clock divided by 10 */
//#define  RCC_GCFGR2_PREDV1_DIV11                    ((uint32_t)0x0000000A)        /*!< PREDV1 input clock divided by 11 */
//#define  RCC_GCFGR2_PREDV1_DIV12                    ((uint32_t)0x0000000B)        /*!< PREDV1 input clock divided by 12 */
//#define  RCC_GCFGR2_PREDV1_DIV13                    ((uint32_t)0x0000000C)        /*!< PREDV1 input clock divided by 13 */
//#define  RCC_GCFGR2_PREDV1_DIV14                    ((uint32_t)0x0000000D)        /*!< PREDV1 input clock divided by 14 */
//#define  RCC_GCFGR2_PREDV1_DIV15                    ((uint32_t)0x0000000E)        /*!< PREDV1 input clock divided by 15 */
//#define  RCC_GCFGR2_PREDV1_DIV16                    ((uint32_t)0x0000000F)        /*!< PREDV1 input clock divided by 16 */


///*!< PREDIV2 configuration */
//#define  RCC_GCFGR2_PREDV2                          ((uint32_t)0x000000F0)        /*!< PREDIV2[3:0] bits */
//#define  RCC_GCFGR2_PREDV2_0                        ((uint32_t)0x00000010)        /*!< Bit 0 */
//#define  RCC_GCFGR2_PREDV2_1                        ((uint32_t)0x00000020)        /*!< Bit 1 */
//#define  RCC_GCFGR2_PREDV2_2                        ((uint32_t)0x00000040)        /*!< Bit 2 */
//#define  RCC_GCFGR2_PREDV2_3                        ((uint32_t)0x00000080)        /*!< Bit 3 */

//#define  RCC_GCFGR2_PREDV2_DIV1                     ((uint32_t)0x00000000)        /*!< PREDV1 input clock not divided */
//#define  RCC_GCFGR2_PREDV2_DIV2                     ((uint32_t)0x00000010)        /*!< PREDV1 input clock divided by 2 */
//#define  RCC_GCFGR2_PREDV2_DIV3                     ((uint32_t)0x00000020)        /*!< PREDV1 input clock divided by 3 */
//#define  RCC_GCFGR2_PREDV2_DIV4                     ((uint32_t)0x00000030)        /*!< PREDV1 input clock divided by 4 */
//#define  RCC_GCFGR2_PREDV2_DIV5                     ((uint32_t)0x00000040)        /*!< PREDV1 input clock divided by 5 */
//#define  RCC_GCFGR2_PREDV2_DIV6                     ((uint32_t)0x00000050)        /*!< PREDV1 input clock divided by 6 */
//#define  RCC_GCFGR2_PREDV2_DIV7                     ((uint32_t)0x00000060)        /*!< PREDV1 input clock divided by 7 */
//#define  RCC_GCFGR2_PREDV2_DIV8                     ((uint32_t)0x00000070)        /*!< PREDV1 input clock divided by 8 */
//#define  RCC_GCFGR2_PREDV2_DIV9                     ((uint32_t)0x00000080)        /*!< PREDV1 input clock divided by 9 */
//#define  RCC_GCFGR2_PREDV2_DIV10                    ((uint32_t)0x00000090)        /*!< PREDV1 input clock divided by 10 */
//#define  RCC_GCFGR2_PREDV2_DIV11                    ((uint32_t)0x000000A0)        /*!< PREDV1 input clock divided by 11 */
//#define  RCC_GCFGR2_PREDV2_DIV12                    ((uint32_t)0x000000B0)        /*!< PREDV1 input clock divided by 12 */
//#define  RCC_GCFGR2_PREDV2_DIV13                    ((uint32_t)0x000000C0)        /*!< PREDV1 input clock divided by 13 */
//#define  RCC_GCFGR2_PREDV2_DIV14                    ((uint32_t)0x000000D0)        /*!< PREDV1 input clock divided by 14 */
//#define  RCC_GCFGR2_PREDV2_DIV15                    ((uint32_t)0x000000E0)        /*!< PREDV1 input clock divided by 15 */
//#define  RCC_GCFGR2_PREDV2_DIV16                    ((uint32_t)0x000000F0)        /*!< PREDV1 input clock divided by 16 */

///*!< PLL2MF configuration */		        
//#define  RCC_GCFGR2_PLL2MF                          ((uint32_t)0x00000F00)        /*!< PLL2MF[4:0] bits (PLL2 multiplication factor) */
//#define  RCC_GCFGR2_PLL2MF_0                        ((uint32_t)0x00000100)        /*!< Bit 0 */
//#define  RCC_GCFGR2_PLL2MF_1                        ((uint32_t)0x00000200)        /*!< Bit 1 */
//#define  RCC_GCFGR2_PLL2MF_2                        ((uint32_t)0x00000400)        /*!< Bit 2 */
//#define  RCC_GCFGR2_PLL2MF_3                        ((uint32_t)0x00000800)        /*!< Bit 3 */

//#define  RCC_GCFGR2_PLL2MF8                         ((uint32_t)0x00000600)        /*!< PLL2 input clock*8 */
//#define  RCC_GCFGR2_PLL2MF9                         ((uint32_t)0x00000700)        /*!< PLL2 input clock*9 */
//#define  RCC_GCFGR2_PLL2MF10                        ((uint32_t)0x00000800)        /*!< PLL2 input clock10 */
//#define  RCC_GCFGR2_PLL2MF11                        ((uint32_t)0x00000900)        /*!< PLL2 input clock*11 */
//#define  RCC_GCFGR2_PLL2MF12                        ((uint32_t)0x00000A00)        /*!< PLL2 input clock*12 */
//#define  RCC_GCFGR2_PLL2MF13                        ((uint32_t)0x00000B00)        /*!< PLL2 input clock*13 */
//#define  RCC_GCFGR2_PLL2MF14                        ((uint32_t)0x00000C00)        /*!< PLL2 input clock*14 */
//#define  RCC_GCFGR2_PLL2MF16                        ((uint32_t)0x00000E00)        /*!< PLL2 input clock*16 */
//#define  RCC_GCFGR2_PLL2MF20                        ((uint32_t)0x00000F00)        /*!< PLL2 input clock*20 */

///*!< PLL3MF configuration */
//#define  RCC_GCFGR2_PLL3MF                          ((uint32_t)0x0000F000)        /*!< PLL3MF[4:0] bits (PLL3 multiplication factor) */
//#define  RCC_GCFGR2_PLL3MF_0                        ((uint32_t)0x00001000)        /*!< Bit 0 */
//#define  RCC_GCFGR2_PLL3MF_1                        ((uint32_t)0x00002000)        /*!< Bit 1 */
//#define  RCC_GCFGR2_PLL3MF_2                        ((uint32_t)0x00004000)        /*!< Bit 2 */
//#define  RCC_GCFGR2_PLL3MF_3                        ((uint32_t)0x00008000)        /*!< Bit 3 */

//#define  RCC_GCFGR2_PLL3MF8                         ((uint32_t)0x00006000)        /*!< PLL input clock*8 */
//#define  RCC_GCFGR2_PLL3MF9                         ((uint32_t)0x00007000)        /*!< PLL input clock*9 */
//#define  RCC_GCFGR2_PLL3MF10                        ((uint32_t)0x00008000)        /*!< PLL input clock10 */
//#define  RCC_GCFGR2_PLL3MF11                        ((uint32_t)0x00009000)        /*!< PLL input clock*11 */
//#define  RCC_GCFGR2_PLL3MF12                        ((uint32_t)0x0000A000)        /*!< PLL input clock*12 */
//#define  RCC_GCFGR2_PLL3MF13                        ((uint32_t)0x0000B000)        /*!< PLL input clock*13 */
//#define  RCC_GCFGR2_PLL3MF14                        ((uint32_t)0x0000C000)        /*!< PLL input clock*14 */
//#define  RCC_GCFGR2_PLL3MF16                        ((uint32_t)0x0000E000)        /*!< PLL input clock*16 */
//#define  RCC_GCFGR2_PLL3MF20                        ((uint32_t)0x0000F000)        /*!< PLL input clock*20 */

///*!< PREDV1SEL configuration */
//#define  RCC_GCFGR2_PREDV1SEL                       ((uint32_t)0x00010000)        /*!< PREDV1SEL bit for entry clock source */
//#define  RCC_GCFGR2_PREDV1SEL_HSE                   ((uint32_t)0x00000000)        /*!< HSE clock  selected as PREDV1 entry clock source */
//#define  RCC_GCFGR2_PREDV1SEL_PLL2                  ((uint32_t)0x00010000)        /*!< PLL2 clock selected as PREDV1 entry clock source */

///*!< PREDV1SEL configuration */
//#define  RCC_GCFGR2_I2S2SEL                         ((uint32_t)0x00020000)        /*!< I2S2SEL bit for entry clock source */
//#define  RCC_GCFGR2_I2S2SEL_CK_SYS                  ((uint32_t)0x00000000)        /*!< CK_SYS clock  selected as I2S2 entry clock source */
//#define  RCC_GCFGR2_I2S2SEL_PLL3                    ((uint32_t)0x00020000)        /*!< PLL3 clock selected as I2S2 entry clock source */


/*!< PREDV1SEL configuration */
#define  RCC_GCFGR2_I2S3SEL                         ((uint32_t)0x00040000)        /*!< I2S3SEL bit for entry clock source */
#define  RCC_GCFGR2_I2S3SEL_CK_SYS                  ((uint32_t)0x00000000)        /*!< CK_SYS clock  selected as I2S3 entry clock source */
#define  RCC_GCFGR2_I2S3SEL_PLL3                    ((uint32_t)0x00040000)        /*!< PLL3 clock selected as I2S3 entry clock source */

#endif/* GD32F10X_CL */

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/

/********************  Bits definition for RTC_TR register  *******************/

/********************  Bits definition for RTC_CTLR1 register  ****************/
#define RTC_CTLR1_SIE                               ((uint8_t)0x01)                  /*!< RTC Second Interrupt Enable */
#define RTC_CTLR1_AIE                               ((uint8_t)0x02)                  /*!< RTC Alarm Interrupt Enable */
#define RTC_CTLR1_OVIE                              ((uint8_t)0x04)                  /*!< RTC OverfloW Interrupt Enable */

/********************  Bits definition for RTC_CTLR2 register  ****************/
#define RTC_CTLR2_SF                                ((uint8_t)0x01)                  /*!< RTC Second Flag */
#define RTC_CTLR2_AF                                ((uint8_t)0x02)                  /*!< RTC Alarm Flag */
#define RTC_CTLR2_OVF                               ((uint8_t)0x04)                  /*!< RTC OverfloW Flag */
#define RTC_CTLR2_RSF                               ((uint8_t)0x08)                  /*!< RTC Registers Synchronized Flag */
#define RTC_CTLR2_CMF                               ((uint8_t)0x10)                  /*!< RTC Configuration Mode Flag */
#define RTC_CTLR2_LWOFF                             ((uint8_t)0x20)                  /*!< RTC Last Write Operation OFF */

/********************  Bits definition for RTC_PLR1 register  *****************/
#define  RTC_PLR1_PLR                               ((uint16_t)0x000F)               /*!< RTC Prescaler Value High */

/********************  Bits definition for RTC_PLR2 register  *****************/
#define  RTC_PLR2_PLR                               ((uint16_t)0xFFFF)               /*!< RTC Prescaler Value Low*/

/********************  Bits definition for RTC_PREDIV1 register  **************/
#define  RTC_PREDIV1_RTC_PREDIV                     ((uint16_t)0x000F)               /*!< RTC  Divider Value High */
									         
/********************  Bits definition for RTC_PREDIV2 register  **************/
#define  RTC_PREDIV2_RTC_PREDIV                     ((uint16_t)0xFFFF)               /*!< RTC  Divider Value Low */

/********************  Bits definition for RTC_CNT1 register  *****************/
#define  RTC_CNT1_RTC_CNT                           ((uint16_t)0xFFFF)               /*!< RTC Counter Value High */

/********************  Bits definition for RTC_CNT2 register  *****************/
#define  RTC_CNT2_RTC_CNT                           ((uint16_t)0xFFFF)               /*!< RTC Counter Value Low */          

/********************  Bits definition for RTC_ALRMR1 register  ***************/
#define  RTC_ALRMR1_RTC_ALRMR                       ((uint16_t)0xFFFF)               /*!< RTC Alarm Value High */

/********************  Bits definition for RTC_ALRMR2 register  ***************/
#define  RTC_ALRMR2_RTC_ALRMR                       ((uint16_t)0xFFFF)               /*!< RTC Alarm Value Low */

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface                         */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for SPI_CTLR1 register  ********************/
#define  SPI_CTLR1_SCKPH                            ((uint16_t)0x0001)            /*!< Clock Phase */
#define  SPI_CTLR1_SCKPL                            ((uint16_t)0x0002)            /*!< Clock Polarity */
#define  SPI_CTLR1_MSTMODE                          ((uint16_t)0x0004)            /*!< Master Selection */

#define  SPI_CTLR1_PSC                              ((uint16_t)0x0038)            /*!< PSC[2:0] bits (Baud Rate Control) */
#define  SPI_CTLR1_PSC_0                            ((uint16_t)0x0008)            /*!< Bit 0 */
#define  SPI_CTLR1_PSC_1                            ((uint16_t)0x0010)            /*!< Bit 1 */
#define  SPI_CTLR1_PSC_2                            ((uint16_t)0x0020)            /*!< Bit 2 */

#define  SPI_CTLR1_SPIEN                            ((uint16_t)0x0040)            /*!< SPI Enable */
#define  SPI_CTLR1_LF                               ((uint16_t)0x0080)            /*!< Frame Format */
#define  SPI_CTLR1_SWNSS                            ((uint16_t)0x0100)            /*!< Internal slave select */
#define  SPI_CTLR1_SWNSSEN                          ((uint16_t)0x0200)            /*!< Software slave management */
#define  SPI_CTLR1_RO                               ((uint16_t)0x0400)            /*!< Receive only */
#define  SPI_CTLR1_FF16                             ((uint16_t)0x0800)            /*!< Data Frame Format */
#define  SPI_CTLR1_CRCNT                            ((uint16_t)0x1000)            /*!< Transmit CRC next */
#define  SPI_CTLR1_CRCEN                            ((uint16_t)0x2000)            /*!< Hardware CRC calculation enable */
#define  SPI_CTLR1_BDOE                             ((uint16_t)0x4000)            /*!< Output enable in bidirectional mode */
#define  SPI_CTLR1_BDM                              ((uint16_t)0x8000)            /*!< Bidirectional data mode enable */
									       
/*******************  Bit definition for SPI_CTLR2 register  ********************/
#define  SPI_CTLR2_DMARE                            ((uint8_t)0x01)               /*!< Rx Buffer DMA Enable */
#define  SPI_CTLR2_DMATE                            ((uint8_t)0x02)               /*!< Tx Buffer DMA Enable */
#define  SPI_CTLR2_NSSDRV                           ((uint8_t)0x04)               /*!< SS Output Enable */
#define  SPI_CTLR2_ERRIE                            ((uint8_t)0x20)               /*!< Error Interrupt Enable */
#define  SPI_CTLR2_RBNEIE                           ((uint8_t)0x40)               /*!< RX buffer Not Empty Interrupt Enable */
#define  SPI_CTLR2_TBEIE                            ((uint8_t)0x80)               /*!< Tx buffer Empty Interrupt Enable */

/********************  Bit definition for SPI_STR register  ********************/
#define  SPI_STR_RBNE                               ((uint8_t)0x01)               /*!< Receive buffer Not Empty */
#define  SPI_STR_TBE                                ((uint8_t)0x02)               /*!< Transmit buffer Empty */
#define  SPI_STR_I2SCH                              ((uint8_t)0x04)               /*!< Channel side */
#define  SPI_STR_TXURE                              ((uint8_t)0x08)               /*!< Underrun flag */
#define  SPI_STR_CRCE                               ((uint8_t)0x10)               /*!< CRC Error flag */
#define  SPI_STR_CONFE                              ((uint8_t)0x20)               /*!< Mode fault */
#define  SPI_STR_RXORE                              ((uint8_t)0x40)               /*!< Overrun flag */
#define  SPI_STR_TRANS                              ((uint8_t)0x80)               /*!< Busy flag */

/********************  Bit definition for SPI_DTR register  ********************/
#define  SPI_DTR_DTR                                ((uint16_t)0xFFFF)            /*!< Data Register */

/*******************  Bit definition for SPI_CRR register  ******************/
#define  SPI_CPR_CPR                                ((uint16_t)0xFFFF)            /*!< CRC polynomial register */

/******************  Bit definition for SPI_RCR register  ******************/
#define  SPI_RCR_RCR                                ((uint16_t)0xFFFF)            /*!< Rx CRC Register */

/******************  Bit definition for SPI_TCR register  ******************/
#define  SPI_TCR_TCR                                ((uint16_t)0xFFFF)            /*!< Tx CRC Register */

/******************  Bit definition for SPI_I2SCTLR register  *****************/
#define  SPI_I2SCTLR_CHLEN                          ((uint16_t)0x0001)            /*!< Channel length (number of bits per audio channel) */
								          
#define  SPI_I2SCTLR_DTLEN                          ((uint16_t)0x0006)            /*!< DTLEN[1:0] bits (Data length to be transferred) */
#define  SPI_I2SCTLR_DTLEN_0                        ((uint16_t)0x0002)            /*!< Bit 0 */
#define  SPI_I2SCTLR_DTLEN_1                        ((uint16_t)0x0004)            /*!< Bit 1 */

#define  SPI_I2SCTLR_CKPL                           ((uint16_t)0x0008)            /*!< steady state clock polarity */

#define  SPI_I2SCTLR_I2SSTD                         ((uint16_t)0x0030)            /*!< I2SSTD[1:0] bits (I2S standard selection) */
#define  SPI_I2SCTLR_I2SSTD_0                       ((uint16_t)0x0010)            /*!< Bit 0 */
#define  SPI_I2SCTLR_I2SSTD_1                       ((uint16_t)0x0020)            /*!< Bit 1 */

#define  SPI_I2SCTLR_PCMSM                          ((uint16_t)0x0080)            /*!< PCM frame synchronization */

#define  SPI_I2SCTLR_I2SOM                          ((uint16_t)0x0300)            /*!< I2SOM[1:0] bits (I2S configuration mode) */
#define  SPI_I2SCTLR_I2SOM_0                        ((uint16_t)0x0100)            /*!< Bit 0 */
#define  SPI_I2SCTLR_I2SOM_1                        ((uint16_t)0x0200)            /*!< Bit 1 */
									         
#define  SPI_I2SCTLR_I2SEN                          ((uint16_t)0x0400)            /*!< I2S Enable */
#define  SPI_I2SCTLR_I2SSEL                         ((uint16_t)0x0800)            /*!< I2S mode selection */

/******************  Bit definition for SPI_I2SCKP register  *******************/
#define  SPI_I2SCKP_DIV                             ((uint16_t)0x00FF)            /*!< I2S Linear prescaler */
#define  SPI_I2SCKP_OF                              ((uint16_t)0x0100)            /*!< Odd factor for the prescaler */
#define  SPI_I2SCKP_MCKOE                           ((uint16_t)0x0200)            /*!< Master Clock Output Enable */

/******************************************************************************/
/*                                                                            */
/*                       System Configuration (SYSCFG)                        */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for SYSCFG_R1 register  ****************/
#define  SYSCFG_R1_BOOT_MODE                        ((uint32_t)0x00000003)        /*!< SYSCFG_Memory Remap Config */
#define  SYSCFG_R1_BOOT_MODE_0                      ((uint32_t)0x00000001)        /*!< SYSCFG_Memory Remap Config Bit 0 */
#define  SYSCFG_R1_BOOT_MODE_1                      ((uint32_t)0x00000002)        /*!< SYSCFG_Memory Remap Config Bit 1 */
#define  SYSCFG_R1_ADC_DMA_RMP                      ((uint32_t)0x00000100)        /*!< ADC DMA remap */
#define  SYSCFG_R1_USART1_TX_DMA_RMP                ((uint32_t)0x00000200)        /*!< USART1 TX DMA remap */
#define  SYSCFG_R1_USART1_RX_DMA_RMP                ((uint32_t)0x00000400)        /*!< USART1 RX DMA remap */
#define  SYSCFG_R1_TIMER16_DMA_RMP                  ((uint32_t)0x00000800)        /*!< Timer 16 DMA remap */
#define  SYSCFG_R1_TIMER17_DMA_RMP                  ((uint32_t)0x00001000)        /*!< Timer 17 DMA remap */
#define  SYSCFG_R1_PB9_HCCE                         ((uint32_t)0x00080000)        /*PB9 pin high current capability enable */

/*****************  Bit definition for SYSCFG_EXTISS1 register  ***************/
#define  SYSCFG_EXTISS1_EXTI0_SS                    ((uint16_t)0x000F)            /*!< EXTI 0 configuration */
#define  SYSCFG_EXTISS1_EXTI1_SS                    ((uint16_t)0x00F0)            /*!< EXTI 1 configuration */
#define  SYSCFG_EXTISS1_EXTI2_SS                    ((uint16_t)0x0F00)            /*!< EXTI 2 configuration */
#define  SYSCFG_EXTISS1_EXTI3_SS                    ((uint16_t)0xF000)            /*!< EXTI 3 configuration */

/** 
  * @brief  EXTI0 configuration  
  */
#define  SYSCFG_EXTISS1_EXTI0_SS_PA                 ((uint16_t)0x0000)            /*!< PA[0] pin */
#define  SYSCFG_EXTISS1_EXTI0_SS_PB                 ((uint16_t)0x0001)            /*!< PB[0] pin */
#define  SYSCFG_EXTISS1_EXTI0_SS_PC                 ((uint16_t)0x0002)            /*!< PC[0] pin */
#define  SYSCFG_EXTISS1_EXTI0_SS_PD                 ((uint16_t)0x0003)            /*!< PD[0] pin */
#define  SYSCFG_EXTISS1_EXTI0_SS_PF                 ((uint16_t)0x0005)            /*!< PF[0] pin */
/** 
  * @brief  EXTI1 configuration  
  */ 
#define  SYSCFG_EXTISS1_EXTI1_SS_PA                 ((uint16_t)0x0000)            /*!< PA[1] pin */
#define  SYSCFG_EXTISS1_EXTI1_SS_PB                 ((uint16_t)0x0010)            /*!< PB[1] pin */
#define  SYSCFG_EXTISS1_EXTI1_SS_PC                 ((uint16_t)0x0020)            /*!< PC[1] pin */
#define  SYSCFG_EXTISS1_EXTI1_SS_PD                 ((uint16_t)0x0030)            /*!< PD[1] pin */
#define  SYSCFG_EXTISS1_EXTI1_SS_PF                 ((uint16_t)0x0050)            /*!< PF[1] pin */
/** 
  * @brief  EXTI2 configuration  
  */
#define  SYSCFG_EXTISS1_EXTI2_SS_PA                 ((uint16_t)0x0000)            /*!< PA[2] pin */
#define  SYSCFG_EXTISS1_EXTI2_SS_PB                 ((uint16_t)0x0100)            /*!< PB[2] pin */
#define  SYSCFG_EXTISS1_EXTI2_SS_PC                 ((uint16_t)0x0200)            /*!< PC[2] pin */
#define  SYSCFG_EXTISS1_EXTI2_SS_PD                 ((uint16_t)0x0300)            /*!< PD[2] pin */
#define  SYSCFG_EXTISS1_EXTI2_SS_PF                 ((uint16_t)0x0500)            /*!< PF[2] pin */
/** 
  * @brief  EXTI3 configuration  
  */
#define  SYSCFG_EXTISS1_EXTI3_SS_PA                 ((uint16_t)0x0000)            /*!< PA[3] pin */
#define  SYSCFG_EXTISS1_EXTI3_SS_PB                 ((uint16_t)0x1000)            /*!< PB[3] pin */
#define  SYSCFG_EXTISS1_EXTI3_SS_PC                 ((uint16_t)0x2000)            /*!< PC[3] pin */
#define  SYSCFG_EXTISS1_EXTI3_SS_PD                 ((uint16_t)0x3000)            /*!< PD[3] pin */
#define  SYSCFG_EXTISS1_EXTI3_SS_PF                 ((uint16_t)0x5000)            /*!< PF[3] pin */

/*****************  Bit definition for SYSCFG_EXTISS2 register  *****************/
#define  SYSCFG_EXTISS2_EXTI4_SS                    ((uint16_t)0x000F)            /*!< EXTI 4 configuration */
#define  SYSCFG_EXTISS2_EXTI5_SS                    ((uint16_t)0x00F0)            /*!< EXTI 5 configuration */
#define  SYSCFG_EXTISS2_EXTI6_SS                    ((uint16_t)0x0F00)            /*!< EXTI 6 configuration */
#define  SYSCFG_EXTISS2_EXTI7_SS                    ((uint16_t)0xF000)            /*!< EXTI 7 configuration */
									        
/** 
  * @brief  EXTI4 configuration  
  */
#define  SYSCFG_EXTISS2_EXTI4_SS_PA                 ((uint16_t)0x0000)            /*!< PA[4] pin */
#define  SYSCFG_EXTISS2_EXTI4_SS_PB                 ((uint16_t)0x0001)            /*!< PB[4] pin */
#define  SYSCFG_EXTISS2_EXTI4_SS_PC                 ((uint16_t)0x0002)            /*!< PC[4] pin */
#define  SYSCFG_EXTISS2_EXTI4_SS_PF                 ((uint16_t)0x0005)            /*!< PD[4] pin */

/** 
  * @brief  EXTI5 configuration  
  */
#define  SYSCFG_EXTISS2_EXTI5_SS_PA                 ((uint16_t)0x0000)            /*!< PA[5] pin */
#define  SYSCFG_EXTISS2_EXTI5_SS_PB                 ((uint16_t)0x0010)            /*!< PB[5] pin */
#define  SYSCFG_EXTISS2_EXTI5_SS_PC                 ((uint16_t)0x0020)            /*!< PC[5] pin */
#define  SYSCFG_EXTISS2_EXTI5_SS_PF                 ((uint16_t)0x0050)            /*!< PD[5] pin */

/** 
  * @brief  EXTI6 configuration  
  */
#define  SYSCFG_EXTISS2_EXTI6_SS_PA                 ((uint16_t)0x0000)            /*!< PA[6] pin */
#define  SYSCFG_EXTISS2_EXTI6_SS_PB                 ((uint16_t)0x0100)            /*!< PB[6] pin */
#define  SYSCFG_EXTISS2_EXTI6_SS_PC                 ((uint16_t)0x0200)            /*!< PC[6] pin */
#define  SYSCFG_EXTISS2_EXTI6_SS_PF                 ((uint16_t)0x0500)            /*!< PD[6] pin */

/** 
  * @brief  EXTI7 configuration  
  */
#define  SYSCFG_EXTISS2_EXTI7_SS_PA                 ((uint16_t)0x0000)            /*!< PA[7] pin */
#define  SYSCFG_EXTISS2_EXTI7_SS_PB                 ((uint16_t)0x1000)            /*!< PB[7] pin */
#define  SYSCFG_EXTISS2_EXTI7_SS_PC                 ((uint16_t)0x2000)            /*!< PC[7] pin */
#define  SYSCFG_EXTISS2_EXTI7_SS_PF                 ((uint16_t)0xF000)            /*!< PD[7] pin */

/*****************  Bit definition for SYSCFG_EXTISS3 register  *****************/
#define  SYSCFG_EXTISS3_EXTI8_SS                    ((uint16_t)0x000F)            /*!< EXTI 8 configuration */
#define  SYSCFG_EXTISS3_EXTI9_SS                    ((uint16_t)0x00F0)            /*!< EXTI 9 configuration */
#define  SYSCFG_EXTISS3_EXTI10_SS                   ((uint16_t)0x0F00)            /*!< EXTI 10 configuration */
#define  SYSCFG_EXTISS3_EXTI11_SS                   ((uint16_t)0xF000)            /*!< EXTI 11 configuration */

/** 
  * @brief  EXTI8 configuration  
  */
#define  SYSCFG_EXTISS3_EXTI8_SS_PA                 ((uint16_t)0x0000)            /*!< PA[8] pin */
#define  SYSCFG_EXTISS3_EXTI8_SS_PB                 ((uint16_t)0x0001)            /*!< PB[8] pin */
#define  SYSCFG_EXTISS3_EXTI8_SS_PC                 ((uint16_t)0x0002)            /*!< PC[8] pin */

/** 
  * @brief  EXTI9 configuration  
  */
#define  SYSCFG_EXTISS3_EXTI9_SS_PA                 ((uint16_t)0x0000)            /*!< PA[9] pin */
#define  SYSCFG_EXTISS3_EXTI9_SS_PB                 ((uint16_t)0x0010)            /*!< PB[9] pin */
#define  SYSCFG_EXTISS3_EXTI9_SS_PC                 ((uint16_t)0x0020)            /*!< PC[9] pin */

/** 
  * @brief  EXTI10 configuration  
  */
#define  SYSCFG_EXTISS3_EXTI10_SS_PA                ((uint16_t)0x0000)            /*!< PA[10] pin */
#define  SYSCFG_EXTISS3_EXTI10_SS_PB                ((uint16_t)0x0100)            /*!< PB[10] pin */
#define  SYSCFG_EXTISS3_EXTI10_SS_PC                ((uint16_t)0x0200)            /*!< PC[10] pin */

/** 
  * @brief  EXTI11 configuration  
  */
#define  SYSCFG_EXTISS3_EXTI11_SS_PA                ((uint16_t)0x0000)            /*!< PA[11] pin */
#define  SYSCFG_EXTISS3_EXTI11_SS_PB                ((uint16_t)0x1000)            /*!< PB[11] pin */
#define  SYSCFG_EXTISS3_EXTI11_SS_PC                ((uint16_t)0x2000)            /*!< PC[11] pin */

/*****************  Bit definition for SYSCFG_EXTISS4 register  *****************/
#define  SYSCFG_EXTISS4_EXTI12_SS                   ((uint16_t)0x000F)            /*!< EXTI 12 configuration */
#define  SYSCFG_EXTISS4_EXTI13_SS                   ((uint16_t)0x00F0)            /*!< EXTI 13 configuration */
#define  SYSCFG_EXTISS4_EXTI14_SS                   ((uint16_t)0x0F00)            /*!< EXTI 14 configuration */
#define  SYSCFG_EXTISS4_EXTI15_SS                   ((uint16_t)0xF000)            /*!< EXTI 15 configuration */

/** 
  * @brief  EXTI12 configuration  
  */
#define SYSCFG_EXTISS4_EXTI12_SS_PA                 ((uint16_t)0x0000)            /*!< PA[12] pin */
#define SYSCFG_EXTISS4_EXTI12_SS_PB                 ((uint16_t)0x0001)            /*!< PB[12] pin */
#define SYSCFG_EXTISS4_EXTI12_SS_PC                 ((uint16_t)0x0002)            /*!< PC[12] pin */

/** 
  * @brief  EXTI13 configuration  
  */
#define  SYSCFG_EXTISS4_EXTI13_SS_PA                ((uint16_t)0x0000)            /*!< PA[13] pin */
#define  SYSCFG_EXTISS4_EXTI13_SS_PB                ((uint16_t)0x0010)            /*!< PB[13] pin */
#define  SYSCFG_EXTISS4_EXTI13_SS_PC                ((uint16_t)0x0020)            /*!< PC[13] pin */

/** 
  * @brief  EXTI14 configuration  
  */
#define  SYSCFG_EXTISS4_EXTI14_SS_PA                ((uint16_t)0x0000)            /*!< PA[14] pin */
#define  SYSCFG_EXTISS4_EXTI14_SS_PB                ((uint16_t)0x0100)            /*!< PB[14] pin */
#define  SYSCFG_EXTISS4_EXTI14_SS_PC                ((uint16_t)0x0200)            /*!< PC[14] pin */

/** 
  * @brief  EXTI15 configuration  
  */
#define  SYSCFG_EXTISS4_EXTI15_SS_PA                ((uint16_t)0x0000)            /*!< PA[15] pin */
#define  SYSCFG_EXTISS4_EXTI15_SS_PB                ((uint16_t)0x1000)            /*!< PB[15] pin */
#define  SYSCFG_EXTISS4_EXTI15_SS_PC                ((uint16_t)0x2000)            /*!< PC[15] pin */

/*****************  Bit definition for SYSCFG_R2 register  ****************/
#define  SYSCFG_R2_LOCKUP_LOCK                      ((uint32_t)0x00000001)        /*!< Enables and locks the LVD connection with Timer1 Break Input and also the LVD_EN and LVDSEL[2:0] bits of the Power Control Interface */
#define  SYSCFG_R2_SRAM_PARITY_ERROR_LOCK           ((uint32_t)0x00000002)        /*!< Enables and locks the SRAM_PARITY error signal with Break Input of TIMER1 */
#define  SYSCFG_R2_LVD_LOCK                         ((uint32_t)0x00000004)        /*!< Enables and locks the LOCKUP (Hardfault) output of CortexM0 with Break Input of TIMER1 */
#define  SYSCFG_R2_SRAM_PCEF                        ((uint32_t)0x00000100)        /*!< SRAM Parity error flag */

/******************************************************************************/
/*                                                                            */
/*                               Timers (TIMER)                               */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for TIMER_CTLR1 register  ********************/
#define  TIMER_CTLR1_CNTE                           ((uint16_t)0x0001)            /*!<Counter enable */
#define  TIMER_CTLR1_UPDIS                          ((uint16_t)0x0002)            /*!<Update disable */
#define  TIMER_CTLR1_UPS                            ((uint16_t)0x0004)            /*!<Update request source */
#define  TIMER_CTLR1_SPM                            ((uint16_t)0x0008)            /*!<One pulse mode */
#define  TIMER_CTLR1_DIR                            ((uint16_t)0x0010)            /*!<Direction */
											 
#define  TIMER_CTLR1_CAM                            ((uint16_t)0x0060)            /*!<CAM[1:0] bits (Center-aligned mode selection) */
#define  TIMER_CTLR1_CAM_0                          ((uint16_t)0x0020)            /*!<Bit 0 */
#define  TIMER_CTLR1_CAM_1                          ((uint16_t)0x0040)            /*!<Bit 1 */

#define  TIMER_CTLR1_ARSE                           ((uint16_t)0x0080)            /*!<Auto-reload preload enable */
												  
#define  TIMER_CTLR1_CDIV                           ((uint16_t)0x0300)            /*!<CDIV[1:0] bits (clock division) */
#define  TIMER_CTLR1_CDIV_0                         ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIMER_CTLR1_CDIV_1                         ((uint16_t)0x0200)            /*!<Bit 1 */

/*******************  Bit definition for TIMER_CTLR2 register  ********************/
#define  TIMER_CTLR2_CCSE                           ((uint16_t)0x0001)            /*!<Capture/Compare Preloaded Control */
#define  TIMER_CTLR2_CCUC                           ((uint16_t)0x0004)            /*!<Capture/Compare Control Update Selection */
#define  TIMER_CTLR2_DMAS                           ((uint16_t)0x0008)            /*!<Capture/Compare DMA Selection */
												 
#define  TIMER_CTLR2_MMC                            ((uint16_t)0x0070)            /*!<MMC[2:0] bits (Master Mode Selection) */
#define  TIMER_CTLR2_MMC_0                          ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIMER_CTLR2_MMC_1                          ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIMER_CTLR2_MMC_2                          ((uint16_t)0x0040)            /*!<Bit 2 */

#define  TIMER_CTLR2_TI1S                           ((uint16_t)0x0080)            /*!<TI1 Selection */
#define  TIMER_CTLR2_ISO1                           ((uint16_t)0x0100)            /*!<Output Idle state 1 (OC1 output) */
#define  TIMER_CTLR2_ISO1N                          ((uint16_t)0x0200)            /*!<Output Idle state 1 (OC1N output) */
#define  TIMER_CTLR2_ISO2                           ((uint16_t)0x0400)            /*!<Output Idle state 2 (OC2 output) */
#define  TIMER_CTLR2_ISO2N                          ((uint16_t)0x0800)            /*!<Output Idle state 2 (OC2N output) */
#define  TIMER_CTLR2_ISO3                           ((uint16_t)0x1000)            /*!<Output Idle state 3 (OC3 output) */
#define  TIMER_CTLR2_ISO3N                          ((uint16_t)0x2000)            /*!<Output Idle state 3 (OC3N output) */
#define  TIMER_CTLR2_ISO4                           ((uint16_t)0x4000)            /*!<Output Idle state 4 (OC4 output) */
								    
/*******************  Bit definition for TIMER_SMC register  *******************/
#define  TIMER_SMC_SMC                              ((uint16_t)0x0007)            /*!<SMC[2:0] bits (Slave mode selection) */
#define  TIMER_SMC_SMC_0                            ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIMER_SMC_SMC_1                            ((uint16_t)0x0002)            /*!<Bit 1 */
#define  TIMER_SMC_SMC_2                            ((uint16_t)0x0004)            /*!<Bit 2 */
									        
#define  TIMER_SMC_TRGS                             ((uint16_t)0x0070)            /*!<TRGS[2:0] bits (Trigger selection) */
#define  TIMER_SMC_TRGS_0                           ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIMER_SMC_TRGS_1                           ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIMER_SMC_TRGS_2                           ((uint16_t)0x0040)            /*!<Bit 2 */

#define  TIMER_SMC_MSM                              ((uint16_t)0x0080)            /*!<Master/slave mode */
											  
#define  TIMER_SMC_ETFC                             ((uint16_t)0x0F00)            /*!<ETFC[3:0] bits (External trigger filter) */
#define  TIMER_SMC_ETFC_0                           ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIMER_SMC_ETFC_1                           ((uint16_t)0x0200)            /*!<Bit 1 */
#define  TIMER_SMC_ETFC_2                           ((uint16_t)0x0400)            /*!<Bit 2 */
#define  TIMER_SMC_ETFC_3                           ((uint16_t)0x0800)            /*!<Bit 3 */

#define  TIMER_SMC_ETPSC                            ((uint16_t)0x3000)            /*!<ETPSC[1:0] bits (External trigger prescaler) */
#define  TIMER_SMC_ETPSC_0                          ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIMER_SMC_ETPSC_1                          ((uint16_t)0x2000)            /*!<Bit 1 */
										  
#define  TIMER_SMC_ECM2E                            ((uint16_t)0x4000)            /*!<External clock enable */
#define  TIMER_SMC_ETPL                             ((uint16_t)0x8000)            /*!<External trigger polarity */
											 
/*******************  Bit definition for TIMER_DIE register  *******************/
#define  TIMER_DIE_UPIE                             ((uint16_t)0x0001)            /*!<Update interrupt enable */
#define  TIMER_DIE_CH1IE                            ((uint16_t)0x0002)            /*!<Capture/Compare 1 interrupt enable */
#define  TIMER_DIE_CH2IE                            ((uint16_t)0x0004)            /*!<Capture/Compare 2 interrupt enable */
#define  TIMER_DIE_CH3IE                            ((uint16_t)0x0008)            /*!<Capture/Compare 3 interrupt enable */
#define  TIMER_DIE_CH4IE                            ((uint16_t)0x0010)            /*!<Capture/Compare 4 interrupt enable */
#define  TIMER_DIE_CCUIE                            ((uint16_t)0x0020)            /*!<COM interrupt enable */
#define  TIMER_DIE_TRGIE                            ((uint16_t)0x0040)            /*!<Trigger interrupt enable */
#define  TIMER_DIE_BKIE                             ((uint16_t)0x0080)            /*!<Break interrupt enable */
#define  TIMER_DIE_UPDE                             ((uint16_t)0x0100)            /*!<Update DMA request enable */
#define  TIMER_DIE_CH1DE                            ((uint16_t)0x0200)            /*!<Capture/Compare 1 DMA request enable */
#define  TIMER_DIE_CH2DE                            ((uint16_t)0x0400)            /*!<Capture/Compare 2 DMA request enable */
#define  TIMER_DIE_CH3DE                            ((uint16_t)0x0800)            /*!<Capture/Compare 3 DMA request enable */
#define  TIMER_DIE_CH4DE                            ((uint16_t)0x1000)            /*!<Capture/Compare 4 DMA request enable */
#define  TIMER_DIE_CCUDE                            ((uint16_t)0x2000)            /*!<COM DMA request enable */
#define  TIMER_DIE_TRGDE                            ((uint16_t)0x4000)            /*!<Trigger DMA request enable */

/********************  Bit definition for TIMER_STR register  ********************/
#define  TIMER_STR_UPIF                             ((uint16_t)0x0001)            /*!<Update interrupt Flag */
#define  TIMER_STR_CH1IF                            ((uint16_t)0x0002)            /*!<Capture/Compare 1 interrupt Flag */
#define  TIMER_STR_CH2IF                            ((uint16_t)0x0004)            /*!<Capture/Compare 2 interrupt Flag */
#define  TIMER_STR_CH3IF                            ((uint16_t)0x0008)            /*!<Capture/Compare 3 interrupt Flag */
#define  TIMER_STR_CH4IF                            ((uint16_t)0x0010)            /*!<Capture/Compare 4 interrupt Flag */
#define  TIMER_STR_CCUIF                            ((uint16_t)0x0020)            /*!<COM interrupt Flag */
#define  TIMER_STR_TRGIF                            ((uint16_t)0x0040)            /*!<Trigger interrupt Flag */
#define  TIMER_STR_BKIF                             ((uint16_t)0x0080)            /*!<Break interrupt Flag */
#define  TIMER_STR_CH1OF                            ((uint16_t)0x0200)            /*!<Capture/Compare 1 Overcapture Flag */
#define  TIMER_STR_CH2OF                            ((uint16_t)0x0400)            /*!<Capture/Compare 2 Overcapture Flag */
#define  TIMER_STR_CH3OF                            ((uint16_t)0x0800)            /*!<Capture/Compare 3 Overcapture Flag */
#define  TIMER_STR_CH4OF                            ((uint16_t)0x1000)            /*!<Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TIMER_EVG register  ********************/
#define  TIMER_EVG_UPG                              ((uint8_t)0x01)               /*!<Update Generation */
#define  TIMER_EVG_CH1G                             ((uint8_t)0x02)               /*!<Capture/Compare 1 Generation */
#define  TIMER_EVG_CH2G                             ((uint8_t)0x04)               /*!<Capture/Compare 2 Generation */
#define  TIMER_EVG_CH3G                             ((uint8_t)0x08)               /*!<Capture/Compare 3 Generation */
#define  TIMER_EVG_CH4G                             ((uint8_t)0x10)               /*!<Capture/Compare 4 Generation */
#define  TIMER_EVG_CCUG                             ((uint8_t)0x20)               /*!<Capture/Compare Control Update Generation */
#define  TIMER_EVG_TRGG                             ((uint8_t)0x40)               /*!<Trigger Generation */
#define  TIMER_EVG_BKG                              ((uint8_t)0x80)               /*!<Break Generation */

/******************  Bit definition for TIMER_CHCTLR1 register  *******************/
#define  TIMER_CHCTLR1_CH1M                         ((uint16_t)0x0003)            /*!<CH1M[1:0] bits (Capture/Compare 1 Selection) */
#define  TIMER_CHCTLR1_CH1M_0                       ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIMER_CHCTLR1_CH1M_1                       ((uint16_t)0x0002)            /*!<Bit 1 */

#define  TIMER_CHCTLR1_CH1OFE                       ((uint16_t)0x0004)            /*!<Output Compare 1 Fast enable */
#define  TIMER_CHCTLR1_CH1OSE                       ((uint16_t)0x0008)            /*!<Output Compare 1 Preload enable */
								          
#define  TIMER_CHCTLR1_CH1OM                        ((uint16_t)0x0070)            /*!<CH1OM[2:0] bits (Output Compare 1 Mode) */
#define  TIMER_CHCTLR1_CH1OM_0                      ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIMER_CHCTLR1_CH1OM_1                      ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIMER_CHCTLR1_CH1OM_2                      ((uint16_t)0x0040)            /*!<Bit 2 */

#define  TIMER_CHCTLR1_CH1OCE                       ((uint16_t)0x0080)            /*!<Output Compare 1Clear Enable */

#define  TIMER_CHCTLR1_CH2M                         ((uint16_t)0x0300)            /*!<CH2M[1:0] bits (Capture/Compare 2 Selection) */
#define  TIMER_CHCTLR1_CH2M_0                       ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIMER_CHCTLR1_CH2M_1                       ((uint16_t)0x0200)            /*!<Bit 1 */

#define  TIMER_CHCTLR1_CH2OFE                       ((uint16_t)0x0400)            /*!<Output Compare 2 Fast enable */
#define  TIMER_CHCTLR1_CH2OSE                       ((uint16_t)0x0800)            /*!<Output Compare 2 Preload enable */

#define  TIMER_CHCTLR1_CH2OM                        ((uint16_t)0x7000)            /*!<CH2OM[2:0] bits (Output Compare 2 Mode) */
#define  TIMER_CHCTLR1_CH2OM_0                      ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIMER_CHCTLR1_CH2OM_1                      ((uint16_t)0x2000)            /*!<Bit 1 */
#define  TIMER_CHCTLR1_CH2OM_2                      ((uint16_t)0x4000)            /*!<Bit 2 */

#define  TIMER_CHCTLR1_CH2OCE                       ((uint16_t)0x8000)            /*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIMER_CHCTLR1_CH1ICP                       ((uint16_t)0x000C)            /*!<CH1ICP[1:0] bits (Input Capture 1 Prescaler) */
#define  TIMER_CHCTLR1_CH1ICP_0                     ((uint16_t)0x0004)            /*!<Bit 0 */
#define  TIMER_CHCTLR1_CH1ICP_1                     ((uint16_t)0x0008)            /*!<Bit 1 */

#define  TIMER_CHCTLR1_CH1ICF                       ((uint16_t)0x00F0)            /*!<CH1ICF[3:0] bits (Input Capture 1 Filter) */
#define  TIMER_CHCTLR1_CH1ICF_0                     ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIMER_CHCTLR1_CH1ICF_1                     ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIMER_CHCTLR1_CH1ICF_2                     ((uint16_t)0x0040)            /*!<Bit 2 */
#define  TIMER_CHCTLR1_CH1ICF_3                     ((uint16_t)0x0080)            /*!<Bit 3 */
									       
#define  TIMER_CHCTLR1_CH2ICP                       ((uint16_t)0x0C00)            /*!<CH2ICP[1:0] bits (Input Capture 2 Prescaler) */
#define  TIMER_CHCTLR1_CH2ICP_0                     ((uint16_t)0x0400)            /*!<Bit 0 */
#define  TIMER_CHCTLR1_CH2ICP_1                     ((uint16_t)0x0800)            /*!<Bit 1 */

#define  TIMER_CHCTLR1_CH2ICF                       ((uint16_t)0xF000)            /*!<CH2ICF[3:0] bits (Input Capture 2 Filter) */
#define  TIMER_CHCTLR1_CH2ICF_0                     ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIMER_CHCTLR1_CH2ICF_1                     ((uint16_t)0x2000)            /*!<Bit 1 */
#define  TIMER_CHCTLR1_CH2ICF_2                     ((uint16_t)0x4000)            /*!<Bit 2 */
#define  TIMER_CHCTLR1_CH2ICF_3                     ((uint16_t)0x8000)            /*!<Bit 3 */

/******************  Bit definition for TIMER_CHCTLR2 register  *******************/
#define  TIMER_CHCTLR2_CH3M                         ((uint16_t)0x0003)            /*!<CH3M[1:0] bits (Capture/Compare 3 Selection) */
#define  TIMER_CHCTLR2_CH3M_0                       ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIMER_CHCTLR2_CH3M_1                       ((uint16_t)0x0002)            /*!<Bit 1 */
									        
#define  TIMER_CHCTLR2_CH3OFE                       ((uint16_t)0x0004)            /*!<Output Compare 3 Fast enable */
#define  TIMER_CHCTLR2_CH3OSE                       ((uint16_t)0x0008)            /*!<Output Compare 3 Preload enable */
										       
#define  TIMER_CHCTLR2_CH3OM                        ((uint16_t)0x0070)            /*!<CH3OM[2:0] bits (Output Compare 3 Mode) */
#define  TIMER_CHCTLR2_CH3OM_0                      ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIMER_CHCTLR2_CH3OM_1                      ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIMER_CHCTLR2_CH3OM_2                      ((uint16_t)0x0040)            /*!<Bit 2 */

#define  TIMER_CHCTLR2_CH3OCE                       ((uint16_t)0x0080)            /*!<Output Compare 3 Clear Enable */

#define  TIMER_CHCTLR2_CH4M                         ((uint16_t)0x0300)            /*!<CH4M[1:0] bits (Capture/Compare 4 Selection) */
#define  TIMER_CHCTLR2_CH4M_0                       ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIMER_CHCTLR2_CH4M_1                       ((uint16_t)0x0200)            /*!<Bit 1 */

#define  TIMER_CHCTLR2_CH4OFE                       ((uint16_t)0x0400)            /*!<Output Compare 4 Fast enable */
#define  TIMER_CHCTLR2_CH4OSE                       ((uint16_t)0x0800)            /*!<Output Compare 4 Preload enable */

#define  TIMER_CHCTLR2_CH4OM                        ((uint16_t)0x7000)            /*!<CH4OM[2:0] bits (Output Compare 4 Mode) */
#define  TIMER_CHCTLR2_CH4OM_0                      ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIMER_CHCTLR2_CH4OM_1                      ((uint16_t)0x2000)            /*!<Bit 1 */
#define  TIMER_CHCTLR2_CH4OM_2                      ((uint16_t)0x4000)            /*!<Bit 2 */

#define  TIMER_CHCTLR2_CH4OCE                       ((uint16_t)0x8000)            /*!<Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIMER_CHCTLR2_CH3ICP                       ((uint16_t)0x000C)            /*!<CH3ICP[1:0] bits (Input Capture 3 Prescaler) */
#define  TIMER_CHCTLR2_CH3ICP_0                     ((uint16_t)0x0004)            /*!<Bit 0 */
#define  TIMER_CHCTLR2_CH3ICP_1                     ((uint16_t)0x0008)            /*!<Bit 1 */

#define  TIMER_CHCTLR2_CH3ICF                       ((uint16_t)0x00F0)            /*!<CH3ICF[3:0] bits (Input Capture 3 Filter) */
#define  TIMER_CHCTLR2_CH3ICF_0                     ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIMER_CHCTLR2_CH3ICF_1                     ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIMER_CHCTLR2_CH3ICF_2                     ((uint16_t)0x0040)            /*!<Bit 2 */
#define  TIMER_CHCTLR2_CH3ICF_3                     ((uint16_t)0x0080)            /*!<Bit 3 */

#define  TIMER_CHCTLR2_CH4ICP                       ((uint16_t)0x0C00)            /*!<CH4ICP[1:0] bits (Input Capture 4 Prescaler) */
#define  TIMER_CHCTLR2_CH4ICP_0                     ((uint16_t)0x0400)            /*!<Bit 0 */
#define  TIMER_CHCTLR2_CH4ICP_1                     ((uint16_t)0x0800)            /*!<Bit 1 */

#define  TIMER_CHCTLR2_CH4ICF                       ((uint16_t)0xF000)            /*!<CH4ICF[3:0] bits (Input Capture 4 Filter) */
#define  TIMER_CHCTLR2_CH4ICF_0                     ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIMER_CHCTLR2_CH4ICF_1                     ((uint16_t)0x2000)            /*!<Bit 1 */
#define  TIMER_CHCTLR2_CH4ICF_2                     ((uint16_t)0x4000)            /*!<Bit 2 */
#define  TIMER_CHCTLR2_CH4ICF_3                     ((uint16_t)0x8000)            /*!<Bit 3 */

/*******************  Bit definition for TIMER_CHE register  *******************/
#define  TIMER_CHE_CH1E                             ((uint16_t)0x0001)            /*!<Capture/Compare 1 output enable */
#define  TIMER_CHE_CH1P                             ((uint16_t)0x0002)            /*!<Capture/Compare 1 output Polarity */
#define  TIMER_CHE_CH1NE                            ((uint16_t)0x0004)            /*!<Capture/Compare 1 Complementary output enable */
#define  TIMER_CHE_CH1NP                            ((uint16_t)0x0008)            /*!<Capture/Compare 1 Complementary output Polarity */
#define  TIMER_CHE_CH2E                             ((uint16_t)0x0010)            /*!<Capture/Compare 2 output enable */
#define  TIMER_CHE_CH2P                             ((uint16_t)0x0020)            /*!<Capture/Compare 2 output Polarity */
#define  TIMER_CHE_CH2NE                            ((uint16_t)0x0040)            /*!<Capture/Compare 2 Complementary output enable */
#define  TIMER_CHE_CH2NP                            ((uint16_t)0x0080)            /*!<Capture/Compare 2 Complementary output Polarity */
#define  TIMER_CHE_CH3E                             ((uint16_t)0x0100)            /*!<Capture/Compare 3 output enable */
#define  TIMER_CHE_CH3P                             ((uint16_t)0x0200)            /*!<Capture/Compare 3 output Polarity */
#define  TIMER_CHE_CH3NE                            ((uint16_t)0x0400)            /*!<Capture/Compare 3 Complementary output enable */
#define  TIMER_CHE_CH3NP                            ((uint16_t)0x0800)            /*!<Capture/Compare 3 Complementary output Polarity */
#define  TIMER_CHE_CH4E                             ((uint16_t)0x1000)            /*!<Capture/Compare 4 output enable */
#define  TIMER_CHE_CH4P                             ((uint16_t)0x2000)            /*!<Capture/Compare 4 output Polarity */
#define  TIMER_CHE_CH4NP                            ((uint16_t)0x8000)            /*!<Capture/Compare 4 Complementary output Polarity */

/*******************  Bit definition for TIMER_CNT register  ********************/
#define  TIMER_CNT_CNT                              ((uint16_t)0xFFFF)            /*!<Counter Value */

/*******************  Bit definition for TIMER_PSC register  ********************/
#define  TIMER_PSC_PSC                              ((uint16_t)0xFFFF)            /*!<Prescaler Value */

/*******************  Bit definition for TIMER_CARL register  ********************/
#define  TIMER_CARL_CARL                            ((uint16_t)0xFFFF)            /*!<actual auto-reload Value */

/*******************  Bit definition for TIMER_CREP register  ********************/
#define  TIMER_CREP_CREP                            ((uint8_t)0xFF)               /*!<Repetition Counter Value */

/*******************  Bit definition for TIMER_CHCC1 register  *******************/
#define  TIMER_CHCC1_CHCC1                          ((uint16_t)0xFFFF)            /*!<Capture/Compare 1 Value */

/*******************  Bit definition for TIMER_CHCC2 register  *******************/
#define  TIMER_CHCC2_CHCC2                          ((uint16_t)0xFFFF)            /*!<Capture/Compare 2 Value */

/*******************  Bit definition for TIMER_CHCC3 register  *******************/
#define  TIMER_CHCC3_CHCC3                          ((uint16_t)0xFFFF)            /*!<Capture/Compare 3 Value */

/*******************  Bit definition for TIMER_CHCC4 register  *******************/
#define  TIMER_CHCC4_CHCC4                          ((uint16_t)0xFFFF)            /*!<Capture/Compare 4 Value */

/*******************  Bit definition for TIMER_BKDT register  *******************/
#define  TIMER_BKDT_DT                              ((uint16_t)0x00FF)            /*!<DT[0:7] bits (Dead-TIMERe Generator set-up) */
#define  TIMER_BKDT_DT_0                            ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIMER_BKDT_DT_1                            ((uint16_t)0x0002)            /*!<Bit 1 */
#define  TIMER_BKDT_DT_2                            ((uint16_t)0x0004)            /*!<Bit 2 */
#define  TIMER_BKDT_DT_3                            ((uint16_t)0x0008)            /*!<Bit 3 */
#define  TIMER_BKDT_DT_4                            ((uint16_t)0x0010)            /*!<Bit 4 */
#define  TIMER_BKDT_DT_5                            ((uint16_t)0x0020)            /*!<Bit 5 */
#define  TIMER_BKDT_DT_6                            ((uint16_t)0x0040)            /*!<Bit 6 */
#define  TIMER_BKDT_DT_7                            ((uint16_t)0x0080)            /*!<Bit 7 */

#define  TIMER_BKDT_LK                              ((uint16_t)0x0300)            /*!<LK[1:0] bits (Lock Configuration) */
#define  TIMER_BKDT_LK_0                            ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIMER_BKDT_LK_1                            ((uint16_t)0x0200)            /*!<Bit 1 */

#define  TIMER_BKDT_IOS                             ((uint16_t)0x0400)            /*!<Off-State Selection for Idle mode */
#define  TIMER_BKDT_ROS                             ((uint16_t)0x0800)            /*!<Off-State Selection for Run mode */
#define  TIMER_BKDT_BRKE                            ((uint16_t)0x1000)            /*!<Break enable */
#define  TIMER_BKDT_BRKP                            ((uint16_t)0x2000)            /*!<Break Polarity */
#define  TIMER_BKDT_OAE                             ((uint16_t)0x4000)            /*!<Automatic Output enable */
#define  TIMER_BKDT_POE                             ((uint16_t)0x8000)            /*!<Main Output enable */

/*******************  Bit definition for TIMER_DCTLR register  ********************/
#define  TIMER_DCTLR_DBAR                           ((uint16_t)0x001F)            /*!<DBAR[4:0] bits (DMA Base Address) */
#define  TIMER_DCTLR_DBAR_0                         ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIMER_DCTLR_DBAR_1                         ((uint16_t)0x0002)            /*!<Bit 1 */
#define  TIMER_DCTLR_DBAR_2                         ((uint16_t)0x0004)            /*!<Bit 2 */
#define  TIMER_DCTLR_DBAR_3                         ((uint16_t)0x0008)            /*!<Bit 3 */
#define  TIMER_DCTLR_DBAR_4                         ((uint16_t)0x0010)            /*!<Bit 4 */

#define  TIMER_DCTLR_DBLTH                          ((uint16_t)0x1F00)            /*!<DBLTH[4:0] bits (DMA Burst Length) */
#define  TIMER_DCTLR_DBLTH_0                        ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIMER_DCTLR_DBLTH_1                        ((uint16_t)0x0200)            /*!<Bit 1 */
#define  TIMER_DCTLR_DBLTH_2                        ((uint16_t)0x0400)            /*!<Bit 2 */
#define  TIMER_DCTLR_DBLTH_3                        ((uint16_t)0x0800)            /*!<Bit 3 */
#define  TIMER_DCTLR_DBLTH_4                        ((uint16_t)0x1000)            /*!<Bit 4 */

/*******************  Bit definition for TIMER_DTRSF register  *******************/
#define  TIMER_DTRSF_DTRSF                          ((uint16_t)0xFFFF)            /*!<DMA register for burst accesses */

/******************************************************************************/
/*                                                                            */
/*                         Window WATCHDOG (WWDG)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for WWDG_CTLR register  ********************/
#define  WWDG_CTLR_CNT                              ((uint8_t)0x7F)                  /*!< CNT[6:0] bits (7-Bit counter (MSB to LSB)) */
#define  WWDG_CTLR_CNT0                             ((uint8_t)0x01)                  /*!< Bit 0 */
#define  WWDG_CTLR_CNT1                             ((uint8_t)0x02)                  /*!< Bit 1 */
#define  WWDG_CTLR_CNT2                             ((uint8_t)0x04)                  /*!< Bit 2 */
#define  WWDG_CTLR_CNT3                             ((uint8_t)0x08)                  /*!< Bit 3 */
#define  WWDG_CTLR_CNT4                             ((uint8_t)0x10)                  /*!< Bit 4 */
#define  WWDG_CTLR_CNT5                             ((uint8_t)0x20)                  /*!< Bit 5 */
#define  WWDG_CTLR_CNT6                             ((uint8_t)0x40)                  /*!< Bit 6 */

#define  WWDG_CTLR_WDGEN                            ((uint8_t)0x80)                  /*!< Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define  WWDG_CFR_WIN                               ((uint16_t)0x007F)               /*!< WIN[6:0] bits (7-bit window value) */
#define  WWDG_CFR_WIN0                              ((uint16_t)0x0001)               /*!< Bit 0 */
#define  WWDG_CFR_WIN1                              ((uint16_t)0x0002)               /*!< Bit 1 */
#define  WWDG_CFR_WIN2                              ((uint16_t)0x0004)               /*!< Bit 2 */
#define  WWDG_CFR_WIN3                              ((uint16_t)0x0008)               /*!< Bit 3 */
#define  WWDG_CFR_WIN4                              ((uint16_t)0x0010)               /*!< Bit 4 */
#define  WWDG_CFR_WIN5                              ((uint16_t)0x0020)               /*!< Bit 5 */
#define  WWDG_CFR_WIN6                              ((uint16_t)0x0040)               /*!< Bit 6 */

#define  WWDG_CFR_PS                                ((uint16_t)0x0180)               /*!< PS[1:0] bits (Timer Base) */
#define  WWDG_CFR_PS0                               ((uint16_t)0x0080)               /*!< Bit 0 */
#define  WWDG_CFR_PS1                               ((uint16_t)0x0100)               /*!< Bit 1 */

#define  WWDG_CFR_EWI                               ((uint16_t)0x0200)               /*!< Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_STR register  ********************/
#define  WWDG_STR_EWIF                              ((uint8_t)0x01)                  /*!< Early Wakeup Interrupt Flag */

#ifdef __cplusplus
}
#endif

#endif /* __GD32F10X_H */

/******************* (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
