
#include "button.h"
#include "LPC17xx.h"

/**
 * @brief  Function that initializes Buttons
 */
void BUTTON_init(void) {
  
	//external interrupt configuration for INT0
	//input pin(default) + 01 config --> interrupt
  LPC_PINCON->PINSEL4    |= (1 << 20);		 
	LPC_PINCON->PINSEL4    &= ~(1 << 21);
	
  LPC_GPIO2->FIODIR      &= ~(1 << 10);  //clear bit for input mode (default)

	//external interrupt configuration for KEY1
	//input pin(default) + 01 config --> interrupt  

  LPC_PINCON->PINSEL4    |= (1 << 22);     
	LPC_PINCON->PINSEL4    &= ~(1 << 23);
	
  LPC_GPIO2->FIODIR      &= ~(1 << 11);    
  
	//external interrupt configuration for KEY2
	//input pin(default) + 01 config --> interrupt  
	
  LPC_PINCON->PINSEL4    |= (1 << 24); 
  LPC_PINCON->PINSEL4    &= ~(1 << 25);	
	
  LPC_GPIO2->FIODIR      &= ~(1 << 12);    
	
	
	

  LPC_SC->EXTMODE = 0x7; 									 /* set edge sensitivity */
	LPC_SC->EXTPOLAR = 0;                    /* low active with level, with edge it translates into falling edge */

  NVIC_EnableIRQ(EINT2_IRQn);              /* enable irq in nvic                 */
	NVIC_SetPriority(EINT2_IRQn, 1);				 /* priority, the lower the better     */
  NVIC_EnableIRQ(EINT1_IRQn);              /* enable irq in nvic                 */
	NVIC_SetPriority(EINT1_IRQn, 2);				 
  NVIC_EnableIRQ(EINT0_IRQn);              /* enable irq in nvic                 */
	NVIC_SetPriority(EINT0_IRQn, 3);				 /* decreasing priority	from EINT2->0	 */
}
