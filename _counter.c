#include <p18f452.h>
#include <timers.h>
#include <delays.h>
#include <stdio.h>
#include <xlcd.h>
#include <portb.h>
#include <timers.h>
#include "_functions.h"
#include "def_f842.h"



#pragma config OSC = XT                                                         // High-Speed oscillator
#pragma config WDT = OFF                                                        // Watchdog timer OFF
#pragma config LVP = OFF      

#define _XTAL_FREQ   4000000

#define     NDEBUG_ISR      0
#define     NDEBUG_LED      0
#define     NDEBUG_KPAD     0
#define     NDEBUG_TEMP     0
#define     NDEBUG_COUNTER  0
#define     NDEBUG          1
#define     TEMP            0
#define     HRATE           1

#define     CLEAR_LCD       WriteCmdXLCD(0x01)

static int  beat_count, i, pNN50_cnt, dbg;
static int isr_count;
unsigned int beats_time[60];
extern short unsigned int kpad_data;
extern int interval;
extern char Temperature[];
float bpm, var;
extern float finaltemp;
char LCD_temp[16];
char LCD_test[32];
char LCD_bpm[32];
char LCD_var[32];


int beats_time_LCD;


void LED_debug(void);
void temp_debug(void);
void kpad_debug(void);


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
#if NDEBUG
    LED_TEST_THREE  =   1;
#endif  
#if NDEBUG_ISR
        isr_count++;
#endif
      
    if(TMR0IF)
    {
#if NDEBUG
        LED_TEST_ONE    =   1;
#endif
        TMR0IF  =   0;
        bpm =   ReadTimer1();
        
        sprintf(LCD_bpm, "BPM: %d", ReadTimer1());
        sprintf(LCD_var, "pNN50: %d", var);
        LCD_NOT_READY;
        CLEAR_LCD;
        LCD_NOT_READY;
        SetDDRamAddr(LINE_ONE);
        LCD_NOT_READY;
        putsXLCD(LCD_bpm);
        LCD_NOT_READY;
        SetDDRamAddr(LINE_TWO);
        LCD_NOT_READY;
        putsXLCD(LCD_var);
#if NDEBUG_ISR
        sprintf(LCD_test,"ISR: %i",isr_count);
        LCD_NOT_READY;
        CLEAR_LCD;
        LCD_NOT_READY;
        SetDDRamAddr(LINE_THREE);
        LCD_NOT_READY;
        putsXLCD(LCD_test);
#endif
        WriteTimer1(0);
        WriteTimer0(0);
    }
#if NDEBUG
    LED_TEST_THREE  =  0; 
#endif
    GIE =   1;
}

void counter_measure_config(void)
{
    bpm   = 0;
    TRISBbits.TRISB0    =   1;      //make input
    PORTBbits.INT0      =   1;
    TRISCbits.TRISC0    =   1;
    TRISCbits.RC0       =   1;
    
    
    T0CON   =   0x87;
    WriteTimer0(30380);
    TMR0IE  =   1;
    RBPU    =   0;      //individual PULLUPS enabled
    IPEN    =   1;      //enable priority
    INT0IF  =   0;      //clear flag    
    WriteTimer1(0);
    OpenTimer1(TIMER_INT_OFF
                & T1_8BIT_RW
                & T1_SOURCE_EXT
                & T1_PS_1_1
                & T1_OSC1EN_OFF
                & T1_SYNC_EXT_OFF
                & T3_SOURCE_CCP
            );
    //INTEDG0 =   1;      //select rising edge
    //INT0IE  =   1;      //enable external interrupt    
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
    int LCD_put     =   0;
    isr_count       =   1;    
  
    
    //choose option for interval storage
#if NDEBUG
    LED_debug();
    temp_debug();
    kpad_debug();
#endif  

    
    TRISBbits.TRISB0 = 1;  
    
#if !NDEBUG
    while(1)
    {
#endif
#if NDEBUG
        LED_TEST_TWO    =   1;
#endif
        
#if HRATE
        counter_measure_config();
        while(1){
#if NDEBUG_COUNTER
            sprintf(LCD_test,"TEST: %i",ReadTimer1());
            CLEAR_LCD;
            LCD_NOT_READY;
            putsXLCD(LCD_test);
#endif
            
        };
#endif
       
#if NDEBUG
        LED_TEST_TWO    =   0;
#endif
        
        
#if TEMP
                temp();
                LCD_NOT_READY;
                putsXLCD(Temperature);
#endif
                //CLEAR_LCD;
                LCD_put = 0;
#if !NDEBUG
    }
#endif
    return;
}

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
    temp();
    LCD_NOT_READY;
    CLEAR_LCD;
    LCD_NOT_READY;
    SetDDRamAddr(0x40);
    sprintf(LCD_test, "Temperature: %f", finaltemp);
    LCD_NOT_READY;
    putsXLCD(LCD_test);
    LED_TEST_ONE    =   1;
    while(1);
#endif
}

void kpad_debug(void)
{
#if NDEBUG_KPAD
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