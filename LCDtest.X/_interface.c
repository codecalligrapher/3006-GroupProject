/***************************************************************************
 * File Name:   _interval.c
 * Author:      Aadidev Sooknanan
 * 
 * Function:
 *      interface_interval
 *          Input:      NONE
 *          Output:     NONE
 *          Process:    
                        Initialises LCD
                        Displays Options for Interval Storage
                        
                                                
 *      interface_action
   *          Input:    NONE
 *          Output:     NONE
 *          Process:    
                        Initialises LCD 
                        Displays Option to "Measure" OR "View Stored"
                        
       itnerface_display_abort
            Input:      NONE
            Output:     NONE 
            Process:
                        Initialises LCD
                        Displays Option to continue or abort storage
                        
      interface_display_stored
            Input:      EEPROM Address 
            Output:     NONE 
            Process:    
                        Calls EEPROM Read Data routine
                        Displays returned values 

    Getters and setters for Temperature, HRV, HR and Glucose

    Variable Listing:
            interface_temp_int      -   buffer between EEPROM and LCD 
                                    OR DS1822 and LCD
            interface_temp_fraction - same as above
            interface_rate          -   buffer between EEPROM and LCD
                                    OR main and LCD
            interface_pnn50         -   buffer between EEPROM and LCD
                                    OR main and LCD
            interface_gluc          -   buffer between EEPROM and LCD 
                                    OR ADC and LCD
            LCD_var, LCD_rate, LCD_temp, LCD_gluc   -   character arrays 
                                            used to parse read/measured values
                                            to the display   
 * **************************************************************************/

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

static int interface_temp_int     =   0;
static int interface_temp_fraction     =   0;
static int interface_rate       =   0;
static int interface_pnn50  =   0;
static int interface_gluc      =   0;
static char interface_disp[32];
static char LCD_rate[32];
static char LCD_var[32];
static char LCD_temp[32];
static char LCD_gluc[32];


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
    SetDDRamAddr(LINE_TWO);
    putrsXLCD("CHOOSE INTERVAL");
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    CLEAR_LCD;
    SetDDRamAddr(LINE_ONE);
    putrsXLCD("A: ALL MEASUREMENTS");
    SetDDRamAddr(LINE_TWO);
    putrsXLCD("B: 2 MEASUREMENTS");
    SetDDRamAddr(LINE_THREE);
    putrsXLCD("C: 5 MEASUREMENTS");
    SetDDRamAddr(LINE_FOUR);
    putrsXLCD("D: 10 MEASUREMENTS");
    return;
}

void interface_action(void)
{
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    CLEAR_LCD;
    LCD_NOT_READY;
    WriteCmdXLCD(DON & BLINK_OFF);
    LCD_NOT_READY;;
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
    CLEAR_LCD;
    SetDDRamAddr(LINE_ONE);
    LCD_NOT_READY;
    putrsXLCD("A: CONTINUE");
    LCD_NOT_READY;
    SetDDRamAddr(LINE_TWO);
    LCD_NOT_READY;
    putrsXLCD("B: ABORT STORAGE");
    return;
}

void interface_set_temp_int(int temp)
{
    interface_temp_int  =   temp;
    return;
}

void interface_set_temp_fraction(int temp)
{
    interface_temp_fraction  =   temp;
    return;
}

void interface_set_rate(int rate)
{
    interface_rate  =   rate;
    return;
}

void interface_set_pnn50(unsigned int var)
{
    interface_pnn50 =   var;
    return;
}


void interface_set_gluc(int gluc)
{
    interface_gluc  =   gluc;
    return;
}

void interface_display_stored(unsigned int addr)
{
    //eeprom_display_data(addr);
    CLEAR_LCD;
    LCD_NOT_READY;    
    sprintf(LCD_rate,   "BPM: %u",      interface_rate);
    sprintf(LCD_var,    "pNN50: %i%%",  interface_pnn50);
    sprintf(LCD_temp,   "TEMP: %i.%i",  interface_temp_int,interface_temp_fraction,0xB0);
    sprintf(LCD_gluc,   "GLUCOSE: %img/dl",  interface_gluc);
    LCD_NOT_READY;
    SetDDRamAddr(LINE_ONE);
    LCD_NOT_READY;
    putsXLCD(LCD_rate);
    LCD_NOT_READY;
    SetDDRamAddr(LINE_TWO);
    LCD_NOT_READY;
    putsXLCD(LCD_var);
    LCD_NOT_READY;
    SetDDRamAddr(LINE_THREE);
    LCD_NOT_READY;
    putsXLCD(LCD_temp);
    LCD_NOT_READY;
    SetDDRamAddr(LINE_FOUR);
    LCD_NOT_READY;
    putsXLCD(LCD_gluc);
    LCD_NOT_READY;
    
    return;
}