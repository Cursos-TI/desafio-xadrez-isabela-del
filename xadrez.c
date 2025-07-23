

   #include <stdio.h>

int main() {
    // Movimento da Torre: 5 casas para a direita (usando for)
    printf("Movimento da Torre:\n");
    for(int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    // Movimento do Bispo: 5 casas na diagonal para cima e à direita (usando while)
    printf("\nMovimento do Bispo:\n");
    int j = 1;
    while(j <= 5) {
        printf("Cima Direita\n");
        j++;
    }

    // Movimento da Rainha: 8 casas para a esquerda (usando do-while)
    printf("\nMovimento da Rainha:\n");
    int k = 1;
    do {
        printf("Esquerda\n");
        k++;
    } while(k <= 8);

    // Movimento do Cavalo: duas casas para baixo e uma para a esquerda
    // Utilizando loops aninhados (for + while)
    printf("\nMovimento do Cavalo:\n");

    // Loop externo com for para as duas casas para baixo
    for(int i = 0; i < 2; i++) {
        printf("Baixo\n");
        
        // Loop interno (executa apenas 1 vez após o segundo "Baixo")
        if (i == 1) {
            int l = 0;
            while(l < 1) {
                printf("Esquerda\n");
                l++;
            }
        }
    }

    return 0;
}
