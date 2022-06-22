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

#ifndef YSS_DRV_SPI__H_
#define YSS_DRV_SPI__H_

#include "mcu.h"

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32L0) || defined(GD32F1)

typedef SPI_TypeDef		YSS_SPI_Peri;

#elif defined(GD32F450)

typedef unsigned int	YSS_SPI_Peri;

#else

#define YSS_DRV_SPI_UNSUPPORTED

#endif

#ifndef YSS_DRV_SPI_UNSUPPORTED

#include "spi/drv_spi_common.h"

#include <drv/Drv.h>
#include <drv/Dma.h>
#include <sac/Comm.h>

namespace drv
{
class Spi : public Drv
{
  public:
	struct Config
	{
		YSS_SPI_Peri *peri;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
		Dma &rxDma;
		Dma::DmaInfo rxDmaInfo;
		unsigned int (*getClockFreq)(void);
	};

	struct Specification
	{
		unsigned char mode;
		unsigned int maxFreq;
		unsigned char bit;
	};

	Spi(const Drv::Config drvConfig, const Config config);
	bool init(void);
	bool setSpecification(const Specification &spec);
	bool send(void *src, unsigned int size, unsigned int timeout = 1000);
	unsigned char exchange(unsigned char data);
	bool exchange(void *des, unsigned int size, unsigned int timeout = 1000);
	void send(char data);
	void send(unsigned char data);
	void enable(bool en);

  private:
	YSS_SPI_Peri *mPeri;
	Dma *mTxDma, *mRxDma;
	Dma::DmaInfo mTxDmaInfo, mRxDmaInfo;
	const Specification *mLastSpec;
	unsigned int (*mGetClockFreq)(void);

};
}

#endif

#endif
