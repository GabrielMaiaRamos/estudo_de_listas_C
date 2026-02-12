#include <stdio.h>
#include <math.h>
#include <string.h>

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

int main()
{
    getchar();
}