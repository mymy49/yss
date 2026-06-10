/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FAT32__H_
#define YSS_FAT32__H_

/**
 * @file Fat32.h
 * @brief FAT32 file system implementation for mass storage devices.
 */

#include <yss/FileSystem.h>
#include <yss/error.h>
#include "Fat32Cluster.h"
#include "Fat32DirectoryEntry.h"
#include <yss/Mutex.h>

/**
 * @brief FAT32 file system driver class.
 *
 * Implements FileSystem operations for FAT32-formatted storage. Inherits from
 * FileSystem for navigation and I/O and Mutex for thread-safe access.
 */
class Fat32 : public FileSystem, public Mutex
{
public :
	/**
	 * @brief Construct a new Fat32 object.
	 *
	 * @param storage MassStorage device used by the FAT32 file system.
	 */
	Fat32(MassStorage &storage);

	/**
	 * @brief Initialize the FAT32 file system.
	 *
	 * @return error_t ERROR_NONE on success, or an error code.
	 */
	error_t initialize(void);

	/**
	 * @brief Retrieve the current entry name.
	 *
	 * @param des Destination buffer for the name.
	 * @param size Size of the destination buffer.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t getName(void* des, uint32_t size);

	/**
	 * @brief Enter the current directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t enterDirectory(void);

	/**
	 * @brief Return to the parent directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t returnDirectory(void);

	/**
	 * @brief Move to the root directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToRootDirectory(void);

	/**
	 * @brief Move to a specific cluster.
	 *
	 * @param cluster Cluster number to move to.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToCluster(uint32_t cluster);

	/**
	 * @brief Reset to the start of the current directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToStart(void);

	/**
	 * @brief Move to the next directory entry.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToNextDirectory(void);

	/**
	 * @brief Move to the next file entry.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToNextFile(void);

	/**
	 * @brief Create a new directory.
	 *
	 * @param name Directory name.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t makeDirectory(const char *name);

	/**
	 * @brief Create a new file.
	 *
	 * @param name File name.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t makeFile(const char *name);

	/**
	 * @brief Open the current file for read or write.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t open(void);

	/**
	 * @brief Open a named file.
	 *
	 * @param name Name of the file to open.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t open(const char *name);

	/**
	 * @brief Read data from the open file.
	 *
	 * @param des Destination buffer.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t read(void *des);

	/**
	 * @brief Write data to the open file.
	 *
	 * @param src Source buffer.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t write(void *src);

	/**
	 * @brief Move to the next sector of the current file.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToNextSector(void);

	/**
	 * @brief Close the current file and update its size.
	 *
	 * @param fileSize Final file size.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t close(uint32_t fileSize);

	/**
	 * @brief Close the current file.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t close(void);

	/**
	 * @brief Move to the start of the current file.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToFileStart(void);

	/**
	 * @brief Compare the current entry name with a UTF-8 name.
	 *
	 * @param utf8 UTF-8 encoded name.
	 * @return true if the names match.
	 * @return false otherwise.
	 */
	bool compareName(const char *utf8);

	/**
	 * @brief Check whether the current entry is a directory.
	 *
	 * @return true if the current entry is a directory.
	 */
	bool isDirectory(void);

	/**
	 * @brief Check whether the current entry is a file.
	 *
	 * @return true if the current entry is a file.
	 */
	bool isFile(void);

	/**
	 * @brief Check if there is another cluster chained after the current one.
	 *
	 * @return true if a next cluster exists.
	 */
	bool isHaveNextCluster(void);

	/**
	 * @brief Get the number of directories in the current location.
	 *
	 * @return int32_t Directory count.
	 */
	int32_t  getDirectoryCount(void);

	/**
	 * @brief Get the number of files in the current location.
	 *
	 * @return int32_t File count.
	 */
	int32_t  getFileCount(void);

	/**
	 * @brief Get the size of the current file.
	 *
	 * @return uint32_t Current file size in bytes.
	 */
	uint32_t getFileSize(void);

	/**
	 * @brief Get the cluster number of the current directory.
	 *
	 * @return uint32_t Current directory cluster.
	 */
	uint32_t getCurrentDirectoryCluster(void);

private :
	/**
	 * @brief Long file name directory entry structure.
	 */
	struct LongFileName
	{
		int8_t order;
		int8_t name1[10];
		int8_t attr;
		int8_t type;
		int8_t checksum;
		int8_t name2[12];
		int8_t zero[2];
		int8_t name3[4];
	};

	enum
	{
		MAX_LFN = 20
	};

	uint32_t mCurrentFileCluster;
	bool mAbleFlag, mFileOpen;
	uint8_t mSectorPerCluster, mNumFATs;
	uint16_t mFsInfoSector;
	uint32_t mNumOfFreeClusters, mNextFreeCluster;
	uint32_t mFatSize, mRootCluster;
	uint32_t mBufferedFatSector, mFileCluster;
	
	Fat32Cluster mCluster;
	Fat32DirectoryEntry mDirectoryEntry;

	/**
	 * @brief Read a cluster into the provided buffer.
	 *
	 * @param cluster Cluster number to read.
	 * @param des Destination buffer.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t initReadCluster(uint32_t cluster, void *des);

	/**
	 * @brief Read the next block of the current file.
	 *
	 * @param des Destination buffer for the block.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t readNextBlock(void *des);

	/**
	 * @brief Count how many entries match the provided type list.
	 *
	 * @param type Array of directory entry types to count.
	 * @param typeCount Number of types in the array.
	 * @return uint32_t Count of matching entries.
	 */
	uint32_t getCount(uint8_t *type, uint8_t typeCount);

	/**
	 * @brief Move to the next item matching one of the provided entry types.
	 *
	 * @param type Array of matching types.
	 * @param typeCount Number of types in the array.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToNextItem(uint8_t *type, uint8_t typeCount);
};

#endif

