/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F0)

#include <drv/peripheral.h>
#include <drv/Adc.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Adc::Adc(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mIndex = 0;
	mNumOfCh = 0;

	for (int32_t  i = 0; i < 18; i++)
	{
		mChannel[i] = 0;
		mResult[i] = 0;
		mLpfLv[i] = define::adc::lpfLv::LV9;
		mBit[i] = define::adc::bit::BIT16;
	}
}

error_t Adc::initialize(void)
{
	uint32_t clk = getClockFrequency();
	
	// 소스 클럭 분주 설정
	if(clk / 14000 < 2000)
		mDev->CFGR2 = ADC_CFGR2_JITOFFDIV2;
	else
		mDev->CFGR2 = ADC_CFGR2_JITOFFDIV4;

	// ADC on
	setBitData(mDev->CR, true, ADC_CR_ADEN_Pos);

	// 샘플 타임 기본 설정은 가장 느리게
	mDev->SMPR = ADC_SMPR1_SMPR;

	setBitData(mDev->IER, true, ADC_IER_EOCIE_Pos);	// ADC 변환 완료 인터럽트 활성화
	setBitData(mDev->CR, true, ADC_CR_ADSTART_Pos);	// ADC 변환 시작

	return error_t::ERROR_NONE;
}

void Adc::isr(void)
{
	int32_t dr = mDev->DR << 19, temp;
	uint8_t index = mChannel[mIndex];

	temp = dr - mResult[index];
	temp >>= mLpfLv[mIndex];
	mResult[index] += temp;

	mIndex++;
	if (mIndex >= mNumOfCh)
		mIndex = 0;

	mDev->CHSELR = 1 << mChannel[mIndex];
	setBitData(mDev->CR, true, ADC_CR_ADSTART_Pos);	// ADC 변환 시작
}

void Adc::add(uint8_t channel, lpfLv_t lpfLv, bit_t bit)
{
	if (mNumOfCh >= 18)
		return;
	mChannel[mNumOfCh] = channel;
	mLpfLv[mNumOfCh] = lpfLv;
	mBit[channel] = bit;
	mNumOfCh++;
}

uint16_t Adc::getResult(uint8_t pin)
{
	return mResult[pin] >> mBit[pin];
}

void Adc::setSampleTime(uint8_t sampleTime)
{
	sampleTime &= ADC_SMPR_SMP_Msk;
	mDev->SMPR = sampleTime;
}

#endif