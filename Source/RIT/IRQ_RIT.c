/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "adc.h"
/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/




void RIT_IRQHandler (void)
{
	static int up=0;
	static int left=0;
	static int right=0;
	static int click=0;
	static int down=0;
																				

	
	
																	//JOYSTICK
	
// Joystick UP pressed 
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	
		up++;
		switch(up){
			case 1:
//if the time passed is only 50ms. If it's a multiple add cases
				break;
			default:
				break;
		}
	}
	else{
			up=0;
	}
		
//Joystick RIGHT pressed 
	 if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		right++;
		switch(right){
			case 1:
//if the time passed is only 50ms. If it's a multiple add cases
				break;
			default:
				break;
		}
	}
	else{
			right=0;
	}
	 
	
//Joystick LEFT pressed	
	 if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		left++;
		switch(left){
			case 1:
//if the time passed is only 50ms. If it's a multiple add cases
				break;
			default:
				break;
		}
	}
	else{
			left=0;
	}
	
	
	
//Joystick DOWN pressed
	 if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	
		down++;
		switch(down){
			case 1:
//if the time passed is only 50ms. If it's a multiple add cases
				break;
			default:
				break;
		}
	}
	else{
			down=0;
	}
	
	
	
//Joystick CLICK pressed
	 if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	
		down++;
		switch(down){
			case 1:
//if the time passed is only 50ms. If it's a multiple add cases
				break;
			default:
				break;
		}
	}
	else{
			down=0;
	}
	
																		//POTENTIOMETER(ADC)

	//ADC_start_conversion(); //65 clk cycles with a clock 5MHz
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
