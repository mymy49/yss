/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FAT32_CLUSTER__H_
#define YSS_FAT32_CLUSTER__H_

#include <yss/error.h>
#include <sac/FileSystem.h>

class Fat32Cluster
{

public:
	struct Address
	{
		uint32_t start, cluster, next, tableIndex;
		uint8_t sectorIndex;
	};

	Fat32Cluster(void);

	void initialize(MassStorage *storage, uint32_t fatSector, uint32_t fatBackup, uint32_t sectorSize, uint8_t sectorPerCluster);

	error_t save(void);

	error_t moveToNextCluster(void);

	error_t increaseDataSectorIndex(void);

	error_t append(bool clear = true);

	error_t setRootCluster(uint32_t cluster);

	uint32_t getRootCluster(void);

	error_t setCluster(uint32_t cluster);

	uint32_t getStartCluster(void);

	uint32_t getCurrentCluster(void);

	uint32_t getNextCluster(void);

	error_t readDataSector(void* des);

	error_t writeDataSector(void* des);

	error_t moveToRoot(void);

	error_t moveToStart(void);

	error_t moveTo(uint32_t cluster);

	uint32_t getSectorSize(void);

	uint32_t allocate(bool clear = true);

	void backup(void);

	void restore(void);

private:
	uint32_t mFatTableBuffer[128], mFatLength;
	uint32_t mRoot, mFatSector, mFatBackupSector, mLastReadFatTable, mSectorSize, mDataStartSector;
	uint8_t mSectorPerCluster;
	MassStorage *mStorage;
	bool mUpdateFlag;
	Address mAddress, mBackupAddress;

	error_t readFat(uint32_t cluster);
	uint32_t calculateNextCluster(void);
};

#endif
