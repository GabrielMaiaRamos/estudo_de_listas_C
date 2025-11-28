#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox, *ant;
};
typedef struct NO lista;

// NAO MUDA EM RELACAO AS CIRCULARES NORMAIS
int buscaElem(lista *L, lista **pre, int elem)
{
    lista *aux, *preL;
    aux = L->prox;
    preL = L;
    while ((aux != L) && (elem > aux->info))
    {
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux != L) && (aux->info == elem))
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
        // mudanca simples, pq agora so precisamos preencher o "ant" de "EL" e do "pre->prox"
        el->prox = pre->prox;
        el->ant = pre;
        pre->prox->ant = el;
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
        pre->prox->ant = lixo->ant;
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

    while ((aux != L) && elem > aux->info)
    {
        aux = aux->prox;
        pos++;
    }

    if ((aux != L) && (aux->info == elem))
        return pos;
    return 0;
}

void print_lista(lista *L, lista *aux)
{
    if (aux != L)
    {
        printf("| %d |", aux->info);
        print_lista(L, aux->prox);
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
    lista *L;
    L = (lista *)malloc(sizeof(lista));
    // proximo e ant apontam pra L
    L->prox = L;
    L->ant = L;

    int op, elem, pos;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            // passa o cabeça como L, e o auxiliar como L->prox, pra comecar dos elementos
            print_lista(L, L->prox);
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