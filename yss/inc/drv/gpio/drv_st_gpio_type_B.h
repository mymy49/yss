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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_GPIO_ST_TYPE_B__H_
#define YSS_DRV_GPIO_ST_TYPE_B__H_

#include <yss/mcu.h>

#if defined(STM32F1)

#include "drv_st_gpio_type_B_config.h"
#include "drv_st_gpio_type_B_define.h"
#include <config.h>
#include <drv/Drv.h>

namespace drv
{
class Gpio : public Drv
{
    GPIO_TypeDef *mPeri;
    unsigned char mExti;

  public:
    Gpio(GPIO_TypeDef *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), unsigned char exti);
    void setExti(unsigned char pin);
    void setAllClock(bool en);
    void setAsAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed = define::gpio::ospeed::MID, bool otype = define::gpio::otype::PUSH_PULL);
    void setAsAltFunc(unsigned char pin, unsigned char ospeed, bool otype);
    void setAsAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype);
    void setAsOutput(unsigned char pin, unsigned char ospeed = define::gpio::ospeed::MID, unsigned char otype = define::gpio::otype::PUSH_PULL);
    void setAsInput(unsigned char pin);
    void setOutput(unsigned char pin, bool data);
    void setPullUpDown(unsigned char pin, unsigned char pupd);
    bool getData(unsigned char pin);
    void setAsAnalog(unsigned char pin);
};
}

#define setToAltFunc setAsAltFunc
#define setToInput setAsInput
#define setToOutput setAsOutput
#define setToAnalog setAsAnalog

#define setGpioA(x)		GPIOA-ODR = x
#define setGpioA0()		GPIOA->BSRR = (1 << 0)
#define setGpioA1()		GPIOA->BSRR = (1 << 1)
#define setGpioA2()		GPIOA->BSRR = (1 << 2)
#define setGpioA3()		GPIOA->BSRR = (1 << 3)
#define setGpioA4()		GPIOA->BSRR = (1 << 4)
#define setGpioA5()		GPIOA->BSRR = (1 << 5)
#define setGpioA6()		GPIOA->BSRR = (1 << 6)
#define setGpioA7()		GPIOA->BSRR = (1 << 7)
#define setGpioA8()		GPIOA->BSRR = (1 << 8)
#define setGpioA9()		GPIOA->BSRR = (1 << 9)
#define setGpioA10()	GPIOA->BSRR = (1 << 10)
#define setGpioA11()	GPIOA->BSRR = (1 << 11)
#define setGpioA12()	GPIOA->BSRR = (1 << 12)
#define setGpioA13()	GPIOA->BSRR = (1 << 13)
#define setGpioA14()	GPIOA->BSRR = (1 << 14)
#define setGpioA15()	GPIOA->BSRR = (1 << 15)

#define resetGpioA0()	GPIOA->BRR = (1 << 0)
#define resetGpioA1()	GPIOA->BRR = (1 << 1)
#define resetGpioA2()	GPIOA->BRR = (1 << 2)
#define resetGpioA3()	GPIOA->BRR = (1 << 3)
#define resetGpioA4()	GPIOA->BRR = (1 << 4)
#define resetGpioA5()	GPIOA->BRR = (1 << 5)
#define resetGpioA6()	GPIOA->BRR = (1 << 6)
#define resetGpioA7()	GPIOA->BRR = (1 << 7)
#define resetGpioA8()	GPIOA->BRR = (1 << 8)
#define resetGpioA9()	GPIOA->BRR = (1 << 9)
#define resetGpioA10()	GPIOA->BRR = (1 << 10)
#define resetGpioA11()	GPIOA->BRR = (1 << 11)
#define resetGpioA12()	GPIOA->BRR = (1 << 12)
#define resetGpioA13()	GPIOA->BRR = (1 << 13)
#define resetGpioA14()	GPIOA->BRR = (1 << 14)
#define resetGpioA15()	GPIOA->BRR = (1 << 15)

#define setGpioB(x)		GPIOB-ODR = x
#define setGpioB0()		GPIOB->BSRR = (1 << 0)
#define setGpioB1()		GPIOB->BSRR = (1 << 1)
#define setGpioB2()		GPIOB->BSRR = (1 << 2)
#define setGpioB3()		GPIOB->BSRR = (1 << 3)
#define setGpioB4()		GPIOB->BSRR = (1 << 4)
#define setGpioB5()		GPIOB->BSRR = (1 << 5)
#define setGpioB6()		GPIOB->BSRR = (1 << 6)
#define setGpioB7()		GPIOB->BSRR = (1 << 7)
#define setGpioB8()		GPIOB->BSRR = (1 << 8)
#define setGpioB9()		GPIOB->BSRR = (1 << 9)
#define setGpioB10()	GPIOB->BSRR = (1 << 10)
#define setGpioB11()	GPIOB->BSRR = (1 << 11)
#define setGpioB12()	GPIOB->BSRR = (1 << 12)
#define setGpioB13()	GPIOB->BSRR = (1 << 13)
#define setGpioB14()	GPIOB->BSRR = (1 << 14)
#define setGpioB15()	GPIOB->BSRR = (1 << 15)

