#include "grafo.h"
#include "mapa.h"
#include "lista_adj.h"

#include <stdlib.h>
#include <stdio.h>

#define POSITION(i, j)         j * mapa.tam_x + i
#define INSERIR(i, j, val)     grafo.lista_de_adj.list[POSITION(i, j)] = inserir(grafo.lista_de_adj.list[POSITION(i,j)], val)

Grafo constroi_grafo_com_mapa(Mapa mapa)
{   
    Grafo grafo;
    grafo.quantidade = mapa.tam_x * mapa.tam_y;
    grafo.lista_de_adj = cria_lista(grafo.quantidade);


    int i, j;
    for(j = 0; j < mapa.tam_y; j++){
        for(i = 0; i < mapa.tam_x; i++){
            
            
            printf("i: %d    (tam_y = %d)        j: %d     (tam_x = %d)      position: %d\n", i, mapa.tam_y, j, mapa.tam_x, POSITION(i, j));
            
            if(j > 0) {
                if(mapa.posicoes[i][j-1] == '.') {
                    printf("inserindo valor: %d\n", POSITION(i, j - 1));
                    INSERIR(i, j, POSITION(i, (j - 1)));
                }
            }

            if(i < mapa.tam_x - 1){
                if(mapa.posicoes[i + 1][j] == '.'){ 
                    printf("inserindo valor: %d\n", POSITION(i +1 , j));
                    INSERIR(i, j, POSITION((i + 1), j));
                }
            }

            if(j < mapa.tam_y - 1){
                if(mapa.posicoes[i][j+1] == '.') {
                    printf("inserindo valor: %d\n", POSITION(i, j + 1));
                    INSERIR(i, j, POSITION(i, (j + 1)));
                }
            }
            if(i > 0){
                if(mapa.posicoes[i - 1][j] == '.'){ 
                    printf("inserindo valor: %d\n", POSITION(i - 1, j));
                    INSERIR(i, j, POSITION((i - 1), j));
                }
            }
            
        }
    }
        imprime_lista(grafo.lista_de_adj);
    

    // for(j = 0; j < mapa.tam_y; j++){
    //     for(i = 0; i < mapa.tam_x; i++){
    //         int linha = j * mapa.tam_x + i;

    //         grafo.lista_de_ligados[linha][0] = mapa.posicoes[i][j] == '.';

    //         if(linha > 0){
    //             if(mapa.posicoes[i][j - 1] == '.'){
    //                 grafo.lista_de_ligados[linha][1] = 0;
    //             }
    //         }
                
    //         if(linha < mapa.tam_y - 1) grafo.lista_de_ligados[linha][2] = mapa.posicoes[i][j + 1] == '.'; 
    //         if(i > 0) grafo.lista_de_ligados[linha][3] = mapa.posicoes[i - 1][j] == '.';
    //         if(i < mapa.tam_x - 1) grafo.lista_de_ligados[linha][4] = mapa.posicoes[i + 1][j] == '.';
    //     }
    // }



    // return grafo;
}

void libera_grafo(Grafo grafo){
    libera_lista(grafo.lista_de_adj);
}