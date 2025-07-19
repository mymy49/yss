/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SENSOR_ACCELEROMETER_LIS302DL__H_
#define YSS_MOD_SENSOR_ACCELEROMETER_LIS302DL__H_

#include <sac/Accelerometer3D.h>
#include <yss/instance.h>
#include <yss/error.h>
#include <drv/Gpio.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class LIS302DL : public Accelerometer3D
{
public :
	enum
	{
		DATARATE_100H = 0,
		DATARATE_400H = 1,
		FULLSCALE_2p3G = 0,
		FULLSCALE_9p2G = 1,
	};

	typedef struct
	{
		Spi &peri;
		pin_t chipSelect;
		uint8_t datarate;
		uint8_t fullscale;
	}config_t;

	error_t initialize(const config_t config);

	virtual bool isUpdated(void);

	virtual accData_t getAccData(void);
	
	LIS302DL(void);

private :
	typedef enum
	{
		WHO_AM_I = 0x0F,
		CTRL_REG1 = 0x20,
		CTRL_REG2,
		CTRL_REG3,
		HP_FILTER_RESET,
		STATUS_REG = 0x27,
		OUT_X = 0x29,
		OUT_Y = 0x2B,
		OUT_Z = 0x2D,
		FF_WU_CFG_1 = 0x30,
		FF_WU_SRC_1,
		FF_WU_THS_1,
		FF_WU_DURATION_1,
		FF_WU_CFG_2,
		FF_WU_SRC_2,
		FF_WU_THS_2,
		FF_WU_DURATION_2,
		CLICK_CFG,
		CLICK_SRC,
		CLICK_THSY_X = 0x3B,
		CLICK_THSZ,
		CLICK_TimeLimit,
		CLICK_Latency,
		CLICK_Window
	}addr_t;

	uint8_t readRegister(addr_t addr);

	void writeRegister(addr_t addr, uint8_t data);

	void readRegister(addr_t addr, uint8_t *des, uint32_t size);

private :
	Spi *mPeri;
	pin_t mCsPin;
	ElapsedTime mUpdateTime;
	uint32_t mRefreshTime;
	float mSensitivity;
};

#endif

#endif

