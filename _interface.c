#include <p18f452.h>
#include <xlcd.h>
#include <delays.h>
#include <stdio.h>
#include "_functions.h"
#include "def_f842.h"


void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD (void);
void init_interface(void);

extern short unsigned int kpad_data;

void init_interface(void)
{
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);    
    LCD_NOT_READY;
    WriteCmdXLCD(DON & BLINK_OFF);    
    LCD_NOT_READY;;
    WriteCmdXLCD(0x01);
    SetCGRamAddr(0x01);
    putrsXLCD("A : Measure");
    
    LCD_NOT_READY;
    SetCGRamAddr(0x0A);
    putrsXLCD("B : View");
    
    if(TMR0IF)
    {
        LCD_NOT_READY;
        SetCGRamAddr(0x13);
        putrsXLCD("C : Store");

        LCD_NOT_READY;
        SetCGRamAddr(0x01);
        putrsXLCD("Press D to Abort");
    }
    kpad_config();
    switch(kpad_data)
    {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4: 
            break;
        case 5: 
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15: 
            break;
        default: 
            return NULL;                    
    }
}
