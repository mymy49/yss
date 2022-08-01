////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/Directory.h>

Directory::Directory(sac::FileSystem &fileSystem)
{
	mFileSystem = &fileSystem;
	mFileCount = mDirectoryCount = 0;
	mCurrentFileIndex = mCurrentDirectoryIndex = 0xFFFFFFFF;
}

Directory::Directory(sac::FileSystem *fileSystem)
{
	mFileSystem = fileSystem;
}

void Directory::init(void)
{
	mFileSystem->init();
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();
	mCurrentFileIndex = mCurrentDirectoryIndex = 0xFFFFFFFF;
}

unsigned int Directory::getDirectoryCount(void)
{
	return mDirectoryCount;
}

unsigned int Directory::getFileCount(void)
{
	return mFileCount;
}

error Directory::getFileName(unsigned int index, void* des, unsigned int size)
{
	error result;

	if(index >= mFileCount)
		return Error::INDEX_OVER;

	mCurrentDirectoryIndex = 0xFFFFFFFF;

	if(index < mCurrentFileIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != Error::NONE)
			return result;

		if(mFileSystem->isFile() == false)
			result = mFileSystem->moveToNextFile();
		if(result != Error::NONE)
			return result;

		mCurrentFileIndex = 0;
	}

	while(index != mCurrentFileIndex)
	{
		result = mFileSystem->moveToNextFile();
		if(result != Error::NONE)
			return result;

		if(mFileSystem->isFile() == false)
			result = mFileSystem->moveToNextFile();
		if(result != Error::NONE)
			return result;

		mCurrentFileIndex++;
	}

	return mFileSystem->getName(des, size);
}

error Directory::getDirectoryName(unsigned int index, void* des, unsigned int size)
{
	error result;

	if(index >= mDirectoryCount)
		return Error::INDEX_OVER;

	mCurrentFileIndex = 0xFFFFFFFF;

	if(index < mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != Error::NONE)
			return result;
		
		if(mFileSystem->isDirectory() == false)
			result = mFileSystem->moveToNextDirectory();
		if(result != Error::NONE)
			return result;

		mCurrentDirectoryIndex = 0;
	}

	while(index != mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToNextDirectory();
		if(result != Error::NONE)
			return result;

		mCurrentDirectoryIndex++;
	}
	
	return mFileSystem->getName(des, size);
}

error Directory::enterDirectory(unsigned int index)
{
	error result;

	if(index >= mDirectoryCount)
		return Error::INDEX_OVER;

	mCurrentFileIndex = 0xFFFFFFFF;

	if(index < mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != Error::NONE)
			return result;
		
		if(mFileSystem->isDirectory() == false)
			result = mFileSystem->moveToNextDirectory();
		if(result != Error::NONE)
			return result;

		mCurrentDirectoryIndex = 0;
	}

	while(index != mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToNextDirectory();
		if(result != Error::NONE)
		{
			return result;
		}

		mCurrentDirectoryIndex++;
	}
	
	result = mFileSystem->enterDirectory();
	if(result != Error::NONE)
		return result;
	
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	return Error::NONE;
}

error Directory::enterDirectory(const char *utfName)
{
	error result;

	mCurrentFileIndex = 0xFFFFFFFF;

	result = mFileSystem->moveToStart();
	if(result != Error::NONE)
		return result;
	
	if(mFileSystem->isDirectory() == false)
		result = mFileSystem->moveToNextDirectory();
	if(result != Error::NONE)
		return result;

	mCurrentDirectoryIndex = 0;

	while(mCurrentDirectoryIndex < mDirectoryCount)
	{
		mCurrentDirectoryIndex++;

		if(mFileSystem->compareName(utfName) == false)
		{
			result = mFileSystem->enterDirectory();
			if(result != Error::NONE)
				return result;

			mDirectoryCount = mFileSystem->getDirectoryCount();
			mFileCount = mFileSystem->getFileCount();

			return Error::NONE;
		}

		result = mFileSystem->moveToNextDirectory();
		if(result != Error::NONE)
			return result;
	}
	
	return Error::NOT_EXIST_NAME;
}

error Directory::returnDirectory(void)
{
	error result;

	result = mFileSystem->returnDirectory();
	if(result != Error::NONE)
		return result;
	
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	
	return Error::NONE;
}

error Directory::makeDirectory(const char *name)
{
#warning "Fat32에 있는 내용 끌어오기"
	error result;

	result = mFileSystem->makeDirectory(name);
	if(result != Error::NONE)
		return result;
	
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	
	return Error::NONE;
}
