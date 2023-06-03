////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
	struct Setup
	{
		YSS_PDM_Peri *dev;
	};

	Pdm(const Drv::Setup drvSetup, const Setup setup);

	void push(int32_t data);

	void isr(void);

private :
	YSS_PDM_Peri *mDev;
	uint32_t *mRcvBuf;
	int32_t  mRcvBufLen;
	int32_t  mTail, mHead, mLastCheckCount;
};

#endif

