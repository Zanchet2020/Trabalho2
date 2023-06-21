#ifndef PILHA_H
#define PILHA_H

#include "nodo.h"

typedef struct pilha{
    nodo * head;
} pilha;

void ppush(pilha * pilha, int val);

int ppop(pilha * pilha);

pilha * cria_pilha();

int pvazia(pilha * pilha);

void imprime_pilha(pilha * pilha);

void libera_pilha(pilha * Pilha);


#endif