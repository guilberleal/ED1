/*
*Booble sorte
*UFMT
*Autor: Alex Matos Iuasse
*Data: 21/11/2013
*Metodo Bubble Sort
*/

#include <stdio.h>
#include <stdlib.h>
#define Max 5

struct lista
{
    int vetor [ Max ];
    int indx;
};
typedef struct lista tipo_lista;

int inserir ( tipo_lista *lista, int entrada )
{
    int i;
    if( lista->indx < Max )
    {
        lista->vetor [ lista->indx ] = entrada;
        lista->indx++;
    }
    return 0;
}

int bubble ( tipo_lista *lista )
{
    int aux,i,cont;
    while( cont )
    {
        cont = 0;
        for( i = 0; i < lista->indx-1; i++)
        {
            if( lista->vetor [ i+1 ] < lista->vetor [ i ] )
            {
                aux = lista->vetor [ i ];
                lista->vetor [ i ] = lista->vetor [ i+1 ];
                lista->vetor[ i+1 ] = aux;
                cont = 1;
            }
        }
    }
}
void imprimir (tipo_lista lista)
{
    int i;
    for(i=0; i<lista.indx; i++)
    {
        printf("%i | ",lista.vetor[i]);
    }
}

int main (int argc, char *argv[])
{
    tipo_lista lista;
    lista.indx = 0;
    int entrada;

    inserir(&lista,2);
    inserir(&lista,7);
    inserir(&lista,1);
    inserir(&lista,3);
    inserir(&lista,0);
    imprimir(lista);
    bubble (&lista);
    puts("");
    imprimir(lista);

    return 0;
}
