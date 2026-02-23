#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stddef.h>

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

int make_chocolates(int small, int big, int goal)
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

int main()
{

    getchar();
}