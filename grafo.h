#ifndef GRAFO_H
#define GRAFO_H

#include "mapa.h"
#include "lista_adj.h"

typedef struct Grafo{ 
    lista_adj lista_de_adj;
    char * mapa;
    int quantidade;
} Grafo;

typedef struct info_regioes
{
    int num_regioes;
    int maior_regiao
} info_regioes;


// recebe um mapa e retorna um grafo
Grafo constroi_grafo_com_mapa(Mapa mapa);

info_regioes regioes(Grafo grafo);

void libera_grafo(Grafo grafo);

#endif