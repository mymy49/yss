//
// main.cpp : Defines entry point for an MAX32660 C/C++ application.
//

#include <max32660.h>
#include <yss/yss.h>
#include <__cross_studio_io.h>
#include <string.h>

void thread_uart1Rx(void)
{
	unsigned char data;
	while(1)
	{
		data = uart1.getWaitUntilReceive();
		debug_printf("0x%02x\n", data);
	}
}

int main(int argc, char *argv[])
{
	yss::init();

	using namespace define::gpio;
	// LED init
	gpio0.setToOutput(13);

	// UART1 init
	gpio0.setToAltFunc(10, altfunc::P0_10_AF2_UART1_TX);
	gpio0.setToAltFunc(11, altfunc::P0_11_AF2_UART1_RX);

	uart1.setClockEn(true);
	uart1.init(9600, 4096);
	uart1.setIntEn(true);

	thread::add(thread_uart1Rx, 1024);

	const char *str = "hello world!!\n\r";

	while(1)
	{
		uart1.send(str, strlen(str), 1000);
		thread::delay(500);
	}
	return 0;
}
