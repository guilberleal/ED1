#include <stdio.h>
#include <stdlib.h>


struct tipofila{
    int fila[10];
    int inicio;
    int fim;
    int qtd;
};typedef struct tipofila tipo_fila;

//prototipacao
void inicializaFila(tipo_fila *fl);
void insereFila(tipo_fila *fl,int valor);
int removeFila(tipo_fila *fl);
void printaFila(tipo_fila *fl);


//funcao main
int main(){
    tipo_fila s_fila;
    inicializaFila(&s_fila);

    insereFila(&s_fila,1);
    insereFila(&s_fila,2);
    insereFila(&s_fila,3);
    insereFila(&s_fila,4);
    insereFila(&s_fila,5);
    insereFila(&s_fila,6);
    insereFila(&s_fila,7);
    insereFila(&s_fila,8);
   	insereFila(&s_fila,9);
	insereFila(&s_fila,10);	
    printf("\nValor removido da fila = %d\n",removeFila(&s_fila));
    printf("\nValor removido da fila = %d\n",removeFila(&s_fila));
    printf("\nValor removido da fila = %d\n",removeFila(&s_fila));
    insereFila(&s_fila,11);	
    insereFila(&s_fila,12);
    insereFila(&s_fila,13);	

    printaFila(&s_fila);



    
    return 1;
}

//inicializa Fila
void inicializaFila(tipo_fila *fl){
    fl->inicio = 0;
    fl->fim = 0;
    fl->qtd = 0;
}
//insere na fila
void insereFila(tipo_fila *fl,int valor){
    if(fl->fim < 10){
        fl->fila[fl->fim] = valor;
        fl->qtd++;
        fl->fim++;
    }
   else if(fl->fim == 10 && fl->inicio > 0){
       int i;
       //Movo os valores para frente
       for(i = 0; i < fl->qtd;i++){
           fl->fila[i] = fl->fila[i+fl->inicio];
       }
       fl->fim = fl->fim - fl->inicio;
       fl->inicio = 0;
       //insiro o valor no final
       fl->fila[fl->fim] = valor;
        fl->qtd++;
        fl->fim++;
    }
    else{
        printf("\n[ERRO] A fila esta cheia\n");
        
    }
   
}
//remove na fila
int removeFila(tipo_fila *fl){
    if(fl->qtd > 0){
        int aux;
        aux = fl->fila[fl->inicio];
        fl->inicio++;
        fl->qtd--;
        return aux;
    }
    else{
    	printf("\n[ERRO] A fila esta vazia\n");
    	return -1;
	}
   
}
//printa a fila
void printaFila(tipo_fila *fl){
    int i;
    printf("\nFILA: [");
    for(i = 0;i<fl->qtd;i++){
        printf("%d ",fl->fila[fl->inicio+i]);
    }
    printf("]\n");
}

