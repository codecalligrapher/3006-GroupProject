/***************************************************************************
   File Name:   _speaker.c
   Author:      Brandon Jodha
   
   Function:
        speaker_init
            Input:      NONE
            Output:     NONE
            Process:    
                        Configures Timer2 for PWM
                        Configures TRISC2 for Output 
                        Sets PWM2 Duty Cycle 
                        Opens PWM2
                              
        speaker_alarm_seq
            Input:      NONE
            Output:     NONE
            Process:    
                        Initialises speaker 
                        Plays alarm sequence

        speaker_alarm           
            Input:      NONE 
            Output:     NONE 
            Process:
                        Calls alarm sequence if HR, HRV or Glucose Flag bits 
                        set
 ****************************************************************************/
#include <p18f452.h>
#include <xlcd.h>
#include <delays.h>
#include <stdio.h>
#include "_functions.h"
#include "def_f842.h"
#include <pwm.h>
#include <timers.h>



#define     HEART_TROUBLE       (countv_get_rate() > 120) | (countv_get_rate() < 30)
#define     HEART_UNSTABLE      (pnn50_get() > 50)
#define     GLUCOSE_UNSTABLE    (adc_glucose_get() > 140) | (adc_glucose_get() < 70)

void speaker_init(void) 
{

        TRISCbits.TRISC2    =   0;
        LED_TEST_ONE = 1;
        OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1); 
        SetDCPWM1(DUTY_CYCLE); 
        
#if NDEBUG_NUKE  
        OpenPWM1(PWM_PERIOD);
        while(1);
#endif
    return;
}

void speaker_alarm_seq(void)
{
    static int i,j = 0;
    speaker_init();
    
    for (i= 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
#if NDEBUG
            LED_TEST_ONE    =   ~LED_TEST_ONE;
#endif 
            OpenPWM1(PWM_PERIOD);
            Delay1KTCYx(256);
            ClosePWM1();
            Delay1KTCYx(256);
        }
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
        Delay1KTCYx(256);
    }
    ClosePWM1();
    return;
}

void speaker_alarm(void)
{
    if (HEART_TROUBLE | HEART_UNSTABLE | GLUCOSE_UNSTABLE)
    {
        speaker_alarm_seq();
    }
    return;
}
