#include <p18f452.h>
#include <delays.h>

//Configuration Bits
#pragma config OSC = XT                                                         // High-Speed oscillator
#pragma config WDT = OFF                                                        // Watchdog timer OFF
#pragma config LVP = OFF                                                        // Low-voltage programming OFF
#pragma config PWRT = OFF                                                       // Power-up Timer Enable bit (PWRT enabled)
#pragma config CPD = OFF                                                        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
// End of configuration

#define _XTAL_FREQ  4000000                                                      // 4MHz crystal

void configADC_i(void);
void confidADC(void);
int calcTacq(int, float);
void high_isr(void);


#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
    _asm GOTO high_isr _endasm
}

#pragma interrupt high_isr save=PROD
void high_isr(void)
{
    INTCONbits.GIE  =   0;
    if (PIR1bits.ADIF)
    {
        PIR1bits.ADIF   =   0;       
    }    
}


/******************************************************************************
*   PROCEDURE:  configADC_1
*   INPUTS:     NONE
*   OUTPUTS:    NONE
*   DESCRIPTION:
*               Clears A/D Interrupt Flag 
*               Configures A/D interrupts
*                   PEIE    -   peripheral interrupts enabled
*                   GIE     -   global interrupts enabled
*                   ADIE    -   ADC interrupt enable
*******************************************************************************/
void configADC_i(void)
{
    PIR1bits.ADIF   =   0;   
    PIE1bits.ADIE   =   1;
    INTCONbits.GIE  =   1;
    INTCONbits.PEIE =   1;
}

/******************************************************************************
*   PROCEDURE:  configADC
*   INPUTS:     NONE
*   OUTPUTS:    NONE
*   DESCRIPTION:
*               Configures ADC using
*                   FRC -   clock conversion during sleep
*                   AN3 -   with Vdd and Vss as references
*                       -   right-justified results
*               Begins conversion
*******************************************************************************/
void configADC(void)
{
    //A/D clock source as internal 
    ADCON0bits.ADCS0    =   1;
    ADCON0bits.ADCS1    =   1;
    ADCON1bits.ADCS2    =   0;
    
    //AN3 as analog channel
    ADCON0bits.CHS2     =   0;
    ADCON0bits.CHS1     =   1;
    ADCON0bits.CHS0     =   1;
    
    //result right-justified
    ADCON1bits.ADFM     =   1;
    
    //Configuring A/D Port Control Bits
    //for AN3 analog input
    ADCON1bits.PCFG3    =   0;
    ADCON1bits.PCFG2    =   0;
    ADCON1bits.PCFG1    =   0;
    ADCON1bits.PCFG0    =   0;
     
    ADRESH  =   0;
    ADRESL  =   0;
    
    //turns on module
    ADCON0bits.ADON     =   1;
    
}

/******************************************************************************
*   PROCEDURE:  calcTacq    
*   INPUTS:     NONE
*   OUTPUTS:    Returns Acquisition Time Required
*   DESCRIPTION:
*       The following values are assumed
*           CHold   =   120pF
*           Rs      =   2.5k 
*           Vdd     =   5V
*           Rss     =   7k  
*  
*       Tacq    =   Amp settling time + Chold Charge Time + Temp Coefficient
*               =   Tamp + Tc + Tcoff
*       
*       Tamp    =   2uS
*       Tc      =   -CHold(Ric + Rss +Rs)ln(1/2048)
*               =   -120(1k + 7k +Rs)ln(1/2048) 
*       Tcoff   =   (50 - Temp)*(0.05u)
 * 
*       Tacq    =   2 + Tc + Tcoff     
*******************************************************************************/
int calcTacq(int r_s, float temp)
{
    unsigned float Tamp     =   0.000002;
    unsigned double TC       =   -120*(8000 + r_s)*log(0.0004883);
    unsigned float Tcoff    =   (50 - temp)*0.00000005;
    
    return (Tamp + TC + Tcoff);    
}

void main(void)
{
    configADC();
    configADC_i();
    Delay10TCYx(calcTacq(20,3));
    
    //begin conversion
    ADCON0bits.GO_DONE  =   1;
    
    while(1);
    
    return;
}