/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_M2XX__H_
#define YSS_INSTANCE_M2XX__H_

#include <NuMicro.h>

// YSS OS RUNTIME 설정 관련 정의
#define RUNTIME_TIMER0		1
#define RUNTIME_TIMER1		2
#define RUNTIME_TIMER2		3
#define RUNTIME_TIMER3		4

// YSS OS DELAY 설정 관련 정의
#define DELAY_TIMER0		1
#define DELAY_TIMER1		2
#define DELAY_TIMER2		3
#define DELAY_TIMER3		4

#if defined(BPWM0)
#include "NuvotonBpwm.h"
extern NuvotonBpwm bpwm0;
#endif

#if defined(BPWM1)
extern NuvotonBpwm bpwm1;
#endif

#if defined(CANFD0)
#include "NuvotonCanFd.h"
extern NuvotonCanFd canfd0;
#endif

#include "NuvotonClock.h"
extern Clock clock;

#if defined(CRC)
#include "NuvotonCrc.h"
extern NuvotonCrc crc;
#endif

#if defined(EADC)
#if defined(__M251_SUBFAMILY)
#define NUM_OF_MAX_ADC_CH		16
#endif 
#include "NuvotonEadc.h"
extern NuvotonEadc eadc;
#endif

#if defined(EMAC0)
#include "NuvotonEmac.h"
extern NuvotonEmac emac0;
#endif

#if defined(EMAC1)
#include "NuvotonEmac.h"
extern NuvotonEmac emac1;
#endif

#if defined(PDMA) || defined(PDMA1)
#include "NuvotonDma.h"

#if YSS__NUM_OF_DMA_CH >= 1
extern DmaChannel1 dmaChannel1;
#endif
#if YSS__NUM_OF_DMA_CH >= 2
extern DmaChannel2 dmaChannel2;
#endif
#if YSS__NUM_OF_DMA_CH >= 3
extern DmaChannel3 dmaChannel3;
#endif
#if YSS__NUM_OF_DMA_CH >= 4
extern DmaChannel4 dmaChannel4;
#endif
#if YSS__NUM_OF_DMA_CH >= 5
extern DmaChannel5 dmaChannel5;
#endif
#if YSS__NUM_OF_DMA_CH >= 6
extern DmaChannel6 dmaChannel6;
#endif
#if YSS__NUM_OF_DMA_CH >= 7
extern DmaChannel7 dmaChannel7;
#endif
#if YSS__NUM_OF_DMA_CH >= 8
extern DmaChannel8 dmaChannel8;
#endif
#if YSS__NUM_OF_DMA_CH >= 9
extern DmaChannel9 dmaChannel9;
#endif
#if YSS__NUM_OF_DMA_CH >= 10
extern DmaChannel10 dmaChannel10;
#endif
#if YSS__NUM_OF_DMA_CH >= 11
extern DmaChannel11 dmaChannel11;
#endif
#if YSS__NUM_OF_DMA_CH >= 12
extern DmaChannel12 dmaChannel12;
#endif
#if YSS__NUM_OF_DMA_CH >= 13
extern DmaChannel13 dmaChannel13;
#endif
#if YSS__NUM_OF_DMA_CH >= 14
extern DmaChannel14 dmaChannel14;
#endif
#if YSS__NUM_OF_DMA_CH >= 15
extern DmaChannel15 dmaChannel15;
#endif
#if YSS__NUM_OF_DMA_CH >= 16
extern DmaChannel16 dmaChannel16;
#endif
#if YSS__NUM_OF_DMA_CH >= 17
extern DmaChannel17 dmaChannel17;
#endif
#if YSS__NUM_OF_DMA_CH >= 18
extern DmaChannel18 dmaChannel18;
#endif
#if YSS__NUM_OF_DMA_CH >= 19
extern DmaChannel19 dmaChannel19;
#endif
#if YSS__NUM_OF_DMA_CH >= 20
extern DmaChannel20 dmaChannel20;
#endif
#if YSS__NUM_OF_DMA_CH >= 21
extern DmaChannel21 dmaChannel21;
#endif
#if YSS__NUM_OF_DMA_CH >= 22
extern DmaChannel22 dmaChannel22;
#endif
#if YSS__NUM_OF_DMA_CH >= 23
extern DmaChannel23 dmaChannel23;
#endif
#if YSS__NUM_OF_DMA_CH >= 24
extern DmaChannel24 dmaChannel24;
#endif
#if YSS__NUM_OF_DMA_CH >= 25
extern DmaChannel25 dmaChannel25;
#endif
#if YSS__NUM_OF_DMA_CH >= 26
extern DmaChannel26 dmaChannel26;
#endif
#if YSS__NUM_OF_DMA_CH >= 27
extern DmaChannel27 dmaChannel27;
#endif
#if YSS__NUM_OF_DMA_CH >= 28
extern DmaChannel28 dmaChannel28;
#endif
#if YSS__NUM_OF_DMA_CH >= 29
extern DmaChannel29 dmaChannel29;
#endif
#if YSS__NUM_OF_DMA_CH >= 30
extern DmaChannel30 dmaChannel30;
#endif
#if YSS__NUM_OF_DMA_CH >= 31
extern DmaChannel31 dmaChannel31;
#endif
#if YSS__NUM_OF_DMA_CH >= 32
extern DmaChannel32 dmaChannel32;
#endif
#if YSS__NUM_OF_DMA_CH >= 33
extern DmaChannel33 dmaChannel33;
#endif
#if YSS__NUM_OF_DMA_CH >= 34
extern DmaChannel34 dmaChannel34;
#endif
#if YSS__NUM_OF_DMA_CH >= 35
extern DmaChannel35 dmaChannel35;
#endif
#if YSS__NUM_OF_DMA_CH >= 36
extern DmaChannel36 dmaChannel36;
#endif
#if YSS__NUM_OF_DMA_CH >= 37
extern DmaChannel37 dmaChannel37;
#endif
#if YSS__NUM_OF_DMA_CH >= 38
extern DmaChannel38 dmaChannel38;
#endif
#if YSS__NUM_OF_DMA_CH >= 39
extern DmaChannel39 dmaChannel39;
#endif
#if YSS__NUM_OF_DMA_CH >= 40
extern DmaChannel40 dmaChannel40;
#endif
#endif

