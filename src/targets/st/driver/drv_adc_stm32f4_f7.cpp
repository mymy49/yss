/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F7)

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
#if defined(ADC123_COMMON)
	ADC123_COMMON->CCR |= ADC_CCR_ADCPRE_Msk;
#endif

	// ADC on
	setBitData(mDev->CR2, true, ADC_CR2_ADON_Pos);

	// 샘플 타임 기본 설정은 가장 느리게
	mDev->SMPR1 = ADC_SMPR1_SMP10_Msk | ADC_SMPR1_SMP11_Msk | ADC_SMPR1_SMP12_Msk | ADC_SMPR1_SMP13_Msk | ADC_SMPR1_SMP14_Msk | ADC_SMPR1_SMP15_Msk | ADC_SMPR1_SMP16_Msk | ADC_SMPR1_SMP17_Msk;
	mDev->SMPR2 = ADC_SMPR2_SMP0_Msk | ADC_SMPR2_SMP1_Msk | ADC_SMPR2_SMP2_Msk | ADC_SMPR2_SMP3_Msk | ADC_SMPR2_SMP4_Msk | ADC_SMPR2_SMP5_Msk | ADC_SMPR2_SMP6_Msk | ADC_SMPR2_SMP7_Msk | ADC_SMPR2_SMP8_Msk | ADC_SMPR2_SMP9_Msk;

	setBitData(mDev->CR1, true, ADC_CR1_EOCIE_Pos);	// ADC 변환 완료 인터럽트 활성화
	setBitData(mDev->CR2, true, ADC_CR2_SWSTART_Pos);	// ADC 변환 시작

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

	setFieldData(mDev->SQR3, ADC_SQR3_SQ1_Msk, mChannel[mIndex], ADC_SQR3_SQ1_Pos);	// ADC 채널 변경
	setBitData(mDev->CR2, true, ADC_CR2_SWSTART_Pos);	// ADC 변환 시작
}

void Adc::add(uint8_t chaanel, lpfLv_t lpfLv, bit_t bit)
{
	if (mNumOfCh >= 18)
		return;
	mChannel[mNumOfCh] = chaanel;
	mLpfLv[mNumOfCh] = lpfLv;
	mBit[chaanel] = bit;
	mNumOfCh++;
}

uint16_t Adc::getResult(uint8_t channel)
{
	return mResult[channel] >> mBit[channel];
}

void Adc::setSampleTime(uint8_t channel, uint8_t sampleTime)
{
	if (channel > 17)
		return;

	register uint8_t index = 1 - channel / 10;
	register uint32_t reg = ((uint32_t *)(&mDev->SMPR1))[index];

	channel = channel % 10 * 3;
	reg &= ~(0x07 << channel);
	reg |= sampleTime << channel;
	((uint32_t *)(&mDev->SMPR1))[index] = reg;
}

#endif
