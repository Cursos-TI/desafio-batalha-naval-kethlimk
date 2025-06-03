#include <stdio.h>
#include <stdlib.h> // Necessário para abs()


#define TAMANHO 10         // Tamanho do tabuleiro
#define NAVIO 3            // Valor para navio
#define HABILIDADE 5       // Valor para área de habilidade
#define TAM_HAB 5          // Tamanho da matriz de habilidade

// Inicia o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = 0;
}

// Posiciona um navio horizontal e/ou vertical
int podePosicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H' && coluna + tamanho <= TAMANHO) {
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        return 1;
    } else if (orientacao == 'V' && linha + tamanho <= TAMANHO) {
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        return 1;
    }
    return 0;
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 'H')
            tabuleiro[linha][coluna + i] = NAVIO;
        else
            tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Posiciona os navios na diagonal
int podePosicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'D' && linha + tamanho <= TAMANHO && coluna + tamanho <= TAMANHO) {
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha + i][coluna + i] != 0) return 0;
        return 1;
    } else if (direcao == 'E' && linha + tamanho <= TAMANHO && coluna - tamanho + 1 >= 0) {
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha + i][coluna - i] != 0) return 0;
        return 1;
    }
    return 0;
}

void posicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'D')
            tabuleiro[linha + i][coluna + i] = NAVIO;
        else
            tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

// Cria uma matriz em forma de cone (V invertido)
void criarMatrizCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = 0;
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i && i <= TAM_HAB / 2)
                matriz[i][j] = 1;
        }
    }
}

// Cria uma matriz em forma de cruz
void criarMatrizCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            matriz[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
}

// Cria matriz em forma de octaedro (losango)
void criarMatrizOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
matriz[i][j] = (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) ? 1 : 0;

        }
    }
}

// Aplica uma matriz de habilidade ao tabuleiro com base em seu ponto de origem
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemLinha - TAM_HAB / 2 + i;
            int coluna = origemColuna - TAM_HAB / 2 + j;
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Mostra o tabuleiro com a representação visual
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro Final:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiro[i][j] == HABILIDADE) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    // Inicia o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona navios
    if (podePosicionarNavio(tabuleiro, 2, 1, 3, 'H')) posicionarNavio(tabuleiro, 2, 1, 3, 'H');
    if (podePosicionarNavio(tabuleiro, 5, 5, 3, 'V')) posicionarNavio(tabuleiro, 5, 5, 3, 'V');
    if (podePosicionarDiagonal(tabuleiro, 6, 0, 3, 'D')) posicionarDiagonal(tabuleiro, 6, 0, 3, 'D');
    if (podePosicionarDiagonal(tabuleiro, 6, 9, 3, 'E')) posicionarDiagonal(tabuleiro, 6, 9, 3, 'E');

    // Cria as matrizes de habilidades
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Aplica as habilidades ao jogo
    aplicarHabilidade(tabuleiro, cone, 1, 1);       // Cone no topo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 8, 4);   // Octaedro na parte inferior

    // Exibe o tabuleiro com o resultado final 
    exibirTabuleiro(tabuleiro);

    return 0;
}
