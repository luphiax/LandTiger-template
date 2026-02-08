/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  20184-12-30
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "LPC17xx.h"
#include "adc.h"
#include "led.h"
#include "timer.h"

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/

unsigned short AD_current;   
unsigned short AD_last = 0xFF;    

//T'=45*k*T_timer ---> 1/f'=45*k/f_timer ---> k= f_timer/(45*f')
//f_timer has frequency 25MHz 
//T' is the frequency of the note we want.
//k is the interval between a sampling point and another 
//in a T' we have 45 sampling points. 

//const int freqs[8]={4240,3779,3367,3175,2834,2525,2249,2120};
/* 
131Hz		k=4240 C3 (Do3)
147Hz		k=3779 D3 (Re3)
165Hz		k=3367 E3 (Mi3)
175Hz		k=3175 F3 (Fa3)
196Hz		k=2834 G3 (Sol3)	
220Hz		k=2525 A3 (La3)
247Hz		k=2249 B3 (Si3)
262Hz		k=2120 C4 (Do4)
*/

const int freqs[8]={2120,1890,1684,1592,1417,1263,1125,1062}; //in reality these are the periods 
/*
262Hz	k=2120		c4 (do4)
294Hz	k=1890		d4 (re4)
330Hz	k=1684		e4 (mi4)
349Hz	k=1592		f4 (fa4)
392Hz	k=1417		g4 (sol4)
440Hz	k=1263		a4 (la4)
494Hz	k=1125		b4 (si4)
523Hz	k=1062		c5 (do5)

*/

void ADC_IRQHandler(void) {
															//POTENTIOMETER(ADC)
	
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);// I access the result from the converted value register
  if(AD_current != AD_last){  //I do the job only when I turn on/off the potentiometer
		//if you want you can switch on the led corresponding to the scale and switch off the one at the stage before
		//sx of the potentiometer minimum value (LED 11), dx maximum
		
		LED_Off(AD_last*7/0xFFF);	  // ad_last : AD_max = x : 7 	
		LED_On(AD_current*7/0xFFF);	// ad_current : AD_max = x : 7 		
		AD_last = AD_current;
															//LOUDSPEAKER(DAC)
		disable_timer(2);
		reset_timer(2);
		init_timer(2,freqs[AD_current*7/0xFFF]); 
		enable_timer(2);
		
		
  }
	
}
