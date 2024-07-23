/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <mod/wiznet/WizFi360_Uart.h>
#include <yss/thread.h>
#include <yss/debug.h>
#include <drv/Uart.h>

#if USE_GUI && !defined(YSS_DRV_UART_UNSUPPORTED)

WizFi360_Uart::WizFi360_Uart(void)
{
	mPeri = 0;
}

WizFi360_Uart::~WizFi360_Uart(void)
{

}

error_t WizFi360_Uart::initialize(const config_t config)
{
	mPeri = &config.peri;
	mRst = config.reset;

	if(mRst.port)
	{
		mRst.port->setOutput(mRst.pin, false);
		thread::delay(100);
		mRst.port->setOutput(mRst.pin, true);
	}

	return WizFi360::initialize();
}

error_t WizFi360_Uart::send(void *src, uint32_t size)
{
	error_t rt;

	if(mPeri == nullptr)
		return error_t::NOT_INITIALIZED;
	
	mPeri->lock();
	rt = mPeri->send(src, size);
	mPeri->unlock();

	return rt;
}

int16_t WizFi360_Uart::getRxByte(void)
{
	if(mPeri == nullptr)
		return -1;
	else
		return mPeri->getRxByte();
}

void WizFi360_Uart::flush(void)
{
	mPeri->flush();
}

#endif

