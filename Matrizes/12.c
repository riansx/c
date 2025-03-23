#include <stdio.h>

void lerMatriz(int m, int n, float matriz[m][n]) {
    int i, j;
    printf("Preencha a matriz T(M,N) de preços dos terrenos:\n");
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
    
    // Leitura das dimensões da matriz T(M, N)
    printf("Digite o número de zonas (M) e metragem (N): ");
    scanf("%d %d", &m, &n);
    
    // Criação da matriz T(M, N) de preços dos terrenos
    float T[m][n];
    lerMatriz(m, n, T);

    // Leitura dos dados do comprador
    printf("Digite os dados do comprador (codigo, zona, metragem, opcao de pagamento):\n");
    scanf("%d %d %d %d", &codigoComprador, &zona, &metragem, &opcaoPagamento);
    
    // A zona e a metragem são fornecidas como índices, então precisamos ajustar as referências
    // zona e metragem devem ser indexadas a partir de 0, então subtraímos 1 para a matriz
    zona--;  // Ajuste para índice de zona
    metragem--;  // Ajuste para índice de metragem
    
    // Preço base do terreno
    precoBase = T[zona][metragem];
    
    // Preço com comissão de corretagem (6% de comissão)
    precoComComissao = precoBase * 1.06;
    
    // Processamento com base na opção de pagamento
    if (opcaoPagamento == 1) {  // Pagamento à vista
        precoFinal = precoComComissao * 0.90;  // Desconto de 10%
        printf("Codigo do comprador: %d\n", codigoComprador);
        printf("Zona: %d\n", zona + 1);  // Ajuste de zona para exibição
        printf("Metragem: %d\n", metragem + 1);  // Ajuste de metragem para exibição
        printf("Valor total a pagar: %.2f\n", precoFinal);
        
    } else if (opcaoPagamento == 2) {  // Pagamento com entrada de 30% e 3 prestações
        precoFinal = precoComComissao * 1.05;  // Acréscimo de 5%
        
        entrada = precoFinal * 0.30;  // Entrada de 30%
        parcela = (precoFinal - entrada) / 3;  // Divisão do restante em 3 parcelas
        
        printf("Codigo do comprador: %d\n", codigoComprador);
        printf("Zona: %d\n", zona + 1);  // Ajuste de zona para exibição
        printf("Metragem: %d\n", metragem + 1);  // Ajuste de metragem para exibição
        printf("Entrada: %.2f\n", entrada);
        printf("Valor de cada parcela: %.2f\n", parcela);
    } else {
        printf("Opção de pagamento inválida.\n");
    }

    return 0;
}

