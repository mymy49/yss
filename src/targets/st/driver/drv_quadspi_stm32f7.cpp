/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

Quadspi::Quadspi(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
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

error_t Quadspi::initialize(void)
{
	setBitData(mDev->CR, true, QUADSPI_CR_DMAEN_Pos);
	setBitData(mDev->CR, true, QUADSPI_CR_APMS_Pos);
	
	return error_t::ERROR_NONE;
}

error_t Quadspi::setSpecification(const specification_t &spec)
{
	// 장치가 활성화되어 있으면 에러
	if(getBitData(mDev->CR, QUADSPI_CR_EN_Pos))
		return error_t::BUSY;
	
	// 이전 사양과 같으면 바꿀 필요 없음
	if(mSpec == &spec)
		return error_t::ERROR_NONE;

	uint32_t prescaler = getClockFrequency() / spec.maxFrequncy;
	if(prescaler > 255)
		return error_t::WRONG_CLOCK_FREQUENCY;

	setFieldData(mDev->CR, QUADSPI_CR_PRESCALER_Msk, prescaler, QUADSPI_CR_PRESCALER_Pos);
	setBitData(mDev->CR, spec.sampleShift, QUADSPI_CR_SSHIFT_Pos);
	setFieldData(mDev->DCR, QUADSPI_DCR_FSIZE_Msk, spec.flashSize, QUADSPI_DCR_FSIZE_Pos);
	setFieldData(mDev->DCR, QUADSPI_DCR_CSHT_Msk, spec.chipSelectHighTime, QUADSPI_DCR_CSHT_Pos);
	setBitData(mDev->DCR, spec.clockMode, QUADSPI_DCR_CKMODE_Pos);
	
	mSpec = &spec;

	return error_t::ERROR_NONE;
}

error_t Quadspi::setWaveform(const Waveform_t &waveform)
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

	return error_t::ERROR_NONE;
}

error_t Quadspi::setBank(uint8_t bank)
{
	// 장치가 활성화되어 있으면 에러
	if(getBitData(mDev->CR, QUADSPI_CR_EN_Pos))
		return error_t::BUSY;
	
	setBitData(mDev->CR, (bool)bank, QUADSPI_CR_FSEL_Pos);

	return error_t::ERROR_NONE;
}

error_t Quadspi::readRegister(uint8_t cmd, void *des, uint32_t size, uint32_t timeout)
{
	error_t result;
	Timeout tout(timeout);

	if(mRxDma == 0)
		return error_t::DMA_ERROR;

	if(size == 0)
		return error_t::ERROR_NONE;

	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;
		mDev->DLR = size - 1;
		mDev->CCR =	(FMODE_INDIRECT_READ << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_DMODE_Msk ) ) |
						cmd;
		mRxDma->lock();
		result = mRxDma->transfer(mRxDmaInfo, des, size);
		mRxDma->unlock();

		if(result != error_t::ERROR_NONE)
			return result;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
		{
			if(tout.isTimeout())
				return error_t::TIMEOUT;

			thread::yield();
		}

		return error_t::ERROR_NONE;
	}
	else
		return error_t::WRONG_CONFIG;
}

error_t Quadspi::writeCommand(unsigned char cmd)
{
	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;

		mDev->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & QUADSPI_CCR_IMODE_Msk) |
						cmd;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
			thread::yield();

		return error_t::ERROR_NONE;
	}
	else
		return error_t::WRONG_CONFIG;
}

error_t Quadspi::wait(uint8_t cmd, uint32_t mask, uint32_t status, uint8_t size, uint8_t pollingMatchMode, uint32_t timeOut)
{
	Timeout timeout(timeOut);

	if(size == 0 || size >= 4)
		return error_t::WRONG_SIZE;

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

		while(!getBitData(mDev->SR, QUADSPI_SR_SMF_Pos))
		{
			if(timeout.isTimeout())
				return error_t::TIMEOUT;

			thread::yield();
		}

		if(getBitData(mDev->SR, QUADSPI_SR_SMF_Pos))
			return error_t::ERROR_NONE;
		else
		{
			enable(false);
			enable(true);
			return error_t::TIMEOUT;
		}
	}
	else
		return error_t::WRONG_CONFIG;
}

error_t Quadspi::writeAddress(uint8_t cmd, uint32_t addr)
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

		return error_t::ERROR_NONE;
	}
	else
		return error_t::WRONG_CONFIG;
}

error_t Quadspi::write(uint8_t cmd, uint32_t addr, void *src, uint32_t size, uint32_t timeout)
{
	Timeout tout(timeout);
	error_t result;

	if(mTxDma == 0)
		return error_t::DMA_ERROR;

	if(size == 0)
		return error_t::ERROR_NONE;

	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;
		mDev->DLR = size - 1;
		mDev->CCR =	(FMODE_INDIRECT_WRITE << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk | QUADSPI_CCR_DMODE_Msk | QUADSPI_CCR_ABMODE_Msk  | QUADSPI_CCR_ABSIZE_Msk) ) |
						cmd;
		mDev->AR = addr;
		
		mTxDma->lock();
		result = mTxDma->transfer(mTxDmaInfo, src, size);
		mTxDma->unlock();

		if(result != error_t::ERROR_NONE)
			return result;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
		{
			if(tout.isTimeout())
				return error_t::TIMEOUT;

			thread::yield();
		}

		return error_t::ERROR_NONE;
	}
	else
		return error_t::WRONG_CONFIG;
}

error_t Quadspi::read(uint8_t cmd, uint32_t addr, void *des, uint32_t size, uint32_t timeout)
{
	error_t result;
	Timeout tout(timeout);

	if(mRxDma == 0)
		return error_t::DMA_ERROR;

	if(size == 0)
		return error_t::ERROR_NONE;

	if(mWaveform && mSpec)
	{
		mDev->FCR = QUADSPI_FCR_CTOF_Msk | QUADSPI_FCR_CSMF_Msk | QUADSPI_FCR_CTCF_Msk | QUADSPI_FCR_CTEF_Msk;
		mDev->DLR = size - 1;
		mDev->CCR =	(FMODE_INDIRECT_READ << QUADSPI_CCR_FMODE_Pos) |
						(mCcr & ( QUADSPI_CCR_IMODE_Msk | QUADSPI_CCR_ADMODE_Msk | QUADSPI_CCR_ADSIZE_Msk | QUADSPI_CCR_DMODE_Msk | QUADSPI_CCR_ABMODE_Msk  | QUADSPI_CCR_ABSIZE_Msk | QUADSPI_CCR_DCYC_Msk) ) |
						cmd;
		mDev->AR = addr;
		
		mTxDma->lock();
		result = mTxDma->transfer(mTxDmaInfo, des, size);
		mTxDma->unlock();

		if(result != error_t::ERROR_NONE)
			return result;

		while(getBitData(mDev->SR, QUADSPI_SR_BUSY_Pos))
		{
			if(tout.isTimeout())
				return error_t::TIMEOUT;

			thread::yield();
		}

		return error_t::ERROR_NONE;
	}
	else
		return error_t::WRONG_CONFIG;
}

void Quadspi::enable(bool en)
{
	setBitData(mDev->CR, en, QUADSPI_CR_EN_Pos);
}

#endif

