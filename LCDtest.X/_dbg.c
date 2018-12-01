/***************************************************************************
   File Name:  _dbg.c
   Author:      Aadidev Sooknanan
   
   Function:
        LED_debug
            Input:      NONE
            Output:     NONE
            Process:    Configures PORTE as Output            
                        Turns ON PORTE for fixed interval
                        
        temp_debug
            Input:      NONE
            Output:     NONE
            Process:    Initialises Temperature sensor 
                        Displays Temperature on LCD
                        
       kpad_debug
            Input:      NONE 
            Output:     NONE 
            Process:
                        Configures Keypad data bus as input 
                        Configures Keypad data ready pin as input 
                        Reads Data bus on a HIGH data ready 
                        Displays Keypress on LCD 
                        
      glucose_debug
            Input:      NONE 
            Output:     NONE 
            Process:    
                        Initialises ADC module 
                        Displays ADC result on LCD 

      hr_debug          
            Input:      NONE 
            Output:     NONE 
            Process:
                        Resets pulse counter, timer0 and HRV 
                        Configures INT2 external interrupt 

     nuke_debug
            Input:      NONE 
            Output:     NONE 
            Process:
                        Configures CCP1 as output for PWM 
                        Configures PWM Module   
                        Opens PWM Module 
                        Plays alarm sequence

      eeprom_debug 
              Input:    NONE 
              Output:   NONE
              Process:  
                        Writes 0-4 to first 5 locations in EEPROM 
                        Calls keypad configuration routine 
                        Displays data from EEPROM on LCD 
                        Allows for scrolling UP/DOWN through EEPROM
 ****************************************************************************/

#include <p18f452.h>
#include <timers.h>
#include <delays.h>
#include <stdio.h>
#include <xlcd.h>
#include <portb.h>
#include <timers.h>
#include <spi.h>
#include <pwm.h>
#include "_functions.h"
#include "def_f842.h"

void LED_debug(void)
{

    TRISEbits.TRISE0    =   0;
    TRISEbits.TRISE1    =   0;
    TRISEbits.TRISE2    =   0;
    LED_TEST_ONE        =   1;
    LED_TEST_TWO        =   1;
    LED_TEST_THREE      =   1;
    Delay1KTCYx(256);
    LED_TEST_ONE        =   0;
    Delay1KTCYx(256);
    LED_TEST_TWO        =   0;
    Delay1KTCYx(256);
    LED_TEST_THREE      =   0;
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);
    LCD_NOT_READY;

#if NDEBUG_LED
    while(1)
    {
        LED_TEST_ONE    =  0;
        LED_TEST_TWO    =  0;
        LED_TEST_THREE  =  0;
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        LED_TEST_ONE    =  1;
        LED_TEST_TWO    =  1;
        LED_TEST_THREE  =  1;
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
    }
#endif

    return;
}

void temp_debug(void)
{
#if NDEBUG_TEMP
    static char LCD_test[32];
    tempinit();
    tempread();
    
    LCD_NOT_READY;
    CLEAR_LCD;
    LCD_NOT_READY;
    SetDDRamAddr(LINE_TWO);
    sprintf(LCD_test, "TEMP: %i.%i", temp_get_int(),temp_get_fraction());
    LCD_NOT_READY;
    putsXLCD(LCD_test);
    LED_TEST_ONE    =   1;
    while(1);
#endif
}

void kpad_debug(void)
{
#if NDEBUG_KPAD
    static char LCD_test[32];
    static unsigned int kpad_data;
    kpad_config();
    while(1)
    {
        LED_TEST_ONE    =   1;
        while(!PORTBbits.INT1);

        kpad_data = kpad_rslv();
        sprintf(LCD_test,"Keypress: %c", kpad_data);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_ONE);
        CLEAR_LCD;
        LCD_NOT_READY;
        putsXLCD(LCD_test);
        LCD_NOT_READY;
    }
#endif
}

