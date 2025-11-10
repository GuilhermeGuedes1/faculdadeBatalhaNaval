#include <stdio.h> //

int main() {
    // Declaracao do tabuleiro: uma matriz 10x10
    int tabuleiro[10][10];

    // Variaveis para os loops
    int i, j;

    // 1. Inicializar o tabuleiro com agua (0)

    for (i = 0; i < 10; i++) {
   
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionar os Navios
    // 

    // Navio 1: Horizontal
    // Comeca na linha 2, coluna 1. Ocupara (2,1), (2,2), (2,3).
    int linha_navio1 = 2;
    int coluna_navio1 = 1;

    // Loop para colocar as 3 partes do navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[linha_navio1][coluna_navio1 + i] = 3; 
    }

    // Navio 2: Vertical
    // Comeca na linha 5, coluna 7. Ocupara (5,7), (6,7), (7,7).
    int linha_navio2 = 5;
    int coluna_navio2 = 7;

    // Loop para colocar as 3 partes do navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[linha_navio2 + i][coluna_navio2] = 3; 
    }

    // 3. Exibir o Tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    printf("0 = Agua, 3 = Navio\n\n");

    // Loops aninhados para imprimir a matriz
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n"); 
    }

    return 0; 
}
