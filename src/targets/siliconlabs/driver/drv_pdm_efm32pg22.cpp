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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(EFM32PG22)

#include <drv/peripheral.h>
#include <drv/Pdm.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <util/Timeout.h>
#include <math.h>
#include <targets/siliconlabs/efm32pg22_pdm.h>

Pdm::Pdm(const Drv::Setup drvSetup, const Setup setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mRcvBuf = 0;
	mRcvBufLen = 0;
}

error Pdm::initialize(Configuration config, uint32_t *receiveBuffer, int32_t  receiveBufferLength)
{
	uint32_t pres = getClockFrequency() / (config.sampleRate * config.downSampleRate) - 1;
	uint8_t gain = 31 - (1 + (uint32_t)(log10f(pow((float)config.downSampleRate, 5)) / log10f(2)));

	if(pres > 1023)
		return error::WRONG_CLOCK_FREQUENCY;
	
	if(pres > 0)
		pres--;
			
	mDev->CMD_SET = _PDM_CMD_STOP_MASK;
	mDev->EN_CLR = _PDM_EN_EN_MASK;

	setBitData(mDev->CFG0, config.ch1ClkPol, _PDM_CFG0_CH1CLKPOL_SHIFT);
	setBitData(mDev->CFG0, config.ch0ClkPol, _PDM_CFG0_CH0CLKPOL_SHIFT);
	setBitData(mDev->CFG0, config.stereoMode, _PDM_CFG0_STEREOMODECH01_SHIFT);
	setFieldData(mDev->CFG0, _PDM_CFG0_FIFODVL_MASK, config.fifoLevel, _PDM_CFG0_FIFODVL_SHIFT);
	setFieldData(mDev->CFG0, _PDM_CFG0_DATAFORMAT_MASK, config.dataFormat, _PDM_CFG0_DATAFORMAT_SHIFT);
	setBitData(mDev->CFG0, config.numOfCh, _PDM_CFG0_NUMCH_SHIFT);
	setBitData(mDev->CFG0, config.filterOrder, _PDM_CFG0_FORDER_SHIFT);
	setFieldData(mDev->CFG1, _PDM_CFG1_DLYMUXSEL_MASK, config.delayMuxSel, _PDM_CFG1_DLYMUXSEL_SHIFT);
	setFieldData(mDev->CFG1, _PDM_CFG1_PRESC_MASK, pres, _PDM_CFG1_PRESC_SHIFT);

	mDev->EN_SET = _PDM_EN_EN_MASK;
	mDev->IEN_SET = _PDM_IEN_DVL_MASK;

	setFieldData(mDev->CTRL, _PDM_CTRL_DSR_MASK, config.downSampleRate, _PDM_CTRL_DSR_SHIFT);
	setFieldData(mDev->CTRL, _PDM_CTRL_GAIN_MASK, gain, _PDM_CTRL_GAIN_SHIFT);

	mRcvBuf = receiveBuffer;
	mRcvBufLen = receiveBufferLength;
	
	return error::ERROR_NONE;
}

error Pdm::initialize(Configuration config, int32_t  receiveBufferLength)
{
	uint32_t *buf = new uint32_t[receiveBufferLength];
	if (buf == 0)
		return error::MALLOC_FAILED;
	
	return initialize(config, buf, receiveBufferLength);
}

void Pdm::start(void)
{
	mDev->CMD_SET = _PDM_CMD_START_MASK;
}

void Pdm::stop(void)
{
	mDev->CMD_SET = _PDM_CMD_STOP_MASK;
}

void Pdm::push(int32_t data)
{
	mRcvBuf[mHead++] = data;
	if (mHead >= mRcvBufLen)
		mHead = 0;
}

uint32_t Pdm::getCount(void)
{
	if(mTail == mHead)	
		return 0;
	else if(mTail < mHead)
		mLastCheckCount =  mHead - mTail;
	else 
		mLastCheckCount = mRcvBufLen - mTail;

	return mLastCheckCount;
}

void Pdm::releaseBuffer(uint32_t count)
{
	if(mLastCheckCount < count)
		count = mLastCheckCount;

	mTail += count;
	if(mRcvBufLen == mTail)
		mTail = 0;
}

uint32_t* Pdm::getCurrentBuffer(void)
{
	return &mRcvBuf[mTail];
}

void Pdm::isr(void)
{
	while(getFieldData(mDev->STATUS, _PDM_STATUS_FIFOCNT_MASK, _PDM_STATUS_FIFOCNT_SHIFT))
		push(mDev->RXDATA);

	mDev->IF_CLR = 0xFFFF;
}

#endif

