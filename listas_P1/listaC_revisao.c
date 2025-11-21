#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=================================================================================================//
//=================================[ EXERCICIO 1 -> PALINDROMOS ]==================================//
//=================================================================================================//

int is_palindromo(int N)
{
    char str_num[20];
    int tam_str;
    itoa(N, str_num, 10);
    tam_str = strlen(str_num);

    for (int i = 0; i < tam_str; i++)
    {
        if (str_num[i] != str_num[tam_str - 1 - i])
            return 0;
    }
    return 1;
}

int main_of_exercise1()
{
    int N = 0;
    while (N >= 0)
    {
        printf("Enter the Number (negative to stop): ");
        scanf("%d", &N);
        if (is_palindromo(N))
            printf("%d is a palindromo!\n", N);
        else
            printf("%d is NOT a palindromo!\n", N);
    }
}

//=================================================================================================//
//===============================[ EXERCICIO 2 -> MEDIA DE NOTAS ]=================================//
//=================================================================================================//

float average()
{
    float sum, lowest_score = 11, highest_score = -1, score;
    for (int i = 0; i < 6; i++)
    {
        printf("Enter the score of the %dth judge: ", i + 1);
        scanf("%f", &score);
        if (score >= highest_score)
            highest_score = score;
        if (score <= lowest_score)
            lowest_score = score;
        sum += score;
    }
    sum -= highest_score;
    sum -= lowest_score;

    return (sum / 4);
}

int main_of_exercise2()
{
    int atletas = 2;
    for (int i = 0; i < 30; i++)
    {
        printf("===%dth Atleth===\n", i + 1);
        printf("Average Score of the %dth atleth = %.2f\n", i + 1, average());
        printf("\n");
    }
}

//=================================================================================================//
//==============================[ EXERCICIO 3 -> PALAVRA NA FRASE ]================================//
//=================================================================================================//

int is_in_frase(int tam_frase, int tam_word, char frase[tam_frase], char word[tam_word])
{
    int indice = 0;
    for (int i = 0; i < tam_word; i++)
    {
        for (int j = indice; j < tam_frase; j++)
        {
            if (word[i] == frase[j])
            {
                indice = j + 1;
                break;
            }
            if (j == tam_frase - 1)
                return 0;
        }
    }
    return 1;
}

int main_of_exercise3()
{
    char frase[100];
    char word[50];
    int tam_frase, tam_word;

    printf("Write the frase: ");
    scanf(" %99[^\n]", frase);
    tam_frase = strlen(frase);

    printf("Write the word: ");
    scanf(" %s", word);
    tam_word = strlen(word);

    if (is_in_frase(tam_frase, tam_word, frase, word))
        printf("%s IS in the frase %s\n", word, frase);
    else
        printf("%s is NOT in the frase %s\n", word, frase);
}

//=================================================================================================//
//=====================================[ EXERCICIO 4 -> MDC ]======================================//
//=================================================================================================//

int mdc(int x, int y)
{
    if (x >= y && x % y == 0)
        return y;
    else if (x < y)
        return mdc(y, x);
    else
        return mdc(y, x % y);
}

int main_of_exercise4()
{
    int x, y;
    printf("Type the x and the y: ");
    scanf("%d%d", &x, &y);
    if (x == 0 || y == 0)
        printf("Enter non-zero numbers!");
    else
        printf("MDC of %d and %d = %d", x, y, mdc(x, y));
}

//=================================================================================================//
//==============================[ EXERCICIO 5 -> SERIE COM PASSO K ]===============================//
//=================================================================================================//

void imprimeSerie(int i, int j, int k)
{
    if (i <= j)
    {
        printf("%d - ", i);
        imprimeSerie(i + k, j, k);
    }
}

int main_of_exercise5()
{
    int i, j, k;
    printf("Type the i, j and k: ");
    scanf("%d%d%d", &i, &j, &k);
    // ja inicializa com i+k pra nao printar o i (nao é INCLUSIVE i e j)
    imprimeSerie(i + k, j, k);
}
//=================================================================================================//
//==============================[ EXERCICIO 6 -> CONTAGEM DE LETRAS ]==============================//
//=================================================================================================//

int tamString(char *word)
{
    // soma 1 enquanto endenreço que o ponteiro aponta agora for DIFERETE
    // do caracter especial de terminação de string
    if (*word != '\0')
        return 1 + tamString(word + 1);
}

int main_of_exercise6()
{
    char word[20];
    printf("Type the word: ");
    scanf(" %s", word);
    printf("Size of the word %s = %d", word, tamString(word));
}

//=================================================================================================//
//==============================[ EXERCICIO 7 -> DIVISAO RECURSIVA ]===============================//
//=================================================================================================//

int divisao(int A, int B)
{
    if (A >= B)
        return 1 + divisao(A - B, B);
    return 0;
}

int main_of_exercise7()
{
    int A, B;
    printf("Enter the A and the B: ");
    scanf("%d%d", &A, &B);
    printf("Integer division between %d and %d = %d", A, B, divisao(A, B));
}

//=================================================================================================//
//==============================[ EXERCICIO 8 -> DIVISAO RECURSIVA ]===============================//
//=================================================================================================//

int main_of_exercise8()
{
    float storage, average, max, min;
    printf("Enter the storage of day 1: ");
    scanf("%f", &storage);
    average = storage;
    max = storage;
    min = storage;
    for (int i = 2; i <= 10; i++)
    {
        printf("Enter the storage of day %d: ", i);
        scanf("%f", &storage);
        if (storage > max)
            max = storage;
        if (storage < min)
            min = storage;
        average += storage;
    }
    average /= 10;
    printf("Average in last month: %.2f\n highest storage = %.2f\n lowest storage = %.2f\n", average, max, min);
}

