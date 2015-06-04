int main()
{
	int vec[4] = {3,1,2,3};
	int * vec1 = vec;
	int res = soma_vitorias(vec1);
	printf("Vitorias totais: %d\n", res);
	return 0;
}
