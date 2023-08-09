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

#include <mod/ctouch/FT5336.h>
#include <yss/event.h>
#include <drv/Exti.h>
#include <yss/debug.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

#define ADDR		0x70
static void trigger_handler(void *peri);

error FT5336::initialize(const Config config)
{
	uint8_t data;
	error result;
	
	mPeri = &config.peri;
	mIsr = config.isrPin;
	
	if(config.resetPin.port)
	{
		config.resetPin.port->setOutput(config.resetPin.pin, false);
		thread::delay(10);
		config.resetPin.port->setOutput(config.resetPin.pin, true);
	}
	thread::delay(100);

	if(getByte(0xa8) != 0x51)
		return error::FAIL;

	mTriggerId = trigger::add(trigger_handler, this, 512);

	if(mTriggerId == 0)
		return error::FAILED_THREAD_ADDING;

	result = exti.add(*mIsr.port, mIsr.pin, Exti::FALLING, mTriggerId);
	if(result == error::ERROR_NONE)
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

error FT5336::getMultiByte(int8_t addr, uint8_t *des, uint8_t size)
{
	error rt = error::UNKNOWN;

	mPeri->lock();
	if(mPeri->send(ADDR, &addr, 1, 100) == error::ERROR_NONE)
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
	uint8_t event, id;
	uint16_t x, y, buf;
	uint8_t data[5];

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

