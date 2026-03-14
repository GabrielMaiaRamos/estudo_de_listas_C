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

int main()
{
    int nums1[11] = {0, 0, 1, 1, 1, 1, 2, 3, 3}, size = 10;
    printf("\n\n%d", removeDuplicates(nums1, size));

    getchar();
}