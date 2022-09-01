/******************************************************************************
 * @file:    stm32f10x_cl.h
 * @purpose: CMSIS Cortex-M3 Core Peripheral Access Layer Header File for the 
 *           ST STM32F10x Connectivity Line Device Series
 * @version: V1.02
 * @date:    22. December 2009
 *----------------------------------------------------------------------------
 *
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * ARM Limited (ARM) is supplying this software for use with Cortex-Mx 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __STM32F10x_CL_H__
#define __STM32F10x_CL_H__

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

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
  ADC_IRQn                    = 18,     /*!< ADC global Interrupt                                 */
  CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupts                                   */
  CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupts                                  */
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
  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
  OTG_FS_WKUP_IRQn            = 42,     /*!< USB On-The-Go FS Wakeup through EXTI Line Interrupt  */
  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */
  TIM6_IRQn                   = 54,     /*!< TIM6 global Interrupt                                */
  TIM7_IRQn                   = 55,     /*!< TIM7 global Interrupt                                */
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel1 global Interrupt                       */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel2 global Interrupt                       */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel3 global Interrupt                       */
  DMA2_Channel4_IRQn          = 59,     /*!< DMA2 Channel4 global Interrupts                      */
  DMA2_Channel5_IRQn          = 60,     /*!< DMA2 Channel5 global Interrupts                      */
  ETH_IRQn                    = 61,     /*!< Ethernet global interrupt                            */
  ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line interrupt          */
  CAN2_TX_IRQn                = 63,     /*!< CAN2 TX interrupts                                   */
  CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 interrupts                                  */
  CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 interrupt                                   */
  CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE interrupt                                   */
  OTG_FS_IRQn                 = 67,     /*!< USB On The Go FS global interrupt                    */
} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __MPU_PRESENT           0       /*!< STM32 does not provide a MPU present or not          */
#define __NVIC_PRIO_BITS        4       /*!< STM32 uses 4 Bits for the Priority Levels            */
#define __Vendor_SysTickConfig  0       /*!< Set to 1 if different SysTick Config is used         */


#include <core_cm3.h>                   /* Cortex-M3 processor and core peripherals               */
#include "system_stm32f10x_cl.h"        /* STM32 System                                           */


/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/*------------------------ Analog to Digital Converter -----------------------*/
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

/*------------------------ Digital to Analog Converter -----------------------*/
typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t SWTRIGR;
  __IO uint32_t DHR12R1;
  __IO uint32_t DHR12L1;
  __IO uint32_t DHR8R1;
  __IO uint32_t DHR12R2;
  __IO uint32_t DHR12L2;
  __IO uint32_t DHR8R2;
  __IO uint32_t DHR12RD;
  __IO uint32_t DHR12LD;
  __IO uint32_t DHR8RD;
  __IO uint32_t DOR1;
  __IO uint32_t DOR2;
} DAC_TypeDef;

/*------------------------ Backup Registers ----------------------------------*/
typedef struct
{
       uint32_t RESERVED0;
  __IO uint16_t DR1;
       uint16_t RESERVED1;
  __IO uint16_t DR2;
       uint16_t RESERVED2;
  __IO uint16_t DR3;
       uint16_t RESERVED3;
  __IO uint16_t DR4;
       uint16_t RESERVED4;
  __IO uint16_t DR5;
       uint16_t RESERVED5;
  __IO uint16_t DR6;
       uint16_t RESERVED6;
  __IO uint16_t DR7;
       uint16_t RESERVED7;
  __IO uint16_t DR8;
       uint16_t RESERVED8;
  __IO uint16_t DR9;
       uint16_t RESERVED9;
  __IO uint16_t DR10;
       uint16_t RESERVED10;
  __IO uint16_t RTCCR;
       uint16_t RESERVED11;
  __IO uint16_t CR;
       uint16_t RESERVED12;
  __IO uint16_t CSR;
       uint16_t RESERVED13[5];
  __IO uint16_t DR11;
       uint16_t RESERVED14;
  __IO uint16_t DR12;
       uint16_t RESERVED15;
  __IO uint16_t DR13;
       uint16_t RESERVED16;
  __IO uint16_t DR14;
       uint16_t RESERVED17;
  __IO uint16_t DR15;
       uint16_t RESERVED18;
  __IO uint16_t DR16;
       uint16_t RESERVED19;
  __IO uint16_t DR17;
       uint16_t RESERVED20;
  __IO uint16_t DR18;
       uint16_t RESERVED21;
  __IO uint16_t DR19;
       uint16_t RESERVED22;
  __IO uint16_t DR20;
       uint16_t RESERVED23;
  __IO uint16_t DR21;
       uint16_t RESERVED24;
  __IO uint16_t DR22;
       uint16_t RESERVED25;
  __IO uint16_t DR23;
       uint16_t RESERVED26;
  __IO uint16_t DR24;
       uint16_t RESERVED27;
  __IO uint16_t DR25;
       uint16_t RESERVED28;
  __IO uint16_t DR26;
       uint16_t RESERVED29;
  __IO uint16_t DR27;
       uint16_t RESERVED30;
  __IO uint16_t DR28;
       uint16_t RESERVED31;
  __IO uint16_t DR29;
       uint16_t RESERVED32;
  __IO uint16_t DR30;
       uint16_t RESERVED33;
  __IO uint16_t DR31;
       uint16_t RESERVED34;
  __IO uint16_t DR32;
       uint16_t RESERVED35;
  __IO uint16_t DR33;
       uint16_t RESERVED36;
  __IO uint16_t DR34;
       uint16_t RESERVED37;
  __IO uint16_t DR35;
       uint16_t RESERVED38;
  __IO uint16_t DR36;
       uint16_t RESERVED39;
  __IO uint16_t DR37;
       uint16_t RESERVED40;
  __IO uint16_t DR38;
       uint16_t RESERVED41;
  __IO uint16_t DR39;
       uint16_t RESERVED42;
  __IO uint16_t DR40;
       uint16_t RESERVED43;
  __IO uint16_t DR41;
       uint16_t RESERVED44;
  __IO uint16_t DR42;
       uint16_t RESERVED45;
} BKP_TypeDef;

