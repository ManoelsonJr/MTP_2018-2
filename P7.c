/* P7.c */
/* Manoelson Moreira Rondon Junior */
/* 11811EBI004 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct 
{
	double x , y ;	
}ponto;
ponto * cria_pontos(int N)
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
		printf("(%.3lf , %.3lf)", p_ini->x , p_ini->y);
		mostrapontos (p_ini+1, p_fim);
	}
}
void salva_como_NetPPM(ponto *pini, int larg_px, int alt_px)
{
	FILE * arquivo;
	int i, j;
	arquivo = fopen("pontos.dat", "W");
	fprintf(arquivo, "P3\n%d %d\n255\n# Pontos:\n", larg_px, alt_px);
	for(i=0; i<alt_px; i++)
		{
			for(j=0; j<larg_px; j++)
			{
				fprintf(arquivo, "%d\t%d\t\t", pini[i].x, pini[i].y);
			}
			fprintf(arquivo, "\n");
		}
		fclose(arquivo);
}
void grava_bin(ponto * pini, int N)
 {
    FILE * arquivo;
    arquivo = fopen("pontos.dat", "wb");
    fwrite(pini, N, sizeof(ponto), arquivo);
    fclose(arquivo);
}
ponto * leitor_bin(char * nome_arquivo, unsigned int * pN)
{
    ponto * p = (ponto *) malloc(sizeof(ponto));    
    unsigned int N = 0;    
    FILE * arquivo;
    arquivo = fopen(nome_arquivo, "rb");    
    while(1) 
	{
        fread(p, 1, sizeof(ponto), arquivo);        
        	if(feof(arquivo)) break;
        N++;
    }
    rewind(arquivo);    
    p = (ponto *) realloc(p, N*sizeof(ponto));
    fread(p, N, sizeof(ponto), arquivo);    
    fclose(arquivo);    
    *pN = N;    
    return p;
}
int main()
{
	int N, esc;
	ponto *p;
	char fn[] = "pontos.dat";	
	printf("\n1 -Criar Arquivo com pontos ; 2 - Mostrar os pontos do arquivo : ");
	scanf("%u", &esc); getchar();	
	
	if(esc==2)
	{
		p = leitor_bin(fn, &N);
		mostrapontos(p, p+N);
	}
	else if(esc==1)
	{
		printf("Insira a quantidade de pontos : ");
		scanf("%d", &N); getchar();
		p = cria_pontos(N);
		salva_como_NetPPM(p, 20, N);
		grava_bin(p, N);
		printf("\n\t\t\tArquivo gravado");
	}
	free(p);
	return 0;
	}
