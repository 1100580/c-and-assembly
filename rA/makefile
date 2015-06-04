main: main.o rotinas.o
	gcc -Wall -g -o main main.o rotinas.o
main.o: main.c rotinas.h
	gcc -Wall -g -c main.c
rotinas.o: rotinas.s
	gcc -Wall -g -c rotinas.s
run: main
	./main
clean:
	rm *.o main