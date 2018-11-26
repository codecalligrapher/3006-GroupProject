// Author: Bradley Doodnath   Group: E - Crytek

#include <p18f452.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>
#include "ow.h"

#pragma config WDT = OFF                    //Disable watchdog timer
#pragma config LVP = OFF                    //Disable low voltage programming

#define _XTAL_FREQ 4000000UL

static unsigned char tempMSB = 0, tempLSB = 0;
static unsigned int MSBdummy = 0, LSBdummy = 0;
static unsigned int TempInteger = 0, FractionInt = 0;
static unsigned char Deg = 0xB0;
static float fraction = 0.0000, finaltemp = 0.0000;
static float TempSum = 0.0000 , TempAvg = 0.000;
static char Temperature[30];
static int i = 0, count = 0;



void tempread()                             // Read Temperature Sensor
{
    
    
    while (1)
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
       
        if(tempLSB & 0x01){fraction += 0.0625;} //calculate fraction
        if(tempLSB & 0x02){fraction += 0.125;}
        if(tempLSB & 0x04){fraction += 0.25;}
        if(tempLSB & 0x08){fraction += 0.5;}
        finaltemp= TempInteger + fraction;      //Final temp calculation
        
    }
}

void tempinit()                             // Find average of 400 values to...
                                            // ...calibrate temperature measure
{                                               
    while (count < 400)
    {
        tempread();
        TempSum = TempSum + finaltemp;      //Calculating sum of temp
        count = count + 1;
    }
    
    TempAvg = TempSum / count;    
}

void tempOut()                              // Calculate and Output running avg
{
    count = count + 1;
    TempSum = TempSum + finaltemp;
    TempAvg = TempSum/count;
    TempInteger = TempAvg;
    fraction = TempAvg - TempInteger;
    
    FractionInt = 1000 * fraction ;
    
                                            //store as string to print on LCD
    
    sprintf(Temperature, "+%d.%03dcC", TempInteger, FractionInt,Deg);     
    
}

void main()
{
    tempinit();
    tempread();
    tempOut();
           
}