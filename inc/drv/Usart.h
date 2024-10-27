/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_USART__H_
#define YSS_DRV_USART__H_

#include "Uart.h"

#if defined(YSS_DRV_UART_UNSUPPORTED)

#define YSS_DRV_USART_UNSUPPORTED

#endif

class Usart : public Uart
{
public:
	void enableSck(bool en = true) __attribute__((optimize("-O1")));

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	Usart(const Drv::setup_t drvConfig, const Uart::setup_t config) __attribute__((optimize("-O1")));
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

