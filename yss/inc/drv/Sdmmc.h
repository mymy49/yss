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

#ifndef YSS_DRV_SDMMC__H_
#define YSS_DRV_SDMMC__H_

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F7)

typedef SDMMC_TypeDef	YSS_SDMMC_Peri;

#else

#define YSS_DRV_SDMMC_UNSUPPORTED

#endif

#ifndef YSS_DRV_SDMMC_UNSUPPORTED



//#include "sdmmc/config_sdmmc_stm32f7.h"
//#include "sdmmc/define_sdmmc_stm32f7.h"
//#include "sdmmc/register_sdmmc_stm32f7.h"
#include <drv/Drv.h>
#include <drv/Gpio.h>
//#include <yss/thread.h>
#include <sac/Comm.h>
#include <drv/Dma.h>

namespace drv
{
class Sdmmc : public sac::Comm, public Drv
{
	//bool mAbleFlag, mHcsFlag;
	//float mVcc;
	//unsigned int mRca;
	//config::gpio::Set mDetectSet;
	//signed int mThreadId;
	//Stream *mStream;
	//YSS_SDMMC_Peri mPeri;

	//bool sendCmd(unsigned char cmd, unsigned long arg);
	//bool sendAcmd(unsigned char cmd, unsigned long arg);

 // public:
	//struct Config
	//{
	//	YSS_SDMMC_Peri *peri;
	//	unsigned char channel;
	//	unsigned short priority;
	//	Stream *stream;
	//	float vcc;						// MCU의	전원 전압
	//	config::gpio::Set detect;		// Detect 포트 셋
	//};

	//Sdmmc(const Drv::Config &drvConfig, const Config &config);

	//bool init(const Drv::Config &drvConfig, const Config config);
	//bool isDetected(void);
	//bool isAble(void);
	//void setAble(bool able);
	//bool connect(void);
	//unsigned char getStatus(void);
};
}

#endif

#endif

