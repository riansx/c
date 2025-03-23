#include <stdio.h>

int main() {
    int i, j;
    float matriz[5][5];

    printf("Preencha a matriz:\n");
    for(i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }
    

    printf("\nMatriz original:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    
    for (i = 0; i < 5; i++) {
        // trocando linha 2 com a linha 4
        if (i == 1) {
            for (j = 0; j < 5; j++) {
                float temp = matriz[1][j];
                matriz[1][j] = matriz[3][j];
                matriz[3][j] = temp;
            }
        }

        //tricando coluna 4 com a coluna 5
        if (i < 5) {
            float temp = matriz[i][3];
            matriz[i][3] = matriz[i][4];
            matriz[i][4] = temp;
        }

        // trocando diagonal principal com a diagonal secundária
        {
            float temp = matriz[i][i];
            matriz[i][i] = matriz[i][5-i-1];
            matriz[i][5-i-1] = temp;
        }

        // trocando linha 3 com a coluna 1
        if (i == 2) {
            for (j = 0; j < 5; j++) {
                float temp = matriz[2][j];
                matriz[2][j] = matriz[j][0];
                matriz[j][0] = temp;
            }
        }
    }

    // mostrando matriz modificada
    printf("\nModificada:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

