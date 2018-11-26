#include <p18cxxx.h>
#include <xlcd.h>
#include <delays.h>
#include "lcd_head.h"

void DelayXLCD (void)
{
    Delay1KTCYx(20);    // Delay of 5ms
                        // Cycles = (TimeDelay * Fosc) / 4
                        // Cycles = (5ms * 4MHz) / 4
                        // Cycles = 5,000
    return;
}
