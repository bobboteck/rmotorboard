/**
 * File:   rMotorBoard.c
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
    // Loop to flash an LED on RA4
    while(1)
    {
        _LATA4 = 1;          // Set RA4 high
        __delay32(15000000); // 500ms delay
        _LATA4 = 0;          // Set RA4 low
        __delay32(15000000); // 500ms delay
    }

    return 0;
}
