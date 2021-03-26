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

#if defined(STM32F7)

#include <drv/sdmmc/drv_st_sdmmc_type_A.h>

#define SD_IDLE 0
#define SD_READY 1
#define SD_IDENT 2
#define SD_STBY 3
#define SD_TRANS 4
#define SD_DATA 5
#define SD_RCA 6
#define SD_PRG 7
#define SD_DIS 8

namespace drv
{
void thread_taskSdmmc(void);

Sdmmc::Sdmmc(SDMMC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *stream, unsigned char channel, unsigned short priority) : Drv(clockFunc, nvicFunc)
{
    this->set(channel, (void *)&(QUADSPI->DR), priority);
    mStream = stream;
    mThreadId = 0;
    mAbleFlag = false;
    mVcc = 0;
    mRca = 0;
}

bool Sdmmc::init(config::sdmmc::Config config)
{
    mDetectSet.port = config.detect.port;
    mDetectSet.pin = config.detect.pin;
    mVcc = config.vcc;
    mThreadId = trigger::add(thread_taskSdmmc, 512);
//    exti.add(*mDetectSet.port, mDetectSet.pin, define::exti::mode::FALLING | define::exti::mode::RISING, mThreadId);

    setSdmmcClkDiv(118);

    return true;
}

#define SHORT_RESP 1
#define LONG_RESP 3
#define setWaitResp(des, x) des |= x << 6
#define setCpsmEn(des) des |= 1 << 10
#define setWaitInt(des) des |= 1 << 8
bool Sdmmc::sendCmd(unsigned char cmd, unsigned long arg)
{
    unsigned long reg = cmd, status;
    resetSdmmcIcr();
    setSdmmcArgument(arg);

    switch (cmd)
    {
    case 0:
        break;
    case 1:
    case 3:
    case 7:
    case 8:
    case 13:
    case 41:
    case 55:
        setWaitResp(reg, SHORT_RESP);
        break;
    case 2:
        setWaitResp(reg, LONG_RESP);
        break;
    default:
        return false;
    }

    setCpsmEn(reg);
    setSdmmcCmd(reg);

    while (true)
    {
        status = getSdmmcStatus();
        if ((status & (SDMMC_STA_CMDSENT_Msk | SDMMC_STA_CMDREND_Msk | SDMMC_STA_CCRCFAIL_Msk)) != 0)
            break;
        else if ((status & (SDMMC_STA_CTIMEOUT_Msk)) != 0)
            goto error;
        thread::switchContext();
    }

    switch (cmd)
    {
    case 0:
    case 2:
    case 41:
        if (getSdmmcRespCmd() != 0x3f)
            goto error;
        break;
    default:
        if (getSdmmcRespCmd() != cmd)
            goto error;
    }

    resetSdmmcCmd();
    return true;
error:
    resetSdmmcCmd();
    return false;
}

bool Sdmmc::sendAcmd(unsigned char cmd, unsigned long arg)
{
    // CMD55
    if (sendCmd(55, 0) == false) // 2.7V ~ 3.6V 동작 설정
        goto error;
    if (getSdmmcResp1() != 0x00000120)
        goto error;

    if (sendCmd(cmd, arg) == false) // 2.7V ~ 3.6V 동작 설정
    {
        if (sendCmd(1, 0x00000000) == false) // 2.7V ~ 3.6V 동작 설정
            goto error;
    }
    return true;
error:
    return false;
}

unsigned char Sdmmc::getStatus(void)
{
    // CMD7
    if (sendCmd(7, mRca) == false)
        return SD_IDLE;
    else
        return (unsigned char)(getSdmmcResp1());
}

bool Sdmmc::isDetected(void)
{
    return !mDetectSet.port->getData(mDetectSet.pin);
}

bool Sdmmc::isAble(void)
{
    return mAbleFlag;
}

void Sdmmc::setAble(bool able)
{
    mAbleFlag = able;
}

#define POWER_OFF 1
#define POWER_ON 3

#define POWER_2_7__2_8 (1 << 15)
#define POWER_2_8__2_9 (1 << 16)
#define POWER_2_9__3_0 (1 << 17)
#define POWER_3_0__3_1 (1 << 18)
#define POWER_3_1__3_2 (1 << 19)
#define POWER_3_2__3_3 (1 << 20)
#define POWER_3_3__3_4 (1 << 21)
#define POWER_3_4__3_5 (1 << 22)
#define POWER_3_5__3_6 (1 << 23)

inline unsigned long getOcr(float vcc)
{
    unsigned long ocr = 0;

    if ((float)2.7 <= vcc && (float)2.8 <= vcc)
        ocr = POWER_2_7__2_8;
    else if ((float)2.8 <= vcc && (float)2.9 <= vcc)
        ocr = POWER_2_8__2_9;
    else if ((float)2.9 <= vcc && (float)3.0 <= vcc)
        ocr = POWER_2_9__3_0;
    else if ((float)3.0 <= vcc && (float)3.1 <= vcc)
        ocr = POWER_3_0__3_1;
    else if ((float)3.1 <= vcc && (float)3.2 <= vcc)
        ocr = POWER_3_1__3_2;
    else if ((float)3.2 <= vcc && (float)3.3 <= vcc)
        ocr = POWER_3_2__3_3;
    else if ((float)3.3 <= vcc && (float)3.4 <= vcc)
        ocr = POWER_3_3__3_4;
    else if ((float)3.4 <= vcc && (float)3.5 <= vcc)
        ocr = POWER_3_4__3_5;
    else if ((float)3.5 <= vcc && (float)3.6 <= vcc)
        ocr = POWER_3_5__3_6;

    return ocr;
}

bool Sdmmc::connect(void)
{
    unsigned long ocr;
    mMutex.lock();
    setSdmmcPowerControl(POWER_ON);
    setSdmmcBypass(false);
    setSdmmcClkEn(true);
    setSdmmcDtimer(0xffff);

    if (ocr == 0)
        goto error;

    // CMD0 (SD메모리 리셋)
    if (sendCmd(0, 0) == false)
        goto error;

    // CMD8 (SD메모리가 SD ver 2.0을 지원하는지 확인)
    if (sendCmd(8, 0x000001aa) == false) // 2.7V ~ 3.6V 동작 설정
        goto error;
    if (getSdmmcResp1() != 0x000001aa)
        goto error;

    // ACMD41
    // 지원하는 전원을 확인
    if (sendAcmd(41, 0) == false)
        goto error;

    // SD메모리에 공급되는 전원에 대한 비트를 얻어옴
    ocr = getOcr(mVcc);
    // HCS 설정
    ocr |= 0x40000000;

    // 현재 공급되는 전원과 카드가 지원하는 전원을 비교
    if ((getSdmmcResp1() & ocr) == 0)
        goto error;

    // 카드에서 HCS를 지원하는지 확인
    if (getSdmmcResp1() & 0x40000000)
    {
        ocr |= 0x40000000;
        mHcsFlag = true;
    }
    else
        mHcsFlag = false;

    // 카드의 초기화 시작과 카드의 초기화가 끝나기 기다림
    do
    {
        if (sendAcmd(41, ocr | 0x40000000) == false)
            goto error;
    } while ((getSdmmcResp1() & 0x80000000) == 0);

    // CMD2 (CID를 얻어옴)
    if (sendCmd(2, 0) == false)
        goto error;

    // CMD3 (새로운 RCA 주소와 SD메모리의 상태를 얻어옴)
    if (sendCmd(3, 0) == false)
        goto error;

    mRca = getSdmmcResp1() & 0xffff0000;
    setSdmmcBypass(true);

    mMutex.unlock();
    return true;
error:
    mRca = 0;
    mMutex.unlock();
    return false;
}

void thread_taskSdmmc(void)
{
    //static bool detectFlag = false;
    //thread::delay(500);

    //if (sdmmc.isDetected() == true && sdmmc.isAble() == false)
    //{
    //    sdmmc.setAble(true);
    //    debug_printf("turn on\n");

    //    sdmmc.connect();

    //    debug_printf("status = %d\n", sdmmc.getStatus());
    //}
    //else if (sdmmc.isDetected() == false && sdmmc.isAble() == true)
    //{
    //    sdmmc.setAble(false);
    //    setSdmmcPowerControl(POWER_OFF);
    //    debug_printf("turn off\n");
    //}
}
}

#endif