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

/*
#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx)

#include <__cross_studio_io.h>

#include <config.h>
#include <util/time.h>
#include <drv/peripherals.h>

#define DDRM		31
#define DHHC		30
#define SIOO		28
#define FMODE		26
#define DMODE		24
#define DCYC		18
#define ABSIZE		16
#define ABMODE		14
#define ADSIZE		12
#define ADMODE		10
#define IMODE		8

#define FMODE_INDIRECT_WRITE	0
#define FMODE_INDIRECT_READ		1
#define FMODE_AUTO_POLLING		2
#define FMODE_MEMEORY_MAPPED	3

#if defined(QUADSPI_ENABLE), defined(QUADSPI)
static void setClockEn(bool en)
{
	clock.peripheral.setQuadspi(en);
} 

drv::Quadspi quadspi(QUADSPI, setClockEn, 0,YSS_DMA_MAP_QUADSPI_STREAM, YSS_DMA_MAP_QUADSPI_CHANNEL, define::dma::priorityLevel::LOW);
#endif

namespace drv
{
	Quadspi::Quadspi(QUADSPI_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *stream, unsigned char channel, unsigned short priority) :  Drv(clockFunc, nvicFunc)
	{
		this->set(channel, (void*)&(QUADSPI->DR), priority);

		mStream = stream;
		mLastWaveform = 0;
		mConfig = 0;
	}

	bool Quadspi::init(sac::QuadspiFlash &memory, unsigned char flash)
	{
		config::quadspi::Config *config = memory.getConfig();
		unsigned long prescaler = clock.getSysClkFreq() / config->maxFrequncy;

		mConfig = config;
		mFlash = flash;

		if(prescaler > 255)
			return false;

		setQuadspiEn(false);
		setQuadspiPrescaler(prescaler);
		setQuadspiSampleShift(config->sampleShift);
		setQuadspiFlashMemorySize(config->flashSize);
		setQuadspiChipSelectHighTime(config->chipSelectHighTime);
		setQuadspiClockMode(config->clockMode);
		setQuadspiFlashMemorySelect(flash);
		setQuadspiEn(true);

		setQuadspiDmaEn(true);
		setQuadspiAutomaticPollModeStop(true);

		return true;
	}


	void Quadspi::setWaveform(config::quadspi::Waveform &waveform)
	{
		if(&waveform != mLastWaveform)
		{
			mLastWaveform = &waveform;
			mCcr =	(waveform.instructionMode << QUADSPI_CCR_IMODE_Pos) |
					(waveform.dummyCycle << QUADSPI_CCR_DCYC_Pos) |
					(waveform.addressSize << QUADSPI_CCR_ADSIZE_Pos) |
					(waveform.addressMode << QUADSPI_CCR_ADMODE_Pos) |
					(waveform.alternateByteSize << QUADSPI_CCR_ABMODE_Pos) |
					(waveform.alternateByteMode << QUADSPI_CCR_ABSIZE_Pos) |
					(waveform.statusSendInstructionOnlyOnce << QUADSPI_CCR_SIOO_Pos) |
					(waveform.dataMode << QUADSPI_CCR_DMODE_Pos);
		}
	}

	bool Quadspi::writeCommand(unsigned char cmd)
	{
		if(mLastWaveform && mConfig)
		{
			clearQuadspiTransferCompleteFlag();

			QUADSPI->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & QUADSPI_CCR_IMODE_Msk) |
							cmd;

			while(getQuadspiBusyFlag())
				thread::switchContext();

			return true;
		}
		else
			return false;
	}

	bool Quadspi::readRegister(unsigned char cmd, void *des, unsigned long size, unsigned long timeout)
	{
		if(mStream == 0)
			return false;

		if(size == 0)
			return false;

		if(mLastWaveform && mConfig)
		{
			clearQuadspiTransferCompleteFlag();
			setQuadspiDataLength(size-1);

			QUADSPI->CCR =	(FMODE_INDIRECT_READ << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_DMODE_Msk ) ) |
							cmd;

			if(!mStream->receive(this, (char*)des, size, timeout))
				return false;

			while(getQuadspiBusyFlag())
				thread::switchContext();

			return true;
		}
		else
			return false;
	}

	bool Quadspi::writeRegister(unsigned char cmd, void *src, unsigned long size, unsigned long timeout)
	{
		if(mStream == 0)
			return false;

		if(size == 0)
			return false;

		if(mLastWaveform && mConfig)
		{
			clearQuadspiTransferCompleteFlag();
			setQuadspiDataLength(size-1);

			QUADSPI->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_DMODE_Msk ) ) |
							cmd;

			if(!mStream->send(this, (char*)src, size, timeout))
				return false;

			while(getQuadspiBusyFlag())
				thread::switchContext();

			return true;
		}
		else
			return false;
	}

	bool Quadspi::writeAddress(unsigned char cmd, unsigned long addr)
	{
		if(mLastWaveform && mConfig)
		{
			clearQuadspiTransferCompleteFlag();

			QUADSPI->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk) ) |
							cmd;

			setQuadspiAddress(addr);

			while(getQuadspiBusyFlag())
				thread::switchContext();
		}
		else
			return false;

		return true;
	}

	bool Quadspi::write(unsigned char cmd, unsigned long addr, void *src, unsigned long size, unsigned long timeout)
	{
		if(mStream == 0)
			return false;

		if(size == 0)
			return false;

		if(mLastWaveform && mConfig)
		{
			clearQuadspiTransferCompleteFlag();

			setQuadspiDataLength(size-1);
			QUADSPI->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk | QUADSPI_CCR_DMODE_Msk | QUADSPI_CCR_ABMODE_Msk  | QUADSPI_CCR_ABSIZE_Msk) ) |
							cmd;

			setQuadspiAddress(addr);
			if(!mStream->send(this, (char*)src, size, timeout))
				return false;

			while(getQuadspiBusyFlag())
				thread::switchContext();

			return true;
		}
		else
			return false;
	}

	bool Quadspi::read(unsigned char cmd, unsigned long addr, void *des, unsigned long size, unsigned long timeout)
	{
		if(mStream == 0)
			return false;

		if(size == 0)
			return false;

		if(mLastWaveform && mConfig)
		{
			clearQuadspiTransferCompleteFlag();

			setQuadspiDataLength(size-1);

			QUADSPI->CCR =	(FMODE_INDIRECT_READ << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk | QUADSPI_CCR_DMODE_Msk | QUADSPI_CCR_ABMODE_Msk  | QUADSPI_CCR_ABSIZE_Msk | QUADSPI_CCR_DCYC_Msk) ) |
							cmd;

			setQuadspiAddress(addr);
			if(!mStream->receive(this, (char*)des, size, timeout))
				return false;

			while(getQuadspiBusyFlag())
				thread::switchContext();

			return true;
		}

		return false;
	}

	bool Quadspi::wait(unsigned char cmd, unsigned long mask, unsigned long status, unsigned char size, bool pollingMatchMode, unsigned long timeOut)
	{
		unsigned long long endTime;

		if(size == 0 || size >= 4)
			return false;

		if(mLastWaveform && mConfig)
		{
			clearQuadspiStatusMatchFlag();
			clearQuadspiTransferCompleteFlag();

			setQuadspiDataLength(size-1);
			setQuadspiPollingStatusMaskValue(mask);
			setQuadspiPollingStatusMatchValue(status);
			setQuadspiPollingMatchMode(pollingMatchMode);

			QUADSPI->CCR =	(FMODE_AUTO_POLLING << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & ( QUADSPI_CCR_SIOO_Msk  | QUADSPI_CCR_DMODE_Msk | QUADSPI_CCR_IMODE_Msk) ) |
							cmd;

			endTime = time::getRunningMsec()+timeOut;
			while(!getQuadspiStatusMatchFlag() && endTime >= time::getRunningMsec())
			{
				thread::switchContext();
			}

			if(getQuadspiStatusMatchFlag())
				return true;
			else
			{
				setQuadspiEn(false);
				setQuadspiEn(true);
				return false;
			}
		}
		else
			return false;
	}

	void Quadspi::lock(void)
	{
		Comm::lock();
	}

	void Quadspi::unlock(void)
	{
		Comm::unlock();
	}
}

#endif
*/