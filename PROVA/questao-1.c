#include <stdlib.h>
#include <stdio.h>

struct Tlista{

	int valor;
	struct Tlista *prox;

};typedef struct Tlista tipo_lista;

//prototipo
tipo_lista *alocaLista(int vl);
void imprimeLista(tipo_lista *lst);
void insere_ordenado(tipo_lista **lst, int valor);
void inserePosicao(tipo_lista **lst,int vl,int pos);

int main(){
	tipo_lista *lista;
	lista = NULL;
	
	insere_ordenado(&lista,8);
	insere_ordenado(&lista,6);
	insere_ordenado(&lista,4);
	insere_ordenado(&lista,3);
	insere_ordenado(&lista,10);
	insere_ordenado(&lista,11);
	insere_ordenado(&lista,5);
	insere_ordenado(&lista,1);
	
	
	
	imprimeLista(lista);
	
}

//inicializa a lista
tipo_lista *alocaLista(int vl){
    tipo_lista *nova_lista;

    nova_lista = (tipo_lista*)malloc(sizeof(tipo_lista));
    nova_lista->prox = NULL;
    nova_lista->valor = vl;
}
//insere de forma ordenada
void insere_ordenado(tipo_lista **lst, int valor){
	tipo_lista *aux,*aux2;
	aux = (*lst);
	aux2 = (*lst);
	int cont = 0;
	
	
	if((*lst) == NULL){
		inserePosicao(&(*lst),valor,0);
		
	}
	else{
		while(valor > aux->valor && aux->prox != NULL ){
			cont++;
			aux = aux->prox;	
			if(aux->prox == NULL){
				cont++;
			}
		}
		inserePosicao(&(*lst),valor,cont);
		
		
	}
	
	
}


//insere posicao
void inserePosicao(tipo_lista **lst,int vl,int pos){
	tipo_lista *novo_no,*aux,*aux2;
	int contador;
	if(pos == 0){
		novo_no = alocaLista(vl);
		novo_no->prox = (*lst);
		(*lst) = novo_no;
	}
	else{
		aux = (*lst);
		contador = 0;
		while((aux != NULL) && (contador < pos)){
			aux2 = aux;
			aux = aux->prox;
			contador++;
		}
		if((aux != NULL)&& (contador == pos)){
			novo_no = alocaLista(vl);
			novo_no->prox = aux;
			aux2->prox = novo_no;
		}
		else if((aux== NULL) && (contador == pos)){
			novo_no = alocaLista(vl);
			aux2->prox = novo_no;
		}
		else{
			printf("\nERRO Posicao invalida para insersao\n");
		}
	}
}

//imprime lista
void imprimeLista(tipo_lista *lst){
	printf("Lista: [");
	while(lst != NULL){
		printf(" %d ",lst->valor);
		lst = lst->prox;
	}
	printf("]\n");
}
