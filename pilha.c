#include "pilha.h"
#include "nodo.h"
#include "fila.h"

#include <stdlib.h>
#include <stdio.h>

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

void imprime_pilha(pilha * Pilha){
    pilha * new = cria_pilha();

    printf("pilha: ");
    while(!pvazia(Pilha)){
        int i = ppop(Pilha);
        printf("%d|", i);
        ppush(new, i);
    }

    while(!pvazia(new)) ppush(Pilha, ppop(new));

    printf("\n");

}


void libera_pilha(pilha * Pilha){
    while(!pvazia(Pilha)) ppop(Pilha);
    free(Pilha);
}