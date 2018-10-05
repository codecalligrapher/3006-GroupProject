#include <p18f452.h>
#include <delays.h>
#include "_keypad.h"

#pragma code low_vector=0x18
void low_interrupt(void)
{
    _asm GOTO low_isr _endasm
}

#pragma code
#pragma interruptlow low_isr save=PROD
void low_isr(void)
{
    if(INTCON3bits.INT1F)
    {
        INTCONbits.GIE      =   0;
        INTCON3bits.INT1E   =   0;
        INTCON3bits.INT1F   =   0;
        read_keypad();
        INTCON3bits.INT1E   =   1;
        INTCONbits.GIE      =   1;
    }
    return;
}

void read_keypad(void)
{
    key_value = PORTBbits.RB0 | PORTBbits.RB1 | PORTBbits.RB2 | PORTBbits.RB3;
    return;
}

void config_keypad(void)
{   
    TRISDbits.TRISD0    =   1;
    TRISDbits.TRISD1    =   1;
    TRISDbits.TRISD2    =   1;
    TRISDbits.TRISD3    =   1;
    
    RCONbits.IPEN       =   1;                              //enables priority
    INTCON3bits.INT1F   =   1;                              //clears INT1 flag
    
    kpad_drt            =   1;                              //INT1 pin as input
    INTCON2bits.INTEDG1 =   1;                              //External INT1 on rising edge
    INTCON3bits.INT1P   =   0;                              //low-priority INT1
    INTCON3bits.INT1E   =   1;                              //enables INT1 interrupts
    INTCONbits.GIE      =   1;
    return;
}

#if 0
void main(void)
{
    config_keypad();
    while(1);
    return;
}
#endif