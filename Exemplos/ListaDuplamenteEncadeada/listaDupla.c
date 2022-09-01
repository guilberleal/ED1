#include <stdio.h>
#include <stdlib.h>

//Definicao da estruct
struct estru_no_dup{
	int valor;
	struct estru_no_dup *prox;
	struct estru_no_dup *anterior;
}; typedef struct estru_no_dup tipo_no_dup;


//Prototipos
tipo_no_dup *alocaNovoNoDup(int vl);
void insereInicioDup(tipo_no_dup **lst,int vl);
void insereFimDup(tipo_no_dup **lst,int vl);
void ImprimeListaDup(tipo_no_dup *lst);
int removeInicioDup(tipo_no_dup **lst);
int removeFimDup(tipo_no_dup **lst);

//Funcao main
int main(){
	tipo_no_dup *listaDup;

    listaDup = NULL;
	//inicializando a lista 1
    insereInicioDup(&listaDup,10);
    insereFimDup(&listaDup,20);
    insereFimDup(&listaDup,30);
	insereFimDup(&listaDup,50);
	insereInicioDup(&listaDup,10);
	printf("Lista 1:");
    ImprimeListaDup(listaDup);
	//inicializa a lista 2
	insereInicioDup(&listaDup,10);
	insereInicioDup(&listaDup,20);
	insereInicioDup(&listaDup,30);
	insereInicioDup(&listaDup,50);
	insereFimDup(&listaDup,60);
	insereFimDup(&listaDup,70);
	printf("Lista 2:");
	ImprimeListaDup(listaDup);
	
    
	
	return 1;
}

//Funcao que aloca memoria para um TIPO_NO_DUP
tipo_no_dup *alocaNovoNoDup(int vl){
    tipo_no_dup *novo_no;
    novo_no = (tipo_no_dup*)malloc(sizeof(tipo_no_dup));
    novo_no->valor = vl;
    novo_no->anterior = NULL;
    novo_no->prox = NULL;
    return novo_no;
}

//funcao insere no inicio da lista duplamente encadeada
void insereInicioDup(tipo_no_dup **lst,int vl){
    tipo_no_dup *novo_no;
    novo_no = alocaNovoNoDup(vl);
    novo_no->prox = (*lst);
    if((*lst) != NULL){
        (*lst)->anterior = novo_no;
    }
    (*lst) = novo_no;
}
//funcao que insere no fim da lista duplamente encadeada
void insereFimDup(tipo_no_dup **lst,int vl){
    tipo_no_dup *novo_no,*aux;
    if((*lst)==NULL){
        (*lst) = alocaNovoNoDup(vl);
    }
    else{
        aux = (*lst);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        novo_no = alocaNovoNoDup(vl);
        novo_no->anterior = aux;
        aux->prox = novo_no;
    }

}
//funcao que imprime a lista duplamente encadeada
void ImprimeListaDup(tipo_no_dup *lst){
    printf(" [");
    while (lst){
        printf("%d ", lst->valor);
        lst = lst->prox;
    }
    printf("]\n");
    
}
//funcao que remove no inicio da lista duplamente encadeada
int removeInicioDup(tipo_no_dup **lst){
    tipo_no_dup *aux;
    int vl;
    if((*lst != NULL)){
        vl = (*lst)->valor;
        aux = (*lst);
        (*lst) = (*lst)->prox;
        if((*lst)!= NULL){   //verifica se Nao é o ultimo elemento
            (*lst)->anterior = NULL;
        }
        if((aux->anterior == NULL) && ((*lst)->prox == NULL)){ //verifica se é o ultimo elemento
            (*lst) = NULL;
        }
        free(aux);
        return vl;
    }
    else {
        printf("[ERRO] A Lista esta vazia");
        return -1;
    }
}
//funcao que remove no fim da lista duplamente encadeada
int removeFimDup(tipo_no_dup **lst){
    tipo_no_dup *aux;
    int vl;
    if((*lst) != NULL){
        aux = (*lst);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        vl = aux->valor;
        if(aux->anterior != NULL){
            aux->anterior->prox = NULL;
        }
        free(aux);
        return vl;
    }
    else{ 
        printf("[ERRO] A Lista esta Vazia");
        return -1;
    }
    
}
