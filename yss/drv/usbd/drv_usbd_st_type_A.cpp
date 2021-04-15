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

#include <yss/mcu.h>

#if defined(STM32F1)

#include <drv/usbd/drv_st_usbd_type_A.h>
#define EPR_TOGGLE_REG	(USB_EP_DTOG_RX_Msk | USB_EP_RX_VALID | USB_EP_DTOG_TX_Msk | USB_EP_TX_VALID)

namespace drv
{
Usbd::Usbd(USB_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
	
    mPeri = peri;
	mBufferTable = (BufferTable*)USB_PMAADDR;
}

void Usbd::init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_USBEN;

    mPeri->CNTR = USB_CNTR_FRES;
    mPeri->BTABLE = 0;
    mPeri->DADDR = 0;
    mPeri->ISTR = 0;
    mPeri->CNTR = USB_CNTR_RESETM;
}

void Usbd::isr(void)
{
    if (USB->ISTR & USB_ISTR_RESET)
    {
        USB->ISTR &= ~USB_ISTR_RESET;
        resetCore();
        return;
    }
}

void Usbd::setEpStatusTx(unsigned char ep, unsigned short status)
{
    volatile unsigned int *epr = (volatile unsigned int *)&mPeri->EP0R;
    register unsigned int reg = epr[ep];
    epr[ep] = (status & USB_EP0R_STAT_TX_Msk) ^ (reg & USB_EP0R_STAT_TX_Msk);
}

void Usbd::setEpStatusRx(unsigned char ep, unsigned short status)
{
    volatile unsigned int *epr = (volatile unsigned int *)&mPeri->EP0R;
	epr[ep] |= USB_EP0R_STAT_RX_Msk;
    register unsigned int reg = epr[ep];
    epr[ep] = (status & USB_EP0R_STAT_RX_Msk) ^ (reg & USB_EP0R_STAT_RX_Msk);
}

void Usbd::setEpType(unsigned char ep, unsigned char type)
{
    volatile unsigned int *epr = (volatile unsigned int *)&mPeri->EP0R;
    register unsigned int reg = epr[ep];
    epr[ep] = (reg & ~EPR_TOGGLE_REG) | (type & USB_EP0R_EP_TYPE_Msk);
}

void Usbd::resetCore(void)
{
    volatile unsigned int *epr = (volatile unsigned int *)&mPeri->EP0R;
	register unsigned int reg;
	unsigned short addr = sizeof(BufferTable);

	mBufferTable->tx0.addr = addr;
	mBufferTable->tx0.cnt = 0;
	
	addr += 64;
	mBufferTable->rx0.addr = addr;
	mBufferTable->rx0.cnt = 0;

	addr += 64;
	mBufferTable->tx1.addr = addr;
	mBufferTable->tx1.cnt = 0;

	addr += 64;
	mBufferTable->rx1.addr= addr;
	mBufferTable->rx1.cnt = 0;

	addr += 64;
	mBufferTable->tx2.addr = addr;
	mBufferTable->tx2.cnt = 0;

	addr += 64;
	mBufferTable->rx2.addr = addr;
	mBufferTable->rx2.cnt = 0;

	addr += 64;
	mBufferTable->tx3.addr = addr;
	mBufferTable->tx3.cnt = 0;

	addr += 64;
	mBufferTable->rx3.addr= addr;
	mBufferTable->rx3.cnt = 0;

	setEpStatusRx(0, USB_EP_RX_VALID);
	setEpStatusTx(0, USB_EP_TX_VALID);
	setEpType(0, USB_EP_CONTROL);

    for (unsigned char i = 1; i < 8; i++)
    {
		setEpStatusRx(i, USB_EP_RX_DIS);
		setEpStatusTx(i, USB_EP_RX_DIS);
    }

//    USB->CNTR = USB_CNTR_RESETM | ;
}

}

#endif