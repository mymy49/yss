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

#define READ_ONLY	0x01
#define HIDDEN_FILE	0x02
#define SYSEM_FILE	0x04
#define DIRECTORY	0x10

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

Fat32::Fat32(sac::MassStorage &storage) : FileSystem(storage)
{
	mAbleFlag = false;
}

error Fat32::init(void)
{
	int result;
	
	result = checkMbr();
	if(result != Error::NONE)
		return result;

	if(mPartitionType == 0x0C || mPartitionType == 0x0B) // FAT32
	{
		mStorage->read(mFirstSector, mSectorBuffer);
		if(*(unsigned short*)&mSectorBuffer[0x1FE] != 0xAA55)
			return Error::SIGNATURE;

		mSectorPerCluster = mSectorBuffer[0x0D];
		mFatStartSector = *(unsigned short*)&mSectorBuffer[0x0E] + mFirstSector;
		mFsInfoSector = *(unsigned short*)&mSectorBuffer[0x30] + mFirstSector;
		mFatSize = *(unsigned int*)&mSectorBuffer[0x24];
		mRootCluster = *(unsigned int*)&mSectorBuffer[0x2C];
		mFatBackupStartSector = mFatStartSector + mFatSize;
		mDataStartSector = mFatBackupStartSector + mFatSize;

		mStorage->read(mFsInfoSector, mSectorBuffer);
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

	result = mStorage->read(mFatStartSector + sector, mFatTableBuffer);
	if(result != Error::NONE)
		return result;
	
	mNextCluster = mFatTableBuffer[index];
	mLastReadIndex = 0;
	mLastReadCluster = cluster;
	mBufferedFatSector = sector;

	if(mNextCluster < 0x0FFFFFF8)
		return Error::NO_DATA;

	return mStorage->read(mDataStartSector + (mLastReadCluster - 2) * mSectorPerCluster, des);
}

error Fat32::readNextBlock(void *des)
{
	error result;

	if(mLastReadIndex < 7)
	{
		mLastReadIndex++;
		return mStorage->read(mDataStartSector + (mLastReadCluster - 2) * mSectorPerCluster + mLastReadIndex, des);
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
			result = mStorage->read(mFatStartSector + sector, mFatTableBuffer);
			if(result != Error::NONE)
				return result;
		}

		mBufferedFatSector = sector;
		mLastReadCluster = mNextCluster;
		mLastReadIndex = 0;
		mNextCluster = mFatTableBuffer[index];

		return mStorage->read(mDataStartSector + (mLastReadCluster - 2) * mSectorPerCluster, des);
	}
}

unsigned int Fat32::getCurrentDirectoryCount(void)
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
		else if(entry->attr == DIRECTORY)
			count++;
	}

	if(readNextBlock(mSectorBuffer))
		goto check;
	
	return count;
}

unsigned int Fat32::getCurrentFileCount(void)
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
		else if(entry->attr == READ_ONLY || entry->attr == SYSEM_FILE || entry->attr == HIDDEN_FILE)
			count++;
	}

	if(readNextBlock(mSectorBuffer))
		goto check;
	
	return count;
}


