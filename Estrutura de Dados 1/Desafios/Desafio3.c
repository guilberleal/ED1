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

int comp (tipo_arvore *arvore, tipo_arvore *arvore2)
{
  int cont, aux1,aux2;
  aux1 = aux2 = 1;
  if (arvore2 != NULL)
  {
    cont = compara (arvore,arvore2->entrada);
    if(arvore2->esquerda != NULL)
      aux1 = comp (arvore,arvore2->esquerda);
    if (arvore2->direita != NULL)
      aux2 = comp (arvore,arvore2->direita);
    if (aux1==1 && aux2==1 && cont==1)
      return 1;
    else
      return 0;
  }
}

int compara (tipo_arvore *arvore, int entrada)
{
  int aux, aux1;
  aux = aux1 = 0;
  if ( arvore != NULL)
  {
    if ( arvore->entrada == entrada)
      return 1;
    else
    {
      if (entrada < arvore->entrada )
	aux = compara(arvore->esquerda,entrada);
      else
	aux1 = compara(arvore->direita,entrada);
      
      if (aux || aux1)
	return 1;
    }
  }
  else
    return 0;
}

int main (int argc, char **argv)
{
  tipo_arvore *arvore = NULL;
  tipo_arvore *arvore2 = NULL;
  tipo_arvore *arvore3 = NULL;
  
  int y [] = {100,90,80,65,30,15,75,25,50};
  int x [] = {50,25,75,15,30,65,80,90,100};
  int z [] = {1,2,3,4,5,6,7,8,9};
  int i =0 , cont , w;
  
  while (i!=9)
  {
    insere_arvore (&arvore,x[i]);
    insere_arvore (&arvore2,y[i]);
    insere_arvore (&arvore3,z[i]);
    i++;
  }
  
  printf("TESTE COM ARVORE E ARVORE 2 ESPERA-SE QUE SEJAM IGUAIS:\n");
  w = comp(arvore,arvore2);
  if (w == 1)
    printf("ARVORES SAO DA MESMA ESPECIE\n\n");
  else
    printf("ARVORES NAO SAO DA MESMA ESPECIE\n");
  
  printf("TESTE COM ARVORE E ARVORE 3 ESPERA-SE QUE SEJAM DIFERENTES:\n");
  w = comp(arvore,arvore3);
  if (w == 1)
    printf("ARVORES SAO DA MESMA ESPECIE\n");
  else
    printf("ARVORES NAO SAO DA MESMA ESPECIE\n");
  
  return 0;
}
