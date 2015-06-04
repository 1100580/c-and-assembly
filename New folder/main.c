/*
 * TESTE E, 2
 *
 * NAO PODE ALTERAR ESTE FICHEIRO
 *
 */

#include <stdio.h>


/*
	Esta funcao recebe o codigo da accao, o vector com a informacao de todas as accoes
	e devolve o valor total da accaoo em euros. Para obter esse valor deve-se multiplicar
	o numero de accoes pelo seu valor em centimos e depois converter para euros.
	O valor retornado deve ser apenas a parte inteira do valor em euros.
*/
int valor_accao (int accao, int *accoes);

/*
 Esta funcao deve calcular o valor total das accoes (em euros) cujo valor individual
 e' maior que valor_ref. Esta funcao deve usar a anterior.
*/
int calcula_total_maiores(int valor_ref, int* accoes);

int accoes[6];

int main(void) {
	int total=0;
	int i=288;

	/* Inicializar o array */
	/*
		Os bits de cada elemento (excluindo o primeiro) tem o seguinte significado:
		0-15 - o valor da accao em centimos
		16-23 - codigo da accaoo
		24-31 - numero de accoes
	*/
	accoes[0]=5;
	accoes[1]=0x10010100;
	accoes[2]=0x20020110;
	accoes[3]=0x30030120;
	accoes[4]=0x40040130;
	accoes[5]=0x50050140;

	total=calcula_total_maiores(i, accoes);

	printf("Valor total das accoes com valor individual maior que %i = %u\n", i, total);
	if (total!=450) printf("Programa ERRADO. O valor deveria ser = 450 !");

	return 0;
}
