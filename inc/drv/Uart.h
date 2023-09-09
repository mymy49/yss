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

#ifndef YSS_DRV_UART__H_
#define YSS_DRV_UART__H_

#include "peripheral.h"

#if defined(STM32F1) || defined(STM32F4) || defined(GD32F4)  || defined(STM32F0)

typedef volatile uint32_t	YSS_USART_Peri;

#elif defined(NRF52840_XXAA)

typedef NRF_UART_Type		YSS_USART_Peri;

#elif defined(EFM32PG22) || defined(EFR32BG22) || defined(STM32F4_N) || defined(STM32F0_N) || defined(STM32F7_N) || defined(STM32F1_N) || defined(GD32F1)

typedef USART_TypeDef		YSS_USART_Peri;

#else

#include <stdint.h>
typedef volatile uint32_t	YSS_USART_Peri;

#define YSS_DRV_UART_UNSUPPORTED

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

class Uart : public Drv
{
  public:
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

	// UART 장치의 Stop Bit 길이를 설정한다.
	//
	// 반환
	//		에러를 반환한다.
	// int8_t stopBit
	//		Stop Bit를 설정한다. define::uart::stopBit에 정의된 항목을 사용한다.
	error setStopBit(int8_t stopBit);

	// 수신된 바이트를 얻는다.
	// 
	// 반환
	//		16비트 자료형으로 수신된 바이트가 없을 경우 -1(0xFFFF)을 반환한다.
	//		수신된 바이트가 있을 경우 0과 같거나 크고 0x0000 ~ 0x00FF의 크기를 갖는다.
	//		바이트 부분만 활용하면 된다.
	int16_t getRxByte(void);

	// 위에 나타낸 getRxByte()와 동일하다.
	// 본 함수는 과거 작성된 프로젝트의 호환성을 위해 일시적으로 지원하므로 신규 코드 작성에 사용을 권하지 않는다.
	int16_t get(void);
	
	// 수신되서 버퍼에 담겨진 데이터의 개수를 반환한다.
	// 
	// 반환
	//		수신된 바이트의 개수를 반환한다.
	uint32_t getRxCount(void);

	// 수신된 버퍼중에 가장 먼저 수신된 버퍼의 데이터 포인터를 반환한다. 다음에 수신된 데이터는 다음 번지에 놓여 있다.
	// 접근 가능한 다음 유효 번지는 geRxCount() 함수의 반환 값까지 접근 가능하다.
	// 
	// 반환
	//		수신된 바이트의 버퍼 포인터를 반환한다.
	void* getRxBuffer(void);
	
	// 수신된 데이터를 getRxBuffer() 함수를 사용해 접근할 경우 현재 수신한 데이터의 처리를 하고, 버퍼에서 다음 수신된 버퍼로 넘어가기 위한 함수이다.
	// 
	// uint32_t count
	//		현재 링버퍼의 포인터를 count에 설정된 포인터만큼 다음 포인터로 이동시킨다.
	void releaseRxBuffer(uint32_t count);

	// 데이터 수신이 있을 때까지 대기한다. 대기하는 동안은 함수 내에서 thread::yield() 함수를 이용해 대기한다.
	// 
	// 반환
	//		수신된 바이트를 반환한다.
	uint8_t getWaitUntilReceive(void);

	// 수신 버퍼를 비운다.
	void flush(void);
	
	// Frame Error 발생시 호출될 Interrupt Service Routine(ISR) 함수를 설정한다.
	//
	// void (*isr)(void)
	//		ISR 함수를 설정한다.
	void setIsrForFrameError(void (*isr)(void));

	// 데이터 수신시 호출될 Interrupt Service Routine(ISR) 함수를 설정한다.
	//
	// void (*isr)(void)
	//		ISR 함수를 설정한다.
	void setIsrForRxData(void (*isr)(uint8_t rxData));
	
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
	
	// UART를 일시적으로 활성화/비활성화 시킬 수 있게 한다.
	// intialize() 함수에서 기본적으로 활성화 되어 있다.
	//
	// bool en
	//		활성화(true)/비활성화(false)로 설정한다.
	void enable(bool en);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
#if defined(GD32F1) || defined(STM32F1_N) || defined(STM32F4) || defined(GD32F4)  || defined(STM32F7_N) || defined(STM32F4_N) || defined(STM32F0_N)
	struct Setup
	{
		YSS_USART_Peri *dev;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
	};
#elif defined(EFM32PG22) || defined(EFR32BG22)
	struct Config
	{
		YSS_USART_Peri *dev;
		Dma **dmaChannelList;
		const Dma::DmaInfo *txDmaInfo;
	};
#elif defined(NRF52840_XXAA)
	struct Config
	{
		YSS_USART_Peri *dev;
	};
#endif	

	Uart(const Drv::Setup drvSetup, const Uart::Setup setup);

	void push(int8_t data);

	void isr(void);

protected:
	YSS_USART_Peri *mDev;
	int8_t *mRcvBuf;
	int32_t  mRcvBufSize;
	int32_t  mTail, mHead;
	bool mOneWireModeFlag;
	void (*mIsrForFrameError)(void);
	void (*mIsrForRxData)(uint8_t rxData);

#if defined(GD32F1) || defined(STM32F1_N) || defined(GD32F4)  || defined(STM32F7_N) || defined(STM32F0_N) || defined(STM32F4_N)
	Dma *mTxDma;
	Dma::DmaInfo mTxDmaInfo;
#elif defined(EFM32PG22) || defined(EFR32BG22)
	Dma **mDmaChannelList;
	const Dma::DmaInfo *mTxDmaInfo;
#endif
};

#endif

// 초기화 방법
//		- GPIO의 setAsAltFunc()함수를 사용해 관련된 포트를 UART 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 장치의 수신 버퍼와 보레이트를 설정하고 장치를 활성화 시킨다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다.

// 전송 방법
//		- lock() 함수를 호출하여 다른 쓰레드에서 접근을 막는다.
//		- send() 함수를 이용하여 한 바이트 또는 여러 바이트를 전송한다.
//		- unlock() 함수를 호출하여 현재 소유권을 해제하고 다른 쓰레드에게 접근을 개방한다.

// 수신 방법 (getRxByte() 함수 사용)
//		- getRxByte()를 호출하고 반환된 값이 0 이상일 경우 수신데이터로 취급하고 처리한다.
//		- 음수일 경우 리턴된 값을 무시한다.

// 수신 방법 (getWaitUntilReceive() 함수 사용
//		- getWaitUntilReceive()를 호출하면 호출한 시점에서 수신이 있기 까지 리턴되지 않는다.
//		- 리턴이 있을 때 마다 수신 데이터를 처리한다.
//		- 호출한 시점부터 수신된 바이트가 발생할 때까지 리턴되지 않으므로 루프상의 처리에 주의해야 한다.

