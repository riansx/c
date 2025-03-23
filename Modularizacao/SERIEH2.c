#include <stdio.h>
#include <math.h>

/* Fun��o para calcular o valor dos N primeiros termos da s�rie H:
   H = 1/1^3 + 1/3^3 + 1/5^3 + 1/7^3 + ... */
   
float serieH(int N) {
    float soma = 0.0;
    int i;  

    for (i = 1; i <= N; i++) {
        // O denominador � o cubo do n�mero �mpar correspondente (2i - 1)
        int denominador = pow(2 * i - 1, 3);

        // O numerador � sempre 1
        soma += 1.0 / denominador;
    }

    return soma;
}

int main() {
    int N;
    float resultado;
    
    // Solicitar o n�mero de termos ao usu�rio
    printf("Digite o numero de termos (N) da serie H: ");
    scanf("%d", &N);
    
    // Calcular o valor da s�rie H
    resultado = serieH(N);

    // Exibir o resultado
    printf("O valor da serie H para N = %d termos: %.6f\n", N, resultado);

    return 0;
}

