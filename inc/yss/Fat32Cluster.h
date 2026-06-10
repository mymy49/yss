/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FAT32_CLUSTER__H_
#define YSS_FAT32_CLUSTER__H_

/**
 * @file Fat32Cluster.h
 * @brief FAT32 cluster management helper for reading and writing data clusters.
 */

#include <yss/error.h>
#include <yss/FileSystem.h>

/**
 * @brief Manages FAT32 cluster navigation and data sector access.
 *
 * Fat32Cluster handles reading, writing, allocation, and cluster chain
 * traversal for a FAT32 volume.
 */
class Fat32Cluster
{

public:
	/**
	 * @brief Cluster address and sector state for the current position.
	 */
	struct Address
	{
		uint32_t start, cluster, next, tableIndex;
		uint8_t sectorIndex;
	};

	/**
	 * @brief Construct a new Fat32Cluster helper.
	 */
	Fat32Cluster(void);

	/**
	 * @brief Initialize FAT32 cluster state.
	 *
	 * @param storage Mass storage device used by FAT32.
	 * @param fatSector First FAT sector.
	 * @param fatBackup Backup FAT sector.
	 * @param sectorSize Sector size in bytes.
	 * @param sectorPerCluster Number of sectors per cluster.
	 */
	void initialize(MassStorage *storage, uint32_t fatSector, uint32_t fatBackup, uint32_t sectorSize, uint8_t sectorPerCluster);

	/**
	 * @brief Save any pending FAT updates to storage.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t save(void);

	/**
	 * @brief Advance to the next cluster in the chain.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToNextCluster(void);

	/**
	 * @brief Increase the current data sector index within the cluster.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t increaseDataSectorIndex(void);

	/**
	 * @brief Append a new cluster to the current chain.
	 *
	 * @param clear If true, clear the newly allocated cluster.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t append(bool clear = true);

	/**
	 * @brief Set the root cluster number.
	 *
	 * @param cluster Root cluster number.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t setRootCluster(uint32_t cluster);

	/**
	 * @brief Get the root cluster number.
	 *
	 * @return uint32_t Root cluster number.
	 */
	uint32_t getRootCluster(void);

	/**
	 * @brief Set the current cluster number.
	 *
	 * @param cluster Cluster number to use.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t setCluster(uint32_t cluster);

	/**
	 * @brief Get the starting cluster of the current chain.
	 *
	 * @return uint32_t Starting cluster number.
	 */
	uint32_t getStartCluster(void);

	/**
	 * @brief Get the current cluster number.
	 *
	 * @return uint32_t Current cluster number.
	 */
	uint32_t getCurrentCluster(void);

	/**
	 * @brief Get the next cluster number in the chain.
	 *
	 * @return uint32_t Next cluster number.
	 */
	uint32_t getNextCluster(void);

	/**
	 * @brief Read the current data sector into the destination buffer.
	 *
	 * @param des Destination buffer.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t readDataSector(void* des);

	/**
	 * @brief Write the current data sector from the source buffer.
	 *
	 * @param des Source buffer.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t writeDataSector(void* des);

	/**
	 * @brief Move to the root cluster.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToRoot(void);

	/**
	 * @brief Move to the start of the current chain.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToStart(void);

	/**
	 * @brief Move to a specific cluster number.
	 *
	 * @param cluster Cluster number to move to.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveTo(uint32_t cluster);

	/**
	 * @brief Get the sector size used by the cluster helper.
	 *
	 * @return uint32_t Sector size in bytes.
	 */
	uint32_t getSectorSize(void);

	/**
	 * @brief Allocate a new cluster and optionally clear it.
	 *
	 * @param clear If true, clear the newly allocated cluster.
	 * @return uint32_t New cluster number.
	 */
	uint32_t allocate(bool clear = true);

	/**
	 * @brief Backup the current cluster state.
	 */
	void backup(void);

	/**
	 * @brief Restore the backed-up cluster state.
	 */
	void restore(void);

private:
	uint32_t mFatTableBuffer[128], mFatLength;
	uint32_t mRoot, mFatSector, mFatBackupSector, mLastReadFatTable, mSectorSize, mDataStartSector;
	uint8_t mSectorPerCluster;
	MassStorage *mStorage;
	bool mUpdateFlag;
	Address mAddress, mBackupAddress;

	/**
	 * @brief Read the FAT entry for a specific cluster.
	 *
	 * @param cluster Cluster number to read.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t readFat(uint32_t cluster);

	/**
	 * @brief Calculate the next cluster number from the current FAT entry.
	 *
	 * @return uint32_t Next cluster number.
	 */
	uint32_t calculateNextCluster(void);
};

#endif
