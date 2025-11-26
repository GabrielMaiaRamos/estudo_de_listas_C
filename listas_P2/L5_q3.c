#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO lista;

void searchElem(lista *L, int elem)
{
    // se ja passei
    if (L == NULL || elem < L->info)
        printf("%d is NOT in the list", elem);

    // se e igual
    else if (L->info == elem)
        printf("%d is in the list", elem);

    // se nao, passa pro prox
    else
        searchElem(L->prox, elem);
}