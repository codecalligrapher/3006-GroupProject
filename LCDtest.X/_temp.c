// Author: Bradley Doodnath   Group: E - Crytek

#include <p18f452.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>
#include <xlcd.h>
#include "_functions.h"
#include "def_f842.h"
#include "ow.h"

static char Temperature[30];
static unsigned char tempMSB = 0, tempLSB = 0;
static unsigned int MSBdummy = 0, LSBdummy = 0;
static unsigned int TempInteger = 0, FractionInt = 0;
static unsigned char Deg = 0xB0;
static char LCD_count[32];
static unsigned int fraction = 0;
static unsigned float finaltemp = 0.0000;
static float TempSum = 0.0000 , TempAvg = 0.000;
static char Temperature[30];
static int i = 0, count = 0;
static unsigned int multipler = 0;

unsigned int temp_get_int(void)
{
#if NDEBUG_MEM_STORE
    TempInteger =   32;   
#endif    
    return TempInteger;
}

unsigned int temp_get_fraction(void)
{
    unsigned int frac_temp;
#if NDEBUG_MEM_STORE
    fraction = 15;    
#endif
    frac_temp = fraction*multipler;
    return frac_temp;
}

void tempread()                             // Read Temperature Sensor
{
        ow_reset();                             //reset device
        ow_write_byte(0xCC);                    //Skip ROM check
        ow_write_byte(0x44);                    //Start conversion
        for (i=1; i<=3; i = i + 1 )
        {
            Delay10KTCYx(102);                  //wait for conversion
        }                                       //approx 760 for enough time   
        
        ////////////////////////////////////////////////////////////////////////
        
        ow_reset();                             //reset device
        ow_write_byte(0xCC);                    //skip ROM check
        ow_write_byte(0xBE);                    //read from scratchpad
        tempLSB = ow_read_byte();
        tempMSB = ow_read_byte();               //store in two variables
        
        //scratchpad sends the other 7 bytes but they are not needed for the...
        //code so we would not read them
        
        ////////////////////////////////////////////////////////////////////////
        ////////        Calculation            /////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        
        MSBdummy= tempMSB << 4;                 //calculate integer
        LSBdummy= tempLSB >> 4;
        TempInteger= MSBdummy | LSBdummy;
       
        if(tempLSB & 0x01){fraction += 0.0625; multipler = 10000;} //calculate fraction
        if(tempLSB & 0x02){fraction += 0.125; multipler = 1000;}
        if(tempLSB & 0x04){fraction += 0.25; multipler = 100;}
        if(tempLSB & 0x08){fraction += 0.5; multipler = 10;}
        finaltemp= TempInteger + fraction;      //Final temp calculation
        return;
}


void temp(void)
{
    unsigned char tempMSB, tempLSB = 0;
    unsigned int MSBdummy, LSBdummy = 0;
    
    unsigned char Deg= 0xB0;
    
    
    int i=0;
    
   
        ow_reset();                             //reset device
        ow_write_byte(0xCC);                    //Skip ROM check
        ow_write_byte(0x44);                    //Start conversion
        for (i=1; i<=3; i = i + 1 )
        {
            Delay10KTCYx(102);                  //wait for conversion
        }                                       //approx 760 for enough time   
        
        ////////////////////////////////////////////////////////////////////////
        
        ow_reset();                             //reset device
        ow_write_byte(0xCC);                    //skip ROM check
        ow_write_byte(0xBE);                    //read from scratchpad
        tempLSB = ow_read_byte();
        tempMSB = ow_read_byte();               //store in two variables
        
        //scratchpad sends the other 7 bytes but they are not needed for the...
        //code so we would not read them
        
        ////////////////////////////////////////////////////////////////////////
        ////////        Calculation            /////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        
        MSBdummy= tempMSB << 4;                 //calculate integer
        LSBdummy= tempLSB >> 4;
        TempInteger= MSBdummy | LSBdummy;
       
        if(tempLSB & 0x01){fraction += 0.0625;} //calculate fraction
        if(tempLSB & 0x02){fraction += 0.125;}
        if(tempLSB & 0x04){fraction += 0.25;}
        if(tempLSB & 0x08){fraction += 0.5;}
        
        finaltemp= TempInteger + fraction;      //Final temp calculation
        
                                               //store as string to print on LCD
        //sprintf(Temperature, "TEMP: +%.4f%cC", finaltemp,Deg);     
        sprintf(Temperature, "TEMP: +%.4f%cC", finaltemp,Deg);     
    
        return;
}


void tempinit()                             // Find average of 50 values to...
                                            // ...calibrate temperature measure
{               
    TRISD   =   0b00000000;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    LCD_NOT_READY;
    while (count < 50)
    {
        LED_TEST_ONE    =   ~LED_TEST_ONE;
        tempread();
        
        TempSum = TempSum + finaltemp;      //Calculating sum of temp
        count = count + 1;
         
    }
    
    TempAvg = TempSum / count;    
    return;
}