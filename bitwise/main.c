int main ()
{
	int aRodar = 4;
	int nBits = 1;
	int res = rodarDir(aRodar, nBits);
	printf("Numero rodado: %d\n", res);

	int data1 = 12032011;
	int data2 = 12052011;
	int resD = menor_data(data1, data2);
	printf("Menor data: %d\n", resD);

	int vec[4] = {1,2,3,4};
	int * vec1 = vec;
	subtrai(vec1, 4);
	return 0;
}

void subtrai(int *vec, int tam)
{

}
int menor_data(int data1, int data2)
{
	int ano1 = data1 & 0x0000FFFF;
	printf("%d\n", ano1);
	int ano2 = data2 & 0x0000FFFF;
	printf("%d\n", ano2);
	int dia1 = rodarDir(data1, 16);
	dia1 = dia1 & 0x000000FF;

	int dia2 = rodarDir(data2, 16);
	dia2 = dia2 & 0x000000FF;

	int mes1 = rodarDir(data1, 8);
	mes1 = mes1 & 0x000000FF;

	int mes2 = rodarDir(data2, 8);
	mes2 = mes2 & 0x000000FF;

	if(ano1 != ano2){
		if(ano1>ano2){ return data2; } else { return data1; }
	}else if(mes1 != mes2){
		if(mes1>mes2){ return data2; } else { return data1; }
	}else if(dia1 != dia2){
		if(dia1>dia2){ return data2; } else { return data1; }
	}else{
		return 0;
	}
}

int rodarDir(int aRodar, int nBits)
{
	int aux = (aRodar >> nBits) | (aRodar <<(32-nBits))&1;
	return aux;
}
int rodarEsq(int aRodar, int nBits)
{
	int aux = (aRodar << nBits) | (aRodar >>(32-nBits))&1;
	return aux;
}
