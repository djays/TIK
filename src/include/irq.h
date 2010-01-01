#include<base.h>
#include<idt.h>

#ifndef __IRQ_H
#define __IRQ_H

/* IRQ handlers defined in irqs.asm */
extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();



/* Set a custom IRQ */
void irq_set_handler(int irq, void (*handler)(struct regs *r));

/* Remove a handler */
void irq_remove_handler(int irq);

/* Since IDT entry 8 is a Double fault in protected mode it need to be remapped.
   This is achieved by signaling the PIC (Programmable Interrupt Counter) to remap 
   IRQ 0-15 to IDT 32 -47
*/
void irq_remap(void);

/* Setup the IRQs by remapping to correct IDT entries and then setting the funtctions */
void irq_setup();

/* Send "End of Interrupt" signal to BOTH the PICs if second gets interrupt else only to first */
/* First:Master PIC, Second:Slave PIC */

void irq_handler(struct regs *r);
void irq_handler(struct regs *r);
#endif
