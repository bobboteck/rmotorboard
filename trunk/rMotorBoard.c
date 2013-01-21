/*
 * File:   dsPIC1.c
 * Author: bobboteck
 *
 * Created on 13 gennaio 2013, 21.44
 */
#include <xc.h>
#include <libpic30.h>
/*
 *
 */
// avvio direttamente con oscillatore primario + PLL
_FOSCSEL(IESO_OFF & FNOSC_PRIPLL);
// FCKSM_CSDCMD : funzione clock switching disattivata
// IOL1WAY_OFF : è possibile effettuare più di una volta le funzioni di remapping
// OSCIOFNC_OFF : il pin OSC2 è utilizzato normalmente come uscita del clock
// POSCMD_XT : stiamo usando un quarzo con un valore da 3 a 10MHz
_FOSC(FCKSM_CSDCMD & IOL1WAY_OFF & OSCIOFNC_OFF & POSCMD_XT);
// Watchdog timer disattivato
_FWDT(FWDTEN_OFF);
// PowerOn Reset di 128mS + I2C rimappata sui pin ASDA1/ASCL1
_FPOR(FPWRT_PWR128 & ALTI2C_ON);

int main(void)
{
    _PLLPRE=0x00; // N1=2
    _PLLDIV=0x1E; // M=32
    _PLLPOST=0x00; // N2=2
    // controllo che sia entrato in funzione l'oscillatore primario con PLL
    while (OSCCONbits.COSC != 0b011) {continue;}
    // controllo che il PLL sia agganciato
    while(OSCCONbits.LOCK!=1) {continue;}
    // Set all port D pins as outputs
    TRISA = 0b1111111111101111;
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
