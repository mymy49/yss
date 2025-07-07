/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_UART__H_
#define YSS_DRV_UART__H_

#include "peripheral.h"

#if defined(NRF52840_XXAA)

typedef NRF_UART_Type		YSS_USART_Typedef;

#elif defined(EFM32PG22) || defined(EFR32BG22) || defined(STM32F4) || defined(STM32F0) || defined(STM32F7) || defined(STM32F1) || defined(GD32F1) || defined(STM32G4)

typedef USART_TypeDef		YSS_USART_Typedef;

#elif defined(W7500)

typedef UART_TypeDef		YSS_USART_Typedef;

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

typedef UART_T				YSS_USART_Typedef;

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
		MODE_NORMAL,	// 일반적인 Tx, Rx가 가능한 모드입니다.
		MODE_TX_ONLY,	// Tx만 가능한 모드 입니다.
		MODE_RX_ONLY,	// Rx만 가능한 모드 입니다.
		MODE_ONE_WIRE	// 1선으로 반이중 전송을 위한 모드입니다.
	}mode_t;

	typedef enum
	{
		STOP_1BIT = 0,
		STOP_2BIT = 1
	}stopbit_t;

	typedef struct
	{
		mode_t mode;			// 동작 모드의 종류를 설정합니다.
		uint32_t baudrate;		// 보레이트를 설정합니다.
		stopbit_t stopbit;		// Stop Bit의 종류를 설정합니다.
		void *rcvBuf;			// 수신 버퍼를 지정합니다.
		uint32_t rcvBufSize;	// 수신 버퍼의 크기를 지정합니다.
	}config_t;
	
	/*	
		UART 장치를 설정한 모드로 초기화 합니다.
		config_t의 rcvBuf 항목이 nullptr로 설정될 경우 자동으로 rcvBufSize에 지정된 용량으로 메모리를 할당해줍니다. 
		.
		@ return : 에러를 반환합니다.
		.
		@ config : UART의 구성을 설정합니다.
	*/
	error_t initialize(config_t config) __attribute__((optimize("-O1")));

	/*
		UART 장치가 동작중에 보레이트를 변경하기 위해 사용됩니다.
		.
		@ return : 에러를 반환합니다.
		@ buadrate : 변경할 통신 보레이트를 설정합니다.
	*/
	error_t changeBaudrate(int32_t buadrate) __attribute__((optimize("-O1")));
	
	/*
		수신된 바이트를 얻습니다.
		16비트 자료형으로 수신된 바이트가 없을 경우 -1(0xFFFF)을 반환합니다.
		수신된 바이트가 있을 경우 0과 같거나 크고 0x0000 ~ 0x00FF의 크기를 갖습니다.
		그러므로 하위 8비트 부분만 사용하면 됩니다.
		.
		@ return : 수신된 바이트를 반환합니다.
	*/
	int16_t getRxByte(void) __attribute__((optimize("-O1")));
	
	/*
		수신되서 버퍼에 담겨진 데이터의 개수를 반환합니다.
		현재 수신된 데이터의 유효한 버퍼의 포인터는 getRxBuffer() 함수를 통해 얻습니다.
		.
		@ return 수신되서 버퍼에 담겨진 데이터의 개수를 반환합니다.
	*/
	uint32_t getRxCount(void) __attribute__((optimize("-O1")));

	/*
		수신된 버퍼중에 가장 먼저 수신된 버퍼의 데이터 포인터를 반환합니다. 
		다음에 수신된 데이터는 다음 번지에 놓여 있습니다.
		유효한 데이터의 인덱스는 geRxCount() 함수의 '반환값 - 1'까지 접근 가능합니다.
		데이터의 사용이 모두 끝나고 다음 데이터의 수신을 준비하기 releaseRxBuffer() 함수를 통해 수신 버퍼를 비워줘야 합니다.
		.
		@ return : 수신된 바이트의 버퍼 포인터를 반환합니다.
	*/
	int8_t* getRxBuffer(void) __attribute__((optimize("-O1")));
	
	/*
		getRxCount() 함수와 getRxBuffer() 함수를 통해 수신 데이터의 처리를 완료하고 다음 데이터 수신을 위해 버퍼를 비우는 함수입니다.
		반드시 이 함수를 사용해 비워줘야 계속 정상적인 데이터의 수신이 가능합니다. 
		getRxCount() 함수에서 받은 용량만큼만 비워줘야 합니다. 
		.
		@ count : 반드시 getRxCount() 함수에서 받은 값을 그대로 설정합니다.
	*/
	void releaseRxBuffer(uint32_t count) __attribute__((optimize("-O1")));
	
	/*
		데이터 수신이 있을 때까지 대기합니다.
		대기하는 동안은 함수 내부에서는 유휴시간동안 thread::yield() 함수를 호출해서 대기합니다.
		Timeout의 설정으로 일정 시간마다 복귀하는 것이 가능합니다.
		.
		@ return : 데이터의 정상 수신 여부를 반환 합니다. 정상 수신이 있을 경우 true를 반환합니다.
		.
		@ timeout : millisecond 시간단위의 초과 시간을 설정합니다.
	*/
	bool waitUntilReceive(uint32_t timeout) __attribute__((optimize("-O1")));

	/*
		수신 버퍼를 비웁니다.
	*/
	void flush(void) __attribute__((optimize("-O1")));
	
	/*
		Frame Error에 대한 ISR 함수를 등록합니다.
		ISR 함수에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
		yss.h 파일에서 문맥전환을 유발하는 함수 유형의 설명을 참고하세요.
		yss.h 파일에서 ISR 함수와 Callback 함수에 대한 구분 설명을 참고하세요. 
		.
		@ isr : ISR 함수의 포인터를 설정합니다.
	*/
	void setIsrForFrameError(void (*isr)(void)) __attribute__((optimize("-O1")));
	
	/*
		데이터 수신에 대한 ISR 함수를 등록합니다.
		ISR 함수에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
		yss.h 파일에서 문맥전환을 유발하는 함수 유형의 설명을 참고하세요.
		yss.h 파일에서 ISR 함수와 Callback 함수에 대한 구분 설명을 참고하세요. 
		.
		@ isr : ISR 함수의 포인터를 설정합니다.
	*/
	void setIsrForRxData(void (*isr)(uint8_t rxData)) __attribute__((optimize("-O1")));
	
	/*
		복수의 데이터를 송신합니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ src : 송신할 데이터 버퍼의 포인터를 설정합니다.
		@ size : 송신할 데이터의 크기를 설정합니다.
	*/
	error_t send(void *src, int32_t  size) __attribute__((optimize("-O1")));
	
	/*
		복수의 데이터를 송신합니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ src : 송신할 데이터 버퍼의 포인터를 설정합니다.
		@ size : 송신할 데이터의 크기를 설정합니다.
	*/
	error_t send(const void *src, int32_t  size) __attribute__((optimize("-O1")));
	
	/*
		한 바이트를 송신합니다.
		.
		@ data : 송신할 데이터 바이트를 설정합니다.
	*/
	void send(int8_t data) __attribute__((optimize("-O1")));

	/*	
		UART를 일시적으로 활성화/비활성화 시킬 수 있게 합니다.
		intialize() 함수를 호출하면 기본 상태가 활성화입니다.
		.
		@ en : 활성화(true)/비활성화(false)로 설정합니다.
	*/
	void enable(bool en) __attribute__((optimize("-O1")));

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	struct setup_t
	{
		YSS_USART_Typedef *dev;
#if defined(GD32F1) || defined(STM32F1) || defined(GD32F4)  || defined(STM32F7) || defined(STM32F4) || defined(STM32F0)
		Dma &txDma;
		Dma::dmaInfo_t txDmaInfo;
#elif defined(EFM32PG22) || defined(EFR32BG22) || defined(STM32G4)
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
#elif  defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
		Dma::dmaInfo_t txDmaInfo;
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
	Dma::dmaInfo_t mTxDmaInfo;
	Dma::dmaInfo_t mRxDmaInfo;
#else
	int32_t  mTail, mHead;
	Dma *mTxDma;
	Dma::dmaInfo_t mTxDmaInfo;
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

