#include <stdio.h>
#include <stdlib.h>

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

void insereElem(lista **L, int elem)
{
    lista *pre, *el;

    if (!buscaElem(*L, &pre, elem))
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elem;

        if ((L == NULL) || (pre == NULL))
        {
            el->prox = (*L);
            (*L) = el;
        }
        else
        {
            el->prox = pre->prox;
            pre->prox = el;
        }
    }
}

void printf_lista(lista *L)
{
    if (L != NULL)
    {
        printf("| %d |", L->info);
        printf_lista(L->prox);
    }
}

lista *uniao(lista *L1, lista *L2)
{
    lista *aux, *uniao;
    uniao = L1;
    aux = L2;

    while (aux != NULL)
    {
        insereElem(&uniao, aux->info);
        aux = aux->prox;
    }
    return uniao;
}

lista *interseccao(lista *L1, lista *L2)
{
    lista *aux1 = L1, *aux2 = L2;
    lista *intersc = NULL;

    // se as duas NAO ESTIVEREM VAZIAS, comeca a logica
    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->info == aux2->info)
        {
            // se achar, comeca a procura com o proximo elemento de L1 E de L2, pois sao ordenadas
            insereElem(&intersc, aux1->info);
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
        // se o elem em L1 ainda for MENOR que um elemento em L2, vejo o proximo elemento de L1
        else if (aux1->info < aux2->info)
        {
            aux1 = aux1->prox;
        }
        // se nao, ou seja, se o elem em L1 ja for MAIOR que o de L2, ent nao vai achar em L2, logo passo
        // pra frente o L2
        else
            aux2 = aux2->prox;
    }
    return intersc;
}

lista *diferenca(lista *L1, lista *L2)
{
    lista *aux1 = L1, *aux2 = L2;
    lista *diferenca = NULL;

    while (aux1 != NULL)
    {
        while (aux2 != NULL && aux1->info < aux2->info)
            aux2 = aux2->prox;

        if ((aux2 == NULL) || (aux1->info != aux2->info))
            insereElem(&diferenca, aux1->info);
        aux1 = aux1->prox;
    }
    return diferenca;
}

int pertinencia(lista *L, int elem)
{
    lista *aux;
    int pos = 1;

    aux = L;

    while ((aux != NULL) && (elem > aux->info))
    {
        aux = aux->prox;
        pos++;
    }
    if ((aux != NULL) && (elem == aux->info))
        return pos;
    return 0;
}

int menu()
{
    int op;
    printf("\n===MENU===\n[1]Uniao\n[2]Interseccao\n[3]Diferenca\n[4]Pertinencia\n[5]Sair-> ");
    scanf("%d", &op);
    if (op >= 1 && op <= 4)
        return op;
    else
        return 0;
}

int main()
{
    int n, op = 1, choose, elem, find;
    lista *L1, *L2, *result;
    L1 = NULL;
    L2 = NULL;
    result = NULL;

    // CRIA LISTA TESTE (de forma porca)
    insereElem(&L1, 10);
    insereElem(&L1, 17);
    insereElem(&L1, 40);
    insereElem(&L2, 30);
    insereElem(&L2, 10);
    insereElem(&L2, 50);
    insereElem(&L2, 20);
    printf("==LISTA 1==\n");
    printf_lista(L1);
    printf("\n");
    printf("==LISTA 2==\n");
    printf_lista(L2);
    printf("\n");

    while (op)
    {

        op = menu();
        switch (op)
        {
        case 1:
            result = uniao(L1, L2);
            printf("UNIAO: \n");
            printf_lista(result);
            break;
        case 2:
            result = interseccao(L1, L2);
            printf("INTERSECCAO: \n");
            printf_lista(result);
            break;
        case 3:
            result = diferenca(L1, L2);
            printf("DIFERENCA: \n");
            printf_lista(result);
            break;
        case 4:
            printf("Pertinencia em qual lista: [1] ou [2]?");
            scanf("%d", &choose);
            printf("Pertinencia de qual elemento? ");
            scanf("%d", &elem);
            if (choose == 1)
            {
                find = pertinencia(L1, elem);
                if (find)
                    printf("Elemento encontrado! posicao: %d\n", find);
                else
                    printf("Elemento NAO encontrado na Lista 1\n");
            }
            else if (choose == 2)
            {
                find = pertinencia(L2, elem);
                if (find)
                    printf("Elemento encontrado! posicao: %d\n", find);
                else
                    printf("Elemento NAO encontrado na Lista 1\n");
                pertinencia(L2, elem);
            }
            else
            {
                printf("nao tem essa lista, po!\n");
                op = 0;
                break;
            }

            break;
        default:
            op = 0;
            break;
        }
    }
    getchar();
    getchar();
}