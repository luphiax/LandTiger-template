/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        Atomic joystick init functions
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "LPC17xx.h"
#include "joystick.h"

/*----------------------------------------------------------------------------
  Function that initializes joysticks and switch them off
 *----------------------------------------------------------------------------*/

void joystick_init(void)
{
    /* P1.25..P1.29 as GPIO (function 00) */
    LPC_PINCON->PINSEL3 &= ~(
            (3u << 18)  /* P1.25  JOY_SEL  */
          | (3u << 20)  /* P1.26  JOY_DOWN */
          | (3u << 22)  /* P1.27  JOY_LEFT */
          | (3u << 24)  /* P1.28  JOY_RIGHT*/
          | (3u << 26)  /* P1.29  JOY_UP   */
        );

    /* P1.25..P1.29 as input (joystick lines) */
    LPC_GPIO1->FIODIR &= ~(
            (1u << 25)  /* JOY_SEL  */
          | (1u << 26)  /* JOY_DOWN */
          | (1u << 27)  /* JOY_LEFT */
          | (1u << 28)  /* JOY_RIGHT*/
          | (1u << 29)  /* JOY_UP   */
        );

    /* pull-up interni lasciati al valore di reset (PINMODE3 = 00) */
}
