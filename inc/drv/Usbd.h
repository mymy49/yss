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

#ifndef YSS_DRV_USBD__H_
#define YSS_DRV_USBD__H_
/*
#include "mcu.h"

#if defined(USB)

#if defined(STM32F1) || defined(STM32L0)

#define MAX_EP_NUM 8

#else

#define YSS_DRV_USBD_UNSUPPORTED

#endif

#ifndef YSS_DRV_USBD_UNSUPPORTED

#include "Drv.h"

class Usbd : public Drv
{
	struct BufferInfo
	{
		uint16_t addr;
		uint16_t rsvd0;
		uint16_t cnt;
		uint16_t rsvd1;
	}__attribute__ ((__packed__));

	struct BufferTable
	{
		BufferInfo tx0;
		BufferInfo rx0;
		BufferInfo tx1;
		BufferInfo rx1;
		BufferInfo tx2;
		BufferInfo rx2;
		BufferInfo tx3;
		BufferInfo rx3;
	}__attribute__ ((__packed__));

	USB_TypeDef *mPeri;
	void setEpStatusTx(uint8_t ep, uint16_t status);
	void setEpStatusRx(uint8_t ep, uint16_t status);
	void setEpType(uint8_t ep, uint16_t type);
	BufferTable *mBufferTable;

  public:
	Usbd(USB_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void));
	void init(void);
	void isr(void);
	void resetCore(void);
};

#endif

#endif
*/
#endif

