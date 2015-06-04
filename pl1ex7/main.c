#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	int i, pid, status,x;
	for(i = 0; i < 7; i++)
	{
		pid=fork();
		if(pid > 0){
			wait(&status);
		}else{
			for(x = i*200; x < (i+1)*200; x++)
			{
				printf("%d\n",x);
			}
			exit(0);
		}
	}
	return 0;
}
