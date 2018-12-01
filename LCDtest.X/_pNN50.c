/***************************************************************************
   File Name:   _pNN50.c
   Author:      Aadidev Sooknanan 
   
   Function:
        pnn50_calc
            Input:      Current Time(int), Previous Time (int)
            Output:     NONE
            Process:    
                        Increments HRV counters if difference between times is
                        greater than 195
                              
        pnn50_var
            Input:      NONE
            Output:     HRV (float)
            Process:    
                        Divides HRV counter by net number or heartbeats

        Getters, setters and resetters for pnn50_cnt and HRV 
        
    Variable Listing:
            pnn50_cnt  -  HRV Counter 
            var        - HRV 
 ****************************************************************************/
#include <p18f452.h>
#include <timers.h>
#include <math.h>
#include "_functions.h"
#include "def_f842.h"

static int pnn50_cnt;
static float var;

void pnn50_reset(void)
{
    var =   0.0;
    pnn50_cnt   =   0;
}

void pnn50_calc(int time1, int time2)
{
    if((time1 - time2) > FIFTY_MSECOND_PS_1_256)
    {
        pnn50_cnt++;
    }
    return;
}

float pnn50_var(void)
{
    var = (pnn50_cnt/countv_get());
    return var;                
}

unsigned int pnn50_get(void)
{
#if NDEBUG_MEM_STORE
    return  10;    
#endif
#if NDEBUG_HRV_STABLE
    return 5;
#endif
    
#if NDEBUG_HRV_UNSTABLE
    return 65;
#endif
    
    return (int)((pnn50_cnt/countv_get())*10);
}

unsigned int pnn50_get_cnt(void)
{
    return pnn50_cnt;
}

unsigned int pnn50_get_int(void)
{
    unsigned int var_temp = (int) var;
    return var_temp;
}

unsigned int pnn50_get_fraction(void)
{
    unsigned int var_temp = (int) (var*10);
    var_temp = var_temp%10;
    return var_temp;
}