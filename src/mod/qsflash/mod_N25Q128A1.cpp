/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

static const Quadspi::specification_t gSpec = 
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

error_t N25Q128A1::initialize(void)
{
	error_t result;

	if(mDev == 0)
		return error_t::WRONG_CONFIG;

	uint8_t buf[3];

	mDev->lock();
	mDev->enable(false);
	mDev->setSpecification(gSpec);
	mDev->setBank(mBank);
	mDev->enable(true);
	mDev->setWaveform(gSetupWaveform);
	
	result = mDev->readRegister(READ_ID, buf, 3, 300);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	if (buf[0] != MANUFACTURER_ID && buf[1] != MEMORY_TYPE)
		result = error_t::UNKNOWN_DEVICE;
	
	mDev->unlock();
	return result;
error_handler :
	mDev->unlock();
	return result;
}

void N25Q128A1::setConfig(const config_t &config)
{
	mDev = &config.dev;
	mBank = config.bank;
}

//error_t N25Q128A1::writeBlock(uint32_t block, void *src)
//{
//}

//error_t N25Q128A1::readBlock(uint32_t block, void *des)
//{
//}

error_t N25Q128A1::write(uint32_t block, void *src)
{
	error_t result;
	uint8_t *cSrc = (uint8_t *)src;

	mDev->lock();
	mDev->setWaveform(gDataWaveform);
	result = mDev->writeCommand(WRITE_ENABLE);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	mDev->setWaveform(gSetupWaveform);
	result = mDev->wait(READ_STATUS, 0x02, 0x02, 1, define::quadspi::pmm::OR, 1000);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	mDev->setWaveform(gDataWaveform);
	result = mDev->writeAddress(ERASE_SUBSECTOR, BLOCK_SIZE * block);

	for (uint8_t i = 0; i < 16; i++)
	{
		mDev->setWaveform(gSetupWaveform);
		result = mDev->wait(READ_FLAG, 0x80, 0x80, 1, define::quadspi::pmm::OR, 1000);
		if(result != error_t::ERROR_NONE)
			goto error_handler;

		mDev->setWaveform(gDataWaveform);
		result = mDev->writeCommand(WRITE_ENABLE);
		if(result != error_t::ERROR_NONE)
			goto error_handler;

		mDev->setWaveform(gSetupWaveform);
		result = mDev->wait(READ_STATUS, 0x02, 0x02, 1, define::quadspi::pmm::OR, 1000);
		if(result != error_t::ERROR_NONE)
			goto error_handler;

		mDev->setWaveform(gDataWaveform);
		result = mDev->write(WRITE_QUAD_INPUT_FAST, 4096 * block + 256 * i, cSrc, 256, TIMEOUT);
		if(result != error_t::ERROR_NONE)
			goto error_handler;

		cSrc = &cSrc[256];
		//thread::delay(100);
	}

	mDev->unlock();
	return error_t::ERROR_NONE;

error_handler :
	mDev->unlock();
	return result;
}

error_t N25Q128A1::read(uint32_t block, void *des)
{
	error_t result;

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



