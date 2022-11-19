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

#include <mod/ctouch/FT5336.h>
#include <yss/event.h>
#include <drv/Exti.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

#if defined(I2C1)
#define ADDR		0x70
namespace mod
{
namespace ctouch
{
	static void trigger_handler(void *peri);

	bool FT5336::init(I2c &peri, Gpio::Pin &isr)
	{
		uint8_t data;

		mPeri = &peri;
		mIsr = isr;
		thread::delay(100);

		if(getByte(0xa8) != 0x51)
			return false;

		mTriggerId = trigger::add(trigger_handler, this, 512);

		if(mTriggerId == 0)
			return false;

		return exti.add(*mIsr.port, mIsr.pin, Exti::FALLING, mTriggerId);
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

	bool FT5336::getMultiByte(int8_t addr, uint8_t *des, uint8_t size)
	{
		bool rt = false;

		mPeri->lock();
		if(mPeri->send(ADDR, &addr, 1, 100))
		{
			rt = mPeri->receive(ADDR, des, size, 100);
		}
		mPeri->stop();
		mPeri->unlock();

		return rt;
	}

	static void trigger_handler(void *var)
	{
		FT5336 *ft5336 = (FT5336*)var;
		static bool penDown = false;
		uint8_t evt, id;
		uint16_t x, y, buf;
		uint8_t data[4];

		ft5336->getMultiByte(0x03, data, 4);
		evt = data[0];
		x = (evt & 0x0f) << 8;
		evt >>= 6;
		x |= (uint16_t)data[1];
		id = (uint16_t)data[2];
		y = (uint16_t)((id & 0x0f) << 8);
		id >>= 6;
		y |= (uint16_t)data[3];

//		if(gPort.swap)
//		{
			buf = x;
			x = y;
			y = buf;
//		}

		if((evt == 0x00) && (penDown == false))
		{
			penDown = true;
#if USE_GUI && YSS_L_HEAP_USE && USE_EVENT
			event::add(x, y, event::PUSH);
			event::trigger();
#endif
		}
		else if((evt == 0x02) && penDown == true)
		{
#if USE_GUI && YSS_L_HEAP_USE && USE_EVENT
			event::add(x, y, event::DRAG);
			event::trigger();
#endif
		}
		else if((evt == 0x01) && penDown == true)
		{
			penDown = false;
#if USE_GUI && YSS_L_HEAP_USE && USE_EVENT
			event::add(x, y, event::UP);
			event::trigger();
#endif
		}
	}
}
}

#endif

#endif
