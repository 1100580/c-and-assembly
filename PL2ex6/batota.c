#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int batota()
{
	int ranN;
	ranN = rand() % 5+1;
	exit(ranN);
}
