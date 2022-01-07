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

#if defined(STM32F7)

#include <drv/Sdmmc.h>
#include <yss/thread.h>
#include <yss/reg.h>

#include <__cross_studio_io.h>

#define POWER_OFF 1
#define POWER_ON 3

namespace drv
{
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
	mDma = &config.txDma;
	mDmaInfo = config.txDmaInfo;
	mAcmdFlag = false;
}

bool Sdmmc::init(void)
{
	setFieldData(mPeri->CLKCR, SDMMC_CLKCR_CLKDIV_Msk, 118, SDMMC_CLKCR_CLKDIV_Pos);

	mPeri->DTIMER = 0xFFFFFFFF;

	return true;
}

#define SHORT_RESP 1
#define LONG_RESP 3
#define setWaitResp(des, x) des |= x << 6

unsigned char Sdmmc::sendCmd(unsigned char cmd, unsigned int arg, unsigned char responseType)
{
	unsigned int reg = cmd | SDMMC_CMD_CPSMEN_Msk, status, statusChkFlag;

	mPeri->ICR = 0xffffffff;	// 모든 인터럽트 클리어
	mPeri->ARG = arg;			// 아규먼트 세팅
	
	switch(responseType)
	{
	case SdMemory::RESPONSE_NONE :
		break;

	case SdMemory::RESPONSE_SHORT :
		setWaitResp(reg, SHORT_RESP);
		break;

	case SdMemory::RESPONSE_LONG :
		setWaitResp(reg, LONG_RESP);
		break;
	}

	//switch (cmd)
	//{
	//case 0:
	//	statusChkFlag = SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk;
	//	break;
	//case  1:case  3:case  7:case  8:case 55:
	//	statusChkFlag = SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk;
	//	setWaitResp(reg, SHORT_RESP);
	//	break;

	//case 2:
	//	statusChkFlag = SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk;
	//	setWaitResp(reg, LONG_RESP);
	//	break;

	//case  9:
	//	statusChkFlag = SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk | SDMMC_STA_CTIMEOUT_Msk;
	//	setWaitResp(reg, LONG_RESP);
	//	break;

	//case 13:
	//	if(mAcmdFlag)
	//		statusChkFlag = SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk | SDMMC_STA_CCRCFAIL_Msk;
	//	else
	//		statusChkFlag = SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk;

	//	setWaitResp(reg, SHORT_RESP);
	//	break;

	//case 41:
	//	if(mAcmdFlag)
	//	{
	//		statusChkFlag = SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk | SDMMC_STA_CCRCFAIL_Msk;
	//		setWaitResp(reg, SHORT_RESP);
	//	}
	//	break;
	//default:
	//	return false;
	//}

	mPeri->CMD = reg;	// 명령어 전송

	while (true)
	{
		status = mPeri->STA; // 상태 레지스터 읽기
		if (status & (SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk))
			break;
		else if (status & (SDMMC_STA_CTIMEOUT_Msk | SDMMC_STA_DTIMEOUT_Msk | SDMMC_STA_CCRCFAIL_Msk | SDMMC_STA_DCRCFAIL_Msk))
			break;
		thread::yield();
	}
	
	mLastResponseCmd = mPeri->RESPCMD;
	if(cmd != mLastResponseCmd)
	{
		mPeri->CMD = 0;	// 명령어 리셋
		return ERROR_RESPONSE_CMD;
	}

	//switch (cmd)
	//{
	//case 0:case 2:
	//	if ( != 0x3f)
	//		goto error;
	//	break;
	//case 41:
	//	if(mAcmdFlag && mPeri->RESPCMD != 0x3f)
	//		goto error;
	//	break;
	//case 9 :
	//	break;
	//default:
	//	if (mPeri->RESPCMD != cmd)
	//		goto error;
	//	break;
	//}

	mPeri->CMD = 0;	// 명령어 리셋
	return ERROR_NONE;
error:
	mPeri->CMD = 0;	// 명령어 리셋

	if(status & SDMMC_STA_CTIMEOUT_Msk)
		return ERROR_CMD_TIMEOUT;
	else if(status & SDMMC_STA_DTIMEOUT_Msk)
		return ERROR_DATA_TIMEOUT;
	else if(status & SDMMC_STA_CCRCFAIL_Msk)
		return ERROR_CMD_CRC;
	else 
		return SDMMC_STA_DCRCFAIL_Msk;
}


void Sdmmc::setPower(bool en)
{
	if(en)
		setFieldData(mPeri->POWER, SDMMC_POWER_PWRCTRL_Msk, POWER_ON, SDMMC_POWER_PWRCTRL_Pos);
	else
		setFieldData(mPeri->POWER, SDMMC_POWER_PWRCTRL_Msk, POWER_OFF, SDMMC_POWER_PWRCTRL_Pos);
}

unsigned int Sdmmc::getShortResponse(void)
{
	return mPeri->RESP1;
}

