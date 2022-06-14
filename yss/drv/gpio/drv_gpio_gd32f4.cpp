////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(GD32F450)

#include <drv/Gpio.h>
#include <yss/reg.h>

enum
{
	CTL = 0, OMODE, OSPD, PUD, ISTAT, OCTL, BOP, LOCK, AFSEL0, AFSEL1, BC, TG
};

namespace drv
{
Gpio::Gpio(YSS_GPIO_Peri *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), unsigned char exti) : Drv(clockFunc, 0, resetFunc)
{
	mPeri = peri;
	mExti = exti;
}

void Gpio::setExti(unsigned char pin)
{
	//unsigned char field = pin % 4 * 4;
	//unsigned int reg = SYSCFG->EXTICR[pin / 4];
	//reg &= 0xF << field;
	//reg |= mExti << field;
	//SYSCFG->EXTICR[pin / 4] = reg;
}

void Gpio::setAsAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, bool otype)
{
	volatile unsigned int *reg = mPeri;
	unsigned char calculatedPin = pin * 2;

	setFieldData(*reg++, GPIO_MODE_MASK(pin), define::gpio::mode::ALT_FUNC, calculatedPin);
	setBitData(*reg++, otype, pin);
	setFieldData(*reg, 0x3 << calculatedPin, ospeed, calculatedPin);
	reg += 6 + pin / 8;
	calculatedPin = (pin % 0x7) * 4;
	setFieldData(*reg, 0xF << calculatedPin, altFunc, calculatedPin);
}

void Gpio::setAsInput(unsigned char pin, unsigned char pullUpDown)
{
	//setGpioMode(mPeri, pin, define::gpio::mode::INPUT);
	//setGpioPullUpDown(mPeri, pin, pullUpDown);
}

void Gpio::setPackageAsAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype)
{
	//GPIO_TypeDef *port;
	//unsigned char pin;
	//unsigned char func;

	//for (unsigned char i = 0; i < numOfPort; i++)
	//{
	//	port = altport[i].port;
	//	pin = altport[i].pin;
	//	func = altport[i].func;

	//	setGpioMode(port, pin, define::gpio::mode::ALT_FUNC);
	//	setGpioAltfunc(port, pin, func);
	//	setGpioOspeed(port, pin, ospeed);
	//	setGpioOtype(port, pin, otype);
	//}
}

void Gpio::setAsOutput(unsigned char pin, unsigned char ospeed, unsigned char otype)
{
	//setGpioMode(mPeri, pin, define::gpio::mode::OUTPUT);
	//setGpioOspeed(mPeri, pin, ospeed);
	//setGpioOtype(mPeri, pin, otype);
}

void Gpio::setOutput(unsigned char pin, bool data)
{
	//setRegBit(mPeri->ODR, data, pin);
}

void Gpio::setPullUpDown(unsigned char pin, unsigned char pupd)
{
	//setGpioPullUpDown(mPeri, pin, pupd);
}

void Gpio::setAsAnalog(unsigned char pin)
{
	//mPeri->MODER |= 0x03 << (pin * 2);
}

bool Gpio::getData(unsigned char pin)
{
	//return getGpioInputData(mPeri, pin);
}
}

#endif
