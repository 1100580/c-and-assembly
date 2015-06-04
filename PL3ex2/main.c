#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int dados[5][2];

	int i, x, k, pid, status;
	int vec1[10] = {1,2,3,4,5,6,7,8,9,9}, vec2[10] = {1,2,3,4,5,6,7,8,9,9}, res[10] = {0,0,0,0,0,0,0,0,0,0};
	for(i = 0; i < 5; i++){
		pipe(dados[i]);
		pid = fork();
		if(pid == 0){
			break;
		}
	}

	if(pid>0){
		//wait(&status);
		for(k = 0; k < 5; k++){
			close(dados[k][1]);
			for(x = i*2; x < (i+1)*2; x++){ //i processos * 2 numeros
				int num = read(dados[k][0], &res[x], sizeof(int));
				printf("NUM; %d RES+X;%d\n", num, res[x]);
			}
			close(dados[k][0]);
		}
		for(k = 0; k < 10; k++){
			printf("%d\n", res[k]);
		}
	}
	else{
		close(dados[i][0]);
		int res;
		for(x = i*2; x < (i+1)*2; x++){ //i processos * 2 numeros
			res = *(vec1+x) + *(vec2+x);
			//printf("i=%d x=%d Num: %d\n",i,x, res);
			write(dados[i][1], &res, sizeof(int));
		}
		close(dados[i][1]);
		exit(i);
	}

	return 0;
}
