#include <xc.h>

int main(void)
{
    unsigned int i;
    
    // Set up DAC1CON
    DAC1CONbits.DACREF = 2;
    DAC1CONbits.DACFM = 0;
    DAC1CONbits.DACTRIG = 0;
    DAC1CONbits.DACEN = 1;
    
    DAC1DAT = 0x00FF;
    
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
        DAC1DAT -= 0x8;
    }
}
