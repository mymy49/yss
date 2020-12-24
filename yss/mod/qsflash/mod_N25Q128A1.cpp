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

#include <__cross_studio_io.h>
#include <yss/thread.h>
#include <drv/peripherals.h>
#include <mod/qsflash/N25Q128A1.h>

#if !defined(YSS_DRV_QUADSPI_NOT_SUPPORT)

#define WRITE_STATUS			0x01
#define READ_STATUS				0x05
#define READ_FLAG				0x70
#define CLEAR_FLAG				0x50
#define WRITE_ENABLE			0x06
#define WRITE_DISABLE			0x04
#define READ_ENHANCED			0x65
#define WRITE_ENHANCED			0x61
#define READ_MULTI_IO_ID		0xaf
#define READ_ID					0x9e
#define READ_VOLATILE			0x85
#define WRITE_VOLATILE			0x81
#define READ_NONVOLATILE		0xb5
#define WRITE_NONVOLATILE		0xb1
#define RESET					0x66
#define READ_QUAD_OUTPUT_FAST	0x6b
#define READ					0x03
#define WRITE_QUAD_INPUT_FAST	0x32
#define WRITE					0x02
#define ERASE_SUBSECTOR			0x20

#define MANUFACTURER_ID			0x20
#define MEMORY_TYPE				0xba

#define MEMORY_SIZE_16MB		0x18

#define BLOCK_SIZE				4096
#define NUM_OF_BLOCK			4095

#define TIMEOUT					300

namespace mod
{
namespace qsflash
{
	static config::quadspi::Config gConfig
	{
		54000000,							//	unsigned long maxFrequncy;
		define::quadspi::flashSize::MB16,	//	unsigned char flashSize;
		0,									//	unsigned char chipSelectHighTime;
		false,								//	bool sampleShift;
		define::quadspi::clockMode::MODE0	//	bool clockMode;
	};

	static config::quadspi::Waveform gSetupWaveform
	{
		define::quadspi::mode::SINGLE,	//  unsigned char dataMode;
		define::quadspi::mode::NO,		//	unsigned char alternateByteMode;
		define::quadspi::size::BIT8,	//	unsigned char alternateByteSize;
		define::quadspi::mode::SINGLE,	//	unsigned char addressMode;
		define::quadspi::size::BIT24,	//	unsigned char addressSize;
		define::quadspi::mode::SINGLE,	//	unsigned char instructionMode;
		0,								//	unsigned char dummyCycle;
		true							//	bool statusSendInstructionOnlyOnce;
	};

	static config::quadspi::Waveform gDataWaveform
	{
		define::quadspi::mode::QUAD,	//  unsigned char dataMode;
		define::quadspi::mode::NO,		//	unsigned char alternateByteMode;
		define::quadspi::size::BIT8,	//	unsigned char alternateByteSize;
		define::quadspi::mode::SINGLE,	//	unsigned char addressMode;
		define::quadspi::size::BIT24,	//	unsigned char addressSize;
		define::quadspi::mode::SINGLE,	//	unsigned char instructionMode;
		8,								//	unsigned char dummyCycle;
		true							//	bool statusSendInstructionOnlyOnce;
	};

	config::quadspi::Config* N25q128a1::getConfig(void)
	{
		return &gConfig;
	}

	unsigned long N25q128a1::getBlockSize(void)
	{
		return BLOCK_SIZE;
	}

	unsigned long N25q128a1::getNumOfBlock(void)
	{
		return NUM_OF_BLOCK;
	}

	N25q128a1::N25q128a1(drv::Quadspi &peri)
	{
		mPeri = &peri;
	}

	bool N25q128a1::init(void)
	{
		unsigned char buf[3];

		mPeri->lock();
		mPeri->setWaveform(gSetupWaveform);

		if(!mPeri->readRegister(READ_ID, buf, 3, 300))
			goto error;

		if(buf[0] != MANUFACTURER_ID && buf[1] != MEMORY_TYPE)
			goto error;

		mPeri->unlock();
		return true;
error:
		mPeri->unlock();
		return false;
	}

	bool N25q128a1::writeBlock(unsigned long block, void *src)
	{
		bool rt;
		unsigned char *cSrc = (unsigned char*)src;

		mPeri->lock();
		mPeri->setWaveform(gDataWaveform);
		if(!mPeri->writeCommand(WRITE_ENABLE))
			goto writeFalse;

		mPeri->setWaveform(gSetupWaveform);
		if(!mPeri->wait(READ_STATUS, 0x02, 0x02, 1, define::quadspi::pmm::OR, 1000))
			goto writeFalse;

		mPeri->setWaveform(gDataWaveform);
		if(!mPeri->writeAddress(ERASE_SUBSECTOR, BLOCK_SIZE*block))
			goto writeFalse;

		for(unsigned char i=0;i<16;i++)
		{
			mPeri->setWaveform(gSetupWaveform);
			if(!mPeri->wait(READ_FLAG, 0x80, 0x80, 1, define::quadspi::pmm::OR, 1000))
				goto writeFalse;

			mPeri->setWaveform(gDataWaveform);
			if(!mPeri->writeCommand(WRITE_ENABLE))
				goto writeFalse;

			mPeri->setWaveform(gSetupWaveform);
			if(!mPeri->wait(READ_STATUS, 0x02, 0x02, 1, define::quadspi::pmm::OR, 1000))
				goto writeFalse;

			mPeri->setWaveform(gDataWaveform);
			if(!mPeri->write(WRITE_QUAD_INPUT_FAST, 4096 * block + 256 * i, cSrc, 256, TIMEOUT))
				goto writeFalse;

			cSrc = &cSrc[256];
	//		thread::delay(100);
		}

		mPeri->unlock();
		return true;
writeFalse:
		mPeri->unlock();
		return false;
	}

	bool N25q128a1::readBlock(unsigned long block, void *des)
	{
		bool rt;

		mPeri->lock();
		mPeri->setWaveform(gDataWaveform);
		rt = mPeri->read(READ_QUAD_OUTPUT_FAST, BLOCK_SIZE*block, des, BLOCK_SIZE, TIMEOUT);
		mPeri->unlock();

		return rt;
	}
}
}

#endif