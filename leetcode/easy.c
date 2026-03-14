#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

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

int removeDuplicates(int *nums, int numsSize) // 26. Remove Duplicates from Sorted Array
{
    int *pointer = nums, *aux = &nums[1], k = 0;

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (*pointer != *aux)
        {
            k++;
            nums[k] = *aux;
            pointer = aux;
        }
        aux++;
    }
    return k + 1;
}

int removeDuplicates(int *nums, int numsSize)
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
    int nums1[11] = {1, 1, 2}, size = 3;
    printf("\n\n%d", removeDuplicates(nums1, size));

    getchar();
}