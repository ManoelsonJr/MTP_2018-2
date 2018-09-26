/* P2.c */
/* Manoelson Moreira Rondon Junior */
/* 11811EBI004 */
#include <stdio.h>

void trocar (char vetor[])
{
	int x, j, band = 0, aux;
	for(x = 0; vetor[x] != '\0'; x++, band++);
	j = band - 1;
	for(x = 0; x < j; x++, j--){
		aux = vetor[x];
		vetor[x] = vetor[j];
		vetor[j] = aux;
	}
	vetor[band] = '\0';
}
int potencia (int resultado, int resultado2)
{
	int x, pot=1;
	for (x=0; x<resultado2; x++)
		pot *= resultado;
	return pot;
}
int binariodec (char vetor[])
{
	int x, soma = 0;
	trocar(vetor);
	for (x=0; vetor[x] != '\0'; x++)
	{
		if (vetor[x]=='1')
			soma = soma + vetor[x] * potencia(2,x);
	}
	return soma/49;
}
int decimalbin (int resultado)
{
	int x, band = 0, vetor[256], j;
	j = resultado;
	for(x = 0; band < 1; x++)
	{
		vetor[x] = j % 2;
		j=j/2;
		if(j == 0 || j == 1)
		{
			vetor[x + 1] = j;
			j = x + 1;
			band++;
		}
	}
	printf("\n Em binario ele e: ");
	for(j; j >= 0; j--){
		printf("%d", vetor[j]);
	}
}
int main()
{
	char vetorauxiliar[256];
	int escolha, resultado;
		printf ("ESCOLHA A OPCAO PARA CONVERSAO:\n\n");
		printf ("1 - BINARIO PARA DECIMAL\n2 - BINARIO PARA HEXADECIMAL\n3 - HEXADECIMAL PARA DECIMAL\n4 - HEXADECIMAL PARA BINARIO\n5 - DECIMAL PARA BINARIO \n6 - DECIMAL PARA HEXADECIMAL \n7 - OCTAL PARA DECIMAL \n8 - DECIMAL PARA OCTAL\n\n");
		scanf ("%d", &escolha);
		switch (escolha)
		{
			case 1:
				printf ("\nDigite o numero binario: ");
				scanf ("%s", &vetorauxiliar[0]);
				printf("\nEm decimal: %d", binariodec(vetorauxiliar));
				break;
			case 2:
				printf ("\nDigite o numero em binario: ");
				scanf ("%s", &vetorauxiliar[0]);
				printf ("\nEm hexadecimal: %x", binariodec(vetorauxiliar));
				break;
			case 3:
				printf ("\nDigite o numero em hexadecimal: ");
				scanf ("%x", &resultado);
				printf ("\n Em decimal: %d.", resultado);
				break;
			case 4: 
				printf ("\nDigite o numero em hexadecimal: ");
				scanf ("%x", &resultado);
				decimalbin(resultado);
				break;
			case 5:
				printf ("\nDigite o numero em decimal: ");
				scanf ("%d", &resultado);
				decimalbin(resultado);
				break;				
			case 6:
				printf ("\nDigite o numero em decimal: ");
				scanf ("%d", &resultado);
				printf ("\n Em hexadecimal ele eh %x", resultado);
				break;				
			case 7:
				printf ("\nDigite o numero em octal: ");
				scanf ("%o", &resultado);
				printf ("\n Em decimal: %d", resultado);
				break;				
			case 8:
				printf ("\nDigite o numero em decimal: ");
				scanf ("%d", &resultado);
				printf ("\n Em octal: %o", resultado);
				break;
			default:
				printf ("\nEssa opcao nao e valida.");
		}
	return 0;
}
