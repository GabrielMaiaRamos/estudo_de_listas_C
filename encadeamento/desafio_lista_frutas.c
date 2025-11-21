#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// no do tipo, guarda o atual e o prox
struct NOtipo
{
    char *nome_tipo;
    struct NOtipo *proxtipo;
};
typedef struct NOtipo tipo;

// no fruta, guarda a fruta atual e a proxima, e o tipo
struct NOfruta
{
    char *nome;
    struct NOfruta *proxFruta;
    struct NOtipo *tipo;
};
typedef struct NOfruta fruta;

int buscaFruta(fruta *L, fruta **pre, char *nome)
{
    fruta *aux, *preL;
    aux = L->proxFruta;
    preL = L;

    while ((aux != NULL) && (strcmp(nome, aux->nome) > 0))
    {
        preL = aux;
        aux = aux->proxFruta;
    }
    (*pre) = preL;

    if ((aux != NULL) && (strcmp(nome, aux->nome) == 0))
        return 1;
    return 0;
}

int buscaTipo(tipo *T, tipo **pre, char *nome_tipo)
{
    tipo *aux, *preT;
    aux = T->proxtipo;
    preT = T;

    while ((aux != NULL) && (strcmp(nome_tipo, aux->nome_tipo) > 0))
    {
        preT = aux;
        aux = aux->proxtipo;
    }
    (*pre) = preT;
    if ((aux != NULL) && (strcmp(nome_tipo, aux->nome_tipo) == 0))
        return 1;
    return 0;
}

fruta *InsereFruta(fruta *L, char *nome)
{
    fruta *pre, *el;

    if (!buscaFruta(L, &pre, nome))
    {
        // aloco espaco pra fruta E um espaco pra CABECA do TIPO dela
        el = (fruta *)malloc(sizeof(fruta));
        el->tipo = (tipo *)malloc(sizeof(tipo));
        el->tipo->proxtipo = NULL;
        // el->nome é uma string, logo deve ser alocado um vetor de caracteres
        el->nome = (char *)malloc(sizeof(strlen(nome) + 1));
        // strcpy pra copiar "nome" em "el->nome"
        strcpy(el->nome, nome);
        el->proxFruta = pre->proxFruta;
        pre->proxFruta = el;
    }
    return L;
}

fruta *InsereTipo(fruta *L, char *nome_fruta)
{
    fruta *pre_Fruta, *atual;
    tipo *pre_Tipo, *el;

    if (buscaFruta(L, &pre_Fruta, nome_fruta))
    {
        atual = pre_Fruta->proxFruta;

        char *nome_tipo = malloc(sizeof(char) * 20);
        printf("Digite o nome do tipo: ");
        scanf(" %19[^\n]", nome_tipo);

        if (!buscaTipo(atual->tipo, &pre_Tipo, nome_tipo))
        {
            el = (tipo *)malloc(sizeof(tipo));
            el->nome_tipo = (char *)malloc(sizeof(strlen(nome_fruta)) + 1);
            strcpy(el->nome_tipo, nome_tipo);
            el->proxtipo = pre_Tipo->proxtipo;
            pre_Tipo->proxtipo = el;
        }
        else
            printf("Esse tipo ja existe!\n");
    }
    else
        printf("Fruta nao encontrada!\n");
    return L;
}

fruta *removeFruta(fruta *L, char *nome_fruta)
{
    fruta *lixo_fruta, *pre_fruta;
    tipo *lixo_tipo, *aux_tipo;

    if (buscaFruta(L, &pre_fruta, nome_fruta))
    {
        lixo_fruta = pre_fruta->proxFruta;
        pre_fruta->proxFruta = lixo_fruta->proxFruta;

        aux_tipo = lixo_fruta->tipo; // NAO pula o no cabeca
        while (aux_tipo->proxtipo != NULL)
        {
            printf("Tipo \" %s \" apagado!\n", aux_tipo->proxtipo->nome_tipo);
            lixo_tipo = aux_tipo->proxtipo;
            aux_tipo->proxtipo = lixo_tipo->proxtipo;
            free(lixo_tipo);
        }
        printf("todos os tipos apagados... fruta pode ser apagada!\n");
        free(lixo_fruta);
    }
    else
        printf("Fruta nao encontrada!\n");
    return L;
}

fruta *removeTipo(fruta *L, char *nome_fruta)
{
    fruta *pre_fruta, *atual;
    tipo *pre_tipo, *lixo;

    if (buscaFruta(L, &pre_fruta, nome_fruta))
    {
        atual = pre_fruta->proxFruta;

        char *nome_tipo = malloc(sizeof(char) * 20);
        printf("Digite o nome do tipo: ");
        scanf(" %19[^\n]", nome_tipo);

        if (buscaTipo(atual->tipo, &pre_tipo, nome_tipo))
        {
            lixo = pre_tipo->proxtipo;
            pre_tipo->proxtipo = lixo->proxtipo;
            printf("Tipo \" %s \" removido!\n", lixo->nome_tipo);
            free(lixo);
        }
        else
            printf("Tipo nao encontrado!\n");
    }
    else
        printf("Fruta nao encontrada!\n");

    return L;
}

void MostrarFrutas(fruta *L)
{
    tipo *aux;

    if (L != NULL)
    {
        printf("|   %s   |", L->nome);
        printf("\n");

        aux = L->tipo->proxtipo;
        while (aux != NULL)
        {
            printf(" -> %s \n", aux->nome_tipo);
            aux = aux->proxtipo;
        }

        printf("\n");
        MostrarFrutas(L->proxFruta);
    }
}

int menu()
{
    int op;
    printf("\n===MENU===\n[1]Mostrar as Frutas\n[2]Inserir Fruta"
           "\n[3]Inserir Tipo\n[4]Remover Fruta\n[5]Remover Tipo\n[6]Sair\n-> ");
    scanf("%d", &op);
    if (op >= 1 && op <= 5)
        return op;
    else
        return 0;
}

int main()
{
    fruta *L = malloc(sizeof(fruta));
    // inicializo encadeada com cabeca
    L->proxFruta = NULL;
    L->tipo = (tipo *)malloc(sizeof(tipo));
    L->tipo->proxtipo = NULL;

    char *nome_fruta = malloc(sizeof(char) * 20);

    int op = 1;
    while (op)
    {
        op = menu();
        switch (op)
        {
        case 1:
            MostrarFrutas(L->proxFruta);
            printf("\n");

            break;

        case 2:
            printf("Digite o nome da fruta: ");
            scanf(" %19s", nome_fruta);
            L = InsereFruta(L, nome_fruta);
            break;

        case 3:
            printf("Digite o nome da fruta que ira adicionar um tipo: ");
            scanf(" %19s", nome_fruta);
            L = InsereTipo(L, nome_fruta);
            break;
        case 4:
            printf("Digite o nome da fruta que deseja remover: ");
            scanf(" %19s", nome_fruta);
            L = removeFruta(L, nome_fruta);
            break;
        case 5:
            printf("Digite o nome da fruta que contem o tipo: ");
            scanf(" %19s", nome_fruta);
            L = removeTipo(L, nome_fruta);
            break;

        case 6:
            printf("Fim do Programa!\n");
            op = 0;
            break;
        }
    }

    printf("\n===Aperte ENTER pra fechar===\n");
    getchar();
    getchar();
}