#include <mod/dac/DAC8311.h>
#include <string.h>

#if !defined(YSS_DRV_SPI_NOT_SUPPORT)

namespace mod
{
namespace dac
{
static config::spi::Config gConfig =
	{
		define::spi::mode::MODE1, //unsigned char mode;
		20000000,                 //unsigned int maxFreq;
		define::spi::bit::BIT8};  //unsigned char bit;

DAC8311::DAC8311(void)
{
	mPowerDown = PD_1KOHM_PULL_DOWN;
	mValue = 0;
}

bool DAC8311::init(const Config config)
{
	mPeri = &config.peri;
	mCs = config.chipSelect;
	mCs.port->setOutput(mCs.pin, true);

	return send();
}

bool DAC8311::setValue(unsigned short value)
{
	mValue = value & 0x3FFF;

	return send();
}

void DAC8311::setPowerDown(unsigned short mode)
{
	mPowerDown = mode & 0xC000;
}

union Data
{
	unsigned short halfword;
	unsigned char byte[2];
};

bool DAC8311::send(void)
{
	bool rt;
	Data data;
	unsigned char buf;

	data.halfword = mValue | mPowerDown;
	buf = data.byte[0];
	data.byte[0] = data.byte[1];
	data.byte[1] = buf;

	mPeri->lock();
	mPeri->setConfig(gConfig);
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
