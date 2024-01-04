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

#include <drv/mcu.h>

#if defined(STM32F7)

#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Quadspi.h>
#include <targets/st/bitfield.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <util/Timeout.h>

#define FMODE_INDIRECT_WRITE	0
#define FMODE_INDIRECT_READ		1
#define FMODE_AUTO_POLLING		2
#define FMODE_MEMEORY_MAPPED	3

Quadspi::Quadspi(const Drv::Setup_t drvSetup, const Setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDma = &setup.txDma;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDma = &setup.rxDma;
	mRxDmaInfo = setup.rxDmaInfo;
	mSpec = 0;
	mCcr = 0;
	mWaveform = 0;
}

error Quadspi::initialize(void)
{
	setBitData(mDev->CR, true, QUADSPI_CR_DMAEN_Pos);
	setBitData(mDev->CR, true, QUADSPI_CR_APMS_Pos);
	
	return error::ERROR_NONE;
}

error Quadspi::setSpecification(const Specification_t &spec)
{
	// 장치가 활성화되어 있으면 에러
	if(getBitData(mDev->CR, QUADSPI_CR_EN_Pos))
		return error::BUSY;
	
	// 이전 사양과 같으면 바꿀 필요 없음
	if(mSpec == &spec)
		return error::ERROR_NONE;

	uint32_t prescaler = getClockFrequency() / spec.maxFrequncy;
	if(prescaler > 255)
		return error::WRONG_CLOCK_FREQUENCY;

	setFieldData(mDev->CR, QUADSPI_CR_PRESCALER_Msk, prescaler, QUADSPI_CR_PRESCALER_Pos);
	setBitData(mDev->CR, spec.sampleShift, QUADSPI_CR_SSHIFT_Pos);
	setFieldData(mDev->DCR, QUADSPI_DCR_FSIZE_Msk, spec.flashSize, QUADSPI_DCR_FSIZE_Pos);
	setFieldData(mDev->DCR, QUADSPI_DCR_CSHT_Msk, spec.chipSelectHighTime, QUADSPI_DCR_CSHT_Pos);
	setBitData(mDev->DCR, spec.clockMode, QUADSPI_DCR_CKMODE_Pos);
	
	mSpec = &spec;

	return error::ERROR_NONE;
}

error Quadspi::setWaveform(const Waveform_t &waveform)
{
	if(&waveform != mWaveform)
	{
		mWaveform = &waveform;
		mCcr =	(waveform.instructionMode << QUADSPI_CCR_IMODE_Pos) |
				(waveform.dummyCycle << QUADSPI_CCR_DCYC_Pos) |
				(waveform.addressSize << QUADSPI_CCR_ADSIZE_Pos) |
				(waveform.addressMode << QUADSPI_CCR_ADMODE_Pos) |
				(waveform.alternateByteSize << QUADSPI_CCR_ABMODE_Pos) |
				(waveform.alternateByteMode << QUADSPI_CCR_ABSIZE_Pos) |
				(waveform.statusSendInstructionOnlyOnce << QUADSPI_CCR_SIOO_Pos) |
				(waveform.dataMode << QUADSPI_CCR_DMODE_Pos);
	}

	return error::ERROR_NONE;
}

error Quadspi::setBank(uint8_t bank)
{
	// 장치가 활성화되어 있으면 에러
	if(getBitData(mDev->CR, QUADSPI_CR_EN_Pos))
		return error::BUSY;
	
	setBitData(mDev->CR, (bool)bank, QUADSPI_CR_FSEL_Pos);
}

error Quadspi::readRegister(uint8_t cmd, void *des, uint32_t size, uint32_t timeout)
{
	error result;

	if(mRxDma == 0)
		return error::DMA;

	if(size == 0)
		return error::ERROR_NONE;

	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;
		mDev->DLR = size - 1;
		mDev->CCR =	(FMODE_INDIRECT_READ << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_DMODE_Msk ) ) |
						cmd;
		
		result = mRxDma->transfer(mRxDmaInfo, des, size);
		if(result != error::ERROR_NONE)
			return result;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
			thread::yield();

		return error::ERROR_NONE;
	}
	else
		return error::WRONG_CONFIG;
}

error Quadspi::writeCommand(unsigned char cmd)
{
	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;

		mDev->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & QUADSPI_CCR_IMODE_Msk) |
						cmd;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
			thread::yield();

		return error::ERROR_NONE;
	}
	else
		return error::WRONG_CONFIG;
}

error Quadspi::wait(uint8_t cmd, uint32_t mask, uint32_t status, uint8_t size, uint8_t pollingMatchMode, uint32_t timeOut)
{
	Timeout timeout(timeOut);

	if(size == 0 || size >= 4)
		return error::WRONG_SIZE;

	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;
		mDev->DLR = size - 1;
		mDev->PSMKR = mask;
		mDev->PSMAR = status;
		setBitData(mDev->CR, (bool)pollingMatchMode, QUADSPI_CR_PMM_Pos);
		
		mDev->CCR =	(FMODE_AUTO_POLLING << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & ( QUADSPI_CCR_SIOO_Msk  | QUADSPI_CCR_DMODE_Msk | QUADSPI_CCR_IMODE_Msk) ) |
						cmd;

		while(!getBitData(mDev->SR, QUADSPI_SR_SMF_Pos) && timeout.isTimeout())
			thread::yield();

		if(getBitData(mDev->SR, QUADSPI_SR_SMF_Pos))
			return error::ERROR_NONE;
		else
		{
			enable(false);
			enable(true);
			return error::TIMEOUT;
		}
	}
	else
		return error::WRONG_CONFIG;
}

error Quadspi::writeAddress(uint8_t cmd, uint32_t addr)
{
	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;
		mDev->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk) ) |
						cmd;
		mDev->AR = addr;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
			thread::yield();

		return error::ERROR_NONE;
	}
	else
		return error::WRONG_CONFIG;
}

error Quadspi::write(uint8_t cmd, uint32_t addr, void *src, uint32_t size, uint32_t timeout)
{
	error result;

	if(mTxDma == 0)
		return error::DMA;

	if(size == 0)
		return error::ERROR_NONE;

	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;
		mDev->DLR = size - 1;
		mDev->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk | QUADSPI_CCR_DMODE_Msk | QUADSPI_CCR_ABMODE_Msk  | QUADSPI_CCR_ABSIZE_Msk) ) |
						cmd;
		mDev->AR = addr;

		result = mTxDma->transfer(mTxDmaInfo, src, size);
		if(result != error::ERROR_NONE)
			return result;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
			thread::yield();

		return error::ERROR_NONE;
	}
	else
		return error::WRONG_CONFIG;
}

error Quadspi::read(uint8_t cmd, uint32_t addr, void *des, uint32_t size, uint32_t timeout)
{
	error result;

	if(mRxDma == 0)
		return error::DMA;

	if(size == 0)
		return error::ERROR_NONE;

	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;
		mDev->DLR = size - 1;
		mDev->CCR =	(FMODE_INDIRECT_READ << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk | QUADSPI_CCR_DMODE_Msk | QUADSPI_CCR_ABMODE_Msk  | QUADSPI_CCR_ABSIZE_Msk | QUADSPI_CCR_DCYC_Msk) ) |
						cmd;
		mDev->AR = addr;

		result = mTxDma->transfer(mTxDmaInfo, des, size);
		if(result != error::ERROR_NONE)
			return result;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
			thread::yield();

		return error::ERROR_NONE;
	}
	else
		return error::WRONG_CONFIG;
}

void Quadspi::enable(bool en)
{
	setBitData(mDev->CR, en, QUADSPI_CR_EN_Pos);
}

#endif

