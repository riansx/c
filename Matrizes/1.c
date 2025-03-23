#include <stdio.h>
#include <stdlib.h>

void verificarMatriz (int N, int n){
	if (n != N){
			printf ("A matriz nao eh quadrada.");
		exit(1);
	}
}

int main(){
	
	/* Faça um programa que encontre e mostre o maior elemento de uma matriz NxN de reais, a seguir,
multiplique cada elemento da diagonal principal pelo maior valor. */
	
	int n, N, i, j;
	
	
	printf ("Digite quantas linhas e quantas colunas tera a matriz: ");
	scanf ("%d%d", &n, &N);
	
	verificarMatriz(n, N);
	
	float matriz[n][N], maior = 0;	
	
	
	printf ("Preencha a matriz:\n");
	for(i = 0; i < n; i++){
		for (j = 0; j < N; j++){
			scanf ("%f", &matriz[i][j]);
			if (matriz[i][j] > maior)
				maior = matriz[i][j];
		
		}
	}
	
	printf ("\nMaior valor da matriz: %.2f", maior);
	
	
	printf ("\nMatriz com a diagonal principal multiplicada: \n");
	for (i = 0; i < n; i++){
		for (j = 0; j < N; j++){
				if (i == j)
				matriz[i][j] *= maior;
			printf ("%.2f ", matriz[i][j]);
		}
		printf ("\n");
	}
	
	
	
	
	return 0;
}
