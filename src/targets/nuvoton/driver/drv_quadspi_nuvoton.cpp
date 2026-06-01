/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M46x_SUBFAMILY) || defined(__M251_SUBFAMILY)

#include <targets/nuvoton/NuvotonQuadspi.h>
#include <yss.h>

#if !defined(QSPI_CTL_SPIEN_Msk)
#define QSPI_CTL_SPIEN_Msk	QSPI_CTL_QSPIEN_Msk
#endif

NuvotonQuadspi::NuvotonQuadspi(const Drv::setup_t drvSetup, const setup_t setup) : Quadspi(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mCapacity = 0;
	mDma = nullptr;
}

error_t NuvotonQuadspi::initialize(config_t config)
{
	if(config.mode == MODE_SUB)
		return error_t::NOT_SUPPORTED_YET;
	
	mDma = system::allocateDma();
	mDev->FIFOCTL = 1 << QSPI_FIFOCTL_TXTH_Pos | 1 << QSPI_FIFOCTL_RXTH_Pos;
	mDev->PDMACTL = QSPI_PDMACTL_PDMARST_Msk;
	if(mDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;
	else
	{
		return error_t::ERROR_NONE;
	}
}

error_t NuvotonQuadspi::setSpecification(const specification_t &spec)
{
	uint32_t clk = getClockFrequency(), mode;
	uint32_t div = (clk + spec.maxFrequncy - 1) / spec.maxFrequncy;

	if(div > 0)
		div--;
	
	if(spec.maxFrequncy < clk / (div + 1))
		return error_t::WRONG_CLOCK_FREQUENCY;

	mDev->CLKDIV = div;
	mCapacity = spec.capacity;

	switch(spec.clockMode)
	{
	case CLOCK_MODE_MODE0 :
		mode = 0x2;
		break;

	case CLOCK_MODE_MODE1 :
		mode = 0x1;
		break;

	case CLOCK_MODE_MODE2 :
		mode = 0x3;
		break;

	case CLOCK_MODE_MODE3 :
		mode = 0x6;
		break;
	}
	
	mClockMode = 0;
	setFieldData(mClockMode, QSPI_CTL_CLKPOL_Msk | QSPI_CTL_TXNEG_Msk | QSPI_CTL_RXNEG_Msk, mode, QSPI_CTL_RXNEG_Pos);
	setFieldData(mClockMode, QSPI_CTL_SUSPITV_Msk, 0, QSPI_CTL_SUSPITV_Pos);

	return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::transmit(dataform_t dataform, uint32_t data)
{
	uint32_t ctl = QSPI_CTL_SPIEN_Msk | QSPI_CTL_DATDIR_Msk | QSPI_CTL_HALFDPX_Msk | mClockMode, buf;
	
	ctl |= ((dataform.dataWidth + 8 & 0x1F) << QSPI_CTL_DWIDTH_Pos) | (dataform.bitWidth << QSPI_CTL_DUALIOEN_Pos) | (dataform.bitOrder << QSPI_CTL_LSB_Pos) | (dataform.byteReorder << QSPI_CTL_REORDER_Pos);

	mDev->CTL = ctl;
	mDev->TX = data;

	while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
		thread::yield();
	
	while(getFieldData(mDev->STATUS, QSPI_STATUS_RXCNT_Msk, QSPI_STATUS_RXCNT_Pos))
		mDev->RX;

	mDev->CTL = 0;

	return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::receive(dataform_t dataform, uint32_t &data)
{
	return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::transmit(dataform_t dataform, void *data, uint32_t size)
{
	uint32_t ctl = QSPI_CTL_SPIEN_Msk | QSPI_CTL_DATDIR_Msk | QSPI_CTL_HALFDPX_Msk | mClockMode, buf;
	
	ctl |= ((dataform.dataWidth + 8 & 0x1F) << QSPI_CTL_DWIDTH_Pos) | (dataform.bitWidth << QSPI_CTL_DUALIOEN_Pos) | (dataform.bitOrder << QSPI_CTL_LSB_Pos) | (dataform.byteReorder << QSPI_CTL_REORDER_Pos);
	
	mTxDmaInfo.ctl &= ~(PDMA_WIDTH_16 | PDMA_WIDTH_32);
	switch(dataform.dataWidth)
	{
	case Quadspi::DATA_WIDTH_8BIT :
		break;

	case Quadspi::DATA_WIDTH_9BIT :
	case Quadspi::DATA_WIDTH_10BIT :
	case Quadspi::DATA_WIDTH_11BIT :
	case Quadspi::DATA_WIDTH_12BIT :
	case Quadspi::DATA_WIDTH_13BIT :
	case Quadspi::DATA_WIDTH_14BIT :
	case Quadspi::DATA_WIDTH_15BIT :
	case Quadspi::DATA_WIDTH_16BIT :
		mTxDmaInfo.ctl |= PDMA_WIDTH_16;
		break;
	
	default :
		mTxDmaInfo.ctl |= PDMA_WIDTH_32;
		break;
	}
	
	mDev->CTL = ctl;
	mDma->setSource(mTxDmaInfo.src);
	mDma->ready(mTxDmaInfo, data, size);
	mDev->PDMACTL = QSPI_PDMACTL_TXPDMAEN_Msk;

	while(!mDma->isComplete())
		thread::yield();

	while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
		thread::yield();
	
	while(getFieldData(mDev->STATUS, QSPI_STATUS_RXCNT_Msk, QSPI_STATUS_RXCNT_Pos))
		mDev->RX;
	
	mDev->CTL = 0;
	mDev->PDMACTL = 0;

	return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::exchange(dataform_t dataform, uint32_t &data)
{
	uint32_t ctl = QSPI_CTL_SPIEN_Msk | mClockMode, buf;
	
	ctl |= ((dataform.dataWidth + 8 & 0x1F) << QSPI_CTL_DWIDTH_Pos) | (dataform.bitWidth << QSPI_CTL_DUALIOEN_Pos) | (dataform.bitOrder << QSPI_CTL_LSB_Pos);

	mDev->CTL = ctl;
	mDev->TX = data;

	while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
		thread::yield();
	
	data = mDev->RX;

	return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::exchange(dataform_t dataform, void *data, uint32_t size)
{
	uint32_t ctl = QSPI_CTL_SPIEN_Msk | mClockMode, buf;
	uint8_t *byte = (uint8_t*)data;
	uint16_t *hw = (uint16_t*)data;
	uint32_t *wd = (uint32_t*)data;
	
	ctl |= (dataform.dataWidth + 8 & 0x1F) << QSPI_CTL_DWIDTH_Pos;
	ctl |= dataform.bitWidth << QSPI_CTL_DUALIOEN_Pos;
	
	mDev->CTL = ctl;
	
	switch(dataform.dataWidth)
	{
	case Quadspi::DATA_WIDTH_8BIT :
		while(size)
		{
			if(~mDev->STATUS & QSPI_STATUS_TXFULL_Msk)
			{
				mDev->TX = *byte;
				size--;

				while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
					thread::yield();

				*byte++ = mDev->RX;
			}
			else
				thread::yield();
		}
		break;

	case Quadspi::DATA_WIDTH_9BIT :
	case Quadspi::DATA_WIDTH_10BIT :
	case Quadspi::DATA_WIDTH_11BIT :
	case Quadspi::DATA_WIDTH_12BIT :
	case Quadspi::DATA_WIDTH_13BIT :
	case Quadspi::DATA_WIDTH_14BIT :
	case Quadspi::DATA_WIDTH_15BIT :
	case Quadspi::DATA_WIDTH_16BIT :
		size &= ~0x01;
		while(size)
		{
			if(~mDev->STATUS & QSPI_STATUS_TXFULL_Msk)
			{
				mDev->TX = *hw;
				size -= 2;

				while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
					thread::yield();

				*hw++ = mDev->RX;
			}
			else
				thread::yield();
		}
		break;
	
	default :
		size &= ~0x03;
		while(size)
		{
			if(~mDev->STATUS & QSPI_STATUS_TXFULL_Msk)
			{
				mDev->TX = *wd;
				size -= 4;

				while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
					thread::yield();

				*wd++ = mDev->RX;
			}
			else
				thread::yield();
		}
		break;
	}
	
	while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
		thread::yield();
	
	return error_t::ERROR_NONE;
}

void NuvotonQuadspi::isr(void)
{
	mDev->STATUS = QSPI_STATUS_UNITIF_Msk;
}

#endif

