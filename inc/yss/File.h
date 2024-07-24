/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FILE__H_
#define YSS_FILE__H_

#include <sac/FileSystem.h>

class File
{
public:
	enum
	{
		WRITE_ONLY = 0,
		READ_ONLY,
	};

	File(FileSystem &fileSystem);

	File(FileSystem *fileSystem);

	error_t initialize(void);

	error_t open(const char *fileName, uint8_t mode);

	error_t open(int32_t  cluster, uint8_t mode);

	error_t setPath(uint32_t cluster);

	uint32_t read(void *des, uint32_t size);

	uint32_t write(void *src, uint32_t size);

	uint32_t getSize(void);

	error_t moveToStart(void);

	error_t moveToEnd(void);

	error_t moveTo(uint32_t position);

	error_t makeFile(const char *fileName);

	error_t close(void);

private:
	FileSystem *mFileSystem;
	bool mOpenFlag;
	uint8_t *mBuffer, mOpenMode;
	uint32_t mFileSize, mBufferCount;

	bool checkFileName(const char *fileName);

	bool bringOneName(char *des, const char **src);

	error_t enterDirectory(const char *name);

	error_t findFile(const char *name);
};

#endif