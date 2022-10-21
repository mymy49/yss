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

#if defined(GD32F1) || defined(GD32F4) || defined(STM32F1)

#include <drv/Sdmmc.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <util/ElapsedTime.h>
#include <cmsis/mcu/common/sdmmc_stm32_gd32f1.h>

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

enum
{
	POWER = 0, CLKCR, ARG, CMD,
	RESPCMD, RESP1, RESP2, RESP3,
	RESP4, DTIMER, DLEN, DCTRL,
	DCOUNT, STA, ICR, MASK,
	FIFOCNT = 18,
	FIFO = 32
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
	mPeri[CLKCR] |= SDIO_CLKCR_HWFC_EN_Msk | SDIO_CLKCR_PWRSAV_Msk;

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

error Sdmmc::sendCmd(uint8_t cmd, uint32_t arg, uint8_t responseType)
{
	uint32_t reg = cmd | SDIO_CMD_CPSMEN_Msk, status, statusChkFlag;
	const int8_t response[3] = {0, 1, 3};
	
	mPeri[ARG] = arg;			// 아규먼트 세팅
	mPeri[ICR] = 0xffffffff;	// 모든 인터럽트 클리어
	mPeri[STA];
	mPeri[DTIMER] = 50000000;
	
	setWaitResp(reg, response[responseType]);
	mPeri[CMD] = reg;	// 명령어 전송

	while (true)
	{
		status = mPeri[STA]; // 상태 레지스터 읽기
		if (status & (SDIO_STA_CMDSENT | SDIO_STA_CMDREND))
			break;
		else if (status & (SDIO_STA_CTIMEOUT_Msk | SDIO_STA_DTIMEOUT_Msk | SDIO_STA_CCRCFAIL_Msk | SDIO_STA_DCRCFAIL_Msk))
			goto error_handler;
		thread::yield();
	}
	
	mLastResponseCmd = mPeri[RESPCMD];
	if(cmd != mLastResponseCmd)
	{
		mPeri[CMD] = 0;	// 명령어 리셋
		return Error::NO_RESPONSE_CMD;
	}

	mPeri[CMD] = 0;	// 명령어 리셋
	return Error::NONE;

error_handler:
	mPeri[CMD] = 0;	// 명령어 리셋

	if(status & SDIO_STA_CTIMEOUT_Msk)
		return Error::CMD_TIMEOUT;
	else if(status & SDIO_STA_DTIMEOUT_Msk)
		return Error::DATA_TIMEOUT;
	else if(status & SDIO_STA_CCRCFAIL_Msk)
		return Error::CMD_CRC_FAIL;
	else 
		return Error::DATA_CRC_FAIL;
}


void Sdmmc::setPower(bool en)
{
	if(en)
		setFieldData(mPeri[POWER], SDIO_POWER_PWRCTRL_Msk, POWER_ON, SDIO_POWER_PWRCTRL_Pos);
	else
		setFieldData(mPeri[POWER], SDIO_POWER_PWRCTRL_Msk, POWER_OFF, SDIO_POWER_PWRCTRL_Pos);
}

uint32_t Sdmmc::getShortResponse(void)
{
	return mPeri[RESP1];
}

void Sdmmc::getLongResponse(void *des)
{
	uint8_t *cDes = (uint8_t*)des;
	uint8_t *cSrc;
	uint32_t reg;
	
	reg = mPeri[RESP1];
	cSrc = (uint8_t*)&reg;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 0] 127 ~ 120
	*cDes++ = *cSrc--;	// [ 1] 119 ~ 112
	*cDes++ = *cSrc--;	// [ 2] 111 ~ 104
	*cDes++ = *cSrc--;	// [ 3] 103 ~  96

	reg = mPeri[RESP2];
	cSrc = (uint8_t*)&reg;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 4]  95 ~  88
	*cDes++ = *cSrc--;	// [ 5]  87 ~  80
	*cDes++ = *cSrc--;	// [ 6]  79 ~  72
	*cDes++ = *cSrc--;	// [ 7]  71 ~  64

	reg = mPeri[RESP3];
	cSrc = (uint8_t*)&reg;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 8]  63 ~  56
	*cDes++ = *cSrc--;	// [ 9]  55 ~  48
	*cDes++ = *cSrc--;	// [10]  47 ~  40
	*cDes++ = *cSrc--;	// [11]  39 ~  32

	reg = mPeri[RESP4];
	cSrc = (uint8_t*)&reg;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [12]  31 ~  24
	*cDes++ = *cSrc--;	// [13]  23 ~  16
	*cDes++ = *cSrc--;	// [14]  15 ~   8
	*cDes++ = *cSrc--;	// [15]   7 ~   0
}

void Sdmmc::setSdioClockBypass(bool en)
{
	setBitData(mPeri[CLKCR], en, 10);
}

void Sdmmc::setClockFrequency(int32_t  frequency)
{
	int32_t  clock = getClockFrequency() / frequency - 2;

	if(clock > 255)
		clock = 255;
	else if(clock < 0)
		clock = 0;

	setFieldData(mPeri[CLKCR], SDIO_CLKCR_CLKDIV_Msk, clock, SDIO_CLKCR_CLKDIV_Pos);
}

