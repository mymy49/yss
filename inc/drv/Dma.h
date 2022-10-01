////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
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

#ifndef YSS_DRV_DMA__H_
#define YSS_DRV_DMA__H_

#include "mcu.h"
#include "Drv.h"

#if defined(STM32F1)
typedef DMA_TypeDef				YSS_DMA_Peri;
typedef DMA_Channel_TypeDef		YSS_DMA_Channel_Peri;
#include "dma/define_dma_stm32f1.h"
#include "dma/map_dma_stm32f1.h"
#elif defined(STM32F4) || defined(STM32F7)
typedef DMA_TypeDef				YSS_DMA_Peri;
typedef DMA_Stream_TypeDef		YSS_DMA_Channel_Peri;
#include "dma/define_dma_stm32f4_f7.h"
#include "dma/map_dma_stm32f4_f7.h"
#elif defined(STM32G4)
typedef DMA_TypeDef				YSS_DMA_Peri;
typedef DMA_Channel_TypeDef		YSS_DMA_Channel_Peri;
#include "dma/define_dma_stm32g4.h"
#include "dma/map_dma_stm32g4.h"
#elif defined(GD32F1)
typedef volatile uint32_t	YSS_DMA_Peri;
typedef volatile uint32_t	YSS_DMA_Channel_Peri;
#include "dma/define_dma_gd32f1.h"
#include "dma/map_dma_gd32f1.h"
#elif defined (GD32F450)
typedef uint32_t			YSS_DMA_Peri;
typedef uint32_t			YSS_DMA_Channel_Peri;
#include "dma/define_dma_gd32f4.h"
#include "gd32f4xx_dma.h"
#else
#define YSS_DRV_DMA_UNSUPPORTED
#endif

#ifndef YSS_DRV_DMA_UNSUPPORTED

#include <drv/Drv.h>
#include <yss/thread.h>
#include <yss/error.h>

class Dma : public Drv
{
  protected :
	YSS_DMA_Peri *mDma;
	YSS_DMA_Channel_Peri *mPeri;
	bool mCompleteFlag, mErrorFlag;
	int32_t  mRemainSize, mAddr, mThreadId;

  public:
	struct Config
	{
		YSS_DMA_Peri *dma;
		YSS_DMA_Channel_Peri *peri;
	};

	struct DmaInfo
	{
		int32_t  controlRegister1;
		int32_t  controlRegister2;
		int32_t  controlRegister3;
		void *dataRegister;
	};

	Dma(const Drv::Config drvConfig, const Config dmaConfig);

	void init(void);
	error transfer(DmaInfo &dmaInfo, void *data, int32_t  size);
	void ready(DmaInfo &dmaInfo, void *data, int32_t  size);

	error send(DmaInfo &dmaInfo, void *src, int32_t  size);
	error receive(DmaInfo &dmaInfo, void *des, int32_t  size);

	void stop(void);
	bool isComplete(void);
	bool isError(void);

	virtual void isr(void) = 0;
};

class DmaChannel1 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel1(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel2 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel2(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel3 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel3(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel4 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel4(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel5 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel5(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel6 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel6(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel7 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel7(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel8 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel8(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel9 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel9(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel10 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel10(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel11 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel11(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel12 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel12(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel13 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel13(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel14 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel14(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
};

class DmaChannel15 : public Dma
{

  protected:

  public :
	struct Config
	{
	};

	DmaChannel15(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config);

	void isr(void);
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

#endif

