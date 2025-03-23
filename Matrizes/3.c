#include <stdio.h>

int main() {
    /* Elaborar um programa que leia uma matriz M(3,3) e um valor A, 
    multiplique a matriz M pelo valor A, coloque os valores da matriz multiplicados por A em um vetor de V(9) 
    e escreva no final o vetor V. */

    int m[3][3], a, v[9], i, j;

    printf("Digite um valor para multiplicar a matriz: ");
    scanf("%d", &a);

    printf("Preencha a matriz:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &m[i][j]);
            m[i][j] *= a;  
        }
    }

    
    int k = 0;  
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            v[k] = m[i][j]; 
            k++;
        }
    }

    
    printf("Vetor V com os valores multiplicados: \n");
    for(i = 0; i < 9; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

