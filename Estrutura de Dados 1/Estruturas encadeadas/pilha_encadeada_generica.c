/**
    IMPLEMENTAÇÃO DO CODIGO DE UMA PILHA ENCADEADA
    GENERICA.
    AUTOR: ALEX MATOS IUASSE
    EXERCICIOS DE ESTRUTURA DE DADOS 1
*/

#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DO NO
struct stack
{
    void *input;
    struct stack *next;
};
typedef struct stack type_stack;

//FUNCAO PARA ALOCAR NOVO NO
type_stack *aloc (void *input)
{
    type_stack *newno = NULL;
    newno = (type_stack*) malloc (sizeof (type_stack));
    newno->input = input;
    newno->next = NULL;
    return newno;
}

//FUNCAO PARA INSERIR EM PILHA
void insert_stack (type_stack **stack, void *input)
{
    type_stack *newno = aloc (input);
    if (*stack == NULL)
    {
        *stack = newno;
    }
    else
    {
        newno->next = *stack;
        *stack = newno;
    }
}

//FUNCAO PARA REMOVER EM PILHA
void remove_stack (type_stack **stack)
{
    if (*stack == NULL)
    {
        printf ("LISTA VAZIA");
    }
    else
    {
        type_stack *aux = *stack;
        *stack = (*stack)->next;
        free (aux);
    }
}

//FUNCAO DE IMPRIMIR KIWI
void print (type_stack *stack)
{
    int *i;
    if(stack == NULL)
        printf("PILHA VAZIA\n");
    else
    {
        do
        {
            i = (int*) stack->input;
			printf ("%d\t",*i);
			stack = stack->next;
        }
        while (stack != NULL);
    }
}

//FUNCAO PRINCIPAL
int main (int argc, char **argv)
{
    type_stack *stack = NULL;
    int *i = NULL;

    //TESTES PARA PILHA ENCADEADA
    printf ("TESTE DE INSERCAO: \t");
    i = (int*) malloc (sizeof(int));
    *i = 1;
    insert_stack (&stack,i);
    i = (int*) malloc (sizeof(int));
    *i = 2;
    insert_stack (&stack,i);
    i = (int*) malloc (sizeof(int));
    *i = 3;
    insert_stack (&stack,i);
    print(stack);

    printf("\nTESTE DE REMOCAO: \t");
    remove_stack(&stack);
    print(stack);
    printf("\nTESTE DE REMOCAO: \t");
    remove_stack(&stack);
    print(stack);
    printf("\nTESTE DE REMOCAO: \t");
    remove_stack(&stack);
    print(stack);

    return 0;
}
