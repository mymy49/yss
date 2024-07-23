/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DIRECTORY__H_
#define YSS_DIRECTORY__H_

#include <sac/FileSystem.h>

class Directory
{
public :
	Directory(FileSystem &fileSystem);

	Directory(FileSystem *fileSystem);

	error_t initialize(void);

	uint32_t getDirectoryCount(void);

	uint32_t getFileCount(void);

	uint32_t getCurrentDirectoryCluster(void);

	error_t getFileName(uint32_t index, void* des, uint32_t size);

	error_t getDirectoryName(uint32_t index, void* des, uint32_t size);

	error_t enterDirectory(uint32_t index);

	error_t enterDirectory(const char *utfName);

	error_t returnDirectory(void);

	error_t makeDirectory(const char *name);

private :
	FileSystem *mFileSystem;
	uint32_t mFileCount, mDirectoryCount, mCurrentFileIndex, mCurrentDirectoryIndex;
};

#endif