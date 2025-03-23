#include <stdio.h>

int main() {
    int i, j, A, iguaisA = 0, k = 0;

    
    int V[4][4];
    int X[16]; 


    printf("Digite o valor de A: ");
    scanf("%d", &A);

  
    printf("Preencha a matriz:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &V[i][j]);
        }
    }

    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (V[i][j] == A) {
                iguaisA++;
            } else {
                X[k] = V[i][j];
                k++;
            }
        }
    }

    
    printf("\nValores iguais a %d: %d\n", A, iguaisA);

    
    printf("Diferentes de %d:\n", A);
    for (i = 0; i < k; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

    return 0;
}

