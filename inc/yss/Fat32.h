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

#ifndef YSS_FAT32__H_
#define YSS_FAT32__H_

#include <sac/FileSystem.h>
#include <yss/error.h>
#include "Fat32Cluster.h"
#include "Fat32DirectoryEntry.h"
#include <yss/Mutex.h>

class Fat32 : public sac::FileSystem, public Mutex
{
	struct LongFileName
	{
		int8_t order;
		int8_t name1[10];
		int8_t attr;
		int8_t type;
		int8_t checksum;
		int8_t name2[12];
		int8_t zero[2];
		int8_t name3[4];
	};

	enum
	{
		MAX_LFN = 20
	};

	uint32_t mCurrentFileCluster;

	bool mAbleFlag, mFileOpen;
	uint8_t mSectorPerCluster, mNumFATs;
	uint16_t mFsInfoSector;
	uint32_t mNumOfFreeClusters, mNextFreeCluster;
	uint32_t mFatSize, mRootCluster;
	uint32_t mBufferedFatSector, mFileCluster;
	
	Fat32Cluster *mCluster;
	Fat32DirectoryEntry *mDirectoryEntry;

	error initReadCluster(uint32_t cluster, void *des);
	error readNextBlock(void *des);
	uint32_t getCount(uint8_t *type, uint8_t typeCount);
	error moveToNextItem(uint8_t *type, uint8_t typeCount);

public :
	// 최대 사용 가능한 파일 이름 숫자 maxLfnLength x 13
	Fat32(sac::MassStorage &storage);
	~Fat32(void);
	error initialize(void);
	error getName(void* des, uint32_t size);
	error enterDirectory(void);
	error returnDirectory(void);
	error moveToRootDirectory(void);
	error moveToCluster(uint32_t cluster);
	error moveToStart(void);
	error moveToNextDirectory(void);
	error moveToNextFile(void);
	error makeDirectory(const char *name);
	error makeFile(const char *name);
	error open(void);
	error open(const char *name);
	error read(void *des);
	error write(void *src);
	error moveToNextSector(void);
	error close(uint32_t fileSize);
	error close(void);
	error moveToFileStart(void);

	bool compareName(const char *utf8);
	bool isDirectory(void);
	bool isFile(void);
	bool isHaveNextCluster(void);
	int32_t  getDirectoryCount(void);
	int32_t  getFileCount(void);
	uint32_t getFileSize(void);
	uint32_t getCurrentDirectoryCluster(void);

};

#endif

