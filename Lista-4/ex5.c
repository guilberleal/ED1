#include <stdio.h>
#include <stdlib.h>
#define TAM 100

struct tipolista{
    int fila[TAM];
    int qtd;
};typedef struct tipolista tipo_lista;

//prototipos
void inicializaLista(tipo_lista *fl);
void insereLista(tipo_lista *fl,int valor);
void printaLista(tipo_lista *fl);
tipo_lista concatenaLista(tipo_lista *fla, tipo_lista *flb);

//funcao main
int main(){
    tipo_lista listaA,listaB;
	tipo_lista listaC;
    inicializaLista(&listaA);
    inicializaLista(&listaB);
    inicializaLista(&listaC);

    //insere todos os valores na fila A
    insereLista(&listaA,2);
    insereLista(&listaA,6);
    insereLista(&listaA,10);
    insereLista(&listaA,21);
    insereLista(&listaA,25);
    insereLista(&listaA,30);
    insereLista(&listaA,40);
    insereLista(&listaA,50);
    printf("FILA A");
    printaLista(&listaA);
    //insere todos os valores na fila B
    insereLista(&listaB,3);
    insereLista(&listaB,5);
    insereLista(&listaB,8);
    insereLista(&listaB,10);
    insereLista(&listaB,11);
    insereLista(&listaB,15);
    insereLista(&listaB,17);
    insereLista(&listaB,20);
    printf("Fila B");
    printaLista(&listaB);
    //concatena e mostra a Fila C
    listaC = concatenaLista(&listaA, &listaB);
   	printf("Fila C");
    printaLista(&listaC);
    return 0;
}

//inicializa fila
void inicializaLista(tipo_lista *fl){
    fl->qtd = 0;
}
//insere na fila
void insereLista(tipo_lista *fl,int valor){
	if(fl->qtd < TAM){
		fl->fila[fl->qtd] = valor;
		fl->qtd++;
	}
	else{
		printf("\nA fila esta cheia\n");
	}
		
}

//funcao que printa fila
void printaLista(tipo_lista *fl){
    int i;
    printf(": [");
    for(i = 0;i<fl->qtd;i++){
        printf(" %d,",fl->fila[i]);
    }
    printf("]\n");
}

//funcao concatena fila
tipo_lista concatenaLista(tipo_lista *fla, tipo_lista *flb){
    tipo_lista aux;
    aux.qtd = fla->qtd + flb->qtd;
    int i,j,k;
    i = fla->qtd - 1;
    j = flb->qtd - 1;
    k = 0;
    while(i >= 0 && j >= 0){
    	if(fla->fila[i] > flb->fila[i]){
    		aux.fila[k] = fla->fila[i];
			i--;
		}
		else{
			aux.fila[k] = flb->fila[j];
			j--;
		}
		k++;
	}
	if(i < 0){

		while(j >= 0){
			aux.fila[k] = flb->fila[j];
			j--;
			k++;
		}
	}
	else{
		while(i >= 0){
			aux.fila[k] = fla->fila[i];
			i--;
			k++;
		
		}	
	}
	return aux;
}
