/* 
 * File:   _keypad.h
 * Author: aaadi
 *
 * Created on October 5, 2018, 7:18 PM
 */

#ifndef _KEYPAD_H
#define	_KEYPAD_H

#define kpad_dr     PORTBbits   .INT1
#define kpad_drt    TRISBbits   .TRISB1 

#define kpad_d0 PORTDbits   .RD0
#define kpad_d1 PORTDbits   .RD1
#define kpad_d2 PORTDbits   .RD2
#define kpad_d3 PORTDbits   .RD3

static unsigned char key_value;

void low_isr(void);
void read_keypad(void);
void config_keypad(void);
