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

#ifndef	YSS_DRV_GPIO_ST_TYPE_A__H_
#define	YSS_DRV_GPIO_ST_TYPE_A__H_

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx) || \
	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)

#include <yss/mcu.h>
#include "drv_st_gpio_type_A_define.h"
#include "drv_st_gpio_type_A_config.h"
#include <drv/Drv.h>

namespace drv
{
	class Gpio : public Drv
	{
		GPIO_TypeDef *mPeri;
		unsigned char mExti;

	public :
		Gpio(GPIO_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned char exti);
		void setExti(unsigned char pin);
		void setToAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed = define::gpio::ospeed::MID, bool otype = define::gpio::otype::PUSH_PULL);
		void setToAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype);
		void setToOutput(unsigned char pin, unsigned char ospeed = define::gpio::ospeed::MID, bool otype = define::gpio::otype::PUSH_PULL);
		void setOutput(unsigned char pin, bool data);
		void setToInput(unsigned char pin, unsigned char pullUpDown = define::gpio::pupd::NONE);
		void setToAnalog(unsigned char pin);

		void setPullUpDown(unsigned char pin, unsigned char pupd);
		bool getData(unsigned char pin);
	};
}

#if defined(GPIOA)
extern drv::Gpio gpioA;
#endif

#if defined(GPIOB)
extern drv::Gpio gpioB;
#endif

#if defined(GPIOC)
extern drv::Gpio gpioC;
#endif

#if defined(GPIOD)
extern drv::Gpio gpioD;
#endif

#if defined(GPIOE)
extern drv::Gpio gpioE;
#endif

#if defined(GPIOF)
extern drv::Gpio gpioF;
#endif

#if defined(GPIOG)
extern drv::Gpio gpioG;
#endif

#if defined(GPIOH)
extern drv::Gpio gpioH;
#endif

#if defined(GPIOI)
extern drv::Gpio gpioI;
#endif

#if defined(GPIOJ)
extern drv::Gpio gpioJ;
#endif

#if defined(GPIOK)
extern drv::Gpio gpioK;
#endif

#endif

#endif
