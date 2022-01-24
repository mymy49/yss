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

#include <yss/Fat32.h>
#include <yss/error.h>
#include <string.h>
#include <__cross_studio_io.h>

#define READ_ONLY					0x01
#define HIDDEN_FILE					0x02
#define SYSEM_FILE					0x04
#define LONG_FILE_NAME				0x0F
#define DIRECTORY					0x10
#define SYSTEM_VOLUME_INFO			0x16
#define ARCHIVE						0x20

struct DirectoryEntry
{
	char name[8];
	char extention[3];
	char attr;
	char reserved[2];
	unsigned short createdTime;
	unsigned short createdDate;
	unsigned short lastAccessedDate;
	unsigned short startingClusterHigh;
	unsigned short lastModifiedTime;
	unsigned short lastModifiedDate;
	unsigned short startingClusterLow;
	unsigned int fileSize;
};

Fat32::Fat32(sac::MassStorage &storage, unsigned int maxLfnLength) : FileSystem(storage)
{
	mAbleFlag = false;
	mMaxLfnLength = maxLfnLength;
	mLongFileName = new LongFileName[maxLfnLength];
}

Fat32::~Fat32(void)
{
	delete mLongFileName;
}

error Fat32::init(void)
{
	int result;
	
	result = checkMbr();
	if(result != Error::NONE)
		return result;

	if(mPartitionType == 0x0C || mPartitionType == 0x0B) // FAT32
	{
		mStorage->lock();
		result = mStorage->read(mFirstSector, mSectorBuffer);
		mStorage->unlock();
		
		if(result != Error::NONE)
			return result;

		if(*(unsigned short*)&mSectorBuffer[0x1FE] != 0xAA55)
			return Error::SIGNATURE;

		mSectorPerCluster = mSectorBuffer[0x0D];
		mFatStartSector = *(unsigned short*)&mSectorBuffer[0x0E] + mFirstSector;
		mFsInfoSector = *(unsigned short*)&mSectorBuffer[0x30] + mFirstSector;
		mFatSize = *(unsigned int*)&mSectorBuffer[0x24];
		mRootCluster = *(unsigned int*)&mSectorBuffer[0x2C];
		mFatBackupStartSector = mFatStartSector + mFatSize;
		mDataStartSector = mFatBackupStartSector + mFatSize;

		mStorage->lock();
		result = mStorage->read(mFsInfoSector, mSectorBuffer);
		mStorage->unlock();
		
		if(result != Error::NONE)
			return result;

		if(	*(unsigned short*)&mSectorBuffer[0x1FE] != 0xAA55 || 
			*(unsigned int*)&mSectorBuffer[0x0] != 0x41615252 || 
			*(unsigned int*)&mSectorBuffer[0x1E4] != 0x61417272
		)
			return Error::SIGNATURE;

		mNumOfFreeClusters = *(unsigned int*)&mSectorBuffer[0x1E8];
		mNextFreeCluster = *(unsigned int*)&mSectorBuffer[0x1EC];
		mLastReadIndex = 0xFF;
		mLastReadCluster = mNextCluster = mBufferedFatSector = 0xFFFFFFFF;
		mCurrentDirectoryCluster = mRootCluster;

		return Error::NONE;
	}
	else
		return Error::PARTITION_TYPE;
}

error Fat32::initReadCluster(unsigned int cluster, void *des)
{
	unsigned int sector = cluster / 128;
	unsigned int index = cluster % 128;
	error result;
	
	mStorage->lock();
	result = mStorage->read(mFatStartSector + sector, mFatTableBuffer);
	mStorage->unlock();

	if(result != Error::NONE)
		return result;
	
	mNextCluster = mFatTableBuffer[index];
	mLastReadIndex = 0;
	mLastReadCluster = cluster;
	mBufferedFatSector = sector;

	if(mNextCluster < 0x0FFFFFF8)
		return Error::NO_DATA;
	
	mStorage->lock();
	result = mStorage->read(mDataStartSector + (mLastReadCluster - 2) * mSectorPerCluster, des);
	mStorage->unlock();

	return result;
}

error Fat32::readNextBlock(void *des)
{
	error result;

	if(mLastReadIndex < 7)
	{
		mLastReadIndex++;
		mStorage->lock();
		result = mStorage->read(mDataStartSector + (mLastReadCluster - 2) * mSectorPerCluster + mLastReadIndex, des);
		mStorage->unlock();

		return result;
	}
	else
	{
		if(mNextCluster <= 1 || 0x0FFFFFF0 <= mNextCluster)
			return Error::NO_DATA;

		unsigned int sector = mNextCluster / 128;
		unsigned int index = mNextCluster % 128;
		
		if(mBufferedFatSector == sector)
			mNextCluster = mFatTableBuffer[index];
		else
		{
			mStorage->lock();
			result = mStorage->read(mFatStartSector + sector, mFatTableBuffer);
			mStorage->unlock();

			if(result != Error::NONE)
				return result;
		}

		mBufferedFatSector = sector;
		mLastReadCluster = mNextCluster;
		mLastReadIndex = 0;
		mNextCluster = mFatTableBuffer[index];
		
		mStorage->lock();
		result = mStorage->read(mDataStartSector + (mLastReadCluster - 2) * mSectorPerCluster, des);
		mStorage->unlock();

		return result;
	}
}

