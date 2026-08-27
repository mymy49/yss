/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file instance_crc_nuvoton.cpp
 * @brief Global driver instances initialization for Nuvoton CRC peripheral.
 */

#include <drv/peripheral.h>

#if defined(__M251_SUBFAMILY) || defined(__M46x_SUBFAMILY)

#include <targets/nuvoton/NuvotonCrc.h>
#include <drv/peripheral.h>
#include <config.h>
#include <yss.h>

#if CRC_ENABLE && defined(CRC)
static void enableCrcClock(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableApb0Clock().
#if defined(__M251_SUBFAMILY)
	clock.enableAhb0Clock(CLK_AHBCLK_CRCCKEN_Pos, en);
#elif defined(__M46x_SUBFAMILY)
	clock.enableAhb0Clock(CLK_AHBCLK0_CRCCKEN_Pos, en);
#endif
}

static void resetCrc()
{
    SYS->REGLCTL = 0x59;
    SYS->REGLCTL = 0x16;
    SYS->REGLCTL = 0x88;
    
    SYS->IPRST0 |= SYS_IPRST0_CRCRST_Msk;   // Reset Assert (리셋 걸기)
    SYS->IPRST0 &= ~SYS_IPRST0_CRCRST_Msk;  // Reset Release (리셋 풀기 - 필수)
    
    SYS->REGLCTL = 0x00;
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

