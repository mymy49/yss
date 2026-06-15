/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/File.h>
#include <string.h>

File::File(FileSystem &fileSystem)
{
	mFileSystem = &fileSystem;
	mOpenFlag = false;
	mBuffer = (uint8_t*)mFileSystem->getSectorBuffer();
	mFileSize = 0;
	mOpenMode = READ_ONLY;
	mBufferCount = 0;
}

File::File(FileSystem *fileSystem)
{
	mFileSystem = fileSystem;
	mOpenFlag = false;
	mBuffer = (uint8_t*)mFileSystem->getSectorBuffer();
	mFileSize = 0;
	mOpenMode = READ_ONLY;
	mBufferCount = 0;
}

// 새로운 SD 메모리가 장착되면 init()을 먼저 호출해줘야 한다.
// SD 메모리의 기본 정보를 읽어오고 루트 디렉토리를 찾는다.
error_t File::initialize(void)
{
	return mFileSystem->initialize();
}

// 파일을 오픈하는 함수이다.
// 파일 저장소의 루트 디렉토리는 파일명의 첫 글짜에 '/' 문자를 사용한다.
// 루트 디렉토리 지정이 없을 경우 현재 디렉토리를 기준의 탐색 한다.
// 현재 디렉토리는 setPath() 함수를 사용한다.
// 현재 디렉토리를 루트로 옮기기 위해서 moveToRoot() 함수 호출이 필요하다.
//
// 반환형 error_t
//		/inc/yss/error_t.h에 정의된 에러를 반환한다.
//
// const int8_t *fileName
//		오픈할 파일명을 지정한다. utf8 엔코딩을 사용한다.
//
// uint8_t mode
//		오픈할 파일의 모드를 설정한다. 읽기 또는 쓰기 등의 설정을 한다.
//		사용 가능한 설정은 File class에 정의되어 있다.
error_t File::open(const char *fileName, uint8_t mode)
{
	// Prevent opening a file while another file is already open.
	if(mOpenFlag)
		return error_t::BUSY;

	// Set the requested access mode and reset state for write mode.
	switch(mode)
	{
	case WRITE_ONLY :
		mFileSize = 0;
		break;
	case READ_ONLY :
		break;
	default :
		return error_t::UNSUPPORTED_MODE;
	} 

	const char *src = fileName;
	mOpenMode = mode;

	if(checkFileName(fileName) == false)
		return error_t::WRONG_FILE_NAME;

	error_t result;
	thread::protect();
	char *name = new char[256];
	
	// If the path begins with '/', start from the root directory.
	if(*src == '/')
	{
		mFileSystem->moveToRootDirectory();
		src++;
	}

	// Parse each path segment and traverse directories until the final element.
	while(*src != 0)
	{
		if(bringOneName(name, &src))
		{
			result = enterDirectory(name);
			if(result == error_t::INDEX_OVER)
			{
				return error_t::WRONG_DIRECTORY_NAME;
			}
			else if(result != error_t::ERROR_NONE)
			{
				goto error_handler;
			}
			if(*src != '/')
				break;
		}
		else
		{
			result = findFile(name);
			
			// If the final component is a file, open it in the requested mode.
			switch(mOpenMode)
			{
			case READ_ONLY :
				if(result != error_t::ERROR_NONE)
					goto error_handler;

				result = mFileSystem->open();
				if(result == error_t::ERROR_NONE)
					mOpenFlag = true;
				mFileSize = mFileSystem->getFileSize();
				mBufferCount = 0;
				break;

			case WRITE_ONLY :
				if(result == error_t::ERROR_NONE)
				{
					// File already exists: open it for writing.
					result = mFileSystem->open();
					if(result == error_t::ERROR_NONE)
						mOpenFlag = true;
				}
				else if(result == error_t::NOT_EXIST_NAME)
				{
					// Create a new file if it does not already exist.
					result = mFileSystem->makeFile(name);
					if(result != error_t::ERROR_NONE)
						goto error_handler;

					result = findFile(name);
					if(result != error_t::ERROR_NONE)
						goto error_handler;

					result = mFileSystem->open();
					if(result == error_t::ERROR_NONE)
						mOpenFlag = true;
				}
				mBufferCount = 0;
				break;
			}
			
			// Normal completion shares cleanup path with the error handler.
			goto error_handler;
		}
		
		src++;
	}

	result = error_t::INDEX_OVER;

error_handler:
	thread::unprotect();
	return result;
}

