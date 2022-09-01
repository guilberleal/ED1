/**
 * LISTA ENCADEADA
 * AUTOR: ALEX MATOS IUASSE
 */

#include <stdio.h>
#include <stdlib.h>

struct estruturano
{
	int valor;
	struct estruturano *prox;
};
typedef struct estruturano tipono;
//funçao alocar
tipono *alocano (int valor)
{
	tipono *novono = NULL;
	novono = (tipono*) malloc (sizeof(tipono));
	novono->valor = valor;
	novono->prox = NULL;
	return (novono);
}
//funçao insere inicio
void insereinicio (tipono **lista, int valor)
{
	tipono *novono = alocano(valor);
	
	if(*lista == NULL)
	{
	     *lista = novono;
	}
	else
	{
	      novono->prox = *lista;
	      *lista = novono;
	}
}
//função imprimir
void imprimir (tipono *lista)
{
	if (lista == NULL)
	{
	      printf("lista vazia");
	}
	else
	{
	      while (lista != NULL)
	      {
		    printf("\n%d,",lista->valor);
		    lista = lista->prox;
	      }
	}
}
//funçao insere inicio 2
tipono *insereinicio2 (tipono *lista, int valor)
{
	tipono *novono = alocano(valor);
	
	if(lista == NULL)
	{
	     lista = novono;
	}
	else
	{
	      novono->prox = lista;
	      lista = novono;
	}
	return (lista);
}
//funçao insere fim
void inserefim (tipono **lista, int valor)
{
	tipono *novono = alocano(valor);
	
	if(*lista == NULL)
	{
	     *lista = novono;
	}
	else
	{
	      tipono *aux = *lista;
	      while (aux->prox != NULL)
		    aux = aux->prox;
	      aux->prox = novono;
	}
}
//função que remove inicio
void removeinicio (tipono **lista)
{
	if(*lista == NULL)
	{
	      printf("lista vazia");
	}
	else
	{
	      tipono *aux = *lista;
	      *lista = (*lista)->prox;
	      free(aux);
	}
}
//função que remove inicio 2
tipono *removeiniciob (tipono *lista)
{
	if(lista == NULL)
	{
	      printf("lista vazia");
	}
	else
	{
	      tipono *aux = lista;
	      lista = lista->prox;
	      free(aux);
	}
	return lista;
}
//função que insere em uma posição
void insere_pos (tipono **lista, int valor, int pos)
{
	if (pos == 0)
	{
		insereinicio (&lista,valor);
	}
	else
	      if (*lista != NULL)
	      {
		     tipono *aux, *aux_atras;
		     int contador = 0;
		     aux = *lista;
		     while( (aux != NULL) && (contador < pos-1) )
		     {
			  aux_atras = aux;
			  aux = aux->prox;
			  contador ++;
		     }
		     if (contador == pos-1)
		     {
			  tipono *novono = alocano(valor);
			  novono->prox = aux->prox;
			  aux->prox = novono;
		     }
		     else
		     {
			  printf("Erro: posicao invalida\n");
		     }
	      }
	      else
	      {
		      printf("Erro: lista vazia, posicao invalida\n");
	      }
}
//funçao principal
int main (int argc, char *argv[])
{
	tipono *lst = NULL;
	
	return 0;
}		