#ifndef FILA_H
#define FILA_H

#include "nodo.h"

typedef struct fila{
    nodo * head;
} fila;

void fpush(fila * fila, int val);

int fpop(fila * fila);

fila * cria_fila();

int fvazia(fila * fila);

void libera_fila(fila * Fila);

//void imprime_fila(fila * fila);


#endif