#include "NuvotonFlash.h"
extern Flash flash;

#include "NuvotonGpio.h"
#if defined(PA) && defined(PA_EXIST)
extern Gpio gpioA;
#endif
#if defined(PB) && defined(PB_EXIST)
extern Gpio gpioB;
#endif
#if defined(PC) && defined(PC_EXIST)
extern Gpio gpioC;
#endif
#if defined(PD) && defined(PD_EXIST)
extern Gpio gpioD;
#endif
#if defined(PE) && defined(PE_EXIST)
extern Gpio gpioE;
#endif
#if defined(PF) && defined(PF_EXIST)
extern Gpio gpioF;
#endif
#if defined(PG) && defined(PG_EXIST)
extern Gpio gpioG;
#endif
#if defined(PH) && defined(PH_EXIST)
extern Gpio gpioH;
#endif
#if defined(PI) && defined(PI_EXIST)
extern Gpio gpioI;
#endif
#if defined(PJ) && defined(PJ_EXIST)
extern Gpio gpioJ;
#endif
#if defined(PK) && defined(PK_EXIST)
extern Gpio gpioK;
#endif
#if defined(PL) && defined(PL_EXIST)
extern Gpio gpioL;
#endif
#if defined(PM) && defined(PM_EXIST)
extern Gpio gpioM;
#endif
#if defined(PN) && defined(PN_EXIST)
extern Gpio gpioN;
#endif

#if defined(HBI)
#include "NuvotonHbi.h"
extern NuvotonHbi hbi;
#endif

#if defined(I2C0)
#include "NuvotonI2c.h"
extern NuvotonI2c i2c0;
#endif
#if defined(I2C1)
extern NuvotonI2c i2c1;
#endif

#include "NuvotonQuadspi.h"
#if defined(QSPI0)
extern NuvotonQuadspi qspi0;
#endif

#if defined(SDH0)
#include "NuvotonSdh.h"
extern NuvotonSdh sdh0;
#endif

#if defined(SPI0)
#include "NuvotonSpi.h"

extern NuvotonSpi spi0;
#endif

#if defined(SPI1)
extern NuvotonSpi spi1;
#endif

#if defined(TIMER0)
#include "NuvotonTmr.h"
extern NuvotonTmr timer0;
#endif

#if defined(TIMER1)
extern NuvotonTmr timer1;
#endif

#if defined(TIMER2)
extern NuvotonTmr timer2;
#endif

#if defined(TIMER3)
extern NuvotonTmr timer3;
#endif

#if defined(UART0)
#include "NuvotonUart.h"
extern NuvotonUart uart0;
#endif

#if defined(UART1)
extern NuvotonUart uart1;
#endif

#if defined(UART2)
extern NuvotonUart uart2;
#endif

#if defined(UART3)
extern NuvotonUart uart3;
#endif

#if defined(USBD)
#include <drv/Usbd.h>
extern Usbd usbd;
#endif

#if defined(USPI0)
#include "NuvotonUspi.h"
extern NuvotonUspi uspi0;
#endif

#if defined(UUART0)
#include "NuvotonUuart.h"
extern NuvotonUuart uuart0;
#endif

#if defined(WDT)
#include "NuvotonWdt.h"
extern NuvotonWdt wdt;
#endif

#endif

