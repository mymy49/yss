////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <config.h>
#include <string.h>
#include <yss/yss.h>

const drv::Gpio::Pin gDetectPin = {&gpioC, 13};
bool gSdmmcAbleFlag;
int gThreadId;

void thread_testSdMemory(void)
{
	unsigned char blockBuf[512];
	unsigned int maxBlockAddr = sdmmc.getNumOfBlock();

	memset(blockBuf, 0xBB, 512);

	sdmmc.lock();
	sdmmc.read(maxBlockAddr - 1, blockBuf);
	sdmmc.unlock();

	memset(blockBuf, 0xAA, 512);

	sdmmc.lock();
	sdmmc.write(maxBlockAddr - 1, blockBuf);
	sdmmc.unlock();

	memset(blockBuf, 0xBB, 512);

	sdmmc.lock();
	sdmmc.read(maxBlockAddr - 1, blockBuf);
	sdmmc.unlock();

	while(1)
	{
		thread::yield();
	}
}

void isr_detectSdMemory(bool detect)
{
	if(detect)
	{
		debug_printf("SD memory detected!!\n");
		if(gThreadId == 0)
			gThreadId = thread::add(thread_testSdMemory, 2048);
	}
	else
	{
		debug_printf("SD memory removed!!\n");
		if(gThreadId)
		{
			thread::remove(gThreadId);
			gThreadId = 0;
		}
	}
}

int main(void)
{
	yss::init();

	using namespace define::gpio;

	// SDMMC Init
	gpioC.setAsAltFunc(8, altfunc::PC8_SDMMC1_D0);
	gpioC.setAsAltFunc(9, altfunc::PC9_SDMMC1_D1);
	gpioC.setAsAltFunc(10, altfunc::PC10_SDMMC1_D2);
	gpioC.setAsAltFunc(11, altfunc::PC11_SDMMC1_D3);
	gpioC.setAsAltFunc(12, altfunc::PC12_SDMMC1_CK);
	gpioD.setAsAltFunc(2, altfunc::PD2_SDMMC1_CMD);

	sdmmc.setClockEn(true);
	sdmmc.init();
	sdmmc.setVcc(3.3);
	sdmmc.setDetectPin({&gpioC, 13});
	sdmmc.setInterruptEn(true);
	sdmmc.start();

	while(1)
	{
		thread::yield();
	}
	return 0;
}

