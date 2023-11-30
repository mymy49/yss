////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_QUADSPI__H_
#define YSS_DRV_QUADSPI__H_

#include "peripheral.h"

#if defined(STM32F7)

typedef QUADSPI_TypeDef		YSS_QUADSPI_Peri;

#else

#define YSS_DRV_QUADSPI_UNSUPPORTED

#endif

#ifndef YSS_DRV_QUADSPI_UNSUPPORTED

#include "quadspi/config_quadspi_common.h"
#include "Drv.h"
#include <drv/Dma.h>
#include <sac/QuadspiFlash.h>

class Quadspi : public Drv
{
public :
	struct Specification_t
	{
		uint32_t maxFrequncy;
		uint8_t flashSize;
		uint8_t chipSelectHighTime;
		bool sampleShift;
		bool clockMode;
	};

	//Quadspi(YSS_QUADSPI_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *stream, uint8_t channel, uint16_t priority);
	error initialize(void);
	//void setWaveform(config::quadspi::Waveform &waveform);
	//bool writeCommand(uint8_t cmd);
	//bool readRegister(uint8_t cmd, void *des, uint32_t size, uint32_t timeout);
	//bool writeRegister(uint8_t cmd, void *src, uint32_t size, uint32_t timeout);
	//bool writeAddress(uint8_t cmd, uint32_t addr);
	//bool write(uint8_t cmd, uint32_t addr, void *src, uint32_t size, uint32_t timeout);
	//bool read(uint8_t cmd, uint32_t addr, void *des, uint32_t size, uint32_t timeout);
	//bool wait(uint8_t cmd, uint32_t mask, uint32_t status, uint8_t size, bool pollingMatchMode, uint32_t timeOut);
	//void lock(void);
	//void unlock(void);

	struct Setup
	{
		YSS_QUADSPI_Peri *dev;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
		Dma &rxDma;
		Dma::DmaInfo rxDmaInfo;
	};

	Quadspi(const Drv::Setup drvSetup, const Setup setup);

private :
	YSS_QUADSPI_Peri *mDev;
	Dma *mTxDma, *mRxDma;
	Dma::DmaInfo mTxDmaInfo, mRxDmaInfo;
	//uint32_t mCcr;
	//uint8_t mFlash;
	//config::quadspi::Config *mConfig;
	//config::quadspi::Waveform *mLastWaveform;
	//Stream *mStream;
};

#endif

#endif

