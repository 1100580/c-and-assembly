#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
		int pid;
		int dados[2];
		char env[20];
		FILE* f;

		f = fopen("fich.txt", "r");
		fgets(env, 20, f);

		pipe(dados);
		pid = fork();

		if(pid>0){
			close(dados[0]);
			write(dados[1], env, sizeof(env)+1);
		}else{
			dup2(dados[0],0);
			close(dados[1]);
			execlp("sort", "sort", NULL);
		}
	return 0;
}
