.section .text
.globl kernel_entry
.globl clear
.global intialize
.global load_local_gdt
.global load_idt
.global _gen_interrupt

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

load_local_gdt:
	pushl %ebp
	movl %esp,%ebp
	lgdt -8(%ebp)
	popl %ebp
	ret

load_idt:
	pushl %ebp
	movl %esp,%ebp
	lidt -8(%ebp)
	popl %ebp
	ret

_gen_interrupt:
	pushl %ebp
	movl %esp,%ebp
	movl -8(%ebp),%eax
	int %al
	popl %ebp
	ret


