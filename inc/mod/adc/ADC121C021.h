/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_ADC_ADC121C021__H_
#define YSS_MOD_ADC_ADC121C021__H_

#include <yss/instance.h>

#ifndef YSS_DRV_I2C_UNSUPPORTED

namespace mod
{
namespace adc
{
class ADC121C021
{
	I2c *mPeri;
	uint8_t mConfigReg;
	bool mInitFlag;

	void sendResistor(uint8_t addr, uint8_t data);

  public:
	struct Config
	{
		I2c &peri;
	};

	enum // setConversionTime(cycleTime)
	{
		CYCLE_TIME_0_KSPS = 0,
		CYCLE_TIME_27_KSPS = 1,
		CYCLE_TIME_13_5_KSPS = 2,
		CYCLE_TIME_6_7_KSPS = 3,
		CYCLE_TIME_3_4_KSPS = 4,
		CYCLE_TIME_1_7_KSPS = 5,
		CYCLE_TIME_0_9_KSPS = 6,
		CYCLE_TIME_0_4_KSPS = 7
	};

	ADC121C021(void);
	bool init(const Config config);
	void setConversionTime(uint8_t cycleTime);
	uint16_t getResult(void);
	void setAddr(uint8_t addr);
};
}
}

#endif

#endif

