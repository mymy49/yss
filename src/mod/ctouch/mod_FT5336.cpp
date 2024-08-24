/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/ctouch/FT5336.h>
#include <yss/event.h>
#include <drv/Exti.h>
#include <yss/debug.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

#define ADDR		0x70
static void trigger_handler(void *peri);

error_t FT5336::initialize(const config_t config)
{
	error_t result;
	
	mPeri = &config.peri;
	mIsr = config.isrPin;
	
	if(config.resetPin.port)
	{
		config.resetPin.port->setOutput(config.resetPin.pin, false);
		thread::delay(10);
		config.resetPin.port->setOutput(config.resetPin.pin, true);
	}
	thread::delay(200);

	if(getByte(0xa8) != 0x51)
		return error_t::FAIL;

	mTriggerId = trigger::add(trigger_handler, this, 512);

	if(mTriggerId == 0)
		return error_t::FAILED_THREAD_ADDING;

	result = exti.add(*mIsr.port, mIsr.pin, Exti::FALLING, mTriggerId);
	if(result == error_t::ERROR_NONE)
		exti.enable(mIsr.pin);

	return result;
}

int8_t FT5336::getByte(int8_t addr)
{
	mPeri->lock();
	mPeri->send(ADDR, (int8_t*)&addr, 1, 100);
	mPeri->receive(ADDR, (int8_t*)&addr, 1, 100);
	mPeri->stop();
	mPeri->unlock();

	return addr;
}

error_t FT5336::getMultiByte(int8_t addr, uint8_t *des, uint8_t size)
{
	error_t rt = error_t::UNKNOWN;

	mPeri->lock();
	if(mPeri->send(ADDR, &addr, 1, 100) == error_t::ERROR_NONE)
	{
		rt = mPeri->receive(ADDR, des, size, 100);
	}
	mPeri->stop();
	mPeri->unlock();

	return rt;
}

void FT5336::isr(void)
{
	static bool penDown = false;
	uint16_t x, y;
	uint8_t data[5], event;

	getMultiByte(0x02, data, 5);
	if(data[0] <= 1)
	{
		event = data[1] >> 6;
		
		data[1] &= 0x0F;
		y = (uint16_t)data[1] << 8;
		y |= data[2];
		x = (uint16_t)data[3] << 8;
		x |= data[4];

		if((event == 0x00) && (penDown == false))
		{
			penDown = true;
			push(x, y, event::TOUCH_DOWN);
		}
		else if((event == 0x02) && penDown == true)
		{
			push(x, y, event::TOUCH_DRAG);
		}
		else if((event == 0x01) && penDown == true)
		{
			penDown = false;
			push(x, y, event::TOUCH_UP);
		}
	}
}

static void trigger_handler(void *var)
{
	((FT5336*)var)->isr();
}

#endif

