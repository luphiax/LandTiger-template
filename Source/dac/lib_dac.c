#include "LPC17xx.h"
#include "dac.h"

/*----------------------------------------------------------------------------
  Function that initializes DAC
 *----------------------------------------------------------------------------*/
void DAC_init (void) {
		 LPC_PINCON->PINSEL1 |= (1<<21);
		 LPC_PINCON->PINSEL1 &= ~(1<<20);			//I set the pin 0.26 to aout(DAC) config 10
		 LPC_GPIO0->FIODIR |= (1<<26);				//need it for software debugging
}

	 
