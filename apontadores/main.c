/*
 * main.c
 *
 *  Created on: Oct 12, 2011
 *      Author: root
 */

#include <stdio.h>

void transVec(double *b, double *c);
//void ordenarVec(double *b);
void exer4();

int main()
{
	// int *a;
	//int b[5];
	//char *c;
	//int x = 5;
	//a = &x <--a aponta para x
	//*a = 22 <-- onde a esta a apontar fica com 22
	//c = str e valido porque sao ambos apontadores
	//*b=7 <-- a prmeira posicao de b e agora 7
	//*(b+2) = 7 <-- a posicao 2(terceira) e agora 7

	int x;
	double b[5];
	double c[5];
	double v1[5];
	int i;
	for(i = 0;i<5;i++)
	{
		printf("%f Insira o numero");
		scanf("%d",&x);
		*(b+i) = x;
	}
	transVec(b,c);
	//ordenarVec(b);
	exer4();
	return 0;
}

void transVec(double *b, double *c)
{
	int j;
	for(j = 0; j<5; j++)
	{
		*(c+j) = 1/(*(b+j));
	}

	for(j = 0; j<5; j++)
	{
		printf("%f\n", *(b+j));
	}
}

void exer4()
{
	float lido;
	int inteiro,decimal;
	int j;
	int *i[5];
	int *d[5];
	for(j = 0; j<5; j++)
	{
		scanf("%f", &lido);
		inteiro = (int)lido;
		decimal = (int)((lido - (float)inteiro)*100);
		i[j] = inteiro;
		d[j] = decimal;
	}

	for(j = 0; j<5; j++)
	{
		printf("%d", i[j]);
		printf("%d", d[j]);
		printf("%f\n");
	}
}

/*void ordenarVec(double *b)
{
	double *v[5];
	int j;
	for(j = 0; j < 5; j++)
	{
		v[j] = &(b[j]);
	}

	int m;
	int l;
	double *temp;
	for(m = 0; m < 5; m++)
	{
		for(l = 1; l < 4; l++)
		{
			if(*(v+m) > *(v+l))
			{
				temp = v[l];
				v[l] = v[m];
				v[m] = temp;
			}
		}
	}
}*/
