#include<base.h>
#include<irq.h>

#ifndef __TIMER_H
#define __TIMER_H

/* Handler for each tick ; Default 18.222Hz */
void timer_handler(struct regs *r);

/* Wait for no of ticks */
void timer_wait(int ticks);

/* Sets handler to IRQ0 ,Since timer is connected to IRQ0 */
void timer_setup();

#endif
