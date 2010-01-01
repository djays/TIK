#include <screen.h>
#include <string.h>
#include <gdt.h>
#include <isr.h>
#include <idt.h>
#include <timer.h>
#include <keyboard.h>

int main()
{
    gdt_setup();    
    idt_setup();
    isr_setup();
    init_video();
    irq_setup();
    __asm__ __volatile__ ("sti");
    timer_setup();
    keyboard_setup();
    puts(" Welcome to TIK! \n");
    for (;;);
    
    return 0;
}
