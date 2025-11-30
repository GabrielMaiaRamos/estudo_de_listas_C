#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO pilha;

pilha *push(pilha *topo, int elem)
{
    pilha *el;
    el = (pilha *)malloc(sizeof(pilha));

    el->info = elem;
    el->prox = topo;
    topo = el;

    return topo;
}

// FUNCAO EM SI
void pares_impares(pilha *topo, pilha **PAR, pilha **IMPAR)
{
    pilha *aux = topo;
    while (aux != NULL)
    {
        if (aux->info % 2 == 0)
            (*PAR) = push(*PAR, aux->info);
        else
            (*IMPAR) = push(*IMPAR, aux->info);
        aux = aux->prox;
    }
}

int main()
{
    pilha *L = NULL, *PAR = NULL, *IMPAR = NULL;
    // primeiro preenche L
    // pra chamada da funcao:
    pares_impares(L, &PAR, &IMPAR);
}