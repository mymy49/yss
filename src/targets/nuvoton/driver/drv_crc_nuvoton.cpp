/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonCrc.h>
#include <yss/thread.h>
#include <yss/reg.h>

NuvotonCrc::NuvotonCrc(const Drv::setup_t drvSetup) : Crc(drvSetup)
{
	mDataLen = Crc::CRC_DAT_LEN_32BIT;
}

error_t NuvotonCrc::initialize(config_t config)
{
	configure(config);

	setBitData(CRC->CTL, true, CRC_CTL_CRCEN_Pos);	

	return error_t::ERROR_NONE;
}

error_t NuvotonCrc::configure(config_t config)
{
	setTwoFieldsData(CRC->CTL,	CRC_CTL_CRCMODE_Msk, config.mode, CRC_CTL_CRCMODE_Pos,
								CRC_CTL_DATLEN_Msk, config.datalen, CRC_CTL_DATLEN_Pos);

	setBitData(CRC->CTL, config.writeBitOrderReverse, CRC_CTL_DATREV_Pos);
	setBitData(CRC->CTL, config.checksumBitOrderReverse, CRC_CTL_CHKSREV_Pos);

	CRC->SEED = config.seed;

	mDataLen = config.datalen;

	return error_t::ERROR_NONE;
}

void NuvotonCrc::resetChecksum(void)
{
	CRC->CTL |= CRC_CTL_CHKSINIT_Msk;
}

uint32_t NuvotonCrc::calculate(void *src, uint32_t size)
{
	switch(mDataLen)
	{
	case Crc::CRC_DAT_LEN_8BIT :
		for(uint32_t i = 0; i < size;i++)
			CRC->DAT = ((uint8_t*)src)[i];
		break;

	case Crc::CRC_DAT_LEN_16BIT :
		size &= ~0x01;
		for(uint32_t i = 0; i < size; i += 2)
			CRC->DAT = ((uint16_t*)src)[i];
		break;

	case Crc::CRC_DAT_LEN_32BIT :
		size &= ~0x03;
		for(uint32_t i = 0; i < size; i += 4)
			CRC->DAT = ((uint32_t*)src)[i];
		break;
	}

	return CRC->CHECKSUM;
}

#endif

