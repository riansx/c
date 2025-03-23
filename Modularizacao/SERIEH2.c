#include <stdio.h>
#include <math.h>

/* Função para calcular o valor dos N primeiros termos da série H:
   H = 1/1^3 + 1/3^3 + 1/5^3 + 1/7^3 + ... */
   
float serieH(int N) {
    float soma = 0.0;
    int i;  

    for (i = 1; i <= N; i++) {
        // O denominador é o cubo do número ímpar correspondente (2i - 1)
        int denominador = pow(2 * i - 1, 3);

        // O numerador é sempre 1
        soma += 1.0 / denominador;
    }

    return soma;
}

int main() {
    int N;
    float resultado;
    
    // Solicitar o número de termos ao usuário
    printf("Digite o numero de termos (N) da serie H: ");
    scanf("%d", &N);
    
    // Calcular o valor da série H
    resultado = serieH(N);

    // Exibir o resultado
    printf("O valor da serie H para N = %d termos: %.6f\n", N, resultado);

    return 0;
}

