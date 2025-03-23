#include <stdio.h>

void mostrar_tabuleiro(char tabuleiro[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("| %c ", tabuleiro[i][j]);
        }
        printf("|\n");
        if (i < 2) printf("-------------\n");
    }
    printf("\n");
}

void validar_movimento(int linha, int coluna, char tabuleiro[3][3]) {
    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
        printf("Movimento invalido! A linha e a coluna devem ser entre 1 e 3.\n");
    } else if (tabuleiro[linha - 1][coluna - 1] != ' ') {
        printf("Movimento invalido! Jogue novamente.\n");
    }
}

int verificar_vitoria(char tabuleiro[3][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1; 
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1; 
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1; 
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int verificar_empate(char tabuleiro[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; 
            }
        }
    }
    return 1; 
}

int main() {
    char tabuleiro[3][3];
    int linha, coluna, rodada, vitoria = 0, empate = 0;
    char jogador;
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    for (rodada = 1; rodada <= 9; rodada++) {
        if (rodada % 2 == 1) {
            jogador = 'X';  
        } else {
            jogador = 'O';  
        }

        do {
            printf("jogador %c, digite a linha e coluna (1 a 3) onde deseja jogar: ", jogador);
            scanf("%d %d", &linha, &coluna);

            validar_movimento(linha, coluna, tabuleiro);

        } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ');

        tabuleiro[linha - 1][coluna - 1] = jogador;

        mostrar_tabuleiro(tabuleiro);

        vitoria = verificar_vitoria(tabuleiro);
        if (vitoria) {
            printf("jogador %c venceu\n", jogador);
            break;
        }

        empate = verificar_empate(tabuleiro);
        if (empate) {
            printf("empate\n");
            break;
        }
    }

    return 0;
}

