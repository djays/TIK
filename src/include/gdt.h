#ifndef __GDT_H
#define __GDT_H

/* Defines a GDT entry */
struct gdt_entry
{
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed));

/* Special pointer: base and limit (size-1) */
struct gdt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

/* Our GDT, with 3 entries, and finally our special GDT pointer */
struct gdt_entry gdt[3];
struct gdt_ptr gp;

/* Defined in CODE.ASM , reload  segment registers */
extern void gdt_flush();

/* Setup a descriptor in the Global Descriptor Table */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

/* Setup the GDT */
extern void gdt_setup();


#endif
