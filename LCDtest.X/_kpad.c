/***************************************************************************
 * File Name:   _kpad.c
 * Author:      Bradley Doodnath
 * 
 * Function:
 *      kpad_rslv
 *          Input:      NONE
 *          Output:     Keypress (char)
 *          Process:    
                        LUT via if-else statements matching keypad data bus 
                        to ASCII characters
                              
 *      kpad_config
   *        Input:      NONE
 *          Output:     NONE
 *          Process:    
                        Configures keypad data bus and data ready line as Input
                        Clears input line interrupt (INT1)

    Variable Listing:
            kpad_data - used in debugging to buffer read data 
 * **************************************************************************/
#include <p18f452.h>
#include <stdio.h>
#include <xlcd.h>
#include "def_f842.h"
#include "_functions.h"

#define KPAD_DATA_NOT_READY     while(!kpad_rdyt);
#define data_rdy    INTCON3bits.INT2IF


//-----------------------------GLOBAL VARIABLES-------------------------------//
short unsigned int kpad_data;

 
#pragma code
char kpad_rslv(void)
{
    if (kpad_d0 && kpad_d1 && kpad_d2 && kpad_d3)
    {
        return 'D';
    }
    if (kpad_d1 && kpad_d2 && kpad_d3)
    {
        return 'C';
    }
    if (kpad_d0 && kpad_d1 && kpad_d2)
    {
        return '0';
    }
    if (kpad_d0 && kpad_d1 && kpad_d3)
    {
        return '#';
    }
    if (kpad_d0 && kpad_d2 && kpad_d3)
    {
        return 'B';
    }
    
    if (kpad_d2 && kpad_d3)
    {
        return 'A';
    }
    if (kpad_d0 && kpad_d2)
    {
        return '5';
    }
    if (kpad_d0 && kpad_d3)
    {
        return '6';
    }
    if (kpad_d1 && kpad_d2)
    {
        return '8';
    }
    if (kpad_d1 && kpad_d3)
    {
        return '9';
    }
    if (kpad_d0 && kpad_d1)
    {
        return '*';
    }
    
    if (kpad_d2)
    {
        return '2';
    }
    if (kpad_d3)
    {
        return '3';
    }
    if (kpad_d0)
    {
        return '4';
    }
    if (kpad_d1)
    {
        return '7';
    }
    else
    {
        return '1';
    }
    
}

void kpad_config(void)
{
    kpad_t0     =   1;
    kpad_t1     =   1;
    kpad_t2     =   1;
    kpad_t3     =   1;
    kpad_data   =   0;
    TRISBbits.TRISB1    =   1;
    RBPU                =   0;
    INT1IP              =   0;
    IPEN                =   1;
    INT1IF              =   0;
    INTEDG1 =       1;     
    INT1IE  =       1;  
    return;
}