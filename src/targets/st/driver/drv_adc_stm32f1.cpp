////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
#if defined(ADC123_COMMON)
	ADC123_COMMON[ADC_COMMON_REG::CCR] |= ADC_CCR_ADCPRE_Msk;
#endif

	// ADC on
	setBitData(mDev->CR2, true, ADC_CR2_ADON_Pos);

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