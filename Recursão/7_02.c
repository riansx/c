#include <stdio.h>
#include <math.h>

/*  Escrever a função recursiva float pot(float x, int n), que retorna x^n. */

float pot(float x, int n){ 
    if (n == 0) 
        return 1; 
    else 
        return x * pot(x, n - 1); 
} 

int main(){ 
    float x, resultado; 
    int n; 
    
    printf("Digite o valor de x: ");
    scanf("%f", &x);
    
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    resultado = pot(x, n); 
    
    printf("Resultado de %.2f^%d = %.2f\n", x, n, resultado); 
    
    return 0; 
}

