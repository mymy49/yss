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

#include <yss/Fat32DirectoryEntry.h>
#include <yss/error.h>
#include <string.h>
#include <__cross_studio_io.h>

#define DELETED						0x00
#define READ_ONLY					0x01
#define HIDDEN_FILE					0x02
#define SYSEM_FILE					0x04
#define LONG_FILE_NAME				0x0F
#define DIRECTORY					0x10
#define SYSTEM_VOLUME_INFO			0x16
#define ARCHIVE						0x20

Fat32DirectoryEntry::Fat32DirectoryEntry(void)
{
	mIndex = 0xFFFF;
	mCluster = 0;
	mSectorSize = 0;
	mEntryBuffer = 0;
}

void Fat32DirectoryEntry::init(Fat32Cluster &cluster, void* sectorBuffer)
{
	mCluster = &cluster;
	mEntryBuffer = (DirectoryEntry*)sectorBuffer;
	mSectorSize = cluster.getSectorSize();

	moveToRoot();
}

error Fat32DirectoryEntry::moveToNext(void)
{
	error result;
	DirectoryEntry *entry;
	LongFileName *lfn;
	unsigned char num;
	
	mLfnCount = 0;

	while(true)
	{
		if(mIndex < 15)
			mIndex++;
		else
		{
			result = mCluster->increaseDataSectorIndex();
			if(result != Error::NONE)
				return result;

			result = mCluster->readDataSector(mEntryBuffer);
			if(result != Error::NONE)
				return result;

			mIndex = 0;
		}

		entry = &mEntryBuffer[mIndex];

		if(entry->attr == LONG_FILE_NAME)
		{
			lfn = (LongFileName*)entry;
			if(lfn->order & 0x40)
			{
				mLfnCount = lfn->order & 0x3F;
			}
			
			if(mLfnCount)
			{
				num = lfn->order & 0x3F;
				memcpy(&mLfn[num-1], lfn, sizeof(LongFileName));
			}
		}
		else if(entry->name[0] == 0xE5)
		{
			// 삭제된 파일이라 다시 탐색 시작
			mLfnCount = 0;
		}
		else if(entry->name[0] == 0x00)
		{
			return Error::INDEX_OVER;
		}
		else
		{
			return Error::NONE;
		}
	}
}

error Fat32DirectoryEntry::moveToRoot(void)
{
	error result;

	result = mCluster->moveToRoot();
	if(result != Error::NONE)
		return result;
	
	result = mCluster->readDataSector(mEntryBuffer);
	if(result != Error::NONE)
		return result;

	mIndex = 0xFFFF;
	
	return moveToNext();
}

error Fat32DirectoryEntry::moveToStart(void)
{
	error result;

	result = mCluster->moveToStart();
	if(result != Error::NONE)
		return result;
	
	result = mCluster->readDataSector(mEntryBuffer);
	if(result != Error::NONE)
		return result;

	mIndex = 0xFFFF;
	
	return moveToNext();
}

error Fat32DirectoryEntry::moveToEnd(void)
{
	error result;
	DirectoryEntry *entry;
	
	while(true)
	{
		if(mIndex < 15)
			mIndex++;
		else
		{
			result = mCluster->readDataSector(mEntryBuffer);
			if(result != Error::NONE)
				return result;

			result = mCluster->increaseDataSectorIndex();
			if(result != Error::NONE)
				return result;

			mIndex = 0;
		}

		entry = &mEntryBuffer[mIndex];

		if(entry->name[0] == 0x00)
		{
			return Error::NONE;
		}
	}
}

Fat32DirectoryEntry::DirectoryEntry Fat32DirectoryEntry::getCurrentDirectoryEntry(void)
{
	return mEntryBuffer[mIndex];
}

error Fat32DirectoryEntry::setRootCluster(unsigned int cluster)
{
	mCluster->setRootCluster(cluster);
	return moveToRoot();
}

error Fat32DirectoryEntry::setCluster(unsigned int cluster)
{
	mCluster->setCluster(cluster);
	return moveToStart();
}

unsigned int Fat32DirectoryEntry::getRootCluster(void)
{
	return mCluster->getRootCluster();
}

unsigned char Fat32DirectoryEntry::getTargetAttribute(void)
{
	return mEntryBuffer[mIndex].attr;
}

