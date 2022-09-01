#include <stdio.h>
#include <stdlib.h>

struct estru_no{
	int valor;
	struct estru_no *prox;
};typedef struct estru_no tipo_no;

//Prototipos
tipo_no *alocaNovoNo(int vl);
void insereFinal(tipo_no **fl,int vl);
void imprimeFila(tipo_no *fl);
tipo_no *insereFinal2(tipo_no *fl,int vl);

//main
int main(){
	tipo_no *fila;
	fila = NULL;
	
	int valor = 20;
	insereFinal(&fila,valor);
	insereFinal(&fila,9);
	
	imprimeFila(fila);
	fila = insereFinal2(fila,3);
	imprimeFila(fila);
	return 1;
}

//Funcao que aloca memoria para tipo nó
tipo_no *alocaNovoNo(int vl){
	tipo_no *novo_no;
	novo_no = (tipo_no*) malloc(sizeof(tipo_no));
	novo_no->valor = vl;
	novo_no->prox = NULL;
	return novo_no; 
}
//funcao que insere novo nó no final
void insereFinal(tipo_no **fl,int vl){
	tipo_no *novo_no;
	novo_no = alocaNovoNo(vl);
	if((*fl) == NULL){
		(*fl) = novo_no;
	}
	else{
		tipo_no *aux;
		aux = (*fl);
		while(aux->prox != NULL){
			aux= aux->prox;
		}
		aux->prox = novo_no;
	}
}

//funcao imprime valores
void imprimeFila(tipo_no *fl){
	printf("Saida <- [");
	while(fl != NULL){
		printf("[%d], ",fl->valor);
		fl = fl->prox;	
	}
	printf("] <-Entrada\n");
}

//funcao que insere novo valor no final retornando o endereco do primeiro valor
tipo_no *insereFinal2(tipo_no *fl,int vl){
	tipo_no *novo_no,*aux;
	novo_no = alocaNovoNo(vl);
	if(fl == NULL){
		return novo_no;
	}
	else{
		aux = fl;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo_no;
		return fl;
	}
}
