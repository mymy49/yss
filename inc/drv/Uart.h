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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_UART__H_
#define YSS_DRV_UART__H_

#include "peripheral.h"

#if defined(NRF52840_XXAA)

typedef NRF_UART_Type		YSS_USART_Typedef;

#elif defined(EFM32PG22) || defined(EFR32BG22) || defined(STM32F4) || defined(STM32F0) || defined(STM32F7) || defined(STM32F1) || defined(GD32F1) || defined(STM32G4)

typedef USART_TypeDef		YSS_USART_Typedef;

#elif defined(W7500)

typedef UART_TypeDef		YSS_USART_Typedef;

#else

#include <stdint.h>
typedef volatile uint32_t	YSS_USART_Typedef;

#define YSS_DRV_UART_UNSUPPORTED

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

class Uart : public Drv
{
public:
	typedef enum
	{
		STOP_1BIT = 0,
		STOP_2BIT = 1
	}stopbit_t;

	// UART 장치를 송신 전용으로 초기화합니다.
	// stopbit는 1비트로 설정됩니다. 필요시 setStopBit() 함수로 변경이 가능합니다.
	// 
	// 반환
	//		에러를 반환합니다.
	// int32_t baud
	//		통신 보레이트를 설정합니다.
	error_t initializeAsTransmitterOnly(int32_t baud) __attribute__((optimize("-O1")));

	// UART 장치를 송신/수신이 가능하도록 초기화합니다. 수신 버퍼의 크기를 입력하면 초기화 함수 내부에서
	// hmalloc을 이용해 메모리를 할당 받습니다.
	// stopbit는 1비트로 설정됩니다. 필요시 setStopBit() 함수로 변경이 가능합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// int32_t baud
	//		통신 보레이트를 설정합니다.
	// int32_t  receiveBufferSize
	//		내부 수신 링버퍼의 크기를 설정합니다.
	error_t initialize(int32_t  baud, int32_t  receiveBufferSize) __attribute__((optimize("-O1")));

