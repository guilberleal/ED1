#include <stdio.h>
#include <stdlib.h>
struct stru_no{
	int valor;
	struct stru_no *prox;
	
};typedef struct stru_no tipo_no;

int main(){
	tipo_no *fila;
	fila = NULL;
	
	tipo_no *novo_no;
	novo_no = (tipo_no*)malloc(sizeof(tipo_no));
	novo_no->valor = 10;
	novo_no->prox = NULL;
	fila = novo_no;
	
	novo_no = (tipo_no*)malloc(sizeof(tipo_no));
	novo_no->valor = 3;
	novo_no->prox= NULL;
	fila->prox = novo_no;
	
	printf("Valor = %d\n",fila->valor);
	printf("Valor = %d\n",fila->prox->valor);
	return 1;
}
