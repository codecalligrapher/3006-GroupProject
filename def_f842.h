/* 
 * File:   def_f842.h
 * Author: aaadi
 *
 * Created on October 29, 2018, 5:30 PM
 */
#include <p18f452.h>
#include "_functions.h"

#define     NDEBUG_GLUCOSE  0
#define     NDEBUG_ISR      0
#define     NDEBUG_KPAD     0
#define     NDEBUG_LED      0
#define     NDEBUG_TEMP     0
#define     NDEBUG_COUNTER  0
#define     NDEBUG_PNN50    0
#define     NDEBUG_NUKE     0
#define     NDEBUG_MEM      0
#define     NDEBUG          1
#define     TEMP            1
#define     HRATE           1
#define     GLUC            0
#define     ROM             1

#define     GIE         INTCONbits.GIE
#define     GIEH        INTCONbits.GIEH
#define     PEIE        INTCONbits.PEIE
#define     TMR0IE      INTCONbits.TMR0IE
#define     INT0IE      INTCONbits.INT0IE
#define     RBIE        INTCONbits.RBIE
#define     TMR0IF      INTCONbits.TMR0IF
#define     INT0IF      INTCONbits.INT0F
#define     RBIF        INTCONbits.RBIF

#define     RBPU        INTCON2bits.NOT_RBPU
#define     INTEDG0     INTCON2bits.INTEDG0
#define     INTEDG1     INTCON2bits.INTEDG1
#define     INTEDG2     INTCON2bits.INTEDG2
#define     TMR0IP      INTCON2bits.TMR0IP
#define     RBIP        INTCON2bits.RBIP

#define     INT2IP      INTCON3bits.INT2IP
#define     INT1IP      INTCON3bits.INT1IP
#define     INT1IE      INTCON3bits.INT1IE
#define     INT2IF      INTCON3bits.INT2IF
#define     INT2IE      INTCON3bits.INT2IE
#define     INT1IF      INTCON3bits.INT1F

#define     PSPIF       PIR1bits.PSPIF
#define     ADIF        PIR1bits.ADIF
#define     RCIF        PIR1bits.RCIF
#define     TXIF        PIR1bits.TXIF
#define     SSPIF       PIR1bits.SSPIF
#define     CCP1IF      PIR1bits.CCP1IF
#define     TMR2IF      PIR1bits.TMR2IF
#define     TMR1IF      PIR1bits.TMR1IF

#define     EEIF        PIR2bits.EEIF
#define     BCLIF       PIR2bits.BCLIF
#define     LVDIF       PIR2bits.LVDIF
#define     TMR3IF      PIR2bits.TMR3IF
#define     CCP2IF      PIR2bits.CCP2IF


#define     PSPIE       PIE1bits.PSPIE
#define     ADIE        PIE1bits.ADIE
#define     RCIE        PIE1bits.RCIE
#define     TXIE        PIE1bits.TXIE
#define     SSPIE       PIE1bits.SSPIE
#define     CCP1IE      PIE1bits.CCP1IE
#define     TMR2IE      PIE1bits.TMR2IE
#define     TMR1IE      PIE1bits.TMR1IE

#define     EEIE        PIE2bits.EEIE
#define     BCLIE       PIE2bits.BCLIE
#define     LVDIE       PIE2bits.LVDIE
#define     TMR3IE      PIE2bits.TMR3IE
#define     CCP2IE      PIE2bits.CCP2IE

#define     PSPIP       IPR1bits.PSPIP
#define     ADIP        IPR1bits.ADIP
#define     RCIP        IPR1bits.RCIP
#define     TXIP        IPR1bits.TXIP
#define     SSPIP       IPR1bits.SSPIP
#define     CCPIP       IPR1bits.TMR1IP
#define     TMR2IP      IPR1bits.TMR2IP
#define     TMR1IP      IPR1bits.TMR1IP

#define     EEIP        IPR2bits.EEIP
#define     BCLIP       IPR2bits.BCLIP
#define     LVDIP       IPR2bits.LVDIP
#define     TMR3IP      IPR2bits.TMR3IP
#define     CCP2IP      IPR2bits.CCP2IP

#define     IPEN        RCONbits.IPEN
#define     NOT_RI      RCONbits.NOT_RI
#define     NOT_TO      RCONbits.NOT_TO
#define     NOT_PD      RCONbits.NOT_PD
#define     NOT_POR     RCONbits.NOT_POR
#define     NOT_BOR     RCONbits.NOT_BOR

#define     TMR0ON      T0CONbits.TMR0ON
#define     T08BIT      T0CONbits.T08BIT
#define     T0CS        T0CONbits.T0CS
#define     T0SE        T0CONbits.T0SE
#define     PSA         T0CONbits.PSA
#define     T0PS2       T0CONbits.T0PS2
#define     T0PS1       T0CONbits.T0PS1
#define     T0PS0       T0CONbits.T0PS0

#define     RD16        T1CONbits.RD16
#define     T1CKPS1     T1CONbits.T1CKPS1
#define     T1CKPS0     T1CONbits.T1CKPS0
#define     T1OSCEN     T1CONbits.T1OSCEN
#define     T1SYNC      T1CONbits.T1INSYNC
#define     TMR1CS      T1CONbits.TMR1CS
#define     TMR1ON      T1CONbits.TMR1ON

#define     EEPGD       EECON1bits.EEPGD
#define     CFGS        EECON1bits.CFGS
#define     FREE        EECON1bits.FREE
#define     WRERR       EECON1bits.WRERR
#define     WREN        EECON1bits.WREN
#define     WR          EECON1bits.WR
#define     RD          EECON1bits.RD

#define LINE_ONE    0x00
#define LINE_TWO    0x40
#define LINE_THREE  0x10
#define LINE_FOUR   0x50

#define ONE_SECOND_PS_1_256 3906.25 
#define TWO_SECOND_PS_1_256 7813 
#define FIFTY_MSECOND_PS_1_256 400

#define     LED_TEST_ONE    LATEbits.LATE0
#define     LED_TEST_TWO    LATEbits.LATE1
#define     LED_TEST_THREE  LATEbits.LATE2
#define     LED_TEST_ONE_STAT   PORTEbits.RE0
#define     LED_TEST_TWO_STAT   PORTEbits.RE1
#define     LED_TEST_THREE_STAT PORTEbits.RE2


#define     CLEAR_LCD       WriteCmdXLCD(0x01)