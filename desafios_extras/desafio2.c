// Dada uma lista duplamente encadeada de caracteres (com inicio e fim),
//  verifique se a palavra formada é um palíndromo (lê-se igual de trás para frente, ex: "ARARA", "OSSO").

#include <stdio.h>
#include <stdlib.h>

struct noDUPLO
{
    char letra;
    struct noDUPLO *prox;
    struct noDUPLO *ant;
};
typedef struct noDUPLO lista;

int eh_palindromo(lista *L)
{
    // se estiver vazia, é um palindromo
    if (L == NULL)
        return 1;

    lista *right = L;
    lista *left = L;

    // acha o final da lista
    while (left->prox != NULL)
        left = left->prox;

    // enquanto nao apontarem pro mesmo (lista impar) EE enquanto nao se cruzarem (lista par)
    while ((right != left) && (right->ant != left))
    {
        if (right->letra != left->letra)
            return 0;
        right = right->prox;
        left = left->ant;
    }
    return 1;
}
