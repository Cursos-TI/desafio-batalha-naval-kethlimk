#include <stdio.h>

#define TAMANHO 10    // Tamanho do tabuleiro (10x10)
#define NAVIO 3       // Valor que representa um navio
#define TAM_NAVIO 3   // Tamanho fixo dos navios

// Inicializa todas as posições do tabuleiro com 0 (simbolizando a água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Testando se é possível posicionar um navio na horizontal ou na vertical
int podePosicionarLinear(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else if (orientacao == 'V') {
        if (linha + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1;
}

// Posiciona navio na horizontal ou vertical
void posicionarLinear(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (orientacao == 'V') {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Testa se é possível posicionar um navio na diagonal (↘ ou ↙)
int podePosicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'D') { // ↘ Diagonal Principal
        if (linha + tamanho > TAMANHO || coluna + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna + i] != 0) return 0;
        }
    } else if (direcao == 'E') { // ↙ Diagonal Secundária
        if (linha + tamanho > TAMANHO || coluna - tamanho + 1 < 0) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0) return 0;
        }
    }
    return 1;
}

// Posiciona navio na diagonal (↘ ou ↙)
void posicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'D') {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        } else if (direcao == 'E') {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

// Exibe o tabuleiro pronto
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicia o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Posicionando os navios lineares (horizontal/vertical)
    // Navio 1: Horizontal
    if (podePosicionarLinear(tabuleiro, 2, 1, TAM_NAVIO, 'H')) {
        posicionarLinear(tabuleiro, 2, 1, TAM_NAVIO, 'H');
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    // Navio 2: Vertical
    if (podePosicionarLinear(tabuleiro, 5, 5, TAM_NAVIO, 'V')) {
        posicionarLinear(tabuleiro, 5, 5, TAM_NAVIO, 'V');
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Posicionando os navios diagonais
    // Navio 3: Diagonal ↘ (principal)
    if (podePosicionarDiagonal(tabuleiro, 6, 0, TAM_NAVIO, 'D')) {
    posicionarDiagonal(tabuleiro, 6, 0, TAM_NAVIO, 'D');
} else {
    printf("Erro ao posicionar navio diagonal principal!\n");
}

    // Navio 4: Diagonal ↙ (secundário)
    if (podePosicionarDiagonal(tabuleiro, 6, 9, TAM_NAVIO, 'E')) {
    posicionarDiagonal(tabuleiro, 6, 9, TAM_NAVIO, 'E');
} else {
    printf("Erro ao posicionar navio diagonal secundária!\n");
}


    // Exibe o tabuleiro com os navios em suas posições
    exibirTabuleiro(tabuleiro);

    return 0;
}
