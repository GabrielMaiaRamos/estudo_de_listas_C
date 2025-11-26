#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO lista;

int buscaElem(lista *L, lista **pre, int elem)
{
    lista *aux, *preL;
    aux = L;
    preL = NULL;

    while ((aux != NULL) && (elem > aux->info))
    {
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;

    if ((aux != NULL) && (elem == aux->info))
        return 1;
    return 0;
}

lista *insereElem(lista *L, int elem)
{
    lista *pre, *el;

    if (!buscaElem(L, &pre, elem))
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elem;

        if ((L == NULL) || (pre == NULL))
        {
            el->prox = L;
            L = el;
        }
        else
        {
            el->prox = pre->prox;
            pre->prox = el;
        }
    }
    return L;
}

lista *removeElem(lista *L, int elem)
{
    lista *pre, *lixo;

    if (buscaElem(L, &pre, elem))
    {
        if (L->info == elem)
        {
            lixo = L;
            L = lixo->prox;
        }
        else
        {
            lixo = pre->prox;
            pre->prox = lixo->prox;
        }
        free(lixo);
    }
    return L;
}

int main()
{
    int N;
    lista *L;
    L = NULL;

    printf("Digite o elemento");
    scanf("%d", &N);

    L = insereElem(L, N);
}