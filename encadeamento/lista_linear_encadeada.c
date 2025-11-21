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

    // comeca no primeiro NO
    aux = L;
    preL = NULL;

    while ((aux != NULL) && (elem > aux->info))
    {
        // enquanto o no atual nao for null e o elem ainda for maior que o no atual:
        // preL vira o atual, e o atual vira o proximo
        preL = aux;
        aux = aux->prox;
    }
    // sempre altera o ponteiro pre pra o preL
    (*pre) = preL;
    if ((aux != NULL) && (elem == aux->info))
        // se o elemento for igual ao no atual, retorna 1
        return 1;

    return 0;
}

lista *insereElem(lista *L, int elem)
{
    lista *pre, *el;

    // se o elemento NAO estiver na lista:
    if (!buscaElem(L, &pre, elem))
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elem;

        // se for no COMECO da lista ou em uma lista VAZIA
        if ((L == NULL) || (pre == NULL))
        {
            el->prox = L;
            L = el;
        }
        // se for no MEIO da lista ou no FINAL da lista
        else
        {
            el->prox = pre->prox;
            pre->prox = el;
        }
    }
    else
        printf("The element \" %d \" IS ALREADY in the list!\n", elem);
    return L;
}

lista *removeElem(lista *L, int elem)
{
    lista *pre, *lixo;
    // se o elemento ESTIVER na lista
    if (buscaElem(L, &pre, elem))
    {
        // se for no COMECO da lista
        if (L->info == elem)
        {
            lixo = L;
            L = lixo->prox;
        }
        // se for no MEIO ou no FINAL da lista
        else
        {
            lixo = pre->prox;
            pre->prox = lixo->prox;
        }
        // libera esse espaco de memoria
        free(lixo);
    }
    else
        printf("The element \" %d \" is NOT in the list!\n", elem);
    return L;
}

// quase igual ao buscaElem, mas aqui eu só conto até chegar no elemento, inclusive, nem uso "pre"
int posicaoElem(lista *L, int elem)
{
    lista *aux;
    int pos = 1;
    aux = (lista *)malloc(sizeof(lista));

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

// recursividade sem return, chamando a funcao com "L->prox" pra ir passando os elementos
void *print_lista(lista *L)
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
    lista *L;
    L = NULL;
    int op, pos, elem;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            print_lista(L);
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