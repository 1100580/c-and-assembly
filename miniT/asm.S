.text

.global soma_vitorias
.global calcula_pontos

soma_vitorias:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp), %ebx
movl (%ebx), %ecx
movl $0, %eax
ciclo:
	cmpl $0, %ecx
	je fim
	addl $4, %ebx
	movl (%ebx), %edx
	addb %dl, %al
	subl $1, %ecx
	jmp ciclo
fim:
movl %ebp, %esp
popl %ebp
ret

calcula_pontos:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp), %ebx
movl (%ebx), %ecx
movl $0, %eax
ciclo2:
	cmpl $0, %ecx
	je fim2
	addl $4, %ebx
	movl (%ebx), %edx
	movb %dl, %al
	imull $3, %eax
	addb %dh, %al
	rcr $24, %edx
	movb %al, %dl
	movl %edx, (%ebx)
	subl $1, %ecx
	jmp ciclo2
fim2:
movl %ebp, %esp
popl %ebp
ret
