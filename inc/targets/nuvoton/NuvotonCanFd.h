/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_CAN__H_
#define YSS_DRV_NUVOTON_CAN__H_

#include <drv/CanFd.h>
#include <yss/error.h>

class NuvotonCanFd : public CanFd
{
public:
	typedef struct
	{
		uint8_t dbrp;			// 0 ~ 31
		uint8_t dtseg1;			// 0 ~ 31
		uint8_t dtseg2;			// 0 ~ 15
		uint8_t dsjw;			// 0 ~ 15
		uint16_t nbrp;			// 0 ~ 511
		uint8_t ntseg1;			// 1 ~ 255
		uint8_t ntseg2;			// 1 ~ 127
		uint8_t nsjw;			// 0 ~ 127
		bool fdOperaiton;		// CAN FD 모드 활성화
		bool enableSilent;		// Silent 모드 활성화
		bool enableLoopback;	// Loopback 모드 활성화
	}config_t;
	
	/*
		CANFD 장치를 초기화 합니다.
		. 
		@ return : 발생한 에러를 반환합니다.
		.
		@ config : 장치의 설정 값을 정의한 구조체입니다.
	*/
	error_t initialize(config_t config);
	
	virtual uint32_t getBaudrate(void);

	virtual float getSamplePoint(void);

	virtual uint32_t getDataBuadrate(void);

	virtual float getDataSamplePoint(void);

	virtual void sendStdCanMessage(uint16_t id, uint8_t *src, uint8_t dlc);

	virtual void sendXtdCanMessage(uint32_t id, uint8_t *src, uint8_t dlc);

	virtual void sendStdCanfdMessage(uint16_t id, uint8_t *src, dlc_t dlc, bool brs = true);

	virtual void sendXtdCanfdMessage(uint32_t id, uint8_t *src, dlc_t dlc, bool brs = true);

	virtual bool isNewRxMessage(void);

	virtual canMsg_t getNewRxCanMessage(void);

	virtual canfdMsg_t getNewRxCanfdMessage(void);

	// 아래 함수들은 시스템 함수로 사용자 호출을 금지합니다.
	struct setup_t
	{
		CANFD_T *dev;
	};
	
	// 수신 관련 인터럽트 서비스 루틴
	void isr0(void);
	
	// 에러 관련 인터럽트 서비스 루틴
	void isr1(void);

	NuvotonCanFd(const Drv::setup_t drvSetup, const setup_t setup);

private :
	typedef struct
	{
		uint8_t stdFilterCount;
		uint8_t extFilterCount;
		uint8_t rxFifoCount0;
		uint8_t rxFifoCount1;
		uint8_t rxBufferCount;
		uint8_t txEventFifo;
		uint8_t txFifoCount;
		uint8_t txBufferCount;
	}malloc_t;

	typedef struct
	{
		uint32_t id : 29;
		uint32_t rtr : 1;
		uint32_t xtd : 1;
		uint32_t esi : 1;
		uint32_t rxts : 16;
		uint32_t dlc : 4;
		uint32_t brs : 1;
		uint32_t fdf : 1;
		uint32_t rsv : 2;
		uint32_t fidx : 7;
		uint32_t anmf : 1;
		uint8_t data[64];
	}rxBuffer_t;
	
	typedef struct
	{
		uint32_t id : 29;
		uint32_t rtr : 1;
		uint32_t xtd : 1;
		uint32_t esi : 1;
		uint32_t rsv0 : 8;
		uint32_t mm0 : 8;
		uint32_t dlc : 4;
		uint32_t brs : 1;
		uint32_t fdf : 1;
		uint32_t rsv1 : 1;
		uint32_t efc : 1;
		uint32_t mm1 : 8;
		uint8_t data[64];
	}txBuffer_t;
	
	typedef struct
	{
		uint32_t sfid2 : 11;
		uint32_t rsv : 5;
		uint32_t sfid1 : 11;
		uint32_t sfec : 3;
		uint32_t sft : 2;
	}stdFilter_t;

	typedef struct
	{
		uint32_t sfid2 : 11;
		uint32_t rsv : 5;
		uint32_t sfid1 : 11;
		uint32_t sfec : 3;
		uint32_t sft : 2;
	}extFilter_t;

	CANFD_T *mDev;
//	malloc_t mMalloc;
	rxBuffer_t *mRxFifo0;
	rxBuffer_t *mRxBuffer;
	txBuffer_t *mTxFifo;
	stdFilter_t *mStdFilter;
	extFilter_t *mExtFilter;
//	canFrame_t *mCanFrame;
	uint32_t mHead, mTail, mRxBufferDepth;

};

#endif

