/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SENSOR_ACCELEROMETER_LIS302DL__H_
#define YSS_MOD_SENSOR_ACCELEROMETER_LIS302DL__H_

#include <sac/Accelerometer3Axis.h>
#include <yss/instance.h>
#include <yss/error.h>
#include <drv/Gpio.h>
#include <util/ElapsedTime.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

/*
	ST사의 3축 가속도 센서입니다.
	사용 인터페이스는 SPI와 I2C로 구성되어 있는 제품으로 본 코드에서는 SPI만 지원하고 있습니다.
	ST사의 홈페이지에는 새로운 프로젝트에 적용하는 것을 권하지 않는 상황입니다.
	.
	아래는 설정의 예입니다.
	.
	LIS302DL accelerometer;
	.
	gpioE.setAsOutput(3);
	.
	LIS302DL::config_t accConfig = 
	{
		spi1,						//Spi &peri;
		{&gpioE, 3},				//pin_t chipSelect;
		LIS302DL::DATARATE_100HZ,	//uint8_t datarate;
		LIS302DL::FULLSCALE_9p2G	//uint8_t fullscale;
	};
	.
	accelerometer.initialize(accConfig);
*/
class LIS302DL : public Accelerometer3Axis
{
public :

	typedef enum
	{
		DATARATE_100HZ = 0,
		DATARATE_400HZ = 1,
	}datarate_t;

	typedef enum
	{
		FULLSCALE_2p3G = 0,
		FULLSCALE_9p2G = 1,
	}fullscale_t;

	typedef struct
	{
		Spi &peri;				// SPI 객체의 instance 설정
		pin_t chipSelect;		// Chip Select 핀 설정
		datarate_t datarate;	// data rate 설정
		fullscale_t fullscale;	// 측정 스케일 설정
	}config_t;

	LIS302DL(void);

	/*
		LIS302DL의 동작을 설정하고 초기화 합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ config : 동작 환경을 설정합니다.
	*/
	error_t initialize(const config_t config);

	/*
		측정 결과가 업데이트 됐는지 알려주는 함수입니다.
		.
		@ return : 측정 결과가 업데이트 되었을 경우 true를 반환합니다.
	*/
	virtual bool isUpdated(void);

	/*
		측정된 결과를 반환합니다.
		.
		@ return : 측정된 X, Y, Z축의 가속도를 반환합니다.
	*/
	virtual axis3_t getAccData(void);

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

