/**
 * ALGORITMO DE ARVORE BINARIA
 * AUTOR: ALEX MATOS IUASSE
 * 
 * ao executar uma busca por um valor em uma arvore binaria, registre o
"caminho" percorrido (registre os valores dos nós visitados). dica, utilize uma
lista para registrar o "caminho".
 *considerando uma arvore binaria que armazena inteiros, encontre o caminho, da
raiz ate um nó folha, que seja maximo, ou seja, o caminho que a somatoria dos
valores visitados seja o maximo possivel.
 *verifique se 2 arvores binarias distintas sao iguais. se diz "iguais" aquelas
arvores com exatamente o mesmo conjunto de valores.
 * verifique se uma arvore binaria esta em equilibrio
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
//#include "Lista_encadeada.c"

struct no_arvore 
{
	int entrada;
	struct no_arvore *esquerda;
	struct no_arvore *direita;
};
typedef struct no_arvore tipo_arvore;

tipo_arvore *aloca_no (int entrada)
{
	tipo_arvore *novo_no = NULL;
	novo_no = (tipo_arvore*) malloc (sizeof(tipo_arvore));
	novo_no->entrada = entrada;
	novo_no->esquerda = NULL;
	novo_no->direita = NULL;
	return novo_no;
}

int insere_arvore (tipo_arvore **arvore, int entrada)
{
	if (*arvore == NULL)
	{
		tipo_arvore *novo_no = aloca_no(entrada);
		*arvore = novo_no;	
	}
	else
	{
		if ( entrada < (*arvore)->entrada )
			insere_arvore (&((*arvore)->esquerda),entrada);
		else
			insere_arvore (&((*arvore)->direita), entrada);
	}
}

void busca (tipo_arvore *arvore, int entrada, tipono **lista)
{
	if ( arvore != NULL )
	{
		printf ("VALOR DO NÓ %i\t", arvore->entrada);
		inserefim (lista,arvore->entrada);
		if ( arvore->entrada == entrada)
			printf("\nVALOR ENCONTRADO\n");
		else 
		{
			if (entrada < arvore->entrada )
				busca ( arvore->esquerda,entrada,lista);
			else 
				busca ( arvore->direita,entrada,lista);
		}
	}
	else
		printf("\nVALOR NAO ENCONTRADO\n");
}

void compara (tipo_arvore *arvore, tipo_arvore *arvore2, int cont)
{
	if (arvore != NULL && arvore2 != NULL)
	{
		printf("%i",cont);
		if (arvore->entrada == arvore2->entrada)
		{
			cont ++;
			compara(arvore,arvore2->esquerda,cont);
			compara(arvore,arvore2->direita,cont);
		}
		else
		{
			if(arvore->entrada < arvore2->entrada)
				compara (arvore->esquerda,arvore2,cont);
			else
				compara(arvore->direita,arvore2,cont);
		}
	}
}

void pre_ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		printf("\t%i",arvore->entrada);
		pre_ordem (arvore->esquerda);
		pre_ordem (arvore->direita);
	}
}
void pos_ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		pos_ordem (arvore->esquerda);
		pos_ordem (arvore->direita);
		printf("\t%i",arvore->entrada);
	}
}
void ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		ordem (arvore->esquerda);
		printf("\t%i",arvore->entrada);
		ordem (arvore->direita);
	}
}



int main (int argc, char **argv)
{
	tipo_arvore *arvore = NULL;
	tipo_arvore *arvore2 = NULL;
	tipono *lista = NULL;
	
	int y [] = {100,90,80,65,30,15,75,25,50};
	int x [] = {50,25,75,15,30,65,80,90,100};
	int i =0 , cont = 0;
	
	while (i!=9)
	{
		insere_arvore (&arvore,x[i]);
		insere_arvore (&arvore2,y[i]);
		i++;
	}
	
	compara (arvore,arvore2,cont);
	//busca (arvore,200,&lista);
	//imprimir (lista);
	puts("");
	
	return 0;
}
