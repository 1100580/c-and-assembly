.text

.global cont
.global max
.global ptrvec

.global ex5

ex5:

pushl %ebx
pushl %ecx

movl ptrvec,%ecx
movl $0, %edx
ciclo:
	movl max, %eax
	movl cont, %ebx
	cmpl %eax, %ebx
	jge fim_ciclo
	addl $1, cont
	addl (%ecx), %edx
	addl $4, %ecx
	jmp ciclo

fim_ciclo:
movl %edx, %eax
popl %ecx
popl %ebx
ret
