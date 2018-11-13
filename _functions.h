/* 
 * File:   kpad.h
 * Author: aaadi
 *
 * Created on October 26, 2018, 4:07 PM
 */

#include <p18f452.h>



/*_kpad.c*/
char kpad_rslv(void);
void kpad_config(void);

/*_adc.c*/
int adc_measure(void);

/*_lcd.c*/
void LCD_config(void);

/*_counter.c*/
void h_isr(void);
void    counter_measure_config(void);
double  counter_bpm(void);

/*_interface.c*/
void interface_action(void);
void interface_display_abort(void);
void interface_interval(void);
void interface_set_temp(float);
void interface_set_rate(int);
void interface_set_pnn50(float);

/*_countv.c*/
void countv_incr(void);
int countv_get(void);
int countv_get_rate(void);
void countv_reset(void);
void time_set(int);
int time_get(void);
void time_reset(void);
void time2_reset(void);
int time2_get(void);
void time2_set(int);

/*_dbg.c*/
void LED_debug(void);
void temp_debug(void);
void kpad_debug(void);
void glucose_debug(void);

/*_temp.c*/
void temp(void);
float temp_get(void);

/*_pNN50.c*/
void pnn50_calc(int, int);
void pnn50_reset(void);
float pnn50_var(void);
int pnn50_get(void);

#define LCD_NOT_READY   while(BusyXLCD());

//-----------------------------PORT DEFINITIONS-------------------------------//
#define kpad_d0     PORTDbits.RD0
#define kpad_d1     PORTDbits.RD1
#define kpad_d2     PORTCbits.RC2
//#define kpad_d2   //PORTDbits.RD2
#define kpad_d3     PORTDbits.RD3
#define kpad_rdy    PORTBbits.RB2 

#define kpad_t0     TRISDbits.TRISD0
#define kpad_t1     TRISDbits.TRISD1
#define kpad_t2     TRISCbits.TRISC2
//#define kpad_t2     TRISDbits.TRISD2
#define kpad_t3     TRISDbits.TRISD3
#define kpad_rdyt   TRISBbits.TRISB2