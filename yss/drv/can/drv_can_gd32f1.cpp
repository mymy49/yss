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

#include <drv/peripheral.h>

#if defined(GD32F10X_XD)

#include <drv/Can.h>
#include <yss/thread.h>
#include <yss/malloc.h>
#include <yss/reg.h>

#define CAN_MODE_SLEEP		0x02
#define CAN_MODE_INIT		0x01
#define CAN_MODE_NORMAL		0X00

namespace drv
{
Can::Can(YSS_CAN_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
	mPeri = peri;
	mGetClockFreq = getClockFreq;
	mHead = 0;
	mTail = 0;
	mData = 0;
	mMaxDepth = 0;
}

bool Can::init(unsigned int baudRate, unsigned int bufDepth, float samplePoint)
{
	unsigned int clk = mGetClockFreq(), ts1, ts2, pres;

	clk /= baudRate;

	ts1 = (unsigned int)((float)clk * samplePoint);
	ts2 = clk - ts1;
	for (pres = ts2; pres > 0; pres--)
		if (((ts1 % pres) == 0) && ((ts2 % pres) == 0))
			break;

	ts1 -= pres;
	ts1 /= pres;
	ts2 /= pres;

	if (pres > 1 && pres <= 1024)
		pres--;
	else
		goto retry1;

	if (ts1 > 0 && ts1 <= 16)
		ts1--;
	else
		goto retry1;

	if (ts2 > 0 && ts2 <= 8)
		ts2--;
	else
		goto retry1;

	goto next;
retry1:

	ts1 = (unsigned int)((float)clk * samplePoint);
	ts1++;

	ts2 = clk - ts1;
	for (pres = ts2; pres > 0; pres--)
		if (((ts1 % pres) == 0) && ((ts2 % pres) == 0))
			break;

	ts1 -= pres;
	ts1 /= pres;
	ts2 /= pres;

	if (pres > 1 && pres <= 1024)
		pres--;
	else
		goto retry2;

	if (ts1 > 0 && ts1 <= 16)
		ts1--;
	else
		goto retry2;

	if (ts2 > 0 && ts2 <= 8)
		ts2--;
	else
		goto retry2;

	goto next;
retry2:
	ts1 = (unsigned int)((float)clk * samplePoint);
	ts1--;

	ts2 = clk - ts1;
	for (pres = ts2; pres > 0; pres--)
		if (((ts1 % pres) == 0) && ((ts2 % pres) == 0))
			break;

	ts1 -= pres;
	ts1 /= pres;
	ts2 /= pres;

	if (pres > 1 && pres <= 1024)
		pres--;
	else
		return false;

	if (ts1 > 0 && ts1 <= 16)
		ts1--;
	else
		return false;

	if (ts2 > 0 && ts2 <= 8)
		ts2--;
	else
		return false;

next:
	setFieldData(mPeri->CTLR, 0x3 << 0, CAN_MODE_INIT, 0);	// CAN init 모드 진입
	while (getFieldData(mPeri->STR, 0x3, 0) != CAN_MODE_INIT)
		thread::yield();
	
	setBitData(mPeri->CTLR, true, 4);	// Auto retransmission Disable
	
	setThreeFieldData(mPeri->BTR, 0x3FF << 0, pres, 0, 0xF << 16, ts1, 16, 0x7 << 20, ts2, 20); // Baudrate 설정
	
	setBitData(mPeri->IER, true, 1); // Fifo0 Pending Interrupt Enable
	
	if (mMaxDepth != bufDepth)
	{
		if (mData)
#if YSS_L_HEAP_USE == true
			lfree(mData);
		mData = (unsigned int *)lmalloc(bufDepth * 16);
#else
			hfree(mData);
		mData = (unsigned int *)hmalloc(bufDepth * 16);
#endif
	}

	if (mData == 0)
	{
		return false;
	}

	mMaxDepth = bufDepth;
	mHead = 0;
	mTail = 0;
	
	setBitData(mPeri->CTLR, true, 6);	// Automatic bus-off recovery 활성화
	setFieldData(mPeri->CTLR, 0x3 << 0, CAN_MODE_NORMAL, 0);	// CAN init 모드 진입

	return true;
error:
	return false;
}

bool Can::disableFilter(unsigned char index)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  
	
	setBitData(mPeri->FCTLR, true, 0);	// Filter Lock 비활성화
	setBitData(mPeri->FWR, false, index);	// Filter 비활성화
	setBitData(mPeri->FCTLR, false, 0);	// Filter Lock 활성화
	
