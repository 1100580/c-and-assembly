.text
.global rotinas

rotinas:
#Prologo
pushl %ebp
movl %esp, %ebp
pushl %ebx #numero a ser trabalho
pushl %ecx #contador de controlo de bits (foram considerados 8 bits para TESTE)
pushl %esi #variavel auxiliar
pushl %edi #variavel auxiliar para as mascaras
movl 8(%ebp), %ebx #le o numero passado
movl 12(%ebp), %eax #le o array

#Corpo
movl $7, %ecx #o contador de controlo é inicializado a 7
movl %ebx, %edx #guarda o parametro original
movl $1, %edi # inicia a mascara

inicio:
movl $7, %esi
cmpl $0, %ecx #compara com 0
jl fim #se for menor que 0, percorreu os bits todos, passa para o fim
jge calculo #ainda nao foram percorridos todos os bits, avanca para o calculo

calculo:
andl %edi, %ebx #retira o bit a 1
cmpl $0, %ebx #compara com 0 (se for 0, nao encontrou nenhum bit activo)
jne categoriaExistente # se diferente de 0, o trabalhador esteve/esta registado na categoria
je decrementa # senao, avanca para o proximo bit

categoriaExistente:
subl %ecx, %esi #vai encontrar a posição do bit
movl %esi, (%eax) #passa a posição para o array
cmpl $0, %ecx #compara com 0
je decrementa
addl $4, %eax #proxima posicao do array
jmp decrementa

decrementa:
decl %ecx
movl %edx, %ebx #repoe o valor
imull $2, %edi #altera a mascara para o bit seguinte
jmp inicio

#Epilogo
fim:
popl %ebx
popl %ecx
popl %esi
movl %ebp, %esp
popl %ebp
ret
