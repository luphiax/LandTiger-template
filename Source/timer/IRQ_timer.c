/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Descriptions:        interrupt handlers of Timer/Counter 0 and 1
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "timer.h"
																		//LOUDSPEAKER(DAC)
uint16_t SinTable[45] =   //these values do not depend on the frequency of the sinusoid that's why I can use them anyways
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};

void TIMER0_IRQHandler (void)
{

	LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}


void TIMER2_IRQHandler (void)
{
																				//LOUDSPEAKER(DAC)
	static int ticks=0;
	LPC_DAC->DACR = (SinTable[ticks]<<6); //For each tick of k length of the timer (with k depending on the frequency) convert into analog a sampled point of the sinusoid
	ticks++;
	if(ticks==45) ticks=0; //each period of a sinusoid of a given musical note (given frequency)

  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER3_IRQHandler (void)
{
																			  //DEBOUNCING 

	static int down_KEY1 =0;
	static int down_KEY2 =0;
	static int down_INT0 =0;

//case KEY2
		if((LPC_PINCON->PINSEL4 & (1 << 24)) == 0){
		down_KEY2++;
		if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){   //int0
			//222 reset_timer(3)
			switch(down_KEY2){
				case 1:

					break;
				default:
					break;
			}
		}
		else {	
			down_KEY2=0;			
			disable_timer(3);
			reset_timer(3);
			NVIC_EnableIRQ(EINT2_IRQn);							 
			LPC_PINCON->PINSEL4    |= (1 << 24);     
		}
	}	
	
	
//case KEY1
	if((LPC_PINCON->PINSEL4 & (1 << 22)) == 0){
		down_KEY1++;
		if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){   //key1
			switch(down_KEY1){
				case 1:
//if the time passed is only 50ms. If it's a multiple add cases
				
					break;
				default:
					break;
			}
		}
		else {	
			down_KEY1=0;			
			disable_timer(3);
			reset_timer(3);
			NVIC_EnableIRQ(EINT1_IRQn);							 
			LPC_PINCON->PINSEL4    |= (1 << 22);    
		}
	}			

	
	
//case INT0
	if((LPC_PINCON->PINSEL4 & (1 << 20)) == 0){
		down_INT0++;
		if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){   //int0
			//222 reset_timer(3)
			switch(down_INT0){
				case 1:
//if the time passed is only 50ms. If it's a multiple add cases
					break;
				default:
					break;
			}
		}
		else {	
			down_INT0=0;			
			disable_timer(3);
			reset_timer(3);
			NVIC_EnableIRQ(EINT0_IRQn);							 
			LPC_PINCON->PINSEL4    |= (1 << 20);     
		}
	}	


  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}


