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

#define DELETED						0x00
#define READ_ONLY					0x01
#define HIDDEN_FILE					0x02
#define SYSEM_FILE					0x04
#define LONG_FILE_NAME				0x0F
#define DIRECTORY					0x10
#define SYSTEM_VOLUME_INFO			0x16
#define ARCHIVE						0x20

Fat32::Fat32(sac::MassStorage &storage) : FileSystem(storage)
{
	mAbleFlag = false;
	mFileOpen = false;
}

Fat32::~Fat32(void)
{
}

error Fat32::init(void)
{
	int result;
	unsigned int fatStartSector, fatBackupStartSector;

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
		fatStartSector = *(unsigned short*)&mSectorBuffer[0x0E] + mFirstSector;
		mFsInfoSector = *(unsigned short*)&mSectorBuffer[0x30] + mFirstSector;
		mFatSize = *(unsigned int*)&mSectorBuffer[0x24];
		mRootCluster = *(unsigned int*)&mSectorBuffer[0x2C];
		fatBackupStartSector = fatStartSector + mFatSize;

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
		
		mCluster.init(mStorage, fatStartSector, fatBackupStartSector, 512, mSectorPerCluster);
		mCluster.setCluster(mRootCluster);
		mDirectoryEntry.init(mCluster, mSectorBuffer);

		return Error::NONE;
	}
	else
		return Error::PARTITION_TYPE;
}

unsigned int Fat32::getCount(unsigned char *type, unsigned char typeCount)
{
	unsigned int count = 0;
	error result;

	if(mFileOpen)
		return 0;

	result = mDirectoryEntry.moveToHome();
	if(result != Error::NONE)
		return result;

	while(true)
	{
		for(int i=0;i<16;i++)
		{
			for(unsigned char i=0;i<typeCount;i++)
			{
				if(type[i] == mDirectoryEntry.getTargetAttribute())
				{
					count++;
					break;
				}
			}

			result = mDirectoryEntry.moveToNext();
			if(result != Error::NONE)
				return count;
		}
	}
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
	if(mFileOpen)
		return Error::BUSY;

	error result;
	unsigned int count = 0;

	result = mDirectoryEntry.moveToHome();
	if(result != Error::NONE)
		return result;

	// 지정한 인덱스 번째의 디렉토리 번호가 일치 할때까지 검사
	while(true)
	{
		for(unsigned char i=0;i<typeCount;i++)
		{
			if(mDirectoryEntry.getTargetAttribute() == type[i])
			{
				if(count == index)
					return mDirectoryEntry.getTargetName(des, size);

				count++;
				break;
			}
		}
		
		// 다음 엔트리를 읽고 탐색 재시작
		result = mDirectoryEntry.moveToNext();
		if(result != Error::NONE)
			return result;
	}
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
	if(mFileOpen)
		return Error::BUSY;

	unsigned int count = 0;
	error result;

	result = mDirectoryEntry.moveToHome();
	if(result != Error::NONE)
		return result;

	while(true)
	{
		if(mDirectoryEntry.getTargetAttribute() == DIRECTORY)
		{
			if(count == index)
			{
				count = mDirectoryEntry.getTargetCluster();
			
				if(count > 0)
					return mDirectoryEntry.setCluster(count);
				else
					return mDirectoryEntry.setCluster(mRootCluster);
			}

			count++;
		}
		
		result = mDirectoryEntry.moveToNext();
		if(result != Error::NONE)
			return result;
	}
}

error Fat32::returnDirectory(void)
{
	if(mFileOpen)
		return Error::BUSY;

	if(mCluster.getCluster() != mRootCluster)
		return enterDirectory(1);
	
	return Error::NONE;
}

error Fat32::makeDirectory(const char *name)
{
	
	return 0;
}
