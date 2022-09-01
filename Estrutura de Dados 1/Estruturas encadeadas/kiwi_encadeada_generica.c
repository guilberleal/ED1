/**
    IMPLEMENTACAO DO CODIGO PARA FILA ENCADEADA
    GENERICA
    AUTOR: ALEX MATOS IUASSE
    EXERCICIOS DE ESTRUTURA DE DADOS 1
*/

#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DO NO
struct kiwi
{
    void *input;
    struct kiwi *next;
};
typedef struct kiwi type_kiwi;

//FUNCAO DE ALOCAR NO
type_kiwi *aloc (void *input)
{
    type_kiwi *newno = NULL;
    newno = (type_kiwi*) malloc (sizeof (type_kiwi));
    newno->input = input;
    newno->next = NULL;
    return newno;
}

//FUNCAO DE INSERIR NA FILA
void insert_kiwi (type_kiwi **kiwi, void *input)
{
    type_kiwi *newno = aloc (input);

    if (*kiwi == NULL)
        *kiwi = newno;
    else
    {
        type_kiwi *aux = *kiwi;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = newno;
    }
}

//FUNCAO DE REMOVER NA FILA
void remove_kiwi (type_kiwi **kiwi)
{
    if (*kiwi == NULL)
        printf ("FILA VAZIA");
    else
    {
        type_kiwi *aux = *kiwi;
        *kiwi = (*kiwi)->next;
        free (aux);
    }
}

//FUNCAO DE IMPRIMIR KIWI
void print (type_kiwi *kiwi)
{
    int *i;
    if(kiwi == NULL)
        printf("FILA VAZIA\n");
    else
    {
        do
        {
            i = (int*) kiwi->input;
			printf ("%d\t",*i);
			kiwi = kiwi->next;
        }
        while (kiwi != NULL);
    }
}

//FUNCAO PRINCIPAL
int main (int argc, char **argv)
{
    type_kiwi *kiwi = NULL;
    int *i;

    //TESTES PARA FILA ENCADEADA
    printf ("TESTE DE INSERCAO: \t");
    i = (int*) malloc (sizeof(int));
    *i = 1;
    insert_kiwi(&kiwi,i);
    i = (int*) malloc (sizeof(int));
    *i = 2;
    insert_kiwi(&kiwi,i);
    i = (int*) malloc (sizeof(int));
    *i = 3;
    insert_kiwi(&kiwi,i);
    print (kiwi);

    printf("\n");

    printf("TESTE DE REMOCAO: \t");
    remove_kiwi(&kiwi);
    print(kiwi);
    printf("\n");
    printf("TESTE DE REMOCAO: \t");
    remove_kiwi(&kiwi);
    print(kiwi);
    printf("\n");
    printf("TESTE DE REMOCAO: \t");
    remove_kiwi(&kiwi);
    print(kiwi);

    return 0;
}
