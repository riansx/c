#include <stdio.h>

void mostrar_tabuleiro(char tabuleiro[3][3]) {
    // Exibe o tabuleiro no formato 3x3
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
    // Valida o movimento, garantindo que a posição esteja entre 1 e 3 e que o espaço esteja vazio
    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
        printf("Movimento inválido! A linha e a coluna devem ser entre 1 e 3.\n");
    } else if (tabuleiro[linha - 1][coluna - 1] != ' ') {
        printf("Movimento inválido! Esse espaço já está ocupado.\n");
    }
}

int verificar_vitoria(char tabuleiro[3][3]) {
    // Verifica se algum jogador venceu
    int i;
    // Verifica linhas e colunas
    for (i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1; // Vitória nas linhas
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1; // Vitória nas colunas
        }
    }
    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1; // Vitória na diagonal principal
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1; // Vitória na diagonal secundária
    }
    return 0; // Nenhuma vitória
}

int verificar_empate(char tabuleiro[3][3]) {
    // Verifica se o jogo é um empate (todas as células estão preenchidas)
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; // Ainda há espaços vazios, portanto não é empate
            }
        }
    }
    return 1; // Não há mais espaços vazios, é um empate
}

int main() {
    char tabuleiro[3][3];
    int linha, coluna, rodada, vitoria = 0, empate = 0;
    char jogador;
    int i, j;

    // Inicializa o tabuleiro
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    // Loop do jogo
    for (rodada = 1; rodada <= 9; rodada++) {
        if (rodada % 2 == 1) {
            jogador = 'X';  // Jogador X
        } else {
            jogador = 'O';  // Jogador O
        }

        do {
            printf("Jogador %c, digite a linha e coluna (1 a 3) onde deseja jogar: ", jogador);
            scanf("%d %d", &linha, &coluna);

            // Valida o movimento
            validar_movimento(linha, coluna, tabuleiro);

        } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ');

        // Atualiza o tabuleiro com o movimento
        tabuleiro[linha - 1][coluna - 1] = jogador;

        // Mostra o tabuleiro
        mostrar_tabuleiro(tabuleiro);

        // Verifica a vitória após cada jogada
        vitoria = verificar_vitoria(tabuleiro);
        if (vitoria) {
            printf("Jogador %c venceu!\n", jogador);
            break;
        }

        // Verifica o empate
        empate = verificar_empate(tabuleiro);
        if (empate) {
            printf("O jogo empatou!\n");
            break;
        }
    }

    return 0;
}

