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

#ifndef YSS_DRV_QUADSPI__H_
#define YSS_DRV_QUADSPI__H_

#include <drv/peripheral.h>

#if defined(QUADSPI)

#if defined(STM32F7)
#include "quadspi/config_quadspi_stm32f7.h"
#include "quadspi/define_quadspi_stm32f7.h"
#endif

#include "quadspi/config_quadspi_common.h"
#include <drv/Drv.h>
#include <drv/Dma.h>
#include <sac/Comm.h>
#include <sac/QuadspiFlash.h>

class Stream;

namespace drv
{
class Quadspi : public sac::Comm, public Drv
{
	unsigned long mCcr;
	unsigned char mFlash;
	config::quadspi::Config *mConfig;
	config::quadspi::Waveform *mLastWaveform;
	Stream *mStream;

  public:
	Quadspi(QUADSPI_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *stream, unsigned char channel, unsigned short priority);
	bool init(sac::QuadspiFlash &memory, unsigned char flash);
	void setWaveform(config::quadspi::Waveform &waveform);
	bool writeCommand(unsigned char cmd);
	bool readRegister(unsigned char cmd, void *des, unsigned long size, unsigned long timeout);
	bool writeRegister(unsigned char cmd, void *src, unsigned long size, unsigned long timeout);
	bool writeAddress(unsigned char cmd, unsigned long addr);
	bool write(unsigned char cmd, unsigned long addr, void *src, unsigned long size, unsigned long timeout);
	bool read(unsigned char cmd, unsigned long addr, void *des, unsigned long size, unsigned long timeout);
	bool wait(unsigned char cmd, unsigned long mask, unsigned long status, unsigned char size, bool pollingMatchMode, unsigned long timeOut);
	void lock(void);
	void unlock(void);
};
}

#else

#define YSS_NOT_HAVE_QUADSPI

#endif

#endif
