/*
 * Zachary Allin
 * Susma Basel
 * Jeremy Bower
 */

#include <msp430.h> 

int table[] = {500,531,563,594,624,655,684,713,
		741,768,794,819,842,864,885,905,
		922,938,952,965,976,984,991,996,
		999,1000,999,996,991,984,976,965,
		952,938,922,905,885,864,842,819,
		794,768,741,713,684,655,624,594,
		563,531,500,469,437,406,376,345,
		316,287,259,232,206,181,158,136,
		115,95,78,62,48,35,24,16,
		9,4,1,0,1,4,9,16,
		24,35,48,62,78,95,115,136,
		158,181,206,232,259,287,316,345,
		376,406,437,469};
int counter = 0;
int i = 0;

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TACCR0_INT()
{
	// set taccr1 to the next sample value (lookup table)
	counter++;
	if(counter==80)
	{
		if(i == 100) // sizeof(table) gave incorrect behavior. constant 100 used instead
			i = 0;
		TACCR1 = table[i];
		i++;
		counter=0;

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
