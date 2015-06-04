#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	int pid;
	int* res[100];
	int i;
	int status;

	pid=fork();
	if(pid > 0)
	{
		for(i = 0; i < 50; i++)
		{
			*res[i] = (int)(i*4+20);
		}
		wait(&status);
		for(i = 0; i < 50; i++)
		{
			printf("%d", *res[i]);
		}
	}else{
		for(i = 50; i < 100; i++)
		{
			*res[i] = (int)(i*4+20);
		}
		for(i = 50; i < 100; i++)
		{
			printf("%d", *res[i]);
		}
	}
	return 0;
}
