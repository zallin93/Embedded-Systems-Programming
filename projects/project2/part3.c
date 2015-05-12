/*
 * Zachary Allin
 * Susma Basel
 * Jeremy Bower
 */

#include <msp430.h> 

int counter = 0;

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TACCR0_INT()
{
	// set taccr1 to the next sample value
	counter++;

    // every 8 times we hit TACCR0, increment TACCR1
	if(counter==8)
	{
		TACCR1++;
		counter=0;
		if(TACCR1 == TACCR0)
			TACCR1 = 0;
	}
}

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    // set the correct output, port 1 pin 6 (green LED)	
    P1DIR |= BIT6;
    P1SEL |= BIT6;

    // set a 16MHz clock
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
    TA0CTL = MC_1 | ID_0 | TASSEL_2;

    TACCR0 = 1000;
    TACCR1 = 0;

    TACCTL0 = CCIE;

    // set control registers
    TA0CCTL1 = OUTMOD_7;

    __enable_interrupt();

    while(1);

	return 0;
}
