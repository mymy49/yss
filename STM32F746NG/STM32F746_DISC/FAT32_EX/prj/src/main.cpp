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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2019.12.22 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <config.h>
#include <string.h>
#include <yss/yss.h>
#include <yss/Fat32.h>
#include <yss/error.h>

const drv::Gpio::Pin gDetectPin = {&gpioC, 13};
bool gSdmmcAbleFlag;
int gThreadId;
Fat32 gFat32(sdmmc);

void isr_detectSdMemory(bool detect)
{
	error result;
	char *name = new char[512];
	int fileCount, directoryCount;

	if(detect)
	{
		result = gFat32.init();
		if(result == Error::NONE)
		{
			fileCount = gFat32.getFileCount();
			directoryCount = gFat32.getDirectoryCount();

			debug_printf("SD memory detected!!\n");
			debug_printf("File count of Root directory = %d\n", fileCount);
			debug_printf("Directory count of Root directory = %d\n", directoryCount);

			debug_printf("\nDirectory list of Root directory\n");
			for(int i=0;i<directoryCount;i++)
			{
				if(gFat32.getDirectoryName(i, name, 512) == Error::NONE)
					debug_printf("[%d] %s\n", i, name);
			}
		}
		else
		{
			debug_printf("SD memory error!!\n");
		}
	}
	else
	{
		debug_printf("SD memory removed!!\n");
	}

	delete name;
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
	sdmmc.setDetectionIsr(isr_detectSdMemory);
	sdmmc.start();

	while(1)
	{
		thread::yield();
	}
	return 0;
}

