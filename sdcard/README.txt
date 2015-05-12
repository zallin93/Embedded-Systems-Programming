This zip file contains several files that will get you started read data from
an SD card. This code was adapted from TI's reference code that was written
for the MSP430F169. I've adapted the pin outs for the G2553, as described in
the commented in the hal_MMC_hardware_board.h file. 

The pinout are as follows:


Pin  Function    SD Card Pin

P1.1 SOMI     -> 7

P1.2 SIMO     -> 2

P1.3 CS       -> 1

P1.4 SCLK     -> 5

P1.5 Detect   -> 6 (really just a second ground)



The SD card breakout boards are all labelled! The GND on the far side of the
board from the VCC lines is where the detect pin should be attached. You
should be able to run the code in main_test.cpp and, with a breakpoint,
observe the correct value for the size of your SD card. If this works reliably
then your wiring is correct and your breakout board is defect-free.
