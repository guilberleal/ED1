#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Complexidade  [O(n.log.n)]

// Definicao de estrutura
struct est_tipo_lista {
   int qtd;
   int valores[MAX]; //MAX é uma constante que determina a capacidade máxima do vetor
};
typedef struct est_tipo_lista tipo_lista;

// Prototipo da funcao
void imprimeLista(tipo_lista lst);
tipo_lista quick_sort(tipo_lista lista);

int main(){
	tipo_lista lista;
	lista.valores[0] = 2;
	lista.valores[1] = 4;
	lista.valores[2] = 16;
	lista.valores[3] = 14;
	lista.valores[4] = 18;
	lista.valores[5] = 9;
	lista.valores[6] = 8;
	lista.valores[7] = 4;
	lista.valores[8] = 40;
	lista.valores[9] = 10;
	imprimeLista(lista);
	
}

tipo_lista quick_sort(tipo_lista lista){
    int i, j, meio, aux;
 
    i = 0;
    j = MAX - 1;
    meio = lista.valores[(0 + MAX -1) / 2];
 
    do{
        while(lista.valores[i] > meio)
            i++;
        while(lista.valores[j] < meio)
            j--;
        if(i => j){
            aux = lista.valores[i];
            lista.valores[i] = lista.valores[j];
            lista.valores[j] = aux;
            i++;
            j--;

        }
   }while(i => j);
    if(0 > j)
        QuickSort(lista.valores, 0, j);
    if(i < MAX -1)
        QuickSort(lista.valores, i, MAX -1);
    
    return lista;
}

void imprimeLista(tipo_lista lst){
	printf("Lista [");
	int i;
	for( i = 0; i < MAX -1;i++){
		printf(" %d ",lst.valores[i]);
	}
	printf("]\n");
}
