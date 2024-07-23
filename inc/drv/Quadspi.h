/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_QUADSPI__H_
#define YSS_DRV_QUADSPI__H_

#include "peripheral.h"

#if defined(STM32F7)

typedef QUADSPI_TypeDef		YSS_QUADSPI_Peri;

#else

#define YSS_DRV_QUADSPI_UNSUPPORTED

#endif

#ifndef YSS_DRV_QUADSPI_UNSUPPORTED

#include "Drv.h"
#include <drv/Dma.h>

class Quadspi : public Drv
{
public :
	struct specification_t
	{
		uint32_t maxFrequncy;
		uint32_t flashSize;
		uint8_t chipSelectHighTime;
		uint8_t clockMode;
		bool sampleShift;
	};

	struct Waveform_t
	{
		uint8_t dataMode;
		uint8_t alternateByteMode;
		uint8_t alternateByteSize;
		uint8_t addressMode;
		uint8_t addressSize;
		uint8_t instructionMode;
		uint8_t dummyCycle;
		bool statusSendInstructionOnlyOnce;
	};

	// Quadspi 장치를 초기화 한다. 초기화만 했을 뿐, 아직 실제 사용 가능한 상태는 아니다.
	// setSpecification() 함수를 사용해 사용할 플래시 메모리의 사양을 설정하고 사용 가능하다.
	// 
	// 반환
	//		에러를 반환한다.
	error_t initialize(void);

	// Quadspi 장치의 기본 사양을 설정한다. 
	// 설정 전에 반드시 enable(false) 를 호출하여 장치를 먼저 비활성화 시키는게 필요하다.
	// 세부 설정 사항은 구조체 specification_t를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	error_t setSpecification(const specification_t &spec);

	// Quadspi 장치의 전송 세부 사양을 설정한다.
	// 설정 전에 반드시 enable(false) 를 호출하여 장치를 먼저 비활성화 시키는게 필요하다.
	// 세부 설정 사항은 구조체 specification_t를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	error_t setWaveform(const Waveform_t &waveform);

	error_t setBank(uint8_t bank);

	// Quadspi 장치를 활성화/비활성화 시킨다.
	// 정상적인 전송을 위해 enable(true)를 하기 전에 setSpecification()를 사용하여 타겟 장치에 맞는 
	// 올바른 전송 사양 설정이 먼저 이뤄져야 한다.
	//
	// bool en
	//		활성화(true)/비활성화(false)로 설정한다.
	void enable(bool en);

	error_t readRegister(uint8_t cmd, void *des, uint32_t size, uint32_t timeout);

	error_t writeCommand(uint8_t cmd);

	error_t wait(uint8_t cmd, uint32_t mask, uint32_t status, uint8_t size, uint8_t pollingMatchMode, uint32_t timeOut);

	error_t writeAddress(uint8_t cmd, uint32_t addr);

	error_t write(uint8_t cmd, uint32_t addr, void *src, uint32_t size, uint32_t timeout);

	error_t read(uint8_t cmd, uint32_t addr, void *des, uint32_t size, uint32_t timeout);

	//Quadspi(YSS_QUADSPI_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *stream, uint8_t channel, uint16_t priority);
	//void setWaveform(config::quadspi::Waveform &waveform);
	//bool writeRegister(uint8_t cmd, void *src, uint32_t size, uint32_t timeout);
	//void lock(void);
	//void unlock(void);

	struct setup_t
	{
		YSS_QUADSPI_Peri *dev;
		Dma &txDma;
		Dma::dmaInfo_t txDmaInfo;
		Dma &rxDma;
		Dma::dmaInfo_t rxDmaInfo;
	};

	Quadspi(const Drv::setup_t drvSetup, const setup_t setup);

private :
	YSS_QUADSPI_Peri *mDev;
	const specification_t *mSpec;
	const Waveform_t *mWaveform;
#if defined(STM32F7)
	Dma *mTxDma, *mRxDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	uint32_t mCcr;
#endif
};

#endif

#endif

