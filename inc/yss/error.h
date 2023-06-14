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

#ifndef YSS_ERROR__H_
#define YSS_ERROR__H_

#include <stdint.h>

// 에러에 대해 간단한 그룹을 형성 했지만, 필요하다면 다른 그룹의 에러도 사용한다.
typedef enum
{
	ERROR_NONE = 0,

// 범용
	BUSY,
	OVERSIZE,
	MALLOC_FAILED,
	OVERFLOW,
	BUFFER_SIZE,
	INDEX_OVER,
	NOT_READY,
	TX_UNDERRUN,
	RX_OVERRUN,
	DMA,
	TIMEOUT,
	UNSUPPORTED_MODE,
	WRONG_CONFIG,
	WRONG_INDEX,
	NOT_INITIALIZED,
	OUT_OF_RANGE,
	UNKNOWN,
	NOT_CONNECTED,
	FAILED_THREAD_ADDING,
	WRONG_SIZE,
	WRONG_CLOCK_FREQUENCY,
	IT_ALREADY_HAVE,
	NOT_HAVE_SPECIFICATON,
	NACK,
	FAIL,
	CHECK_SUM,

// FAT 관련
	SECTOR_READ,
	SIGNATURE,
	PARTITION_TYPE,
	NO_BOOT_SECTOR,
	NO_DATA,
	NO_FREE_DATA,
	NO_FILE,
	NOT_EXIST_NAME,
	WRONG_FORMAT,
	WRONG_FILE_NAME,
	WRONG_DIRECTORY_PATH,
	FILE_NOT_OPENED,

// SD메모리 관련
	BAD_SECTOR,
	NOT_DIRECTORY,
	SAME_FILE_NAME_EXIST,
	NO_RESPONSE_CMD,
	CMD_TIMEOUT,
	DATA_TIMEOUT,
	CMD_CRC_FAIL,
	DATA_CRC_FAIL,
	SDCARD_NOT_ABLE,

// STM32 관련
	SYSCLK_SRC_IS_PLL,
	HSE_NOT_READY,

// CAN 통신 관련
	SLEEP_ACK_INTERRUP,
	WAKEUP_INTERRUPT,
	ERROR_INTERRUP,
}error;

#endif