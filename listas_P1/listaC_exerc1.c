#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=================================================================================================//
//====================================[ EXERCICIO 1 -> HANOI ]=====================================//
//=================================================================================================//

int hanoi(int N)
{
    if (N == 1)
        return 1;
    else
        return 2 * hanoi(N - 1) + 1;
}

int main_of_exercise1()
{
    int N;
    printf("Type the number of discs in hanoi: ");
    scanf("%d", &N);
    printf("Number of moves: %d\n", hanoi(N));
}

//=================================================================================================//
//=================================[ EXERCICIO 2 -> BASE BINARIA ]=================================//
//=================================================================================================//

char *dec_to_bin(int num)
{
    if (num > 0)
    {
        char *num_binario = malloc(10 * sizeof(char));
        sprintf(num_binario, "%s%d", dec_to_bin(num / 2), num % 2);
        return num_binario;
    }
    else
        return "0";
}

int main_of_exercise2()
{
    int N;
    printf("Enter the number N in decimal: ");
    scanf("%d", &N);
    printf("Num in binary: %s\n", dec_to_bin(N));
}

//=================================================================================================//
//=====================================[ EXERCICIO 3 -> ÁGUA ]=====================================//
//=================================================================================================//

int fill_vet_exercise3(int N, int *vet)
{
    for (int i = 0; i < N; i++)
    {
        printf("Type the height of the %d wall: ", i + 1);
        scanf("%d", &vet[i]);
    }
}
int max_height(int N, int *vet)
{
    int base, altura, area, max_area = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            base = i - j;
            if (i < j)
                base *= -1;
            if (vet[i] >= vet[j])
                altura = vet[j];
            else
                altura = vet[i];
            area = base * altura;
            if (area > max_area)
                max_area = area;
        }
    return max_area;
}

int main_of_exercise3()
{
    int N;
    printf("Type the number of vectors: ");
    scanf("%d", &N);
    int *vet;

    vet = (int *)malloc(sizeof(int) * N);
    fill_vet_exercise3(N, vet);
    printf("The max area = %d", max_height(N, vet));
}

//=================================================================================================//
//================================[ EXERCICIO 4 -> MAIS NOVO ]=====================================//
//=================================================================================================//

struct aluno
{
    char nome[40];
    char dta_nasc[12];
};
typedef struct aluno tAluno;

tAluno *fill_vet_exercise4(int N, tAluno *vet)
{
    for (int i = 0; i < N; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %39[^\n]", vet[i].nome);
        printf("Enter the date of birth: ");
        scanf(" %s", vet[i].dta_nasc);
    }
}

tAluno *younger(int N, tAluno *vet)
{
    char aux_day[3], aux_month[3], aux_year[5];
    char aux_younger_day[3], aux_younger_month[3], aux_younger_year[5];
    int younger_day, younger_month, younger_year;
    int day, month, year;
    int changed = 1;
    tAluno *younger_age = &vet[0];

    for (int i = 1; i < N; i++)
    {
        if (changed)
        {
            strncpy(aux_younger_day, younger_age->dta_nasc, 2);
            strncpy(aux_younger_month, &younger_age->dta_nasc[3], 2);
            strncpy(aux_younger_year, &younger_age->dta_nasc[6], 4);

            younger_day = atoi(aux_younger_day);
            younger_month = atoi(aux_younger_month);
            younger_year = atoi(aux_younger_year);
        }
        strncpy(aux_day, vet[i].dta_nasc, 2);
        strncpy(aux_month, &vet[i].dta_nasc[3], 2);
        strncpy(aux_year, &vet[i].dta_nasc[6], 4);

        day = atoi(aux_day);
        month = atoi(aux_month);
        year = atoi(aux_year);

        if (year > younger_year)
        {
            younger_age = &vet[i];
            changed = 1;
        }
        else if (year == younger_year)
        {
            if (month > younger_month)
            {
                younger_age = &vet[i];
                changed = 1;
            }
            else if (month == younger_month)
            {
                if (day > younger_day)
                {
                    younger_age = &vet[i];
                    changed = 1;
                }
                else
                    changed = 0;
            }
            else
                changed = 0;
        }
        else
            changed = 0;
    }

    return younger_age;
}
int main_of_exercise4()
{
    int N;
    tAluno *vet, *vet_younger;
    printf("Type the number of students: ");
    scanf("%d", &N);
    // ponteiro vet guarda o endereço de um vetor de structs
    vet = (tAluno *)malloc(sizeof(tAluno) * N);
    fill_vet_exercise4(N, vet);

    vet_younger = younger(N, vet);

    printf("Youger = %s", vet_younger->nome);
}

