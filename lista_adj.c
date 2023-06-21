#include "lista_adj.h"
#include <stdlib.h>
#include <stdio.h>

int vazia_lista(node * head){
    return head == NULL ? 1 : 0;
}

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

node * remover_ultimo(node * head, int * ret){
    if(head == NULL) {
        *ret = INT_MIN;
        return NULL;
    }
    if(head->next == NULL){
        *ret = head->val;
        free(head);
        return NULL;
    }
    head->next = remover_ultimo(head->next, ret);
    return head;
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
    int trash;
    for(int i; i < lista.tamanho; i++){
        while(lista.list[i] != NULL) lista.list[i] = remover_ultimo(lista.list[i], &trash);
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