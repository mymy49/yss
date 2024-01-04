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

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F7)

#include <targets/st/bitfield.h>
#include <drv/Flash.h>
#include <yss/thread.h>

struct OptionBytes2
{
	unsigned reserved0 : 16;
	unsigned sprmod : 1;
	unsigned db1m : 1;
	unsigned reserved1 : 2;
	unsigned nwrp : 12;
};

const OptionBytes2 *gOptionByte2 = (OptionBytes2 *)(0x1FFFC008);

#if defined(STM32F767xx)
static const uint32_t g2MFlashSinglelBankAddrTable[12] =
	{
		0x08000000, 0x08008000, 0x08010000, 0x08018000, 0x08020000,
		0x08040000, 0x08080000, 0x080C0000, 0x08100000, 0x08140000,
		0x08180000, 0x081C0000};

static const uint32_t g2MFlashDualBankAddrTable[24] =
	{
		0x08000000, 0x08004000, 0x08008000, 0x0800C000, 0x08010000,
		0x08020000, 0x08040000, 0x08060000, 0x08080000, 0x080A0000,
		0x080C0000, 0x080E0000, 0x08100000, 0x08104000, 0x08108000, 
		0x0810C000, 0x08110000, 0x08120000, 0x08140000, 0x08160000, 
		0x08180000, 0x081A0000, 0x081C0000, 0x081E0000};
#endif

#if defined(STM32F411xE)
void Flash::setLatency(uint32_t frequency, uint8_t vcc)
{
	register uint32_t wait;

	if (vcc >= 27)
	{
		if(frequency <= 30000000)
			wait = 0;
		else if(frequency <= 64000000)
			wait = 1;
		else if(frequency <= 90000000)
			wait = 2;
		else
			wait = 3;
	}
	else if (vcc >= 24)
	{
		if(frequency <= 24000000)
			wait = 0;
		else if(frequency <= 48000000)
			wait = 1;
		else if(frequency <= 72000000)
			wait = 2;
		else if(frequency <= 96000000)
			wait = 3;
		else
			wait = 4;
	}
	else if (vcc >= 21)
	{
		if(frequency <= 18000000)
			wait = 0;
		else if(frequency <= 36000000)
			wait = 1;
		else if(frequency <= 54000000)
			wait = 2;
		else if(frequency <= 72000000)
			wait = 3;
		else if(frequency <= 90000000)
			wait = 4;
		else
			wait = 5;
	}
	else
	{
		if(frequency <= 16000000)
			wait = 0;
		else if(frequency <= 32000000)
			wait = 1;
		else if(frequency <= 48000000)
			wait = 2;
		else if(frequency <= 64000000)
			wait = 3;
		else if(frequency <= 80000000)
			wait = 4;
		else if(frequency <= 96000000)
			wait = 5;
		else
			wait = 6;
	}

	setFieldData(FLASH->ACR, FLASH_ACR_LATENCY_Msk, wait, FLASH_ACR_LATENCY_Pos);
}
#elif defined(STM32F429xx) || defined(STM32F446xx) || defined(STM32F767xx) || defined(STM32F746xx) || defined(STM32F407xx)
void Flash::setLatency(uint32_t freq, uint8_t vcc)
{
	uint32_t div, wait;

	if (vcc > 27)
	{
		div = 30;
	}
	else if (vcc > 24)
	{
		div = 24;
	}
	else if (vcc > 21)
	{
		div = 22;
	}
	else
	{
		div = 20;
	}

	freq /= 1000000;
	wait = freq / div;
	if (!(freq % div))
		wait--;
	
	setFieldData(FLASH->ACR, FLASH_ACR_LATENCY_Msk, wait, FLASH_ACR_LATENCY_Pos);
}
#endif

#if defined(STM32F4)
void Flash::enableDataCache(bool en)
{
	if(en)
		FLASH->ACR |= FLASH_ACR_DCEN_Msk;
	else
		FLASH->ACR &= ~FLASH_ACR_DCEN_Msk;
}

void Flash::enableInstructionCache(bool en)
{
	if(en)
		FLASH->ACR |= FLASH_ACR_ICEN_Msk;
	else
		FLASH->ACR &= ~FLASH_ACR_ICEN_Msk;
}
#elif defined(STM32F7)
void Flash::enableArtAccelerator(bool en)
{
	setBitData(FLASH->ACR, en, FLASH_ACR_ARTEN_Pos);
}
#endif

void Flash::enablePrefetch(bool en)
{
	setBitData(FLASH->ACR, en, FLASH_ACR_PRFTEN_Pos);
}

