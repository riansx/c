#include <stdio.h>

// Fun��o para ler a matriz
void lerMatriz(int n, int matriz[n][n]) {
    int i, j;
    printf("Preencha a matriz: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main () {
    int n, i, j;
    
    // Leitura do tamanho da matriz
    printf("Digite o tamanho da matriz n: ");
    scanf("%d", &n);
    
    int mat[n][n];
    
    // Leitura da matriz
    lerMatriz(n, mat);
    
    // Vari�veis para armazenar as somas das linhas, colunas e diagonais
    int somaLinha, somaColuna, somaDiagonalPrincipal = 0, somaDiagonalSecundaria = 0;
    int somaReferencia = 0;  // Soma de refer�ncia que vamos comparar
    
    // Calcular a soma da primeira linha para usar como refer�ncia
    for (j = 0; j < n; j++) {
        somaReferencia += mat[0][j];
    }
    
    // Verificar as somas das linhas
    for (i = 1; i < n; i++) {
        somaLinha = 0;
        for (j = 0; j < n; j++) {
            somaLinha += mat[i][j];
        }
        if (somaLinha != somaReferencia) {
            printf("Nao\n");
            return 0;  // Se a soma de alguma linha for diferente, j� podemos afirmar que n�o � quadrado m�gico
        }
    }

    // Verificar as somas das colunas
    for (j = 0; j < n; j++) {
        somaColuna = 0;
        for (i = 0; i < n; i++) {
            somaColuna += mat[i][j];
        }
        if (somaColuna != somaReferencia) {
            printf("Nao\n");
            return 0;  // Se a soma de alguma coluna for diferente, j� podemos afirmar que n�o � quadrado m�gico
        }
    }

    // Verificar a soma da diagonal principal
    for (i = 0; i < n; i++) {
        somaDiagonalPrincipal += mat[i][i];
    }
    if (somaDiagonalPrincipal != somaReferencia) {
        printf("Nao\n");
        return 0;
    }

    // Verificar a soma da diagonal secund�ria
    for (i = 0; i < n; i++) {
        somaDiagonalSecundaria += mat[i][n - 1 - i];
    }
    if (somaDiagonalSecundaria != somaReferencia) {
        printf("Nao\n");
        return 0;
    }

    // Se todas as verifica��es forem bem-sucedidas
    printf("Sim\n");

    return 0;
}

