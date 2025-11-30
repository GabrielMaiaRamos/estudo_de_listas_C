// Considere uma lista sequencial estática (vetor) que armazena números inteiros.
// Crie uma função que receba duas listas ordenadas (L1 e L2) e gere uma terceira lista (L3),
// que deve conter todos os elementos de L1 e L2, também ordenados.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct lista
{
    int numeros[MAX];
    int tam;
};
typedef struct lista Estatica;

Estatica *intercalar_ordenado(Estatica *L1, Estatica *L2)
{
    int i = 0, j = 0;
    Estatica *L3 = malloc(sizeof(Estatica));
    L3->tam = 0;

    while (i < L1->tam && j < L2->tam)
    {
        // se elemento de L2 for menor, ele entra em L3
        if (L1->numeros[i] < L2->numeros[j])
        {
            L3->numeros[L3->tam] = L1->numeros[i];
            i++;
        }
        // se o elemento de L1 for menor, ele entra em L3
        else
        {
            L3->numeros[L3->tam] = L2->numeros[j];
            j++;
        }
        L3->tam++;
    }
    while (i < L1->tam)
    {
        L3->numeros[L3->tam] = L1->numeros[i];
        i++;
        L3->tam++;
    }
    while (j < L2->tam)
    {
        L3->numeros[L3->tam] = L2->numeros[j];
        j++;
        L3->tam++;
    }
    return L3;
}

// Pequeno teste
int main()
{
    Estatica l1 = {{1, 3, 5, 7}, 4};     // Já ordenada
    Estatica l2 = {{2, 4, 6, 8, 10}, 5}; // Já ordenada, e maior que l1

    Estatica *resultado = intercalar_ordenado(&l1, &l2);

    printf("Lista Intercalada: ");
    for (int i = 0; i < resultado->tam; i++)
    {
        printf("%d ", resultado->numeros[i]);
    }
    // Saída esperada: 1 2 3 4 5 6 7 8 10

    free(resultado);

    getchar();
    getchar();
    return 0;
}