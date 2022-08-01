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

#if defined(GD32F1)

#include <drv/peripheral.h>
#include <drv/Adc.h>
#include <drv/adc/register_adc_stm32f1.h>
#include <yss/reg.h>

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
	mPeri->CTLR2 |= ADC_CTLR2_ADCON | ADC_CTLR2_ETSRC | ADC_CTLR2_ETERC;

	//// 샘플 타임 기본 설정은 가장 느리게
	mPeri->SPT1 = ADC_SPT1_SPT10 | ADC_SPT1_SPT11 | ADC_SPT1_SPT12 | ADC_SPT1_SPT13 | ADC_SPT1_SPT14 | ADC_SPT1_SPT15 | ADC_SPT1_SPT16 | ADC_SPT1_SPT17;
	mPeri->SPT2 = ADC_SPT2_SPT0 | ADC_SPT2_SPT1 | ADC_SPT2_SPT2 | ADC_SPT2_SPT3 | ADC_SPT2_SPT4 | ADC_SPT2_SPT5 | ADC_SPT2_SPT6 | ADC_SPT2_SPT7 | ADC_SPT2_SPT8 | ADC_SPT2_SPT9;

	setBitData(mPeri->CTLR1, true, 5);	// ADC 변환 완료 인터럽트 활성화
	setBitData(mPeri->CTLR2, true, 22);	// ADC 변환 시작
	return true;
}

void Adc::isr(void)
{
	signed int dr = mPeri->RDTR << 19, temp, abs;
	unsigned char index = mChannel[mIndex];

	temp = dr - mResult[index];
	temp >>= mLpfLv[mIndex];
	mResult[index] += temp;

	mIndex++;
	if (mIndex >= mNumOfCh)
		mIndex = 0;
	
	setFieldData(mPeri->RSQ3, 0x1F << 0, mChannel[mIndex], 0);	// ADC 채널 변경
	setBitData(mPeri->CTLR2, true, 22);	// ADC 변환 시작
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
	register unsigned int reg = ((unsigned int *)(&mPeri->SPT1))[index];

	pin = pin % 10 * 3;
	reg &= ~(0x07 << pin);
	reg |= sampleTime << pin;
	((unsigned int *)(&mPeri->SPT1))[index] = reg;
}

#endif