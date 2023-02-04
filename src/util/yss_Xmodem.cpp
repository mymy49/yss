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

#include <external/crc16.h>
#include <drv/peripheral.h>
#include <util/ElapsedTime.h>
#include <util/Xmodem.h>
#include <yss/thread.h>

#if !defined(YSS_DRV_UART_UNSUPPORTED)

#define SOH 0x01
#define EOT 0x04
#define ACK 0x06
#define NAK 0x15
#define CAN 0x18

static void thread_handleXmodem(void *var);
extern const uint16_t crc16tab[256];

Xmodem::Xmodem(Uart &uart)
{
	mUart = &uart;
	mRetryNum = 20;
	mThreadId = 0;
	mReceiveHandler = 0;
	mCompleteFlag = false;
}

void Xmodem::start(void)
{
	mMutex.lock();
	if (mThreadId)
	{
		mUart->unlock();
		thread::remove(mThreadId);
		mThreadId = 0;
	}
	mMutex.unlock();
	mCompleteFlag = false;

	mThreadId = thread::add(thread_handleXmodem, this, 512);
}

uint8_t Xmodem::receiveOnePacket(void)
{
	int16_t rcvData;
	uint16_t index = 0;
	ElapsedTime timeout;

	while (1)
	{
		rcvData = mUart->get();
		if (rcvData >= 0)
		{
			if (index == 0)
			{
				if (rcvData != SOH)
					return rcvData;
			}

			mPaceketData[index++] = rcvData;
			if (index >= 132)
			{
				// 문서에는 CRC가 2바이트라고 표현되어 있지만
				// minicom을 통한 전송에서 CRC는 1바이트만 들어오는 문제로
				// CRC 검사는 무시함. 추후 변경 필요
				if (mReceiveHandler)
					mReceiveHandler(mPaceketData[1], &mPaceketData[3]);
				return ACK;
			}
		}
		else
			thread::yield();

		if (timeout.getMsec() >= 3000)
			return NAK;
	}
}

void Xmodem::setReceiveHandler(void (*handler)(uint8_t packetNum, uint8_t *data))
{
	mReceiveHandler = handler;
}

void Xmodem::process(void)
{
	const int8_t ack = 0x06, nak = 0x15;
	uint8_t packet = 1, retryCount = 0;
	uint16_t rcvCnt = 0;
	bool eraseFlag = false;

	mResultFlag = false;
	mCompleteFlag = false;

	mUart->lock();
	mUart->flush();
	mUart->send(&nak, 1);

	while (1)
	{
		switch (receiveOnePacket())
		{
		case NAK:
			mUart->send(&nak, 1);
			retryCount++;
			if (retryCount > mRetryNum)
				goto complete;
			break;
		case ACK:
			mUart->send(&ack, 1);
			break;
		case EOT:
			mResultFlag = true;
		case CAN:
			mUart->send(&ack, 1);
			goto complete;
		}
	}

complete:
	mMutex.lock();
	mUart->unlock();
	mThreadId = 0;
	mCompleteFlag = true;
	mMutex.unlock();
	return;
}

void Xmodem::setRetry(uint32_t num)
{
	mRetryNum = num;
}

void Xmodem::stop(void)
{
	mMutex.lock();
	if (mThreadId)
	{
		mUart->unlock();
		mThreadId = 0;
		mCompleteFlag = true;
	}
	mMutex.unlock();
}

bool Xmodem::isComplete(void)
{
	return mCompleteFlag;
}

static void thread_handleXmodem(void *var)
{
	Xmodem *xmodem = (Xmodem *)var;
	xmodem->process();
}

#endif

