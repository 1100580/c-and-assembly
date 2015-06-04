#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <string.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *__buf;
};

int main(){

	void *memoria_partilhada = (void *) 0;
	int *aponta;
	int semid, shmid, i, pid;
	key_t key;
	union semun arg;
	struct sembuf up = {0, 1, 0};
	struct sembuf down = {0, -1, IPC_NOWAIT};
	struct sembuf cortar = {1, -1, 0};
	struct sembuf acabar = {1, 1, 0};

	key=ftok("main.c", 98);
	shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
		if (shmid == -1) {
		printf("Erro !!!\n");
		exit(-1);
	}

	memoria_partilhada = shmat(shmid, (void *) 0, 0);
	if (memoria_partilhada == (void *) -1) {
		printf("Erro ao fazer shmat\n");
		exit(-1);
	}
	aponta = (int *) memoria_partilhada;
	*aponta = 0;

	if ((semid = semget(key, 2, 0666 | IPC_CREAT)) == -1) {
		perror("semget");
		exit(1);
	}

	arg.val = 5; /* 5 cadeiras */
	if (semctl(semid, 0, SETVAL, arg) == -1) {
		perror("semctl");
		exit(1);
	}
	arg.val = 0;
	if (semctl(semid, 1, SETVAL, arg) == -1) {
		perror("semctl");
		exit(1);
	}

	for(i = 0; i < 5; i++){
		pid=fork();
		if(pid == 0){
			break;
		}
	}

	if(pid > 0){
		while(1){
			if (semop(semid, &cortar, 1) == -1) {
				perror("semop");
				exit(1);
			}
			printf("Valor::::: %d", *aponta);
			(*aponta)++;
			printf("Valor::::: %d", *aponta);
		}
	}else if(pid == 0){	/*Cliente senta*/
		printf("Chega o cliente %d ",i);
		if (semop(semid, &down, 1) == -1) {
			perror("semop filho");
			exit(1);
		}
		int var;
		var = semctl(semid,0,GETVAL,arg);
		if(var >= 0){
			printf("e senta.\n");
			while(i!=*aponta){sleep(1);}
				sleep(3);
				if (semop(semid, &acabar, 1) == -1) {
					perror("semop");
					exit(1);
				}
				if (semop(semid, &up, 1) == -1) {
					perror("semop");
					exit(1);
				}
				printf("Cabelo do cliente %d cortado.\n", i);
			}else{
			printf(",mas a sala esta cheia.\n");
		}
		exit(i);
	}

	return 0;
}

/*10. O barbeiro dorminhoco. A barbearia consiste numa sala de espera com n cadeiras mais a
cadeira do barbeiro. As regras de funcionamento da barbearia são as seguintes:
Se não existirem clientes o barbeiro fica a dormir;
Ao chegar um cliente:
Se todas as cadeiras estiverem ocupadas, este vai-se embora;
Se o barbeiro estiver ocupado, mas existirem cadeiras então o cliente senta-se e fica
à espera;
Se o barbeiro estiver a dormir o cliente acorda-o e corta o cabelo.
Teste o programa desenvolvido, começando por executar um barbeiro e vários clientes.
Depois, execute vários barbeiros e vários clientes.
*/