/*------------------------ Controller Area Network ---------------------------*/
typedef struct
{
  __IO uint32_t TIR;
  __IO uint32_t TDTR;
  __IO uint32_t TDLR;
  __IO uint32_t TDHR;
} CAN_TxMailBox_TypeDef;

typedef struct
{
  __IO uint32_t RIR;
  __IO uint32_t RDTR;
  __IO uint32_t RDLR;
  __IO uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
  __IO uint32_t FR1;
  __IO uint32_t FR2;
} CAN_FilterRegister_TypeDef;

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
       uint32_t RESERVED0[88];
  CAN_TxMailBox_TypeDef      sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];
       uint32_t RESERVED1[12];
  __IO uint32_t FMR;
  __IO uint32_t FM1R;
       uint32_t RESERVED2;
  __IO uint32_t FS1R;
       uint32_t RESERVED3;
  __IO uint32_t FFA1R;
       uint32_t RESERVED4;
  __IO uint32_t FA1R;
       uint32_t RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[28];
} CAN_TypeDef;

/*------------------------ DMA Controller ------------------------------------*/
typedef struct
{
  __IO uint32_t CCR;
  __IO uint32_t CNDTR;
  __IO uint32_t CPAR;
  __IO uint32_t CMAR;
} DMA_CH_TypeDef;

typedef struct
{
  __IO uint32_t ISR;
  __IO uint32_t IFCR;
} DMA_TypeDef;

/*------------------------ External Interrupt/Event Controller ---------------*/
typedef struct
{
  __IO uint32_t IMR;
  __IO uint32_t EMR;
  __IO uint32_t RTSR;
  __IO uint32_t FTSR;
  __IO uint32_t SWIER;
  __IO uint32_t PR;
} EXTI_TypeDef;

/*------------------------ Flash Memory Interface and Option Bytes Registers -*/
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

/*------------------------ General Purpose and Alternate Function IO ---------*/
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

typedef struct
{
  __IO uint32_t EVCR;
  __IO uint32_t MAPR;
  __IO uint32_t EXTICR[4];
} AFIO_TypeDef;

/*------------------------ Inter-integrated Circuit Interface ----------------*/
typedef struct
{
  __IO uint16_t CR1;
       uint16_t RESERVED0;
  __IO uint16_t CR2;
       uint16_t RESERVED1;
  __IO uint16_t OAR1;
       uint16_t RESERVED2;
  __IO uint16_t OAR2;
       uint16_t RESERVED3;
  __IO uint16_t DR;
       uint16_t RESERVED4;
  __IO uint16_t SR1;
       uint16_t RESERVED5;
  __IO uint16_t SR2;
       uint16_t RESERVED6;
  __IO uint16_t CCR;
       uint16_t RESERVED7;
  __IO uint16_t TRISE;
       uint16_t RESERVED8;
} I2C_TypeDef;

/*------------------------ Independent Watchdog ------------------------------*/
typedef struct
{
  __IO uint32_t KR;
  __IO uint32_t PR;
  __IO uint32_t RLR;
  __IO uint32_t SR;
} IWDG_TypeDef;



/*------------------------ Power Control -------------------------------------*/
typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CSR;
} PWR_TypeDef;

/*------------------------ Reset and Clock Control ---------------------------*/
typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t APB2RSTR;
  __IO uint32_t APB1RSTR;
  __IO uint32_t AHBENR;
  __IO uint32_t APB2ENR;
  __IO uint32_t APB1ENR;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
  __IO uint32_t AHBSTR;
  __IO uint32_t CFGR2;
} RCC_TypeDef;

/*------------------------ Real-Time Clock -----------------------------------*/
typedef struct
{
  __IO uint16_t CRH;
       uint16_t RESERVED0;
  __IO uint16_t CRL;
       uint16_t RESERVED1;
  __IO uint16_t PRLH;
       uint16_t RESERVED2;
  __IO uint16_t PRLL;
       uint16_t RESERVED3;
  __IO uint16_t DIVH;
       uint16_t RESERVED4;
  __IO uint16_t DIVL;
       uint16_t RESERVED5;
  __IO uint16_t CNTH;
       uint16_t RESERVED6;
  __IO uint16_t CNTL;
       uint16_t RESERVED7;
  __IO uint16_t ALRH;
       uint16_t RESERVED8;
  __IO uint16_t ALRL;
       uint16_t RESERVED9;
} RTC_TypeDef;

