/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

