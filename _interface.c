#include <p18f452.h>
#include <xlcd.h>
#include <delays.h>
#include <stdio.h>
#include "_functions.h"
#include "def_f842.h"


void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD (void);

extern short unsigned int kpad_data;

static float interface_temp     =   0;
static int interface_rate       =   0;
static float interface_pnn50    =   0;
static float interface_gluc      =   0;
static char interface_disp[32];

void interface_interval(void)
{
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);
    LCD_NOT_READY;
    WriteCmdXLCD(DON & BLINK_OFF);
    LCD_NOT_READY;;
    WriteCmdXLCD(0x01);
    SetDDRamAddr(LINE_ONE);
    putrsXLCD("CHOOSE INTERVAL");
    SetDDRamAddr(LINE_TWO);
    putrsXLCD("A: 2 MEASUREMENTS");
    SetDDRamAddr(LINE_THREE);
    putrsXLCD("A: 5 MEASUREMENTS");
    SetDDRamAddr(LINE_FOUR);
    putrsXLCD("A: 10 MEASUREMENTS");
    return;
}

void interface_action(void)
{
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);
    LCD_NOT_READY;
    WriteCmdXLCD(DON & BLINK_OFF);
    LCD_NOT_READY;;
    WriteCmdXLCD(0x01);
    SetDDRamAddr(LINE_ONE);
    putrsXLCD("A : MEASURE");
    SetDDRamAddr(LINE_TWO);
    putrsXLCD("B : VIEW STORED");
    return;
}

void interface_display_abort(void)
{
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);
    LCD_NOT_READY;
    WriteCmdXLCD(DON & BLINK_OFF);
    LCD_NOT_READY;;
    WriteCmdXLCD(0x01);
    SetDDRamAddr(LINE_ONE);
    putrsXLCD("PRESS ANY KEY TO ABORT");
    Delay1KTCYx(100);
    return;
}

void interface_display_read(void)
{
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);
    LCD_NOT_READY;
    WriteCmdXLCD(DON & BLINK_OFF);
    LCD_NOT_READY;;
    WriteCmdXLCD(0x01);
    SetDDRamAddr(LINE_ONE);
    sprintf(interface_disp, "BPM: %d", interface_rate);
    LCD_NOT_READY;
    putsXLCD(interface_disp);
    
    LCD_NOT_READY;
    SetDDRamAddr(LINE_TWO);
    sprintf(interface_disp, "TEMP: %f", interface_temp);
    LCD_NOT_READY;
    putsXLCD(interface_disp);
    
    LCD_NOT_READY;
    SetDDRamAddr(LINE_THREE);
    sprintf(interface_disp, "pNN50: %f", interface_pnn50);
    LCD_NOT_READY;
    putsXLCD(interface_disp);
    
    LCD_NOT_READY;
    SetDDRamAddr(LINE_FOUR);
    sprintf(interface_disp, "GLUCOSE: %f", interface_gluc);
    LCD_NOT_READY;
    putsXLCD(interface_disp);
    
    return;
}


void interface_set_temp(float temp)
{
    interface_temp  =   temp;
    return;
}

void interface_set_rate(int rate)
{
    interface_rate  =   rate;
    return;
}

void interface_set_pnn50(float var)
{
    interface_pnn50 =   var;
    return;
}

void interface_set_gluc(float gluc)
{
    interface_gluc  =   gluc;
    return;
}
