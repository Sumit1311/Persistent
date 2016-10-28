execoutputdir=./bin/
buildoutputdir=./build/
srcdir=./src/
bootloader =$(join $(srcdir),boot_loader.asm)
bootloader2 =$(join $(srcdir),boot_loader2.asm)
kernelasm=$(join $(srcdir),kernel.asm)
flatbinary=$(join $(execoutputdir),Boot1.bin)
#must be capital
kernelloader=$(join $(execoutputdir),KRNLDR.BIN)
kernelbinary=$(join $(execoutputdir),KERNEL.BIN)
diskimage =$(join $(execoutputdir),c.img)
tempmountpt=$(join $(execoutputdir),tmp)
CROSS_CC=i686-elf-gcc
CC_FLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra -iquote include/kernel/ -iquote include/lib/
OBJS=$(patsubst %.o,$(join $(buildoutputdir),%.o),$(_OBJS))
_OBJS= debug_display.o entry.o string.o main.o archx86.o cpu.o gdt.o hal.o idt.o stdio.o pic.o pit.o exception.o panic.o mmngr_phys.o mmngr_virtual.o vmmngr_pde.o vmmngr_pte.o kybrd.o flpydsk.o
LD_SCRIPT=$(join $(srcdir)kernel/,linker.ld)
KERNEL_LOADER_INCLUDE=stdio.inc gdt.inc A20.inc fat12.inc common.inc oem_block.inc memory.inc bootinfo.inc
.PHONY: copyflatbinary copykernel main.dep entry.dep string.dep debug_display.dep cpu.dep gdt.dep idt.dep hal.dep stdio.dep clean all pic.dep pit.dep exception.dep panic.dep mmngr_virtual.dep vmmngr_pde.dep vmmngr_pte.dep kybrd.dep flpydsk.dep
 
vpath %.inc include
vpath %.h include/kernel
vpath %.h include/lib
vpath %.c src/kernel
vpath %.S src/kernel
vpath %.ld src/kernel
vpath %.asm src
vpath %.c lib

all: copyflatbinary copykernel | $(buildoutputdir);

$(diskimage):| $(execoutputdir)
	mkdosfs -C $@ 1440
	
copyflatbinary: $(flatbinary) | $(execoutputdir) $(diskimage)
	dd status=noxfer conv=notrunc if=$< of=$(diskimage) bs=512 count=1 && sync
	
$(flatbinary):$(join $(srcdir),boot_loader.asm) | $(execoutputdir)
	nasm -O0 -w+orphan-labels -f bin -o $@ $< 	

copykernel:$(kernelloader) $(kernelbinary) | $(execoutputdir) $(diskimage) $(tempmountpt)
	sudo mount -t vfat -o loop $(diskimage) $(tempmountpt) && \
	sudo cp $(kernelloader) $(tempmountpt) && sudo cp $(kernelbinary) $(tempmountpt)

$(kernelloader):$(join $(srcdir),boot_loader2.asm) $(KERNEL_LOADER_INCLUDE) | $(execoutputdir)
	nasm -O0 -w+orphan-labels -f bin -o $@ $<

$(kernelbinary):$(OBJS) $(LD_SCRIPT) | $(execoutputdir)	
	$(CROSS_CC) -v -T $(srcdir)kernel/linker.ld -o $@ -ffreestanding -O2 -nostdlib $(OBJS) -lgcc
#$(kernelbinary):$(join $(buildoutputdir) ,bare_bones.o) | $(execoutputdir)
#	$(CROSS_CC) -v -T $(srcdir)/kernel/linker.ld -o $@ -ffreestanding -O2 -nostdlib $(join $(buildoutputdir) ,bare_bones.o) -lgcc
# for flat binary kernel
#   $(join $(srcdir),kernel.asm) prereq
#	nasm -O0 -w+orphan-labels -f bin -o $@ $< command  
#$(join $(buildoutputdir) ,bare_bones.o):bare_bones.c | $(buildoutputdir)
#	$(CROSS_CC) $(CC_FLAGS) -c  $< -o $@

$(join $(buildoutputdir),%.o) :%.c %.dep | $(buildoutputdir)
	$(CROSS_CC) $(CC_FLAGS) -c  $< -o $@

main.dep:debug_display.h ;
entry.dep: ;
string.dep:string.h;
debug_display.dep:debug_display.h;
cpu.dep: cpu.h gdt.h idt.h;
gdt.dep: gdt.h string.h;
idt.dep: idt.h string.h hal.h debug_display.h;
hal.dep: cpu.h gdt.h idt.h;
stdio.dep: string.h stdio.h;
pic.dep:hal.h pic.h;
pit.dep:hal.h pit.h idt.h pic.h;
exception.dep: exception.h hal.h;
panic.dep: hal.h stdarg.h debug_display.h;
mmngr_phys.dep:mmngr_phys.h;
mmngr_virtual.dep:string.h mmngr_virtual.h mmngr_phys.h;
vmmngr_pde.dep:vmmngr_pde.h;
vmmngr_pte.dep:vmmngr_pte.h;
kybrd.dep:kybrd.h;
flpydsk.dep:flpydsk.h hal.h;
	
$(join $(buildoutputdir),archx86.o) : archx86.S | $(buildoutputdir)
	$(CROSS_CC) $(CC_FLAGS) -c $< -o $@
	
$(execoutputdir) :
	mkdir $@
	
$(buildoutputdir) :
	mkdir $@
	
$(tempmountpt):|$(execoutputdir)
	mkdir $@
		
clean:
	rm -rf $(execoutputdir) && rm -rf $(buildoutputdir)