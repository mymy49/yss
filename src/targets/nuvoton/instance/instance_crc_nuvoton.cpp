/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M251_SUBFAMILY)

#include <targets/nuvoton/NuvotonCrc.h>
#include <config.h>
#include <yss.h>

#if CRC_ENABLE && defined(CRC)
static void enableCrcClock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableAhb0Clock(CLK_AHBCLK_CRCCKEN_Pos, en);
}

static const Drv::setup_t gDrvCrcSetup = 
{
	enableCrcClock,		//void (*clockFunc)(bool en);
	nullptr,			//void (*nvicFunc)(bool en);
	nullptr,			//void (*resetFunc)(void);
	nullptr				//uint32_t (*getClockFunc)(void);
};

NuvotonCrc crc(gDrvCrcSetup);

#endif

#endif

