#include "pilha.h"
#include "nodo.h"

#include <stdlib.h>

pilha * cria_pilha(){
    pilha * new = (pilha*) malloc(sizeof(pilha));
    new->head = NULL;
    return new;
}

void ppush(pilha * pilha, int val){
    nodo * new = (nodo*)malloc(sizeof(nodo));
    new->val = val;
    new->next = pilha->head;
    pilha->head = new;
}

int ppop(pilha * pilha){
    if(pvazia(pilha)) return INT_MIN;
    nodo * aux = pilha->head;
    int temp = aux->val;
    pilha->head = aux->next;
    free(aux);
    return temp;
}

int pvazia(pilha * pilha){
    return pilha->head == NULL ? 1 : 0;
}