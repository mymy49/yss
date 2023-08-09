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

#include <sac/FileSystem.h>
#include <yss/error.h>

namespace sac
{
FileSystem::FileSystem(sac::MassStorage &storage)
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

error FileSystem::checkMbr(void)
{
	uint8_t *buf;
	error result;
	
	mStorage->lock();
	result = mStorage->read(0, mSectorBuffer);
	mStorage->unlock();
	
	if(result != error::ERROR_NONE)
		return result;

	if(*(uint16_t*)&mSectorBuffer[0x1FE] != 0xAA55)
		return error::SIGNATURE;

	for(int32_t  i=0;i<4;i++)
	{
		buf = &mSectorBuffer[0x1BE + 0x10 * i];
		if(buf[4])
		{
			mPartitionType = buf[4];
			mFirstSector = *(uint32_t*)&buf[8];
			mNumOfSector = *(uint32_t*)&buf[12];

			return error::ERROR_NONE;
		}
	}

	return error::NO_BOOT_SECTOR;
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
	int8_t *src = (int8_t*)utf8;
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
}

