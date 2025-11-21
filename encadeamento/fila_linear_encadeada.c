#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO fila;

void insereElem(fila **inicio, fila **final, int elem)
{
    fila *el = malloc(sizeof(fila));
    // como é inserido no final da fila, o prox sempre será NULL
    el->info = elem;
    el->prox = NULL;

    // se o inicio for NULL, a lista ta vazia, entao inicio tambem aponta pra el
    if ((*inicio) == NULL)
        (*inicio) = el;
    else
        // se nao, a lista tem item, entao o prox do final deixa de ser NULL e vira o el
        (*final)->prox = el;

    // em qualquer caso final aponta pra el
    (*final) = el;
}

int removeElem(fila **inicio)
{
    // nesse caso (so por escolha mesmo) eu estou alterando o inicio dinamicamente e retornando o elemento
    // no caso da pilha, eu fiz o contrario.
    fila *lixo = malloc(sizeof(fila));
    int elem;
    // se a fila nao estiver vazia
    if ((*inicio) != NULL)
    {
        // lixo recebe o inicio enquanto o inicio vira o proximo
        lixo = (*inicio);
        elem = lixo->info;
        (*inicio) = lixo->prox;
        free(lixo);
    }
    return elem;
}

void print_fila(fila *inicio)
{
    if (inicio != NULL)
    {
        printf("| %d |", inicio->info);
        print_fila(inicio->prox);
    }
}

int posicaoElem(fila *inicio, int elem)
{
    fila *aux = malloc(sizeof(fila));
    aux = inicio;
    int pos = 1;

    while (aux != NULL)
    {
        if (aux->info == elem)
            return pos;
        pos++;
        aux = aux->prox;
    }
    return 0;
}

int menu()
{
    int op;
    printf("\n===MENU===\n[1]Print the List\n[2]Search for a element\n[3]Insert an element\n[4]Remove\n[5]Leave\n-> ");
    scanf("%d", &op);
    if (op >= 1 && op <= 5)
        return op;
    else
        return 0;
}

int main()
{
    fila *inicio, *final;
    inicio = NULL;
    final = NULL;
    int op, pos, elem;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            print_fila(inicio);
            printf("\n");
            break;
        case 2:
            printf("Type the element to search: ");
            scanf("%d", &elem);

            pos = posicaoElem(inicio, elem);
            if (pos)
                printf("Elemento ENCONTRADO!\nPosicao = %d\n", pos);
            else
                printf("Elemento NAO encontrado!\n");

            break;
        case 3:
            printf("Type the element to insert: ");
            scanf("%d", &elem);

            insereElem(&inicio, &final, elem);

            break;
        case 4:
            if (inicio != NULL)
            {
                elem = removeElem(&inicio);
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