#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int dados[2];
	FILE *f;
	f = fopen("ficheiro.txt","r");

	char resultado[20], enviado[20];
	fgets(enviado,20,f);
	int pid;

	pipe(dados);

	pid = fork();

	if(pid > 0){
		close(dados[0]);
		write(dados[1], enviado, sizeof(enviado)+1);
	}else{
		close(dados[1]);
		read(dados[0], resultado, sizeof(resultado)+1);
		printf("O resultado foi %s", resultado);
	}
	return 0;
}
