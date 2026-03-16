/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CAN__H_
#define YSS_DRV_CAN__H_

#include "peripheral.h"
#include "Drv.h"
#include <yss/error.h>

typedef struct
{
	bool xtd;
	uint32_t id;
	uint8_t dlc;
	uint8_t data[8];
}canMsg_t;

class Can : public Drv
{
public :
	virtual uint32_t getBaudrate(void) = 0;

	virtual float getSamplePoint(void) = 0;

	virtual void sendStdCanMessage(uint16_t id, uint8_t *src, uint8_t dlc) = 0;

	virtual void sendXtdCanMessage(uint32_t id, uint8_t *src, uint8_t dlc) = 0;

	virtual bool isNewRxMessage(void) = 0;

	virtual canMsg_t getNewRxCanMessage(void) = 0;

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	Can(const Drv::setup_t drvSetup);

private :
};

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

#endif

