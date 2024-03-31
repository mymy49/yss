////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(W7500)

#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/wiznet/bitfield_w7500x.h>

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : GpioBase(drvSetup)
{
	mDev = setup.dev;
	mAfc = setup.afc;
	mPadcon = setup.padcon;
	mOutputAf = setup.outputAf;
}

error_t Gpio::setAsOutput(uint8_t pin, strength_t strength, otype_t otype)
{
	if(pin > 15)
		return error_t::PIN_INDEX_OVER;
	
	if(strength > 1)
		return error_t::WRONG_CONFIG;

	if(otype > 1)
		return error_t::WRONG_CONFIG;
	
	if(mOutputAf[pin] < 0)
		return error_t::THIS_PIN_DO_NOT_HAVE_GPIO_OUTPUT;

	__disable_irq();
	mAfc->REGISTER[pin] = mOutputAf[pin];
	mPadcon->REGISTER[pin] = (strength & 0x01) << 2 | (otype & 0x01) << 3 | 0x03 << 5;
	mDev->OUTENSET = 1 << pin;
	__enable_irq();

	return error_t::ERROR_NONE;
}

error_t Gpio::setAsAltFunc(uint8_t pin, altfunc_t altfunc, strength_t strength, otype_t otype)
{
	if(pin > 15)
		return error_t::PIN_INDEX_OVER;
	
	if(strength > 1)
		return error_t::WRONG_CONFIG;

	if(otype > 1)
		return error_t::WRONG_CONFIG;
	
	__disable_irq();
	mAfc->REGISTER[pin] = altfunc;
	mPadcon->REGISTER[pin] = (strength & 0x01) << 2 | (otype & 0x01) << 3 | 0x03 << 5;
	__enable_irq();

	return error_t::ERROR_NONE;
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	__disable_irq();
	if(data)
		mDev->DATAOUT |= 1 << pin;
	else
		mDev->DATAOUT &= ~(1 << pin);		
	__enable_irq();
}

#endif

