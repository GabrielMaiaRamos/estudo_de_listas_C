#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int code;
    int time;
    struct no *prox;
} fila;

// insere no fim
void insereProcesso(fila **inicio, fila **fim, int code, int time)
{
    fila *el;
    el = (fila *)malloc(sizeof(fila));

    el->code = code;
    el->time = time;
    el->prox = NULL;

    if ((*inicio) == NULL)
        (*inicio = el);
    else
        (*fim)->prox = el;
    (*fim) = el;
}
// remove no inicio
int removeProcesso(fila **inicio)
{
    fila *lixo;
    int code;
    if ((*inicio) != NULL)
    {
        lixo = (*inicio);
        code = lixo->code;
        (*inicio) = lixo->prox;
        free(lixo);
    }
    return code;
}

void print_processos(fila *inicio)
{
    if (inicio != NULL)
    {
        printf("|  Processo #%-5d | Tempo = %-3d seg  |\n", inicio->code, inicio->time);

        print_processos(inicio->prox);
    }
}

int main()
{
    fila *inicio, *fim;
    inicio = NULL;
    fim = NULL;

    int op = 1, removed, code, time;
    while (op)
    {
        printf("[1]Inserir Processo\n[2]Iniciar Processo\n->");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o codigo do processo e o tempo de execucao: ");
            scanf("%d%d", &code, &time);
            insereProcesso(&inicio, &fim, code, time);
            break;
        case 2:
            printf("Iniciando Processo....\n");
            op = 0;
            break;
        }
    }
    printf("====== FILA DE PROCESSOS INICIAL ======\n");
    print_processos(inicio);
    printf("=======================================\n");

    while (inicio != NULL)
    {
        printf("\n\n====== ATUALIZACAO DOS PROCESSOS ======\n");
        if (inicio->time <= 2)
        {
            removed = removeProcesso(&inicio);

            print_processos(inicio);
            printf("Processo #%d removido!\n", removed);
        }
        else
        {
            insereProcesso(&inicio, &fim, inicio->code, inicio->time - 2);
            removed = removeProcesso(&inicio);

            print_processos(inicio);
            printf("Tempo insuficiente.. Processo #%d realocado!\n", removed);
        }
    }
    getchar();
    getchar();
}