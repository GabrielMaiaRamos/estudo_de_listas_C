#include <stdio.h>

int power(int X, int N)
{
    if (N == 1)
        return X;
    return X * power(X, N - 1);
}

int sum_range(int A, int B)
{
    if (A == B)
        return A;
    return A + sum_range(A + 1, B);
}

int division(int A, int B)
{
    if (A < B)
        return 0;
    return 1 + division(A - B, B);
}

int evens(int N)
{
    if (N < 0)
        return 0;

    if (N % 2 == 0)
    {
        printf("%d - ", N);
        return evens(N - 2);
    }
    else
        return evens(N - 1);
}

int fibonnaci(int N)
{
    if (N == 1)
        return 0;
    else if (N == 2)
        return 1;
    return (fibonnaci(N - 2) + fibonnaci(N - 1));
}

int main()
{
    int X, N1;
    printf("Type X and the N: ");
    scanf("%d%d", &X, &N1);
    printf("%d to the %dth power = %d\n", X, N1, power(X, N1));

    int A1, B1;
    printf("Type A and B: ");
    scanf("%d%d", &A1, &B1);
    printf("Sum = %d", sum_range(A1, B1));

    int A2, B2;
    printf("Type A and B: ");
    scanf("%d%d", &A2, &B2);
    printf("Division = %d", division(A2, B2));

    int N2;
    printf("Type the N: ");
    scanf("%d", &N2);
    evens(N2);

    int N3;
    printf("Type the N: ");
    scanf("%d", &N3);
    for (int i = 0; i < N3; i++)
        printf("Term (%d) = %d\n", i + 1, fibonnaci(i + 1));

    getchar();
    getchar();
}