#include <stdio.h>

// Função recursiva para o movimento da Torre (direita)
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para o movimento da Rainha (esquerda)
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Função recursiva combinada com loops aninhados para o Bispo
void moverBispo(int casas) {
    if (casas == 0) return;

    // Loop externo para o movimento vertical (cima)
    for (int v = 0; v < 1; v++) {
        // Loop interno para o movimento horizontal (direita)
        for (int h = 0; h < 1; h++) {
            printf("Cima Direita\n");
        }
    }

    moverBispo(casas - 1);
}

// Movimento do Cavalo (duas casas para cima, uma para a direita)
// Usando loops aninhados, múltiplas variáveis e controle com break/continue
void moverCavalo() {
    printf("Movimento do Cavalo:\n");

    for (int cima = 0; cima < 2; cima++) {
        if (cima == 1) {
            int direita = 0;
            while (direita < 2) {
                direita++;
                if (direita == 1) {
                    printf("Direita\n");
                    break; // Sai do loop depois de mover 1 casa à direita
                } else {
                    continue;
                }
            }
        }
        printf("Cima\n");
    }
}

int main() {
    // Constantes de movimento
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // Torre
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    // Linha em branco
    printf("\n");

    // Bispo
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo);

    // Linha em branco
    printf("\n");

    // Rainha
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);

    // Linha em branco
    printf("\n");

    // Cavalo
    moverCavalo();

    return 0;
}

  
