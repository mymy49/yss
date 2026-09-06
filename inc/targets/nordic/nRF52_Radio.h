/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_RADIO_NRF52__H_
#define YSS_CLASS_RADIO_NRF52__H_

#include <hal/BleRadio.h>
#include <drv/Drv.h>
#include <yss/scheduler.h>
#include <yss/error.h>

class nRF52_Radio : public BleRadio, public Drv
{
	enum status_t
	{
		STATUS_TRANSMIT_ONE_SHOT,
		STATUS_RECEIVE_ONE_SHOT,
		STATUS_TRANSMIT_ADV,
		STATUS_WAIT_FOR_SCAN_REQ,
		STATUS_TRANSMIT_ADV_SCAN_RSP
	};

	enum result_t
	{
		RESULT_PROCESS,
		RESULT_COMPLETE,
		RESULT_NO_SCAN_REQ,
	};

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

	error_t receive(uint32_t timeout = 1000) override;

	error_t transmit(uint32_t timeout = 1000) override;

	error_t transmitAdv(uint32_t timeout = 1000, uint16_t tifs = 150) override;

	// Internal system interrupt routine. Do not call from user application.
	void isr(void)  __attribute__((optimize("-O0")));

private :
	NRF_RADIO_Type *mDev;
	volatile threadId_t mThreadId;
	volatile result_t mResult;
	status_t mStatus;
};

#endif


