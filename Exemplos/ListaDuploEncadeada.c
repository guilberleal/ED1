#include <stdio.h>
#include <stdlib.h>

//Definicao da struct
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

//Funcao main
int main(){
	tipo_no_dup *listaDup;
    listaDup = NULL;

    insereInicioDup(&listaDup,10);

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
    printf("Lista DUPLAMENTE ENCADEADA: [");
    while (lst != NULL){
        printf("%d ", lst->valor);
        lst = lst->prox;
    }
    printf("]\n");
    
}

