.text

.global calcula_total_maiores
.global valor_accao

valor_accao:
pushl %ebp
movl %esp, %ebp

movb 8(%ebp), %bl #char em ebx
movl 12(%ebp), %ecx #ap para vector em ecx
movl $0, %eax
ciclo:
	incl %ecx
	rcrl $16, (%ecx) # para ficar com o char em cl e numero de accoes em ch
	cmpb %bl, %cl #compara o char passado por parametro com o da posicao
	jne ciclo
	movb %ch, %al
	rcll $16, (%ecx) #para ficar com o o valor da accao em cx
	imulw %cx, %ax #multiplica o valor da accao por o numero de accoes, para daro custo total e ficar em eax
	idivl $10, %eax #divide eax por 10 para retornar apenas os euros
	jmp fim
fim:
movl %ebp, %esp
popl %ebp
ret

calcula_total_maiores:
pushl %ebp
movl %esp, %ebp
pushl %edx
pushl %esi
pushl %ebx

movl 8(%ebp), %edx #valor de referencia
movl 12(%ebp), %esi #numero de accoes
movl 4(%esi), %ebx #aponta para primeira posicao

movl $0, %edi #inicializar o contador do total
chama_funcao:
	cmpl $0, %esi #ve se ja percorreu todas as posicoes
	je fim2
	rcrl $24, (%ebx) #roda o numero para passar o char actual para a stack, que vai ser o primeiro parametro da funcao que chamamos
	pushb %bl
	rcll $24, (%ebx)
	pushl %ebx #passa o segundo parametro, o apontador para o vector
	call valor_accao
	incl %ebx #passar a proxima posicao do vector
	cmp %edx, %eax #ao comparar edx com eax ficamos a saber se o valor da funcao e maior que o da referencia, logo sabemos se e para o adicionar ao total
	jl menor
	maior:
		addl %eax, %edi #adiciona ao total que ira ser retornado
	menor:
	decl %esi #decrementa o contador das vezes que a funcao e executada, para que possa ser 0 quando todas as posicoes forem percorridas
	jmp chama_funcao
fim2:
popl %ebx
popl %esi
popl %edx

movl %edi, %eax #o programa retorna sempre eax, por isso temos que passar o total para la
movl %ebp, %esp
popl %ebp
ret
