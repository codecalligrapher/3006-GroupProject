#include <p18f452.h>
#include <timers.h>
#include <math.h>
#include "_functions.h"
#include "def_f842.h"

static unsigned int countv_beats    = 0;
static unsigned int countv_time     = 0;
static unsigned int countv_time2    = 0;
/***************************************************************************
 * File Name: _counter.c
 * Function:    Setters, Getters, Incrementers and reset functions for 
 *              pulse counting 
 * 
 *              Setters, Getters, Incrementers and reset functions for 
 *              pNN50 variables (time and time2 - current and previous
 *              time respectively)
 * 
 * Variable listing:    
 *              countv_beats    -   primary pulse counter
 *              countv_time     -   stores value of Timer0 on current pulse
 *              countv_time2    -   stores value of Timer0 on previous pulse 
 * **************************************************************************/
void countv_incr(void)
{
    countv_beats++;
    return;
}

int countv_get(void)
{
    return countv_beats;
}

void countv_reset(void)
{
    countv_beats = 0;
    return;
}

int countv_get_rate(void)
{
#if NDEBUG_MEM_STORE
    countv_beats    =   15;
#endif

#if NDEBUG_HR_STABLE
    return 60;
#endif
    
#if NDEBUG_HR_UNSTABLE
    return 25;
#endif
    
    //return (4*countv_beats);
    return (2*countv_beats);
}

void time_set(int timer_value)
{
    countv_time = timer_value;
    return;
}

int time_get(void)
{
    return countv_time;
}

void time_reset(void)
{
    countv_time =   0;
    return;
}

void time2_reset(void)
{
    countv_time2    =   0;
    return;
}
int time2_get(void)
{
    return countv_time2;
}
void time2_set(int timer_value)
{
    countv_time2    =   timer_value;
    return;
}
