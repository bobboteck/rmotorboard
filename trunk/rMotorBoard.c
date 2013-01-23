/*
 * File:   dsPIC1.c
 * Author: bobboteck
 *
 * Created on 13 gennaio 2013, 21.44
 */
#include <xc.h>
#include <libpic30.h>
#include "settings.h"
/*
 *
 */
int main(void)
{
    DsPicSettings();
    // Loop to flash an LED on RD0 (pin 23)
    while(1)
    {
        _LATA4 = 1;          // Set RD0 high
        __delay32(15000000); // 500ms delay
        _LATA4 = 0;          // Set RD0 low
        __delay32(15000000); // 500ms delay
    }

    return 0;
}