	// UART 장치를 송신/수신이 가능하도록 초기화합니다. 사용자가 별도로 확보한 메모리를 수신 버퍼로 설정합니다.
	// 수신 버퍼의 크기도 설정해줘야 합니다.
	// stopbit는 1비트로 설정됩니다. 필요시 setStopBit() 함수로 변경이 가능합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// int32_t baud
	//		통신 보레이트를 설정합니다.
	// void *receiveBuffer
	//		사용자가 직접 확보한 내부 수신 버퍼 메모리를 설정합니다.
	// int32_t  receiveBufferSize
	//		receiveBuffer에서 사용자가 설정한 버퍼의 크기를 설정합니다.
	error_t initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize) __attribute__((optimize("-O1")));

	// UART 장치가 동작중에 보레이트를 변경하기 위해 사용됩니다.
	//
	// 반환
	//		에러를 반환합니다.
	// int32_t baud
	//		변경할 통신 보레이트를 설정합니다.
	error_t changeBaudrate(int32_t baud) __attribute__((optimize("-O1")));

	// UART 장치의 Stop Bit의 길이를 설정합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// stopbit_t stopBit
	//		Stop Bit를 설정합니다.
	error_t setStopBit(stopbit_t stopBit) __attribute__((optimize("-O1")));

	// 수신된 바이트를 얻습니다.
	// 
	// 반환
	//		16비트 자료형으로 수신된 바이트가 없을 경우 -1(0xFFFF)을 반환합니다.
	//		수신된 바이트가 있을 경우 0과 같거나 크고 0x0000 ~ 0x00FF의 크기를 갖습니다.
	//		그러므로 하위 8비트 부분만 사용하면 됩니다.
	int16_t getRxByte(void) __attribute__((optimize("-O1")));

	// 위에 나타낸 getRxByte()와 동일합니다.
	// 본 함수는 과거 작성된 프로젝트의 호환성을 위해 일시적으로 지원하므로 신규 코드 작성에 사용을 권장하지 않습니다.
	int16_t get(void) __attribute__((optimize("-O1")));
	
	// 수신되서 버퍼에 담겨진 데이터의 개수를 반환합니다.
	// 
	// 반환
	//		수신된 바이트의 개수를 반환합니다.
	uint32_t getRxCount(void) __attribute__((optimize("-O1")));

	// 수신된 버퍼중에 가장 먼저 수신된 버퍼의 데이터 포인터를 반환합니다. 다음에 수신된 데이터는 다음 번지에 놓여 있습니다.
	// 접근 가능한 다음 유효 번지는 geRxCount() 함수의 반환 값까지 접근 가능합니다.
	// 
	// 반환
	//		수신된 바이트의 버퍼 포인터를 반환합니다.
	void* getRxBuffer(void) __attribute__((optimize("-O1")));
	
	// getRxCount() 함수와 getRxBuffer() 함수를 통해 수신 데이터의 처리를 완료하고 그 버퍼를 비우는 함수입니다.
	// 반드시 이 함수를 사용해 비워줘야 계속 데이터의 수신이 가능합니다. 
	// getRxCount() 함수에서 받은 용량만큼만 비워줘야 합니다. 
	// 
	// uint32_t count
	//		반드시 getRxCount() 함수에서 받은 값을 그대로 설정합니다.
	void releaseRxBuffer(uint32_t count) __attribute__((optimize("-O1")));

	// 데이터 수신이 있을 때까지 대기합니다.
	// 대기하는 동안은 함수 내부에서는 유휴시간동안 thread::yield() 함수를 호출해서 대기합니다.
	// 
	// 반환
	//		수신된 바이트를 반환합니다.
	uint8_t getWaitUntilReceive(void) __attribute__((optimize("-O1")));

	// 수신 버퍼를 비웁니다.
	void flush(void) __attribute__((optimize("-O1")));
	
	// Frame Error에 대한 ISR 함수를 등록합니다.
	// ISR 함수에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
	// yss.h 파일에서 문맥전환을 유발하는 함수 유형의 설명을 참고하세요.
	// yss.h 파일에서 ISR 함수와 Callback 함수에 대한 구분 설명을 참고하세요. 
	//
	// void (*isr)(void)
	//		ISR 함수의 포인터를 설정합니다.
	void setIsrForFrameError(void (*isr)(void)) __attribute__((optimize("-O1")));

	// 데이터 수신에 대한 ISR 함수를 등록합니다.
	// ISR 함수에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
	// yss.h 파일에서 문맥전환을 유발하는 함수 유형의 설명을 참고하세요.
	// yss.h 파일에서 ISR 함수와 Callback 함수에 대한 구분 설명을 참고하세요. 
	//
	// void (*isr)(void)
	//		ISR 함수의 포인터를 설정합니다.
	void setIsrForRxData(void (*isr)(uint8_t rxData)) __attribute__((optimize("-O1")));
	
	// 복수의 데이터를 송신합니다.
	// 
	// 반환
	//		에러를 반환합니다.
	// void *src
	//		송신할 데이터 버퍼의 포인터를 설정합니다.
	// int32_t size
	//		송신할 데이터의 크기를 설정합니다.
	error_t send(void *src, int32_t  size) __attribute__((optimize("-O1")));

	// 복수의 데이터를 송신합니다.
	// 
	// 반환
	//		에러를 반환합니다.
	// const void *src
	//		송신할 데이터 버퍼의 포인터를 설정합니다.
	// int32_t size
	//		송신할 데이터의 크기를 설정합니다.
	error_t send(const void *src, int32_t  size) __attribute__((optimize("-O1")));

	// 한 바이트를 송신합니다.
	// 
	// int8_t data
	//		송신할 데이터 바이트를 설정합니다.
	void send(int8_t data) __attribute__((optimize("-O1")));

	// UART를 One Wire 모드 동작을 활성화 시킬 때 사용합니다.
	// 송신 데이터가 수신 데이터로 들어오는 것을 막아줍니다.
	//
	// bool en
	//		One Wire 모드의 활성화를 설정합니다. (true - 활성화, false - 비활성화)
	void setOneWireMode(bool en) __attribute__((optimize("-O1")));
	
	// UART를 일시적으로 활성화/비활성화 시킬 수 있게 합니다.
	// intialize() 함수를 호출하면 기본 상태가 활성화입니다.
	//
	// bool en
	//		활성화(true)/비활성화(false)로 설정합니다.
	void enable(bool en) __attribute__((optimize("-O1")));

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	struct setup_t
	{
#if defined(GD32F1) || defined(STM32F1) || defined(GD32F4)  || defined(STM32F7) || defined(STM32F4) || defined(STM32F0)
		YSS_USART_Typedef *dev;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
#elif defined(EFM32PG22) || defined(EFR32BG22) || defined(STM32G4)
		YSS_USART_Typedef *dev;
		Dma::DmaInfo txDmaInfo;
		Dma::DmaInfo rxDmaInfo;
#elif defined(NRF52840_XXAA) || defined(W7500)
		YSS_USART_Typedef *dev;
#endif
	};

	Uart(const Drv::setup_t drvSetup, const Uart::setup_t setup) __attribute__((optimize("-O1")));

	void push(int8_t data) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

protected:
	YSS_USART_Typedef *mDev;
	int8_t *mRcvBuf;
	int32_t  mRcvBufSize;
	bool mOneWireModeFlag;
	void (*mIsrForFrameError)(void);
	void (*mIsrForRxData)(uint8_t rxData);

#if defined(YSS__UART_RX_DMA)
	int32_t  mTail;
	Dma *mRxDma;
	Dma::DmaInfo mTxDmaInfo;
	Dma::DmaInfo mRxDmaInfo;
#else
	int32_t  mTail, mHead;
	Dma *mTxDma;
	Dma::DmaInfo mTxDmaInfo;
#endif
};

#endif

// 초기화 방법
//		- GPIO의 setAsAltFunc()함수를 사용해 관련된 포트를 UART 포트로 변경합니다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급합니다.
//		- initialize() 함수를 사용해 장치의 수신 버퍼와 보레이트를 설정하고 장치를 활성화 시킵니다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화합니다.

// 전송 방법
//		- lock() 함수를 호출하여 다른 쓰레드에서 접근을 막습니다.
//		- send() 함수를 이용하여 한 바이트 또는 여러 바이트를 전송합니다.
//		- unlock() 함수를 호출하여 현재 소유권을 해제하고 다른 쓰레드에게 접근을 개방합니다.

// 수신 방법 (getRxByte() 함수 사용)
//		- getRxByte()를 호출하고 반환된 값이 0 이상일 경우 수신데이터로 취급하고 처리합니다.
//		- 음수일 경우 리턴된 값을 무시합니다.

// 수신 방법 (getWaitUntilReceive() 함수 사용
//		- getWaitUntilReceive()를 호출하면 호출한 시점에서 수신이 있기 까지 리턴되지 않습니다.
//		- 리턴이 있을 때 마다 수신 데이터를 처리합니다.
//		- 호출한 시점부터 수신된 바이트가 발생할 때까지 리턴되지 않으므로 루프상의 처리에 주의해야 합니다.

