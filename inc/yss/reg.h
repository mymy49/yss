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

#ifndef REG__H_
#define REG__H_

// 이전 사용 방식(나중에 제거할 예정)
#define setRegBit(des, bit, shift) \
	if (bit)                       \
		des |= 1 << shift;         \
	else                           \
		des &= ~(1 << shift)

#define getRegBit(src, shift) ((src >> (shift)) & 0x1)

#if defined(STM32F1) || defined (GD32F1) || defined(STM32F4) || defined(STM32F7)
template <class setRegFieldVar>
__attribute__((always_inline)) __STATIC_INLINE void setRegField(setRegFieldVar &des, uint32_t mask, uint32_t data, uint8_t sh)
{
	des = (des & ~(mask << sh)) | ((data & mask) << sh);
}
#define getRegField(addr, mask, sh) ((addr >> sh) & mask)
#endif

// 앞으로 사용할 방식
#define setBitData(des, bit, shift) \
	if (bit)                       \
		des |= 1 << shift;         \
	else                           \
		des &= ~(1 << shift)

#define getBitData(src, shift) ((src >> (shift)) & 0x1)

#define setFieldData(des, mask, data, shift) des = (des & ~(mask)) | (((data) << (shift)) & (mask))
#define getFieldData(src, mask, shift) ((src & mask) >> shift)

#define setTwoFieldData(des, mask1, data1, shift1, mask2, data2, shift2) des = (des & ~(mask1 | mask2)) | ((data1 << shift1 & mask1) | (data2 << shift2 & mask2))
#define setThreeFieldData(des, mask1, data1, shift1, mask2, data2, shift2, mask3, data3, shift3) des = (des & ~((mask1)|(mask2)|(mask3))) | (((data1) << (shift1) | (data2) << (shift2) | (data3) << (shift3)) & ((mask1)|(mask2)|(mask3)))

#endif