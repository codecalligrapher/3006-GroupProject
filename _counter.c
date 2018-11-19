#include <p18f452.h>
#include <timers.h>
#include <delays.h>
#include <stdio.h>
#include <xlcd.h>
#include <portb.h>
#include <timers.h>
#include <spi.h>
#include "_functions.h"
#include "def_f842.h"

#pragma config OSC = XT                                                         // High-Speed oscillator
#pragma config WDT = OFF                                                        // Watchdog timer OFF
#pragma config LVP = OFF

#define _XTAL_FREQ   4000000


static int  i;
extern short unsigned int kpad_data;
extern char Temperature[];
extern float finaltemp;
static char LCD_temp[16];
static char LCD_bpm[32];
static char LCD_rate[32];
static char LCD_var[32];
static char LCD_test[32];
static char LCD_gluc[32];
static unsigned char interval_valid =   0;
static unsigned char action_valid    =   0;
static unsigned char store_valid    =   0;
static unsigned char action;
static unsigned int addr_scroll;


#pragma code high_vector=0x08
void high_vector(void)
{
    _asm GOTO h_isr _endasm
}

#pragma code
#pragma interrupt h_isr save=PROD
void h_isr(void)
{
    GIE =   0;

    if (INT2IF)
    {
#if NDEBUG
    LED_TEST_THREE  =   ~LED_TEST_THREE;
#endif
        INT2IF  =   0;
        time2_set(time_get());
        time_set(ReadTimer0());
        pnn50_calc(time_get(), time2_get());
        countv_incr();
#if NDEBUG_PNN50
        LCD_NOT_READY;
        CLEAR_LCD;
        SetDDRamAddr(LINE_THREE);
        sprintf(LCD_test, "PREV: %u", time2_get());
        LCD_NOT_READY;
        putsXLCD(LCD_test);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_TWO);
        sprintf(LCD_test, "CURR: %u", time_get());
        LCD_NOT_READY;
        putsXLCD(LCD_test);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_THREE);
        sprintf(LCD_test, "VAR CNT: %i", pnn50_get_cnt());
        LCD_NOT_READY;
        putsXLCD(LCD_test);     
        
#endif
#if NDEBUG_COUNTER
        LCD_NOT_READY;
        SetDDRamAddr(LINE_ONE);
        sprintf(LCD_test,"COUNT: %u, TIME: %u", countv_get(), ReadTimer0());
        LCD_NOT_READY;
        putsXLCD(LCD_test);
#endif
    }
#if 0
    LED_TEST_THREE  =  0;
#endif
    GIE =   1;
}

void counter_measure_config(void)
{
    TRISBbits.TRISB2    =   1;      //make input
    TRISCbits.TRISC0    =   1;
    TRISCbits.RC0       =   1;

    countv_reset();
    time_reset();
    pnn50_reset();
    
    T0CON   =   0x87;
    WriteTimer0(6942);
    TMR0IE  =   0;
    RBPU    =   0;      //individual PULLUPS enabled
    IPEN    =   1;      //enable priority
    INT2IF  =   0;      //clear flag
    INTEDG2 =   1;      //select rising edge
    INT2IE  =   1;      //enable external interrupt
    INT2IP  =   1;
    GIE     =   1;      //enable HIGH interrupts
    PEIE    =   1;      //enable LOW interrupts
    return;
}

double counter_bpm(void)
{
    int count_temp  =   ReadTimer1();
    return (count_temp*6);
}