unsigned int Fat32DirectoryEntry::translateUtf16ToUtf8(const char *utf16)
{
	unsigned int utf8;
	unsigned short *buf = (unsigned short*)utf16;

	if(*buf <= 0x7F)
	{
		utf8 = *buf;
	}
	else
	{
		utf8 = 0xe08080 | ((*buf << 4) & 0x0F0000);
		utf8 |= ((*buf << 2) & 0x003F00) | (*buf & 0x00003F);
	}

	return utf8;
}

unsigned int Fat32DirectoryEntry::translateMixedUtf16ToUtf8(const char *utf16)
{
	unsigned int utf8;
	unsigned char *buf = (unsigned char*)utf16;
	
	if(*buf <= 0x7F)
		utf8 = *buf;
	else
	{
		utf8 = 0xe08080 | ((*(unsigned short*)buf << 4) & 0x0F0000);
		utf8 |= ((*(unsigned short*)buf << 2) & 0x003F00) | (*(unsigned short*)buf & 0x00003F);
	}

	return utf8;
}

unsigned short Fat32DirectoryEntry::translateUtf8ToUtf16(const char *utf8)
{
	unsigned short utf16;

	if(*utf8 <= 0x7F)
		utf16 = *utf8;
	else
		utf16 = (utf8[0] & 0x0F) << 12 | (utf8[1] & 0x3F) << 6 | (utf8[2] & 0x3F);

	return utf16;
}

error Fat32DirectoryEntry::getTargetName(void *des, unsigned int size)
{
	char *cdes = (char*)des, *csrc;
	unsigned short used;
	unsigned int utf8;

	// 긴 파일 이름인지 점검
	if(mLfnCount == 0)
		goto extractShortName;

	// 파일 이름 추출
	used = 0;
	for(int j=0;j<mLfnCount;j++)
	{
		csrc = mLfn[j].name1;
		for(int i=0;i<5;i++)
		{
			utf8 = translateUtf16ToUtf8(csrc);
			csrc += 2;

			if(utf8 == 0)
			{
				*cdes = 0;
				return Error::NONE;
			}
			else if(utf8 < 0x80) // 아스키 코드
			{
				if(used+1 >= size)
					goto extractShortName;

				used++;
				*cdes++ = utf8;
			}
			else // 유니코드
			{
				used += 3;
				*cdes++ = utf8 >> 16;
				*cdes++ = utf8 >> 8;
				*cdes++ = utf8;
			}
		}

		csrc = mLfn[j].name2;
		for(int i=0;i<6;i++)
		{
			utf8 = translateUtf16ToUtf8(csrc);
			csrc += 2;

			if(utf8 == 0)
			{
				*cdes = 0;
				return Error::NONE;
			}
			else if(utf8 < 0x80) // 아스키 코드
			{
				if(used+1 >= size)
					goto extractShortName;

				used++;
				*cdes++ = utf8;
			}
			else // 유니코드
			{
				if(used+3 >= size)
					goto extractShortName;

				used += 3;
				*cdes++ = utf8 >> 16;
				*cdes++ = utf8 >> 8;
				*cdes++ = utf8;
			}

		}

		csrc = mLfn[j].name3;
		for(int i=0;i<2;i++)
		{
			utf8 = translateUtf16ToUtf8(csrc);
			csrc += 2;

			if(utf8 == 0)
			{
				*cdes = 0;
				return Error::NONE;
			}
			else if(utf8 < 0x80) // 아스키 코드
			{
				if(used+1 >= size)
					goto extractShortName;
	
				used++;
				*cdes++ = utf8;
				
				if(j+1 == mLfnCount && i == 1)
				{
					*cdes = 0;
					return Error::NONE;
				}
			}
			else // 유니코드
			{
				if(used >= size)
					goto extractShortName;

				used += 3;
				*cdes++ = utf8 >> 16;
				*cdes++ = utf8 >> 8;
				*cdes++ = utf8;

				if(j+1 == mLfnCount && i == 1)
				{
					*cdes = 0;
					return Error::NONE;
				}
			}
		}
	}

extractShortName :
	csrc = mEntryBuffer[mIndex].name;
	cdes = (char*)des;
	used = 0;

	for(int i=0;i<8 && *csrc;i++)
	{
		utf8 = translateMixedUtf16ToUtf8(csrc);

		if(utf8 == 0)
		{
			if(used >= size)
				goto extractShortName;

			*cdes = 0;
			return Error::NONE;
		}
		else if(utf8 < 0x80) // 아스키 코드
		{
			csrc += 1;
			if(used >= size)
				goto extractShortName;

			used++;
			*cdes++ = utf8;
		}
		else // 유니코드
		{
			if(used >= size)
				goto extractShortName;

			csrc += 2;
			used += 3;
			*cdes++ = utf8 >> 16;
			*cdes++ = utf8 >> 8;
			*cdes++ = utf8;
		}
	}

	*cdes = 0;
	
	return Error::NONE;
}

