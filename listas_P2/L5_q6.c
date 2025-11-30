#include <stdio.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO pilha;

void print_pilha(pilha *topo)
{
    if (topo != NULL)
    {
        printf("| %d |", topo->info);
        print_pilha(topo->prox);
    }
}