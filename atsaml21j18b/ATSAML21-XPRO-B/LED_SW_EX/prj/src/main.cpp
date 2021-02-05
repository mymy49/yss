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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.01.19 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <sam.h>
#include <yss/yss.h>
#include <__cross_studio_io.h>

void thread_sw(void)
{
	while(1)
	{
		if(!gpioA.getData(2))
		{
			debug_printf("push!!\n");
			while(!gpioA.getData(2));
				thread::yield();
		}
	}
}

int main(void)
{
	yss::init();

	gpioB.setToOutput(10);
	gpioA.setToInput(2, define::gpio::pupd::PULL_UP);

	gpioA.setToAltFunc(0, 2, 0, 0);

	thread::add(thread_sw, 512);

	while(1)
	{
		gpioB.setOutput(10, true);
		for(volatile int i=0;i<100000;i++);
		gpioB.setOutput(10, false);
		for(volatile int i=0;i<100000;i++);
		thread::yield();
	}
	return 0;
}