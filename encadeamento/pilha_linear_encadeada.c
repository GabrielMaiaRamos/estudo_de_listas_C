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

    // topo vira o NO do elemento
    el->info = elem;
    el->prox = topo;
    topo = el;

    return topo;
}

pilha *pop(pilha *topo, int *elem)
{
    // nesse caso (so por escolha mesmo) eu estou alterando o elemento dinamicamente e retornando o topo
    // no caso da pilha, eu fiz o contrario.
    pilha *lixo;
    lixo = (pilha *)malloc(sizeof(pilha));

    // se nao estiver vazia
    if (topo != NULL)
    {
        // passa o topo para o prox elemento e exclui o antigo
        lixo = topo;
        topo = lixo->prox;
        (*elem) = lixo->info;
        free(lixo);
    }

    return topo;
}

void print_pilha(pilha *topo)
{
    // igual ao de lista linear encadeada
    if (topo != NULL)
    {
        printf("| %d |", topo->info);
        print_pilha(topo->prox);
    }
}

int posicaoElem(pilha *topo, int elem)
{

    pilha *aux;
    int pos = 1;

    aux = (pilha *)malloc(sizeof(pilha));
    aux = topo;

    while ((aux != NULL))
    {
        // igual ao da lista linear encadeada, mas aqui preciso chegar a lista inteira, pois nao esta ordenada
        if (aux->info == elem)
            return pos;

        aux = aux->prox;
        pos++;
    }

    return 0;
}

int menu()
{
    int op;
    printf("\n===MENU===\n[1]Print the List\n[2]Search for a element\n[3]Push an element\n[4]Pop\n[5]Leave\n-> ");
    scanf("%d", &op);
    if (op >= 1 && op <= 5)
        return op;
    else
        return 0;
}

int main()
{
    pilha *topo;
    topo = NULL;
    int op, pos, elem;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            print_pilha(topo);
            printf("\n");
            break;

        case 2:
            printf("Type the element to search: ");
            scanf("%d", &elem);

            pos = posicaoElem(topo, elem);
            if (pos)
                printf("Elemento ENCONTRADO!\nPosicao = %d\n", pos);
            else
                printf("Elemento NAO encontrado!\n");

            break;

        case 3:
            printf("Type the element to insert: ");
            scanf("%d", &elem);

            topo = push(topo, elem);

            break;
        case 4:
            if (topo != NULL)
            {
                topo = pop(topo, &elem);
                printf("Elemento \" %d \" REMOVIDO!\n", elem);
            }
            else
                printf("Empty list!\n");

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