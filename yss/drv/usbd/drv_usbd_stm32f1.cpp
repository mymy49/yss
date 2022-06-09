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

#include <drv/peripheral.h>

#if defined(STM32F1)

#include <drv/Usbd.h>
#define EPR_TOGGLE_REG (USB_EP_DTOG_RX_Msk | USB_EP_RX_VALID | USB_EP_DTOG_TX_Msk | USB_EP_TX_VALID)

namespace drv
{
Usbd::Usbd(USB_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{

	mPeri = peri;
	mBufferTable = (BufferTable *)USB_PMAADDR;
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
	register unsigned int reg = epr[ep];
	epr[ep] = (status & USB_EP0R_STAT_RX_Msk) ^ (reg & USB_EP0R_STAT_RX_Msk);
}

void Usbd::setEpType(unsigned char ep, unsigned short type)
{
	volatile unsigned int *epr = (volatile unsigned int *)&mPeri->EP0R;
	register unsigned int reg = epr[ep];
	epr[ep] = (reg & ~(EPR_TOGGLE_REG | USB_EP0R_EP_TYPE_Msk)) | (type & USB_EP0R_EP_TYPE_Msk);
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
	mBufferTable->rx1.addr = addr;
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
	mBufferTable->rx3.addr = addr;
	mBufferTable->rx3.cnt = 0;

	setEpStatusRx(0, USB_EP_RX_VALID);
	setEpStatusTx(0, USB_EP_TX_VALID);
	setEpType(0, USB_EP_CONTROL);

	for (unsigned char i = 1; i < 8; i++)
	{
		setEpStatusRx(i, USB_EP_RX_DIS);
		setEpStatusTx(i, USB_EP_RX_DIS);
	}

	USB->CNTR = USB_CNTR_RESETM | USB_CNTR_CTRM;
}

}

#endif