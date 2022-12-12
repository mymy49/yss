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

#ifndef YSS_DRV_UART__H_
#define YSS_DRV_UART__H_

#include "mcu.h"

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4) || defined(GD32F4)  || defined(STM32F7) || defined(STM32F0)

typedef volatile uint32_t	YSS_USART_Peri;

#elif defined(NRF52840_XXAA)

typedef NRF_UART_Type		YSS_USART_Peri;

#else

#define YSS_DRV_UART_UNSUPPORTED

#endif

#ifndef YSS_DRV_UART_UNSUPPORTED

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

class Uart : public Drv
{
	YSS_USART_Peri *mPeri;
	int8_t *mRcvBuf;
	int32_t  mRcvBufSize;
	int32_t  mTail, mHead;
	bool mOneWireModeFlag;
	void (*mCallbackForFrameError)(void);

#if !defined(YSS_DRV_DMA_UNSUPPORTED)
	Dma *mTxDma;
	Dma::DmaInfo mTxDmaInfo;
#endif

  public:
#if !defined(YSS_DRV_DMA_UNSUPPORTED)
	struct Config
	{
		YSS_USART_Peri *peri;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
	};
#else
	struct Config
	{
		YSS_USART_Peri *peri;
	};
#endif

	Uart(const Drv::Config drvConfig, const Config config);
	Uart(YSS_USART_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), uint32_t (*getClockFreq)(void));
	
	// UART 장치를 송신 전용으로 초기화 한다.
	// 
	// 반환
	//		에러를 반환한다.
	// int32_t baud
	//		통신 보레이트를 설정한다.
	error initializeAsTransmitterOnly(int32_t baud);

	// UART 장치를 송신/수신이 가능하도록 초기화 한다. 수신 버퍼의 크기를 입력하면 초기화 함수 내부에서
	// hmalloc을 이용해 메모리를 할당 받는다.
	//
	// 반환
	//		에러를 반환한다.
	// int32_t baud
	//		통신 보레이트를 설정한다.
	// int32_t  receiveBufferSize
	//		내부 수신 링버퍼의 크기를 설정한다.
	error initialize(int32_t  baud, int32_t  receiveBufferSize);

	// UART 장치를 송신/수신이 가능하도록 초기화 한다. 사용자가 별도로 확보한 메모리를 수신 버퍼로 설정한다.
	// 수신 버퍼의 크기도 지정해줘야 한다.
	//
	// 반환
	//		에러를 반환한다.
	// int32_t baud
	//		통신 보레이트를 설정한다.
	// void *receiveBuffer
	//		사용자가 직접 확보한 내부 수신 버퍼 메모리를 설정한다.
	// int32_t  receiveBufferSize
	//		receiveBuffer에서 사용자가 설정한 버퍼의 크기를 설정한다.
	error initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize);

	// UART 장치가 동작중에 보레이트를 변경하기 위해 사용된다.
	//
	// 반환
	//		에러를 반환한다.
	// int32_t baud
	//		변경할 통신 보레이트를 설정한다.
	error changeBaudrate(int32_t baud);

	// 수신된 바이트를 얻는다.
	// 
	// 반환
	//		16비트 자료형으로 수신된 바이트가 없을 경우 -1(0xFFFF)을 반환한다.
	//		수신된 바이트가 있을 경우 0과 같거나 크고 0x0000 ~ 0x00FF의 크기를 갖는다.
	//		바이트 부분만 활용하면 된다.
	int16_t getReceivedByte(void);

	// 위에 나타낸 getReceivedByte()와 동일하다.
	// 본 함수는 과거 작성된 프로젝트의 호환성을 위해 일시적으로 지원하므로 신규 코드 작성에 사용을 권하지 않는다.
	int16_t get(void);
	
	// 데이터 수신이 있을 때까지 대기한다. 대기하는 동안은 함수 내에서 thread::yield() 함수를 이용해 대기한다.
	// 
	// 반환
	//		수신된 바이트를 반환한다.
	int8_t getWaitUntilReceive(void);

	// 수신 버퍼를 비운다.
	void flush(void);
	
	// Frame Error 발생시 호출될 Callback 함수를 설정한다.
	//
	// void (*func)(void)
	//		Callback 함수를 설정한다.
	void setCallbackForFrameError(void (*callback)(void));
	
	// 복수의 데이터를 송신한다.
	// 
	// 반환
	//		에러를 반환한다.
	// void *src
	//		송신할 데이터 버퍼의 포인터를 설정한다.
	// int32_t size
	//		송신할 데이터의 크기를 설정한다.
	error send(void *src, int32_t  size);

	// 복수의 데이터를 송신한다.
	// 
	// 반환
	//		에러를 반환한다.
	// const void *src
	//		송신할 데이터 버퍼의 포인터를 설정한다.
	// int32_t size
	//		송신할 데이터의 크기를 설정한다.
	error send(const void *src, int32_t  size);

	// 하나의 바이트 데이터를 송신한다.
	// 
	// int8_t data
	//		송신할 데이터 바이트를 설정한다.
	void send(int8_t data);

	// UART를 One Wire 모드 동작을 활성화 시킬 때 사용한다.
	// 송신 데이터가 수신 데이터로 들어오는 것을 막아준다.
	//
	// bool en
	//		One Wire 모드의 활성화를 설정한다. (true - 활성화, false - 비활성화)
	void setOneWireMode(bool en);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	void push(int8_t data);
	void isr(void);
};

#endif

#endif

// 초기화 방법
//		- GPIO의 setAsAltFunc()함수를 사용해 관련된 포트를 UART 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 장치의 수신 버퍼와 보레이트를 설정하고 장치를 활성화 시킨다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다.



