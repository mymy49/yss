//
// main.cpp : Defines entry point for an MAX32660 C/C++ application.
//

#include <max32660.h>
#include <yss/yss.h>
#include <__cross_studio_io.h>

int main(int argc, char *argv[])
{
	char data[10];

	yss::init();

	using namespace define::gpio;

	// I2C0 init
	gpio0.setToAltFunc(8, altfunc::P0_8_AF1_I2C0_SCL);
	gpio0.setToAltFunc(9, altfunc::P0_9_AF1_I2C0_SDA);

	i2c0.setClockEn(true);
	i2c0.init(define::i2c::speed::STANDARD);
	i2c0.setIntEn(true);

	i2c0.send(0xF0, data, 10, 1000);

	while(1)
	{
		thread::yield();
	}
	return 0;
}
