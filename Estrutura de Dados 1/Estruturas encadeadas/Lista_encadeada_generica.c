/**
 * LISTA ENCADEADA GENERICA
 * AUTOR: ALEX MATOS IUASSE
 * EXERCICIO DE ESTRUTURA DE DADOS 1
 * UNICO ALGORITMO COM APROVEITAMENTO DE CODIGO :3
 */

#include <stdio.h>
#include <stdlib.h>

struct estruturano
{
  void *valor;
  struct estruturano *prox;
};
typedef struct estruturano tipono;

//funçao alocar
tipono *alocano (void *valor)
{
  tipono *novono = NULL;
  novono = (tipono*) malloc (sizeof(tipono));
  novono->valor = valor;
  novono->prox = NULL;
  return (novono);
}

//funçao insere inicio
void insereinicio (tipono **lista, void *valor)
{
  tipono *novono = alocano(valor);
  
  if(*lista == NULL)
    *lista = novono;
  else
  {
    novono->prox = *lista;
    *lista = novono;
  }
}

//funçao insere fim
void inserefim (tipono **lista, void *valor)
{
  tipono *novono = alocano(valor);
  
  if(*lista == NULL)
    *lista = novono;
  else
  {
    tipono *aux = *lista;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = novono;
  }
}

//funcao que insere posicao
void inserepos (tipono **lista, void *valor, int pos)
{
  tipono *aux1, *aux2;
  tipono *novono = alocano(valor);
  aux1 = *lista;
  if(aux1 == NULL && pos == 0)
    aux1 = novono;
  else if (pos == 0)
    insereinicio(lista,valor);
  else
  {
    int i = 0;
    while (i != pos-1)
    {
      aux2 = aux1;
      aux1 = aux1->prox;
      i++;
      if(aux1->prox == NULL)
      {
	printf("POSICAO INVALIDA\n");
	exit(1);
      }
    }
    aux2->prox = novono;
    novono->prox = aux1;
  }
}

//função que remove inicio
void removeinicio (tipono **lista)
{
  if(*lista == NULL)
    printf("lista vazia");  
  else
  {
    tipono *aux = *lista;
    *lista = (*lista)->prox;
    free(aux);
  }
}

//funcao que remove posicao
int removepos ( tipono **lista, int pos ) 
{
  tipono *aux1, *aux2;
  aux2 = *lista;
  int i = 0;
  if (*lista == NULL)
  {
    printf ( "LISTA VAZIA\n");
    return 0;
  }
  else if (pos == 0) 
    removeinicio(lista);
  else 
  {
    while (i != pos-1) 
    {
      aux1 = aux2;
      aux2 = aux2->prox;
      i++;
      if(aux2 == NULL)
      {
	printf("POSICAO INVALIDA\n");
	return 0;
      }
    }
    aux1->prox = aux2->prox;
    free (aux2);
  }
}

//funcao remove fim
void removefim (tipono **lista)
{
  if(*lista == NULL)
    printf("lista vazia");
  else
  {
    tipono *aux = *lista;
    tipono *aux2;
    while (aux->prox != NULL)
    {
      aux2 = aux;
      aux = aux->prox;
    }
    aux2->prox = NULL;
    free(aux);
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
    int *i;
    while (lista != NULL)
    {
      i = (int*) lista->valor;
      printf("[%d]\t",*i);
      lista = lista->prox;
    }
  }
}

//funçao principal
int main (int argc, char *argv[])
{
  tipono *lst = NULL;
  int *i;
  
  printf("TESTE DE INSERCAO INICIO: \t");
  i = (int*) malloc (sizeof(int));
  *i = 1;
  insereinicio(&lst,i);
  i = (int*) malloc (sizeof(int));
  *i = 2;
  insereinicio(&lst,i);
  imprimir(lst);
  
  puts("");
  
  printf("TESTE DE INSERCAO FIM: \t\t");
  i = (int*) malloc (sizeof(int));
  *i = 3;
  inserefim(&lst,i);
  i = (int*) malloc (sizeof(int));
  *i = 4;
  inserefim(&lst,i);
  imprimir(lst);
  
  puts("");
  
  printf("TESTE DE INSERCAO POSICAO 2: \t");
  i = (char*) malloc (sizeof(char));
  *i = 'a';
  inserepos(&lst,i,2);
  imprimir(lst);
  
  puts("");
  
  printf("TESTE DE REMOCAO POSICAO 3: \t");
  removepos(&lst,3);
  imprimir(lst);
  
  puts("");
  
  printf("TESTE DE REMOCAO POSICAO 6: \t");
  removepos(&lst,6);
  
  printf("TESTE DE REMOCAO INICIO: \t");
  removeinicio(&lst);
  imprimir(lst);
  
  puts("");
  
  printf("TESTE DE REMOCAO FIM: \t\t");
  removefim(&lst);
  imprimir(lst);
  
  puts("");
  return 0;
}