/*------------------------ Serial Peripheral Interface -----------------------*/
typedef struct
{
  __IO uint16_t CR1;
       uint16_t RESERVED0;
  __IO uint16_t CR2;
       uint16_t RESERVED1;
  __IO uint16_t SR;
       uint16_t RESERVED2;
  __IO uint16_t DR;
       uint16_t RESERVED3;
  __IO uint16_t CRCPR;
       uint16_t RESERVED4;
  __IO uint16_t RXCRCR;
       uint16_t RESERVED5;
  __IO uint16_t TXCRCR;
       uint16_t RESERVED6;
  __IO uint16_t I2SCFGR;
       uint16_t RESERVED7;
  __IO uint16_t I2SPR;
       uint16_t RESERVED8;
} SPI_TypeDef;


/*------------------------ Advanced Control Timer ----------------------------*/
typedef struct
{
  __IO uint16_t CR1;
       uint16_t RESERVED0;
  __IO uint16_t CR2;
       uint16_t RESERVED1;
  __IO uint16_t SMCR;
       uint16_t RESERVED2;
  __IO uint16_t DIER;
       uint16_t RESERVED3;
  __IO uint16_t SR;
       uint16_t RESERVED4;
  __IO uint16_t EGR;
       uint16_t RESERVED5;
  __IO uint16_t CCMR1;
       uint16_t RESERVED6;
  __IO uint16_t CCMR2;
       uint16_t RESERVED7;
  __IO uint16_t CCER;
       uint16_t RESERVED8;
  __IO uint16_t CNT;
       uint16_t RESERVED9;
  __IO uint16_t PSC;
       uint16_t RESERVED10;
  __IO uint16_t ARR;
       uint16_t RESERVED11;
  __IO uint16_t RCR;
       uint16_t RESERVED12;
  __IO uint16_t CCR1;
       uint16_t RESERVED13;
  __IO uint16_t CCR2;
       uint16_t RESERVED14;
  __IO uint16_t CCR3;
       uint16_t RESERVED15;
  __IO uint16_t CCR4;
       uint16_t RESERVED16;
  __IO uint16_t BDTR;
       uint16_t RESERVED17;
  __IO uint16_t DCR;
       uint16_t RESERVED18;
  __IO uint16_t DMAR;
       uint16_t RESERVED19;
} TIM_AC_TypeDef;

/*------------------------ General Purpose Timer -----------------------------*/
typedef struct
{
  __IO uint16_t CR1;
       uint16_t RESERVED0;
  __IO uint16_t CR2;
       uint16_t RESERVED1;
  __IO uint16_t SMCR;
       uint16_t RESERVED2;
  __IO uint16_t DIER;
       uint16_t RESERVED3;
  __IO uint16_t SR;
       uint16_t RESERVED4;
  __IO uint16_t EGR;
       uint16_t RESERVED5;
  __IO uint16_t CCMR1;
       uint16_t RESERVED6;
  __IO uint16_t CCMR2;
       uint16_t RESERVED7;
  __IO uint16_t CCER;
       uint16_t RESERVED8;
  __IO uint16_t CNT;
       uint16_t RESERVED9;
  __IO uint16_t PSC;
       uint16_t RESERVED10;
  __IO uint16_t ARR;
       uint16_t RESERVED11[3];
  __IO uint16_t CCR1;
       uint16_t RESERVED12;
  __IO uint16_t CCR2;
       uint16_t RESERVED13;
  __IO uint16_t CCR3;
       uint16_t RESERVED14;
  __IO uint16_t CCR4;
       uint16_t RESERVED15[3];
  __IO uint16_t DCR;
       uint16_t RESERVED16;
  __IO uint16_t DMAR;
       uint16_t RESERVED17;
} TIM_GP_TypeDef;

/*------------------------ Basic Timer ---------------------------------------*/
typedef struct
{
  __IO uint16_t CR1;
       uint16_t RESERVED0;
  __IO uint16_t CR2;
       uint16_t RESERVED1[3];
  __IO uint16_t DIER;
       uint16_t RESERVED2;
  __IO uint16_t SR;
       uint16_t RESERVED3;
  __IO uint16_t EGR;
       uint16_t RESERVED4[7];
  __IO uint16_t CNT;
       uint16_t RESERVED5;
  __IO uint16_t PSC;
       uint16_t RESERVED6;
  __IO uint16_t ARR;
       uint16_t RESERVED7;
} TIM_B_TypeDef;

/*----------------- Universal Synchronous Asynchronous Receiver Transmitter --*/
typedef struct
{
  __IO uint16_t SR;
       uint16_t RESERVED0;
  __IO uint16_t DR;
       uint16_t RESERVED1;
  __IO uint16_t BRR;
       uint16_t RESERVED2;
  __IO uint16_t CR1;
       uint16_t RESERVED3;
  __IO uint16_t CR2;
       uint16_t RESERVED4;
  __IO uint16_t CR3;
       uint16_t RESERVED5;
  __IO uint16_t GTPR;
       uint16_t RESERVED6;
} USART_TypeDef;

/*------------------------ Window Watchdog -----------------------------------*/
typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFR;
  __IO uint32_t SR;
} WWDG_TypeDef;

/*------------------------ CRC Calculation Unit ------------------------------*/
typedef struct
{
  __IO uint32_t DR;
  __IO uint32_t IDR;
  __IO uint32_t CR;
} CRC_TypeDef;

/*------------------------ USB Full Speed Device Interface (USB_FS) ----------*/
typedef struct
{
  __IO uint32_t EP0R;
  __IO uint32_t EP1R;
  __IO uint32_t EP2R;
  __IO uint32_t EP3R;
  __IO uint32_t EP4R;
  __IO uint32_t EP5R;
  __IO uint32_t EP6R;
  __IO uint32_t EP7R;
       uint32_t RESERVED0[8];
  __IO uint32_t CNTR;
  __IO uint32_t ISTR;
  __IO uint32_t FNR;
  __IO uint32_t DADDR;
  __IO uint32_t BTABLE;
} USB_FS_TypeDef;

