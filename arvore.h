typedef struct No{
   char value;
    struct No *pEsq, *pDir;
}TNo;

TNo *tno_Cria();
void insere(TNo *no, char *string, int inicio, int fim);
int precedenciaMenor(TNo *no, char * string, int inicio,int fim);
int precedencia(char value);