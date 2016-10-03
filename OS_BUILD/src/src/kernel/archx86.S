.section .text
.globl kernel_entry
.globl clear
.global intialize
.global load_local_gdt
.global load_idt
.global _gen_interrupt
.global _get_cpu_info

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

_get_cpu_info:
	movl 0,%eax
    pushl %ebp
	movl %esp,%ebp
    cpuid
    pushl %ecx
    pushl %edx
    pushl %ebx
	movl 8(%ebp),%eax
	popl (%eax)
	popl (%eax+4)
	popl (%eax+8)
	popl %ebp
	ret
