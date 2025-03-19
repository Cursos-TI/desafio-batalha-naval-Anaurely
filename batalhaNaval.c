#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10
#define NAVIO 3



// Função para representar o tabuleiro com 0
void RepresentarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para apresentar o tabuleiro
void apresentarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// função para confirmar(validar) navios.
int validarposicao(int tabuleiro[TAMANHO][TAMANHO],int linha, int coluna, int tamanho, int direcao, int diagonal){
    for (int i = 0; i < tamanho; i++) {
        int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
        int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));

        if(x >= TAMANHO || y >= TAMANHO || tabuleiro[x][y] != 0) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar os navios
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int tamanho, int diagonal) {
    int linha, coluna, direcao ,valido;
    do {
        linha = rand() % TAMANHO;
        coluna = rand() % TAMANHO;
        direcao = rand() % 2; // 0 = horizontal, 1 = vertical
        valido = validarposicao(tabuleiro, linha, coluna, tamanho, direcao, diagonal);
    } while (!valido);

    for (int i = 0; i < tamanho; i++) {
        int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
        int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));
        tabuleiro[x][y] = NAVIO;
    }
}
    

int main() {
    srand(time(NULL));
    int tabuleiro[TAMANHO][TAMANHO];

    
    // Representa tabuleiro
    RepresentarTabuleiro(tabuleiro);
    
    // Posiciona os navios (horizontais ou verticais).
    posicionarNavio(tabuleiro, 3, 0);
    posicionarNavio(tabuleiro, 3, 0);
    
    // Posiciona os navios (diagonais).
    posicionarNavio(tabuleiro, 3, 1);
    posicionarNavio(tabuleiro, 3, 1);


    // apresenta o tabuleiro
    apresentarTabuleiro(tabuleiro);
    
    return 0;
}