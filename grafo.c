#include "grafo.h"
#include "mapa.h"
#include "lista_adj.h"
#include "pilha.h"
#include "fila.h"

#include <stdlib.h>
#include <stdio.h>

#define POSITION(i, j)         ((j) * mapa.tam_x + i)
#define INSERIR(i, j, val)     grafo.lista_de_adj.list[POSITION(i, j)] = inserir(grafo.lista_de_adj.list[POSITION(i,j)], val)

Grafo constroi_grafo_com_mapa(Mapa mapa)
{   
    Grafo grafo;
    grafo.quantidade = mapa.tam_x * mapa.tam_y;
    grafo.tam_x = mapa.tam_x;
    grafo.tam_y = mapa.tam_y;
    grafo.lista_de_adj = cria_lista(grafo.quantidade);

    int i, j;
    grafo.mapa = (char*) calloc(grafo.quantidade, sizeof(int));

    for(j = 0; j < mapa.tam_y; j++){
        for(i = 0; i < mapa.tam_x; i++){
            
            grafo.mapa[POSITION(i, j)] = mapa.posicoes[i][j];
            
            if(j > 0) {
                if(mapa.posicoes[i][j-1] == '.') {
                    INSERIR(i, j, POSITION(i, j - 1));
                }
            }

            if(i < mapa.tam_x - 1){
                if(mapa.posicoes[i + 1][j] == '.'){ 
                    INSERIR(i, j, POSITION(i + 1, j));
                }
            }

            if(j < mapa.tam_y - 1){
                if(mapa.posicoes[i][j+1] == '.') {
                    INSERIR(i, j, POSITION(i, j + 1));
                }
            }
            if(i > 0){
                if(mapa.posicoes[i - 1][j] == '.'){ 
                    INSERIR(i, j, POSITION(i - 1, j));
                }
            }
        }
    }
    return grafo;
}

Info_regioes regioes(Grafo grafo){
    Info_regioes info_reg;

    int * visitados = (int*)calloc(grafo.quantidade, sizeof(int));

    info_reg.maior_regiao = 0;
    info_reg.num_regioes = 0;

    

    pilha * pilha = cria_pilha();

    while (1)
    {
        int tam_regiao_atual = 0;
        int i = 0;
        for(i = 0; i < grafo.quantidade; i++){
            if(!visitados[i] && grafo.mapa[i] == '.') {
                info_reg.num_regioes++;
                break;
            }
        } 
        if(i == grafo.quantidade) break;
        
        // encontrada primeira cabeca / ponto inicial da busca
        visitados[i] = 1;
        tam_regiao_atual++;
        ppush(pilha, i);
        while(!pvazia(pilha)){
            i = ppop(pilha);
            if(!visitados[i]){
                tam_regiao_atual++;
            }
            visitados[i] = 1;
            while(!vazia_lista(grafo.lista_de_adj.list[i])){
                int ret = 0;
                grafo.lista_de_adj.list[i] = remover_ultimo(grafo.lista_de_adj.list[i], &ret);
                if(!visitados[ret]) ppush(pilha, ret);
            }
        }
        if(tam_regiao_atual > info_reg.maior_regiao) info_reg.maior_regiao = tam_regiao_atual;
    }
    free(visitados);
    libera_pilha(pilha);
    return info_reg;

}

int caminho(Grafo grafo, int x1, int y1, int x2, int y2){
    int raiz = x1 * grafo.tam_x + y1;
    int destino = x2 * grafo.tam_x + y2;

    if(raiz == destino) return 0;

    int * enfileirado = (int*)calloc(grafo.quantidade, sizeof(int));
    int * nivel = (int*)calloc(grafo.quantidade, sizeof(int));

    fila * Fila = cria_fila();

    fpush(Fila, raiz);
    enfileirado[raiz] = 1;
    while(!fvazia(Fila)){
        int i = fpop(Fila);
        while(!vazia_lista(grafo.lista_de_adj.list[i])){
                int ret = 0;
                grafo.lista_de_adj.list[i] = remover_ultimo(grafo.lista_de_adj.list[i], &ret);
                if(!enfileirado[ret]){
                    fpush(Fila, ret);
                    enfileirado[ret] = 1;
                    nivel[ret] = 1 + nivel[i];
                }
            }
    }
    free(enfileirado);
    libera_fila(Fila);
    if(nivel[destino] == 0) return -1;

    return nivel[destino];
}

void libera_grafo(Grafo grafo){
    free(grafo.mapa);
    libera_lista(grafo.lista_de_adj);
}