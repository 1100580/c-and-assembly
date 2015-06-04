#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union opera
{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *__buf;
};

int main(){
	FILE *f;
	f = fopen("texto.txt", "a+");

	struct sembuf down = {0, -1, 0};
	struct sembuf down2 = {1, -1, 0};
	struct sembuf up = {0, 1, 0};
	//struct sembuf up2 = {1, 1, 0};
	union opera o;
	int semid;
	key_t key;

	/* Atribui unique key*/
	if((key = (int)ftok("sem05.c", 0)) == -1){
		perror("ftok");
	}
	/* Get vetor de semaforos*/
	if ((semid = semget(key, 2, 0666 | IPC_CREAT)) == -1) {
		perror("semget");
	}
	/*inicializa semaforo 0 com arg.val*/
	o.val = 1;
	if (semctl(semid, 0, SETVAL, o) == -1) {
		perror("semctl");
	}

	/*inicializa semaforo 0 com arg.val*/
	o.val = 10;
	if (semctl(semid, 1, SETVAL, o) == -1) {
		perror("semctl");
	}

	if((semop(semid, &down, 1)) == -1){
		perror("semop1");
	}
	if((semop(semid, &down2, 1)) != -1){
		printf("A escrever\n");
		fprintf(f,"Linha\n");
		sleep(2);
		printf("Escrito\n");
	}else{
		perror("semop2");
	}
	if((semop(semid, &up, 1)) == -1){
		perror("semop1");
	}

	fclose(f);

	return 0;
}
