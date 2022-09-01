/*
    Disciplina: Estrutura de Dados I
    Professor: Ivairton M. Santos
    Alunos: Kalmon Valdão e Athur Rosa
    compilar: gcc morse.c -o morse && ./morse
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArvT {
    //LETRA
    char l;

    //ROTA
    char codMorse[10];

    //Ramos da arvore
    struct ArvT *esq;
    struct ArvT *dir;
}ArvT;

ArvT *ConstDicionario(ArvT *raiz,char codigoL[],int tam,char l,int pos);
void PreOrdem(ArvT *raiz);
void Traduz(ArvT **raiz,char codigoMor[],int pos,int tam);

int main(){
    char codigoL[10],simb,letra;
    int cont;
    ArvT *raiz;
    
    //alocamento do raizamento que num tem nada dentro
    raiz = (ArvT*) malloc(sizeof (ArvT) );
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->l = '*';
    FILE *arqv;
    arqv = fopen("dicionario.txt","r");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    
    cont = 0;
    while(fscanf(arqv,"%c", &simb) != EOF){
        if(simb == ' '){
            fscanf(arqv,"%c", &letra);
            raiz = ConstDicionario(raiz,codigoL,cont,letra,0);
            cont = 0;
        } else if (simb != '\n'){
            codigoL[cont++] =  simb;
            
        }
    }
    fclose(arqv);
    
    int op,i;
    char codigoMor[10],cod;
    do{
        puts("Digite nº da opção:\n1-Impressão em Pré Ordem\n2-Tradução\n0-Sair");
        scanf("%d", &op);
        system("clear");
        switch(op){
            case 1:
                  PreOrdem(raiz);
                break;
            case 2:
                cont = 0;
                arqv = fopen("texto.txt","r");
                if(arqv == NULL){
                    printf("Erro na abertura do arquivo.\n");
                }
                while( fscanf(arqv,"%c", &cod) != EOF){
                        
                        if((cod!=' ') && (cod!='/') && (cod!='\n') ){
                            codigoMor[cont++] = cod;
                        } else if (cod == '/'){
                            printf(" ");
                        } else if ((cod==' ') || (cod=='\n') ) {
                            Traduz(&raiz,codigoMor,0,cont);
                            cont = 0;
                        }
                        if( cod == '\n'){
                                puts(" ");
                        }
                }
                break;
            default:
                break;
        }
    }while(op != 0);
    return 0;
}

//caminha alocando nos ate a posição refente ao codigo morse
// obs: o * é usando para marcar os nos que não foram tiveram letras guardadas
ArvT *ConstDicionario(ArvT *raiz,char codigoL[],int tam,char l,int pos){
    if( raiz == NULL){
        raiz = (ArvT*) malloc(sizeof(ArvT) );
        raiz->esq = NULL;
        raiz->dir = NULL;
        raiz->l = '*';
    }
    if(pos < tam){
        if( codigoL[pos] == '.'){
            raiz->esq = ConstDicionario(raiz->esq,codigoL,tam,l,pos+1);
        } else {
            raiz->dir = ConstDicionario(raiz->dir,codigoL,tam,l,pos+1);
        }
    } else {
        if(raiz->l == '*'){
            raiz->l = l;
            codigoL[pos] = '\0';
            strcpy(raiz->codMorse,codigoL);
        } else {
                puts("Erro: dicionario.txt, duas letras contem o mesmo ponto na arvore.");
                printf("%c\n",l);
        }
    
    }
    return raiz;
}


// imprime arvore estruturada
void PreOrdem(ArvT *raiz){
    if(raiz != NULL){
        if(raiz->l != '*'){
            printf("%s %c\n",raiz->codMorse,raiz->l);
        }
        
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}    



// Função que caminha ateh o no referente a letra que deseja traduzir
void Traduz(ArvT **raiz,char codigoMor[],int pos, int tam){
    ArvT *no;
    no = *raiz;
    if ( pos < tam){
        if( codigoMor[pos] == '.'){
            Traduz(&(no)->esq,codigoMor,pos+1,tam);
        } else if ( codigoMor[pos] == '-') {
            Traduz(&(no)->dir,codigoMor,pos+1,tam);
        }
    } else {
        if(no->l != '*'){
            printf("%c",no->l);
        }
        
    }

} 
    
    
    
