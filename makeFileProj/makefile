makeFileProj: media.o main.o
	gcc media.o main.o -o makeFileProj

media.o: media.c
	gcc -c media.c -o media.o

main.o: main.c
	gcc -c main.c -o main.o

run: makeFileProj
	./makeFileProj

clean:
	rm media.o main.o makeFileProj