# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler 
# rule, as we use nasm instead of GNU as.

CFLAGS=-Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -c -I./include
LINKERFLAGS=-Tlink.ld
ASMFLAGS=-felf
ASSEMBLER= nasm $(ASMFLAGS) 
LINKER= ld $(LINKERFLAGS) 

OBJECTS=boot.o main.o base.o screen.o string.o mem.o stdlib.o gdt.o idt.o dt.o isr.o isrs.o irqs.o irq.o timer.o keyboard.o

all: clean $(OBJECTS) link
	-rm -f *.o
clean:
	-rm -f *.o *~ include/*~ ../iso/boot/kernel ../*.iso
link:
	$(LINKER) -o ../iso/boot/kernel $(OBJECTS)

%.o: %.asm	
	$(ASSEMBLER) -o $*.o $*.asm    

iso:
	-rm -f ../*.iso
	cp ../README ../iso/README
	mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o ../TIK.iso ../iso