unsigned int Fat32DirectoryEntry::getTargetCluster(void)
{
	return mEntryBuffer[mIndex].startingClusterHigh << 16 | mEntryBuffer[mIndex].startingClusterLow;
}

bool Fat32DirectoryEntry::comapreTargetName(const char *utf8)
{
	char *csrc = (char*)utf8;
	char *utf16;
	unsigned int ch;

	// 긴 파일 이름인지 점검
	if(mLfnCount == 0)
		goto extractShortName;
	
	// 파일 이름 추출
	for(int j=0;j<mLfnCount;j++)
	{
		utf16 = mLfn[j].name1;
		for(int i=0;i<5;i++)
		{
			ch = translateUtf16ToUtf8(utf16);
			utf16 += 2;

			if(ch == 0)
			{
				if(*csrc == 0)
					return false;
				else
					return true;
			}
			else if(ch < 0x80) // 아스키 코드
			{
				if(*csrc++ != (char)ch)
					return true;
			}
			else // 유니코드
			{
				if(*csrc++ != (char)(ch >> 16))
					return true;
				if(*csrc++ != (char)(ch >> 8))
					return true;
				if(*csrc++ != (char)ch)
					return true;
			}
		}

		utf16 = mLfn[j].name2;
		for(int i=0;i<6;i++)
		{
			ch = translateUtf16ToUtf8(utf16);
			utf16 += 2;

			if(ch == 0)
			{
				if(*csrc == 0)
					return false;
				else
					return true;
			}
			else if(ch < 0x80) // 아스키 코드
			{
				if(*csrc++ != (char)ch)
					return true;
			}
			else // 유니코드
			{
				if(*csrc++ != (char)(ch >> 16))
					return true;
				if(*csrc++ != (char)(ch >> 8))
					return true;
				if(*csrc++ != (char)ch)
					return true;
			}
		}

		utf16 = mLfn[j].name3;
		for(int i=0;i<2;i++)
		{
			ch = translateUtf16ToUtf8(utf16);
			utf16 += 2;

			if(ch == 0)
			{
				if(*csrc == 0)
					return false;
				else
					return true;
			}
			else if(ch < 0x80) // 아스키 코드
			{
				if(*csrc++ != (char)ch)
					return true;
			}
			else // 유니코드
			{
				if(*csrc++ != (char)(ch >> 16))
					return true;
				if(*csrc++ != (char)(ch >> 8))
					return true;
				if(*csrc++ != (char)ch)
					return true;
			}
		}
	}

extractShortName :
	csrc = (char*)utf8;
	char *cmp = mEntryBuffer[mIndex].name;

	for(int i=0;i<8 && *csrc && *cmp;i++)
	{
		if(*cmp++ != *csrc++)
			return true;
	}

	if(*cmp != *csrc)
		return true;
	else
		return false;
}

int Fat32DirectoryEntry::strlen(const char *src)
{
	int count = 0;

	while(*src)
	{
		if(*src >= 0x80)
			src += 3;
		else
			src++;
		count++;
	}

	return count;
}

error Fat32DirectoryEntry::append(void)
{
	error result;

	result = mCluster->append();
	if(result != Error::NONE)
		return result;

	memset(mEntryBuffer, 0, 512);
	mIndex = 0;

	return Error::NONE;
}

