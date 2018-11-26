#include <p18f452.h>
#include <delays.h>
#include <timers.h>
#include <stdio.h>
#include "def_f842.h"
#include "kpad.h"

#define TMR0_RST    WriteTimer0(0)
#define TMR1_RST    WriteTimer1(0)

#define measure_ready   PORTBbits   .RB0    
#define heart_in        PORTAbits   .T0CKI

#define test_LED_0      LATDbits    .LATD0

#define TEST            0
#define ALARM_SEQUENCE  0
//---------------------------MESAUREMENT PERIOD-------------------------------//
#define     P_30S       6942
#define     P_15S       36239
#define     P_10S       46004
#define     P_5S        55770

static int count;
short unsigned float h_rate;
short int delay;
char MEASURE;

#pragma code low_vector    =   0x18
void interrupt_at_low_vector(void)
{
    _asm GOTO h_isr  _endasm
}

#pragma code
#pragma interrupt h_isr
void h_isr(void)
{
    if (TMR1IF){
        GIE = 0;
        if (count > 0)
        {
            TMR1IF  =   0;
            count--;
            config_timer();
        }
        else
        {
            MEASURE = 0;
            TMR1IF  =   0;
            get_rate();
        }
        GIE = 1;
        return;
    }
    
}
//only function that needs to be called
//poll MEASURE to determine when read is available
void init_measure(void)
{
    MEASURE =   1;
    delay = 15;
    count = 64;
    measure();
    return;
}

void measure(void)
{
    config_timer();
    config_counter();
}
#if TEST
void get_count(void)
{
    h_rate  =   ReadTimer0();
    return;
}
#endif
void get_rate(void)
{
    TMR1_RST;
    switch(delay)
    {           
        case 5:
            h_rate      =   ReadTimer0()/5;
            MEASURE     =   0;
            break;
        case 10:
            h_rate      =   ReadTimer0()/10;
            MEASURE     =   0;
            break;
        case 15:   
            h_rate      =   ReadTimer0()/15;
            MEASURE     =   0;
            break;
        case 30:
            h_rate      =   ReadTimer0()/30;
            MEASURE     =   0;
            break;
        default:    
            h_rate      =    NULL;   
            MEASURE     =   0;
    }
    TMR0_RST;
    return;
}



void config_counter(void)
{
    TMR0_RST;
    OpenTimer0(TIMER_INT_OFF 
            &   T0_8BIT
            &   T0_SOURCE_EXT
            &   T0_EDGE_RISE
            &   T0_PS_1_1);
    return;
}

void config_timer(void)
{
    TMR1_RST;
    switch(delay)
    {           
        case 5:
            WriteTimer1(P_5S);
            break;
        case 10:
            WriteTimer1(P_10S);
            break;
        case 15:   
            WriteTimer1(P_15S);
            break;
        case 30:
            WriteTimer1(P_30S);
            break;
        default:    
            return NULL;                             
    }
    OpenTimer1(TIMER_INT_ON
            &   T1_16BIT_RW
            &   T1_SOURCE_INT
            &   T1_PS_1_8
            &   T1_OSC1EN_OFF
            &   T1_SYNC_EXT_OFF);
    PEIE    =   1;
    IPEN    =   1;
    GIE     =   1;
    return;
}

