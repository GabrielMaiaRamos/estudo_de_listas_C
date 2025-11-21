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
    aux = L->prox;
    preL = L;

    while ((aux != NULL) && elem > aux->info)
    {
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;

    if ((aux != NULL) && (aux->info == elem))
        return 1;
    return 0;
}

lista *insereElem(lista *L, int elem)
{
    lista *pre, *el;

    if (!buscaElem(L, &pre, elem))
    {
        // unica diferenca é que nao preciso checar se esta vazia ou se vai inserir na primeira posicao
        // pois sempre ha o no cabeca ali
        el = (lista *)malloc(sizeof(lista));
        el->info = elem;
        el->prox = pre->prox;
        pre->prox = el;
    }
    return L;
}

lista *removeElem(lista *L, int elem)
{
    lista *lixo, *pre;

    if (buscaElem(L, &pre, elem))
    {
        lixo = pre->prox;
        pre->prox = lixo->prox;
        free(lixo);
    }
    else
        printf("The element \" %d \" is NOT in the list!\n", elem);
    return L;
}

int posicaoElem(lista *L, int elem)
{
    lista *aux;
    aux = L->prox;

    int pos = 1;

    while ((aux != NULL) && elem > aux->info)
    {
        aux = aux->prox;
        pos++;
    }

    if ((aux != NULL) && (aux->info == elem))
        return pos;
    return 0;
}

void print_lista(lista *L)
{
    if (L != NULL)
    {
        printf("| %d |", L->info);
        print_lista(L->prox);
    }
}

int menu()
{
    int op;
    printf("\n===MENU===\n[1]Print the List\n[2]Search for a element\n[3]Insert an element\n[4]Remove an element\n[5]Leave\n-> ");
    scanf("%d", &op);
    if (op >= 1 && op <= 5)
        return op;
    else
        return 0;
}

int main()
{
    lista *L = malloc(sizeof(lista));
    L->prox = NULL;

    int op, elem, pos;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            // so muda na chamada da funcao, comecando depois da cabeca
            print_lista(L->prox);
            printf("\n");
            break;

        case 2:
            printf("Type the element to search: ");
            scanf("%d", &elem);

            pos = posicaoElem(L, elem);
            if (pos)
                printf("Elemento ENCONTRADO!\nPosicao = %d\n", pos);
            else
                printf("Elemento NAO encontrado!\n");

            break;

        case 3:
            printf("Type the element to insert: ");
            scanf("%d", &elem);

            L = insereElem(L, elem);

            break;
        case 4:
            printf("Type the element to remove: ");
            scanf("%d", &elem);

            L = removeElem(L, elem);

            break;

        default:
            printf("End of progam.\n");
            op = 0;
            break;
        }

    } while (op);

    getchar();
    getchar();
}