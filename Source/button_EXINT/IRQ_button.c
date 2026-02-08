#include "button.h"
#include "LPC17xx.h"
#include "timer.h"

void EINT0_IRQHandler (void)	  	/* INT0														 */
{	
		                     //DEBOUNCING
	
	enable_timer(3);
	NVIC_DisableIRQ(EINT0_IRQn);
  //lo cambio in GPIO output
  LPC_PINCON->PINSEL4	&= ~(1<<20); //deve essere 00 per GPIO out	
	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  	/* KEY1														 */
{
	                      //DEBOUNCING
	enable_timer(3);
	NVIC_DisableIRQ(EINT1_IRQn);
  //lo cambio in GPIO output
  LPC_PINCON->PINSEL4	&= ~(1<<22); //deve essere 00 per GPIO out
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  	/* KEY2														 */
{
											 //DEBOUNCING
	
	enable_timer(3);
	NVIC_DisableIRQ(EINT2_IRQn);
  //lo cambio in GPIO output
  LPC_PINCON->PINSEL4	&= ~(1<<24); //deve essere 00 per GPIO out
  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


