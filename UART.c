#include <p18f452.h>
#include <delays.h>
#include <sw_uart.h>

#pragma config OSC = XT                                                         // High-Speed oscillator
#pragma config WDT = OFF                                                        // Watchdog timer OFF
#pragma config LVP = OFF                                                        // Low-voltage programming OFF
#pragma config PWRTE = OFF                                                      // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON                                                       // Brown-out Reset Enable bit (BOR enabled)
#pragma config CPD = OFF                                                        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF                                                        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF                                                         // Flash Program Memory Code Protection bit (Code protection off)
// End of configuration

#define _XTAL_FREQ 4000000                                                      // 4MHz crystal
#define BAUD    9600
_asm
        SWTXD           equ     PORTC           ; Transmit pin port and pin
        SWTXDpin        equ     6
        TRIS_SWTXD      equ     TRISC           ; Transmit pin tris and pin
        SWRXD           equ     PORTC           ; Receive pin port and pin
        SWRXDpin        equ     7
        TRIS_SWRXD      equ     TRISC           ; Receive pin tris and pin
_endasm
             
                
                
void main(void)
{   
    char data;            
    OpenUART();                 //configure software UART
}
       
void DelayTXBitUART(void) 
 { 
    char d_time = (((((2*_XTAL_FREQ)/(4*BAUD))+1)/2)-12)/10; 
    Delay10TCYx(d_time); 
    return; 
 } 

 void DelayRXHalfBitUART(void) 
 { 
    char d_time = (((((2*_XTAL_FREQ)/(8*BAUD))+1)/2)-9)/10; 
    Delay10TCYx(d_time); 
    return; 
 } 
 void DelayRXBitUART(void) 
 { 
    char d_time = (((((2*_XTAL_FREQ/(4*BAUD))+1)/2)-14)/10; 
    Delay10TCYx(d_time); 
    return; 
 }
