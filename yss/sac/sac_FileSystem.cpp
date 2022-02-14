////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 소스 코드 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
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
}

error FileSystem::checkMbr(void)
{
	unsigned char *buf;
	error result;
	
	mStorage->lock();
	result = mStorage->read(0, mSectorBuffer);
	mStorage->unlock();
	
	if(result != Error::NONE)
		return result;

	if(*(unsigned short*)&mSectorBuffer[0x1FE] != 0xAA55)
		return Error::SIGNATURE;

	for(int i=0;i<4;i++)
	{
		buf = &mSectorBuffer[0x1BE + 0x10 * i];
		if(buf[4])
		{
			mPartitionType = buf[4];
			mFirstSector = *(unsigned int*)&buf[8];
			mNumOfSector = *(unsigned int*)&buf[12];

			return Error::NONE;
		}
	}

	return Error::NO_BOOT_SECTOR;
}

unsigned int FileSystem::translateUtf16ToUtf8(void *utf16)
{
	unsigned int utf8;
	unsigned short *buf = (unsigned short*)utf16;

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

unsigned int FileSystem::countUtf8Char(void *utf8)
{
	char *src = (char*)utf8;
	unsigned int count = 0;

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

}

