#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun
{
	int val; /* valor para SETVAL */
	struct semid_ds *buf; /* buffer para IPC_STAT e IPC_SET */
	unsigned short int *array; /* vector para GETALL e SETALL */
	struct seminfo *__buf; /* buffer para IPC_INFO */
};

int main(void)
{
	union semun semun;
	int i, pid, status;
	status = 0;
	FILE * f;
	struct sembuf sb = {0, -1, 0};

	int key,sem;
	key=(int)ftok("msads", 0);

	sem=semget(key,1,IPC_CREAT|0666);
	semun.val = 1;
	semctl(sem, 0, SETVAL, semun);

	for(i = 0; i < 5; i++){
		pid = fork();
		if(pid>0){}
		else{
			break;
		}
	}

	if(pid>0){
	}else{
		semop(sem, &sb, 1);
		int value;
		printf("Value: %d", i);
		scanf("%d",&value);
		f = fopen("texto.txt", "a+");
		fprintf(f,"%d\n",value);
		fclose(f);
		sb.sem_op = 1;
		semop(sem, &sb, 1);
		sb.sem_op = -1;
	}

	return 0;
}
