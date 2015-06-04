/*
 * media.c
 *
 *  Created on: Oct 7, 2011
 *      Author: root
 */

double media(double n1, double n2)
{
	return (n1+n2)/2;
}

int g_n = 3;
double g_v[100]={1,2,3};

double media_vector_g()
{
	float media = 0;
	int i;
	for(i = 0; i< g_n;i++)
	{
		media = media + g_v[i];
	}
	return media/g_n;
}

double media_vector(double v[], int n)
{
	float media = 0;
	int i;
	for(i = 0; i< n;i++)
	{
		media = media + v[i];
	}
	return media/n;
}
