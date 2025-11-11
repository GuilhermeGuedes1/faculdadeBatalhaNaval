#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // 1 - Inicializar tudo com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Função base: checa e coloca navio só se espaço tiver livre
    int pode_colocar, k;

    // 2 - Navio 1: horizontal (3 partes)
    int linha1 = 2, col1 = 1, tam1 = 3;
    if (col1 + tam1 <= 10) { // cabe na linha
        pode_colocar = 1;
        for (k = 0; k < tam1; k++) {
            if (tabuleiro[linha1][col1 + k] != 0)
                pode_colocar = 0;
        }
        if (pode_colocar) {
            for (k = 0; k < tam1; k++) {
                tabuleiro[linha1][col1 + k] = 3;
            }
        }
    }

    // 3 - Navio 2: vertical (3 partes)
    int linha2 = 5, col2 = 7, tam2 = 3;
    if (linha2 + tam2 <= 10) { // cabe na coluna
        pode_colocar = 1;
        for (k = 0; k < tam2; k++) {
            if (tabuleiro[linha2 + k][col2] != 0)
                pode_colocar = 0;
        }
        if (pode_colocar) {
            for (k = 0; k < tam2; k++) {
                tabuleiro[linha2 + k][col2] = 3;
            }
        }
    }

    // 4️ - Navio 3: diagonal ↘️ (linha e coluna aumentam)
    int linha3 = 4, col3 = 2, tam3 = 3;
    if (linha3 + tam3 <= 10 && col3 + tam3 <= 10) {
        pode_colocar = 1;
        for (k = 0; k < tam3; k++) {
            if (tabuleiro[linha3 + k][col3 + k] != 0)
                pode_colocar = 0;
        }
        if (pode_colocar) {
            for (k = 0; k < tam3; k++) {
                tabuleiro[linha3 + k][col3 + k] = 3;
            }
        }
    }

    // 5 - Navio 4: diagonal  (linha aumenta, coluna diminui)
    int linha4 = 0, col4 = 5, tam4 = 3;
    if (linha4 + tam4 <= 10 && col4 - tam4 >= -1) {
        pode_colocar = 1;
        for (k = 0; k < tam4; k++) {
            if (tabuleiro[linha4 + k][col4 - k] != 0)
                pode_colocar = 0;
        }
        if (pode_colocar) {
            for (k = 0; k < tam4; k++) {
                tabuleiro[linha4 + k][col4 - k] = 3;
            }
        }
    }

    // 6 - Mostrar tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    printf("0 = Agua | 3 = Navio\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
