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

/*
#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx)

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
	Quadspi::Quadspi(QUADSPI_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *stream, uint8_t channel, uint16_t priority) :  Drv(clockFunc, nvicFunc)
	{
		this->set(channel, (void*)&(QUADSPI->DR), priority);

		mStream = stream;
		mLastWaveform = 0;
		mConfig = 0;
	}

	bool Quadspi::init(sac::QuadspiFlash &memory, uint8_t flash)
	{
		config::quadspi::Config *config = memory.getConfig();
		uint32_t prescaler = clock.getSysClkFreq() / config->maxFrequncy;

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

	bool Quadspi::writeCommand(uint8_t cmd)
	{
		if(mLastWaveform && mConfig)
		{
			clearQuadspiTransferCompleteFlag();

			QUADSPI->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & QUADSPI_CCR_IMODE_Msk) |
							cmd;

			while(getQuadspiBusyFlag())
				thread::yield();

			return true;
		}
		else
			return false;
	}

	bool Quadspi::readRegister(uint8_t cmd, void *des, uint32_t size, uint32_t timeout)
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

			if(!mStream->receive(this, (int8_t*)des, size, timeout))
				return false;

			while(getQuadspiBusyFlag())
				thread::yield();

			return true;
		}
		else
			return false;
	}

	bool Quadspi::writeRegister(uint8_t cmd, void *src, uint32_t size, uint32_t timeout)
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

			if(!mStream->send(this, (int8_t*)src, size, timeout))
				return false;

			while(getQuadspiBusyFlag())
				thread::yield();

			return true;
		}
		else
			return false;
	}

	bool Quadspi::writeAddress(uint8_t cmd, uint32_t addr)
	{
		if(mLastWaveform && mConfig)
		{
			clearQuadspiTransferCompleteFlag();

			QUADSPI->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
							(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk) ) |
							cmd;

			setQuadspiAddress(addr);

			while(getQuadspiBusyFlag())
				thread::yield();
		}
		else
			return false;

		return true;
	}

	bool Quadspi::write(uint8_t cmd, uint32_t addr, void *src, uint32_t size, uint32_t timeout)
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
			if(!mStream->send(this, (int8_t*)src, size, timeout))
				return false;

			while(getQuadspiBusyFlag())
				thread::yield();

			return true;
		}
		else
			return false;
	}

	bool Quadspi::read(uint8_t cmd, uint32_t addr, void *des, uint32_t size, uint32_t timeout)
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
			if(!mStream->receive(this, (int8_t*)des, size, timeout))
				return false;

			while(getQuadspiBusyFlag())
				thread::yield();

			return true;
		}

		return false;
	}

	bool Quadspi::wait(uint8_t cmd, uint32_t mask, uint32_t status, uint8_t size, bool pollingMatchMode, uint32_t timeOut)
	{
		uint64_t endTime;

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
				thread::yield();
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