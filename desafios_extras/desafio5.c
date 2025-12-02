// O "Caixa Rápido" Você tem duas filas estáticas, F1 e F2.
// A F1 é preferencial (idosos) e a F2 é comum.
// Crie uma função que receba essas duas filas e gere uma terceira fila F_Unica.
// Regra: A F_Unica deve ser preenchida intercalando: 2 pessoas da fila preferencial
// para cada 1 pessoa da fila comum. Se uma fila acabar, termine de preencher com a que sobrou.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct FilaEstatica
{
    int dados[MAX];
    int inicio, fim, tam;
} fila;

void mesclar_filas(fila *f1, fila *f2, fila *f_unica)
{
    int valor;
    while (f1->tam > 0 || f2->tam > 0)
    {
        for (int i = 0; i < 2; i++)
        {
            if (f1->tam > 0)
            {
                // tiro o da frente de F1
                valor = f1->dados[f1->inicio];
                f1->inicio = (f1->inicio + 1) % MAX;
                f1->tam--;
            }
            // adiciono no final de f_unica
            f_unica->dados[f_unica->fim] = valor;
            f_unica->fim = (f1->fim + 1) % MAX;
            f_unica->tam++;
        }
        if (f2->tam > 0)
        {
            // tiro o da frente de F2
            valor = f2->dados[f2->inicio];
            f2->inicio = (f2->inicio + 1) % MAX;
            f2->tam--;
        }
        // adiciona no final de f_unica
        f_unica->dados[f_unica->fim] = valor;
        f_unica->fim = (f_unica->fim + 1) % MAX;
        f_unica->tam++;
    }
}