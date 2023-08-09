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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Exti.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/nordic/nrf52840_bitfields.h>

static int8_t gPortList[EXTI_COUNT];

static int8_t findId(int8_t pinId)
{
	for(int8_t i=0;i<EXTI_COUNT;i++)
	{
		if(gPortList[i] == pinId)
			return i;
	}

	return -1;
}

static int8_t findEmpty(void)
{
	for(int8_t i=0;i<EXTI_COUNT;i++)
	{
		if(gPortList[i] == -1)
			return i;
	}

	return -1;
}

Exti::Exti(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
	for(uint32_t i=0;i<EXTI_COUNT;i++)
		gPortList[i] = -1;
}

error Exti::add(Gpio &gpio, uint8_t pin, uint8_t mode, void (*func)(void))
{
	int8_t pinId, index, port;

	if (pin > 31)
		return error::INDEX_OVER;

	if(gpio.getPeripheralAddress() == NRF_P0_BASE)
	{
		pinId = pin;
		port = 0;
	}
	else
	{
		pinId = pin + 32;
		port = 1;
	}
	
	index = findId(pinId);

	if(index >= 0)
		return error::IT_ALREADY_HAVE;
	
	index = findEmpty();
	gPortList[index] = pinId;
	mTriggerFlag[index] = false;
	mIsr[index] = func;
	
	NRF_GPIOTE->CONFIG[index] = (GPIOTE_CONFIG_MODE_Event << GPIOTE_CONFIG_MODE_Pos) | 
								(pin << GPIOTE_CONFIG_PSEL_Pos) |
								(port << GPIOTE_CONFIG_PORT_Pos) |
								(mode << GPIOTE_CONFIG_POLARITY_Pos);
	
	NRF_GPIOTE->INTENSET = 1 << index;

	return error::ERROR_NONE;
}

error Exti::add(Gpio &gpio, uint8_t pin, uint8_t mode, int32_t  trigger)
{
	int8_t pinId, index, port;

	if (pin > 31)
		return error::INDEX_OVER;

	if(gpio.getPeripheralAddress() == NRF_P0_BASE)
	{
		pinId = pin;
		port = 0;
	}
	else
	{
		pinId = pin + 32;
		port = 1;
	}
	
	index = findId(pinId);

	if(index >= 0)
		return error::IT_ALREADY_HAVE;
	
	index = findEmpty();
	gPortList[index] = pinId;
	mTriggerFlag[index] = true;
	mTriggerNum[index] = trigger;
	
	NRF_GPIOTE->CONFIG[index] = (GPIOTE_CONFIG_MODE_Event << GPIOTE_CONFIG_MODE_Pos) | 
								(pin << GPIOTE_CONFIG_PSEL_Pos) |
								(port << GPIOTE_CONFIG_PORT_Pos) |
								(mode << GPIOTE_CONFIG_POLARITY_Pos);
	
	NRF_GPIOTE->INTENSET = 1 << index;

	return error::ERROR_NONE;
}

void Exti::isr(int32_t  num)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	if (mTriggerFlag[num])
		trigger::run(mTriggerNum[num]);
	else if(mIsr[num])
		mIsr[num]();
#else
	if (mIsr[num])
		mIsr[num]();
#endif
}

#endif

