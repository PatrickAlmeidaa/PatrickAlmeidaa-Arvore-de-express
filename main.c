#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void posOrdem(TNo *p, Pilha* pilha);
int ehOperador(char operador);
int converteChar(char x);

int main(){
    char string[100];
    printf("NÃO DIGITAR NUMEROS COM MAIS DE UMA CASA\n");
    printf("Digite a expressao: ");
    gets(string);
    int size = strlen(string);
    TNo *raiz = tno_Cria();
    insere(raiz,string, 0, size-1);
    char aux;
    int convertido;

    Pilha calculadora;
    pilhaInicia(&calculadora);
    posOrdem(raiz, &calculadora);
    
    int res = pilhaPop(&calculadora);

    printf("Resultado: %d\n", res);

    return 0;
}

void posOrdem(TNo *p, Pilha* pilha){
    if(p == NULL){
        return;
    }
    int convertido;
    posOrdem(p->pEsq, pilha);
    posOrdem(p->pDir, pilha);
    printf("%c", p->value);
    printf("\n");
    if (!ehOperador(p->value)){
            convertido = converteChar(p->value);
            pilhaPush(pilha, convertido);
        }
    else if (ehOperador(p->value)){
        int a, b, c;
        switch (p->value){
        case '+':
            a = pilhaPop(pilha);
            b = pilhaPop(pilha);
            c = a+b;
            pilhaPush(pilha, c);
            break;
        case '-':
            a = pilhaPop(pilha);
            b = pilhaPop(pilha);
            c = b-a;
            pilhaPush(pilha, c);
            break;
        case '*':
            a = pilhaPop(pilha);
            b = pilhaPop(pilha);
            c = a*b;
            pilhaPush(pilha, c);
            break;
        case '/':
            a = pilhaPop(pilha);
            b = pilhaPop(pilha);
            c = b/a;
            pilhaPush(pilha, c);
            break;
        }
    }
}

int ehOperador(char operador){
    if(operador == '+' || operador == '-' || operador == '*' || operador == '/'){
        return 1;
    }
    return 0;
}

int converteChar(char x){
    if (x == '0'){
        return 0;
    }
    else if (x == '1'){
        return 1;
    }
    else if (x == '2'){
        return 2;
    }
    else if (x == '3'){
        return 3;
    }
    else if (x == '4'){
        return 4;
    }
    else if (x == '5'){
        return 5;
    }
    else if (x == '6'){
        return 6;
    }
    else if (x == '7'){
        return 7;
    }
    else if (x == '8'){
        return 8;
    }
    else if (x == '9'){
        return 9;
    }
}