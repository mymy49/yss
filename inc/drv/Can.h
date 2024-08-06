/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CAN__H_
#define YSS_DRV_CAN__H_

#include "peripheral.h"

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F7) || defined(STM32F4)

typedef struct
{
	uint32_t reserved1 : 1;
	uint32_t remote : 1;
	uint32_t extension : 1;
	uint32_t id : 29;
	uint32_t dataLength : 4;
	uint32_t reserved2 : 28;
	uint8_t data[8];
}canFrame_t;

typedef struct
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
}j1939Frame_t;

typedef CAN_TypeDef	YSS_CAN_TypeDef;

#else

struct canFrame_t
{
};

struct j1939Frame_t
{
};

#define YSS_DRV_CAN_UNSUPPORTED

typedef volatile uint32_t	YSS_CAN_TypeDef;
struct CanFrame{};
struct J1939Frame{};

#endif

#include "Drv.h"
#include <yss/error.h>

class Can : public Drv
{
  public:
	struct config_t
	{
		uint32_t baudrate;		// 통신 보레이트
		uint32_t rxBufferDepth;	// 수신 패킷 링버퍼의 크기
		float samplePoint;		// 샘플 포인트 (보통 0.875)
		bool enableSilent;		// Silent 모드 활성화
		bool enableLoopback;	// Loopback 모드 활성화
	};

	// CAN 장치를 초기화 한다. 이 함수에서 보레이트와 최대 수신 패킷 링 버퍼의 크기 및 샘플 타임을 설정한다.
	// 
	// 반환
	//		에러를 반환한다.
	// config_t config
	//		장치의 설정 값을 정의한 구조체이다.
	error_t initialize(config_t config);
	
	// 설정된 인덱스의 수신 필터를 비활성화 한다.
	// 수신 필터의 개수는 MCU마다 다르다.
	// 
	// 반환
	//		수신 필터를 정상적으로 비활성화 할 경우 true를 반환한다.
	// uint8_t index
	//		비활성화 할 필터의 번호를 설정한다.
	error_t disableFilter(uint8_t index);

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
	error_t setStdMaskFilter(uint8_t index, uint16_t id, uint16_t mask);

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
	error_t setExtMaskFilter(uint8_t index, uint32_t id, uint32_t mask);

	// 설정된 인덱스의 수신 필터를 표준 CAN 전송의 ID 매치 필터로 설정한다.
	// 수신 필터의 개수는 MCU마다 다르다.
	// 
	// 반환
	//		수신 필터를 정상적으로 설정 할 경우 true를 반환한다.
	// uint8_t index
	//		설정을 적용할 필터의 번호를 설정한다.
	// uint16_t id
	//		수신할 ID를 설정한다.
	error_t setStdMatchFilter(uint8_t index, uint16_t id);

	// 설정된 인덱스의 수신 필터를 확장 CAN 전송의 ID 매치 필터로 설정한다.
	// 수신 필터의 개수는 MCU마다 다르다.
	// 
	// 반환
	//		수신 필터를 정상적으로 설정 할 경우 true를 반환한다.
	// uint8_t index
	//		설정을 적용할 필터의 번호를 설정한다.
	// uint16_t id
	//		수신할 ID를 설정한다.
	error_t setExtMatchFilter(uint8_t index, uint32_t id);
	
	// 데이터를 전송한다.
	// 
	// 반환
	//		전송에 성공하면 true를 반환한다.
	// CanFrame packet
	//		전송할 데이터를 설정한다.
	error_t send(canFrame_t packet);

	// 데이터를 전송한다.
	// 
	// 반환
	//		전송에 성공하면 true를 반환한다.
	// J1939Frame packet
	//		전송할 데이터를 설정한다.
	error_t send(j1939Frame_t packet);
	
	// 발생한 전송 에러의 카운트를 얻는다.
	//
	// 반환
	//		전송 에러의 카운트를 반환한다.
	uint8_t getTxErrorCount(void);

	// 발생한 수신 에러의 카운트를 얻는다.
	//
	// 반환
	//		수신 에러의 카운트를 반환한다.
	uint8_t getRxErrorCount(void);

	// 수신한 데이터 패킷의 카운트를 얻는다.
	//
	// 반환
	//		수신한 데이터 패킷의 카운트를 반환한다.
	uint32_t getRxCount(void);

	// 수신 링버퍼의 포인터를 초기화 하여 수신 데이터를 비운다.
	void flush(void);
	
	// 링버퍼의 현재 포인터를 설정된 양 만큼의 다음 데이터로 옮긴다.
	//
	// uint32_t id
	//		링 버퍼의 포인터를 이동시킬 양을 설정한다.
	void releaseFifo(uint32_t count);
	
	// 현재 링버퍼의 포인터가 가르키는 수신 패킷의 포인터를 얻는다.
	// 데이터 수신에 대한 처리가 끝나면 releaseFifo() 함수를 호출하여 현재 포인터를 다음 처리할 데이터의 포인터로 옮겨야 한다.
	// 
	// 반환
	//		수신한 데이터를 얻는다.
	canFrame_t* getRxPacketPointer(void);

	// 송신용 J1939Frame 데이터에 기본값 설정을 도와준다.
	// J1939Frame 데이터의 기본 설정 후에 데이터를 설정하고 전송하는데 사용한다.
	// 
	// 반환
	//		J1939Frame으로 생성한 데이터를 반환한다.
	j1939Frame_t generateJ1939Frame(uint8_t priority, uint16_t pgn, uint8_t sa, uint8_t count);

