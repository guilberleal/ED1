#include<stdio.h>
#include<stdlib.h>
struct t_pilha{
	char *pilha;
	int topo;
	
};typedef struct t_pilha tipo_pilha;

void desempilha (tipo_pilha*);
void empilha (tipo_pilha*, char);
int pilha_vazia (tipo_pilha*);

int main() {
	int i, digitos, tira_digito, pos;
	int retirados = 0;
	char *string;
	tipo_pilha pilha;
	while (1) {
		pilha.topo = 0;
		scanf("%d %d", &digitos, &tira_digito);
		if (digitos == 0) {
			break;
		}
		pilha.pilha = (char*) malloc (sizeof(char)*(digitos+1));
		string = (char*) malloc (sizeof(char)*(digitos+1));
		scanf("%s", string);
		empilha (&pilha, string[0]);
		pos = 1;
		retirados = 0;
		
		while (pos < digitos) {
			if (retirados == tira_digito) {
				for (i = pos; i < digitos; i++) {
					empilha(&pilha, string[i]);
				}
				break;
			}
					
			if (pilha_vazia(&pilha)) {
				empilha (&pilha, string[pos]);
				pos++;
				
			} else { 
				if (pilha.pilha[pilha.topo-1] < string[pos]) {
					desempilha (&pilha);
					retirados++;
					
				} else { 
					empilha ( &pilha, string[pos]);
					pos++;
				}
			}
		}
		if (retirados < tira_digito) {
			for (i = 0; i < (tira_digito - retirados); i++) {
				desempilha(&pilha);
			}
		}
		for (i = 0; i < pilha.topo; i++) {
			printf("%c", pilha.pilha[i]);
		}
		printf("\n");
		free(pilha.pilha);
		free(string);
	}
	return 0;
}

void desempilha (tipo_pilha *pl) {
	pl->topo -= 1;
}

void empilha ( tipo_pilha *pl, char num) {
	pl->pilha[pl->topo++] = num;
}

int pilha_vazia (tipo_pilha *pl) {
	if (pl->topo == 0){
		return 1;
	} else {
		return 0;
	}
}
