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