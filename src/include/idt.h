#ifndef __IDT_H
#define __IDT_H

/* Defines an IDT entry */
struct idt_entry
{
    unsigned short base_low;        // Starting Address of Base 
    unsigned short select;
    unsigned char always0;          // Always set to 0
    unsigned char flags;            // Control Access. (Value = 14)
    unsigned short base_high;       // Ending Address of Base 
} __attribute__((packed));

/* Special pointer: base of idt and limit (size-1) */
struct idt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

/* Define 256 entries (using only first 32), Rest are for trapping  */
struct idt_entry idt[256];
struct idt_ptr idtp;

/* In 'code.asm',Load the IDT */
extern void idt_load();

/* Set an entry in IDT */
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

/* Setup the IDT*/
void idt_setup();
#endif  /* End IDT.h */
