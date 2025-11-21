#include <stdio.h>

void caminhao()
{
    float caixa, peso_total;
    for (int i = 0; i < 5; i++)
    {
        printf("Digite o peso da caixa [%d] ", i + 1);
        scanf("%f", &caixa);
        peso_total += caixa;
    }
    printf("Peso total = %.2f", peso_total);
}

void soma_intervalo()
{
    int A, B, sum = 0;
    printf("Type A and B: ");
    scanf("%d%d", &A, &B);
    if (A > B)
        printf("Impossible to sum");
    else
    {
        for (int i = A + 1; i < B; i++)
        {
            sum += i;
        }
        printf("Total = %d", sum);
    }
}

void soma_mult_4()
{
    int A, B, sum = 0;
    printf("Type A and B: ");
    scanf("%d%d", &A, &B);
    if (A > B)
        printf("Impossible to sum");
    else
    {
        for (int i = A + 1; i < B; i++)
        {
            if (i % 4 == 0)
                sum += i;
        }
        printf("Total = %d", sum);
    }
}

void house_area()
{
    float height, width, total;
    do
    {
        printf("Type the height and the width in meters: ");
        scanf("%f%f", &height, &width);
        total += (height * width);

    } while (height >= 0 && width >= 0);
    printf("House area = %.2f", total);
}

void multiplication_table()
{
    int N;
    printf("Type the N: ");
    scanf("%d", &N);

    if (0 <= N <= 9)
        for (int i = 0; i <= 10; i++)
            printf("%d x %d = %d\n", N, i, N * i);
    else
        printf("Type an number between 0 and 9");
}

void cinema()
{

    float age = 0, people = 0, total = 0, otimo = 0, bom = 0, regular = 0, pessimo = 0;
    char opnion;

    while (age >= 0)
    {
        printf("Enter your age and your opnion about the film: ");
        scanf("%f %c", &age, &opnion);
        if (age < 0)
            break;

        total += age;
        people++;

        switch (opnion)
        {
        case 'O':
            printf("O ein");
            otimo++;
            break;
        case 'B':
            printf("B ein");
            bom++;
            break;
        case 'R':
            printf("R ein");
            regular++;
            break;
        case 'P':
            printf("P ein");
            pessimo++;
            break;
        }
    }

    printf("\nALAAA = %f, %f", people, total);
    printf("Average age: %.2f\n", total / people);
    printf("===Percentage===\n");
    printf("Otimo = %.0f%%\n", (otimo / people) * 100);
    printf("Bom = %0.f%%\n", (bom / people) * 100);
    printf("Regular = %0.f%%\n", (regular / people) * 100);
    printf("Pessimo = %0.f%%\n", (pessimo / people) * 100);
}

void expression()
{
    int E = 0, N, pot = 1;
    printf("Type the N: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        pot *= 2;
        E += pot;
    }
    printf("E = %d", E);
}

void factorial()
{
    int N, fat;
    printf("Type the N: ");
    scanf("%d", &N);
    fat = N;
    for (int i = 1; i < N; i++)
    {
        fat *= N - i;
    }
    printf("Factorial = %d\n", fat);
}

void city_hall()
{
    int age;
    float salary, highest = 0, men_count = 0, fem_count = 0, men_wage = 0, fem_wage = 0;
    char sex;

    while (salary >= 0)
    {
        printf("Enter your sex, salary and age: ");
        scanf(" %c%f%d", &sex, &salary, &age);
        if (salary < 0)
            break;
        if (age < 30)
        {
            if (salary > highest)
                highest = salary;
        }
        switch (sex)
        {
        case 'M':
            men_count += 1;
            men_wage += salary;
            break;
        case 'F':
            fem_count += 1;
            fem_wage += salary;
        }
    }
    printf("Average salary for men: %.2f\n", men_wage / men_count);
    printf("Average salary for fem: %.2f\n", fem_wage / fem_count);
    printf("Highest salary among people under thirty: %.2f\n", highest);
}

int main()
{
    // caminhao();
    // soma_intervalo();
    // soma_mult_4();
    // house_area();
    // multiplication_table();
    // cinema();
    // expression();
    // factorial();
    // city_hall();

    getchar();
    getchar();
}