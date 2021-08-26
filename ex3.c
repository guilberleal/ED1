#include <stdio.h>
#include <stdlib.h>
#define TAM 10


struct tipofila{
    int fila[TAM];
    int qtd;
};typedef struct tipofila tipo_fila;

//prototipos
void inicializaFila(tipo_fila *fl);
void insereFila(tipo_fila *fl,int valor);
int removeFila(tipo_fila *fl);
int removeFila(tipo_fila *fl);

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
   	printf("Valor removido da fila = %d\n",removeFila(&s_fila));
   	 insereFila(&s_fila,9);

    printaFila(&s_fila);

    return 0;
}

//inicializa fila
void inicializaFila(tipo_fila *fl){
    fl->fila[0] = 2;
    fl->fila[1] = 2;
    fl->qtd = 0;
}

//insere na fila
void insereFila(tipo_fila *fl,int valor){
    if(fl->qtd < TAM - 2){ //insere no final da fila se o ponteiro nao apontar no final
            fl->fila[fl->fila[1]] = valor;
            fl->fila[1]++;
            fl->qtd++;
    }
   else if(fl->fila[1] >= TAM - 2  && fl->qtd < TAM - 2){ //se o fim aponta pro TAM, e o inicio nao é igual a 2
            fl->fila[1] = 2;

            fl->fila[fl->fila[1]] = valor;
            fl->fila[1]++;

            //atualiza flag pra 1 por que o fim foi pro inicio
            fl->qtd++;
        }
    
    else{
        printf("\n[ERRO] A fila esta cheia\n");
    }
}

//remove na fila
int removeFila(tipo_fila *fl){ //remocao acontece sempre no inicio e atualiza o ponteiro inicio
    
    if(fl->qtd > 0){
        int aux;
        aux = fl->fila[fl->fila[0]];
        fl->qtd--;
        fl->fila[0]++;
        return aux;
    }
    else {
        printf("\n[ERRO] A fila esta vazia\n");
    }
   
}

//printa a fila
void printaFila(tipo_fila *fl){
    int i;
    printf("FILA: [");
    for(i = 0;i<fl->qtd;i++){
        printf("%d",fl->fila[fl->fila[0]+i]);
    }
    printf("]\n");
}
