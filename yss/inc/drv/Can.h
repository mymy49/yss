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

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7) || defined(GD32F10X_XD) || defined(GD32F10X_HD)
struct CanFrame
{
	unsigned int reserved1 : 1;
	unsigned int remote : 1;
	unsigned int extension : 1;
	unsigned int id : 29;
	unsigned int dataLength : 4;
	unsigned int reserved2 : 28;
	unsigned char data[8];
};

struct J1939Frame
{
	unsigned int reserved1 : 1;
	unsigned int remote : 1;
	unsigned int extension : 1;
	unsigned int sa : 8;
	unsigned int pgn : 16;
	unsigned int dp : 1;
	unsigned int r : 1;
	unsigned int priority : 3;
	unsigned int dataLength : 4;
	unsigned int reserved2 : 28;
	unsigned char data[8];
};

typedef CAN_TypeDef				YSS_CAN_Peri;
#elif defined(STM32G4)
typedef FDCAN_GlobalTypeDef		YSS_CAN_Peri;
#else
struct CanFrame{};
struct J1939Frame{};
typedef void					YSS_CAN_Peri;
#endif

namespace drv
{
class Can : public Drv
{
	CanFrame *mCanFrame;
	unsigned int mHead, mTail, mMaxDepth;
	unsigned int (*mGetClockFreq)(void);
	YSS_CAN_Peri *mPeri;

#if defined(STM32G4)
	unsigned int *mCanTxBuffer; 
	unsigned int *mCanTxEventFifo;
	unsigned int *mCanRxFifo1;
	unsigned int *mCanRxFifo0;
	unsigned int *mCanExtFilter;
	unsigned int *mCanStdFilter;

	unsigned char mTxFifoIndex;

	const unsigned int *mRxFifo0[3];
	const unsigned int *mTxbuf[3];
	unsigned char mRxFifoIndex0;
#endif

	void push(CanFrame *frame);

  public:
	Can(YSS_CAN_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), unsigned int (*getClockFreq)(void));
	bool init(unsigned int baudRate, unsigned int bufDepth, float samplePoint = 0.875);
	bool disableFilter(unsigned char index);
	bool setStandardMaskFilter(unsigned char index, unsigned short id, unsigned short mask);
	bool setExtendedMaskFilter(unsigned char index, unsigned int id, unsigned int mask);
	bool setStandardMatchFilter(unsigned char index, unsigned short id);
	bool setExtendedMatchFilter(unsigned char index, unsigned int id);
	bool isReceived(void);
	void flush(void);
	void releaseFifo(void);
	bool send(CanFrame packet);
	bool send(J1939Frame packet);
	void isr(void);
	unsigned char getSendErrorCount(void);
	unsigned char getReceiveErrorCount(void);
	CanFrame getPacket(void);
	J1939Frame generateJ1939FrameBuffer(unsigned char priority, unsigned short pgn, unsigned short sa, unsigned char count);
};
}

#endif