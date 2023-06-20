#ifndef GRAFO_H
#define GRAFO_H

#include "mapa.h"
#include "lista_adj.h"

typedef struct Grafo{ 
    lista_adj lista_de_adj;
    int quantidade;
} Grafo;

// recebe um mapa e retorna um grafo
Grafo constroi_grafo_com_mapa(Mapa mapa);

void libera_grafo(Grafo grafo);

#endif