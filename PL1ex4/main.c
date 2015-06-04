#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
	pid_t pid;
	int f;
	int status;
	int aux;
	for (f = 0; f < 3; f++)
	{
		pid = fork(); /* Cria um PROCESSO */
		if (pid > 0) /* Código do PAI */{
			printf("Pai: Eu sou o PAI\n");
			if(f==1){
				do{
					aux = waitpid(pid, &status, WNOHANG);
					if (aux==-1)
					{
						perror("Erro em waitpid");
						exit(-1);
					}
					if (aux == 0)
					{
						//printf(".\n");
						sleep(1);
					}
				} while (aux == 0);
				if (WIFEXITED(status))
				{
					printf("Pai: o filho retornou o valor:%d com o ID:%d\n",WEXITSTATUS(status), getpid());
				}
			}
		}else /* Código dos FILHOS */{
			sleep(1);
			printf("Filho: Eu sou o FILHO de ID:%d\n", getpid());
			exit(f);
		}
	}
	return 0;
} /* fim main */
