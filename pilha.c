#include <stdio.h>
#include "pilha.h"

void pilhaInicia(Pilha *pilha){
    pilha->tam =0;
}

int pilhaVazia(Pilha *pilha){
    if (pilha->tam == 0){
        return 1;
    }
    return 0;
}

void pilhaPush(Pilha *pilha, int x){
    if (pilha->tam < MAXP){
        pilha->itens[pilha->tam] = x;
        pilha->tam++;
    }
}

int pilhaPop(Pilha *pilha){
    int item = pilha->itens[pilha->tam - 1];
    pilha->tam--;
    return item;
}

int pilhaTamanho(Pilha *pilha){
    return pilha->tam;
}