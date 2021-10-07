#include <__cross_studio_io.h>
#include <mod/rf/HC-12.h>
#include <string.h>

namespace mod
{
namespace rf
{
HC_12::HC_12(void)
{
	mPeri = 0;
}

bool HC_12::init(Config config)
{
	mPeri = &config.peri;
	mSet = config.set;
	mSet.port->setOutput(mSet.pin, true);

	return true;
}

bool HC_12::send(void *src, unsigned int size)
{
	return mPeri->send(src, size);
}

char HC_12::getWaitUntilReceive(void)
{
	return mPeri->getWaitUntilReceive();
}

signed short HC_12::get(void)
{
	return mPeri->get();
}
}
}