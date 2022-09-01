#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//struct Pilha encadeada
struct s_pilha{
    float valor;
    struct s_pilha *prox;
};typedef struct s_pilha tipo_pilha;


//prototipos
tipo_pilha *alocaNovaPilha();
tipo_pilha *empilha(tipo_pilha *pl,float vl);
tipo_pilha *desempilha(tipo_pilha **pl);
void imprime(tipo_pilha *pl);
float resolverExpressao(char x[]);
float operacao(float a,float b,char x);


//Funcao main
int main(){
    tipo_pilha *pilha;
    pilha = NULL;

    char exp[50] =  {"5 3 2 + * 4 / 6 & "};

    printf("Resultado de %s:\t",exp);
    printf("%f\n",resolverExpressao(exp));

    

   
    return 0;
}
//aloca novo no na pilha
tipo_pilha *alocaNovaPilha(){
    tipo_pilha *novo_no;
    novo_no = (tipo_pilha*)malloc(sizeof(tipo_pilha));
    novo_no->prox = NULL;
    novo_no->valor = 0;
    return novo_no;
}

//Funcao insere na pilha
tipo_pilha *empilha(tipo_pilha *pl,float vl){
    tipo_pilha *novo_no;
    novo_no = alocaNovaPilha();
    novo_no->valor = vl;
    novo_no->prox = pl;
    return novo_no;

}
//funcao que desempilha
tipo_pilha *desempilha(tipo_pilha **pl){
    tipo_pilha *aux;
    aux = *pl;
    if(aux != NULL){
        *pl = aux->prox;
    }
    else{
        printf("\n[ERRO] Expressao invalida\n");
    }
    return aux;
}
//Funcao que imprime
void imprime(tipo_pilha *pl){
    if(pl != NULL){
        printf("TOPO -> [ ");
        while(pl != NULL){
            printf("[%d]",pl->valor);
            pl = pl->prox;
        }
        printf("]");
    }
    else{
        printf("\n[ERRO] Expressao invalida\n");
    }
}

//funcao que resolve a expressao
float resolverExpressao(char x[]){
    tipo_pilha *n1,*n2,*pilha = NULL;
    float num;

    char *pt = strtok(x," ");
    while(pt){
        if( pt[0] == '+' || pt[0] == '-'|| pt[0] == '/' || pt[0] == '*'){
           n2 = desempilha(&pilha);
           n1 = desempilha(&pilha);
           num = operacao(n1->valor,n2->valor,pt[0]);
           pilha = empilha(pilha,num);
           free(n1);
           free(n2);
        }
        else if(isdigit(pt[0]) != 0){
            num = strtol(pt,NULL,10);
            pilha = empilha(pilha,num);
        }
        else{
            printf("\n[ERRO] Expressao invalida\n");
        }
        pt = strtok(NULL," ");
    }
    n1 = desempilha(&pilha);
    
    if(n1->prox == NULL){
        num = n1->valor;
        free(n1);
        return num;
    }
    else{
        printf("\n[ERRO] Expressao invalida!\n");
    }
}

//Operacao
float operacao(float a,float b,char x){
    switch (x)
    {
    case '+':
        return a + b;
        break;
    
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    }
}

