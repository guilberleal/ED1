#include<stdio.h>
#include<stdlib.>

int main() {
	int inst, i, j, linha, coluna, l, c, value, dimensao, **mat, casos, p;
	scanf("%d", &inst);
	for (i=0; i < inst; i++) {
		scanf("%d%d", &dimensao, &casos);
		mat = (int**) malloc(sizeof(int) * dimensao);
		for (l = 0; l < dimensao; l++) {
			mat[l] = (int*) malloc(sizeof(int) * dimensao);
		}
		for (l = 0; l < dimensao; l++) {
			for (c = 0; c < dimensao; c++) {
				mat[l][c] = 0;
			}
		}
		for (j=0; j < casos; j++) {
			scanf("%d%d%d%d", &p, &linha, &coluna, &value);
			mat[linha-1][coluna-1] += value;

		}
		for (l = 0; l < dimensao; l++){
			for (c = 0; c < dimensao; c++){
				if (mat[l][c] != 0) {
					printf("%d %d %d\n", l+1, c+1, mat[l][c]);
				}
			}
		}
		if (i < inst-1) {
			printf("\n");
		}
		for (l=0; l < dimensao; l++) {
			free(mat[l]);
		}
		free(mat);
	}

	return 0;
}
