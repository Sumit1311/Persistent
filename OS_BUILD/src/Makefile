outputdir=./bin/
srcdir=./src/
bootloader =$(join $(srcdir),boot_loader.asm)
bootloader2 =$(join $(srcdir),boot_loader2.asm)
kernelasm=$(join $(srcdir),kernel.asm)
flatbinary=$(join $(outputdir),Boot1.bin)
#must be capital
kernelloader=$(join $(outputdir),KRNLDR.BIN)
kernelbinary=$(join $(outputdir),KERNEL.BIN)
diskimage =$(join $(outputdir),c.img)
tempmountpt=$(join $(outputdir),tmp)
CROSS_CC=i686-elf-gcc

all: createimage $(diskimage) copykernel buildkernel

$(diskimage):$(flatbinary)
	dd status=noxfer conv=notrunc if=$(flatbinary) of=$(diskimage) bs=512 count=1

$(flatbinary):$(join $(srcdir),boot_loader.asm)
	nasm -O0 -w+orphan-labels -f bin -o $(flatbinary) $(bootloader)

copykernel:$(kernelloader) $(kernelbinary)
	sudo mkdir $(tempmountpt) && sudo mount -t vfat -o loop $(diskimage) $(tempmountpt) && sudo cp $(kernelloader) $(tempmountpt) && sudo cp $(kernelbinary) $(tempmountpt)

$(kernelloader):$(join $(srcdir),boot_loader2.asm)
	nasm -O0 -w+orphan-labels -f bin -o $(kernelloader) $(bootloader2)
	
$(kernelbinary):$(join $(srcdir),kernel.asm)
	nasm -O0 -w+orphan-labels -f bin -o $(kernelbinary) $(kernelasm)
		
clean:
	rm -rf $(diskimage) $(flatbinary) $(kernelloader) $(kernelbinary) && rm -rf $(tempmountpt) 
	
createimage:
	mkdosfs -C $(diskimage) 1440
	
buildkernel:
	