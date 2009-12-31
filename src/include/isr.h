#ifndef __ISR_H
#define __ISR_H
#include<base.h>

char *exception_message[] =
{
    " 0: Divide By Zero Exception",
    " 1: Debug Exception",         
    " 2: Non Maskable Interrupt Exception",
    " 3: Int 3 Exception",                 
    " 4: INTO Exception",                  
    " 5: Out of Bounds Exception",         
    " 6: Invalid Opcode Exception",        
    " 7: Coprocessor Not Available Exception",
    " 8: Double Fault Exception ",
    " 9: Coprocessor Segment Overrun Exception",    
    "10: Bad TSS Exception ",     
    "11: Segment Not Present Exception ",
    "12: Stack Fault Exception ",        
    "13: General Protection Fault Exception ",
    "14: Page Fault Exception ",              
    "15: Reserved Exception",                                   
    "16: Floating Point Exception",                             
    "17: Alignment Check Exception",                            
    "18: Machine Check Exception",                              
    "19: Reserved",                                             
    "20: Reserved",
    "21: Reserved",
    "22: Reserved",
    "23: Reserved",
    "24: Reserved",
    "25: Reserved",
    "26: Reserved",
    "27: Reserved",
    "28: Reserved",
    "29: Reserved",
    "30: Reserved",
    "31: Reserved"
};

/* Set the Interrupt Service Routines */
void isr_setup();

/* Fault Handler called from isr.asm */
void fault_handler(struct regs *r);

/* 0: Divide By 0 Exception */
extern void isr0();

/* 1: Debug Exception */
extern void isr1();

/* 2: NMI (Non Maskable Exception */
extern void isr2();

/* 3: INT 3 Exception */
extern void isr3();

/* 4: INT O Exception */
extern void isr4();

/* 5: Out of Bounds Exception */
extern void isr5();

/* 6: Invalid Opcode Exception */
extern void isr6();

/* 7: Coprocessor Not Available Exception */
extern void isr7();

/* 8: Double Fault Exception */
extern void isr8();

/* 9: Coprocessor Segment Overrun Exception */
extern void isr9();

/*  10: Bad TSS Exception (With Error Code!) */
extern void isr10();                           

/*  11: Segment Not Present Exception (With Error Code!) */
extern void isr11();                                       

/*  12: Stack Fault Exception (With Error Code!) */
extern void isr12();                               

/*  13: General Protection Fault Exception (With Error Code!) */
extern void isr13();                                            

/*  14: Page Fault Exception (With Error Code!) */
extern void isr14();                              

/*  15: Reserved Exception */
extern void isr15();         

/*  16: Floating Point Exception */
extern void isr16();               

/*  17: Alignment Check Exception */
extern void isr17();                

/*  18: Machine Check Exception */
extern void isr18();              

/*  19: Reserved */
extern void isr19();

/*  20: Reserved */
extern void isr20();

/*  21: Reserved */
extern void isr21();

/*  22: Reserved */
extern void isr22();

/*  23: Reserved */
extern void isr23();

/*  24: Reserved */
extern void isr24();

/*  25: Reserved */
extern void isr25();

/*  26: Reserved */
extern void isr26();

/*  27: Reserved */
extern void isr27();

/*  28: Reserved */
extern void isr28();

/*  29: Reserved */
extern void isr29();

/*  30: Reserved */
extern void isr30();

/*  31: Reserved */
extern void isr31();

/* Rest are Trap */

#endif //ISR.H
