/*
 * File:   kpad.h
 * Author: aaadi
 *
 * Created on October 26, 2018, 4:07 PM
 */

/*_kpad.c*/
char kpad_rslv(void);
void kpad_config(void);

/*_adc.c*/
int adc_measure(void);
void adc_glucose_rslv(void);
int adc_glucose_get(void);
void adc_glucoset_reset(void);

/*_lcd.c*/
void LCD_config(void);

/*_counter.c*/
void h_isr(void);
void    counter_measure_config(void);
double  counter_bpm(void);
unsigned char get_action_valid(void);
void set_invalid_action(void);
void set_valid_action(void);
void dly_8s(void);
void dly_2s(void);
void dly_1s(void);
unsigned char get_store_valid(void);
void set_valid_store(void);
void set_invalid_store(void);

/*_interface.c*/
void interface_action(void);
void interface_display_abort(void);
void interface_interval(void);
void interface_set_temp(float);
void interface_set_rate(int);
void interface_set_pnn50(unsigned int);
void interface_set_temp_int(int);
void interface_set_temp_fraction(int);
void interface_set_gluc(int);
void interface_disply_stored(unsigned int);

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
void set_valid_int(void);
void set_invalid_int(void);
short unsigned int get_valid_int(void);

/*_dbg.c*/
void LED_debug(void);
void temp_debug(void);
void kpad_debug(void);
void glucose_debug(void);
void nuke_debug(void);

/*_temp.c*/
void temp(void);
unsigned int temp_get_int(void);
unsigned int temp_get_fraction(void);

/*_pNN50.c*/
void            pnn50_calc(int, int);
void            pnn50_reset(void);
float           pnn50_var(void);
unsigned int    pnn50_get(void);
unsigned int    pnn50_get_cnt(void);
unsigned int    pnn50_get_int(void);
unsigned int    pnn50_get_fraction(void);


/*_eeprom.c*/
void            eeprom_write(unsigned int,unsigned int);
unsigned char   eeprom_read(unsigned int);
void            eeprom_write_data(unsigned int);
unsigned int    eeprom_get_next(void);
void            eeprom_set_next(unsigned int);

#define LCD_NOT_READY   while(BusyXLCD());

//-----------------------------PORT DEFINITIONS-------------------------------//
#define kpad_d0     PORTDbits.RD0
#define kpad_d1     PORTDbits.RD1
#define kpad_d2     PORTCbits.RC1
//#define kpad_d2   //PORTDbits.RD2
#define kpad_d3     PORTDbits.RD3
#define kpad_rdy    PORTBbits.RB2

#define kpad_t0     TRISDbits.TRISD0
#define kpad_t1     TRISDbits.TRISD1
#define kpad_t2     TRISCbits.TRISC1
//#define kpad_t2     TRISDbits.TRISD2
#define kpad_t3     TRISDbits.TRISD3
#define kpad_rdyt   TRISBbits.TRISB2
