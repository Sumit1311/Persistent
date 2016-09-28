.section .text
.globl kernel_entry
.globl clear
.global intialize

intialize:
	  cli			// clear interrupts--Do not enable them yet
      mov $0x10,%ax	// offset 0x10 in gdt for data selector, remember?
      mov %ax, %ds
      mov %ax, %es
      mov %ax, %fs
      mov %ax, %gs
      mov %ax, %ss// Set up base stack
      mov $0x90000, %esp
      mov %esp, %ebp// store current stack pointer
      push %ebp
	  call kernel_entry

clear:
	cli
