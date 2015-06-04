#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int d;
	FILE* f;
	f = popen("sort fich.txt", "r");

	char buffer[50];
	while ((d = fread(buffer, sizeof(char), 80, f))) {
		buffer[d] = '\0';
		printf("%s", buffer);
	}

	pclose(f);

	return 0;
}
