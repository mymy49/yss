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

#if defined(GD32F4)

#include <drv/Gpio.h>
#include <yss/reg.h>

enum
{
	CTL = 0, OMODE, OSPD, PUD, ISTAT, OCTL, BOP, LOCK, AFSEL0, AFSEL1, BC, TG
};

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

void Gpio::setAsAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, unsigned char otype)
{
	unsigned char pinOffset = pin * 2;

	setFieldData(mPeri[CTL], GPIO_MODE_MASK(pin), define::gpio::mode::ALT_FUNC, pinOffset);
	setBitData(mPeri[OMODE], otype, pin);
	setFieldData(mPeri[OSPD], 0x3 << pinOffset, ospeed, pinOffset);
	pinOffset = (pin % 0x8) * 4;
	setFieldData(mPeri[AFSEL0 + pin / 8], 0xF << pinOffset, altFunc, pinOffset);
}

void Gpio::setAsInput(unsigned char pin, unsigned char pullUpDown)
{
	//setGpioMode(mPeri, pin, define::gpio::mode::INPUT);
	//setGpioPullUpDown(mPeri, pin, pullUpDown);
}

void Gpio::setPackageAsAltFunc(AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, unsigned char otype)
{
	YSS_GPIO_Peri *port;
	unsigned char pin, pinOffset;
	unsigned char func;

	for (unsigned char i = 0; i < numOfPort; i++)
	{
		port = altport[i].port;
		pin = altport[i].pin;
		pinOffset = pin * 2;
		func = altport[i].func;

		setFieldData(port[CTL], GPIO_MODE_MASK(pin), define::gpio::mode::ALT_FUNC, pinOffset);
		setBitData(port[OMODE], otype, pin);
		setFieldData(port[OSPD], 0x3 << pinOffset, ospeed, pinOffset);
		pinOffset = (pin % 0x8) * 4;
		setFieldData(port[AFSEL0 + pin / 8], 0xF << pinOffset, func, pinOffset);
	}
}

void Gpio::setAsOutput(unsigned char pin, unsigned char ospeed, unsigned char otype)
{
	unsigned char pinOffset = pin * 2;

	setFieldData(mPeri[CTL], GPIO_MODE_MASK(pin), define::gpio::mode::OUTPUT, pinOffset);
	setBitData(mPeri[OMODE], otype, pin);
	setFieldData(mPeri[OSPD], 0x3 << pinOffset, ospeed, pinOffset);
}

void Gpio::setOutput(unsigned char pin, bool data)
{
	if(data)
		mPeri[BOP] = 1 << pin;
	else
		mPeri[BOP] = 1 << pin + 16;
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

#endif
