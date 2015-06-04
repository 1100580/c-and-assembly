#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int enviado;
	FILE *executa;
	int* dados[2];
	int status;
	char* buffer[80];

	pid = fork();

	if(pid>0){
		close(dados[1]);
	}else{
		close(dados[0]);
		dup2(dados[1],1);
	}

	return 0;
}
