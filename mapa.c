#include "mapa.h"

#include <stdlib.h>
#include <stdio.h>

Mapa criar_mapa(int N, int M)
{
    Mapa mapa;
    mapa.tam_y = N;
    mapa.tam_x = M;

    // primeiro quantidade de colunas
    mapa.posicoes = (char**)malloc(mapa.tam_x * sizeof(char*));
    for(int i = 0; i < M; i++){
        mapa.posicoes[i] = (char*)calloc(mapa.tam_y, sizeof(char));
    }
    for(int j = 0; j < mapa.tam_y; j++){
        for(int i = 0; i < mapa.tam_x; i++){
            scanf("%c", &mapa.posicoes[i][j]);
            if(mapa.posicoes[i][j] != '.' && mapa.posicoes[i][j] != 'x') i--;
        }
    }
    return mapa;
}

inline void inserir_no_mapa(int x, int y, char valor, Mapa * mapa)
{
    mapa->posicoes[x][y] = valor;
}

void imprimir_mapa(Mapa mapa){
    for(int j = 0; j < mapa.tam_y; j++){
        for(int i = 0; i < mapa.tam_x; i++){
            printf("%c", mapa.posicoes[i][j]);
        }
        printf("\n");
    }
}