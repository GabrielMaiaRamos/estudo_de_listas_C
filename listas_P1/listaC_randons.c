#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=================================================================================================//
//=====================================[ EXERCICIO 1 -> STRUCT ]=====================================//
//=================================================================================================//
struct tipoPonto
{
    int x;
    int y;
};
typedef struct tipoPonto tPonto;

void mult_and_sum(tPonto p1, tPonto p2, tPonto *sum, tPonto *mult)
{
    // sintaxe com parenteses
    (*sum).x = p1.x + p2.x;
    (*sum).y = p1.y + p2.y;

    // sintaxe mais usada e clara, com seta ->
    mult->x = p1.x * p2.x;
    mult->y = p1.y * p2.y;
    // nao preciso retornar nada, pois estou alterando sum e mult na memoria, ou seja, de modo global
}
void main_of_exercise1()
{
    tPonto P1, P2, sum, mult;
    printf("Type the coordinates (x,y) of P1: ");
    scanf("%d%d", &P1.x, &P1.y);
    printf("Type the coordinates (x,y of P2: ");
    scanf("%d%d", &P2.x, &P2.y);
    // passo copias de P1 e P2, e passo o endereço em si de sum e mult
    mult_and_sum(P1, P2, &sum, &mult);
    printf("Sum of the points = (%d,%d)\nMultiplication of the points = (%d,%d)\n", sum.x, sum.y, mult.x, mult.y);
}

//=================================================================================================//
//===================================[ EXERCICIO 2 -> PONTEIRO ]===================================//
//=================================================================================================//

void separate_date(char data[10], int *day, int *month, int *year)
{
    char D[3], M[3], Y[5];
    strncpy(D, data, 2);
    strncpy(M, &data[3], 2);
    strncpy(Y, &data[6], 4);

    *day = atoi(D);
    *month = atoi(M);
    *year = atoi(Y);
}

void main_of_exercise2()
{
    char data[10];
    int dia, mes, ano;

    printf("Enter your date of birth: ");
    scanf(" %s", data);
    separate_date(data, &dia, &mes, &ano);

    printf("===Unformated Data===\nDay = %d, Month = %d, Year = %d\n", dia, mes, ano);
}

//=================================================================================================//
//===============================[ EXERCICIO 3 -> PONTEIRO E STRUCT ]==============================//
//=================================================================================================//

struct aluno
{
    char mat[12];
    char nome[40];
    float CR;
    int tranc;
};
typedef struct aluno tAluno;

void fillStruct(tAluno *dadoAluno)
{
    scanf(" %s", dadoAluno->mat);
    scanf(" %40[^\n]", dadoAluno->nome);
    scanf("%f", &dadoAluno->CR);
    scanf("%d", &dadoAluno->tranc);
}

void fillVector(tAluno *vet, int N)
{
    tAluno auxiliar;

    for (int i = 0; i < N; i++)
    {
        printf("Enter the Mat, Nome, CR and locked semesters of the candidate %d:\n", i + 1);
        // preencho um auxiliar em uma função diferente
        fillStruct(&auxiliar);
        // o elemento i do meu vetor recebe esses dados na sua estrutura
        vet[i] = auxiliar;
    }
}

int jubila(tAluno *vet, int N)
{
    int semestre_in, semestre_now, semestre_total, year_in, year_now, jubilados = 0;
    char aux_sem_in[2], aux_year_in[3];

    printf("\nEnter the current semester and year: ");
    scanf("%d%d", &semestre_now, &year_now);

    for (int i = 0; i < N; i++)
    {
        semestre_total = 0;
        strncpy(aux_sem_in, vet[i].mat, 1);
        strncpy(aux_year_in, &vet[i].mat[1], 2);
        semestre_in = atoi(aux_sem_in);
        year_in = atoi(aux_year_in);

        if (semestre_in == semestre_now)
            semestre_total++;

        else if (semestre_in < semestre_now)
            semestre_total += 2;

        semestre_total += ((2 * (year_now - year_in)) - vet[i].tranc);

        if (semestre_total > 10)
        {
            printf("%s ESTA JUBILADO, %d SEMESTRES CURSADOS\n", vet[i].nome, semestre_total);
            jubilados += 1;
        }
        else
            printf("%s -> NAAAO <- ESTA JUBILADO, %d SEMESTRES CURSADOS\n", vet[i].nome, semestre_total);
    }
    return jubilados;
}

void main_of_exercise3()
{
    tAluno *vet;
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);

    // vet é um ponteiro que guarda o endereço de um vetor que possui N elementos do tipo tAluno
    vet = (tAluno *)malloc(sizeof(tAluno) * N);
    fillVector(vet, N);

    for (int i = 0; i < N; i++)
    {
        printf("\nMATRICULA: %s", vet[i].mat);
        printf("\nNOME: %s", vet[i].nome);
        printf("\nNOTA: %f", vet[i].CR);
        printf("\nANO: %d", vet[i].tranc);
        printf("\n---------------------------------");
    }
    printf("\nTotal of jubilados = %d", jubila(vet, N));
}
int main()
{
    // main_of_exercise1();
    // main_of_exercise2();
    main_of_exercise3();

    getchar();
    getchar();
}