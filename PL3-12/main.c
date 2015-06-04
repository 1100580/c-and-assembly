#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>

int main(){
	pid_t pid;
	int i;
	key_t keyS,keyM;
	keyS=ftok("main.c",6);
	keyM=ftok("main.c",7);

	for(i=0;i<30;i++){
		pid=fork();
		if(pid<0) perror("fork()");
		else if(pid==0) break;
	}

	if(pid==0){
		if(i%2==0){
			execlp("./sentido_ab","sentido_ab",keyS,keyM,NULL);
			perror("exec");
			exit(-1);
		}else{
			execlp("./sentido_ba","sentido_ab",keyS,keyM,NULL);
			perror("exec");
			exit(-1);
		}
	}else{
		for(i=0;i<30;i++){
			wait(NULL);
		}
		printf("Todos os carros passaram a ponte\n");
	}
	return 0;
}

