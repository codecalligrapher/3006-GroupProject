#include <p18f452.h>
#include <xlcd.h>


#pragma config  OSC     =   HS
#pragma config  WDT     =   OFF
#pragma config  BOR     =   OFF
#pragma config  PWRT    =   OFF
#pragma config  CCP2MUX =   ON
#pragma config  STVR    =   OFF
#pragma config  LVP     =   OFF
#pragma config  DEBUG   =   OFF

unsigned char read_EEPROM(unsigned char);
void write_EEPROM(unsigned char, unsigned char);

unsigned char read_EEPROM(unsigned char rom_address)
{
    while(EECON1bits.WR || EECON1bits.RD);
    EEADR               =   rom_address;
    EECON1bits.EEPGD    =   0;                  //point to DATA memory
    EECON1bits.CFGS     =   0;                  //access DATA memory
    EECON1bits.RD       =   1;                  //initiate read
    while(EECON1bits.RD);                       //wait for read to finish
    return EEDATA;
}

void write_EEPROM(unsigned char rom_address,unsigned char rom_data)
{
    char gie_stat;
    while(EECON1bits.WR == 1);                  //ensure no writes are in progress
    EEADR               =   rom_address;        //write sequence
    EEDATA              =   rom_data;
    EECON1bits.EEPGD    =   0;                  //points to DATA memory
    EECON1bits.WREN     =   1;                  //enables write to EEPROM
    gie_stat            =   INTCONbits.GIE;         //copies current GIE state
    INTCONbits.GIE      =   0;                  //disables ALL interrupts
    EECON2              =   0x55;
    EECON2              =   0xAA;
    EECON1bits.WR       =   1;
    INTCONbits.GIE      =   gie_stat;           //restores GIE status
    while(EECON1bits.WR == 1);                  //wait for write to finish
    return;            
}

struct data{
    float   h_rate;
    float   glucose;
    float   variation;
    float   temp_current;
};

void main(void)
{
    
    return;
}
