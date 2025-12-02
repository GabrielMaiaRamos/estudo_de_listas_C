// O Filtro de Pares Dada uma Fila Dinâmica F contendo números inteiros aleatórios,
// separe-a em duas novas filas: F_Pares e F_Impares.
// Regra: Ao final do processo, a fila original F deve estar vazia.

#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int info;
    struct NO *prox;
} fila;

void separar_pares_impares(fila **f_original_inicio, fila **pares_inicio, fila **pares_fim, fila **impares_inicio, fila **impares_fim)
{
    fila *lixo;
    while ((*f_original_inicio) != NULL)
    {
        if ((*f_original_inicio)->info % 2 == 0)
        {
            insereElem(pares_inicio, pares_fim, (*f_original_inicio)->info);
        }
        else
            insereElem(impares_inicio, impares_fim, (*f_original_inicio)->info);
        removeElem(f_original_inicio);
    }
}