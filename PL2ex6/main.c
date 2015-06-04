#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int main(void)
{
	int din, apo, pid, status;
	din = 25;

	while(din >= 0){
		printf("Insira valor a apostar.");
		scanf("%d", &apo);
		pid = fork();
		if(pid>0){
			wait(&status);
			if(status==1){
				din+=(apo*2);
			}else{
				din-=apo;
			}
		}else{
			execl("/media/aufs/media/sf_ARQCPVM/eclipse/PL2ex1", "batota.c", NULL);
		}
	}
	return 0;
}
