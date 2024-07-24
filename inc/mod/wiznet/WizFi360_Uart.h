/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_WIZNET_WIZFI360_UART__H_
#define YSS_MOD_WIZNET_WIZFI360_UART__H_

#include <drv/Uart.h>
#include <drv/Gpio.h>
#include <yss/error.h>
#include <yss/thread.h>
#include "WizFi360.h"

class WizFi360_Uart  : public WizFi360
{
public:
	struct config_t
	{
		Uart &peri;
		pin_t reset;
	};

	WizFi360_Uart(void);

	~WizFi360_Uart(void);

	error_t initialize(const config_t config);

protected:
	virtual error_t send(void *src, uint32_t size);

	virtual int16_t getRxByte(void);

	virtual void flush(void);

private:
	Uart *mPeri;
	pin_t mRst;
};

#endif

