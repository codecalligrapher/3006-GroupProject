#include <p18f452.h>
#include <timers.h>
#include <math.h>
#include "_functions.h"
#include "def_f842.h"

static int pnn50_cnt    =   0;
static float var = 0.0;

void pnn50_reset(void)
{
    var =   0.0;
    pnn50_cnt   =   0;
}

int pnn50_get(void)
{
    return pnn50_cnt;
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