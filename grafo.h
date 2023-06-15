#ifndef GRAFO_H
#define GRAFO_H

#include "mapa.h"

typedef struct {
    int ** lista_de_ligados;
} Grafo;

// recebe um mapa e retorna um grafo
Grafo constroi_grafo_com_mapa(Mapa mapa);

#endif