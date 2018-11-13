#include <p18f452.h>
#include <timers.h>
#include <delays.h>
#include <stdio.h>
#include <xlcd.h>
#include <portb.h>
#include <timers.h>
#include <spi.h>
#include "_functions.h"
#include "def_f842.h"

void LED_debug(void)
{

    TRISEbits.TRISE0    =   0;
    TRISEbits.TRISE1    =   0;
    TRISEbits.TRISE2    =   0;
    LED_TEST_ONE        =   1;
    LED_TEST_TWO        =   1;
    LED_TEST_THREE      =   1;
    Delay1KTCYx(256);
    LED_TEST_ONE        =   0;
    Delay1KTCYx(256);
    LED_TEST_TWO        =   0;
    Delay1KTCYx(256);
    LED_TEST_THREE      =   0;
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);
    LCD_NOT_READY;

#if NDEBUG_LED
    while(1)
    {
        LED_TEST_ONE    =  0;
        LED_TEST_TWO    =  0;
        LED_TEST_THREE  =  0;
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        LED_TEST_ONE    =  1;
        LED_TEST_TWO    =  1;
        LED_TEST_THREE  =  1;
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
    }
#endif

    return;
}

void temp_debug(void)
{
#if NDEBUG_TEMP
    static char LCD_test[32];
    temp();
    LCD_NOT_READY;
    CLEAR_LCD;
    LCD_NOT_READY;
    SetDDRamAddr(0x40);
    sprintf(LCD_test, "Temperature: %f", finaltemp);
    LCD_NOT_READY;
    putsXLCD(LCD_test);
    LED_TEST_ONE    =   1;
    while(1);
#endif
}

void kpad_debug(void)
{
#if NDEBUG_KPAD
    static char LCD_test[32];
    static unsigned int kpad_data;
    kpad_config();
    while(1)
    {
        LED_TEST_ONE    =   1;
        while(!PORTBbits.INT1);

        kpad_data = kpad_rslv();
        sprintf(LCD_test,"Keypress: %c", kpad_data);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_ONE);
        CLEAR_LCD;
        LCD_NOT_READY;
        putsXLCD(LCD_test);
        LCD_NOT_READY;
    }
#endif
}

void glucose_debug(void)
{
    
    static char LCD_test[32];
#if NDEBUG_GLUCOSE
    while(1)
    {
        LED_TEST_ONE    =   1;
        LED_TEST_TWO    =   ~LED_TEST_ONE;
        sprintf(LCD_test, "ADC: %i", adc_measure());
        LCD_NOT_READY;
        SetDDRamAddr(LINE_THREE);
        CLEAR_LCD;
        LCD_NOT_READY;
        putsXLCD(LCD_test);
        LCD_NOT_READY;

        LED_TEST_ONE    =   0;
        LED_TEST_TWO    =   ~LED_TEST_ONE;
        Delay1KTCYx(256);
        Delay1KTCYx(256);
    }

#endif
}