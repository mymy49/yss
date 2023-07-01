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

#ifndef YSS_DRV_USART__H_
#define YSS_DRV_USART__H_

#include "Uart.h"

#if defined(YSS_DRV_UART_UNSUPPORTED)

#define YSS_DRV_USART_UNSUPPORTED

#endif

class Usart : public Uart
{
public:
	void enableSck(bool en = true);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	Usart(const Drv::Setup drvConfig, const Uart::Setup config);
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

