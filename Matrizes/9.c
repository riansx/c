#include <stdio.h>

int main() {
    int i, j, N, linhaMaior = 0, colunaMaior = 0;;
    
    
    printf("Digite o valor de N: ");
    scanf("%d", &N);


    int matriz[N][N];

   
    printf("Preencha a matriz N x N:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

 
    int maior = matriz[0][0];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    
    int minimax = matriz[linhaMaior][0]; 
    for (j = 1; j < N; j++) {
        if (matriz[linhaMaior][j] < minimax) {
            minimax = matriz[linhaMaior][j];
        }
    }


    printf("maior elemento da matriz: %d\n", maior, linhaMaior, colunaMaior);
    printf("elemento minimax da matriz %d.\n", minimax);

    return 0;
}

