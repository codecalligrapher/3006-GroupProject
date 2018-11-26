#include <p18f452.h>
#include <xlcd.h>
#include <stdio.h>
#include <delays.h>
#include <timers.h>
#include "_functions.h"
#include "def_f842.h"


#define DATA_PORT               PORTD
#define TRIS_DATA_PORT          TRISD

#define RW_PIN   LATAbits.LATA1           /* PORT for RW */
#define TRIS_RW  TRISAbits.TRISA1         /* TRIS for RW */

#define RS_PIN   LATAbits.LATA2           /* PORT for RS */
#define TRIS_RS  TRISAbits.TRISA2         /* TRIS for RS */

#define E_PIN    LATAbits.LATA0          /* PORT for D  */
#define TRIS_E   TRISAbits.TRISA0        /* TRIS for E  */



//----------------------------FUNCTION PROTOTYPES-----------------------------//

void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD (void);
void abort(void);



#pragma code
void abort()
{
    WriteTimer0(0);
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);
    LCD_NOT_READY;
    putrsXLCD("MEASUREMENT        ABORTED");
    Delay10KTCYx(10000000);
    return;
}

void LCD_config(void)
{
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    WriteCmdXLCD(0x01);
    LCD_NOT_READY;
    return;
}

/* LCD DELAY FUNCTIONS*/
void DelayFor18TCY(void)
{
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    return;

}

void DelayPORXLCD(void)
{
    Delay1KTCYx(25);    // Delay of 15ms
                        // Cycles = (TimeDelay * Fosc) / 4
                        // Cycles = (15ms * 4MHz) / 4
                        // Cycles = 15,000
    return;
}

void DelayXLCD (void)
{
    Delay1KTCYx(30);    // Delay of 5ms
                        // Cycles = (TimeDelay * Fosc) / 4
                        // Cycles = (5ms * 4MHz) / 4
                        // Cycles = 5,000
    return;
}
