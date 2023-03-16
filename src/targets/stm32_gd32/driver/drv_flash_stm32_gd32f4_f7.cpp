////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F7)

#include <drv/Flash.h>
#include <targets/st_gigadevice/flash_stm32_gd32f4_f7.h>
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

Flash::Flash(void) : Drv(0, 0)
{
}

static const uint32_t g1MFlashSingleBankAddrTable[12] =
	{
		0x08000000, 0x08004000, 0x08008000, 0x0800C000, 0x08010000,
		0x08020000, 0x08040000, 0x08060000, 0x08080000, 0x080A0000,
		0x080C0000, 0x080E0000};

static const uint32_t g1MFlashDualBankAddrTable[20] =
	{
		0x08000000, 0x08004000, 0x08008000, 0x0800C000, 0x08010000,
		0x08020000, 0x08040000, 0x08060000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x08080000, 0x08084000, 0x08088000,
		0x0808C000, 0x08090000, 0x080A0000, 0x080C0000, 0x080E0000};

static const uint32_t g2MFlashDualBankAddrTable[24] =
	{
		0x08000000, 0x08004000, 0x08008000, 0x0800C000, 0x08010000,
		0x08020000, 0x08040000, 0x08060000, 0x08080000, 0x080A0000,
		0x080C0000, 0x080E0000, 0x08100000, 0x08104000, 0x08108000,
		0x0810C000, 0x08110000, 0x08120000, 0x08140000, 0x08160000,
		0x08180000, 0x081A0000, 0x081C0000, 0x081E0000};

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

	setFieldData(FLASH[FLASH_REG::ACR], FLASH_ACR_LATENCY_Msk, wait, FLASH_ACR_LATENCY_Pos);
}
#elif defined (STM32F7) || defined(STM32F429xx)
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
	
	setFieldData(FLASH[FLASH_REG::ACR], FLASH_ACR_LATENCY_Msk, wait, FLASH_ACR_LATENCY_Pos);
}
#endif

#if defined(STM32F4)
void Flash::enableDataCache(bool en)
{
	if(en)
		FLASH[FLASH_REG::ACR] |= FLASH_ACR_DCEN_Msk;
	else
		FLASH[FLASH_REG::ACR] &= ~FLASH_ACR_DCEN_Msk;
}

void Flash::enableInstructionCache(bool en)
{
	if(en)
		FLASH[FLASH_REG::ACR] |= FLASH_ACR_ICEN_Msk;
	else
		FLASH[FLASH_REG::ACR] &= ~FLASH_ACR_ICEN_Msk;
}
#elif defined(STM32F7)
void Flash::enableArtAccelerator(bool en)
{
	setBitData(FLASH[FLASH_REG::ACR], en, FLASH_ACR_ARTEN_Pos);
}
#endif

void Flash::enablePrefetch(bool en)
{
	setBitData(FLASH[FLASH_REG::ACR], en, FLASH_ACR_PRFTEN_Pos);
}

uint32_t Flash::getAddress(uint16_t sector)
{
	uint16_t size = *(uint16_t *)FLASHSIZE_BASE / 1024;

	switch (size)
	{
	case 1:
		if (gOptionByte2->db1m)
		{
			if (sector > 19)
				sector = 19;
			return g1MFlashDualBankAddrTable[sector];
		}
		else
		{
			if (sector > 11)
				sector = 11;
			return g1MFlashSingleBankAddrTable[sector];
		}
		break;
	case 2:
		if (sector > 23)
			sector = 23;
		return g2MFlashDualBankAddrTable[sector];
		break;
	}

	return 0;
}

void Flash::erase(uint16_t sector)
{
	uint32_t cr;

	if (sector >= 12)
	{
		sector -= 12;
		sector |= 0x10;
	}

	FLASH[FLASH_REG::SR] = 0XFFFF;

	__NOP();
	__NOP();
	while (FLASH[FLASH_REG::SR] & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH[FLASH_REG::KEYR] = 0x45670123;
	FLASH[FLASH_REG::KEYR] = 0xCDEF89AB;

	__NOP();
	__NOP();
	while (FLASH[FLASH_REG::CR] & FLASH_CR_LOCK_Msk)
		thread::yield();

	FLASH[FLASH_REG::CR] = FLASH_CR_SER_Msk | FLASH_CR_STRT_Msk | (sector << FLASH_CR_SNB_Pos) & FLASH_CR_SNB_Msk;

	__NOP();
	__NOP();
	while (FLASH[FLASH_REG::SR] & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH[FLASH_REG::CR] = FLASH_CR_LOCK_Msk;
}

void *Flash::program(uint32_t sector, void *src, uint32_t size)
{
	uint8_t *cdes = (uint8_t *)getAddress(sector), *csrc = (uint8_t *)src;
	FLASH[FLASH_REG::SR] = 0XFFFF;

	while (FLASH[FLASH_REG::SR] & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH[FLASH_REG::KEYR] = 0x45670123;
	FLASH[FLASH_REG::KEYR] = 0xCDEF89AB;

	while (FLASH[FLASH_REG::CR] & FLASH_CR_LOCK_Msk)
		thread::yield();

	FLASH[FLASH_REG::CR] = FLASH_CR_PG_Msk;

	for (uint32_t i = 0; i < size; i++)
	{
		__NOP();
		__NOP();
		*cdes++ = *csrc++;
		while (FLASH[FLASH_REG::SR] & FLASH_SR_BSY_Msk)
			thread::yield();

		if (FLASH[FLASH_REG::SR] & ~FLASH_SR_BSY_Msk)
			return (void *)cdes;
	}

	FLASH[FLASH_REG::CR] = FLASH_CR_LOCK_Msk;

	return (void *)cdes;
}

void *Flash::program(void *des, void *src, uint32_t size)
{
	uint8_t *cdes = (uint8_t *)des, *csrc = (uint8_t *)src;
	FLASH[FLASH_REG::SR] = 0XFFFF;

	while (FLASH[FLASH_REG::SR] & FLASH_SR_BSY_Msk)
		thread::yield();

	FLASH[FLASH_REG::KEYR] = 0x45670123;
	FLASH[FLASH_REG::KEYR] = 0xCDEF89AB;

	while (FLASH[FLASH_REG::CR] & FLASH_CR_LOCK_Msk)
		thread::yield();

	FLASH[FLASH_REG::CR] = FLASH_CR_PG_Msk;

	for (uint32_t i = 0; i < size; i++)
	{
		__NOP();
		__NOP();
		*cdes++ = *csrc++;
		while (FLASH[FLASH_REG::SR] & FLASH_SR_BSY_Msk)
			thread::yield();

		if (FLASH[FLASH_REG::SR] & ~FLASH_SR_BSY_Msk)
			return (void *)cdes;
	}

	FLASH[FLASH_REG::CR] = FLASH_CR_LOCK_Msk;

	return (void *)cdes;
}
#endif

