#include <stdio.h>

int main() {
    int i, j, M, N;

   
    printf("numero de linhas: ");
    scanf("%d", &M);
    printf("numero de colunas: ");
    scanf("%d", &N);

   
    int matriz[M][N];
    int matrizG[N][M]; 

    
    printf("Preencha a matriz:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
            matrizG[j][M - 1 - i] = matriz[i][j];
        }
    }

    
    printf("\nMatriz girada:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", matrizG[i][j]);
        }
        printf("\n");
    }

    return 0;
}

