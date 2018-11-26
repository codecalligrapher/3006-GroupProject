/* 
 * File:   _lvd.h
 * Author: aaadi
 *
 * Created on October 8, 2018, 9:12 PM
 */
#define _XTAL_FREQ  4000000

#define _IRVST  LVDCONbits  .IRVST
#define _LVDEN  LVDCONbits  .LVDEN
#define _LVLD3  LVDCONbits  .LVDL3
#define _LVLD2  LVDCONbits  .LVDL2
#define _LVLD1  LVDCONbits  .LVDL1
#define _LVLD0  LVDCONbits  .LVDL0

#define _LVDIE  PIE2bits    .LVDIE
#define _LVDIF  PIR2bits    .LVDIF

void lvd_config(void); 


