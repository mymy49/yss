/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_POWERAMP_TAS5756M__H_
#define YSS_MOD_POWERAMP_TAS5756M__H_

#include <yss/instance.h>
#include <yss/error.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

/*
	현재 작성중으로 사용이 불가능합니다.
*/
class TAS5756M
{
public :
	typedef enum
	{
		ADDR0 = 0x0,
		ADDR1 = 0x2,
		ADDR2 = 0x4,
		ADDR3 = 0x6,
	}addr_t;

	struct config_t
	{
		I2c &peri;
		addr_t addr;
	};

	TAS5756M(void);

	error_t initialize(const config_t config);

	error_t reset(void);

	uint8_t getStatus(void);
	
	typedef enum
	{
		WORD_LENGTH_16BIT = 0,
		WORD_LENGTH_20BIT,
		WORD_LENGTH_24BIT,
		WORD_LENGTH_32BIT
	}wordLength_t;

	void setWordLength(wordLength_t wordLength);

	void setVolume(uint8_t vol);

protected :

	error_t readRegister(uint8_t addr, uint8_t &data);

	error_t writeRegister(uint8_t addr, uint8_t data);

private :
	I2c *mPeri;
	uint8_t mAddr;

//	uint8_t 
};

#endif

#endif

