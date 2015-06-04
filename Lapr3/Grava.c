
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grava.h"
#include "Ler.h"

int main()
{
char *path;
FILE *fp;
path ="/media/sf_ARQCPVM/eclipse/Lapr3/Teste.csv";

dados *ap = ler(path);

path="/media/sf_ARQCPVM/eclipse/Lapr3/test.bin";

fp =fopen(path,"wB");
	int i;
	i=sizeof(dados);
	int x;
	x = 0;
	for(x = 0; x < sizeof(ap);x++){
		fwrite(ap+x,i,1,fp);
	}
	fclose(fp);

return 0;
} 
