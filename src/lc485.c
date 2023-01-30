#include <stdio.h>

/**
 * 给定一个二进制数组nums, 计算其中最大连续1的个数
 */

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int oneCount = 0;
    int tempCount = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            tempCount++;
        }
        else if (nums[i] != 1)
        {
            if (oneCount < tempCount)
            {
                oneCount = tempCount;
            }
            tempCount = 0;
        }
    }
    if (tempCount > oneCount)
    {
        oneCount = tempCount;
    }
    return oneCount;
}

int main()
{
    int length = 0;
    scanf("%d", &length);

    int nums[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d", nums + i);
    }

    printf("consectutiveOnesCount : %d", findMaxConsecutiveOnes(nums, length));
    return 0;
}