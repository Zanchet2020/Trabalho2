#ifndef GRAFO_H
#define GRAFO_H

#include "mapa.h"
#include "lista_adj.h"

typedef struct Grafo{ 
    lista_adj lista_de_adj;
    char * mapa;
    int tam_x, tam_y;
    int quantidade;
} Grafo;

typedef struct Info_regioes
{
    int num_regioes;
    int maior_regiao;
} Info_regioes;


// recebe um mapa e retorna um grafo
Grafo constroi_grafo_com_mapa(Mapa mapa);

Info_regioes regioes(Grafo grafo);

void libera_grafo(Grafo grafo);

int caminho(Grafo grafo, int x1, int y1, int x2, int y2);

#endif