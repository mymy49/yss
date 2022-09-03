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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CAN__H_
#define YSS_DRV_CAN__H_

#include "mcu.h"
#include "Drv.h"

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

typedef uint32_t			YSS_CAN_Peri;

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

#elif defined(STM32G4)
typedef FDCAN_GlobalTypeDef		YSS_CAN_Peri;
#else
struct CanFrame{};
struct J1939Frame{};
typedef void					YSS_CAN_Peri;
#endif

class Can : public Drv
{
	CanFrame *mCanFrame;
	uint32_t mHead, mTail, mMaxDepth;
	uint32_t (*mGetClockFreq)(void);
	YSS_CAN_Peri *mPeri;

#if defined(STM32G4)
	uint32_t *mCanTxBuffer; 
	uint32_t *mCanTxEventFifo;
	uint32_t *mCanRxFifo1;
	uint32_t *mCanRxFifo0;
	uint32_t *mCanExtFilter;
	uint32_t *mCanStdFilter;

	uint8_t mTxFifoIndex;

	const uint32_t *mRxFifo0[3];
	const uint32_t *mTxbuf[3];
	uint8_t mRxFifoIndex0;
#endif

	void push(CanFrame *frame);

  public:
	Can(YSS_CAN_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), uint32_t (*getClockFreq)(void));
	bool init(uint32_t baudRate, uint32_t bufDepth, float samplePoint = 0.875);
	bool disableFilter(uint8_t index);
	bool setStandardMaskFilter(uint8_t index, uint16_t id, uint16_t mask);
	bool setExtendedMaskFilter(uint8_t index, uint32_t id, uint32_t mask);
	bool setStandardMatchFilter(uint8_t index, uint16_t id);
	bool setExtendedMatchFilter(uint8_t index, uint32_t id);
	bool isReceived(void);
	void flush(void);
	void releaseFifo(void);
	bool send(CanFrame packet);
	bool send(J1939Frame packet);
	void isr(void);
	uint8_t getSendErrorCount(void);
	uint8_t getReceiveErrorCount(void);
	CanFrame getPacket(void);
	J1939Frame generateJ1939FrameBuffer(uint8_t priority, uint16_t pgn, uint16_t sa, uint8_t count);
};

#endif