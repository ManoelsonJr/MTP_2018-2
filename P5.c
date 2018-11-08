/* P5.c */
/* Manoelson Moreira Rondon Junior */
/* 11811EBI004 */
#include <stdio.h>

typedef
	unsigned long long int
Bytes8;
typedef
	struct LCG { Bytes8 w, x, y, rand_max, atual;}
LCG;

void semente(LCG * r, Bytes8 seed) 
{
	r->w = 0x5DEECE66DULL;
	r->x = 11ULL;
	r->y = (1ULL << 48);
	r->rand_max = r->y - 1;
	r->atual = seed;
}
Bytes8 lcg_rand(LCG * r) 
{
	r->atual = (r->w * r->atual + r->x) % r->y;
	return r->atual;
}
double lcg_rand_01(LCG * r) 
{
	return ((double) lcg_rand(r))/(r->rand_max);
}
void gerador_num(float * vetor, int tam, float min, float max, LCG * r) 
{
	int i;
	for(i = 0; i < tam; i++)
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
}
float somatorio(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor + somatorio(inicio_vetor + 1, fim_vetor));
	return 0;
}

float produtorio(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor * produtorio(inicio_vetor + 1, fim_vetor));
	return 1;	
}

int main()
{
	LCG random;
   	semente(&random, 123456);
	int op;
		float numeros[50];
	gerador_num(numeros, 50, 0.5, 1.5, &random);
		do
			{
				printf ("Gerou-se 50 numeros aleatorios. Gostaria de fazer uma: \
				\n\n1) Soma dos numeros gerados? \n2) Produto dos numeros gerados? \n3) Sair do programa. \n\n");
				scanf ("%d", &op);
				switch (op)
				{
					case 1:
					printf ("\nA soma: %.6f \n\n", somatorio (&numeros[0], &numeros[49]));
					break;
					case 2:
					printf ("\nO produto: %g \n\n", produtorio (&numeros[0], &numeros[49]));
					break;	
				default:
					if (op != 3)
					printf ("\nOpcao invalida! \n\n");
				}	
			} while (op != 3);
	return 0;
}
