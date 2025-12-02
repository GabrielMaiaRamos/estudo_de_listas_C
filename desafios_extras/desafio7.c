// Desafio: Inverter o Topo Escreva uma função que receba uma Pilha Estática P e um número inteiro K.
// Regra: Você deve inverter a ordem apenas dos K elementos do topo da pilha.
// O restante da base deve ficar intocado. Se K for maior que o tamanho da pilha, inverta ela toda.

#include <stdio.h>

#define MAX 100

typedef struct PilhaEstatica
{
    int dados[MAX];
    int topo;
} pilha;

void inverter_k_topo(pilha *p, int k)
{
    int fila[k];
    int tam_fila = 0;

    while (p->topo != -1 && tam_fila < k)
    {
        fila[tam_fila] = p->dados[p->topo];
        p->topo--;
        tam_fila++;
    }
    for (int i = 0; i < tam_fila; i++)
    {
        p->topo++;
        p->dados[p->topo] = fila[i];
    }
}