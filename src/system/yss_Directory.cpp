////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
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
	mFileCount = mDirectoryCount = 0;
	mCurrentFileIndex = mCurrentDirectoryIndex = 0xFFFFFFFF;
}

// 새로운 SD 메모리가 장착되면 init()을 먼저 호출해줘야 한다.
// SD 메모리의 기본 정보를 읽어오고 루트 디렉토리를 찾는다.
error Directory::initialize(void)
{
	error result;
	result = mFileSystem->initialize();
	if(result != error::ERROR_NONE)
		return result;

	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();
	mCurrentFileIndex = mCurrentDirectoryIndex = 0xFFFFFFFF;

	return error::ERROR_NONE;
}

uint32_t Directory::getDirectoryCount(void)
{
	return mDirectoryCount;
}

uint32_t Directory::getFileCount(void)
{
	return mFileCount;
}

error Directory::getFileName(uint32_t index, void* des, uint32_t size)
{
	error result;

	if(index >= mFileCount)
		return error::INDEX_OVER;

	mCurrentDirectoryIndex = 0xFFFFFFFF;

	if(index < mCurrentFileIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != error::ERROR_NONE)
			return result;

		if(mFileSystem->isFile() == false)
			result = mFileSystem->moveToNextFile();
		if(result != error::ERROR_NONE)
			return result;

		mCurrentFileIndex = 0;
	}

	while(index != mCurrentFileIndex)
	{
		result = mFileSystem->moveToNextFile();
		if(result != error::ERROR_NONE)
			return result;

		if(mFileSystem->isFile() == false)
			result = mFileSystem->moveToNextFile();
		if(result != error::ERROR_NONE)
			return result;

		mCurrentFileIndex++;
	}

	return mFileSystem->getName(des, size);
}

error Directory::getDirectoryName(uint32_t index, void* des, uint32_t size)
{
	error result;

	if(index >= mDirectoryCount)
		return error::INDEX_OVER;

	mCurrentFileIndex = 0xFFFFFFFF;

	if(index < mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != error::ERROR_NONE)
			return result;
		
		if(mFileSystem->isDirectory() == false)
			result = mFileSystem->moveToNextDirectory();
		if(result != error::ERROR_NONE)
			return result;

		mCurrentDirectoryIndex = 0;
	}

	while(index != mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToNextDirectory();
		if(result != error::ERROR_NONE)
			return result;

		mCurrentDirectoryIndex++;
	}
	
	return mFileSystem->getName(des, size);
}

error Directory::enterDirectory(uint32_t index)
{
	error result;

	if(index >= mDirectoryCount)
		return error::INDEX_OVER;

	mCurrentFileIndex = 0xFFFFFFFF;

	if(index < mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToStart();
		if(result != error::ERROR_NONE)
			return result;
		
		if(mFileSystem->isDirectory() == false)
			result = mFileSystem->moveToNextDirectory();
		if(result != error::ERROR_NONE)
			return result;

		mCurrentDirectoryIndex = 0;
	}

	while(index != mCurrentDirectoryIndex)
	{
		result = mFileSystem->moveToNextDirectory();
		if(result != error::ERROR_NONE)
		{
			return result;
		}

		mCurrentDirectoryIndex++;
	}
	
	result = mFileSystem->enterDirectory();
	if(result != error::ERROR_NONE)
		return result;
	
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	return error::ERROR_NONE;
}

error Directory::enterDirectory(const char *utfName)
{
	error result;

	mCurrentFileIndex = 0xFFFFFFFF;

	result = mFileSystem->moveToStart();
	if(result != error::ERROR_NONE)
		return result;
	
	if(mFileSystem->isDirectory() == false)
		result = mFileSystem->moveToNextDirectory();
	if(result != error::ERROR_NONE)
		return result;

	mCurrentDirectoryIndex = 0;

	while(mCurrentDirectoryIndex < mDirectoryCount)
	{
		mCurrentDirectoryIndex++;

		if(mFileSystem->compareName(utfName) == false)
		{
			result = mFileSystem->enterDirectory();
			if(result != error::ERROR_NONE)
				return result;

			mDirectoryCount = mFileSystem->getDirectoryCount();
			mFileCount = mFileSystem->getFileCount();

			return error::ERROR_NONE;
		}

		result = mFileSystem->moveToNextDirectory();
		if(result != error::ERROR_NONE)
			return result;
	}
	
	return error::NOT_EXIST_NAME;
}

error Directory::returnDirectory(void)
{
	error result;

	result = mFileSystem->returnDirectory();
	if(result != error::ERROR_NONE)
		return result;
	
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	
	return error::ERROR_NONE;
}

error Directory::makeDirectory(const char *name)
{
	error result;

	result = mFileSystem->makeDirectory(name);
	if(result != error::ERROR_NONE)
		return result;
	
	mDirectoryCount = mFileSystem->getDirectoryCount();
	mFileCount = mFileSystem->getFileCount();

	mCurrentDirectoryIndex = 0xFFFFFFFF;
	mCurrentFileIndex = 0xFFFFFFFF;
	
	return error::ERROR_NONE;
}

uint32_t Directory::getCurrentDirectoryCluster(void)
{
	return mFileSystem->getCurrentDirectoryCluster();
}