error Fat32DirectoryEntry::insertEntry(unsigned char lfnLen, DirectoryEntry *src)
{
	error result;
	
	// mEntryBuffer에 mLfn 버퍼를 복사
	for(int i=0;i<lfnLen;i++)
	{
		memcpy(&mEntryBuffer[mIndex++], &mLfn[i], sizeof(DirectoryEntry));
		if(mIndex > 15)
		{
			result = mCluster->writeDataSector(mEntryBuffer);
			if(result != Error::NONE)
				return result;

			result = mCluster->increaseDataSectorIndex();
			if(result == Error::NO_DATA)
			{
				// 마지막 엔트리에서 비워진 다음 섹터가 없다면 클러스터 하나 추가
				result = append();
				if(result != Error::NONE)
					return result;
			}
			else if(result != Error::NONE)
				return result;
			else
			{
				memset(mEntryBuffer, 0, 512);
				mIndex = 0;
			}
		}
	}

	memcpy(&mEntryBuffer[mIndex++], src, sizeof(DirectoryEntry));
	if(mIndex > 15)
	{
		result = mCluster->writeDataSector(mEntryBuffer);
		if(result != Error::NONE)
			return result;

		result = mCluster->increaseDataSectorIndex();
		if(result == Error::NO_DATA)
		{
			// 마지막 엔트리에서 비워진 다음 섹터가 없다면 클러스터 하나 추가
			result = append();
			if(result != Error::NONE)
				return result;
		}
		else if(result != Error::NONE)
			return result;
		else
		{
			memset(mEntryBuffer, 0, 512);
			mIndex = 0;
		}
	}
	else
	{
		result = mCluster->writeDataSector(mEntryBuffer);
		if(result != Error::NONE)
			return result;
	}

	return Error::NONE;
}

error Fat32DirectoryEntry::makeDirectory(const char *src)
{
	DirectoryEntry *entry, sfn, parent;
	error result;
	int len = strlen(src), tmp;
	int lfnLen = (len + 11) / 12;
	unsigned int cluster;
	unsigned char checksum;
	unsigned char *sectorBuffer;

	memset(&sfn, 0, sizeof(DirectoryEntry));
	// 현재 엔트리가 비워진 엔트리가 아니라면
	entry = &mEntryBuffer[mIndex];
	if(entry->name[0] != 0)
	{
		// 마지막 비워진 엔트리로 이동
		result = moveToEnd();
		if(result == Error::NO_DATA)
		{
			// 마지막 엔트리에서 비워진 데이터가 없다면 클러스터 하나 추가
			result = append();
			if(result != Error::NONE)
				return result;
		}
		else if(result != Error::NONE)
			return result;
	}
	
	// 새 디렉토리용 클러스터 할당
	cluster = mCluster->allocate();
	if(cluster == 0)
		return Error::NO_FREE_DATA;
	
	// Short File Name 데이터 생성
	setShortName(sfn.name, src);
	sfn.attr = DIRECTORY;
	sfn.extention[0] = sfn.extention[1] = sfn.extention[2] = ' ';
	sfn.startingClusterLow = cluster & 0xFFFF;
	sfn.startingClusterHigh = (cluster >> 16) & 0xFFFF;
	
	checksum = calculateChecksum(&sfn);

	// Long File Name 데이터 생성
	for(int i=0;i<lfnLen;i++)
	{
		mLfn[i].attr = LONG_FILE_NAME;
		mLfn[i].order = lfnLen - i;
		mLfn[i].type = 0;
		mLfn[i].checksum = checksum;
		*(unsigned short*)&mLfn[0].zero = 0;
	}
	mLfn[0].order |= 0x40;
	copyStringUtf8ToLfnBuffer(src, len);
	
	parent = getCurrentDirectoryEntry();
	
	// 생성된 디렉토리 내의 '.', '..' 폴더 기입용 메모리 할당
	sectorBuffer = new unsigned char[512];
	if(sectorBuffer == 0)
		return Error::NEW_FAILED;
	memset(sectorBuffer, 0, 512);
	
	// '.' 폴더 설정
	entry = (DirectoryEntry*)&sectorBuffer[0];
	*entry = sfn;
	memcpy(entry->name, ".       ", 8);

	// '..' 폴더 설정
	entry = (DirectoryEntry*)&sectorBuffer[sizeof(DirectoryEntry)];
	*entry = parent;
	memcpy(entry->name, "..      ", 8);
	entry->extention[0] = entry->extention[1] = entry->extention[2] = ' ';
	entry->attr = DIRECTORY;
	tmp = mCluster->getStartCluster();
	if(tmp == mCluster->getRootCluster())
		tmp = 0;
	entry->startingClusterLow = tmp & 0xFFFF;
	entry->startingClusterHigh = (tmp >> 16) & 0xFFFF;

	mCluster->backup();
	
	result = mCluster->setCluster(cluster);
	if(result != Error::NONE)
		goto handle_error;

	mCluster->writeDataSector(sectorBuffer);
	if(result != Error::NONE)
		goto handle_error;
	
	mCluster->restore();

	// 폴더 추가에서 깨진 mEntryBuffer의 데이터를 다시 복원
	result = mCluster->readDataSector(mEntryBuffer);
	if(result != Error::NONE)
		goto handle_error;

	// 생성된 디렉토리의 엔트리 정보를 엔트리 버퍼에 삽입
	result = insertEntry(lfnLen, &sfn);

handle_error:
	delete sectorBuffer;
	return result;
}

