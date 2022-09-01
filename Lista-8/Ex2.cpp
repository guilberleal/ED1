
#include <stdio.h>
#include <stdlib.h>

//DEFINICAO DE UMA CONSTANTE PARA DETERMINAR O TAMANHO DO VETOR
#define n 10

//ESTRUTURA DA ARVORE
struct arvore_mult
{
	int entrada [n];
	int cont;
	struct arvore_mult *filho [n+1];
};
typedef struct arvore_mult tipo_arvore;

//ALOCACAO DE NOVO NO DE ARVORE
tipo_arvore *aloca_no (int entrada)
{
	tipo_arvore *novo_no = NULL;
	novo_no = (tipo_arvore*) malloc (sizeof(tipo_arvore));
	int i;
        
	novo_no->entrada [0] = entrada;
        
	for ( i = 0; i < n+1; i++)
		novo_no->filho[i] = NULL;
        
	novo_no->cont = 1;

	return novo_no;
}

//INSERCAO ORDENADA DE UM ELEMENTO NO VETOR DA ARVORE
void insere_ordenado ( tipo_arvore **aux, int entrada )
{
	int i, y;

	for ( i = 0; i < (*aux)->cont ; i ++ )
		if ( entrada < (*aux)->entrada [i] )
			break;
	if ( i < (*aux)->cont )
		for ( y = (*aux)->cont; y > i; y -- )
			(*aux)->entrada [y] = (*aux)->entrada [y-1];

        (*aux)->entrada [i] = entrada;
        (*aux)->cont ++;
}

//INSERCAO DE UM ELEMENTO NA ARVORE
void insere_arvore_multi (tipo_arvore **arvore, int entrada)
{
	if (*arvore == NULL)
		*arvore = aloca_no(entrada);
	else
	{
		if ( (*arvore)->cont < n)
			insere_ordenado (arvore,entrada);
		else
		{
			int i;
			for ( i = 0; i < n; i++ )
				if ( entrada < (*arvore)->entrada [i] )
					break;
			insere_arvore_multi ( & ( (*arvore)->filho [i] ), entrada);
		}
	}
}

//IMPRESSAO EM PREORDEM DA ARVORE
void preordem (tipo_arvore *arvore)
{
	if ( arvore != NULL )
	{
		int i;
		for ( i = 0; i < (arvore)->cont ; i++)
			printf ("[ %i ]\t", arvore->entrada[i]);
		for ( i = 0; i < (arvore)->cont+1 ; i++)
			preordem (arvore->filho[i]);
	}
}

//IMPRESSAO EM POSORDEM DA ARVORE
void posordem (tipo_arvore *arvore)
{
        if ( arvore != NULL )
        {
                int i;
                for ( i = 0; i < (arvore)->cont+1 ; i++)
                        preordem (arvore->filho[i]);
                for ( i = 0; i < (arvore)->cont; i++)
                        printf ("[ %i ]\t", arvore->entrada[i]);
        }
}

//FUNCAO PRINCIPAL
int main (int argc, char **argv)
{
        //DEFINICAO DA ARVORE
	tipo_arvore *arvore = NULL;
        //VETOR DE TESTES
	int teste [9] = {100,20,120,200,50};
	int i;
        
        //INSERCAO DE UM ELEMENTO NA ARVORE
	for ( i = 0; i < 5; i ++ )
		insere_arvore_multi (&arvore, teste[i]);
        
	ordem (arvore);
        puts("");

	return 0;
}
