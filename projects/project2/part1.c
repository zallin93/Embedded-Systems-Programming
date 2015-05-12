/*
 * Zachary Allin
 * Susma Basel
 * Jeremy Bower
 */

#include <msp430.h> 

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TACCR0_INT()
{
    // nothing needed as TACCR1 remains constant
}


/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    P1DIR |= BIT6;
    P1SEL |= BIT6;

    // set a 16MHz clock
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
    TA0CTL = MC_1 | ID_0 | TASSEL_2;

    TACCR0 = 1000;
    TACCR1 = 250;

    TACCTL0 = CCIE;

    // set control registers
    TA0CCTL1 = OUTMOD_7;

    __enable_interrupt();

    while(1);

	return 0;
}
