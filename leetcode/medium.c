#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

bool canJump(int *nums, int numsSize) // 55. Jump Game
{
    int goal = numsSize - 1;
    for (int i = numsSize - 2; i >= 0; i--)
    {
        if (i + nums[i] >= goal)
            goal = i;
    }
    return (goal == 0);
}

int removeDuplicates(int *nums, int numsSize) // 80. Remove Duplicates from Sorted Array II
{
    if (numsSize <= 2)
        return numsSize;
    int k = 2;

    for (int i = 2; i < numsSize; i++)
    {
        if (nums[i] != nums[k - 2])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

void rotate(int *nums, int numsSize, int k) // 189. Rotate Array
{
    int aux;

    // o "k" nos testes pode ser maior que o tamanho do array (nao sei pq),
    // entao precisa reduzir para o resto da divisao pelo tamanho do array, pois
    // seria como rodar todo o array ate ele voltar ao normal e entao rodar dnv o restante
    k = k % numsSize;
    // inverte os numsSize-k primeiros valores
    for (int i = 0; i < (numsSize - k) / 2; i++)
    {
        printf("%d and %d\n", nums[i], nums[numsSize - 1 - k - i]);
        aux = nums[i];
        nums[i] = nums[numsSize - 1 - k - i];
        nums[numsSize - 1 - k - i] = aux;
    }

    // inverte os k ultimos valores
    for (int j = 0; j < k / 2; j++)
    {
        printf("%d and %d\n", nums[j + numsSize - k], nums[numsSize - 1 - j]);
        aux = nums[j + numsSize - k];
        nums[j + numsSize - k] = nums[numsSize - 1 - j];
        nums[numsSize - 1 - j] = aux;
    }

    // inverte todos os valores
    for (int c = 0; c < numsSize / 2; c++)
    {
        printf("%d and %d\n", nums[c], nums[numsSize - 1 - c]);
        aux = nums[c];
        nums[c] = nums[numsSize - 1 - c];
        nums[numsSize - 1 - c] = aux;
    }

    for (int i = 0; i < numsSize; i++)
        printf("%d | ", nums[i]);
}

int main()
{
    int nums1[11] = {0, 0, 1, 1, 1, 1, 2, 3, 3}, size = 10;
    printf("\n\n%d", removeDuplicates(nums1, size));

    getchar();
}