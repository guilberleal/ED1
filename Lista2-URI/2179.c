#include<stdio.h>
#include<stdlib.h>

int main () {
	int N, i, j, F, C, contPassos = 1, contPara = 1;
	int qntdPassos = 1;
	int **matriz, nQuad;
	scanf("%d %d %d", &N, &F, &C);
	matriz = (int*) malloc (N * sizeof (int));
			for (i=0; i<N; i++) {
					matriz[i] = (int*) malloc ( N * sizeof(int) );
			}	
		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
				matriz[i][j] = contPassos;
				contPassos++;
			}
		}
		printf("%d", matriz[F][C]);
		contPassos = 1;
		nQuad = N*N;
		while (contPara < nQuad) {
			//Deslocamento a direita
			for (i=1; i <= qntdPassos && contPara < nQuad; i++) {
				C++;
				contPassos++;
				if (C < N && F < N && C >=0 && F >= 0) {
					printf(" %d", matriz[F][C]);
					contPara++;
				}
			}
			//Deslocamento para baixo
			for (i=0; i<qntdPassos && contPara < nQuad; i++) {
				F++;
				contPassos++;
				if (F < N && C < N && F >=0 && C >= 0) {
					printf(" %d", matriz[F][C]);
					contPara++;
				}
			}
			//Deslocamento para esquerda
			qntdPassos++;
			for (i=0; i<qntdPassos && contPara < nQuad; i++) {
				C--;
				contPassos++;
				if (C < N && F < N && C >=0 && F >= 0) {
					printf(" %d", matriz[F][C]);
					contPara++;
				}
			}
			//Deslocamento para cima
			for (i=0; i<qntdPassos && contPara < nQuad; i++) {
				F--;
				contPassos++;
				if (F < N && C < N && F >=0 && C >= 0) {
					printf(" %d", matriz[F][C]);
					contPara++;
				}
			}
			qntdPassos++;
		}
		printf("\n%d\n", contPassos);
		
	return 0;
}
