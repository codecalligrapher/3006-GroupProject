#include <p18f452.h>
#include <timers.h>
#include "_functions.h"
#include "def_f842.h"

int beats;
unsigned int beats_time[60];

float rate;

#pragma code high_vector=0x08
void high_vector(void)
{
    _asm GOTO h_isr _endasm
}

#pragma code
#pragma interrupt h_isr 
void h_isr(void)
{
    if (INT0IF)
    {
        INT0IF  =   0;
        beats_time[beats] = ReadTimer0();
        beats++;
    }
}

void measure_beats(void)
{
    beats = 0;
    TRISBbits.TRISB0    =   1;      //make input
    RBPU    =   0;      //individual PULLUPS enabled
    IPEN    =   1;      //enable priority
    INT0IF  =   0;      //clear flag    
    INTEDG0 =   1;      //select rising edge
    INT0IE  =   1;      //enable external interrupt    
    GIE     =   1;      //enable HIGH interrupts
    PEIE    =   1;      //enable LOW interrupts
    return;
}

int calc_rate(int period)
{
    return beats*(30/period);
}
