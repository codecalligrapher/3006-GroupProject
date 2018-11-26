/* 
 * File:   lcd_head.h
 * Author: aaadi
 *
 * Created on September 20, 2018, 1:18 PM
 */
#include <p18f452.h>
#include <p18cxxx.h>
    unsigned char BusyXLCD(void);
    void OpenXLCD(unsigned char lcdtype);
    void putsXLCD(char *buffer);
    void putrsXLCD(const rom char *buffer);
    unsigned char ReadAddrXLCD(void);
    char ReadDataXLCD(void);
    void SetCGRamAddr(unsigned char addr);
    void setDDRamAddr(unsigned char addr);
    void WriteCmdXLCD(unsigned char cmd);
    void WriteDataXLCD(char data);
    
    /*Delay Functions*/
    void DelayFor18TCY(void);
    void DelayPORXLCD(void);
    void DelayXLCD (void);


