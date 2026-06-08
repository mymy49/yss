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

	// Load the FAT sector that contains the cluster entry.
	if(table != mLastReadFatTable)
	{
		// Save any pending updates before reading a new FAT sector.
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
	// Data region begins after FAT and its backup area.
	mDataStartSector = fatBackup + mFatLength;
	mUpdateFlag = false;
}

error_t Fat32Cluster::readDataSector(void* des)
{
	error_t result;
	
	// Read the current sector in the active cluster.
	mStorage->lock();
	result = mStorage->read(mDataStartSector + (mAddress.cluster - 2) * mSectorPerCluster + mAddress.sectorIndex, des);
	mStorage->unlock();

	return result;
}

error_t Fat32Cluster::writeDataSector(void* des)
{
	error_t result;

	// Write to the current sector in the active cluster.
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

	// Save current FAT updates before moving to a new cluster.
	save();
	mAddress.cluster = cluster;

	result = readFat(mAddress.cluster);
	if(result != error_t::ERROR_NONE)
		return result;

skip:
	// Cache the next cluster from the FAT entry.
	next = calculateNextCluster();
	if(next == 0x0FFFFFF7)
		return error_t::BAD_SECTOR;
	
	mAddress.next = next;
	return result;
}

error_t Fat32Cluster::increaseDataSectorIndex(void)
{
	error_t result = error_t::ERROR_NONE;

	// Advance to the next sector within the cluster.
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

	// Validate the next cluster pointer.
	if(mAddress.next == 0x0FFFFFF7)
		return error_t::BAD_SECTOR;
	else if(mAddress.next < 2 || mAddress.next > 0x0FFFFFEF)
		return error_t::NO_DATA;
	
	// Load the FAT sector containing the next cluster entry.
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
		// Write the modified FAT sector and its backup to storage.
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

	// Allocate a new cluster in the FAT.
	uint32_t cluster = allocate();
	if(cluster == 0)
		return error_t::NO_FREE_DATA;
	
	if(mAddress.cluster / 128 != cluster / 128)
	{
		// The new cluster is in a different FAT sector, so load the current FAT entry first.
		result = readFat(mAddress.cluster);
		if(result != error_t::ERROR_NONE)
			return result;

		mFatTableBuffer[mAddress.tableIndex] = cluster;
		mUpdateFlag = true;
		save();
	
		mAddress.cluster = cluster;
		readFat(cluster);
	}
	else
	{
		// The new cluster remains in the same FAT sector.
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
			// Check whether this FAT entry is free.
			if((mFatTableBuffer[i] & 0x0FFFFFFF) == 0)
			{
				cluster = fatTable * 128 + i;
				
				// If requested, clear the newly allocated cluster data.
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

				// Mark the cluster as allocated in the FAT and write it back.
				mFatTableBuffer[i] = 0x0FFFFFFF;
				mStorage->lock();
				result = mStorage->write(mFatSector + fatTable, mFatTableBuffer);
				mStorage->unlock();

				return cluster;
			}
		}
		
		fatTable++;

		// Have we reached the end of the FAT table and wrapped around?
		if(overFlowFlag == false) // still scanning forward through FAT tables
		{
			// Did we reach the final FAT table?
			if(fatTable >= mFatLength)
			{
				overFlowFlag = true;
				fatTable = 0;
			}
		}
		else	// wrapped around to the beginning of the FAT table list
		{
			if(fatTable == mLastReadFatTable)
				return error_t::NO_FREE_DATA;
		}
		
		// Save changes to the current FAT sector before loading a new one.
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
	// Preserve the current cluster traversal state.
	mBackupAddress = mAddress;
}

void Fat32Cluster::restore(void)
{
	// Restore the preserved cluster traversal state.
	mAddress = mBackupAddress;
}

