#include <p18f452.h>
#include <stdlib.h>
#include <adc.h>
#include <delays.h>
#include "def_f842.h"
#include "_functions.h"

static int glucose;

int adc_measure(void)
{
    static int adc_res;
    
    OpenADC(ADC_FOSC_64 
            & ADC_RIGHT_JUST 
            & ADC_8ANA_0REF,
                ADC_CH4 
            & ADC_INT_OFF);
    Delay10TCYx(5);
    ConvertADC();
    while(BusyADC());
    adc_res = ReadADC();
    CloseADC();
    return adc_res;
}

void adc_glucose_rslv(void)
{
    glucose = 0;
    return;
}

int adc_glucose_get(void)
{
    adc_glucose_rslv();
#if NDEBUG_MEM_STORE
    glucose = 70;
#endif
#if NDEBUG_GLUC_UNSTABLE
    return 45;
#endif
    
#if NDEBUG_GLUC_STABLE
    return 80;
#endif
    
    
    return glucose;
}

void adc_glucose_reset(void)
{
    glucose = 0;
}