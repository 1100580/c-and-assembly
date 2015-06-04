.data
texto:
.asciz "N= %d\n"
.text

.global print_n

print_n:
pushl %ebp
movl %esp, %ebp
movl 8(%ebp), %ecx

cmp $1, %ecx
jl cont
pushl %ecx
pushl $texto
call printf
addl $8,%esp
jmp fim
cont:
dec %ecx
pushl %ecx
call print_n
addl $4, %esp
movl 8(%ebp), %ecx
inc %ecx
pushl %ecx
pushl $texto
call printf
addl $8,%esp

fim:
movl %ebp, %esp
popl %ebp
ret
