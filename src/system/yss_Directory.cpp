/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/Directory.h>

Directory::Directory(FileSystem &fileSystem)
{
	mFileSystem = &fileSystem;
	mFileCount = mDirectoryCount = 0;
	mCurrentFileIndex = mCurrentDirectoryIndex = 0xFFFFFFFF;
}

Directory::Directory(FileSystem *fileSystem)
{
	mFileSystem = fileSystem;
	mFileCount = mDirectoryCount = 0;
	mCurrentFileIndex = mCurrentDirectoryIndex = 0xFFFFFFFF;
}

error_t Directory::initialize(void)
{
	error_t result;
	result = mFileSystem->initialize();
	if(result != error_t::ERROR_NONE)
		return result;

	// Cache the current counts of files and directories for quick access.
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();
	mCurrentFileIndex = mCurrentDirectoryIndex = 0xFFFFFFFF;

	return error_t::ERROR_NONE;
}

uint32_t Directory::getDirectoryCount(void)
{
	return mDirectoryCount;
}

uint32_t Directory::getFileCount(void)
{
	return mFileCount;
}

error_t Directory::getFileName(uint32_t index, void* des, uint32_t size)
{
	error_t result;

	if(index >= mFileCount)
		return error_t::INDEX_OVER;

	// Reset directory traversal state when querying file names.
	mCurrentDirectoryIndex = 0xFFFFFFFF;

	// If requested file index is before the cached current file, restart scanning.
	if(index < mCurrentFileIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != error_t::ERROR_NONE)
			return result;

		if(mFileSystem->isFile() == false)
			result = mFileSystem->moveToNextFile();
		if(result != error_t::ERROR_NONE)
			return result;

		mCurrentFileIndex = 0;
	}

	// Advance until the desired file index is reached.
	while(index != mCurrentFileIndex)
	{
		result = mFileSystem->moveToNextFile();
		if(result != error_t::ERROR_NONE)
			return result;

		if(mFileSystem->isFile() == false)
			result = mFileSystem->moveToNextFile();
		if(result != error_t::ERROR_NONE)
			return result;

		mCurrentFileIndex++;
	}

	// Return the name of the targeted file.
	return mFileSystem->getName(des, size);
}

error_t Directory::getDirectoryName(uint32_t index, void* des, uint32_t size)
{
	error_t result;

	if(index >= mDirectoryCount)
		return error_t::INDEX_OVER;

	// Reset file traversal state when querying directory names.
	mCurrentFileIndex = 0xFFFFFFFF;

	if(index < mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != error_t::ERROR_NONE)
			return result;
		
		if(mFileSystem->isDirectory() == false)
			result = mFileSystem->moveToNextDirectory();
		if(result != error_t::ERROR_NONE)
			return result;

		mCurrentDirectoryIndex = 0;
	}

	// Advance through directories until the desired index.
	while(index != mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToNextDirectory();
		if(result != error_t::ERROR_NONE)
			return result;

		mCurrentDirectoryIndex++;
	}
	
	// Return the name of the targeted directory.
	return mFileSystem->getName(des, size);
}

error_t Directory::enterDirectory(uint32_t index)
{
	error_t result;

	if(index >= mDirectoryCount)
		return error_t::INDEX_OVER;

	// Clear file traversal state when changing the current directory.
	mCurrentFileIndex = 0xFFFFFFFF;

	if(index < mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != error_t::ERROR_NONE)
			return result;
		
		if(mFileSystem->isDirectory() == false)
			result = mFileSystem->moveToNextDirectory();
		if(result != error_t::ERROR_NONE)
			return result;

		mCurrentDirectoryIndex = 0;
	}

	// Advance to the target directory index.
	while(index != mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToNextDirectory();
		if(result != error_t::ERROR_NONE)
		{
			return result;
		}

		mCurrentDirectoryIndex++;
	}
	
	result = mFileSystem->enterDirectory();
	if(result != error_t::ERROR_NONE)
		return result;
	
	// Update counts after changing directory and invalidate cached indices.
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	return error_t::ERROR_NONE;
}

error_t Directory::enterDirectory(const char *utfName)
{
	error_t result;

	// Reset file traversal state when changing directories by name.
	mCurrentFileIndex = 0xFFFFFFFF;

	result = mFileSystem->moveToStart();
	if(result != error_t::ERROR_NONE)
		return result;
	
	if(mFileSystem->isDirectory() == false)
		result = mFileSystem->moveToNextDirectory();
	if(result != error_t::ERROR_NONE)
		return result;

	mCurrentDirectoryIndex = 0;

	// Iterate through each directory entry until a matching name is found.
	while(mCurrentDirectoryIndex < mDirectoryCount)
	{
		mCurrentDirectoryIndex++;

		if(mFileSystem->compareName(utfName) == false)
		{
			result = mFileSystem->enterDirectory();
			if(result != error_t::ERROR_NONE)
				return result;

			mDirectoryCount = mFileSystem->getDirectoryCount();
			mFileCount = mFileSystem->getFileCount();

			return error_t::ERROR_NONE;
		}

		result = mFileSystem->moveToNextDirectory();
		if(result != error_t::ERROR_NONE)
			return result;
	}
	
	return error_t::NOT_EXIST_NAME;
}

error_t Directory::returnDirectory(void)
{
	error_t result;

	// Return to the parent directory and refresh directory/file counts.
	result = mFileSystem->returnDirectory();
	if(result != error_t::ERROR_NONE)
		return result;
	
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	
	return error_t::ERROR_NONE;
}

error_t Directory::makeDirectory(const char *name)
{
	error_t result;

	result = mFileSystem->makeDirectory(name);
	if(result != error_t::ERROR_NONE)
		return result;
	
	// Refresh the cached counts and invalidate traversal indices after creating a directory.
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	
	return error_t::ERROR_NONE;
}

uint32_t Directory::getCurrentDirectoryCluster(void)
{
	return mFileSystem->getCurrentDirectoryCluster();
}

