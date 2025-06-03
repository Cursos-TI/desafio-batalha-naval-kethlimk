#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO 10

// Valor usado para representar uma parte do navio no tabuleiro
#define NAVIO 3

// Função para ilustrar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se o navio cabe no tabuleiro
int podePosicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        // Verificando se ultrapassa os limites na horizontal
        if (coluna + tamanho > TAMANHO) return 0;

        // Verificando se há sobreposição
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else if (orientacao == 'V') {
        // Verificando se ultrapassa os limites na vertical
        if (linha + tamanho > TAMANHO) return 0;

        // Verificando se há sobreposição
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1;
}

// Função para mostar o posicionamento de um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro no console
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
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicialização do tabuleiro com 0 (água)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais para a posição dos navios
    int linha1 = 2, coluna1 = 4; // navio horizontal
    int linha2 = 5, coluna2 = 7; // navio vertical
    int tamanhoNavio = 3;

    // Validação e posicionamento do navio na horizontal
    if (podePosicionarNavio(tabuleiro, linha1, coluna1, tamanhoNavio, 'H')) {
        posicionarNavio(tabuleiro, linha1, coluna1, tamanhoNavio, 'H');
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    // Validação e posicionamento do navio na vertical
    if (podePosicionarNavio(tabuleiro, linha2, coluna2, tamanhoNavio, 'V')) {
        posicionarNavio(tabuleiro, linha2, coluna2, tamanhoNavio, 'V');
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
