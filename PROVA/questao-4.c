
#include <stdio.h>
#include <stdlib.h>

//DEFINICAO DE UMA CONSTANTE PARA DETERMINAR O TAMANHO DO VETOR
#define n 3

//ESTRUTURA DA ARVORE
struct arvore_mult
{
	int entrada [n];
	int cont;
	struct arvore_mult *filho [n+1];
};
typedef struct arvore_mult tipo_arvore;

//prototipo
void imprimeTotal (tipo_arvore *arvore);
tipo_arvore *aloca_no (int entrada);

int main(){
	 //DEFINICAO DA ARVORE
	tipo_arvore *arvore = NULL;
        //VETOR DE TESTES
	arvore->entrada[0] = 5;
	arvore->entrada[1] = 10;
	arvore->entrada[3] = 15;
	
    imprimeTotal(arvore);
        
	
	
}

//ALOCACAO DE NOVO NO DE ARVORE
tipo_arvore *aloca_no (int entrada)
{
	tipo_arvore *novo_no = NULL;
	novo_no = (tipo_arvore*) malloc (sizeof(tipo_arvore));
	int i;
        
	novo_no->entrada [0] = entrada;
        
	for ( i = 0; i < n+1; i++)
		novo_no->filho[i] = NULL;
        
	novo_no->cont = 1;

	return novo_no;
}

void imprimeTotal (tipo_arvore *arvore){
	int	total;
        if ( arvore != NULL )
        {
                int i;
                for ( i = 0; i < (arvore)->cont+1 ; i++)
                        imprimeTotal (arvore->filho[i]);
                        
                for ( i = 0; i < (arvore)->cont; i++){
						total = total + arvore->entrada[i];
                        printf ("[ %i ]\t", arvore->entrada[i]);
				}
			printf("TOTAL: %d",total);
					
        }
}


