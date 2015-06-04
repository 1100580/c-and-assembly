.text

.global quadrado
.global somatorio_n
.global menor
.global devolve_soma_e_maior
.global troca
.global testaiguais

quadrado:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp),%eax
imull %eax

movl %ebp, %esp
popl %ebp
ret

somatorio_n:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp),%ebx #max
movl $0, %ecx #contador
movl $0, %eax #soma
loop:
cmpl %ebx, %ecx
je fim
inc %ecx
addl %ecx, %eax
jmp loop
fim:
movl %ebp, %esp
popl %ebp
ret

menor:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp), %eax
movl 12(%ebp), %ebx
movl 16(%ebp), %ecx

cmpl %eax, %ebx
jg a
jl b
a:
cmp %eax, %ecx
jg reta
jl retc
b:
cmp %eax, %ecx
jg retb
jl retc
reta:
jmp fim2
retb:
movl %ebx, %eax
jmp fim2
retc:
movl %ecx, %eax
jmp fim2
fim2:
movl %ebp, %esp
popl %ebp
ret

devolve_soma_e_maior:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp), %eax
movl 12(%ebp), %ebx
movl 16(%ebp), %ecx

cmpl %eax, %ebx
jl a2
jg b2
a2:
movl %eax, (%ecx)
jmp adi
b2:
movl %ebx, (%ecx)
jmp adi
adi:
addl %ebx, %eax

movl %ebp, %esp
popl %ebp
ret

troca:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp), %eax
movl 12(%ebp), %ebx

movl (%eax), %ecx
movl (%ebx), %edx
movl %ecx, (%ebx)
movl %edx, (%eax)

movl %ebp, %esp
popl %ebp
ret

testaiguais:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp), %ebx
movl 12(%ebp), %ecx
movl $1, %eax

ciclo:
movb (%ebx), %cl
movb (%ecx), %ch
cmpb $0, %cl
je fim3
cmpb %cl, %ch
je igual
jmp dif
igual:
inc %ecx
inc %ebx
jmp ciclo
dif:
movl $0, %eax
fim3:
movl %ebp, %esp
popl %ebp
ret
