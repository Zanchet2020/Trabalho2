#include "lista_adj.h"
#include <stdlib.h>


int inserir(node * nodo, int valor){
    if(nodo->val == valor){
        return 0;
    }
    if(nodo->next == NULL) {
        nodo->next = (node*) malloc(sizeof(node));
        nodo->next->val = valor;
        nodo->next->next = NULL;
        return 1;
    }

    return inserir(nodo->next, valor);
}

int remover(node * nodo, int valor){
     
}