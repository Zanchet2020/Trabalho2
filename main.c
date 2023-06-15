#include "mapa.h"
#include "grafo.h"

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
            
        } else if(!strcmp(command_buffer, "cam")){
            
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

        }
    }

    
    

    return 0;
}