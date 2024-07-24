/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F7) || defined(GD32F1) || defined(STM32F0) || defined(STM32F1)

#include <drv/Exti.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Exti::Exti(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
}

error_t Exti::add(Gpio &gpio, uint8_t pin, mode_t mode, void (*func)(void))
{
	if (pin > 15)
		return error_t::INDEX_OVER;

	mTriggerFlag[pin] = false;
	mIsr[pin] = func;
	gpio.setExti(pin);

	setBitData(EXTI->RTSR, (Exti::RISING & mode) == Exti::RISING, pin);
	setBitData(EXTI->FTSR, (Exti::FALLING & mode) == Exti::FALLING, pin);

	return error_t::ERROR_NONE;
}

error_t Exti::add(Gpio &gpio, uint8_t pin, mode_t mode, triggerId_t  trigger)
{
	if (pin > 15)
		return error_t::INDEX_OVER;

	mTriggerFlag[pin] = true;
	mTriggerNum[pin] = trigger;
	gpio.setExti(pin);
	
	setBitData(EXTI->RTSR, (Exti::RISING & mode) == Exti::RISING, pin);
	setBitData(EXTI->FTSR, (Exti::FALLING & mode) == Exti::FALLING, pin);

	return error_t::ERROR_NONE;
}

void Exti::enable(uint8_t pin, bool enable)
{
	setBitData(EXTI->IMR, enable, pin);	
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

