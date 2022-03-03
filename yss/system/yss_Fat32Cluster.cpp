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

#include <yss/Fat32Cluster.h>
#include <yss/error.h>
#include <string.h>
#include <__cross_studio_io.h>

static const char gClearBuffer[512] = {0, };

error Fat32Cluster::readFat(unsigned int cluster)
{
	unsigned int table = cluster / 128;
	mAddress.tableIndex = cluster % 128;
	error result = Error::NONE;

	if(table != mLastReadFatTable)
	{
		result = save();
		if(result != Error::NONE)
			return result;
	
		mStorage->lock();
		result = mStorage->read(mFatSector + table, mFatTableBuffer);
		mStorage->unlock();

		mLastReadFatTable = table;
	}

	return result;
}

unsigned int Fat32Cluster::calculateNextCluster(void)
{
	return mFatTableBuffer[mAddress.tableIndex] & 0x0FFFFFFF;
}

Fat32Cluster::Fat32Cluster(void)
{
	mStorage = 0;
	mRoot = mAddress.cluster = 0;
	mFatSector = 0;
	mFatBackupSector = 0;
	mAddress.next = 0;
	mFatLength = 0;
	mAddress.sectorIndex = 0;
	mLastReadFatTable = 0xFFFFFFFF;
	mUpdateFlag = false;
}

void Fat32Cluster::init(sac::MassStorage *storage, unsigned int fatSector, unsigned int fatBackup, unsigned int sectorSize, unsigned char sectorPerCluster)
{
	mStorage = storage;
	mFatSector = fatSector;
	mFatBackupSector = fatBackup;
	mAddress.next = 0;
	mFatLength = fatBackup - fatSector;
	mSectorPerCluster = sectorPerCluster;
	mSectorSize = sectorSize;
	mDataStartSector = fatBackup + mFatLength;
	mUpdateFlag = false;
}

error Fat32Cluster::readDataSector(void* des)
{
	error result;
	
	mStorage->lock();
	result = mStorage->read(mDataStartSector + (mAddress.cluster - 2) * mSectorPerCluster + mAddress.sectorIndex, des);
	mStorage->unlock();

	return result;
}

error Fat32Cluster::writeDataSector(void* des)
{
	error result;

	mStorage->lock();
	result = mStorage->write(mDataStartSector + (mAddress.cluster - 2) * mSectorPerCluster + mAddress.sectorIndex, des);
	mStorage->unlock();

	return result;
}

error Fat32Cluster::moveToStart(void)
{
	return moveTo(mAddress.start);
}

error Fat32Cluster::moveToRoot(void)
{
	mAddress.start = mRoot;
	return moveTo(mRoot);
}

error Fat32Cluster::moveTo(unsigned int cluster)
{
	unsigned int next;
	error result = Error::NONE;
	mAddress.sectorIndex = 0;

	if(mAddress.cluster == cluster)
		goto skip;

	save();
	mAddress.cluster = cluster;

	result = readFat(mAddress.cluster);
	if(result != Error::NONE)
		return result;

skip:
	next = calculateNextCluster();
	if(next == 0x0FFFFFF7)
		return Error::BAD_SECTOR;
	
	mAddress.next = next;
	return result;
}

error Fat32Cluster::increaseDataSectorIndex(void)
{
	error result = Error::NONE;

	mAddress.sectorIndex++;
	if(mAddress.sectorIndex >= mSectorPerCluster)
	{
		mAddress.sectorIndex = 0;
		mStorage->lock();
		result = moveToNextCluster();
		mStorage->unlock();
	}

	return result;
}

error Fat32Cluster::setRootCluster(unsigned int cluster)
{
	mRoot = cluster;
	mAddress.start =cluster;
	return moveToRoot();
}

error Fat32Cluster::setCluster(unsigned int cluster)
{
	mAddress.start =cluster;
	return moveToStart();
}

unsigned int Fat32Cluster::getRootCluster(void)
{
	return mRoot;
}

unsigned int Fat32Cluster::getStartCluster(void)
{
	return mAddress.start;
}

unsigned int Fat32Cluster::getCurrentCluster(void)
{
	return mAddress.cluster;
}

error Fat32Cluster::moveToNextCluster(void)
{
	error result;
	unsigned int next;

	if(mAddress.next == 0x0FFFFFF7)
		return Error::BAD_SECTOR;
	else if(mAddress.next < 2 || mAddress.next > 0x0FFFFFEF)
		return Error::NO_DATA;
	
	result = readFat(mAddress.next);
	if(result != Error::NONE)
		return result;

	next = calculateNextCluster();
	if(next == 0x0FFFFFF7)
		return Error::BAD_SECTOR;
	
	mAddress.cluster = mAddress.next;
	mAddress.next = next;
	return result;
}

