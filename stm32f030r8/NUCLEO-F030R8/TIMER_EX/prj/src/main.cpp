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
//  주담당자 : 아이구 (mymy49@nate.com) 2019.12.22 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <string.h>
#include <util/ElapsedTime.h>
#include <util/time.h>
#include <yss/yss.h>

int gCnt = 0;

void isr_timer0(void)
{
    gCnt++;
}

int main(void)
{
    // 이순신 os 초기화
    yss::init();

    // Timer0 update 인터럽트 초기화
    timer1.setClockEn(true);         // Timer1에 클럭 공급 활성화
    timer1.init(1000);               // 1kH로 초기화
    timer1.setUpdateIntEn(true);     // update 인터럽트 활성화
    timer1.setUpdateIsr(isr_timer0); // update 콜백 함수 등록
    timer1.setIntEn(true);           // Timer1 글로벌 인터럽트 활성화
    timer1.start();                  // Timer1 Up카운트 시작

    while (1)
    {
        debug_printf("%d\r", gCnt);
    }
    return 0;
}