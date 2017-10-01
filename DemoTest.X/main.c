/********************************************************************
* FileName:     main.c
* Dependencies:    
* Processor:    PIC24F16KA102 Family
* Hardware:     Microstick for 3V PIC24 K Series
* Compiler:     C30 3.30c or later
* Company:      Microchip Technology, Inc.
*
* Software License Agreement
*
* The software supplied herewith by Microchip Technology Incorporated
* (the ?Company?) for its PICmicro® Microcontroller is intended and
* supplied to you, the Company?s customer, for use solely and
* exclusively on Microchip PICmicro Microcontroller products. The
* software is owned by the Company and/or its supplier, and is
* protected under applicable copyright laws. All rights are reserved.
* Any use in violation of the foregoing restrictions may subject the
* user to criminal sanctions under applicable laws, as well as to
* civil liability for the breach of the terms and conditions of this
* license.
*
* THIS SOFTWARE IS PROVIDED IN AN ?AS IS? CONDITION. NO WARRANTIES,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
* IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
* 
* Change History:
*
* Author        Revision #      Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* E. Schlunder  1.00            08-18-2011  Initial code
********************************************************************/

#include <xc.h>


// Configuration Bits to make the part run from Internal FRCDIV
// Oscillator.

_FBS
(
    BWRP_OFF &      // Table Write Protect Boot (Boot segment may be written)
    BSS_OFF         // Boot segment Protect (No boot program Flash segment)
)

_FGS
(
    GWRP_OFF &      // General Segment Code Flash Write Protection bit (General segment may be written)
    GCP_OFF         // General Segment Code Flash Code Protection bit (No protection)
)

_FOSCSEL
(
    FNOSC_FRCDIV &  // Oscillator Select (8 MHz FRC oscillator with divide-by-N (FRCDIV))
    IESO_ON         // Internal External Switch Over bit (Internal External Switchover mode enabled (Two-Speed Start-up enabled))
)

_FOSC
(
    POSCMOD_NONE &  // Primary Oscillator Configuration bits (Primary oscillator disabled)
//    OSCIOFNC_OFF &  // CLKO Enable Configuration bit (CLKO output disabled)
    POSCFREQ_MS &   // Primary Oscillator Frequency Range Configuration bits (Primary oscillator/external clock input frequency between 100 kHz and 8 MHz)
    SOSCSEL_SOSCHP &// SOSC Power Selection Configuration bits (Secondary oscillator configured for high-power operation)
    FCKSM_CSECME    // Clock Switching and Monitor Selection (Both Clock Switching and Fail-safe Clock Monitor are enabled)
)

_FWDT
(
    WDTPS_PS32768 & // Watchdog Timer Postscale Select bits (1:32,768)
    FWPSA_PR128 &   // WDT Prescaler (WDT prescaler ratio of 1:128)
    WINDIS_OFF &    // Windowed Watchdog Timer Disable bit (Standard WDT selected; windowed WDT disabled)
    FWDTEN_OFF      // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
)

// Warning:
// Always enable MCLRE_ON config bit setting so that the MCLR pin function will
// work for low-voltage In-Circuit Serial Programming (ICSP). The Microstick
// programming circuitry only supports low-voltage ICSP. If you disable MCLR pin
// functionality, a high-voltage ICSP tool will be required to re-program the
// part in the future.
_FPOR
(
    BOREN_BOR3 &    // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware; SBOREN bit disabled)
    PWRTEN_ON &     // Power-up Timer Enable bit (PWRT enabled)
    I2C1SEL_PRI &   // Alternate I2C1 Pin Mapping bit (Default location for SCL1/SDA1 pins)
    BORV_V18 &      // Brown-out Reset Voltage bits (Brown-out Reset set to lowest voltage (1.8V))
    MCLRE_ON        // MCLR Pin Enable bit (MCLR pin enabled; RA5 input pin disabled)
)

_FICD
(
    ICS_PGx3        // ICD Pin Placement Select bits (PGC3/PGD3 are used for programming and debugging the device)
)

//_FDS
//(
//    DSWDTPS_DSWDTPSF &// Deep Sleep Watchdog Timer Postscale Select bits (1:2,147,483,648 (25.7 Days))
//    DSWDTOSC_LPRC & // DSWDT Reference Clock Select bit (DSWDT uses LPRC as reference clock)
//    RTCOSC_SOSC &   // RTCC Reference Clock Select bit (RTCC uses SOSC as reference clock)
//    DSBOREN_OFF &   // Deep Sleep Zero-Power BOR Enable bit (Deep Sleep BOR disabled in Deep Sleep)
//    DSWDTEN_OFF     // Deep Sleep Watchdog Timer Enable bit (DSWDT disabled)
//)


int main(void)
{
    unsigned int i;
    
    // Set up output pin for LED
    TRISAbits.TRISA0 = 0;

    while(1)
    {

        // (insert your application code here)



        // To make the LED blink visibly, we have to wait a while between toggling

        // the LED pin.
        for(i = 0; i < 65535; i++)
        {
            Nop();
            Nop();
            Nop();
            Nop();
        }
        

        // Toggle the LED output pin to alternate between the LED being on and off
        LATAbits.LATA0 ^= 1;
    }
}
