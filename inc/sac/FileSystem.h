/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FILE_SYSTEM__H_
#define YSS_FILE_SYSTEM__H_

#include <sac/MassStorage.h>
#include <yss/error.h>
#include <stdint.h>

class FileSystem
{
protected :

	uint8_t *mSectorBuffer;
	MassStorage *mStorage;
	uint32_t mNumOfSector, mFirstSector;
	uint8_t mPartitionType;
	bool mAbleFlag;
	
	FileSystem(MassStorage &storage);
	~FileSystem(void);
	error_t checkMbr(void);
	
	int32_t  translateUtf16ToUtf8(void *utf16);
	int32_t  countUtf8Char(void *utf8);

public :
	virtual error_t initialize(void) = 0;
	virtual int32_t getDirectoryCount(void) = 0;
	virtual int32_t getFileCount(void) = 0;
	virtual error_t moveToRootDirectory(void) = 0;
	virtual error_t moveToStart(void) = 0;
	virtual error_t moveToCluster(uint32_t cluster) = 0;
	virtual error_t moveToNextFile(void) = 0;
	virtual error_t getName(void* des, uint32_t size) = 0;
	virtual error_t moveToNextDirectory(void) = 0;
	virtual bool isDirectory(void) = 0;
	virtual bool isFile(void) = 0;
	virtual bool isHaveNextCluster(void) = 0;
	virtual bool compareName(const char *utfName) = 0;
	virtual error_t enterDirectory(void) = 0;
	virtual error_t returnDirectory(void) = 0;
	virtual error_t makeDirectory(const char*name) = 0;
	virtual error_t makeFile(const char *name) = 0;
	virtual error_t open(void) = 0;
	virtual error_t read(void *des) = 0;
	virtual error_t write(void *src) = 0;
	virtual uint32_t getFileSize(void) = 0;
	virtual error_t moveToNextSector(void) = 0;
	virtual error_t close(uint32_t fileSize) = 0;
	virtual error_t close(void) = 0;
	virtual uint32_t getCurrentDirectoryCluster(void) = 0;
	virtual error_t moveToFileStart(void) = 0;

	void* getSectorBuffer(void);
};

#endif
