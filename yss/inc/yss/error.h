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

#ifndef YSS_ERROR__H_
#define YSS_ERROR__H_

typedef int error;

namespace Error
{
	enum
	{
		NONE = 0,
		SECTOR_READ = 1,
		SIGNATURE = 2,
		PARTITION_TYPE = 3,
		NO_BOOT_SECTOR = 4,
		NO_DATA = 5,
		INDEX_OVER = 6,
		BUFFER_SIZE = 7,
		MALLOC_FAILED = 8,
		WRONG_FORMAT = 9,
		OVERFLOW = 10,
		NO_FREE_DATA = 11,
		BUSY = 12,
		OVERSIZE = 13,
		BAD_SECTOR = 14,
		NOT_DIRECTORY = 15,
		SAME_FILE_NAME_EXIST = 16,
		NEW_FAILED = 17,
		NO_RESPONSE_CMD = 18,
		CMD_TIMEOUT = 19,
		DATA_TIMEOUT = 20,
		CMD_CRC_FAIL = 21,
		DATA_CRC_FAIL = 22,
		NOT_READY = 23,
		TX_UNDERRUN = 24,
		RX_OVERRUN = 25,
		DMA = 26,
		TIMEOUT = 27,
		NO_FILE = 28,
		NOT_EXIST_NAME = 29,
		WRONG_FILE_NAME = 30,
		WRONG_DIRECTORY_PATH = 31,
		UNSUPPORTED_MODE = 32,
		FILE_NOT_OPENED = 33,
		SDCARD_NOT_ABLE = 34,
		WRONG_CONFIG = 35,
	};
}

#endif