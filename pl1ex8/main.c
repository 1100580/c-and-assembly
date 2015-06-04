#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int main(void)
{
	int pid,i;
	for(i = 0; i < 2; i++)
	{
		pid = fork();
		if(pid > 0){
			printf("A\n");
		}else{
			printf("B\n");
			pid = fork();
			if(pid > 0){
				printf("A\n");
				exit(0);
			}
		}
	}
	return 0;
}
