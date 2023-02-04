////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/debug.h>
#include <mod/rtouch/STMPE811.h>
#include <yss/thread.h>
#include <yss/event.h>
#include <util/runtime.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

namespace ADDR
{
	enum
	{
		CHIP_ID = 0x00,
		ID_VER = 0x02,
		SYS_CTRL1 = 0x03,
		SYS_CTRL2 = 0x04,
		SPI_CFG = 0x08,

		INT_CTRL = 0x09,
		INT_EN = 0x0A,
		INT_STA = 0x0B,
		GPIO_INT_EN = 0x0C,
		GPIO_INT_STA = 0x0D,
		ADC_INT_EN = 0x0E,
		ADC_INT_STA = 0x0F,

		GPIO_SET_PIN = 0x10,
		GPIO_CLR_PIN = 0x11,
		GPIO_MP_STA = 0x12,
		GPIO_DIR = 0x13,
		GPIO_ED_STA = 0x14,
		GPIO_RE = 0x15,
		GPIO_FE = 0x16,
		GPIO_ALT_FUNC = 0x17,

		ADC_CTRL1 = 0x20,
		ADC_CTRL2 = 0x21,
		ADC_CAPT = 0x22,
	
		TSC_CTRL = 0x40,
		TSC_CFG = 0x41,
		WDW_TR_X = 0x42,
		WDW_TR_Y = 0x44,
		WDW_BL_X = 0x46,
		WDW_BL_Y = 0x48,
		FIFO_TH = 0x4A,
		FIFO_STA = 0x4B,
		FIFO_SIZE = 0x4C,
		TSC_DATA_X = 0x4D,
		TSC_DATA_Y = 0x4F,
		TSC_DATA_Z = 0x51,
		TSC_FRACTION_Z = 0x56,
		TSC_DATA_XYZ_AI = 0x57,
		TSC_DATA_XYZ_NAI = 0xD7,
		TSC_I_DRIVE = 0x58,
		TSC_SHIELD = 0x59,
	};
}

STMPE811::STMPE811(void)
{
	mPeri = 0;
	mThreadId = 0;
	mFirstFlag = false;
	mDetectedFlag = false;
	mY = mX = 0;
}

STMPE811::~STMPE811(void)
{
	if(mThreadId)
		thread::remove(mThreadId);
}

void STMPE811::sendByte(uint8_t addr, uint8_t data)
{
	uint8_t buf[2] = {addr, data};

	mPeri->lock();
	mPeri->send(0x82, buf, 2, 300);
	mPeri->stop();
	mPeri->unlock();
}

uint8_t STMPE811::receiveByte(uint8_t addr)
{
	mPeri->lock();
	if(mPeri->send(0x82, &addr, 1, 300))
		mPeri->receive(0x82, &addr, 1, 300);
	mPeri->stop();
	mPeri->unlock();

	return addr;
}

void STMPE811::isr(void)
{
	uint8_t data[4];
	uint8_t size, status;
	uint16_t x, y;
	
	// 인터럽트 처리가 수월하지 않아 폴링으로 처리	
	while(1)
	{
		if(mIsrPin.port->getInputData(mIsrPin.pin) == false)
		{
			status = receiveByte(ADDR::INT_STA);
			sendByte(ADDR::INT_STA, status);

			if(status & 0x01 && mDetectedFlag == false)
			{
				mFirstFlag = false;
				mLastUpdateTime.reset();
			}

			while(size = receiveByte(ADDR::FIFO_SIZE))
			{
				data[0] = ADDR::TSC_DATA_X;
				mPeri->lock();
				mPeri->send(0x82, data, 1, 300);
				mPeri->receive(0x82, data, 4, 300);
				mPeri->stop();
				mPeri->unlock();

				mX = (uint16_t)data[0] << 8;
				mX |= data[1];
				mY = (uint16_t)data[2] << 8;
				mY |= data[3];

				if(mFirstFlag == false)
				{
					mDetectedFlag = true;
					mFirstFlag = true;
					push(mX, mY, event::TOUCH_DOWN);
				}
				else
					push(mX, mY, event::TOUCH_DRAG);

				mLastUpdateTime.reset();
			}
		}

		if(mDetectedFlag && mLastUpdateTime.getMsec() >= 100)
		{
			mDetectedFlag = false;
			push(mX, mY, event::TOUCH_UP);
		}

		thread::yield();
	}
}

void thread_isr(void* var)
{
	STMPE811 *obj = (STMPE811*)var;
	obj->isr();
}

bool STMPE811::init(const Config &config)
{
	int8_t data[64];

	mPeri = &config.peri;
	mIsrPin = config.isrPin;

	if(receiveByte(ADDR::CHIP_ID) != 0x08 || receiveByte(ADDR::CHIP_ID+1) != 0x11)
		return false;

	sendByte(ADDR::SYS_CTRL1, 0x02);
	sendByte(ADDR::SYS_CTRL2, 0x0C);
	sendByte(ADDR::INT_EN, 0x02);
	sendByte(ADDR::ADC_CTRL1, 0x00);
	thread::delay(2);
	sendByte(ADDR::GPIO_ALT_FUNC, 0x00);
	sendByte(ADDR::TSC_CFG, 0xE3);
	sendByte(ADDR::FIFO_TH, 0x05);
	sendByte(ADDR::FIFO_STA, 0x01);
	sendByte(ADDR::FIFO_STA, 0x00);
	sendByte(ADDR::TSC_FRACTION_Z, 0x07);
	sendByte(ADDR::TSC_I_DRIVE, 0x00);
	sendByte(ADDR::TSC_CTRL, 0x03);
	sendByte(ADDR::INT_STA, 0xFF);
	sendByte(ADDR::INT_CTRL, 0x01);
	
	mIsrPin.port->setPullUpDown(mIsrPin.pin, define::gpio::pupd::PULL_UP);
	mThreadId = thread::add(thread_isr, this, 512);

	return true;
}

#endif


