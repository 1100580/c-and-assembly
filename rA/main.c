#include <stdio.h>
#include "rotinas.h"
#define NUM_MAX_CAT 8
int main(){
	int op;
	int i;
	int array[NUM_MAX_CAT];
	for(i=0; i<NUM_MAX_CAT;i++){
		array[i]=-1;
	};

	printf("Qual a tarefa a efectuar?\n");
	printf("1-Categorias em que um funcion�rio esteve\n");
	printf("2-Categoria em que um funcion�rio est�\n");
	printf("3-N�mero de categorias em que um funcion�rio j� esteve\n");
	printf("4-O n�mero de funcion�rios numa dada categoria\n");

	scanf("%d",&op);
	if(op==1 || op==2 || op==3)
	{
		int nFunc;
		printf("Qual o ID do funcion�rio?");
		scanf("%d",&nFunc);
		int cats = 13;//getCat(nFunc);
		rotinas(cats, array);
		if(op==1)
			for(i = 0; i < NUM_MAX_CAT; i++)
				printf("Categoria %d", array[i]);
	}
	for(i=0; i<NUM_MAX_CAT;i++){
		printf("TESTE %d\n", array[i]);
	};

	return 0;
}