/*------ Ethernet (ETH): media access control (MAC) with DMA controller ------*/
typedef struct
{
  __IO uint32_t MACCR;
  __IO uint32_t MACFFR;
  __IO uint32_t MACHTHR;
  __IO uint32_t MACHTLR;
  __IO uint32_t MACMIIAR;
  __IO uint32_t MACMIIDR;
  __IO uint32_t MACFCR;
  __IO uint32_t MACVLANTR;
       uint32_t RESERVED0[2];
  __IO uint32_t MACRWUFFR;
  __IO uint32_t MACPMTCSR;
       uint32_t RESERVED1[2];
  __IO uint32_t MACSR;
  __IO uint32_t MACIMR;
  __IO uint32_t MACA0HR;
  __IO uint32_t MACA0LR;
  __IO uint32_t MACA1HR;
  __IO uint32_t MACA1LR;
  __IO uint32_t MACA2HR;
  __IO uint32_t MACA2LR;
  __IO uint32_t MACA3HR;
  __IO uint32_t MACA3LR;
       uint32_t RESERVED2[40];
  __IO uint32_t MMCCR;
  __IO uint32_t MMCRIR;
  __IO uint32_t MMCTIR;
  __IO uint32_t MMCRIMR;
  __IO uint32_t MMCTIMR;
       uint32_t RESERVED3[14];
  __IO uint32_t MMCTGFSCCR;
  __IO uint32_t MMCTGFMSCCR;
       uint32_t RESERVED4[5];
  __IO uint32_t MMCTGFCR;
       uint32_t RESERVED5[10];
  __IO uint32_t MMCRFCECR;
  __IO uint32_t MMCRFAECR;
       uint32_t RESERVED6[10];
  __IO uint32_t MMCRGUFCR;
       uint32_t RESERVED7[334];
  __IO uint32_t PTPTSCR;
  __IO uint32_t PTPSSIR;
  __IO uint32_t PTPTSHR;
  __IO uint32_t PTPTSLR;
  __IO uint32_t PTPTSHUR;
  __IO uint32_t PTPTSLUR;
  __IO uint32_t PTPTSAR;
  __IO uint32_t PTPTTHR;
  __IO uint32_t PTPTTLR;
       uint32_t RESERVED8[567];
  __IO uint32_t DMABMR;
  __IO uint32_t DMATPDR;
  __IO uint32_t DMARPDR;
  __IO uint32_t DMARDLAR;
  __IO uint32_t DMATDLAR;
  __IO uint32_t DMASR;
  __IO uint32_t DMAOMR;
  __IO uint32_t DMAIER;
  __IO uint32_t DMAMFBOCR;
       uint32_t RESERVED9[9];
  __IO uint32_t DMACHTDR;
  __IO uint32_t DMACHRDR;
  __IO uint32_t DMACHTBAR;
  __IO uint32_t DMACHRBAR;
} ETH_TypeDef;

