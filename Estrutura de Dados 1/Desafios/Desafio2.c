/**
 * DESAFIOS DE IVAIRTON, ESTRUTURA DE DADOS 1
 * AUTOR: ALEX MATOS IUASSE
 * OBS: PROFESSOR ESSE ALGORITMO ESTA COM ALGUM BUG !! MAS ENVIAREI MESMO ASSIM
 */

#include <stdio.h>
#include <stdlib.h>

struct no_arvore
{
  int entrada;
  int chave;
  struct no_arvore *esquerda;
  struct no_arvore *direita;
};
typedef struct no_arvore tipo_arvore;

tipo_arvore *aloca_no (int entrada,int chave)
{
  tipo_arvore *novo_no = NULL;
  novo_no = (tipo_arvore*) malloc (sizeof(tipo_arvore));
  novo_no->entrada = entrada;
  novo_no->chave = chave;
  novo_no->esquerda = NULL;
  novo_no->direita = NULL;
  return novo_no;
}

int insere_arvore (tipo_arvore **arvore, int entrada, int chave)
{
  if (*arvore == NULL)
  {
    tipo_arvore *novo_no = aloca_no(entrada,chave);
    *arvore = novo_no;
  }
  else
  {
    if ( entrada < (*arvore)->chave )
      insere_arvore(&((*arvore)->esquerda),entrada,chave);
    else
      insere_arvore (&((*arvore)->direita),entrada,chave);
  }
}

//funcao de impressao em ordem da arvore
void ordem (tipo_arvore *arvore)
{
  if (arvore != NULL)
  {
    ordem (arvore->esquerda);
    printf("%i\t",arvore->entrada);
    ordem (arvore->direita);
  }
}

//funçao de achar o valor maximo
int soma (tipo_arvore *arvore)
{
  if (arvore != NULL)
  {
    int esq=0,dir=0;
    esq =  soma (arvore->esquerda);
    dir =  soma (arvore->direita);
    if ( esq > dir )
      return ( esq + arvore->entrada );
    else
      return (dir + arvore->entrada );
  }
  return 0;
}

int main (int argc, char **argv)
{
  tipo_arvore *arvore = NULL;
  
  int x [] = {50,25,75,15,70,5};
  int chave [] = {10,1,2,11,12,3};
  int i =0 ;
  int som=0;
  
  while (i!=6)
  {
    insere_arvore (&arvore,x[i],chave[i]);
    i++;
  }
  ordem (arvore);
  som = soma (arvore);
  printf("\nSoma do maior caminho: [ %i ]\n", som);
  
  return 0;
}
