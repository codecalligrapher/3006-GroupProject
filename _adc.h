/* 
 * File:   _adc.h
 * Author: aaadi
 *
 * Created on October 8, 2018, 8:28 PM
 */
static long int _ADRES;

#define _XTAL_FREQ  4000000

#define _tacqus     15  

//ADCON0 redefinition
#define _ADCS1      ADCON0bits  .ADCS1
#define _ADCS0      ADCON0bits  .ADCS0
#define _CHS2       ADCON0bits  .CHS2
#define _CHS1       ADCON0bits  .CHS1
#define _CHS0       ADCON0bits  .CHS0
#define _GO         ADCON0bits   .GO
#define _ADON       ADCON0bits  .ADON

//ADCON1 redefinition
#define _ADFM       ADCON1bits  .ADFM
#define _ADCS2      ADCON1bits   .ADCS2
#define _PCFG3      ADCON1bits  .PCFG3
#define _PCFG2      ADCON1bits  .PCFG2
#define _PCFG1      ADCON1bits  .PCFG1
#define _PCFG0      ADCON1bits  .PCFG0

int return_adc(void);