error Fat32Cluster::save(void)
{
	error result = Error::NONE;

	if(mUpdateFlag)
	{
		mStorage->lock();
		mUpdateFlag = false;
		result = mStorage->write(mFatSector + mLastReadFatTable, mFatTableBuffer);
		result = mStorage->write(mFatBackupSector + mLastReadFatTable, mFatTableBuffer);
		mStorage->unlock();
	}

	return result;
}

#warning "아직 완료 안됨"
error Fat32Cluster::append(bool clear)
{
	unsigned int fatTable = mLastReadFatTable, current;
	error result;
	bool overFlowFlag = false;

	if(mAddress.next == 0x0FFFFFF7)
	{
		return Error::BAD_SECTOR;
	}

	while(1)
	{
		for(unsigned int i=0;i<128;i++)
		{
			if(mFatTableBuffer[i] & 0x0FFFFFFF == 0)
			{
				current = fatTable * 128 + i;

				// 마지막 클러스터에 발견한 클러스터 번지 추가
				if(fatTable != mLastReadFatTable) // 섹터가 다른 경우
				{
					mStorage->lock();
					result = mStorage->read(mFatSector + mLastReadFatTable, mFatTableBuffer);
					mStorage->unlock();
					if(result != Error::NONE)
						return result;

					mFatTableBuffer[mAddress.tableIndex] = current;
					mUpdateFlag = true;
					result = save();
					if(result != Error::NONE)
						return result;

					mStorage->lock();
					result = mStorage->read(mFatSector + fatTable, mFatTableBuffer);
					mStorage->unlock();
				}
				else // 섹터가 같은 경우
					mFatTableBuffer[mAddress.tableIndex] = current;
				
				if(clear)
				{
					for(int j=0;j<mSectorPerCluster;j++)
						result = mStorage->write(mDataStartSector + (current - 2) * mSectorPerCluster + j, (void*)gClearBuffer);
				}

				// 할당 완료
				mAddress.tableIndex = i;
				mAddress.cluster = current;
				mLastReadFatTable = fatTable;
				mFatTableBuffer[i] = 0x0FFFFFFF;
				mUpdateFlag = true;
			}
		}
		
		fatTable++;
		if(overFlowFlag == false)
		{
			if(fatTable >= mFatLength)
			{
				overFlowFlag = true;
				fatTable = 0;
			}
		}
		else
		{
			if(fatTable == mLastReadFatTable)
			{
				result = Error::NO_FREE_DATA;
				return result;
			}
		}

		result = save();
		if(result != Error::NONE)
			return result;

		mStorage->lock();
		result = mStorage->read(mFatSector + fatTable, mFatTableBuffer);
		mStorage->unlock();
		
		if(result != Error::NONE)
			return result;
	}
}

unsigned int Fat32Cluster::getSectorSize(void)
{
	return mSectorSize;
}

unsigned int Fat32Cluster::allocate(bool clear)
{
	unsigned int fatTable = mLastReadFatTable, cluster;
	error result;
	bool overFlowFlag = false;

	do
	{
		for(unsigned int i=0;i<128;i++)
		{
			// 비워진 클러스터인지 확인
			if((mFatTableBuffer[i] & 0x0FFFFFFF) == 0)
			{
				cluster = fatTable * 128 + i;
				
				// clear 플래그가 세트되어 있을 경우, 새로 할당 받은 클러스터의 데이터를 0으로 초기화
				if(clear)
				{
					for(int j=0;j<mSectorPerCluster;j++)
					{
						result = mStorage->write(mDataStartSector + (cluster - 2) * mSectorPerCluster + j, (void*)gClearBuffer);
						if(result != Error::NONE)
							return result;
					}
					
				}

				// 할당 완료
				mFatTableBuffer[i] = 0x0FFFFFFF;
				mUpdateFlag = true;

				return cluster;
			}
		}
		
		fatTable++;

		// FAT 테이블 끝에 도달해서 다시 시작 했는가?
		if(overFlowFlag == false) // 아직 FAT 테이블 끝까지 도착 안함
		{
			// FAT 테이블의 끝까지 갔는가?
			if(fatTable >= mFatLength)
			{
				overFlowFlag = true;
				fatTable = 0;
			}
		}
		else	// FAT 테이블 끝까지 도착하고 처음부터 다시 시작함
		{
			if(fatTable == mLastReadFatTable)
				return Error::NO_FREE_DATA;
		}
		
		// 현재이 FAT 섹터를 저장
		result = save();
		if(result != Error::NONE)
			return result;
		
		// 다음 FAT 섹터를 읽어옴
		mStorage->lock();
		result = mStorage->read(mFatSector + fatTable, mFatTableBuffer);
		mStorage->unlock();
		
		if(result != Error::NONE)
			return result;

	}while(1);
}

void Fat32Cluster::backup(void)
{
	mBackupAddress = mAddress;
}

void Fat32Cluster::restore(void)
{
	mAddress = mBackupAddress;
}

