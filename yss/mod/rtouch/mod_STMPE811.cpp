////////////////////////////////////////////////////////////////////////////////////////
//
//  저작권 표기		License_ver_1.1
//  본 소스코드의 소유권은 홍윤기에게 있습니다.
//  본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
//  아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//  본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//  본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
//  본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
//  본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
//  본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	E-mail : mymy49@nate.com
//  Copyright 2016. Yoon-Ki Hong all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <mod/rtouch/STMPE811.h>
#include <drv/peripherals.h>
#include <yss/thread.h>
#include <yss/event.h>
#include <util/time.h>

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

namespace mod
{
namespace rtouch
{
	STMPE811::STMPE811(void)
	{
		mPeri = 0;
        mId = 0;
        mFirst = true;
	}

	void STMPE811::sendByte(unsigned char addr, unsigned char data)
	{
		unsigned char buf[2] = {addr, data};
		
		mPeri->lock();
		mPeri->send(0x82, buf, 2, 300);
		mPeri->stop();
		mPeri->unlock();
	}

	unsigned char STMPE811::receiveByte(unsigned char addr)
	{
		mPeri->lock();
		if(mPeri->send(0x82, &addr, 1, 300))
			mPeri->receive(0x82, &addr, 1, 300);
		mPeri->stop();
		mPeri->unlock();
		
		return addr;
	}

	void thread_isr(void *var)
    {
		STMPE811 *peri = (STMPE811*)var;

		while(1)
		{
			peri->handleIsr();
        }
    }

    void trigger_Isr(void *var)
    {
		STMPE811 *peri = (STMPE811*)var;
        peri->handleIsr();
    }
	
	void STMPE811::handleIsr(void)
    {
		unsigned char data[4];
		unsigned char size;
		unsigned short x, y;
		
		size = receiveByte(ADDR::FIFO_SIZE);
		
		if(size)
		{
			data[0] = ADDR::TSC_DATA_X;
			mPeri->lock();
			mPeri->send(0x82, data, 1, 300);
			mPeri->receive(0x82, data, 4, 300);
			mPeri->stop();
			mPeri->unlock();

			x = (unsigned short)data[0] << 8;
			x |= data[1];
			y = (unsigned short)data[2] << 8;
			y |= data[3];

			if(x || y)
			{
				if(mFirst)
				{
					mFirst = false;
                    mLastX = x;
                    mLastY = y;
					set(x, y, event::PUSH);
					trigger();
				}
				else
				{
					if(mLastX != x || mLastY != y)
                    {
						set(x, y, event::DRAG);
						trigger();
					}
				}
			}

			mLastUpdateTime = time::getRunningMsec();
		}
		else if(mFirst == false && mLastUpdateTime + 100 < time::getRunningMsec())
        {
			mFirst = true;
			set(0, 0, event::UP);
			trigger();
        }
        else
			thread::delay(25);
    }

	bool STMPE811::getIsrState(void)
    {
		return mIsr.port->getData(mIsr.pin);
    }

	bool STMPE811::init(drv::I2c &peri, config::gpio::Set &isr)
	{
		char data[64];

		mPeri = &peri;
		mIsr = isr;

        if(receiveByte(ADDR::CHIP_ID) != 0x08 || receiveByte(ADDR::CHIP_ID+1) != 0x11)
			return false;

		sendByte(ADDR::SYS_CTRL1, 0x02);
		sendByte(ADDR::SYS_CTRL2, 0x0c);
		sendByte(ADDR::INT_EN, 0x02);
		sendByte(ADDR::ADC_CTRL1, 0x00);
		thread::delay(2);
		sendByte(ADDR::GPIO_ALT_FUNC, 0x00);
		sendByte(ADDR::TSC_CFG, 0x2d);
		sendByte(ADDR::FIFO_TH, 0x01);
		sendByte(ADDR::FIFO_STA, 0x01);
		sendByte(ADDR::FIFO_STA, 0x00);
		sendByte(ADDR::TSC_FRACTION_Z, 0x07);
		sendByte(ADDR::TSC_I_DRIVE, 0x00);
		sendByte(ADDR::TSC_CTRL, 0x03);
		sendByte(ADDR::INT_STA, 0xff);
		sendByte(ADDR::INT_CTRL, 0x01);
		
        thread::add(thread_isr, this, 1024);
        return true;
	}
}
}

