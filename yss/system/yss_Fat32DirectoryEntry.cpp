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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2022. yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2022.01.15 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/Fat32DirectoryEntry.h>
#include <yss/error.h>
#include <string.h>
#include <__cross_studio_io.h>

#define DELETED						0x00
#define READ_ONLY					0x01
#define HIDDEN_FILE					0x02
#define SYSEM_FILE					0x04
#define LONG_FILE_NAME				0x0F
#define DIRECTORY					0x10
#define SYSTEM_VOLUME_INFO			0x16
#define ARCHIVE						0x20

Fat32DirectoryEntry::Fat32DirectoryEntry(void)
{
	mIndex = 0xFFFF;
	mCluster = 0;
	mSectorSize = 0;
	mEntryBuffer = 0;
}

void Fat32DirectoryEntry::init(Fat32Cluster &cluster, void* sectorBuffer)
{
	mCluster = &cluster;
	mEntryBuffer = (DirectoryEntry*)sectorBuffer;
	mSectorSize = cluster.getSectorSize();

	moveToHome();
}

error Fat32DirectoryEntry::extractEntry(void)
{
}

error Fat32DirectoryEntry::moveToHome(void)
{
	error result;

	result = mCluster->moveToHome();
	if(result != Error::NONE)
		return result;
	
	mCluster->readDataSector(mEntryBuffer);
	if(result != Error::NONE)
		return result;

	mIndex = 0xFFFF;
	moveToNext();
	
	return Error::NONE;
}

error Fat32DirectoryEntry::moveToNext(void)
{
	error result;
	DirectoryEntry *entry;
	LongFileName *lfn;
	unsigned char num;
	
	mLfnCount = 0;

	while(true)
	{
		if(mIndex < 16)
			mIndex++;
		else
		{
			result = mCluster->readDataSector(mEntryBuffer);
			if(result != Error::NONE)
				return result;

			mIndex = 0;
		}

		entry = &mEntryBuffer[mIndex];

		if(entry->attr == LONG_FILE_NAME)
		{
			lfn = (LongFileName*)entry;
			if(lfn->order & 0x40)
			{
				mLfnCount = lfn->order & 0x3F;
			}
			
			if(mLfnCount)
			{
				num = lfn->order & 0x3F;
				memcpy(&mLfn[num-1], lfn, sizeof(LongFileName));
			}
		}
		else if(entry->name[0] == 0xE5)
		{
			// 삭제된 파일이라 다시 탐색 시작
			mLfnCount = 0;
		}
		else if(entry->name[0] == 0x00)
		{
			return Error::INDEX_OVER;
		}
		else
		{
			return Error::NONE;
		}
	}
}

error Fat32DirectoryEntry::setCluster(unsigned int cluster)
{
	mCluster->setCluster(cluster);
	return moveToHome();
}

unsigned int Fat32DirectoryEntry::getCluster(void)
{
	return mCluster->getCluster();
}

unsigned char Fat32DirectoryEntry::getTargetAttribute(void)
{
	return mEntryBuffer[mIndex].attr;
}

unsigned int Fat32DirectoryEntry::translateUtf16ToUtf8(void *utf16)
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

error Fat32DirectoryEntry::getTargetName(void *des, unsigned int size)
{
	char *cdes = (char*)des, *csrc;
	unsigned short used;
	unsigned int utf8;

	// 긴 파일 이름인지 점검
	if(mLfnCount == 0)
		goto extractShortName;
	
	// 파일 이름 추출
	used = 0;
	for(int j=0;j<mLfnCount;j++)
	{
		csrc = mLfn[j].name1;
		for(int i=0;i<5;i++)
		{
			utf8 = translateUtf16ToUtf8(csrc);
			csrc += 2;

			if(used >= size)
				goto extractShortName;

			if(utf8 == 0)
			{
				*cdes = 0;
				return Error::NONE;
			}
			else if(utf8 < 0x80) // 아스키 코드
			{
				used++;
				*cdes++ = utf8;
			}
			else // 유니코드
			{
				used += 3;
				*cdes++ = utf8 >> 16;
				*cdes++ = utf8 >> 8;
				*cdes++ = utf8;
			}
		}

		csrc = mLfn[j].name2;
		for(int i=0;i<6;i++)
		{
			utf8 = translateUtf16ToUtf8(csrc);
			csrc += 2;

			if(utf8 == 0)
			{
				if(used >= size)
					goto extractShortName;

				*cdes = 0;
				return Error::NONE;
			}
			else if(utf8 < 0x80) // 아스키 코드
			{
				if(used >= size)
					goto extractShortName;

				used++;
				*cdes++ = utf8;
			}
			else // 유니코드
			{
				used += 3;
				*cdes++ = utf8 >> 16;
				*cdes++ = utf8 >> 8;
				*cdes++ = utf8;
			}
		}

		csrc = mLfn[j].name3;
		for(int i=0;i<2;i++)
		{
			utf8 = translateUtf16ToUtf8(csrc);
			csrc += 2;

			if(utf8 == 0)
			{
				if(used >= size)
					goto extractShortName;
				
				*cdes = 0;
				return Error::NONE;
			}
			else if(utf8 < 0x80) // 아스키 코드
			{
				if(used >= size)
					goto extractShortName;
	
				used++;
				*cdes++ = utf8;
				
				if(j+1 == mLfnCount && i == 1)
				{
					*cdes = 0;
					return Error::NONE;
				}
			}
			else // 유니코드
			{
				used += 3;
				*cdes++ = utf8 >> 16;
				*cdes++ = utf8 >> 8;
				*cdes++ = utf8;
			}
		}
	}

extractShortName :
	csrc = mEntryBuffer[mIndex].name;
	cdes = (char*)des;

	for(int i=0;i<8 && *csrc;i++)
		*cdes++ = *csrc++;

	*cdes = 0;
	
	return Error::NONE;
}

unsigned int Fat32DirectoryEntry::getTargetCluster(void)
{
	return mEntryBuffer[mIndex].startingClusterHigh << 16 | mEntryBuffer[mIndex].startingClusterLow;
}