/*------ USB On-The-Go Full Speed (OTG_FS) Controller ------------------------*/
typedef struct
{
  __IO uint32_t GOTGCTL;
  __IO uint32_t GOTGINT;
  __IO uint32_t GAHBCFG;
  __IO uint32_t GUSBCFG;
  __IO uint32_t GRSTCTL;
  __IO uint32_t GINTSTS;
  __IO uint32_t GINTMSK;
  __IO uint32_t GRXSTSR;
  __IO uint32_t GRXSTSP;
  __IO uint32_t GRXFSIZ;
  __IO uint32_t GNPTXFSIZ;
  __IO uint32_t GNPTXSTS;
       uint32_t RESERVED0[2];
  __IO uint32_t GCCFG;
  __IO uint32_t CID;
       uint32_t RESERVED1[48];
  __IO uint32_t HPTXFSIZ;
  __IO uint32_t DIEPTXF1;
  __IO uint32_t DIEPTXF2;
  __IO uint32_t DIEPTXF3;
  __IO uint32_t DIEPTXF4;
       uint32_t RESERVED2[187];
  __IO uint32_t HCFG;
  __IO uint32_t HFIR;
  __IO uint32_t HFNUM;
       uint32_t RESERVED3;
  __IO uint32_t HPTXSTS;
  __IO uint32_t HAINT;
  __IO uint32_t HAINTMSK;
       uint32_t RESERVED4[9];
  __IO uint32_t HPRT;
       uint32_t RESERVED5[47];
  __IO uint32_t HCCHAR0;
       uint32_t RESERVED6;
  __IO uint32_t HCINT0;
  __IO uint32_t HCINTMSK0;
  __IO uint32_t HCTSIZ0;
       uint32_t RESERVED7[3];
  __IO uint32_t HCCHAR1;
       uint32_t RESERVED8;
  __IO uint32_t HCINT1;
  __IO uint32_t HCINTMSK1;
  __IO uint32_t HCTSIZ1;
       uint32_t RESERVED9[3];
  __IO uint32_t HCCHAR2;
       uint32_t RESERVED10;
  __IO uint32_t HCINT2;
  __IO uint32_t HCINTMSK2;
  __IO uint32_t HCTSIZ2;
       uint32_t RESERVED11[3];
  __IO uint32_t HCCHR3;
       uint32_t RESERVED12;
  __IO uint32_t HCINT3;
  __IO uint32_t HCINTMSK3;
  __IO uint32_t HCTSIZ3;
       uint32_t RESERVED13[3];
  __IO uint32_t HCCHR4;
       uint32_t RESERVED14;
  __IO uint32_t HCINT4;
  __IO uint32_t HCINTMSK4;
  __IO uint32_t HCTSIZ4;
       uint32_t RESERVED15[3];
  __IO uint32_t HCCHR5;
       uint32_t RESERVED16;
  __IO uint32_t HCINT5;
  __IO uint32_t HCINTMSK5;
  __IO uint32_t HCTSIZ5;
       uint32_t RESERVED17[3];
  __IO uint32_t HCCHR6;
       uint32_t RESERVED18;
  __IO uint32_t HCINT6;
  __IO uint32_t HCINTMSK6;
  __IO uint32_t HCTSIZ6;
       uint32_t RESERVED19[3];
  __IO uint32_t HCCHR7;
       uint32_t RESERVED20;
  __IO uint32_t HCINT7;
  __IO uint32_t HCINTMSK7;
  __IO uint32_t HCTSIZ7;
       uint32_t RESERVED21[3];
  __IO uint32_t HCCHR8;
       uint32_t RESERVED22;
  __IO uint32_t HCINT8;
  __IO uint32_t HCINTMSK8;
  __IO uint32_t HCTSIZ8;
       uint32_t RESERVED23[3];
  __IO uint32_t HCCHR9;
       uint32_t RESERVED24;
  __IO uint32_t HCINT9;
  __IO uint32_t HCINTMSK9;
  __IO uint32_t HCTSIZ9;
       uint32_t RESERVED25[3];
  __IO uint32_t HCCHR10;
       uint32_t RESERVED26;
  __IO uint32_t HCINT10;
  __IO uint32_t HCINTMSK10;
  __IO uint32_t HCTSIZ10;
       uint32_t RESERVED27[3];
  __IO uint32_t HCCHR11;
       uint32_t RESERVED28;
  __IO uint32_t HCINT11;
  __IO uint32_t HCINTMSK11;
  __IO uint32_t HCTSIZ11;
       uint32_t RESERVED29[3];
  __IO uint32_t HCCHR12;
       uint32_t RESERVED30;
  __IO uint32_t HCINT12;
  __IO uint32_t HCINTMSK12;
  __IO uint32_t HCTSIZ12;
       uint32_t RESERVED31[3];
  __IO uint32_t HCCHR13;
       uint32_t RESERVED32;
  __IO uint32_t HCINT13;
  __IO uint32_t HCINTMSK13;
  __IO uint32_t HCTSIZ13;
       uint32_t RESERVED33[3];
  __IO uint32_t HCCHR14;
       uint32_t RESERVED34;
  __IO uint32_t HCINT14;
  __IO uint32_t HCINTMSK14;
  __IO uint32_t HCTSIZ14;
       uint32_t RESERVED35[3];
  __IO uint32_t HCCHR15;
       uint32_t RESERVED36;
  __IO uint32_t HCINT15;
  __IO uint32_t HCINTMSK15;
  __IO uint32_t HCTSIZ15;
       uint32_t RESERVED37[3];
       uint32_t RESERVED38[64];
  __IO uint32_t DCFG;
  __IO uint32_t DCTL;
  __IO uint32_t DSTS;
       uint32_t RESERVED39;
  __IO uint32_t DIEPMSK;
  __IO uint32_t DOEPMSK;
  __IO uint32_t DAINT;
  __IO uint32_t DAINTMSK;
       uint32_t RESERVED40[2];
  __IO uint32_t DVBUSDIS;
  __IO uint32_t DVBUSPULSE;
       uint32_t RESERVED41;
  __IO uint32_t DIEPEMPMSK;
       uint32_t RESERVED42[50];
  __IO uint32_t DIEPCTL0;
       uint32_t RESERVED43;
  __IO uint32_t DIEPINT0;
       uint32_t RESERVED44;
  __IO uint32_t DIEPTSIZ0;
       uint32_t RESERVED45;
  __IO uint32_t DTXFSTS0;
       uint32_t RESERVED46;
  __IO uint32_t DIEPCTL1;
       uint32_t RESERVED47;
  __IO uint32_t DIEPINT1;
       uint32_t RESERVED48;
  __IO uint32_t DIEPTSIZ1;
       uint32_t RESERVED49;
  __IO uint32_t DTXFSTS1;
       uint32_t RESERVED50;
  __IO uint32_t DIEPCTL2;
       uint32_t RESERVED51;
  __IO uint32_t DIEPINT2;
       uint32_t RESERVED52;
  __IO uint32_t DIEPTSIZ2;
       uint32_t RESERVED53;
  __IO uint32_t DTXFSTS2;
       uint32_t RESERVED54;
  __IO uint32_t DIEPCTL3;
       uint32_t RESERVED55;
  __IO uint32_t DIEPINT3;
       uint32_t RESERVED56;
  __IO uint32_t DIEPTSIZ3;
       uint32_t RESERVED57;
  __IO uint32_t DTXFSTS3;
       uint32_t RESERVED58;
  __IO uint32_t DIEPCTL4;
       uint32_t RESERVED59;
  __IO uint32_t DIEPINT4;
       uint32_t RESERVED60;
  __IO uint32_t DIEPTSIZ4;
       uint32_t RESERVED61;
  __IO uint32_t DTXFSTS4;
       uint32_t RESERVED62;
  __IO uint32_t DIEPCTL5;
       uint32_t RESERVED63;
  __IO uint32_t DIEPINT5;
       uint32_t RESERVED64;
  __IO uint32_t DIEPTSIZ5;
       uint32_t RESERVED65[3];
  __IO uint32_t DIEPCTL6;
       uint32_t RESERVED66;
  __IO uint32_t DIEPINT6;
       uint32_t RESERVED67;
  __IO uint32_t DIEPTSIZ6;
       uint32_t RESERVED68[3];
  __IO uint32_t DIEPCTL7;
       uint32_t RESERVED69;
  __IO uint32_t DIEPINT7;
       uint32_t RESERVED70;
  __IO uint32_t DIEPTSIZ7;
       uint32_t RESERVED71[3];
  __IO uint32_t DIEPCTL8;
       uint32_t RESERVED72;
  __IO uint32_t DIEPINT8;
       uint32_t RESERVED73;
  __IO uint32_t DIEPTSIZ8;
       uint32_t RESERVED74[3];
  __IO uint32_t DIEPCTL9;
       uint32_t RESERVED75;
  __IO uint32_t DIEPINT9;
       uint32_t RESERVED76;
  __IO uint32_t DIEPTSIZ9;
       uint32_t RESERVED77[3];
  __IO uint32_t DIEPCTL10;
       uint32_t RESERVED78;
  __IO uint32_t DIEPINT10;
       uint32_t RESERVED79;
  __IO uint32_t DIEPTSIZ10;
       uint32_t RESERVED80[3];
  __IO uint32_t DIEPCTL11;
       uint32_t RESERVED81;
  __IO uint32_t DIEPINT11;
       uint32_t RESERVED82;
  __IO uint32_t DIEPTSIZ11;
       uint32_t RESERVED83[3];
  __IO uint32_t DIEPCTL12;
       uint32_t RESERVED84;
  __IO uint32_t DIEPINT12;
       uint32_t RESERVED85;
  __IO uint32_t DIEPTSIZ86;
       uint32_t RESERVED86[3];
  __IO uint32_t DIEPCTL13;
       uint32_t RESERVED87;
  __IO uint32_t DIEPINT13;
       uint32_t RESERVED88;
  __IO uint32_t DIEPTSIZ13;
       uint32_t RESERVED89[3];
  __IO uint32_t DIEPCTL14;
       uint32_t RESERVED90;
  __IO uint32_t DIEPINT14;
       uint32_t RESERVED91;
  __IO uint32_t DIEPTSIZ14;
       uint32_t RESERVED92[3];
  __IO uint32_t DIEPCTL15;
       uint32_t RESERVED93;
  __IO uint32_t DIEPINT15;
       uint32_t RESERVED94;
  __IO uint32_t DIEPTSIZ15;
       uint32_t RESERVED95[3];
  __IO uint32_t DOEPCTL0;
       uint32_t RESERVED96;
  __IO uint32_t DOEPINT0;
       uint32_t RESERVED97;
  __IO uint32_t DOEPTSIZ0;
       uint32_t RESERVED98[3];
  __IO uint32_t DOEPCTL1;
       uint32_t RESERVED99;
  __IO uint32_t DOEPINT1;
       uint32_t RESERVED100;
  __IO uint32_t DOEPTSIZ1;
       uint32_t RESERVED101[3];
  __IO uint32_t DOEPCTL2;
       uint32_t RESERVED102;
  __IO uint32_t DOEPINT2;
       uint32_t RESERVED103;
  __IO uint32_t DOEPTSIZ2;
       uint32_t RESERVED104[3];
  __IO uint32_t DOEPCTL3;
       uint32_t RESERVED105;
  __IO uint32_t DOEPINT3;
       uint32_t RESERVED106;
  __IO uint32_t DOEPTSIZ3;
       uint32_t RESERVED107[3];
  __IO uint32_t DOEPCTL4;
       uint32_t RESERVED108;
  __IO uint32_t DOEPINT4;
       uint32_t RESERVED109;
  __IO uint32_t DOEPTSIZ4;
       uint32_t RESERVED110[3];
  __IO uint32_t DOEPCTL5;
       uint32_t RESERVED111;
  __IO uint32_t DOEPINT5;
       uint32_t RESERVED112;
  __IO uint32_t DOEPTSIZ5;
       uint32_t RESERVED113[3];
  __IO uint32_t DOEPCTL6;
       uint32_t RESERVED114;
  __IO uint32_t DOEPINT6;
       uint32_t RESERVED115;
  __IO uint32_t DOEPTSIZ6;
       uint32_t RESERVED116[3];
  __IO uint32_t DOEPCTL7;
       uint32_t RESERVED117;
  __IO uint32_t DOEPINT7;
       uint32_t RESERVED118;
  __IO uint32_t DOEPTSIZ7;
       uint32_t RESERVED119[3];
  __IO uint32_t DOEPCTL8;
       uint32_t RESERVED120;
  __IO uint32_t DOEPINT8;
       uint32_t RESERVED121;
  __IO uint32_t DOEPTSIZ8;
       uint32_t RESERVED122[3];
  __IO uint32_t DOEPCTL9;
       uint32_t RESERVED123;
  __IO uint32_t DOEPINT9;
       uint32_t RESERVED124;
  __IO uint32_t DOEPTSIZ9;
       uint32_t RESERVED125[3];
  __IO uint32_t DOEPCTL10;
       uint32_t RESERVED126;
  __IO uint32_t DOEPINT10;
       uint32_t RESERVED127;
  __IO uint32_t DOEPTSIZ10;
       uint32_t RESERVED128[3];
  __IO uint32_t DOEPCTL11;
       uint32_t RESERVED129;
  __IO uint32_t DOEPINT11;
       uint32_t RESERVED130;
  __IO uint32_t DOEPTSIZ11;
       uint32_t RESERVED131[3];
  __IO uint32_t DOEPCTL12;
       uint32_t RESERVED132;
  __IO uint32_t DOEPINT12;
       uint32_t RESERVED133;
  __IO uint32_t DOEPTSIZ12;
       uint32_t RESERVED134[3];
  __IO uint32_t DOEPCTL13;
       uint32_t RESERVED135;
  __IO uint32_t DOEPINT13;
       uint32_t RESERVED136;
  __IO uint32_t DOEPTSIZ13;
       uint32_t RESERVED137[3];
  __IO uint32_t DOEPCTL14;
       uint32_t RESERVED138;
  __IO uint32_t DOEPINT14;
       uint32_t RESERVED139;
  __IO uint32_t DOEPTSIZ14;
       uint32_t RESERVED140[3];
  __IO uint32_t DOEPCTL15;
       uint32_t RESERVED141;
  __IO uint32_t DOEPINT15;
       uint32_t RESERVED142;
  __IO uint32_t DOEPTSIZ15;
       uint32_t RESERVED143[3];
       uint32_t RESERVED144[64];
  __IO uint32_t PCGCCTL;
} OTG_FS_TypeDef;


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Peripheral and SRAM base address in the alias region */
#define PERIPH_BB_BASE        ((     uint32_t)0x42000000)
#define SRAM_BB_BASE          ((     uint32_t)0x22000000)

