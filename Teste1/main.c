/* sdemo08.c */ /* leitor da memoria partilhada */
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>

 int main()
 {
	 void *memoria_partilhada = (void *) 0;
	 /* apontador para o segmento de memoria partilhada */
	 int *aponta;
	 int shmid;
	 key_t key;
	 char *vecS = "Texto";

	 /* cria ou utiliza o segmento de memoria partilhada */
	 key=ftok("main.c", 0);

	 shmid = shmget(key, sizeof(vecS), 0666 | IPC_CREAT);
	 if (shmid == -1) {
		 printf("Erro !!!\n");
		 exit(-1);
	 }

	 memoria_partilhada = shmat(shmid, (void *) 0, 0);
	 if (memoria_partilhada == (void *) -1) {
		 printf("Erro ao fazer shmat\n");
		 exit(-1);
	 }

	 printf("A memoria esta ligada em %X\n", (int) memoria_partilhada);
	 aponta = (int *) memoria_partilhada;
	 printf("O valor que esta na regiao de memoria partilhada e %s\n",*aponta);
	 *aponta = vecS;
	 printf("O novo valor na regiao de memoria partilhada e %s\n", *aponta);
	 /* "Desliga-se" da regiao de memoria partilhada */
	 if (shmdt(memoria_partilhada) == -1) {
		 printf("Erro ao fazer shmdt\n");
		 exit(-1);
	 }

	 /* para remover a regiao de memoria partilhada,
 	 tire o comentario nas seguintes linhas */
	 if (shmctl(shmid, IPC_RMID, 0) == -1) {
 	 	 printf("Erro ao remover a regiao de memoria partilhada\n");
 	 	 exit(-1);
	}

	return 0;
}
