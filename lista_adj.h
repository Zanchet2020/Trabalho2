#ifndef LISTA_ADJ_H
#define LISTA_ADJ_H

typedef struct 
{
    int val;
    node * next;
} node;


typedef struct 
{
    node ** lista;
} lista_adj;


int inserir(node * nodo, int valor);

int remover(node * nodo, int valor);

int buscar(node * nodo, int valor);


#endif