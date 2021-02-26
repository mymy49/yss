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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021.yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <sac/Brush.h>

namespace sac
{
	void Brush::drawDot(signed short x, signed short y, unsigned short color){}

    void Brush::setSize(unsigned short width, unsigned short height)
	{
		mWidth = width;
		mHeight = height;
	}
	
	void Brush::drawLine(signed short sx, signed short sy, signed short ex, signed short ey, unsigned short color)
	{
		signed short buf, loop;
		float dx, dy, d;

		if(sx > ex)
		{
			buf = ex;
			ex = sx;
			sx = buf;
		}
		if(sy > ey)
		{
			buf = ey;
			ey = sy;
			sy = buf;
		}
		
		dx = ex - sx;
		dy = ey - sy;
		if(dx > dy)
		{
			d = dy / dx;
			loop = dx;
			for(int i=0;i<loop;i++)
			{
				drawDot(sx+i, sy+d*i, color);
			}
		}
		else
		{
			d = dx / dy;
			loop = dy;
			for(int i=0;i<loop;i++)
			{
				drawDot(sx+d*i, sy+i, color);
			}
		}
	}

	void Brush::drawLine(signed short sx, signed short sy, signed short ex, signed short ey, unsigned short thickness, unsigned short color)
	{
		signed short dx, dy;

		if(ex > sx)
			dx = ex - sx;
		else
			dx = sx - ex;

		if(ey > sy)
			dy = ey - sy;
		else
			dy = sy - ey;
		
		if(dx > dy)
			for(int i=0;i<thickness;i++)
				drawLine(sx, sy+i, ex, ey+i, color);
		else
			for(int i=0;i<thickness;i++)
				drawLine(sx+i, sy, ex+i, ey, color);
	}

	void Brush::drawRect(signed short x, signed short y, unsigned short width, unsigned short height, unsigned short color)
	{
		drawLine(x, y, x+width, y, color);
		drawLine(x+width-1, y, x+width-1, y+height, color);
		drawLine(x+width-1, y+height-1, x, y+height-1, color);
		drawLine(x, y+height, x, y, color);
	}

	void Brush::drawRect(signed short x, signed short y, unsigned short width, unsigned short height, unsigned short thickness, unsigned short color)
	{
		drawLine(x, y, x+width, y, thickness, color);
		drawLine(x+width-thickness, y, x+width-thickness, y+height, thickness, color);
		drawLine(x+width-thickness, y+height-thickness, x, y+height-thickness, thickness, color);
		drawLine(x, y+height, x, y, thickness, color);
	}

}
