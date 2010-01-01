#include<idt.h>
#include<mem.h>
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    /* The interrupt routine's base address */
    idt[num].base_low = (base & 0xFFFF);
    idt[num].base_high = (base >> 16) & 0xFFFF;

    /* The segment or 'selector' that this IDT entry will use *  is set here, along with any access flags */
    idt[num].select = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

/* Installs the IDT */
void idt_setup()
{
    /* Sets the special IDT pointer up, just like in 'gdt.c' */
    idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
    idtp.base = (unsigned int) &idt;

    /* Initialize entire IDT to 0 */
    memset((unsigned char *)&idt, 0, sizeof(struct idt_entry) * 256);

    /* Place for new ISRs using idt_set_gate*/
    /* defined later after loading*/

    /* Points the processor's internal register to the new IDT */
    idt_load();
}
