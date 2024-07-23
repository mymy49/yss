/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(GD32F1) || defined(STM32F4) || defined(STM32F7) | defined(STM32F1)

#include <drv/peripheral.h>
#include <drv/Crc32.h>
#include <targets/st/bitfield.h>

Crc32::Crc32(YSS_CRC32_Dev *peri, const Drv::setup_t drvConfig) : Drv(drvConfig)
{
	mPeri = peri;
	reset();
}

void Crc32::resetCrc32Value(void)
{
	mPeri->CR |= CRC_CR_RESET_Msk;
}

void Crc32::calculateInLittleEndian(void *src, uint32_t size)
{
	uint32_t *src32 = (uint32_t*)src;
	while(size--)
	{
		mPeri->DR = *src32++;
	}
}

void Crc32::calculateInBigEndian(void *src, uint32_t size)
{
	uint32_t bigendian;
	uint32_t *src32 = (uint32_t*)src;

	while(size--)
	{
		bigendian = *src32 >> 24;
		bigendian |= (*src32 >> 8) & 0xFF00;
		bigendian |= (*src32 << 8) & 0xFF0000;
		bigendian |= (*src32++ << 24) & 0xFF000000;
		
		mPeri->DR = bigendian;
	}
}

uint32_t Crc32::getCrc32Value(void)
{
	return mPeri->DR;
}

#endif
