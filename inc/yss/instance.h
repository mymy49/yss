/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE__H_
#define YSS_INSTANCE__H_

#include <drv/peripheral.h>

#include <drv/Adc.h>
#include <drv/Bpwm.h>
#include <drv/Can.h>
#include <drv/Capture.h>
#include <drv/Clock.h>
#include <drv/Crc32.h>
#include <drv/Dac.h>
#include <drv/Dma.h>
#include <drv/Dma2d.h>
#include <drv/Epwm.h>
#include <drv/Exti.h>
#include <drv/Flash.h>
#include <drv/Gpio.h>
#include <drv/I2c.h>
#include <drv/I2s.h>
#include <drv/Ltdc.h>
#include <drv/Nvic.h>
#include <drv/Pbus.h>
#include <drv/Pwm.h>
#include <drv/Qencoder.h>
#include <drv/Quadspi.h>
#include <drv/Rtc.h>
#include <drv/Sai.h>
#include <drv/Sdmmc.h>
#include <drv/Sdram.h>
#include <drv/Spi.h>
#include <drv/Timer.h>
#include <drv/Uart.h>
#include <drv/Usart.h>
#include <drv/Usbd.h>
#include <drv/Wdog.h>

// NVIC
#if defined(NVIC)
extern Nvic nvic;
#endif

#if defined(STM32F4)

#include <targets/st/instance_stm32f4.h>

#elif defined(STM32G4)

#include <targets/st/instance_stm32g4.h>

#elif defined(STM32F0)

#include <targets/st/instance_stm32f0.h>

#elif defined(STM32F1) || defined(GD32F1)

#include <targets/st/instance_stm32f1.h>

#elif defined(STM32F7)

#include <targets/st/instance_stm32f7.h>

#elif defined(EFM32PG22)

#include <targets/siliconlabs/instance_efm32pg22.h>

#elif defined(EFR32BG22)

#include <targets/siliconlabs/instance_efr32bg22.h>

#elif defined(W7500)

#include <targets/wiznet/instance_w7500x.h>

#elif defined(CPU_MIMXRT1011DAE5A)

#include <targets/nxp/instance_mimxrt1011.h>

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <targets/nuvoton/instance_m4xx.h>

#elif defined(__M2xx_FAMILY)

#include <targets/nuvoton/instance_m2xx.h>

#endif

#endif

