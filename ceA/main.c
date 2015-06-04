#include <stdio.h>
#include "rotinas.h"
#define NUM_MAX_CAT 8
int main(){
	int op;
	int num=13;
	int array[NUM_MAX_CAT];
	int i;
	int nFunc;
	int cat;
	int maior;
	maior = -1;
	for(i=0; i<NUM_MAX_CAT;i++){
		array[i]=-1;
	};

	printf("Qual a tarefa a efectuar?\n");
	printf("1-Categorias em que um funcionário esteve\n");
	printf("2-Categoria em que um funcionário está\n");
	printf("3-Número de categorias em que um funcionário já esteve\n");
	printf("4-O número de funcionários numa dada categoria\n");

	scanf("%d",&op);
	if(op==1 || op==2 || op==3)
	{
		printf("Qual o ID do funcionário?");
		scanf("%d",&nFunc);
		//num = getCats();
		rotinas(num, array);
		
		if(op==1){
			for(i=0; i<NUM_MAX_CAT;i++){
				if(array[i]!=-1){printf("Categoria %d\n", array[i]+1);}
			};
		}else if(op==2){
			for(i=0; i<NUM_MAX_CAT;i++){
				if(array[i]>maior){maior = array[i];}
			};
			printf("Categoria actual: %d\n", maior+1);
		}else if(op==3){
			for(i=0; i<NUM_MAX_CAT;i++){
				if(array[i+1]!=-1 && array[i]!=-1){printf("Categoria: %d\n", array[i]+1);}
			};
		}
	}else{
	/*
		printf("Qual a categoria?");
		scanf("%d",&cat);

		FILE *fp; fp =fopen(path,"r");
		if (fp==NULL)
		{
			fprintf(stderr,"Erro no fopen %s \n","ficheiro.bin");
		}
		while (fgets(line,sizeof(line),fp)!=NULL){
			//nFunc = line[0];
			nFunc = 1;
			//num = getCat();
			rotinas(num,array);
			for(i = 0; i < NUM_MAX_CAT; i++){
				if(cat==array[i]){printf("Funcionario %d", nFunc);}
			}
		}
	*/
	}
	return 0;
}
