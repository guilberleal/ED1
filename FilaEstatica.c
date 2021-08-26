#include <stdio.h>
#define N 10

struct s_fila{
	int vet[N];
	int contador;
};typedef struct s_fila Tfila;

//Prototipacao
void inicializaFila(Tfila *f);
void insereFila(Tfila *f,int valor);
void removeFila (Tfila *f);
void printaFila(Tfila f);


int main(){
	Tfila fila;
	
	inicializaFila(&fila);
	
	insereFila(&fila,7);
	insereFila(&fila,8);
	insereFila(&fila,5);
	insereFila(&fila,3);
	
	printaFila(&fila);
	
	removeFila(&fila);
	
	printaFila(&fila);
	
	removeFila(&fila);
	removeFila(&fila);
	removeFila(&fila);
	removeFila(&fila);

	insereFila(&fila,1);
	insereFila(&fila,2);

	printaFila(&fila);
	
	removeFila(&fila);
	removeFila(&fila);
	
	printaFila(&fila);
	
	return 1;
}
void inicializaFila(Tfila *f){
	f->contador = 0;
}

void insereFila(Tfila *f,int valor){
	if(f->contador < N){
		f->vet[f->contador] = valor;
		f->contador++;
	}
	else
		printf("\nA fila esta cheia\n");
}


void removeFila (Tfila *f){
	
	if(f->contador <= 0){
		printf("\nA fila esta vazia\n");
	}
	else{
		int i;
		for( i = 0; i < f->contador -1;i++){
			f->vet[i] = f->vet[i+1];
		}
		f->contador--;
	}
	
}

void printaFila(Tfila f){
	if(f.contador <= 0){
		printf("\nA fila esta vazia\n");
	}
	else{
		int i;
		for( i = 0;i <f.contador;i++){
		printf("\nfila na posicao[%d] = %d\n",i,f.vet[i]);
		}
	}
}
