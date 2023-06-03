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

#ifndef YSS_DRV_DMA__H_
#define YSS_DRV_DMA__H_

#include "peripheral.h"

#if defined(STM32F4) || defined(GD32F4) || defined(STM32F7)
typedef volatile uint32_t		YSS_DMA_Peri;
typedef volatile uint32_t		YSS_DMA_Channel_Peri;
#include <targets/st_gigadevice/define_dma_stm32_gd32f4_f7.h>
#include <targets/st_gigadevice/map_dma_stm32_gd32f4_f7.h>
#elif defined(STM32F0_N) || defined(GD32F1) || defined(STM32F1_N)
typedef DMA_TypeDef				YSS_DMA_Peri;
typedef DMA_Channel_TypeDef		YSS_DMA_Channel_Peri;
#elif defined(STM32F4_N) || defined(STM32F7_N)
typedef DMA_TypeDef				YSS_DMA_Peri;
typedef DMA_Stream_TypeDef		YSS_DMA_Channel_Peri;
#elif defined(EFM32PG22) || defined(EFR32BG22)
typedef LDMA_TypeDef				YSS_DMA_Peri;
typedef LDMA_CH_TypeDef				YSS_DMA_Channel_Peri;
typedef LDMAXBAR_CH_TypeDef			YSS_DMA_Channel_Src;
#else
#define YSS_DRV_DMA_UNSUPPORTED
typedef volatile uint32_t		YSS_DMA_Peri;
typedef volatile uint32_t		YSS_DMA_Channel_Peri;
#endif

#include "Drv.h"
#include <yss/error.h>
#include <yss/thread.h>

class Dma : public Drv
{
  public:
	struct Config
	{
		YSS_DMA_Peri *dma;
		YSS_DMA_Channel_Peri *peri;
#if defined(EFM32PG22) || defined(EFR32BG22)
		YSS_DMA_Channel_Src *src;
		uint8_t channelNumber;
#endif
	};

	struct DmaInfo
	{
		uint32_t  controlRegister1;
		uint32_t  controlRegister2;
		uint32_t  controlRegister3;
		void *dataRegister;
	};

	Dma(const Drv::Config drvConfig, const Config dmaConfig);
	
	// DMA를 초기화 하는 함수이다.
	void initialize(void);

	// DMA로 데이터를 송신 또는 수신하는 함수이다. 데이터의 전송이 완료되거나 전송중 에러가 발생하면 반환된다.
	// 아래 send(), receive() 역활과 같은 역할을 한다. 최근 업데이트에서 send()와 receive() 함수의 구분이
	// 의미를 잃었다. 앞으로 이 함수가 전반적으로 사용될 예정이다.
	//
	// 반환
	//		발생한 error를 반환한다.
	// DmaInfo &dmaInfo
	//		DMA 전송 설정 정보이다. 
	// void *src
	//		전송할 데이터의 버퍼이다.
	// int32_t count
	//		전송할 데이터의 전체 갯수이다.
	error transfer(DmaInfo &dmaInfo, void *data, int32_t  count);

	// DMA로 데이터를 송/수신을 준비하는 함수이다. 데이터의 송/수신이 완료되거나 송/수신중 에러가 발생하면 반환된다.
	// 자체적으로 직접 전송을 시작하지는 않고, 하드웨어가 부가적인 흐름을 만들어야 하는 전송에서 사용된다.
	// 예를 들어 SD메모리에서 데이터 송/수신 명령이 전달되고 송/수신을 개시해야 하는 경우 등에서 사용된다.
	//
	// 반환
	//		발생한 error를 반환한다.
	// DmaInfo &dmaInfo
	//		DMA 전송 설정 정보이다. 
	// void *des
	//		수신할 데이터의 버퍼이다.
	// int32_t size
	//		수신할 데이터의 전체 크기이다.
	error ready(DmaInfo &dmaInfo, void *data, int32_t  size);

