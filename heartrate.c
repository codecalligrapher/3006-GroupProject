#include <p18f4550.h>
#include <delays.h>
#include <timers.h>
#include <definition.h>
#include <heartrate.h>
#include <stdio.h>

#define _XTAL_FREQ      4000000
#define measure_ready   PORTBbits   .RB0    
#define heart_in        PORTBbits   .RB2
//---------------------------MESAUREMENT PERIOD-------------------------------//
#define     P_30S       6942
#define     P_15S       36239
#define     P_10S       46004
#define     P_5S        55770

short unsigned int period, count;
short unsigned float h_rate;

#pragma code high_vector    =   0x08
void interrupt_high(void)
{
    _asm GOTO h_isr  _endasm
}

#pragma code
#pragma interrupt h_isr
void h_isr(void)
{
    if (TMR1IF)
    {
        if(count != 0)
        {
            init_timer();
            count--;
        }
        else
        {
            stop_measure(&h_rate);
        }
    }
}

#if 1
void main(void)
{
    init_measure();
    if (h_rate < 50 || h_rate > 90)
    {
        //alarm();
    }
    return;
}
#endif
void init_counter(void)
{
    GIE         =       0;
    PEIE        =       0;
    TMR0IF      =       0;
    TMR0ON      =       0;
    tmr0_rst();
    
    T0CS        =       1;                                                      //transition on T0CKI pin
    T08BIT      =       1;                                                      //8-bit counter
    T0SE        =       0;                                                      //increment on LOW-HIGH transition
    PSA         =       0;                                                      //PRESCALER not assigned 
    
    return;
}

void init_timer(void)
{
    GIE         =       0;
    TMR1IE      =       0;
    TMR1ON      =       0;
    RD16        =       1;                                                      //16-BIT operations    
    T1RUN       =       0;                                                      
    T1CKPS1     =       1;
    T1CKPS0     =       1;
    T1OSCEN     =       0;
    TMR1CS      =       0;                                                      //internal clock source
    
    switch(period)
    {           
        case 5:
            TMR1H   =   P_5S;
            break;
        case 10:
            TMR1H   =   P_10S;
            break;
        case 15:   
            TMR1H   =   P_15S;
            break;
        case 30:
            TMR1H   =   P_30S;
            break;
        default:    
            return NULL;                             
    }
    TMR1IF      =       0;
    IPEN        =       1;                                                      //interrupt PRIORITY enables    
    TMR1IP      =       1;                                                      //priority HIGH on overflow
    PEIE        =       1;
    TMR1IE      =       1;
    GIE         =       1;
    TMR1ON      =       1;
    return;
}

void init_measure(void)
{
    count   =   64;    
    init_counter();
    init_timer();
    return;
}

void stop_measure(short unsigned float *h_rate)
{
    TMR1IE      =       0;    
    TMR1IF      =       0;
    tmr1_rst();
    switch(period)
    {           
        case 5:
            *h_rate   =   TMR0L/5;
            break;
        case 10:
            *h_rate   =   TMR0L/10;
            break;
        case 15:   
            *h_rate   =   TMR0L/15;
            break;
        case 30:
            *h_rate   =   TMR0L/30;
            break;
        default:    
            *h_rate   =    NULL;                             
    }
    tmr0_rst();
    return;
}

void tmr0_rst(void)
{
    TMR0H   =   0;
    TMR0L   =   0;
}

void tmr1_rst(void)
{
    TMR1H   =   0;
    TMR1L   =   0;
}


