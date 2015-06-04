#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int main(void)
{
	void* memPart = (void *)0;
	int* aponta;
	int* shmid;
	key_t key;
	int i, x, pid, status,num;
	status = 0;
	int* vec[1000];
	int* maiores[10];

	for(i = 0; i < 1000; i++){
		  srand ( time(NULL) );
		  *vec[i] = rand() % 10 + 1;
	}

	key = ftok("cenas", 0);
	shmid = shmget(key, sizeof(maiores), 0666 | IPC_CREAT);
	if (shmid == -1) {
		printf("Erro !!!\n");
		exit(-1);
	}

	for(i = 0; i < 10; i++){
		pid = fork();
		if(pid>0){}
		else{
			break;
		}
	}

	if(pid>0){
		int maiorM;
		wait(&status);
		memoria_partilhada = shmat(shmid, (void *) 0, 0);
		if (memoria_partilhada == (void *) -1) {
			printf("Erro ao fazer shmat\n");
			exit(-1);
		}
		aponta = (int *) memoria_partilhada;

		for(i = 0; i < 10; i++){
			if(*aponta+i > maiorM){
				maiorM = *aponta+i;
			}
		}

		if (shmdt(memoria_partilhada) == -1) {
			printf("Erro ao fazer shmdt\n");
			exit(-1);
		}

		printf("Maior valor: %d", &maiorM);
	}
	else{
		int maior;
		for(x = i*100; x < (i+1)*100; x++){
			maior = *vec[x];
		}

		memoria_partilhada = shmat(shmid, (void *) 0, 0);
		if (memoria_partilhada == (void *) -1) {
			printf("Erro ao fazer shmat\n");
			exit(-1);
		}
		aponta = (int *) memoria_partilhada;

		*aponta+i = maior;

		/* "Desliga-se" da regiao de memoria partilhada */
		if (shmdt(memoria_partilhada) == -1) {
			printf("Erro ao fazer shmdt\n");
			exit(-1);
		}
		exit(i);
	}
	return 0;
}
