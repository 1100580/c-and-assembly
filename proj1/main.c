/*
 * main.c
 *
 *  Created on: Oct 21, 2010
 *      Author: alex
 */
#include <stdio.h>

#include "add.h"

int main()
{
	int n1=5;
	int n2=10;
	int r=0;

	r=add(10, 12);
	printf("Adicao em assembly de 10+12=%d\n", r);

	r=0;
	r=add2(&n1, &n2);
	printf("Adicao em assembly de 5+10=%d\n", r);

	r=0;
	add3(&n1, &n2, &r);
	printf("Adicao em assembly de 5+10=%d\n", r);

	return 0;
}

