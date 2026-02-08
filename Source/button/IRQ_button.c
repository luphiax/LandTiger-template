#include "button.h"
#include "../RIT/RIT.h"
#include "LPC17xx.h" 
#include "../led/led.h"
#include <stdio.h>


//devi usare INT0 e KEY1 rispettivamente 2.10 e 2.11 
//bisogna fare il debouncing 
void EINT0_IRQHandler (void)	  
{
	enable_RIT();
	//disabilito l'interrupt
	NVIC_DisableIRQ(EINT0_IRQn);
  //lo cambio in GPIO output
  LPC_PINCON->PINSEL4	&= ~(1<<20); //deve essere 00 per GPIO out
	LPC_SC->EXTINT |= (1 << 1);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
	enable_RIT();
	//disabilito l'interrupt
	NVIC_DisableIRQ(EINT1_IRQn);
  //lo cambio in GPIO output
  LPC_PINCON->PINSEL4	&= ~(1<<22); //deve essere 00 per GPIO out
	LPC_SC->EXTINT |= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{
	enable_RIT();
	//disabilito l'interrupt
	NVIC_DisableIRQ(EINT2_IRQn);
  //lo cambio in GPIO output
  LPC_PINCON->PINSEL4	&= ~(1<<24); //deve essere 00 per GPIO out
	LPC_SC->EXTINT |= (1 << 2);     /* clear pending interrupt         */    
}


