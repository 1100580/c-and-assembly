/*
 * main.c
 *
 *  Created on: Oct 7, 2011
 *      Author: root
 */

#include <stdio.h>
#include "media.h"

 int main()
 {
 double v[2]={1,2};
 double r=0;
 r=media(v[0], v[1]);
 printf("media = %f\n", r);

 double f[3]={5,6,7};
 double n = 3;
 double res = media_vector(f, n);
 printf("media =%f\n", res);

 res = media_vector_g();
 printf("media =%f\n", res);
 return 0;
}
