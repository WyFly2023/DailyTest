#include <stdio.h>
#include <stdlib.h>

int *FindNumsAppearOnce(int *nums, int numsLen)
{

    unsigned int ret = 0;
    for (int i = 0; i < numsLen; ++i)
        ret = ret ^ nums[i];
    unsigned int rightOne = ret & (~ret + 1);
    int *AppearOnceNums = (int *)calloc(2, sizeof(int));
    for (int i = 0; i < numsLen; ++i)
    {
        if ((nums[i] & rightOne) == rightOne)
            AppearOnceNums[0] ^= nums[i];
        else
            AppearOnceNums[1] ^= nums[i];
    }

    return AppearOnceNums;
}

int main()
{
    // 示例
    int nums[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 6};

    int numsLen = sizeof(nums) / sizeof(nums[0]);
    int *ptr = FindNumsAppearOnce(nums, numsLen);
    for (int i = 0; i < 2; ++i)
        printf("%d ", ptr[i]);

    return 0;
}