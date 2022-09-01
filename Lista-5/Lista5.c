#include <stdio.h>
#include <stdlib.h>

struct Tlista{

	int valor;
	struct Tlista *prox;
	struct Tlista *anterior;

};typedef struct Tlista tipo_lista;

//prototipos
tipo_lista *alocaLista(int vl);
void insereInicio(tipo_lista **lst,int vl);
void insereFim(tipo_lista **lst,int vl);
void ImprimeLista(tipo_lista *lst);
int removeFimDup(tipo_lista **lst);
int removeInicioDup(tipo_lista **lst);
void concatenaLista(tipo_lista *lstA, tipo_lista *lstB,tipo_lista **lstC);
void removeTodosNo(tipo_lista **lst);
void inverteLista(tipo_lista **lst);
void ordenaLista(tipo_lista **lstA, tipo_lista **lstB,tipo_lista **lstC);
void numerodeElementos(tipo_lista **lst);
tipo_lista *retornaEndMemoria(tipo_lista *lst,int vl);
tipo_lista *copiaLista(tipo_lista *lst);
void valoresComun(tipo_lista *lstA,tipo_lista *lstB,tipo_lista **lstC);
void insere_pos(tipo_lista **lista, int valor, int pos);


//funcao main
int main(){
    //inicializa lista A
	tipo_lista *listaA;
	listaA = NULL;
	insereInicio(&listaA,10);
	insereInicio(&listaA,15);
	insereInicio(&listaA,13);
	insereInicio(&listaA,40);
	insereInicio(&listaA,50);
	printf("LISTA A:");
	ImprimeLista(listaA);
    
    //inicializa lista B
    tipo_lista *listaB;
    listaB = NULL;
    insereInicio(&listaB,17);
	insereInicio(&listaB,15);
	insereInicio(&listaB,80);
    insereInicio(&listaB,40);
    printf("Lista B: ");
	ImprimeLista(listaB);
	
	//inicializa lista C
	tipo_lista *listaC;
	listaC = NULL;
	
	
    //1) concatena lista A e B
    concatenaLista(listaA,listaB,&listaC);
    printf("LISTA A e B concatenada: ");
    ImprimeLista(listaC);
    
    
    /*2)Liberar todos os nós da lista (de uma só vez)
    removeTodosNo(&listaA);
    ImprimeLista(listaA); */
    
 	/*3)Inverter uma lista de modo que o último elemento se torne o primeiro, e assim por diante;
    inverteLista(&listaC);
    ImprimeLista(listaC);
    */
    
    /*4)Combinar duas listas já ordenadas numa única lista ordenada;
    ordenaLista(&listaA,&listaB,&listaC);
    printf("\nLista A + B Ordenada");
    ImprimeLista(listaC);
	*/
	
	/*5)Formar uma lista contendo a intersecção dos elementos de duas listas (apenas os valores comuns);
	valoresComun(listaA,listaB,&listaC);
	printf("Valores em comum na Lista A e Lista B :");
	ImprimeLista(listaC);
	*/
	
	/*6) insere na posicao dada
	int i = 3;
	insere_pos(&listaA,10,i);
	printf("\nLista A com valor inserido na posicao: %d\n",i);
	ImprimeLista(listaA);
	*/
	
	/*7)Retornar o número de elementos da lista;
	numerodeElementos(&listaC);
	*/
	
	/*8)Retorne um ponteiro (endereço de memória) para o nó com o valor do dado igual a x (parâmetro);
	printf("O endereco de memoria do parametro dado = (%p)\n",retornaEndMemoria(listaC,50));
	*/
	
	/*10)Criar uma cópia de uma lista
	listaC = copiaLista(listaA);
	insereInicio(&listaA,100);
	printf("\nCopia da lista A:");
	ImprimeLista(listaC);
	printf("\nLista A:");
	ImprimeLista(listaA);
	*/
	
    return 1;
}

