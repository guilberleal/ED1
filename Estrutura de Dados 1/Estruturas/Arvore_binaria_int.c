
//CABEÇALHO DE INCLUSAO

#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA ARVORE

struct no_arvore
{
	int entrada;
	struct no_arvore *esquerda;
	struct no_arvore *direita;
};
typedef struct no_arvore tipo_arvore;

//ESTRUTURA DA LISTA

struct estruturano
{
	int valor;
	struct estruturano *prox;
};
typedef struct estruturano tipono;

//FUNCAO DE ALOCAR NO NA LISTA
tipono *alocano (int valor)
{
	tipono *novono = NULL;
	novono = (tipono*) malloc (sizeof(tipono));
	novono->valor = valor;
	novono->prox = NULL;
	return (novono);
}

//FUNCAO DE INSERIR NA LISTA
void insereinicio (tipono **lista, int valor)
{
	tipono *novono = alocano(valor);

	if(*lista == NULL)
	{
	     *lista = novono;
	}
	else
	{
	      novono->prox = *lista;
	      *lista = novono;
	}
}

//FUNCAO DE IMPRIMIR LISTA
void imprimir (tipono *lista)
{
    while (lista != NULL)
    {
        printf("[ %d ]\t",lista->valor);
        lista = lista->prox;
    }
}
//DECLARANDO FUNCOES
tipo_arvore *aloca_no (int entrada);
void insere_arvore (tipo_arvore **arvore, int entrada);
void busca (tipo_arvore *arvore, int entrada);
int qtd_valores (tipo_arvore *arvore);
int altura (tipo_arvore *arvore);
int verifica_folha (tipo_arvore *arvore, int entrada);
void retorna_folha (tipo_arvore *arvore, tipono **lista);
void impressao_por_nivel (tipo_arvore *arvore);
void imprime_nivel (tipo_arvore *arvore, int nivelAtual, int nivelAlvo);
void pre_ordem (tipo_arvore *arvore);
void pos_ordem (tipo_arvore *arvore);
void ordem (tipo_arvore *arvore);

//FUNCAO DE ALOCAR NOVOS NOS NA ARVORE
//1) Cria uma árvore binária vazi
tipo_arvore *aloca_no (int entrada)
{
	tipo_arvore *novo_no = NULL;
	novo_no = (tipo_arvore*) malloc (sizeof(tipo_arvore));
	novo_no->entrada = entrada;
	novo_no->esquerda = NULL;
	novo_no->direita = NULL;
	return novo_no;
}

//FUNCAO DE INSERCAO NA ARVORE
//2) Insere um valor na árvore binária;
void insere_arvore (tipo_arvore **arvore, int entrada)
{
	if (*arvore == NULL)
	{
		tipo_arvore *novo_no = aloca_no(entrada);
		*arvore = novo_no;
	}
	else
	{
		if ( entrada < (*arvore)->entrada )
			insere_arvore (&((*arvore)->esquerda),entrada);
		else
			insere_arvore (&((*arvore)->direita), entrada);
	}
}

//FUNCAO QUE BUSCA UM DETERMINADO NO NA ARVORE
//3) Busca por um valor na árvore binária, retornando a resposta se o valor foi encontrado
void busca (tipo_arvore *arvore, int entrada)
{
	if ( arvore != NULL )
	{
		if ( arvore->entrada == entrada)
			printf("\nVALOR ENCONTRADO\n");
		else
		{
			if (entrada < arvore->entrada )
				busca ( arvore->esquerda,entrada);
			else
				busca ( arvore->direita,entrada);
		}
	}
	else
		printf("\nVALOR NAO ENCONTRADO\n");
}
//5)Contabiliza e retorna o resultado do total de nós da árvore binária
int qtd_valores (tipo_arvore *arvore) {
	int cont;
	cont = 0;
	if (arvore == NULL) {
		return 0;
	} else {
		cont++;
		cont = cont + qtd_valores(arvore->esquerda);
		cont = cont + qtd_valores(arvore->direita);
		return cont;
	}
}


//FUNCAO QUE MEDE A ALTURA DE UMA ARVORE
//6) Verifica e retorna a altura da árvore binária
int altura (tipo_arvore *arvore)
{
	if ( arvore == NULL )
        return -1;
    else
	{
	    int h_esq,h_dir;

        h_esq = altura (arvore->esquerda) + 1;
        h_dir = altura (arvore->direita) + 1;
        if (h_esq < h_dir)
            return h_dir ;
        else
            return h_esq ;
	}
}

//FUNCAO QUE VERIFICA SE UM NO E FOLHA OU NAO