	return true;
}

bool Can::setStandardMaskFilter(unsigned char index, unsigned short id, unsigned short mask)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  

	setBitData(mPeri->FCTLR, true, 0);	// Filter Lock 비활성화
	
	setFieldData(mPeri->FilterRegister[index].FD0R, 0x7FF << 21, id, 21);
	setFieldData(mPeri->FilterRegister[index].FD1R, 0x7FF << 21, mask, 21);

	setBitData(mPeri->FMR, false, index);	// Filter Mask Mode 설정
	setBitData(mPeri->FSR, true, index);	// Filter width 32bit 설정
	setBitData(mPeri->FWR, true, index);	// Filter 활성화

	setBitData(mPeri->FCTLR, false, 0);	// Filter Lock 활성화

	return true;
}

bool Can::setExtendedMaskFilter(unsigned char index, unsigned int id, unsigned int mask)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  

	setBitData(mPeri->FCTLR, true, 0);	// Filter Lock 비활성화
	
	setFieldData(mPeri->FilterRegister[index].FD0R, 0x1FFFFFFF << 3, id, 3);
	setFieldData(mPeri->FilterRegister[index].FD1R, 0x1FFFFFFF << 3, mask, 3);

	setBitData(mPeri->FMR, false, index);	// Filter Mask Mode 설정
	setBitData(mPeri->FSR, true, index);	// Filter width 32bit 설정
	setBitData(mPeri->FWR, true, index);	// Filter 활성화

	setBitData(mPeri->FCTLR, false, 0);	// Filter Lock 활성화

	return true;
}

bool Can::setStandardMatchFilter(unsigned char index, unsigned short id)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  

	setBitData(mPeri->FCTLR, true, 0);	// Filter Lock 비활성화
	
	mPeri->FilterRegister[index].FD0R = 0x0;
	setFieldData(mPeri->FilterRegister[index].FD1R, 0x7FF << 21, id, 21);

	setBitData(mPeri->FMR, true, index);	// Filter Mask Mode 설정
	setBitData(mPeri->FSR, true, index);	// Filter width 32bit 설정
	setBitData(mPeri->FWR, true, index);	// Filter 활성화

	setBitData(mPeri->FCTLR, false, 0);	// Filter Lock 활성화

	return true;
}

bool Can::setExtendedMatchFilter(unsigned char index, unsigned int id)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  

	setBitData(mPeri->FCTLR, true, 0);	// Filter Lock 비활성화
	
	mPeri->FilterRegister[index].FD0R = 0x0;
	setFieldData(mPeri->FilterRegister[index].FD1R, 0x1FFFFFFF << 3, id, 3);

	setBitData(mPeri->FMR, true, index);	// Filter Mask Mode 설정
	setBitData(mPeri->FSR, true, index);	// Filter width 32bit 설정
	setBitData(mPeri->FWR, true, index);	// Filter 활성화

	setBitData(mPeri->FCTLR, false, 0);	// Filter Lock 활성화

	return true;
}

void Can::push(unsigned int rixr, unsigned int rdtxr, unsigned int rdlxr, unsigned int rdhxr)
{
	unsigned int offset = mHead++ * 4;

	mData[offset++] = rixr;
	mData[offset++] = rdtxr;
	mData[offset++] = rdlxr;
	mData[offset++] = rdhxr;

	if (mHead >= mMaxDepth)
		mHead = 0;
}

bool Can::isReceived(void)
{
	bool rt;
	if (mHead != mTail)
		rt = true;
	else
		rt = false;
	return rt;
}

bool Can::isStandard(void)
{
	unsigned int offset = mTail * 4;

	if (mData[offset] & 0x00000004)
		return false;
	else
		return true;
}

unsigned short Can::getStandardIdentifier(void)
{
	unsigned int offset = mTail * 4;
	return (unsigned short)(mData[offset] >> 21 & 0x7FF);
}

unsigned int Can::getExtendedIdentifier(void)
{
	unsigned int offset = mTail * 4;
	return mData[offset] >> 3;
}

unsigned char Can::getPriority(void)
{
	unsigned int offset = mTail * 4;
	unsigned int rt;
	rt = mData[offset] >> 29;
	return (unsigned char)rt;
}

unsigned short Can::getPgn(void)
{
	unsigned int offset = mTail * 4;
	unsigned int rt;
	rt = mData[offset] >> 11;
	return (unsigned short)(rt & 0xffff);
}

