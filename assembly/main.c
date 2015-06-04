/*
 * main.c
 *
 *  Created on: Oct 5, 2011
 *      Author: root
 */

#include <stdio.h>
#include "asm.h"

int g_int_1 = 1;
int g_int_2 = 5;
int g_int_resultado = 0;

int ex2_1 = 5;
int ex2_2 = 4;
int ex2_3 = 6;

int ex3_1 = 3;
int ex3_2 = 2;

int ex5_1 = -3;
int ex5_2 = 2;

int n1 = 5;
int n2 = 4;
int n3 = 3;
int n4 = 0;

int sinal = 0;
int g_dividendo = 4;
int g_divisor = 2;
float g_quociente;

char c;
char *p = &c;

int main()
{
	/*funcao();*/
	/*funcao2();*/
	/*funcao3();*/
	/*int resultado = funcao4();*/
	/*int resultado = funcao5();*/
	/*funcao6();*/
	/*int resultado = funcao7();*/
	/*int resultado = funcao8();*/
	/*funcao9();*/
	/*printf("g_int_resultado=%d\n", g_int_resultado);*/
	/*float resultado = funcao10();*/
	/*printf("resultado=%f\n", resultado);*/
	/*g_quociente = funcao11();*/
	/*printf("g_int_resultado=%f\n", g_quociente);*/
	inicializaChar();
	printf("%c\n",*p);
	return 0;
}
