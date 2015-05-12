/*
 * main.c
 *
 * Example of reading from the SD card
 * This will read the size of the SD card
 * Use a breakpoint to verify that your wiring is correct
 */

#include <msp430.h>
#include <string.h> //For mem copy
#include "MMC.h"
#include "hal_SPI.h"
#include "hal_MMC_hardware_board.h"

//Red onboard LED
const unsigned char LED = BIT0;

void main(void) {
	//Turn off the watchdog timer
	WDTCTL = WDTPW + WDTHOLD;

	P1DIR |= LED;
	P1OUT &= ~LED;

	//16MHz
	//Set DCO to 16 MHz calibrated
	DCOCTL = CALDCO_16MHZ;
	BCSCTL1 = CALBC1_16MHZ;

	//Reset SD card by cycling power
	//Credit to Boris Cherkasskiy and his blog post on Launchpad+MMC
	P2DIR |= BIT2;
	P2OUT &= ~BIT2;
	__delay_cycles(1600000);	// 100ms @ 16MHz
	P2OUT |= BIT2;
	__delay_cycles(1600000);	// 100ms @ 16MHz

	//Initialize MMC library
	while (MMC_SUCCESS != mmcInit());
	//Verify card ready
	while (MMC_SUCCESS != mmcPing());
	//Check the memory card size
	volatile unsigned long size = mmcReadCardSize();

	//Toggle the LED to indicate that reading was successful
	P1OUT ^= LED;

	//Set a breakpoint here and read the size of the SD card
	while (1);
}
