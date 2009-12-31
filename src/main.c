#include "screen.h"
#include "string.h"
#include "gdt.h"


int main()
{
    gdt_setup();    
    idt_setup();
    isr_setup();
    init_video();
    puts(" TIK \n");
    put(1/0);
    puts(" Check \n");
    for (;;);
    
    return 0;
}
