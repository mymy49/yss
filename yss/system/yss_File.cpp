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

#include <yss/File.h>
#include <string.h>

File::File(sac::FileSystem &fileSystem)
{
	mFileSystem = &fileSystem;
	mOpenFlag = false;
	mBuffer = (unsigned char*)mFileSystem->getSectorBuffer();
	mFileSize = 0;
}

File::File(sac::FileSystem *fileSystem)
{
	mFileSystem = fileSystem;
	mOpenFlag = false;
	mBuffer = (unsigned char*)mFileSystem->getSectorBuffer();
	mFileSize = 0;
}

error File::open(const char *fileName, unsigned char mode)
{
	if(mOpenFlag)
		return Error::BUSY;

	if(checkFileName(fileName) == false)
		return Error::WRONG_FILE_NAME;
	
	error result;
	char name[256];
	const char *src = fileName;
	
	if(*src != '/')
		return Error::WRONG_DIRECTORY_PATH;
	
	src++;

	while(*src != 0)
	{
		if(bringOneName(name, &src))
		{
			result = enterDirectory(name);
			if(result != Error::NONE)
				return result;

			if(*src != '/')
				break;;
		}
		else
		{
			result = findFile(name);
			if(result != Error::NONE)
				return result;
			
			result = mFileSystem->open();
			if(result == Error::NONE)
				mOpenFlag = true;
			mFileSize = mFileSystem->getFileSize();
			mReadCount = 0;
			return result;
		}
		
		src++;
	}

	return Error::INDEX_OVER;
}

bool File::checkFileName(const char *fileName)
{
	while(*fileName)
	{
		if(	*fileName == '\\' ||
			*fileName == '?' ||
			*fileName == '%' ||
			*fileName == '*' ||
			*fileName == ';' ||
			*fileName == '|' ||
			*fileName == '"' ||
			*fileName == '<' ||
			*fileName == '>'
		)
			return false;
		
		fileName++;
	}

	return true;
}

bool File::bringOneName(char *des, const char **src)
{
	while(**src != 0 && **src != '/')
	{
		*des++ = *(*src)++;
	}
	
	*des++ = 0;
	return *(*src) == '/';
}

error File::enterDirectory(const char *name)
{
	error result;

	result = mFileSystem->moveToStart();
	if(result != Error::NONE)
		return result;
	
	if(mFileSystem->isDirectory() == false)
		result = mFileSystem->moveToNextDirectory();
	if(result != Error::NONE)
		return result;

	while(1)
	{
		if(mFileSystem->comapreName(name) == false)
		{
			result = mFileSystem->enterDirectory();
			if(result != Error::NONE)
				return result;

			return Error::NONE;
		}

		result = mFileSystem->moveToNextDirectory();
		if(result != Error::NONE)
			return result;
	}
	
	return Error::NOT_EXIST_NAME;
}

error File::findFile(const char *name)
{
	error result;

	result = mFileSystem->moveToStart();
	if(result != Error::NONE)
		return result;
	
	if(mFileSystem->isFile() == false)
		result = mFileSystem->moveToNextFile();
	if(result != Error::NONE)
		return result;

	while(1)
	{
		if(mFileSystem->comapreName(name) == false)
			return Error::NONE;

		result = mFileSystem->moveToNextFile();
		if(result != Error::NONE)
			return result;
	}
	
	return Error::NOT_EXIST_NAME;
}

unsigned int File::read(void *des, unsigned int size)
{
	if(!mOpenFlag)
		return 0;
	
	char *src, *cDes = (char*)des;
	unsigned int tmp, len = 0;
	error result;

	while(size)
	{
		if(mReadCount > 0)
		{
			src = (char*)&mBuffer[512 - mReadCount];

			if(size >= mReadCount)
			{
				tmp = mReadCount;
				size -= tmp;
				mReadCount = 0;
			}
			else
			{
				tmp = size;
				mReadCount -= size;
				size = 0;
			}

			len += tmp;
			memcpy(cDes, src, tmp);
			cDes += tmp;

			if(size == 0)
				return len;
		}

		result = mFileSystem->read(mBuffer);
		mReadCount = 512;
		if(result == Error::INDEX_OVER)
			return len;
		else if(result != Error::NONE)
			return 0;
	}
	
	return len;
}

unsigned int File::getSize(void)
{
	return mFileSize;
}