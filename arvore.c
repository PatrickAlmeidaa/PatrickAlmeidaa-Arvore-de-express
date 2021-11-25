#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

TNo *tno_Cria() {
    TNo *pAux = malloc(sizeof(TNo));
    pAux->pEsq = NULL;
    pAux->pDir = NULL;
    return pAux;
}

void insere(TNo *no, char *string, int inicio, int fim) {
    int position = precedenciaMenor(no, string, inicio, fim);
    if (position != -1 && fim - inicio) {
        no->pEsq = tno_Cria();
        no->pDir = tno_Cria();
        //esquerda
        insere(no->pEsq, string, inicio, position - 1);
        insere(no->pDir, string, position + 1, fim);
    }

}

int precedenciaMenor(TNo *no, char *string, int inicio, int fim) {
    int position = inicio;
    if (inicio != fim) {
        for (int i = inicio + 1; i <= fim; i++) {
            if (precedencia(string[position]) >= precedencia(string[i])) {
                position = i;
            }
        }
        no->value = string[position];
        return position;
    } else {
        no->value = string[position];
        return -1;
    }
}

int precedencia(char value) {
    if (value == '-' || value == '+') {
        return 1;
    } else if (value == '/' || value == '*') {
        return 2;
    } else {
        return 3;
    }
}