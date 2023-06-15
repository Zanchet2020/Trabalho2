#include "grafo.h"
#include "mapa.h"

#include <stdlib.h>

Grafo constroi_grafo_com_mapa(Mapa mapa)
{
    int i, j;
    Grafo grafo;

    // 
    grafo.lista_de_ligados = (int**) malloc(mapa.tam_x * mapa.tam_y * sizeof(int*));
    for(i = 0; i < 4; i++){
        grafo.lista_de_ligados[i] = (int*) calloc(5, sizeof(int));
    }


    for(i = 0; i < mapa.tam_x; i++){
        for(j = 0; j < mapa.tam_y; j++){
            if(mapa.posicoes[i][j] == '.'){
                grafo.lista_de_ligados[mapa.tam_x + mapa.tam_y + i * 5][0] = 1;
            } else {
                grafo.lista_de_ligados[mapa.tam_x + mapa.tam_y + i * 5][0] = 0;
                continue;
            }

            int posicao = mapa.tam_y * i;
            
            // grafo.lista_de_ligados[posicao][2] = mapa.posicoes[i][j-1] == '.';
            // grafo.lista_de_ligados[posicao][3] = mapa.posicoes[i+1][j] == '.';
            // grafo.lista_de_ligados[posicao][1] = mapa.posicoes[i][j+1] == '.';
            // grafo.lista_de_ligados[posicao][4] = mapa.posicoes[i-1][j] == '.';
        }
    }

    return grafo;
}