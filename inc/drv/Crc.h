/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CRC__H_
#define YSS_DRV_CRC__H_

#include "Drv.h"
#include <yss/error.h>

class Crc : public Drv
{
public :
	typedef enum
	{
		CRC_MODE_CCITT,
		CRC_MODE_CRC8,
		CRC_MODE_CRC16,
		CRC_MODE_CRC32
	}mode_t;

	typedef enum
	{
		CRC_DAT_LEN_8BIT = 0,
		CRC_DAT_LEN_16BIT,
		CRC_DAT_LEN_32BIT
	}datalen_t;

	typedef struct
	{
		mode_t mode;					// 동작 모드의 종류를 설정합니다.
		datalen_t datalen;				// 코어가 한번에 쓰는 비트의 폭을 설정합니다.
		uint32_t seed;					// 체크섬 리셋의 초기값을 설정합니다.
		bool writeBitOrderReverse;		// 쓰여지는 데이터의 비트 배열을 반전시킵니다.
		bool checksumBitOrderReverse;	// 체크섬의 비트 배열을 반전시킵니다.
	}config_t;

	/*	
		CRC 장치의 동작 구성을 설정합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ config : CRC의 동작 구성을 설정합니다.
	*/
	virtual error_t configure(config_t config) = 0;

	/*	
		CRC 체크섬을 계산합니다.
		.
		@ return : 계산된 CRC 체크섬 값을 반환합니다.
		.
		@ src : CRC 체크섬을 계산할 소스를 설정합니다.
		@ size : CRC 체크섬을 계산할 소스의 용량을 설정합니다.
	*/
	virtual uint32_t calculate(void *src, uint32_t size) = 0;

	/*	
		CRC 체크섬 값을 초기화 합니다.
	*/
	virtual void resetChecksum(void) = 0;

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	Crc(const Drv::setup_t drvSetup);

protected :
};

#endif

