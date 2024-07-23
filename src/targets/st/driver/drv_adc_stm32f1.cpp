/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F1) || defined(GD32F1)

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
	uint32_t clk = getClockFrequency() / 2;

	if(clk > 14000000)
	{
		clk /= 14000000;
		if(clk > 3)
			return error_t::WRONG_CLOCK_FREQUENCY;

		setFieldData(RCC->CFGR, RCC_CFGR_ADCPRE_Msk, clk, RCC_CFGR_ADCPRE_Pos);
	}

#if defined(ADC123_COMMON)
	ADC123_COMMON[ADC_COMMON_REG::CCR] |= ADC_CCR_ADCPRE_Msk;
#endif
	
	// ADC on
	mDev->CR2 = ADC_CR2_ADON_Msk | ADC_CR2_EXTSEL_Msk | ADC_CR2_EXTTRIG_Msk;

	// 샘플 타임 기본 설정은 가장 느리게
	mDev->SMPR1 = ADC_SMPR1_SMP10_Msk | ADC_SMPR1_SMP11_Msk | ADC_SMPR1_SMP12_Msk | ADC_SMPR1_SMP13_Msk | ADC_SMPR1_SMP14_Msk | ADC_SMPR1_SMP15_Msk | ADC_SMPR1_SMP16_Msk | ADC_SMPR1_SMP17_Msk;
	mDev->SMPR2 = ADC_SMPR2_SMP0_Msk | ADC_SMPR2_SMP1_Msk | ADC_SMPR2_SMP2_Msk | ADC_SMPR2_SMP3_Msk | ADC_SMPR2_SMP4_Msk | ADC_SMPR2_SMP5_Msk | ADC_SMPR2_SMP6_Msk | ADC_SMPR2_SMP7_Msk | ADC_SMPR2_SMP8_Msk | ADC_SMPR2_SMP9_Msk;

	setBitData(mDev->CR1, true, ADC_CR1_EOSIE_Pos);	// ADC 변환 완료 인터럽트 활성화
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

void Adc::add(uint8_t pin, uint8_t lpfLv, uint8_t bit)
{
	if (mNumOfCh >= 18)
		return;
	mChannel[mNumOfCh] = pin;
	mLpfLv[mNumOfCh] = lpfLv;
	mBit[pin] = bit;
	mNumOfCh++;
}

uint16_t Adc::get(uint8_t pin)
{
	return mResult[pin] >> mBit[pin];
}

void Adc::setSampleTime(uint8_t pin, uint8_t sampleTime)
{
	if (pin > 17)
		return;

	register uint8_t index = 1 - pin / 10;
	register uint32_t reg = ((uint32_t *)(&mDev->SMPR1))[index];

	pin = pin % 10 * 3;
	reg &= ~(0x07 << pin);
	reg |= sampleTime << pin;
	((uint32_t *)(&mDev->SMPR1))[index] = reg;
}

#endif