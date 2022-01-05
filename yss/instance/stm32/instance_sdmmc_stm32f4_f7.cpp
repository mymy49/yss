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
// 주담당자 : 아이구 (mymy49@nate.com) 2021.03.05 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(SDMMC_ENABLE) & defined(SDMMC1)
static void setClockEn(bool en)
{
	clock.peripheral.setSdmmcEn(en);
}

static void setInterruptEn(bool en)
{
//	nvic.setSd(en);
}

static void reset(void)
{
	clock.peripheral.resetSdmmc();
}

static const Drv::Config gDrvConfig
{
	setClockEn,		//void (*clockFunc)(bool en);
	setInterruptEn,	//void (*nvicFunc)(bool en);
	reset			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gDmaInfo = 
{
	define::dma2::stream3::SDIO_DMA,	//unsigned char channelNumber;
	(void*)&SDMMC1->FIFO,				//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::WORD,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Sdmmc::Config gConfig
{
	SDMMC1,			//YSS_SDMMC_Peri *peri;
	dmaChannel12,	//Dma &txDma;
	gDmaInfo		//Dma::DmaInfo txDmaInfo;
};

drv::Sdmmc sdmmc(gDrvConfig, gConfig);
#endif
