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

int majorityElement(int *nums, int numsSize) // 169. Majority Element
// usando Algoritmo de Votação de Boyer-Moore
{
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
        }
        if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int maxProfit(int *prices, int pricesSize) // 121. Best Time to Buy and Sell Stock
{
    if (pricesSize == 0)
        return 0;
    int buy = prices[0], price = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        if (buy > prices[i])
            buy = prices[i];
        if (price < (prices[i] - buy))
            price = prices[i] - buy;
    }
    return price;
}

int main()
{
    int nums1[11] = {1, 2, 3, 4, 5, 6, 7}, size = 7;

    printf("\n\n%d", maxProfit(nums1, size));

    getchar();
}