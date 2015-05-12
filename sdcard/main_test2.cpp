/*
 * main.c
 *
 * Example of reading from the SD card
 * This will read the size of the SD card
 * And then read the first block of data.
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

	//Test that the SD card is working
	//Read in the OEM name and version in bytes 3-10
	volatile unsigned char block[64] = {0};

	// Read in a 512 byte sector
	// This is a multipart process.
	// First you must mount the block, telling the SD card the relative offset
	// of your subsequent reads. Then you read the block in multiple frames.
	// We do this so we don't need to allocate a full 512 byte buffer in the
	// MSP430's memory. Instead we'll use smaller 64 byte buffers. This
	// means that an entire block will take 8 reads. The spiReadFrame command
	// reads in the given number of bytes into the byte array passed to it.
	// After reading all of the data in the block it should be unmounted.
	//volatile char result = mmcReadBlock(0, 64, block);
	//volatile char result = mmcMountBlock(0, 512);
	volatile char result = mmcMountBlock(0, 512);

	//My FAT partition apparently starts at block 129 (0x81)
	//If you have a FAT16 filesystem you could read data from that point
	//Read in the block 64 bytes at a time
	if (result == MMC_SUCCESS) {
		volatile int i = 0;
		//8 blocks of 64 to read
		for (i = 0; i < 8; ++i) {
			//If you set a breakpoint here you can examine the memory in the card.
			spiReadFrame((void*)block, 64);
		}
		mmcUnmountBlock();
	}

	while (1);
}
