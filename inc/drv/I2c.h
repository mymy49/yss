/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_I2C__H_
#define YSS_DRV_I2C__H_

#include "Drv.h"
#include <yss/error.h>

class I2c : public Drv
{
public:
    typedef enum
	{
		SPEED_STANDARD = 0,
		SPEED_FAST,
		SPEED_FAST_PLUS
	}speed_t;

	typedef struct
	{
		speed_t speed;			// 통신 속도
	}mainConfig_t;

	virtual error_t initialize(mainConfig_t config) __attribute__((optimize("-O1"))) = 0;

	virtual error_t send(uint8_t addr, void *src, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1"))) = 0;

	virtual error_t receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1"))) = 0;

	virtual void stop(void) __attribute__((optimize("-O1"))) = 0;

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
	I2c(const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));
};

#endif

