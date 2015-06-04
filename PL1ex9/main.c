#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int main(void)
{
	int i, x, pid, status,num;
	status = 0;
	scanf("%d",&num);
	int* vec[10];
	pid = fork();
	for(i = 0; i < 4; i++){
		if(pid>0){
			pid=fork();
		}
		else{
			break;
		}
	}

	if(pid>0){
		wait(&status);
		printf("Processo: %d\n", status);
	}
	else{
		for(x = i*2; x < (i+1)*2; x++){ //i processos * 2 numeros
			if(num == *vec[x]){
				printf("%d\n", *vec[x]);
				exit(i);
			}
		}
	}

	return 0;
}
