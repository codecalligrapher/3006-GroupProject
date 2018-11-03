#include <p18f452.h>
#include <timers.h>
#include <math.h>
#include "_functions.h"
#include "def_f842.h"

extern unsigned int beats_time[60];
extern int beats;
short unsigned int RR_dif;
unsigned int beats_difference[60];

double variability(short unsigned int period)
{
    double RR_diff = 0.0;
    int var_value = 0;
    int u = 0;
    RR_dif = 0;
    
    if (period == 5)
    {
        var_value = 391;
    }
    else
    {
        var_value = 195;
    }
    
    for(u = 0; u < beats - 1; u++)
    {
        beats_difference[u] = beats_time[u +1] - beats_time[u];
        if (fabs(beats_difference[u]) > var_value)
        {
            RR_dif++;
        }
    }
    return (RR_diff/beats);
                
}