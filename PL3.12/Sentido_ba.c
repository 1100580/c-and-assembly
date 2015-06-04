#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

int cria_semaforo(int chave,int n_sem, int n_recursos[n_sem]){
	int semid,i;
	if((semid=semget(chave,n_sem, 0666 | IPC_CREAT | IPC_EXCL))==-1){
		if((semid=semget(chave,n_sem, 0666 | IPC_CREAT))==-1){
			perror("semget");
			exit(1);
		}
	}else{
		for(i=0;i<n_sem;i++){
			if(semctl(semid,i, SETVAL, n_recursos[i])==-1){
				perror("semctl:setval");
				exit(1);
			}
		}
	}
	return semid;
}

int down(int identificador,int posicao,int n_recursos){
	if(n_recursos>=0)
		return -1;
	struct sembuf al={posicao,n_recursos,0};
	if(semop(identificador,&al,1)==-1){
		perror("semop:down");
		exit(1);
	}
	return 0;
}

int up(int identificador,int posicao,int n_recursos){
	if(n_recursos<=0)
		return -1;
	struct sembuf al={posicao,n_recursos,0};
	if(semop(identificador,&al,1)==-1){
		perror("semop:up");
		exit(1);
	}
	return 0;
}

void block(int identificador,int posicao){
	struct sembuf block={posicao,0,0};
	if(semop(identificador,&block,1)==-1){
		perror("semop:block");
		exit(1);
	}
}

void remove_semaforo(int identificador){
	union semun arg;
	if (semctl(identificador, 0, IPC_RMID, arg) == -1) {
		perror("semctl:remove_semaforo");
		exit(1);
	}
}

int main(int argc, char *argv[]){
	/* semid - acesso a memoria partilhada AB-1 BA-0*/
	/* semid2 - carros na ponte */
	/*shmid - sentido */
	int semid,semid2,v[1]={1},v2[1]={15},shmid,*sentido,espera,ponte;
	key_t key;
	union semun arg;
	key=ftok("Sentido_ba.c",6);

	semid=cria_semaforo(atoi(argv[1]),1,v);
	semid2=cria_semaforo(key,1,v2);

	if((shmid=shmget(atoi(argv[2]), sizeof(int), 0666 | IPC_CREAT | IPC_EXCL)==-1)){
		if((shmid=shmget(atoi(argv[2]), sizeof(int), 0666 | IPC_CREAT)==-1)){
			perror("shmget");
			exit(1);
		}
		if(c=shmat(shmid, (void *) 0, 0)==(void*)-1)
			perror("Erro shmat\n");
	}else{
		if(c=shmat(shmid, (void *) 0, 0)==(void*)-1)
			perror("Erro shmat\n");
		*c=1;
	}
	while(1){
		down(semid,0,-1);
		if(*c==0){
			up(semid,0,-1);
			down(semid2,0,-1);
			printf("Na ponte...\n");
			sleep(2);
			printf("Demorou n segundos...\n");
			espera=semctl(semid2,0,GETNCNT,arg);
			ponte=semctl(semid2,0,GETVAL,arg);
			if(espera==0 && ponte==14){
				down(semid,0,-1);
				*c=1;
				up(semid2,0,1);
				up(semid,0,1);
			}else{
				up(semid2,0,1);
			}
			break;
		}
		up(semid,0,1);
	}
	return 0;
}
