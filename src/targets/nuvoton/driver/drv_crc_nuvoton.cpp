/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonCrc.h>
#include <yss/scheduler.h>
#include <yss/reg.h>

/**
 * @file drv_crc_nuvoton.cpp
 * @brief CRC target-specific driver source file for Nuvoton.
 */

NuvotonCrc::NuvotonCrc(const Drv::setup_t drvSetup) : Crc(drvSetup)
{
	// Default data length to 32-bit width.
	mDataLen = Crc::CRC_DAT_LEN_32BIT;
}

error_t NuvotonCrc::initialize(config_t config)
{
	// Configure CRC block settings.
	configure(config);

	// Enable CRC engine.
	setBitData(CRC->CTL, true, CRC_CTL_CRCEN_Pos);	

	return error_t::ERROR_NONE;
}

error_t NuvotonCrc::configure(config_t config)
{
	// Set mode and data length options.
	setTwoFieldsData(CRC->CTL,	CRC_CTL_CRCMODE_Msk, config.mode, CRC_CTL_CRCMODE_Pos,
								CRC_CTL_DATLEN_Msk, config.datalen, CRC_CTL_DATLEN_Pos);

	// Configure byte/bit order reversal for data write and checksum query.
	setBitData(CRC->CTL, config.writeBitOrderReverse, CRC_CTL_DATREV_Pos);
	setBitData(CRC->CTL, config.checksumBitOrderReverse, CRC_CTL_CHKSREV_Pos);

	// Load initial seed value.
	CRC->SEED = config.seed;

	mDataLen = config.datalen;

	return error_t::ERROR_NONE;
}

void NuvotonCrc::resetChecksum(void)
{
	// Initialize checksum computation state with seed.
	CRC->CTL |= CRC_CTL_CHKSINIT_Msk;
}

uint32_t NuvotonCrc::calculate(void *src, uint32_t size)
{
	// Stream data byte-by-byte or word-by-word into calculation register based on width.
	switch(mDataLen)
	{
	case Crc::CRC_DAT_LEN_8BIT :
		for(uint32_t i = 0; i < size;i++)
			*(uint8_t*)&CRC->DAT = ((uint8_t*)src)[i];
		break;

	case Crc::CRC_DAT_LEN_16BIT :
		size &= ~0x01;
		for(uint32_t i = 0; i < size; i += 2)
			*(uint16_t*)&CRC->DAT = ((uint16_t*)src)[i];
		break;

	case Crc::CRC_DAT_LEN_32BIT :
		size &= ~0x03;
		for(uint32_t i = 0; i < size; i += 4)
			CRC->DAT = ((uint32_t*)src)[i];
		break;
	}

	// Return the resulting computed checksum.
	return CRC->CHECKSUM;
}

#endif