#define resetGpioB0()	GPIOB->BRR = (1 << 0)
#define resetGpioB1()	GPIOB->BRR = (1 << 1)
#define resetGpioB2()	GPIOB->BRR = (1 << 2)
#define resetGpioB3()	GPIOB->BRR = (1 << 3)
#define resetGpioB4()	GPIOB->BRR = (1 << 4)
#define resetGpioB5()	GPIOB->BRR = (1 << 5)
#define resetGpioB6()	GPIOB->BRR = (1 << 6)
#define resetGpioB7()	GPIOB->BRR = (1 << 7)
#define resetGpioB8()	GPIOB->BRR = (1 << 8)
#define resetGpioB9()	GPIOB->BRR = (1 << 9)
#define resetGpioB10()	GPIOB->BRR = (1 << 10)
#define resetGpioB11()	GPIOB->BRR = (1 << 11)
#define resetGpioB12()	GPIOB->BRR = (1 << 12)
#define resetGpioB13()	GPIOB->BRR = (1 << 13)
#define resetGpioB14()	GPIOB->BRR = (1 << 14)
#define resetGpioB15()	GPIOB->BRR = (1 << 15)

#define setGpioC(x)		GPIOC->ODR = x
#define setGpioC0()		GPIOC->BSRR = (1 << 0)
#define setGpioC1()		GPIOC->BSRR = (1 << 1)
#define setGpioC2()		GPIOC->BSRR = (1 << 2)
#define setGpioC3()		GPIOC->BSRR = (1 << 3)
#define setGpioC4()		GPIOC->BSRR = (1 << 4)
#define setGpioC5()		GPIOC->BSRR = (1 << 5)
#define setGpioC6()		GPIOC->BSRR = (1 << 6)
#define setGpioC7()		GPIOC->BSRR = (1 << 7)
#define setGpioC8()		GPIOC->BSRR = (1 << 8)
#define setGpioC9()		GPIOC->BSRR = (1 << 9)
#define setGpioC10()	GPIOC->BSRR = (1 << 10)
#define setGpioC11()	GPIOC->BSRR = (1 << 11)
#define setGpioC12()	GPIOC->BSRR = (1 << 12)
#define setGpioC13()	GPIOC->BSRR = (1 << 13)
#define setGpioC14()	GPIOC->BSRR = (1 << 14)
#define setGpioC15()	GPIOC->BSRR = (1 << 15)

#define resetGpioC0()	GPIOC->BRR = (1 << 0)
#define resetGpioC1()	GPIOC->BRR = (1 << 1)
#define resetGpioC2()	GPIOC->BRR = (1 << 2)
#define resetGpioC3()	GPIOC->BRR = (1 << 3)
#define resetGpioC4()	GPIOC->BRR = (1 << 4)
#define resetGpioC5()	GPIOC->BRR = (1 << 5)
#define resetGpioC6()	GPIOC->BRR = (1 << 6)
#define resetGpioC7()	GPIOC->BRR = (1 << 7)
#define resetGpioC8()	GPIOC->BRR = (1 << 8)
#define resetGpioC9()	GPIOC->BRR = (1 << 9)
#define resetGpioC10()	GPIOC->BRR = (1 << 10)
#define resetGpioC11()	GPIOC->BRR = (1 << 11)
#define resetGpioC12()	GPIOC->BRR = (1 << 12)
#define resetGpioC13()	GPIOC->BRR = (1 << 13)
#define resetGpioC14()	GPIOC->BRR = (1 << 14)
#define resetGpioC15()	GPIOC->BRR = (1 << 15)

