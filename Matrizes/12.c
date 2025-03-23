#include <stdio.h>

void lerMatriz(int m, int n, float matriz[m][n]) {
    int i, j;
    printf("Preencha a matriz T(M,N) de pre�os dos terrenos:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }
}

int main() {
    int m, n, codigoComprador, zona, metragem, opcaoPagamento;
    float precoBase, precoComComissao, precoFinal;
    float entrada, parcela;
    
    // Leitura das dimens�es da matriz T(M, N)
    printf("Digite o n�mero de zonas (M) e metragem (N): ");
    scanf("%d %d", &m, &n);
    
    // Cria��o da matriz T(M, N) de pre�os dos terrenos
    float T[m][n];
    lerMatriz(m, n, T);

    // Leitura dos dados do comprador
    printf("Digite os dados do comprador (codigo, zona, metragem, opcao de pagamento):\n");
    scanf("%d %d %d %d", &codigoComprador, &zona, &metragem, &opcaoPagamento);
    
    // A zona e a metragem s�o fornecidas como �ndices, ent�o precisamos ajustar as refer�ncias
    // zona e metragem devem ser indexadas a partir de 0, ent�o subtra�mos 1 para a matriz
    zona--;  // Ajuste para �ndice de zona
    metragem--;  // Ajuste para �ndice de metragem
    
    // Pre�o base do terreno
    precoBase = T[zona][metragem];
    
    // Pre�o com comiss�o de corretagem (6% de comiss�o)
    precoComComissao = precoBase * 1.06;
    
    // Processamento com base na op��o de pagamento
    if (opcaoPagamento == 1) {  // Pagamento � vista
        precoFinal = precoComComissao * 0.90;  // Desconto de 10%
        printf("Codigo do comprador: %d\n", codigoComprador);
        printf("Zona: %d\n", zona + 1);  // Ajuste de zona para exibi��o
        printf("Metragem: %d\n", metragem + 1);  // Ajuste de metragem para exibi��o
        printf("Valor total a pagar: %.2f\n", precoFinal);
        
    } else if (opcaoPagamento == 2) {  // Pagamento com entrada de 30% e 3 presta��es
        precoFinal = precoComComissao * 1.05;  // Acr�scimo de 5%
        
        entrada = precoFinal * 0.30;  // Entrada de 30%
        parcela = (precoFinal - entrada) / 3;  // Divis�o do restante em 3 parcelas
        
        printf("Codigo do comprador: %d\n", codigoComprador);
        printf("Zona: %d\n", zona + 1);  // Ajuste de zona para exibi��o
        printf("Metragem: %d\n", metragem + 1);  // Ajuste de metragem para exibi��o
        printf("Entrada: %.2f\n", entrada);
        printf("Valor de cada parcela: %.2f\n", parcela);
    } else {
        printf("Op��o de pagamento inv�lida.\n");
    }

    return 0;
}

