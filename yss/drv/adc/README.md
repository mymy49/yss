# ADC

## class 기본 구성
```c++
namespace drv
{
class Adc : public Drv
{
  public:
    Adc(ADC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void));
    bool init(void);
    void isr(void);
    void add(unsigned char pin, unsigned char lpfLv = define::adc::lpfLv::LV0, unsigned char bit = define::adc::bit::BIT12);
    unsigned short get(unsigned char pin);
};
}
}
```

## bool init(void);
	들여쓰기 테스트
	
