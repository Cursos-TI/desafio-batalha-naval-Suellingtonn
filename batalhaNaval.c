#include <stdio.h>

#define TABELA_SIZE 10  // Tamanho do tabuleiro 10x10

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TABELA_SIZE][TABELA_SIZE]) {
    for (int i = 0; i < TABELA_SIZE; i++) {
        for (int j = 0; j < TABELA_SIZE; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade Cone no tabuleiro
void aplicar_cone(int tabuleiro[TABELA_SIZE][TABELA_SIZE], int origem_x, int origem_y) {
    int tamanho = 5;  // Tamanho da matriz de efeito (5x5 para o cone)
    
    // Construção da área de efeito do cone
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j <= i; j++) {
            int x = origem_x + i;
            int y = origem_y - i + 2 * j;

            if (x < TABELA_SIZE && y < TABELA_SIZE && x >= 0 && y >= 0) {
                tabuleiro[x][y] = 5;  // Marca a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Cruz no tabuleiro
void aplicar_cruz(int tabuleiro[TABELA_SIZE][TABELA_SIZE], int origem_x, int origem_y) {
    int tamanho = 5;  // Tamanho da matriz de efeito (5x5 para a cruz)
    
    // Construção da área de efeito da cruz
    for (int i = 0; i < tamanho; i++) {
        // Linha horizontal (na linha origem)
        if (origem_y - 2 + i >= 0 && origem_y - 2 + i < TABELA_SIZE) {
            tabuleiro[origem_x][origem_y - 2 + i] = 5;
        }

        // Coluna vertical (na coluna origem)
        if (origem_x - 2 + i >= 0 && origem_x - 2 + i < TABELA_SIZE) {
            tabuleiro[origem_x - 2 + i][origem_y] = 5;
        }
    }
}

// Função para aplicar a habilidade Octaedro no tabuleiro
void aplicar_octaedro(int tabuleiro[TABELA_SIZE][TABELA_SIZE], int origem_x, int origem_y) {
    int tamanho = 5;  // Tamanho da matriz de efeito (5x5 para o octaedro)
    
    // Construção da área de efeito do octaedro
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) {  // Condição para formar o losango
                int x = origem_x + i;
                int y = origem_y + j;
                
                if (x < TABELA_SIZE && y < TABELA_SIZE && x >= 0 && y >= 0) {
                    tabuleiro[x][y] = 5;  // Marca a área afetada
                }
            }
        }
    }
}

int main() {
    // Inicialização do tabuleiro (10x10)
    int tabuleiro[TABELA_SIZE][TABELA_SIZE] = {0};
    
    // Definindo a posição dos navios
    tabuleiro[3][3] = 3;  // Exemplo de navio na posição (3,3)
    tabuleiro[4][4] = 3;  // Exemplo de navio na posição (4,4)
    tabuleiro[5][5] = 3;  // Exemplo de navio na posição (5,5)
    
    // Definindo as origens das habilidades
    int origem_cone_x = 2, origem_cone_y = 2;
    int origem_cruz_x = 5, origem_cruz_y = 5;
    int origem_octaedro_x = 6, origem_octaedro_y = 6;
    
    // Aplicando as habilidades
    aplicar_cone(tabuleiro, origem_cone_x, origem_cone_y);
    aplicar_cruz(tabuleiro, origem_cruz_x, origem_cruz_y);
    aplicar_octaedro(tabuleiro, origem_octaedro_x, origem_octaedro_y);
    
    // Exibindo o tabuleiro com as habilidades aplicadas
    printf("Tabuleiro com as habilidades aplicadas:\n");
    exibir_tabuleiro(tabuleiro);
    
    return 0;
}
