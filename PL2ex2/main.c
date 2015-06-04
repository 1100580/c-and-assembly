#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int main(void)
{
	char* comando;
	int pid, status;
	while(strcmp(comando,"sair")==1){
		scanf("%s", comando);
		pid=fork();
		if(pid>0){
			wait(&status);
		}else{
			execlp(comando, comando, NULL);
		}
	}
	return 0;
}
