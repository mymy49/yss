////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.1
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////


#ifndef YSS_DRV_CAN__H_
#define YSS_DRV_CAN__H_

#include "mcu.h"
#include <stdint.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)
struct CanFrame
{
	uint32_t reserved1 : 1;
	uint32_t remote : 1;
	uint32_t extension : 1;
	uint32_t id : 29;
	uint32_t dataLength : 4;
	uint32_t reserved2 : 28;
	uint8_t data[8];
};

struct J1939Frame
{
	uint32_t reserved1 : 1;
	uint32_t remote : 1;
	uint32_t extension : 1;
	uint32_t sa : 8;
	uint32_t pgn : 16;
	uint32_t dp : 1;
	uint32_t r : 1;
	uint32_t priority : 3;
	uint32_t dataLength : 4;
	uint32_t reserved2 : 28;
	uint8_t data[8];
};

typedef volatile uint32_t	YSS_CAN_Peri;

#elif defined(GD32F1)

struct CanFrame
{
	uint32_t reserved1 : 1;
	uint32_t remote : 1;
	uint32_t extension : 1;
	uint32_t id : 29;
	uint32_t dataLength : 4;
	uint32_t reserved2 : 28;
	uint8_t data[8];
};

struct J1939Frame
{
	uint32_t reserved1 : 1;
	uint32_t remote : 1;
	uint32_t extension : 1;
	uint32_t sa : 8;
	uint32_t pgn : 16;
	uint32_t dp : 1;
	uint32_t r : 1;
	uint32_t priority : 3;
	uint32_t dataLength : 4;
	uint32_t reserved2 : 28;
	uint8_t data[8];
};

typedef volatile uint32_t	YSS_CAN_Peri;

#else

#define YSS_DRV_CAN_UNSUPPORTED

typedef volatile uint32_t	YSS_CAN_Peri;
struct CanFrame{};
struct J1939Frame{};

#endif

#include "Drv.h"