	// DMA로 데이터를 전송하는 함수이다. 데이터의 전송이 완료되거나 전송중 에러가 발생하면 반환된다.
	//
	// 반환
	//		발생한 error를 반환한다.
	// DmaInfo &dmaInfo
	//		DMA 전송 설정 정보이다. 
	// void *src
	//		전송할 데이터의 버퍼이다.
	// int32_t size
	//		전송할 데이터의 전체 크기이다.
	error send(DmaInfo &dmaInfo, void *src, int32_t  size);

	// DMA로 데이터를 수신하는 함수이다. 데이터의 수신이 완료되거나 수신중 에러가 발생하면 반환된다.
	//
	// 반환
	//		발생한 error를 반환한다.
	// DmaInfo &dmaInfo
	//		DMA 전송 설정 정보이다. 
	// void *des
	//		수신할 데이터의 버퍼이다.
	// int32_t size
	//		수신할 데이터의 전체 크기이다.
	error receive(DmaInfo &dmaInfo, void *des, int32_t  size);

	// 설정된 전송 버퍼를 DMA로 시작부터 끝까지 전송하면 자동으로 전송 버퍼의 시작으로
	// 되돌아가 버퍼의 데이터를 다시 전송한다. stop() 함수를 통해 중단 할 때까지 계속 전송한다.
	// setTransferCircularDataHandlerThreadId() 함수를 사용하여 데이터 핸들러의 Thread ID를 설정하면
	// 전송이 절반 또는 전체 전송이 완료 됐을 때, 해당 쓰레드로 자동 진입 한다.
	//
	// DmaInfo &dmaInfo
	//		DMA 전송 설정 정보이다. 
	// void *des
	//		전송할 데이터의 버퍼이다.
	// uint16_t size
	//		순환 버퍼의 전체 크기이다. 최대 크기는 0xFFFF이다.
	void transferAsCircularMode(const DmaInfo *dmaInfo, void *src, uint16_t size);
	
	// 현재 전송 중이거나 전송할 transferCircular() 함수의 버퍼 데이터를 처리해줄 쓰레드에서 
	// 한 차례 호출해주면 자동으로 해당 쓰레드의 ID가 등록된다.
	void setThreadIdOfTransferCircularDataHandler(void);

	// 현재 전송 카운트 숫자를 반환한다. transferAsCircularMode() 함수를 통해 데이터 전송을
	// 할 때에, 현재 채워야 하는 버퍼 카운트를 확인하기 위해 사용한다.
	uint16_t getCurrentTransferBufferCount(void);
	
	// 현재 데이터 전송을 중단한다.
	void stop(void);

	// 마지막 데이터 전송이 완료 됐는지 확인하는 함수이다.
	//
	// 반환
	//		마지막 데이터 전송이 완료됐을 경우 true를 반환한다.
	bool isComplete(void);

	// 마지막 데이터 전송에 에러가 발생했는지 확인하는 함수이다.
	//
	// 반환
	//		마지막 데이터 전송에 에러가 발생한 경우 true를 반환한다.
	bool isError(void);
	
	// 인터럽트 벡터에서 호출되는 함수이다.
	// 사용자 임의의 호출은 금지한다.
	virtual void isr(void) = 0;

  protected :
	YSS_DMA_Peri *mDma;
	YSS_DMA_Channel_Peri *mPeri;
#if defined(EFM32PG22) || defined(EFR32BG22)
	YSS_DMA_Channel_Src *mSrc;
	uint8_t mChannelNumber;
#endif
	bool mCompleteFlag, mErrorFlag;
	int32_t mRemainSize, mAddr;
	threadId mThreadId;
};

class DmaChannel1 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel1(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel2 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel2(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel3 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel3(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel4 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel4(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel5 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel5(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel6 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel6(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel7 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel7(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel8 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel8(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel9 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel9(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel10 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel10(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel11 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel11(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel12 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel12(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel13 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel13(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel14 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel14(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel15 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel15(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	virtual void isr(void);

};

class DmaChannel16 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel16(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

#endif

