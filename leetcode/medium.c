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

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) // 88. Merge Sorted Array
{
    int i = m - 1,
        j = n - 1,
        right = n + m - 1;

    while (j >= 0)
    {
        if (i >= 0 && nums1[i] >= nums2[j])
        {
            nums1[right] = nums1[i];
            i--;
        }
        else
        {
            nums1[right] = nums2[j];
            j--;
        }
        right--;
    }
}

int removeElement(int *nums, int numsSize, int val) // 27. Remove Element
{
    int right = numsSize - 1, count = 0, i = 0;
    if (numsSize == 0)
        return 0;
    while (count < numsSize)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[right];
            right--;
        }
        else
            i++;
        count++;
    }
    for (int i = 0; i < numsSize; i++)
        return right + 1;
}
int main()
{
    int nums1[6] = {1}, size = 1;
    printf("\n\n%d", removeElement(nums1, size, 1));

    getchar();
}