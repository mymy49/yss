/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_PDM__H_
#define YSS_DRV_PDM__H_

#include "peripheral.h"

#if defined(EFM32PG22)
typedef PDM_TypeDef				YSS_PDM_Peri;
#else
typedef volatile uint32_t		YSS_PDM_Peri;
#define YSS_DRV_PDM_UNSUPPORTED
typedef volatile uint32_t	YSS_PDM_Peri;
#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

class Pdm : public Drv
{
public:
	struct Configuration
	{
		uint8_t ch0ClkPol;		// 채널0 클럭 엣지 설정
		uint8_t ch1ClkPol;		// 채널1 클럭 엣지 설정
		uint8_t stereoMode;		// 스테레오 모드 설정
		uint8_t fifoLevel;		// FIFO 사용 길이 설정
		uint8_t dataFormat;		// 데이터 포멧 설정
		uint8_t numOfCh;		// 채널 개수 설정
		uint8_t filterOrder;	// Filter Order 설정
		uint8_t delayMuxSel;	// Data Delay Buffer Mux 설정
		uint32_t sampleRate;	// Sample Rate 주파수 설정
		uint8_t downSampleRate;	// Down Sampling Rate 설정
	};

	error initialize(Configuration config, uint32_t *receiveBuffer, int32_t  receiveBufferLength);

	error initialize(Configuration config, int32_t  receiveBufferLength);

	void start(void);

	void stop(void);

	uint32_t getCount(void);

	void releaseBuffer(uint32_t count);

	uint32_t* getCurrentBuffer(void);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	struct setup_t
	{
		YSS_PDM_Peri *dev;
	};

	Pdm(const Drv::setup_t drvSetup, const Setup setup);

	void push(int32_t data);

	void isr(void);

private :
	YSS_PDM_Peri *mDev;
	uint32_t *mRcvBuf;
	int32_t  mRcvBufLen;
	int32_t  mTail, mHead, mLastCheckCount;
};

#endif

