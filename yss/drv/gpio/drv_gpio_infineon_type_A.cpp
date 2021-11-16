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

#if defined (XMC4300_F100x256)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <yss/mcu.h>

#if defined(PORT0)
drv::Gpio gpioA((XMC_GPIO_PORT_t*)PORT0, 0, 0);
#endif

#if defined(PORT1)
drv::Gpio gpioB((XMC_GPIO_PORT_t*)PORT1, 0, 0);
#endif

#if defined(PORT2)
drv::Gpio gpioC((XMC_GPIO_PORT_t*)PORT2, 0, 0);
#endif

#if defined(PORT3)
drv::Gpio gpioD((XMC_GPIO_PORT_t*)PORT3, 0, 0);
#endif

#if defined(PORT4)
drv::Gpio gpioE((XMC_GPIO_PORT_t*)PORT4, 0, 0);
#endif

#if defined(PORT5)
drv::Gpio gpioF((XMC_GPIO_PORT_t*)PORT5, 0, 0);
#endif

namespace drv
{
	void Gpio::setToOutput(unsigned char pin, unsigned char ospeed, bool otype)
	{
		unsigned char index = pin / 4;
		unsigned char num = pin % 4;
		num = num * 8 + 3;
		mPeri->IOCR[index] &= ~(0x1f << num);
		mPeri->IOCR[index] |= 0x10 << num;
	}

	Gpio::Gpio(XMC_GPIO_PORT_t *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) :  Drv(clockFunc, nvicFunc)
	{
		mPeri = peri;
	}

	void Gpio::setOutput(unsigned char pin, bool data)
	{
		if(data)
			mPeri->OUT |= 1 << pin;
		else
			mPeri->OUT &= ~(1 << pin);
	}


/*

	void Gpio::setExti(unsigned char pin)
	{
		syscfg.setExtiPort(pin, mExti);
	}

	void Gpio::setToAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, bool otype)
	{
		setGpioMode(mPeri, pin,	define::gpio::mode::ALT_FUNC);
		setGpioAltfunc(mPeri, pin, altFunc);
		setGpioOspeed(mPeri, pin, ospeed);
		setGpioOtype(mPeri,	pin, otype);
	}

	void Gpio::setToInput(unsigned char pin, unsigned char pullUpDown)
	{
		setGpioMode(mPeri, pin,	define::gpio::mode::ALT_FUNC);	
		setGpioPullUpDown(mPeri, pin, pullUpDown);
	}

	void Gpio::setToAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype)
	{
		GPIO_TypeDef *port;
		unsigned char pin;
		unsigned char func;

		for(unsigned char i=0;i<numOfPort;i++)
		{
			port = altport[i].port;
			pin = altport[i].pin;
			func = altport[i].func;

			setGpioMode(port, pin,	define::gpio::mode::ALT_FUNC);
			setGpioAltfunc(port, pin, func);
			setGpioOspeed(port,	pin, ospeed);
			setGpioOtype(port, pin,	otype);
		}
	}


	void Gpio::setPullUpDown(unsigned char pin, unsigned char pupd)
	{
		setGpioPullUpDown(mPeri, pin, pupd);
	}

	bool Gpio::getData(unsigned char pin)
	{
		return getGpioInputData(mPeri, pin);
	}
*/
}
#endif

