/* 
 * File:   interrupts.h
 * Author: aaadi
 *
 * Created on October 21, 2018, 8:25 AM
 */
#include <p18f4550.h>

//--------------------------------INTERRUPTS----------------------------------//
#define     GIE     INTCONbits  .GIE
#define     GIEH    INTCONbits  .GIEH
#define     PEIE    INTCONbits  .PEIE
#define     GIEL    INTCONbits  .GIEL
#define     TMR0IE  INTCONbits  .TMR0IE
#define     INT0IE  INTCONbits  .INT0IE
#define     RBIE    INTCONbits  .RBIE
#define     TMR0IF  INTCONbits  .TMR0IF
#define     INT0IF  INTCONbits  .INT0IF
#define     RBIF    INTCONbits  .RBIF

#define     RBPU    INTCON2bits .RBPU
#define     INTEDG0 INTCON2bits .INTEDG0
#define     INTEDG1 INTCON2bits .INTEDG1
#define     INTEDG2 INTCON2bits .INTEDG2
#define     TMR0IP  INTCON2bits .TMR0IP
#define     RBIP    INTCON2bits .RBIP

#define     INT2IP  INTCON3bits .INT2IP
#define     INT1IP  INTCON3bits .INT1IP
#define     INT2IE  INTCON3bits .INT2IE
#define     INT1IE  INTCON3bits .INT1IE
#define     INT2IF  INTCON3bits .INT2IF
#define     INT1IF  INTCON3bits .INT1IF

//----------------------------PERIPHERAL FLAGS--------------------------------//
#define     SPPIF   PIR1bits    .SSPIF
#define     ADIF    PIR1bits    .ADIF
#define     RCIF    PIR1bits    .RCIF
#define     TXIF    PIR1bits    .TXIF
#define     SSPIF   PIR1bits    .SSPIF
#define     CCPIF   PIR1bits    .CCP1IF
#define     TMR2IF  PIR1bits    .TMR2IF
#define     TMR1IF  PIR1bits    .TMR1IF

#define     OSCFIF  PIR2bits    .OSCFIF
#define     CMIF    PIR2bits    .CMIF   
#define     USBIF   PIR2bits    .USBIF
#define     EEIF    PIR2bits    .EEIF
#define     BCLIF   PIR2bits    .BCLIF
#define     HLVDIF  PIR2bits    .HLVDIF
#define     TMR3IF  PIR2bits    .TMR3IF
#define     CCP2IF  PIR2bits    .CCP2IF

#define     SPPIE   PIE1bits    .SPPIE
#define     ADIE    PIE1bits    .ADIE
#define     RCIE    PIE1bits    .RCIE
#define     TXIE    PIE1bits    .TXIE
#define     SSPIE   PIE1bits    .SSPIE
#define     CCP1IE  PIE1bits    .CCP1IE
#define     TMR2IE  PIE1bits    .TMR2IE
#define     TMR1IE  PIE1bits    .TMR1IE

#define     OSCFIE  PIE2bits    .OSCFIE
#define     CMIE    PIE2bits    .CMIE 
#define     USBIE   PIE2bits    .USBIE
#define     EEIE    PIE2bits    .EEIE
#define     BCLIE   PIE2bits    .BCLIE
#define     HLVDIE  PIE2bits    .HLVDIE
#define     TMR3IE  PIE2bits    .TMR3IE
#define     CCP2IE  PIE2bits    .CCP2IE

#define     SPPIP   IPR1bits    .SPPIP
#define     ADIP    IPR1bits    .ADIP
#define     RCIP    IPR1bits    .RCIP
#define     TXIP    IPR1bits    .TXIP
#define     SSPIP   IPR1bits    .SSPIP
#define     CCP1IP  IPR1bits    .CCP1IP
#define     TMR2IP  IPR1bits    .TMR2IP
#define     TMR1IP  IPR1bits    .TMR1IP

#define     OSCFIP  IPR2bits    .OSCFIP
#define     CMIP    IPR2bits    .CMIP
#define     USBIP   IPR2bits    .USBIP
#define     EEIP    IPR2bits    .EEIP
#define     BCLIP   IPR2bits    .BCLIP
#define     HLVDIP  IPR2bits    .HLVDIP
#define     TMR3IP  IPR2bits    .TMR3IP
#define     CCP2IP  IPR2bits    .CCP2IP

#define     IPEN    RCONbits    .IPEN
#define     SBOREN  RCONbits    .SBOREN
#define     RI      RCONbits    .RI
#define     TO      RCONbits    .TO
#define     PD      RCONbits    .PD
#define     POR     RCONbits    .POR
#define     BOR     RCONbits    .BOR

//-----------------------------TIMER0  CONTROL--------------------------------//
#define     TMR0ON      T0CONbits   .TMR0ON
#define     T08BIT      T0CONbits   .T08BIT
#define     T0CS        T0CONbits   .T0CS
#define     T0SE        T0CONbits   .T0SE
#define     PSA         T0CONbits   .PSA
#define     T0PS2       T0CONbits   .T0PS2
#define     T0PS1       T0CONbits   .T0PS1
#define     T0PS0       T0CONbits   .T0PS0

//-----------------------------TIMER1  CONTROL--------------------------------//
#define     TMR1ON      T1CONbits   .TMR1ON
#define     T1RUN       T1CONbits   .T1RUN
#define     T1CKPS1     T1CONbits   .T1CKPS1
#define     T1CKPS0     T1CONbits   .T1CKPS0
#define     T1OSCEN     T1CONbits   .T1OSCEN
#define     T1SYNC      T1CONbits   .NOT_T1SYNC
#define     TMR1CS      T1CONbits   .TMR1CS
#define     RD16        T1CONbits   .RD16
