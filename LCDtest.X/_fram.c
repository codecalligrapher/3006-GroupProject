#include <p18f452.h>
#include <delays.h>
#include "_functions.h"
#include "def_f842.h"

void fram_clk_pulse(void)
{
    FRAM_CLK    =   1;
    Delay10TCYx(1);
    FRAM_CLK    =   0;
    Delay10TCYx(1);
}

void fram_shift_out(unsigned int addr)
{
    int shift_i;
    FRAM_LAT    =   0;
    for (shift_i = 0; shift_i < 18; shift_i++)
    {
        FRAM_SER    = (addr >> shift_i) & 0x01;
        fram_clk_pulse();
    }
    FRAM_LAT    =   1;
    Delay10TCYx(1);
    FRAM_LAT    =   0;
    return;
}

void fram_data_commit(void)
{
    FRAM_W_EN   =   0;
    Delay10TCYx(4);
    FRAM_W_EN   =   1;
    Delay10TCYx(4);
    return;
}

void fram_begin(void)
{
    FRAM_W_EN   =   1;
    FRAM_OUT_EN =   1;
    return;
}

void fram_read(void)
{
    FRAM_OUT_EN =   0;
}

void fram_write_init(void)
{
    FRAM_D7 =   1;
    FRAM_D6 =   0;
    FRAM_D5 =   1;
    FRAM_D4 =   0;
    FRAM_D3 =   1;
    FRAM_D2 =   0;
    FRAM_D1 =   1;
    FRAM_D0 =   0;
    fram_shift_out(0x5555);
    fram_data_commit();
    
    FRAM_D7 =   0;
    FRAM_D6 =   1;
    FRAM_D5 =   0;
    FRAM_D4 =   1;
    FRAM_D3 =   0;
    FRAM_D2 =   1;
    FRAM_D1 =   0;
    FRAM_D0 =   1;
    fram_shift_out(0x2AAA);
    fram_data_commit();
    
    FRAM_D7 =   1;
    FRAM_D6 =   0;
    FRAM_D5 =   1;
    FRAM_D4 =   0;
    FRAM_D3 =   0;
    FRAM_D2 =   0;
    FRAM_D1 =   0;
    FRAM_D0 =   0;
    fram_shift_out(0x5555);
    fram_data_commit();
    return;
}

void fram_write_data(int data, int addr)
{
    fram_write_init();
    fram_write(data,addr);
    fram_delay();
}

void fram_write(int data, int addr)
{
    fram_shift_out(addr);
    FRAM_D0 =   data & 0x01;
    FRAM_D1 =   (data >> 1) & 0x01;
    FRAM_D2 =   (data >> 2) & 0x01;
    FRAM_D3 =   (data >> 3) & 0x01;
    FRAM_D4 =   (data >> 4) & 0x01;
    FRAM_D5 =   (data >> 5) & 0x01;
    FRAM_D6 =   (data >> 6) & 0x01;
    FRAM_D7 =   (data >> 7) & 0x01;
    fram_data_commit();
}

void fram_delay(void)
{
    Delay100TCYx(1);
    return;
}