#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int numero;
	char nome[50];
}DADOS;

void criaStrDin(char a, char b, char c, char d, char e);
void criaStrUti();
DADOS * reserva_espaco();
void le5Alunos();
int main()
{
	criaStrDin('a','b','c','d','e');
	criaStrUti();
	DADOS *d = reserva_espaco();
	le5Alunos();
	return 0;
}

void le5Alunos()
{
	DADOS *a1 = reserva_espaco();
	a1->numero = 3;
	strcpy(a1->nome, "Pedro");
	printf("Numero : %d | Nome: %s\n", a1->numero, a1->nome);
}
DADOS * reserva_espaco()
{
	DADOS * ap;
	ap = (DADOS*) malloc(sizeof(DADOS));
	return ap;
}

void criaStrUti()
{
	printf("Qual o tamanho da string? ");
	int tam;
	scanf("%d", &tam);
	char *ap;
	ap = (char*) calloc(tam + 1, sizeof(char));
	printf("Introduza a string: ");
	scanf("%s", ap);
	ap[tam] = '\0';
	printf("String concluida: %s\n", ap);
}

void criaStrDin(char a, char b, char c, char d, char e)
{
	char *ap;
	ap = (char*) calloc(6, sizeof(char));
	ap[0]=a;ap[1]=b;ap[2]=c;ap[3]=d;ap[4]=e;ap[5]='\0';
	printf("String: %s\n", ap);
}
