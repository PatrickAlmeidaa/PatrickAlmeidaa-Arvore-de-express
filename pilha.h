#define MAXP 1000
typedef struct pilha
{
    int itens[MAXP];
    int tam;
}Pilha;

void pilhaInicia(Pilha *pilha);

int pilhaVazia(Pilha *pilha);

void pilhaPush(Pilha *pilha, int x);

int pilhaPop(Pilha *pilha);

int pilhaTamanho(Pilha *pilha);