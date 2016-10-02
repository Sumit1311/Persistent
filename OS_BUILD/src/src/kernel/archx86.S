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
	mov 8(%ebp),%eax
	lgdt (%eax)
	popl %ebp
	ret

load_idt:
	pushl %ebp
	movl %esp,%ebp
	mov 8(%ebp),%eax
	lidt (%eax)
	popl %ebp
	ret

genint:
	int $0x00
	jmp _exit_routine

_gen_interrupt:
	pushl %ebp
	movl %esp,%ebp
	movl 8(%ebp),%eax
	movb %al, (genint+1)
	jmp genint
_exit_routine:
	popl %ebp
	ret


