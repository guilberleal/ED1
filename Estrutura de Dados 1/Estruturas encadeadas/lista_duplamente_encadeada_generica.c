/**
    IMPLEMENTACAO DO CODIGO DE LISTA DUPLAMENTE ENCADEADA
    GENERICA
    AUTOR: ALEX MATOS IUASSE
    EXERCICIOS DE ESTRUTURA DE DADOS 1
*/

#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DO NO
struct list
{
    void *input;
    struct list *next;
    struct list *previous;
};
typedef struct list type_list;

//ALOCAR NOVO NO
type_list *aloc (void *input)
{
    type_list *newno = NULL;
    newno = (type_list*) malloc (sizeof (type_list));
    newno->input = input;
    newno->previous = NULL;
    newno->next = NULL;
    return newno;
}

//INSERIR NO FIM DA LISTA
void insert_end (type_list **list, void *input)
{
    type_list *newno = aloc (input);
    if (*list == NULL)
    {
        *list = newno;
    }
    else
    {
        type_list *end = *list;
        while (end->next != NULL)
            end = end->next;
        end->next = newno;
        newno->previous = end;
    }
}

//INSERIR NO INICIO DA LISTA
void insert_first (type_list **list, void *input)
{
    type_list *newno = aloc (input);
    if (*list == NULL)
    {
        *list = newno;
    }
    else
    {
        (*list)->previous = newno;
        newno->next = *list;
        *list = newno;
    }
}

//INSERIR EM UMA POSICAO ESPECIFICA DA LISTA
void insert_place (type_list **list, void *input, int place)
{
    type_list *newno = aloc (input);
    if (place == 0)
    {
        insert_first(list,input);
    }
    else
    if (*list != NULL)
    {
        type_list *aux;
        int cont = 0;
        aux = *list;

        while( (aux != NULL) && (cont < place-1) )
        {
            aux = aux->next;
			cont ++;
        }
        if (cont == place-1)
        {
			if (aux->next == NULL)
            {
				insert_end (list, input);
			}
			else
            {
                type_list *newno = aloc(input);
				newno->next = aux->next;
				newno->previous = aux;
				aux->next = newno;
				(newno->next)->previous = newno;
			}
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

//REMOVER O PRIMEIRO ELEMENTO DA LISTA
void remove_first (type_list **list)
{
    if (*list == NULL)
    {
        printf("LISTA VAZIA");
    }
    else
    {
        type_list *aux = *list;
        *list = (*list)->next;
        (*list)->previous = NULL;
        free(aux);
    }
}

//REMOVER O ULTIMO ELEMENTO DA LISTA
void remove_end (type_list **list)
{
    if (*list == NULL)
    {
        printf("LISTA VAZIA");
    }
    else
    {
        if ((*list)->next == NULL)
        {
            free(*list);
            *list = NULL;
        }
        else
        {
            type_list *aux = *list;
            type_list *aux_previous = NULL;
            while (aux != NULL)
            {
                aux_previous = aux->previous;
                aux = aux->next;
            }
            aux_previous->next = NULL;
            free(aux);
        }
    }
}

//FUNCAO REMOVE POSICAO
int remove_place ( type_list **list, int pos ) 
{
    type_list *aux = *list;
    int i = 0;
    if (aux == NULL) 
	printf ( "LISTA VAZIA\n");
    else if (pos == 0) 
	    remove_first(list);
    else 
    {
	while (i != pos-1)
	{
	    aux = aux->next;
	    if (aux == NULL) 
	    {
		printf ("ERRO POSICAO INVALIDA\t");
		return 0;
	   }
	   i++;
	}
	if(aux->next == NULL)
	{
	    (aux->previous)->next = NULL;
	    free(aux);
	}
	else
	{
	    (aux->previous)->next = aux->next;
	    (aux->next)->previous = aux->previous;
	    free ( aux );
	}
    }
}

//FUNCAO DE IMPRESSAO
void print (type_list *list)
{
    int *i;
    if(list == NULL)
        printf("LISTA VAZIA\n");
    else
    {
        do
        {
            i = (int*) list->input;
	    printf ("[%d]\t",*i);
	    list = list->next;
        }
        while (list != NULL);
    }
}
//FUNCAO PRINCIPAL
int main (int argc, char **argv)
{
    type_list *list = NULL;
    int *i;

    //TESTES DA LISTA
    printf ("TESTE DE INSERCAO INICIO: \t");
    i = (int*) malloc (sizeof(int));
    *i = 1;
    insert_first(&list,i);
    i = (int*) malloc (sizeof(int));
    *i = 2;
    insert_first(&list,i);
    print(list);
    
    puts("");
    
    printf ("TESTE DE INSERCAO FIM: \t\t");
    i = (int*) malloc (sizeof(int));
    *i = 5;
    insert_end(&list,i);
    i = (int*) malloc (sizeof(int));
    *i = 6;
    insert_end(&list,i);
    print(list);
    
    puts("");
    
    printf("TESTE DE INSERCAO POSICAO 3: \t");
    i = (int*) malloc (sizeof(int));
    *i = 65;
    insert_place(&list,i,3);
    print(list);
    
    puts("");
    
    printf("TESTE DE REMOCAO INICIO: \t");
    remove_first(&list);
    print(list);
    
    puts("");
    
    printf("TESTE DE REMOCAO FIM: \t\t");
    remove_end(&list);
    print(list);
    
    puts("");
    
    printf("TESTE DE REMOCAO POSICAO 4: \t");
    remove_place(&list,4);

    puts("");
    
    printf("TESTE DE REMOCAO POSICAO 2: \t");
    remove_place(&list,2);
    print(list);
    
    puts("");
    return 0;
}
