#include <p18f452.h>
#include <delays.h>
#include <pwm.h>
#include <timers.h>
#include "_functions.h"

#define A_PERIOD    16036063
#define B_PERIOD    16034322                    
#define C_PERIOD    16051425
#define D_PERIOD    16061155

void alarm_init(char note)
{
    OpenTimer2(TIMER_INT_OFF
            & T2_PS_1_4
            & T2_POST_1_1);
    switch(note)
    {
        case 'A':
            OpenPWM2(A_PERIOD);
            break;
        case 'B':
            OpenPWM2(B_PERIOD);
            break;
        case 'C':
            OpenPWM2(50);
            break;
        case 'D':
            OpenPWM2(D_PERIOD);
            break;
        default:
            OpenPWM2(C_PERIOD);
    }
    return;
}

void alarm_close(void)
{
    ClosePWM2();
    return;
}

void alarm(void)
{
    TRISBbits.CCP2    =   0;
    
        alarm_init('C');
        Delay1KTCYx(500);
        SetDCPWM2(0);
        Delay1KTCYx(500);
    
    return;
}
