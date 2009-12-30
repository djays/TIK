;
; To define Descriptor tables and ISR
;

[GLOBAL gdt_flush]
[EXTERN gp]
gdt_flush:    
    lgdt [gp]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    jmp 0x08:flush2
flush2:
    ret

[GLOBAL idt_load]
[EXTERN idtp]
idt_load:
    lidt [idtp]
    ret

