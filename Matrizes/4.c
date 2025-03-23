#include <stdio.h>

int main() {
    int m[5][5], sl[5] = {0}, sc[5] = {0}, i, j, vet = 0;; 


    
    printf("Preencha a matriz 5x5: \n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            sl[i] += m[i][j]; 
            sc[j] += m[i][j]; 
        }
    }

 
    printf("Matriz:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 5; i++) {
        printf("\nSoma da linha %d = %d ", i+1, sl[i]);
    }
		printf("\n");
    for (i = 0; i < 5; i++) {
        printf("\nSoma coluna %d = %d ", i+1, sc[i]);
    }
    

    return 0;
}

