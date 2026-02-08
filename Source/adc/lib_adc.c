#include "LPC17xx.h"
#include "adc.h"

/*----------------------------------------------------------------------------
  Function that initializes ADC
 *----------------------------------------------------------------------------*/
void ADC_init (void) {

  LPC_PINCON->PINSEL3 |=  (3UL<<30);    //Potentiometer connected to pin 1.31 which corresponds to AD0.5 that's why I'm selecting as the function of the PIN

  LPC_SC->PCONP       |=  (1<<12);      //Enable power

  LPC_ADC->ADCR        =  (1<< 5) |     //we are in software mode: so only 1 channel allowed: I select AD0.5 for the potentiometer
                          (4<< 8) |     //ADC clock is ClkADC/(CLKDIV + 1) since we count 0. so 25 MHz /4+1 = 5 MHz               */
                          (1<<21);      /* enable ADC                         */ 

  LPC_ADC->ADINTEN     =  (1<< 8);      /* a conversion on channel 0 generates interrupt (I am using 0.5 so it's correct)           */

  NVIC_EnableIRQ(ADC_IRQn);             /* enable ADC Interrupt               */
	NVIC_SetPriority(ADC_IRQn,1);
}

void ADC_start_conversion (void) {
	LPC_ADC->ADCR |=  (1<<24);            /* Start A/D Conversion 				*/
}				 