/* Peripheral and SRAM base address in the bit-band region */
#define SRAM_BASE             ((     uint32_t)0x20000000)
#define PERIPH_BASE           ((     uint32_t)0x40000000)

/* Flash Option Bytes base address */
#define OB_BASE               ((     uint32_t)0x1FFFF800)

/* Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define USART4_BASE           (APB1PERIPH_BASE + 0x4C00)
#define USART5_BASE           (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define USB_FS_BASE           (APB1PERIPH_BASE + 0x5C00)
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
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2400)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2800)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)

#define DMA1_BASE             (AHBPERIPH_BASE  + 0x0000)
#define DMA1_CH1_BASE         (AHBPERIPH_BASE  + 0x0008)
#define DMA1_CH2_BASE         (AHBPERIPH_BASE  + 0x001C)
#define DMA1_CH3_BASE         (AHBPERIPH_BASE  + 0x0030)
#define DMA1_CH4_BASE         (AHBPERIPH_BASE  + 0x0044)
#define DMA1_CH5_BASE         (AHBPERIPH_BASE  + 0x0058)
#define DMA1_CH6_BASE         (AHBPERIPH_BASE  + 0x006C)
#define DMA1_CH7_BASE         (AHBPERIPH_BASE  + 0x0080)
#define DMA2_BASE             (AHBPERIPH_BASE  + 0x0400)
#define DMA2_CH1_BASE         (AHBPERIPH_BASE  + 0x0408)
#define DMA2_CH2_BASE         (AHBPERIPH_BASE  + 0x041C)
#define DMA2_CH3_BASE         (AHBPERIPH_BASE  + 0x0430)
#define DMA2_CH4_BASE         (AHBPERIPH_BASE  + 0x0444)
#define DMA2_CH5_BASE         (AHBPERIPH_BASE  + 0x0458)
#define DMA2_CH6_BASE         (AHBPERIPH_BASE  + 0x046C)
#define DMA2_CH7_BASE         (AHBPERIPH_BASE  + 0x0480)
#define RCC_BASE              (AHBPERIPH_BASE  + 0x1000)
#define FLASH_BASE            (AHBPERIPH_BASE  + 0x2000)
#define CRC_BASE              (AHBPERIPH_BASE  + 0x3000)
#define ETH_BASE              (AHBPERIPH_BASE  + 0x8000)
#define OTG_FS_BASE           (APB1PERIPH_BASE + 0x10000000)
#define OTG_FS_DFIFO0_BASE    (APB1PERIPH_BASE + 0x10001000)
#define OTG_FS_DFIFO1_BASE    (APB1PERIPH_BASE + 0x10002000)
#define OTG_FS_DFIFO2_BASE    (APB1PERIPH_BASE + 0x10003000)
#define OTG_FS_DFIFO3_BASE    (APB1PERIPH_BASE + 0x10004000)
#define OTG_FS_DFIFO4_BASE    (APB1PERIPH_BASE + 0x10005000)
#define OTG_FS_DFIFO5_BASE    (APB1PERIPH_BASE + 0x10006000)
#define OTG_FS_DFIFO6_BASE    (APB1PERIPH_BASE + 0x10007000)
#define OTG_FS_DFIFO7_BASE    (APB1PERIPH_BASE + 0x10008000)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define TIM2                  ((TIM_GP_TypeDef *) TIM2_BASE    )
#define TIM3                  ((TIM_GP_TypeDef *) TIM3_BASE    )
#define TIM4                  ((TIM_GP_TypeDef *) TIM4_BASE    )
#define TIM5                  ((TIM_GP_TypeDef *) TIM5_BASE    )
#define TIM6                  ((TIM_B_TypeDef  *) TIM6_BASE    )
#define TIM7                  ((TIM_B_TypeDef  *) TIM7_BASE    )
#define RTC                   ((RTC_TypeDef    *) RTC_BASE     )
#define WWDG                  ((WWDG_TypeDef   *) WWDG_BASE    )
#define IWDG                  ((IWDG_TypeDef   *) IWDG_BASE    )
#define SPI2                  ((SPI_TypeDef    *) SPI2_BASE    )
#define SPI3                  ((SPI_TypeDef    *) SPI3_BASE    )
#define USART2                ((USART_TypeDef  *) USART2_BASE  )
#define USART3                ((USART_TypeDef  *) USART3_BASE  )
#define USART4                ((USART_TypeDef  *) USART4_BASE  )
#define USART5                ((USART_TypeDef  *) USART5_BASE  )
#define I2C1                  ((I2C_TypeDef    *) I2C1_BASE    )
#define I2C2                  ((I2C_TypeDef    *) I2C2_BASE    )
#define USB_FS                ((USB_FS_TypeDef *) USB_FS_BASE  )
#define CAN1                  ((CAN_TypeDef    *) CAN1_BASE    )
#define CAN2                  ((CAN_TypeDef    *) CAN2_BASE    )
#define BKP                   ((BKP_TypeDef    *) BKP_BASE     )
#define PWR                   ((PWR_TypeDef    *) PWR_BASE     )
#define DAC                   ((DAC_TypeDef    *) DAC_BASE     )
#define AFIO                  ((AFIO_TypeDef   *) AFIO_BASE    )
#define EXTI                  ((EXTI_TypeDef   *) EXTI_BASE    )
#define GPIOA                 ((GPIO_TypeDef   *) GPIOA_BASE   )
#define GPIOB                 ((GPIO_TypeDef   *) GPIOB_BASE   )
#define GPIOC                 ((GPIO_TypeDef   *) GPIOC_BASE   )
#define GPIOD                 ((GPIO_TypeDef   *) GPIOD_BASE   )
#define GPIOE                 ((GPIO_TypeDef   *) GPIOE_BASE   )
#define ADC1                  ((ADC_TypeDef    *) ADC1_BASE    )
#define ADC2                  ((ADC_TypeDef    *) ADC2_BASE    )
#define TIM1                  ((TIM_AC_TypeDef *) TIM1_BASE    )
#define SPI1                  ((SPI_TypeDef    *) SPI1_BASE    )
#define USART1                ((USART_TypeDef  *) USART1_BASE  )
#define DMA1                  ((DMA_TypeDef    *) DMA1_BASE    )
#define DMA1_CH1              ((DMA_CH_TypeDef *) DMA1_CH1_BASE)
#define DMA1_CH2              ((DMA_CH_TypeDef *) DMA1_CH2_BASE)
#define DMA1_CH3              ((DMA_CH_TypeDef *) DMA1_CH3_BASE)
#define DMA1_CH4              ((DMA_CH_TypeDef *) DMA1_CH4_BASE)
#define DMA1_CH5              ((DMA_CH_TypeDef *) DMA1_CH5_BASE)
#define DMA1_CH6              ((DMA_CH_TypeDef *) DMA1_CH6_BASE)
#define DMA1_CH7              ((DMA_CH_TypeDef *) DMA1_CH7_BASE)
#define DMA2                  ((DMA_TypeDef    *) DMA2_BASE    )
#define DMA2_CH1              ((DMA_CH_TypeDef *) DMA2_CH1_BASE)
#define DMA2_CH2              ((DMA_CH_TypeDef *) DMA2_CH2_BASE)
#define DMA2_CH3              ((DMA_CH_TypeDef *) DMA2_CH3_BASE)
#define DMA2_CH4              ((DMA_CH_TypeDef *) DMA2_CH4_BASE)
#define DMA2_CH5              ((DMA_CH_TypeDef *) DMA2_CH5_BASE)
#define DMA2_CH6              ((DMA_CH_TypeDef *) DMA2_CH6_BASE)
#define DMA2_CH7              ((DMA_CH_TypeDef *) DMA2_CH7_BASE)
#define RCC                   ((RCC_TypeDef    *) RCC_BASE     )
#define FLASH                 ((FLASH_TypeDef  *) FLASH_BASE   )
#define CRC                   ((CRC_TypeDef    *) CRC_BASE     )
#define ETH                   ((ETH_TypeDef    *) ETH_BASE     )
#define OTG_FS                ((OTG_FS_TypeDef *) OTG_FS_BASE  )
#define OTG_FS_DFIFO0         (((uint32_t      *) OTG_FS_DFIFO0_BASE)  )
#define OTG_FS_DFIFO1         (((uint32_t      *) OTG_FS_DFIFO1_BASE)  )
#define OTG_FS_DFIFO2         (((uint32_t      *) OTG_FS_DFIFO2_BASE)  )
#define OTG_FS_DFIFO3         (((uint32_t      *) OTG_FS_DFIFO3_BASE)  )
#define OTG_FS_DFIFO4         (((uint32_t      *) OTG_FS_DFIFO4_BASE)  )
#define OTG_FS_DFIFO5         (((uint32_t      *) OTG_FS_DFIFO5_BASE)  )
#define OTG_FS_DFIFO6         (((uint32_t      *) OTG_FS_DFIFO6_BASE)  )
#define OTG_FS_DFIFO7         (((uint32_t      *) OTG_FS_DFIFO7_BASE)  )
#define OB                    ((OB_TypeDef     *) OB_BASE      )

#endif
