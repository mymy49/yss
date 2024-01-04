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

#include <mod/qsflash/N25Q128A1.h>

#if !defined(YSS_DRV_QUADSPI_UNSUPPORTED)

#include <yss/thread.h>

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

using namespace define::quadspi;

static const Quadspi::Specification_t gSpec = 
{
	54000000,			//uint32_t maxFrequncy;
	flashSize::MB16,	//uint32_t flashSize;
	0,					//uint8_t chipSelectHighTime;
	clockMode::MODE0,	//uint8_t clockMode;
	false				//bool sampleShift;
};

static const Quadspi::Waveform_t gSetupWaveform = 
{
	mode::SINGLE,	//uint8_t dataMode;
	mode::NO,		//uint8_t alternateByteMode;
	size::BIT8,		//uint8_t alternateByteSize;
	mode::SINGLE,	//uint8_t addressMode;
	size::BIT24,	//uint8_t addressSize;
	mode::SINGLE,	//uint8_t instructionMode;
	0,				//uint8_t dummyCycle;
	true			//bool statusSendInstructionOnlyOnce;
};

static const Quadspi::Waveform_t gDataWaveform = 
{
	mode::QUAD,		//uint8_t dataMode;
	mode::NO,		//uint8_t alternateByteMode;
	size::BIT8,		//uint8_t alternateByteSize;
	mode::SINGLE,	//uint8_t addressMode;
	size::BIT24,	//uint8_t addressSize;
	mode::SINGLE,	//uint8_t instructionMode;
	8,				//uint8_t dummyCycle;
	true			//bool statusSendInstructionOnlyOnce;
};

N25Q128A1::N25Q128A1(void)
{
	mDev = 0;
	mBank = define::quadspi::bank::BANK1;
}

uint32_t N25Q128A1::getBlockSize(void)
{
	return BLOCK_SIZE;
}

uint32_t N25Q128A1::getNumOfBlock(void)
{
	return NUM_OF_BLOCK;
}

error N25Q128A1::initialize(void)
{
	error result;

	if(mDev == 0)
		return error::WRONG_CONFIG;

	uint8_t buf[3];

	mDev->lock();
	mDev->enable(false);
	mDev->setSpecification(gSpec);
	mDev->setBank(mBank);
	mDev->enable(true);
	mDev->setWaveform(gSetupWaveform);
	
	result = mDev->readRegister(READ_ID, buf, 3, 300);
	if(result != error::ERROR_NONE)
		goto error_handler;

	if (buf[0] != MANUFACTURER_ID && buf[1] != MEMORY_TYPE)
		result = error::UNKNOWN_DEVICE;
	
	mDev->unlock();
	return result;
error_handler :
	mDev->unlock();
	return result;
}

void N25Q128A1::setConfig(const Config_t &config)
{
	mDev = &config.dev;
	mBank = config.bank;
}

//error N25Q128A1::writeBlock(uint32_t block, void *src)
//{
//}

//error N25Q128A1::readBlock(uint32_t block, void *des)
//{
//}

error N25Q128A1::write(uint32_t block, void *src)
{
	error result;
	uint8_t *cSrc = (uint8_t *)src;

	mDev->lock();
	mDev->setWaveform(gDataWaveform);
	result = mDev->writeCommand(WRITE_ENABLE);
	if(result != error::ERROR_NONE)
		goto error_handler;

	mDev->setWaveform(gSetupWaveform);
	result = mDev->wait(READ_STATUS, 0x02, 0x02, 1, define::quadspi::pmm::OR, 1000);
	if(result != error::ERROR_NONE)
		goto error_handler;

	mDev->setWaveform(gDataWaveform);
	result = mDev->writeAddress(ERASE_SUBSECTOR, BLOCK_SIZE * block);

	for (uint8_t i = 0; i < 16; i++)
	{
		mDev->setWaveform(gSetupWaveform);
		result = mDev->wait(READ_FLAG, 0x80, 0x80, 1, define::quadspi::pmm::OR, 1000);
		if(result != error::ERROR_NONE)
			goto error_handler;

		mDev->setWaveform(gDataWaveform);
		result = mDev->writeCommand(WRITE_ENABLE);
		if(result != error::ERROR_NONE)
			goto error_handler;

		mDev->setWaveform(gSetupWaveform);
		result = mDev->wait(READ_STATUS, 0x02, 0x02, 1, define::quadspi::pmm::OR, 1000);
		if(result != error::ERROR_NONE)
			goto error_handler;

		mDev->setWaveform(gDataWaveform);
		result = mDev->write(WRITE_QUAD_INPUT_FAST, 4096 * block + 256 * i, cSrc, 256, TIMEOUT);
		if(result != error::ERROR_NONE)
			goto error_handler;

		cSrc = &cSrc[256];
		//thread::delay(100);
	}

	mDev->unlock();
	return error::ERROR_NONE;

error_handler :
	mDev->unlock();
	return result;
}

error N25Q128A1::read(uint32_t block, void *des)
{
	error result;

	mDev->lock();
	mDev->setWaveform(gDataWaveform);
	result = mDev->read(READ_QUAD_OUTPUT_FAST, BLOCK_SIZE * block, des, BLOCK_SIZE, TIMEOUT);
	mDev->unlock();

	return result;
}

bool N25Q128A1::isConnected(void)
{
	return true;
}

#endif



