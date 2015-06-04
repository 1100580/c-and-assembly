# exemplo de makefile 
# variaveis do make
INCLUDES =  
SOURCES = main.c 
OBJFILES = main.o add.o 

# regras de sufixo
.SUFFIXES : .c .o
.SUFFIXES : .S .o

# como transformar um .c num .o ; $< -- nome do ficheiro
.c.o:
	gcc -g -ansi -Wall  -c $<  

# como transformar um .S num .o ; $< -- nome do ficheiro
.S.o:
	gcc -c -g $<  
		
# o eclipse assume que o target por defeito chama-se "all"	
all: proj1	

# para fazer o programa principal 
proj1: ${OBJFILES}
	gcc -g -o proj1  ${OBJFILES}


main.o: main.c 

run:  proj1
	./proj1

clean: 
	rm ${OBJFILES} proj1 
	