//=================================================================================================//
//================================[ EXERCICIO 5 -> MATRIZ ESPIRAL ]================================//
//=================================================================================================//

void printf_matriz_espiral(int N, int **matriz)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int **mat_espiral(int N, int **mat)
{
    int num = 0;
    int linha_up = 0;
    int linha_down = N - 1;
    int borda_left = 0;
    int borda_right = N - 1;

    while (linha_up <= linha_down && borda_left <= borda_right)
    {
        for (int j = borda_left; j <= borda_right; j++)
        {
            num++;
            mat[linha_up][j] = num;
        }
        linha_up++;

        for (int i = linha_up; i <= linha_down; i++)
        {
            num++;
            mat[i][borda_right] = num;
        }
        borda_right--;

        for (int j = borda_right; j >= borda_left; j--)
        {
            num++;
            mat[linha_down][j] = num;
        }
        linha_down--;

        for (int i = linha_down; i >= linha_up; i--)
        {
            num++;
            mat[i][borda_left] = num;
        }
        borda_left++;
    }
    return mat;
}

int main_of_exercise5()
{
    int N;
    int **mat;
    printf("Type the size of the matriz: ");
    scanf("%d", &N);

    mat = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
        mat[i] = (int *)malloc(sizeof(int) * N);

    mat_espiral(N, mat);
    printf_matriz_espiral(N, mat);
}

//=================================================================================================//
//==========================[ EXERCICIO 6 -> MULTIPLICACAO DE MATRIZES ]===========================//
//=================================================================================================//

void fill_matriz(int linhas, int colunas, int **mat)
{
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
        {
            printf("Type the element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
}

void printf_matriz(int N, int M, int **matriz)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("-------------------\n");
}

int **mult_mat(int N1, int M1, int N2, int M2, int **mat1, int **mat2)
{
    int **mult_mat;
    mult_mat = (int **)malloc(sizeof(int *) * N1);
    for (int i = 0; i < N1; i++)
        mult_mat[i] = (int *)malloc(sizeof(int) * M2);

    int sum, k = 0;
    if (M1 != N2)
    {
        printf("Impossible to do operation");
        return 0;
    }
    // i vai de 0 ate o total de linhas da mat1
    for (int i = 0; i < N1; i++)
    {
        // j vai de 0 ate o total de colunas da mat2
        for (int j = 0; j < M2; j++)
        {
            // inicializo a posicao com o valor 0 pra poder interar a soma dos elementos no proximo if
            mult_mat[i][j] = 0;
            // pra poder fazer a operacao linha com coluna, preciso de mais um if
            for (int k = 0; k < M1; k++)
                // nesse caso, a mat1 mantem na linha que esta e so vai mudando coluna e a mat2 faz o contrario, muda suas linhas
                mult_mat[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    return mult_mat;
}

int main_of_exercise6()
{
    int N1, M1, N2, M2;
    int **mat1, **mat2, **resultado;

    printf("Type the size NxM of the first matriz: ");
    scanf("%d%d", &N1, &M1);
    printf("Type the size NxM of the second matriz: ");
    scanf("%d%d", &N2, &M2);

    mat1 = (int **)malloc(sizeof(int *) * N1);
    for (int i = 0; i < N1; i++)
        mat1[i] = (int *)malloc(sizeof(int) * M1);
    mat2 = (int **)malloc(sizeof(int *) * N2);
    for (int i = 0; i < N2; i++)
        mat2[i] = (int *)malloc(sizeof(int) * M2);

    fill_matriz(N1, M1, mat1);
    fill_matriz(N2, M2, mat2);

    printf("===Matriz 1===\n");
    printf_matriz(N1, M1, mat1);
    printf("===Matriz 2===\n");
    printf_matriz(N2, M2, mat2);

    resultado = mult_mat(N1, M1, N2, M2, mat1, mat2);
    printf("===Multiplicacao das Matrizes===\n");
    printf_matriz(N1, M2, resultado);
}

//=================================================================================================//
//=========================[ EXERCICIO 7 -> ORDENACAO E BUSCA EM VETOR ]===========================//
//=================================================================================================//

void fill_vet_exercise7(int N, int *vet)
{
    for (int i = 0; i < N; i++)
    {
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &vet[i]);
    }
}

void bobble_sort(int N, int *vet)
{
    int temp;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - 1 - i; j++)
            if (vet[j] > vet[j + 1])
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
}

int exist_sum(int N, int *vet, int X)
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (vet[i] + vet[j] == X)
            {
                printf("Find it!  %d + %d = %d\n", vet[i], vet[j], X);
                return 1;
            }
    return 0;
}

void show_vet_exercise7(int N, int *vet)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d - ", vet[i]);
    }
}

