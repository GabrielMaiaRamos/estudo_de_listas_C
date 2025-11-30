#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO lista;

struct NODUPLO
{
    int info;
    struct NODUPLO *prox, *ant;
};
typedef struct NODUPLO duplo;

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

// linear simplesmente encadeada, nao circular, sem no cabeca
lista *concatena_A(lista *L1, lista *L2)
{
    lista *aux1;
    // se L2 for vazia, nem faz nada
    if ((L2 != NULL))
        // se apenas L1 for vazia, entao a concatenagem é literalmente L2 (visto no else)
        if (L1 != NULL)
        {
            // percorre L1 ate o ultimo elemento pra apontar pra L2
            aux1 = L1;
            while (aux1->prox != NULL)
                aux1 = aux1->prox;
            aux1->prox = L2;
        }
        else
            L1 = L2;
    return L1;
}

// linear simplesmente encadeada, nao circular, com no cabeca
lista *concatena_B(lista *L1, lista *L2)
{
    lista *aux1, *aux2;
    if (L2->prox != NULL)
    {
        aux1 = L1;
        while (aux1->prox != NULL)
            aux1 = aux1->prox;
        aux1->prox = L2;
    }
    free(L2);

    return L1;
}
// linear simplesmente encadeada, circular, sem no cabeca (dica: nao usar kkkkk)
lista *concatena_C(lista *L1, lista *L2)
{
    lista *aux1, *aux2;
    if (L2 != NULL)
        if (L1 != NULL)
        {
            // percorre L1 ate o ultimo elemento pra apontar pra L2
            aux1 = L1;
            while (aux1->prox != L1)
                aux1 = aux1->prox;
            aux1->prox = L2;

            // percorre L2 ate o ultimo elemento pra apontar pra L1 (circular)
            aux2 = L2;
            while (aux2->prox != L2)
                aux2 = aux2->prox;
            aux2->prox = L1;
        }
        else
            L1 = L2;
    return L1;
}

// linear simplesmente encadeada, circular, com no cabeca
lista *concatena_D(lista *L1, lista *L2)
{
    lista *aux1, *aux2;
    if (L2->prox != L2)
    {
        aux1 = L1;
        while (aux1->prox != L1)
            aux1 = aux1->prox;
        // aux1 pula o no cabeca de L2
        aux1->prox = L2->prox;

        aux2 = L2;
        while (aux2->prox != L2)
            aux2 = aux2->prox;
        // "aux2->prox" vira o no cabeca de L1 (L2 fica circular comecando em L1)
        aux2->prox = L1;
    }
    // libera o no cabeca L2, pois nao é necessario ficarem 2 nos cabecas na memoria
    free(L2);
    return L1;
}

// linear duplamente encadeada, circular, com no cabeca
lista *concatena_E(duplo *L1, duplo *L2)
{
    duplo *aux1, *aux2;
    if (L2->prox != L2)
    {
        aux1 = L1->ant;
        aux1->prox = L2->prox;
        L2->prox->ant = aux1;

        aux2 = L2->ant;
        aux2->prox = L1;
        L1->ant = aux2;
    }
    free(L2);
}

void printf_lista(lista *L)
{
    if (L != NULL)
    {
        printf("| %d |", L->info);
        printf_lista(L->prox);
    }
}