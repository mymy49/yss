////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CAN_ST_TYPE_A_REG__H_
#define YSS_DRV_CAN_ST_TYPE_A_REG__H_

#include <yss/reg.h>

#define setCanModeRequest(addr, x)				setRegField(addr->MCR, 0x3UL, x, 0)
#define setCanNoAutoRetransmission(addr, x)		setRegBit(addr->MCR, x, 4)
#define setCanAutoWakeupMode(addr, x)			setRegBit(addr->MCR, x, 5)
#define setCanAutoBusoff(addr, x)				setRegBit(addr->MCR, x, 6)

#define getCanModeAck(addr)						getRegField(addr->MSR, 0x3UL, 0)
#define getCanInitModeStatus(addr)				getRegBit(addr->MSR, 0)
#define getCanSleepModeStatus(addr)				getRegBit(addr->MSR, 1)

#define getCanTransmitEmpty0(addr)				getRegBit(addr->TSR, 26)
#define getCanTransmitEmpty1(addr)				getRegBit(addr->TSR, 27)
#define getCanTransmitEmpty2(addr)				getRegBit(addr->TSR, 28)

#define releaseFifo0MailBox(addr)				setRegBit(addr->RF0R, 1, 5)

#define setCanFifoPending0IntEn(addr, x)		setRegBit(addr->IER, x, 1)

#define setCanBaudratePrescaler(addr, x)		setRegField(addr->BTR, 0x3FFUL, x, 0)
#define setCanTimeSegment1(addr, x)				setRegField(addr->BTR, 0xFUL, x, 16)
#define setCanTimeSegment2(addr, x)				setRegField(addr->BTR, 0x7UL, x, 20)
#define setCanResyncJumpWidth(addr, x)			setRegField(addr->BTR, 0x3UL, x, 24)

#define setCanTxIdentifierRegister(addr, x)		addr.TIR = x
#define setCanTxLengthRegister(addr, x)			addr.TDTR = x
#define setCanTxLowRegister(addr, x)			addr.TDLR = x
#define setCanTxHighRegister(addr, x)			addr.TDHR = x

#define setCanActiveFilterMode(addr, x)			setRegBit(addr->FMR, x, 0)

#define setCanFilterScaleConfig(addr, num, x)	setRegBit(addr->FS1R, x, num)

#define setCanFilterActive(addr, num, x)		setRegBit(addr->FA1R, x, num)

#define CAN_MODE_SLEEP		0x02
#define CAN_MODE_INIT		0x01
#define CAN_MODE_NORMAL		0X00

#endif
