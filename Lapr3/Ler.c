#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "Grava.h"

dados* ler(char *path){

	int cont;
	cont = 0;
	int i;
	i=0;
	int x;
	x=0;
	char aux[50];
	char nome[80];
	char * cat;
	int num;
	int linhas;
	linhas = 0;

	FILE *fp; fp =fopen(path,"r");
	if (fp==NULL)
	{
		fprintf(stderr,"Erro no fopen %s \n","ficheiro.bin");
	}
	
	char line[128];

	while (fgets(line,sizeof(line),fp)!= NULL){
		linhas++;
	}
	printf("Linhas: %d", linhas);
	fclose(fp);

	dados *data = NULL;
	data = (dados*) malloc(linhas*sizeof(dados));

	fp = fopen(path,"r");
	while (fgets(line,sizeof(line),fp)!=NULL){ //para cada linha
		x=0;
		strcpy(aux," ");
		while (line[x]!=','){ //para o numero
			if(x==0){
				strncpy(aux,(line+x),1);
			}else{
				strncat(aux,(line+x),1);
			}
			x++;
		}
		num=atoi(aux);
		printf("Numero: %d\n",num);
		data[cont].num = num;

		x++;
		strcpy(aux," "); //reset string
		while(line[x]!=','){ //para o nome
			strncat(aux,(line+x),1);
			x++;
		}
		strcpy(nome,aux);
		strcat(nome,"\n");
		printf("Nome:  %s\n",nome);
		strcpy(data[cont].nome, nome);


		x++;
		strcpy(aux,"");
		while (line[x]!='\0'){ // enquanto linha nao termina
			if(line[x]!='>' && line[x]!=',' && line[x]!='\n'){
				strncat(aux,line+x,1);
			}
			x++;
		}
		cat = aux;
		printf("Cats:   %s\n",cat);

		int dois;
		int total;
		int dig;
		int k;
		k = 0;
		dois = 1;
		total = 0;
		char digito[2] = "a\0";
		while(cat[k] != '\0'){
			strncpy(digito, cat+k, 1);
			dig = atoi(digito);
			int z;
			for(z = 0; z < dig-1; z++){
				dois = dois*2;
			}
			total = total | dois;
			k++;
			printf("Total: %d \n", total);
			dois = 1;
		}
		data[cont].categoria = total;
		cont++;
	}
	fclose(fp);
	return data;
}
