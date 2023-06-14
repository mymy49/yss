////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/Fat32.h>
#include <yss/error.h>
#include <string.h>

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
	mCluster = new Fat32Cluster();
	mDirectoryEntry = new Fat32DirectoryEntry();
	mDirectoryEntry->initialize(*mCluster, getSectorBuffer());
}

Fat32::~Fat32(void)
{
	if(mCluster)
		delete mCluster;

	if(mDirectoryEntry)
		delete mDirectoryEntry;
}

error Fat32::initialize(void)
{
	error result;
	uint32_t fatStartSector, fatBackupStartSector;
	
	mStorage->lock();
	if(mStorage->isConnected() == false)
	{
		mStorage->unlock();
		return error::SDCARD_NOT_ABLE;
	}
	mStorage->unlock();

	result = checkMbr();
	if(result != error::ERROR_NONE)
		return result;

	if(mPartitionType == 0x0C || mPartitionType == 0x0B ||  mPartitionType == 0x6E) // FAT32
	{
		mStorage->lock();
		result = mStorage->read(mFirstSector, mSectorBuffer);
		mStorage->unlock();
		
		if(result != error::ERROR_NONE)
			return result;

		if(*(uint16_t*)&mSectorBuffer[0x1FE] != 0xAA55)
			return error::SIGNATURE;

		mSectorPerCluster = mSectorBuffer[0x0D];
		fatStartSector = *(uint16_t*)&mSectorBuffer[0x0E] + mFirstSector;
		mFsInfoSector = *(uint16_t*)&mSectorBuffer[0x30] + mFirstSector;
		mFatSize = *(uint32_t*)&mSectorBuffer[0x24];
		mRootCluster = *(uint32_t*)&mSectorBuffer[0x2C];
		fatBackupStartSector = fatStartSector + mFatSize;

		mStorage->lock();
		result = mStorage->read(mFsInfoSector, mSectorBuffer);
		mStorage->unlock();
		
		if(result != error::ERROR_NONE)
			return result;

		if(	*(uint16_t*)&mSectorBuffer[0x1FE] != 0xAA55 || 
			*(uint32_t*)&mSectorBuffer[0x0] != 0x41615252 || 
			*(uint32_t*)&mSectorBuffer[0x1E4] != 0x61417272
		)
			return error::SIGNATURE;

		mNumOfFreeClusters = *(uint32_t*)&mSectorBuffer[0x1E8];
		mNextFreeCluster = *(uint32_t*)&mSectorBuffer[0x1EC];
		
		mCluster->initialize(mStorage, fatStartSector, fatBackupStartSector, 512, mSectorPerCluster);
		mCluster->setRootCluster(mRootCluster);
		mDirectoryEntry->initialize(*mCluster, mSectorBuffer);

		return error::ERROR_NONE;
	}
	else
		return error::PARTITION_TYPE;
}

uint32_t Fat32::getCount(uint8_t *type, uint8_t typeCount)
{
	uint32_t count = 0;
	uint8_t attribute;

	error result;

	if(mFileOpen)
		return 0;

	result = mDirectoryEntry->moveToStart();
	if(result != error::ERROR_NONE)
		return result;

	while(true)
	{
		attribute = mDirectoryEntry->getTargetAttribute();
		for(uint8_t i=0;i<typeCount;i++)
		{
			if(type[i] == attribute)
			{
				count++;
				break;
			}
		}

		result = mDirectoryEntry->moveToNext();
		if(result != error::ERROR_NONE)
			return count;
	}
}

int32_t  Fat32::getDirectoryCount(void)
{
	const uint8_t type[1] = {DIRECTORY};

	return getCount((uint8_t*)type, 1);
}

int32_t  Fat32::getFileCount(void)
{
	const uint8_t type[4] = {READ_ONLY, HIDDEN_FILE, SYSEM_FILE, ARCHIVE};

	return getCount((uint8_t*)type, 4);
}

error Fat32::returnDirectory(void)
{
	error result;

	if(mFileOpen)
		return error::BUSY;

	if(mCluster->getCurrentCluster() != mRootCluster)
	{
		result = moveToStart();
		if(result != error::ERROR_NONE)
			return result;
		
		result = moveToNextDirectory();
		if(result != error::ERROR_NONE)
			return result;

		return enterDirectory();
	}
	
	return error::ERROR_NONE;
}



error Fat32::moveToNextItem(uint8_t *type, uint8_t typeCount)
{
	if(mFileOpen)
		return error::BUSY;

	error result;
	uint8_t attribute;

	while(true)
	{
		// 다음 엔트리를 읽고 탐색 재시작
		result = mDirectoryEntry->moveToNext();
		if(result != error::ERROR_NONE)
			return result;

		attribute = mDirectoryEntry->getTargetAttribute();

		for(uint8_t i=0;i<typeCount;i++)
		{
			if(attribute == type[i])
				return error::ERROR_NONE;
		}
	}
}

error Fat32::moveToCluster(uint32_t cluster)
{
	error result;

	if(mFileOpen)
		return error::BUSY;
	
	result = mDirectoryEntry->setCluster(cluster);
	if(result != error::ERROR_NONE)
		return result;

	return mDirectoryEntry->moveToStart();
}

error Fat32::moveToRootDirectory(void)
{
	if(mFileOpen)
		return error::BUSY;

	return mDirectoryEntry->moveToRoot();
}

error Fat32::moveToStart(void)
{
	if(mFileOpen)
		return error::BUSY;

	return mDirectoryEntry->moveToStart();
}

