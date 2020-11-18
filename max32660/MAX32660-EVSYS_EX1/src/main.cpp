//
// main.cpp : Defines entry point for an MAX32660 C/C++ application.
//

#include <max32660.h>
#include <yss/yss.h>
#include <__cross_studio_io.h>

Mutex gMutex;

void thread_test1(void)
{
	while(1)
	{
		gMutex.lock();
		debug_printf("thread1!!\n");
		gMutex.unlock();
		thread::delay(500);
	}
}

void thread_test2(void)
{
	while(1)
	{
		gMutex.lock();
		debug_printf("thread2!!\n");
		gMutex.unlock();
		thread::delay(500);
	}
}

void thread_uart1Rx(void)
{
	unsigned char data;
	while(1)
	{
		data = uart1.getWaitUntilReceive();
		gMutex.lock();
		debug_printf("0x%02x\n", data);
		gMutex.unlock();
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
	uart1.init(9000, 4096);
	uart1.setIntEn(true);

	// I2C0 init
	gpio0.setToAltFunc(8, altfunc::P0_8_AF1_I2C0_SCL);
	gpio0.setToAltFunc(9, altfunc::P0_9_AF1_I2C0_SDA);

	i2c0.setClockEn(true);
	i2c0.init(define::i2c::speed::STANDARD);
	i2c0.setIntEn(true);

	//thread::add(thread_test1, 1024);
	//thread::add(thread_test2, 1024);
	thread::add(thread_uart1Rx, 1024);

	while(1)
	{
		uart1.send("hello world!!\n\r", sizeof("hello world!!\n\r"), 1000);
		gpio0.setOutput(13, true);
		thread::delay(500);
		gpio0.setOutput(13, false);
		thread::delay(500);
	}
	return 0;
}