int verifica_folha (tipo_arvore *arvore, int entrada)
{
    if ( arvore != NULL )
	{
		if ( arvore->entrada == entrada)
        {
            if (arvore->esquerda == NULL && arvore->direita == NULL)
                return 0;
            else
                return 1;
        }
		else
		{
			if (entrada < arvore->entrada )
				verifica_folha ( arvore->esquerda,entrada );
			else
				verifica_folha ( arvore->direita,entrada );
		}
	}
	else
		printf("\nVALOR NAO ENCONTRADO\n");
}

//FUNCAO QUE RETORNA TODOS NOS FOLHAS EM UMA LISTA
//7) Imprime todos os nós folhas;
void retorna_folha (tipo_arvore *arvore, tipono **lista)
{
    if ( arvore != NULL )
	{
	    int aux;
        aux = verifica_folha(arvore,arvore->entrada);
        if(aux == 0)
            insereinicio(lista,arvore->entrada);
		retorna_folha(arvore->esquerda,lista);
		retorna_folha(arvore->direita,lista);
	}
}
//8) Imprime todos os valores por nível
void impressao_por_nivel (tipo_arvore *arvore) {	
	int nivel_processado, alt, qtdNivel, i;
	alt = altura(arvore);
	nivel_processado = 0;
	while (nivel_processado < alt) {
		imprime_nivel (arvore, 0, nivel_processado);
		nivel_processado++;
	}
}

void imprime_nivel (tipo_arvore *arvore, int nivelAtual, int nivelAlvo) {
	if (arvore != NULL) {
		if (nivelAtual == nivelAlvo) {
			printf("[%d]", arvore->entrada);
		} else {
			imprime_nivel (arvore->esquerda, nivelAtual+1, nivelAlvo);
			imprime_nivel (arvore->direita, nivelAtual+1, nivelAlvo);
		}
	}
}


//FUNCOES DE IMPRESSAO EM PRE-ORDEM, POS-ORDEM E ORDEM
//9) Imprime os valores presentes na árvore binária em pré-ordem
void pre_ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		printf("[ %i ]  ",arvore->entrada);
		pre_ordem (arvore->esquerda);
		pre_ordem (arvore->direita);
	}
}
//11) Imprime os valores presentes na árvore binária em pós-ordem
void pos_ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		pos_ordem (arvore->esquerda);
		pos_ordem (arvore->direita);
		printf("[ %i ]  ",arvore->entrada);
	}
}
//10) Imprime os valores presentes na árvore binária em ordem;
void ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		ordem (arvore->esquerda);
		printf("[ %i ]  ",arvore->entrada);
		ordem (arvore->direita);
	}
}

//FUNCAO PRINCIPAL

int main (int argc, char **argv)
{
    
    //1) Cria uma árvore binária vazia
	tipo_arvore *arvore = NULL;
	
	//DEFINICAO  DA LISTA
	tipono *lista = NULL;
	tipono *lista2 = NULL;

    //COLOQUEI OS NUMEROS QUE SERAO INSERIDOS NA ARVORE DENTRO DO VETOR
	int numeros [] = {50,25,75,15,30,65,80,90,100};
	int indx = 0;

	//2) Insere um valor na árvore binária;
    //LAÇO PARA ENVIAR OS NUMEROS DO VETOR PARA A ARVORE
	while ( indx != 9 )
	{
		insere_arvore (&arvore,numeros[indx]);
		indx++;
	}

    //IMPRESSAO DA ARVORE DE VARIAS FORMAS
    printf("IMPRESSOES DA ARVORE:\n\n");
	//9) Imprime os valores presentes na árvore binária em pré-ordem
	printf("PRE ORDEM:\n");
	pre_ordem (arvore);
    puts("");
	//11) Imprime os valores presentes na árvore binária em pós-ordem
	printf("\nPOS ORDEM:\n");
	pos_ordem (arvore);
    puts("");
	//10) Imprime os valores presentes na árvore binária em ordem
	printf("\nEM ORDEM:\n");
	ordem (arvore);
	puts("\n");
	//8) Imprime todos os valores por nível
	printf("\nIMPRESSAO DE TODOS OS VALORES POR NIVEL:\n");
	impressao_por_nivel (arvore);
	puts("\n");

	
	//VARIAVEIS AUXILIARES
	int altu,balan,folha;

    //7) Imprime todos os nós folhas;
    printf("IMPRESSAO DOS NOS FOLHAS:\n");
    retorna_folha(arvore,&lista);
    imprimir(lista);
    puts("\n");



    //6) Verifica e retorna a altura da árvore binária
    printf("A ARVORE TEM ALTURA DE: [ %i ]\n",altu = altura (arvore));
	
	//5) Contabiliza e retorna o resultado do total de nós da árvore binária  
    printf("\nQUANTIDADE DE NOS EM UMA ARVORE: %d\n",qtd_valores(arvore));
    
    //3) Busca por um valor na árvore binária, retornando a resposta se o valor foi encontrado
    printf("\nVERIFICA SE O VALOR ESTA NA ARVORE:");
	busca (arvore, 15);
	return 0;
}




