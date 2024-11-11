/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_INTERFACE_MCP23017__H_
#define YSS_MOD_INTERFACE_MCP23017__H_

#include <yss/instance.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED)

class MCP23017
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

	typedef enum
	{
		PORT_GPA = 0x0,
		PORT_GPB
	}port_t;

	struct config_t
	{
		I2c &dev;
		addr_t addr;
	};

	error_t initialize(const config_t config);

	void write(port_t port, uint8_t data);

	void setDirection(port_t port, uint8_t direction);

	MCP23017(void);

private :
	I2c *mDev;
	bool mInitFlag;
	uint8_t mAddr;
};

#endif

#endif

