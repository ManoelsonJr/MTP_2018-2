/* P6.c */
/* Manoelson Moreira Rondon Junior */
/* 11811EBI004 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct 
{
	double x , y ;	
}ponto;
ponto * gera_pontos(int N)
{
	ponto *p = (ponto *) malloc(N*sizeof(ponto));
	int i;
	for(i=0; i<N; i++)
	{
		p[i].x = cos(i*2.0*M_PI/(N-1));
		p[i].y = sin(i*2.0*M_PI/(N-1));
	}
	return p;
}
void mostrapontos (ponto *p_ini, ponto *p_fim)
{
	if(p_ini < p_fim)
	{
		printf("(%.3lf, %.3lf)", p_ini->x , p_ini->y);
		mostrapontos (p_ini+1, p_fim);
	}
}
int main()
{
	int N;
	ponto *p;
	printf("Digite a quantidade de pontos : ");
	scanf("%d", &N); 
	getchar();
	p = gera_pontos(N);
	mostrapontos(p, p+N);
	free(p);
	return 0;	
}
