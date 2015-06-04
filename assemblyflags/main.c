#include <stdio.h>
#include "asm.h"
#define num 6

int max = num;
int cont = 0;
int vec[num] = {14,1,2,3,4,5};

int * ptrvec = vec;

int main()
{
	int res = ex5();
	printf("%d\n", res);
	return 0;
}