#if defined(STM32F767xx)
uint32_t Flash::getAddress(uint16_t sector)
{
	uint16_t size = *(uint16_t *)FLASHSIZE_BASE / 1024;

	switch (size)
	{
	case 2:
		if(FLASH->OPTCR & FLASH_OPTCR_nDBANK_Msk)
		{
			if (sector > 11)
				sector = 11;
			return g2MFlashSinglelBankAddrTable[sector];
		}
		else
		{
			if (sector > 23)
				sector = 23;
			return g2MFlashDualBankAddrTable[sector];
		}
		break;
	}

	return 0;
}
#elif defined(STM32F746xx)
uint32_t Flash::getAddress(uint16_t sector)
{
	const uint32_t addrTable[8] =
	{
		0x08000000, 0x08008000, 0x08010000, 0x08018000, 0x08020000,
		0x08040000, 0x08080000, 0x080C0000
	};

	if(sector < 8)
		return addrTable[sector];
	else
		return 0;
}
#endif

void Flash::erase(uint16_t sector)
{
	if (sector >= 12)
	{
		sector -= 12;
		sector |= 0x10;
	}

	FLASH->SR = 0XFFFF;

	__DSB();
	while (FLASH->SR & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH->KEYR = 0x45670123;
	FLASH->KEYR = 0xCDEF89AB;

	__DSB();
	while (FLASH->CR & FLASH_CR_LOCK_Msk)
		thread::yield();

	setFieldData(FLASH->CR, FLASH_CR_PSIZE_Msk, 2, FLASH_CR_PSIZE_Pos);
	FLASH->CR = FLASH_CR_SER_Msk | ((sector << FLASH_CR_SNB_Pos) & FLASH_CR_SNB_Msk);
	FLASH->CR |= FLASH_CR_STRT_Msk;

	__DSB();
	while (FLASH->SR & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH->CR = FLASH_CR_LOCK_Msk;
}

void *Flash::program(uint32_t sector, void *src, uint32_t size)
{
	uint32_t *cdes = (uint32_t *)getAddress(sector), *csrc = (uint32_t *)src;
	FLASH->SR = 0XFFFF;

	size += 3;
	size >>= 2;

	__DSB();
	while (FLASH->SR & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH->KEYR = 0x45670123;
	FLASH->KEYR = 0xCDEF89AB;

	__DSB();
	while (FLASH->CR & FLASH_CR_LOCK_Msk)
		thread::yield();

	setFieldData(FLASH->CR, FLASH_CR_PSIZE_Msk, 2, FLASH_CR_PSIZE_Pos);
	setBitData(FLASH->CR, true, FLASH_CR_PG_Pos);

	for (uint32_t i = 0; i < size; i++)
	{
		__DSB();
		while (FLASH->SR & FLASH_SR_BSY_Msk)
			thread::yield();

		*cdes++ = *csrc++;
	}

	__DSB();
	while (FLASH->SR & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH->CR = FLASH_CR_LOCK_Msk;

	return (void *)cdes;
}

void *Flash::program(void *des, void *src, uint32_t size)
{
	uint32_t *cdes = (uint32_t *)des, *csrc = (uint32_t *)src;
	FLASH->SR = 0XFFFF;
	size += 3;
	size /= 4;

	__DSB();
	while (FLASH->SR & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH->KEYR = 0x45670123;
	FLASH->KEYR = 0xCDEF89AB;

	__DSB();
	while (FLASH->CR & FLASH_CR_LOCK_Msk)
		thread::yield();

	setFieldData(FLASH->CR, FLASH_CR_PSIZE_Msk, 2, FLASH_CR_PSIZE_Pos);
	setBitData(FLASH->CR, true, FLASH_CR_PG_Pos);

	__DSB();
	while (FLASH->SR & FLASH_SR_BSY_Msk)
		thread::yield();

	for (uint32_t i = 0; i < size; i++)
	{
		*cdes++ = *csrc++;

		__DSB();
		while (FLASH->SR & FLASH_SR_BSY_Msk)
			thread::yield();
	}

	FLASH->CR = FLASH_CR_LOCK_Msk;

	return (void *)cdes;
}

#if defined(STM32F767xx)
	void Flash::setBank(uint8_t bank)
	{
		FLASH->OPTKEYR = 0x08192A3B;
		FLASH->OPTKEYR = 0x4C5D6E7F;
		setBitData(FLASH->OPTCR, bank, FLASH_OPTCR_nDBANK_Pos);
		FLASH->OPTCR |= FLASH_OPTCR_OPTLOCK_Msk;
	}
#endif

#endif

