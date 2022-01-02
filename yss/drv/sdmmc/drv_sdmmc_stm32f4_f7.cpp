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
void thread_taskSdmmc(void *var);

Sdmmc::Sdmmc(const Drv::Config &drvConfig, const Config &config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mAcmdFlag = false;
}

bool Sdmmc::init(void)
{
	setFieldData(mPeri->CLKCR, SDMMC_CLKCR_CLKDIV_Msk, 118, SDMMC_CLKCR_CLKDIV_Pos);

	mPeri->DTIMER = 0xFFFF;

	return true;
}

#define SHORT_RESP 1
#define LONG_RESP 3
#define setWaitResp(des, x) des |= x << 6

bool Sdmmc::sendCmd(unsigned char cmd, unsigned int arg)
{
	unsigned int reg = cmd | SDMMC_CMD_CPSMEN_Msk, status;

	mPeri->ICR = 0xffffffff;	// 모든 인터럽트 클리어
	mPeri->ARG = arg;			// 아규먼트 세팅

	switch (cmd)
	{
	case 0:
		break;

	case  1:case  3:case  7:case  8:case 41:case 55:
		setWaitResp(reg, SHORT_RESP);
		break;

	case 2:
		setWaitResp(reg, LONG_RESP);
		break;
	
	case 13:
		setWaitResp(reg, SHORT_RESP);
		
		if(mAcmdFlag)
			reg |= SDMMC_CMD_WAITPEND_Msk;
		break;

	default:
		return false;
	}

	mPeri->CMD = reg;	// 명령어 전송

	while (true)
	{
		status = mPeri->STA; // 상태 레지스터 읽기
		if ((status & (SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk | SDMMC_STA_CCRCFAIL_Msk)) != 0)
			break;
		else if ((status & (SDMMC_STA_CTIMEOUT_Msk)) != 0)
			goto error;
		thread::yield();
	}

	switch (cmd)
	{
	case 0:case 2:case 41:
		if (mPeri->RESPCMD != 0x3f)
			goto error;
		break;
	default:
		if (mPeri->RESPCMD != cmd)
			goto error;
		break;
	}

	mPeri->CMD = 0;	// 명령어 리셋
	return true;
error:
	mPeri->CMD = 0;	// 명령어 리셋
	return false;
}

bool Sdmmc::sendAcmd(unsigned char cmd, unsigned int arg)
{
	// CMD55 - 다음 명령을 ACMD로 인식 하도록 사전에 보냄
	if (sendCmd(55, 0) == false) 
		goto error;

	mAcmdFlag = true;
	if (mPeri->RESP1 != 0x00000120)
		goto error;
	
	mAcmdFlag = false;
	// 이번에 전송하는 명령을 ACMD로 인식
	return sendCmd(cmd, arg); 

error:
	mAcmdFlag = false;
	return false;
}

void Sdmmc::setPower(bool en)
{
	if(en)
		setFieldData(mPeri->POWER, SDMMC_POWER_PWRCTRL_Msk, POWER_ON, SDMMC_POWER_PWRCTRL_Pos);
	else
		setFieldData(mPeri->POWER, SDMMC_POWER_PWRCTRL_Msk, POWER_OFF, SDMMC_POWER_PWRCTRL_Pos);
}

unsigned int Sdmmc::getResponse1(void)
{
	return mPeri->RESP1;
}

unsigned int Sdmmc::getResponse2(void)
{
	return mPeri->RESP2;
}

unsigned int Sdmmc::getResponse3(void)
{
	return mPeri->RESP3;
}

unsigned int Sdmmc::getResponse4(void)
{
	return mPeri->RESP4;
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
					SDMMC_DCTRL_RWMOD_Msk | 
					SDMMC_DCTRL_RWSTART_Msk |
					SDMMC_DCTRL_DTDIR_Msk |
					SDMMC_DCTRL_DTEN_Msk;

//	setFieldData()
}

void Sdmmc::setDataBlockSize(unsigned char blockSize)
{
	if(blockSize <= 14)
	{
		mBlockSize = blockSize;
	}
}

}

#endif

