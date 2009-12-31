# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler 
# rule, as we use nasm instead of GNU as.


SOURCES=boot.o main.o base.o screen.o string.o mem.o stdlib.o gdt.o idt.o isr.o
CFLAGS=-Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -c -I./include
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) link
	-rm -f *.o
clean:
	-rm -f *.o *~ include/*~ ../iso/boot/kernel ../*.iso
link:
	ld $(LDFLAGS) -o ../iso/boot/kernel $(SOURCES) dtasm.o israsm.o

.s.o:
	nasm $(ASFLAGS) $<
	nasm $(ASFLAGS) dt.asm -o  dtasm.o
	nasm $(ASFLAGS) isr.asm -o israsm.o
    

iso:
	-rm -f ../*.iso
	cp ../README ../iso/README
	mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o ../TIK.iso ../iso
