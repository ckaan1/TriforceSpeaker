#include <xc.h>


/* Example code for Timer1 ISR*/
void __attribute__((__interrupt__, __shadow__)) _T1Interrupt(void)
{
    /* Interrupt Service Routine code goes here */
    IFS0bits.T1IF = 0; //Reset Timer1 interrupt flag and Return from ISR
    LATAbits.LATA0 ^= 1;
}


int main(void)
{
    unsigned int i;
    
    T1CON = 0x00; //Stops the Timer1 and reset control reg.
    TMR1 = 0x00; //Clear contents of the timer register
    PR1 = 0x7A12; //Load the Period register with the value 0xFFFF
    IPC0bits.T1IP = 0x01; //Setup Timer1 interrupt for desired priority level

    IFS0bits.T1IF = 0; //Clear the Timer1 interrupt status flag
    IEC0bits.T1IE = 1; //Enable Timer1 interrupts
    T1CONbits.TON = 3; //Start Timer1 with prescaler settings at 1:1 and
    //clock source set to the internal instruction cycle
    
    // Set up DAC1CON
    // Port setup for DACs
    TRISBbits.TRISB12 = 0; // DAC1 Output, Analog output, Pin 23
    ANSBbits.ANSB12 = 1;
    
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
        DAC1DAT -= 0x8;
    }
}
