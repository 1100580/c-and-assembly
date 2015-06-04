/*
 * asm.S
 *
 *  Created on: Oct 7, 2011
 *      Author: root
 */

	.text

	.global g_int_1
	.global g_int_2
	.global g_int_resultado
	.global ex2_1
	.global ex2_2
	.global ex2_3
	.global ex3_1
	.global ex3_2
	.global ex5_1
	.global ex5_2
	.global n1,n2,n3,n4
	.global g_divisor
	.global g_dividendo
	.global sinal
	.global g_quociente
	.global c
	.global p


	#funcao em assembly que e invocada do C sem parametros
	.global funcao
	.global funcao2
	.global funcao3
	.global funcao4
	.global funcao5
	.global funcao6
	.global funcao7
	.global funcao8
	.global funcao9
	.global funcao10
	.global funcao11
	.global inicializaChar

funcao:
# prologo da funcao
	pushl %ebp			# guardar a stack frame anterior
	movl %esp, %ebp		# o novo stack frame

# corpo da funcao
	movl g_int_1, %eax			# colocar o valor da variavel global g_int_1 no registo eax
	addl g_int_2, %eax			# adiciona o valor da variavel global g_int_2 no registo eax
	movl %eax, g_int_resultado	# colocar o valor do registo eax na variavel global g_int_resultado

# epilogo da funcao
	movl %ebp, %esp			# voltar a colocar o esp no local original para o "ret"
	popl %ebp				# repor o stack frame da funcao que invocou esta
	ret

funcao2:

pushl %ebp
movl %esp, %ebp

	movl ex2_1, %eax
	addl ex2_2, %eax
	subl ex2_3, %eax

movl %ebp, %esp
popl %ebp
ret

funcao3:

pushl %ebp
movl %esp, %ebp

	movl ex3_1, %eax
	mull ex3_2
	movl %eax, g_int_resultado

movl %ebp, %esp
popl %ebp
ret

funcao4:

pushl %ebp
movl %esp, %ebp

	movl ex3_1, %eax
	mull ex3_2

movl %ebp, %esp
popl %ebp
ret

funcao5:

pushl %ebp
movl %esp, %ebp

	movl ex5_1, %eax
	imull ex5_2

movl %ebp, %esp
popl %ebp
ret

funcao6:

pushl %ebp
movl %esp, %ebp

	movl ex5_1, %eax
	imull ex5_2
	movl %eax, g_int_resultado

movl %ebp, %esp
popl %ebp
ret

funcao7:

pushl %ebp
movl %esp, %ebp

	movl ex3_1, %eax
	addl ex3_2, %eax

	movl ex2_2, %edx
	addl ex2_1, %edx

	imull %edx

	movl ex2_2, %edx
	subl g_int_1, %edx

	imull %edx

movl %ebp, %esp
popl %ebp
ret

funcao8:

pushl %ebp
movl %esp, %ebp

movl n1, %eax
addl n2, %eax
subl n3, %eax

movl %ebp, %esp
popl %ebp
ret

funcao9:

pushl %ebp
movl %esp, %ebp

movl n1, %eax
addl n2, %eax
subl n3, %eax
movl %eax, g_int_resultado

movl %ebp, %esp
popl %ebp
ret

funcao10:

pushl %ebp
movl %esp, %ebp

movl sinal, %edx
movl g_dividendo, %eax
idivl g_divisor

movl %ebp, %esp
popl %ebp
ret

funcao11:

pushl %ebp
movl %esp, %ebp

movl sinal, %edx
movl g_dividendo, %eax
idivl g_divisor
movl %eax, g_quociente

movl %ebp, %esp
popl %ebp
ret

inicializaChar:

pushl %ebp
movl %esp, %ebp

movl $0x65, %eax
movl %eax,p

movl %ebp, %esp
popl %ebp
ret
