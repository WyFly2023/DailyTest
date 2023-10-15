/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int prev = 0;
    for (int cur = 1; cur < numsSize; ++cur)
    {
        if (nums[prev] != nums[cur])
        {
            prev++;
            nums[prev] = nums[cur];
        }
    }
    return prev + 1;
}
// @lc code=end
