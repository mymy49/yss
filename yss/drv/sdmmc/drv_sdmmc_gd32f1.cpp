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

#if defined(GD32F1)

#include <drv/Sdmmc.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <util/ElapsedTime.h>

#include <__cross_studio_io.h>

#define POWER_OFF 1
#define POWER_ON 3

enum
{
	BLOCK_1_BYTE = 0,
	BLOCK_2_BYTES = 1,
	BLOCK_4_BYTES = 2,
	BLOCK_8_BYTES = 3,
	BLOCK_16_BYTES = 4,
	BLOCK_32_BYTES = 5,
	BLOCK_64_BYTES = 6,
	BLOCK_128_BYTES = 7,
	BLOCK_256_BYTES = 8,
	BLOCK_512_BYTES = 9,
	BLOCK_1024_BYTES = 10,
	BLOCK_2048_BYTES = 11,
	BLOCK_4096_BYTES = 12,
	BLOCK_8192_BYTES = 13,
	BLOCK_16384_BYTES = 14,
};

void thread_taskSdmmc(void *var);

Sdmmc::Sdmmc(const Drv::Config &drvConfig, const Config &config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
	mAcmdFlag = false;
}

bool Sdmmc::init(void)
{
	mPeri->CLKCTLR |= SDIO_CLKCTLR_HWFL_EN | SDIO_CLKCTLR_PWRSAV;

	return true;
}

void Sdmmc::lock(void)
{
	Mutex::lock();
}

void Sdmmc::unlock(void)
{
	Mutex::unlock();
}

#define SHORT_RESP 1
#define LONG_RESP 3
#define setWaitResp(des, x) des |= x << 6

error Sdmmc::sendCmd(unsigned char cmd, unsigned int arg, unsigned char responseType)
{
	unsigned int reg = cmd | SDIO_CMD_CSMEN, status, statusChkFlag;
	const char response[3] = {0, 1, 3};
	
	mPeri->PARA = arg;			// 아규먼트 세팅
	mPeri->ICR = 0xffffffff;	// 모든 인터럽트 클리어
	mPeri->STR;
	mPeri->DTTR = 0x200000;
	
	setWaitResp(reg, response[responseType]);
	mPeri->CMD = reg;	// 명령어 전송

	while (true)
	{
		status = mPeri->STR; // 상태 레지스터 읽기
		if (status & (SDIO_STR_CMDSENT | SDIO_STR_CMDREND))
			break;
		else if (status & (SDIO_STR_CMDTMOUT | SDIO_STR_DTTMOUT | SDIO_STR_CCRCFAIL | SDIO_STR_DTCRCFAIL))
			goto error_handler;
		thread::yield();
	}
	
	mLastResponseCmd = mPeri->RESPCMD;
	if(cmd != mLastResponseCmd)
	{
		mPeri->CMD = 0;	// 명령어 리셋
		return Error::NO_RESPONSE_CMD;
	}

	mPeri->CMD = 0;	// 명령어 리셋
	return Error::NONE;

error_handler:
	mPeri->CMD = 0;	// 명령어 리셋

	if(status & SDIO_STR_CMDTMOUT)
		return Error::CMD_TIMEOUT;
	else if(status & SDIO_STR_DTTMOUT)
		return Error::DATA_TIMEOUT;
	else if(status & SDIO_STR_CCRCFAIL)
		return Error::CMD_CRC_FAIL;
	else 
		return Error::DATA_CRC_FAIL;
}


void Sdmmc::setPower(bool en)
{
	if(en)
		setFieldData(mPeri->POWER, SDIO_POWER_PWRSTATE, POWER_ON, 0);
	else
		setFieldData(mPeri->POWER, SDIO_POWER_PWRSTATE, POWER_OFF, 0);
}

unsigned int Sdmmc::getShortResponse(void)
{
	return mPeri->RESP1;
}

void Sdmmc::getLongResponse(void *des)
{
	unsigned char *cDes = (unsigned char*)des;
	unsigned char *cSrc;
	unsigned int reg;
	
	reg = mPeri->RESP1;
	cSrc = (unsigned char*)&reg;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 0] 127 ~ 120
	*cDes++ = *cSrc--;	// [ 1] 119 ~ 112
	*cDes++ = *cSrc--;	// [ 2] 111 ~ 104
	*cDes++ = *cSrc--;	// [ 3] 103 ~  96

	reg = mPeri->RESP2;
	cSrc = (unsigned char*)&reg;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 4]  95 ~  88
	*cDes++ = *cSrc--;	// [ 5]  87 ~  80
	*cDes++ = *cSrc--;	// [ 6]  79 ~  72
	*cDes++ = *cSrc--;	// [ 7]  71 ~  64

	reg = mPeri->RESP3;
	cSrc = (unsigned char*)&reg;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 8]  63 ~  56
	*cDes++ = *cSrc--;	// [ 9]  55 ~  48
	*cDes++ = *cSrc--;	// [10]  47 ~  40
	*cDes++ = *cSrc--;	// [11]  39 ~  32

	reg = mPeri->RESP4;
	cSrc = (unsigned char*)&reg;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [12]  31 ~  24
	*cDes++ = *cSrc--;	// [13]  23 ~  16
	*cDes++ = *cSrc--;	// [14]  15 ~   8
	*cDes++ = *cSrc--;	// [15]   7 ~   0
}

void Sdmmc::setSdioClockBypass(bool en)
{
	setBitData(mPeri->CLKCTLR, en, 10);
}

