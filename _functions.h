/* 
 * File:   kpad.h
 * Author: aaadi
 *
 * Created on October 26, 2018, 4:07 PM
 */

#include <p18f452.h>




short unsigned int kpad_read(void);
unsigned char kpad_rslv(void);
/*_adc.c*/
void kpad_config(void);
int glucose(void);
void h_isr(void);
void measure(void);
/*heartrate.c*/
void config_timer(void);                                                        //configures timer1 for required interval of measurement
void config_counter(void);                                                      //configures timer0 to begin counting
void get_rate(void);
void get_count(void);
void init_measure(void);

/*_counter.c*/
void h_isr(void);
void main(void);
int calc_rate(int period);
void measure_beats(void);


#define LCD_NOT_READY   while(BusyXLCD());

//-----------------------------PORT DEFINITIONS-------------------------------//
#define kpad_d0     PORTDbits.RD0
#define kpad_d1     PORTDbits.RD1
#define kpad_d2     PORTAbits.RA3 
//#define kpad_d2     PORTDbits.RD2
#define kpad_d3     PORTDbits.RD3
#define kpad_rdy    PORTBbits.RB2 

#define kpad_t0     TRISDbits.TRISD0
#define kpad_t1     TRISDbits.TRISD1
#define kpad_t2     TRISAbits.TRISA3
//#define kpad_t2     TRISDbits.TRISD2
#define kpad_t3     TRISDbits.TRISD3
#define kpad_rdyt   TRISBbits.TRISB2


//------------------------------BIT DEFINITIONS-------------------------------//
#define data_rdy    INTCON3bits.INT2IF