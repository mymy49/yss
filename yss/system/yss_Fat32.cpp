////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
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

#include <yss/Fat32.h>
#include <yss/error.h>
#include <string.h>
//#include <__cross_studio_io.h>

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
	mDirectoryEntry->init(*mCluster, getSectorBuffer());
}

Fat32::~Fat32(void)
{
	if(mCluster)
		delete mCluster;

	if(mDirectoryEntry)
		delete mDirectoryEntry;
}

error Fat32::init(void)
{
	int result;
	unsigned int fatStartSector, fatBackupStartSector;
	
	mStorage->lock();
	if(mStorage->isConnected() == false)
	{
		mStorage->unlock();
		return Error::SDCARD_NOT_ABLE;
	}
	mStorage->unlock();

	result = checkMbr();
	if(result != Error::NONE)
		return result;

	if(mPartitionType == 0x0C || mPartitionType == 0x0B ||  mPartitionType == 0x6E) // FAT32
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
		
		mCluster->init(mStorage, fatStartSector, fatBackupStartSector, 512, mSectorPerCluster);
		mCluster->setRootCluster(mRootCluster);
		mDirectoryEntry->init(*mCluster, mSectorBuffer);

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

	result = mDirectoryEntry->moveToStart();
	if(result != Error::NONE)
		return result;

	while(true)
	{
		for(unsigned char i=0;i<typeCount;i++)
		{
			if(type[i] == mDirectoryEntry->getTargetAttribute())
			{
				count++;
				break;
			}
		}

		result = mDirectoryEntry->moveToNext();
		if(result != Error::NONE)
			return count;
	}
}

int Fat32::getDirectoryCount(void)
{
	const unsigned char type[1] = {DIRECTORY};

	return getCount((unsigned char*)type, 1);
}

int Fat32::getFileCount(void)
{
	const unsigned char type[4] = {READ_ONLY, HIDDEN_FILE, SYSEM_FILE, ARCHIVE};

	return getCount((unsigned char*)type, 4);
}

error Fat32::returnDirectory(void)
{
	error result;

	if(mFileOpen)
		return Error::BUSY;

	if(mCluster->getCurrentCluster() != mRootCluster)
	{
		result = moveToStart();
		if(result != Error::NONE)
			return result;
		
		result = moveToNextDirectory();
		if(result != Error::NONE)
			return result;

		return enterDirectory();
	}
	
	return Error::NONE;
}



error Fat32::moveToNextItem(unsigned char *type, unsigned char typeCount)
{
	if(mFileOpen)
		return Error::BUSY;

	error result;
	unsigned char attribute;

	while(true)
	{
		// 다음 엔트리를 읽고 탐색 재시작
		result = mDirectoryEntry->moveToNext();
		if(result != Error::NONE)
			return result;

		attribute = mDirectoryEntry->getTargetAttribute();

		for(unsigned char i=0;i<typeCount;i++)
		{
			if(attribute == type[i])
				return Error::NONE;
		}
	}
}

error Fat32::moveToCluster(unsigned int cluster)
{
	error result;

	if(mFileOpen)
		return Error::BUSY;
	
	result = mDirectoryEntry->setCluster(cluster);
	if(result != Error::NONE)
		return result;

	return mDirectoryEntry->moveToStart();
}

error Fat32::moveToRootDirectory(void)
{
	if(mFileOpen)
		return Error::BUSY;

	return mDirectoryEntry->moveToRoot();
}

error Fat32::moveToStart(void)
{
	if(mFileOpen)
		return Error::BUSY;

	return mDirectoryEntry->moveToStart();
}

error Fat32::moveToNextDirectory(void)
{
	if(mFileOpen)
		return Error::BUSY;

	const unsigned char type[1] = {DIRECTORY};

	return moveToNextItem((unsigned char*)type, 1);
}

error Fat32::moveToNextFile(void)
{
	if(mFileOpen)
		return Error::BUSY;

	const unsigned char type[4] = {READ_ONLY, HIDDEN_FILE, SYSEM_FILE, ARCHIVE};

	return moveToNextItem((unsigned char*)type, 4);
}

error Fat32::enterDirectory(void)
{
	if(mFileOpen)
		return Error::BUSY;

	unsigned int cluster;
	error result;

	if(mDirectoryEntry->getTargetAttribute() == DIRECTORY)
	{
		cluster = mDirectoryEntry->getTargetCluster();
		if(cluster > 1)
			return mDirectoryEntry->setCluster(cluster);
		else
			return mDirectoryEntry->moveToRoot();
	}

	return Error::NOT_DIRECTORY;
}

error Fat32::getName(void* des, unsigned int size)
{
	if(mFileOpen)
		return Error::BUSY;

	return mDirectoryEntry->getTargetName(des, size);
}

error Fat32::makeDirectory(const char *name)
{
	if(mFileOpen)
		return Error::BUSY;

	error result;

	// 동일한 이름이 있는지 확인 시작
	result = mDirectoryEntry->moveToStart();
	if(result != Error::NONE)
		return result;
	
	while(true)
	{
		if(!mDirectoryEntry->comapreTargetName(name))
			return Error::SAME_FILE_NAME_EXIST;

		result = mDirectoryEntry->moveToNext();
		if(result == Error::INDEX_OVER)
		{
			break;
		}
		else if(result == Error::NO_DATA)
		{
			result = mDirectoryEntry->append();
			if(result != Error::NONE)
				return result;
			break;
		}
		else if(result != Error::NONE)
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
	unsigned char attribute = mDirectoryEntry->getTargetAttribute();

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
		return Error::BUSY;
	
	mCluster->backup();
	result = mCluster->setCluster(mDirectoryEntry->getTargetCluster());

	if(result == Error::NONE)
		mFileOpen = true;
	
	return result;
}

error Fat32::open(const char *name)
{
	if(mFileOpen)
		return Error::BUSY;

	error result;

	// 동일한 이름이 있는지 확인 시작
	result = mDirectoryEntry->moveToStart();
	if(result != Error::NONE)
		return result;
	
	while(true)
	{
		if(!mDirectoryEntry->comapreTargetName(name))
		{
			mCluster->backup();
			result = mCluster->setCluster(mDirectoryEntry->getTargetCluster());

			if(result == Error::NONE)
				mFileOpen = true;

			return result;
		}

		result = mDirectoryEntry->moveToNext();
		if(result == Error::INDEX_OVER)
			return Error::NO_FILE;
		else if(result != Error::NONE)
			return result;
	}
}

bool Fat32::compareName(const char *utf8)
{
	return mDirectoryEntry->comapreTargetName(utf8);
}

error Fat32::read(void *des)
{
	error result;

	result = mCluster->readDataSector(des);
	if(result == Error::NONE)
		result = mCluster->increaseDataSectorIndex();
	
	return result;
}

error Fat32::write(void *src)
{
	error result;

	result = mCluster->writeDataSector(src);
	if(result == Error::NONE)
		result = mCluster->increaseDataSectorIndex();
	
	return result;
}

unsigned int Fat32::getFileSize(void)
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
		return Error::BUSY;

	error result;

	result = mDirectoryEntry->moveToEnd();
	if(result != Error::NONE)
		return result;

	return mDirectoryEntry->makeFile(name);
}

error Fat32::close(unsigned int fileSize)
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
	return Error::NONE;
}

// 현재 설정된 디렉토리의 시작 클러스터를 얻는 함수이다.
// 반환 : 현재 클러스터의 번지를 반환함.
unsigned int Fat32::getCurrentDirectoryCluster(void)
{
	return mCluster->getStartCluster();
}


