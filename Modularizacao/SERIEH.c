#include <stdio.h>

/* Fun��o para calcular o valor dos primeiros N termos da s�rie H */

float serieH(int N) {
    float soma = 0.0;
    int denominador = 500;  // Inicializando o denominador com 500

    for (int i = 1; i <= N; i++) {
        int numerador;

        // Alterna entre numerador 2 e 5
        if (i % 2 == 1) {
            numerador = 2;  // Para i �mpar, numerador � 2
        } else {
            numerador = 5;  // Para i par, numerador � 5
        }

        // Adiciona o termo � soma
        soma += (float)numerador / denominador;

        // Atualiza o denominador de 50 em 50
        denominador -= 50;
    }

    return soma;
}

int main() {
    int N;
    
    
    printf("Digite o numero de termos (N) da serie H: ");
    scanf("%d", &N);

    
    float resultado = serieH(N);

    
    printf("O valor da s�rie H para N = %d termos: %.4f\n", N, resultado);

    return 0;
}

