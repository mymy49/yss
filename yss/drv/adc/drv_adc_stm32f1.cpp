////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 소스 코드 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F1)

#include <drv/peripheral.h>
#include <drv/Adc.h>
#include <drv/adc/register_adc_stm32f1.h>

Adc::Adc(YSS_ADC_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
	mPeri = peri;
	mIndex = 0;
	mNumOfCh = 0;

	for (int i = 0; i < 18; i++)
	{
		mChannel[i] = 0;
		mResult[i] = 0;
		mLpfLv[i] = define::adc::lpfLv::LV9;
		mBit[i] = define::adc::bit::BIT16;
	}
}

bool Adc::init(void)
{
	// ADC on
	mPeri->CR2 |= ADC_CR2_ADON | ADC_CR2_EXTSEL | ADC_CR2_EXTTRIG;

	// 샘플 타임 기본 설정은 가장 느리게
	mPeri->SMPR1 = ADC_SMPR1_SMP10 | ADC_SMPR1_SMP11 | ADC_SMPR1_SMP12 | ADC_SMPR1_SMP13 | ADC_SMPR1_SMP14 | ADC_SMPR1_SMP15 | ADC_SMPR1_SMP16 | ADC_SMPR1_SMP17;
	mPeri->SMPR2 = ADC_SMPR2_SMP0 | ADC_SMPR2_SMP1 | ADC_SMPR2_SMP2 | ADC_SMPR2_SMP3 | ADC_SMPR2_SMP4 | ADC_SMPR2_SMP5 | ADC_SMPR2_SMP6 | ADC_SMPR2_SMP7 | ADC_SMPR2_SMP8 | ADC_SMPR2_SMP9;
	
#if defined(__SEGGER_LINKER)
	mPeri->CR1 |= ADC_CR1_EOCIE;
#else
	mPeri->CR1 |= ADC_CR1_EOSIE;
#endif
	mPeri->CR2 |= ADC_CR2_SWSTART;
	return true;
}

void Adc::isr(void)
{
#if defined(__SEGGER_LINKER)
	if (mPeri->CR1 & ADC_CR1_EOCIE && mPeri->SR & ADC_SR_EOC)
#else
	if (mPeri->CR1 & ADC_CR1_EOSIE_Msk && mPeri->SR & ADC_SR_EOS_Msk)
#endif
	{
		signed int dr = mPeri->DR << 19, temp, abs;
		unsigned char index = mChannel[mIndex];

		mPeri->SR = 0;

		temp = dr - mResult[index];
		temp >>= mLpfLv[mIndex];
		mResult[index] += temp;

		mIndex++;
		if (mIndex >= mNumOfCh)
			mIndex = 0;

		mPeri->SQR3 &= ~ADC_SQR3_SQ1;
		mPeri->SQR3 |= mChannel[mIndex];
		mPeri->CR2 |= ADC_CR2_SWSTART;
	}
}

void Adc::add(unsigned char pin, unsigned char lpfLv, unsigned char bit)
{
	if (mNumOfCh >= 18)
		return;
	mChannel[mNumOfCh] = pin;
	mLpfLv[mNumOfCh] = lpfLv;
	mBit[pin] = bit;
	mNumOfCh++;
}

unsigned short Adc::get(unsigned char pin)
{
	return mResult[pin] >> mBit[pin];
}

void Adc::setSampleTime(unsigned char pin, unsigned char sampleTime)
{
	if (pin > 17)
		return;

	register unsigned char index = 1 - pin / 10;
	register unsigned int reg = ((unsigned int *)(&mPeri->SMPR1))[index];

	pin = pin % 10 * 3;
	reg &= ~(0x07 << pin);
	reg |= sampleTime << pin;
	((unsigned int *)(&mPeri->SMPR1))[index] = reg;
}

#endif