#include <stdlib.h>
#include <stdio.h>

//Complexidade O(n)
struct Tlista{

	int valor;
	struct Tlista *prox;
	struct Tlista *anterior;

};typedef struct Tlista tipo_lista;
//prototipos
tipo_lista *alocaLista(int vl);
void insereInicio(tipo_lista **lst,int vl);
void retira_maiores(tipo_lista **lst, int k);
void ImprimeLista(tipo_lista *lst);

int main(){
	tipo_lista *lista;
	lista = NULL;
	
	insereInicio(&lista,10);
	insereInicio(&lista,8);
	insereInicio(&lista,15);
	insereInicio(&lista,17);
	insereInicio(&lista,11);
	insereInicio(&lista,7);
	insereInicio(&lista,4);
	insereInicio(&lista,6);
	printf("Antes\n");
	ImprimeLista(lista);
	
	retira_maiores(&lista,8);
	printf("Depois\n");
	ImprimeLista(lista);
	
	
	
}

//aloca lista
tipo_lista *alocaLista(int vl){
    tipo_lista *nova_lista;

    nova_lista = (tipo_lista*)malloc(sizeof(tipo_lista));
    nova_lista->prox = NULL;
    nova_lista->anterior = NULL;
    nova_lista->valor = vl;
}

//funcao insere no inicio da lista duplamente encadeada
void insereInicio(tipo_lista **lst,int vl){
    tipo_lista *novo_no;
    novo_no = alocaLista(vl);
    novo_no->prox = (*lst);
    if((*lst) != NULL){
        (*lst)->anterior = novo_no;
    }
    
    (*lst) = novo_no;
}

//funcao que imprime a lista duplamente encadeada
void ImprimeLista(tipo_lista *lst){
	if(lst != NULL){
	    printf(" [");
	    while (lst != NULL){
	        printf(" %d,", lst->valor);
	        lst = lst->prox;
	    }
	    printf("]\n");
	}
	else {
		printf("\nA Lista Esta Vazia !\n");
	}
    
}
//retira maiores
void retira_maiores(tipo_lista **lst, int k){
	
	tipo_lista *aux,*libera;
	if((*lst) != NULL){
		if((*lst)->valor > k){
			(*lst) = aux;
			(*lst) = (*lst)->prox;
			(*lst)->anterior = NULL;
		}
		
	    while((*lst) != NULL){
	    	if((*lst)->valor > k){
	    		aux = (*lst);
	   	 		(*lst) = (*lst)->prox;
	   	 		(*lst)->anterior = aux->anterior;
	   	 		aux->anterior->prox = (*lst);
	   	 		
	    		free(aux);
	    		printf("chegou aqui\n");
			}
			
			(*lst) = (*lst)->prox;
			
	    }
	}
	else{
		printf("\nA Lista ja esta Vazia\n");
	}

}