error Fat32::moveToNextDirectory(void)
{
	if(mFileOpen)
		return error::BUSY;

	const uint8_t type[1] = {DIRECTORY};

	return moveToNextItem((uint8_t*)type, 1);
}

error Fat32::moveToNextFile(void)
{
	if(mFileOpen)
		return error::BUSY;

	const uint8_t type[4] = {READ_ONLY, HIDDEN_FILE, SYSEM_FILE, ARCHIVE};

	return moveToNextItem((uint8_t*)type, 4);
}

error Fat32::enterDirectory(void)
{
	if(mFileOpen)
		return error::BUSY;

	uint32_t cluster;
	error result;

	if(mDirectoryEntry->getTargetAttribute() == DIRECTORY)
	{
		cluster = mDirectoryEntry->getTargetCluster();
		if(cluster > 1)
			return mDirectoryEntry->setCluster(cluster);
		else
			return mDirectoryEntry->moveToRoot();
	}

	return error::NOT_DIRECTORY;
}

error Fat32::getName(void* des, uint32_t size)
{
	if(mFileOpen)
		return error::BUSY;

	return mDirectoryEntry->getTargetName(des, size);
}

error Fat32::makeDirectory(const char *name)
{
	if(mFileOpen)
		return error::BUSY;

	error result;

	// 동일한 이름이 있는지 확인 시작
	result = mDirectoryEntry->moveToStart();
	if(result != error::ERROR_NONE)
		return result;
	
	while(true)
	{
		if(!mDirectoryEntry->comapreTargetName(name))
			return error::SAME_FILE_NAME_EXIST;

		result = mDirectoryEntry->moveToNext();
		if(result == error::INDEX_OVER)
		{
			break;
		}
		else if(result == error::NO_DATA)
		{
			result = mDirectoryEntry->append();
			if(result != error::ERROR_NONE)
				return result;
			break;
		}
		else if(result != error::ERROR_NONE)
			return result;
	}

	return mDirectoryEntry->makeDirectory(name);
}

bool Fat32::isDirectory(void)
{
	return mDirectoryEntry->getTargetAttribute() == DIRECTORY;
}

bool Fat32::isFile(void)
{
	uint8_t attribute = mDirectoryEntry->getTargetAttribute();

	return (attribute == READ_ONLY) || (attribute == HIDDEN_FILE) || (attribute == SYSEM_FILE) || (attribute == ARCHIVE);
}

bool Fat32::isHaveNextCluster(void)
{
	if(mCluster)
		return true;
	else
		return false;
}

error Fat32::open(void)
{
	error result;

	if(mFileOpen)
		return error::BUSY;
	
	mCluster->backup();
	mFileCluster = mDirectoryEntry->getTargetCluster();
	result = mCluster->setCluster(mFileCluster);

	if(result == error::ERROR_NONE)
		mFileOpen = true;
	
	return result;
}

error Fat32::open(const char *name)
{
	if(mFileOpen)
		return error::BUSY;

	error result;

	// 동일한 이름이 있는지 확인 시작
	result = mDirectoryEntry->moveToStart();
	if(result != error::ERROR_NONE)
		return result;
	
	while(true)
	{
		if(!mDirectoryEntry->comapreTargetName(name))
		{
			mCluster->backup();
			result = mCluster->setCluster(mDirectoryEntry->getTargetCluster());

			if(result == error::ERROR_NONE)
				mFileOpen = true;

			return result;
		}

		result = mDirectoryEntry->moveToNext();
		if(result == error::INDEX_OVER)
			return error::NO_FILE;
		else if(result != error::ERROR_NONE)
			return result;
	}
}

error Fat32::moveToFileStart(void)
{
	return mCluster->setCluster(mFileCluster);
}

bool Fat32::compareName(const char *utf8)
{
	return mDirectoryEntry->comapreTargetName(utf8);
}

error Fat32::read(void *des)
{
	error result;

	result = mCluster->readDataSector(des);
	if(result == error::ERROR_NONE)
		result = mCluster->increaseDataSectorIndex();
	
	return result;
}

error Fat32::write(void *src)
{
	error result;

	result = mCluster->writeDataSector(src);
	if(result == error::ERROR_NONE)
		result = mCluster->increaseDataSectorIndex();
	
	return result;
}

uint32_t Fat32::getFileSize(void)
{
	return mDirectoryEntry->getTargetFileSize();
}

error Fat32::moveToNextSector(void)
{
	return mCluster->increaseDataSectorIndex();
}

error Fat32::makeFile(const char *name)
{
	if(mFileOpen)
		return error::BUSY;

	error result;

	result = mDirectoryEntry->moveToEnd();
	if(result != error::ERROR_NONE)
		return result;

	return mDirectoryEntry->makeFile(name);
}

error Fat32::close(uint32_t fileSize)
{
	mCluster->restore();
	mCluster->readDataSector(mSectorBuffer);
	mFileOpen = false;
	mDirectoryEntry->setTargetFileSize(fileSize);
	return mDirectoryEntry->saveEntry();
}

// 현재 열린 파일을 닫는다.
// 반환 : 현재 발생한 에러를 반환한다.
error Fat32::close(void)
{
	mFileOpen = false;
	mCluster->restore();
	return error::ERROR_NONE;
}

// 현재 설정된 디렉토리의 시작 클러스터를 얻는 함수이다.
// 반환 : 현재 클러스터의 번지를 반환함.
uint32_t Fat32::getCurrentDirectoryCluster(void)
{
	return mCluster->getStartCluster();
}