void MatTabuada(int N, int **mat)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = (i + 1) * (j + 1);
}

void imprimeMatTabuada(int N, int **mat)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

//=================================================================================================//
//================================[ EXERCICIO 9 -> MATRIZ TABUADA ]================================//
//=================================================================================================//

int main_of_exercise9()
{
    int N;
    printf("Type the N: ");
    scanf("%d", &N);
    int **mat;
    mat = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
        mat[i] = (int *)malloc(sizeof(int) * N);
    MatTabuada(N, mat);
    imprimeMatTabuada(N, mat);
    int X = 1;
    while (X > 0)
    {
        printf("\nType the tabuada that you want see in the matriz of tabuadas: ");
        scanf("%d", &X);
        if (X > N || X < 0)
            printf("X is NOT in the matriz");
        else
            for (int j = 0; j < N; j++)
                printf("%d x %d = %d\n", X, j + 1, mat[X - 1][j]);
    }
}

//=================================================================================================//
//=================================[ EXERCICIO 10 -> MEDIA ALUNOS ]================================//
//=================================================================================================//

struct aluno
{
    char nome[40];
    int ano;
    float N1, N2, N3, N4, media;
};
typedef struct aluno tAluno;

int main_of_exercise10()
{
    int N, indice;
    float highest = 0;

    printf("How many students? ");
    scanf("%d", &N);

    tAluno *vetAlunos;
    vetAlunos = (tAluno *)malloc(sizeof(tAluno) * N);

    for (int i = 0; i < N; i++)
    {
        printf("\n=====Student %d=====\n", i + 1);
        printf("Enter the name: ");
        scanf(" %40[^\n]", vetAlunos[i].nome);
        printf("Enter the year of entry in to college: ");
        scanf(" %40[^\n]", &vetAlunos[i].ano);
        printf("Enter the four grades: ");
        scanf("%f%f%f%f", &vetAlunos[i].N1, &vetAlunos[i].N2, &vetAlunos[i].N3, &vetAlunos[i].N4);

        vetAlunos[i].media = (vetAlunos[i].N1 + vetAlunos[i].N2 + vetAlunos[i].N3 + vetAlunos[i].N4) / 4;
        if (vetAlunos[i].media >= highest)
            highest = vetAlunos[i].media;
    }
    printf("Highest average = %.2f\n", highest);

    printf("\n===Students that have the average equals the highest average===\n");
    for (int i = 0; i < N; i++)
        if (vetAlunos[i].media == highest)
            printf("Student: %s\n", vetAlunos[i].nome);
}

//=================================================================================================//
//============================[ EXERCICIO 11 -> OPERACOES COM VETORES ]============================//
//=================================================================================================//

void fillVet(int N, float *vet)
{
    for (int i = 0; i < N; i++)
    {
        printf("Type the element %d: ", i + 1);
        scanf("%f", &vet[i]);
    }
}

void showVet(int N, float *vet)
{
    for (int i = 0; i < N; i++)
    {
        printf("%.1f  ", vet[i]);
    }
}

void sum(int N, float *vetX, float *vetY)
{
    for (int i = 0; i < N; i++)
    {
        printf("%.1f ", vetX[i] + vetY[i]);
    }
}

void subtraction(int N, float *vetX, float *vetY)
{
    for (int i = 0; i < N; i++)
    {
        printf("%.1f ", vetX[i] - vetY[i]);
    }
}

int search(int N, float *vet, float num)
{
    for (int i = 0; i < N; i++)
    {
        if (vet[i] == num)
            return 1;
    }
    return 0;
}

int menu()
{
    int op;
    printf("\n\n===MENU===\n");
    printf("[1] - soma vetores\n");
    printf("[2] - subtrai vetores\n");
    printf("[3] - mostra vetores\n");
    printf("[4] - procura elemento\n");
    printf("[5] - finaliza programa\n");
    printf("\n>>>> Escolha uma opcao: \n");
    scanf("%d", &op);
    return op;
}

int main_of_exercise11()
{
    int N, op;
    float num;
    printf("Type the size of the vectors: ");
    scanf("%d", &N);

    float *vetX, *vetY;

    printf("\n===Vector One===\n");
    vetX = (float *)malloc(sizeof(float) * N);
    fillVet(N, vetX);

    printf("\n===Vector Two===\n");
    vetY = (float *)malloc(sizeof(float) * N);
    fillVet(N, vetY);

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            sum(N, vetX, vetY);
            break;
        case 2:
            subtraction(N, vetX, vetY);
            break;
        case 3:
            showVet(N, vetX);
            printf("\n");
            showVet(N, vetY);
            break;
        case 4:
            printf("\nEnter the number to search: ");
            scanf("%f", &num);

            if (search(N, vetX, num))
                printf("\nIS IN the vector X!\n");
            else
                printf("\nIs NOT in the vector X!\n");

            if (search(N, vetY, num))
                printf("\nIS IN the vector Y!\n");
            else
                printf("\nIs NOT in the vector Y\n!");
            break;
        case 5:
            printf("\nEnd of program!\n");
            break;
        default:
            printf("\nOption not included!\n");
            break;
        }
    } while (op != 5);
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
    // main_of_exercise8();
    // main_of_exercise9();
    // main_of_exercise10();
    // main_of_exercise11();

    getchar();
    getchar();
}