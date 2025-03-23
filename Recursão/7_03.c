#include <stdio.h>

/* Função para calcular o fatorial de n (n!) */
int fat(int n) {
    if (n == 0)
        return 1;
    else
        return n * fat(n - 1);
}

/* Função para calcular x^n */
float pot(float x, int n) {
    if (n == 0)
        return 1;  
    else
        return x * pot(x, n - 1);  
}

/* Função para calcular a somatória: 1 + x + x^2/2! + x^3/3! + ... + x^n/n! */
float somatoria(float x, int n) {
    if (n == 0)
        return 1;  
    else
        return pot(x, n) / fat(n) + somatoria(x, n - 1);  
}

int main() {
    float x, resultado;
    int n;


    printf("Digite o valor de x: ");
    scanf("%f", &x);

    
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    
    resultado = somatoria(x, n);

    
    printf("Resultado da somatoria: %.2f\n", resultado);

    return 0;
}

