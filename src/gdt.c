#include "base.h"
#include "gdt.h"


void gdt_set_gate(int index, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
    /* Setup the descriptor base address */
    gdt[index].base_low = (base & 0xFFFF);
    gdt[index].base_middle = (base >> 16) & 0xFF;
    gdt[index].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[index].limit_low = (limit & 0xFFFF);
    gdt[index].granularity = ((limit >> 16) & 0x0F);

    /* et up the granularity and access flags */
    gdt[index].granularity |= (gran & 0xF0);
    gdt[index].access = access;
}


void gdt_setup()
{
    /* Setup the GDT pointer and limit */
    gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
    gp.base = (unsigned int)&gdt;

    /* NULL descriptor */
    gdt_set_gate(0, 0, 0, 0, 0);

    /* Code Segment(Access 0x9A): Base address is 0,limit is 4 GBytes,4 KByte granularity */
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    /*  Data Segment(Access 0x92): Base address is 0,limit is 4 GBytes,4 KByte granularity */
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    /* Flush out the old GDT and insert the new changes */
    gdt_flush();
}
