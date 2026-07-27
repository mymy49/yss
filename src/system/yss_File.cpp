/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file yss_File.cpp
 * @brief High-level File interface implementation for Yss file systems.
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

/**
 * @brief Initializes the file system when a new storage medium (e.g. SD card) is mounted.
 *
 * @details
 * Reads the basic partition/medium info and locates the root directory.
 * Must be called before performing file operations upon mounting a new SD memory.
 *
 * @return error_t Error code.
 */
error_t File::initialize(void)
{
	return mFileSystem->initialize();
}

/**
 * @brief Opens a file with the specified access mode.
 *
 * @details
 * If the path starts with '/', the search begins at the root directory.
 * If not, the file is searched relative to the current working directory.
 * Use setPath() to establish the current directory context, or moveToRoot() to return to root.
 *
 * @param[in] fileName The name (or path) of the file to open. Must be UTF-8 encoded.
 * @param[in] mode The access mode to open the file (e.g. READ_ONLY, WRITE_ONLY).
 * @return error_t Error code defined in /inc/yss/error.h.
 */
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

/**
 * @brief Sets the current directory path using a cluster number.
 *
 * @details
 * Uses a cluster index (such as that returned by Directory::getCurrentDirectoryCluster())
 * to configure the current directory path context for relative file operations.
 *
 * @param[in] cluster The starting cluster number assigned to the target directory.
 * @return error_t Error code defined in /inc/yss/error.h.
 */
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
