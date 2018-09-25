#include <p18f452.h>
#include <delays.h>
#include <timers.h>

//Configuration Bits
#pragma config OSC = XT                                                         // High-Speed oscillator
#pragma config WDT = OFF                                                        // Watchdog timer OFF
#pragma config LVP = OFF                                                        // Low-voltage programming OFF
#pragma config PWRT = OFF                                                       // Power-up Timer Enable bit (PWRT enabled)
#pragma config CPD = OFF                                                        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
// End of configuration

void CloseTimer0(void);
void OpenTimer0(unsigned char config);
unsigned int ReadTimer0(void);
void WriteTimer0(unsigned int timer);
double rate(void);
static double rates;

void main(void)
{
    OpenTimer0(
            TIMER_INT_OFF 
            & T0_SOURCE_EXT 
            & T0_8BIT
            & T0_EDGE_RISE
            & T0_PS_1_4);
    
    
    rates = rate();
    return;
}

double rate(void)
{
    TMR0L   =   0;
    TMR0H   =   0;
    Delay10KTCYx(1500);
    return (TMR0L / 15);
}



