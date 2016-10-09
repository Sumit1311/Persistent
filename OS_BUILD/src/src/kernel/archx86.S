.section .text
.globl kernel_entry
.globl clear
.globl set
.globl intialize
.globl load_local_gdt
.globl load_idt
.globl _gen_interrupt
.globl _get_cpu_info
.globl _inport_read
.globl _outport_write
.globl _save_stack_interrupt
.globl _restore_stack_interrupt
.globl _i86_pit_irq_wrapper
.globl _get_kernel_size

intialize:
	  cli			// clear interrupts--Do not enable them yet
	  movl 4(%esp),%ecx
	  movl %esp,%ebx
	  movl $0x90000, %esp
	  pushl %ebx
	  xor %ebx,%ebx
      mov $0x10,%bx	// offset 0x10 in gdt for data selector, remember?
      mov %bx, %ds
      mov %bx, %es
      mov %bx, %fs
      mov %bx, %gs
      mov %bx, %ss// Set up base stack
      mov %esp, %ebp// store current stack pointer
      pushl %ebp
      pushl %ecx
	  call kernel_entry
	  popl %ecx
	  popl %ecx
	  popl %esp
	  ret

clear:
	pushl %ebp
	movl %esp,%ebp
	cli
	popl %ebp
	ret

set:
	pushl %ebp
	movl %esp,%ebp
	sti
	popl %ebp
	ret

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
	popl %edx
	popl %edx
	popl %edx
	popl %ebp
	ret

_inport_read:
	pushl %ebp
	movl %esp,%ebp
	movl 8(%ebp),%ebx
	movw (%ebx),%dx //portid
  	in %dx,%al
  	movb %al,(%ebx)
  	popl %ebp
  	ret

_outport_write:
	pushl %ebp
	movl %esp,%ebp
	movw 8(%ebp),%dx //portid
	movb 12(%ebp),%al //value
  	out %al,%dx
  	popl %ebp
  	ret

_i86_pit_irq_wrapper:
	pushal
    cld /* C code following the sysV ABI requires DF to be clear on function entry */
    call i86_pit_irq
    popal
    iret

_get_kernel_size:
	pushl %ebp
	movl %esp,%ebp
	pushl %eax
	movl 8(%ebp),%eax //portid
	movl %edx,(%eax)
	popl %eax
	popl %ebp
  	ret
