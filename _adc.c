#include <p18f452.h>
#include <stdlib.h>
#include <adc.h>
#include <delays.h>

#define _XTAL_FREQ   4000000

#define LIFE_LINE   LATCbits.LATC0;

int glucose(void)
{
    int adc_res;
    TRISCbits.TRISC0    =   0;
    LATCbits.LATC0      =   0;
    
    OpenADC(ADC_FOSC_64 & ADC_RIGHT_JUST & ADC_8ANA_0REF,
            ADC_CH4 & ADC_INT_OFF);
    Delay10TCYx(5);
    ConvertADC();
    while(BusyADC());
    LATCbits.LATC0      =   0;
    adc_res = ReadADC();
    CloseADC();
    return adc_res;
}