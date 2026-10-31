/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_HAL_ETHERNET__H_
#define	YSS_HAL_ETHERNET__H_

#include <yss/Mutex.h>
#include <yss/error.h>

class Ethernet
{
public :
	struct config_t
	{
	    uint8_t macAddress[6];      // 보드 고유 MAC 주소
		uint16_t rxDescriptorCount;
		uint16_t txDescriptorCount;

	    // 1. PHY 관련
	    //bool autoNegotiation;       // 자동 협상 사용 여부
	    //// 2. MAC / 패킷 관련
	    //bool enableChecksumOffload; // 하드웨어 체크섬 오프로드 사용 여부
	    //// 3. 메모리 / DMA 관련
	    //void *rxDescriptorTable;    // Rx 디스크립터 메모리 주소 (정렬 필수)
	    //void *txDescriptorTable;    // Tx 디스크립터 메모리 주소 (정렬 필수)
	    //uint16_t rxDescriptorCount; // Rx 디스크립터 개수
	    //uint16_t txDescriptorCount; // Tx 디스크립터 개수
	};

	Ethernet();

	virtual error_t initialize(config_t config) = 0;

	error_t setPhysicalLayerAddress(uint8_t pa);

protected :
	struct DmaDesc
	{
	    volatile uint32_t status;      // DES0: 상태 및 제어 플래그 (OWN, Frame Length 등)
	    volatile uint32_t control;     // DES1: 버퍼 크기 및 Ring 제어 (RBS1, RER/TER, TCH 등)
	    volatile uint32_t buffer1Addr; // DES2: 실제 패킷 데이터가 담길 메모리 버퍼 주소
	    volatile uint32_t buffer2Addr; // DES3: 두 번째 버퍼 주소 또는 Next Desc 주소 (Chain 모드 시)
	} __attribute__((aligned(8)));     // 8바이트 또는 캐시라인 정렬 필수
	
	DmaDesc *mTxDesc;
	DmaDesc *mRxDesc;
	uint8_t *mMallocBuffer;
	uint16_t mRxDescCount;
	uint16_t mTxDescCount;
	uint8_t mPhysicalLayerAddr;

	static const uint16_t mMaxBufferSize = 1536;

	virtual void updateConfig() = 0;

	error_t malloc();
};

#endif

