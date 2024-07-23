/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <sac/FileSystem.h>
#include <yss/error.h>

FileSystem::FileSystem(MassStorage &storage)
{
	mFirstSector = 0;
	mNumOfSector = 0;
	mPartitionType = 0;
	mStorage = &storage;
	mSectorBuffer = new uint8_t[512];
}

FileSystem::~FileSystem(void)
{
	delete mSectorBuffer;
}

error_t FileSystem::checkMbr(void)
{
	uint8_t *buf;
	error_t result;
	
	mStorage->lock();
	result = mStorage->read(0, mSectorBuffer);
	mStorage->unlock();
	
	if(result != error_t::ERROR_NONE)
		return result;

	if(*(uint16_t*)&mSectorBuffer[0x1FE] != 0xAA55)
		return error_t::SIGNATURE;

	for(int32_t  i=0;i<4;i++)
	{
		buf = &mSectorBuffer[0x1BE + 0x10 * i];
		if(buf[4])
		{
			mPartitionType = buf[4];
			mFirstSector = *(uint32_t*)&buf[8];
			mNumOfSector = *(uint32_t*)&buf[12];

			return error_t::ERROR_NONE;
		}
	}

	return error_t::NO_BOOT_SECTOR;
}

int32_t  FileSystem::translateUtf16ToUtf8(void *utf16)
{
	uint32_t utf8;
	uint16_t *buf = (uint16_t*)utf16;

	if(*buf <= 0x7F)
	{
		utf8 = *buf;
	}
	else
	{
		utf8 = 0xe08080 | ((*buf << 4) & 0x0F0000);
		utf8 |= ((*buf << 2) & 0x003F00) | (*buf & 0x00003F);
	}

	return utf8;
}

int32_t  FileSystem::countUtf8Char(void *utf8)
{
	uint8_t *src = (uint8_t*)utf8;
	uint32_t count = 0;

	while(*src)
	{
		if(*src <= 0x7F)
		{
			src++;
			count++;
		}
		else
		{
			src += 3;
			count++;
		}
	}

	return count;
}

void* FileSystem::getSectorBuffer(void)
{
	return mSectorBuffer;
}

