#ifndef MAPA_H
#define MAPA_H

typedef struct {
    char ** posicoes;
    int tam_x, tam_y;
} Mapa;

Mapa criar_mapa(int N, int M);

void inserir_no_mapa(int x, int y, char valor, Mapa * mapa);

void imprimir_mapa(Mapa mapa);

void libera_mapa(Mapa mapa);


#endif