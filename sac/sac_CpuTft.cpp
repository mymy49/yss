////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <sac/CpuTft.h>
#include <config.h>
#include <yss/malloc.h>
#include <yss/stdlib.h>

namespace sac
{
	CpuTft::CpuTft(void)
    {
		mBrushColor.halfword = 0xFFFF;
		mBgColor.halfword = 0x0000;
    }

	void CpuTft::lock(void)
	{
		mMutex.lock();
	}

	void CpuTft::unlock(void)
	{
		mMutex.unlock();
	}

//	void CpuTft::fillToArea(void)
//    {
//		unsigned short color = translateColor(mBrushColor);
//		memsethw(mFrameBuffer, color, mAreaWidth*mAreaHeight*2);
//    }
//	
//	unsigned char CpuTft::drawCharToArea(signed short x, signed short y, unsigned int utf8)
//    {
//		unsigned short table[16], width, height;
//        unsigned char *fontFb;
////        unsigned short color = 
//
//		if(mFont.setChar(utf8))
//			return 0;
//	
//		YssFontInfo *fontInfo = mFont.getFontInfo();
//		fontFb = mFont.getFrameBuffer();
//		
//        width = fontInfo->width;
//        height = fontInfo->height;
//        for(int y=0;y<height;y++)
//        {
//			for(int x=0;x<width;x++)
//            {
////				mFrameBuffer[]
//            }
//        }
//
//        return fontInfo->width;
//    }

	void CpuTft::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
	{
		mBrushColor.color.red = red >> 3;
		mBrushColor.color.green = green >> 2;
		mBrushColor.color.blue = blue >> 3;
	}

	void CpuTft::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
	{
		mBgColor.color.red = red >> 3;
		mBgColor.color.green = green >> 2;
		mBgColor.color.blue = blue >> 3;
	}

	void CpuTft::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    {
//		mFontColor.color.red = red >> 3;
//		mFontColor.color.green = green >> 2;
//        mFontColor.color.blue = blue >> 3;
    }


}
