#include<irq.h>

#ifndef __KEYBOARD_H
#define __KEYBOARD_H


/* Handles the keyboard interrupt */
void keyboard_handler(struct regs *r);


/* Sets the keyboard handler into IRQ1 */
void keyboard_setup();


#endif