int main_of_exercise7()
{
    int N, X = 1;
    printf("Type the sieze of the vector: ");
    scanf("%d", &N);

    int *vet;
    vet = (int *)malloc(sizeof(int) * N);
    fill_vet_exercise7(N, vet);

    bobble_sort(N, vet);
    show_vet_exercise7(N, vet);

    while (X > 0)
    {
        printf("Type the X: ");
        scanf("%d", &X);

        if (exist_sum(N, vet, X))
            printf("Exist!\n");
        else
            printf("DONT Exist!\n");
    }
}

//=================================================================================================//
//===========================[ EXERCICIO 8 -> ORDENACAO POR CRITERIOS ]============================//
//=================================================================================================//

struct aluno
{
    char nome[40], data_nasc[12];
    float CR;
    int ID;
};
typedef struct aluno tAluno;

void fill_vector(int N, tAluno *vet)
{
    for (int i = 0; i < N; i++)
    {
        printf("Type the NAME of student %d: ", i + 1);
        scanf(" %s", vet[i].nome);
        printf("Type the birth date of studen %d: ", i + 1);
        scanf(" %s", vet[i].data_nasc);
        printf("Type the CR and ID of student %d: ", i + 1);
        scanf("%f%d", &vet[i].CR, &vet[i].ID);
    }
}

void troca(int Aluno1, int Aluno2, tAluno *vet)
{
    tAluno temp;
    temp = vet[Aluno1];
    vet[Aluno1] = vet[Aluno2];
    vet[Aluno2] = temp;
}

void show_vetor(int N, tAluno *vet)
{
    printf("CR //     NAME     // BIRTH DATE // ID \n");
    for (int i = 0; i < N; i++)
    {
        printf("%.2f // %s // %s // %d\n", vet[i].CR, vet[i].nome, vet[i].data_nasc, vet[i].ID);
    }
}

int comp_birth_date(int Aluno1, int Aluno2, tAluno *vet)
{
    int ano1, mes1, dia1, ano2, mes2, dia2;

    // Converter strings para números
    sscanf(vet[Aluno1].data_nasc, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(vet[Aluno2].data_nasc, "%d/%d/%d", &dia2, &mes2, &ano2);

    // Comparar ano primeiro
    if (ano1 != ano2)
        return (ano1 < ano2) ? -1 : 1;

    // Se anos iguais, comparar mês
    if (mes1 != mes2)
        return (mes1 < mes2) ? -1 : 1;

    // Se meses iguais, comparar dia
    if (dia1 != dia2)
        return (dia1 < dia2) ? -1 : 1;

    return 0; // Datas iguais
}

void ordena(int N, tAluno *vet)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            // COMPARAR CR
            if (vet[j].CR < vet[j + 1].CR)
                troca(j, j + 1, vet);
            // SE O CR FOR O MESMO, COMPARAR NOME
            else if (vet[j].CR == vet[j + 1].CR)
            {
                if (strcmp(vet[j].nome, vet[j + 1].nome) > 0)
                    troca(j, j + 1, vet);
                // SE O NOME FOR O MESMO, COMPARAR DATA DE NASCIMENTO
                else if (strcmp(vet[j].nome, vet[j + 1].nome) == 0)
                {
                    if (comp_birth_date(j, j + 1, vet) == 1)
                        troca(j, j + 1, vet);
                    // SE A DATA DE NASCIMENTO FOR A MESMA, COMPARO O ID
                    else if (comp_birth_date(j, j + 1, vet) == 0)
                    {
                        if (vet[j].ID < vet[j + 1].ID)
                            troca(j, j + 1, vet);
                    }
                }
            }
        }
    }
}

int main_of_exercise8()
{
    int N;
    printf("Type the size of the vector: ");
    scanf("%d", &N);
    tAluno *vet;
    vet = (tAluno *)malloc(sizeof(tAluno) * N);

    fill_vector(N, vet);
    printf("\n\n=====Standard Vector=====\n");
    show_vetor(N, vet);
    printf("\n\n=====Ordered Vector=====\n");
    ordena(N, vet);
    show_vetor(N, vet);
}

int main()
{
    // main_of_exercise1();
    // main_of_exercise2();
    // main_of_exercise3();
    // main_of_exercise4();
    // main_of_exercise5();
    // main_of_exercise6();
    // main_of_exercise7();
    main_of_exercise8();

    getchar();
    getchar();
}
