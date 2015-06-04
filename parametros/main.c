int main()
{
	int base = 4;
	int rquad = quadrado(base);
	printf("Quadrado de %d = %d\n", base, rquad);

	int n = 3;
	int rsomat = somatorio_n(n);
	printf("Somatorio ate %d = %d\n", n, rsomat);

	int menora = 15;
	int menorb = 98;
	int menorc = 145;
	int rmenor = menor(menora, menorb, menorc);
	printf("Menor numero: %d\n", rmenor);

	int num1 = 2;
	int num2 = 3;
	int posmaior = 0;
	int * maior = & posmaior;
	int rdsem = devolve_soma_e_maior(num1, num2, maior);
	printf("Resultado da soma: %d, maior numero dos dois: %d\n", rdsem, posmaior);

	int n1 = 4;
	int n2 = 5;
	int *p1 = &n1;
	int *p2 = &n2;
	/*troca(p1,p2);*/

	char ig1[] = "trinta";
	char ig2[] = "trinta";
	char * pig1 = ig1;
	char * pig2 = ig2;
	int igual = 1;
	igual = testaiguais(pig1, pig2);
	printf("Igual? : %d\n", igual);

	return 0;
}
