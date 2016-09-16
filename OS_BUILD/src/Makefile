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
CC_FLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra -iquote include/kernel/
OBJS=$(join $(buildoutputdir) ,debug_display.o) $(join $(buildoutputdir) ,entry.o) $(join $(buildoutputdir) , string.o) $(join $(buildoutputdir) , main.o)
 
vpath %.inc include
vpath %.h include/kernel
vpath %.c src/kernel
vpath %.ld src/kernel
vpath %.asm src
vpath %.c lib

all: createimage $(diskimage) $(kernelbinary) copykernel | $(buildoutputdir)

$(diskimage):$(flatbinary) | $(execoutputdir)
	dd status=noxfer conv=notrunc if=$< of=$@ bs=512 count=1

$(flatbinary):$(join $(srcdir),boot_loader.asm) | $(execoutputdir)
	nasm -O0 -w+orphan-labels -f bin -o $@ $<

copykernel:$(kernelloader) | $(execoutputdir)
	sudo mkdir $(tempmountpt) && sudo mount -t vfat -o loop $(diskimage) $(tempmountpt) && \
	sudo cp $(kernelloader) $(tempmountpt) && sudo cp $(kernelbinary) $(tempmountpt)

$(kernelloader):$(join $(srcdir),boot_loader2.asm) $(wildcard %.inc) | $(execoutputdir)
	nasm -O0 -w+orphan-labels -f bin -o $@ $<
	
.PHONY: clean		
clean:
	rm -rf $(execoutputdir) && rm -rf $(buildoutputdir)
	
createimage: | $(execoutputdir)
	mkdosfs -C $(diskimage) 1440
	
$(kernelbinary):$(OBJS) | $(execoutputdir)
# for flat binary kernel
#   $(join $(srcdir),kernel.asm) prereq
#	nasm -O0 -w+orphan-labels -f bin -o $@ $< command 
	$(CROSS_CC) -v -T $(srcdir)/kernel/linker.ld -o $@ -ffreestanding -O2 -nostdlib $(OBJS) -lgcc 

$(join $(buildoutputdir),debug_display.o) : debug_display.c debug_display.h | $(buildoutputdir)
	$(CROSS_CC) $(CC_FLAGS) -c  $< -o $@

$(join $(buildoutputdir),entry.o) : entry.c  | $(buildoutputdir)
	$(CROSS_CC) $(CC_FLAGS) -c  $< -o $@

$(join $(buildoutputdir),string.o) : string.c string.h | $(buildoutputdir)
	$(CROSS_CC) $(CC_FLAGS) -c $< -o $@
	
$(join $(buildoutputdir),main.o) : main.c debug_display.h | $(buildoutputdir)
	$(CROSS_CC) $(CC_FLAGS) -c $< -o $@
	
$(execoutputdir) :
	mkdir $@
	
$(buildoutputdir) :
	mkdir $@