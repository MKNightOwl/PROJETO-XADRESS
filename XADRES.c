#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int i, j;
    printf("  A B C D E F G H\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função recursiva para o Bispo
void moverBispoRecursivo(int linha, int coluna, int deltaLinha, int deltaColuna) {
    int novaLinha = linha + deltaLinha;
    int novaColuna = coluna + deltaColuna;

    // Verifica limites do tabuleiro
    if (novaLinha < 0 || novaLinha >= TAMANHO_TABULEIRO ||
        novaColuna < 0 || novaColuna >= TAMANHO_TABULEIRO)
        return;

    printf("-> (%c, %d)\n", 'A' + novaColuna, novaLinha + 1);

    // Chamada recursiva
    moverBispoRecursivo(novaLinha, novaColuna, deltaLinha, deltaColuna);
}

void moverBispo(int linha, int coluna) {
    printf("Movimentos validos do Bispo (recursivo) a partir de (%c, %d):\n", 'A' + coluna, linha + 1);
    moverBispoRecursivo(linha, coluna, -1, 1);  // diagonal superior direita
    moverBispoRecursivo(linha, coluna, -1, -1); // diagonal superior esquerda
    moverBispoRecursivo(linha, coluna, 1, 1);   // diagonal inferior direita
    moverBispoRecursivo(linha, coluna, 1, -1);  // diagonal inferior esquerda
    printf("\n");
}

// Movimento do Cavalo com continue e break
void moverCavalo(int linha, int coluna) {
    printf("Movimentos validos do Cavalo (loops avançados) a partir de (%c, %d):\n", 'A' + coluna, linha + 1);

    int movimentos[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };

    int i;
    for (i = 0; i < 8; i++) {
        int novaLinha = linha + movimentos[i][0];
        int novaColuna = coluna + movimentos[i][1];

        // Ignora movimentos fora do tabuleiro
        if (novaLinha < 0 || novaLinha >= TAMANHO_TABULEIRO ||
            novaColuna < 0 || novaColuna >= TAMANHO_TABULEIRO)
            continue;

        printf("-> (%c, %d)\n", 'A' + novaColuna, novaLinha + 1);

        // Exemplo de break: para se atingir primeira coluna
        if (novaColuna == 0) {
            printf("Cavalo atingiu primeira coluna, break.\n");
            break;
        }
    }

    printf("\n");
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Inicializa o tabuleiro com espaços
    for (i = 0; i < TAMANHO_TABULEIRO; i++)
        for (j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = ' ';

    // Posições das peças
    int posBispo[2] = {4, 3}; // E5
    int posCavalo[2] = {4, 4}; // E5

    // Coloca peças no tabuleiro
    tabuleiro[posBispo[0]][posBispo[1]] = 'B';
    tabuleiro[posCavalo[0]][posCavalo[1]] = 'C';

    printf("=== Desafio de Xadrez - MateCheck (Mestre) ===\n");
    imprimirTabuleiro(tabuleiro);

    moverBispo(posBispo[0], posBispo[1]);
    moverCavalo(posCavalo[0], posCavalo[1]);

    return 0;
}