#define setGpioD(x)		GPIOD-ODR = x
#define setGpioD0()		GPIOD->BSRR = (1 << 0)
#define setGpioD1()		GPIOD->BSRR = (1 << 1)
#define setGpioD2()		GPIOD->BSRR = (1 << 2)
#define setGpioD3()		GPIOD->BSRR = (1 << 3)
#define setGpioD4()		GPIOD->BSRR = (1 << 4)
#define setGpioD5()		GPIOD->BSRR = (1 << 5)
#define setGpioD6()		GPIOD->BSRR = (1 << 6)
#define setGpioD7()		GPIOD->BSRR = (1 << 7)
#define setGpioD8()		GPIOD->BSRR = (1 << 8)
#define setGpioD9()		GPIOD->BSRR = (1 << 9)
#define setGpioD10()	GPIOD->BSRR = (1 << 10)
#define setGpioD11()	GPIOD->BSRR = (1 << 11)
#define setGpioD12()	GPIOD->BSRR = (1 << 12)
#define setGpioD13()	GPIOD->BSRR = (1 << 13)
#define setGpioD14()	GPIOD->BSRR = (1 << 14)
#define setGpioD15()	GPIOD->BSRR = (1 << 15)

#define resetGpioD0()	GPIOD->BRR = (1 << 0)
#define resetGpioD1()	GPIOD->BRR = (1 << 1)
#define resetGpioD2()	GPIOD->BRR = (1 << 2)
#define resetGpioD3()	GPIOD->BRR = (1 << 3)
#define resetGpioD4()	GPIOD->BRR = (1 << 4)
#define resetGpioD5()	GPIOD->BRR = (1 << 5)
#define resetGpioD6()	GPIOD->BRR = (1 << 6)
#define resetGpioD7()	GPIOD->BRR = (1 << 7)
#define resetGpioD8()	GPIOD->BRR = (1 << 8)
#define resetGpioD9()	GPIOD->BRR = (1 << 9)
#define resetGpioD10()	GPIOD->BRR = (1 << 10)
#define resetGpioD11()	GPIOD->BRR = (1 << 11)
#define resetGpioD12()	GPIOD->BRR = (1 << 12)
#define resetGpioD13()	GPIOD->BRR = (1 << 13)
#define resetGpioD14()	GPIOD->BRR = (1 << 14)
#define resetGpioD15()	GPIOD->BRR = (1 << 15)

#define setGpioE(x)		GPIOE-ODR = x
#define setGpioE0()		GPIOE->BSRR = (1 << 0)
#define setGpioE1()		GPIOE->BSRR = (1 << 1)
#define setGpioE2()		GPIOE->BSRR = (1 << 2)
#define setGpioE3()		GPIOE->BSRR = (1 << 3)
#define setGpioE4()		GPIOE->BSRR = (1 << 4)
#define setGpioE5()		GPIOE->BSRR = (1 << 5)
#define setGpioE6()		GPIOE->BSRR = (1 << 6)
#define setGpioE7()		GPIOE->BSRR = (1 << 7)
#define setGpioE8()		GPIOE->BSRR = (1 << 8)
#define setGpioE9()		GPIOE->BSRR = (1 << 9)
#define setGpioE10()	GPIOE->BSRR = (1 << 10)
#define setGpioE11()	GPIOE->BSRR = (1 << 11)
#define setGpioE12()	GPIOE->BSRR = (1 << 12)
#define setGpioE13()	GPIOE->BSRR = (1 << 13)
#define setGpioE14()	GPIOE->BSRR = (1 << 14)
#define setGpioE15()	GPIOE->BSRR = (1 << 15)

#define resetGpioE0()	GPIOE->BRR = (1 << 0)
#define resetGpioE1()	GPIOE->BRR = (1 << 1)
#define resetGpioE2()	GPIOE->BRR = (1 << 2)
#define resetGpioE3()	GPIOE->BRR = (1 << 3)
#define resetGpioE4()	GPIOE->BRR = (1 << 4)
#define resetGpioE5()	GPIOE->BRR = (1 << 5)
#define resetGpioE6()	GPIOE->BRR = (1 << 6)
#define resetGpioE7()	GPIOE->BRR = (1 << 7)
#define resetGpioE8()	GPIOE->BRR = (1 << 8)
#define resetGpioE9()	GPIOE->BRR = (1 << 9)
#define resetGpioE10()	GPIOE->BRR = (1 << 10)
#define resetGpioE11()	GPIOE->BRR = (1 << 11)
#define resetGpioE12()	GPIOE->BRR = (1 << 12)
#define resetGpioE13()	GPIOE->BRR = (1 << 13)
#define resetGpioE14()	GPIOE->BRR = (1 << 14)
#define resetGpioE15()	GPIOE->BRR = (1 << 15)

