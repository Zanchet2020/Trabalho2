#include "grafo.h"
#include "mapa.h"

#include <stdlib.h>
#include <stdio.h>

Grafo constroi_grafo_com_mapa(Mapa mapa)
{
    int i, j;
    Grafo grafo;

    // 
    grafo.quantidade = mapa.tam_x * mapa.tam_y;

    grafo.lista_de_ligados = (int**) malloc(mapa.tam_x * mapa.tam_y * sizeof(int*));
    for(i = 0; i < mapa.tam_x * mapa.tam_y; i++){
        grafo.lista_de_ligados[i] = (int*) malloc(5 * sizeof(int));
        for(j = 0; j < mapa.tam_y; j++){
            grafo.lista_de_ligados[i][j] = -1;
        }
    }


    for(j = 0; j < mapa.tam_y; j++){
        for(i = 0; i < mapa.tam_x; i++){
            int linha = j * mapa.tam_x + i;

            grafo.lista_de_ligados[linha][0] = mapa.posicoes[i][j] == '.';

            if(linha > 0){
                if(mapa.posicoes[i][j - 1] == '.'){
                    grafo.lista_de_ligados[linha][1] = 0;
                }
            }
                
            if(linha < mapa.tam_y - 1) grafo.lista_de_ligados[linha][2] = mapa.posicoes[i][j + 1] == '.'; 
            if(i > 0) grafo.lista_de_ligados[linha][3] = mapa.posicoes[i - 1][j] == '.';
            if(i < mapa.tam_x - 1) grafo.lista_de_ligados[linha][4] = mapa.posicoes[i + 1][j] == '.';
        }
    }



    return grafo;
}

void libera_grafo(Grafo grafo){
    for(int i = 0; i <grafo.quantidade; i++){
        free(grafo.lista_de_ligados[i]);
    }
    free(grafo.lista_de_ligados);
}