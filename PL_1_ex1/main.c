#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
	pid_t a,p;
	int status1, status2;
	a=fork();
	if(a>0)/*O pai*/
	{
		waitpid(a, &status1, 0);
		if (WIFEXITED(status1))
		{
			printf("Pai: o filho 1 retornou o valor:%d\n",WEXITSTATUS(status1));
		}
		p=fork();
		if(p==0){
			printf("Filho 2 termina.\n");
			exit(2);
		}
		waitpid(p, &status2,0);
		if (WIFEXITED(status2)){
			printf("Pai: o filho 2 retornou o valor:%d\n",WEXITSTATUS(status2));
		}
	}else{ /*O 1 filho*/
		sleep(5);
		printf("Filho 1 termina\n");
		exit(1);
	}
	return 0;
}
