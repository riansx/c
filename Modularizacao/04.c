#include <stdio.h>
//QUESTAO 4 distancia entre dois pontos
int distancia(int a1,int a2,int b1,int b2)
{
    int distanciap;
    
    distanciap = ((a2 -a1)*2)+((b2 - b1)*2);
    return distanciap;
}
int main()
{
    int x1, x2, y1, y2;
    
    printf("valor de x1:");
    scanf("%d", &x1);
    printf("valor de x2:");
    scanf("%d", &x2);
    printf("valor de y1:");
    scanf("%d", &y1);
    printf("valor de y2:");
    scanf("%d", &y2);
    
    printf("a distancia entre dois pontos: %d ", distancia(x1,x2,y1,y2));
    
}

