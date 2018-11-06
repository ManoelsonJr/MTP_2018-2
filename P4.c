/* P4.c */
/* MANOELSON MOREIRA RONDON JUNIOR */
/* 11811EBI004 */
#include <stdio.h>

double func(float m, float n)
{
	if(m==0)
		return n+1;
	else if(m>0 && n==0)
		return func(m-1,1);
	else if (m>0 && n>0)
		return func(m-1, func(m, n-1));
}

int main()
{
	float m, n;
	scanf("%f %f", &m, &n);
	printf("%.2f + %.2f = %.2lf", m, n, func(m,n));
	return 0;
}




