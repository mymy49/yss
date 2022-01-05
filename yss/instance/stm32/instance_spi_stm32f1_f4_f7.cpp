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
// 주담당자 : 아이구 (mymy49@nate.com) 2021.03.10 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>
#include <yss/instance.h>
#include <config.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)

static unsigned int getApb2ClkFreq(void)
{
	return clock.getApb2ClkFreq();
}

static unsigned int getApb1ClkFreq(void)
{
	return clock.getApb1ClkFreq();
}

#if defined(SPI1_ENABLE) && defined(SPI1)
static void setSpi1ClockEn(bool en)
{
	clock.peripheral.setSpi1En(en);
}

static void resetSpi1(void)
{
	clock.peripheral.resetSpi1();
}

static const Drv::Config gDrvSpi1Config
{
	setSpi1ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi1			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi1TxDmaInfo = 
{
	define::dma2::stream3::SPI1_TX,		//unsigned char channelNumber;
	(void*)&SPI1->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Dma::DmaInfo gSpi1RxDmaInfo = 
{
	define::dma2::stream0::SPI1_RX,		//unsigned char channelNumber;
	(void*)&SPI1->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Spi::Config gSpi1Config
{
	SPI1,			//YSS_SPI_Peri *peri;
	dmaChannel12,	//Dma &txDma;
	gSpi1TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel9,	//Dma &rxDma;
	gSpi1RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb2ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi1(gDrvSpi1Config, gSpi1Config);
#endif



#if defined(SPI2_ENABLE) && defined(SPI2)
static void setSpi2ClockEn(bool en)
{
	clock.peripheral.setSpi2En(en);
}

static void resetSpi2(void)
{
	clock.peripheral.resetSpi2();
}

static const Drv::Config gDrvSpi2Config
{
	setSpi2ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi2			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi2TxDmaInfo = 
{
	define::dma1::stream4::SPI2_TX,		//unsigned char channelNumber;
	(void*)&SPI2->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Dma::DmaInfo gSpi2RxDmaInfo = 
{
	define::dma1::stream3::SPI2_RX,		//unsigned char channelNumber;
	(void*)&SPI2->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Spi::Config gSpi2Config
{
	SPI2,			//YSS_SPI_Peri *peri;
	dmaChannel5,	//Dma &txDma;
	gSpi2TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel4,	//Dma &rxDma;
	gSpi2RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb1ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi2(gDrvSpi2Config, gSpi2Config);
#endif



#if defined(SPI3_ENABLE) && defined(SPI3)
static void setSpi3ClockEn(bool en)
{
	clock.peripheral.setSpi3En(en);
}

static void resetSpi3(void)
{
	clock.peripheral.resetSpi3();
}

static const Drv::Config gDrvSpi3Config
{
	setSpi3ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi3			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi3TxDmaInfo = 
{
	define::dma1::stream5::SPI3_TX,		//unsigned char channelNumber;
	(void*)&SPI3->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Dma::DmaInfo gSpi3RxDmaInfo = 
{
	define::dma1::stream0::SPI3_RX,		//unsigned char channelNumber;
	(void*)&SPI3->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Spi::Config gSpi3Config
{
	SPI3,			//YSS_SPI_Peri *peri;
	dmaChannel6,	//Dma &txDma;
	gSpi3TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel1,	//Dma &rxDma;
	gSpi3RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb1ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi3(gDrvSpi3Config, gSpi3Config);
#endif



#if defined(SPI4_ENABLE) && defined(SPI4)
static void setSpi4ClockEn(bool en)
{
	clock.peripheral.setSpi4En(en);
}

static void resetSpi4(void)
{
	clock.peripheral.resetSpi4();
}

static const Drv::Config gDrvSpi4Config
{
	setSpi4ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi4			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi4TxDmaInfo = 
{
	define::dma2::stream1::SPI4_TX,		//unsigned char channelNumber;
	(void*)&SPI4->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Dma::DmaInfo gSpi4RxDmaInfo = 
{
	define::dma2::stream0::SPI4_RX,		//unsigned char channelNumber;
	(void*)&SPI4->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Spi::Config gSpi4Config
{
	SPI4,			//YSS_SPI_Peri *peri;
	dmaChannel10,	//Dma &txDma;
	gSpi4TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel9,	//Dma &rxDma;
	gSpi4RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb2ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi4(gDrvSpi4Config, gSpi4Config);
#endif



#if defined(SPI5_ENABLE) && defined(SPI5)
static void setSpi5ClockEn(bool en)
{
	clock.peripheral.setSpi5En(en);
}

static void resetSpi5(void)
{
	clock.peripheral.resetSpi5();
}

static const Drv::Config gDrvSpi5Config
{
	setSpi5ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi5			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi5TxDmaInfo = 
{
	define::dma2::stream4::SPI5_TX,		//unsigned char channelNumber;
	(void*)&SPI5->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Dma::DmaInfo gSpi5RxDmaInfo = 
{
	define::dma2::stream3::SPI5_RX,		//unsigned char channelNumber;
	(void*)&SPI5->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Spi::Config gSpi5Config
{
	SPI5,			//YSS_SPI_Peri *peri;
	dmaChannel13,	//Dma &txDma;
	gSpi5TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel12,	//Dma &rxDma;
	gSpi5RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb2ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi5(gDrvSpi5Config, gSpi5Config);
#endif



#if defined(SPI6_ENABLE) && defined(SPI6)
static void setSpi6ClockEn(bool en)
{
	clock.peripheral.setSpi6En(en);
}

static void resetSpi6(void)
{
	clock.peripheral.resetSpi6();
}

static const Drv::Config gDrvSpi6Config
{
	setSpi6ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi6			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi6TxDmaInfo = 
{
	define::dma2::stream5::SPI6_TX,		//unsigned char channelNumber;
	(void*)&SPI6->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Dma::DmaInfo gSpi6RxDmaInfo = 
{
	define::dma2::stream6::SPI6_RX,		//unsigned char channelNumber;
	(void*)&SPI6->DR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Spi::Config gSpi6Config
{
	SPI6,			//YSS_SPI_Peri *peri;
	dmaChannel14,	//Dma &txDma;
	gSpi6TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel15,	//Dma &rxDma;
	gSpi6RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb2ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi6(gDrvSpi6Config, gSpi6Config);
#endif

#endif

