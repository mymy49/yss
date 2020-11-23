////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/yss.h>
#include <__cross_studio_io.h>
#include <string.h>
#include <util/TimeLapse.h>

int main(int argc, char *argv[])
{
	char data[10];
	char addr[2];
	TimeLapse timelapse;
	unsigned int spendTime1, spendTime2;

	yss::init();

	using namespace define::gpio;

	// I2C2 init
	gpioB.setToAltFunc(10, define::gpio::altfunc::PB10_I2C2_SCL, define::gpio::ospeed::LOW, define::gpio::otype::OPEN_DRAIN);
	gpioB.setToAltFunc(11, define::gpio::altfunc::PB11_I2C2_SDA, define::gpio::ospeed::LOW, define::gpio::otype::OPEN_DRAIN);
	clock.peripheral.setI2c2En(true);
	i2c2.init(define::i2c::speed::STANDARD);

	memset(data, 0, 10);
	memset(addr, 0, 2);

	timelapse.reset();
	i2c2.send(0xA0, data, 2, 1000);
	i2c2.receive(0xA0, data, 4, 1000);
	spendTime1 = timelapse.getUsec();

	i2c2.send(0xA0, data, 2, 1000);
	i2c2.receive(0xA0, data, 4, 1000);
	spendTime2 = timelapse.getUsec();

	debug_printf("spend time1 = %d usec\n", spendTime1);
	debug_printf("spend time2 = %d usec\n", spendTime2);

	while(1)
	{
		thread::yield();
	}
	return 0;
}
