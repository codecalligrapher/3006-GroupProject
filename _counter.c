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

#pragma config OSC = XT                                                         // High-Speed oscillator
#pragma config WDT = OFF                                                        // Watchdog timer OFF
#pragma config LVP = OFF

#define _XTAL_FREQ   4000000


static int  i;
extern short unsigned int kpad_data;
extern char Temperature[];
extern float finaltemp;
static char LCD_temp[16];
static char LCD_bpm[32];
static char LCD_rate[32];
static char LCD_var[32];
static char LCD_test[32];

#pragma code high_vector=0x08
void high_vector(void)
{
    _asm GOTO h_isr _endasm
}

#pragma code
#pragma interrupt h_isr save=PROD
void h_isr(void)
{
    GIE =   0;

    if (INT2IF)
    {
#if NDEBUG
    LED_TEST_THREE  =   ~LED_TEST_THREE;
#endif
        INT2IF  =   0;
        time2_set(time_get());
        time_set(ReadTimer0());
        pnn50_calc(time_get(), time2_get());
        countv_incr();
#if NDEBUG_PNN50
        LCD_NOT_READY;
        CLEAR_LCD;
        SetDDRamAddr(LINE_THREE);
        sprintf(LCD_test, "PREV: %u", time2_get());
        LCD_NOT_READY;
        putsXLCD(LCD_test);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_TWO);
        sprintf(LCD_test, "CURR: %u", time_get());
        LCD_NOT_READY;
        putsXLCD(LCD_test);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_THREE);
        sprintf(LCD_test, "VAR CNT: %i", pnn50_get());
        LCD_NOT_READY;
        putsXLCD(LCD_test);     
        
#endif
#if NDEBUG_COUNTER
        LCD_NOT_READY;
        SetDDRamAddr(LINE_ONE);
        sprintf(LCD_test,"COUNT: %u, TIME: %u", countv_get(), ReadTimer0());
        LCD_NOT_READY;
        putsXLCD(LCD_test);
#endif
    }

    if(TMR0IF)
    {
#if NDEBUG
        LED_TEST_ONE    =   1;
#endif
        TMR0IF  =   0;
        
        sprintf(LCD_rate, "BPM: %u", countv_get_rate());
        sprintf(LCD_var, "pNN50: %2.2f",3.142);// pnn50_var());
        LCD_NOT_READY;
        CLEAR_LCD;
        LCD_NOT_READY;
        SetDDRamAddr(LINE_ONE);
        LCD_NOT_READY;
        putsXLCD(LCD_rate);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_TWO);
        LCD_NOT_READY;
        putsXLCD(LCD_var);
        countv_reset();
        time_reset();
        time2_reset();
        WriteTimer0(0);
    }
#if 0
    LED_TEST_THREE  =  0;
#endif
    GIE =   1;
}

void counter_measure_config(void)
{
    TRISBbits.TRISB2    =   1;      //make input
    TRISCbits.TRISC0    =   1;
    TRISCbits.RC0       =   1;

    countv_reset();
    time_reset();
    pnn50_reset();
    
    T0CON   =   0x87;
    WriteTimer0(6942);
    TMR0IE  =   1;
    RBPU    =   0;      //individual PULLUPS enabled
    IPEN    =   1;      //enable priority
    INT2IF  =   0;      //clear flag
    INTEDG2 =   1;      //select rising edge
    INT2IE  =   1;      //enable external interrupt
    INT2IP  =   1;
    GIE     =   1;      //enable HIGH interrupts
    PEIE    =   1;      //enable LOW interrupts
    return;
}

double counter_bpm(void)
{
    int count_temp  =   ReadTimer1();
    return (count_temp*6);
}


void main(void)
{
    int LCD_put     =   0;

    //choose option for interval storage
#if NDEBUG
    LED_debug();
    temp_debug();
    kpad_debug();
    glucose_debug();
#endif

    TRISBbits.TRISB0 = 1;

#if !NDEBUG
    while(1)
    {
#endif
#if NDEBUG
        LED_TEST_TWO    =   1;
#endif

#if HRATE
        putrsXLCD("MEASURING");
        counter_measure_config();
        while(1);
#endif

#if NDEBUG
        LED_TEST_TWO    =   0;
#endif


#if TEMP
                temp();
                LCD_NOT_READY;
                putsXLCD(Temperature);
#endif
                //CLEAR_LCD;
                LCD_put = 0;
#if !NDEBUG
    }
#endif
    return;
}
