#include <stdio.h>
#include <string.h>

void triangles()
{
    float a, b, c;
    printf("Type the sides: \n");
    scanf("%f%f%f", &a, &b, &c);
    if (a <= b + c && b <= a + c && c <= b + a)
    {
        if (a == b && b == c)
            printf("Equilateral Triangle\n");
        else if (a == b || b == c)
            printf("Isosceles Triangle\n");
        else
            printf("Scalene Triangle\n");
    }
    else
        printf("Isnt possible to create a triangle\n");
}

void operations()
{
    float a, b;
    printf("Type A and B: ");
    scanf("%f%f", &a, &b);

    printf("Sum = %.2f\n", a + b);
    printf("Subtraction = %.2f\n", a - b);
    printf("Multiplcation = %.2f\n", a * b);
    if (b == 0)
        printf("isnt possible to divide by zero\n");
    else
        printf("Division = %.2f\n", a / b);
}

void sport_category()
{
    int age;

    printf("Type your age: ");
    scanf("%d", &age);
    if (age <= 4)
        printf("Category: Baby\n");
    else if (age >= 5 && age <= 10)
        printf("Category: Infantil\n");
    else if (age >= 11 && age <= 17)
        printf("Category: Juvenil\n");
    else
        printf("Category: Master\n");
}

void produto()
{
    float price, new_price;
    printf("How much does this product cost: ");
    scanf("%f", &price);

    if (price <= 50)
        new_price = price * 1.05;
    else if (price > 50 && price <= 100)
        new_price = price * 1.1;
    else
        new_price = price * 1.15;

    if (new_price <= 80)
        printf("Cheap: %.2f\n", new_price);
    else if (new_price > 80 && new_price <= 120)
        printf("Normal: %.2f\n", new_price);
    else if (new_price > 120 && new_price <= 200)
        printf("Expensive: %.2f\n", new_price);
    else
        printf("Very Expensive: %.2f\n", new_price);
}

void ideal_weight()
{
    float height;
    char sex[6];
    printf("Type your sex: ");
    scanf("%s", sex);
    printf("Type your height: ");
    scanf("%f", &height);

    if (strncmp(sex, "male", 4) == 0)
        printf("Seu peso ideal seria: %.2f\n", (72.7 * height) - 58);
    else
        printf("Seu peso ideal seria: %.2f\n", (62.1 * height) - 44.7);
}

void paridade()
{
    int a;
    printf("Type one number: ");
    scanf("%d", &a);

    if (a % 2 == 0)
        printf("even number\n");
    else
        printf("odd number\n");
}

void wage()
{
    float ha, hb, va, vb;
    printf("===How many hours do you teach===\n");
    printf("Teacher 1: ");
    scanf("%f", &ha);
    printf("Teacher 2: ");
    scanf("%f", &hb);
    printf("===How much do you get paid per hour===\n");
    printf("Teacher 1: ");
    scanf("%f", &vb);
    printf("Teacher 2: ");
    scanf("%f", &va);
    printf("\n===Wage of each one===\nProfessor 1: %.2f\nProfessor 2: %.2f\n", ha * va, hb * vb);
    if (ha * va > hb * vb)
        printf("Teacher 1 receives more!\n");
    else
        printf("Teacher 2 receives more!\n");
}

void election()
{
    int population;
    float white, null, valid;
    printf("What is the local population? ");
    scanf("%d", &population);

    printf("===Number of votes===\n");
    printf("White: ");
    scanf("%f", &white);
    printf("Null: ");
    scanf("%f", &null);
    printf("Valid: ");
    scanf("%f", &valid);

    printf("===Percentage of votes===\n");
    printf("White: %.0f%%\n", (white / population) * 100);
    printf("Null: %0.f%%\n", (null / population) * 100);
    printf("Valid: %0.f%%\n", (valid / population) * 100);
}

void neverlands()
{
    int C, P, W;
    float total;
    printf("Votes to Capitao Gancho");
    scanf("%d", &C);
    printf("Votes to Peter Pan");
    scanf("%d", &P);
    printf("Votes to Capitao Gancho");
    scanf("%d", &W);
    total = C + P + W;
    if (C / total >= 0.5)
        printf("Capitao Gancho won the election in the first turn");
    else if (P / total >= 0.5)
        printf("Peter Pan won the election in the first turn");
    else
        printf("Wendy won the election in the first turn");
}

void special_number()
{
    int N, P1, P2, NewN;
    printf("Type one number in [1000, 9999] ");
    scanf("%d", &N);
    P1 = N / 100;
    P2 = N % 100;
    NewN = P1 + P2;
    if (NewN * NewN == N)
        printf("Number %d IS an special number", N);
    else
        printf("Number %d is NOT an special number", N);
}

void bike_store()
{
    int employess, min_wage, mensal_amount, indiviual_wage;
    printf("Enter the total number of employess: ");
    scanf("%d", &employess);
    printf("Enter the minimum wage: ");
    scanf("%d", &min_wage);
    printf("Enter the sales value for the month");
    scanf("%d", &mensal_amount);

    indiviual_wage = ((2 * min_wage * employess) + (0.05 * mensal_amount)) / employess;
    printf("Each employess's salary is: %d", indiviual_wage);
}

int main()
{
    // triangkes();
    // operations();
    // sport_category();
    // produto();
    // ideal_weight();
    // paridade();
    // wage();
    // election();
    // neverlands();
    // special_number();
    // bike_store();

    printf("\nPress any key to close\n");
    getchar();
    getchar();
}