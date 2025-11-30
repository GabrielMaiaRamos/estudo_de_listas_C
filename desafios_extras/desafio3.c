// Considere uma lista estática.
// Implemente uma função que remove todos os elementos cujas posições estão no intervalo [inicio, fim].

#include <stdio.h>

#define MAX 100

struct lista
{
    int dados[MAX];
    int tam;
};
typedef struct lista lista;

void removeIntervalo(lista *L, int inicio, int final)
{
    int qtd_interv = final - inicio + 1;

    for (int i = inicio; i + qtd_interv < L->tam; i++)
        L->dados[i] = L->dados[i + qtd_interv];
    L->tam -= qtd_interv;
}

void imprime(lista L)
{
    for (int i = 0; i < L.tam; i++)
        printf("%d ", L.dados[i]);
    printf("\n");
}
int main()
{
    lista L = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9};

    printf("Lista original: ");
    imprime(L);

    removeIntervalo(&L, 2, 5); // remove posições 2 até 5 → remove 3,4,5,6

    printf("Após remover intervalo [2,5]: ");
    imprime(L);

    getchar();
    getchar();
    return 0;
}
