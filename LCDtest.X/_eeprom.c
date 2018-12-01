/***************************************************************************
 * File Name:   _eeprom.c
 * Author:      Aadidev Sooknanan
 * 
 * Function:
 *      eeprom_write_data
 *          Input:      EEPROM Address (int)
 *          Output:     NONE
 *          Process:    
                        Calls getter functions for:
                          Pulse count
                          HRV 
                          Temperature 
                          Glucose 
                        Writes returned values to five consecutive EEPROM 
                        locations beginning from EEPROM Address
                        
                                                
 *      eeprom_store_interval
 *          Input:      Option for Interval (char)
 *          Output:     NONE
 *          Process:    
                        Writes input parameter to EE_LOC_INTERVAL address 
                        Provides error-catching for invalid choice of interval
                        
       eeprom_display_data
            Input:      EEPROM Address (int)
            Output:     NONE 
            Process:
                        Reads five consecutive memory locations beginning from 
                        EEPROM Address and calls _interface.c setters for each
                        read value
                        
      eeprom_write
            Input:      Data (int) Address (int) 
            Output:     NONE 
            Process:    
                        Performs EEPROM Write Sequence 
                        Writes Data to Address 

     eeprom_reead
            Input:      Address (int) 
            Output:     Data (char) 
            Process:
                        Performs EEPROM Read Sequence 
                        Returns read data

    Getters and setters for Interval and next available memory location


    Variable Listing:
            addr_1:addr_5   -    stores consecutive EEPROM Addresses
            interval_store  -   used as a buffer between main and the EEPROM
 * **************************************************************************/

#include <p18f452.h>
#include <delays.h>
#include "_functions.h"
#include "def_f842.h"

static int addr_1;
static int addr_2;
static int addr_3;
static int addr_4;
static int addr_5;
static unsigned int interval_store   =   0;

void eeprom_write_data(unsigned int addr)
{
    addr_1  =   addr;
    addr_2  =   addr + 1;
    addr_3  =   addr + 2;
    addr_4  =   addr + 3;
    addr_5  =   addr + 4;
    eeprom_write(countv_get_rate(),addr_1);
    eeprom_write(pnn50_get,addr_2);
    eeprom_write(temp_get_int(), addr_3);
    eeprom_write(temp_get_fraction(),addr_4);    
    //eeprom_write(gluc_get(),addr_5);
    return;
}

void eeprom_store_interval(char interval_option)
{
    
    switch(interval_option)
    {
        case 'A':
            interval_store =   1;
            eeprom_write(1,EE_LOC_INTERVAL);
            set_valid_int();
            break;
        case 'B':
            interval_store  =   2;
            eeprom_write(2, EE_LOC_INTERVAL);
            set_valid_int();
            break;
        case 'C':
            interval_store  =   5;
            eeprom_write(5,EE_LOC_INTERVAL);
            set_valid_int();
            break;
        case 'D':
            interval_store  =   10;
            eeprom_write(10, EE_LOC_INTERVAL);
            
            set_valid_int();
            break;
        default:
            
            CLEAR_LCD;
            set_invalid_int();
            SetDDRamAddr(LINE_TWO);
            putrsXLCD("INVALID OPTION");
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            CLEAR_LCD;
            putrsXLCD("TRY AGAIN");
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            Delay1KTCYx(256);
            CLEAR_LCD;            
            break;
    }
    return;
}

void eeprom_display_data(int addr)
{
    addr_1  =   addr;
    addr_2  =   addr + 1;
    addr_3  =   addr + 2;
    addr_4  =   addr + 3;
    addr_5  =   addr + 4;
    interface_set_rate(eeprom_read(addr_1));
    interface_set_pnn50(eeprom_read(addr_2));
    interface_set_temp_int(eeprom_read(addr_3));
    interface_set_temp_fraction(eeprom_read(addr_4));
    interface_set_gluc(eeprom_read(addr_5));
    return;
}

void eeprom_write(unsigned int data, unsigned int addr)
{
    unsigned char GIE_temp  =   GIE;
    EEPGD   =   0;
    CFGS    =   0;
    GIE     =   0;
    while(WR);
    EEADR   =   addr;
    EEDATA  =   data;
    WREN    =   1;  
   
    EECON2  =   0x55;
    EECON2  =   0xAA;
    WR      =   1;
    while(WR);
    WREN    =   0;
    EEIF    =   0;
    GIE =   GIE_temp;
    EEPGD   =   1;
    return;
}

unsigned char eeprom_read(unsigned int addr)
{
    
    while(RD||WR);
    EEADR   =   addr;
    EEPGD   =   0;
    CFGS    =   0;
    RD      =   1;
    while(RD);
    EEPGD   =   1;
    return EEDATA;
}

unsigned int eeprom_get_interval(void)
{
    interval_store  =   eeprom_read(EE_LOC_INTERVAL);
    return interval_store;
}

void eeprom_set_next(unsigned int next_loc)
{
    eeprom_write(next_loc, 0xFF);
    return;
}

unsigned int eeprom_get_next(void)
{
    return eeprom_read(0xFF);
}
