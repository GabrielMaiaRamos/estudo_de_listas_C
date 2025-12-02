// Desafio: A Torre de Hanói Simplificada (Ordenação) Dada uma Pilha Dinâmica P desordenada,
// ordene-a em ordem crescente (o menor elemento no topo) usando apenas uma outra Pilha auxiliar.
// Regra: Você não pode usar vetores ou arrays auxiliares.

#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int info;
    struct NO *prox;
} pilha;

void ordenar_pilha(pilha *topo)
{
    pilha *aux;
    aux = NULL;
    int valor_atual;
    while (topo != NULL)
    {
        // remover o topo da pilha original pra analisar o elemento
        valor_atual = topo->info;
        pilha *lixo = topo;
        topo = topo->prox;
        free(lixo);

        // enquanto tiver alguem na "aux" MAIOR do que a original, entao devolve esse maior pra original
        while (aux != NULL && aux->info > valor_atual)
        {
            int volta;
            // retira de aux
            pilha *lixo = aux;
            volta = aux->info; // guarda o elemento que sera removido
            aux = aux->prox;
            free(lixo);

            // adiciona na original novamente
            pilha *el = malloc(sizeof(pilha));
            el->info = volta;
            el->prox = topo;
            topo = el;
        }

        // coloca o atual na aux
        pilha *el = malloc(sizeof(pilha));
        el->info = valor_atual;
        el->prox = topo;
        topo = el;
    }

    // agora passar AUX pra TOPO de forma invertida
    while (aux != NULL)
    {
        // adiciona em TOPO
        pilha *el = malloc(sizeof(pilha));
        el->info = aux->info;
        el->prox = topo;
        topo = el;

        // remove de AUX
        pilha *lixo = aux;
        aux = aux->prox;
        free(lixo);
    }
}