void main(void)
{
    static unsigned int interval_store_cnt  =   0;
    static unsigned int eeprom_loc_temp     =   0x0;
    int i = 0, j = 0;
    set_invalid_int();
#if NDEBUG
    
    
    LED_debug();
    eeprom_debug();
    temp_debug();
    kpad_debug();
    glucose_debug();
    nuke_debug();
    
    for (i = 0; i < 0xFF; i++)
    {
        LED_TEST_ONE    =   ~LED_TEST_ONE;
        eeprom_write(i,i);
    }
#endif    
#if NDEBUG
    LED_TEST_ONE    =   1;
#endif
    while(!interval_valid)
    {
#if NDEBUG
    LED_TEST_TWO    =   1;
#endif
        interface_interval();
        kpad_config();
        while(!PORTBbits.INT1);
        eeprom_store_interval(kpad_rslv());
        eeprom_set_next(0x00);
#if NDEBUG
    LED_TEST_TWO    =   0;
#endif
        CLEAR_LCD;
    }
    Delay1KTCYx(256);
    Delay1KTCYx(256);
#if NDEBUG
    LED_TEST_ONE    =   0;
#endif
    
    TRISBbits.TRISB0 = 1;


    while(1)
    {
        set_invalid_action();

#if NDEBUG
        LED_TEST_TWO    =   1;
#endif        
        while(!get_action_valid())
        {
            interface_action();
            kpad_config();
            while(!PORTBbits.INT1);
            action = kpad_rslv();
            CLEAR_LCD;
#if NDEBUG
          LED_TEST_TWO    =   0;
#endif
            switch(action)
            {
                case 'A':
                    set_valid_action();
                    interval_store_cnt = interval_store_cnt + 1;
#if TEMP
                    temp();                  
#endif       
                    putrsXLCD("MEASURING");
#if HRATE
                    
                    counter_measure_config();
#if NDEBUG
          LED_TEST_TWO    =   1;
#endif
                    //while(!TMR0IF);
#if NDEBUG
          LED_TEST_TWO    =   0;
#endif
#endif
#if GLUC
                    
#endif
#if NDEBUG
           LED_TEST_ONE    =   1;
#endif
                    GIE  =   0;
                    TMR0IF  =   0;        
                    sprintf(LCD_rate, "BPM: %u", countv_get_rate());
                    sprintf(LCD_var, "pNN50: %i%%",pnn50_get());
                    sprintf(LCD_temp, "TEMP: %i.%i", temp_get_int(),temp_get_fraction());
                    sprintf(LCD_gluc, "GLUCOSE: %i", adc_glucose_get());
                    LCD_NOT_READY;
                    CLEAR_LCD;
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
                    dly_8s();
#if ROM
                    if (eeprom_get_interval() == interval_store_cnt)
                    {
                        interface_display_abort();
#if NDEBUG
                        
                        LED_TEST_ONE    =   0;
#endif
                        set_invalid_store();                        
                        kpad_config();                        
                        while(!PORTBbits.INT1);
                        kpad_data = kpad_rslv();
                        while (!get_store_valid())
                        {
                            kpad_config();
                            while(!PORTBbits.INT1);
                            kpad_data = kpad_rslv();
                            if (kpad_data == 'A')
                            {
                                
                                //eeprom_write_data(eeprom_get_next());
                                eeprom_write(countv_get_rate(),eeprom_get_next());
                                eeprom_write(pnn50_get(),eeprom_get_next() + 0x01);
                                eeprom_write(temp_get_int(),eeprom_get_next() + 0x02);
                                eeprom_write(temp_get_fraction(),eeprom_get_next() + 0x03);
                                eeprom_write(adc_glucose_get(),eeprom_get_next() + 0x04);                                
                                
                                eeprom_set_next(eeprom_get_next() + 0x05);                                
                                set_valid_store();
                                CLEAR_LCD;
                                LCD_NOT_READY;
                                SetDDRamAddr(LINE_TWO);
                                LCD_NOT_READY;
                                putrsXLCD("STORE SUCCESSFUL");
                                dly_2s();                                   
#if NDEBUG
                        
                        LED_TEST_ONE    =   1;
#endif
                            }
                            
                            if (kpad_data == 'B')
                            {
                                CLEAR_LCD;
                                LCD_NOT_READY;
                                SetDDRamAddr(LINE_TWO);
                                LCD_NOT_READY;
                                set_valid_store();
                                putrsXLCD("STORAGE ABORTED");
                                dly_2s();
                                dly_2s();
                            }
                        }
#if NDEBUG
                        
                        LED_TEST_ONE    =   0;
#endif                       
                        
                        interval_store_cnt  =   0;
                                               
                    }
#endif
                    dly_8s();
                    CLEAR_LCD;
                    countv_reset();
                    time_reset();
                    time2_reset();
                    WriteTimer0(0);     
            
#if NDEBUG
    LED_TEST_ONE  =  0;
#endif             
                    break;
                case 'B':
                    set_valid_action();
                    CLEAR_LCD;
                    kpad_config();
                    while(!PORTBbits.INT1);
                    kpad_data = kpad_rslv();
                    addr_scroll =   0;
                    while(kpad_data != 'D')
                    {                        
                        //interface_display_stored(addr_scroll);
                        interface_set_rate(eeprom_read(addr_scroll));
                        interface_set_pnn50(eeprom_read(addr_scroll + 0x01));
                        interface_set_temp_int(eeprom_read(addr_scroll + 0x02));
                        interface_set_temp_fraction(eeprom_read(addr_scroll + 0x03));
                        interface_set_gluc(eeprom_read(addr_scroll + 0x04));
                        interface_display_stored(addr_scroll);
                        kpad_config();
                        Delay1KTCYx(256);
                        Delay1KTCYx(256);
                        while(!PORTBbits.INT1);
                        kpad_data = kpad_rslv();                        
                        if (kpad_data == 'A')
                        {
#if NDEBUG
                        
                        LED_TEST_ONE    =   1;
                        Delay1KTCYx(256);
                        LED_TEST_ONE    =   0;
#endif
                            addr_scroll = addr_scroll + 0x05;
                            if (addr_scroll > 0xEF)
                            {
                                addr_scroll =   0x00;
                            }
                  
                        }
                        
                        if (kpad_data == 'B')
                        {
#if NDEBUG
                        
                        LED_TEST_TWO    =   1;
                        Delay1KTCYx(256);
                        LED_TEST_TWO    =   0;
#endif
              
                            addr_scroll = addr_scroll - 0x05;
                            if (addr_scroll < 0x00)
                            {
                                addr_scroll = 0x0;
                            }
#if NDEBUG
                        
                        LED_TEST_TWO    =   0;
#endif
                            
                            
                        }   
                        
                    }
                    
                    break;
                default:                    
                    set_invalid_action();
                    LCD_NOT_READY;
                    CLEAR_LCD;
                    LCD_NOT_READY;
                    SetDDRamAddr(LINE_ONE);
                    LCD_NOT_READY;
                    putrsXLCD("INVALID");
                    SetDDRamAddr(LINE_TWO);
                    LCD_NOT_READY;
                    putrsXLCD("TRY AGAIN");
                    dly_2s();
                    break;
                   
            }
        }        
    }

    return;
}

void set_valid_int(void)
{
    interval_valid  =   1;
    return;
}

void set_invalid_int(void)
{
    interval_valid  =   0;
    return;
}

short unsigned int get_valid_int(void)
{
    return interval_valid;
}

void set_valid_action(void)
{
    action_valid    =   1;
    return;
}

void set_invalid_action(void)
{
    action_valid    =   0;
    return;
}

unsigned char get_action_valid(void)
{
    return action_valid;
}



unsigned char get_store_valid(void)
{
    return store_valid;
}

void set_valid_store(void)
{
    store_valid =   1;
    return;
}

void set_invalid_store(void)
{
    store_valid =   0;
    return;
}


void dly_8s(void)
{
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
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    return;
}

void dly_2s(void)
{
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    return;
}

void dly_1s(void)
{
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    Delay1KTCYx(256);
    return;
}