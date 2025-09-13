// Projeto Xadrez - Trabalho de Faculdade
// Autor: Cambruzzi
// Data: 10/09/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 8

// Tabuleiro global
char tabuleiro[TAM][TAM];

// Função para iniciar o tabuleiro com as peças na posição inicial
void iniciarTabuleiro() {
    char pecasIniciais[8] = {'T','C','B','Q','K','B','C','T'};

    // Preenche peças pretas (maiúsculas)
    for (int i = 0; i < TAM; i++) {
        tabuleiro[0][i] = pecasIniciais[i];
        tabuleiro[1][i] = 'P';
    }

    // Espaços vazios
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Peças brancas (minúsculas)
    for (int i = 0; i < TAM; i++) {
        tabuleiro[6][i] = 'p';
        tabuleiro[7][i] = pecasIniciais[i] + 32; // converte para minúsculo
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro() {
    printf("\n   a b c d e f g h\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d  ", 8 - i); // numeração das linhas
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf(" %d\n", 8 - i);
    }
    printf("   a b c d e f g h\n\n");
}

// Converte coordenadas (ex: "e2") em índices da matriz
int converterCoordenada(char coluna, char linha, int *x, int *y) {
    if (coluna < 'a' || coluna > 'h' || linha < '1' || linha > '8')
        return 0;

    *y = coluna - 'a';         // coluna -> índice
    *x = 8 - (linha - '0');    // linha -> índice
    return 1;
}

// Função para mover uma peça (sem validar regras ainda)
void moverPeca(char origemCol, char origemLin, char destCol, char destLin) {
    int x1, y1, x2, y2;

    if (!converterCoordenada(origemCol, origemLin, &x1, &y1) ||
        !converterCoordenada(destCol, destLin, &x2, &y2)) {
        printf("Coordenadas inválidas!\n");
        return;
    }

    char peca = tabuleiro[x1][y1];
    if (peca == '.') {
        printf("Não há peça na posição de origem!\n");
        return;
    }

    // Executa o movimento
    tabuleiro[x2][y2] = peca;
    tabuleiro[x1][y1] = '.';
    printf("Movimento realizado!\n");
}

int main() {
    iniciarTabuleiro();
    imprimirTabuleiro();

    char oCol, oLin, dCol, dLin;

    while (1) {
        printf("Digite a jogada (ex: e2 e4) ou 0 para sair: ");
        scanf(" %c", &oCol);
        if (oCol == '0') break; // sair do jogo
        scanf("%c %c%c", &oLin, &dCol, &dLin);

        moverPeca(oCol, oLin, dCol, dLin);
        imprimirTabuleiro();
    }

    return 0;
}