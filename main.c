#include "grafo.h"
#include "mapa.h"
#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N = 0, M = 0;
    char command_buffer[8];
    scanf("%d", &N);
    scanf("%d", &M);

    // alocando e lendo o mapa no inicio do programa

    Mapa mapa = criar_mapa(N, M);

    Grafo grafo = constroi_grafo_com_mapa(mapa);

    while(1){
        scanf("%s", command_buffer);
        if(!strcmp(command_buffer, "regioes")){
            Info_regioes info_reg;
            info_reg = regioes(grafo);
            printf("%d regioes; a maior tem area %d\n", info_reg.num_regioes, info_reg.maior_regiao);    
            grafo = constroi_grafo_com_mapa(mapa);        
        } else if(!strcmp(command_buffer, "cam")){
            int x1, y1, x2, y2;
            scanf("%d", &x1);
            scanf("%d", &y1);
            scanf("%d", &x2);
            scanf("%d", &y2);
            int passos;
            passos = caminho(grafo, x1, y1, x2, y2);      
            if(passos == -1){
                printf("Nao ha caminho de (%d,%d) para(%d,%d)\n", x1, y1, x2, y2);
            } else {
                printf("De (%d,%d) para (%d,%d) em %d passos\n", x1, y1, x2, y2, passos);
            }
            grafo = constroi_grafo_com_mapa(mapa);
        } else if(!strcmp(command_buffer, ".")){
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
            inserir_no_mapa(x, y, '.', &mapa);
            grafo = constroi_grafo_com_mapa(mapa);
            imprimir_mapa(mapa);
        } else if(!strcmp(command_buffer, "x")){
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
            inserir_no_mapa(x, y, 'x', &mapa);
            grafo = constroi_grafo_com_mapa(mapa);
            imprimir_mapa(mapa);
        } else if(!strcmp(command_buffer, "F")){
            libera_grafo(grafo);
            libera_mapa(mapa);
            break;
        }
    }

    
    

    return 0;
}