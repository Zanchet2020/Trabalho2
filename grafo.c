#include "grafo.h"
#include "mapa.h"

#include <stdlib.h>
#include <stdio.h>

Grafo constroi_grafo_com_mapa(Mapa mapa)
{
    int i, j;
    Grafo grafo;

    // 
    grafo.lista_de_ligados = (int**) malloc(mapa.tam_x * mapa.tam_y * sizeof(int*));
    for(i = 0; i < mapa.tam_x * mapa.tam_y; i++){
        grafo.lista_de_ligados[i] = (int*) calloc(5, sizeof(int));
    }


    for(j = 0; j < mapa.tam_y; j++){
        for(i = 0; i < mapa.tam_x; i++){
            int linha = j * mapa.tam_x + i;

            printf("linha: %d      i: %d       j: %d \n", linha, i, j);

            grafo.lista_de_ligados[linha][0] = mapa.posicoes[i][j] == '.';
            
            printf("\tprimeiro feito\n");

            if(linha > 0) grafo.lista_de_ligados[linha][1] = mapa.posicoes[i][j - 1] == '.';
            
            printf("\tsegundo feito\n");

            if(linha < mapa.tam_y - 1) grafo.lista_de_ligados[linha][2] = mapa.posicoes[i][j + 1] == '.'; 

            printf("\tterceiro feito\n");
            
            if(i > 0) grafo.lista_de_ligados[linha][3] = mapa.posicoes[i - 1][j] == '.';
            
            printf("\tquarto feito\n");
            
            if(i < mapa.tam_x - 1) grafo.lista_de_ligados[linha][4] = mapa.posicoes[i + 1][j] == '.';
            
            printf("\tquinto feito\n");
        }
    }

    return grafo;
}