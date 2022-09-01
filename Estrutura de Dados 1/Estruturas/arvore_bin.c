/**
 * ARVORE BINARIA
 * AUTOR: ALEX MATOS IUASSE
 * UMA ESTRUTURA DE DADOS DEFINIDA COMO ARVORE É UMA ESTRUTURA HIERARQUICA,
 * DIFERENTE DAS ESTRUTURAS LINEARES(LISTAS) QUE SÃO DE ACESSO SEQUENCIAL.
 * UMA ÁRVORE POSSUI OS SEGUINTES COMPONENTES:
 * 
 * NÓS: É CADA VERITICE DA ARVORE.
 * 
 * RAIZ: É O PRIMEIRO NO DA ARVORE, É APARTIR DELE QUE OS DEMAIS NÓS SÃO
ACESSADOS.
 * 
 * FILHOS: SÃO OS NÓS HIERAQUICAMENTE INFERIORES AO NÓ DE REFERENCIA. UM NÓ PODE
 * POSSUIR "NENHUM" OU TANTOS FILHOS QUANTO A ORDEM DA ARVORE.
 * 
 * PAI: É O NÓ HIERARQUICAMENTE SUPERIOR AO NÓ DE REFERENCIA. UM NO SEMPRE
POSSUI
 * UM "PAI", EXCETO O NÓ RAIZ.
 * 
 * FOLHAS: SÃO OS NÓS DE NÍVEL MAIS INFERIOR. UM NÓ FOLHA É CARACTIZADO POR NÃO
 * POSSUIR UM NÓ FILHO.
 * 
 *			(X)				[RAIZ]
 *		        /      \
 *		(Y)		(Z)			[NÓ]
 *	      /		         /     \			
 *	(K)		   (M)	        (L)	[FILHO NOZ]
 *				\			
 *				(N)			
 *				/			
 *			    (P)			[NÓ FOLHA]
 *			   
 * ORDEM: A ORDEM DE UMA ARVORE E DETERMINADA PELA CAPACIDADE QUE UM DETERMINADO
 * NO TEM DE POSSUIR FILHOS, POR EXEMPLO, UMA ARVORE ONDE OS NOS ARMAZENAM NO
 * MAXIMO 2 FILHOS, TEM ORDEM IGUAL A 2. TAMBEM E DITA BINARIA.
 * 
 * GRAU: E UM ASPECT DO NO, O GRAU DE UM NO E DADO PELO NUMERO DE FILHOS QUE ELE
 * POSSUI. POR EXEMPLO UM NO FOLHA TEM GRAU 0.
 * 
 * PROFUNDIDADE: A PROFUNDIDA DE UM NO E A DISTANCIA DO NO A RAIZ.
 * 
 * NIVEL: E O CONJUNTO DE NOS DE UMA MESMA PROFUNDIDADE.
 * 
 * ALTURA: E A MAIOR PROFUNDIDADE PRESENTE NA ARVORE.
 * 
 * COMPLETUDE: UMA ARVORE E DITA SER "COMPLETA" QUANDO TODOS OS NOS POSSUEM GRAU
 * ZERO OU "MAXIMO". POR EXEMPLO EM UMA ARVORE BINARIA, ELA E COMPLETA SE TODOS
OS
 * NOS TEM GRAU 0 OU 2.
 * 
 * BALANCEAMENTO: UMA ARVORE E DITA BALANCEADA QUANDO TODOS OS NOS DOS PRIMEIROS
 * NIVEIS ESTAO COMPLETO.
 * 
 * EX: ARVORE ORDEM 2, TODOS NOS TEM GRAU 2 EXCETO AS FOLHAS
 * 
 * UMA ARVORE BINARIA E UMA ESPECIALIZACAO DE UM GRAFO. E UM ACICLICO, CONEXO,
 * DIRIGIDO E QUE CADA NO NAO TEM GRAU MENOR QUE 2. ASSIM, SO EXISTE 1 CAMINHO
 * ENTRE DOIS NOS QUAISQUER NA ARVORE.
 * 
 * CADA RAMO DA ARVORE E UM VERTICE DIRIGIDO, SEM PESO, QUE PARTE DO PAI PARA O
 * FILHO.
 * 
 * INSERCAO EM ARVORE BINARIA:
 * 
 *	EM UMA ARVORE BINARIA OS NOS FILHOS DEVEM SEMPRE ATENDER AO PRINCIPIO
 * DA HIERARQUIA, DE MODO QUE O FILHO ESQUERDO SEMPRE TERA VALOR INFERIOR AO
PAI,
 * ENQUANTO QUE O FILHO DIREITO SEMPRE TERA VALOR MAIOR QUE O PAI.
 *	
 *	CONSIDERE A ARVORE BINARIA RESULTANTE DA SEGUINTE SEQUENCIA DE
 * INSERCAO: {50,25,75,15,30,65,80,90,100}
 * 
 *				50			
 *							
 *			25		75
 *							
 *		    15	      30     65       80
 *		    
 *						 90
 *			
 *							100
 *							
 * IMPLEMENTAR:
 * 1- BUSCAR UM ELEMENTO(VALOR);
 * 2- RETORNAR SE UM NO ESPECIFICO E FOLHA OU NAO;
 * 3- RETORNAR A PROFUNDIDE DE UM NO ESPECIFICO;
 * 4- RETORNAR TODOS OS VALORES DOS NOS EM UM DETERMINADO NIVEL;
 * 5- RETORNAR A ALTURA DA ARVORE;
 * 6- RETORNAR SE A ARVORE E COMPLETA OU NAO;
 * 7- RETORNAR TODOS OS VALORES DOS NOS FOLHA;
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct no_arvore 
{
	void *entrada;
	struct no_arvore *esquerda;
	struct no_arvore *direita;
};
typedef struct no_arvore tipo_arvore;

tipo_arvore *aloca_no (void *entrada)
{
	tipo_arvore *novo_no = NULL;
	novo_no = (tipo_arvore*) malloc (sizeof(tipo_arvore));
	novo_no->entrada = entrada;
	novo_no->esquerda = NULL;
	novo_no->direita = NULL;
	return novo_no;
}

int insere_arvore (tipo_arvore **arvore, void *entrada)
{
	if (*arvore == NULL)
	{
		tipo_arvore *novo_no = aloca_no(entrada);
		*arvore = novo_no;	
	}
	else
	{
		if ( *((int*)entrada) < *((int*)(*arvore)->entrada) )
			insere_arvore (&((*arvore)->esquerda),entrada);
		else
			insere_arvore (&((*arvore)->direita), entrada);
	}
}

void pre_ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		int *i;
		i = (int*) arvore->entrada;
		printf("\t%i",*i);
		pre_ordem (arvore->esquerda);
		pre_ordem (arvore->direita);
	}
}
void pos_ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		int *i;
		i = (int*) arvore->entrada;
		pos_ordem (arvore->esquerda);
		pos_ordem (arvore->direita);
		printf("\t%i",*i);
	}
}
void ordem (tipo_arvore *arvore)
{
	if (arvore != NULL)
	{
		int *i;
		i = (int*) arvore->entrada;
		ordem (arvore->esquerda);
		printf("\t%i",*i);
		ordem (arvore->direita);
	}
}

int main (int argc, char **argv)
{
	tipo_arvore *arvore = NULL;
	int *i;
	
	i=(int*) malloc(sizeof(int));
	*i = 50;
	insere_arvore (&arvore,i);
	i=(int*) malloc(sizeof(int));
	*i = 25;
	insere_arvore (&arvore,i);
	i=(int*) malloc(sizeof(int));
	*i = 75;
	insere_arvore (&arvore,i);
	i=(int*) malloc(sizeof(int));
	*i = 15;
	insere_arvore (&arvore,i);
	i=(int*) malloc(sizeof(int));
	*i = 30;
	insere_arvore (&arvore,i);
	i=(int*) malloc(sizeof(int));
	*i = 65;
	insere_arvore (&arvore,i);
	i=(int*) malloc(sizeof(int));
	*i = 80;
	insere_arvore (&arvore,i);
	i=(int*) malloc(sizeof(int));
	*i = 90;
	insere_arvore (&arvore,i);
	i=(int*) malloc(sizeof(int));
	*i = 100;
	insere_arvore (&arvore,i);
	
	printf("PRE ORDEM: \t");
	pre_ordem (arvore);
	
	printf("\nPOS ORDEM: \t");
	pos_ordem (arvore);
	
	printf("\nORDEM: \t\t");
	ordem (arvore);
	
	puts("");
	
	return 0;
}