unsigned int Fat32::getCount(unsigned char *type, unsigned char typeCount)
{
	DirectoryEntry *entry;
	unsigned int count = 0;

	initReadCluster(mCurrentDirectoryCluster, mSectorBuffer);

check:
	for(int i=0;i<16;i++)
	{
		entry = (DirectoryEntry*)&mSectorBuffer[0x20 * i];
		if(entry->name[0] == 0)
			return count;
		
		for(unsigned char i=0;i<typeCount;i++)
		{
			if(type[i] == entry->attr)
			{
				count++;
				break;
			}
		}
	}

	if(readNextBlock(mSectorBuffer) == Error::NONE)
		goto check;
	
	return count;
}

unsigned int Fat32::getDirectoryCount(void)
{
	const unsigned char type[1] = {DIRECTORY};

	return getCount((unsigned char*)type, 1);
}

unsigned int Fat32::getFileCount(void)
{
	const unsigned char type[4] = {READ_ONLY, HIDDEN_FILE, SYSEM_FILE, ARCHIVE};

	return getCount((unsigned char*)type, 4);
}

error Fat32::getName(unsigned char *type, unsigned char typeCount, unsigned int index, void* des, unsigned int size)
{
	DirectoryEntry *entry;
	LongFileName *lfn;
	unsigned int count = 0, i, utf8, used, order, num;
	char *cdes = (char*)des, *csrc;
	bool longNameFlag = false, firstFlag = false;

	initReadCluster(mCurrentDirectoryCluster, mSectorBuffer);

	// 지정한 인덱스 번째의 디렉토리 번호가 일치 할때까지 검사
	do
	{
		for(i=0;i<16;i++)
		{
			entry = (DirectoryEntry*)&mSectorBuffer[0x20 * i];
			lfn = (LongFileName*)entry;

			if(entry->name[0] == 0)
			{
				return Error::INDEX_OVER;
			}
			else if(lfn->attr == LONG_FILE_NAME)
			{
				if(lfn->order & 0x40)
				{
					order = lfn->order & 0x3F;
					longNameFlag = true;
				}
				
				if(longNameFlag)
				{
					num = lfn->order & 0x3F;
					if(num < mMaxLfnLength)
						memcpy(&mLongFileName[num-1], lfn, sizeof(LongFileName));
					else
						longNameFlag = false;
				}
			}

			for(unsigned char i=0;i<typeCount;i++)
			{
				if(entry->attr == type[i])
				{
					if(count == index)
						goto extractName;
					count++;
				}
			}

			if(lfn->attr != LONG_FILE_NAME)
				longNameFlag = false;
		}
		// 다음 섹터를 읽고 탐색 재시작
	}while(readNextBlock(mSectorBuffer) == Error::NONE);
	
	return Error::INDEX_OVER;

extractName:
	// 긴 파일 이름인지 점검
	if(longNameFlag == false)
		goto extractShortName;
	
	// 파일 이름 추출
	used = 0;
	for(int j=0;j<order;j++)
	{
		csrc = mLongFileName[j].name1;
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

		csrc = mLongFileName[j].name2;
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

		csrc = mLongFileName[j].name3;
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
				
				if(j+1 == order && i == 1)
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
	csrc = entry->name;
	cdes = (char*)des;

	for(int i=0;i<8 && *csrc;i++)
		*cdes++ = *csrc++;

	*cdes = 0;

	return Error::NONE;
}

error Fat32::getDirectoryName(unsigned int index, void* des, unsigned int size)
{
	const unsigned char type[1] = {DIRECTORY};

	return getName((unsigned char*)type, 1, index, des, size);
}

error Fat32::getFileName(unsigned int index, void* des, unsigned int size)
{
	const unsigned char type[4] = {READ_ONLY, HIDDEN_FILE, SYSEM_FILE, ARCHIVE};

	return getName((unsigned char*)type, 4, index, des, size);
}

error Fat32::enterDirectory(unsigned int index)
{
	DirectoryEntry *entry;
	unsigned int count = 0;

	initReadCluster(mCurrentDirectoryCluster, mSectorBuffer);

check:
	for(int i=0;i<16;i++)
	{
		entry = (DirectoryEntry*)&mSectorBuffer[0x20 * i];
		if(entry->name[0] == 0)
			return count;
		
		if(entry->attr == DIRECTORY)
		{
			if(count == index)
			{
				count = entry->startingClusterHigh << 16 | entry->startingClusterLow;
				
				if(count > 0)
					mCurrentDirectoryCluster = count;
				else
					mCurrentDirectoryCluster = mRootCluster;

				return Error::NONE;
			}

			count++;
		}
	}

	if(readNextBlock(mSectorBuffer) == Error::NONE)
		goto check;

	return Error::INDEX_OVER;
}

error Fat32::returnDirectory(void)
{
	if(mCurrentDirectoryCluster != mRootCluster)
		return enterDirectory(1);
	
	return Error::NONE;
}