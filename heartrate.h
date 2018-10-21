/* 
 * File:   heartrate.h
 * Author: aaadi
 *
 * Created on October 21, 2018, 7:44 AM
 */

#ifndef HEARTRATE_H
#define	HEARTRATE_H

void init_counter(void);
void init_measure(void);
void stop_measure(short unsigned float*);
void init_timer(void);
void tmr0_rst(void);
void tmr1_rst(void);
void h_isr(void);
extern void alarm(void);