//inicializa a lista
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
//funcao que insere no fim da lista duplamente encadeada
void insereFim(tipo_lista **lst,int vl){
    tipo_lista *novo_no,*aux;
    if((*lst)==NULL){
        (*lst) = alocaLista(vl);
    }
    else{
        aux = (*lst);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        novo_no = alocaLista(vl);
        novo_no->anterior = aux;
        aux->prox = novo_no;
    }
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
//funcao que remove no fim da lista duplamente encadeada
int removeFimDup(tipo_lista **lst){
    tipo_lista *aux;
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

//funcao que remove no inicio da lista duplamente encadeada
int removeInicioDup(tipo_lista **lst){
    tipo_lista *aux;
    int vl;
    if((*lst != NULL)){
        vl = (*lst)->valor;
        aux = (*lst);
        (*lst) = (*lst)->prox;
        if((*lst)!= NULL){   //verifica se Nao e o ultimo elemento
            (*lst)->anterior = NULL;
        }
        if((aux->anterior == NULL) && ((*lst)->prox == NULL)){ //verifica se e o ultimo elemento
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

//concatena as duas listas
void concatenaLista(tipo_lista *lstA, tipo_lista *lstB,tipo_lista **lstC){
    tipo_lista *aux;

    aux = lstA;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    lstB->anterior = aux;
    aux->prox = lstB;
    (*lstC) = lstA;
}
//funcao que libera todos os Nós
void removeTodosNo(tipo_lista **lst){
	tipo_lista *aux,*libera;
	if((*lst) != NULL){
	    while((*lst)->prox != NULL){
	    	aux = (*lst);
	   	 	(*lst) = (*lst)->prox;
	    	free(aux);
	    }
	    (*lst) = NULL;
	}
	else{
		printf("\nA Lista ja esta Vazia\n");
	}
 
}

//Inverter uma lista de modo que o último elemento se torne o primeiro, e assim por diante
void inverteLista(tipo_lista **lst){
	tipo_lista *aux,*aux2;
	if((*lst) != NULL){
        aux = (*lst);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
      	(*lst) = aux;
		(*lst)->prox = (*lst)->anterior;
        (*lst)->anterior = NULL;
        
        aux = aux->prox;
        while(aux->anterior != NULL){
        	aux2 = aux->prox;
        	aux->prox = aux->anterior;
        	aux->anterior = aux2;
        	aux = aux->prox;
		}
		aux->anterior = aux->prox;
		aux->prox = NULL;
	}
}

//Combinar duas listas já ordenadas numa única lista ordenada
void ordenaLista(tipo_lista **lstA, tipo_lista **lstB,tipo_lista **lstC){
	tipo_lista *auxA,*auxB,*auxC;
	auxC = NULL;
	int vl;
	auxA = (*lstA);
	auxB = (*lstB);

	while(auxA != NULL && auxB != NULL){
		if(auxA->valor >= auxB->valor){
			vl = auxA->valor;
			insereInicio(&auxC,vl);
			auxA = auxA->prox;
		
		}
		else{
			vl = auxB->valor;
			insereInicio(&auxC,vl);
			auxB = auxB->prox;	
			
		}
	}
	if(auxA != NULL){
		while(auxA != NULL){
		vl = auxA->valor;
		insereInicio(&auxC,vl);
		auxA = auxA->prox;
		}
	}
	else if(auxB != NULL){
		while(auxB != NULL){
			vl = auxB->valor;
			insereInicio(&auxC,vl);
			auxB = auxB->prox;
		}
	}
	(*lstC) = auxC;
}
	


//Retornar o número de elementos da lista;
void numerodeElementos(tipo_lista **lst){
	tipo_lista *aux;
	int i = 1;
	if((*lst) != NULL){
        aux = (*lst);
        while(aux->prox != NULL){
        	i++;
            aux = aux->prox;
        }
        printf("\nA Lista tem: %d Elementos\n",i);
	}
	else{
		printf("\nA Lista tem nem um elemento\n");
	}
}

// Retorne um ponteiro (endereço de memória) para o nó com o valor do dado igual a x (parâmetro)
tipo_lista *retornaEndMemoria(tipo_lista *lst,int vl){
	while(lst != NULL){
		if(lst->valor = vl){
			return lst;
		}
	lst = lst->prox;
	}
	return NULL;
}

//Criar uma cópia de uma lista
tipo_lista *copiaLista(tipo_lista *lst){
	tipo_lista *nova_lista;
	while(lst != NULL){
		insereFim(&nova_lista,lst->valor);
		lst = lst->prox;
	}
	return nova_lista;
}

//Formar uma lista contendo a intersecção dos elementos de duas listas (apenas os valores comuns);
void valoresComun(tipo_lista *lstA,tipo_lista *lstB,tipo_lista **lstC){
	//problema na funcao
	tipo_lista *auxB,*auxC;
	int vlA,vlB,vl;
	auxB = lstB;
	while(lstA != NULL){
		while(lstA->valor != lstB->valor){
			printf("\nVALOR DE A: %d\n",lstA->valor);
			printf("\nVALOR DE B: %d\n",lstB->valor);
			if(lstB == NULL){
				break;
			}
			else{
				lstB = lstB->prox;
			}
		}
		if(lstA->valor == lstB->valor){
			vl = lstA->valor;
			insereFim(&auxC,vl);
			auxC = auxC->prox;	
			
			lstA = lstA->prox;
			lstB = auxB;
		}
		else{
			printf("A++");
			lstA = lstA->prox;
			lstB = auxB;	
		}
	}
	
	(*lstC) = auxC;
}

//Funcao que insere numa posicao especifica (valida) da lista
void insere_pos(tipo_lista **lista, int valor, int pos) {
    int auxPos;
    tipo_lista *novo_no, *aux;
    if (pos == 0) {
        insereInicio(lista, valor);
    } else if (pos > 0) {
        auxPos = 0;
        aux = (*lista);
        while ( (aux != NULL) && (auxPos < pos) ) {
            aux = aux->prox;
            auxPos++;
        }
        if ( (aux == NULL) && (auxPos == pos-1) ) {
            insereFim(lista, valor);
        } else if (aux != NULL) {
            novo_no = alocaLista(valor);
            aux->anterior->prox = novo_no;
            novo_no->anterior = aux->anterior;
            aux->anterior = novo_no;
            novo_no->prox = aux;
        }
    }
}

