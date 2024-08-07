/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/Fat32Cluster.h>
#include <yss/error.h>
#include <string.h>

static const int8_t gClearBuffer[512] = {0, };

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

error_t Fat32Cluster::readFat(uint32_t cluster)
{
	uint32_t table = cluster / 128;
	mAddress.tableIndex = cluster % 128;
	error_t result = error_t::ERROR_NONE;

	if(table != mLastReadFatTable)
	{
		result = save();
		if(result != error_t::ERROR_NONE)
			return result;
	
		mStorage->lock();
		result = mStorage->read(mFatSector + table, mFatTableBuffer);
		mStorage->unlock();

		mLastReadFatTable = table;
	}

	return result;
}

uint32_t Fat32Cluster::calculateNextCluster(void)
{
	return mFatTableBuffer[mAddress.tableIndex] & 0x0FFFFFFF;
}

void Fat32Cluster::initialize(MassStorage *storage, uint32_t fatSector, uint32_t fatBackup, uint32_t sectorSize, uint8_t sectorPerCluster)
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

error_t Fat32Cluster::readDataSector(void* des)
{
	error_t result;
	
	mStorage->lock();
	result = mStorage->read(mDataStartSector + (mAddress.cluster - 2) * mSectorPerCluster + mAddress.sectorIndex, des);
	mStorage->unlock();

	return result;
}

error_t Fat32Cluster::writeDataSector(void* des)
{
	error_t result;

	mStorage->lock();
	result = mStorage->write(mDataStartSector + (mAddress.cluster - 2) * mSectorPerCluster + mAddress.sectorIndex, des);
	mStorage->unlock();

	return result;
}

error_t Fat32Cluster::moveToStart(void)
{
	return moveTo(mAddress.start);
}

error_t Fat32Cluster::moveToRoot(void)
{
	mAddress.start = mRoot;
	return moveTo(mRoot);
}

error_t Fat32Cluster::moveTo(uint32_t cluster)
{
	uint32_t next;
	error_t result = error_t::ERROR_NONE;
	mAddress.sectorIndex = 0;

	if(mAddress.cluster == cluster)
		goto skip;

	save();
	mAddress.cluster = cluster;

	result = readFat(mAddress.cluster);
	if(result != error_t::ERROR_NONE)
		return result;

skip:
	next = calculateNextCluster();
	if(next == 0x0FFFFFF7)
		return error_t::BAD_SECTOR;
	
	mAddress.next = next;
	return result;
}

error_t Fat32Cluster::increaseDataSectorIndex(void)
{
	error_t result = error_t::ERROR_NONE;

	mAddress.sectorIndex++;
	if(mAddress.sectorIndex >= mSectorPerCluster)
	{
		mAddress.sectorIndex = 0;
		result = moveToNextCluster();
	}

	return result;
}

error_t Fat32Cluster::setRootCluster(uint32_t cluster)
{
	mRoot = cluster;
	mAddress.start =cluster;
	return moveToRoot();
}

error_t Fat32Cluster::setCluster(uint32_t cluster)
{
	mAddress.start =cluster;
	return moveToStart();
}

uint32_t Fat32Cluster::getRootCluster(void)
{
	return mRoot;
}

uint32_t Fat32Cluster::getStartCluster(void)
{
	return mAddress.start;
}

uint32_t Fat32Cluster::getCurrentCluster(void)
{
	return mAddress.cluster;
}

error_t Fat32Cluster::moveToNextCluster(void)
{
	error_t result;
	uint32_t next;

	if(mAddress.next == 0x0FFFFFF7)
		return error_t::BAD_SECTOR;
	else if(mAddress.next < 2 || mAddress.next > 0x0FFFFFEF)
		return error_t::NO_DATA;
	
	result = readFat(mAddress.next);
	if(result != error_t::ERROR_NONE)
		return result;

	next = calculateNextCluster();
	if(next == 0x0FFFFFF7)
		return error_t::BAD_SECTOR;
	
	mAddress.cluster = mAddress.next;
	mAddress.next = next;
	return result;
}

uint32_t Fat32Cluster::getNextCluster(void)
{
	return mAddress.next;
}

error_t Fat32Cluster::save(void)
{
	error_t result = error_t::ERROR_NONE;

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

error_t Fat32Cluster::append(bool clear)
{
	(void)clear;

	error_t result;

	uint32_t cluster = allocate();
	if(cluster == 0)
		return error_t::NO_FREE_DATA;
	
	if(mAddress.cluster / 128 != cluster / 128)
	{
		result = readFat(mAddress.cluster);
		if(result != error_t::ERROR_NONE)
			return result;

//#error_t "추가된 클러스터 정보를 테이블에 넣고 새 클러스터로 이동해서 마무리 하도록 수정해야 함"
		mFatTableBuffer[mAddress.tableIndex] = cluster;
		mUpdateFlag = true;
		save();
	
		mAddress.cluster = cluster;
		readFat(cluster);
	}
	else
	{
		mFatTableBuffer[mAddress.tableIndex] = cluster;
		mAddress.tableIndex = cluster % 128;
		mAddress.cluster = cluster;
		mUpdateFlag = true;
	}

	return error_t::ERROR_NONE;
}

uint32_t Fat32Cluster::getSectorSize(void)
{
	return mSectorSize;
}

uint32_t Fat32Cluster::allocate(bool clear)
{
	uint32_t fatTable = mLastReadFatTable, cluster;
	error_t result;
	bool overFlowFlag = false;

	while(1)
	{
		for(uint32_t i=0;i<128;i++)
		{
			// 비워진 클러스터인지 확인
			if((mFatTableBuffer[i] & 0x0FFFFFFF) == 0)
			{
				cluster = fatTable * 128 + i;
				
				// clear 플래그가 세트되어 있을 경우, 새로 할당 받은 클러스터의 데이터를 0으로 초기화
				if(clear)
				{
					for(int32_t  j=0;j<mSectorPerCluster;j++)
					{
						for(int32_t  k=0;k<10;k++)
						{
							result = mStorage->write(mDataStartSector + (cluster - 2) * mSectorPerCluster + j, (void*)gClearBuffer);
							if(result == error_t::ERROR_NONE)
								break;
						}
						if(result != error_t::ERROR_NONE)
							return 0;
					}
				}

				// 할당 완료
				mFatTableBuffer[i] = 0x0FFFFFFF;
				mStorage->lock();
				result = mStorage->write(mFatSector + fatTable, mFatTableBuffer);
				mStorage->unlock();

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
				return error_t::NO_FREE_DATA;
		}
		
		// 현재 FAT 섹터를 저장
		result = save();
		if(result != error_t::ERROR_NONE)
			return result;
		
		// 다음 FAT 섹터를 읽어옴
		mStorage->lock();
		result = mStorage->read(mFatSector + fatTable, mFatTableBuffer);
		mStorage->unlock();
		
		if(result != error_t::ERROR_NONE)
			return result;

	}
}

void Fat32Cluster::backup(void)
{
	mBackupAddress = mAddress;
}

void Fat32Cluster::restore(void)
{
	mAddress = mBackupAddress;
}

