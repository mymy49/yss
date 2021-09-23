# ADC 구성

```c++
namespace drv
{
class Adc : public Drv
{
    ADC_TypeDef *mPeri;
    signed int mResult[18];
    unsigned char mIndex;
    unsigned char mLpfLv[18];
    unsigned char mChannel[18];
    unsigned char mBit[18];
    unsigned char mNumOfCh;

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