void Sdmmc::setClockFrequency(int frequency)
{
	int clock = getClockFrequency() / frequency - 2;

	if(clock > 255)
		clock = 255;
	else if(clock < 0)
		clock = 0;

	setFieldData(mPeri->CLKCTLR, SDIO_CLKCTLR_DIV, clock, 0);
}

void Sdmmc::setSdioClockEn(bool en)
{
	setBitData(mPeri->CLKCTLR, en, 8);
}

void Sdmmc::readyRead(void *des, unsigned short length)
{
	mRxDma->lock();
	while(mPeri->STR & SDIO_STR_RXDTVAL)
		mPeri->FIFO;

	mPeri->ICR = 0xffffffff;	// 모든 인터럽트 클리어
	
#define DBLOCKSIZE_Pos		4

	mPeri->DTCTLR =	mBlockSize << DBLOCKSIZE_Pos | 
					SDIO_DTCTLR_DTTDIR |
					SDIO_DTCTLR_DMAEN |
					SDIO_DTCTLR_DTTEN;
//	mPeri->DTCTLR |= SDIO_DTCTLR_DTTEN;
	
	length >>= 2;
	mRxDma->ready(mRxDmaInfo, des, length);
}

void Sdmmc::readyWrite(void *des, unsigned short length)
{
	mTxDma->lock();
	mTxDma->ready(mTxDmaInfo, des, length);
}

error Sdmmc::waitUntilReadComplete(void)
{
	ElapsedTime timeout;
	unsigned int status;

	while (true)
	{
		status = mPeri->STR; // 상태 레지스터 읽기
		if (status & SDIO_STR_DTEND && mRxDma->isComplete())
		{
			mRxDma->stop();
			mRxDma->unlock();
			return Error::NONE;
		}
		else if (status & (SDIO_STR_DTCRCFAIL | SDIO_STR_DTTMOUT | SDIO_STR_RXORE) || mRxDma->isError())
			goto error_handle;
		else if(timeout.getMsec() > 1000)
		{
			mRxDma->stop();
			mRxDma->unlock();
			mPeri->CMD = 0;	// 명령어 리셋
			return Error::TIMEOUT;
		}
		thread::yield();
	}

error_handle :
	mRxDma->stop();
	mRxDma->unlock();
	mPeri->CMD = 0;	// 명령어 리셋

	if(status & SDIO_STR_DTCRCFAIL)
		return Error::DATA_CRC_FAIL;
	else if(status & SDIO_STR_DTTMOUT)
		return Error::DATA_TIMEOUT;
	else if(status & SDIO_STR_RXORE)
		return Error::RX_OVERRUN;
	else 
		return Error::DMA;
}

error Sdmmc::waitUntilWriteComplete(void)
{
	ElapsedTime timeout;
	unsigned int status;

	mPeri->STR;
	mPeri->DTCTLR =	mBlockSize << DBLOCKSIZE_Pos | 
					SDIO_DTCTLR_DMAEN |
					SDIO_DTCTLR_DTTEN;

	while (true)
	{
		status = mPeri->STR; // 상태 레지스터 읽기
		if (status & (SDIO_STR_DTEND) && mTxDma->isComplete())
		{
			mTxDma->stop();
			mTxDma->unlock();
			return Error::NONE;
		}
		else if (status & (SDIO_STR_DTCRCFAIL | SDIO_STR_DTTMOUT | SDIO_STR_TXURE) || mTxDma->isError())
			goto error_handle;
		else if(timeout.getMsec() > 1000)
		{
			mTxDma->stop();
			mTxDma->unlock();
			mPeri->CMD = 0;	// 명령어 리셋
			return Error::TIMEOUT;
		}

		thread::yield();
	}

error_handle :
	mTxDma->stop();
	mTxDma->unlock();
	mPeri->CMD = 0;	// 명령어 리셋

	if(status & SDIO_STR_DTCRCFAIL)
		return Error::DATA_CRC_FAIL;
	else if(status & SDIO_STR_DTTMOUT)
		return Error::DATA_TIMEOUT;
	else if(status & SDIO_STR_TXURE)
		return Error::TX_UNDERRUN;
	else 
		return Error::DMA;
}

void Sdmmc::unlockRead(void)
{
	mPeri->CMD = 0;
	mRxDma->unlock();
}

void Sdmmc::unlockWrite(void)
{
	mPeri->CMD = 0;
	mTxDma->unlock();
}

void Sdmmc::setDataBlockSize(unsigned char blockSize)
{
	int dlen = 1 << blockSize;

	mBlockSize = blockSize;
	mPeri->DTLEN = dlen;
}

#define BUSMOD_Pos	4

bool Sdmmc::setBusWidth(unsigned char width)
{
	switch(width)
	{
	case SdMemory::BUS_WIDTH_1BIT :
		setFieldData(mPeri->CLKCTLR, SDIO_CLKCTLR_BUSMODE, 0, BUSMOD_Pos);
		return true;
	case SdMemory::BUS_WIDTH_4BIT :
		setFieldData(mPeri->CLKCTLR, SDIO_CLKCTLR_BUSMODE, 1, BUSMOD_Pos);
		return true;
	case SdMemory::BUS_WIDTH_8BIT :
		setFieldData(mPeri->CLKCTLR, SDIO_CLKCTLR_BUSMODE, 2, BUSMOD_Pos);
		return true;
	}

	return false;
}

#endif

