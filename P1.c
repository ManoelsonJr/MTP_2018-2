/* P1.c */
/* MANOELSON MOREIRA RONDON JUNIOR */
/* 11811EBI004 */
#include<stdio.h>
int main()
{
	int estado=0, i=0, numero;
	char bits[256];
	printf("Digite o numero a ser verificado: ");
	scanf("%s", bits);
	while(bits[i] != '\0')
	{
		if(estado== 0 && bits[i] == '0')
		estado = 0;
		else if(estado ==0 && bits[i] == '1')
		estado = 1;
		else if(estado == 1 && bits[i] == '1')
		estado = 0;
		else if(estado == 1 && bits[i] =='0')
		estado = 2;
		else if(estado == 2 && bits[i] == '0')
		estado = 1;
		else if(estado == 2 && bits[i] == '1')
		estado = 2;
		i++;
	}
	printf("A sequencia original %s \n ", bits);
	if(estado==0)
	printf("Eh multiplo de 3.");
	else
	printf("Nao eh multiplo de 3.");
	return 0;
}