class Can : public Drv
{
  public:
	Can(YSS_CAN_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), uint32_t (*getClockFreq)(void));
	
	// CAN 장치를 초기화 한다. 이 함수에서 보레이트와 최대 수신 패킷 링 버퍼의 크기 및 샘플 타임을 설정한다.
	// 
	// 반환
	//		초기화 성공 유무를 반환한다. 초기화 성공시 true를 반환한다.
	// uint32_t baudRate
	//		통신 보레이트를 설정한다.
	// uint32_t bufDepth
	//		수신 패킷 링버퍼의 크기를 설정한다.
	// float samplePoint
	//		샘플 포인트를 설정한다.
	bool initialize(uint32_t baudRate, uint32_t bufDepth, float samplePoint = 0.875);
	
	// 설정된 인덱스의 수신 필터를 비활성화 한다.
	// 수신 필터의 개수는 MCU마다 다르다.
	// 
	// 반환
	//		수신 필터를 정상적으로 비활성화 할 경우 true를 반환한다.
	// uint8_t index
	//		비활성화 할 필터의 번호를 설정한다.
	bool disableFilter(uint8_t index);

	// 설정된 인덱스의 수신 필터를 표준 CAN 전송 ID의 마스크 필터로 설정한다.
	// 수신 필터의 개수는 MCU마다 다르다.
	// 
	// 반환
	//		수신 필터를 정상적으로 설정 할 경우 true를 반환한다.
	// uint8_t index
	//		설정을 적용할 필터의 번호를 설정한다.
	// uint16_t id
	//		마스크할 패턴을 설정한다.
	// uint16_t mask
	//		id에 설정된 패턴을 수신 ID와 실제 비교할 비트의 마스킹을 설정한다.
	bool setStandardMaskFilter(uint8_t index, uint16_t id, uint16_t mask);

	// 설정된 인덱스의 수신 필터를 확장 CAN 전송 ID의 마스크 필터로 설정한다.
	// 수신 필터의 개수는 MCU마다 다르다.
	// 
	// 반환
	//		수신 필터를 정상적으로 설정 할 경우 true를 반환한다.
	// uint8_t index
	//		설정을 적용할 필터의 번호를 설정한다.
	// uint16_t id
	//		마스크할 패턴을 설정한다.
	// uint16_t mask
	//		id에 설정된 패턴을 수신 ID와 실제 비교할 비트의 마스킹을 설정한다.
	bool setExtendedMaskFilter(uint8_t index, uint32_t id, uint32_t mask);

	// 설정된 인덱스의 수신 필터를 표준 CAN 전송의 ID 매치 필터로 설정한다.
	// 수신 필터의 개수는 MCU마다 다르다.
	// 
	// 반환
	//		수신 필터를 정상적으로 설정 할 경우 true를 반환한다.
	// uint8_t index
	//		설정을 적용할 필터의 번호를 설정한다.
	// uint16_t id
	//		수신할 ID를 설정한다.
	bool setStandardMatchFilter(uint8_t index, uint16_t id);

	// 설정된 인덱스의 수신 필터를 확장 CAN 전송의 ID 매치 필터로 설정한다.
	// 수신 필터의 개수는 MCU마다 다르다.
	// 
	// 반환
	//		수신 필터를 정상적으로 설정 할 경우 true를 반환한다.
	// uint8_t index
	//		설정을 적용할 필터의 번호를 설정한다.
	// uint16_t id
	//		수신할 ID를 설정한다.
	bool setExtendedMatchFilter(uint8_t index, uint32_t id);
	
	// 데이터를 전송한다.
	// 
	// 반환
	//		전송에 성공하면 true를 반환한다.
	// CanFrame packet
	//		전송할 데이터를 설정한다.
	bool send(CanFrame packet);

	// 데이터를 전송한다.
	// 
	// 반환
	//		전송에 성공하면 true를 반환한다.
	// J1939Frame packet
	//		전송할 데이터를 설정한다.
	bool send(J1939Frame packet);
	
	// 발생한 전송 에러의 카운트를 얻는다.
	//
	// 반환
	//		전송 에러의 카운트를 반환한다.
	uint8_t getSendErrorCount(void);

	// 발생한 수신 에러의 카운트를 얻는다.
	//
	// 반환
	//		수신 에러의 카운트를 반환한다.
	uint8_t getReceiveErrorCount(void);

	// 데이터 수신 여부를 확인한다.
	// 
	// 반환
	//		데이터 수신이 있을 경우 true를 반환한다.
	bool isReceived(void);
	
	// 데이터 수신 버퍼를 비운다.
	void flush(void);
	
	// 링버퍼의 현재 포인터를 다음 데이터로 옮긴다. 데이터 수신이 발생한 경우, 이 함수를 호출하여야
	// 다음 데이터에 접근이 가능하다.
	void releaseFifo(void);
	
	// 현재 링버퍼의 포인터가 가르키는 수신 데이터를 하나 얻는다.
	// 데이터 수신에 대한 처리가 끝나면 releaseFifo() 함수를 호출하여 현재 포인터를 다음 데이터로 옮겨야 한다.
	// 
	// 반환
	//		수신한 데이터를 얻는다.
	CanFrame getPacket(void);

	// 송신용 J1939Frame 데이터에 기본값 설정을 도와준다.
	// J1939Frame 데이터의 기본 설정 후에 데이터를 설정하고 전송하는데 사용한다.
	// 
	// 반환
	//		수신한 데이터를 얻는다.
	J1939Frame generateJ1939FrameBuffer(uint8_t priority, uint16_t pgn, uint8_t sa, uint8_t count);

	// 인터럽트 벡터에서 호출되는 함수이다.
	// 사용자 임의의 호출은 금지한다.
	void isr(void);

private :
	CanFrame *mCanFrame;
	uint32_t mHead, mTail, mMaxDepth;
	uint32_t (*mGetClockFreq)(void);
	YSS_CAN_Peri *mPeri;

	void push(CanFrame *frame);
};

#endif

// 초기화 방법
//		- GPIO의 setAsAltFunc()함수를 사용해 관련된 포트를 CAN 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 장치를 초기화 한다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다.

// 전송 방법
//		- CanFrame 또는 J1939Frame 구조체의 객체를 생성하고 전송 값을 설정한다.
//		- lock() 함수를 호출하여 다른 쓰레드에서 접근을 막는다.
//		- send() 함수를 이용하여 데이터를 전송한다.
//		- unlock() 함수를 호출하여 현재 소유권을 해제하고 다른 쓰레드에게 접근을 개방한다.

// 수신 방법
//		- 루프에서 isReceived() 함수를 이용하여 수신된 데이터가 있는지 확인한다.
//		- getPacket() 함수를 이용하여 수신된 데이터를 얻어오고 그 처리를 한다.
//		- releaseFifo() 함수를 이용하여 수신된 데이터의 포인터를 다음 번지로 이동시킨다.

