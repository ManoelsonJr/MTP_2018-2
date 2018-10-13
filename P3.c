/* P3.c */
/* MANOELSON MOREIRA RONDON JUNIOR */
/* 11811EBI004 */
#include<stdio.h>

int main()
{
	char rec[256];
	int i, num=0, num2, result;
	printf("Digite os caracteres: ");
	scanf("%s", rec);
	for(i=0; rec[i]!= '\0'; i++)
	{
		if(rec[i]>=48 && rec[i]<=57)
		{
		 	num2 = rec[i] - 48;
			result = num2 + num; 
			num = result*10;
		}
	}
	printf("%d", result);
	return 0;
}
