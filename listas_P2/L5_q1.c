#include <stdio.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO lista;

int contaNO(lista *L)
{
    if (L != NULL)
        return 1 + contaNO(L->prox);
}

int main()
{
    lista *L;
    L = NULL;
    // nothing
}