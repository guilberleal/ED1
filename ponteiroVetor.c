#include <stdio.h>

int main(void){

	
	int vetor[3] = {1,2,3};
	int *ponteiro = vetor;
	
	int *pont = &vetor[2];
	
	printf("%i",*ponteiro);
	
	printf("\n%i",*pont);
	
	
	getchar();
	return 0;
}
