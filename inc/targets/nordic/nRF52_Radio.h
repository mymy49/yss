/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_RADIO_NRF52__H_
#define YSS_CLASS_RADIO_NRF52__H_

#include <hal/Ble.h>
#include <drv/Drv.h>
#include <yss/scheduler.h>
#include <yss/error.h>

class nRF52_Radio : public Ble, public Drv
{
public :
	typedef struct
	{
		NRF_RADIO_Type *dev;
	}setup_t;

	nRF52_Radio(const Drv::setup_t drvSetup, const nRF52_Radio::setup_t setup);

	typedef struct
	{

	}config_t;

	error_t initialize(config_t config);

	error_t initializeAsBle() override;

	error_t setChannel(uint8_t channel) override;

	error_t setSpeed(speed_t speed) override;

	error_t receive() override;

	void* getRxBuffer() override;

	// Internal system interrupt routine. Do not call from user application.
	void isr(void);

private :
	NRF_RADIO_Type *mDev;
	threadId_t mThreadId;
	uint8_t *mRadioBuffer;
};

#endif


