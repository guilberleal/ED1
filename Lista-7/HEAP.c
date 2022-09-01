
#include <stdio.h>
#include <stdlib.h>

//definicao struct heap
#define N 20
struct heap_est{
    int heap[N];
    int cont;
};typedef struct heap_est tipo_heap;


//prototipos
int posPai(int p);
int posFEsq(int f);
int posFDir(int f);
void inicializaHeap(tipo_heap *hp); //cria um heap
void insereHeap(tipo_heap *hp, int valor);//insere no Heap
void insereSemSubir(tipo_heap *hep, int valor);//insere sem subir 
void sobeValor(tipo_heap *hp, int pos);
void desceValor(tipo_heap *hp, int pos);
void imprimeHeap(tipo_heap hp);//imprime Heap
void qtdElementos(tipo_heap hp);//quantidade de elementos armazenados
void valorMaximo(tipo_heap hp);//Consulta do valor máximo (raiz)
void concatenaHeap(tipo_heap *hpA,tipo_heap *hpB);//concatena duas listas
int removeHeap(tipo_heap *hp);//Remoção do valor máximo (raiz) – retornando o valor
void heapSort(tipo_heap *hp);//ondenacao heap
void verificaValor(tipo_heap *hp,int valor);// Verifica se um dado valor (passado por parâmetro) está presente no Heap;

//funcao que inicializa heap
void inicializaHeap(tipo_heap *hp){
   hp->cont = 0;
}

//funcao que calcula os indeces dos valores pai, filho esq e dir
int posPai(int i){
    return (int)((i-1)/2);
}

int posFEsq(int i){
    return 2*i+1;
}
int posFDir(int i){
    return 2*i+2;
}

//funcao que insere heap
void insereHeap(tipo_heap *hp, int valor){
     hp->heap[hp->cont++] = valor;
     sobeValor(hp,hp->cont-1);
}
//funcao que insere sem subir
void insereSemSubir(tipo_heap *hep, int valor){
	hep->heap[hep->cont++] = valor;
}

//funcao para heap maximo, que sobe com o valor atÃ© a posicao adequada
void sobeValor(tipo_heap *hp, int pos){
	int aux;
    if(hp->heap[pos] > hp->heap[posPai(pos)]){
        aux = hp->heap[pos];
        hp->heap[pos] = hp->heap[posPai(pos)];
        hp->heap[posPai(pos)] = aux;
        if(posPai(pos)>0){
            sobeValor(hp,posPai(pos));
        } 
    }
}

//imprime o heap
void imprimeHeap(tipo_heap hp){
    int i;
    printf("\nHEAP MAX [");
    for(i = 0; i < hp.cont;i++){
        printf(" %d ",hp.heap[i]);
        
    }
    printf("]\n");
}
void qtdElementos(tipo_heap hp){
	printf("\nQuantidade de elementos Armazenado no Heap: %d",hp.cont);
}
void valorMaximo(tipo_heap hp){
	int valor;
	if(hp.cont > 0){
		valor = hp.heap[0];
		printf("\nValor Maximo: %d",valor);
	}
	else{
		printf("\n[ERRO] Heap vazio");
	}
	
}
void desceValor(tipo_heap *hp, int pos){
	int novaPos,aux;
	novaPos = -1;
	if(posFEsq(pos) < hp->cont){
		if(posFDir(pos) < hp->cont){
			if(hp->heap[posFEsq(pos)] > hp->heap[posFDir(pos)]){
				if(hp->heap[pos] <  hp->heap[posFEsq(pos)]){
					novaPos = posFEsq(pos);
				}
			}
			else{
				if(hp->heap[pos] < hp->heap[posFDir(pos)]){
					novaPos = posFDir(pos);
				}
			}
		}
		else{
			if(hp->heap[pos] < hp->heap[posFEsq(pos)]){
				novaPos = posFEsq(pos);
			}
		}
		if(novaPos > -1){
		aux = hp->heap[pos];
		hp->heap[pos] = hp->heap[novaPos];
		hp->heap[novaPos] = aux;
		desceValor(hp,novaPos);
		}
	}
}

int removeHeap(tipo_heap *hp){
	int valor;
	if(hp->cont > 0){
		valor = hp->heap[0];
		hp->heap[0] = hp->heap[hp->cont-1];
		hp->cont--;
		desceValor(hp,0);
		return valor;
	}
	else{
		return -1;
	}
}

void heapSort(tipo_heap *hp){
	int tam = hp->cont;
	int i,j,valor;
	int vet[tam];
	for(i= 0; i < tam;i++){
		vet[i] = removeHeap(hp);
	}
	for(j = 0; j < tam ;j++){
		valor = vet[j];
		insereSemSubir(hp,valor);
	}	
}

void verificaValor(tipo_heap *hp,int valor){
	int i,p;
	for(i = 0; i < hp->cont;i++){
		if(hp->heap[i] == valor){
			printf("\nO valor: %d esta presente no heap, Na posicao: %d",valor,i);
			p = 1;
		}
	}
	if(p != 1){
		printf("\nEste valor nao esta presente no heap");		
	}	
}
void concatenaHeap(tipo_heap *hpA,tipo_heap *hpB){
	int i;
	for(i = 0; i < hpB->cont;i++){
		insereSemSubir(hpA,hpB->heap[i]);
	}	
}

int main(){
    tipo_heap heap;
    inicializaHeap(&heap);

    insereHeap(&heap,10);
    insereHeap(&heap,5);
    insereHeap(&heap,15);
    insereHeap(&heap,20);
    insereHeap(&heap,17);
    insereHeap(&heap,8);
    insereHeap(&heap,25);
    
    tipo_heap heap2;
    inicializaHeap(&heap2);
    
    insereHeap(&heap2,30);
    insereHeap(&heap2,31);
    insereHeap(&heap2,32);
    insereHeap(&heap2,33);
    insereHeap(&heap2,34);
    
    concatenaHeap(&heap,&heap2);
    
    
    imprimeHeap(heap);
    
    /*
    printf("\nValor Removido: %d",removeHeap(&heap));
    imprimeHeap(heap);
    
    heapSort(&heap);
    printf("\nHEAP Ordenado");
    imprimeHeap(heap);
    
    verificaValor(&heap,17);
    
    qtdElementos(heap);
    */

    return 0;
}
