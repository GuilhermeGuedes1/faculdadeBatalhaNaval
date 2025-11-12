#include <stdio.h>

#define TAM 10
#define HAB 5

int main() {
    int tabuleiro[TAM][TAM];
    int i, j, k;

    // 1️⃣ Inicializa tudo com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2️⃣ Coloca alguns navios (valor 3)
    int pode_colocar;

    // Navio 1: horizontal
    int linha1 = 2, col1 = 1, tam1 = 3;
    if (col1 + tam1 <= TAM) {
        pode_colocar = 1;
        for (k = 0; k < tam1; k++)
            if (tabuleiro[linha1][col1 + k] != 0) pode_colocar = 0;

        if (pode_colocar)
            for (k = 0; k < tam1; k++)
                tabuleiro[linha1][col1 + k] = 3;
    }

    // Navio 2: vertical
    int linha2 = 5, col2 = 7, tam2 = 3;
    if (linha2 + tam2 <= TAM) {
        pode_colocar = 1;
        for (k = 0; k < tam2; k++)
            if (tabuleiro[linha2 + k][col2] != 0) pode_colocar = 0;

        if (pode_colocar)
            for (k = 0; k < tam2; k++)
                tabuleiro[linha2 + k][col2] = 3;
    }

    // Navio 3: diagonal ↘
    int linha3 = 4, col3 = 2, tam3 = 3;
    if (linha3 + tam3 <= TAM && col3 + tam3 <= TAM) {
        pode_colocar = 1;
        for (k = 0; k < tam3; k++)
            if (tabuleiro[linha3 + k][col3 + k] != 0) pode_colocar = 0;

        if (pode_colocar)
            for (k = 0; k < tam3; k++)
                tabuleiro[linha3 + k][col3 + k] = 3;
    }

    // Navio 4: diagonal ↙
    int linha4 = 0, col4 = 5, tam4 = 3;
    if (linha4 + tam4 <= TAM && col4 - tam4 >= -1) {
        pode_colocar = 1;
        for (k = 0; k < tam4; k++)
            if (tabuleiro[linha4 + k][col4 - k] != 0) pode_colocar = 0;

        if (pode_colocar)
            for (k = 0; k < tam4; k++)
                tabuleiro[linha4 + k][col4 - k] = 3;
    }

    // 3️⃣ Criação das matrizes de habilidades (5x5)
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // --- Cone ---
    // Forma triangular expandindo para baixo
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (j >= (HAB/2 - i) && j <= (HAB/2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // --- Cruz ---
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (i == HAB/2 || j == HAB/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // --- Octaedro (losango) ---
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (abs(i - HAB/2) + abs(j - HAB/2) <= HAB/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // 4️⃣ Definir posições das habilidades no tabuleiro
    int origemCone[2] = {1, 8};
    int origemCruz[2] = {7, 2};
    int origemOctaedro[2] = {6, 6};

    // 5️⃣ Função para sobrepor habilidades (valor 5)
    int h, v;
    int matriz[HAB][HAB];
    // Aplicar Cone
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (cone[i][j] == 1) {
                v = origemCone[0] + i - HAB/2;
                h = origemCone[1] + j - HAB/2;
                if (v >= 0 && v < TAM && h >= 0 && h < TAM)
                    tabuleiro[v][h] = 5;
            }
        }
    }

    // Aplicar Cruz
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (cruz[i][j] == 1) {
                v = origemCruz[0] + i - HAB/2;
                h = origemCruz[1] + j - HAB/2;
                if (v >= 0 && v < TAM && h >= 0 && h < TAM)
                    tabuleiro[v][h] = 5;
            }
        }
    }

    // Aplicar Octaedro
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (octaedro[i][j] == 1) {
                v = origemOctaedro[0] + i - HAB/2;
                h = origemOctaedro[1] + j - HAB/2;
                if (v >= 0 && v < TAM && h >= 0 && h < TAM)
                    tabuleiro[v][h] = 5;
            }
        }
    }

    // 6️⃣ Mostrar resultado final
    printf("\n=== TABULEIRO FINAL ===\n");
    printf("0 = Agua | 3 = Navio | 5 = Habilidade\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
