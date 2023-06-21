#include "fila.h"
#include "nodo.h"

#include <stdlib.h>
#include <stdio.h>

fila * cria_fila(){
    fila * new = (fila*) malloc(sizeof(fila));
    new->head = NULL;
    return new;
}

void fpush(fila * fila, int val){
    if(fila->head == NULL) {
        fila->head = (nodo*) malloc(sizeof(nodo));
        fila->head->next = NULL;
        fila->head->val = val;
        return;
    }
    nodo * temp = fila->head;
    while(temp->next != NULL) temp = temp->next;
    nodo * new = (nodo*) malloc(sizeof(nodo));
    new->next = NULL;
    new->val = val;
    temp->next = new;
    return;
}

int fpop(fila * fila){
    if(fvazia(fila)) return INT_MIN;
    nodo * aux = fila->head;
    int temp = aux->val;
    fila->head = aux->next;
    free(aux);
    return temp;
}

int fvazia(fila * fila){
    return fila->head == NULL ? 1 : 0;
}

void libera_fila(fila * Fila){
    while(!fvazia(Fila)) fpop(Fila);
    free(Fila);
}