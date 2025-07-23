#include <stdio.h>

#define TAM 10
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para aplicar matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    int offset = TAM_HABILIDADE / 2;  // deslocamento para centralizar

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int lin = origem_linha + (i - offset);
                int col = origem_coluna + (j - offset);

                // Verifica se está dentro dos limites
                if (lin >= 0 && lin < TAM && col >= 0 && col < TAM) {
                    if (tabuleiro[lin][col] == AGUA) {
                        tabuleiro[lin][col] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Função para criar matriz Cone
void criarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i >= j - 2 && i >= 2 - j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz Cruz
void criarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz Octaedro (losango)
void criarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro Final (0=Água, 3=Navio, 5=Habilidade):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicialização do tabuleiro
    int tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Posicionar 2 navios horizontais/verticais
    tabuleiro[2][3] = tabuleiro[2][4] = tabuleiro[2][5] = NAVIO;
    tabuleiro[5][6] = tabuleiro[6][6] = tabuleiro[7][6] = NAVIO;

    // Posicionar 2 navios diagonais
    tabuleiro[0][0] = tabuleiro[1][1] = tabuleiro[2][2] = NAVIO;
    tabuleiro[0][9] = tabuleiro[1][8] = tabuleiro[2][7] = NAVIO;

    // Matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Pontos de origem no tabuleiro
    int origem_cone_linha = 4, origem_cone_coluna = 4;
    int origem_cruz_linha = 7, origem_cruz_coluna = 2;
    int origem_octa_linha = 6, origem_octa_coluna = 8;

    aplicarHabilidade(tabuleiro, cone, origem_cone_linha, origem_cone_coluna);
    aplicarHabilidade(tabuleiro, cruz, origem_cruz_linha, origem_cruz_coluna);
    aplicarHabilidade(tabuleiro, octaedro, origem_octa_linha, origem_octa_coluna);

    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
   
  
