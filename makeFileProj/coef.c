/*
 * coef.c
 *
 *  Created on: Oct 7, 2011
 *      Author: root
 */

void coef(int n,int k)
{

	if(n = 0)
	{
		return 0;
	}else if(k = 0)
	{
		return 1;
	}else
	{
		return (coef(n-1, k-1) - coef(n-1, k));
	}
}
