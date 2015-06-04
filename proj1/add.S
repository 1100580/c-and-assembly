# add.S

.text

# funcao em assembly que adiciona dois numeros inteiros (passados pela stack)
# int add (int n1, int n2)
.global add
add:
# prologo da funcao
	pushl %ebp			# guardar a stack frame anterior
	movl %esp, %ebp		# o novo stack framde de "add"

# corpo da funcao
	movl 8(%ebp), %eax		# colocar o n1 (primeiro parametro) no eax
	addl 12(%ebp), %eax		# adicionar o (segundo parametro) ao eax

# epilogo da funcao
	movl %ebp, %esp			# voltar a colocar o esp no local original para o "ret"
	popl %ebp				# repor o stack frame da funcao que invocou esta
	ret

# funcao em assembly que adiciona dois numeros inteiros cujos apontadores são passados pela stack. O resultado e' devolvido como retorno da funcao em eax
# int add2 (int* n1, int* n2)
.global add2
add2:
# prologo da funcao
	pushl %ebp			# guardar a stack frame anterior
	movl %esp, %ebp		# o novo stack framde de "add"

	pushl %ebx			# vamos guardar o valor actual dos registos que esta funcao utiliza
	pushl %ecx

# corpo da funcao
	movl 8(%ebp), %ebx		# colocar o primeiro apontador (primeiro parametro) no ebx
	movl 12(%ebp), %ecx		# colocar o segundo apontador (segundo parametro) no ecx

	movl (%ebx), %eax
	addl (%ecx), %eax

# epilogo da funcao
	popl %ecx			# vamos repor o valor dos registos que esta funcao utilizou
	popl %ebx

	movl %ebp, %esp			# voltar a colocar o esp no local original para o "ret"
	popl %ebp				# repor o stack frame da funcao que invocou esta
	ret

# funcao em assembly que adiciona dois numeros inteiros cujos apontadores sao passados pela stack e que devolve o resultado no endereco apontado pelo terceiro parametro
# void add3 (int* n1, int* n2, int* res)
.global add3
add3:
# prologo da funcao
	pushl %ebp			# guardar a stack frame anterior
	movl %esp, %ebp		# o novo stack framde de "add"

	pushl %ebx			# vamos guardar o valor actual dos registos que esta funcao utiliza
	pushl %ecx
	pushl %edx

# corpo da funcao
	movl 8(%ebp), %ebx		# colocar o primeiro apontador (primeiro parametro) no ebx
	movl 12(%ebp), %ecx		# colocar o segundo apontador (segundo parametro) no ecx
	movl 16(%ebp), %edx

	movl (%ebx), %eax
	addl (%ecx), %eax
	movl %eax, (%edx)

# epilogo da funcao
	popl %edx			# vamos repor o valor dos registos que esta funcao utilizou
	popl %ecx
	popl %ebx

	movl %ebp, %esp			# voltar a colocar o esp no local original para o "ret"
	popl %ebp				# repor o stack frame da funcao que invocou esta
	ret

