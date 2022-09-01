/**
  LISTA ENCADEADA CIRCULAR
  AUTOR: ALEX MATOS IUASSE
*/

#include <stdio.h>
#include <stdlib.h>

struct lista_no
{
    int entrada;
    struct lista_no *prox;
};
typedef struct lista_no tipono;

//ALOCAR NOVO NO
tipono *aloca_no (int entrada)
{
	tipono *novono = NULL;
	novono = (tipono*) malloc (sizeof(tipono));
	novono->entrada = entrada;
	novono->prox = NULL;
	return (novono);
}

//FUNÇÃO PARA INSERÇÃO
void inserir_inicio (tipono **lista, int entrada)
{
	tipono *novono = aloca_no(entrada);
	tipono *aux = *lista;
	if (*lista == NULL)
	{
		*lista = novono;
		(*lista)->prox = *lista;
	}
	else
	{
		while (aux->prox != *lista)
			aux = aux->prox;
		novono->prox = *lista;
		aux->prox = novono;
		*lista = novono;
    }
}
//FUNÇÃO IMPRIMIR
void imprimir (tipono *lista)
{
	tipono *aux = lista;
	if (lista == NULL)
	{
		printf("LISTA VAZIA");
	}
	else if (lista->prox == lista){
		printf("[ %d ]\n",lista->entrada);
		}
	else
	{
		tipono *aux;
		aux = lista;

		do{
			printf("[ %d ]\t",aux->entrada);
			aux = aux->prox;
		}while (aux != lista);
		puts("");
    }
}

//FUNÇÃO INSERIR FINAL
void inserir_final (tipono **lista, int entrada)
{
	tipono *novono = aloca_no(entrada);

	if(*lista == NULL)
	{
		*lista = novono;
		(*lista)->prox = *lista;
	}
	else
	{
		tipono *aux = *lista;
		while (aux->prox != *lista)
			aux = aux->prox;
		aux->prox = novono;
		novono->prox = *lista;
	}
}

//REMOVER FINAL
void remover_final (tipono **lista)
{
	if(*lista == NULL)
	{
	      printf("LISTA VAZIA");
	}
	else
	{
		tipono *aux = NULL;
		tipono *aux_fim = *lista;

		if ((*lista)->prox == *lista )
		{
			free(*lista);
			*lista = NULL;
		}
		else
		{
			while (aux_fim->prox != *lista)
			{
				aux = aux_fim;
				aux_fim = aux_fim->prox;
			}
			aux->prox = *lista;
			free(aux_fim);
		}
	}
}

//REMOVER INICIO
void remove_inicio (tipono **lista)
{
	if(*lista == NULL)
	{
	      printf("LISTA VAZIA");
	}
	else
	{
	      tipono *aux = *lista;
		  tipono *aux_fim = *lista;
		  while (aux_fim->prox != *lista)
				aux_fim = aux_fim->prox;
			*lista = (*lista)->prox;
			aux_fim->prox = *lista;
			free(aux);
	}
}

//FUNÇÃO PRINCIPAL
int main (int argc, char *argv[])
{
    tipono *lista = NULL;

	puts("");
	printf("TESTE INSERIR INICIO: \n");
	inserir_inicio (&lista,6);
	inserir_inicio (&lista,6);
	inserir_inicio (&lista,6);
	imprimir (lista);
	printf("TESTE REMOVER 1 ELEMENTO INICIO: \n");
	remove_inicio (&lista);
	imprimir (lista);
	printf("TESTE INSERIR FINAL: \n");
	inserir_final (&lista,666);
	imprimir (lista);
	printf("TESTE REMOVER FINAL: \n");
	remover_final (&lista);
	imprimir (lista);
	puts("");

    return 0;
}
