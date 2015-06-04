#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	return 0;
}

char cria_gemeos(pid_t lista[2]){
	int pid,status;
	pid = fork();
	if(pid>0){
		pid = fork();
		if(pid>0){
			wait(&status);
			return 'p';
		}else{
			lista[1]=getpid();
			return 'b';
		}
	}else{
		lista[0]=getpid();
		return 'a';
	}
}
