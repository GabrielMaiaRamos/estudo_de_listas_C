#include <stdio.h>
#include <stdlib.h>

//=================================================================================================//
//===================[ Q2 (A) -> PRINTAR UMA ALOCACAO SEQUENCIAL ESTATICA ]========================//
//=================================================================================================//

#define N 10

struct elemento
{
    int codigo;
    char nome[40];
    int preco;
};
typedef struct elemento produto;

void print_dados(produto *vet)
{
    for (int i = 0; i < N; i++)
        printf("Nome: %s\nCodigo: %d\nPreco: $%d,00\n\n", vet[i].nome, vet[i].codigo, vet[i].preco);
}

int main_of_A()
{
    produto vet[N];
}

//=================================================================================================//
//===================[ Q2 (B) -> MEDIA DE PRECOS DE UMA LISTA ENCADEADA ]==========================//
//=================================================================================================//

struct NO
{
    int codigo;
    char *nome;
    int preco;
    struct NO *prox;
};
typedef struct NO lista;

int mediaPrecos(lista *L)
{
    lista *aux = L;
    float i = 0, sum = 0;
    while (aux != NULL)
    {
        sum += aux->preco;
        aux = aux->prox;
        i++;
    }
    if (i != 0)
        return sum / i;
}