void Sdmmc::setSdioClockEn(bool en)
{
	setBitData(mPeri[CLKCR], en, 8);
}

void Sdmmc::readyRead(void *des, uint16_t length)
{
	mRxDma->lock();
	while(mPeri[STA] & SDIO_STA_RXDAVL_Msk)
		mPeri[FIFO];

	mPeri[ICR] = 0xffffffff;	// 모든 인터럽트 클리어
	mPeri[DCTRL] =	mBlockSize << SDIO_DCTRL_DBLOCKSIZE_Pos | 
					SDIO_DCTRL_DTDIR_Msk |
					SDIO_DCTRL_DMAEN_Msk |
					SDIO_DCTRL_DTEN_Msk;
	
	length >>= 2;
	mRxDma->ready(mRxDmaInfo, des, length);
}

void Sdmmc::readyWrite(void *des, uint16_t length)
{
	mTxDma->lock();
	mTxDma->ready(mTxDmaInfo, des, length);
}

error Sdmmc::waitUntilReadComplete(void)
{
	ElapsedTime timeout;
	uint32_t status;

	while (true)
	{
		status = mPeri[STA]; // 상태 레지스터 읽기
		if (status & SDIO_STA_DATAEND_Msk && mRxDma->isComplete())
		{
			mRxDma->stop();
			mRxDma->unlock();
			return Error::NONE;
		}
		else if (status & (SDIO_STA_DCRCFAIL_Msk | SDIO_STA_DTIMEOUT_Msk | SDIO_STA_RXOVERR_Msk) || mRxDma->isError())
			goto error_handle;
		else if(timeout.getMsec() > 1000)
		{
			mRxDma->stop();
			mRxDma->unlock();
			mPeri[CMD] = 0;	// 명령어 리셋
			return Error::TIMEOUT;
		}
		thread::yield();
	}

error_handle :
	mRxDma->stop();
	mRxDma->unlock();
	mPeri[CMD] = 0;	// 명령어 리셋

	if(status & SDIO_STA_DCRCFAIL_Msk)
		return Error::DATA_CRC_FAIL;
	else if(status & SDIO_STA_DTIMEOUT_Msk)
		return Error::DATA_TIMEOUT;
	else if(status & SDIO_STA_RXOVERR_Msk)
		return Error::RX_OVERRUN;
	else 
		return Error::DMA;
}

error Sdmmc::waitUntilWriteComplete(void)
{
	ElapsedTime timeout;
	uint32_t status;

	mPeri[STA];
	mPeri[DCTRL] =	mBlockSize << SDIO_DCTRL_DBLOCKSIZE_Pos | 
					SDIO_DCTRL_DMAEN_Msk |
					SDIO_DCTRL_DTEN_Msk;

	while (true)
	{
		status = mPeri[STA]; // 상태 레지스터 읽기
		if (status & (SDIO_STA_DATAEND_Msk) && mTxDma->isComplete())
		{
			mTxDma->stop();
			mTxDma->unlock();
			return Error::NONE;
		}
		else if (status & (SDIO_STA_DCRCFAIL_Msk | SDIO_STA_DTIMEOUT_Msk | SDIO_STA_TXUNDERR_Msk) || mTxDma->isError())
			goto error_handle;
		else if(timeout.getMsec() > 1000)
		{
			mTxDma->stop();
			mTxDma->unlock();
			mPeri[CMD] = 0;	// 명령어 리셋
			return Error::TIMEOUT;
		}

		thread::yield();
	}

error_handle :
	mTxDma->stop();
	mTxDma->unlock();
	mPeri[CMD] = 0;	// 명령어 리셋

	if(status & SDIO_STA_DCRCFAIL_Msk)
		return Error::DATA_CRC_FAIL;
	else if(status & SDIO_STA_DTIMEOUT_Msk)
		return Error::DATA_TIMEOUT;
	else if(status & SDIO_STA_TXUNDERR_Msk)
		return Error::TX_UNDERRUN;
	else 
		return Error::DMA;
}

void Sdmmc::unlockRead(void)
{
	mPeri[CMD] = 0;
	mRxDma->unlock();
}

void Sdmmc::unlockWrite(void)
{
	mPeri[CMD] = 0;
	mTxDma->unlock();
}

void Sdmmc::setDataBlockSize(uint8_t blockSize)
{
	int32_t  dlen = 1 << blockSize;

	mBlockSize = blockSize;
	mPeri[DLEN] = dlen;
}

bool Sdmmc::setBusWidth(uint8_t width)
{
	switch(width)
	{
	case SdMemory::BUS_WIDTH_1BIT :
		setFieldData(mPeri[CLKCR], SDIO_CLKCR_WIDBUS_Msk, 0, SDIO_CLKCR_WIDBUS_Pos);
		return true;
	case SdMemory::BUS_WIDTH_4BIT :
		setFieldData(mPeri[CLKCR], SDIO_CLKCR_WIDBUS_Msk, 1, SDIO_CLKCR_WIDBUS_Pos);
		return true;
	case SdMemory::BUS_WIDTH_8BIT :
		setFieldData(mPeri[CLKCR], SDIO_CLKCR_WIDBUS_Msk, 2, SDIO_CLKCR_WIDBUS_Pos);
		return true;
	}

	return false;
}

#endif

