#include <xc.h>
#include <libpic30.h>
#include "settings.h"

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

/**
 * OscillatorSttings
 */
void OscillatorSettings()
{
    _PLLPRE=0x00; // N1=2
    _PLLDIV=0x1E; // M=32
    _PLLPOST=0x00; // N2=2
    // controllo che sia entrato in funzione l'oscillatore primario con PLL
    while (OSCCONbits.COSC != 0b011) {continue;}
    // controllo che il PLL sia agganciato
    while(OSCCONbits.LOCK!=1) {continue;}
}

/**
 * DsPicSettings
 *
 *
 */
void DsPicSettings()
{
    OscillatorSettings();

    // Set all port A pins as input except RA4
    TRISA = 0b1111111111101111;
}