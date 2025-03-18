#include <stdio.h>

int TAMANHO = 10;
int NAVIO = 3;

// Função para representar o tabuleiro com 0
void RepresentarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int x = 0; x < TAMANHO; x++) {
        for (int y = 0; y < TAMANHO; y++) {
            tabuleiro[x][y] = 0;
        }
    }
}

// Função para posicionar os navios
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    for (int x = 0; x < NAVIO; x++) {
        if (orientacao == 0) {
            tabuleiro[linha][coluna + x] = NAVIO; // Horizontal
        } else {
            tabuleiro[linha + x][coluna] = NAVIO; // Vertical
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int x = 0; x < TAMANHO; x++) {
        for (int y = 0; y < TAMANHO; y++) {
            printf("%d ", tabuleiro[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Representa tabuleiro
    RepresentarTabuleiro(tabuleiro);
    
    // Posiciona os navios (coordenadas predefinidas)
    posicionarNavio(tabuleiro, 0, 1, 1); // Navio horizontal na linha 0, coluna (1+1)2
    posicionarNavio(tabuleiro, 8, 6, 0); // Navio vertical na linha (7+1)8, coluna(5+1)6 (facilitar para contar)
    
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}