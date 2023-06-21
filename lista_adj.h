#ifndef LISTA_ADJ_H
#define LISTA_ADJ_H

typedef struct node
{
    int val;
    struct node * next;
} node;


typedef struct lista_adj
{
    node ** list;
    int tamanho;
} lista_adj;


lista_adj cria_lista(int quant);

node * inserir(node * head, int valor);

node * remover(node * head, int valor);

int buscar(node * head, int valor);

void libera_lista(lista_adj lista);

node * remover_ultimo(node * head, int * ret);

void imprime_lista(lista_adj lista);

int vazia_lista(node * head);


#endif