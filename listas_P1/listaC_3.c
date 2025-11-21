#include <stdio.h>

#define STUDENTS1 60
#define TAMVEC1 100

//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//

void is_approved(int linhas, char nomes[linhas][50], float notas[linhas])
{
    // PRINT DOS ALUNOS APROVADOS
    printf("===Approved Students===\n");
    for (int i = 0; i < linhas; i++)
        if (notas[i] >= 6.0)
            printf("%s\n", nomes[i]);
}

void approved_students()
{
    char nomes[STUDENTS1][50];
    float notas[STUDENTS1];

    // PREENCHER
    for (int i = 0; i < STUDENTS1; i++)
    {
        printf("Write your name: ");
        scanf(" %49[^\n]", nomes[i]);
        printf("Write the grade of %s: ", nomes[i]);
        scanf("%f", &notas[i]);
    }

    is_approved(STUDENTS1, nomes, notas);
}

//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//

void fill_vector(int tam, int vet[tam])
{
    for (int i = 0; i < tam; i++)
    {
        printf("Type the %dth number: ", i + 1);
        scanf("%d", &vet[i]);
    }
}

int higgest_value(int tam, int vet[tam])
{
    int higgest = vet[0];
    for (int i = 1; i < tam; i++)
    {
        if (vet[i] > higgest)
            higgest = vet[i];
    }
    return higgest;
}

void print_new_vector(int tam, int vet[tam])
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d - ", vet[i]);
    }
    printf("\n");
}

void vector_num()
{
    int vet[TAMVEC1];
    char new_vet[TAMVEC1];

    fill_vector(TAMVEC1, vet);
    for (int i = 0; i < TAMVEC1; i++)
    {
        if (vet[i] % 2 == 0)
            vet[i] /= 2;
        else
            vet[i] *= 3;
    }
    printf("===New Vector===\n");
    print_new_vector(TAMVEC1, vet);
    printf("Higgest value: %d\n", higgest_value(TAMVEC1, vet));
}

//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//

void above_average(int tam, int vet[tam], float average)
{
    for (int i = 0; i < tam; i++)
        if (vet[i] >= average)
            printf("%d - ", vet[i]);
}

void enterprise()
{
    int employess;
    printf("How many employess are in your enterprise? ");
    scanf("%d", &employess);

    int wages[employess];
    float average = 0.0;
    for (int i = 0; i < employess; i++)
    {
        // PREENCHER
        printf("Type the wage of the %dth employer: ", i + 1);
        scanf("%d", &wages[i]);
        average += wages[i];
    }
    average /= employess;
    printf("=== Above the Average of %.2f ===", average);
    above_average(employess, wages, average);
}

//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//

int is_in_fibonacci(int N, int term)
{
    int fib[N];
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            fib[i] = 0;
        else if (i == 1)
            fib[i] = 1;
        else
            fib[i] = fib[i - 1] + fib[i - 2];

        if (fib[i] == term)
            return 1;
    }
    return 0;
}

void vector_inputed()
{
    int N, term;
    printf("Type the number of terms in the fibonacci sequence: ");
    scanf("%d", &N);

    printf("Type any number: ");
    scanf("%d", &term);

    if (is_in_fibonacci(N, term))
        printf("The term %d ARE in the fibonacci sequence", term);
    else
        printf("The term %d are NOT in the fibonacci sequence", term);
}

//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//

void printf_matriz(int linhas, int colunas, int mat[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void transposed_matriz(int linhas, int colunas, int mat[linhas][colunas])
{
    int linhasTP = colunas, colunasTP = linhas;
    int matTP[linhasTP][colunasTP];

    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            matTP[j][i] = mat[i][j];

    printf("\n===Transposed Matriz===\n");
    printf_matriz(linhasTP, colunasTP, matTP);
}

void matriz_10x5()
{
    int linhas = 10, colunas = 5;
    int mat[linhas][colunas];
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
        {
            printf("Type the element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    printf("\n===Commom Matriz===\n");
    printf_matriz(linhas, colunas, mat);

    transposed_matriz(linhas, colunas, mat);
}

//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//

int is_symmetric(int linhas, int colunas, int mat[linhas][colunas])
{
    for (int i = 0; i < linhas - 1; i++)
        for (int j = i + 1; j < colunas; j++)
            if (mat[i][j] != mat[j][i])
                return 0;
    return 1;
}

int main_diagonal(int linhas, int colunas, int mat[linhas][colunas])
{
    int sum = 0;
    for (int i = 0; i < linhas; i++)
        sum += mat[i][i];
    return sum;
}

int secundary_diagonal(int linhas, int colunas, int mat[linhas][colunas])
{
    int sum = 0;
    for (int i = 0; i < linhas; i++)
        sum += mat[i][linhas - 1 - i];
    return sum;
}

void matriz_5x5()
{
    int linhas = 3, colunas = 3;
    int mat[linhas][colunas];
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
        {
            printf("Type the element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }

    printf_matriz(linhas, colunas, mat);

    if (is_symmetric(linhas, colunas, mat))
        printf("IS symmetric!\n");
    else
        printf("Is NOT symmetric!\n");

    printf("Sum of main diagonal = %d\n", main_diagonal(linhas, colunas, mat));
    printf("Sum of secundary diagonal = %d\n", secundary_diagonal(linhas, colunas, mat));
}

//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//

int main()
{
    // approved_students();
    // vector_num();
    // enterprise();
    // vector_inputed();
    // matriz_10x5();
    // matriz_5x5();

    getchar();
    getchar();
}