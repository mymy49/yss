////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
// 주담당자 : 아이구 (mymy49@nate.com) 2021.02.11 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32F1) || defined(STM32F4)

#include <config.h>

static const drv::Dma::DmaInfo gDmaDummy = 
{
	0,			// unsigned int controlRegister2
	0,			// unsigned int controlRegister3
	0,			//void *dataRegister;
};

static unsigned int getI2cClockFrequency(void)
{
	return clock.getApb1ClkFreq();
}

#if defined(I2C1) && defined(I2C1_ENABLE)
static void setI2c1ClockEn(bool en)
{
	clock.peripheral.setI2c1En(en);
}

static void resetI2c1(void)
{
	clock.peripheral.resetI2c1();
}

static const Drv::Config gDrvI2c1Config
{
	setI2c1ClockEn,			//void (*clockFunc)(bool en);
	0,						//void (*nvicFunc)(bool en);
	resetI2c1,				//void (*resetFunc)(void);
	getI2cClockFrequency	//unsigned int (*getClockFunc)(void);
};

static const drv::I2c::Config gI2c1Config
{
	I2C1,			//YSS_I2C_Peri *peri;
	dmaChannel6,	//Dma &txDma;
	gDmaDummy,		//Dma::DmaInfo txDmaInfo;
	dmaChannel7,	//Dma &rxDma;
	gDmaDummy		//Dma::DmaInfo rxDmaInfo;
};

drv::I2c i2c1(gDrvI2c1Config, gI2c1Config);
#endif



#if defined(I2C2) && defined(I2C2_ENABLE)
static void setI2c2ClockEn(bool en)
{
	clock.peripheral.setI2c2En(en);
}

static void resetI2c2(void)
{
	clock.peripheral.resetI2c2();
}

static const Drv::Config gDrvI2c2Config
{
	setI2c2ClockEn,			//void (*clockFunc)(bool en);
	0,						//void (*nvicFunc)(bool en);
	resetI2c2,				//void (*resetFunc)(void);
	getI2cClockFrequency	//unsigned int (*getClockFunc)(void);
};

static const drv::I2c::Config gI2c2Config
{
	I2C2,			//YSS_I2C_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gDmaDummy,		//Dma::DmaInfo txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gDmaDummy		//Dma::DmaInfo rxDmaInfo;
};

drv::I2c i2c2(gDrvI2c1Config, gI2c1Config);
#endif

#endif

