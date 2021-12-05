#include <mod/codec/WM8994.h>
#include <__cross_studio_io.h>

namespace mod
{
namespace codec
{
WM8994::WM8994(void)
{
	mInitFlag = false;
	mAddr = ADDR_LOW;
	mCMFMODpin.port = 0;
	mCMFMODpin.pin = 0;
	mPeri = 0;
}

bool WM8994::init(const Config config)
{
	unsigned short data;

	mPeri = &(config.peri);
	mAddr = config.addr;
	mCMFMODpin = config.CMFMOD;
	mInitFlag = true;

	if(mCMFMODpin.port)
		mCMFMODpin.port->setOutput(mCMFMODpin.pin, false);

	read(0, &data, 1);

	if(data == 0x8994)
		return true;
	else
		return false;
}

bool WM8994::read(unsigned short addr, void *des, unsigned int len)
{
	bool result;
	unsigned char buf;
	unsigned char *cDes = (unsigned char*)des;

	len *= 2;

	mPeri->lock();
	result = mPeri->send(mAddr, &addr, 2);
	if(result)
		result = mPeri->receive(mAddr, des, len);
	mPeri->stop();
	mPeri->unlock();

	if(result)
	{
		for(int i=0;i<len;i+=2)
		{
			buf = cDes[i];
			cDes[i] = cDes[i+1];
			cDes[i+1] = buf;
		}
	}

	return result;
}

}
}