#include "lista_adj.h"
#include <stdlib.h>
#include <stdio.h>


node * inserir(node * head, int valor){
    if(head == NULL){
        node * temp = (node*) malloc(sizeof(node));
        temp->val = valor;
        temp->next = NULL;
        
        return temp;
    }
    
    head->next = inserir(head->next, valor);
    return head;
}

node * remover(node * head, int valor){
    if(head == NULL) return NULL;
    if(head->val == valor) {
        node * temp = head->next;
        free(head);
        return temp;
    }
    return remover(head->next, valor);
}

int buscar(node * head, int valor){
    if(head == NULL) return 0;
    if(head->val == valor) return 1;
    return buscar(head->next, valor);
}

int remover_ultimo(node * head){
    if(head == NULL) return INT_MIN;
    if(head->next == NULL) {
        int temp = head->val;
        free(head);
        return temp;
    }
    return remover_ultimo(head->next);
}


lista_adj cria_lista(int quant){
    lista_adj nova_lista;
    nova_lista.list = (node**) malloc(quant * sizeof(node*));
    nova_lista.tamanho = quant;
    for(int i = 0; i < quant; i++){
        nova_lista.list[i] = NULL;
    }
    return nova_lista;
}

void libera_lista(lista_adj lista){
    for(int i; i < lista.tamanho; i++){
        while(lista.list != NULL) remover_ultimo(lista.list[i]);
    }
    free(lista.list);
}



void imprime_lista(lista_adj lista){
    for(int i = 0; i < lista.tamanho; i++){
        printf("%d", i);
        node * nodo = lista.list[i];
        while(nodo != NULL){
            printf(" -> ");
            printf("%d", nodo->val);
            nodo = nodo->next;
        }
        printf("\n");
    }
}