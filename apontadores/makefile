apontadores: main.o
	gcc main.o -o apontadores

main.o: main.c
	gcc -c main.c -o main.o

run: apontadores
	./apontadores

clean:
	rm main.o apontadores