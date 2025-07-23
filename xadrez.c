#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro 10x10 com água
    int tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ------------------------------
    // Coordenadas dos 4 navios (linha, coluna)
    // Navio 1 - horizontal
    int linhaH = 2, colunaH = 1;

    // Navio 2 - vertical
    int linhaV = 5, colunaV = 4;

    // Navio 3 - diagonal principal (↘)
    int linhaD1 = 0, colunaD1 = 0;

    // Navio 4 - diagonal secundária (↙)
    int linhaD2 = 0, colunaD2 = 9;

    int sobreposicao = 0;

    // ------------------------------
    // Validação e posicionamento do navio horizontal
    if (colunaH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] == NAVIO) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    } else {
        printf("Navio horizontal fora dos limites.\n");
        return 1;
    }

    // ------------------------------
    // Validação e posicionamento do navio vertical
    if (!sobreposicao && linhaV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    } else {
        printf("Navio vertical fora dos limites.\n");
        return 1;
    }

    // ------------------------------
    // Validação e posicionamento do navio diagonal principal (↘)
    if (!sobreposicao && linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == NAVIO) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    } else {
        printf("Navio diagonal ↘ fora dos limites.\n");
        return 1;
    }

    // ------------------------------
    // Validação e posicionamento do navio diagonal secundária (↙)
    if (!sobreposicao && linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == NAVIO) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    } else {
        printf("Navio diagonal ↙ fora dos limites.\n");
        return 1;
    }

    // ------------------------------
    // Exibição do tabuleiro
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
   
  
