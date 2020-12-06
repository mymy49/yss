////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CLOCK_ST_TYPE_B__H_
#define YSS_DRV_CLOCK_ST_TYPE_B__H_

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

#include "drv_st_clock_type_B_config.h"
#include "drv_st_clock_type_B_define.h"
#include "drv_st_clock_type_B_ec.h"
#include <config.h>
#include <yss/mcu.h>

namespace drv
{
class Mainpll
{
  public:
    bool enable(unsigned char src, unsigned char xtpre, unsigned char mul);
    unsigned long getFreq(void);
};

class Peripheral
{
  public:
#if defined(DMA1)
    void setDmaEn(bool en);
#endif

#if defined(AFIO)
    void setAfioEn(bool en);
#endif
#if defined(GPIOA)
    void setGpioAEn(bool en);
#endif
#if defined(GPIOB)
    void setGpioBEn(bool en);
#endif
#if defined(GPIOC)
    void setGpioCEn(bool en);
#endif
#if defined(GPIOD)
    void setGpioDEn(bool en);
#endif
#if defined(GPIOE)
    void setGpioEEn(bool en);
#endif
#if defined(GPIOF)
    void setGpioFEn(bool en);
#endif
#if defined(GPIOG)
    void setGpioGEn(bool en);
#endif

#if defined(TIM1)
    void setTimer1En(bool en);
#endif
#if defined(TIM2)
    void setTimer2En(bool en);
#endif
#if defined(TIM3)
    void setTimer3En(bool en);
#endif
#if defined(TIM4)
    void setTimer4En(bool en);
#endif
#if defined(TIM5)
    void setTimer5En(bool en);
#endif
#if defined(TIM6)
    void setTimer6En(bool en);
#endif
#if defined(TIM7)
    void setTimer7En(bool en);
#endif
#if defined(TIM8)
    void setTimer8En(bool en);
#endif
#if defined(TIM9)
    void setTimer9En(bool en);
#endif
#if defined(TIM10)
    void setTimer10En(bool en);
#endif
#if defined(TIM11)
    void setTimer11En(bool en);
#endif
#if defined(TIM12)
    void setTimer12En(bool en);
#endif
#if defined(TIM13)
    void setTimer13En(bool en);
#endif
#if defined(TIM14)
    void setTimer14En(bool en);
#endif

#if defined(I2C1)
    void setI2c1En(bool en);
    void resetI2c1(void);
#endif
#if defined(I2C2)
    void setI2c2En(bool en);
    void resetI2c2(void);
#endif

#if defined(USART1)
    void setUart1En(bool en);
#endif
#if defined(USART2)
    void setUart2En(bool en);
#endif
#if defined(USART3)
    void setUart3En(bool en);
#endif
#if defined(UART4)
    void setUart4En(bool en);
#endif
#if defined(UART5)
    void setUart5En(bool en);
#endif

#if defined(ADC1)
    void setAdc1En(bool en);
#endif

#if defined(ADC2)
    void setAdc2En(bool en);
#endif

#if defined(CAN1)
    void setCan1En(bool en);
    void resetCan1(void);
#endif

#if defined(CAN2)
    void setCan2En(bool en);
    void resetCan2(void);
#endif

#if defined(SPI1)
    void setSpi1En(bool en);
#endif

#if defined(SPI2)
    void setSpi2En(bool en);
#endif

#if defined(SPI3)
    void setSpi3En(bool en);
#endif

#if defined(DAC)
    void setDacEn(bool en);
#endif
};

class Clock
{
    //		bool setLsiEn(bool en);
    //		bool setPllEn(bool en);
    //		bool setSaiPllEn(bool en);
    //		bool setSysclkSrc(unsigned char	src);
    //		void calculatePllClockFreq(void);
  public:
    Mainpll pll;
    Peripheral peripheral;

    bool enableHse(unsigned char hseMhz);
    bool enableLsi(bool en = true);
    bool enableLse(bool en = true);
    bool setUsbClkSrc(unsigned char src);
    bool setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2);

    unsigned long getSysClkFreq(void);
    unsigned long getApb1ClkFreq(void);
    unsigned long getApb2ClkFreq(void);
    unsigned long getTimerApb1ClkFreq(void);
    unsigned long getTimerApb2ClkFreq(void);
};
}

#if defined(RCC)
extern drv::Clock clock;
#endif

#endif

#endif