unsigned char Can::getSrcAddr(void)
{
	unsigned int offset = mTail * 4;
	unsigned int rt;
	rt = mData[offset] >> 3;
	return (unsigned short)(rt & 0xff);
}

void Can::releaseFifo(void)
{
	mTail++;
	if (mTail >= mMaxDepth)
		mTail = 0;
}

char *Can::getData(void)
{
	unsigned int offset = mTail * 4 + 2;
	return (char *)&mData[offset];
}

unsigned char Can::getSize(void)
{
	unsigned int offset = mTail * 4 + 1;
	return (unsigned char)mData[offset] & 0x0f;
}

bool Can::sendJ1939(unsigned char priority, unsigned short pgn, unsigned char srcAddr, void *data, unsigned char size)
{
	unsigned int tmir = 0x04, tmd0r, tmd1r;
	char *src = (char *)data;
	tmir |= (priority & 0x1F) << 27;
	tmir |= pgn << 11;
	tmir |= srcAddr << 3;

	tmd0r = src[0];
	tmd0r |= src[1] << 8;
	tmd0r |= src[2] << 16;
	tmd0r |= src[3] << 24;

	tmd1r = src[4];
	tmd1r |= src[5] << 8;
	tmd1r |= src[6] << 16;
	tmd1r |= src[7] << 24;

retry:
	if (getBitData(mPeri->TSTR, 26))
	{
		mPeri->TxMailBox[0].TMD1R = tmd1r;
		mPeri->TxMailBox[0].TMD0R = tmd0r;
		setFieldData(mPeri->TxMailBox[0].TMPR, 0xF << 0, size, 0); 
		mPeri->TxMailBox[0].TMIR = tmir;
	}
	else
	{
		thread::yield();
		goto retry;
	}

	return true;
}

bool Can::sendExtended(unsigned int id, void *data, unsigned char size)
{
	unsigned int tmir = 0x05, tmd0r, tmd1r;
	char *src = (char *)data;
	
	tmir |= (id & 0x1FFFFFFF) << 3;

	tmd0r = src[0];
	tmd0r |= src[1] << 8;
	tmd0r |= src[2] << 16;
	tmd0r |= src[3] << 24;

	tmd1r = src[4];
	tmd1r |= src[5] << 8;
	tmd1r |= src[6] << 16;
	tmd1r |= src[7] << 24;

retry:
	if (getBitData(mPeri->TSTR, 26))
	{
		mPeri->TxMailBox[0].TMD1R = tmd1r;
		mPeri->TxMailBox[0].TMD0R = tmd0r;
		setFieldData(mPeri->TxMailBox[0].TMPR, 0xF << 0, size, 0); 
		mPeri->TxMailBox[0].TMIR = tmir;
	}
	else
	{
		thread::yield();
		goto retry;
	}

	return true;
}

bool Can::send(unsigned short id, void *data, unsigned char size)
{
	unsigned int tmir = 0x01, tmd0r, tmd1r;
	char *src = (char *)data;
	
	tmir |= (id & 0x7FF) << 21;

	tmd0r = src[0];
	tmd0r |= src[1] << 8;
	tmd0r |= src[2] << 16;
	tmd0r |= src[3] << 24;

	tmd1r = src[4];
	tmd1r |= src[5] << 8;
	tmd1r |= src[6] << 16;
	tmd1r |= src[7] << 24;

retry:
	if (getBitData(mPeri->TSTR, 26))
	{
		mPeri->TxMailBox[0].TMD1R = tmd1r;
		mPeri->TxMailBox[0].TMD0R = tmd0r;
		setFieldData(mPeri->TxMailBox[0].TMPR, 0xF << 0, size, 0); 
		mPeri->TxMailBox[0].TMIR = tmir;
	}
	else
	{
		thread::yield();
		goto retry;
	}

	return true;
}

void Can::flush(void)
{
	mTail = mHead = 0;
}

void Can::isr(void)
{
	setBitData(mPeri->IER, false, 1); // Fifo0 Pending Interrupt Disable
	push(mPeri->FIFOMailBox[0].RFMIR, mPeri->FIFOMailBox[0].RFMPR, mPeri->FIFOMailBox[0].RFMD0R, mPeri->FIFOMailBox[0].RFMD1R);
	setBitData(mPeri->RFR0, true, 5); // Receive FIFO0 dequeue
	setBitData(mPeri->IER, true, 1); // Fifo0 Pending Interrupt Enable
}
}

#endif