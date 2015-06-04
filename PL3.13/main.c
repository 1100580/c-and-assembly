#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>

/*main lanca clientes (processos) pares querem fazer uma coisa impares outra.
 * sao passados como parametro a zona de memoria com as contas, qual a conta a aceder e se necessario o valor a levantar
 * outros 2 programas modificam as zonas de memoria ou apresentam o seu valor*/
int main(){
	int i,pid;
	for(i = 0; i < 4; i++){
		pid=fork();
		if(pid==0)
			break;
	}

	if(pid>0){
		while(1){
			/*tentar levantar dinheiro(numero da conta na memPart, valor na memPart)*/
			/*tentar servir consulta de saldo(numero da conta na memPart)*/
		}
	}else{
		printf("Chega o cliente %d.\n",i);
		while(i!=*aponta) sleep(1);

	}


	return 0;
}
