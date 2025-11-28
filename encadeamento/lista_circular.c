#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO lista;

// das tres basicas, so essa muda
int buscaElem(lista *L, lista **pre, int elem)
{
    lista *aux, *preL;
    aux = L->prox;
    preL = L;
    // muda apenas a verificacao, pois agora a lista acaba no nó cabeca, entao
    // a verificacao deixa de ser NULL, e passa a ser o proprio L
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
// IGUAL a encadeada normalmente
lista *insereElem(lista *L, int elem)
{
    lista *pre, *el;

    if (!buscaElem(L, &pre, elem))
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elem;
        el->prox = pre->prox;
        pre->prox = el;
    }
    return L;
}
// IGUAL a encadeada normalmente
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
// muda como a buscaElem, pois troca a verificacao de NULL pra L
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
// muda a estrutura, agora passo dois parametros, L (que é o no cabeca) e um auxiliar, que vai ser
// o que percorre a lista
void print_lista(lista *L, lista *aux)
{
    // a verificacao é quando aux chega no nó cabeca (significa que reiniciou a lista circular)
    if (aux != L)
    {
        printf("| %d |", aux->info);
        // e na chamada recursiva, apenas aux é passado adiante, L continua parado no nó cabeca
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
    // circular: o "nó cabeça -> prox" aponta pra ele mesmo, e nao pra NULL
    L->prox = L;

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