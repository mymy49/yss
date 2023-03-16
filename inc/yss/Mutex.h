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

#ifndef YSS_MUTEX__H_
#define YSS_MUTEX__H_

#include <stdint.h>
#include <drv/peripheral.h>

class Mutex
{
public:

	// 뮤텍스를 잠그고 다른 쓰레드의 진입을 막는다.
	//
	// 반환
	//		현재 lock key 값을 반환한다.
	uint32_t lock(void);

	// 뮤텍스를 잠글 수 있는지 확인한다. 만약 잠글 수 있다면 잠근다.
	//
	// 반환
	//		잠금 상태를 반환한다. 다른 쓰레드에 의해 잠겨지지 않았다면 잠그고 true를 반환한다. 다른 쓰레드에 의해 잠겨 있어, 잠글 수 없다면 false를 반환한다.
	bool check(void);
	
	// 현재 잠궈놓은 뮤텍스의 잠금을 해제한다. 만약 잠그지 않은 뮤텍스를 해제할 경우 의도치 않은 동작을 일으킨다. 
	void unlock(void);
	
	// 현재 뮤텍스가 lock()을 할 경우, 동시에 잠글 인터럽트의 IRQ를 등록한다.
	// unlock()을 호출 할 경우, IRQ도 동시에 잠금이 해제된다.
	//
	// IRQn_Type irq
	//		뮤텍스가 같이 잠글 IRQ의 번호를 설정한다.
	void setIrq(IRQn_Type irq);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	Mutex(void);

	void initializeMutex(void);

private:
	uint32_t mWaitNum, mCurrentNum;
	IRQn_Type mIrqNum;
	static bool mInit;
};

#endif