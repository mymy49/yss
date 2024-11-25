/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_INTERFACE_PCA9555A__H_
#define YSS_MOD_INTERFACE_PCA9555A__H_

#include <yss/instance.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED)

class PCA9555A
{
public:
	typedef enum
	{
		ADDR0 = 0x0,
		ADDR1 = 0x2,
		ADDR2 = 0x4,
		ADDR3 = 0x6,
		ADDR4 = 0x8,
		ADDR5 = 0xA,
		ADDR6 = 0xC,
		ADDR7 = 0xE
	}addr_t;

	typedef struct 
	{
		I2c &dev;
		addr_t addr;
	}config_t;

	error_t initialize(const config_t config);

	typedef enum
	{
		PORT_P0 = 0,
		PORT_P1
	}port_t;

	uint8_t read(port_t port);

	void write(port_t port, uint8_t data);
	
	/*
		핀의 입출력 방향을 설정하는 함수입니다.
		port에서 선택된 포트 전체를 동시에 변경합니다.
		.
		@ port : 입출력 방향을 변경할 포트를 설정합니다.
		@ direction : 설정된 포트의 전체 방향을 설정합니다. '1'은 입력, '0'은 출력입니다.
	*/
	void setDirection(port_t port, uint8_t direction);

	void polarity(port_t port, uint8_t polarity);

	PCA9555A(void);

private :
	I2c *mDev;
	bool mInitFlag;
	uint8_t mAddr;
};

#endif

#endif