	// Error 또는 상태 변화 발생시 호출될 Interrupt Service Routine 함수를 설정한다.
	//
	// void (*func)(void)
	//		ISR 함수를 설정한다.
	void setIsrForEvent(void (*func)(error_t code));

	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	struct setup_t
	{
		YSS_CAN_TypeDef *dev;
	};
	
	// 수신 관련 인터럽트 서비스 루틴
	void isrRx(void);
	
	// 에러 관련 인터럽트 서비스 루틴
	void isrEvent(void);

	Can(const Drv::setup_t drvSetup, const setup_t setup);

private :
	canFrame_t *mCanFrame;
	uint32_t mHead, mTail, mRxBufferDepth;
	YSS_CAN_TypeDef *mDev;

	void (*mIsrForEvent)(error_t code);

	void push(canFrame_t *frame);
};

#endif

// ##### 초기화 방법 #####
//		- GPIO의 setAsAltFunc()함수를 사용해 관련된 포트를 CAN 포트로 변경한다.
//		- Can::config_t 설정 구조체를 알맞게 설정한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 장치를 초기화 한다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다.
//		- setStdMaskFilte() 또는 setEtxMaskFilter() 함수를 사용해 필터를 설정한다.

// ##### 초기화 예시 #####
/*
	const Can::config_t canConfig	// 설정 구조체 생성
	{
		250000,			//uint32_t baudrate;		// 통신 보레이트
		128,			//uint32_t rxBufferDepth;	// 수신 패킷 링버퍼의 크기
		SAMPLE_POINT,	//float samplePoint;		// 샘플 포인트 (보통 0.875)
		false,			//bool enableSilent;		// Silent 모드 활성화
		false			//bool enableLoopback;		// Loopback 모드 활성화
	};

	can1.enableClock();					// CAN1 장치 클럭 활성화
	can1.initialize(canConfig);			// CAN1 장치 초기화
	can1.enableInterrupt();				// CAN1 인터럽트 활성화 
	can1.setExtMaskFilter(0, 0x0, 0x0);	// CAN1 수신 마스크0번을 모두 수신으로 설정
*/

// ##### 전송 방법 #####
//		- CanFrame 또는 J1939Frame 구조체의 객체를 생성하고 전송 값을 설정한다.
//		- lock() 함수를 호출하여 다른 쓰레드에서 접근을 막는다.
//		- send() 함수를 이용하여 데이터를 전송한다.
//		- unlock() 함수를 호출하여 현재 소유권을 해제하고 다른 쓰레드에게 접근을 개방한다.

// ##### 전송 예시 #####
/*
	CanFrame sendBuf = {0, };	// 송신 버퍼 생성

	sendBuf.id = 0x123;			// CAN ID 설정
	sendBuf.dataLength = 8;		// 전송 데이터 길이 설정
	sendBuf.data[0] = 0x01;		// 전송 데이터 설정
	sendBuf.data[1] = 0x02;
	sendBuf.data[2] = 0x03;
	sendBuf.data[3] = 0x04;
	sendBuf.data[4] = 0x05;
	sendBuf.data[5] = 0x06;
	sendBuf.data[6] = 0x07;
	sendBuf.data[7] = 0x08;

	can1.lock();				// CAN1 장치 뮤텍스 락
	can1.send(sendBuf);			// CAN1 데이터 전송
	can1.unlock();				// CAN1 장치 뮤텍스 언락
*/

// ##### 수신 방법 #####
//		- 루프에서 getRxCount() 함수를 이용하여 수신된 데이터가 있는지 확인한다.
//		- getRxPacketPointer() 함수를 이용하여 수신된 데이터의 포인터를 얻어오고 그 처리를 한다.
//		- releaseFifo() 함수를 이용하여 수신된 데이터의 포인터를 다음 번지로 이동시킨다.
/*
	uint32_t count;

	while(1)
	{
		count = can1.getRxCount();	// CAN 수신 패킷의 갯수를 얻음
	
		if(count)	// 수신 패킷이 있을 경우
		{
			rcvBuf = can1.getRxPacketPointer();	// 수신 패킷 링버퍼의 첫번째 인자의 포인터를 얻음

			for(uint32_t i=0;i<count;i++)
			{
				if(!rcvBuf[i].extension)	// 수신 메시지가 표준일 경우
				{
					switch(rcvBuf[i].id)
					{
					case 0 :	// 수신 메시지의 ID가 0일 경우 처리
						
						break;
					
					case 1 :	// 수신 메시지의 ID가 1일 경우의 처리
						
						break;

					// 그 외 수신 ID에 대한 처리 추가
					}
				}
				else	// 수신 메시지가 확장일 경우
				{
					switch(rcvBuf[i].id)
					{
					case 0 :	// 수신 메시지의 ID가 0일 경우 처리
						
						break;
					
					case 1 :	// 수신 메시지의 ID가 1일 경우의 처리
						
						break;
					}
				}
			}

			can1.releaseFifo(count);	// 수신 메시지에 대해 처리가 완료되면 링버퍼의 포인터를 다음 수신되는 데이터로 이동
		}
		
		// 수신 메시지 처리가 끝나거나 메시지가 없을 경우, 바로 다음 수신 카운트를 확인하지 않고 CPU를 다음 쓰레드에 양도한다.
		// 처리 효율을 높이기 위한 처리이다.
		thread::yield();	
	}
*/
