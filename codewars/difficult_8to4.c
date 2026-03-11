#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

//====================================== [ 8 ] ======================================//
const char *greet(const char *name, const char *owner) // Grasshopper - Personalized Message
{
    if (!strcmp(name, owner))
        return "Hello boss";
    return "Hello guest";
}

unsigned bin_to_decimal(const char *bin) // Bin to Decimal
{
    int num = 0, index = strlen(bin) - 1;

    for (int pos = 0; pos <= index; pos++)
    {
        if (bin[pos] == '1')
        {
            num += pow(2, (index - pos));
        }
    }
    return num;
}

double solution(const double values[3], const char *const units[3])
{
    double force = (6.67e-11 * values[0] * values[1]) / pow(values[2], 2);
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(units[i], "kg"))

            switch (units[i][0])
            {
            case 'g':
                force /= pow(10, 3);
                break;
            case 'm':
                force /= pow(10, 6);
                break;
            case 'l':
                force *= 0.453592;
                break;
            default: // for μ
                force /= pow(10, 9);
                break;
            }
    }
    if (strcmp(units[2], "m"))
    {
        switch (units[2][0])
        {
        case 'c':
            force *= pow(10, 4);
            break;
        case 'm':
            force *= pow(10, 6);
            break;
        case 'f':
            force /= pow(0.3048, 2);
            break;
        default: // for μ
            force *= pow(10, 12);
            break;
        }
    }
    return force;
}

//====================================== [ 7 ] ======================================//

int dominator(const int array[/* n */], size_t n) // What dominates your array?
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (array[i] == array[j])
                count++;
        if (count > n / 2)
            return array[i];
    }
    return -1;
}

//====================================== [ 6 ] ======================================//

int make_chocolates(int small, int big, int goal) // Pack Some Chocolates
{
    int count = 0, min = goal / 5;

    // usa o maximo possivel de chocolates grandes
    if (big < goal / 5)
        min = big;

    goal -= min * 5;

    // se usou muito e nao eh par, entao volta 1 atras
    // obs: pra isso, deve ter usado pelo menos uma vez, logo min!=0
    if (min != 0 && goal % 2 != 0)
        goal += 5;

    // termina o resto usando os chocolates menores
    // se tiver o suficiente de menores, retorna a quantidade necessaria, se nao retorna -1
    if (goal % 2 == 0 && small >= goal / 2)
        return goal / 2;

    return -1;
}

// Array.diff
int *array_diff(const int arr1[/* n1 */], size_t n1, const int arr2[/* n2 */], size_t n2, size_t *z)
{
    if (n1 == 0)
    {
        *z = 0;
        return NULL;
    }
    int *arr3, count = 0;
    bool has;

    arr3 = (int *)malloc(n1 * sizeof(int));

    for (size_t i = 0; i < n1; i++)
    {
        has = false;
        for (size_t j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                has = true;
                break;
            }
        }
        if (!has)
        {
            arr3[count] = arr1[i];
            count++;
        }
    }
    *z = count;
    return arr3;
}

//====================================== [ MAIN ] ======================================//

int main()
{
    getchar();
}