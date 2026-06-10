/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FILE__H_
#define YSS_FILE__H_

/**
 * @file File.h
 * @brief File wrapper class for file operations using FileSystem.
 */

#include <yss/FileSystem.h>

/**
 * @brief Provides a high-level file interface on top of FileSystem.
 *
 * File manages opening, reading, writing, and navigating files within a
 * file system implementation.
 */
class File
{
public:
	enum
	{
		WRITE_ONLY = 0,
		READ_ONLY,
	};

	/**
	 * @brief Construct a new File object.
	 *
	 * @param fileSystem Reference to the underlying file system.
	 */
	File(FileSystem &fileSystem);

	/**
	 * @brief Construct a new File object.
	 *
	 * @param fileSystem Pointer to the underlying file system.
	 */
	File(FileSystem *fileSystem);

	/**
	 * @brief Initialize the file object.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t initialize(void);

	/**
	 * @brief Open a file by name.
	 *
	 * @param fileName Name of the file to open.
	 * @param mode Open mode using WRITE_ONLY or READ_ONLY.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t open(const char *fileName, uint8_t mode);

	/**
	 * @brief Open a file by starting cluster.
	 *
	 * @param cluster Starting cluster of the file.
	 * @param mode Open mode using WRITE_ONLY or READ_ONLY.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t open(int32_t cluster, uint8_t mode);

	/**
	 * @brief Set the current file path by cluster.
	 *
	 * @param cluster Cluster number to set as the current path.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t setPath(uint32_t cluster);

	/**
	 * @brief Read data from the open file.
	 *
	 * @param des Destination buffer.
	 * @param size Number of bytes to read.
	 * @return uint32_t Number of bytes actually read.
	 */
	uint32_t read(void *des, uint32_t size);

	/**
	 * @brief Write data to the open file.
	 *
	 * @param src Source buffer containing data to write.
	 * @param size Number of bytes to write.
	 * @return uint32_t Number of bytes actually written.
	 */
	uint32_t write(void *src, uint32_t size);

	/**
	 * @brief Get the size of the currently open file.
	 *
	 * @return uint32_t File size in bytes.
	 */
	uint32_t getSize(void);

	/**
	 * @brief Move the file cursor to the beginning of the file.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToStart(void);

	/**
	 * @brief Move the file cursor to the end of the file.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveToEnd(void);

	/**
	 * @brief Move the file cursor to a specific position.
	 *
	 * @param position Byte position within the file.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t moveTo(uint32_t position);

	/**
	 * @brief Create a new file in the current directory.
	 *
	 * @param fileName Name of the file to create.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t makeFile(const char *fileName);

	/**
	 * @brief Close the currently open file.
	 *
	 * @return error_t ERROR_NONE on success.
	 */
	error_t close(void);

private:
	FileSystem *mFileSystem;
	bool mOpenFlag;
	uint8_t *mBuffer, mOpenMode;
	uint32_t mFileSize, mBufferCount;

	/**
	 * @brief Validate a file name string.
	 *
	 * @param fileName File name to validate.
	 * @return true when valid.
	 * @return false otherwise.
	 */
	bool checkFileName(const char *fileName);

	/**
	 * @brief Extract one component from a path string.
	 *
	 * @param des Destination buffer for the component.
	 * @param src Pointer to the source path string pointer.
	 * @return true when a component was extracted.
	 */
	bool bringOneName(char *des, const char **src);

	/**
	 * @brief Enter a directory by name.
	 *
	 * @param name Directory name.
	 * @return error_t ERROR_NONE on success.
	 */
	error_t enterDirectory(const char *name);

	/**
	 * @brief Find a file by name in the current directory.
	 *
	 * @param name File name to find.
	 * @return error_t ERROR_NONE if found.
	 */
	error_t findFile(const char *name);
};

#endif