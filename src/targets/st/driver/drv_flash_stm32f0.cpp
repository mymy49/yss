/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F0)

#include <drv/peripheral.h>
#include <drv/Flash.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

void Flash::setLatency(uint32_t freq)
{
	if (freq <= 24000000)
		setFieldData(FLASH->ACR, FLASH_ACR_LATENCY_Msk, 0, FLASH_ACR_LATENCY_Pos);
	else
		setFieldData(FLASH->ACR, FLASH_ACR_LATENCY_Msk, 1, FLASH_ACR_LATENCY_Pos);
}

void Flash::setPrefetchEn(bool en)
{
	setBitData(FLASH->ACR, FLASH_ACR_PRFTBE_Pos, en);
}

uint32_t Flash::getAddress(uint16_t sector)
{
	uint32_t max, size;
#if defined(STM32F030xC)
	max = *(uint16_t *)FLASHSIZE_BASE;
	size = 2048;
#else
	max = *(uint16_t *)FLASHSIZE_BASE;
	size = 1024;
#endif

	if (sector > max)
		sector = max;

	return 0x08000000 + (uint32_t)sector * size;
}

void Flash::erase(uint16_t sector)
{
	uint32_t addr = getAddress(sector);

	while (getBitData(FLASH->SR, 0))
		thread::yield();

	if (sector < 256)
	{
		if (getBitData(FLASH->CR, 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FLASH->KEYR = 0x45670123;
			FLASH->KEYR = 0xCDEF89AB;
		}
		
		// Unlock이 될때까지 대기
		__DSB();
		while (getBitData(FLASH->CR, 7))
			thread::yield();
		
		// 지우기
		setBitData(FLASH->CR, true, 1);
		FLASH->AR = addr;
		setBitData(FLASH->CR, true, 6);

		__DSB();
		while (getBitData(FLASH->SR, 0))
			;

		setBitData(FLASH->CR, false, 1);	// 지우기 해제
		setBitData(FLASH->CR, false, 7);	// 잠금
	}
}

void *Flash::program(void *des, void *src, uint32_t size)
{
	uint16_t *addr = (uint16_t *)des;

	size += 1;
	size >>= 1;

	while (getBitData(FLASH->SR, 0))
		thread::yield();

	if ((int32_t )des < 0x08080000)
	{
		if (getBitData(FLASH->CR, 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FLASH->KEYR = 0x45670123;
			FLASH->KEYR = 0xCDEF89AB;
		}

		// Unlock이 될때까지 대기
		__DSB();
		while (getBitData(FLASH->CR, 7))
			thread::yield();

		setBitData(FLASH->CR, true, 0);	// 쓰기 설정

		__DSB();
		for (uint32_t i = 0; i < size; i++)
		{
			addr[i] = ((uint16_t *)src)[i];
			__DSB();
			while (getBitData(FLASH->SR, 0))
				;
		}

		__DSB();
		setBitData(FLASH->CR, false, 0);	// 쓰기 해제
		setBitData(FLASH->CR, false, 7);	// 잠금
	}

	return &addr[size];
}

void *Flash::program(uint32_t sector, void *src, uint32_t size)
{
	return program((void*)getAddress(sector), src, size);
}

#endif


