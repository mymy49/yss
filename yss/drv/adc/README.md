# ADC

## class 기본 구성
```c++
namespace drv
{
class Adc : public Drv
{
  public:
    bool init(void);
    void add(unsigned char pin, unsigned char lpfLv = define::adc::lpfLv::LV0, unsigned char bit = define::adc::bit::BIT12);
    unsigned short get(unsigned char pin);
};
}
}
```

## bool init(void);
	[반환]
		초기화에 성공할 경우 true를 반환한다.
	[인자]
		없음
	
	ADC 장치의 설정을 초기화 하는 함수이다. init 함수로 ADC가 바로 동작하지는 않고 add() 함수를 사용하여 ADC 입력 채널을 추가해야 해당 채널의 ADC를 수행한다.

## void add(unsigned char pin, unsigned char lpfLv = define::adc::lpfLv::LV0, unsigned char bit = define::adc::bit::BIT12);
	[반환]
		없음
	[인자]
		unsgiend char pin
			ADC 입력 핀 번호를 지정한다.
		unsigned char lpflv = define::adc::lpfLv::LV0
			ADC 입력에 대한 Low Pass Filter 주파수 설정을 한다. 하지만 처리 부하를 

