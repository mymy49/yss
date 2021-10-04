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

### bool init(void);
	[반환]
		초기화에 성공할 경우 true를 반환한다.

	[인자]
		없음
	
	ADC 장치의 설정을 초기화 하는 함수이다. init 함수로 ADC가 바로 동작하지는 않고 add() 함수를 사용하여 ADC 입력 채널을 추가해야 해당 채널의 ADC를 수행한다.

### void add(unsigned char pin, unsigned char lpfLv = define::adc::lpfLv::LV0, unsigned char bit = define::adc::bit::BIT12);
	[반환]
		없음

	[인자]
		unsgiend char pin
			ADC 입력 핀 번호를 지정한다.

		unsigned char lpflv = define::adc::lpfLv::LV0
			ADC 입력에 대한 Low Pass Filter 레벨을 설정한다. 레벨이 커질 수록 응답 속도는 줄어든다.
			기본 인자 값은 LV0으로 설정되어 있다.

		unsigned char bit = define::adc::bit::BIT12
			ADC의 입력 해상도를 설정한다. 하드웨어 적으로 낮은 ADC라고 하더라도 Low Pass Filter로 인해 높은 해상도의 연산적 출력이 가능하다.
		

### unsigned short get(unsigned char pin);
	[반환]
		ADC 입력에 대한 디지털 변환 값을 반환한다.

	[인자]
		unsgiend char pin
			반환 받을 ADC 입력 핀 번호를 지정한다.

## ADC 예제 코드
```c++
void init(void)
{
    // ADC1 초기화
    adc1.setClockEn(true); // 클럭 활성화
    adc1.init(); // adc1 초기화
    gpioA.setAsAnalog(0); // GPIOA의 0번 핀을 아날로그 핀으로 설정
    gpioA.setAsAnalog(4); // GPIOA의 4번 핀을 아날로그 핀으로 설정
    gpioA.setAsAnalog(5); // GPIOA의 5번 핀을 아날로그 핀으로 설정

    adc1.add(0, lpfLv::LV12, bit::BIT16); // AIN0 핀을 LPF를 LV12로 비트를 16비트로 활성
    adc1.add(4, lpfLv::LV12, bit::BIT16); // AIN4 핀을 LPF를 LV12로 비트를 16비트로 활성
    adc1.add(5, lpfLv::LV12, bit::BIT16); // AIN5 핀을 LPF를 LV12로 비트를 16비트로 활성

    adc1.setIntEn(true); // adc1 인터럽트 활성화
}

int main(void)
{
    unsigned int result0, result1, result2;

    yss::init();
    init();

    while(1)
    {
        result0 = adc1.get(0);
        result1 = adc1.get(4);
        result2 = adc1.get(5);
    }
}
```
