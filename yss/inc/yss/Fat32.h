////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 소스 코드 기여는 기증으로 받아들입니다.
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

#ifndef YSS_FAT32__H_
#define YSS_FAT32__H_

#include <sac/FileSystem.h>
#include <yss/error.h>
#include "Fat32Cluster.h"
#include "Fat32DirectoryEntry.h"

class Fat32 : public sac::FileSystem
{
	struct LongFileName
	{
		char order;
		char name1[10];
		char attr;
		char type;
		char checksum;
		char name2[12];
		char zero[2];
		char name3[4];
	};

	enum
	{
		MAX_LFN = 20
	};

	unsigned int mCurrentFileCluster;

	bool mAbleFlag, mFileOpen;
	unsigned char mSectorPerCluster, mNumFATs;
	unsigned short mFsInfoSector;
	unsigned int mNumOfFreeClusters, mNextFreeCluster;
	unsigned int mFatSize, mRootCluster;
	unsigned int mBufferedFatSector;
	
	Fat32Cluster mCluster;
	Fat32DirectoryEntry mDirectoryEntry;

	error initReadCluster(unsigned int cluster, void *des);
	error readNextBlock(void *des);
	unsigned int getCount(unsigned char *type, unsigned char typeCount);
	error getName(unsigned char *type, unsigned char typeCount, unsigned int index, void* des, unsigned int size);
	error moveToNextItem(unsigned char *type, unsigned char typeCount);

public :
	// 최대 사용 가능한 파일 이름 숫자 maxLfnLength x 13
	Fat32(sac::MassStorage &storage);
	~Fat32(void);
	error init(void);

	unsigned int getDirectoryCount(void);
	unsigned int getFileCount(void);

	error getName(void* des, unsigned int size);
	error enterDirectory(void);
	error returnDirectory(void);
	error moveToHome(void);
	error moveToNextDirectory(void);
	error moveToNextFile(void);

	error makeDirectory(const char *name);
};

#endif
