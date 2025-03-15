/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_DMA__H_
#define YSS_DRV_DMA__H_

#include "peripheral.h"

#if defined(STM32F0) || defined(GD32F1) || defined(STM32F1)
typedef DMA_TypeDef				YSS_DMA_Peri;
typedef DMA_Channel_TypeDef		YSS_DMA_Channel_Peri;
#elif defined(STM32G4)
typedef DMA_TypeDef				YSS_DMA_Peri;
typedef DMA_Channel_TypeDef		YSS_DMA_Channel_Peri;
typedef DMAMUX_Channel_TypeDef	YSS_DMAMUX_Channel_Peri;
#define DMA_OCCUPANCY_ABLE
#elif defined(STM32F4) || defined(STM32F7)
typedef DMA_TypeDef				YSS_DMA_Peri;
typedef DMA_Stream_TypeDef		YSS_DMA_Channel_Peri;
#elif defined(EFM32PG22) || defined(EFR32BG22)
typedef LDMA_TypeDef			YSS_DMA_Peri;
typedef LDMA_CH_TypeDef			YSS_DMA_Channel_Peri;
typedef LDMAXBAR_CH_TypeDef		YSS_DMA_Channel_Src;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
typedef PDMA_T					YSS_DMA_Peri;
typedef DSCT_T					YSS_DMA_Channel_Peri;
#elif defined(W7500)
typedef DMA_TypeDef				YSS_DMA_Peri;
#else
#define YSS_DRV_DMA_UNSUPPORTED
typedef volatile uint32_t		YSS_DMA_Peri;
typedef volatile uint32_t		YSS_DMA_Channel_Peri;
#endif

#include "Drv.h"
#include <yss/error.h>
#include <yss/thread.h>

/*
	DMA 장치의 드라이버 입니다.
*/
class Dma : public Drv
{
  public:
#if defined(DMA_PL230)
	typedef struct
	{
		volatile void *src;
		volatile void *des;
		volatile uint32_t control;
		volatile uint32_t reserved;
	}dmaChannelData_t;
#endif

	typedef struct
	{
#if defined(STM32G4)
		uint32_t ccr;
		uint32_t muxccr;
		void *cpar;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
		uint32_t ctl;
		uint8_t src;
		void *cpar;
#elif defined(W7500)
		uint32_t  controlRegister1;
		void *dataRegister;
#else
		uint32_t  controlRegister1;
		uint32_t  controlRegister2;
		uint32_t  controlRegister3;
		void *dataRegister;
#endif
	}dmaInfo_t;
	
	/*
		DMA를 초기화 하는 함수입니다.
	*/
	void initialize(void) __attribute__((optimize("-O1")));
	
	/*
		DMA로 데이터를 송신 또는 수신하는 함수입니다. 데이터의 전송이 완료되거나 전송중 에러가 발생하면 리턴합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ dmaInfo : 전송에 필요한 DMA 설정입니다.
		@ *data : 송수신할 데이터의 포인터입니다.
		@ count : 송수신할 데이터의 전체 갯수입니다.
	*/
	error_t transfer(dmaInfo_t &dmaInfo, void *data, int32_t  count) __attribute__((optimize("-O1")));
	
	/*
		DMA로 데이터의 송/수신을 준비하는 함수입니다. 데이터의 송/수신이 완료되거나 송/수신중 에러가 발생하면 리턴합니다.
		자체적으로 직접 전송을 시작하지는 않고, 하드웨어가 부가적인 흐름을 만들어야 하는 전송에서 사용됩니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ dmaInfo : 전송에 필요한 DMA 설정입니다.
		@ *data : 송수신할 데이터의 포인터입니다.
		@ count : 송수신할 데이터의 전체 갯수입니다.
	*/
	error_t ready(dmaInfo_t &dmaInfo, void *data, int32_t  count) __attribute__((optimize("-O1")));
	
	/*
		설정된 데이터 버퍼와 그 버퍼의 카운트 만큼을 링버퍼 형태로 순환하면서 계속 전송을 합니다.
		stop() 함수가 호출되면 전송을 중단합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ dmaInfo : 전송에 필요한 DMA 설정입니다.
		@ *data : 송수신할 데이터의 포인터입니다.
		@ count : 송수신할 데이터의 전체 갯수입니다.
	*/
	error_t transferAsCircularMode(const dmaInfo_t &dmaInfo, void *data, uint16_t count) __attribute__((optimize("-O1")));
	
	/*	
		현재 DMA의 남은 전송 카운트를 반환합니다.
		.
		@ return : 현재 DMA에 남은 전송 카운트를 반환합니다.
	*/
	uint16_t getRemainingTransferCount(void) __attribute__((optimize("-O1")));
	
#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	/*	
		SCATTER 모드로 전송할 때, 전송이 완료된 전송 횟수를 얻습니다.
		.
		@ return : SCATTER 모드의 전송 완료 횟수를 반환합니다.
	*/
	uint16_t getCircularModeSentCount(void) __attribute__((optimize("-O1")));
	
