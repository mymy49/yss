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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_UART_ST_TYPE_A__H_
#define YSS_DRV_UART_ST_TYPE_A__H_

#include <config.h>
#include <yss/mcu.h>
#include "drv_st_uart_type_A_define.h"
#include <sac/Comm.h>

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

#include <config.h>
#include <drv/peripherals.h>
#include <yss/mcu.h>

namespace drv
{
class Uart : public sac::Comm, public Drv
{
    USART_TypeDef *mPeri;
    unsigned int (*mGetClockFreq)(void);
    unsigned char *mRcvBuf;
    unsigned int mRcvBufSize;
    unsigned int mTail, mHead;
    Stream *mTxStream;

  public:
    Uart(USART_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *txStream, unsigned char txChannel, unsigned short priority, unsigned int (*getClockFreq)(void));
    bool init(unsigned int baud, unsigned int receiveBufferSize);
    bool send(void *src, unsigned int size, unsigned int timeout = 3000);
    bool send(const void *src, unsigned int size, unsigned int timeout = 3000);
    void push(char data);
    void isr(void);
    char getWaitUntilReceive(void);
    signed short get(void);
    void flush(void);
    bool send(char *src, unsigned int size);
};
}

#if defined(USART1) && defined(UART1_ENABLE)
extern drv::Uart uart1;
#endif

#if defined(USART2) && defined(UART2_ENABLE)
extern drv::Uart uart2;
#endif

#if defined(USART3) && defined(UART3_ENABLE)
extern drv::Uart uart3;
#endif

#if defined(UART4) && defined(UART4_ENABLE)
extern drv::Uart uart4;
#endif

#if defined(UART5) && defined(UART5_ENABLE)
extern drv::Uart uart5;
#endif

#if defined(UsART6) && defined(UART6_ENABLE)
extern drv::Uart uart6;
#endif

#if defined(UART7) && defined(UART7_ENABLE)
extern drv::Uart uart7;
#endif

#if defined(UART8) && defined(UART8_ENABLE)
extern drv::Uart uart8;
#endif

#endif

#endif