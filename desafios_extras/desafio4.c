// Dada uma lista duplamente encadeada,
// construa uma função que remova todos os nós cuja informação seja maior que x.

#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox, *ant;
};
typedef struct NO noDuplo;

void removeMaiores(noDuplo **L, int x)
{
    if (L == NULL)
        return;
    noDuplo *aux, *lixo;
    aux = *L;

    // achar o primeiro termo que é maior
    while (aux->info <= x)
        aux = aux->prox;
    // se o primeiro termo ja for maior, L precisa ser NULL
    if (aux->ant == NULL)
        *L = NULL;
    else
        // faz o no anterior ser o ULTIMO (pois o resto sera apagado)
        aux->ant->prox = NULL;
    // excluir os termos alem do encontrado
    while (aux != NULL)
    {
        lixo = aux;
        aux = aux->prox;
        free(lixo);
    }
}