void Fat32DirectoryEntry::setShortName(void *des, const char *src)
{
	char *cdes = (char*)des;
	unsigned char len = 8;
	unsigned short utf16;

	while(*src)
	{
		if(*src <= 0x7F) // 아스키 코드
		{
			if(*src >= 'a' && *src <= 'z')
				*cdes++ = *src++ - 0x20;
			else
				*cdes++ = *src++;
			
			src++;
			len--;
		}
		else
		{
			utf16 = translateUtf8ToUtf16(src);
			*cdes++ = utf16 >> 8;
			*cdes++ = utf16;
			src += 3;
			len -= 2;
		}

		if(len <= 3)
		{
			*cdes++ = '~';
			*cdes++ = '1';
			return;
		}
	}

	*cdes = 0;
}

// 함수 코드의 출처
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=bitnang&logNo=70183899277
unsigned char Fat32DirectoryEntry::calculateChecksum(DirectoryEntry *src)
{
	int i;
	unsigned char sum=0, *buf = (unsigned char*)src;

	for(i=0;i<11;i++)
		sum = ((sum & 1) ? 0x80 : 0) + (sum >> 1) + buf[i];

	return sum; 
}

void Fat32DirectoryEntry::copyStringUtf8ToLfnBuffer(const char *utf8, signed int len)
{
	unsigned short utf16;
	unsigned char *des;
	int lfnLen = (len + 11) / 12;

	for(unsigned char i=1;i<=lfnLen;i++)
	{
		des = (unsigned char*)mLfn[lfnLen-i].name1;
		for(int j=0;j<5;j++)
		{
			if(len == 0)
			{
				*des++ = 0;
				*des++ = 0;
			}
			else if(len < 0)
			{
				*des++ = 0xFF;
				*des++ = 0xFF;
			}
			else
			{
				utf16 = translateUtf8ToUtf16(utf8);
				if(utf16 > 0x7F)
					utf8+=3;
				else
					utf8++;
				*des++ = utf16;
				*des++ = utf16 >> 8;
			}
			len--;
		}

		des = (unsigned char*)mLfn[lfnLen-i].name2;
		for(int j=0;j<6;j++)
		{
			if(len == 0)
			{
				*des++ = 0;
				*des++ = 0;
			}
			else if(len < 0)
			{
				*des++ = 0xFF;
				*des++ = 0xFF;
			}
			else
			{
				utf16 = translateUtf8ToUtf16(utf8);
				if(utf16 > 0x7F)
					utf8+=3;
				else
					utf8++;
				*des++ = utf16;
				*des++ = utf16 >> 8;
			}
			len--;
		}

		des = (unsigned char*)mLfn[lfnLen-i].name3;
		for(int j=0;j<2;j++)
		{
			if(len == 0)
			{
				*des++ = 0;
				*des++ = 0;
			}
			else if(len < 0)
			{
				*des++ = 0xFF;
				*des++ = 0xFF;
			}
			else
			{
				utf16 = translateUtf8ToUtf16(utf8);
				if(utf16 > 0x7F)
					utf8+=3;
				else
					utf8++;
				*des++ = utf16;
				*des++ = utf16 >> 8;
			}
			len--;
		}
	}
}
