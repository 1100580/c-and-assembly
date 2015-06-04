.text

.global menor_dataA

menor_dataA:
pushl %ebp
movl %esp, %ebp

movl 8(%ebp), %ebx
movl 12(%ebp), %ecx

cmpw %bx, %cx
je cmes
jg data1
jl data2
cmes:
rcr $24, %ebx
rcr $24, %ecx
movb %bl, %al
movb %cl, %ah
rcl $24, %ebx
rcl $24, %ecx
cmpb %al, %ah
je cdia
jg data1
jl data2
cdia:
rcr $16, %ebx
rcr $16, %ecx
movb %bl, %al
movb %cl, %ah
rcl $16, %ebx
rcl $16, %ecx
cmpb %al, %ah
je igual
jg data1
jl data2

data1:
movl %ebx, %eax
data2:
movl %ecx, %eax
igual:
movl $0, %eax

movl %ebp, %esp
popl %ebp
ret
