/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FAT32__H_
#define YSS_FAT32__H_

#include <sac/FileSystem.h>
#include <yss/error.h>
#include "Fat32Cluster.h"
#include "Fat32DirectoryEntry.h"
#include <yss/Mutex.h>

class Fat32 : public FileSystem, public Mutex
{
public :
	// 최대 사용 가능한 파일 이름 숫자 maxLfnLength x 13
	Fat32(MassStorage &storage);

	error_t initialize(void);

	error_t getName(void* des, uint32_t size);

	error_t enterDirectory(void);

	error_t returnDirectory(void);

	error_t moveToRootDirectory(void);

	error_t moveToCluster(uint32_t cluster);

	error_t moveToStart(void);

	error_t moveToNextDirectory(void);

	error_t moveToNextFile(void);

	error_t makeDirectory(const char *name);

	error_t makeFile(const char *name);

	error_t open(void);

	error_t open(const char *name);

	error_t read(void *des);

	error_t write(void *src);

	error_t moveToNextSector(void);

	error_t close(uint32_t fileSize);

	error_t close(void);

	error_t moveToFileStart(void);

	bool compareName(const char *utf8);

	bool isDirectory(void);

	bool isFile(void);

	bool isHaveNextCluster(void);

	int32_t  getDirectoryCount(void);

	int32_t  getFileCount(void);

	uint32_t getFileSize(void);

	uint32_t getCurrentDirectoryCluster(void);

private :
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

	error_t initReadCluster(uint32_t cluster, void *des);

	error_t readNextBlock(void *des);

	uint32_t getCount(uint8_t *type, uint8_t typeCount);

	error_t moveToNextItem(uint8_t *type, uint8_t typeCount);
};

#endif

