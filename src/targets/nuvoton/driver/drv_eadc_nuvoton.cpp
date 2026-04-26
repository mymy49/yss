 /*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M251_SUBFAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonEadc.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <util/Timeout.h>

NuvotonEadc::NuvotonEadc(const Drv::setup_t drvSetup, const setup_t setup) : Adc(drvSetup)
{
	mDev = setup.dev;
	mSwTrigger = 0;
}

error_t NuvotonEadc::initialize(uint8_t numOfChannel)
{
	error_t result;

	if(numOfChannel >= NUM_OF_MAX_ADC_CH)
		return error_t::OVERSIZE;

	result = malloc(numOfChannel);
	if(result != error_t::ERROR_NONE)
		return result;

	for(uint8_t i = 0; i < numOfChannel; i++)
		mChannel[i].result = 0;

	setBitData(mDev->CTL, true, EADC_CTL_ADCEN_Pos);

	return error_t::ERROR_NONE;
}

error_t NuvotonEadc::add(uint8_t ch, lpfLv_t lpflv, bit_t bit)
{
	if(mChCount < mMaxChCount)
	{
		setConversionStartDelay(mChCount, 0, 100);
		setFieldData(mDev->SCTL[mChCount], EADC_SCTL_CHSEL_Msk, ch, EADC_SCTL_CHSEL_Pos);
		mChannel[mChCount].bit = bit;
		mSwTrigger |= 1 << mChCount;
		mChannel[mChCount++].lpfLevel = lpflv;

		return error_t::ERROR_NONE;
	}
	else
		return error_t::OVERFLOW;
}

void NuvotonEadc::setConversionStartDelay(uint8_t index, uint8_t div, uint8_t count)
{
	if(index < mMaxChCount)
	{
		setTwoFieldsData(mDev->SCTL[index], EADC_SCTL_TRGDLYDIV_Msk, div, EADC_SCTL_TRGDLYDIV_Pos,
											EADC_SCTL_TRGDLYCNT_Msk, count, EADC_SCTL_TRGDLYCNT_Pos);
		setBitData(mDev->INTSRC[0], true, (mChCount - 1));
	}
}

error_t NuvotonEadc::convert(bool en)
{
	Timeout timeout(1000);

	setBitData(mDev->CTL, en, EADC_CTL_ADCIEN0_Pos);

	if(en)
	{
		while(~mDev->PWRCTL & EADC_PWRCTL_READY_Msk)
		{
			if(timeout.isTimeout())
				return error_t::TIMEOUT;

			thread::yield();
		}

		mDev->SWTRG = mSwTrigger;
	}

	return error_t::ERROR_NONE;
}

void NuvotonEadc::isr(void)
{
	int32_t dr, temp;

	mDev->STATUS2 = EADC_STATUS2_ADIF0_Msk;

	for(uint8_t i = 0;i < mChCount; i++)
	{
		dr = mDev->DAT[i];
		if(dr & EADC_DAT_VALID_Msk)
		{
			dr = dr << 19;
			temp = dr - mChannel[i].result;
			temp >>= mChannel[i].lpfLevel;
			mChannel[i].result += temp;
		}
	}
	
	mDev->SWTRG = mSwTrigger;
}

#endif

