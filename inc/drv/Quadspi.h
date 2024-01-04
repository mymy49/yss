////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
	struct Specification_t
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
	error initialize(void);

	// Quadspi 장치의 기본 사양을 설정한다. 
	// 설정 전에 반드시 enable(false) 를 호출하여 장치를 먼저 비활성화 시키는게 필요하다.
	// 세부 설정 사항은 구조체 Specification_t를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	error setSpecification(const Specification_t &spec);

	// Quadspi 장치의 전송 세부 사양을 설정한다.
	// 설정 전에 반드시 enable(false) 를 호출하여 장치를 먼저 비활성화 시키는게 필요하다.
	// 세부 설정 사항은 구조체 Specification_t를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	error setWaveform(const Waveform_t &waveform);

	error setBank(uint8_t bank);

	// Quadspi 장치를 활성화/비활성화 시킨다.
	// 정상적인 전송을 위해 enable(true)를 하기 전에 setSpecification()를 사용하여 타겟 장치에 맞는 
	// 올바른 전송 사양 설정이 먼저 이뤄져야 한다.
	//
	// bool en
	//		활성화(true)/비활성화(false)로 설정한다.
	void enable(bool en);

	error readRegister(uint8_t cmd, void *des, uint32_t size, uint32_t timeout);

	error writeCommand(uint8_t cmd);

	error wait(uint8_t cmd, uint32_t mask, uint32_t status, uint8_t size, uint8_t pollingMatchMode, uint32_t timeOut);

	error writeAddress(uint8_t cmd, uint32_t addr);

	error write(uint8_t cmd, uint32_t addr, void *src, uint32_t size, uint32_t timeout);

	error read(uint8_t cmd, uint32_t addr, void *des, uint32_t size, uint32_t timeout);

	//Quadspi(YSS_QUADSPI_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *stream, uint8_t channel, uint16_t priority);
	//void setWaveform(config::quadspi::Waveform &waveform);
	//bool writeRegister(uint8_t cmd, void *src, uint32_t size, uint32_t timeout);
	//void lock(void);
	//void unlock(void);

	struct Setup_t
	{
		YSS_QUADSPI_Peri *dev;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
		Dma &rxDma;
		Dma::DmaInfo rxDmaInfo;
	};

	Quadspi(const Drv::Setup_t drvSetup, const Setup_t setup);

private :
	YSS_QUADSPI_Peri *mDev;
	const Specification_t *mSpec;
	const Waveform_t *mWaveform;
#if defined(STM32F7)
	Dma *mTxDma, *mRxDma;
	Dma::DmaInfo mTxDmaInfo, mRxDmaInfo;
	uint32_t mCcr;
#endif
};

#endif

#endif

