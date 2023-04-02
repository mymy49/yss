////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_FAT32_DIRECTORY_ENTRY__H_
#define YSS_FAT32_DIRECTORY_ENTRY__H_

#include "Fat32Cluster.h"

class Fat32DirectoryEntry
{
	struct LongFileName
	{
		int8_t order;
		char name1[10];
		int8_t attr;
		int8_t type;
		int8_t checksum;
		char name2[12];
		int8_t zero[2];
		char name3[4];
	};

	struct DirectoryEntry
	{
		char name[8];
		int8_t extention[3];
		int8_t attr;
		int8_t reserved[2];
		uint16_t createdTime;
		uint16_t createdDate;
		uint16_t lastAccessedDate;
		uint16_t startingClusterHigh;
		uint16_t lastModifiedTime;
		uint16_t lastModifiedDate;
		uint16_t startingClusterLow;
		uint32_t fileSize;
	};
	
	enum
	{
		MAX_LFN = 20
	};

	Fat32Cluster *mCluster;
	DirectoryEntry *mEntryBuffer;
	uint16_t mSectorSize;
	int16_t mIndex;
	uint8_t mCurrentAttribute, mLfnCount;
	LongFileName mLfn[MAX_LFN];

	error insertEntry(uint8_t lfnLen, DirectoryEntry *src);
	uint32_t translateUtf16ToUtf8(const char *utf16);
	uint32_t translateMixedUtf16ToUtf8(const char *utf16);
	uint16_t translateUtf8ToUtf16(const char *utf8);
	int32_t  strlen(const char *src);
	void setShortName(void *des, const char *src);
	uint8_t calculateChecksum(DirectoryEntry *src);
	void copyStringUtf8ToLfnBuffer(const char *utf8, int32_t len);
	DirectoryEntry getCurrentDirectoryEntry(void);

	error prepareInsert(uint32_t &cluster, DirectoryEntry &sfn, uint8_t attribute, const char *name, uint32_t len);

public:
	Fat32DirectoryEntry(void);
	void initialize(Fat32Cluster &cluster, void* sectorBuffer);
	error moveToRoot(void);
	error moveToStart(void);
	error moveToNext(void);
	error moveToEnd(void);
	error setRootCluster(uint32_t cluster);
	error setCluster(uint32_t cluster);
	error append(void);
	uint32_t getRootCluster(void);
	
	error makeDirectory(const char *name);
	error makeFile(const char *name);

	error getTargetName(void *des, uint32_t size);
	uint8_t getTargetAttribute(void);
	uint32_t getTargetCluster(void);
	uint32_t getTargetFileSize(void);
	void setTargetFileSize(uint32_t size);
	bool comapreTargetName(const char *utf8);
	error saveEntry(void);
};

#endif
