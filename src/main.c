#include <screen.h>
#include <string.h>
#include <gdt.h>
#include <idt.h>
#include <timer.h>

int main()
{
    gdt_setup();    
    idt_setup();
    isr_setup();
    init_video();
    irq_setup();
    __asm__ __volatile__ ("sti");
    timer_setup();
    puts(" Welcome to TIK! \n");
    for (;;);
    
    return 0;
}
