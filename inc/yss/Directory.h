/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DIRECTORY__H_
#define YSS_DIRECTORY__H_

#include <yss/FileSystem.h>

/**
 * @file Directory.h
 * @brief Directory helper class header file.
 */

/**
 * @class Directory
 * @brief High-level helper class to manage and navigate directories on a FileSystem.
 *
 * @details
 * This class provides convenient methods to list files/directories, enter/return directories,
 * retrieve item names, and create new directories. It caches directory and file counts to
 * optimize traversal performance.
 */
class Directory
{
public :
	/**
	 * @brief Constructor for Directory using a reference to a FileSystem.
	 *
	 * @param[in] fileSystem Reference to the target FileSystem.
	 */
	Directory(FileSystem &fileSystem);

	/**
	 * @brief Constructor for Directory using a pointer to a FileSystem.
	 *
	 * @param[in] fileSystem Pointer to the target FileSystem.
	 */
	Directory(FileSystem *fileSystem);

	/**
	 * @brief Initializes the Directory manager and caches file/directory counts.
	 *
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t initialize(void);

	/**
	 * @brief Gets the number of subdirectories in the current directory.
	 *
	 * @return uint32_t Number of directories.
	 */
	uint32_t getDirectoryCount(void);

	/**
	 * @brief Gets the number of files in the current directory.
	 *
	 * @return uint32_t Number of files.
	 */
	uint32_t getFileCount(void);

	/**
	 * @brief Gets the cluster number of the current directory.
	 *
	 * @return uint32_t Current directory cluster number.
	 */
	uint32_t getCurrentDirectoryCluster(void);

	/**
	 * @brief Retrieves the file name matching the specified index.
	 *
	 * @param[in] index The index of the file in the current directory (0 to getFileCount() - 1).
	 * @param[out] des Pointer to the destination buffer to copy the file name.
	 * @param[in] size The size of the destination buffer.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t getFileName(uint32_t index, void* des, uint32_t size);

	/**
	 * @brief Retrieves the directory name matching the specified index.
	 *
	 * @param[in] index The index of the directory in the current directory (0 to getDirectoryCount() - 1).
	 * @param[out] des Pointer to the destination buffer to copy the directory name.
	 * @param[in] size The size of the destination buffer.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t getDirectoryName(uint32_t index, void* des, uint32_t size);

	/**
	 * @brief Enters the directory at the specified index.
	 *
	 * @param[in] index Index of the directory to enter.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t enterDirectory(uint32_t index);

	/**
	 * @brief Enters the directory with the matching UTF-8 name.
	 *
	 * @param[in] utfName Null-terminated UTF-8 string containing the directory name.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t enterDirectory(const char *utfName);

	/**
	 * @brief Returns to the parent directory.
	 *
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t returnDirectory(void);

	/**
	 * @brief Creates a new directory in the current directory.
	 *
	 * @param[in] name Null-terminated string containing the name of the directory to create.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t makeDirectory(const char *name);

private :
	FileSystem *mFileSystem;
	uint32_t mFileCount, mDirectoryCount, mCurrentFileIndex, mCurrentDirectoryIndex;
};

#endif