	/*
		SCATTER 모드로 전송할 때, 직전에 전송이 완료된 버퍼의 포인터를 얻습니다.
		다음 전송을 위해 데이터를 채워 넣기 위해 사용됩니다.
		.
		@ return : 직전 전송이 완료된 버퍼의 포인터를 반환합니다.
	*/
	void* getCircularModePreviouslyTransmittedDataBuffer(void);
#endif
	
	/*
		DMA의 전송을 중단합니다.
	*/
	void stop(void) __attribute__((optimize("-O1")));

	/*
		ready() 함수로 준비시킨 전송을 송신을 개시하도록 하는 함수입니다.
	*/
	void trigger(void) __attribute__((optimize("-O1")));

	/*
		DMA 데이터 전송이 완료 됐는지 확인하는 함수이다.
		.
		@ return : 마지막 데이터 전송이 완료됐을 경우 true를 반환합니다.
	*/
	bool isComplete(void) __attribute__((optimize("-O1")));
	
	/*
		직전 데이터 전송에 에러가 발생했는지 확인하는 함수힙니다.
		.
		@ return : 직전 데이터 전송에 에러가 발생한 경우 true를 반환합니다.
	*/
	bool isError(void) __attribute__((optimize("-O1")));

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	/*
		DMA가 전송할 주변장치의 (소스) 번호를 지정합니다.
		.
		@ src : 주변장치의 소스 번호를 설정합니다.
	*/
	virtual void setSource(uint8_t src) __attribute__((optimize("-O1"))) = 0;
#endif
	
	// 아래 함수들은 시스템 함수로 사용자 호출을 금지합니다.
	void remainingTransfer(void);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	void isr(void) __attribute__((optimize("-O1")));
#else
	virtual void isr(void) __attribute__((optimize("-O1"))) = 0;
#endif

	struct setup_t
	{
#if defined(STM32G4)
		YSS_DMA_Peri *dma;
		YSS_DMA_Channel_Peri *channel;
		YSS_DMAMUX_Channel_Peri *dmamux;
#elif defined(EFM32PG22) || defined(EFR32BG22)
		YSS_DMA_Peri *dma;
		YSS_DMA_Channel_Peri *peri;
		YSS_DMA_Channel_Src *src;
		uint8_t channelNumber;
#elif defined(W7500)
		YSS_DMA_Peri *dma;
		dmaChannelData_t *primary;
		dmaChannelData_t *alternate;
		uint8_t channelNumber;
#else
		YSS_DMA_Peri *dma;
		YSS_DMA_Channel_Peri *peri;
#endif
	};

	Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup);

  protected :
	threadId_t mThreadId;
	bool mCompleteFlag, mErrorFlag;
	int32_t mRemainSize, mAddr;

#if defined(STM32G4)
	YSS_DMA_Peri *mDma;
	YSS_DMA_Channel_Peri *mChannel;
	YSS_DMAMUX_Channel_Peri *mDmaMux;
#elif defined(EFM32PG22) || defined(EFR32BG22)
	YSS_DMA_Peri *mDma;
	YSS_DMA_Channel_Peri *mChannel;
	YSS_DMA_Channel_Src *mSrc;
	uint8_t mChannelNumber;
#elif defined(W7500)
	YSS_DMA_Peri *mDma;
	dmaChannelData_t *mPrimary;
	dmaChannelData_t *mAlternate;
	uint8_t mChannelNumber;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	YSS_DMA_Peri *mDma;
	YSS_DMA_Channel_Peri *mChannel;
	uint8_t mSrcNum, mChNum;
	bool mCircularModeFlag;
	YSS_DMA_Channel_Peri mMainChannel, mSubChannel;
	uint32_t mCircularSentCnt;
#else
	YSS_DMA_Peri *mDma;
	YSS_DMA_Channel_Peri *mChannel;
	uint8_t mSrcNum, mChNum;
#endif
};

class DmaChannel1 : public Dma
{
public :
	DmaChannel1(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel2 : public Dma
{
public :
	DmaChannel2(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel3 : public Dma
{
public :
	DmaChannel3(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel4 : public Dma
{
public :
	DmaChannel4(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel5 : public Dma
{
public :
	DmaChannel5(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel6 : public Dma
{
public :
	DmaChannel6(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel7 : public Dma
{
public :
	DmaChannel7(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel8 : public Dma
{
 public :
	DmaChannel8(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel9 : public Dma
{
public :
	DmaChannel9(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel10 : public Dma
{
public :
	DmaChannel10(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel11 : public Dma
{
public :
	DmaChannel11(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel12 : public Dma
{
public :
	DmaChannel12(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel13 : public Dma
{
public :
	DmaChannel13(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel14 : public Dma
{
public :
	DmaChannel14(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel15 : public Dma
{
public :
	DmaChannel15(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

class DmaChannel16 : public Dma
{
public :
	DmaChannel16(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	virtual void setSource(uint8_t src);
#endif

#if !(defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY))
	virtual void isr(void);
#endif
};

#endif

