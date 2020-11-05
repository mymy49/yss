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

#include <drv/peripherals.h>

#if defined(YSS_DRV_GPIO_NOT_SUPPORT)

#include <__cross_studio_io.h>

#if defined(GPIOA)
drv::Gpio gpioA;
#endif

#if defined(GPIOB)
drv::Gpio gpioB;
#endif

#if defined(GPIOC)
drv::Gpio gpioC;
#endif

#if defined(GPIOD)
drv::Gpio gpioD;
#endif

#if defined(GPIOE)
drv::Gpio gpioE;
#endif

#if defined(GPIOF)
drv::Gpio gpioF;
#endif

#if defined(GPIOG)
drv::Gpio gpioG;
#endif

#if defined(GPIOH)
drv::Gpio gpioH(GPIOH, 0, 0, 0);
#endif

#if defined(GPIOI)
drv::Gpio gpioI(GPIOI, 0, 0, 0);
#endif

#if defined(GPIOJ)
drv::Gpio gpioJ(GPIOJ, 0, 0, 0);
#endif

#if defined(GPIOK)
drv::Gpio gpioH(GPIOK, 0, 0, 0);
#endif

namespace drv
{
	Gpio::Gpio(void) : Drv(0, 0){}
	void Gpio::setExti(unsigned char pin){}
	void Gpio::setToAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, bool otype){}
	void Gpio::setToAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype){}
	void Gpio::setToOutput(unsigned char pin, unsigned char ospeed, bool otype){}
	void Gpio::setOutput(unsigned char pin, bool data){}
	void Gpio::setPullUpDown(unsigned char pin, unsigned char pupd){}
	bool Gpio::getData(unsigned char pin){return false;}
}
#endif

