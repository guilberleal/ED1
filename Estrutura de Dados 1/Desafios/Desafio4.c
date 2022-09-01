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

int verifica (tipo_arvore *arvore)
{
}

int altu (tipo_arvore *arvore)
{
  if ( arvore == NULL )
    return -1;
  else
  {
    int h_esq,h_dir;
    
    h_esq = altu (arvore->esquerda) +1;
    h_dir = altu (arvore->direita) +1;
    return abs (h_esq - h_dir);
  }
}


int main (int argc, char **argv)
{
  tipo_arvore *arvore = NULL;
  tipo_arvore *arvore2 = NULL;
  
  int x [] = {50,25,75,15,30,65,80,90,100};
  int y [] = {50,25,75};
  int i =0,w;
  
  while (i!=9)
  {
    insere_arvore (&arvore,x[i]);
    insere_arvore (&arvore2,y[i]);
    i++;
  }
  
  printf("ESPERA-SE QUE ESSA ARVORE NAO ESTEJA BALANCEADA:\n");
  w = altu(arvore);
  if (w <= 1)
    printf ("ARVORE BALANCEADA\n");
  else
    printf ("ARVORE DESBALANCEADA\n\n");
  
  printf("ESPERA-SE QUE ESSA ARVORE ESTEJA BALANCEADA:\n");
  w = altu(arvore2);
  if (w <= 1)
    printf ("ARVORE BALANCEADA\n");
  else
    printf ("ARVORE DESBALANCEADA\n");
  return 0;
}
