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
#include <yss/Fat32.h>
#include <yss/error.h>
#include <stdio.h>

#define DEPTH_LV1	128
#define DEPTH_LV2	128
#define DEPTH_LV3	128

const drv::Gpio::Pin gDetectPin = {&gpioC, 13};
bool gSdmmcAbleFlag;
int gThreadId, gNum1, gNum2, gNum3;
Fat32 gFat32(sdmmc);

void makeSubDirectory2(unsigned short num1, unsigned short num2, char *nameBuf)
{
	error result;

	gFat32.moveToStart();
	gNum1 = num1;
	gNum2 = num2;
	for(int i=0;i<DEPTH_LV3;i++)
	{
		gNum3 = i;
		sprintf(nameBuf, "%d의 %d번 폴더내에 한글 서브 폴더 생성 테스트 %05d",num1, num2, i);
		result = gFat32.makeDirectory(nameBuf);
		if(result == Error::NONE)
		{
//			debug_printf("\"%s\" 폴더 생성 완료                     \n", nameBuf);
		}
		else
			debug_printf("\"%s\" 폴더 생성 실패[%d]                    \n", nameBuf, result);
	}
}

void makeSubDirectory1(unsigned short num, char *nameBuf)
{
	error result;

	gFat32.moveToStart();
	gNum1 = num;

	for(int i=0;i<DEPTH_LV2;i++)
	{
		gNum2 = i;
		sprintf(nameBuf, "%d번 폴더내에 한글 서브 폴더 생성 테스트 %05d",num, i);
		result = gFat32.makeDirectory(nameBuf);
		if(result == Error::NONE)
		{
//			debug_printf("\"%s\" 폴더 생성 완료                   \n", nameBuf);
		}
		else
			debug_printf("\"%s\" 폴더 생성 실패[%d]                    \n", nameBuf, result);
	}
}

void makeRootDirectory(char *nameBuf)
{
	error result;

	gFat32.moveToRoot();

	for(int i=0;i<DEPTH_LV1;i++)
	{
		gNum1 = i;
		sprintf(nameBuf, "한글 루트 폴더 생성 테스트 %05d", i);
		result = gFat32.makeDirectory(nameBuf);
		if(result == Error::NONE)
		{
//			debug_printf("\"%s\" 폴더 생성 완료         \n", nameBuf);
		}
		else
			debug_printf("\"%s\" 폴더 생성 실패[%d]        \n", nameBuf, result);
	}
}

void displayRootDirectoryList(char *nameBuf)
{
	int rootDirectoryCount;

	gFat32.moveToRoot();
	rootDirectoryCount = gFat32.getDirectoryCount();

	for(int i=0;i<rootDirectoryCount;i++)
	{
		gFat32.moveToNextDirectory();
		if(gFat32.getName(nameBuf, 512) == Error::NONE)
			debug_printf("[%05d]%s                      \n", i, nameBuf);
		else
			continue;
	}
}

void isr_detectSdMemory(bool detect)
{
	error result;
	char *name = new char[512];
	int fileCount, directoryCount, rootDirectoryCount;

	if(detect)
	{
		gFat32.lock();

		result = gFat32.init();
		if(result == Error::NONE)
		{
			debug_printf("SD memory detected!!\n");
			
			// 루트 폴더의 폴더 리스트 출력
			displayRootDirectoryList(name);

			// 루트 디렉토리에 폴더 생성
			makeRootDirectory(name);
			
			for(int i=0;i<DEPTH_LV1;i++)
			{
				gFat32.moveToRoot();
				if(!gFat32.isDirectory())
					gFat32.moveToNextDirectory();

				for(int j=0;j<i;j++)
					gFat32.moveToNextDirectory();
				
				gFat32.enterDirectory();
				makeSubDirectory1(i, name);
				gFat32.returnDirectory();
			}
			
			for(int i=0;i<DEPTH_LV2;i++)
			{
				gFat32.moveToRoot();
				if(!gFat32.isDirectory())
					gFat32.moveToNextDirectory();

				for(int j=0;j<i;j++)
					gFat32.moveToNextDirectory();
				
				gFat32.enterDirectory();
				
				for(int j=0;j<DEPTH_LV3;j++)
				{
					gFat32.moveToNextDirectory(); // '.' 디렉토리
					gFat32.moveToNextDirectory(); // '..' 디렉토리
					for(int k=0;k<j;k++)
						gFat32.moveToNextDirectory();

					gFat32.enterDirectory();
					makeSubDirectory2(i, j, name);
					gFat32.returnDirectory();
				}
				gFat32.returnDirectory();
			}

			//// 루트 폴더에 "한글 폴더 생성 테스트 0000x"로 폴더 256개 생성
			//for(int k=0;k<rootDirectoryCount;k++)
			//{
			//	gFat32.moveToRoot();

			//	if(!gFat32.isDirectory())
			//		gFat32.moveToNextDirectory();

			//	for(int j=0;j<k;j++)
			//		gFat32.moveToNextDirectory();
			//	gFat32.enterDirectory();

			//	for(int i=0;i<256;i++)
			//	{
			//		sprintf(name, "한글 하위 폴더 생성 테스트 %05d", i);
			//		result = gFat32.makeDirectory(name);
			//		if(result == Error::NONE)
			//		{
			//			debug_printf("\"%s\" 폴더 생성 완료         \n", name);
			//		}
			//		else
			//			debug_printf("\"%s\" 폴더 생성 실패[%d]        \n", name, result);
			//	}

			//	gFat32.returnDirectory();
			//}
		}
		else
		{
			debug_printf("SD memory error!!\n");
		}

		gFat32.unlock();
	}
	else
	{
		debug_printf("SD memory removed!!\n");
	}

	delete name;
}

extern "C"
{
	void HardFault_Handler(void)
	{
		return;
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
	sdmmc.setDetectionIsr(isr_detectSdMemory);
	sdmmc.start();

	while(1)
	{
		thread::yield();
	}
	return 0;
}