#define setGpioF(x)		GPIOF-ODR = x
#define setGpioF0()		GPIOF->BSRR = (1 << 0)
#define setGpioF1()		GPIOF->BSRR = (1 << 1)
#define setGpioF2()		GPIOF->BSRR = (1 << 2)
#define setGpioF3()		GPIOF->BSRR = (1 << 3)
#define setGpioF4()		GPIOF->BSRR = (1 << 4)
#define setGpioF5()		GPIOF->BSRR = (1 << 5)
#define setGpioF6()		GPIOF->BSRR = (1 << 6)
#define setGpioF7()		GPIOF->BSRR = (1 << 7)
#define setGpioF8()		GPIOF->BSRR = (1 << 8)
#define setGpioF9()		GPIOF->BSRR = (1 << 9)
#define setGpioF10()	GPIOF->BSRR = (1 << 10)
#define setGpioF11()	GPIOF->BSRR = (1 << 11)
#define setGpioF12()	GPIOF->BSRR = (1 << 12)
#define setGpioF13()	GPIOF->BSRR = (1 << 13)
#define setGpioF14()	GPIOF->BSRR = (1 << 14)
#define setGpioF15()	GPIOF->BSRR = (1 << 15)

#define resetGpioF0()	GPIOF->BRR = (1 << 0)
#define resetGpioF1()	GPIOF->BRR = (1 << 1)
#define resetGpioF2()	GPIOF->BRR = (1 << 2)
#define resetGpioF3()	GPIOF->BRR = (1 << 3)
#define resetGpioF4()	GPIOF->BRR = (1 << 4)
#define resetGpioF5()	GPIOF->BRR = (1 << 5)
#define resetGpioF6()	GPIOF->BRR = (1 << 6)
#define resetGpioF7()	GPIOF->BRR = (1 << 7)
#define resetGpioF8()	GPIOF->BRR = (1 << 8)
#define resetGpioF9()	GPIOF->BRR = (1 << 9)
#define resetGpioF10()	GPIOF->BRR = (1 << 10)
#define resetGpioF11()	GPIOF->BRR = (1 << 11)
#define resetGpioF12()	GPIOF->BRR = (1 << 12)
#define resetGpioF13()	GPIOF->BRR = (1 << 13)
#define resetGpioF14()	GPIOF->BRR = (1 << 14)
#define resetGpioF15()	GPIOF->BRR = (1 << 15)

#define setGpioG(x)		GPIOG-ODR = x
#define setGpioG0()		GPIOG->BSRR = (1 << 0)
#define setGpioG1()		GPIOG->BSRR = (1 << 1)
#define setGpioG2()		GPIOG->BSRR = (1 << 2)
#define setGpioG3()		GPIOG->BSRR = (1 << 3)
#define setGpioG4()		GPIOG->BSRR = (1 << 4)
#define setGpioG5()		GPIOG->BSRR = (1 << 5)
#define setGpioG6()		GPIOG->BSRR = (1 << 6)
#define setGpioG7()		GPIOG->BSRR = (1 << 7)
#define setGpioG8()		GPIOG->BSRR = (1 << 8)
#define setGpioG9()		GPIOG->BSRR = (1 << 9)
#define setGpioG10()	GPIOG->BSRR = (1 << 10)
#define setGpioG11()	GPIOG->BSRR = (1 << 11)
#define setGpioG12()	GPIOG->BSRR = (1 << 12)
#define setGpioG13()	GPIOG->BSRR = (1 << 13)
#define setGpioG14()	GPIOG->BSRR = (1 << 14)
#define setGpioG15()	GPIOG->BSRR = (1 << 15)

#define resetGpioG0()	GPIOG->BRR = (1 << 0)
#define resetGpioG1()	GPIOG->BRR = (1 << 1)
#define resetGpioG2()	GPIOG->BRR = (1 << 2)
#define resetGpioG3()	GPIOG->BRR = (1 << 3)
#define resetGpioG4()	GPIOG->BRR = (1 << 4)
#define resetGpioG5()	GPIOG->BRR = (1 << 5)
#define resetGpioG6()	GPIOG->BRR = (1 << 6)
#define resetGpioG7()	GPIOG->BRR = (1 << 7)
#define resetGpioG8()	GPIOG->BRR = (1 << 8)
#define resetGpioG9()	GPIOG->BRR = (1 << 9)
#define resetGpioG10()	GPIOG->BRR = (1 << 10)
#define resetGpioG11()	GPIOG->BRR = (1 << 11)
#define resetGpioG12()	GPIOG->BRR = (1 << 12)
#define resetGpioG13()	GPIOG->BRR = (1 << 13)
#define resetGpioG14()	GPIOG->BRR = (1 << 14)
#define resetGpioG15()	GPIOG->BRR = (1 << 15)

#endif

#endif