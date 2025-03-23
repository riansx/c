#include <stdio.h>

int main() {
    int i, j;
    int matriz[6][6];

    // Preenchendo a matriz com base na distância das bordas
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            // Calcular a distância até a borda mais próxima
            int lado;
            
            // Calcular a distância até a borda superior ou esquerda
            if (i < j) {
                lado = i;
            } else {
                lado = j;
            }

            // Calcular a distância até a borda inferior ou direita
            if ((5 - i) < lado) {
                lado = 5 - i;
            }
            if ((5 - j) < lado) {
                lado = 5 - j;
            }

            // O valor de cada célula é a distância até a borda + 1
            matriz[i][j] = lado + 1;
        }
    }

    // Mostrar a matriz gerada
    printf("Matriz gerada:\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

