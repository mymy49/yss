/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FAT32_DIRECTORY_ENTRY__H_
#define YSS_FAT32_DIRECTORY_ENTRY__H_

/**
 * @file Fat32DirectoryEntry.h
 * @brief FAT32 directory entry management and name handling.
 */

#include "Fat32Cluster.h"

/**
 * @brief Handles FAT32 directory entries and long file name records.
 *
 * Fat32DirectoryEntry provides methods for navigating directory entries,
 * creating files and directories, and working with short and long file names.
 */
class Fat32DirectoryEntry
{
public:
	/**
	 * @brief Construct a new Fat32DirectoryEntry object.
	 */
	Fat32DirectoryEntry(void);

	/**
	 * @brief Initialize the directory entry helper.
	 *
	 * @param cluster FAT32 cluster manager instance.
	 * @param sectorBuffer Buffer for sector data.
	 */
	void initialize(Fat32Cluster &cluster, void* sectorBuffer);

	/**
	 * @brief Move to the root directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToRoot(void);

	/**
	 * @brief Move to the start of the current directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToStart(void);

	/**
	 * @brief Move to the next directory entry.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToNext(void);

	/**
	 * @brief Move to the end of the current directory.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToEnd(void);

	/**
	 * @brief Set the root cluster for the current directory.
	 *
	 * @param cluster Root cluster number.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t setRootCluster(uint32_t cluster);

	/**
	 * @brief Set the current directory cluster.
	 *
	 * @param cluster Cluster number to use.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t setCluster(uint32_t cluster);

	/**
	 * @brief Append a new directory entry.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t append(void);

	/**
	 * @brief Get the root cluster number.
	 *
	 * @return uint32_t Root cluster number.
	 */
	uint32_t getRootCluster(void);
	
	/**
	 * @brief Create a new directory entry.
	 *
	 * @param name Directory name.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t makeDirectory(const char *name);

	/**
	 * @brief Create a new file entry.
	 *
	 * @param name File name.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t makeFile(const char *name);

	/**
	 * @brief Retrieve the current target name.
	 *
	 * @param des Destination buffer for the name.
	 * @param size Size of the destination buffer.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t getTargetName(void *des, uint32_t size);

	/**
	 * @brief Get the attribute of the current target entry.
	 *
	 * @return uint8_t Attribute flags.
	 */
	uint8_t getTargetAttribute(void);

	/**
	 * @brief Get the starting cluster of the current target entry.
	 *
	 * @return uint32_t Starting cluster number.
	 */
	uint32_t getTargetCluster(void);

	/**
	 * @brief Get the size of the current target file.
	 *
	 * @return uint32_t File size in bytes.
	 */
	uint32_t getTargetFileSize(void);

	/**
	 * @brief Set the size of the current target file.
	 *
	 * @param size File size in bytes.
	 */
	void setTargetFileSize(uint32_t size);

	/**
	 * @brief Compare the current target name with a UTF-8 string.
	 *
	 * @param utf8 UTF-8 encoded name.
	 * @return true if the names match.
	 * @return false otherwise.
	 */
	bool comapreTargetName(const char *utf8);

	/**
	 * @brief Save the current directory entry to the file system.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t saveEntry(void);

private:
	struct LongFileName
	{
		int8_t order;
		char name1[10];
		int8_t attr;
		int8_t type;
		int8_t checksum;
		char name2[12];
		int8_t zero[2];
		char name3[4];
	};

	struct DirectoryEntry
	{
		char name[8];
		int8_t extention[3];
		int8_t attr;
		int8_t reserved[2];
		uint16_t createdTime;
		uint16_t createdDate;
		uint16_t lastAccessedDate;
		uint16_t startingClusterHigh;
		uint16_t lastModifiedTime;
		uint16_t lastModifiedDate;
		uint16_t startingClusterLow;
		uint32_t fileSize;
	};
	
	enum
	{
		MAX_LFN = 20
	};

	Fat32Cluster *mCluster;
	DirectoryEntry *mEntryBuffer;
	uint16_t mSectorSize;
	int16_t mIndex;
	uint8_t mCurrentAttribute, mLfnCount;
	LongFileName mLfn[MAX_LFN];

	error_t insertEntry(uint8_t lfnLen, DirectoryEntry *src);

	uint32_t translateUtf16ToUtf8(const char *utf16);

	uint32_t translateMixedUtf16ToUtf8(const char *utf16);

	uint16_t translateUtf8ToUtf16(const char *utf8);

	int32_t  strlen(const char *src);

	void setShortName(void *des, const char *src);

	uint8_t calculateChecksum(DirectoryEntry *src);

	void copyStringUtf8ToLfnBuffer(const char *utf8, int32_t len);

	DirectoryEntry getCurrentDirectoryEntry(void);

	error_t prepareInsert(uint32_t &cluster, DirectoryEntry &sfn, uint8_t attribute, const char *name, uint32_t len);
};

#endif
