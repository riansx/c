#include <stdio.h>
#include <stdlib.h>

void verificarMatriz(int N, int n) {
    if (n != N) {
        printf("A matriz nao eh quadrada.\n");
        exit(1);
    }
}

float produtoAcima(int n, float matriz[n][n]){
	int i, j;
	float produtoAcima = 1;
	 for(i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
        		if (i < j){
		produtoAcima*=matriz[i][j];
				}
			}
		}
		return produtoAcima;
}

int main() {
    /* Fazer um programa que leia uma matriz NxN e calcule separadamente o produto dos elementos que
    estão acima da diagonal principal, abaixo da diagonal principal, na própria diagonal principal e
    na diagonal secundaria. 
    Mostrar o resultado dos produtos. */

    int n, N, i, j;
    
    printf("Digite quantas linhas e quantas colunas tera a matriz: ");
    scanf("%d%d", &n, &N);
    
    verificarMatriz(n, N);
    
    float matriz[n][N], produtoAcimaResultado = 1, produtoAbaixo = 1, produtoDiagonal = 1, produtoDiagonalSecundaria = 1;

    printf("Preencha a matriz:\n");
    for(i = 0; i < n; i++) {
        for (j = 0; j < N; j++) {
            scanf("%f", &matriz[i][j]);
            
            if (i > j)  
                produtoAbaixo *= matriz[i][j];
                
            if (i == j)  
                produtoDiagonal *= matriz[i][j];

            if (i + j == N - 1) // condição para a diagonal secundária
                produtoDiagonalSecundaria *= matriz[i][j];
        }
    }
    
    
    printf("\nMatriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    
    produtoAcimaResultado = produtoAcima(n, matriz);
    printf("\nProduto acima da diagonal principal: %.2f\n", produtoAcimaResultado);
    printf("Produto abaixo da diagonal principal: %.2f\n", produtoAbaixo);
    printf("Produto da diagonal principal: %.2f\n", produtoDiagonal);
    printf("Produto da diagonal secundaria: %.2f\n", produtoDiagonalSecundaria);
    
    return 0;
}

