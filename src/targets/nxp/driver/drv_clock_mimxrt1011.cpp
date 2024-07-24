/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(CPU_MIMXRT1011DAE5A)

#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/nxp/bitfield_MIMXRT1011.h>

static uint32_t gHseFreq __attribute__((section(".non_init")));

error_t Clock::enableOsc(uint32_t hseHz)
{
	//gHseFreq = hseHz;

	//XTALOSC24M->MISC0_SET = XTALOSC24M_MISC0_SET_XTAL_24M_PWD_MASK;

	//CRG->OSC_PDR &= ~CRG_OSC_PDR_OSCPD;

	return error_t::ERROR_NONE;
}

#endif

