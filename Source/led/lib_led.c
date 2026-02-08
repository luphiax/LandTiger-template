/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           timer.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        Atomic led init functions
** Correlated files:    lib_timer.c, funct_timer.c, IRQ_timer.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "LPC17xx.h"
#include "led.h"

/*----------------------------------------------------------------------------
  Function that initializes LEDs and switch them off
 *----------------------------------------------------------------------------*/

unsigned char led_value;

void LED_init(void) {

	LPC_PINCON->PINSEL4 &= ~(
		(3u <<  0)   // P2.0
	| (3u <<  2)   // P2.1
	| (3u <<  4)   // P2.2
	| (3u <<  6)   // P2.3
	| (3u <<  8)   // P2.4
	| (3u << 10)   // P2.5
	| (3u << 12)   // P2.6
	| (3u << 14)   // P2.7
	);	//PIN mode GPIO (00b value per P2.0 to P2.7)


	//P2.0...P2.7 Output (LEDs on PORT2 defined as Output, value 1 for each bit)
	LPC_GPIO2->FIODIR |=
		(1u << 0)   // P2.0 
	| (1u << 1)   // P2.1 
	| (1u << 2)   // P2.2 
	| (1u << 3)   // P2.3 
	| (1u << 4)   // P2.4 
	| (1u << 5)   // P2.5 
	| (1u << 6)   // P2.6 
	| (1u << 7);  // P2.7   LPC_GPIO2->FIODIR   |= 0x000000FF;  

/*
	// all LEDs on on P2.0...P2.7 
	LPC_GPIO2->FIOSET =
		(1u << 0)
	| (1u << 1)
	| (1u << 2)
	| (1u << 3)
	| (1u << 4)
	| (1u << 5)
	| (1u << 6)
	| (1u << 7);  // LPC_GPIO2->FIOSET    = 0x000000FF;	
*/

	// all LEDs off on P2.0...P2.7 
	LPC_GPIO2->FIOCLR =
		(1u << 0)
	| (1u << 1)
	| (1u << 2)
	| (1u << 3)
	| (1u << 4)
	| (1u << 5)
	| (1u << 6)
	| (1u << 7); //LPC_GPIO2->FIOCLR    = 0x000000FF; 
	led_value = 0;	
}


void LED_deinit(void) {
// P2.0...P2.7 Output (LEDs on PORT2 defined as Output)
LPC_GPIO2->FIODIR &= ~(
		(1u << 0)   // P2.0 
	| (1u << 1)   // P2.1 
	| (1u << 2)   // P2.2 
	| (1u << 3)   // P2.3 
	| (1u << 4)   // P2.4 
	| (1u << 5)   // P2.5 
	| (1u << 6)   // P2.6 
	| (1u << 7)   // P2.7  LPC_GPIO2->FIODIR &= 0xFFFFFF00; 
	);

}
