#include <stdio.h>

int String2Inteiro(char[]);
int calculaMedia();
void encheVecInt(int[]);
int lePalavrasFrase(char[]);
void ordCres();
int vec[10];

int main()
{
	printf("%u\n", sizeof(int));
	printf("%u\n", sizeof(float));
	printf("%u\n", sizeof(char));
	printf("%u\n", sizeof(double));
	
	char s[10] = "21";
	
	int num = String2Inteiro(s);
	
	printf("%u\n", num);
	
	int media = calculaMedia();
	
	printf("%u\n", media);


	encheVecInt(vec);

	char f[100] = "Palavra palavra palavra.";

	int palavras = lePalavrasFrase(f);

	printf("%s\n", "N de palavras");
	printf("%d", palavras);

	ordCres();

	return 0;
}

void ordCres()
{
	encheVecInt(vec);
	int nVec[100];
	int numM = 0;
	int i;
	int k;
	int tamVec = 5;
	for(k = 0; k < 3; k++)
	{
		for(i = 0; i < tamVec; i++)
		{
			if(vec[k] >= vec[i]){
				int aux = vec[k];
				vec[k] = vec[i];
				vec[i] = aux;
			}
		}
		printf("%d", nVec[k]);
	}
}

int lePalavrasFrase(char f[])
{
	int palavras = 1;
	int indice = 0;
	while(f[indice++] != '\0')
	{
		if(f[indice] == ' ')
		{
			palavras++;
		}
	}
	return palavras;
}

void encheVecInt(int vec[])
{
	int i = 0;
	int j;
	int numLido = 9;
	while(numLido != 0)
	{
		printf("Insira um numero\n");
		scanf("%d", &numLido);
		vec[i++] = numLido;
	}

	for(j = 0; j< i-1;j++)
	{
		printf("%d", vec[j]);
		printf("\n");
	}

}

int calculaMedia()
{
	int num1;
	int num2;
	int numFinal;
	char lido1[10];
	char lido2[10];
	printf("Insira o primeiro numero\n");
	scanf("%s", lido1);
	printf("Insira o segundo\n");
	scanf("%s", lido2);
	printf("Media:\n");
	num1 = String2Inteiro(lido1);
	num2 = String2Inteiro(lido2);
	numFinal = (num1+num2)/2;
	return numFinal;
}
	
int String2Inteiro(char s[])
{
		int num = 0;
		int numeros = 0;
		int power = 1;
		while(s[numeros] != '\0')
		{
			numeros++;
			power = power*10;
		}
		int j;
		for(j = 0; j<numeros; j++)
		{
			num = num + (s[j] - 48)*power/10;
			power = power/10;
		}
		return num;
}
