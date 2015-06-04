#include <stdio.h>
#include "asm.h"
void lista1AteN(int numMaxR);
int main(){

	int numMaxR = 3;
	lista1AteN(numMaxR);
	printf("End C.\n");
	print_n(numMaxR);
	return 0;
}

void lista1AteN(int numMaxR){
	if(numMaxR == 1){
		printf("%d . ",numMaxR);
	}else{
		int modded = numMaxR - 1;
		lista1AteN(modded);
		printf("%d . ", numMaxR);
	}
}