void Sdmmc::getLongResponse(void *des)
{
	unsigned char *cDes = (unsigned char*)des;
	unsigned char *cSrc = (unsigned char*)&mPeri->RESP1;
	
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 0] 127 ~ 120
	*cDes++ = *cSrc--;	// [ 1] 119 ~ 112
	*cDes++ = *cSrc--;	// [ 2] 111 ~ 104
	*cDes++ = *cSrc--;	// [ 3] 103 ~  96
	cSrc = (unsigned char*)&mPeri->RESP2;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 4]  95 ~  88
	*cDes++ = *cSrc--;	// [ 5]  87 ~  80
	*cDes++ = *cSrc--;	// [ 6]  79 ~  72
	*cDes++ = *cSrc--;	// [ 7]  71 ~  64
	cSrc = (unsigned char*)&mPeri->RESP3;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [ 8]  63 ~  56
	*cDes++ = *cSrc--;	// [ 9]  55 ~  48
	*cDes++ = *cSrc--;	// [10]  47 ~  40
	*cDes++ = *cSrc--;	// [11]  39 ~  32
	cSrc = (unsigned char*)&mPeri->RESP4;
	cSrc = &cSrc[3];
	*cDes++ = *cSrc--;	// [12]  31 ~  24
	*cDes++ = *cSrc--;	// [13]  23 ~  16
	*cDes++ = *cSrc--;	// [14]  15 ~   8
	*cDes++ = *cSrc--;	// [15]   7 ~   0
}

void Sdmmc::setSdioClockBypass(bool en)
{
	setBitData(mPeri->CLKCR, en, SDMMC_CLKCR_BYPASS_Pos);
}

void Sdmmc::setSdioClockEn(bool en)
{
	setBitData(mPeri->CLKCR, en, SDMMC_CLKCR_CLKEN_Pos);
}

void Sdmmc::readyRead(void *des, unsigned short length)
{
	mPeri->DCTRL =	mBlockSize << SDMMC_DCTRL_DBLOCKSIZE_Pos | 
					SDMMC_DCTRL_DTDIR_Msk |
					SDMMC_DCTRL_DMAEN_Msk |
					SDMMC_DCTRL_DTEN_Msk;
	
	mDma->lock();
	mDma->readyRx(mDmaInfo, des, length);
}

bool Sdmmc::waitUntilReadComplete(void)
{
	unsigned int status;

	while (true)
	{
		status = mPeri->STA; // 상태 레지스터 읽기
		if (status & (SDMMC_STA_DATAEND_Msk))
			return true;
		else if (status & (SDMMC_STA_DCRCFAIL_Msk | SDMMC_STA_DTIMEOUT_Msk | SDMMC_STA_RXOVERR_Msk))
			return false;
		thread::yield();
	}
}

void Sdmmc::setDataBlockSize(unsigned char blockSize)
{
	int dlen = 0;

	switch(blockSize)
	{
	case SdMemory::BLOCK_1_BYTE :
		mBlockSize = BLOCK_1_BYTE;
		dlen = 1;
		break;
	
	case SdMemory::BLOCK_2_BYTES :
		mBlockSize = BLOCK_2_BYTES;
		dlen = 2;
		break;

	case SdMemory::BLOCK_4_BYTES :
		mBlockSize = BLOCK_4_BYTES;
		dlen = 4;
		break;

	case SdMemory::BLOCK_8_BYTES :
		mBlockSize = BLOCK_8_BYTES;
		dlen = 8;
		break;

	case SdMemory::BLOCK_16_BYTES :
		mBlockSize = BLOCK_16_BYTES;
		dlen = 16;
		break;

	case SdMemory::BLOCK_32_BYTES :
		mBlockSize = BLOCK_32_BYTES;
		dlen = 32;
		break;

	case SdMemory::BLOCK_64_BYTES :
		mBlockSize = BLOCK_64_BYTES;
		dlen = 64;
		break;

	case SdMemory::BLOCK_128_BYTES :
		mBlockSize = BLOCK_128_BYTES;
		dlen = 128;
		break;

	case SdMemory::BLOCK_256_BYTES :
		mBlockSize = BLOCK_256_BYTES;
		dlen = 256;
		break;

	case SdMemory::BLOCK_512_BYTES :
		mBlockSize = BLOCK_512_BYTES;
		dlen = 512;
		break;

	case SdMemory::BLOCK_1024_BYTES :
		mBlockSize = BLOCK_1024_BYTES;
		dlen = 1024;
		break;

	case SdMemory::BLOCK_2048_BYTES :
		mBlockSize = BLOCK_2048_BYTES;
		dlen = 2048;
		break;

	case SdMemory::BLOCK_4096_BYTES :
		mBlockSize = BLOCK_4096_BYTES;
		dlen = 4096;
		break;

	case SdMemory::BLOCK_8192_BYTES :
		mBlockSize = BLOCK_8192_BYTES;
		dlen = 8192;
		break;

	case SdMemory::BLOCK_16384_BYTES :
		mBlockSize = BLOCK_16384_BYTES;
		dlen = 16384;
		break;
	}

	mPeri->DLEN = dlen;
}

bool Sdmmc::setBusWidth(unsigned char width)
{
	switch(width)
	{
	case SdMemory::BUS_WIDTH_1BIT :
		setFieldData(mPeri->CLKCR, SDMMC_CLKCR_WIDBUS_Msk, 0, SDMMC_CLKCR_WIDBUS_Pos);
		break;
	case SdMemory::BUS_WIDTH_4BIT :
		setFieldData(mPeri->CLKCR, SDMMC_CLKCR_WIDBUS_Msk, 1, SDMMC_CLKCR_WIDBUS_Pos);
		break;
	case SdMemory::BUS_WIDTH_8BIT :
		setFieldData(mPeri->CLKCR, SDMMC_CLKCR_WIDBUS_Msk, 2, SDMMC_CLKCR_WIDBUS_Pos);
		break;
	}
}

}

#endif

