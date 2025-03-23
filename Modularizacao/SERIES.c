#include <stdio.h>
#include <math.h>

/* Função para calcular o valor da soma dos primeiros N termos da série S:
   S = 1 + 2/4 + 3/9 + 4/16 + 5/25 + ... */

float serieS(int N) {
    float soma = 0.0;
    int i;  

    for (i = 1; i <= N; i++) {
        // Cada termo é i / i^2 (equivalente a 1 / i)
        soma += (float)i / (i * i);  // O denominador é i^2
    }

    return soma;
}

int main() {
    int N;
    float resultado;
    
    
    printf("Digite o numero de termos (N) da serie S: ");
    scanf("%d", &N);
    
    
    resultado = serieS(N);

    
    printf("O valor da soma da serie S para N = %d termos eh: %.6f\n", N, resultado);

    return 0;
}

