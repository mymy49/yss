/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FILE_SYSTEM__H_
#define YSS_FILE_SYSTEM__H_

/**
 * @file FileSystem.h
 * @brief Abstract file system base class for mass storage access.
 */

#include <hal/MassStorage.h>
#include <yss/error.h>
#include <stdint.h>

/**
 * @brief Base class for implementing a FAT-compatible file system.
 *
 * FileSystem provides common members and utility methods for derived
 * filesystem implementations. It exposes abstract file and directory
 * navigation, creation, and I/O operations.
 */
class FileSystem
{
protected :

	uint8_t *mSectorBuffer;
	MassStorage *mStorage;
	uint32_t mNumOfSector, mFirstSector;
	uint8_t mPartitionType;
	bool mAbleFlag;
	
	/**
	 * @brief Construct a FileSystem instance for the given storage device.
	 *
	 * @param storage Mass storage device used by the file system.
	 */
	FileSystem(MassStorage &storage);

	/**
	 * @brief Destroy the FileSystem instance.
	 */
	~FileSystem(void);

	/**
	 * @brief Validate the master boot record and partition layout.
	 *
	 * @return error_t ERROR_NONE if the MBR is valid; otherwise an error code.
	 */
	error_t checkMbr(void);
	
	/**
	 * @brief Convert a UTF-16 file name to UTF-8.
	 *
	 * @param utf16 Pointer to the UTF-16 name buffer.
	 * @return int32_t Number of bytes written to the UTF-8 buffer.
	 */
	int32_t  translateUtf16ToUtf8(void *utf16);

	/**
	 * @brief Count the number of UTF-8 characters.
	 *
	 * @param utf8 Pointer to the UTF-8 string.
	 * @return int32_t Number of UTF-8 characters.
	 */
	int32_t  countUtf8Char(void *utf8);

public :
	/**
	 * @brief Initialize the file system.
	 *
	 * @return error_t ERROR_NONE on success, otherwise an error code.
	 */
	virtual error_t initialize(void) = 0;

	/**
	 * @brief Get the number of entries in the current directory.
	 *
	 * @return int32_t Number of directories available.
	 */
	virtual int32_t getDirectoryCount(void) = 0;

	/**
	 * @brief Get the number of files in the current directory.
	 *
	 * @return int32_t Number of files available.
	 */
	virtual int32_t getFileCount(void) = 0;

	/**
	 * @brief Move the current pointer to the root directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t moveToRootDirectory(void) = 0;

	/**
	 * @brief Move the current pointer to the start of the current directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t moveToStart(void) = 0;

	/**
	 * @brief Move to a specific cluster number.
	 *
	 * @param cluster Cluster number to navigate to.
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t moveToCluster(uint32_t cluster) = 0;

	/**
	 * @brief Move to the next file entry.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t moveToNextFile(void) = 0;

	/**
	 * @brief Get the name of the current directory or file.
	 *
	 * @param des Destination buffer for the name.
	 * @param size Maximum size of the destination buffer.
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t getName(void* des, uint32_t size) = 0;

	/**
	 * @brief Move to the next directory entry.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t moveToNextDirectory(void) = 0;

	/**
	 * @brief Determine whether the current entry is a directory.
	 *
	 * @return true when current entry is a directory.
	 * @return false otherwise.
	 */
	virtual bool isDirectory(void) = 0;

	/**
	 * @brief Determine whether the current entry is a file.
	 *
	 * @return true when current entry is a file.
	 * @return false otherwise.
	 */
	virtual bool isFile(void) = 0;

	/**
	 * @brief Check if the current cluster has a following cluster.
	 *
	 * @return true if another cluster is available.
	 * @return false otherwise.
	 */
	virtual bool isHaveNextCluster(void) = 0;

	/**
	 * @brief Compare the current entry name with a UTF-8 name.
	 *
	 * @param utfName UTF-8 encoded name to compare.
	 * @return true when the names match.
	 * @return false otherwise.
	 */
	virtual bool compareName(const char *utfName) = 0;

	/**
	 * @brief Enter the current directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t enterDirectory(void) = 0;

	/**
	 * @brief Return to the parent directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t returnDirectory(void) = 0;

	/**
	 * @brief Create a new directory.
	 *
	 * @param name Name of the directory to create.
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t makeDirectory(const char*name) = 0;

	/**
	 * @brief Create a new file.
	 *
	 * @param name Name of the file to create.
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t makeFile(const char *name) = 0;

	/**
	 * @brief Open the current file for read/write.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t open(void) = 0;

	/**
	 * @brief Read from the open file into the destination buffer.
	 *
	 * @param des Destination buffer for read data.
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t read(void *des) = 0;

	/**
	 * @brief Write data from the source buffer to the open file.
	 *
	 * @param src Source buffer containing data to write.
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t write(void *src) = 0;

	/**
	 * @brief Get the size of the current file.
	 *
	 * @return uint32_t File size in bytes.
	 */
	virtual uint32_t getFileSize(void) = 0;

	/**
	 * @brief Move to the next sector in the file or directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t moveToNextSector(void) = 0;

	/**
	 * @brief Close the current file and update its size.
	 *
	 * @param fileSize Final size of the file.
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t close(uint32_t fileSize) = 0;

	/**
	 * @brief Close the current file without specifying a size.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t close(void) = 0;

	/**
	 * @brief Get the cluster number of the current directory.
	 *
	 * @return uint32_t Current directory cluster number.
	 */
	virtual uint32_t getCurrentDirectoryCluster(void) = 0;

	/**
	 * @brief Move to the start of the current file.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	virtual error_t moveToFileStart(void) = 0;

	/**
	 * @brief Get the internal sector buffer used by the file system.
	 *
	 * @return void* Pointer to the sector buffer.
	 */
	void* getSectorBuffer(void);
};

#endif
