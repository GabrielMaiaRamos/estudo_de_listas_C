#include <stdio.h>

int mdc(int a, int b)
{
    if (b == 0)
    {
        if (a < 0)
            a *= -1;
        return a;
    }
    return mdc(b, a % b);
}

int main_1022()
{
    int N1, N2, D1, D2, qtd, R1, R2, max_divisor;
    char op;

    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);
        switch (op)
        {
        case '+':
            R1 = (N1 * D2) + (N2 * D1);
            R2 = D1 * D2;
            break;
        case '-':
            R1 = (N1 * D2) - (N2 * D1);
            R2 = D1 * D2;
            break;
        case '*':
            R1 = N1 * N2;
            R2 = D1 * D2;
            break;
        case '/':
            R1 = N1 * D2;
            R2 = D1 * N2;
            break;
        }
        max_divisor = mdc(R1, R2);
        printf("%d/%d = %d/%d\n", R1, R2, R1 / max_divisor, R2 / max_divisor);
    }
    return 0;
}

int main()
{
    main_1022();

    getchar();
    getchar();
    return 0;
}