#include <p18f4550.h>
#include <delays.h>
#include <timers.h>
#include <definition.h>

void alarm(void)
{
    long int cnt;
    TRISCbits.TRISC2  =   0;
    cnt = 512000;
    while(cnt > 0)
    {
        LATCbits    .LATC2  =   1;
        Delay10TCYx(1);
        LATCbits    .LATC2  =   0;
        Delay10TCYx(1);
    }
    return;
}

