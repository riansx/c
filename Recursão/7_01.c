 #include <stdio.h>

/*  Escrever a função recursiva int soma(int n), que retorna a soma dos n primeiros 
inteiros ímpares. */

int soma(int n){ 
	if (n == 1) 
		return 1; 
	else 
		return (2*n-1) + soma(n-1); 
} 
int main(){ 
	int n,s; 
		
	printf("n = "); 
	scanf("%d",&n); 
	s = soma(n); printf("Soma = %d\n",s);     


	return 0; 
} 
