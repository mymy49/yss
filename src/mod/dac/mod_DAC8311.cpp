/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/dac/DAC8311.h>
#include <string.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

namespace mod
{
namespace dac
{
static const Spi::specification_t gConfig =
{
	Spi::MODE_MODE1,	//uint8_t mode;
	20000000,			//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
}; 

DAC8311::DAC8311(void)
{
	mPowerDown = PD_1KOHM_PULL_DOWN;
	mValue = 0;
}

bool DAC8311::initialize(const Config config)
{
	mPeri = &config.peri;
	mCs = config.chipSelect;
	mCs.port->setOutput(mCs.pin, true);

	return send();
}

bool DAC8311::setValue(uint16_t value)
{
	mValue = value & 0x3FFF;

	return send();
}

void DAC8311::setPowerDown(uint16_t mode)
{
	mPowerDown = mode & 0xC000;
}

union Data
{
	uint16_t halfword;
	uint8_t byte[2];
};

bool DAC8311::send(void)
{
	bool rt;
	Data data;
	uint8_t buf;

	data.halfword = mValue | mPowerDown;
	buf = data.byte[0];
	data.byte[0] = data.byte[1];
	data.byte[1] = buf;

	mPeri->lock();
	mPeri->setSpecification(gConfig);
	mPeri->enable(true);
	mCs.port->setOutput(mCs.pin, false);
	rt = mPeri->send(&data, 2);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();

	return rt;
}
}
}

#endif
