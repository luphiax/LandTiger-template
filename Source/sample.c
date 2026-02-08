
/*----------------------------------------------------------------------------
 * Name:    sample.c
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2020 Politecnico di Torino. All rights reserved.
 *----------------------------------------------------------------------------*/
 
/* When creating the project, open the Debug tab (inside Options for target) and set:
	1) Dialog DLL: DARMP1.DLL (Simulator) or TARMP1.DLL (ULINK2/ME Cortex Debugger)
	2) Parameter: -pLPC1768 (both)						*/
                 
#include "LPC17xx.h"                    /* LPC17xx definitions                */

/*-----------------------------------------------------------------
Uncomment to import the libraries that you need
 *-----------------------------------------------------------------*/

#include "button.h"
#include "timer.h"
#include "led.h"
#include "RIT.h"
#include "joystick.h"
#include "adc.h"
#include "dac.h"
#include <stdio.h>

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void)
{  
	//all timers at 25 MHz(default), RIT at 100 MHz(default)
	   SystemInit();
	   BUTTON_init();				/* BUTTON Initialization */
	   //I power on timer2 for ADC conversion
	   //LPC_SC->PCONP |=  (1<<22);
	   init_timer(3,0x1312D0);//for debouncing buttons 50ms=0x1312D0/25MHz
	   joystick_init();
	   init_RIT(0x004C4B40);	//clock is 100 MHz. calculate 50ms
		 enable_RIT();	
	   LED_init();
	  // ADC_init();
	  // DAC_init();
	   LPC_SC->PCON |= 0x1;	/* power-down mode */								
	   LPC_SC->PCON &= 0xFFFFFFFFD; 
	   SCB->SCR |= 0x2;				/* set SLEEPONEXIT */	
	
	   __ASM("wfi");
}
