#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
void executa(char* cmd);

int main(void)
{
	int i, pid;
	char* cmd[] = { "ls", "ps", "who", NULL };
	while(cmd[i] != NULL){
		pid = fork();
		if(pid>0){

		}else{
			execlp(*cmd[i], args);
		}
	}
	return 0;
}



