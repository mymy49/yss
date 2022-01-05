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
// 주담당자 : 아이구 (mymy49@nate.com) 2021.03.10 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>
#include <yss/instance.h>

#if defined(STM32F7)

#include <config.h>

static unsigned int getApb2ClkFreq(void)
{
	return clock.getApb2ClkFreq();
}

static unsigned int getApb1ClkFreq(void)
{
	return clock.getApb1ClkFreq();
}



#if defined(USART1) && defined(UART1_ENABLE)
static void setUart1ClockEn(bool en)
{
	clock.peripheral.setUart1En(en);
}

static void setUart1IntEn(bool en)
{
	nvic.setUart1En(en);
}

static void resetUart1(void)
{
	clock.peripheral.resetUart1();
}

static const Drv::Config gDrvUart1Config
{
	setUart1ClockEn,	//void (*clockFunc)(bool en);
	setUart1IntEn,		//void (*nvicFunc)(bool en);
	resetUart1			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gUart1DmaInfoTx = 
{
	define::dma2::stream7::USART1_TX,	//unsigned char channelNumber;
	(void*)&USART1->TDR,				//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Uart::Config gUart1Config
{
	USART1,				//YSS_USART_Peri *peri;
	dmaChannel16,		//Dma txDma;
	gUart1DmaInfoTx,	//Dma::DmaInfo txDmaInfo;
	getApb2ClkFreq,		//unsigned int (*getClockFreq)(void);
};

drv::Uart uart1(gDrvUart1Config, gUart1Config);

extern "C"
{
	void USART1_IRQHandler(void)
	{
		uart1.isr();
	}
}
#endif



#if defined(USART2) && defined(UART2_ENABLE)
static void setUart2ClockEn(bool en)
{
	clock.peripheral.setUart2En(en);
}

static void setUart2IntEn(bool en)
{
	nvic.setUart2En(en);
}

static void resetUart2(void)
{
	clock.peripheral.resetUart2();
}

static const Drv::Config gDrvUart2Config
{
	setUart2ClockEn,	//void (*clockFunc)(bool en);
	setUart2IntEn,		//void (*nvicFunc)(bool en);
	resetUart2			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gUart2DmaInfoTx = 
{
	define::dma1::stream6::USART2_TX,	//unsigned char channelNumber;
	(void*)&USART2->TDR,				//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Uart::Config gUart2Config
{
	USART2,				//YSS_USART_Peri *peri;
	dmaChannel7,		//Dma txDma;
	gUart2DmaInfoTx,	//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,		//unsigned int (*getClockFreq)(void);
};

drv::Uart uart2(gDrvUart2Config, gUart2Config);

extern "C"
{
	void USART2_IRQHandler(void)
	{
		uart2.isr();
	}
}
#endif



#if defined(USART3) && defined(UART3_ENABLE)
static void setUart3ClockEn(bool en)
{
	clock.peripheral.setUart3En(en);
}

static void setUart3IntEn(bool en)
{
	nvic.setUart3En(en);
}

static void resetUart3(void)
{
	clock.peripheral.resetUart3();
}

static const Drv::Config gDrvUart3Config
{
	setUart3ClockEn,	//void (*clockFunc)(bool en);
	setUart3IntEn,		//void (*nvicFunc)(bool en);
	resetUart3			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gUart3DmaInfoTx = 
{
	define::dma1::stream3::USART3_TX,	//unsigned char channelNumber;
	(void*)&USART3->TDR,				//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Uart::Config gUart3Config
{
	USART3,				//YSS_USART_Peri *peri;
	dmaChannel4,		//Dma txDma;
	gUart3DmaInfoTx,	//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,		//unsigned int (*getClockFreq)(void);
};

drv::Uart uart3(gDrvUart3Config, gUart3Config);

extern "C"
{
	void USART3_IRQHandler(void)
	{
		uart3.isr();
	}
}
#endif



#if defined(UART4) && defined(UART4_ENABLE)
static void setUart4ClockEn(bool en)
{
	clock.peripheral.setUart4En(en);
}

static void setUart4IntEn(bool en)
{
	nvic.setUart4En(en);
}

static void resetUart4(void)
{
	clock.peripheral.resetUart4();
}

static const Drv::Config gDrvUart4Config
{
	setUart4ClockEn,	//void (*clockFunc)(bool en);
	setUart4IntEn,		//void (*nvicFunc)(bool en);
	resetUart4			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gUart4DmaInfoTx = 
{
	define::dma1::stream4::UART4_TX,	//unsigned char channelNumber;
	(void*)&UART4->TDR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Uart::Config gUart4Config
{
	UART4,				//YSS_USART_Peri *peri;
	dmaChannel5,		//Dma txDma;
	gUart4DmaInfoTx,	//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,		//unsigned int (*getClockFreq)(void);
};

drv::Uart uart4(gDrvUart4Config, gUart4Config);

extern "C"
{
	void UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}
#endif



#if defined(UART5) && defined(UART5_ENABLE)
static void setUart5ClockEn(bool en)
{
	clock.peripheral.setUart5En(en);
}

static void setUart5IntEn(bool en)
{
	nvic.setUart5En(en);
}

static void resetUart5(void)
{
	clock.peripheral.resetUart5();
}

static const Drv::Config gDrvUart5Config
{
	setUart5ClockEn,	//void (*clockFunc)(bool en);
	setUart5IntEn,		//void (*nvicFunc)(bool en);
	resetUart5			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gUart5DmaInfoTx = 
{
	define::dma1::stream7::UART5_TX,	//unsigned char channelNumber;
	(void*)&UART5->TDR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Uart::Config gUart5Config
{
	UART5,				//YSS_USART_Peri *peri;
	dmaChannel8,		//Dma txDma;
	gUart5DmaInfoTx,	//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,		//unsigned int (*getClockFreq)(void);
};

drv::Uart uart5(gDrvUart5Config, gUart5Config);

extern "C"
{
	void UART5_IRQHandler(void)
	{
		uart5.isr();
	}
}
#endif



#if defined(USART6) && defined(UART6_ENABLE)
static void setUart6ClockEn(bool en)
{
	clock.peripheral.setUart6En(en);
}

static void setUart6IntEn(bool en)
{
	nvic.setUart6En(en);
}

static void resetUart6(void)
{
	clock.peripheral.resetUart6();
}

static const Drv::Config gDrvUart6Config
{
	setUart6ClockEn,	//void (*clockFunc)(bool en);
	setUart6IntEn,		//void (*nvicFunc)(bool en);
	resetUart6			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gUart6DmaInfoTx = 
{
	define::dma2::stream6::USART6_TX,	//unsigned char channelNumber;
	(void*)&USART6->TDR,				//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Uart::Config gUart6Config
{
	USART6,				//YSS_USART_Peri *peri;
	dmaChannel15,		//Dma txDma;
	gUart6DmaInfoTx,	//Dma::DmaInfo txDmaInfo;
	getApb2ClkFreq,		//unsigned int (*getClockFreq)(void);
};

drv::Uart uart6(gDrvUart6Config, gUart6Config);

extern "C"
{
	void USART6_IRQHandler(void)
	{
		uart6.isr();
	}
}
#endif



#if defined(UART7) && defined(UART7_ENABLE)
static void setUart7ClockEn(bool en)
{
	clock.peripheral.setUart7En(en);
}

static void setUart7IntEn(bool en)
{
	nvic.setUart7En(en);
}

static void resetUart7(void)
{
	clock.peripheral.resetUart7();
}

static const Drv::Config gDrvUart7Config = 
{
	setUart7ClockEn,	//void (*clockFunc)(bool en);
	setUart7IntEn,		//void (*nvicFunc)(bool en);
	resetUart7			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gUart7DmaInfoTx = 
{
	define::dma1::stream1::UART7_TX,	//unsigned char channelNumber;
	(void*)&UART7->TDR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Uart::Config gUart7Config = 
{
	UART7,				//YSS_USART_Peri *peri;
	dmaChannel8,		//Dma txDma;
	gUart7DmaInfoTx,	//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,		//unsigned int (*getClockFreq)(void);
};

drv::Uart uart7(gDrvUart7Config, gUart7Config);

extern "C"
{
	void UART7_IRQHandler(void)
	{
		uart7.isr();
	}
}
#endif

#if defined(UART8) && defined(UART8_ENABLE)
static void setUart8ClockEn(bool en)
{
	clock.peripheral.setUart8En(en);
}

static void setUart8IntEn(bool en)
{
	nvic.setUart8En(en);
}

static void resetUart8(void)
{
	clock.peripheral.resetUart8();
}

static const Drv::Config gDrvUart8Config = 
{
	setUart8ClockEn,	//void (*clockFunc)(bool en);
	setUart8IntEn,		//void (*nvicFunc)(bool en);
	resetUart8			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gUart8DmaInfoTx = 
{
	define::dma1::stream0::UART8_TX,	//unsigned char channelNumber;
	(void*)&UART8->TDR,					//void *dataRegister;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	define::dma::size::BYTE,			//unsigned char peripheralDataSize;
	define::dma::size::BYTE				//unsigned char memoryDataSize;
};

static const drv::Uart::Config gUart8Config = 
{
	UART8,				//YSS_USART_Peri *peri;
	dmaChannel8,		//Dma txDma;
	gUart7DmaInfoTx,	//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,		//unsigned int (*getClockFreq)(void);
};

drv::Uart uart8(gDrvUart8Config, gUart8Config);

extern "C"
{
	void UART8_IRQHandler(void)
	{
		uart8.isr();
	}
}
#endif

#endif

