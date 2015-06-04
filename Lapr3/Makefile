main: Grava.o Ler.o
	gcc -Wall -g -o main Grava.o Ler.o

Grava.o: Grava.c Grava.h
	gcc -Wall -g -c Grava.c

Ler.o: Ler.c Ler.h
	gcc -Wall -g -c Ler.c

run: main
	./main
