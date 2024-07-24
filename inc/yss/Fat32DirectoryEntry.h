/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FAT32_DIRECTORY_ENTRY__H_
#define YSS_FAT32_DIRECTORY_ENTRY__H_

#include "Fat32Cluster.h"

class Fat32DirectoryEntry
{
public:
	Fat32DirectoryEntry(void);

	void initialize(Fat32Cluster &cluster, void* sectorBuffer);

	error_t moveToRoot(void);

	error_t moveToStart(void);

	error_t moveToNext(void);

	error_t moveToEnd(void);

	error_t setRootCluster(uint32_t cluster);

	error_t setCluster(uint32_t cluster);

	error_t append(void);

	uint32_t getRootCluster(void);
	
	error_t makeDirectory(const char *name);

	error_t makeFile(const char *name);

	error_t getTargetName(void *des, uint32_t size);

	uint8_t getTargetAttribute(void);

	uint32_t getTargetCluster(void);

	uint32_t getTargetFileSize(void);

	void setTargetFileSize(uint32_t size);

	bool comapreTargetName(const char *utf8);

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
