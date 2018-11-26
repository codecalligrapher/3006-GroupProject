#include <p18cxxx.h>
#include <xlcd.h>
#include <delays.h>
#include "lcd_head.h"

void DelayPORXLCD(void)
{
    Delay1KTCYx(15);    // Delay of 15ms
                        // Cycles = (TimeDelay * Fosc) / 4
                        // Cycles = (15ms * 4MHz) / 4
                        // Cycles = 15,000
    return;
}
