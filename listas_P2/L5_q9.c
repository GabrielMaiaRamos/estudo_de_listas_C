#include <stdio.h>

#define N 20

typedef struct
{
    int fila[N];
    int inicio, fim;
    int total;
} fila;

void insereElem(fila *D, int num, int pos)
{
    if (D->total < N)
    {
        if (pos == 'I')
        {
            D->inicio += -1 + N;
            D->inicio = D->inicio % N;
            D->fila[D->inicio] = num;
        }
        else if (pos == 'F')
        {
            D->fila[D->fim] = num;
            D->fim++;
            D->fim = D->fim % N;
            D->total++;
        }
    }
}

int removeElem(fila *D, int pos)
{
    int num = -1;

    if (D->total > 0)
    {
        if (pos == 'I')
        {
            num = D->fila[D->inicio];
            D->inicio++;
            D->inicio = D->inicio % N;
            D->total--;
        }
        else if (pos == 'F')
        {
            num = D->fila[D->fim];
            D->fim = -1 + N;
            D->fim = D->fim % N;
            D->total--;
        }
    }
    return num;
}

int main()
{
    fila D;
    D.inicio = 0;
    D.fim = -1;
    D.total = 0;

    printf("--- Teste de Insercao ---\n");

    // Inserindo normalmente no final: [10, 20]
    insereElem(&D, 10, 'F');
    insereElem(&D, 20, 'F');
    insereElem(&D, 30, 'F');
    insereElem(&D, 40, 'F');
    insereElem(&D, 50, 'F');
    insereElem(&D, 60, 'F');

    // Inserindo no INÍCIO (Fura fila): [5, 10, 20]
    // O 5 vai entrar "antes" do 10. Num vetor circular, isso significa ir pro final do array.
    insereElem(&D, 5, 'I');

    printf("Estado atual (Total %d):\n", D.total);
    printf("Inicio no indice: %d | Valor: %d\n", D.inicio, D.fila[D.inicio]);
    printf("Fim no indice:    %d | Valor: %d\n", D.fim, D.fila[D.fim]);

    printf("\n--- Teste de Remocao ---\n");
    // Deve remover o 5 (que está no início)
    printf("Removendo do inicio: %d\n", removeElem(&D, 'I'));

    // Deve remover o 20 (que está no final)
    printf("Removendo do final:  %d\n", removeElem(&D, 'F'));
    printf("\n");
    for (int i = 0; i < D.total; i++)
    {
        int indice = D.inicio + i;
        indice = indice % N;
        printf("| %d |", D.fila[indice]);
    }
    getchar();
    getchar();
}