/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonSdh.h>
#include <yss/reg.h>
#include <util/Timeout.h>

/**
 * @file drv_sdh_nuvoton.cpp
 * @brief SDH (Secure Digital Host) target-specific driver source file for Nuvoton.
 */

NuvotonSdh::NuvotonSdh(const Drv::setup_t &drvSetup, const setup_t &setup) : Sdmmc(drvSetup)
{
	mDev = setup.dev;
	setSdhClockFrequency = setup.setSdhClockFrequency;
	mAcmdFlag = false;
}


error_t NuvotonSdh::initialize(void)
{
	Timeout timeout(100);
	mDev->INTEN |= SDH_INTEN_CDSRC_Msk;
	
	mDev->DMACTL = SDH_DMACTL_DMARST_Msk;
	timeout.reset();
	while((mDev->DMACTL & SDH_DMACTL_DMARST_Msk) == SDH_DMACTL_DMARST_Msk)
	{
		if(timeout.isTimeout())
			return error_t::TIMEOUT;
		thread::yield();
	}
	mDev->DMACTL = SDH_DMACTL_DMAEN_Msk;

	mDev->GCTL = SDH_GCTL_GCTLRST_Msk | SDH_GCTL_SDEN_Msk;
	timeout.reset();
	while((mDev->GCTL & SDH_GCTL_GCTLRST_Msk) == SDH_GCTL_GCTLRST_Msk)
	{
		if(timeout.isTimeout())
			return error_t::TIMEOUT;
		thread::yield();
	}

	mDev->CTL |= SDH_CTL_CTLRST_Msk;
	timeout.reset();
	while((mDev->CTL & SDH_CTL_CTLRST_Msk) == SDH_CTL_CTLRST_Msk)
	{
		if(timeout.isTimeout())
			return error_t::TIMEOUT;
		thread::yield();
	}

	setFieldData(mDev->CTL, SDH_CTL_SDNWR_Msk, 9, SDH_CTL_SDNWR_Pos);

	return error_t::ERROR_NONE;
}

error_t NuvotonSdh::sendPowerOn74Clock(void)
{
	uint32_t ctl = mDev->CTL | SDH_CTL_CLK74OEN_Msk;
	
	mDev->CTL = ctl;

	while(mDev->CTL & SDH_CTL_CLK74OEN_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t NuvotonSdh::sendCmd(cmd_t cmd, uint32_t arg, response_t responseType)
{
	uint32_t ctl = mDev->CTL | SDH_CTL_COEN_Msk;
	Timeout timeout(100);

	switch(cmd)
	{
	case CMD17_READ_SINGLE_BLOCK :
		ctl |= SDH_CTL_DIEN_Msk;
		break;

	default :
		break;
	}

	switch(responseType)
	{
	case RESPONSE_NO_R :
		break;

	case RESPONSE_R2 :
		ctl |= SDH_CTL_R2EN_Msk;
		break;
	
	case RESPONSE_R1 :
	case RESPONSE_R1b :
	case RESPONSE_R3 :
	case RESPONSE_R6 :
	case RESPONSE_R7 :
		ctl |= SDH_CTL_RIEN_Msk;
		break;
	
	default :
		return error_t::UNSUPPORTED_RESPONSE_TYPE;
	}

	setFieldData(ctl, SDH_CTL_CMDCODE_Msk, cmd, SDH_CTL_CMDCODE_Pos);
	
	mDev->INTSTS = SDH_INTSTS_BLKDIF_Msk;
    mDev->CMDARG = arg;
	mDev->CTL = ctl;
	
	while((mDev->CTL & SDH_CTL_COEN_Msk) || (mDev->CTL & SDH_CTL_RIEN_Msk) || (mDev->CTL & SDH_CTL_R2EN_Msk) || (mDev->CTL & SDH_CTL_DIEN_Msk))
	{
		if(timeout.isTimeout())
		{
			mDev->CTL |= SDH_CTL_CTLRST_Msk;
			return error_t::TIMEOUT;
		}

		thread::yield();
	}
	
	switch(cmd)
	{
	case CMD17_READ_SINGLE_BLOCK :
		if(mDev->INTSTS & SDH_INTSTS_CRC16_Msk)
			break;
		else
			return error_t::DATA_CRC_FAIL;

	default :
		break;
	}

	switch(responseType)
	{
	case RESPONSE_NO_R :
	case RESPONSE_R1 :
	case RESPONSE_R1b :
	case RESPONSE_R2 :
	case RESPONSE_R6 :
	case RESPONSE_R7 :
		if(mDev->INTSTS & SDH_INTSTS_CRC7_Msk)
			return error_t::ERROR_NONE;
		else
			return error_t::CMD_CRC_FAIL;

	case RESPONSE_R3 :
		return error_t::ERROR_NONE;
	
	default :
		return error_t::UNSUPPORTED_RESPONSE_TYPE;
	}
}

uint32_t NuvotonSdh::getShortResponse(void)
{
	uint32_t resp = mDev->RESP0 << 8;
	resp |= (uint8_t)mDev->RESP1;
	return resp;
}

inline uint32_t SDH_Swap32(uint32_t val)
{
    uint32_t buf;

    buf = val;
    val <<= 24;
    val |= (buf << 8) & 0xff0000ul;
    val |= (buf >> 8) & 0xff00ul;
    val |= (buf >> 24) & 0xfful;
    return val;
}

void NuvotonSdh::getLongResponse(void *des)
{
	uint32_t *wDes = (uint32_t*)des;
	uint8_t *cSrc;
	uint32_t reg;
    uint32_t tmpBuf[5];

	for(uint32_t i = 0; i < 5; i++)
		tmpBuf[i] = SDH_Swap32(mDev->FB[i]);

	for(uint32_t i = 0; i < 4; i++)
		wDes[i] = ((tmpBuf[i] & 0x00fffffful) << 8) | ((tmpBuf[i + 1ul] & 0xff000000ul) >> 24);

	for(uint32_t i = 0; i < 4; i++)
		wDes[i] = SDH_Swap32(wDes[i]);
}

void NuvotonSdh::setSdioClockBypass(bool en)
{
}

void NuvotonSdh::setSdioClockEn(bool en)
{
}

void NuvotonSdh::setClockFrequency(int32_t  frequency)
{
	setSdhClockFrequency(frequency);
}

void NuvotonSdh::enablePower(bool en)
{
}

void NuvotonSdh::readyRead(void *des, uint16_t length)
{
	mDev->DMASA = (uint32_t)des;
}

void NuvotonSdh::stopReadyRead(void)
{
}

void NuvotonSdh::readyWrite(void *des, uint16_t length)
{
}

void NuvotonSdh::setDataBlockSize(uint16_t blockSize)
{
	mDev->BLEN = blockSize - 1;
}

error_t NuvotonSdh::waitUntilReadComplete(void)
{
	return error_t::ERROR_NONE;
}

error_t NuvotonSdh::waitUntilWriteComplete(void)
{
	return error_t::ERROR_NONE;
}

bool NuvotonSdh::setBusWidth(busWidth_t width)
{
	switch(width)
	{
	case BUS_WIDTH_1BIT :
		mDev->CTL &= ~SDH_CTL_DBW_Msk;
		break;
	
	case BUS_WIDTH_4BIT :
		mDev->CTL |= ~SDH_CTL_DBW_Msk;
		break;
	
	case BUS_WIDTH_8BIT :
		return error_t::UNSUPPORTED_MODE;
	}

	return error_t::ERROR_NONE;
}

#endif

