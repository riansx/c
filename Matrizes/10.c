#include <stdio.h>

int main() {
    int i, j, k;
    int matriz[3][3];

    printf("Preencha a matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

   
    printf("Pontos cela\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int maiorLinha = 1, maiorColuna = 1;

            // Verificando se � o maior da linha
            for (k = 0; k < 3; k++) {
                if (matriz[i][k] > matriz[i][j]) {
                    maiorLinha = 0; // N�o � o maior da linha
                    break;
                }
            }

            // Verificando se � o maior da coluna
            for (k = 0; k < 3; k++) {
                if (matriz[k][j] > matriz[i][j]) {
                    maiorColuna = 0; // N�o � o maior da coluna
                    break;
                }
            }

            // Se for maior da linha e da coluna, � um ponto cela
            if (maiorLinha && maiorColuna) {
                printf("Valor: %d\n", matriz[i][j], i, j);
            }
        }
    }

    return 0;
}

