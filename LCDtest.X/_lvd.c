/***************************************************************************
 * File Name:   _lvd.c
 * Author:      Brandon Jodha
 * NOTE: Module NOT implemented
 * 
 * Function:
 *      lvd_config
 *          Input:      NONE
 *          Output:     NONE
 *          Process:    
                        Configures LVD module and enables LVD interrupt
 * **************************************************************************/

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f452.h>
#include "_lvd.h"


void lvd_config(void)
{
    _LVDIE  =   0;                              //disables LVD interrupt
    
    _LVLD3  =   1;                              //configures low voltage between 3.8-4.03V
    _LVLD2  =   0;
    _LVLD1  =   1;
    _LVLD0  =   1;
    
    _LVDEN  =   1;                              //enables Low Voltage Detect
    
    while(!_IRVST);                             //waits for stabilise
    
    _LVDIF  =   0;                              //clear LVD flag
    _LVDIE  =   1;                              //enables LVD interrupt
    INTCONbits.GIE  =   1;
    
    return;
}

#if 0
void main(void)
{
    lvd_config();
    return;
}
#endif