// Directory class의 getCurrentDirectoryCluster() 함수로부터 현재 디렉토리 경로에 해당하는 cluster 번호를 
// 사용해 현재 경로를 지정하는 함수이다.
//
// 반환형 error_t
//		/inc/yss/error_t.h에 정의된 에러를 반환한다.
//
// uint32_t cluster
//		디렉토리에 할당된 clsuter 번호를 지정한다.
error_t File::setPath(uint32_t cluster)
{
	return mFileSystem->moveToCluster(cluster);
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

error_t File::enterDirectory(const char *name)
{
	error_t result;

	if(mOpenFlag)
		return error_t::BUSY;

	result = mFileSystem->moveToStart();
	if(result != error_t::ERROR_NONE)
		return result;
	
	if(mFileSystem->isDirectory() == false)
		result = mFileSystem->moveToNextDirectory();
	if(result != error_t::ERROR_NONE)
		return result;

	while(1)
	{
		if(mFileSystem->compareName(name) == false)
		{
			result = mFileSystem->enterDirectory();
			if(result != error_t::ERROR_NONE)
				return result;

			return error_t::ERROR_NONE;
		}

		result = mFileSystem->moveToNextDirectory();
		if(result != error_t::ERROR_NONE)
			return result;
	}
	
	return error_t::NOT_EXIST_NAME;
}

error_t File::findFile(const char *name)
{
	error_t result;

	result = mFileSystem->moveToStart();
	if(result != error_t::ERROR_NONE)
		return result;
	
	if(mFileSystem->isFile() == false)
		result = mFileSystem->moveToNextFile();
	if(result == error_t::INDEX_OVER)
		return error_t::NOT_EXIST_NAME;
	else if(result != error_t::ERROR_NONE)
		return result;

	while(1)
	{
		if(mFileSystem->compareName(name) == false)
			return error_t::ERROR_NONE;

		result = mFileSystem->moveToNextFile();
		if(result == error_t::INDEX_OVER)
			return error_t::NOT_EXIST_NAME;
		else if(result != error_t::ERROR_NONE)
			return result;
	}
	
	return error_t::NOT_EXIST_NAME;
}

uint32_t File::read(void *des, uint32_t size)
{
	if(!mOpenFlag)
		return 0;
	
	// Allow only read mode on this method.
	switch(mOpenMode)
	{
	case READ_ONLY :
		break;
	default :
		return 0;
	}

	int8_t *src, *cDes = (int8_t*)des;
	uint32_t tmp, len = 0;
	error_t result;

	while(size)
	{
		// First consume any leftover bytes from the internal sector buffer.
		if(mBufferCount > 0)
		{
			src = (int8_t*)&mBuffer[512 - mBufferCount];

			if(size >= mBufferCount)
			{
				tmp = mBufferCount;
				size -= tmp;
				mBufferCount = 0;
			}
			else
			{
				tmp = size;
				mBufferCount -= size;
				size = 0;
			}

			len += tmp;
			memcpy(cDes, src, tmp);
			cDes += tmp;
		}
		
		if(size >= 512)
		{
			// Read whole sectors directly into the destination buffer.
			result = mFileSystem->read(cDes);
			cDes += 512;
			size -= 512;
			len += 512;
		}
		else
		{
			// Read the next sector into the internal buffer for partial consumption.
			result = mFileSystem->read(mBuffer);
			mBufferCount = 512;
		}

		if(size == 0 || result == error_t::INDEX_OVER)
			return len;

		if(result == error_t::NO_DATA)
			;
		else if(result != error_t::ERROR_NONE)
			return len;
	}
	
	return len;
}

uint32_t File::write(void *src, uint32_t size)
{
	if(!mOpenFlag)
		return 0;
	
	// Allow only write mode on this method.
	switch(mOpenMode)
	{
	case WRITE_ONLY :
		break;
	default :
		return 0;
	}

	int8_t *des, *cSrc = (int8_t*)src;
	uint32_t tmp, len = 0;
	error_t result;

	while(size)
	{
		des = (int8_t*)&mBuffer[mBufferCount];

		if(size >= (512-mBufferCount))
		{
			// Fill the rest of the current sector buffer and flush it.
			tmp = (512-mBufferCount);
			size -= tmp;
			mBufferCount = 512;
		}
		else
		{
			// Only a partial sector remains; leave it buffered until later.
			tmp = size;
			mBufferCount += size;
			size = 0;
		}

		len += tmp;
		memcpy(des, cSrc, tmp);
		cSrc += tmp;
		mFileSize += tmp;
		
		if(mBufferCount >= 512)
		{
			result = mFileSystem->write(mBuffer);
			if(result != error_t::ERROR_NONE)
				return 0;
			mBufferCount = 0;
		}
	}
	
	return len;
}

uint32_t File::getSize(void)
{
	if(!mOpenFlag)
		return error_t::FILE_NOT_OPENED;

	return mFileSize;
}

error_t File::moveToStart(void)
{
	error_t result;

	if(!mOpenFlag)
		return error_t::FILE_NOT_OPENED;
	
	result = mFileSystem->moveToFileStart();
	mBufferCount = 0;

	return result;
}

error_t File::moveToEnd(void)
{
	uint32_t movingSector = mFileSize / 512;
	error_t result;

	if(!mOpenFlag)
		return error_t::FILE_NOT_OPENED;

	// Reset position, then advance to the final sector for the current file size.
	moveToStart();
	
	for(uint32_t i=0;i<movingSector;i++)
	{
		result = mFileSystem->moveToNextSector();
		if(result != error_t::ERROR_NONE)
			return result;
	}

	// Track remaining bytes within the last sector.
	mBufferCount = mFileSize % 512;

	return error_t::ERROR_NONE;
}

error_t File::moveTo(uint32_t position)
{
	error_t result;
	uint32_t movingSector;

	if(!mOpenFlag)
		return error_t::FILE_NOT_OPENED;

	if(position > mFileSize)
		return moveToEnd();
	
	// Move to the sector that contains the requested byte position.
	movingSector = position / 512;

	moveToStart();
	
	for(uint32_t i=0;i<movingSector;i++)
	{
		result = mFileSystem->moveToNextSector();
		if(result != error_t::ERROR_NONE)
			return result;
	}

	// Read the current sector into the buffer and position within it.
	result = mFileSystem->read(mBuffer);
	mBufferCount = 512 - position % 512;

	return error_t::ERROR_NONE;
}

error_t File::makeFile(const char *fileName)
{
	error_t result;

	if(mOpenFlag)
		return error_t::BUSY;

	result = findFile(fileName);
	if(result == error_t::NOT_EXIST_NAME)
	{
		result = mFileSystem->makeFile(fileName);
		if(result != error_t::ERROR_NONE)
			return result;
	}

	return error_t::ERROR_NONE;
}

error_t File::close(void)
{
	if(!mOpenFlag)
		return error_t::FILE_NOT_OPENED;

	error_t result;
	mOpenFlag = false;

	// Finalize file I/O depending on the open mode.
	switch(mOpenMode)
	{
	case WRITE_ONLY :
		if(mBufferCount)
		{
			// Flush any remaining buffered data before closing.
			result = mFileSystem->write(mBuffer);
			if(result != error_t::ERROR_NONE)
				return result;
			mBufferCount = 0;
			result = mFileSystem->close(mFileSize);
			if(result != error_t::ERROR_NONE)
				return result;
		}
		break;
	case READ_ONLY :
		mFileSystem->close();
		break;
	default :
		return error_t::UNSUPPORTED_MODE;
	}

	return error_t::ERROR_NONE;
}
