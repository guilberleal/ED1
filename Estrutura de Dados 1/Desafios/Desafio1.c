/**
 * DESAFIOS DE IVAIRTON, ESTRUTURA DE DADOS 1
 * AUTOR: ALEX MATOS IUASSE
 */

#include <stdio.h>
#include <stdlib.h>

struct no_arvore
{
  int entrada;
  struct no_arvore *esquerda;
  struct no_arvore *direita;
};
typedef struct no_arvore tipo_arvore;

struct estruturano
{
  int valor;
  struct estruturano *prox;
};
typedef struct estruturano tipono;

tipo_arvore *aloca_no (int entrada)
{
  tipo_arvore *novo_no = NULL;
  novo_no = (tipo_arvore*) malloc (sizeof(tipo_arvore));
  novo_no->entrada = entrada;
  novo_no->esquerda = NULL;
  novo_no->direita = NULL;
  return novo_no;
}

tipono *alocano (int valor)
{
  tipono *novono = NULL;
  novono = (tipono*) malloc (sizeof(tipono));
  novono->valor = valor;
  novono->prox = NULL;
  return (novono);
}

void inserefim (tipono **lista, int valor)
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
    inserefim (lista,arvore->entrada);
    if ( arvore->entrada == entrada)
      printf("VALOR ENCONTRADO\n");
    else
    {
      if (entrada < arvore->entrada )
	busca ( arvore->esquerda,entrada,lista);
      else
	busca ( arvore->direita,entrada,lista);
    }
  }
  else
    printf("ELEMENTO NAO ENCONTRADO\n");
}

void imprimir (tipono *lista)
{
  if (lista == NULL)
    printf("lista vazia");
  else
  {
    while (lista != NULL)
    {
      printf("[%d]\t",lista->valor);
      lista = lista->prox;
    }
  }
}

int main (int argc, char **argv)
{
  tipo_arvore *arvore = NULL;
  tipono *lista = NULL;
  
  int x [] = {50,25,75,15,30,65,80,90,100};
  int i =0 , cont = 0;
  
  while (i!=9)
  {
    insere_arvore (&arvore,x[i]);
    i++;
  }
  
  printf("REALIZAR BUSCA DO ELEMENTO 200: \n");
  busca (arvore,200,&lista);
  printf("CAMINHO PERCORRIDO: \t");
  imprimir (lista);
  
  printf("\n\nREALIZAR BUSCA DO ELEMENTO 100: \n");
  busca (arvore,100,&lista);
  printf("CAMINHO PERCORRIDO: \t");
  imprimir (lista);
  puts("");
  
  return 0;
}