void glucose_debug(void)
{
    
    static char LCD_test[32];
#if NDEBUG_GLUCOSE
    while(1)
    {
        LED_TEST_ONE    =   1;
        LED_TEST_TWO    =   ~LED_TEST_ONE;
        adc_glucose_rslv();
        sprintf(LCD_test, "GLUC: %img/dl", adc_glucose_get());
        LCD_NOT_READY;
        SetDDRamAddr(LINE_THREE);
        CLEAR_LCD;
        LCD_NOT_READY;
        putsXLCD(LCD_test);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_TWO);
        sprintf(LCD_test, "ADC: %i", adc_measure());
        LCD_NOT_READY;
        putsXLCD(LCD_test);;
        LCD_NOT_READY;

        LED_TEST_ONE    =   0;
        LED_TEST_TWO    =   ~LED_TEST_ONE;
        Delay1KTCYx(256);
        Delay1KTCYx(256);
    }

#endif
}


void hr_debug(void)
{
#if NDEBUG_HR
     TRISBbits.TRISB2    =   1;      //make input
    TRISCbits.TRISC0    =   1;
    TRISCbits.RC0       =   1;

    countv_reset();
    time_reset();
    pnn50_reset();
    
    
    TMR0IE  =   0;
    RBPU    =   0;      //individual PULLUPS enabled
    IPEN    =   1;      //enable priority
    INT2IF  =   0;      //clear flag
    INTEDG2 =   1;      //select rising edge
    INT2IE  =   1;      //enable external interrupt
    INT2IP  =   1;
    GIE     =   1;      //enable HIGH interrupts
    PEIE    =   1;      //enable LOW interrupts
    while(1)
    {
        
    }
#endif
    return;
}
void nuke_debug(void)
{
#if NDEBUG_NUKE  
        TRISD   =   0b00000000;
        OpenXLCD(FOUR_BIT & LINES_5X7);
        LCD_NOT_READY;
        CLEAR_LCD;
        LCD_NOT_READY;
        WriteCmdXLCD(DON & BLINK_OFF);
        LCD_NOT_READY;;
        CLEAR_LCD;
        SetDDRamAddr(LINE_TWO);
        putrsXLCD("GLORY TO THE FUHRER");
        TRISCbits.TRISC2    =   0;
        OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1); 
        SetDCPWM1(DUTY_CYCLE); 
        LED_TEST_ONE = 1;
        while(1){
#if NDEBUG
            LED_TEST_TWO    =   1;
#endif
            OpenPWM1(PWM_PERIOD);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            ClosePWM1();
#if NDEBUG
            LED_TEST_TWO    =   0;
#endif
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);

        }
        
        while(1);
#endif
    return;
}

void eeprom_debug(void)
{
#if NDEBUG_MEM
    unsigned int ROM_test;
    unsigned char ROM_lcd[32];
    unsigned char kpad_data;
    unsigned int eeprom_dat[5] = {0,1,2,3,4};
    int i = 0;
    eeprom_write(eeprom_dat[0],eeprom_dat[0]);
    eeprom_write(eeprom_dat[1],eeprom_dat[1]);
    eeprom_write(eeprom_dat[2],eeprom_dat[2]);
    eeprom_write(eeprom_dat[3],eeprom_dat[3]);
    eeprom_write(eeprom_dat[4],eeprom_dat[4]);
    LED_TEST_ONE    =   1;
    i = 0;
    while(1)
    {
        LED_TEST_TWO    =   1;
        kpad_config();
        while(!PORTBbits.INT1);
        kpad_data = kpad_rslv();
        if (kpad_data == 'A')
        {
            i = i + 0x01; 
            if (i > 0x05)
            {
                i = 0x05;
            }
            ROM_test = eeprom_read(i);
            LED_TEST_TWO    =   0;
        }
        if (kpad_data == 'B')
        {
            i = i - 0x01;
            if (i < 0x00)
            {
                i = 0x00;
            }
            ROM_test = eeprom_read(i);
            LED_TEST_TWO    =   0;
        }
        TRISD   =   0b00000000;
        OpenXLCD(FOUR_BIT & LINES_5X7);
        LCD_NOT_READY;
        CLEAR_LCD;
        LCD_NOT_READY;
        WriteCmdXLCD(DON & BLINK_OFF);
        LCD_NOT_READY;;
        CLEAR_LCD;
        SetDDRamAddr(LINE_TWO);
        LCD_NOT_READY;
        sprintf(ROM_lcd, "ROM: %i", ROM_test);
        putsXLCD(ROM_lcd);
        LED_TEST_TWO    =   1;
        Delay1KTCYx(256);
        Delay1KTCYx(256);
    }
    
    
    while(1);
#endif
    return;
}