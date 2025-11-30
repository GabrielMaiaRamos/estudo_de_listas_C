#include <stdio.h>

#define MAX 20

typedef struct
{
    int FILA[MAX];
    int comeco, fim;
    int qnt;
} fila;

int verifica_par(fila *L)
{
    int v;
    v = L->FILA[L->comeco];
    if (v % 2 == 0)
    {
        printf("O primeiro termo é par");
        return 1;
    }
    else
    {
        printf("O primeiro termo NÃO é par");
        return 0;
    }
}

int main()
{
    fila *L;
    L->comeco = 0;
    L->fim = 0;
    L->qnt = 0;
    // preenche a fila
    verifica_par(L);
}